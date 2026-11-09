
===== UfsSendUicDmePeerGet @ 140001010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint UfsSendUicDmePeerGet(longlong *param_1,int param_2,ushort param_3,uint *param_4)

{
  ulonglong uVar1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined8 local_70;
  wchar_t *local_68;
  ulonglong local_60;
  wchar_t *local_58;
  ulonglong local_50;
  wchar_t *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  ulonglong local_30;
  uint local_28 [2];
  uint local_20 [4];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  local_20[0] = param_2 << 0x10 | (uint)param_3;
  *param_4 = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_28[0] = 0;
  uVar1 = UfsExecuteUicCommandSynchronous(param_1,3,local_20,local_28);
  local_30 = uVar1 & 0xffffffff;
  if ((int)uVar1 == 0) {
    *param_4 = local_20[2];
  }
  else {
    if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
      local_60 = (ulonglong)*param_4;
      local_50 = (ulonglong)local_20[0];
      local_38 = L"status";
      local_40 = 1;
      local_48 = L"errorStatus";
      local_58 = L"args0";
      local_68 = L"Value";
      local_70 = 0;
      local_78 = 0;
      local_80 = 3;
      local_88 = 1;
      local_90 = L"Sending of DmePeerGet command failed.";
      local_98 = 2;
      StorPortExtendedFunction(0x56,param_1,0);
    }
    local_28[0] = 1;
  }
  return local_28[0];
}



===== UfsIntelLkfLifelineCheck @ 140001170 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsIntelLkfLifelineCheck(longlong *param_1,uint param_2)

{
  longlong *plVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  uint *puVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  longlong lVar14;
  bool bVar15;
  undefined1 local_e8 [32];
  undefined8 local_c8;
  wchar_t *local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  ulonglong local_90;
  wchar_t *local_88;
  ulonglong local_80;
  wchar_t *pwStack_78;
  ulonglong uStack_70;
  wchar_t *pwStack_68;
  ulonglong uStack_60;
  uint local_58;
  char local_54 [12];
  longlong local_48;
  uint local_40;
  ulonglong local_3c;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_e8;
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) == 0) {
    return 0;
  }
  if (param_2 != 0) {
    uVar6 = 1000;
    if (param_2 < 0x3e9) {
      uVar6 = (ulonglong)param_2;
    }
    if ((int)uVar6 != 0) {
      do {
        StorPortStallExecution(1000);
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  lVar14 = *param_1;
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 2;
  iVar5 = 0;
  local_3c = 0;
  local_40 = 0x15aa0000;
  LOCK();
  iVar2 = (int)param_1[0x19d];
  if (iVar2 == 0) {
    *(int *)(param_1 + 0x19d) = 1;
  }
  else {
    iVar5 = iVar2;
  }
  UNLOCK();
  local_48 = lVar14;
  if (iVar5 == 1) {
    uVar10 = 0xc1000001;
  }
  else {
    *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 2;
    puVar8 = &local_40;
    lVar13 = 3;
    lVar9 = 0;
    do {
      *(uint *)(lVar14 + 0x94 + lVar9) = *puVar8;
      LOCK();
      UNLOCK();
      lVar9 = lVar9 + 4;
      puVar8 = puVar8 + 1;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      LOCK();
      plVar1 = param_1 + 0x345;
      lVar9 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      puVar7 = (undefined8 *)
               ((ulonglong)(*(uint *)((longlong)param_1 + 0x1a2c) & (int)lVar9 - 1U) * 0x20 +
               param_1[0x346]);
      param_1[0x347] = (longlong)puVar7;
      *puVar7 = 0x53434955;
      puVar7[1] = 3;
      puVar7[2] = 0x15aa0000;
      puVar7[3] = 0;
    }
    if ((*(uint *)(param_1 + 0x193) & 0x20000) != 0) {
      local_80 = 1;
      local_88 = L"Synchronous";
      local_90 = 3;
      local_98 = L"Opcode";
      local_a0 = 0;
      local_a8 = 0;
      local_b0 = 4;
      local_b8 = 1;
      local_c0 = L"Sending UIC cmd.";
      local_c8 = CONCAT44(local_c8._4_4_,2);
      StorPortExtendedFunction(0x55,param_1,0);
    }
    *(undefined4 *)(lVar14 + 0x90) = 3;
    LOCK();
    UNLOCK();
    uVar11 = 0;
    if ((int)param_1[0x1ca] * 100 != 0) {
      do {
        lVar14 = *param_1;
        local_58 = ~*(uint *)(lVar14 + 0x24) & *(uint *)(lVar14 + 0x20);
        *(uint *)(lVar14 + 0x20) = local_58;
        LOCK();
        UNLOCK();
        cVar3 = UfsHandleBusError(param_1,&local_58);
        if (cVar3 != '\0') {
          *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
          local_c0 = (wchar_t *)local_54;
          local_c8 = 0;
          local_54[0] = '\0';
          local_54[1] = '\0';
          local_54[2] = '\0';
          local_54[3] = '\0';
          StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0);
          if ((local_54[0] == '\0') && ((*(uint *)(param_1 + 0x193) & 0x8000) != 0)) {
            uVar6 = FUN_140010e28();
            return uVar6;
          }
        }
        uVar10 = 0xffffffff;
        if (((*(uint *)(param_1 + 0x1b5) & 1) != 0) ||
           (((*(uint *)(param_1 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_1 + 0xda4) == 0))))
        {
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
            uVar10 = *(uint *)(param_1[0x12e] + 0x14);
          }
          uVar10 = uVar10 & *(uint *)((longlong)param_1 + 0x4f4) & *(uint *)(param_1 + 0x9f) &
                   *(uint *)((longlong)param_1 + 0x4fc);
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
            *(uint *)(param_1[0x12e] + 0x14) = uVar10;
            LOCK();
            UNLOCK();
          }
          else {
            uVar10 = uVar10 & ~*(uint *)(param_1[0x12e] + 8);
          }
          uVar4 = *(uint *)(param_1 + 0xa0);
          do {
            LOCK();
            uVar12 = *(uint *)(param_1 + 0xa0);
            bVar15 = uVar4 == uVar12;
            if (bVar15) {
              *(uint *)(param_1 + 0xa0) = uVar4 | uVar10;
            }
            else {
              uVar4 = uVar12;
            }
            UNLOCK();
          } while (!bVar15);
          if (((~uVar4 & uVar10) != 0) && (uVar12 = 0, (int)param_1[0x12d] != 0)) {
            do {
              if (((~uVar4 & uVar10) >> (uVar12 & 0x1f) & 1) != 0) {
                UfsCompleteTransferRequest(param_1,uVar12,local_58);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < *(uint *)(param_1 + 0x12d));
          }
        }
        uVar10 = 0xffffffff;
        if (((*(uint *)(param_1 + 0x1b5) & 1) != 0) ||
           (((*(uint *)(param_1 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_1 + 0xda4) == 0))))
        {
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
            uVar10 = *(uint *)(param_1[0x92] + 0x14);
          }
          uVar10 = uVar10 & *(uint *)((longlong)param_1 + 0x14) & *(uint *)(param_1 + 3) &
                   *(uint *)((longlong)param_1 + 0x1c);
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
            *(uint *)(param_1[0x92] + 0x14) = uVar10;
            LOCK();
            UNLOCK();
          }
          else {
            uVar10 = uVar10 & ~*(uint *)(param_1[0x92] + 8);
          }
          uVar4 = *(uint *)(param_1 + 4);
          do {
            LOCK();
            uVar12 = *(uint *)(param_1 + 4);
            bVar15 = uVar4 == uVar12;
            if (bVar15) {
              *(uint *)(param_1 + 4) = uVar4 | uVar10;
            }
            else {
              uVar4 = uVar12;
            }
            UNLOCK();
          } while (!bVar15);
          if (((~uVar4 & uVar10) != 0) && (uVar12 = 0, (int)param_1[0x91] != 0)) {
            do {
              if (((~uVar4 & uVar10) >> (uVar12 & 0x1f) & 1) != 0) {
                UfsCompleteTaskManRequest(param_1,uVar12);
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < *(uint *)(param_1 + 0x91));
          }
        }
        if ((local_58 >> 10 & 1) != 0) {
          LOCK();
          if ((int)param_1[0x19d] == 1) {
            *(int *)(param_1 + 0x19d) = 0;
          }
          UNLOCK();
        }
        if ((local_58 & 0x40) != 0) {
          LOCK();
          *(undefined4 *)((longlong)param_1 + 0xdac) = 1;
          UNLOCK();
        }
        if ((local_58 & 0x20) != 0) {
          LOCK();
          *(undefined4 *)((longlong)param_1 + 0xdac) = 0;
          UNLOCK();
        }
        if ((local_58 & 0x10) != 0) {
          *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 8;
        }
        if ((int)param_1[0x19d] == 0) break;
        StorPortStallExecution(10);
        uVar11 = uVar11 + 1;
      } while (uVar11 < (uint)((int)param_1[0x1ca] * 100));
      lVar14 = local_48;
    }
    uVar10 = 0;
    if ((0 < (int)param_1[0x19d]) || (uVar11 == (int)param_1[0x1ca] * 100)) {
      uVar10 = 0xc1000001;
    }
    lVar9 = 3;
    puVar8 = &local_40;
    do {
      *puVar8 = *(uint *)((lVar14 - (longlong)&local_40) + 0x90 + (longlong)(puVar8 + 1));
      lVar9 = lVar9 + -1;
      puVar8 = puVar8 + 1;
    } while (lVar9 != 0);
    local_90 = local_3c & 0xff;
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      LOCK();
      plVar1 = param_1 + 0x345;
      lVar14 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      puVar7 = (undefined8 *)
               ((ulonglong)(*(uint *)((longlong)param_1 + 0x1a2c) & (int)lVar14 - 1U) * 0x20 +
               param_1[0x346]);
      param_1[0x347] = (longlong)puVar7;
      puVar7[2] = (ulonglong)local_40;
      puVar7[3] = local_3c & 0xff;
      *puVar7 = 0x43434955;
      puVar7[1] = 3;
    }
    *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffffffd;
    LOCK();
    if ((int)param_1[0x19d] == 1) {
      *(int *)(param_1 + 0x19d) = 0;
    }
    UNLOCK();
    if (uVar10 == 0) {
LAB_1400014ad:
      if ((char)local_3c == '\0') {
        return 0;
      }
      return 0xc1000001;
    }
    if ((*(uint *)(param_1 + 0x193) & 0x8000) == 0) {
      if (uVar10 == 0) goto LAB_1400014ad;
    }
    else {
      uStack_60 = 0;
      pwStack_68 = (wchar_t *)0x0;
      uStack_70 = (ulonglong)uVar10;
      pwStack_78 = L"status";
      local_80 = 3;
      local_88 = L"UicOpcode";
      local_98 = L"ErrorCode";
      local_a0 = 0;
      local_a8 = 0;
      local_b0 = 3;
      local_b8 = 1;
      local_c0 = L"Synchronous UIC command failed.";
      local_c8 = CONCAT44(local_c8._4_4_,2);
      StorPortExtendedFunction(0x56,param_1,0);
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    local_80 = (ulonglong)local_40;
    uStack_60 = (ulonglong)uVar10;
    pwStack_68 = L"status";
    uStack_70 = 1;
    pwStack_78 = L"errorStatus";
    local_88 = L"args0";
    local_90 = 0;
    local_98 = L"Value";
    local_a0 = 0;
    local_a8 = 0;
    local_b0 = 3;
    local_b8 = 1;
    local_c0 = L"Sending of DmePeerGet command failed.";
    local_c8 = CONCAT44(local_c8._4_4_,2);
    StorPortExtendedFunction(0x56,param_1,0);
  }
  return 0xc1000001;
}



===== UfsExecuteUicCommandSynchronous @ 1400017c0 =====

ulonglong UfsExecuteUicCommandSynchronous
                    (longlong *param_1,uint param_2,uint *param_3,uint *param_4)

{
  longlong *plVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  uint *puVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  longlong lVar14;
  bool bVar15;
  uint local_res8 [2];
  undefined4 local_58;
  uint local_54;
  longlong local_48;
  
  lVar14 = *param_1;
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 2;
  iVar4 = 0;
  uVar6 = (ulonglong)param_2;
  LOCK();
  iVar2 = (int)param_1[0x19d];
  if (iVar2 == 0) {
    *(int *)(param_1 + 0x19d) = 1;
  }
  else {
    iVar4 = iVar2;
  }
  UNLOCK();
  if (iVar4 == 1) {
    return 0xc1000001;
  }
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 2;
  if (param_3 != (uint *)0x0) {
    lVar10 = 0;
    lVar13 = 3;
    puVar8 = param_3;
    do {
      *(uint *)(lVar10 + 0x94 + lVar14) = *puVar8;
      LOCK();
      UNLOCK();
      lVar10 = lVar10 + 4;
      puVar8 = puVar8 + 1;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
  }
  uVar11 = param_3[2];
  uVar9 = *param_3;
  if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
    LOCK();
    plVar1 = param_1 + 0x345;
    lVar10 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    puVar7 = (undefined8 *)
             ((ulonglong)(*(uint *)((longlong)param_1 + 0x1a2c) & (int)lVar10 - 1U) * 0x20 +
             param_1[0x346]);
    param_1[0x347] = (longlong)puVar7;
    *puVar7 = 0x53434955;
    puVar7[1] = uVar6;
    puVar7[2] = (ulonglong)uVar9;
    puVar7[3] = (ulonglong)uVar11;
  }
  local_48 = lVar14;
  if ((*(uint *)(param_1 + 0x193) & 0x20000) != 0) {
    StorPortExtendedFunction
              (0x55,param_1,0,0,2,L"Sending UIC cmd.",1,4,0,0,L"Opcode",uVar6,L"Synchronous",1);
  }
  *(uint *)(lVar14 + 0x90) = param_2;
  LOCK();
  UNLOCK();
  local_54 = 0;
  uVar11 = 0;
  if ((int)param_1[0x1ca] * 100 != 0) {
    do {
      lVar14 = *param_1;
      local_res8[0] = ~*(uint *)(lVar14 + 0x24) & *(uint *)(lVar14 + 0x20);
      *(uint *)(lVar14 + 0x20) = local_res8[0];
      LOCK();
      UNLOCK();
      cVar3 = UfsHandleBusError(param_1,local_res8);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
        local_58 = 0;
        StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0,0,&local_58);
        if (((char)local_58 == '\0') && ((*(uint *)(param_1 + 0x193) & 0x8000) != 0)) {
          uVar6 = FUN_1400110aa();
          return uVar6;
        }
      }
      uVar9 = 0xffffffff;
      if (((*(uint *)(param_1 + 0x1b5) & 1) != 0) ||
         (((*(uint *)(param_1 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_1 + 0xda4) == 0)))) {
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
          uVar9 = *(uint *)(param_1[0x12e] + 0x14);
        }
        uVar9 = uVar9 & *(uint *)((longlong)param_1 + 0x4f4) & *(uint *)(param_1 + 0x9f) &
                *(uint *)((longlong)param_1 + 0x4fc);
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
          *(uint *)(param_1[0x12e] + 0x14) = uVar9;
          LOCK();
          UNLOCK();
        }
        else {
          uVar9 = uVar9 & ~*(uint *)(param_1[0x12e] + 8);
        }
        uVar5 = *(uint *)(param_1 + 0xa0);
        do {
          LOCK();
          uVar12 = *(uint *)(param_1 + 0xa0);
          bVar15 = uVar5 == uVar12;
          if (bVar15) {
            *(uint *)(param_1 + 0xa0) = uVar5 | uVar9;
          }
          else {
            uVar5 = uVar12;
          }
          UNLOCK();
        } while (!bVar15);
        if (((~uVar5 & uVar9) != 0) && (uVar12 = 0, (int)param_1[0x12d] != 0)) {
          do {
            if (((~uVar5 & uVar9) >> (uVar12 & 0x1f) & 1) != 0) {
              UfsCompleteTransferRequest(param_1,uVar12,local_res8[0]);
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < *(uint *)(param_1 + 0x12d));
        }
      }
      uVar9 = 0xffffffff;
      if (((*(uint *)(param_1 + 0x1b5) & 1) != 0) ||
         (((*(uint *)(param_1 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_1 + 0xda4) == 0)))) {
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
          uVar9 = *(uint *)(param_1[0x92] + 0x14);
        }
        uVar9 = uVar9 & *(uint *)((longlong)param_1 + 0x14) & *(uint *)(param_1 + 3) &
                *(uint *)((longlong)param_1 + 0x1c);
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
          *(uint *)(param_1[0x92] + 0x14) = uVar9;
          LOCK();
          UNLOCK();
        }
        else {
          uVar9 = uVar9 & ~*(uint *)(param_1[0x92] + 8);
        }
        uVar5 = *(uint *)(param_1 + 4);
        do {
          LOCK();
          uVar12 = *(uint *)(param_1 + 4);
          bVar15 = uVar5 == uVar12;
          if (bVar15) {
            *(uint *)(param_1 + 4) = uVar5 | uVar9;
          }
          else {
            uVar5 = uVar12;
          }
          UNLOCK();
        } while (!bVar15);
        if (((~uVar5 & uVar9) != 0) && (uVar12 = 0, (int)param_1[0x91] != 0)) {
          do {
            if (((~uVar5 & uVar9) >> (uVar12 & 0x1f) & 1) != 0) {
              UfsCompleteTaskManRequest(param_1,uVar12);
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < *(uint *)(param_1 + 0x91));
        }
      }
      if ((local_res8[0] >> 10 & 1) != 0) {
        LOCK();
        if ((int)param_1[0x19d] == 1) {
          *(int *)(param_1 + 0x19d) = 0;
        }
        UNLOCK();
      }
      if ((local_res8[0] & 0x40) != 0) {
        LOCK();
        *(undefined4 *)((longlong)param_1 + 0xdac) = 1;
        UNLOCK();
      }
      if ((local_res8[0] & 0x20) != 0) {
        LOCK();
        *(undefined4 *)((longlong)param_1 + 0xdac) = 0;
        UNLOCK();
      }
      if ((local_res8[0] & 0x10) != 0) {
        *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 8;
      }
      if (param_2 == 0x18) {
        iVar2 = *(int *)((longlong)param_1 + 0xdac);
LAB_140001a5c:
        if (iVar2 == 0) goto LAB_140001a5e;
      }
      else {
        if (param_2 == 0x17) {
          iVar2 = *(int *)((longlong)param_1 + 0xdac) + -1;
          goto LAB_140001a5c;
        }
LAB_140001a5e:
        if ((int)param_1[0x19d] == 0) break;
      }
      StorPortStallExecution(10);
      uVar11 = uVar11 + 1;
    } while (uVar11 < (uint)((int)param_1[0x1ca] * 100));
    lVar14 = local_48;
  }
  if ((0 < (int)param_1[0x19d]) || (uVar9 = local_54, uVar11 == (int)param_1[0x1ca] * 100)) {
    uVar9 = 0xc1000001;
  }
  lVar10 = 3;
  puVar8 = param_3;
  do {
    *puVar8 = *(uint *)((longlong)puVar8 + (lVar14 - (longlong)param_3) + 0x94);
    lVar10 = lVar10 + -1;
    puVar8 = puVar8 + 1;
  } while (lVar10 != 0);
  if (param_4 != (uint *)0x0) {
    *param_4 = param_3[1] & 0xff;
  }
  uVar11 = param_3[1];
  uVar5 = *param_3;
  if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
    LOCK();
    plVar1 = param_1 + 0x345;
    lVar14 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    puVar7 = (undefined8 *)
             ((ulonglong)(*(uint *)((longlong)param_1 + 0x1a2c) & (int)lVar14 - 1U) * 0x20 +
             param_1[0x346]);
    param_1[0x347] = (longlong)puVar7;
    *puVar7 = 0x43434955;
    puVar7[1] = uVar6;
    puVar7[2] = (ulonglong)uVar5;
    puVar7[3] = (ulonglong)(uVar11 & 0xff);
  }
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffffffd;
  LOCK();
  if ((int)param_1[0x19d] == 1) {
    *(int *)(param_1 + 0x19d) = 0;
  }
  UNLOCK();
  if ((uVar9 != 0) && ((*(uint *)(param_1 + 0x193) & 0x8000) != 0)) {
    StorPortExtendedFunction
              (0x56,param_1,0,1,2,L"Synchronous UIC command failed.",1,3,0,0,L"ErrorCode",*param_4,
               L"UicOpcode",uVar6,L"status",uVar9,0,0);
  }
  return (ulonglong)uVar9;
}



===== UfsInterrupt @ 140001d90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 UfsInterrupt(longlong *param_1)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined7 extraout_var;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined1 local_d8 [32];
  undefined8 *local_b8;
  uint *local_b0;
  char local_a8 [4];
  uint local_a4 [2];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_d8;
  lVar1 = *param_1;
  if (*(uint *)(lVar1 + 0x20) == 0) {
    return 0;
  }
  local_a4[0] = *(uint *)(lVar1 + 0x20) & *(uint *)(lVar1 + 0x24);
  *(uint *)(lVar1 + 0x20) = local_a4[0];
  LOCK();
  UNLOCK();
  if ((local_a4[0] & 0x400) != 0) {
    local_b0 = &local_98;
    local_98 = 0;
    local_b8 = (undefined8 *)0x0;
    StorPortNotification(0x1002,param_1,param_1 + 0x19e,0);
  }
  uVar5 = (ulonglong)*(uint *)(param_1 + 0x1a8);
  if (*(uint *)(param_1 + 0x1a8) != 1) {
    cVar2 = UfsHandleBusError(param_1,local_a4);
    uVar5 = CONCAT71(extraout_var,cVar2);
    if (cVar2 != '\0') {
      *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
      local_b0 = &local_9c;
      local_b8 = (undefined8 *)0x0;
      local_9c = 0;
      uVar5 = StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0);
      if ((char)local_9c == '\0') goto LAB_140001ec9;
    }
    uVar6 = local_a4[0];
    uVar9 = 0xffffffff;
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      if ((local_a4[0] & 1) != 0) {
        local_b0 = &local_94;
        local_94 = 0;
        local_b8 = (undefined8 *)0x0;
        uVar5 = StorPortNotification(0x1002,param_1,param_1 + 0x124,local_a4[0]);
      }
    }
    else {
      local_90 = 5;
      local_b8 = &local_90;
      local_88 = 0;
      local_80 = 0;
      uStack_78 = 0;
      StorPortExtendedFunction(0x5d,param_1,5);
      uVar6 = local_a4[0];
      uVar8 = 0xffffffff;
      if (((*(uint *)(param_1 + 0x1b5) & 1) != 0) ||
         ((((*(uint *)(param_1 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_1 + 0xda4) == 0)) &&
          ((int)param_1[0x1a8] != 1)))) {
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
          uVar8 = *(uint *)(param_1[0x12e] + 0x14);
        }
        uVar8 = uVar8 & *(uint *)((longlong)param_1 + 0x4f4) & ~*(uint *)(param_1 + 0x9f) &
                *(uint *)((longlong)param_1 + 0x4fc);
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
          *(uint *)(param_1[0x12e] + 0x14) = uVar8;
          LOCK();
          UNLOCK();
        }
        else {
          uVar8 = uVar8 & ~*(uint *)(param_1[0x12e] + 8);
        }
        uVar3 = *(uint *)(param_1 + 0xa0);
        do {
          LOCK();
          uVar7 = *(uint *)(param_1 + 0xa0);
          bVar10 = uVar3 == uVar7;
          if (bVar10) {
            *(uint *)(param_1 + 0xa0) = uVar3 | uVar8;
          }
          else {
            uVar3 = uVar7;
          }
          UNLOCK();
        } while (!bVar10);
        if ((~uVar3 & uVar8) != 0) {
          for (uVar7 = 0; uVar7 < *(uint *)(param_1 + 0x12d); uVar7 = uVar7 + 1) {
            local_a8[0] = '\0';
            StorPortExtendedFunction(0x6d,param_1,local_a8);
            if (local_a8[0] == '\x02') {
              local_40 = 0;
              local_50 = 0;
              uStack_48 = 0;
              iVar4 = StorPortExtendedFunction(0x6a,param_1,&local_50);
              if (iVar4 == 0) {
                bVar10 = true;
                if ((int)uStack_48 != 0) {
                  bVar10 = true;
                  if ((uint)(uStack_48._4_4_ * 100) < (uint)((int)uStack_48 * 5)) {
                    bVar10 = false;
                  }
                }
                if ((((int)local_50 != 0) &&
                    ((uint)(local_50._4_4_ * 100) < (uint)((int)local_50 * 5))) || (!bVar10)) {
                  *(int *)(param_1 + 0x34b) = (int)param_1[0x34b] + 1;
                  break;
                }
              }
            }
            if (((~uVar3 & uVar8) >> (uVar7 & 0x1f) & 1) != 0) {
              UfsCompleteTransferRequest(param_1,uVar7,uVar6);
            }
          }
        }
      }
      uVar5 = StorPortNotification(0x1004,param_1,&local_90);
    }
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      if ((uVar6 >> 9 & 1) != 0) {
        local_b0 = local_a4 + 1;
        local_b8 = (undefined8 *)0x0;
        local_a4[1] = 0;
        uVar5 = StorPortNotification(0x1002,param_1,param_1 + 0x88,uVar6);
      }
    }
    else {
      local_70 = 5;
      local_68 = 0;
      local_b8 = &local_70;
      local_60 = 0;
      uStack_58 = 0;
      StorPortExtendedFunction(0x5d,param_1,5);
      if (((*(uint *)(param_1 + 0x1b5) & 1) != 0) ||
         ((((*(uint *)(param_1 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_1 + 0xda4) == 0)) &&
          ((int)param_1[0x1a8] != 1)))) {
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
          uVar9 = *(uint *)(param_1[0x92] + 0x14);
        }
        uVar9 = uVar9 & *(uint *)((longlong)param_1 + 0x14) & ~*(uint *)(param_1 + 3) &
                *(uint *)((longlong)param_1 + 0x1c);
        if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
           ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
          *(uint *)(param_1[0x92] + 0x14) = uVar9;
          LOCK();
          UNLOCK();
        }
        else {
          uVar9 = uVar9 & ~*(uint *)(param_1[0x92] + 8);
        }
        uVar6 = *(uint *)(param_1 + 4);
        do {
          LOCK();
          uVar8 = *(uint *)(param_1 + 4);
          bVar10 = uVar6 == uVar8;
          if (bVar10) {
            *(uint *)(param_1 + 4) = uVar6 | uVar9;
          }
          else {
            uVar6 = uVar8;
          }
          UNLOCK();
        } while (!bVar10);
        if (((~uVar6 & uVar9) != 0) && (uVar8 = 0, (int)param_1[0x91] != 0)) {
          do {
            if (((~uVar6 & uVar9) >> (uVar8 & 0x1f) & 1) != 0) {
              UfsCompleteTaskManRequest(param_1,uVar8);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(uint *)(param_1 + 0x91));
        }
      }
      uVar5 = StorPortNotification(0x1004,param_1,&local_70);
      uVar6 = local_a4[0];
    }
    if ((uVar6 >> 10 & 1) != 0) {
      local_b0 = local_a4 + 1;
      local_a4[1] = 0;
      local_b8 = (undefined8 *)0x0;
      uVar5 = StorPortNotification(0x1002,param_1,param_1 + 0x19e,0);
    }
    if ((uVar6 & 0x10) != 0) {
      *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 8;
    }
  }
LAB_140001ec9:
  return (int)CONCAT71((int7)(uVar5 >> 8),1);
}



===== UfsCompleteTransferDpc @ 140002310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UfsCompleteTransferDpc(undefined8 param_1,longlong *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_a8 [32];
  undefined8 *local_88;
  char local_78 [8];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_a8;
  local_70 = 5;
  local_68 = 0;
  local_88 = &local_70;
  local_60 = 0;
  uStack_58 = 0;
  StorPortExtendedFunction(0x5d,param_2,5,param_1);
  uVar3 = 0xffffffff;
  if (((*(uint *)(param_2 + 0x1b5) & 1) != 0) ||
     ((((*(uint *)(param_2 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_2 + 0xda4) == 0)) &&
      ((int)param_2[0x1a8] != 1)))) {
    if (((*(uint *)((longlong)param_2 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_2 + 0x12f) & 1) == 0)) {
      uVar3 = *(uint *)(param_2[0x12e] + 0x14);
    }
    uVar3 = uVar3 & *(uint *)((longlong)param_2 + 0x4f4) & ~*(uint *)(param_2 + 0x9f) &
            *(uint *)((longlong)param_2 + 0x4fc);
    if (((*(uint *)((longlong)param_2 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_2 + 0x12f) & 1) == 0)) {
      *(uint *)(param_2[0x12e] + 0x14) = uVar3;
      LOCK();
      UNLOCK();
    }
    else {
      uVar3 = uVar3 & ~*(uint *)(param_2[0x12e] + 8);
    }
    uVar1 = *(uint *)(param_2 + 0xa0);
    do {
      LOCK();
      uVar4 = *(uint *)(param_2 + 0xa0);
      bVar5 = uVar1 == uVar4;
      if (bVar5) {
        *(uint *)(param_2 + 0xa0) = uVar1 | uVar3;
      }
      else {
        uVar1 = uVar4;
      }
      UNLOCK();
    } while (!bVar5);
    if ((~uVar1 & uVar3) != 0) {
      for (uVar4 = 0; uVar4 < *(uint *)(param_2 + 0x12d); uVar4 = uVar4 + 1) {
        local_78[0] = '\0';
        StorPortExtendedFunction(0x6d,param_2,local_78);
        if (local_78[0] == '\x02') {
          local_40 = 0;
          local_50 = 0;
          uStack_48 = 0;
          iVar2 = StorPortExtendedFunction(0x6a,param_2,&local_50);
          if (iVar2 == 0) {
            bVar5 = true;
            if ((int)uStack_48 != 0) {
              bVar5 = true;
              if ((uint)(uStack_48._4_4_ * 100) < (uint)((int)uStack_48 * 5)) {
                bVar5 = false;
              }
            }
            if ((((int)local_50 != 0) && ((uint)(local_50._4_4_ * 100) < (uint)((int)local_50 * 5)))
               || (!bVar5)) {
              *(int *)(param_2 + 0x34b) = (int)param_2[0x34b] + 1;
              break;
            }
          }
        }
        if (((~uVar1 & uVar3) >> (uVar4 & 0x1f) & 1) != 0) {
          UfsCompleteTransferRequest(param_2,uVar4,param_3);
        }
      }
    }
  }
  StorPortNotification(0x1004,param_2,&local_70);
  return;
}



===== UfsCompleteTransferRequest @ 140002560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UfsCompleteTransferRequest(longlong *param_1,uint param_2,uint param_3)

{
  longlong *plVar1;
  uint *puVar2;
  uint uVar3;
  char cVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  byte bVar10;
  ushort uVar11;
  int iVar12;
  undefined8 *puVar13;
  wchar_t *pwVar14;
  uint uVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  longlong lVar18;
  bool bVar19;
  undefined1 local_128 [32];
  undefined8 *local_108;
  wchar_t *local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  wchar_t *local_d8;
  ulonglong local_d0;
  wchar_t *local_c8;
  undefined8 local_c0;
  undefined4 local_b8 [2];
  wchar_t *local_b0;
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined2 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)local_128;
  local_48 = 0;
  local_a0 = 0;
  local_88 = 0;
  local_80 = 0;
  local_b0 = L"Complete transfer request failed.";
  uVar17 = (ulonglong)param_2;
  lVar18 = uVar17 * 0x20;
  lVar9 = param_1[(ulonglong)param_2 * 2 + 0x133];
  local_78 = 0;
  uStack_70 = 0;
  lVar5 = param_1[(ulonglong)param_2 + 0x172];
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  puVar13 = (undefined8 *)(lVar9 + (ulonglong)*(ushort *)(param_1[0x130] + 0x1a + lVar18) * 4);
  if ((*(uint *)(param_1 + 0x193) & 0x2000) != 0) {
    local_78 = *puVar13;
    uStack_70 = puVar13[1];
    local_48 = *(undefined4 *)(puVar13 + 6);
    local_68 = puVar13[2];
    uStack_60 = puVar13[3];
    local_80 = *(undefined2 *)(lVar9 + 0x18);
    local_58 = puVar13[4];
    uStack_50 = puVar13[5];
    local_88 = *(undefined8 *)(lVar9 + 0x10);
  }
  uVar6 = *(uint *)(param_1[0x130] + 8 + lVar18) & 0xff;
  bVar10 = (byte)param_2;
  if (uVar6 == 0) {
    cVar4 = *(char *)((longlong)puVar13 + 7);
    if (cVar4 == '\0') {
      uVar16 = 1;
    }
    else if (cVar4 == '\x02') {
LAB_14000263a:
      uVar16 = 4;
    }
    else if (cVar4 == '\b') {
      uVar16 = 5;
    }
    else {
      if (cVar4 != '@') goto LAB_14000263a;
      *(int *)((longlong)param_1 + 0x1a64) = *(int *)((longlong)param_1 + 0x1a64) + 1;
      uVar16 = 2;
    }
  }
  else {
    if ((uVar6 - 7 & 0xfffffff7) != 0) goto LAB_14000263a;
    uVar16 = 4;
    if ((param_3 >> 0x11 & 1) == 0) {
      *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
      local_100 = (wchar_t *)local_a8;
      local_108 = (undefined8 *)0x0;
      local_a8[0] = 0;
      StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0);
    }
    else {
      *(int *)(*param_1 + 0x5c) = ~(1 << (bVar10 & 0x1f));
      LOCK();
      UNLOCK();
    }
  }
  if (lVar5 == 0) {
    local_90 = 0;
    if (((*(uint *)(param_1 + 0x12d) <= param_2) ||
        (uVar6 = 1 << (bVar10 & 0x1f), (uVar6 & *(uint *)((longlong)param_1 + 0x4f4)) == 0)) ||
       ((uVar6 & *(uint *)((longlong)param_1 + 0x4fc)) == 0)) {
LAB_140002965:
      local_d0 = 0xc1000006;
LAB_14000292b:
      pwVar14 = L"Complete transfer request release completion failed.";
      goto LAB_1400027af;
    }
    uVar15 = ~uVar6;
    uVar7 = *(uint *)((longlong)param_1 + 0x4f4);
    do {
      LOCK();
      uVar3 = *(uint *)((longlong)param_1 + 0x4f4);
      bVar19 = uVar7 == uVar3;
      if (bVar19) {
        *(uint *)((longlong)param_1 + 0x4f4) = uVar7 & uVar15;
      }
      else {
        uVar7 = uVar3;
      }
      UNLOCK();
    } while (!bVar19);
    LOCK();
    *(uint *)(param_1 + 0x9f) = *(uint *)(param_1 + 0x9f) & uVar15;
    UNLOCK();
    LOCK();
    *(uint *)((longlong)param_1 + 0x4fc) = *(uint *)((longlong)param_1 + 0x4fc) & uVar15;
    UNLOCK();
    LOCK();
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & uVar15;
    UNLOCK();
    if ((uVar7 & uVar6) == 0) goto LAB_140002965;
    puVar2 = (uint *)(lVar18 + 0x524 + (longlong)param_1);
    *puVar2 = *puVar2 | 1;
    if ((param_1 == (longlong *)0xfffffffffffffaf0) ||
       (param_1 + uVar17 * 4 + 0xa6 == (longlong *)0x0)) goto LAB_140002965;
    local_108 = &local_90;
    uVar6 = StorPortExtendedFunction(0x26,param_1);
    local_d0 = (ulonglong)uVar6;
    if (uVar6 != 0) goto LAB_14000292b;
    local_d0 = 0;
    pwVar14 = L"Complete transfer request failed.";
  }
  else {
    *(char *)(lVar5 + 3) = (char)uVar16;
    cVar4 = *(char *)((longlong)puVar13 + 7);
    *(char *)(lVar5 + 4) = cVar4;
    uVar6 = *(uint *)((longlong)puVar13 + 0xc);
    *(int *)(lVar5 + 0x10) =
         *(int *)(lVar5 + 0x10) -
         (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18);
    uVar11 = *(ushort *)(puVar13 + 4) >> 8 | *(ushort *)(puVar13 + 4) << 8;
    if ((uVar11 <= *(byte *)(lVar5 + 0xb)) && (cVar4 != '\0')) {
      memmove(*(void **)(lVar5 + 0x20),(void *)((longlong)puVar13 + 0x22),(ulonglong)uVar11);
      *(byte *)(lVar5 + 3) = *(byte *)(lVar5 + 3) | 0x80;
    }
    uVar8 = Feature_WriteBooster__private_IsEnabledDeviceUsageNoInline();
    if ((((((int)uVar8 != 0) && ((*(uint *)(param_1 + 0x193) & 0x4000) != 0)) &&
         (*(char *)(lVar5 + 0x48) == '*')) &&
        ((*(char *)(lVar5 + 3) == '\x01' && (1 < *(byte *)((longlong)param_1 + 0xdbc))))) &&
       (param_1[0x252] != 0)) {
      lVar9 = KeQueryInterruptTimePrecise(&local_a0);
      param_1[0x253] = lVar9 - param_1[0x252];
      param_1[0x254] = param_1[0x254] + (lVar9 - param_1[(ulonglong)param_2 + 0x1ea]);
      if ((ulonglong)param_1[0x251] <= (ulonglong)(lVar9 - param_1[0x252])) {
        StorPortDebugPrint(3,"StorUfs - Starting to transition P-state from %u\n",
                           *(undefined1 *)((longlong)param_1 + 0xdbd));
        local_100 = (wchar_t *)local_b8;
        *(undefined1 *)(param_1 + 0x255) = 1;
        local_108 = (undefined8 *)0x0;
        local_b8[0] = 0;
        StorPortNotification(0x1002,param_1,param_1 + 0x194,0);
        if ((char)local_b8[0] == '\0') {
          StorPortDebugPrint(0,"StorUfs - P-state request to transition failed.\n");
        }
        else {
          StorPortDebugPrint(3,"StorUfs - P-state request to transition issued.\n");
        }
      }
      if ((*(uint *)(param_1 + 0x1b7) & 1) == 0) {
        iVar12 = 0;
      }
      else {
        iVar12 = *(byte *)((longlong)param_1 + 0xdbc) - 1;
      }
      if ((int)(uint)*(byte *)((longlong)param_1 + 0xdbd) < iVar12) {
        UfsSetPStateTimer((longlong)param_1);
      }
    }
    if ((((*(uint *)((longlong)param_1 + 0xe24) & 0xe000000) != 0) && ((int)param_1[0x1e9] == 0)) &&
       (((*(uint *)(param_1 + 0x193) & 0x4000) == 0 &&
        (uVar8 = UfsWriteBoosterInitialize(param_1), (int)uVar8 == 0)))) {
      StorPortExtendedFunction(0x39,param_1,0,0xffffffff);
    }
    local_98 = 0;
    if (((param_2 < *(uint *)(param_1 + 0x12d)) &&
        (uVar6 = 1 << (bVar10 & 0x1f), (uVar6 & *(uint *)((longlong)param_1 + 0x4f4)) != 0)) &&
       ((uVar6 & *(uint *)((longlong)param_1 + 0x4fc)) != 0)) {
      uVar15 = ~uVar6;
      uVar7 = *(uint *)((longlong)param_1 + 0x4f4);
      do {
        LOCK();
        uVar3 = *(uint *)((longlong)param_1 + 0x4f4);
        bVar19 = uVar7 == uVar3;
        if (bVar19) {
          *(uint *)((longlong)param_1 + 0x4f4) = uVar7 & uVar15;
        }
        else {
          uVar7 = uVar3;
        }
        UNLOCK();
      } while (!bVar19);
      LOCK();
      *(uint *)(param_1 + 0x9f) = *(uint *)(param_1 + 0x9f) & uVar15;
      UNLOCK();
      LOCK();
      *(uint *)((longlong)param_1 + 0x4fc) = *(uint *)((longlong)param_1 + 0x4fc) & uVar15;
      UNLOCK();
      LOCK();
      *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & uVar15;
      UNLOCK();
      if ((uVar7 & uVar6) == 0) goto LAB_14000295b;
      puVar2 = (uint *)(lVar18 + 0x524 + (longlong)param_1);
      *puVar2 = *puVar2 | 1;
      if ((param_1 == (longlong *)0xfffffffffffffaf0) ||
         (param_1 + uVar17 * 4 + 0xa6 == (longlong *)0x0)) goto LAB_14000295b;
      local_108 = &local_98;
      uVar6 = StorPortExtendedFunction(0x26,param_1);
      local_d0 = (ulonglong)uVar6;
      if (uVar6 == 0) {
        local_d0 = 0;
      }
    }
    else {
LAB_14000295b:
      local_d0 = 0xc1000006;
    }
    pwVar14 = L"Complete transfer request release completion index failed.";
    if ((int)local_d0 == 0) {
      pwVar14 = L"Complete transfer request failed.";
    }
LAB_1400027af:
    local_b0 = pwVar14;
  }
  if ((*(uint *)(param_1 + 0x193) & 0x2000) == 0) {
    if (lVar5 == 0) goto LAB_1400027e7;
    if ((int)local_d0 == 0) goto LAB_140002942;
  }
  else {
    local_d0 = UfsHPBCheckForRegionUpdate((longlong)param_1,(longlong)&local_78,(char *)&local_88);
    local_d0 = local_d0 & 0xffffffff;
    if (lVar5 != 0) {
LAB_140002942:
      StorPortNotification(0,param_1,lVar5);
      goto LAB_1400027ef;
    }
    pwVar14 = local_b0;
LAB_1400027e7:
    if ((int)local_d0 == 0) goto LAB_1400027ef;
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    local_c8 = L"srbStatus";
    local_d8 = L"status";
    local_e0 = 0;
    local_e8 = 0;
    local_f0 = 2;
    local_f8 = 1;
    local_108 = (undefined8 *)CONCAT44(local_108._4_4_,0x15);
    local_100 = pwVar14;
    local_c0 = uVar16;
    StorPortExtendedFunction(0x55,param_1,0);
  }
LAB_1400027ef:
  if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
    LOCK();
    plVar1 = param_1 + 0x345;
    lVar9 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    puVar13 = (undefined8 *)
              ((ulonglong)(*(uint *)((longlong)param_1 + 0x1a2c) & (int)lVar9 - 1U) * 0x20 +
              param_1[0x346]);
    param_1[0x347] = (longlong)puVar13;
    *puVar13 = 0x6f437254;
    puVar13[1] = (ulonglong)param_2;
    puVar13[2] = lVar5;
    puVar13[3] = uVar16;
  }
  return;
}



===== UfsWaitForCompletedRequest @ 140002a80 =====

undefined8
UfsWaitForCompletedRequest
          (longlong *param_1,uint param_2,uint param_3,uint param_4,int param_5,longlong param_6)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  wchar_t *pwVar9;
  uint uVar10;
  bool bVar11;
  undefined4 local_res8 [2];
  uint local_res10 [2];
  
  lVar2 = *param_1;
  if ((param_2 == 0xffffffff) || (param_3 == 0xffffffff)) {
    uVar10 = 0;
    if (param_5 * 100 != 0) {
      do {
        uVar8 = 0;
        lVar3 = *param_1;
        local_res10[0] = ~*(uint *)(lVar3 + 0x24) & *(uint *)(lVar3 + 0x20);
        *(uint *)(lVar3 + 0x20) = local_res10[0];
        LOCK();
        UNLOCK();
        cVar4 = UfsHandleBusError(param_1,local_res10);
        if (cVar4 != '\0') {
          *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
          local_res8[0] = 0;
          StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0,0,local_res8);
          if (((char)local_res8[0] == '\0') && ((*(uint *)(param_1 + 0x193) & 0x8000) != 0)) {
            uVar5 = FUN_1400113fa();
            return uVar5;
          }
        }
        uVar6 = 0xffffffff;
        if (((*(uint *)(param_1 + 0x1b5) & 1) == 0) &&
           (((*(uint *)(param_1 + 0x1b5) & 4) != 0 || (*(int *)((longlong)param_1 + 0xda4) != 0))))
        {
          uVar6 = 0;
        }
        else {
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
            uVar6 = *(uint *)(param_1[0x12e] + 0x14);
          }
          uVar6 = uVar6 & *(uint *)((longlong)param_1 + 0x4f4) & *(uint *)(param_1 + 0x9f) &
                  *(uint *)((longlong)param_1 + 0x4fc);
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
            *(uint *)(param_1[0x12e] + 0x14) = uVar6;
            LOCK();
            UNLOCK();
          }
          else {
            uVar6 = uVar6 & ~*(uint *)(param_1[0x12e] + 8);
          }
          uVar7 = *(uint *)(param_1 + 0xa0);
          do {
            LOCK();
            uVar1 = *(uint *)(param_1 + 0xa0);
            bVar11 = uVar7 == uVar1;
            if (bVar11) {
              *(uint *)(param_1 + 0xa0) = uVar7 | uVar6;
            }
            else {
              uVar7 = uVar1;
            }
            UNLOCK();
          } while (!bVar11);
          uVar6 = ~uVar7 & uVar6;
          if ((uVar6 != 0) && ((int)param_1[0x12d] != 0)) {
            do {
              if ((uVar6 >> (uVar8 & 0x1f) & 1) != 0) {
                UfsCompleteTransferRequest(param_1,uVar8,local_res10[0]);
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint *)(param_1 + 0x12d));
          }
        }
        uVar7 = 0;
        uVar8 = 0xffffffff;
        if (((*(uint *)(param_1 + 0x1b5) & 1) != 0) ||
           (((*(uint *)(param_1 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_1 + 0xda4) == 0))))
        {
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
            uVar8 = *(uint *)(param_1[0x92] + 0x14);
          }
          uVar7 = uVar8 & *(uint *)((longlong)param_1 + 0x14) & *(uint *)(param_1 + 3) &
                  *(uint *)((longlong)param_1 + 0x1c);
          if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
             ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
            *(uint *)(param_1[0x92] + 0x14) = uVar7;
            LOCK();
            UNLOCK();
          }
          else {
            uVar7 = uVar7 & ~*(uint *)(param_1[0x92] + 8);
          }
          uVar8 = *(uint *)(param_1 + 4);
          do {
            LOCK();
            uVar1 = *(uint *)(param_1 + 4);
            bVar11 = uVar8 == uVar1;
            if (bVar11) {
              *(uint *)(param_1 + 4) = uVar8 | uVar7;
            }
            else {
              uVar8 = uVar1;
            }
            UNLOCK();
          } while (!bVar11);
          uVar7 = ~uVar8 & uVar7;
          if ((uVar7 != 0) && (uVar8 = 0, (int)param_1[0x91] != 0)) {
            do {
              if ((uVar7 >> (uVar8 & 0x1f) & 1) != 0) {
                UfsCompleteTaskManRequest(param_1,uVar8);
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint *)(param_1 + 0x91));
          }
        }
        if ((local_res10[0] >> 10 & 1) != 0) {
          LOCK();
          if ((int)param_1[0x19d] == 1) {
            *(int *)(param_1 + 0x19d) = 0;
          }
          UNLOCK();
        }
        if ((local_res10[0] & 0x40) != 0) {
          LOCK();
          *(undefined4 *)((longlong)param_1 + 0xdac) = 1;
          UNLOCK();
        }
        if ((local_res10[0] & 0x20) != 0) {
          LOCK();
          *(undefined4 *)((longlong)param_1 + 0xdac) = 0;
          UNLOCK();
        }
        if ((local_res10[0] & 0x10) != 0) {
          *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 8;
        }
        if (((param_2 != 0xffffffff) && ((uVar6 >> (param_2 & 0x1f) & 1) != 0)) ||
           ((param_3 != 0xffffffff && ((uVar7 >> (param_3 & 0x1f) & 1) != 0)))) break;
        StorPortStallExecution(10);
        uVar10 = uVar10 + 1;
      } while (uVar10 < (uint)(param_5 * 100));
    }
    if (uVar10 != param_5 * 100) {
      return 0;
    }
    pwVar9 = L"Completion of the transfer request failed with timeout.";
    if (param_2 == 0xffffffff) {
      if (param_3 != 0xffffffff) {
        uVar8 = 1 << ((byte)param_3 & 0x1f);
        *(uint *)(lVar2 + 0x7c) = ~uVar8 & 0xff;
        LOCK();
        UNLOCK();
        uVar10 = 0;
        do {
          if ((byte)((byte)uVar8 & (byte)*(undefined4 *)(lVar2 + 0x78)) != 0) break;
          uVar10 = uVar10 + 1;
        } while (uVar10 < 10);
        uVar5 = UfsReleaseCompletionIndex(param_1,(longlong)(param_1 + 2),param_3);
        pwVar9 = L"Completion of the transfer request failed while release completion index.";
        if ((int)uVar5 == 0) {
          pwVar9 = L"Completion of the transfer request failed with timeout.";
        }
      }
    }
    else {
      uVar5 = UfsSendTaskManRequest((longlong)param_1,param_2,param_4,1,0);
      pwVar9 = L"Completion of the transfer request failed during send task man request.";
      if ((int)uVar5 == 0) {
        pwVar9 = L"Completion of the transfer request failed with timeout.";
      }
      uVar8 = 1 << ((byte)param_2 & 0x1f);
      *(uint *)(lVar2 + 0x5c) = ~uVar8;
      LOCK();
      UNLOCK();
      uVar10 = 0;
      do {
        if ((*(uint *)(lVar2 + 0x58) & uVar8) != 0) break;
        uVar10 = uVar10 + 1;
      } while (uVar10 < 10);
      uVar5 = UfsReleaseCompletionIndex(param_1,(longlong)(param_1 + 0x9e),param_2);
      if ((int)uVar5 != 0) {
        pwVar9 = L"Completion of the transfer request failed while release completion index.";
      }
    }
    uVar5 = 0xc1000001;
    if (param_6 != 0) {
      *(undefined1 *)(param_6 + 3) = 9;
      pwVar9 = L"Completion of the transfer request failed with status timeout.";
    }
  }
  else {
    uVar5 = 0xc1000006;
    pwVar9 = L"Completion of the transfer request failed with invalid parameter.";
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x56,param_1,0,1,3,pwVar9,1,3,0,0,L"TrlIndex",param_2,L"Lun",param_4,L"status",uVar5,
               0,0);
  }
  return uVar5;
}



===== UfsPollForCompletion @ 140002e90 =====

void UfsPollForCompletion(longlong *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_res8 [2];
  undefined4 local_res10 [4];
  
  lVar2 = *param_1;
  local_res8[0] = ~*(uint *)(lVar2 + 0x24) & *(uint *)(lVar2 + 0x20);
  *(uint *)(lVar2 + 0x20) = local_res8[0];
  LOCK();
  UNLOCK();
  cVar3 = UfsHandleBusError(param_1,local_res8);
  if (cVar3 != '\0') {
    *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
    local_res10[0] = 0;
    StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0,0,local_res10);
    if (((char)local_res10[0] == '\0') && ((*(uint *)(param_1 + 0x193) & 0x8000) != 0)) {
      FUN_14001165a();
      return;
    }
  }
  uVar5 = 0xffffffff;
  uVar4 = 0xffffffff;
  if (((*(uint *)(param_1 + 0x1b5) & 1) == 0) &&
     (((*(uint *)(param_1 + 0x1b5) & 4) != 0 || (*(int *)((longlong)param_1 + 0xda4) != 0)))) {
    uVar4 = 0;
  }
  else {
    if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
      uVar4 = *(uint *)(param_1[0x12e] + 0x14);
    }
    uVar4 = uVar4 & *(uint *)((longlong)param_1 + 0x4f4) & *(uint *)(param_1 + 0x9f) &
            *(uint *)((longlong)param_1 + 0x4fc);
    if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_1 + 0x12f) & 1) == 0)) {
      *(uint *)(param_1[0x12e] + 0x14) = uVar4;
      LOCK();
      UNLOCK();
    }
    else {
      uVar4 = uVar4 & ~*(uint *)(param_1[0x12e] + 8);
    }
    uVar6 = *(uint *)(param_1 + 0xa0);
    do {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0xa0);
      bVar7 = uVar6 == uVar1;
      if (bVar7) {
        *(uint *)(param_1 + 0xa0) = uVar6 | uVar4;
      }
      else {
        uVar6 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
    uVar4 = ~uVar6 & uVar4;
    if ((uVar4 != 0) && (uVar6 = 0, (int)param_1[0x12d] != 0)) {
      do {
        if ((uVar4 >> (uVar6 & 0x1f) & 1) != 0) {
          UfsCompleteTransferRequest(param_1,uVar6,local_res8[0]);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x12d));
    }
  }
  if (((*(uint *)(param_1 + 0x1b5) & 1) == 0) &&
     (((*(uint *)(param_1 + 0x1b5) & 4) != 0 || (*(int *)((longlong)param_1 + 0xda4) != 0)))) {
    uVar5 = 0;
  }
  else {
    if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
      uVar5 = *(uint *)(param_1[0x92] + 0x14);
    }
    uVar5 = uVar5 & *(uint *)((longlong)param_1 + 0x14) & *(uint *)(param_1 + 3) &
            *(uint *)((longlong)param_1 + 0x1c);
    if (((*(uint *)((longlong)param_1 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_1 + 0x93) & 1) == 0)) {
      *(uint *)(param_1[0x92] + 0x14) = uVar5;
      LOCK();
      UNLOCK();
    }
    else {
      uVar5 = uVar5 & ~*(uint *)(param_1[0x92] + 8);
    }
    uVar6 = *(uint *)(param_1 + 4);
    do {
      LOCK();
      uVar1 = *(uint *)(param_1 + 4);
      bVar7 = uVar6 == uVar1;
      if (bVar7) {
        *(uint *)(param_1 + 4) = uVar6 | uVar5;
      }
      else {
        uVar6 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
    uVar5 = ~uVar6 & uVar5;
    if ((uVar5 != 0) && (uVar6 = 0, (int)param_1[0x91] != 0)) {
      do {
        if ((uVar5 >> (uVar6 & 0x1f) & 1) != 0) {
          UfsCompleteTaskManRequest(param_1,uVar6);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x91));
    }
  }
  if ((local_res8[0] >> 10 & 1) != 0) {
    LOCK();
    if ((int)param_1[0x19d] == 1) {
      *(int *)(param_1 + 0x19d) = 0;
    }
    UNLOCK();
  }
  if ((local_res8[0] & 0x40) != 0) {
    LOCK();
    *(undefined4 *)((longlong)param_1 + 0xdac) = 1;
    UNLOCK();
  }
  if ((local_res8[0] & 0x20) != 0) {
    LOCK();
    *(undefined4 *)((longlong)param_1 + 0xdac) = 0;
    UNLOCK();
  }
  if ((local_res8[0] & 0x10) != 0) {
    *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 8;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar4;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar5;
  }
  return;
}



===== UfsHandleBusError @ 140003230 =====

char UfsHandleBusError(longlong *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  
  cVar6 = '\0';
  lVar4 = *param_1;
  if ((*param_2 & 4) != 0) {
    *(int *)(param_1 + 0x349) = (int)param_1[0x349] + 1;
    *(int *)((longlong)param_1 + 0x1a74) = *(int *)((longlong)param_1 + 0x1a74) + 1;
    uVar1 = *(uint *)(lVar4 + 0x3c);
    if ((int)*(uint *)(lVar4 + 0x38) < 0) {
      uVar5 = (ulonglong)(*(uint *)(lVar4 + 0x38) & 0x1f);
      UfsAddDbgLog((longlong)param_1,0x45724877,(ulonglong)*param_2,1,uVar5);
      if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
        StorPortExtendedFunction
                  (0x55,param_1,0,1,0x11,L"Detected UFS Physical Layer error.",0x40,2,0,0,
                   L"PA Error Code",uVar5,0,0);
      }
    }
    if ((int)uVar1 < 0) {
      UfsAddDbgLog((longlong)param_1,0x45724877,(ulonglong)*param_2,2,(ulonglong)(uVar1 & 0x7fff));
      if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
        StorPortExtendedFunction
                  (0x55,param_1,0,1,0x11,L"Detected UFS Data Link error.",0x40,2,0,0,
                   L"DL Error Code",(ulonglong)(uVar1 & 0x7fff),0,0);
      }
      cVar6 = '\0';
      if ((uVar1 & 0x7fff) == 0x2000) {
        cVar6 = '\x01';
      }
    }
    uVar1 = *(uint *)(lVar4 + 0x48);
    uVar2 = *(uint *)(lVar4 + 0x40);
    uVar3 = *(uint *)(lVar4 + 0x44);
    UfsTelemetryHwError((longlong)param_1);
    if ((int)uVar2 < 0) {
      UfsAddDbgLog((longlong)param_1,0x45724877,(ulonglong)*param_2,3,(ulonglong)(uVar2 & 7));
      cVar6 = '\x01';
    }
    if ((int)uVar3 < 0) {
      UfsAddDbgLog((longlong)param_1,0x45724877,(ulonglong)*param_2,4,(ulonglong)(uVar3 & 0x7f));
      cVar6 = '\x01';
    }
    if ((int)uVar1 < 0) {
      UfsAddDbgLog((longlong)param_1,0x45724877,(ulonglong)*param_2,5,(ulonglong)(uVar1 & 1));
    }
  }
  uVar1 = *param_2;
  if ((uVar1 >> 0x10 & 1) != 0) {
    *(int *)(param_1 + 0x349) = (int)param_1[0x349] + 1;
    *(int *)((longlong)param_1 + 0x1a6c) = *(int *)((longlong)param_1 + 0x1a6c) + 1;
    UfsAddDbgLog((longlong)param_1,0x45724877,(ulonglong)uVar1,6,0);
    cVar6 = '\x01';
  }
  uVar1 = *param_2;
  if ((uVar1 >> 0xb & 1) == 0) {
    if (cVar6 == '\0') {
      return '\0';
    }
  }
  else {
    *(int *)(param_1 + 0x349) = (int)param_1[0x349] + 1;
    *(int *)(param_1 + 0x34e) = (int)param_1[0x34e] + 1;
    UfsAddDbgLog((longlong)param_1,0x45724877,(ulonglong)uVar1,7,0);
    cVar6 = '\x01';
  }
  *(int *)(param_1 + 0x34f) = (int)param_1[0x34f] + 1;
  if ((*(uint *)(param_1 + 0x193) & 0x10000) != 0) {
    StorPortExtendedFunction
              (0x56,param_1,0,2,0x11,L"Bus power state requires reset.",1,2,0,0,
               L"DeviceFatalErrorNumErrors",(int)param_1[0x34e],L"HostContFatalErrorNumErrors",
               *(undefined4 *)((longlong)param_1 + 0x1a6c),L"UicErrorNumErrors",
               *(undefined4 *)((longlong)param_1 + 0x1a74),L"NumErrors",(int)param_1[0x349]);
  }
  return cVar6;
}



===== UfsBuildIo @ 140003310 =====

undefined8 UfsBuildIo(longlong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined8 in_RAX;
  ulonglong uVar4;
  byte local_18 [16];
  
  if (*(char *)(param_2 + 2) != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  cVar2 = *(char *)(param_2 + 0x48);
  if ((cVar2 == '(') || (cVar2 == '*')) {
    if ((*(uint *)((longlong)param_1 + 0xe24) & 0x40) == 0) {
      *(byte *)(param_2 + 0x49) = *(byte *)(param_2 + 0x49) & 0xf7;
    }
  }
  else {
    if (cVar2 == 'H') {
      if ((*(char *)(param_2 + 7) == '\0') &&
         ((byte)(*(char *)((longlong)param_1 + 0x13cd) - 2U) < 2)) {
        uVar4 = *(ulonglong *)((longlong)param_1 + 0x13c1);
        uVar1 = uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8;
        if ((0xffffffff <
             (uVar1 | (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
              (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38)) ||
           (uVar4 = UfsSendUnmapRequest(param_1,0,0,(uint)uVar1), (int)uVar4 != 0))
        goto LAB_140003392;
        cVar2 = StorPortPause(param_1,600);
        if (cVar2 == '\0') {
          *(undefined1 *)(param_2 + 3) = 4;
        }
        else {
          uVar4 = UfsWaitForOutstandingOperations((longlong)param_1);
          if ((char)uVar4 == '\0') {
            uVar3 = 0xb;
          }
          else {
            local_18[8] = 0;
            local_18[9] = 0;
            local_18[10] = 0;
            local_18[0xb] = 0;
            local_18[0xc] = 0;
            local_18[0xd] = 0;
            local_18[0xe] = 0;
            local_18[0xf] = 0;
            local_18[0] = 6;
            local_18[1] = 6;
            local_18[2] = 0;
            local_18[3] = 0;
            local_18[4] = 0;
            local_18[5] = 0;
            local_18[6] = 0;
            local_18[7] = 0;
            uVar4 = UfsSendQueryUpiu(param_1,-0x7f,local_18,0,(undefined4 *)0x0);
            if ((int)uVar4 == 0) {
              uVar4 = UfsGetPurgeDeviceRequestStatus(param_1,param_2);
              goto LAB_14000336c;
            }
            uVar3 = 0x30;
          }
          *(undefined1 *)(param_2 + 3) = uVar3;
          if (cVar2 == '\x01') {
            StorPortResume(param_1);
          }
        }
      }
      else {
LAB_140003392:
        *(undefined1 *)(param_2 + 3) = 0x30;
      }
      uVar4 = StorPortNotification(0,param_1,param_2);
      goto LAB_14000336c;
    }
    if (cVar2 == -0x60) {
      *(undefined1 *)(param_2 + 0x4a) = 0;
    }
  }
  if ((int)param_1[0x1a8] == 0) {
    if (((*(uint *)(param_1 + 0x193) & 0x2000) != 0) &&
       ((*(uint *)(param_1 + 0x1dc) >> (*(byte *)(param_2 + 7) & 0x1f) & 1) != 0)) {
      if (*(char *)(param_2 + 0x48) == '(') {
        UfsHPBReadUpdateSrb((longlong)param_1,param_2);
      }
      else if (*(char *)(param_2 + 0x48) == '*') {
        UfsHPBMarkRangeDirty((longlong)param_1,param_2);
      }
    }
    uVar4 = UfsSendTransferRequest((longlong)param_1,param_2);
    if ((char)uVar4 == '\x01') {
LAB_14000336c:
      return uVar4 & 0xffffffffffffff00;
    }
  }
  else {
    uVar4 = 5;
  }
  *(char *)(param_2 + 3) = (char)uVar4;
  uVar4 = StorPortNotification(0,param_1,param_2);
  return uVar4 & 0xffffffffffffff00;
}



===== UfsSendTransferRequest @ 140003410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 UfsSendTransferRequest(longlong param_1,longlong param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  byte bVar6;
  ushort uVar7;
  undefined1 *puVar8;
  bool bVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint *puVar14;
  undefined8 uVar15;
  uint uVar16;
  undefined8 *puVar17;
  uint *puVar18;
  uint *puVar19;
  byte bVar20;
  ulonglong uVar21;
  bool bVar22;
  undefined1 local_b8 [32];
  undefined8 *local_98;
  longlong local_88;
  longlong local_80 [2];
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)local_b8;
  uVar12 = 0;
  local_48 = 0;
  puVar1 = (uint *)(param_1 + 0x4f0);
  local_70 = 0;
  local_80[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  uVar13 = 0;
  if (((param_1 + 0x510 != 0) &&
      (local_88 = param_2, uVar13 = StorPortExtendedFunction(0x25,param_1,param_1 + 0x510,local_80),
      (int)uVar13 == 0)) && (uVar13 = 0, local_80[0] != 0)) {
    *(uint *)(local_80[0] + -0xc) = *(uint *)(local_80[0] + -0xc) & 0xfffffffe;
    uVar16 = *(uint *)(local_80[0] + -0x10);
    uVar21 = (ulonglong)uVar16;
    bVar20 = (byte)uVar16;
    if (((*(uint *)(param_1 + 0xe24) & 0x10) == 0) && ((*(uint *)(param_1 + 0x978) & 1) == 0)) {
      puVar19 = (uint *)(param_1 + 0x4f4);
    }
    else {
      puVar19 = puVar1;
    }
    uVar11 = 1 << (bVar20 & 0x1f);
    uVar13 = (ulonglong)uVar11;
    LOCK();
    *puVar19 = *puVar19 | uVar11;
    UNLOCK();
    if ((uVar16 != 0xffffffff) && (uVar16 < *(uint *)(param_1 + 0x968))) {
      local_68 = uVar21 * 0x20;
      *(longlong *)(param_1 + 0xb90 + uVar21 * 8) = param_2;
      uVar16 = *(uint *)(param_2 + 0xc);
      puVar18 = (uint *)(*(longlong *)(param_1 + 0x980) + local_68);
      puVar19 = puVar1 + (uVar21 + 0x4a) * 4;
      if (((byte)uVar16 & 0xc0) == 0xc0) {
        uVar16 = 0x15000000;
      }
      else if ((uVar16 & 0x40) == 0) {
        uVar16 = (uVar16 & 0x80 | 0x440) << 0x12;
      }
      else {
        uVar16 = 0x15000000;
      }
      puVar14 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
      lVar10 = local_88;
      if (puVar14 != (uint *)0x0) {
        uVar12 = *puVar14;
      }
      if ((puVar18 != (uint *)0x0) && (puVar19 != (uint *)0x0)) {
        puVar18[0] = 0;
        puVar18[1] = 0;
        puVar18[2] = 0;
        puVar18[3] = 0;
        puVar18[4] = 0;
        puVar18[5] = 0;
        puVar18[6] = 0;
        puVar18[7] = 0;
        *puVar18 = uVar16;
        *(undefined1 *)(puVar18 + 2) = 0xf;
        puVar18[4] = *puVar19;
        puVar18[5] = puVar19[1];
        puVar18[6] = 0x8000e;
        *(short *)(puVar18 + 7) = (short)uVar12;
        *(undefined2 *)((longlong)puVar18 + 0x1e) = 0x16;
        puVar17 = *(undefined8 **)(puVar19 + 2);
        *puVar17 = 0;
        puVar17[1] = 0;
        puVar17[2] = 0;
        puVar17[3] = 0;
        puVar17[4] = 0;
        puVar17[5] = 0;
        puVar17[6] = 0;
        puVar17[7] = 0;
        puVar17[8] = 0;
        puVar17[9] = 0;
        puVar17[10] = 0;
      }
      uVar7 = *(ushort *)((longlong)puVar18 + 0x1e);
      puVar8 = *(undefined1 **)(puVar19 + 2);
      *puVar8 = 1;
      uVar5 = *(undefined1 *)(local_88 + 7);
      puVar8[4] = puVar8[4] & 0xf;
      puVar8[2] = uVar5;
      *(undefined2 *)(puVar8 + 10) = 0;
      puVar8[1] = 0;
      puVar8[3] = bVar20;
      puVar8[8] = 0;
      if ((*puVar18 & 0x6000000) == 0x2000000) {
        puVar8[1] = 0x20;
      }
      else if ((*puVar18 & 0x6000000) == 0x4000000) {
        puVar8[1] = 0x40;
      }
      uVar16 = *(uint *)(local_88 + 0x10);
      *(uint *)(puVar8 + 0xc) =
           uVar16 >> 0x18 | (uVar16 & 0xff0000) >> 8 | (uVar16 & 0xff00) << 8 | uVar16 << 0x18;
      memmove(puVar8 + 0x10,(void *)(local_88 + 0x48),(ulonglong)*(byte *)(local_88 + 10));
      if (((((char)*(undefined4 *)(param_1 + 0xc98) < '\0') &&
           (uVar15 = StorPortExtendedFunction(0x4e,param_1,lVar10,&local_58), (int)uVar15 == 0)) &&
          ((int)local_58 == 1)) && (local_58._4_4_ == 0x18)) {
        if ((*(uint *)(param_1 + 0xc98) & 0x100) == 0) {
          return CONCAT71((int7)((ulonglong)uVar15 >> 8),6);
        }
        puVar18[1] = (uint)local_48;
        *(undefined1 *)puVar18 = (undefined1)uStack_50;
        *puVar18 = *puVar18 | 0x800000;
        puVar18[3] = (uint)((ulonglong)local_48 >> 0x20);
      }
      if ((uVar12 != 0) && (uVar12 = 0, *puVar14 != 0)) {
        do {
          uVar13 = (ulonglong)uVar12;
          puVar19 = (uint *)(puVar8 + uVar13 * 0x10 + (ulonglong)uVar7 * 4);
          uVar16 = puVar14[uVar13 * 6 + 6];
          uVar11 = puVar14[uVar13 * 6 + 4];
          puVar19[1] = puVar14[uVar13 * 6 + 5];
          *puVar19 = uVar11;
          if ((*(uint *)(param_1 + 0xe24) & 0xc000000) == 0) {
            uVar16 = uVar16 + 3 & 0xfffffffc;
          }
          else {
            uVar16 = uVar16 + 7 & 0xfffffff8;
          }
          uVar12 = uVar12 + 1;
          puVar19[3] = (uVar16 - 1 ^ puVar19[3]) & 0x3ffff ^ puVar19[3];
        } while (uVar12 < *puVar14);
      }
      bVar6 = *(byte *)(lVar10 + 7);
      if ((*(byte *)(param_1 + 0xc98) & 1) == 0) {
        LOCK();
        piVar2 = (int *)(param_1 + 0x1a28);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        puVar17 = (undefined8 *)
                  ((ulonglong)(*(uint *)(param_1 + 0x1a2c) & iVar3 - 1U) * 0x20 +
                  *(longlong *)(param_1 + 0x1a30));
        *(undefined8 **)(param_1 + 0x1a38) = puVar17;
        *puVar17 = 0x63537254;
        puVar17[1] = lVar10;
        puVar17[2] = uVar21;
        puVar17[3] = (ulonglong)bVar6;
      }
      uVar13 = Feature_WriteBooster__private_IsEnabledDeviceUsageNoInline();
      if ((((int)uVar13 != 0) && ((*(uint *)(param_1 + 0xc98) & 0x4000) != 0)) &&
         (*(char *)(lVar10 + 0x48) == '*')) {
        if (*(int *)(lVar10 + 0x10) != 0) {
          StorPortExtendedFunction(0x2f,param_1,0,param_1 + 0xf50 + uVar21 * 8);
        }
        uVar15 = KeQueryInterruptTimePrecise(&local_70);
        if (*(longlong *)(param_1 + 0x1290) == 0) {
          *(undefined8 *)(param_1 + 0x1290) = uVar15;
          StorPortExtendedFunction(0x20,param_1,param_1 + 0x12b0);
          StorPortNotification(0x1001,param_1,param_1 + 0xca0,UfsPStateTimerDpc);
        }
      }
      local_60 = 0;
      if (((*(uint *)(param_1 + 0xe24) & 0x10) == 0) && ((*(uint *)(param_1 + 0x978) & 1) == 0)) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      if (((*(uint *)(param_1 + 0xda8) & 1) == 0) && ((*(uint *)(param_1 + 0xda8) & 2) == 0)) {
        uVar15 = 0x24;
      }
      else if (*(int *)(param_1 + 0xd40) == 1) {
        uVar15 = 0xe;
      }
      else {
        if (bVar9) {
          uVar12 = *puVar1;
        }
        else {
          uVar12 = *(uint *)(param_1 + 0x4f4);
        }
        if ((1 << (bVar20 & 0x1f) & uVar12) != 0) {
          uVar12 = 1 << (bVar20 & 0x1f);
          *(uint *)(*(longlong *)(param_1 + 0x970) + 8) = uVar12;
          LOCK();
          UNLOCK();
          LOCK();
          *(uint *)(param_1 + 0x4fc) = *(uint *)(param_1 + 0x4fc) | uVar12;
          UNLOCK();
          if (bVar9) {
            LOCK();
            *puVar1 = *puVar1 & ~uVar12;
            UNLOCK();
            LOCK();
            *(uint *)(param_1 + 0x4f4) = *(uint *)(param_1 + 0x4f4) | uVar12;
            UNLOCK();
            return 1;
          }
          return 1;
        }
        uVar15 = 0x30;
      }
      uVar11 = 1 << (bVar20 & 0x1f);
      uVar16 = ~uVar11;
      LOCK();
      *puVar1 = *puVar1 & uVar16;
      UNLOCK();
      uVar12 = *(uint *)(param_1 + 0x4f4);
      do {
        LOCK();
        uVar4 = *(uint *)(param_1 + 0x4f4);
        bVar22 = uVar12 == uVar4;
        if (bVar22) {
          *(uint *)(param_1 + 0x4f4) = uVar12 & uVar16;
        }
        else {
          uVar12 = uVar4;
        }
        UNLOCK();
      } while (!bVar22);
      LOCK();
      *(uint *)(param_1 + 0x4f8) = *(uint *)(param_1 + 0x4f8) & uVar16;
      UNLOCK();
      LOCK();
      *(uint *)(param_1 + 0x4fc) = *(uint *)(param_1 + 0x4fc) & uVar16;
      UNLOCK();
      LOCK();
      *(uint *)(param_1 + 0x500) = *(uint *)(param_1 + 0x500) & uVar16;
      UNLOCK();
      if ((!bVar9) && ((uVar12 & uVar11) == 0)) {
        return uVar15;
      }
      puVar1 = (uint *)(param_1 + 0x524 + local_68);
      *puVar1 = *puVar1 | 1;
      if (local_68 + 0x530 + param_1 == 0) {
        return uVar15;
      }
      local_98 = &local_60;
      StorPortExtendedFunction(0x26,param_1,param_1 + 0x510);
      return uVar15;
    }
  }
  return CONCAT71((int7)(uVar13 >> 8),5);
}



===== UfsAdapterPowerActive @ 140003a20 =====

undefined8 UfsAdapterPowerActive(longlong param_1,longlong param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 uVar6;
  longlong lVar5;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(char *)(param_2 + 0x14) == '\0') {
    LOCK();
    *(uint *)(param_1 + 0xda8) = *(uint *)(param_1 + 0xda8) & 0xfffffffe;
    UNLOCK();
  }
  else {
    LOCK();
    *(uint *)(param_1 + 0xda8) = *(uint *)(param_1 + 0xda8) | 1;
    UNLOCK();
  }
  if (*(char *)(param_2 + 0x14) == '\0') {
    if (*(byte *)(param_1 + 0xda1) < 2) {
      return 0;
    }
    if (((ulonglong)*(uint *)(param_1 + 0xdcc) == 0) || (*(int *)(param_1 + 0xdc0) == 1)) {
      *(byte *)(param_1 + 0xda0) = *(byte *)(param_1 + 0xda0) | 4;
      UfsAdapterFStateIdleTimerCallback(param_1);
      return 0;
    }
    *(byte *)(param_1 + 0xda0) = *(byte *)(param_1 + 0xda0) | 4;
    lVar5 = param_1;
    iVar3 = StorPortExtendedFunction
                      (0x21,param_1,*(undefined8 *)(param_1 + 0xde8),
                       UfsAdapterFStateIdleTimerCallback,param_1,
                       (ulonglong)*(uint *)(param_1 + 0xdcc) * 1000,10000);
    uVar6 = (undefined4)((ulonglong)lVar5 >> 0x20);
    pwVar4 = L"Adapter power active routine idle with no timeout with more than one F-state.";
  }
  else {
    *(byte *)(param_1 + 0xda0) = *(byte *)(param_1 + 0xda0) & 0xfb;
    uVar8 = 0;
    uVar7 = 0;
    iVar2 = StorPortExtendedFunction
                      (0x21,param_1,*(undefined8 *)(param_1 + 0xde8),
                       UfsAdapterFStateIdleTimerCallback,param_1,0,0);
    pwVar4 = L"Adapter power active routine cancel F-state timer failed.";
    iVar3 = 0;
    if (iVar2 != -0x3efffffa) {
      iVar3 = iVar2;
    }
    bVar1 = KeGetCurrentIrql();
    if ((*(byte *)(param_1 + 0xc98) & 1) == 0) {
      if (bVar1 == 2) {
        KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1 + 0xdf0,&local_28);
      }
      else if (bVar1 < 2) {
        KeAcquireInStackQueuedSpinLock(param_1 + 0xdf0,&local_28);
      }
    }
    uVar6 = 0;
    StorPortExtendedFunction(0x33,param_1,0,0,0,uVar7,uVar8);
    if ((*(byte *)(param_1 + 0xc98) & 1) == 0) {
      if (bVar1 == 2) {
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
      }
      else if (bVar1 < 2) {
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
    }
  }
  if (iVar3 == 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0xc98) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x55,param_1,0,1,CONCAT44(uVar6,0x10),pwVar4,1,2,0,0,L"status",iVar3,0,0);
  }
  return 1;
}



===== UfsAdapterFStateIdleTimerCallback @ 140003c40 =====

void UfsAdapterFStateIdleTimerCallback(longlong param_1)

{
  byte bVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  bVar1 = KeGetCurrentIrql();
  if ((*(byte *)(param_1 + 0xc98) & 1) == 0) {
    if (bVar1 == 2) {
      KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1 + 0xdf0,&local_28);
    }
    else if (bVar1 < 2) {
      KeAcquireInStackQueuedSpinLock(param_1 + 0xdf0,&local_28);
    }
  }
  if ((*(byte *)(param_1 + 0xda0) & 4) != 0) {
    *(byte *)(param_1 + 0xda0) = *(byte *)(param_1 + 0xda0) & 0xfb;
    StorPortExtendedFunction(0x33,param_1,0,0,(ulonglong)*(uint *)(param_1 + 0xdc4) * 10000);
  }
  if ((*(byte *)(param_1 + 0xc98) & 1) == 0) {
    if (bVar1 == 2) {
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
      return;
    }
    if (bVar1 < 2) {
      KeReleaseInStackQueuedSpinLock(&local_28);
    }
  }
  return;
}



===== UfsFillPrdtData @ 140003d50 =====

void UfsFillPrdtData(longlong param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  uint uVar1;
  
  *param_2 = param_3;
  param_2[1] = param_4;
  if ((*(uint *)(param_1 + 0xe24) & 0xc000000) == 0) {
    uVar1 = param_5 + 3U & 0xfffffffc;
  }
  else {
    uVar1 = param_5 + 7U & 0xfffffff8;
  }
  param_2[3] = (param_2[3] ^ uVar1 - 1) & 0x3ffff ^ param_2[3];
  return;
}



===== UfsAcquireBuildIndex @ 140003da0 =====

undefined4 UfsAcquireBuildIndex(longlong param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  if (((param_2 + 8 == (uint *)0x0) ||
      (iVar1 = StorPortExtendedFunction(0x25,param_1,param_2 + 8,local_res10), iVar1 != 0)) ||
     (local_res10[0] == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    *(uint *)(local_res10[0] + -0xc) = *(uint *)(local_res10[0] + -0xc) & 0xfffffffe;
    uVar2 = *(undefined4 *)(local_res10[0] + -0x10);
    if (((*(uint *)(param_1 + 0xe24) & 0x10) == 0) && ((param_2[0x122] & 1) == 0)) {
      param_2 = param_2 + 1;
    }
    LOCK();
    *param_2 = *param_2 | 1 << ((byte)uVar2 & 0x1f);
    UNLOCK();
  }
  return uVar2;
}



===== UfsReleaseBuildIndex @ 140003e40 =====

undefined8 UfsReleaseBuildIndex(longlong param_1,uint *param_2,ulonglong param_3,char param_4)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 local_res8;
  
  uVar4 = param_3 & 0xffffffff;
  local_res8 = 0;
  if (((*(uint *)(param_1 + 0xe24) & 0x10) == 0) && ((param_2[0x122] & 1) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  bVar3 = (byte)uVar4;
  if (((*(uint *)(param_1 + 0xda8) & 1) == 0) && ((*(uint *)(param_1 + 0xda8) & 2) == 0)) {
    uVar5 = 0x24;
  }
  else if ((*(int *)(param_1 + 0xd40) == 1) && (param_4 == '\0')) {
    uVar5 = 0xe;
  }
  else {
    uVar6 = 1 << (bVar3 & 0x1f);
    if (bVar2) {
      if ((uVar6 & *param_2) != 0) {
LAB_140003eb3:
        *(int *)(*(longlong *)(param_2 + 0x120) + 8) = 1 << (bVar3 & 0x1f);
        LOCK();
        UNLOCK();
        LOCK();
        param_2[3] = param_2[3] | uVar6;
        UNLOCK();
        if (!bVar2) {
          return 1;
        }
        LOCK();
        *param_2 = *param_2 & ~uVar6;
        UNLOCK();
        LOCK();
        param_2[1] = param_2[1] | uVar6;
        UNLOCK();
        if (param_4 == '\0') {
          return 1;
        }
        LOCK();
        param_2[2] = param_2[2] | uVar6;
        UNLOCK();
        return 1;
      }
    }
    else if ((uVar6 & param_2[1]) != 0) {
      if (param_4 != '\0') {
        LOCK();
        param_2[2] = param_2[2] | uVar6;
        UNLOCK();
      }
      goto LAB_140003eb3;
    }
    uVar5 = 0x30;
  }
  uVar8 = 1 << (bVar3 & 0x1f);
  uVar7 = ~uVar8;
  LOCK();
  *param_2 = *param_2 & uVar7;
  UNLOCK();
  uVar6 = param_2[1];
  do {
    LOCK();
    uVar1 = param_2[1];
    bVar9 = uVar6 == uVar1;
    if (bVar9) {
      param_2[1] = uVar6 & uVar7;
    }
    else {
      uVar6 = uVar1;
    }
    UNLOCK();
  } while (!bVar9);
  LOCK();
  param_2[2] = param_2[2] & uVar7;
  UNLOCK();
  LOCK();
  param_2[3] = param_2[3] & uVar7;
  UNLOCK();
  LOCK();
  param_2[4] = param_2[4] & uVar7;
  UNLOCK();
  if ((bVar2) || ((uVar6 & uVar8) != 0)) {
    param_2[uVar4 * 8 + 0xd] = param_2[uVar4 * 8 + 0xd] | 1;
    if ((param_2 + 8 != (uint *)0x0) && (param_2 + uVar4 * 8 + 0x10 != (uint *)0x0)) {
      StorPortExtendedFunction(0x26,param_1,param_2 + 8,param_2 + uVar4 * 8 + 0x10,&local_res8);
    }
  }
  return uVar5;
}



===== UfsAddDbgLog @ 140004000 =====

void UfsAddDbgLog(longlong param_1,uint param_2,ulonglong param_3,ulonglong param_4,
                 ulonglong param_5)

{
  int *piVar1;
  int iVar2;
  ulonglong *puVar3;
  
  if ((*(byte *)(param_1 + 0xc98) & 1) == 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 0x1a28);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    puVar3 = (ulonglong *)
             ((ulonglong)(*(uint *)(param_1 + 0x1a2c) & iVar2 - 1U) * 0x20 +
             *(longlong *)(param_1 + 0x1a30));
    *(ulonglong **)(param_1 + 0x1a38) = puVar3;
    puVar3[1] = param_3;
    puVar3[3] = param_5;
    *puVar3 = (ulonglong)
              ((param_2 & 0xff00 | param_2 << 0x10) << 8 |
              (param_2 & 0xff0000 | param_2 >> 0x10) >> 8);
    puVar3[2] = param_4;
  }
  return;
}



===== UfsReleaseCompletionIndex @ 140004090 =====

undefined8 UfsReleaseCompletionIndex(undefined8 param_1,longlong param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  bool bVar8;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  if (((param_3 < *(uint *)(param_2 + 0x478)) &&
      (uVar6 = 1 << ((byte)param_3 & 0x1f), (uVar6 & *(uint *)(param_2 + 4)) != 0)) &&
     ((uVar6 & *(uint *)(param_2 + 0xc)) != 0)) {
    uVar5 = ~uVar6;
    uVar3 = *(uint *)(param_2 + 4);
    do {
      LOCK();
      uVar2 = *(uint *)(param_2 + 4);
      bVar8 = uVar3 == uVar2;
      if (bVar8) {
        *(uint *)(param_2 + 4) = uVar3 & uVar5;
      }
      else {
        uVar3 = uVar2;
      }
      UNLOCK();
    } while (!bVar8);
    LOCK();
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & uVar5;
    UNLOCK();
    LOCK();
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & uVar5;
    UNLOCK();
    LOCK();
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & uVar5;
    UNLOCK();
    if ((uVar3 & uVar6) != 0) {
      lVar7 = ((ulonglong)param_3 + 2) * 0x20 + param_2;
      puVar1 = (uint *)((ulonglong)param_3 * 0x20 + 0x34 + param_2);
      *puVar1 = *puVar1 | 1;
      if ((param_2 + 0x20 != 0) && (lVar7 != 0)) {
        uVar4 = StorPortExtendedFunction(0x26,param_1,param_2 + 0x20,lVar7,local_res10);
        if ((int)uVar4 == 0) {
          return 0;
        }
        return uVar4;
      }
    }
  }
  return 0xc1000006;
}



===== UfsInitializeTrdUcd @ 140004160 =====

void UfsInitializeTrdUcd(uint *param_1,uint *param_2,uint param_3,undefined2 param_4)

{
  undefined8 *puVar1;
  
  if ((param_1 != (uint *)0x0) && (param_2 != (uint *)0x0)) {
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 2) = 0xf;
    *param_1 = (param_3 & 3) << 0x19 | 0x11000000;
    param_1[4] = *param_2;
    param_1[5] = param_2[1];
    param_1[6] = 0x8000e;
    *(undefined2 *)(param_1 + 7) = param_4;
    *(undefined2 *)((longlong)param_1 + 0x1e) = 0x16;
    puVar1 = *(undefined8 **)(param_2 + 2);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
  }
  return;
}



===== UfsDelay @ 1400041d0 =====

void UfsDelay(uint param_1)

{
  ulonglong uVar1;
  
  if (param_1 != 0) {
    uVar1 = (ulonglong)param_1;
    do {
      StorPortStallExecution(1000);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}



===== UfsCompleteTaskManDpc @ 140004210 =====

void UfsCompleteTaskManDpc(undefined8 param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar4 = 0;
  local_28 = 5;
  local_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  StorPortExtendedFunction(0x5d,param_2,5,param_1,&local_28);
  uVar3 = 0xffffffff;
  if (((*(uint *)(param_2 + 0x1b5) & 1) != 0) ||
     ((((*(uint *)(param_2 + 0x1b5) & 4) == 0 && (*(int *)((longlong)param_2 + 0xda4) == 0)) &&
      ((int)param_2[0x1a8] != 1)))) {
    if (((*(uint *)((longlong)param_2 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_2 + 0x93) & 1) == 0)) {
      uVar3 = *(uint *)(param_2[0x92] + 0x14);
    }
    uVar3 = *(uint *)((longlong)param_2 + 0x1c) & ~*(uint *)(param_2 + 3) &
            *(uint *)((longlong)param_2 + 0x14) & uVar3;
    if (((*(uint *)((longlong)param_2 + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(param_2 + 0x93) & 1) == 0)) {
      *(uint *)(param_2[0x92] + 0x14) = uVar3;
      LOCK();
      UNLOCK();
    }
    else {
      uVar3 = uVar3 & ~*(uint *)(param_2[0x92] + 8);
    }
    uVar2 = *(uint *)(param_2 + 4);
    do {
      LOCK();
      uVar1 = *(uint *)(param_2 + 4);
      bVar5 = uVar2 == uVar1;
      if (bVar5) {
        *(uint *)(param_2 + 4) = uVar2 | uVar3;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (!bVar5);
    if (((~uVar2 & uVar3) != 0) && ((int)param_2[0x91] != 0)) {
      do {
        if (((~uVar2 & uVar3) >> (uVar4 & 0x1f) & 1) != 0) {
          UfsCompleteTaskManRequest(param_2,uVar4);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_2 + 0x91));
    }
  }
  StorPortNotification(0x1004,param_2,&local_28);
  return;
}



===== UfsAdapterControl @ 140004370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140004acf) */
/* WARNING: Removing unreachable block (ram,0x000140004b1f) */
/* WARNING: Removing unreachable block (ram,0x000140004b29) */
/* WARNING: Removing unreachable block (ram,0x000140004bb7) */
/* WARNING: Removing unreachable block (ram,0x000140004bca) */
/* WARNING: Removing unreachable block (ram,0x000140004c31) */
/* WARNING: Removing unreachable block (ram,0x000140004c6f) */
/* WARNING: Removing unreachable block (ram,0x000140004ddf) */
/* WARNING: Removing unreachable block (ram,0x000140004c77) */
/* WARNING: Removing unreachable block (ram,0x000140004ca5) */
/* WARNING: Removing unreachable block (ram,0x000140004cb0) */
/* WARNING: Removing unreachable block (ram,0x000140004d8e) */
/* WARNING: Removing unreachable block (ram,0x000140004d3b) */
/* WARNING: Removing unreachable block (ram,0x000140004d68) */
/* WARNING: Removing unreachable block (ram,0x000140004d90) */
/* WARNING: Removing unreachable block (ram,0x000140004d92) */
/* WARNING: Removing unreachable block (ram,0x000140004dc3) */
/* WARNING: Removing unreachable block (ram,0x000140004d9a) */
/* WARNING: Removing unreachable block (ram,0x000140004da0) */
/* WARNING: Removing unreachable block (ram,0x000140004dbb) */
/* WARNING: Removing unreachable block (ram,0x000140004da6) */
/* WARNING: Removing unreachable block (ram,0x000140004dc6) */
/* WARNING: Removing unreachable block (ram,0x000140004c26) */
/* WARNING: Removing unreachable block (ram,0x000140004de2) */
/* WARNING: Removing unreachable block (ram,0x000140004de9) */
/* WARNING: Removing unreachable block (ram,0x000140004df2) */
/* WARNING: Removing unreachable block (ram,0x000140004e54) */
/* WARNING: Removing unreachable block (ram,0x000140004f35) */
/* WARNING: Removing unreachable block (ram,0x000140004edf) */
/* WARNING: Removing unreachable block (ram,0x000140004f0c) */
/* WARNING: Removing unreachable block (ram,0x000140004f37) */
/* WARNING: Removing unreachable block (ram,0x000140004f3e) */
/* WARNING: Removing unreachable block (ram,0x000140004f42) */
/* WARNING: Removing unreachable block (ram,0x000140004f39) */
/* WARNING: Removing unreachable block (ram,0x000140004f46) */
/* WARNING: Removing unreachable block (ram,0x000140004f5a) */
/* WARNING: Removing unreachable block (ram,0x000140004f60) */
/* WARNING: Removing unreachable block (ram,0x000140004e49) */
/* WARNING: Removing unreachable block (ram,0x000140004bac) */
/* WARNING: Removing unreachable block (ram,0x000140004f6d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong UfsAdapterControl(longlong *param_1,undefined4 param_2,int *param_3)

{
  longlong *plVar1;
  byte bVar2;
  short *psVar3;
  size_t _Size;
  longlong lVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  char *pcVar11;
  undefined1 local_1c8 [32];
  uint local_130 [2];
  longlong local_128;
  uint local_120;
  undefined4 local_11c;
  undefined8 local_e0;
  undefined8 uStack_d8;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)local_1c8;
  local_11c = param_2;
  switch(param_2) {
  case 0:
    *(undefined2 *)(param_3 + 1) = 0x101;
    *(undefined1 *)((longlong)param_3 + 6) = 1;
    *(undefined1 *)((longlong)param_3 + 10) = 1;
    bVar5 = ~(byte)(*(uint *)((longlong)param_1 + 0xe24) >> 2) & 1;
    *(byte *)(param_3 + 3) = bVar5;
    *(byte *)((longlong)param_3 + 0xd) = bVar5;
    *(byte *)(param_3 + 4) = bVar5;
    *(byte *)((longlong)param_3 + 0x13) = bVar5;
    *(undefined2 *)((longlong)param_3 + 0x15) = 0x101;
    *(undefined1 *)(param_3 + 6) = 1;
    return 0;
  case 1:
    if ((*(uint *)(param_1 + 0x193) & 0x30) != 0) {
      UfsStopAdapter(param_1);
      *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b4) & 0xfe;
      local_e0 = 0;
      uStack_d8 = 0;
      LOCK();
      *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffe;
      UNLOCK();
      uVar10 = Feature_WriteBooster__private_IsEnabledDeviceUsageNoInline();
      if ((((int)uVar10 != 0) && ((*(uint *)(param_1 + 0x193) & 0x4000) != 0)) &&
         ((*(uint *)(param_1 + 0x1b7) & 1) != 0)) {
        if (param_1[0x252] != 0) {
          param_1[0x252] = 0;
          StorPortExtendedFunction(0x22,param_1,param_1[0x256]);
        }
        *(uint *)(param_1 + 0x1b7) = *(uint *)(param_1 + 0x1b7) & 0xfffffffe;
        *(undefined2 *)((longlong)param_1 + 0xdbc) = 0;
        param_1[0x254] = 0;
        if (param_1[0x1b6] != 0) {
          param_1[0x1b6] = 0;
        }
        uVar10 = Feature_UfsRemoveManualFlush__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar10 == 0) {
          local_e0 = CONCAT62(local_e0._2_6_,0xf07);
          uVar10 = UfsSendQueryUpiu(param_1,-0x7f,(byte *)&local_e0,0,(undefined4 *)0x0);
          if ((int)uVar10 != 0) {
            StorPortExtendedFunction(0x55,param_1,0);
          }
        }
      }
      StorPortExtendedFunction(0x22,param_1,param_1[0x1bd]);
      return 0;
    }
  case 2:
    return 0;
  default:
switchD_1400043cd_caseD_3:
    uVar10 = 1;
    goto LAB_1400050f5;
  case 6:
    uVar10 = 0;
    if (param_3[5] == 1) {
      if ((*(uint *)(param_1 + 0x193) & 0x40) == 0) {
        uVar7 = UfsAdapterPowerUp(param_1);
        uVar10 = (ulonglong)uVar7;
      }
      else {
        uVar10 = UfsStartAdapter(param_1);
        iVar6 = (int)uVar10;
        if (((char)param_1[0x193] < '\0') && (iVar6 == 0)) {
          uVar8 = UfsCryptoEngineEnable(param_1);
          iVar6 = (int)uVar8;
        }
        *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xffffffbf;
        UfsWriteBoosterInitialize(param_1);
        uVar10 = (ulonglong)(iVar6 != 0);
      }
    }
    else {
      if (param_3[5] != 4) goto switchD_1400043cd_caseD_3;
      if (param_3[4] == 3) {
        *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffffeff | 0x40;
        return 0;
      }
      local_130[0] = 0;
      LOCK();
      *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) | 2;
      UNLOCK();
      if ((int)param_1[0x9e] == 0 &&
          (*(int *)((longlong)param_1 + 0x4f4) == 0 &&
          ((int)param_1[0xa0] == 0 && (int)param_1[0x9f] == 0))) {
        uVar8 = UfsSendStartStopUnitTransferRequest(param_1,(param_3[4] - 4U < 3) + 2);
        if ((int)uVar8 == 0) {
          iVar6 = UfsSendUicDmeHibernate(param_1,0x17,local_130);
          if (*(int *)((longlong)param_1 + 0xc9c) != 0) {
            StorPortStallExecution(*(int *)((longlong)param_1 + 0xc9c) + 10);
          }
          if ((iVar6 != 0) || (local_130[0] != 0)) {
            uVar10 = 1;
          }
        }
        else {
          uVar10 = 1;
        }
      }
      else {
        uVar10 = 1;
      }
      *(undefined4 *)(*param_1 + 0x24) = 0;
      LOCK();
      UNLOCK();
      LOCK();
      *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) | 4;
      UNLOCK();
      LOCK();
      *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffd;
      UNLOCK();
      if ((int)uVar10 == 0) {
        return uVar10;
      }
      if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
        StorPortExtendedFunction(0x56,param_1,0);
      }
    }
    break;
  case 8:
    uVar10 = UfsAdapterPowerActive((longlong)param_1,(longlong)param_3);
    uVar10 = uVar10 & 0xffffffff;
    break;
  case 9:
    iVar6 = param_3[5];
    uVar10 = 0;
    local_120 = 0;
    if (iVar6 == 0) {
      uVar7 = 0x18;
    }
    else {
      if (iVar6 != 1) goto LAB_1400048a7;
      uVar7 = 0x17;
    }
    LOCK();
    *(int *)((longlong)param_1 + 0xda4) = iVar6;
    UNLOCK();
    iVar6 = UfsSendUicDmeHibernate(param_1,uVar7,&local_120);
    if ((iVar6 != 0) || (local_120 != 0)) {
LAB_1400048a7:
      uVar10 = 1;
    }
    break;
  case 0xc:
    if (((uint)param_3[1] < 0x10) || (*param_3 == 0)) goto LAB_1400048a7;
    if (((*(uint *)((longlong)param_1 + 0xe24) & 0xe000000) == 0) || ((int)param_1[0x1e9] != 1)) {
      iVar6 = param_3[2];
      *(int *)(param_1 + 0x1b8) = iVar6;
      *(int *)(param_1 + 0x1b9) = param_3[3];
      if (iVar6 == 1) {
        StorPortExtendedFunction(0x39,param_1,0,*(undefined4 *)((longlong)param_1 + 0xdd4));
        *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b4) & 0xfb;
        StorPortExtendedFunction(0x21,param_1,param_1[0x1bd],UfsAdapterFStateIdleTimerCallback);
        uVar10 = 0;
      }
      else {
        StorPortExtendedFunction(0x39,param_1,0,(int)param_1[0x1ba]);
        uVar10 = 0;
      }
    }
    else {
      uVar10 = 0;
    }
    break;
  case 0xf:
    bVar5 = *(byte *)((longlong)param_1 + 0xdbd);
    if (((uint)param_3[1] < 0x18) || (*param_3 == 0)) {
      uVar10 = 1;
    }
    else {
      bVar2 = *(byte *)(param_3 + 4);
      pcVar11 = "Succeeded";
      if ((char)param_3[3] == '\0') {
        pcVar11 = "Failed";
      }
      StorPortDebugPrint(3,"StorUfs - POWERPLAY: P-State Callback for P%u, PEP %s\n",bVar2,pcVar11);
      if ((char)param_3[3] == '\0') {
        uVar10 = 1;
      }
      else {
        StorPortDebugPrint(3,"StorUfs - POWER: Transitioning to UFS PS%u - from: %u state\n",bVar2,
                           bVar5);
        if (*(byte *)((longlong)param_1 + 0xdbe) < bVar5) {
          uVar10 = 1;
        }
        else {
          *(uint *)(param_1 + 0x250) = (uint)bVar2;
          *(undefined1 *)(param_1 + 0x255) = 0;
          uVar10 = 0;
          *(byte *)((longlong)param_1 + 0xdbd) = bVar2;
        }
      }
    }
    break;
  case 0x11:
    if (((param_3 == (int *)0x0) || ((byte *)((longlong)param_1 + 0x16dd) == (byte *)0x0)) ||
       (*param_3 != 1)) goto LAB_1400048a7;
    _Size = (ulonglong)((int)(*(byte *)((longlong)param_1 + 0x16dd) - 2) / 2 & 0xffff) * 2;
    memmove((void *)((longlong)param_3 + 9),(void *)((longlong)param_1 + 0x16df),_Size);
    *(undefined2 *)(_Size + 9 + (longlong)param_3) = 0;
    uVar10 = 0;
    *(undefined1 *)(param_3 + 2) = 1;
    break;
  case 0x12:
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      LOCK();
      plVar1 = param_1 + 0x345;
      lVar4 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      puVar9 = (undefined8 *)
               ((ulonglong)(*(uint *)((longlong)param_1 + 0x1a2c) & (int)lVar4 - 1U) * 0x20 +
               param_1[0x346]);
      param_1[0x347] = (longlong)puVar9;
      *puVar9 = 0x53507243;
      puVar9[1] = param_3;
      puVar9[2] = 0;
      puVar9[3] = 0;
    }
    if (param_3 == (int *)0x0) {
      uVar10 = 0xc1000006;
    }
    else if ((char)*(uint *)(param_1 + 0x193) < '\0') {
      if ((*(uint *)(param_1 + 0x193) >> 8 & 1) == 0) {
        uVar10 = 0xc1000009;
      }
      else if (*param_3 == 1) {
        if (param_3[1] == 0x28) {
          psVar3 = *(short **)(param_3 + 2);
          if (*psVar3 == 1) {
            if (psVar3[1] == 0x28) {
              if ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1e & 1) == 0) {
                if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) == 0) {
                  uVar10 = 0xc1000002;
                }
                else {
                  uVar10 = UfsIntelCryptoInsertKey(param_1,(longlong)psVar3);
                  uVar10 = uVar10 & 0xffffffff;
                }
              }
              else {
                local_128 = 0;
                uVar7 = StorPortExtendedFunction(0x18,param_1,0x20,0);
                uVar10 = (ulonglong)uVar7;
                _DAT_00000000 = 0;
                uRam0000000000000008 = 0;
                uRam0000000000000010 = 0;
                uRam0000000000000018 = 0;
                if (local_128 != 0) {
                  StorPortExtendedFunction(0x19,param_1);
                }
              }
            }
            else {
              uVar10 = 0xc1000006;
            }
          }
          else {
            uVar10 = 0xc1000006;
          }
        }
        else {
          uVar10 = 0xc1000006;
        }
      }
      else {
        uVar10 = 0xc1000002;
      }
    }
    else {
      uVar10 = 0xc1000009;
    }
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      LOCK();
      plVar1 = param_1 + 0x345;
      lVar4 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      puVar9 = (undefined8 *)
               ((ulonglong)(*(uint *)((longlong)param_1 + 0x1a2c) & (int)lVar4 - 1U) * 0x20 +
               param_1[0x346]);
      param_1[0x347] = (longlong)puVar9;
      *puVar9 = 0x43507243;
      puVar9[1] = param_3;
      puVar9[2] = uVar10;
      puVar9[3] = 0;
    }
    uVar10 = (ulonglong)((int)uVar10 != 0);
    break;
  case 0x14:
    uVar10 = 1;
    if (param_3 != (int *)0x0) {
      if (*param_3 == 1) {
        *(uint *)(param_1 + 0x193) =
             ((uint)*(byte *)(param_3 + 1) << 0xf ^ *(uint *)(param_1 + 0x193)) & 0x8000 ^
             *(uint *)(param_1 + 0x193);
        return 0;
      }
      if (*param_3 == 2) {
        *(uint *)(param_1 + 0x193) =
             ((uint)*(byte *)(param_3 + 1) << 0x10 ^ *(uint *)(param_1 + 0x193)) & 0x10000 ^
             *(uint *)(param_1 + 0x193);
      }
      return 0;
    }
    goto LAB_1400050f5;
  }
  if ((int)uVar10 != 0) {
LAB_1400050f5:
    if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
      StorPortExtendedFunction(0x56,param_1,0);
    }
  }
  return uVar10;
}



===== UfsSendUicDmeHibernate @ 1400051d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UfsSendUicDmeHibernate(longlong *param_1,uint param_2,uint *param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  undefined1 local_e8 [32];
  undefined8 local_c8;
  wchar_t *local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  ulonglong local_90;
  wchar_t *local_88;
  ulonglong local_80;
  wchar_t *local_78;
  ulonglong local_70;
  undefined8 local_68;
  undefined8 local_60;
  wchar_t local_58 [4];
  longlong local_50;
  longlong local_48;
  uint local_40 [4];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_e8;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  lVar1 = *param_1;
  if ((((*(uint *)((longlong)param_1 + 0xe24) & 4) != 0) ||
      ((*(uint *)((longlong)param_1 + 0xe24) & 1) != 0)) ||
     ((*(uint *)(param_1 + 0x193) & 0x400) != 0)) {
    *param_3 = 0;
    iVar6 = 0;
    goto LAB_1400053f9;
  }
  if ((param_2 == 0x18) && ((int)param_1[0x1bb] != 0)) {
    local_50 = 0;
    local_48 = 0;
    StorPortExtendedFunction(0x2f,param_1,&local_48,&local_50);
    lVar3 = (local_50 - param_1[0x1bc]) * 1000000;
    lVar4 = lVar3 / local_48;
    if (lVar4 < (longlong)(ulonglong)*(uint *)(param_1 + 0x1bb)) {
      StorPortStallExecution(*(uint *)(param_1 + 0x1bb) - (int)lVar4,lVar3 % local_48);
    }
  }
  uVar5 = UfsExecuteUicCommandSynchronous(param_1,param_2,local_40,param_3);
  if (((int)uVar5 == 0) && (*param_3 == 0)) {
    if ((*(uint *)(lVar1 + 0x30) & 0x700) != 0x100) goto LAB_140005349;
    iVar6 = 0;
    if (param_2 != 0x17) goto LAB_1400053f9;
    if (*(int *)((longlong)param_1 + 0xc9c) != 0) {
      StorPortStallExecution(*(int *)((longlong)param_1 + 0xc9c) + 10);
    }
    if ((int)param_1[0x1bb] == 0) goto LAB_1400053f9;
    uVar2 = StorPortExtendedFunction(0x2f,param_1,0,param_1 + 0x1bc);
    uVar5 = (ulonglong)uVar2;
    iVar6 = 0;
    if (uVar2 == 0) goto LAB_1400053f9;
  }
  else {
    local_c8 = CONCAT44(local_c8._4_4_,*param_3);
    StorPortDebugPrint(0,"Hibernate command %x status %x & ErrorCode %x\n",(ulonglong)param_2,
                       uVar5 & 0xffffffff);
LAB_140005349:
    uVar5 = 0xc1000001;
  }
  iVar6 = (int)uVar5;
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    local_80 = (ulonglong)*param_3;
    local_60 = 0;
    local_68 = 0;
    local_78 = L"status";
    local_88 = L"ErrorCode";
    local_98 = L"HibernateOpcode";
    local_a0 = 0;
    local_a8 = 0;
    local_b0 = 3;
    local_b8 = 1;
    local_c0 = L"Sending a DME_HIBERN8 command failed.";
    local_c8 = CONCAT44(local_c8._4_4_,2);
    local_90 = (ulonglong)param_2;
    local_70 = uVar5;
    StorPortExtendedFunction(0x56,param_1,0);
  }
LAB_1400053f9:
  if ((((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) && (param_2 == 0x18)) &&
     ((iVar6 != 0 ||
      ((*param_3 != 0 ||
       (uVar5 = UfsIntelLkfLifelineCheck(param_1,*(uint *)((longlong)param_1 + 0x1a0c)),
       (int)uVar5 != 0)))))) {
    *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
    local_c0 = local_58;
    local_c8 = 0;
    local_58[0] = L'\0';
    local_58[1] = L'\0';
    StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0);
  }
  if (((((*(uint *)((longlong)param_1 + 0xe24) & 0x40000000) != 0) && (param_2 == 0x18)) &&
      ((*(uint *)(param_1 + 0x193) & 0x100) != 0)) &&
     (uVar2 = UfsQcGetControllerVersion8380(param_1), uVar2 == 0x50000000)) {
    lVar1 = *param_1;
    if ((*(uint *)((longlong)param_1 + 0xe24) & 0x40000000) != 0) {
      *(undefined4 *)(lVar1 + 0x2600) = 0x18;
      LOCK();
      UNLOCK();
      *(undefined4 *)(lVar1 + 0x2600) = 0;
      LOCK();
      UNLOCK();
    }
    local_80 = 0;
    local_88 = (wchar_t *)0x0;
    local_90 = 0;
    local_98 = (wchar_t *)0x0;
    local_a0 = 0;
    local_a8 = 0;
    local_b0 = 3;
    local_b8 = 1;
    local_c0 = L"Successfully updated 0x18 and 0x0 register values for 8380 QC hardware.";
    local_c8 = CONCAT44(local_c8._4_4_,2);
    StorPortExtendedFunction(0x55,param_1,0);
  }
  return iVar6;
}



===== Feature_WriteBooster__private_IsEnabledDeviceUsageNoInline @ 140005558 =====

ulonglong Feature_WriteBooster__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_WriteBooster__private_featureState;
  if ((Feature_WriteBooster__private_featureState & 0x10) == 0) {
    uVar1 = Feature_WriteBooster__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_WriteBooster__private_featureState & 1);
  }
  return uVar1;
}



===== __report_gsfailure @ 1400055a0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== DriverEntry @ 1400055b0 =====

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
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
  code *local_10;
  
  if (g_DumpPreInitializeInvoked == '\0') {
    wil_InitializeFeatureStaging();
  }
  memset(&local_d8,0,0xd0);
  local_d8 = 0xd0;
  local_d0 = UfsInitialize;
  local_d4 = 5;
  local_c8 = UfsStartIo;
  local_98 = 0x1a80;
  local_58 = UfsBuildIo;
  local_8c = 6;
  local_c0 = UfsInterrupt;
  local_80 = 0x1010100;
  local_b8 = UfsFindAdapter;
  local_b0 = UfsResetBus;
  local_60 = UfsAdapterControl;
  local_10 = UfsUnitControl;
  local_90 = 4;
  local_94 = 4;
  local_7c = 1;
  local_20 = 0x1438;
  iVar1 = StorPortInitialize(param_1,param_2,&local_d8,0);
  if (g_DumpPreInitializeInvoked == '\0') {
    if (iVar1 == 0) {
      StorPortDriverUnload = *(longlong *)(param_1 + 0x68);
      if (StorPortDriverUnload != 0) {
        *(code **)(param_1 + 0x68) = StorUfsDriverUnload;
      }
    }
    else {
      wil_UninitializeFeatureStaging();
    }
  }
  return iVar1;
}



===== DumpPreInitialize @ 1400056f0 =====

void DumpPreInitialize(void)

{
                    /* 0x56f0  1  DumpPreInitialize */
  g_DumpPreInitializeInvoked = 1;
  wil_InitializeFeatureStaging();
  return;
}



===== DumpUninitialize @ 140005710 =====

void DumpUninitialize(void)

{
                    /* 0x5710  2  DumpUninitialize */
  wil_UninitializeFeatureStaging();
  return;
}



===== Feature_UfsTelemetryAndHealth__private_IsEnabledDeviceUsageNoInline @ 140005728 =====

ulonglong Feature_UfsTelemetryAndHealth__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_UfsTelemetryAndHealth__private_featureState;
  if ((Feature_UfsTelemetryAndHealth__private_featureState & 0x10) == 0) {
    uVar1 = Feature_UfsTelemetryAndHealth__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_UfsTelemetryAndHealth__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_UfsTelemetryAndHealth__private_IsEnabledFallback @ 140005760 =====

void Feature_UfsTelemetryAndHealth__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_UfsTelemetryAndHealth__private_descriptor);
  return;
}



===== Feature_WriteBoosterSupportUFS2_2__private_IsEnabledDeviceUsageNoInline @ 14000577c =====

ulonglong Feature_WriteBoosterSupportUFS2_2__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_WriteBoosterSupportUFS2_2__private_featureState;
  if ((Feature_WriteBoosterSupportUFS2_2__private_featureState & 0x10) == 0) {
    uVar1 = Feature_WriteBoosterSupportUFS2_2__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_WriteBoosterSupportUFS2_2__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_WriteBoosterSupportUFS2_2__private_IsEnabledFallback @ 1400057b4 =====

void Feature_WriteBoosterSupportUFS2_2__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_WriteBoosterSupportUFS2_2__private_descriptor);
  return;
}



===== Feature_WriteBooster__private_IsEnabledFallback @ 1400057d0 =====

void Feature_WriteBooster__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_WriteBooster__private_descriptor);
  return;
}



===== StorUfsDriverUnload @ 1400057f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorUfsDriverUnload(void)

{
  (*StorPortDriverUnload)();
  wil_UninitializeFeatureStaging();
  return;
}



===== UfsAllocateRequestLists @ 140005814 =====

undefined8 UfsAllocateRequestLists(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  void *_Dst;
  longlong lVar4;
  undefined8 uVar5;
  longlong *plVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  
  plVar6 = param_1 + 2;
  plVar2 = param_1 + 0x9e;
  *(undefined4 *)(param_1 + 0x91) = 8;
  iVar7 = *(int *)(param_2 + 0xd0);
  *(int *)(param_1 + 0x12d) = iVar7;
  local_res8[0] = 0;
  local_res10 = 0;
  uVar9 = iVar7 * 0x500 + 0x1057 +
          (iVar7 * 0x20 + 0xfffU & 0xfffff000) + ((int)param_1[0x91] * 0x50 + 0xfffU & 0xfffff000);
  _Dst = (void *)StorPortGetUncachedExtension(param_1,param_2,uVar9);
  uVar3 = StorPortGetPhysicalAddress(param_1,0,_Dst,local_res8);
  param_1[0x192] = (longlong)_Dst;
  memset(_Dst,0,(ulonglong)uVar9);
  uVar9 = 0x1000 - (uVar3 & 0xfff);
  if ((uVar3 & 0xfff) == 0) {
    uVar9 = 0;
  }
  param_1[0x94] = (ulonglong)uVar9 + (longlong)_Dst;
  lVar4 = StorPortGetPhysicalAddress(param_1,0,(ulonglong)uVar9 + (longlong)_Dst,local_res8);
  param_1[0x95] = lVar4;
  *(undefined4 *)plVar6 = 0;
  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)((longlong)param_1 + 0x1c) = 0;
  plVar1 = param_1 + 6;
  *(uint *)(param_1 + 0x93) = *(uint *)(param_1 + 0x93) | 1;
  uVar9 = ((int)param_1[0x91] * 0x50 + 0xfffU & 0xfffff000) + uVar9;
  param_1[0x92] = *param_1 + 0x70;
  if (plVar1 != (longlong *)0x0) {
    uVar5 = StorPortExtendedFunction(0x23,param_1,plVar1);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    uVar3 = (int)param_1[0x91] - 1;
    puVar8 = (uint *)((longlong)(int)uVar3 * 0x20 + 0x34 + (longlong)plVar6);
    for (; -1 < (int)uVar3; uVar3 = uVar3 - 1) {
      *puVar8 = *puVar8 | 1;
      puVar8[-1] = uVar3;
      if (plVar6 + ((longlong)(int)uVar3 + 2) * 4 == (longlong *)0x0) {
        return 0xc1000006;
      }
      uVar5 = StorPortExtendedFunction
                        (0x26,param_1,plVar1,plVar6 + ((longlong)(int)uVar3 + 2) * 4,&local_res10);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      puVar8 = puVar8 + -8;
    }
    lVar4 = (ulonglong)uVar9 + (longlong)_Dst;
    param_1[0x130] = lVar4;
    lVar4 = StorPortGetPhysicalAddress(param_1,0,lVar4,local_res8);
    param_1[0x131] = lVar4;
    iVar7 = 0;
    uVar9 = uVar9 + ((int)param_1[0x12d] * 0x20 + 0xfffU & 0xfffff000);
    if (0 < (int)param_1[0x12d]) {
      plVar6 = param_1 + 0x132;
      do {
        plVar6[1] = (ulonglong)uVar9 + (longlong)_Dst;
        lVar4 = StorPortGetPhysicalAddress(param_1,0,(ulonglong)uVar9 + (longlong)_Dst,local_res8);
        *plVar6 = lVar4;
        uVar9 = uVar9 + 0x500;
        iVar7 = iVar7 + 1;
        plVar6 = plVar6 + 2;
      } while (iVar7 < (int)param_1[0x12d]);
    }
    param_1[0x24e] = (ulonglong)uVar9 + (longlong)_Dst;
    lVar4 = StorPortGetPhysicalAddress(param_1,0,(ulonglong)uVar9 + (longlong)_Dst,local_res8);
    param_1[0x24f] = lVar4;
    lVar4 = (ulonglong)(uVar9 + 0x18) + (longlong)_Dst;
    param_1[599] = lVar4;
    lVar4 = StorPortGetPhysicalAddress(param_1,0,lVar4,local_res8);
    param_1[600] = lVar4;
    lVar4 = (ulonglong)(uVar9 + 0x30) + (longlong)_Dst;
    param_1[0x259] = lVar4;
    lVar4 = StorPortGetPhysicalAddress(param_1,0,lVar4,local_res8);
    param_1[0x25a] = lVar4;
    plVar6 = param_1 + 0xa2;
    *(undefined4 *)plVar2 = 0;
    *(undefined4 *)((longlong)param_1 + 0x4f4) = 0;
    *(undefined4 *)(param_1 + 0x9f) = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    *(undefined4 *)((longlong)param_1 + 0x4fc) = 0;
    *(uint *)(param_1 + 0x12f) = *(uint *)(param_1 + 0x12f) & 0xfffffffe;
    param_1[0x12e] = *param_1 + 0x50;
    if (plVar6 != (longlong *)0x0) {
      uVar5 = StorPortExtendedFunction(0x23,param_1,plVar6);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      uVar9 = (int)param_1[0x12d] - 1;
      puVar8 = (uint *)((longlong)(int)uVar9 * 0x20 + 0x34 + (longlong)plVar2);
      while( true ) {
        if ((int)uVar9 < 0) {
          *(undefined4 *)(param_1 + 0x19d) = 0;
          return 0;
        }
        *puVar8 = *puVar8 | 1;
        puVar8[-1] = uVar9;
        if (plVar2 + ((longlong)(int)uVar9 + 2) * 4 == (longlong *)0x0) break;
        uVar5 = StorPortExtendedFunction
                          (0x26,param_1,plVar6,plVar2 + ((longlong)(int)uVar9 + 2) * 4,&local_res10)
        ;
        if ((int)uVar5 != 0) {
          return uVar5;
        }
        uVar9 = uVar9 - 1;
        puVar8 = puVar8 + -8;
      }
    }
  }
  return 0xc1000006;
}



===== UfsClearOutstandingRequests @ 140005bd8 =====

void UfsClearOutstandingRequests(longlong *param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if ((int)param_1[0x12d] != 0) {
    do {
      uVar1 = (uint)uVar2;
      if (((*(uint *)((longlong)param_1 + 0x4f4) >> (uVar1 & 0x1f) & 1) != 0) &&
         ((param_2 == 0xffffffff || (param_2 == *(byte *)(param_1[uVar2 * 2 + 0x133] + 2))))) {
        *(int *)((longlong)param_1 + 0x1a5c) = *(int *)((longlong)param_1 + 0x1a5c) + 1;
        UfsClearRequest(param_1,uVar1);
      }
      uVar2 = (ulonglong)(uVar1 + 1);
    } while (uVar1 + 1 < *(uint *)(param_1 + 0x12d));
  }
  return;
}



===== UfsClearRequest @ 140005c4c =====

void UfsClearRequest(longlong *param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  
  lVar1 = *param_1;
  lVar2 = param_1[(ulonglong)param_2 + 0x172];
  uVar5 = 1 << ((byte)param_2 & 0x1f);
  *(uint *)(lVar1 + 0x5c) = ~uVar5;
  LOCK();
  UNLOCK();
  uVar4 = 0;
  do {
    if ((*(uint *)(lVar1 + 0x58) & uVar5) != 0) break;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 10);
  uVar3 = UfsReleaseCompletionIndex(param_1,(longlong)(param_1 + 0x9e),param_2);
  if ((lVar2 != 0) && ((int)uVar3 == 0)) {
    *(undefined1 *)(lVar2 + 3) = 2;
    param_1[(ulonglong)param_2 + 0x172] = 0;
    StorPortNotification(0,param_1,lVar2);
  }
  return;
}



===== UfsCompleteTaskManRequest @ 140005cec =====

void UfsCompleteTaskManRequest(longlong *param_1,uint param_2)

{
  char cVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  char cVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 local_res10 [2];
  
  if (7 < param_2) {
    return;
  }
  uVar7 = (ulonglong)param_2;
  uVar2 = param_1[uVar7 + 0x96];
  lVar6 = uVar7 * 0x50 + param_1[0x94];
  uVar3 = *(uint *)(lVar6 + 8) & 0xff;
  if (uVar3 != 0) {
    if ((uVar3 == 6) || (uVar3 == 0xf)) {
      *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
      local_res10[0] = 0;
      cVar5 = '\x04';
      StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0,0,local_res10);
    }
    else {
      cVar5 = '\x04';
    }
    goto LAB_140005df0;
  }
  uVar3 = *(uint *)(lVar6 + 0x3c);
  uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  if (uVar3 == 0) {
LAB_140005d66:
    cVar5 = '\x01';
  }
  else if (uVar3 == 4) {
    cVar5 = '\x06';
  }
  else {
    if (uVar3 != 5) {
      if (uVar3 == 8) goto LAB_140005d66;
      if (uVar3 == 9) {
        cVar5 = ' ';
        goto LAB_140005d68;
      }
    }
    cVar5 = (*(char *)(lVar6 + 0x15) != '\x01') + '\x03';
  }
LAB_140005d68:
  cVar1 = *(char *)(lVar6 + 0x15);
  if (cVar1 == '\x01') {
    uVar3 = *(uint *)(lVar6 + 0x20);
    UfsClearRequest(param_1,uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                            uVar3 << 0x18);
  }
  else if (((cVar1 == '\x02') || (cVar1 == '\x04')) || (cVar1 == '\b')) {
    UfsClearOutstandingRequests(param_1,(uint)*(byte *)(lVar6 + 0x12));
  }
LAB_140005df0:
  if (uVar2 != 0) {
    *(char *)(uVar2 + 3) = cVar5;
    *(undefined1 *)(uVar2 + 4) = *(undefined1 *)(lVar6 + 0x37);
  }
  uVar4 = UfsReleaseCompletionIndex(param_1,(longlong)(param_1 + 2),param_2);
  if (((int)uVar4 != 0) && ((*(uint *)(param_1 + 0x193) & 0x8000) != 0)) {
    StorPortExtendedFunction
              (0x55,param_1,0,1,0x15,L"Complete task man request release completion index failed.",1
               ,2,0,0,L"status",uVar4 & 0xffffffff,L"srbStatus",cVar5);
  }
  uVar3 = *(uint *)(lVar6 + 0x3c);
  UfsAddDbgLog((longlong)param_1,0x544d436f,uVar7,uVar2,
               (ulonglong)
               (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18));
  return;
}



===== UfsCompleteUicCommandDpc @ 140005ed0 =====

uint UfsCompleteUicCommandDpc(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0xc98);
  if ((uVar2 & 2) == 0) {
    uVar2 = 1;
    LOCK();
    uVar1 = *(uint *)(param_2 + 0xce8);
    if (uVar1 == 1) {
      *(uint *)(param_2 + 0xce8) = 0;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  }
  return uVar2;
}



===== UfsCryptoEngineEnable @ 140005f00 =====

undefined8 UfsCryptoEngineEnable(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  
  lVar1 = *param_1;
  if ((char)param_1[0x193] < '\0') {
    if ((*(uint *)(lVar1 + 0x34) & 1) == 0) {
      uVar2 = 0xc1000009;
    }
    else {
      *(uint *)(lVar1 + 0x34) = *(uint *)(lVar1 + 0x34) | 2;
      uVar3 = 0;
      LOCK();
      UNLOCK();
      if ((int)param_1[0x1ca] * 1000 != 0) {
        do {
          UfsDelay(1);
          if ((*(uint *)(lVar1 + 0x34) & 2) != 0) break;
          uVar3 = uVar3 + 1;
        } while (uVar3 < (uint)((int)param_1[0x1ca] * 1000));
      }
      if (uVar3 == (int)param_1[0x1ca] * 1000) {
        uVar2 = 0xc1000001;
      }
      else {
        *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 0x100;
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0xc1000002;
  }
  return uVar2;
}



===== UfsFindAdapter @ 140005fb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 UfsFindAdapter(longlong *param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  uint uVar11;
  longlong in_stack_00000028;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  wchar_t *local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_88;
  undefined8 local_80;
  wchar_t *local_78;
  ulonglong local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_58 = 0;
  uStack_50 = 0;
  puVar1 = *(undefined2 **)(in_stack_00000028 + 0x40);
  *(uint *)(param_1 + 0x193) =
       (uint)(*(char *)(in_stack_00000028 + 0xc5) != '\0') | *(uint *)(param_1 + 0x193) & 0xfffffffe
  ;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  UfsInitializeDbgLog((longlong)param_1);
  param_1[0x349] = 0;
  param_1[0x34a] = 0;
  param_1[0x34b] = 0;
  param_1[0x34c] = 0;
  param_1[0x34d] = 0;
  param_1[0x34e] = 0;
  *(undefined4 *)(param_1 + 0x34f) = 0;
  if ((*(byte *)(param_1 + 0x193) & 1) != 0) {
    if (puVar1 == (undefined2 *)0x0) {
      return 2;
    }
    local_a8 = (undefined8 *)((ulonglong)local_a8 & 0xffffffff00000000);
    StorPortExtendedFunction(0x2d,param_1,puVar1,0x268);
    if ((*(byte *)(param_1 + 0x193) & 1) != 0) {
      *(undefined4 *)((longlong)param_1 + 0xe24) = *(undefined4 *)(puVar1 + 0x118);
      lVar5 = *(longlong *)(puVar1 + 0x11e);
      param_1[0x1c5] = *(longlong *)(puVar1 + 0x11a);
      param_1[0x1c6] = lVar5;
      lVar5 = *(longlong *)(puVar1 + 0x126);
      param_1[0x1c7] = *(longlong *)(puVar1 + 0x122);
      param_1[0x1c8] = lVar5;
      uVar2 = *(undefined4 *)(puVar1 + 300);
      uVar3 = *(undefined4 *)(puVar1 + 0x12e);
      uVar4 = *(undefined4 *)(puVar1 + 0x130);
      *(undefined4 *)(param_1 + 0x1c9) = *(undefined4 *)(puVar1 + 0x12a);
      *(undefined4 *)((longlong)param_1 + 0xe4c) = uVar2;
      *(undefined4 *)(param_1 + 0x1ca) = uVar3;
      *(undefined4 *)((longlong)param_1 + 0xe54) = uVar4;
      goto LAB_1400060d8;
    }
  }
  UfsRegistryReadControllerSettings(param_1);
LAB_1400060d8:
  if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
    if (*(int *)(in_stack_00000028 + 8) == 5) {
      local_a8 = &local_58;
      local_a0 = (wchar_t *)CONCAT44(local_a0._4_4_,0x30);
      iVar6 = StorPortGetBusData(param_1,4,*(undefined4 *)(in_stack_00000028 + 4),
                                 *(undefined4 *)(in_stack_00000028 + 100));
      if (iVar6 != 0x30) {
        return 2;
      }
      *(undefined2 *)(param_1 + 0x1c1) = (undefined2)local_58;
      *(undefined2 *)((longlong)param_1 + 0xe0a) = local_58._2_2_;
      *(undefined1 *)((longlong)param_1 + 0xe0c) = (undefined1)uStack_50;
      param_1[0x1c0] = local_48 & 0xfffffffffffff000;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x1c1) = *puVar1;
    *(undefined2 *)((longlong)param_1 + 0xe0a) = puVar1[1];
    *(undefined1 *)((longlong)param_1 + 0xe0c) = *(undefined1 *)(puVar1 + 2);
    param_1[0x1c0] = *(longlong *)(puVar1 + 4);
  }
  UfsGetRegisterAddress(param_1,in_stack_00000028);
  if (*param_1 == 0) {
    return 3;
  }
  *(uint *)(in_stack_00000028 + 0xdc) = *(uint *)(in_stack_00000028 + 0xdc) | 8;
  uVar11 = 0x20;
  *(undefined4 *)(in_stack_00000028 + 0xd0) = 0x20;
  *(undefined1 *)(in_stack_00000028 + 0x48) = 1;
  *(undefined2 *)(in_stack_00000028 + 0x61) = 1;
  *(undefined1 *)(in_stack_00000028 + 0x59) = 0;
  *(undefined4 *)(in_stack_00000028 + 0x30) = 3;
  *(undefined2 *)(in_stack_00000028 + 0x90) = 0x102;
  *(undefined2 *)(in_stack_00000028 + 0x51) = 0x101;
  *(undefined1 *)(in_stack_00000028 + 0x5b) = 1;
  *(undefined4 *)(in_stack_00000028 + 0x94) = 1;
  *(undefined1 *)(in_stack_00000028 + 0xc4) = 0;
  *(undefined8 *)(in_stack_00000028 + 0x84) = 0x1a80;
  *(undefined4 *)(in_stack_00000028 + 0x8c) = 0;
  *(undefined4 *)(in_stack_00000028 + 0xd8) = 0;
  *(undefined4 *)(in_stack_00000028 + 0x18) = 0x80000;
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
    *(undefined4 *)(in_stack_00000028 + 0x30) = 7;
  }
  uVar8 = UfsAllocateRequestLists(param_1,in_stack_00000028);
  if ((int)uVar8 != 0) {
    return 2;
  }
  if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
    UfsInitializeDpcs((longlong)param_1);
  }
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  plVar10 = param_1;
  uVar7 = UfsQcGetControllerVersion(param_1);
  if (0x3fff < uVar7) {
    UfsPhyGetCapabilities(plVar10);
  }
  if ((((*(byte *)(param_1 + 0x193) & 1) == 0) &&
      ((*(uint *)((longlong)param_1 + 0xe24) & 0x40000000) != 0)) &&
     (uVar7 = UfsQcGetControllerVersion8380(param_1), uVar7 == 0x50000000)) {
    *(uint *)((longlong)param_1 + 0xe24) = *(uint *)((longlong)param_1 + 0xe24) | 8;
    local_70 = (ulonglong)*(uint *)((longlong)param_1 + 0xe24);
    local_60 = 0;
    local_68 = 0;
    local_78 = L"FeatureFlags";
    local_80 = 0;
    local_88 = 0;
    local_90 = 3;
    local_98 = 1;
    local_a0 = 
    L"Successfully disabled featureflag with UFS_FEATURE_DISABLE_ICE for 8380 QC hardware.";
    local_a8 = (undefined8 *)CONCAT44(local_a8._4_4_,2);
    StorPortExtendedFunction(0x55,param_1,0,1);
  }
  uVar7 = 0;
  do {
    uVar9 = UfsStartAdapter(param_1);
    if ((int)uVar9 == 0) goto LAB_140006322;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 5);
  if (uVar7 == 5) {
    return 0;
  }
LAB_140006322:
  *(undefined1 *)(in_stack_00000028 + 0x92) = 8;
  *(undefined4 *)(in_stack_00000028 + 0x1c) = 0x40;
  if (*(byte *)((longlong)param_1 + 0x12f9) == 0) {
    if (*(byte *)((longlong)param_1 + 0x13bc) == 0) {
      *(undefined4 *)(in_stack_00000028 + 0xd0) = 0x20;
    }
    else {
      *(uint *)(in_stack_00000028 + 0xd0) = (uint)*(byte *)((longlong)param_1 + 0x13bc);
      uVar11 = (uint)*(byte *)((longlong)param_1 + 0x13bc);
    }
  }
  else {
    *(uint *)(in_stack_00000028 + 0xd0) = (uint)*(byte *)((longlong)param_1 + 0x12f9);
    uVar11 = (uint)*(byte *)((longlong)param_1 + 0x12f9);
  }
  *(uint *)(in_stack_00000028 + 0xd4) = uVar11;
  *(undefined4 *)(in_stack_00000028 + 0xcc) = 0x1f;
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xffffff8f;
  *(undefined4 *)(param_1 + 0x1cb) = 0x1f;
  return 1;
}



===== UfsHostControllerEnable @ 1400063c0 =====

undefined8 UfsHostControllerEnable(longlong *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = *param_1;
  *(undefined4 *)(lVar2 + 0x34) = 0;
  LOCK();
  UNLOCK();
  uVar3 = 0;
  do {
    StorPortStallExecution(10);
    uVar1 = *(uint *)(lVar2 + 0x34);
    if ((uVar1 & 1) == 0) goto LAB_140006422;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 1000000);
  if (uVar3 != 1000000) {
LAB_140006422:
    if (*(int *)((longlong)param_1 + 0xe24) < 0) {
      UfsIntelResetMphy(param_1);
    }
    *(uint *)(lVar2 + 0x34) = uVar1 | 1;
    LOCK();
    UNLOCK();
    uVar3 = 0;
    do {
      StorPortStallExecution(10);
      if ((*(uint *)(lVar2 + 0x34) & 1) != 0) goto LAB_140006462;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 1000000);
    if (uVar3 != 1000000) {
LAB_140006462:
      if ((*(uint *)((longlong)param_1 + 0xe24) & 0xa0000000) != 0) {
        *(uint *)(*param_1 + 0xc0) = *(uint *)(*param_1 + 0xc0) | 0x30000;
        LOCK();
        UNLOCK();
        UfsIntelPhyClearLcc(param_1);
      }
      if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
        UfsIntelPhyClearLcc(param_1);
      }
      *(uint *)(lVar2 + 0x24) = *(uint *)(lVar2 + 0x24) & 0xfffffbff;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0x1d2) = 1;
      *(undefined1 *)((longlong)param_1 + 0xe8c) = 1;
      *(undefined1 *)(param_1 + 0x1d0) = 0;
      return 0;
    }
  }
  return 0xc1000001;
}



===== UfsInitialize @ 1400064f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsInitialize(longlong *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStack_98 [32];
  uint local_78 [12];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_78[0] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[10] = 0;
  local_78[0xb] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
    local_78[1] = 0;
    StorPortNotification(0x1000,param_1,UfsPassiveInitialize,local_78 + 1);
  }
  else {
    LOCK();
    *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) | 1;
    UNLOCK();
    *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b4) & 0xfc;
    *(undefined1 *)((longlong)param_1 + 0xda1) = 1;
    *(undefined4 *)((longlong)param_1 + 0xda4) = 0;
    LOCK();
    *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffb;
    UNLOCK();
    *(undefined4 *)(param_1 + 0x1b8) = 0;
  }
  local_78[2] = 8;
  local_78[3] = 0x28;
  iVar3 = StorPortExtendedFunction(0xe,param_1,1,local_78 + 2);
  if (iVar3 == 0) {
    local_78[2] = 8;
    local_78[3] = 0x28;
    local_78[5] = KeQueryActiveProcessorCountEx(0xffff);
    local_78[4] = 3;
    uVar5 = StorPortExtendedFunction(0xe,param_1,0,local_78 + 2);
    if ((int)uVar5 == 0) goto LAB_14000660d;
LAB_140006673:
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  else {
LAB_14000660d:
    uVar1 = local_38;
    if (((*(uint *)(param_1 + 0x193) & 1) == 0) && ((*(uint *)(param_1 + 0x193) & 4) != 0)) {
      local_48 = 0x3000000001;
      local_38 = CONCAT71(local_38._1_7_,0xec);
      uVar2 = local_38;
      local_38._4_4_ = SUB84(uVar1,4);
      local_38._0_4_ = CONCAT22(1,(short)uVar2);
      uStack_30 = 0x400000001;
      local_28 = CONCAT53((int5)((ulonglong)local_28 >> 0x18),0xc40000);
      uStack_40 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0xea4),(int)param_1[0x1d5]);
      uStack_20 = CONCAT44(uStack_20._4_4_,1);
      uVar5 = StorPortExtendedFunction(0x44,param_1,0,&local_48);
      if ((int)uVar5 != 0) goto LAB_140006673;
    }
    uVar5 = UfsAdapterGetRefClkGatingWait(param_1,local_78);
    if ((int)uVar5 == 0) {
      uVar4 = 0xff;
      if (local_78[0] < 0xff) {
        uVar4 = local_78[0];
      }
    }
    else {
      uVar4 = 0;
    }
    *(uint *)((longlong)param_1 + 0xc9c) = uVar4;
    UfsTelemetryDeviceDesc((longlong)param_1);
    uVar5 = Feature_UfsTelemetryAndHealth__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      uVar5 = UfsTelemetryHealthDesc(param_1);
    }
    uVar5 = CONCAT71((int7)(uVar5 >> 8),1);
  }
  return uVar5;
}



===== UfsInitializeDpcs @ 1400066e8 =====

void UfsInitializeDpcs(longlong param_1)

{
  StorPortNotification(0x1001,param_1,param_1 + 0x440,UfsCompleteTaskManDpc);
  StorPortNotification(0x1001,param_1,param_1 + 0x920,UfsCompleteTransferDpc);
  StorPortNotification(0x1001,param_1,param_1 + 0xcf0,UfsCompleteUicCommandDpc);
  StorPortNotification(0x1001,param_1,param_1 + 0xd48,UfsResetBusDpc);
  return;
}



===== UfsInitializeRequestLists @ 140006788 =====

void UfsInitializeRequestLists(longlong *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = *param_1;
  *(undefined4 *)(lVar2 + 0x60) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar2 + 0x80) = 0;
  LOCK();
  UNLOCK();
  uVar1 = *(undefined4 *)((longlong)param_1 + 0x98c);
  *(int *)(lVar2 + 0x50) = (int)param_1[0x131];
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar2 + 0x54) = uVar1;
  LOCK();
  UNLOCK();
  uVar1 = *(undefined4 *)((longlong)param_1 + 0x4ac);
  *(int *)(lVar2 + 0x70) = (int)param_1[0x95];
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar2 + 0x74) = uVar1;
  LOCK();
  UNLOCK();
  return;
}



===== UfsPStateTimerDpc @ 140006830 =====

void UfsPStateTimerDpc(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  StorPortDebugPrint(3);
  if ((*(uint *)(param_2 + 0xdb8) & 1) != 0) {
    uVar1 = UfsPerfStateTransition(param_2,0);
    if ((char)uVar1 != '\0') {
      StorPortDebugPrint(3,"StorUfs - P-state transition successful\n");
    }
  }
  return;
}



===== UfsPassiveInitialize @ 140006890 =====

ulonglong UfsPassiveInitialize(longlong *param_1,longlong *param_2)

{
  int iVar1;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar2;
  bool bVar3;
  
  iVar1 = UfsInitializePower((longlong)param_1);
  uVar2 = CONCAT44(extraout_var,iVar1);
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      iVar1 = UfsQueryIceParameters(param_1,param_2);
      uVar2 = CONCAT44(extraout_var_00,iVar1);
      if (iVar1 == 0) {
        uVar2 = UfsCryptoEngineEnable(param_1);
        bVar3 = (int)uVar2 == 0;
      }
      else {
        bVar3 = iVar1 == -0x3efffffe;
      }
      if (!bVar3) goto LAB_1400068d6;
      uVar2 = UfsWriteBoosterInitialize(param_1);
    }
    uVar2 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  else {
LAB_1400068d6:
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== UfsQueryDeviceDescriptors @ 1400068e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UfsQueryDeviceDescriptors(longlong *param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined1 auStackY_e8 [32];
  undefined8 local_78;
  undefined8 uStack_70;
  uint local_68 [2];
  undefined8 local_60;
  undefined2 uStack_58;
  byte bStack_56;
  undefined5 uStack_55;
  undefined3 uStack_50;
  undefined5 uStack_4d;
  undefined8 uStack_48;
  undefined2 local_40;
  undefined1 local_3e;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_68[0] = 0;
  local_40 = 0;
  local_3e = 0;
  uStack_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  bStack_56 = 0;
  uStack_55 = 0;
  uStack_50 = 0;
  uStack_4d = 0;
  uStack_48 = 0;
  LOCK();
  puVar1 = (uint *)(param_1 + 0x1b5);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 | 1;
  UNLOCK();
  local_78 = 0x5a00000000000001;
  UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_78,0x5a,(undefined4 *)(param_1 + 0x25b));
  local_78._0_2_ = CONCAT11(7,(byte)local_78);
  *(uint *)(param_1 + 0x193) =
       ((uint)*(byte *)((longlong)param_1 + 0x12e5) << 2 ^ *(uint *)(param_1 + 0x193)) & 4 ^
       *(uint *)(param_1 + 0x193);
  local_78 = CONCAT26(0x5700,(undefined6)local_78);
  UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_78,0x57,(undefined4 *)((longlong)param_1 + 0x1332))
  ;
  *(uint *)((longlong)param_1 + 0xea4) = (uint)*(byte *)((longlong)param_1 + 0x1349) << 8;
  uStack_70 = 0;
  local_78 = 0x703;
  UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_78,4,local_68);
  if ((uint)*(byte *)((longlong)param_1 + 0x1347) <
      (local_68[0] >> 0x18 | (local_68[0] & 0xff0000) >> 8 | (local_68[0] & 0xff00) << 8 |
      local_68[0] << 0x18)) {
    StorPortExtendedFunction(0x55,param_1,0,1);
  }
  local_78 = CONCAT62(local_78._2_6_,0x201);
  local_78 = CONCAT26(0x2d00,(undefined6)local_78);
  UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_78,0x2d,(undefined4 *)((longlong)param_1 + 0x13b6))
  ;
  if ((*(uint *)(param_1 + 0x193) & 4) != 0) {
    local_78._0_3_ = CONCAT12(0xc4,(undefined2)local_78);
    local_78 = CONCAT26(0x2300,(undefined6)local_78);
    UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_78,0x23,(undefined4 *)&local_60);
    *(uint *)(param_1 + 0x1d5) =
         ((uint)(byte)((uint3)uStack_50 >> 0x10) |
          ((uint)(CONCAT35(uStack_50,uStack_55) >> 0x20) & 0xff0000) >> 8 |
          (uint)(CONCAT35(uStack_50,uStack_55) >> 0x18) & 0xff0000 |
         (uint)((uint5)uStack_55 >> 8) & 0xff000000) * (1 << (bStack_56 & 0x1f));
  }
  UfsQueryStringDescriptor
            (param_1,*(byte *)((longlong)param_1 + 0x12ec),(char *)((longlong)param_1 + 0x13e3));
  UfsQueryStringDescriptor
            (param_1,*(byte *)((longlong)param_1 + 0x12ed),(char *)((longlong)param_1 + 0x14e1));
  UfsQueryStringDescriptor
            (param_1,*(byte *)((longlong)param_1 + 0x12ef),(char *)((longlong)param_1 + 0x15df));
  UfsQueryStringDescriptor
            (param_1,*(byte *)((longlong)param_1 + 0x12ee),(char *)((longlong)param_1 + 0x16dd));
  UfsQueryStringDescriptor
            (param_1,*(byte *)((longlong)param_1 + 0x1302),(char *)((longlong)param_1 + 0x17db));
  if ((uVar2 & 1) == 0) {
    LOCK();
    *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffe;
    UNLOCK();
  }
  else {
    LOCK();
    *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) | 1;
    UNLOCK();
  }
  return;
}



===== UfsQueryIceParameters @ 140006b88 =====

int UfsQueryIceParameters(longlong *param_1,longlong *param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  int local_res8 [2];
  undefined4 *local_res10;
  
  local_res10 = (undefined4 *)0x0;
  uVar6 = 0;
  local_res8[0] = 0;
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xffffff7f;
  lVar2 = *param_1;
  if ((((*(uint *)((longlong)param_1 + 0xe24) & 8) == 0) &&
      (param_2 = param_1, iVar3 = StorPortExtendedFunction(0x37,param_1,0,&DAT_1400141c0,local_res8)
      , iVar3 == 0)) && (local_res8[0] == 1)) {
    *(uint *)(param_1 + 0x193) =
         (*(uint *)(param_1 + 0x1c2) >> 0x15 ^ *(uint *)(param_1 + 0x193)) & 0x80 ^
         *(uint *)(param_1 + 0x193);
  }
  if ((char)param_1[0x193] < '\0') {
    uVar1 = *(uint *)(lVar2 + 0x100);
    *(uint *)(param_1 + 0x339) = uVar1 & 0xff;
    if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
      param_1[0x33b] = (ulonglong)((uVar1 >> 0x18) << 8) + *param_1;
    }
    uVar6 = (uVar1 & 0xff) * 0x1c + 0xc;
    iVar3 = UfsAllocateContiguousMemory(param_1,param_2,uVar6,&local_res10);
    if (iVar3 == 0) {
      if (local_res10 == (undefined4 *)0x0) {
        return -0x3efffffd;
      }
      *local_res10 = 1;
      local_res10[1] = uVar6;
      *(ushort *)(local_res10 + 2) = (ushort)(uVar1 >> 8) & 0xff;
      *(short *)((longlong)local_res10 + 10) = (short)param_1[0x339];
      uVar5 = 0;
      if ((int)param_1[0x339] != 0) {
        do {
          uVar1 = *(uint *)(lVar2 + 0x104 + uVar5 * 4);
          local_res10[uVar5 * 7 + 6] = (uVar1 & 0xff) + 1;
          *(short *)(local_res10 + uVar5 * 7 + 5) = (short)uVar5;
          uVar4 = (int)uVar5 + 1;
          local_res10[uVar5 * 7 + 7] = uVar1 >> 0x10 & 0xff;
          local_res10[uVar5 * 7 + 3] = 1;
          local_res10[uVar5 * 7 + 4] = 0x1c;
          *(ushort *)(uVar5 * 0x1c + 0x16 + (longlong)local_res10) = (ushort)(uVar1 >> 8) & 0xff;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(uint *)(param_1 + 0x339));
      }
      param_2 = param_1;
      iVar3 = StorPortExtendedFunction(0x4d,param_1,local_res10);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x339) = 0;
    iVar3 = -0x3efffffe;
  }
  if (local_res10 != (undefined4 *)0x0) {
    UfsFreeContiguousMemory(param_1,param_2,(ulonglong)uVar6,(longlong)local_res10);
  }
  return iVar3;
}



===== UfsQueryStringDescriptor @ 140006d70 =====

ulonglong UfsQueryStringDescriptor(longlong *param_1,byte param_2,char *param_3)

{
  ulonglong uVar1;
  ushort *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 local_18;
  undefined1 auStack_16 [6];
  undefined8 uStack_10;
  
  uStack_10 = 0;
  _local_18 = CONCAT62(CONCAT51(0,param_2),0x501);
  _local_18 = CONCAT26(0xfe00,_local_18);
  uVar1 = UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_18,0xfe,(undefined4 *)param_3);
  if ((int)uVar1 == 0) {
    puVar2 = (ushort *)(param_3 + 2);
    if ((puVar2 == (ushort *)0x0) || ((byte)(*param_3 - 2U) < 2)) {
      uVar1 = 0xc1000006;
    }
    else {
      uVar3 = (uint)((byte)(*param_3 - 2U) >> 1);
      uVar1 = 0;
      if (uVar3 != 0) {
        uVar4 = (ulonglong)uVar3;
        do {
          *puVar2 = *puVar2 >> 8 | *puVar2 << 8;
          puVar2 = puVar2 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
    }
  }
  return uVar1;
}



===== UfsRegistryReadControllerSettings @ 140006e04 =====

void UfsRegistryReadControllerSettings(longlong *param_1)

{
  int iVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  uint *local_res18 [2];
  
  local_res18[0] = local_res8;
  *(undefined4 *)((longlong)param_1 + 0xe24) = 0;
  local_res8[0] = 0;
  local_res10[0] = 4;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"FeatureFlags",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)((longlong)param_1 + 0xe24) = local_res8[0];
  }
  *(undefined4 *)(param_1 + 0x1c5) = 0;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"HighSpeedGearMode",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x1c5) = local_res8[0];
  }
  *(undefined4 *)(param_1 + 0x1c6) = 0;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"HSSeries",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x1c6) = local_res8[0];
  }
  *(undefined4 *)((longlong)param_1 + 0xe2c) = 0;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"NumLanes",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)((longlong)param_1 + 0xe2c) = local_res8[0];
  }
  *(undefined4 *)((longlong)param_1 + 0xe34) = 1000;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"D3IdleTimeoutInMS",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)((longlong)param_1 + 0xe34) = local_res8[0];
  }
  *(undefined4 *)(param_1 + 0x1c7) = 0x32;
  iVar1 = StorPortExtendedFunction
                    (0x3e,param_1,0,"D3IdleTimeoutIoCoalescingInMS",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x1c7) = local_res8[0];
  }
  *(undefined4 *)((longlong)param_1 + 0xe3c) = 0x32;
  iVar1 = StorPortExtendedFunction
                    (0x3e,param_1,0,"LinkHibern8TimeoutInMS",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)((longlong)param_1 + 0xe3c) = local_res8[0];
  }
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffff7ff;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"UseDumpPointers",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x193) =
         (local_res8[0] & 1) << 0xb | *(uint *)(param_1 + 0x193) & 0xfffff7ff;
  }
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  iVar1 = StorPortExtendedFunction
                    (0x3e,param_1,0,"LinkHibern8ResidencyIntervalInUS",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x1c8) = local_res8[0];
  }
  *(undefined4 *)((longlong)param_1 + 0xe44) = 1;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"HPBFeatureToggle",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)((longlong)param_1 + 0xe44) = local_res8[0];
  }
  *(undefined4 *)(param_1 + 0x1c9) = 0;
  iVar1 = StorPortExtendedFunction
                    (0x3e,param_1,0,"WriteBoosterFeatureToggle",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x1c9) = local_res8[0];
  }
  uVar2 = Feature_WriteBoosterSupportUFS2_2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    *(undefined4 *)((longlong)param_1 + 0xe4c) = 0;
    iVar1 = StorPortExtendedFunction
                      (0x3e,param_1,0,"WriteBoosterUFS2_2_Support",4,local_res18,local_res10);
    if (iVar1 == 0) {
      *(uint *)((longlong)param_1 + 0xe4c) = local_res8[0];
    }
  }
  UfsScsiSendDiagnosticRequest(param_1);
  *(undefined4 *)(param_1 + 0x1ca) = 10000;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"CommandTimeoutInMS",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x1ca) = local_res8[0];
  }
  *(undefined4 *)((longlong)param_1 + 0xe54) = 0x2000;
  iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"DebugLogSize",4,local_res18,local_res10);
  if (iVar1 == 0) {
    *(uint *)((longlong)param_1 + 0xe54) = local_res8[0];
    UfsInitializeDbgLog((longlong)param_1);
  }
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
    UfsIntelLkfRegistryReadControllerSettings((longlong)param_1);
  }
  if ((iVar1 != 0) && ((*(uint *)(param_1 + 0x193) & 0x8000) != 0)) {
    StorPortExtendedFunction
              (0x56,param_1,0,1,0xe,L"Registry Read Controller settings routine failed.",1,2,0,0,
               L"regDwordData",local_res8[0],L"dataLength",local_res10[0],L"status",iVar1,0,0);
  }
  return;
}



===== UfsResetBus @ 140007320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char UfsResetBus(longlong *param_1)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 auStackY_e8 [32];
  uint local_58 [2];
  undefined8 local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_50 = 0;
  local_48 = 0;
  local_58[0] = 0;
  cVar3 = '\x01';
  puVar1 = (uint *)(param_1 + 0x193);
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
    cVar3 = UfsIntelLkfResetBus(param_1);
    goto LAB_140007488;
  }
  if ((*puVar1 & 1) != 0) goto LAB_140007488;
  StorPortNotification(0xb,param_1);
  LOCK();
  if ((int)param_1[0x1a8] == 0) {
    *(int *)(param_1 + 0x1a8) = 1;
  }
  UNLOCK();
  UfsAddDbgLog((longlong)param_1,0x52657342,0,0,0);
  *(int *)((longlong)param_1 + 0x1a54) = *(int *)((longlong)param_1 + 0x1a54) + 1;
  UfsClearOutstandingRequests(param_1,0xffffffff);
  uVar4 = UfsExecuteUicCommandSynchronous(param_1,0x15,(uint *)&local_50,local_58);
  if (((int)uVar4 == 0) && (local_58[0] == 0)) {
    UfsStopAdapter(param_1);
    uVar4 = UfsStartAdapter(param_1);
    if (((int)uVar4 != 0) ||
       (((char)*puVar1 < '\0' && (uVar5 = UfsCryptoEngineEnable(param_1), (int)uVar5 != 0))))
    goto LAB_140007460;
    UfsWriteBoosterInitialize(param_1);
  }
  else {
LAB_140007460:
    cVar3 = '\0';
  }
  StorPortNotification(10,param_1);
LAB_140007488:
  LOCK();
  if ((int)param_1[0x1a8] == 1) {
    *(int *)(param_1 + 0x1a8) = 0;
  }
  UNLOCK();
  if (cVar3 == '\0') {
    UfsScsiSendDiagnosticRequest(param_1);
    uVar2 = *puVar1;
  }
  else {
    uVar2 = *puVar1;
  }
  if ((uVar2 & 0x8000) != 0) {
    StorPortExtendedFunction(0x56,param_1,0,1);
  }
  return cVar3;
}



===== UfsResetBusDpc @ 140007620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfsResetBusDpc(undefined8 param_1,longlong *param_2,undefined *param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_20 = 0;
  local_28 = 5;
  local_18 = 0;
  uStack_10 = 0;
  StorPortExtendedFunction(0x5d,param_2,5,param_1,&local_28);
  cVar1 = UfsResetBus(param_2);
  if (param_3 != (undefined *)0x0) {
    (*(code *)param_3)(param_2,cVar1,param_4);
  }
  StorPortNotification(0x1004,param_2,&local_28);
  return;
}



===== UfsSetPStateTimer @ 1400076bc =====

void UfsSetPStateTimer(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  lVar1 = KeQueryInterruptTimePrecise(local_res8);
  uVar3 = *(ulonglong *)(param_1 + 0x1288);
  uVar2 = lVar1 - *(longlong *)(param_1 + 0x1290);
  uVar2 = -(ulonglong)(uVar2 < uVar3) & uVar3 - uVar2;
  if (uVar2 < uVar3) {
    uVar3 = uVar2;
  }
  StorPortExtendedFunction
            (0x21,param_1,*(undefined8 *)(param_1 + 0x12b0),UfsPerfStateTransition,param_1,-uVar3,0)
  ;
  return;
}



===== UfsStartAdapter @ 140007744 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsStartAdapter(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint *puVar3;
  int iVar4;
  ulonglong uVar5;
  longlong *plVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 local_158 [32];
  char local_88 [4];
  uint local_84 [3];
  byte local_78 [17];
  undefined2 local_67;
  undefined1 local_65;
  undefined4 local_64;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined8 local_4c;
  uint local_40 [4];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_158;
  lVar1 = *param_1;
  local_84[1] = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_67 = 0;
  local_65 = 0;
  local_5c = 0;
  local_4c = 0;
  local_88[0] = '\x01';
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
    uVar5 = UfsIntelLkfStartAdapter(param_1,(undefined1 *)0x0);
    return uVar5;
  }
  if ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1c & 1) != 0) {
    UfsSetUpToshibaAdapter((longlong)param_1);
  }
  uVar5 = UfsHostControllerEnable(param_1);
  uVar10 = uVar5 & 0xffffffff;
  if ((int)uVar5 != 0) {
    StorPortDebugPrint(0,"Host Controller enable attempt failed with status %x\n",uVar5 & 0xffffffff
                      );
    goto LAB_140007b80;
  }
  if ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1e & 1) != 0) {
    UfsQcPreLinkAdapterConfig(param_1);
  }
  uVar8 = 0;
  do {
    uVar5 = UfsExecuteUicCommandSynchronous(param_1,0x16,local_40,local_84 + 1);
    if ((*(uint *)(lVar1 + 0x30) & 1) != 0) goto LAB_140007851;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 5);
  if (uVar8 == 5) {
    pcVar7 = "UIC_DME_LINKSTARTUP exhausted attempts with status %x\n";
LAB_140007835:
    StorPortDebugPrint(1,pcVar7,uVar5 & 0xffffffff);
    uVar10 = 0xc1000001;
  }
  else {
LAB_140007851:
    if ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1e & 1) == 0) {
      if ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1c & 1) != 0) {
        UfsToshibaPostLinkAdapterConfig(param_1);
      }
    }
    else {
      lVar2 = *param_1;
      local_84[0] = 0;
      UfsSendUicDmeGet(param_1,0x1540,0,local_84);
      *(int *)(lVar2 + 0x3744) = ~(-1 << ((byte)local_84[0] & 0x1f));
      LOCK();
      UNLOCK();
    }
    UfsInitializeRequestLists(param_1);
    puVar3 = (uint *)*param_1;
    *(uint *)(param_1 + 0x1c2) = *puVar3;
    *(uint *)((longlong)param_1 + 0xe14) = puVar3[2];
    *(uint *)(param_1 + 0x1c3) = puVar3[4];
    *(uint *)((longlong)param_1 + 0xe1c) = puVar3[5];
    *(uint *)(param_1 + 0x1c4) = puVar3[6];
    plVar6 = param_1;
    uVar8 = UfsQcGetControllerVersion(param_1);
    if (uVar8 < 0x4000) {
      UfsPhyGetCapabilities(plVar6);
    }
    *(undefined4 *)(lVar1 + 0x60) = 1;
    LOCK();
    UNLOCK();
    *(undefined4 *)(lVar1 + 0x80) = 1;
    LOCK();
    UNLOCK();
    *(undefined4 *)(lVar1 + 0x20) = 0xffffffff;
    LOCK();
    UNLOCK();
    uVar8 = *(uint *)(param_1 + 0x1b5);
    uVar9 = 0;
    LOCK();
    *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) | 1;
    UNLOCK();
    do {
      uVar5 = UfsSendNopOutUpiu(param_1);
      uVar10 = uVar5 & 0xffffffff;
      if ((int)uVar5 == 0) goto LAB_14000796d;
      uVar9 = uVar9 + 1;
    } while (uVar9 < 5);
    if (uVar9 == 5) {
      StorPortDebugPrint(1,"UfsSendNopOutUpiu exhausted attempts with status %x\n",
                         uVar5 & 0xffffffff);
      goto LAB_140007b80;
    }
LAB_14000796d:
    if (*(char *)((longlong)param_1 + 0xe5c) != '\0') {
      UfsToggleAndWaitRefClkGating((longlong)param_1,'\x01');
      local_64 = (undefined4)param_1[0x1cc];
      local_78[0x10] = *(undefined1 *)((longlong)param_1 + 0xe5c);
      local_60 = *(undefined4 *)((longlong)param_1 + 0xe64);
      local_54 = (undefined4)param_1[0x1ce];
      local_50 = *(undefined4 *)((longlong)param_1 + 0xe74);
      UfsPhySetSpeedMode(param_1,(char *)(local_78 + 0x10));
    }
    uVar9 = 0;
    local_78[8] = 0;
    local_78[9] = 0;
    local_78[10] = 0;
    local_78[0xb] = 0;
    local_78[0xc] = 0;
    local_78[0xd] = 0;
    local_78[0xe] = 0;
    local_78[0xf] = 0;
    local_78[0] = 6;
    local_78[1] = 1;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[6] = 0;
    local_78[7] = 0;
    do {
      uVar5 = UfsSendQueryUpiu(param_1,-0x7f,local_78,0,(undefined4 *)0x0);
      if ((int)uVar5 == 0) break;
      uVar9 = uVar9 + 1;
    } while (uVar9 < 5);
    if (uVar9 != 5) {
      UfsDelay(300);
      uVar9 = 0;
      local_78[8] = 0;
      local_78[9] = 0;
      local_78[10] = 0;
      local_78[0xb] = 0;
      local_78[0xc] = 0;
      local_78[0xd] = 0;
      local_78[0xe] = 0;
      local_78[0xf] = 0;
      local_78[0] = 5;
      local_78[1] = 1;
      local_78[2] = 0;
      local_78[3] = 0;
      local_78[4] = 0;
      local_78[5] = 0;
      local_78[6] = 0;
      local_78[7] = 0;
      do {
        uVar5 = UfsSendQueryUpiu(param_1,'\x01',local_78,0,(undefined4 *)local_88);
        if (((int)uVar5 == 0) && (local_88[0] == '\0')) break;
        UfsDelay(3);
        uVar9 = uVar9 + 1;
      } while (uVar9 < 1000);
      if (uVar9 == 1000) {
        pcVar7 = "fDeviceInit not set to zero by device, exhausted attempts with status %x\n";
        goto LAB_140007835;
      }
      UfsGetInitPowerMode(param_1);
      uVar9 = 0;
      do {
        UfsSendRequestSenseTransferRequest(param_1,(byte)uVar9);
        uVar9 = uVar9 + 1;
      } while (uVar9 < 8);
      UfsSendRequestSenseTransferRequest(param_1,0xc4);
      UfsSendRequestSenseTransferRequest(param_1,0xb0);
      UfsSendRequestSenseTransferRequest(param_1,0xd0);
      UfsScsiWaitUntilTestUnitReadyRequest(param_1,0xc4);
      UfsScsiWaitUntilTestUnitReadyRequest(param_1,0xb0);
      uVar5 = UfsScsiWaitUntilTestUnitReadyRequest(param_1,0xd0);
      if ((uVar8 & 1) == 0) {
        LOCK();
        *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffe;
        UNLOCK();
      }
      *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffffbff;
      uVar8 = *(uint *)((longlong)param_1 + 0xe24);
      if (((uVar8 >> 0x1e & 1) == 0) && ((*(uint *)(param_1 + 0x1c2) & 0x800000) != 0)) {
        if ((uVar8 & 0xa0000000) != 0) {
          iVar4 = UfsIntelPhySetHibern8Attr(param_1);
          if (iVar4 != 0) {
            return 0xc1000001;
          }
          uVar8 = *(uint *)((longlong)param_1 + 0xe24);
          if (((byte)uVar8 & 3) == 1) {
            *(undefined4 *)(param_1 + 0x1c4) = 0xc0a;
          }
        }
        if (((byte)uVar8 & 3) == 1) {
          *(int *)(lVar1 + 0x18) = (int)param_1[0x1c4];
          LOCK();
          UNLOCK();
          *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 0x400;
        }
      }
      UfsQueryDeviceDescriptors(param_1);
      *(undefined4 *)(lVar1 + 0x20) = 0xffffffff;
      LOCK();
      UNLOCK();
      if ((*(uint *)(param_1 + 0x1b5) & 2) == 0) {
        *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) | 0x31a85;
        LOCK();
        UNLOCK();
      }
      *(undefined4 *)(lVar1 + 0x4c) = 0;
      LOCK();
      UNLOCK();
    }
    uVar10 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 0) {
      uVar5 = Feature_UfsTelemetryAndHealth__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        return uVar10;
      }
      UfsLogTelemetryEx(param_1,param_1 + 0x1bf,(ulonglong)*(byte *)((longlong)param_1 + 0xe5c),4,
                        "Ufs Capabilities");
      return uVar10;
    }
  }
LAB_140007b80:
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction(0x55,param_1,0);
  }
  return uVar10;
}



===== UfsStopAdapter @ 140007d58 =====

void UfsStopAdapter(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = *param_1;
  uVar2 = 0;
  *(undefined4 *)(lVar1 + 0x24) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar1 + 0x20) = 0xffffffff;
  LOCK();
  UNLOCK();
  UfsClearOutstandingRequests(param_1,0xffffffff);
  *(undefined4 *)(lVar1 + 0x34) = 0;
  LOCK();
  UNLOCK();
  do {
    StorPortStallExecution(10);
    if ((*(uint *)(lVar1 + 0x34) & 1) == 0) {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 1000000);
  return;
}



===== UfsUnitControl @ 140007dc0 =====

undefined8 UfsUnitControl(longlong param_1,int param_2,longlong param_3)

{
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 6) = 0x101;
    *(undefined1 *)(param_3 + 4) = 1;
  }
  else if (param_2 == 1) {
    if (*(int *)(param_3 + 8) == 2) {
      *(uint *)(param_1 + 0xc98) =
           *(uint *)(param_1 + 0xc98) | -(uint)(*(char *)(param_3 + 0xc) != '\0') & 0x200;
    }
  }
  else if ((param_2 != 2) && (param_2 != 3)) {
    return 1;
  }
  return 0;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140007e18 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140018ba7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140007e44 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140007f1c =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140008000 =====

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
LAB_140008158:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000814b:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140008158;
      if (uVar5 == 5) goto LAB_14000814b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140008180 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140008204 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400082f4 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140008404 =====

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
    do {
      if ((uVar3 & 2) == 0) {
        return;
      }
      if (((uVar3 ^ param_1) & 1) != 0) {
        return;
      }
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
    } while (!bVar5);
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 140008460 =====

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



===== wil_details_IsEnabledFallback @ 1400085c0 =====

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



===== wil_details_MapReportingKind @ 140008654 =====

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



===== wil_details_RecordCachedUsage @ 1400086f4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140008850 =====

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



===== Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline @ 1400088d4 =====

ulonglong Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_FirmwareUpdateFailure__private_featureState;
  if ((Feature_FirmwareUpdateFailure__private_featureState & 0x10) == 0) {
    uVar1 = Feature_FirmwareUpdateFailure__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_FirmwareUpdateFailure__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_FirmwareUpdateFailure__private_IsEnabledFallback @ 14000890c =====

void Feature_FirmwareUpdateFailure__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_FirmwareUpdateFailure__private_descriptor);
  return;
}



===== UfsCreateFirmwareUpdatePrdt @ 140008928 =====

void UfsCreateFirmwareUpdatePrdt
               (longlong param_1,longlong param_2,uint *param_3,uint param_4,undefined4 *param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  
  uVar4 = 0;
  uVar3 = 0;
  uVar5 = 0;
  uVar9 = (ulonglong)param_4;
  if (*param_3 != 0) {
    do {
      uVar6 = param_3[uVar5 * 6 + 6];
      uVar1 = (uint)uVar9;
      if (uVar1 == 0) {
        lVar7 = *(longlong *)(param_3 + uVar5 * 6 + 4);
        for (; uVar6 != 0; uVar6 = uVar6 + (-1 - uVar1)) {
          puVar2 = (undefined4 *)(uVar4 * 0x10 + param_2);
          UfsFillPrdtData(param_1,puVar2,(int)lVar7,(int)((ulonglong)lVar7 >> 0x20),uVar6);
          uVar1 = puVar2[3];
          uVar4 = (ulonglong)((int)uVar4 + 1);
          puVar2[3] = uVar1;
          uVar1 = uVar1 & 0x3ffff;
          lVar7 = lVar7 + (ulonglong)(uVar1 + 1);
        }
      }
      else if (uVar1 < uVar6) {
        lVar7 = *(longlong *)(param_3 + uVar5 * 6 + 4);
        for (; uVar6 != 0; uVar6 = uVar6 + ((-1 - uVar1) - iVar8)) {
          iVar8 = (int)uVar9;
          puVar2 = (undefined4 *)(uVar4 * 0x10 + param_2);
          UfsFillPrdtData(param_1,puVar2,(int)lVar7 + iVar8,(int)((ulonglong)lVar7 >> 0x20),
                          uVar6 - iVar8);
          uVar1 = puVar2[3];
          uVar4 = (ulonglong)((int)uVar4 + 1);
          puVar2[3] = uVar1;
          uVar1 = uVar1 & 0x3ffff;
          uVar9 = 0;
          lVar7 = lVar7 + (ulonglong)(uVar1 + iVar8 + 1);
        }
      }
      else if (uVar1 == uVar6) {
        uVar9 = 0;
      }
      else {
        uVar9 = (ulonglong)(uVar1 - uVar6);
      }
      uVar3 = (undefined4)uVar4;
      uVar6 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar6;
    } while (uVar6 < *param_3);
  }
  *param_5 = uVar3;
  return;
}



===== UfsGetPurgeDeviceRequestStatus @ 140008a50 =====

void UfsGetPurgeDeviceRequestStatus(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint local_res8 [2];
  byte local_18 [16];
  
  local_res8[0] = 0;
  local_18[8] = 0;
  local_18[9] = 0;
  local_18[10] = 0;
  local_18[0xb] = 0;
  local_18[0xc] = 0;
  local_18[0xd] = 0;
  local_18[0xe] = 0;
  local_18[0xf] = 0;
  local_18[0] = 3;
  local_18[1] = 6;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar4 = UfsSendQueryUpiu(param_1,'\x01',local_18,4,local_res8);
  if (((int)uVar4 == 0) &&
     (uVar2 = local_res8[0] >> 0x18 | (local_res8[0] & 0xff0000) >> 8 |
              (local_res8[0] & 0xff00) << 8 | local_res8[0] << 0x18, uVar2 != 0)) {
    if (uVar2 == 1) {
      plVar1 = param_1 + 0x338;
      if (*plVar1 == 0) {
        StorPortExtendedFunction(0x20,param_1,plVar1);
      }
      if ((*plVar1 != 0) &&
         (iVar3 = StorPortExtendedFunction
                            (0x21,param_1,*plVar1,UfsGetPurgeDeviceRequestStatus,param_2,1000000,
                             100000), iVar3 == 0)) {
        return;
      }
    }
    else {
      if (uVar2 == 2) {
        *(undefined1 *)(param_2 + 3) = 2;
        *(int *)(param_1 + 0x34c) = (int)param_1[0x34c] + 1;
        goto LAB_140008b30;
      }
      if (uVar2 == 3) {
        *(undefined1 *)(param_2 + 3) = 1;
        goto LAB_140008b30;
      }
    }
  }
  *(undefined1 *)(param_2 + 3) = 0x30;
LAB_140008b30:
  StorPortNotification(0,param_1,param_2);
  StorPortResume(param_1);
  if (param_1[0x338] != 0) {
    StorPortExtendedFunction(0x22,param_1);
    param_1[0x338] = 0;
  }
  return;
}



===== UfsScsiSendDiagnosticRequest @ 140008b94 =====

ulonglong UfsScsiSendDiagnosticRequest(longlong *param_1)

{
  undefined2 *puVar1;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint *puVar7;
  uint *puVar8;
  ulonglong uVar9;
  char cVar10;
  undefined4 uVar11;
  uint uVar12;
  byte *pbVar13;
  
  pbVar13 = (byte *)0x0;
  uVar12 = 0;
  while( true ) {
    puVar8 = (uint *)(param_1 + 0x9e);
    bVar2 = false;
    uVar3 = UfsAcquireBuildIndex((longlong)param_1,puVar8);
    if ((uVar3 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar3)) break;
    uVar11 = 0;
    param_1[(ulonglong)uVar3 + 0x172] = 0;
    puVar4 = (uint *)((ulonglong)uVar3 * 0x20 + param_1[0x130]);
    cVar10 = '\x01';
    puVar7 = puVar8 + ((ulonglong)uVar3 + 0x4a) * 4;
    UfsInitializeTrdUcd(puVar4,puVar7,2,1);
    puVar1 = *(undefined2 **)(puVar7 + 2);
    *(byte *)(puVar1 + 2) = *(byte *)(puVar1 + 2) & 0xf;
    *puVar1 = 0x4001;
    *(byte *)((longlong)puVar1 + 0x11) = *(byte *)((longlong)puVar1 + 0x11) & 0xb | 4;
    *(char *)((longlong)puVar1 + 3) = (char)uVar3;
    *(char *)(puVar1 + 4) = (char)uVar11;
    puVar1[5] = (short)uVar11;
    *(undefined4 *)(puVar1 + 6) = uVar11;
    *(undefined1 *)(puVar1 + 8) = 0x1d;
    uVar5 = UfsReleaseBuildIndex((longlong)param_1,puVar8,(ulonglong)uVar3,cVar10);
    if ((char)uVar5 != '\x01') {
      uVar9 = 0xc1000001;
      UfsClearRequest(param_1,uVar3);
      goto LAB_140008d1f;
    }
    uVar6 = UfsWaitForCompletedRequest(param_1,uVar3,0xffffffff,0,(int)param_1[0x1ca],0);
    uVar9 = uVar6 & 0xffffffff;
    if ((int)uVar6 != 0) goto LAB_140008d1f;
    uVar6 = (ulonglong)*(ushort *)((longlong)puVar4 + 0x1a);
    cVar10 = *(char *)((longlong)puVar1 + uVar6 * 4 + 7);
    if (cVar10 == '\x02') {
      pbVar13 = (byte *)(puVar1 + uVar6 * 2 + 0x11);
      bVar2 = false;
      if ((pbVar13 != (byte *)0x0) && ((pbVar13[2] & 0xf) == 6)) {
        bVar2 = true;
        uVar12 = uVar12 + 1;
        UfsDelay(5);
      }
      if (5 < uVar12) {
        return uVar9;
      }
    }
    else if (cVar10 != '\0') {
      uVar9 = 0xc1000001;
      goto LAB_140008d1f;
    }
    if (!bVar2) {
      return uVar9;
    }
  }
  uVar9 = 0xc100000c;
LAB_140008d1f:
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    if (pbVar13 == (byte *)0x0) {
      StorPortExtendedFunction
                (0x56,param_1,0,1,0x18,L"Send diagnostic request failed.",1,3,0,0,L"index",uVar3,
                 L"status",uVar9,0,0,0,0);
    }
    else {
      StorPortExtendedFunction
                (0x57,param_1,0,1,0x18,L"Send diagnostic request failed.",1,3,0,0,L"SenseKey",
                 pbVar13[2] & 0xf,L"AdditionalSenseCode",pbVar13[0xc],
                 L"AdditionalSenseCodeQualifier",pbVar13[0xd],L"ErrorCode",*pbVar13 & 0x7f,L"index",
                 uVar3,L"status",uVar9,0,0,0,0);
    }
  }
  return uVar9;
}



===== UfsScsiWaitUntilTestUnitReadyRequest @ 140008ef0 =====

ulonglong UfsScsiWaitUntilTestUnitReadyRequest(longlong *param_1,byte param_2)

{
  uint *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint *puVar6;
  ulonglong uVar7;
  byte *pbVar8;
  char cVar9;
  uint *puVar10;
  ulonglong uVar11;
  
  puVar1 = (uint *)(param_1 + 0x9e);
  pbVar8 = (byte *)0x0;
  do {
    uVar3 = UfsAcquireBuildIndex((longlong)param_1,puVar1);
    uVar11 = (ulonglong)uVar3;
    if ((uVar3 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar3)) {
      uVar7 = 0xc100000c;
LAB_140009046:
      if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
        if (pbVar8 == (byte *)0x0) {
          StorPortExtendedFunction
                    (0x56,param_1,0,1,5,L"Test unit ready request failed.",1,3,0,0,L"index",uVar11,
                     L"status",uVar7,0,0,0,0);
        }
        else {
          StorPortExtendedFunction
                    (0x57,param_1,0,1,5,L"Test unit ready request failed.",1,3,0,0,L"SenseKey",
                     pbVar8[2] & 0xf,L"AdditionalSenseCode",pbVar8[0xc],
                     L"AdditionalSenseCodeQualifier",pbVar8[0xd],L"ErrorCode",*pbVar8 & 0x7f,
                     L"index",uVar11,L"status",uVar7,0,0,0,0);
        }
      }
      return uVar7;
    }
    cVar9 = '\x01';
    param_1[uVar11 + 0x172] = 0;
    puVar10 = (uint *)((ulonglong)uVar3 * 0x20 + param_1[0x130]);
    puVar6 = puVar1 + (uVar11 + 0x4a) * 4;
    UfsInitializeTrdUcd(puVar10,puVar6,2,1);
    puVar2 = *(undefined2 **)(puVar6 + 2);
    *(byte *)(puVar2 + 2) = *(byte *)(puVar2 + 2) & 0xf;
    *puVar2 = 0x4001;
    *(byte *)(puVar2 + 1) = param_2;
    *(char *)((longlong)puVar2 + 3) = (char)uVar3;
    *(undefined1 *)(puVar2 + 4) = 0;
    puVar2[5] = 0;
    *(undefined4 *)(puVar2 + 6) = 0;
    *(undefined1 *)(puVar2 + 8) = 0;
    *(undefined1 *)((longlong)puVar2 + 0x15) = 0;
    uVar4 = UfsReleaseBuildIndex((longlong)param_1,puVar1,(ulonglong)uVar3,cVar9);
    if ((char)uVar4 != '\x01') {
      uVar7 = 0xc1000001;
      goto LAB_140009046;
    }
    uVar5 = UfsWaitForCompletedRequest(param_1,uVar3,0xffffffff,(uint)param_2,(int)param_1[0x1ca],0)
    ;
    uVar7 = uVar5 & 0xffffffff;
    if ((int)uVar5 != 0) goto LAB_140009046;
    uVar5 = (ulonglong)*(ushort *)((longlong)puVar10 + 0x1a);
    cVar9 = *(char *)((longlong)puVar2 + uVar5 * 4 + 7);
    if (cVar9 != '\x02') {
      if (cVar9 == '\0') {
        return uVar7;
      }
      uVar7 = 0xc1000001;
      goto LAB_140009046;
    }
    pbVar8 = (byte *)(puVar2 + uVar5 * 2 + 0x11);
    if (pbVar8 == (byte *)0x0) {
      return uVar7;
    }
    if ((pbVar8[2] & 0xf) != 6) {
      return uVar7;
    }
    UfsDelay(5);
  } while( true );
}



===== UfsSendInquiryRequest @ 140009220 =====

ulonglong UfsSendInquiryRequest(longlong *param_1,byte param_2)

{
  uint *puVar1;
  ushort uVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint *puVar9;
  wchar_t *pwVar10;
  
  puVar1 = (uint *)(param_1 + 0x9e);
  pwVar10 = L"Sending Inquiry Request failed.";
  uVar4 = UfsAcquireBuildIndex((longlong)param_1,puVar1);
  uVar8 = 0;
  if ((uVar4 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar4)) {
    uVar8 = 0xc100000c;
  }
  else {
    param_1[(ulonglong)uVar4 + 0x172] = 0;
    puVar9 = (uint *)((ulonglong)uVar4 * 0x20 + param_1[0x130]);
    puVar7 = puVar1 + ((ulonglong)uVar4 + 0x4a) * 4;
    UfsInitializeTrdUcd(puVar9,puVar7,2,1);
    puVar3 = *(undefined2 **)(puVar7 + 2);
    uVar2 = *(ushort *)((longlong)puVar9 + 0x1e);
    *(byte *)(puVar3 + 2) = *(byte *)(puVar3 + 2) & 0xf;
    *puVar3 = 0x4001;
    *(byte *)(puVar3 + 1) = param_2;
    *(char *)((longlong)puVar3 + 3) = (char)uVar4;
    *(char *)(puVar3 + 4) = (char)uVar8;
    puVar3[5] = (short)uVar8;
    *(byte *)((longlong)puVar3 + 0x11) = *(byte *)((longlong)puVar3 + 0x11) & 0xfe;
    *(undefined1 *)(puVar3 + 8) = 0x12;
    *(char *)(puVar3 + 9) = (char)uVar8;
    puVar3[10] = 0x24;
    *(undefined4 *)(puVar3 + 6) = 0x24000000;
    UfsFillPrdtData((longlong)param_1,(undefined4 *)(puVar3 + (ulonglong)uVar2 * 2),
                    (int)param_1[0x25a],*(undefined4 *)((longlong)param_1 + 0x12d4),0x24);
    uVar6 = (ulonglong)uVar4;
    UfsAddDbgLog((longlong)param_1,0x54724952,uVar6,(ulonglong)param_2,uVar8);
    uVar5 = UfsReleaseBuildIndex((longlong)param_1,puVar1,uVar6,'\x01');
    if ((char)uVar5 == '\x01') {
      uVar6 = UfsWaitForCompletedRequest
                        (param_1,uVar4,0xffffffff,(uint)param_2,(int)param_1[0x1ca],0);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 == 0) {
        if (*(char *)((longlong)puVar3 + (ulonglong)*(ushort *)((longlong)puVar9 + 0x1a) * 4 + 7) ==
            '\0') {
          return uVar8;
        }
        uVar8 = 0xc1000001;
        pwVar10 = L"Sending of inquiry request failed with operation unsuccessful.";
      }
      else {
        pwVar10 = L"Sending inquiry Request failed in wait completion request.";
      }
    }
    else {
      uVar8 = 0xc1000001;
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction(0x55,param_1,0,1,3,pwVar10,1,3,0,0,L"index",uVar4,L"status",uVar8);
  }
  return uVar8;
}



===== UfsSendNopOutUpiu @ 14000942c =====

ulonglong UfsSendNopOutUpiu(longlong *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  ulonglong in_stack_ffffffffffffff98;
  
  pwVar7 = L"Sending a NOP OUT request failed.";
  uVar1 = UfsAcquireBuildIndex((longlong)param_1,(uint *)(param_1 + 0x9e));
  uVar6 = (ulonglong)uVar1;
  if ((uVar1 != 0xffffffff) && (uVar1 < *(uint *)(param_1 + 0x12d))) {
    param_1[uVar6 + 0x172] = 0;
    uVar3 = 0;
    UfsInitializeTrdUcd((uint *)((ulonglong)uVar1 * 0x20 + param_1[0x130]),
                        (uint *)(param_1 + (uVar6 + 0x99) * 2),0,0);
    uVar5 = (ulonglong)uVar1;
    UfsAddDbgLog((longlong)param_1,0x54724e6f,uVar5,uVar3,in_stack_ffffffffffffff98 & uVar3);
    uVar2 = UfsReleaseBuildIndex((longlong)param_1,(uint *)(param_1 + 0x9e),uVar5,'\x01');
    if ((char)uVar2 == '\x01') {
      iVar4 = 10;
      if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
        iVar4 = 10;
        if ((int)param_1[0x342] != 0) {
          iVar4 = (int)param_1[0x342];
        }
      }
      uVar3 = UfsWaitForCompletedRequest(param_1,uVar1,0xffffffff,0,iVar4,0);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        return uVar5;
      }
      goto LAB_14000951c;
    }
    pwVar7 = L"Sending of NOP OUT request failed during doorbell.";
  }
  uVar5 = 0xc1000001;
LAB_14000951c:
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction(0x55,param_1,0,1,6,pwVar7,1,3,0,0,L"index",uVar6,L"status",uVar5);
  }
  return uVar5;
}



===== UfsSendQueryUpiu @ 1400095b4 =====

ulonglong UfsSendQueryUpiu(longlong *param_1,char param_2,byte *param_3,uint param_4,
                          undefined4 *param_5)

{
  byte bVar1;
  undefined1 *puVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint *puVar11;
  int iVar12;
  
  uVar4 = UfsAcquireBuildIndex((longlong)param_1,(uint *)(param_1 + 0x9e));
  uVar6 = (ulonglong)uVar4;
  if ((uVar4 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar4)) {
    return 0xc100000c;
  }
  param_1[uVar6 + 0x172] = 0;
  puVar11 = (uint *)((ulonglong)uVar4 * 0x20 + param_1[0x130]);
  iVar12 = 0;
  UfsInitializeTrdUcd(puVar11,(uint *)(param_1 + (uVar6 + 0x99) * 2),0,0);
  uVar8 = iVar12 + 0x20;
  uVar9 = uVar8;
  if (param_2 == -0x7f) {
    if (*param_3 == 2) {
      uVar9 = uVar8 + (param_4 + 7 & 0xfffffff8);
    }
  }
  else if ((param_2 == '\x01') && (*param_3 == 1)) {
    uVar8 = (param_4 + 7 & 0xfffffff8) + uVar8;
  }
  *(short *)(puVar11 + 6) = (short)(uVar8 >> 2);
  *(ushort *)((longlong)puVar11 + 0x1a) = (ushort)(uVar9 + 7 >> 2) & 0xfffe;
  *(ushort *)((longlong)puVar11 + 0x1e) = (ushort)(uVar8 + 7 + uVar9 >> 2) & 0xfffe;
  uVar3 = (short)param_4 + 7;
  puVar2 = *(undefined1 **)((longlong)(param_1 + (uVar6 + 0x99) * 2) + 8);
  *(ushort *)(puVar2 + 10) = uVar3 >> 8 | (uVar3 & 0xfff8) << 8;
  *puVar2 = 0x16;
  puVar2[5] = param_2;
  puVar2[0xc] = *param_3;
  puVar2[0xd] = param_3[1];
  puVar2[0xe] = param_3[2];
  puVar2[0xf] = param_3[3];
  *(undefined8 *)(puVar2 + 0x10) = *(undefined8 *)(param_3 + 4);
  *(undefined4 *)(puVar2 + 0x18) = *(undefined4 *)(param_3 + 0xc);
  if ((param_4 != 0) && (param_2 == -0x7f)) {
    memmove(puVar2 + 0x20,param_5,(ulonglong)param_4);
  }
  UfsAddDbgLog((longlong)param_1,0x54725175,uVar6,(ulonglong)*param_3,(ulonglong)param_3[1]);
  uVar5 = UfsReleaseBuildIndex((longlong)param_1,(uint *)(param_1 + 0x9e),uVar6,'\x01');
  if ((char)uVar5 == '\x01') {
    uVar6 = UfsWaitForCompletedRequest(param_1,uVar4,0xffffffff,0,(int)param_1[0x1ca],0);
    uVar10 = uVar6 & 0xffffffff;
    if ((int)uVar6 != 0) {
      return uVar10;
    }
    uVar7 = (ulonglong)*(ushort *)((longlong)puVar11 + 0x1a);
    if (puVar2[uVar7 * 4 + 7] == (char)uVar6) {
      if (param_2 != '\x01') {
        return uVar10;
      }
      bVar1 = *param_3;
      if (bVar1 == 1) {
        memmove(param_5,puVar2 + (uVar7 + 8) * 4,
                (ulonglong)
                (ushort)((ushort)(*(short *)(puVar2 + uVar7 * 4 + 10) + 7U) >> 8 |
                        (*(short *)(puVar2 + uVar7 * 4 + 10) + 7U & 0xfff8) << 8));
        return uVar10;
      }
      if (bVar1 == 3) {
        *param_5 = *(undefined4 *)(puVar2 + uVar7 * 4 + 0x14);
        return uVar10;
      }
      if (bVar1 == 5) {
        *(undefined1 *)param_5 = puVar2[uVar7 * 4 + 0x17];
        return uVar10;
      }
      return uVar10;
    }
  }
  return 0xc1000001;
}



===== UfsSendRequestSenseTransferRequest @ 1400097ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsSendRequestSenseTransferRequest(longlong *param_1,byte param_2)

{
  uint *puVar1;
  ushort uVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined1 auStackY_118 [32];
  undefined1 local_a8 [3];
  char local_a5;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  memset(local_a8,0,0x58);
  puVar1 = (uint *)(param_1 + 0x9e);
  uVar4 = UfsAcquireBuildIndex((longlong)param_1,puVar1);
  if ((uVar4 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar4)) {
    uVar8 = 0xc100000c;
  }
  else {
    param_1[(ulonglong)uVar4 + 0x172] =
         -(ulonglong)((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) & (ulonglong)local_a8
    ;
    puVar9 = (uint *)((ulonglong)uVar4 * 0x20 + param_1[0x130]);
    puVar7 = puVar1 + ((ulonglong)uVar4 + 0x4a) * 4;
    UfsInitializeTrdUcd(puVar9,puVar7,2,1);
    puVar3 = *(undefined2 **)(puVar7 + 2);
    uVar2 = *(ushort *)((longlong)puVar9 + 0x1e);
    *(byte *)(puVar3 + 2) = *(byte *)(puVar3 + 2) & 0xf;
    *puVar3 = 0x4001;
    *(byte *)(puVar3 + 1) = param_2;
    *(char *)((longlong)puVar3 + 3) = (char)uVar4;
    *(undefined1 *)(puVar3 + 4) = 0;
    puVar3[5] = 0;
    *(undefined4 *)(puVar3 + 6) = 0x12000000;
    *(undefined1 *)(puVar3 + 8) = 3;
    *(undefined1 *)(puVar3 + 10) = 0x12;
    UfsFillPrdtData((longlong)param_1,(undefined4 *)(puVar3 + (ulonglong)uVar2 * 2),
                    (int)param_1[0x24f],*(undefined4 *)((longlong)param_1 + 0x127c),0x12);
    uVar8 = (ulonglong)uVar4;
    UfsAddDbgLog((longlong)param_1,0x54725253,uVar8,(ulonglong)param_2,0);
    uVar5 = UfsReleaseBuildIndex((longlong)param_1,puVar1,uVar8,'\x01');
    if ((char)uVar5 == '\x01') {
      uVar6 = UfsWaitForCompletedRequest
                        (param_1,uVar4,0xffffffff,(uint)param_2,(int)param_1[0x1ca],0);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 == 0) {
        if (*(char *)((longlong)puVar3 + (ulonglong)*(ushort *)((longlong)puVar9 + 0x1a) * 4 + 7) ==
            '\0') {
          if (((*(uint *)((longlong)param_1 + 0xe24) >> 0x1b & 1) == 0) &&
             ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1a & 1) == 0)) {
            return uVar8;
          }
          if (param_2 != 0) {
            return uVar8;
          }
          if (local_a5 == '\x01') {
            return uVar8;
          }
          uVar8 = 0xc1000001;
        }
        else {
          uVar8 = 0xc1000001;
        }
      }
    }
    else {
      uVar8 = 0xc1000001;
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction(0x55,param_1,0);
  }
  return uVar8;
}



===== UfsSendStartStopUnitTransferRequest @ 140009a78 =====

undefined8 UfsSendStartStopUnitTransferRequest(longlong *param_1,uint param_2)

{
  uint *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  uint *puVar5;
  ulonglong uVar6;
  
  puVar1 = (uint *)(param_1 + 0x9e);
  uVar3 = UfsAcquireBuildIndex((longlong)param_1,puVar1);
  if ((uVar3 != 0xffffffff) && (uVar3 < *(uint *)(param_1 + 0x12d))) {
    param_1[(ulonglong)uVar3 + 0x172] = 0;
    puVar5 = puVar1 + ((ulonglong)uVar3 + 0x4a) * 4;
    UfsInitializeTrdUcd((uint *)((ulonglong)uVar3 * 0x20 + param_1[0x130]),puVar5,0,0);
    puVar2 = *(undefined2 **)(puVar5 + 2);
    uVar6 = (ulonglong)uVar3;
    *(byte *)(puVar2 + 2) = *(byte *)(puVar2 + 2) & 0xf;
    *(byte *)((longlong)puVar2 + 0x11) = *(byte *)((longlong)puVar2 + 0x11) & 0xfe;
    *(byte *)(puVar2 + 10) = *(byte *)(puVar2 + 10) & 0xb | (char)param_2 << 4;
    *puVar2 = 1;
    *(undefined1 *)(puVar2 + 1) = 0xd0;
    *(char *)((longlong)puVar2 + 3) = (char)uVar3;
    *(undefined1 *)(puVar2 + 4) = 0;
    puVar2[5] = 0;
    *(undefined4 *)(puVar2 + 6) = 0;
    *(undefined1 *)(puVar2 + 8) = 0x1b;
    *(undefined1 *)((longlong)puVar2 + 0x15) = 0;
    UfsAddDbgLog((longlong)param_1,0x5472506f,uVar6,(ulonglong)param_2,0);
    uVar4 = UfsReleaseBuildIndex((longlong)param_1,puVar1,uVar6,'\x01');
    if ((char)uVar4 == '\x01') {
      UfsWaitForCompletedRequest(param_1,uVar3,0xffffffff,0xd0,(int)param_1[0x1ca],0);
    }
  }
  return 0;
}



===== UfsSendTaskManRequest @ 140009ba4 =====

undefined8
UfsSendTaskManRequest(longlong param_1,uint param_2,uint param_3,uint param_4,ulonglong param_5)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint *puVar4;
  ulonglong uVar5;
  
  uVar1 = UfsAcquireBuildIndex(param_1,(uint *)(param_1 + 0x10));
  uVar5 = (ulonglong)uVar1;
  if (uVar1 == 0xffffffff) {
    uVar2 = 0xc100000c;
    if (param_5 != 0) {
      *(undefined1 *)(param_5 + 3) = 5;
    }
  }
  else {
    puVar4 = (uint *)(uVar5 * 0x50 + *(longlong *)(param_1 + 0x4a0));
    *(ulonglong *)(param_1 + 0x4b0 + uVar5 * 8) = -(ulonglong)(param_5 != 0) & param_5;
    *puVar4 = *puVar4 | 0x1000000;
    *(undefined1 *)(puVar4 + 2) = 0xf;
    *(undefined2 *)(puVar4 + 4) = 4;
    *(char *)((longlong)puVar4 + 0x12) = (char)param_3;
    *(char *)((longlong)puVar4 + 0x13) = (char)uVar1;
    *(char *)((longlong)puVar4 + 0x15) = (char)param_4;
    *(undefined1 *)(puVar4 + 6) = 0;
    *(undefined2 *)((longlong)puVar4 + 0x1a) = 0;
    puVar4[7] = param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 |
                param_3 << 0x18;
    if ((param_4 == 1) || (param_4 == 0x80)) {
      puVar4[8] = param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 |
                  param_2 << 0x18;
    }
    UfsAddDbgLog(param_1,0x544d5365,param_5,uVar5,(ulonglong)param_4);
    uVar3 = UfsReleaseBuildIndex(param_1,(uint *)(param_1 + 0x10),uVar5,'\x01');
    if ((char)uVar3 == '\x01') {
      uVar2 = UfsWaitForCompletedRequest
                        ((longlong *)param_1,0xffffffff,uVar1,param_3,*(int *)(param_1 + 0xe50),
                         param_5);
    }
    else {
      uVar2 = 0xc1000001;
      if (param_5 != 0) {
        *(char *)(param_5 + 3) = (char)uVar3;
      }
    }
  }
  return uVar2;
}



===== UfsSendUicDmeGet @ 140009ce8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint UfsSendUicDmeGet(longlong *param_1,int param_2,ushort param_3,uint *param_4)

{
  ulonglong uVar1;
  uint uVar2;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined8 local_70;
  wchar_t *local_68;
  ulonglong local_60;
  wchar_t *local_58;
  ulonglong local_50;
  wchar_t *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  ulonglong local_30;
  uint local_28 [2];
  uint local_20 [4];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  *param_4 = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_28[0] = 0;
  uVar2 = 1;
  local_20[0] = param_2 << 0x10 | (uint)param_3;
  uVar1 = UfsExecuteUicCommandSynchronous(param_1,1,local_20,local_28);
  local_30 = uVar1 & 0xffffffff;
  if ((int)uVar1 == 0) {
    *param_4 = local_20[2];
    uVar2 = local_28[0];
  }
  else if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    local_60 = (ulonglong)*param_4;
    local_50 = (ulonglong)local_20[0];
    local_38 = L"status";
    local_40 = 1;
    local_48 = L"errorStatus";
    local_58 = L"args0";
    local_68 = L"Value";
    local_70 = 0;
    local_78 = 0;
    local_80 = 3;
    local_88 = 1;
    local_90 = L"Sending of DME_GET command failed.";
    local_98 = 2;
    StorPortExtendedFunction(0x56,param_1,0,1);
  }
  return uVar2;
}



===== UfsSendUicDmePeerSet @ 140009e38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint UfsSendUicDmePeerSet(longlong *param_1,int param_2,ushort param_3,uint param_4)

{
  uint uVar1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined8 local_70;
  wchar_t *local_68;
  ulonglong local_60;
  wchar_t *local_58;
  ulonglong local_50;
  wchar_t *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  ulonglong local_30;
  uint local_28 [2];
  uint local_20 [4];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  local_20[1] = 0;
  local_28[0] = 0;
  local_20[0] = param_2 << 0x10 | (uint)param_3;
  local_20[2] = param_4;
  local_30 = UfsExecuteUicCommandSynchronous(param_1,4,local_20,local_28);
  if ((int)local_30 == 0) {
    uVar1 = local_28[0];
  }
  else {
    uVar1 = 1;
    if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
      local_50 = (ulonglong)local_20[0];
      local_30 = local_30 & 0xffffffff;
      local_38 = L"status";
      local_40 = 1;
      local_48 = L"errorStatus";
      local_58 = L"args0";
      local_68 = L"Value";
      local_70 = 0;
      local_78 = 0;
      local_80 = 3;
      local_88 = 1;
      local_90 = L"Sending DmePeerSet command failed.";
      local_98 = 2;
      local_60 = (ulonglong)param_4;
      StorPortExtendedFunction(0x56,param_1,0,1);
    }
  }
  return uVar1;
}



===== UfsSendUicDmeSet @ 140009f7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint UfsSendUicDmeSet(longlong *param_1,int param_2,ushort param_3,uint param_4)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  wchar_t *local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_88;
  undefined8 local_80;
  wchar_t *local_78;
  ulonglong local_70;
  wchar_t *local_68;
  ulonglong local_60;
  wchar_t *local_58;
  ulonglong local_50;
  wchar_t *local_48;
  ulonglong local_40;
  uint local_38 [2];
  uint local_30 [4];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_c8;
  local_30[1] = 0;
  local_38[0] = 0;
  local_30[0] = param_2 << 0x10 | (uint)param_3;
  local_30[2] = param_4;
  uVar2 = UfsExecuteUicCommandSynchronous(param_1,2,local_30,local_38);
  uVar3 = local_38[0];
  iVar1 = (int)uVar2;
  local_40 = uVar2 & 0xffffffff;
  if (((iVar1 != 0) || (local_38[0] != 0)) &&
     (StorPortDebugPrint(3," status %x & errorStatus %x\n",uVar2 & 0xffffffff,local_38[0]),
     iVar1 != 0)) {
    uVar3 = 1;
  }
  if (iVar1 == 0) {
    if ((*(uint *)(param_1 + 0x193) >> 0x11 & 1) == 0) {
      return uVar3;
    }
    local_40 = 0;
    local_a0 = L"Sending DME_SET command.";
    uVar4 = 0;
    local_90 = 4;
  }
  else {
    if ((*(uint *)(param_1 + 0x193) >> 0xf & 1) == 0) {
      return uVar3;
    }
    uVar4 = 1;
    local_a0 = L"Sending DME_SET command failed.";
    local_90 = 3;
  }
  local_48 = L"status";
  local_50 = (ulonglong)uVar3;
  local_58 = L"errorStatus";
  local_60 = (ulonglong)local_30[0];
  local_68 = L"args0";
  local_78 = L"Value";
  local_80 = 0;
  local_88 = 0;
  local_98 = 1;
  local_a8 = 2;
  local_70 = (ulonglong)param_4;
  StorPortExtendedFunction(0x56,param_1,0,uVar4);
  return uVar3;
}



===== UfsSendUnmapRequest @ 14000a16c =====

ulonglong UfsSendUnmapRequest(longlong *param_1,byte param_2,undefined8 param_3,uint param_4)

{
  uint *puVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined8 *puVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  wchar_t *pwVar9;
  uint *puVar10;
  ulonglong uVar11;
  uint *puVar12;
  uint *puVar13;
  undefined1 uStackX_19;
  undefined1 uStackX_1a;
  undefined1 uStackX_1b;
  undefined1 uStackX_1c;
  undefined1 uStackX_1d;
  undefined1 uStackX_1e;
  undefined1 uStackX_1f;
  undefined1 uStackX_21;
  undefined1 uStackX_22;
  undefined1 uStackX_23;
  
  puVar1 = (uint *)(param_1 + 0x9e);
  uVar6 = UfsAcquireBuildIndex((longlong)param_1,puVar1);
  uVar11 = 0;
  if ((uVar6 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar6)) {
    uVar11 = 0xc100000c;
    pwVar9 = L"Sending of Unmap request failed with busy.";
  }
  else {
    param_1[(ulonglong)uVar6 + 0x172] = 0;
    puVar12 = (uint *)((ulonglong)uVar6 * 0x20 + param_1[0x130]);
    puVar10 = puVar1 + ((ulonglong)uVar6 + 0x4a) * 4;
    puVar13 = puVar12;
    UfsInitializeTrdUcd(puVar12,puVar10,1,1);
    uVar2 = *(ushort *)((longlong)puVar13 + 0x1e);
    puVar3 = *(undefined2 **)(puVar10 + 2);
    *(byte *)(puVar3 + 2) = *(byte *)(puVar3 + 2) & 0xf;
    *puVar3 = 0x2001;
    *(byte *)(puVar3 + 1) = param_2;
    *(char *)((longlong)puVar3 + 3) = (char)uVar6;
    *(char *)(puVar3 + 4) = (char)uVar11;
    puVar3[5] = (short)uVar11;
    *(undefined4 *)(puVar3 + 6) = 0x18000000;
    puVar4 = (undefined8 *)param_1[599];
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar5 = (undefined2 *)param_1[599];
    *puVar5 = 0x1600;
    *(undefined2 *)(param_1[599] + 2) = 0x1000;
    uStackX_19 = (undefined1)((ulonglong)param_3 >> 8);
    *(undefined1 *)(puVar5 + 7) = uStackX_19;
    uStackX_1a = (undefined1)((ulonglong)param_3 >> 0x10);
    *(undefined1 *)((longlong)puVar5 + 0xd) = uStackX_1a;
    uStackX_1b = (undefined1)((ulonglong)param_3 >> 0x18);
    *(undefined1 *)(puVar5 + 6) = uStackX_1b;
    uStackX_1c = (undefined1)((ulonglong)param_3 >> 0x20);
    *(undefined1 *)((longlong)puVar5 + 0xb) = uStackX_1c;
    uStackX_1d = (undefined1)((ulonglong)param_3 >> 0x28);
    *(undefined1 *)(puVar5 + 5) = uStackX_1d;
    uStackX_1e = (undefined1)((ulonglong)param_3 >> 0x30);
    *(undefined1 *)((longlong)puVar5 + 9) = uStackX_1e;
    uStackX_1f = (undefined1)((ulonglong)param_3 >> 0x38);
    *(undefined1 *)(puVar5 + 4) = uStackX_1f;
    uStackX_21 = (undefined1)(param_4 >> 8);
    *(undefined1 *)(puVar5 + 9) = uStackX_21;
    uStackX_22 = (undefined1)(param_4 >> 0x10);
    *(undefined1 *)((longlong)puVar5 + 0x11) = uStackX_22;
    uStackX_23 = (undefined1)(param_4 >> 0x18);
    *(undefined1 *)(puVar5 + 8) = uStackX_23;
    *(char *)((longlong)puVar5 + 0xf) = (char)param_3;
    *(char *)((longlong)puVar5 + 0x13) = (char)param_4;
    *(undefined1 *)(puVar3 + 8) = 0x42;
    *(undefined2 *)((longlong)puVar3 + 0x17) = 0x1800;
    UfsFillPrdtData((longlong)param_1,(undefined4 *)(puVar3 + (ulonglong)uVar2 * 2),
                    (int)param_1[600],*(undefined4 *)((longlong)param_1 + 0x12c4),0x18);
    uVar8 = (ulonglong)uVar6;
    UfsAddDbgLog((longlong)param_1,0x5472556d,uVar8,(ulonglong)param_4,uVar11);
    uVar7 = UfsReleaseBuildIndex((longlong)param_1,puVar1,uVar8,'\x01');
    if ((char)uVar7 == '\x01') {
      uVar8 = UfsWaitForCompletedRequest
                        (param_1,uVar6,0xffffffff,(uint)param_2,(int)param_1[0x1ca],0);
      uVar11 = uVar8 & 0xffffffff;
      if ((int)uVar8 == 0) {
        if (*(char *)((longlong)puVar3 + (ulonglong)*(ushort *)((longlong)puVar12 + 0x1a) * 4 + 7)
            == '\0') {
          return uVar11;
        }
        uVar11 = 0xc1000001;
        pwVar9 = L"Sending of Unmap request failed with operation unsuccessful.";
      }
      else {
        pwVar9 = L"Sending of Unmap request failed in completion request.";
      }
    }
    else {
      uVar11 = 0xc1000001;
      pwVar9 = L"Sending of Unmap request failed during doorbell.";
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction(0x55,param_1,0,1,7,pwVar9,1,3,0,0,L"index",uVar6,L"status",uVar11);
  }
  return uVar11;
}



===== UfsSendWriteBufferFirmwareUpdateRequest @ 14000a424 =====

ulonglong UfsSendWriteBufferFirmwareUpdateRequest
                    (longlong *param_1,ulonglong param_2,uint param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  undefined2 *puVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  wchar_t *pwVar9;
  uint *puVar10;
  uint *puVar11;
  uint local_res8 [2];
  undefined1 uStackX_21;
  undefined1 uStackX_22;
  
  puVar1 = (uint *)(param_1 + 0x9e);
  local_res8[0] = CONCAT31(local_res8[0]._1_3_,1);
  pwVar9 = L"Sending Firmware update request failed.";
  uVar4 = UfsAcquireBuildIndex((longlong)param_1,puVar1);
  uVar8 = (ulonglong)uVar4;
  if ((uVar4 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar4)) {
    uVar8 = 0xc100000c;
    cVar3 = (char)local_res8[0];
    if (param_2 != 0) {
      *(undefined1 *)(param_2 + 3) = 5;
    }
  }
  else {
    param_1[uVar8 + 0x172] = param_2;
    puVar10 = (uint *)((ulonglong)uVar4 * 0x20 + param_1[0x130]);
    puVar11 = puVar1 + (uVar8 + 0x4a) * 4;
    UfsInitializeTrdUcd(puVar10,puVar11,1,0);
    puVar5 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
    if ((puVar5 != (uint *)0x0) && (local_res8[0] = *puVar5, local_res8[0] != 0)) {
      UfsCreateFirmwareUpdatePrdt
                ((longlong)param_1,
                 *(longlong *)(puVar11 + 2) + (ulonglong)*(ushort *)((longlong)puVar10 + 0x1e) * 4,
                 puVar5,param_3,local_res8);
      *(undefined2 *)(puVar10 + 7) = (undefined2)local_res8[0];
    }
    puVar2 = *(undefined2 **)(puVar11 + 2);
    *(byte *)(puVar2 + 2) = *(byte *)(puVar2 + 2) & 0xf;
    *puVar2 = 0x2001;
    *(undefined1 *)(puVar2 + 1) = 0;
    *(char *)((longlong)puVar2 + 3) = (char)uVar4;
    *(undefined1 *)(puVar2 + 4) = 0;
    puVar2[5] = 0;
    *(uint *)(puVar2 + 6) =
         param_5 >> 0x18 | (param_5 & 0xff0000) >> 8 | (param_5 & 0xff00) << 8 | param_5 << 0x18;
    *(char *)((longlong)puVar2 + 0x15) = (char)param_4;
    *(char *)(puVar2 + 0xc) = (char)param_5;
    *(byte *)((longlong)puVar2 + 0x11) = *(byte *)((longlong)puVar2 + 0x11) & 0xee | 0xe;
    uStackX_22 = (undefined1)(param_4 >> 0x10);
    *(undefined1 *)((longlong)puVar2 + 0x13) = uStackX_22;
    uStackX_21 = (undefined1)(param_4 >> 8);
    *(undefined1 *)(puVar2 + 10) = uStackX_21;
    *(undefined1 *)(puVar2 + 0xb) = param_5._2_1_;
    *(undefined1 *)((longlong)puVar2 + 0x17) = param_5._1_1_;
    *(undefined1 *)(puVar2 + 8) = 0x3b;
    *(undefined1 *)(puVar2 + 9) = 0;
    *(undefined1 *)((longlong)puVar2 + 0x19) = 0;
    UfsAddDbgLog((longlong)param_1,0x54724657,uVar8,param_2,(ulonglong)param_4);
    uVar6 = UfsReleaseBuildIndex((longlong)param_1,puVar1,uVar8,'\x01');
    cVar3 = (char)uVar6;
    local_res8[0] = CONCAT31(local_res8[0]._1_3_,cVar3);
    if (cVar3 == '\x01') {
      uVar7 = UfsWaitForCompletedRequest
                        (param_1,uVar4,0xffffffff,0,(uint)*(byte *)(param_1 + 0x25f) * 1000,param_2)
      ;
      uVar8 = uVar7 & 0xffffffff;
      if ((int)uVar7 == 0) {
        if (*(char *)((longlong)puVar2 + (ulonglong)*(ushort *)((longlong)puVar10 + 0x1a) * 4 + 7)
            == '\0') {
          return uVar8;
        }
        uVar8 = 0xc1000001;
        pwVar9 = L"Sending of firmware update failed with operation unsuccessful.";
      }
      else {
        pwVar9 = L"Sending firmware update Request failed in wait completion request.";
      }
      cVar3 = (char)local_res8[0];
    }
    else {
      uVar8 = 0xc1000001;
      if (param_2 != 0) {
        *(char *)(param_2 + 3) = cVar3;
      }
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x56,param_1,0,1,1,pwVar9,1,3,0,0,L"FwBufferOffset",param_4,L"BufferSize",param_5,
               L"SrbStatus",cVar3,L"status",uVar8);
  }
  return uVar8;
}



===== UfsSendWriteBufferFirmwareUpdateRequest2 @ 14000a730 =====

ulonglong UfsSendWriteBufferFirmwareUpdateRequest2
                    (longlong *param_1,ulonglong param_2,uint param_3,uint param_4,uint param_5,
                    undefined1 *param_6)

{
  uint *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  uint *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint *puVar8;
  wchar_t *pwVar9;
  ulonglong uVar10;
  uint *puVar11;
  uint local_res8 [2];
  undefined1 uStackX_21;
  undefined1 uStackX_22;
  
  pwVar9 = L"Sending Firmware update request failed.";
  uVar10 = 1;
  uVar4 = Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 != 0) {
    *param_6 = 0;
  }
  puVar1 = (uint *)(param_1 + 0x9e);
  uVar3 = UfsAcquireBuildIndex((longlong)param_1,puVar1);
  uVar4 = (ulonglong)uVar3;
  if ((uVar3 == 0xffffffff) || (*(uint *)(param_1 + 0x12d) <= uVar3)) {
    uVar4 = 0xc100000c;
    if (param_2 != 0) {
      *(undefined1 *)(param_2 + 3) = 5;
    }
  }
  else {
    param_1[uVar4 + 0x172] = param_2;
    puVar8 = (uint *)((ulonglong)uVar3 * 0x20 + param_1[0x130]);
    puVar11 = puVar1 + (uVar4 + 0x4a) * 4;
    UfsInitializeTrdUcd(puVar8,puVar11,1,0);
    puVar5 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
    if ((puVar5 != (uint *)0x0) && (local_res8[0] = *puVar5, local_res8[0] != 0)) {
      UfsCreateFirmwareUpdatePrdt
                ((longlong)param_1,
                 *(longlong *)(puVar11 + 2) + (ulonglong)*(ushort *)((longlong)puVar8 + 0x1e) * 4,
                 puVar5,param_3,local_res8);
      *(undefined2 *)(puVar8 + 7) = (undefined2)local_res8[0];
    }
    puVar2 = *(undefined2 **)(puVar11 + 2);
    *(byte *)(puVar2 + 2) = *(byte *)(puVar2 + 2) & 0xf;
    *(undefined1 *)(puVar2 + 1) = 0;
    *(undefined1 *)(puVar2 + 4) = 0;
    puVar2[5] = 0;
    *puVar2 = 0x2001;
    *(char *)((longlong)puVar2 + 3) = (char)uVar3;
    *(uint *)(puVar2 + 6) =
         param_5 >> 0x18 | (param_5 & 0xff0000) >> 8 | (param_5 & 0xff00) << 8 | param_5 << 0x18;
    *(undefined1 *)(puVar2 + 9) = 0;
    *(undefined1 *)((longlong)puVar2 + 0x19) = 0;
    *(byte *)((longlong)puVar2 + 0x11) = *(byte *)((longlong)puVar2 + 0x11) & 0xee | 0xe;
    uStackX_22 = (undefined1)(param_4 >> 0x10);
    *(undefined1 *)((longlong)puVar2 + 0x13) = uStackX_22;
    uStackX_21 = (undefined1)(param_4 >> 8);
    *(undefined1 *)(puVar2 + 10) = uStackX_21;
    *(undefined1 *)(puVar2 + 0xb) = param_5._2_1_;
    *(char *)((longlong)puVar2 + 0x15) = (char)param_4;
    *(char *)(puVar2 + 0xc) = (char)param_5;
    *(undefined1 *)((longlong)puVar2 + 0x17) = param_5._1_1_;
    *(undefined1 *)(puVar2 + 8) = 0x3b;
    UfsAddDbgLog((longlong)param_1,0x54724657,uVar4,param_2,(ulonglong)param_4);
    uVar6 = UfsReleaseBuildIndex((longlong)param_1,puVar1,uVar4,'\x01');
    uVar10 = uVar6 & 0xff;
    if ((char)uVar6 == '\x01') {
      uVar6 = UfsWaitForCompletedRequest
                        (param_1,uVar3,0xffffffff,0,(uint)*(byte *)(param_1 + 0x25f) * 1000,param_2)
      ;
      uVar4 = uVar6 & 0xffffffff;
      uVar7 = Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
      if ((((int)uVar7 != 0) && (param_2 != 0)) && (*(char *)(param_2 + 3) != '\t')) {
        *param_6 = 1;
      }
      if ((int)uVar6 == 0) {
        if (*(char *)((longlong)puVar2 + (ulonglong)*(ushort *)((longlong)puVar8 + 0x1a) * 4 + 7) ==
            '\0') {
          return uVar4;
        }
        pwVar9 = L"Sending of firmware update failed with operation unsuccessful.";
        uVar6 = Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar6 == 0) {
          return uVar4;
        }
      }
      else {
        pwVar9 = L"Sending firmware update Request failed in wait completion request.";
        Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
      }
    }
    else {
      uVar4 = 0xc1000001;
      if (param_2 != 0) {
        *(char *)(param_2 + 3) = (char)uVar6;
      }
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x56,param_1,0,1,1,pwVar9,1,3,0,0,L"FwBufferOffset",param_4,L"BufferSize",param_5,
               L"SrbStatus",uVar10,L"status",uVar4);
  }
  return uVar4;
}



===== UfsFirmwareDownloadCompletionAfterReset @ 14000aa70 =====

void UfsFirmwareDownloadCompletionAfterReset(undefined8 param_1,char param_2,longlong param_3)

{
  if (param_3 != 0) {
    *(uint *)(*(longlong *)(param_3 + 0x18) + 0x14) = ~-(uint)(param_2 != '\0') & 0x20;
    *(undefined1 *)(param_3 + 3) = 1;
    StorPortNotification(0,param_1);
    StorPortResume(param_1);
  }
  return;
}



===== UfsSrbAbortCommand @ 14000aac0 =====

ulonglong UfsSrbAbortCommand(longlong param_1,ushort *param_2)

{
  uint uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  
  uVar4 = 0;
  uVar5 = 0;
  do {
    uVar1 = *(uint *)(param_1 + 0x968);
    if (uVar1 <= uVar5) {
LAB_14000ab45:
      if (uVar5 == uVar1) {
        *(undefined1 *)((longlong)param_2 + 3) = 4;
      }
      return uVar4;
    }
    puVar2 = *(ushort **)(param_1 + 0xb90 + (ulonglong)uVar5 * 8);
    if ((puVar2 != (ushort *)0x0) && (*param_2 == *puVar2)) {
      uVar3 = RtlCompareMemory(*(undefined8 *)(param_2 + 0x14),puVar2,*param_2);
      if (uVar3 == *param_2) {
        uVar4 = UfsSendTaskManRequest
                          (param_1,uVar5,(uint)*(byte *)(*(longlong *)(param_2 + 0x14) + 7),1,
                           (ulonglong)param_2);
        uVar1 = *(uint *)(param_1 + 0x968);
        uVar4 = uVar4 & 0xffffffff;
        goto LAB_14000ab45;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



===== UfsSrbDumpPointers @ 14000ab6c =====

undefined8 UfsSrbDumpPointers(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined2 *local_res8;
  
  local_res8 = (undefined2 *)0x0;
  puVar1 = *(undefined4 **)(param_2 + 0x18);
  if ((((*(uint *)(param_1 + 0xc98) & 0x800) == 0) || (puVar1 == (undefined4 *)0x0)) ||
     (*(uint *)(param_2 + 0x10) < 0x70)) {
    uVar2 = 0xc1000007;
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else {
    uVar2 = StorPortExtendedFunction(0,param_1,0x268,0x20736655,&local_res8);
    if (((int)uVar2 == 0) && (local_res8 != (undefined2 *)0x0)) {
      *puVar1 = 0x700100;
      *(undefined2 **)(puVar1 + 0x10) = local_res8;
      *local_res8 = *(undefined2 *)(param_1 + 0xe08);
      local_res8[1] = *(undefined2 *)(param_1 + 0xe0a);
      *(undefined1 *)(local_res8 + 2) = *(undefined1 *)(param_1 + 0xe0c);
      *(undefined8 *)(local_res8 + 4) = *(undefined8 *)(param_1 + 0xe00);
      *(undefined8 *)(local_res8 + 8) = *(undefined8 *)(param_1 + 0x980);
      *(undefined8 *)(local_res8 + 0xc) = *(undefined8 *)(param_1 + 0x4a0);
      *(undefined8 *)(local_res8 + 0x114) = *(undefined8 *)(param_1 + 0x988);
      *(undefined8 *)(local_res8 + 0x110) = *(undefined8 *)(param_1 + 0x4a8);
      memmove(local_res8 + 0x10,(void *)(param_1 + 0x990),(ulonglong)*(uint *)(param_1 + 0x968) << 4
             );
      *(undefined4 *)(local_res8 + 0x118) = *(undefined4 *)(param_1 + 0xe24);
      uVar2 = *(undefined8 *)(param_1 + 0xe30);
      *(undefined8 *)(local_res8 + 0x11a) = *(undefined8 *)(param_1 + 0xe28);
      *(undefined8 *)(local_res8 + 0x11e) = uVar2;
      uVar2 = *(undefined8 *)(param_1 + 0xe40);
      *(undefined8 *)(local_res8 + 0x122) = *(undefined8 *)(param_1 + 0xe38);
      *(undefined8 *)(local_res8 + 0x126) = uVar2;
      uVar2 = *(undefined8 *)(param_1 + 0xe50);
      *(undefined8 *)(local_res8 + 0x12a) = *(undefined8 *)(param_1 + 0xe48);
      *(undefined8 *)(local_res8 + 0x12e) = uVar2;
      *(undefined1 *)(param_2 + 3) = 1;
      uVar2 = 0;
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
    }
  }
  return uVar2;
}



===== UfsSrbFirmwareDownload @ 14000ad0c =====

ulonglong UfsSrbFirmwareDownload(longlong *param_1,ulonglong param_2,char *param_3)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  int *piVar9;
  int *piVar10;
  uint local_res18 [2];
  undefined4 local_res20 [2];
  uint local_58;
  byte local_50 [24];
  
  uVar1 = *(uint *)(param_1 + 0x193);
  local_res18[0] = 0;
  local_58 = 0;
  *param_3 = '\0';
  cVar3 = '\0';
  if ((uVar1 & 0x1000) != 0) {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar8 = 0xc1000007;
    goto LAB_14000adb7;
  }
  *(uint *)(param_1 + 0x193) = uVar1 | 0x1000;
  if (*(uint *)(param_2 + 0x10) < 0x1c) {
    *(undefined1 *)(param_2 + 3) = 0x15;
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0x18);
    piVar9 = (int *)((ulonglong)*(uint *)(lVar2 + 0x2c) + lVar2);
    if ((*piVar9 != 2) || (piVar10 = piVar9, (uint)piVar9[1] < 0x20)) {
      piVar10 = (int *)0x0;
    }
    uVar1 = *(uint *)(lVar2 + 0x30);
    if (piVar10 == (int *)0x0) {
      if (uVar1 < 0x18) goto LAB_14000ada7;
      lVar7 = *(longlong *)(piVar9 + 4);
      uVar8 = lVar7 + 0x18;
LAB_14000ad9d:
      if ((((uVar1 < uVar8) || (lVar7 == 0)) || ((*(byte *)(piVar9 + 2) & 3) != 0)) ||
         ((*(ulonglong *)(piVar9 + 4) & 3) != 0)) goto LAB_14000ada7;
      if (*(ulonglong *)(piVar9 + 4) < 0x80001) {
        cVar3 = StorPortPause(param_1,600);
        if (cVar3 == '\0') {
          *(undefined4 *)(lVar2 + 0x14) = 0x40;
          uVar8 = 0xc1000001;
          *(undefined1 *)(param_2 + 3) = 4;
          goto LAB_14000adb7;
        }
        uVar8 = UfsWaitForOutstandingOperations((longlong)param_1);
        if ((char)uVar8 == '\0') {
          *(undefined4 *)(lVar2 + 0x14) = 0x40;
          uVar8 = 0xc100000c;
          *(undefined1 *)(param_2 + 3) = 0xb;
          goto LAB_14000adb7;
        }
        uVar8 = Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar8 == 0) {
          uVar8 = UfsSendWriteBufferFirmwareUpdateRequest
                            (param_1,param_2,
                             (-(uint)(piVar10 != (int *)0x0) & 8) + 0x18 + *(int *)(lVar2 + 0x2c),
                             piVar9[2],piVar9[4]);
          iVar4 = (int)uVar8;
        }
        else {
          uVar8 = UfsSendWriteBufferFirmwareUpdateRequest2
                            (param_1,param_2,
                             (-(uint)(piVar10 != (int *)0x0) & 8) + 0x18 + *(int *)(lVar2 + 0x2c),
                             piVar9[2],piVar9[4],param_3);
          iVar4 = (int)uVar8;
        }
        uVar8 = Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar8 == 0) {
          if (*(char *)(param_2 + 3) == '\x01') {
LAB_14000af00:
            if (iVar4 == 0) goto LAB_14000af04;
          }
          else if (iVar4 == 0) {
            *param_3 = '\x01';
          }
        }
        else {
          if (*param_3 != '\0') {
LAB_14000af04:
            if ((*(uint *)(lVar2 + 0x28) & 2) != 0) {
              *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
              local_res20[0] = 0;
              StorPortNotification
                        (0x1002,param_1,param_1 + 0x1a9,UfsFirmwareDownloadCompletionAfterReset,
                         param_2,local_res20);
              if ((char)local_res20[0] == '\0') {
                *(undefined4 *)(lVar2 + 0x14) = 0x20;
                *(undefined1 *)(param_2 + 3) = 1;
              }
            }
            do {
              local_50[8] = 0;
              local_50[9] = 0;
              local_50[10] = 0;
              local_50[0xb] = 0;
              local_50[0xc] = 0;
              local_50[0xd] = 0;
              local_50[0xe] = 0;
              local_50[0xf] = 0;
              local_50[0] = 3;
              local_50[1] = 0x14;
              local_50[2] = 0;
              local_50[3] = 0;
              local_50[4] = 0;
              local_50[5] = 0;
              local_50[6] = 0;
              local_50[7] = 0;
              uVar5 = UfsSendQueryUpiu(param_1,'\x01',local_50,4,local_res18);
              uVar8 = uVar5 & 0xffffffff;
              uVar6 = Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
              if ((((int)uVar6 == 0) || (*param_3 == '\0')) && ((int)uVar5 != 0)) {
                *(undefined1 *)(param_2 + 3) = 4;
                goto LAB_14000adb7;
              }
              local_res18[0] =
                   local_res18[0] >> 0x18 | (local_res18[0] & 0xff0000) >> 8 |
                   (local_res18[0] & 0xff00) << 8 | local_res18[0] << 0x18;
              if (local_res18[0] == 1) break;
              UfsDelay(1000);
              local_58 = local_58 + 1;
            } while (local_58 < *(byte *)(param_1 + 0x25f));
            if (((int)uVar5 == 0) && ((*(uint *)(lVar2 + 0x28) & 2) != 0)) {
              return uVar8;
            }
            goto LAB_14000adb7;
          }
          if (*(char *)(param_2 + 3) == '\x01') goto LAB_14000af00;
        }
        uVar8 = 0xc1000001;
        *(undefined4 *)(lVar2 + 0x14) = 1;
        goto LAB_14000adb7;
      }
      *(undefined4 *)(lVar2 + 0x14) = 4;
    }
    else {
      if (0x1f < uVar1) {
        lVar7 = *(longlong *)(piVar10 + 4);
        uVar8 = lVar7 + 0x20;
        goto LAB_14000ad9d;
      }
LAB_14000ada7:
      *(undefined4 *)(lVar2 + 0x14) = 3;
    }
    *(undefined1 *)(param_2 + 3) = 0x15;
  }
  uVar8 = 0xc1000006;
LAB_14000adb7:
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xffffefff;
  if (cVar3 == '\x01') {
    StorPortResume(param_1);
  }
  return uVar8;
}



===== UfsSrbFirmwareGetInfo @ 14000aff4 =====

undefined8 UfsSrbFirmwareGetInfo(longlong *param_1,longlong param_2)

{
  uint *_Dst;
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (*(uint *)(param_2 + 0x10) < 0x1c) {
    *(undefined1 *)(param_2 + 3) = 0x15;
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
    uVar2 = *(uint *)(lVar3 + 0x30);
    if (0x17 < uVar2) {
      _Dst = (uint *)(lVar3 + (ulonglong)*(uint *)(lVar3 + 0x2c));
      if ((*_Dst < 2) || (_Dst[1] < 0x18)) {
        *(undefined4 *)(lVar3 + 0x14) = 3;
        *(undefined1 *)(param_2 + 3) = 0x22;
        return 0xc1000006;
      }
      if (*(uint *)(lVar3 + 0x2c) + uVar2 <= *(uint *)(param_2 + 0x10)) {
        memset(_Dst,0,(ulonglong)uVar2);
        *_Dst = 2;
        _Dst[1] = 0x18;
        bVar1 = *(byte *)((longlong)param_1 + 0x12f7);
        *(undefined4 *)((longlong)_Dst + 9) = 0x1ff0001;
        *(byte *)(_Dst + 2) = bVar1 & 1;
        _Dst[4] = 0x1000;
        _Dst[5] = 0x80000;
        if (*(uint *)(lVar3 + 0x30) < 0x30) {
          *(undefined4 *)(lVar3 + 0x30) = 0x30;
          *(undefined4 *)(lVar3 + 0x14) = 5;
        }
        else {
          *(undefined2 *)(_Dst + 6) = 0;
          uVar4 = UfsSendInquiryRequest(param_1,*(byte *)(param_2 + 7));
          if ((int)uVar4 == 0) {
            _Dst[8] = *(uint *)(param_1[0x259] + 0x20);
          }
          *(undefined4 *)(lVar3 + 0x14) = 0;
        }
        *(undefined1 *)(param_2 + 3) = 1;
        return 0;
      }
    }
    *(undefined4 *)(lVar3 + 0x14) = 3;
    *(undefined1 *)(param_2 + 3) = 0x15;
  }
  return 0xc1000006;
}



===== UfsSrbFirmwareUpdate @ 14000b11c =====

ulonglong UfsSrbFirmwareUpdate(longlong *param_1,ulonglong param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  char local_res8 [8];
  
  uVar1 = *(uint *)((longlong)param_1 + 0xe24);
  lVar4 = *(longlong *)(param_2 + 0x18);
  uVar2 = *(uint *)(param_2 + 0x10);
  local_res8[0] = '\0';
  *param_3 = 1;
  if ((uVar1 & 0x20) != 0) {
    *(undefined1 *)(param_2 + 3) = 6;
    return 0xc1000002;
  }
  if (0x33 < uVar2) {
    uVar1 = *(uint *)(lVar4 + 0x2c);
    if (((((ulonglong)uVar2 < (ulonglong)*(uint *)(lVar4 + 0x30) + (ulonglong)uVar1) ||
         (*(int *)(lVar4 + 0x1c) == 0)) || ((*(uint *)(lVar4 + 0x28) & 1) == 0)) ||
       ((uVar1 < 0x34 || ((uVar1 & 3) != 0)))) {
      *(undefined4 *)(lVar4 + 0x14) = 3;
    }
    else {
      iVar3 = *(int *)(lVar4 + 0x24);
      if (iVar3 == 1) {
        uVar5 = UfsSrbFirmwareGetInfo(param_1,param_2);
        return uVar5 & 0xffffffff;
      }
      if (iVar3 == 2) {
        uVar5 = UfsSrbFirmwareDownload(param_1,param_2,local_res8);
        uVar6 = Feature_FirmwareUpdateFailure__private_IsEnabledDeviceUsageNoInline();
        if ((((int)uVar6 == 0) && ((int)uVar5 == 0)) || (local_res8[0] != '\0')) {
          *param_3 = 0;
          return uVar5 & 0xffffffff;
        }
        return uVar5 & 0xffffffff;
      }
      if (iVar3 == 3) {
        *(undefined4 *)(lVar4 + 0x14) = 0;
        *(undefined1 *)(param_2 + 3) = 1;
        *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xffffefff;
        return 0;
      }
    }
  }
  *(undefined1 *)(param_2 + 3) = 0x15;
  return 0xc1000006;
}



===== UfsSrbGetDumpInfo @ 14000b20c =====

undefined8 UfsSrbGetDumpInfo(longlong param_1,longlong param_2)

{
  undefined4 *_Dst;
  undefined8 uVar1;
  undefined2 *local_res8;
  
  local_res8 = (undefined2 *)0x0;
  if (((*(longlong *)(param_2 + 0x18) == 0) || (*(uint *)(param_2 + 0x10) < 0x20)) ||
     (*(int *)(*(longlong *)(param_2 + 0x18) + 8) != 0x474d4449)) {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar1 = 0xc1000007;
  }
  else {
    uVar1 = StorPortExtendedFunction(0,param_1,0x268,0x20736655,&local_res8);
    if (((int)uVar1 == 0) && (local_res8 != (undefined2 *)0x0)) {
      memset(local_res8,0,0x268);
      *local_res8 = *(undefined2 *)(param_1 + 0xe08);
      local_res8[1] = *(undefined2 *)(param_1 + 0xe0a);
      *(undefined1 *)(local_res8 + 2) = *(undefined1 *)(param_1 + 0xe0c);
      *(undefined8 *)(local_res8 + 4) = *(undefined8 *)(param_1 + 0xe00);
      *(undefined8 *)(local_res8 + 8) = *(undefined8 *)(param_1 + 0x980);
      *(undefined8 *)(local_res8 + 0xc) = *(undefined8 *)(param_1 + 0x4a0);
      *(undefined8 *)(local_res8 + 0x114) = *(undefined8 *)(param_1 + 0x988);
      *(undefined8 *)(local_res8 + 0x110) = *(undefined8 *)(param_1 + 0x4a8);
      memmove(local_res8 + 0x10,(void *)(param_1 + 0x990),(ulonglong)*(uint *)(param_1 + 0x968) << 4
             );
      *(undefined4 *)(local_res8 + 0x118) = *(undefined4 *)(param_1 + 0xe24);
      uVar1 = *(undefined8 *)(param_1 + 0xe30);
      *(undefined8 *)(local_res8 + 0x11a) = *(undefined8 *)(param_1 + 0xe28);
      *(undefined8 *)(local_res8 + 0x11e) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0xe40);
      *(undefined8 *)(local_res8 + 0x122) = *(undefined8 *)(param_1 + 0xe38);
      *(undefined8 *)(local_res8 + 0x126) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0xe50);
      *(undefined8 *)(local_res8 + 0x12a) = *(undefined8 *)(param_1 + 0xe48);
      *(undefined8 *)(local_res8 + 0x12e) = uVar1;
      _Dst = *(undefined4 **)(param_2 + 0x18);
      memset(_Dst,0,(ulonglong)*(uint *)(param_2 + 0x10));
      _Dst[2] = 0x4d504449;
      *_Dst = 0x18;
      _Dst[1] = 0x18;
      *(undefined2 **)(_Dst + 4) = local_res8;
      uVar1 = 0;
      *(undefined1 *)(param_2 + 3) = 1;
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
    }
  }
  return uVar1;
}



===== UfsSrbIoControl @ 14000b3c8 =====

int UfsSrbIoControl(longlong *param_1,ulonglong param_2,undefined1 *param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  *param_3 = 1;
  iVar3 = *(int *)(lVar1 + 0x10);
  if (iVar3 == 0x1b0780) {
    uVar4 = UfsSrbFirmwareUpdate(param_1,param_2,param_3);
    iVar3 = (int)uVar4;
  }
  else if (iVar3 == 0x2d1400) {
    cVar2 = UfsCompareId(param_1,param_2,(char *)(lVar1 + 4));
    if (cVar2 == '\0') {
      *(undefined1 *)(param_2 + 3) = 6;
LAB_14000b408:
      iVar3 = -0x3efffff9;
      goto LAB_14000b448;
    }
    uVar4 = UfsSrbQueryProtocol(param_1,param_2);
    iVar3 = (int)uVar4;
  }
  else if (iVar3 == 0x2d1680) {
    uVar4 = UfsSrbQueryBootLun(param_1,param_2);
    iVar3 = (int)uVar4;
  }
  else {
    if (iVar3 != 0x2dd684) {
      *(undefined1 *)(param_2 + 3) = 6;
      goto LAB_14000b408;
    }
    uVar4 = UfsSrbSetBootLun(param_1,param_2);
    iVar3 = (int)uVar4;
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_14000b448:
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x55,param_1,0,1,9,L"SRB IO Control commands failed.",1,3,0,0,L"ControlCode",
               *(undefined4 *)(lVar1 + 0x10),L"status",iVar3);
  }
  return iVar3;
}



===== UfsSrbQueryBootLun @ 14000b4e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsSrbQueryBootLun(longlong *param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined4 uVar8;
  byte bVar9;
  undefined1 auStackY_a8 [32];
  uint local_78 [2];
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined1 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar8 = 0;
  local_40 = 0;
  local_38 = 0;
  local_34 = 0;
  uVar1 = *(uint *)(param_2 + 0x10);
  local_78[0] = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (uVar1 < 0x24) {
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar7 = 0xc1000006;
    if (uVar1 < 0x1c) {
      return 0xc1000006;
    }
  }
  else if ((ulonglong)uVar1 < 0x3c) {
    *(undefined4 *)(lVar2 + 0x1c) = 1;
    uVar8 = 8;
    *(undefined4 *)(lVar2 + 0x20) = 0x20;
    uVar7 = 0xc1000004;
    *(undefined1 *)(param_2 + 3) = 0x12;
  }
  else if (((ulonglong)*(uint *)(lVar2 + 0x20) == (ulonglong)uVar1 - 0x1c) &&
          (*(int *)(lVar2 + 0x1c) == 1)) {
    *(undefined4 *)(lVar2 + 0x28) = 0xffffffff;
    uStack_68 = 0;
    *(undefined4 *)(lVar2 + 0x24) = 0;
    _local_70 = 3;
    uVar6 = UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_70,4,local_78);
    uVar7 = uVar6 & 0xffffffff;
    if ((int)uVar6 == 0) {
      bVar9 = 0;
      uVar1 = local_78[0] >> 0x18;
      uVar3 = local_78[0] & 0xff0000;
      uVar4 = local_78[0] & 0xff00;
      uVar5 = local_78[0] << 0x18;
      do {
        uStack_68 = 0;
        local_70 = (uint)CONCAT12(bVar9,0x201);
        _local_70 = CONCAT44(0x2d000000,local_70);
        uVar6 = UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_70,0x2d,(undefined4 *)&local_60);
        uVar7 = uVar6 & 0xffffffff;
        if ((int)uVar6 == 0) {
          if ((byte)(local_60._4_1_ - 1) < 2) {
            if (1 < *(uint *)(lVar2 + 0x24)) break;
            *(undefined4 *)(lVar2 + 0x2c + (ulonglong)*(uint *)(lVar2 + 0x24) * 8) = 8;
            *(undefined1 *)(lVar2 + 0x30 + (ulonglong)*(uint *)(lVar2 + 0x24) * 8) = 0;
            *(undefined1 *)(lVar2 + 0x31 + (ulonglong)*(uint *)(lVar2 + 0x24) * 8) = 0;
            *(undefined1 *)(lVar2 + 0x32 + (ulonglong)*(uint *)(lVar2 + 0x24) * 8) = 0;
            *(byte *)(lVar2 + 0x33 + (ulonglong)*(uint *)(lVar2 + 0x24) * 8) = bVar9;
            if ((uVar1 | uVar3 >> 8 | uVar4 << 8 | uVar5) == (uint)local_60._4_1_) {
              *(undefined4 *)(lVar2 + 0x28) = *(undefined4 *)(lVar2 + 0x24);
            }
            *(int *)(lVar2 + 0x24) = *(int *)(lVar2 + 0x24) + 1;
          }
        }
        else {
          uVar7 = 0;
        }
        bVar9 = bVar9 + 1;
      } while (bVar9 < 8);
      uVar8 = 0x20;
      *(undefined1 *)(param_2 + 3) = 1;
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
    }
  }
  else {
    *(undefined1 *)(param_2 + 3) = 4;
    uVar7 = 0xc1000006;
  }
  *(undefined4 *)(lVar2 + 0x18) = uVar8;
  return uVar7;
}



===== UfsSrbQueryProtocol @ 14000b6bc =====

ulonglong UfsSrbQueryProtocol(longlong *param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (0x4b < *(uint *)(param_2 + 0x10)) {
    lVar2 = *(longlong *)(param_2 + 0x18);
    uVar3 = (ulonglong)*(uint *)(lVar2 + 0x34) + 0x24;
    if (*(uint *)(lVar2 + 0x38) + uVar3 <= (ulonglong)*(uint *)(param_2 + 0x10)) {
      if ((((*(uint *)(lVar2 + 0x34) == 0) || ((uVar3 & 7) == 0)) && (*(int *)(lVar2 + 0x24) == 5))
         && (iVar1 = *(int *)(lVar2 + 0x28), iVar1 - 1U < 5)) {
        if (iVar1 == 1) {
          uVar3 = UfsSrbQueryProtocolQueryDescriptor(param_1,param_2);
          return uVar3;
        }
        if (iVar1 == 2) {
          uVar3 = UfsSrbQueryProtocolQueryAttribute(param_1,param_2);
          return uVar3;
        }
        if (iVar1 == 3) {
          uVar3 = UfsSrbQueryProtocolQueryFlag(param_1,param_2);
          return uVar3;
        }
        if (iVar1 == 4) {
          uVar3 = UfsSrbQueryProtocolQueryDmeAttribute(param_1,param_2);
          return uVar3;
        }
        if (iVar1 == 5) {
          uVar3 = UfsSrbQueryProtocolQueryDmePeerAttribute(param_1,param_2);
          return uVar3;
        }
      }
      *(undefined1 *)(param_2 + 3) = 6;
      return 0xc1000006;
    }
  }
  *(undefined1 *)(param_2 + 3) = 0x15;
  return 0xc1000006;
}



===== UfsSrbQueryProtocolQueryAttribute @ 14000b76c =====

ulonglong UfsSrbQueryProtocolQueryAttribute(longlong *param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  longlong lVar8;
  ushort uVar9;
  byte local_18 [16];
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar7 = 0;
  lVar8 = lVar2 + 0x1c;
  uVar6 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  local_18[8] = 0;
  local_18[9] = 0;
  local_18[10] = 0;
  local_18[0xb] = 0;
  local_18[0xc] = 0;
  local_18[0xd] = 0;
  local_18[0xe] = 0;
  local_18[0xf] = 0;
  cVar1 = *(char *)(lVar2 + 0x2c);
  if (cVar1 != '\t') {
    if (cVar1 != '\x10') goto LAB_14000b7b8;
    uVar6 = 0xf;
  }
  uVar7 = *(undefined1 *)(lVar2 + 0x30);
LAB_14000b7b8:
  uVar9 = 4;
  uVar4 = UfsSrbQueryProtocolVerifyDataLength(param_1,param_2,lVar8,4);
  uVar3 = local_18._0_8_;
  uVar5 = uVar4 & 0xffffffff;
  if ((int)uVar4 == 0) {
    local_18[1] = cVar1;
    local_18[0] = 3;
    local_18[2] = uVar7;
    local_18._4_4_ = SUB84(uVar3,4);
    local_18[3] = uVar6;
    uVar4 = UfsSrbQueryProtocolSendUpiu(param_1,param_2,local_18,lVar8,uVar9);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      return uVar5;
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x56,param_1,0,1,10,L"Query UFS attribute fail.",1,3,0,0,L"idn",cVar1,L"index",uVar7,
               L"selector",uVar6,L"status",uVar5);
  }
  return uVar5;
}



===== UfsSrbQueryProtocolQueryDescriptor @ 14000b8f4 =====

ulonglong UfsSrbQueryProtocolQueryDescriptor(longlong *param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  ushort uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  char cVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 uVar11;
  byte local_18 [6];
  ushort uStack_12;
  undefined8 uStack_10;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  cVar7 = '\0';
  lVar10 = lVar2 + 0x1c;
  uVar11 = 0;
  _local_18 = 0;
  uStack_10 = 0;
  cVar1 = *(char *)(lVar2 + 0x2c);
  plVar6 = param_1;
  if (cVar1 == '\0') {
    uVar9 = 0x5a;
  }
  else if (cVar1 == '\x01') {
    uVar9 = 0x90;
    uVar4 = *(ushort *)(param_1 + 0x25d) >> 8 | *(ushort *)(param_1 + 0x25d) << 8;
    plVar6 = (longlong *)0x310;
    if ((uVar4 == 0x310) || (plVar6 = (longlong *)0x220, uVar4 == 0x220)) {
      uVar9 = 0xe6;
    }
    cVar7 = *(char *)(lVar2 + 0x30);
    uVar11 = *(undefined1 *)(lVar2 + 0x40);
  }
  else if (cVar1 == '\x02') {
    cVar7 = *(char *)(lVar2 + 0x30);
    uVar4 = 0x23;
    if (cVar7 != -0x3c) {
      uVar4 = 0x2d;
    }
    uVar9 = (uint)uVar4;
  }
  else if (cVar1 == '\x04') {
    uVar9 = 6;
  }
  else if (cVar1 == '\x05') {
    cVar7 = *(char *)(lVar2 + 0x30);
    uVar9 = 0xfe;
  }
  else if (cVar1 == '\a') {
    uVar9 = 0x57;
  }
  else if (cVar1 == '\b') {
    uVar9 = 0x62;
  }
  else {
    if (cVar1 != '\t') {
      *(undefined1 *)(param_2 + 3) = 6;
      uVar8 = 0xc1000002;
      goto LAB_14000ba86;
    }
    uVar9 = 0x2d;
  }
  uVar4 = 2;
  if (cVar1 != '\x05') {
    uVar4 = (ushort)uVar9;
  }
  uVar5 = UfsSrbQueryProtocolVerifyDataLength(plVar6,param_2,lVar10,uVar4);
  uVar3 = _local_18;
  uVar4 = (ushort)uVar9;
  uVar8 = uVar5 & 0xffffffff;
  if ((int)uVar5 == 0) {
    if ((cVar1 == '\x05') && (*(uint *)(lVar10 + 0x1c) < (uVar9 & 0xffff))) {
      uVar4 = *(ushort *)(lVar10 + 0x1c);
    }
    stack0xffffffffffffffec = SUB84(uVar3,4);
    local_18._0_4_ = CONCAT13(uVar11,CONCAT12(cVar7,CONCAT11(cVar1,1)));
    _local_18 = CONCAT26(uVar4 >> 8 | uVar4 << 8,local_18);
    uVar5 = UfsSrbQueryProtocolSendUpiu(param_1,param_2,local_18,lVar10,uVar4);
    uVar8 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 0) {
      return uVar8;
    }
  }
LAB_14000ba86:
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x56,param_1,0,1,10,L"Query UFS descriptor failed.",1,3,0,0,L"idn",cVar1,L"index",
               cVar7,L"selector",uVar11,L"status",uVar8);
  }
  return uVar8;
}



===== UfsSrbQueryProtocolQueryDmeAttribute @ 14000bb5c =====

ulonglong UfsSrbQueryProtocolQueryDmeAttribute(longlong *param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int iVar6;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  iVar6 = *(int *)(lVar2 + 0x2c);
  uVar1 = *(undefined4 *)(lVar2 + 0x30);
  uVar3 = *(uint *)(lVar2 + 0x34);
  uVar4 = UfsSrbQueryProtocolVerifyDataLength(param_1,param_2,lVar2 + 0x1c,4);
  uVar5 = uVar4 & 0xffffffff;
  if ((int)uVar4 == 0) {
    uVar3 = UfsSendUicDmeGet(param_1,iVar6,(ushort)uVar1,(uint *)(lVar2 + 0x24 + (ulonglong)uVar3));
    if (uVar3 == 0) {
      *(undefined1 *)(param_2 + 3) = 1;
      *(undefined4 *)(lVar2 + 0x38) = 4;
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
      uVar5 = 0xc1000001;
      *(undefined4 *)(lVar2 + 0x38) = 0;
    }
  }
  return uVar5;
}



===== UfsSrbQueryProtocolQueryDmePeerAttribute @ 14000bbf8 =====

ulonglong UfsSrbQueryProtocolQueryDmePeerAttribute(longlong *param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int iVar6;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  iVar6 = *(int *)(lVar2 + 0x2c);
  uVar1 = *(undefined4 *)(lVar2 + 0x30);
  uVar3 = *(uint *)(lVar2 + 0x34);
  uVar4 = UfsSrbQueryProtocolVerifyDataLength(param_1,param_2,lVar2 + 0x1c,4);
  uVar5 = uVar4 & 0xffffffff;
  if ((int)uVar4 == 0) {
    uVar3 = UfsSendUicDmePeerGet
                      (param_1,iVar6,(ushort)uVar1,(uint *)(lVar2 + 0x24 + (ulonglong)uVar3));
    if (uVar3 == 0) {
      *(undefined1 *)(param_2 + 3) = 1;
      *(undefined4 *)(lVar2 + 0x38) = 4;
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
      uVar5 = 0xc1000001;
      *(undefined4 *)(lVar2 + 0x38) = 0;
    }
  }
  return uVar5;
}



===== UfsSrbQueryProtocolQueryFlag @ 14000bc94 =====

ulonglong UfsSrbQueryProtocolQueryFlag(longlong *param_1,longlong param_2)

{
  undefined1 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte local_18 [2];
  undefined1 auStack_16 [6];
  undefined8 uStack_10;
  
  lVar4 = *(longlong *)(param_2 + 0x18) + 0x1c;
  _local_18 = 0;
  uStack_10 = 0;
  uVar1 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 0x2c);
  uVar2 = UfsSrbQueryProtocolVerifyDataLength(param_1,param_2,lVar4,1);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == 0) {
    _local_18 = CONCAT62(CONCAT42(auStack_16._2_4_,auStack_16._0_2_ & (ushort)uVar2),
                         CONCAT11(uVar1,5));
    uVar2 = UfsSrbQueryProtocolSendUpiu(param_1,param_2,local_18,lVar4,1);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      return uVar3;
    }
  }
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction
              (0x55,param_1,0,1,10,L"Query UFS flag fail.",1,3,0,0,L"idn",uVar1,L"status",uVar3);
  }
  return uVar3;
}



===== UfsSrbQueryProtocolSendUpiu @ 14000bda8 =====

ulonglong UfsSrbQueryProtocolSendUpiu
                    (longlong *param_1,longlong param_2,byte *param_3,longlong param_4,
                    ushort param_5)

{
  ulonglong uVar1;
  
  uVar1 = UfsSendQueryUpiu(param_1,'\x01',param_3,(uint)param_5,
                           (undefined4 *)(param_4 + 8 + (ulonglong)*(uint *)(param_4 + 0x18)));
  if ((int)uVar1 == 0) {
    *(uint *)(param_4 + 0x1c) = (uint)param_5;
    uVar1 = 0;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 4;
    *(undefined4 *)(param_4 + 0x1c) = 0;
  }
  return uVar1;
}



===== UfsSrbQueryProtocolVerifyDataLength @ 14000be0c =====

undefined8
UfsSrbQueryProtocolVerifyDataLength
          (undefined8 param_1,longlong param_2,longlong param_3,ushort param_4)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_3 + 0x1c) < (uint)param_4) {
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar1 = 0xc1000006;
  }
  return uVar1;
}



===== UfsSrbResetDevice @ 14000be2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsSrbResetDevice(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined1 auStack_98 [32];
  uint local_78 [2];
  char local_70 [4];
  undefined4 local_6c;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined4 local_58;
  undefined8 local_54;
  uint local_48 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  lVar1 = *param_1;
  local_78[0] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = 0;
  local_64 = 0;
  local_54 = 0;
  StorPortNotification(0xb);
  *(int *)(param_1 + 0x34a) = (int)param_1[0x34a] + 1;
  UfsClearOutstandingRequests(param_1,0xffffffff);
  uVar2 = UfsExecuteUicCommandSynchronous(param_1,0x15,local_48,local_78);
  uVar3 = uVar2 & 0xffffffff;
  if (((int)uVar2 == 0) && (local_78[0] == 0)) {
    local_48[0] = 1;
    uVar2 = UfsExecuteUicCommandSynchronous(param_1,0x14,local_48,local_78);
    uVar3 = uVar2 & 0xffffffff;
    if (((int)uVar2 == 0) && (local_78[0] == 0)) {
      local_48[0] = 0;
      uVar2 = UfsExecuteUicCommandSynchronous(param_1,0x12,local_48,local_78);
      uVar3 = uVar2 & 0xffffffff;
      if (((int)uVar2 == 0) && (local_78[0] == 0)) {
        uVar4 = 0;
        do {
          uVar3 = UfsExecuteUicCommandSynchronous(param_1,0x16,local_48,local_78);
          uVar3 = uVar3 & 0xffffffff;
          if ((*(uint *)(lVar1 + 0x30) & 1) != 0) goto LAB_14000bf69;
          uVar4 = uVar4 + 1;
        } while (uVar4 < 5);
        if (uVar4 != 5) {
LAB_14000bf69:
          if (*(char *)((longlong)param_1 + 0xe5c) != '\0') {
            UfsToggleAndWaitRefClkGating((longlong)param_1,'\x01');
            local_6c = (undefined4)param_1[0x1cc];
            local_70[0] = *(char *)((longlong)param_1 + 0xe5c);
            local_68 = *(undefined4 *)((longlong)param_1 + 0xe64);
            local_5c = (undefined4)param_1[0x1ce];
            local_58 = *(undefined4 *)((longlong)param_1 + 0xe74);
            uVar4 = UfsPhySetSpeedMode(param_1,local_70);
            if (uVar4 != 0) goto LAB_14000bf3c;
          }
          *(undefined1 *)(param_2 + 3) = 1;
          goto LAB_14000bf45;
        }
LAB_14000bf3c:
        uVar3 = 0xc1000001;
      }
    }
  }
  *(undefined1 *)(param_2 + 3) = 4;
LAB_14000bf45:
  StorPortNotification(10,param_1);
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
    *(undefined1 *)(param_2 + 3) = 4;
    uVar3 = 0xc1000001;
  }
  return uVar3;
}



===== UfsSrbSetBootLun @ 14000bff4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsSrbSetBootLun(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auVar6 [6];
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 auStackY_98 [32];
  undefined1 local_68 [6];
  undefined2 uStack_62;
  longlong lStack_60;
  uint local_58 [2];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined1 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58[0] = 0;
  local_30 = 0;
  local_28 = 0;
  local_24 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (*(uint *)(param_2 + 0x10) < 0x2c) {
    *(undefined1 *)(param_2 + 3) = 0x15;
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x18);
    if (((ulonglong)*(uint *)(lVar1 + 0x20) == (ulonglong)*(uint *)(param_2 + 0x10) - 0x1c) &&
       (*(int *)(lVar1 + 0x1c) == 1)) {
      lStack_60 = 0;
      _local_68 = 3;
      uVar7 = UfsSendQueryUpiu(param_1,'\x01',local_68,4,local_58);
      uVar8 = uVar7 & 0xffffffff;
      if ((int)uVar7 == 0) {
        lStack_60 = 0;
        local_68 = (undefined1  [6])((uint6)*(byte *)(lVar1 + 0x2b) << 0x10);
        auVar6 = local_68;
        _local_68 = CONCAT26(0x2d00,local_68);
        local_68._0_4_ = CONCAT13((char)uVar8,auVar6._0_3_);
        uVar2 = local_58[0] >> 0x18;
        uVar3 = local_58[0] & 0xff0000;
        uVar4 = local_58[0] & 0xff00;
        uVar5 = local_58[0] << 0x18;
        _local_68 = CONCAT62(stack0xffffffffffffff9a,0x201);
        uVar7 = UfsSendQueryUpiu(param_1,'\x01',local_68,0x2d,(undefined4 *)&local_50);
        uVar8 = uVar7 & 0xffffffff;
        if ((int)uVar7 == 0) {
          if ((byte)(local_50._4_1_ - 1) < 2) {
            *(undefined1 *)(param_2 + 3) = 1;
            if ((uVar2 | uVar3 >> 8 | uVar4 << 8 | uVar5) == (uint)local_50._4_1_) {
              return uVar8;
            }
            lStack_60 = (ulonglong)local_50._4_1_ << 0x18;
            _local_68 = 4;
            uVar7 = UfsSendQueryUpiu(param_1,-0x7f,local_68,0,(undefined4 *)0x0);
            uVar8 = uVar7 & 0xffffffff;
            if ((int)uVar7 == 0) {
              return uVar8;
            }
          }
          else {
            uVar8 = 0xc1000002;
          }
        }
      }
      *(undefined1 *)(param_2 + 3) = 4;
      return uVar8;
    }
    *(undefined1 *)(param_2 + 3) = 4;
  }
  return 0xc1000006;
}



===== UfsStartIo @ 14000c160 =====

undefined8 UfsStartIo(longlong *param_1,ushort *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  undefined8 in_RAX;
  undefined4 extraout_var;
  uint uVar7;
  undefined8 uVar8;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  bVar1 = (byte)param_2[1];
  if (bVar1 < 0x21) {
    if (bVar1 == 0x20) {
      *(int *)((longlong)param_1 + 0x1a4c) = *(int *)((longlong)param_1 + 0x1a4c) + 1;
      if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) == 0) {
        UfsSendTaskManRequest
                  ((longlong)param_1,0,(uint)*(byte *)((longlong)param_2 + 7),8,(ulonglong)param_2);
      }
      else {
        *(undefined1 *)((longlong)param_2 + 3) = 4;
      }
    }
    else {
      if (bVar1 == 0) goto LAB_14000c327;
      if (bVar1 == 2) {
        iVar6 = UfsSrbIoControl(param_1,(ulonglong)param_2,local_res8);
        in_RAX = CONCAT71((int7)(CONCAT44(extraout_var,iVar6) >> 8),local_res8[0]);
        goto LAB_14000c30f;
      }
      if (bVar1 == 7) {
        if ((*(byte *)(param_1 + 0x193) & 1) != 0) {
          UfsSendStartStopUnitTransferRequest(param_1,3);
        }
        *(undefined1 *)((longlong)param_2 + 3) = 1;
      }
      else if (bVar1 == 0x10) {
        UfsSrbAbortCommand((longlong)param_1,param_2);
      }
      else {
        if (bVar1 != 0x13) goto LAB_14000c242;
        UfsSrbResetDevice(param_1,(longlong)param_2);
      }
    }
  }
  else if (bVar1 == 0x25) {
    uVar2 = *(uint *)(param_2 + 0x20);
    lVar4 = *(longlong *)(param_2 + 0xc);
    iVar6 = *(int *)(param_2 + 4);
    *(undefined1 *)((longlong)param_2 + 3) = 6;
    if ((uVar2 & 1) == 0) {
      if (iVar6 == 9) {
        uVar3 = *(uint *)(lVar4 + 4);
        uVar7 = uVar3 & 0xfffffd80;
        *(uint *)(lVar4 + 4) = uVar7 | 0x80;
        uVar7 = uVar7 | 0x480;
        if (*(char *)((longlong)param_2 + 7) == '\0') {
          uVar7 = uVar3 & 0xfffff980 | 0x80;
        }
        *(uint *)(lVar4 + 4) = uVar7;
LAB_14000c309:
        *(undefined1 *)((longlong)param_2 + 3) = 1;
      }
    }
    else if (((iVar6 == 2) || (iVar6 == 4)) || (iVar6 == 0x17)) {
      *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 0x20;
      goto LAB_14000c309;
    }
    in_RAX = CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
LAB_14000c30f:
    if ((char)in_RAX == '\0') goto LAB_14000c327;
  }
  else if (bVar1 == 0x26) {
    UfsSrbDumpPointers((longlong)param_1,(longlong)param_2);
  }
  else if (bVar1 == 0x27) {
    if ((*(longlong *)(param_2 + 0xc) == 0) || (*(uint *)(param_2 + 8) < 0x70)) {
LAB_14000c280:
      uVar5 = 6;
    }
    else {
      uVar8 = *(undefined8 *)(*(longlong *)(param_2 + 0xc) + 0x40);
LAB_14000c268:
      StorPortExtendedFunction(1,param_1,uVar8);
      uVar5 = 1;
    }
    *(undefined1 *)((longlong)param_2 + 3) = uVar5;
  }
  else if (bVar1 == 0x2a) {
    UfsSrbGetDumpInfo((longlong)param_1,(longlong)param_2);
  }
  else {
    if (bVar1 == 0x2b) {
      lVar4 = *(longlong *)(param_2 + 0xc);
      if (((lVar4 == 0) || (*(uint *)(param_2 + 8) < 0x18)) || (*(int *)(lVar4 + 8) != 0x464d4449))
      goto LAB_14000c280;
      uVar8 = *(undefined8 *)(lVar4 + 0x10);
      goto LAB_14000c268;
    }
LAB_14000c242:
    *(undefined1 *)((longlong)param_2 + 3) = 6;
  }
  in_RAX = StorPortNotification(0,param_1,param_2);
LAB_14000c327:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== UfsWaitForOutstandingOperations @ 14000c33c =====

ulonglong UfsWaitForOutstandingOperations(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = 5000000;
  while( true ) {
    if (*(int *)(param_1 + 0x4f0) == 0 &&
        (*(int *)(param_1 + 0x4f4) == 0 &&
        (*(int *)(param_1 + 0x4f8) == 0 && *(int *)(param_1 + 0x500) == 0))) {
      return 1;
    }
    uVar1 = StorPortStallExecution(10);
    if (uVar2 < 10) break;
    uVar2 = uVar2 - 10;
  }
  return uVar1 & 0xffffffffffffff00;
}



===== UfsConfigurePaTActivate @ 14000c3a4 =====

uint UfsConfigurePaTActivate(longlong *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  uint local_res10 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  uint local_28 [4];
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  local_28[0] = 0;
  uVar1 = UfsSendUicDmeGet(param_1,0x15aa,0,local_res10);
  if ((uVar1 == 0) &&
     (plVar4 = param_1, uVar1 = UfsSendUicDmePeerGet(param_1,0x15aa,0,local_res18), uVar1 == 0)) {
    uVar1 = UfsConvertPhyGranularity(plVar4,local_res18[0]);
    uVar2 = UfsSendUicDmeGet(param_1,0x15a8,0,local_res20);
    if ((uVar2 == 0) &&
       (plVar4 = param_1, uVar2 = UfsSendUicDmePeerGet(param_1,0x15a8,0,local_28), uVar2 == 0)) {
      iVar3 = UfsConvertPhyGranularity(plVar4,local_res10[0]);
      if ((((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) == 0) || (local_res10[0] != 6)) ||
         (local_res18[0] != 6)) {
        if (local_28[0] * uVar1 < iVar3 * local_res20[0]) {
          uVar1 = UfsSendUicDmePeerSet
                            (param_1,0x15a8,0,((iVar3 * local_res20[0] - 1) + uVar1) / uVar1 + 1);
          return -(uint)(uVar1 != 0) & 0xc1000001;
        }
      }
      else {
        uVar1 = UfsSendUicDmePeerSet
                          (param_1,0x15a8,0,local_res20[0] + *(int *)((longlong)param_1 + 0x1a14));
        if (uVar1 != 0) {
          return 0xc1000001;
        }
      }
      return 0;
    }
  }
  return 0xc1000001;
}



===== UfsConvertPhyGranularity @ 14000c4c4 =====

undefined4 UfsConvertPhyGranularity(undefined8 param_1,int param_2)

{
  if (param_2 != 1) {
    if (param_2 == 2) {
      return 4;
    }
    if (param_2 == 3) {
      return 8;
    }
    if (param_2 == 4) {
      return 0x10;
    }
    if (param_2 == 5) {
      return 0x20;
    }
    if (param_2 == 6) {
      return 100;
    }
  }
  return 1;
}



===== UfsPhyGetCapabilities @ 14000c510 =====

void UfsPhyGetCapabilities(longlong *param_1)

{
  uint uVar1;
  
  UfsSendUicDmeGet(param_1,0x1587,0,(uint *)(param_1 + 0x1cc));
  *(bool *)((longlong)param_1 + 0xe5c) = 0 < (int)*(uint *)(param_1 + 0x1cc);
  UfsSendUicDmeGet(param_1,0x156a,0,(uint *)((longlong)param_1 + 0xe64));
  UfsSendUicDmeGet(param_1,0x1586,0,(uint *)((longlong)param_1 + 0xe6c));
  uVar1 = *(uint *)((longlong)param_1 + 0xe24) & 0xc000000;
  UfsSendUicDmeGet(param_1,(-(uint)(uVar1 != 0) & 0x41) + 0x1540,0,(uint *)(param_1 + 0x1ce));
  UfsSendUicDmeGet(param_1,(-(uint)(uVar1 != 0) & 0x41) + 0x1520,0,
                   (uint *)((longlong)param_1 + 0xe74));
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0x40000000) != 0) {
    UfsQcPostPhyGetCapabilities((longlong)param_1);
  }
  return;
}



===== UfsPhySetSpeedMode @ 14000c5e0 =====

uint UfsPhySetSpeedMode(longlong *param_1,char *param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  int iVar5;
  uint uVar6;
  
  lVar1 = *param_1;
  uVar2 = *(uint *)(param_2 + 0x14);
  *(uint *)((longlong)param_1 + 0xe94) = uVar2;
  uVar3 = *(uint *)((longlong)param_1 + 0xe2c);
  if (uVar3 != 0) {
    if (uVar3 <= uVar2) {
      uVar2 = uVar3;
    }
    *(uint *)((longlong)param_1 + 0xe94) = uVar2;
  }
  UfsSendUicDmeSet(param_1,0x1580,0,uVar2);
  uVar2 = *(uint *)(param_2 + 0x18);
  *(uint *)(param_1 + 0x1d3) = uVar2;
  uVar3 = *(uint *)((longlong)param_1 + 0xe2c);
  if (uVar3 != 0) {
    if (uVar3 <= uVar2) {
      uVar2 = uVar3;
    }
    *(uint *)(param_1 + 0x1d3) = uVar2;
  }
  UfsSendUicDmeSet(param_1,0x1560,0,uVar2);
  plVar4 = param_1;
  uVar2 = UfsQcGetControllerVersion(param_1);
  if (*param_2 == '\0') {
    if (param_2[0xc] == '\0') goto LAB_14000c7a3;
    uVar3 = *(uint *)(param_2 + 0x10);
    *(uint *)(param_1 + 0x1d2) = uVar3;
    UfsSendUicDmeSet(plVar4,0x1583,0,uVar3);
    uVar3 = *(uint *)(param_1 + 0x1d2);
    iVar5 = 0x1568;
  }
  else {
    if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
      UfsSendUicDmeSet(plVar4,0x1585,0,1);
    }
    uVar3 = *(uint *)(param_2 + 4);
    *(uint *)((longlong)param_1 + 0xe84) = uVar3;
    uVar6 = *(uint *)(param_1 + 0x1c5);
    if (uVar6 != 0) {
      if (uVar3 < uVar6) {
        uVar6 = uVar3;
      }
      uVar3 = uVar6;
      *(uint *)((longlong)param_1 + 0xe84) = uVar3;
    }
    UfsSendUicDmeSet(param_1,0x1583,0,uVar3);
    UfsSendUicDmeSet(param_1,0x1568,0,*(uint *)((longlong)param_1 + 0xe84));
    if (0x3fff < uVar2) {
      if (*(int *)((longlong)param_1 + 0xe84) == 4) {
        UfsSendUicDmePeerGet(param_1,0x9f,4,(uint *)((longlong)param_1 + 0xe9c));
        UfsSendUicDmeSet(param_1,0x15d3,0,*(uint *)((longlong)param_1 + 0xe9c));
        uVar3 = 1;
      }
      else {
        uVar3 = 3;
      }
      *(uint *)(param_1 + 0x1d4) = uVar3;
      UfsSendUicDmeSet(param_1,0x15d4,0,uVar3);
    }
    if (((*(uint *)((longlong)param_1 + 0xe24) & 0x8000000) == 0) ||
       (*(int *)((longlong)param_1 + 0xe84) != 4)) goto LAB_14000c7a3;
    *(undefined4 *)(param_1 + 0x1d4) = 1;
    uVar3 = 1;
    iVar5 = 0x15d4;
  }
  UfsSendUicDmeSet(param_1,iVar5,0,uVar3);
LAB_14000c7a3:
  UfsSendUicDmeSet(param_1,0x1584,0,1);
  UfsSendUicDmeSet(param_1,0x1569,0,1);
  *(uint *)(param_1 + 0x1d1) = *(uint *)((longlong)param_1 + 0xe64);
  uVar3 = *(uint *)(param_1 + 0x1c6);
  uVar6 = *(uint *)((longlong)param_1 + 0xe64);
  if (uVar3 != 0) {
    *(uint *)(param_1 + 0x1d1) = uVar3;
    uVar6 = uVar3;
  }
  if (0x3fff < uVar2) {
    uVar6 = *(uint *)((longlong)param_1 + 0xe64);
    *(uint *)(param_1 + 0x1d1) = uVar6;
  }
  UfsSendUicDmeSet(param_1,0x156a,0,uVar6);
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xac000000) != 0) {
    UfsSendUicDmeSet(param_1,0x15b0,0,0x1fff);
    UfsSendUicDmeSet(param_1,0x15b1,0,0xffff);
    UfsSendUicDmeSet(param_1,0x15b2,0,0x7fff);
    UfsSendUicDmeSet(param_1,0x15b3,0,0x1fff);
    UfsSendUicDmeSet(param_1,0x15b4,0,0xffff);
    UfsSendUicDmeSet(param_1,0x15b5,0,0xffff);
  }
  if (*param_2 == '\0') {
    uVar3 = (-(uint)(param_2[0xc] != '\0') & 0x1b) + 7;
  }
  else {
    uVar3 = 0x11;
  }
  *(undefined4 *)(lVar1 + 0x20) = 0xffffffff;
  LOCK();
  UNLOCK();
  uVar3 = UfsSendUicDmeSet(param_1,0x1571,0,uVar3);
  uVar6 = 0;
  do {
    if ((uint)((int)param_1[0x1ca] * 10000) <= uVar6) {
code_r0x00014000c928:
      uVar6 = *(uint *)(lVar1 + 0x30);
      if ((((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) && ((uVar6 & 0x700) != 0)) &&
         ((uVar6 & 0x700) != 0x100)) {
        uVar3 = 1;
      }
      *(undefined1 *)(param_1 + 0x1d0) = 1;
      *(undefined1 *)((longlong)param_1 + 0xe8c) = 0;
      if (((*(uint *)((longlong)param_1 + 0xe24) & 0x40000000) != 0) && (uVar2 < 0x4000)) {
        UfsDelay(5);
        UfsQcConfigureClocks(param_1);
      }
      if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) == 0) {
        UfsConfigurePaTActivate(param_1);
      }
      return uVar3;
    }
    UfsPollForCompletion(param_1,(uint *)0x0,(uint *)0x0);
    if ((*(uint *)(param_1 + 0x193) & 8) != 0) {
      *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffffff7;
      uVar3 = 0;
      goto code_r0x00014000c928;
    }
    StorPortStallExecution(10);
    uVar6 = uVar6 + 1;
  } while( true );
}



===== Feature_UfsRemoveManualFlush__private_IsEnabledDeviceUsageNoInline @ 14000c9b8 =====

ulonglong Feature_UfsRemoveManualFlush__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_UfsRemoveManualFlush__private_featureState;
  if ((Feature_UfsRemoveManualFlush__private_featureState & 0x10) == 0) {
    uVar1 = Feature_UfsRemoveManualFlush__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_UfsRemoveManualFlush__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_UfsRemoveManualFlush__private_IsEnabledFallback @ 14000c9f0 =====

void Feature_UfsRemoveManualFlush__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_UfsRemoveManualFlush__private_descriptor);
  return;
}



===== UfsAdapterGetRefClkGatingWait @ 14000ca0c =====

ulonglong UfsAdapterGetRefClkGatingWait(longlong *param_1,uint *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint local_res8 [8];
  byte local_18 [16];
  
  uVar1 = *(ushort *)(param_1 + 0x25d);
  local_res8[0] = 0;
  *param_2 = 0;
  if ((ushort)(uVar1 >> 8 | uVar1 << 8) < 0x30) {
    uVar3 = 0xc100000b;
  }
  else {
    local_18[8] = 0;
    local_18[9] = 0;
    local_18[10] = 0;
    local_18[0xb] = 0;
    local_18[0xc] = 0;
    local_18[0xd] = 0;
    local_18[0xe] = 0;
    local_18[0xf] = 0;
    local_18[0] = 3;
    local_18[1] = 0x17;
    local_18[2] = 0;
    local_18[3] = 0;
    local_18[4] = 0;
    local_18[5] = 0;
    local_18[6] = 0;
    local_18[7] = 0;
    uVar2 = UfsSendQueryUpiu(param_1,'\x01',local_18,4,local_res8);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      *param_2 = local_res8[0] >> 0x18 | (local_res8[0] & 0xff0000) >> 8 |
                 (local_res8[0] & 0xff00) << 8 | local_res8[0] << 0x18;
    }
    else {
      *param_2 = 0xff;
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== UfsAdapterPowerUp @ 14000ca88 =====

int UfsAdapterPowerUp(longlong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  ulonglong uVar4;
  int iVar5;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  
  local_res8[0] = 0;
  pwVar3 = L"Adapter power up routine failed.";
  LOCK();
  *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) | 2;
  UNLOCK();
  LOCK();
  *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffb;
  UNLOCK();
  iVar5 = 0;
  uVar4 = 0xc1000001;
  if ((int)param_1[0x9e] == 0 &&
      (*(int *)((longlong)param_1 + 0x4f4) == 0 &&
      ((int)param_1[0xa0] == 0 && (int)param_1[0x9f] == 0))) {
    if ((*(byte *)(param_1 + 0x1b4) & 2) == 0) {
      uVar1 = UfsSendUicDmeHibernate(param_1,0x18,local_res8);
      uVar2 = (ulonglong)uVar1;
    }
    else {
      uVar2 = UfsStartAdapter(param_1);
    }
    uVar4 = uVar2 & 0xffffffff;
    if (((int)uVar2 == 0) && (local_res8[0] == 0)) {
      uVar2 = UfsSendStartStopUnitTransferRequest(param_1,1);
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 == 0) {
        *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) | 0x31a85;
        LOCK();
        UNLOCK();
        goto LAB_14000cb58;
      }
      pwVar3 = L"Adapter power device wakeup failed";
    }
    else {
      pwVar3 = L"Adapter power wake/start up failed.";
    }
  }
  else {
    pwVar3 = L"Adapter power wake/start up failed due to pending outstanding command.";
  }
  iVar5 = 1;
LAB_14000cb58:
  LOCK();
  *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffd;
  UNLOCK();
  if (iVar5 != 0) {
    if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
      *(int *)(param_1 + 0x34d) = (int)param_1[0x34d] + 1;
      local_res10[0] = 0;
      StorPortNotification(0x1002,param_1,param_1 + 0x1a9,0,0,local_res10);
    }
    if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
      StorPortExtendedFunction
                (0x56,param_1,0,1,0x10,pwVar3,1,2,0,0,L"errorCode",local_res8[0],L"status",uVar4,
                 L"returnStatus",iVar5,0,0);
    }
  }
  return iVar5;
}



===== UfsInitializePower @ 14000cc78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UfsInitializePower(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 auStack_108 [32];
  char *local_e8;
  undefined4 *local_e0;
  undefined8 local_d8;
  undefined8 *local_d0;
  char local_c8 [4];
  undefined4 local_c4;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  int local_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  uVar4 = 1;
  memset(&local_b8,0,0x80);
  uVar3 = *(uint *)(param_1 + 0xe24);
  local_c8[0] = '\0';
  iVar1 = 0;
  local_c0 = 0;
  local_c4 = 0;
  if (((uVar3 & 5) == 0) &&
     (uVar4 = 1, (uVar3 & 2) != 0 || (*(uint *)(param_1 + 0xc98) & 0x400) == 0)) {
    uVar4 = 2;
  }
  if ((*(byte *)(param_1 + 0xda0) & 1) == 0) {
    local_b8 = 2;
    local_b4 = 0x18;
    local_b0 = 1;
    local_a0 = 2;
    local_9c = 0x28;
    local_90 = 0xdcaf9c10;
    uStack_8c = 0x481f895f;
    uStack_88 = 0xced492a4;
    uStack_84 = 0x3356f5d2;
    if ((uVar3 >> 0x1b & 1) == 0) {
      local_7c = 0;
    }
    else {
      local_7c = uVar4 - 1;
    }
    local_a8 = *(undefined4 *)(param_1 + 0xe34);
    *(undefined4 *)(param_1 + 0xdd4) = *(undefined4 *)(param_1 + 0xe38);
    *(undefined4 *)(param_1 + 0xdd0) = local_a8;
    local_ac = 0x55c;
    if (uVar4 < 2) {
      local_ac = 0x45c;
    }
    local_78 = 1;
    local_74 = 0x20;
    local_70 = 0;
    local_68 = 0;
    local_60 = 0xffffffff;
    if (1 < (byte)uVar4) {
      local_58 = 1;
      local_54 = 0x20;
      local_50 = 0x10;
      local_48 = 0;
      local_40 = 0xffffffff;
    }
    local_98 = uVar4;
    local_94 = local_7c;
    if ((uVar3 & 4) == 0) {
      local_e8 = local_c8;
      iVar1 = StorPortExtendedFunction(0x30,param_1,0,&local_b8);
      *(uint *)(param_1 + 0xda8) = *(uint *)(param_1 + 0xda8) | 1;
      *(byte *)(param_1 + 0xda1) = (byte)uVar4;
      *(byte *)(param_1 + 0xda0) =
           *(byte *)(param_1 + 0xda0) & 0xfd | 1 | -(local_c8[0] != '\0') & 2U;
      *(undefined4 *)(param_1 + 0xda4) = 0;
      *(undefined4 *)(param_1 + 0xdc0) = 0;
      *(uint *)(param_1 + 0xda8) = *(uint *)(param_1 + 0xda8) & 0xfffffffb;
      *(undefined4 *)(param_1 + 0xdc4) = 0x10;
      *(undefined4 *)(param_1 + 0xdcc) = 0x32;
      if (*(int *)(param_1 + 0xe3c) != 0x32) {
        *(int *)(param_1 + 0xdcc) = *(int *)(param_1 + 0xe3c);
      }
      if (1 < *(byte *)(param_1 + 0xda1)) {
        StorPortExtendedFunction(0x20,param_1,param_1 + 0xde8);
        KeInitializeSpinLock(param_1 + 0xdf0);
        local_e8 = (char *)0x0;
        StorPortExtendedFunction(0x33,param_1,0);
        local_e8 = (char *)0x0;
        iVar1 = StorPortExtendedFunction(0x34,param_1,0);
      }
    }
    else {
      *(byte *)(param_1 + 0xda0) = *(byte *)(param_1 + 0xda0) & 0xfc;
      *(uint *)(param_1 + 0xda8) = *(uint *)(param_1 + 0xda8) | 1;
      *(undefined1 *)(param_1 + 0xda1) = 1;
      *(undefined4 *)(param_1 + 0xda4) = 0;
      *(undefined4 *)(param_1 + 0xdc0) = 0;
      *(uint *)(param_1 + 0xda8) = *(uint *)(param_1 + 0xda8) & 0xfffffffb;
      *(undefined4 *)(param_1 + 0xdc4) = 0x10;
      *(undefined4 *)(param_1 + 0xdcc) = 0;
    }
    uVar3 = 999;
    if (*(uint *)(param_1 + 0xe40) < 999) {
      uVar3 = *(uint *)(param_1 + 0xe40);
    }
    *(uint *)(param_1 + 0xdd8) = uVar3;
    uVar2 = Feature_WriteBooster__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar2 != 0) &&
       ((*(uint *)(param_1 + 0xe24) & 0x40000000) != 0 && (*(uint *)(param_1 + 0xc98) & 0x4000) != 0
       )) {
      local_d0 = &local_c0;
      local_e0 = &local_c4;
      local_d8 = 0;
      local_e8 = (char *)0x1000;
      iVar1 = StorPortExtendedFunction(0x77,param_1,0);
      if (iVar1 == 0) {
        *(uint *)(param_1 + 0xdb8) = *(uint *)(param_1 + 0xdb8) | 1;
        *(undefined8 *)(param_1 + 0xdb0) = local_c0;
        *(char *)(param_1 + 0xdbc) = (char)local_c4;
        *(char *)(param_1 + 0xdbe) = (char)local_c4;
        *(undefined1 *)(param_1 + 0xdbd) = 0;
        *(undefined8 *)(param_1 + 0x1288) = 100;
      }
      pcVar5 = "Succeeded";
      if (iVar1 != 0) {
        pcVar5 = "Failed";
      }
      StorPortDebugPrint(3,"StorUFS - POWER: Perf State Registration %s with status %x\n",pcVar5,
                         iVar1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== UfsPerfStateTransition @ 14000d040 =====

ulonglong UfsPerfStateTransition(longlong param_1,ulonglong param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffffa0;
  uint uVar9;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar10;
  
  uVar9 = (uint)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  local_res8 = 0;
  cVar1 = *(char *)(param_1 + 0xdbd);
  if ((*(uint *)(param_1 + 0xdb8) & 1) == 0) {
    uVar5 = (ulonglong)(*(uint *)(param_1 + 0xdb8) & 0xffffff00);
  }
  else {
    uVar5 = *(ulonglong *)(param_1 + 0x1298);
    uVar6 = *(ulonglong *)(param_1 + 0x12a0);
    if (uVar5 < *(ulonglong *)(param_1 + 0x12a0)) {
      uVar6 = uVar5;
    }
    *(undefined8 *)(param_1 + 0x12a0) = 0;
    if (uVar6 == 0) {
      uVar3 = 0;
    }
    else {
      uVar6 = (uVar5 * 100) / uVar6;
      uVar3 = (uint)(10000 / uVar6);
      param_2 = 10000 % uVar6;
    }
    uVar7 = KeQueryInterruptTimePrecise(&local_res8,param_2);
    bVar2 = uVar3 < 0x33;
    *(bool *)(param_1 + 0xdbe) = bVar2;
    uVar8 = uVar7;
    if (*(char *)(param_1 + 0x12a8) != '\0') {
      uVar5 = (ulonglong)bVar2;
      if ((bool)cVar1 != bVar2) {
        StorPortDebugPrint(3,"StorUfs - POWER: Requesting transition to P%u\n",bVar2);
        uVar6 = uVar5;
        iVar4 = StorPortExtendedFunction
                          (0x42,param_1,0,0,0,(ulonglong)uVar9 << 0x20,CONCAT44(uVar10,(uint)bVar2),
                           uVar5);
        uVar10 = (undefined4)(uVar6 >> 0x20);
        if (iVar4 == 0) {
          uVar8 = StorPortDebugPrint(3,"StorUfs - POWER: Successfully transitioned to P%u\n");
        }
        else {
          uVar8 = StorPortDebugPrint(0,
                                     "StorUfs - POWER: Failed transitioning to P%u with status %x\n"
                                     ,(uint)bVar2,iVar4);
          if ((*(uint *)(param_1 + 0xc98) & 0x8000) != 0) {
            uVar8 = StorPortExtendedFunction
                              (0x55,param_1,0,1,0x12,L"Power state transitioning failed.",1,
                               CONCAT44(uVar10,2),0,0,L"pState",uVar5,L"status",iVar4);
          }
        }
      }
    }
    *(undefined1 *)(param_1 + 0x12a8) = 0;
    if (*(longlong *)(param_1 + 0x1290) != 0) {
      *(undefined8 *)(param_1 + 0x1290) = uVar7;
    }
    uVar5 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  return uVar5;
}



===== UfsToggleAndWaitRefClkGating @ 14000d220 =====

void UfsToggleAndWaitRefClkGating(longlong param_1,char param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc9c) != 0) {
    if (param_2 == '\0') {
      iVar1 = *(int *)(param_1 + 0xc9c) + 10;
    }
    else {
      iVar1 = 1;
    }
    StorPortStallExecution(iVar1);
  }
  return;
}



===== UfsInitializeDbgLog @ 14000d254 =====

void UfsInitializeDbgLog(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(byte *)(param_1 + 0xc98) & 1) == 0) {
    plVar1 = (longlong *)(param_1 + 0x1a20);
    uVar3 = 0x2000;
    if (*(uint *)(param_1 + 0xe54) - 1 < 0x1ffff) {
      uVar3 = *(uint *)(param_1 + 0xe54);
    }
    if (*plVar1 != 0) {
      StorPortExtendedFunction(1,param_1);
      *plVar1 = 0;
    }
    iVar2 = StorPortExtendedFunction(0,param_1,uVar3,0x20736655,plVar1);
    if (iVar2 == 0) {
      memset((void *)*plVar1,0,(ulonglong)uVar3);
      *(undefined4 *)(param_1 + 0x1a28) = 0;
      *(undefined8 *)(param_1 + 0x1a38) = 0;
      *(longlong *)(param_1 + 0x1a30) = *plVar1;
      *(uint *)(param_1 + 0x1a2c) = (uVar3 >> 5) - 1;
      *(ulonglong *)(param_1 + 0x1a40) = *plVar1 + -0x20 + ((ulonglong)uVar3 & 0xffffffffffffffe0);
    }
    else if ((*(uint *)(param_1 + 0xc98) & 0x8000) != 0) {
      StorPortExtendedFunction
                (0x55,param_1,0,1,0x17,L"DbgLog initialization memory allocation failed.",1,3,0,0,
                 L"status",iVar2,L"logSize",uVar3);
    }
  }
  return;
}



===== GetStringLength @ 14000d3c4 =====

uint GetStringLength(char *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (*param_1 == '\0') break;
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    } while (uVar1 < param_2);
    if (uVar1 < param_2) {
      return uVar1;
    }
  }
  return param_2;
}



===== UfsAllocateContiguousMemory @ 14000d3e8 =====

undefined4
UfsAllocateContiguousMemory(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = StorPortExtendedFunction(0x18,param_1,param_3,0,0x7fffffffffffffff,0,1,0x80000000,param_4)
  ;
  if (param_4 != (undefined8 *)0x0) {
    memset((void *)*param_4,0,(ulonglong)param_3);
  }
  return uVar1;
}



===== UfsCompareId @ 14000d46c =====

undefined1 UfsCompareId(undefined8 param_1,undefined8 param_2,char *param_3)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_3 == (char *)0x0) {
    uVar2 = 1;
  }
  else {
    while( true ) {
      if ((*param_3 == '\0') && (param_3[1] == '\0')) {
        return 0;
      }
      uVar4 = 8;
      pcVar6 = "PROTOCOL";
      pcVar5 = param_3;
      uVar3 = GetStringLength(param_3,8);
      if ((uVar3 <= uVar4) && (uVar4 = GetStringLength(pcVar5,uVar4), uVar4 == 0)) break;
      uVar3 = 0;
      while( true ) {
        if (uVar4 <= uVar3) {
          return 1;
        }
        cVar1 = (param_3 + -0x140015170)[(longlong)pcVar6];
        if (cVar1 == '*') {
          return 1;
        }
        if (((*pcVar6 == '\0') || (cVar1 == '\0')) || ((*pcVar6 != cVar1 && (cVar1 != '?')))) break;
        pcVar6 = pcVar6 + 1;
        uVar3 = uVar3 + 1;
      }
      uVar3 = GetStringLength(pcVar5,8);
      param_3 = pcVar5 + (uVar3 + 1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== UfsFreeContiguousMemory @ 14000d520 =====

void UfsFreeContiguousMemory
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  if (param_4 != 0) {
    StorPortExtendedFunction(0x19,param_1,param_4,param_3,1);
  }
  return;
}



===== UfsGetInitPowerMode @ 14000d55c =====

undefined1 UfsGetInitPowerMode(longlong *param_1)

{
  byte local_18 [16];
  
  local_18[8] = 0;
  local_18[9] = 0;
  local_18[10] = 0;
  local_18[0xb] = 0;
  local_18[0xc] = 0;
  local_18[0xd] = 0;
  local_18[0xe] = 0;
  local_18[0xf] = 0;
  local_18[0] = 1;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0x5a;
  UfsSendQueryUpiu(param_1,'\x01',local_18,0x5a,(undefined4 *)(param_1 + 0x25b));
  return *(undefined1 *)((longlong)param_1 + 0x12e2);
}



===== UfsGetRegisterAddress @ 14000d5ac =====

void UfsGetRegisterAddress(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  
  lVar5 = param_1[0x1c0];
  iVar6 = *(int *)(param_2 + 8);
  if ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1e & 1) == 0) {
    if ((*(uint *)((longlong)param_1 + 0xe24) >> 0x1c & 1) != 0) {
      puVar1 = *(undefined8 **)(param_2 + 0x38);
      lVar5 = puVar1[2];
      uVar4 = StorPortGetDeviceBase
                        (param_1,iVar6,*(undefined4 *)(param_2 + 4),*puVar1,
                         *(undefined4 *)(puVar1 + 1),*(char *)((longlong)puVar1 + 0xc) == '\0');
      param_1[0x33f] = uVar4;
    }
  }
  else {
    lVar5 = **(longlong **)(param_2 + 0x38);
    if (iVar6 == 0x11) {
      iVar6 = 0xf;
    }
  }
  uVar3 = 0;
  do {
    if (*(uint *)(param_2 + 0x34) <= uVar3) {
LAB_14000d67c:
      if (*(int *)((longlong)param_1 + 0xe24) < 0) {
        uVar4 = StorPortGetDeviceBase
                          (param_1,iVar6,*(undefined4 *)(param_2 + 4),0xd0dc0000,0x2500,0);
        param_1[0x340] = uVar4;
      }
      return;
    }
    lVar2 = *(longlong *)(param_2 + 0x38);
    uVar7 = (ulonglong)uVar3;
    if (*(longlong *)(lVar2 + uVar7 * 0x10) == lVar5) {
      uVar4 = StorPortGetDeviceBase
                        (param_1,iVar6,*(undefined4 *)(param_2 + 4),
                         *(undefined8 *)(lVar2 + uVar7 * 0x10),
                         *(undefined4 *)(lVar2 + 8 + uVar7 * 0x10),
                         *(char *)(lVar2 + 0xc + uVar7 * 0x10) == '\0');
      *param_1 = uVar4;
      goto LAB_14000d67c;
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



===== UfsIntelCryptoInsertKey @ 14000d6d0 =====

undefined8 UfsIntelCryptoInsertKey(longlong *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined4 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  undefined4 *puVar11;
  uint uVar12;
  
  uVar1 = *(uint *)(param_2 + 4);
  uVar7 = (ulonglong)uVar1;
  lVar4 = param_1[0x33b];
  uVar2 = *(uint *)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 0x10);
  lVar10 = *param_1;
  lVar8 = (ulonglong)uVar1 * 0x80;
  puVar11 = (undefined4 *)(lVar8 + lVar4);
  uVar6 = puVar11[0x10];
  if ((int)uVar6 < 0) {
    for (uVar9 = 0; uVar9 < *(uint *)(param_1 + 0x12d); uVar9 = uVar9 + 1) {
      uVar12 = 1 << ((byte)uVar9 & 0x1f);
      if (((((uVar12 & *(uint *)((longlong)param_1 + 0x4f4)) != 0) ||
           ((uVar12 & *(uint *)(param_1 + 0x9f)) != 0)) &&
          (uVar12 = *(uint *)((ulonglong)uVar9 * 0x20 + param_1[0x130]), (uVar12 >> 0x17 & 1) != 0))
         && ((uVar12 & 0xff) == uVar1)) {
        return 0xc100000c;
      }
    }
    uVar6 = uVar6 & 0x7fff0000;
    puVar11[0x10] = uVar6;
    LOCK();
    UNLOCK();
  }
  uVar1 = *(uint *)(lVar10 + 0x104 + (ulonglong)uVar2 * 4);
  uVar9 = uVar1 & 0xff;
  if ((char)uVar1 == '\0') {
    puVar5 = *(undefined4 **)(param_2 + 0x18);
    if (iVar3 == 0x20) {
      lVar8 = 4;
      puVar11 = (undefined4 *)(uVar7 * 0x80 + lVar4);
      do {
        *puVar11 = *puVar5;
        LOCK();
        UNLOCK();
        puVar5 = puVar5 + 1;
        puVar11 = puVar11 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      lVar10 = 4;
      lVar8 = uVar7 << 7;
      do {
        *(undefined4 *)(lVar8 + 0x10 + lVar4) = 0;
        LOCK();
        UNLOCK();
        lVar8 = lVar8 + 4;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      lVar10 = 4;
      lVar8 = uVar7 << 7;
      do {
        *(undefined4 *)(lVar8 + 0x20 + lVar4) = *puVar5;
        LOCK();
        UNLOCK();
        lVar8 = lVar8 + 4;
        puVar5 = puVar5 + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      lVar10 = 4;
      lVar8 = uVar7 << 7;
      do {
        *(undefined4 *)(lVar8 + 0x30 + lVar4) = 0;
        LOCK();
        UNLOCK();
        lVar8 = lVar8 + 4;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
    }
    else if (iVar3 == 0x40) {
      lVar10 = 8;
      do {
        *puVar11 = *puVar5;
        LOCK();
        UNLOCK();
        puVar5 = puVar5 + 1;
        puVar11 = puVar11 + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      lVar10 = 8;
      do {
        *(undefined4 *)(lVar8 + 0x20 + lVar4) = *puVar5;
        LOCK();
        UNLOCK();
        lVar8 = lVar8 + 4;
        puVar5 = puVar5 + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
    }
  }
  else if (((uVar9 == 1) || (uVar9 == 2)) || (uVar9 == 3)) {
    return 0xc1000002;
  }
  *(uint *)(uVar7 * 0x80 + 0x40 + lVar4) =
       (uVar2 & 0xff | 0xff800000) << 8 | *(uint *)(param_2 + 0xc) & 0xff | uVar6 & 0xffff0000;
  LOCK();
  UNLOCK();
  return 0;
}



===== UfsIntelLkfRegistryReadControllerSettings @ 14000d908 =====

void UfsIntelLkfRegistryReadControllerSettings(longlong param_1)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_res10 [3];
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  if ((*(uint *)(param_1 + 0xe24) & 0xc000000) != 0) {
    *(undefined4 *)(param_1 + 0x1a0c) = 1;
    iVar1 = StorPortExtendedFunction
                      (0x3e,param_1,0,"LkfLinkCheckDelayInMS",4,local_res10,local_res8);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1a0c) = 0;
    }
    *(undefined4 *)(param_1 + 0x1a10) = 200;
    iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"LkfNopOutTimeoutInMS",4,local_res10,local_res8)
    ;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1a10) = 0;
    }
    *(undefined4 *)(param_1 + 0x1a14) = 2;
    iVar1 = StorPortExtendedFunction(0x3e,param_1,0,"LkfPaTactivate",4,local_res10,local_res8);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1a14) = 0;
    }
    *(undefined4 *)(param_1 + 0x1a18) = 5;
    iVar1 = StorPortExtendedFunction
                      (0x3e,param_1,0,"LkfResetRetryAttempts",4,local_res10,local_res8);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1a18) = 0;
    }
  }
  return;
}



===== UfsIntelLkfResetBus @ 14000da6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 UfsIntelLkfResetBus(longlong *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined1 auStackY_d8 [32];
  char local_48 [4];
  uint local_44;
  uint local_40 [4];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar1 = *param_1;
  local_40[0] = 0;
  local_40[1] = 0;
  uVar7 = 1;
  local_40[2] = 0;
  local_44 = 0;
  local_48[0] = '\0';
  uVar2 = 0;
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) != 0) {
    if ((*(byte *)(param_1 + 0x193) & 1) == 0) {
      StorPortNotification(0xb,param_1);
      LOCK();
      if ((int)param_1[0x1a8] == 0) {
        *(int *)(param_1 + 0x1a8) = 1;
      }
      UNLOCK();
      UfsAddDbgLog((longlong)param_1,0x52657342,0,0,0);
      *(int *)((longlong)param_1 + 0x1a54) = *(int *)((longlong)param_1 + 0x1a54) + 1;
      UfsClearOutstandingRequests(param_1,0xffffffff);
      UfsDelay(300);
      for (uVar6 = 0; uVar5 = 0, uVar6 <= *(uint *)(param_1 + 0x343); uVar6 = uVar6 + 1) {
        UfsStopAdapter(param_1);
        uVar3 = UfsHostControllerEnable(param_1);
        if ((int)uVar3 != 0) goto LAB_14000dc90;
        do {
          uVar4 = UfsExecuteUicCommandSynchronous(param_1,0x16,local_40,&local_44);
          if ((int)uVar4 == 0) {
            if ((*(uint *)(lVar1 + 0x30) & 1) != 0) break;
          }
          else {
            StorPortDebugPrint(1,"Failed to link startup with storStatus %x.\n",uVar4 & 0xffffffff);
          }
          UfsDelay(10);
          uVar5 = uVar5 + 1;
        } while (uVar5 < 5);
        if (uVar5 == 5) {
          StorPortDebugPrint(1,"Link startup attempt failed with storStatus %x & val %x\n",
                             uVar4 & 0xffffffff,local_44);
        }
        uVar4 = UfsExecuteUicCommandSynchronous(param_1,0x15,local_40,&local_44);
        if (((int)uVar4 != 0) || (local_44 != 0)) goto LAB_14000dc90;
        UfsStopAdapter(param_1);
        UfsDelay(300);
        uVar4 = UfsIntelLkfStartAdapter(param_1,local_48);
        if ((int)uVar4 == 0) break;
        if (local_48[0] != '\x01') goto LAB_14000dc90;
        UfsDelay(0x14);
      }
      if ((uVar6 == (int)param_1[0x343] + 1U) ||
         (((char)param_1[0x193] < '\0' && (uVar3 = UfsCryptoEngineEnable(param_1), (int)uVar3 != 0))
         )) {
LAB_14000dc90:
        uVar7 = 0;
      }
      StorPortNotification(10,param_1);
      LOCK();
      if ((int)param_1[0x1a8] == 1) {
        *(int *)(param_1 + 0x1a8) = 0;
      }
      UNLOCK();
      if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
        StorPortExtendedFunction(0x56,param_1,0,1);
      }
      uVar2 = uVar7;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== UfsIntelLkfStartAdapter @ 14000dd88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsIntelLkfStartAdapter(longlong *param_1,undefined1 *param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined1 local_128 [32];
  char local_98 [4];
  uint local_94;
  byte local_90 [17];
  undefined2 local_7f;
  undefined1 local_7d;
  int local_7c;
  undefined4 local_78;
  undefined8 local_74;
  int local_6c;
  undefined4 local_68;
  undefined8 local_64;
  uint local_58 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_128;
  lVar1 = *param_1;
  uVar7 = 0;
  local_98[0] = '\x01';
  local_94 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_7f = 0;
  local_7d = 0;
  local_74 = 0;
  local_64 = 0;
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0xc000000) == 0) {
    uVar6 = 0xc1000001;
  }
  else {
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = 0;
    }
    uVar4 = UfsHostControllerEnable(param_1);
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      uVar5 = 0;
      do {
        uVar4 = UfsExecuteUicCommandSynchronous(param_1,0x16,local_58,&local_94);
        if (((int)uVar4 == 0) && (local_94 == 0)) {
          if ((*(uint *)(lVar1 + 0x30) & 1) != 0) break;
        }
        else {
          StorPortDebugPrint(1,"Intel LKF platform failed to start link with Status %x val %x.\n",
                             uVar4 & 0xffffffff);
          UfsDelay(10);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 5);
      if (uVar5 == 5) {
        uVar6 = 0xc1000001;
      }
      else {
        UfsInitializeRequestLists(param_1);
        puVar2 = (undefined4 *)*param_1;
        *(undefined4 *)(param_1 + 0x1c2) = *puVar2;
        *(undefined4 *)((longlong)param_1 + 0xe14) = puVar2[2];
        *(undefined4 *)(param_1 + 0x1c3) = puVar2[4];
        *(undefined4 *)((longlong)param_1 + 0xe1c) = puVar2[5];
        *(undefined4 *)(param_1 + 0x1c4) = puVar2[6];
        UfsPhyGetCapabilities(param_1);
        UfsConfigurePaTActivate(param_1);
        *(undefined4 *)(lVar1 + 0x60) = 1;
        LOCK();
        UNLOCK();
        *(undefined4 *)(lVar1 + 0x80) = 1;
        LOCK();
        UNLOCK();
        *(undefined4 *)(lVar1 + 0x20) = 0xffffffff;
        LOCK();
        UNLOCK();
        uVar5 = *(uint *)(param_1 + 0x1b5);
        LOCK();
        *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) | 1;
        UNLOCK();
        do {
          uVar6 = UfsSendNopOutUpiu(param_1);
          if ((int)uVar6 == 0) goto LAB_14000df52;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 5);
        if (uVar7 != 5) {
LAB_14000df52:
          uVar7 = 0;
          if (*(char *)((longlong)param_1 + 0xe5c) != '\0') {
            UfsToggleAndWaitRefClkGating((longlong)param_1,'\x01');
            local_90[0x10] = *(undefined1 *)((longlong)param_1 + 0xe5c);
            local_7c = (int)param_1[0x1cc];
            local_6c = (int)param_1[0x1ce];
            local_78 = *(undefined4 *)((longlong)param_1 + 0xe64);
            local_68 = *(undefined4 *)((longlong)param_1 + 0xe74);
            if (((local_7c == 4) && (local_6c == 2)) &&
               (uVar3 = UfsIntelPhySetSpeedModePWMx2(param_1), uVar3 != 0)) {
              if (param_2 != (undefined1 *)0x0) {
                *param_2 = 1;
              }
              uVar6 = 0xc1000001;
              goto LAB_14000e20f;
            }
            uVar3 = UfsPhySetSpeedMode(param_1,(char *)(local_90 + 0x10));
            if (uVar3 != 0) {
              if (param_2 != (undefined1 *)0x0) {
                *param_2 = 1;
              }
              uVar6 = 0xc1000001;
              goto LAB_14000e20f;
            }
          }
          local_90[8] = 0;
          local_90[9] = 0;
          local_90[10] = 0;
          local_90[0xb] = 0;
          local_90[0xc] = 0;
          local_90[0xd] = 0;
          local_90[0xe] = 0;
          local_90[0xf] = 0;
          local_90[0] = 6;
          local_90[1] = 1;
          local_90[2] = 0;
          local_90[3] = 0;
          local_90[4] = 0;
          local_90[5] = 0;
          local_90[6] = 0;
          local_90[7] = 0;
          do {
            uVar6 = UfsSendQueryUpiu(param_1,-0x7f,local_90,0,(undefined4 *)0x0);
            if ((int)uVar6 == 0) goto LAB_14000e034;
            uVar7 = uVar7 + 1;
          } while (uVar7 < 5);
          if (uVar7 != 5) {
LAB_14000e034:
            UfsDelay(300);
            local_90[8] = 0;
            local_90[9] = 0;
            local_90[10] = 0;
            local_90[0xb] = 0;
            local_90[0xc] = 0;
            local_90[0xd] = 0;
            local_90[0xe] = 0;
            local_90[0xf] = 0;
            local_90[0] = 5;
            local_90[1] = 1;
            local_90[2] = 0;
            local_90[3] = 0;
            local_90[4] = 0;
            local_90[5] = 0;
            local_90[6] = 0;
            local_90[7] = 0;
            uVar7 = 0;
            do {
              uVar4 = UfsSendQueryUpiu(param_1,'\x01',local_90,0,(undefined4 *)local_98);
              if (((int)uVar4 == 0) && (local_98[0] == '\0')) break;
              UfsDelay(3);
              uVar7 = uVar7 + 1;
            } while (uVar7 < 1000);
            if (uVar7 < 1000) {
              UfsGetInitPowerMode(param_1);
              for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {
                uVar4 = UfsSendRequestSenseTransferRequest(param_1,(byte)uVar7);
                if ((uVar7 == 0) && ((int)uVar4 != 0)) {
                  if (param_2 != (undefined1 *)0x0) {
                    *param_2 = 1;
                  }
                  StorPortDebugPrint(1,"Request sense SCSI command failed for LUN0\n");
                  uVar6 = 0xc1000001;
                  goto LAB_14000e20f;
                }
              }
              uVar7 = 0;
              do {
                UfsScsiWaitUntilTestUnitReadyRequest(param_1,(byte)uVar7);
                uVar7 = uVar7 + 1;
              } while (uVar7 < 8);
              UfsSendRequestSenseTransferRequest(param_1,0xc4);
              UfsSendRequestSenseTransferRequest(param_1,0xb0);
              UfsSendRequestSenseTransferRequest(param_1,0xd0);
              UfsScsiWaitUntilTestUnitReadyRequest(param_1,0xc4);
              UfsScsiWaitUntilTestUnitReadyRequest(param_1,0xb0);
              uVar4 = UfsScsiWaitUntilTestUnitReadyRequest(param_1,0xd0);
              uVar6 = uVar4 & 0xffffffff;
              if ((uVar5 & 1) == 0) {
                LOCK();
                *(uint *)(param_1 + 0x1b5) = *(uint *)(param_1 + 0x1b5) & 0xfffffffe;
                UNLOCK();
              }
              *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffffbff;
              if ((*(uint *)(param_1 + 0x1c2) & 0x800000) != 0 &&
                  ((byte)*(undefined4 *)((longlong)param_1 + 0xe24) & 3) == 1) {
                if ((int)param_1[0x1c4] == 0) {
                  *(uint *)(param_1 + 0x1c4) = *(uint *)((longlong)param_1 + 0xe3c) | 0xc00;
                }
                *(int *)(lVar1 + 0x18) = (int)param_1[0x1c4];
                LOCK();
                UNLOCK();
                *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 0x400;
              }
              UfsQueryDeviceDescriptors(param_1);
              *(undefined4 *)(lVar1 + 0x20) = 0xffffffff;
              LOCK();
              UNLOCK();
              if ((*(uint *)(param_1 + 0x1b5) & 2) == 0) {
                *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) | 0x31a85;
                LOCK();
                UNLOCK();
              }
              *(undefined4 *)(lVar1 + 0x4c) = 0;
              LOCK();
              UNLOCK();
              if ((int)uVar4 == 0) {
                return uVar6;
              }
            }
            else {
              StorPortDebugPrint(1,"fDeviceInit not set to zero by device, exhausted attempts \n");
              uVar6 = 0xc1000001;
            }
            goto LAB_14000e20f;
          }
        }
        uVar6 = uVar6 & 0xffffffff;
      }
    }
  }
LAB_14000e20f:
  if ((*(uint *)(param_1 + 0x193) & 0x8000) != 0) {
    StorPortExtendedFunction(0x56,param_1,0);
  }
  return uVar6;
}



===== UfsIntelPhyClearLcc @ 14000e2e0 =====

void UfsIntelPhyClearLcc(longlong *param_1)

{
  UfsSendUicDmeSet(param_1,0x155e,0,0);
  return;
}



===== UfsIntelPhySetHibern8Attr @ 14000e300 =====

void UfsIntelPhySetHibern8Attr(longlong *param_1)

{
  UfsSendUicDmeSet(param_1,0x15a7,0,0x80);
  UfsSendUicDmeSet(param_1,0x15a8,0,0x10);
  return;
}



===== UfsIntelPhySetSpeedModePWMx2 @ 14000e340 =====

uint UfsIntelPhySetSpeedModePWMx2(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  lVar1 = *param_1;
  *(undefined4 *)(param_1 + 0x1d2) = 1;
  UfsSendUicDmeSet(param_1,0x1568,0,1);
  UfsSendUicDmeSet(param_1,0x1583,0,*(uint *)(param_1 + 0x1d2));
  *(undefined4 *)(param_1 + 0x1d3) = 2;
  UfsSendUicDmeSet(param_1,0x1560,0,2);
  *(undefined4 *)((longlong)param_1 + 0xe94) = 2;
  UfsSendUicDmeSet(param_1,0x1580,0,2);
  *(undefined4 *)(param_1 + 0x1d1) = 2;
  UfsSendUicDmeSet(param_1,0x156a,0,2);
  UfsSendUicDmeSet(param_1,0x1569,0,0);
  UfsSendUicDmeSet(param_1,0x1584,0,0);
  UfsSendUicDmeSet(param_1,0x1585,0,0);
  UfsSendUicDmeSet(param_1,0x15b0,0,0x1fff);
  UfsSendUicDmeSet(param_1,0x15b1,0,0xffff);
  UfsSendUicDmeSet(param_1,0x15b2,0,0x7fff);
  UfsSendUicDmeSet(param_1,0x15b3,0,0x1fff);
  UfsSendUicDmeSet(param_1,0x15b4,0,0xffff);
  UfsSendUicDmeSet(param_1,0x15b5,0,0x7fff);
  *(undefined4 *)(lVar1 + 0x20) = 0xffffffff;
  LOCK();
  UNLOCK();
  uVar2 = UfsSendUicDmeSet(param_1,0x1571,0,0x55);
  uVar3 = 0;
  do {
    if ((uint)((int)param_1[0x1ca] * 10000) <= uVar3) {
code_r0x00014000e506:
      uVar3 = *(uint *)(lVar1 + 0x30);
      if (((uVar3 & 0x700) != 0) && ((uVar3 & 0x700) != 0x100)) {
        uVar2 = 1;
      }
      *(undefined1 *)(param_1 + 0x1d0) = 0;
      *(undefined1 *)((longlong)param_1 + 0xe8c) = 1;
      UfsToggleAndWaitRefClkGating((longlong)param_1,'\0');
      return uVar2;
    }
    UfsPollForCompletion(param_1,(uint *)0x0,(uint *)0x0);
    if ((*(uint *)(param_1 + 0x193) & 8) != 0) {
      *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) & 0xfffffff7;
      goto code_r0x00014000e506;
    }
    StorPortStallExecution(10);
    uVar3 = uVar3 + 1;
  } while( true );
}



===== UfsIntelResetMphy @ 14000e55c =====

void UfsIntelResetMphy(longlong *param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *param_1;
  lVar3 = param_1[0x340];
  *(undefined4 *)(lVar2 + 0x34) = 1;
  LOCK();
  UNLOCK();
  puVar1 = (uint *)(lVar3 + 0x20);
  *puVar1 = *puVar1 & 0xfcffffff;
  puVar1 = (uint *)(lVar3 + 0x1054);
  *puVar1 = *puVar1 | 0x7000000;
  *(undefined4 *)(lVar2 + 0x34) = 0;
  LOCK();
  UNLOCK();
  UfsDelay(1);
  return;
}



===== UfsQcConfigureClocks @ 14000e5a8 =====

void UfsQcConfigureClocks(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  lVar2 = *param_1;
  if ((char)param_1[0x1d0] == '\0') {
    iVar1 = (int)param_1[0x1d2];
    if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) || (uVar4 = 2, iVar1 != 4)) {
      uVar4 = 1;
    }
  }
  else {
    iVar1 = *(int *)((longlong)param_1 + 0xe84);
    if (iVar1 == 1) {
      uVar4 = 0x24;
      if ((int)param_1[0x1d1] == 1) {
        uVar4 = 0x1f;
      }
    }
    else {
      if (iVar1 == 2) {
        uVar4 = 0x3e;
        uVar3 = 0x49;
      }
      else {
        if ((iVar1 != 3) && (iVar1 != 5)) {
          uVar4 = 0x1f;
          goto LAB_14000e639;
        }
        uVar4 = 0x7c;
        uVar3 = 0x124;
      }
      if ((int)param_1[0x1d1] != 1) {
        uVar4 = uVar3;
      }
    }
  }
LAB_14000e639:
  *(undefined4 *)(lVar2 + 0xc0) = 200;
  LOCK();
  UNLOCK();
  *(uint *)(lVar2 + 0xc4) = uVar4 | 0x1400;
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar2 + 0xd8) = 20000000;
  LOCK();
  UNLOCK();
  return;
}



===== UfsQcCryptoCompletionRoutine @ 14000e680 =====

undefined8 UfsQcCryptoCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== UfsQcGetControllerVersion @ 14000e6ac =====

uint UfsQcGetControllerVersion(longlong *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0x40000000) != 0) {
    uVar1 = *(uint *)(*param_1 + 0xe4) >> 0x10;
  }
  return uVar1;
}



===== UfsQcGetControllerVersion8380 @ 14000e6d4 =====

uint UfsQcGetControllerVersion8380(longlong *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*(uint *)((longlong)param_1 + 0xe24) & 0x40000000) != 0) {
    uVar1 = *(uint *)(*param_1 + 0xe4) & 0xf0000000;
    StorPortExtendedFunction
              (0x55,param_1,0,1,2,L"Successfully got qcHwVersion value.",1,3,0,0,L"qcHwVersion",
               uVar1,0,0);
  }
  return uVar1;
}



===== UfsQcPostPhyGetCapabilities @ 14000e768 =====

ulonglong UfsQcPostPhyGetCapabilities(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res8 [2];
  int *local_res10;
  undefined4 local_res18;
  undefined4 local_res1c;
  
  local_res18 = 0x42696541;
  local_res10 = (int *)0x0;
  local_res8[0] = 0;
  *(undefined1 *)(param_1 + 0x1a08) = 0;
  local_res1c = 0x4c554d45;
  uVar2 = StorPortExtendedFunction(0,param_1,0x100,0x20736655,&local_res10);
  if ((int)uVar2 == 0) {
    uVar1 = StorPortExtendedFunction
                      (0x1b,param_1,*(undefined8 *)(param_1 + 0xdf8),0x4c554d45,&local_res18,8,
                       local_res10,0x100,local_res8);
    uVar2 = (ulonglong)uVar1;
    if ((((uVar1 == 0) && (*local_res10 == 0x426f6541)) && (local_res10[2] == 1)) &&
       (((short)local_res10[3] == 0 && (local_res10[4] == 1)))) {
      *(undefined1 *)(param_1 + 0x1a08) = 1;
      *(undefined4 *)(param_1 + 0xe60) = 1;
    }
    if (local_res10 != (int *)0x0) {
      StorPortExtendedFunction(1,param_1);
    }
  }
  return uVar2;
}



===== UfsQcPreLinkAdapterConfig @ 14000e86c =====

void UfsQcPreLinkAdapterConfig(longlong *param_1)

{
  longlong *plVar1;
  uint uVar2;
  uint local_res10 [6];
  
  uVar2 = 0;
  local_res10[0] = 0;
  do {
    if (9 < uVar2) break;
    UfsSendUicDmeGet(param_1,0x41,0,local_res10);
    UfsDelay(1);
    uVar2 = uVar2 + 1;
  } while (local_res10[0] != 1);
  plVar1 = param_1;
  uVar2 = UfsQcGetControllerVersion(param_1);
  if (uVar2 < 0x4000) {
    UfsQcConfigureClocks(plVar1);
  }
  UfsSendUicDmeSet(param_1,0x155e,0,0);
  UfsSendUicDmeSet(param_1,0x155f,0,0);
  return;
}



===== UfsSetUpToshibaAdapter @ 14000e8f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UfsSetUpToshibaAdapter(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined1 local_48 [32];
  undefined4 local_28 [6];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  local_28[3] = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x19f8);
  local_28[0] = 5;
  local_28[1] = 4;
  local_28[2] = 3;
  local_28[4] = 1;
  local_28[5] = 2;
  *puVar1 = 0;
  LOCK();
  UNLOCK();
  UfsDelay(5);
  puVar4 = local_28;
  lVar2 = 6;
  do {
    puVar1[0x80] = ~(1 << ((byte)*puVar4 & 0x1f)) & puVar1[0x80];
    LOCK();
    UNLOCK();
    UfsDelay(1);
    puVar4 = puVar4 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  puVar4 = local_28;
  lVar2 = 6;
  do {
    lVar3 = lVar2;
    puVar1[0x80] = 1 << ((byte)*puVar4 & 0x1f) | puVar1[0x80];
    LOCK();
    UNLOCK();
    UfsDelay(1);
    puVar4 = puVar4 + 1;
    lVar2 = lVar3 + -1;
  } while (lVar2 != 0);
  *puVar1 = 1;
  LOCK();
  UNLOCK();
  UfsDelay((int)lVar3 + 4);
  return;
}



===== UfsToshibaPostLinkAdapterConfig @ 14000ea18 =====

void UfsToshibaPostLinkAdapterConfig(longlong *param_1)

{
  UfsSendUicDmeSet(param_1,0x3000,0,0);
  UfsSendUicDmeSet(param_1,0x3001,0,0);
  UfsSendUicDmeSet(param_1,0x4020,0,0);
  UfsSendUicDmeSet(param_1,0x4021,0,1);
  UfsSendUicDmeSet(param_1,0x4022,0,0);
  UfsSendUicDmeSet(param_1,0x4023,0,0);
  UfsSendUicDmeSet(param_1,0x4025,0,6);
  UfsSendUicDmeSet(param_1,0x4020,0,1);
  UfsSendUicDmeSet(param_1,0x4020,1,0);
  UfsSendUicDmeSet(param_1,0x4021,1,1);
  UfsSendUicDmeSet(param_1,0x4022,1,1);
  UfsSendUicDmeSet(param_1,0x4023,1,1);
  UfsSendUicDmeSet(param_1,0x4025,1,6);
  UfsSendUicDmeSet(param_1,0x4020,1,1);
  UfsSendUicDmeSet(param_1,0x4020,2,0);
  UfsSendUicDmeSet(param_1,0x4021,2,1);
  UfsSendUicDmeSet(param_1,0x4022,2,2);
  UfsSendUicDmeSet(param_1,0x4023,2,0);
  UfsSendUicDmeSet(param_1,0x4025,2,6);
  UfsSendUicDmeSet(param_1,0x4020,2,1);
  UfsSendUicDmePeerSet(param_1,0x4020,0,0);
  UfsSendUicDmePeerSet(param_1,0x4021,0,0);
  UfsSendUicDmePeerSet(param_1,0x4022,0,0);
  UfsSendUicDmePeerSet(param_1,0x4023,0,0);
  UfsSendUicDmePeerSet(param_1,0x4025,0,6);
  UfsSendUicDmePeerSet(param_1,0x4020,0,1);
  UfsSendUicDmePeerSet(param_1,0x4020,1,0);
  UfsSendUicDmePeerSet(param_1,0x4021,1,0);
  UfsSendUicDmePeerSet(param_1,0x4022,1,1);
  UfsSendUicDmePeerSet(param_1,0x4023,1,1);
  UfsSendUicDmePeerSet(param_1,0x4025,1,6);
  UfsSendUicDmePeerSet(param_1,0x4020,1,1);
  UfsSendUicDmePeerSet(param_1,0x4020,2,0);
  UfsSendUicDmePeerSet(param_1,0x4021,2,0);
  UfsSendUicDmePeerSet(param_1,0x4022,2,2);
  UfsSendUicDmePeerSet(param_1,0x4023,2,0);
  UfsSendUicDmePeerSet(param_1,0x4025,2,6);
  UfsSendUicDmePeerSet(param_1,0x4020,2,1);
  return;
}



===== UfsHPBAllocateRegionInfo @ 14000ecfc =====

longlong * UfsHPBAllocateRegionInfo(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  code *pcVar5;
  longlong *plVar6;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  plVar6 = (longlong *)(param_1 + 0xf08);
  puVar1 = (undefined8 *)(param_1 + 0xef8);
  uStack_10 = 0;
  local_18 = 0;
  local_14 = 0;
  if ((longlong *)*plVar6 == plVar6) {
    UfsHPBFreeRegionInfo(param_1,(longlong *)*puVar1);
  }
  plVar2 = (longlong *)*plVar6;
  if (((longlong *)plVar2[1] == plVar6) && (lVar3 = *plVar2, *(longlong **)(lVar3 + 8) == plVar2)) {
    *plVar6 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar6;
    RtlInitializeBitMap(&local_18,*(undefined8 *)(param_1 + 0xee8),*(undefined4 *)(param_1 + 0xef0))
    ;
    RtlSetBit(&local_18,param_2);
    puVar4 = *(undefined8 **)(param_1 + 0xf00);
    if ((undefined8 *)*puVar4 == puVar1) {
      *plVar2 = (longlong)puVar1;
      plVar2[1] = (longlong)puVar4;
      *puVar4 = plVar2;
      *(longlong **)(param_1 + 0xf00) = plVar2;
      *(undefined4 *)(plVar2 + 2) = param_2;
      *(int *)(param_1 + 0xef4) = *(int *)(param_1 + 0xef4) + 1;
      return plVar2;
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  plVar6 = (longlong *)(*pcVar5)();
  return plVar6;
}



===== UfsHPBApplyRegionUpdates @ 14000eddc =====

undefined8 UfsHPBApplyRegionUpdates(longlong param_1,longlong param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if ((*(uint *)(param_1 + 0xc98) & 0x2000) == 0) {
    uVar2 = 0xc1000007;
  }
  else {
    if (*(char *)(param_2 + 2) == '\x01') {
      uVar6 = 0;
      if (*(char *)(param_2 + 5) != '\0') {
        do {
          uVar4 = *(ushort *)(param_2 + 0xe + uVar6 * 2);
          uVar4 = uVar4 >> 8 | uVar4 << 8;
          uVar3 = UfsHPBDeactivateRegion(param_1,(uint)uVar4);
          if ((int)uVar3 != 0) {
            StorPortDebugPrint(3,
                               "Inactive region queued for deactivation - region: 0x%x, status: 0x%x\n"
                               ,uVar4,uVar3 & 0xffffffff);
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(byte *)(param_2 + 5));
      }
      uVar4 = *(ushort *)(param_2 + 10);
      uVar1 = *(ushort *)(param_2 + 0xc);
      if (*(char *)(param_2 + 4) != '\0') {
        UfsHPBMappingUpdateEnqueue
                  (param_1,(uint)(ushort)(*(ushort *)(param_2 + 6) >> 8 |
                                         *(ushort *)(param_2 + 6) << 8),
                   (uint)(ushort)(*(ushort *)(param_2 + 8) >> 8 | *(ushort *)(param_2 + 8) << 8));
        if (*(char *)(param_2 + 4) == '\x02') {
          UfsHPBMappingUpdateEnqueue
                    (param_1,(uint)(ushort)(uVar4 >> 8 | uVar4 << 8),
                     (uint)(ushort)(uVar1 >> 8 | uVar1 << 8));
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== UfsHPBCheckForRegionUpdate @ 14000eec8 =====

ulonglong UfsHPBCheckForRegionUpdate(longlong param_1,longlong param_2,char *param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  longlong *plVar5;
  ulonglong uVar6;
  ulonglong in_stack_ffffffffffffffd8;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  if (*(char *)(param_2 + 2) != '\0') {
    return 0xc1000006;
  }
  if (((*(uint *)(param_1 + 0xc98) & 0x2000) == 0) || ((*(uint *)(param_1 + 0xee0) & 1) == 0)) {
    return 0xc1000007;
  }
  if (((ushort)(*(ushort *)(param_2 + 10) >> 8 | *(ushort *)(param_2 + 10) << 8) == 0x14) &&
     (*(char *)(param_2 + 0x24) == '\x01')) {
    if ((*(char *)(param_2 + 0x27) != '\0') && (*param_3 == -0x78)) {
      uVar3 = *(uint *)(param_3 + 2);
      uVar6 = *(ulonglong *)(param_3 + 6);
      uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      in_stack_ffffffffffffffd8 =
           CONCAT44((int)(in_stack_ffffffffffffffd8 >> 0x20),
                    (int)(((ulonglong)uVar3 / (ulonglong)*(uint *)(param_1 + 0xed0)) /
                         (ulonglong)*(uint *)(param_1 + 0xec0)));
      StorPortDebugPrint(3,"HPB read for LBA %x, PPN %x (region %d) contains deactivation request\n"
                         ,uVar3,uVar6 >> 0x38 | (uVar6 & 0xff000000000000) >> 0x28 |
                                (uVar6 & 0xff0000000000) >> 0x18 | (uVar6 & 0xff00000000) >> 8 |
                                (uVar6 & 0xff000000) << 8 | (uVar6 & 0xff0000) << 0x18 |
                                (uVar6 & 0xff00) << 0x28 | uVar6 << 0x38,in_stack_ffffffffffffffd8);
    }
    UfsHPBApplyRegionUpdates(param_1,param_2 + 0x22);
  }
  if (*param_3 == -7) {
    StorPortExtendedFunction(0x32,param_1,0,0,in_stack_ffffffffffffffd8 & 0xffffffff00000000,0);
    if (*param_3 == -7) {
      if (*(char *)(param_2 + 7) == '\0') {
LAB_14000f003:
        uVar2 = *(ushort *)(param_3 + 2) >> 8 | *(ushort *)(param_3 + 2) << 8;
        uVar6 = (ulonglong)(ushort)(*(ushort *)(param_3 + 4) >> 8 | *(ushort *)(param_3 + 4) << 8);
        uVar1 = ExAcquireSpinLockExclusive(param_1 + 0xeac);
        uStack_10 = 0;
        local_18 = 0;
        local_14 = 0;
        plVar5 = UfsHPBGetActiveRegionInfo(param_1,(uint)uVar2);
        if (plVar5 != (longlong *)0x0) {
          RtlInitializeBitMap(&local_18,plVar5[3],*(undefined4 *)((longlong)plVar5 + 0x14));
          RtlSetBit(&local_18,uVar6);
        }
        *(int *)(param_1 + 0xf34) = *(int *)(param_1 + 0xf34) + -1;
        StorPortDebugPrint(3,"Activated region %d, subregion %d - regions active:%d\n",uVar2,uVar6,
                           *(undefined4 *)(param_1 + 0xef4));
        ExReleaseSpinLockExclusive(param_1 + 0xeac,uVar1);
        UfsAddDbgLog(param_1,0x54635242,(ulonglong)uVar2,uVar6,0);
        goto LAB_14000ef91;
      }
      if (*(char *)(param_2 + 7) == '\x02') {
        if (*(char *)(param_2 + 0x2e) == '\x06') {
          iVar4 = 0;
          if (*(byte *)(param_2 + 0x2f) < 2) {
            iVar4 = -0x3efffff9;
          }
        }
        else {
          iVar4 = -0x3efffffa;
          if (*(char *)(param_2 + 0x2e) != '$') {
            iVar4 = -0x3effffff;
          }
        }
        if (iVar4 == 0) goto LAB_14000f003;
      }
    }
    uVar6 = UfsHPBDeactivateRegion(param_1,-1);
  }
  else {
LAB_14000ef91:
    uVar6 = 0;
  }
  return uVar6;
}



===== UfsHPBDeactivateRegion @ 14000f10c =====

ulonglong UfsHPBDeactivateRegion(longlong param_1,int param_2)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
  uVar1 = ExAcquireSpinLockExclusive(param_1 + 0xeac);
  uVar2 = UfsHPBDeactivateRegionInternal(param_1,param_2);
  ExReleaseSpinLockExclusive(param_1 + 0xeac,uVar1);
  return uVar2 & 0xffffffff;
}



===== UfsHPBDeactivateRegionInternal @ 14000f17c =====

undefined8 UfsHPBDeactivateRegionInternal(longlong param_1,int param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = UfsHPBGetActiveRegionInfo(param_1,param_2);
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 0xc1000006;
  }
  else {
    UfsHPBFreeRegionInfo(param_1,plVar1);
    StorPortDebugPrint(3,"Region %d deactivated, %d active regions\n",param_2,
                       *(undefined4 *)(param_1 + 0xef4));
    uVar2 = 0;
  }
  return uVar2;
}



===== UfsHPBFreeRegionInfo @ 14000f1e0 =====

void UfsHPBFreeRegionInfo(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  *(int *)(param_1 + 0xef4) = *(int *)(param_1 + 0xef4) + -1;
  uStack_20 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_24 = 0;
  local_18 = 0;
  local_14 = 0;
  RtlInitializeBitMap(&local_28,*(undefined8 *)(param_1 + 0xee8),*(undefined4 *)(param_1 + 0xef0));
  RtlClearBit(&local_28,(int)param_2[2]);
  RtlInitializeBitMap(&local_18,param_2[3],*(undefined4 *)((longlong)param_2 + 0x14));
  RtlClearAllBits(&local_18);
  *(undefined4 *)(param_2 + 2) = 0xffffffff;
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) == param_2) &&
     (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 == param_2)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    plVar2 = *(longlong **)(param_1 + 0xf10);
    if (*plVar2 == param_1 + 0xf08) {
      *param_2 = param_1 + 0xf08;
      param_2[1] = (longlong)plVar2;
      *plVar2 = (longlong)param_2;
      *(longlong **)(param_1 + 0xf10) = param_2;
      return;
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== UfsHPBGetActiveRegionInfo @ 14000f2bc =====

longlong * UfsHPBGetActiveRegionInfo(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)(param_1 + 0xef8);
  plVar1 = (longlong *)*plVar2;
  if (plVar1 != plVar2) {
    for (; plVar1 != plVar2; plVar1 = (longlong *)*plVar1) {
      if (param_2 == (int)plVar1[2]) {
        return plVar1;
      }
    }
  }
  return (longlong *)0x0;
}



===== UfsHPBGetPpnFromLba @ 14000f2e4 =====

undefined8 UfsHPBGetPpnFromLba(longlong param_1,ulonglong param_2,longlong *param_3)

{
  int iVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_20 = 0;
  local_28 = 0;
  local_24 = 0;
  iVar1 = (int)((param_2 / *(uint *)(param_1 + 0xed0)) / (ulonglong)*(uint *)(param_1 + 0xec0));
  plVar2 = UfsHPBGetActiveRegionInfo(param_1,iVar1);
  if (plVar2 != (longlong *)0x0) {
    RtlInitializeBitMap(&local_28,plVar2[3],*(undefined4 *)((longlong)plVar2 + 0x14));
    uVar3 = (param_2 / *(uint *)(param_1 + 0xed0)) % (ulonglong)*(uint *)(param_1 + 0xec0);
    if ((*(byte *)(CONCAT44(uStack_1c,uStack_20) + ((longlong)uVar3 >> 3)) >> (uVar3 & 7) & 1) != 0)
    {
      uVar4 = param_2 % (ulonglong)*(uint *)(param_1 + 0xecc);
      local_res8 = *(longlong *)(plVar2[4] + uVar4 * 8);
      if (local_res8 == -1) {
        StorPortDebugPrint(3,
                           "Failed to HPB read, range invalidated by write - LBA: 0x%llx - PPN: 0x%llx\n"
                           ,param_2);
      }
      else {
        if (local_res8 != 0) {
          *param_3 = local_res8;
          return 0;
        }
        StorPortDebugPrint(3,
                           "Failed to HPB read, PPN entry == 0 - LBA: 0x%llx - LBA offset: 0x%llx, region:%d, subregion:%d, ppnAddress: (0x%llx)\n"
                           ,param_2,uVar4,iVar1,uVar3,&local_res8);
      }
      return 0xc1000001;
    }
  }
  return 0xc1000007;
}



===== UfsHPBMappingUpdateEnqueue @ 14000f430 =====

ulonglong UfsHPBMappingUpdateEnqueue(longlong param_1,int param_2,undefined4 param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong *plVar7;
  int iVar8;
  longlong lVar9;
  undefined1 *puVar10;
  longlong *local_res20;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  longlong **local_28;
  undefined4 local_20;
  
  local_res20 = (longlong *)0x0;
  local_28 = &local_res20;
  uVar5 = StorPortExtendedFunction(0,param_1,0x18,0x42504855);
  if ((int)uVar5 == 0) {
    lVar1 = param_1 + 0xeac;
    uVar3 = ExAcquireSpinLockExclusive(lVar1);
    iVar8 = param_2;
    plVar6 = UfsHPBGetActiveRegionInfo(param_1,param_2);
    if ((plVar6 == (longlong *)0x0) &&
       (plVar6 = UfsHPBAllocateRegionInfo(param_1,iVar8), plVar6 == (longlong *)0x0)) {
      ExReleaseSpinLockExclusive(lVar1,uVar3);
      return 0xc1000003;
    }
    ExReleaseSpinLockExclusive(lVar1,uVar3);
    local_20 = 0;
    local_28 = (longlong **)((ulonglong)local_28 & 0xffffffff00000000);
    uVar4 = StorPortExtendedFunction(0x31,param_1,0);
    *(int *)(local_res20 + 2) = param_2;
    *(undefined4 *)((longlong)local_res20 + 0x14) = param_3;
    uVar3 = ExAcquireSpinLockExclusive(lVar1);
    puVar10 = auStack_48;
    lVar9 = param_1 + 0xf20;
    plVar6 = *(longlong **)(param_1 + 0xf28);
    plVar7 = local_res20;
    if (*plVar6 != lVar9) {
      plVar7 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      uVar3 = (*pcVar2)();
      puVar10 = auStack_40;
    }
    *plVar7 = lVar9;
    plVar7[1] = (longlong)plVar6;
    *plVar6 = (longlong)plVar7;
    *(longlong **)(lVar9 + 8) = plVar7;
    LOCK();
    *(int *)(param_1 + 0xf30) = *(int *)(param_1 + 0xf30) + 1;
    UNLOCK();
    *(undefined8 *)(puVar10 + -8) = 0x14000f562;
    ExReleaseSpinLockExclusive(lVar1,uVar3);
    *(uint *)(puVar10 + 0x20) = uVar4;
    *(undefined8 *)(puVar10 + -8) = 0x14000f584;
    StorPortDebugPrint(2,"UfsHPBMappingUpdateEnqueue - region: %d, subregion: %d, status %x\n",
                       param_2,param_3);
    uVar5 = (ulonglong)uVar4;
  }
  return uVar5;
}



===== UfsHPBMarkRangeDirty @ 14000f5a8 =====

undefined8 UfsHPBMarkRangeDirty(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  longlong *plVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar5 = 0;
  plVar4 = (longlong *)0x0;
  if (*(char *)(param_2 + 0x48) != '*') {
    return 0xc1000006;
  }
  uVar7 = *(uint *)(param_2 + 0x4a);
  lVar1 = param_1 + 0xeac;
  uVar6 = (uint)(ushort)(*(ushort *)(param_2 + 0x4f) >> 8 | *(ushort *)(param_2 + 0x4f) << 8);
  uVar8 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
  uVar7 = uVar8 % *(uint *)(param_1 + 0xecc);
  uVar9 = (ulonglong)uVar8;
  if ((ulonglong)uVar8 % (ulonglong)*(uint *)(param_1 + 0xed0) != 0) {
    uVar2 = ExAcquireSpinLockShared(lVar1);
    plVar4 = UfsHPBGetActiveRegionInfo(param_1,uVar7);
    if (plVar4 == (longlong *)0x0) {
      ExReleaseSpinLockShared(lVar1,uVar2);
      return 0xc1000001;
    }
    iVar3 = ExTryConvertSharedSpinLockExclusive(lVar1);
    if (iVar3 != 0) goto LAB_14000f692;
    ExReleaseSpinLockShared(lVar1);
  }
  uVar2 = ExAcquireSpinLockExclusive(lVar1);
LAB_14000f692:
  do {
    if (uVar6 == 0) {
LAB_14000f6e1:
      ExReleaseSpinLockExclusive(lVar1,uVar2);
      return uVar5;
    }
    if ((uVar9 % (ulonglong)*(uint *)(param_1 + 0xed0) == 0) &&
       (plVar4 = UfsHPBGetActiveRegionInfo(param_1,uVar7), plVar4 == (longlong *)0x0)) {
      uVar5 = 0xc1000001;
      goto LAB_14000f6e1;
    }
    *(undefined8 *)(plVar4[4] + (uVar9 % (ulonglong)*(uint *)(param_1 + 0xecc)) * 8) =
         0xffffffffffffffff;
    uVar6 = uVar6 - 1;
    uVar9 = uVar9 + 1;
  } while( true );
}



===== UfsHPBReadUpdateSrb @ 14000f71c =====

ulonglong UfsHPBReadUpdateSrb(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong local_res8;
  
  local_res8 = 0xffffffffffffffff;
  if ((*(uint *)(param_1 + 0xc98) & 0x2000) == 0) {
    return 0xc1000007;
  }
  if ((*(int *)(param_2 + 0x10) == *(int *)(param_1 + 0xec8)) && (*(char *)(param_2 + 0x48) == '('))
  {
    lVar1 = param_1 + 0xeac;
    uVar5 = ExAcquireSpinLockShared(lVar1);
    uVar10 = *(uint *)(param_2 + 0x4a);
    uVar10 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
    uVar7 = UfsHPBGetPpnFromLba(param_1,(ulonglong)uVar10,(longlong *)&local_res8);
    uVar9 = uVar7 & 0xffffffff;
    if ((int)uVar7 != 0) {
      ExReleaseSpinLockShared(lVar1,uVar5);
      goto LAB_14000f8f2;
    }
    iVar6 = ExTryConvertSharedSpinLockExclusive(lVar1);
    if (iVar6 == 0) {
      ExReleaseSpinLockShared(lVar1);
      uVar5 = ExAcquireSpinLockExclusive(lVar1);
    }
    plVar8 = UfsHPBGetActiveRegionInfo
                       (param_1,(int)(((ulonglong)uVar10 / (ulonglong)*(uint *)(param_1 + 0xed0)) /
                                     (ulonglong)*(uint *)(param_1 + 0xec0)));
    if (plVar8 == (longlong *)0x0) {
      uVar9 = 0xc1000007;
      ExReleaseSpinLockExclusive(lVar1,uVar5);
      goto LAB_14000f8f2;
    }
    lVar2 = *plVar8;
    if ((*(longlong **)(lVar2 + 8) == plVar8) &&
       (plVar3 = (longlong *)plVar8[1], (longlong *)*plVar3 == plVar8)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      plVar3 = *(longlong **)(param_1 + 0xf00);
      if (*plVar3 == param_1 + 0xef8) {
        *plVar8 = param_1 + 0xef8;
        uVar9 = 0;
        plVar8[1] = (longlong)plVar3;
        *plVar3 = (longlong)plVar8;
        *(longlong **)(param_1 + 0xf00) = plVar8;
        ExReleaseSpinLockExclusive(lVar1,CONCAT71((int7)((ulonglong)plVar3 >> 8),uVar5));
        uVar7 = local_res8;
        *(undefined1 *)(param_2 + 0x48) = 0x88;
        *(undefined2 *)(param_2 + 0x56) = 0x111;
        *(ulonglong *)(param_2 + 0x4e) =
             local_res8 >> 0x38 | (local_res8 & 0xff000000000000) >> 0x28 |
             (local_res8 & 0xff0000000000) >> 0x18 | (local_res8 & 0xff00000000) >> 8 |
             (local_res8 & 0xff000000) << 8 | (local_res8 & 0xff0000) << 0x18 |
             (local_res8 & 0xff00) << 0x28 | local_res8 << 0x38;
        *(undefined1 *)(param_2 + 10) = 0x10;
        StorPortDebugPrint(2,"UfsHPBReadUpdateSrb (0x%llx) - LBA: 0x%llx, PPN: 0x%llx\n",param_2,
                           uVar10,local_res8);
        UfsAddDbgLog(param_1,0x52485042,param_2,(ulonglong)uVar10,uVar7 & 0xffffffff);
        goto LAB_14000f8f2;
      }
    }
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
  }
  uVar9 = 0xc1000006;
LAB_14000f8f2:
  return uVar9;
}



===== UfsReadConfigDescriptor @ 14000f910 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsReadConfigDescriptor(longlong *param_1)

{
  ulonglong uVar1;
  ushort uVar2;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  uVar2 = *(ushort *)(param_1 + 0x25d) >> 8 | *(ushort *)(param_1 + 0x25d) << 8;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = Feature_WriteBoosterSupportUFS2_2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    if (uVar2 < 0x310) {
      return 0xc100000b;
    }
  }
  else if (uVar2 < (ushort)((-(ushort)(*(int *)((longlong)param_1 + 0xe4c) != 0) & 0xff10) + 0x310))
  {
    return 0xc100000b;
  }
  local_28 = CONCAT44(local_28._4_4_,0x101);
  local_28 = CONCAT26(0xe600,(undefined6)local_28);
  uVar1 = UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_28,0xe6,
                           (undefined4 *)((longlong)param_1 + 0x18d9));
  return uVar1;
}



===== UfsWriteBoosterInitialize @ 14000f9d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UfsWriteBoosterInitialize(longlong *param_1)

{
  undefined8 uVar1;
  ulonglong uVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined1 auStackY_d8 [32];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined2 uStack_62;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined1 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_38 = 0;
  local_30 = 0;
  local_2c = 0;
  _local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if ((*(byte *)((longlong)param_1 + 0x1329) & 1) == 0) {
    uVar4 = 0xc1000007;
    goto LAB_14000fa4f;
  }
  uVar2 = UfsReadConfigDescriptor(param_1);
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 != 0) goto LAB_14000fa4f;
  if ((*(int *)((longlong)param_1 + 0x18eb) != 0) ||
     (*(char *)((longlong)param_1 + 0x18ea) != '\x01')) {
    if (*(char *)((longlong)param_1 + 0x18ea) != '\0') {
LAB_14000fb87:
      uStack_60 = 0;
      _local_68 = 0xe06;
      uVar2 = UfsSendQueryUpiu(param_1,-0x7f,(byte *)&local_68,0,(undefined4 *)0x0);
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 == 0) {
        uVar2 = Feature_UfsRemoveManualFlush__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar2 == 0) {
          _local_68 = CONCAT62(stack0xffffffffffffff9a,0xf06);
          uVar2 = UfsSendQueryUpiu(param_1,-0x7f,(byte *)&local_68,0,(undefined4 *)0x0);
          uVar4 = uVar2 & 0xffffffff;
          if ((int)uVar2 != 0) goto LAB_14000fc1c;
        }
        _local_68 = CONCAT62(stack0xffffffffffffff9a,0x1006);
        uVar2 = UfsSendQueryUpiu(param_1,-0x7f,(byte *)&local_68,0,(undefined4 *)0x0);
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 == 0) {
          KeInitializeSpinLock(param_1 + 0x1e8);
          goto LAB_14000fc2e;
        }
      }
LAB_14000fc1c:
      if ((int)uVar4 == 0) {
LAB_14000fc2e:
        *(undefined4 *)(param_1 + 0x1e9) = 1;
        *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 0x4000;
        return uVar4;
      }
      goto LAB_14000fa4f;
    }
    _local_68 = CONCAT62(stack0xffffffffffffff9a,0x201);
    uVar1 = _local_68;
    _local_68 = CONCAT26(0x2d00,_local_68);
    bVar3 = 0;
    local_68._0_3_ = (uint3)uVar1;
    local_68 = (uint)(uint3)local_68;
    do {
      local_68._0_3_ = CONCAT12(bVar3,(undefined2)local_68);
      uVar2 = UfsSendQueryUpiu(param_1,'\x01',(byte *)&local_68,0x2d,(undefined4 *)&local_58);
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 != 0) goto LAB_14000fa4f;
      if (CONCAT13(local_2c,local_30._1_3_) != 0) goto LAB_14000fb87;
      bVar3 = bVar3 + 1;
    } while (bVar3 < 8);
  }
  uVar4 = 0xc1000001;
LAB_14000fa4f:
  *(uint *)(param_1 + 0x193) = *(uint *)(param_1 + 0x193) | 0x4000;
  *(undefined4 *)(param_1 + 0x1e9) = 0;
  StorPortExtendedFunction(0x55,param_1,0);
  return uVar4;
}



===== UfsLogTelemetryEx @ 14000fc4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UfsLogTelemetryEx(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                      char *param_5)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  char *in_stack_00000050;
  char *in_stack_00000060;
  char *in_stack_00000070;
  char *in_stack_00000080;
  char *in_stack_00000090;
  char *in_stack_000000a0;
  char *in_stack_000000b0;
  char *in_stack_000000c0;
  undefined1 auStack_228 [32];
  undefined4 local_208;
  char *local_1f8;
  char *local_1f0;
  char *local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_1c0 [32];
  undefined8 local_1a0;
  undefined1 local_188 [40];
  undefined1 local_160 [40];
  undefined1 local_138 [40];
  undefined1 local_110 [40];
  undefined1 local_e8 [40];
  undefined1 local_c0 [40];
  undefined1 local_98 [40];
  undefined1 local_70 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_228;
  local_1f8 = in_stack_000000a0;
  local_1f0 = in_stack_000000b0;
  local_1e8 = in_stack_000000c0;
  local_1e0 = param_2;
  local_1d8 = param_1;
  memset(&local_1c8,0,0x180);
  uVar1 = 0;
  local_1c8 = 1;
  uVar3 = 0x20;
  pcVar2 = param_5;
  do {
    if (*pcVar2 == '\0') goto LAB_14000fd0d;
    uVar1 = uVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar1 < 0x20);
  uVar1 = 0x20;
LAB_14000fd0d:
  local_1c4 = param_4;
  memmove(local_1c0,param_5,(ulonglong)uVar1);
  local_1a0 = 1;
  if (in_stack_00000050 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = in_stack_00000050;
    do {
      if (*pcVar2 == '\0') goto LAB_14000fd43;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    uVar1 = 0x20;
LAB_14000fd43:
    memmove(local_188,in_stack_00000050,(ulonglong)uVar1);
  }
  if (in_stack_00000060 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = in_stack_00000060;
    do {
      if (*pcVar2 == '\0') goto LAB_14000fd78;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    uVar1 = 0x20;
LAB_14000fd78:
    memmove(local_160,in_stack_00000060,(ulonglong)uVar1);
  }
  if (in_stack_00000070 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = in_stack_00000070;
    do {
      if (*pcVar2 == '\0') goto LAB_14000fdad;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    uVar1 = 0x20;
LAB_14000fdad:
    memmove(local_138,in_stack_00000070,(ulonglong)uVar1);
  }
  if (in_stack_00000080 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = in_stack_00000080;
    do {
      if (*pcVar2 == '\0') goto LAB_14000fde2;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    uVar1 = 0x20;
LAB_14000fde2:
    memmove(local_110,in_stack_00000080,(ulonglong)uVar1);
  }
  if (in_stack_00000090 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = in_stack_00000090;
    do {
      if (*pcVar2 == '\0') goto LAB_14000fe17;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    uVar1 = 0x20;
LAB_14000fe17:
    memmove(local_e8,in_stack_00000090,(ulonglong)uVar1);
  }
  if (local_1f8 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = local_1f8;
    do {
      if (*pcVar2 == '\0') goto LAB_14000fe51;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    uVar1 = 0x20;
LAB_14000fe51:
    memmove(local_c0,local_1f8,(ulonglong)uVar1);
  }
  if (local_1f0 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = local_1f0;
    do {
      if (*pcVar2 == '\0') goto LAB_14000fe8b;
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    uVar1 = 0x20;
LAB_14000fe8b:
    memmove(local_98,local_1f0,(ulonglong)uVar1);
  }
  if (local_1e8 != (char *)0x0) {
    uVar1 = 0;
    pcVar2 = local_1e8;
    do {
      if (*pcVar2 == '\0') {
        uVar3 = uVar1;
        break;
      }
      uVar1 = uVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar1 < 0x20);
    memmove(local_70,local_1e8,(ulonglong)uVar3);
  }
  local_208 = 1;
  StorPortExtendedFunction(0x60,local_1d8,local_1e0,&local_1c8);
  return;
}



===== UfsTelemetryDeviceDesc @ 14000ff40 =====

void UfsTelemetryDeviceDesc(longlong param_1)

{
  if (param_1 != -0x12d8) {
    UfsLogTelemetryEx(param_1,param_1 + 0xdf8,"WriteBoosterActive",2,"UFSDeviceDesc");
  }
  return;
}



===== UfsTelemetryHealthDesc @ 14001006c =====

void UfsTelemetryHealthDesc(longlong *param_1)

{
  byte local_18 [16];
  
  local_18[8] = 0;
  local_18[9] = 0;
  local_18[10] = 0;
  local_18[0xb] = 0;
  local_18[0xc] = 0;
  local_18[0xd] = 0;
  local_18[0xe] = 0;
  local_18[0xf] = 0;
  local_18[0] = 1;
  local_18[1] = 9;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0x2d;
  UfsSendQueryUpiu(param_1,'\x01',local_18,0x2d,(undefined4 *)((longlong)param_1 + 0x1389));
  if ((undefined4 *)((longlong)param_1 + 0x1389) != (undefined4 *)0x0) {
    UfsLogTelemetryEx(param_1,param_1 + 0x1bf,(longlong)param_1 + 0x138e,3,"UFSDeviceDesc");
  }
  return;
}



===== UfsTelemetryHwError @ 1400101ac =====

void UfsTelemetryHwError(longlong param_1)

{
  longlong local_res8;
  uint *in_stack_00000030;
  
  if (param_1 != 0) {
    local_res8 = 0;
    StorPortQuerySystemTime(&local_res8);
    if ((*(uint *)(param_1 + 0xd90) < 2) ||
       (17999999999 < (ulonglong)(local_res8 - *(longlong *)(param_1 + 0xd98)))) {
      *(uint *)(param_1 + 0xd90) = *(uint *)(param_1 + 0xd90) + 1;
      UfsLogTelemetryEx(param_1,param_1 + 0xdf8,(ulonglong)*in_stack_00000030,1,"UFSHandleBusError")
      ;
    }
    *(longlong *)(param_1 + 0xd98) = local_res8;
  }
  return;
}



===== _guard_check_icall @ 140010350 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140010368 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001038c =====

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



===== __cpu_features_init @ 140010400 =====

/* WARNING: Removing unreachable block (ram,0x00014001046a) */
/* WARNING: Removing unreachable block (ram,0x000140010419) */
/* WARNING: Removing unreachable block (ram,0x00014001040a) */

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



===== __security_check_cookie @ 1400104d0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140010510 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140010540 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140010540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140010570 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1400105c0 =====

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



===== memset @ 1400108c0 =====

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



===== __memset_repmovs @ 140010a00 =====

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



===== __memset_query @ 140010a80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140010b00 =====

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



===== __memset_spec_ermsb_repmovsb @ 140010c40 =====

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



===== __memset_spec_plain @ 140010cc0 =====

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



===== FUN_140010e28 @ 140010e28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140010e28(void)

{
  longlong *plVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  longlong lVar8;
  longlong *unaff_RBX;
  uint unaff_EBP;
  uint unaff_ESI;
  uint uVar9;
  uint unaff_R13D;
  bool bVar10;
  undefined4 uStack0000000000000038;
  ulonglong uStack0000000000000068;
  wchar_t *pwStack0000000000000070;
  ulonglong uStack0000000000000078;
  uint uStack0000000000000090;
  char cStack0000000000000094;
  longlong in_stack_000000a0;
  undefined4 uStack00000000000000a8;
  byte in_stack_000000ac;
  
  uStack0000000000000068 = (ulonglong)_DAT_00000000;
  uStack0000000000000038 = 3;
  StorPortExtendedFunction(0x55);
  while( true ) {
    uVar7 = 0xffffffff;
    if (((*(uint *)(unaff_RBX + 0x1b5) & 1) != 0) ||
       (((*(uint *)(unaff_RBX + 0x1b5) & 4) == 0 && (*(int *)((longlong)unaff_RBX + 0xda4) == 0))))
    {
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x12f) & 1) == 0)) {
        uVar7 = *(uint *)(unaff_RBX[0x12e] + 0x14);
      }
      uVar7 = uVar7 & *(uint *)((longlong)unaff_RBX + 0x4f4) & *(uint *)(unaff_RBX + 0x9f) &
              *(uint *)((longlong)unaff_RBX + 0x4fc);
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x12f) & 1) == 0)) {
        *(uint *)(unaff_RBX[0x12e] + 0x14) = uVar7;
        LOCK();
        UNLOCK();
      }
      else {
        uVar7 = uVar7 & ~*(uint *)(unaff_RBX[0x12e] + 8);
      }
      uVar3 = *(uint *)(unaff_RBX + 0xa0);
      do {
        LOCK();
        uVar9 = *(uint *)(unaff_RBX + 0xa0);
        bVar10 = uVar3 == uVar9;
        if (bVar10) {
          *(uint *)(unaff_RBX + 0xa0) = uVar3 | uVar7;
        }
        else {
          uVar3 = uVar9;
        }
        UNLOCK();
      } while (!bVar10);
      if ((~uVar3 & uVar7) != 0) {
        uVar9 = unaff_R13D;
        if (unaff_R13D < *(uint *)(unaff_RBX + 0x12d)) {
          do {
            if (((~uVar3 & uVar7) >> (uVar9 & 0x1f) & 1) != 0) {
              UfsCompleteTransferRequest(unaff_RBX,uVar9,uStack0000000000000090);
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < *(uint *)(unaff_RBX + 0x12d));
        }
        unaff_ESI = 1;
      }
    }
    uVar7 = 0xffffffff;
    if (((*(uint *)(unaff_RBX + 0x1b5) & 1) != 0) ||
       (((*(uint *)(unaff_RBX + 0x1b5) & 4) == 0 && (*(int *)((longlong)unaff_RBX + 0xda4) == 0))))
    {
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
        uVar7 = *(uint *)(unaff_RBX[0x92] + 0x14);
      }
      uVar7 = uVar7 & *(uint *)((longlong)unaff_RBX + 0x14) & *(uint *)(unaff_RBX + 3) &
              *(uint *)((longlong)unaff_RBX + 0x1c);
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
        *(uint *)(unaff_RBX[0x92] + 0x14) = uVar7;
        LOCK();
        UNLOCK();
      }
      else {
        uVar7 = uVar7 & ~*(uint *)(unaff_RBX[0x92] + 8);
      }
      uVar3 = *(uint *)(unaff_RBX + 4);
      do {
        LOCK();
        uVar9 = *(uint *)(unaff_RBX + 4);
        bVar10 = uVar3 == uVar9;
        if (bVar10) {
          *(uint *)(unaff_RBX + 4) = uVar3 | uVar7;
        }
        else {
          uVar3 = uVar9;
        }
        UNLOCK();
      } while (!bVar10);
      if ((~uVar3 & uVar7) != 0) {
        uVar9 = unaff_R13D;
        if (unaff_R13D < *(uint *)(unaff_RBX + 0x91)) {
          do {
            if (((~uVar3 & uVar7) >> (uVar9 & 0x1f) & 1) != 0) {
              UfsCompleteTaskManRequest(unaff_RBX,uVar9);
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < *(uint *)(unaff_RBX + 0x91));
        }
        unaff_ESI = 1;
      }
    }
    if ((uStack0000000000000090 >> 10 & 1) != 0) {
      LOCK();
      if (unaff_ESI == *(uint *)(unaff_RBX + 0x19d)) {
        *(uint *)(unaff_RBX + 0x19d) = unaff_R13D;
      }
      UNLOCK();
    }
    if ((uStack0000000000000090 & 0x40) != 0) {
      LOCK();
      *(uint *)((longlong)unaff_RBX + 0xdac) = unaff_ESI;
      UNLOCK();
    }
    if ((uStack0000000000000090 & 0x20) != 0) {
      LOCK();
      *(uint *)((longlong)unaff_RBX + 0xdac) = unaff_R13D;
      UNLOCK();
    }
    if ((uStack0000000000000090 & 0x10) != 0) {
      *(uint *)(unaff_RBX + 0x193) = *(uint *)(unaff_RBX + 0x193) | 8;
    }
    if ((int)unaff_RBX[0x19d] == 0) break;
    StorPortStallExecution(10);
    unaff_EBP = unaff_EBP + 1;
    if ((uint)((int)unaff_RBX[0x1ca] * 100) <= unaff_EBP) break;
    lVar8 = *unaff_RBX;
    uStack0000000000000090 = ~*(uint *)(lVar8 + 0x24) & *(uint *)(lVar8 + 0x20);
    *(uint *)(lVar8 + 0x20) = uStack0000000000000090;
    LOCK();
    UNLOCK();
    cVar2 = UfsHandleBusError(unaff_RBX,&uStack0000000000000090);
    if (cVar2 != '\0') {
      *(int *)(unaff_RBX + 0x34d) = (int)unaff_RBX[0x34d] + 1;
      _cStack0000000000000094 = unaff_R13D;
      StorPortNotification(0x1002);
      if ((cStack0000000000000094 == (char)unaff_R13D) &&
         ((*(uint *)(unaff_RBX + 0x193) & 0x8000) != 0)) {
        uVar4 = FUN_140010e28();
        return uVar4;
      }
    }
  }
  uStack0000000000000078 = (ulonglong)unaff_R13D;
  if ((0 < (int)unaff_RBX[0x19d]) || (unaff_EBP == (int)unaff_RBX[0x1ca] * 100)) {
    uStack0000000000000078 = 0xc1000001;
  }
  lVar8 = 3;
  puVar5 = &uStack00000000000000a8;
  do {
    *puVar5 = *(undefined4 *)
               ((in_stack_000000a0 - (longlong)&uStack00000000000000a8) + 0x90 +
               (longlong)(puVar5 + 1));
    lVar8 = lVar8 + -1;
    puVar5 = puVar5 + 1;
  } while (lVar8 != 0);
  if ((*(byte *)(unaff_RBX + 0x193) & 1) == 0) {
    LOCK();
    plVar1 = unaff_RBX + 0x345;
    lVar8 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    puVar6 = (undefined8 *)
             ((ulonglong)(*(uint *)((longlong)unaff_RBX + 0x1a2c) & (int)lVar8 - 1U) * 0x20 +
             unaff_RBX[0x346]);
    unaff_RBX[0x347] = (longlong)puVar6;
    puVar6[2] = (ulonglong)uStack00000000000000a8;
    puVar6[3] = (ulonglong)in_stack_000000ac;
    *puVar6 = 0x43434955;
    puVar6[1] = 3;
  }
  *(uint *)(unaff_RBX + 0x193) = *(uint *)(unaff_RBX + 0x193) & 0xfffffffd;
  LOCK();
  if (unaff_ESI == *(uint *)(unaff_RBX + 0x19d)) {
    *(uint *)(unaff_RBX + 0x19d) = unaff_R13D;
  }
  UNLOCK();
  if ((int)uStack0000000000000078 == 0) {
LAB_1400014ad:
    if (in_stack_000000ac == 0) {
      return (ulonglong)unaff_R13D;
    }
  }
  else {
    if ((*(uint *)(unaff_RBX + 0x193) & 0x8000) == 0) {
      if ((int)uStack0000000000000078 == 0) goto LAB_1400014ad;
    }
    else {
      pwStack0000000000000070 = L"status";
      uStack0000000000000068 = 3;
      uStack0000000000000038 = 3;
      StorPortExtendedFunction(0x56);
    }
    if ((*(uint *)(unaff_RBX + 0x193) & 0x8000) != 0) {
      uStack0000000000000068 = (ulonglong)uStack00000000000000a8;
      uStack0000000000000078 = 1;
      pwStack0000000000000070 = L"errorStatus";
      uStack0000000000000038 = 3;
      StorPortExtendedFunction(0x56);
    }
  }
  return 0xc1000001;
}



===== FUN_1400110aa @ 1400110aa =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1400110aa(void)

{
  longlong *plVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  uint *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  longlong lVar9;
  longlong *unaff_RBX;
  uint unaff_EBP;
  uint uVar10;
  uint unaff_R12D;
  undefined8 unaff_R14;
  bool bVar11;
  undefined8 uStack0000000000000030;
  undefined4 uStack0000000000000038;
  undefined4 uStack0000000000000040;
  ulonglong uStack0000000000000058;
  wchar_t *pwStack0000000000000070;
  ulonglong uStack0000000000000078;
  undefined8 uStack0000000000000080;
  undefined8 uStack0000000000000088;
  uint in_stack_00000094;
  longlong in_stack_000000a0;
  uint uStack00000000000000f0;
  uint *in_stack_00000100;
  uint *in_stack_00000108;
  
  uStack0000000000000058 = (ulonglong)uStack00000000000000f0;
  uStack0000000000000038 = 3;
  uStack0000000000000030 = 1;
  StorPortExtendedFunction(0x55);
  do {
    uVar8 = 0xffffffff;
    if (((*(uint *)(unaff_RBX + 0x1b5) & 1) != 0) ||
       (((*(uint *)(unaff_RBX + 0x1b5) & 4) == 0 && (*(int *)((longlong)unaff_RBX + 0xda4) == 0))))
    {
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x12f) & 1) == 0)) {
        uVar8 = *(uint *)(unaff_RBX[0x12e] + 0x14);
      }
      uVar8 = uVar8 & *(uint *)((longlong)unaff_RBX + 0x4f4) & *(uint *)(unaff_RBX + 0x9f) &
              *(uint *)((longlong)unaff_RBX + 0x4fc);
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x12f) & 1) == 0)) {
        *(uint *)(unaff_RBX[0x12e] + 0x14) = uVar8;
        LOCK();
        UNLOCK();
      }
      else {
        uVar8 = uVar8 & ~*(uint *)(unaff_RBX[0x12e] + 8);
      }
      uVar4 = *(uint *)(unaff_RBX + 0xa0);
      do {
        LOCK();
        uVar10 = *(uint *)(unaff_RBX + 0xa0);
        bVar11 = uVar4 == uVar10;
        if (bVar11) {
          *(uint *)(unaff_RBX + 0xa0) = uVar4 | uVar8;
        }
        else {
          uVar4 = uVar10;
        }
        UNLOCK();
      } while (!bVar11);
      if (((~uVar4 & uVar8) != 0) &&
         (uVar10 = unaff_R12D, unaff_R12D < *(uint *)(unaff_RBX + 0x12d))) {
        do {
          if (((~uVar4 & uVar8) >> (uVar10 & 0x1f) & 1) != 0) {
            UfsCompleteTransferRequest(unaff_RBX,uVar10,uStack00000000000000f0);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint *)(unaff_RBX + 0x12d));
      }
    }
    uVar8 = 0xffffffff;
    if (((*(uint *)(unaff_RBX + 0x1b5) & 1) != 0) ||
       (((*(uint *)(unaff_RBX + 0x1b5) & 4) == 0 && (*(int *)((longlong)unaff_RBX + 0xda4) == 0))))
    {
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
        uVar8 = *(uint *)(unaff_RBX[0x92] + 0x14);
      }
      uVar8 = uVar8 & *(uint *)((longlong)unaff_RBX + 0x14) & *(uint *)(unaff_RBX + 3) &
              *(uint *)((longlong)unaff_RBX + 0x1c);
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
        *(uint *)(unaff_RBX[0x92] + 0x14) = uVar8;
        LOCK();
        UNLOCK();
      }
      else {
        uVar8 = uVar8 & ~*(uint *)(unaff_RBX[0x92] + 8);
      }
      uVar4 = *(uint *)(unaff_RBX + 4);
      do {
        LOCK();
        uVar10 = *(uint *)(unaff_RBX + 4);
        bVar11 = uVar4 == uVar10;
        if (bVar11) {
          *(uint *)(unaff_RBX + 4) = uVar4 | uVar8;
        }
        else {
          uVar4 = uVar10;
        }
        UNLOCK();
      } while (!bVar11);
      if (((~uVar4 & uVar8) != 0) && (uVar10 = unaff_R12D, unaff_R12D < *(uint *)(unaff_RBX + 0x91))
         ) {
        do {
          if (((~uVar4 & uVar8) >> (uVar10 & 0x1f) & 1) != 0) {
            UfsCompleteTaskManRequest(unaff_RBX,uVar10);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint *)(unaff_RBX + 0x91));
      }
    }
    if ((uStack00000000000000f0 >> 10 & 1) != 0) {
      LOCK();
      if (*(uint *)(unaff_RBX + 0x19d) == 1) {
        *(uint *)(unaff_RBX + 0x19d) = unaff_R12D;
      }
      UNLOCK();
    }
    if ((uStack00000000000000f0 & 0x40) != 0) {
      LOCK();
      *(undefined4 *)((longlong)unaff_RBX + 0xdac) = 1;
      UNLOCK();
    }
    if ((uStack00000000000000f0 & 0x20) != 0) {
      LOCK();
      *(uint *)((longlong)unaff_RBX + 0xdac) = unaff_R12D;
      UNLOCK();
    }
    if ((uStack00000000000000f0 & 0x10) != 0) {
      *(uint *)(unaff_RBX + 0x193) = *(uint *)(unaff_RBX + 0x193) | 8;
    }
    if ((int)unaff_R14 == 0x18) {
      iVar2 = *(int *)((longlong)unaff_RBX + 0xdac);
LAB_140001a5c:
      if (iVar2 == 0) goto LAB_140001a5e;
    }
    else {
      if ((int)unaff_R14 == 0x17) {
        iVar2 = *(int *)((longlong)unaff_RBX + 0xdac) + -1;
        goto LAB_140001a5c;
      }
LAB_140001a5e:
      if ((int)unaff_RBX[0x19d] == 0) goto LAB_140001a91;
    }
    StorPortStallExecution(10);
    unaff_EBP = unaff_EBP + 1;
    if ((uint)((int)unaff_RBX[0x1ca] * 100) <= unaff_EBP) {
LAB_140001a91:
      if ((0 < (int)unaff_RBX[0x19d]) || (unaff_EBP == (int)unaff_RBX[0x1ca] * 100)) {
        in_stack_00000094 = 0xc1000001;
      }
      lVar9 = 3;
      puVar6 = in_stack_00000100;
      do {
        *puVar6 = *(uint *)((longlong)puVar6 +
                           (in_stack_000000a0 - (longlong)in_stack_00000100) + 0x94);
        lVar9 = lVar9 + -1;
        puVar6 = puVar6 + 1;
      } while (lVar9 != 0);
      if (in_stack_00000108 != (uint *)0x0) {
        *in_stack_00000108 = in_stack_00000100[1] & 0xff;
      }
      uVar8 = in_stack_00000100[1];
      uVar4 = *in_stack_00000100;
      if ((*(byte *)(unaff_RBX + 0x193) & 1) == 0) {
        LOCK();
        plVar1 = unaff_RBX + 0x345;
        lVar9 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        puVar7 = (undefined8 *)
                 ((ulonglong)(*(uint *)((longlong)unaff_RBX + 0x1a2c) & (int)lVar9 - 1U) * 0x20 +
                 unaff_RBX[0x346]);
        unaff_RBX[0x347] = (longlong)puVar7;
        *puVar7 = 0x43434955;
        puVar7[1] = unaff_R14;
        puVar7[2] = (ulonglong)uVar4;
        puVar7[3] = (ulonglong)(uVar8 & 0xff);
      }
      *(uint *)(unaff_RBX + 0x193) = *(uint *)(unaff_RBX + 0x193) & 0xfffffffd;
      LOCK();
      if ((int)unaff_RBX[0x19d] == 1) {
        *(int *)(unaff_RBX + 0x19d) = 0;
      }
      UNLOCK();
      if ((in_stack_00000094 != 0) && ((*(uint *)(unaff_RBX + 0x193) & 0x8000) != 0)) {
        uStack0000000000000058 = (ulonglong)*in_stack_00000108;
        uStack0000000000000088 = 0;
        uStack0000000000000080 = 0;
        uStack0000000000000078 = (ulonglong)in_stack_00000094;
        pwStack0000000000000070 = L"status";
        uStack0000000000000040 = 0;
        uStack0000000000000038 = 3;
        uStack0000000000000030 = 1;
        StorPortExtendedFunction(0x56);
      }
      return (ulonglong)in_stack_00000094;
    }
    lVar9 = *unaff_RBX;
    uStack00000000000000f0 = ~*(uint *)(lVar9 + 0x24) & *(uint *)(lVar9 + 0x20);
    *(uint *)(lVar9 + 0x20) = uStack00000000000000f0;
    LOCK();
    UNLOCK();
    cVar3 = UfsHandleBusError(unaff_RBX,&uStack00000000000000f0);
    if (cVar3 != '\0') {
      *(int *)(unaff_RBX + 0x34d) = (int)unaff_RBX[0x34d] + 1;
      StorPortNotification(0x1002);
      if ((*(uint *)(unaff_RBX + 0x193) & 0x8000) != 0) {
        uVar5 = FUN_1400110aa();
        return uVar5;
      }
    }
  } while( true );
}



===== FUN_1400113fa @ 1400113fa =====

/* PDB: Separated code (from the compiler): 1400113fa - 140011659 for parent address: 140002a80 */

undefined8 FUN_1400113fa(void)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  longlong *unaff_RBX;
  ulonglong unaff_RBP;
  uint unaff_EDI;
  wchar_t *pwVar8;
  uint unaff_R12D;
  uint unaff_R13D;
  uint unaff_R14D;
  uint unaff_R15D;
  bool bVar9;
  wchar_t *pwStack0000000000000028;
  undefined8 uStack0000000000000030;
  undefined4 uStack0000000000000038;
  undefined4 uStack0000000000000040;
  wchar_t *pwStack0000000000000050;
  ulonglong uStack0000000000000068;
  wchar_t *pwStack0000000000000070;
  undefined8 uStack0000000000000078;
  undefined8 uStack0000000000000080;
  undefined8 uStack0000000000000088;
  longlong in_stack_00000098;
  wchar_t wStack00000000000000e0;
  uint uStack00000000000000e8;
  uint in_stack_000000f8;
  int in_stack_00000100;
  longlong in_stack_00000108;
  
  uStack0000000000000068 = unaff_RBP & 0xffffffff;
  pwStack0000000000000050 = L"is";
  uStack0000000000000038 = 3;
  uStack0000000000000030 = 1;
  pwStack0000000000000028 = L"UfsPollForCompletion reset bus initiation already in progress.";
  StorPortExtendedFunction();
  while( true ) {
    uVar6 = 0xffffffff;
    if (((*(uint *)(unaff_RBX + 0x1b5) & 1) == 0) &&
       (((*(uint *)(unaff_RBX + 0x1b5) & 4) != 0 || (*(int *)((longlong)unaff_RBX + 0xda4) != 0))))
    {
      uVar6 = unaff_EDI;
    }
    else {
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x12f) & 1) == 0)) {
        uVar6 = *(uint *)(unaff_RBX[0x12e] + 0x14);
      }
      uVar6 = uVar6 & *(uint *)((longlong)unaff_RBX + 0x4f4) & *(uint *)(unaff_RBX + 0x9f) &
              *(uint *)((longlong)unaff_RBX + 0x4fc);
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x12f) & 1) == 0)) {
        *(uint *)(unaff_RBX[0x12e] + 0x14) = uVar6;
        LOCK();
        UNLOCK();
      }
      else {
        uVar6 = uVar6 & ~*(uint *)(unaff_RBX[0x12e] + 8);
      }
      uVar7 = *(uint *)(unaff_RBX + 0xa0);
      do {
        LOCK();
        uVar4 = *(uint *)(unaff_RBX + 0xa0);
        bVar9 = uVar7 == uVar4;
        if (bVar9) {
          *(uint *)(unaff_RBX + 0xa0) = uVar7 | uVar6;
        }
        else {
          uVar7 = uVar4;
        }
        UNLOCK();
      } while (!bVar9);
      uVar6 = ~uVar7 & uVar6;
      if (uVar6 != 0) {
        if ((int)unaff_RBX[0x12d] != 0) {
          do {
            if ((uVar6 >> (unaff_EDI & 0x1f) & 1) != 0) {
              UfsCompleteTransferRequest(unaff_RBX,unaff_EDI,uStack00000000000000e8);
            }
            unaff_EDI = unaff_EDI + 1;
          } while (unaff_EDI < *(uint *)(unaff_RBX + 0x12d));
        }
        unaff_EDI = 0;
      }
    }
    uVar7 = 0xffffffff;
    if (((*(uint *)(unaff_RBX + 0x1b5) & 1) != 0) ||
       (((*(uint *)(unaff_RBX + 0x1b5) & 4) == 0 && (*(int *)((longlong)unaff_RBX + 0xda4) == 0))))
    {
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
        uVar7 = *(uint *)(unaff_RBX[0x92] + 0x14);
      }
      uVar7 = uVar7 & *(uint *)((longlong)unaff_RBX + 0x14) & *(uint *)(unaff_RBX + 3) &
              *(uint *)((longlong)unaff_RBX + 0x1c);
      if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
         ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
        *(uint *)(unaff_RBX[0x92] + 0x14) = uVar7;
        LOCK();
        UNLOCK();
      }
      else {
        uVar7 = uVar7 & ~*(uint *)(unaff_RBX[0x92] + 8);
      }
      uVar4 = *(uint *)(unaff_RBX + 4);
      do {
        LOCK();
        uVar1 = *(uint *)(unaff_RBX + 4);
        bVar9 = uVar4 == uVar1;
        if (bVar9) {
          *(uint *)(unaff_RBX + 4) = uVar4 | uVar7;
        }
        else {
          uVar4 = uVar1;
        }
        UNLOCK();
      } while (!bVar9);
      unaff_EDI = ~uVar4 & uVar7;
      if ((unaff_EDI != 0) && (uVar7 = 0, (int)unaff_RBX[0x91] != 0)) {
        do {
          if ((unaff_EDI >> (uVar7 & 0x1f) & 1) != 0) {
            UfsCompleteTaskManRequest(unaff_RBX,uVar7);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint *)(unaff_RBX + 0x91));
      }
    }
    if ((uStack00000000000000e8 >> 10 & 1) != 0) {
      LOCK();
      if ((int)unaff_RBX[0x19d] == 1) {
        *(int *)(unaff_RBX + 0x19d) = 0;
      }
      UNLOCK();
    }
    if ((uStack00000000000000e8 & 0x40) != 0) {
      LOCK();
      *(undefined4 *)((longlong)unaff_RBX + 0xdac) = 1;
      UNLOCK();
    }
    if ((uStack00000000000000e8 & 0x20) != 0) {
      LOCK();
      *(undefined4 *)((longlong)unaff_RBX + 0xdac) = 0;
      UNLOCK();
    }
    if ((uStack00000000000000e8 & 0x10) != 0) {
      *(uint *)(unaff_RBX + 0x193) = *(uint *)(unaff_RBX + 0x193) | 8;
    }
    if (((unaff_R12D != 0xffffffff) && ((uVar6 >> (unaff_R12D & 0x1f) & 1) != 0)) ||
       ((unaff_R15D != 0xffffffff && ((unaff_EDI >> (unaff_R15D & 0x1f) & 1) != 0)))) break;
    StorPortStallExecution(10);
    unaff_R14D = unaff_R14D + 1;
    unaff_EDI = 0;
    if (unaff_R13D <= unaff_R14D) break;
    lVar2 = *unaff_RBX;
    uStack00000000000000e8 = ~*(uint *)(lVar2 + 0x24) & *(uint *)(lVar2 + 0x20);
    *(uint *)(lVar2 + 0x20) = uStack00000000000000e8;
    LOCK();
    UNLOCK();
    cVar3 = UfsHandleBusError(unaff_RBX,&uStack00000000000000e8);
    if (cVar3 != '\0') {
      *(int *)(unaff_RBX + 0x34d) = (int)unaff_RBX[0x34d] + 1;
      pwStack0000000000000028 = &wStack00000000000000e0;
      _wStack00000000000000e0 = 0;
      StorPortNotification();
      if (((char)wStack00000000000000e0 == '\0') && ((*(uint *)(unaff_RBX + 0x193) & 0x8000) != 0))
      {
        uVar5 = FUN_1400113fa();
        return uVar5;
      }
    }
  }
  if (unaff_R14D == in_stack_00000100 * 100) {
    pwVar8 = L"Completion of the transfer request failed with timeout.";
    if (unaff_R12D == 0xffffffff) {
      if (unaff_R15D != 0xffffffff) {
        uVar7 = 1 << ((byte)unaff_R15D & 0x1f);
        *(uint *)(in_stack_00000098 + 0x7c) = ~uVar7 & 0xff;
        LOCK();
        UNLOCK();
        uVar6 = 0;
        do {
          if ((byte)((byte)uVar7 & (byte)*(undefined4 *)(in_stack_00000098 + 0x78)) != 0) break;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 10);
        uVar5 = UfsReleaseCompletionIndex(unaff_RBX,(longlong)(unaff_RBX + 2),unaff_R15D);
        pwVar8 = L"Completion of the transfer request failed while release completion index.";
        if ((int)uVar5 == 0) {
          pwVar8 = L"Completion of the transfer request failed with timeout.";
        }
      }
    }
    else {
      uVar6 = 0;
      uVar5 = UfsSendTaskManRequest((longlong)unaff_RBX,unaff_R12D,in_stack_000000f8,1,0);
      pwVar8 = L"Completion of the transfer request failed during send task man request.";
      if ((int)uVar5 == 0) {
        pwVar8 = L"Completion of the transfer request failed with timeout.";
      }
      uVar7 = 1 << ((byte)unaff_R12D & 0x1f);
      *(uint *)(in_stack_00000098 + 0x5c) = ~uVar7;
      LOCK();
      UNLOCK();
      do {
        if ((*(uint *)(in_stack_00000098 + 0x58) & uVar7) != 0) break;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 10);
      uVar5 = UfsReleaseCompletionIndex(unaff_RBX,(longlong)(unaff_RBX + 0x9e),unaff_R12D);
      if ((int)uVar5 != 0) {
        pwVar8 = L"Completion of the transfer request failed while release completion index.";
      }
    }
    if (in_stack_00000108 != 0) {
      *(undefined1 *)(in_stack_00000108 + 3) = 9;
      pwVar8 = L"Completion of the transfer request failed with status timeout.";
    }
    if ((*(uint *)(unaff_RBX + 0x193) & 0x8000) != 0) {
      uStack0000000000000088 = 0;
      uStack0000000000000080 = 0;
      uStack0000000000000068 = (ulonglong)in_stack_000000f8;
      uStack0000000000000078 = 0xc1000001;
      pwStack0000000000000070 = L"status";
      pwStack0000000000000050 = L"TrlIndex";
      uStack0000000000000040 = 0;
      uStack0000000000000038 = 3;
      uStack0000000000000030 = 1;
      pwStack0000000000000028 = pwVar8;
      StorPortExtendedFunction(0x56);
    }
    uVar5 = 0xc1000001;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



===== FUN_14001165a @ 14001165a =====

/* PDB: Separated code (from the compiler): 14001165a - 140011724 for parent address: 140002e90 */

void FUN_14001165a(void)

{
  uint uVar1;
  uint uVar2;
  longlong *unaff_RBX;
  uint uVar3;
  uint uVar4;
  uint *unaff_R12;
  uint unaff_R13D;
  uint *unaff_R14;
  byte bVar5;
  uint unaff_R15D;
  bool bVar6;
  wchar_t *pwStack0000000000000028;
  undefined4 uStack0000000000000038;
  wchar_t *pwStack0000000000000050;
  ulonglong uStack0000000000000058;
  wchar_t *pwStack0000000000000060;
  ulonglong uStack0000000000000068;
  uint in_stack_000000b0;
  
  uStack0000000000000068 = (ulonglong)*unaff_R14;
  uStack0000000000000058 = (ulonglong)in_stack_000000b0;
  pwStack0000000000000060 = L"TrlResources";
  pwStack0000000000000050 = L"is";
  uStack0000000000000038 = 3;
  pwStack0000000000000028 = L"UfsPollForCompletion reset bus initiation already in progress.";
  StorPortExtendedFunction(0x55);
  uVar3 = 0xffffffff;
  uVar2 = 0xffffffff;
  bVar5 = (byte)unaff_R15D;
  if (((bVar5 & (byte)unaff_RBX[0x1b5]) == 0) &&
     (((*(uint *)(unaff_RBX + 0x1b5) & 4) != 0 || (*(int *)((longlong)unaff_RBX + 0xda4) != 0)))) {
    uVar2 = unaff_R13D;
  }
  else {
    if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
       ((bVar5 & (byte)unaff_RBX[0x12f]) == 0)) {
      uVar2 = *(uint *)(unaff_RBX[0x12e] + 0x14);
    }
    uVar2 = uVar2 & *(uint *)((longlong)unaff_RBX + 0x4f4) & *(uint *)(unaff_RBX + 0x9f) &
            *(uint *)((longlong)unaff_RBX + 0x4fc);
    if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
       ((bVar5 & (byte)unaff_RBX[0x12f]) == 0)) {
      *(uint *)(unaff_RBX[0x12e] + 0x14) = uVar2;
      LOCK();
      UNLOCK();
    }
    else {
      uVar2 = uVar2 & ~*(uint *)(unaff_RBX[0x12e] + 8);
    }
    uVar4 = *(uint *)(unaff_RBX + 0xa0);
    do {
      LOCK();
      uVar1 = *(uint *)(unaff_RBX + 0xa0);
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        *(uint *)(unaff_RBX + 0xa0) = uVar4 | uVar2;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
    uVar2 = ~uVar4 & uVar2;
    if (uVar2 != 0) {
      uVar4 = unaff_R13D;
      if (unaff_R13D < *(uint *)(unaff_RBX + 0x12d)) {
        do {
          if ((uVar2 >> (uVar4 & 0x1f) & 1) != 0) {
            UfsCompleteTransferRequest(unaff_RBX,uVar4,in_stack_000000b0);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(unaff_RBX + 0x12d));
      }
      unaff_R15D = 1;
    }
  }
  if (((*(uint *)(unaff_RBX + 0x1b5) & 1) == 0) &&
     (((*(uint *)(unaff_RBX + 0x1b5) & 4) != 0 || (*(int *)((longlong)unaff_RBX + 0xda4) != 0)))) {
    uVar3 = unaff_R13D;
  }
  else {
    if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
      uVar3 = *(uint *)(unaff_RBX[0x92] + 0x14);
    }
    uVar3 = uVar3 & *(uint *)((longlong)unaff_RBX + 0x14) & *(uint *)(unaff_RBX + 3) &
            *(uint *)((longlong)unaff_RBX + 0x1c);
    if (((*(uint *)((longlong)unaff_RBX + 0xe24) & 0x10) == 0) &&
       ((*(uint *)(unaff_RBX + 0x93) & 1) == 0)) {
      *(uint *)(unaff_RBX[0x92] + 0x14) = uVar3;
      LOCK();
      UNLOCK();
    }
    else {
      uVar3 = uVar3 & ~*(uint *)(unaff_RBX[0x92] + 8);
    }
    uVar4 = *(uint *)(unaff_RBX + 4);
    do {
      LOCK();
      uVar1 = *(uint *)(unaff_RBX + 4);
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        *(uint *)(unaff_RBX + 4) = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
    uVar3 = ~uVar4 & uVar3;
    if ((uVar3 != 0) && (uVar4 = unaff_R13D, unaff_R13D < *(uint *)(unaff_RBX + 0x91))) {
      do {
        if ((uVar3 >> (uVar4 & 0x1f) & 1) != 0) {
          UfsCompleteTaskManRequest(unaff_RBX,uVar4);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(unaff_RBX + 0x91));
    }
  }
  if ((in_stack_000000b0 >> 10 & 1) != 0) {
    LOCK();
    if (unaff_R15D == *(uint *)(unaff_RBX + 0x19d)) {
      *(uint *)(unaff_RBX + 0x19d) = unaff_R13D;
    }
    UNLOCK();
  }
  if ((in_stack_000000b0 & 0x40) != 0) {
    LOCK();
    *(uint *)((longlong)unaff_RBX + 0xdac) = unaff_R15D;
    UNLOCK();
  }
  if ((in_stack_000000b0 & 0x20) != 0) {
    LOCK();
    *(uint *)((longlong)unaff_RBX + 0xdac) = unaff_R13D;
    UNLOCK();
  }
  if ((in_stack_000000b0 & 0x10) != 0) {
    *(uint *)(unaff_RBX + 0x193) = *(uint *)(unaff_RBX + 0x193) | 8;
  }
  if (unaff_R14 != (uint *)0x0) {
    *unaff_R14 = uVar2;
  }
  if (unaff_R12 != (uint *)0x0) {
    *unaff_R12 = uVar3;
  }
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001c008 =====

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



===== wil_UninitializeFeatureStaging @ 14001c0d4 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14001c12c =====

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
      goto LAB_14001c189;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001c189;
    }
  }
  uVar1 = 0x206;
LAB_14001c189:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001c194 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001c24c =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14001c284 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001c306;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001c306;
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
LAB_14001c306:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001c350 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001c3b0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001c3cc =====

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



===== entry @ 14001e010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001e044 =====

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



===== wil_InitializeFeatureStaging @ 14001e078 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001e168 =====

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


