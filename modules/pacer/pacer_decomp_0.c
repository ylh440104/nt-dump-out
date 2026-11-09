
===== PcpReferenceFlow @ 140001010 =====

longlong PcpReferenceFlow(longlong param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)(*(uint *)(param_1 + 0x268) >> 8);
  if ((*(uint *)(param_1 + 0x268) & 8) == 0) {
    LOCK();
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    UNLOCK();
    return CONCAT71((uint7)uVar1,1);
  }
  return (ulonglong)uVar1 << 8;
}



===== PcFilterReceiveNetBufferLists @ 140001030 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcFilterReceiveNetBufferLists
               (longlong param_1,undefined8 *param_2,undefined4 param_3,uint param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  ushort *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined1 auStack_e8 [32];
  undefined8 *local_c8;
  undefined4 local_b8;
  undefined8 *local_b0;
  undefined8 *puStack_a8;
  ulonglong local_a0;
  undefined8 *local_98;
  undefined8 *puStack_90;
  undefined8 local_88;
  longlong local_78;
  undefined8 local_70;
  ushort local_68 [8];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_e8;
  local_a0 = 0;
  local_88 = 0;
  local_b0 = (undefined8 *)0x0;
  puStack_a8 = (undefined8 *)0x0;
  local_98 = (undefined8 *)0x0;
  puStack_90 = (undefined8 *)0x0;
  puVar7 = param_2;
  local_b8 = param_3;
  if (*(int *)(param_1 + 0x18) == 2) {
    if ((*(int *)(param_1 + 0x10) == 3) && (*(short *)(param_1 + 0xd4) == 0x800)) {
      puVar7 = (undefined8 *)0x0;
      if (param_2 != (undefined8 *)0x0) {
        puVar9 = (undefined8 *)0x0;
        do {
          local_70 = 0;
          local_68[0] = 0;
          local_68[1] = 0;
          local_68[2] = 0;
          local_68[3] = 0;
          puVar3 = (undefined8 *)*param_2;
          local_68[4] = 0;
          local_68[5] = 0;
          local_68[6] = 0;
          local_78 = param_2[1];
          *param_2 = 0;
          local_c8 = (undefined8 *)((ulonglong)local_c8 & 0xffffffff00000000);
          puVar5 = (ushort *)NdisGetDataBuffer(local_78,0xe,local_68);
          if ((puVar5 == (ushort *)0x0) || (lVar6 = PcpLineLookupById(*puVar5), lVar6 == 0)) {
            if (puVar9 == (undefined8 *)0x0) {
              puVar8 = puVar7;
              puVar7 = param_2;
              local_98 = param_2;
            }
            else {
              puVar8 = (undefined8 *)*puVar9;
              *puVar9 = param_2;
            }
            *param_2 = puVar8;
            if (puVar8 == (undefined8 *)0x0) {
              puVar9 = param_2;
              puStack_90 = param_2;
            }
          }
          else {
            *(undefined4 *)puVar5 = *(undefined4 *)(lVar6 + 0x14e);
            puVar5[2] = *(ushort *)(lVar6 + 0x152);
            puVar5[3] = *(ushort *)(lVar6 + 0xf0);
            LOCK();
            piVar1 = (int *)(lVar6 + 0xf8);
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              if (*(longlong *)(lVar6 + 0x140) != 0) {
                NdisFreeMemoryWithTag(*(longlong *)(lVar6 + 0x140),0x616e6350);
              }
              if (*(longlong *)(lVar6 + 0x100) != 0) {
                PcpFilterDecrementDetachCount(*(longlong *)(lVar6 + 0x100));
              }
              if (*(longlong *)(lVar6 + 0x10) != 0) {
                NdisFreeRWLock();
              }
              ExFreePoolWithTag(lVar6,0x656c6350);
            }
            if (puVar5 == local_68) {
              local_c8 = &local_70;
              RtlCopyBufferToMdl(puVar5,*(undefined8 *)(local_78 + 8),
                                 *(undefined4 *)(local_78 + 0x10),0xc);
            }
            if (puStack_a8 == (undefined8 *)0x0) {
              puVar7 = local_b0;
              local_b0 = param_2;
            }
            else {
              puVar7 = (undefined8 *)*puStack_a8;
              *puStack_a8 = param_2;
            }
            *param_2 = puVar7;
            if (puVar7 == (undefined8 *)0x0) {
              puStack_a8 = param_2;
            }
            local_a0 = CONCAT44(local_a0._4_4_,(int)local_a0 + 1);
            puVar7 = local_98;
            puVar9 = puStack_90;
          }
          param_2 = puVar3;
        } while (puVar3 != (undefined8 *)0x0);
      }
    }
    else {
      puVar7 = (undefined8 *)0x0;
      local_a0 = (ulonglong)param_4;
      local_b0 = param_2;
    }
  }
  uVar4 = local_b8;
  if ((puVar7 != (undefined8 *)0x0) && ((param_5 & 2) == 0)) {
    NdisFReturnNetBufferLists(*(undefined8 *)(param_1 + 0x28),puVar7,param_5 & 1);
  }
  if (local_b0 != (undefined8 *)0x0) {
    local_c8 = (undefined8 *)CONCAT44(local_c8._4_4_,param_5);
    NdisFIndicateReceiveNetBufferLists
              (*(undefined8 *)(param_1 + 0x28),local_b0,uVar4,local_a0 & 0xffffffff);
  }
  return;
}



===== PcpLineLookupById @ 140001320 =====

longlong PcpLineLookupById(ushort param_1)

{
  longlong lVar1;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  DAT_140019668 = KeAcquireSpinLockRaiseToDpc(&PcgLineTableLock);
  if (((param_1 == 0) || (PcgLineTableLen <= param_1)) || (PcgLineTable == 0)) {
    KeReleaseSpinLock(&PcgLineTableLock,DAT_140019668);
  }
  else {
    lVar1 = *(longlong *)(PcgLineTable + (ulonglong)param_1 * 8);
    if (lVar1 == 0) {
      KeReleaseSpinLock(&PcgLineTableLock,DAT_140019668);
      return 0;
    }
    LOCK();
    *(int *)(lVar1 + 0xf8) = *(int *)(lVar1 + 0xf8) + 1;
    UNLOCK();
    KeReleaseSpinLock(&PcgLineTableLock,DAT_140019668);
    NdisAcquireRWLockRead(*(undefined8 *)(lVar1 + 0x10),&local_res8,0);
    if (*(int *)(lVar1 + 0xf4) != 0) {
      NdisReleaseRWLock();
      return lVar1;
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar1 + 0x10),&local_res8);
    PcpLineDereference(lVar1);
  }
  return 0;
}



===== PcFilterSendNetBufferLists @ 140001430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcFilterSendNetBufferLists(longlong param_1,longlong *param_2,uint param_3,uint param_4)

{
  longlong *plVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  longlong *plVar7;
  ushort *puVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  byte bVar11;
  uint uVar12;
  ulonglong uVar13;
  int iVar14;
  undefined8 *puVar15;
  undefined2 *puVar16;
  uint *puVar17;
  longlong lVar18;
  int *piVar19;
  longlong *plVar20;
  longlong *plVar21;
  uint uVar22;
  longlong *plVar23;
  longlong lVar24;
  longlong lVar25;
  longlong lVar26;
  int iVar27;
  uint uVar28;
  undefined8 *puVar29;
  longlong **pplVar30;
  longlong **pplVar31;
  ulonglong uVar32;
  bool bVar33;
  bool bVar34;
  undefined1 auStackY_2e8 [32];
  longlong *local_290;
  undefined8 *local_288;
  uint local_278 [2];
  undefined8 *local_270;
  undefined8 *local_268;
  longlong *local_260;
  undefined2 local_258;
  undefined1 local_256;
  undefined2 local_254;
  undefined1 local_252;
  longlong **local_250;
  uint local_248;
  ulonglong local_240;
  longlong *local_238;
  longlong *local_230;
  longlong *local_228;
  longlong *local_220;
  undefined4 local_218;
  longlong *local_210;
  longlong *local_208;
  longlong local_200;
  longlong *local_1f8;
  longlong **local_1f0;
  ulonglong local_1e8;
  ulonglong local_1e0;
  longlong local_1d8;
  ulonglong local_1d0;
  longlong *local_1c8;
  longlong *local_1c0;
  ulonglong local_1b8;
  longlong *local_1b0;
  longlong *plStack_1a8;
  undefined8 local_1a0;
  longlong local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  uint local_170;
  undefined8 local_16c;
  undefined8 uStack_164;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined2 local_b4;
  ulonglong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_2e8;
  uVar3 = 0;
  local_110 = 0;
  local_210 = (longlong *)0x0;
  local_120 = 0;
  uStack_118 = 0;
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
  plVar23 = param_2;
  local_278[0] = param_3;
  if (*(int *)(param_1 + 0x18) == 2) {
    bVar33 = (param_4 & 1) == 0;
    if (bVar33) {
      uVar3 = KfRaiseIrql(2);
    }
    local_248 = KeGetCurrentProcessorNumberEx(0);
    lVar24 = _DAT_fffff78000000008;
    uVar32 = (ulonglong)local_248;
    local_200 = (ulonglong)local_248 * 0x80;
    plVar23 = (longlong *)(*QosgTimerTable + local_200);
    local_1e8 = 0;
    uVar5 = KeQueryPerformanceCounter(&local_1e8);
    uVar13 = (uVar5 >> 0x20) * 1000000;
    bVar11 = *(byte *)(plVar23 + 0xe);
    local_1d8 = ((uVar13 % local_1e8 << 0x20) + (uVar5 & 0xffffffff) * 1000000) / local_1e8 +
                (uVar13 / local_1e8 << 0x20);
    if (bVar11 == 0) {
      bVar4 = 2;
    }
    else {
      bVar4 = bVar11 - 1;
    }
    uVar13 = (ulonglong)bVar4;
    if (plVar23[uVar13 + 8] - local_1d8 < 1) {
      plVar23[(ulonglong)bVar11 + 2] = uVar5;
      plVar23[(ulonglong)bVar11 + 5] = local_1e8;
      plVar23[(ulonglong)bVar11 + 8] = local_1d8;
    }
    else {
      plVar23[(ulonglong)bVar11 + 2] = plVar23[uVar13 + 2];
      plVar23[(ulonglong)bVar11 + 5] = plVar23[uVar13 + 5];
      plVar23[(ulonglong)bVar11 + 8] = plVar23[uVar13 + 8];
      local_1d8 = plVar23[uVar13 + 8];
    }
    plVar23[(ulonglong)bVar11 + 0xb] = lVar24;
    *plVar23 = local_1d8;
    local_1b0 = (longlong *)0x0;
    plStack_1a8 = (longlong *)0x0;
    plVar23[1] = lVar24;
    lVar24 = PcgDelayQueue;
    *(byte *)(plVar23 + 0xe) = (byte)((char)plVar23[0xe] + 1U) % 3;
    piVar19 = (int *)(uVar32 * 0x40 + 0x10 + lVar24);
    *piVar19 = *piVar19 + 1;
    piVar19 = (int *)(uVar32 * 0xc0 + 0x28 + PcgTimerUnits);
    *piVar19 = *piVar19 + 1;
    local_1a0 = 0;
    local_260 = (longlong *)0x0;
    if (param_2 != (longlong *)0x0) {
      lVar24 = local_1d8;
      uVar22 = local_248;
      do {
        plVar23 = (longlong *)*param_2;
        *param_2 = 0;
        local_290 = (longlong *)param_2[0x15];
        local_238 = param_2;
        if ((*(char *)(param_1 + 0xd3) == '\x01') && (local_290 == (longlong *)0x0)) {
          if (PcgDefaultFlow == (longlong *)0x0) {
            local_88 = 0;
            uStack_80 = 0;
            uVar5 = 0;
            local_78 = 0;
            uStack_70 = 0;
            local_68 = 0;
            uStack_60 = 0;
            local_a8 = 0xffffffffffffffff;
            uStack_a0 = 0xffffffffffffffff;
            local_98 = 0x1ffffffff;
            uStack_90 = 0xffffffffffffffff;
            PcpCreateFlow(&local_210,0,0,0,0x50,0,&local_a8,'\x01',(undefined8 *)0x0);
            LOCK();
            bVar34 = PcgDefaultFlow == (longlong *)0x0;
            if (bVar34) {
              PcgDefaultFlow = local_210;
            }
            UNLOCK();
            if ((!bVar34) && (local_210 != (longlong *)0x0)) {
              PcpDeleteFlow(local_210,uVar5);
            }
            if (PcgDefaultFlow == (longlong *)0x0) goto LAB_140001649;
          }
          uVar5 = 0x7fffffffffffffff;
          lVar18 = PcpReferenceFlow((longlong)PcgDefaultFlow);
          plVar7 = PcgDefaultFlow;
          if ((char)lVar18 == '\x01') {
            local_290 = PcgDefaultFlow;
            param_2[0x15] = (longlong)PcgDefaultFlow;
            if ((((plVar7 != (longlong *)0x0) &&
                 (Microsoft_Windows_Networking_CorrelationEnabled != 0)) &&
                (PcgEventTraceEnabled != 0)) && ((param_2[0x1f] & uVar5) != 0)) {
              PcpEtwTransferFlowActivity(param_2[0x1f] & uVar5,plVar7);
            }
          }
        }
LAB_140001649:
        local_268 = *(undefined8 **)(param_1 + 0xa0);
        bVar34 = false;
        if ((*(int *)(param_1 + 0x10) == 3) && (*(short *)(param_1 + 0xd4) == 0x800)) {
          local_c0 = 0;
          local_b8 = 0;
          local_b4 = 0;
          local_190 = 0;
          local_288 = (undefined8 *)param_2[1];
          uVar5 = 0xe;
          puVar8 = (ushort *)NdisGetDataBuffer(local_288);
          if (puVar8 != (ushort *)0x0) {
            local_270 = (undefined8 *)PcpLineLookupById(*puVar8);
            local_268 = local_270;
            if (local_270 != (undefined8 *)0x0) {
              if (*(int *)((longlong)local_270 + 0xf4) != 2) {
                PcpLineDereference((longlong)local_270);
                goto LAB_140002422;
              }
              *(undefined4 *)puVar8 = *(undefined4 *)(local_270 + 0x29);
              puVar8[2] = *(ushort *)((longlong)local_270 + 0x14c);
              puVar8[3] = *(ushort *)(local_270 + 0x1e);
              if (puVar8 != (ushort *)&local_c0) {
                local_288 = (undefined8 *)*local_288;
              }
              if (local_288 == (undefined8 *)0x0) {
              }
              else {
                do {
                  RtlCopyBufferToMdl(puVar8,local_288[1]);
                  local_288 = (undefined8 *)*local_288;
                } while (local_288 != (undefined8 *)0x0);
                param_2 = local_238;
                uVar22 = local_248;
              }
              bVar34 = true;
              bVar2 = true;
              if (local_290 == (longlong *)0x0) goto LAB_14000166e;
              uVar5 = 8;
              iVar14 = NdisAllocateNetBufferListContext(param_2);
              if (iVar14 == 0) {
                LOCK();
                *(int *)(local_270 + 0x1f) = *(int *)(local_270 + 0x1f) + 1;
                UNLOCK();
                *(undefined8 **)((ulonglong)*(ushort *)(param_2[2] + 10) + 0x10 + param_2[2]) =
                     local_270;
                goto LAB_1400019b0;
              }
              plVar7 = (longlong *)param_2[0x15];
              if ((plVar7 != (longlong *)0x0) && (plVar7 == PcgDefaultFlow)) {
                PcpDereferenceFlow(plVar7,uVar5);
                param_2[0x15] = 0;
              }
              *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc0000001;
              NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2);
              PcpLineDereference((longlong)local_270);
              goto LAB_140001695;
            }
          }
LAB_140002422:
          plVar7 = (longlong *)param_2[0x15];
          if ((plVar7 != (longlong *)0x0) && (plVar7 == PcgDefaultFlow)) {
            PcpDereferenceFlow(plVar7,uVar5);
            param_2[0x15] = 0;
          }
          *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc0000001;
          NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2);
        }
        else {
          bVar2 = false;
          if (local_290 == (longlong *)0x0) {
LAB_14000166e:
            bVar34 = bVar2;
            if (plStack_1a8 == (longlong *)0x0) {
              plVar7 = local_1b0;
              local_1b0 = param_2;
            }
            else {
              plVar7 = (longlong *)*plStack_1a8;
              *plStack_1a8 = (longlong)param_2;
            }
            *param_2 = (longlong)plVar7;
            if (plVar7 == (longlong *)0x0) {
              plStack_1a8 = param_2;
            }
          }
          else {
LAB_1400019b0:
            if (local_290 != local_260) {
              local_250 = (longlong **)(local_290 + 0xc);
              local_260 = local_290;
              KeAcquireInStackQueuedSpinLockAtDpcLevel(local_250,&local_120);
              do {
              } while (*(int *)(local_250 + 1) != 0);
              if (((*(uint *)((longlong)local_290 + 0x54) != uVar22) &&
                  (plVar7 = (longlong *)local_290[0x1d], plVar7 != local_290 + 0x1d)) &&
                 (plVar7[3] - lVar24 < 1)) {
                PcpFlowDelay((longlong)local_290,uVar22);
              }
              KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_120);
            }
            lVar18 = param_2[0x15];
            local_208 = (longlong *)0x0;
            local_e0 = 0;
            local_f8 = 0;
            local_258 = 0;
            local_256 = 0;
            local_1f8 = (longlong *)0x0;
            local_f0 = 0;
            uStack_e8 = 0;
            local_108 = 0;
            uStack_100 = 0;
            local_270 = (undefined8 *)((ulonglong)*(uint *)(lVar18 + 0x54) * 0xc0 + PcgTimerUnits);
            KeAcquireInStackQueuedSpinLock(lVar18 + 0x60);
            lVar26 = _DAT_fffff78000000008;
            do {
            } while (*(int *)(lVar18 + 0x68) != 0);
            local_250 = (longlong **)(local_200 + *QosgTimerTable);
            if ((longlong *)_DAT_fffff78000000008 != local_250[1]) {
              local_1e0 = 0;
              uVar5 = KeQueryPerformanceCounter(&local_1e0);
              uVar13 = (uVar5 >> 0x20) * 1000000;
              bVar11 = *(byte *)(local_250 + 0xe);
              lVar25 = ((uVar13 % local_1e0 << 0x20) + (uVar5 & 0xffffffff) * 1000000) / local_1e0 +
                       (uVar13 / local_1e0 << 0x20);
              if (bVar11 == 0) {
                bVar4 = 2;
              }
              else {
                bVar4 = bVar11 - 1;
              }
              uVar13 = (ulonglong)bVar4;
              if ((longlong)local_250[uVar13 + 8] - lVar25 < 1) {
                local_250[(ulonglong)bVar11 + 2] = (longlong *)uVar5;
                local_250[(ulonglong)bVar11 + 5] = (longlong *)local_1e0;
                local_250[(ulonglong)bVar11 + 8] = (longlong *)lVar25;
              }
              else {
                local_250[(ulonglong)bVar11 + 2] = local_250[uVar13 + 2];
                local_250[(ulonglong)bVar11 + 5] = local_250[uVar13 + 5];
                local_250[(ulonglong)bVar11 + 8] = local_250[uVar13 + 8];
                lVar25 = (longlong)local_250[uVar13 + 8];
              }
              local_250[(ulonglong)bVar11 + 0xb] = (longlong *)lVar26;
              *local_250 = (longlong *)lVar25;
              local_250[1] = (longlong *)lVar26;
              *(byte *)(local_250 + 0xe) = (byte)((char)local_250[0xe] + 1U) % 3;
            }
            local_220 = *local_250;
            local_158 = 0x7fffffffffffffff;
            local_16c = 0;
            uStack_164 = 0;
            local_170 = *(uint *)(lVar18 + 0x1c8);
            local_15c = 0;
            local_150 = 0;
            if (local_170 != 0) {
              uVar5 = QosTbcAdjustBytesSent(lVar18 + 0x88,(longlong)local_220);
              puVar15 = local_268;
              if ((char)uVar5 != '\0') {
                if (*(longlong *)(lVar18 + 0x58) == local_268[0x25]) {
                  puVar10 = local_268;
                }
                else {
                  puVar10 = PcpLineFindByLuid(*(longlong *)(lVar18 + 0x58));
                }
                if (puVar10 != (undefined8 *)0x0) {
                  PcpLineSignalExternalEvent((longlong)puVar10,(ulonglong)uVar22);
                  puVar16 = &local_258;
                  NdisAcquireRWLockWrite(puVar10[2],puVar16,0);
                  puVar29 = puVar10;
                  QosLineQueryQueueFeedback((longlong)(puVar10 + 3),puVar16,&local_170);
                  NdisReleaseRWLock(puVar29[2],&local_258);
                  if (puVar10 != puVar15) {
                    PcpLineDereference((longlong)puVar10);
                  }
                }
                QosTbcAdjustSendWindow(lVar18 + 0x88,(longlong)&local_170);
              }
            }
            lVar26 = _DAT_fffff78000000008;
            local_218 = 0;
            local_250 = (longlong **)(local_200 + *QosgTimerTable);
            if ((longlong *)_DAT_fffff78000000008 != local_250[1]) {
              local_1b8 = 0;
              uVar5 = KeQueryPerformanceCounter(&local_1b8);
              uVar13 = (uVar5 >> 0x20) * 1000000;
              bVar11 = *(byte *)(local_250 + 0xe);
              lVar25 = ((uVar13 % local_1b8 << 0x20) + (uVar5 & 0xffffffff) * 1000000) / local_1b8 +
                       (uVar13 / local_1b8 << 0x20);
              if (bVar11 == 0) {
                bVar4 = 2;
              }
              else {
                bVar4 = bVar11 - 1;
              }
              uVar13 = (ulonglong)bVar4;
              if ((longlong)local_250[uVar13 + 8] - lVar25 < 1) {
                local_250[(ulonglong)bVar11 + 2] = (longlong *)uVar5;
                local_250[(ulonglong)bVar11 + 5] = (longlong *)local_1b8;
                local_250[(ulonglong)bVar11 + 8] = (longlong *)lVar25;
              }
              else {
                local_250[(ulonglong)bVar11 + 2] = local_250[uVar13 + 2];
                local_250[(ulonglong)bVar11 + 5] = local_250[uVar13 + 5];
                local_250[(ulonglong)bVar11 + 8] = local_250[uVar13 + 8];
                lVar25 = (longlong)local_250[uVar13 + 8];
              }
              local_250[(ulonglong)bVar11 + 0xb] = (longlong *)lVar26;
              *local_250 = (longlong *)lVar25;
              local_250[1] = (longlong *)lVar26;
              *(byte *)(local_250 + 0xe) = (byte)((char)local_250[0xe] + 1U) % 3;
            }
            local_198 = (longlong)*local_250;
            pplVar30 = &local_208;
            piVar19 = (int *)(lVar18 + 0x88);
            local_1f0 = (longlong **)0x0;
            local_250 = (longlong **)0x0;
            pplVar31 = &local_1f8;
            if (*(longlong *)(lVar18 + 0xe8) == lVar18 + 0xe8) {
              if ((*(int *)*QosgEtwDispatchTable == 1) &&
                 (lVar26 = local_198 - *(longlong *)(lVar18 + 400), 0 < lVar26)) {
                QosTraceFlowSendQueue((longlong)piVar19,0,local_198,lVar26,0,0,0);
              }
            }
            else if (*(longlong *)(*(longlong *)(lVar18 + 0xe8) + 0x18) - local_198 < 1) {
              QosTbcProcessQueuedNetBufferLists((longlong)piVar19,uVar22);
              if (local_1f0 != (longlong **)0x0) {
                pplVar30 = local_1f0;
              }
              if (local_250 != (longlong **)0x0) {
                pplVar31 = local_250;
              }
            }
            *(int *)(lVar18 + 0xa8) = *(int *)(lVar18 + 0xa8) + 1;
            uVar12 = 0;
            uVar28 = 0;
            for (puVar15 = (undefined8 *)local_238[1]; puVar15 != (undefined8 *)0x0;
                puVar15 = (undefined8 *)*puVar15) {
              uVar28 = uVar28 + *(int *)(puVar15 + 3);
              uVar12 = uVar12 + 1;
            }
            *(int *)(lVar18 + 0x90) = *(int *)(lVar18 + 0x90) + uVar12;
            *(longlong *)(lVar18 + 0x98) = *(longlong *)(lVar18 + 0x98) + (ulonglong)uVar28;
            plVar7 = local_238;
            uVar5 = QosTbcSendNetBufferList
                              (piVar19,uVar22,local_268 + 3,(longlong)local_238,uVar12,uVar28,
                               (byte)param_4,(longlong *)pplVar30,(longlong *)pplVar31);
            if ((char)uVar5 == '\0') {
              *(longlong *)(lVar18 + 400) = local_198;
            }
            else {
              uVar5 = *(ulonglong *)(*(longlong *)(lVar18 + 0xe8) + 0x18);
              RtlAcquireWriteLockAtDpcLevel((longlong)local_270);
              PcpSetTimer((longlong)local_270,(ulonglong)local_220,uVar5);
              PcpSetFlowTimer((longlong)local_270,lVar18,uVar5);
              KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_108);
            }
            KeReleaseInStackQueuedSpinLock(&local_f0);
            if (local_208 == (longlong *)0x0) {
LAB_140001d52:
            }
            else {
              puVar15 = (undefined8 *)local_208[0xc];
              plVar21 = local_208;
              local_270 = puVar15;
              if ((longlong *)*local_208 != (longlong *)0x0) {
                plVar9 = local_208;
                plVar20 = (longlong *)*local_208;
                do {
                  if ((undefined8 *)plVar20[0xc] != puVar15) {
                    *plVar9 = 0;
                    PcpLineSendNetBufferLists((longlong)(puVar15 + -3),uVar22,plVar21,plVar7);
                    puVar15 = (undefined8 *)plVar20[0xc];
                    plVar21 = plVar20;
                  }
                  plVar1 = (longlong *)*plVar20;
                  plVar9 = plVar20;
                  plVar20 = plVar1;
                } while (plVar1 != (longlong *)0x0);
                local_270 = puVar15;
              }
              puVar15 = local_270;
              lVar18 = _DAT_fffff78000000008;
              local_230 = (longlong *)0x0;
              local_228 = (longlong *)0x0;
              if (local_270 != (undefined8 *)0x18) {
                local_254 = 0;
                local_252 = 0;
                local_220 = (longlong *)(local_200 + *QosgTimerTable);
                if (_DAT_fffff78000000008 != local_220[1]) {
                  local_1d0 = 0;
                  uVar5 = KeQueryPerformanceCounter(&local_1d0);
                  uVar13 = (uVar5 >> 0x20) * 1000000;
                  bVar11 = *(byte *)(local_220 + 0xe);
                  lVar26 = ((uVar13 % local_1d0 << 0x20) + (uVar5 & 0xffffffff) * 1000000) /
                           local_1d0 + (uVar13 / local_1d0 << 0x20);
                  if (bVar11 == 0) {
                    bVar4 = 2;
                  }
                  else {
                    bVar4 = bVar11 - 1;
                  }
                  uVar13 = (ulonglong)bVar4;
                  if (local_220[uVar13 + 8] - lVar26 < 1) {
                    local_220[(ulonglong)bVar11 + 2] = uVar5;
                    local_220[(ulonglong)bVar11 + 5] = local_1d0;
                    local_220[(ulonglong)bVar11 + 8] = lVar26;
                  }
                  else {
                    local_220[(ulonglong)bVar11 + 2] = local_220[uVar13 + 2];
                    local_220[(ulonglong)bVar11 + 5] = local_220[uVar13 + 5];
                    local_220[(ulonglong)bVar11 + 8] = local_220[uVar13 + 8];
                    lVar26 = local_220[uVar13 + 8];
                  }
                  local_220[(ulonglong)bVar11 + 0xb] = lVar18;
                  *local_220 = lVar26;
                  local_220[1] = lVar18;
                  *(byte *)(local_220 + 0xe) = (byte)((char)local_220[0xe] + 1U) % 3;
                }
                if ((local_270[0x15] - *local_220 < 1) || (local_270[0x14] - *local_220 < 1)) {
                  LOCK();
                  piVar19 = (int *)(local_270 + 0x10);
                  iVar14 = *piVar19;
                  *piVar19 = *piVar19 + 1;
                  UNLOCK();
                  if (iVar14 == 0) {
                    NdisAcquireRWLockWrite(puVar15[-1],&local_254,0);
                    QosLineSignalExternalEvent((longlong)local_270,(ulonglong)uVar22);
                    NdisReleaseRWLock(puVar15[-1]);
                  }
                }
                iVar14 = 0;
                plVar7 = plVar21;
                do {
                  iVar27 = 0;
                  for (puVar10 = (undefined8 *)plVar7[1]; puVar10 != (undefined8 *)0x0;
                      puVar10 = (undefined8 *)*puVar10) {
                    iVar27 = iVar27 + *(int *)(puVar10 + 3);
                  }
                  plVar7 = (longlong *)*plVar7;
                  iVar14 = iVar14 + iVar27;
                } while (plVar7 != (longlong *)0x0);
                LOCK();
                *(int *)((longlong)puVar15 + 0x84) = *(int *)((longlong)puVar15 + 0x84) + iVar14;
                UNLOCK();
                plVar7 = plVar21;
                iVar14 = 0;
                do {
                  plVar9 = plVar7 + 0xf;
                  plVar7 = (longlong *)*plVar7;
                  iVar27 = iVar14 + 1;
                  if (*plVar9 != *(longlong *)(puVar15[0x1d] + 0x28)) {
                    iVar27 = iVar14;
                  }
                  iVar14 = iVar27;
                } while (plVar7 != (longlong *)0x0);
                if (0 < iVar27) {
                  LOCK();
                  piVar19 = (int *)(puVar15[0x1d] + 0x80);
                  *piVar19 = *piVar19 + iVar27;
                  UNLOCK();
                }
                NdisFSendNetBufferLists(*(undefined8 *)(puVar15[0x1d] + 0x28),plVar21);
                goto LAB_140001d52;
              }
              lVar24 = *(longlong *)((ulonglong)*(ushort *)(plVar21[2] + 10) + 0x30 + plVar21[2]) +
                       -0x18;
              plVar7 = plVar21;
              do {
                local_238 = (longlong *)*plVar7;
                if (local_238 == (longlong *)0x0) {
                  lVar18 = 0;
                }
                else {
                  lVar18 = *(longlong *)
                            ((ulonglong)*(ushort *)(local_238[2] + 10) + 0x30 + local_238[2]) +
                           -0x18;
                }
                if (lVar24 != lVar18) {
                  uVar5 = (ulonglong)uVar22;
                  *plVar7 = 0;
                  PcpLineSignalExternalEvent(lVar24,uVar5);
                  QosLineSendNetBufferLists
                            (lVar24 + 0x18,uVar5,plVar21,plVar7,&local_230,&local_228);
                  puVar15 = local_268;
                  if (local_230 != (longlong *)0x0) {
                    iVar14 = 0;
                    plVar7 = local_230;
                    do {
                      plVar21 = plVar7 + 0xf;
                      plVar7 = (longlong *)*plVar7;
                      iVar27 = iVar14 + 1;
                      if (*plVar21 != *(longlong *)(*(longlong *)(lVar24 + 0x100) + 0x28)) {
                        iVar27 = iVar14;
                      }
                      iVar14 = iVar27;
                    } while (plVar7 != (longlong *)0x0);
                    if (0 < iVar14) {
                      LOCK();
                      piVar19 = (int *)(*(longlong *)(lVar24 + 0x100) + 0x80);
                      *piVar19 = *piVar19 + iVar14;
                      UNLOCK();
                    }
                    NdisFSendNetBufferLists
                              (*(undefined8 *)(*(longlong *)(lVar24 + 0x100) + 0x28),local_230,0,0);
                    local_230 = (longlong *)0x0;
                  }
                  if (local_228 != (longlong *)0x0) {
                    iVar14 = 0;
                    plVar7 = local_228;
                    do {
                      plVar21 = plVar7 + 0xf;
                      plVar7 = (longlong *)*plVar7;
                      iVar27 = iVar14 + 1;
                      if (*plVar21 != *(longlong *)(*(longlong *)(lVar24 + 0x100) + 0x28)) {
                        iVar27 = iVar14;
                      }
                      iVar14 = iVar27;
                    } while (plVar7 != (longlong *)0x0);
                    if (0 < iVar14) {
                      LOCK();
                      piVar19 = (int *)(*(longlong *)(lVar24 + 0x100) + 0x80);
                      *piVar19 = *piVar19 + iVar14;
                      UNLOCK();
                    }
                    local_268 = puVar15;
                    PcpLineDropNblChain(lVar24,local_228);
                    local_228 = (longlong *)0x0;
                  }
                  plVar21 = local_238;
                  local_268 = puVar15;
                }
                lVar24 = lVar18;
                plVar7 = local_238;
              } while (local_238 != (longlong *)0x0);
              lVar24 = local_1d8;
            }
            if (local_1f8 != (longlong *)0x0) {
              PcpSchedulerBatchAndSendOrDropNblChain(local_1f8,uVar22,param_4,(longlong *)0x0);
            }
          }
          puVar15 = local_268;
          if (bVar34) {
            LOCK();
            piVar19 = (int *)(local_268 + 0x1f);
            iVar14 = *piVar19;
            *piVar19 = *piVar19 + -1;
            UNLOCK();
            if (iVar14 == 1) {
              if (local_268[0x28] != 0) {
                NdisFreeMemoryWithTag(local_268[0x28],0x616e6350);
              }
              if (puVar15[0x20] != 0) {
                PcpFilterDecrementDetachCount(puVar15[0x20]);
              }
              if (puVar15[2] != 0) {
                NdisFreeRWLock();
              }
              ExFreePoolWithTag(puVar15,0x656c6350);
            }
          }
        }
LAB_140001695:
        param_2 = plVar23;
      } while (plVar23 != (longlong *)0x0);
    }
    if (local_1b0 != (longlong *)0x0) {
      NdisFSendNetBufferLists(*(undefined8 *)(param_1 + 0x28),local_1b0,local_278[0],param_4);
    }
    uVar22 = local_248;
    lVar18 = _DAT_fffff78000000008;
    uVar13 = (ulonglong)local_248;
    local_178 = 0;
    local_188 = 0;
    uStack_180 = 0;
    plVar23 = (longlong *)(uVar13 * 0x80 + *QosgTimerTable);
    local_240 = 0;
    puVar6 = (ulonglong *)KeQueryPerformanceCounter(&local_240);
    uVar5 = ((ulonglong)puVar6 >> 0x20) * 1000000;
    bVar11 = *(byte *)(plVar23 + 0xe);
    lVar24 = ((uVar5 % local_240 << 0x20) + ((ulonglong)puVar6 & 0xffffffff) * 1000000) / local_240
             + (uVar5 / local_240 << 0x20);
    if (bVar11 == 0) {
      bVar4 = 2;
    }
    else {
      bVar4 = bVar11 - 1;
    }
    uVar5 = (ulonglong)bVar4;
    if (plVar23[uVar5 + 8] - lVar24 < 1) {
      plVar23[(ulonglong)bVar11 + 2] = (longlong)puVar6;
      plVar23[(ulonglong)bVar11 + 5] = local_240;
      plVar23[(ulonglong)bVar11 + 8] = lVar24;
    }
    else {
      plVar23[(ulonglong)bVar11 + 2] = plVar23[uVar5 + 2];
      plVar23[(ulonglong)bVar11 + 5] = plVar23[uVar5 + 5];
      plVar23[(ulonglong)bVar11 + 8] = plVar23[uVar5 + 8];
      lVar24 = plVar23[uVar5 + 8];
    }
    plVar23[(ulonglong)bVar11 + 0xb] = lVar18;
    plVar23[1] = lVar18;
    *plVar23 = lVar24;
    *(byte *)(plVar23 + 0xe) = (byte)((char)plVar23[0xe] + 1U) % 3;
    lVar18 = uVar13 * 0xc0 + PcgTimerUnits;
    bVar34 = PcgDisableRecursionFix != 0;
    if (bVar34) {
      *(int *)(lVar18 + 0x28) = *(int *)(lVar18 + 0x28) + -1;
    }
    if (*(uint *)(lVar18 + 0x28) == (uint)!bVar34) {
      KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar18);
      do {
      } while (*(int *)(lVar18 + 8) != 0);
      if (((*(uint *)(lVar18 + 0x2c) & 1) == 0) && (*(longlong *)(lVar18 + 0x18) - lVar24 < 1)) {
        KeReleaseInStackQueuedSpinLockFromDpcLevel();
        *(uint *)(lVar18 + 0x2c) = *(uint *)(lVar18 + 0x2c) | 2;
        puVar6 = (ulonglong *)0x0;
        PcpTimeoutHandler(0,lVar18,0,(longlong ****)0x0);
        *(uint *)(lVar18 + 0x2c) = *(uint *)(lVar18 + 0x2c) & 0xfffffffd;
      }
      else {
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_188);
      }
    }
    if (PcgDisableRecursionFix == 0) {
      *(int *)(lVar18 + 0x28) = *(int *)(lVar18 + 0x28) + -1;
    }
    lVar24 = PcgDelayQueue;
    lVar18 = uVar13 * 0x40;
    piVar19 = (int *)(lVar18 + 0x10 + PcgDelayQueue);
    *piVar19 = *piVar19 + -1;
    if (*piVar19 == 0) {
      puVar15 = *(undefined8 **)(lVar18 + lVar24);
      *(undefined8 *)(lVar18 + lVar24) = 0;
      *(undefined8 *)(lVar18 + 8 + lVar24) = 0;
      lVar24 = _DAT_fffff78000000008;
      local_d8 = 0;
      uStack_d0 = 0;
      local_c8 = 0;
      local_278[0] = local_278[0] & 0xff000000;
      plVar23 = (longlong *)(uVar13 * 0x80 + *QosgTimerTable);
      local_148 = 0;
      uStack_140 = 0;
      local_128 = 0;
      local_138 = 0;
      uStack_130 = 0;
      if (_DAT_fffff78000000008 != plVar23[1]) {
        local_240 = 0;
        uVar5 = KeQueryPerformanceCounter(&local_240);
        uVar13 = (uVar5 >> 0x20) * 1000000;
        bVar11 = *(byte *)(plVar23 + 0xe);
        lVar18 = ((uVar13 % local_240 << 0x20) + (uVar5 & 0xffffffff) * 1000000) / local_240 +
                 (uVar13 / local_240 << 0x20);
        if (bVar11 == 0) {
          bVar4 = 2;
        }
        else {
          bVar4 = bVar11 - 1;
        }
        uVar13 = (ulonglong)bVar4;
        if (plVar23[uVar13 + 8] - lVar18 < 1) {
          plVar23[(ulonglong)bVar11 + 2] = uVar5;
          plVar23[(ulonglong)bVar11 + 5] = local_240;
          plVar23[(ulonglong)bVar11 + 8] = lVar18;
        }
        else {
          plVar23[(ulonglong)bVar11 + 2] = plVar23[uVar13 + 2];
          plVar23[(ulonglong)bVar11 + 5] = plVar23[uVar13 + 5];
          plVar23[(ulonglong)bVar11 + 8] = plVar23[uVar13 + 8];
          lVar18 = plVar23[uVar13 + 8];
        }
        plVar23[(ulonglong)bVar11 + 0xb] = lVar24;
        bVar11 = (char)plVar23[0xe] + 1;
        *plVar23 = lVar18;
        plVar23[1] = lVar24;
        uVar28 = (uint)bVar11 + (bVar11 / 3) * -3;
        puVar6 = (ulonglong *)(ulonglong)uVar28;
        *(char *)(plVar23 + 0xe) = (char)uVar28;
      }
      lVar24 = *plVar23;
      while (puVar15 != (undefined8 *)0x0) {
        puVar29 = (undefined8 *)*puVar15;
        puVar10 = &local_d8;
        RtlAcquireWriteLockAtDpcLevel((longlong)(puVar15 + 7));
        *(uint *)(puVar15 + 0x48) = *(uint *)(puVar15 + 0x48) & 0xfffffffb;
        local_1c8 = (longlong *)0x0;
        local_1c0 = (longlong *)0x0;
        local_240 = local_240 & 0xffffffff00000000;
        if ((*(uint *)(puVar15 + 0x48) & 8) == 0) {
          uVar5 = QosFlowNeedQueueFeedback((longlong)(puVar15 + 0xc),lVar24,&local_148);
          if (((char)uVar5 != '\0') &&
             (puVar10 = PcpLineFindByLuid(puVar15[6]), puVar10 != (undefined8 *)0x0)) {
            PcpLineSignalExternalEvent((longlong)puVar10,(ulonglong)uVar22);
            puVar17 = local_278;
            NdisAcquireRWLockWrite(puVar10[2],puVar17,0);
            QosLineQueryQueueFeedback((longlong)(puVar10 + 3),puVar17,(uint *)&local_148);
            NdisReleaseRWLock(puVar10[2],local_278);
            PcpLineDereference((longlong)puVar10);
            QosTbcAdjustSendWindow((longlong)(puVar15 + 0xc),(longlong)&local_148);
          }
          puVar10 = (undefined8 *)(ulonglong)uVar22;
          puVar6 = &local_240;
          QosFlowProcessQueuedNetBufferLists((longlong)(puVar15 + 0xc),uVar22);
        }
        plVar7 = local_1c0;
        plVar23 = local_1c8;
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_d8);
        if (plVar23 != (longlong *)0x0) {
          puVar6 = (ulonglong *)CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
          puVar10 = (undefined8 *)(ulonglong)uVar22;
          PcpSchedulerBatchAndSendOrDropNblChain(plVar23,uVar22,0,(longlong *)puVar6);
        }
        if (plVar7 != (longlong *)0x0) {
          puVar6 = (ulonglong *)0x0;
          puVar10 = (undefined8 *)(ulonglong)uVar22;
          PcpSchedulerBatchAndSendOrDropNblChain(plVar7,uVar22,0,(longlong *)0x0);
        }
        PcpDereferenceFlow(puVar15 + -5,(ulonglong)puVar10);
        puVar15 = puVar29;
      }
    }
    if (bVar33) {
      KeLowerIrql(uVar3);
    }
  }
  else {
    for (; plVar23 != (longlong *)0x0; plVar23 = (longlong *)*plVar23) {
      *(undefined4 *)((longlong)plVar23 + 0x8c) = 0xc023002a;
    }
    NdisFSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2,param_4);
  }
  return;
}



===== QosTbcSendNetBufferList @ 140002ac0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong QosTbcSendNetBufferList
                    (int *param_1,uint param_2,undefined8 *param_3,longlong param_4,uint param_5,
                    int param_6,byte param_7,longlong *param_8,longlong *param_9)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  int *piVar9;
  ulonglong uVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint uVar15;
  ulonglong *puVar16;
  longlong lVar17;
  longlong *plVar18;
  longlong *plVar19;
  ulonglong uVar20;
  longlong *plVar21;
  undefined8 *puVar22;
  int iVar23;
  bool bVar24;
  undefined1 auStackY_248 [8];
  undefined1 auStackY_240 [24];
  ulonglong **in_stack_fffffffffffffdd8;
  uint local_1f8;
  uint local_1f4;
  ulonglong *local_1f0;
  uint local_1e8 [2];
  ulonglong local_1e0;
  longlong *local_1d8;
  undefined8 *local_1d0;
  uint local_1c8;
  int local_1c4;
  int local_1c0 [2];
  longlong local_1b8;
  ulonglong local_1b0;
  undefined8 local_1a8;
  ulonglong *local_1a0;
  longlong *local_198;
  longlong local_190;
  longlong *local_188;
  ulonglong local_180;
  undefined8 uStack_178;
  ulonglong **local_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  longlong local_148;
  undefined4 local_140;
  ulonglong *local_13c;
  ulonglong *local_134;
  ulonglong *local_12c;
  ulonglong *local_124;
  ulonglong *local_11c;
  ulonglong *local_114;
  ulonglong *local_10c;
  ulonglong *local_104;
  undefined4 local_fc;
  ulonglong local_f8 [20];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_248;
  uVar20 = (ulonglong)param_5;
  local_188 = param_8;
  local_1f8 = param_5;
  local_1d8 = param_9;
  local_1c8 = 0;
  local_190 = 0;
  local_198 = (longlong *)0x0;
  local_1e8[0] = 0;
  local_1c0[0] = 0;
  local_1a8 = 0;
  local_1c4 = 0;
  local_158 = 0;
  local_1a0 = (ulonglong *)0x0;
  *(undefined8 **)(param_4 + 0x60) = param_3;
  local_168 = 0;
  uStack_160 = 0;
  local_1d0 = param_3;
  local_1b8 = param_4;
  if (param_5 < 6) {
    local_1f0 = local_f8;
LAB_140002b75:
    puVar8 = local_1f0;
    puVar13 = auStackY_248;
    memset(local_1f0,0,uVar20 << 5);
    uVar5 = _DAT_fffff78000000008;
    uVar10 = 0;
    for (puVar22 = *(undefined8 **)(param_4 + 8); puVar22 != (undefined8 *)0x0;
        puVar22 = (undefined8 *)*puVar22) {
      *(undefined4 *)(uVar10 * 0x20 + 0x1c + (longlong)puVar8) = *(undefined4 *)(puVar22 + 3);
      uVar10 = (ulonglong)((int)uVar10 + 1);
    }
    puVar16 = (ulonglong *)((ulonglong)param_2 * 0x80 + *QosgTimerTable);
    if (_DAT_fffff78000000008 != puVar16[1]) {
      local_1b0 = 0;
      uVar7 = KeQueryPerformanceCounter(&local_1b0);
      uVar10 = (uVar7 >> 0x20) * 1000000;
      bVar1 = (byte)puVar16[0xe];
      uVar10 = ((uVar7 & 0xffffffff) * 1000000 + (uVar10 % local_1b0 << 0x20)) / local_1b0 +
               (uVar10 / local_1b0 << 0x20);
      if (bVar1 == 0) {
        bVar3 = 2;
      }
      else {
        bVar3 = bVar1 - 1;
      }
      uVar12 = (ulonglong)bVar3;
      if ((longlong)(puVar16[uVar12 + 8] - uVar10) < 1) {
        puVar16[(ulonglong)bVar1 + 2] = uVar7;
        puVar16[(ulonglong)bVar1 + 5] = local_1b0;
        puVar16[(ulonglong)bVar1 + 8] = uVar10;
      }
      else {
        puVar16[(ulonglong)bVar1 + 2] = puVar16[uVar12 + 2];
        puVar16[(ulonglong)bVar1 + 5] = puVar16[uVar12 + 5];
        puVar16[(ulonglong)bVar1 + 8] = puVar16[uVar12 + 8];
        uVar10 = puVar16[uVar12 + 8];
      }
      puVar16[(ulonglong)bVar1 + 0xb] = uVar5;
      *puVar16 = uVar10;
      puVar16[1] = uVar5;
      *(byte *)(puVar16 + 0xe) = (byte)((char)puVar16[0xe] + 1U) % 3;
    }
    uVar10 = *puVar16;
    uVar5 = 0;
    LOCK();
    bVar24 = QosgLastSendBoundary == 0;
    if (bVar24) {
      QosgLastSendBoundary = uVar10;
    }
    else {
      uVar5 = QosgLastSendBoundary;
    }
    UNLOCK();
    if (bVar24) {
      uVar5 = uVar10;
    }
    else if (uVar10 < uVar5) {
      uVar10 = uVar5;
    }
    uVar7 = (ulonglong)QosgBoundaryPeriod;
    local_1e0 = (uVar7 - ((uVar7 - uVar5) + uVar10) % uVar7) + uVar10;
    if (*(char *)((longlong)param_1 + 0x5d) == '\0') {
      piVar9 = (int *)*QosgEtwDispatchTable;
      if (*piVar9 == 1) {
        piVar9 = param_1;
        QosTraceFlowConformance((longlong)param_1,uVar10,3);
      }
      local_180 = *(ulonglong *)(param_1 + 0x22);
      uStack_178 = *(undefined8 *)(param_1 + 0x24);
      uVar7 = *(ulonglong *)(param_1 + 0x1c);
      local_170 = *(ulonglong ***)(param_1 + 0x26);
      if (uVar7 < uVar10) {
        QosUtilComputeTokenSpec((longlong *)&local_180,uVar10 - uVar7);
        piVar9 = (int *)(ulonglong)(uint)param_1[0x22];
        param_1[0x20] = param_1[0x22];
        *puVar8 = uVar10;
      }
      else {
        *puVar8 = uVar7;
        local_180 = (ulonglong)(uint)param_1[0x20];
      }
      in_stack_fffffffffffffdd8 = local_170;
      uVar14 = QosComputeNetBufferConformanceTime
                         (piVar9,param_4,(longlong *)puVar8,(uint)local_180,(ulonglong)local_170,
                          uVar10,&local_1c8);
      iVar23 = param_5 - uVar14;
      param_1[0x2b] = param_1[0x2b] + iVar23;
      LOCK();
      *(int *)((longlong)local_1d0 + 0x54) = *(int *)((longlong)local_1d0 + 0x54) + iVar23;
      UNLOCK();
      QosUpdateGenerationOverQuota
                (uVar10,iVar23 != 0,(ulonglong *)(param_1 + 0x3e),(ulonglong *)(param_1 + 0x40));
      if ((param_1[0x16] != 2) || (param_5 <= uVar14)) {
        local_168 = *(undefined8 *)(param_1 + 0x22);
        uStack_160 = *(undefined8 *)(param_1 + 0x24);
        local_1a8 = *(undefined8 *)(param_1 + 0x1c);
        local_158 = *(undefined8 *)(param_1 + 0x26);
        local_1c4 = param_1[0x20];
        local_1a0 = *(ulonglong **)(param_1 + 0x1e);
        *(ulonglong *)(param_1 + 0x1c) = puVar8[(ulonglong)(param_5 - 1) * 4];
        *(ulonglong *)(param_1 + 0x22) = local_180;
        *(undefined8 *)(param_1 + 0x24) = uStack_178;
        param_1[0x20] = local_1c8;
        *(ulonglong ***)(param_1 + 0x26) = local_170;
        *(ulonglong *)(param_1 + 0x22) = (ulonglong)local_1c8;
        if (*(int *)*QosgEtwDispatchTable == 1) {
          QosTraceFlowConformance((longlong)param_1,uVar10,4);
        }
        goto LAB_140002c2d;
      }
      iVar23 = 0;
LAB_140003303:
      QosTbcDropNbl((longlong)param_1,local_1d8,param_4,param_5,param_5,iVar23);
      puVar16 = local_f8;
      if (puVar8 != local_f8) {
LAB_140002d5e:
LAB_140002d61:
        puVar16 = (ulonglong *)ExFreePoolWithTag(puVar8,0);
      }
    }
    else {
      if (param_5 != 0) {
        puVar16 = puVar8;
        uVar7 = uVar20;
        do {
          *puVar16 = uVar10;
          puVar16 = puVar16 + 4;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
LAB_140002c2d:
      if (*(longlong *)(param_1 + 0x28) == -1) {
        if (param_5 == 0) goto LAB_140002dde;
        puVar16 = puVar8 + 2;
        uVar7 = uVar20;
        do {
          puVar16[-1] = puVar16[-2];
          *puVar16 = puVar16[-2];
          puVar16 = puVar16 + 4;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
LAB_140002c65:
        iVar23 = 0;
        uVar14 = 0;
        puVar16 = puVar8 + 2;
        do {
          uVar7 = *puVar16;
          if (uVar7 < local_1e0) {
            uVar14 = uVar14 + 1;
            iVar23 = iVar23 + *(int *)((longlong)puVar16 + 0xc);
            uVar7 = uVar10;
          }
          else {
            uVar7 = uVar7 - (uVar7 - uVar5) % (ulonglong)QosgBoundaryPeriod;
          }
          *puVar16 = uVar7;
          uVar20 = uVar20 - 1;
          puVar16 = puVar16 + 4;
        } while (uVar20 != 0);
      }
      else {
        uVar7 = *(ulonglong *)(param_1 + 0x1e);
        if (*(ulonglong *)(param_1 + 0x1e) < uVar10) {
          uVar7 = uVar10;
        }
        puVar8[1] = uVar7;
        QosComputeNetBufferPeakConformanceTime
                  (*(ulonglong *)(param_1 + 0x28),param_5,uVar10,(longlong)puVar8);
        *(ulonglong *)(param_1 + 0x1e) =
             ((ulonglong)*(uint *)((ulonglong)(param_5 - 1) * 0x20 + 0x1c + (longlong)puVar8) *
             1000000) / *(ulonglong *)(param_1 + 0x28) + puVar8[(ulonglong)(param_5 - 1) * 4 + 1];
LAB_140002dde:
        uVar14 = 0;
        iVar23 = 0;
        if (param_5 != 0) goto LAB_140002c65;
      }
      if (param_1[0x50] != 0) {
        param_1[0x55] = param_1[0x55] + iVar23;
        if (uVar14 == 0) {
          iVar4 = 0;
          local_1f4 = 0;
          uVar6 = 0;
        }
        else if ((param_1[0x68] & 2U) == 0) {
          uVar6 = QosTbcComputeNbsToDrop((longlong)param_1,uVar14);
          uVar15 = 0;
          iVar4 = 0;
          local_1f4 = 0;
          if (uVar14 != uVar6) {
            do {
              uVar20 = (ulonglong)uVar15;
              uVar15 = uVar15 + 1;
              iVar4 = iVar4 + *(int *)(uVar20 * 0x20 + 0x1c + (longlong)local_1f0);
              local_1f4 = uVar15;
            } while (uVar15 < uVar14 - uVar6);
          }
        }
        else {
          iVar4 = QosTbcComputeNbsToDrop((longlong)param_1,1);
          uVar6 = iVar4 * local_1f8;
          iVar4 = (1 - iVar4) * param_6;
          local_1f4 = local_1f8 - uVar6;
        }
        uVar14 = local_1f4;
        if (param_1[0x53] == 1) {
LAB_14000343d:
          puVar8 = local_1f0;
          param_5 = local_1f8;
          goto LAB_140002caf;
        }
        if (uVar6 != 0) {
          in_stack_fffffffffffffdd8 =
               (ulonglong **)CONCAT44((int)((ulonglong)in_stack_fffffffffffffdd8 >> 0x20),uVar6);
          QosTbcDropNbl((longlong)param_1,local_1d8,local_1b8,local_1f8,uVar6,7);
        }
        param_1[0x4b] = param_1[0x4b] + (iVar23 - iVar4);
        if (uVar6 != local_1f8) goto LAB_14000343d;
        puVar16 = local_f8;
        if (local_1f0 == puVar16) goto LAB_140002d6f;
        puVar8 = local_1f0;
        goto LAB_140002d61;
      }
      local_1f4 = uVar14;
LAB_140002caf:
      local_1f0 = *(ulonglong **)(param_1 + 0x38);
      local_1f8 = param_1[0x3a];
      if (param_1[0x35] != 0) {
        in_stack_fffffffffffffdd8 = &local_1f0;
        QosTbcFrontalSpread(uVar10,local_1e0,param_1[0x35],param_1[0x36],
                            (ulonglong *)in_stack_fffffffffffffdd8,&local_1f8,(longlong)puVar8,
                            param_5,(int *)&local_1f4);
        uVar14 = local_1f4;
      }
      param_4 = local_1b8;
      if (((param_1[0x16] == 1) && (uVar10 < puVar8[(ulonglong)(param_5 - 1) * 4 + 2])) &&
         (*(ulonglong *)(param_1 + 0x3c) < puVar8[(ulonglong)(param_5 - 1) * 4 + 2] - uVar10)) {
        QosTbcDropNbl((longlong)param_1,local_1d8,local_1b8,param_5,param_5,1);
        if (puVar8 != local_f8) {
          ExFreePoolWithTag(puVar8,0);
        }
        *(undefined8 *)(param_1 + 0x1c) = local_1a8;
        param_1[0x20] = local_1c4;
        *(undefined8 *)(param_1 + 0x22) = local_168;
        *(undefined8 *)(param_1 + 0x24) = uStack_160;
        *(ulonglong **)(param_1 + 0x1e) = local_1a0;
        *(undefined8 *)(param_1 + 0x26) = local_158;
        puVar16 = local_1a0;
      }
      else {
        if (((char)param_1[0x17] != '\0') && (uVar14 != param_5)) {
          iVar23 = 0;
          if (param_1[0x16] != 2) {
            iVar23 = -1;
          }
          uVar5 = QosConstructNetBufferListToSend
                            (local_1d0,local_1b8,(longlong)puVar8,uVar14,in_stack_fffffffffffffdd8,
                             iVar23,param_7 & 1,&local_190,(longlong *)&local_198);
          uVar20 = local_1e0;
          if (-1 < (int)uVar5) {
            uVar6 = param_1[0x34] + uVar14;
            param_1[0x34] = uVar6;
            if ((uint)param_1[0x2c] < uVar6) {
              param_1[0x2c] = uVar6;
            }
            LOCK();
            piVar9 = (int *)(local_1d0 + 6);
            iVar23 = *piVar9;
            *piVar9 = *piVar9 + uVar14;
            UNLOCK();
            if (*(uint *)(local_1d0 + 0xb) < iVar23 + local_1f4) {
              LOCK();
              if (*(uint *)(local_1d0 + 0xb) == *(uint *)(local_1d0 + 0xb)) {
                *(uint *)(local_1d0 + 0xb) = iVar23 + local_1f4;
              }
              UNLOCK();
            }
            iVar23 = 0;
            uVar5 = 0;
            *(ulonglong **)(param_1 + 0x38) = local_1f0;
            param_1[0x3a] = local_1f8;
            if (local_198 != (longlong *)0x0) {
              plVar11 = local_198;
              plVar19 = local_198;
              iVar23 = 0;
              do {
                lVar17 = (ulonglong)*(ushort *)(plVar11[2] + 10) + plVar11[2];
                *(int *)(lVar17 + 0x60) = param_1[0x20];
                *(undefined8 *)(lVar17 + 0x68) = *(undefined8 *)(param_1 + 0x1c);
                *(undefined8 *)(lVar17 + 0x70) = *(undefined8 *)(param_1 + 0x1e);
                *(undefined8 *)(lVar17 + 0x78) = *(undefined8 *)(param_1 + 0x22);
                *(int *)(lVar17 + 0x50) = *param_1;
                plVar11[0xc] = (longlong)local_1d0;
                plVar21 = (longlong *)*plVar11;
                *plVar11 = 0;
                bVar24 = *(ulonglong *)(lVar17 + 0x58) < uVar20;
                *(bool *)(lVar17 + 0x3d) = bVar24;
                if (((!bVar24) || (param_1[0x50] == 0)) || (param_1[0x53] != 2)) {
                  plVar11 = *(longlong **)(param_1 + 0x1a);
                  plVar18 = (longlong *)(lVar17 + 0x40);
                  if ((int *)*plVar11 != param_1 + 0x18) {
                    pcVar2 = (code *)swi(0x29);
                    (*pcVar2)(3);
                    puVar13 = auStackY_240;
                    goto LAB_140003511;
                  }
                  *(longlong **)(lVar17 + 0x48) = plVar11;
                  *plVar18 = (longlong)(param_1 + 0x18);
                  uVar5 = 1;
                  *plVar11 = (longlong)plVar18;
                  *(longlong **)(param_1 + 0x1a) = plVar18;
                  QosGetNetBufferCount((longlong)plVar19,local_1c0);
                  iVar23 = iVar23 + local_1c0[0];
                }
                else {
                  *local_1d8 = (longlong)plVar11;
                  local_1d8 = plVar11;
                }
                plVar11 = plVar21;
              } while (plVar11 != (longlong *)0x0);
            }
            if (local_190 == 0) {
LAB_140003511:
              uVar14 = *(uint *)(puVar13 + 0x60);
            }
            else {
              param_1[0x31] = param_1[0x31] + 1;
              lVar17 = local_190;
              puVar22 = local_1d0;
              iVar4 = QosGetNetBufferCount(local_190,(int *)local_1e8);
              param_1[3] = param_1[3] + iVar4;
              *(ulonglong *)(param_1 + 6) = *(longlong *)(param_1 + 6) + (ulonglong)local_1e8[0];
              param_1[0x4a] = param_1[0x4a] + local_1e8[0];
              *(undefined8 **)(lVar17 + 0x60) = puVar22;
              *local_188 = lVar17;
              puVar13 = auStackY_248;
              uVar14 = local_1e8[0];
            }
            if (*(int *)*QosgEtwDispatchTable == 1) {
              *(int *)(puVar13 + 0x30) = iVar23;
              *(uint *)(puVar13 + 0x28) = uVar14;
              *(int *)(puVar13 + 0x20) = param_6;
              *(undefined8 *)(puVar13 + -8) = 0x140003544;
              QosTraceFlowSendQueue
                        ((longlong)param_1,1,uVar10,0,*(undefined4 *)(puVar13 + 0x20),
                         *(undefined4 *)(puVar13 + 0x28),*(undefined4 *)(puVar13 + 0x30));
            }
            if (puVar8 != local_f8) {
              *(undefined8 *)(puVar13 + -8) = 0x140003559;
              ExFreePoolWithTag(puVar8,0);
            }
            goto LAB_140002d71;
          }
          iVar23 = 3;
          goto LAB_140003303;
        }
        param_1[0x2f] = param_1[0x2f] + 1;
        iVar23 = 0;
        param_1[0x2e] = param_1[0x2e] + 1;
        uVar20 = 0;
        param_1[0x31] = param_1[0x31] + 1;
        for (puVar22 = *(undefined8 **)(local_1b8 + 8); iVar4 = (int)uVar20,
            puVar22 != (undefined8 *)0x0; puVar22 = (undefined8 *)*puVar22) {
          uVar20 = (ulonglong)(uint)(iVar4 + *(int *)(puVar22 + 3));
          iVar23 = iVar23 + 1;
        }
        param_1[3] = param_1[3] + iVar23;
        param_1[0x4a] = param_1[0x4a] + iVar4;
        *(ulonglong *)(param_1 + 6) = *(longlong *)(param_1 + 6) + uVar20;
        if (*(int *)*QosgEtwDispatchTable == 1) {
          QosTraceFlowSendQueue((longlong)param_1,1,uVar10,0,iVar4,iVar4,0);
        }
        *(undefined8 **)(param_4 + 0x60) = local_1d0;
        *local_188 = param_4;
        puVar16 = local_f8;
        if (puVar8 != local_f8) goto LAB_140002d5e;
      }
    }
  }
  else {
    local_1f0 = (ulonglong *)ExAllocatePool2(0x40,uVar20 << 5,0x74626e51);
    if (local_1f0 != (ulonglong *)0x0) goto LAB_140002b75;
    local_fc = 0;
    puVar16 = (ulonglong *)*QosgEtwDispatchTable;
    if ((int)*puVar16 == 1) {
      local_140 = 2;
      local_148 = param_4;
      local_13c = local_1f0;
      local_134 = local_1f0;
      local_12c = local_1f0;
      local_124 = local_1f0;
      local_11c = local_1f0;
      local_114 = local_1f0;
      local_10c = local_1f0;
      local_104 = local_1f0;
      puVar16 = (ulonglong *)(*(code *)QosgEtwDispatchTable[5])(&local_148);
    }
    *(undefined4 *)(param_4 + 0x8c) = 0xc000009a;
    param_1[1] = param_1[1] + param_5;
    *param_9 = param_4;
  }
LAB_140002d6f:
  puVar13 = auStackY_248;
  uVar5 = (ulonglong)puVar16 & 0xffffffffffffff00;
LAB_140002d71:
  *(undefined8 *)(puVar13 + -8) = 0x140002d80;
  return uVar5;
}



===== RtlAcquireWriteLockAtDpcLevel @ 1400035a0 =====

void RtlAcquireWriteLockAtDpcLevel(longlong param_1)

{
  KeAcquireInStackQueuedSpinLockAtDpcLevel();
  do {
  } while (*(int *)(param_1 + 8) != 0);
  return;
}



===== QosComputeNetBufferPeakConformanceTime @ 1400035cc =====

int QosComputeNetBufferPeakConformanceTime
              (ulonglong param_1,uint param_2,ulonglong param_3,longlong param_4)

{
  uint *puVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  int iVar6;
  ulonglong uVar7;
  
  uVar7 = *(ulonglong *)(param_4 + 8);
  iVar6 = 0;
  if (param_2 != 0) {
    puVar5 = (ulonglong *)(param_4 + 0x10);
    uVar4 = (ulonglong)param_2;
    do {
      puVar5[-1] = uVar7;
      uVar3 = uVar7;
      if (uVar7 <= puVar5[-2]) {
        uVar3 = puVar5[-2];
      }
      *puVar5 = uVar3;
      puVar1 = (uint *)((longlong)puVar5 + 0xc);
      puVar5 = puVar5 + 4;
      iVar2 = iVar6 + 1;
      if (param_3 < uVar3) {
        iVar2 = iVar6;
      }
      iVar6 = iVar2;
      uVar7 = uVar7 + ((ulonglong)*puVar1 * 1000000) / param_1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar6;
}



===== QosUpdateGenerationOverQuota @ 140003640 =====

undefined8
QosUpdateGenerationOverQuota(ulonglong param_1,byte param_2,ulonglong *param_3,ulonglong *param_4)

{
  undefined1 auVar1 [16];
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = *param_3;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_1;
  uVar2 = param_1 / 600000 - *param_4;
  if (uVar2 != 0) {
    if (uVar2 < 0x40) {
      uVar3 = uVar3 << ((byte)uVar2 & 0x3f);
    }
    else {
      uVar3 = 0;
    }
    *param_4 = param_1 / 600000;
  }
  *param_3 = param_2 | uVar3;
  return SUB168(ZEXT816(0xdfb23b0979b4b02f) * auVar1,0);
}



===== QosComputeNetBufferConformanceTime @ 140003680 =====

int QosComputeNetBufferConformanceTime
              (undefined8 param_1,longlong param_2,longlong *param_3,uint param_4,ulonglong param_5,
              longlong param_6,uint *param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong lVar6;
  
  uVar3 = 0;
  puVar4 = *(undefined8 **)(param_2 + 8);
  lVar5 = *param_3;
  iVar2 = 0;
  *param_7 = param_4;
  for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4) {
    uVar1 = *(uint *)(puVar4 + 3);
    if (param_4 < uVar1) {
      lVar6 = ((ulonglong)(uVar1 - param_4) * 1000000) / param_5 + lVar5;
      param_3[(ulonglong)uVar3 * 4] = lVar6;
      if ((lVar6 == lVar5) && (lVar5 == param_6)) {
        iVar2 = iVar2 + 1;
      }
      param_4 = 0;
    }
    else {
      iVar2 = iVar2 + 1;
      param_3[(ulonglong)uVar3 * 4] = lVar5;
      param_4 = param_4 - uVar1;
      lVar6 = lVar5;
    }
    *param_7 = param_4;
    uVar3 = uVar3 + 1;
    lVar5 = lVar6;
  }
  return iVar2;
}



===== QosUtilComputeTokenSpec @ 140003718 =====

void QosUtilComputeTokenSpec(longlong *param_1,longlong param_2)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  longlong lVar3;
  ulonglong uVar4;
  
  if (param_1[2] == -1) {
    uVar4 = 0;
  }
  else {
    uVar4 = param_1[2] * param_2;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar4;
    lVar3 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);
    uVar4 = (uVar4 - lVar3 >> 1) + lVar3 >> 9;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar4;
    lVar3 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar2,8);
    uVar4 = (uVar4 - lVar3 >> 1) + lVar3 >> 9;
  }
  lVar3 = *param_1 + uVar4;
  if ((lVar3 < *param_1) || (*param_1 = lVar3, param_1[1] < lVar3)) {
    *param_1 = param_1[1];
  }
  return;
}



===== PcpLineSignalExternalEvent @ 140003780 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpLineSignalExternalEvent(longlong param_1,ulonglong param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  longlong lVar4;
  byte bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong lVar9;
  ulonglong local_res8;
  undefined2 local_res10;
  undefined1 local_res12;
  
  lVar4 = _DAT_fffff78000000008;
  local_res10 = 0;
  local_res12 = 0;
  plVar8 = (longlong *)((param_2 & 0xffffffff) * 0x80 + *QosgTimerTable);
  if (_DAT_fffff78000000008 != plVar8[1]) {
    local_res8 = 0;
    uVar6 = KeQueryPerformanceCounter(&local_res8);
    uVar7 = (uVar6 >> 0x20) * 1000000;
    bVar3 = *(byte *)(plVar8 + 0xe);
    lVar9 = ((uVar7 % local_res8 << 0x20) + (uVar6 & 0xffffffff) * 1000000) / local_res8 +
            (uVar7 / local_res8 << 0x20);
    if (bVar3 == 0) {
      bVar5 = 2;
    }
    else {
      bVar5 = bVar3 - 1;
    }
    uVar7 = (ulonglong)bVar5;
    if (plVar8[uVar7 + 8] - lVar9 < 1) {
      plVar8[(ulonglong)bVar3 + 2] = uVar6;
      plVar8[(ulonglong)bVar3 + 5] = local_res8;
      plVar8[(ulonglong)bVar3 + 8] = lVar9;
    }
    else {
      plVar8[(ulonglong)bVar3 + 2] = plVar8[uVar7 + 2];
      plVar8[(ulonglong)bVar3 + 5] = plVar8[uVar7 + 5];
      plVar8[(ulonglong)bVar3 + 8] = plVar8[uVar7 + 8];
      lVar9 = plVar8[uVar7 + 8];
    }
    plVar8[(ulonglong)bVar3 + 0xb] = lVar4;
    *plVar8 = lVar9;
    plVar8[1] = lVar4;
    *(byte *)(plVar8 + 0xe) = (byte)((char)plVar8[0xe] + 1U) % 3;
  }
  if ((*(longlong *)(param_1 + 0xc0) - *plVar8 < 1) || (*(longlong *)(param_1 + 0xb8) - *plVar8 < 1)
     ) {
    LOCK();
    piVar1 = (int *)(param_1 + 0x98);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x10),&local_res10,0);
      QosLineSignalExternalEvent(param_1 + 0x18,param_2 & 0xffffffff);
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res10);
    }
  }
  return;
}



===== PcpSchedulerCompletePacket @ 140003930 =====

void PcpSchedulerCompletePacket
               (longlong param_1,longlong param_2,longlong param_3,undefined4 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  longlong local_res8;
  longlong local_38 [4];
  
  plVar3 = local_38;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x60);
  do {
  } while (*(int *)(param_1 + 0x68) != 0);
  iVar4 = 0;
  local_res8 = param_3;
  if ((*(longlong *)(param_3 + 0x78) == *(longlong *)(param_2 + 0x38)) &&
     (*(int *)((ulonglong)*(ushort *)(*(longlong *)(param_3 + 0x10) + 10) + 0x38 +
              *(longlong *)(param_3 + 0x10)) == 0)) {
    plVar3 = &local_res8;
    QosNblCadComplete(param_3,plVar3,(byte)param_4 & 1);
    iVar4 = 1;
  }
  lVar2 = local_res8;
  if (local_res8 != 0) {
    LOCK();
    *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
    UNLOCK();
  }
  KeReleaseInStackQueuedSpinLock(local_38);
  if (lVar2 != 0) {
    if ((*(int *)(*(longlong *)(param_2 + 0x100) + 0x10) == 3) &&
       (*(short *)(*(longlong *)(param_2 + 0x100) + 0xd4) == 0x800)) {
      PcpLineDereference(param_2);
      plVar3 = (longlong *)0x8;
      NdisFreeNetBufferListContext(lVar2);
    }
    plVar1 = *(longlong **)(lVar2 + 0xa8);
    if ((plVar1 != (longlong *)0x0) && (plVar1 == PcgDefaultFlow)) {
      PcpDereferenceFlow(plVar1,(ulonglong)plVar3);
      *(undefined8 *)(lVar2 + 0xa8) = 0;
    }
    NdisFSendNetBufferListsComplete
              (*(undefined8 *)(*(longlong *)(param_2 + 0x100) + 0x28),lVar2,param_4);
  }
  if (iVar4 != 0) {
    PcpFilterDecrementPauseCount(*(longlong *)(param_2 + 0x100),iVar4);
  }
  return;
}



===== PcFilterSendNetBufferListsComplete @ 140003ab0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcFilterSendNetBufferListsComplete(ulonglong param_1,longlong *param_2,uint param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  undefined8 *puVar11;
  byte bVar12;
  ulonglong uVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong **pplVar16;
  longlong lVar17;
  uint uVar18;
  longlong lVar19;
  longlong *plVar20;
  bool bVar21;
  ulonglong local_res8;
  undefined1 local_res10;
  char local_res18;
  undefined2 local_res20;
  undefined1 local_res22;
  ulonglong local_138;
  longlong *local_130;
  longlong *local_128;
  longlong local_120;
  ulonglong local_118;
  undefined8 local_110;
  longlong local_108;
  longlong *local_100;
  longlong *local_f8;
  longlong *local_f0;
  longlong *plStack_e8;
  undefined8 local_e0;
  longlong local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  longlong *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  
  local_res10 = 0;
  local_80 = 0;
  local_e0 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_f0 = (longlong *)0x0;
  plStack_e8 = (longlong *)0x0;
  local_res8 = param_1;
  if ((param_3 & 1) == 0) {
    local_res18 = '\0';
    local_res10 = KfRaiseIrql(2);
  }
  else {
    local_res18 = '\x01';
  }
  uVar7 = KeGetCurrentProcessorNumberEx(0);
  lVar15 = _DAT_fffff78000000008;
  local_d8 = (ulonglong)uVar7 * 0x80;
  plVar20 = (longlong *)(*QosgTimerTable + local_d8);
  local_118 = 0;
  uVar9 = KeQueryPerformanceCounter(&local_118);
  uVar13 = (uVar9 >> 0x20) * 1000000;
  bVar12 = *(byte *)(plVar20 + 0xe);
  lVar17 = ((uVar13 % local_118 << 0x20) + (uVar9 & 0xffffffff) * 1000000) / local_118 +
           (uVar13 / local_118 << 0x20);
  if (bVar12 == 0) {
    bVar6 = 2;
  }
  else {
    bVar6 = bVar12 - 1;
  }
  uVar13 = (ulonglong)bVar6;
  if (plVar20[uVar13 + 8] - lVar17 < 1) {
    plVar20[(ulonglong)bVar12 + 2] = uVar9;
    plVar20[(ulonglong)bVar12 + 5] = local_118;
    plVar20[(ulonglong)bVar12 + 8] = lVar17;
  }
  else {
    plVar20[(ulonglong)bVar12 + 2] = plVar20[uVar13 + 2];
    plVar20[(ulonglong)bVar12 + 5] = plVar20[uVar13 + 5];
    plVar20[(ulonglong)bVar12 + 8] = plVar20[uVar13 + 8];
    lVar17 = plVar20[uVar13 + 8];
  }
  plVar20[(ulonglong)bVar12 + 0xb] = lVar15;
  plVar20[1] = lVar15;
  *plVar20 = lVar17;
  local_110 = 0;
  local_108 = 0;
  *(byte *)(plVar20 + 0xe) = (byte)((char)plVar20[0xe] + 1U) % 3;
  IoGetStackLimits(&local_108,&local_110);
  bVar21 = 0x2000 < (ulonglong)((longlong)&local_110 - local_108);
  if (bVar21) {
    piVar1 = (int *)((ulonglong)uVar7 * 0x40 + 0x10 + PcgDelayQueue);
    *piVar1 = *piVar1 + 1;
    piVar1 = (int *)((ulonglong)uVar7 * 0xc0 + 0x28 + PcgTimerUnits);
    *piVar1 = *piVar1 + 1;
  }
  local_120 = 0;
  lVar15 = 0;
  if (param_2 != (longlong *)0x0) {
    plVar20 = plStack_e8;
    do {
      plVar2 = (longlong *)*param_2;
      *param_2 = 0;
      lVar3 = param_2[0x15];
      if (lVar3 == 0) {
        if (plVar20 == (longlong *)0x0) {
          plVar14 = local_f0;
          local_f0 = param_2;
        }
        else {
          plVar14 = (longlong *)*plVar20;
          *plVar20 = (longlong)param_2;
        }
        *param_2 = (longlong)plVar14;
        if (plVar14 == (longlong *)0x0) {
          plVar20 = param_2;
          plStack_e8 = param_2;
        }
      }
      else {
        if ((*(int *)(local_res8 + 0x10) == 3) && (*(short *)(local_res8 + 0xd4) == 0x800)) {
          lVar19 = (ulonglong)*(ushort *)(param_2[2] + 10) + param_2[2];
          if (param_2[0xf] == *(longlong *)(local_res8 + 0x28)) {
            lVar19 = *(longlong *)(lVar19 + 0x30) + -0x18;
          }
          else {
            lVar19 = *(longlong *)(lVar19 + 0x10);
          }
        }
        else {
          lVar19 = *(longlong *)(local_res8 + 0xa0);
        }
        if (lVar3 != lVar15) {
          local_120 = lVar3;
          KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar3 + 0x60,&local_90);
          do {
          } while (*(int *)(lVar3 + 0x68) != 0);
          if (((*(uint *)(lVar3 + 0x54) != uVar7) &&
              (plVar20 = *(longlong **)(lVar3 + 0xe8), plVar20 != (longlong *)(lVar3 + 0xe8))) &&
             (plVar20[3] - lVar17 < 1)) {
            PcpFlowDelay(lVar3,uVar7);
          }
          KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_90);
        }
        local_res20 = 0;
        local_res22 = 0;
        local_130 = (longlong *)(local_d8 + *QosgTimerTable);
        if (_DAT_fffff78000000008 != local_130[1]) {
          QosTimerConvertPerformanceCounterToMicroseconds(local_130,_DAT_fffff78000000008);
        }
        if ((*(longlong *)(lVar19 + 0xc0) - *local_130 < 1) ||
           (*(longlong *)(lVar19 + 0xb8) - *local_130 < 1)) {
          LOCK();
          piVar1 = (int *)(lVar19 + 0x98);
          iVar8 = *piVar1;
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          if (iVar8 == 0) {
            NdisAcquireRWLockWrite(*(undefined8 *)(lVar19 + 0x10),&local_res20,0);
            QosLineSignalExternalEvent(lVar19 + 0x18,(ulonglong)uVar7);
            NdisReleaseRWLock(*(undefined8 *)(lVar19 + 0x10),&local_res20);
          }
        }
        lVar15 = lVar19;
        iVar8 = QosGetNblChainDataLength(param_2);
        LOCK();
        *(int *)(lVar15 + 0xa0) = *(int *)(lVar15 + 0xa0) + iVar8;
        UNLOCK();
        local_78 = (longlong *)0x0;
        uStack_70 = 0;
        local_68 = 0;
        pplVar16 = &local_78;
        KeAcquireInStackQueuedSpinLock(lVar3 + 0x60);
        do {
        } while (*(int *)(lVar3 + 0x68) != 0);
        local_130 = (longlong *)((ulonglong)local_130 & 0xffffffff00000000);
        local_128 = param_2;
        if ((param_2[0xf] == *(longlong *)(lVar19 + 0x38)) &&
           (*(int *)((ulonglong)*(ushort *)(param_2[2] + 10) + 0x38 + param_2[2]) == 0)) {
          pplVar16 = &local_128;
          QosNblCadComplete((longlong)param_2,pplVar16,(char)(param_3 & 1));
          local_130 = (longlong *)CONCAT44(local_130._4_4_,1);
        }
        plVar20 = local_128;
        if (local_128 != (longlong *)0x0) {
          LOCK();
          *(int *)(lVar3 + 0xac) = *(int *)(lVar3 + 0xac) + 1;
          UNLOCK();
        }
        KeReleaseInStackQueuedSpinLock(&local_78);
        if (plVar20 != (longlong *)0x0) {
          if ((*(int *)(*(longlong *)(lVar19 + 0x100) + 0x10) == 3) &&
             (*(short *)(*(longlong *)(lVar19 + 0x100) + 0xd4) == 0x800)) {
            PcpLineDereference(lVar19);
            pplVar16 = (longlong **)0x8;
            NdisFreeNetBufferListContext(plVar20);
          }
          plVar14 = (longlong *)plVar20[0x15];
          if ((plVar14 != (longlong *)0x0) && (plVar14 == PcgDefaultFlow)) {
            PcpDereferenceFlow(plVar14,(ulonglong)pplVar16);
            plVar20[0x15] = 0;
          }
          NdisFSendNetBufferListsComplete
                    (*(undefined8 *)(*(longlong *)(lVar19 + 0x100) + 0x28),plVar20,param_3);
        }
        if ((int)local_130 != 0) {
          PcpFilterDecrementPauseCount(*(longlong *)(lVar19 + 0x100),(int)local_130);
        }
        plVar20 = plStack_e8;
        lVar15 = local_120;
      }
      param_2 = plVar2;
    } while (plVar2 != (longlong *)0x0);
  }
  if (local_f0 != (longlong *)0x0) {
    NdisFSendNetBufferListsComplete(*(undefined8 *)(local_res8 + 0x28),local_f0,param_3);
  }
  lVar17 = _DAT_fffff78000000008;
  if (bVar21) {
    uVar13 = (ulonglong)uVar7;
    local_c0 = 0;
    local_d0 = 0;
    uStack_c8 = 0;
    plVar20 = (longlong *)(uVar13 * 0x80 + *QosgTimerTable);
    local_138 = 0;
    puVar10 = (ulonglong *)KeQueryPerformanceCounter(&local_138);
    uVar9 = ((ulonglong)puVar10 >> 0x20) * 1000000;
    bVar12 = *(byte *)(plVar20 + 0xe);
    lVar15 = ((uVar9 % local_138 << 0x20) + ((ulonglong)puVar10 & 0xffffffff) * 1000000) / local_138
             + (uVar9 / local_138 << 0x20);
    if (bVar12 == 0) {
      bVar6 = 2;
    }
    else {
      bVar6 = bVar12 - 1;
    }
    uVar9 = (ulonglong)bVar6;
    if (plVar20[uVar9 + 8] - lVar15 < 1) {
      plVar20[(ulonglong)bVar12 + 2] = (longlong)puVar10;
      plVar20[(ulonglong)bVar12 + 5] = local_138;
      plVar20[(ulonglong)bVar12 + 8] = lVar15;
    }
    else {
      plVar20[(ulonglong)bVar12 + 2] = plVar20[uVar9 + 2];
      plVar20[(ulonglong)bVar12 + 5] = plVar20[uVar9 + 5];
      plVar20[(ulonglong)bVar12 + 8] = plVar20[uVar9 + 8];
      lVar15 = plVar20[uVar9 + 8];
    }
    plVar20[(ulonglong)bVar12 + 0xb] = lVar17;
    plVar20[1] = lVar17;
    *plVar20 = lVar15;
    *(byte *)(plVar20 + 0xe) = (byte)((char)plVar20[0xe] + 1U) % 3;
    lVar17 = uVar13 * 0xc0 + PcgTimerUnits;
    bVar21 = PcgDisableRecursionFix != 0;
    if (bVar21) {
      *(int *)(lVar17 + 0x28) = *(int *)(lVar17 + 0x28) + -1;
    }
    if (*(uint *)(lVar17 + 0x28) == (uint)!bVar21) {
      KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar17);
      do {
      } while (*(int *)(lVar17 + 8) != 0);
      if (((*(uint *)(lVar17 + 0x2c) & 1) == 0) && (*(longlong *)(lVar17 + 0x18) - lVar15 < 1)) {
        KeReleaseInStackQueuedSpinLockFromDpcLevel();
        *(uint *)(lVar17 + 0x2c) = *(uint *)(lVar17 + 0x2c) | 2;
        puVar10 = (ulonglong *)0x0;
        PcpTimeoutHandler(0,lVar17,0,(longlong ****)0x0);
        *(uint *)(lVar17 + 0x2c) = *(uint *)(lVar17 + 0x2c) & 0xfffffffd;
      }
      else {
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_d0);
      }
    }
    if (PcgDisableRecursionFix == 0) {
      *(int *)(lVar17 + 0x28) = *(int *)(lVar17 + 0x28) + -1;
    }
    lVar17 = PcgDelayQueue;
    lVar15 = uVar13 * 0x40;
    piVar1 = (int *)(lVar15 + 0x10 + PcgDelayQueue);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      puVar4 = *(undefined8 **)(lVar15 + lVar17);
      *(undefined8 *)(lVar15 + lVar17) = 0;
      *(undefined8 *)(lVar15 + 8 + lVar17) = 0;
      lVar17 = _DAT_fffff78000000008;
      local_60 = 0;
      uStack_58 = 0;
      local_50 = 0;
      local_res8 = local_res8 & 0xffffffffff000000;
      plVar20 = (longlong *)(uVar13 * 0x80 + *QosgTimerTable);
      local_b8 = 0;
      uStack_b0 = 0;
      local_98 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      if (_DAT_fffff78000000008 != plVar20[1]) {
        local_138 = 0;
        uVar9 = KeQueryPerformanceCounter(&local_138);
        uVar13 = (uVar9 >> 0x20) * 1000000;
        bVar12 = *(byte *)(plVar20 + 0xe);
        lVar15 = ((uVar13 % local_138 << 0x20) + (uVar9 & 0xffffffff) * 1000000) / local_138 +
                 (uVar13 / local_138 << 0x20);
        if (bVar12 == 0) {
          bVar6 = 2;
        }
        else {
          bVar6 = bVar12 - 1;
        }
        uVar13 = (ulonglong)bVar6;
        if (plVar20[uVar13 + 8] - lVar15 < 1) {
          plVar20[(ulonglong)bVar12 + 2] = uVar9;
          plVar20[(ulonglong)bVar12 + 5] = local_138;
          plVar20[(ulonglong)bVar12 + 8] = lVar15;
        }
        else {
          plVar20[(ulonglong)bVar12 + 2] = plVar20[uVar13 + 2];
          plVar20[(ulonglong)bVar12 + 5] = plVar20[uVar13 + 5];
          plVar20[(ulonglong)bVar12 + 8] = plVar20[uVar13 + 8];
          lVar15 = plVar20[uVar13 + 8];
        }
        plVar20[(ulonglong)bVar12 + 0xb] = lVar17;
        bVar12 = (char)plVar20[0xe] + 1;
        *plVar20 = lVar15;
        plVar20[1] = lVar17;
        uVar18 = (uint)bVar12 + (bVar12 / 3) * -3;
        puVar10 = (ulonglong *)(ulonglong)uVar18;
        *(char *)(plVar20 + 0xe) = (char)uVar18;
      }
      lVar17 = *plVar20;
      while (puVar4 != (undefined8 *)0x0) {
        puVar5 = (undefined8 *)*puVar4;
        puVar11 = &local_60;
        RtlAcquireWriteLockAtDpcLevel((longlong)(puVar4 + 7));
        *(uint *)(puVar4 + 0x48) = *(uint *)(puVar4 + 0x48) & 0xfffffffb;
        local_100 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_138 = local_138 & 0xffffffff00000000;
        if ((*(uint *)(puVar4 + 0x48) & 8) == 0) {
          uVar9 = QosFlowNeedQueueFeedback((longlong)(puVar4 + 0xc),lVar17,&local_b8);
          if (((char)uVar9 != '\0') &&
             (puVar11 = PcpLineFindByLuid(puVar4[6]), puVar11 != (undefined8 *)0x0)) {
            PcpLineSignalExternalEvent((longlong)puVar11,(ulonglong)uVar7);
            puVar10 = &local_res8;
            NdisAcquireRWLockWrite(puVar11[2],puVar10,0);
            QosLineQueryQueueFeedback((longlong)(puVar11 + 3),puVar10,(uint *)&local_b8);
            NdisReleaseRWLock(puVar11[2],&local_res8);
            PcpLineDereference((longlong)puVar11);
            QosTbcAdjustSendWindow((longlong)(puVar4 + 0xc),(longlong)&local_b8);
          }
          puVar11 = (undefined8 *)(ulonglong)uVar7;
          puVar10 = &local_138;
          QosFlowProcessQueuedNetBufferLists((longlong)(puVar4 + 0xc),uVar7);
        }
        plVar2 = local_f8;
        plVar20 = local_100;
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_60);
        if (plVar20 != (longlong *)0x0) {
          puVar10 = (ulonglong *)CONCAT71((int7)((ulonglong)puVar10 >> 8),1);
          puVar11 = (undefined8 *)(ulonglong)uVar7;
          PcpSchedulerBatchAndSendOrDropNblChain(plVar20,uVar7,0,(longlong *)puVar10);
        }
        if (plVar2 != (longlong *)0x0) {
          puVar10 = (ulonglong *)0x0;
          puVar11 = (undefined8 *)(ulonglong)uVar7;
          PcpSchedulerBatchAndSendOrDropNblChain(plVar2,uVar7,0,(longlong *)0x0);
        }
        PcpDereferenceFlow(puVar4 + -5,(ulonglong)puVar11);
        puVar4 = puVar5;
      }
    }
  }
  if (local_res18 == '\0') {
    KeLowerIrql(local_res10);
  }
  return;
}



===== QosGetNblChainDataLength @ 1400044f0 =====

int QosGetNblChainDataLength(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  for (; param_1 != (undefined8 *)0x0; param_1 = (undefined8 *)*param_1) {
    iVar3 = 0;
    for (puVar1 = (undefined8 *)param_1[1]; puVar1 != (undefined8 *)0x0;
        puVar1 = (undefined8 *)*puVar1) {
      iVar3 = iVar3 + *(int *)(puVar1 + 3);
    }
    iVar2 = iVar2 + iVar3;
  }
  return iVar2;
}



===== PcpSchedulerCompleteNblChain @ 140004530 =====

void PcpSchedulerCompleteNblChain
               (undefined8 param_1,ulonglong param_2,longlong param_3,undefined4 param_4)

{
  longlong *plVar1;
  ulonglong uVar2;
  
  uVar2 = param_2;
  if ((*(int *)(*(longlong *)(param_2 + 0x100) + 0x10) == 3) &&
     (*(short *)(*(longlong *)(param_2 + 0x100) + 0xd4) == 0x800)) {
    PcpLineDereference(param_2);
    uVar2 = 8;
    NdisFreeNetBufferListContext(param_3);
  }
  plVar1 = *(longlong **)(param_3 + 0xa8);
  if ((plVar1 != (longlong *)0x0) && (plVar1 == PcgDefaultFlow)) {
    PcpDereferenceFlow(plVar1,uVar2);
    *(undefined8 *)(param_3 + 0xa8) = 0;
  }
  NdisFSendNetBufferListsComplete
            (*(undefined8 *)(*(longlong *)(param_2 + 0x100) + 0x28),param_3,param_4);
  return;
}



===== PcpDereferenceFlow @ 1400045e0 =====

void PcpDereferenceFlow(longlong *param_1,ulonglong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  LOCK();
  plVar1 = param_1 + 4;
  lVar2 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar2 == 1) {
    if ((*(uint *)(param_1 + 0x4d) & 8) == 0) {
      PcpDeleteFlow(param_1,param_2);
    }
    else {
      PcpCleanupFlow(param_1);
    }
  }
  return;
}



===== PcpIoctlDeleteFlow @ 140004618 =====

undefined4 PcpIoctlDeleteFlow(longlong param_1,longlong param_2,undefined4 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  code *pcVar6;
  longlong *plVar7;
  undefined1 uVar8;
  longlong *plVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar4 = *(undefined8 **)(param_1 + 0x18);
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x18) {
    return 0xc0000023;
  }
  if (*(uint *)(param_2 + 0x10) < 0x10) {
    uVar11 = 0xc0000023;
  }
  else {
    uVar11 = 0;
    if (puVar4[1] == 0) {
      uVar11 = 0xc0000225;
    }
    else {
      lVar1 = lVar5 + 0x20;
      uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
      uVar3 = *(uint *)(puVar4 + 1);
      uVar10 = (ulonglong)uVar3;
      plVar2 = (longlong *)(lVar5 + 0x10);
      plVar7 = (longlong *)*plVar2;
      do {
        plVar9 = plVar7;
        if (plVar9 == plVar2) {
          uVar11 = 0xc0000225;
          KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar3 >> 8),uVar8));
          goto LAB_140004749;
        }
        plVar7 = (longlong *)*plVar9;
      } while (*(uint *)((longlong)plVar9 + 0x254) != uVar3);
      RtlAcquireReadLockAtDpcLevel((longlong)(plVar9 + 10));
      puVar12 = auStack_38;
      if ((longlong *)plVar9[0x45] == plVar9 + 0x45) {
        lVar5 = *plVar9;
        if ((*(longlong **)(lVar5 + 8) == plVar9) &&
           (plVar2 = (longlong *)plVar9[1], (longlong *)*plVar2 == plVar9)) {
          *plVar2 = lVar5;
          uVar10 = CONCAT71((int7)(uVar10 >> 8),uVar8);
          *(longlong **)(lVar5 + 8) = plVar2;
          LOCK();
          *(int *)(plVar9 + 0xb) = (int)plVar9[0xb] + -1;
          UNLOCK();
          KeReleaseSpinLock(lVar1);
          puVar4[2] = plVar9[0x48];
          puVar4[1] = 0;
          PcpDeleteFlow(plVar9 + -2,uVar10);
          goto LAB_140004755;
        }
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar12 = auStack_30;
      }
      LOCK();
      *(int *)(plVar9 + 0xb) = (int)plVar9[0xb] + -1;
      UNLOCK();
      *(undefined8 *)(puVar12 + -8) = 0x140004726;
      KeReleaseSpinLock(lVar1,uVar8);
      uVar11 = 0xc0000101;
    }
  }
LAB_140004749:
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
LAB_140004755:
  *(undefined4 *)puVar4 = uVar11;
  *param_3 = 0x18;
  return uVar11;
}



===== PcpDeleteFlow @ 140004788 =====

void PcpDeleteFlow(longlong *param_1,ulonglong param_2)

{
  longlong *plVar1;
  uint uVar2;
  bool bVar3;
  longlong lVar4;
  undefined8 *puVar5;
  int local_res8 [2];
  ulonglong local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_48 = 0;
  local_res10 = param_2 & 0xffffffffff000000;
  local_58 = 0;
  uStack_50 = 0;
  if ((char)param_1[6] == '\x01') {
    puVar5 = PcpLineFindByInstanceName((ushort *)param_1[0x4b] + 1,*(ushort *)param_1[0x4b]);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x39);
    if ((uVar2 == 0) || (10000 < uVar2)) goto LAB_1400048a6;
    puVar5 = PcpLineFindByLuid(param_1[0xb]);
  }
  if (puVar5 != (undefined8 *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x39);
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    uStack_28 = 0;
    bVar3 = uVar2 - 1 < 10000;
    if (bVar3) {
      local_40 = (ulonglong)uVar2;
      uStack_38 = CONCAT44(0xffffffff,-uVar2);
    }
    local_res8[0] = -1;
    NdisAcquireRWLockWrite(puVar5[2]);
    if (bVar3) {
      QosLineUpdate(puVar5 + 3,(undefined8 *)0x0,0,(uint *)&local_40);
    }
    QosLineUpdateStats((longlong)(puVar5 + 3),local_res8);
    NdisReleaseRWLock(puVar5[2],&local_res10);
    PcpTcNotify((longlong)puVar5,-0x4fefefa,puVar5 + 6,4);
    PcpLineDereference((longlong)puVar5);
  }
LAB_1400048a6:
  if ((*(uint *)(param_1 + 0x4d) & 2) != 0) {
    PcpFilterDecrementIntercept(1);
  }
  KeAcquireInStackQueuedSpinLock(param_1 + 0xc,&local_58);
  do {
  } while ((int)param_1[0xd] != 0);
  *(uint *)(param_1 + 0x4d) = *(uint *)(param_1 + 0x4d) | 8;
  KeReleaseInStackQueuedSpinLock(&local_58);
  LOCK();
  plVar1 = param_1 + 4;
  lVar4 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar4 < 2) {
    PcpCleanupFlow(param_1);
  }
  return;
}



===== RtlAcquireReadLock @ 140004920 =====

void RtlAcquireReadLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KfRaiseIrql(2);
  *param_2 = uVar1;
  RtlAcquireReadLockAtDpcLevel(param_1);
  return;
}



===== PcpLineFindByInstanceName @ 14000495c =====

undefined8 * PcpLineFindByInstanceName(void *param_1,ushort param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockRead(PcgLineListLock,&local_res10,0);
  puVar3 = PcgLineList;
  while( true ) {
    if ((undefined8 **)puVar3 == &PcgLineList) {
      NdisReleaseRWLock(PcgLineListLock,&local_res10);
      return (undefined8 *)0x0;
    }
    LOCK();
    *(int *)(puVar3 + 0x1f) = *(int *)(puVar3 + 0x1f) + 1;
    UNLOCK();
    NdisReleaseRWLock(PcgLineListLock);
    NdisAcquireRWLockRead(puVar3[2],&local_res10,0);
    if (((*(int *)((longlong)puVar3 + 0xf4) == 2) && (param_2 == *(ushort *)(puVar3 + 0x21))) &&
       (iVar2 = memcmp(param_1,(void *)puVar3[0x22],(ulonglong)param_2), iVar2 == 0)) break;
    NdisReleaseRWLock(puVar3[2],&local_res10);
    NdisAcquireRWLockRead(PcgLineListLock,&local_res10);
    puVar1 = (undefined8 *)*puVar3;
    PcpLineDereference((longlong)puVar3);
    puVar3 = puVar1;
  }
  NdisReleaseRWLock(puVar3[2],&local_res10);
  return puVar3;
}



===== PcpCounterSetCallback @ 140004aa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PcpCounterSetCallback(int param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  longlong lVar2;
  longlong *plVar3;
  uint uVar4;
  int iVar5;
  longlong *_Src;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  ushort *puVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  undefined1 auStack_198 [32];
  longlong **local_178;
  undefined1 local_168;
  undefined2 local_164;
  undefined1 local_162;
  undefined2 local_160;
  undefined1 local_15e;
  undefined8 local_158;
  longlong *local_150;
  undefined4 local_148;
  longlong local_140;
  longlong lStack_138;
  longlong *local_130;
  ushort local_128 [8];
  longlong *local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined8 local_c4;
  undefined8 local_bc;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  local_158 = CONCAT44(local_158._4_4_,param_1);
  local_160 = 0;
  local_15e = 0;
  local_164 = 0;
  local_162 = 0;
  local_130 = (longlong *)CONCAT44(local_130._4_4_,0xc);
  uVar14 = 0;
  uVar13 = 0;
  uVar16 = 6;
  local_128[0] = 0;
  local_128[1] = 0;
  local_128[2] = 0;
  local_128[3] = 0;
  local_128[4] = 0;
  local_128[5] = 0;
  local_128[6] = 0;
  local_128[7] = 0;
  local_140 = 0;
  lStack_138 = 0;
  memset(&local_f8,0,0x44);
  memset(&local_a8,0,0x68);
  local_110 = 0;
  uStack_108 = 0;
  if (param_1 - 2U < 2) {
    if (param_3 == 1) {
      _Src = (longlong *)ExAllocatePool2(0x40,0x30,0x73637050);
      if (_Src != (longlong *)0x0) {
        NdisAcquireRWLockRead(PcgLineListLock,&local_160,0);
        for (puVar10 = PcgLineList; uVar12 = (uint)uVar14, (undefined8 **)puVar10 != &PcgLineList;
            puVar10 = (undefined8 *)*puVar10) {
          NdisAcquireRWLockRead(puVar10[2],&local_164,0);
          if ((*(int *)((longlong)puVar10 + 0xf4) == 2) &&
             (((lVar2 = puVar10[0x20], lVar2 == 0 || (*(int *)(lVar2 + 0x10) != 3)) ||
              (*(undefined8 **)(lVar2 + 0xa0) != puVar10)))) {
            LOCK();
            *(int *)(puVar10 + 0x1f) = *(int *)(puVar10 + 0x1f) + 1;
            UNLOCK();
            NdisReleaseRWLock(puVar10[2],&local_164);
            uVar15 = (uint)uVar16;
            if (uVar12 == uVar15) {
              uVar16 = (ulonglong)(uVar15 * 2);
              local_130 = (longlong *)ExAllocatePool2(0x40,uVar16 * 8,0x73637050);
              if (local_130 == (longlong *)0x0) {
                PcpLineDereference((longlong)puVar10);
                NdisReleaseRWLock(PcgLineListLock,&local_160);
                if (uVar12 != 0) {
                  plVar11 = _Src;
                  do {
                    PcpLineDereference(*plVar11);
                    plVar11 = plVar11 + 1;
                    uVar14 = uVar14 - 1;
                  } while (uVar14 != 0);
                }
                goto LAB_140005001;
              }
              memmove(local_130,_Src,(ulonglong)(uVar15 & 0x7fffffff) << 3);
              ExFreePoolWithTag(_Src,0x73637050);
              _Src = local_130;
            }
            _Src[uVar14] = (longlong)puVar10;
            uVar14 = (ulonglong)(uVar12 + 1);
          }
          else {
            NdisReleaseRWLock(puVar10[2],&local_164);
          }
        }
        NdisReleaseRWLock(PcgLineListLock,&local_160);
        RtlInitUnicodeString(&local_110,L"Traffic Control Global Interface");
        if ((int)local_158 == 2) {
          local_158 = *(undefined8 *)(param_2 + 0x18);
          for (uVar13 = 0; (uint)uVar13 < uVar12; uVar13 = (ulonglong)((uint)uVar13 + 1)) {
            lVar2 = _Src[uVar13];
            iVar5 = RtlCompareUnicodeString(&local_110,lVar2 + 0x108,1);
            if (iVar5 != 0) {
              uVar1 = *(ushort *)(lVar2 + 0x10a);
              lVar7 = ExAllocatePool2(0x100,uVar1,0x73637050);
              if (lVar7 == 0) {
                if (uVar12 != 0) {
                  plVar11 = _Src;
                  do {
                    PcpLineDereference(*plVar11);
                    plVar11 = plVar11 + 1;
                    uVar14 = uVar14 - 1;
                  } while (uVar14 != 0);
                }
                goto LAB_140005001;
              }
              local_140 = (ulonglong)uVar1 << 0x10;
              lStack_138 = lVar7;
              RtlCopyUnicodeString(&local_140,lVar2 + 0x108);
              PcpConvertToInstanceName((longlong)&local_140);
              local_178 = &local_150;
              local_150 = (longlong *)0x0;
              local_148 = 0x44;
              PcwAddInstance(local_158,&local_140,uVar13,1);
              ExFreePoolWithTag(lVar7,0x73637050);
            }
            PcpLineDereference(lVar2);
          }
        }
        else if ((int)local_158 == 3) {
          local_158 = *(undefined8 *)(param_2 + 0x18);
          uVar13 = 0;
LAB_140004d57:
          if ((uint)uVar13 < uVar12) {
            lVar2 = _Src[uVar13];
            uVar1 = *(ushort *)(lVar2 + 0x10a);
            lVar7 = ExAllocatePool2(0x100,uVar1,0x73637050);
            if (lVar7 != 0) goto code_r0x000140004d92;
            if (uVar12 != 0) {
              plVar11 = _Src;
              do {
                PcpLineDereference(*plVar11);
                plVar11 = plVar11 + 1;
                uVar14 = uVar14 - 1;
              } while (uVar14 != 0);
            }
LAB_140005001:
            uVar6 = 0x73637050;
LAB_140005009:
            ExFreePoolWithTag(_Src,uVar6);
            goto LAB_140004b73;
          }
        }
        uVar6 = 0x73637050;
        goto LAB_140004bef;
      }
    }
    else {
      _Src = (longlong *)ExAllocatePool2(0x40,0x60,0x73636650);
      if (_Src != (longlong *)0x0) {
        local_168 = KfRaiseIrql(2);
        RtlAcquireReadLockAtDpcLevel(0x140019780);
        for (puVar10 = PcgFileCtxList; (undefined8 **)puVar10 != &PcgFileCtxList;
            puVar10 = (undefined8 *)*puVar10) {
          KeAcquireSpinLockAtDpcLevel(puVar10 + 4);
          puVar17 = (undefined8 *)puVar10[2];
LAB_1400050bd:
          if (puVar17 != puVar10 + 2) {
            local_150 = puVar17 + -2;
            PcpReferenceFlow((longlong)local_150);
            uVar12 = (uint)local_130;
            uVar15 = (uint)uVar13;
            if (uVar15 != (uint)local_130) goto LAB_1400052d0;
            uVar4 = (uint)local_130 * 2;
            local_130 = (longlong *)CONCAT44(local_130._4_4_,uVar4);
            uVar14 = (ulonglong)uVar4 * 8;
            local_118 = (longlong *)ExAllocatePool2(0x40,uVar14,0x73636650);
            if (local_118 != (longlong *)0x0) {
              memmove(local_118,_Src,(ulonglong)(uVar12 & 0x7fffffff) << 3);
              ExFreePoolWithTag(_Src,0x73636650);
              _Src = local_118;
              goto LAB_1400052d0;
            }
            PcpDereferenceFlow(local_150,uVar14);
            KeReleaseSpinLockFromDpcLevel(puVar10 + 4);
            LOCK();
            _DAT_140019788 = _DAT_140019788 + -1;
            UNLOCK();
            KeLowerIrql(local_168);
            if (uVar15 != 0) {
              plVar11 = _Src;
              do {
                PcpDereferenceFlow((longlong *)*plVar11,uVar14);
                plVar11 = plVar11 + 1;
                uVar13 = uVar13 - 1;
              } while (uVar13 != 0);
            }
            uVar6 = 0x73636650;
            goto LAB_140005009;
          }
          KeReleaseSpinLockFromDpcLevel(puVar10 + 4);
        }
        LOCK();
        _DAT_140019788 = _DAT_140019788 + -1;
        UNLOCK();
        KeLowerIrql(local_168);
        uVar12 = (uint)uVar13;
        if ((int)local_158 == 2) {
          uVar6 = *(undefined8 *)(param_2 + 0x18);
          uVar15 = 0;
          if (uVar12 != 0) {
            plVar11 = _Src;
            do {
              plVar3 = (longlong *)*plVar11;
              RtlInitUnicodeString(local_128,(longlong)plVar3 + 0x34);
              local_150 = (longlong *)0x0;
              local_178 = &local_150;
              local_148 = 0x68;
              puVar9 = local_128;
              PcwAddInstance(uVar6,puVar9,uVar15,1);
              PcpDereferenceFlow(plVar3,(ulonglong)puVar9);
              uVar15 = uVar15 + 1;
              plVar11 = plVar11 + 1;
            } while (uVar15 < uVar12);
          }
        }
        else if ((int)local_158 == 3) {
          uVar6 = *(undefined8 *)(param_2 + 0x18);
          uVar15 = 0;
          if (uVar12 != 0) {
            plVar11 = _Src;
            do {
              plVar3 = (longlong *)*plVar11;
              RtlInitUnicodeString(local_128);
              if (*(longlong *)(*(ushort **)(param_2 + 8) + 4) == 0) {
LAB_140004f0f:
                memset(&local_a8,0,0x68);
                local_a8 = *(undefined4 *)((longlong)plVar3 + 0x8c);
                puVar9 = local_128;
                local_a4 = (undefined4)plVar3[0x12];
                local_a0 = *(undefined4 *)((longlong)plVar3 + 0x94);
                local_98 = plVar3[0x13];
                local_90 = plVar3[0x14];
                local_88 = plVar3[0x14];
                local_80 = plVar3[0x13];
                local_78 = *(undefined4 *)((longlong)plVar3 + 0x94);
                local_74 = (undefined4)plVar3[0x12];
                local_70 = *(undefined4 *)((longlong)plVar3 + 0x8c);
                local_6c = *(undefined4 *)((longlong)plVar3 + 0x134);
                local_68 = *(undefined4 *)((longlong)plVar3 + 0x134);
                local_64 = *(undefined4 *)((longlong)plVar3 + 0x13c);
                local_60 = (undefined4)plVar3[0x27];
                local_150 = (longlong *)&local_a8;
                local_178 = &local_150;
                local_148 = 0x68;
                PcwAddInstance(uVar6,puVar9,uVar15,1);
              }
              else {
                puVar9 = local_128;
                uVar8 = PcpWildcardMatch(*(ushort **)(param_2 + 8),puVar9);
                if ((char)uVar8 != '\0') goto LAB_140004f0f;
              }
              PcpDereferenceFlow(plVar3,(ulonglong)puVar9);
              uVar15 = uVar15 + 1;
              plVar11 = plVar11 + 1;
            } while (uVar15 < uVar12);
          }
        }
        uVar6 = 0x73636650;
LAB_140004bef:
        ExFreePoolWithTag(_Src,uVar6);
        goto LAB_140004bfb;
      }
    }
LAB_140004b73:
    uVar6 = 0xc000009a;
  }
  else {
LAB_140004bfb:
    uVar6 = 0;
  }
  return uVar6;
code_r0x000140004d92:
  local_140 = (ulonglong)uVar1 << 0x10;
  lStack_138 = lVar7;
  RtlCopyUnicodeString(&local_140,lVar2 + 0x108);
  PcpConvertToInstanceName((longlong)&local_140);
  if ((*(longlong *)(*(ushort **)(param_2 + 8) + 4) == 0) ||
     (uVar6 = PcpWildcardMatch(*(ushort **)(param_2 + 8),(ushort *)&local_140), (char)uVar6 != '\0')
     ) {
    iVar5 = RtlCompareUnicodeString(&local_110,lVar2 + 0x108,1);
    if (iVar5 != 0) {
      local_cc = 0;
      local_c4 = 0;
      local_bc = 0;
      local_f8 = *(undefined4 *)(lVar2 + 0x50);
      local_f4 = *(undefined4 *)(lVar2 + 0x54);
      local_f0 = *(undefined4 *)(lVar2 + 0x58);
      local_ec = *(undefined4 *)(lVar2 + 0x5c);
      local_e8 = *(undefined4 *)(lVar2 + 0x60);
      local_e4 = *(undefined4 *)(lVar2 + 100);
      local_e0 = *(undefined4 *)(lVar2 + 0x68);
      local_dc = *(undefined4 *)(lVar2 + 0x6c);
      local_d8 = *(undefined4 *)(lVar2 + 0x6c);
      local_d4 = *(undefined4 *)(lVar2 + 0x74);
      local_d0 = *(undefined4 *)(lVar2 + 0x70);
      local_150 = (longlong *)&local_f8;
      local_178 = &local_150;
      local_148 = 0x44;
      PcwAddInstance(local_158,&local_140,uVar13,1);
    }
    ExFreePoolWithTag(lVar7,0x73637050);
  }
  PcpLineDereference(lVar2);
  uVar13 = (ulonglong)((uint)uVar13 + 1);
  goto LAB_140004d57;
LAB_1400052d0:
  _Src[uVar13] = (longlong)(puVar17 + -2);
  puVar17 = (undefined8 *)*puVar17;
  uVar13 = (ulonglong)(uVar15 + 1);
  goto LAB_1400050bd;
}



===== PcpConvertToInstanceName @ 140005388 =====

longlong PcpConvertToInstanceName(longlong param_1)

{
  wchar_t *pwVar1;
  wchar_t _Ch;
  wchar_t *pwVar2;
  wchar_t *_Str;
  ulonglong uVar3;
  wchar_t *pwVar4;
  
  pwVar1 = *(wchar_t **)(param_1 + 8);
  _Ch = L')';
  uVar3 = 0;
  pwVar4 = L")(#\\/";
  do {
    _Str = pwVar1;
    while( true ) {
      pwVar2 = wcschr(_Str,_Ch);
      if (pwVar2 == (wchar_t *)0x0) break;
      _Ch = *pwVar4;
      _Str = pwVar2 + 1;
      *pwVar2 = L'-';
    }
    uVar3 = (ulonglong)((int)uVar3 + 1);
    pwVar4 = L")(#\\/" + uVar3;
    _Ch = *pwVar4;
  } while (_Ch != L'\0');
  return param_1;
}



===== PcpLineDereference @ 140005420 =====

int PcpLineDereference(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xf8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    if (*(longlong *)(param_1 + 0x140) != 0) {
      NdisFreeMemoryWithTag(*(longlong *)(param_1 + 0x140),0x616e6350);
    }
    if (*(longlong *)(param_1 + 0x100) != 0) {
      PcpFilterDecrementDetachCount(*(longlong *)(param_1 + 0x100));
    }
    if (*(longlong *)(param_1 + 0x10) != 0) {
      NdisFreeRWLock();
    }
    ExFreePoolWithTag(param_1,0x656c6350);
  }
  return iVar2 + -1;
}



===== PcpWildcardMatch @ 1400054ac =====

ulonglong PcpWildcardMatch(ushort *param_1,ushort *param_2)

{
  short *psVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  short *psVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  short *psVar8;
  
  psVar8 = (short *)0x0;
  psVar1 = *(short **)(param_1 + 4) + (*param_1 >> 1);
  uVar3 = (ulonglong)(*param_2 >> 1);
  uVar2 = *(ulonglong *)(param_2 + 4) + uVar3 * 2;
  psVar4 = *(short **)(param_1 + 4);
  uVar6 = 0;
  uVar7 = *(ulonglong *)(param_2 + 4);
  while ((uVar7 < uVar2 || (psVar4 < psVar1))) {
    uVar5 = uVar6;
    if ((psVar4 < psVar1) && (*psVar4 == 0x2a)) {
      do {
        psVar4 = psVar4 + 1;
        if (psVar1 <= psVar4) goto LAB_1400054fe;
      } while (*psVar4 == 0x2a);
      uVar5 = uVar7 + 2;
      psVar8 = psVar4;
    }
    if (((uVar7 < uVar2) && (psVar4 < psVar1)) &&
       ((*psVar4 == 0x3f || (uVar3 = RtlCompareUnicodeStrings(psVar4,1,uVar7,1,1), (int)uVar3 == 0))
       )) {
      psVar4 = psVar4 + 1;
      uVar6 = uVar5;
      uVar7 = uVar7 + 2;
    }
    else {
      if ((psVar8 == (short *)0x0) || (uVar2 <= uVar5)) {
        return uVar3 & 0xffffffffffffff00;
      }
      uVar6 = uVar5 + 2;
      psVar4 = psVar8;
      uVar7 = uVar5;
    }
  }
LAB_1400054fe:
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== RtlAcquireReadLockAtDpcLevel @ 140005594 =====

void RtlAcquireReadLockAtDpcLevel(longlong param_1)

{
  char cVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  UNLOCK();
  cVar1 = KeTestSpinLock();
  if (cVar1 == '\0') {
    LOCK();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    UNLOCK();
    KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1,&local_28);
    LOCK();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    UNLOCK();
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  }
  return;
}



===== PcFilterDetach @ 140005600 =====

void PcFilterDetach(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(param_1[4],&local_res8,0);
  *(undefined4 *)(param_1 + 3) = 5;
  NdisResetEvent(param_1 + 0xd);
  NdisReleaseRWLock(param_1[4],&local_res8);
  PcpTraceLineUpDownEvent(param_1[0x14] + 0x128);
  NdisFreeNetBufferListPool(param_1[6]);
  NdisAcquireRWLockWrite(PcgFilterDriverContext,&local_res8,0);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) != param_1) ||
     (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 != param_1)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *plVar4 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar4;
  NdisReleaseRWLock(PcgFilterDriverContext,&local_res8);
  plVar4 = (longlong *)param_1[0x14];
  param_1[0x14] = 0;
  PcpLineDestroy(plVar4);
  do {
    NdisAcquireRWLockWrite(PcgLineListLock,&local_res8,0);
    plVar4 = PcgLineList;
    do {
      plVar3 = plVar4;
      plVar4 = (longlong *)0x0;
      if ((longlong **)plVar3 == &PcgLineList) goto LAB_14000574e;
      plVar4 = (longlong *)*plVar3;
    } while ((longlong *)plVar3[0x20] != param_1);
    LOCK();
    *(int *)(plVar3 + 0x1f) = (int)plVar3[0x1f] + 1;
    UNLOCK();
    plVar4 = plVar3;
LAB_14000574e:
    NdisReleaseRWLock(PcgLineListLock,&local_res8);
    if (plVar4 == (longlong *)0x0) {
      PcpInitializeDSCPToUPMappings((undefined8 *)((longlong)param_1 + 0xd6));
      PcpFilterDecrementDetachCount((longlong)param_1);
      NdisWaitEvent(param_1 + 0xd,0);
      NdisFreeRWLock(param_1[4]);
      NdisFreeMemoryWithTag(param_1,0x63666350);
      return;
    }
    PcpLineDestroy(plVar4);
    PcpLineDereference((longlong)plVar4);
  } while( true );
}



===== PcpLineDestroy @ 14000580c =====

void PcpLineDestroy(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  bVar4 = false;
  NdisAcquireRWLockWrite(param_1[2],&local_res8,0);
  if (*(int *)((longlong)param_1 + 0xf4) == 2) {
    bVar4 = true;
    *(undefined4 *)((longlong)param_1 + 0xf4) = 0;
    *(uint *)(param_1 + 0x1d) = *(uint *)(param_1 + 0x1d) | 1;
  }
  else {
    if (*(int *)((longlong)param_1 + 0xf4) == 0) {
      NdisReleaseRWLock(param_1[2],&local_res8);
      return;
    }
    *(undefined4 *)((longlong)param_1 + 0xf4) = 0;
  }
  NdisReleaseRWLock(param_1[2],&local_res8);
  if (bVar4) {
    PcpTcIndicateInterfaceChange((longlong)param_1,0x40010010);
  }
  if ((short)param_1[0x1e] != 0) {
    PcpLineFreeId((longlong)param_1);
  }
  NdisAcquireRWLockWrite(PcgLineListLock,&local_res8,0);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    NdisReleaseRWLock(PcgLineListLock,&local_res8);
    PcpLineDereference((longlong)param_1);
    PcpLineDereference((longlong)param_1);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== PcFilterPause @ 140005940 =====

undefined8 PcFilterPause(longlong param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_res8,0);
  *(undefined4 *)(param_1 + 0x18) = 4;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res8);
  PcpTraceLineUpDownEvent(*(longlong *)(param_1 + 0xa0) + 0x128);
  PcpFilterDecrementPauseCount(param_1,1);
  NdisWaitEvent(param_1 + 0x88,0);
  *(undefined4 *)(param_1 + 0x18) = 1;
  return 0;
}



===== PcFilterAttach @ 140005a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PcFilterAttach(longlong param_1,undefined8 param_2,longlong param_3)

{
  ushort *puVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  PMIB_UNICASTIPADDRESS_TABLE Memory;
  NET_LUID *pNVar6;
  undefined2 uVar7;
  undefined4 *puVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  undefined1 auStackY_f8 [8];
  undefined1 auStackY_f0 [24];
  undefined1 uVar16;
  undefined4 uVar17;
  undefined4 in_stack_ffffffffffffff4c;
  longlong *local_98;
  undefined2 local_90;
  undefined1 local_8e;
  int *local_88;
  PMIB_UNICASTIPADDRESS_TABLE local_80;
  undefined8 local_78;
  ULONG64 local_70;
  undefined8 local_68;
  short *psStack_60;
  undefined8 local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar12 = 0;
  uStack_48 = 0;
  local_78 = 0;
  local_90 = 0;
  local_8e = 0;
  local_70 = 0;
  local_98 = (longlong *)0x0;
  local_80 = (PMIB_UNICASTIPADDRESS_TABLE)0x0;
  local_58 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  local_88 = (int *)0x0;
  uVar15 = 0;
  local_68 = 0;
  psStack_60 = (short *)0x0;
  iVar4 = NdisAllocateMemoryWithTag(&local_98,0x120,0x63666350);
  if (iVar4 != 0) goto LAB_140005e32;
  memset(local_98,0,0x120);
  local_98[5] = param_1;
  *(undefined4 *)((longlong)local_98 + 100) = 1;
  *(undefined4 *)(local_98 + 2) = *(undefined4 *)(param_3 + 0x48);
  *(undefined4 *)((longlong)local_98 + 0x14) = *(undefined4 *)(param_3 + 0x4c);
  *(undefined4 *)(local_98 + 0xc) = *(undefined4 *)(param_3 + 0x18);
  *(undefined1 *)((longlong)local_98 + 0x1c) = 1;
  InitializeSListHead((PSLIST_HEADER)(local_98 + 8));
  KeInitializeSpinLock(local_98 + 10);
  NdisInitializeEvent(local_98 + 0xd);
  NdisInitializeEvent(local_98 + 0x11);
  NdisResetEvent(local_98 + 0xd);
  lVar5 = NdisAllocateRWLock(local_98[5]);
  local_98[4] = lVar5;
  if (local_98[4] == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      uVar7 = 0xe;
LAB_140005f38:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
              &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids);
    }
LAB_140005f48:
    iVar4 = -0x3fffff66;
LAB_140005e32:
    puVar11 = auStackY_f8;
    Memory = local_80;
    puVar10 = auStackY_f8;
    if (local_80 == (PMIB_UNICASTIPADDRESS_TABLE)0x0) goto LAB_140005e3f;
  }
  else {
    uStack_4c = 0;
    uStack_48 = 0;
    local_58 = CONCAT26(PcgNblContextSize,0x140180);
    uStack_50 = 0x62736350;
    lVar5 = NdisAllocateNetBufferListPool(param_1,&local_58);
    local_98[6] = lVar5;
    if (local_98[6] == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        uVar7 = 0xf;
        goto LAB_140005f38;
      }
      goto LAB_140005f48;
    }
    PcpReadSettings(param_1,(uint *)(local_98 + 0x15));
    PcpInitializeDSCPToUPMappings((undefined8 *)((longlong)local_98 + 0xd6));
    iVar4 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,2,local_98 + 0xc);
    if ((iVar4 < 0) || (iVar4 = GetUnicastIpAddressTable(2,&local_80), iVar4 < 0))
    goto LAB_140005e32;
    uVar9 = (ulonglong)local_80->NumEntries;
    if (local_80->NumEntries != 0) {
      pNVar6 = &local_80->Table[0].InterfaceLuid;
      do {
        if (pNVar6->Value == local_70) {
          uVar12 = (ulonglong)((int)uVar12 + 1);
        }
        pNVar6 = pNVar6 + 10;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
      if ((int)uVar12 == 0) goto LAB_140005c61;
      if ((uVar12 * 0x14 < 0x100000000) &&
         (uVar14 = (uint)(uVar12 * 0x14), uVar15 = uVar14 + 6, uVar14 <= uVar15)) {
        iVar4 = NdisAllocateMemoryWithTag(&local_88,uVar15,0x616e6350);
        if (iVar4 == 0) {
          memset(local_88,0,(ulonglong)uVar15);
          uVar9 = 0;
          *local_88 = (int)uVar12;
          *(undefined2 *)(local_88 + 1) = 2;
          puVar8 = (undefined4 *)((longlong)local_88 + 6);
          if (local_80->NumEntries != 0) {
            do {
              if (local_80->Table[uVar9].InterfaceLuid.Value == local_70) {
                *puVar8 = 0x20010;
                *(_struct_1249 *)(puVar8 + 2) =
                     local_80->Table[uVar9].Address.Ipv4.sin_addr.S_un.S_un_b;
                puVar8 = puVar8 + 5;
              }
              uVar14 = (int)uVar9 + 1;
              uVar9 = (ulonglong)uVar14;
            } while (uVar14 < local_80->NumEntries);
          }
          goto LAB_140005c61;
        }
      }
      else {
        iVar4 = -0x3fffff6b;
      }
      goto LAB_140005e32;
    }
LAB_140005c61:
    puVar1 = *(ushort **)(param_3 + 0x28);
    if ((((((*puVar1 < 0x10) || (psStack_60 = *(short **)(puVar1 + 4), *psStack_60 != 0x5c)) ||
          (psStack_60[1] != 0x44)) || ((psStack_60[2] != 0x45 || (psStack_60[3] != 0x56)))) ||
        ((psStack_60[4] != 0x49 || ((psStack_60[5] != 0x43 || (psStack_60[6] != 0x45)))))) ||
       (psStack_60[7] != 0x5c)) {
      local_68 = *(undefined8 *)puVar1;
      psStack_60 = *(short **)(puVar1 + 4);
    }
    else {
      psStack_60 = psStack_60 + 8;
      local_68._0_4_ = CONCAT22(puVar1[1] - 0x10,*puVar1 - 0x10);
    }
    uVar12 = *(ulonglong *)(param_3 + 0x38);
    if (uVar12 != 0xffffffffffffffff) {
      uVar12 = uVar12 >> 3;
    }
    uVar17 = 0;
    uVar16 = 0;
    iVar4 = PcpLineCreate(local_98 + 0x14,(longlong)local_98,'\x01',
                          *(ushort *)(*(longlong *)(param_3 + 0x20) + 2),
                          (ushort)((ulonglong)local_68 >> 0x10),local_70,uVar12,0,0);
    if (iVar4 < 0) goto LAB_140005e32;
    piVar13 = (int *)0xffffffffffffffff;
    uVar14 = 0xffffffff;
    if (local_88 != (int *)0x0) {
      piVar13 = local_88;
      uVar14 = uVar15;
    }
    PcpLineUpdate(local_98[0x14],*(longlong *)(param_3 + 0x20),(longlong)&local_68,(undefined8 *)0x0
                  ,0,0,0,uVar16,CONCAT44(in_stack_ffffffffffffff4c,uVar17),(longlong)piVar13,uVar14)
    ;
    local_88 = (int *)0x0;
    local_78 = 0x8018d;
    iVar4 = NdisFSetAttributes(param_1,local_98,&local_78);
    if (iVar4 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids,iVar4);
      }
      goto LAB_140005e32;
    }
    *(undefined4 *)(local_98 + 3) = 1;
    NdisAcquireRWLockWrite(PcgFilterDriverContext,&local_90,0);
    Memory = (PMIB_UNICASTIPADDRESS_TABLE)0x3;
    if (((DAT_140019898 != 0) || (*(int *)(param_3 + 0x48) == 3)) ||
       (*(char *)((longlong)local_98 + 0xd3) == '\x01')) {
      *(undefined1 *)((longlong)local_98 + 0x1c) = 0;
    }
    if ((undefined8 *)*DAT_140019890 == &DAT_140019888) {
      local_98[1] = (longlong)DAT_140019890;
      *local_98 = (longlong)&DAT_140019888;
      *DAT_140019890 = (longlong)local_98;
      DAT_140019890 = local_98;
      NdisReleaseRWLock(PcgFilterDriverContext,&local_90);
      PcpTraceLineUpDownEvent(local_98[0x14] + 0x128);
      PcpLineStart(local_98[0x14]);
      goto LAB_140005e32;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar11 = auStackY_f0;
  }
  *(undefined8 *)(puVar11 + -8) = 0x1400060b2;
  FreeMibTable(Memory);
  puVar10 = puVar11;
LAB_140005e3f:
  if (iVar4 != 0) {
    if (local_98 != (longlong *)0x0) {
      if (local_98[6] != 0) {
        *(undefined8 *)(puVar10 + -8) = 0x1400060d5;
        NdisFreeNetBufferListPool();
      }
      plVar2 = (longlong *)local_98[0x14];
      if (plVar2 != (longlong *)0x0) {
        *(undefined8 *)(puVar10 + -8) = 0x1400060ef;
        PcpLineDestroy(plVar2);
      }
      if (local_98[4] != 0) {
        *(undefined8 *)(puVar10 + -8) = 0x140006103;
        NdisFreeRWLock();
      }
      *(undefined8 *)(puVar10 + -8) = 0x140006118;
      NdisFreeMemoryWithTag(local_98,0x63666350);
    }
    if (local_88 != (int *)0x0) {
      *(undefined8 *)(puVar10 + -8) = 0x140006136;
      NdisFreeMemoryWithTag(local_88,0x616e6350);
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x140005e55;
  return iVar4;
}



===== PcpInitializeDSCPToUPMappings @ 140006150 =====

void PcpInitializeDSCPToUPMappings(undefined8 *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_d142f05ff1783a702b1695b6c61349f7_Traceguids);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined4 *)(param_1 + 7) = 0;
  return;
}



===== PcpLineCreate @ 1400061b8 =====

int PcpLineCreate(undefined8 *param_1,longlong param_2,char param_3,ushort param_4,ushort param_5,
                 longlong param_6,longlong param_7,undefined4 param_8,undefined4 param_9)

{
  code *pcVar1;
  int iVar2;
  longlong *_Dst;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined2 local_res20;
  undefined1 local_res22;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  local_res20 = 0;
  local_res22 = 0;
  uVar8 = param_5 + 0x158 + (uint)param_4;
  *param_1 = 0;
  _Dst = (longlong *)ExAllocatePool2(0x40,uVar8,0x656c6350);
  if (_Dst != (longlong *)0x0) {
    memset(_Dst,0,(ulonglong)uVar8);
    if (param_4 != 0) {
      *(ushort *)((longlong)_Dst + 0x10a) = param_4;
      _Dst[0x22] = (longlong)(_Dst + 0x2b);
    }
    if (param_5 != 0) {
      *(ushort *)((longlong)_Dst + 0x11a) = param_5;
      _Dst[0x24] = (ulonglong)param_4 + 0x158 + (longlong)_Dst;
    }
    *(undefined4 *)(_Dst + 0x26) = param_8;
    *(undefined4 *)((longlong)_Dst + 0x134) = param_9;
    *(undefined4 *)(_Dst + 0x1f) = 1;
    _Dst[0x25] = param_6;
    if (param_2 == 0) {
      uVar3 = 0;
      uVar7 = PcgFilterDriverHandle;
    }
    else {
      uVar3 = *(undefined8 *)(param_2 + 0x30);
      uVar7 = *(undefined8 *)(param_2 + 0x28);
    }
    QosLineCreate(_Dst + 3,param_6,param_7,uVar7,uVar3);
    *(undefined4 *)((longlong)_Dst + 0xf4) = 1;
    if (param_2 == 0) {
      uVar3 = PcgFilterDriverHandle;
    }
    else {
      uVar3 = *(undefined8 *)(param_2 + 0x28);
      LOCK();
      *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
      UNLOCK();
      _Dst[0x20] = param_2;
    }
    lVar4 = NdisAllocateRWLock(uVar3);
    _Dst[2] = lVar4;
    if (lVar4 != 0) {
      LOCK();
      *(int *)(_Dst + 0x1f) = (int)_Dst[0x1f] + 1;
      UNLOCK();
      NdisAcquireRWLockWrite(PcgLineListLock,&local_res20,0);
      puVar6 = auStackY_58;
      puVar5 = &PcgLineList;
      if ((undefined8 *)*DAT_140019688 != &PcgLineList) {
        puVar5 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        DAT_140019688 = (longlong *)(*pcVar1)();
        puVar6 = auStackY_50;
      }
      *_Dst = (longlong)puVar5;
      uVar3 = PcgLineListLock;
      _Dst[1] = (longlong)DAT_140019688;
      *DAT_140019688 = (longlong)_Dst;
      *(undefined8 *)(puVar6 + -8) = 0x14000637d;
      DAT_140019688 = _Dst;
      NdisReleaseRWLock(uVar3,puVar6 + 0x78);
      if (param_3 == '\0') {
        *(undefined8 *)(puVar6 + -8) = 0x14000638f;
        iVar2 = PcpLineAllocId((longlong)_Dst);
        if (iVar2 < 0) {
          *(undefined8 *)(puVar6 + -8) = 0x14000639d;
          PcpLineDestroy(_Dst);
          return iVar2;
        }
      }
      *param_1 = _Dst;
      return 0;
    }
    PcpLineDereference((longlong)_Dst);
  }
  return -0x3fffff66;
}



===== PcFilterRequestComplete @ 1400063d0 =====

void PcFilterRequestComplete(longlong param_1,longlong param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0xd8);
  if (lVar3 == 0) {
    *(int *)(param_2 + 0x110) = param_3;
    lVar3 = param_2 + 0xf8;
    goto LAB_140006478;
  }
  iVar2 = *(int *)(lVar3 + 4);
  if ((iVar2 == 2) || (iVar2 == 0)) {
    *(undefined4 *)(lVar3 + 0x34) = *(undefined4 *)(param_2 + 0x34);
LAB_14000640b:
    *(undefined4 *)(lVar3 + 0x38) = *(undefined4 *)(param_2 + 0x38);
  }
  else if (iVar2 == 1) {
    param_3 = PcpOidSet(param_1,lVar3,param_2,param_3);
  }
  else {
    *(undefined4 *)(lVar3 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    if (iVar2 != 0xc) goto LAB_14000640b;
    *(undefined4 *)(lVar3 + 0x40) = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(lVar3 + 0x44) = *(undefined4 *)(param_2 + 0x44);
    *(undefined4 *)(lVar3 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  }
  *(undefined8 *)(param_2 + 0xd8) = 0;
  NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x28),param_2);
  NdisFOidRequestComplete(*(undefined8 *)(param_1 + 0x28),lVar3,param_3);
  LOCK();
  piVar1 = (int *)(param_1 + 100);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 != 1) {
    return;
  }
  lVar3 = param_1 + 0x68;
LAB_140006478:
  NdisSetEvent(lVar3);
  return;
}



===== PcpProcessFilterRequest @ 1400064e0 =====

int PcpProcessFilterRequest(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_2 + 0xd8);
  iVar2 = *(int *)(lVar1 + 4);
  if ((iVar2 == 2) || (iVar2 == 0)) {
    *(undefined4 *)(lVar1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
  }
  else {
    if (iVar2 == 1) {
      iVar2 = PcpOidSet(param_1,lVar1,param_2,param_3);
      return iVar2;
    }
    *(undefined4 *)(lVar1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    if (iVar2 == 0xc) {
      *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
      *(undefined4 *)(lVar1 + 0x44) = *(undefined4 *)(param_2 + 0x44);
      *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
      return param_3;
    }
  }
  *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)(param_2 + 0x38);
  return param_3;
}



===== PcpOidSet @ 140006550 =====

int PcpOidSet(longlong param_1,longlong param_2,longlong param_3,int param_4)

{
  uint uVar1;
  int *_Src;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  size_t _Size;
  int iVar7;
  void *local_res10;
  undefined1 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffd8;
  
  iVar7 = 0;
  iVar2 = 0;
  _Src = *(int **)(param_2 + 0x28);
  uVar1 = *(uint *)(param_2 + 0x30);
  if (*(int *)(param_2 + 0x20) != 0x10118) {
    if ((((*(int *)(param_2 + 0x20) == 0x4010104) && (*(int *)(param_1 + 0x10) == 3)) &&
        (param_4 == 0)) && (5 < uVar1)) {
      *(ushort *)(param_1 + 0xd4) = CONCAT11((char)_Src[1],*(undefined1 *)((longlong)_Src + 5));
    }
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_3 + 0x34);
    *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_3 + 0x38);
    return param_4;
  }
  local_res10 = (void *)0x0;
  if ((_Src != (int *)0x0) && (_Size = 6, 5 < uVar1)) {
    puVar4 = (ushort *)((longlong)_Src + 6);
    for (iVar3 = 0; iVar5 = (int)_Size, iVar3 < *_Src; iVar3 = iVar3 + 1) {
      uVar6 = iVar5 + *puVar4 + 4;
      _Size = (size_t)uVar6;
      if (uVar1 < uVar6) goto LAB_1400065f9;
      puVar4 = (ushort *)((longlong)puVar4 + (ulonglong)(*puVar4 + 4));
    }
    if (iVar5 == 0) goto LAB_1400065fb;
    iVar2 = NdisAllocateMemoryWithTag(&local_res10);
    iVar7 = iVar2;
    if (iVar2 == 0) {
      memmove(local_res10,_Src,_Size);
      goto LAB_1400065fb;
    }
  }
LAB_1400065f9:
  iVar2 = iVar7;
  iVar5 = 0;
LAB_1400065fb:
  PcpLineUpdate(*(longlong *)(param_1 + 0xa0),0,0,(undefined8 *)0x0,0,0,0,in_stack_ffffffffffffffd0,
                in_stack_ffffffffffffffd8,(longlong)local_res10,iVar5);
  return iVar2;
}



===== PcFilterStatus @ 1400066a0 =====

/* WARNING: Removing unreachable block (ram,0x000140006901) */
/* WARNING: Removing unreachable block (ram,0x00014000690d) */
/* WARNING: Removing unreachable block (ram,0x000140006937) */
/* WARNING: Removing unreachable block (ram,0x00014000693b) */
/* WARNING: Removing unreachable block (ram,0x00014000694b) */
/* WARNING: Removing unreachable block (ram,0x00014000694f) */
/* WARNING: Removing unreachable block (ram,0x000140006951) */
/* WARNING: Removing unreachable block (ram,0x000140006954) */
/* WARNING: Removing unreachable block (ram,0x00014000696a) */
/* WARNING: Removing unreachable block (ram,0x00014000696e) */

void PcFilterStatus(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  bool bVar10;
  undefined2 local_res8;
  undefined1 local_resa;
  
  if (*(int *)(param_1 + 0x18) - 1U < 4) {
    iVar2 = *(int *)(param_2 + 0x14);
    if (iVar2 == 0x40010008) {
      PcpFilterStatusWanLineUp(param_1,param_2);
    }
    else if (iVar2 == 0x40010009) {
      PcpFilterStatusWanLineDown(param_1,param_2);
    }
    else {
      if (iVar2 == 0x40010017) {
        uVar8 = *(ulonglong *)(*(longlong *)(param_2 + 0x30) + 0x10);
        if (uVar8 != 0xffffffffffffffff) {
          lVar6 = *(longlong *)(param_1 + 0xa0);
          uVar8 = uVar8 >> 3;
          local_res8 = 0;
          local_resa = 0;
          NdisAcquireRWLockWrite(*(undefined8 *)(lVar6 + 0x10),&local_res8);
          if (*(int *)(lVar6 + 0xf4) == 0) {
            NdisReleaseRWLock(*(undefined8 *)(lVar6 + 0x10),&local_res8);
          }
          else {
            uVar3 = *(undefined4 *)(lVar6 + 0x134);
            uVar9 = 0;
            uVar4 = *(undefined4 *)(lVar6 + 0x130);
            puVar1 = (undefined8 *)(lVar6 + 0x128);
            if (puVar1 != (undefined8 *)0x0) {
              *(undefined8 *)(lVar6 + 0x18) = *puVar1;
            }
            uVar5 = *(uint *)(lVar6 + 0xe8);
            bVar10 = (uVar5 >> 1 & 1) != 0;
            if (bVar10) {
              *(uint *)(lVar6 + 0xe8) = uVar5 & 2 ^ uVar5;
            }
            if ((uVar8 != 0) && (uVar8 != *(ulonglong *)(lVar6 + 0x20))) {
              *(ulonglong *)(lVar6 + 0x20) = uVar8;
              bVar10 = true;
            }
            if (bVar10) {
              QosLineComputeControlInterval(lVar6 + 0x18);
              QosLineComputeBufferSizes(lVar6 + 0x18);
              lVar7 = *(longlong *)(lVar6 + 0x78);
              if ((lVar7 != 0) && (lVar7 != *(longlong *)(lVar6 + 0x20))) {
                uVar9 = ((ulonglong)*(uint *)(lVar6 + 0x8c) * lVar7) / 1000000;
              }
              *(ulonglong *)(lVar6 + 0xd8) = uVar9;
              *(undefined4 *)(lVar6 + 0x134) = uVar3;
            }
            else {
              *(undefined4 *)(lVar6 + 0x134) = uVar3;
            }
            *(undefined4 *)(lVar6 + 0x130) = uVar4;
            *puVar1 = *puVar1;
            NdisReleaseRWLock(*(undefined8 *)(lVar6 + 0x10),&local_res8);
          }
        }
        NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28),param_2);
        return;
      }
      if (iVar2 == 0x40030036) {
        if ((*(int *)(param_1 + 0x14) - 1U & 0xfffffff7) == 0) {
          PcpHandleDot11DSCPToUPMappingIndication
                    ((undefined8 *)(param_1 + 0xd6),*(longlong *)(param_2 + 0x30));
          NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28),param_2);
        }
      }
      else {
        NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28));
      }
    }
  }
  return;
}



===== QosLineUpdate @ 1400069c0 =====

undefined8 QosLineUpdate(undefined8 *param_1,undefined8 *param_2,longlong param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  
  uVar10 = 0;
  bVar4 = false;
  if (param_2 != (undefined8 *)0x0) {
    *param_1 = *param_2;
  }
  if (param_4 != (uint *)0x0) {
    uVar1 = *(uint *)(param_1 + 0x1a);
    if (((uVar1 >> 1 ^ param_4[6]) & 1) != 0) {
      bVar4 = true;
      *(uint *)(param_1 + 0x1a) = (param_4[6] * 2 ^ uVar1) & 2 ^ uVar1;
    }
  }
  if ((param_3 != 0) && (param_3 != param_1[1])) {
    param_1[1] = param_3;
    bVar4 = true;
  }
  if (param_4 != (uint *)0x0) {
    if (*(longlong *)(param_4 + 4) - 1U < 0xfffffffffffffffe) {
      param_1[0xc] = *(longlong *)(param_4 + 4);
      bVar4 = true;
    }
    if (param_4[2] != 0) {
      uVar1 = param_4[1];
      uVar2 = param_4[3];
      uVar3 = *param_4;
      uVar5 = *(uint *)(param_1 + 0xe);
      uVar7 = *(int *)((longlong)param_1 + 0x6c) + param_4[2];
      *(uint *)((longlong)param_1 + 0x6c) = uVar7;
      lVar9 = (ulonglong)*(uint *)(param_1 + 0xd) + (longlong)(int)uVar2;
      if (0xfffffffe < lVar9) {
        lVar9 = 0xffffffff;
      }
      *(int *)(param_1 + 0xd) = (int)lVar9;
      if (uVar5 == uVar3) {
        uVar5 = 0;
      }
      if (uVar5 <= uVar1) {
        uVar5 = uVar1;
      }
      *(uint *)(param_1 + 0xe) = uVar5;
      uVar6 = (ulonglong)*(uint *)((longlong)param_1 + 0xcc) * (ulonglong)uVar7 * 2;
      if (0xfffffffe < uVar6) {
        uVar6 = 0xffffffff;
      }
      *(int *)((longlong)param_1 + 0x7c) = (int)uVar6;
      goto LAB_140006a28;
    }
  }
  if (!bVar4) {
    return 0;
  }
LAB_140006a28:
  puVar8 = param_1;
  QosLineComputeControlInterval((longlong)param_1);
  QosLineComputeBufferSizes((longlong)puVar8);
  lVar9 = param_1[0xc];
  if ((lVar9 != 0) && (lVar9 != param_1[1])) {
    uVar10 = ((ulonglong)*(uint *)((longlong)param_1 + 0x74) * lVar9) / 1000000;
  }
  param_1[0x18] = uVar10;
  return 0;
}



===== PcpLineUpdate @ 140006b00 =====

/* WARNING: Removing unreachable block (ram,0x000140006d4d) */
/* WARNING: Removing unreachable block (ram,0x000140006d58) */
/* WARNING: Removing unreachable block (ram,0x000140006d85) */
/* WARNING: Removing unreachable block (ram,0x000140006d89) */
/* WARNING: Removing unreachable block (ram,0x000140006d93) */
/* WARNING: Removing unreachable block (ram,0x000140006d97) */
/* WARNING: Removing unreachable block (ram,0x000140006d9b) */
/* WARNING: Removing unreachable block (ram,0x000140006da0) */
/* WARNING: Removing unreachable block (ram,0x000140006db6) */
/* WARNING: Removing unreachable block (ram,0x000140006dba) */

void PcpLineUpdate(longlong param_1,longlong param_2,longlong param_3,undefined8 *param_4,
                  longlong param_5,int param_6,int param_7,undefined1 param_8,undefined8 param_9,
                  longlong param_10,undefined4 param_11)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined1 uStack0000000000000042;
  
  _param_8 = 0;
  uStack0000000000000042 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x10),&param_8,0);
  if (*(int *)(param_1 + 0xf4) != 0) {
    if (param_6 == 0) {
      param_6 = *(int *)(param_1 + 0x130);
    }
    if (param_7 == 0) {
      param_7 = *(int *)(param_1 + 0x134);
    }
    if (param_3 == 0) {
      param_3 = param_1 + 0x118;
    }
    if (param_2 == 0) {
      param_2 = param_1 + 0x108;
    }
    if (param_4 == (undefined8 *)0x0) {
      param_4 = (undefined8 *)(param_1 + 0x128);
    }
    if (param_4 != (undefined8 *)0x0) {
      *(undefined8 *)(param_1 + 0x18) = *param_4;
    }
    uVar1 = *(uint *)(param_1 + 0xe8);
    bVar4 = (uVar1 >> 1 & 1) != 0;
    if (bVar4) {
      *(uint *)(param_1 + 0xe8) = uVar1 & 2 ^ uVar1;
    }
    if ((param_5 != 0) && (param_5 != *(longlong *)(param_1 + 0x20))) {
      *(longlong *)(param_1 + 0x20) = param_5;
      bVar4 = true;
    }
    uVar3 = 0;
    if (bVar4) {
      QosLineComputeControlInterval(param_1 + 0x18);
      QosLineComputeBufferSizes(param_1 + 0x18);
      lVar2 = *(longlong *)(param_1 + 0x78);
      if ((lVar2 != 0) && (lVar2 != *(longlong *)(param_1 + 0x20))) {
        uVar3 = ((ulonglong)*(uint *)(param_1 + 0x8c) * lVar2) / 1000000;
      }
      *(ulonglong *)(param_1 + 0xd8) = uVar3;
    }
    *(int *)(param_1 + 0x130) = param_6;
    *(int *)(param_1 + 0x134) = param_7;
    *(undefined8 *)(param_1 + 0x128) = *param_4;
    if (param_3 != param_1 + 0x118) {
      RtlCopyUnicodeString(param_1 + 0x118,param_3);
    }
    if (param_2 != param_1 + 0x108) {
      RtlCopyUnicodeString(param_1 + 0x108,param_2);
    }
    lVar2 = param_10;
    if (param_10 != -1) {
      if (*(longlong *)(param_1 + 0x140) != 0) {
        NdisFreeMemoryWithTag(*(longlong *)(param_1 + 0x140),0x616e6350);
      }
      *(undefined4 *)(param_1 + 0x138) = param_11;
      *(longlong *)(param_1 + 0x140) = lVar2;
    }
    if ((lVar2 != -1) && (*(int *)(param_1 + 0xf4) == 2)) {
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&param_8);
      PcpTcIndicateInterfaceChange(param_1,-0xffffff);
      return;
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&param_8);
  return;
}



===== QosLineComputeBufferSizes @ 140006e20 =====

void QosLineComputeBufferSizes(longlong param_1)

{
  undefined1 auVar1 [16];
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  
  uVar3 = *(ulonglong *)(param_1 + 8);
  iVar5 = 0;
  if (uVar3 == 0xffffffffffffffff) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(uint *)(param_1 + 0x74) * uVar3) / 1000000;
    if ((uVar3 < 0x8000001) || (uVar3 < 0xc80001)) {
      uVar2 = 0x32;
    }
    else {
      uVar2 = 0x17;
      iVar5 = 0xc;
    }
    if (10 < *(uint *)(param_1 + 0x68)) {
      uVar2 = uVar2 + iVar5;
    }
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar2 * uVar6;
    lVar4 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
    iVar5 = (int)((uVar2 * uVar6 - lVar4 >> 1) + lVar4 >> 6);
  }
  *(int *)(param_1 + 0xcc) = (int)uVar6;
  uVar3 = (ulonglong)*(uint *)(param_1 + 0x6c) * (uVar6 & 0xffffffff) * 2;
  *(int *)(param_1 + 0x78) = iVar5;
  if (0xfffffffe < uVar3) {
    uVar3 = 0xffffffff;
  }
  *(int *)(param_1 + 0x7c) = (int)uVar3;
  return;
}



===== QosLineComputeControlInterval @ 140006ed4 =====

void QosLineComputeControlInterval(longlong param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar2 = 1;
  if (*(ulonglong *)(param_1 + 8) < 0xc80001) {
    uVar1 = 10000;
    uVar3 = 10000;
  }
  else {
    if (*(ulonglong *)(param_1 + 8) < 0x8000001) {
      *(undefined4 *)(param_1 + 0x74) = 1000;
      uVar1 = 5000;
      uVar3 = 7000;
      goto LAB_140006f00;
    }
    uVar1 = 500;
    uVar2 = 10;
    uVar3 = 0x30d4;
  }
  *(undefined4 *)(param_1 + 0x74) = uVar1;
LAB_140006f00:
  if (*(uint *)(param_1 + 0x68) < 0xb) {
    return;
  }
  if (0x1d < *(uint *)(param_1 + 0x68)) {
    uVar1 = (undefined4)(uVar3 / uVar2);
  }
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  return;
}



===== PcpTcIndicateInterfaceChange @ 140006f44 =====

void PcpTcIndicateInterfaceChange(longlong param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint local_res18 [2];
  
  local_res18[0] = 0;
  PcpCollectNetworkAddressList(param_1,local_res18,(undefined2 *)0x0);
  uVar2 = local_res18[0] + 8;
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,uVar2,0x696d7750);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    PcpCollectNetworkAddressList(param_1,local_res18,(undefined2 *)(puVar1 + 2));
    PcpTcNotify(param_1,param_2,puVar1,uVar2);
    ExFreePoolWithTag(puVar1,0);
  }
  return;
}



===== PcpCollectNetworkAddressList @ 140006fe8 =====

undefined8 PcpCollectNetworkAddressList(longlong param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x10),&local_res8,0);
  if (*(longlong *)(param_1 + 0x140) == 0) {
    iVar3 = 6;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x138);
  }
  uVar4 = iVar3 + 0x214;
  if (*param_2 < uVar4) {
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res8);
    uVar2 = 0xc0000023;
    *param_2 = uVar4;
  }
  else {
    memset(param_3,0,(ulonglong)*param_2);
    memmove(param_3 + 1,*(void **)(param_1 + 0x120),(ulonglong)*(ushort *)(param_1 + 0x118));
    *param_3 = *(undefined2 *)(param_1 + 0x118);
    *(undefined8 *)(param_3 + 0x104) = *(undefined8 *)(param_1 + 0x128);
    if (*(longlong *)(param_1 + 0x100) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x100) + 0x10);
    }
    *(undefined4 *)(param_3 + 0x108) = uVar1;
    if (*(void **)(param_1 + 0x140) == (void *)0x0) {
      *(undefined4 *)(param_3 + 0x10a) = 0;
      param_3[0x10c] = 0;
    }
    else {
      memmove(param_3 + 0x10a,*(void **)(param_1 + 0x140),(ulonglong)*(uint *)(param_1 + 0x138));
    }
    *param_2 = uVar4;
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res8);
    uVar2 = 0;
  }
  return uVar2;
}



===== PcpTcNotify @ 140007130 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PcpTcNotify(longlong param_1,int param_2,void *param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  void *_Src;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *_Dst;
  uint *_Dst_00;
  undefined8 *puVar8;
  uint uVar9;
  
  _Src = *(void **)(param_1 + 0x110);
  puVar8 = (undefined8 *)&PcgSupportedGuids;
  uVar1 = *(ushort *)(param_1 + 0x108);
  uVar5 = 0;
  while( true ) {
    if (0x17 < uVar5) {
      return -0x3fffffff;
    }
    uVar2 = *(uint *)(puVar8 + 3);
    if (((uVar2 & 2) != 0) && (*(int *)(puVar8 + 2) == param_2)) break;
    uVar5 = uVar5 + 1;
    puVar8 = (undefined8 *)((longlong)puVar8 + 0x1c);
  }
  if ((uVar2 & 0x20) == 0) {
    return -0x3fffffff;
  }
  uVar5 = param_4 + 4;
  if ((uVar2 & 0x10) == 0) {
    uVar5 = param_4;
  }
  uVar9 = (uVar1 + 9 & 0xfffffff8) + 0x40;
  if ((uVar9 < 0x40) || (uVar6 = uVar5 + uVar9, uVar6 < uVar9)) {
    return -0x3fffff6b;
  }
  _Dst = (uint *)ExAllocatePool2(0x40,uVar6,0x696d7750);
  if (_Dst == (uint *)0x0) {
    return -0x3fffffff;
  }
  memset(_Dst,0,(ulonglong)uVar6);
  *_Dst = uVar6;
  uVar6 = IoWMIDeviceObjectToProviderId(PcgDeviceObject);
  _Dst[1] = uVar6;
  _Dst[2] = 1;
  *(undefined8 *)(_Dst + 4) = _DAT_fffff78000000014;
  uVar3 = *puVar8;
  uVar4 = puVar8[1];
  _Dst[0xb] = 10;
  *(undefined8 *)(_Dst + 6) = uVar3;
  *(undefined8 *)(_Dst + 8) = uVar4;
  _Dst[0xc] = 0x40;
  _Dst[0xe] = uVar9;
  _Dst[0xf] = uVar5;
  *(ushort *)(_Dst + 0x10) = uVar1;
  memmove((void *)((longlong)_Dst + 0x42),_Src,(ulonglong)uVar1);
  _Dst_00 = (uint *)((ulonglong)_Dst[0xe] + (longlong)_Dst);
  if ((uVar2 & 0x10) == 0) {
    if (uVar5 == 0) goto LAB_14000729a;
  }
  else {
    if ((param_3 == (void *)0x0) || (param_4 == 0)) {
      *_Dst_00 = 0;
      goto LAB_14000729a;
    }
    *_Dst_00 = param_4 / *(uint *)((longlong)puVar8 + 0x14);
    _Dst_00 = _Dst_00 + 1;
    uVar5 = param_4;
  }
  memmove(_Dst_00,param_3,(ulonglong)uVar5);
LAB_14000729a:
  iVar7 = IoWMIWriteEvent(_Dst);
  if (iVar7 < 0) {
    ExFreePoolWithTag(_Dst,0);
    return iVar7;
  }
  return iVar7;
}



===== PcpTraceLineUpDownEvent @ 1400072fc =====

void PcpTraceLineUpDownEvent(undefined8 param_1)

{
  undefined *puVar1;
  int in_stack_00000038;
  
  if (PcgEventTraceEnabled != 0) {
    puVar1 = &QOS_EVENT_PACER_START;
    if (0xf < in_stack_00000038) {
      puVar1 = &QOS_EVENT_PACER_STOP;
    }
    PcpEtwWriteEventUlongPtr(puVar1,0,0,7,param_1);
  }
  return;
}



===== PcpFilterDecrementPauseCount @ 14000740c =====

int PcpFilterDecrementPauseCount(longlong param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x80);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -param_2;
  UNLOCK();
  iVar2 = iVar2 + -param_2;
  if (iVar2 == 0) {
    NdisSetEvent(param_1 + 0x88);
  }
  return iVar2;
}



===== PcpFilterDecrementDetachCount @ 140007450 =====

int PcpFilterDecrementDetachCount(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 100);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    NdisSetEvent(param_1 + 0x68);
  }
  return iVar2 + -1;
}



===== QosLineCreate @ 140007488 =====

ulonglong QosLineCreate(undefined8 *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                       undefined8 param_5)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  memset(param_1,0,0xd8);
  uVar4 = 0;
  param_1[4] = param_4;
  param_1[5] = param_5;
  lVar5 = -1;
  if (param_3 != 0) {
    lVar5 = param_3;
  }
  uVar1 = KeGetCurrentProcessorNumberEx(0);
  uVar2 = QosTimerGetCurrentTime(uVar1,'\x01','\0');
  *param_1 = param_2;
  if ((lVar5 != 0) && (lVar5 != param_1[1])) {
    param_1[1] = lVar5;
    puVar3 = param_1;
    QosLineComputeControlInterval((longlong)param_1);
    QosLineComputeBufferSizes((longlong)puVar3);
    lVar5 = param_1[0xc];
    if ((lVar5 != 0) && (lVar5 != param_1[1])) {
      uVar4 = ((ulonglong)*(uint *)((longlong)param_1 + 0x74) * lVar5) / 1000000;
    }
    param_1[0x18] = uVar4;
  }
  lVar5 = uVar2 - uVar2 % (ulonglong)*(uint *)((longlong)param_1 + 0x74);
  param_1[0x14] = lVar5;
  param_1[0x15] = lVar5;
  return uVar2 / *(uint *)((longlong)param_1 + 0x74);
}



===== PcpUpdateFlow @ 140007580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PcpUpdateFlow(undefined8 *param_1,ulonglong param_2,uint param_3,int param_4,
                       ulonglong *param_5,char param_6,int param_7,undefined4 *param_8,
                       ushort *param_9,ushort *param_10)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  bool bVar4;
  code *pcVar5;
  byte bVar6;
  uint uVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong *puVar16;
  undefined2 *puVar17;
  undefined8 *puVar18;
  int iVar19;
  undefined *puVar20;
  undefined1 *puVar21;
  ulonglong *puVar22;
  ulonglong uVar23;
  undefined *puVar24;
  longlong *plVar25;
  undefined4 uVar26;
  ulonglong *puVar27;
  undefined4 uVar28;
  int iVar29;
  bool bVar30;
  undefined1 auStackY_228 [8];
  undefined1 auStackY_220 [24];
  byte *pbVar31;
  char local_1d8;
  undefined2 local_1d4;
  undefined1 local_1d2;
  uint local_1d0;
  uint local_1cc;
  int local_1c8;
  int local_1c4;
  ulonglong local_1c0;
  undefined4 local_1b8 [2];
  ulonglong local_1b0;
  ulonglong uStack_1a8;
  ulonglong local_1a0;
  uint uStack_198;
  undefined4 uStack_194;
  undefined8 local_190;
  uint local_188;
  longlong *local_180;
  longlong *local_178;
  ushort *local_170;
  ushort *local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  longlong local_138;
  undefined8 uStack_130;
  uint local_128 [12];
  longlong local_f8 [5];
  longlong local_d0;
  longlong local_c8;
  longlong local_b8;
  longlong local_b0;
  ulonglong local_a8;
  ulonglong local_a0;
  ulonglong local_98;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  byte local_78;
  char local_77;
  char local_76;
  char local_75;
  char local_74;
  char local_73;
  int local_70;
  uint local_6c;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_228;
  local_170 = param_9;
  local_168 = param_10;
  local_1cc = param_3;
  local_1c8 = param_4;
  local_1c0 = param_2;
  memset(&local_a8,0,0x40);
  local_150 = 0;
  local_48 = 0;
  local_178 = (longlong *)0x0;
  local_180 = (longlong *)0x0;
  local_160 = 0;
  uStack_158 = 0;
  uStack_194 = 0;
  puVar11 = (undefined8 *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_1d4 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_1d2 = 0;
  memset(local_f8,0,0x50);
  puVar21 = auStackY_228;
  local_1d8 = '\0';
  *param_9 = 0xffff;
  *param_10 = 0xffff;
  local_1b8[0] = 0;
  local_1c4 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  local_1d0 = *(uint *)(&PcgFlowTypeToFeatureFlagsMapping + (longlong)local_1c8 * 4);
  if (local_1c8 == 2) {
    local_1b0 = *param_5;
    puVar27 = (ulonglong *)param_5[9];
    uVar7 = (uint)param_5[8];
    local_190 = 0xffffffffffffffff;
    uStack_1a8 = param_5[1];
    local_1a0 = param_5[2];
    uStack_198 = (uint)param_5[3];
LAB_14000777a:
    if (param_6 != '\x01') {
      puVar22 = (ulonglong *)param_1[0x4b];
      if (local_1c8 == 2) {
        local_68 = *puVar22;
        local_48 = 0xffffffffffffffff;
        uStack_60 = puVar22[1];
        local_58 = puVar22[2];
        uStack_50 = CONCAT44(uStack_50._4_4_,(uint)puVar22[3]);
      }
      else {
        local_68 = 0xffffffffffffffff;
        puVar16 = (ulonglong *)((longlong)puVar22 + 0x20c);
        if (local_1c8 != 1) {
          puVar16 = puVar22;
        }
        if ((uint)*puVar16 != 0xffffffff) {
          local_68 = (ulonglong)(uint)*puVar16;
        }
        uStack_60 = 0xffffffffffffffff;
        if (*(uint *)((longlong)puVar16 + 4) != 0xffffffff) {
          uStack_60 = (ulonglong)*(uint *)((longlong)puVar16 + 4);
        }
        local_58 = 0xffffffffffffffff;
        if ((uint)puVar16[1] != 0xffffffff) {
          local_58 = (ulonglong)(uint)puVar16[1];
        }
        uStack_50 = CONCAT44(uStack_50._4_4_,*(uint *)((longlong)puVar16 + 0x14));
        local_48 = CONCAT44((uint)puVar16[3],*(uint *)((longlong)puVar16 + 0x1c));
      }
    }
    puVar22 = &local_68;
    if (param_6 != '\0') {
      puVar22 = (ulonglong *)0x0;
    }
    uVar9 = PcpValidateFlowParameters
                      (&local_1d0,&local_1b0,puVar22,(uint *)puVar27,uVar7,local_f8,param_7,
                       local_170,local_168);
    uVar23 = uVar9 & 0xffffffff;
    puVar21 = auStackY_228;
    if (-1 < (int)uVar9) {
      if ((param_6 == '\x01') && ((*(uint *)(param_1 + 0x4d) & 2) != 0)) {
        uVar7 = PcpFilterIncrementIntercept();
        uVar23 = (ulonglong)uVar7;
        puVar21 = auStackY_228;
        if ((int)uVar7 < 0) goto LAB_140007ba0;
        local_1d8 = param_6;
      }
      KeAcquireInStackQueuedSpinLock(param_1 + 0xc,&local_160);
      do {
      } while (*(int *)(param_1 + 0xd) != 0);
      if ((param_6 == '\0') && (*(uint *)(param_1 + 0x4c) < local_1cc)) {
        lVar10 = ExAllocatePool2(0x40,local_1cc,0x6c666350);
        if (lVar10 != 0) {
          if ((undefined8 *)param_1[0x4b] != param_1 + 0x4e) {
            ExFreePoolWithTag((undefined8 *)param_1[0x4b],0);
          }
          param_1[0x4b] = lVar10;
          goto LAB_14000793c;
        }
        uVar23 = 0xc000009a;
      }
      else {
LAB_14000793c:
        uVar7 = uStack_198;
        uVar9 = local_1a0;
        uVar23 = uStack_1a8;
        if (local_1c0 != 0) {
          param_1[0x4a] = local_1c0;
        }
        *(uint *)(param_1 + 6) = local_1d0;
        puVar27 = (ulonglong *)param_1[0x4b];
        *(uint *)(param_1 + 0x4c) = local_1cc;
        if (local_1c8 == 2) {
          memmove(puVar27,param_5,(ulonglong)local_1cc);
          puVar27 = (ulonglong *)param_1[0x4b];
          *puVar27 = local_1b0;
          puVar27[1] = uStack_1a8;
          puVar27[2] = local_1a0;
          puVar27[3] = CONCAT44(uStack_194,uStack_198);
LAB_140007a6c:
          if ((uint)param_5[8] != 0) {
            memmove((void *)(param_1[0x4b] + 0x50),(void *)param_5[9],(ulonglong)(uint)param_5[8]);
            *(longlong *)(param_1[0x4b] + 0x48) = param_1[0x4b] + 0x50;
          }
        }
        else {
          uVar28 = (undefined4)uStack_1a8;
          uVar26 = (undefined4)local_1a0;
          if (local_1c8 != 1) {
            uVar12 = param_5[1];
            *puVar27 = *param_5;
            puVar27[1] = uVar12;
            uVar12 = param_5[3];
            puVar27[2] = param_5[2];
            puVar27[3] = uVar12;
            uVar12 = param_5[5];
            puVar27[4] = param_5[4];
            puVar27[5] = uVar12;
            uVar12 = param_5[7];
            puVar27[6] = param_5[6];
            puVar27[7] = uVar12;
            uVar12 = param_5[9];
            puVar27[8] = param_5[8];
            puVar27[9] = uVar12;
            puVar3 = (undefined4 *)param_1[0x4b];
            uVar8 = 0xffffffff;
            if (local_1b0 != 0xffffffffffffffff) {
              uVar8 = (int)local_1b0;
            }
            *puVar3 = uVar8;
            uVar8 = 0xffffffff;
            if (uStack_1a8 != 0xffffffffffffffff) {
              uVar8 = uVar28;
            }
            puVar3[5] = uStack_198;
            puVar3[1] = uVar8;
            uVar28 = 0xffffffff;
            if (local_1a0 != 0xffffffffffffffff) {
              uVar28 = uVar26;
            }
            puVar3[2] = uVar28;
            puVar3[7] = (undefined4)local_190;
            puVar3[6] = local_190._4_4_;
            goto LAB_140007a6c;
          }
          memmove(puVar27,param_5,(ulonglong)local_1cc);
          lVar10 = param_1[0x4b];
          uVar8 = 0xffffffff;
          if (local_1b0 != 0xffffffffffffffff) {
            uVar8 = (int)local_1b0;
          }
          *(undefined4 *)(lVar10 + 0x20c) = uVar8;
          uVar8 = 0xffffffff;
          if (uVar23 != 0xffffffffffffffff) {
            uVar8 = uVar28;
          }
          *(uint *)(lVar10 + 0x220) = uVar7;
          *(undefined4 *)(lVar10 + 0x210) = uVar8;
          *(undefined4 *)(lVar10 + 0x228) = (undefined4)local_190;
          uVar28 = 0xffffffff;
          if (uVar9 != 0xffffffffffffffff) {
            uVar28 = uVar26;
          }
          *(undefined4 *)(lVar10 + 0x214) = uVar28;
          *(undefined4 *)(lVar10 + 0x224) = local_190._4_4_;
        }
        local_a0 = uVar23;
        local_98 = uVar9;
        local_a8 = local_1b0;
        if ((local_b8 == 0) || (iVar29 = *(int *)(local_b8 + 8), iVar29 == -1)) {
          iVar29 = *(int *)(param_1 + 0x39);
        }
        local_88 = (undefined4)local_190;
        local_70 = iVar29;
        if ((iVar29 == 0) || (puVar11 != (undefined8 *)0x0)) {
LAB_140007b29:
          if (local_d0 == 0) {
LAB_140007bf5:
            uVar23 = 0;
            puVar20 = &PcgSettings;
            if ((puVar11 == (undefined8 *)0x0) ||
               (puVar24 = (undefined *)(puVar11[0x20] + 0xa8), puVar11[0x20] == 0)) {
              puVar24 = &PcgSettings;
            }
            pbVar31 = &local_78;
            plVar25 = local_f8;
            PcpMrkSetMarkingValues((longlong)param_1,uVar7,(longlong)puVar24,plVar25,pbVar31);
            if ((puVar11 != (undefined8 *)0x0) && (puVar11[0x20] != 0)) {
              puVar20 = (undefined *)(puVar11[0x20] + 0xa8);
            }
            if (local_d0 == 0) {
              if ((*(uint *)(param_1 + 6) & 0x1000) == 0) {
                local_84 = 1;
              }
              else if (uVar7 == 2) {
                local_84 = *(undefined4 *)(puVar20 + 8);
              }
              else if (uVar7 == 3) {
                local_84 = *(undefined4 *)(puVar20 + 0xc);
              }
              else if (uVar7 != 6) {
                if (uVar7 == 10) {
                  local_84 = *(undefined4 *)(puVar20 + 0x10);
                }
                else if (uVar7 == 0xd) {
                  local_84 = *(undefined4 *)(puVar20 + 0x14);
                }
                else {
                  local_84 = 0;
                }
              }
            }
            else {
              local_84 = *(undefined4 *)(local_d0 + 8);
            }
            if (local_c8 == 0) {
              local_80 = 0;
            }
            else {
              local_80 = *(undefined8 *)(local_c8 + 8);
            }
            local_1cc = KeGetCurrentProcessorNumberEx(0);
            uVar9 = (ulonglong)local_1cc;
            lVar10 = QosTimerGetCurrentTime(local_1cc,'\x01','\x01');
            local_128[5] = 0;
            puVar1 = (uint *)(param_1 + 0x11);
            local_128[6] = 0xffffffff;
            local_128[7] = 0x7fffffff;
            local_128[0] = *(uint *)(param_1 + 0x39);
            local_128[8] = 0;
            local_128[9] = 0;
            local_128[1] = 0;
            local_128[2] = 0;
            local_128[3] = 0;
            local_128[4] = 0;
            if ((local_128[0] != 0) &&
               (uVar12 = QosTbcAdjustBytesSent((longlong)puVar1,lVar10), (char)uVar12 != '\0')) {
              PcpLineSignalExternalEvent((longlong)puVar11,uVar9);
              puVar17 = &local_1d4;
              NdisAcquireRWLockWrite(puVar11[2],puVar17,0);
              QosLineQueryQueueFeedback((longlong)(puVar11 + 3),puVar17,local_128);
              NdisReleaseRWLock(puVar11[2],&local_1d4);
              QosTbcAdjustSendWindow((longlong)puVar1,(longlong)local_128);
            }
            uVar7 = local_6c;
            local_6c = local_6c | 1;
            local_1c0 = CONCAT44(local_1c0._4_4_,local_70);
            if (local_70 == -1) {
LAB_140007dfa:
              bVar6 = 1;
              uVar15 = *(uint *)(param_1 + 0x45);
              local_1d0 = 0;
              if (((uVar15 ^ local_6c) & 2) != 0) {
                *(uint *)(param_1 + 0x45) = (local_6c ^ uVar15) & 2 ^ uVar15;
              }
              if ((((local_78 == *(byte *)(param_1 + 0x1b)) &&
                   (local_77 == *(char *)((longlong)param_1 + 0xd9))) &&
                  (local_76 == *(char *)((longlong)param_1 + 0xda))) &&
                 (((local_75 == *(char *)((longlong)param_1 + 0xdb) &&
                   (local_74 == *(char *)((longlong)param_1 + 0xdc))) &&
                  (local_73 == *(char *)((longlong)param_1 + 0xdd))))) {
                local_1d0 = *puVar1;
              }
              else {
                *puVar1 = *puVar1 + 1;
                bVar6 = 0;
              }
              QosMrkFlowUpdate((longlong)puVar1,(longlong *)&local_a8);
              plVar25 = (longlong *)(-(ulonglong)bVar6 & (ulonglong)&local_1d0);
              QosTbcFlowUpdate((int *)puVar1,local_1cc,(longlong *)&local_a8,(int *)plVar25,
                               (longlong)pbVar31,local_1b8,(longlong *)&local_178,
                               (longlong *)&local_180);
              local_6c = uVar7 & 0xfffffffe;
              local_1d0 = uStack_140._4_4_;
              local_1c0 = CONCAT44(local_1c0._4_4_,local_148._4_4_);
              local_188 = (uint)local_148;
              iVar29 = (int)uStack_140;
            }
            else {
              local_188 = *(uint *)(param_1 + 0x39);
              iVar29 = local_70 - local_188;
              if (iVar29 == local_70) {
                local_1d0 = 1;
              }
              else {
                local_1d0 = (iVar29 != -local_188) - 1;
              }
              if (iVar29 == 0) goto LAB_140007dfa;
              uVar23 = 0x103;
            }
            uVar7 = local_6c;
            iVar19 = local_1c4;
            if (param_6 != '\0') {
              iVar19 = 1;
            }
            local_1c4 = iVar19;
            if ((int)uVar23 == 0x103) {
              NdisAcquireRWLockWrite(puVar11[2],&local_1d4,0);
              uVar15 = *(uint *)(puVar11 + 0x1d);
              bVar30 = ((uVar15 >> 1 ^ (uint)uStack_130) & 1) != 0;
              if (bVar30) {
                *(uint *)(puVar11 + 0x1d) = ((uint)uStack_130 * 2 ^ uVar15) & 2 ^ uVar15;
              }
              bVar4 = local_138 - 1U < 0xfffffffffffffffe;
              if (bVar4) {
                puVar11[0xf] = local_138;
              }
              if (iVar29 == 0) {
                if (bVar4 || bVar30) goto LAB_140007fd3;
              }
              else {
                uVar13 = *(int *)((longlong)puVar11 + 0x84) + iVar29;
                *(uint *)((longlong)puVar11 + 0x84) = uVar13;
                lVar10 = (ulonglong)*(uint *)(puVar11 + 0x10) + (longlong)(int)local_1d0;
                uVar15 = *(uint *)(puVar11 + 0x11);
                if (0xfffffffe < lVar10) {
                  lVar10 = 0xffffffff;
                }
                *(int *)(puVar11 + 0x10) = (int)lVar10;
                if (uVar15 == local_188) {
                  uVar15 = 0;
                }
                uVar14 = (uint)local_1c0;
                if ((uint)local_1c0 < uVar15) {
                  uVar14 = uVar15;
                }
                *(uint *)(puVar11 + 0x11) = uVar14;
                uVar23 = (ulonglong)*(uint *)((longlong)puVar11 + 0xe4) * (ulonglong)uVar13 * 2;
                if (0xfffffffe < uVar23) {
                  uVar23 = 0xffffffff;
                }
                *(int *)((longlong)puVar11 + 0x94) = (int)uVar23;
LAB_140007fd3:
                uVar23 = 0;
                QosLineComputeControlInterval((longlong)(puVar11 + 3));
                QosLineComputeBufferSizes((longlong)(puVar11 + 3));
                lVar10 = puVar11[0xf];
                if ((lVar10 != 0) && (lVar10 != puVar11[4])) {
                  uVar23 = ((ulonglong)*(uint *)((longlong)puVar11 + 0x8c) * lVar10) / 1000000;
                }
                puVar11[0x1b] = uVar23;
              }
              uVar23 = 0;
              uVar15 = *(int *)(puVar11 + 6) + iVar19;
              *(uint *)(puVar11 + 6) = uVar15;
              if (iVar19 < 1) {
                if (iVar19 == 0) {
                  *(int *)(puVar11 + 0xc) = *(int *)(puVar11 + 0xc) + 1;
                }
                else {
                  *(int *)(puVar11 + 0xb) = *(int *)(puVar11 + 0xb) + 1;
                }
              }
              else {
                uVar13 = *(uint *)(puVar11 + 0xd);
                if (*(uint *)(puVar11 + 0xd) <= uVar15) {
                  uVar13 = uVar15;
                }
                *(int *)((longlong)puVar11 + 0x54) = *(int *)((longlong)puVar11 + 0x54) + 1;
                *(uint *)(puVar11 + 0xd) = uVar13;
              }
              NdisReleaseRWLock(puVar11[2],&local_1d4);
              piVar2 = (int *)(param_1 + 0x11);
              uVar9 = local_1c0 >> 0x20;
              local_1c0 = local_1c0 & 0xffffffff00000000;
              uVar15 = *(uint *)(param_1 + 0x45);
              if (((uVar7 ^ uVar15) & 2) != 0) {
                *(uint *)(param_1 + 0x45) = (uVar7 ^ uVar15) & 2 ^ uVar15;
              }
              if (((((local_78 == *(byte *)(param_1 + 0x1b)) &&
                    (local_77 == *(char *)((longlong)param_1 + 0xd9))) &&
                   (local_76 == *(char *)((longlong)param_1 + 0xda))) &&
                  ((local_75 == *(char *)((longlong)param_1 + 0xdb) &&
                   (local_74 == *(char *)((longlong)param_1 + 0xdc))))) &&
                 (local_73 == *(char *)((longlong)param_1 + 0xdd))) {
                bVar6 = 1;
                local_1c0 = CONCAT44((int)uVar9,*piVar2);
              }
              else {
                *piVar2 = *piVar2 + 1;
                bVar6 = 0;
              }
              QosMrkFlowUpdate((longlong)piVar2,(longlong *)&local_a8);
              uVar7 = local_1cc;
              plVar25 = (longlong *)(-(ulonglong)bVar6 & (ulonglong)&local_1c0);
              QosTbcFlowUpdate(piVar2,local_1cc,(longlong *)&local_a8,(int *)plVar25,
                               (longlong)pbVar31,local_1b8,(longlong *)&local_178,
                               (longlong *)&local_180);
            }
            else {
              if (puVar11 != (undefined8 *)0x0) {
                NdisAcquireRWLockWrite(puVar11[2],&local_1d4);
                QosLineUpdateStats((longlong)(puVar11 + 3),&local_1c4);
                NdisReleaseRWLock(puVar11[2],&local_1d4);
              }
              uVar7 = local_1cc;
            }
            KeReleaseInStackQueuedSpinLock(&local_160);
            puVar21 = auStackY_228;
            if (param_6 == '\x01') {
              PcpCreateFlowInstanceName((longlong)param_1);
              RtlAcquireWriteLock(0x1400197f0);
              puVar21 = auStackY_228;
              puVar18 = &PcgFlowList;
              if ((undefined8 *)*DAT_1400197d8 != &PcgFlowList) {
                pcVar5 = (code *)swi(0x29);
                DAT_1400197d8 = (undefined8 *)(*pcVar5)(3);
                puVar21 = auStackY_220;
              }
              *param_1 = puVar18;
              param_1[1] = DAT_1400197d8;
              *DAT_1400197d8 = param_1;
              *(undefined8 *)(puVar21 + -8) = 0x1400081ed;
              DAT_1400197d8 = param_1;
              KeReleaseInStackQueuedSpinLock(&local_160);
              if (*(int *)(puVar21 + 0x60) == 1) {
                plVar25 = (longlong *)0x0;
                *(undefined8 *)(puVar21 + -8) = 0x14000820f;
                PcpTcNotify((longlong)puVar11,-0x4fefefa,puVar11 + 6,4);
              }
            }
            if (local_178 != (longlong *)0x0) {
              *(undefined8 *)(puVar21 + -8) = 0x140008226;
              PcpSchedulerBatchAndSendOrDropNblChain
                        (local_178,uVar7,0,(longlong *)CONCAT71((int7)((ulonglong)plVar25 >> 8),1));
            }
            if (local_180 != (longlong *)0x0) {
              *(undefined8 *)(puVar21 + -8) = 0x140008241;
              PcpSchedulerBatchAndSendOrDropNblChain(local_180,uVar7,0,(longlong *)0x0);
            }
            goto LAB_140007ba0;
          }
          if (iVar29 == -1) {
            iVar29 = *(int *)(param_1 + 0x39);
          }
          if (iVar29 == 0) {
            if ((local_1b0 != 0xffffffffffffffff) || (*(int *)(local_d0 + 8) == 0))
            goto LAB_140007bf5;
            uVar23 = 0xc0020081;
          }
          else {
            if (*(int *)(local_d0 + 8) - 1U < 2) goto LAB_140007bf5;
            uVar23 = 0xc0020083;
          }
        }
        else {
          if (local_b0 == 0) {
            lVar10 = param_1[0xb];
          }
          else {
            lVar10 = *(longlong *)(local_b0 + 8);
          }
          if (lVar10 == 0) {
            uVar23 = 0xc000000d;
          }
          else {
            puVar11 = PcpLineFindByLuid(lVar10);
            if (puVar11 != (undefined8 *)0x0) {
              param_1[0xb] = lVar10;
              goto LAB_140007b29;
            }
            uVar23 = 0xc0000225;
          }
        }
      }
      KeReleaseInStackQueuedSpinLock(&local_160);
      puVar21 = auStackY_228;
      if ((int)uVar23 < 0) {
        puVar21 = auStackY_228;
        if (local_1d8 != '\0') {
          PcpFilterDecrementIntercept(1);
          puVar21 = auStackY_228;
        }
      }
    }
LAB_140007ba0:
    if (puVar11 != (undefined8 *)0x0) {
      *(undefined8 *)(puVar21 + -8) = 0x140007bad;
      PcpLineDereference((longlong)puVar11);
    }
    if (-1 < (int)uVar23) goto LAB_140007bc5;
  }
  else {
    if (local_1c8 != 1) {
      puVar27 = (ulonglong *)param_5[9];
      uVar7 = (uint)param_5[8];
      puVar22 = param_5;
LAB_140007731:
      local_1b0 = 0xffffffffffffffff;
      if ((uint)*puVar22 != 0xffffffff) {
        local_1b0 = (ulonglong)(uint)*puVar22;
      }
      uStack_1a8 = 0xffffffffffffffff;
      if (*(uint *)((longlong)puVar22 + 4) != 0xffffffff) {
        uStack_1a8 = (ulonglong)*(uint *)((longlong)puVar22 + 4);
      }
      local_1a0 = 0xffffffffffffffff;
      if ((uint)puVar22[1] != 0xffffffff) {
        local_1a0 = (ulonglong)(uint)puVar22[1];
      }
      uStack_198 = *(uint *)((longlong)puVar22 + 0x14);
      local_190 = CONCAT44((uint)puVar22[3],*(uint *)((longlong)puVar22 + 0x1c));
      goto LAB_14000777a;
    }
    uVar7 = *(uint *)((longlong)param_5 + 0x24c);
    puVar27 = param_5 + 0x4a;
    if ((ushort)*param_5 < 0x1ff) {
      puVar11 = PcpLineFindByInstanceName((void *)((longlong)param_5 + 2),(ushort)*param_5);
      puVar21 = auStackY_228;
      if (puVar11 != (undefined8 *)0x0) {
        puVar22 = (ulonglong *)((longlong)param_5 + 0x20c);
        goto LAB_140007731;
      }
      uVar23 = 0xc0000225;
      local_170 = param_9;
    }
    else {
      uVar23 = 0xc000000d;
      local_170 = param_9;
    }
  }
  *local_170 = 0xffff;
  *local_168 = 0xffff;
LAB_140007bc5:
  *(undefined8 *)(puVar21 + -8) = 0x140007bd6;
  return uVar23;
}



===== PcpValidateFlowParameters @ 14000824c =====

undefined8
PcpValidateFlowParameters
          (uint *param_1,ulonglong *param_2,ulonglong *param_3,uint *param_4,uint param_5,
          longlong *param_6,int param_7,ushort *param_8,ushort *param_9)

{
  ulonglong *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  uint *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong lVar12;
  char cVar13;
  
  memset(param_6,0,0x50);
  uVar11 = (uint)param_2[3];
  bVar6 = false;
  if ((uVar11 & 0xffff0000) != 0) {
    *(undefined2 *)((longlong)param_2 + 0x1a) = 0;
    uVar11 = (uint)param_2[3];
  }
  uVar2 = *param_1;
  cVar13 = (char)uVar2;
  if (cVar13 == '\0') {
    bVar6 = false;
    if (uVar11 == 0) {
      param_2[4] = 0xffffffffffffffff;
      uVar11 = 1;
      *(undefined4 *)(param_2 + 3) = 1;
      *param_2 = 0xffffffffffffffff;
      param_2[1] = 0xffffffffffffffff;
      param_2[2] = 0xffffffffffffffff;
    }
    else if (uVar11 == 6) {
      if (param_3 == (ulonglong *)0x0) {
        param_2[4] = 0xffffffffffffffff;
        uVar11 = 1;
        *(undefined4 *)(param_2 + 3) = 1;
        *param_2 = 0xffffffffffffffff;
        param_2[1] = 0xffffffffffffffff;
        param_2[2] = 0xffffffffffffffff;
      }
      else {
        uVar10 = param_3[1];
        *param_2 = *param_3;
        param_2[1] = uVar10;
        uVar10 = param_3[3];
        param_2[2] = param_3[2];
        param_2[3] = uVar10;
        param_2[4] = param_3[4];
        uVar11 = (uint)param_2[3];
      }
      bVar6 = true;
    }
    if (((int)param_2[4] == 0) || ((int)param_2[4] == -1)) {
      *(undefined4 *)(param_2 + 4) = 0x80;
    }
  }
  if (uVar11 != 1) {
    if ((uVar11 == 2) || (uVar11 == 3)) {
      if (*param_2 == 0xffffffffffffffff) {
        return 0xc0020081;
      }
    }
    else if (uVar11 == 10) {
      if (cVar13 == '\0') {
        return 0xc0020080;
      }
    }
    else if (uVar11 != 0xd) {
      return 0xc0020080;
    }
  }
  uVar10 = *param_2;
  if (uVar10 == 0) {
    return 0xc0020081;
  }
  puVar1 = param_2 + 2;
  uVar9 = *puVar1;
  if ((uVar9 == 0) ||
     ((uVar9 != 0xffffffffffffffff && ((uVar10 == 0xffffffffffffffff || (uVar9 < uVar10)))))) {
    return 0xc0020082;
  }
  bVar5 = false;
  do {
    if ((param_5 == 0) || (bVar5)) {
      if ((((uVar2 >> 10 & 1) != 0) || (*param_6 == 0)) &&
         (((uVar2 >> 9 & 1) != 0 || (param_6[1] == 0)))) {
        if ((((uVar2 >> 0xe & 1) != 0) && (param_6[5] != 0)) && (1 < *(int *)(param_6[5] + 8) - 1U))
        {
          return 0xc0020083;
        }
        if (((uVar2 >> 0xd & 1) != 0) || (param_6[7] == 0)) {
          if (((param_7 != 0) && ((*param_2 < 0x100000000 && (param_2[1] < 0x100000000)))) &&
             (*puVar1 < 0x100000000)) {
            if (param_7 == 1) {
              lVar12 = 0x28;
            }
            else if (param_7 == 2) {
              lVar12 = 0x3c;
            }
            else if (param_7 == 3) {
              lVar12 = 0x1c;
            }
            else if (param_7 == 4) {
              lVar12 = 0x30;
            }
            else {
              lVar12 = 0;
            }
            uVar10 = (ulonglong)(uint)param_2[4];
            if (((uint)param_2[4] - 1 < 0xfffffffe) && (!bVar6)) {
              uVar9 = ((uVar10 + lVar12) * *param_2) / uVar10;
              if (uVar9 < 0xffffffff) {
                uVar9 = uVar9 & 0xffffffff;
              }
              else {
                uVar9 = 0xfffffffe;
              }
              *param_2 = uVar9;
              uVar9 = ((uVar10 + lVar12) * param_2[1]) / uVar10;
              if (uVar9 < 0xffffffff) {
                uVar9 = uVar9 & 0xffffffff;
              }
              else {
                uVar9 = 0xfffffffe;
              }
              param_2[1] = uVar9;
              uVar10 = ((uVar10 + lVar12) * *puVar1) / uVar10;
              if (uVar10 < 0xffffffff) {
                *puVar1 = uVar10 & 0xffffffff;
              }
              else {
                *puVar1 = 0xfffffffe;
              }
            }
          }
          if ((param_6[8] == 0) || (0xffffd8ed < *(int *)(param_6[8] + 8) - 0x2711U)) {
            return 0;
          }
          return 0xc0020084;
        }
      }
      return 0xc0020086;
    }
    if (param_5 < 8) {
      return 0xc0020086;
    }
    uVar11 = param_4[1];
    if (param_5 < uVar11) {
      return 0xc0020086;
    }
    if (uVar11 < 8) {
      return 0xc0020086;
    }
    uVar3 = *param_4;
    if (uVar3 == 0xfa1) {
      if (param_5 < 0xc) {
        return 0xc0020086;
      }
      if (uVar11 < 0xc) {
        return 0xc0020086;
      }
      uVar11 = param_4[2];
      param_6[1] = (longlong)param_4;
      if (0x3f < uVar11) {
        return 0xc0020091;
      }
      *param_8 = (ushort)(byte)param_4[2];
    }
    else if (uVar3 < 0xfa2) {
      if (uVar3 == 0x7d1) {
        bVar5 = true;
      }
      else if (uVar3 == 0x7d2) {
        if (param_5 < 0xc) {
          return 0xc0020086;
        }
        if (uVar11 < 0xc) {
          return 0xc0020086;
        }
        uVar11 = param_4[2];
        param_6[5] = (longlong)param_4;
        if (((uVar11 != 0) && (uVar11 != 1)) && ((uVar11 != 2 && (uVar11 != 3)))) {
          return 0xc0020083;
        }
      }
      else if (uVar3 == 0x7d3) {
        if (param_5 < 0xc) {
          return 0xc0020086;
        }
        if (uVar11 < 0xc) {
          return 0xc0020086;
        }
        uVar11 = param_4[2];
        param_6[2] = (longlong)param_4;
        if ((uVar11 == 0) || (*param_2 < (ulonglong)uVar11)) {
          return 0xc0020090;
        }
      }
      else if (uVar3 == 0x7d4) {
        if (cVar13 != '\0') {
          return 0xc0020086;
        }
      }
      else if (uVar3 == 0xbbc) {
        if (param_5 < 0xc) {
          return 0xc0020086;
        }
        if (uVar11 < 0xc) {
          return 0xc0020086;
        }
        uVar11 = param_4[2];
        param_6[4] = (longlong)param_4;
        if (7 < (byte)uVar11) {
          return 0xc0020084;
        }
      }
      else {
        if (uVar3 != 0xbbd) {
          return 0xc0020086;
        }
        if (param_5 < 0x10) {
          return 0xc0020086;
        }
        if (uVar11 < 0x10) {
          return 0xc0020086;
        }
        param_6[6] = (longlong)param_4;
        if (param_4[2] == 0) {
          return 0xc0020086;
        }
        if (param_4[3] < 0x1e8) {
          return 0xc0020086;
        }
      }
    }
    else if (uVar3 == 0xfa2) {
      if (param_5 < 0xc) {
        return 0xc0020086;
      }
      if (uVar11 < 0xc) {
        return 0xc0020086;
      }
      uVar11 = param_4[2];
      *param_6 = (longlong)param_4;
      if (7 < uVar11) {
        return 0xc0020085;
      }
      *param_9 = (ushort)(byte)param_4[2];
    }
    else if (uVar3 == 0xfa3) {
      if (param_5 < 0xc) {
        return 0xc0020086;
      }
      if (uVar11 < 0xc) {
        return 0xc0020086;
      }
      uVar3 = param_4[2];
      param_6[3] = (longlong)param_4;
      if (((uVar3 == 0) || (0xffffffff < (ulonglong)uVar3 * 5)) ||
         (uVar4 = (uint)((ulonglong)uVar3 * 5), uVar7 = uVar4 + 0xc, uVar7 < uVar4)) {
        return 0xc0020088;
      }
      if (param_5 < uVar7) {
        return 0xc0020086;
      }
      if (uVar11 < uVar7) {
        return 0xc0020086;
      }
      puVar8 = param_4 + 3;
      for (uVar11 = 0; uVar11 < uVar3; uVar11 = uVar11 + 1) {
        if (0x3f < (byte)*puVar8) {
          return 0xc0020088;
        }
        if (0x3f < *(byte *)((longlong)puVar8 + 1)) {
          return 0xc0020088;
        }
        if (0x3f < *(byte *)((longlong)puVar8 + 2)) {
          return 0xc0020088;
        }
        if (7 < *(byte *)((longlong)puVar8 + 3)) {
          return 0xc0020088;
        }
        if (7 < (byte)puVar8[1]) {
          return 0xc0020088;
        }
        puVar8 = (uint *)((longlong)puVar8 + 5);
      }
    }
    else if (uVar3 == 0x1389) {
      if (param_5 < 0xc) {
        return 0xc0020086;
      }
      if (uVar11 < 0xc) {
        return 0xc0020086;
      }
      param_6[7] = (longlong)param_4;
    }
    else if (uVar3 == 0x138a) {
      if (param_5 < 0xc) {
        return 0xc0020086;
      }
      if (uVar11 < 0xc) {
        return 0xc0020086;
      }
      param_6[8] = (longlong)param_4;
    }
    else {
      if (uVar3 != 0x138b) {
        return 0xc0020086;
      }
      if (param_5 < 0x10) {
        return 0xc0020086;
      }
      if (uVar11 < 0x10) {
        return 0xc0020086;
      }
      param_6[9] = (longlong)param_4;
    }
    param_5 = param_5 - param_4[1];
    param_4 = (uint *)((longlong)param_4 + (ulonglong)param_4[1]);
  } while( true );
}



===== QosTbcFlowUpdate @ 140008810 =====

void QosTbcFlowUpdate(int *param_1,uint param_2,longlong *param_3,int *param_4,longlong param_5,
                     undefined4 *param_6,longlong *param_7,longlong *param_8)

{
  longlong ****pppplVar1;
  code *pcVar2;
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  longlong *plVar9;
  undefined1 uVar10;
  longlong ***ppplVar11;
  longlong ****pppplVar12;
  int local_res20 [2];
  longlong *local_78;
  longlong ****local_70;
  longlong ****local_68;
  longlong local_60;
  longlong *plStack_58;
  undefined8 local_50;
  longlong local_48;
  longlong *plStack_40;
  undefined8 local_38;
  
  param_5 = 0;
  local_68 = (longlong ****)&local_70;
  local_78 = (longlong *)0x0;
  local_res20[0] = 0;
  local_70 = (longlong ****)&local_70;
  local_50 = 0;
  local_60 = 0;
  plStack_58 = (longlong *)0x0;
  local_38 = 0;
  uVar10 = 1;
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  uVar7 = QosTimerGetCurrentTime(param_2,'\x01','\x01');
  if (param_4 != (int *)0x0) {
    pppplVar1 = *(longlong *****)(param_1 + 0x1a);
    while (pppplVar12 = pppplVar1, pppplVar12 != (longlong ****)(param_1 + 0x18)) {
      pppplVar1 = (longlong ****)pppplVar12[1];
      if (*(int *)(pppplVar12 + 2) != *param_4) break;
      ppplVar11 = *pppplVar12;
      if (((longlong ****)ppplVar11[1] != pppplVar12) || ((longlong ****)*pppplVar1 != pppplVar12))
      goto LAB_140008b40;
      *pppplVar1 = ppplVar11;
      ppplVar11[1] = (longlong **)pppplVar1;
      if ((longlong *****)local_70[1] != &local_70) goto LAB_140008b40;
      *pppplVar12 = (longlong ***)local_70;
      pppplVar12[1] = (longlong ***)&local_70;
      local_70[1] = (longlong ***)pppplVar12;
      local_70 = pppplVar12;
    }
    if ((longlong *****)local_70 != &local_70) {
      param_1[0x20] = *(int *)(local_70 + 4);
      *(longlong ****)(param_1 + 0x1c) = local_70[5];
      *(longlong ****)(param_1 + 0x1e) = local_70[6];
      *(longlong ****)(param_1 + 0x22) = local_70[7];
      *(longlong ****)(param_1 + 0x38) = local_70[3];
      if (*(int *)*QosgEtwDispatchTable == 1) {
        QosTraceFlowConformance((longlong)param_1,uVar7,0);
      }
    }
  }
  param_1[0x16] = *(int *)((longlong)param_3 + 0x24);
  if (*(ulonglong *)(param_1 + 0x1c) < uVar7) {
    plVar9 = (longlong *)(param_1 + 0x22);
    QosUtilComputeTokenSpec(plVar9,uVar7 - *(ulonglong *)(param_1 + 0x1c));
    puVar3 = QosgEtwDispatchTable;
    param_1[0x20] = (int)*plVar9;
    *(ulonglong *)(param_1 + 0x1c) = uVar7;
    if (*(int *)*puVar3 == 1) {
      QosTraceFlowConformance((longlong)param_1,uVar7,1);
    }
  }
  QosUtilSetTokenSpec((longlong *)(param_1 + 0x22),param_3,*(longlong *)(param_1 + 0x24) == 0);
  if (*(int *)*QosgEtwDispatchTable == 1) {
    QosTraceFlowConformance((longlong)param_1,uVar7,2);
  }
  *(longlong *)(param_1 + 0x28) = param_3[2];
  iVar4 = 0;
  if ((int)param_3[4] != -1) {
    iVar4 = (int)param_3[4];
  }
  param_1[0x2a] = iVar4;
  iVar4 = param_1[0x16];
  if ((iVar4 == 3) || (*(longlong *)(param_1 + 0x26) == -1)) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  *(undefined1 *)((longlong)param_1 + 0x5d) = uVar8;
  if ((iVar4 != 1) && ((param_3[2] == -1 || (iVar4 == 3)))) {
    uVar10 = 0;
  }
  *(undefined1 *)(param_1 + 0x17) = uVar10;
  param_1[0x35] = (int)param_3[5];
  param_1[0x36] = *(int *)((longlong)param_3 + 0x2c);
  if (param_3[3] != 0) {
    *(longlong *)(param_1 + 0x3c) = param_3[3];
  }
  uVar6 = *(uint *)(param_3 + 7);
  if (uVar6 != 0xffffffff) {
    param_1[0x50] = uVar6;
    param_1[0x53] = 2;
    uVar5 = uVar6;
    if (uVar6 <= (uint)param_1[0x51]) {
      uVar5 = param_1[0x51];
    }
    param_1[0x51] = uVar5;
    if (uVar6 <= (uint)param_1[0x52]) {
      uVar6 = param_1[0x52];
    }
    param_1[0x52] = uVar6;
    QosTbcTuneParameters((longlong)param_1);
  }
  while ((longlong *****)local_70 != &local_70) {
    param_5 = 0;
    local_78 = (longlong *)0x0;
    if (((longlong *****)local_70[1] != &local_70) ||
       (pppplVar1 = (longlong ****)*local_70, (longlong ****)pppplVar1[1] != local_70))
    goto LAB_140008b40;
    pppplVar1[1] = (longlong ***)&local_70;
    ppplVar11 = local_70[-3];
    pppplVar12 = local_70;
    local_70 = pppplVar1;
    uVar6 = QosGetNetBufferCount((longlong)ppplVar11,local_res20);
    QosTbcSendNetBufferList
              (param_1,param_2,pppplVar12[-2],(longlong)ppplVar11,uVar6,local_res20[0],0,&param_5,
               (longlong *)&local_78);
    if (param_5 != 0) {
      QosNblChainInsert(&local_60,plStack_58,(longlong *)param_5);
    }
    if (local_78 != (longlong *)0x0) {
      QosNblChainInsert(&local_48,plStack_40,local_78);
    }
  }
LAB_140008b47:
  *param_7 = local_60;
  *param_8 = local_48;
  *param_6 = (undefined4)local_50;
  return;
LAB_140008b40:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  goto LAB_140008b47;
}



===== QosTimerGetCurrentTime @ 140008b90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong QosTimerGetCurrentTime(uint param_1,char param_2,char param_3)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  undefined4 in_register_0000000c;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  ulonglong local_res20;
  
  uVar4 = 0;
  if (param_3 == '\0') {
    uVar4 = KfRaiseIrql(CONCAT71((int7)(CONCAT44(in_register_0000000c,param_1) >> 8),2));
    param_1 = KeGetCurrentProcessorNumberEx(0);
  }
  lVar2 = _DAT_fffff78000000008;
  plVar7 = (longlong *)((ulonglong)param_1 * 0x80 + *QosgTimerTable);
  if ((param_2 != '\0') || (_DAT_fffff78000000008 != plVar7[1])) {
    local_res20 = 0;
    uVar5 = KeQueryPerformanceCounter(&local_res20);
    uVar6 = (uVar5 >> 0x20) * 1000000;
    bVar1 = *(byte *)(plVar7 + 0xe);
    lVar8 = ((uVar6 % local_res20 << 0x20) + (uVar5 & 0xffffffff) * 1000000) / local_res20 +
            (uVar6 / local_res20 << 0x20);
    if (bVar1 == 0) {
      bVar3 = 2;
    }
    else {
      bVar3 = bVar1 - 1;
    }
    uVar6 = (ulonglong)bVar3;
    if (plVar7[uVar6 + 8] - lVar8 < 1) {
      plVar7[(ulonglong)bVar1 + 2] = uVar5;
      plVar7[(ulonglong)bVar1 + 5] = local_res20;
      plVar7[(ulonglong)bVar1 + 8] = lVar8;
    }
    else {
      plVar7[(ulonglong)bVar1 + 2] = plVar7[uVar6 + 2];
      plVar7[(ulonglong)bVar1 + 5] = plVar7[uVar6 + 5];
      plVar7[(ulonglong)bVar1 + 8] = plVar7[uVar6 + 8];
      lVar8 = plVar7[uVar6 + 8];
    }
    plVar7[(ulonglong)bVar1 + 0xb] = lVar2;
    *plVar7 = lVar8;
    plVar7[1] = lVar2;
    *(byte *)(plVar7 + 0xe) = (byte)((char)plVar7[0xe] + 1U) % 3;
  }
  lVar2 = *plVar7;
  if (param_3 == '\0') {
    KeLowerIrql(uVar4);
  }
  return lVar2;
}



===== QosUtilSetTokenSpec @ 140008d2c =====

void QosUtilSetTokenSpec(longlong *param_1,longlong *param_2,char param_3)

{
  longlong lVar1;
  
  lVar1 = param_2[1];
  if (param_3 == '\0') {
    if (lVar1 == -1) {
      lVar1 = 0x7fffffffffffffff;
    }
    param_1[1] = lVar1;
    if (lVar1 < *param_1) {
      *param_1 = lVar1;
    }
  }
  else if (lVar1 == -1) {
    *param_1 = 0;
    param_1[1] = 0x7fffffffffffffff;
  }
  else {
    *param_1 = lVar1;
    param_1[1] = param_2[1];
  }
  param_1[2] = *param_2;
  return;
}



===== PcpMrkSetMarkingValues @ 140008d8c =====

void PcpMrkSetMarkingValues
               (longlong param_1,int param_2,longlong param_3,longlong *param_4,byte *param_5)

{
  longlong lVar1;
  byte bVar2;
  byte bVar3;
  
  if (param_2 == 1) {
    *param_5 = *(byte *)(param_3 + 0x18);
    bVar2 = *(byte *)(param_3 + 0x1e);
  }
  else if (param_2 == 2) {
    *param_5 = *(byte *)(param_3 + 0x19);
    bVar2 = *(byte *)(param_3 + 0x1f);
  }
  else if (param_2 == 3) {
    *param_5 = *(byte *)(param_3 + 0x1a);
    bVar2 = *(byte *)(param_3 + 0x20);
  }
  else if (param_2 == 10) {
    *param_5 = *(byte *)(param_3 + 0x1b);
    bVar2 = *(byte *)(param_3 + 0x21);
  }
  else if (param_2 == 0xd) {
    *param_5 = *(byte *)(param_3 + 0x1c);
    bVar2 = *(byte *)(param_3 + 0x22);
  }
  else {
    *param_5 = 0;
    bVar2 = 0;
  }
  param_5[1] = bVar2;
  if (param_4[1] != 0) {
    *param_5 = *(char *)(param_4[1] + 8) << 2;
  }
  if (param_2 == 1) {
    if ((*(uint *)(param_1 + 0x30) & 0x800) != 0) {
      bVar2 = *(byte *)(param_3 + 0x24);
      goto LAB_140008e6e;
    }
LAB_140008e78:
    bVar2 = 0;
    param_5[2] = 0;
    bVar3 = 0;
  }
  else {
    if (param_2 == 2) {
      if ((*(uint *)(param_1 + 0x30) & 0x800) != 0) {
        bVar2 = *(byte *)(param_3 + 0x25);
        goto LAB_140008e6e;
      }
      goto LAB_140008e78;
    }
    if (param_2 == 3) {
      if ((*(uint *)(param_1 + 0x30) & 0x800) != 0) {
        bVar2 = *(byte *)(param_3 + 0x26);
        goto LAB_140008e6e;
      }
      goto LAB_140008e78;
    }
    if (param_2 == 10) {
      if ((*(uint *)(param_1 + 0x30) & 0x800) != 0) {
        bVar2 = *(byte *)(param_3 + 0x27);
        goto LAB_140008e6e;
      }
      goto LAB_140008e78;
    }
    if ((param_2 != 0xd) || ((*(uint *)(param_1 + 0x30) & 0x800) == 0)) goto LAB_140008e78;
    bVar2 = *(byte *)(param_3 + 0x28);
LAB_140008e6e:
    param_5[2] = bVar2;
    bVar3 = *(byte *)(param_3 + 0x2a);
  }
  param_5[3] = bVar3;
  if (*param_4 != 0) {
    bVar2 = *(byte *)(*param_4 + 8);
    param_5[2] = bVar2;
  }
  if (bVar2 == 0) {
    bVar2 = *param_5 >> 2;
    if (bVar2 < 0x1d) {
      if (bVar2 == 0x1c) {
LAB_140008f08:
        bVar2 = 4;
      }
      else if (bVar2 < 0x11) {
        if ((bVar2 != 0x10) && (bVar2 != 0)) {
          if (bVar2 == 8) {
            bVar2 = 1;
            goto LAB_140008f2b;
          }
          if (((bVar2 != 10) && (bVar2 != 0xc)) && (bVar2 != 0xe)) goto LAB_140008f20;
        }
        bVar2 = 0;
      }
      else {
        if (((bVar2 != 0x12) && (bVar2 != 0x14)) && (bVar2 != 0x16)) {
          if ((bVar2 != 0x18) && (bVar2 != 0x1a)) goto LAB_140008f20;
          goto LAB_140008f08;
        }
        bVar2 = 3;
      }
    }
    else if (bVar2 < 0x29) {
      if (bVar2 == 0x28) {
        bVar2 = 5;
      }
      else {
        if ((((bVar2 == 0x1e) || (bVar2 == 0x20)) || (bVar2 == 0x22)) ||
           ((bVar2 == 0x24 || (bVar2 == 0x26)))) goto LAB_140008f08;
LAB_140008f20:
        bVar2 = *param_5 >> 5;
      }
    }
    else if ((bVar2 == 0x2c) || (bVar2 == 0x2e)) {
      bVar2 = 6;
    }
    else {
      if ((bVar2 != 0x30) && (bVar2 != 0x38)) goto LAB_140008f20;
      bVar2 = 7;
    }
  }
LAB_140008f2b:
  param_5[4] = bVar2;
  bVar2 = param_5[3];
  if (bVar2 != 0) goto LAB_140008fc3;
  bVar2 = param_5[1] >> 2;
  if (bVar2 < 0x1d) {
    if (bVar2 != 0x1c) {
      if (bVar2 < 0x11) {
        if ((bVar2 != 0x10) && (bVar2 != 0)) {
          if (bVar2 == 8) {
            bVar2 = 1;
            goto LAB_140008fc3;
          }
          if (((bVar2 != 10) && (bVar2 != 0xc)) && (bVar2 != 0xe)) goto LAB_140008fb8;
        }
        bVar2 = 0;
        goto LAB_140008fc3;
      }
      if (((bVar2 == 0x12) || (bVar2 == 0x14)) || (bVar2 == 0x16)) {
        bVar2 = 3;
        goto LAB_140008fc3;
      }
      if ((bVar2 != 0x18) && (bVar2 != 0x1a)) goto LAB_140008fb8;
    }
LAB_140008fa0:
    bVar2 = 4;
  }
  else {
    if (bVar2 < 0x29) {
      if (bVar2 == 0x28) {
        bVar2 = 5;
        goto LAB_140008fc3;
      }
      if ((((bVar2 == 0x1e) || (bVar2 == 0x20)) || (bVar2 == 0x22)) ||
         ((bVar2 == 0x24 || (bVar2 == 0x26)))) goto LAB_140008fa0;
    }
    else {
      if ((bVar2 == 0x2c) || (bVar2 == 0x2e)) {
        bVar2 = 6;
        goto LAB_140008fc3;
      }
      if ((bVar2 == 0x30) || (bVar2 == 0x38)) {
        bVar2 = 7;
        goto LAB_140008fc3;
      }
    }
LAB_140008fb8:
    bVar2 = param_5[1] >> 5;
  }
LAB_140008fc3:
  param_5[5] = bVar2;
  lVar1 = param_4[7];
  if (lVar1 == 0) {
    param_5[6] = 0;
    bVar2 = 0;
  }
  else {
    param_5[6] = *(byte *)(lVar1 + 8) & 1;
    bVar2 = (byte)(*(uint *)(lVar1 + 8) >> 1) & 1;
  }
  param_5[7] = bVar2;
  return;
}



===== PcpIndicateDelayQueueConsumerEnd @ 140009000 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpIndicateDelayQueueConsumerEnd
               (uint param_1,undefined8 param_2,undefined8 param_3,longlong ****param_4)

{
  int *piVar1;
  byte bVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined2 *puVar12;
  longlong *plVar13;
  undefined2 local_res8;
  undefined1 local_resa;
  longlong *******local_res10;
  longlong *local_res18;
  longlong *local_res20;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  
  lVar4 = PcgDelayQueue;
  lVar11 = (ulonglong)param_1 * 0x40;
  piVar1 = (int *)(lVar11 + 0x10 + PcgDelayQueue);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    local_78 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_res8 = 0;
    local_resa = 0;
    *(undefined8 *)(lVar11 + 8 + lVar4) = 0;
    puVar3 = *(undefined8 **)(lVar11 + lVar4);
    *(undefined8 *)(lVar11 + lVar4) = 0;
    lVar4 = _DAT_fffff78000000008;
    local_70 = 0;
    uStack_68 = 0;
    local_50 = 0;
    plVar13 = (longlong *)((ulonglong)param_1 * 0x80 + *QosgTimerTable);
    local_60 = 0;
    uStack_58 = 0;
    if (_DAT_fffff78000000008 != plVar13[1]) {
      local_res10 = (longlong *******)0x0;
      uVar8 = KeQueryPerformanceCounter(&local_res10);
      uVar10 = (uVar8 >> 0x20) * 1000000;
      bVar2 = *(byte *)(plVar13 + 0xe);
      lVar11 = ((uVar10 % (ulonglong)local_res10 << 0x20) + (uVar8 & 0xffffffff) * 1000000) /
               (ulonglong)local_res10 + (uVar10 / (ulonglong)local_res10 << 0x20);
      if (bVar2 == 0) {
        bVar7 = 2;
      }
      else {
        bVar7 = bVar2 - 1;
      }
      uVar10 = (ulonglong)bVar7;
      if (plVar13[uVar10 + 8] - lVar11 < 1) {
        plVar13[(ulonglong)bVar2 + 2] = uVar8;
        plVar13[(ulonglong)bVar2 + 5] = (longlong)local_res10;
        plVar13[(ulonglong)bVar2 + 8] = lVar11;
      }
      else {
        plVar13[(ulonglong)bVar2 + 2] = plVar13[uVar10 + 2];
        plVar13[(ulonglong)bVar2 + 5] = plVar13[uVar10 + 5];
        plVar13[(ulonglong)bVar2 + 8] = plVar13[uVar10 + 8];
        lVar11 = plVar13[uVar10 + 8];
      }
      plVar13[(ulonglong)bVar2 + 0xb] = lVar4;
      *plVar13 = lVar11;
      plVar13[1] = lVar4;
      *(byte *)(plVar13 + 0xe) = (byte)((char)plVar13[0xe] + 1U) % 3;
      param_4 = (longlong ****)local_res10;
    }
    lVar4 = *plVar13;
    while (puVar3 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)*puVar3;
      puVar9 = &local_88;
      RtlAcquireWriteLockAtDpcLevel((longlong)(puVar3 + 7));
      *(uint *)(puVar3 + 0x48) = *(uint *)(puVar3 + 0x48) & 0xfffffffb;
      local_res18 = (longlong *)0x0;
      local_res20 = (longlong *)0x0;
      local_res10 = (longlong *******)((ulonglong)local_res10 & 0xffffffff00000000);
      if ((*(uint *)(puVar3 + 0x48) & 8) == 0) {
        uVar8 = QosFlowNeedQueueFeedback((longlong)(puVar3 + 0xc),lVar4,&local_70);
        if (((char)uVar8 != '\0') &&
           (puVar9 = PcpLineFindByLuid(puVar3[6]), puVar9 != (undefined8 *)0x0)) {
          PcpLineSignalExternalEvent((longlong)puVar9,(ulonglong)param_1);
          puVar12 = &local_res8;
          NdisAcquireRWLockWrite(puVar9[2],puVar12,0);
          QosLineQueryQueueFeedback((longlong)(puVar9 + 3),puVar12,(uint *)&local_70);
          NdisReleaseRWLock(puVar9[2],&local_res8);
          PcpLineDereference((longlong)puVar9);
          QosTbcAdjustSendWindow((longlong)(puVar3 + 0xc),(longlong)&local_70);
        }
        puVar9 = (undefined8 *)(ulonglong)param_1;
        param_4 = (longlong ****)&local_res10;
        QosFlowProcessQueuedNetBufferLists((longlong)(puVar3 + 0xc),param_1);
      }
      plVar6 = local_res20;
      plVar13 = local_res18;
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_88);
      if (plVar13 != (longlong *)0x0) {
        param_4 = (longlong ****)CONCAT71((int7)((ulonglong)param_4 >> 8),1);
        puVar9 = (undefined8 *)(ulonglong)param_1;
        PcpSchedulerBatchAndSendOrDropNblChain(plVar13,param_1,0,(longlong *)param_4);
      }
      if (plVar6 != (longlong *)0x0) {
        param_4 = (longlong ****)0x0;
        puVar9 = (undefined8 *)(ulonglong)param_1;
        PcpSchedulerBatchAndSendOrDropNblChain(plVar6,param_1,0,(longlong *)0x0);
      }
      PcpDereferenceFlow(puVar3 + -5,(ulonglong)puVar9);
      puVar3 = puVar5;
    }
  }
  return;
}



===== QosTimerConvertPerformanceCounterToMicroseconds @ 1400092e0 =====

void QosTimerConvertPerformanceCounterToMicroseconds(longlong *param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong local_res8;
  
  local_res8 = 0;
  uVar3 = KeQueryPerformanceCounter(&local_res8);
  uVar5 = (uVar3 >> 0x20) * 1000000;
  bVar1 = *(byte *)(param_1 + 0xe);
  lVar4 = ((uVar5 % local_res8 << 0x20) + (uVar3 & 0xffffffff) * 1000000) / local_res8 +
          (uVar5 / local_res8 << 0x20);
  if (bVar1 == 0) {
    bVar2 = 2;
  }
  else {
    bVar2 = bVar1 - 1;
  }
  uVar5 = (ulonglong)bVar2;
  if (param_1[uVar5 + 8] - lVar4 < 1) {
    param_1[(ulonglong)bVar1 + 2] = uVar3;
    param_1[(ulonglong)bVar1 + 5] = local_res8;
    param_1[(ulonglong)bVar1 + 8] = lVar4;
  }
  else {
    param_1[(ulonglong)bVar1 + 2] = param_1[uVar5 + 2];
    param_1[(ulonglong)bVar1 + 5] = param_1[uVar5 + 5];
    param_1[(ulonglong)bVar1 + 8] = param_1[uVar5 + 8];
    lVar4 = param_1[uVar5 + 8];
  }
  param_1[(ulonglong)bVar1 + 0xb] = param_2;
  param_1[1] = param_2;
  *param_1 = lVar4;
  *(byte *)(param_1 + 0xe) = (byte)((char)param_1[0xe] + 1U) % 3;
  return;
}



===== PcFilterRequest @ 1400093e0 =====

int PcFilterRequest(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res8;
  
  local_res8 = 0;
  iVar2 = NdisAllocateCloneOidRequest
                    (*(undefined8 *)(param_1 + 0x28),param_2,0x72636350,&local_res8);
  lVar1 = local_res8;
  if (iVar2 == 0) {
    *(undefined8 *)(local_res8 + 0xd8) = param_2;
    LOCK();
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
    UNLOCK();
    iVar2 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x28),local_res8);
    if (iVar2 != 0x103) {
      iVar2 = PcpProcessFilterRequest(param_1,local_res8,iVar2);
      *(undefined8 *)(lVar1 + 0xd8) = 0;
      NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x28),local_res8);
      PcpFilterDecrementDetachCount(param_1);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_b9430ea6b97e3220a658a58314301cbf_Traceguids,iVar2);
  }
  return iVar2;
}



===== PcQoSPQueryTrafficClass @ 1400094f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcQoSPQueryTrafficClass(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  ushort uVar9;
  bool bVar10;
  undefined1 auStackY_c8 [32];
  byte local_98 [4];
  undefined2 local_94;
  undefined1 local_92;
  undefined2 local_90;
  undefined1 local_8e;
  int local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar1 = *(longlong *)(*param_1 + 0xa8);
  if (((Microsoft_Windows_Networking_CorrelationEnabled != 0) && (PcgEventTraceEnabled != 0)) &&
     (uVar7 = *(ulonglong *)(*param_1 + 0xf8) & 0x7fffffffffffffff, uVar7 != 0)) {
    PcpEtwTransferFlowActivity(uVar7,lVar1);
  }
  lVar2 = param_1[1];
  lVar3 = *param_1;
  uVar9 = (ushort)(*(uint *)(lVar1 + 0x30) >> 0xe) & 1;
  local_98[0] = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  local_8c = 0;
  iVar5 = NdisIfGetInterfaceIndexFromNetLuid(lVar2,&local_8c);
  if (iVar5 == 0) {
    local_94 = 0;
    local_92 = 0;
    NdisAcquireRWLockRead(PcgFilterDriverContext,&local_94,0);
    puVar4 = DAT_140019888;
    do {
      puVar6 = puVar4;
      if ((undefined8 **)puVar6 == &DAT_140019888) {
        NdisReleaseRWLock(PcgFilterDriverContext,&local_94);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
          WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids,lVar2);
        }
        goto LAB_140009817;
      }
      puVar4 = (undefined8 *)*puVar6;
    } while (*(int *)(puVar6 + 0xc) != local_8c);
    iVar5 = *(int *)((longlong)puVar6 + 0x14);
    NdisReleaseRWLock(PcgFilterDriverContext,&local_94);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids,lVar2);
    }
LAB_140009817:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_3643923c9bd13e596b9957c4c416ef65_Traceguids,lVar2);
    }
    iVar5 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_d142f05ff1783a702b1695b6c61349f7_Traceguids);
  }
  local_40 = 0;
  local_38 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (iVar5 == 9) {
    local_8c = 0;
    uVar9 = uVar9 | 2;
    iVar5 = NdisIfGetInterfaceIndexFromNetLuid(lVar2,&local_8c);
    if (iVar5 == 0) {
      local_90 = 0;
      local_8e = 0;
      NdisAcquireRWLockRead(PcgFilterDriverContext,&local_90,0);
      puVar4 = DAT_140019888;
      do {
        puVar6 = puVar4;
        if ((undefined8 **)puVar6 == &DAT_140019888) {
          NdisReleaseRWLock(PcgFilterDriverContext,&local_90);
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0)) goto LAB_1400097bf;
          uVar8 = 0xb;
          goto LAB_1400099e2;
        }
        puVar4 = (undefined8 *)*puVar6;
      } while (*(int *)(puVar6 + 0xc) != local_8c);
      local_70 = *(undefined8 *)((longlong)puVar6 + 0xd6);
      uStack_68 = *(undefined8 *)((longlong)puVar6 + 0xde);
      local_38 = *(undefined4 *)((longlong)puVar6 + 0x10e);
      local_60 = *(undefined8 *)((longlong)puVar6 + 0xe6);
      uStack_58 = *(undefined8 *)((longlong)puVar6 + 0xee);
      local_50 = *(undefined8 *)((longlong)puVar6 + 0xf6);
      uStack_48 = *(undefined8 *)((longlong)puVar6 + 0xfe);
      local_40 = *(undefined8 *)((longlong)puVar6 + 0x106);
      NdisReleaseRWLock(PcgFilterDriverContext,&local_90);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_3643923c9bd13e596b9957c4c416ef65_Traceguids,(uint)(byte)local_70);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        uVar8 = 10;
LAB_1400099e2:
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                 &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids,lVar2);
      }
LAB_1400097bf:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_3643923c9bd13e596b9957c4c416ef65_Traceguids);
      }
    }
  }
  KeAcquireInStackQueuedSpinLock(lVar1 + 0x60,&local_88);
  do {
  } while (*(int *)(lVar1 + 0x68) != 0);
  QosMrkComputeMarking
            (lVar1 + 0x88,(char *)&local_70,lVar3,uVar9,local_98,
             (undefined1 *)((longlong)param_1 + 0x11));
  KeReleaseInStackQueuedSpinLock(&local_88);
  bVar10 = PcgAllowAppDSCPMarking == 0;
  *(byte *)(param_1 + 2) = local_98[0] >> 2;
  if ((bVar10) && (((*(uint *)(lVar1 + 0x30) & 0xff) - 2 & 0xfffffffd) != 0)) {
    *(undefined1 *)(param_1 + 2) = 0;
  }
  return;
}



===== QosMrkComputeMarking @ 140009a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosMrkComputeMarking
               (longlong param_1,char *param_2,longlong param_3,ushort param_4,byte *param_5,
               undefined1 *param_6)

{
  uint *puVar1;
  int iVar2;
  undefined8 *puVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  longlong *plVar8;
  uint uVar9;
  undefined1 auStack_c8 [32];
  longlong local_a8;
  longlong local_98;
  ushort local_90;
  ushort local_8e;
  ushort local_8c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(&local_98,0,0x50);
  if ((param_4 & 1) != 0) {
    uVar5 = (uint)*(byte *)(param_1 + 0x52);
    *param_5 = *(byte *)(param_1 + 0x50);
    uVar9 = (uint)*(byte *)(param_1 + 0x54);
    *param_6 = *(undefined1 *)(param_1 + 0x56);
    goto LAB_140009ab7;
  }
  if (*(longlong *)(param_1 + 0x98) == -1) {
    uVar5 = (uint)*(byte *)(param_1 + 0x52);
    *param_5 = *(byte *)(param_1 + 0x50);
    uVar9 = (uint)*(byte *)(param_1 + 0x54);
    local_a8 = *(longlong *)(param_1 + 0x38);
  }
  else {
    uVar5 = KeGetCurrentProcessorNumberEx(0);
    uVar6 = QosTimerGetCurrentTime(uVar5,'\0','\x01');
    if (*(ulonglong *)(param_1 + 0x30) < uVar6) {
      QosUtilComputeTokenSpec((longlong *)(param_1 + 0x38),uVar6 - *(ulonglong *)(param_1 + 0x30));
      *(ulonglong *)(param_1 + 0x30) = uVar6;
    }
    puVar3 = QosgEtwDispatchTable;
    plVar8 = *(longlong **)(param_3 + 8);
    local_a8 = *(longlong *)(param_1 + 0x38);
    if (plVar8 != (longlong *)0x0) {
      do {
        puVar1 = (uint *)(plVar8 + 3);
        plVar8 = (longlong *)*plVar8;
        local_a8 = local_a8 - (ulonglong)*puVar1;
      } while (plVar8 != (longlong *)0x0);
    }
    iVar2 = *(int *)(param_1 + 0x28);
    if (iVar2 == 0) {
      if (-1 < local_a8) goto LAB_140009c74;
      bVar4 = *(byte *)(param_1 + 0x51);
      bVar7 = *(byte *)(param_1 + 0x53);
      uVar5 = (uint)bVar7;
      *param_5 = bVar4;
      uVar9 = (uint)*(byte *)(param_1 + 0x55);
      if (*(int *)*puVar3 == 1) {
        local_90 = (ushort)(bVar4 >> 2);
        local_8e = (ushort)bVar7;
        local_8c = (ushort)*(byte *)(param_1 + 0x55);
        local_98 = param_3;
        (*(code *)puVar3[6])(&local_98);
      }
    }
    else if (iVar2 == 1) {
LAB_140009c74:
      uVar5 = (uint)*(byte *)(param_1 + 0x52);
      *param_5 = *(byte *)(param_1 + 0x50);
      uVar9 = (uint)*(byte *)(param_1 + 0x54);
    }
    else if (iVar2 == 2) {
      uVar5 = (uint)*(byte *)(param_1 + 0x52);
      *param_5 = *(byte *)(param_1 + 0x50);
      uVar9 = (uint)*(byte *)(param_1 + 0x54);
      if (local_a8 < 0) {
        local_a8 = *(longlong *)(param_1 + 0x38);
      }
    }
    else if (iVar2 == 3) {
      uVar5 = (uint)*(byte *)(param_1 + 0x52);
      *param_5 = *(byte *)(param_1 + 0x50);
      uVar9 = (uint)*(byte *)(param_1 + 0x54);
    }
    else {
      uVar5 = 0;
      *param_5 = 0;
      uVar9 = 0;
    }
  }
  *param_6 = *(undefined1 *)(param_1 + 0x56);
  *(longlong *)(param_1 + 0x38) = local_a8;
LAB_140009ab7:
  if (*(char *)(param_1 + 0x57) == '\0') {
    *(uint *)(param_3 + 0xb0) = (uVar5 ^ *(uint *)(param_3 + 0xb0)) & 7 ^ *(uint *)(param_3 + 0xb0);
  }
  if ((param_4 & 2) != 0) {
    if (*param_2 != '\0') {
      bVar7 = *param_5 >> 2;
      for (bVar4 = 0; bVar4 < (byte)param_2[0x11]; bVar4 = bVar4 + 1) {
        if (bVar7 == param_2[(ulonglong)bVar4 * 2 + 0x12]) {
          uVar9 = (uint)(byte)param_2[(ulonglong)bVar4 * 2 + 0x13];
          goto LAB_140009b05;
        }
      }
      uVar6 = 0;
      while( true ) {
        uVar9 = (uint)uVar6;
        if (7 < (byte)uVar6) break;
        if (((byte)param_2[uVar6 * 2 + 1] <= bVar7) && (bVar7 <= (byte)param_2[uVar6 * 2 + 2]))
        goto LAB_140009b05;
        uVar6 = (ulonglong)(byte)((byte)uVar6 + 1);
      }
      uVar9 = 0;
    }
LAB_140009b05:
    *(uint *)(param_3 + 0xb0) =
         (uVar9 << 0x10 ^ *(uint *)(param_3 + 0xb0)) & 0xf0000 ^ *(uint *)(param_3 + 0xb0);
  }
  return;
}



===== QosNblChainInsert @ 140009cf0 =====

longlong * QosNblChainInsert(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  
  if (param_2 == (longlong *)0x0) {
    lVar1 = *param_1;
    *param_1 = (longlong)param_3;
  }
  else {
    lVar1 = *param_2;
    *param_2 = (longlong)param_3;
  }
  *param_3 = lVar1;
  if (lVar1 == 0) {
    param_1[1] = (longlong)param_3;
  }
  *(int *)(param_1 + 2) = (int)param_1[2] + 1;
  return param_3;
}



===== PcpSchedulerBatchAndSendOrDropNblChain @ 140009d20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpSchedulerBatchAndSendOrDropNblChain
               (longlong *param_1,uint param_2,uint param_3,longlong *param_4)

{
  longlong *plVar1;
  int *piVar2;
  byte bVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  byte bVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar10;
  int iVar11;
  int iVar12;
  longlong lVar13;
  char cVar14;
  ulonglong uVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong *local_res8;
  undefined2 local_res20;
  undefined1 local_res22;
  longlong *local_48;
  ulonglong local_40;
  
  iVar11 = 0;
  lVar10 = param_1[0xc];
  cVar14 = (char)param_4;
  uVar15 = (ulonglong)param_2;
  plVar5 = (longlong *)*param_1;
  plVar16 = param_1;
  lVar17 = _DAT_fffff78000000008;
  while (plVar1 = plVar5, _DAT_fffff78000000008 = lVar17, plVar1 != (longlong *)0x0) {
    if (plVar1[0xc] != lVar10) {
      *plVar16 = 0;
      if (cVar14 == '\0') {
        param_4 = (longlong *)(ulonglong)param_3;
        PcpSchedulerDropNblChain(param_1[0x15],lVar10 - 0x18,param_1,param_3);
      }
      else {
        PcpLineSendNetBufferLists(lVar10 + -0x18,param_2,param_1,param_4);
      }
      lVar10 = plVar1[0xc];
      param_1 = plVar1;
    }
    plVar16 = plVar1;
    lVar17 = _DAT_fffff78000000008;
    plVar5 = (longlong *)*plVar1;
  }
  if (cVar14 == '\0') {
    PcpSchedulerDropNblChain(param_1[0x15],lVar10 - 0x18U,param_1,param_3);
  }
  else {
    local_res8 = (longlong *)0x0;
    local_48 = (longlong *)0x0;
    if (lVar10 - 0x18U == 0) {
      plVar16 = param_1;
      lVar10 = *(longlong *)((ulonglong)*(ushort *)(param_1[2] + 10) + 0x30 + param_1[2]) + -0x18;
      do {
        plVar5 = (longlong *)*plVar16;
        if (plVar5 == (longlong *)0x0) {
          lVar17 = 0;
        }
        else {
          lVar17 = *(longlong *)((ulonglong)*(ushort *)(plVar5[2] + 10) + 0x30 + plVar5[2]) + -0x18;
        }
        if (lVar10 != lVar17) {
          *plVar16 = 0;
          uVar7 = uVar15;
          PcpLineSignalExternalEvent(lVar10,uVar15);
          QosLineSendNetBufferLists(lVar10 + 0x18,uVar7,param_1,param_4,&local_res8,&local_48);
          if (local_res8 != (longlong *)0x0) {
            iVar11 = 0;
            plVar16 = local_res8;
            do {
              plVar1 = plVar16 + 0xf;
              plVar16 = (longlong *)*plVar16;
              iVar8 = iVar11 + 1;
              if (*plVar1 != *(longlong *)(*(longlong *)(lVar10 + 0x100) + 0x28)) {
                iVar8 = iVar11;
              }
              iVar11 = iVar8;
            } while (plVar16 != (longlong *)0x0);
            if (0 < iVar11) {
              LOCK();
              piVar2 = (int *)(*(longlong *)(lVar10 + 0x100) + 0x80);
              *piVar2 = *piVar2 + iVar11;
              UNLOCK();
            }
            param_4 = (longlong *)0x0;
            NdisFSendNetBufferLists
                      (*(undefined8 *)(*(longlong *)(lVar10 + 0x100) + 0x28),local_res8,0);
            local_res8 = (longlong *)0x0;
          }
          if (local_48 != (longlong *)0x0) {
            iVar11 = 0;
            param_4 = local_48;
            do {
              plVar16 = param_4 + 0xf;
              param_4 = (longlong *)*param_4;
              iVar8 = iVar11 + 1;
              if (*plVar16 != *(longlong *)(*(longlong *)(lVar10 + 0x100) + 0x28)) {
                iVar8 = iVar11;
              }
              iVar11 = iVar8;
            } while (param_4 != (longlong *)0x0);
            if (0 < iVar11) {
              LOCK();
              piVar2 = (int *)(*(longlong *)(lVar10 + 0x100) + 0x80);
              *piVar2 = *piVar2 + iVar11;
              UNLOCK();
            }
            PcpLineDropNblChain(lVar10,local_48);
            local_48 = (longlong *)0x0;
          }
          param_1 = plVar5;
        }
        plVar16 = plVar5;
        lVar10 = lVar17;
      } while (plVar5 != (longlong *)0x0);
    }
    else {
      local_res20 = 0;
      local_res22 = 0;
      plVar16 = (longlong *)(uVar15 * 0x80 + *QosgTimerTable);
      if (lVar17 != plVar16[1]) {
        local_40 = 0;
        uVar7 = KeQueryPerformanceCounter(&local_40);
        uVar9 = (uVar7 >> 0x20) * 1000000;
        bVar3 = *(byte *)(plVar16 + 0xe);
        lVar13 = ((uVar9 % local_40 << 0x20) + (uVar7 & 0xffffffff) * 1000000) / local_40 +
                 (uVar9 / local_40 << 0x20);
        if (bVar3 == 0) {
          bVar6 = 2;
        }
        else {
          bVar6 = bVar3 - 1;
        }
        uVar9 = (ulonglong)bVar6;
        if (plVar16[uVar9 + 8] - lVar13 < 1) {
          plVar16[(ulonglong)bVar3 + 2] = uVar7;
          plVar16[(ulonglong)bVar3 + 5] = local_40;
          plVar16[(ulonglong)bVar3 + 8] = lVar13;
        }
        else {
          plVar16[(ulonglong)bVar3 + 2] = plVar16[uVar9 + 2];
          plVar16[(ulonglong)bVar3 + 5] = plVar16[uVar9 + 5];
          plVar16[(ulonglong)bVar3 + 8] = plVar16[uVar9 + 8];
          lVar13 = plVar16[uVar9 + 8];
        }
        plVar16[(ulonglong)bVar3 + 0xb] = lVar17;
        *plVar16 = lVar13;
        plVar16[1] = lVar17;
        *(byte *)(plVar16 + 0xe) = (byte)((char)plVar16[0xe] + 1U) % 3;
      }
      if ((*(longlong *)(lVar10 + 0xa8) - *plVar16 < 1) ||
         (*(longlong *)(lVar10 + 0xa0) - *plVar16 < 1)) {
        LOCK();
        piVar2 = (int *)(lVar10 + 0x80);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        if (iVar8 == 0) {
          NdisAcquireRWLockWrite(*(undefined8 *)(lVar10 + -8),&local_res20,0);
          QosLineSignalExternalEvent(lVar10,uVar15);
          NdisReleaseRWLock(*(undefined8 *)(lVar10 + -8),&local_res20);
        }
      }
      iVar8 = 0;
      plVar16 = param_1;
      do {
        iVar12 = 0;
        for (puVar4 = (undefined8 *)plVar16[1]; puVar4 != (undefined8 *)0x0;
            puVar4 = (undefined8 *)*puVar4) {
          iVar12 = iVar12 + *(int *)(puVar4 + 3);
        }
        plVar16 = (longlong *)*plVar16;
        iVar8 = iVar8 + iVar12;
      } while (plVar16 != (longlong *)0x0);
      LOCK();
      *(int *)(lVar10 + 0x84) = *(int *)(lVar10 + 0x84) + iVar8;
      UNLOCK();
      plVar16 = param_1;
      do {
        plVar5 = plVar16 + 0xf;
        plVar16 = (longlong *)*plVar16;
        iVar8 = iVar11 + 1;
        if (*plVar5 != *(longlong *)(*(longlong *)(lVar10 + 0xe8) + 0x28)) {
          iVar8 = iVar11;
        }
        iVar11 = iVar8;
      } while (plVar16 != (longlong *)0x0);
      if (0 < iVar11) {
        LOCK();
        piVar2 = (int *)(*(longlong *)(lVar10 + 0xe8) + 0x80);
        *piVar2 = *piVar2 + iVar11;
        UNLOCK();
      }
      NdisFSendNetBufferLists(*(undefined8 *)(*(longlong *)(lVar10 + 0xe8) + 0x28),param_1,0,0);
    }
  }
  return;
}



===== PcpLineSendNetBufferLists @ 14000a170 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpLineSendNetBufferLists(longlong param_1,uint param_2,undefined8 *param_3,longlong *param_4)

{
  longlong *plVar1;
  int *piVar2;
  byte bVar3;
  undefined8 *puVar4;
  byte bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong lVar10;
  int iVar11;
  int iVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *local_res8;
  longlong *local_res18;
  undefined4 local_res20;
  ulonglong local_38 [2];
  
  lVar10 = _DAT_fffff78000000008;
  local_res20 = (int)param_4;
  iVar11 = 0;
  local_res8 = (longlong *)0x0;
  local_res18 = (longlong *)0x0;
  if (param_1 == 0) {
    puVar9 = param_3;
    lVar10 = *(longlong *)((ulonglong)*(ushort *)(param_3[2] + 10) + 0x30 + param_3[2]) + -0x18;
    do {
      puVar4 = (undefined8 *)*puVar9;
      if (puVar4 == (undefined8 *)0x0) {
        lVar13 = 0;
      }
      else {
        lVar13 = *(longlong *)((ulonglong)*(ushort *)(puVar4[2] + 10) + 0x30 + puVar4[2]) + -0x18;
      }
      if (lVar10 != lVar13) {
        *puVar9 = 0;
        uVar6 = (ulonglong)param_2;
        PcpLineSignalExternalEvent(lVar10,uVar6);
        QosLineSendNetBufferLists(lVar10 + 0x18,uVar6,param_3,param_4,&local_res8,&local_res18);
        if (local_res8 != (longlong *)0x0) {
          iVar11 = 0;
          plVar14 = local_res8;
          do {
            plVar1 = plVar14 + 0xf;
            plVar14 = (longlong *)*plVar14;
            iVar12 = iVar11 + 1;
            if (*plVar1 != *(longlong *)(*(longlong *)(lVar10 + 0x100) + 0x28)) {
              iVar12 = iVar11;
            }
            iVar11 = iVar12;
          } while (plVar14 != (longlong *)0x0);
          if (0 < iVar11) {
            LOCK();
            piVar2 = (int *)(*(longlong *)(lVar10 + 0x100) + 0x80);
            *piVar2 = *piVar2 + iVar11;
            UNLOCK();
          }
          param_4 = (longlong *)0x0;
          NdisFSendNetBufferLists
                    (*(undefined8 *)(*(longlong *)(lVar10 + 0x100) + 0x28),local_res8,0);
          local_res8 = (longlong *)0x0;
        }
        if (local_res18 != (longlong *)0x0) {
          iVar11 = 0;
          param_4 = local_res18;
          do {
            plVar14 = param_4 + 0xf;
            param_4 = (longlong *)*param_4;
            iVar12 = iVar11 + 1;
            if (*plVar14 != *(longlong *)(*(longlong *)(lVar10 + 0x100) + 0x28)) {
              iVar12 = iVar11;
            }
            iVar11 = iVar12;
          } while (param_4 != (longlong *)0x0);
          if (0 < iVar11) {
            LOCK();
            piVar2 = (int *)(*(longlong *)(lVar10 + 0x100) + 0x80);
            *piVar2 = *piVar2 + iVar11;
            UNLOCK();
          }
          PcpLineDropNblChain(lVar10,local_res18);
          local_res18 = (longlong *)0x0;
        }
        param_3 = puVar4;
      }
      puVar9 = puVar4;
      lVar10 = lVar13;
    } while (puVar4 != (undefined8 *)0x0);
  }
  else {
    local_res20._3_1_ = (byte)((ulonglong)param_4 >> 0x18);
    local_res20 = (uint)local_res20._3_1_ << 0x18;
    plVar14 = (longlong *)((ulonglong)param_2 * 0x80 + *QosgTimerTable);
    if (_DAT_fffff78000000008 != plVar14[1]) {
      local_38[0] = 0;
      uVar6 = KeQueryPerformanceCounter(local_38);
      uVar7 = (uVar6 >> 0x20) * 1000000;
      bVar3 = *(byte *)(plVar14 + 0xe);
      lVar13 = ((uVar7 % local_38[0] << 0x20) + (uVar6 & 0xffffffff) * 1000000) / local_38[0] +
               (uVar7 / local_38[0] << 0x20);
      if (bVar3 == 0) {
        bVar5 = 2;
      }
      else {
        bVar5 = bVar3 - 1;
      }
      uVar7 = (ulonglong)bVar5;
      if (plVar14[uVar7 + 8] - lVar13 < 1) {
        plVar14[(ulonglong)bVar3 + 2] = uVar6;
        plVar14[(ulonglong)bVar3 + 5] = local_38[0];
        plVar14[(ulonglong)bVar3 + 8] = lVar13;
      }
      else {
        plVar14[(ulonglong)bVar3 + 2] = plVar14[uVar7 + 2];
        plVar14[(ulonglong)bVar3 + 5] = plVar14[uVar7 + 5];
        plVar14[(ulonglong)bVar3 + 8] = plVar14[uVar7 + 8];
        lVar13 = plVar14[uVar7 + 8];
      }
      plVar14[(ulonglong)bVar3 + 0xb] = lVar10;
      *plVar14 = lVar13;
      plVar14[1] = lVar10;
      *(byte *)(plVar14 + 0xe) = (byte)((char)plVar14[0xe] + 1U) % 3;
    }
    if ((*(longlong *)(param_1 + 0xc0) - *plVar14 < 1) ||
       (*(longlong *)(param_1 + 0xb8) - *plVar14 < 1)) {
      LOCK();
      piVar2 = (int *)(param_1 + 0x98);
      iVar12 = *piVar2;
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      if (iVar12 == 0) {
        NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x10),&local_res20,0);
        QosLineSignalExternalEvent(param_1 + 0x18,(ulonglong)param_2);
        NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res20);
      }
    }
    iVar12 = 0;
    plVar14 = param_3;
    if (param_3 == (undefined8 *)0x0) {
      LOCK();
      *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x9c);
      UNLOCK();
    }
    else {
      do {
        iVar8 = 0;
        for (puVar9 = (undefined8 *)plVar14[1]; puVar9 != (undefined8 *)0x0;
            puVar9 = (undefined8 *)*puVar9) {
          iVar8 = iVar8 + *(int *)(puVar9 + 3);
        }
        plVar14 = (longlong *)*plVar14;
        iVar12 = iVar12 + iVar8;
      } while (plVar14 != (longlong *)0x0);
      LOCK();
      *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + iVar12;
      UNLOCK();
      plVar14 = param_3;
      do {
        plVar1 = plVar14 + 0xf;
        plVar14 = (longlong *)*plVar14;
        iVar12 = iVar11 + 1;
        if (*plVar1 != *(longlong *)(*(longlong *)(param_1 + 0x100) + 0x28)) {
          iVar12 = iVar11;
        }
        iVar11 = iVar12;
      } while (plVar14 != (longlong *)0x0);
      if (0 < iVar11) {
        LOCK();
        piVar2 = (int *)(*(longlong *)(param_1 + 0x100) + 0x80);
        *piVar2 = *piVar2 + iVar11;
        UNLOCK();
      }
      NdisFSendNetBufferLists(*(undefined8 *)(*(longlong *)(param_1 + 0x100) + 0x28),param_3,0,0);
    }
  }
  return;
}



===== QosLineSignalExternalEvent @ 14000a530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong QosLineSignalExternalEvent(longlong param_1,ulonglong param_2)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong *plVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined1 auStack_108 [32];
  ulonglong local_e8 [2];
  longlong local_d8;
  longlong local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined8 local_b4;
  undefined8 local_ac;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined4 local_8c;
  longlong local_88;
  ulonglong local_80;
  longlong local_78;
  ulonglong local_70;
  ulonglong local_68;
  ulonglong local_60;
  longlong local_58;
  int local_50;
  int local_4c;
  undefined4 local_48;
  ulonglong local_38;
  
  lVar2 = _DAT_fffff78000000008;
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  plVar12 = (longlong *)((param_2 & 0xffffffff) * 0x80 + *QosgTimerTable);
  if (_DAT_fffff78000000008 != plVar12[1]) {
    local_e8[0] = 0;
    uVar6 = KeQueryPerformanceCounter(local_e8);
    uVar7 = (uVar6 >> 0x20) * 1000000;
    lVar10 = ((uVar7 % local_e8[0] << 0x20) + (uVar6 & 0xffffffff) * 1000000) / local_e8[0] +
             (uVar7 / local_e8[0] << 0x20);
    bVar1 = *(byte *)(plVar12 + 0xe);
    if (bVar1 == 0) {
      bVar3 = 2;
    }
    else {
      bVar3 = bVar1 - 1;
    }
    uVar7 = (ulonglong)bVar3;
    if (plVar12[uVar7 + 8] - lVar10 < 1) {
      plVar12[(ulonglong)bVar1 + 2] = uVar6;
      plVar12[(ulonglong)bVar1 + 5] = local_e8[0];
      plVar12[(ulonglong)bVar1 + 8] = lVar10;
    }
    else {
      plVar12[(ulonglong)bVar1 + 2] = plVar12[uVar7 + 2];
      plVar12[(ulonglong)bVar1 + 5] = plVar12[uVar7 + 5];
      plVar12[(ulonglong)bVar1 + 8] = plVar12[uVar7 + 8];
      lVar10 = plVar12[uVar7 + 8];
    }
    plVar12[(ulonglong)bVar1 + 0xb] = lVar2;
    *plVar12 = lVar10;
    plVar12[1] = lVar2;
    *(byte *)(plVar12 + 0xe) = (byte)((char)plVar12[0xe] + 1U) % 3;
  }
  lVar2 = *plVar12;
  if (*(longlong *)(param_1 + 0xa8) - lVar2 < 1) {
    memset(&local_88,0,0x50);
    uVar6 = (ulonglong)*(uint *)(param_1 + 0x78);
    iVar8 = 0;
    iVar9 = 0;
    if (*(uint *)(param_1 + 0x78) == 0) {
      uVar7 = 0x7fffffffffffffff;
      uVar14 = 0x7fffffff;
      lVar10 = 0x7fffffffffffffff;
      uVar6 = 0x7fffffffffffffff;
      uVar11 = 0x7fffffffffffffff;
      lVar13 = 0;
    }
    else if ((*(uint *)(param_1 + 0xd0) & 4) == 0) {
      *(uint *)(param_1 + 0xd0) = *(uint *)(param_1 + 0xd0) | 4;
      lVar10 = 0;
      lVar13 = 0;
      uVar7 = uVar6;
      uVar11 = uVar6;
      uVar14 = uVar6;
    }
    else {
      LOCK();
      iVar8 = *(int *)(param_1 + 0x84);
      *(int *)(param_1 + 0x84) = 0;
      UNLOCK();
      LOCK();
      iVar9 = *(int *)(param_1 + 0x88);
      *(int *)(param_1 + 0x88) = 0;
      UNLOCK();
      lVar13 = (ulonglong)*(uint *)(param_1 + 0x8c) + ((longlong)iVar8 - (longlong)iVar9);
      uVar14 = (ulonglong)*(uint *)(param_1 + 0x78) - lVar13;
      lVar10 = (uVar14 - (longlong)*(int *)(param_1 + 200)) * 3;
      lVar10 = lVar10 + SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816(lVar10),8);
      lVar5 = SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816((longlong)uVar14),8) + uVar14;
      lVar10 = (lVar10 >> 7) - (lVar10 >> 0x3f);
      uVar6 = (lVar5 >> 6) - (lVar5 >> 0x3f);
      uVar7 = lVar10 + uVar6;
      uVar4 = *(longlong *)(param_1 + 0xb8) + uVar7;
      if ((longlong)uVar4 < 1) {
        uVar4 = 0;
      }
      uVar11 = (ulonglong)*(uint *)(param_1 + 0x7c);
      if ((longlong)uVar4 < (longlong)(ulonglong)*(uint *)(param_1 + 0x7c)) {
        uVar11 = uVar4;
      }
    }
    if (*(int *)*QosgEtwDispatchTable == 1) {
      local_88 = lVar2;
      local_80 = uVar14;
      local_78 = lVar10;
      local_70 = uVar6;
      local_68 = uVar7;
      local_60 = uVar11;
      local_58 = param_1;
      local_50 = iVar8;
      local_4c = iVar9;
      local_48 = (int)lVar13;
      (*(code *)QosgEtwDispatchTable[7])(&local_88);
    }
    uVar6 = (ulonglong)*(uint *)(param_1 + 0x74);
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x98);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x9c);
    *(int *)(param_1 + 200) = (int)uVar14;
    *(ulonglong *)(param_1 + 0xb8) = uVar11;
    *(int *)(param_1 + 0x8c) = (int)lVar13;
    *(ulonglong *)(param_1 + 0xa8) = (uVar6 - (uVar6 + lVar2) % uVar6) + lVar2;
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  uVar6 = *(longlong *)(param_1 + 0xa0) - lVar2;
  if ((longlong)uVar6 < 1) {
    local_bc = 0;
    local_b4 = 0;
    local_ac = 0;
    local_a4 = 0;
    local_9c = 0;
    local_94 = 0;
    local_8c = 0;
    if (*(int *)*QosgEtwDispatchTable == 1) {
      local_c8 = *(undefined4 *)(param_1 + 0x90);
      local_c4 = *(undefined4 *)(param_1 + 0x94);
      local_c0 = *(undefined4 *)(param_1 + 0xb8);
      local_d8 = lVar2;
      local_d0 = param_1;
      (*(code *)QosgEtwDispatchTable[2])(&local_d8);
    }
    uVar7 = (ulonglong)*(uint *)(param_1 + 0x74);
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0xb8);
    uVar6 = (uVar7 + lVar2) / uVar7;
    *(ulonglong *)(param_1 + 0xa0) = (uVar7 - (uVar7 + lVar2) % uVar7) + lVar2;
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x80) = 0;
  UNLOCK();
  return uVar6;
}



===== PcpFilterIncrementDetachCount @ 14000a900 =====

int PcpFilterIncrementDetachCount(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 100);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}



===== QosGetNetBufferCount @ 14000a920 =====

int QosGetNetBufferCount(longlong param_1,int *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  for (puVar1 = *(undefined8 **)(param_1 + 8); puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    iVar3 = iVar3 + *(int *)(puVar1 + 3);
    iVar2 = iVar2 + 1;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar3;
  }
  return iVar2;
}



===== QosLineSendNetBufferLists @ 14000a950 =====

ulonglong QosLineSendNetBufferLists
                    (longlong param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                    undefined8 *param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  for (puVar2 = param_3; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2) {
    iVar3 = 0;
    for (puVar1 = (undefined8 *)puVar2[1]; puVar1 != (undefined8 *)0x0;
        puVar1 = (undefined8 *)*puVar1) {
      iVar3 = iVar3 + *(int *)(puVar1 + 3);
    }
    iVar4 = iVar4 + iVar3;
  }
  LOCK();
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + iVar4;
  UNLOCK();
  *param_5 = param_3;
  *param_6 = 0;
  return (ulonglong)param_6 & 0xffffffffffffff00;
}



===== PcWfpCallout @ 14000a9b0 =====

undefined8
PcWfpCallout(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
            longlong param_5,undefined8 param_6,undefined4 *param_7)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)0x0;
  uVar1 = *(ulonglong *)(param_3 + 0x48);
  lVar4 = *(longlong *)(param_5 + 0x30);
  *param_7 = 0x2006;
  plVar2 = *(longlong **)(param_3 + 0xa8);
  if (uVar1 != 0) {
    plVar5 = *(longlong **)(uVar1 + 0xa8);
  }
  if (plVar2 == (longlong *)0x0) {
    if ((*(uint *)(lVar4 + 0x268) & 8) != 0) {
      return 0;
    }
    LOCK();
    *(int *)(lVar4 + 0x20) = *(int *)(lVar4 + 0x20) + 1;
    UNLOCK();
  }
  else {
    if ((char)plVar2[6] != '\x01') {
      return 0;
    }
    if (uVar1 == 0) {
      return 0;
    }
    if (plVar2 != plVar5) {
      return 0;
    }
    PcpDereferenceFlow(plVar2,uVar1);
    lVar3 = PcpReferenceFlow(lVar4);
    if ((char)lVar3 != '\x01') {
      lVar4 = 0;
    }
  }
  *(longlong *)(param_3 + 0xa8) = lVar4;
  return 0;
}



===== PcQoSPDereferenceFlow @ 14000aa50 =====

void PcQoSPDereferenceFlow(undefined8 *param_1,ulonglong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  plVar2 = (longlong *)*param_1;
  LOCK();
  plVar1 = plVar2 + 4;
  lVar3 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar3 == 1) {
    if ((*(uint *)(plVar2 + 0x4d) & 8) == 0) {
      PcpDeleteFlow(plVar2,param_2);
    }
    else {
      PcpCleanupFlow(plVar2);
    }
  }
  return;
}



===== QosFlowNeedQueueFeedback @ 14000aa88 =====

ulonglong QosFlowNeedQueueFeedback(longlong param_1,longlong param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[4] = 0;
  param_3[3] = 0x7fffffffffffffff;
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x140);
  *(uint *)param_3 = *(uint *)(param_1 + 0x140);
  if (*(int *)(param_1 + 0x140) != 0) {
    uVar1 = QosTbcAdjustBytesSent(param_1,param_2);
    uVar2 = (undefined1)uVar1;
  }
  return CONCAT71((int7)(uVar1 >> 8),uVar2);
}



===== RtlAcquireWriteLock @ 14000aae0 =====

void RtlAcquireWriteLock(longlong param_1)

{
  KeAcquireInStackQueuedSpinLock();
  do {
  } while (*(int *)(param_1 + 8) != 0);
  return;
}



===== PcQoSPReferenceFlow @ 14000ab10 =====

undefined8 PcQoSPReferenceFlow(longlong *param_1)

{
  int *piVar1;
  
  if ((*(uint *)(*param_1 + 0x268) & 8) == 0) {
    LOCK();
    piVar1 = (int *)(*param_1 + 0x20);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    return 0;
  }
  return 0xc0000056;
}



===== PcFilterSetModuleOptions @ 14000ab40 =====

void PcFilterSetModuleOptions(longlong param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  undefined8 local_38;
  code *pcStack_30;
  code *local_28;
  code *pcStack_20;
  code *local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  pcStack_30 = (code *)0x0;
  local_resa = 0;
  local_28 = (code *)0x0;
  pcStack_20 = (code *)0x0;
  local_38 = 0x30008c;
  local_18 = (code *)0x0;
  uStack_10 = 0;
  NdisAcquireRWLockRead(PcgFilterDriverContext,&local_res8,0);
  if (*(char *)(param_1 + 0x1c) == '\0') {
    pcStack_30 = PcFilterSendNetBufferLists;
    local_28 = PcFilterSendNetBufferListsComplete;
    pcStack_20 = PcFilterCancelSend;
    if (*(int *)(param_1 + 0x10) == 3) {
      local_18 = PcFilterReceiveNetBufferLists;
    }
  }
  NdisReleaseRWLock(PcgFilterDriverContext,&local_res8);
  NdisSetOptionalHandlers(*(undefined8 *)(param_1 + 0x28),&local_38);
  return;
}



===== PcpWmiGetGuid @ 14000ac0c =====

undefined8 PcpWmiGetGuid(undefined8 *param_1,longlong *param_2,int param_3)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  bool bVar4;
  
  plVar2 = (longlong *)&PcgSupportedGuids;
  uVar3 = 0;
  do {
    if (0x17 < uVar3) {
      return 0xc0000001;
    }
    if (param_2 == (longlong *)0x0) {
      if ((*(uint *)(plVar2 + 3) & 2) != 0) {
        bVar4 = (int)plVar2[2] == param_3;
        goto LAB_14000ac44;
      }
    }
    else {
      lVar1 = *plVar2 - *param_2;
      if (lVar1 == 0) {
        lVar1 = plVar2[1] - param_2[1];
      }
      bVar4 = lVar1 == 0;
LAB_14000ac44:
      if (bVar4) {
        *param_1 = plVar2;
        return 0;
      }
    }
    uVar3 = uVar3 + 1;
    plVar2 = (longlong *)((longlong)plVar2 + 0x1c);
  } while( true );
}



===== PcpIoctlAddFlow @ 14000ac74 =====

int PcpIoctlAddFlow(longlong param_1,longlong param_2,undefined4 *param_3)

{
  longlong lVar1;
  ushort uVar2;
  int *piVar3;
  longlong lVar4;
  code *pcVar5;
  longlong *plVar6;
  undefined1 uVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  uint uVar13;
  longlong *local_res8;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res8 = (longlong *)0x0;
  piVar3 = *(int **)(param_1 + 0x18);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x228) {
    return -0x3fffffdd;
  }
  if (*(uint *)(param_2 + 0x10) < 0x264) {
LAB_14000acce:
    iVar8 = -0x3fffffdd;
  }
  else {
    if ((ulonglong)*(uint *)(param_2 + 0x10) < (ulonglong)(uint)piVar3[0x98] + 0x264)
    goto LAB_14000acce;
    uVar13 = piVar3[0x98] + 0x250;
    if ((piVar3[4] == uVar13) && ((ushort)*(ulonglong *)(piVar3 + 5) < 0x1ff)) {
      plVar11 = (longlong *)0x0;
      iVar8 = PcpCreateFlow(&local_res8,0,0,*(ulonglong *)(piVar3 + 2),uVar13,1,
                            (ulonglong *)(piVar3 + 5),'\0',(undefined8 *)0x0);
      plVar6 = local_res8;
      if (-1 < iVar8) {
        KeAcquireInStackQueuedSpinLock(&PcgHandleFactoryLock,&local_48);
        plVar11 = plVar6;
        iVar8 = HfAllocateHandle32(PcgHandleFactory,plVar6,(uint *)((longlong)plVar6 + 0x264));
        KeReleaseInStackQueuedSpinLock(&local_48);
        if (-1 < iVar8) {
          lVar1 = lVar4 + 0x20;
          uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
          puVar12 = auStackY_98;
          plVar11 = (longlong *)CONCAT71((int7)((ulonglong)plVar11 >> 8),uVar7);
          if (*(char *)(lVar4 + 0x34) != '\x01') {
            lVar9 = lVar4 + 0x10;
            plVar10 = *(longlong **)(lVar4 + 0x18);
            plVar11 = plVar6 + 2;
            if (*plVar10 != lVar9) {
              plVar10 = (longlong *)0x3;
              pcVar5 = (code *)swi(0x29);
              lVar9 = (*pcVar5)();
              puVar12 = auStackY_90;
            }
            plVar11[1] = (longlong)plVar10;
            *plVar11 = lVar9;
            *plVar10 = (longlong)plVar11;
            *(longlong **)(lVar9 + 8) = plVar11;
            *(undefined8 *)(puVar12 + -8) = 0x14000ae41;
            KeReleaseSpinLock(lVar1);
            *(ulonglong *)(piVar3 + 2) = (ulonglong)*(uint *)((longlong)plVar6 + 0x264);
            lVar4 = plVar6[0x4a];
            piVar3[4] = 0;
            piVar3[5] = 0;
            *(longlong *)(piVar3 + 6) = lVar4;
            uVar2 = *(ushort *)(plVar6 + 10);
            *(ushort *)(piVar3 + 8) = uVar2;
            *(undefined8 *)(puVar12 + -8) = 0x14000ae76;
            memmove((void *)((longlong)piVar3 + 0x22),(void *)((longlong)plVar6 + 0x34),
                    (ulonglong)uVar2 + 2);
            goto LAB_14000adeb;
          }
          KeReleaseSpinLock(lVar1);
          iVar8 = -0x3fffffaa;
        }
      }
      if (plVar6 != (longlong *)0x0) {
        PcpDeleteFlow(plVar6,(ulonglong)plVar11);
      }
    }
    else {
      iVar8 = -0x3ffffff3;
    }
  }
  memset(piVar3 + 1,0,0x224);
LAB_14000adeb:
  *piVar3 = iVar8;
  *param_3 = 0x228;
  return iVar8;
}



===== PcpCleanupFlow @ 14000ae84 =====

void PcpCleanupFlow(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&PcgFlowListLock,&local_28);
  do {
  } while (DAT_1400197f8 != 0);
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
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((*(uint *)(param_1 + 0x4d) & 1) != 0) {
    PcpDecrementHold();
  }
  if (PcgEventTraceEnabled != 0) {
    PcpEtwWriteFlowEvent(&QOS_EVENT_PACER_CLEANUP_FLOW,param_1,7,(longlong)param_1 + 0x8c);
  }
  PcpUninitializeFlow((longlong)param_1);
  PcpTraceActivityIdStop(param_1);
  PcpFreeFlow((longlong)param_1);
  return;
}



===== PcpCreateFlow @ 14000afd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PcpCreateFlow(undefined8 *param_1,uint param_2,int param_3,ulonglong param_4,uint param_5,
                 int param_6,ulonglong *param_7,char param_8,undefined8 *param_9)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 *_Dst;
  undefined1 auStackY_108 [32];
  ushort local_68 [2];
  ushort local_64 [2];
  int local_60 [2];
  undefined8 *local_58;
  undefined8 *local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  local_50 = param_9;
  _Dst = (undefined8 *)(ulonglong)param_5;
  local_58 = (undefined8 *)0x0;
  local_64[0] = 0;
  local_68[0] = 0;
  uVar3 = PcpAllocateFlow(param_5,&local_58);
  puVar1 = local_58;
  local_60[0] = (int)uVar3;
  if (-1 < local_60[0]) {
    PcpInitializeFlow((longlong)local_58);
    if (param_8 == '\0') {
      *(uint *)(puVar1 + 0x4d) = *(uint *)(puVar1 + 0x4d) | 3;
    }
    if (((*(uint *)(puVar1 + 0x4d) & 1) == 0) ||
       (local_60[0] = PcpIncrementHold(), -1 < local_60[0])) {
      _Dst = puVar1 + 0x11;
      memset(_Dst,0,0x1a8);
      QosTbcFlowInitialize((longlong)_Dst);
      if ((param_2 & 1) == 0) {
        _Dst = puVar1;
        uVar4 = PcpUpdateFlow(puVar1,param_4,param_5,param_6,param_7,'\x01',param_3,
                              (undefined4 *)0x0,local_64,local_68);
        local_60[0] = (int)uVar4;
        if (local_60[0] < 0) {
          if ((*(uint *)(puVar1 + 0x4d) & 1) != 0) {
            PcpDecrementHold();
          }
          PcpUninitializeFlow((longlong)puVar1);
          _Dst = puVar1;
          PcpFreeFlow((longlong)puVar1);
        }
      }
    }
    else {
      PcpUninitializeFlow((longlong)puVar1);
      _Dst = puVar1;
      PcpFreeFlow((longlong)puVar1);
    }
  }
  if (local_60[0] < 0) {
    local_58 = (undefined8 *)0x0;
    *param_1 = 0;
  }
  else {
    *param_1 = puVar1;
    if (Microsoft_Windows_Networking_CorrelationEnabled != 0) {
      uStack_48 = 0x7de6b5e058b5a6a8;
      local_50 = local_58;
      if (Microsoft_Windows_Networking_CorrelationEnabled != 0) {
        EtwEx_tidActivityInfo(_Dst,&ActivityStart,&local_50);
      }
      if ((param_2 & 2) != 0) {
        PcpEtwTransferActivityIdGuid();
      }
    }
  }
  if (PcgEventTraceEnabled != 0) {
    if ((param_6 == 2) || (param_6 != 1)) {
      uVar2 = (undefined4)param_7[8];
    }
    else {
      uVar2 = *(undefined4 *)((longlong)param_7 + 0x24c);
    }
    local_50 = (undefined8 *)CONCAT44(local_50._4_4_,uVar2);
    PcpEtwWriteFlowEvent(&QOS_EVENT_PACER_CREATE_FLOW,local_58,8,local_60);
  }
  return local_60[0];
}



===== PcpUninitializeFlow @ 14000b27c =====

void PcpUninitializeFlow(longlong param_1)

{
  undefined1 local_res8 [32];
  
  local_res8[0] = 0;
  RtlCleanupTimerWheelEntry
            (*(undefined8 *)((ulonglong)*(uint *)(param_1 + 0x54) * 0xc0 + 0x20 + PcgTimerUnits),
             param_1 + 0x70,local_res8);
  return;
}



===== PcpIncrementHold @ 14000b2c0 =====

int PcpIncrementHold(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar3 = 0;
  bVar1 = KeGetCurrentIrql();
  bVar5 = bVar1 < 2;
  if (bVar5) {
    KeAcquireInStackQueuedSpinLock(&PcgHoldLock,&local_28);
  }
  else {
    KeAcquireInStackQueuedSpinLockAtDpcLevel();
  }
  PcgHoldCount = PcgHoldCount + 1;
  if (PcgHoldHandle == 0) {
    if ((PcgHoldCloseWorkItem != 0) ||
       (PcgHoldCloseWorkItem = IoAllocateWorkItem(PcgDeviceObject), PcgHoldCloseWorkItem != 0)) {
      if (bVar5) {
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
      else {
        KeReleaseInStackQueuedSpinLockFromDpcLevel();
      }
      if ((bVar1 == 0) && (cVar2 = KeAreApcsDisabled(), cVar2 == '\0')) {
        iVar3 = PcpCreateHoldHandle();
        if (-1 < iVar3) {
          return iVar3;
        }
      }
      else {
        lVar4 = IoAllocateWorkItem(PcgDeviceObject);
        if (lVar4 != 0) {
          IoQueueWorkItemEx(lVar4,PcpCreateHoldHandleWorkerRoutine,1);
          return 0;
        }
        iVar3 = -0x3fffff66;
      }
      PcpDecrementHold();
      return iVar3;
    }
    PcgHoldCount = PcgHoldCount + -1;
    iVar3 = -0x3fffff66;
    PcgHoldCloseWorkItem = 0;
  }
  if (bVar5) {
    KeReleaseInStackQueuedSpinLock(&local_28);
    return iVar3;
  }
  KeReleaseInStackQueuedSpinLockFromDpcLevel();
  return iVar3;
}



===== PcpFindFlow @ 14000b430 =====

undefined8 PcpFindFlow(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0x10);
  while( true ) {
    if (puVar1 == (undefined8 *)(param_2 + 0x10)) {
      return 0xc0000225;
    }
    if (puVar1 + -2 == param_1) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return 0;
}



===== PcpFilterIncrementIntercept @ 14000b460 =====

int PcpFilterIncrementIntercept(void)

{
  undefined8 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  puVar3 = &local_res8;
  puVar5 = (undefined *)0x0;
  local_res8 = 0;
  iVar2 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(PcgFilterDriverContext);
  DAT_140019898 = DAT_140019898 + 1;
  if (DAT_140019898 == 0) {
    iVar2 = -0x3fffff6b;
  }
  else {
    puVar4 = DAT_140019888;
    do {
      if ((undefined8 **)puVar4 == &DAT_140019888) goto LAB_14000b4cc;
      puVar1 = (undefined8 *)*puVar4;
      iVar2 = PcpFilterEnableIntercept((longlong)puVar4,puVar3,puVar5);
      puVar4 = puVar1;
    } while (-1 < iVar2);
  }
  DAT_140019898 = DAT_140019898 + -1;
LAB_14000b4cc:
  NdisReleaseRWLock(PcgFilterDriverContext,&local_res8);
  return iVar2;
}



===== PcpCreateFlowInstanceName @ 14000b4f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcpCreateFlowInstanceName(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [14];
  undefined2 local_1a [5];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_38,param_1 + 0x34);
  local_38._0_4_ = CONCAT22(0x1c,(undefined2)local_38);
  RtlAppendUnicodeToString(&local_38,&PcgFlowPrefix);
  LOCK();
  UNLOCK();
  uVar2 = PcgFlowIndex + 1;
  puVar4 = local_1a;
  iVar3 = 8;
  do {
    uVar1 = uVar2 & 0xf;
    uVar2 = uVar2 >> 4;
    *puVar4 = *(undefined2 *)(&PcgHexChars + (ulonglong)uVar1 * 2);
    puVar4 = puVar4 + -1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_1a[1] = 0;
  PcgFlowIndex = PcgFlowIndex + 1;
  RtlAppendUnicodeToString(&local_38,local_28);
  *(undefined2 *)(param_1 + 0x50) = (undefined2)local_38;
  return;
}



===== PcQoSPValidateAndReferenceFlow @ 14000b5d0 =====

ulonglong PcQoSPValidateAndReferenceFlow(undefined8 *param_1)

{
  ulonglong uVar1;
  
  if (param_1[1] == 0) {
    param_1[2] = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = PcpValidateAndReferenceFlow((uint *)*param_1,param_1[1],param_1 + 2);
  }
  return uVar1;
}



===== QosLineRestart @ 14000b5fc =====

void QosLineRestart(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  return;
}



===== QosTbcTuneParameters @ 14000b614 =====

void QosTbcTuneParameters(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  
  uVar5 = 0;
  uVar4 = 1;
  uVar3 = (uint)(10000 / (ulonglong)*(uint *)(param_1 + 0x150));
  if (uVar3 < 0xb) {
    uVar3 = 10;
  }
  uVar1 = *(uint *)(param_1 + 0x140);
  if (((uVar1 != 0) && (*(uint *)(param_1 + 0x148) != 0)) && (*(uint *)(param_1 + 0x144) != 0)) {
    uVar2 = ((ulonglong)uVar1 * 0x3fffffff) / (ulonglong)*(uint *)(param_1 + 0x148);
    if (uVar2 == 0) {
      uVar2 = 0;
    }
    uVar6 = 0x7fffffff;
    if (uVar2 < 0x7fffffff) {
      uVar6 = uVar2;
    }
    uVar5 = (undefined4)uVar6;
    uVar2 = ((ulonglong)uVar1 * 10) / (ulonglong)*(uint *)(param_1 + 0x144);
    if ((1 < uVar2) && (uVar4 = uVar2, 0xfffffffe < uVar2)) {
      uVar4 = 0xffffffff;
    }
  }
  *(uint *)(param_1 + 0x16c) = uVar3;
  *(undefined4 *)(param_1 + 0x17c) = uVar5;
  *(int *)(param_1 + 0x178) = (int)uVar4;
  *(undefined4 *)(param_1 + 0x170) = 0x14;
  *(undefined4 *)(param_1 + 0x168) = 2;
  return;
}



===== QosTbcDropNbl @ 14000b6e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTbcDropNbl(longlong param_1,longlong *param_2,longlong param_3,int param_4,int param_5,
                  int param_6)

{
  undefined4 uVar1;
  undefined1 auStack_a8 [32];
  longlong local_88;
  int local_80;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(&local_88,0,0x50);
  if (*(int *)*QosgEtwDispatchTable == 1) {
    local_80 = param_6;
    local_88 = param_3;
    QosTraceEvent(4,&local_88);
  }
  uVar1 = 0xc000009a;
  if (1 < param_6 - 2U) {
    uVar1 = 0xc0000120;
  }
  *(undefined4 *)(param_3 + 0x8c) = uVar1;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_4;
  if (param_5 == param_4) {
    *param_2 = param_3;
  }
  return;
}



===== PcpFilterDecrementIntercept @ 14000b794 =====

void PcpFilterDecrementIntercept(int param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(PcgFilterDriverContext,&local_res8,0);
  DAT_140019898 = DAT_140019898 - param_1;
  NdisReleaseRWLock(PcgFilterDriverContext,&local_res8);
  return;
}



===== PcpProcessSettingsChange @ 14000b7f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpProcessSettingsChange(void)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 *puVar4;
  undefined8 *puVar5;
  undefined *puVar6;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined1 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffff98;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined4 local_20;
  
  local_28 = 0;
  local_20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_res8 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_resa = 0;
  PcpReadSettings(0,(uint *)&local_48);
  _PcgSettings = local_48;
  uRam0000000140019848 = uStack_40;
  _DAT_140019868 = local_20;
  _DAT_140019860 = local_28;
  _DAT_140019850 = (undefined4)local_38;
  uRam0000000140019854 = local_38._4_4_;
  uRam0000000140019858 = (undefined4)uStack_30;
  uRam000000014001985c = uStack_30._4_4_;
  NdisAcquireRWLockRead(PcgFilterDriverContext,&local_res8);
  puVar5 = DAT_140019888;
  while ((undefined8 **)puVar5 != &DAT_140019888) {
    LOCK();
    *(int *)((longlong)puVar5 + 100) = *(int *)((longlong)puVar5 + 100) + 1;
    UNLOCK();
    NdisReleaseRWLock(PcgFilterDriverContext,&local_res8);
    NdisAcquireRWLockRead(puVar5[4],&local_res8);
    if (*(int *)(puVar5 + 3) == 2) {
      cVar1 = *(char *)((longlong)puVar5 + 0xd3);
      lVar2 = puVar5[5];
      NdisReleaseRWLock(puVar5[4],&local_res8);
      PcpReadSettings(lVar2,(uint *)&local_48);
      puVar4 = &local_res8;
      puVar6 = (undefined *)0x0;
      NdisAcquireRWLockWrite(puVar5[4]);
      puVar5[0x15] = local_48;
      puVar5[0x16] = uStack_40;
      puVar5[0x17] = local_38;
      puVar5[0x18] = uStack_30;
      puVar5[0x19] = local_28;
      *(undefined4 *)(puVar5 + 0x1a) = local_20;
      if ((cVar1 == '\0') && (*(char *)((longlong)puVar5 + 0xd3) == '\x01')) {
        PcpFilterEnableIntercept((longlong)puVar5,puVar4,puVar6);
      }
    }
    NdisReleaseRWLock(puVar5[4],&local_res8);
    NdisAcquireRWLockRead(PcgFilterDriverContext,&local_res8);
    puVar3 = (undefined8 *)*puVar5;
    PcpFilterDecrementDetachCount((longlong)puVar5);
    puVar5 = puVar3;
  }
  NdisReleaseRWLock(PcgFilterDriverContext);
  NdisAcquireRWLockRead(PcgLineListLock,&local_res8);
  puVar5 = PcgLineList;
  while ((undefined8 **)puVar5 != &PcgLineList) {
    if (puVar5[0x20] == 0) {
      puVar5 = (undefined8 *)*puVar5;
    }
    else {
      LOCK();
      *(int *)(puVar5 + 0x1f) = *(int *)(puVar5 + 0x1f) + 1;
      UNLOCK();
      NdisReleaseRWLock(PcgLineListLock);
      PcpLineUpdate((longlong)puVar5,0,0,(undefined8 *)0x0,0,0,0,in_stack_ffffffffffffff90,
                    in_stack_ffffffffffffff98,-1,0xffffffff);
      NdisAcquireRWLockRead(PcgLineListLock,&local_res8);
      puVar3 = (undefined8 *)*puVar5;
      PcpLineDereference((longlong)puVar5);
      puVar5 = puVar3;
    }
  }
  NdisReleaseRWLock(PcgLineListLock,&local_res8);
  return;
}



===== PcpInitializeFlow @ 14000baa0 =====

void PcpInitializeFlow(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  KeInitializeSpinLock();
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x20) = 1;
  lVar3 = QosTimerGetCurrentTime(0,'\0','\0');
  *(longlong *)(param_1 + 0x230) = lVar3;
  lVar3 = param_1 + 0x238;
  *(longlong *)(param_1 + 0x240) = lVar3;
  *(longlong *)lVar3 = lVar3;
  lVar3 = param_1 + 0x10;
  *(longlong *)(param_1 + 0x18) = lVar3;
  *(longlong *)lVar3 = lVar3;
  *(longlong *)(param_1 + 8) = param_1;
  *(longlong *)param_1 = param_1;
  LOCK();
  UNLOCK();
  uVar1 = (ulonglong)PcgNumberOfProcessors;
  uVar2 = (ulonglong)PcgTimerUnitAssignmentIndex;
  PcgTimerUnitAssignmentIndex = PcgTimerUnitAssignmentIndex + 1;
  *(int *)(param_1 + 0x54) = (int)(uVar2 % uVar1);
  RtlInitializeTimerWheelEntry
            (*(undefined8 *)((uVar2 % uVar1) * 0xc0 + 0x20 + PcgTimerUnits),param_1 + 0x70,0,0);
  return;
}



===== PcpSchedulerDropNblChain @ 14000bb50 =====

void PcpSchedulerDropNblChain
               (longlong param_1,ulonglong param_2,longlong *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong local_res18;
  
  if (param_3 != (longlong *)0x0) {
    local_res18 = 0;
    lVar6 = param_1;
    plVar7 = &local_res18;
    do {
      plVar3 = (longlong *)*param_3;
      *param_3 = 0;
      if (param_3[0xf] == *(longlong *)(param_2 + 0x38)) {
        lVar4 = param_3[2];
        uVar5 = (ulonglong)*(ushort *)(lVar4 + 10);
        if (*(int *)(uVar5 + 0x38 + lVar4) == 0) {
          *(undefined1 *)(uVar5 + 0x3c + lVar4) = 1;
          param_3 = (longlong *)0x0;
          lVar4 = *(longlong *)(uVar5 + 0x20 + lVar4);
          LOCK();
          piVar1 = (int *)(lVar4 + 0x30);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 != 1) goto LAB_14000bbf7;
          QosNblCadReassemble(lVar4,'\0');
          param_3 = *(longlong **)(lVar4 + 0x18);
          lVar6 = QosgNblCadLookasideList;
          ExFreeToNPagedLookasideList();
        }
        if (param_3 != (longlong *)0x0) {
          LOCK();
          *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
          UNLOCK();
        }
      }
LAB_14000bbf7:
      *plVar7 = (longlong)param_3;
      plVar8 = param_3;
      if (param_3 == (longlong *)0x0) {
        plVar8 = plVar7;
      }
      param_3 = plVar3;
      plVar7 = plVar8;
    } while (plVar3 != (longlong *)0x0);
    if (local_res18 != 0) {
      PcpSchedulerCompleteNblChain(lVar6,param_2,local_res18,param_4);
    }
  }
  return;
}



===== PcpFilterEnableIntercept @ 14000bc4c =====

void PcpFilterEnableIntercept(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      param_2 = 0x13;
      param_3 = &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids);
    }
    iVar1 = NdisFRestartFilter(*(undefined8 *)(param_1 + 0x28));
    if (iVar1 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,iVar1);
      }
      *(undefined1 *)(param_1 + 0x1c) = 1;
    }
  }
  NdisConvertNdisStatusToNtStatus(iVar1);
  return;
}



===== PcpAllocateFlow @ 14000bd04 =====

undefined8 PcpAllocateFlow(uint param_1,undefined8 *param_2)

{
  void *_Dst;
  uint uVar1;
  
  if (param_1 < 0x1651) {
    uVar1 = param_1 + 0x270;
    if (uVar1 < 0x270) {
      return 0xc0000095;
    }
    _Dst = (void *)ExAllocatePool2(0x40,uVar1,0x6c666350);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,(ulonglong)uVar1);
      *param_2 = _Dst;
      *(longlong *)((longlong)_Dst + 600) = (longlong)_Dst + 0x270;
      return 0;
    }
  }
  return 0xc000009a;
}



===== PcpFreeFlow @ 14000bd94 =====

void PcpFreeFlow(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(longlong *)(param_1 + 600) != param_1 + 0x270) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 600),0);
  }
  if (*(int *)(param_1 + 0x264) != 0) {
    KeAcquireInStackQueuedSpinLock(&PcgHandleFactoryLock,&local_28);
    HfFreeHandle32(PcgHandleFactory,(int *)(param_1 + 0x264));
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PcpLineStart @ 14000be40 =====

void PcpLineStart(longlong param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x10),&local_res8,0);
  if (*(int *)(param_1 + 0xf4) == 1) {
    *(undefined4 *)(param_1 + 0xf4) = 2;
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res8);
    PcpTcIndicateInterfaceChange(param_1,0x4001000f);
  }
  else {
    NdisReleaseRWLock();
  }
  return;
}



===== QosLineUpdateStats @ 14000bebc =====

void QosLineUpdateStats(longlong param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *param_2;
  uVar3 = *(int *)(param_1 + 0x18) + iVar1;
  *(uint *)(param_1 + 0x18) = uVar3;
  if (0 < iVar1) {
    uVar2 = *(uint *)(param_1 + 0x50);
    if (*(uint *)(param_1 + 0x50) <= uVar3) {
      uVar2 = uVar3;
    }
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    *(uint *)(param_1 + 0x50) = uVar2;
    return;
  }
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    return;
  }
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  return;
}



===== PcpFlowDelay @ 14000bef0 =====

void PcpFlowDelay(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar5 = (ulonglong)param_2;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(uint *)(param_1 + 0x268) & 4) == 0) {
    lVar2 = PcpReferenceFlow(param_1);
    if ((char)lVar2 != '\0') {
      *(uint *)(param_1 + 0x268) = *(uint *)(param_1 + 0x268) | 4;
      lVar2 = PcgDelayQueue;
      puVar1 = (undefined8 *)(param_1 + 0x28);
      lVar4 = (uVar5 & 0xffffffff) * 0x40;
      *puVar1 = 0;
      if (*(longlong *)(lVar4 + lVar2) == 0) {
        *(undefined8 **)(lVar4 + lVar2) = puVar1;
      }
      else {
        **(undefined8 **)(lVar4 + 8 + lVar2) = puVar1;
      }
      *(undefined8 **)(lVar4 + 8 + lVar2) = puVar1;
      if (*(int *)(lVar4 + 0x10 + lVar2) == 0) {
        uVar3 = QosTimerGetCurrentTime((uint)uVar5,'\0','\x01');
        lVar2 = (uVar5 & 0xffffffff) * 0xc0 + PcgTimerUnits;
        RtlAcquireWriteLockAtDpcLevel(lVar2);
        PcpSetTimer(lVar2,uVar3,uVar3 + 0xfa);
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
      }
    }
  }
  return;
}



===== QosTbcProcessQueuedNetBufferLists @ 14000bfcc =====

/* WARNING: Removing unreachable block (ram,0x00014000c070) */

bool QosTbcProcessQueuedNetBufferLists(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  code *pcVar8;
  bool bVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  longlong *plVar14;
  int iVar15;
  int local_res8;
  longlong *in_stack_00000030;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  uint local_68;
  int local_64;
  int local_60;
  longlong local_58;
  longlong *plStack_50;
  undefined8 local_48;
  
  local_res8 = 0;
  *in_stack_00000030 = 0;
  local_68 = 0;
  uVar11 = QosTimerGetCurrentTime(param_2,'\0','\x01');
  local_48 = 0;
  local_58 = 0;
  plStack_50 = (longlong *)0x0;
  if ((QosgLastSendBoundary == 0) ||
     (uVar12 = QosgBoundaryPeriod + QosgLastSendBoundary, uVar12 <= uVar11)) {
    uVar12 = QosgBoundaryPeriod + uVar11;
    bVar9 = true;
    QosgLastSendBoundary = uVar11;
  }
  else {
    bVar9 = false;
  }
  LOCK();
  UNLOCK();
  if ((bVar9) && (*(uint *)(param_1 + 0xd4) != 0)) {
    QosTbcRandomSpread(*(uint *)(param_1 + 0xd4),*(uint *)(param_1 + 0xd8),
                       (undefined8 *)(param_1 + 0x60),uVar11,uVar12);
  }
  iVar15 = 0;
  plVar14 = *(longlong **)(param_1 + 0x60);
  do {
    puVar13 = auStackY_b8;
    if (plVar14 == (longlong *)(param_1 + 0x60)) {
LAB_14000c233:
      puVar6 = *(undefined8 **)(puVar13 + 0xe8);
      iVar10 = *(int *)(puVar13 + 0x44);
      *puVar6 = 0;
      plVar14 = *(longlong **)(param_1 + 0x60);
      iVar2 = *(int *)(puVar13 + 0x40);
      *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + iVar15;
      *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + iVar2;
      LOCK();
      *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + iVar10;
      UNLOCK();
      LOCK();
      *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + *(int *)(puVar13 + 0x48);
      UNLOCK();
      plVar3 = *(longlong **)(puVar13 + 0xd0);
      puVar7 = *(undefined8 **)(puVar13 + 0xd8);
      *plVar3 = *(longlong *)(puVar13 + 0x60);
      if (puVar7 != (undefined8 *)0x0) {
        *puVar7 = *(undefined8 *)(puVar13 + 0x68);
      }
      **(undefined4 **)(puVar13 + 0xe0) = *(undefined4 *)(puVar13 + 0x4c);
      if (*(undefined8 **)(puVar13 + 0xf0) != (undefined8 *)0x0) {
        **(undefined8 **)(puVar13 + 0xf0) = *puVar6;
      }
      lVar4 = *plVar3;
      if (lVar4 != 0) {
        LOCK();
        piVar1 = (int *)(*(longlong *)(lVar4 + 0x60) + 0x30);
        *piVar1 = *piVar1 + local_res8;
        UNLOCK();
      }
      if (*(int *)*QosgEtwDispatchTable == 1) {
        *(undefined4 *)(puVar13 + 0x30) = 0;
        *(int *)(puVar13 + 0x28) = iVar15;
        *(undefined4 *)(puVar13 + 0x20) = 0;
        *(undefined8 *)(puVar13 + -8) = 0x14000c2fa;
        QosTraceFlowSendQueue
                  (param_1,2,uVar11,0,*(undefined4 *)(puVar13 + 0x20),
                   *(undefined4 *)(puVar13 + 0x28),*(undefined4 *)(puVar13 + 0x30));
      }
      return plVar14 != (longlong *)(param_1 + 0x60);
    }
    plVar3 = (longlong *)*plVar14;
    local_64 = QosGetNetBufferCount(plVar14[-3],(int *)&local_68);
    uVar12 = (ulonglong)local_68;
    local_60 = iVar15 + local_68;
    puVar13 = auStackY_b8;
    if (0xfa < (longlong)(plVar14[3] - uVar11)) {
LAB_14000c22b:
      local_res8 = *(int *)(puVar13 + 0xc0);
      goto LAB_14000c233;
    }
    if (*(int *)(param_1 + 0x140) == 0) {
LAB_14000c1c3:
      lVar4 = *plVar14;
      if ((*(longlong **)(lVar4 + 8) != plVar14) ||
         (plVar5 = (longlong *)plVar14[1], (longlong *)*plVar5 != plVar14)) goto LAB_14000c21e;
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      iVar15 = local_60;
      iVar10 = local_64;
      QosNblChainInsert(&local_58,plStack_50,(longlong *)plVar14[-3]);
      *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + uVar12;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar10;
      local_res8 = local_res8 + -1;
      plVar14 = plVar3;
    }
    else {
      if (*(char *)((longlong)plVar14 + -3) == '\0') {
        *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + local_68;
      }
      iVar10 = QosTbcComputeNbsToDrop(param_1,1);
      if (iVar10 == 0) {
        iVar10 = 1;
      }
      else {
        iVar10 = 0;
        if (*(int *)(param_1 + 0x14c) == 1) {
          iVar10 = 2;
        }
      }
      if (iVar10 != 0) {
        puVar13 = auStackY_b8;
        if (iVar10 != 1) goto LAB_14000c22b;
        goto LAB_14000c1c3;
      }
      lVar4 = *plVar14;
      if ((*(longlong **)(lVar4 + 8) != plVar14) ||
         (plVar5 = (longlong *)plVar14[1], (longlong *)*plVar5 != plVar14)) {
LAB_14000c21e:
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        puVar13 = auStackY_b0;
        goto LAB_14000c22b;
      }
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      QosTbcDropNbl(param_1,in_stack_00000030,plVar14[-3],local_64,local_64,7);
      in_stack_00000030 = (longlong *)plVar14[-3];
      plVar14 = plVar3;
    }
  } while( true );
}



===== PcpTraceActivityIdStop @ 14000c320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcpTraceActivityIdStop(undefined8 param_1)

{
  undefined1 auStack_58 [48];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if (Microsoft_Windows_Networking_CorrelationEnabled != 0) {
    uStack_20 = 0x7de6b5e058b5a6a8;
    if (Microsoft_Windows_Networking_CorrelationEnabled != 0) {
      local_28 = param_1;
      EtwEx_tidActivityInfo(param_1,&ActivityStop,&local_28);
    }
  }
  return;
}



===== PcpValidateAndReferenceFlow @ 14000c384 =====

ulonglong PcpValidateAndReferenceFlow(uint *param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  if (param_2 == 8) {
    lVar3 = *(longlong *)param_1;
    lVar1 = PcpReferenceFlow(lVar3);
    if ((char)lVar1 == '\x01') {
      *param_3 = lVar3;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xc0000056;
    }
  }
  else if (param_2 == 0x18) {
    uVar2 = PcpValidateAndReferenceFlowUmode
                      (*param_1,*(longlong *)(param_1 + 2),(int)*(undefined8 *)(param_1 + 4),
                       param_1[4],param_3);
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== PcpTraceUpdateFlowEvent @ 14000c3dc =====

void PcpTraceUpdateFlowEvent(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_res10 [2];
  undefined4 local_res18;
  
  if (PcgEventTraceEnabled != 0) {
    local_res10[0] = param_2;
    local_res18 = param_3;
    PcpEtwWriteFlowEvent(&QOS_EVENT_PACER_UPDATE_FLOW,param_1,8,local_res10);
  }
  return;
}



===== PcpIoctlZawEvent @ 14000c490 =====

undefined8 PcpIoctlZawEvent(void)

{
  PcpProcessSettingsChange();
  return 0;
}



===== PcpUlongToHexString @ 14000c4a8 =====

undefined8 PcpUlongToHexString(uint param_1,undefined8 param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar2 = 8;
  puVar3 = (undefined2 *)(param_3 + 0xe);
  do {
    uVar1 = param_1 & 0xf;
    param_1 = param_1 >> 4;
    *puVar3 = *(undefined2 *)(&PcgHexChars + (ulonglong)uVar1 * 2);
    puVar3 = puVar3 + -1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(param_3 + 0x10) = 0;
  return 0;
}



===== __report_gsfailure @ 14000c4f0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== PcpCreateTimerUnits @ 14000c500 =====

ulonglong PcpCreateTimerUnits(void)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  bool bVar7;
  
  uVar4 = 0;
  uVar6 = 0;
  if (PcgTimerUnits == 0) {
    lVar1 = ExAllocatePool2(0x40,(ulonglong)PcgNumberOfProcessors * 0xc0,0x61746350);
    if (lVar1 == 0) {
      uVar6 = 0xc000009a;
    }
    else {
      while (uVar3 = (uint)uVar4, uVar3 < PcgNumberOfProcessors) {
        uVar2 = PcpInitializeTimerUnit((void *)(uVar4 * 0xc0 + lVar1),uVar3);
        uVar6 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) goto LAB_14000c588;
        uVar4 = (ulonglong)(uVar3 + 1);
      }
      LOCK();
      bVar7 = PcgTimerUnits == 0;
      if (bVar7) {
        PcgTimerUnits = lVar1;
      }
      UNLOCK();
      if (!bVar7) {
LAB_14000c588:
        if (uVar3 != 0) {
          lVar5 = lVar1;
          do {
            PcpUninitializeTimerUnit(lVar5);
            lVar5 = lVar5 + 0xc0;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        ExFreePoolWithTag(lVar1,0x61746350);
      }
    }
  }
  return uVar6;
}



===== PcpDereferenceDriver @ 14000c5d8 =====

void PcpDereferenceDriver(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = PcgDriverReference + -1;
  UNLOCK();
  bVar2 = PcgDriverReference == 1;
  PcgDriverReference = iVar1;
  if (bVar2) {
    NdisSetEvent(&PcgDriverUnloadEvent);
  }
  return;
}



===== PcpInitializeTimerUnit @ 14000c60c =====

undefined8 PcpInitializeTimerUnit(void *param_1,undefined4 param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 local_res18 [4];
  
  uVar3 = 0;
  local_res18[0] = 0;
  lVar2 = ExAllocatePool2(0x40,0x3038,0x77746350);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    cVar1 = RtlInitializeTimerWheel(lVar2,0x200,1,1,0);
    if (cVar1 == '\0') {
      uVar3 = 0xc0000001;
      ExFreePoolWithTag(lVar2,0x77746350);
    }
    else {
      memset(param_1,0,0xc0);
      *(undefined4 *)((longlong)param_1 + 0x2c) = 1;
      KeInitializeDpc((longlong)param_1 + 0x30,PcpTimeoutHandler,param_1);
      KeGetProcessorNumberFromIndex(param_2,local_res18);
      KeSetTargetProcessorDpcEx((longlong)param_1 + 0x30,local_res18);
      KeInitializeTimerEx((longlong)param_1 + 0x70,0);
      KeInitializeSpinLock(param_1);
      *(undefined4 *)((longlong)param_1 + 8) = 0;
      *(longlong *)((longlong)param_1 + 0x20) = lVar2;
      RtlSuspendTimerWheel(lVar2);
    }
  }
  return uVar3;
}



===== PcpSetFlowTimer @ 14000c748 =====

undefined8 PcpSetFlowTimer(longlong param_1,longlong param_2,ulonglong param_3)

{
  longlong *plVar1;
  undefined1 auVar2 [16];
  undefined8 uVar3;
  longlong lVar4;
  int iVar5;
  
  plVar1 = (longlong *)(param_2 + 0x70);
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_3;
  lVar4 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar2,8);
  uVar3 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar2,0);
  iVar5 = (int)((param_3 - lVar4 >> 1) + lVar4 >> 7);
  if ((*(int *)(param_2 + 0x84) == 0) || (iVar5 - *(int *)(param_2 + 0x84) < 0)) {
    if (iVar5 == 0) {
      iVar5 = 1;
    }
    *(int *)(param_2 + 0x84) = iVar5;
    if ((longlong *)*plVar1 == plVar1) {
      LOCK();
      *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
      UNLOCK();
    }
    uVar3 = RtlIndicateTimerWheelEntryTimerStart(*(undefined8 *)(param_1 + 0x20),plVar1);
  }
  return uVar3;
}



===== PcpSetTimer @ 14000c7b8 =====

void PcpSetTimer(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  undefined1 auVar1 [16];
  char cVar2;
  longlong lVar3;
  
  if ((((*(uint *)(param_1 + 0x2c) & 1) != 0) ||
      ((longlong)(*(longlong *)(param_1 + 0x18) - param_2) < 1)) ||
     ((longlong)(param_3 - *(longlong *)(param_1 + 0x18)) < 0)) {
    if (param_2 < param_3) {
      lVar3 = (param_2 - param_3) * 10;
    }
    else {
      lVar3 = 0;
    }
    *(ulonglong *)(param_1 + 0x18) = param_3;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffffe;
    KeSetTimerEx(param_1 + 0x70,lVar3);
  }
  cVar2 = RtlIsTimerWheelSuspended(*(undefined8 *)(param_1 + 0x20));
  if (cVar2 != '\0') {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_2;
    lVar3 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);
    RtlResumeTimerWheel(*(undefined8 *)(param_1 + 0x20),lVar3 + (param_2 - lVar3 >> 1) >> 7);
  }
  if (PcgEventTraceEnabled != 0) {
    PcpTraceTimer(param_1,param_2,0,0);
  }
  return;
}



===== PcpStartTimerWheel @ 14000c8a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PcpStartTimerWheel(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  PcgNumberOfProcessors = KeQueryMaximumProcessorCountEx(0xffff);
  PcgTimerUnitAssignmentIndex = 0;
  DAT_1400198c8 = PcgNumberOfProcessors;
  PcgTimerTable = ExAllocatePool2(0x40,(ulonglong)PcgNumberOfProcessors << 7,0x61746350);
  if (PcgTimerTable == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    PcgTimerUnits = 0;
    uVar1 = PcpCreateTimerUnits();
    uVar2 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      _PcgInitializedModules = _PcgInitializedModules | 8;
      LOCK();
      PcgDriverReference = PcgDriverReference + 1;
      UNLOCK();
      return 0;
    }
  }
  if (PcgTimerTable != 0) {
    ExFreePoolWithTag(PcgTimerTable,0x61746350);
  }
  return uVar2;
}



===== PcpStopTimerWheel @ 14000c950 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopTimerWheel(void)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (PcgTimerUnits != 0) {
    uVar2 = 0;
    if (PcgNumberOfProcessors != 0) {
      do {
        PcpUninitializeTimerUnit(uVar2 * 0xc0 + PcgTimerUnits);
        uVar1 = (int)uVar2 + 1;
        uVar2 = (ulonglong)uVar1;
      } while (uVar1 < PcgNumberOfProcessors);
    }
    ExFreePoolWithTag(PcgTimerUnits,0x61746350);
  }
  if (PcgTimerTable != 0) {
    ExFreePoolWithTag(PcgTimerTable,0x61746350);
  }
  _PcgInitializedModules = _PcgInitializedModules & 0xfffffffffffffff7;
  PcpDereferenceDriver();
  return;
}



===== PcpTimeoutHandler @ 14000c9e0 =====

void PcpTimeoutHandler(undefined8 param_1,longlong param_2,undefined8 param_3,longlong ****param_4)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  char cVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  int iVar14;
  longlong lVar15;
  undefined2 *puVar16;
  longlong *plVar17;
  int iVar18;
  undefined8 *puVar19;
  uint uVar20;
  int iVar21;
  ulonglong uVar22;
  longlong *plVar23;
  undefined2 local_b8;
  undefined1 local_b6;
  int local_b4;
  int local_b0;
  uint local_ac;
  int local_a8 [2];
  ulonglong local_a0;
  longlong *local_98;
  longlong *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  longlong *local_70;
  uint local_68 [10];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_68[8] = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_78 = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_b8 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_b6 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uVar9 = KeGetCurrentProcessorNumberEx(0);
  puVar11 = (undefined8 *)QosTimerGetCurrentTime(uVar9,'\x01','\x01');
  local_98 = (longlong *)0x0;
  auVar4._8_8_ = 0;
  auVar4._0_8_ = puVar11;
  lVar15 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar4,8);
  local_90 = (longlong *)0x0;
  uVar22 = ((ulonglong)((longlong)puVar11 - lVar15) >> 1) + lVar15 >> 7;
  puVar13 = &local_88;
  uVar20 = 0;
  local_a8[0] = 0;
  piVar2 = (int *)((ulonglong)uVar9 * 0x40 + 0x10 + PcgDelayQueue);
  *piVar2 = *piVar2 + 1;
  local_ac = 0;
  local_b0 = 0;
  local_b4 = 0;
  local_a0 = uVar22;
  RtlAcquireWriteLockAtDpcLevel(param_2);
  uVar10 = *(uint *)(param_2 + 0x2c);
  *(undefined8 **)(param_2 + 0x10) = puVar11;
  *(uint *)(param_2 + 0x2c) = (~(uVar10 >> 1) ^ uVar10) & 1 ^ uVar10;
  cVar7 = RtlIsTimerWheelSuspended(*(undefined8 *)(param_2 + 0x20));
  if (cVar7 == '\0') {
    RtlUpdateCurrentTimerWheelTick(*(undefined8 *)(param_2 + 0x20),uVar22 & 0xffffffff);
    plVar12 = (longlong *)RtlGetNextExpiredTimerWheelEntry(*(undefined8 *)(param_2 + 0x20));
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_88);
    if (plVar12 != (longlong *)0x0) {
      LOCK();
      *(int *)(plVar12 + -10) = (int)plVar12[-10] + 1;
      UNLOCK();
      do {
        iVar21 = (int)uVar22;
        plVar1 = plVar12 + -0xe;
        local_70 = plVar12;
        RtlAcquireWriteLockAtDpcLevel((longlong)(plVar12 + -2));
        *(undefined4 *)((longlong)plVar12 + 0x14) = 0;
        plVar3 = plVar12 + 3;
        uVar22 = QosFlowNeedQueueFeedback((longlong)plVar3,(longlong)puVar11,(undefined8 *)local_68)
        ;
        if ((char)uVar22 != '\0') {
          puVar13 = PcpLineFindByLuid(plVar12[-3]);
          if (puVar13 != (undefined8 *)0x0) {
            PcpLineSignalExternalEvent((longlong)puVar13,(ulonglong)uVar9);
            puVar16 = &local_b8;
            NdisAcquireRWLockWrite(puVar13[2],puVar16,0);
            QosLineQueryQueueFeedback((longlong)(puVar13 + 3),puVar16,local_68);
            NdisReleaseRWLock(puVar13[2],&local_b8);
            PcpLineDereference((longlong)puVar13);
            QosTbcAdjustSendWindow((longlong)plVar3,(longlong)local_68);
          }
          iVar21 = (int)local_a0;
        }
        param_4 = (longlong ****)local_a8;
        bVar8 = QosFlowProcessQueuedNetBufferLists((longlong)plVar3,uVar9);
        if (bVar8) {
          auVar5._8_8_ = 0;
          auVar5._0_8_ = *(ulonglong *)(plVar12[0xf] + 0x18);
          lVar15 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar5,8);
          iVar18 = (int)((*(ulonglong *)(plVar12[0xf] + 0x18) - lVar15 >> 1) + lVar15 >> 7);
          iVar14 = iVar18 + 1;
          if (0 < iVar18 - iVar21) {
            iVar14 = iVar18;
          }
          if (iVar14 == 0) {
            iVar14 = 1;
          }
          *(int *)((longlong)plVar12 + 0x14) = iVar14;
        }
        RtlAcquireWriteLockAtDpcLevel(param_2);
        plVar17 = plVar12;
        cVar7 = RtlReturnTimerWheelEntry(*(undefined8 *)(param_2 + 0x20));
        plVar3 = (longlong *)*plVar12;
        plVar12 = (longlong *)RtlGetNextExpiredTimerWheelEntry(*(undefined8 *)(param_2 + 0x20));
        if (plVar12 != (longlong *)0x0) {
          LOCK();
          *(int *)(plVar12 + -10) = (int)plVar12[-10] + 1;
          UNLOCK();
        }
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_88);
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_40);
        if (local_98 != (longlong *)0x0) {
          param_4 = (longlong ****)CONCAT71((int7)((ulonglong)param_4 >> 8),1);
          plVar17 = (longlong *)(ulonglong)uVar9;
          PcpSchedulerBatchAndSendOrDropNblChain(local_98,uVar9,0,(longlong *)param_4);
        }
        plVar23 = local_90;
        if (local_90 != (longlong *)0x0) {
          param_4 = (longlong ****)0x0;
          plVar17 = (longlong *)(ulonglong)uVar9;
          PcpSchedulerBatchAndSendOrDropNblChain(local_90,uVar9,0,(longlong *)0x0);
        }
        if ((plVar3 == local_70) && (cVar7 != '\0')) {
          PcpDereferenceFlow(plVar1,(ulonglong)plVar17);
        }
        PcpDereferenceFlow(plVar1,(ulonglong)plVar17);
        local_b0 = local_b0 + local_a8[0];
        uVar20 = local_ac + 1;
        if (plVar23 != (longlong *)0x0) {
          do {
            plVar23 = (longlong *)*plVar23;
            local_b4 = local_b4 + 1;
          } while (plVar23 != (longlong *)0x0);
        }
        uVar22 = local_a0;
        local_ac = uVar20;
      } while (plVar12 != (longlong *)0x0);
    }
    if (PcgEventTraceEnabled != 0) {
      param_4 = (longlong ****)(ulonglong)uVar20;
      PcpTraceTimer(param_2,puVar11,1,uVar20);
    }
    puVar13 = &local_88;
    RtlAcquireWriteLockAtDpcLevel(param_2);
  }
  uVar10 = RtlGetNextExpirationTimerWheelTick(*(undefined8 *)(param_2 + 0x20));
  if (PcgDisableRecursionFix == 0) {
    puVar11 = (undefined8 *)QosTimerGetCurrentTime(uVar9,'\x01','\x01');
    auVar6._8_8_ = 0;
    auVar6._0_8_ = puVar11;
    puVar13 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar6,8);
    uVar20 = (uint)(((ulonglong)((longlong)puVar11 - (longlong)puVar13) >> 1) + (longlong)puVar13 >>
                   7);
    if (uVar10 < uVar20) {
      puVar19 = puVar11;
      goto LAB_14000cdcd;
    }
  }
  else {
    uVar20 = (uint)uVar22;
  }
  puVar19 = (undefined8 *)((ulonglong)(uVar10 - uVar20) * 0xfa + (longlong)puVar11);
LAB_14000cdcd:
  if (uVar10 == 0) {
    cVar7 = RtlIsTimerWheelSuspended(*(undefined8 *)(param_2 + 0x20));
    puVar11 = puVar13;
    if (cVar7 == '\0') {
      RtlSuspendTimerWheel(*(undefined8 *)(param_2 + 0x20));
      puVar11 = puVar13;
    }
    *(uint *)(param_2 + 0x2c) = *(uint *)(param_2 + 0x2c) | 1;
    KeCancelTimer(param_2 + 0x70);
    if (PcgEventTraceEnabled != 0) {
      puVar11 = *(undefined8 **)(param_2 + 0x10);
      param_4 = (longlong ****)0x0;
      puVar19 = (undefined8 *)0x2;
      PcpTraceTimer(param_2,puVar11,2,0);
    }
  }
  else {
    PcpSetTimer(param_2,(ulonglong)puVar11,(ulonglong)puVar19);
  }
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_88);
  PcpIndicateDelayQueueConsumerEnd(uVar9,puVar11,puVar19,param_4);
  return;
}



===== PcpTraceTimer @ 14000ce80 =====

void PcpTraceTimer(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  PcpEtwWriteEventUlongPtr(&QOS_EVENT_TIMER,0,0,9,local_res18);
  return;
}



===== PcpUninitializeTimerUnit @ 14000cf54 =====

void PcpUninitializeTimerUnit(longlong param_1)

{
  RtlCleanupTimerWheel(*(undefined8 *)(param_1 + 0x20));
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0x77746350);
  return;
}



===== Feature_3421136185__private_IsEnabledDeviceUsageNoInline @ 14000cf90 =====

ulonglong Feature_3421136185__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3421136185__private_featureState;
  if ((Feature_3421136185__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3421136185__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3421136185__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3421136185__private_IsEnabledFallback @ 14000cfc8 =====

void Feature_3421136185__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== PcpAddFilter @ 14000cfe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PcpAddFilter(longlong *param_1,longlong *param_2,short param_3,undefined8 *param_4,
                      longlong param_5,undefined8 param_6,undefined8 param_7)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  undefined4 uVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  longlong lVar14;
  undefined1 auStackY_1b8 [8];
  undefined1 auStackY_1b0 [24];
  undefined4 local_184;
  longlong local_180;
  longlong *local_178;
  longlong *local_170;
  longlong *local_168;
  longlong local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  longlong local_138;
  longlong lStack_130;
  wchar_t *local_128;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_c8;
  longlong local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined8 *local_a0;
  longlong local_68;
  longlong lStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_158 = param_7;
  local_160 = param_5;
  local_170 = param_1;
  local_168 = param_2;
  memset(&local_138,0,200);
  puVar13 = auStackY_1b8;
  local_184 = 0;
  local_178 = (longlong *)0x0;
  uVar10 = 0;
  local_140 = 0;
  local_180 = 0;
  local_68 = 0;
  lStack_60 = 0;
  local_150 = 0;
  uStack_148 = 0;
  if ((param_3 != 2) && (param_3 != 0x17)) {
    uVar12 = 0xc000000d;
    goto LAB_14000d0fa;
  }
  uVar7 = PcpRegisterCallout();
  uVar12 = uVar7 & 0xffffffff;
  if (-1 < (int)uVar7) {
    plVar8 = (longlong *)ExAllocatePool2(0x40,0x90,0x66667750);
    if (plVar8 != (longlong *)0x0) {
      KeAcquireInStackQueuedSpinLock(&PcgHandleFactoryLock,&local_150);
      uVar5 = HfAllocateHandle32(PcgHandleFactory,plVar8,plVar8 + 5);
      uVar12 = (ulonglong)uVar5;
      KeReleaseInStackQueuedSpinLock(&local_150);
      puVar13 = auStackY_1b8;
      lVar14 = 0;
      if ((int)uVar5 < 0) {
LAB_14000d42c:
        *(undefined8 *)(puVar13 + -8) = 0x14000d434;
        PcpFreeFilter((longlong)plVar8);
      }
      else {
        uVar5 = PcpCreateWfpFilterConditionList
                          (param_3,param_1,(longlong)param_2,&local_184,&local_180);
        if (((int)uVar5 < 0) ||
           (uVar5 = ExUuidCreate(&local_68), lVar14 = local_180, (int)uVar5 < 0)) {
          puVar13 = auStackY_1b8;
          uVar12 = (ulonglong)uVar5;
          lVar14 = local_180;
          goto LAB_14000d42c;
        }
        local_128 = L"QoS";
        local_b8 = 0x6004;
        local_c8 = local_184;
        local_c0 = local_180;
        local_138 = local_68;
        lStack_130 = lStack_60;
        local_e8 = 0x41a5e6a9877519e1;
        uStack_e0 = 0x604a8e114f8cb481;
        if (param_3 == 2) {
          local_f8 = 0x9e61aea;
          uStack_f4 = 0x46e2d214;
          uStack_f0 = 0x6bb2219b;
          uStack_ec = 0xc8282f0b;
          local_b4 = 0x10a05337;
          uStack_b0 = 0x4544130d;
          uStack_ac = 0xd47398ad;
          uStack_a8 = 0x7ff76476;
        }
        else {
          local_f8 = 0xe1735bde;
          uStack_f4 = 0x4655013f;
          uStack_f0 = 0x9ea451b3;
          uStack_ec = 0xf02d7615;
          local_b4 = 0x35ccc6d;
          uStack_b0 = 0x40770a70;
          uStack_ac = 0x6142d2b6;
          uStack_a8 = 0x5c479efa;
        }
        local_a0 = param_4;
        uVar12 = Feature_3421136185__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar12 == 0) {
          uVar5 = FwpmFilterAdd0(PcgWfpEngineHandle,&local_138,0,0);
          uVar12 = (ulonglong)uVar5;
        }
        else {
          uVar7 = PcpBeginWfpAdd((longlong)param_4,(undefined4 *)&local_68,&local_178);
          puVar13 = auStackY_1b8;
          uVar12 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_14000d42c;
          uVar5 = FwpmFilterAdd0(PcgWfpEngineHandle,&local_138,0,0);
          uVar12 = (ulonglong)uVar5;
          if (local_178 != (longlong *)0x0) {
            PcpEndWfpAdd(local_178);
          }
        }
        lVar3 = local_160;
        puVar13 = auStackY_1b8;
        iVar6 = (int)uVar12;
        if (iVar6 == 0) {
          lVar1 = local_160 + 0x20;
          uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
          if (*(char *)(lVar3 + 0x34) != '\x01') {
            uVar12 = PcpFindFlow(param_4,lVar3);
            iVar6 = (int)uVar12;
            uVar12 = uVar12 & 0xffffffff;
            if (iVar6 != -0x3ffffddb) {
              plVar8[4] = (longlong)param_4;
              *(short *)((longlong)plVar8 + 0x2c) = param_3;
              plVar8[2] = local_68;
              plVar8[3] = lStack_60;
              lVar3 = local_170[1];
              plVar8[6] = *local_170;
              plVar8[7] = lVar3;
              if (param_3 == 2) {
                plVar8[8] = local_170[2];
                lVar3 = local_168[1];
                plVar8[9] = *local_168;
                plVar8[10] = lVar3;
                plVar8[0xb] = local_168[2];
              }
              else {
                lVar3 = local_170[3];
                plVar8[8] = local_170[2];
                plVar8[9] = lVar3;
                lVar3 = local_170[5];
                plVar8[10] = local_170[4];
                plVar8[0xb] = lVar3;
                lVar3 = local_168[1];
                plVar8[0xc] = *local_168;
                plVar8[0xd] = lVar3;
                lVar3 = local_168[3];
                plVar8[0xe] = local_168[2];
                plVar8[0xf] = lVar3;
                lVar3 = local_168[5];
                plVar8[0x10] = local_168[4];
                plVar8[0x11] = lVar3;
              }
              RtlAcquireWriteLockAtDpcLevel((longlong)(param_4 + 0xc));
              puVar13 = auStackY_1b8;
              puVar9 = param_4 + 0x47;
              plVar11 = (longlong *)param_4[0x48];
              if ((undefined8 *)*plVar11 != puVar9) {
                plVar11 = (longlong *)0x3;
                pcVar2 = (code *)swi(0x29);
                puVar9 = (undefined8 *)(*pcVar2)();
                puVar13 = auStackY_1b0;
              }
              plVar8[1] = (longlong)plVar11;
              *plVar8 = (longlong)puVar9;
              *plVar11 = (longlong)plVar8;
              puVar9[1] = plVar8;
              *(int *)(param_4 + 0x49) = *(int *)(param_4 + 0x49) + 1;
              *(undefined8 *)(puVar13 + -8) = 0x14000d39c;
              KeReleaseInStackQueuedSpinLockFromDpcLevel(puVar13 + 0x68);
              *(undefined8 *)(puVar13 + -8) = 0x14000d3ae;
              KeReleaseSpinLock(lVar1,uVar4);
              goto LAB_14000d3b5;
            }
          }
          KeReleaseSpinLock(lVar1,uVar4);
          iVar6 = FwpmFilterDeleteByKey0(PcgWfpEngineHandle,&local_68);
          if ((((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                     &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,iVar6);
          }
          puVar13 = auStackY_1b8;
          uVar12 = 0xc0000056;
          goto LAB_14000d42c;
        }
LAB_14000d3b5:
        if (iVar6 < 0) goto LAB_14000d42c;
      }
      if (lVar14 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x14000d445;
        ExFreePoolWithTag(lVar14,0);
      }
      uVar10 = *(undefined4 *)(puVar13 + 0x30);
      goto LAB_14000d0fa;
    }
    uVar12 = 0xc000009a;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,0xc000009a);
    }
  }
  puVar13 = auStackY_1b8;
  uVar10 = 0;
LAB_14000d0fa:
  if (*(undefined4 **)(puVar13 + 0x60) != (undefined4 *)0x0) {
    **(undefined4 **)(puVar13 + 0x60) = uVar10;
  }
  *(undefined8 *)(puVar13 + -8) = 0x14000d114;
  return uVar12;
}



===== PcpCleanupFileHandle @ 14000d45c =====

undefined8 PcpCleanupFileHandle(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong ***ppplVar4;
  longlong ***ppplVar5;
  code *pcVar6;
  undefined1 uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong ***ppplVar10;
  undefined8 uVar11;
  longlong ***ppplVar12;
  undefined **ppuVar13;
  longlong ***ppplVar14;
  longlong ***local_48;
  longlong ***local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_48 = (longlong ***)0x0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x30) + 0x18);
  RtlAcquireWriteLock(0x140019780);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    uVar11 = (*pcVar6)();
    return uVar11;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  KeReleaseInStackQueuedSpinLock(&local_38);
  uVar7 = KeAcquireSpinLockRaiseToDpc(plVar1 + 4);
  ppplVar10 = (longlong ***)(plVar1 + 2);
  *(undefined1 *)((longlong)plVar1 + 0x34) = 1;
  local_48 = (longlong ***)*ppplVar10;
  if (local_48 == ppplVar10) {
    local_40 = (longlong ***)&local_48;
    ppplVar12 = local_48;
    local_48 = (longlong ***)&local_48;
  }
  else {
    local_40 = (longlong ***)plVar1[3];
    local_48[1] = (longlong **)&local_48;
    ppplVar12 = (longlong ***)&local_48;
    *local_40 = (longlong **)ppplVar12;
    plVar1[3] = (longlong)ppplVar10;
    *ppplVar10 = (longlong **)ppplVar10;
  }
  uVar9 = Feature_3421136185__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 != 0) {
    for (ppplVar10 = local_48; (longlong ****)ppplVar10 != &local_48;
        ppplVar10 = (longlong ***)*ppplVar10) {
      LOCK();
      *(int *)(ppplVar10 + 2) = *(int *)(ppplVar10 + 2) + 1;
      UNLOCK();
    }
  }
  lVar2 = plVar1[6];
  *(undefined4 *)(plVar1 + 6) = 0;
  ppuVar13 = (undefined **)CONCAT71((int7)((ulonglong)ppplVar12 >> 8),uVar7);
  KeReleaseSpinLock(plVar1 + 4);
  ppplVar10 = local_48;
  while ((longlong ****)ppplVar10 != &local_48) {
    ppplVar12 = ppplVar10 + -2;
    ppplVar4 = (longlong ***)*ppplVar10;
    ppplVar14 = (longlong ***)ppplVar10[0x45];
    while (ppplVar14 != ppplVar10 + 0x45) {
      ppplVar5 = (longlong ***)*ppplVar14;
      ppuVar13 = (undefined **)(ppplVar14 + 2);
      iVar8 = FwpmFilterDeleteByKey0(PcgWfpEngineHandle);
      if (iVar8 < 0) {
        ppuVar13 = &WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
          ppuVar13 = (undefined **)0x11;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,iVar8);
        }
      }
      PcpFreeFilter((longlong)ppplVar14);
      ppplVar14 = ppplVar5;
    }
    PcpDeleteFlow((longlong *)ppplVar12,(ulonglong)ppuVar13);
    uVar9 = Feature_3421136185__private_IsEnabledDeviceUsageNoInline();
    ppplVar10 = ppplVar4;
    if ((int)uVar9 != 0) {
      PcpDereferenceFlow((longlong *)ppplVar12,(ulonglong)ppuVar13);
    }
  }
  if ((int)lVar2 != 0) {
    PcpFilterDecrementIntercept((int)lVar2);
  }
  return 0;
}



===== PcpCreateFileHandle @ 14000d650 =====

int PcpCreateFileHandle(longlong param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  bool bVar7;
  longlong *local_res10;
  longlong local_res18 [2];
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined1 uVar8;
  undefined4 uVar9;
  undefined4 in_stack_ffffffffffffff8c;
  undefined8 local_58;
  wchar_t *local_50;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_48 = 0x420040;
  local_res10 = (longlong *)0x0;
  local_28 = 0;
  local_58 = 0x4e004c;
  iVar2 = 0;
  local_40 = L"Traffic Control Global Interface";
  local_50 = L"{6A5FEDA9-9BCE-4da1-94BF-E67D08946119}";
  local_38 = 0;
  uStack_30 = 0;
  puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x38,0x63686650);
  if (puVar3 == (undefined8 *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3fffff66;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0) {
      return -0x3fffff66;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,0xc000009a);
    return -0x3fffff66;
  }
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar5 = puVar3 + 2;
  puVar3[3] = puVar5;
  *puVar5 = puVar5;
  KeInitializeSpinLock(puVar3 + 4);
  uVar4 = PsGetCurrentProcessId();
  puVar3[5] = uVar4;
  if (PcgGlobalTcLine == (longlong *)0x0) {
    uVar9 = 0;
    uVar8 = 0;
    iVar2 = PcpLineCreate(&local_res10,0,'\x01',local_48._2_2_,local_58._2_2_,0,0x1fffffff,0,0);
    puVar6 = auStackY_b8;
    if (iVar2 < 0) goto LAB_14000d8d5;
    LOCK();
    bVar7 = PcgGlobalTcLine == (longlong *)0x0;
    if (bVar7) {
      PcgGlobalTcLine = local_res10;
    }
    UNLOCK();
    if (bVar7) {
      PcpLineUpdate((longlong)local_res10,(longlong)&local_48,(longlong)&local_58,(undefined8 *)0x0,
                    0,0,0,uVar8,CONCAT44(in_stack_ffffffffffffff8c,uVar9),-1,0xffffffff);
      PcpLineStart((longlong)local_res10);
    }
    else {
      PcpLineDestroy(local_res10);
    }
  }
  if (PcgHandleFactory == 0) {
    local_res18[0] = 0;
    iVar2 = HfCreateFactory(0,local_res18);
    if (iVar2 < 0) {
      puVar6 = auStackY_b8;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (puVar6 = auStackY_b8, 1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (puVar6 = auStackY_b8, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,iVar2);
        puVar6 = auStackY_b8;
      }
      goto LAB_14000d8d5;
    }
    LOCK();
    bVar7 = PcgHandleFactory == 0;
    if (bVar7) {
      PcgHandleFactory = local_res18[0];
    }
    UNLOCK();
    if (!bVar7) {
      HfDestroyFactory(local_res18);
    }
  }
  RtlAcquireWriteLock(0x140019780);
  puVar6 = auStackY_b8;
  puVar5 = &PcgFileCtxList;
  if ((undefined8 *)*DAT_140019778 != &PcgFileCtxList) {
    puVar5 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    DAT_140019778 = (undefined8 *)(*pcVar1)();
    puVar6 = auStackY_b0;
  }
  *puVar3 = puVar5;
  puVar3[1] = DAT_140019778;
  *DAT_140019778 = puVar3;
  *(undefined8 *)(puVar6 + -8) = 0x14000d8c4;
  DAT_140019778 = puVar3;
  KeReleaseInStackQueuedSpinLock(&local_38);
  *(undefined8 **)(*(longlong *)(param_1 + 0x30) + 0x18) = puVar3;
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_14000d8d5:
  *(undefined8 *)(puVar6 + -8) = 0x14000d8e1;
  ExFreePoolWithTag(puVar3,0);
  return iVar2;
}



===== PcpFindFlowByHandle32 @ 14000d904 =====

undefined8 PcpFindFlowByHandle32(int param_1,longlong param_2,longlong *param_3)

{
  undefined8 *puVar1;
  int *piVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_2 + 0x10);
  do {
    if (puVar3 == (undefined8 *)(param_2 + 0x10)) {
      return 0xc0000225;
    }
    puVar1 = puVar3 + -2;
    piVar2 = (int *)((longlong)puVar3 + 0x254);
    puVar3 = (undefined8 *)*puVar3;
  } while (*piVar2 != param_1);
  *param_3 = (longlong)puVar1;
  return 0;
}



===== PcpFreeFilter @ 14000d934 =====

void PcpFreeFilter(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(int *)(param_1 + 0x28) != 0) {
    KeAcquireInStackQueuedSpinLock(&PcgHandleFactoryLock,&local_28);
    HfFreeHandle32(PcgHandleFactory,param_1 + 0x28);
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PcpIoctlAddFlow32 @ 14000d9b8 =====

int PcpIoctlAddFlow32(longlong param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong *puVar1;
  longlong lVar2;
  ushort uVar3;
  int *piVar4;
  longlong lVar5;
  code *pcVar6;
  longlong *plVar7;
  undefined1 uVar8;
  int iVar9;
  longlong lVar10;
  longlong *plVar11;
  uint uVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  longlong *local_res8;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res8 = (longlong *)0x0;
  piVar4 = *(int **)(param_1 + 0x18);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x214) {
    return -0x3fffffdd;
  }
  if (*(uint *)(param_2 + 0x10) < 0x25c) {
LAB_14000da17:
    iVar9 = -0x3fffffdd;
  }
  else {
    puVar1 = (ulonglong *)(piVar4 + 3);
    if ((ulonglong)*(uint *)(param_2 + 0x10) < (ulonglong)(uint)piVar4[0x96] + 0x25c)
    goto LAB_14000da17;
    uVar12 = piVar4[0x96] + 0x250;
    if ((piVar4[2] == uVar12) && ((ushort)*puVar1 < 0x1ff)) {
      plVar13 = (longlong *)0x0;
      iVar9 = PcpCreateFlow(&local_res8,0,0,(ulonglong)(uint)piVar4[1],uVar12,1,puVar1,'\0',
                            (undefined8 *)0x0);
      plVar7 = local_res8;
      if (-1 < iVar9) {
        KeAcquireInStackQueuedSpinLock(&PcgHandleFactoryLock,&local_48);
        plVar13 = plVar7;
        iVar9 = HfAllocateHandle32(PcgHandleFactory,plVar7,(int *)((longlong)plVar7 + 0x264));
        KeReleaseInStackQueuedSpinLock(&local_48);
        if (-1 < iVar9) {
          lVar2 = lVar5 + 0x20;
          uVar8 = KeAcquireSpinLockRaiseToDpc(lVar2);
          puVar14 = auStackY_98;
          plVar13 = (longlong *)CONCAT71((int7)((ulonglong)plVar13 >> 8),uVar8);
          if (*(char *)(lVar5 + 0x34) != '\x01') {
            lVar10 = lVar5 + 0x10;
            plVar11 = *(longlong **)(lVar5 + 0x18);
            plVar13 = plVar7 + 2;
            if (*plVar11 != lVar10) {
              plVar11 = (longlong *)0x3;
              pcVar6 = (code *)swi(0x29);
              lVar10 = (*pcVar6)();
              puVar14 = auStackY_90;
            }
            plVar13[1] = (longlong)plVar11;
            *plVar13 = lVar10;
            *plVar11 = (longlong)plVar13;
            *(longlong **)(lVar10 + 8) = plVar13;
            *(undefined8 *)(puVar14 + -8) = 0x14000db8d;
            KeReleaseSpinLock(lVar2);
            piVar4[1] = *(int *)((longlong)plVar7 + 0x264);
            lVar5 = plVar7[0x4a];
            piVar4[2] = 0;
            *(int *)puVar1 = (int)lVar5;
            uVar3 = *(ushort *)(plVar7 + 10);
            *(ushort *)(piVar4 + 4) = uVar3;
            *(undefined8 *)(puVar14 + -8) = 0x14000dbbf;
            memmove((void *)((longlong)piVar4 + 0x12),(void *)((longlong)plVar7 + 0x34),
                    (ulonglong)uVar3 + 2);
            goto LAB_14000db32;
          }
          KeReleaseSpinLock(lVar2);
          iVar9 = -0x3fffffaa;
        }
      }
      if (plVar7 != (longlong *)0x0) {
        PcpDeleteFlow(plVar7,(ulonglong)plVar13);
      }
    }
    else {
      iVar9 = -0x3ffffff3;
    }
  }
  memset(piVar4 + 1,0,0x210);
LAB_14000db32:
  *piVar4 = iVar9;
  *param_3 = 0x214;
  return iVar9;
}



===== PcpIoctlDeleteFlow32 @ 14000dbcc =====

ulonglong PcpIoctlDeleteFlow32(longlong param_1,longlong param_2,undefined4 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  longlong *plVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  puVar4 = *(uint **)(param_1 + 0x18);
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0xc) {
    return 0xc0000023;
  }
  if (*(uint *)(param_2 + 0x10) < 8) {
    uVar10 = 0xc0000023;
  }
  else if (puVar4[1] == 0) {
    uVar10 = 0xc0000225;
  }
  else {
    lVar1 = lVar5 + 0x20;
    uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
    uVar11 = PcpFindFlowByHandle32(puVar4[1],lVar5,(longlong *)&local_res8);
    plVar8 = local_res8;
    uVar10 = (uint)uVar11;
    if ((int)uVar10 < 0) {
      KeReleaseSpinLock(lVar1,uVar9);
    }
    else {
      RtlAcquireReadLockAtDpcLevel((longlong)(local_res8 + 0xc));
      if ((longlong *)plVar8[0x47] == plVar8 + 0x47) {
        plVar2 = plVar8 + 2;
        lVar5 = *plVar2;
        if ((*(longlong **)(lVar5 + 8) != plVar2) ||
           (plVar6 = (longlong *)plVar8[3], (longlong *)*plVar6 != plVar2)) {
          pcVar7 = (code *)swi(0x29);
          (*pcVar7)(3);
          pcVar7 = (code *)swi(3);
          uVar12 = (*pcVar7)();
          return uVar12;
        }
        *plVar6 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar6;
        uVar12 = CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar9);
        LOCK();
        *(int *)(plVar8 + 0xd) = (int)plVar8[0xd] + -1;
        UNLOCK();
        KeReleaseSpinLock(lVar1);
        uVar3 = *(uint *)(local_res8 + 0x4a);
        puVar4[1] = 0;
        puVar4[2] = uVar3;
        PcpDeleteFlow(local_res8,uVar12);
        goto LAB_14000dd00;
      }
      LOCK();
      *(int *)(plVar8 + 0xd) = (int)plVar8[0xd] + -1;
      UNLOCK();
      KeReleaseSpinLock(lVar1,uVar9);
      uVar10 = 0xc0000101;
    }
  }
  puVar4[1] = 0;
  puVar4[2] = 0;
LAB_14000dd00:
  *puVar4 = uVar10;
  *param_3 = 0xc;
  return (ulonglong)uVar10;
}



===== PcpIoctlDeregisterClient @ 14000dd20 =====

undefined8 PcpIoctlDeregisterClient(longlong param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 4) {
    uVar5 = 0xc0000023;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
    *param_3 = 4;
    if (uVar1 < 8) {
      uVar5 = 0xc0000023;
      *puVar2 = 0xc0000023;
    }
    else {
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x20);
      *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + -1;
      KeReleaseSpinLock(lVar3 + 0x20,uVar4);
      PcpFilterDecrementIntercept(1);
      *puVar2 = 0;
      uVar5 = 0;
    }
  }
  return uVar5;
}



===== PcpIoctlDeregisterClient32 @ 14000ddac =====

undefined8 PcpIoctlDeregisterClient32(longlong param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 4) {
    uVar5 = 0xc0000023;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
    *param_3 = 4;
    if (uVar1 < 4) {
      uVar5 = 0xc0000023;
      *puVar2 = 0xc0000023;
    }
    else {
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x20);
      *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + -1;
      KeReleaseSpinLock(lVar3 + 0x20,uVar4);
      PcpFilterDecrementIntercept(1);
      *puVar2 = 0;
      uVar5 = 0;
    }
  }
  return uVar5;
}



===== PcpIoctlEnumerateFlow @ 14000de38 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PcpIoctlEnumerateFlow(longlong param_1,longlong param_2,int *param_3)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  bool bVar10;
  undefined4 uVar11;
  int iVar12;
  undefined8 *puVar13;
  longlong lVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  undefined4 uVar18;
  undefined8 *puVar19;
  bool bVar20;
  undefined1 local_res10 [8];
  int *local_res18;
  int local_res20;
  uint local_78;
  uint *local_68;
  
  puVar5 = *(undefined4 **)(param_1 + 0x18);
  uVar18 = 0;
  local_res10[0] = 0;
  local_78 = *(uint *)(param_2 + 8);
  if (local_78 < 0x248) {
    return 0xc0000023;
  }
  local_res18 = param_3;
  if (*(uint *)(param_2 + 0x10) < 0x18) {
    memset(puVar5 + 1,0,0x244);
    uVar18 = 0xc0000023;
  }
  else {
    iVar3 = puVar5[4];
    *param_3 = 0x18;
    if (iVar3 == 0) {
      memset(puVar5 + 1,0,0x244);
      *puVar5 = 0xc000000d;
      return 0xc000000d;
    }
    local_78 = local_78 - 0x18;
    uVar4 = puVar5[2];
    bVar20 = uVar4 != 0;
    local_68 = puVar5 + 6;
    local_res20 = 0;
    *(undefined8 *)(puVar5 + 2) = 0;
    bVar10 = false;
    RtlAcquireReadLock(0x140019780,local_res10);
    puVar19 = PcgFileCtxList;
    iVar12 = 0;
    uVar11 = 0;
    if ((undefined8 **)PcgFileCtxList != &PcgFileCtxList) {
      do {
        uVar18 = uVar11;
        if (bVar10) break;
        puVar6 = (undefined8 *)*puVar19;
        KeAcquireSpinLockAtDpcLevel(puVar19 + 4);
        puVar7 = (undefined8 *)puVar19[2];
LAB_14000df5d:
        puVar13 = puVar7;
        if (puVar13 != puVar19 + 2) {
          puVar7 = (undefined8 *)*puVar13;
          puVar17 = (uint *)((longlong)puVar13 + 0x254);
          if (bVar20) goto code_r0x00014000df7e;
          goto LAB_14000df86;
        }
LAB_14000e143:
        KeReleaseSpinLockFromDpcLevel(puVar19 + 4);
        puVar19 = puVar6;
        uVar11 = uVar18;
      } while ((undefined8 **)puVar6 != &PcgFileCtxList);
      iVar12 = local_res20;
    }
    LOCK();
    _DAT_140019788 = _DAT_140019788 + -1;
    UNLOCK();
    KeLowerIrql(local_res10[0]);
    if (!bVar20) {
      *puVar5 = uVar18;
      puVar5[4] = iVar12;
      return uVar18;
    }
    *(undefined8 *)(puVar5 + 2) = 0;
    uVar18 = 0xc000003e;
    puVar5[4] = 0;
  }
  *puVar5 = uVar18;
  *param_3 = 0x18;
  return uVar18;
code_r0x00014000df7e:
  if (*puVar17 == uVar4) {
    bVar20 = false;
LAB_14000df86:
    if (local_res20 != iVar3) {
      iVar12 = PcpComputeFlowInfoLength((longlong)(puVar13 + -2));
      uVar15 = iVar12 + 0x227U & 0xfffffff8;
      if (uVar15 <= local_78) {
        puVar17 = local_68 + 0x88;
        for (puVar8 = (undefined8 *)puVar13[0x45]; puVar8 != puVar13 + 0x45;
            puVar8 = (undefined8 *)*puVar8) {
          sVar1 = *(short *)((longlong)puVar8 + 0x2c);
          puVar17[2] = 0x10;
          if (sVar1 == 2) {
            *puVar17 = 0;
            lVar14 = 0x40;
            puVar17[1] = 0x18;
            puVar17[3] = 0x28;
            uVar9 = puVar8[7];
            *(undefined8 *)(puVar17 + 4) = puVar8[6];
            *(undefined8 *)(puVar17 + 6) = uVar9;
            *(undefined8 *)(puVar17 + 8) = puVar8[8];
            uVar9 = puVar8[10];
            *(undefined8 *)(puVar17 + 10) = puVar8[9];
            *(undefined8 *)(puVar17 + 0xc) = uVar9;
            *(undefined8 *)(puVar17 + 0xe) = puVar8[0xb];
          }
          else {
            *puVar17 = 3;
            lVar14 = 0x70;
            puVar17[1] = 0x30;
            puVar17[3] = 0x40;
            uVar9 = puVar8[7];
            *(undefined8 *)(puVar17 + 4) = puVar8[6];
            *(undefined8 *)(puVar17 + 6) = uVar9;
            uVar9 = puVar8[9];
            *(undefined8 *)(puVar17 + 8) = puVar8[8];
            *(undefined8 *)(puVar17 + 10) = uVar9;
            uVar9 = puVar8[0xb];
            *(undefined8 *)(puVar17 + 0xc) = puVar8[10];
            *(undefined8 *)(puVar17 + 0xe) = uVar9;
            uVar9 = puVar8[0xd];
            *(undefined8 *)(puVar17 + 0x10) = puVar8[0xc];
            *(undefined8 *)(puVar17 + 0x12) = uVar9;
            uVar9 = puVar8[0xf];
            *(undefined8 *)(puVar17 + 0x14) = puVar8[0xe];
            *(undefined8 *)(puVar17 + 0x16) = uVar9;
            uVar9 = puVar8[0x11];
            *(undefined8 *)(puVar17 + 0x18) = puVar8[0x10];
            *(undefined8 *)(puVar17 + 0x1a) = uVar9;
          }
          puVar17 = (uint *)((longlong)puVar17 + lVar14);
        }
        memmove(puVar17,(void *)puVar13[0x49],(ulonglong)*(uint *)(puVar13 + 0x4a));
        uVar16 = (int)puVar17 - (int)local_68;
        local_68[0x87] = uVar16 - 0x220;
        *(undefined8 *)(local_68 + 0x84) = puVar19[5];
        *local_68 = uVar15;
        uVar2 = *(ushort *)(puVar13 + 8);
        *(ushort *)(local_68 + 1) = uVar2;
        memmove((void *)((longlong)local_68 + 6),(void *)((longlong)puVar13 + 0x24),
                (ulonglong)uVar2 + 2);
        local_78 = local_78 - uVar15;
        local_68[0x86] = *(uint *)(puVar13 + 0x47);
        local_68[0x83] = uVar16;
        local_68[0x82] = *(uint *)(puVar13 + 0x4a);
        local_68 = (uint *)((longlong)local_68 + (ulonglong)uVar15);
        *local_res18 = *local_res18 + uVar15;
        local_res20 = local_res20 + 1;
        param_3 = local_res18;
        goto LAB_14000df5d;
      }
      uVar18 = 0xc0000023;
    }
    *(ulonglong *)(puVar5 + 2) = (ulonglong)*puVar17;
    bVar10 = true;
    goto LAB_14000e143;
  }
  goto LAB_14000df5d;
}



===== PcpIoctlEnumerateFlow32 @ 14000e1cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PcpIoctlEnumerateFlow32(longlong param_1,longlong param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  bool bVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  uint uVar13;
  uint *_Dst;
  undefined4 uVar14;
  int *piVar15;
  undefined8 *puVar16;
  bool bVar17;
  undefined1 local_res10 [8];
  int *local_res18;
  int local_res20;
  uint local_78;
  uint *local_68;
  
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  uVar14 = 0;
  local_res10[0] = 0;
  local_78 = *(uint *)(param_2 + 8);
  if (local_78 < 0x238) {
    return 0xc0000023;
  }
  local_res18 = param_3;
  if (*(uint *)(param_2 + 0x10) < 0xc) {
    memset(puVar4 + 1,0,0x234);
    uVar14 = 0xc0000023;
  }
  else {
    iVar2 = puVar4[2];
    *param_3 = 0xc;
    if (iVar2 == 0) {
      memset(puVar4 + 1,0,0x234);
      *puVar4 = 0xc000000d;
      return 0xc000000d;
    }
    local_78 = local_78 - 0xc;
    iVar3 = puVar4[1];
    bVar17 = iVar3 != 0;
    local_68 = puVar4 + 3;
    local_res20 = 0;
    puVar4[1] = 0;
    bVar8 = false;
    RtlAcquireReadLock(0x140019780,local_res10);
    puVar16 = PcgFileCtxList;
    iVar10 = 0;
    uVar9 = 0;
    if ((undefined8 **)PcgFileCtxList != &PcgFileCtxList) {
      do {
        uVar14 = uVar9;
        if (bVar8) break;
        puVar5 = (undefined8 *)*puVar16;
        KeAcquireSpinLockAtDpcLevel(puVar16 + 4);
        puVar6 = (undefined8 *)puVar16[2];
LAB_14000e2f1:
        puVar11 = puVar6;
        if (puVar11 != puVar16 + 2) {
          puVar6 = (undefined8 *)*puVar11;
          piVar15 = (int *)((longlong)puVar11 + 0x254);
          if (bVar17) goto code_r0x00014000e312;
          goto LAB_14000e31a;
        }
LAB_14000e468:
        KeReleaseSpinLockFromDpcLevel(puVar16 + 4);
        puVar16 = puVar5;
        uVar9 = uVar14;
      } while ((undefined8 **)puVar5 != &PcgFileCtxList);
      iVar10 = local_res20;
    }
    LOCK();
    _DAT_140019788 = _DAT_140019788 + -1;
    UNLOCK();
    KeLowerIrql(local_res10[0]);
    if (!bVar17) {
      *puVar4 = uVar14;
      puVar4[2] = iVar10;
      return uVar14;
    }
    puVar4[1] = 0;
    uVar14 = 0xc000003e;
    puVar4[2] = 0;
  }
  *puVar4 = uVar14;
  *param_3 = 0xc;
  return uVar14;
code_r0x00014000e312:
  if (iVar3 == *piVar15) {
    bVar17 = false;
LAB_14000e31a:
    if (local_res20 != iVar2) {
      iVar10 = PcpComputeFlowInfoLength((longlong)(puVar11 + -2));
      uVar13 = iVar10 + 0x21fU & 0xfffffffc;
      if (uVar13 <= local_78) {
        _Dst = local_68 + 0x87;
        for (puVar12 = (undefined8 *)puVar11[0x45]; puVar12 != puVar11 + 0x45;
            puVar12 = (undefined8 *)*puVar12) {
          *_Dst = 0;
          _Dst[1] = 0x18;
          _Dst[2] = 0x10;
          _Dst[3] = 0x28;
          uVar7 = puVar12[7];
          *(undefined8 *)(_Dst + 4) = puVar12[6];
          *(undefined8 *)(_Dst + 6) = uVar7;
          *(undefined8 *)(_Dst + 8) = puVar12[8];
          uVar7 = puVar12[10];
          *(undefined8 *)(_Dst + 10) = puVar12[9];
          *(undefined8 *)(_Dst + 0xc) = uVar7;
          *(undefined8 *)(_Dst + 0xe) = puVar12[0xb];
          _Dst = _Dst + 0x10;
        }
        memmove(_Dst,(void *)puVar11[0x49],(ulonglong)*(uint *)(puVar11 + 0x4a));
        local_68[0x86] = 0x18;
        local_68[0x84] = *(uint *)(puVar16 + 5);
        *local_68 = uVar13;
        uVar1 = *(ushort *)(puVar11 + 8);
        *(ushort *)(local_68 + 1) = uVar1;
        memmove((void *)((longlong)local_68 + 6),(void *)((longlong)puVar11 + 0x24),
                (ulonglong)uVar1 + 2);
        local_78 = local_78 - uVar13;
        local_68[0x85] = *(uint *)(puVar11 + 0x47);
        local_68[0x83] = (int)_Dst - (int)local_68;
        local_68[0x82] = *(uint *)(puVar11 + 0x4a);
        local_68 = (uint *)((longlong)local_68 + (ulonglong)uVar13);
        *local_res18 = *local_res18 + uVar13;
        local_res20 = local_res20 + 1;
        param_3 = local_res18;
        goto LAB_14000e2f1;
      }
      uVar14 = 0xc0000023;
    }
    bVar8 = true;
    puVar4[1] = *piVar15;
    goto LAB_14000e468;
  }
  goto LAB_14000e2f1;
}



===== PcpIoctlRegisterClient @ 14000e4f0 =====

int PcpIoctlRegisterClient(longlong param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  int *piVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  
  piVar2 = *(int **)(param_1 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x10) {
    iVar5 = -0x3fffffdd;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
    *param_3 = 0x10;
    if (uVar1 < 0x18) {
      iVar5 = -0x3fffffdd;
    }
    else {
      iVar5 = PcpFilterIncrementIntercept();
      if (-1 < iVar5) {
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x20);
        *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + 1;
        KeReleaseSpinLock(lVar3 + 0x20,uVar4);
        *piVar2 = 0;
        piVar2[2] = 1;
        piVar2[3] = 0;
        return 0;
      }
    }
    piVar2[2] = 0;
    piVar2[3] = 0;
    *piVar2 = iVar5;
  }
  return iVar5;
}



===== PcpIoctlRegisterClient32 @ 14000e588 =====

int PcpIoctlRegisterClient32(longlong param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  int *piVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  
  piVar2 = *(int **)(param_1 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 8) {
    iVar5 = -0x3fffffdd;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
    *param_3 = 8;
    if (uVar1 < 0x10) {
      iVar5 = -0x3fffffdd;
    }
    else {
      iVar5 = PcpFilterIncrementIntercept();
      if (-1 < iVar5) {
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x20);
        *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + 1;
        KeReleaseSpinLock(lVar3 + 0x20,uVar4);
        *piVar2 = 0;
        piVar2[1] = 1;
        return 0;
      }
    }
    piVar2[1] = 0;
    *piVar2 = iVar5;
  }
  return iVar5;
}



===== PcpRemoveFilterByHandle32 @ 14000e620 =====

ulonglong PcpRemoveFilterByHandle32(int param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  *param_3 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uVar8 = 0xc0000225;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x20);
  puVar9 = *(undefined8 **)(param_2 + 0x10);
  do {
    if (puVar9 == (undefined8 *)(param_2 + 0x10)) break;
    puVar1 = (undefined8 *)*puVar9;
    RtlAcquireWriteLockAtDpcLevel((longlong)(puVar9 + 10));
    puVar2 = (undefined8 *)puVar9[0x45];
    do {
      puVar6 = puVar2;
      if (puVar6 == puVar9 + 0x45) goto LAB_14000e6cb;
      puVar2 = (undefined8 *)*puVar6;
    } while (*(int *)(puVar6 + 5) != param_1);
    if (((undefined8 *)puVar2[1] != puVar6) ||
       (puVar3 = (undefined8 *)puVar6[1], (undefined8 *)*puVar3 != puVar6)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar7 = (*pcVar4)();
      return uVar7;
    }
    *puVar3 = puVar2;
    puVar2[1] = puVar3;
    *(int *)(puVar9 + 0x47) = *(int *)(puVar9 + 0x47) + -1;
    uVar8 = 0;
    *param_3 = puVar6;
LAB_14000e6cb:
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_48);
    puVar9 = puVar1;
  } while (uVar8 != 0);
  KeReleaseSpinLock(param_2 + 0x20,uVar5);
  return (ulonglong)uVar8;
}



===== PcpValidateFlowByHandle32 @ 14000e720 =====

ulonglong PcpValidateFlowByHandle32(int param_1,longlong param_2,longlong *param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x20);
  uVar2 = PcpFindFlowByHandle32(param_1,param_2,param_3);
  if (-1 < (int)uVar2) {
    PcpReferenceFlow(*param_3);
  }
  KeReleaseSpinLock(param_2 + 0x20,uVar1);
  return uVar2 & 0xffffffff;
}



===== WPP_SF_D @ 14000e7a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000e7e4 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000e8bc =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000e9a0 =====

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
LAB_14000eaf8:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000eaeb:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000eaf8;
      if (uVar5 == 5) goto LAB_14000eaeb;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000eb20 =====

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
              (0x3c5a42c,&Feature_3421136185_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000eb9c =====

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
                     (local_50,(uint *)&Feature_3421136185__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3c5a42c,param_3 & 0xffffffff,1,&Feature_3421136185__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3c5a42c);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000ec88 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000ed98 =====

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
  if ((Feature_3421136185__private_featureState & 2) != 0) {
    uVar1 = Feature_3421136185__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3421136185__private_featureState;
      if (bVar3) {
        Feature_3421136185__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3421136185__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 14000edec =====

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



===== wil_details_IsEnabledFallback @ 14000ef4c =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3421136185__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3421136185__private_featureState,(ulonglong)param_1,
                             0x140018768);
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



===== wil_details_MapReportingKind @ 14000efdc =====

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



===== PcFilterCancelSend @ 14000f080 =====

void PcFilterCancelSend(longlong param_1)

{
  NdisFCancelSendNetBufferLists(*(undefined8 *)(param_1 + 0x28));
  return;
}



===== PcFilterSetOptions @ 14000f0a0 =====

undefined8 PcFilterSetOptions(undefined8 param_1)

{
  PcpSetDisableRecursionFix(param_1);
  PcgLineListLock = NdisAllocateRWLock(param_1);
  if (PcgLineListLock == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids);
    }
  }
  else {
    PcgFilterDriverContext = NdisAllocateRWLock(param_1);
    if (PcgFilterDriverContext != 0) {
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids);
    }
    NdisFreeRWLock(PcgLineListLock);
  }
  return 0xc000009a;
}



===== PcpFilterStatusWanLineDown @ 14000f180 =====

undefined8 PcpFilterStatusWanLineDown(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  undefined8 uVar3;
  int iVar4;
  longlong *plVar5;
  undefined2 local_res10;
  undefined1 local_res12;
  
  piVar1 = *(int **)(param_2 + 0x30);
  local_res10 = 0;
  local_res12 = 0;
  if (*(uint *)(param_2 + 0x38) < 0xc) {
    uVar3 = 0xc000000d;
  }
  else if ((*(int *)(param_1 + 0x10) == 3) && (*(short *)(param_1 + 0xd4) == 0x800)) {
    NdisAcquireRWLockRead(PcgLineListLock,&local_res10,0);
    plVar5 = PcgLineList;
    while ((longlong **)plVar5 != &PcgLineList) {
      LOCK();
      *(int *)(plVar5 + 0x1f) = (int)plVar5[0x1f] + 1;
      UNLOCK();
      NdisReleaseRWLock(PcgLineListLock);
      NdisAcquireRWLockWrite(plVar5[2],&local_res10,0);
      iVar4 = (int)plVar5[0x29] - *piVar1;
      if (iVar4 == 0) {
        iVar4 = (uint)*(ushort *)((longlong)plVar5 + 0x14c) - (uint)*(ushort *)(piVar1 + 1);
      }
      if (iVar4 == 0) {
        *(short *)piVar1 = (short)plVar5[0x1e];
        *(undefined2 *)((longlong)piVar1 + 6) = *(undefined2 *)((longlong)plVar5 + 0x14e);
        NdisReleaseRWLock(plVar5[2],&local_res10);
        PcpTraceLineUpDownEvent(plVar5 + 0x25);
        PcpLineDestroy(plVar5);
        NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28),param_2);
        PcpLineDereference((longlong)plVar5);
        goto LAB_14000f34f;
      }
      NdisReleaseRWLock(plVar5[2]);
      NdisAcquireRWLockRead(PcgLineListLock,&local_res10);
      plVar2 = (longlong *)*plVar5;
      PcpLineDereference((longlong)plVar5);
      plVar5 = plVar2;
    }
    NdisReleaseRWLock(PcgLineListLock,&local_res10);
    uVar3 = 0xc0000001;
  }
  else {
    NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28));
LAB_14000f34f:
    uVar3 = 0;
  }
  return uVar3;
}



===== PcpFilterStatusWanLineUp @ 14000f36c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PcpFilterStatusWanLineUp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint *puVar2;
  int *piVar3;
  longlong *plVar4;
  int iVar5;
  ulonglong uVar6;
  undefined4 extraout_var;
  uint uVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 auStackY_b8 [32];
  undefined1 uVar10;
  undefined4 uVar11;
  undefined4 in_stack_ffffffffffffff8c;
  longlong *local_58;
  undefined8 local_50;
  undefined1 local_48 [24];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar2 = *(uint **)(param_2 + 0x30);
  local_58 = (longlong *)0x0;
  local_50 = 0;
  if (*(uint *)(param_2 + 0x38) < 0x40) {
    return 0xc000000d;
  }
  if ((*(int *)(param_1 + 0x10) == 3) && (*(short *)(param_1 + 0xd4) == 0x800)) {
    uVar7 = puVar2[5];
    if (uVar7 == 0) {
      uVar7 = (uint)(ushort)puVar2[6];
    }
    if (uVar7 != 0) {
      uVar6 = PcpFilterStatusWanLineUpdate(param_1,param_2);
      return uVar6;
    }
    uVar7 = puVar2[1];
    uVar11 = *(undefined4 *)(*(longlong *)(param_1 + 0xa0) + 0x130);
    lVar8 = param_1;
    iVar5 = PcpLineCreate(&local_58,param_1,'\0',
                          *(short *)(*(longlong *)(param_1 + 0xa0) + 0x10a) + 0x22,
                          *(ushort *)((longlong)puVar2 + 0x32),0,(ulonglong)(*puVar2 >> 3) * 100,
                          uVar11,uVar7);
    plVar4 = local_58;
    uVar10 = (undefined1)uVar11;
    if (iVar5 < 0) {
      return CONCAT44(extraout_var,iVar5);
    }
    PcpUlongToHexString((uint)*(ushort *)(local_58 + 0x1e),lVar8,(longlong)local_48);
    plVar1 = plVar4 + 0x21;
    RtlAppendUnicodeToString(plVar1,L"WAN: [");
    RtlAppendUnicodeToString(plVar1,local_48);
    RtlAppendUnicodeToString(plVar1,L"] ");
    RtlAppendUnicodeStringToString(plVar1,*(longlong *)(param_1 + 0xa0) + 0x108);
    if ((short)puVar2[10] == 0x800) {
      piVar3 = *(int **)(puVar2 + 8);
      local_58 = (longlong *)0x0;
      local_50 = *(undefined8 *)(piVar3 + 6);
      uVar9 = 0x1a;
      if (*piVar3 != 1) {
        uVar9 = 0x2e;
      }
      iVar5 = NdisAllocateMemoryWithTag(&local_58,uVar9,0x616e6350);
      if (iVar5 == 0) {
        memset(local_58,0,(ulonglong)uVar9);
        *(uint *)local_58 = (*piVar3 != 1) + 1;
        *(undefined2 *)((longlong)local_58 + 4) = 2;
        *(undefined4 *)((longlong)local_58 + 6) = 0x20010;
        *(int *)((longlong)local_58 + 0xe) = piVar3[0x92];
        if (*piVar3 != 1) {
          *(undefined4 *)((longlong)local_58 + 0x1a) = 0x20010;
          *(int *)((longlong)local_58 + 0x22) = piVar3[0x94];
        }
        PcpLineUpdate((longlong)plVar4,0,0,(undefined8 *)0x0,0,0,0,uVar10,
                      CONCAT44(in_stack_ffffffffffffff8c,uVar7),(longlong)local_58,uVar9);
      }
    }
    *(undefined4 *)(plVar4 + 0x29) = *(undefined4 *)((longlong)puVar2 + 0xe);
    *(undefined2 *)((longlong)plVar4 + 0x14c) = *(undefined2 *)((longlong)puVar2 + 0x12);
    *(short *)((longlong)puVar2 + 0xe) = (short)plVar4[0x1e];
    NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28));
    if (*(int *)((longlong)puVar2 + 0x16) == 0) {
      PcpLineDestroy(plVar4);
      return 0xc0000001;
    }
    *(uint *)((longlong)plVar4 + 0x14e) = puVar2[5];
    *(short *)((longlong)plVar4 + 0x152) = (short)puVar2[6];
    *(short *)(puVar2 + 5) = (short)plVar4[0x1e];
    *(short *)((longlong)puVar2 + 0xe) = (short)plVar4[0x29];
    PcpLineUpdate((longlong)plVar4,0,(longlong)(puVar2 + 0xc),&local_50,0,0,0,uVar10,
                  CONCAT44(in_stack_ffffffffffffff8c,uVar7),-1,0xffffffff);
    PcpTraceLineUpDownEvent(plVar4 + 0x25);
    PcpLineStart((longlong)plVar4);
  }
  else {
    NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28));
  }
  return 0;
}



===== PcpFilterStatusWanLineUpdate @ 14000f6d8 =====

undefined8 PcpFilterStatusWanLineUpdate(longlong param_1,longlong param_2)

{
  uint *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined1 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffc8;
  
  puVar1 = *(uint **)(param_2 + 0x30);
  local_res10 = 0;
  local_res12 = 0;
  if (*(uint *)(param_2 + 0x38) < 0x40) {
    uVar3 = 0xc000000d;
  }
  else {
    NdisAcquireRWLockRead(PcgLineListLock,&local_res10);
    puVar5 = PcgLineList;
    while ((undefined8 **)puVar5 != &PcgLineList) {
      LOCK();
      *(int *)(puVar5 + 0x1f) = *(int *)(puVar5 + 0x1f) + 1;
      UNLOCK();
      NdisReleaseRWLock(PcgLineListLock);
      NdisAcquireRWLockWrite(puVar5[2],&local_res10);
      if (*(int *)((longlong)puVar5 + 0xf4) - 1U < 2) {
        iVar4 = *(int *)(puVar5 + 0x29) - *(int *)((longlong)puVar1 + 0xe);
        if (iVar4 == 0) {
          iVar4 = (uint)*(ushort *)((longlong)puVar5 + 0x14c) -
                  (uint)*(ushort *)((longlong)puVar1 + 0x12);
        }
        if (iVar4 == 0) {
          *(undefined2 *)((longlong)puVar1 + 0xe) = *(undefined2 *)(puVar5 + 0x1e);
          *(undefined2 *)(puVar1 + 5) = *(undefined2 *)((longlong)puVar5 + 0x14e);
          NdisReleaseRWLock(puVar5[2],&local_res10);
          PcpLineUpdate((longlong)puVar5,0,0,(undefined8 *)0x0,(ulonglong)(*puVar1 >> 3) * 100,0,
                        puVar1[1],in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,-1,0xffffffff)
          ;
          NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x28),param_2);
          PcpLineDereference((longlong)puVar5);
          return 0;
        }
      }
      NdisReleaseRWLock(puVar5[2],&local_res10);
      NdisAcquireRWLockRead(PcgLineListLock,&local_res10);
      puVar2 = (undefined8 *)*puVar5;
      PcpLineDereference((longlong)puVar5);
      puVar5 = puVar2;
    }
    NdisReleaseRWLock(PcgLineListLock,&local_res10);
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== PcpSetDisableRecursionFix @ 14000f8ac =====

void PcpSetDisableRecursionFix(undefined8 param_1)

{
  int local_res8 [2];
  undefined8 local_res10;
  longlong local_res18;
  undefined8 local_38;
  wchar_t *local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_28 = 0x1401a9;
  uStack_18 = 0;
  local_res10 = 0;
  local_20 = param_1;
  local_res8[0] = NdisOpenConfigurationEx(&local_28,&local_res10);
  if (local_res8[0] == 0) {
    local_30 = L"DisableRecursionFix";
    local_res18 = 0;
    local_38 = 0x280026;
    NdisReadConfiguration(local_res8,&local_res18,local_res10,&local_38,0);
    if (local_res8[0] == 0) {
      PcgDisableRecursionFix = (uint)(*(int *)(local_res18 + 8) == 1);
    }
    NdisCloseConfiguration(local_res10);
  }
  return;
}



===== WPP_SF_ @ 14000f960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_d @ 14000f98c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_263d9268693f357b83e9029a6246d0a9_Traceguids,0x14,local_res20,4,0);
  return;
}



===== WPP_SF_i @ 14000f9d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_i(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== EtwEx_tidActivityInfo @ 14000fa1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidActivityInfo(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auStack_68 [32];
  undefined **local_48;
  undefined4 local_38 [2];
  undefined *local_30;
  undefined8 local_28;
  undefined4 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar1 = 0;
  local_38[0] = 0;
  if (Microsoft_Windows_Networking_CorrelationTraceActivityPayload == 0) {
    local_48 = (undefined **)0x0;
  }
  else {
    local_28 = 0x10;
    local_30 = &Microsoft_Windows_Networking_ProviderId;
    uVar1 = 2;
    local_20 = local_38;
    local_18 = 4;
    local_48 = &local_30;
  }
  EtwWrite(Microsoft_Windows_Networking_CorrelationHandle,param_2,param_3,uVar1);
  return;
}



===== EtwEx_tidActivityInfoTransfer @ 14000faa8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidActivityInfoTransfer(void)

{
  undefined1 uStack0000000000000038;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined **local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0x1000ea63;
  uStack_44 = 0x901;
  uStack_40 = 1;
  uStack_3c = 0x80000000;
  if (Microsoft_Windows_Networking_CorrelationTraceActivityPayload == 0) {
    local_50 = (undefined **)0x0;
    local_58 = 0;
  }
  else {
    local_30 = 0x10;
    local_38 = &Microsoft_Windows_Networking_ProviderId;
    local_28 = &uStack0000000000000038;
    local_50 = &local_38;
    local_58 = 2;
    local_20 = 4;
  }
  EtwWriteTransfer(Microsoft_Windows_Networking_CorrelationHandle,&local_48);
  return;
}



===== PcpComputeFlowInfoLength @ 14000fb48 =====

int PcpComputeFlowInfoLength(longlong param_1)

{
  short *psVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  
  if ((char)*(undefined4 *)(param_1 + 0x30) == '\x01') {
    iVar4 = *(int *)(param_1 + 0x248) * 0x10 + *(int *)(param_1 + 0x260);
    puVar3 = *(undefined8 **)(param_1 + 0x238);
    while (puVar3 != (undefined8 *)(param_1 + 0x238)) {
      psVar1 = (short *)((longlong)puVar3 + 0x2c);
      puVar3 = (undefined8 *)*puVar3;
      iVar2 = 0x30;
      if (*psVar1 != 2) {
        iVar2 = 0x60;
      }
      iVar4 = iVar4 + iVar2;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x260);
  }
  return iVar4;
}



===== PcpCreateHoldHandle @ 14000fb98 =====

int PcpCreateHoldHandle(void)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_24 = 0;
  local_res8 = 0;
  local_3c = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  lVar3 = IoAllocateWorkItem(PcgDeviceObject);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    RtlInitUnicodeString(&local_78,L"\\Device\\Psched");
    local_30 = &local_78;
    local_38 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_20 = 0;
    uStack_18 = 0;
    iVar2 = ZwCreateFile(&local_res8,0x80000000,&local_40,&local_68,0,0x80,7,1,0x40,0,0);
    if (-1 < iVar2) {
      KeAcquireInStackQueuedSpinLock(&PcgHoldLock,&local_58);
      lVar1 = local_res8;
      if ((PcgHoldCount != 0) && (PcgHoldHandle == 0)) {
        local_res8 = 0;
        PcgHoldHandle = lVar1;
      }
      KeReleaseInStackQueuedSpinLock(&local_58);
      if (local_res8 != 0) {
        IoQueueWorkItemEx(lVar3,PcpCloseHoldHandleWorkerRoutine,1);
        return iVar2;
      }
    }
    IoFreeWorkItem(lVar3);
  }
  return iVar2;
}



===== PcpDecrementHold @ 14000fd28 =====

void PcpDecrementHold(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&PcgHoldLock,&local_28);
  lVar2 = PcgHoldHandle;
  lVar1 = PcgHoldCloseWorkItem;
  PcgHoldCount = PcgHoldCount + -1;
  lVar3 = 0;
  lVar4 = 0;
  if (PcgHoldCount == 0) {
    PcgHoldHandle = 0;
    PcgHoldCloseWorkItem = 0;
    lVar3 = lVar1;
    lVar4 = lVar2;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (lVar4 == 0) {
    if (lVar3 != 0) {
      IoFreeWorkItem(lVar3);
    }
  }
  else {
    IoQueueWorkItemEx(lVar3,PcpCloseHoldHandleWorkerRoutine,1,lVar4);
  }
  return;
}



===== PcpEtwTransferActivityIdGuid @ 14000fde0 =====

void PcpEtwTransferActivityIdGuid(void)

{
  if (Microsoft_Windows_Networking_CorrelationEnabled != 0) {
    EtwEx_tidActivityInfoTransfer();
  }
  return;
}



===== PcpTraceFlowConformance @ 14000fe10 =====

void PcpTraceFlowConformance(longlong param_1)

{
  PcpEtwWriteFlowEvent
            (&QOS_EVENT_PACER_FLOW_CONFORMANCE,*(longlong *)(param_1 + 0x30) + -0x88,8,
             param_1 + 0x3c);
  return;
}



===== PcpTraceFlowControlInterval @ 14000fee0 =====

void PcpTraceFlowControlInterval(longlong param_1)

{
  PcpEtwWriteFlowEvent
            (&QOS_EVENT_PACER_FLOW_CONTROL_INTERVAL,*(longlong *)(param_1 + 0x10) + -0x88,0xe,
             param_1);
  return;
}



===== PcpTraceFlowSendQueue @ 140010040 =====

void PcpTraceFlowSendQueue(longlong param_1)

{
  PcpEtwWriteFlowEvent
            (&QOS_EVENT_PACER_FLOW_SEND_QUEUE,*(longlong *)(param_1 + 0x18) + -0x88,7,param_1 + 0x2c
            );
  return;
}



===== PcpTraceNonConformingQueryTrafficClassEvent @ 1400100f0 =====

void PcpTraceNonConformingQueryTrafficClassEvent(longlong *param_1)

{
  if (PcgEventTraceEnabled != 0) {
    PcpEtwWriteEventUlongPtr
              (&QOS_EVENT_PACER_NONCONF_QTC,*(ulonglong *)(*param_1 + 0xf8) & 0x7fffffffffffffff,0,3
               ,param_1 + 1);
  }
  return;
}



===== PcpTracePacketDrop @ 140010170 =====

void PcpTracePacketDrop(longlong *param_1)

{
  undefined4 local_res8 [8];
  
  local_res8[0] = (undefined4)param_1[1];
  if (PcgEventTraceEnabled != 0) {
    PcpEtwWriteEventUlongPtr
              (&QOS_EVENT_PACER_PACKET_DROP,*(ulonglong *)(*param_1 + 0xf8) & 0x7fffffffffffffff,0,1
               ,local_res8);
  }
  return;
}



===== PcpValidateAndReferenceFlowUmode @ 1400101d0 =====

ulonglong PcpValidateAndReferenceFlowUmode
                    (uint param_1,longlong param_2,int param_3,int param_4,longlong *param_5)

{
  undefined1 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong local_res10;
  
  local_res10 = 0;
  if ((PcgDeviceObject == 0) ||
     (lVar2 = IoGetRelatedDeviceObject(param_2), lVar2 != PcgDeviceObject)) {
    return 0xc0000008;
  }
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar1 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x20);
  if (*(char *)(lVar2 + 0x34) != '\x01') {
    if ((param_1 & 1) == 0) {
      param_4 = param_3;
    }
    uVar3 = PcpFindFlowByHandle32(param_4,lVar2,&local_res10);
    uVar6 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) goto LAB_140010273;
    lVar5 = local_res10;
    lVar4 = PcpReferenceFlow(local_res10);
    if ((char)lVar4 != '\0') {
      *param_5 = lVar5;
      goto LAB_140010273;
    }
  }
  uVar6 = 0xc0000056;
LAB_140010273:
  KeReleaseSpinLock(lVar2 + 0x20,uVar1);
  return uVar6;
}



===== WPP_SF_L @ 1400102a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,0x11,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 140010300 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar1;
  }
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140010334 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14001879f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 14001035c =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400104b0 =====

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



===== PcAttachQoSClient @ 140010540 =====

undefined8
PcAttachQoSClient(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined2 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  code *pcVar1;
  undefined8 *_Dst;
  undefined8 uVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined2 local_18;
  undefined1 local_16;
  
  local_18 = 0;
  local_16 = 0;
  _Dst = (undefined8 *)ExAllocatePool2(0x40,0x40,0x63536f51);
  if (_Dst == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,0x40);
    _Dst[3] = param_5;
    puVar3 = &PcpQoSProviderDispatchPrivate;
    _Dst[2] = param_4;
    _Dst[6] = param_1;
    *(byte *)(_Dst + 7) = (byte)((ushort)*param_5 >> 0xf);
    *param_6 = _Dst;
    if (*(char *)(_Dst + 7) == '\0') {
      puVar3 = &PcpQoSProviderDispatch;
    }
    *param_7 = puVar3;
    LOCK();
    *(int *)(_Dst + 4) = *(int *)(_Dst + 4) + 1;
    UNLOCK();
    NdisAcquireRWLockWrite(PcgQoSClientListLock,&local_18,0);
    puVar4 = auStack_38;
    puVar3 = &PcgQoSClientList;
    if ((undefined *)*DAT_1400196e8 != &PcgQoSClientList) {
      puVar3 = (undefined *)0x3;
      pcVar1 = (code *)swi(0x29);
      DAT_1400196e8 = (undefined8 *)(*pcVar1)();
      puVar4 = auStack_30;
    }
    *_Dst = puVar3;
    uVar2 = PcgQoSClientListLock;
    _Dst[1] = DAT_1400196e8;
    *DAT_1400196e8 = _Dst;
    *(undefined8 *)(puVar4 + -8) = 0x14001063b;
    DAT_1400196e8 = _Dst;
    NdisReleaseRWLock(uVar2,puVar4 + 0x20);
    uVar2 = 0;
  }
  return uVar2;
}



===== PcCleanupQoSClient @ 140010660 =====

void PcCleanupQoSClient(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PcDeregisterQoSProviderComplete @ 140010680 =====

void PcDeregisterQoSProviderComplete(void)

{
  PcpDereferenceDriver();
  return;
}



===== PcDetachQoSClient @ 1400106a0 =====

undefined8 PcDetachQoSClient(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  param_1[5] = param_1[6];
  NdisAcquireRWLockWrite(PcgQoSClientListLock,&local_res8,0);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) != param_1) ||
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    uVar4 = (*pcVar3)();
    return uVar4;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  NdisReleaseRWLock(PcgQoSClientListLock,&local_res8);
  LOCK();
  plVar2 = param_1 + 4;
  lVar1 = *plVar2;
  *(int *)plVar2 = (int)*plVar2 + -1;
  UNLOCK();
  if ((int)lVar1 == 1) {
    NmrProviderDetachClientComplete(param_1[5]);
  }
  return 0x103;
}



===== PcQoSPAssociateFlow @ 140010740 =====

undefined8 PcQoSPAssociateFlow(longlong *param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar1 = *param_1;
  if (*(longlong **)(param_1[1] + 0xa8) != (longlong *)0x0) {
    PcpDereferenceFlow(*(longlong **)(param_1[1] + 0xa8),param_2);
  }
  lVar2 = PcpReferenceFlow(lVar1);
  if ((char)lVar2 == '\0') {
    *(undefined8 *)(param_1[1] + 0xa8) = 0;
    uVar3 = 0xc0000056;
  }
  else {
    *(longlong *)(param_1[1] + 0xa8) = lVar1;
    uVar3 = 0;
  }
  return uVar3;
}



===== PcQoSPConfigureGlobalSetting @ 1400107a0 =====

undefined8 PcQoSPConfigureGlobalSetting(int *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*param_1 == 0) {
    if (param_1[4] == 4) {
      PcgAllowAppDSCPMarking = **(undefined4 **)(param_1 + 2);
      if (PcgEventTraceEnabled != 0) {
        PcpEtwWriteEventUlongPtr
                  (&QOS_EVENT_PACER_ALLOW_APP_DSCP_MARKING,0,0,1,*(undefined4 **)(param_1 + 2));
      }
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== PcQoSPCopyFlow @ 140010810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcQoSPCopyFlow(longlong *param_1)

{
  int iVar1;
  undefined1 auStackY_78 [32];
  longlong local_28 [5];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStackY_78;
  local_28[0] = *param_1;
  local_28[1] = 0x7de6b5e058b5a6a8;
  iVar1 = PcpCreateFlow((undefined8 *)param_1[1],2,0,0,*(uint *)(local_28[0] + 0x260),
                        *(uint *)(local_28[0] + 0x30) & 0xff,*(ulonglong **)(local_28[0] + 600),'\0'
                        ,local_28);
  PcpNormalizeNtStatus(iVar1);
  return;
}



===== PcQoSPCreateFlow @ 1400108a0 =====

void PcQoSPCreateFlow(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  
  if (*(int *)((longlong)param_1 + 0x14) != 1) {
    for (uVar3 = 0; (uint)uVar3 < 4; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      if ((&PcgQoSFlowTypeMapping)[uVar3 * 2] == *(int *)((longlong)param_1 + 0x14)) {
        uVar1 = (int)((ulonglong *)*param_1)[8] + 0x50;
        if (uVar1 < 0x50) {
          iVar2 = -0x3fffff6b;
        }
        else if ((ulonglong)param_1[1] < (ulonglong)uVar1) {
          iVar2 = -0x3fffffdd;
        }
        else {
          iVar2 = PcpCreateFlow((undefined8 *)param_1[3],*(uint *)(param_1 + 2),
                                *(int *)(param_1 + 4),0,uVar1,*(int *)(&UNK_140016dd4 + uVar3 * 8),
                                (ulonglong *)*param_1,'\0',(undefined8 *)((longlong)param_1 + 0x24))
          ;
        }
        goto LAB_140010924;
      }
    }
  }
  iVar2 = -0x3ffffff3;
LAB_140010924:
  PcpNormalizeNtStatus(iVar2);
  return;
}



===== PcQoSPCreateFlowPrivate @ 140010940 =====

void PcQoSPCreateFlowPrivate(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (int)((ulonglong *)*param_1)[8] + 0x50;
  if (uVar1 < 0x50) {
    iVar2 = -0x3fffff6b;
  }
  else if ((ulonglong)param_1[1] < (ulonglong)uVar1) {
    iVar2 = -0x3fffffdd;
  }
  else {
    iVar2 = PcpCreateFlow((undefined8 *)param_1[3],0,0,0,uVar1,2,(ulonglong *)*param_1,'\0',
                          (undefined8 *)param_1[2]);
  }
  PcpNormalizeNtStatus(iVar2);
  return;
}



===== PcQoSPDeleteFlow @ 1400109b0 =====

void PcQoSPDeleteFlow(undefined8 *param_1,ulonglong param_2)

{
  PcpDeleteFlow((longlong *)*param_1,param_2);
  return;
}



===== PcQoSPQueryFlowSize @ 1400109d0 =====

void PcQoSPQueryFlowSize(int *param_1)

{
  param_1[1] = *param_1 + 0x2c0;
  return;
}



===== PcQoSPQueryFlowTrafficClass @ 1400109f0 =====

void PcQoSPQueryFlowTrafficClass(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 local_res8 [8];
  
  lVar2 = *param_1;
  uVar3 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  local_res8[0] = 0;
  RtlAcquireReadLock(lVar2 + 0x60,local_res8);
  if (((*(uint *)(lVar2 + 0x30) >> 0xe & 1) == 0) && (*(longlong *)(lVar2 + 0x120) != -1)) {
    iVar1 = *(int *)(lVar2 + 0xb0);
    if (iVar1 == 0) {
      if (*(longlong *)(lVar2 + 0xc0) < 0) {
        uVar3 = (ulonglong)*(byte *)(lVar2 + 0xd9);
        goto LAB_140010a65;
      }
    }
    else if (iVar1 != 1) {
      if ((iVar1 != 2) && (iVar1 != 3)) goto LAB_140010a65;
    }
  }
  uVar3 = (ulonglong)*(byte *)(lVar2 + 0xd8);
LAB_140010a65:
  *(char *)(param_1 + 1) = (char)(uVar3 >> 2);
  LOCK();
  *(int *)(lVar2 + 0x68) = *(int *)(lVar2 + 0x68) + -1;
  UNLOCK();
  KeLowerIrql(local_res8[0]);
  return;
}



===== PcQoSPQueryQuotaHistory @ 140010aa0 =====

undefined8 PcQoSPQueryQuotaHistory(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong local_res8;
  ulonglong local_res10;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *param_1;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(lVar1 + 0x60);
  local_res8 = *(ulonglong *)(lVar1 + 0x180);
  local_res10 = *(ulonglong *)(lVar1 + 0x188);
  uVar2 = KeGetCurrentProcessorNumberEx(0);
  uVar3 = QosTimerGetCurrentTime(uVar2,'\x01','\x01');
  QosUpdateGenerationOverQuota(uVar3,0,&local_res8,&local_res10);
  param_1[1] = local_res8;
  *(undefined4 *)(param_1 + 2) = 600;
  uVar2 = KeGetCurrentProcessorNumberEx(0);
  lVar4 = QosTimerGetCurrentTime(uVar2,'\0','\x01');
  uVar2 = *(uint *)(param_1 + 2);
  uVar3 = lVar4 - *(longlong *)(lVar1 + 0x230);
  *(longlong *)(lVar1 + 0x230) = lVar4;
  uVar5 = uVar3 / ((ulonglong)uVar2 * 1000);
  KeReleaseInStackQueuedSpinLock(&local_28,uVar3 % ((ulonglong)uVar2 * 1000));
  if (0x40 < uVar5) {
    uVar5 = 0x40;
  }
  *(int *)((longlong)param_1 + 0x14) = (int)uVar5;
  return 0;
}



===== PcQoSPQueryStatistics @ 140010ba0 =====

void PcQoSPQueryStatistics(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  
  piVar1 = (int *)param_1[1];
  iVar3 = 0;
  if (*piVar1 == 0) {
    if (piVar1[1] == 0x28) {
      lVar2 = *param_1;
      piVar1[1] = 0x28;
      piVar1[2] = *(int *)(lVar2 + 0x8c);
      piVar1[3] = *(int *)(lVar2 + 0x90);
      piVar1[4] = *(int *)(lVar2 + 0x94);
      *(undefined8 *)(piVar1 + 6) = *(undefined8 *)(lVar2 + 0x98);
      *(undefined8 *)(piVar1 + 8) = *(undefined8 *)(lVar2 + 0xa0);
    }
    else {
      iVar3 = -0x3fffffdd;
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
  PcpNormalizeNtStatus(iVar3);
  return;
}



===== PcQoSPQueryTrafficClass_Deprecated @ 140010c20 =====

void PcQoSPQueryTrafficClass_Deprecated(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x2c);
  (*pcVar1)();
  return;
}



===== PcQoSPUpdateFlow @ 140010c30 =====

void PcQoSPUpdateFlow(undefined8 *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ushort local_res8 [4];
  ushort local_res10 [4];
  undefined4 local_res18 [4];
  
  puVar1 = (undefined8 *)param_1[3];
  local_res10[0] = 0;
  local_res8[0] = 0;
  uVar2 = (int)((ulonglong *)*param_1)[8] + 0x50;
  if (uVar2 < 0x50) {
    iVar3 = -0x3fffff6b;
  }
  else if ((ulonglong)param_1[1] < (ulonglong)uVar2) {
    iVar3 = -0x3fffffdd;
  }
  else {
    local_res18[0] = 0;
    uVar4 = PcpUpdateFlow(puVar1,0,uVar2,*(uint *)(puVar1 + 6) & 0xff,(ulonglong *)*param_1,
                          *(char *)(param_1 + 2),*(int *)(param_1 + 4),local_res18,local_res10,
                          local_res8);
    iVar3 = (int)uVar4;
    PcpTraceUpdateFlowEvent(puVar1,iVar3,*(uint *)(puVar1 + 6) & 0xff);
  }
  PcpNormalizeNtStatus(iVar3);
  return;
}



===== PcQoSPUpdateFlowPrivate @ 140010d20 =====

void PcQoSPUpdateFlowPrivate(undefined8 *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ushort local_res8 [4];
  ushort local_res10 [4];
  undefined4 local_res18 [4];
  
  puVar1 = (undefined8 *)param_1[2];
  local_res10[0] = 0;
  local_res8[0] = 0;
  uVar2 = (int)((ulonglong *)*param_1)[8] + 0x50;
  if (uVar2 < 0x50) {
    iVar3 = -0x3fffff6b;
  }
  else if ((ulonglong)param_1[1] < (ulonglong)uVar2) {
    iVar3 = -0x3fffffdd;
  }
  else {
    local_res18[0] = 0;
    uVar4 = PcpUpdateFlow(puVar1,0,uVar2,2,(ulonglong *)*param_1,'\0',0,local_res18,local_res10,
                          local_res8);
    iVar3 = (int)uVar4;
    PcpTraceUpdateFlowEvent(puVar1,iVar3,2);
  }
  PcpNormalizeNtStatus(iVar3);
  return;
}



===== PcWfpNotify @ 140010e10 =====

int PcWfpNotify(int param_1,undefined4 *param_2,longlong param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  if (param_1 == 0) {
    uVar2 = Feature_3421136185__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 != 0) {
      iVar1 = PcpReferenceWfpAddFlow(param_2,*(longlong *)(param_3 + 0x30));
      return iVar1;
    }
    lVar3 = PcpReferenceFlow(*(longlong *)(param_3 + 0x30));
    if ((char)lVar3 == '\0') {
      return -0x3fffffaa;
    }
  }
  else if (param_1 == 1) {
    PcpDereferenceFlow(*(longlong **)(param_3 + 0x30),(ulonglong)param_2);
  }
  return 0;
}



===== PcpBeginWfpAdd @ 140010e74 =====

undefined8 PcpBeginWfpAdd(longlong param_1,undefined4 *param_2,undefined8 *param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  *param_3 = 0;
  puVar7 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x66667750);
  if (puVar7 == (undefined8 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_3d8b747fe13d335cadcbf0d03feb93cd_Traceguids);
    }
    uVar8 = 0xc000009a;
  }
  else {
    lVar9 = PcpReferenceFlow(param_1);
    if ((char)lVar9 == '\0') {
      ExFreePoolWithTag(puVar7,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_3d8b747fe13d335cadcbf0d03feb93cd_Traceguids);
      }
      uVar8 = 0xc0000225;
    }
    else {
      uVar2 = *param_2;
      uVar3 = param_2[1];
      uVar4 = param_2[2];
      uVar5 = param_2[3];
      puVar7[4] = param_1;
      *(undefined4 *)(puVar7 + 2) = uVar2;
      *(undefined4 *)((longlong)puVar7 + 0x14) = uVar3;
      *(undefined4 *)(puVar7 + 3) = uVar4;
      *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar5;
      uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_140019540);
      puVar12 = auStack_28;
      puVar11 = &DAT_140019548;
      puVar10 = DAT_140019550;
      if ((undefined8 *)*DAT_140019550 != &DAT_140019548) {
        puVar10 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        uVar6 = (*pcVar1)();
        puVar12 = auStack_20;
      }
      *puVar7 = puVar11;
      puVar7[1] = puVar10;
      *puVar10 = puVar7;
      *(undefined8 *)(puVar12 + -8) = 0x140010fac;
      DAT_140019550 = puVar7;
      KeReleaseSpinLock(&DAT_140019540,uVar6);
      uVar8 = 0;
      *param_3 = puVar7;
    }
  }
  return uVar8;
}



===== PcpEndWfpAdd @ 140010fd4 =====

void PcpEndWfpAdd(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  
  plVar1 = (longlong *)param_1[4];
  KeAcquireSpinLockRaiseToDpc(&DAT_140019540);
  lVar2 = *param_1;
  if ((*(longlong **)(lVar2 + 8) == param_1) &&
     (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 == param_1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(&DAT_140019540);
    uVar5 = 0;
    ExFreePoolWithTag(param_1);
    PcpDereferenceFlow(plVar1,uVar5);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== PcpReferenceWfpAddFlow @ 140011058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PcpReferenceWfpAddFlow(undefined4 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  iVar5 = -0x3fffffaa;
  if (param_1 == (undefined4 *)0x0) {
    iVar5 = -0x3ffffff3;
  }
  else {
    local_28 = *param_1;
    uStack_24 = param_1[1];
    uStack_20 = param_1[2];
    uStack_1c = param_1[3];
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140019540);
    puVar1 = DAT_140019548;
    do {
      puVar4 = puVar1;
      if ((undefined8 **)puVar4 == &DAT_140019548) goto LAB_1400110fb;
      puVar1 = (undefined8 *)*puVar4;
    } while ((puVar4[2] != CONCAT44(uStack_24,local_28)) ||
            (puVar4[3] != CONCAT44(uStack_1c,uStack_20)));
    if (param_2 == puVar4[4]) {
      lVar3 = PcpReferenceFlow(puVar4[4]);
      iVar5 = -0x3fffffaa;
      if ((char)lVar3 != '\0') {
        iVar5 = 0;
      }
    }
    else {
      iVar5 = -0x3ffffff3;
    }
LAB_1400110fb:
    KeReleaseSpinLock(&DAT_140019540,uVar2);
    if (-1 < iVar5) {
      return iVar5;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_3d8b747fe13d335cadcbf0d03feb93cd_Traceguids,iVar5);
  }
  return iVar5;
}



===== PcQueryGuidData @ 140011178 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
PcQueryGuidData(longlong param_1,longlong param_2,uint param_3,uint *param_4,uint param_5)

{
  byte bVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined2 local_res10;
  undefined1 local_res12;
  uint local_18 [4];
  
  uVar3 = uRam0000000140019120;
  local_18[1] = 0;
  local_18[0] = 0;
  local_res10 = 0;
  local_res12 = 0;
  if (param_2 == 0) {
    if (param_3 < 0xff010104) {
      if (param_3 != 0xff010103) {
        if (param_3 < 0xfb01010a) {
          if (param_3 == 0xfb010109) {
            *(undefined8 *)param_4 = _PcgDefaultProfile;
            *(undefined8 *)(param_4 + 2) = uVar3;
            return 0;
          }
          if (param_3 == 0xfb010100) {
            uVar3 = PcpCollectNetworkAddressList(param_1,&param_5,(undefined2 *)param_4);
            return uVar3;
          }
          if (param_3 != 0xfb010101) {
            if (param_3 == 0xfb010103) {
              *param_4 = 0xffffffff;
              return 0;
            }
            if (param_3 == 0xfb010104) {
              *param_4 = 0xffffffff;
              return 0;
            }
            if (param_3 == 0xfb010106) {
              NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x10),&local_res10,0);
              *param_4 = *(uint *)(param_1 + 0x30);
              goto LAB_14001130f;
            }
            if (param_3 != 0xfb010107) {
              return 0xc00002dd;
            }
          }
          NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x10),&local_res10,0);
          uVar2 = *(ulonglong *)(param_1 + 0x20);
          NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res10);
          uVar4 = (uint)uVar2;
          if (0xffffffff < uVar2) {
            uVar4 = 0xffffffff;
          }
          *param_4 = uVar4;
          return 0;
        }
        if (param_3 != 0xfb01010a) {
          if (param_3 == 0xfb01010b) {
            NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x10),&local_res10,0);
            *param_4 = 1;
            param_4[1] = 0x1c;
            uVar3 = *(undefined8 *)(param_1 + 0x58);
            *(undefined8 *)(param_4 + 2) = *(undefined8 *)(param_1 + 0x50);
            *(undefined8 *)(param_4 + 4) = uVar3;
            *(undefined8 *)(param_4 + 6) = *(undefined8 *)(param_1 + 0x60);
            param_4[8] = *(uint *)(param_1 + 0x68);
            param_4[9] = 3;
            param_4[10] = 4;
            param_4[0xb] = *(uint *)(param_1 + 0x6c);
            param_4[0xc] = 4;
            param_4[0xd] = 8;
            *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_1 + 0x70);
            param_4[0x10] = 5;
            param_4[0x11] = 0x14;
            param_4[0x12] = 0;
            param_4[0x13] = 0;
            param_4[0x14] = 0;
            param_4[0x15] = 0;
            param_4[0x16] = 0;
LAB_14001130f:
            NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res10);
            return 0;
          }
          if (param_3 != 0xfb01010d) {
            if (param_3 == 0xfb010112) {
              uVar4 = PcgEnableAvgStats;
            }
            else {
              if (param_3 != 0xfb010113) {
                return 0xc00002dd;
              }
              uVar4 = PcgEnableWindowAdjustment;
            }
            goto LAB_1400111fd;
          }
        }
      }
    }
    else if (param_3 != 0xff010104) {
      return 0xc00002dd;
    }
LAB_14001143d:
    *param_4 = 0;
    return 0;
  }
  if (param_3 == 0xfb010102) goto LAB_14001143d;
  if (param_3 == 0xfb010105) {
    bVar1 = *(byte *)(param_2 + 0xd8);
  }
  else {
    if (param_3 == 0xfb01010b) {
      uVar3 = PcpQueryFlowStats(param_2,(longlong)param_4,param_5,local_18 + 1,local_18);
      return uVar3;
    }
    if (param_3 != 0xfb01010f) {
      if (param_3 == 0xfb010110) {
        uVar4 = (uint)*(byte *)(param_2 + 0xda);
      }
      else {
        if (param_3 != 0xfb010111) {
          return 0xc00002dd;
        }
        uVar4 = (uint)*(byte *)(param_2 + 0xdb);
      }
      goto LAB_1400111fd;
    }
    bVar1 = *(byte *)(param_2 + 0xd9);
  }
  uVar4 = (uint)(bVar1 >> 2);
LAB_1400111fd:
  *param_4 = uVar4;
  return 0;
}



===== PcQuerySetMiniport @ 140011460 =====

uint PcQuerySetMiniport(longlong param_1,longlong param_2,uint param_3,int *param_4,int param_5)

{
  bool bVar1;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  local_res18 = 0;
  local_res1a = 0;
  if (param_3 < 0xfb010109) {
    if (param_3 == 0xfb010108) {
      return 0xc00002dd;
    }
    if (param_3 == 0xfb010100) {
      return 0xc00002dd;
    }
    if (param_3 == 0xfb010101) {
      return 0xc00002dd;
    }
    if (param_3 == 0xfb010104) {
      return 0xc00002dd;
    }
    if (param_3 == 0xfb010106) {
      return 0xc00002dd;
    }
    bVar1 = param_3 == 0xfb010107;
  }
  else {
    if (param_3 == 0xfb010109) {
      return 0xc00002dd;
    }
    if (param_3 == 0xfb01010a) {
      return 0xc00002dd;
    }
    if (param_3 == 0xff010103) {
      return 0xc00002dd;
    }
    bVar1 = param_3 == 0xff010104;
  }
  if (!bVar1) {
    if (param_2 == 0) {
      if (param_3 != 0xfb010103) {
        if (param_3 == 0xfb01010b) {
          NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x10),&local_res18,0);
          *(undefined8 *)(param_1 + 0x50) = 0;
          *(undefined8 *)(param_1 + 0x58) = 0;
          *(undefined8 *)(param_1 + 0x60) = 0;
          *(undefined8 *)(param_1 + 0x68) = 0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res18);
          return 0;
        }
        if (param_3 == 0xfb01010d) {
          if (param_5 == 4) {
            if (*param_4 == 1) {
              return 0;
            }
            return -(uint)(*param_4 != 2) & 0xc000000d;
          }
        }
        else if (param_3 == 0xfb010112) {
          if (param_5 == 4) {
            PcgEnableAvgStats = *param_4;
            return 0;
          }
        }
        else {
          if (param_3 != 0xfb010113) {
            return 0xc00002dd;
          }
          if (param_5 == 4) {
            PcgEnableWindowAdjustment = *param_4;
            return 0;
          }
        }
        return 0xc0000023;
      }
      if (param_5 != 4) {
        return 0xc0000023;
      }
    }
    else if (param_3 == 0xfb01010b) {
      *(undefined8 *)(param_2 + 0x8c) = 0;
      *(undefined8 *)(param_2 + 0x94) = 0;
      *(undefined8 *)(param_2 + 0x9c) = 0;
      *(undefined4 *)(param_2 + 0xa4) = 0;
      *(undefined4 *)(param_2 + 0x134) = 0;
      *(undefined8 *)(param_2 + 0x138) = 0;
      return 0;
    }
  }
  return 0xc00002dd;
}



===== PcWmiQueryAllData @ 140011614 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PcWmiQueryAllData(longlong *param_1,uint *param_2,uint param_3,uint *param_4)

{
  longlong lVar1;
  bool bVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 local_64;
  undefined1 local_62;
  uint local_60;
  uint local_5c;
  undefined8 *local_58;
  longlong local_50;
  undefined2 *local_48;
  longlong local_40;
  
  local_50 = 0;
  local_60 = 0;
  bVar2 = false;
  uVar8 = 0;
  local_64 = 0;
  local_62 = 0;
  *param_4 = 0;
  if (param_3 < 0x38) {
    uVar6 = 0xc0000023;
  }
  else {
    uVar7 = 0;
    NdisAcquireRWLockRead(PcgLineListLock,&local_64);
    for (puVar3 = PcgLineList; (undefined8 **)puVar3 != &PcgLineList; puVar3 = (undefined8 *)*puVar3
        ) {
      uVar7 = uVar7 + 1;
    }
    NdisReleaseRWLock(PcgLineListLock,&local_64);
    uVar4 = PcpWmiGetGuid(&local_50,param_1,0);
    uVar6 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      uVar10 = uVar7 * 8 + 0x48;
      *(undefined8 *)(param_2 + 4) = _DAT_fffff78000000014;
      local_40 = (ulonglong)uVar10 + (longlong)param_2;
      param_2[0xe] = uVar10;
      uVar9 = uVar7 * 0xc + 0x4f & 0xfffffff8;
      local_48 = (undefined2 *)((ulonglong)uVar9 + (longlong)param_2);
      NdisAcquireRWLockRead(PcgLineListLock,&local_64);
      puVar3 = PcgLineList;
      uVar10 = uVar9;
      while ((undefined8 **)puVar3 != &PcgLineList) {
        LOCK();
        *(int *)(puVar3 + 0x1f) = *(int *)(puVar3 + 0x1f) + 1;
        UNLOCK();
        local_58 = puVar3;
        NdisReleaseRWLock(PcgLineListLock,&local_64);
        NdisAcquireRWLockRead(puVar3[2],&local_64,0);
        if ((*(int *)((longlong)puVar3 + 0xf4) == 2) &&
           (((lVar1 = puVar3[0x20], lVar1 == 0 || (*(int *)(lVar1 + 0x10) != 3)) ||
            (*(undefined8 **)(lVar1 + 0xa0) != puVar3)))) {
          NdisReleaseRWLock(puVar3[2]);
          uVar4 = PcQueryGuidDataSize((longlong)puVar3,0,*(uint *)(local_50 + 0x10),&local_60);
          uVar6 = uVar4 & 0xffffffff;
          if (-1 < (int)uVar4) {
            if (uVar7 <= uVar8) {
LAB_140011923:
              NdisAcquireRWLockRead(PcgLineListLock,&local_64,0);
              PcpLineDereference((longlong)puVar3);
              break;
            }
            NdisAcquireRWLockRead(puVar3[2],&local_64);
            local_5c = local_60 + 7 & 0xfffffff8;
            uVar5 = *(ushort *)(puVar3 + 0x21) + 9 & 0xfffffff8;
            uVar10 = uVar10 + local_5c + uVar5;
            if (param_3 < uVar10) {
              NdisReleaseRWLock(puVar3[2],&local_64);
              param_2[0xb] = param_2[0xb] | 0x20;
              *param_2 = 0x38;
              uVar6 = 0;
              param_2[0xc] = uVar10;
              *param_4 = 0x38;
              bVar2 = true;
            }
            else {
              *(uint *)(local_40 + (ulonglong)uVar8 * 4) = uVar9;
              *local_48 = *(undefined2 *)(puVar3 + 0x21);
              memmove(local_48 + 1,(void *)puVar3[0x22],(ulonglong)*(ushort *)(puVar3 + 0x21));
              NdisReleaseRWLock(puVar3[2]);
              uVar9 = uVar9 + uVar5;
              uVar4 = PcQueryGuidData((longlong)puVar3,0,*(uint *)(local_50 + 0x10),
                                      (uint *)((ulonglong)uVar9 + (longlong)param_2),local_60);
              uVar6 = uVar4 & 0xffffffff;
              if ((int)uVar4 < 0) goto LAB_140011923;
              param_2[(ulonglong)uVar8 * 2 + 0x10] = local_60;
              param_2[(ulonglong)uVar8 * 2 + 0xf] = uVar9;
              uVar9 = uVar9 + local_5c;
              local_48 = (undefined2 *)((ulonglong)uVar9 + (longlong)param_2);
              uVar8 = uVar8 + 1;
            }
          }
        }
        else {
          NdisReleaseRWLock(puVar3[2],&local_64);
        }
        NdisAcquireRWLockRead(PcgLineListLock,&local_64);
        puVar3 = (undefined8 *)*puVar3;
        PcpLineDereference((longlong)local_58);
      }
      NdisReleaseRWLock(PcgLineListLock,&local_64);
      if (!bVar2) {
        uVar6 = 0;
        *param_2 = uVar10;
        param_2[0xd] = uVar8;
        *param_4 = uVar10;
      }
    }
  }
  return uVar6;
}



===== PcpFindFlowInstanceByName @ 14001198c =====

longlong * PcpFindFlowInstanceByName(undefined8 param_1,undefined2 param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_44 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = param_2;
  local_46 = param_2;
  local_40 = param_1;
  RtlAcquireWriteLock(0x1400197f0);
  plVar4 = PcgFlowList;
  while (((longlong **)plVar4 != &PcgFlowList &&
         (lVar2 = PcpReferenceFlow((longlong)plVar4), (char)lVar2 == '\0'))) {
    plVar4 = (longlong *)*plVar4;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  do {
    if ((longlong **)plVar4 == &PcgFlowList) {
      return (longlong *)0x0;
    }
    RtlInitUnicodeString(&local_38,(longlong)plVar4 + 0x34);
    cVar1 = RtlEqualUnicodeString(&local_38,&local_48,1);
    if (cVar1 == '\x01') {
      return plVar4;
    }
    puVar3 = &local_28;
    RtlAcquireWriteLock(0x1400197f0);
    plVar5 = plVar4;
    do {
      plVar5 = (longlong *)*plVar5;
      if ((longlong **)plVar5 == &PcgFlowList) break;
      lVar2 = PcpReferenceFlow((longlong)plVar5);
    } while ((char)lVar2 == '\0');
    KeReleaseInStackQueuedSpinLock(&local_28);
    PcpDereferenceFlow(plVar4,(ulonglong)puVar3);
    plVar4 = plVar5;
  } while( true );
}



===== PcpWmiDispatch @ 140011ab0 =====

uint PcpWmiDispatch(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  uint *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined2 local_res8;
  undefined1 local_resa;
  uint local_res10 [2];
  longlong local_res18;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_res10[0] = 0;
  plVar3 = *(longlong **)(lVar2 + 0x10);
  uVar6 = *(uint *)(lVar2 + 0x18);
  puVar4 = *(uint **)(lVar2 + 0x20);
  if (*(longlong *)(lVar2 + 8) != param_1) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    return 0xc0000010;
  }
  cVar1 = *(char *)(lVar2 + 1);
  if (cVar1 == '\0') {
    uVar8 = PcWmiQueryAllData(plVar3,puVar4,uVar6,local_res10);
    uVar6 = (uint)uVar8;
    goto LAB_140011c12;
  }
  if (cVar1 == '\x01') {
    local_res18 = 0;
    uVar7 = PcpWmiGetGuid(&local_res18,(longlong *)(puVar4 + 6),0);
    if (-1 < (int)uVar7) {
      iVar9 = 1;
LAB_140011bc5:
      uVar6 = PcWmiHandleSingleInstance(iVar9,puVar4,local_res18,uVar6,local_res10);
      goto LAB_140011c12;
    }
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        if (cVar1 == '\x04') {
          uVar7 = PcpWmiEnableEvents(plVar3);
          uVar6 = (uint)uVar7;
          goto LAB_140011c12;
        }
        if (cVar1 == '\x05') {
          uVar7 = PcpWmiDisableEvents(plVar3);
          uVar6 = (uint)uVar7;
          goto LAB_140011c12;
        }
        if ((cVar1 != '\x06') && (cVar1 != '\a')) {
          if (cVar1 == '\b') {
            uVar7 = PcpWmiRegister((longlong)plVar3,puVar4,uVar6,local_res10);
            uVar6 = (uint)uVar7;
            goto LAB_140011c12;
          }
LAB_140011bb9:
          uVar6 = 0xc0000010;
          goto LAB_140011c12;
        }
      }
      uVar6 = 0xc00000bb;
      goto LAB_140011c12;
    }
    local_res18 = 0;
    uVar7 = PcpWmiGetGuid(&local_res18,(longlong *)(puVar4 + 6),0);
    if (-1 < (int)uVar7) {
      if ((*(uint *)(local_res18 + 0x18) & 0x40) != 0) {
        uVar6 = 0xc00002dd;
        goto LAB_140011c12;
      }
      if (puVar4[0xf] != 0) {
        if ((*(uint *)(local_res18 + 0x18) & 1) == 0) goto LAB_140011bb9;
        iVar9 = 2;
        goto LAB_140011bc5;
      }
    }
  }
  uVar6 = 0xc000000d;
LAB_140011c12:
  *(uint *)(param_2 + 0x30) = uVar6;
  uVar10 = 0;
  if (-1 < (int)uVar6) {
    uVar10 = local_res10[0];
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar10;
  IofCompleteRequest(param_2,0);
  if (cVar1 == '\b') {
    local_res8 = 0;
    local_resa = 0;
    NdisAcquireRWLockRead(PcgLineListLock,&local_res8,0);
    puVar11 = PcgLineList;
    while ((undefined8 **)puVar11 != &PcgLineList) {
      LOCK();
      *(int *)(puVar11 + 0x1f) = *(int *)(puVar11 + 0x1f) + 1;
      UNLOCK();
      NdisReleaseRWLock(PcgLineListLock,&local_res8);
      NdisAcquireRWLockRead(puVar11[2],&local_res8,0);
      if (*(int *)((longlong)puVar11 + 0xf4) == 2) {
        NdisReleaseRWLock();
        PcpTcIndicateInterfaceChange((longlong)puVar11,0x4001000f);
      }
      else {
        NdisReleaseRWLock(puVar11[2],&local_res8);
      }
      NdisAcquireRWLockRead(PcgLineListLock,&local_res8);
      puVar5 = (undefined8 *)*puVar11;
      PcpLineDereference((longlong)puVar11);
      puVar11 = puVar5;
    }
    NdisReleaseRWLock(PcgLineListLock);
  }
  return uVar6;
}



===== PcpLineAllocId @ 140011d40 =====

undefined4 PcpLineAllocId(longlong param_1)

{
  size_t _Size;
  void *_Dst;
  uint uVar1;
  ushort uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  uVar4 = 0;
  DAT_140019668 = KeAcquireSpinLockRaiseToDpc(&PcgLineTableLock);
  uVar2 = PcgLineTableNextId;
  for (uVar5 = 1; uVar1 = (uint)PcgLineTableLen, uVar5 < PcgLineTableLen; uVar5 = uVar5 + 1) {
    if (*(longlong *)((longlong)PcgLineTable + (ulonglong)uVar2 * 8) == 0) {
      *(longlong *)((longlong)PcgLineTable + (ulonglong)uVar2 * 8) = param_1;
      *(ushort *)(param_1 + 0xf0) = uVar2;
      PcgLineTableNextId =
           (short)((longlong)(ulonglong)(uVar2 + 1) % (longlong)(int)(uVar1 - 1)) + 1;
      goto LAB_140011ecf;
    }
    uVar2 = (short)((longlong)(ulonglong)(uVar2 + 1) % (longlong)(int)(uVar1 - 1)) + 1;
  }
  if (PcgLineTableLen == 0) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = PcgLineTableLen * 2;
    if (uVar2 < PcgLineTableLen) {
      uVar4 = 0xc0000095;
      goto LAB_140011ecf;
    }
  }
  _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)uVar2 << 3,0x746c6350);
  if (_Dst == (void *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    uVar3 = (ulonglong)PcgLineTableLen;
    if (PcgLineTableLen == 0) {
      memset(_Dst,0,(ulonglong)uVar2 << 3);
      uVar3 = 1;
    }
    else {
      _Size = uVar3 * 8;
      memmove(_Dst,PcgLineTable,_Size);
      memset((void *)(_Size + (longlong)_Dst),0,_Size);
    }
    *(longlong *)((longlong)_Dst + uVar3 * 8) = param_1;
    *(short *)(param_1 + 0xf0) = (short)uVar3;
    PcgLineTableNextId = (short)(((int)uVar3 + 1) % (int)(uVar2 - 1)) + 1;
    if (PcgLineTable != (void *)0x0) {
      ExFreePoolWithTag(PcgLineTable,0x746c6350);
    }
    PcgLineTable = _Dst;
    PcgLineTableLen = uVar2;
  }
LAB_140011ecf:
  KeReleaseSpinLock(&PcgLineTableLock,DAT_140019668);
  return uVar4;
}



===== PcpLineDropNblChain @ 140011f10 =====

void PcpLineDropNblChain(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  lVar2 = param_2[0x15];
  puVar1 = param_2;
  for (puVar3 = (undefined8 *)*param_2; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)*puVar3)
  {
    if (puVar3[0x15] != lVar2) {
      *puVar1 = 0;
      PcpSchedulerCompletePacket(lVar2,param_1,(longlong)param_2,0);
      lVar2 = puVar3[0x15];
      param_2 = puVar3;
    }
    puVar1 = puVar3;
  }
  PcpSchedulerCompletePacket(lVar2,param_1,(longlong)param_2,0);
  return;
}



===== PcpLineFindByLuid @ 140011f8c =====

undefined8 * PcpLineFindByLuid(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockRead(PcgLineListLock,&local_res10,0);
  puVar2 = PcgLineList;
  while( true ) {
    if ((undefined8 **)puVar2 == &PcgLineList) {
      NdisReleaseRWLock(PcgLineListLock,&local_res10);
      return (undefined8 *)0x0;
    }
    LOCK();
    *(int *)(puVar2 + 0x1f) = *(int *)(puVar2 + 0x1f) + 1;
    UNLOCK();
    NdisReleaseRWLock(PcgLineListLock);
    NdisAcquireRWLockRead(puVar2[2],&local_res10,0);
    if ((*(int *)((longlong)puVar2 + 0xf4) == 2) && (puVar2[3] == param_1)) break;
    NdisReleaseRWLock(puVar2[2],&local_res10);
    NdisAcquireRWLockRead(PcgLineListLock,&local_res10);
    puVar1 = (undefined8 *)*puVar2;
    PcpLineDereference((longlong)puVar2);
    puVar2 = puVar1;
  }
  NdisReleaseRWLock(puVar2[2],&local_res10);
  return puVar2;
}



===== PcpLineFreeId @ 1400120ac =====

void PcpLineFreeId(longlong param_1)

{
  ushort uVar1;
  
  DAT_140019668 = KeAcquireSpinLockRaiseToDpc(&PcgLineTableLock);
  uVar1 = *(ushort *)(param_1 + 0xf0);
  *(undefined8 *)(PcgLineTable + (ulonglong)uVar1 * 8) = 0;
  KeReleaseSpinLock(&PcgLineTableLock,CONCAT11((char)(uVar1 >> 8),DAT_140019668));
  return;
}



===== PcpTraceLineBufferSample @ 140012110 =====

void PcpTraceLineBufferSample(longlong param_1)

{
  PcpEtwWriteEventUlongPtr
            (&QOS_EVENT_PACER_LINE_BUFFER_SAMPLE,0,0,10,*(longlong *)(param_1 + 0x30) + 0x110);
  return;
}



===== PcpTraceLineControlInterval @ 140012220 =====

void PcpTraceLineControlInterval(longlong param_1)

{
  PcpEtwWriteEventUlongPtr
            (&QOS_EVENT_PACER_LINE_CONTROL_INTERVAL,0,0,5,*(longlong *)(param_1 + 8) + 0x110);
  return;
}



===== PcpNormalizeNtStatus @ 14001229c =====

int PcpNormalizeNtStatus(int param_1)

{
  if (param_1 < -0x3ffdff79) {
    if (((param_1 != -0x3ffdff7a) && (param_1 != -0x3ffdff80)) &&
       (((param_1 != -0x3ffdff7f &&
         (((param_1 != -0x3ffdff7e && (param_1 != -0x3ffdff7d)) && (param_1 != -0x3ffdff7c)))) &&
        (param_1 != -0x3ffdff7b)))) {
      return param_1;
    }
  }
  else if ((((param_1 != -0x3ffdff79) && (param_1 != -0x3ffdff78)) && (param_1 != -0x3ffdff77)) &&
          (((param_1 != -0x3ffdff70 && (param_1 != -0x3ffdff6f)) && (param_1 != -0x3ffdff6e)))) {
    return param_1;
  }
  return -0x3ffffff3;
}



===== WPP_SF_Zd @ 140012318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zd(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_140012340;
    }
  }
  pwVar2 = L"NULL";
LAB_140012340:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e1442377b4dc3ef8da9019e657b54aa7_Traceguids,10,param_4,2,pwVar2,wVar1
             ,&param_5,4,0);
  return;
}



===== PcpEtwCallback @ 1400123b0 =====

void PcpEtwCallback(undefined8 param_1,undefined4 param_2)

{
  LOCK();
  PcgEventTraceEnabled = param_2;
  UNLOCK();
  return;
}



===== PcpEtwTransferFlowActivity @ 1400123c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcpEtwTransferFlowActivity(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_20 = 0;
  uStack_30 = 0x7de6b5e058b5a6a8;
  local_38 = param_2;
  local_28 = param_1;
  PcpEtwTransferActivityIdGuid();
  return;
}



===== PcpEtwWriteEvent @ 140012418 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcpEtwWriteEvent(undefined8 param_1,undefined8 param_2,longlong param_3,ushort param_4,
                     undefined8 *param_5)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 auStack_f8 [32];
  undefined8 *local_d8;
  undefined8 *local_d0;
  undefined8 local_c8 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  uVar1 = (ulonglong)param_4;
  if (param_4 < 9) {
    puVar2 = local_c8;
    puVar3 = (undefined8 *)0x0;
  }
  else {
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,uVar1 << 4,0x77746550);
    puVar3 = puVar2;
    if (puVar2 == (undefined8 *)0x0) {
      return;
    }
  }
  uVar4 = 0;
  if (param_4 != 0) {
    uVar5 = uVar1;
    puVar6 = puVar2;
    do {
      *puVar6 = *param_5;
      *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(param_5 + 1);
      uVar5 = uVar5 - 1;
      uVar4 = uVar1;
      puVar6 = puVar6 + 2;
      param_5 = param_5 + 2;
    } while (uVar5 != 0);
  }
  if (param_3 == 0) {
    local_d8 = puVar2;
    EtwWrite(PcgEventTraceHandle,param_1,param_2,uVar4);
  }
  else {
    local_d8 = (undefined8 *)CONCAT44(local_d8._4_4_,(int)uVar4);
    local_d0 = puVar2;
    EtwWriteTransfer(PcgEventTraceHandle,param_1,param_2,param_3);
  }
  if (puVar3 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar3,0);
  }
  return;
}



===== PcpEtwWriteEventUlongPtr @ 140012544 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcpEtwWriteEventUlongPtr
               (undefined8 param_1,longlong param_2,longlong param_3,ushort param_4,
               undefined8 param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined1 auStackY_68 [32];
  longlong local_30 [6];
  
  local_30[4] = __security_cookie ^ (ulonglong)auStackY_68;
  plVar2 = (longlong *)0x0;
  plVar1 = (longlong *)0x0;
  local_30[0] = 0;
  local_30[2] = 0;
  if (param_2 != 0) {
    plVar1 = local_30;
    local_30[0] = param_2;
  }
  local_30[1] = 0;
  if (param_3 != 0) {
    plVar2 = local_30 + 2;
    local_30[2] = param_3;
  }
  local_30[3] = 0;
  PcpEtwWriteEvent(param_1,plVar1,(longlong)plVar2,param_4,&param_5);
  return;
}



===== PcpEtwWriteFlowEvent @ 1400125c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PcpEtwWriteFlowEvent(undefined8 param_1,undefined8 param_2,ushort param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  uStack_20 = 0x7de6b5e058b5a6a8;
  local_res20 = param_4;
  local_28 = param_2;
  PcpEtwWriteEvent(param_1,&local_28,0,param_3,&local_res20);
  return;
}



===== PcpStartDelayModule @ 140012630 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PcpStartDelayModule(void)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = KeQueryMaximumProcessorCountEx(0xffff);
  PcgDelayQueue = (void *)ExAllocatePool2(0x40,(ulonglong)uVar1 << 6,0x65676350);
  uVar2 = 0;
  if (PcgDelayQueue == (void *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    memset(PcgDelayQueue,0,(ulonglong)uVar1 << 6);
    _PcgInitializedModules = _PcgInitializedModules | 0x80;
  }
  return uVar2;
}



===== PcpStopDelayModule @ 1400126b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopDelayModule(void)

{
  _PcgInitializedModules = _PcgInitializedModules & 0xfffffffffffffffd;
  ExFreePoolWithTag(PcgDelayQueue,0x65676350);
  return;
}



===== PcpHandleDot11DSCPToUPMappingIndication @ 1400126e0 =====

void PcpHandleDot11DSCPToUPMappingIndication(undefined8 *param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined2 uVar2;
  
  PcpInitializeDSCPToUPMappings(param_1);
  if (*(char *)(param_2 + 4) == '\0') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0) {
      return;
    }
    uVar2 = 0xb;
  }
  else {
    if (*(byte *)(param_2 + 0x15) < 0x16) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_d142f05ff1783a702b1695b6c61349f7_Traceguids);
      }
      *(undefined1 *)param_1 = 1;
      *(undefined1 *)((longlong)param_1 + 0x11) = *(undefined1 *)(param_2 + 0x15);
      uVar1 = *(undefined8 *)(param_2 + 0xd);
      *(undefined8 *)((longlong)param_1 + 1) = *(undefined8 *)(param_2 + 5);
      *(undefined8 *)((longlong)param_1 + 9) = uVar1;
      memmove((void *)((longlong)param_1 + 0x12),(void *)(param_2 + 0x16),
              (ulonglong)*(byte *)(param_2 + 0x15) * 2);
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0) {
      return;
    }
    uVar2 = 0xc;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
          &WPP_d142f05ff1783a702b1695b6c61349f7_Traceguids);
  return;
}



===== QosFlowProcessQueuedNetBufferLists @ 1400127e4 =====

bool QosFlowProcessQueuedNetBufferLists(longlong param_1,uint param_2)

{
  bool bVar1;
  longlong lVar2;
  
  bVar1 = QosTbcProcessQueuedNetBufferLists(param_1,param_2);
  if (!bVar1) {
    lVar2 = QosTimerGetCurrentTime(param_2,'\0','\x01');
    *(longlong *)(param_1 + 0x108) = lVar2;
  }
  return bVar1;
}



===== QosFlowQueryStats @ 140012848 =====

uint QosFlowQueryStats(longlong param_1,longlong param_2,int param_3,uint *param_4,uint *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_2 == 0) {
    *param_4 = *param_4 + 0x40;
    uVar2 = 0;
  }
  else {
    uVar2 = *param_5;
    uVar5 = (ulonglong)uVar2;
    if (0x1b < param_3 - uVar2) {
      puVar3 = (undefined4 *)(param_2 + uVar5);
      *puVar3 = 3;
      uVar5 = (ulonglong)(uVar2 + 0x1c);
      puVar3[1] = 4;
      puVar3[2] = *(undefined4 *)(param_1 + 0xac);
      puVar3[3] = 4;
      puVar3[4] = 8;
      *(undefined8 *)(puVar3 + 5) = *(undefined8 *)(param_1 + 0xb0);
      *param_5 = uVar2 + 0x1c;
    }
    uVar2 = *param_4;
    uVar4 = (uint)uVar5;
    if (0x23 < param_3 - uVar4) {
      puVar3 = (undefined4 *)(uVar5 + param_2);
      uVar4 = uVar4 + 0x24;
      *param_5 = uVar4;
      *puVar3 = 2;
      puVar3[1] = 0x1c;
      uVar1 = *(undefined8 *)(param_1 + 0xc);
      *(undefined8 *)(puVar3 + 2) = *(undefined8 *)(param_1 + 4);
      *(undefined8 *)(puVar3 + 4) = uVar1;
      *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(param_1 + 0x14);
      puVar3[8] = *(undefined4 *)(param_1 + 0x1c);
    }
    *param_4 = uVar2 + 0x40;
    uVar2 = -(uint)(uVar2 + 0x40 != uVar4) & 0xc0010016;
  }
  return uVar2;
}



===== QosLineQueryQueueFeedback @ 140012918 =====

void QosLineQueryQueueFeedback(longlong param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
  *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + *param_3;
  uVar1 = *(uint *)(param_1 + 0x70);
  if (*(uint *)(param_1 + 0x70) <= *param_3) {
    uVar1 = *param_3;
  }
  *(uint *)(param_1 + 0x70) = uVar1;
  param_3[2] = *(uint *)(param_1 + 0x78);
  param_3[3] = *(uint *)(param_1 + 0x6c);
  *(undefined8 *)(param_3 + 6) = *(undefined8 *)(param_1 + 0xb0);
  param_3[5] = *(uint *)(param_1 + 0x74);
  *(undefined8 *)(param_3 + 8) = *(undefined8 *)(param_1 + 0xc0);
  param_3[4] = *(uint *)(param_1 + 0x70);
  return;
}



===== QosTraceEvent @ 140012970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosTraceEvent(int param_1,undefined8 param_2)

{
  (**(code **)(QosgEtwDispatchTable + 8 + (longlong)param_1 * 8))(param_2);
  return;
}



===== QosTimerInitialize @ 140012998 =====

undefined8 QosTimerInitialize(void)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = 0;
  if ((DAT_1400198c8 == 0) || (PcgTimerTable == 0)) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar3 = 0;
    QosgTimerTable = &PcgTimerTable;
    if (DAT_1400198c8 != 0) {
      do {
        memset((void *)(uVar3 * 0x80 + *QosgTimerTable),0,0x80);
        QosTimerGetCurrentTime((uint)uVar3,'\x01','\x01');
        uVar2 = (uint)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < DAT_1400198c8);
    }
  }
  return uVar1;
}



===== QosNblCadComplete @ 140012a1c =====

void QosNblCadComplete(longlong param_1,undefined8 *param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  *param_2 = 0;
  lVar4 = *(longlong *)((ulonglong)*(ushort *)(lVar3 + 10) + 0x20 + lVar3);
  *(undefined1 *)((ulonglong)*(ushort *)(lVar3 + 10) + 0x3c + lVar3) = 1;
  LOCK();
  piVar1 = (int *)(lVar4 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    QosNblCadReassemble(lVar4,param_3);
    uVar5 = QosgNblCadLookasideList;
    *param_2 = *(undefined8 *)(lVar4 + 0x18);
    ExFreeToNPagedLookasideList(uVar5,lVar4);
  }
  return;
}



===== QosNblCadDisassemble @ 140012a88 =====

undefined8
QosNblCadDisassemble
          (longlong param_1,undefined8 *param_2,uint param_3,int param_4,undefined8 param_5,
          longlong *param_6,char param_7)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  uint uVar16;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  longlong *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  uVar2 = QosgNblCadLookasideList;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  *param_6 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  uVar13 = 0;
  puVar10 = param_2;
  puVar5 = (undefined8 *)ExAllocateFromNPagedLookasideList(uVar2);
  if (puVar5 == (undefined8 *)0x0) {
LAB_140012c11:
    while( true ) {
      uVar13 = 0xc000009a;
      if ((undefined8 *)*param_6 == (undefined8 *)0x0) break;
      puVar5 = QosNblChainRemove(param_6,puVar10,(undefined8 *)*param_6);
      NdisFreeNetBufferList(puVar5);
    }
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    KeInitializeSpinLock(puVar5 + 2);
    puVar10 = puVar5 + 4;
    iVar9 = 0;
    puVar5[5] = puVar10;
    *puVar10 = puVar10;
    puVar5[3] = param_1;
    iVar3 = QosGetNetBufferCount(param_1,(int *)0x0);
    puVar12 = auStack_78;
    uVar16 = iVar9 + 1;
    if ((iVar3 - param_3 != 0) && (uVar16 = param_4 + 1, param_4 == -1)) {
      uVar16 = (iVar3 - param_3) + 1;
    }
    for (uVar4 = 0; uVar4 < uVar16; uVar4 = uVar4 + 1) {
      plVar6 = (longlong *)NdisAllocateNetBufferList(param_2[5],0x70);
      local_58 = plVar6;
      if (plVar6 == (longlong *)0x0) {
        ExFreeToNPagedLookasideList(QosgNblCadLookasideList);
        puVar10 = puVar5;
        goto LAB_140012c11;
      }
      NdisCopySendNetBufferListInfo(plVar6);
      plVar6[0xf] = param_2[4];
      lVar11 = (ulonglong)*(ushort *)(plVar6[2] + 10) + plVar6[2];
      memset((void *)(lVar11 + 0x10),0,0x70);
      plVar6 = (longlong *)param_6[1];
      *(undefined4 *)(lVar11 + 0x38) = 0;
      *(undefined8 **)(lVar11 + 0x30) = param_2;
      *(longlong **)(lVar11 + 0x28) = local_58;
      *(undefined8 **)(lVar11 + 0x20) = puVar5;
      QosNblChainInsert(param_6,plVar6,local_58);
    }
    plVar6 = (longlong *)*param_6;
    puVar14 = (undefined8 *)0x0;
    plVar6[1] = *(longlong *)(param_1 + 8);
    *(undefined8 *)(param_1 + 8) = 0;
    puVar8 = (undefined8 *)plVar6[1];
    if (param_3 != 0) {
      uVar7 = (ulonglong)param_3;
      do {
        puVar14 = puVar8;
        puVar8 = (undefined8 *)*puVar14;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *puVar14 = 0;
    puVar14 = (undefined8 *)*plVar6;
    if (puVar14 == (undefined8 *)0x0) {
      *(undefined8 **)(param_1 + 8) = puVar8;
    }
    else if (param_4 == 1) {
      puVar14[1] = puVar8;
    }
    else {
      while (puVar8 != (undefined8 *)0x0) {
        puVar15 = (undefined8 *)*puVar8;
        puVar14[1] = puVar8;
        *puVar8 = 0;
        puVar14 = (undefined8 *)*puVar14;
        puVar8 = puVar15;
      }
    }
    LOCK();
    *(int *)(puVar5 + 6) = *(int *)(puVar5 + 6) + (int)param_6[2];
    UNLOCK();
    if (param_7 == '\0') {
      KeAcquireInStackQueuedSpinLock(puVar5 + 2,&local_50);
    }
    else {
      KeAcquireInStackQueuedSpinLockAtDpcLevel();
    }
    for (puVar8 = (undefined8 *)*param_6; puVar8 != (undefined8 *)0x0;
        puVar8 = (undefined8 *)*puVar8) {
      puVar14 = (undefined8 *)puVar5[5];
      puVar15 = (undefined8 *)((ulonglong)*(ushort *)(puVar8[2] + 10) + 0x10 + puVar8[2]);
      if ((undefined8 *)*puVar14 != puVar10) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(3);
        puVar12 = auStack_70;
        goto LAB_140012d26;
      }
      *puVar15 = puVar10;
      puVar15[1] = puVar14;
      *puVar14 = puVar15;
      puVar5[5] = puVar15;
    }
    if (param_7 == '\0') {
LAB_140012d26:
      *(undefined8 *)(puVar12 + -8) = 0x140012d2d;
      KeReleaseInStackQueuedSpinLock();
    }
    else {
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_50);
    }
  }
  return uVar13;
}



===== QosNblCadReassemble @ 140012d54 =====

void QosNblCadReassemble(longlong param_1,char param_2)

{
  longlong ****pppplVar1;
  undefined8 uVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong ****local_38;
  longlong ****local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = (longlong ****)0x0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_2 == '\0') {
    KeAcquireInStackQueuedSpinLock(param_1 + 0x10,&local_28);
  }
  else {
    KeAcquireInStackQueuedSpinLockAtDpcLevel();
  }
  pppplVar1 = (longlong ****)(param_1 + 0x20);
  local_38 = (longlong ****)*pppplVar1;
  if (local_38 == pppplVar1) {
    local_30 = (longlong ****)&local_38;
    local_38 = (longlong ****)&local_38;
  }
  else {
    local_30 = *(longlong *****)(param_1 + 0x28);
    local_38[1] = (longlong ***)&local_38;
    *local_30 = (longlong ***)&local_38;
    *(longlong *****)(param_1 + 0x28) = pppplVar1;
    *pppplVar1 = (longlong ***)pppplVar1;
  }
  if (param_2 == '\0') {
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  else {
    KeReleaseInStackQueuedSpinLockFromDpcLevel();
  }
  uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8);
  *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8) = 0;
  puVar7 = (undefined8 *)(*(longlong *)(param_1 + 0x18) + 8);
  do {
    if ((longlong *****)local_38 == &local_38) {
LAB_140012e86:
      *puVar7 = uVar2;
      return;
    }
    if (((longlong *****)local_38[1] != &local_38) ||
       (pppplVar1 = (longlong ****)*local_38, (longlong ****)pppplVar1[1] != local_38)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      goto LAB_140012e86;
    }
    pppplVar1[1] = (longlong ***)&local_38;
    ppplVar3 = local_38[3];
    *puVar7 = ppplVar3[1];
    ppplVar3[1] = (longlong **)0x0;
    puVar6 = (undefined8 *)*puVar7;
    while (puVar5 = puVar6, puVar5 != (undefined8 *)0x0) {
      puVar7 = puVar5;
      puVar6 = (undefined8 *)*puVar5;
    }
    local_38 = pppplVar1;
    NdisFreeNetBufferList();
  } while( true );
}



===== QosNblChainRemove @ 140012ea0 =====

undefined8 * QosNblChainRemove(undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = *param_3;
  *param_3 = 0;
  *param_1 = uVar1;
  if ((undefined8 *)param_1[1] == param_3) {
    param_1[1] = 0;
  }
  *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + -1;
  return param_3;
}



===== QosInit @ 140012ec4 =====

ulonglong QosInit(void)

{
  uint uVar1;
  undefined **ppuVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined4 *in_R9;
  bool bVar5;
  
  QosgInitializedModules = 0;
  QosgNblCadLookasideList = &PcgNblCadLookasideList;
  uVar1 = KeQueryTimeIncrement();
  QosgLastSendBoundary = 0;
  QosgBoundaryPeriod = uVar1 / 10;
  QosgRandomValue = KeQueryPerformanceCounter(0);
  bVar5 = PcgEtwDispatchTable == (undefined *)0x0;
  *in_R9 = 0x70;
  if (bVar5) {
LAB_140012f2c:
    uVar4 = 0xc000000d;
  }
  else {
    for (ppuVar2 = &PTR_PcpTraceFlowControlInterval_140019008; (longlong)ppuVar2 < 0x140019040;
        ppuVar2 = ppuVar2 + 1) {
      if (*ppuVar2 == (undefined *)0x0) goto LAB_140012f2c;
    }
    QosgInitializedModules = QosgInitializedModules | 1;
    QosgEtwDispatchTable = &PcgEtwDispatchTable;
    uVar3 = QosTimerInitialize();
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      QosgInitializedModules = QosgInitializedModules | 2;
      goto LAB_140012f36;
    }
  }
  QosTerminate();
LAB_140012f36:
  return uVar4 & 0xffffffff;
}



===== QosTerminate @ 140012f90 =====

void QosTerminate(void)

{
  if (((QosgInitializedModules & 2) != 0) && (QosgTimerTable != 0)) {
    QosgTimerTable = 0;
  }
  if ((QosgInitializedModules & 1) != 0) {
    QosgEtwDispatchTable = 0;
  }
  return;
}



===== QosMrkFlowUpdate @ 140012fc0 =====

void QosMrkFlowUpdate(longlong param_1,longlong *param_2)

{
  uint uVar1;
  longlong lVar2;
  
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((longlong)param_2 + 0x24);
  *(longlong *)(param_1 + 0x50) = param_2[6];
  QosUtilSetTokenSpec((longlong *)(param_1 + 0x38),param_2,*(longlong *)(param_1 + 0x40) == 0);
  uVar1 = KeGetCurrentProcessorNumberEx(0);
  lVar2 = QosTimerGetCurrentTime(uVar1,'\0','\x01');
  *(longlong *)(param_1 + 0x30) = lVar2;
  return;
}



===== QosAssignSlot @ 140013014 =====

ulonglong QosAssignSlot(uint param_1,uint param_2,uint param_3,longlong param_4,uint *param_5,
                       uint *param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = *param_6;
  if (*param_6 == 0) {
    uVar2 = *param_5;
    *param_6 = param_2;
    uVar2 = QosSelectSlot(uVar2 + 1,0,param_3,param_4);
    *param_5 = uVar2;
    uVar2 = param_2;
  }
  uVar1 = *param_5;
  uVar3 = (ulonglong)uVar1;
  if (uVar2 < param_1) {
    *param_6 = param_2 - (param_1 - uVar2) % param_2;
    uVar2 = QosSelectSlot(uVar1 + 1,(param_1 - uVar2) / param_2,param_3,param_4);
    *param_5 = uVar2;
  }
  else {
    *param_6 = uVar2 - param_1;
  }
  return uVar3 & 0xffffffff;
}



===== QosConstructNetBufferListToSend @ 1400130a4 =====

ulonglong QosConstructNetBufferListToSend
                    (undefined8 *param_1,longlong param_2,longlong param_3,uint param_4,
                    undefined8 param_5,int param_6,char param_7,longlong *param_8,longlong *param_9)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  uVar7 = 0;
  *param_8 = 0;
  *param_9 = 0;
  local_28 = (undefined8 *)0x0;
  uStack_20 = 0;
  if (*(longlong *)(param_2 + 0x78) == param_1[4]) {
    lVar2 = *(longlong *)(param_2 + 0x10);
    if (*(int *)((ulonglong)*(ushort *)(lVar2 + 10) + 0x38 + lVar2) == 0) {
      *(undefined8 *)((ulonglong)*(ushort *)(lVar2 + 10) + 0x58 + lVar2) =
           *(undefined8 *)(param_3 + 0x10);
      if (param_4 == 0) {
        *param_9 = param_2;
      }
      else {
        *param_8 = param_2;
      }
      goto LAB_1400131cc;
    }
  }
  uVar6 = 1;
  if (param_4 != 0) {
    uVar6 = param_4;
  }
  uVar3 = QosNblCadDisassemble
                    (param_2,param_1,uVar6,param_6,in_stack_ffffffffffffffb8,(longlong *)&local_28,
                     param_7);
  uVar7 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if (param_4 != 0) {
    puVar4 = QosNblChainRemove(&local_28,param_1,local_28);
    *param_8 = (longlong)puVar4;
    lVar2 = puVar4[2];
    uVar1 = *(ushort *)(lVar2 + 10);
    lVar5 = lVar2 + 0x40 + (ulonglong)uVar1;
    *(longlong *)(lVar5 + 8) = lVar5;
    *(longlong *)lVar5 = lVar5;
    *(undefined8 *)((ulonglong)uVar1 + 0x58 + lVar2) = *(undefined8 *)(param_3 + 0x10);
  }
  *param_9 = (longlong)local_28;
  for (; uVar3 = (ulonglong)param_4, local_28 != (undefined8 *)0x0;
      local_28 = (undefined8 *)*local_28) {
    lVar2 = local_28[2];
    uVar1 = *(ushort *)(lVar2 + 10);
    lVar5 = lVar2 + 0x40 + (ulonglong)uVar1;
    *(longlong *)(lVar5 + 8) = lVar5;
    *(longlong *)lVar5 = lVar5;
    param_4 = param_4 + 1;
    *(undefined8 *)((ulonglong)uVar1 + 0x58 + lVar2) =
         *(undefined8 *)(uVar3 * 0x20 + 0x10 + param_3);
  }
LAB_1400131cc:
  return uVar7 & 0xffffffff;
}



===== QosSelectSlot @ 1400131ec =====

uint QosSelectSlot(uint param_1,int param_2,uint param_3,longlong param_4)

{
  uint uVar1;
  char *pcVar2;
  
  for (; param_1 < param_3; param_1 = param_1 + 1) {
    pcVar2 = (char *)((ulonglong)param_1 + param_4);
    if (param_4 != 0) {
      do {
        if (*pcVar2 != '\0') break;
        param_1 = param_1 + 1;
        pcVar2 = pcVar2 + 1;
      } while (param_1 < param_3);
      if (param_3 <= param_1) break;
    }
    if (param_2 == 0) {
      return param_1;
    }
    param_2 = param_2 + -1;
  }
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_3 - 1;
  }
  return uVar1;
}



===== QosTbcAdjustBytesSent @ 140013238 =====

ulonglong QosTbcAdjustBytesSent(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x110) - param_2;
  if (lVar3 < 1) {
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x150);
    if (*(uint *)(param_1 + 0x150) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (ulonglong)(param_2 - *(longlong *)(param_1 + 0x110)) / uVar5;
    }
    *(ulonglong *)(param_1 + 0x180) = uVar4;
    *(ulonglong *)(param_1 + 0x110) = (uVar5 - (uVar5 + param_2) % uVar5) + param_2;
    uVar1 = *(uint *)(param_1 + 0x1a0);
    *(uint *)(param_1 + 0x1a0) = uVar1 | 1;
    if ((uVar1 & 4) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x154);
      *(uint *)(param_1 + 0x1a0) = uVar1 | 5;
    }
    else {
      uVar5 = QosTbcSmoothBytesRequested(param_1,uVar4);
      uVar2 = (undefined4)uVar5;
    }
    *(undefined4 *)(param_1 + 0x158) = uVar2;
    QosTbcSampleMaxBytesRequested(param_1,uVar4);
    lVar3 = QosTbcEndRcEpisode(param_1);
    *(undefined4 *)(param_1 + 0x154) = 0;
  }
  return CONCAT71((int7)((ulonglong)lVar3 >> 8),*(undefined1 *)(param_1 + 0x1a0)) &
         0xffffffffffffff01;
}



===== QosTbcAdjustSendWindow @ 140013304 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTbcAdjustSendWindow(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStack_98 [32];
  longlong local_78;
  undefined8 local_70;
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  ulonglong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xfffffffe;
  uVar1 = *(uint *)(param_1 + 0x140);
  local_4c = 0;
  uVar3 = *(uint *)(param_2 + 0x14);
  uVar6 = *(uint *)(param_2 + 0xc);
  if (*(uint *)(param_2 + 0xc) <= uVar1) {
    uVar6 = uVar1;
  }
  if (*(uint *)(param_1 + 0x150) != uVar3) {
    if (uVar3 < 100) {
      uVar3 = 100;
    }
    *(uint *)(param_1 + 0x150) = uVar3;
    *(longlong *)(param_1 + 0x120) =
         (longlong)((ulonglong)*(uint *)(param_2 + 8) * (ulonglong)uVar1) /
         (longlong)(ulonglong)uVar6;
    QosTbcTuneParameters(param_1);
  }
  if (*(uint *)(param_1 + 0x144) != uVar6) {
    *(uint *)(param_1 + 0x144) = uVar6;
    QosTbcTuneParameters(param_1);
  }
  uVar1 = *(uint *)(param_2 + 0x10);
  if (*(uint *)(param_1 + 0x148) != uVar1) {
    uVar3 = *(uint *)(param_1 + 0x140);
    if (*(uint *)(param_1 + 0x140) <= uVar1) {
      uVar3 = uVar1;
    }
    *(uint *)(param_1 + 0x148) = uVar3;
    QosTbcTuneParameters(param_1);
  }
  if (*(longlong *)(param_2 + 0x18) == 0x7fffffffffffffff) {
    *(undefined4 *)(param_1 + 0x140) = 0;
    lVar4 = 0;
    local_50 = 0;
  }
  else {
    local_50 = *(uint *)(param_1 + 0x140);
    lVar4 = (longlong)((ulonglong)local_50 * *(longlong *)(param_2 + 0x18)) /
            (longlong)(ulonglong)uVar6;
    lVar2 = *(longlong *)(param_2 + 0x20);
    if ((0 < lVar2) && (lVar2 <= lVar4)) {
      lVar4 = lVar2;
    }
    if (*(int *)(param_1 + 0x174) != 0) {
      *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x174) + -1;
    }
  }
  if (*(int *)*QosgEtwDispatchTable == 1) {
    local_78 = *(longlong *)(param_1 + 0x110) - (ulonglong)*(uint *)(param_1 + 0x150);
    local_60 = *(undefined4 *)(param_1 + 0x128);
    local_5c = *(undefined4 *)(param_1 + 300);
    local_58 = (undefined4)lVar4;
    local_54 = (local_50 * *(int *)(param_2 + 8)) / uVar6;
    local_48 = (ulonglong)*(uint *)(param_1 + 0x158);
    local_68 = param_1;
    uVar5 = QosTbcComputeDropRate(param_1);
    local_34 = *(undefined4 *)(param_1 + 0x19c);
    local_40 = (undefined4)uVar5;
    local_70 = *(undefined8 *)(param_1 + 0x180);
    if ((*(uint *)(param_1 + 0x1a0) & 8) == 0) {
      local_3c = 0;
      local_38 = 0;
      local_30 = 0;
    }
    else {
      local_3c = *(undefined4 *)(param_1 + 0x188);
      local_38 = *(undefined4 *)(param_1 + 0x194);
      local_30 = *(undefined4 *)(param_1 + 400);
    }
    local_2c = *(undefined4 *)(param_1 + 0x15c);
    QosTraceEvent(0,&local_78);
  }
  *(longlong *)(param_1 + 0x130) =
       *(longlong *)(param_1 + 0x130) + (ulonglong)*(uint *)(param_1 + 0x128);
  *(longlong *)(param_1 + 0x138) =
       *(longlong *)(param_1 + 0x138) + (ulonglong)*(uint *)(param_1 + 300);
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(longlong *)(param_1 + 0x118) = lVar4;
  return;
}



===== QosTbcComputeDropRate @ 140013538 =====

ulonglong QosTbcComputeDropRate(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x140) != 0) {
    uVar1 = QosTbcSmoothBytesRequested(param_1,0);
    if ((int)uVar1 != 0) {
      lVar2 = (*(longlong *)(param_1 + 0x118) * 0x7fffffff) / (longlong)(uVar1 & 0xffffffff);
      if (0x7fffffff < lVar2) {
        lVar2 = 0x7fffffff;
      }
      lVar3 = 0;
      if (-1 < lVar2) {
        lVar3 = lVar2;
      }
      uVar4 = 0x7fffffff - lVar3;
    }
  }
  return uVar4 & 0xffffffff;
}



===== QosTbcComputeNbsToDrop @ 14001359c =====

undefined4 QosTbcComputeNbsToDrop(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 0x14c) == 1) {
    if ((longlong)(ulonglong)*(uint *)(param_1 + 0x128) <= *(longlong *)(param_1 + 0x118)) {
      param_2 = 0;
    }
    uVar5 = param_2;
  }
  else {
    uVar3 = QosTbcComputeDropRate(param_1);
    if (((uint)uVar3 != 0) && (*(int *)(param_1 + 0x174) == 0)) {
      uVar1 = *(uint *)(param_1 + 0x19c);
      uVar2 = *(uint *)(param_1 + 0x17c);
      if (0xe < uVar1) {
        uVar4 = uVar1 - 1;
        if (0x1f < uVar4) {
          uVar4 = 0x1f;
        }
        uVar2 = uVar2 / (uint)(1 << ((byte)uVar4 & 0x1f));
      }
      if (uVar2 < (uint)uVar3) {
        if ((((*(uint *)(param_1 + 0x1a0) & 8) == 0) && (uVar1 != 0x1f)) &&
           ((*(longlong *)(param_1 + 0x120) * 3) / 4 <= *(longlong *)(param_1 + 0x118))) {
          *(longlong *)(param_1 + 0x188) = *(longlong *)(param_1 + 0x118);
          *(undefined8 *)(param_1 + 0x194) = 0;
          *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xffffffef | 0x28;
        }
        uVar5 = 1;
        *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x178);
      }
    }
  }
  return uVar5;
}



===== QosTbcEndRcEpisode @ 140013690 =====

void QosTbcEndRcEpisode(longlong param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x1a0);
  if ((uVar3 & 8) != 0) {
    if ((uVar3 & 0x20) != 0) {
      iVar1 = *(int *)(param_1 + 0x15c);
      *(undefined4 *)(param_1 + 0x15c) = 0;
      *(undefined4 *)(param_1 + 0x164) = 0;
      *(undefined4 *)(param_1 + 0x160) = 0;
      uVar3 = uVar3 & 0xffffffdf;
      *(uint *)(param_1 + 400) = (uint)(iVar1 * 3) >> 2;
      *(uint *)(param_1 + 0x1a0) = uVar3;
    }
    *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
    if ((*(int *)(param_1 + 0x174) != 0) && ((uVar3 & 0x10) == 0)) {
      *(undefined4 *)(param_1 + 0x198) = 0;
      uVar3 = uVar3 | 0x10;
      *(uint *)(param_1 + 0x1a0) = uVar3;
    }
    if ((uVar3 & 0x10) != 0) {
      cVar2 = QosTbcEndRcMonitoring(param_1);
      if (cVar2 != '\0') {
        *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xfffffff7;
      }
    }
  }
  return;
}



===== QosTbcEndRcMonitoring @ 140013724 =====

char QosTbcEndRcMonitoring(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  char cVar4;
  
  cVar4 = '\0';
  if ((*(uint *)(param_1 + 0x1a0) & 0x10) != 0) {
    uVar3 = *(int *)(param_1 + 0x198) + 1;
    uVar2 = 10000 / (ulonglong)*(uint *)(param_1 + 0x150);
    *(uint *)(param_1 + 0x198) = uVar3;
    if ((uint)uVar2 < 0xb) {
      uVar2 = 10;
    }
    uVar1 = (ulonglong)uVar3 % uVar2;
    if ((int)uVar1 == 0) {
      if (*(uint *)(param_1 + 400) < *(uint *)(param_1 + 0x15c)) {
        if ((uint)uVar2 < *(uint *)(param_1 + 0x194)) {
          *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + 1;
        }
        *(undefined4 *)(param_1 + 0x174) = 0;
        cVar4 = '\0';
        uVar3 = 0x1f;
        if (*(uint *)(param_1 + 0x19c) < 0x1f) {
          uVar3 = *(uint *)(param_1 + 0x19c);
        }
        *(uint *)(param_1 + 0x19c) = uVar3;
        if (uVar3 == 0x1f) {
          cVar4 = '\x01';
        }
      }
      else {
        cVar4 = (char)uVar1 + '\x01';
      }
      *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xffffffef;
    }
  }
  return cVar4;
}



===== QosTbcFlowInitialize @ 1400137e0 =====

undefined8 QosTbcFlowInitialize(longlong param_1)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = KeGetCurrentProcessorNumberEx(0);
  uVar4 = QosTimerGetCurrentTime(uVar3,'\x01','\x01');
  lVar1 = param_1 + 0x60;
  *(longlong *)(param_1 + 0x68) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined4 *)(param_1 + 0x14c) = 0xffffffff;
  *(ulonglong *)(param_1 + 0x108) = uVar4;
  *(ulonglong *)(param_1 + 0x110) = uVar4;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar4;
  *(undefined4 *)(param_1 + 0x150) = 100;
  *(ulonglong *)(param_1 + 0x100) = uVar4 / 600;
  *(undefined4 *)(param_1 + 0x19c) = 1;
  *(undefined8 *)(param_1 + 0xf0) = 250000000;
  return SUB168(ZEXT816(0x6d3a06d3a06d3a07) * auVar2,0);
}



===== QosTbcFrontalSpread @ 14001386c =====

void QosTbcFrontalSpread(ulonglong param_1,ulonglong param_2,uint param_3,uint param_4,
                        ulonglong *param_5,uint *param_6,longlong param_7,uint param_8,int *param_9)

{
  ulonglong *puVar1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  ulonglong uVar7;
  ulonglong local_res8;
  
  piVar2 = param_9;
  puVar1 = param_5;
  uVar7 = (ulonglong)param_4;
  uVar3 = *param_5;
  if (uVar3 < param_1) {
    uVar5 = uVar3 + param_4;
    *param_6 = param_3;
    uVar3 = param_1;
    if (param_1 < uVar5) {
      uVar3 = uVar5;
    }
    *param_5 = uVar3;
  }
  if (param_2 <= uVar3) {
    param_2 = ((ulonglong)QosgBoundaryPeriod -
              ((QosgBoundaryPeriod - param_2) + uVar3) % (ulonglong)QosgBoundaryPeriod) + uVar3;
  }
  param_5._0_4_ = 0;
  local_res8 = (param_2 - uVar3) / uVar7;
  *param_9 = 0;
  if (param_8 != 0) {
    puVar6 = (ulonglong *)(param_7 + 0x10);
    uVar5 = uVar3;
    param_9 = (int *)(ulonglong)param_8;
    do {
      if (param_2 <= *puVar6) {
        if (uVar3 < param_2) {
          uVar3 = uVar7 + uVar3;
          *param_6 = param_3;
          if (uVar3 <= param_2) {
            uVar3 = param_2;
          }
          *puVar1 = uVar3;
        }
        param_2 = param_2 + QosgBoundaryPeriod;
        local_res8 = (param_2 - uVar3) / uVar7;
        param_5._0_4_ = 0;
        uVar5 = uVar3;
      }
      uVar3 = QosAssignSlot(*(uint *)((longlong)puVar6 + 0xc),param_3,(uint)local_res8,0,
                            (uint *)&param_5,param_6);
      uVar4 = (int)uVar3 * param_4 + uVar5;
      uVar3 = param_4 * (int)param_5 + uVar5;
      *puVar1 = uVar3;
      *puVar6 = uVar4;
      if (uVar4 == param_1) {
        *piVar2 = *piVar2 + 1;
      }
      puVar6 = puVar6 + 4;
      param_9 = (int *)((longlong)param_9 + -1);
    } while (param_9 != (int *)0x0);
  }
  return;
}



===== QosTbcRandomSpread @ 1400139f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
QosTbcRandomSpread(uint param_1,uint param_2,undefined8 *param_3,ulonglong param_4,ulonglong param_5
                  )

{
  byte bVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined1 auVar4 [16];
  bool bVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  byte *pbVar11;
  longlong lVar12;
  undefined8 *puVar13;
  uint uVar14;
  undefined1 uVar15;
  undefined8 *puVar16;
  undefined1 auStackY_118 [32];
  uint local_e8;
  uint local_e4;
  uint local_e0;
  ulonglong local_d8;
  byte local_c8 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar6 = QosgBoundaryPeriod / param_2;
  if (uVar6 < 0x41) {
    for (puVar13 = (undefined8 *)*param_3; (puVar13 != param_3 && ((ulonglong)puVar13[3] < param_4))
        ; puVar13 = (undefined8 *)*puVar13) {
    }
    uVar14 = 0;
    local_c8[0] = 1;
    local_c8[1] = 1;
    local_c8[2] = 1;
    local_c8[3] = 1;
    local_c8[4] = 1;
    local_c8[5] = 1;
    local_c8[6] = 1;
    local_c8[7] = 1;
    local_c8[8] = 1;
    local_c8[9] = 1;
    local_c8[10] = 1;
    local_c8[0xb] = 1;
    local_c8[0xc] = 1;
    local_c8[0xd] = 1;
    local_c8[0xe] = 1;
    local_c8[0xf] = 1;
    bVar5 = false;
    uVar10 = 0;
    local_c8[0x10] = 1;
    local_c8[0x11] = 1;
    local_c8[0x12] = 1;
    local_c8[0x13] = 1;
    local_c8[0x14] = 1;
    local_c8[0x15] = 1;
    local_c8[0x16] = 1;
    local_c8[0x17] = 1;
    local_c8[0x18] = 1;
    local_c8[0x19] = 1;
    local_c8[0x1a] = 1;
    local_c8[0x1b] = 1;
    local_c8[0x1c] = 1;
    local_c8[0x1d] = 1;
    local_c8[0x1e] = 1;
    local_c8[0x1f] = 1;
    local_c8[0x20] = 1;
    local_c8[0x21] = 1;
    local_c8[0x22] = 1;
    local_c8[0x23] = 1;
    local_c8[0x24] = 1;
    local_c8[0x25] = 1;
    local_c8[0x26] = 1;
    local_c8[0x27] = 1;
    local_c8[0x28] = 1;
    local_c8[0x29] = 1;
    local_c8[0x2a] = 1;
    local_c8[0x2b] = 1;
    local_c8[0x2c] = 1;
    local_c8[0x2d] = 1;
    local_c8[0x2e] = 1;
    local_c8[0x2f] = 1;
    local_e4 = 0;
    local_c8[0x30] = 1;
    local_c8[0x31] = 1;
    local_c8[0x32] = 1;
    local_c8[0x33] = 1;
    local_c8[0x34] = 1;
    local_c8[0x35] = 1;
    local_c8[0x36] = 1;
    local_c8[0x37] = 1;
    local_c8[0x38] = 1;
    local_c8[0x39] = 1;
    local_c8[0x3a] = 1;
    local_c8[0x3b] = 1;
    local_c8[0x3c] = 1;
    local_c8[0x3d] = 1;
    local_c8[0x3e] = 1;
    local_c8[0x3f] = 1;
    puVar16 = puVar13;
    local_e8 = param_1;
    local_e0 = param_2;
    local_d8 = param_4;
    while (puVar16 != param_3) {
      puVar3 = (undefined8 *)*puVar16;
      if (param_5 <= (ulonglong)puVar16[3]) {
        bVar5 = true;
        break;
      }
      uVar8 = QosAssignSlot(*(uint *)(*(longlong *)(puVar16[-3] + 8) + 0x18),param_1,0x40,
                            (longlong)local_c8,&local_e4,&local_e8);
      uVar10 = (int)uVar8 + 1;
      puVar16 = puVar3;
    }
    if (uVar6 <= uVar10) {
      bVar5 = true;
      uVar10 = uVar6;
    }
    if (bVar5) {
      memset(local_c8,0,0x40);
      uVar7 = 0;
      pbVar11 = local_c8 + 0x40;
      uVar15 = 1;
      do {
        *pbVar11 = (byte)uVar7;
        uVar7 = uVar7 + 1;
        pbVar11 = pbVar11 + 1;
      } while (uVar7 < 0x40);
      if (uVar10 != 0) {
        pbVar11 = local_c8 + 0x40;
        do {
          uVar8 = (ulonglong)QosgRandomValue * 0x7fffffed + 0x7fffffc3;
          auVar4._8_8_ = 0;
          auVar4._0_8_ = uVar8;
          lVar12 = SUB168(ZEXT816(0x200000005) * auVar4,8);
          QosgRandomValue = (int)uVar8 + (int)((uVar8 - lVar12 >> 1) + lVar12 >> 0x1e) * -0x7fffffff
          ;
          bVar1 = *pbVar11;
          uVar8 = (ulonglong)(QosgRandomValue % (uVar6 - uVar14) + uVar14);
          uVar14 = uVar14 + 1;
          bVar2 = local_c8[uVar8 + 0x40];
          *pbVar11 = bVar2;
          pbVar11 = pbVar11 + 1;
          local_c8[uVar8 + 0x40] = bVar1;
          local_c8[bVar2] = 1;
        } while (uVar14 < uVar10);
      }
      local_e8 = param_1;
      local_e4 = QosSelectSlot(0,0,uVar10,(longlong)local_c8);
      uVar8 = local_d8;
      uVar10 = local_e0;
      if (puVar13 != param_3) {
        do {
          puVar16 = (undefined8 *)*puVar13;
          if (param_5 <= (ulonglong)puVar13[3]) break;
          uVar9 = QosAssignSlot(*(uint *)(*(longlong *)(puVar13[-3] + 8) + 0x18),param_1,uVar6,
                                (longlong)local_c8,&local_e4,&local_e8);
          puVar13[3] = (int)uVar9 * uVar10 + uVar8;
          puVar13 = puVar16;
        } while (puVar16 != param_3);
        uVar15 = 1;
      }
      return uVar15;
    }
  }
  return 0;
}



===== QosTbcSampleMaxBytesRequested @ 140013c4c =====

int QosTbcSampleMaxBytesRequested(longlong param_1,ulonglong param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar5 = 10000 / (ulonglong)*(uint *)(param_1 + 0x150);
  if ((uint)uVar5 < 0xb) {
    uVar5 = 10;
  }
  uVar4 = uVar5;
  if (param_2 < uVar5) {
    uVar4 = param_2;
  }
  uVar2 = (int)uVar4 + *(int *)(param_1 + 0x164) + 1;
  *(uint *)(param_1 + 0x164) = uVar2;
  if ((uint)uVar5 <= uVar2) {
    *(undefined4 *)(param_1 + 0x15c) = 0;
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(int *)(param_1 + 0x164) = (int)((ulonglong)uVar2 % uVar5);
  }
  iVar1 = *(int *)(param_1 + 0x15c);
  iVar3 = iVar1 * 7;
  if ((uint)(iVar1 * 0x19) / 100 <= *(uint *)(param_1 + 0x154)) {
    *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + 1;
    iVar3 = (int)(*(uint *)(param_1 + 0x154) - iVar1) / *(int *)(param_1 + 0x160) + iVar1;
    *(int *)(param_1 + 0x15c) = iVar3;
  }
  return iVar3;
}



===== QosTbcSmoothBytesRequested @ 140013cf4 =====

ulonglong QosTbcSmoothBytesRequested(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x16c);
  uVar2 = (longlong)
          (((ulonglong)*(uint *)(param_1 + 0x154) - (ulonglong)*(uint *)(param_1 + 0x158)) *
          (ulonglong)*(uint *)(param_1 + 0x168)) / (longlong)uVar1 +
          (ulonglong)*(uint *)(param_1 + 0x158);
  if (param_2 != 0) {
    if (uVar1 <= param_2) {
      param_2 = uVar1;
    }
    uVar1 = ((longlong)(*(uint *)(param_1 + 0x168) * uVar2) / (longlong)uVar1) * param_2;
    if ((longlong)uVar2 <= (longlong)uVar1) {
      uVar1 = uVar2;
    }
    uVar2 = uVar2 - uVar1;
  }
  return uVar2 & 0xffffffff;
}



===== QosTraceFlowConformance @ 140013d54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTraceFlowConformance(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  memset(&local_78,0,0x50);
  local_70 = *(undefined8 *)(param_1 + 0x70);
  local_60 = *(undefined8 *)(param_1 + 0x88);
  uStack_58 = *(undefined8 *)(param_1 + 0x90);
  local_50 = *(undefined8 *)(param_1 + 0x98);
  local_68 = *(undefined8 *)(param_1 + 0x78);
  local_40 = *(undefined4 *)(param_1 + 0x80);
  local_78 = param_2;
  local_48 = param_1;
  local_3c = param_3;
  QosTraceEvent(2,&local_78);
  return;
}



===== QosTraceFlowSendQueue @ 140013dfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTraceFlowSendQueue
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  longlong *plVar1;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  plVar1 = *(longlong **)(param_1 + 0x60);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (plVar1 == (longlong *)(param_1 + 0x60)) {
    local_58 = 0;
  }
  else {
    local_58 = plVar1[3];
  }
  local_48 = param_5;
  local_44 = param_6;
  local_40 = param_7;
  local_68 = param_3;
  local_60 = param_4;
  local_50 = param_1;
  local_3c = param_2;
  QosTraceEvent(3,&local_68);
  return;
}



===== Microsoft_Windows_Networking_Correlation_EtwEnableCallback @ 140013e90 =====

void Microsoft_Windows_Networking_Correlation_EtwEnableCallback
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4)

{
  LOCK();
  Microsoft_Windows_Networking_CorrelationEnabled = param_2;
  UNLOCK();
  LOCK();
  Microsoft_Windows_Networking_CorrelationTraceActivityPayload = (uint)(param_4 >> 3) & 1;
  UNLOCK();
  return;
}



===== _guard_check_icall @ 140013ec0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140013ed8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140013efc =====

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



===== __cpu_features_init @ 140013f70 =====

/* WARNING: Removing unreachable block (ram,0x000140013fda) */
/* WARNING: Removing unreachable block (ram,0x000140013f89) */
/* WARNING: Removing unreachable block (ram,0x000140013f7a) */

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



===== __security_check_cookie @ 140014040 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140014080 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400140b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400140b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400140e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140014120 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140014163;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1400141d4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1400141d0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400141d4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1400141cc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400141d0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400141cc;
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
LAB_1400141d4:
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
LAB_140014163:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140014240 =====

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



===== memset @ 140014540 =====

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



===== __memset_repmovs @ 140014680 =====

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



===== __memset_query @ 140014700 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140014780 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400148c0 =====

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



===== __memset_spec_plain @ 140014940 =====

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



===== PcpCreateWfpFilterConditionList @ 14001e008 =====

undefined4
PcpCreateWfpFilterConditionList
          (short param_1,undefined8 *param_2,longlong param_3,undefined4 *param_4,
          undefined8 *param_5)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 *_Dst;
  undefined8 *puVar4;
  uint uVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  size_t _Size;
  uint *puVar9;
  ushort uVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  ulonglong uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  bool bVar18;
  undefined4 local_78;
  longlong local_70;
  char *local_68;
  undefined8 *local_60;
  undefined8 *local_58;
  longlong local_50;
  
  local_78 = 0;
  local_60 = (undefined8 *)0x0;
  local_50 = 0;
  local_58 = (undefined8 *)0x0;
  local_70 = 0;
  if (param_1 == 2) {
    uVar17 = *(ushort *)(param_3 + 0x10);
    uVar10 = *(ushort *)(param_3 + 0x12);
    uVar15 = *(ushort *)(param_2 + 2);
    uVar16 = *(ushort *)((longlong)param_2 + 0x12);
    bVar11 = *(byte *)(param_3 + 0x14);
    bVar13 = *(byte *)((longlong)param_2 + 0x14);
    local_60 = param_2;
    local_50 = param_3;
  }
  else {
    uVar17 = *(ushort *)(param_3 + 0x28);
    uVar10 = *(ushort *)(param_3 + 0x2a);
    uVar15 = *(ushort *)(param_2 + 5);
    uVar16 = *(ushort *)((longlong)param_2 + 0x2a);
    bVar11 = *(byte *)(param_3 + 0x2c);
    bVar13 = *(byte *)((longlong)param_2 + 0x2c);
    local_70 = param_3;
    local_58 = param_2;
  }
  uVar7 = -(uint)(uVar17 != 0) & 0x48;
  uVar8 = uVar7 + 0x30;
  uVar5 = (uVar17 != 0) + 1;
  if (uVar10 != 0) {
    uVar5 = (uVar17 != 0) + 2;
    uVar8 = uVar7 + 0x78;
  }
  uVar7 = uVar8 + 0x48;
  uVar3 = uVar5 + 1;
  if (bVar11 == 0) {
    uVar7 = uVar8;
    uVar3 = uVar5;
  }
  if (param_1 == 2) {
    uVar8 = uVar3 + 1;
    uVar5 = uVar7 + 0x30;
    if (*(int *)(local_50 + 8) == 0) {
      uVar8 = uVar3;
      uVar5 = uVar7;
    }
    bVar18 = *(int *)(local_50 + 0xc) == 0;
    uVar7 = uVar8 + 1;
    if (bVar18) {
      uVar7 = uVar8;
    }
    uVar14 = (ulonglong)uVar7;
    uVar7 = uVar5 + 0x30;
    if (bVar18) {
      uVar7 = uVar5;
    }
    _Size = (size_t)uVar7;
  }
  else {
    bVar18 = *(char *)(local_70 + 8) == '\0';
    uVar5 = uVar7 + 0x40;
    if (bVar18) {
      uVar5 = uVar7;
    }
    _Size = (size_t)uVar5;
    uVar7 = uVar3 + 1;
    if (bVar18) {
      uVar7 = uVar3;
    }
    uVar14 = (ulonglong)uVar7;
    if (*(char *)(local_70 + 0x18) != '\0') {
      uVar14 = (ulonglong)(uVar7 + 1);
      _Size = (size_t)(uVar5 + 0x40);
    }
  }
  local_68 = (char *)(local_70 + 8);
  _Dst = (undefined8 *)ExAllocatePool2(0x100,_Size,0x66667750);
  if (_Dst == (undefined8 *)0x0) {
    local_78 = 0xc000009a;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,0xc000009a);
    }
    _Dst = (undefined8 *)0x0;
    uVar14 = 0;
    goto LAB_14001e44f;
  }
  memset(_Dst,0,_Size);
  puVar1 = _Dst + uVar14 * 5;
  *(undefined4 *)(_Dst + 2) = 0;
  _Dst[4] = puVar1;
  *(undefined4 *)(_Dst + 3) = 4;
  *_Dst = 0x496959c34cd62a49;
  _Dst[1] = 0xa49028d3a5bdf3b7;
  puVar4 = local_60;
  if (param_1 != 2) {
    puVar4 = local_58;
  }
  puVar6 = _Dst + 5;
  *puVar1 = *puVar4;
  puVar9 = (uint *)(puVar1 + 1);
  if (uVar17 != 0) {
    *(undefined4 *)(puVar1 + 3) = 2;
    *puVar9 = 2;
    if (uVar17 == 0xff) {
      uVar17 = uVar15 >> 8 | uVar15 << 8;
      *(ushort *)(puVar1 + 2) = uVar17;
      *(ushort *)(puVar1 + 4) = uVar17;
    }
    else {
      *(ushort *)(puVar1 + 4) = (ushort)(~uVar17 | uVar15) >> 8 | (~uVar17 | uVar15) << 8;
      *(ushort *)(puVar1 + 2) = (uVar17 & uVar15) >> 8 | (uVar17 & uVar15) << 8;
    }
    _Dst[9] = puVar9;
    puVar9 = (uint *)(puVar1 + 5);
    *(undefined4 *)(_Dst + 7) = 5;
    *puVar6 = 0x453f57650c1ba1af;
    _Dst[6] = 0x5b77ac91f7a822af;
    *(undefined4 *)(_Dst + 8) = 0x102;
    puVar6 = _Dst + 10;
  }
  if (uVar10 != 0) {
    puVar9[4] = 2;
    *puVar9 = 2;
    if (uVar10 == 0xff) {
      uVar17 = uVar16 >> 8 | uVar16 << 8;
      *(ushort *)(puVar9 + 2) = uVar17;
      *(ushort *)(puVar9 + 6) = uVar17;
    }
    else {
      *(ushort *)(puVar9 + 6) = (ushort)(~uVar10 | uVar16) >> 8 | (~uVar10 | uVar16) << 8;
      *(ushort *)(puVar9 + 2) = (uVar10 & uVar16) >> 8 | (uVar10 & uVar16) << 8;
    }
    puVar6[4] = puVar9;
    puVar9 = puVar9 + 8;
    *(undefined4 *)(puVar6 + 2) = 5;
    *puVar6 = 0x4e1ad22bc35a604d;
    puVar6[1] = 0x4b67ee74f668b491;
    *(undefined4 *)(puVar6 + 3) = 0x102;
    puVar6 = puVar6 + 5;
  }
  if (param_1 == 2) {
    uVar5 = *(uint *)(local_50 + 8);
    if (uVar5 != 0) {
      puVar9[1] = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = *(uint *)(local_60 + 1);
      *puVar9 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      puVar6[4] = puVar9;
      puVar9 = puVar9 + 2;
      *puVar6 = 0x4617c1efd9ee00de;
      puVar6[1] = 0x5789a0f5d8ffe3bf;
      *(undefined4 *)(puVar6 + 2) = 0;
      *(undefined4 *)(puVar6 + 3) = 0x100;
      puVar6 = puVar6 + 5;
    }
    uVar5 = *(uint *)(local_50 + 0xc);
    if (uVar5 != 0) {
      puVar9[1] = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = *(uint *)((longlong)local_60 + 0xc);
      *puVar9 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      puVar6[4] = puVar9;
      puVar9 = puVar9 + 2;
      *puVar6 = 0x49b81d64b235ae9a;
      puVar6[1] = 0x455009d9f35f4ca4;
      *(undefined4 *)(puVar6 + 3) = 0x100;
      goto LAB_14001e3f9;
    }
  }
  else {
    if (*local_68 != '\0') {
      *(char *)(puVar9 + 4) = *local_68;
      uVar2 = local_58[2];
      *(undefined8 *)puVar9 = local_58[1];
      *(undefined8 *)(puVar9 + 2) = uVar2;
      puVar6[4] = puVar9;
      puVar9 = puVar9 + 6;
      *puVar6 = 0x4617c1efd9ee00de;
      puVar6[1] = 0x5789a0f5d8ffe3bf;
      *(undefined4 *)(puVar6 + 2) = 0;
      *(undefined4 *)(puVar6 + 3) = 0x101;
      puVar6 = puVar6 + 5;
    }
    if (*(char *)(local_70 + 0x18) != '\0') {
      *(char *)(puVar9 + 4) = *(char *)(local_70 + 0x18);
      uVar2 = local_58[4];
      *(undefined8 *)puVar9 = local_58[3];
      *(undefined8 *)(puVar9 + 2) = uVar2;
      puVar6[4] = puVar9;
      puVar9 = puVar9 + 6;
      *puVar6 = 0x49b81d64b235ae9a;
      puVar6[1] = 0x455009d9f35f4ca4;
      *(undefined4 *)(puVar6 + 3) = 0x101;
LAB_14001e3f9:
      *(undefined4 *)(puVar6 + 2) = 0;
      puVar6 = puVar6 + 5;
    }
  }
  if (bVar11 != 0) {
    *puVar9 = 1;
    puVar9[4] = 1;
    if (bVar11 == 0xf) {
      bVar12 = bVar13;
    }
    else {
      bVar12 = bVar11 & bVar13;
      bVar13 = ~bVar11 | bVar13;
    }
    *(byte *)(puVar9 + 2) = bVar12;
    *(byte *)(puVar9 + 6) = bVar13;
    *(undefined4 *)(puVar6 + 2) = 5;
    *(undefined4 *)(puVar6 + 3) = 0x102;
    *puVar6 = 0x4f9a623e3971ef2b;
    puVar6[1] = 0xa7b906b8796eb18c;
    puVar6[4] = puVar9;
  }
LAB_14001e44f:
  *param_5 = _Dst;
  *param_4 = (int)uVar14;
  return local_78;
}



===== PcpIoctlAddFilter @ 14001e488 =====

int PcpIoctlAddFilter(longlong param_1,longlong *param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong *plVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  longlong *plVar6;
  uint uVar7;
  short sVar8;
  uint local_res8 [2];
  longlong *local_res10;
  undefined8 in_stack_ffffffffffffffb0;
  
  plVar6 = (longlong *)0x0;
  local_res8[0] = 0;
  bVar3 = false;
  piVar1 = *(int **)(param_1 + 0x18);
  plVar2 = *(longlong **)(param_2[6] + 0x18);
  local_res10 = (longlong *)0x0;
  if ((*(uint *)(param_2 + 2) < 0x28) || (*(uint *)(param_2 + 1) < 0x18)) {
    return -0x3fffffdd;
  }
  if (piVar1[7] == 0) {
    if (piVar1[8] == 0x18) {
      sVar8 = 2;
      uVar7 = 0x18;
      goto LAB_14001e4f9;
    }
  }
  else if ((piVar1[7] == 3) && (piVar1[8] == 0x30)) {
    sVar8 = 0x17;
    uVar7 = 0x30;
LAB_14001e4f9:
    if (*(uint *)(param_2 + 2) < uVar7 * 2 + 0x24) {
      iVar4 = -0x3fffffdd;
      goto LAB_14001e57d;
    }
    if (*(longlong *)(piVar1 + 2) != 0) {
      param_2 = plVar2;
      uVar5 = PcpValidateFlowByHandle32(piVar1[2],(longlong)plVar2,(longlong *)&local_res10);
      plVar6 = local_res10;
      iVar4 = (int)uVar5;
      if (-1 < iVar4) {
        param_2 = (longlong *)((ulonglong)uVar7 + 0x24 + (longlong)piVar1);
        bVar3 = true;
        uVar5 = PcpAddFilter((longlong *)(piVar1 + 9),param_2,sVar8,local_res10,(longlong)plVar2,
                             in_stack_ffffffffffffffb0,local_res8);
        iVar4 = (int)uVar5;
        if (-1 < iVar4) {
          piVar1[4] = 0;
          *(ulonglong *)(piVar1 + 2) = (ulonglong)local_res8[0];
        }
      }
      goto LAB_14001e57d;
    }
  }
  iVar4 = -0x3ffffff3;
LAB_14001e57d:
  *piVar1 = iVar4;
  *param_3 = 0x18;
  if (bVar3) {
    PcpDereferenceFlow(plVar6,(ulonglong)param_2);
  }
  if (iVar4 < 0) {
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
  }
  return iVar4;
}



===== PcpIoctlAddFilter32 @ 14001e5cc =====

int PcpIoctlAddFilter32(longlong param_1,longlong *param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong *plVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  longlong *plVar6;
  uint uVar7;
  short sVar8;
  int local_res8 [2];
  longlong *local_res10;
  undefined8 in_stack_ffffffffffffffb0;
  
  plVar6 = (longlong *)0x0;
  local_res8[0] = 0;
  bVar3 = false;
  piVar1 = *(int **)(param_1 + 0x18);
  plVar2 = *(longlong **)(param_2[6] + 0x18);
  local_res10 = (longlong *)0x0;
  if ((*(uint *)(param_2 + 2) < 0x1c) || (*(uint *)(param_2 + 1) < 0xc)) {
    return -0x3fffffdd;
  }
  if (piVar1[4] == 0) {
    if (piVar1[5] == 0x18) {
      sVar8 = 2;
      uVar7 = 0x18;
      goto LAB_14001e63d;
    }
  }
  else if ((piVar1[4] == 3) && (piVar1[5] == 0x30)) {
    sVar8 = 0x17;
    uVar7 = 0x30;
LAB_14001e63d:
    if (*(uint *)(param_2 + 2) < uVar7 * 2 + 0x18) {
      iVar4 = -0x3fffffdd;
      goto LAB_14001e6be;
    }
    if (piVar1[1] != 0) {
      param_2 = plVar2;
      uVar5 = PcpValidateFlowByHandle32(piVar1[1],(longlong)plVar2,(longlong *)&local_res10);
      plVar6 = local_res10;
      iVar4 = (int)uVar5;
      if (-1 < iVar4) {
        param_2 = (longlong *)((ulonglong)uVar7 + 0x18 + (longlong)piVar1);
        bVar3 = true;
        uVar5 = PcpAddFilter((longlong *)(piVar1 + 6),param_2,sVar8,local_res10,(longlong)plVar2,
                             in_stack_ffffffffffffffb0,local_res8);
        iVar4 = (int)uVar5;
        if (-1 < iVar4) {
          piVar1[2] = 0;
          piVar1[1] = local_res8[0];
        }
      }
      goto LAB_14001e6be;
    }
  }
  iVar4 = -0x3ffffff3;
LAB_14001e6be:
  *piVar1 = iVar4;
  *param_3 = 0xc;
  if (bVar3) {
    PcpDereferenceFlow(plVar6,(ulonglong)param_2);
  }
  if (iVar4 < 0) {
    piVar1[1] = 0;
    piVar1[2] = 0;
  }
  return iVar4;
}



===== PcpIoctlDeleteFilter @ 14001e70c =====

int PcpIoctlDeleteFilter(longlong param_1,longlong param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong local_res8;
  
  local_res8 = 0;
  piVar1 = *(int **)(param_1 + 0x18);
  if ((*(uint *)(param_2 + 0x10) < 0x10) || (*(uint *)(param_2 + 8) < 4)) {
    iVar3 = -0x3fffffdd;
  }
  else {
    if (*(longlong *)(piVar1 + 2) == 0) {
      iVar3 = -0x3ffffddb;
    }
    else {
      uVar4 = PcpRemoveFilterByHandle32
                        (piVar1[2],*(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18),&local_res8);
      lVar2 = local_res8;
      iVar3 = (int)uVar4;
      if (-1 < iVar3) {
        iVar3 = FwpmFilterDeleteByKey0(PcgWfpEngineHandle,local_res8 + 0x10);
        if ((((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,iVar3);
        }
        PcpFreeFilter(lVar2);
      }
    }
    *piVar1 = iVar3;
    *param_3 = 4;
  }
  return iVar3;
}



===== PcpIoctlDeleteFilter32 @ 14001e800 =====

int PcpIoctlDeleteFilter32(longlong param_1,longlong param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong local_res8;
  
  local_res8 = 0;
  piVar1 = *(int **)(param_1 + 0x18);
  if ((*(uint *)(param_2 + 0x10) < 8) || (*(uint *)(param_2 + 8) < 4)) {
    iVar3 = -0x3fffffdd;
  }
  else {
    iVar3 = piVar1[1];
    if (iVar3 == 0) {
      iVar3 = -0x3ffffddb;
    }
    else {
      uVar4 = PcpRemoveFilterByHandle32
                        (iVar3,*(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18),&local_res8);
      lVar2 = local_res8;
      iVar3 = (int)uVar4;
      if (-1 < iVar3) {
        iVar3 = FwpmFilterDeleteByKey0(PcgWfpEngineHandle,local_res8 + 0x10);
        if ((((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_2f62ffcc0a253160c008801dc1cba625_Traceguids,iVar3);
        }
        PcpFreeFilter(lVar2);
      }
    }
    *piVar1 = iVar3;
    *param_3 = 4;
  }
  return iVar3;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001e8f0 =====

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



===== PcpStartFilter @ 14001e9c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PcpStartFilter(void)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_60;
  code *local_58;
  code *local_48;
  code *local_40;
  code *local_38;
  
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_128 = 0;
  uStack_120 = 0;
  RtlInitUnicodeString(&local_108,L"Psched");
  RtlInitUnicodeString(&local_128,L"QoS Packet Scheduler");
  RtlInitUnicodeString(&local_118);
  memset(&local_f8,0,0xf0);
  local_f8 = 0xf0038b;
  local_a8 = PcFilterAttach;
  local_f4 = 0x15906;
  local_a0 = PcFilterDetach;
  local_98 = PcFilterRestart;
  local_90 = PcFilterPause;
  local_b0 = PcFilterSetModuleOptions;
  local_60 = PcFilterRequest;
  local_58 = PcFilterRequestComplete;
  local_48 = PcFilterPnPEventNotify;
  local_40 = PcFilterPnPEvent;
  local_e8 = local_128;
  uStack_e0 = uStack_120;
  local_38 = PcFilterStatus;
  local_b8 = PcFilterSetOptions;
  local_d8 = (undefined4)local_118;
  uStack_d4 = local_118._4_4_;
  uStack_d0 = (undefined4)uStack_110;
  uStack_cc = uStack_110._4_4_;
  local_c8 = (undefined4)local_108;
  uStack_c4 = local_108._4_4_;
  uStack_c0 = (undefined4)uStack_100;
  uStack_bc = uStack_100._4_4_;
  KeInitializeSpinLock(&PcgLineTableLock);
  DAT_140019688 = &PcgLineList;
  PcgLineList = &PcgLineList;
  PcgLineTable = 0;
  PcgLineTableLen = 0;
  PcgLineTableNextId = 0;
  ExInitializeNPagedLookasideList(&PcgNblCadLookasideList,0,0,0x200,0x38,0x706f6350,0);
  PcpReadSettings(0,(uint *)&PcgSettings);
  PcgDefaultFlow = 0;
  QosInit();
  PcgNblContextSize = 0;
  DAT_140019890 = &DAT_140019888;
  DAT_140019888 = &DAT_140019888;
  uVar2 = NdisFRegisterFilterDriver
                    (PcgDriverObject,&PcgFilterDriverContext,&local_f8,&PcgFilterDriverHandle);
  iVar1 = (int)uVar2;
  if (iVar1 == 0) {
    _PcgInitializedModules = _PcgInitializedModules | 2;
    LOCK();
    PcgDriverReference = PcgDriverReference + 1;
    UNLOCK();
    uVar3 = uVar2;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_263d9268693f357b83e9029a6246d0a9_Traceguids,iVar1);
    }
    QosTerminate();
    ExDeleteNPagedLookasideList(&PcgNblCadLookasideList);
    uVar3 = 0xc0000001;
    if (iVar1 < 0) {
      uVar3 = uVar2 & 0xffffffff;
    }
  }
  return uVar3;
}



===== PcpStopFilter @ 14001ec60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopFilter(undefined8 param_1,ulonglong param_2)

{
  _PcgInitializedModules = _PcgInitializedModules & 0xfffffffffffffffd;
  NdisFDeregisterFilterDriver(PcgFilterDriverHandle);
  PcpDereferenceDriver();
  if (PcgDefaultFlow != (longlong *)0x0) {
    PcpDeleteFlow(PcgDefaultFlow,param_2);
  }
  QosTerminate();
  ExDeleteNPagedLookasideList(&PcgNblCadLookasideList);
  if (PcgLineTable != 0) {
    ExFreePoolWithTag(PcgLineTable,0x746c6350);
    PcgLineTable = 0;
  }
  PcgLineTableLen = 0;
  PcgLineTableNextId = 0;
  NdisFreeRWLock(PcgLineListLock);
  NdisFreeRWLock(PcgFilterDriverContext);
  return;
}



===== PcpCloseHoldHandleWorkerRoutine @ 14001ed20 =====

void PcpCloseHoldHandleWorkerRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ZwClose(param_2);
  IoFreeWorkItem(param_3);
  return;
}



===== PcpCreateHoldHandleWorkerRoutine @ 14001ed60 =====

void PcpCreateHoldHandleWorkerRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  PcpCreateHoldHandle();
  IoFreeWorkItem(param_3);
  return;
}



===== PcpQueryFlowStats @ 14001ed8c =====

void PcpQueryFlowStats(longlong param_1,longlong param_2,int param_3,uint *param_4,uint *param_5)

{
  QosFlowQueryStats(param_1 + 0x88,param_2,param_3,param_4,param_5);
  return;
}



===== DriverEntry @ 14001edb4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,short *param_2)

{
  int iVar1;
  
  _DAT_140019728 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140019708 = &WPP_ThisDir_CTLGUID_NETIO;
  DAT_140019710 = 0;
  _DAT_140019720 = 0;
  WppLoadTracingSupport();
  _DAT_140019720 = 0;
  WppInitKm();
  iVar1 = wil_InitializeFeatureStaging();
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,iVar1);
    }
    WppCleanupKm();
  }
  else {
    NdisInitializeEvent(&PcgDriverUnloadEvent);
    PcgDriverObject = param_1;
    *(code **)(param_1 + 0x68) = PcUnload;
    _DAT_1400196f2 = *param_2 + 2;
    PcgRegistryPath = *param_2;
    iVar1 = NdisAllocateMemoryWithTag(&DAT_1400196f8,_DAT_1400196f2,0x65676350);
    if (iVar1 != 0) {
      wil_UninitializeFeatureStaging();
      WppCleanupKm();
      if (iVar1 < 0) {
        return iVar1;
      }
      return -0x3fffffff;
    }
    RtlCopyUnicodeString(&PcgRegistryPath,param_2);
    DAT_1400197d8 = &PcgFlowList;
    PcgFlowList = &PcgFlowList;
    KeInitializeSpinLock(&PcgFlowListLock);
    DAT_1400197f8 = 0;
    DAT_140019778 = &PcgFileCtxList;
    PcgFileCtxList = &PcgFileCtxList;
    KeInitializeSpinLock(&PcgFileCtxListLock);
    _DAT_140019788 = 0;
    KeInitializeSemaphore(&PcgWfpInitSemaphore,1,1);
    KeInitializeSpinLock(&PcgHandleFactoryLock);
    PcgHandleFactory = 0;
    KeInitializeSpinLock(&PcgHoldLock);
    PcgHoldHandle = 0;
    PcgHoldCloseWorkItem = 0;
    PcgHoldCount = 0;
    iVar1 = RtlInvokeStartRoutines(&PcgStartStopRoutines,8,&PcgInitializedModules);
    if (iVar1 < 0) {
      wil_UninitializeFeatureStaging();
      WppCleanupKm();
      NdisFreeMemoryWithTag(DAT_1400196f8,0x65676350);
    }
    else {
      LOCK();
      PcgDriverReference = PcgDriverReference + 1;
      UNLOCK();
    }
  }
  return iVar1;
}



===== PcUnload @ 14001f010 =====

void PcUnload(void)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  RtlInvokeStopRoutines(&PcgStartStopRoutines,8,&PcgInitializedModules);
  PcpDereferenceDriver();
  uVar3 = 0;
  NdisWaitEvent(&PcgDriverUnloadEvent);
  plVar2 = PcgFlowList;
  while ((longlong **)plVar2 != &PcgFlowList) {
    plVar1 = (longlong *)*plVar2;
    PcpDeleteFlow(plVar2,uVar3);
    plVar2 = plVar1;
  }
  KeFlushQueuedDpcs();
  PcpCleanup();
  return;
}



===== PcpAllocateAndInitializeSid @ 14001f09c =====

undefined8 PcpAllocateAndInitializeSid(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined8 uVar3;
  undefined8 *in_stack_00000058;
  
  uVar1 = RtlLengthRequiredSid(6);
  puVar2 = (undefined2 *)ExAllocatePool2(0x40,uVar1,0x65676350);
  if (puVar2 == (undefined2 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids);
    }
    uVar3 = 0xc000009a;
  }
  else {
    *puVar2 = 0x601;
    *(undefined4 *)(puVar2 + 1) = *param_1;
    puVar2[3] = *(undefined2 *)(param_1 + 1);
    *(undefined4 *)(puVar2 + 0xe) = 0xf123d6d4;
    *(undefined4 *)(puVar2 + 0xc) = 0xeba2e3c2;
    *(undefined4 *)(puVar2 + 10) = 0x33564568;
    *in_stack_00000058 = puVar2;
    uVar3 = 0;
    *(undefined4 *)(puVar2 + 8) = 0xbba433cc;
    *(undefined4 *)(puVar2 + 6) = 0x62e42435;
    *(undefined4 *)(puVar2 + 4) = 0x50;
  }
  return uVar3;
}



===== PcpBuildDeviceAcl @ 14001f16c =====

ulonglong PcpBuildDeviceAcl(longlong *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined4 local_res10;
  undefined2 local_res14;
  longlong local_res18;
  
  local_res18 = 0;
  local_res10 = 0;
  local_res14 = 0x500;
  uVar10 = PcpAllocateAndInitializeSid(&local_res10);
  lVar4 = local_res18;
  uVar12 = uVar10 & 0xffffffff;
  if (-1 < (int)uVar10) {
    lVar11 = *(longlong *)SeExports_exref;
    uVar1 = *(undefined8 *)(lVar11 + 0x110);
    uVar2 = *(undefined8 *)(lVar11 + 0x108);
    uVar3 = *(undefined8 *)(lVar11 + 0x180);
    iVar5 = RtlLengthSid(local_res18);
    iVar6 = RtlLengthSid(uVar3);
    iVar7 = RtlLengthSid(uVar1);
    iVar8 = RtlLengthSid(uVar2);
    iVar5 = iVar5 + iVar6 + iVar7 + iVar8 + 0x28;
    lVar11 = ExAllocatePool2(0x40,iVar5,0x65676350);
    if (lVar11 == 0) {
      uVar12 = 0xc000009a;
    }
    else {
      uVar9 = RtlCreateAcl(lVar11,iVar5,2);
      uVar12 = (ulonglong)uVar9;
      if (-1 < (int)uVar9) {
        uVar9 = RtlAddAccessAllowedAceEx(lVar11,2,3,0x10000000,uVar1);
        uVar12 = (ulonglong)uVar9;
        if (-1 < (int)uVar9) {
          uVar9 = RtlAddAccessAllowedAceEx(lVar11,2,3,0x10000000,uVar2);
          uVar12 = (ulonglong)uVar9;
          if (-1 < (int)uVar9) {
            uVar9 = RtlAddAccessAllowedAceEx(lVar11,2,3,0x10000000,uVar3);
            uVar12 = (ulonglong)uVar9;
            if (-1 < (int)uVar9) {
              uVar9 = RtlAddAccessAllowedAceEx(lVar11,2,3,0x10000000,lVar4);
              uVar12 = (ulonglong)uVar9;
              if (-1 < (int)uVar9) {
                *param_1 = lVar11;
                goto LAB_14001f359;
              }
            }
          }
        }
      }
      ExFreePoolWithTag(lVar11,0);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,(int)uVar12);
  }
LAB_14001f359:
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  return uVar12;
}



===== PcpCleanup @ 14001f394 =====

void PcpCleanup(void)

{
  if (PcgWfpEngineHandle != 0) {
    FwpiCalloutUnregisterAndDeleteByKey0(PcgWfpEngineHandle,&PcgWfpCalloutGuid);
    FwpiCalloutUnregisterAndDeleteByKey0(PcgWfpEngineHandle,&PcgWfpV6CalloutGuid);
    FwpmEngineClose0(PcgWfpEngineHandle);
    PcgWfpEngineHandle = 0;
  }
  NdisFreeMemoryWithTag(DAT_1400196f8,0x65676350);
  if (PcgHandleFactory != 0) {
    HfDestroyFactory(&PcgHandleFactory);
  }
  wil_UninitializeFeatureStaging();
  WppCleanupKm();
  return;
}



===== PcpCreateDevice @ 14001f438 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PcpCreateDevice(void)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  undefined8 *puStack_150;
  undefined8 *local_148;
  code **ppcStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  ulonglong local_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  code *local_f8 [2];
  code *local_e8;
  code *local_88;
  code *local_80;
  code *local_68;
  code *local_40;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_178;
  local_128 = local_128 & 0xffffffff00000000;
  local_120 = 0;
  uStack_118 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_158 = 0;
  puStack_150 = (undefined8 *)0x0;
  local_148 = (undefined8 *)0x0;
  ppcStack_140 = (code **)0x0;
  local_138 = 0;
  uStack_130 = 0;
  memset(local_f8,0,0xe0);
  local_88 = PcpDispatch;
  local_80 = PcpDispatch;
  local_f8[0] = PcpDispatch;
  local_68 = PcpDispatch;
  local_e8 = PcpDispatch;
  local_40 = PcpWmiDispatch;
  RtlInitUnicodeString(&local_120,L"\\Device\\Psched");
  RtlInitUnicodeString(&local_110,L"\\DosDevices\\Psched");
  puStack_150 = &local_120;
  local_138 = 0;
  local_148 = &local_110;
  local_158 = 0x380180;
  ppcStack_140 = local_f8;
  uStack_130 = 0;
  local_128 = 0;
  iVar1 = NdisRegisterDeviceEx
                    (PcgFilterDriverHandle,&local_158,&PcgDeviceObject,&PcgNdisDeviceHandle);
  if (iVar1 == 0) {
    *(uint *)(PcgDeviceObject + 0x30) = *(uint *)(PcgDeviceObject + 0x30) | 4;
    uVar3 = PcpSetDeviceSecurityDescriptor();
    iVar2 = (int)uVar3;
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,iVar2);
      }
      NdisDeregisterDeviceEx(PcgNdisDeviceHandle);
      PcgDeviceObject = 0;
      PcgNdisDeviceHandle = 0;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,iVar1);
    }
    iVar2 = -0x3fffffff;
    if (iVar1 < 0) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



===== PcpSetDeviceSecurityDescriptor @ 14001f638 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PcpSetDeviceSecurityDescriptor(void)

{
  uint uVar1;
  ulonglong uVar2;
  void *_Dst;
  undefined2 uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined8 local_70;
  undefined1 local_68 [4];
  undefined4 local_64;
  void *local_60;
  void *local_58;
  longlong local_50;
  undefined1 local_48 [40];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  local_50 = 0;
  local_58 = (void *)0x0;
  local_60 = (void *)0x0;
  _Dst = (void *)0x0;
  local_68[0] = 0;
  local_64 = 4;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (5 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids);
  }
  uVar1 = ObGetObjectSecurity(PcgDeviceObject,&local_58,local_68);
  uVar5 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((1 < (byte)WPP_GLOBAL_Control[0x29]) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,uVar1);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) == 0) {
      return uVar5;
    }
    uVar3 = 0xe;
  }
  else {
    uVar2 = PcpBuildDeviceAcl(&local_50);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,(int)uVar2);
      }
    }
    else {
      RtlCreateSecurityDescriptor(local_48,1);
      RtlSetDaclSecurityDescriptor(local_48,1,local_50,0);
      uVar1 = RtlLengthSecurityDescriptor(local_58);
      _Dst = (void *)ExAllocatePool2(0x100,uVar1,0x65676350);
      local_60 = _Dst;
      if (_Dst == (void *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids);
        }
        _Dst = (void *)0x0;
      }
      else {
        memmove(_Dst,local_58,(ulonglong)uVar1);
        local_70 = IoGetFileObjectGenericMapping();
        local_78 = 0x200;
        puVar6 = local_48;
        puVar4 = &local_64;
        uVar1 = SeSetSecurityDescriptorInfo(0,puVar4,puVar6,&local_60);
        uVar5 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar4,puVar6,uVar1);
          }
        }
        else {
          uVar1 = ObSetSecurityObjectByPointer(PcgDeviceObject,local_64,local_60);
          uVar5 = (ulonglong)uVar1;
        }
      }
    }
    ObReleaseObjectSecurity(local_58,local_68[0]);
    if (local_60 != _Dst) {
      ExFreePoolWithTag(_Dst,0);
    }
    if (local_60 != (void *)0x0) {
      ExFreePoolWithTag(local_60,0);
    }
    if (local_50 != 0) {
      ExFreePoolWithTag(local_50,0);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 6) {
      return uVar5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) == 0) {
      return uVar5;
    }
    uVar3 = 0x12;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_c6c5df1111473950c1adef193433fd5a_Traceguids,(int)uVar5);
  return uVar5;
}



===== WppCleanupKm @ 14001f970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

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
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppInitKm @ 14001f9f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
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
  }
  return;
}



===== WppLoadTracingSupport @ 14001fa80 =====

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



===== WppTraceCallback @ 14001fbd0 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== wil_UninitializeFeatureStaging @ 14001fe58 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14001feb0 =====

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
      goto LAB_14001ff0d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001ff0d;
    }
  }
  uVar1 = 0x206;
LAB_14001ff0d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001ff18 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001ffd0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140020008 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14002008a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14002008a;
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
LAB_14002008a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400200e0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140020140 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14002015c =====

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



===== PcpStartQoSProvider @ 140020210 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PcpStartQoSProvider(void)

{
  int iVar1;
  
  DAT_1400196e8 = &PcgQoSClientList;
  _PcgQoSClientList = &PcgQoSClientList;
  PcgQoSClientListLock = NdisAllocateRWLock(PcgFilterDriverHandle);
  if (PcgQoSClientListLock == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = NmrRegisterProvider(&PcpQoSProviderNotify,0,&PcgQoSProviderHandle);
    if (iVar1 < 0) {
      NdisFreeRWLock(PcgQoSClientListLock);
    }
    else {
      _PcgInitializedModules = _PcgInitializedModules | 1;
      LOCK();
      PcgDriverReference = PcgDriverReference + 1;
      UNLOCK();
    }
  }
  return iVar1;
}



===== PcpStopQoSProvider @ 1400202b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopQoSProvider(void)

{
  _PcgInitializedModules = _PcgInitializedModules & 0xfffffffffffffffe;
  NmrDeregisterProvider(PcgQoSProviderHandle);
  if (PcgQoSProviderHandle != 0) {
    NmrWaitForProviderDeregisterComplete();
    PcDeregisterQoSProviderComplete();
  }
  NdisFreeRWLock(PcgQoSClientListLock);
  return;
}



===== PcpRegisterCallout @ 14002030c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PcpRegisterCallout(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_188 [32];
  longlong *local_168;
  longlong local_158 [4];
  code *local_138;
  code *local_130;
  undefined8 local_128;
  longlong local_120 [3];
  code *local_108;
  code *local_100;
  undefined8 local_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  wchar_t *local_d8;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined8 local_88;
  undefined8 uStack_80;
  wchar_t *local_78;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  uVar2 = 0;
  local_158[3] = 0;
  local_120[2] = 0;
  local_158[0] = 0;
  if (PcgWfpEngineHandle != 0) {
    return 0;
  }
  local_168 = (longlong *)0x0;
  iVar1 = KeWaitForSingleObject(&PcgWfpInitSemaphore,0,0);
  if (iVar1 == 0) {
    if (PcgWfpEngineHandle == 0) {
      KeInitializeSpinLock(&DAT_140019540);
      DAT_140019550 = &DAT_140019548;
      DAT_140019548 = &DAT_140019548;
      local_168 = local_158;
      iVar1 = FwpmEngineOpen0(0,10,0);
      if (iVar1 == 0) {
        local_158[3] = 0;
        local_128 = 0;
        local_138 = PcWfpCallout;
        local_130 = PcWfpNotify;
        local_158[1] = 0x4544130d10a05337;
        local_158[2] = 0x7ff76476d47398ad;
        memset(&local_e8,0,0x58);
        local_d8 = L"QoS";
        local_168 = (longlong *)0x0;
        local_a8 = 0x9e61aea;
        uStack_a4 = 0x46e2d214;
        uStack_a0 = 0x6bb2219b;
        uStack_9c = 0xc8282f0b;
        local_e8 = 0x4544130d10a05337;
        uStack_e0 = 0x7ff76476d47398ad;
        iVar1 = FwpiCalloutRegisterAndAddWithoutDevice0(local_158[0],local_158 + 1,&local_e8,0);
        if (iVar1 == 0) {
          local_120[2] = 0;
          local_108 = PcWfpCallout;
          local_120[0] = 0x40770a70035ccc6d;
          local_120[1] = 0x5c479efa6142d2b6;
          local_100 = PcWfpNotify;
          local_f8 = 0;
          memset(&local_88,0,0x58);
          local_78 = L"QoS";
          local_168 = (longlong *)0x0;
          local_48 = 0xe1735bde;
          uStack_44 = 0x4655013f;
          uStack_40 = 0x9ea451b3;
          uStack_3c = 0xf02d7615;
          local_88 = 0x40770a70035ccc6d;
          uStack_80 = 0x5c479efa6142d2b6;
          iVar1 = FwpiCalloutRegisterAndAddWithoutDevice0(local_158[0],local_158 + 7,&local_88,0);
          if (iVar1 == 0) {
            PcgWfpEngineHandle = local_158[0];
            goto LAB_1400205e9;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_3d8b747fe13d335cadcbf0d03feb93cd_Traceguids,iVar1);
          }
          FwpiCalloutUnregisterAndDeleteByKey0(local_158[0],&PcgWfpCalloutGuid);
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_3d8b747fe13d335cadcbf0d03feb93cd_Traceguids,iVar1);
        }
        KeReleaseSemaphore(&PcgWfpInitSemaphore,0,1);
        FwpmEngineClose0(local_158[0]);
        goto LAB_140020383;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_3d8b747fe13d335cadcbf0d03feb93cd_Traceguids,iVar1);
      }
      uVar2 = 0xc0000001;
    }
LAB_1400205e9:
    KeReleaseSemaphore(&PcgWfpInitSemaphore,0,1);
  }
  else {
LAB_140020383:
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== PcQueryGuidDataSize @ 14002063c =====

undefined8 PcQueryGuidDataSize(longlong param_1,longlong param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  uint local_res10 [6];
  
  local_res10[0] = 0;
  if (param_2 == 0) {
    if (param_3 < 0xfb01010e) {
      if (((param_3 == 0xfb01010d) || (param_3 == 0xfb010103)) ||
         ((param_3 == 0xfb010104 || (param_3 == 0xfb010106)))) goto LAB_140020787;
      if (param_3 == 0xfb010109) {
        *param_4 = 0x10;
        return 0;
      }
      bVar1 = param_3 == 0xfb01010a;
    }
    else {
      if (((param_3 == 0xfb010112) || (param_3 == 0xfb010113)) || (param_3 == 0xff010103))
      goto LAB_140020787;
      bVar1 = param_3 == 0xff010104;
    }
    if (!bVar1) {
      if (param_1 != 0) {
        if (param_3 == 0xfb010100) {
          *param_4 = 0;
          PcpCollectNetworkAddressList(param_1,param_4,(undefined2 *)0x0);
          return 0;
        }
        if ((param_3 == 0xfb010101) || (param_3 == 0xfb010107)) goto LAB_140020787;
        if (param_3 == 0xfb01010b) {
          *param_4 = 0x5c;
          return 0;
        }
      }
      return 0xc00002dd;
    }
  }
  else if ((param_3 != 0xfb010102) && (param_3 != 0xfb010105)) {
    if (param_3 == 0xfb01010b) {
      *param_4 = 0;
      QosFlowQueryStats(param_2 + 0x88,0,0,param_4,local_res10);
      return 0;
    }
    if (((param_3 != 0xfb01010f) && (param_3 != 0xfb010110)) && (param_3 != 0xfb010111)) {
      return 0xc00002dd;
    }
  }
LAB_140020787:
  *param_4 = 4;
  return 0;
}



===== PcWmiHandleSingleInstance @ 14002079c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PcWmiHandleSingleInstance
               (int param_1,uint *param_2,longlong param_3,uint param_4,uint *param_5)

{
  ushort uVar1;
  uint *puVar2;
  uint uVar3;
  longlong *_Dst;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  uint uVar9;
  
  puVar2 = param_5;
  uVar9 = param_2[0xc];
  uVar3 = 0xc0000296;
  uVar1 = *(ushort *)((longlong)param_2 + (ulonglong)uVar9);
  *param_5 = 0;
  _Dst = (longlong *)ExAllocatePool2(0x40,(ulonglong)uVar1 + 2,0x65676350);
  if (_Dst == (longlong *)0x0) {
    return 0xc000009a;
  }
  memmove(_Dst,(void *)((ulonglong)uVar9 + 2 + (longlong)param_2),(ulonglong)uVar1);
  puVar5 = (undefined8 *)0x0;
  *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar1 >> 1) * 2) = 0;
  plVar4 = (longlong *)0x0;
  if (9 < uVar1) {
    lVar7 = *_Dst + -0x77006f006c0046;
    if (lVar7 == 0) {
      lVar7 = (ulonglong)*(ushort *)(_Dst + 1) - 0x3a;
    }
    if (lVar7 == 0) {
      plVar4 = PcpFindFlowInstanceByName(_Dst,uVar1);
      goto LAB_140020871;
    }
  }
  puVar5 = PcpLineFindByInstanceName(_Dst,uVar1);
LAB_140020871:
  plVar8 = (longlong *)0x0;
  ExFreePoolWithTag(_Dst);
  if ((puVar5 != (undefined8 *)0x0) || (plVar4 != (longlong *)0x0)) {
    if (param_1 == 1) {
      param_5._0_4_ = 0;
      plVar8 = plVar4;
      uVar6 = PcQueryGuidDataSize((longlong)puVar5,(longlong)plVar4,*(uint *)(param_3 + 0x10),
                                  (uint *)&param_5);
      uVar3 = (uint)uVar6;
      param_5 = (uint *)CONCAT44(param_5._4_4_,(uint)param_5);
      if (-1 < (int)uVar3) {
        uVar9 = (uint)param_5 + param_2[0xe];
        if (uVar9 < param_2[0xe]) {
          uVar3 = 0xc0000095;
          param_5 = (uint *)CONCAT44(param_5._4_4_,(uint)param_5);
        }
        else if (param_4 < uVar9) {
          if (param_4 < 0x38) {
            uVar3 = 0xc0000023;
            param_5 = (uint *)CONCAT44(param_5._4_4_,(uint)param_5);
          }
          else {
            param_2[0xb] = param_2[0xb] | 0x20;
            uVar3 = 0;
            *param_2 = 0x38;
            param_2[0xc] = uVar9;
            *puVar2 = 0x38;
            param_5 = (uint *)CONCAT44(param_5._4_4_,(uint)param_5);
          }
        }
        else {
          *(undefined8 *)(param_2 + 4) = _DAT_fffff78000000014;
          param_2[0xf] = (uint)param_5;
          *param_2 = uVar9;
          plVar8 = plVar4;
          uVar6 = PcQueryGuidData((longlong)puVar5,(longlong)plVar4,*(uint *)(param_3 + 0x10),
                                  (uint *)((ulonglong)param_2[0xe] + (longlong)param_2),
                                  (uint)param_5);
          uVar3 = (uint)uVar6;
          param_5 = (uint *)CONCAT44(param_5._4_4_,(uint)param_5);
          if (-1 < (int)uVar3) {
            *puVar2 = uVar9;
            param_5 = (uint *)CONCAT44(param_5._4_4_,(uint)param_5);
          }
        }
      }
    }
    else if (param_1 == 2) {
      plVar8 = plVar4;
      uVar3 = PcQuerySetMiniport((longlong)puVar5,(longlong)plVar4,*(uint *)(param_3 + 0x10),
                                 (int *)((ulonglong)param_2[0xe] + (longlong)param_2),param_2[0xf]);
    }
    if (puVar5 != (undefined8 *)0x0) {
      PcpLineDereference((longlong)puVar5);
    }
    if (plVar4 != (longlong *)0x0) {
      PcpDereferenceFlow(plVar4,(ulonglong)plVar8);
    }
  }
  return uVar3;
}



===== PcpStartWmi @ 1400209c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PcpStartWmi(void)

{
  int iVar1;
  
  PcgGlobalTcLine = 0;
  iVar1 = PcpCreateDevice();
  if (-1 < iVar1) {
    *(uint *)(PcgDeviceObject + 0x30) = *(uint *)(PcgDeviceObject + 0x30) & 0xffffff7f;
    iVar1 = IoWMIRegistrationControl(PcgDeviceObject,1);
    if (iVar1 < 0) {
      NdisDeregisterDeviceEx(PcgNdisDeviceHandle);
      PcgDeviceObject = 0;
      PcgNdisDeviceHandle = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_9e00e2476b2b307411c622e7ad3d4b5d_Traceguids,iVar1);
      }
    }
    else {
      _PcgInitializedModules = _PcgInitializedModules | 4;
      LOCK();
      PcgDriverReference = PcgDriverReference + 1;
      UNLOCK();
    }
  }
  return iVar1;
}



===== PcpStopWmi @ 140020a90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopWmi(void)

{
  if (PcgGlobalTcLine != (longlong *)0x0) {
    PcpLineDestroy(PcgGlobalTcLine);
    PcgGlobalTcLine = (longlong *)0x0;
  }
  IoWMIRegistrationControl(PcgDeviceObject,2);
  NdisDeregisterDeviceEx(PcgNdisDeviceHandle);
  PcgDeviceObject = 0;
  PcgNdisDeviceHandle = 0;
  _PcgInitializedModules = _PcgInitializedModules & 0xfffffffffffffffb;
  PcpDereferenceDriver();
  return;
}



===== PcpWmiDisableEvents @ 140020b04 =====

undefined8 PcpWmiDisableEvents(longlong *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong local_res10 [3];
  
  uVar3 = 0;
  local_res10[0] = 0;
  uVar2 = PcpWmiGetGuid(local_res10,param_1,0);
  if ((int)uVar2 < 0) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar1 = *(uint *)(local_res10[0] + 0x18);
    if ((uVar1 & 2) == 0) {
      uVar3 = 0xc0000010;
    }
    else if (-1 < (char)uVar1) {
      *(uint *)(local_res10[0] + 0x18) = uVar1 & 0xffffffdf;
    }
  }
  return uVar3;
}



===== PcpWmiEnableEvents @ 140020b58 =====

undefined8 PcpWmiEnableEvents(longlong *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong local_res10 [3];
  
  uVar2 = 0;
  local_res10[0] = 0;
  uVar1 = PcpWmiGetGuid(local_res10,param_1,0);
  if ((int)uVar1 < 0) {
    uVar2 = 0xc000000d;
  }
  else if ((*(uint *)(local_res10[0] + 0x18) & 2) == 0) {
    uVar2 = 0xc0000010;
  }
  else {
    *(uint *)(local_res10[0] + 0x18) = *(uint *)(local_res10[0] + 0x18) | 0x20;
  }
  return uVar2;
}



===== PcpWmiRegister @ 140020ba8 =====

undefined8 PcpWmiRegister(longlong param_1,uint *param_2,uint param_3,uint *param_4)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined2 *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  undefined8 uVar10;
  
  uVar10 = 0;
  *param_4 = 0;
  if (param_1 == 0) {
    uVar7 = PcgRegistryPath + 0x33e;
    if (param_3 < uVar7) {
      *param_2 = uVar7;
      *param_4 = 4;
      return 0xc0000023;
    }
    *param_4 = uVar7;
    memset(param_2,0,(ulonglong)uVar7);
    lVar5 = 0x18;
    *param_2 = uVar7;
    param_2[4] = 0x18;
    puVar4 = (undefined8 *)&PcgSupportedGuids;
    puVar9 = param_2 + 6;
    do {
      puVar8 = puVar9;
      uVar2 = *puVar4;
      uVar3 = puVar4[1];
      puVar4 = (undefined8 *)((longlong)puVar4 + 0x1c);
      *(undefined8 *)puVar8 = uVar2;
      *(undefined8 *)(puVar8 + 2) = uVar3;
      puVar9 = puVar8 + 8;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    param_2[2] = (int)puVar9 - (int)param_2;
    *(ushort *)puVar9 = PcgRegistryPath;
    memmove((ushort *)((longlong)puVar8 + 0x22),DAT_1400196f8,(ulonglong)PcgRegistryPath);
    puVar6 = (undefined2 *)((ulonglong)PcgRegistryPath + (longlong)puVar8 + 0x22);
    param_2[3] = (int)puVar6 - (int)param_2;
    *puVar6 = 0x22;
    pwVar1 = puVar6 + 1;
    pwVar1[0] = L'P';
    pwVar1[1] = L's';
    pwVar1[2] = L'c';
    pwVar1[3] = L'h';
    pwVar1 = puVar6 + 5;
    pwVar1[0] = L'e';
    pwVar1[1] = L'd';
    pwVar1[2] = L'M';
    pwVar1[3] = L'o';
    pwVar1 = puVar6 + 9;
    pwVar1[0] = L'f';
    pwVar1[1] = L'R';
    pwVar1[2] = L'e';
    pwVar1[3] = L's';
    pwVar1 = puVar6 + 0xd;
    pwVar1[0] = L'o';
    pwVar1[1] = L'u';
    pwVar1[2] = L'r';
    pwVar1[3] = L'c';
    puVar6[0x11] = 0x65;
  }
  else {
    uVar10 = 0xc000000d;
  }
  return uVar10;
}



===== PcpStartTrace @ 140020cb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PcpStartTrace(void)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = EtwRegister(&QOS_EVENT_PROVIDER_PACER,PcpEtwCallback,0,&PcgEventTraceHandle);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (Microsoft_Windows_Networking_CorrelationHandle == 0) {
    uVar1 = EtwRegister(&Microsoft_Windows_Networking_CorrelationId,
                        Microsoft_Windows_Networking_Correlation_EtwEnableCallback,0,
                        &Microsoft_Windows_Networking_CorrelationHandle);
    if (uVar1 != 0) {
      if ((int)uVar1 < 0) {
        EtwUnregister(PcgEventTraceHandle);
        PcgEventTraceHandle = 0;
        return (ulonglong)uVar1;
      }
      goto LAB_140020d44;
    }
  }
  _Microsoft_Windows_Networking_ProviderId = 0x4addb70d914ed502;
  uRam0000000140019598 = 0xa3f85428699558b7;
LAB_140020d44:
  _PcgInitializedModules = _PcgInitializedModules | 0x10;
  return 0;
}



===== PcpStopTrace @ 140020d60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopTrace(void)

{
  EtwUnregister(Microsoft_Windows_Networking_CorrelationHandle);
  Microsoft_Windows_Networking_CorrelationHandle = 0;
  EtwUnregister(PcgEventTraceHandle);
  PcgEventTraceHandle = 0;
  _PcgInitializedModules = _PcgInitializedModules & 0xffffffffffffffef;
  return;
}



===== PcpStartPacerCounters @ 140020db0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PcpStartPacerCounters(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 *local_30;
  code *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_44 = 0;
  local_34 = 0;
  local_18 = 0;
  local_40 = &`InitRegistrationInformationPacerPipeCounterSet'::__l2::Name;
  local_48 = 0x200;
  local_30 = &`InitRegistrationInformationPacerPipeCounterSet'::__l2::Descriptors;
  local_38 = 0x11;
  local_28 = PcpCounterSetCallback;
  local_20 = 1;
  uVar1 = PcwRegister(&PacerPipeCounterSet,&local_48);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar4;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar4;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0) {
      return uVar4;
    }
    uVar3 = 10;
  }
  else {
    local_44 = 0;
    local_34 = 0;
    local_18 = 0;
    local_40 = &`InitRegistrationInformationPacerFlowCounterSet'::__l2::Name;
    local_30 = &`InitRegistrationInformationPacerFlowCounterSet'::__l2::Descriptors;
    local_48 = 0x200;
    local_38 = 0x14;
    local_28 = PcpCounterSetCallback;
    local_20 = 2;
    uVar2 = PcwRegister(&PacerFlowCounterSet,&local_48);
    uVar4 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      _PcgInitializedModules = _PcgInitializedModules | 0x20;
      return uVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar4;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar4;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0) {
      return uVar4;
    }
    uVar3 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_e4aa2b4349c93ac3ba2a1816a17e4e5b_Traceguids,(int)uVar4);
  return uVar4;
}



===== PcpStopPacerCounters @ 140020f10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopPacerCounters(void)

{
  PcwUnregister(PacerPipeCounterSet);
  PcwUnregister(PacerFlowCounterSet);
  _PcgInitializedModules = _PcgInitializedModules & 0xffffffffffffffdf;
  return;
}



===== PcpDisableRegistryNotification @ 140020f50 =====

void PcpDisableRegistryNotification(void)

{
  KeWaitForSingleObject(&PcgRegistryStateLock,0,0,0,0);
  if (PcgPolicyKeyHandle != 0) {
    ZwClose();
    PcgPolicyKeyHandle = 0;
  }
  KeSetEvent(&PcgRegistryStateLock,0,0);
  KeWaitForSingleObject(&PcgRegistryCompletionEvent,0,0,0,0);
  return;
}



===== PcpQueryIfRegistryHiveExists @ 140020fdc =====

bool PcpQueryIfRegistryHiveExists(undefined1 *param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 local_res8 [8];
  ulonglong in_stack_ffffffffffffffc8;
  undefined *puVar3;
  
  local_res8[0] = 0;
  *param_1 = 0;
  iVar1 = ZwQueryValueKey(PcgPolicyKeyHandle,&PcgRegistryKeySoftwareHive,2,0,
                          in_stack_ffffffffffffffc8 & 0xffffffff00000000,local_res8);
  if (iVar1 == -0x3fffffdd) {
    bVar2 = true;
  }
  else {
    puVar3 = &PcgPolicyIosb;
    iVar1 = ZwNotifyChangeKey(PcgPolicyKeyHandle,0,&PcgPolicyNotifyCallbackWorkItem,1,&PcgPolicyIosb
                              ,4,0,0,0,1);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_47bed8e3521e399cbed58f7190fbbb6f_Traceguids,iVar1);
      }
    }
    else {
      *param_1 = 1;
    }
    iVar1 = ZwQueryValueKey(PcgPolicyKeyHandle,&PcgRegistryKeySoftwareHive,2,0,
                            (ulonglong)puVar3 & 0xffffffff00000000,local_res8);
    bVar2 = iVar1 == -0x3fffffdd;
  }
  return bVar2;
}



===== PcpRegistryNotificationCallback @ 140021100 =====

void PcpRegistryNotificationCallback(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char local_res10 [24];
  
  local_res10[0] = '\0';
  bVar1 = true;
  iVar3 = KeWaitForSingleObject(&PcgRegistryStateLock,0,0,0,0);
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_47bed8e3521e399cbed58f7190fbbb6f_Traceguids,iVar3);
    }
  }
  else if (PcgPolicyKeyHandle == 0) {
    KeSetEvent(&PcgRegistryStateLock,0,0);
  }
  else {
    bVar2 = PcpQueryIfRegistryHiveExists(local_res10);
    if (bVar2) {
      PcpProcessSettingsChange();
    }
    if ((local_res10[0] == '\0') || (bVar1 = false, bVar2)) {
      ZwClose(PcgPolicyKeyHandle);
      PcgPolicyKeyHandle = 0;
    }
    KeSetEvent(&PcgRegistryStateLock,0,0);
    if (!bVar1) {
      return;
    }
  }
  KeSetEvent(&PcgRegistryCompletionEvent,0,0);
  return;
}



===== PcpStartRegistryNotification @ 140021230 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PcpStartRegistryNotification(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char local_res8 [8];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_34 = 0;
  bVar1 = true;
  local_res8[0] = '\0';
  KeInitializeEvent(&PcgRegistryStateLock,1,1);
  KeInitializeEvent(&PcgRegistryCompletionEvent,0,0);
  _DAT_140019618 = 0;
  _PcgPolicyNotifyCallbackWorkItem = 0;
  local_30 = 0;
  _DAT_140019610 = PcpRegistryNotificationCallback;
  local_38 = 0x30;
  local_28 = &PcgRegistryKeyHiveList;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar3 = ZwOpenKey(&PcgPolicyKeyHandle,0x20019,&local_38);
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_47bed8e3521e399cbed58f7190fbbb6f_Traceguids,iVar3);
    }
  }
  else {
    bVar2 = PcpQueryIfRegistryHiveExists(local_res8);
    if (bVar2) {
      PcpProcessSettingsChange();
    }
    else {
      if (local_res8[0] == '\0') goto LAB_140021341;
      bVar1 = false;
    }
    if (local_res8[0] != '\0') goto LAB_140021359;
  }
LAB_140021341:
  KeSetEvent(&PcgRegistryCompletionEvent,0,0);
LAB_140021359:
  if (bVar1) {
    PcpDisableRegistryNotification();
  }
  else {
    _PcgInitializedModules = _PcgInitializedModules | 0x40;
  }
  return 0;
}



===== PcpStopRegistryNotification @ 140021390 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PcpStopRegistryNotification(void)

{
  PcpDisableRegistryNotification();
  _PcgInitializedModules = _PcgInitializedModules & 0xffffffffffffffbf;
  return;
}



===== PcpReadSettings @ 1400213b0 =====

void PcpReadSettings(longlong param_1,uint *param_2)

{
  char cVar1;
  int local_res8 [2];
  undefined4 local_res10 [2];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58 [3];
  undefined4 local_40;
  
  local_res8[0] = -1;
  local_res10[0] = 0;
  *param_2 = 0xffff;
  local_40 = 0;
  param_2[10] = 0;
  param_2[3] = 1;
  param_2[4] = 0;
  param_2[1] = 0x50;
  param_2[2] = 0;
  param_2[5] = 0;
  param_2[6] = 0xc0a06000;
  *(undefined8 *)((longlong)param_2 + 0x1e) = 0;
  *(undefined2 *)(param_2 + 7) = 0;
  *(undefined2 *)((longlong)param_2 + 0x26) = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  if (param_1 != 0) {
    local_58[1] = 0x1801a9;
    local_40 = 0;
    local_58[2] = param_1;
    local_res10[0] = NdisOpenConfigurationEx(local_58 + 1,local_58);
  }
  cVar1 = PcpReadRegistryUlong(local_58[0],0x1400190e8,param_2,1,0xffffffff,0,local_res8,0);
  if (cVar1 == '\0') {
    if (*param_2 == 0) {
      *param_2 = 0xffff;
    }
  }
  else {
    *(undefined1 *)((longlong)param_2 + 0x2b) = 1;
  }
  PcpReadRegistryUlong(local_58[0],0x1400190f8,param_2 + 1,0,100,0x50,local_res8,0);
  local_res20 = 0;
  if (local_58[0] != 0) {
    NdisOpenConfigurationKeyByName(local_res10,local_58[0],&PcRegKeyDiffservConf);
  }
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019058,local_res18,0,0x3f,0,local_res8,0x140019098);
  *(char *)((longlong)param_2 + 0x1d) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019108,local_res18,0,0x3f,0,local_res8,0x140019098);
  *(char *)(param_2 + 6) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x1400190b8,local_res18,0,0x3f,0x18,local_res8,0x140019098);
  *(char *)((longlong)param_2 + 0x19) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019078,local_res18,0,0x3f,0x28,local_res8,0x140019098);
  *(char *)((longlong)param_2 + 0x1a) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x1400190d8,local_res18,0,0x3f,0,local_res8,0x140019098);
  *(char *)(param_2 + 7) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019068,local_res18,0,0x3f,0x30,local_res8,0x140019098);
  *(char *)((longlong)param_2 + 0x1b) = (char)local_res18[0] << 2;
  if (local_res20 != 0) {
    NdisCloseConfiguration();
  }
  local_res20 = 0;
  if (local_58[0] != 0) {
    NdisOpenConfigurationKeyByName(local_res10,local_58[0],&PcRegKeyDiffservNonConf);
  }
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019058,local_res18,0,0x3f,0,local_res8,0x1400190c8);
  *(char *)((longlong)param_2 + 0x23) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019108,local_res18,0,0x3f,0,local_res8,0x1400190c8);
  *(char *)((longlong)param_2 + 0x1e) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x1400190b8,local_res18,0,0x3f,0,local_res8,0x1400190c8);
  *(char *)((longlong)param_2 + 0x1f) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019078,local_res18,0,0x3f,0,local_res8,0x1400190c8);
  *(char *)(param_2 + 8) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x1400190d8,local_res18,0,0x3f,0,local_res8,0x1400190c8);
  *(char *)((longlong)param_2 + 0x22) = (char)local_res18[0] << 2;
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019068,local_res18,0,0x3f,0,local_res8,0x1400190c8);
  *(char *)((longlong)param_2 + 0x21) = (char)local_res18[0] << 2;
  if (local_res20 != 0) {
    NdisCloseConfiguration();
  }
  local_res20 = 0;
  if (local_58[0] != 0) {
    NdisOpenConfigurationKeyByName(local_res10,local_58[0],&PcRegKeyUserPriority);
  }
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019058,local_res18,0,7,0,local_res8,0x1400190a8);
  *(char *)((longlong)param_2 + 0x29) = (char)local_res18[0];
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019108,local_res18,0,7,0,local_res8,0x1400190a8);
  *(char *)(param_2 + 9) = (char)local_res18[0];
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x1400190b8,local_res18,0,7,0,local_res8,0x1400190a8);
  *(char *)((longlong)param_2 + 0x25) = (char)local_res18[0];
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019078,local_res18,0,7,0,local_res8,0x1400190a8);
  *(char *)((longlong)param_2 + 0x26) = (char)local_res18[0];
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x1400190d8,local_res18,0,7,0,local_res8,0x1400190a8);
  *(char *)(param_2 + 10) = (char)local_res18[0];
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019068,local_res18,0,7,0,local_res8,0x1400190a8);
  *(char *)((longlong)param_2 + 0x27) = (char)local_res18[0];
  local_res18[0] = 0;
  PcpReadRegistryUlong(local_res20,0x140019048,local_res18,0,7,0,local_res8,0x1400190a8);
  *(char *)((longlong)param_2 + 0x2a) = (char)local_res18[0];
  if (local_res20 != 0) {
    NdisCloseConfiguration();
  }
  if (local_58[0] != 0) {
    NdisCloseConfiguration();
  }
  return;
}



===== PcpReadRegistryUlong @ 140021a30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
PcpReadRegistryUlong
          (longlong param_1,longlong param_2,uint *param_3,uint param_4,uint param_5,uint param_6,
          int *param_7,longlong param_8)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined1 auStack_178 [32];
  int local_148;
  uint local_144;
  longlong local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined *local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined1 local_f8 [8];
  undefined4 local_f0;
  undefined8 local_e8;
  uint *local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  uint *local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  uVar3 = 0;
  local_140 = 0;
  local_148 = 0;
  if (param_1 == 0) {
    local_148 = -0x3fffffff;
  }
  else {
    NdisReadConfiguration(&local_148,&local_140,param_1,param_2);
  }
  if (local_148 == 0) {
    uVar2 = *(uint *)(local_140 + 8);
    if ((param_4 <= uVar2) && (uVar2 <= param_5)) {
      uVar3 = 1;
      param_6 = uVar2;
    }
    *param_3 = param_6;
  }
  else if (*param_7 == 0) {
    *param_3 = param_6;
  }
  else {
    local_144 = param_6;
    memset(local_f8,0,0xa8);
    local_d0 = 0;
    local_c8 = 0;
    if (param_8 == 0) {
      local_e8 = *(undefined8 *)(param_2 + 8);
      local_e0 = &local_144;
      local_f0 = 0x24;
      local_d8 = 4;
    }
    else {
      local_e8 = *(undefined8 *)(param_8 + 8);
      local_b0 = *(undefined8 *)(param_2 + 8);
      local_a8 = &local_144;
      local_f0 = 1;
      local_e0 = (uint *)0x0;
      local_d8 = 0;
      local_c0 = 0;
      local_b8 = 0x24;
      local_a0 = 4;
      local_98 = 0;
      local_90 = 0;
    }
    iVar1 = RtlQueryRegistryValuesEx(0,PTR_u__Registry_Machi_140019090,local_f8,0);
    if (((iVar1 < 0) || (local_144 < param_4)) || (param_5 < local_144)) {
      *param_3 = param_6;
      if (*param_7 != -1) {
        return 0;
      }
      local_138 = 0;
      local_130 = 0x30;
      puVar4 = &local_130;
      local_120 = &PcRegKeyMachine;
      local_118 = 0x240;
      local_128 = 0;
      local_110 = 0;
      uStack_108 = 0;
      uVar2 = ZwOpenKey(&local_138,0x80000000);
      if ((int)uVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) {
          WPP_SF_Zd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar2,puVar4,
                    (wchar_t *)&PcRegKeyMachine,(char)uVar2);
        }
        *param_7 = 0;
        return 0;
      }
      ZwClose(local_138);
    }
    else {
      *param_3 = local_144;
      uVar3 = 1;
    }
    *param_7 = 1;
  }
  return uVar3;
}



===== PcFilterRestart @ 140021cb0 =====

int PcFilterRestart(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 uVar7;
  int local_res8 [2];
  undefined1 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res8[0] = 0;
  *(undefined4 *)(param_1 + 0x18) = 3;
  iVar3 = 0;
  uVar7 = 1;
  *(undefined4 *)(param_1 + 0x80) = 1;
  lVar6 = param_2;
  NdisResetEvent(param_1 + 0x88);
  puVar4 = *(undefined8 **)(param_2 + 0x10);
  if (puVar4 == (undefined8 *)0x0) {
LAB_140021dce:
    QosLineRestart(*(longlong *)(param_1 + 0xa0) + 0x18);
    uVar7 = 2;
    PcpTraceLineUpDownEvent(*(longlong *)(param_1 + 0xa0) + 0x128);
  }
  else {
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4) {
      if ((*(int *)(puVar4 + 1) == 0x1021d) && (0x57 < *(uint *)((longlong)puVar4 + 0xc))) {
        if (puVar4 != (undefined8 *)0xfffffffffffffff0) {
          if (*(int *)(param_1 + 0x10) == 3) {
            *(int *)((longlong)puVar4 + 0x54) = *(int *)((longlong)puVar4 + 0x54) + 8;
          }
          iVar3 = PcpMakeNdisRequest(param_1,lVar6,param_3,local_res8);
          if (iVar3 != 0) goto LAB_140021d0c;
          uVar1 = puVar4[3];
          uVar5 = uVar1;
          if (uVar1 != 0xffffffffffffffff) {
            uVar2 = *(ulonglong *)(*(longlong *)(param_1 + 0xa0) + 0x20);
            uVar5 = uVar1 >> 3;
            if (uVar1 >> 3 <= uVar2) {
              uVar5 = uVar2;
            }
          }
          PcpLineUpdate(*(longlong *)(param_1 + 0xa0),0,0,(undefined8 *)0x0,uVar5,
                        *(int *)((longlong)puVar4 + 0x14),local_res8[0],in_stack_ffffffffffffffc0,
                        in_stack_ffffffffffffffc8,-1,0xffffffff);
          goto LAB_140021dce;
        }
        break;
      }
    }
    iVar3 = -0x3ffffff0;
LAB_140021d0c:
    PcpFilterDecrementPauseCount(param_1,1);
    NdisWaitEvent(param_1 + 0x88,0);
  }
  *(undefined4 *)(param_1 + 0x18) = uVar7;
  return iVar3;
}



===== PcpMakeNdisRequest @ 140021e58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PcpMakeNdisRequest(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined1 local_40 [24];
  int local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(&local_138,0,0x118);
  NdisInitializeEvent(local_40);
  local_134 = 0;
  local_138 = 0xf80196;
  local_118 = 0x10111;
  local_108 = 4;
  local_110 = param_4;
  PcpFilterIncrementDetachCount(param_1);
  iVar1 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x28),&local_138);
  if (iVar1 == 0x103) {
    NdisWaitEvent(local_40,0);
    iVar1 = local_28;
  }
  PcpFilterDecrementDetachCount(param_1);
  return iVar1;
}



===== PcpDispatch @ 140021f40 =====

int PcpDispatch(undefined8 param_1,longlong param_2)

{
  char cVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint local_res10 [2];
  
  plVar2 = *(longlong **)(param_2 + 0xb8);
  uVar6 = 0;
  local_res10[0] = 0;
  cVar1 = (char)*plVar2;
  if (cVar1 == '\0') {
    iVar3 = PcpCreateFileHandle((longlong)plVar2);
  }
  else {
    if (cVar1 == '\x02') {
      ExFreePoolWithTag(*(undefined8 *)(plVar2[6] + 0x18),0);
      iVar3 = 0;
      goto LAB_140021fcd;
    }
    if ((cVar1 == '\x0e') || (cVar1 == '\x0f')) {
      uVar5 = PcpDispatchIoctl(param_2,plVar2,(int *)local_res10);
      iVar3 = (int)uVar5;
      uVar6 = local_res10[0];
    }
    else {
      if (cVar1 != '\x12') {
        iVar3 = -0x3ffffffe;
        goto LAB_140021fcd;
      }
      uVar4 = PcpCleanupFileHandle((longlong)plVar2);
      iVar3 = (int)uVar4;
    }
  }
  if (iVar3 == 0x103) {
    return 0x103;
  }
LAB_140021fcd:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
  *(int *)(param_2 + 0x30) = iVar3;
  IofCompleteRequest(param_2,2);
  return iVar3;
}



===== PcpDispatchIoctl @ 140022000 =====

ulonglong PcpDispatchIoctl(longlong param_1,longlong *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  undefined4 extraout_var_05;
  undefined4 extraout_var_06;
  undefined4 extraout_var_07;
  undefined4 extraout_var_08;
  undefined4 extraout_var_09;
  undefined4 extraout_var_10;
  undefined4 extraout_var_11;
  
  iVar2 = (int)param_2[3];
  if (iVar2 == 0x128000) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      iVar2 = PcpIoctlAddFilter(param_1,param_2,param_3);
      uVar4 = CONCAT44(extraout_var_11,iVar2);
    }
    else {
      iVar2 = PcpIoctlAddFilter32(param_1,param_2,param_3);
      uVar4 = CONCAT44(extraout_var_10,iVar2);
    }
  }
  else if (iVar2 == 0x128004) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      iVar2 = PcpIoctlDeleteFilter(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_09,iVar2);
    }
    else {
      iVar2 = PcpIoctlDeleteFilter32(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_08,iVar2);
    }
  }
  else if (iVar2 == 0x128008) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      iVar2 = PcpIoctlAddFlow(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_07,iVar2);
    }
    else {
      iVar2 = PcpIoctlAddFlow32(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_06,iVar2);
    }
  }
  else if (iVar2 == 0x12800c) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      uVar3 = PcpIoctlDeleteFlow(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_05,uVar3);
    }
    else {
      uVar4 = PcpIoctlDeleteFlow32(param_1,(longlong)param_2,param_3);
    }
  }
  else if (iVar2 == 0x128010) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      iVar2 = PcpIoctlRegisterClient(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_04,iVar2);
    }
    else {
      iVar2 = PcpIoctlRegisterClient32(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_03,iVar2);
    }
  }
  else if (iVar2 == 0x128014) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      uVar4 = PcpIoctlDeregisterClient(param_1,(longlong)param_2,param_3);
    }
    else {
      uVar4 = PcpIoctlDeregisterClient32(param_1,(longlong)param_2,param_3);
    }
  }
  else if (iVar2 == 0x128018) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      uVar3 = PcpIoctlEnumerateFlow(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_02,uVar3);
    }
    else {
      uVar3 = PcpIoctlEnumerateFlow32(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_01,uVar3);
    }
  }
  else if (iVar2 == 0x12801c) {
    cVar1 = IoIs32bitProcess();
    if (cVar1 == '\0') {
      iVar2 = PcpIoctlModifyFlow(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var_00,iVar2);
    }
    else {
      iVar2 = PcpIoctlModifyFlow32(param_1,(longlong)param_2,param_3);
      uVar4 = CONCAT44(extraout_var,iVar2);
    }
  }
  else if (iVar2 == 0x128050) {
    uVar4 = PcpIoctlZawEvent();
  }
  else {
    uVar4 = 0xc0000002;
  }
  return uVar4;
}



===== PcpIoctlModifyFlow32 @ 1400221e0 =====

int PcpIoctlModifyFlow32(longlong param_1,longlong param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ushort local_res8 [4];
  ushort local_res10 [8];
  undefined4 local_res20 [2];
  longlong *local_48 [2];
  
  piVar1 = *(int **)(param_1 + 0x18);
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_48[0] = (longlong *)0x0;
  if (*(uint *)(param_2 + 8) < 0xc) {
    return -0x3fffffdd;
  }
  if (*(uint *)(param_2 + 0x10) < 0x25c) {
    iVar3 = -0x3fffffdd;
LAB_14002223d:
    *param_3 = 0xc;
  }
  else {
    if ((ulonglong)*(uint *)(param_2 + 0x10) < (ulonglong)(uint)piVar1[0x96] + 0x25c) {
      iVar3 = -0x3ffdff7a;
      goto LAB_14002223d;
    }
    if (piVar1[2] != piVar1[0x96] + 0x250U) {
      iVar3 = -0x3ffffff3;
      goto LAB_14002223d;
    }
    if (piVar1[1] == 0) {
      iVar3 = -0x3ffffddb;
      goto LAB_14002223d;
    }
    uVar4 = PcpValidateFlowByHandle32
                      (piVar1[1],*(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18),
                       (longlong *)local_48);
    plVar2 = local_48[0];
    iVar3 = (int)uVar4;
    if (-1 < iVar3) {
      uVar4 = PcpUpdateFlow(local_48[0],0,piVar1[2],1,(ulonglong *)(piVar1 + 3),'\0',0,local_res20,
                            local_res10,local_res8);
      uVar5 = uVar4 & 0xffffffff;
      iVar3 = (int)uVar4;
      PcpTraceUpdateFlowEvent(plVar2,iVar3,1);
      piVar1[2] = *(int *)((longlong)plVar2 + 0x264);
      piVar1[1] = (int)plVar2[0x4a];
      PcpDereferenceFlow(plVar2,uVar5);
    }
    *param_3 = 0xc;
    if (-1 < iVar3) goto LAB_140022344;
  }
  piVar1[1] = 0;
  piVar1[2] = 0;
LAB_140022344:
  *piVar1 = iVar3;
  return iVar3;
}



===== PcpIoctlModifyFlow @ 140022360 =====

int PcpIoctlModifyFlow(longlong param_1,longlong param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ushort local_res8 [4];
  ushort local_res10 [8];
  undefined4 local_res20 [2];
  longlong *local_48 [2];
  
  piVar1 = *(int **)(param_1 + 0x18);
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_48[0] = (longlong *)0x0;
  if (*(uint *)(param_2 + 8) < 0x18) {
    return -0x3fffffdd;
  }
  if (*(uint *)(param_2 + 0x10) < 0x264) {
    iVar3 = -0x3fffffdd;
LAB_1400223b9:
    *param_3 = 0x18;
  }
  else {
    if ((ulonglong)*(uint *)(param_2 + 0x10) < (ulonglong)(uint)piVar1[0x98] + 0x264) {
      iVar3 = -0x3ffdff7a;
      goto LAB_1400223b9;
    }
    if (piVar1[4] != piVar1[0x98] + 0x250U) {
      iVar3 = -0x3ffffff3;
      goto LAB_1400223b9;
    }
    if (*(longlong *)(piVar1 + 2) == 0) {
      iVar3 = -0x3ffffddb;
      goto LAB_1400223b9;
    }
    uVar4 = PcpValidateFlowByHandle32
                      (piVar1[2],*(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18),
                       (longlong *)local_48);
    plVar2 = local_48[0];
    iVar3 = (int)uVar4;
    if (-1 < iVar3) {
      uVar4 = PcpUpdateFlow(local_48[0],0,piVar1[4],1,(ulonglong *)(piVar1 + 5),'\0',0,local_res20,
                            local_res10,local_res8);
      uVar5 = uVar4 & 0xffffffff;
      iVar3 = (int)uVar4;
      PcpTraceUpdateFlowEvent(plVar2,iVar3,1);
      *(ulonglong *)(piVar1 + 4) = (ulonglong)*(uint *)((longlong)plVar2 + 0x264);
      *(longlong *)(piVar1 + 2) = plVar2[0x4a];
      PcpDereferenceFlow(plVar2,uVar5);
    }
    *param_3 = 0x18;
    if (-1 < iVar3) goto LAB_1400224c7;
  }
  piVar1[0] = 0;
  piVar1[1] = 0;
  piVar1[2] = 0;
  piVar1[3] = 0;
  piVar1[4] = 0;
  piVar1[5] = 0;
LAB_1400224c7:
  *piVar1 = iVar3;
  return iVar3;
}



===== PcFilterPnPEvent @ 1400224f0 =====

void PcFilterPnPEvent(longlong param_1)

{
  NdisFNetPnPEvent(*(undefined8 *)(param_1 + 0x28));
  return;
}



===== PcFilterPnPEventNotify @ 140022510 =====

void PcFilterPnPEventNotify(longlong param_1)

{
  NdisFDevicePnPEventNotify(*(undefined8 *)(param_1 + 0x28));
  return;
}



===== entry @ 140023010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140023044 =====

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



===== wil_InitializeFeatureStaging @ 140023078 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140023168 =====

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


