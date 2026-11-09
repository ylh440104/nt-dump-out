
===== WanNdisReceivePackets @ 140001010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanNdisReceivePackets
               (longlong param_1,longlong **param_2,undefined8 param_3,int param_4,uint param_5)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  longlong **pplVar4;
  code *pcVar5;
  longlong *plVar6;
  byte bVar7;
  undefined1 uVar8;
  byte bVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  char cVar13;
  ushort uVar14;
  undefined8 uVar15;
  longlong lVar16;
  uint uVar17;
  longlong *plVar18;
  uint uVar19;
  longlong lVar20;
  bool bVar21;
  undefined1 auStackY_118 [32];
  undefined1 local_df;
  longlong **local_d8;
  byte local_cc;
  longlong *local_c8;
  uint local_c0;
  uint local_bc;
  longlong **local_b8;
  longlong local_b0;
  longlong *local_a8;
  longlong *local_a0;
  longlong local_98;
  longlong local_90;
  longlong *local_88;
  short *local_80;
  code *local_78;
  undefined8 uStack_70;
  longlong *local_68;
  ulonglong uStack_60;
  undefined8 local_50;
  undefined4 local_48;
  undefined2 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_a0 = (longlong *)0x0;
  local_c8 = (longlong *)0x0;
  bVar21 = param_1 != 0xcabb1e4;
  if (bVar21) {
    local_a8 = &DAT_14000a498;
    local_80 = (short *)&DAT_14000a2ac;
    local_88 = &DAT_14000a328;
  }
  else {
    local_a8 = &DAT_14000a248;
    local_80 = &DAT_14000a05c;
    local_88 = &DAT_14000a0d8;
  }
  local_d8 = &local_a0;
  local_50 = 0;
  local_48 = 0;
  lVar16 = 0;
  local_44 = 0;
  local_b8 = &local_c8;
  bVar7 = (byte)param_5;
  local_cc = bVar7 & 1;
  local_90 = 0;
  local_98 = 0;
  local_b0 = 0;
  local_c0 = 0xffffffff;
  local_df = 0;
  local_78 = (code *)0x0;
  uStack_70 = 0;
  local_68 = (longlong *)0x0;
  uStack_60 = 0;
  LOCK();
  _glReceivedNbls = _glReceivedNbls + param_4;
  UNLOCK();
  cVar13 = DAT_14000aa66;
  if (bVar21) {
    cVar13 = DAT_14000ab86;
  }
  if (cVar13 == '\0') {
    if (param_2 == (longlong **)0x0) {
      return;
    }
    do {
      pplVar4 = (longlong **)*param_2;
      if ((param_5 & 2) == 0) {
        *local_d8 = (longlong *)param_2;
        local_d8 = param_2;
      }
      param_2 = pplVar4;
    } while (pplVar4 != (longlong **)0x0);
    goto LAB_14000156f;
  }
  if (param_2 == (longlong **)0x0) goto LAB_14000156f;
  uVar19 = param_5 & 2;
  uVar17 = uVar19;
  do {
    pplVar4 = (longlong **)*param_2;
    param_2[0xe] = (longlong *)0x0;
    lVar11 = NdisGetDataBuffer(param_2[1],0xe,&local_50);
    if (lVar11 == 0) {
      uVar17 = uVar19;
LAB_140001502:
      if (uVar17 == 0) {
        *local_d8 = (longlong *)param_2;
        local_d8 = param_2;
      }
      uVar17 = uVar19;
    }
    else {
      uVar14 = *(ushort *)(lVar11 + 0xc) >> 8 | *(ushort *)(lVar11 + 0xc) << 8;
      if (uVar14 < 0x600) goto LAB_140001502;
      uVar17 = *(uint *)(lVar11 + 2);
      local_bc = uVar19;
      KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
      if (uVar17 < g_ulConnTableSize) {
        KeReleaseSpinLock();
        if (uVar17 != local_c0) {
          if (local_c0 != 0xffffffff) {
            if (*(int *)(lVar16 + 100) != 0) {
              KeReleaseSpinLockFromDpcLevel(local_b0 + 0x38);
            }
            KeReleaseSpinLock(*(undefined8 *)(lVar16 + 0x50),local_df);
            if (local_c8 != (longlong *)0x0) {
              *local_b8 = (longlong *)0x0;
              uVar8 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar16 + 0x50));
              if (*(int *)(lVar16 + 0x7c) == 5) {
                KeReleaseSpinLock(*(undefined8 *)(lVar16 + 0x50),uVar8);
              }
              else {
                KeReleaseSpinLock();
                uVar3 = SystemReserved1[0x12]._4_4_;
                uVar15 = 0xe;
                for (plVar18 = local_c8; plVar18 != (longlong *)0x0; plVar18 = (longlong *)*plVar18)
                {
                  LOCK();
                  _glFLPIndicatedNBLs = _glFLPIndicatedNBLs + 1;
                  UNLOCK();
                }
                pcVar5 = *(code **)(*(longlong *)(*local_88 + 8) + 0x40);
                if (*local_a8 == 0) {
                  (*pcVar5)(*(undefined8 *)(lVar16 + 0x80),local_c8,local_cc);
                }
                else {
                  uStack_70 = *(undefined8 *)(lVar16 + 0x80);
                  uStack_60 = CONCAT71(uStack_60._1_7_,bVar7) & 0xffffffffffffff01;
                  local_68 = local_c8;
                  plVar18 = local_c8;
                  local_78 = pcVar5;
                  bVar9 = KeGetCurrentIrql();
                  NetioExpandKernelStackAndCallout(*local_a8,uVar15,&local_78,plVar18,uVar3,bVar9);
                }
              }
              local_b8 = &local_c8;
              local_c8 = (longlong *)0x0;
            }
            LOCK();
            piVar1 = (int *)(lVar16 + 0x60);
            iVar10 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar10 == 1) {
              WanpDeleteConnEntry(lVar16);
            }
            local_c0 = 0xffffffff;
            local_98 = 0;
            lVar16 = 0;
            local_b0 = 0;
          }
          local_df = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
          lVar11 = *(longlong *)(g_puipConnTable + (ulonglong)uVar17 * 8);
          if (lVar11 == 0) {
            KeReleaseSpinLock(&g_rlConnTableLock);
            if (uVar19 != 0) {
              uVar17 = uVar19;
              goto LAB_140001680;
            }
            *local_d8 = (longlong *)param_2;
            uVar17 = uVar19;
            local_d8 = param_2;
            goto LAB_1400013bf;
          }
          LOCK();
          *(int *)(lVar11 + 0x60) = *(int *)(lVar11 + 0x60) + 1;
          UNLOCK();
          KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(lVar11 + 0x50));
          KeReleaseSpinLockFromDpcLevel(&g_rlConnTableLock);
          local_b0 = *(longlong *)(lVar11 + 0x10);
          lVar20 = *(longlong *)(lVar11 + 8);
          local_90 = lVar20;
          if (*(int *)(lVar11 + 100) != 0) {
            KeAcquireSpinLockAtDpcLevel(local_b0 + 0x38);
          }
          lVar16 = lVar11;
          local_c0 = uVar17;
          local_98 = lVar20;
        }
        LOCK();
        *(longlong *)(local_98 + 0xf0) =
             *(longlong *)(local_98 + 0xf0) + (ulonglong)*(uint *)(param_2[1] + 3);
        UNLOCK();
        if (((*local_80 == 2) && (uVar14 == 0x800)) || ((*local_80 == 0x17 && (uVar14 == 0x86dd))))
        {
          if (uVar19 != 0) {
            param_2 = (longlong **)
                      NetioAllocateAndReferenceCopyNetBufferListEx
                                (param_2,FlpFreeNetBufferListChain,lVar16,local_cc);
            uVar17 = uVar19;
            if (param_2 == (longlong **)0x0) goto LAB_140001680;
          }
          plVar18 = param_2[1];
          uVar17 = (int)plVar18[2] + 0xe;
          if (uVar17 < *(uint *)(plVar18[1] + 0x28)) {
            *(int *)(plVar18 + 5) = (int)plVar18[5] + 0xe;
            *(int *)(plVar18 + 3) = (int)plVar18[3] + -0xe;
            *(uint *)(plVar18 + 2) = uVar17;
          }
          else {
            NdisAdvanceNetBufferDataStart(plVar18,0xe,0,0);
          }
          if (((*(char *)(lVar16 + 4) == '\0') || (*(char *)(lVar16 + 0x7a) != '\x01')) ||
             (uVar12 = WanpDropNetbiosPacket(param_2[1],(int)param_2[1][3] - 0xe),
             (char)uVar12 == '\0')) {
            if (uVar19 == 0) {
              NetioInitializeNetBufferListContext(param_2,0,FlpReturnNetBufferListChain,lVar16);
              *(uint *)(param_2 + 0x11) = *(uint *)(param_2 + 0x11) | 0x20000000;
              param_2[0xe] = (longlong *)0x0;
            }
            *(undefined4 *)((longlong)param_2 + 0x8c) = 0;
            param_2[0x22] = (longlong *)(ulonglong)*(uint *)(local_90 + 0x168);
            LOCK();
            *(int *)(lVar16 + 0x60) = *(int *)(lVar16 + 0x60) + 1;
            UNLOCK();
            LOCK();
            plVar18 = (longlong *)(*(longlong *)(lVar16 + 8) + 0xf8);
            *plVar18 = *plVar18 + 1;
            UNLOCK();
            *local_b8 = (longlong *)param_2;
            local_b8 = param_2;
            uVar17 = uVar19;
          }
          else {
            LOCK();
            *(longlong *)(local_90 + 0xe0) = *(longlong *)(local_90 + 0xe0) + 1;
            UNLOCK();
            NetioRestoreNetBuffer((longlong)param_2[1]);
            if (uVar19 == 0) {
              *local_d8 = (longlong *)param_2;
              local_d8 = param_2;
            }
            else {
              NetioCompleteCopyNetBufferListChain(local_c8,0,local_cc);
            }
            uVar17 = uVar19;
          }
        }
        else {
          LOCK();
          *(longlong *)(local_98 + 0xd8) = *(longlong *)(local_98 + 0xd8) + 1;
          UNLOCK();
          if (uVar19 != 0) {
            uVar17 = local_bc;
            goto LAB_140001680;
          }
          *local_d8 = (longlong *)param_2;
          uVar17 = uVar19;
          local_d8 = param_2;
        }
      }
      else {
        KeReleaseSpinLock(&g_rlConnTableLock);
        if (uVar19 == 0) {
          *local_d8 = (longlong *)param_2;
          uVar17 = uVar19;
          local_d8 = param_2;
        }
        else {
          uVar17 = uVar19;
LAB_140001680:
        }
      }
LAB_1400013bf:
    }
    param_2 = pplVar4;
  } while (pplVar4 != (longlong **)0x0);
  if (local_c0 == 0xffffffff) goto LAB_14000156f;
  if (*(int *)(lVar16 + 100) != 0) {
    KeReleaseSpinLockFromDpcLevel(local_b0 + 0x38);
  }
  KeReleaseSpinLock(*(undefined8 *)(lVar16 + 0x50));
  if (local_c8 != (longlong *)0x0) {
    *local_b8 = (longlong *)0x0;
    KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar16 + 0x50));
    if (*(int *)(lVar16 + 0x7c) == 5) {
      KeReleaseSpinLock(*(undefined8 *)(lVar16 + 0x50));
    }
    else {
      KeReleaseSpinLock();
      plVar6 = local_a8;
      uVar17 = SystemReserved1[0x12]._4_4_;
      for (plVar18 = local_c8; plVar18 != (longlong *)0x0; plVar18 = (longlong *)*plVar18) {
        LOCK();
        _glFLPIndicatedNBLs = _glFLPIndicatedNBLs + 1;
        UNLOCK();
      }
      pcVar5 = *(code **)(*(longlong *)(*local_88 + 8) + 0x40);
      if (*local_a8 == 0) {
        (*pcVar5)(*(undefined8 *)(lVar16 + 0x80),local_c8,local_cc);
      }
      else {
        uStack_70 = *(undefined8 *)(lVar16 + 0x80);
        uStack_60 = CONCAT71(uStack_60._1_7_,bVar7) & 0xffffffffffffff01;
        local_68 = local_c8;
        uVar12 = (ulonglong)SystemReserved1[0x12]._4_4_;
        local_78 = pcVar5;
        bVar7 = KeGetCurrentIrql();
        lVar11 = *plVar6;
        if (bVar7 < 2) {
          uVar15 = 1;
LAB_140001932:
          lVar20 = 0;
        }
        else {
          uVar15 = 0;
          if ((*(uint *)(lVar11 + 0x3c) & 1) != 0) goto LAB_140001932;
          uVar19 = *(uint *)(lVar11 + 0x48 + uVar12 * 0x10);
          if ((uVar19 & 1) != 0) goto LAB_140001932;
          *(uint *)(lVar11 + 0x48 + uVar12 * 0x10) = uVar19 | 1;
          lVar20 = *(longlong *)(lVar11 + ((ulonglong)uVar17 + 4) * 0x10);
        }
        while (iVar10 = KeExpandKernelStackAndCalloutEx
                                  (WanNdisReceivePacketsCalloutRoutine,&local_78,0x4800,uVar15),
              iVar10 == -0x3fffffe9) {
          if (lVar20 != 0) goto LAB_1400019f3;
          if (bVar7 < 2) {
            KeWaitForSingleObject(lVar11,0,0,0);
            uVar19 = *(uint *)(lVar11 + 0x38);
            uVar3 = *(uint *)(lVar11 + 0x48 + (ulonglong)uVar19 * 0x10);
            if ((uVar3 & 1) != 0) goto LAB_140001a14;
            lVar20 = *(longlong *)(lVar11 + ((ulonglong)uVar19 + 4) * 0x10);
            *(uint *)(lVar11 + 0x48 + (ulonglong)uVar19 * 0x10) = uVar3 | 1;
          }
          else {
            uVar19 = *(uint *)(lVar11 + 0x48 + (ulonglong)uVar17 * 0x10);
            if ((uVar19 & 1) != 0) goto LAB_140001530;
            *(uint *)(lVar11 + 0x48 + (ulonglong)uVar17 * 0x10) = uVar19 | 1;
            lVar20 = *(longlong *)(lVar11 + (uVar12 + 4) * 0x10);
          }
        }
        if (lVar20 != 0) {
LAB_1400019f3:
          if (bVar7 < 2) {
            puVar2 = (uint *)(lVar11 + 0x48 + (ulonglong)*(uint *)(lVar11 + 0x38) * 0x10);
            *puVar2 = *puVar2 & 0xfffffffe;
LAB_140001a14:
            KeReleaseMutex(lVar11);
          }
          else {
            puVar2 = (uint *)(lVar11 + 0x48 + (ulonglong)uVar17 * 0x10);
            *puVar2 = *puVar2 & 0xfffffffe;
          }
        }
      }
    }
  }
LAB_140001530:
  LOCK();
  piVar1 = (int *)(lVar16 + 0x60);
  iVar10 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar10 == 1) {
    WanpDeleteConnEntry(lVar16);
  }
LAB_14000156f:
  if (local_a0 != (longlong *)0x0) {
    *local_d8 = (longlong *)0x0;
    local_c8 = local_a0;
    if (local_a0 != (longlong *)0x0) {
      do {
        LOCK();
        _glReturnedNbls = _glReturnedNbls + 1;
        UNLOCK();
        local_c8 = (longlong *)*local_c8;
      } while (local_c8 != (longlong *)0x0);
      local_c8 = (longlong *)0x0;
    }
    uVar15 = DAT_14000aa68;
    if (bVar21) {
      uVar15 = DAT_14000ab88;
    }
    NdisReturnNetBufferLists(uVar15,local_a0,param_5 & 1);
  }
  return;
}



===== WanNdisIfQueryHandler @ 140001ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WanNdisIfQueryHandler(undefined8 *param_1,uint param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  ushort *puVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  int iVar8;
  ushort *puVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  undefined1 auStack_278 [32];
  ushort local_258;
  undefined8 auStack_256 [64];
  undefined2 local_56;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_278;
  uVar14 = 0;
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xf);
  cVar3 = *(char *)((longlong)param_1 + 0x94);
  LOCK();
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  UNLOCK();
  if (param_2 == 0x1010102) {
LAB_140001be9:
    memset(param_4,0,(ulonglong)*param_3);
    *param_3 = 0;
    goto LAB_140001bfb;
  }
  if (param_2 == 0x10289) {
    memset(auStack_256,0,0x202);
    if (*param_3 < 0x204) {
      uVar14 = 0xc0010014;
    }
    else {
      memset(param_4,0,(ulonglong)*param_3);
      if (*(ushort *)(param_1 + 0xb) < 0x101) {
        local_258 = *(ushort *)(param_1 + 0xb) + 2;
        memmove(auStack_256,(undefined8 *)param_1[0xc],(ulonglong)local_258);
      }
      else {
        local_258 = 0x102;
        lVar11 = 2;
        puVar12 = auStack_256;
        puVar13 = (undefined8 *)param_1[0xc];
        do {
          uVar10 = puVar13[1];
          uVar4 = puVar13[2];
          uVar5 = puVar13[3];
          *puVar12 = *puVar13;
          puVar12[1] = uVar10;
          uVar10 = puVar13[4];
          uVar6 = puVar13[5];
          puVar12[2] = uVar4;
          puVar12[3] = uVar5;
          uVar4 = puVar13[6];
          uVar5 = puVar13[7];
          puVar12[4] = uVar10;
          puVar12[5] = uVar6;
          uVar10 = puVar13[8];
          uVar6 = puVar13[9];
          puVar12[6] = uVar4;
          puVar12[7] = uVar5;
          uVar4 = puVar13[10];
          uVar5 = puVar13[0xb];
          puVar12[8] = uVar10;
          puVar12[9] = uVar6;
          uVar10 = puVar13[0xc];
          uVar6 = puVar13[0xd];
          puVar12[10] = uVar4;
          puVar12[0xb] = uVar5;
          uVar4 = puVar13[0xe];
          uVar5 = puVar13[0xf];
          puVar12[0xc] = uVar10;
          puVar12[0xd] = uVar6;
          puVar12[0xe] = uVar4;
          puVar12[0xf] = uVar5;
          lVar11 = lVar11 + -1;
          puVar12 = puVar12 + 0x10;
          puVar13 = puVar13 + 0x10;
        } while (lVar11 != 0);
        local_56 = 0;
      }
      lVar11 = 4;
      puVar9 = &local_258;
      do {
        piVar1 = param_4 + 0x20;
        uVar10 = *(undefined8 *)(puVar9 + 4);
        uVar4 = *(undefined8 *)(puVar9 + 8);
        uVar5 = *(undefined8 *)(puVar9 + 0xc);
        puVar2 = puVar9 + 0x40;
        *(undefined8 *)param_4 = *(undefined8 *)puVar9;
        *(undefined8 *)(param_4 + 2) = uVar10;
        uVar10 = *(undefined8 *)(puVar9 + 0x10);
        uVar6 = *(undefined8 *)(puVar9 + 0x14);
        *(undefined8 *)(param_4 + 4) = uVar4;
        *(undefined8 *)(param_4 + 6) = uVar5;
        uVar4 = *(undefined8 *)(puVar9 + 0x18);
        uVar5 = *(undefined8 *)(puVar9 + 0x1c);
        *(undefined8 *)(param_4 + 8) = uVar10;
        *(undefined8 *)(param_4 + 10) = uVar6;
        uVar10 = *(undefined8 *)(puVar9 + 0x20);
        uVar6 = *(undefined8 *)(puVar9 + 0x24);
        *(undefined8 *)(param_4 + 0xc) = uVar4;
        *(undefined8 *)(param_4 + 0xe) = uVar5;
        uVar4 = *(undefined8 *)(puVar9 + 0x28);
        uVar5 = *(undefined8 *)(puVar9 + 0x2c);
        *(undefined8 *)(param_4 + 0x10) = uVar10;
        *(undefined8 *)(param_4 + 0x12) = uVar6;
        uVar10 = *(undefined8 *)(puVar9 + 0x30);
        uVar6 = *(undefined8 *)(puVar9 + 0x34);
        *(undefined8 *)(param_4 + 0x14) = uVar4;
        *(undefined8 *)(param_4 + 0x16) = uVar5;
        uVar4 = *(undefined8 *)(puVar9 + 0x38);
        uVar5 = *(undefined8 *)(puVar9 + 0x3c);
        *(undefined8 *)(param_4 + 0x18) = uVar10;
        *(undefined8 *)(param_4 + 0x1a) = uVar6;
        *(undefined8 *)(param_4 + 0x1c) = uVar4;
        *(undefined8 *)(param_4 + 0x1e) = uVar5;
        lVar11 = lVar11 + -1;
        puVar9 = puVar2;
        param_4 = piVar1;
      } while (lVar11 != 0);
      *piVar1 = *(int *)puVar2;
    }
    *param_3 = 0x204;
    goto LAB_140001bfb;
  }
  if (param_2 < 0x10284) {
    if (param_2 == 0x10283) {
switchD_140001c8a_caseD_10288:
      *param_4 = (cVar3 != '\x06') + 1;
      *param_3 = 4;
      goto LAB_140001bfb;
    }
    if (param_2 == 0x10106) {
      iVar8 = GetMTUSize(param_1);
      *param_4 = iVar8;
      goto LAB_140001bfb;
    }
    if (param_2 == 0x10280) {
      *(undefined1 *)param_4 = 1;
      goto LAB_140001bfb;
    }
    goto switchD_140001c8a_caseD_10286;
  }
  if (param_2 == 0x1010101) goto LAB_140001be9;
  if (param_2 < 0x1010102) {
    switch(param_2) {
    case 0x10284:
      uVar10 = GetXmitLinkSpeed(param_1);
      *(undefined8 *)param_4 = uVar10;
      break;
    case 0x10285:
      uVar10 = GetRcvLinkSpeed(param_1);
      *(undefined8 *)param_4 = uVar10;
      break;
    default:
      goto switchD_140001c8a_caseD_10286;
    case 0x10287:
      memset(param_4,0,0xd8);
      param_4[3] = 2;
      iVar8 = (cVar3 != '\x06') + 1;
      *param_4 = iVar8;
      param_4[2] = iVar8;
      puVar12 = param_1;
      iVar8 = GetMTUSize(param_1);
      param_4[4] = iVar8;
      *(undefined1 *)(param_4 + 5) = 1;
      uVar10 = GetXmitLinkSpeed(puVar12);
      *(undefined8 *)(param_4 + 6) = uVar10;
      uVar10 = GetRcvLinkSpeed(puVar12);
      *(undefined8 *)(param_4 + 8) = uVar10;
      *(undefined8 *)(param_4 + 10) = param_1[0x19];
      *(undefined8 *)(param_4 + 0xc) = param_1[0x1a];
      *(undefined8 *)(param_4 + 0xe) = param_1[0x1b];
      *(undefined8 *)(param_4 + 0x10) = param_1[0x1c];
      *(undefined8 *)(param_4 + 0x12) = param_1[0x1d];
      *(undefined8 *)(param_4 + 0x14) = param_1[0x1e];
      *(undefined8 *)(param_4 + 0x16) = param_1[0x1f];
      *(undefined8 *)(param_4 + 0x18) = param_1[0x20];
      *(undefined8 *)(param_4 + 0x1a) = param_1[0x21];
      *(undefined8 *)(param_4 + 0x1c) = param_1[0x22];
      *(undefined8 *)(param_4 + 0x1e) = param_1[0x23];
      *(undefined8 *)(param_4 + 0x20) = param_1[0x24];
      *(undefined8 *)(param_4 + 0x22) = param_1[0x25];
      *(undefined8 *)(param_4 + 0x24) = param_1[0x26];
      *(undefined8 *)(param_4 + 0x26) = param_1[0x27];
      param_4[0x34] = *(int *)(param_1 + 0x2e);
      break;
    case 0x10288:
    case 0x1028a:
      goto switchD_140001c8a_caseD_10288;
    case 0x1028c:
      *param_4 = 2;
    }
  }
  else {
switchD_140001c8a_caseD_10286:
    memset(param_4,0,(ulonglong)*param_3);
    uVar14 = 0xc00000bb;
  }
LAB_140001bfb:
  KeReleaseSpinLock(param_1 + 0xf,uVar7);
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar8 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar8 == 1) {
    WanpDeleteAdapter((longlong)param_1);
  }
  return uVar14;
}



===== GetPacketIPInfo @ 140001ec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetPacketIPInfo(longlong param_1,undefined2 *param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  undefined1 auStack_868 [32];
  undefined4 local_848;
  undefined1 local_838 [2048];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_868;
  memset(local_838,0,0x800);
  if (param_1 == 0) {
    return 0xc023000f;
  }
  uVar1 = *(uint *)(param_1 + 0x18);
  if (0x13 < uVar1) {
    local_848 = 0;
    pbVar3 = (byte *)NdisGetDataBuffer(param_1,0x14,local_838);
    if ((pbVar3 != (byte *)0x0) && ((*pbVar3 & 0xf0) == 0x40)) {
      if (param_2 != (undefined2 *)0x0) {
        *param_2 = 2;
      }
      if (param_3 == (undefined8 *)0x0) {
        return 0;
      }
      *(undefined4 *)param_3 = *(undefined4 *)(pbVar3 + 0xc);
      return 0;
    }
  }
  if (uVar1 < 0x28) {
    return 0xc023000f;
  }
  local_848 = 0;
  puVar4 = (undefined4 *)NdisGetDataBuffer(param_1,0x28,local_838);
  if (puVar4 == (undefined4 *)0x0) {
    return 0xc023000f;
  }
  if (((byte)*puVar4 & 0xf0) != 0x60) {
    return 0xc023000f;
  }
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = 0x17;
  }
  if (param_3 != (undefined8 *)0x0) {
    uVar2 = *(undefined8 *)(puVar4 + 4);
    *param_3 = *(undefined8 *)(puVar4 + 2);
    param_3[1] = uVar2;
  }
  return 0;
}



===== NetioRestoreNetBuffer @ 140002000 =====

void NetioRestoreNetBuffer(longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x58) = 0;
  for (iVar5 = ((*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x54)) - *(int *)(param_1 + 0x50)) +
               *(int *)(param_1 + 0x18) + iVar5; iVar5 != 0; iVar5 = iVar5 - iVar2) {
    puVar4 = *(undefined8 **)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = *puVar4;
    iVar2 = *(int *)(puVar4 + 5);
    NetioFreeMdl();
  }
  lVar3 = *(longlong *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x54);
  uVar1 = *(uint *)(param_1 + 0x50);
  *(uint *)(param_1 + 0x28) = uVar1;
  *(longlong *)(param_1 + 8) = lVar3;
  *(uint *)(param_1 + 0x10) = uVar1;
  if ((lVar3 != 0) && (*(uint *)(lVar3 + 0x28) < uVar1)) {
    NdisAdjustNetBufferCurrentMdl(param_1);
  }
  return;
}



===== WanNdisSendComplete @ 1400020a0 =====

void WanNdisSendComplete(undefined8 param_1,longlong *param_2,uint param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  
  if (param_2 != (longlong *)0x0) {
    do {
      plVar4 = (longlong *)*param_2;
      lVar5 = *(longlong *)((ulonglong)*(ushort *)(param_2[2] + 10) + 0x10 + param_2[2]);
      NdisFreeNetBufferListContext(param_2,8);
      NetioAdvanceNetBufferList(param_2,0xe);
      if (lVar5 == 0) {
        NetioDereferenceNetBufferList(param_2,param_3 & 1);
      }
      else {
        for (puVar6 = (undefined8 *)param_2[1]; puVar6 != (undefined8 *)0x0;
            puVar6 = (undefined8 *)*puVar6) {
          if (*(int *)((longlong)param_2 + 0x8c) == 0) {
            LOCK();
            plVar2 = (longlong *)(*(longlong *)(lVar5 + 8) + 0x110);
            *plVar2 = *plVar2 + (ulonglong)*(uint *)(puVar6 + 3);
            UNLOCK();
          }
          else {
            LOCK();
            plVar2 = (longlong *)(*(longlong *)(lVar5 + 8) + 0x138);
            *plVar2 = *plVar2 + 1;
            UNLOCK();
          }
        }
        NetioDereferenceNetBufferList(param_2,param_3 & 1);
        LOCK();
        piVar1 = (int *)(lVar5 + 0x60);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          WanpDeleteConnEntry(lVar5);
        }
      }
      param_2 = plVar4;
    } while (plVar4 != (longlong *)0x0);
  }
  return;
}



===== NetioAdvanceNetBuffer @ 1400021a0 =====

void NetioAdvanceNetBuffer(longlong param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 != 0) {
    uVar1 = *(int *)(param_1 + 0x10) + param_2;
    if (uVar1 < *(uint *)(*(longlong *)(param_1 + 8) + 0x28)) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_2;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - param_2;
      *(uint *)(param_1 + 0x10) = uVar1;
      return;
    }
    NdisAdvanceNetBufferDataStart(param_1,param_2,0,0);
  }
  return;
}



===== IsDialInAdapter @ 1400021f0 =====

undefined8 IsDialInAdapter(undefined8 *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = g_leDialInAdapterList;
  while( true ) {
    if ((undefined8 **)puVar1 == &g_leDialInAdapterList) {
      return 0;
    }
    if (puVar1 + -4 == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return 1;
}



===== WanNdisStatus @ 140002230 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanNdisStatus(longlong param_1,char *param_2)

{
  char cVar1;
  
  if (((g_fPagesLocked != '\0') && (*param_2 == -0x68)) && (*(short *)(param_2 + 2) == 0x70)) {
    cVar1 = DAT_14000aa66;
    if (param_1 != 0xcabb1e4) {
      cVar1 = DAT_14000ab86;
    }
    if (cVar1 != '\0') {
      if (*(int *)(param_2 + 0x14) == 0x40010008) {
        WanpLinkUpIndication(*(int **)(param_2 + 0x30),param_1 == 0xcabb1e4);
        LOCK();
        _g_DebugCounter = _g_DebugCounter + 1;
        UNLOCK();
      }
      else if (*(int *)(param_2 + 0x14) == 0x40010009) {
        WanpLinkDownIndication((longlong)*(int **)(param_2 + 0x30),0);
        LOCK();
        _DAT_14000a7e4 = _DAT_14000a7e4 + 1;
        UNLOCK();
      }
    }
  }
  return;
}



===== WanpNdisOpenAdapter @ 1400022c0 =====

undefined8 WanpNdisOpenAdapter(longlong param_1,undefined8 param_2,char param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  bool bVar4;
  undefined8 local_48;
  undefined8 local_40;
  undefined *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  undefined *local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_48 = 0x380187;
  local_2c = 0;
  bVar4 = param_3 == '\0';
  local_14 = 0;
  local_40 = *(undefined8 *)(param_1 + 0x10);
  local_38 = &DAT_14000a1c4;
  if (bVar4) {
    local_38 = &DAT_14000a414;
  }
  puVar2 = &DAT_14000aa68;
  local_30 = DAT_14000a1c0;
  if (bVar4) {
    local_30 = DAT_14000a410;
  }
  local_28 = &DAT_14000aaa8;
  if (bVar4) {
    local_28 = &DAT_14000abc8;
  }
  local_20 = &DAT_14000a1d4;
  local_18 = DAT_14000a1d0;
  if (bVar4) {
    local_20 = &DAT_14000a424;
    local_18 = DAT_14000a420;
  }
  uVar3 = 0xcabb1e4;
  uVar1 = DAT_14000a160;
  if (bVar4) {
    uVar3 = 0xcabb1e6;
    puVar2 = &DAT_14000ab88;
    uVar1 = DAT_14000a3b0;
  }
  uVar1 = NdisOpenAdapterEx(uVar1,uVar3,&local_48,param_2,puVar2);
  if ((int)uVar1 != 0x103) {
    WanNdisOpenAdapterComplete((ulonglong)uVar3,(int)uVar1);
    uVar1 = 0x103;
  }
  return uVar1;
}



===== FlpFreeNetBufferListChain @ 1400023c0 =====

void FlpFreeNetBufferListChain(longlong param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x58);
  NetioCompleteCopyNetBufferListChain();
  uVar4 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar3 + 0x50));
  KeReleaseSpinLock(*(undefined8 *)(lVar3 + 0x50),uVar4);
  while (param_2 != 0) {
    param_2 = param_2 + -1;
    LOCK();
    piVar1 = (int *)(lVar3 + 0x60);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      WanpDeleteConnEntry(lVar3);
    }
  }
  return;
}



===== WanpReleaseResource @ 140002440 =====

void WanpReleaseResource(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 != 1) {
    KeSetEvent(param_1 + 2,0,0);
  }
  return;
}



===== WanpRemoveAllAdaptersFromIp @ 140002480 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanpRemoveAllAdaptersFromIp(char param_1)

{
  longlong ******pppppplVar1;
  longlong ******pppppplVar2;
  longlong ******pppppplVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *****ppppplVar7;
  code *pcVar8;
  longlong *plVar9;
  undefined1 uVar10;
  longlong lVar11;
  longlong *****ppppplVar12;
  longlong ******pppppplVar13;
  longlong ******local_58;
  longlong ******local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_38,1,0);
  local_50 = (longlong ******)&local_58;
  local_58 = (longlong ******)&local_58;
  uVar10 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  plVar5 = g_leMappedAdapterList;
  do {
    while( true ) {
      do {
        plVar9 = plVar5;
        if ((longlong **)plVar9 == &g_leMappedAdapterList) {
          KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
          do {
            KeReleaseSpinLock(&g_rwlAdapterLock,uVar10);
            while( true ) {
              pppppplVar1 = local_58;
              if ((longlong *******)local_58 == &local_58) {
                return;
              }
              if (((longlong *******)local_58[1] != &local_58) ||
                 (pppppplVar13 = (longlong ******)*local_58,
                 (longlong ******)pppppplVar13[1] != local_58)) goto LAB_140002805;
              pppppplVar2 = local_58 + -2;
              pppppplVar13[1] = (longlong *****)&local_58;
              pppppplVar3 = local_58 + 0xd;
              local_58 = pppppplVar13;
              uVar10 = KeAcquireSpinLockRaiseToDpc(pppppplVar3);
              if (param_1 == '\0') {
                ppppplVar12 = pppppplVar1[0x14];
              }
              else {
                ppppplVar12 = pppppplVar1[0x13];
              }
              KeReleaseSpinLock(pppppplVar1 + 0xd,uVar10);
              WanpDeleteInterfaceFromIp((longlong)ppppplVar12);
              uVar10 = KeAcquireSpinLockRaiseToDpc(pppppplVar1 + 0xd);
              LOCK();
              pppppplVar13 = pppppplVar1 + 0xe;
              iVar4 = *(int *)pppppplVar13;
              *(int *)pppppplVar13 = *(int *)pppppplVar13 + -1;
              UNLOCK();
              if (iVar4 == 1) {
                WanpDeleteAdapter((longlong)pppppplVar2);
              }
              KeReleaseSpinLock(pppppplVar1 + 0xd,uVar10);
              uVar10 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
              KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
              pppppplVar13 = pppppplVar1 + 0x14;
              if (param_1 == '\0') {
                pppppplVar13 = pppppplVar1 + 0x13;
              }
              if (*pppppplVar13 != (longlong *****)0x0) break;
              ppppplVar12 = *pppppplVar2;
              if (((longlong ******)ppppplVar12[1] != pppppplVar2) ||
                 (ppppplVar7 = pppppplVar1[-1], (longlong ******)*ppppplVar7 != pppppplVar2))
              goto LAB_140002805;
              *ppppplVar7 = (longlong ****)ppppplVar12;
              ppppplVar12[1] = (longlong ****)ppppplVar7;
              KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
              KeReleaseSpinLock(&g_rwlAdapterLock,uVar10);
              LOCK();
              pppppplVar1 = pppppplVar1 + 0xe;
              iVar4 = *(int *)pppppplVar1;
              *(int *)pppppplVar1 = *(int *)pppppplVar1 + -1;
              UNLOCK();
              if (iVar4 == 1) {
                WanpDeleteAdapter((longlong)pppppplVar2);
              }
            }
            KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
          } while( true );
        }
        plVar5 = (longlong *)*plVar9;
        if (param_1 == '\0') {
          lVar11 = plVar9[0x16];
        }
        else {
          lVar11 = plVar9[0x15];
        }
      } while (lVar11 == 0);
      KeAcquireSpinLockAtDpcLevel(plVar9 + 0xf);
      if (*(int *)(lVar11 + 0x6c) != 2) break;
      KeReleaseSpinLockFromDpcLevel(plVar9 + 0xf);
      KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
      KeReleaseSpinLock(&g_rwlAdapterLock,uVar10);
      WanRemoveRouterInterface(*(int *)(lVar11 + 0x20));
      uVar10 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
      KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
    }
    if ((int)plVar9[0x17] == 1) {
      lVar11 = *plVar9;
      if ((*(longlong **)(lVar11 + 8) != plVar9) ||
         (plVar6 = (longlong *)plVar9[1], (longlong *)*plVar6 != plVar9)) {
LAB_140002805:
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        return;
      }
      _g_ulNumMappedAdapters = _g_ulNumMappedAdapters + -1;
      *plVar6 = lVar11;
      *(longlong **)(lVar11 + 8) = plVar6;
      plVar9[1] = (longlong)plVar9;
      *plVar9 = (longlong)plVar9;
      *(undefined1 *)((longlong)plVar9 + 0x94) = 1;
    }
    pppppplVar1 = (longlong ******)(plVar9 + 2);
    plVar9[3] = (longlong)pppppplVar1;
    *pppppplVar1 = (longlong *****)pppppplVar1;
    if ((longlong *******)local_58[1] != &local_58) goto LAB_140002805;
    *pppppplVar1 = (longlong *****)local_58;
    plVar9[3] = (longlong)&local_58;
    local_58[1] = (longlong *****)pppppplVar1;
    LOCK();
    *(int *)(plVar9 + 0x10) = (int)plVar9[0x10] + 1;
    UNLOCK();
    local_58 = pppppplVar1;
    KeReleaseSpinLockFromDpcLevel(plVar9 + 0xf);
  } while( true );
}



===== WanpCloseNdisWan @ 140002840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WanpCloseNdisWan(char param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_108;
  undefined1 *local_100;
  undefined4 local_f8;
  code *local_30;
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(&local_128,0,0x108);
  local_30 = WanpClearPacketFilterComplete;
  local_100 = local_28;
  local_124 = 1;
  local_128 = 0xf80196;
  lVar5 = DAT_14000aa68;
  if (param_1 == '\0') {
    lVar5 = DAT_14000ab88;
  }
  local_108 = 0x1010e;
  local_f8 = 4;
  iVar1 = NdisOidRequest(lVar5,&local_128);
  if (iVar1 != 0x103) {
    lVar5 = DAT_14000aa68;
    if (param_1 == '\0') {
      lVar5 = DAT_14000ab88;
    }
    WanpClearPacketFilterComplete(lVar5);
    if (iVar1 != 0) goto LAB_14000292e;
  }
  local_138 = 0;
  puVar2 = &DAT_14000ab50;
  if (param_1 == '\0') {
    puVar2 = &DAT_14000ac70;
  }
  KeWaitForSingleObject(puVar2,0,0,0);
LAB_14000292e:
  lVar5 = DAT_14000aa68;
  if (param_1 == '\0') {
    lVar5 = DAT_14000ab88;
  }
  if (lVar5 != 0) {
    iVar1 = NdisCloseAdapterEx();
    puVar3 = &DAT_14000aa66;
    if (param_1 == '\0') {
      puVar3 = &DAT_14000ab86;
    }
    *puVar3 = 0;
    puVar4 = &DAT_14000aa68;
    if (param_1 == '\0') {
      puVar4 = &DAT_14000ab88;
    }
    *puVar4 = 0;
    if (iVar1 != 0x103) {
      lVar5 = 0xcabb1e4;
      if (param_1 == '\0') {
        lVar5 = 0xcabb1e6;
      }
      WanNdisCloseAdapterComplete(lVar5);
    }
  }
  return;
}



===== WanNdisSetOptions @ 1400029d0 =====

undefined8 WanNdisSetOptions(void)

{
  return 0;
}



===== WanNdisReceivePacketsCalloutRoutine @ 1400029e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WanNdisReceivePacketsCalloutRoutine(undefined8 *param_1)

{
  (*(code *)*param_1)(param_1[1],param_1[2],*(undefined1 *)(param_1 + 3));
  return;
}



===== WanpRemoveAllAdapters @ 140002a10 =====

void WanpRemoveAllAdapters(char param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  bool bVar4;
  
  WanpRemoveAllAdaptersFromIp(param_1);
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  LOCK();
  iVar1 = DAT_14000ad30 + 1;
  UNLOCK();
  bVar4 = DAT_14000ad30 == 0;
  DAT_14000ad30 = iVar1;
  if (bVar4) {
    KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  }
  KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
  puVar2 = g_leDialInAdapterList;
  if (g_ulNumDialInAdapters == 0) {
    LOCK();
    UNLOCK();
    if (DAT_14000ad30 == 1) {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeReleaseSpinLock(&DAT_14000ad28,uVar3);
    }
    else {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeLowerIrql(uVar3);
    }
    WanpSetCloseEventIfRequired(param_1);
    LOCK();
    iVar1 = g_wrBindMutex + -1;
    UNLOCK();
    bVar4 = g_wrBindMutex != 1;
    g_wrBindMutex = iVar1;
    if (bVar4) {
      KeSetEvent(&DAT_14000adc8,0,0);
    }
  }
  else {
    for (; (undefined8 **)puVar2 != &g_leDialInAdapterList; puVar2 = (undefined8 *)*puVar2) {
      KeAcquireSpinLockAtDpcLevel(puVar2 + 0xb);
      WanpUnmapServerInterface((longlong)(puVar2 + -4),uVar3,param_1);
      WanpAcquireResource(&g_wrBindMutex);
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
      LOCK();
      iVar1 = DAT_14000ad30 + 1;
      UNLOCK();
      bVar4 = DAT_14000ad30 == 0;
      DAT_14000ad30 = iVar1;
      if (bVar4) {
        KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
      }
      KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
    }
    LOCK();
    UNLOCK();
    if (DAT_14000ad30 == 1) {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeReleaseSpinLock(&DAT_14000ad28,uVar3);
    }
    else {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeLowerIrql(uVar3);
    }
    WanpReleaseResource(&g_wrBindMutex);
  }
  return;
}



===== WanpSetCloseEventIfRequired @ 140002c00 =====

void WanpSetCloseEventIfRequired(char param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  
  cVar2 = DAT_14000aaac;
  if (param_1 == '\0') {
    cVar2 = DAT_14000abcc;
  }
  if (cVar2 != '\0') {
    puVar3 = &DAT_14000ab38;
    if (param_1 == '\0') {
      puVar3 = &DAT_14000ac58;
    }
    KeSetEvent(puVar3,0,0);
    uVar1 = KeAcquireSpinLockRaiseToDpc(&g_rlStateLock);
    puVar4 = &DAT_14000aa64;
    if (param_1 == '\0') {
      puVar4 = &DAT_14000ab84;
    }
    *puVar4 = 0;
    KeReleaseSpinLock(&g_rlStateLock,uVar1);
    puVar4 = &DAT_14000aaac;
    if (param_1 == '\0') {
      puVar4 = &DAT_14000abcc;
    }
    *puVar4 = 0;
  }
  return;
}



===== DereferenceAdapterContext @ 140002cb0 =====

void DereferenceAdapterContext(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x84);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== WanpDoNdisRequest @ 140002ce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WanpDoNdisRequest(undefined8 param_1,undefined4 param_2,undefined8 param_3,
                           undefined4 param_4,undefined4 *param_5,undefined *param_6,char param_7)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  *(undefined **)(param_5 + 0x3e) = param_6;
  param_5[1] = 1;
  *param_5 = 0xf80196;
  param_5[8] = param_2;
  *(undefined8 *)(param_5 + 10) = param_3;
  param_5[0xc] = param_4;
  uVar3 = DAT_14000aa68;
  if (param_7 == '\0') {
    uVar3 = DAT_14000ab88;
  }
  uVar2 = NdisOidRequest(uVar3,param_5);
  iVar1 = (int)uVar2;
  if (iVar1 != 0x103) {
    if (param_6 != (undefined *)0x0) {
      uVar3 = DAT_14000aa68;
      if (param_7 == '\0') {
        uVar3 = DAT_14000ab88;
      }
      (*(code *)param_6)(uVar3,param_5,uVar2 & 0xffffffff);
    }
    uVar2 = uVar2 & 0xffffffff;
    if (iVar1 == 0) {
      uVar2 = 0x103;
    }
  }
  return uVar2;
}



===== NetioExpandKernelStackAndCallout @ 140002d9c =====

int NetioExpandKernelStackAndCallout
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              uint param_5,byte param_6)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 uVar7;
  
  if (param_6 < 2) {
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
    if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
      uVar4 = *(uint *)(param_1 + 0x48 + (ulonglong)param_5 * 0x10);
      if ((uVar4 & 1) == 0) {
        *(uint *)(param_1 + 0x48 + (ulonglong)param_5 * 0x10) = uVar4 | 1;
        lVar6 = *(longlong *)(param_1 + ((ulonglong)param_5 + 4) * 0x10);
        goto LAB_140002df7;
      }
    }
  }
  lVar6 = 0;
LAB_140002df7:
  while (iVar3 = KeExpandKernelStackAndCalloutEx
                           (WanNdisReceivePacketsCalloutRoutine,param_3,0x4800,uVar7,lVar6),
        iVar3 == -0x3fffffe9) {
    if (lVar6 != 0) goto LAB_140002e8f;
    if (param_6 < 2) {
      KeWaitForSingleObject(param_1,0,0,0,0);
      uVar2 = *(uint *)(param_1 + 0x38);
      uVar5 = (ulonglong)uVar2;
      uVar4 = *(uint *)(param_1 + 0x48 + uVar5 * 0x10);
      if ((uVar4 & 1) != 0) goto LAB_140002eaf;
    }
    else {
      uVar5 = (ulonglong)param_5;
      uVar4 = *(uint *)(param_1 + 0x48 + uVar5 * 0x10);
      uVar2 = param_5;
      if ((uVar4 & 1) != 0) {
        return -0x3fffffe9;
      }
    }
    lVar6 = *(longlong *)(param_1 + ((ulonglong)uVar2 + 4) * 0x10);
    *(uint *)(param_1 + 0x48 + uVar5 * 0x10) = uVar4 | 1;
  }
  if (lVar6 != 0) {
LAB_140002e8f:
    if (param_6 < 2) {
      puVar1 = (uint *)(param_1 + 0x48 + (ulonglong)*(uint *)(param_1 + 0x38) * 0x10);
      *puVar1 = *puVar1 & 0xfffffffe;
LAB_140002eaf:
      KeReleaseMutex(param_1,0);
    }
    else {
      puVar1 = (uint *)(param_1 + 0x48 + (ulonglong)param_5 * 0x10);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
  }
  return iVar3;
}



===== __report_gsfailure @ 140002ef0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledDeviceUsageNoInline @ 140002f00 =====

ulonglong Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledDeviceUsageNoInline
                    (void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_featureState
  ;
  if ((Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledFallback
                      (local_res8,3);
  }
  else {
    uVar1 = (ulonglong)
            (Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledFallback @ 140002f38 =====

void Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,
             &Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_descriptor);
  return;
}



===== RoReferenceEx @ 140002f54 =====

ulonglong RoReferenceEx(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar2 = *param_1;
    if ((uVar2 & 1) != 0) {
      return (ulonglong)(uVar2 & 0xffffff00);
    }
    LOCK();
    uVar1 = *param_1;
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *param_1 = uVar2 + 2;
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (!bVar3);
  return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
}



===== WanNdisBindAdapter @ 140002f80 =====

ulonglong WanNdisBindAdapter(undefined *param_1,undefined8 param_2,longlong param_3)

{
  short *psVar1;
  ushort *puVar2;
  char cVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  
  psVar1 = *(short **)(param_3 + 0x10);
  puVar2 = *(ushort **)(param_3 + 8);
  WanpAcquireResource(&g_wrBindMutex);
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rlStateLock);
  cVar3 = DAT_14000aa64;
  if (param_1 != &WanNmrV4ProviderState) {
    cVar3 = DAT_14000ab84;
  }
  if (cVar3 == '\x01') {
    uVar6 = 0;
  }
  else {
    puVar9 = &DAT_14000aa64;
    if (param_1 != &WanNmrV4ProviderState) {
      puVar9 = &DAT_14000ab84;
    }
    *puVar9 = 1;
    KeReleaseSpinLock(&g_rlStateLock,uVar4);
    puVar8 = &DAT_14000aa90;
    if (param_1 != &WanNmrV4ProviderState) {
      puVar8 = &DAT_14000abb0;
    }
    puVar7 = &DAT_14000ab70;
    if (param_1 != &WanNmrV4ProviderState) {
      puVar7 = &DAT_14000ac90;
    }
    *puVar8 = param_2;
    *puVar7 = *(undefined8 *)(param_3 + 0xa8);
    uVar5 = WanpInitNdiswanAdapterInfo(psVar1,puVar2,param_1 == &WanNmrV4ProviderState);
    uVar6 = uVar5 & 0xffffffff;
    if (((int)uVar5 == 0) || ((int)uVar5 == 0x103)) {
      uVar5 = WanpNdisOpenAdapter(param_3,param_2,param_1 == &WanNmrV4ProviderState);
      return uVar5;
    }
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rlStateLock);
    *puVar9 = 0;
    *puVar8 = 0;
  }
  KeReleaseSpinLock(&g_rlStateLock,uVar4);
  WanpReleaseResource(&g_wrBindMutex);
  return uVar6;
}



===== WanNdisRequestComplete @ 140003100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WanNdisRequestComplete(undefined8 param_1,longlong param_2,ulonglong param_3)

{
  if (*(code **)(param_2 + 0xf8) == (code *)0x0) {
    ExFreePoolWithTag(param_2);
  }
  else {
    if ((*(int *)(param_2 + 4) == 1) &&
       (param_3 = param_3 & 0xffffffff, *(int *)(param_2 + 0x20) == 0x10119)) {
      param_3 = 0;
    }
    (**(code **)(param_2 + 0xf8))(param_1,param_2,param_3);
  }
  return;
}



===== WanpClearPacketFilterComplete @ 140003150 =====

void WanpClearPacketFilterComplete(longlong param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_14000ab50;
  if (param_1 != 0xcabb1e4) {
    puVar1 = &DAT_14000ac70;
  }
  KeSetEvent(puVar1,0,0);
  return;
}



===== WanpFindDialInAdapterGivenCompartmentId @ 140003190 =====

undefined8 * WanpFindDialInAdapterGivenCompartmentId(int param_1)

{
  undefined8 *puVar1;
  
  puVar1 = g_leDialInAdapterList;
  while( true ) {
    if ((undefined8 **)puVar1 == &g_leDialInAdapterList) {
      return (undefined8 *)0x0;
    }
    if (*(int *)(puVar1 + 0x2a) == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1 + -4;
}



===== WanpFindDialInAdapterGivenInterfaceIndex @ 1400031c0 =====

undefined8 * WanpFindDialInAdapterGivenInterfaceIndex(int param_1,int param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = g_leDialInAdapterList;
  while( true ) {
    if ((undefined8 **)puVar1 == &g_leDialInAdapterList) {
      return (undefined8 *)0x0;
    }
    if (param_2 == 0) {
      lVar2 = puVar1[0x12];
    }
    else {
      lVar2 = puVar1[0x11];
    }
    if ((lVar2 != 0) && (*(int *)(lVar2 + 0x20) == param_1)) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1 + -4;
}



===== WanpLastOidComplete @ 140003210 =====

void WanpLastOidComplete(longlong param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  code *pcVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  ExFreePoolWithTag(param_2,0);
  if (param_3 == 0) {
    puVar3 = &DAT_14000aab0;
    if (param_1 != 0xcabb1e4) {
      puVar3 = &DAT_14000abd0;
    }
    pcVar2 = WanpNdisCompleteBindAdapter;
  }
  else {
    bVar4 = param_1 != 0xcabb1e4;
    piVar1 = &DAT_14000aaa4;
    if (bVar4) {
      piVar1 = &DAT_14000abc4;
    }
    *piVar1 = param_3;
    piVar1 = &DAT_14000aaa0;
    if (bVar4) {
      piVar1 = &DAT_14000abc0;
    }
    puVar3 = &DAT_14000aad0;
    *piVar1 = param_3;
    if (bVar4) {
      puVar3 = &DAT_14000abf0;
    }
    pcVar2 = WanpCloseNdisWan;
  }
  puVar3[3] = (ulonglong)(param_1 == 0xcabb1e4);
  puVar3[2] = pcVar2;
  *puVar3 = 0;
  ExQueueWorkItem(puVar3,1);
  return;
}



===== WanpSetLookaheadComplete @ 1400032e0 =====

void WanpSetLookaheadComplete(longlong param_1,undefined4 *param_2,int param_3)

{
  if (param_3 == 0) {
    param_2[0x40] = 9;
    WanpDoNdisRequest(param_1,0x1010e,param_2 + 0x40,4,param_2,WanpSetPacketFilterComplete,
                      param_1 == 0xcabb1e4);
  }
  else {
    WanpLastOidComplete(param_1,param_2,param_3);
  }
  return;
}



===== WanpSetPacketFilterComplete @ 140003340 =====

void WanpSetPacketFilterComplete(longlong param_1,undefined4 *param_2,int param_3)

{
  if (param_3 == 0) {
    *(undefined2 *)((longlong)param_2 + 0x102) = 0xe;
    *(undefined2 *)(param_2 + 0x40) = 2;
    WanpDoNdisRequest(param_1,0x10119,param_2 + 0x40,4,param_2,WanpLastOidComplete,
                      param_1 == 0xcabb1e4);
  }
  else {
    WanpLastOidComplete(param_1,param_2,param_3);
  }
  return;
}



===== WanpSetProtocolTypeComplete @ 1400033b0 =====

void WanpSetProtocolTypeComplete(longlong param_1,undefined4 *param_2,int param_3)

{
  if (param_3 == 0) {
    param_2[0x40] = 0x80;
    WanpDoNdisRequest(param_1,0x1010f,param_2 + 0x40,4,param_2,WanpSetLookaheadComplete,
                      param_1 == 0xcabb1e4);
  }
  else {
    WanpLastOidComplete(param_1,param_2,param_3);
  }
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000340c =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 1400034e4 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400035c8 =====

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
LAB_140003720:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140003713:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140003720;
      if (uVar5 == 5) goto LAB_140003713;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140003748 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400037cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400038bc =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400039cc =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
               (uint param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = (uint *)*param_3;
  if (param_2 == 3) {
    uVar4 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar4 = 0x20;
  }
  if ((*(char *)((longlong)param_3 + 0x1e) == '\0') && (*(char *)((longlong)param_3 + 0x1d) == '\0')
     ) {
    uVar3 = *puVar2;
    if ((uVar3 & 2) != 0) {
      while ((uVar3 & 1) == (param_1 & 1)) {
        LOCK();
        uVar1 = *puVar2;
        bVar5 = uVar3 == uVar1;
        if (bVar5) {
          *puVar2 = uVar4 | uVar3;
        }
        else {
          uVar3 = uVar1;
        }
        UNLOCK();
        if (bVar5) {
          return;
        }
        if ((uVar3 & 2) == 0) {
          return;
        }
      }
    }
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 140003a30 =====

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



===== wil_details_IsEnabledFallback @ 140003b90 =====

uint wil_details_IsEnabledFallback(ulonglong param_1,int param_2,undefined8 *param_3)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_MapReportingKind @ 140003c24 =====

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



===== FreeConnection @ 140003cc4 =====

void FreeConnection(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x38),0);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  if (*(char *)(param_1 + 0xf8) != '\0') {
    DereferenceAdapterContext(*(longlong *)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
  }
  ExFreeToNPagedLookasideList(&g_llConnBlocks,param_1);
  return;
}



===== UpdateInterfaceIndexImpl @ 140003d24 =====

void UpdateInterfaceIndexImpl(longlong param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  NdisIfGetNetLuidFromInterfaceIndex(param_2,local_res8);
  uVar3 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_1 + 0x50));
  *(undefined8 *)(param_1 + 0x48) = local_res8[0];
  KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),uVar3);
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    WanpDeleteConnEntry(param_1);
  }
  return;
}



===== UpdateInterfaceIndexWorkItem @ 140003da0 =====

void UpdateInterfaceIndexWorkItem(longlong param_1)

{
  UpdateInterfaceIndexImpl(*(longlong *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x28));
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WanpRemoveConnections @ 140003dd4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanpRemoveConnections(char param_1,int param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
  uVar4 = 1;
  if (1 < g_ulConnTableSize) {
    do {
      uVar3 = (uint)uVar4;
      lVar1 = *(longlong *)(g_puipConnTable + uVar4 * 8);
      if (lVar1 != 0) {
        KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(lVar1 + 0x50));
        if (((*(int *)(lVar1 + 100) == 0) && (*(char *)(lVar1 + 4) == param_1)) &&
           (*(int *)(lVar1 + 0x10c) == param_2)) {
          KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(lVar1 + 0x50));
          KeReleaseSpinLock(&g_rlConnTableLock,uVar2);
          WanpLinkDownIndication(0,uVar3);
          LOCK();
          _DAT_14000a7e4 = _DAT_14000a7e4 + 1;
          UNLOCK();
          uVar2 = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
          if (g_ulConnTableSize <= uVar3) break;
          if (*(longlong *)(g_puipConnTable + uVar4 * 8) == lVar1) {
            *(undefined8 *)(g_puipConnTable + uVar4 * 8) = 0;
            _g_rgulConns = _g_rgulConns + -1;
          }
        }
        else {
          KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(lVar1 + 0x50));
        }
      }
      uVar4 = (ulonglong)(uVar3 + 1);
    } while (uVar3 + 1 < g_ulConnTableSize);
  }
  KeReleaseSpinLock(&g_rlConnTableLock,uVar2);
  return;
}



===== DriverCleanup @ 140003f30 =====

void DriverCleanup(void)

{
  if (DAT_14000aaf8 != 0) {
    IoDeleteDevice();
    DAT_14000aaf8 = 0;
  }
  if (DAT_14000ac18 != 0) {
    IoDeleteDevice();
    DAT_14000ac18 = 0;
  }
  WanpSetupExternalName(0,L"\\DosDevices\\WanArp",'\0');
  WanpSetupExternalName(0,L"\\DosDevices\\WanArpV6",'\0');
  WanpFreeDriverStructures();
  return;
}



===== DriverWait @ 140003fa8 =====

void DriverWait(void)

{
  if (DAT_14000a9c0 != 0) {
    NmrWaitForClientDeregisterComplete();
  }
  return;
}



===== EnterModuleCode @ 140003fd0 =====

undefined1 EnterModuleCode(char param_1)

{
  char cVar1;
  uint uVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined7 in_register_00000009;
  undefined1 uVar6;
  ulonglong local_res10;
  
  cVar1 = DAT_14000aa64;
  if (param_1 == '\0') {
    cVar1 = DAT_14000ab84;
  }
  uVar6 = 1;
  uVar2 = 0;
  while( true ) {
    if (cVar1 != '\0') {
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_rlStateLock);
      iVar5 = DAT_14000ab00;
      if (param_1 == '\0') {
        iVar5 = DAT_14000ac20;
      }
      if (iVar5 == 2) {
        piVar4 = &DAT_14000ab68;
        iVar5 = DAT_14000ab68;
        if (param_1 == '\0') {
          iVar5 = DAT_14000ac88;
        }
        if (param_1 == '\0') {
          piVar4 = &DAT_14000ac88;
        }
        *piVar4 = iVar5 + 1;
      }
      else {
        uVar6 = 0;
      }
      KeReleaseSpinLock(&g_rlStateLock,uVar3);
      return uVar6;
    }
    if (2 < uVar2) break;
    local_res10 = (ulonglong)((uVar2 + 2) * -50000000);
    KeDelayExecutionThread(CONCAT71(in_register_00000009,1),0,&local_res10);
    cVar1 = DAT_14000aa64;
    if (param_1 == '\0') {
      cVar1 = DAT_14000ab84;
    }
    in_register_00000009 = 0;
    uVar2 = uVar2 + 1;
  }
  return 0;
}



===== ExitModuleCode @ 1400040cc =====

void ExitModuleCode(char param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&g_rlStateLock);
  piVar3 = &DAT_14000ab68;
  iVar5 = DAT_14000ab68;
  if (param_1 == '\0') {
    iVar5 = DAT_14000ac88;
  }
  if (param_1 == '\0') {
    piVar3 = &DAT_14000ac88;
  }
  *piVar3 = iVar5 + -1;
  iVar2 = DAT_14000ab00;
  if (param_1 == '\0') {
    iVar2 = DAT_14000ac20;
  }
  if ((iVar2 == 0) && (iVar5 + -1 == 0)) {
    puVar4 = &DAT_14000ab20;
    if (param_1 == '\0') {
      puVar4 = &DAT_14000ac40;
    }
    KeSetEvent(puVar4,0);
  }
  KeReleaseSpinLock(&g_rlStateLock,uVar1);
  return;
}



===== Feature_132113720__private_IsEnabledDeviceUsageNoInline @ 14000417c =====

ulonglong Feature_132113720__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_132113720__private_featureState;
  if ((Feature_132113720__private_featureState & 0x10) == 0) {
    uVar1 = Feature_132113720__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_132113720__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_132113720__private_IsEnabledFallback @ 1400041b4 =====

void Feature_132113720__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_132113720__private_descriptor);
  return;
}



===== FlProcessorAddHandler @ 1400041d0 =====

void FlProcessorAddHandler(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = NetioStackBlockProcessorAddHandler(DAT_14000a248,param_1,param_2);
  if (-1 < iVar1) {
    NetioStackBlockProcessorAddHandler(DAT_14000a498,param_1,param_2);
  }
  return;
}



===== WaitTillDriverDereferenced @ 140004224 =====

void WaitTillDriverDereferenced(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = g_DriverRefCount + -1;
  UNLOCK();
  bVar2 = g_DriverRefCount != 0;
  g_DriverRefCount = iVar1;
  if (bVar2) {
    KeWaitForSingleObject(&g_DriverRefCountEvent,0,0,0,0);
  }
  return;
}



===== WanpAcquireResource @ 140004268 =====

void WanpAcquireResource(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + 1;
  UNLOCK();
  if (iVar1 != 0) {
    KeWaitForSingleObject(param_1 + 2,0,0,0,0);
  }
  return;
}



===== WanpClearPendingIrps @ 1400042a8 =====

void WanpClearPendingIrps(char param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 *puVar4;
  longlong *plVar5;
  undefined1 local_res8 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar4 = auStack_28;
  local_res8[0] = 0;
  plVar5 = &g_lePendingV4IrpList;
  if (param_1 == '\0') {
    plVar5 = &g_lePendingV6IrpList;
  }
  do {
    IoAcquireCancelSpinLock(local_res8);
    plVar1 = (longlong *)*plVar5;
    if (plVar1 == plVar5) {
LAB_14000433d:
      *(undefined8 *)(puVar4 + -8) = 0x140004348;
      IoReleaseCancelSpinLock(puVar4[0x30]);
      return;
    }
    if (((longlong *)plVar1[1] != plVar5) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1))
    {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar4 = auStack_20;
      goto LAB_14000433d;
    }
    *plVar5 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar5;
    LOCK();
    plVar1[-8] = 0;
    UNLOCK();
    plVar1[-0xe] = 0;
    *(undefined4 *)(plVar1 + -0xf) = 0xc000000e;
    IoReleaseCancelSpinLock(local_res8[0]);
    IofCompleteRequest(plVar1 + -0x15,2);
  } while( true );
}



===== WanpDriverCleanupNotification @ 140004360 =====

void WanpDriverCleanupNotification(char param_1)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&g_rlStateLock);
  piVar2 = &DAT_14000ab04;
  iVar3 = DAT_14000ab04;
  if (param_1 == '\0') {
    iVar3 = DAT_14000ac24;
  }
  if (param_1 == '\0') {
    piVar2 = &DAT_14000ac24;
  }
  *piVar2 = iVar3 + -1;
  if (iVar3 + -1 == 0) {
    WanpStopModule(uVar1,param_1);
  }
  else {
    KeReleaseSpinLock(&g_rlStateLock,CONCAT71((int7)((ulonglong)piVar2 >> 8),uVar1));
  }
  return;
}



===== WanpFreeDriverStructures @ 1400043d8 =====

void WanpFreeDriverStructures(void)

{
  if (g_puipConnTable != 0) {
    ExFreePoolWithTag(g_puipConnTable,0);
    g_puipConnTable = 0;
    g_ulConnTableSize = 0;
  }
  ExDeleteNPagedLookasideList(&g_llConnBlocks);
  ExDeleteNPagedLookasideList(&g_llNotificationBlocks);
  return;
}



===== WanpProcessorAddCallback @ 140004440 =====

void WanpProcessorAddCallback(undefined8 param_1,int *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((*param_3 < 0) && (*param_2 == 0)) {
    return;
  }
  KeWaitForSingleObject(&DAT_14000a960,0,0,0,0);
  if (DAT_14000a958 == '\0') {
    iVar3 = *param_2;
    if (iVar3 == 0) {
      DAT_14000a940 = param_2[1] + 1;
      iVar3 = FlProcessorAddHandler(param_2[1],0);
      *param_3 = iVar3;
    }
    else {
      if (iVar3 == 1) {
        uVar2 = KeQueryActiveProcessorCountEx(0xffff);
        uVar4 = DAT_14000a940;
        if (DAT_14000a940 < uVar2) {
          while( true ) {
            uVar1 = uVar4 + 1;
            DAT_14000a940 = uVar1;
            iVar3 = FlProcessorAddHandler(uVar4,0);
            *param_3 = iVar3;
            if (iVar3 < 0) break;
            iVar3 = FlProcessorAddHandler(uVar4,1);
            *param_3 = iVar3;
            if ((iVar3 < 0) || (uVar4 = uVar1, uVar2 <= uVar1)) break;
          }
        }
        iVar3 = *param_2;
        uVar4 = param_2[1];
      }
      else {
        if (iVar3 != 2) goto LAB_14000452d;
        uVar4 = param_2[1];
        iVar3 = 2;
        DAT_14000a940 = uVar4;
      }
      FlProcessorAddHandler(uVar4,iVar3);
    }
  }
  else {
    *param_3 = 0;
  }
LAB_14000452d:
  KeReleaseMutex(&DAT_14000a960,0);
  return;
}



===== WanpStartModule @ 140004564 =====

undefined4 WanpStartModule(char param_1)

{
  undefined1 uVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&g_rlStateLock);
  piVar4 = &DAT_14000ab04;
  iVar6 = DAT_14000ab04;
  if (param_1 == '\0') {
    iVar6 = DAT_14000ac24;
  }
  if (param_1 == '\0') {
    piVar4 = &DAT_14000ac24;
  }
  piVar2 = &DAT_14000ab00;
  *piVar4 = iVar6 + 1;
  if (param_1 == '\0') {
    piVar2 = &DAT_14000ac20;
  }
  if (iVar6 + 1 == 1) {
    *piVar2 = 2;
    puVar3 = &DAT_14000ab08;
    if (param_1 == '\0') {
      puVar3 = &DAT_14000ac28;
    }
    KeSetEvent(puVar3,0,0);
    KeReleaseSpinLock(&g_rlStateLock,uVar1);
    uVar5 = 0;
  }
  else {
    uVar5 = 0x103;
    if (*piVar2 != 1) {
      uVar5 = 0;
    }
    KeReleaseSpinLock(&g_rlStateLock,CONCAT71(0x14000ac,uVar1));
  }
  return uVar5;
}



===== WanpStopModule @ 140004648 =====

void WanpStopModule(undefined1 param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = &DAT_14000ab00;
  if (param_2 == '\0') {
    puVar2 = &DAT_14000ac20;
  }
  *puVar2 = 0;
  iVar1 = DAT_14000ab68;
  if (param_2 == '\0') {
    iVar1 = DAT_14000ac88;
  }
  KeReleaseSpinLock(&g_rlStateLock,CONCAT71(0x14000ac,param_1));
  if (iVar1 != 0) {
    puVar3 = &DAT_14000ab20;
    if (param_2 == '\0') {
      puVar3 = &DAT_14000ac40;
    }
    do {
      do {
        iVar1 = KeWaitForSingleObject(puVar3,0,0,0,0);
      } while (iVar1 == 0xc0);
    } while ((iVar1 == 0x101) || (iVar1 == 0x102));
  }
  WanpClearPendingIrps(param_2);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1400046f8 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140009f1f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140004720 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004880 =====

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



===== RtlStringCchCatExW @ 140004904 =====

uint RtlStringCchCatExW(short *param_1,ulonglong param_2,wchar_t *param_3,undefined8 *param_4,
                       ulonglong *param_5)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  short *psVar4;
  wchar_t *pwVar5;
  longlong local_18 [2];
  
  local_18[0] = 0;
  lVar2 = 0;
  if (((param_1 == (short *)0x0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = RtlStringLengthWorkerW(param_1,param_2,local_18);
      lVar2 = local_18[0];
    }
  }
  if (-1 < (int)uVar1) {
    uVar3 = param_2 - lVar2;
    psVar4 = param_1 + lVar2;
    uVar1 = 0;
    pwVar5 = L"";
    if (param_3 != (wchar_t *)0x0) {
      pwVar5 = param_3;
    }
    if (uVar3 < 2) {
      if (*pwVar5 != L'\0') {
        if (param_1 == (short *)0x0) {
          return 0xc000000d;
        }
        uVar1 = 0x80000005;
      }
    }
    else {
      local_18[0] = 0;
      uVar1 = RtlStringCopyWorkerW(psVar4,uVar3,local_18,(longlong)pwVar5);
      uVar3 = uVar3 - local_18[0];
      psVar4 = psVar4 + local_18[0];
      if (((uVar1 + 0x80000000 & 0x80000000) == 0) && (uVar1 != 0x80000005)) {
        return uVar1;
      }
    }
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = psVar4;
    }
    if (param_5 != (ulonglong *)0x0) {
      *param_5 = uVar3;
    }
  }
  return uVar1;
}



===== RtlStringCchCopyExW @ 140004a14 =====

uint RtlStringCchCopyExW(short *param_1,ulonglong param_2,undefined8 param_3,longlong *param_4,
                        longlong *param_5)

{
  uint uVar1;
  longlong lVar2;
  longlong local_res18;
  
  if (((param_1 == (short *)0x0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  else {
    if (param_2 == 0) {
      if (param_1 == (short *)0x0) {
        return 0xc000000d;
      }
      uVar1 = 0x80000005;
      lVar2 = 0;
    }
    else {
      local_res18 = 0;
      uVar1 = RtlStringCopyWorkerW(param_1,param_2,&local_res18,0x14000858c);
      lVar2 = param_2 - local_res18;
      param_1 = param_1 + local_res18;
      if (((uVar1 + 0x80000000 & 0x80000000) == 0) && (uVar1 != 0x80000005)) {
        return uVar1;
      }
    }
    if (param_4 != (longlong *)0x0) {
      *param_4 = (longlong)param_1;
    }
    if (param_5 != (longlong *)0x0) {
      *param_5 = lVar2;
    }
  }
  return uVar1;
}



===== RtlStringCopyWorkerW @ 140004ad8 =====

uint RtlStringCopyWorkerW(short *param_1,longlong param_2,longlong *param_3,longlong param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar5 = 0;
  if (param_2 != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = param_4 - (longlong)param_1;
    do {
      if ((lVar2 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      lVar2 = lVar2 + -1;
      param_1 = param_1 + 1;
      lVar5 = lVar5 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar3 = param_1 + -1;
  if (param_2 != 0) {
    psVar3 = param_1;
  }
  *psVar3 = 0;
  if (param_3 != (longlong *)0x0) {
    lVar2 = lVar5 + -1;
    if (param_2 != 0) {
      lVar2 = lVar5;
    }
    *param_3 = lVar2;
  }
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== RtlStringLengthWorkerW @ 140004b54 =====

uint RtlStringLengthWorkerW(short *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  for (; (lVar2 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
    lVar2 = lVar2 + -1;
  }
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = param_2 - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== RtlStringValidateDestAndLengthW @ 140004b9c =====

uint RtlStringValidateDestAndLengthW(short *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  
  if (param_2 - 1U < 0x7fffffff) {
    uVar1 = RtlStringLengthWorkerW(param_1,param_2,param_3);
  }
  else {
    *param_3 = 0;
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WanRemoveRouterInterface @ 140004bc8 =====

undefined8 WanRemoveRouterInterface(int param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  uint *puVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  uint uVar9;
  
  uVar8 = 0;
  uVar6 = KeAcquireSpinLockRaiseToDpc(&g_rwlIfLock);
  KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
  plVar7 = WanpFindInterfaceGivenIndex(param_1);
  if (plVar7 == (longlong *)0x0) {
    KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
    KeReleaseSpinLock(&g_rwlIfLock,uVar6);
    uVar8 = 0xc0000034;
  }
  else {
    lVar2 = *plVar7;
    if ((*(longlong **)(lVar2 + 8) != plVar7) ||
       (plVar3 = (longlong *)plVar7[1], (longlong *)*plVar3 != plVar7)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar8 = (*pcVar5)();
      return uVar8;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
    KeReleaseSpinLockFromDpcLevel(&g_rwlIfLock);
    puVar4 = (uint *)plVar7[0x13];
    if (puVar4 != (uint *)0x0) {
      uVar9 = *puVar4;
      uVar1 = *(uint *)(plVar7 + 0x14);
      plVar7[0x13] = 0;
      *(undefined4 *)(plVar7 + 0x14) = 0;
      KeReleaseSpinLock(plVar7 + 7,uVar6);
      WanpRemoveSubnetFilters(puVar4,uVar1);
      while (uVar9 != 0) {
        uVar9 = uVar9 - 1;
        LOCK();
        plVar3 = plVar7 + 8;
        lVar2 = *plVar3;
        *(int *)plVar3 = (int)*plVar3 + -1;
        UNLOCK();
        if ((int)lVar2 == 1) {
          WanpDeleteInterface(plVar7);
        }
      }
      ExFreePoolWithTag(puVar4,0);
      KeAcquireSpinLockRaiseToDpc(plVar7 + 7);
    }
    WanpDeleteRouterInterface((longlong)plVar7);
    LOCK();
    plVar3 = plVar7 + 8;
    lVar2 = *plVar3;
    *(int *)plVar3 = (int)*plVar3 + -1;
    UNLOCK();
    if ((int)lVar2 == 1) {
      WanpDeleteInterface(plVar7);
    }
    LOCK();
    plVar3 = plVar7 + 8;
    lVar2 = *plVar3;
    *(int *)plVar3 = (int)*plVar3 + -1;
    UNLOCK();
    if ((int)lVar2 == 1) {
      WanpDeleteInterface(plVar7);
    }
    LOCK();
    plVar3 = plVar7 + 8;
    lVar2 = *plVar3;
    *(int *)plVar3 = (int)*plVar3 + -1;
    UNLOCK();
    if ((int)lVar2 == 1) {
      WanpDeleteInterface(plVar7);
    }
  }
  return uVar8;
}



===== _guard_check_icall @ 140004d90 =====

void _guard_check_icall(void)

{
  return;
}



===== WanNmrAttachClient @ 140004da0 =====

int WanNmrAttachClient(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                      longlong param_5,undefined8 *param_6,longlong *param_7)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  bool bVar6;
  
  puVar1 = (undefined *)(param_2 + -8);
  puVar4 = (undefined8 *)0x0;
  cVar2 = DAT_14000ab6c;
  if (puVar1 != &WanNmrV4ProviderState) {
    cVar2 = DAT_14000ac8c;
  }
  if (cVar2 == '\0') {
    WanpAcquireResource(&g_wrBindMutex);
  }
  if (*(short *)(param_5 + 4) == *(short *)(param_2 + 0x54)) {
    puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x43706c46);
    if (puVar4 == (undefined8 *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      LOCK();
      bVar6 = *(longlong *)(param_2 + 0xd0) == 0;
      if (bVar6) {
        *(longlong *)(param_2 + 0xd0) = (longlong)puVar4;
      }
      UNLOCK();
      if (bVar6) {
        puVar4[1] = param_5;
        *puVar4 = param_4;
        puVar4[3] = param_1;
        puVar4[5] = puVar1;
        *param_6 = *(undefined8 *)(param_2 + 0xd0);
        *param_7 = param_2 + 0x60;
        puVar5 = &DAT_14000aaf0;
        if (puVar1 != &WanNmrV4ProviderState) {
          puVar5 = &DAT_14000ac10;
        }
        *puVar5 = 1;
        *(undefined4 *)(*(longlong *)(param_2 + 0xd0) + 0x20) = 2;
        iVar3 = NdisRegisterProtocolDriver(puVar1,param_2 + 0xd8,param_2 + 0x158);
        if (iVar3 != 0) {
          *(undefined8 *)(param_2 + 0xd0) = 0;
        }
      }
      else {
        iVar3 = -0x3fffffff;
      }
    }
  }
  else {
    iVar3 = -0x3ffffd47;
  }
  if (cVar2 == '\0') {
    WanpReleaseResource(&g_wrBindMutex);
  }
  if ((iVar3 != 0) && (puVar4 != (undefined8 *)0x0)) {
    ExFreePoolWithTag(puVar4,0);
  }
  return iVar3;
}



===== WanNmrCleanupClientContext @ 140004f30 =====

void WanNmrCleanupClientContext(longlong param_1)

{
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0xd8) = 0;
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WanNmrDeregisterProviderComplete @ 140004f5c =====

void WanNmrDeregisterProviderComplete(longlong param_1)

{
  int iVar1;
  bool bVar2;
  
  *(undefined8 *)(param_1 + 0x48) = 0;
  LOCK();
  iVar1 = g_DriverRefCount + -1;
  UNLOCK();
  bVar2 = g_DriverRefCount == 0;
  g_DriverRefCount = iVar1;
  if (bVar2) {
    KeSetEvent(&g_DriverRefCountEvent,0,0);
  }
  return;
}



===== WanNmrDetachClient @ 140004fa0 =====

undefined8 WanNmrDetachClient(longlong param_1)

{
  undefined *puVar1;
  longlong lVar2;
  
  puVar1 = *(undefined **)(param_1 + 0x28);
  lVar2 = IoAllocateWorkItem();
  *(longlong *)(puVar1 + 0x1d8) = lVar2;
  if (lVar2 == 0) {
    WanNmrpDetachClientWorkerRoutine(0,puVar1);
  }
  else {
    *(undefined8 *)(*(longlong *)(puVar1 + 0xd8) + 0x10) =
         *(undefined8 *)(*(longlong *)(puVar1 + 0xd8) + 0x18);
    IoQueueWorkItem(*(undefined8 *)(puVar1 + 0x1d8),WanNmrpDetachClientWorkerRoutine,1,puVar1);
  }
  return 0x103;
}



===== WanNmrFinalizeDetach @ 14000502c =====

void WanNmrFinalizeDetach(longlong param_1)

{
  NmrProviderDetachClientComplete(*(undefined8 *)(*(longlong *)(param_1 + 0xd8) + 0x10));
  return;
}



===== WanNmrpCleanupProviderState @ 140005054 =====

void WanNmrpCleanupProviderState(char *param_1)

{
  if (((param_1 != (char *)0x0) && (*param_1 != '\0')) && (*(longlong *)(param_1 + 0x248) != 0)) {
    NetioFreeStackBlock(*(longlong *)(param_1 + 0x248),0x42537257);
    param_1[0x248] = '\0';
    param_1[0x249] = '\0';
    param_1[0x24a] = '\0';
    param_1[0x24b] = '\0';
    param_1[0x24c] = '\0';
    param_1[0x24d] = '\0';
    param_1[0x24e] = '\0';
    param_1[0x24f] = '\0';
  }
  return;
}



===== WanNmrpDeregisterV4Provider @ 140005098 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanNmrpDeregisterV4Provider(void)

{
  if (DAT_14000a050 != 0) {
    LOCK();
    _FlStartedModules = _FlStartedModules + -0x4000;
    UNLOCK();
    NmrDeregisterProvider(DAT_14000a050);
  }
  return;
}



===== WanNmrpDeregisterV6Provider @ 1400050d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanNmrpDeregisterV6Provider(void)

{
  if (DAT_14000a2a0 != 0) {
    LOCK();
    _FlStartedModules = _FlStartedModules + -0x40;
    UNLOCK();
    NmrDeregisterProvider(DAT_14000a2a0);
  }
  if (g_hNdisIfProviderHandle != 0) {
    NdisIfDeregisterProvider();
    g_hNdisIfProviderHandle = 0;
  }
  return;
}



===== WanNmrpDetachClientWorkerRoutine @ 140005130 =====

void WanNmrpDetachClientWorkerRoutine(undefined8 param_1,undefined *param_2)

{
  int *piVar1;
  int iVar2;
  
  WanpDeinitializeNdis(param_2 == &WanNmrV4ProviderState);
  if (*(longlong *)(param_2 + 0x1d8) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_2 + 0x1d8) = 0;
  }
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_2 + 0xd8) + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 2) {
    NmrProviderDetachClientComplete(*(undefined8 *)(*(longlong *)(param_2 + 0xd8) + 0x10));
  }
  return;
}



===== WanNmrpInitializeProviderState @ 1400051a8 =====

undefined8 WanNmrpInitializeProviderState(undefined1 *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = 1;
    lVar1 = NetioAllocateAndInitializeStackBlock(0,0x42537257);
    *(longlong *)(param_1 + 0x248) = lVar1;
    if (lVar1 == 0) {
      *param_1 = 0;
      uVar2 = 0xc000009a;
    }
  }
  return uVar2;
}



===== WanNmrpWaitV4Provider @ 1400051fc =====

void WanNmrpWaitV4Provider(void)

{
  if (DAT_14000a050 != 0) {
    NmrWaitForProviderDeregisterComplete();
    WanNmrDeregisterProviderComplete(0x14000a008);
  }
  return;
}



===== WanNmrpWaitV6Provider @ 140005230 =====

void WanNmrpWaitV6Provider(void)

{
  if (DAT_14000a2a0 != 0) {
    NmrWaitForProviderDeregisterComplete();
    WanNmrDeregisterProviderComplete(0x14000a258);
  }
  return;
}



===== WanIpQueryInterface @ 140005270 =====

undefined8 WanIpQueryInterface(void)

{
  return 0xc00000bb;
}



===== WanIpQueryRealAf @ 140005280 =====

short WanIpQueryRealAf(longlong param_1)

{
  return (-(ushort)(*(char *)(param_1 + 0x14) != '\0') & 0xffeb) + 0x17;
}



===== WanIpQuerySetInterfaceDirect @ 1400052a0 =====

undefined8
WanIpQuerySetInterfaceDirect
          (longlong param_1,int param_2,int param_3,undefined8 param_4,longlong param_5,int param_6,
          undefined8 param_7,int param_8)

{
  longlong lVar1;
  
  if (param_2 != 0) {
    return 0xc00000f0;
  }
  if (*(int *)(param_1 + 0x6c) == 1) {
    if (param_3 != 0) {
      return 0xc00000f1;
    }
    if ((param_6 != 0x88) || (param_8 != 0)) {
      return 0xc0000206;
    }
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48);
    if (lVar1 != 0) {
      *(longlong *)(param_5 + 0x80) = lVar1;
      return 0;
    }
  }
  return 0xc00000bb;
}



===== WanIpQuerySubInterface @ 140005310 =====

undefined8 WanIpQuerySubInterface(longlong *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if (*(uint *)(param_1 + 2) < 0x20) {
    *(undefined4 *)(param_1 + 2) = 0x20;
    return 0xc0000023;
  }
  lVar1 = *param_1;
  puVar2 = (undefined8 *)param_1[1];
  uVar3 = *(undefined8 *)(lVar1 + 0x118);
  *puVar2 = *(undefined8 *)(lVar1 + 0x110);
  puVar2[1] = uVar3;
  uVar3 = *(undefined8 *)(lVar1 + 0x128);
  puVar2[2] = *(undefined8 *)(lVar1 + 0x120);
  puVar2[3] = uVar3;
  return 0;
}



===== NetioRetreatNetBuffer @ 14000534c =====

undefined8 NetioRetreatNetBuffer(longlong param_1)

{
  undefined8 uVar1;
  
  if (*(uint *)(param_1 + 0x10) < 0xe) {
    uVar1 = NdisRetreatNetBufferDataStart(param_1,0xe,0,NetioAllocateMdl_exref);
  }
  else {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -0xe;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 0xe;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) - 0xe;
    uVar1 = 0;
  }
  return uVar1;
}



===== WanpQueueNetBufferLists @ 140005390 =====

undefined8 WanpQueueNetBufferLists(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  char cVar3;
  longlong lVar4;
  longlong *plVar5;
  char cVar6;
  bool bVar7;
  bool bVar8;
  undefined1 uVar9;
  int iVar10;
  longlong lVar11;
  undefined8 uVar12;
  longlong lVar13;
  
  lVar4 = *(longlong *)(param_1 + 0x18);
  lVar13 = 0;
  cVar3 = *(char *)(param_1 + 0x14);
  cVar6 = DAT_14000aa66;
  if (cVar3 == '\0') {
    cVar6 = DAT_14000ab86;
  }
  if (cVar6 == '\0') {
    return 0;
  }
  if (param_2 == (longlong *)0x0) {
    return 0;
  }
  lVar1 = lVar4 + 0x78;
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x38);
  iVar10 = *(int *)(param_1 + 0x90);
  if (iVar10 == 2) {
    *(undefined4 *)(param_1 + 0x90) = 3;
    bVar8 = true;
  }
  else {
    bVar7 = false;
    bVar8 = false;
    if ((iVar10 != 3) && (iVar10 != 4)) goto LAB_140005548;
  }
  do {
    bVar7 = bVar8;
    plVar5 = (longlong *)*param_2;
    if (*(uint *)(param_1 + 0x88) < 0x20) {
      lVar11 = NetioAllocateAndReferenceCloneNetBufferList(param_2,1);
      if (lVar11 != 0) {
        *(ulonglong *)(lVar11 + 0xd0) = (ulonglong)*(uint *)(param_2 + 0x1a);
        if (lVar13 == 0) {
          lVar13 = lVar11;
        }
        *(longlong *)(lVar11 + 0x90) = param_2[0x12];
        iVar10 = NdisAllocateNetBufferListContext(lVar11,8,0,0x7750444e);
        if (-1 < iVar10) {
          iVar10 = NetioRetreatNetBufferList(lVar11,0xe);
          if (-1 < iVar10) {
            uVar12 = DAT_14000aa68;
            if (cVar3 == '\0') {
              uVar12 = DAT_14000ab88;
            }
            *(undefined8 *)(lVar11 + 0x78) = uVar12;
            **(longlong **)(param_1 + 0x80) = lVar11;
            *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
            *(longlong *)(param_1 + 0x80) = lVar11;
            goto LAB_14000552e;
          }
          NdisFreeNetBufferListContext(lVar11,8);
        }
        NetioDereferenceNetBufferList(lVar11,1);
      }
    }
    else {
      plVar2 = (longlong *)(lVar4 + 0x138);
      *plVar2 = *plVar2 + 1;
    }
LAB_14000552e:
    param_2 = plVar5;
    bVar8 = bVar7;
  } while (plVar5 != (longlong *)0x0);
LAB_140005548:
  **(undefined8 **)(param_1 + 0x80) = 0;
  if ((bVar7) && (lVar13 != 0)) {
    WanpHandleDemandDialCallOutRequest(lVar13,param_1);
  }
  if (*(int *)(param_1 + 0x90) == 4) {
    WanpTransmitQueuedPackets(*(longlong *)(param_1 + 0x18),uVar9,*(char *)(param_1 + 0x14));
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x38);
    KeReleaseSpinLock(lVar1,uVar9);
  }
  return 0;
}



===== WanpDropNetbiosPacket @ 1400055c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WanpDropNetbiosPacket(undefined8 param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  memset(local_68,0,0x46);
  local_78 = 0;
  pbVar2 = (byte *)NdisGetDataBuffer(param_1,0x14,local_68);
  if ((pbVar2 != (byte *)0x0) && (pbVar2[9] == 0x11)) {
    bVar1 = *pbVar2;
    pbVar2 = (byte *)0x0;
    uVar3 = (bVar1 & 0xf) * 4 + 10;
    if (uVar3 <= param_2) {
      local_78 = 0;
      pbVar2 = (byte *)NdisGetDataBuffer(param_1,uVar3,local_68,2);
    }
  }
  return (ulonglong)pbVar2 & 0xffffffffffffff00;
}



===== FlAttachNaProvider @ 140005680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FlAttachNaProvider(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined *local_18;
  undefined8 local_10;
  
  lVar3 = ExAllocatePool2(0x40,0x20,0x73646e57);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar3 + 0x18) = param_1;
    iVar1 = NmrClientAttachProvider(param_1,lVar3,&FlNaClientDispatch,lVar3,(longlong *)(lVar3 + 8))
    ;
    if (iVar1 < 0) {
      ExFreePoolWithTag(lVar3,0);
    }
    else {
      local_10 = 0;
      DAT_14000a9d4 = 2;
      local_18 = &NPI_MS_NDIS_MODULEID;
      DAT_14000a9c8 = lVar3;
      iVar2 = (**(code **)(*(longlong *)(lVar3 + 8) + 8))(&local_18);
      if (-1 < iVar2) {
        DAT_14000a9d0 = (undefined4)local_10;
      }
    }
  }
  return iVar1;
}



===== FlCleanupNaProviderContext @ 140005760 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FlCleanupNaProviderContext(void)

{
  _DAT_14000a9d0 = 0;
  DAT_14000a9c0 = 0;
  DAT_14000a9c8 = 0;
  ExFreePoolWithTag(0,0);
  return;
}



===== FlDetachNaProvider @ 1400057a0 =====

uint FlDetachNaProvider(longlong param_1)

{
  int iVar1;
  
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_1 + 0x18);
  iVar1 = DAT_14000a9d4;
  LOCK();
  DAT_14000a9d4 = DAT_14000a9d4 + -1;
  UNLOCK();
  return ~-(uint)(iVar1 == 2) & 0x103;
}



===== FlNaStop @ 1400057d0 =====

void FlNaStop(void)

{
  if (DAT_14000a9c0 != 0) {
    NmrDeregisterClient();
  }
  return;
}



===== FllwanpGetCompartmentInformation @ 1400057f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FllwanpGetCompartmentInformation
              (undefined4 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined1 local_58 [8];
  undefined4 local_50;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  longlong local_30;
  undefined4 local_28;
  undefined4 local_20;
  longlong local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar3 = RoReferenceEx((uint *)&DAT_14000a9d4);
  if ((char)uVar3 == '\0') {
    iVar2 = -0x3fffffff;
  }
  else {
    memset(local_58,0,0x50);
    local_20 = 0;
    local_50 = DAT_14000a9d0;
    local_48 = &NPI_MS_NDIS_MODULEID;
    local_10 = 0x10;
    local_c = 0x10;
    local_40 = 7;
    local_38 = 1;
    local_28 = 4;
    local_34 = param_1;
    local_30 = param_2;
    local_18 = param_4;
    iVar2 = (**(code **)(*(longlong *)(DAT_14000a9c8 + 8) + 0x10))(local_58);
    if (-1 < iVar2) {
      memset(local_58,0,0x50);
      local_20 = 0;
      local_50 = DAT_14000a9d0;
      local_48 = &NPI_MS_NDIS_MODULEID;
      local_40 = 7;
      local_38 = 1;
      local_28 = 4;
      local_10 = 8;
      local_c = 8;
      local_34 = param_1;
      local_30 = param_2;
      local_18 = param_3;
      iVar2 = (**(code **)(*(longlong *)(DAT_14000a9c8 + 8) + 0x10))(local_58);
      if (-1 < iVar2) {
        local_40 = 0;
        local_18 = param_3 + 8;
        local_34 = 0;
        local_c = 0;
        local_28 = 8;
        local_20 = 2;
        local_10 = 4;
        local_30 = param_3;
        iVar2 = (**(code **)(*(longlong *)(DAT_14000a9c8 + 8) + 0x10))(local_58);
      }
    }
    LOCK();
    iVar1 = DAT_14000a9d4 + -2;
    UNLOCK();
    bVar4 = DAT_14000a9d4 == 3;
    DAT_14000a9d4 = iVar1;
    if (bVar4) {
      NmrClientDetachProviderComplete(*(undefined8 *)(DAT_14000a9c8 + 0x10));
    }
  }
  return iVar2;
}



===== WdmlibRtlInitUnicodeStringEx @ 1400059b0 =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== __GSHandlerCheck @ 140005a08 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140005a2c =====

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



===== __cpu_features_init @ 140005aa0 =====

/* WARNING: Removing unreachable block (ram,0x000140005b0a) */
/* WARNING: Removing unreachable block (ram,0x000140005ab9) */
/* WARNING: Removing unreachable block (ram,0x000140005aaa) */

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



===== __security_check_cookie @ 140005b70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005bb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005be0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005be0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005c10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140005c80 =====

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



===== memset @ 140005f80 =====

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



===== __memset_repmovs @ 1400060c0 =====

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



===== __memset_query @ 140006140 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400061c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006300 =====

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



===== __memset_spec_plain @ 140006380 =====

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



===== WanpRemoveAllConnections @ 14000e010 =====

void WanpRemoveAllConnections(char param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 1;
  if (1 < g_ulConnTableSize) {
    do {
      lVar1 = *(longlong *)(uVar3 * 8 + g_puipConnTable);
      if (((lVar1 != 0) && (*(int *)(lVar1 + 100) != 3)) && (*(char *)(lVar1 + 4) == param_1)) {
        WanpLinkDownIndication(0,(uint)uVar3);
        *(undefined8 *)(uVar3 * 8 + g_puipConnTable) = 0;
      }
      uVar2 = (uint)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < g_ulConnTableSize);
  }
  return;
}



===== GetAdapterFromDeviceGuid @ 14000e090 =====

char GetAdapterFromDeviceGuid(longlong *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  char cVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  bool bVar8;
  
  *param_2 = 0;
  cVar5 = '\0';
  uVar2 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  LOCK();
  iVar1 = DAT_14000ad30 + 1;
  UNLOCK();
  bVar8 = DAT_14000ad30 == 0;
  DAT_14000ad30 = iVar1;
  if (bVar8) {
    KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  }
  KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
  puVar4 = g_leMappedAdapterList;
  puVar6 = (undefined8 *)0x0;
  while (puVar7 = puVar4, (undefined8 **)puVar7 != &g_leMappedAdapterList) {
    lVar3 = puVar7[0x13] - *param_1;
    if (lVar3 == 0) {
      lVar3 = puVar7[0x14] - param_1[1];
    }
    if (lVar3 == 0) goto LAB_14000e173;
    puVar6 = puVar7;
    puVar4 = (undefined8 *)*puVar7;
  }
  puVar7 = puVar6;
  for (puVar4 = g_leDialInAdapterList; (undefined8 **)puVar4 != &g_leDialInAdapterList;
      puVar4 = (undefined8 *)*puVar4) {
    puVar7 = puVar4 + -4;
    lVar3 = puVar4[0xf] - *param_1;
    if (lVar3 == 0) {
      lVar3 = puVar4[0x10] - param_1[1];
    }
    if (lVar3 == 0) goto LAB_14000e173;
  }
LAB_14000e175:
  LOCK();
  UNLOCK();
  if (DAT_14000ad30 == 1) {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeReleaseSpinLock(&DAT_14000ad28,uVar2);
  }
  else {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeLowerIrql(uVar2);
  }
  if (cVar5 != '\0') {
    *param_2 = puVar7;
  }
  return cVar5;
LAB_14000e173:
  cVar5 = '\x01';
  goto LAB_14000e175;
}



===== IsBindingPresent @ 14000e1d8 =====

undefined8 IsBindingPresent(char param_1,longlong param_2)

{
  if (param_1 == '\0') {
    if (*(longlong *)(param_2 + 0xb0) == 0) {
      return 0;
    }
  }
  else if (*(longlong *)(param_2 + 0xa8) == 0) {
    return 0;
  }
  return 1;
}



===== WanIpAddInterfaceComplete @ 14000e200 =====

void WanIpAddInterfaceComplete(longlong *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *param_1;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x38);
  *(int *)(lVar1 + 0x68) = (int)param_1[2];
  if (*(longlong *)(lVar1 + 0x60) != 0) {
    KeSetEvent(*(longlong *)(lVar1 + 0x60),0,0);
  }
  KeReleaseSpinLock(lVar1 + 0x38,uVar2);
  return;
}



===== WanIpAddSubInterfaceComplete @ 14000e280 =====

void WanIpAddSubInterfaceComplete(longlong *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *param_1;
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar1 + 0x50));
  *(int *)(lVar1 + 0x90) = (int)param_1[2];
  if (*(longlong *)(lVar1 + 0x88) != 0) {
    KeSetEvent(*(longlong *)(lVar1 + 0x88),0,0);
  }
  KeReleaseSpinLock(*(undefined8 *)(lVar1 + 0x50),uVar2);
  return;
}



===== WanIpDeleteDialOutSubInterfaceComplete @ 14000e300 =====

void WanIpDeleteDialOutSubInterfaceComplete(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *param_1;
  LOCK();
  piVar1 = (int *)(lVar3 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    FreeConnection(lVar3);
  }
  return;
}



===== WanIpDeleteInterfaceComplete @ 14000e330 =====

void WanIpDeleteInterfaceComplete(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  undefined *puVar5;
  
  lVar4 = *param_1;
  cVar3 = *(char *)(lVar4 + 0x14);
  LOCK();
  piVar1 = (int *)(lVar4 + 0x40);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(lVar4,0);
  }
  lVar4 = DAT_14000a0d8;
  if (cVar3 == '\0') {
    lVar4 = DAT_14000a328;
  }
  LOCK();
  piVar1 = (int *)(lVar4 + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    puVar5 = &WanNmrV4ProviderState;
    if (cVar3 == '\0') {
      puVar5 = &WanNmrV6ProviderState;
    }
    WanNmrFinalizeDetach((longlong)puVar5);
  }
  return;
}



===== WanIpDeleteSubInterfaceComplete @ 14000e3a0 =====

void WanIpDeleteSubInterfaceComplete(longlong *param_1)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = *param_1;
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    WanpIpDeleteSubInterfaceCompleteWorkItem(lVar1);
  }
  else {
    *(undefined8 *)(lVar1 + 0xa8) = 0;
    *(code **)(lVar1 + 0xb8) = WanpIpDeleteSubInterfaceCompleteWorkItem;
    *(longlong *)(lVar1 + 0xc0) = lVar1;
    ExQueueWorkItem((undefined8 *)(lVar1 + 0xa8),0);
    *(undefined1 *)(lVar1 + 200) = 1;
  }
  return;
}



===== WanpAddAdapterToIp @ 14000e400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WanpAddAdapterToIp(longlong param_1,longlong param_2,char param_3,undefined1 param_4)

{
  longlong lVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined *puVar9;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  code *local_40;
  undefined8 local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  longlong local_18;
  
  puVar9 = &WanNmrV4ProviderState;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if (param_3 == '\0') {
    puVar9 = &WanNmrV6ProviderState;
  }
  local_40 = WanIpAddInterfaceComplete;
  local_38 = **(undefined8 **)(puVar9 + 0xd8);
  local_28 = param_1 + 0x160;
  local_20 = param_2 + 0xb8;
  local_18 = param_2 + 0x58;
  local_30 = param_2;
  uVar8 = RoReferenceEx((uint *)(*(undefined8 **)(puVar9 + 0xd8) + 4));
  if ((char)uVar8 != '\0') {
    *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_2 + 0xa4);
    uVar3 = *(undefined4 *)(param_2 + 0xac);
    uVar4 = *(undefined4 *)(param_2 + 0xb0);
    uVar5 = *(undefined4 *)(param_2 + 0xb4);
    *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_2 + 0xa8);
    *(undefined4 *)(param_1 + 0x178) = uVar3;
    *(undefined4 *)(param_1 + 0x17c) = uVar4;
    *(undefined4 *)(param_1 + 0x180) = uVar5;
    KeInitializeEvent(&local_58,1);
    *(undefined8 **)(param_2 + 0x60) = &local_58;
    if (*(int *)(param_2 + 0x6c) != 2) {
      *(longlong *)(param_2 + 0x18) = param_1;
      *(undefined1 *)(param_2 + 0x30) = 6;
      if (param_3 == '\0') {
        *(longlong *)(param_1 + 0xb0) = param_2;
      }
      else {
        *(longlong *)(param_1 + 0xa8) = param_2;
      }
    }
    if (*(int *)(param_2 + 0x6c) != 0) {
      *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + 1;
    }
    LOCK();
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
    UNLOCK();
    lVar1 = param_2 + 0x38;
    KeReleaseSpinLockFromDpcLevel(lVar1);
    KeReleaseSpinLock(param_1 + 0x78,param_4);
    iVar7 = (**(code **)(*(longlong *)(*(longlong *)(puVar9 + 0xd8) + 8) + 8))(&local_40);
    LOCK();
    *(int *)(&DAT_14000a7f8 + (longlong)*(int *)(param_2 + 0x6c) * 0x10) =
         *(int *)(&DAT_14000a7f8 + (longlong)*(int *)(param_2 + 0x6c) * 0x10) + 1;
    UNLOCK();
    if (iVar7 == 0x103) {
      KeWaitForSingleObject(*(undefined8 *)(param_2 + 0x60),0,0,0,0);
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(undefined8 *)(param_2 + 0x60) = 0;
      iVar7 = *(int *)(param_2 + 0x68);
      KeReleaseSpinLock(lVar1,uVar6);
    }
    if (-1 < iVar7) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(undefined8 *)(param_2 + 0x60) = 0;
      if (*(int *)(param_2 + 0x6c) != 2) {
        LOCK();
        *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
        UNLOCK();
      }
      KeReleaseSpinLock(lVar1,uVar6);
      return iVar7;
    }
    LOCK();
    piVar2 = (int *)(param_2 + 0x40);
    iVar7 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar7 == 1) {
      ExFreePoolWithTag(param_2,0);
    }
    LOCK();
    piVar2 = (int *)(*(longlong *)(puVar9 + 0xd8) + 0x20);
    iVar7 = *piVar2;
    *piVar2 = *piVar2 + -2;
    UNLOCK();
    if (iVar7 == 3) {
      WanNmrFinalizeDetach((longlong)puVar9);
    }
  }
  return -0x3fffffff;
}



===== WanpCreateAdapter @ 14000e650 =====

undefined8
WanpCreateAdapter(undefined4 *param_1,ushort *param_2,ushort *param_3,undefined8 param_4,
                 char param_5,longlong *param_6)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  uint uVar13;
  void *pvVar14;
  
  if ((param_5 == '\x01') && (*param_6 != 0)) {
LAB_14000e8d8:
    uVar12 = 0;
  }
  else {
    *param_6 = 0;
    uVar1 = *param_2;
    if (*(longlong *)(param_3 + 4) == 0) {
      param_3 = param_2;
    }
    uVar13 = uVar1 + 2;
    if ((((uVar1 <= uVar13) && (uVar8 = uVar1 + 5, uVar13 <= uVar8)) &&
        (uVar8 = uVar8 & 0xfffffffc, uVar13 = uVar8 * 2, uVar8 <= uVar13)) &&
       (uVar13 <= uVar13 + 0x188)) {
      uVar1 = *param_3;
      uVar8 = uVar1 + 2;
      if (((uVar1 <= uVar8) && (uVar9 = uVar1 + 5, uVar8 <= uVar9)) &&
         ((uVar9 = uVar9 & 0xfffffffc, uVar13 = uVar9 + uVar13 + 0x188, uVar9 <= uVar13 &&
          ((uVar8 = (uVar1 >> 1) + uVar13, uVar13 <= uVar8 && (uVar8 <= uVar8 + 2)))))) {
        lVar10 = ExAllocatePool2(0x40,uVar8 + 2,0x61707257);
        if (lVar10 != 0) {
          *(ushort *)(lVar10 + 0x38) = *param_2;
          pvVar14 = (void *)(lVar10 + 0x18bU & 0xfffffffffffffffc);
          *(ushort *)(lVar10 + 0x3a) = *param_2;
          *(void **)(lVar10 + 0x40) = pvVar14;
          memmove(pvVar14,*(void **)(param_2 + 4),(ulonglong)*param_2);
          uVar1 = *param_2;
          *(ushort *)(lVar10 + 0x48) = uVar1;
          uVar2 = *param_2;
          pvVar14 = (void *)((longlong)pvVar14 + (ulonglong)uVar1 + 5 & 0xfffffffffffffffc);
          *(void **)(lVar10 + 0x50) = pvVar14;
          *(ushort *)(lVar10 + 0x4a) = uVar2;
          memmove(pvVar14,*(void **)(param_2 + 4),(ulonglong)*param_2);
          *(undefined2 *)(*(longlong *)(lVar10 + 0x50) + (ulonglong)(*param_2 >> 1) * 2) = 0;
          *(undefined1 *)(lVar10 + 0x95) = 1;
          uVar1 = *param_2;
          *(ushort *)(lVar10 + 0x58) = *param_3;
          pvVar14 = (void *)((longlong)pvVar14 + (ulonglong)uVar1 + 5 & 0xfffffffffffffffc);
          *(ushort *)(lVar10 + 0x5a) = *param_3;
          *(void **)(lVar10 + 0x60) = pvVar14;
          memmove(pvVar14,*(void **)(param_3 + 4),(ulonglong)*param_3);
          *(undefined2 *)(*(longlong *)(lVar10 + 0x60) + (ulonglong)(*param_3 >> 1) * 2) = 0;
          *(ulonglong *)(lVar10 + 0x70) =
               (ulonglong)*(ushort *)(lVar10 + 0x58) + 5 + (longlong)pvVar14 & 0xfffffffffffffffc;
          cVar7 = KeGetCurrentIrql();
          if (cVar7 == '\0') {
            *(ushort *)(lVar10 + 0x6a) = (*param_3 >> 1) + 1;
            RtlUnicodeStringToAnsiString(lVar10 + 0x68,param_3,0);
          }
          else {
            *(undefined2 *)(lVar10 + 0x6a) = 0;
          }
          uVar3 = *param_1;
          uVar4 = param_1[1];
          uVar5 = param_1[2];
          uVar6 = param_1[3];
          *(undefined1 *)(lVar10 + 0x94) = 0;
          *(undefined4 *)(lVar10 + 0x98) = uVar3;
          *(undefined4 *)(lVar10 + 0x9c) = uVar4;
          *(undefined4 *)(lVar10 + 0xa0) = uVar5;
          *(undefined4 *)(lVar10 + 0xa4) = uVar6;
          *(undefined4 *)(lVar10 + 0x90) = 0xffffffff;
          *(undefined4 *)(lVar10 + 0x8c) = 0xffffffff;
          *(undefined4 *)(lVar10 + 0xbc) = 0x78455300;
          *(undefined2 *)(lVar10 + 0xc0) = 0x78;
          *(char *)(lVar10 + 0xbf) = (char)((uint)*(undefined4 *)(lVar10 + 0x88) >> 8);
          *(undefined1 *)(lVar10 + 0xc0) = *(undefined1 *)(lVar10 + 0x88);
          KeInitializeSpinLock(lVar10 + 0x78);
          *(undefined4 *)(lVar10 + 0x30) = 0x61646157;
          *(undefined4 *)(lVar10 + 0x168) = 0xffffffff;
          uVar11 = Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledDeviceUsageNoInline
                             ();
          if ((int)uVar11 != 0) {
            *(undefined4 *)(lVar10 + 0x158) = 0;
          }
          *(undefined4 *)(lVar10 + 0x80) = 1;
          LOCK();
          *(int *)(lVar10 + 0x84) = *(int *)(lVar10 + 0x84) + 1;
          UNLOCK();
          *param_6 = lVar10;
          goto LAB_14000e8d8;
        }
      }
    }
    uVar12 = 0xc000009a;
  }
  return uVar12;
}



===== WanpCreateAdapterContext @ 14000e908 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
WanpCreateAdapterContext(uint *param_1,ushort *param_2,undefined8 param_3,longlong *param_4)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ushort *puVar8;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  short *psStack_b0;
  short local_a8 [48];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  *param_4 = 0;
  local_b8 = 0;
  psStack_b0 = (short *)0x0;
  memset(local_a8 + 8,0,0x50);
  local_a8[4] = 0x49;
  local_a8[5] = 0x43;
  local_a8[6] = 0x45;
  local_a8[7] = 0x5c;
  local_a8[0] = 0x5c;
  local_a8[1] = 0x44;
  local_a8[2] = 0x45;
  local_a8[3] = 0x56;
  ConvertGuidToString(param_1,local_a8 + 8,0x28);
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (local_a8[lVar3] != 0);
  uVar1 = (short)lVar3 * 2;
  psStack_b0 = local_a8;
  puVar8 = (ushort *)&local_b8;
  if (*(longlong *)(param_2 + 4) != 0) {
    puVar8 = param_2;
  }
  local_b8._0_4_ = CONCAT22(uVar1,uVar1);
  uVar4 = uVar1 + 2;
  if ((((uVar1 <= uVar4) && (uVar2 = uVar1 + 5, uVar4 <= uVar2)) &&
      (uVar2 = uVar2 & 0xfffffffc, uVar4 = uVar2 * 2, uVar2 <= uVar4)) && (uVar4 <= uVar4 + 0x188))
  {
    uVar1 = *puVar8;
    uVar2 = uVar1 + 2;
    if (((uVar1 <= uVar2) && (uVar5 = uVar1 + 5, uVar2 <= uVar5)) &&
       ((uVar5 = uVar5 & 0xfffffffc, uVar4 = uVar4 + 0x188 + uVar5, uVar5 <= uVar4 &&
        ((uVar2 = (uVar1 >> 1) + uVar4, uVar4 <= uVar2 && (uVar2 <= uVar2 + 2)))))) {
      lVar3 = ExAllocatePool2(0x40,uVar2 + 2,0x61707257);
      *param_4 = lVar3;
      if (lVar3 != 0) {
        *(ushort *)(lVar3 + 0x38) = (ushort)local_b8;
        uVar7 = lVar3 + 0x18bU & 0xfffffffffffffffc;
        *(ushort *)(*param_4 + 0x3a) = (ushort)local_b8;
        *(ulonglong *)(*param_4 + 0x40) = uVar7;
        memmove(*(void **)(*param_4 + 0x40),psStack_b0,local_b8 & 0xffff);
        uVar7 = uVar7 + (local_b8 & 0xffff) + 5 & 0xfffffffffffffffc;
        *(ushort *)(*param_4 + 0x48) = (ushort)local_b8;
        *(ushort *)(*param_4 + 0x4a) = (ushort)local_b8;
        *(ulonglong *)(*param_4 + 0x50) = uVar7;
        memmove(*(void **)(*param_4 + 0x50),psStack_b0,local_b8 & 0xffff);
        *(undefined2 *)(*(longlong *)(*param_4 + 0x50) + (local_b8 >> 1 & 0x7fff) * 2) = 0;
        *(undefined1 *)(*param_4 + 0x95) = 1;
        uVar7 = uVar7 + (local_b8 & 0xffff) + 5 & 0xfffffffffffffffc;
        *(ushort *)(*param_4 + 0x58) = *puVar8;
        *(ushort *)(*param_4 + 0x5a) = *puVar8;
        *(ulonglong *)(*param_4 + 0x60) = uVar7;
        memmove(*(void **)(*param_4 + 0x60),*(void **)(puVar8 + 4),(ulonglong)*puVar8);
        *(undefined2 *)(*(longlong *)(*param_4 + 0x60) + (ulonglong)(*puVar8 >> 1) * 2) = 0;
        *(ulonglong *)(*param_4 + 0x70) =
             (ulonglong)*(ushort *)(*param_4 + 0x58) + 5 + uVar7 & 0xfffffffffffffffc;
        *(ushort *)(*param_4 + 0x6a) = (*puVar8 >> 1) + 1;
        RtlUnicodeStringToAnsiString(*param_4 + 0x68,puVar8,0);
        lVar3 = *param_4;
        uVar4 = param_1[1];
        uVar2 = param_1[2];
        uVar5 = param_1[3];
        *(uint *)(lVar3 + 0x98) = *param_1;
        *(uint *)(lVar3 + 0x9c) = uVar4;
        *(uint *)(lVar3 + 0xa0) = uVar2;
        *(uint *)(lVar3 + 0xa4) = uVar5;
        *(undefined4 *)(*param_4 + 0x90) = 0xffffffff;
        *(undefined4 *)(*param_4 + 0x8c) = 0xffffffff;
        *(undefined1 *)(*param_4 + 0x94) = 0;
        lVar3 = *param_4;
        *(undefined4 *)(lVar3 + 0xbc) = 0x78455300;
        *(undefined2 *)(lVar3 + 0xc0) = 0x78;
        *(char *)(*param_4 + 0xbf) = (char)((uint)*(undefined4 *)(*param_4 + 0x88) >> 8);
        *(undefined1 *)(*param_4 + 0xc0) = *(undefined1 *)(*param_4 + 0x88);
        KeInitializeSpinLock(*param_4 + 0x78);
        *(undefined4 *)(*param_4 + 0x30) = 0x61646157;
        *(undefined4 *)(*param_4 + 0x168) = 0xffffffff;
        uVar7 = Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledDeviceUsageNoInline
                          ();
        if ((int)uVar7 != 0) {
          *(undefined4 *)(*param_4 + 0x158) = 0;
        }
        *(undefined4 *)(*param_4 + 0x80) = 1;
        LOCK();
        *(int *)(*param_4 + 0x84) = *(int *)(*param_4 + 0x84) + 1;
        UNLOCK();
        return 0;
      }
      uVar6 = 0xc000009a;
      goto LAB_14000ec54;
    }
  }
  uVar6 = 0xc0000095;
LAB_14000ec54:
  if (*param_4 != 0) {
    ExFreePoolWithTag(*param_4,0);
    *param_4 = 0;
  }
  return uVar6;
}



===== WanpCreateAndRegisterInterface @ 14000ec94 =====

ulonglong WanpCreateAndRegisterInterface
                    (uint *param_1,ushort *param_2,undefined8 *param_3,undefined4 param_4,
                    undefined8 param_5,char param_6,undefined4 param_7,longlong *param_8,
                    longlong *param_9)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong local_38;
  longlong local_30;
  
  local_38 = 0;
  lVar8 = 0;
  local_30 = 0;
  bVar1 = false;
  puVar9 = param_3;
  cVar2 = GetAdapterFromDeviceGuid((longlong *)param_1,&local_38);
  lVar6 = local_38;
  if ((cVar2 != '\0') && (uVar4 = IsBindingPresent(param_6,local_38), (char)uVar4 != '\0')) {
    return 0xc000000d;
  }
  if (lVar6 == 0) {
    uVar5 = WanpCreateAdapterContext(param_1,param_2,puVar9,&local_38);
    uVar7 = uVar5 & 0xffffffff;
    lVar6 = local_38;
    if ((int)uVar5 < 0) goto LAB_14000edb4;
  }
  else {
    bVar1 = true;
  }
  uVar5 = WanpCreateInterfaceContext(param_6,param_4,puVar9,param_7,&local_30);
  lVar8 = local_30;
  uVar7 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
LAB_14000edb4:
    if ((lVar6 != 0) && (!bVar1)) {
      ExFreePoolWithTag(lVar6,0);
    }
    if (lVar8 != 0) {
      ExFreePoolWithTag(lVar8,0);
    }
    return uVar7;
  }
  *(undefined8 *)(lVar6 + 0x160) = *param_3;
  if (!bVar1) {
    uVar3 = WanpRegisterInterface(param_7,param_2,lVar6,local_30);
    uVar7 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_14000edb4;
  }
  *(undefined8 *)(lVar6 + 0x160) = *param_3;
  *(longlong *)(lVar8 + 0x18) = lVar6;
  LOCK();
  *(int *)(lVar6 + 0x80) = *(int *)(lVar6 + 0x80) + 1;
  UNLOCK();
  if (param_6 == '\0') {
    *(longlong *)(local_38 + 0xb0) = local_30;
  }
  else {
    *(longlong *)(local_38 + 0xa8) = local_30;
  }
  LOCK();
  *(int *)(local_30 + 0x40) = *(int *)(local_30 + 0x40) + 1;
  UNLOCK();
  *param_8 = local_38;
  *param_9 = local_30;
  return uVar7;
}



===== WanpCreateInterfaceContext @ 14000ee08 =====

undefined8
WanpCreateInterfaceContext
          (char param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,longlong *param_5)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  lVar2 = ExAllocatePool2(0x40,0x228,0x69707257);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    *(char *)(lVar2 + 0x14) = param_1;
    *(undefined4 *)(lVar2 + 0x10) = 0x746e6957;
    *(undefined4 *)(lVar2 + 0xa4) = param_4;
    *(undefined2 *)(lVar2 + 0xb8) = 0x10e;
    *(undefined1 *)(lVar2 + 0xba) = 0;
    uVar4 = DAT_14000a170;
    if (param_1 == '\0') {
      uVar4 = DAT_14000a3c0;
    }
    *(undefined1 *)(lVar2 + 0xbb) = uVar4;
    uVar4 = DAT_14000a171;
    if (param_1 == '\0') {
      uVar4 = DAT_14000a3c1;
    }
    *(undefined4 *)(lVar2 + 0xc0) = 3;
    *(undefined4 *)(lVar2 + 200) = 0;
    *(undefined4 *)(lVar2 + 0xcc) = 0;
    *(undefined1 *)(lVar2 + 0xbc) = uVar4;
    *(undefined4 *)(lVar2 + 0xc4) = 0x17;
    if (param_1 == '\0') {
      uVar1 = *(uint *)(lVar2 + 0xd4) | 0x333;
    }
    else {
      uVar1 = *(uint *)(lVar2 + 0xd4) & 0xffffffcf | 0x303;
    }
    *(undefined8 *)(lVar2 + 0x60) = 0;
    *(undefined4 *)(lVar2 + 0x20) = param_2;
    *(undefined4 *)(lVar2 + 0x40) = 1;
    *(uint *)(lVar2 + 0xd4) = uVar1 & 0xfffffb3f | 0xc;
    *(undefined4 *)(lVar2 + 0x6c) = 2;
    *(undefined4 *)(lVar2 + 0x90) = 2;
    *(undefined4 *)(lVar2 + 0x8c) = 2;
    *(undefined8 *)(lVar2 + 0x78) = 0;
    *(undefined8 **)(lVar2 + 0x80) = (undefined8 *)(lVar2 + 0x78);
    KeInitializeSpinLock(lVar2 + 0x38);
    *(undefined4 *)(lVar2 + 0xd8) = 9;
    uVar5 = DAT_14000aa68;
    if (param_1 == '\0') {
      uVar5 = DAT_14000ab88;
    }
    *param_5 = lVar2;
    uVar3 = 0;
    *(undefined8 *)(lVar2 + 0xe0) = uVar5;
  }
  return uVar3;
}



===== WanpCreateNewAdapter @ 14000ef78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WanpCreateNewAdapter
                    (uint *param_1,ushort *param_2,char param_3,undefined8 param_4,int param_5,
                    longlong *param_6)

{
  int iVar1;
  short sVar2;
  uint *puVar3;
  undefined1 uVar4;
  char cVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined7 uVar10;
  longlong lVar11;
  char cVar12;
  undefined7 uVar13;
  int *piVar14;
  ulonglong uVar15;
  bool bVar16;
  undefined1 auStackY_108 [32];
  longlong local_d8;
  uint *local_d0;
  ushort local_c8 [4];
  short *psStack_c0;
  ushort *local_b8;
  short local_a8 [48];
  ulonglong local_48;
  
  cVar12 = (char)param_4;
  uVar13 = (undefined7)((ulonglong)param_4 >> 8);
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d8 = 0;
  piVar14 = (int *)&g_ModuleV4;
  if (param_3 == '\0') {
    piVar14 = &g_ModuleV6;
  }
  lVar11 = -1;
  uVar15 = 0;
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  psStack_c0 = (short *)0x0;
  local_d0 = param_1;
  local_b8 = param_2;
  if (param_5 == 1) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
    LOCK();
    iVar1 = DAT_14000ad30 + 1;
    UNLOCK();
    bVar16 = DAT_14000ad30 == 0;
    DAT_14000ad30 = iVar1;
    if (bVar16) {
      KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
    }
    KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
    uVar10 = 0;
    puVar6 = WanpFindDialInAdapterGivenCompartmentId(1);
    if (((cVar12 != '\0') && (puVar6 != (undefined8 *)0x0)) &&
       (uVar7 = IsBindingPresent(param_3,(longlong)puVar6), (char)uVar7 != '\0')) {
      *param_6 = (longlong)puVar6;
      LOCK();
      UNLOCK();
      if (DAT_14000ad30 == 1) {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeReleaseSpinLock(&DAT_14000ad28,uVar4);
      }
      else {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeLowerIrql(CONCAT71(uVar10,uVar4));
      }
      return 0;
    }
    LOCK();
    UNLOCK();
    if (DAT_14000ad30 == 1) {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeReleaseSpinLock(&DAT_14000ad28,uVar4);
    }
    else {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeLowerIrql(CONCAT71(uVar10,uVar4));
    }
  }
  puVar3 = local_d0;
  cVar5 = GetAdapterFromDeviceGuid((longlong *)local_d0,&local_d8);
  lVar9 = local_d8;
  if ((cVar5 != '\0') && (uVar7 = IsBindingPresent(param_3,local_d8), (char)uVar7 != '\0')) {
    return 0xc000000d;
  }
  if (lVar9 == 0) {
    memset(local_a8 + 8,0,0x50);
    local_a8[4] = 0x49;
    local_a8[5] = 0x43;
    local_a8[6] = 0x45;
    local_a8[0] = 0x5c;
    local_a8[1] = 0x44;
    local_a8[2] = 0x45;
    local_a8[3] = 0x56;
    local_a8[7] = 0x5c;
    ConvertGuidToString(puVar3,local_a8 + 8,0x28);
    do {
      lVar11 = lVar11 + 1;
    } while (local_a8[lVar11] != 0);
    psStack_c0 = local_a8;
    sVar2 = (short)lVar11 * 2;
    local_c8[1] = sVar2;
    local_c8[0] = sVar2;
    uVar8 = WanpCreateAdapter(puVar3,local_c8,local_b8,CONCAT71(uVar13,param_3),cVar12,&local_d8);
    uVar15 = uVar8 & 0xffffffff;
    if ((int)uVar8 != 0) {
      return uVar15;
    }
  }
  lVar11 = local_d8;
  LOCK();
  *piVar14 = *piVar14 + 1;
  UNLOCK();
  if (cVar12 == '\x01') {
    if (param_3 == '\0') {
      lVar9 = *(longlong *)(local_d8 + 0xb0);
    }
    else {
      lVar9 = *(longlong *)(local_d8 + 0xa8);
    }
    if (lVar9 == 0) {
      lVar9 = ExAllocatePool2(0x40,0x228,0x69707257);
      if (lVar9 == 0) {
        ExFreePoolWithTag(lVar11,0);
        *param_6 = 0;
        return 0xc000009a;
      }
      *(char *)(lVar9 + 0x14) = param_3;
      *(undefined4 *)(lVar9 + 0x10) = 0x746e6957;
      *(undefined1 *)(lVar9 + 0x30) = 0;
      KeInitializeSpinLock(lVar9 + 0x38);
      *(undefined4 *)(lVar9 + 0x20) = 0xffffffff;
      *(undefined4 *)(lVar9 + 0x40) = 1;
      *(undefined4 *)(lVar9 + 0x8c) = 1;
      *(undefined4 *)(lVar9 + 0x90) = 4;
      *(undefined4 *)(lVar9 + 0x6c) = 0;
      *(undefined8 *)(lVar9 + 0x60) = 0;
      uVar7 = uRam000000014000a558;
      *(undefined8 *)(lVar9 + 0x44) = _ServerInterfaceGuid;
      *(undefined8 *)(lVar9 + 0x4c) = uVar7;
      if (param_3 == '\0') {
        *(longlong *)(lVar11 + 0xb0) = lVar9;
      }
      else {
        *(longlong *)(lVar11 + 0xa8) = lVar9;
      }
      *(int *)(lVar11 + 0xb8) = *(int *)(lVar11 + 0xb8) + 1;
    }
    if ((int)uVar15 != 0) {
      return uVar15;
    }
  }
  *param_6 = lVar11;
  return uVar15;
}



===== WanpDeleteAdapter @ 14000f2c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WanpDeleteAdapter(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_VPN_SFI_Bugfixes_2025A_Wanarp_KASANcrash_Fix__private_IsEnabledDeviceUsageNoInline
                    ();
  if ((int)uVar3 != 0) {
    uVar3 = 0;
    LOCK();
    uVar2 = *(uint *)(param_1 + 0x158);
    if (uVar2 == 0) {
      *(uint *)(param_1 + 0x158) = 1;
    }
    else {
      uVar3 = (ulonglong)uVar2;
    }
    UNLOCK();
    if (uVar2 != 0) {
      return uVar3;
    }
  }
  if (*(int *)(param_1 + 0x168) != -1) {
    NdisIfDeregisterInterface();
    *(undefined4 *)(param_1 + 0x168) = 0xffffffff;
  }
  if (*(longlong *)(param_1 + 0xa8) != 0) {
    LOCK();
    _g_ModuleV4 = _g_ModuleV4 + -1;
    UNLOCK();
  }
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    LOCK();
    g_ModuleV6 = g_ModuleV6 + -1;
    UNLOCK();
  }
  LOCK();
  puVar1 = (uint *)(param_1 + 0x84);
  uVar2 = *puVar1;
  uVar3 = (ulonglong)uVar2;
  *puVar1 = *puVar1 - 1;
  UNLOCK();
  if (uVar2 == 1) {
    uVar3 = ExFreePoolWithTag(param_1,0);
  }
  return uVar3;
}



===== WanpDeleteInterfaceFromIp @ 14000f358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WanpDeleteInterfaceFromIp(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  undefined *puVar7;
  
  lVar1 = param_1 + 0x38;
  iVar6 = 0;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  lVar4 = *(longlong *)(param_1 + 0x18);
  puVar7 = &WanNmrV4ProviderState;
  if (*(char *)(param_1 + 0x14) == '\0') {
    puVar7 = &WanNmrV6ProviderState;
  }
  LOCK();
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  UNLOCK();
  if (*(longlong *)(param_1 + 0x58) == 0) {
    KeReleaseSpinLock(lVar1,uVar5);
  }
  else {
    KeReleaseSpinLock(lVar1);
    iVar6 = (**(code **)(*(longlong *)(*(longlong *)(puVar7 + 0xd8) + 8) + 0x10))();
    if (iVar6 != 0x103) {
      LOCK();
      piVar2 = (int *)(param_1 + 0x40);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        ExFreePoolWithTag(param_1,0);
      }
      LOCK();
      piVar2 = (int *)(*(longlong *)(puVar7 + 0xd8) + 0x20);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -2;
      UNLOCK();
      if (iVar3 == 3) {
        WanNmrFinalizeDetach((longlong)puVar7);
      }
    }
    LOCK();
    *(int *)(&DAT_14000a7fc + (longlong)*(int *)(param_1 + 0x6c) * 0x10) =
         *(int *)(&DAT_14000a7fc + (longlong)*(int *)(param_1 + 0x6c) * 0x10) + 1;
    UNLOCK();
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x78);
    KeAcquireSpinLockAtDpcLevel(lVar1);
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined1 *)(param_1 + 0x30) = 0;
    if (*(int *)(param_1 + 0x6c) == 1) {
      if (*(char *)(param_1 + 0x14) == '\0') {
        *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0xb0) = 0;
      }
      else {
        *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0xa8) = 0;
      }
    }
    if (*(int *)(param_1 + 0x6c) != 0) {
      piVar2 = (int *)(*(longlong *)(param_1 + 0x18) + 0xb8);
      *piVar2 = *piVar2 + -1;
    }
    KeReleaseSpinLockFromDpcLevel(lVar1);
    KeReleaseSpinLock(*(longlong *)(param_1 + 0x18) + 0x78,uVar5);
    if (*(int *)(param_1 + 0x6c) != 2) {
      LOCK();
      piVar2 = (int *)(lVar4 + 0x80);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        WanpDeleteAdapter(lVar4);
      }
    }
  }
  LOCK();
  piVar2 = (int *)(param_1 + 0x40);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    ExFreePoolWithTag(param_1,0);
  }
  return iVar6;
}



===== WanpFindInterfaceGivenIndex @ 14000f540 =====

undefined8 * WanpFindInterfaceGivenIndex(int param_1)

{
  undefined8 *puVar1;
  
  puVar1 = g_leIfList;
  while( true ) {
    if ((undefined8 **)puVar1 == &g_leIfList) {
      return (undefined8 *)0x0;
    }
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  KeAcquireSpinLockAtDpcLevel(puVar1 + 7);
  LOCK();
  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) + 1;
  UNLOCK();
  return puVar1;
}



===== WanpIpAddSubInterface @ 14000f58c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WanpIpAddSubInterface(longlong param_1,longlong param_2,longlong param_3,char param_4)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  code *local_90;
  undefined8 local_88;
  longlong local_80;
  ulonglong *local_78;
  longlong local_70;
  longlong local_68;
  ulonglong local_60;
  uint local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined8 local_44;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  local_98 = 0;
  local_58 = *(uint *)(param_3 + 0x40);
  local_44 = 0;
  local_3c = 0;
  local_90 = WanIpAddSubInterfaceComplete;
  local_88 = *(undefined8 *)(param_2 + 0x58);
  local_78 = &local_60;
  local_70 = param_3 + 0x110;
  local_68 = param_3 + 0x80;
  local_a8 = 0;
  uStack_a0 = 0;
  local_54 = 0;
  uStack_4c = 0;
  local_60 = *(ulonglong *)(param_1 + 0x160);
  if (*(int *)(param_3 + 100) == 0) {
    local_60 = (ulonglong)local_58;
  }
  local_80 = param_3;
  KeInitializeEvent(&local_a8,1);
  uVar1 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_3 + 0x50));
  *(undefined8 **)(param_3 + 0x88) = &local_a8;
  *(longlong *)(param_3 + 0x10) = param_2;
  *(longlong *)(param_3 + 8) = param_1;
  if (*(int *)(param_3 + 100) != 0) {
    *(longlong *)(param_2 + 0x28) = param_3;
  }
  KeReleaseSpinLock(*(undefined8 *)(param_3 + 0x50),uVar1);
  lVar3 = DAT_14000a0d8;
  if (param_4 == '\0') {
    lVar3 = DAT_14000a328;
  }
  iVar2 = (**(code **)(*(longlong *)(lVar3 + 8) + 0x20))(&local_90);
  LOCK();
  *(int *)(&DAT_14000a800 + (longlong)*(int *)(param_3 + 100) * 0x10) =
       *(int *)(&DAT_14000a800 + (longlong)*(int *)(param_3 + 100) * 0x10) + 1;
  UNLOCK();
  if (iVar2 == 0x103) {
    local_b8 = 0;
    KeWaitForSingleObject(&local_a8,0,0,0);
    uVar1 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_3 + 0x50));
    *(undefined8 *)(param_3 + 0x88) = 0;
    iVar2 = *(int *)(param_3 + 0x90);
  }
  else {
    uVar1 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_3 + 0x50));
    *(undefined8 *)(param_3 + 0x88) = 0;
    if (iVar2 < 0) goto LAB_14000f718;
  }
  LOCK();
  *(int *)(param_3 + 0x60) = *(int *)(param_3 + 0x60) + 1;
  UNLOCK();
LAB_14000f718:
  KeReleaseSpinLock(*(undefined8 *)(param_3 + 0x50),uVar1);
  return iVar2;
}



===== WanpIpDeleteSpecialSubInterfaceComplete @ 14000f750 =====

int WanpIpDeleteSpecialSubInterfaceComplete(longlong param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  int iVar7;
  longlong lVar8;
  bool bVar9;
  
  lVar4 = *(longlong *)(param_1 + 0x10);
  lVar5 = *(longlong *)(param_1 + 8);
  uVar6 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  LOCK();
  iVar7 = DAT_14000ad30 + 1;
  UNLOCK();
  bVar9 = DAT_14000ad30 == 0;
  DAT_14000ad30 = iVar7;
  if (bVar9) {
    KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  }
  KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
  LOCK();
  UNLOCK();
  if (DAT_14000ad30 == 1) {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeReleaseSpinLock(&DAT_14000ad28,uVar6);
  }
  else {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeLowerIrql(uVar6);
  }
  if ((lVar4 == 0) || (lVar5 == 0)) {
    iVar7 = -0x3ffffe7c;
  }
  else {
    iVar7 = WanpDeleteInterfaceFromIp(lVar4);
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x78);
    cVar3 = *(char *)(param_1 + 4);
    if (cVar3 == '\0') {
      lVar8 = *(longlong *)(lVar5 + 0xa8);
    }
    else {
      lVar8 = *(longlong *)(lVar5 + 0xb0);
    }
    if (lVar8 == 0) {
      *(undefined1 *)(lVar5 + 0x94) = 3;
    }
    *(undefined8 *)(lVar4 + 0x18) = 0;
    *(undefined8 *)(lVar4 + 0x58) = 0;
    *(undefined8 *)(lVar4 + 0x28) = 0;
    LOCK();
    piVar1 = (int *)(lVar5 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      WanpDeleteAdapter(lVar5);
    }
    LOCK();
    piVar1 = (int *)(lVar4 + 0x40);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      ExFreePoolWithTag(lVar4,0);
    }
    KeReleaseSpinLock(lVar5 + 0x78,uVar6);
    WanpSetCloseEventIfRequired(cVar3);
    WanpReleaseResource(&g_wrBindMutex);
    LOCK();
    piVar1 = (int *)(lVar5 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      WanpDeleteAdapter(lVar5);
    }
  }
  return iVar7;
}



===== WanpMapAdapter @ 14000f90c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WanpMapAdapter(int param_1,undefined8 *param_2,longlong param_3,longlong param_4,
                  undefined1 *param_5,int *param_6,longlong param_7,char param_8)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  char cVar12;
  bool bVar13;
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [24];
  undefined8 *local_c8;
  char local_b8;
  char local_b7;
  int local_b4;
  int *local_b0;
  longlong local_a8;
  undefined1 *local_a0;
  ulonglong local_98;
  void *pvStack_90;
  longlong local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  local_a0 = param_5;
  local_88 = param_7;
  local_b0 = param_6;
  local_80 = 0;
  uStack_78 = 0;
  local_b7 = '\0';
  local_a8 = param_4;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  LOCK();
  iVar6 = DAT_14000ad30 + 1;
  UNLOCK();
  bVar13 = DAT_14000ad30 == 0;
  DAT_14000ad30 = iVar6;
  if (bVar13) {
    KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  }
  KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
  if (param_1 == 0) {
    if (param_2 == (undefined8 *)0x0) {
      LOCK();
      UNLOCK();
      if (DAT_14000ad30 == 1) {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeReleaseSpinLock(&DAT_14000ad28,uVar5);
      }
      else {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeLowerIrql(uVar5);
      }
    }
    else {
      puVar8 = param_2 + 0xf;
      KeAcquireSpinLockAtDpcLevel(puVar8);
      if (param_8 == '\0') {
        lVar9 = param_2[0x16];
      }
      else {
        lVar9 = param_2[0x15];
      }
      LOCK();
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
      UNLOCK();
      if (*(char *)((longlong)param_2 + 0x94) == '\x06') {
        KeReleaseSpinLockFromDpcLevel(puVar8);
        LOCK();
        UNLOCK();
        if (DAT_14000ad30 == 1) {
          DAT_14000ad30 = DAT_14000ad30 + -1;
          KeReleaseSpinLock(&DAT_14000ad28,uVar5);
        }
        else {
          DAT_14000ad30 = DAT_14000ad30 + -1;
          KeLowerIrql(uVar5);
        }
        iVar6 = WanpIpAddSubInterface((longlong)param_2,lVar9,local_a8,param_8);
        if (iVar6 == 0) {
          uVar5 = KeAcquireSpinLockRaiseToDpc(puVar8);
          puVar11 = auStack_e8;
          *local_a0 = uVar5;
          goto LAB_14000fb29;
        }
        LOCK();
        piVar1 = (int *)(param_2 + 0x10);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        goto LAB_14000ffa5;
      }
      KeReleaseSpinLockFromDpcLevel();
      LOCK();
      UNLOCK();
      if (DAT_14000ad30 == 1) {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeReleaseSpinLock(&DAT_14000ad28,uVar5);
      }
      else {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeLowerIrql(uVar5);
      }
      LOCK();
      piVar1 = (int *)(param_2 + 0x10);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        WanpDeleteAdapter((longlong)param_2);
      }
    }
    puVar11 = auStack_e8;
    iVar6 = -0x3ffffff2;
  }
  else {
    puVar8 = param_2 + 0xf;
    KeAcquireSpinLockAtDpcLevel(puVar8);
    LOCK();
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    UNLOCK();
    local_b8 = *(char *)((longlong)param_2 + 0x94);
    KeReleaseSpinLockFromDpcLevel(puVar8);
    LOCK();
    UNLOCK();
    if (DAT_14000ad30 == 1) {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeReleaseSpinLock(&DAT_14000ad28,uVar5);
    }
    else {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeLowerIrql(uVar5);
    }
    if (local_b8 == '\0') {
      local_50 = 0;
      local_b4 = 1;
      local_98 = 0;
      pvStack_90 = (void *)0x0;
      local_70 = 0;
      uStack_68 = 0;
      local_60 = 0;
      uStack_58 = 0;
      if (param_1 == 1) {
        local_b4 = param_6[0xc];
        *(int *)(param_3 + 0xa4) = local_b4;
        local_80 = *(undefined8 *)(param_6 + 8);
        uStack_78 = *(undefined8 *)(param_6 + 10);
      }
      else {
        FllwanpGetCompartmentInformation
                  (1,(longlong)&local_b4,(longlong)&local_70,(longlong)&local_80);
      }
      uVar5 = KeAcquireSpinLockRaiseToDpc(puVar8);
      *(int *)(param_2 + 0x2e) = local_b4;
      *(undefined1 *)((longlong)param_2 + 0x94) = 2;
      KeReleaseSpinLock(puVar8,uVar5);
      RtlInitUnicodeString(&local_98,param_6 + 0xd);
      puVar7 = (undefined8 *)ExAllocatePool2(0x40,(short)local_98 + 0x62,0x73646e57);
      if (puVar7 == (undefined8 *)0x0) {
        iVar6 = -0x3fffff66;
        uVar5 = KeAcquireSpinLockRaiseToDpc(puVar8);
        *(undefined1 *)((longlong)param_2 + 0x94) = 0;
        KeReleaseSpinLock(puVar8,uVar5);
      }
      else {
        *puVar7 = 0x600180;
        *(undefined8 *)((longlong)puVar7 + 0x14) = 0;
        *(undefined4 *)(puVar7 + 1) = 0xffffffff;
        *(undefined4 *)((longlong)puVar7 + 0xc) = 0xffffffff;
        *(undefined4 *)(puVar7 + 2) = 0xffffffff;
        *(undefined8 *)((longlong)puVar7 + 0x1c) = 3;
        *(undefined4 *)((longlong)puVar7 + 0x24) = 3;
        *(undefined2 *)((longlong)puVar7 + 0x2a) = 0;
        *(undefined2 *)((longlong)puVar7 + 0x2e) = 0;
        *(undefined2 *)((longlong)puVar7 + 0x32) = 0x60;
        *(short *)(puVar7 + 6) = (short)local_98 + 2;
        uVar4 = param_2[0x14];
        *(undefined8 *)((longlong)puVar7 + 0x34) = param_2[0x13];
        *(undefined8 *)((longlong)puVar7 + 0x3c) = uVar4;
        *(undefined8 *)((longlong)puVar7 + 0x44) = local_80;
        *(undefined8 *)((longlong)puVar7 + 0x4c) = uStack_78;
        memmove(puVar7 + 0xc,pvStack_90,(local_98 & 0xffff) + 2);
        local_c8 = param_2 + 0x2d;
        iVar6 = NdisIfRegisterInterface(g_hNdisIfProviderHandle,param_2[0x2c],param_2,puVar7);
        ExFreePoolWithTag(puVar7,0);
        if (iVar6 == 0) {
          if (*(int *)(local_88 + 100) != -1) {
            NdisIfAddIfStackEntry(*(undefined4 *)(param_2 + 0x2d));
          }
          LOCK();
          *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
          UNLOCK();
          uVar5 = KeAcquireSpinLockRaiseToDpc(puVar8);
          KeAcquireSpinLockAtDpcLevel(param_3 + 0x38);
          *(undefined1 *)((longlong)param_2 + 0x94) = 3;
          cVar12 = '\x01';
          goto LAB_14000fe1c;
        }
        uVar5 = KeAcquireSpinLockRaiseToDpc(puVar8);
        *(undefined1 *)((longlong)param_2 + 0x94) = 0;
        KeReleaseSpinLock(puVar8,uVar5);
        param_6 = local_b0;
      }
    }
    else {
      uVar5 = KeAcquireSpinLockRaiseToDpc(puVar8);
      KeAcquireSpinLockAtDpcLevel(param_3 + 0x38);
      *(undefined4 *)(param_3 + 0xa4) = *(undefined4 *)(param_2 + 0x2e);
      cVar12 = local_b7;
LAB_14000fe1c:
      param_6 = local_b0;
      if (param_8 == '\0') {
        *(undefined8 *)(param_3 + 0xf8) = *(undefined8 *)(local_b0 + 0x93);
      }
      else {
        *(char *)(param_3 + 0xfe) = (char)((uint)*(undefined4 *)(param_2 + 0x2d) >> 8);
        *(undefined1 *)(param_3 + 0xff) = *(undefined1 *)(param_2 + 0x2d);
      }
      iVar6 = WanpAddAdapterToIp((longlong)param_2,param_3,param_8,uVar5);
      if (iVar6 == 0) {
        iVar6 = WanpIpAddSubInterface((longlong)param_2,param_3,local_a8,param_8);
        if (iVar6 == 0) {
          uVar5 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
          KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
          KeAcquireSpinLockAtDpcLevel(puVar8);
          puVar10 = auStack_e8;
          puVar11 = auStack_e8;
          if (*(int *)(param_2 + 0x17) == 1) {
            puVar8 = &g_leMappedAdapterList;
            if ((undefined8 *)*DAT_14000ada8 != &g_leMappedAdapterList) {
              pcVar3 = (code *)swi(0x29);
              puVar8 = (undefined8 *)(*pcVar3)(3);
              puVar10 = auStack_e0;
            }
            _g_ulNumMappedAdapters = _g_ulNumMappedAdapters + 1;
            *param_2 = puVar8;
            param_2[1] = DAT_14000ada8;
            *DAT_14000ada8 = param_2;
            puVar11 = puVar10;
            DAT_14000ada8 = param_2;
          }
          LOCK();
          *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
          UNLOCK();
          *(undefined8 *)(puVar11 + -8) = 0x14000ff69;
          KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
          *(undefined8 *)(puVar11 + -8) = 0x14000ff7c;
          KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
          *local_a0 = uVar5;
LAB_14000fb29:
          iVar6 = 0;
          goto LAB_14000ffb1;
        }
        WanpDeleteInterfaceFromIp(param_3);
      }
      if (cVar12 != '\0') {
        LOCK();
        piVar1 = (int *)(param_2 + 0x10);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          WanpDeleteAdapter((longlong)param_2);
        }
      }
    }
    LOCK();
    piVar1 = (int *)(param_2 + 0x10);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      WanpDeleteAdapter((longlong)param_2);
    }
    if (*param_6 == 1) {
      if (param_8 == '\0') {
        lVar9 = param_2[0x15];
      }
      else {
        lVar9 = param_2[0x16];
      }
      if (lVar9 == 0) {
        LOCK();
        piVar1 = (int *)(param_2 + 0x10);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
LAB_14000ffa5:
        if (iVar2 == 1) {
          WanpDeleteAdapter((longlong)param_2);
        }
      }
    }
    puVar11 = auStack_e8;
  }
LAB_14000ffb1:
  *(undefined8 *)(puVar11 + -8) = 0x14000ffbd;
  return iVar6;
}



===== WanpRegisterInterface @ 14000ffe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WanpRegisterInterface(undefined4 param_1,ushort *param_2,longlong param_3,longlong param_4)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined1 auStack_b8 [32];
  undefined4 *local_98;
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  local_50 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_88[0] = param_1;
  FllwanpGetCompartmentInformation(0,(longlong)local_88,(longlong)&local_70,(longlong)&local_80);
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,*param_2 + 0x62,0x73646e57);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    *puVar5 = 0x600180;
    *(undefined8 *)((longlong)puVar5 + 0x14) = 0;
    *(undefined4 *)(puVar5 + 1) = 0xffffffff;
    *(undefined4 *)((longlong)puVar5 + 0xc) = 0xffffffff;
    *(undefined4 *)(puVar5 + 2) = 0xffffffff;
    *(undefined2 *)((longlong)puVar5 + 0x2a) = 0;
    *(undefined8 *)((longlong)puVar5 + 0x1c) = 3;
    *(undefined4 *)((longlong)puVar5 + 0x24) = 3;
    *(undefined2 *)((longlong)puVar5 + 0x2e) = 0;
    uVar2 = *param_2;
    *(undefined2 *)((longlong)puVar5 + 0x32) = 0x60;
    *(ushort *)(puVar5 + 6) = uVar2 + 2;
    uVar3 = *(undefined8 *)(param_3 + 0xa0);
    *(undefined8 *)((longlong)puVar5 + 0x34) = *(undefined8 *)(param_3 + 0x98);
    *(undefined8 *)((longlong)puVar5 + 0x3c) = uVar3;
    *(undefined8 *)((longlong)puVar5 + 0x44) = local_80;
    *(undefined8 *)((longlong)puVar5 + 0x4c) = uStack_78;
    memmove(puVar5 + 0xc,*(void **)(param_2 + 4),(ulonglong)*param_2 + 2);
    puVar1 = (undefined4 *)(param_3 + 0x168);
    local_98 = puVar1;
    iVar4 = NdisIfRegisterInterface
                      (g_hNdisIfProviderHandle,*(undefined8 *)(param_3 + 0x160),param_3,puVar5);
    ExFreePoolWithTag(puVar5,0);
    if (iVar4 == 0) {
      LOCK();
      *(int *)(param_3 + 0x80) = *(int *)(param_3 + 0x80) + 1;
      UNLOCK();
      *(char *)(param_4 + 0xfe) = (char)((uint)*puVar1 >> 8);
      *(undefined1 *)(param_4 + 0xff) = *(undefined1 *)puVar1;
    }
  }
  return iVar4;
}



===== WanpUnmapInterface @ 140010164 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanpUnmapInterface(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  longlong lVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar4 = *(longlong **)(param_1 + 0x18);
  uVar9 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  plVar1 = plVar4 + 0xf;
  KeAcquireSpinLockAtDpcLevel(plVar1);
  puVar10 = auStack_28;
  if (*(char *)((longlong)plVar4 + 0x94) == '\x01') {
LAB_1400102c6:
    *(undefined8 *)(puVar10 + -8) = 0x1400102d0;
    KeReleaseSpinLockFromDpcLevel(plVar1);
    *(undefined8 *)(puVar10 + -8) = 0x1400102e3;
    KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
    *(undefined8 *)(puVar10 + -8) = 0x1400102f9;
    KeReleaseSpinLock(&g_rwlAdapterLock,uVar9);
  }
  else {
    lVar8 = plVar4[0x17];
    if ((int)lVar8 == 1) {
      lVar5 = *plVar4;
      if ((*(longlong **)(lVar5 + 8) != plVar4) ||
         (plVar6 = (longlong *)plVar4[1], (longlong *)*plVar6 != plVar4)) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        puVar10 = auStack_20;
        goto LAB_1400102c6;
      }
      _g_ulNumMappedAdapters = _g_ulNumMappedAdapters + -1;
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      *(undefined1 *)((longlong)plVar4 + 0x94) = 1;
    }
    KeReleaseSpinLockFromDpcLevel(plVar1);
    KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
    KeReleaseSpinLock(&g_rwlAdapterLock,uVar9);
    LOCK();
    piVar2 = (int *)(param_1 + 0x40);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      ExFreePoolWithTag(param_1,0);
    }
    WanpDeleteInterfaceFromIp(param_1);
    puVar10 = auStack_28;
    if ((int)lVar8 == 1) {
      NdisIfDeregisterInterface((int)plVar4[0x2d]);
      uVar9 = KeAcquireSpinLockRaiseToDpc(plVar1);
      *(undefined4 *)(plVar4 + 0x2d) = 0xffffffff;
      KeReleaseSpinLock(plVar1,uVar9);
      puVar10 = auStack_28;
      LOCK();
      plVar1 = plVar4 + 0x10;
      lVar8 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar8 == 1) {
        WanpDeleteAdapter((longlong)plVar4);
        puVar10 = auStack_28;
      }
    }
  }
  LOCK();
  plVar1 = plVar4 + 0x10;
  lVar8 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar8 == 1) {
    *(undefined8 *)(puVar10 + -8) = 0x140010316;
    WanpDeleteAdapter((longlong)plVar4);
  }
  return;
}



===== WanpUnmapServerInterface @ 140010338 =====

undefined8 WanpUnmapServerInterface(longlong param_1,undefined1 param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  uVar6 = 0;
  if (*(char *)(param_1 + 0x94) == '\x06') {
    if (param_3 == '\0') {
      lVar5 = *(longlong *)(param_1 + 0xb0);
    }
    else {
      lVar5 = *(longlong *)(param_1 + 0xa8);
    }
    if (lVar5 != 0) {
      if (g_bEnableLinkDownAtStop != 0) {
        WanpRemoveConnections(param_3,*(int *)(lVar5 + 0xa4));
      }
      cVar4 = WanpIsConnectionTableEmpty(param_3,*(int *)(lVar5 + 0xa4));
      if (cVar4 == '\0') {
        uVar6 = 0xc0000101;
      }
      else {
        KeAcquireSpinLockAtDpcLevel(lVar5 + 0x38);
        lVar3 = *(longlong *)(lVar5 + 0x28);
        KeReleaseSpinLockFromDpcLevel(lVar5 + 0x38);
        if (lVar3 != 0) {
          LOCK();
          *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
          UNLOCK();
          KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(lVar3 + 0x50));
          *(undefined4 *)(lVar3 + 0x7c) = 0;
          KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(lVar3 + 0x50));
          KeReleaseSpinLockFromDpcLevel(param_1 + 0x78);
          LOCK();
          UNLOCK();
          if (DAT_14000ad30 == 1) {
            DAT_14000ad30 = DAT_14000ad30 + -1;
            KeReleaseSpinLock(&DAT_14000ad28,param_2);
          }
          else {
            DAT_14000ad30 = DAT_14000ad30 + -1;
            KeLowerIrql(param_2);
          }
          LOCK();
          piVar1 = (int *)(lVar3 + 0x60);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            WanpDeleteConnEntry(lVar3);
          }
          LOCK();
          piVar1 = (int *)(lVar3 + 0x60);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            WanpDeleteConnEntry(lVar3);
            return 0;
          }
          return 0;
        }
        uVar6 = 0xc0000034;
      }
    }
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x78);
  LOCK();
  UNLOCK();
  if (DAT_14000ad30 == 1) {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeReleaseSpinLock(&DAT_14000ad28,param_2);
  }
  else {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeLowerIrql(param_2);
  }
  WanpSetCloseEventIfRequired(param_3);
  WanpReleaseResource(&g_wrBindMutex);
  return uVar6;
}



===== WanpAllocateAndInitializeConnectionEntry @ 1400104f8 =====

undefined4 * WanpAllocateAndInitializeConnectionEntry(int *param_1,longlong param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  
  piVar2 = *(int **)(param_1 + 8);
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
  puVar4 = WanpCreateConnEntry(*piVar2,param_3);
  if (puVar4 == (undefined4 *)0x0) {
    KeReleaseSpinLock(&g_rlConnTableLock,uVar3);
    puVar4 = (undefined4 *)0x0;
  }
  else {
    if (*piVar2 == 0) {
      *(undefined4 **)(puVar4 + 0x14) = puVar4 + 0x16;
    }
    else {
      *(longlong *)(puVar4 + 0x14) = param_2 + 0x78;
      LOCK();
      *(int *)(param_2 + 0x84) = *(int *)(param_2 + 0x84) + 1;
      UNLOCK();
      *(undefined1 *)(puVar4 + 0x3e) = 1;
    }
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(puVar4 + 0x14));
    *(ulonglong *)(puVar4 + 0x26) = (ulonglong)(uint)(*param_1 * 100);
    *(ulonglong *)(puVar4 + 0x28) = (ulonglong)(uint)(*param_1 * 100);
    puVar4[0x46] = param_1[1];
    *(ulonglong *)(puVar4 + 0x48) = (ulonglong)(uint)(*param_1 * 100);
    iVar1 = *param_1;
    puVar4[0x44] = 1;
    *(ulonglong *)(puVar4 + 0x4a) = (ulonglong)(uint)(iVar1 * 100);
    *(bool *)((longlong)puVar4 + 0x7a) = piVar2[1] == 1;
    puVar4[0x10] = piVar2[4];
    *(undefined8 *)(puVar4 + 0x40) = *(undefined8 *)(piVar2 + 0x96);
    puVar4[0x43] = piVar2[0xc];
    if (param_3 == '\0') {
      if (*piVar2 != 0) {
        *(undefined8 *)(puVar4 + 0xc) = *(undefined8 *)(piVar2 + 0x93);
      }
    }
    else {
      puVar4[7] = piVar2[0x93];
      puVar4[6] = piVar2[0x92];
      puVar4[8] = piVar2[0x94];
    }
    puVar4[0x1f] = 1;
    if (*piVar2 == 0) {
      *(undefined8 *)(puVar4 + 10) = *(undefined8 *)(piVar2 + 6);
    }
    KeReleaseSpinLockFromDpcLevel(&g_rlConnTableLock);
    KeReleaseSpinLock(*(undefined8 *)(puVar4 + 0x14),uVar3);
  }
  return puVar4;
}



===== WanpCreateConnEntry @ 140010690 =====

undefined4 * WanpCreateConnEntry(int param_1,undefined1 param_2)

{
  undefined4 *_Dst;
  ulonglong uVar1;
  void *_Dst_00;
  uint uVar2;
  uint uVar3;
  
  _Dst = (undefined4 *)ExAllocateFromNPagedLookasideList(&g_llConnBlocks);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x130);
    _Dst[0x1f] = 3;
    _Dst[0x19] = param_1;
    *(undefined1 *)(_Dst + 1) = param_2;
    *_Dst = 0x6e6f6357;
    _Dst[0x44] = 1;
    _Dst[0x46] = 0x578;
    KeInitializeSpinLock(_Dst + 0x16);
    uVar2 = g_ulNextConnIndex;
    for (uVar3 = 0; uVar3 < g_ulConnTableSize; uVar3 = uVar3 + 1) {
      if (*(longlong *)((longlong)g_puipConnTable + (ulonglong)uVar2 * 8) == 0) {
        *(undefined4 **)((longlong)g_puipConnTable + (ulonglong)uVar2 * 8) = _Dst;
        *(int *)(&g_rgulConns + (longlong)param_1 * 4) =
             *(int *)(&g_rgulConns + (longlong)param_1 * 4) + 1;
        _Dst[0x1a] = uVar2;
        g_ulNextConnIndex = (g_ulNextConnIndex + 1) % g_ulConnTableSize;
        return _Dst;
      }
      uVar2 = (uVar2 + 1) % g_ulConnTableSize;
    }
    if (((g_ulConnTableSize <= g_ulConnTableSize + 0x20) &&
        (uVar1 = (ulonglong)(g_ulConnTableSize + 0x20) * 8, uVar1 < 0x100000000)) &&
       (_Dst_00 = (void *)ExAllocatePool2(0x40,uVar1 & 0xffffffff,0x63707257),
       _Dst_00 != (void *)0x0)) {
      memmove(_Dst_00,g_puipConnTable,(ulonglong)g_ulConnTableSize << 3);
      ExFreePoolWithTag(g_puipConnTable,0);
      g_puipConnTable = _Dst_00;
      *(undefined4 **)((longlong)_Dst_00 + (ulonglong)g_ulConnTableSize * 8) = _Dst;
      uVar2 = g_ulConnTableSize;
      *(int *)(&g_rgulConns + (longlong)param_1 * 4) =
           *(int *)(&g_rgulConns + (longlong)param_1 * 4) + 1;
      _Dst[0x1a] = uVar2;
      g_ulNextConnIndex = g_ulConnTableSize + 1;
      g_ulConnTableSize = g_ulConnTableSize + 0x20;
      return _Dst;
    }
    FreeConnection((longlong)_Dst);
  }
  return (undefined4 *)0x0;
}



===== WanpDeleteConnEntry @ 14001083c =====

void WanpDeleteConnEntry(longlong param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\x02') {
    *(undefined8 *)(param_1 + 0xa8) = 0;
    *(code **)(param_1 + 0xb8) = WanpDeleteConnEntryPassive;
    *(longlong *)(param_1 + 0xc0) = param_1;
    ExQueueWorkItem((undefined8 *)(param_1 + 0xa8),0);
    *(undefined1 *)(param_1 + 200) = 1;
  }
  else {
    WanpDeleteConnEntryPassive(param_1);
  }
  return;
}



===== WanpIsConnectionTableEmpty @ 14001089c =====

undefined1 WanpIsConnectionTableEmpty(char param_1,int param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
  uVar3 = 0;
  for (uVar4 = 1; (uint)uVar4 < g_ulConnTableSize; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
    lVar1 = *(longlong *)(g_puipConnTable + uVar4 * 8);
    if ((((lVar1 != 0) && (*(int *)(lVar1 + 100) != 3)) && (*(char *)(lVar1 + 4) == param_1)) &&
       (((*(int *)(lVar1 + 0x10c) == param_2 && (*(int *)(lVar1 + 0x7c) != 3)) &&
        (*(int *)(lVar1 + 100) == 0)))) goto LAB_140010912;
  }
  uVar3 = 1;
LAB_140010912:
  KeReleaseSpinLock(&g_rlConnTableLock,uVar2);
  return uVar3;
}



===== WanpLinkDownIndication @ 140010944 =====

undefined8 WanpLinkDownIndication(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  
  if (param_1 != 0) {
    param_2 = *(uint *)(param_1 + 8);
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
  lVar3 = *(longlong *)(g_puipConnTable + (ulonglong)param_2 * 8);
  if (lVar3 == 0) {
    KeReleaseSpinLock(&g_rlConnTableLock,uVar4);
  }
  else {
    LOCK();
    *(int *)(lVar3 + 0x60) = *(int *)(lVar3 + 0x60) + 1;
    UNLOCK();
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(lVar3 + 0x50));
    KeReleaseSpinLockFromDpcLevel(&g_rlConnTableLock);
    if ((*(int *)(lVar3 + 0x7c) == 0) || (*(int *)(lVar3 + 0x7c) - 3U < 2)) {
      KeReleaseSpinLock(*(undefined8 *)(lVar3 + 0x50),uVar4);
      LOCK();
      piVar1 = (int *)(lVar3 + 0x60);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        WanpDeleteConnEntry(lVar3);
      }
    }
    else {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x60);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        WanpDeleteConnEntry(lVar3);
      }
      *(undefined4 *)(lVar3 + 0x7c) = 0;
      *(longlong *)(lVar3 + 0xf0) = param_1;
      LOCK();
      *(int *)(lVar3 + 0x60) = *(int *)(lVar3 + 0x60) + 1;
      UNLOCK();
      KeReleaseSpinLock(*(undefined8 *)(lVar3 + 0x50));
      cVar5 = KeGetCurrentIrql();
      if (cVar5 == '\0') {
        WanpLinkDownIndicationWorkItemImpl(lVar3,0);
        if (param_1 != 0) {
          *(undefined1 *)(param_1 + 0xc) = 0;
        }
      }
      else {
        if (param_1 != 0) {
          *(undefined1 *)(param_1 + 0xc) = 1;
        }
        *(undefined8 *)(lVar3 + 0xd0) = 0;
        *(code **)(lVar3 + 0xe0) = WanpLinkDownIndicationWorkItem;
        *(longlong *)(lVar3 + 0xe8) = lVar3;
        ExQueueWorkItem((undefined8 *)(lVar3 + 0xd0),0);
      }
    }
  }
  return 0;
}



===== WanpLinkDownIndicationWorkItem @ 140010ac0 =====

void WanpLinkDownIndicationWorkItem(longlong param_1)

{
  WanpLinkDownIndicationWorkItemImpl(param_1,1);
  return;
}



===== WanpLinkDownIndicationWorkItemImpl @ 140010ad8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanpLinkDownIndicationWorkItemImpl(longlong param_1,undefined1 param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  uint *puVar5;
  longlong lVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined7 in_register_00000011;
  undefined1 *puVar13;
  longlong *plVar14;
  longlong local_res8;
  undefined1 local_res10;
  longlong local_res18;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  
  local_res8 = 0;
  local_res10 = param_2;
  uVar9 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_1 + 0x50));
  lVar12 = *(longlong *)(param_1 + 0xf0);
  cVar3 = *(char *)(param_1 + 4);
  local_res18 = lVar12;
  if (*(int *)(param_1 + 100) == 2) {
    lVar4 = *(longlong *)(param_1 + 0x10);
    LOCK();
    *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
    UNLOCK();
    KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),CONCAT71(in_register_00000011,uVar9));
    WanpAcquireResource((int *)&WfpMutex);
    uVar9 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_1 + 0x50));
    KeAcquireSpinLockAtDpcLevel(lVar4 + 0x38);
    puVar5 = *(uint **)(lVar4 + 0x98);
    uVar10 = *(uint *)(lVar4 + 0xa0);
    uVar11 = WanpRouterLinkDownHandler(param_1,uVar9,&local_res8);
    if ((-1 < (int)uVar11) && (puVar5 != (uint *)0x0)) {
      WanpAddSubnetFilters(puVar5,uVar10,lVar4);
      for (uVar10 = *puVar5; uVar10 != 0; uVar10 = uVar10 - 1) {
        LOCK();
        *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
        UNLOCK();
      }
    }
    WanpReleaseResource((int *)&WfpMutex);
    puVar13 = auStack_58;
    LOCK();
    piVar1 = (int *)(lVar4 + 0x40);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      ExFreePoolWithTag(lVar4,0);
      puVar13 = auStack_58;
    }
    goto LAB_140010e2d;
  }
  lVar4 = *(longlong *)(param_1 + 8);
  if (cVar3 == '\0') {
    plVar14 = *(longlong **)(lVar4 + 0xb0);
  }
  else {
    plVar14 = *(longlong **)(lVar4 + 0xa8);
  }
  if (*(int *)((longlong)plVar14 + 0x6c) == 0) {
    KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),CONCAT71(in_register_00000011,uVar9));
    puVar13 = auStack_58;
  }
  else {
    *(undefined1 *)(plVar14 + 6) = 4;
    if (*(int *)(lVar4 + 0xb8) == 1) {
      *(undefined2 *)(lVar4 + 0x94) = 0x204;
    }
    KeAcquireSpinLockAtDpcLevel(&g_rwlIfLock);
    KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
    KeAcquireSpinLockAtDpcLevel(plVar14 + 7);
    *(undefined4 *)(plVar14 + 0x12) = 2;
    *(undefined4 *)((longlong)plVar14 + 0x8c) = 2;
    *(longlong *)(lVar4 + 200) = _DAT_fffff78000000014 / 100000;
    lVar12 = ExAllocateFromNPagedLookasideList(&g_llNotificationBlocks);
    puVar13 = auStack_58;
    local_res8 = lVar12;
    if (*(int *)((longlong)plVar14 + 0x6c) == 1) {
      if (lVar12 != 0) {
        *(undefined4 *)(lVar12 + 0x30) = 4;
        *(undefined4 *)(lVar12 + 0x38) = *(undefined4 *)(lVar4 + 0x168);
        *(undefined4 *)(lVar12 + 0x34) = 0xffffffff;
        *(char *)(lVar12 + 0x3c) = cVar3;
        if (cVar3 == '\0') {
          *(undefined8 *)(lVar12 + 0x40) = *(undefined8 *)(param_1 + 0x30);
        }
        else {
          *(undefined4 *)(lVar12 + 0x40) = *(undefined4 *)(param_1 + 0x18);
          *(undefined4 *)(lVar12 + 0x44) = *(undefined4 *)(param_1 + 0x1c);
          *(undefined4 *)(lVar12 + 0x48) = *(undefined4 *)(param_1 + 0x20);
        }
      }
      lVar6 = *plVar14;
      if ((*(longlong **)(lVar6 + 8) != plVar14) ||
         (plVar7 = (longlong *)plVar14[1], (longlong *)*plVar7 != plVar14)) {
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        puVar13 = auStack_50;
        goto LAB_140010d63;
      }
      *plVar7 = lVar6;
      *(longlong **)(lVar6 + 8) = plVar7;
      LOCK();
      g_ulNumDialOutInterfaces = g_ulNumDialOutInterfaces + -1;
      UNLOCK();
      KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
      KeReleaseSpinLockFromDpcLevel(&g_rwlIfLock);
      puVar13 = auStack_58;
    }
    else {
LAB_140010d63:
      *(undefined8 *)(puVar13 + -8) = 0x140010d71;
      KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
      *(undefined8 *)(puVar13 + -8) = 0x140010d84;
      KeReleaseSpinLockFromDpcLevel(&g_rwlIfLock);
      if (lVar12 != 0) {
        *(undefined4 *)(lVar12 + 0x30) = 2;
        *(undefined4 *)(lVar12 + 0x38) = *(undefined4 *)(lVar4 + 0x168);
        *(int *)(lVar12 + 0x34) = (int)plVar14[4];
        *(char *)(lVar12 + 0x3c) = cVar3;
        if (cVar3 == '\0') {
          *(undefined8 *)(lVar12 + 0x40) = *(undefined8 *)(param_1 + 0x30);
        }
        else {
          *(undefined4 *)(lVar12 + 0x40) = *(undefined4 *)(param_1 + 0x18);
          *(undefined4 *)(lVar12 + 0x44) = *(undefined4 *)(param_1 + 0x1c);
          *(undefined4 *)(lVar12 + 0x48) = *(undefined4 *)(param_1 + 0x20);
        }
      }
    }
    *(undefined8 *)(puVar13 + -8) = 0x140010dd4;
    KeReleaseSpinLockFromDpcLevel(plVar14 + 7);
    uVar11 = *(undefined8 *)(param_1 + 0x50);
    *(undefined8 *)(puVar13 + -8) = 0x140010de7;
    KeReleaseSpinLock(uVar11,uVar9);
    LOCK();
    piVar1 = (int *)(lVar4 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      *(undefined8 *)(puVar13 + -8) = 0x140010e02;
      WanpDeleteAdapter(lVar4);
    }
    lVar12 = *(longlong *)(puVar13 + 0x70);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *(undefined8 *)(puVar13 + -8) = 0x140010e1a;
    WanpDeleteConnEntry(param_1);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *(undefined8 *)(puVar13 + -8) = 0x140010e2d;
    WanpDeleteConnEntry(param_1);
  }
LAB_140010e2d:
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *(undefined8 *)(puVar13 + -8) = 0x140010e40;
    WanpDeleteConnEntry(param_1);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *(undefined8 *)(puVar13 + -8) = 0x140010e53;
    WanpDeleteConnEntry(param_1);
  }
  if (*(undefined8 **)(puVar13 + 0x60) != (undefined8 *)0x0) {
    *(undefined8 *)(puVar13 + -8) = 0x140010e62;
    WanpCompleteIrp(*(undefined8 **)(puVar13 + 0x60));
  }
  if ((puVar13[0x68] != '\0') && (lVar12 != 0)) {
    *(undefined8 *)(puVar13 + -8) = 0x140010e79;
    NdisSetEvent(lVar12 + 0x10);
  }
  return;
}



===== WanpLinkUpIndication @ 140010e9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WanpLinkUpIndication(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong lVar11;
  uint uVar12;
  longlong lVar13;
  undefined *puVar14;
  bool bVar15;
  undefined8 *local_res18;
  undefined4 *local_res20;
  ushort local_60 [8];
  undefined8 local_50;
  ulonglong local_48;
  longlong local_40;
  
  piVar2 = *(int **)(param_1 + 8);
  local_res18 = (undefined8 *)0x0;
  local_48 = 0;
  puVar8 = (undefined8 *)0x0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  local_60[5] = 0;
  local_60[6] = 0;
  local_60[7] = 0;
  RtlInitUnicodeString(local_60,piVar2 + 0xd);
  cVar5 = EnterModuleCode(param_2);
  if (cVar5 == '\0') {
    return -0x3ffeffef;
  }
  uVar12 = *(uint *)((longlong)param_1 + 0x16);
  if (uVar12 == 0) {
    iVar7 = *piVar2;
    if (iVar7 == 0) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
      LOCK();
      iVar7 = DAT_14000ad30 + 1;
      UNLOCK();
      bVar15 = DAT_14000ad30 == 0;
      DAT_14000ad30 = iVar7;
      if (bVar15) {
        KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
      }
      KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
      local_res18 = WanpFindDialInAdapterGivenCompartmentId(piVar2[0xc]);
      LOCK();
      UNLOCK();
      if (DAT_14000ad30 == 1) {
        puVar14 = &DAT_14000ad28;
        DAT_14000ad30 = DAT_14000ad30 + -1;
        goto LAB_14001120a;
      }
      DAT_14000ad30 = DAT_14000ad30 + -1;
LAB_1400112f7:
      KeLowerIrql(uVar6);
    }
    else if (iVar7 == 1) {
      uVar9 = WanpCreateNewAdapter
                        (*(uint **)(param_1 + 0xe),local_60,param_2,0,1,(longlong *)&local_res18);
      iVar7 = (int)uVar9;
      if (iVar7 < 0) goto LAB_1400114d5;
      *(int *)(local_res18 + 0x28) = param_1[1];
      local_res18[0x29] = (ulonglong)(uint)(*param_1 * 100);
      local_res18[0x2a] = (ulonglong)(uint)(*param_1 * 100);
    }
    else {
      if (iVar7 != 2) {
        iVar7 = -0x3ffffff3;
        goto LAB_1400114d5;
      }
      uVar6 = KeAcquireSpinLockRaiseToDpc(&g_rwlIfLock);
      LOCK();
      iVar7 = DAT_14000acd0 + 1;
      UNLOCK();
      bVar15 = DAT_14000acd0 == 0;
      DAT_14000acd0 = iVar7;
      if (bVar15) {
        KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
      }
      KeReleaseSpinLockFromDpcLevel(&g_rwlIfLock);
      puVar8 = WanpFindInterfaceGivenIndex(piVar2[3]);
      if (puVar8 == (undefined8 *)0x0) {
        LOCK();
        UNLOCK();
        if (DAT_14000acd0 == 1) {
          DAT_14000acd0 = DAT_14000acd0 + -1;
          KeReleaseSpinLock(&DAT_14000acc8,uVar6);
        }
        else {
          DAT_14000acd0 = DAT_14000acd0 + -1;
          KeLowerIrql(uVar6);
        }
        iVar7 = -0x3fffffcc;
        goto LAB_1400114d5;
      }
      local_res18 = (undefined8 *)puVar8[3];
      *(undefined8 *)(piVar2 + 6) = local_res18[0x2c];
      KeReleaseSpinLockFromDpcLevel(puVar8 + 7);
      LOCK();
      UNLOCK();
      if (DAT_14000acd0 != 1) {
        DAT_14000acd0 = DAT_14000acd0 + -1;
        goto LAB_1400112f7;
      }
      puVar14 = &DAT_14000acc8;
      DAT_14000acd0 = DAT_14000acd0 + -1;
LAB_14001120a:
      KeReleaseSpinLock(puVar14,uVar6);
    }
    puVar3 = local_res18;
    local_res20 = WanpAllocateAndInitializeConnectionEntry(param_1,(longlong)local_res18,param_2);
    if (local_res20 == (undefined4 *)0x0) {
LAB_14001131f:
      iVar7 = -0x3fffff66;
    }
    else {
      uVar12 = *(ushort *)((longlong)param_1 + 0x32) + 0x40;
      if (*(ushort *)((longlong)param_1 + 0x32) <= uVar12) {
        iVar7 = 0;
        plVar10 = (longlong *)ExAllocatePool2(0x40,uVar12,0x6c707277);
        puVar4 = local_res20;
        if (plVar10 != (longlong *)0x0) {
          *(char *)(plVar10 + 1) = param_2;
          *plVar10 = (longlong)param_1;
          plVar10[3] = (longlong)puVar3;
          LOCK();
          *(int *)(puVar3 + 0x10) = *(int *)(puVar3 + 0x10) + 1;
          UNLOCK();
          if (puVar8 != (undefined8 *)0x0) {
            plVar10[2] = (longlong)puVar8;
            LOCK();
            *(int *)(puVar8 + 8) = *(int *)(puVar8 + 8) + 1;
            UNLOCK();
          }
          plVar10[4] = (longlong)local_res20;
          LOCK();
          local_res20[0x18] = local_res20[0x18] + 1;
          UNLOCK();
          *(undefined2 *)((longlong)plVar10 + 0x2a) = *(undefined2 *)((longlong)param_1 + 0x32);
          *(short *)(plVar10 + 5) = (short)param_1[0xc];
          plVar10[6] = (longlong)(plVar10 + 8);
          memmove(plVar10 + 8,*(void **)(param_1 + 0xe),(ulonglong)*(ushort *)(param_1 + 0xc));
          param_1[5] = 0;
          *(undefined2 *)(param_1 + 6) = 0;
          *(undefined4 *)((longlong)param_1 + 0x16) = puVar4[0x1a];
          *(undefined8 *)(puVar4 + 0x1b) = 0;
          puVar4[0x1d] = puVar4[0x1a];
          puVar4[0x1b] = *(undefined4 *)((longlong)param_1 + 0xe);
          *(undefined2 *)(puVar4 + 0x1c) = *(undefined2 *)((longlong)param_1 + 0x12);
          *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(local_res18 + 9);
          memmove(*(void **)(param_1 + 0xe),(void *)local_res18[10],
                  (ulonglong)*(ushort *)(local_res18 + 9));
          LOCK();
          puVar4[0x18] = puVar4[0x18] + 1;
          UNLOCK();
          cVar5 = KeGetCurrentIrql();
          if (cVar5 != '\0') {
            *(undefined8 *)(puVar4 + 0x34) = 0;
            *(code **)(puVar4 + 0x38) = WanpLinkUpIndicationWorkItem;
            *(longlong **)(puVar4 + 0x3a) = plVar10;
            ExQueueWorkItem();
          }
          else {
            WanpLinkUpIndicationWorkItemImpl(plVar10,'\0');
          }
          *(bool *)(param_1 + 0x10) = cVar5 != '\0';
          goto LAB_1400114d5;
        }
        goto LAB_14001131f;
      }
      iVar7 = -0x3fffff6b;
    }
    if (*piVar2 == 1) {
      if (param_2 == '\0') {
        lVar11 = puVar3[0x15];
      }
      else {
        lVar11 = puVar3[0x16];
      }
      if (lVar11 == 0) {
        WanpDeleteAdapter((longlong)puVar3);
      }
    }
    else if (*piVar2 == 2) {
      LOCK();
      piVar2 = (int *)(puVar8 + 8);
      iVar1 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        ExFreePoolWithTag(puVar8,0);
      }
    }
    if (local_res20 != (undefined4 *)0x0) {
      local_res20[0x1f] = 3;
      WanpDeleteConnEntry((longlong)local_res20);
    }
    param_1[5] = 0;
    *(undefined2 *)(param_1 + 6) = 0;
    goto LAB_1400114d5;
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
  lVar11 = *(longlong *)(g_puipConnTable + (ulonglong)uVar12 * 8);
  if (lVar11 == 0) {
LAB_1400110ef:
    KeReleaseSpinLock(&g_rlConnTableLock,uVar6);
  }
  else {
    LOCK();
    *(int *)(lVar11 + 0x60) = *(int *)(lVar11 + 0x60) + 1;
    UNLOCK();
    if (*(int *)(lVar11 + 0x7c) != 2) {
      LOCK();
      piVar2 = (int *)(lVar11 + 0x60);
      iVar7 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar7 == 1) {
        WanpDeleteConnEntry(lVar11);
      }
      goto LAB_1400110ef;
    }
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(lVar11 + 0x50));
    KeReleaseSpinLockFromDpcLevel(&g_rlConnTableLock);
    if (param_1[1] != *(int *)(lVar11 + 0x118)) {
      *(int *)(lVar11 + 0x118) = param_1[1];
      local_48 = local_48 | 2;
    }
    if ((ulonglong)(uint)(*param_1 * 100) != *(ulonglong *)(lVar11 + 0x120)) {
      *(ulonglong *)(lVar11 + 0x120) = (ulonglong)(uint)(*param_1 * 100);
      local_48 = local_48 | 4;
    }
    if ((ulonglong)(uint)(*param_1 * 100) != *(ulonglong *)(lVar11 + 0x128)) {
      *(ulonglong *)(lVar11 + 0x128) = (ulonglong)(uint)(*param_1 * 100);
      local_48 = local_48 | 4;
    }
    local_50 = *(undefined8 *)(lVar11 + 0x80);
    local_40 = lVar11 + 0x110;
    KeReleaseSpinLock(*(undefined8 *)(lVar11 + 0x50),uVar6);
    lVar13 = DAT_14000a0d8;
    if (param_2 == '\0') {
      lVar13 = DAT_14000a328;
    }
    (**(code **)(*(longlong *)(lVar13 + 8) + 0x30))(&local_50);
    *(int *)(*(longlong *)(lVar11 + 8) + 0x140) = param_1[1];
    *(ulonglong *)(*(longlong *)(lVar11 + 8) + 0x148) = (ulonglong)(uint)(*param_1 * 100);
    *(ulonglong *)(*(longlong *)(lVar11 + 8) + 0x150) = (ulonglong)(uint)(*param_1 * 100);
    if (*(int *)(lVar11 + 100) == 1) {
      cVar5 = KeGetCurrentIrql();
      if (cVar5 == '\0') {
        UpdateInterfaceIndexImpl(lVar11,param_1[0x19]);
      }
      else {
        puVar8 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x6c707277);
        if (puVar8 == (undefined8 *)0x0) {
          LOCK();
          piVar2 = (int *)(lVar11 + 0x60);
          iVar7 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar7 == 1) {
            WanpDeleteConnEntry(lVar11);
          }
          iVar7 = -0x3fffff66;
          goto LAB_1400114d5;
        }
        puVar8[3] = puVar8;
        puVar8[2] = UpdateInterfaceIndexWorkItem;
        *puVar8 = 0;
        puVar8[4] = lVar11;
        *(int *)(puVar8 + 5) = param_1[0x19];
        ExQueueWorkItem(puVar8,0);
      }
    }
    else {
      LOCK();
      piVar2 = (int *)(lVar11 + 0x60);
      iVar7 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar7 == 1) {
        WanpDeleteConnEntry(lVar11);
      }
    }
  }
  iVar7 = 0;
LAB_1400114d5:
  ExitModuleCode(param_2);
  return iVar7;
}



===== WanpLinkUpIndicationWorkItem @ 140011500 =====

void WanpLinkUpIndicationWorkItem(longlong *param_1)

{
  WanpLinkUpIndicationWorkItemImpl(param_1,'\x01');
  return;
}



===== WanpLinkUpIndicationWorkItemImpl @ 140011518 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WanpLinkUpIndicationWorkItemImpl(longlong *param_1,char param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint *puVar16;
  char cVar17;
  undefined1 uVar18;
  int iVar19;
  undefined8 *puVar20;
  longlong *plVar21;
  longlong lVar22;
  undefined8 *puVar23;
  ushort uVar24;
  uint uVar25;
  undefined1 *puVar26;
  int *piVar27;
  bool bVar28;
  undefined1 auStackY_118 [8];
  undefined1 auStackY_110 [24];
  undefined1 local_d7;
  char local_d6;
  int *local_d0;
  uint *local_c8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int *local_b8;
  longlong *local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined2 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  cVar4 = (char)param_1[1];
  puVar6 = (undefined8 *)param_1[3];
  lVar7 = param_1[4];
  puVar20 = (undefined8 *)0x0;
  lVar22 = param_1[2];
  local_d7 = 0;
  local_d6 = param_2;
  local_b0 = param_1;
  memset(&local_88,0,0x4e);
  local_d0 = (int *)*param_1;
  local_c8 = (uint *)0x4267141ae307d632;
  piVar27 = *(int **)(local_d0 + 8);
  uStack_c0 = 0xd5234198;
  uStack_bc = 0xf2c38658;
  local_b8 = piVar27;
  ConvertGuidToString((uint *)param_1[6],(short *)&local_88,0x27);
  local_3c = 0;
  cVar17 = EnterModuleCode(cVar4);
  if (cVar17 == '\0') {
    LOCK();
    piVar27 = (int *)(param_1[3] + 0x80);
    iVar19 = *piVar27;
    *piVar27 = *piVar27 + -1;
    UNLOCK();
    if (iVar19 == 1) {
      WanpDeleteAdapter(param_1[3]);
    }
    if (param_1[2] != 0) {
      LOCK();
      piVar27 = (int *)(param_1[2] + 0x40);
      iVar19 = *piVar27;
      *piVar27 = *piVar27 + -1;
      UNLOCK();
      if (iVar19 == 1) {
        ExFreePoolWithTag(param_1[2],0);
      }
    }
    LOCK();
    piVar27 = (int *)(param_1[4] + 0x60);
    iVar19 = *piVar27;
    *piVar27 = *piVar27 + -1;
    UNLOCK();
    if (iVar19 == 1) {
      WanpDeleteConnEntry(param_1[4]);
    }
    ExFreePoolWithTag(param_1,0);
    piVar27 = local_d0;
    if (local_d6 != '\0') {
      NdisSetEvent(local_d0 + 0x12);
    }
    puVar26 = auStackY_118;
    piVar27[0x18] = -0x3ffeffef;
    goto LAB_140011787;
  }
  if ((*piVar27 == 1) && (*(short *)((longlong)puVar6 + 0x6a) == 0)) {
    local_a0 = 0;
    uStack_98 = 0;
    RtlInitUnicodeString(&local_a0,piVar27 + 0xd);
    *(ushort *)((longlong)puVar6 + 0x6a) = ((ushort)local_a0 >> 1) + 1;
    RtlUnicodeStringToAnsiString(puVar6 + 0xd,&local_a0);
  }
  iVar19 = *piVar27;
  if (iVar19 == 0) {
    iVar19 = WanpMapAdapter(0,puVar6,0,lVar7,&local_d7,piVar27,(longlong)local_d0,cVar4);
    if (iVar19 < 0) goto LAB_1400116e0;
    if (cVar4 == '\0') {
      plVar21 = (longlong *)puVar6[0x16];
    }
    else {
      plVar21 = (longlong *)puVar6[0x15];
    }
    KeAcquireSpinLockAtDpcLevel(plVar21 + 7);
    puVar26 = auStackY_118;
    LOCK();
    *(int *)(plVar21 + 8) = (int)plVar21[8] + 1;
    UNLOCK();
    piVar27 = local_b8;
LAB_1400120d9:
    if (*piVar27 != 0) {
      if (*(int *)(puVar6 + 0x17) == 1) {
        *(undefined1 *)((longlong)puVar6 + 0x94) = 6;
      }
      *(undefined4 *)(plVar21 + 0x12) = 4;
      puVar6[0x19] = _DAT_fffff78000000014 / 100000;
      LOCK();
      *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + 1;
      UNLOCK();
      LOCK();
      *(int *)(plVar21 + 8) = (int)plVar21[8] + 1;
      UNLOCK();
      plVar21[5] = lVar7;
    }
    if (*(int *)(lVar7 + 100) == 0) {
      uVar9 = *(undefined8 *)(lVar7 + 0x50);
      *(undefined8 *)(puVar26 + -8) = 0x14001214b;
      KeAcquireSpinLockAtDpcLevel(uVar9);
    }
    *(undefined8 **)(lVar7 + 8) = puVar6;
    LOCK();
    *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + 1;
    UNLOCK();
    *(undefined4 *)(lVar7 + 0x7c) = 2;
    LOCK();
    *(int *)(lVar7 + 0x60) = *(int *)(lVar7 + 0x60) + 1;
    UNLOCK();
    uVar24 = (-(ushort)(cVar4 != '\0') & 0x8123) + 0x86dd;
    *(ushort *)(lVar7 + 0x78) = uVar24 >> 8 | uVar24 * 0x100;
    if (*(int *)(lVar7 + 100) == 0) {
      uVar9 = *(undefined8 *)(lVar7 + 0x50);
      *(undefined8 *)(puVar26 + -8) = 0x14001219b;
      KeReleaseSpinLockFromDpcLevel(uVar9);
    }
    *(undefined8 *)(puVar26 + -8) = 0x1400121ab;
    KeReleaseSpinLockFromDpcLevel(plVar21 + 7);
    *(undefined8 *)(puVar26 + -8) = 0x1400121be;
    KeReleaseSpinLock(puVar6 + 0xf,local_d7);
    if (*piVar27 == 1) {
      *(undefined8 *)(puVar26 + -8) = 0x1400121d1;
      WanpCompleteIrp(puVar20);
    }
    uVar5 = *(undefined4 *)(puVar6 + 0x2d);
    *(undefined8 *)(puVar26 + -8) = 0x1400121e5;
    iVar19 = NdisIfUpdateInterface(g_hNdisIfProviderHandle,uVar5);
    LOCK();
    piVar27 = (int *)(puVar6 + 0x10);
    iVar3 = *piVar27;
    *piVar27 = *piVar27 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      *(undefined8 *)(puVar26 + -8) = 0x140012203;
      WanpDeleteAdapter((longlong)puVar6);
    }
    LOCK();
    plVar2 = plVar21 + 8;
    lVar7 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + -1;
    UNLOCK();
    if ((int)lVar7 == 1) {
      *(undefined8 *)(puVar26 + -8) = 0x14001221e;
      ExFreePoolWithTag(plVar21,0);
    }
LAB_1400116ed:
  }
  else {
    if (iVar19 == 1) {
      puVar20 = (undefined8 *)ExAllocateFromNPagedLookasideList(&g_llNotificationBlocks);
      if (puVar20 != (undefined8 *)0x0) {
        NdisIfGetNetLuidFromInterfaceIndex(local_d0[0x19],lVar7 + 0x48);
        plVar21 = (longlong *)ExAllocatePool2(0x40,0x228,0x69707257);
        if (plVar21 != (longlong *)0x0) {
          *(char *)((longlong)plVar21 + 0x14) = cVar4;
          bVar28 = cVar4 == '\0';
          *(undefined4 *)(plVar21 + 2) = 0x746e6957;
          puVar6[0x2c] = *(undefined8 *)(piVar27 + 6);
          lVar22 = DAT_14000ab70;
          if (bVar28) {
            lVar22 = DAT_14000ac90;
          }
          plVar21[0x1e] = lVar22;
          *(undefined4 *)((longlong)plVar21 + 0xa4) = 1;
          *(undefined2 *)(plVar21 + 0x17) = 0x10e;
          *(undefined1 *)((longlong)plVar21 + 0xba) = 0;
          uVar18 = DAT_14000a170;
          if (bVar28) {
            uVar18 = DAT_14000a3c0;
          }
          *(undefined1 *)((longlong)plVar21 + 0xbb) = uVar18;
          uVar18 = DAT_14000a171;
          if (bVar28) {
            uVar18 = DAT_14000a3c1;
          }
          *(undefined4 *)(plVar21 + 0x18) = 3;
          *(undefined1 *)((longlong)plVar21 + 0xbc) = uVar18;
          *(undefined8 *)((longlong)plVar21 + 0xc4) = 0x17;
          *(undefined4 *)((longlong)plVar21 + 0xcc) = 0;
          *(undefined4 *)((longlong)plVar21 + 0x6c) = 1;
          *(undefined4 *)(plVar21 + 0x15) = 0xe307d632;
          *(undefined4 *)((longlong)plVar21 + 0xac) = 0x4267141a;
          *(undefined4 *)(plVar21 + 0x16) = 0xd5234198;
          *(undefined4 *)((longlong)plVar21 + 0xb4) = 0xf2c38658;
          if (cVar4 == '\0') {
            uVar25 = *(uint *)((longlong)plVar21 + 0xd4) | 0x333;
          }
          else {
            uVar25 = *(uint *)((longlong)plVar21 + 0xd4) & 0xffffffcf | 0x303;
          }
          *(undefined1 *)(plVar21 + 6) = 0;
          plVar21[0xc] = 0;
          *(uint *)((longlong)plVar21 + 0xd4) = uVar25 & 0xfffffb3f | 0xc;
          plVar21[0xf] = 0;
          plVar21[0x10] = (longlong)(plVar21 + 0xf);
          KeInitializeSpinLock(plVar21 + 7);
          *(undefined4 *)(plVar21 + 0x1b) = 9;
          lVar22 = DAT_14000aa68;
          if (cVar4 == '\0') {
            lVar22 = DAT_14000ab88;
          }
          plVar21[0x1c] = lVar22;
          iVar19 = WanpMapAdapter(1,puVar6,(longlong)plVar21,lVar7,&local_d7,piVar27,
                                  (longlong)local_d0,cVar4);
          piVar27 = local_b8;
          if (-1 < iVar19) {
            if (cVar4 == '\0') {
              *(int *)(plVar21 + 0xe) = local_b8[0x92];
            }
            puVar8 = (undefined4 *)local_b0[6];
            uVar5 = *puVar8;
            uVar13 = puVar8[1];
            uVar14 = puVar8[2];
            uVar15 = puVar8[3];
            *(undefined4 *)((longlong)plVar21 + 0x8c) = 1;
            *(undefined4 *)(plVar21 + 0x12) = 3;
            *(undefined4 *)((longlong)plVar21 + 0x44) = uVar5;
            *(undefined4 *)(plVar21 + 9) = uVar13;
            *(undefined4 *)((longlong)plVar21 + 0x4c) = uVar14;
            *(undefined4 *)(plVar21 + 10) = uVar15;
            puVar6[0x19] = _DAT_fffff78000000014 / 100000;
            *(undefined4 *)(plVar21 + 4) = 0xffffffff;
            *(undefined4 *)((longlong)plVar21 + 0x6c) = 1;
            *(undefined4 *)(plVar21 + 8) = 1;
            LOCK();
            *(int *)(plVar21 + 8) = (int)plVar21[8] + 1;
            UNLOCK();
            KeAcquireSpinLockAtDpcLevel(plVar21 + 7);
            KeAcquireSpinLockAtDpcLevel(&g_rwlIfLock);
            KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
            puVar26 = auStackY_118;
            puVar23 = &g_leIfList;
            if ((longlong **)g_leIfList[1] != &g_leIfList) {
              puVar23 = (undefined8 *)0x3;
              pcVar10 = (code *)swi(0x29);
              g_leIfList = (longlong *)(*pcVar10)();
              puVar26 = auStackY_110;
            }
            *plVar21 = (longlong)g_leIfList;
            plVar21[1] = (longlong)puVar23;
            g_leIfList[1] = (longlong)plVar21;
            LOCK();
            g_ulNumDialOutInterfaces = g_ulNumDialOutInterfaces + 1;
            UNLOCK();
            *(undefined8 *)(puVar26 + -8) = 0x140011f5a;
            g_leIfList = plVar21;
            KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
            *(undefined8 *)(puVar26 + -8) = 0x140011f6d;
            KeReleaseSpinLockFromDpcLevel(&g_rwlIfLock);
            *(undefined4 *)((longlong)puVar20 + 0x34) = 0xffffffff;
            *(undefined4 *)(puVar20 + 6) = 3;
            *(undefined4 *)(puVar20 + 7) = *(undefined4 *)(puVar6 + 0x2d);
            *(char *)((longlong)puVar20 + 0x3c) = cVar4;
            if (cVar4 == '\0') {
              puVar20[8] = *(undefined8 *)(piVar27 + 0x93);
              *(int *)(puVar20 + 9) = piVar27[2];
              *(undefined8 *)((longlong)puVar20 + 0x4c) = local_88;
              *(undefined8 *)((longlong)puVar20 + 0x54) = uStack_80;
              *(undefined8 *)((longlong)puVar20 + 0x5c) = local_78;
              *(undefined8 *)((longlong)puVar20 + 100) = uStack_70;
              *(undefined8 *)((longlong)puVar20 + 0x6c) = local_68;
              *(undefined8 *)((longlong)puVar20 + 0x74) = uStack_60;
              *(undefined8 *)((longlong)puVar20 + 0x7c) = local_58;
              *(undefined8 *)((longlong)puVar20 + 0x84) = uStack_50;
              *(undefined8 *)((longlong)puVar20 + 0x8c) = local_48;
              *(undefined4 *)((longlong)puVar20 + 0x94) = local_40;
              *(undefined2 *)(puVar20 + 0x13) = 0;
            }
            else {
              *(int *)((longlong)puVar20 + 0x44) = piVar27[0x93];
              *(int *)(puVar20 + 8) = piVar27[0x92];
              *(int *)(puVar20 + 9) = piVar27[0x94];
              *(int *)((longlong)puVar20 + 0x4c) = piVar27[2];
              puVar20[10] = local_88;
              puVar20[0xb] = uStack_80;
              puVar20[0xc] = local_78;
              puVar20[0xd] = uStack_70;
              puVar20[0xe] = local_68;
              puVar20[0xf] = uStack_60;
              puVar20[0x10] = local_58;
              puVar20[0x11] = uStack_50;
              puVar20[0x12] = local_48;
              *(undefined4 *)(puVar20 + 0x13) = local_40;
              *(undefined2 *)((longlong)puVar20 + 0x9c) = 0;
            }
            goto LAB_1400120d9;
          }
          ExFreePoolWithTag(plVar21,0);
          ExFreeToNPagedLookasideList(&g_llNotificationBlocks,puVar20);
          goto LAB_1400116e0;
        }
        ExFreeToNPagedLookasideList(&g_llNotificationBlocks,puVar20);
      }
      iVar19 = -0x3fffff66;
LAB_1400116e0:
      puVar26 = auStackY_118;
      if (lVar7 != 0) {
        *(undefined4 *)(lVar7 + 0x7c) = 3;
        puVar26 = auStackY_118;
      }
      goto LAB_1400116ed;
    }
    if (iVar19 != 2) {
      iVar19 = -0x3ffffff3;
      goto LAB_1400116e0;
    }
    uVar18 = KeAcquireSpinLockRaiseToDpc(puVar6 + 0xf);
    local_d7 = uVar18;
    KeAcquireSpinLockAtDpcLevel(lVar22 + 0x38);
    if (1 < *(int *)(lVar22 + 0x90) - 2U) {
      KeReleaseSpinLockFromDpcLevel(lVar22 + 0x38);
      KeReleaseSpinLock(puVar6 + 0xf,uVar18);
      LOCK();
      piVar27 = (int *)(lVar22 + 0x40);
      iVar19 = *piVar27;
      *piVar27 = *piVar27 + -1;
      UNLOCK();
      if (iVar19 == 1) {
        ExFreePoolWithTag(lVar22,0);
      }
      iVar19 = -0x3ffffe7c;
LAB_140011ab8:
      LOCK();
      piVar27 = (int *)(lVar7 + 0x60);
      iVar3 = *piVar27;
      *piVar27 = *piVar27 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        WanpDeleteConnEntry(lVar7);
      }
      local_d7 = KeAcquireSpinLockRaiseToDpc(puVar6 + 0xf);
      *(undefined4 *)(lVar7 + 0x7c) = 3;
      KeAcquireSpinLockAtDpcLevel(lVar22 + 0x38);
      WanpFlushQueuedNetBufferLists((longlong)puVar6,cVar4);
      *(undefined4 *)(lVar22 + 0x8c) = 2;
      *(undefined4 *)(lVar22 + 0x90) = 2;
      puVar6[0x19] = _DAT_fffff78000000014 / 100000;
      KeReleaseSpinLockFromDpcLevel(lVar22 + 0x38);
      KeReleaseSpinLock(puVar6 + 0xf,local_d7);
      puVar26 = auStackY_118;
      goto LAB_1400116ed;
    }
    piVar1 = (int *)(lVar22 + 0x40);
    if (*(char *)(lVar22 + 0x30) != '\0') {
      KeReleaseSpinLockFromDpcLevel(lVar22 + 0x38);
      KeReleaseSpinLock(puVar6 + 0xf,uVar18);
      LOCK();
      iVar19 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar19 == 1) {
        ExFreePoolWithTag(lVar22,0);
      }
      iVar19 = -0x3ffffe7c;
      goto LAB_140011ab8;
    }
    iVar19 = *(int *)(puVar6 + 0x13);
    iVar3 = *(int *)((longlong)puVar6 + 0x9c);
    iVar11 = *(int *)(puVar6 + 0x14);
    iVar12 = *(int *)((longlong)puVar6 + 0xa4);
    piVar27[0x8e] = iVar19;
    piVar27[0x8f] = iVar3;
    piVar27[0x90] = iVar11;
    piVar27[0x91] = iVar12;
    *(int *)(lVar22 + 0x44) = iVar19;
    *(int *)(lVar22 + 0x48) = iVar3;
    *(int *)(lVar22 + 0x4c) = iVar11;
    *(int *)(lVar22 + 0x50) = iVar12;
    local_a8 = (undefined8 *)ExAllocateFromNPagedLookasideList(&g_llNotificationBlocks);
    if (local_a8 == (undefined8 *)0x0) {
      KeReleaseSpinLockFromDpcLevel(lVar22 + 0x38);
      KeReleaseSpinLock(puVar6 + 0xf,uVar18);
      LOCK();
      iVar19 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar19 == 1) {
        ExFreePoolWithTag(lVar22,0);
      }
      iVar19 = -0x3fffff66;
      goto LAB_140011ab8;
    }
    *(longlong *)(lVar22 + 0x28) = lVar7;
    *(longlong *)(lVar7 + 0x10) = lVar22;
    *(undefined8 **)(lVar7 + 8) = puVar6;
    LOCK();
    *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + 1;
    UNLOCK();
    LOCK();
    *(int *)(lVar7 + 0x60) = *(int *)(lVar7 + 0x60) + 1;
    UNLOCK();
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (cVar4 == '\0') {
      *(undefined8 *)(lVar22 + 0xf8) = *(undefined8 *)(piVar27 + 0x93);
    }
    else {
      *(char *)(lVar22 + 0xfe) = (char)((uint)*(undefined4 *)(puVar6 + 0x2d) >> 8);
      *(undefined1 *)(lVar22 + 0xff) = *(undefined1 *)(puVar6 + 0x2d);
    }
    *(undefined4 *)(local_a8 + 6) = 1;
    *(undefined4 *)((longlong)local_a8 + 0x34) = *(undefined4 *)(lVar22 + 0x20);
    *(undefined4 *)(local_a8 + 7) = *(undefined4 *)(puVar6 + 0x2d);
    *(char *)((longlong)local_a8 + 0x3c) = cVar4;
    if (cVar4 == '\0') {
      local_a8[8] = *(undefined8 *)(piVar27 + 0x93);
      *(int *)(local_a8 + 9) = piVar27[2];
    }
    else {
      *(int *)((longlong)local_a8 + 0x44) = piVar27[0x93];
      *(int *)(local_a8 + 8) = piVar27[0x92];
      *(int *)(local_a8 + 9) = piVar27[0x94];
      *(int *)((longlong)local_a8 + 0x4c) = piVar27[2];
    }
    *(undefined4 *)(lVar22 + 0x8c) = 1;
    *(undefined4 *)(lVar22 + 0x90) = 4;
    bVar28 = g_SetInterfaceTagforRouter != '\0';
    puVar6[0x19] = _DAT_fffff78000000014 / 100000;
    if (bVar28) {
      *(uint **)(lVar22 + 0xa8) = local_c8;
      *(ulonglong *)(lVar22 + 0xb0) = CONCAT44(uStack_bc,uStack_c0);
    }
    WanpUpdateConnEntryWithLinkUpInfo(lVar7,local_d0);
    iVar19 = WanpAddAdapterToIp((longlong)puVar6,lVar22,cVar4,local_d7);
    if (iVar19 == 0) {
      iVar19 = WanpIpAddSubInterface((longlong)puVar6,lVar22,lVar7,cVar4);
      if (iVar19 != 0) {
        LOCK();
        piVar27 = (int *)(lVar7 + 0x60);
        iVar3 = *piVar27;
        *piVar27 = *piVar27 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          WanpDeleteConnEntry(lVar7);
        }
        WanpDeleteInterfaceFromIp(lVar22);
        goto LAB_140011a8e;
      }
      WanpAcquireResource((int *)&WfpMutex);
      uVar18 = KeAcquireSpinLockRaiseToDpc(puVar6 + 0xf);
      local_d7 = uVar18;
      KeAcquireSpinLockAtDpcLevel(lVar22 + 0x38);
      local_c8 = *(uint **)(lVar22 + 0x98);
      local_b8 = (int *)CONCAT44(local_b8._4_4_,*(undefined4 *)(lVar22 + 0xa0));
      *(undefined1 *)(lVar22 + 0x30) = 6;
      WanpTransmitQueuedPackets((longlong)puVar6,uVar18,cVar4);
      puVar16 = local_c8;
      if (local_c8 != (uint *)0x0) {
        WanpRemoveSubnetFilters(local_c8,(uint)local_b8);
        uVar25 = *puVar16;
        while (uVar25 != 0) {
          uVar25 = uVar25 - 1;
          LOCK();
          iVar3 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            ExFreePoolWithTag(lVar22,0);
          }
        }
      }
      WanpReleaseResource((int *)&WfpMutex);
      WanpCompleteIrp(local_a8);
      local_d0[0x1a] = *(int *)(puVar6 + 0x2d);
    }
    else {
      LOCK();
      piVar27 = (int *)(lVar7 + 0x60);
      iVar3 = *piVar27;
      *piVar27 = *piVar27 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        WanpDeleteConnEntry(lVar7);
      }
LAB_140011a8e:
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        ExFreePoolWithTag(lVar22,0);
      }
      if (iVar19 < 0) goto LAB_140011ab8;
    }
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    puVar26 = auStackY_118;
    if (iVar3 == 1) {
      ExFreePoolWithTag(lVar22,0);
      puVar26 = auStackY_118;
    }
  }
  plVar21 = local_b0;
  LOCK();
  piVar27 = (int *)(local_b0[3] + 0x80);
  iVar3 = *piVar27;
  *piVar27 = *piVar27 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    lVar7 = local_b0[3];
    *(undefined8 *)(puVar26 + -8) = 0x140011710;
    WanpDeleteAdapter(lVar7);
  }
  if (plVar21[2] != 0) {
    LOCK();
    piVar27 = (int *)(plVar21[2] + 0x40);
    iVar3 = *piVar27;
    *piVar27 = *piVar27 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      lVar7 = plVar21[2];
      *(undefined8 *)(puVar26 + -8) = 0x140011733;
      ExFreePoolWithTag(lVar7,0);
    }
  }
  LOCK();
  piVar27 = (int *)(plVar21[4] + 0x60);
  iVar3 = *piVar27;
  *piVar27 = *piVar27 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    lVar7 = plVar21[4];
    *(undefined8 *)(puVar26 + -8) = 0x140011750;
    WanpDeleteConnEntry(lVar7);
  }
  piVar27 = local_d0;
  local_d0[0x18] = iVar19;
  *(undefined8 *)(puVar26 + -8) = 0x140011764;
  ExFreePoolWithTag(plVar21,0);
  if (local_d6 != '\0') {
    *(undefined8 *)(puVar26 + -8) = 0x14001177a;
    NdisSetEvent(piVar27 + 0x12);
  }
  *(undefined8 *)(puVar26 + -8) = 0x140011787;
  ExitModuleCode(cVar4);
LAB_140011787:
  *(undefined8 *)(puVar26 + -8) = 0x140011793;
  return;
}



===== WanpRouterLinkDownHandler @ 140012230 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WanpRouterLinkDownHandler(longlong param_1,undefined1 param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  lVar4 = *(longlong *)(param_1 + 8);
  *(undefined4 *)(lVar3 + 0x8c) = 2;
  *(undefined4 *)(lVar3 + 0x90) = 2;
  *(longlong *)(lVar4 + 200) = _DAT_fffff78000000014 / 100000;
  *(undefined8 *)(lVar3 + 0x28) = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    WanpDeleteConnEntry(param_1);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    WanpDeleteConnEntry(param_1);
  }
  if (*(int *)(lVar3 + 0x88) != 0) {
    WanpFlushQueuedNetBufferLists(lVar4,*(char *)(param_1 + 4));
  }
  lVar5 = ExAllocateFromNPagedLookasideList(&g_llNotificationBlocks);
  if (lVar5 == 0) {
    KeReleaseSpinLockFromDpcLevel(lVar3 + 0x38);
    KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),param_2);
  }
  else {
    *(undefined4 *)(lVar5 + 0x30) = 2;
    *(undefined4 *)(lVar5 + 0x38) = *(undefined4 *)(lVar4 + 0x168);
    *(undefined4 *)(lVar5 + 0x34) = *(undefined4 *)(lVar3 + 0x20);
    *(undefined1 *)(lVar5 + 0x3c) = *(undefined1 *)(param_1 + 4);
    if (*(char *)(param_1 + 4) == '\0') {
      *(undefined8 *)(lVar5 + 0x40) = *(undefined8 *)(param_1 + 0x30);
    }
    else {
      *(undefined4 *)(lVar5 + 0x40) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(lVar5 + 0x44) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(lVar5 + 0x48) = *(undefined4 *)(param_1 + 0x20);
    }
    KeReleaseSpinLockFromDpcLevel(lVar3 + 0x38);
    KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),param_2);
    *param_3 = lVar5;
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    WanpDeleteConnEntry(param_1);
  }
  return 0;
}



===== WanpUpdateConnEntryWithLinkUpInfo @ 1400123b8 =====

undefined8 WanpUpdateConnEntryWithLinkUpInfo(longlong param_1,int *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  ushort uVar4;
  
  lVar2 = *(longlong *)(param_2 + 8);
  *(ulonglong *)(param_1 + 0x98) = (ulonglong)(uint)(*param_2 * 100);
  *(ulonglong *)(param_1 + 0xa0) = (ulonglong)(uint)(*param_2 * 100);
  *(int *)(param_1 + 0x118) = param_2[1];
  *(ulonglong *)(param_1 + 0x120) = (ulonglong)(uint)(*param_2 * 100);
  iVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x110) = 1;
  *(undefined4 *)(param_1 + 0x7c) = 2;
  *(ulonglong *)(param_1 + 0x128) = (ulonglong)(uint)(iVar1 * 100);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(lVar2 + 0x10);
  *(bool *)(param_1 + 0x7a) = *(int *)(lVar2 + 4) == 1;
  if (*(char *)(param_1 + 4) == '\0') {
    uVar3 = *(ulonglong *)(lVar2 + 0x24c);
    *(ulonglong *)(param_1 + 0x30) = uVar3;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(lVar2 + 0x24c);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(lVar2 + 0x248);
    uVar3 = (ulonglong)*(uint *)(lVar2 + 0x250);
    *(uint *)(param_1 + 0x20) = *(uint *)(lVar2 + 0x250);
  }
  LOCK();
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  UNLOCK();
  uVar4 = (-(ushort)(*(char *)(param_1 + 4) != '\0') & 0x8123) + 0x86dd;
  *(ushort *)(param_1 + 0x78) = uVar4 >> 8 | uVar4 * 0x100;
  return CONCAT71((int7)(uVar3 >> 8),-*(char *)(param_1 + 4));
}



===== ConvertGuidToString @ 140012478 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ConvertGuidToString(uint *param_1,short *param_2,ulonglong param_3)

{
  short *psVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStackY_138 [32];
  ulonglong local_108;
  short *local_100;
  longlong local_f8 [2];
  wchar_t local_e8 [104];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_138;
  local_108 = param_3 & 0xffffffff;
  local_100 = param_2;
  RtlStringCchCopyExW(param_2,local_108,param_3,(longlong *)&local_100,(longlong *)&local_108);
  ultoaW(*param_1,local_e8);
  RtlStringCchCatExW(local_100,local_108,local_e8,&local_100,&local_108);
  RtlStringCchCatExW(local_100,local_108,L"-",&local_100,&local_108);
  ultoaW((uint)(ushort)param_1[1],local_e8);
  RtlStringCchCatExW(local_100,local_108,local_e8,&local_100,&local_108);
  RtlStringCchCatExW(local_100,local_108,L"-",&local_100,&local_108);
  ultoaW((uint)*(ushort *)((longlong)param_1 + 6),local_e8);
  RtlStringCchCatExW(local_100,local_108,local_e8,&local_100,&local_108);
  RtlStringCchCatExW(local_100,local_108,L"-",&local_100,&local_108);
  uVar3 = 0;
  puVar2 = param_1 + 2;
  do {
    ultoaW((uint)(byte)*puVar2,local_e8);
    RtlStringCchCatExW(local_100,local_108,local_e8,&local_100,&local_108);
    if (uVar3 == 1) {
      RtlStringCchCatExW(local_100,local_108,L"-",&local_100,&local_108);
    }
    psVar1 = local_100;
    uVar3 = uVar3 + 1;
    puVar2 = (uint *)((longlong)puVar2 + 1);
  } while (uVar3 < 8);
  local_f8[0] = 0;
  uVar4 = local_108;
  uVar3 = RtlStringValidateDestAndLengthW(local_100,local_108,local_f8);
  if (-1 < (int)uVar3) {
    RtlStringCopyWorkerW(psVar1 + local_f8[0],uVar4 - local_f8[0],(longlong *)0x0,0x140008594);
  }
  return 0;
}



===== ultoaW @ 1400126c0 =====

uint ultoaW(uint param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  longlong lVar3;
  longlong lVar2;
  ulonglong uVar4;
  uint uVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  ulonglong uVar8;
  ulonglong in_stack_00000030;
  
  uVar8 = 0;
  uVar4 = 0;
  if ((param_2 == (wchar_t *)0x0) || (pwVar7 = param_2, 99 < in_stack_00000030)) {
    uVar5 = 0xc000000d;
  }
  else {
    do {
      uVar5 = (uint)uVar4;
      if (0x62 < uVar8) break;
      uVar5 = param_1 & 0xf;
      uVar4 = (ulonglong)uVar5;
      uVar8 = uVar8 + 1;
      param_1 = param_1 - uVar5 >> 4;
      *pwVar7 = L"0123456789ABCDEF"[uVar4];
      pwVar7 = pwVar7 + 1;
    } while (param_1 != 0);
    uVar5 = -(uint)(uVar5 != 0) & 0x80000005;
    if (uVar8 < in_stack_00000030) {
      pwVar6 = pwVar7;
      for (uVar4 = in_stack_00000030 - uVar8 & 0x7fffffffffffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pwVar6 = L'0';
        pwVar6 = pwVar6 + 1;
      }
      pwVar7 = pwVar7 + (in_stack_00000030 - uVar8);
    }
    *pwVar7 = L'\0';
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_2[lVar2] != L'\0');
    pwVar7 = param_2 + lVar3;
    if (param_2 < pwVar7) {
      do {
        wVar1 = *param_2;
        *param_2 = *pwVar7;
        param_2 = param_2 + 1;
        *pwVar7 = wVar1;
        pwVar7 = pwVar7 + -1;
      } while (param_2 < pwVar7);
    }
  }
  return uVar5;
}



===== WanAddUserModeInterface @ 14001279c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WanAddUserModeInterface(longlong param_1,uint param_2,uint param_3,undefined8 param_4)

{
  char cVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  bool bVar5;
  longlong lVar6;
  undefined1 uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  uint *puVar11;
  longlong lVar12;
  undefined8 uVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  longlong lVar16;
  char cVar17;
  bool bVar18;
  bool bVar19;
  undefined1 auStackY_128 [8];
  undefined1 auStackY_120 [24];
  undefined8 in_stack_fffffffffffffef8;
  undefined1 local_d7;
  longlong *local_d0;
  uint local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  longlong *local_a8;
  undefined8 *local_a0;
  longlong local_98;
  ushort local_90 [8];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  cVar17 = (char)param_4;
  local_d0 = (longlong *)0x0;
  local_90[0] = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  local_90[3] = 0;
  local_90[4] = 0;
  local_90[5] = 0;
  local_90[6] = 0;
  local_90[7] = 0;
  bVar5 = false;
  local_b8 = (longlong *)0x4267141ae307d632;
  uStack_b0 = 0xd5234198;
  uStack_ac = 0xf2c38658;
  LOCK();
  _DAT_14000a7e8 = _DAT_14000a7e8 + 1;
  UNLOCK();
  *(undefined8 *)(param_1 + 0x38) = 0;
  if (0x437 < param_2) {
    piVar2 = *(int **)(param_1 + 0x18);
    local_98 = param_1;
    RtlInitUnicodeString(local_90,piVar2 + 0x8a);
    puVar11 = (uint *)&ServerInterfaceGuid;
    if (piVar2[0x10c] != 1) {
      puVar11 = (uint *)(piVar2 + 0x86);
    }
    if (piVar2[1] == 0) {
      uVar7 = KeAcquireSpinLockRaiseToDpc(&g_rwlIfLock);
      KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
      plVar10 = WanpFindInterfaceGivenIndex(*piVar2);
      local_a8 = plVar10;
      if (plVar10 != (longlong *)0x0) {
        KeReleaseSpinLockFromDpcLevel(plVar10 + 7);
        LOCK();
        plVar10 = plVar10 + 8;
        lVar16 = *plVar10;
        *(int *)plVar10 = (int)*plVar10 + -1;
        UNLOCK();
        if ((int)lVar16 == 1) {
          ExFreePoolWithTag(local_a8);
        }
        KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
        KeReleaseSpinLock(&g_rwlIfLock,uVar7);
        puVar15 = auStackY_128;
        LOCK();
        _DAT_14000a7ec = _DAT_14000a7ec + 1;
        UNLOCK();
        uVar9 = 0x40000000;
        goto LAB_1400131b0;
      }
      KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
      KeReleaseSpinLock(&g_rwlIfLock,uVar7);
      WanpAcquireResource((int *)&WfpMutex);
      uVar8 = WanpSetupWfpCallOuts();
      plVar10 = (longlong *)(ulonglong)uVar8;
      WanpReleaseResource((int *)&WfpMutex);
      puVar15 = auStackY_128;
      if (-1 < (int)uVar8) {
        uVar9 = WanpCreateAndRegisterInterface
                          ((uint *)(piVar2 + 0x86),local_90,(undefined8 *)(piVar2 + 0x84),*piVar2,
                           in_stack_fffffffffffffef8,cVar17,piVar2[0x10c],(longlong *)&local_d0,
                           (longlong *)&local_a8);
        puVar15 = auStackY_128;
        plVar10 = (longlong *)(uVar9 & 0xffffffff);
        if (-1 < (int)uVar9) {
          uVar7 = KeAcquireSpinLockRaiseToDpc(&g_rwlIfLock);
          plVar10 = (longlong *)CONCAT71((int7)((ulonglong)plVar10 >> 8),uVar7);
          KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
          if ((longlong **)g_leIfList[1] == &g_leIfList) {
            *local_a8 = (longlong)g_leIfList;
            local_a8[1] = (longlong)&g_leIfList;
            g_leIfList[1] = (longlong)local_a8;
            g_leIfList = local_a8;
            LOCK();
            *(int *)(local_a8 + 8) = (int)local_a8[8] + 1;
            UNLOCK();
            KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
            KeReleaseSpinLock(&g_rwlIfLock,uVar7);
            uVar7 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
            KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
            plVar10 = local_d0;
            plVar14 = local_d0 + 0xf;
            KeAcquireSpinLockAtDpcLevel(plVar14);
            if (*(char *)((longlong)plVar10 + 0x94) == '\0') {
              *(undefined1 *)((longlong)plVar10 + 0x94) = 6;
              if ((undefined8 *)*DAT_14000ada8 != &g_leMappedAdapterList) goto LAB_140013199;
              _g_ulNumMappedAdapters = _g_ulNumMappedAdapters + 1;
              *plVar10 = (longlong)&g_leMappedAdapterList;
              plVar10[1] = (longlong)DAT_14000ada8;
              *DAT_14000ada8 = (longlong)plVar10;
              DAT_14000ada8 = plVar10;
              LOCK();
              *(int *)(plVar10 + 0x10) = (int)plVar10[0x10] + 1;
              UNLOCK();
              plVar10 = local_d0;
            }
            KeReleaseSpinLockFromDpcLevel(plVar14);
            KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
            KeReleaseSpinLock(&g_rwlAdapterLock,uVar7);
            puVar15 = auStackY_128;
            piVar2[2] = (int)plVar10[0x2d];
            *(undefined8 *)(local_98 + 0x38) = 0x438;
            uVar9 = 0;
            goto LAB_1400131b0;
          }
LAB_140013199:
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          puVar15 = auStackY_120;
        }
      }
      LOCK();
      _DAT_14000a7ec = _DAT_14000a7ec + 1;
      UNLOCK();
      uVar9 = (ulonglong)plVar10 & 0xffffffff;
      goto LAB_1400131b0;
    }
    if (0x437 < param_3) {
      uVar9 = WanpCreateNewAdapter
                        (puVar11,local_90,cVar17,CONCAT71((int7)((ulonglong)param_4 >> 8),1),
                         piVar2[0x10c],(longlong *)&local_d0);
      puVar15 = auStackY_128;
      local_c8 = (uint)uVar9;
      if ((int)local_c8 < 0) goto LAB_1400131b0;
      if (cVar17 == '\0') {
        lVar16 = local_d0[0x16];
      }
      else {
        lVar16 = local_d0[0x15];
      }
      uVar7 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
      LOCK();
      iVar4 = DAT_14000ad30 + 1;
      UNLOCK();
      bVar18 = DAT_14000ad30 == 0;
      DAT_14000ad30 = iVar4;
      if (bVar18) {
        KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
      }
      KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
      lVar12 = *(longlong *)(piVar2 + 0x84);
      bVar18 = lVar12 == 0;
      if (bVar18) {
        lVar12 = local_d0[0x2c];
        *(longlong *)(piVar2 + 0x84) = lVar12;
      }
      else {
        local_d0[0x2c] = lVar12;
      }
      LOCK();
      UNLOCK();
      if (DAT_14000ad30 == 1) {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeReleaseSpinLock(&DAT_14000ad28);
      }
      else {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeLowerIrql(CONCAT71((int7)((ulonglong)lVar12 >> 8),uVar7));
      }
      *(int *)(lVar16 + 0xa4) = piVar2[0x10c];
      *(undefined2 *)(lVar16 + 0xb8) = 0x10e;
      uVar7 = DAT_14000a170;
      if (cVar17 == '\0') {
        uVar7 = DAT_14000a3c0;
      }
      *(undefined1 *)(lVar16 + 0xbb) = uVar7;
      *(undefined1 *)(lVar16 + 0xba) = 0;
      uVar7 = DAT_14000a171;
      if (cVar17 == '\0') {
        uVar7 = DAT_14000a3c1;
      }
      *(undefined1 *)(lVar16 + 0xbc) = uVar7;
      *(undefined4 *)(lVar16 + 0xc0) = 4;
      *(undefined8 *)(lVar16 + 0xc4) = 0x17;
      *(undefined4 *)(lVar16 + 0xcc) = 0;
      *(undefined4 *)(lVar16 + 0x6c) = 0;
      uVar8 = *(uint *)(lVar16 + 0xd4) & 0xffffffef | 0x20f;
      if (cVar17 == '\0') {
        uVar8 = *(uint *)(lVar16 + 0xd4) | 0x21f;
      }
      *(uint *)(lVar16 + 0xd4) = uVar8 & 0xfffffb3f | 0x120;
      *(undefined8 *)(lVar16 + 0x78) = 0;
      *(undefined8 **)(lVar16 + 0x80) = (undefined8 *)(lVar16 + 0x78);
      *(undefined4 *)(lVar16 + 0xd8) = 9;
      uVar13 = DAT_14000aa68;
      if (cVar17 == '\0') {
        uVar13 = DAT_14000ab88;
      }
      *(undefined8 *)(lVar16 + 0xe0) = uVar13;
      if (g_SetInterfaceTagForVpnServer != '\0') {
        *(undefined4 *)(lVar16 + 0xa8) = (undefined4)local_b8;
        *(undefined4 *)(lVar16 + 0xac) = local_b8._4_4_;
        *(undefined4 *)(lVar16 + 0xb0) = uStack_b0;
        *(undefined4 *)(lVar16 + 0xb4) = uStack_ac;
      }
      KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
      KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
      *(undefined4 *)(lVar16 + 0x90) = 2;
      local_d0[0x19] = _DAT_fffff78000000014 / 100000;
      KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
      KeReleaseSpinLock(&g_rwlAdapterLock);
      memset(piVar2 + 3,0,0x204);
      local_d7 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
      LOCK();
      iVar4 = DAT_14000ad30 + 1;
      UNLOCK();
      bVar19 = DAT_14000ad30 == 0;
      DAT_14000ad30 = iVar4;
      if (bVar19) {
        KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
      }
      KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
      plVar10 = local_d0 + 0xf;
      KeAcquireSpinLockAtDpcLevel(plVar10);
      local_c0 = lVar16 + 0x38;
      KeAcquireSpinLockAtDpcLevel(local_c0);
      LOCK();
      iVar4 = DAT_14000ad30 + -1;
      UNLOCK();
      bVar19 = DAT_14000ad30 == 1;
      DAT_14000ad30 = iVar4;
      if (bVar19) {
        KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
      }
      plVar14 = local_d0;
      if (*piVar2 != 0) {
        *(int *)(lVar16 + 0x20) = *piVar2;
      }
      memmove(piVar2 + 3,(void *)(local_d0[10] + 0x10),(ulonglong)*(ushort *)(local_d0 + 9) - 0x10);
      cVar1 = *(char *)((longlong)plVar14 + 0x94);
      lVar12 = local_c0;
      if (cVar1 == '\x03') {
        if ((!bVar18) && (*(char *)(lVar16 + 0x30) != '\x06')) {
          if (cVar17 == '\0') {
LAB_140012bc0:
            *(undefined8 *)(lVar16 + 0xf8) = *(undefined8 *)(piVar2 + 0x10a);
          }
          else {
            *(char *)(lVar16 + 0xfe) = (char)((ulonglong)plVar14[0x2d] >> 8);
            uVar7 = (undefined1)plVar14[0x2d];
LAB_140012e4e:
            *(undefined1 *)(lVar16 + 0xff) = uVar7;
          }
        }
LAB_140012e5a:
        piVar2[2] = (int)plVar14[0x2d];
        KeReleaseSpinLockFromDpcLevel(lVar12);
        KeReleaseSpinLock(plVar10,local_d7);
        uVar7 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
        KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
        if (bVar5) {
          plVar10 = plVar14 + 4;
          if ((undefined8 *)*DAT_14000ad48 != &g_leDialInAdapterList) goto LAB_140013199;
          g_ulNumDialInAdapters = g_ulNumDialInAdapters + 1;
          *plVar10 = (longlong)&g_leDialInAdapterList;
          plVar14[5] = (longlong)DAT_14000ad48;
          *DAT_14000ad48 = (longlong)plVar10;
          DAT_14000ad48 = plVar10;
        }
        KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
        KeReleaseSpinLock(&g_rwlAdapterLock,uVar7);
        *(undefined8 *)(local_98 + 0x38) = 0x438;
      }
      else {
        if (cVar1 == '\x02') {
          KeReleaseSpinLockFromDpcLevel(local_c0);
          KeReleaseSpinLock(plVar10,local_d7);
          puVar15 = auStackY_128;
          uVar9 = 0xc0000184;
          goto LAB_1400131b0;
        }
        if (cVar1 != '\0') goto LAB_140012e5a;
        bVar5 = true;
        local_50 = 0;
        lVar12 = lVar16 + 0x38;
        local_c0 = CONCAT44(local_c0._4_4_,piVar2[0x10c]);
        *(undefined1 *)((longlong)plVar14 + 0x94) = 2;
        local_80 = 0;
        uStack_78 = 0;
        local_70 = 0;
        uStack_68 = 0;
        local_60 = 0;
        uStack_58 = 0;
        KeReleaseSpinLockFromDpcLevel(lVar12);
        KeReleaseSpinLock(plVar10,local_d7);
        FllwanpGetCompartmentInformation
                  (0,(longlong)&local_c0,(longlong)&local_70,(longlong)&local_80);
        uVar7 = KeAcquireSpinLockRaiseToDpc(plVar10);
        KeAcquireSpinLockAtDpcLevel(lVar12);
        local_a0 = (undefined8 *)ExAllocatePool2(0x40,(short)plVar14[0xb] + 0x62);
        if (local_a0 == (undefined8 *)0x0) {
          KeReleaseSpinLockFromDpcLevel(lVar12);
          KeReleaseSpinLock(plVar10,uVar7);
          puVar15 = auStackY_128;
          uVar9 = 0xc000009a;
          goto LAB_1400131b0;
        }
        *local_a0 = 0x600180;
        *(undefined8 *)((longlong)local_a0 + 0x14) = 0;
        *(undefined4 *)(local_a0 + 1) = 0xffffffff;
        *(undefined4 *)((longlong)local_a0 + 0xc) = 0xffffffff;
        *(undefined4 *)(local_a0 + 2) = 0xffffffff;
        *(undefined2 *)((longlong)local_a0 + 0x2a) = 0;
        *(undefined2 *)((longlong)local_a0 + 0x2e) = 0;
        *(undefined4 *)((longlong)local_a0 + 0x24) = 2;
        *(undefined8 *)((longlong)local_a0 + 0x1c) = 4;
        lVar6 = plVar14[0xb];
        *(undefined2 *)((longlong)local_a0 + 0x32) = 0x60;
        *(short *)(local_a0 + 6) = (short)lVar6 + 2;
        lVar6 = plVar14[0x14];
        *(longlong *)((longlong)local_a0 + 0x34) = plVar14[0x13];
        *(longlong *)((longlong)local_a0 + 0x3c) = lVar6;
        *(undefined8 *)((longlong)local_a0 + 0x44) = local_80;
        *(undefined8 *)((longlong)local_a0 + 0x4c) = uStack_78;
        memmove(local_a0 + 0xc,(void *)plVar14[0xc],(ulonglong)*(ushort *)(plVar14 + 0xb) + 2);
        KeReleaseSpinLockFromDpcLevel(lVar12);
        KeReleaseSpinLock(plVar10,uVar7);
        local_b8 = plVar14 + 0x2d;
        local_c8 = NdisIfRegisterInterface(g_hNdisIfProviderHandle,plVar14[0x2c],plVar14,local_a0);
        ExFreePoolWithTag(local_a0);
        if (local_c8 == 0) {
          LOCK();
          *(int *)(plVar14 + 0x10) = (int)plVar14[0x10] + 1;
          UNLOCK();
          local_d7 = KeAcquireSpinLockRaiseToDpc(plVar10);
          KeAcquireSpinLockAtDpcLevel(lVar12);
          *(undefined1 *)((longlong)plVar14 + 0x94) = 3;
          *(int *)(local_d0 + 0x2e) = piVar2[0x10c];
          plVar14 = local_d0;
          if (cVar17 == '\0') goto LAB_140012bc0;
          *(char *)(lVar16 + 0xfe) = (char)((ulonglong)*local_b8 >> 8);
          uVar7 = (undefined1)*local_b8;
          goto LAB_140012e4e;
        }
        uVar7 = KeAcquireSpinLockRaiseToDpc();
        *(undefined1 *)((longlong)plVar14 + 0x94) = 0;
        KeReleaseSpinLock(plVar10,uVar7);
      }
      puVar15 = auStackY_128;
      uVar9 = (ulonglong)local_c8;
      goto LAB_1400131b0;
    }
  }
  puVar15 = auStackY_128;
  uVar9 = 0xc0000023;
LAB_1400131b0:
  *(undefined8 *)(puVar15 + -8) = 0x1400131bc;
  return uVar9;
}



===== WanAllocLuidIndex @ 1400131e0 =====

void WanAllocLuidIndex(longlong param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_2 == 8) && (param_3 == 8)) {
    uVar1 = NdisIfAllocateNetLuidIndex
                      (**(undefined2 **)(param_1 + 0x18),*(undefined2 **)(param_1 + 0x18) + 2);
  }
  else {
    uVar1 = 0xc000000d;
  }
  *(undefined8 *)(param_1 + 0x38) = 8;
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}



===== WanCancelNotificationIrp @ 140013230 =====

void WanCancelNotificationIrp(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  plVar1 = (longlong *)(param_2 + 0xa8);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    IoReleaseCancelSpinLock
              (CONCAT71((int7)((ulonglong)plVar3 >> 8),*(undefined1 *)(param_2 + 0x45)));
    IofCompleteRequest(param_2,2);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== WanDeleteUserModeInterface @ 14001329c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WanDeleteUserModeInterface(longlong param_1,uint param_2,undefined8 param_3,byte param_4)

{
  longlong lVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  longlong lVar5;
  undefined1 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  LOCK();
  _DAT_14000a7f0 = _DAT_14000a7f0 + 1;
  UNLOCK();
  *(undefined8 *)(param_1 + 0x38) = 0;
  piVar3 = *(int **)(param_1 + 0x18);
  if (param_2 < 4) {
    LOCK();
    _DAT_14000a7f4 = _DAT_14000a7f4 + 1;
    UNLOCK();
    return 0xc0000023;
  }
  WanpAcquireResource(&g_wrBindMutex);
  uVar6 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  plVar7 = WanpFindDialInAdapterGivenInterfaceIndex(*piVar3,(uint)param_4);
  if (plVar7 != (longlong *)0x0) {
    plVar11 = plVar7 + 0xf;
    KeAcquireSpinLockAtDpcLevel(plVar11);
    if (param_4 == 0) {
      lVar12 = plVar7[0x16];
    }
    else {
      lVar12 = plVar7[0x15];
    }
    if (lVar12 != 0) {
      lVar1 = lVar12 + 0x38;
      KeAcquireSpinLockAtDpcLevel(lVar1);
      puVar10 = auStack_48;
      if (*(int *)(lVar12 + 0x20) == *piVar3) {
        if (((*(char *)((longlong)plVar7 + 0x94) == '\x03') ||
            (*(char *)((longlong)plVar7 + 0x94) == '\x06')) &&
           (lVar5 = plVar7[0x2d], (int)lVar5 != -1)) {
          plVar9 = plVar7;
          if ((int)plVar7[0x17] == 1) {
            *(undefined4 *)(plVar7 + 0x2d) = 0xffffffff;
            *(undefined1 *)((longlong)plVar7 + 0x94) = 0;
            KeReleaseSpinLockFromDpcLevel(lVar1);
            *(int *)(plVar7 + 0x17) = (int)plVar7[0x17] + -1;
            KeReleaseSpinLockFromDpcLevel(plVar11);
            KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
            KeReleaseSpinLock(&g_rwlAdapterLock,uVar6);
            if (param_4 == 0) {
              plVar7[0x16] = 0;
            }
            else {
              plVar7[0x15] = 0;
            }
            NdisIfDeregisterInterface((int)lVar5);
            plVar11 = (longlong *)0xffffffff;
            LOCK();
            plVar9 = plVar7 + 0x10;
            lVar1 = *plVar9;
            *(int *)plVar9 = (int)*plVar9 + -1;
            UNLOCK();
            if ((int)lVar1 == 1) {
              WanpDeleteAdapter((longlong)plVar7);
            }
            LOCK();
            piVar3 = (int *)(lVar12 + 0x40);
            iVar2 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              ExFreePoolWithTag(lVar12,0);
            }
            puVar10 = auStack_48;
            plVar9 = plVar7 + 4;
            lVar1 = *plVar9;
            if ((*(longlong **)(lVar1 + 8) == plVar9) &&
               (plVar7 = (longlong *)plVar7[5], (longlong *)*plVar7 == plVar9)) {
              g_ulNumDialInAdapters = g_ulNumDialInAdapters + -1;
              *plVar7 = lVar1;
              *(longlong **)(lVar1 + 8) = plVar7;
              goto LAB_140013568;
            }
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            puVar10 = auStack_40;
          }
          *(undefined8 *)(puVar10 + -8) = 0x1400134f1;
          KeReleaseSpinLockFromDpcLevel();
          *(int *)(plVar9 + 0x17) = (int)plVar9[0x17] + -1;
          if (param_4 == 0) {
            plVar9[0x16] = 0;
          }
          else {
            plVar9[0x15] = 0;
          }
          *(undefined8 *)(puVar10 + -8) = 0x14001351b;
          KeReleaseSpinLockFromDpcLevel(plVar11);
          *(undefined8 *)(puVar10 + -8) = 0x14001352e;
          KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
          *(undefined8 *)(puVar10 + -8) = 0x140013544;
          KeReleaseSpinLock(&g_rwlAdapterLock,uVar6);
          LOCK();
          piVar3 = (int *)(lVar12 + 0x40);
          iVar2 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            *(undefined8 *)(puVar10 + -8) = 0x140013563;
            ExFreePoolWithTag(lVar12,0);
          }
LAB_140013568:
          *(undefined8 *)(puVar10 + -8) = 0x140013574;
          WanpReleaseResource(&g_wrBindMutex);
          return 0;
        }
        KeReleaseSpinLockFromDpcLevel(lVar1);
        KeReleaseSpinLockFromDpcLevel(plVar11);
        KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
        KeReleaseSpinLock(&g_rwlAdapterLock,uVar6);
        WanpReleaseResource(&g_wrBindMutex);
        uVar13 = 0xc0000184;
        goto LAB_1400135d9;
      }
      KeReleaseSpinLockFromDpcLevel(lVar1);
    }
    KeReleaseSpinLockFromDpcLevel(plVar11);
  }
  KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
  KeReleaseSpinLock(&g_rwlAdapterLock,uVar6);
  uVar8 = WanRemoveRouterInterface(*piVar3);
  uVar13 = uVar8 & 0xffffffff;
  WanpReleaseResource(&g_wrBindMutex);
  if ((int)uVar8 == 0) {
    return uVar13;
  }
LAB_1400135d9:
  LOCK();
  _DAT_14000a7f4 = _DAT_14000a7f4 + 1;
  UNLOCK();
  return uVar13;
}



===== WanFreeLuidIndex @ 140013608 =====

void WanFreeLuidIndex(longlong param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 8) {
    uVar1 = NdisIfFreeNetLuidIndex
                      (**(undefined2 **)(param_1 + 0x18),
                       *(undefined4 *)(*(undefined2 **)(param_1 + 0x18) + 2));
  }
  else {
    uVar1 = 0xc000000d;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}



===== WanIpDummyInterfaceDeleteComplete @ 140013650 =====

void WanIpDummyInterfaceDeleteComplete(void)

{
  return;
}



===== WanMapServerAdapter @ 14001365c =====

ulonglong WanMapServerAdapter(longlong param_1,uint param_2,uint param_3,char param_4)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  bool bVar10;
  
  *(undefined8 *)(param_1 + 0x38) = 0;
  piVar2 = *(int **)(param_1 + 0x18);
  if ((param_3 < 0x14) || (param_2 < 0x14)) {
    return 0xc0000023;
  }
  WanpAcquireResource(&g_wrBindMutex);
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  LOCK();
  iVar3 = DAT_14000ad30 + 1;
  UNLOCK();
  bVar10 = DAT_14000ad30 == 0;
  DAT_14000ad30 = iVar3;
  if (bVar10) {
    KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  }
  KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
  puVar6 = WanpFindDialInAdapterGivenCompartmentId(piVar2[2]);
  if (puVar6 == (undefined8 *)0x0) {
    LOCK();
    UNLOCK();
    if (DAT_14000ad30 == 1) {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeReleaseSpinLock(&DAT_14000ad28,uVar4);
    }
    else {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeLowerIrql(uVar4);
    }
    WanpReleaseResource(&g_wrBindMutex);
    return 0xc000000e;
  }
  if (param_4 == '\0') {
    lVar9 = puVar6[0x16];
  }
  else {
    lVar9 = puVar6[0x15];
  }
  puVar1 = puVar6 + 0xf;
  KeAcquireSpinLockAtDpcLevel(puVar1);
  if (*piVar2 == 0) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar7 = WanpUnmapServerInterface((longlong)puVar6,uVar4,param_4);
    return uVar7;
  }
  if (*(char *)((longlong)puVar6 + 0x94) == '\x06') {
    if (*(char *)(lVar9 + 0x30) == '\x06') {
      piVar2[1] = *(int *)(puVar6 + 0x2d);
      KeReleaseSpinLockFromDpcLevel(puVar1);
      LOCK();
      UNLOCK();
      if (DAT_14000ad30 == 1) {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeReleaseSpinLock(&DAT_14000ad28,uVar4);
      }
      else {
        DAT_14000ad30 = DAT_14000ad30 + -1;
        KeLowerIrql(uVar4);
      }
      goto LAB_140013807;
    }
  }
  else if (*(char *)((longlong)puVar6 + 0x94) != '\x03') {
    KeReleaseSpinLockFromDpcLevel(puVar1);
    LOCK();
    UNLOCK();
    if (DAT_14000ad30 == 1) {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeReleaseSpinLock(&DAT_14000ad28,uVar4);
    }
    else {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeLowerIrql(uVar4);
    }
    uVar5 = 0xc0000184;
    goto LAB_140013b56;
  }
  LOCK();
  *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + 1;
  UNLOCK();
  if (*(char *)((longlong)puVar6 + 0x94) != '\x06') {
    *(undefined1 *)((longlong)puVar6 + 0x94) = 5;
  }
  KeReleaseSpinLockFromDpcLevel(puVar1);
  LOCK();
  UNLOCK();
  if (DAT_14000ad30 == 1) {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeReleaseSpinLock(&DAT_14000ad28,uVar4);
  }
  else {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeLowerIrql(uVar4);
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(puVar1);
  KeAcquireSpinLockAtDpcLevel(lVar9 + 0x38);
  if (param_4 == '\0') {
    *(undefined8 *)(lVar9 + 0xf8) = *(undefined8 *)(piVar2 + 3);
  }
  uVar5 = WanpAddAdapterToIp((longlong)puVar6,lVar9,param_4,uVar4);
  if (uVar5 == 0) {
    puVar8 = WanpCreateConnEntry(3,param_4);
    if (puVar8 == (undefined4 *)0x0) {
      WanpDeleteInterfaceFromIp(lVar9);
      uVar5 = 0xc000009a;
    }
    else {
      *(undefined4 **)(puVar8 + 0x14) = puVar8 + 0x16;
      *(undefined8 *)(puVar8 + 10) = puVar6[0x2c];
      *(undefined4 **)(lVar9 + 0x28) = puVar8;
      puVar8[0x18] = 0;
      uVar5 = WanpIpAddSubInterface((longlong)puVar6,lVar9,(longlong)puVar8,param_4);
      if ((int)uVar5 < 0) {
        FreeConnection((longlong)puVar8);
        WanpDeleteInterfaceFromIp(lVar9);
      }
      else {
        puVar8[0x1f] = 2;
        if (uVar5 == 0) {
          uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
          LOCK();
          iVar3 = DAT_14000ad30 + 1;
          UNLOCK();
          bVar10 = DAT_14000ad30 == 0;
          DAT_14000ad30 = iVar3;
          if (bVar10) {
            KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
          }
          KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
          KeAcquireSpinLockAtDpcLevel(puVar1);
          *(undefined1 *)((longlong)puVar6 + 0x94) = 6;
          LOCK();
          puVar8[0x18] = puVar8[0x18] + 1;
          UNLOCK();
          LOCK();
          *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + 1;
          UNLOCK();
          LOCK();
          *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + 1;
          UNLOCK();
          LOCK();
          *(int *)(lVar9 + 0x40) = *(int *)(lVar9 + 0x40) + 1;
          UNLOCK();
          piVar2[1] = *(int *)(puVar6 + 0x2d);
          KeReleaseSpinLockFromDpcLevel(puVar1);
          LOCK();
          UNLOCK();
          if (DAT_14000ad30 == 1) {
            DAT_14000ad30 = DAT_14000ad30 + -1;
            KeReleaseSpinLock(&DAT_14000ad28,uVar4);
          }
          else {
            DAT_14000ad30 = DAT_14000ad30 + -1;
            KeLowerIrql(uVar4);
          }
          LOCK();
          piVar2 = (int *)(puVar6 + 0x10);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            WanpDeleteAdapter((longlong)puVar6);
          }
LAB_140013807:
          WanpReleaseResource(&g_wrBindMutex);
          *(undefined8 *)(param_1 + 0x38) = 0x14;
          return 0;
        }
      }
    }
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  LOCK();
  iVar3 = DAT_14000ad30 + 1;
  UNLOCK();
  bVar10 = DAT_14000ad30 == 0;
  DAT_14000ad30 = iVar3;
  if (bVar10) {
    KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  }
  KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
  KeAcquireSpinLockAtDpcLevel(puVar1);
  *(undefined1 *)((longlong)puVar6 + 0x94) = 0;
  KeReleaseSpinLockFromDpcLevel(puVar1);
  LOCK();
  UNLOCK();
  if (DAT_14000ad30 == 1) {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeReleaseSpinLock(&DAT_14000ad28,uVar4);
  }
  else {
    DAT_14000ad30 = DAT_14000ad30 + -1;
    KeLowerIrql(uVar4);
  }
  LOCK();
  piVar2 = (int *)(puVar6 + 0x10);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    WanpDeleteAdapter((longlong)puVar6);
  }
LAB_140013b56:
  WanpReleaseResource(&g_wrBindMutex);
  return (ulonglong)uVar5;
}



===== WanProcessConnectionFailure @ 140013b90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
WanProcessConnectionFailure(longlong param_1,uint param_2,undefined8 param_3,byte param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  bool bVar9;
  
  *(undefined8 *)(param_1 + 0x38) = 0;
  if (param_2 < 4) {
    uVar6 = 0xc0000023;
  }
  else {
    iVar2 = **(int **)(param_1 + 0x18);
    uVar5 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
    LOCK();
    iVar4 = DAT_14000ad30 + 1;
    UNLOCK();
    bVar9 = DAT_14000ad30 == 0;
    DAT_14000ad30 = iVar4;
    if (bVar9) {
      KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
    }
    KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
    puVar7 = WanpFindDialInAdapterGivenInterfaceIndex(iVar2,(uint)param_4);
    LOCK();
    UNLOCK();
    if (DAT_14000ad30 == 1) {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeReleaseSpinLock(&DAT_14000ad28,uVar5);
    }
    else {
      DAT_14000ad30 = DAT_14000ad30 + -1;
      KeLowerIrql(uVar5);
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(&g_rwlIfLock);
    LOCK();
    iVar4 = DAT_14000acd0 + 1;
    UNLOCK();
    bVar9 = DAT_14000acd0 == 0;
    DAT_14000acd0 = iVar4;
    if (bVar9) {
      KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
    }
    KeReleaseSpinLockFromDpcLevel(&g_rwlIfLock);
    puVar8 = WanpFindInterfaceGivenIndex(iVar2);
    if (puVar8 == (undefined8 *)0x0) {
      LOCK();
      UNLOCK();
      if (DAT_14000acd0 == 1) {
        DAT_14000acd0 = DAT_14000acd0 + -1;
        KeReleaseSpinLock(&DAT_14000acc8,uVar5);
      }
      else {
        DAT_14000acd0 = DAT_14000acd0 + -1;
        KeLowerIrql(uVar5);
      }
      uVar6 = 0xc0000034;
    }
    else if (puVar7 == (undefined8 *)0x0) {
      LOCK();
      iVar2 = DAT_14000acd0 + -1;
      UNLOCK();
      bVar9 = DAT_14000acd0 == 1;
      DAT_14000acd0 = iVar2;
      if (bVar9) {
        KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
      }
      puVar7 = puVar8 + 7;
      if (*(int *)(puVar8 + 0x12) == 3) {
        lVar3 = puVar8[3];
        KeReleaseSpinLock(puVar7,uVar5);
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x78);
        KeAcquireSpinLockAtDpcLevel(puVar7);
        WanpFlushQueuedNetBufferLists(lVar3,param_4);
        *(undefined4 *)((longlong)puVar8 + 0x8c) = 2;
        *(undefined4 *)(puVar8 + 0x12) = 2;
        *(longlong *)(lVar3 + 200) = _DAT_fffff78000000014 / 100000;
        KeReleaseSpinLockFromDpcLevel(puVar7);
        KeReleaseSpinLock(lVar3 + 0x78,uVar5);
        uVar6 = 0;
      }
      else {
        KeReleaseSpinLock();
        LOCK();
        piVar1 = (int *)(puVar8 + 8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          ExFreePoolWithTag(puVar8,0);
        }
        uVar6 = 0xc0000184;
      }
    }
    else {
      KeReleaseSpinLockFromDpcLevel(puVar8 + 7);
      LOCK();
      piVar1 = (int *)(puVar8 + 8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        ExFreePoolWithTag(puVar8,0);
      }
      LOCK();
      UNLOCK();
      if (DAT_14000acd0 == 1) {
        DAT_14000acd0 = DAT_14000acd0 + -1;
        KeReleaseSpinLock(&DAT_14000acc8,uVar5);
      }
      else {
        DAT_14000acd0 = DAT_14000acd0 + -1;
        KeLowerIrql(uVar5);
      }
      uVar6 = 0xc000000d;
    }
  }
  return uVar6;
}



===== WanProcessNotification @ 140013e94 =====

undefined8 WanProcessNotification(longlong param_1,undefined8 *param_2,uint param_3,char param_4)

{
  byte *pbVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 local_res10 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  local_res10[0] = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  if (((uint)param_2 < 0x620) || (param_3 < 0x620)) {
    return 0xc0000023;
  }
  IoAcquireCancelSpinLock(local_res10);
  puVar8 = auStack_38;
  puVar9 = auStack_38;
  plVar5 = (longlong *)&g_lePendingV4NotificationList;
  plVar4 = g_lePendingV4NotificationList;
  if (param_4 == '\0') {
    plVar5 = (longlong *)&g_lePendingV6NotificationList;
    plVar4 = g_lePendingV6NotificationList;
  }
  if (plVar4 == plVar5) {
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    puVar6 = (undefined8 *)(param_1 + 0xa8);
    if (param_4 != '\0') {
      param_2 = &g_lePendingV4IrpList;
      if ((undefined8 *)*DAT_14000ad68 == &g_lePendingV4IrpList) {
        *puVar6 = &g_lePendingV4IrpList;
        *(undefined8 **)(param_1 + 0xb0) = DAT_14000ad68;
        *DAT_14000ad68 = puVar6;
        DAT_14000ad68 = puVar6;
        goto LAB_140013fd3;
      }
      goto LAB_140013fbb;
    }
    param_2 = &g_lePendingV6IrpList;
    if ((undefined8 *)*DAT_14000ace8 != &g_lePendingV6IrpList) goto LAB_140013fbb;
  }
  else {
    if (((longlong *)plVar4[1] == plVar5) && (lVar2 = *plVar4, *(longlong **)(lVar2 + 8) == plVar4))
    {
      *plVar5 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar5;
      memmove(*(void **)(param_1 + 0x18),plVar4 + 6,0x620);
      LOCK();
      *(undefined8 *)(param_1 + 0x68) = 0;
      UNLOCK();
      *(undefined8 *)(param_1 + 0x38) = 0x620;
      IoReleaseCancelSpinLock(local_res10[0]);
      ExFreeToNPagedLookasideList(&g_llNotificationBlocks,plVar4);
      return 0;
    }
LAB_140013fbb:
    puVar7 = (undefined8 *)0x3;
    pcVar3 = (code *)swi(0x29);
    puVar6 = (undefined8 *)(*pcVar3)();
    puVar8 = auStack_30;
    DAT_14000ace8 = puVar7;
  }
  *puVar6 = param_2;
  puVar6[1] = DAT_14000ace8;
  *DAT_14000ace8 = puVar6;
  puVar9 = puVar8;
  DAT_14000ace8 = puVar6;
LAB_140013fd3:
  LOCK();
  *(code **)(param_1 + 0x68) = WanCancelNotificationIrp;
  UNLOCK();
  *(undefined8 *)(puVar9 + -8) = 0x140013fe9;
  IoReleaseCancelSpinLock(puVar9[0x48]);
  return 0x103;
}



===== WanRecreateInterface @ 140014014 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WanRecreateInterface(longlong param_1,uint param_2,undefined8 param_3,char param_4)

{
  longlong lVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  int iVar8;
  longlong lVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined8 *puVar12;
  bool bVar13;
  bool bVar14;
  code *local_60;
  undefined8 uStack_58;
  code *local_50;
  undefined8 uStack_48;
  
  *(undefined8 *)(param_1 + 0x38) = 0;
  bVar14 = false;
  local_60 = (code *)0x0;
  uStack_58 = 0;
  local_50 = (code *)0x0;
  uStack_48 = 0;
  if (param_2 < 8) {
    iVar8 = -0x3fffffdd;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x18);
    WanpAcquireResource(&g_wrBindMutex);
    uVar7 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
    LOCK();
    iVar8 = DAT_14000ad30 + 1;
    UNLOCK();
    bVar13 = DAT_14000ad30 == 0;
    DAT_14000ad30 = iVar8;
    if (bVar13) {
      KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
    }
    KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
    puVar10 = (undefined8 *)0x0;
    for (puVar12 = g_leMappedAdapterList; (undefined8 **)puVar12 != &g_leMappedAdapterList;
        puVar12 = (undefined8 *)*puVar12) {
      KeAcquireSpinLockAtDpcLevel(puVar12 + 0xf);
      puVar10 = puVar12;
      if (*(int *)(puVar12 + 0x2d) == *piVar3) {
        bVar14 = true;
        break;
      }
      KeReleaseSpinLockFromDpcLevel(puVar12 + 0xf);
    }
    LOCK();
    iVar8 = DAT_14000ad30 + -1;
    UNLOCK();
    if (bVar14) {
      bVar14 = DAT_14000ad30 == 1;
      DAT_14000ad30 = iVar8;
      if (bVar14) {
        KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
      }
      if (param_4 == '\0') {
        lVar11 = puVar10[0x16];
      }
      else {
        lVar11 = puVar10[0x15];
      }
      if (lVar11 == 0) {
        KeReleaseSpinLockFromDpcLevel(puVar10 + 0xf);
        LOCK();
        UNLOCK();
        if (DAT_14000ad30 == 1) {
          DAT_14000ad30 = DAT_14000ad30 + -1;
          KeReleaseSpinLock(&DAT_14000ad28,uVar7);
        }
        else {
          DAT_14000ad30 = DAT_14000ad30 + -1;
          KeLowerIrql(uVar7);
        }
        WanpReleaseResource(&g_wrBindMutex);
        return 0;
      }
      lVar1 = lVar11 + 0x38;
      KeAcquireSpinLockAtDpcLevel(lVar1);
      uVar4 = *(undefined8 *)(lVar11 + 0x58);
      lVar5 = *(longlong *)(lVar11 + 0x28);
      KeReleaseSpinLockFromDpcLevel(lVar1);
      if ((*(int *)(lVar5 + 100) == 1) &&
         ((*(int *)(lVar5 + 0x7c) == 2 || (*(char *)((longlong)puVar10 + 0x94) == '\x06')))) {
        uVar6 = *(undefined8 *)(lVar5 + 0x80);
        *(undefined4 *)(lVar5 + 0x7c) = 5;
        KeReleaseSpinLock(puVar10 + 0xf,uVar7);
        local_60 = WanIpDummyInterfaceDeleteComplete;
        lVar9 = DAT_14000a0d8;
        if (param_4 == '\0') {
          lVar9 = DAT_14000a328;
        }
        uStack_58 = uVar6;
        (**(code **)(*(longlong *)(lVar9 + 8) + 0x28))(&local_60);
        lVar9 = DAT_14000a0d8;
        if (param_4 == '\0') {
          lVar9 = DAT_14000a328;
        }
        local_50 = WanIpDummyInterfaceDeleteComplete;
        uStack_48 = uVar4;
        (**(code **)(*(longlong *)(lVar9 + 8) + 0x10))(&local_50);
        uVar7 = KeAcquireSpinLockRaiseToDpc(puVar10 + 0xf);
        KeAcquireSpinLockAtDpcLevel(lVar1);
        *(int *)(lVar11 + 0xa4) = piVar3[1];
        *(int *)(puVar10 + 0x17) = *(int *)(puVar10 + 0x17) + -1;
        *(undefined8 *)(lVar11 + 0x58) = 0;
        *(undefined8 *)(lVar5 + 0x80) = 0;
        iVar8 = WanpAddAdapterToIp((longlong)puVar10,lVar11,param_4,uVar7);
        if ((-1 < iVar8) &&
           (iVar8 = WanpIpAddSubInterface((longlong)puVar10,lVar11,lVar5,param_4), iVar8 < 0)) {
          WanpDeleteInterfaceFromIp(lVar11);
        }
        uVar7 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar5 + 0x50));
        *(undefined4 *)(lVar5 + 0x7c) = 2;
        KeReleaseSpinLock(*(undefined8 *)(lVar5 + 0x50),uVar7);
        LOCK();
        piVar3 = (int *)(lVar5 + 0x60);
        iVar2 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          WanpDeleteConnEntry(lVar5);
        }
        LOCK();
        piVar3 = (int *)(puVar10 + 0x10);
        iVar2 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          WanpDeleteAdapter((longlong)puVar10);
        }
        LOCK();
        piVar3 = (int *)(lVar11 + 0x40);
        iVar2 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          ExFreePoolWithTag(lVar11,0);
        }
        WanpReleaseResource(&g_wrBindMutex);
        if (-1 < iVar8) {
          return iVar8;
        }
      }
      else {
        KeReleaseSpinLock(puVar10 + 0xf,uVar7);
        WanpReleaseResource(&g_wrBindMutex);
        iVar8 = -0x3ffffff3;
      }
    }
    else {
      if (DAT_14000ad30 == 1) {
        DAT_14000ad30 = iVar8;
        KeReleaseSpinLock(&DAT_14000ad28,uVar7);
      }
      else {
        DAT_14000ad30 = iVar8;
        KeLowerIrql(uVar7);
      }
      WanpReleaseResource(&g_wrBindMutex);
      iVar8 = -0x3ffffddb;
    }
  }
  *(int *)(param_1 + 0x30) = iVar8;
  return iVar8;
}



===== WanSetInterfaceSubnetInfo @ 140014420 =====

int WanSetInterfaceSubnetInfo(uint *param_1,uint param_2,undefined8 param_3,char param_4)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  ulonglong uVar13;
  uint *puVar14;
  ulonglong uVar15;
  undefined8 *puVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  uint local_res18 [2];
  char local_res20;
  
  uVar18 = 0;
  local_res18[0] = 0;
  local_res20 = param_4;
  WanpAcquireResource((int *)&WfpMutex);
  if (0xb < param_2) {
    uVar13 = ((-(ulonglong)(param_1[2] != 0) & 0xfffffffffffffff7) + 0x11) * (ulonglong)*param_1;
    if ((0xffffffff < uVar13) || (uVar12 = (int)uVar13 + 0xc, uVar12 < 0xc)) {
      iVar7 = -0x3fffff6b;
      goto LAB_1400148cf;
    }
    if (uVar12 <= param_2) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(&g_rwlIfLock);
      LOCK();
      iVar7 = DAT_14000acd0 + 1;
      UNLOCK();
      bVar19 = DAT_14000acd0 == 0;
      DAT_14000acd0 = iVar7;
      if (bVar19) {
        KeAcquireSpinLockAtDpcLevel(&DAT_14000acc8);
      }
      KeReleaseSpinLockFromDpcLevel(&g_rwlIfLock);
      puVar8 = WanpFindInterfaceGivenIndex(param_1[1]);
      LOCK();
      iVar7 = DAT_14000acd0 + -1;
      UNLOCK();
      if (puVar8 == (undefined8 *)0x0) {
        if (DAT_14000acd0 == 1) {
          DAT_14000acd0 = iVar7;
          KeReleaseSpinLock(&DAT_14000acc8,uVar6);
        }
        else {
          DAT_14000acd0 = iVar7;
          KeLowerIrql(uVar6);
        }
        iVar7 = -0x3fffffcc;
        goto LAB_1400148cf;
      }
      bVar19 = DAT_14000acd0 == 1;
      DAT_14000acd0 = iVar7;
      if (bVar19) {
        KeReleaseSpinLockFromDpcLevel(&DAT_14000acc8);
      }
      iVar7 = *(int *)(puVar8 + 0x12);
      puVar1 = puVar8 + 7;
      puVar10 = (uint *)puVar8[0x13];
      local_res20 = iVar7 != 4;
      if (puVar10 == (uint *)0x0) {
        KeReleaseSpinLock(puVar1,uVar6);
      }
      else {
        uVar12 = *(uint *)(puVar8 + 0x14);
        uVar17 = *puVar10;
        puVar8[0x13] = 0;
        *(undefined4 *)(puVar8 + 0x14) = 0;
        local_res18[0] = uVar12;
        KeReleaseSpinLock();
        if (iVar7 != 4) {
          WanpRemoveSubnetFilters(puVar10,uVar12);
          while (uVar17 != 0) {
            uVar17 = uVar17 - 1;
            LOCK();
            piVar2 = (int *)(puVar8 + 8);
            iVar7 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if (iVar7 == 1) {
              ExFreePoolWithTag(puVar8,0);
            }
          }
        }
        ExFreePoolWithTag(puVar10,0);
      }
      iVar7 = 0;
      if (*param_1 != 0) {
        uVar9 = ComputeSizeOfSubnetFilterInfoRequired
                          ((ulonglong)*param_1,(uint)*(byte *)((longlong)puVar8 + 0x14),local_res18)
        ;
        uVar12 = local_res18[0];
        iVar7 = (int)uVar9;
        if (iVar7 < 0) {
          LOCK();
          piVar2 = (int *)(puVar8 + 8);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          bVar19 = iVar3 == 1;
          goto LAB_14001462b;
        }
        puVar10 = (uint *)ExAllocatePool2(0x40,local_res18[0],0x70667757);
        cVar5 = local_res20;
        if (puVar10 != (uint *)0x0) {
          *puVar10 = *param_1;
          uVar17 = 0;
          puVar10[1] = (uint)*(byte *)((longlong)puVar8 + 0x14);
          cVar4 = *(char *)((longlong)puVar8 + 0x14);
          puVar11 = puVar10 + 2;
          if (cVar4 != '\0') {
            puVar11 = (uint *)0x0;
          }
          puVar14 = param_1 + 3;
          if (cVar4 != '\0') {
            puVar14 = (uint *)0x0;
          }
          uVar13 = -(ulonglong)(cVar4 != '\0') & (ulonglong)(param_1 + 3);
          if (cVar4 == '\0') {
            if (*param_1 != 0) {
              do {
                puVar16 = (undefined8 *)((longlong)puVar14 + (ulonglong)uVar17 * 0x11);
                iVar7 = WanpAddIpv6DemandDialFilter
                                  (puVar16,*(undefined1 *)(puVar16 + 2),(longlong)puVar8,
                                   puVar11 + (ulonglong)uVar17 * 0x32,local_res20);
                if (iVar7 < 0) goto LAB_140014838;
                LOCK();
                *(int *)(puVar8 + 8) = *(int *)(puVar8 + 8) + 1;
                UNLOCK();
                uVar17 = uVar17 + 1;
              } while (uVar17 < *param_1);
              goto LAB_140014751;
            }
          }
          else if (*param_1 != 0) {
            do {
              uVar15 = (ulonglong)uVar17;
              iVar7 = WanpAddIpv4DemandDialFilter
                                (*(undefined4 *)(uVar13 + uVar15 * 8),
                                 *(undefined4 *)(uVar13 + 4 + uVar15 * 8),(longlong)puVar8,
                                 (undefined8 *)
                                 (uVar15 * 0xb8 +
                                 (-(ulonglong)(cVar4 != '\0') & (ulonglong)(puVar10 + 2))),cVar5);
              if (iVar7 < 0) goto LAB_140014838;
              LOCK();
              *(int *)(puVar8 + 8) = *(int *)(puVar8 + 8) + 1;
              UNLOCK();
              uVar17 = uVar17 + 1;
            } while (uVar17 < *param_1);
LAB_140014751:
            uVar12 = local_res18[0];
          }
          uVar6 = KeAcquireSpinLockRaiseToDpc(puVar1);
          if (puVar8[0x13] == 0) {
            puVar8[0x13] = puVar10;
            *(uint *)(puVar8 + 0x14) = uVar12;
          }
          else {
            KeReleaseSpinLock(puVar1,uVar6);
            WanpRemoveSubnetFilters(puVar10,uVar12);
            uVar6 = KeAcquireSpinLockRaiseToDpc(puVar1);
            if (*puVar10 != 0) {
              do {
                LOCK();
                piVar2 = (int *)(puVar8 + 8);
                iVar3 = *piVar2;
                *piVar2 = *piVar2 + -1;
                UNLOCK();
                if (iVar3 == 1) {
                  ExFreePoolWithTag(puVar8,0);
                }
                uVar18 = uVar18 + 1;
              } while (uVar18 < *puVar10);
            }
            ExFreePoolWithTag(puVar10,0);
          }
          KeReleaseSpinLock(puVar1,uVar6);
          goto LAB_1400148ba;
        }
        iVar7 = -0x3fffff66;
      }
      LOCK();
      piVar2 = (int *)(puVar8 + 8);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      bVar19 = iVar3 == 1;
      goto LAB_14001462b;
    }
  }
  iVar7 = -0x3ffffff3;
  goto LAB_1400148cf;
LAB_140014838:
  *puVar10 = uVar17;
  ComputeSizeOfSubnetFilterInfoRequired
            ((ulonglong)uVar17,(uint)*(byte *)((longlong)puVar8 + 0x14),local_res18);
  WanpRemoveSubnetFilters(puVar10,local_res18[0]);
  if (uVar17 != 0) {
    uVar13 = (ulonglong)uVar17;
    do {
      LOCK();
      piVar2 = (int *)(puVar8 + 8);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        ExFreePoolWithTag(puVar8,0);
      }
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  ExFreePoolWithTag(puVar10,0);
LAB_1400148ba:
  LOCK();
  piVar2 = (int *)(puVar8 + 8);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  bVar19 = iVar3 == 1;
LAB_14001462b:
  if (bVar19) {
    ExFreePoolWithTag(puVar8,0);
  }
LAB_1400148cf:
  WanpReleaseResource((int *)&WfpMutex);
  return iVar7;
}



===== WanSetIpAddresses @ 1400148fc =====

undefined4 WanSetIpAddresses(longlong param_1,uint param_2,undefined8 param_3,char param_4)

{
  int *_Src;
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined1 uVar4;
  longlong lVar5;
  int *piVar6;
  uint *_Dst;
  undefined8 *puVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  bool bVar11;
  bool bVar12;
  
  *(undefined8 *)(param_1 + 0x38) = 0;
  bVar12 = false;
  if (param_2 < 0x108) {
    uVar8 = 0xc0000023;
    goto LAB_140014bc5;
  }
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1[1] == 0) {
    return 0;
  }
  if ((uint)piVar1[1] < 0x11) {
    WanpAcquireResource(&g_wrBindMutex);
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
    LOCK();
    iVar3 = DAT_14000ad30 + 1;
    UNLOCK();
    bVar11 = DAT_14000ad30 == 0;
    DAT_14000ad30 = iVar3;
    if (bVar11) {
      KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
    }
    KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
    puVar10 = (undefined8 *)0x0;
    for (puVar7 = g_leMappedAdapterList; (undefined8 **)puVar7 != &g_leMappedAdapterList;
        puVar7 = (undefined8 *)*puVar7) {
      KeAcquireSpinLockAtDpcLevel(puVar7 + 0xf);
      puVar10 = puVar7;
      if (*(int *)(puVar7 + 0x2d) == *piVar1) {
        if (param_4 == '\0') {
          lVar5 = puVar7[0x16];
        }
        else {
          lVar5 = puVar7[0x15];
        }
        if (lVar5 != 0) {
          bVar12 = true;
          break;
        }
      }
      KeReleaseSpinLockFromDpcLevel(puVar7 + 0xf);
    }
    LOCK();
    iVar3 = DAT_14000ad30 + -1;
    UNLOCK();
    if (!bVar12) {
      if (DAT_14000ad30 == 1) {
        DAT_14000ad30 = iVar3;
        KeReleaseSpinLock(&DAT_14000ad28,uVar4);
      }
      else {
        DAT_14000ad30 = iVar3;
        KeLowerIrql(uVar4);
      }
      WanpReleaseResource(&g_wrBindMutex);
      uVar8 = 0xc0000225;
      goto LAB_140014bc5;
    }
    bVar12 = DAT_14000ad30 == 1;
    DAT_14000ad30 = iVar3;
    if (bVar12) {
      KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
    }
    if (param_4 == '\0') {
      lVar5 = puVar10[0x16];
    }
    else {
      lVar5 = puVar10[0x15];
    }
    KeAcquireSpinLockAtDpcLevel(lVar5 + 0x38);
    lVar2 = *(longlong *)(lVar5 + 0x28);
    KeReleaseSpinLockFromDpcLevel(lVar5 + 0x38);
    if ((*(int *)(lVar2 + 100) == 1) && (*(int *)(lVar2 + 0x7c) == 2)) {
      piVar6 = (int *)ExAllocatePool2(0x40,0x104,0x64646157);
      if (piVar6 != (int *)0x0) {
        if (*(longlong *)(lVar2 + 0x38) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar2 + 0x38),0);
        }
        *(int **)(lVar2 + 0x38) = piVar6;
        _Src = piVar1 + 2;
        *piVar6 = piVar1[1];
        uVar9 = (ulonglong)**(uint **)(lVar2 + 0x38);
        _Dst = *(uint **)(lVar2 + 0x38) + 1;
        if (param_4 == '\0') {
          memmove(_Dst,_Src,uVar9 << 4);
          *(undefined8 *)(lVar2 + 0x30) = *(undefined8 *)(piVar1 + 4);
        }
        else {
          memmove(_Dst,_Src,uVar9 << 2);
          *(int *)(lVar2 + 0x18) = *_Src;
        }
        KeReleaseSpinLock(puVar10 + 0xf,uVar4);
        WanpReleaseResource(&g_wrBindMutex);
        return 0;
      }
      KeReleaseSpinLock(puVar10 + 0xf,uVar4);
      WanpReleaseResource(&g_wrBindMutex);
      uVar8 = 0xc000009a;
      goto LAB_140014bc5;
    }
    KeReleaseSpinLock(puVar10 + 0xf,uVar4);
    WanpReleaseResource(&g_wrBindMutex);
  }
  uVar8 = 0xc000000d;
LAB_140014bc5:
  *(undefined4 *)(param_1 + 0x30) = uVar8;
  return uVar8;
}



===== WanStartStopQueuing @ 140014bf0 =====

undefined8 WanStartStopQueuing(longlong param_1,uint param_2,uint param_3,char param_4)

{
  int *piVar1;
  int *piVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  bool bVar17;
  undefined1 local_res10 [8];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  *(undefined8 *)(param_1 + 0x38) = 0;
  piVar2 = *(int **)(param_1 + 0x18);
  local_res10[0] = 0;
  if (param_2 < 8) {
    return 0xc0000023;
  }
  IoAcquireCancelSpinLock(local_res10);
  puVar13 = auStack_48;
  plVar10 = &g_lePendingV4NotificationList;
  if (param_4 == '\0') {
    plVar10 = &g_lePendingV6NotificationList;
  }
  if (*piVar2 == 0) {
    g_bQueueNotifications = 0;
    while (plVar3 = (longlong *)*plVar10, plVar3 != plVar10) {
      if (((longlong *)plVar3[1] != plVar10) ||
         (lVar9 = *plVar3, *(longlong **)(lVar9 + 8) != plVar3)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar13 = auStack_40;
        break;
      }
      *plVar10 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar10;
      ExFreeToNPagedLookasideList(&g_llNotificationBlocks);
    }
    *(undefined8 *)(puVar13 + -8) = 0x140014cae;
    IoReleaseCancelSpinLock(puVar13[0x58]);
    *(undefined8 *)(puVar13 + -8) = 0x140014cbb;
    WanpClearPendingIrps(param_4);
LAB_140014e6a:
    uVar11 = 0;
  }
  else {
    if (param_3 < 8) {
      uVar11 = 0xc0000023;
    }
    else {
      KeAcquireSpinLockAtDpcLevel(&g_rwlAdapterLock);
      LOCK();
      iVar6 = DAT_14000ad30 + 1;
      UNLOCK();
      bVar17 = DAT_14000ad30 == 0;
      DAT_14000ad30 = iVar6;
      if (bVar17) {
        KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
      }
      KeReleaseSpinLockFromDpcLevel(&g_rwlAdapterLock);
      uVar14 = g_ulNumDialOutInterfaces * 0x20 + 8;
      piVar2[1] = g_ulNumDialOutInterfaces;
      if (uVar14 <= param_3) {
        uVar15 = 0;
        puVar12 = g_leMappedAdapterList;
        if ((undefined8 **)g_leMappedAdapterList != &g_leMappedAdapterList) {
          do {
            KeAcquireSpinLockAtDpcLevel(puVar12 + 0xf);
            if (param_4 == '\0') {
              lVar9 = puVar12[0x16];
            }
            else {
              lVar9 = puVar12[0x15];
            }
            uVar16 = uVar15;
            if (((lVar9 != 0) && (lVar4 = *(longlong *)(lVar9 + 0x28), lVar4 != 0)) &&
               (*(int *)(lVar4 + 100) == 1)) {
              iVar6 = *(int *)(lVar9 + 0x48);
              iVar7 = *(int *)(lVar9 + 0x4c);
              iVar8 = *(int *)(lVar9 + 0x50);
              uVar16 = (ulonglong)((int)uVar15 + 1);
              piVar1 = piVar2 + uVar15 * 8 + 2;
              *piVar1 = *(int *)(lVar9 + 0x44);
              piVar1[1] = iVar6;
              piVar1[2] = iVar7;
              piVar1[3] = iVar8;
              piVar2[uVar15 * 8 + 6] = *(int *)(puVar12 + 0x2d);
              piVar2[uVar15 * 8 + 7] = *(int *)(lVar4 + 0x18);
              piVar2[uVar15 * 8 + 8] = *(int *)(lVar4 + 0x1c);
              piVar2[uVar15 * 8 + 9] = *(int *)(lVar4 + 0x20);
            }
            KeReleaseSpinLockFromDpcLevel(puVar12 + 0xf);
            puVar12 = (undefined8 *)*puVar12;
            uVar15 = uVar16;
          } while ((undefined8 **)puVar12 != &g_leMappedAdapterList);
        }
        g_bQueueNotifications = 1;
        LOCK();
        iVar6 = DAT_14000ad30 + -1;
        UNLOCK();
        bVar17 = DAT_14000ad30 == 1;
        DAT_14000ad30 = iVar6;
        if (bVar17) {
          KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
        }
        IoReleaseCancelSpinLock(local_res10[0]);
        *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar14;
        goto LAB_140014e6a;
      }
      *(undefined8 *)(param_1 + 0x38) = 8;
      LOCK();
      iVar6 = DAT_14000ad30 + -1;
      UNLOCK();
      bVar17 = DAT_14000ad30 == 1;
      DAT_14000ad30 = iVar6;
      if (bVar17) {
        KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
      }
      uVar11 = 0x105;
    }
    IoReleaseCancelSpinLock(local_res10[0]);
  }
  return uVar11;
}



===== WanpCompleteIrp @ 140014e90 =====

void WanpCompleteIrp(undefined8 *param_1)

{
  char cVar1;
  undefined1 uVar2;
  longlong lVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  bool bVar10;
  undefined1 local_res8 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  cVar1 = *(char *)((longlong)param_1 + 0x3c);
  local_res8[0] = 0;
  IoAcquireCancelSpinLock(local_res8);
  puVar9 = auStack_28;
  bVar10 = cVar1 == '\0';
  plVar8 = (longlong *)&g_lePendingV4IrpList;
  plVar5 = g_lePendingV4IrpList;
  if (bVar10) {
    plVar8 = (longlong *)&g_lePendingV6IrpList;
    plVar5 = g_lePendingV6IrpList;
  }
  puVar6 = &g_lePendingV4NotificationList;
  if (bVar10) {
    puVar6 = &g_lePendingV6NotificationList;
  }
  if (g_bQueueNotifications == '\0') {
    IoReleaseCancelSpinLock(local_res8[0]);
LAB_140014f6e:
    ExFreeToNPagedLookasideList(&g_llNotificationBlocks,param_1);
  }
  else {
    if (plVar5 == plVar8) {
      puVar7 = (undefined8 *)puVar6[1];
      if ((undefined8 *)*puVar7 != puVar6) goto LAB_140014f8f;
    }
    else {
      if (((longlong *)plVar5[1] == plVar8) &&
         (lVar3 = *plVar5, *(longlong **)(lVar3 + 8) == plVar5)) {
        *plVar8 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar8;
        memmove((void *)plVar5[-0x12],param_1 + 6,0x620);
        LOCK();
        plVar5[-8] = 0;
        UNLOCK();
        *(undefined4 *)(plVar5 + -0xf) = 0;
        plVar5[-0xe] = 0x620;
        IoReleaseCancelSpinLock(local_res8[0]);
        IofCompleteRequest(plVar5 + -0x15,2);
        goto LAB_140014f6e;
      }
LAB_140014f8f:
      puVar7 = (undefined8 *)0x3;
      pcVar4 = (code *)swi(0x29);
      puVar6 = (undefined8 *)(*pcVar4)();
      puVar9 = auStack_20;
    }
    param_1[1] = puVar7;
    *param_1 = puVar6;
    *puVar7 = param_1;
    uVar2 = puVar9[0x30];
    puVar6[1] = param_1;
    *(undefined8 *)(puVar9 + -8) = 0x140014faf;
    IoReleaseCancelSpinLock(uVar2);
  }
  return;
}



===== WanpDeleteInterface @ 140014fc8 =====

void WanpDeleteInterface(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WanpDeleteRouterInterface @ 140014fe8 =====

undefined8 WanpDeleteRouterInterface(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  longlong *plVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 uVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  plVar5 = *(longlong **)(param_1 + 0x18);
  lVar1 = param_1 + 0x38;
  KeReleaseSpinLock(lVar1);
  cVar4 = *(char *)(param_1 + 0x14);
  uVar8 = KeAcquireSpinLockRaiseToDpc(plVar5 + 0xf);
  KeAcquireSpinLockAtDpcLevel(lVar1);
  WanpFlushQueuedNetBufferLists((longlong)plVar5,cVar4);
  LOCK();
  plVar10 = plVar5 + 0x10;
  lVar7 = *plVar10;
  *(int *)plVar10 = (int)*plVar10 + -1;
  UNLOCK();
  if ((int)lVar7 == 1) {
    WanpDeleteAdapter((longlong)plVar5);
  }
  KeReleaseSpinLockFromDpcLevel(lVar1);
  if (cVar4 == '\0') {
    plVar5[0x16] = 0;
  }
  else {
    plVar5[0x15] = 0;
  }
  LOCK();
  piVar2 = (int *)(param_1 + 0x40);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    ExFreePoolWithTag(param_1,0);
  }
  puVar9 = auStack_48;
  plVar10 = plVar5 + 0x16;
  if (cVar4 == '\0') {
    plVar10 = plVar5 + 0x15;
  }
  if (*plVar10 == 0) {
    *(undefined1 *)((longlong)plVar5 + 0x94) = 4;
    KeReleaseSpinLock(plVar5 + 0xf,uVar8);
    uVar8 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
    KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
    lVar1 = *plVar5;
    if ((*(longlong **)(lVar1 + 8) == plVar5) &&
       (plVar10 = (longlong *)plVar5[1], (longlong *)*plVar10 == plVar5)) {
      *plVar10 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar10;
      KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
      KeReleaseSpinLock(&g_rwlAdapterLock,uVar8);
      LOCK();
      plVar10 = plVar5 + 0x10;
      lVar1 = *plVar10;
      *(int *)plVar10 = (int)*plVar10 + -1;
      UNLOCK();
      if ((int)lVar1 == 1) {
        WanpDeleteAdapter((longlong)plVar5);
      }
      LOCK();
      plVar10 = plVar5 + 0x10;
      lVar1 = *plVar10;
      *(int *)plVar10 = (int)*plVar10 + -1;
      UNLOCK();
      if ((int)lVar1 == 1) {
        WanpDeleteAdapter((longlong)plVar5);
      }
      LOCK();
      plVar10 = plVar5 + 0x10;
      lVar1 = *plVar10;
      *(int *)plVar10 = (int)*plVar10 + -1;
      UNLOCK();
      if ((int)lVar1 == 1) {
        WanpDeleteAdapter((longlong)plVar5);
        return 0;
      }
      return 0;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar9 = auStack_40;
  }
  *(undefined8 *)(puVar9 + -8) = 0x1400151a9;
  KeReleaseSpinLock();
  return 0;
}



===== WanIpCancelSendPackets @ 1400151e0 =====

void WanIpCancelSendPackets(longlong *param_1)

{
  char cVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = *param_1;
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar3 + 0x50));
  cVar1 = *(char *)(lVar3 + 4);
  KeReleaseSpinLock(*(undefined8 *)(lVar3 + 0x50),uVar2);
  lVar3 = DAT_14000aa68;
  if (cVar1 == '\0') {
    lVar3 = DAT_14000ab88;
  }
  if (lVar3 != 0) {
    NdisCancelSendNetBufferLists(lVar3,param_1[1]);
  }
  return;
}



===== WanpFlushQueuedNetBufferLists @ 14001525c =====

undefined8 WanpFlushQueuedNetBufferLists(longlong param_1,char param_2)

{
  longlong *plVar1;
  undefined7 in_register_00000011;
  longlong lVar2;
  undefined8 *puVar3;
  
  if (param_2 == '\0') {
    lVar2 = *(longlong *)(param_1 + 0xb0);
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0xa8);
  }
  plVar1 = (longlong *)(lVar2 + 0x78);
  puVar3 = (undefined8 *)*plVar1;
  while (puVar3 != (undefined8 *)0x0) {
    NdisFreeNetBufferListContext(puVar3,8);
    in_register_00000011 = 0;
    NetioAdvanceNetBufferList(puVar3,0xe);
    puVar3 = (undefined8 *)*puVar3;
    *(int *)(lVar2 + 0x88) = *(int *)(lVar2 + 0x88) + -1;
  }
  if (*plVar1 != 0) {
    NetioDereferenceNetBufferListChain(*plVar1,CONCAT71(in_register_00000011,1));
    *plVar1 = 0;
    *(longlong **)(lVar2 + 0x80) = plVar1;
  }
  return 0;
}



===== WanpHandleDemandDialCallOutRequest @ 1400152f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WanpHandleDemandDialCallOutRequest(longlong param_1,longlong param_2)

{
  void *_Dst;
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  void *_Src;
  longlong lVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined1 local_78 [24];
  undefined1 local_60 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar2 = *(longlong *)(param_1 + 8);
  lVar9 = *(longlong *)(param_2 + 0x18);
  cVar1 = *(char *)(param_2 + 0x14);
  lVar10 = 0;
  NetioAdvanceNetBuffer(lVar2,0xe);
  local_88 = 0;
  puVar12 = local_60;
  if (cVar1 != '\0') {
    puVar12 = local_78;
  }
  lVar7 = NdisGetDataBuffer(lVar2,(-(uint)(cVar1 != '\0') & 0xffffffec) + 0x28,puVar12,1);
  if (*(char *)(param_2 + 0x14) != '\0') {
    lVar10 = lVar7;
    lVar7 = 0;
  }
  lVar8 = ExAllocateFromNPagedLookasideList(&g_llNotificationBlocks);
  if (lVar8 == 0) {
    NetioRetreatNetBuffer(lVar2);
    return 0xc000009a;
  }
  *(undefined4 *)(lVar8 + 0x30) = 0;
  *(undefined4 *)(lVar8 + 0x34) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(lVar8 + 0x38) = *(undefined4 *)(lVar9 + 0x168);
  if (*(char *)(param_2 + 0x14) == '\0') {
    if (lVar7 == 0) goto LAB_1400154a3;
    uVar3 = *(undefined4 *)(lVar7 + 0xc);
    uVar4 = *(undefined4 *)(lVar7 + 0x10);
    uVar5 = *(undefined4 *)(lVar7 + 0x14);
    *(undefined4 *)(lVar8 + 0x40) = *(undefined4 *)(lVar7 + 8);
    *(undefined4 *)(lVar8 + 0x44) = uVar3;
    *(undefined4 *)(lVar8 + 0x48) = uVar4;
    *(undefined4 *)(lVar8 + 0x4c) = uVar5;
    uVar6 = *(undefined8 *)(lVar7 + 0x20);
    *(undefined8 *)(lVar8 + 0x50) = *(undefined8 *)(lVar7 + 0x18);
    *(undefined8 *)(lVar8 + 0x58) = uVar6;
    *(uint *)(lVar8 + 0x60) = (uint)*(ushort *)(lVar7 + 4);
    *(undefined1 *)(lVar8 + 100) = *(undefined1 *)(lVar7 + 6);
    *(undefined1 *)(lVar8 + 0x65) = *(undefined1 *)(lVar7 + 7);
    lVar9 = 0x66;
  }
  else {
    if (lVar10 == 0) goto LAB_1400154a3;
    *(undefined4 *)(lVar8 + 0x40) = *(undefined4 *)(lVar10 + 0xc);
    *(undefined4 *)(lVar8 + 0x44) = *(undefined4 *)(lVar10 + 0x10);
    *(uint *)(lVar8 + 0x48) = (uint)*(ushort *)(lVar10 + 2);
    *(undefined1 *)(lVar8 + 0x4c) = *(undefined1 *)(lVar10 + 9);
    lVar9 = 0x4d;
  }
  _Dst = (void *)(lVar8 + lVar9);
  if (_Dst != (void *)0x0) {
    uVar11 = *(uint *)(lVar2 + 0x18);
    if (uVar11 != 0) {
      local_88 = 0;
      if (0x5e9 < uVar11) {
        uVar11 = 0x5ea;
      }
      _Src = (void *)NdisGetDataBuffer(lVar2,uVar11,_Dst,1);
      if ((_Src != (void *)0x0) && (_Src != _Dst)) {
        memmove(_Dst,_Src,(ulonglong)uVar11);
      }
    }
    NetioRetreatNetBuffer(lVar2);
    *(longlong *)(lVar8 + 0x28) = lVar8;
    *(code **)(lVar8 + 0x20) = WanpCompleteIrp;
    *(undefined8 *)(lVar8 + 0x10) = 0;
    ExQueueWorkItem((undefined8 *)(lVar8 + 0x10),1);
    return 0;
  }
LAB_1400154a3:
  NetioRetreatNetBuffer(lVar2);
  ExFreeToNPagedLookasideList(&g_llNotificationBlocks,lVar8);
  return 0xc000000d;
}



===== WanpTransmitQueuedPackets @ 1400154f8 =====

void WanpTransmitQueuedPackets(longlong param_1,undefined1 param_2,char param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined7 in_register_00000011;
  longlong lVar5;
  
  if (param_3 == '\0') {
    lVar5 = *(longlong *)(param_1 + 0xb0);
  }
  else {
    lVar5 = *(longlong *)(param_1 + 0xa8);
  }
  lVar2 = *(longlong *)(lVar5 + 0x28);
  if (*(int *)(lVar5 + 0x88) == 0) {
    KeReleaseSpinLockFromDpcLevel();
    KeReleaseSpinLock(param_1 + 0x78,CONCAT71(in_register_00000011,param_2));
  }
  else {
    *(undefined4 *)(lVar5 + 0x88) = 0;
    puVar1 = (undefined8 *)(lVar5 + 0x78);
    puVar3 = (undefined8 *)*puVar1;
    *puVar1 = 0;
    *(undefined8 **)(lVar5 + 0x80) = puVar1;
    KeReleaseSpinLockFromDpcLevel(lVar5 + 0x38);
    for (puVar1 = puVar3; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
      *(longlong *)((ulonglong)*(ushort *)(puVar1[2] + 10) + 0x10 + puVar1[2]) = lVar2;
      LOCK();
      *(int *)(lVar2 + 0x60) = *(int *)(lVar2 + 0x60) + 1;
      UNLOCK();
      WanpPreparePacketsForSend((longlong)puVar1,lVar2);
    }
    KeReleaseSpinLock(param_1 + 0x78,param_2);
    uVar4 = DAT_14000aa68;
    if (param_3 == '\0') {
      uVar4 = DAT_14000ab88;
    }
    NdisSendNetBufferLists(uVar4,puVar3,0,0);
  }
  return;
}



===== ComputeSizeOfSubnetFilterInfoRequired @ 140015610 =====

undefined8 ComputeSizeOfSubnetFilterInfoRequired(ulonglong param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = ((-(ulonglong)(param_2 != 0) & 0xfffffffffffffff0) + 200) * (param_1 & 0xffffffff);
  if ((uVar3 < 0x100000000) && (uVar1 = (uint)uVar3, uVar2 = uVar1 + 8, uVar1 <= uVar2)) {
    *param_3 = uVar2;
    return 0;
  }
  return 0xc0000095;
}



===== WanIpv4ClassifyDemandDialCallOut @ 140015650 =====

void WanIpv4ClassifyDemandDialCallOut
               (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
               longlong param_5,undefined8 param_6,undefined4 *param_7)

{
  WanpQueueNetBufferLists(*(longlong *)(param_5 + 0x30),param_3);
  *(undefined8 *)(param_7 + 2) = 0;
  param_7[6] = param_7[6] & 0xfffffffe;
  *param_7 = 0x1001;
  return;
}



===== WanIpv4NotifyDemandDialCallOut @ 140015690 =====

undefined8 WanIpv4NotifyDemandDialCallOut(void)

{
  return 0;
}



===== WanpAddIpv4DemandDialFilter @ 14001569c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WanpAddIpv4DemandDialFilter
              (undefined4 param_1,undefined4 param_2,longlong param_3,undefined8 *param_4,
              char param_5)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_178 [32];
  undefined4 local_158 [4];
  undefined1 local_148 [16];
  wchar_t *local_138;
  undefined4 local_128;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_e8;
  undefined *local_e0;
  undefined4 local_d8;
  undefined8 *local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  longlong local_b0;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_178;
  memset(local_148,0,200);
  local_48 = 0;
  local_158[0] = *(undefined4 *)(param_3 + 0xa4);
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = 0;
  uStack_70 = 0;
  iVar3 = FllwanpGetCompartmentInformation
                    (0,(longlong)local_158,(longlong)&local_68,(longlong)&local_78);
  if (-1 < iVar3) {
    uVar2 = (undefined4)uStack_60;
    puVar1 = param_4 + 0x16;
    *(undefined4 *)puVar1 = param_1;
    *(undefined4 *)((longlong)param_4 + 0xb4) = param_2;
    *(undefined4 *)(param_4 + 2) = 0;
    *(undefined4 *)(param_4 + 3) = 0x100;
    param_4[4] = puVar1;
    *(undefined4 *)(param_4 + 7) = 0;
    *(undefined4 *)(param_4 + 8) = 3;
    *(undefined4 *)(param_4 + 9) = (undefined4)uStack_60;
    *param_4 = 0x49b81d64b235ae9a;
    param_4[1] = 0x455009d9f35f4ca4;
    param_4[5] = 0x434ad695667fd755;
    param_4[6] = 0xbc59125a83d3f58a;
    if (param_5 != '\0') {
      local_138 = L"RRAS WANARP";
      local_128 = 0;
      local_108 = 0x41358a841e5c9fae;
      uStack_100 = 0xcd9e22540b9531a3;
      local_e0 = &DAT_14000a568;
      local_e8 = 4;
      local_d8 = 2;
      local_c4 = 0x488b9ee9;
      uStack_c0 = 0x4c33be17;
      uStack_bc = 0x77840aac;
      uStack_b8 = 0xd19d7058;
      local_c8 = 0x5003;
      local_d0 = param_4;
      local_b0 = param_3;
      iVar3 = FwpmFilterAdd0(DAT_14000a9d8,local_148,0,param_4 + 10);
      if (iVar3 < 0) goto LAB_1400158d0;
    }
    *(undefined4 *)(param_4 + 0xd) = 0;
    local_d0 = param_4 + 0xb;
    *(undefined4 *)(param_4 + 0xe) = 0x100;
    param_4[0xf] = puVar1;
    *(undefined4 *)(param_4 + 0x12) = 0;
    *(undefined4 *)(param_4 + 0x13) = 3;
    *(undefined4 *)(param_4 + 0x14) = uVar2;
    *local_d0 = 0x45c6b3902d79133b;
    param_4[0xc] = 0x33edafeaacac9986;
    param_4[0x10] = 0x45ee413935cf6522;
    param_4[0x11] = 0x79d84909b867d5a0;
    if (param_5 == '\0') {
      return iVar3;
    }
    local_138 = L"RRAS WANARP";
    local_128 = 0;
    local_108 = 0x4ee14ee1a82acc24;
    uStack_100 = 0xa410cb251dfd65b4;
    local_e0 = &DAT_14000a568;
    local_e8 = 4;
    local_d8 = 2;
    local_c4 = 0x29a05d7d;
    uStack_c0 = 0x408cbddf;
    uStack_bc = 0xce0ea3b8;
    uStack_b8 = 0x1bc4ce0a;
    local_c8 = 0x5003;
    local_b0 = param_3;
    iVar3 = FwpmFilterAdd0(DAT_14000a9d8,local_148,0,param_4 + 0x15);
    if (-1 < iVar3) {
      return iVar3;
    }
    FwpmFilterDeleteById0(DAT_14000a9d8,param_4[10]);
  }
LAB_1400158d0:
  param_4[0x15] = 0;
  param_4[10] = 0;
  return iVar3;
}



===== WanpAddIpv6DemandDialFilter @ 14001590c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WanpAddIpv6DemandDialFilter
              (undefined8 *param_1,undefined1 param_2,longlong param_3,undefined4 *param_4,
              char param_5)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_178 [32];
  undefined4 local_158 [4];
  undefined1 local_148 [16];
  wchar_t *local_138;
  undefined4 local_128;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_e8;
  undefined *local_e0;
  undefined4 local_d8;
  undefined8 *local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  longlong local_b0;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_178;
  memset(local_148,0,200);
  local_48 = 0;
  local_158[0] = *(undefined4 *)(param_3 + 0xa4);
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = 0;
  uStack_70 = 0;
  iVar5 = FllwanpGetCompartmentInformation
                    (0,(longlong)local_158,(longlong)&local_68,(longlong)&local_78);
  if (-1 < iVar5) {
    uVar2 = *param_1;
    uVar3 = param_1[1];
    puVar1 = (undefined8 *)(param_4 + 0x2c);
    uVar4 = (undefined4)uStack_60;
    *(undefined1 *)(param_4 + 0x30) = param_2;
    *puVar1 = uVar2;
    *(undefined8 *)(param_4 + 0x2e) = uVar3;
    param_4[4] = 0;
    param_4[6] = 0x101;
    *(undefined8 **)(param_4 + 8) = puVar1;
    param_4[0xe] = 0;
    param_4[0x10] = 3;
    param_4[0x12] = (undefined4)uStack_60;
    *param_4 = 0xb235ae9a;
    param_4[1] = 0x49b81d64;
    param_4[2] = 0xf35f4ca4;
    param_4[3] = 0x455009d9;
    *(undefined8 *)(param_4 + 10) = 0x434ad695667fd755;
    *(undefined8 *)(param_4 + 0xc) = 0xbc59125a83d3f58a;
    if (param_5 != '\0') {
      local_138 = L"RRAS WANARP";
      local_128 = 0;
      local_108 = 0x488c3564a3b3ab6b;
      uStack_100 = 0x632714824ef31791;
      local_e0 = &DAT_14000a568;
      local_e8 = 4;
      local_d8 = 2;
      local_c4 = 0x41689847;
      uStack_c0 = 0x4b06a3e5;
      uStack_bc = 0x2faa65b3;
      uStack_b8 = 0xa4e44595;
      local_c8 = 0x5003;
      local_d0 = (undefined8 *)param_4;
      local_b0 = param_3;
      iVar5 = FwpmFilterAdd0(DAT_14000a9d8,local_148,0,param_4 + 0x14);
      if (iVar5 < 0) goto LAB_140015b49;
    }
    param_4[0x1a] = 0;
    local_d0 = (undefined8 *)(param_4 + 0x16);
    param_4[0x1c] = 0x101;
    *(undefined8 **)(param_4 + 0x1e) = puVar1;
    param_4[0x24] = 0;
    param_4[0x26] = 3;
    param_4[0x28] = uVar4;
    *local_d0 = 0x45c6b3902d79133b;
    *(undefined8 *)(param_4 + 0x18) = 0x33edafeaacac9986;
    *(undefined8 *)(param_4 + 0x20) = 0x45ee413935cf6522;
    *(undefined8 *)(param_4 + 0x22) = 0x79d84909b867d5a0;
    if (param_5 == '\0') {
      return iVar5;
    }
    local_138 = L"RRAS WANARP";
    local_128 = 0;
    local_108 = 0x493a19c77b964818;
    uStack_100 = 0x8cd284362c831fb7;
    local_e0 = &DAT_14000a568;
    local_e8 = 4;
    local_d8 = 2;
    local_c4 = 0xa9b59c23;
    uStack_c0 = 0x45538519;
    uStack_bc = 0xdef4bc92;
    uStack_b8 = 0x5fe0c1b9;
    local_c8 = 0x5003;
    local_b0 = param_3;
    iVar5 = FwpmFilterAdd0(DAT_14000a9d8,local_148,0,param_4 + 0x2a);
    if (-1 < iVar5) {
      return iVar5;
    }
    FwpmFilterDeleteById0(DAT_14000a9d8,*(undefined8 *)(param_4 + 0x14));
  }
LAB_140015b49:
  *(undefined8 *)(param_4 + 0x2a) = 0;
  *(undefined8 *)(param_4 + 0x14) = 0;
  return iVar5;
}



===== WanpAddSubnetFilters @ 140015b84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WanpAddSubnetFilters(uint *param_1,uint param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint *puVar5;
  uint *puVar6;
  ulonglong uVar7;
  undefined1 auStack_138 [32];
  uint local_118 [2];
  undefined8 local_110;
  undefined1 local_108 [16];
  wchar_t *local_f8;
  undefined4 local_e8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_a8;
  undefined *local_a0;
  undefined4 local_98;
  uint *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined8 local_70;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_138;
  local_118[0] = 0;
  local_110 = param_3;
  memset(local_108,0,200);
  uVar2 = param_1[1];
  uVar1 = *param_1;
  uVar3 = ComputeSizeOfSubnetFilterInfoRequired((ulonglong)uVar1,uVar2,local_118);
  uVar7 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    if (param_2 == local_118[0]) {
      puVar6 = param_1 + 2;
      if (uVar2 != 0) {
        puVar6 = (uint *)0x0;
      }
      uVar3 = 0;
      local_118[0] = 0;
      if (uVar2 == 0) {
        if (uVar1 != 0) {
          do {
            local_e8 = 0;
            local_c8 = 0x488c3564a3b3ab6b;
            uStack_c0 = 0x632714824ef31791;
            puVar5 = puVar6 + uVar3 * 0x32;
            local_f8 = L"RRAS WANARP";
            local_a8 = 4;
            local_a0 = &DAT_14000a568;
            local_98 = 2;
            local_88 = 0x5003;
            local_84 = 0x41689847;
            uStack_80 = 0x4b06a3e5;
            uStack_7c = 0x2faa65b3;
            uStack_78 = 0xa4e44595;
            local_70 = local_110;
            local_90 = puVar5;
            FwpmFilterAdd0(DAT_14000a9d8,local_108,0,puVar5 + 0x14);
            local_90 = puVar5 + 0x16;
            local_e8 = 0;
            local_c8 = 0x493a19c77b964818;
            uStack_c0 = 0x8cd284362c831fb7;
            local_f8 = L"RRAS WANARP";
            local_84 = 0xa9b59c23;
            uStack_80 = 0x45538519;
            uStack_7c = 0xdef4bc92;
            uStack_78 = 0x5fe0c1b9;
            local_a8 = 4;
            local_a0 = &DAT_14000a568;
            local_98 = 2;
            local_88 = 0x5003;
            local_70 = local_110;
            uVar2 = FwpmFilterAdd0(DAT_14000a9d8,local_108,0,puVar5 + 0x2a);
            uVar7 = (ulonglong)uVar2;
            local_118[0] = local_118[0] + 1;
            uVar3 = (ulonglong)local_118[0];
          } while (local_118[0] < *param_1);
        }
      }
      else if (uVar1 != 0) {
        do {
          local_e8 = 0;
          local_c8 = 0x41358a841e5c9fae;
          uStack_c0 = 0xcd9e22540b9531a3;
          lVar4 = uVar3 * 0xb8 + (-(ulonglong)(uVar2 != 0) & (ulonglong)(param_1 + 2));
          local_f8 = L"RRAS WANARP";
          local_98 = 2;
          local_a8 = 4;
          local_a0 = &DAT_14000a568;
          local_88 = 0x5003;
          local_84 = 0x488b9ee9;
          uStack_80 = 0x4c33be17;
          uStack_7c = 0x77840aac;
          uStack_78 = 0xd19d7058;
          local_70 = local_110;
          local_90 = (uint *)lVar4;
          FwpmFilterAdd0(DAT_14000a9d8,local_108,0,lVar4 + 0x50);
          local_90 = (uint *)(lVar4 + 0x58);
          local_e8 = 0;
          local_c8 = 0x4ee14ee1a82acc24;
          uStack_c0 = 0xa410cb251dfd65b4;
          local_f8 = L"RRAS WANARP";
          local_84 = 0x29a05d7d;
          uStack_80 = 0x408cbddf;
          uStack_7c = 0xce0ea3b8;
          uStack_78 = 0x1bc4ce0a;
          local_a8 = 4;
          local_a0 = &DAT_14000a568;
          local_98 = 2;
          local_88 = 0x5003;
          local_70 = local_110;
          uVar1 = FwpmFilterAdd0(DAT_14000a9d8,local_108,0,lVar4 + 0xa8);
          uVar7 = (ulonglong)uVar1;
          local_118[0] = local_118[0] + 1;
          uVar3 = (ulonglong)local_118[0];
        } while (local_118[0] < *param_1);
      }
    }
    else {
      uVar7 = 0xc000000d;
    }
  }
  return uVar7;
}



===== WanpRemoveSubnetFilters @ 140015e78 =====

ulonglong WanpRemoveSubnetFilters(uint *param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  uint local_res8 [2];
  
  uVar1 = param_1[1];
  uVar7 = *param_1;
  local_res8[0] = 0;
  uVar2 = ComputeSizeOfSubnetFilterInfoRequired((ulonglong)uVar7,uVar1,local_res8);
  uVar6 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    if (param_2 == local_res8[0]) {
      puVar4 = param_1 + 2;
      if (uVar1 != 0) {
        puVar4 = (uint *)0x0;
      }
      uVar3 = 0;
      uVar2 = -(ulonglong)(uVar1 != 0) & (ulonglong)(param_1 + 2);
      if (uVar1 == 0) {
        if (uVar7 != 0) {
          do {
            uVar2 = (ulonglong)uVar3;
            if (*(longlong *)(puVar4 + uVar2 * 0x32 + 0x14) != 0) {
              uVar1 = FwpmFilterDeleteById0(DAT_14000a9d8);
              uVar6 = (ulonglong)uVar1;
              (puVar4 + uVar2 * 0x32 + 0x14)[0] = 0;
              (puVar4 + uVar2 * 0x32 + 0x14)[1] = 0;
            }
            if (*(longlong *)(puVar4 + uVar2 * 0x32 + 0x2a) != 0) {
              uVar1 = FwpmFilterDeleteById0(DAT_14000a9d8);
              uVar6 = (ulonglong)uVar1;
              (puVar4 + uVar2 * 0x32 + 0x2a)[0] = 0;
              (puVar4 + uVar2 * 0x32 + 0x2a)[1] = 0;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *param_1);
        }
      }
      else if (uVar7 != 0) {
        do {
          lVar5 = (ulonglong)uVar3 * 0xb8;
          if (*(longlong *)(lVar5 + 0x50 + uVar2) != 0) {
            uVar1 = FwpmFilterDeleteById0(DAT_14000a9d8);
            uVar6 = (ulonglong)uVar1;
            *(undefined8 *)(lVar5 + 0x50 + uVar2) = 0;
          }
          if (*(longlong *)(lVar5 + 0xa8 + uVar2) != 0) {
            uVar1 = FwpmFilterDeleteById0(DAT_14000a9d8);
            uVar6 = (ulonglong)uVar1;
            *(undefined8 *)(lVar5 + 0xa8 + uVar2) = 0;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < *param_1);
      }
    }
    else {
      uVar6 = 0xc000000d;
    }
  }
  return uVar6;
}



===== WanpRemoveWfpCallOuts @ 140015fd4 =====

undefined8 WanpRemoveWfpCallOuts(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (DAT_14000a9d8 != 0) {
    FwpiCalloutUnregisterAndDeleteByKey0(DAT_14000a9d8,&DAT_140008738);
    FwpiCalloutUnregisterAndDeleteByKey0(DAT_14000a9d8,&DAT_140008758);
    FwpiCalloutUnregisterAndDeleteByKey0(DAT_14000a9d8,&DAT_140008728);
    FwpiCalloutUnregisterAndDeleteByKey0(DAT_14000a9d8,&DAT_140008748);
    uVar1 = FwpmEngineClose0(DAT_14000a9d8);
    if (-1 < (int)uVar1) {
      DAT_14000a9d8 = 0;
    }
  }
  return uVar1;
}



===== WanpSetupWfpCallOuts @ 140016078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WanpSetupWfpCallOuts(void)

{
  int iVar1;
  undefined1 auStack_d8 [32];
  undefined8 *local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  wchar_t *local_68;
  wchar_t *local_60;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  iVar1 = 0;
  if (DAT_14000a9d8 == 0) {
    local_94 = 0;
    local_80 = 0;
    memset(&local_78,0,0x58);
    local_b8 = &DAT_14000a9d8;
    iVar1 = FwpmEngineOpen0(0,10,0,0);
    if (-1 < iVar1) {
      local_b8 = (undefined8 *)0x0;
      local_a8 = 0x4c33be17488b9ee9;
      uStack_a0 = 0xd19d705877840aac;
      local_78 = 0x4c33be17488b9ee9;
      uStack_70 = 0xd19d705877840aac;
      local_90 = WanIpv4ClassifyDemandDialCallOut;
      local_88 = WanIpv4NotifyDemandDialCallOut;
      local_98 = 0x20;
      local_38 = 0x1e5c9fae;
      uStack_34 = 0x41358a84;
      uStack_30 = 0xb9531a3;
      uStack_2c = 0xcd9e2254;
      local_68 = L"WANARP Ipv4 Send Callout";
      local_60 = L"WANARP Callout for Demand Dial";
      iVar1 = FwpiCalloutRegisterAndAddWithoutDevice0(DAT_14000a9d8,&local_a8,&local_78,0);
      if (-1 < iVar1) {
        local_b8 = (undefined8 *)0x0;
        local_a8 = 0x408cbddf29a05d7d;
        uStack_a0 = 0x1bc4ce0ace0ea3b8;
        local_78 = 0x408cbddf29a05d7d;
        uStack_70 = 0x1bc4ce0ace0ea3b8;
        local_90 = WanIpv4ClassifyDemandDialCallOut;
        local_88 = WanIpv4NotifyDemandDialCallOut;
        local_98 = 0x20;
        local_38 = 0xa82acc24;
        uStack_34 = 0x4ee14ee1;
        uStack_30 = 0x1dfd65b4;
        uStack_2c = 0xa410cb25;
        local_68 = L"WANARP Ipv4 Forward Callout";
        local_60 = L"WANARP Callout for Demand Dial";
        iVar1 = FwpiCalloutRegisterAndAddWithoutDevice0(DAT_14000a9d8,&local_a8,&local_78,0);
        if (-1 < iVar1) {
          local_b8 = (undefined8 *)0x0;
          local_a8 = 0x4b06a3e541689847;
          uStack_a0 = 0xa4e445952faa65b3;
          local_78 = 0x4b06a3e541689847;
          uStack_70 = 0xa4e445952faa65b3;
          local_90 = WanIpv4ClassifyDemandDialCallOut;
          local_88 = WanIpv4NotifyDemandDialCallOut;
          local_98 = 0x20;
          local_38 = 0xa3b3ab6b;
          uStack_34 = 0x488c3564;
          uStack_30 = 0x4ef31791;
          uStack_2c = 0x63271482;
          local_68 = L"WANARP Ipv6 Send Callout";
          local_60 = L"WANARP Callout for Demand Dial";
          iVar1 = FwpiCalloutRegisterAndAddWithoutDevice0(DAT_14000a9d8,&local_a8,&local_78,0);
          if (-1 < iVar1) {
            local_b8 = (undefined8 *)0x0;
            local_a8 = 0x45538519a9b59c23;
            uStack_a0 = 0x5fe0c1b9def4bc92;
            local_78 = 0x45538519a9b59c23;
            uStack_70 = 0x5fe0c1b9def4bc92;
            local_90 = WanIpv4ClassifyDemandDialCallOut;
            local_88 = WanIpv4NotifyDemandDialCallOut;
            local_98 = 0x20;
            local_38 = 0x7b964818;
            uStack_34 = 0x493a19c7;
            uStack_30 = 0x2c831fb7;
            uStack_2c = 0x8cd28436;
            local_68 = L"WANARP Ipv6 Forward Callout";
            local_60 = L"WANARP Callout for Demand Dial";
            iVar1 = FwpiCalloutRegisterAndAddWithoutDevice0(DAT_14000a9d8,&local_a8,&local_78,0);
            if (-1 < iVar1) {
              return iVar1;
            }
          }
        }
      }
      WanpRemoveWfpCallOuts();
    }
  }
  return iVar1;
}



===== FlpReturnNetBufferListChain @ 1400162f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FlpReturnNetBufferListChain(longlong *param_1,undefined8 param_2,undefined1 param_3)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong *plVar11;
  uint uVar12;
  int iVar13;
  longlong *plVar14;
  
  if (param_1 != (longlong *)0x0) {
    plVar9 = param_1;
    do {
      LOCK();
      _glFLPReturnedNBLs = _glFLPReturnedNBLs + 1;
      UNLOCK();
      plVar9 = (longlong *)*plVar9;
    } while (plVar9 != (longlong *)0x0);
    uVar12 = 0;
    plVar14 = (longlong *)0x0;
    lVar8 = 0;
    plVar9 = (longlong *)0x0;
    do {
      plVar11 = param_1;
      lVar5 = plVar11[0xb];
      param_1 = (longlong *)*plVar11;
      if (lVar5 != lVar8) {
        if (lVar8 != 0) {
          *plVar9 = 0;
          FlpCompleteNetBufferListChainHelper(plVar9,plVar14,uVar12,param_3);
        }
        uVar12 = 0;
        lVar8 = lVar5;
        plVar14 = plVar11;
      }
      uVar12 = uVar12 + 1;
      plVar9 = plVar11;
    } while (param_1 != (longlong *)0x0);
    if (lVar8 != 0) {
      *plVar11 = 0;
      lVar8 = plVar14[0xb];
      cVar2 = *(char *)(lVar8 + 4);
      plVar9 = plVar14;
      do {
        for (puVar6 = (undefined8 *)plVar9[1]; puVar6 != (undefined8 *)0x0;
            puVar6 = (undefined8 *)*puVar6) {
          iVar13 = *(int *)(puVar6 + 0xb);
          *(undefined4 *)(puVar6 + 0xb) = 0;
          for (iVar13 = ((iVar13 - *(int *)(puVar6 + 10)) - *(int *)((longlong)puVar6 + 0x54)) +
                        *(int *)(puVar6 + 5) + *(int *)(puVar6 + 3); iVar13 != 0;
              iVar13 = iVar13 - iVar4) {
            puVar7 = (undefined8 *)puVar6[4];
            puVar6[4] = *puVar7;
            iVar4 = *(int *)(puVar7 + 5);
            NetioFreeMdl();
          }
          lVar5 = puVar6[4];
          *(undefined4 *)(puVar6 + 3) = *(undefined4 *)((longlong)puVar6 + 0x54);
          uVar3 = *(uint *)(puVar6 + 10);
          *(uint *)(puVar6 + 5) = uVar3;
          puVar6[1] = lVar5;
          *(uint *)(puVar6 + 2) = uVar3;
          if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x28) < uVar3)) {
            NdisAdjustNetBufferCurrentMdl(puVar6);
          }
        }
        plVar9 = (longlong *)*plVar9;
      } while (plVar9 != (longlong *)0x0);
      plVar9 = plVar14;
      do {
        LOCK();
        _glReturnedNbls = _glReturnedNbls + 1;
        UNLOCK();
        plVar9 = (longlong *)*plVar9;
      } while (plVar9 != (longlong *)0x0);
      uVar10 = DAT_14000aa68;
      if (cVar2 == '\0') {
        uVar10 = DAT_14000ab88;
      }
      NdisReturnNetBufferLists(uVar10,plVar14,param_3);
      while (uVar12 != 0) {
        uVar12 = uVar12 - 1;
        LOCK();
        piVar1 = (int *)(lVar8 + 0x60);
        iVar13 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar13 == 1) {
          WanpDeleteConnEntry(lVar8);
        }
      }
    }
  }
  return;
}



===== FlpCompleteNetBufferListChainHelper @ 1400164d0 =====

void FlpCompleteNetBufferListChainHelper
               (undefined8 param_1,longlong *param_2,uint param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  lVar3 = param_2[0xb];
  uVar4 = (ulonglong)param_3;
  FlpCompleteNdisNetBufferListChain(param_2,uVar4,param_4);
  while (param_3 != 0) {
    param_3 = (int)uVar4 - 1;
    uVar4 = (ulonglong)param_3;
    LOCK();
    piVar1 = (int *)(lVar3 + 0x60);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      WanpDeleteConnEntry(lVar3);
    }
  }
  return;
}



===== FlpCompleteNdisNetBufferListChain @ 140016530 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FlpCompleteNdisNetBufferListChain(longlong *param_1,undefined8 param_2,undefined1 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined8 uVar8;
  int iVar9;
  
  cVar1 = *(char *)(param_1[0xb] + 4);
  plVar7 = param_1;
  do {
    for (puVar4 = (undefined8 *)plVar7[1]; puVar4 != (undefined8 *)0x0;
        puVar4 = (undefined8 *)*puVar4) {
      iVar9 = *(int *)(puVar4 + 0xb);
      *(undefined4 *)(puVar4 + 0xb) = 0;
      for (iVar9 = ((*(int *)(puVar4 + 5) - *(int *)((longlong)puVar4 + 0x54)) -
                   *(int *)(puVar4 + 10)) + *(int *)(puVar4 + 3) + iVar9; iVar9 != 0;
          iVar9 = iVar9 - iVar3) {
        puVar6 = (undefined8 *)puVar4[4];
        puVar4[4] = *puVar6;
        iVar3 = *(int *)(puVar6 + 5);
        NetioFreeMdl();
      }
      lVar5 = puVar4[4];
      *(undefined4 *)(puVar4 + 3) = *(undefined4 *)((longlong)puVar4 + 0x54);
      uVar2 = *(uint *)(puVar4 + 10);
      *(uint *)(puVar4 + 5) = uVar2;
      puVar4[1] = lVar5;
      *(uint *)(puVar4 + 2) = uVar2;
      if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x28) < uVar2)) {
        NdisAdjustNetBufferCurrentMdl(puVar4);
      }
    }
    plVar7 = (longlong *)*plVar7;
  } while (plVar7 != (longlong *)0x0);
  plVar7 = param_1;
  do {
    LOCK();
    _glReturnedNbls = _glReturnedNbls + 1;
    UNLOCK();
    plVar7 = (longlong *)*plVar7;
  } while (plVar7 != (longlong *)0x0);
  uVar8 = DAT_14000aa68;
  if (cVar1 == '\0') {
    uVar8 = DAT_14000ab88;
  }
  NdisReturnNetBufferLists(uVar8,param_1,param_3);
  return;
}



===== WanIpSendPackets @ 140016650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WanIpSendPackets(longlong param_1,ulonglong param_2,undefined8 *param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  char cVar4;
  uint *puVar5;
  byte bVar6;
  undefined1 uVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 **ppuVar10;
  longlong lVar11;
  char cVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  uint uVar15;
  ulonglong uVar16;
  char cVar17;
  undefined8 *puVar18;
  ulonglong uVar19;
  undefined8 **ppuVar20;
  undefined8 **ppuVar21;
  longlong lVar22;
  undefined1 auStack_e8 [32];
  undefined8 *local_c8;
  undefined4 local_c0;
  byte local_b8;
  undefined1 local_b7;
  char local_b6;
  uint local_b4;
  short local_b0 [2];
  uint local_ac;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined2 local_7c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  local_b8 = (byte)param_2;
  uVar7 = 0;
  local_a8 = (undefined8 *)0x0;
  cVar17 = '\0';
  lVar22 = 0;
  local_ac = (uint)(local_b8 != 0);
  cVar4 = *(char *)(param_1 + 4);
  cVar12 = DAT_14000aa66;
  if (cVar4 == '\0') {
    cVar12 = DAT_14000ab86;
  }
  ppuVar20 = &local_a8;
  if (cVar12 == '\0') {
LAB_1400169a8:
    uVar19 = 0x10003;
    iVar8 = 0x10003;
    for (; param_3 != (undefined8 *)0x0; param_3 = (undefined8 *)*param_3) {
LAB_140016c9c:
      iVar8 = (int)uVar19;
      ppuVar21 = (undefined8 **)param_3[1];
      *ppuVar20 = ppuVar21;
      ppuVar20 = ppuVar21;
    }
LAB_1400169b6:
    *ppuVar20 = (undefined8 *)0x0;
    puVar14 = local_a8;
    if (cVar17 == '\0') goto joined_r0x0001400169d2;
  }
  else {
    uVar7 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_1 + 0x50));
    local_b7 = uVar7;
    if ((*(int *)(param_1 + 100) == 3) || (*(int *)(param_1 + 0x7c) != 2)) {
      KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),uVar7);
      param_2 = (ulonglong)local_b8;
      goto LAB_1400169a8;
    }
    lVar22 = *(longlong *)(param_1 + 0x10);
    if (*(int *)(param_1 + 100) != 0) {
      KeAcquireSpinLockAtDpcLevel(lVar22 + 0x38);
    }
    local_b6 = '\x01';
    LOCK();
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
    UNLOCK();
    uVar16 = 0;
    while( true ) {
      bVar6 = local_b8;
      local_b4 = (uint)uVar16;
      if (param_3 == (undefined8 *)0x0) {
        if (*(int *)(param_1 + 100) != 0) {
          KeReleaseSpinLockFromDpcLevel(lVar22 + 0x38);
        }
        KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),local_b7);
        LOCK();
        piVar1 = (int *)(param_1 + 0x60);
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          WanpDeleteConnEntry(param_1);
        }
        *ppuVar20 = (undefined8 *)0x0;
        puVar14 = DAT_14000aa68;
        if (cVar4 == '\0') {
          puVar14 = DAT_14000ab88;
        }
        NdisSendNetBufferLists(puVar14,local_a8,0,local_ac);
        return;
      }
      ppuVar21 = (undefined8 **)param_3[1];
      ppuVar10 = ppuVar21;
      if (((ulonglong)ppuVar21[0x11] & 0x20000000) != 0) break;
LAB_140016735:
      if (*(int *)(param_1 + 100) != 1) goto LAB_14001677e;
      local_b0[0] = 0;
      local_a0 = 0;
      uStack_98 = 0;
      uVar9 = GetPacketIPInfo((longlong)ppuVar10[1],local_b0,&local_a0);
      uVar19 = uVar9 & 0xffffffff;
      if ((int)uVar9 != 0) {
        if ((int)uVar16 != 0) {
          do {
            LOCK();
            piVar1 = (int *)(param_1 + 0x60);
            iVar8 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar8 == 1) {
              WanpDeleteConnEntry(param_1);
            }
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
        }
        LOCK();
        piVar1 = (int *)(param_1 + 0x60);
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          WanpDeleteConnEntry(param_1);
        }
        goto LAB_140016c8d;
      }
      if (local_b0[0] == 2) {
        if (*(uint *)(param_1 + 0x18) != (uint)local_a0) {
          puVar5 = *(uint **)(param_1 + 0x38);
          if (puVar5 != (uint *)0x0) {
            for (uVar15 = 1; uVar15 < *puVar5; uVar15 = uVar15 + 1) {
              if (puVar5[(ulonglong)uVar15 + 1] == (uint)local_a0) goto LAB_14001677e;
            }
          }
LAB_140016af8:
          if (g_bDisableSpoofingProtection == 0) {
            LOCK();
            *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
            UNLOCK();
            if ((int)uVar16 != 0) {
              do {
                LOCK();
                piVar1 = (int *)(param_1 + 0x60);
                iVar8 = *piVar1;
                *piVar1 = *piVar1 + -1;
                UNLOCK();
                if (iVar8 == 1) {
                  WanpDeleteConnEntry(param_1);
                }
                uVar16 = uVar16 - 1;
              } while (uVar16 != 0);
            }
            LOCK();
            piVar1 = (int *)(param_1 + 0x60);
            iVar8 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar8 == 1) {
              WanpDeleteConnEntry(param_1);
            }
            uVar19 = 0;
LAB_140016c8d:
            param_2 = (ulonglong)local_b8;
            uVar7 = local_b7;
            cVar17 = local_b6;
            goto LAB_140016c9c;
          }
        }
      }
      else {
        lVar11 = RtlCompareMemory(param_1 + 0x30,&uStack_98);
        if (lVar11 != 8) {
          if (*(longlong *)(param_1 + 0x38) != 0) {
            for (uVar15 = 1; uVar15 < **(uint **)(param_1 + 0x38); uVar15 = uVar15 + 1) {
              lVar11 = RtlCompareMemory(*(uint **)(param_1 + 0x38) + (ulonglong)uVar15 * 4 + 1,
                                        &local_a0);
              if (lVar11 == 0x10) {
                uVar16 = (ulonglong)local_b4;
                goto LAB_14001677e;
              }
            }
            uVar16 = (ulonglong)local_b4;
          }
          goto LAB_140016af8;
        }
      }
LAB_14001677e:
      iVar8 = NdisAllocateNetBufferListContext(ppuVar10,8);
      if (iVar8 < 0) goto LAB_140016b87;
      *(longlong *)
       ((ulonglong)*(ushort *)((longlong)ppuVar10[2] + 10) + 0x10 + (longlong)ppuVar10[2]) = param_1
      ;
      iVar8 = NetioRetreatNetBufferList(ppuVar10,0xe);
      if (iVar8 < 0) goto LAB_140016b87;
      puVar14 = ppuVar10[1];
      puVar18 = (undefined8 *)0x0;
      local_90 = 0;
      for (; puVar14 != (undefined8 *)0x0; puVar14 = (undefined8 *)*puVar14) {
        LOCK();
        plVar2 = (longlong *)(*(longlong *)(param_1 + 8) + 0x118);
        *plVar2 = *plVar2 + 1;
        UNLOCK();
        lVar11 = puVar14[1];
        if ((uint)(*(int *)(lVar11 + 0x28) - *(int *)(puVar14 + 2)) < 0xe) {
LAB_140016947:
          local_80 = *(undefined4 *)(param_1 + 0x74);
          local_88 = *(undefined8 *)(param_1 + 0x6c);
          local_7c = *(undefined2 *)(param_1 + 0x78);
          local_c8 = &local_90;
          RtlCopyBufferToMdl(&local_88);
        }
        else {
          if ((*(byte *)(lVar11 + 10) & 5) == 0) {
            local_c0 = 0x40000000;
            local_c8 = (undefined8 *)((ulonglong)local_c8 & 0xffffffff00000000);
            lVar11 = MmMapLockedPagesSpecifyCache(lVar11,0);
          }
          else {
            lVar11 = *(longlong *)(lVar11 + 0x18);
          }
          puVar13 = (undefined8 *)((ulonglong)*(uint *)(puVar14 + 2) + lVar11);
          if ((((ulonglong)puVar13 & 1) != 0) || (puVar13 == (undefined8 *)0x0)) goto LAB_140016947;
          if (puVar18 == (undefined8 *)0x0) {
            *puVar13 = *(undefined8 *)(param_1 + 0x6c);
            *(undefined4 *)(puVar13 + 1) = *(undefined4 *)(param_1 + 0x74);
            *(undefined2 *)((longlong)puVar13 + 0xc) = *(undefined2 *)(param_1 + 0x78);
            puVar18 = puVar13;
          }
          else {
            *puVar13 = *puVar18;
            *(undefined4 *)(puVar13 + 1) = *(undefined4 *)(puVar18 + 1);
            *(undefined2 *)((longlong)puVar13 + 0xc) = *(undefined2 *)((longlong)puVar18 + 0xc);
          }
        }
      }
      puVar14 = DAT_14000aa68;
      if (cVar4 == '\0') {
        puVar14 = DAT_14000ab88;
      }
      ppuVar10[0xf] = puVar14;
      *ppuVar20 = ppuVar10;
      LOCK();
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
      UNLOCK();
      param_3 = (undefined8 *)*param_3;
      uVar16 = (ulonglong)(local_b4 + 1);
      ppuVar20 = ppuVar10;
    }
    ppuVar10 = (undefined8 **)NetioAllocateAndReferenceCloneNetBufferList(ppuVar21,local_b8);
    if (ppuVar10 != (undefined8 **)0x0) {
      ppuVar10[0x1a] = (undefined8 *)(ulonglong)*(uint *)(ppuVar21 + 0x1a);
      ppuVar10[0x12] = ppuVar21[0x12];
      NetioDereferenceNetBufferList(ppuVar21,bVar6);
      param_3[1] = ppuVar10;
      uVar16 = (ulonglong)local_b4;
      goto LAB_140016735;
    }
    uVar16 = (ulonglong)local_b4;
    iVar8 = -0x3fffff66;
LAB_140016b87:
    uVar7 = local_b7;
    cVar17 = local_b6;
    puVar14 = local_a8;
    if ((int)uVar16 != 0) {
      do {
        LOCK();
        piVar1 = (int *)(param_1 + 0x60);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          WanpDeleteConnEntry(param_1);
        }
        uVar16 = uVar16 - 1;
        uVar7 = local_b7;
        cVar17 = local_b6;
        puVar14 = local_a8;
      } while (uVar16 != 0);
    }
    while (ppuVar21 = ppuVar20, local_b7 = uVar7, local_b6 = cVar17, puVar14 != (undefined8 *)0x0) {
      puVar18 = (undefined8 *)*puVar14;
      NdisFreeNetBufferListContext(puVar14,8);
      NetioAdvanceNetBufferList(puVar14,0xe);
      uVar7 = local_b7;
      cVar17 = local_b6;
      puVar14 = puVar18;
    }
    do {
      ppuVar20 = (undefined8 **)param_3[1];
      *ppuVar21 = ppuVar20;
      LOCK();
      plVar2 = (longlong *)(*(longlong *)(param_1 + 8) + 0x138);
      *plVar2 = *plVar2 + 1;
      UNLOCK();
      param_3 = (undefined8 *)*param_3;
      ppuVar21 = ppuVar20;
    } while (param_3 != (undefined8 *)0x0);
    LOCK();
    piVar1 = (int *)(param_1 + 0x60);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 != 1) {
      param_2 = (ulonglong)local_b8;
      goto LAB_1400169b6;
    }
    WanpDeleteConnEntry(param_1);
    *ppuVar20 = (undefined8 *)0x0;
    uVar7 = local_b7;
  }
  if (*(int *)(param_1 + 100) != 0) {
    KeReleaseSpinLockFromDpcLevel(lVar22 + 0x38);
  }
  KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),uVar7);
  param_2 = (ulonglong)local_b8;
  puVar14 = local_a8;
joined_r0x0001400169d2:
  for (; puVar14 != (undefined8 *)0x0; puVar14 = (undefined8 *)*puVar14) {
    *(int *)((longlong)puVar14 + 0x8c) = iVar8;
  }
  NetioDereferenceNetBufferListChain(local_a8,param_2);
  return;
}



===== WanpPreparePacketsForSend @ 140016cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WanpPreparePacketsForSend(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined4 local_70;
  undefined8 local_68 [2];
  undefined8 local_58;
  undefined4 local_50;
  undefined2 local_4c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = *(undefined8 **)(param_1 + 8);
  puVar5 = (undefined8 *)0x0;
  local_68[0] = 0;
  do {
    if (puVar2 == (undefined8 *)0x0) {
      return 0;
    }
    LOCK();
    plVar1 = (longlong *)(*(longlong *)(param_2 + 8) + 0x118);
    *plVar1 = *plVar1 + 1;
    UNLOCK();
    lVar3 = puVar2[1];
    if ((uint)(*(int *)(lVar3 + 0x28) - *(int *)(puVar2 + 2)) < 0xe) {
LAB_140016dd6:
      local_50 = *(undefined4 *)(param_2 + 0x74);
      local_58 = *(undefined8 *)(param_2 + 0x6c);
      local_4c = *(undefined2 *)(param_2 + 0x78);
      local_78 = local_68;
      RtlCopyBufferToMdl(&local_58,puVar2[1],*(undefined4 *)(puVar2 + 2));
    }
    else {
      if ((*(byte *)(lVar3 + 10) & 5) == 0) {
        local_70 = 0x40000000;
        local_78 = (undefined8 *)((ulonglong)local_78 & 0xffffffff00000000);
        lVar3 = MmMapLockedPagesSpecifyCache(lVar3,0,1);
      }
      else {
        lVar3 = *(longlong *)(lVar3 + 0x18);
      }
      puVar4 = (undefined8 *)((ulonglong)*(uint *)(puVar2 + 2) + lVar3);
      if ((((ulonglong)puVar4 & 1) != 0) || (puVar4 == (undefined8 *)0x0)) goto LAB_140016dd6;
      if (puVar5 == (undefined8 *)0x0) {
        *puVar4 = *(undefined8 *)(param_2 + 0x6c);
        *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(param_2 + 0x74);
        *(undefined2 *)((longlong)puVar4 + 0xc) = *(undefined2 *)(param_2 + 0x78);
        puVar5 = puVar4;
      }
      else {
        *puVar4 = *puVar5;
        *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(puVar5 + 1);
        *(undefined2 *)((longlong)puVar4 + 0xc) = *(undefined2 *)((longlong)puVar5 + 0xc);
      }
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== GetMTUSize @ 140016e60 =====

undefined4 GetMTUSize(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = IsDialInAdapter(param_1);
  if (((int)uVar1 == 0) && (*(char *)((longlong)param_1 + 0x94) == '\x06')) {
    return *(undefined4 *)(param_1 + 0x28);
  }
  return 0x578;
}



===== GetXmitLinkSpeed @ 140016ea0 =====

undefined8 GetXmitLinkSpeed(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = IsDialInAdapter(param_1);
  if (((int)uVar1 == 0) && (*(char *)((longlong)param_1 + 0x94) == '\x06')) {
    return param_1[0x29];
  }
  return 0x7080;
}



===== GetRcvLinkSpeed @ 140016ee0 =====

undefined8 GetRcvLinkSpeed(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = IsDialInAdapter(param_1);
  if (((int)uVar1 == 0) && (*(char *)((longlong)param_1 + 0x94) == '\x06')) {
    return param_1[0x2a];
  }
  return 0x7080;
}



===== WanpDeleteConnEntryPassive @ 140016f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WanpDeleteConnEntryPassive(longlong param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 uVar7;
  int iVar8;
  longlong lVar9;
  code *local_18;
  longlong local_10;
  
  cVar3 = *(char *)(param_1 + 4);
  uVar7 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_1 + 0x50));
  uVar4 = *(uint *)(param_1 + 0x68);
  *(undefined1 *)(param_1 + 200) = 0;
  if (*(int *)(param_1 + 0x7c) == 0) {
    lVar5 = *(longlong *)(param_1 + 0x80);
    *(undefined4 *)(param_1 + 0x7c) = 4;
    KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x50),uVar7);
    uVar7 = KeAcquireSpinLockRaiseToDpc(&g_rlConnTableLock);
    if (*(longlong *)(g_puipConnTable + (ulonglong)uVar4 * 8) == param_1) {
      *(undefined8 *)(g_puipConnTable + (ulonglong)uVar4 * 8) = 0;
      *(int *)(&g_rgulConns + (longlong)*(int *)(param_1 + 100) * 4) =
           *(int *)(&g_rgulConns + (longlong)*(int *)(param_1 + 100) * 4) + -1;
      if (*(longlong *)(g_puipConnTable + (ulonglong)g_ulNextConnIndex * 8) != 0) {
        g_ulNextConnIndex = uVar4;
      }
    }
    KeReleaseSpinLock(&g_rlConnTableLock,uVar7);
    uVar4 = *(uint *)(param_1 + 100);
    local_18 = WanIpDeleteSubInterfaceComplete;
    LOCK();
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
    UNLOCK();
    bVar6 = uVar4 - 1 < 2;
    if (bVar6) {
      local_18 = WanIpDeleteDialOutSubInterfaceComplete;
      LOCK();
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
      UNLOCK();
    }
    if (lVar5 != 0) {
      lVar9 = DAT_14000a0d8;
      if (cVar3 == '\0') {
        lVar9 = DAT_14000a328;
      }
      local_10 = lVar5;
      iVar8 = (**(code **)(*(longlong *)(lVar9 + 8) + 0x28))(&local_18);
      LOCK();
      *(int *)(&DAT_14000a804 + (ulonglong)uVar4 * 0x10) =
           *(int *)(&DAT_14000a804 + (ulonglong)uVar4 * 0x10) + 1;
      UNLOCK();
      if ((iVar8 != 0x103) && (bVar6)) {
        LOCK();
        piVar1 = (int *)(param_1 + 0x60);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          FreeConnection(param_1);
        }
      }
      if ((uVar4 - 1 < 2) || (iVar8 != 0x103)) {
        WanpIpDeleteSubInterfaceCompleteWorkItem(param_1);
      }
    }
  }
  else {
    KeReleaseSpinLock();
  }
  return;
}



===== WanpIpDeleteSubInterfaceCompleteWorkItem @ 1400170d0 =====

void WanpIpDeleteSubInterfaceCompleteWorkItem(longlong param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 uVar6;
  longlong lVar7;
  
  lVar7 = *(longlong *)(param_1 + 0x10);
  lVar4 = *(longlong *)(param_1 + 8);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x38);
  bVar5 = false;
  if (*(int *)(param_1 + 100) != 0) {
    *(undefined8 *)(lVar7 + 0x28) = 0;
    bVar5 = false;
    if (*(int *)(param_1 + 100) == 3) {
      bVar5 = true;
    }
  }
  KeReleaseSpinLock(lVar7 + 0x38,uVar6);
  if (*(int *)(param_1 + 100) == 2) {
    LOCK();
    piVar1 = (int *)(lVar7 + 0x40);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      ExFreePoolWithTag(lVar7,0);
    }
    LOCK();
    piVar1 = (int *)(lVar4 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      WanpDeleteAdapter(lVar4);
    }
  }
  cVar3 = *(char *)(param_1 + 4);
  *(undefined1 *)(param_1 + 200) = 0;
  if (*(int *)(lVar7 + 0x6c) == 2) {
    WanpDeleteInterfaceFromIp(lVar7);
  }
  else {
    if ((*(int *)(param_1 + 100) == 0) || (*(int *)(param_1 + 100) == 3)) {
      if (bVar5) {
        WanpIpDeleteSpecialSubInterfaceComplete(param_1);
      }
    }
    else {
      WanpUnmapInterface(lVar7);
      LOCK();
      piVar1 = (int *)(lVar4 + 0x80);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        WanpDeleteAdapter(lVar4);
      }
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x78);
      if (cVar3 == '\0') {
        lVar7 = *(longlong *)(lVar4 + 0xa8);
      }
      else {
        lVar7 = *(longlong *)(lVar4 + 0xb0);
      }
      if (lVar7 != 0) {
        KeReleaseSpinLock(lVar4 + 0x78,uVar6);
        goto LAB_140017233;
      }
      KeReleaseSpinLock();
    }
    LOCK();
    piVar1 = (int *)(lVar4 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      WanpDeleteAdapter(lVar4);
    }
  }
LAB_140017233:
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    FreeConnection(param_1);
  }
  return;
}



===== WanNdisCloseAdapterComplete @ 140018010 =====

void WanNdisCloseAdapterComplete(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  
  puVar3 = &DAT_14000aa98;
  uVar4 = DAT_14000aaa0;
  lVar1 = DAT_14000aa90;
  lVar2 = DAT_14000aa98;
  if (param_1 != 0xcabb1e4) {
    puVar3 = &DAT_14000abb8;
    uVar4 = DAT_14000abc0;
    lVar1 = DAT_14000abb0;
    lVar2 = DAT_14000abb8;
  }
  *puVar3 = 0;
  puVar3 = &DAT_14000aa90;
  if (param_1 != 0xcabb1e4) {
    puVar3 = &DAT_14000abb0;
  }
  *puVar3 = 0;
  WanpFreeBindResourcesAndReleaseLock(param_1 == 0xcabb1e4);
  if (lVar1 != 0) {
    NdisCompleteBindAdapterEx(lVar1,uVar4);
  }
  if (lVar2 != 0) {
    NdisCompleteUnbindAdapterEx(lVar2);
  }
  return;
}



===== WanNdisIfSetHandler @ 1400180d0 =====

undefined8 WanNdisIfSetHandler(void)

{
  return 0xc00000bb;
}



===== WanNdisUnbindAdapter @ 1400180e0 =====

undefined8 WanNdisUnbindAdapter(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  WanpAcquireResource(&g_wrBindMutex);
  lVar3 = DAT_14000aa68;
  if (param_2 != 0xcabb1e4) {
    lVar3 = DAT_14000ab88;
  }
  uVar2 = 0;
  if (lVar3 == 0) {
    WanpReleaseResource(&g_wrBindMutex);
  }
  else {
    puVar1 = &DAT_14000aa98;
    if (param_2 != 0xcabb1e4) {
      puVar1 = &DAT_14000abb8;
    }
    *puVar1 = param_1;
    WanpCloseNdisWan(param_2 == 0xcabb1e4);
    uVar2 = 0x103;
  }
  return uVar2;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140018170 =====

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



===== GetRegDWORDValue @ 14001823c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GetRegDWORDValue(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 *local_c0;
  undefined4 local_b8 [2];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_98;
  uint local_90;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  local_b8[0] = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  RtlInitUnicodeString(&local_b0);
  local_98 = 0;
  local_c0 = local_b8;
  local_c8 = 0x80;
  iVar1 = ZwQueryValueKey(param_1,&local_b0,1,&local_98);
  if (-1 < iVar1) {
    if (local_98._4_4_ == 4) {
      *param_3 = *(undefined4 *)((longlong)&local_98 + (ulonglong)local_90);
    }
    else {
      iVar1 = -0x3fffffd0;
    }
  }
  return iVar1;
}



===== OpenRegKey @ 140018300 =====

void OpenRegKey(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_30 = 0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_2;
  ZwOpenKey(0,0x20019,&local_38);
  return;
}



===== WanDispatch @ 140018350 =====

int WanDispatch(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  bool bVar10;
  
  bVar10 = param_1 == DAT_14000aaf8;
  pcVar4 = *(char **)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  cVar5 = *pcVar4;
  if (cVar5 == '\0') {
    if (g_fPagesLocked == '\0') {
      MmLockPagableDataSection(WanpCreateAdapter);
      g_fPagesLocked = '\x01';
    }
    iVar6 = WanpStartModule(bVar10);
    if (iVar6 != 0) {
      if (iVar6 != 0x103) goto LAB_1400184d2;
      puVar9 = &DAT_14000ab08;
      if (!bVar10) {
        puVar9 = &DAT_14000ac28;
      }
      iVar6 = KeWaitForSingleObject(puVar9,0,0,0,0);
    }
    cVar5 = EnterModuleCode(bVar10);
    if (cVar5 == '\0') {
      iVar6 = -0x3fffffff;
      goto LAB_1400184d2;
    }
  }
  else {
    if (cVar5 == '\x02') {
      iVar6 = 0;
      goto LAB_1400184d2;
    }
    if (cVar5 != '\x0e') {
      if (cVar5 == '\x12') {
        iVar6 = 0;
        WanpDriverCleanupNotification(bVar10);
      }
      else {
        iVar6 = -0x3ffffff3;
      }
      goto LAB_1400184d2;
    }
    uVar1 = *(uint *)(pcVar4 + 0x18);
    uVar2 = *(uint *)(pcVar4 + 0x10);
    uVar3 = *(uint *)(pcVar4 + 8);
    cVar5 = EnterModuleCode(bVar10);
    if (cVar5 == '\0') {
      iVar6 = -0x3ffffff2;
      goto LAB_1400184d2;
    }
    if (uVar1 < 0x90018019) {
      if (uVar1 == 0x90018018) {
        uVar8 = WanStartStopQueuing(param_2,uVar2,uVar3,bVar10);
        iVar6 = (int)uVar8;
      }
      else if (uVar1 == 0x90018000) {
        uVar8 = WanProcessNotification(param_2,(undefined8 *)(ulonglong)uVar2,uVar3,bVar10);
        iVar6 = (int)uVar8;
      }
      else if (uVar1 == 0x90018004) {
        uVar7 = WanAddUserModeInterface
                          (param_2,uVar2,uVar3,CONCAT71((int7)((ulonglong)param_4 >> 8),bVar10));
        iVar6 = (int)uVar7;
      }
      else if (uVar1 == 0x90018008) {
        uVar7 = WanDeleteUserModeInterface(param_2,uVar2,param_3,bVar10);
        iVar6 = (int)uVar7;
      }
      else if (uVar1 == 0x9001800c) {
        uVar8 = WanProcessConnectionFailure(param_2,uVar2,param_3,bVar10);
        iVar6 = (int)uVar8;
      }
      else {
        if (uVar1 != 0x90018014) goto LAB_1400184bd;
        uVar7 = WanMapServerAdapter(param_2,uVar2,uVar3,bVar10);
        iVar6 = (int)uVar7;
      }
    }
    else if (uVar1 == 0x9001801c) {
      iVar6 = WanAllocLuidIndex(param_2,uVar2,uVar3);
    }
    else if (uVar1 == 0x90018020) {
      iVar6 = WanFreeLuidIndex(param_2,uVar2);
    }
    else if (uVar1 == 0x90018024) {
      iVar6 = WanRecreateInterface(param_2,uVar2,param_3,bVar10);
    }
    else if (uVar1 == 0x90018028) {
      iVar6 = WanSetInterfaceSubnetInfo(*(uint **)(param_2 + 0x18),uVar2,param_3,(char)param_4);
    }
    else if (uVar1 == 0x9001802c) {
      iVar6 = WanSetIpAddresses(param_2,uVar2,param_3,bVar10);
    }
    else {
LAB_1400184bd:
      iVar6 = -0x3ffffff3;
    }
  }
  ExitModuleCode(bVar10);
  if (iVar6 == 0x103) {
    return 0x103;
  }
LAB_1400184d2:
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,2);
  return iVar6;
}



===== WanUnload @ 1400185f0 =====

void WanUnload(void)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  
  FlNaStop();
  DriverWait();
  WanNmrpDeregisterV4Provider();
  WanNmrpWaitV4Provider();
  WanNmrpDeregisterV6Provider();
  WanNmrpWaitV6Provider();
  KeWaitForSingleObject(&DAT_14000a960,0,0,0,0);
  DAT_14000a958 = 1;
  WanNmrpCleanupProviderState(&WanNmrV4ProviderState);
  WanNmrpCleanupProviderState(&WanNmrV6ProviderState);
  NetioUnInitializeNetBufferListLibrary();
  KeReleaseMutex(&DAT_14000a960,0);
  NetioUnRegisterProcessorAddCallback(&DAT_14000a948);
  WanpAcquireResource(&g_wrBindMutex);
  WanpReleaseResource(&g_wrBindMutex);
  WanpAcquireResource((int *)&WfpMutex);
  WanpRemoveWfpCallOuts();
  WanpReleaseResource((int *)&WfpMutex);
  WaitTillDriverDereferenced();
  DriverCleanup();
  uVar8 = KeAcquireSpinLockRaiseToDpc(&g_rwlAdapterLock);
  KeAcquireSpinLockAtDpcLevel(&DAT_14000ad28);
  plVar3 = g_leDialInAdapterList;
  if ((longlong **)g_leDialInAdapterList != &g_leDialInAdapterList) {
    lVar5 = *g_leDialInAdapterList;
    plVar1 = g_leDialInAdapterList + -4;
    if ((*(longlong **)(lVar5 + 8) != g_leDialInAdapterList) ||
       (plVar6 = (longlong *)g_leDialInAdapterList[1], (longlong *)*plVar6 != g_leDialInAdapterList)
       ) {
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    *plVar6 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar6;
    if (plVar3[0x11] != 0) {
      LOCK();
      piVar2 = (int *)(plVar3[0x11] + 0x40);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        WanpDeleteInterface(plVar3[0x11]);
      }
    }
    if (plVar3[0x12] != 0) {
      LOCK();
      piVar2 = (int *)(plVar3[0x12] + 0x40);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        WanpDeleteInterface(plVar3[0x12]);
      }
    }
    LOCK();
    plVar3 = plVar3 + 0xc;
    lVar5 = *plVar3;
    *(int *)plVar3 = (int)*plVar3 + -1;
    UNLOCK();
    if ((int)lVar5 == 1) {
      WanpDeleteAdapter((longlong)plVar1);
    }
  }
  KeReleaseSpinLockFromDpcLevel(&DAT_14000ad28);
  KeReleaseSpinLock(&g_rwlAdapterLock,uVar8);
  wil_UninitializeFeatureStaging();
  return;
}



===== WanpDeinitializeNdis @ 1400187dc =====

void WanpDeinitializeNdis(char param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  longlong lVar5;
  
  WanpAcquireResource(&g_wrBindMutex);
  puVar2 = &DAT_14000aa66;
  lVar1 = DAT_14000a160;
  if (param_1 == '\0') {
    puVar2 = &DAT_14000ab86;
    lVar1 = DAT_14000a3b0;
  }
  *puVar2 = 0;
  lVar5 = DAT_14000aa68;
  if (param_1 == '\0') {
    lVar5 = DAT_14000ab88;
  }
  WanpReleaseResource(&g_wrBindMutex);
  if (lVar1 != 0) {
    NdisDeregisterProtocolDriver(lVar1);
  }
  if (lVar5 != 0) {
    puVar4 = &DAT_14000ab38;
    if (param_1 == '\0') {
      puVar4 = &DAT_14000ac58;
    }
    KeWaitForSingleObject(puVar4,0,0,0,0);
  }
  WanpAcquireResource(&g_wrBindMutex);
  puVar3 = &DAT_14000a160;
  if (param_1 == '\0') {
    puVar3 = &DAT_14000a3b0;
  }
  *puVar3 = 0;
  WanpReleaseResource(&g_wrBindMutex);
  return;
}



===== WanpInitializeResource @ 1400188c8 =====

void WanpInitializeResource(undefined4 *param_1)

{
  *param_1 = 0;
  KeInitializeEvent(param_1 + 2,1);
  return;
}



===== WanpSetDeviceObjectDacl @ 1400188f4 =====

int WanpSetDeviceObjectDacl(void)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res10 [3];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res10[0] = 0;
  lVar3 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = ObOpenObjectByPointer(0,0x200,0,0x40000,0,0,local_res10);
  if (-1 < iVar1) {
    iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
    iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
    iVar1 = iVar1 + iVar2 + 0x18;
    lVar3 = ExAllocatePool2(0x100,iVar1,0x64707257);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = RtlCreateAcl(lVar3,iVar1,2);
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar3,2,0x1f01ff,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
        if (-1 < iVar1) {
          iVar1 = RtlAddAccessAllowedAce
                            (lVar3,2,0x1f01ff,*(undefined8 *)(*(longlong *)SeExports_exref + 0x110))
          ;
          if (-1 < iVar1) {
            iVar1 = RtlCreateSecurityDescriptor(&local_38,1);
            if (-1 < iVar1) {
              iVar1 = RtlSetDaclSecurityDescriptor(&local_38,1,lVar3,0);
              if (-1 < iVar1) {
                iVar1 = ZwSetSecurityObject(local_res10[0],4,&local_38);
              }
            }
          }
        }
      }
    }
  }
  if (local_res10[0] != 0) {
    ZwClose();
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x64707257);
  }
  return iVar1;
}



===== WanpSetupExternalName @ 140018ae8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WanpSetupExternalName(undefined8 param_1,undefined8 param_2,char param_3)

{
  undefined8 uVar1;
  undefined1 auStack_118 [32];
  undefined8 local_f8;
  undefined1 *local_f0;
  undefined1 local_e8 [208];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  local_f8 = 0;
  local_f0 = local_e8;
  RtlInitUnicodeString(&local_f8);
  if (param_3 == '\0') {
    IoDeleteSymbolicLink(&local_f8);
  }
  else {
    uVar1 = IoCreateSymbolicLink(&local_f8,param_1);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
  }
  return 0;
}



===== wil_UninitializeFeatureStaging @ 140018b84 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140018bdc =====

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
      goto LAB_140018c39;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140018c39;
    }
  }
  uVar1 = 0x206;
LAB_140018c39:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140018c44 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140018cfc =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140018d34 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140018db6;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140018db6;
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
LAB_140018db6:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140018e00 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140018e60 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140018e7c =====

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



===== WdmlibInit @ 140018f30 =====

void WdmlibInit(void)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
  PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
  if (PfnIoCreateDeviceSecure == (code *)0x0) {
    PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
  }
  RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
  MmGetSystemRoutineAddress(&local_18);
  WdmlibInitialized = 1;
  return;
}



===== WdmlibIoCreateDeviceSecure @ 140018fbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,param_3,0x12,0x100,0,in_stack_00000038,in_stack_00000040,in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 140019040 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,uint *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (uint *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1400191a0;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (uint *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1400191a0;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_1400191a0:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1400191d4 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 1400192c4 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 1400193a4 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 1400194a4 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 140019590 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  short *local_res8;
  uint local_res10;
  uint local_res18 [2];
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_res18[0] = 0;
  iVar5 = 0;
  local_58 = (wchar_t *)0x0;
  local_50[0] = 0;
  uVar15 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar3 = false;
  bVar2 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar15 = uVar15 + 1;
    }
    else {
      bVar2 = bVar3;
      if (*pwVar10 != L' ') {
        bVar3 = true;
        bVar2 = true;
      }
    }
  }
  uVar11 = uVar15 / 5;
  local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11);
  if ((uVar15 != uVar11 * 5) || ((uVar15 == 0 && (bVar2)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (uVar11 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar15 = uVar11 * 0x30 + 8;
      if (0xffff < uVar15) {
        uVar15 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar15,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar15);
        *_Dst = 2;
        _Dst[1] = (short)uVar15;
        *(undefined4 *)(_Dst + 2) = 0;
        uVar15 = (uint)local_res8;
        for (local_res10 = 0; uVar11 = 0, local_res10 < uVar15; local_res10 = local_res10 + 1) {
          local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
          for (; *param_1 == L' '; param_1 = param_1 + 1) {
          }
          if (*param_1 == L'(') {
            do {
              param_1 = param_1 + 1;
            } while (*param_1 == L' ');
          }
          iVar4 = _wcsnicmp(param_1,L"A",1);
          if (iVar4 != 0) {
LAB_1400198b4:
            iVar5 = -0x3ffffff3;
LAB_1400198b6:
            lVar7 = *param_2;
            goto LAB_1400198c2;
          }
          for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          if (*pwVar6 != L';') goto LAB_1400198b4;
          do {
            pwVar6 = pwVar6 + 1;
          } while (*pwVar6 == L' ');
          while (wVar1 = *pwVar6, wVar1 != L';') {
            while (wVar1 == L' ') {
              pwVar6 = pwVar6 + 1;
              wVar1 = *pwVar6;
            }
            uVar9 = SepSddlLookupAccessMaskInTable(pwVar6,local_res18,(longlong *)&local_58);
            if ((int)uVar9 == 0) {
              SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
              if (local_58 == pwVar6) goto LAB_1400198b4;
              uVar11 = (uint)local_res8;
            }
            else {
              local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11 | local_res18[0]);
              uVar11 = uVar11 | local_res18[0];
            }
            pwVar6 = local_58;
          }
          pwVar6 = pwVar6 + 1;
          if (iVar5 != 0) goto LAB_1400198b6;
          lVar7 = 2;
          do {
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') {
              iVar5 = -0x3ffffff3;
            }
            pwVar6 = pwVar6 + 1;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
          if (iVar5 != 0) goto LAB_1400198b6;
          for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          local_res8 = (short *)0x0;
          ppsVar13 = &local_res8;
          uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
          iVar5 = (int)uVar9;
          if (iVar5 != 0) break;
          psVar12 = local_res8;
          if (local_res8 == (short *)0x0) {
LAB_14001984e:
            iVar5 = -0x3fffff89;
            goto LAB_1400198b6;
          }
          for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
          }
          if (*psVar12 != 0x29) goto LAB_14001984e;
          param_1 = psVar12 + 1;
          if (local_50[0] != 0) {
            uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar11,
                                       uVar15 - local_res10,local_50[0]);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) goto LAB_1400198b6;
          }
          if (*param_1 == L'(') {
            param_1 = psVar12 + 2;
          }
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(undefined2 *)(lVar7 + 2) = (undefined2)local_res20[0];
          return 0;
        }
LAB_1400198c2:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 140019900 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar6 = 0;
  do {
    if (0xd < uVar6) {
      uVar4 = 0xc0000073;
LAB_1400199a8:
      *param_2 = uVar5;
      return uVar4;
    }
    uVar3 = (ulonglong)uVar6;
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_14000a57c + uVar3 * 0x18),
                      (ulonglong)*(uint *)(&DAT_14000a584 + uVar3 * 0x18));
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_14000a578 + uVar3 * 0x18);
      uVar6 = *(uint *)(&DAT_14000a584 + uVar3 * 0x18);
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto code_r0x00014001998d;
      }
      else {
code_r0x00014001998d:
        uVar5 = *(undefined8 *)
                 (*(longlong *)(&DAT_14000a570 + uVar3 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar4 = 0;
      goto LAB_1400199a8;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



===== SepSddlLookupAccessMaskInTable @ 1400199d4 =====

undefined8 SepSddlLookupAccessMaskInTable(wchar_t *param_1,undefined4 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = 0;
  while( true ) {
    if (7 < uVar2) {
      *param_2 = 0;
      *param_3 = (longlong)param_1;
      return 0;
    }
    uVar3 = (ulonglong)uVar2;
    iVar1 = _wcsnicmp(param_1,(wchar_t *)(&PTR_u_RC_14000a4a0)[uVar3 * 2],
                      (ulonglong)(uint)(&DAT_14000a4a8)[uVar3 * 4]);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
  }
  *param_2 = (&DAT_14000a4ac)[uVar3 * 4];
  *param_3 = (longlong)(param_1 + (uint)(&DAT_14000a4a8)[uVar3 * 4]);
  return 1;
}



===== SepSddlParseWideStringUlong @ 140019a6c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = *param_1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_140019ad9:
      iVar6 = 10;
      goto LAB_140019ab0;
    }
    param_1 = param_1 + 2;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_140019ad9;
  iVar6 = 0x10;
LAB_140019ab0:
  uVar7 = 0;
  for (puVar4 = param_1; uVar1 = *puVar4, uVar1 != 0; puVar4 = puVar4 + 1) {
    if ((ushort)(uVar1 - 0x30) < 10) {
      iVar2 = uVar1 - 0x30;
    }
    else {
      if (iVar6 != 0x10) break;
      if ((ushort)(uVar1 - 0x41) < 6) {
        iVar2 = uVar1 - 0x37;
      }
      else {
        if (5 < (ushort)(uVar1 - 0x61)) break;
        iVar2 = uVar1 - 0x57;
      }
    }
    uVar5 = iVar6 * uVar7 + iVar2;
    if (uVar5 < uVar7) goto LAB_140019b1d;
    uVar7 = uVar5;
  }
  if (puVar4 == param_1) {
LAB_140019b1d:
    uVar3 = 0;
  }
  else {
    *param_2 = puVar4;
    uVar3 = 1;
    *param_3 = uVar7;
  }
  return uVar3;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 140019b44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_140019c89;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_140019c89:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 140019ce8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (uint *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140008970,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar3 = (ulonglong)*param_1;
    pwVar5 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar4 = 2;
    }
    else {
      uVar2 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar5,uVar3,0,&local_b8,local_a8);
      uVar4 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar4;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 140019e84 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1400088f0);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_14001a003;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140008908,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14001a003;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140008920,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14001a003;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140008950,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_14001a003:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 14001a048 =====

ulonglong PpRegStateReadCreateClassCreationSettings(uint *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x140008890,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1400088a8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400088b8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400088d8,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 14001a1ac =====

ulonglong PpRegStateUpdateStackCreationSettings(uint *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar2 = CmRegUtilCreateWstrKey
                      (local_res20,0x140008890,uVar7,uVar8,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = (ulonglong)uVar2;
    ZwClose(local_res20);
    if (-1 < (int)uVar2) {
      uVar3 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1400088f0);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar2 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar3);
        uVar4 = (ulonglong)uVar2;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 14001a314 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateUcKey @ 14001a410 =====

int CmRegUtilCreateUcKey
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  int iVar1;
  undefined8 local_res8 [3];
  undefined4 local_res20 [2];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_1c = 0;
  local_res20[0] = 0;
  local_res8[0] = 0;
  local_10 = 0;
  local_18 = param_5;
  local_38 = 0x30;
  local_20 = 0x240;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwCreateKey(local_res8,0xf003f,&local_38,0,0,0,local_res20);
  if (iVar1 < 0) {
    local_res8[0] = 0;
    local_res20[0] = 0;
  }
  *param_7 = local_res8[0];
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_res20[0];
  }
  return iVar1;
}



===== CmRegUtilCreateWstrKey @ 14001a4b8 =====

void CmRegUtilCreateWstrKey
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  short local_18 [12];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_18,param_2);
  if (-1 < (int)uVar1) {
    CmRegUtilCreateUcKey(param_1,local_18,param_3,param_1,param_5,param_6,param_7);
  }
  return;
}



===== CmRegUtilOpenExistingWstrKey @ 14001a518 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 14001a5ac =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_14001a6e4;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_14001a6e4:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 14001a728 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 14001a874 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 14001a918 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== WanNdisPnPEvent @ 14001a980 =====

undefined8 WanNdisPnPEvent(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if ((param_1 - 0xcabb1e4U & 0xfffffffffffffffd) != 0) {
    return 0x10001;
  }
  if (*(int *)(param_2 + 8) != 4) {
    return 0;
  }
  if (*(uint *)(param_2 + 0x18) < 0xc) {
    return 0xc0010016;
  }
  uVar1 = 0x10001;
  if (*(int *)(*(longlong *)(param_2 + 0x10) + 4) == 2) {
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



===== WanNdisOpenAdapterComplete @ 14001a9d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WanNdisOpenAdapterComplete(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  bool bVar5;
  bool bVar6;
  undefined1 auStackY_68 [32];
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  bVar5 = param_1 == 0xcabb1e4;
  local_20 = 0x80;
  local_1c = 8;
  local_28 = 0x80;
  local_24 = 0xdd86;
  puVar3 = &local_28;
  if (bVar5) {
    puVar3 = &local_20;
  }
  if (param_2 == 0) {
    lVar2 = ExAllocatePool2(0x40,0x108,0x72707257);
    if (lVar2 == 0) {
      bVar6 = param_1 != 0xcabb1e4;
      puVar3 = &DAT_14000aaa4;
      if (bVar6) {
        puVar3 = &DAT_14000abc4;
      }
      *puVar3 = 0xc000009a;
      puVar3 = &DAT_14000aaa0;
      if (bVar6) {
        puVar3 = &DAT_14000abc0;
      }
      puVar1 = &DAT_14000aad0;
      *puVar3 = 0xc000009a;
      if (bVar6) {
        puVar1 = &DAT_14000abf0;
      }
      puVar1[2] = WanpCloseNdisWan;
      puVar1[3] = (ulonglong)bVar5;
      *puVar1 = 0;
      ExQueueWorkItem(puVar1,1);
    }
    else {
      *(undefined4 *)(lVar2 + 0x100) = *puVar3;
      *(undefined2 *)(lVar2 + 0x104) = *(undefined2 *)(puVar3 + 1);
      WanpDoNdisRequest(lVar2,0x4010104,(undefined4 *)(lVar2 + 0x100),6,(undefined4 *)lVar2,
                        WanpSetProtocolTypeComplete,bVar5);
    }
  }
  else {
    uVar4 = DAT_14000aa90;
    if (param_1 != 0xcabb1e4) {
      uVar4 = DAT_14000abb0;
    }
    NdisCompleteBindAdapterEx(uVar4);
    puVar1 = &DAT_14000aa90;
    if (param_1 != 0xcabb1e4) {
      puVar1 = &DAT_14000abb0;
    }
    *puVar1 = 0;
    WanpFreeBindResourcesAndReleaseLock(bVar5);
  }
  return;
}



===== WanpFreeBindResourcesAndReleaseLock @ 14001ab80 =====

void WanpFreeBindResourcesAndReleaseLock(char param_1)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  
  uVar3 = DAT_14000aa78;
  if (param_1 == '\0') {
    uVar3 = DAT_14000ab98;
  }
  ExFreePoolWithTag(uVar3,0);
  puVar1 = &DAT_14000aa78;
  if (param_1 == '\0') {
    puVar1 = &DAT_14000ab98;
  }
  *puVar1 = 0;
  uVar3 = DAT_14000aa88;
  if (param_1 == '\0') {
    uVar3 = DAT_14000aba8;
  }
  ExFreePoolWithTag(uVar3,0);
  puVar1 = &DAT_14000aa88;
  if (param_1 == '\0') {
    puVar1 = &DAT_14000aba8;
  }
  *puVar1 = 0;
  puVar2 = &DAT_14000aaac;
  if (param_1 == '\0') {
    puVar2 = &DAT_14000abcc;
  }
  *puVar2 = 1;
  WanpRemoveAllConnections(param_1);
  WanpRemoveAllAdapters(param_1);
  return;
}



===== WanpNdisCompleteBindAdapter @ 14001ac40 =====

void WanpNdisCompleteBindAdapter(char param_1)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  bool bVar4;
  
  uVar3 = DAT_14000aa90;
  if (param_1 == '\0') {
    uVar3 = DAT_14000abb0;
  }
  NdisCompleteBindAdapterEx(uVar3,0);
  bVar4 = param_1 == '\0';
  puVar1 = &DAT_14000aa90;
  if (bVar4) {
    puVar1 = &DAT_14000abb0;
  }
  *puVar1 = 0;
  puVar2 = &DAT_14000aa65;
  if (bVar4) {
    puVar2 = &DAT_14000ab85;
  }
  *puVar2 = 1;
  puVar2 = &DAT_14000aa66;
  if (bVar4) {
    puVar2 = &DAT_14000ab86;
  }
  *puVar2 = 1;
  WanpReleaseResource(&g_wrBindMutex);
  return;
}



===== WanpInitNdiswanAdapterInfo @ 14001acd0 =====

undefined8 WanpInitNdiswanAdapterInfo(short *param_1,ushort *param_2,char param_3)

{
  longlong lVar1;
  void *_Dst;
  undefined8 uVar2;
  undefined8 *puVar3;
  short sVar4;
  ushort *puVar5;
  ushort uVar6;
  longlong *plVar7;
  short *psVar8;
  short *psVar9;
  bool bVar10;
  
  *param_1 = *param_1 + 2;
  lVar1 = ExAllocatePool2(0x40,*param_1,0x73707257);
  plVar7 = &DAT_14000aa78;
  if (param_3 == '\0') {
    plVar7 = &DAT_14000ab98;
  }
  *plVar7 = lVar1;
  if (lVar1 == 0) {
    return 0xc000009a;
  }
  psVar8 = (short *)&DAT_14000aa72;
  if (param_3 == '\0') {
    psVar8 = (short *)&DAT_14000ab92;
  }
  psVar9 = &DAT_14000aa70;
  *psVar8 = *param_1;
  if (param_3 == '\0') {
    psVar9 = &DAT_14000ab90;
  }
  RtlUpcaseUnicodeString(psVar9,param_1,0);
  *param_1 = *param_1 + -2;
  sVar4 = DAT_14000aa70;
  if (param_3 == '\0') {
    sVar4 = DAT_14000ab90;
  }
  *psVar9 = sVar4 + -2;
  uVar6 = DAT_14000aa72;
  if (param_3 == '\0') {
    uVar6 = DAT_14000ab92;
  }
  lVar1 = DAT_14000aa78;
  if (param_3 == '\0') {
    lVar1 = DAT_14000ab98;
  }
  *(undefined2 *)(lVar1 + -2 + (ulonglong)(uVar6 >> 1) * 2) = 0;
  _Dst = (void *)ExAllocatePool2(0x40,param_2[1],0x73707257);
  if (_Dst == (void *)0x0) {
    lVar1 = DAT_14000aa78;
    if (param_3 == '\0') {
      lVar1 = DAT_14000ab98;
    }
    ExFreePoolWithTag(lVar1,0);
    uVar2 = 0xc000009a;
    *plVar7 = 0;
    *psVar8 = 0;
    *psVar9 = 0;
  }
  else {
    bVar10 = param_3 == '\0';
    puVar5 = &DAT_14000aa82;
    if (bVar10) {
      puVar5 = &DAT_14000aba2;
    }
    *puVar5 = param_2[1];
    puVar5 = &DAT_14000aa80;
    if (bVar10) {
      puVar5 = &DAT_14000aba0;
    }
    *puVar5 = *param_2;
    puVar3 = &DAT_14000aa88;
    if (bVar10) {
      puVar3 = &DAT_14000aba8;
    }
    *puVar3 = _Dst;
    memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)*param_2);
    uVar2 = 0;
  }
  return uVar2;
}



===== entry @ 14001b010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001b044 =====

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



===== DriverEntry @ 14001b078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014001b5c6) */
/* WARNING: Removing unreachable block (ram,0x00014001b5b0) */
/* WARNING: Removing unreachable block (ram,0x00014001b5d0) */

ulonglong DriverEntry(longlong param_1,short *param_2)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  bool bVar11;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined *local_c8;
  undefined8 *local_c0;
  undefined8 *local_b8;
  int local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  longlong lStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  local_a8[0] = 0;
  local_58 = 0x11cee3254d36e975;
  uStack_50 = 0x1803e12b0008c1bf;
  local_a0 = 0;
  uVar5 = 0;
  bVar2 = false;
  local_98 = 0;
  lStack_90 = 0;
  local_68 = 0;
  uStack_60 = 0;
  wil_InitializeFeatureStaging();
  KeInitializeMutex(&DAT_14000a960,0);
  sVar1 = *param_2;
  lVar6 = ExAllocatePool2(0x40,sVar1 + 0x1a,0x73707257);
  if (lVar6 == 0) {
    uVar9 = 0xc000009a;
    goto LAB_14001b5dc;
  }
  local_98._0_4_ = CONCAT22(sVar1 + 0x1a,(undefined2)local_98);
  lStack_90 = lVar6;
  RtlCopyUnicodeString(&local_98,param_2);
  RtlInitUnicodeString(&local_68,L"\\Parameters");
  RtlAppendUnicodeStringToString(&local_98,&local_68);
  iVar3 = OpenRegKey(&local_a0,&local_98);
  ExFreePoolWithTag(lVar6,0);
  if (iVar3 == 0) {
    iVar3 = GetRegDWORDValue(local_a0,L"DisableSpoofingProtection",local_a8);
    if (iVar3 == 0) {
      g_bDisableSpoofingProtection = (uint)(local_a8[0] != 0);
    }
    iVar3 = GetRegDWORDValue(local_a0,L"EnableLinkDownAtStop",local_a8);
    if (iVar3 == 0) {
      g_bEnableLinkDownAtStop = (uint)(local_a8[0] != 0);
    }
    iVar3 = GetRegDWORDValue(local_a0,L"DisableNATOnS2SExternalInterface",local_a8);
    if (iVar3 == 0) {
      g_SetInterfaceTagforRouter = local_a8[0] == 0;
    }
    iVar3 = GetRegDWORDValue(local_a0,L"EnableNATOnDialInInterface",local_a8);
    if (iVar3 == 0) {
      g_SetInterfaceTagForVpnServer = local_a8[0] != 0;
    }
    ZwClose(local_a0);
  }
  DAT_14000ab00 = 0;
  DAT_14000ac20 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  RtlInitUnicodeString(&local_88,L"\\Device\\WANARP");
  pwVar8 = L"\\Device\\WANARPV6";
  RtlInitUnicodeString(&local_78);
  uVar9 = Feature_132113720__private_IsEnabledDeviceUsageNoInline();
  local_b8 = &DAT_14000aaf8;
  local_c0 = &local_58;
  if ((int)uVar9 == 0) {
    local_c8 = &SDDL_SYS_ALL_NS_ALL;
  }
  else {
    local_c8 = &SDDL_SYS_ALL_ADM_ALL;
  }
  uVar4 = WdmlibIoCreateDeviceSecure(param_1,pwVar8,&local_88);
  uVar9 = (ulonglong)uVar4;
  bVar11 = uVar4 == 0;
  if ((int)uVar4 < 0) {
LAB_14001b4d8:
    if (bVar11) {
      return 0;
    }
    if ((uVar5 & 0x10) != 0) {
      local_d8 = 0;
      KeWaitForSingleObject(&DAT_14000a960,0,0,0);
      WanNmrpCleanupProviderState(&WanNmrV4ProviderState);
      WanNmrpCleanupProviderState(&WanNmrV6ProviderState);
    }
    if ((uVar5 & 0x40) != 0) {
      NetioUnInitializeNetBufferListLibrary();
    }
    if ((uVar5 & 0x70) != 0) {
      DAT_14000a958 = 1;
      KeReleaseMutex(&DAT_14000a960,0);
    }
    if ((uVar5 & 0x20) != 0) {
      NetioUnRegisterProcessorAddCallback(&DAT_14000a948);
    }
  }
  else {
    uVar9 = Feature_132113720__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar9 != 0) {
      uVar4 = WanpSetDeviceObjectDacl();
      uVar9 = (ulonglong)uVar4;
      if (-1 < (int)uVar4) goto LAB_14001b2ef;
      goto LAB_14001b4d6;
    }
LAB_14001b2ef:
    uVar9 = Feature_132113720__private_IsEnabledDeviceUsageNoInline();
    local_b8 = &DAT_14000ac18;
    local_c0 = &local_58;
    if ((int)uVar9 == 0) {
      local_c8 = &SDDL_SYS_ALL_NS_ALL;
    }
    else {
      local_c8 = &SDDL_SYS_ALL_ADM_ALL;
    }
    uVar4 = WdmlibIoCreateDeviceSecure(param_1,pwVar8,&local_78);
    uVar9 = (ulonglong)uVar4;
    bVar11 = uVar4 == 0;
    if ((int)uVar4 < 0) goto LAB_14001b4d8;
    uVar9 = Feature_132113720__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar9 != 0) {
      uVar4 = WanpSetDeviceObjectDacl();
      uVar9 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) goto LAB_14001b4d6;
    }
    uVar7 = WanpSetupExternalName(&local_88,L"\\DosDevices\\WanArp",'\x01');
    uVar9 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) {
LAB_14001b4d6:
      bVar11 = (int)uVar9 == 0;
      goto LAB_14001b4d8;
    }
    uVar5 = 0;
    bVar2 = true;
    uVar7 = WanpSetupExternalName(&local_78,L"\\DosDevices\\WanArpV6",'\x01');
    uVar9 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) goto LAB_14001b4d6;
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(code **)(param_1 + 0x68) = WanUnload;
    bVar2 = true;
    puVar10 = (undefined8 *)(param_1 + 0x70);
    for (lVar6 = 0x1c; lVar6 != 0; lVar6 = lVar6 + -1) {
      *puVar10 = WanDispatch;
      puVar10 = puVar10 + 1;
    }
    bVar11 = WanpInitializeDriverStructures();
    if (bVar11) {
      WanpAcquireResource(&g_wrBindMutex);
      DAT_14000ab6c = 1;
      DAT_14000ac8c = 1;
      local_d8 = 0;
      bVar2 = true;
      KeWaitForSingleObject(&DAT_14000a960,0,0,0);
      uVar5 = NetioRegisterProcessorAddCallback(&DAT_14000a948,WanpProcessorAddCallback);
      uVar9 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        uVar5 = 0x2f;
        bVar2 = true;
        DAT_14000a940 = KeQueryActiveProcessorCountEx(0xffff);
        uVar4 = NetioInitializeNetBufferListLibrary();
        uVar9 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          uVar5 = 0x6f;
          bVar2 = true;
          uVar7 = WanNmrpRegisterProviders();
          uVar9 = uVar7 & 0xffffffff;
          if (-1 < (int)uVar7) {
            KeReleaseMutex(&DAT_14000a960,0);
            DAT_14000ab6c = 0;
            DAT_14000ac8c = 0;
            WanpReleaseResource(&g_wrBindMutex);
            uVar5 = 0x7b;
            bVar2 = true;
            DAT_14000a9d4 = 1;
            uVar9 = NmrRegisterClient(&FlNaClientNotify,0);
            uVar9 = uVar9 & 0xffffffff;
          }
        }
        goto LAB_14001b4d6;
      }
      KeReleaseMutex(&DAT_14000a960,0);
    }
    else {
      uVar9 = 0xc000009a;
    }
  }
  if (DAT_14000aaf8 != 0) {
    IoDeleteDevice();
  }
  if (DAT_14000ac18 != 0) {
    IoDeleteDevice();
  }
  if (bVar2) {
    WanpSetupExternalName(0,L"\\DosDevices\\WanArp",'\0');
  }
LAB_14001b5dc:
  wil_UninitializeFeatureStaging();
  return uVar9;
}



===== WanpInitializeDriverStructures @ 14001b618 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool WanpInitializeDriverStructures(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  bool bVar3;
  
  KeInitializeSpinLock(&g_rlStateLock);
  puVar1 = (undefined4 *)&g_ModuleV4;
  lVar2 = 2;
  do {
    KeInitializeEvent(puVar1 + 0x30,1);
    KeInitializeEvent(puVar1 + 0x2a,0);
    KeInitializeEvent(puVar1 + 0x36,1);
    KeInitializeEvent(puVar1 + 0x3c,1);
    puVar1 = &g_ModuleV6;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  WanpInitializeResource(&g_wrBindMutex);
  WanpInitializeResource((undefined4 *)&WfpMutex);
  KeInitializeEvent(&g_DriverRefCountEvent,0,0);
  KeInitializeSpinLock(&g_rwlIfLock);
  KeInitializeSpinLock(&DAT_14000acc8);
  DAT_14000acd0 = 0;
  KeInitializeSpinLock(&g_rwlAdapterLock);
  KeInitializeSpinLock(&DAT_14000ad28);
  DAT_14000ad30 = 0;
  _DAT_14000aca8 = &g_leIfList;
  g_leIfList = &g_leIfList;
  _DAT_14000ade8 = &g_lePendingV4NotificationList;
  g_lePendingV4NotificationList = &g_lePendingV4NotificationList;
  DAT_14000ad08 = &g_lePendingV6NotificationList;
  g_lePendingV6NotificationList = &g_lePendingV6NotificationList;
  DAT_14000ad68 = &g_lePendingV4IrpList;
  g_lePendingV4IrpList = &g_lePendingV4IrpList;
  DAT_14000ace8 = &g_lePendingV6IrpList;
  g_lePendingV6IrpList = &g_lePendingV6IrpList;
  DAT_14000ada8 = &g_leMappedAdapterList;
  g_leMappedAdapterList = &g_leMappedAdapterList;
  DAT_14000ad48 = &g_leDialInAdapterList;
  g_leDialInAdapterList = &g_leDialInAdapterList;
  g_puipConnTable = (undefined8 *)ExAllocatePool2(0x40,0x80,0x63707257);
  bVar3 = g_puipConnTable != (undefined8 *)0x0;
  if (bVar3) {
    g_ulNextConnIndex = 1;
    g_ulConnTableSize = 0x10;
    *g_puipConnTable = 0xffffffffffffffff;
    KeInitializeSpinLock(&g_rlConnTableLock);
    ExInitializeNPagedLookasideList(&g_llConnBlocks,0,0,0x200,0x130,0x63707257,0x10);
    ExInitializeNPagedLookasideList(&g_llNotificationBlocks,0,0,0x200,0x650,0x6e707257,4);
  }
  return bVar3;
}



===== wil_InitializeFeatureStaging @ 14001b8a0 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001b990 =====

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



===== WanNmrpRegisterProviders @ 14001ba78 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WanNmrpRegisterProviders(void)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  uVar2 = WanNmrpInitializeProviderState(&WanNmrV4ProviderState);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar2 = WanNmrpInitializeProviderState(&WanNmrV6ProviderState);
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar1 = NmrRegisterProvider(&DAT_14000a008,&DAT_14000a008,&DAT_14000a050);
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        LOCK();
        g_DriverRefCount = g_DriverRefCount + 1;
        UNLOCK();
        LOCK();
        _FlStartedModules = _FlStartedModules + 0x4000;
        UNLOCK();
        uVar1 = NmrRegisterProvider(&DAT_14000a258,&DAT_14000a258,&DAT_14000a2a0);
        uVar3 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          LOCK();
          g_DriverRefCount = g_DriverRefCount + 1;
          UNLOCK();
          LOCK();
          _FlStartedModules = _FlStartedModules + 0x40;
          UNLOCK();
          local_38 = 0x280180;
          local_30 = WanNdisIfQueryHandler;
          local_28 = WanNdisIfSetHandler;
          local_20 = 0;
          uStack_18 = 0;
          uVar1 = NdisIfRegisterProvider
                            (&local_38,&g_hNdisIfProviderHandle,&g_hNdisIfProviderHandle);
          uVar3 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            return uVar3;
          }
        }
      }
    }
  }
  WanNmrpDeregisterV4Provider();
  WanNmrpWaitV4Provider();
  WanNmrpCleanupProviderState(&WanNmrV4ProviderState);
  WanNmrpDeregisterV6Provider();
  WanNmrpWaitV6Provider();
  WanNmrpCleanupProviderState(&WanNmrV6ProviderState);
  return uVar3;
}


