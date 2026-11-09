
===== WinHvOnInterrupt @ 140001010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WinHvOnInterrupt(void)

{
  uint *puVar1;
  uint uVar2;
  uint *_Src;
  byte bVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  bool bVar7;
  
  bVar3 = KeGetCurrentIrql();
  bVar7 = bVar3 < 0xc;
  if (bVar7) {
    bVar3 = KfRaiseIrql(0xc);
  }
  _Src = *(uint **)(WinHvpVpDataPages + (ulonglong)SystemReserved1[0x12]._4_4_ * 0x30);
  if (*_Src == 0) goto LAB_1400010f7;
  uVar2 = *_Src;
  if ((uVar2 & 0xffffff00) == 0x80000100) {
    lVar5 = (ulonglong)SystemReserved1[0x12]._4_4_ * 0x170 + DAT_140015150;
    memmove((void *)(lVar5 + 0x70),_Src,(ulonglong)(byte)_Src[1] + 0x10);
    *(undefined1 *)(lVar5 + 0x20) = 1;
    KeSetTargetProcessorDpcEx(lVar5 + 0x28,lVar5 + 4);
    KeInsertQueueDpc(lVar5 + 0x28,0,0);
    goto LAB_1400010f7;
  }
  if (uVar2 == 0x80000040) {
    if (WinHvpEventLogCompletedNotificationRoutine != (code *)0x0) {
      (*WinHvpEventLogCompletedNotificationRoutine)(_Src[4]);
    }
  }
  else if (uVar2 == 0x80000061) {
    if ((code *)0x1 < *(code **)(&WinHvpGlobalSintInterceptHandlers + (ulonglong)_Src[4] * 8)) {
      (**(code **)(&WinHvpGlobalSintInterceptHandlers + (ulonglong)_Src[4] * 8))
                (*(undefined8 *)(&WinHvpGlobalSintInterceptHandlerContexts + (ulonglong)_Src[4] * 8)
                );
    }
  }
  else if (uVar2 == 0x80000070) {
    WinHvpOnCallCompletionNotification((longlong)_Src);
  }
  else if (uVar2 == 0x80000071) {
    if (*(longlong *)(_Src + 2) == WinHvpCurrentPartitionId) {
      WinHvpOnRootInsufficientMemoryNotification((longlong)_Src);
    }
    else {
LAB_140001251:
      WinHvpOnInterception((longlong)_Src);
    }
  }
  else if (uVar2 == 0x80000072) {
    WinHvpOnMirroringNotification((longlong)_Src);
  }
  else {
    if (uVar2 != 0x80000073) goto LAB_140001251;
    if (WinHvpBlackbox != 0) {
      LOCK();
      puVar1 = (uint *)(WinHvpBlackbox + 4);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 1;
      UNLOCK();
      uVar6 = (ulonglong)(uVar2 & 0x3f);
      *(uint *)(WinHvpBlackbox + 8 + uVar6 * 0x10) = 4 - (uint)(_Src[5] != 0);
      *(undefined4 *)(WinHvpBlackbox + 0xc + uVar6 * 0x10) = 0;
      uVar4 = KeQueryPerformanceCounter(0);
      *(undefined8 *)(WinHvpBlackbox + 0x10 + uVar6 * 0x10) = uVar4;
    }
    WinHvpOnRestartCompletionNotification((longlong)_Src);
  }
  *_Src = 0;
  LOCK();
  UNLOCK();
  if ((*(byte *)((longlong)_Src + 5) & 1) != 0) {
    WinHvpSetVpRegister64Self(0xa0014,0);
  }
LAB_1400010f7:
  if (bVar7) {
    KeLowerIrql(bVar3);
  }
  return;
}



===== WinHvpSetVpRegister64Self @ 140001264 =====

void WinHvpSetVpRegister64Self(int param_1,undefined8 param_2)

{
  WinHvpSetVpRegister64Self2(param_1,param_2,'\0');
  return;
}



===== WinHvGetPartitionProperty @ 140001280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetPartitionProperty(undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 ****local_58;
  undefined8 *local_50;
  undefined8 *local_48;
  undefined8 local_40;
  ushort local_38;
  undefined4 local_36;
  undefined2 local_32;
  undefined *local_30;
  byte local_28;
  undefined7 uStack_27;
  code *local_20;
  
                    /* 0x1280  79  WinHvGetPartitionProperty */
  local_40 = 0;
  local_36 = 0;
  local_32 = 0;
  local_28 = 0;
  uStack_27 = 0;
  local_30 = (undefined *)0x0;
  local_38 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  local_30 = (undefined *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)local_38 * 0x80 + WinHvpNodeToHypercallLookaside);
  local_20 = WinHvpReleasePoolBuffers;
  if (local_30 == (undefined *)0x0) {
    local_28 = KeGetCurrentIrql();
    if (local_28 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      local_30 = &WinHvpFallbackBuffer2;
    }
    else {
      local_28 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      local_30 = &WinHvpFallbackBuffer;
    }
    local_20 = WinHvpReleaseFallbackBuffers;
  }
  local_50 = *(undefined8 **)(local_30 + 0x10);
  puVar1 = *(undefined8 **)(local_30 + 0x20);
  local_58 = &local_58;
  *local_50 = param_1;
  *(undefined4 *)(local_50 + 1) = param_2;
  local_48 = puVar1;
  uVar2 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_58,0x44);
  if (-1 < (int)uVar2) {
    *param_3 = *puVar1;
  }
  (*local_20)(local_58);
  return uVar2;
}



===== WinHvUnmapGpaPages @ 1400013d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvUnmapGpaPages(undefined8 param_1,longlong param_2,uint param_3,ulonglong param_4,
                       longlong *param_5)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 auStackY_128 [32];
  ulonglong local_e8;
  undefined8 *local_e0;
  longlong local_d8;
  undefined8 *local_d0;
  code *local_a0;
  undefined1 local_98 [64];
  undefined8 local_58;
  longlong lStack_50;
  uint local_48;
  undefined4 uStack_44;
  ulonglong local_40;
  
                    /* 0x13d0  190  WinHvUnmapGpaPages */
  local_40 = __security_cookie ^ (ulonglong)auStackY_128;
  memset(&local_d8,0,0x40);
  uStack_44 = 0;
  uVar2 = 0;
  *param_5 = 0;
  local_e8 = 0;
  local_58 = param_1;
  lStack_50 = param_2;
  local_48 = param_3;
  if (0xfff < param_4) {
    iVar1 = (int)param_2;
    uVar3 = (ulonglong)((iVar1 + 0xfffU & 0xfffffe00) - iVar1);
    if (param_4 - uVar3 < 0x1000) {
      uVar2 = WinHvpRangeRepHypercall
                        (0x4c,uVar3,&local_58,0x18,&lStack_50,1,&local_d8,(longlong *)&local_e8);
      *param_5 = *param_5 + local_e8;
      param_4 = param_4 - local_e8;
      if ((int)uVar2 < 0) goto LAB_1400014df;
    }
    else {
      uVar2 = (iVar1 + 0x1ffU & 0xfffffe00) - iVar1;
      if (uVar2 != 0) {
        uVar2 = WinHvpRangeRepHypercall
                          (0x4c,(ulonglong)uVar2,&local_58,0x18,&lStack_50,1,&local_d8,
                           (longlong *)&local_e8);
        *param_5 = *param_5 + local_e8;
        param_4 = param_4 - local_e8;
        if ((int)uVar2 < 0) goto LAB_1400014df;
        param_3 = local_48;
      }
      local_48 = param_3 | 2;
      uVar2 = WinHvpRangeRepHypercall
                        (0x4c,param_4 >> 9,&local_58,0x18,&lStack_50,0x200,&local_d8,
                         (longlong *)&local_e8);
      *param_5 = *param_5 + local_e8 * 0x200;
      param_4 = param_4 + local_e8 * -0x200;
      if ((int)uVar2 < 0) goto LAB_1400014df;
      local_48 = local_48 & 0xfffffffd;
    }
  }
  if (param_4 != 0) {
    memset(local_98,0,0x40);
    local_e0 = (undefined8 *)0x0;
    plVar5 = (longlong *)0x0;
    local_e8 = local_e8 & 0xffffffff00000000;
    uVar2 = 0;
    lVar4 = 0;
    if (local_d8 != 0) {
      local_e0 = local_d0;
      *local_d0 = local_58;
      local_d0[1] = lStack_50;
      plVar5 = local_d0 + 1;
      local_d0[2] = CONCAT44(uStack_44,local_48);
    }
    do {
      if (param_4 == 0) break;
      if (local_d8 == 0) {
        WinHvpSetupHypercall(&local_e0,(undefined8 *)0x0,(longlong)&local_d8);
        *local_e0 = local_58;
        local_e0[1] = lStack_50;
        plVar5 = local_e0 + 1;
        local_e0[2] = CONCAT44(uStack_44,local_48);
      }
      uVar2 = 0xfff;
      if (param_4 < 0xfff) {
        uVar2 = (uint)param_4;
      }
      uVar2 = WinHvpRepPoolHypercall_CallViaMacro(local_d8,0x4c,uVar2,(uint *)&local_e8);
      uVar3 = local_e8 & 0xffffffff;
      lStack_50 = lStack_50 + uVar3;
      lVar4 = lVar4 + uVar3;
      *plVar5 = *plVar5 + uVar3;
      param_4 = param_4 - uVar3;
      if (local_a0 == WinHvpReleaseFallbackBuffers) {
        WinHvpReleaseFallbackBuffers(local_d8);
        local_d8 = 0;
      }
    } while (-1 < (int)uVar2);
    *param_5 = *param_5 + lVar4;
  }
LAB_1400014df:
  if (local_d8 != 0) {
    (*local_a0)();
  }
  return uVar2;
}



===== WinHvpRepPoolHypercall_CallViaMacro @ 1400016c0 =====

uint WinHvpRepPoolHypercall_CallViaMacro(longlong param_1,uint param_2,uint param_3,uint *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    uVar3 = 0;
    if (*(longlong *)(param_1 + 0x10) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x28);
    }
    if (*(longlong *)(param_1 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x18);
    }
    if (WinHvpConnected == '\0') {
      uVar3 = 0xc0351000;
    }
    else {
      uVar1 = HvlInvokeHypercall(CONCAT44(param_3,param_2) & 0xfff0000ffff |
                                 (ulonglong)(-(uint)(WinHvpNested != '\0') & 0x80000000),uVar2,uVar1
                                );
      if (param_4 != (uint *)0x0) {
        *param_4 = (uint)((ulonglong)uVar1 >> 0x20) & 0xfff;
      }
      if ((short)uVar1 != 0) {
        uVar3 = (uint)uVar1 & 0xffff | 0xc0350000;
      }
    }
  }
  else {
    uVar3 = WinHvpSlowHypercallRemote
                      (param_2,param_3,*(longlong *)(param_1 + 8),*(longlong *)(param_1 + 0x10),
                       param_4);
  }
  return uVar3;
}



===== WinHvSetPortProperty @ 1400017b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetPortProperty
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 ****local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  ushort local_38;
  undefined4 local_36;
  undefined2 local_32;
  undefined *local_30;
  byte local_28;
  undefined7 uStack_27;
  code *local_20;
  
                    /* 0x17b0  169  WinHvSetPortProperty */
  local_40 = 0;
  local_36 = 0;
  local_32 = 0;
  local_28 = 0;
  uStack_27 = 0;
  local_30 = (undefined *)0x0;
  local_38 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  local_30 = (undefined *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)local_38 * 0x80 + WinHvpNodeToHypercallLookaside);
  local_20 = WinHvpReleasePoolBuffers;
  if (local_30 == (undefined *)0x0) {
    local_28 = KeGetCurrentIrql();
    if (local_28 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      local_30 = &WinHvpFallbackBuffer2;
    }
    else {
      local_28 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      local_30 = &WinHvpFallbackBuffer;
    }
    local_20 = WinHvpReleaseFallbackBuffers;
  }
  local_50 = *(undefined8 **)(local_30 + 0x10);
  local_58 = &local_58;
  local_48 = 0;
  *local_50 = param_1;
  *(undefined4 *)(local_50 + 1) = param_2;
  *(undefined4 *)(local_50 + 2) = param_3;
  local_50[3] = param_4;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_58,0x70);
  (*local_20)(local_58);
  return uVar1;
}



===== WinHvTranslateVirtualAddress @ 140001900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvTranslateVirtualAddress
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 ****local_58;
  undefined8 *local_50;
  undefined8 *local_48;
  undefined8 local_40;
  ushort local_38;
  undefined4 local_36;
  undefined2 local_32;
  undefined *local_30;
  byte local_28;
  undefined7 uStack_27;
  code *local_20;
  
                    /* 0x1900  184  WinHvTranslateVirtualAddress */
  local_40 = 0;
  local_36 = 0;
  local_32 = 0;
  local_28 = 0;
  uStack_27 = 0;
  local_30 = (undefined *)0x0;
  local_38 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  local_30 = (undefined *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)local_38 * 0x80 + WinHvpNodeToHypercallLookaside);
  local_20 = WinHvpReleasePoolBuffers;
  if (local_30 == (undefined *)0x0) {
    local_28 = KeGetCurrentIrql();
    if (local_28 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      local_30 = &WinHvpFallbackBuffer2;
    }
    else {
      local_28 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      local_30 = &WinHvpFallbackBuffer;
    }
    local_20 = WinHvpReleaseFallbackBuffers;
  }
  local_50 = *(undefined8 **)(local_30 + 0x10);
  puVar1 = *(undefined8 **)(local_30 + 0x20);
  local_58 = &local_58;
  *local_50 = param_1;
  *(undefined4 *)(local_50 + 1) = param_2;
  local_50[2] = param_3;
  local_50[3] = param_4;
  local_48 = puVar1;
  uVar6 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_58,0xac);
  if (-1 < (int)uVar6) {
    uVar5 = puVar1[1];
    *param_5 = *puVar1;
    param_5[1] = uVar5;
    uVar5 = puVar1[3];
    param_5[2] = puVar1[2];
    param_5[3] = uVar5;
    uVar2 = *(undefined4 *)((longlong)puVar1 + 0x24);
    uVar3 = *(undefined4 *)(puVar1 + 5);
    uVar4 = *(undefined4 *)((longlong)puVar1 + 0x2c);
    *(undefined4 *)(param_5 + 4) = *(undefined4 *)(puVar1 + 4);
    *(undefined4 *)((longlong)param_5 + 0x24) = uVar2;
    *(undefined4 *)(param_5 + 5) = uVar3;
    *(undefined4 *)((longlong)param_5 + 0x2c) = uVar4;
    *param_6 = puVar1[6];
  }
  (*local_20)(local_58);
  return uVar6;
}



===== WinHvpRangeRepHypercall @ 140001a84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpRangeRepHypercall
               (uint param_1,ulonglong param_2,void *param_3,uint param_4,longlong *param_5,
               longlong param_6,longlong *param_7,longlong *param_8)

{
  longlong lVar1;
  void *_Dst;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *plVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong _Size;
  uint local_res10 [2];
  void *local_res18;
  uint local_res20;
  void *local_98;
  uint local_90;
  uint uStack_8c;
  longlong local_88 [9];
  
  local_res18 = param_3;
  local_res20 = param_4;
  memset(local_88,0,0x40);
  plVar4 = (longlong *)0x0;
  uVar8 = 0;
  local_98 = (void *)0x0;
  uVar6 = 0;
  *param_8 = 0;
  local_res10[0] = 0;
  if (param_7 == (longlong *)0x0) {
    plVar5 = local_88;
  }
  else {
    plVar5 = param_7;
    if (*param_7 != 0) {
      _Dst = (void *)param_7[1];
      local_98 = _Dst;
      memmove(_Dst,local_res18,(ulonglong)local_res20);
      param_3 = local_res18;
      if (param_5 != (longlong *)0x0) {
        plVar4 = (longlong *)(((longlong)_Dst - (longlong)local_res18) + (longlong)param_5);
      }
    }
  }
  _Size = (ulonglong)local_res20;
  do {
    if (param_2 == 0) break;
    if (*plVar5 == 0) {
      WinHvpSetupHypercall(&local_98,(undefined8 *)0x0,(longlong)plVar5);
      memmove(local_98,param_3,_Size);
      if (param_5 != (longlong *)0x0) {
        plVar4 = (longlong *)(((longlong)local_98 - (longlong)param_3) + (longlong)param_5);
      }
    }
    uVar2 = 0;
    lVar1 = *plVar5;
    uVar6 = 0xfff;
    if (param_2 < 0xfff) {
      uVar6 = (uint)param_2;
    }
    if (*(char *)(lVar1 + 0x18) == '\0') {
      if (*(longlong *)(lVar1 + 0x10) == 0) {
        uVar7 = uVar2;
      }
      else {
        uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 0x28) + 0x28);
      }
      if (*(longlong *)(lVar1 + 8) != 0) {
        uVar2 = *(undefined8 *)(*(longlong *)(lVar1 + 0x28) + 0x18);
      }
      uStack_8c = uVar6 & 0xfff;
      local_90 = param_1 & 0xffff | -(uint)(WinHvpNested != '\0') & 0x80000000;
      if (WinHvpConnected == '\0') {
        uVar6 = 0xc0351000;
      }
      else {
        uVar2 = HvlInvokeHypercall(CONCAT44(uVar6,local_90) & 0xfffffffffff,uVar2,uVar7);
        local_res10[0] = (uint)((ulonglong)uVar2 >> 0x20) & 0xfff;
        uVar8 = local_res10[0];
        if ((short)uVar2 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = (uint)uVar2 & 0xffff | 0xc0350000;
        }
      }
    }
    else {
      uVar6 = WinHvpSlowHypercallRemote
                        (param_1,uVar6,*(longlong *)(lVar1 + 8),*(longlong *)(lVar1 + 0x10),
                         local_res10);
      uVar8 = local_res10[0];
    }
    uVar3 = (ulonglong)uVar8;
    param_2 = param_2 - uVar3;
    *param_8 = *param_8 + uVar3;
    if (param_5 != (longlong *)0x0) {
      *param_5 = *param_5 + uVar3 * param_6;
      *plVar4 = *plVar4 + uVar3 * param_6;
    }
    if ((code *)plVar5[7] == WinHvpReleaseFallbackBuffers) {
      WinHvpReleaseFallbackBuffers(*plVar5);
      *plVar5 = 0;
    }
  } while (-1 < (int)uVar6);
  if ((param_7 == (longlong *)0x0) && (*plVar5 != 0)) {
    (*(code *)plVar5[7])();
  }
  return uVar6;
}



===== WinHvAssertVirtualInterrupt @ 140001d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvAssertVirtualInterrupt
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  uint uVar1;
  undefined8 ****local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  ushort local_38;
  undefined4 local_36;
  undefined2 local_32;
  undefined *local_30;
  byte local_28;
  undefined7 uStack_27;
  code *local_20;
  
                    /* 0x1d40  13  WinHvAssertVirtualInterrupt */
  local_40 = 0;
  local_36 = 0;
  local_32 = 0;
  local_28 = 0;
  uStack_27 = 0;
  local_30 = (undefined *)0x0;
  local_38 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  local_30 = (undefined *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)local_38 * 0x80 + WinHvpNodeToHypercallLookaside);
  local_20 = WinHvpReleasePoolBuffers;
  if (local_30 == (undefined *)0x0) {
    local_28 = KeGetCurrentIrql();
    if (local_28 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      local_30 = &WinHvpFallbackBuffer2;
    }
    else {
      local_28 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      local_30 = &WinHvpFallbackBuffer;
    }
    local_20 = WinHvpReleaseFallbackBuffers;
  }
  local_50 = *(undefined8 **)(local_30 + 0x10);
  local_58 = &local_58;
  local_48 = 0;
  *(undefined2 *)((longlong)local_50 + 0x1d) = 0;
  *(undefined1 *)((longlong)local_50 + 0x1f) = 0;
  *local_50 = param_1;
  local_50[1] = param_2;
  local_50[2] = param_3;
  *(undefined4 *)(local_50 + 3) = param_4;
  *(undefined1 *)((longlong)local_50 + 0x1c) = param_5;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_58,0x94);
  (*local_20)(local_58);
  return uVar1;
}



===== WinHvUncommitGpaPages @ 140001ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvUncommitGpaPages(undefined8 param_1,longlong param_2,ulonglong param_3,longlong *param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  longlong *plVar6;
  undefined1 auStackY_f8 [32];
  uint local_c8 [2];
  undefined4 *local_c0;
  int local_b8;
  uint uStack_b4;
  longlong local_a8 [7];
  code *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
                    /* 0x1ea0  186  WinHvUncommitGpaPages */
  local_58 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_68 = param_1;
  uStack_60 = param_2;
  memset(local_a8,0,0x40);
  plVar6 = (longlong *)0x0;
  local_c0 = (undefined4 *)0x0;
  uVar5 = 0;
  local_c8[0] = 0;
  uVar4 = 0;
  *param_4 = 0;
  while (param_3 != 0) {
    if (local_a8[0] == 0) {
      WinHvpSetupHypercall(&local_c0,(undefined8 *)0x0,(longlong)local_a8);
      *local_c0 = (undefined4)local_68;
      local_c0[1] = local_68._4_4_;
      local_c0[2] = (undefined4)uStack_60;
      local_c0[3] = uStack_60._4_4_;
      plVar6 = (longlong *)(local_c0 + 2);
    }
    uVar4 = 0xfff;
    if (param_3 < 0xfff) {
      uVar4 = (uint)param_3;
    }
    if (*(char *)(local_a8[0] + 0x18) == '\0') {
      if (*(longlong *)(local_a8[0] + 0x10) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined8 *)(*(longlong *)(local_a8[0] + 0x28) + 0x28);
      }
      if (*(longlong *)(local_a8[0] + 8) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(*(longlong *)(local_a8[0] + 0x28) + 0x18);
      }
      uStack_b4 = uVar4 & 0xfff;
      local_b8 = (-(uint)(WinHvpNested != '\0') & 0x80000000) + 0xbf;
      if (WinHvpConnected == '\0') {
        uVar4 = 0xc0351000;
      }
      else {
        uVar1 = HvlInvokeHypercall(CONCAT44(uVar4,local_b8) & 0xfffffffffff,uVar3,uVar1);
        local_c8[0] = (uint)((ulonglong)uVar1 >> 0x20) & 0xfff;
        uVar5 = local_c8[0];
        if ((short)uVar1 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = (uint)uVar1 & 0xffff | 0xc0350000;
        }
      }
    }
    else {
      uVar4 = WinHvpSlowHypercallRemote
                        (0xbf,uVar4,*(longlong *)(local_a8[0] + 8),*(longlong *)(local_a8[0] + 0x10)
                         ,local_c8);
      uVar5 = local_c8[0];
    }
    uVar2 = (ulonglong)uVar5;
    *param_4 = *param_4 + uVar2;
    uStack_60 = param_2 + uVar2;
    param_3 = param_3 - uVar2;
    *plVar6 = *plVar6 + uVar2;
    if (local_70 == WinHvpReleaseFallbackBuffers) {
      WinHvpReleaseFallbackBuffers(local_a8[0]);
      local_a8[0] = 0;
    }
    if ((int)uVar4 < 0) break;
    param_2 = uStack_60;
  }
  if (local_a8[0] != 0) {
    (*local_70)();
  }
  return uVar4;
}



===== WinHvpAllocatingHypercall @ 14000209c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpAllocatingHypercall
               (ulonglong param_1,uint param_2,uint param_3,char param_4,void *param_5,
               size_t param_6,void *param_7,size_t param_8)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *local_88;
  void *local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  longlong local_68 [3];
  char local_50;
  code *local_30;
  
  iVar3 = 0;
  if (param_4 == '\0') {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = WinHvpReferencePartition(param_1);
    if (piVar2 == (int *)0x0) {
      return 0xc035000d;
    }
  }
  local_78 = (undefined8 *)(-(ulonglong)(param_7 != (void *)0x0) & (ulonglong)&local_80);
  local_70 = (undefined8 *)(-(ulonglong)(param_5 != (void *)0x0) & (ulonglong)&local_88);
  do {
    while( true ) {
      local_88 = (void *)0x0;
      local_80 = (void *)0x0;
      memset(local_68,0,0x40);
      WinHvpSetupHypercall(local_70,local_78,(longlong)local_68);
      if (param_5 != (void *)0x0) {
        memmove(local_88,param_5,param_6);
      }
      if (param_4 != '\0') {
        WinHvpAcquireAsyncMessage((longlong)piVar2);
      }
      uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_68[0],param_3);
      if ((param_7 != (void *)0x0) && (-1 < (int)uVar1)) {
        memmove(param_7,local_80,param_8);
      }
      (*local_30)();
      if ((uVar1 == 0xc0350079) && (piVar2 != (int *)0x0)) {
        uVar1 = WinHvpWaitForAsyncCall((longlong)piVar2,(undefined8 *)0x0,(undefined4 *)0x0);
      }
      if (param_4 != '\0') {
        WinHvpReleaseAsyncMessage((longlong)piVar2);
      }
      if (((uVar1 != 0xc035000b) && (uVar1 != 0xc0350075)) && (1 < uVar1 + 0x3fcaff7f)) break;
      uVar1 = WinHvpLowMemoryHandler((undefined *)param_1,param_2,uVar1,param_3,iVar3,local_50);
      if ((int)uVar1 < 0) goto LAB_1400021b9;
      iVar3 = iVar3 + 1;
    }
  } while (((uVar1 == 0xc0350073) || (uVar1 + 0x3fcaff7d < 3)) &&
          (uVar1 = WinHvLowMemoryPolicyAutoDeposit(0,0xffffffffffffffff,param_2,uVar1),
          -1 < (int)uVar1));
LAB_1400021b9:
  if (piVar2 != (int *)0x0) {
    WinHvpDereferencePartition(piVar2);
  }
  return uVar1;
}



===== WinHvpSimplePoolHypercall_CallViaMacro @ 1400022c0 =====

uint WinHvpSimplePoolHypercall_CallViaMacro(longlong param_1,uint param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar3 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    uVar3 = WinHvpSlowHypercallRemote
                      (param_2,0,*(longlong *)(param_1 + 8),*(longlong *)(param_1 + 0x10),
                       (uint *)0x0);
    return uVar3;
  }
  if (*(longlong *)(param_1 + 0x10) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x28);
  }
  if (*(longlong *)(param_1 + 8) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x18);
  }
  if (WinHvpConnected == '\0') {
    uVar3 = 0xc0351000;
  }
  else {
    uVar1 = HvlInvokeHypercall(param_2 & 0xffff | -(uint)(WinHvpNested != '\0') & 0x80000000,uVar2,
                               uVar4);
    if (uVar1 != 0) {
      uVar3 = uVar1 | 0xc0350000;
    }
  }
  return uVar3;
}



===== WinHvpSetupHypercall @ 140002370 =====

void WinHvpSetupHypercall(undefined8 *param_1,undefined8 *param_2,longlong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined *puVar5;
  longlong lVar6;
  
  uVar1 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  *(ushort *)(param_3 + 0x20) = uVar1;
  lVar6 = (ulonglong)uVar1 * 0x80 + WinHvpNodeToHypercallLookaside;
  *(undefined8 *)(param_3 + 0x28) = 0;
  puVar5 = (undefined *)ExAllocateFromNPagedLookasideList(lVar6);
  *(undefined **)(param_3 + 0x28) = puVar5;
  *(code **)(param_3 + 0x38) = WinHvpReleasePoolBuffers;
  if (puVar5 == (undefined *)0x0) {
    bVar3 = KeGetCurrentIrql();
    *(byte *)(param_3 + 0x30) = bVar3;
    if (bVar3 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      puVar5 = &WinHvpFallbackBuffer2;
    }
    else {
      uVar4 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      *(undefined1 *)(param_3 + 0x30) = uVar4;
      puVar5 = &WinHvpFallbackBuffer;
    }
    *(undefined **)(param_3 + 0x28) = puVar5;
    *(code **)(param_3 + 0x38) = WinHvpReleaseFallbackBuffers;
  }
  if (param_1 == (undefined8 *)0x0) {
    *(undefined8 *)(param_3 + 8) = 0;
  }
  else {
    uVar2 = *(undefined8 *)(puVar5 + 0x10);
    *(undefined8 *)(param_3 + 8) = uVar2;
    *param_1 = uVar2;
  }
  if (param_2 == (undefined8 *)0x0) {
    *(undefined8 *)(param_3 + 0x10) = 0;
  }
  else {
    uVar2 = *(undefined8 *)(*(longlong *)(param_3 + 0x28) + 0x20);
    *(undefined8 *)(param_3 + 0x10) = uVar2;
    *param_2 = uVar2;
  }
  *(longlong *)param_3 = param_3;
  return;
}



===== WinHvpLowMemoryHandler @ 140002494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WinHvpLowMemoryHandler
              (undefined *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
              char param_6)

{
  int *piVar1;
  
  if ((param_1 == WinHvpCurrentPartitionId) || (param_1 == (undefined *)0xffffffffffffffff)) {
    param_3 = WinHvLowMemoryPolicyAutoDeposit(0,0xffffffffffffffff,param_2,param_3);
  }
  else if (param_6 == '\0') {
    piVar1 = WinHvpReferencePartition((ulonglong)param_1);
    if (piVar1 != (int *)0x0) {
      if (param_2 == 0x8000ffff) {
        param_2 = piVar1[8];
      }
      param_3 = (**(code **)(piVar1 + 10))
                          (*(undefined8 *)(piVar1 + 0xc),param_1,param_2,param_3,param_4,param_5);
      WinHvpDereferencePartition(piVar1);
    }
  }
  else {
    param_3 = WinHvpRemotePartitionLowMemoryHandler(param_1,param_2,param_3,param_4,param_5);
  }
  return param_3;
}



===== WinHvpDereferencePartition @ 140002570 =====

void WinHvpDereferencePartition(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    WinHvpDeletePartitionObject((longlong)param_1);
  }
  return;
}



===== WinHvDisconnectDoorbell @ 1400025a0 =====

void WinHvDisconnectDoorbell(undefined8 param_1,undefined4 param_2)

{
  undefined8 local_18;
  undefined4 local_10;
  undefined4 uStack_c;
  
                    /* 0x25a0  51  WinHvDisconnectDoorbell */
  _local_10 = CONCAT44(1,param_2);
  local_18 = param_1;
  WinHvpFastHypercall(0x5b,&local_18);
  return;
}



===== WinHvSignalEvent @ 1400025e0 =====

void WinHvSignalEvent(undefined4 param_1,undefined2 param_2)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x25e0  180  WinHvSignalEvent */
  local_10 = 0;
  local_18 = (ulonglong)CONCAT24(param_2,param_1);
  WinHvpFastHypercall(0x5d,&local_18);
  return;
}



===== WinHvClearVirtualInterrupt @ 140002620 =====

void WinHvClearVirtualInterrupt(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x2620  21  WinHvClearVirtualInterrupt */
  local_10 = 0;
  local_18 = param_1;
  WinHvpFastHypercall(0x56,&local_18);
  return;
}



===== WinHvDisconnectPort @ 140002650 =====

void WinHvDisconnectPort(undefined8 param_1,uint param_2)

{
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x2650  52  WinHvDisconnectPort */
  local_10 = (ulonglong)param_2;
  local_18 = param_1;
  WinHvpFastHypercall(0x5b,&local_18);
  return;
}



===== WinHvDeletePort @ 140002680 =====

void WinHvDeletePort(undefined8 param_1,uint param_2)

{
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x2680  42  WinHvDeletePort */
  local_10 = (ulonglong)param_2;
  local_18 = param_1;
  WinHvpFastHypercall(0x58,&local_18);
  return;
}



===== WinHvpNotifySchedulerOfSignalledEvent @ 1400026b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WinHvpNotifySchedulerOfSignalledEvent(ulonglong param_1,uint param_2)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  longlong lVar7;
  
  lVar7 = 0;
  iVar6 = -0x3fcafff2;
  piVar5 = WinHvpReferencePartition(param_1);
  if (piVar5 != (int *)0x0) {
    if (param_2 < (uint)piVar5[0x10]) {
      uVar3 = ExAcquireSpinLockShared(piVar5 + 0x12);
      lVar2 = *(longlong *)(*(longlong *)(piVar5 + 0xe) + (ulonglong)param_2 * 8);
      iVar6 = -0x3fcafff2;
      if (lVar2 != 0) {
        LOCK();
        *(int *)(lVar2 + 0xc) = *(int *)(lVar2 + 0xc) + 1;
        UNLOCK();
        iVar6 = 0;
        lVar7 = lVar2;
      }
      ExReleaseSpinLockShared(piVar5 + 0x12,uVar3);
    }
    LOCK();
    iVar1 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      WinHvpDeletePartitionObject((longlong)piVar5);
    }
    if (-1 < iVar6) {
      cVar4 = ExAcquireRundownProtection(lVar7 + 0xb0);
      if (cVar4 != '\0') {
        (*DAT_140015190)(1,*(undefined8 *)(lVar7 + 0xb8));
        ExReleaseRundownProtection(lVar7 + 0xb0);
      }
    }
    if (lVar7 != 0) {
      LOCK();
      piVar5 = (int *)(lVar7 + 0xc);
      iVar6 = *piVar5;
      *piVar5 = *piVar5 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        ExFreePoolWithTag(lVar7,0x57764857);
      }
    }
  }
  return;
}



===== WinHvSignalEventWithSchedulerAssist @ 1400027d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint WinHvSignalEventWithSchedulerAssist(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  char cVar7;
  ushort uVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  int iVar13;
  longlong lVar14;
  uint uVar15;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 ****local_68;
  undefined4 *local_60;
  ulonglong *local_58;
  undefined8 local_50;
  ushort local_48;
  undefined4 local_46;
  undefined2 local_42;
  undefined *local_40;
  byte local_38;
  undefined7 uStack_37;
  code *local_30;
  
                    /* 0x27d0  182  WinHvSignalEventWithSchedulerAssist */
  if (DAT_140015190 == (code *)0x0) {
    local_78 = (ulonglong)CONCAT24(param_2,param_1);
    local_70 = 0;
    uVar15 = WinHvpFastHypercall(0x5d,&local_78);
    return uVar15;
  }
  local_50 = 0;
  local_46 = 0;
  local_42 = 0;
  local_38 = 0;
  uStack_37 = 0;
  local_40 = (undefined *)0x0;
  local_48 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  local_40 = (undefined *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)local_48 * 0x80 + WinHvpNodeToHypercallLookaside);
  local_30 = WinHvpReleasePoolBuffers;
  if (local_40 == (undefined *)0x0) {
    local_38 = KeGetCurrentIrql();
    if (local_38 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      local_40 = &WinHvpFallbackBuffer2;
    }
    else {
      local_38 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      local_40 = &WinHvpFallbackBuffer;
    }
    local_30 = WinHvpReleaseFallbackBuffers;
  }
  local_60 = *(undefined4 **)(local_40 + 0x10);
  local_68 = &local_68;
  puVar2 = *(ulonglong **)(local_40 + 0x20);
  *local_60 = param_1;
  *(undefined2 *)(local_60 + 1) = param_2;
  *(undefined2 *)((longlong)local_60 + 6) = 0;
  local_58 = puVar2;
  if ((char)local_50 == '\0') {
    if (puVar2 == (ulonglong *)0x0) {
      uVar12 = 0;
    }
    else {
      uVar12 = *(undefined8 *)(local_40 + 0x28);
    }
    if (local_60 == (undefined4 *)0x0) {
      uVar11 = 0;
    }
    else {
      uVar11 = *(undefined8 *)(local_40 + 0x18);
    }
    uVar9 = 0xf3;
    if (WinHvpNested != '\0') {
      uVar9 = 0x800000f3;
    }
    if (WinHvpConnected == '\0') {
      uVar15 = 0xc0351000;
      goto LAB_1400028ec;
    }
    uVar8 = HvlInvokeHypercall(uVar9,uVar11,uVar12);
    if (uVar8 == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = uVar8 | 0xc0350000;
    }
  }
  else {
    uVar15 = WinHvpSlowHypercallRemote(0xf3,0,(longlong)local_60,(longlong)puVar2,(uint *)0x0);
  }
LAB_1400028ec:
  if ((int)uVar15 < 0) {
    (*local_30)(local_68);
  }
  else {
    uVar3 = *puVar2;
    uVar5 = puVar2[1];
    cVar7 = *(char *)((longlong)puVar2 + 0xc);
    (*local_30)(local_68);
    if (cVar7 != '\0') {
      lVar14 = 0;
      iVar13 = -0x3fcafff2;
      piVar10 = WinHvpReferencePartition(uVar3);
      if (piVar10 != (int *)0x0) {
        if ((uint)uVar5 < (uint)piVar10[0x10]) {
          uVar6 = ExAcquireSpinLockShared(piVar10 + 0x12);
          lVar4 = *(longlong *)(*(longlong *)(piVar10 + 0xe) + (ulonglong)(uint)uVar5 * 8);
          iVar13 = -0x3fcafff2;
          if (lVar4 != 0) {
            LOCK();
            *(int *)(lVar4 + 0xc) = *(int *)(lVar4 + 0xc) + 1;
            UNLOCK();
            iVar13 = 0;
            lVar14 = lVar4;
          }
          ExReleaseSpinLockShared(piVar10 + 0x12,uVar6);
        }
        LOCK();
        iVar1 = *piVar10;
        *piVar10 = *piVar10 + -1;
        UNLOCK();
        if (iVar1 == 1) {
          WinHvpDeletePartitionObject((longlong)piVar10);
        }
        if (-1 < iVar13) {
          cVar7 = ExAcquireRundownProtection(lVar14 + 0xb0);
          if (cVar7 != '\0') {
            (*DAT_140015190)(1,*(undefined8 *)(lVar14 + 0xb8));
            ExReleaseRundownProtection(lVar14 + 0xb0);
          }
        }
        if (lVar14 != 0) {
          LOCK();
          piVar10 = (int *)(lVar14 + 0xc);
          iVar13 = *piVar10;
          *piVar10 = *piVar10 + -1;
          UNLOCK();
          if (iVar13 == 1) {
            ExFreePoolWithTag(lVar14,0x57764857);
          }
        }
      }
    }
  }
  return uVar15;
}



===== WinHvpReferencePartition @ 140002b40 =====

int * WinHvpReferencePartition(ulonglong param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  bVar2 = KeGetCurrentIrql();
  if (bVar2 < 2) {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&WinHvpPartitionArrayLock,0);
  }
  piVar5 = (int *)0x0;
  if (WinHvpPartitionArray != (int *)0x0) {
    iVar4 = *WinHvpPartitionArray + -1;
    iVar1 = 0;
    while (iVar6 = iVar1, iVar6 <= iVar4) {
      uVar3 = (uint)(iVar4 + iVar6) >> 1;
      if (*(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar3 * 4 + 2) == param_1) {
        piVar5 = *(int **)(WinHvpPartitionArray + (ulonglong)uVar3 * 4 + 4);
        if (piVar5 != (int *)0x0) {
          LOCK();
          *piVar5 = *piVar5 + 1;
          UNLOCK();
        }
        break;
      }
      iVar1 = uVar3 + 1;
      if (param_1 <= *(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar3 * 4 + 2)) {
        iVar4 = uVar3 - 1;
        iVar1 = iVar6;
      }
    }
  }
  if (bVar2 < 2) {
    ExReleasePushLockSharedEx(&WinHvpPartitionArrayLock,0);
    KeLeaveCriticalRegion();
  }
  return piVar5;
}



===== WinHvpFastHypercall @ 140002c20 =====

uint WinHvpFastHypercall(uint param_1,undefined8 *param_2)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (WinHvpConnected == '\0') {
    uVar2 = 0xc0351000;
  }
  else {
    uVar1 = HvlInvokeHypercall(param_1 & 0xffff |
                               (-(uint)(WinHvpNested != '\0') & 0x80000000) + 0x10000,*param_2,
                               param_2[1]);
    if (uVar1 != 0) {
      uVar2 = uVar1 | 0xc0350000;
    }
  }
  return uVar2;
}



===== WinHvpReferenceVp @ 140002ca0 =====

undefined8 WinHvpReferenceVp(ulonglong param_1,uint param_2,longlong *param_3)

{
  longlong lVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined8 uVar8;
  int iVar9;
  
  uVar8 = 0xc035000e;
  bVar3 = KeGetCurrentIrql();
  if (bVar3 < 2) {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&WinHvpPartitionArrayLock,0);
  }
  if (WinHvpPartitionArray != (int *)0x0) {
    iVar6 = *WinHvpPartitionArray + -1;
    iVar2 = 0;
    while (iVar9 = iVar2, iVar9 <= iVar6) {
      uVar5 = (uint)(iVar6 + iVar9) >> 1;
      if (*(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar5 * 4 + 2) == param_1) {
        piVar7 = *(int **)(WinHvpPartitionArray + (ulonglong)uVar5 * 4 + 4);
        if (piVar7 != (int *)0x0) {
          LOCK();
          *piVar7 = *piVar7 + 1;
          UNLOCK();
        }
        goto LAB_140002d3f;
      }
      iVar2 = uVar5 + 1;
      if (param_1 <= *(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar5 * 4 + 2)) {
        iVar6 = uVar5 - 1;
        iVar2 = iVar9;
      }
    }
  }
  piVar7 = (int *)0x0;
LAB_140002d3f:
  if (bVar3 < 2) {
    ExReleasePushLockSharedEx(&WinHvpPartitionArrayLock,0);
    KeLeaveCriticalRegion();
  }
  if (piVar7 == (int *)0x0) {
    uVar8 = 0xc035000d;
  }
  else {
    if (param_2 < (uint)piVar7[0x10]) {
      uVar4 = ExAcquireSpinLockShared(piVar7 + 0x12);
      lVar1 = *(longlong *)(*(longlong *)(piVar7 + 0xe) + (ulonglong)param_2 * 8);
      if (lVar1 != 0) {
        LOCK();
        *(int *)(lVar1 + 0xc) = *(int *)(lVar1 + 0xc) + 1;
        UNLOCK();
        *param_3 = lVar1;
        uVar8 = 0;
      }
      ExReleaseSpinLockShared(piVar7 + 0x12,uVar4);
    }
    LOCK();
    iVar6 = *piVar7;
    *piVar7 = *piVar7 + -1;
    UNLOCK();
    if (iVar6 == 1) {
      WinHvpDeletePartitionObject((longlong)piVar7);
    }
  }
  return uVar8;
}



===== WinHvAssertDeviceInterrupt @ 140002e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140002f3c) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint WinHvAssertDeviceInterrupt(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ushort uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 ****local_48;
  undefined8 *local_40;
  undefined8 local_38;
  undefined8 local_30;
  ushort local_28;
  undefined4 local_26;
  undefined2 local_22;
  undefined *local_20;
  byte local_18;
  undefined7 uStack_17;
  code *local_10;
  
                    /* 0x2e10  12  WinHvAssertDeviceInterrupt */
  uVar7 = 0;
  local_30 = 0;
  local_26 = 0;
  local_22 = 0;
  local_18 = 0;
  uStack_17 = 0;
  local_20 = (undefined *)0x0;
  local_28 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
  local_20 = (undefined *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)local_28 * 0x80 + WinHvpNodeToHypercallLookaside);
  local_10 = WinHvpReleasePoolBuffers;
  if (local_20 == (undefined *)0x0) {
    local_18 = KeGetCurrentIrql();
    if (local_18 < 2) {
      ExAcquireFastMutex(&WinHvpFallbackMutex);
      local_20 = &WinHvpFallbackBuffer2;
    }
    else {
      local_18 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
      local_20 = &WinHvpFallbackBuffer;
    }
    local_10 = WinHvpReleaseFallbackBuffers;
  }
  local_40 = *(undefined8 **)(local_20 + 0x10);
  local_48 = &local_48;
  local_38 = 0;
  *local_40 = param_1;
  local_40[1] = param_2;
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *(undefined4 *)(local_40 + 2) = *param_3;
  *(undefined4 *)((longlong)local_40 + 0x14) = uVar1;
  *(undefined4 *)(local_40 + 3) = uVar2;
  *(undefined4 *)((longlong)local_40 + 0x1c) = uVar3;
  if ((char)local_30 == '\0') {
    if (local_40 == (undefined8 *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(undefined8 *)(local_20 + 0x18);
    }
    uVar5 = 0x80;
    if (WinHvpNested != '\0') {
      uVar5 = 0x80000080;
    }
    if (WinHvpConnected == '\0') {
      uVar7 = 0xc0351000;
    }
    else {
      uVar4 = HvlInvokeHypercall(uVar5,uVar6,0);
      if (uVar4 != 0) {
        uVar7 = uVar4 | 0xc0350000;
      }
    }
  }
  else {
    uVar7 = WinHvpSlowHypercallRemote(0x80,0,(longlong)local_40,0,(uint *)0x0);
  }
  (*local_10)(local_48);
  return uVar7;
}



===== WinHvpProcessDispatchSignal @ 140002ff0 =====

void WinHvpProcessDispatchSignal(longlong param_1)

{
  longlong *plVar1;
  
  KeSetEvent(*(undefined8 *)(param_1 + 0x90),0,0);
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x30);
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  if (*plVar1 == 0) {
    ExUnblockOnAddressPushLockEx(&DAT_140015148,0);
  }
  return;
}



===== WinHvSetVpRegisters @ 140003040 =====

void WinHvSetVpRegisters(undefined8 param_1,undefined4 param_2,undefined1 param_3,uint param_4,
                        undefined4 *param_5,undefined8 *param_6,longlong *param_7)

{
  byte bVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 *local_18;
  undefined8 *local_10;
  
                    /* 0x3040  178  WinHvSetVpRegisters */
  local_20 = 0;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    local_18 = param_5;
    local_10 = param_6;
    local_20 = (ulonglong)CONCAT14(param_3,param_2);
    local_28 = param_1;
    WinHvpSpecialListRepHypercall
              (0x51,(ulonglong)param_4,&local_28,0x10,(longlong *)0x0,0,&local_18,0x20,
               WinHvpSetVpRegisterBuilder,WinHvpSetVpRegisterAdvancer,(void *)0x0,0,(undefined *)0x0
               ,(longlong *)0x0,param_7);
  }
  else {
    WinHvpSetVpRegistersElevated(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}



===== WinHvGetVpRegisters @ 140003190 =====

void WinHvGetVpRegisters(undefined8 param_1,undefined4 param_2,undefined1 param_3,ulonglong param_4,
                        void *param_5,longlong *param_6,void *param_7)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x3190  90  WinHvGetVpRegisters */
  local_10 = (ulonglong)CONCAT14(param_3,param_2);
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0x50,param_4 & 0xffffffff,&local_18,0x10,(longlong *)0x0,0,param_5,4,(undefined *)0x0,
             (undefined *)0x0,param_7,0x10,(undefined *)0x0,(longlong *)0x0,param_6);
  return;
}



===== WinHvGetGpaPagesAccessState @ 140003230 =====

void WinHvGetGpaPagesAccessState
               (undefined8 param_1,undefined8 param_2,longlong param_3,ulonglong param_4,
               void *param_5,longlong *param_6)

{
  undefined8 local_28;
  undefined8 local_20;
  longlong local_18 [3];
  
                    /* 0x3230  67  WinHvGetGpaPagesAccessState */
  local_28 = param_1;
  local_20 = param_2;
  local_18[0] = param_3;
  WinHvpSpecialListRepHypercall
            (0xc9,param_4,&local_28,0x18,local_18,1,(void *)0x0,0,(undefined *)0x0,(undefined *)0x0,
             param_5,1,(undefined *)0x0,(longlong *)0x0,param_6);
  return;
}



===== WinHvpSpecialListRepHypercall @ 1400032c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpSpecialListRepHypercall
               (undefined4 param_1,ulonglong param_2,void *param_3,uint param_4,longlong *param_5,
               longlong param_6,void *param_7,uint param_8,undefined *param_9,undefined *param_10,
               void *param_11,uint param_12,undefined *param_13,longlong *param_14,
               longlong *param_15)

{
  void *_Dst;
  ushort uVar1;
  longlong lVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  longlong *plVar10;
  int iVar11;
  ulonglong uVar12;
  uint uVar13;
  void *_Dst_00;
  uint local_88 [2];
  void *local_80;
  longlong local_78 [8];
  
  memset(local_78,0,0x40);
  *param_15 = 0;
  if (param_2 == 0) {
    return (WinHvpConnected != '\0') + 0xc0350002;
  }
  if (param_8 == 0) {
    uVar5 = 0xfff;
  }
  else {
    uVar5 = (0x1000 - param_4) / param_8;
  }
  if (param_12 == 0) {
    uVar13 = 0xfff;
  }
  else {
    uVar13 = (uint)(0x1000 / (ulonglong)param_12);
  }
  if (uVar5 < uVar13) {
    if (param_8 != 0) {
      uVar5 = (0x1000 - param_4) / param_8;
      goto LAB_140003379;
    }
  }
  else if (param_12 != 0) {
    uVar5 = (uint)(0x1000 / (ulonglong)param_12);
    goto LAB_140003379;
  }
  uVar5 = 0xfff;
LAB_140003379:
  local_80 = (void *)0x0;
  plVar10 = local_78;
  if (param_14 != (longlong *)0x0) {
    plVar10 = param_14;
  }
  _Dst_00 = (void *)0x0;
  KeGetCurrentIrql();
  while( true ) {
    if (*plVar10 == 0) {
      uVar1 = *(ushort *)(WinHvpProcessorToNode + (ulonglong)SystemReserved1[0x12]._4_4_ * 2);
      *(ushort *)(plVar10 + 4) = uVar1;
      plVar10[5] = 0;
      puVar6 = (undefined *)
               ExAllocateFromNPagedLookasideList
                         ((ulonglong)uVar1 * 0x80 + WinHvpNodeToHypercallLookaside);
      plVar10[5] = (longlong)puVar6;
      plVar10[7] = (longlong)WinHvpReleasePoolBuffers;
      if (puVar6 == (undefined *)0x0) {
        bVar3 = KeGetCurrentIrql();
        *(byte *)(plVar10 + 6) = bVar3;
        if (bVar3 < 2) {
          ExAcquireFastMutex(&WinHvpFallbackMutex);
          puVar6 = &WinHvpFallbackBuffer2;
        }
        else {
          uVar4 = KeAcquireSpinLockRaiseToDpc(&WinHvpFallbackSpinLock);
          *(undefined1 *)(plVar10 + 6) = uVar4;
          puVar6 = &WinHvpFallbackBuffer;
        }
        plVar10[5] = (longlong)puVar6;
        plVar10[7] = (longlong)WinHvpReleaseFallbackBuffers;
      }
      _Dst_00 = *(void **)(puVar6 + 0x10);
      plVar10[1] = (longlong)_Dst_00;
      local_80 = *(void **)(puVar6 + 0x20);
      plVar10[2] = (longlong)local_80;
      *plVar10 = (longlong)plVar10;
    }
    local_88[0] = 0;
    uVar12 = 0;
    uVar7 = 0xffffffff;
    if (param_2 < 0xffffffff) {
      uVar7 = param_2;
    }
    if (uVar5 < (uint)uVar7) {
      uVar13 = uVar5;
    }
    else {
      uVar13 = 0xffffffff;
      if (param_2 < 0xffffffff) {
        uVar13 = (uint)param_2;
      }
    }
    if (param_4 != 0) {
      memmove(_Dst_00,param_3,(ulonglong)param_4);
    }
    if (param_8 != 0) {
      _Dst = (void *)((longlong)_Dst_00 + (ulonglong)param_4);
      if (param_9 == (undefined *)0x0) {
        memmove(_Dst,param_7,(ulonglong)(uVar13 * param_8));
      }
      else {
        (*(code *)param_9)(_Dst,param_7);
      }
    }
    lVar2 = *plVar10;
    if (*(char *)(lVar2 + 0x18) == '\0') {
      if (*(longlong *)(lVar2 + 0x10) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x28);
      }
      if (*(longlong *)(lVar2 + 8) == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x18);
      }
      if (WinHvpConnected == '\0') {
        uVar13 = 0xc0351000;
      }
      else {
        uVar8 = HvlInvokeHypercall(CONCAT44(uVar13,param_1) & 0xfff0000ffff |
                                   (ulonglong)(-(uint)(WinHvpNested != '\0') & 0x80000000),uVar9,
                                   uVar8);
        uVar12 = (ulonglong)((uint)((ulonglong)uVar8 >> 0x20) & 0xfff);
        if ((short)uVar8 == 0) {
          uVar13 = 0;
        }
        else {
          uVar13 = (uint)uVar8 & 0xffff | 0xc0350000;
        }
      }
    }
    else {
      uVar13 = WinHvpSlowHypercallRemote
                         (param_1,uVar13,*(longlong *)(lVar2 + 8),*(longlong *)(lVar2 + 0x10),
                          local_88);
      uVar12 = (ulonglong)local_88[0];
    }
    iVar11 = (int)uVar12;
    *param_15 = *param_15 + uVar12;
    if (param_2 < uVar12) {
      uVar13 = 0x80000005;
    }
    if ((param_12 != 0) && (iVar11 != 0)) {
      if (param_13 == (undefined *)0x0) {
        memmove(param_11,local_80,(ulonglong)(iVar11 * param_12));
      }
      else {
        (*(code *)param_13)(local_80,param_11);
      }
    }
    if ((code *)plVar10[7] == WinHvpReleaseFallbackBuffers) {
      WinHvpReleaseFallbackBuffers(*plVar10);
      *plVar10 = 0;
    }
    param_2 = param_2 - uVar12;
    if ((uVar13 != 0) || (param_2 == 0)) break;
    if (iVar11 != 0) {
      if (param_8 != 0) {
        if (param_10 == (undefined *)0x0) {
          param_7 = (void *)((longlong)param_7 + (ulonglong)(iVar11 * param_8));
        }
        else {
          param_7 = (void *)(*(code *)param_10)(param_7,uVar12);
        }
      }
      if ((param_12 != 0) && (param_11 != (void *)0x0)) {
        param_11 = (void *)((longlong)param_11 + (ulonglong)(iVar11 * param_12));
      }
      if (param_5 != (longlong *)0x0) {
        *param_5 = *param_5 + uVar12 * param_6;
      }
    }
  }
  if ((param_14 == (longlong *)0x0) && (*plVar10 != 0)) {
    (*(code *)plVar10[7])();
  }
  return uVar13;
}



===== WinHvpHypercall @ 140003810 =====

uint WinHvpHypercall(ushort param_1,uint param_2,undefined8 param_3,undefined8 param_4,uint *param_5
                    )

{
  uint uVar1;
  undefined8 uVar2;
  
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0351000;
  }
  else {
    uVar2 = HvlInvokeHypercall((ulonglong)(param_2 & 0xfff) << 0x20 | (ulonglong)param_1 |
                               (ulonglong)(-(uint)(WinHvpNested != '\0') & 0x80000000),param_3,
                               param_4);
    if (param_5 != (uint *)0x0) {
      *param_5 = (uint)((ulonglong)uVar2 >> 0x20) & 0xfff;
    }
    if ((short)uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (uint)uVar2 & 0xffff | 0xc0350000;
    }
  }
  return uVar1;
}



===== WinHvGetNextQueuedPort @ 1400038a0 =====

int WinHvGetNextQueuedPort(uint param_1)

{
  int iVar1;
  undefined1 *puVar2;
  byte bVar3;
  ulonglong uVar4;
  byte bVar5;
  byte *pbVar6;
  ulonglong local_18 [2];
  
                    /* 0x38a0  76  WinHvGetNextQueuedPort */
  if (WinHvpConnected == '\0') {
LAB_14000395c:
    iVar1 = 0;
  }
  else {
    puVar2 = (undefined1 *)
             ((ulonglong)param_1 * 0x100 +
             *(longlong *)(WinHvpVpDataPages + 0x20 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0x30)
             );
    pbVar6 = (byte *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x40 + WinHvpEventRingControl +
                     (ulonglong)param_1);
    bVar3 = *pbVar6;
    uVar4 = (ulonglong)bVar3;
    iVar1 = *(int *)(puVar2 + uVar4 * 4 + 4);
    if (iVar1 == 0) {
      if (puVar2[1] == '\0') {
LAB_14000394e:
        *puVar2 = 0;
        LOCK();
        UNLOCK();
        iVar1 = *(int *)(puVar2 + uVar4 * 4 + 4);
        if (iVar1 == 0) goto LAB_14000395c;
      }
      else {
        local_18[0] = (ulonglong)param_1;
        puVar2[1] = 0;
        local_18[1] = 0;
        WinHvpFastHypercall(0x8b,local_18);
        iVar1 = *(int *)(puVar2 + uVar4 * 4 + 4);
        if (iVar1 == 0) goto LAB_14000394e;
      }
      *puVar2 = 1;
    }
    bVar3 = bVar3 + 1;
    *(undefined4 *)(puVar2 + uVar4 * 4 + 4) = 0;
    bVar5 = 0;
    if (bVar3 != 0x3f) {
      bVar5 = bVar3;
    }
    *pbVar6 = bVar5;
  }
  return iVar1;
}



===== WinHvpHypercallRoutine @ 1400039a0 =====

uint WinHvpHypercallRoutine(void)

{
  uint uVar1;
  undefined8 uVar2;
  uint *in_R9;
  
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0351000;
  }
  else {
    uVar2 = HvlInvokeHypercall();
    if (in_R9 != (uint *)0x0) {
      *in_R9 = (uint)((ulonglong)uVar2 >> 0x20) & 0xfff;
    }
    if ((short)uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (uint)uVar2 & 0xffff | 0xc0350000;
    }
  }
  return uVar1;
}



===== WinHvpThrottleVpDispatchThreadNoCheck @ 140003a00 =====

void WinHvpThrottleVpDispatchThreadNoCheck(longlong param_1)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  
  local_res8 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x58);
  uVar2 = KeQueryInterruptTimePrecise(&local_res8);
  *(longlong *)(param_1 + 0x50) = (longlong)DAT_140015140 + *(longlong *)(param_1 + 0x40);
  if (uVar2 < *(ulonglong *)(param_1 + 0x50)) {
    LOCK();
    *(int *)(param_1 + -4) = *(int *)(param_1 + -4) + 1;
    UNLOCK();
    ExSetTimer(*(undefined8 *)(param_1 + 0x30),-(*(longlong *)(param_1 + 0x50) - uVar2),0,0);
    KeSetActualBasePriorityThread(*(undefined8 *)(param_1 + 0x28),1);
  }
  else {
    *(undefined8 *)(param_1 + 0x50) = 0xffffffffffffffff;
  }
  KeReleaseSpinLock(param_1 + 0x58,uVar1);
  return;
}



===== WinHvpVpDispatchDeadlineTimerCallback @ 140003ad0 =====

void WinHvpVpDispatchDeadlineTimerCallback(undefined8 param_1,longlong param_2)

{
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x58);
  if (*(longlong *)(param_2 + 0x28) != 0) {
    KeSetActualBasePriorityThread(*(longlong *)(param_2 + 0x28),0xf);
  }
  *(undefined8 *)(param_2 + 0x50) = 0xffffffffffffffff;
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x58);
  WinHvpDereferenceVp(param_2 + -0x10);
  return;
}



===== WinHvpDereferenceVp @ 140003b40 =====

void WinHvpDereferenceVp(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0x57764857);
  }
  return;
}



===== WinHvpReleasePoolBuffers @ 140003b80 =====

void WinHvpReleasePoolBuffers(longlong param_1)

{
  ExFreeToNPagedLookasideList
            ((ulonglong)*(ushort *)(param_1 + 0x20) * 0x80 + WinHvpNodeToHypercallLookaside,
             *(undefined8 *)(param_1 + 0x28));
  return;
}



===== WinHvLookupPortId @ 140003bb0 =====

undefined8 WinHvLookupPortId(uint param_1,undefined8 *param_2)

{
  uint uVar1;
  
                    /* 0x3bb0  102  WinHvLookupPortId */
  uVar1 = param_1 & 0xffffff;
  if ((uVar1 == 0) || ((WinHvpPortTableCapacity & 0xffffff) < uVar1)) {
    return 0xc0000001;
  }
  *param_2 = *(undefined8 *)(WinHvpPortTable + (ulonglong)(uVar1 - 1) * 0x10);
  return 0;
}



===== WinHvpGetMsrNameFromRegisterName @ 140003bec =====

int WinHvpGetMsrNameFromRegisterName(int param_1,undefined1 *param_2)

{
  *param_2 = 0;
  if (param_1 < 0xa0012) {
    if (param_1 != 0xa0011) {
      if (param_1 < 0xa0005) {
        if (param_1 != 0xa0004) {
          if (param_1 < 0x90023) {
            if (param_1 == 0x90022) {
              return 0x400000e2;
            }
            if (param_1 == 0x240) {
              return 0x40000022;
            }
            if (param_1 == 0x90002) {
              return 0x40000000;
            }
            if (param_1 == 0x90003) {
              return 0x40000002;
            }
            if (param_1 == 0x90004) {
              return 0x40000020;
            }
            if (param_1 == 0x90019) {
              return -0x3ffefed0;
            }
            return 0x400000e0;
          }
          if (param_1 == 0x91003) {
            return 0x40001002;
          }
        }
LAB_140003c6f:
        return param_1 + 0x3ff60090;
      }
      if ((((param_1 < 0xa000c) || (param_1 == 0xa000c)) || (param_1 == 0xa000d)) ||
         ((param_1 == 0xa000e || (param_1 == 0xa000f)))) goto LAB_140003c6f;
    }
  }
  else {
    if (0xa1008 < param_1) {
      if (param_1 < 0xa1010) goto LAB_140003c6f;
      goto LAB_140003c36;
    }
    if ((((param_1 == 0xa1008) || (0xa1002 < param_1)) || (param_1 == 0xa1002)) ||
       ((((param_1 != 0xa0012 && (param_1 != 0xa0013)) && (param_1 != 0xa0014)) &&
        (param_1 != 0xa0015)))) goto LAB_140003c6f;
  }
  *param_2 = 1;
LAB_140003c36:
  return param_1 + 0x3ff60070;
}



===== WinHvpCheckLargeSpaPage @ 140003d64 =====

ulonglong WinHvpCheckLargeSpaPage(ulonglong param_1,ulonglong *param_2,uint param_3)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  uint uVar2;
  
  if ((param_1 & 0x30000) == 0) {
    uVar1 = *param_2 & 0xffffffffff;
    if ((*param_2 & 0x1ff) != 0) {
LAB_140003db1:
      return in_RAX & 0xffffffffffffff00;
    }
    for (uVar2 = 1; uVar2 < 0x200; uVar2 = uVar2 + 1) {
      uVar1 = uVar1 + 1;
      param_2 = (ulonglong *)((longlong)param_2 + (ulonglong)param_3);
      in_RAX = *param_2 & 0xffffffffff;
      if (in_RAX != uVar1) goto LAB_140003db1;
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== WinHvpIsHypercallFallbackBuffer @ 140003dbc =====

undefined8 WinHvpIsHypercallFallbackBuffer(longlong param_1)

{
  return CONCAT71(0x1400058,*(code **)(param_1 + 0x38) == WinHvpReleaseFallbackBuffers);
}



===== WinHvFlushEventLogBuffer @ 140003de0 =====

uint WinHvFlushEventLogBuffer(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  uint uVar2;
  
                    /* 0x3de0  58  WinHvFlushEventLogBuffer */
  uVar2 = 0;
  if (WinHvpConnected == '\0') {
    uVar2 = 0xc0351000;
  }
  else {
    uVar1 = HvlInvokeHypercall((-(uint)(WinHvpNested != '\0') & 0x80000000) + 0x10068,
                               CONCAT44(param_2,param_1),0);
    if (uVar1 != 0) {
      uVar2 = uVar1 | 0xc0350000;
    }
  }
  return uVar2;
}



===== WinHvpWithdrawMemoryConsumer @ 140003e60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpWithdrawMemoryConsumer(longlong param_1,undefined8 param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_278 [32];
  undefined8 local_258;
  short local_250;
  undefined2 local_24e;
  undefined8 local_238;
  int local_230;
  undefined4 local_22c;
  undefined8 local_228 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_278;
  memset(&local_258,0,0x230);
  for (; param_3 != 0; param_3 = param_3 - iVar2) {
    uVar3 = (ulonglong)param_3;
    local_258 = 0;
    local_24e = 0;
    if (0x40 < param_3) {
      uVar3 = 0x40;
    }
    local_238 = 0;
    iVar2 = (int)uVar3;
    local_22c = 0;
    local_230 = iVar2 << 0xc;
    local_250 = ((short)uVar3 + 6) * 8;
    if (iVar2 != 0) {
      puVar1 = local_228;
      uVar4 = uVar3;
      do {
        *puVar1 = *(undefined8 *)((param_1 - (longlong)local_228) + (longlong)puVar1);
        puVar1 = puVar1 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    MmFreePagesFromMdl(&local_258);
    param_1 = param_1 + uVar3 * 8;
  }
  return;
}



===== WinHvpSetProximityDomain @ 140003f60 =====

void WinHvpSetProximityDomain(undefined8 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  if (((WinHvpNodeCount <= (param_2 & 0x7fffffff)) ||
      (puVar1 = (undefined4 *)(WinHvpNodeInfo + (ulonglong)(param_2 & 0x7fffffff) * 0x28),
      *(char *)(puVar1 + 1) == '\0')) || (puVar1 == (undefined4 *)0x0)) {
    return;
  }
  if ((int)param_2 < 0) {
    *(undefined4 *)((longlong)param_1 + 4) = 1;
    uVar2 = 0x80000001;
  }
  else {
    uVar2 = 0x80000000;
  }
  *(undefined4 *)param_1 = *puVar1;
  *(undefined4 *)((longlong)param_1 + 4) = uVar2;
  return;
}



===== WinHvpVariableHeaderHypercall @ 140003fb8 =====

uint WinHvpVariableHeaderHypercall(uint param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (WinHvpConnected == '\0') {
    uVar2 = 0xc0351000;
  }
  else {
    uVar1 = HvlInvokeHypercall((param_2 + 7) * 0x4000 & 0x3fe0000U | param_1 & 0x3fff,param_3,
                               param_4);
    if (uVar1 != 0) {
      uVar2 = uVar1 | 0xc0350000;
    }
  }
  return uVar2;
}



===== WinHvpSetVpRegisterBuilder @ 140004030 =====

void WinHvpSetVpRegisterBuilder(undefined4 *param_1,undefined8 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  puVar2 = (undefined4 *)*param_2;
  puVar3 = (undefined8 *)param_2[1];
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *param_1 = uVar1;
    uVar4 = *puVar3;
    uVar5 = puVar3[1];
    puVar3 = puVar3 + 2;
    *(undefined8 *)(param_1 + 4) = uVar4;
    *(undefined8 *)(param_1 + 6) = uVar5;
    param_1 = param_1 + 8;
  }
  return;
}



===== WinHvpInitializeFastHypercall @ 140004064 =====

void WinHvpInitializeFastHypercall(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



===== WinHvpDepositMemoryBuilder @ 140004080 =====

void WinHvpDepositMemoryBuilder(undefined8 *param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  
  if (param_3 != 0) {
    lVar1 = param_2 - (longlong)param_1;
    do {
      *param_1 = *(undefined8 *)(lVar1 + (longlong)param_1);
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



===== WinHvNtProcessorToVpIndex @ 1400040b0 =====

undefined8 WinHvNtProcessorToVpIndex(uint param_1,undefined4 *param_2)

{
                    /* 0x40b0  126  WinHvNtProcessorToVpIndex */
  if (WinHvpMaximumProcessorCount <= param_1) {
    return 0xc0000001;
  }
  if (*(char *)(WinHvpProcessorToVpIndex + 4 + (ulonglong)param_1 * 8) == '\0') {
    return 0xc0350002;
  }
  *param_2 = *(undefined4 *)(WinHvpProcessorToVpIndex + (ulonglong)param_1 * 8);
  return 0;
}



===== WinHvpSynchronizationDpc @ 1400040f0 =====

void WinHvpSynchronizationDpc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSignalCallDpcDone(param_3);
  return;
}



===== WinHvpMapGpaPagesBuilderRoutine @ 140004110 =====

void WinHvpMapGpaPagesBuilderRoutine(ulonglong *param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (param_3 != 0) {
    lVar1 = param_2 - (longlong)param_1;
    uVar2 = (ulonglong)param_3;
    do {
      *param_1 = *(ulonglong *)(lVar1 + (longlong)param_1) & 0xffffffffff;
      param_1 = param_1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== WinHvPostMessage @ 140004150 =====

void WinHvPostMessage(undefined4 param_1,undefined4 param_2,void *param_3,ulonglong param_4)

{
                    /* 0x4150  128  WinHvPostMessage */
  WinHvPostMessage2(param_1,param_2,0,param_3,param_4);
  return;
}



===== WinHvGetSintEventFlags @ 140004170 =====

longlong WinHvGetSintEventFlags(uint param_1)

{
  longlong local_res10 [3];
  
                    /* 0x4170  82  WinHvGetSintEventFlags */
  local_res10[0] = 0;
  WinHvGetSintEventFlags2(param_1,0,local_res10);
  return local_res10[0];
}



===== WinHvSetEndOfMessage @ 1400041a0 =====

void WinHvSetEndOfMessage(void)

{
                    /* 0x41a0  156  WinHvSetEndOfMessage */
  WinHvSetEndOfMessage2(0);
  return;
}



===== WinHvGetSystemInformation @ 1400041c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetSystemInformation
               (int param_1,void *param_2,uint param_3,undefined4 *param_4,uint param_5,
               uint *param_6)

{
  uint uVar1;
  uint uVar2;
  size_t _Size;
  size_t _Size_00;
  undefined8 *local_68;
  void *local_60;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x41c0  87  WinHvGetSystemInformation */
  local_68 = (undefined8 *)0x0;
  local_60 = (void *)0x0;
  memset(local_58,0,0x40);
  uVar1 = 0;
  uVar2 = 0;
  WinHvpSetupHypercall(&local_68,&local_60,(longlong)local_58);
  *local_68 = 0;
  local_68[1] = 0;
  if (7 < param_1) {
    if (param_1 == 9) {
      *(undefined4 *)local_68 = 0x21;
      _Size = 1;
      goto LAB_1400043a8;
    }
    if (param_1 == 10) {
      *(undefined4 *)local_68 = 0x24;
      _Size = 0xc;
    }
    else if (param_1 == 0xb) {
      *(undefined4 *)local_68 = 0x23;
      _Size = 0x208;
    }
    else {
      if (param_1 == 0xc) {
        *(undefined4 *)local_68 = 0x25;
      }
      else {
        if (param_1 == 0xd) {
          *(undefined4 *)local_68 = 0x26;
          uVar1 = 4;
          _Size = 0x100;
          goto LAB_1400043a8;
        }
        if (param_1 != 0xe) {
LAB_140004351:
          uVar1 = 0xc0000003;
          goto LAB_1400043f4;
        }
        *(undefined4 *)local_68 = 0x2d;
      }
LAB_140004329:
      _Size = 8;
    }
    goto LAB_140004299;
  }
  if (param_1 == 7) {
    *(undefined4 *)local_68 = 0x1c;
    goto LAB_140004329;
  }
  if (param_1 == 0) {
    *(undefined4 *)local_68 = 5;
    _Size = 0x30;
LAB_140004299:
    uVar2 = (uint)_Size;
    if (uVar2 <= param_5) {
      if (((WinHvpCpuManagement == '\0') && (WinHvpVmManagement != '\0')) && (param_1 == 1)) {
        *param_4 = 3;
        if (param_6 != (uint *)0x0) {
          *param_6 = uVar2;
        }
        return 0;
      }
      if (param_3 != 0) {
        _Size_00 = 8;
        if (param_3 < 8) {
          _Size_00 = (ulonglong)param_3;
        }
        memmove(local_68 + 1,param_2,_Size_00);
      }
      uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x7b);
      if (-1 < (int)uVar1) {
        memmove(param_4,local_60,_Size);
      }
      goto LAB_1400043f4;
    }
  }
  else {
    if (param_1 == 1) {
      *(undefined4 *)local_68 = 0xf;
      _Size = 4;
      goto LAB_140004299;
    }
    if (param_1 == 2) {
      *(undefined4 *)local_68 = 0x10;
      _Size = 2;
      goto LAB_140004299;
    }
    if (param_1 == 3) {
      *(undefined4 *)local_68 = 0x15;
      uVar1 = 4;
      _Size = 8;
    }
    else {
      if (param_1 == 4) {
        *(undefined4 *)local_68 = 0x35;
        _Size = 0x20;
        goto LAB_140004299;
      }
      if (param_1 == 5) {
        *(undefined4 *)local_68 = 0x36;
        uVar1 = 8;
        _Size = 0x408;
      }
      else {
        if (param_1 != 6) goto LAB_140004351;
        *(undefined4 *)local_68 = 0x37;
        _Size = 0x20;
        uVar1 = 8;
      }
    }
LAB_1400043a8:
    uVar2 = (uint)_Size;
    if (uVar1 <= param_3) goto LAB_140004299;
  }
  uVar1 = 0xc0000023;
LAB_1400043f4:
  (*local_20)(local_58[0]);
  if (param_6 != (uint *)0x0) {
    *param_6 = uVar2;
  }
  return uVar1;
}



===== WinHvpOnInterception @ 140004438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WinHvpOnInterception(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (WinHvpPartitionArray != (int *)0x0) {
    iVar4 = *WinHvpPartitionArray + -1;
    iVar2 = 0;
    while (iVar5 = iVar2, iVar5 <= iVar4) {
      uVar3 = (uint)(iVar4 + iVar5) >> 1;
      if (*(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar3 * 4 + 2) ==
          *(ulonglong *)(param_1 + 8)) {
        lVar1 = *(longlong *)(WinHvpPartitionArray + (ulonglong)uVar3 * 4 + 4);
        if (lVar1 == 0) {
          return;
        }
        (**(code **)(lVar1 + 0x10))(*(undefined8 *)(lVar1 + 0x18),param_1);
        return;
      }
      iVar2 = uVar3 + 1;
      if (*(ulonglong *)(param_1 + 8) <=
          *(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar3 * 4 + 2)) {
        iVar4 = uVar3 - 1;
        iVar2 = iVar5;
      }
    }
  }
  return;
}



===== WinHvDetachDevice @ 1400044c0 =====

void WinHvDetachDevice(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x44c0  47  WinHvDetachDevice */
  local_18 = param_1;
  local_10 = param_2;
  WinHvpFastHypercall(0x83,&local_18);
  return;
}



===== WinHvpDepositMemoryAdvancer @ 1400044f0 =====

longlong WinHvpDepositMemoryAdvancer(longlong param_1,uint param_2)

{
  return param_1 + (ulonglong)param_2 * 8;
}



===== WinHvNotifyStandbyTransition @ 140004500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvNotifyStandbyTransition(undefined1 param_1,undefined1 param_2)

{
  uint uVar1;
  undefined1 *local_res18 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x4500  125  WinHvNotifyStandbyTransition */
  local_res18[0] = (undefined1 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(local_res18,(undefined8 *)0x0,(longlong)local_48);
  *local_res18[0] = param_1;
  local_res18[0][1] = param_2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x85);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvModifySparseGpaPages @ 140004580 =====

void WinHvModifySparseGpaPages
               (undefined8 param_1,uint param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x4580  121  WinHvModifySparseGpaPages */
  local_10 = (ulonglong)param_2;
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0x90,param_3,&local_18,0x10,(longlong *)0x0,0,param_4,8,WinHvpMapGpaPagesBuilderRoutine
             ,(undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_5);
  return;
}



===== WinHvpGetPartitionSchedulingProperties @ 140004600 =====

undefined8
WinHvpGetPartitionSchedulingProperties(ulonglong param_1,undefined1 *param_2,undefined1 *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = WinHvpReferencePartition(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc035000d;
  }
  else {
    *param_2 = (char)piVar1[1];
    *param_3 = *(undefined1 *)((longlong)piVar1 + 5);
    WinHvpDereferencePartition(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== WinHvpCurrentPartitionLowMemoryHandler @ 140004648 =====

void WinHvpCurrentPartitionLowMemoryHandler(int param_1,uint param_2)

{
  WinHvLowMemoryPolicyAutoDeposit(0,0xffffffffffffffff,param_2,param_1);
  return;
}



===== WinHvLowMemoryPolicyAutoDeposit @ 140004680 =====

int WinHvLowMemoryPolicyAutoDeposit(undefined8 param_1,ulonglong param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  longlong local_18 [2];
  
                    /* 0x4680  103  WinHvLowMemoryPolicyAutoDeposit */
  local_18[0] = 0;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    cVar3 = '\x01';
    if (((param_4 == -0x3fcaff7d) || (param_4 < -0x3fcaff7f)) || (-0x3fcaff7b < param_4)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    if ((0x10 < param_4 + 0x3fcaff8bU) || ((0x16001U >> (param_4 + 0x3fcaff8bU & 0x1f) & 1) == 0)) {
      cVar3 = '\0';
    }
    WinHvpDepositMemory(param_2,0x440,param_3,cVar3,cVar4,local_18);
    if ((local_18[0] != 0) ||
       (((cVar4 != '\0' && (-1 < (int)param_3)) &&
        ((WinHvpDepositMemory(param_2,0x440,param_3 | 0x80000000,cVar3,cVar4,local_18),
         local_18[0] != 0 && (iVar2 = WinHvSetPartitionProperty(param_2,0x5001e,5), -1 < iVar2))))))
    {
      return 0;
    }
  }
  return param_4;
}



===== WinHvpGetPartitionVpTable @ 140004798 =====

longlong WinHvpGetPartitionVpTable(longlong param_1)

{
  return param_1 + 0x38;
}



===== __report_gsfailure @ 1400047b0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400047bd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400047bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WinHvAcceptGpaPages @ 1400047d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvAcceptGpaPages(undefined8 param_1,uint param_2,uint param_3,uint param_4,
                        undefined4 param_5,longlong param_6,ulonglong param_7,longlong *param_8)

{
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  longlong local_18;
  ulonglong local_10;
  
                    /* 0x47d0  4  WinHvAcceptGpaPages */
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_20 = ((param_4 & 7) << 2 | param_3 & 3) << 6 | param_2 & 0x3f;
  local_1c = param_5;
  local_18 = param_6;
  local_28 = param_1;
  WinHvpRangeRepHypercall(0xd9,param_7,&local_28,0x18,&local_18,1,(longlong *)0x0,param_8);
  return;
}



===== WinHvAcquireSparseGpaPageHostAccess @ 140004880 =====

void WinHvAcquireSparseGpaPageHostAccess
               (undefined8 param_1,uint param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x4880  5  WinHvAcquireSparseGpaPageHostAccess */
  local_10 = (ulonglong)(param_2 & 7);
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0xd2,param_3,&local_18,0x10,(longlong *)0x0,0,param_4,8,(undefined *)0x0,
             (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_5);
  return;
}



===== WinHvAcquireSparseSpaPageHostAccess @ 140004910 =====

void WinHvAcquireSparseSpaPageHostAccess
               (byte param_1,undefined4 param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  uint local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x4910  6  WinHvAcquireSparseSpaPageHostAccess */
  local_18 = param_1 & 3;
  local_10 = 0;
  local_14 = param_2;
  WinHvpSpecialListRepHypercall
            (0xd7,param_3,&local_18,0x10,(longlong *)0x0,0,param_4,8,(undefined *)0x0,
             (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_5);
  return;
}



===== WinHvCheckSparseGpaPageVtlAccess @ 1400049b0 =====

void WinHvCheckSparseGpaPageVtlAccess
               (undefined8 param_1,undefined1 param_2,undefined1 param_3,ulonglong param_4,
               void *param_5,void *param_6,longlong *param_7)

{
  undefined8 local_18;
  ulonglong uStack_10;
  
                    /* 0x49b0  20  WinHvCheckSparseGpaPageVtlAccess */
  uStack_10 = (ulonglong)CONCAT11(param_3,param_2) & 0xffffffffffffff0f | 0x10;
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0xd4,param_4,&local_18,0x10,(longlong *)0x0,0,param_5,8,(undefined *)0x0,
             (undefined *)0x0,param_6,8,(undefined *)0x0,(longlong *)0x0,param_7);
  return;
}



===== WinHvFlushCache @ 140004a50 =====

void WinHvFlushCache(void)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x4a50  57  WinHvFlushCache */
  local_18 = 0;
  local_10 = 0;
  WinHvpFastHypercall(0x1d,&local_18);
  return;
}



===== WinHvGetGpaRangesAccessState @ 140004a80 =====

void WinHvGetGpaRangesAccessState
               (undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 param_4,
               ulonglong param_5,void *param_6,longlong *param_7)

{
  undefined8 local_28;
  undefined8 local_20;
  longlong local_18;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0x4a80  68  WinHvGetGpaRangesAccessState */
  local_c = 0;
  local_28 = param_1;
  local_20 = param_2;
  local_18 = param_3;
  local_10 = param_4;
  WinHvpSpecialListRepHypercall
            (0x102,param_5,&local_28,0x20,&local_18,1L << ((char)param_4 * '\t' & 0x3fU),(void *)0x0
             ,0,(undefined *)0x0,(undefined *)0x0,param_6,1,(undefined *)0x0,(longlong *)0x0,param_7
            );
  return;
}



===== WinHvGetSparseGpaPagesAccessState @ 140004b20 =====

void WinHvGetSparseGpaPagesAccessState
               (undefined8 param_1,undefined8 param_2,ulonglong param_3,void *param_4,void *param_5,
               longlong *param_6)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x4b20  86  WinHvGetSparseGpaPagesAccessState */
  local_18 = param_1;
  local_10 = param_2;
  WinHvpSpecialListRepHypercall
            (0xca,param_3,&local_18,0x10,(longlong *)0x0,0,param_4,8,(undefined *)0x0,
             (undefined *)0x0,param_5,1,(undefined *)0x0,(longlong *)0x0,param_6);
  return;
}



===== WinHvMapGpaPagesFromMbpArrayBuilderRoutine @ 140004ba0 =====

void WinHvMapGpaPagesFromMbpArrayBuilderRoutine(ulonglong *param_1,ulonglong *param_2,uint param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (param_3 != 0) {
    uVar2 = (ulonglong)param_3;
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 2;
      *param_1 = uVar1 & 0xffffffffff;
      param_1 = param_1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== WinHvModifySparseGpaPageHostVisibility @ 140004be0 =====

void WinHvModifySparseGpaPageHostVisibility
               (undefined8 param_1,uint param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x4be0  120  WinHvModifySparseGpaPageHostVisibility */
  local_10 = (ulonglong)(param_2 & 3);
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0xdb,param_3,&local_18,0x10,(longlong *)0x0,0,param_4,8,(undefined *)0x0,
             (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_5);
  return;
}



===== WinHvModifySparseGpaPagesFromMbpArray @ 140004c70 =====

void WinHvModifySparseGpaPagesFromMbpArray
               (undefined8 param_1,uint param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x4c70  122  WinHvModifySparseGpaPagesFromMbpArray */
  local_10 = (ulonglong)param_2;
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0x90,param_3,&local_18,0x10,(longlong *)0x0,0,param_4,0x10,
             WinHvMapGpaPagesFromMbpArrayBuilderRoutine,(undefined *)0x0,(void *)0x0,0,
             (undefined *)0x0,(longlong *)0x0,param_5);
  return;
}



===== WinHvModifyVtlProtectionMask @ 140004cf0 =====

void WinHvModifyVtlProtectionMask
               (undefined *param_1,undefined4 param_2,ulonglong param_3,void *param_4,byte param_5,
               longlong *param_6)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong local_res8;
  undefined *local_38;
  undefined4 local_30;
  uint local_2c;
  
                    /* 0x4cf0  123  WinHvModifyVtlProtectionMask */
  local_res8 = 0;
  *param_6 = 0;
  local_2c = (uint)(param_5 & 0xf | 0x10);
  iVar4 = 0;
  local_38 = param_1;
  local_30 = param_2;
  while( true ) {
    uVar2 = WinHvpSpecialListRepHypercall
                      (0xc,param_3,&local_38,0x10,(longlong *)0x0,0,param_4,8,(undefined *)0x0,
                       (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,&local_res8);
    lVar1 = local_res8;
    *param_6 = *param_6 + local_res8;
    if (((uVar2 != 0xc0350075) && (uVar2 != 0xc035000b)) && (1 < uVar2 + 0x3fcaff7f)) break;
    iVar3 = WinHvpLowMemoryHandler(param_1,0x8000ffff,uVar2,0xc,iVar4,'\0');
    if (iVar3 < 0) {
      return;
    }
    param_3 = param_3 - lVar1;
    param_4 = (void *)((longlong)param_4 + lVar1 * 8);
    iVar4 = iVar4 + 1;
  }
  return;
}



===== WinHvModifyVtlProtectionMaskRange @ 140004e20 =====

void WinHvModifyVtlProtectionMaskRange
               (undefined8 param_1,longlong param_2,ulonglong param_3,undefined2 param_4,
               void *param_5,longlong *param_6)

{
  undefined8 local_28;
  longlong local_20;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  
                    /* 0x4e20  124  WinHvModifyVtlProtectionMaskRange */
  local_16 = 0;
  local_12 = 0;
  local_28 = param_1;
  local_20 = param_2;
  local_18 = param_4;
  WinHvpSpecialListRepHypercall
            (0xcd,param_3,&local_28,0x18,&local_20,1,param_5,4,(undefined *)0x0,(undefined *)0x0,
             (void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_6);
  return;
}



===== WinHvQueryVtlProtectionMaskRange @ 140004ec0 =====

void WinHvQueryVtlProtectionMaskRange
               (undefined8 param_1,longlong param_2,ulonglong param_3,undefined2 param_4,
               void *param_5,longlong *param_6)

{
  undefined8 local_28;
  longlong local_20;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  
                    /* 0x4ec0  138  WinHvQueryVtlProtectionMaskRange */
  local_16 = 0;
  local_12 = 0;
  local_28 = param_1;
  local_20 = param_2;
  local_18 = param_4;
  WinHvpSpecialListRepHypercall
            (0xcc,param_3,&local_28,0x18,&local_20,1,(void *)0x0,0,(undefined *)0x0,(undefined *)0x0
             ,param_5,4,(undefined *)0x0,(longlong *)0x0,param_6);
  return;
}



===== WinHvReadGpa @ 140004f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvReadGpa(undefined8 param_1,undefined4 param_2,undefined8 param_3,uint param_4,
                 undefined8 param_5,undefined8 *param_6,void *param_7)

{
  uint uVar1;
  undefined8 *local_58;
  undefined8 *local_50;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x4f60  139  WinHvReadGpa */
  local_58 = (undefined8 *)0x0;
  local_50 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  if (param_4 < 0x11) {
    WinHvpSetupHypercall(&local_58,&local_50,(longlong)local_48);
    *local_58 = param_1;
    *(undefined4 *)(local_58 + 1) = param_2;
    *(uint *)((longlong)local_58 + 0xc) = param_4;
    local_58[2] = param_3;
    local_58[3] = param_5;
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x53);
    if (-1 < (int)uVar1) {
      *param_6 = *local_50;
      memmove(param_7,local_50 + 1,(ulonglong)param_4);
    }
    (*local_10)(local_48[0]);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WinHvReleaseSparseGpaPageHostAccess @ 140005040 =====

void WinHvReleaseSparseGpaPageHostAccess
               (undefined8 param_1,uint param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x5040  142  WinHvReleaseSparseGpaPageHostAccess */
  local_10 = (ulonglong)(param_2 & 7);
  local_18 = param_1;
  WinHvpSpecialListRepHypercall
            (0xd3,param_3,&local_18,0x10,(longlong *)0x0,0,param_4,8,(undefined *)0x0,
             (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_5);
  return;
}



===== WinHvReleaseSparseSpaPageHostAccess @ 1400050d0 =====

void WinHvReleaseSparseSpaPageHostAccess
               (undefined8 param_1,uint param_2,undefined4 param_3,ulonglong param_4,void *param_5,
               longlong *param_6)

{
  uint local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x50d0  143  WinHvReleaseSparseSpaPageHostAccess */
  local_18 = param_2 & 3;
  local_14 = param_3;
  local_10 = param_1;
  WinHvpSpecialListRepHypercall
            (0xd8,param_4,&local_18,0x10,(longlong *)0x0,0,param_5,8,(undefined *)0x0,
             (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_6);
  return;
}



===== WinHvUnacceptGpaPages @ 140005160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvUnacceptGpaPages
               (undefined8 param_1,uint param_2,undefined4 param_3,longlong param_4,
               ulonglong param_5,longlong *param_6)

{
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  longlong local_18;
  ulonglong local_10;
  
                    /* 0x5160  185  WinHvUnacceptGpaPages */
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_20 = param_2 & 7;
  local_28 = param_1;
  local_1c = param_3;
  local_18 = param_4;
  WinHvpRangeRepHypercall(0xda,param_5,&local_28,0x18,&local_18,1,(longlong *)0x0,param_6);
  return;
}



===== WinHvWriteGpa @ 1400051f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvWriteGpa(undefined8 param_1,undefined4 param_2,undefined8 param_3,uint param_4,
                  undefined8 param_5,void *param_6,undefined8 *param_7)

{
  uint uVar1;
  undefined8 *local_58;
  undefined8 *local_50;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x51f0  201  WinHvWriteGpa */
  local_58 = (undefined8 *)0x0;
  local_50 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  if (param_4 < 0x11) {
    WinHvpSetupHypercall(&local_58,&local_50,(longlong)local_48);
    *local_58 = param_1;
    *(undefined4 *)(local_58 + 1) = param_2;
    *(uint *)((longlong)local_58 + 0xc) = param_4;
    local_58[2] = param_3;
    local_58[3] = param_5;
    memmove(local_58 + 4,param_6,(ulonglong)param_4);
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x54);
    if (-1 < (int)uVar1) {
      *param_7 = *local_50;
    }
    (*local_10)(local_48[0]);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WinHvDriverReinit @ 1400052d0 =====

void WinHvDriverReinit(void)

{
  if (WinHvpQueriedNodeInfo == '\0') {
    WinHvpLoadProximityDomainInfo();
  }
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1400052f0 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000ebef < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140005318 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005470 =====

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



===== WinHvpCheckPartitionPrivileges @ 1400054f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140005519) */

undefined8 WinHvpCheckPartitionPrivileges(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if (WinHvpNested == '\0') {
    local_28 = 0;
    uStack_20 = 0;
    uVar3 = HviGetHypervisorFeatures(&local_28);
    uVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),(undefined1)local_28) & 0xffffffffffffff7e;
    bVar4 = (char)uVar2 == '~';
  }
  else {
    puVar1 = (uint *)cpuid(0x40000009);
    uVar2 = (ulonglong)*puVar1 & 0xffffffffffffff74;
    bVar4 = (char)uVar2 == 't';
  }
  return CONCAT71((int7)(uVar2 >> 8),bVar4);
}



===== WinHvpRegisterInterruptCallback @ 140005558 =====

void WinHvpRegisterInterruptCallback(void)

{
  int iVar1;
  
  iVar1 = HvlRegisterInterruptCallback(0,WinHvOnInterrupt,0);
  if (-1 < iVar1) {
    DAT_140015060 = 1;
  }
  return;
}



===== WinHvpSetHypervisorInformation @ 14000558c =====

void WinHvpSetHypervisorInformation(void)

{
  ZwSetSystemInformation(0x5b,0,0);
  return;
}



===== WinHvpAllocateHypercallBuffer @ 1400055b0 =====

longlong WinHvpAllocateHypercallBuffer(void)

{
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  bVar2 = KeGetCurrentIrql();
  if ((bVar2 < 3) && (lVar3 = ExAllocatePool2(0x40,0x30,0x42764857), lVar3 != 0)) {
    lVar4 = ExAllocatePool2(0x42,0x1000,0x4a764857);
    *(longlong *)(lVar3 + 0x10) = lVar4;
    plVar1 = (longlong *)(lVar3 + 0x20);
    if (lVar4 != 0) {
      lVar4 = ExAllocatePool2(0x42,0x1000,0x4b764857);
      *plVar1 = lVar4;
      if (lVar4 != 0) {
        uVar5 = MmGetPhysicalAddress(*(undefined8 *)(lVar3 + 0x10));
        *(undefined8 *)(lVar3 + 0x18) = uVar5;
        uVar5 = MmGetPhysicalAddress(*plVar1);
        *(undefined8 *)(lVar3 + 0x28) = uVar5;
        return lVar3;
      }
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x10),0x4a764857);
    }
    if (*plVar1 != 0) {
      ExFreePoolWithTag(*plVar1,0x4b764857);
    }
    ExFreePoolWithTag(lVar3,0x42764857);
  }
  return 0;
}



===== WinHvpFastAllocatingHypercall @ 1400056c8 =====

void WinHvpFastAllocatingHypercall(undefined *param_1,uint param_2,uint param_3,undefined8 *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    while (((uVar1 = WinHvpFastHypercall(param_3,param_4), uVar1 == 0xc0350075 ||
            (uVar1 == 0xc035000b)) || (uVar1 + 0x3fcaff7f < 2))) {
      iVar2 = WinHvpLowMemoryHandler(param_1,param_2,uVar1,param_3,iVar3,'\0');
      if (iVar2 < 0) {
        return;
      }
      iVar3 = iVar3 + 1;
    }
    if ((uVar1 != 0xc0350073) && (2 < uVar1 + 0x3fcaff7d)) break;
    iVar2 = WinHvLowMemoryPolicyAutoDeposit(0,0xffffffffffffffff,param_2,uVar1);
    if (iVar2 < 0) {
      return;
    }
  }
  return;
}



===== WinHvpFastRepHypercall @ 140005788 =====

void WinHvpFastRepHypercall(void)

{
  WinHvpHypercallRoutine();
  return;
}



===== WinHvpFreeHypercallBuffer @ 1400057f0 =====

void WinHvpFreeHypercallBuffer(longlong param_1)

{
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0x4b764857);
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0x4a764857);
  ExFreePoolWithTag(param_1,0x42764857);
  return;
}



===== WinHvpReleaseFallbackBuffers @ 140005850 =====

void WinHvpReleaseFallbackBuffers(longlong param_1)

{
  if (*(undefined **)(param_1 + 0x28) == &WinHvpFallbackBuffer2) {
    ExReleaseFastMutex(&WinHvpFallbackMutex);
  }
  else if (*(undefined **)(param_1 + 0x28) == &WinHvpFallbackBuffer) {
    KeReleaseSpinLock(&WinHvpFallbackSpinLock,CONCAT71(0x1400150,*(undefined1 *)(param_1 + 0x30)));
  }
  return;
}



===== WinHvQueryDeviceInterruptTarget @ 1400058b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvQueryDeviceInterruptTarget
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,void *param_4,
               uint *param_5,undefined8 *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  uint uVar4;
  undefined8 *local_res8;
  uint *local_res10;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x58b0  134  WinHvQueryDeviceInterruptTarget */
  local_res8 = (undefined8 *)0x0;
  local_res10 = (uint *)0x0;
  memset(local_58,0,0x40);
  WinHvpSetupHypercall(&local_res8,&local_res10,(longlong)local_58);
  *local_res8 = param_1;
  local_res8[1] = param_2;
  uVar2 = param_3[1];
  local_res8[2] = *param_3;
  local_res8[3] = uVar2;
  uVar4 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0xe0);
  puVar3 = local_res10;
  if (-1 < (int)uVar4) {
    if (param_5 != (uint *)0x0) {
      uVar1 = *local_res10;
      if ((uVar1 != 0) && (param_4 != (void *)0x0)) {
        if (*param_5 < uVar1) {
          uVar4 = 0xc0000023;
        }
        else {
          memmove(param_4,local_res10 + 2,(ulonglong)uVar1);
        }
      }
      *param_5 = *puVar3;
    }
    if (param_6 != (undefined8 *)0x0) {
      uVar2 = *(undefined8 *)(puVar3 + 0x4a);
      *param_6 = *(undefined8 *)(puVar3 + 0x48);
      param_6[1] = uVar2;
    }
  }
  (*local_20)(local_58[0]);
  return uVar4;
}



===== WinHvAllocateOverlayPages @ 1400059b0 =====

void WinHvAllocateOverlayPages(int param_1)

{
                    /* 0x59b0  8  WinHvAllocateOverlayPages */
  WinHvpAllocateOverlayPages(param_1);
  return;
}



===== WinHvFreeOverlayPages @ 1400059d0 =====

void WinHvFreeOverlayPages(undefined8 param_1)

{
                    /* 0x59d0  60  WinHvFreeOverlayPages */
  WinHvpFreeOverlayPages(param_1,'\0');
  return;
}



===== WinHvpAllocateHypervisorVisiblePages @ 1400059e8 =====

longlong WinHvpAllocateHypervisorVisiblePages(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  char in_stack_00000028;
  
  if (WinHvpConnected == '\0') {
LAB_140005abd:
    lVar1 = 0;
  }
  else {
    uVar3 = 0;
    do {
      if (3 < uVar3) {
        lVar1 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,0,param_1 << 0xc,1,0x24);
        if (lVar1 == 0) goto LAB_140005abd;
        break;
      }
      lVar1 = MmAllocatePagesForMdlEx();
      uVar3 = uVar3 + 1;
    } while (lVar1 == 0);
    lVar2 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000020);
    if ((lVar2 == 0) && (lVar1 != 0)) {
      WinHvpReclaimAndFreeHypervisorVisiblePages(lVar1,in_stack_00000028);
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== WinHvpAllocateOverlayPages @ 140005ae4 =====

undefined8 WinHvpAllocateOverlayPages(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 local_18;
  longlong local_10;
  
  uVar3 = 0;
  lVar1 = WinHvpAllocateHypervisorVisiblePages(param_1);
  if (lVar1 != 0) {
    local_18 = *(undefined8 *)(lVar1 + 0x18);
    local_10 = lVar1;
    ExAcquireFastMutex(&WinHvpOverlayTableLock);
    lVar2 = RtlInsertElementGenericTable(&WinHvpOverlayTable,&local_18,0x10,0,uVar3);
    ExReleaseFastMutex(&WinHvpOverlayTableLock);
    if (lVar2 != 0) {
      return *(undefined8 *)(lVar1 + 0x18);
    }
    WinHvpReclaimAndFreeHypervisorVisiblePages(lVar1,'\0');
  }
  return 0;
}



===== WinHvpAllocateOverlayPhysicalPage @ 140005b84 =====

undefined8 WinHvpAllocateOverlayPhysicalPage(void)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0xffffffffffffffff;
  lVar1 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,0,0x1000,1,5);
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x30);
    ExFreePoolWithTag(lVar1,0);
  }
  return uVar2;
}



===== WinHvpAllocateOverlayTableEntry @ 140005bf0 =====

void WinHvpAllocateOverlayTableEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x40,param_2,0x55764857);
  return;
}



===== WinHvpCompareOverlayTableEntry @ 140005c20 =====

int WinHvpCompareOverlayTableEntry(undefined8 param_1,ulonglong *param_2,ulonglong *param_3)

{
  if (*param_2 < *param_3) {
    return 0;
  }
  return 2 - (uint)(*param_3 < *param_2);
}



===== WinHvpFreeOverlayPages @ 140005c3c =====

void WinHvpFreeOverlayPages(undefined8 param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_18 = param_1;
  ExAcquireFastMutex(&WinHvpOverlayTableLock);
  lVar2 = RtlLookupElementGenericTable(&WinHvpOverlayTable,&local_18);
  lVar1 = *(longlong *)(lVar2 + 8);
  RtlDeleteElementGenericTable(&WinHvpOverlayTable,lVar2);
  ExReleaseFastMutex(&WinHvpOverlayTableLock);
  WinHvpReclaimAndFreeHypervisorVisiblePages(lVar1,param_2);
  return;
}



===== WinHvpFreeOverlayPhysicalPage @ 140005ccc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpFreeOverlayPhysicalPage(undefined8 param_1)

{
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_3c = 0;
  uStack_34 = 0;
  local_2c = 0;
  local_48 = 0;
  local_40 = 0x38;
  local_28 = 0;
  local_20 = 0x1000;
  local_18 = param_1;
  MmFreePagesFromMdl(&local_48);
  return;
}



===== WinHvpFreeOverlayTableEntry @ 140005d40 =====

void WinHvpFreeOverlayTableEntry(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0);
  return;
}



===== WinHvpReclaimAndFreeHypervisorVisiblePages @ 140005d64 =====

void WinHvpReclaimAndFreeHypervisorVisiblePages(longlong param_1,char param_2)

{
  if ((*(byte *)(param_1 + 10) & 1) != 0) {
    MmUnmapLockedPages(*(undefined8 *)(param_1 + 0x18),param_1);
  }
  if (param_2 != '\0') {
    *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) & 0xf7ff;
  }
  MmFreePagesFromMdl(param_1);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WinHvpValidateAndMapOverlayAddress @ 140005dd0 =====

uint WinHvpValidateAndMapOverlayAddress
               (ulonglong param_1,undefined8 param_2,char param_3,longlong *param_4)

{
  longlong lVar1;
  
  if ((param_1 & 0xfff) == 0) {
    if (param_3 == '\0') {
      if ((WinHvpSharedGpaBoundary == 0) || (param_1 < WinHvpSharedGpaBoundary)) goto LAB_140005e10;
    }
    else if (WinHvpSharedGpaBoundary <= param_1) {
LAB_140005e10:
      lVar1 = MmMapIoSpaceEx((int)param_1,0x1000,4);
      *param_4 = lVar1;
      return ~-(uint)(lVar1 != 0) & 0xc000009a;
    }
  }
  *param_4 = 0;
  return 0xc0000001;
}



===== WinHvGetPortProperty @ 140005e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetPortProperty
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 *local_58 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x5e40  81  WinHvGetPortProperty */
  local_res8 = (undefined8 *)0x0;
  local_58[0] = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,local_58,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  *(undefined4 *)(local_res8 + 2) = param_3;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x5a);
  if (-1 < (int)uVar1) {
    *param_4 = *local_58[0];
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvPostMessage2 @ 140005ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvPostMessage2(undefined4 param_1,undefined4 param_2,uint param_3,void *param_4,
                      ulonglong param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *local_68 [2];
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x5ef0  129  WinHvPostMessage2 */
  local_68[0] = (undefined4 *)0x0;
  memset(local_58,0,0x40);
  if ((((param_3 & 0xfffffffe) == 0) && ((param_3 & 1) == 0)) && (param_5 < 0xf1)) {
    WinHvpSetupHypercall(local_68,(undefined8 *)0x0,(longlong)local_58);
    puVar1 = local_68[0];
    *local_68[0] = param_1;
    local_68[0][2] = param_2;
    local_68[0][3] = (int)param_5;
    memmove(local_68[0] + 4,param_4,param_5);
    memset((void *)((longlong)puVar1 + param_5 + 0x10),0,0xf0 - param_5);
    uVar2 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x5c);
    (*local_20)(local_58[0]);
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== WinHvPostMessageDirect @ 140005fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvPostMessageDirect
               (undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x5fe0  130  WinHvPostMessageDirect */
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  lVar5 = 2;
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  *(undefined1 *)((longlong)local_res8 + 0xc) = param_3;
  *(undefined4 *)(local_res8 + 2) = param_4;
  puVar4 = (undefined8 *)((longlong)local_res8 + 0x14);
  do {
    uVar2 = param_5[1];
    *puVar4 = *param_5;
    puVar4[1] = uVar2;
    uVar2 = param_5[3];
    puVar4[2] = param_5[2];
    puVar4[3] = uVar2;
    uVar2 = param_5[5];
    puVar4[4] = param_5[4];
    puVar4[5] = uVar2;
    uVar2 = param_5[7];
    puVar4[6] = param_5[6];
    puVar4[7] = uVar2;
    uVar2 = param_5[9];
    puVar4[8] = param_5[8];
    puVar4[9] = uVar2;
    uVar2 = param_5[0xb];
    puVar4[10] = param_5[10];
    puVar4[0xb] = uVar2;
    uVar2 = param_5[0xd];
    puVar4[0xc] = param_5[0xc];
    puVar4[0xd] = uVar2;
    puVar1 = param_5 + 0xe;
    uVar2 = param_5[0xf];
    param_5 = param_5 + 0x10;
    puVar4[0xe] = *puVar1;
    puVar4[0xf] = uVar2;
    lVar5 = lVar5 + -1;
    puVar4 = puVar4 + 0x10;
  } while (lVar5 != 0);
  uVar3 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xc1);
  (*local_10)(local_48[0]);
  return uVar3;
}



===== WinHvSignalEventDirect @ 1400060e0 =====

uint WinHvSignalEventDirect
               (ulonglong param_1,uint param_2,undefined1 param_3,uint param_4,undefined2 param_5,
               char param_6)

{
  ushort uVar1;
  uint uVar2;
  ulonglong local_28;
  uint local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  char local_18 [16];
  
                    /* 0x60e0  181  WinHvSignalEventDirect */
  if (param_4 == (param_4 & 0xff)) {
    uVar2 = 0;
    local_1b = (undefined1)param_4;
    local_1a = param_5;
    local_28 = param_1;
    local_20 = param_2;
    local_1c = param_3;
    uVar1 = HvlInvokeFastExtendedHypercall(0x100c0,&local_28,0x10,local_18,8);
    if (uVar1 == 0) {
      if (((param_6 != '\0') && (local_18[0] != '\0')) && (DAT_140015190 != 0)) {
        WinHvpNotifySchedulerOfSignalledEvent(param_1,param_2);
      }
    }
    else {
      uVar2 = uVar1 | 0xc0350000;
    }
  }
  else {
    uVar2 = 0xc0350005;
  }
  return uVar2;
}



===== WinHvpAllocateSintDpcRoutine @ 1400061b0 =====

void WinHvpAllocateSintDpcRoutine(undefined8 param_1,int *param_2,undefined8 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uStack_10 = 0;
  local_18 = 0;
  local_14 = 0;
  uVar2 = KeQueryActiveProcessorCountEx(0xffff);
  RtlInitializeBitMap(&local_18,WinHvpSynicProcessorsBitmap,uVar2);
  cVar1 = RtlTestBit(&local_18,SystemReserved1[0x12]._4_4_);
  if (cVar1 != '\0') {
    WinHvpSetVpRegister64Self(*param_2,*(undefined8 *)(param_2 + 2));
  }
  KeSignalCallDpcDone(param_3);
  return;
}



===== WinHvGetSintEventFlags2 @ 140006250 =====

undefined8 WinHvGetSintEventFlags2(uint param_1,ulonglong param_2,longlong *param_3)

{
  longlong lVar1;
  
                    /* 0x6250  83  WinHvGetSintEventFlags2 */
  if (WinHvpConnected != '\0') {
    if (((param_2 & 0xfffffffe) != 0) || ((param_2 & 1) != 0)) {
      return 0xc0350005;
    }
    lVar1 = *(longlong *)(WinHvpVpDataPages + 0x10 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0x30);
    if (lVar1 != 0) {
      *param_3 = (ulonglong)param_1 * 0x100 + lVar1;
      return 0;
    }
  }
  return 0xc0350002;
}



===== WinHvGetSintMessage @ 1400062b0 =====

longlong WinHvGetSintMessage(uint param_1)

{
  longlong local_res10 [3];
  
                    /* 0x62b0  84  WinHvGetSintMessage */
  local_res10[0] = 0;
  WinHvGetSintMessage2(param_1,0,local_res10);
  return local_res10[0];
}



===== WinHvGetSintMessage2 @ 1400062e0 =====

undefined8 WinHvGetSintMessage2(uint param_1,ulonglong param_2,longlong *param_3)

{
  longlong lVar1;
  
                    /* 0x62e0  85  WinHvGetSintMessage2 */
  if (WinHvpConnected != '\0') {
    if (((param_2 & 0xfffffffe) != 0) || ((param_2 & 1) != 0)) {
      return 0xc0350005;
    }
    lVar1 = *(longlong *)(WinHvpVpDataPages + (ulonglong)SystemReserved1[0x12]._4_4_ * 0x30);
    if (lVar1 != 0) {
      *param_3 = (ulonglong)param_1 * 0x100 + lVar1;
      return 0;
    }
  }
  return 0xc0350002;
}



===== WinHvSetEndOfMessage2 @ 140006340 =====

ulonglong WinHvSetEndOfMessage2(uint param_1)

{
  ulonglong uVar1;
  
                    /* 0x6340  157  WinHvSetEndOfMessage2 */
  if ((param_1 & 0xfffffffe) == 0) {
    if (WinHvpConnected == '\0') {
      uVar1 = 0xc0350002;
    }
    else {
      uVar1 = WinHvpSetVpRegister64Self2
                        ((-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0014,0,(byte)param_1 & 1);
    }
  }
  else {
    uVar1 = 0xc0350005;
  }
  return uVar1;
}



===== WinHvSetSint @ 1400063a0 =====

void WinHvSetSint(uint param_1,uint param_2,char param_3,char param_4,ulonglong *param_5)

{
  uint uVar1;
  
                    /* 0x63a0  172  WinHvSetSint */
  uVar1 = param_3 != '\0' | 2;
  if (param_4 == '\0') {
    uVar1 = (uint)(param_3 != '\0');
  }
  WinHvSetSint2(param_1,param_2,param_5,uVar1);
  return;
}



===== WinHvSetSint2 @ 1400063e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WinHvSetSint2(uint param_1,uint param_2,ulonglong *param_3,uint param_4)

{
  bool bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined1 auStack_78 [40];
  longlong local_50;
  ulonglong uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
                    /* 0x63e0  173  WinHvSetSint2 */
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  uStack_38 = 0;
  uVar2 = KeQueryGroupAffinity((short)param_3[1]);
  uVar2 = uVar2 & *param_3;
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar5 = &local_40;
    bVar1 = false;
    uVar4 = 0;
    if (uVar2 != 0) {
      for (; (uVar2 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
      }
    }
    local_50 = 0;
    uStack_48 = (ulonglong)(ushort)param_3[1];
    if (uVar2 != 0) {
      bVar1 = true;
      do {
        uVar2 = uVar2 & ~(1L << (uVar4 & 0x3f));
        local_50 = 1L << ((byte)uVar4 & 0x3f);
        KeSetSystemGroupAffinityThread(&local_50,puVar5);
        puVar5 = (undefined8 *)0x0;
        uVar4 = WinHvSetSintOnCurrentProcessor2(param_1,param_2,param_4);
        uVar3 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) goto LAB_1400064a2;
        uVar4 = 0;
        if (uVar2 != 0) {
          for (; (uVar2 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
          }
        }
      } while (uVar2 != 0);
    }
    uVar3 = 0;
    if (bVar1) {
LAB_1400064a2:
      KeRevertToUserGroupAffinityThread(&local_40);
    }
  }
  return uVar3;
}



===== WinHvSetSintOnCurrentProcessor @ 1400064f0 =====

void WinHvSetSintOnCurrentProcessor(uint param_1,uint param_2,char param_3,char param_4)

{
  uint uVar1;
  
                    /* 0x64f0  174  WinHvSetSintOnCurrentProcessor */
  uVar1 = param_3 != '\0' | 2;
  if (param_4 == '\0') {
    uVar1 = (uint)(param_3 != '\0');
  }
  WinHvSetSintOnCurrentProcessor2(param_1,param_2,uVar1);
  return;
}



===== WinHvSetSintOnCurrentProcessor2 @ 140006520 =====

ulonglong WinHvSetSintOnCurrentProcessor2(uint param_1,uint param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x6520  175  WinHvSetSintOnCurrentProcessor2 */
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0350002;
  }
  else {
    if ((param_1 < 0x10) && ((param_3 & 0xfffffff8) == 0)) {
      if ((param_3 & 4) == 0) {
        uVar1 = WinHvpSetVpRegister64Self2
                          ((-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0000 + param_1,
                           (ulonglong)(param_3 & 3) << 0x10 | (ulonglong)param_2 & 0xff,'\0');
        return uVar1;
      }
    }
    uVar1 = 0xc0350005;
  }
  return uVar1;
}



===== WinHvpConnectToSynic @ 140006594 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpConnectToSynic(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  undefined8 *puVar9;
  bool bVar10;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  puVar9 = &local_30;
  local_58 = 0;
  uStack_48 = 0;
  local_50 = 0;
  local_4c = 0;
  local_40 = 0;
  uStack_38 = 0;
  bVar1 = false;
  local_30 = 0;
  uStack_28 = 0;
  uVar3 = KeQueryActiveProcessorCountEx(0xffff);
  RtlInitializeBitMap(&local_50,WinHvpSynicProcessorsBitmap,uVar3);
  bVar10 = WinHvpNested != '\0';
  ExAcquireFastMutex(&WinHvpSynicChangeLock);
  iVar4 = WinHvpGetVpRegister64Self((-(uint)bVar10 & 0x1000) + 0xa0011,&local_58);
  if (((-1 < iVar4) && (local_58 == 1)) && (uVar6 = 0, uVar3 != 0)) {
    do {
      cVar2 = RtlTestBit(&local_50,uVar6);
      if (cVar2 == '\0') {
        local_58 = local_58 & 0xffffffff00000000;
        local_40 = 0;
        uStack_38 = 0;
        KeGetProcessorNumberFromIndex(uVar6,&local_58);
        uStack_38 = CONCAT62(uStack_38._2_6_,(undefined2)local_58);
        local_40 = 1L << (local_58._2_1_ & 0x3f);
        KeSetSystemGroupAffinityThread(&local_40,puVar9);
        bVar1 = true;
        puVar9 = (undefined8 *)0x0;
        uVar5 = WinHvpEnableSynic();
        if ((int)uVar5 < 0) goto LAB_14000673a;
        uVar8 = 5;
        puVar7 = &DAT_14000f064;
        do {
          if (*puVar7 != 0) {
            iVar4 = WinHvpSetVpRegister64Self
                              ((-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0000 + uVar8,
                               (ulonglong)(*puVar7 & 0xff) | 0x10000);
            if (iVar4 < 0) break;
          }
          uVar8 = uVar8 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar8 < 0x10);
        RtlSetBit(&local_50,uVar6);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar3);
    if (bVar1) {
LAB_14000673a:
      KeRevertToUserGroupAffinityThread(&local_30);
    }
  }
  ExReleaseFastMutex(&WinHvpSynicChangeLock);
  return;
}



===== WinHvpDisableSynic @ 140006790 =====

void WinHvpDisableSynic(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x30 + WinHvpVpDataPages);
  WinHvpDisableSynicComponent(puVar1,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0013);
  WinHvpDisableSynicComponent(puVar1 + 2,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0012);
  WinHvpDisableSynicComponent(puVar1 + 4,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0015);
  return;
}



===== WinHvpDisableSynicComponent @ 140006818 =====

void WinHvpDisableSynicComponent(undefined8 *param_1,int param_2)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = 0;
  if (*(char *)((longlong)param_1 + 10) != '\0') {
    uVar1 = WinHvpGetVpRegister64Self2(param_2,&local_res8);
    if (-1 < (int)uVar1) {
      WinHvpSetVpRegister64Self2(param_2,local_res8 & 0xfffffffffffffffe,'\0');
    }
    *(undefined1 *)((longlong)param_1 + 10) = 0;
  }
  if (*(char *)((longlong)param_1 + 9) != '\0') {
    MmUnmapIoSpace(*param_1);
    *(undefined1 *)((longlong)param_1 + 9) = 0;
  }
  if (*(char *)(param_1 + 1) != '\0') {
    WinHvpFreeOverlayPages(*param_1,'\0');
    *(undefined1 *)(param_1 + 1) = 0;
  }
  *param_1 = 0;
  return;
}



===== WinHvpEnableSynic @ 1400068a4 =====

ulonglong WinHvpEnableSynic(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong local_res10;
  
  local_res10 = 0;
  plVar4 = (longlong *)((ulonglong)SystemReserved1[0x12]._4_4_ * 0x30 + WinHvpVpDataPages);
  uVar1 = WinHvpEnableSynicComponent(plVar4,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0013);
  uVar2 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    WinHvpEnableSynicComponent(plVar4 + 2,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0012);
    WinHvpEnableSynicComponent(plVar4 + 4,(-(uint)(WinHvpNested != '\0') & 0x1000) + 0xa0015);
    uVar3 = -(uint)(WinHvpNested != '\0') & 0x1000;
    uVar1 = WinHvpGetVpRegister64Self2(uVar3 + 0xa0010,&local_res10);
    uVar2 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      uVar1 = WinHvpSetVpRegister64Self2(uVar3 + 0xa0010,local_res10 | 1,'\0');
      uVar2 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        return uVar2;
      }
    }
  }
  WinHvpDisableSynic();
  return uVar2;
}



===== WinHvpEnableSynicComponent @ 140006988 =====

ulonglong WinHvpEnableSynicComponent(longlong *param_1,int param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong local_res20;
  
  local_res20 = 0;
  puVar5 = &local_res20;
  uVar2 = WinHvpGetVpRegister64Self2(param_2,puVar5);
  uVar4 = local_res20;
  uVar6 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (((WinHvpCpuManagement == '\0') && (WinHvpNested == '\0')) && ((local_res20 & 1) == 0)) {
    lVar3 = WinHvpAllocateOverlayPages(1);
    *param_1 = lVar3;
    if (lVar3 == 0) {
      uVar6 = 0xc000009a;
      goto LAB_1400069ea;
    }
    *(undefined1 *)(param_1 + 1) = 1;
    uVar2 = MmGetPhysicalAddress(lVar3);
  }
  else {
    uVar2 = local_res20 & 0xfffffffffffff000;
    uVar1 = WinHvpValidateAndMapOverlayAddress(uVar2,puVar5,'\x01',param_1);
    uVar6 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_1400069ea;
    *(undefined1 *)((longlong)param_1 + 9) = 1;
  }
  *(undefined1 *)((longlong)param_1 + 10) = 0;
  if ((uVar4 & 1) != 0) {
    return uVar6;
  }
  uVar4 = WinHvpSetVpRegister64Self2
                    (param_2,uVar2 & 0xfffffffffffff000 | (ulonglong)((uint)uVar4 & 0xffe) | 1,'\0')
  ;
  uVar6 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    *(undefined1 *)((longlong)param_1 + 10) = 1;
    return uVar6;
  }
LAB_1400069ea:
  WinHvpDisableSynicComponent(param_1,param_2);
  return uVar6;
}



===== WinHvGetNodeRequirement @ 140006a90 =====

ulonglong WinHvGetNodeRequirement(int *param_1)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
                    /* 0x6a90  77  WinHvGetNodeRequirement */
  if (param_1[1] < 0) {
    uVar3 = 0;
    while (uVar2 = (uint)uVar3, uVar2 < WinHvpNodeCount) {
      if ((*(char *)(WinHvpNodeInfo + 4 + uVar3 * 0x28) != '\0') &&
         (*(int *)(WinHvpNodeInfo + uVar3 * 0x28) == *param_1)) {
        uVar1 = (ulonglong)(uVar2 | 0x80000000);
        if ((*(byte *)(param_1 + 1) & 1) == 0) {
          uVar1 = uVar3;
        }
        return uVar1;
      }
      uVar3 = (ulonglong)(uVar2 + 1);
    }
  }
  return 0x8000ffff;
}



===== WinHvGetCurrentVpIndex @ 140006ae0 =====

undefined8 WinHvGetCurrentVpIndex(undefined4 *param_1)

{
  undefined8 uVar1;
  undefined8 local_res10 [3];
  
                    /* 0x6ae0  66  WinHvGetCurrentVpIndex */
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0350002;
  }
  else {
    local_res10[0] = 0;
    uVar1 = WinHvpGetVpRegister64Self
                      ((-(uint)(WinHvpNested != '\0') & 0x1000) + 0x90003,local_res10);
    *param_1 = (undefined4)local_res10[0];
  }
  return uVar1;
}



===== WinHvInjectSyntheticMachineCheckEvent @ 140006b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvInjectSyntheticMachineCheckEvent
               (undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x6b40  96  WinHvInjectSyntheticMachineCheckEvent */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  uVar1 = param_3[1];
  local_res8[2] = *param_3;
  local_res8[3] = uVar1;
  uVar1 = param_3[3];
  local_res8[4] = param_3[2];
  local_res8[5] = uVar1;
  uVar1 = param_3[5];
  local_res8[6] = param_3[4];
  local_res8[7] = uVar1;
  uVar1 = param_3[7];
  local_res8[8] = param_3[6];
  local_res8[9] = uVar1;
  uVar1 = param_3[9];
  local_res8[10] = param_3[8];
  local_res8[0xb] = uVar1;
  uVar1 = param_3[0xb];
  local_res8[0xc] = param_3[10];
  local_res8[0xd] = uVar1;
  uVar1 = param_3[0xd];
  local_res8[0xe] = param_3[0xc];
  local_res8[0xf] = uVar1;
  uVar2 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x8c);
  (*local_10)(local_48[0]);
  return uVar2;
}



===== WinHvProcessorNumberToVpIndex @ 140006c00 =====

ulonglong WinHvProcessorNumberToVpIndex(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res8 [2];
  
                    /* 0x6c00  133  WinHvProcessorNumberToVpIndex */
  uVar2 = 0xc0000001;
  local_res8[0] = param_1;
  uVar1 = KeGetProcessorIndexFromNumber(local_res8);
  if (uVar1 != 0xffffffff) {
    uVar2 = WinHvNtProcessorToVpIndex(uVar1,param_2);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== WinHvpGetVpRegister64Self @ 140006c4c =====

void WinHvpGetVpRegister64Self(int param_1,undefined8 *param_2)

{
  WinHvpGetVpRegister64Self2(param_1,param_2);
  return;
}



===== WinHvpGetVpRegister64Self2 @ 140006c64 =====

ulonglong WinHvpGetVpRegister64Self2(int param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 local_18 [24];
  
  uVar3 = 0;
  iVar2 = WinHvpGetMsrNameFromRegisterName(param_1,local_18);
  uVar1 = rdmsr(iVar2);
  *param_2 = uVar1;
  return uVar3 & 0xffffffff;
}



===== WinHvpSetVpRegister64Self2 @ 140006cac =====

ulonglong WinHvpSetVpRegister64Self2(int param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 local_res18 [16];
  
  uVar2 = 0;
  iVar1 = WinHvpGetMsrNameFromRegisterName(param_1,local_res18);
  if (param_3 == '\0') {
    wrmsr(iVar1,param_2);
    uVar2 = uVar2 & 0xffffffff;
  }
  else {
    uVar2 = 0xc0350005;
  }
  return uVar2;
}



===== WinHvpSetVpRegisterAdvancer @ 140006d00 =====

longlong * WinHvpSetVpRegisterAdvancer(longlong *param_1,uint param_2)

{
  *param_1 = *param_1 + (ulonglong)param_2 * 4;
  param_1[1] = param_1[1] + (ulonglong)param_2 * 0x10;
  return param_1;
}



===== WinHvpSetVpRegistersElevated @ 140006d24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvpSetVpRegistersElevated
               (undefined8 param_1,undefined4 param_2,undefined1 param_3,uint param_4,
               undefined4 *param_5,undefined8 *param_6,longlong *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  undefined1 auStackY_378 [32];
  uint local_300 [64];
  undefined8 local_200;
  undefined4 local_1f8;
  undefined1 local_1f4;
  undefined1 local_1f3;
  undefined2 local_1f2;
  undefined4 local_1f0 [4];
  undefined8 local_1e0 [28];
  ulonglong local_100;
  
  local_100 = __security_cookie ^ (ulonglong)auStackY_378;
  if (param_4 == 0) {
    uVar3 = (WinHvpConnected != '\0') + 0xc0350002;
  }
  else {
    *param_7 = 0;
    memset(local_1f0,0,0xf0);
    local_1f3 = 0;
    local_1f2 = 0;
    local_200 = param_1;
    local_1f8 = param_2;
    local_1f4 = param_3;
    do {
      uVar7 = (ulonglong)param_4;
      local_300[0] = 0;
      if (param_4 < 8) {
        uVar3 = 0;
        if (param_4 != 0) goto LAB_140006de6;
      }
      else {
        uVar7 = 7;
LAB_140006de6:
        uVar3 = (uint)uVar7;
        puVar5 = local_1e0;
        puVar6 = param_6;
        puVar8 = param_5;
        do {
          uVar1 = *puVar8;
          puVar8 = puVar8 + 1;
          *(undefined4 *)(puVar5 + -2) = uVar1;
          uVar4 = *puVar6;
          uVar2 = puVar6[1];
          puVar6 = puVar6 + 2;
          *puVar5 = uVar4;
          puVar5[1] = uVar2;
          puVar5 = puVar5 + 4;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      uVar4 = MmGetPhysicalAddress(&local_200);
      uVar3 = WinHvpHypercall(0x51,uVar3,uVar4,0,local_300);
      uVar7 = (ulonglong)local_300[0];
      *param_7 = *param_7 + uVar7;
      param_4 = param_4 - local_300[0];
      param_5 = param_5 + uVar7;
      param_6 = param_6 + uVar7 * 2;
    } while ((uVar3 == 0) && (param_4 != 0));
  }
  return uVar3;
}



===== WinHvDisablePartitionVtl @ 140006e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvDisablePartitionVtl(undefined8 param_1,undefined1 param_2,undefined1 param_3)

{
  uint uVar1;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x6e90  49  WinHvDisablePartitionVtl */
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  *(undefined1 *)(local_res8 + 1) = param_2;
  *(undefined1 *)((longlong)local_res8 + 9) = param_3;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xe);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvDisableVpVtl @ 140006f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvDisableVpVtl(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  uint uVar1;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x6f20  50  WinHvDisableVpVtl */
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  *(undefined1 *)((longlong)local_res8 + 0xc) = param_3;
  *(undefined1 *)((longlong)local_res8 + 0xd) = param_4;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x10);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvEnablePartitionVtl @ 140006fc0 =====

void WinHvEnablePartitionVtl
               (ulonglong param_1,undefined1 param_2,byte param_3,byte param_4,byte param_5)

{
  ulonglong local_18;
  undefined8 uStack_10;
  
                    /* 0x6fc0  53  WinHvEnablePartitionVtl */
  uStack_10 = (ulonglong)
              CONCAT11(((param_5 & 1) * '\x02' | param_4 & 1) * '\x02' | param_3 & 1,param_2);
  local_18 = param_1;
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0xd,'\0',&local_18,0x10,(void *)0x0,0);
  return;
}



===== WinHvEnableVpVtl @ 140007040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvEnableVpVtl(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 *local_res8;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x7040  54  WinHvEnableVpVtl */
  local_res8 = (undefined8 *)0x0;
  memset(local_58,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_58);
  puVar2 = local_res8;
  memset(local_res8,0,0xf0);
  *puVar2 = param_1;
  *(undefined4 *)(puVar2 + 1) = param_2;
  *(undefined1 *)((longlong)puVar2 + 0xc) = param_3;
  uVar1 = param_4[1];
  puVar2[2] = *param_4;
  puVar2[3] = uVar1;
  uVar1 = param_4[3];
  puVar2[4] = param_4[2];
  puVar2[5] = uVar1;
  uVar1 = param_4[5];
  puVar2[6] = param_4[4];
  puVar2[7] = uVar1;
  uVar1 = param_4[7];
  puVar2[8] = param_4[6];
  puVar2[9] = uVar1;
  uVar1 = param_4[9];
  puVar2[10] = param_4[8];
  puVar2[0xb] = uVar1;
  uVar1 = param_4[0xb];
  puVar2[0xc] = param_4[10];
  puVar2[0xd] = uVar1;
  uVar1 = param_4[0xd];
  puVar2[0xe] = param_4[0xc];
  puVar2[0xf] = uVar1;
  uVar1 = param_4[0xf];
  puVar2[0x10] = param_4[0xe];
  puVar2[0x11] = uVar1;
  uVar1 = param_4[0x11];
  puVar2[0x12] = param_4[0x10];
  puVar2[0x13] = uVar1;
  uVar1 = param_4[0x13];
  puVar2[0x14] = param_4[0x12];
  puVar2[0x15] = uVar1;
  uVar1 = param_4[0x15];
  puVar2[0x16] = param_4[0x14];
  puVar2[0x17] = uVar1;
  uVar1 = param_4[0x17];
  puVar2[0x18] = param_4[0x16];
  puVar2[0x19] = uVar1;
  uVar1 = param_4[0x19];
  puVar2[0x1a] = param_4[0x18];
  puVar2[0x1b] = uVar1;
  uVar1 = param_4[0x1b];
  puVar2[0x1c] = param_4[0x1a];
  puVar2[0x1d] = uVar1;
  uVar3 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0xf);
  (*local_20)(local_58[0]);
  return uVar3;
}



===== WinHvControlHypervisorIptTrace @ 140007170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvControlHypervisorIptTrace(void *param_1,void *param_2)

{
  uint uVar1;
  void *local_res8;
  void *local_res18 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x7170  28  WinHvControlHypervisorIptTrace */
  memset(local_48,0,0x40);
  local_res8 = (void *)0x0;
  local_res18[0] = (void *)0x0;
  WinHvpSetupHypercall(&local_res8,local_res18,(longlong)local_48);
  memmove(local_res8,param_1,0x820);
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xe9);
  if (-1 < (int)uVar1) {
    memmove(param_2,local_res18[0],0x1000);
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvQueryReferenceCounter @ 140007220 =====

undefined8 WinHvQueryReferenceCounter(undefined8 *param_1)

{
  undefined8 uVar1;
  
                    /* 0x7220  137  WinHvQueryReferenceCounter */
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0350002;
  }
  else {
    uVar1 = WinHvpGetVpRegister64Self(0x90004,param_1);
  }
  return uVar1;
}



===== WinHvpFreeAllVpDataPages @ 140007250 =====

void WinHvpFreeAllVpDataPages(void)

{
  if (WinHvpVpDataPages != 0) {
    ExFreePoolWithTag(WinHvpVpDataPages,0x55764857);
    WinHvpVpDataPages = 0;
  }
  return;
}



===== WinHvpFreeVmmCapabilities @ 140007288 =====

void WinHvpFreeVmmCapabilities(void)

{
  if (WinHvpVmmCapabilities != 0) {
    ExFreePoolWithTag(WinHvpVmmCapabilities,0x55764857);
    WinHvpVmmCapabilities = 0;
  }
  return;
}



===== WinHvpTriageDumpBugcheckCallback @ 1400072c0 =====

void WinHvpTriageDumpBugcheckCallback(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  if ((WinHvpBlackbox != 0) && ((*(uint *)(param_3 + 1) & 1) != 0)) {
    *param_3 = WinHvpBlackbox + 0x438;
  }
  return;
}



===== WinHvLowMemoryPolicyReturnStatus @ 1400072f0 =====

undefined4 WinHvLowMemoryPolicyReturnStatus(void)

{
  undefined4 in_R9D;
  
                    /* 0x72f0  104  WinHvLowMemoryPolicyReturnStatus */
  return in_R9D;
}



===== WinHvFinalizePartition @ 140007300 =====

void WinHvFinalizePartition(ulonglong param_1)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong local_18 [2];
  
                    /* 0x7300  56  WinHvFinalizePartition */
  if (WinHvpRootSchedulerActive != '\0') {
    piVar1 = WinHvpReferencePartition(param_1);
    if (piVar1 != (int *)0x0) {
      lVar2 = WinHvpGetPartitionVpTable((longlong)piVar1);
      if ((*(int *)(lVar2 + 0xc) != 0) && (uVar3 = 0, *(int *)(lVar2 + 8) != 0)) {
        do {
          WinHvpDeleteVpObject(param_1,uVar3);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(lVar2 + 8));
      }
      WinHvpDereferencePartition(piVar1);
    }
  }
  local_18[1] = 0;
  local_18[0] = param_1;
  uVar3 = WinHvpFastHypercall(0x42,local_18);
  if (-1 < (int)uVar3) {
    WinHvpUnpersistMirroringDeposit(param_1);
  }
  return;
}



===== WinHvGetNextChildPartition @ 1400073a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetNextChildPartition(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 *local_res10;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x73a0  73  WinHvGetNextChildPartition */
  local_res8 = (undefined8 *)0x0;
  local_res10 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,&local_res10,(longlong)local_48);
  *local_res8 = param_1;
  local_res8[1] = param_2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x47);
  if (-1 < (int)uVar1) {
    *param_3 = *local_res10;
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvGetPartitionId @ 140007440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetPartitionId(longlong *param_1)

{
  uint uVar1;
  longlong *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x7440  78  WinHvGetPartitionId */
  local_res8 = (longlong *)0x0;
  memset(local_48,0,0x40);
  uVar1 = 0;
  if (WinHvpCurrentPartitionId == 0) {
    WinHvpSetupHypercall((undefined8 *)0x0,&local_res8,(longlong)local_48);
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x46);
    if (-1 < (int)uVar1) {
      WinHvpCurrentPartitionId = *local_res8;
    }
    (*local_10)(local_48[0]);
  }
  *param_1 = WinHvpCurrentPartitionId;
  return uVar1;
}



===== WinHvGetPartitionPropertyEx @ 1400074d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetPartitionPropertyEx
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,void *param_4)

{
  uint uVar1;
  undefined8 *local_res8;
  void *local_res18 [2];
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x74d0  80  WinHvGetPartitionPropertyEx */
  memset(local_58,0,0x40);
  local_res8 = (undefined8 *)0x0;
  local_res18[0] = (void *)0x0;
  WinHvpSetupHypercall(&local_res8,local_res18,(longlong)local_58);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  local_res8[2] = param_3;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x101);
  if (-1 < (int)uVar1) {
    memmove(param_4,local_res18[0],0xfe8);
  }
  (*local_20)(local_58[0]);
  return uVar1;
}



===== WinHvGetVmmCapabilities @ 140007590 =====

undefined8 WinHvGetVmmCapabilities(void)

{
                    /* 0x7590  88  WinHvGetVmmCapabilities */
  return WinHvpVmmCapabilities;
}



===== WinHvIsOverlayMapLocationRequired @ 1400075a0 =====

undefined1 WinHvIsOverlayMapLocationRequired(void)

{
  undefined1 uVar1;
  
                    /* 0x75a0  98  WinHvIsOverlayMapLocationRequired */
  uVar1 = 0;
  if ((WinHvpCpuManagement == '\0') && ((*(byte *)(WinHvpVmmCapabilities + 8) & 2) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}



===== WinHvQueryInterceptIrql @ 1400075d0 =====

undefined1 WinHvQueryInterceptIrql(void)

{
                    /* 0x75d0  135  WinHvQueryInterceptIrql */
  return 0xc;
}



===== WinHvQueryPartitionReservedPages @ 1400075e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvQueryPartitionReservedPages
               (undefined8 param_1,ulonglong param_2,ushort *param_3,void *param_4)

{
  uint uVar1;
  undefined8 *local_res18 [2];
  ushort *local_68 [2];
  longlong local_58 [7];
  code *local_20;
  
  memset(local_58,0,0x40);
  local_res18[0] = (undefined8 *)0x0;
  local_68[0] = (ushort *)0x0;
  WinHvpSetupHypercall(local_res18,local_68,(longlong)local_58);
  if (*param_3 == 0x1ff) {
    local_res18[0][1] = 0;
    *local_res18[0] = param_1;
    local_res18[0][1] = (param_2 & 0xff ^ local_res18[0][1]) & 0xfffffffffffffffe ^ param_2 & 0xff;
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_58,0x105);
    if (uVar1 == 0xc0350002) {
      uVar1 = 0;
    }
    else if ((int)uVar1 < 0) goto LAB_1400076ae;
    *param_3 = *local_68[0];
    if (*local_68[0] != 0) {
      memmove(param_4,local_68[0] + 4,(ulonglong)*local_68[0] << 3);
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
LAB_1400076ae:
  if (local_58[0] != 0) {
    (*local_20)();
  }
  return uVar1;
}



===== WinHvSetInterceptRoutine @ 1400076e0 =====

undefined8 WinHvSetInterceptRoutine(ulonglong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  
                    /* 0x76e0  163  WinHvSetInterceptRoutine */
  piVar1 = WinHvpReferencePartition(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc035000d;
  }
  else {
    *(undefined8 *)(piVar1 + 4) = param_2;
    *(undefined8 *)(piVar1 + 6) = param_3;
    WinHvpDereferencePartition(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== WinHvSetLowMemoryPolicyRoutine @ 140007730 =====

undefined8 WinHvSetLowMemoryPolicyRoutine(ulonglong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  
                    /* 0x7730  166  WinHvSetLowMemoryPolicyRoutine */
  piVar1 = WinHvpReferencePartition(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc035000d;
  }
  else {
    *(undefined8 *)(piVar1 + 10) = param_2;
    *(undefined8 *)(piVar1 + 0xc) = param_3;
    WinHvpDereferencePartition(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== WinHvpAcquireAsyncMessage @ 140007778 =====

void WinHvpAcquireAsyncMessage(longlong param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &WinHvpGlobalAsyncMutex;
  }
  else {
    puVar1 = (undefined *)(param_1 + 0xb0);
  }
  ExAcquireFastMutex(puVar1);
  return;
}



===== WinHvpDeleteHvPartition @ 1400077ac =====

void WinHvpDeleteHvPartition(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_18 = param_1;
  WinHvpFastHypercall(0x43,&local_18);
  return;
}



===== WinHvpDeletePartitionObject @ 1400077d8 =====

void WinHvpDeletePartitionObject(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x38),0x4e764857);
  }
  if (*(int **)(param_1 + 0x50) != (int *)0x0) {
    WinHvpDereferencePartitionData(*(int **)(param_1 + 0x50));
  }
  ExFreePoolWithTag(param_1,0x48764857);
  return;
}



===== WinHvpDeletePartitionRemote @ 14000782c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpDeletePartitionRemote(undefined8 param_1)

{
  uint uVar1;
  undefined8 *local_res8 [4];
  undefined8 local_48 [3];
  undefined1 local_30;
  code *local_10;
  
  memset(local_48,0,0x40);
  local_res8[0] = (undefined8 *)0x0;
  local_30 = 1;
  WinHvpSetupHypercall(local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8[0] = param_1;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,0x43);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvpFinalizePartitionRemote @ 140007898 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpFinalizePartitionRemote(undefined8 param_1)

{
  uint uVar1;
  undefined8 *local_res8 [4];
  undefined8 local_48 [3];
  undefined1 local_30;
  code *local_10;
  
  memset(local_48,0,0x40);
  local_res8[0] = (undefined8 *)0x0;
  local_30 = 1;
  WinHvpSetupHypercall(local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8[0] = param_1;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,0x42);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvpInitializePartitionRemote @ 140007904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpInitializePartitionRemote(undefined8 param_1)

{
  uint uVar1;
  undefined8 *local_res8 [4];
  undefined8 local_48 [3];
  undefined1 local_30;
  code *local_10;
  
  memset(local_48,0,0x40);
  local_res8[0] = (undefined8 *)0x0;
  local_30 = 1;
  WinHvpSetupHypercall(local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8[0] = param_1;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,0x41);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvpOnCallCompletionDpcRoutine @ 140007970 =====

void WinHvpOnCallCompletionDpcRoutine(undefined8 param_1,undefined8 param_2,int *param_3)

{
  if (param_3 == (int *)0x0) {
    KeSetEvent(&WinHvpGlobalAsyncEvent);
  }
  else {
    KeSetEvent(param_3 + 0x26,0,0);
    WinHvpDereferencePartition(param_3);
  }
  return;
}



===== WinHvpOnCallCompletionNotification @ 1400079c0 =====

void WinHvpOnCallCompletionNotification(longlong param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(ulonglong *)(param_1 + 0x10) == 0) {
    if (*(ushort *)(param_1 + 0x18) != 0) {
      uVar3 = *(ushort *)(param_1 + 0x18) | 0xc0350000;
    }
    piVar2 = (int *)&WinHvpGlobalAsyncDpc;
    piVar1 = (int *)0x0;
    WinHvpGlobalAsyncStatus = uVar3;
  }
  else {
    piVar1 = WinHvpReferencePartition(*(ulonglong *)(param_1 + 0x10));
    if (*(ushort *)(param_1 + 0x18) != 0) {
      uVar3 = *(ushort *)(param_1 + 0x18) | 0xc0350000;
    }
    piVar1[0x3a] = uVar3;
    piVar2 = piVar1 + 0x16;
    *(undefined8 *)(piVar1 + 0x3c) = *(undefined8 *)(param_1 + 0x20);
    piVar1[0x3e] = *(int *)(param_1 + 0x1c);
  }
  KeInsertQueueDpc(piVar2,piVar1,0);
  return;
}



===== WinHvpOnMirroringNotification @ 140007a54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WinHvpOnMirroringNotification(longlong param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  int *piVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (*(ulonglong *)(param_1 + 8) == WinHvpCurrentPartitionId) {
    if (WinHvpBlackbox != 0) {
      LOCK();
      puVar1 = (uint *)(WinHvpBlackbox + 4);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + 1;
      UNLOCK();
      uVar6 = (ulonglong)(uVar5 & 0x3f);
      *(undefined4 *)(WinHvpBlackbox + 8 + uVar6 * 0x10) = 2;
      if (*(ushort *)(param_1 + 0x10) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(ushort *)(param_1 + 0x10) | 0xc0350000;
      }
      *(uint *)(WinHvpBlackbox + 0xc + uVar6 * 0x10) = uVar5;
      uVar2 = KeQueryPerformanceCounter(0);
      *(undefined8 *)(WinHvpBlackbox + 0x10 + uVar6 * 0x10) = uVar2;
    }
    if (WinHvpMirroringNotificationIsr == (code *)0x0) {
      return;
    }
    uVar2 = 0;
    pcVar4 = WinHvpMirroringNotificationIsr;
  }
  else {
    piVar3 = WinHvpReferencePartition(*(ulonglong *)(param_1 + 8));
    if (piVar3 == (int *)0x0) {
      return;
    }
    WinHvpDereferencePartition(piVar3);
    pcVar4 = *(code **)(piVar3 + 4);
    uVar2 = *(undefined8 *)(piVar3 + 6);
  }
  (*pcVar4)(uVar2,param_1);
  return;
}



===== WinHvpReferencePartitionData @ 140007b24 =====

undefined8 WinHvpReferencePartitionData(ulonglong param_1,undefined8 *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined8 uVar3;
  
  uVar3 = 0xc035000d;
  piVar2 = WinHvpReferencePartition(param_1);
  if (piVar2 != (int *)0x0) {
    piVar1 = *(int **)(piVar2 + 0x14);
    *param_2 = piVar1;
    if (piVar1 != (int *)0x0) {
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    WinHvpDereferencePartition(piVar2);
    uVar3 = 0;
  }
  return uVar3;
}



===== WinHvpReleaseAsyncMessage @ 140007b70 =====

void WinHvpReleaseAsyncMessage(longlong param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &WinHvpGlobalAsyncMutex;
  }
  else {
    puVar1 = (undefined *)(param_1 + 0xb0);
  }
  ExReleaseFastMutex(puVar1);
  return;
}



===== WinHvpWaitForAsyncCall @ 140007ba4 =====

undefined4 WinHvpWaitForAsyncCall(longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    puVar2 = &WinHvpGlobalAsyncEvent;
  }
  else {
    puVar2 = (undefined *)(param_1 + 0x98);
  }
  KeWaitForSingleObject(puVar2,0,0,0,0);
  if (param_1 == 0) {
    uVar1 = WinHvpGlobalAsyncStatus;
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = *(undefined8 *)(param_1 + 0xf0);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0xf8);
    }
    uVar1 = *(undefined4 *)(param_1 + 0xe8);
  }
  return uVar1;
}



===== WinHvLogHypervisorSystemConfig @ 140007c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvLogHypervisorSystemConfig(void)

{
  uint uVar1;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x7c40  101  WinHvLogHypervisorSystemConfig */
  memset(local_48,0,0x40);
  WinHvpSetupHypercall((undefined8 *)0x0,(undefined8 *)0x0,(longlong)local_48);
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xf8);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvQueryLoaderInterface @ 140007ca0 =====

undefined8 WinHvQueryLoaderInterface(undefined1 *param_1,undefined8 *param_2)

{
                    /* 0x7ca0  136  WinHvQueryLoaderInterface */
  if ((((param_1 == (undefined1 *)0x0) || (param_2 == (undefined8 *)0x0)) ||
      (*param_1 = 6, 6 < (byte)param_1[1])) || ((byte)param_1[2] < 6)) {
    return 0xc000000d;
  }
  param_2[1] = WinHvRegisterRemoteHvCallInterface;
  param_2[2] = WinHvUnregisterRemoteHvCallInterface;
  *param_2 = WinHvReportPresentHypervisor;
  param_2[3] = WinHvpGetSystemProperty;
  param_2[4] = WinHvpSetSystemProperty;
  param_2[5] = WinHvpPersistDevice;
  param_2[6] = WinHvpUnpersistDevice;
  param_2[7] = WinHvpPersistDeviceInterrupt;
  param_2[8] = WinHvCreateServicePartition;
  param_2[9] = WinHvDeleteServicePartition;
  param_2[10] = WinHvMapSparseGpaPages;
  param_2[0xb] = WinHvpDepositNonMirroringMemory;
  param_2[0xc] = WinHvWithdrawAllMemory;
  param_2[0xd] = WinHvCreateVp;
  param_2[0xe] = WinHvDeleteVp;
  param_2[0xf] = WinHvSetVpRegisters;
  param_2[0x10] = WinHvGetVpRegisters;
  param_2[0x11] = WinHvMapUnmapVpStatePage;
  param_2[0x12] = WinHvpSubsumeInitializedMemory;
  param_2[0x13] = WinHvpSubsumeVp;
  param_2[0x14] = WinHvpDestroySubsumedContext;
  param_2[0x15] = WinHvpRegisterSintIsr;
  param_2[0x16] = WinHvQueryPartitionReservedPages;
  return 0;
}



===== WinHvSetHvDebugProperty @ 140007df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetHvDebugProperty(undefined1 param_1)

{
  uint uVar1;
  undefined4 *local_res10 [3];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x7df0  161  WinHvSetHvDebugProperty */
  memset(local_48,0,0x40);
  local_res10[0] = (undefined4 *)0x0;
  WinHvpSetupHypercall(local_res10,(undefined8 *)0x0,(longlong)local_48);
  *(undefined8 *)(local_res10[0] + 2) = 0;
  *(undefined8 *)(local_res10[0] + 4) = 0;
  *(undefined8 *)(local_res10[0] + 6) = 0;
  *(undefined8 *)(local_res10[0] + 8) = 0;
  *local_res10[0] = 10;
  *(undefined1 *)(local_res10[0] + 2) = param_1;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x6f);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvSetHwWatchdogConfig @ 140007e70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetHwWatchdogConfig(void *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  void *local_res18 [2];
  undefined1 local_58 [40];
  longlong local_30;
  code *local_20;
  
                    /* 0x7e70  162  WinHvSetHwWatchdogConfig */
  memset(local_58,0,0x40);
  local_res18[0] = (void *)0x0;
  if (param_2 - 1 < 0x1000) {
    iVar2 = 0;
    while( true ) {
      WinHvpSetupHypercall(local_res18,(undefined8 *)0x0,(longlong)local_58);
      memmove(local_res18[0],param_1,(ulonglong)param_2);
      uVar1 = WinHvpVariableHeaderHypercall
                        (0xf6,param_2 - 1,*(undefined8 *)(local_30 + 0x18),
                         *(undefined8 *)(local_30 + 0x28));
      (*local_20)();
      if ((((uVar1 != 0xc0350075) && (uVar1 != 0xc035000b)) && (1 < uVar1 + 0x3fcaff7f)) ||
         (uVar1 = WinHvpLowMemoryHandler
                            ((undefined *)0xffffffffffffffff,0x8000ffff,uVar1,0xf6,iVar2,'\0'),
         (int)uVar1 < 0)) break;
      iVar2 = iVar2 + 1;
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WinHvSetSystemInformation @ 140007f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetSystemInformation(int param_1,void *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  size_t _Size;
  undefined4 *local_res20;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x7f80  177  WinHvSetSystemInformation */
  memset(local_58,0,0x40);
  local_res20 = (undefined4 *)0x0;
  WinHvpSetupHypercall(&local_res20,(undefined8 *)0x0,(longlong)local_58);
  bVar2 = false;
  bVar1 = true;
  if (param_1 == 5) {
    uVar3 = 0x10;
    *local_res20 = 0x36;
LAB_1400080e9:
    if (uVar3 <= param_3) goto LAB_14000800e;
    uVar3 = 0xc0000023;
  }
  else {
    if (param_1 == 8) {
      *local_res20 = 0x1d;
LAB_1400080d3:
      uVar3 = 4;
      goto LAB_1400080e9;
    }
    if (param_1 == 9) {
      *local_res20 = 0x21;
LAB_1400080c5:
      uVar3 = 1;
      goto LAB_1400080e9;
    }
    if (param_1 == 10) {
      *local_res20 = 0x24;
      goto LAB_1400080d3;
    }
    if (param_1 == 0xf) {
      WinHvpAcquireAsyncMessage(0);
      bVar2 = true;
      *local_res20 = 0x32;
      goto LAB_1400080c5;
    }
    if (param_1 != 0x10) {
      uVar3 = 0xc0000003;
      goto LAB_14000806f;
    }
    *local_res20 = 0x38;
LAB_14000800e:
    _Size = 0x20;
    if (param_3 < 0x20) {
      _Size = (ulonglong)param_3;
    }
    memmove(local_res20 + 2,param_2,_Size);
    uVar3 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x6f);
    (*local_20)();
    bVar1 = false;
    if (uVar3 == 0xc0350079) {
      uVar3 = WinHvpWaitForAsyncCall(0,(undefined8 *)0x0,(undefined4 *)0x0);
    }
  }
  if (bVar2) {
    WinHvpReleaseAsyncMessage(0);
  }
  if (!bVar1) {
    return uVar3;
  }
LAB_14000806f:
  (*local_20)(local_58[0]);
  return uVar3;
}



===== WinHvUpdateHvProcessorFeatures @ 140008110 =====

void WinHvUpdateHvProcessorFeatures(undefined4 param_1,undefined8 param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x8110  195  WinHvUpdateHvProcessorFeatures */
  local_14 = 0;
  local_18 = param_1;
  local_10 = param_2;
  WinHvpAllocatingHypercall(0xffffffffffffffff,0x8000ffff,5,'\0',&local_18,0x10,(void *)0x0,0);
  return;
}



===== WinHvpGetSystemProperty @ 140008160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpGetSystemProperty
               (undefined4 param_1,void *param_2,uint param_3,void *param_4,uint param_5)

{
  uint uVar1;
  undefined8 *local_58;
  void *local_50;
  longlong local_48 [7];
  code *local_10;
  
  memset(local_48,0,0x40);
  local_58 = (undefined8 *)0x0;
  local_50 = (void *)0x0;
  WinHvpSetupHypercall(&local_58,&local_50,(longlong)local_48);
  *local_58 = 0;
  local_58[1] = 0;
  *(undefined4 *)local_58 = param_1;
  if (param_3 != 0) {
    memmove(local_58 + 1,param_2,(ulonglong)param_3);
  }
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x7b);
  if (-1 < (int)uVar1) {
    memmove(param_4,local_50,(ulonglong)param_5);
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvpOnRestartCompletionNotification @ 140008228 =====

void WinHvpOnRestartCompletionNotification(longlong param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    piVar1 = &DAT_14001516c;
  }
  else {
    if (*(int *)(param_1 + 0x14) != 1) {
      return;
    }
    piVar1 = &DAT_140015168;
  }
  LOCK();
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  KeInsertQueueDpc(&DAT_140015070,0,0);
  return;
}



===== WinHvpRestartNotificationDpcRoutine @ 140008270 =====

ulonglong WinHvpRestartNotificationDpcRoutine(void)

{
  ulonglong uVar1;
  bool bVar2;
  
  uVar1 = 0;
  LOCK();
  bVar2 = DAT_140015170 == 0;
  if (bVar2) {
    DAT_140015170 = 1;
  }
  else {
    uVar1 = (ulonglong)DAT_140015170;
  }
  UNLOCK();
  if (bVar2) {
    uVar1 = IoQueueWorkItemEx(DAT_1400150b0,WinHvpRestartNotificationWorkItemRoutine,1,0);
  }
  return uVar1;
}



===== WinHvpSetSystemProperty @ 1400082b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpSetSystemProperty(undefined4 param_1,void *param_2,uint param_3)

{
  uint uVar1;
  undefined8 *local_res20;
  longlong local_48 [7];
  code *local_10;
  
  memset(local_48,0,0x40);
  local_res20 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res20,(undefined8 *)0x0,(longlong)local_48);
  *local_res20 = 0;
  local_res20[1] = 0;
  local_res20[2] = 0;
  local_res20[3] = 0;
  local_res20[4] = 0;
  *(undefined4 *)local_res20 = param_1;
  memmove(local_res20 + 1,param_2,(ulonglong)param_3);
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x6f);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvCheckForIoIntercept @ 140008360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvCheckForIoIntercept
               (undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined2 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 *param_7)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined1 *local_58 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x8360  19  WinHvCheckForIoIntercept */
  local_res8 = (undefined8 *)0x0;
  local_58[0] = (undefined1 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,local_58,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  *(undefined1 *)((longlong)local_res8 + 0xc) = param_3;
  *(undefined2 *)((longlong)local_res8 + 0xe) = param_4;
  *(undefined1 *)(local_res8 + 2) = param_5;
  *(undefined1 *)((longlong)local_res8 + 0x11) = param_6;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xad);
  if (uVar1 == 0) {
    *param_7 = *local_58[0];
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvCompleteIntercept @ 140008440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvCompleteIntercept(undefined8 param_1,undefined4 param_2,uint param_3,void *param_4)

{
  uint uVar1;
  undefined8 *local_58 [2];
  undefined8 local_48 [5];
  longlong local_20;
  code *local_10;
  
                    /* 0x8440  23  WinHvCompleteIntercept */
  memset(local_48,0,0x40);
  local_58[0] = (undefined8 *)0x0;
  if (param_3 < 0xff1) {
    WinHvpSetupHypercall(local_58,(undefined8 *)0x0,(longlong)local_48);
    *local_58[0] = param_1;
    *(undefined4 *)(local_58[0] + 1) = param_2;
    *(uint *)((longlong)local_58[0] + 0xc) = param_3;
    if (param_3 != 0) {
      memmove(local_58[0] + 2,param_4,(ulonglong)param_3);
    }
    uVar1 = WinHvpVariableHeaderHypercall
                      (0xbd,param_3,*(undefined8 *)(local_20 + 0x18),
                       *(undefined8 *)(local_20 + 0x28));
    (*local_10)(local_48[0]);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WinHvGetLogicalProcessorProperty @ 140008500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetLogicalProcessorProperty(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined4 *local_res20;
  undefined4 *local_58 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x8500  69  WinHvGetLogicalProcessorProperty */
  local_res20 = (undefined4 *)0x0;
  local_58[0] = (undefined4 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res20,local_58,(longlong)local_48);
  *local_res20 = param_1;
  local_res20[1] = param_2;
  uVar5 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x7a);
  if (-1 < (int)uVar5) {
    uVar1 = local_58[0][1];
    uVar2 = local_58[0][2];
    uVar3 = local_58[0][3];
    *param_3 = *local_58[0];
    param_3[1] = uVar1;
    param_3[2] = uVar2;
    param_3[3] = uVar3;
    uVar4 = *(undefined8 *)(local_58[0] + 6);
    *(undefined8 *)(param_3 + 4) = *(undefined8 *)(local_58[0] + 4);
    *(undefined8 *)(param_3 + 6) = uVar4;
  }
  (*local_10)(local_48[0]);
  return uVar5;
}



===== WinHvGetLogicalProcessorRegisters @ 1400085b0 =====

void WinHvGetLogicalProcessorRegisters(uint param_1,void *param_2,longlong *param_3,void *param_4)

{
                    /* 0x85b0  70  WinHvGetLogicalProcessorRegisters */
  WinHvpSpecialListRepHypercall
            (0x88,(ulonglong)param_1,(void *)0x0,0,(longlong *)0x0,0,param_2,0x10,(undefined *)0x0,
             (undefined *)0x0,param_4,0x10,(undefined *)0x0,(longlong *)0x0,param_3);
  return;
}



===== WinHvGetLogicalProcessorRunTime @ 140008610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetLogicalProcessorRunTime
               (undefined4 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined4 *local_58;
  undefined8 *local_50;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x8610  71  WinHvGetLogicalProcessorRunTime */
  local_58 = (undefined4 *)0x0;
  local_50 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_58,&local_50,(longlong)local_48);
  *local_58 = param_1;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],4);
  if (-1 < (int)uVar1) {
    *param_2 = *local_50;
    *param_3 = local_50[1];
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = local_50[3];
    }
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvProcessorIndexToLpIndex @ 1400086d0 =====

undefined8 WinHvProcessorIndexToLpIndex(uint param_1,undefined4 *param_2)

{
                    /* 0x86d0  132  WinHvProcessorIndexToLpIndex */
  if (WinHvpMaximumProcessorCount <= param_1) {
    return 0xc0000001;
  }
  if (*(char *)(WinHvpProcessorToLpIndex + 4 + (ulonglong)param_1 * 8) == '\0') {
    return 0xc0000022;
  }
  *param_2 = *(undefined4 *)(WinHvpProcessorToLpIndex + (ulonglong)param_1 * 8);
  return 0;
}



===== WinHvSetLogicalProcessorRegisters @ 140008710 =====

void WinHvSetLogicalProcessorRegisters
               (uint param_1,longlong param_2,undefined8 *param_3,longlong *param_4)

{
  byte bVar1;
  longlong local_18;
  undefined8 *local_10;
  
                    /* 0x8710  165  WinHvSetLogicalProcessorRegisters */
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    local_18 = param_2;
    local_10 = param_3;
    WinHvpSpecialListRepHypercall
              (0x89,(ulonglong)param_1,(void *)0x0,0,(longlong *)0x0,0,&local_18,0x20,
               WinHvpSetLogicalProcessorRegisterBuilder,WinHvpSetLogicalProcessorRegisterAdvancer,
               (void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_4);
  }
  else {
    WinHvpSetLogicalProcessorRegistersElevated(param_1,param_2,param_3,param_4);
  }
  return;
}



===== WinHvpSetLogicalProcessorRegisterAdvancer @ 1400087f0 =====

longlong * WinHvpSetLogicalProcessorRegisterAdvancer(longlong *param_1,uint param_2)

{
  *param_1 = *param_1 + (ulonglong)param_2 * 0x10;
  param_1[1] = param_1[1] + (ulonglong)param_2 * 0x10;
  return param_1;
}



===== WinHvpSetLogicalProcessorRegisterBuilder @ 140008810 =====

void WinHvpSetLogicalProcessorRegisterBuilder(undefined8 *param_1,undefined8 *param_2,int param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  puVar1 = (undefined8 *)*param_2;
  puVar2 = (undefined8 *)param_2[1];
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar3 = *puVar1;
    uVar4 = puVar1[1];
    puVar1 = puVar1 + 2;
    *param_1 = uVar3;
    param_1[1] = uVar4;
    uVar3 = *puVar2;
    uVar4 = puVar2[1];
    puVar2 = puVar2 + 2;
    param_1[2] = uVar3;
    param_1[3] = uVar4;
    param_1 = param_1 + 4;
  }
  return;
}



===== WinHvpSetLogicalProcessorRegistersElevated @ 140008848 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvpSetLogicalProcessorRegistersElevated
               (uint param_1,longlong param_2,undefined8 *param_3,longlong *param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined1 auStackY_368 [32];
  uint local_300 [64];
  undefined8 local_200 [32];
  ulonglong local_100;
  
  local_100 = __security_cookie ^ (ulonglong)auStackY_368;
  if (param_1 == 0) {
    uVar4 = (WinHvpConnected != '\0') + 0xc0350002;
  }
  else {
    *param_4 = 0;
    memset(local_200,0,0x100);
    uVar5 = MmGetPhysicalAddress(local_200);
    do {
      local_300[0] = 0;
      if (param_1 < 8) {
        uVar4 = param_1;
        if (param_1 != 0) goto LAB_1400088e5;
      }
      else {
        uVar4 = 7;
LAB_1400088e5:
        uVar8 = (ulonglong)uVar4;
        puVar6 = local_200 + 2;
        puVar7 = param_3;
        do {
          puVar1 = (undefined8 *)((param_2 - (longlong)param_3) + (longlong)puVar7);
          uVar2 = puVar1[1];
          puVar6[-2] = *puVar1;
          puVar6[-1] = uVar2;
          uVar2 = *puVar7;
          uVar3 = puVar7[1];
          puVar7 = puVar7 + 2;
          *puVar6 = uVar2;
          puVar6[1] = uVar3;
          puVar6 = puVar6 + 4;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      uVar4 = WinHvpHypercall(0x89,uVar4,uVar5,0,local_300);
      uVar8 = (ulonglong)local_300[0];
      *param_4 = *param_4 + uVar8;
      param_1 = param_1 - local_300[0];
      param_2 = param_2 + uVar8 * 0x10;
      param_3 = param_3 + uVar8 * 2;
    } while ((uVar4 == 0) && (param_1 != 0));
  }
  return uVar4;
}



===== WinHvpAddVpToPartition @ 14000897c =====

undefined8 WinHvpAddVpToPartition(ulonglong *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined8 uVar4;
  
  piVar3 = WinHvpReferencePartition(*param_1);
  uVar4 = 0;
  if (piVar3 == (int *)0x0) {
    uVar4 = 0xc035000d;
  }
  else {
    uVar2 = ExAcquireSpinLockExclusive(piVar3 + 0x12);
    lVar1 = *(longlong *)(piVar3 + 0xe);
    *(ulonglong **)(lVar1 + (ulonglong)(uint)param_1[1] * 8) = param_1;
    piVar3[0x11] = piVar3[0x11] + 1;
    ExReleaseSpinLockExclusive(piVar3 + 0x12,CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar2));
    WinHvpDereferencePartition(piVar3);
  }
  return uVar4;
}



===== WinHvpDereferencePartitionData @ 140008a08 =====

void WinHvpDereferencePartitionData(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    ExFreePoolWithTag(param_1,0x5a764857);
  }
  return;
}



===== WinHvpRemoveVpFromPartition @ 140008a38 =====

void WinHvpRemoveVpFromPartition(ulonglong *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  int *piVar3;
  
  piVar3 = WinHvpReferencePartition(*param_1);
  uVar2 = ExAcquireSpinLockExclusive(piVar3 + 0x12);
  lVar1 = *(longlong *)(piVar3 + 0xe);
  *(undefined8 *)(lVar1 + (ulonglong)(uint)param_1[1] * 8) = 0;
  piVar3[0x11] = piVar3[0x11] + -1;
  ExReleaseSpinLockExclusive(piVar3 + 0x12,CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar2));
  WinHvpDereferencePartition(piVar3);
  return;
}



===== WinHvAddPhysicalMemory @ 140008ab0 =====

void WinHvAddPhysicalMemory
               (undefined1 param_1,ulonglong param_2,ulonglong param_3,longlong *param_4)

{
                    /* 0x8ab0  7  WinHvAddPhysicalMemory */
  WinHvpAddRemovePhysicalMemory('\x01',param_1,param_2,param_3,param_4);
  return;
}



===== WinHvForceSmallPages @ 140008ae0 =====

void WinHvForceSmallPages(void)

{
                    /* 0x8ae0  59  WinHvForceSmallPages */
  WinHvpMmFlags = WinHvpMmFlags & 0xffffffdf;
  return;
}



===== WinHvGetMemoryBalance @ 140008af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetMemoryBalance(undefined8 param_1,uint param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 *local_58 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x8af0  72  WinHvGetMemoryBalance */
  local_res8 = (undefined8 *)0x0;
  local_58[0] = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,local_58,(longlong)local_48);
  *local_res8 = param_1;
  WinHvpSetProximityDomain(local_res8 + 1,param_2);
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x4a);
  if (-1 < (int)uVar1) {
    *param_3 = *local_58[0];
    *param_4 = local_58[0][1];
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvHandleInsufficientRootMemory @ 140008bb0 =====

void WinHvHandleInsufficientRootMemory(ushort param_1,int *param_2)

{
  ulonglong uVar1;
  uint uVar2;
  
                    /* 0x8bb0  92  WinHvHandleInsufficientRootMemory */
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = param_1 | 0xc0350000;
  }
  uVar1 = WinHvGetNodeRequirement(param_2);
  WinHvLowMemoryPolicyAutoDeposit(0,0xffffffffffffffff,(uint)uVar1,uVar2);
  return;
}



===== WinHvRemovePhysicalMemory @ 140008c10 =====

void WinHvRemovePhysicalMemory
               (undefined1 param_1,ulonglong param_2,ulonglong param_3,longlong *param_4)

{
                    /* 0x8c10  144  WinHvRemovePhysicalMemory */
  WinHvpAddRemovePhysicalMemory('\0',param_1,param_2,param_3,param_4);
  return;
}



===== WinHvpInitializeRmSupport @ 140008c34 =====

int WinHvpInitializeRmSupport(void)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_48;
  wchar_t *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_48 = 0x440042;
  local_1c = 0;
  local_34 = 0;
  local_40 = L"\\KernelObjects\\HvlWithdrawAllowed";
  WinHvpMmFlags = 0x32;
  KeInitializeDpc(&DAT_1400150e0,WinHvpOnInsufficientMemoryDpcRoutine,0);
  DAT_140015120 = IoAllocateWorkItem(WinHvpHypervisorDriver);
  if (DAT_140015120 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    local_30 = 0;
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwOpenEvent(&local_res8,1,&local_38);
    if (-1 < iVar1) {
      local_res10 = 0;
      iVar1 = ObReferenceObjectByHandle(local_res8,1,0,0,&local_res10,0);
      WinHvpWithdrawAllowedEvent = local_res10;
      ZwClose(local_res8);
    }
  }
  return iVar1;
}



===== WinHvpOnInsufficientMemoryDpcRoutine @ 140008d60 =====

void WinHvpOnInsufficientMemoryDpcRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  IoQueueWorkItemEx(DAT_140015120,WinHvpOnInsufficientMemoryWorkItemRoutine,1,param_3);
  return;
}



===== WinHvpOnInsufficientMemoryWorkItemRoutine @ 140008da0 =====

void WinHvpOnInsufficientMemoryWorkItemRoutine(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res20;
  
  local_res20 = DAT_140015130;
  DAT_140015061 = 0;
  if (DAT_140015128 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = DAT_140015128 | 0xc0350000;
  }
  uVar2 = WinHvGetNodeRequirement((int *)&local_res20);
  uVar1 = WinHvLowMemoryPolicyAutoDeposit(0,0xffffffffffffffff,(uint)uVar2,uVar1);
  WinHvSetPartitionProperty(WinHvpCurrentPartitionId,0x5001e,(ulonglong)(~uVar1 >> 0x1f) | 2);
  return;
}



===== WinHvpOnRootInsufficientMemoryNotification @ 140008e2c =====

void WinHvpOnRootInsufficientMemoryNotification(longlong param_1)

{
  char cVar1;
  
  cVar1 = DAT_140015061;
  LOCK();
  DAT_140015061 = 1;
  UNLOCK();
  if (cVar1 == '\0') {
    DAT_140015128 = *(undefined2 *)(param_1 + 0x14);
    DAT_140015130 = *(undefined8 *)(param_1 + 0x18);
    KeInsertQueueDpc(&DAT_1400150e0,0,0);
  }
  return;
}



===== Feature_450263353__private_IsEnabledDeviceUsageNoInline @ 140008e7c =====

ulonglong Feature_450263353__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_450263353__private_featureState;
  if ((Feature_450263353__private_featureState & 0x10) == 0) {
    uVar1 = Feature_450263353__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_450263353__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_450263353__private_IsEnabledFallback @ 140008eb4 =====

void Feature_450263353__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140008ecc =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140008fa4 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140009088 =====

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
LAB_1400091e0:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_1400091d3:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400091e0;
      if (uVar5 == 5) goto LAB_1400091d3;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140009208 =====

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
              (0x3c2eb18,&Feature_450263353_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140009284 =====

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
                     (local_50,(uint *)&Feature_450263353__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3c2eb18,param_3 & 0xffffffff,1,&Feature_450263353__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3c2eb18);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140009370 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140009480 =====

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
  if ((Feature_450263353__private_featureState & 2) != 0) {
    uVar1 = Feature_450263353__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_450263353__private_featureState;
      if (bVar3) {
        Feature_450263353__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_450263353__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 1400094d4 =====

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



===== wil_details_IsEnabledFallback @ 140009634 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_450263353__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_450263353__private_featureState,(ulonglong)param_1,0x14000ebb8
                            );
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



===== wil_details_MapReportingKind @ 1400096c4 =====

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



===== WinHvConfigureProfiler @ 140009770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvConfigureProfiler(undefined2 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 *local_res10 [3];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x9770  25  WinHvConfigureProfiler */
  local_res10[0] = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(local_res10,(undefined8 *)0x0,(longlong)local_48);
  *local_res10[0] = 0;
  local_res10[0][1] = 0;
  local_res10[0][2] = 0;
  local_res10[0][3] = 0;
  local_res10[0][4] = 0;
  *(undefined4 *)local_res10[0] = 1;
  *(undefined2 *)(local_res10[0] + 1) = param_1;
  local_res10[0][2] = param_2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x6f);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvDeleteEventLogBuffer @ 140009800 =====

void WinHvDeleteEventLogBuffer(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x9800  38  WinHvDeleteEventLogBuffer */
  local_10 = 0;
  local_18 = param_1;
  local_14 = param_2;
  WinHvpFastHypercall(99,(undefined8 *)&local_18);
  return;
}



===== WinHvFinalizeEventLogBufferGroup @ 140009830 =====

void WinHvFinalizeEventLogBufferGroup(uint param_1)

{
  ulonglong local_18 [3];
  
                    /* 0x9830  55  WinHvFinalizeEventLogBufferGroup */
  local_18[1] = 0;
  local_18[0] = (ulonglong)param_1;
  WinHvpFastHypercall(0x61,local_18);
  return;
}



===== WinHvReleaseEventLogBuffer @ 140009860 =====

void WinHvReleaseEventLogBuffer(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x9860  141  WinHvReleaseEventLogBuffer */
  local_10 = 0;
  local_18 = param_1;
  local_14 = param_2;
  WinHvpFastHypercall(0x67,(undefined8 *)&local_18);
  return;
}



===== WinHvSetEventLogCompletedNotificationRoutine @ 140009890 =====

void WinHvSetEventLogCompletedNotificationRoutine(undefined8 param_1)

{
                    /* 0x9890  158  WinHvSetEventLogCompletedNotificationRoutine */
  WinHvpEventLogCompletedNotificationRoutine = param_1;
  return;
}



===== WinHvSetEventLogGranularSources @ 1400098a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetEventLogGranularSources
               (undefined4 param_1,undefined8 param_2,void *param_3,uint param_4,void *param_5,
               uint param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *local_res18;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x98a0  159  WinHvSetEventLogGranularSources */
  memset(local_58,0,0x40);
  local_res18 = (undefined4 *)0x0;
  if ((((param_3 == (void *)0x0) && (param_5 == (void *)0x0)) || (0x100 < param_4)) ||
     (0x100 < param_6)) {
    return 0xc000000d;
  }
  WinHvpSetupHypercall(&local_res18,(undefined8 *)0x0,(longlong)local_58);
  puVar1 = local_res18;
  memset(local_res18,0,0x220);
  *puVar1 = param_1;
  *(undefined8 *)(puVar1 + 2) = param_2;
  puVar3 = puVar1 + 4;
  if (param_3 == (void *)0x0) {
LAB_140009975:
    if (param_5 != (void *)0x0) {
      if (param_6 == 0) goto LAB_14000994b;
      *puVar3 = 0x1e00;
      *(short *)((longlong)puVar3 + 6) = (short)param_6;
      memmove(puVar3 + 2,param_5,(ulonglong)param_6);
      puVar1[1] = puVar1[1] + 1;
    }
    uVar2 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x66);
  }
  else {
    if (param_4 != 0) {
      *puVar3 = 0x1d00;
      *(short *)((longlong)puVar1 + 0x16) = (short)param_4;
      memmove(puVar1 + 6,param_3,(ulonglong)param_4);
      puVar1[1] = puVar1[1] + 1;
      puVar3 = puVar1 + 0x46;
      goto LAB_140009975;
    }
LAB_14000994b:
    uVar2 = 0xc000000d;
  }
  (*local_20)(local_58[0]);
  return uVar2;
}



===== WinHvSetEventLogGroupSources @ 1400099f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetEventLogGroupSources(undefined4 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *local_res10;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x99f0  160  WinHvSetEventLogGroupSources */
  local_res10 = (undefined4 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res10,(undefined8 *)0x0,(longlong)local_48);
  puVar1 = local_res10;
  memset(local_res10,0,0x220);
  *puVar1 = param_1;
  *(undefined8 *)(puVar1 + 2) = param_2;
  uVar2 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x66);
  (*local_10)(local_48[0]);
  return uVar2;
}



===== WinHvUnmapEventLogBuffer @ 140009a80 =====

void WinHvUnmapEventLogBuffer(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x9a80  189  WinHvUnmapEventLogBuffer */
  local_10 = 0xffffffffffffffff;
  local_18 = param_1;
  local_14 = param_2;
  WinHvpFastHypercall(0x65,(undefined8 *)&local_18);
  return;
}



===== WinHvConfigureSchedulerAssistNotifications @ 140009ab0 =====

ulonglong WinHvConfigureSchedulerAssistNotifications
                    (ulonglong param_1,uint param_2,char param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong local_18 [2];
  
                    /* 0x9ab0  26  WinHvConfigureSchedulerAssistNotifications */
  local_18[0] = 0;
  uVar3 = WinHvpReferenceVp(param_1,param_2,local_18);
  lVar2 = local_18[0];
  if (-1 < (int)uVar3) {
    lVar1 = local_18[0] + 0xb0;
    if (param_3 == '\0') {
      ExWaitForRundownProtectionRelease(lVar1);
      ExRundownCompleted(lVar1);
      *(undefined8 *)(lVar2 + 0xb8) = 0;
    }
    else {
      *(undefined8 *)(local_18[0] + 0xb8) = param_4;
      ExReInitializeRundownProtection();
    }
  }
  if (lVar2 != 0) {
    WinHvpDereferenceVp(lVar2);
  }
  return uVar3 & 0xffffffff;
}



===== WinHvCommitSecFwSvn @ 140009b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvCommitSecFwSvn(void)

{
  uint uVar1;
  int iVar2;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x9b60  22  WinHvCommitSecFwSvn */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  iVar2 = 0;
  while( true ) {
    if (local_48[0] == 0) {
      WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
      *local_res8 = 0;
      local_res8[1] = 0;
      local_res8[2] = 0;
      local_res8[3] = 0;
      *(undefined4 *)(local_res8 + 3) = 4;
    }
    WinHvpAcquireAsyncMessage(0);
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,7);
    if (local_10 == WinHvpReleaseFallbackBuffers) {
      WinHvpReleaseFallbackBuffers(local_48[0]);
      local_48[0] = 0;
    }
    if (uVar1 == 0xc0350079) break;
    WinHvpReleaseAsyncMessage(0);
    if ((uVar1 != 0xc035000b) && (uVar1 != 0xc0350075)) goto LAB_140009c47;
    uVar1 = WinHvpLowMemoryHandler((undefined *)0xffffffffffffffff,0x8000ffff,uVar1,2,iVar2,'\0');
    if ((int)uVar1 < 0) goto LAB_140009c47;
    iVar2 = iVar2 + 1;
  }
  uVar1 = WinHvpWaitForAsyncCall(0,(undefined8 *)0x0,(undefined4 *)0x0);
  WinHvpReleaseAsyncMessage(0);
LAB_140009c47:
  if (local_48[0] != 0) {
    (*local_10)();
  }
  return uVar1;
}



===== WinHvIssueNestedSnpPspRequests @ 140009c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvIssueNestedSnpPspRequests
               (undefined *param_1,uint param_2,undefined8 *param_3,uint param_4,void *param_5,
               uint *param_6,int *param_7)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int *piVar3;
  int *piVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint local_a8;
  int local_a4;
  int local_a0;
  uint local_98;
  undefined4 uStack_94;
  uint local_90;
  uint local_8c;
  undefined8 *local_88;
  undefined8 local_80;
  longlong local_78 [3];
  char local_60;
  code *local_40;
  
                    /* 0x9c80  99  WinHvIssueNestedSnpPspRequests */
  local_90 = 0;
  memset(local_78,0,0x40);
  uVar7 = 0;
  local_a8 = 0;
  puVar9 = (undefined8 *)0x0;
  local_80 = 0;
  local_88 = (undefined8 *)0x0;
  *param_6 = 0;
  local_a4 = 0;
  local_a0 = 0;
  if ((param_4 == 0) || (param_2 < 2)) {
    local_8c = param_4 + 7;
    uVar8 = local_8c & 0xfffffff8;
    if (uVar8 < 0xfb5) {
      piVar3 = WinHvpReferencePartition((ulonglong)param_1);
      if (piVar3 == (int *)0x0) {
        uVar6 = 0xc035000d;
      }
      else {
        uVar6 = 0;
        if (param_2 != 0) {
          do {
            if ((uVar6 != 0) || (local_a0 != 0)) break;
            if (local_78[0] == 0) {
              WinHvpSetupHypercall(&local_88,(undefined8 *)0x0,(longlong)local_78);
              *local_88 = param_1;
              puVar9 = local_88;
            }
            WinHvpAcquireAsyncMessage((longlong)piVar3);
            if (param_4 == 0) {
              uVar6 = 0x3c;
              if (param_2 - uVar7 < 0x3c) {
                uVar6 = param_2 - uVar7;
              }
              memmove(puVar9 + 1,(void *)((ulonglong)uVar7 * 0x44 + (longlong)param_3),
                      (ulonglong)uVar6 * 0x44);
              uVar6 = WinHvpRepPoolHypercall_CallViaMacro(local_78[0],0xf9,uVar6,&local_a8);
            }
            else {
              memmove(puVar9 + 1,param_5,(ulonglong)param_4);
              uVar5 = (ulonglong)(uVar8 + 8);
              uVar2 = param_3[1];
              *(undefined8 *)(uVar5 + (longlong)puVar9) = *param_3;
              ((undefined8 *)(uVar5 + (longlong)puVar9))[1] = uVar2;
              uVar2 = param_3[3];
              puVar1 = (undefined8 *)(uVar5 + 0x10 + (longlong)puVar9);
              *puVar1 = param_3[2];
              puVar1[1] = uVar2;
              uVar2 = param_3[5];
              puVar1 = (undefined8 *)(uVar5 + 0x20 + (longlong)puVar9);
              *puVar1 = param_3[4];
              puVar1[1] = uVar2;
              uVar2 = param_3[7];
              puVar1 = (undefined8 *)(uVar5 + 0x30 + (longlong)puVar9);
              *puVar1 = param_3[6];
              puVar1[1] = uVar2;
              *(undefined4 *)(uVar5 + 0x40 + (longlong)puVar9) = *(undefined4 *)(param_3 + 8);
              _local_98 = CONCAT44(1,(local_8c & 0xff8) << 0xe | 0xf9);
              uVar6 = WinHvpHypercallRoutine();
            }
            if (local_40 == WinHvpReleaseFallbackBuffers) {
              WinHvpReleaseFallbackBuffers(local_78[0]);
              local_78[0] = 0;
            }
            if (uVar6 == 0xc0350079) {
              uVar6 = WinHvpWaitForAsyncCall((longlong)piVar3,&local_80,&local_90);
              local_a8 = local_90;
              local_a0 = (int)local_80;
              WinHvpReleaseAsyncMessage((longlong)piVar3);
            }
            else {
              WinHvpReleaseAsyncMessage((longlong)piVar3);
              if (((uVar6 == 0xc0350075) || (uVar6 == 0xc035000b)) || (uVar6 + 0x3fcaff7f < 2)) {
                piVar4 = WinHvpReferencePartition((ulonglong)param_1);
                if (piVar4 == (int *)0x0) {
                  _local_98 = CONCAT44(uStack_94,0xffff);
                }
                else {
                  _local_98 = CONCAT44(uStack_94,piVar4[8]);
                  WinHvpDereferencePartition(piVar4);
                }
                uVar6 = WinHvpLowMemoryHandler(param_1,local_98,uVar6,0xf9,local_a4,local_60);
                local_a4 = local_a4 + 1;
              }
            }
            uVar7 = uVar7 + local_a8;
          } while (uVar7 < param_2);
        }
      }
      *param_6 = uVar7;
      *param_7 = local_a0;
      if (local_78[0] != 0) {
        (*local_40)();
      }
      if (piVar3 != (int *)0x0) {
        WinHvpDereferencePartition(piVar3);
      }
      return uVar6;
    }
  }
  return 0xc000000d;
}



===== HviGetHypervisorFeatures @ 140009f48 =====

/* WARNING: Removing unreachable block (ram,0x000140009f61) */

void HviGetHypervisorFeatures(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar4 == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    puVar1 = (undefined4 *)cpuid(0x40000003);
    uVar4 = puVar1[1];
    uVar2 = puVar1[2];
    uVar3 = puVar1[3];
    *(undefined4 *)param_1 = *puVar1;
    *(undefined4 *)((longlong)param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 1) = uVar3;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar2;
  }
  return;
}



===== HviIsAnyHypervisorPresent @ 140009f88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140009fbc) */
/* WARNING: Removing unreachable block (ram,0x000140009fab) */

undefined8 HviIsAnyHypervisorPresent(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = (ulonglong)*puVar1;
  uVar3 = 0;
  if ((int)puVar1[3] < 0) {
    puVar1 = (uint *)cpuid(0x40000001);
    uVar2 = (ulonglong)*puVar1;
    uVar3 = 0;
    if (*puVar1 != 0x766e6258) {
      uVar3 = 1;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== HviIsHypervisorMicrosoftCompatible @ 140009fe4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000a011) */

undefined4 HviIsHypervisorMicrosoftCompatible(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 == '\0') {
  }
  else {
    piVar1 = (int *)cpuid(0x40000001);
    local_28._0_4_ = *piVar1;
  }
  return CONCAT31((int3)((uint)(int)local_28 >> 8),(int)local_28 == 0x31237648);
}



===== _guard_check_icall @ 14000a050 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 14000a068 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000a08c =====

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



===== __chkstk @ 14000a0f2 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000a0f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== __cpu_features_init @ 14000a110 =====

/* WARNING: Removing unreachable block (ram,0x00014000a17a) */
/* WARNING: Removing unreachable block (ram,0x00014000a129) */
/* WARNING: Removing unreachable block (ram,0x00014000a11a) */

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



===== __security_check_cookie @ 14000a1e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000a220 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000a250 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000a250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000a280 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000a300 =====

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



===== memset @ 14000a600 =====

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



===== __memset_repmovs @ 14000a740 =====

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



===== __memset_query @ 14000a7c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000a840 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000a980 =====

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



===== __memset_spec_plain @ 14000aa00 =====

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



===== WinHvpProcessSignalPairMessage @ 14000b008 =====

void WinHvpProcessSignalPairMessage(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  byte bVar4;
  ulonglong uVar5;
  
  piVar3 = (int *)0x0;
  uVar5 = 0;
  if (*(char *)(param_1 + 4) != '\0') {
    do {
      uVar2 = *(ulonglong *)(param_1 + 8 + uVar5 * 8);
      uVar1 = *(uint *)(param_1 + 0xa0 + uVar5 * 4);
      if (((char)uVar5 == '\0') || (uVar2 != *(ulonglong *)(piVar3 + 2))) {
        if (piVar3 != (int *)0x0) {
          WinHvpDereferencePartition(piVar3);
        }
        piVar3 = WinHvpReferencePartition(uVar2);
      }
      WinHvpProcessDispatchSignal(*(longlong *)(*(longlong *)(piVar3 + 0xe) + (ulonglong)uVar1 * 8))
      ;
      bVar4 = (char)uVar5 + 1;
      uVar5 = (ulonglong)bVar4;
    } while (bVar4 < *(byte *)(param_1 + 4));
    WinHvpDereferencePartition(piVar3);
  }
  return;
}



===== WinHvCancelVpDispatchLoop @ 14000b0b0 =====

ulonglong WinHvCancelVpDispatchLoop(ulonglong param_1,uint param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong local_res18 [2];
  
                    /* 0xb0b0  18  WinHvCancelVpDispatchLoop */
  local_res18[0] = 0;
  if (WinHvpRootSchedulerActive == '\0') {
    uVar3 = 0xc0350006;
  }
  else {
    uVar2 = WinHvpReferenceVp(param_1,param_2,local_res18);
    lVar1 = local_res18[0];
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar2 = WinHvpTransitionVpDispatchLoopState(local_res18[0] + 0x10,2);
      uVar3 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        KeSetEvent(lVar1 + 0x98,0,0);
      }
    }
    if (lVar1 != 0) {
      WinHvpDereferenceVp(lVar1);
    }
  }
  return uVar3;
}



===== WinHvRunVpDispatchLoop @ 14000b140 =====

uint WinHvRunVpDispatchLoop(ulonglong param_1,uint param_2,uint param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined8 *puVar9;
  int iVar10;
  int local_38 [4];
  
                    /* 0xb140  150  WinHvRunVpDispatchLoop */
  puVar9 = (undefined8 *)0x0;
  local_38[0] = 0;
  if (WinHvpRootSchedulerActive == '\0') {
    uVar6 = 0xc0350006;
  }
  else {
    uVar6 = 0xc035000e;
    bVar3 = KeGetCurrentIrql();
    if (bVar3 < 2) {
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(&WinHvpPartitionArrayLock,0);
    }
    if (WinHvpPartitionArray != (int *)0x0) {
      iVar7 = *WinHvpPartitionArray + -1;
      iVar2 = 0;
      while (iVar10 = iVar2, iVar10 <= iVar7) {
        uVar5 = (uint)(iVar7 + iVar10) >> 1;
        if (*(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar5 * 4 + 2) == param_1) {
          piVar8 = *(int **)(WinHvpPartitionArray + (ulonglong)uVar5 * 4 + 4);
          if (piVar8 != (int *)0x0) {
            LOCK();
            *piVar8 = *piVar8 + 1;
            UNLOCK();
          }
          goto LAB_14000b1ff;
        }
        iVar2 = uVar5 + 1;
        if (param_1 <= *(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar5 * 4 + 2)) {
          iVar7 = uVar5 - 1;
          iVar2 = iVar10;
        }
      }
    }
    piVar8 = (int *)0x0;
LAB_14000b1ff:
    if (bVar3 < 2) {
      ExReleasePushLockSharedEx(&WinHvpPartitionArrayLock,0);
      KeLeaveCriticalRegion();
    }
    if (piVar8 == (int *)0x0) {
      uVar6 = 0xc035000d;
    }
    else {
      if (param_2 < (uint)piVar8[0x10]) {
        uVar4 = ExAcquireSpinLockShared(piVar8 + 0x12);
        puVar1 = *(undefined8 **)(*(longlong *)(piVar8 + 0xe) + (ulonglong)param_2 * 8);
        if (puVar1 != (undefined8 *)0x0) {
          LOCK();
          *(int *)((longlong)puVar1 + 0xc) = *(int *)((longlong)puVar1 + 0xc) + 1;
          UNLOCK();
          uVar6 = 0;
          puVar9 = puVar1;
        }
        ExReleaseSpinLockShared(piVar8 + 0x12,uVar4);
      }
      LOCK();
      iVar7 = *piVar8;
      *piVar8 = *piVar8 + -1;
      UNLOCK();
      if (iVar7 == 1) {
        WinHvpDeletePartitionObject((longlong)piVar8);
      }
      if ((-1 < (int)uVar6) &&
         (uVar6 = WinHvpVpDispatchLoop(puVar9,param_3,local_38), -1 < (int)uVar6)) {
        *param_4 = 0;
        if (local_38[0] == 4) {
          *(undefined4 *)param_4 = 1;
        }
        else if (local_38[0] == 5) {
          *(undefined4 *)param_4 = 2;
        }
        else if (local_38[0] == 6) {
          *(undefined4 *)param_4 = 3;
        }
      }
      if (puVar9 != (undefined8 *)0x0) {
        LOCK();
        piVar8 = (int *)((longlong)puVar9 + 0xc);
        iVar7 = *piVar8;
        *piVar8 = *piVar8 + -1;
        UNLOCK();
        if (iVar7 == 1) {
          ExFreePoolWithTag(puVar9,0x57764857);
        }
      }
    }
  }
  return uVar6;
}



===== WinHvpVpDispatchLoop @ 14000b360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000b99e) */
/* WARNING: Removing unreachable block (ram,0x00014000bb5a) */

uint WinHvpVpDispatchLoop(undefined8 *param_1,uint param_2,int *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined4 uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  void *pvVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 *puVar18;
  undefined1 auStackY_148 [32];
  char local_107;
  char local_106;
  char local_105;
  uint local_104;
  uint local_100;
  undefined8 local_f8;
  undefined4 local_f0 [2];
  void *local_e8;
  undefined8 local_e0;
  int *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  longlong local_b0;
  longlong local_a8;
  undefined8 local_a0;
  undefined8 *puStack_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  uint local_5c;
  undefined8 local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  puVar1 = param_1 + 2;
  local_d0 = 0;
  local_a8 = 0;
  local_f0[0] = 0;
  local_106 = '\0';
  local_a0 = 0;
  puStack_98 = (undefined8 *)0x0;
  local_105 = '\0';
  local_78 = 0;
  uStack_70 = 0;
  local_107 = '\0';
  local_e0 = 0;
  local_100 = param_2;
  local_d8 = param_3;
  local_b8 = param_1;
  cVar3 = ExTryAcquirePushLockExclusiveEx(puVar1,0);
  if (cVar3 == '\0') {
    return 0xc0350015;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 4);
  iVar7 = *(int *)(param_1 + 3);
  if (iVar7 == 1) {
    *(undefined4 *)(param_1 + 3) = 2;
  }
  else if ((iVar7 != 2) && (iVar7 != 3)) {
    KeReleaseSpinLock(param_1 + 4,uVar4);
    ExReleasePushLockExclusiveEx(puVar1,0);
    return 0xc0350015;
  }
  KeReleaseSpinLock(param_1 + 4,uVar4);
  uVar13 = 0;
  if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd);
    uVar11 = 1;
    param_1[7] = SystemReserved1[0xf];
    if (param_1[0xc] == -1) {
      uVar11 = 0xf;
    }
    uVar6 = KeSetActualBasePriorityThread(param_1[7],uVar11);
    *(undefined4 *)(param_1 + 0xe) = uVar6;
    KeReleaseSpinLock(param_1 + 0xd,uVar4);
  }
  *param_3 = 6;
  pvVar14 = SystemReserved1[0xf];
  local_a0 = param_1[0x12];
  puStack_98 = param_1 + 0x13;
  local_d0 = 0xffffffffffff3cb0;
  lVar9 = param_1[0x19];
  local_e8 = SystemReserved1[0xf];
  puVar18 = param_1;
  local_b0 = lVar9;
  if (*(char *)((longlong)param_1 + 0x1d) != '\0') {
    LOCK();
    *(int *)(lVar9 + 4) = *(int *)(lVar9 + 4) + -1;
    UNLOCK();
    *(undefined1 *)((longlong)param_1 + 0x1d) = 0;
  }
  while (*(int *)(param_1 + 3) != 4) {
    uVar12 = 0;
    local_104 = 0;
    if ((*(int *)(param_1 + 5) == 1) &&
       (local_104 = KeWaitForMultipleObjects(2,&local_a0), local_104 == 0)) {
      *(undefined4 *)(param_1 + 5) = 2;
    }
    cVar3 = PsIsThreadTerminating(pvVar14);
    if ((cVar3 != '\0') || (*(int *)(param_1 + 3) == 3)) {
      if ((param_2 & 1) != 0) {
        local_f0[0] = 1;
        local_78 = 0;
        uVar13 = WinHvSetVpRegisters(*puVar18,*(undefined4 *)(puVar18 + 1),0,1,local_f0,&local_78,
                                     &local_a8);
        if ((int)uVar13 < 0) break;
      }
      *local_d8 = 5;
      goto LAB_14000b9cb;
    }
    uVar13 = local_104;
    if (*(int *)(param_1 + 5) == 2) {
      if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
        local_c8 = 0;
        uVar4 = KfRaiseIrql(CONCAT71((uint7)(uint3)((uint)*(int *)(param_1 + 3) >> 8),2));
        lVar15 = (ulonglong)SystemReserved1[0x12]._4_4_ * 0x170 + DAT_140015150;
        uVar8 = KeQueryInterruptTimePrecise(&local_c8);
        if (param_1[9] == 0) {
          if (*(ulonglong *)(lVar15 + 0x10) <= uVar8) {
            lVar17 = (longlong)DAT_140015140;
            lVar16 = ((lVar17 >> 3) -
                     ((ulonglong)(*(longlong *)(lVar15 + 0x18) + *(longlong *)(lVar15 + 8) * 2) >> 3
                     )) + *(longlong *)(lVar15 + 8);
            if (lVar16 < 500) {
              lVar16 = 500;
            }
            else if (DAT_140015144 < lVar16) {
              lVar16 = (longlong)DAT_140015144;
            }
            *(longlong *)(lVar15 + 8) = lVar16;
            *(ulonglong *)(lVar15 + 0x10) = lVar17 + uVar8;
            *(undefined8 *)(lVar15 + 0x18) = 0;
          }
          param_1[9] = *(undefined8 *)(lVar15 + 8);
          if (param_1[0xc] == -1) {
            param_1[10] = uVar8;
          }
        }
        uVar11 = KeQueryTotalCycleTimeThread(SystemReserved1[0xf],0);
        param_1[0xb] = uVar11;
        KeLowerIrql(uVar4);
      }
      local_e0 = 0;
      uVar13 = param_2 & 1 | 2;
      KePrepareToDispatchVirtualProcessor
                (CONCAT31((uint3)(param_2 >> 9),(char)(param_2 >> 1)) & 0xffffff01,&local_107,
                 &local_106,&local_105);
      if (local_107 != '\0') {
        uVar13 = param_2 & 1 | 10;
      }
      if (local_106 != '\0') {
        uVar13 = uVar13 | 0x10;
      }
      if (local_105 != '\0') {
        uVar13 = uVar13 | 0x20;
      }
      local_68 = *puVar18;
      local_60 = *(undefined4 *)(puVar18 + 1);
      local_58 = param_1[9];
      lVar15 = param_1[0x18];
      local_50 = local_e0;
      local_f8 = 0x100c2;
      local_88 = 0;
      uStack_80 = 0;
      if (lVar15 != 0) {
        *(undefined1 *)(lVar15 + 0x41) = 1;
      }
      local_5c = uVar13;
      uVar5 = HvlInvokeFastExtendedHypercall(0x100c2);
      if (lVar15 != 0) {
        *(undefined1 *)(lVar15 + 0x41) = 0;
      }
      if (uVar5 == 0) {
        *(undefined4 *)(param_1 + 5) = (undefined4)local_88;
        *(undefined4 *)((longlong)param_1 + 0x2c) = local_88._4_4_;
        local_f8 = (ulonglong)local_f8._4_4_ << 0x20;
        local_104 = 0;
      }
      else {
        local_104 = uVar5 | 0xc0350000;
        local_f8 = CONCAT44(local_f8._4_4_,(uint)uVar5) | 0xc0350000;
      }
      if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
        local_c0 = 0;
        uVar4 = KfRaiseIrql(2);
        lVar9 = KeQueryTotalCycleTimeThread(SystemReserved1[0xf]);
        uVar8 = (lVar9 - param_1[0xb]) * 10;
        uVar10 = uVar8 / DAT_140015138;
        uVar8 = uVar8 % DAT_140015138;
        if (*(int *)((longlong)param_1 + 0x2c) - 7U < 2) {
LAB_14000bac5:
          param_1[9] = 0;
        }
        else if (uVar10 != 0) {
          uVar8 = param_1[9];
          if (uVar8 < uVar10 + 500) goto LAB_14000bac5;
          uVar8 = uVar8 - uVar10;
          param_1[9] = uVar8;
        }
        uVar8 = KeQueryInterruptTimePrecise(&local_c0,uVar8);
        lVar9 = (ulonglong)SystemReserved1[0x12]._4_4_ * 0x170 + DAT_140015150;
        iVar7 = KeQueryPriorityThread(SystemReserved1[0xf]);
        if (iVar7 == 0xf) {
          if (uVar8 <= *(ulonglong *)(lVar9 + 0x10)) {
            *(longlong *)(lVar9 + 0x18) = *(longlong *)(lVar9 + 0x18) + uVar10;
            goto LAB_14000b7e7;
          }
LAB_14000b7f0:
          lVar16 = (longlong)DAT_140015140;
          lVar15 = ((lVar16 >> 3) -
                   ((ulonglong)(*(longlong *)(lVar9 + 0x18) + *(longlong *)(lVar9 + 8) * 2) >> 3)) +
                   *(longlong *)(lVar9 + 8);
          if (lVar15 < 500) {
            lVar15 = 500;
          }
          else if (DAT_140015144 < lVar15) {
            lVar15 = (longlong)DAT_140015144;
          }
          *(longlong *)(lVar9 + 8) = lVar15;
          *(ulonglong *)(lVar9 + 0x10) = lVar16 + uVar8;
          *(ulonglong *)(lVar9 + 0x18) = uVar10;
        }
        else {
LAB_14000b7e7:
          uVar10 = 0;
          if (*(ulonglong *)(lVar9 + 0x10) <= uVar8) goto LAB_14000b7f0;
        }
        KeLowerIrql(uVar4);
        puVar18 = local_b8;
        lVar9 = local_b0;
        param_2 = local_100;
      }
      uVar13 = local_104;
      param_2 = param_2 & 0xfffffffe;
      local_100 = param_2;
      if ((int)local_f8 < 0) {
        if ((int)local_f8 != -0x3fcafff9) break;
        *(undefined4 *)(param_1 + 5) = 2;
        *(undefined4 *)((longlong)param_1 + 0x2c) = 5;
        if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
          if (param_1[0xc] == -1) {
            WinHvpThrottleVpDispatchThreadNoCheck((longlong)puVar1);
          }
          if ((param_1[0xc] != -1) && (iVar7 = ZwYieldExecution(), iVar7 < 0)) {
            KeDelayExecutionThread(0,0);
          }
        }
      }
      if ((param_1[9] == 0) && (*(char *)((longlong)param_1 + 0x1c) != '\0')) {
        if (param_1[0xc] == -1) {
          WinHvpThrottleVpDispatchThreadNoCheck((longlong)puVar1);
        }
        if (param_1[0xc] != -1) {
          ZwYieldExecution();
        }
      }
      pvVar14 = local_e8;
      iVar7 = *(int *)((longlong)param_1 + 0x2c);
      if (iVar7 == 2) {
        if ((param_1[0x18] != 0) && (*(int *)(param_1[0x18] + 0x14) != 0)) {
          LOCK();
          *(int *)(lVar9 + 4) = *(int *)(lVar9 + 4) + 1;
          UNLOCK();
          *(undefined1 *)((longlong)param_1 + 0x1d) = 1;
        }
        *local_d8 = 4;
        uVar12 = uVar13;
        goto LAB_14000b9cb;
      }
      if (iVar7 == 6) {
        cVar3 = ExAcquireRundownProtection(param_1 + 0x16);
        if (cVar3 != '\0') {
          (*DAT_140015190)(0,param_1[0x17]);
          ExReleaseRundownProtection(param_1 + 0x16);
        }
        pvVar14 = local_e8;
      }
      else if ((*(char *)((longlong)param_1 + 0x1c) == '\0') && (iVar7 == 7)) {
        Ordinal_6(3 - (uint)(*(int *)(lVar9 + 4) != 0));
      }
    }
  }
  uVar12 = uVar13;
LAB_14000b9cb:
  iVar7 = *local_d8;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 4);
  iVar2 = *(int *)(param_1 + 3);
  if (iVar2 == 1) {
    if (iVar7 == 1) {
      *(undefined4 *)(param_1 + 3) = 2;
    }
    else {
      *(uint *)(param_1 + 3) = (iVar7 != 2) + 3;
    }
    goto LAB_14000ba18;
  }
  if (iVar2 == 2) {
    if (1 < iVar7 - 4U) {
      if (iVar7 == 2) {
        *(undefined4 *)(param_1 + 3) = 3;
        goto LAB_14000ba18;
      }
LAB_14000bbec:
      if (iVar7 == 3) {
        *(undefined4 *)(param_1 + 3) = 4;
      }
      goto LAB_14000ba18;
    }
  }
  else {
    if (iVar2 != 3) goto LAB_14000ba18;
    if (1 < iVar7 - 4U) goto LAB_14000bbec;
  }
  *(undefined4 *)(param_1 + 3) = 1;
LAB_14000ba18:
  KeReleaseSpinLock(param_1 + 4,uVar4);
  if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd);
    param_1[7] = 0;
    KeSetActualBasePriorityThread(SystemReserved1[0xf],*(undefined4 *)(param_1 + 0xe));
    KeReleaseSpinLock(param_1 + 0xd,uVar4);
  }
  ExReleasePushLockExclusiveEx(puVar1,0);
  return uVar12;
}



===== WinHvpXSchedulerDpcRoutine @ 14000bca0 =====

void WinHvpXSchedulerDpcRoutine(undefined8 param_1,longlong param_2)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int *piVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong *puVar12;
  bool bVar13;
  
  if (*(int *)(param_2 + 0x70) == -0x7fffff00) {
    uVar11 = *(ulonglong *)(param_2 + 0x80);
    bVar3 = KeGetCurrentIrql();
    if (bVar3 < 2) {
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(&WinHvpPartitionArrayLock,0);
    }
    if (WinHvpPartitionArray != (int *)0x0) {
      iVar2 = 0;
      iVar5 = *WinHvpPartitionArray + -1;
      while (iVar10 = iVar2, iVar10 <= iVar5) {
        uVar4 = (uint)(iVar5 + iVar10) >> 1;
        if (*(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar4 * 4 + 2) == uVar11) {
          piVar9 = *(int **)(WinHvpPartitionArray + (ulonglong)uVar4 * 4 + 4);
          if (piVar9 != (int *)0x0) {
            LOCK();
            *piVar9 = *piVar9 + 1;
            UNLOCK();
          }
          goto LAB_14000bdaa;
        }
        iVar2 = uVar4 + 1;
        if (uVar11 <= *(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar4 * 4 + 2)) {
          iVar2 = iVar10;
          iVar5 = uVar4 - 1;
        }
      }
    }
    piVar9 = (int *)0x0;
LAB_14000bdaa:
    if (bVar3 < 2) {
      ExReleasePushLockSharedEx(&WinHvpPartitionArrayLock,0);
      KeLeaveCriticalRegion();
    }
    uVar11 = *(ulonglong *)(param_2 + 0x98);
    puVar12 = (ulonglong *)(param_2 + 0xa0);
    uVar8 = 0;
    bVar13 = uVar11 != 0;
    if (bVar13) {
      for (; (uVar11 >> uVar8 & 1) == 0; uVar8 = uVar8 + 1) {
      }
    }
    while (bVar13) {
      uVar7 = *puVar12;
      uVar11 = uVar11 ^ 1L << (uVar8 & 0x3f);
      uVar6 = 0;
      if (uVar7 != 0) {
        for (; (uVar7 >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
        }
      }
      if (uVar7 != 0) {
        do {
          uVar7 = uVar7 ^ 1L << (uVar6 & 0x3f);
          WinHvpProcessDispatchSignal
                    (*(longlong *)
                      (*(longlong *)(piVar9 + 0xe) +
                      (ulonglong)(uint)((int)uVar6 + (int)uVar8 * 0x40) * 8));
          uVar6 = 0;
          if (uVar7 != 0) {
            for (; (uVar7 >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
            }
          }
          uVar6 = uVar6 & 0xffffffff;
        } while (uVar7 != 0);
      }
      puVar12 = puVar12 + 1;
      uVar8 = 0;
      bVar13 = uVar11 != 0;
      if (bVar13) {
        for (; (uVar11 >> uVar8 & 1) == 0; uVar8 = uVar8 + 1) {
        }
      }
      uVar8 = uVar8 & 0xffffffff;
    }
    if (piVar9 != (int *)0x0) {
      WinHvpDereferencePartition(piVar9);
    }
  }
  else if (*(int *)(param_2 + 0x70) == -0x7ffffeff) {
    WinHvpProcessSignalPairMessage(param_2 + 0x80);
  }
  *(undefined1 *)(param_2 + 0x20) = 0;
  puVar1 = *(undefined4 **)(WinHvpVpDataPages + (ulonglong)SystemReserved1[0x12]._4_4_ * 0x30);
  *puVar1 = 0;
  LOCK();
  UNLOCK();
  if ((*(byte *)((longlong)puVar1 + 5) & 1) != 0) {
    WinHvpSetVpRegister64Self(0xa0014,0);
  }
  return;
}



===== WinHvpTransitionVpDispatchLoopState @ 14000bec0 =====

undefined8 WinHvpTransitionVpDispatchLoopState(longlong param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 1) {
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 8) = 2;
    }
    else {
      *(uint *)(param_1 + 8) = (param_2 != 2) + 3;
    }
    goto LAB_14000bf18;
  }
  if (iVar1 == 2) {
    if (1 < param_2 - 4U) {
      if (param_2 == 2) {
        *(undefined4 *)(param_1 + 8) = 3;
        goto LAB_14000bf18;
      }
LAB_14000bf71:
      if (param_2 == 3) {
        *(undefined4 *)(param_1 + 8) = 4;
      }
      goto LAB_14000bf18;
    }
  }
  else {
    if (iVar1 != 3) {
      if ((iVar1 != 4) || (2 < param_2 - 4U)) {
        uVar3 = 0xc0350015;
      }
      goto LAB_14000bf18;
    }
    if (1 < param_2 - 4U) goto LAB_14000bf71;
  }
  *(undefined4 *)(param_1 + 8) = 1;
LAB_14000bf18:
  KeReleaseSpinLock(param_1 + 0x10,uVar2);
  return uVar3;
}



===== WinHvCreatePartitionEx @ 14001a010 =====

ulonglong WinHvCreatePartitionEx
                    (undefined8 param_1,ulonglong param_2,uint param_3,undefined4 param_4,
                    undefined8 *param_5,undefined8 *param_6,ulonglong *param_7,undefined8 param_8,
                    undefined8 param_9,undefined8 param_10,undefined8 param_11)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  uint uVar6;
  undefined4 extraout_var;
  ulonglong uVar7;
  int *piVar8;
  int iVar9;
  longlong lVar10;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  int iVar15;
  ulonglong *puVar16;
  longlong lVar17;
  int *piVar18;
  ulonglong local_res10;
  longlong local_48 [4];
  
                    /* 0x1a010  33  WinHvCreatePartitionEx */
  local_48[2] = 0;
  local_48[1] = 0;
  local_res10 = 0;
  local_48[0] = 0;
  piVar18 = (int *)0x0;
  if ((param_2 & 0xfffffffffffffff8) != 0) {
    return 0xc000000d;
  }
  if ((param_2 & 4) == 0) {
    bVar5 = false;
    uVar6 = WinHvpCreatePartition(param_1,param_3,param_4,param_5,param_6,'\0',&local_res10);
    if ((int)uVar6 < 0) {
      return CONCAT44(extraout_var,uVar6);
    }
    uVar14 = local_res10;
  }
  else {
    uVar14 = *param_7;
    bVar5 = true;
    local_res10 = uVar14;
    uVar6 = WinHvGetMemoryBalance(uVar14,0x8000ffff,local_48 + 2,local_48 + 1);
    if ((int)uVar6 < 0) {
      return 0xc0350007;
    }
  }
  uVar7 = WinHvpCreatePartitionObject
                    (uVar14,param_3,param_8,param_9,param_10,param_11,(byte)param_1,(byte)param_2,
                     local_48);
  uVar13 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) {
    lVar12 = 0;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&WinHvpPartitionArrayLock,0);
    if (WinHvpPartitionArray == (int *)0x0) {
      iVar11 = 1;
    }
    else {
      iVar11 = *WinHvpPartitionArray + 1;
    }
    piVar8 = (int *)ExAllocatePool2(0x42,(longlong)iVar11 * 0x10 + 8,0x41764857);
    if (piVar8 != (int *)0x0) {
      *piVar8 = iVar11;
      if (iVar11 == 1) {
        iVar11 = 0;
      }
      else {
        iVar11 = iVar11 + -2;
        uVar7 = (ulonglong)iVar11;
        if (-1 < (longlong)uVar7) {
          puVar16 = (ulonglong *)(WinHvpPartitionArray + uVar7 * 4 + 2);
          do {
            if (*puVar16 < uVar14) break;
            iVar11 = iVar11 + -1;
            uVar7 = uVar7 - 1;
            puVar16 = puVar16 + -2;
          } while (uVar7 < 0x8000000000000000);
        }
        iVar11 = iVar11 + 1;
      }
      if (WinHvpPartitionArray != (int *)0x0) {
        iVar9 = 0;
        iVar15 = 0;
        lVar10 = 0;
        lVar12 = 0;
        do {
          lVar17 = lVar12;
          if (iVar9 == iVar11) {
LAB_14001a255:
            iVar9 = iVar9 + 1;
            lVar10 = lVar10 + 0x10;
          }
          else {
            iVar15 = iVar15 + 1;
            lVar17 = lVar12 + 0x10;
            if (*(longlong *)((longlong)WinHvpPartitionArray + lVar12 + 0x10) != 0) {
              uVar2 = *(undefined4 *)((longlong)WinHvpPartitionArray + lVar12 + 0xc);
              uVar3 = *(undefined4 *)((longlong)WinHvpPartitionArray + lVar12 + 0x10);
              uVar4 = *(undefined4 *)((longlong)WinHvpPartitionArray + lVar12 + 0x14);
              puVar1 = (undefined4 *)(lVar10 + 8 + (longlong)piVar8);
              *puVar1 = *(undefined4 *)((longlong)WinHvpPartitionArray + lVar12 + 8);
              puVar1[1] = uVar2;
              puVar1[2] = uVar3;
              puVar1[3] = uVar4;
              goto LAB_14001a255;
            }
            *piVar8 = *piVar8 + -1;
            iVar11 = iVar11 + -1;
          }
          lVar12 = lVar17;
        } while (iVar15 < *WinHvpPartitionArray);
      }
      *(ulonglong *)(piVar8 + (longlong)iVar11 * 4 + 2) = uVar14;
      *(longlong *)(piVar8 + (longlong)iVar11 * 4 + 4) = local_48[0];
      piVar18 = WinHvpPartitionArray;
      WinHvpPartitionArray = piVar8;
      ExReleasePushLockExclusiveEx(&WinHvpPartitionArrayLock,0);
      KeLeaveCriticalRegion();
      KeGenericCallDpc(WinHvpSynchronizationDpc,0);
      uVar13 = 0;
      *param_7 = uVar14;
      goto LAB_14001a2c1;
    }
    uVar13 = 0xc000009a;
    ExReleasePushLockExclusiveEx(&WinHvpPartitionArrayLock);
    KeLeaveCriticalRegion();
    lVar12 = local_48[0];
  }
  if (!bVar5) {
    WinHvFinalizePartition(uVar14);
    WinHvWithdrawAllMemoryWithCount(uVar14,(longlong *)0x0);
    WinHvpDeleteHvPartition(uVar14);
  }
  if (lVar12 != 0) {
    WinHvpDeletePartitionObject(lVar12);
  }
LAB_14001a2c1:
  if (piVar18 != (int *)0x0) {
    ExFreePoolWithTag(piVar18,0x41764857);
  }
  return uVar13;
}



===== WinHvSetPartitionProperty @ 14001a310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvSetPartitionProperty(ulonglong param_1,int param_2,undefined8 param_3)

{
  undefined1 auStackY_68 [32];
  ulonglong local_28;
  int local_20;
  undefined4 local_1c;
  undefined8 local_18;
  ulonglong local_10;
  
                    /* 0x1a310  167  WinHvSetPartitionProperty */
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_1c = 0;
  local_28 = param_1;
  local_20 = param_2;
  local_18 = param_3;
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0x45,param_2 == 0x5000c,&local_28,0x18,(void *)0x0,0)
  ;
  return;
}



===== WinHvpInitializeVpDispatchContext @ 14001a384 =====

ulonglong WinHvpInitializeVpDispatchContext(ulonglong *param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  param_1[2] = 0;
  KeInitializeSpinLock(param_1 + 4);
  *(undefined4 *)(param_1 + 5) = 2;
  *(undefined4 *)(param_1 + 3) = 1;
  KeInitializeEvent(param_1 + 0xf,1,0);
  param_1[0x12] = (ulonglong)(param_1 + 0xf);
  KeInitializeEvent(param_1 + 0x13,1,0);
  puVar1 = param_1 + 0x16;
  ExInitializeRundownProtection(puVar1);
  ExWaitForRundownProtectionRelease(puVar1);
  ExRundownCompleted(puVar1);
  uVar2 = WinHvpGetPartitionSchedulingProperties
                    (*param_1,(undefined1 *)((longlong)param_1 + 0x1c),
                     (undefined1 *)((longlong)param_1 + 0x1e));
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar2 = WinHvpReferencePartitionData(*param_1,param_1 + 0x19);
    uVar3 = uVar2 & 0xffffffff;
    if ((-1 < (int)uVar2) && (*(char *)((longlong)param_1 + 0x1c) != '\0')) {
      param_1[0xc] = 0xffffffffffffffff;
      uVar2 = ExAllocateTimer(WinHvpVpDispatchDeadlineTimerCallback,param_1 + 2,4);
      param_1[8] = uVar2;
      if (uVar2 == 0) {
        uVar3 = 0xc000009a;
      }
    }
  }
  return uVar3;
}



===== WinHvpCreateVpObject @ 14001a4ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WinHvpCreateVpObject(ulonglong param_1,undefined4 param_2,uint param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar3 = param_3 & 0x7fffffff;
  bVar4 = uVar3 < WinHvpNodeCount;
  local_28 = 0;
  uStack_20 = 0;
  if (bVar4) {
    KeSetSystemGroupAffinityThread(&WinHvpNodeToProcessorMask + (ulonglong)uVar3 * 0x10,&local_28);
  }
  puVar1 = (ulonglong *)ExAllocatePool2(0x40,0xd8,0x57764857);
  if (puVar1 == (ulonglong *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar1 = param_1;
    *(undefined4 *)(puVar1 + 1) = param_2;
    *(undefined4 *)((longlong)puVar1 + 0xc) = 1;
    uVar2 = WinHvpInitializeVpDispatchContext(puVar1);
    if (-1 < (int)uVar2) {
      uVar2 = WinHvpAddVpToPartition(puVar1);
      if (-1 < (int)uVar2) {
        uVar2 = 0;
        goto LAB_14001a571;
      }
    }
    uVar2 = uVar2 & 0xffffffff;
    WinHvpDereferenceVp((longlong)puVar1);
  }
LAB_14001a571:
  if (bVar4) {
    KeRevertToUserGroupAffinityThread(&local_28);
  }
  return uVar2;
}



===== WinHvpFreeStatsTableEntry @ 14001a5c0 =====

void WinHvpFreeStatsTableEntry(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0x51764857);
  return;
}



===== WinHvpAllocateStatsTableEntry @ 14001a5f0 =====

void WinHvpAllocateStatsTableEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x102,param_2,0x51764857);
  return;
}



===== WinHvpTerminateVpDispatchLoop @ 14001a61c =====

undefined8 WinHvpTerminateVpDispatchLoop(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong local_res8;
  longlong local_res10;
  
  local_res8 = 0;
  puVar1 = param_1 + 2;
  if (*(char *)((longlong)param_1 + 0x1e) == '\0') {
    uVar3 = WinHvpTransitionVpDispatchLoopState((longlong)puVar1,3);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    KeSetEvent(param_1 + 0x13,0,0);
  }
  uVar3 = WinHvpDisableVpDispatch(param_1);
  if (-1 < (int)uVar3) {
    if (*(char *)((longlong)param_1 + 0x1e) == '\0') {
      ExAcquirePushLockExclusiveEx(puVar1,0);
      ExReleasePushLockExclusiveEx(puVar1,0);
    }
    uVar3 = WinHvpGetHypervisorVpSignalCount(param_1,&local_res8);
    if (-1 < (int)uVar3) {
      plVar2 = param_1 + 6;
      LOCK();
      local_res10 = *plVar2;
      *plVar2 = *plVar2 - local_res8;
      UNLOCK();
      local_res10 = local_res10 - local_res8;
      while (local_res10 != 0) {
        ExBlockOnAddressPushLock(&DAT_140015148,plVar2,&local_res10,8,0);
        local_res10 = *plVar2;
      }
      ExWaitForRundownProtectionRelease(param_1 + 0x16);
      ExRundownCompleted(param_1 + 0x16);
      if (param_1[8] != 0) {
        ExDeleteTimer(param_1[8],0,0,0);
        param_1[8] = 0;
      }
      if ((int *)param_1[0x19] != (int *)0x0) {
        WinHvpDereferencePartitionData((int *)param_1[0x19]);
        param_1[0x19] = 0;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== WinHvpSlowHypercallRemote @ 14001a774 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpSlowHypercallRemote
               (undefined4 param_1,undefined4 param_2,longlong param_3,longlong param_4,
               uint *param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ulonglong local_18;
  
  cVar1 = ExAcquireRundownProtection(&DAT_1400150b8);
  uVar3 = 0;
  if (cVar1 == '\0') {
    uVar3 = 0xc0350008;
  }
  else {
    if (DAT_1400150c8 == (code *)0x0) {
      uVar3 = 0xc0350002;
    }
    else {
      local_18 = CONCAT44(param_2,param_1) & 0xfff0000ffff;
      uVar2 = (*DAT_1400150c8)(local_18,param_3,-(uint)(param_3 != 0) & 0x1000,param_4,
                               -(uint)(param_4 != 0) & 0x1000);
      if (param_5 != (uint *)0x0) {
        *param_5 = (int)uVar2 >> 0x10 & 0xffff;
      }
      if ((short)uVar2 != 0) {
        uVar3 = uVar2 & 0xffff | 0xc0350000;
      }
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar3;
}



===== WinHvMapGpaPages @ 14001a880 =====

void WinHvMapGpaPages(undefined *param_1,longlong param_2,uint param_3,ulonglong param_4,
                     ulonglong *param_5,longlong *param_6)

{
  bool bVar1;
  uint uVar2;
  
                    /* 0x1a880  108  WinHvMapGpaPages */
  bVar1 = (param_3 & 0x30000) == 0;
  if (bVar1) {
    uVar2 = 8;
  }
  else {
    uVar2 = 0;
    param_5 = (ulonglong *)0x0;
  }
  WinHvpMapGpaPages(param_1,param_2,param_4,param_3,param_5,uVar2,(uint)!bVar1,param_6);
  return;
}



===== WinHvMapGpaPagesFromMbpArray @ 14001a8e0 =====

void WinHvMapGpaPagesFromMbpArray
               (undefined *param_1,longlong param_2,uint param_3,ulonglong param_4,
               ulonglong *param_5,longlong *param_6)

{
  bool bVar1;
  uint uVar2;
  
                    /* 0x1a8e0  109  WinHvMapGpaPagesFromMbpArray */
  bVar1 = (param_3 & 0x30000) == 0;
  if (bVar1) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 0;
    param_5 = (ulonglong *)0x0;
  }
  WinHvpMapGpaPages(param_1,param_2,param_4,param_3,param_5,uVar2,(uint)!bVar1,param_6);
  return;
}



===== WinHvMapGpaPagesScanLargePages @ 14001a940 =====

void WinHvMapGpaPagesScanLargePages
               (undefined *param_1,longlong param_2,uint param_3,ulonglong param_4,
               ulonglong *param_5,longlong *param_6)

{
                    /* 0x1a940  112  WinHvMapGpaPagesScanLargePages */
  WinHvpMapGpaPages(param_1,param_2,param_4,param_3,param_5,8,1,param_6);
  return;
}



===== WinHvMapSparseGpaPages @ 14001a990 =====

uint WinHvMapSparseGpaPages
               (undefined *param_1,uint param_2,ulonglong param_3,void *param_4,longlong *param_5)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  longlong local_res8;
  undefined *local_38;
  ulonglong local_30;
  
                    /* 0x1a990  116  WinHvMapSparseGpaPages */
  local_res8 = 0;
  iVar3 = 0;
  local_30 = (ulonglong)param_2;
  *param_5 = 0;
  local_38 = param_1;
  while( true ) {
    uVar2 = WinHvpSpecialListRepHypercall
                      (0x6e,param_3,&local_38,0x10,(longlong *)0x0,0,param_4,0x10,(undefined *)0x0,
                       (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,&local_res8);
    lVar1 = local_res8;
    *param_5 = *param_5 + local_res8;
    if (-1 < (int)uVar2) {
      return uVar2;
    }
    if (((uVar2 == 0xc035000b) || (uVar2 == 0xc0350075)) || (uVar2 + 0x3fcaff7f < 2)) {
      uVar2 = WinHvpLowMemoryHandler(param_1,0x8000ffff,uVar2,0x6e,iVar3,'\0');
    }
    else if ((uVar2 == 0xc0350073) || (uVar2 + 0x3fcaff7d < 3)) {
      uVar2 = WinHvpCurrentPartitionLowMemoryHandler(uVar2,0x8000ffff);
    }
    if ((int)uVar2 < 0) break;
    param_3 = param_3 - lVar1;
    param_4 = (void *)((longlong)param_4 + lVar1 * 0x10);
    iVar3 = iVar3 + 1;
  }
  return uVar2;
}



===== DllUnload @ 14001ab20 =====

undefined8 DllUnload(void)

{
                    /* 0x1ab20  2  DllUnload */
  WinHvpUnInitialize();
  wil_UninitializeFeatureStaging();
  if (DAT_1400158f8 != 0) {
    ExFreePoolWithTag(DAT_1400158f8,0x55764857);
    DAT_1400158f8 = 0;
  }
  return 0;
}



===== WinHvpEnvInit @ 14001ab64 =====

void WinHvpEnvInit(void)

{
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0x1e001c;
  local_10 = L"\\Driver\\WinHvr";
  IoCreateDriver(&local_18,WinHvpHypervisorDriverInitialization);
  return;
}



===== WinHvpEnvUninit @ 14001aba4 =====

void WinHvpEnvUninit(void)

{
  if (WinHvpHypervisorDriver != 0) {
    IoDeleteDriver();
    WinHvpHypervisorDriver = 0;
  }
  if (WinHvpBlackbox != 0) {
    KeDeregisterBugCheckReasonCallback(WinHvpBlackbox + 0x408);
    ExFreePoolWithTag(WinHvpBlackbox,0x55764857);
    WinHvpBlackbox = 0;
  }
  return;
}



===== wil_UninitializeFeatureStaging @ 14001ac14 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14001ac6c =====

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
      goto LAB_14001acc9;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001acc9;
    }
  }
  uVar1 = 0x206;
LAB_14001acc9:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001acd4 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001ad8c =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14001adc4 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001ae46;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001ae46;
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
LAB_14001ae46:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001ae90 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001aef0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001af0c =====

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



===== WinHvpConnectToHypervisor @ 14001afc0 =====

int WinHvpConnectToHypervisor(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = HviIsAnyHypervisorPresent();
  if ((char)uVar3 != '\0') {
    uVar1 = HviIsHypervisorMicrosoftCompatible();
    if (((char)uVar1 == '\0') || (uVar3 = WinHvpCheckPartitionPrivileges(), (char)uVar3 == '\0')) {
      return -0x3fcaffe2;
    }
    if (WinHvpRunningLoopback == '\0') {
      iVar2 = WinHvpSetHypervisorInformation();
      if (iVar2 < 0) {
        return iVar2;
      }
      WinHvpConnected = 1;
      WinHvpRegisterInterruptCallback();
      return iVar2;
    }
  }
  return -0x3fcaf000;
}



===== WinHvpDisconnectFromHypervisor @ 14001b020 =====

void WinHvpDisconnectFromHypervisor(void)

{
  if (DAT_140015060 != '\0') {
    HvlUnregisterInterruptCallback(0,WinHvOnInterrupt);
    DAT_140015060 = '\0';
  }
  WinHvpConnected = 0;
  return;
}



===== WinHvpCleanupHypercallLookasideBuffer @ 14001b05c =====

void WinHvpCleanupHypercallLookasideBuffer(void)

{
  byte bVar1;
  ulonglong uVar2;
  
  if (WinHvpNodeToHypercallLookaside != 0) {
    uVar2 = 0;
    if (WinHvpNodeCount != 0) {
      do {
        ExDeleteNPagedLookasideList(uVar2 * 0x80 + WinHvpNodeToHypercallLookaside);
        bVar1 = (char)uVar2 + 1;
        uVar2 = (ulonglong)bVar1;
      } while (bVar1 < WinHvpNodeCount);
    }
    ExFreePoolWithTag(WinHvpNodeToHypercallLookaside,0x4c764857);
  }
  WinHvpNodeToHypercallLookaside = 0;
  WinHvpTeardownNodeInfo();
  if (WinHvpSratInfo != 0) {
    ExFreePoolWithTag(WinHvpSratInfo,0x47764857);
    WinHvpSratInfo = 0;
  }
  return;
}



===== WinHvpCleanupHypercallSupport @ 14001b0f8 =====

void WinHvpCleanupHypercallSupport(void)

{
  WinHvpCleanupHypercallLookasideBuffer();
  return;
}



===== WinHvpInitializeFallbackHypercallBuffers @ 14001b110 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WinHvpInitializeFallbackHypercallBuffers(void)

{
  KeInitializeSpinLock(&WinHvpFallbackSpinLock);
  DAT_140015040 = &WinHvpFallbackInputBuffer;
  _DAT_140015048 = MmGetPhysicalAddress();
  DAT_140015050 = &WinHvpFallbackOutputBuffer;
  _DAT_140015058 = MmGetPhysicalAddress();
  _DAT_140015b28 = 0;
  _DAT_140015b30 = 0;
  _WinHvpFallbackMutex = 1;
  KeInitializeEvent(&DAT_140015b38,1,0);
  DAT_140015010 = &WinHvpDispatchFallbackInputBuffer;
  DAT_140015020 = &WinHvpDispatchFallbackOutputBuffer;
  _DAT_140015018 = MmGetPhysicalAddress();
  _DAT_140015028 = MmGetPhysicalAddress(&WinHvpDispatchFallbackOutputBuffer);
  return 0;
}



===== WinHvpInitializeHypercallLookasideBuffer @ 14001b1f0 =====

undefined4 WinHvpInitializeHypercallLookasideBuffer(void)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  
  WinHvpNodeInfo = ExAllocatePool2(0x40,(ulonglong)WinHvpNodeCount * 0x28,0x46764857);
  if (WinHvpNodeInfo != 0) {
    if (WinHvpVmManagement != '\0') {
      WinHvpLoadProximityDomainInfo();
    }
    WinHvpNodeToHypercallLookaside =
         ExAllocatePool2(0x42,(ulonglong)WinHvpNodeCount << 7,0x4c764857);
    if (WinHvpNodeToHypercallLookaside != 0) {
      uVar5 = 0;
      if (WinHvpNodeCount == 0) {
        return 0;
      }
      uVar2 = 0;
      do {
        lVar3 = uVar5 * 0x80;
        ExInitializeNPagedLookasideList
                  (WinHvpNodeToHypercallLookaside + lVar3,WinHvpAllocateHypercallBuffer,
                   WinHvpFreeHypercallBuffer,0x200,0x30,uVar2,0);
        lVar1 = ExAllocateFromNPagedLookasideList(WinHvpNodeToHypercallLookaside + lVar3);
        if (lVar1 != 0) {
          ExFreeToNPagedLookasideList(WinHvpNodeToHypercallLookaside + lVar3,lVar1);
        }
        bVar4 = (char)uVar5 + 1;
        uVar5 = (ulonglong)bVar4;
        uVar2 = (uint)bVar4;
      } while (uVar2 < WinHvpNodeCount);
      return 0;
    }
    WinHvpTeardownNodeInfo();
  }
  return 0xc000009a;
}



===== WinHvAttachDevice @ 14001b340 =====

void WinHvAttachDevice(ulonglong param_1,undefined1 param_2,undefined8 param_3,undefined4 param_4,
                      undefined8 param_5,undefined4 param_6,undefined2 param_7)

{
  ulonglong local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined1 local_24;
  undefined2 local_23;
  undefined1 local_21;
  undefined8 local_20;
  undefined4 local_18;
  undefined2 local_14;
  undefined2 local_12;
  
                    /* 0x1b340  14  WinHvAttachDevice */
  local_23 = 0;
  local_21 = 0;
  local_12 = 0;
  local_20 = param_5;
  local_18 = param_6;
  local_14 = param_7;
  local_38 = param_1;
  local_30 = param_3;
  local_28 = param_4;
  local_24 = param_2;
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0x82,'\0',&local_38,0x28,(void *)0x0,0);
  return;
}



===== WinHvMapDeviceInterrupt @ 14001b3d0 =====

void WinHvMapDeviceInterrupt
               (ulonglong param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4,
               undefined8 *param_5)

{
  uint uVar1;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x1b3d0  105  WinHvMapDeviceInterrupt */
  local_58 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  memset(&local_50,0,0x48);
  local_28 = *param_4;
  uStack_20 = param_4[1];
  local_18 = param_4[2];
  uStack_10 = param_4[3];
  local_50 = param_1;
  local_48 = param_2;
  local_40 = param_3;
  uVar1 = WinHvpAllocatingHypercall(param_1,0x8000ffff,0x7c,'\0',&local_50,0x48,&local_88,0x38);
  if (-1 < (int)uVar1) {
    *param_5 = local_88;
    param_5[1] = uStack_80;
  }
  return;
}



===== WinHvReserveDeviceInterrupt @ 14001b4b0 =====

uint WinHvReserveDeviceInterrupt
               (ulonglong param_1,undefined8 param_2,undefined4 param_3,ulonglong param_4,
               undefined8 *param_5)

{
  uint uVar1;
  ulonglong local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
                    /* 0x1b4b0  146  WinHvReserveDeviceInterrupt */
  if (((param_4 & 4) == 0) || (param_5 != (undefined8 *)0x0)) {
    local_34 = 0;
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    if ((param_4 & 4) != 0) {
      local_28 = *param_5;
      uStack_20 = param_5[1];
    }
    local_48 = param_1;
    local_40 = param_2;
    local_38 = param_3;
    local_30 = param_4;
    uVar1 = WinHvpAllocatingHypercall(param_1,0x8000ffff,0xea,'\0',&local_48,0x38,(void *)0x0,0);
  }
  else {
    uVar1 = 0xc00000f3;
  }
  return uVar1;
}



===== WinHvRetargetDeviceInterrupt @ 14001b550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvRetargetDeviceInterrupt
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,void *param_4,uint param_5
               )

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 *local_res8;
  undefined8 local_48 [5];
  longlong local_20;
  code *local_10;
  
                    /* 0x1b550  149  WinHvRetargetDeviceInterrupt */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  local_res8[2] = 0;
  local_res8[3] = 0;
  local_res8[4] = 0;
  local_res8[5] = 0;
  local_res8[6] = 0;
  *local_res8 = param_1;
  local_res8[1] = param_2;
  uVar1 = param_3[1];
  local_res8[2] = *param_3;
  local_res8[3] = uVar1;
  memmove(local_res8 + 5,param_4,(ulonglong)param_5);
  uVar2 = WinHvpVariableHeaderHypercall(0x7e,param_5 - 0x10,*(undefined8 *)(local_20 + 0x18),0);
  (*local_10)(local_48[0]);
  return uVar2;
}



===== WinHvSetPhysicalDeviceProperty @ 14001b620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetPhysicalDeviceProperty
               (undefined8 param_1,undefined4 param_2,void *param_3,uint param_4)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 local_48 [5];
  longlong local_20;
  code *local_10;
  
                    /* 0x1b620  168  WinHvSetPhysicalDeviceProperty */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  memmove(local_res8 + 2,param_3,(ulonglong)param_4);
  uVar1 = WinHvpVariableHeaderHypercall(0xab,param_4,*(undefined8 *)(local_20 + 0x18),0);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvUnmapDeviceInterrupt @ 14001b6d0 =====

void WinHvUnmapDeviceInterrupt
               (ulonglong param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4)

{
  ulonglong local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1b6d0  188  WinHvUnmapDeviceInterrupt */
  local_28 = *param_3;
  uStack_20 = param_3[1];
  local_14 = 0;
  local_38 = param_1;
  local_30 = param_2;
  local_18 = param_4;
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0x7d,'\0',&local_38,0x28,(void *)0x0,0);
  return;
}



===== WinHvpPersistDevice @ 14001b730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpPersistDevice(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4
                        ,undefined4 param_5,undefined2 param_6)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 local_48 [7];
  code *local_10;
  
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  local_res8[2] = 0;
  local_res8[3] = 0;
  local_res8[4] = 0;
  *local_res8 = param_1;
  local_res8[1] = param_2;
  *(undefined4 *)(local_res8 + 2) = param_3;
  local_res8[3] = param_4;
  *(undefined4 *)(local_res8 + 4) = param_5;
  *(undefined2 *)((longlong)local_res8 + 0x24) = param_6;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,0xeb);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvpPersistDeviceInterrupt @ 14001b7f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpPersistDeviceInterrupt
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
               undefined8 param_5,undefined4 *param_6)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 *local_res8;
  undefined4 *local_res10;
  undefined8 local_58 [7];
  code *local_20;
  
  memset(local_58,0,0x40);
  local_res8 = (undefined8 *)0x0;
  local_res10 = (undefined4 *)0x0;
  WinHvpSetupHypercall(&local_res8,&local_res10,(longlong)local_58);
  *local_res8 = 0;
  local_res8[1] = 0;
  local_res8[2] = 0;
  local_res8[3] = 0;
  local_res8[4] = 0;
  local_res8[5] = 0;
  *local_res8 = param_1;
  local_res8[1] = param_2;
  uVar1 = param_3[1];
  local_res8[2] = *param_3;
  local_res8[3] = uVar1;
  *(undefined4 *)(local_res8 + 4) = param_4;
  local_res8[5] = param_5;
  uVar2 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_58,0xed);
  if (-1 < (int)uVar2) {
    *param_6 = *local_res10;
  }
  (*local_20)(local_58[0]);
  return uVar2;
}



===== WinHvpUnpersistDevice @ 14001b8d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpUnpersistDevice(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 local_48 [7];
  code *local_10;
  
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  local_res8[1] = param_2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,0xec);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvAllocatePartitionSintIndex @ 14001b950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WinHvAllocatePartitionSintIndex(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  
                    /* 0x1b950  9  WinHvAllocatePartitionSintIndex */
  local_48 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = 0;
  uStack_50 = 0;
  if (((char)param_2 == '\0') && ((byte)param_1 < 0x10)) {
    iVar2 = -0x3ffffff3;
  }
  else if (WinHvpConnected == '\0') {
    iVar2 = -0x3fcafffe;
  }
  else {
    iVar2 = -0x3fffff66;
    ExAcquireFastMutex(&WinHvpSynicChangeLock);
    for (uVar1 = 5; uVar1 < 0x10; uVar1 = uVar1 + 1) {
      if (*(int *)(&WinHvpGlobalSintVectors + (ulonglong)uVar1 * 4) == 0) {
        iVar2 = 0;
        uStack_50 = (ulonglong)(param_2 & 1) << 0x10 | (ulonglong)(param_1 & 0xff);
        local_58 = CONCAT44(local_58._4_4_,uVar1 + 0xa0000);
        if (param_1 == 0x30) {
          uStack_50 = uStack_50 | 0x80000;
        }
        KeGenericCallDpc(WinHvpAllocateSintDpcRoutine,&local_58);
        *(uint *)(&WinHvpGlobalSintVectors + (ulonglong)uVar1 * 4) = param_1;
        break;
      }
    }
    ExReleaseFastMutex(&WinHvpSynicChangeLock);
    if (-1 < iVar2) {
      *param_3 = uVar1;
    }
  }
  return iVar2;
}



===== WinHvAllocateSingleSintIndex @ 14001ba70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WinHvAllocateSingleSintIndex(uint param_1,byte param_2,uint *param_3,uint *param_4)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_c8 [32];
  byte local_a8;
  undefined4 local_a4;
  uint local_a0;
  ulonglong local_98;
  undefined8 *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 uStack_80;
  uint *local_78;
  uint *local_70;
  longlong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x1ba70  11  WinHvAllocateSingleSintIndex */
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar6 = 0;
  uStack_80 = 0;
  local_88 = 0;
  local_84 = 0;
  local_98 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((param_2 == 0) && ((byte)param_1 < 0x10)) {
    uVar6 = 0xc000000d;
  }
  else if (WinHvpConnected == '\0') {
    uVar6 = 0xc0350002;
  }
  else {
    local_90 = &local_58;
    bVar2 = false;
    uVar8 = 0x10;
    bVar1 = false;
    local_a8 = param_2;
    local_78 = param_3;
    local_70 = param_4;
    uVar4 = KeQueryActiveProcessorCountEx(0xffff);
    local_a0 = uVar4;
    RtlInitializeBitMap(&local_88,WinHvpSynicProcessorsBitmap,uVar4);
    ExAcquireFastMutex(&WinHvpSynicChangeLock);
    for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
      cVar3 = RtlTestBit(&local_88,uVar7);
      if (cVar3 != '\0') {
        local_a4 = 0;
        local_68 = 0;
        uStack_60 = 0;
        KeGetProcessorNumberFromIndex(uVar7,&local_a4);
        uStack_60 = CONCAT62(uStack_60._2_6_,(undefined2)local_a4);
        local_68 = 1L << (local_a4._2_1_ & 0x3f);
        KeSetSystemGroupAffinityThread(&local_68,local_90);
        bVar1 = true;
        local_90 = (undefined8 *)0x0;
        for (uVar8 = 5; uVar8 < 0x10; uVar8 = uVar8 + 1) {
          if (*(int *)(&WinHvpGlobalSintVectors + (ulonglong)uVar8 * 4) == 0) {
            iVar5 = WinHvpGetVpRegister64Self(uVar8 + 0xa0000,&local_98);
            if (iVar5 < 0) break;
            if (((local_98 >> 0x10 & 1) != 0) && ((char)local_98 == '\0')) {
              local_98 = (ulonglong)(local_a8 & 1) << 0x10 | (ulonglong)(param_1 & 0xff) |
                         local_98 & 0xfffffffffffeff00;
              if (param_1 == 0x30) {
                local_98 = local_98 | 0x80000;
              }
              iVar5 = WinHvpSetVpRegister64Self(uVar8 + 0xa0000,local_98);
              if (-1 < iVar5) {
                bVar2 = true;
                goto LAB_14001bc40;
              }
              break;
            }
          }
        }
        uVar4 = local_a0;
      }
    }
LAB_14001bc40:
    ExReleaseFastMutex(&WinHvpSynicChangeLock);
    if (bVar1) {
      KeRevertToUserGroupAffinityThread(&local_58);
    }
    if (bVar2) {
      *local_78 = uVar8;
      *local_70 = uVar7;
    }
    else {
      uVar6 = 0xc000009a;
    }
  }
  return uVar6;
}



===== WinHvFreePartitionSintIndex @ 14001bcb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvFreePartitionSintIndex(uint param_1)

{
  undefined1 auStack_48 [32];
  int local_28 [4];
  ulonglong local_18;
  
                    /* 0x1bcb0  61  WinHvFreePartitionSintIndex */
  if (param_1 < 0x10) {
    local_18 = __security_cookie ^ (ulonglong)auStack_48;
    local_28[2] = 0;
    local_28[0] = 0;
    local_28[1] = 0;
    if (WinHvpConnected != '\0') {
      ExAcquireFastMutex(&WinHvpSynicChangeLock);
      if (*(int *)(&WinHvpGlobalSintVectors + (ulonglong)param_1 * 4) != 0) {
        local_28[0] = param_1 + 0xa0000;
        local_28[2] = 0x10000;
        local_28[3] = 0;
        KeGenericCallDpc(WinHvpAllocateSintDpcRoutine,local_28);
        *(undefined4 *)(&WinHvpGlobalSintVectors + (ulonglong)param_1 * 4) = 0;
      }
      ExReleaseFastMutex(&WinHvpSynicChangeLock);
    }
  }
  return;
}



===== WinHvFreeSingleSintIndex @ 14001bd80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvFreeSingleSintIndex(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  longlong local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
                    /* 0x1bd80  63  WinHvFreeSingleSintIndex */
  if (param_1 < 0x10) {
    local_10 = __security_cookie ^ (ulonglong)auStack_58;
    local_20 = 0;
    uStack_18 = 0;
    if (WinHvpConnected != '\0') {
      local_38 = 0;
      local_30 = 0;
      uStack_28 = 0;
      iVar1 = KeGetProcessorNumberFromIndex(param_2,&local_38);
      uStack_28 = CONCAT62(uStack_28._2_6_,(undefined2)local_38);
      local_30 = 1L << (local_38._2_1_ & 0x3f);
      if (-1 < iVar1) {
        KeSetSystemGroupAffinityThread(&local_30,&local_20);
        WinHvpSetVpRegister64Self(param_1 + 0xa0000,0x10000);
        KeRevertToUserGroupAffinityThread(&local_20);
      }
    }
  }
  return;
}



===== WinHvSetSyntheticInterruptHandler @ 14001be40 =====

undefined8 WinHvSetSyntheticInterruptHandler(uint param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
                    /* 0x1be40  176  WinHvSetSyntheticInterruptHandler */
  uVar4 = (ulonglong)param_1;
  if (param_1 - 5 < 0xb) {
    if (WinHvpConnected == '\0') {
      return 0xc0350002;
    }
    bVar1 = KeGetCurrentIrql();
    if (bVar1 < 2) {
      lVar2 = *(longlong *)(&WinHvpGlobalSintInterceptHandlers + uVar4 * 8);
      do {
        if (lVar2 == 1) {
          return 0;
        }
        LOCK();
        lVar3 = *(longlong *)(&WinHvpGlobalSintInterceptHandlers + uVar4 * 8);
        if (lVar2 == lVar3) {
          *(longlong *)(&WinHvpGlobalSintInterceptHandlers + uVar4 * 8) = 1;
          lVar3 = lVar2;
        }
        else {
        }
        UNLOCK();
        bVar5 = lVar2 != lVar3;
        lVar2 = lVar3;
      } while (bVar5);
      if (lVar3 != 1) {
        KeGenericCallDpc(WinHvpSynchronizationDpc,0);
        LOCK();
        *(undefined8 *)(&WinHvpGlobalSintInterceptHandlerContexts + uVar4 * 8) = param_3;
        UNLOCK();
        LOCK();
        *(undefined8 *)(&WinHvpGlobalSintInterceptHandlers + uVar4 * 8) = param_2;
        UNLOCK();
      }
      return 0;
    }
  }
  return 0xc000000d;
}



===== WinHvpCleanupSynicSupport @ 14001bf00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpCleanupSynicSupport(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  longlong local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uStack_38 = 0;
  local_40 = 0;
  local_3c = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if (WinHvpSynicProcessorsBitmap != 0) {
    puVar5 = &local_20;
    bVar1 = false;
    uVar3 = KeQueryActiveProcessorCountEx(0xffff);
    RtlInitializeBitMap(&local_40,WinHvpSynicProcessorsBitmap,uVar3);
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        cVar2 = RtlTestBit(&local_40,uVar4);
        if (cVar2 != '\0') {
          local_48 = 0;
          local_30 = 0;
          uStack_28 = 0;
          KeGetProcessorNumberFromIndex(uVar4,&local_48);
          uStack_28 = CONCAT62(uStack_28._2_6_,(undefined2)local_48);
          local_30 = 1L << (local_48._2_1_ & 0x3f);
          KeSetSystemGroupAffinityThread(&local_30,puVar5);
          puVar5 = (undefined8 *)0x0;
          bVar1 = true;
          WinHvpDisableSynic();
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
      if (bVar1) {
        KeRevertToUserGroupAffinityThread(&local_20);
      }
    }
    RtlClearAllBits(&local_40);
    if (WinHvpEventRingControl != 0) {
      ExFreePoolWithTag(WinHvpEventRingControl,0x55764857);
      WinHvpEventRingControl = 0;
    }
    ExFreePoolWithTag(WinHvpSynicProcessorsBitmap,0x55764857);
    WinHvpSynicProcessorsBitmap = 0;
  }
  return;
}



===== WinHvpLoadProximityDomainInfo @ 14001c090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpLoadProximityDomainInfo(void)

{
  int *piVar1;
  byte bVar2;
  longlong lVar3;
  int iVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_468 [32];
  uint local_448 [2];
  undefined8 local_440;
  int local_438 [260];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_468;
  local_448[1] = 0;
  local_440 = 0;
  local_448[0] = 0;
  local_18 = 0;
  memset(local_438,0,0x408);
  iVar4 = ZwQuerySystemInformation(0x3c,local_438,0x408,local_448 + 1);
  if (iVar4 < 0) {
    return;
  }
  if (local_438[0] != 0) {
    local_1c = 0;
    local_28 = 0x41435049;
    local_24 = 1;
    local_20 = 0x54415253;
    iVar4 = ZwQuerySystemInformation(0x4c,&local_28,0x14,local_448);
    if (iVar4 != -0x3fffffdd) {
      if (iVar4 == -0x3ffffffe) {
        IoRegisterDriverReinitialization(WinHvpHypervisorDriver,WinHvDriverReinit,0);
        return;
      }
      return;
    }
    if (local_448[0] < 0x10) {
      return;
    }
    puVar5 = (undefined4 *)ExAllocatePool2(0x42,local_448[0],0x47764857);
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
    *puVar5 = 0x41435049;
    puVar5[1] = 1;
    puVar5[2] = 0x54415253;
    puVar5[3] = local_448[0] - 0x10;
    iVar4 = ZwQuerySystemInformation(0x4c,puVar5,local_448[0],local_448 + 1);
    if (iVar4 < 0) {
      ExFreePoolWithTag(puVar5,0x47764857);
      return;
    }
    pcVar8 = (char *)((longlong)puVar5 + (ulonglong)(uint)puVar5[5] + 0x10);
    if ((char *)((ulonglong)local_448[0] + (longlong)puVar5) < pcVar8) {
      pcVar8 = (char *)((ulonglong)local_448[0] + (longlong)puVar5);
    }
    WinHvpSratInfo = puVar5;
    for (pcVar7 = (char *)(puVar5 + 0x10); pcVar7 < pcVar8; pcVar7 = pcVar7 + (byte)pcVar7[1]) {
      if ((*pcVar7 == '\x01') && ((pcVar7[0x1c] & 1U) != 0)) {
        local_440 = CONCAT44(local_440._4_4_,(uint)(byte)pcVar7[2]);
        iVar4 = ZwQuerySystemInformation(0x65,&local_440,8);
        lVar3 = WinHvpNodeInfo;
        if ((-1 < iVar4) && (local_440._4_2_ < WinHvpNodeCount)) {
          uVar6 = (ulonglong)local_440._4_2_;
          bVar2 = pcVar7[2];
          piVar1 = (int *)(WinHvpNodeInfo + 8 + uVar6 * 0x28);
          *piVar1 = *piVar1 + 1;
          *(uint *)(lVar3 + uVar6 * 0x28) = (uint)bVar2;
          *(undefined1 *)(lVar3 + 4 + uVar6 * 0x28) = 1;
          if (*(longlong *)(lVar3 + 0x10 + uVar6 * 0x28) == 0) {
            *(char **)(lVar3 + 0x10 + uVar6 * 0x28) = pcVar7;
            *(char **)(lVar3 + 0x20 + uVar6 * 0x28) = pcVar7;
          }
          *(char **)(lVar3 + 0x18 + uVar6 * 0x28) = pcVar7;
        }
      }
    }
  }
  WinHvpQueriedNodeInfo = 1;
  return;
}



===== WinHvpTeardownNodeInfo @ 14001c300 =====

void WinHvpTeardownNodeInfo(void)

{
  if (WinHvpNodeInfo != 0) {
    ExFreePoolWithTag(WinHvpNodeInfo,0x46764857);
    WinHvpNodeInfo = 0;
  }
  return;
}



===== WinHvCreateVp @ 14001c340 =====

uint WinHvCreateVp(ulonglong param_1,uint param_2,undefined8 *param_3,uint param_4,
                  undefined8 param_5)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong local_38;
  uint local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  undefined1 local_29;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
                    /* 0x1c340  36  WinHvCreateVp */
  local_28 = *param_3;
  local_2c = 0;
  local_2a = 0;
  local_20 = 0;
  local_18 = 0;
  local_29 = *(undefined1 *)(param_3 + 1);
  local_38 = param_1;
  local_30 = param_4;
  WinHvpSetProximityDomain(&local_20,param_2);
  local_18 = param_5;
  uVar1 = WinHvpAllocatingHypercall(param_1,param_2,0x4e,'\0',&local_38,0x28,(void *)0x0,0);
  if ((-1 < (int)uVar1) && (WinHvpRootSchedulerActive != '\0')) {
    uVar2 = WinHvpCreateVpObject(param_1,param_4,param_2);
    uVar1 = (uint)uVar2;
    if ((int)uVar1 < 0) {
      WinHvDeleteVp(param_1,param_4);
    }
  }
  return uVar1;
}



===== WinHvDeleteVp @ 14001c430 =====

uint WinHvDeleteVp(ulonglong param_1,uint param_2)

{
  uint uVar1;
  ulonglong local_18;
  uint local_10;
  undefined4 local_c;
  
                    /* 0x1c430  43  WinHvDeleteVp */
  local_c = 0;
  if (WinHvpRootSchedulerActive != '\0') {
    WinHvpDeleteVpObject(param_1,param_2);
  }
  WinHvpInitializeFastHypercall(&local_18);
  local_18 = param_1;
  local_10 = param_2;
  ExAcquireFastMutex(&WinHvpStatsTableLock);
  uVar1 = WinHvpFastHypercall(0x4f,&local_18);
  WinHvpCompleteVpStatsDelete(uVar1,param_1,param_2);
  return uVar1;
}



===== WinHvGetVpCpuidValues @ 14001c4c0 =====

void WinHvGetVpCpuidValues
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4,
               void *param_5,void *param_6,longlong *param_7)

{
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  
                    /* 0x1c4c0  89  WinHvGetVpCpuidValues */
  local_18 = 0;
  local_28 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  WinHvpSpecialListRepHypercall
            (0xf4,param_4,&local_28,0x18,(longlong *)0x0,0,param_5,0x18,(undefined *)0x0,
             (undefined *)0x0,param_6,0x10,(undefined *)0x0,(longlong *)0x0,param_7);
  return;
}



===== WinHvMapUnmapVpStatePage @ 14001c560 =====

undefined8
WinHvMapUnmapVpStatePage
          (undefined8 param_1,undefined4 param_2,undefined2 param_3,char param_4,undefined8 *param_5
          )

{
  undefined8 uVar1;
  
  if (param_4 == '\0') {
    if (param_5 == (undefined8 *)0x0) {
      uVar1 = 0xc000000d;
    }
    else {
      uVar1 = WinHvMapVpStatePage(param_1,param_2,param_3,param_5);
    }
  }
  else {
    uVar1 = WinHvUnmapVpStatePage(param_1,param_2,param_3);
  }
  return uVar1;
}



===== WinHvMapVpStatePage2 @ 14001c5a0 =====

void WinHvMapVpStatePage2
               (undefined8 param_1,undefined4 param_2,undefined2 param_3,byte param_4,
               longlong param_5,undefined8 *param_6)

{
  byte bVar1;
  uint uVar2;
  undefined8 local_res8;
  undefined8 local_28;
  undefined4 local_20;
  undefined2 local_1c;
  byte local_1a;
  bool bStack_19;
  longlong local_18;
  
                    /* 0x1c5a0  119  WinHvMapVpStatePage2 */
  local_res8 = 0;
  *param_6 = 0xffffffffffffffff;
  bVar1 = 0;
  if (param_4 != 0xf) {
    bVar1 = param_4 & 0xf | 0x10;
  }
  local_18 = param_5;
  _local_1a = CONCAT11(param_5 != -1,bVar1);
  local_28 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  uVar2 = WinHvpAllocatingHypercall
                    (0xffffffffffffffff,0x8000ffff,0xe1,'\0',&local_28,0x18,&local_res8,8);
  if (-1 < (int)uVar2) {
    *param_6 = local_res8;
  }
  return;
}



===== WinHvStartVirtualProcessor @ 14001c670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvStartVirtualProcessor
               (undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 *local_res8;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x1c670  183  WinHvStartVirtualProcessor */
  local_res8 = (undefined8 *)0x0;
  memset(local_58,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_58);
  puVar2 = local_res8;
  memset(local_res8,0,0xf0);
  *puVar2 = param_1;
  *(undefined4 *)(puVar2 + 1) = param_2;
  *(undefined1 *)((longlong)puVar2 + 0xc) = param_3;
  uVar1 = param_4[1];
  puVar2[2] = *param_4;
  puVar2[3] = uVar1;
  uVar1 = param_4[3];
  puVar2[4] = param_4[2];
  puVar2[5] = uVar1;
  uVar1 = param_4[5];
  puVar2[6] = param_4[4];
  puVar2[7] = uVar1;
  uVar1 = param_4[7];
  puVar2[8] = param_4[6];
  puVar2[9] = uVar1;
  uVar1 = param_4[9];
  puVar2[10] = param_4[8];
  puVar2[0xb] = uVar1;
  uVar1 = param_4[0xb];
  puVar2[0xc] = param_4[10];
  puVar2[0xd] = uVar1;
  uVar1 = param_4[0xd];
  puVar2[0xe] = param_4[0xc];
  puVar2[0xf] = uVar1;
  uVar1 = param_4[0xf];
  puVar2[0x10] = param_4[0xe];
  puVar2[0x11] = uVar1;
  uVar1 = param_4[0x11];
  puVar2[0x12] = param_4[0x10];
  puVar2[0x13] = uVar1;
  uVar1 = param_4[0x13];
  puVar2[0x14] = param_4[0x12];
  puVar2[0x15] = uVar1;
  uVar1 = param_4[0x15];
  puVar2[0x16] = param_4[0x14];
  puVar2[0x17] = uVar1;
  uVar1 = param_4[0x17];
  puVar2[0x18] = param_4[0x16];
  puVar2[0x19] = uVar1;
  uVar1 = param_4[0x19];
  puVar2[0x1a] = param_4[0x18];
  puVar2[0x1b] = uVar1;
  uVar1 = param_4[0x1b];
  puVar2[0x1c] = param_4[0x1a];
  puVar2[0x1d] = uVar1;
  uVar3 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x99);
  (*local_20)(local_58[0]);
  return uVar3;
}



===== WinHvUnmapVpStatePage @ 14001c7a0 =====

void WinHvUnmapVpStatePage(undefined8 param_1,undefined4 param_2,undefined2 param_3)

{
                    /* 0x1c7a0  192  WinHvUnmapVpStatePage */
  WinHvUnmapVpStatePage2(param_1,param_2,param_3,0xf);
  return;
}



===== WinHvUnmapVpStatePage2 @ 14001c7c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvUnmapVpStatePage2(undefined8 param_1,undefined4 param_2,undefined2 param_3,byte param_4)

{
  uint uVar1;
  byte bVar2;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x1c7c0  193  WinHvUnmapVpStatePage2 */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = 0;
  local_res8[1] = 0;
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  *(undefined2 *)((longlong)local_res8 + 0xc) = param_3;
  bVar2 = *(byte *)((longlong)local_res8 + 0xe) & 0xef;
  *(byte *)((longlong)local_res8 + 0xe) = bVar2;
  if (param_4 != 0xf) {
    bVar2 = bVar2 | 0x10;
    *(byte *)((longlong)local_res8 + 0xe) = (bVar2 ^ param_4) & 0xf ^ bVar2;
  }
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xe2);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvpBuildVpIndexCache @ 14001c878 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WinHvpBuildVpIndexCache(void)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  puVar6 = &local_30;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  WinHvpProcessorToVpIndex =
       ExAllocatePool2(0x40,(ulonglong)WinHvpMaximumProcessorCount << 3,0x55764857);
  uVar3 = 0;
  if (WinHvpProcessorToVpIndex == 0) {
    uVar3 = 0xc000009a;
    WinHvpTeardownVpIndexCache();
  }
  else {
    uVar1 = KeQueryActiveProcessorCountEx(0xffff);
    uVar5 = 0;
    if (uVar1 != 0) {
      lVar4 = 0;
      lVar7 = 0;
      do {
        local_48 = 0;
        local_40 = 0;
        uStack_38 = 0;
        KeGetProcessorNumberFromIndex(uVar5,&local_48);
        uStack_38 = CONCAT62(uStack_38._2_6_,(undefined2)local_48);
        local_40 = 1L << (local_48._2_1_ & 0x3f);
        KeSetSystemGroupAffinityThread(&local_40,puVar6);
        puVar6 = (undefined8 *)0x0;
        uVar2 = WinHvGetCurrentVpIndex((undefined4 *)(WinHvpProcessorToVpIndex + lVar7));
        if (-1 < (int)uVar2) {
          *(undefined1 *)(lVar4 + 4 + WinHvpProcessorToVpIndex) = 1;
        }
        uVar5 = uVar5 + 1;
        lVar7 = lVar7 + 8;
        lVar4 = lVar4 + 8;
      } while (uVar5 < uVar1);
      KeRevertToUserGroupAffinityThread(&local_30);
    }
  }
  return uVar3;
}



===== WinHvpTeardownVpIndexCache @ 14001c9d4 =====

void WinHvpTeardownVpIndexCache(void)

{
  if (WinHvpProcessorToVpIndex != 0) {
    ExFreePoolWithTag(WinHvpProcessorToVpIndex,0x55764857);
    WinHvpProcessorToVpIndex = 0;
  }
  return;
}



===== WinHvReportPresentHypervisor @ 14001ca10 =====

undefined4 WinHvReportPresentHypervisor(void)

{
  undefined4 uVar1;
  
                    /* 0x1ca10  145  WinHvReportPresentHypervisor */
  uVar1 = WinHvpPostHypervisorInitializationStatus;
  if (WinHvpConnected == '\0') {
    uVar1 = 0xc0351000;
  }
  return uVar1;
}



===== WinHvpCreateBlackbox @ 14001ca30 =====

void WinHvpCreateBlackbox(void)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  
  if ((WinHvpBlackbox == 0) && (lVar2 = ExAllocatePool2(0x40,0x1000,0x55764857), lVar2 != 0)) {
    LOCK();
    bVar3 = WinHvpBlackbox == 0;
    if (bVar3) {
      WinHvpBlackbox = lVar2;
    }
    UNLOCK();
    if (bVar3) {
      *(undefined1 *)(WinHvpBlackbox + 0x434) = 0;
      iVar1 = KeInitializeTriageDumpDataArray(WinHvpBlackbox + 0x438,0xb0);
      if (iVar1 < 0) {
        ExFreePoolWithTag(WinHvpBlackbox,0x55764857);
        WinHvpBlackbox = 0;
      }
      else {
        KeRegisterBugCheckReasonCallback
                  (WinHvpBlackbox + 0x408,WinHvpTriageDumpBugcheckCallback,7,"WinHv");
        KeAddTriageDumpDataBlock(WinHvpBlackbox + 0x438,&WinHvpBlackbox,8);
        KeAddTriageDumpDataBlock(WinHvpBlackbox + 0x438,WinHvpBlackbox,0x1000);
      }
    }
    else {
      ExFreePoolWithTag(lVar2,0x55764857);
    }
  }
  return;
}



===== WinHvpUnInitialize @ 14001cb5c =====

void WinHvpUnInitialize(void)

{
  if (WinHvpDllLoadSuccessful != '\0') {
    if (WinHvpRunningLoopback == '\0') {
      if (DAT_140015060 != '\0') {
        HvlUnregisterInterruptCallback(0,WinHvOnInterrupt);
        DAT_140015060 = '\0';
      }
      WinHvpConnected = 0;
      WinHvpTeardownXSchedulerSupport();
      WinHvpTeardownLpIndexCache();
      WinHvpCleanupRmSupport();
      WinHvpCleanupSystemSupport();
      WinHvpFreeVmmCapabilities();
      WinHvpTeardownVpIndexCache();
      WinHvpCleanupSynicSupport();
      WinHvpCleanupPortIdSupport();
      WinHvpCleanupPartitionSupport();
      WinHvpCleanupHypercallLookasideBuffer();
      WinHvpFreeAllVpDataPages();
      WinHvpTeardownNumaMaps();
      WinHvpEnvUninit();
    }
    else {
      WinHvpCleanupHypercallLookasideBuffer();
      WinHvpTeardownNumaMaps();
    }
  }
  return;
}



===== WinHvCompleteIsolatedImport @ 14001cc00 =====

void WinHvCompleteIsolatedImport(ulonglong param_1,void *param_2)

{
  ulonglong local_d18;
  undefined1 local_d10 [3336];
  
                    /* 0x1cc00  24  WinHvCompleteIsolatedImport */
  memset(local_d10,0,0xd08);
  local_d18 = param_1;
  if (param_2 != (void *)0x0) {
    memmove(local_d10,param_2,0xd08);
  }
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0xf1,'\x01',&local_d18,0xd10,(void *)0x0,0);
  return;
}



===== WinHvCreatePartition @ 14001cc90 =====

void WinHvCreatePartition
               (undefined8 param_1,ulonglong param_2,uint param_3,undefined4 param_4,
               undefined8 *param_5,ulonglong *param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9,undefined8 param_10)

{
                    /* 0x1cc90  32  WinHvCreatePartition */
  WinHvCreatePartitionEx
            (param_1,param_2,param_3,param_4,param_5,(undefined8 *)0x0,param_6,param_7,param_8,
             param_9,param_10);
  return;
}



===== WinHvCreateServicePartition @ 14001cd00 =====

ulonglong WinHvCreateServicePartition(char *param_1,ulonglong *param_2)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar5 = 0;
  bVar2 = false;
  WinHvpCreateBlackbox();
  if (*param_1 == '\0') {
    uVar4 = *(ulonglong *)(param_1 + 8);
    uVar6 = *(undefined8 *)(param_1 + 0x10);
    pcVar7 = *(code **)(param_1 + 0x18);
    uVar8 = *(undefined8 *)(param_1 + 0x20);
  }
  else {
    uVar4 = *(ulonglong *)(param_1 + 0x10);
    pcVar7 = WinHvLowMemoryPolicyAutoDeposit;
    uVar6 = *(undefined8 *)(param_1 + 0x18);
    uVar8 = 0;
    uVar5 = 4;
    param_2 = (ulonglong *)(param_1 + 8);
  }
  uVar5 = WinHvCreatePartitionEx
                    (0x2480600,uVar5,0x80000000,0xfe00,&local_28,(undefined8 *)0x0,param_2,uVar4,
                     uVar6,pcVar7,uVar8);
  uVar4 = uVar5 & 0xffffffff;
  if ((-1 < (int)uVar5) && (*param_1 == '\0')) {
    uVar3 = WinHvInitializePartition((undefined *)*param_2);
    uVar4 = (ulonglong)uVar3;
    bVar2 = true;
  }
  if (WinHvpBlackbox != 0) {
    LOCK();
    puVar1 = (uint *)(WinHvpBlackbox + 4);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 + 1;
    UNLOCK();
    uVar5 = (ulonglong)(uVar3 & 0x3f);
    *(undefined4 *)(WinHvpBlackbox + 8 + uVar5 * 0x10) = 1;
    *(int *)(WinHvpBlackbox + 0xc + uVar5 * 0x10) = (int)uVar4;
    uVar6 = KeQueryPerformanceCounter(0);
    *(undefined8 *)(WinHvpBlackbox + 0x10 + uVar5 * 0x10) = uVar6;
  }
  if (((int)uVar4 < 0) && (bVar2)) {
    WinHvpDeletePartition(*param_2,WinHvWithdrawAllMemory);
  }
  return uVar4;
}



===== WinHvDeletePartition @ 14001ce60 =====

void WinHvDeletePartition(ulonglong param_1)

{
                    /* 0x1ce60  40  WinHvDeletePartition */
  WinHvpDeletePartition(param_1,WinHvWithdrawAllMemory);
  return;
}



===== WinHvDeleteServicePartition @ 14001ce80 =====

ulonglong WinHvDeleteServicePartition(char *param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  
  if (*param_1 == '\0') {
    if (*(undefined **)(param_1 + 0x10) == (undefined *)0x0) {
      uVar2 = 0xc000000d;
    }
    else {
      iVar1 = WinHvpDeletePartition(*(ulonglong *)(param_1 + 8),*(undefined **)(param_1 + 0x10));
      uVar2 = CONCAT44(extraout_var,iVar1);
    }
  }
  else {
    uVar2 = WinHvUnlinkPreExistingPartition(*(ulonglong *)(param_1 + 8));
  }
  return uVar2;
}



===== WinHvInitializePartition @ 14001cec0 =====

undefined4 WinHvInitializePartition(undefined *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  longlong lVar3;
  undefined *local_18;
  undefined8 local_10;
  
                    /* 0x1cec0  95  WinHvInitializePartition */
  local_10 = 0;
  piVar2 = WinHvpReferencePartition((ulonglong)param_1);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0xc035000d;
  }
  else {
    lVar3 = WinHvpInitializeFastHypercall(&local_18);
    local_18 = param_1;
    uVar1 = WinHvpFastAllocatingHypercall(param_1,*(uint *)(lVar3 + 0x20),0x41,&local_18);
    WinHvpDereferencePartition(piVar2);
  }
  return uVar1;
}



===== WinHvScrubPartition @ 14001cf30 =====

void WinHvScrubPartition(void)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x1cf30  152  WinHvScrubPartition */
  local_10 = 0;
  local_18 = WinHvpInitializeFastHypercall(&local_18);
  WinHvpFastHypercall(0x8d,&local_18);
  return;
}



===== WinHvUnlinkPreExistingPartition @ 14001cf70 =====

undefined8 WinHvUnlinkPreExistingPartition(ulonglong param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  
                    /* 0x1cf70  187  WinHvUnlinkPreExistingPartition */
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&WinHvpPartitionArrayLock,0);
  uVar5 = 0;
  if (WinHvpPartitionArray != (int *)0x0) {
    iVar3 = *WinHvpPartitionArray + -1;
    iVar1 = 0;
    while (iVar4 = iVar1, iVar4 <= iVar3) {
      uVar2 = (uint)(iVar3 + iVar4) >> 1;
      if (*(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar2 * 4 + 2) == param_1) {
        lVar6 = *(longlong *)(WinHvpPartitionArray + (ulonglong)uVar2 * 4 + 4);
        goto LAB_14001cfe9;
      }
      iVar1 = uVar2 + 1;
      if (param_1 <= *(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar2 * 4 + 2)) {
        iVar3 = uVar2 - 1;
        iVar1 = iVar4;
      }
    }
  }
  lVar6 = 0;
LAB_14001cfe9:
  ExReleasePushLockSharedEx(&WinHvpPartitionArrayLock,0);
  KeLeaveCriticalRegion();
  if ((lVar6 == 0) || (*(char *)(lVar6 + 6) == '\0')) {
    uVar5 = 0xc035000d;
  }
  else {
    WinHvpDeleteWinHvPartition(param_1);
  }
  return uVar5;
}



===== WinHvpCleanupPartitionSupport @ 14001d03c =====

void WinHvpCleanupPartitionSupport(void)

{
  longlong lVar1;
  
  lVar1 = WinHvpPartitionArray;
  if (WinHvpPartitionArray != 0) {
    WinHvpPartitionArray = 0;
    KeGenericCallDpc(WinHvpSynchronizationDpc,0);
    ExFreePoolWithTag(lVar1,0x41764857);
  }
  return;
}



===== WinHvpCreatePartition @ 14001d08c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpCreatePartition
               (undefined8 param_1,uint param_2,undefined4 param_3,undefined8 *param_4,
               undefined8 *param_5,char param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  undefined8 *local_88;
  undefined8 *local_80;
  longlong local_78 [3];
  char local_60;
  code *local_40;
  
  local_88 = (undefined8 *)0x0;
  local_80 = (undefined8 *)0x0;
  memset(local_78,0,0x40);
  local_res20 = 0;
  WinHvpSetProximityDomain(&local_res20,-(uint)(param_6 != '\0') & 0x80000000 | param_2);
  uVar1 = local_res20;
  local_60 = param_6;
  while( true ) {
    WinHvpSetupHypercall(&local_88,&local_80,(longlong)local_78);
    *local_88 = param_1;
    local_88[1] = uVar1;
    *(undefined4 *)(local_88 + 2) = param_3;
    if (param_4 == (undefined8 *)0x0) {
      local_88[3] = 0;
      local_88[4] = 0;
      local_88[5] = 0;
    }
    else {
      uVar3 = param_4[1];
      local_88[3] = *param_4;
      local_88[4] = uVar3;
      local_88[5] = param_4[2];
    }
    if (param_5 == (undefined8 *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *param_5;
    }
    local_88[6] = uVar3;
    uVar2 = WinHvpSimplePoolHypercall_CallViaMacro(local_78[0],0x40);
    uVar3 = *local_80;
    (*local_40)(local_78[0]);
    if (((uVar2 != 0xc0350075) && (uVar2 != 0xc035000b)) && (1 < uVar2 + 0x3fcaff7f)) break;
    uVar2 = WinHvpCurrentPartitionLowMemoryHandler(uVar2,param_2);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if (-1 < (int)uVar2) {
    *param_7 = uVar3;
  }
  return uVar2;
}



===== WinHvpCreatePartitionObject @ 14001d1ec =====

undefined8
WinHvpCreatePartitionObject
          (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,byte param_7,byte param_8,undefined8 *param_9)

{
  int *piVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = 0xc000009a;
  piVar1 = (int *)ExAllocatePool2(0x40,0x100,0x48764857);
  if (piVar1 == (int *)0x0) {
    return 0xc000009a;
  }
  *(undefined8 *)(piVar1 + 6) = param_4;
  *(undefined8 *)(piVar1 + 2) = param_1;
  *piVar1 = 1;
  *(undefined8 *)(piVar1 + 4) = param_3;
  piVar1[8] = param_2;
  *(undefined8 *)(piVar1 + 10) = param_5;
  *(undefined8 *)(piVar1 + 0xc) = param_6;
  *(byte *)((longlong)piVar1 + 6) = param_8 >> 2 & 1;
  KeInitializeDpc(piVar1 + 0x16,WinHvpOnCallCompletionDpcRoutine,0);
  KeInitializeEvent(piVar1 + 0x26,1,0);
  piVar1[0x2e] = 0;
  piVar1[0x2f] = 0;
  piVar1[0x30] = 0;
  piVar1[0x2c] = 1;
  KeInitializeEvent(piVar1 + 0x32,1,0);
  if (WinHvpRootSchedulerActive == '\0') {
    if ((param_8 & 2) != 0) {
      uVar4 = 0xc000000d;
      goto LAB_14001d3a0;
    }
  }
  else {
    *(undefined1 *)(piVar1 + 1) = WinHvpDfssEnabled;
    if ((param_8 & 1) != 0) {
      *(undefined1 *)(piVar1 + 1) = 0;
    }
    if ((param_8 & 2) != 0) {
      *(undefined2 *)(piVar1 + 1) = 0x100;
    }
    if ((param_7 & 0x80) != 0) {
      puVar2 = (undefined4 *)ExAllocatePool2(0x100,8,0x5a764857);
      *(undefined4 **)(piVar1 + 0x14) = puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_14001d3a0;
      *puVar2 = 1;
    }
    piVar1[0x10] = 0x800;
    lVar3 = ExAllocatePool2(0x40,0x4000,0x4e764857);
    *(longlong *)(piVar1 + 0xe) = lVar3;
    if (lVar3 == 0) {
LAB_14001d3a0:
      WinHvpDereferencePartition(piVar1);
      return uVar4;
    }
  }
  *param_9 = piVar1;
  return 0;
}



===== WinHvpDeletePartition @ 14001d3b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WinHvpDeletePartition(ulonglong param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = WinHvFinalizePartition(param_1);
  iVar2 = 0;
  if (iVar1 != -0x3fcafff9) {
    iVar2 = iVar1;
  }
  if (-1 < iVar2) {
    iVar2 = (*(code *)param_2)(param_1);
    if (-1 < iVar2) {
      iVar2 = WinHvpDeleteHvPartition(param_1);
      WinHvpDeleteWinHvPartition(param_1);
    }
  }
  return iVar2;
}



===== WinHvpDeleteWinHvPartition @ 14001d414 =====

void WinHvpDeleteWinHvPartition(ulonglong param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  longlong lVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  longlong lVar15;
  uint uVar16;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&WinHvpPartitionArrayLock,0);
  piVar9 = WinHvpPartitionArray;
  if (WinHvpPartitionArray != (int *)0x0) {
    iVar3 = 0;
    iVar10 = *WinHvpPartitionArray + -1;
    while (iVar13 = iVar3, iVar13 <= iVar10) {
      uVar8 = (uint)(iVar10 + iVar13) >> 1;
      if (*(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar8 * 4 + 2) == param_1) {
        piVar4 = *(int **)(WinHvpPartitionArray + (ulonglong)uVar8 * 4 + 4);
        if (piVar4 != (int *)0x0) {
          piVar12 = (int *)0x0;
          iVar3 = *WinHvpPartitionArray;
          if (iVar3 + -1 == 0) {
            WinHvpPartitionArray = (int *)0x0;
            piVar12 = piVar9;
          }
          else {
            piVar9 = (int *)ExAllocatePool2(0x42);
            if (piVar9 == (int *)0x0) {
              piVar9 = WinHvpPartitionArray + ((ulonglong)uVar8 + 1) * 4;
              piVar9[0] = 0;
              piVar9[1] = 0;
            }
            else {
              *piVar9 = iVar3 + -1;
              if (0 < *WinHvpPartitionArray) {
                lVar15 = 0;
                lVar11 = 0;
                uVar14 = 0;
                do {
                  uVar16 = uVar14 + 1;
                  if (uVar14 != uVar8) {
                    if (*(longlong *)(lVar11 + 0x10 + (longlong)WinHvpPartitionArray) == 0) {
                      *piVar9 = *piVar9 + -1;
                    }
                    else {
                      puVar1 = (undefined4 *)(lVar11 + 8 + (longlong)WinHvpPartitionArray);
                      uVar5 = puVar1[1];
                      uVar6 = puVar1[2];
                      uVar7 = puVar1[3];
                      puVar2 = (undefined4 *)(lVar15 + 8 + (longlong)piVar9);
                      *puVar2 = *puVar1;
                      puVar2[1] = uVar5;
                      puVar2[2] = uVar6;
                      puVar2[3] = uVar7;
                      lVar15 = lVar15 + 0x10;
                    }
                  }
                  lVar11 = lVar11 + 0x10;
                  uVar14 = uVar16;
                } while ((int)uVar16 < *WinHvpPartitionArray);
              }
              if (*piVar9 == 0) {
                ExFreePoolWithTag(piVar9,0x41764857);
                piVar9 = (int *)0x0;
              }
              piVar12 = WinHvpPartitionArray;
              WinHvpPartitionArray = piVar9;
            }
          }
          ExReleasePushLockExclusiveEx(&WinHvpPartitionArrayLock,0);
          KeLeaveCriticalRegion();
          KeGenericCallDpc(WinHvpSynchronizationDpc,0);
          WinHvpDereferencePartition(piVar4);
          if (piVar12 == (int *)0x0) {
            return;
          }
          ExFreePoolWithTag(piVar12,0x41764857);
          return;
        }
        break;
      }
      iVar3 = uVar8 + 1;
      if (param_1 <= *(ulonglong *)(WinHvpPartitionArray + (ulonglong)uVar8 * 4 + 2)) {
        iVar3 = iVar13;
        iVar10 = uVar8 - 1;
      }
    }
  }
  ExReleasePushLockExclusiveEx(&WinHvpPartitionArrayLock,0);
  KeLeaveCriticalRegion();
  return;
}



===== WinHvpSendRestartNotificationToAllPartitions @ 14001d60c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpSendRestartNotificationToAllPartitions(undefined4 param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_138 [32];
  undefined4 local_118 [2];
  undefined8 local_110;
  undefined4 local_108;
  undefined4 local_104;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  memset(local_118,0,0x100);
  local_108 = 0xffffffff;
  local_118[0] = 0x80000073;
  local_104 = param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&WinHvpPartitionArrayLock,0);
  if ((WinHvpPartitionArray != (int *)0x0) && (iVar2 = 0, 0 < *WinHvpPartitionArray)) {
    lVar3 = 0;
    do {
      lVar1 = *(longlong *)(lVar3 + 0x10 + (longlong)WinHvpPartitionArray);
      local_110 = *(undefined8 *)(lVar1 + 8);
      if (*(code **)(lVar1 + 0x10) != (code *)0x0) {
        (**(code **)(lVar1 + 0x10))(*(undefined8 *)(lVar1 + 0x18),local_118);
      }
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 0x10;
    } while (iVar2 < *WinHvpPartitionArray);
  }
  ExReleasePushLockSharedEx(&WinHvpPartitionArrayLock,0);
  KeLeaveCriticalRegion();
  return;
}



===== WinHvCancelRestorePartitionState @ 14001d710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvCancelRestorePartitionState(undefined8 param_1)

{
  uint uVar1;
  undefined8 *local_res8;
  int *local_res10 [3];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x1d710  16  WinHvCancelRestorePartitionState */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  local_res10[0] = (int *)0x0;
  WinHvpSetupHypercall(&local_res8,local_res10,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = 4;
  *(undefined4 *)((longlong)local_res8 + 0xc) = 0;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x5f);
  if ((-1 < (int)uVar1) && (*local_res10[0] != 0)) {
    uVar1 = 0xc0000001;
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvCancelSavePartitionState @ 14001d7a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvCancelSavePartitionState(undefined8 param_1)

{
  uint uVar1;
  undefined8 *local_res8;
  longlong local_res10 [3];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x1d7a0  17  WinHvCancelSavePartitionState */
  memset(local_48,0,0x40);
  local_res8 = (undefined8 *)0x0;
  local_res10[0] = 0;
  WinHvpSetupHypercall(&local_res8,local_res10,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = 4;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0x5e);
  if ((-1 < (int)uVar1) && (*(int *)(local_res10[0] + 4) != 0)) {
    uVar1 = 0xc0000001;
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvRestorePartitionState @ 14001d830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvRestorePartitionState
               (undefined8 param_1,undefined4 param_2,uint param_3,void *param_4,int *param_5,
               int *param_6)

{
  uint uVar1;
  int *piVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar5;
  size_t _Size;
  int iVar6;
  int *local_res8;
  undefined8 *local_78 [2];
  longlong local_68 [7];
  code *local_30;
  
  memset(local_68,0,0x40);
  local_78[0] = (undefined8 *)0x0;
  local_res8 = (int *)0x0;
  WinHvpSetupHypercall(local_78,&local_res8,(longlong)local_68);
  puVar3 = local_78[0];
  piVar2 = local_res8;
  iVar6 = 0;
  *local_res8 = 1;
  *local_78[0] = param_1;
  *(undefined4 *)(local_78[0] + 1) = param_2;
  do {
    _Size = 0xff0;
    if (param_3 < 0xff0) {
      _Size = (ulonglong)param_3;
    }
    *(int *)((longlong)puVar3 + 0xc) = (int)_Size;
    memmove(puVar3 + 2,param_4,_Size);
    uVar4 = WinHvpSimplePoolHypercall_CallViaMacro(local_68[0],0x5f);
    if ((int)uVar4 < 0) goto LAB_14001d917;
    uVar1 = *(uint *)((longlong)puVar3 + 0xc);
    uVar5 = piVar2[1];
    if (uVar1 < (uint)piVar2[1]) {
      piVar2[1] = uVar1;
      uVar5 = uVar1;
    }
    param_3 = param_3 - uVar5;
    param_4 = (void *)((longlong)param_4 + (ulonglong)uVar5);
    iVar6 = iVar6 + uVar5;
  } while ((*piVar2 == 1) &&
          (*(uint *)(puVar3 + 1) = *(uint *)(puVar3 + 1) & 0xfffffffe, param_3 != 0));
  *param_5 = iVar6;
  *param_6 = *piVar2;
LAB_14001d917:
  (*local_30)(local_68[0]);
  return uVar4;
}



===== WinHvSavePartitionState @ 14001d950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSavePartitionState
               (undefined8 param_1,undefined4 param_2,uint param_3,void *param_4,int *param_5,
               uint *param_6)

{
  undefined8 *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 *local_68;
  uint *local_60;
  longlong local_58 [7];
  code *local_20;
  
                    /* 0x1d950  151  WinHvSavePartitionState */
  memset(local_58,0,0x40);
  local_68 = (undefined8 *)0x0;
  local_60 = (uint *)0x0;
  if (param_3 < 0xff0) {
    uVar3 = 0xc0000023;
  }
  else {
    WinHvpSetupHypercall(&local_68,&local_60,(longlong)local_58);
    puVar2 = local_60;
    puVar1 = local_68;
    iVar5 = 0;
    *local_68 = param_1;
    uVar3 = 0;
    *(undefined4 *)(local_68 + 1) = param_2;
    while (0xfef < param_3) {
      uVar3 = WinHvpSimplePoolHypercall_CallViaMacro(local_58[0],0x5e);
      if ((int)uVar3 < 0) goto LAB_14001da35;
      uVar4 = *puVar2;
      if (0xff0 < uVar4) {
        *puVar2 = 0xff0;
        uVar4 = 0xff0;
      }
      memmove(param_4,puVar2 + 2,(ulonglong)uVar4);
      uVar4 = *puVar2;
      param_3 = param_3 - uVar4;
      param_4 = (void *)((longlong)param_4 + (ulonglong)uVar4);
      iVar5 = iVar5 + uVar4;
      if (puVar2[1] != 1) break;
      *(uint *)(puVar1 + 1) = *(uint *)(puVar1 + 1) & 0xfffffffe;
    }
    *param_5 = iVar5;
    *param_6 = puVar2[1];
LAB_14001da35:
    (*local_20)(local_58[0]);
  }
  return uVar3;
}



===== WinHvpCleanupSystemSupport @ 14001da6c =====

void WinHvpCleanupSystemSupport(void)

{
  if (DAT_1400150b0 != 0) {
    IoFreeWorkItem();
    DAT_1400150b0 = 0;
  }
  return;
}



===== WinHvpDepositNonMirroringMemory @ 14001daa0 =====

void WinHvpDepositNonMirroringMemory
               (undefined8 param_1,ulonglong param_2,uint param_3,longlong *param_4)

{
  WinHvpDepositMemory(param_1,param_2,param_3,'\0','\0',param_4);
  return;
}



===== WinHvpDestroySubsumedContext @ 14001dad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpDestroySubsumedContext(void)

{
  uint uVar1;
  longlong local_48 [7];
  code *local_10;
  
  memset(local_48,0,0x40);
  WinHvpSetupHypercall((undefined8 *)0x0,(undefined8 *)0x0,(longlong)local_48);
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xfd);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvpInitializeSystemSupport @ 14001db24 =====

uint WinHvpInitializeSystemSupport(void)

{
  KeInitializeDpc(&DAT_140015070,WinHvpRestartNotificationDpcRoutine,0);
  DAT_1400150b0 = IoAllocateWorkItem(WinHvpHypervisorDriver);
  return ~-(uint)(DAT_1400150b0 != 0) & 0xc000009a;
}



===== WinHvpRegisterSintIsr @ 14001db80 =====

undefined8 WinHvpRegisterSintIsr(undefined8 param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_2 == -0x7fffff8e) {
    WinHvpMirroringNotificationIsr = param_1;
    KeGenericCallDpc(WinHvpSynchronizationDpc,0);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WinHvpRestartNotificationWorkItemRoutine @ 14001dbd0 =====

void WinHvpRestartNotificationWorkItemRoutine(void)

{
  int iVar1;
  
  iVar1 = DAT_14001516c;
  DAT_140015170 = 0;
  LOCK();
  UNLOCK();
  LOCK();
  DAT_14001516c = 0;
  UNLOCK();
  if (iVar1 != 0) {
    WinHvpSendRestartNotificationToAllPartitions(0);
  }
  iVar1 = DAT_140015168;
  LOCK();
  DAT_140015168 = 0;
  UNLOCK();
  if (iVar1 != 0) {
    WinHvpSendRestartNotificationToAllPartitions(1);
  }
  return;
}



===== WinHvpSubsumeInitializedMemory @ 14001dc20 =====

void WinHvpSubsumeInitializedMemory
               (undefined8 param_1,ulonglong param_2,void *param_3,longlong *param_4)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = param_1;
  WinHvpSpecialListRepHypercall
            (0xfb,param_2,local_res8,8,(longlong *)0x0,0,param_3,8,(undefined *)0x0,(undefined *)0x0
             ,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,param_4);
  return;
}



===== WinHvpSubsumeVp @ 14001dc80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpSubsumeVp(undefined8 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xfc);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvCreateCpuGroup @ 14001dd00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvCreateCpuGroup(longlong param_1,uint param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  undefined8 *local_res20;
  undefined8 *local_88 [2];
  undefined8 local_78 [5];
  longlong local_50;
  code *local_40;
  
                    /* 0x1dd00  29  WinHvCreateCpuGroup */
  local_res20 = (undefined8 *)0x0;
  memset(local_78,0,0x40);
  local_88[0] = (undefined8 *)0x0;
  if (0x800 < param_2) {
    return 0xc000000d;
  }
  iVar9 = 0;
  do {
    WinHvpSetupHypercall(&local_res20,local_88,(longlong)local_78);
    puVar2 = local_res20;
    uVar8 = 0;
    *local_res20 = 0;
    local_res20[1] = 0;
    uVar6 = 0;
    while( true ) {
      uVar3 = (uint)uVar6;
      if (param_2 <= (uint)uVar8) break;
      uVar1 = *(uint *)(param_1 + uVar8 * 4);
      if (0x7ff < uVar1) {
LAB_14001de98:
        (*local_40)(local_78[0]);
        return 0xc000000d;
      }
      uVar5 = uVar1 >> 6;
      uVar7 = uVar6;
      if (uVar3 <= uVar5) {
        uVar7 = (ulonglong)(uVar5 + 1);
        if (0x1000 < uVar7 * 8 + 0x10) goto LAB_14001de98;
        memset(puVar2 + uVar6 + 2,0,(ulonglong)((uVar5 - uVar3) + 1) << 3);
      }
      puVar2[(ulonglong)uVar5 + 2] = puVar2[(ulonglong)uVar5 + 2] | 1L << (uVar1 & 0x3f);
      uVar8 = (ulonglong)((uint)uVar8 + 1);
      uVar6 = uVar7;
    }
    *puVar2 = 0;
    if (uVar3 == 0x40) {
      lVar4 = -1;
    }
    else {
      lVar4 = (1L << ((byte)uVar6 & 0x3f)) + -1;
    }
    puVar2[1] = lVar4;
    uVar3 = WinHvpVariableHeaderHypercall
                      (0xb5,uVar3 * 8 + 0x10,*(undefined8 *)(local_50 + 0x18),
                       *(undefined8 *)(local_50 + 0x28));
    if (-1 < (int)uVar3) {
      *param_3 = *local_88[0];
    }
    (*local_40)();
    if (((uVar3 != 0xc0350075) && (uVar3 != 0xc035000b)) && (1 < uVar3 + 0x3fcaff7f)) {
      return uVar3;
    }
    uVar3 = WinHvpLowMemoryHandler((undefined *)0xffffffffffffffff,0x8000ffff,uVar3,0xb5,iVar9,'\0')
    ;
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    iVar9 = iVar9 + 1;
  } while( true );
}



===== WinHvDeleteCpuGroup @ 14001ded0 =====

void WinHvDeleteCpuGroup(void)

{
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x1ded0  37  WinHvDeleteCpuGroup */
  local_10 = 0;
  local_18 = WinHvpInitializeFastHypercall(&local_18);
  WinHvpFastHypercall(0xb6,&local_18);
  return;
}



===== WinHvGetCpuGroupAffinity @ 14001df10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetCpuGroupAffinity(undefined8 param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong *puVar8;
  int *piVar9;
  undefined8 *local_res8;
  uint *local_res20;
  longlong local_68 [7];
  code *local_30;
  
                    /* 0x1df10  64  WinHvGetCpuGroupAffinity */
  uVar7 = 0;
  local_res8 = (undefined8 *)((ulonglong)local_res8 & 0xffffffff00000000);
  memset(local_68,0,0x40);
  local_res8 = (undefined8 *)0x0;
  local_res20 = (uint *)0x0;
  WinHvpSetupHypercall(&local_res8,&local_res20,(longlong)local_68);
  *local_res8 = param_1;
  uVar5 = WinHvpSimplePoolHypercall_CallViaMacro(local_68[0],0xb9);
  if (-1 < (int)uVar5) {
    uVar1 = *local_res20;
    if (*param_3 < uVar1) {
      uVar5 = 0xc0000023;
    }
    else {
      uVar6 = *(ulonglong *)(local_res20 + 4);
      puVar8 = (ulonglong *)(local_res20 + 6);
      while( true ) {
        uVar4 = 0;
        if (uVar6 != 0) {
          for (; (uVar6 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
          }
        }
        if (uVar6 == 0) break;
        uVar6 = uVar6 ^ 1L << (uVar4 & 0x3f);
        if (uVar7 < uVar1) {
          piVar9 = (int *)(param_2 + (ulonglong)uVar7 * 4);
          do {
            uVar2 = *puVar8;
            uVar3 = 0;
            if (uVar2 != 0) {
              for (; (uVar2 >> uVar3 & 1) == 0; uVar3 = uVar3 + 1) {
              }
            }
            if (uVar2 == 0) break;
            uVar7 = uVar7 + 1;
            *puVar8 = uVar2 ^ 1L << (uVar3 & 0x3f);
            *piVar9 = (int)uVar4 * 0x40 + (int)uVar3;
            piVar9 = piVar9 + 1;
          } while (uVar7 < uVar1);
        }
        puVar8 = puVar8 + 1;
      }
    }
    *param_3 = uVar1;
  }
  (*local_30)(local_68[0]);
  return uVar5;
}



===== WinHvGetCpuGroupProperty @ 14001e010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetCpuGroupProperty(undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 *local_res20;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x1e010  65  WinHvGetCpuGroupProperty */
  local_res8 = (undefined8 *)0x0;
  local_res20 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,&local_res20,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xb7);
  if (-1 < (int)uVar1) {
    *param_3 = *local_res20;
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvGetNextCpuGroup @ 14001e0b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetNextCpuGroup(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 *local_res18 [2];
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x1e0b0  74  WinHvGetNextCpuGroup */
  local_res8 = (undefined8 *)0x0;
  local_res18[0] = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,local_res18,(longlong)local_48);
  *local_res8 = param_1;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xba);
  if (-1 < (int)uVar1) {
    *param_2 = *local_res18[0];
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvGetNextCpuGroupPartition @ 14001e140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetNextCpuGroupPartition(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 *local_res8;
  undefined8 *local_res10;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x1e140  75  WinHvGetNextCpuGroupPartition */
  local_res8 = (undefined8 *)0x0;
  local_res10 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,&local_res10,(longlong)local_48);
  *local_res8 = param_1;
  local_res8[1] = param_2;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xbb);
  if (-1 < (int)uVar1) {
    *param_3 = *local_res10;
  }
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvSetCpuGroupAffinity @ 14001e1e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetCpuGroupAffinity(undefined8 param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined8 *local_res20;
  longlong local_78 [7];
  code *local_40;
  
                    /* 0x1e1e0  153  WinHvSetCpuGroupAffinity */
  memset(local_78,0,0x40);
  local_res20 = (undefined8 *)0x0;
  if (param_2 < 0x801) {
    iVar5 = 0;
    while( true ) {
      WinHvpSetupHypercall(&local_res20,(undefined8 *)0x0,(longlong)local_78);
      puVar2 = local_res20;
      memset(local_res20,0,0x118);
      uVar3 = 0;
      *puVar2 = param_1;
      uVar7 = 0;
      if (param_2 != 0) {
        puVar8 = param_3;
        do {
          uVar1 = *puVar8;
          if (0x7ff < uVar1) goto LAB_14001e379;
          uVar6 = uVar1 >> 6;
          if (uVar3 <= uVar6) {
            if (0x1000 < (uVar6 + 1) * 8 + 0x10) goto LAB_14001e379;
            memset(puVar2 + (ulonglong)uVar3 + 3,0,(ulonglong)((uVar6 - uVar3) + 1) << 3);
            uVar3 = uVar6 + 1;
          }
          uVar7 = uVar7 + 1;
          puVar8 = puVar8 + 1;
          puVar2[(ulonglong)uVar6 + 3] = puVar2[(ulonglong)uVar6 + 3] | 1L << (uVar1 & 0x3f);
        } while (uVar7 < param_2);
      }
      puVar2[1] = 0;
      if (uVar3 == 0x40) {
        lVar4 = -1;
      }
      else {
        lVar4 = (1L << ((byte)uVar3 & 0x3f)) + -1;
      }
      puVar2[2] = lVar4;
      uVar3 = WinHvpSimplePoolHypercall_CallViaMacro(local_78[0],0x115);
      if (((uVar3 != 0xc035000b) && (uVar3 != 0xc0350075)) && (1 < uVar3 + 0x3fcaff7f)) break;
      (*local_40)();
      local_78[0] = 0;
      uVar3 = WinHvpLowMemoryHandler
                        ((undefined *)0xffffffffffffffff,0x8000ffff,uVar3,0x115,iVar5,'\0');
      if ((int)uVar3 < 0) break;
      iVar5 = iVar5 + 1;
    }
  }
  else {
LAB_14001e379:
    uVar3 = 0xc000000d;
  }
  if (local_78[0] != 0) {
    (*local_40)();
  }
  return uVar3;
}



===== WinHvSetCpuGroupProperty @ 14001e3c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetCpuGroupProperty(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *local_res8;
  longlong local_48 [7];
  code *local_10;
  
                    /* 0x1e3c0  154  WinHvSetCpuGroupProperty */
  local_res8 = (undefined8 *)0x0;
  memset(local_48,0,0x40);
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_48);
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  local_res8[2] = param_3;
  uVar1 = WinHvpSimplePoolHypercall_CallViaMacro(local_48[0],0xb8);
  (*local_10)(local_48[0]);
  return uVar1;
}



===== WinHvUnregisterInterceptResult @ 14001e450 =====

void WinHvUnregisterInterceptResult
               (ulonglong param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  ulonglong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x1e450  194  WinHvUnregisterInterceptResult */
  local_18 = *param_4;
  uStack_10 = param_4[1];
  local_28 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0x92,'\0',&local_28,0x20,(void *)0x0,0);
  return;
}



===== WinHvSetLogicalProcessorProperty @ 14001e4b0 =====

void WinHvSetLogicalProcessorProperty(undefined4 param_1,undefined4 param_2,undefined8 *param_3)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
                    /* 0x1e4b0  164  WinHvSetLogicalProcessorProperty */
  local_30 = *param_3;
  uStack_28 = param_3[1];
  local_20 = param_3[2];
  uStack_18 = param_3[3];
  local_38 = param_1;
  local_34 = param_2;
  WinHvpAllocatingHypercall(1,0x8000ffff,0x79,'\0',&local_38,0x28,(void *)0x0,0);
  return;
}



===== WinHvpBuildLpIndexCache @ 14001e50c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvpBuildLpIndexCache(void)

{
  int iVar1;
  bool bVar2;
  longlong lVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined4 *local_b0;
  longlong local_a8;
  undefined4 *local_a0;
  longlong local_98 [7];
  code *local_60;
  longlong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  memset(local_98,0,0x40);
  local_b0 = (undefined4 *)0x0;
  local_a8 = 0;
  iVar1 = WinHvpMaximumProcessorCount * 8;
  bVar2 = false;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  WinHvpSetupHypercall(&local_b0,&local_a8,(longlong)local_98);
  WinHvpProcessorToLpIndex = ExAllocatePool2(0x40,iVar1,0x55764857);
  if (WinHvpProcessorToLpIndex == 0) {
    uVar6 = 0xc000009a;
LAB_14001e5b0:
    WinHvpTeardownLpIndexCache();
  }
  else {
    puVar10 = &local_48;
    uVar5 = KeQueryActiveProcessorCountEx(0xffff);
    lVar3 = local_a8;
    local_a0 = local_b0;
    uVar9 = 0;
    while (puVar4 = local_a0, uVar8 = (uint)uVar9, uVar8 < uVar5) {
      if (WinHvpCpuManagement == '\0') {
        uVar7 = WinHvNtProcessorToVpIndex
                          (uVar8,(undefined4 *)(WinHvpProcessorToLpIndex + uVar9 * 8));
        uVar6 = (uint)uVar7;
        if ((int)uVar6 < 0) goto LAB_14001e5b0;
      }
      else {
        local_b8 = 0;
        local_58 = 0;
        uStack_50 = 0;
        KeGetProcessorNumberFromIndex(uVar9,&local_b8);
        uStack_50 = CONCAT62(uStack_50._2_6_,(undefined2)local_b8);
        local_58 = 1L << (local_b8._2_1_ & 0x3f);
        KeSetSystemGroupAffinityThread(&local_58,puVar10);
        *puVar4 = 0xfffffffe;
        bVar2 = true;
        puVar10 = (undefined8 *)0x0;
        uVar6 = WinHvpSimplePoolHypercall_CallViaMacro(local_98[0],0x8a);
        if ((int)uVar6 < 0) goto LAB_14001e5b0;
        *(uint *)(uVar9 * 8 + WinHvpProcessorToLpIndex) = (uint)*(ushort *)(lVar3 + 4);
      }
      *(undefined1 *)(uVar9 * 8 + 4 + WinHvpProcessorToLpIndex) = 1;
      uVar9 = (ulonglong)(uVar8 + 1);
    }
    uVar6 = 0;
  }
  if (bVar2) {
    KeRevertToUserGroupAffinityThread(&local_48);
  }
  (*local_60)(local_98[0]);
  return uVar6;
}



===== WinHvpTeardownLpIndexCache @ 14001e710 =====

void WinHvpTeardownLpIndexCache(void)

{
  if (WinHvpProcessorToLpIndex != 0) {
    ExFreePoolWithTag(WinHvpProcessorToLpIndex,0x55764857);
    WinHvpProcessorToLpIndex = 0;
  }
  return;
}



===== WinHvAttachDeviceRemote @ 14001e750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvAttachDeviceRemote
               (undefined *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined2 param_6)

{
  undefined *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined *local_78;
  undefined8 *local_70;
  undefined8 local_68 [3];
  undefined1 local_50;
  code *local_30;
  
                    /* 0x1e750  15  WinHvAttachDeviceRemote */
  memset(local_68,0,0x40);
  local_70 = (undefined8 *)0x0;
  local_78 = (undefined *)0x0;
  cVar2 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar2 == '\0') {
    uVar3 = 0xc0350008;
  }
  else {
    uVar3 = WinHvpLookupRemotePartitionByLocalId(param_1,&local_78,(undefined8 *)0x0);
    puVar1 = local_78;
    if (-1 < (int)uVar3) {
      iVar4 = 0;
      local_50 = 1;
      while( true ) {
        WinHvpSetupHypercall(&local_70,(undefined8 *)0x0,(longlong)local_68);
        *local_70 = 0;
        local_70[1] = 0;
        local_70[2] = 0;
        local_70[3] = 0;
        local_70[4] = 0;
        *local_70 = puVar1;
        local_70[1] = param_2;
        *(undefined4 *)(local_70 + 2) = param_3;
        local_70[3] = param_4;
        *(undefined4 *)(local_70 + 4) = param_5;
        *(undefined2 *)((longlong)local_70 + 0x24) = param_6;
        uVar3 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_68,0x82);
        (*local_30)(local_68[0]);
        if (((uVar3 != 0xc0350075) && (uVar3 != 0xc035000b)) && (1 < uVar3 + 0x3fcaff7f)) break;
        uVar3 = WinHvpRemotePartitionLowMemoryHandler(puVar1,-0x7fff0001,uVar3,0x82,iVar4);
        if ((int)uVar3 < 0) break;
        iVar4 = iVar4 + 1;
      }
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar3;
}



===== WinHvCreatePartitionRemote @ 14001e8d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvCreatePartitionRemote
               (undefined *param_1,undefined8 param_2,uint param_3,undefined4 param_4,
               undefined8 *param_5,undefined8 *param_6,undefined *param_7,undefined8 param_8)

{
  undefined8 uVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined **ppuVar6;
  undefined1 *puVar7;
  int iVar8;
  code *pcVar9;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  
                    /* 0x1e8d0  34  WinHvCreatePartitionRemote */
  iVar8 = 0;
  cVar3 = ExAcquireRundownProtection(&DAT_1400150b8);
  puVar7 = auStackY_68;
  if (cVar3 == '\0') {
    uVar4 = 0xc0350008;
  }
  else {
    if (DAT_1400150d0 == (code *)0x0) {
      uVar4 = 0xc0350002;
    }
    else {
      puVar5 = (undefined8 *)ExAllocatePool2(0x42,0x78,0x59764857);
      if (puVar5 == (undefined8 *)0x0) {
        return 0xc000009a;
      }
      pcVar9 = WinHvpAutoDepositRemote;
      if (param_7 != (undefined *)0x0) {
        pcVar9 = (code *)param_7;
      }
      uVar4 = WinHvpCreatePartition
                        (param_2,param_3,param_4,param_5,(undefined8 *)0x0,'\x01',param_6);
      if ((int)uVar4 < 0) {
        ExFreePoolWithTag(puVar5,0x59764857);
        puVar7 = auStackY_68;
      }
      else {
        puVar5[2] = param_1;
        puVar5[3] = *param_6;
        *(uint *)(puVar5 + 4) = param_3;
        puVar5[5] = pcVar9;
        puVar5[6] = param_8;
        puVar5[8] = 0;
        *(undefined4 *)(puVar5 + 9) = 0;
        *(undefined4 *)(puVar5 + 7) = 1;
        KeInitializeEvent(puVar5 + 10,1,0);
        ExInitializeRundownProtection(puVar5 + 0xe);
        ExAcquireFastMutex(&WinHvpRemoteIdMapLock);
        puVar7 = auStackY_68;
        ppuVar6 = &WinHvpRemoteIdMap;
        if (*(undefined ***)(WinHvpRemoteIdMap + 8) != &WinHvpRemoteIdMap) {
          ppuVar6 = (undefined **)0x3;
          pcVar2 = (code *)swi(0x29);
          WinHvpRemoteIdMap = (undefined *)(*pcVar2)();
          puVar7 = auStackY_60;
        }
        puVar5[1] = ppuVar6;
        *puVar5 = WinHvpRemoteIdMap;
        *(undefined8 **)(WinHvpRemoteIdMap + 8) = puVar5;
        *(undefined8 *)(puVar7 + -8) = 0x14001ea4b;
        WinHvpRemoteIdMap = (undefined *)puVar5;
        ExReleaseFastMutex(&WinHvpRemoteIdMapLock);
        uVar4 = 0xc035000b;
        do {
          *(int *)(puVar7 + 0x28) = iVar8;
          *(undefined4 *)(puVar7 + 0x20) = 0x41;
          *(undefined8 *)(puVar7 + -8) = 0x14001ea77;
          uVar4 = (*pcVar9)(param_8,param_1,param_3,uVar4);
          if ((int)uVar4 < 0) goto LAB_14001eab8;
          uVar1 = *param_6;
          *(undefined8 *)(puVar7 + -8) = 0x14001ea85;
          uVar4 = WinHvpInitializePartitionRemote(uVar1);
          iVar8 = iVar8 + 1;
        } while ((((uVar4 == 0xc035000b) || (uVar4 == 0xc0350075)) || (uVar4 == 0xc0350081)) ||
                (uVar4 == 0xc0350082));
        uVar1 = *param_6;
        *(undefined8 *)(puVar7 + -8) = 0x14001eab2;
        uVar4 = (*DAT_1400150d0)(param_1,uVar1);
        if ((int)uVar4 < 0) {
LAB_14001eab8:
          *(undefined8 *)(puVar7 + -8) = 0x14001eac0;
          WinHvDeletePartitionRemote(param_1);
        }
      }
    }
    *(undefined8 *)(puVar7 + -8) = 0x14001eae4;
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar4;
}



===== WinHvDeletePartitionRemote @ 14001eb10 =====

uint WinHvDeletePartitionRemote(undefined *param_1)

{
  char cVar1;
  uint uVar2;
  undefined8 local_res10;
  longlong local_res18 [2];
  
                    /* 0x1eb10  41  WinHvDeletePartitionRemote */
  local_res10 = 0;
  cVar1 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar1 == '\0') {
    uVar2 = 0xc0350008;
  }
  else {
    uVar2 = WinHvpLookupRemotePartitionByLocalId(param_1,&local_res10,(undefined8 *)0x0);
    if (-1 < (int)uVar2) {
      WinHvpFinalizePartitionRemote(local_res10);
      local_res18[0] = 0;
      WinHvpWithdrawMemory(local_res10,0xffffffffffffffff,0x80000000,'\x01',local_res18);
      WinHvpDeletePartitionRemote(local_res10);
      WinHvpRemoveRemotePartitionId(param_1);
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar2;
}



===== WinHvDepositMemoryFromMdlRemote @ 14001ebd0 =====

uint WinHvDepositMemoryFromMdlRemote(undefined *param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  longlong local_res20;
  undefined8 local_28 [2];
  
                    /* 0x1ebd0  46  WinHvDepositMemoryFromMdlRemote */
  local_28[0] = 0;
  local_res20 = 0;
  cVar2 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar2 == '\0') {
    uVar3 = 0xc0350008;
  }
  else {
    uVar3 = WinHvpLookupRemotePartitionByLocalId(param_1,local_28,&local_res20);
    lVar1 = local_res20;
    if (-1 < (int)uVar3) {
      ExAcquireFastMutex(local_res20 + 0x38);
      uVar3 = WinHvpDepositMemoryFromMdl(local_28[0],param_2,'\x01','\0',param_3);
      ExReleaseFastMutex(lVar1 + 0x38);
      ExReleaseRundownProtection(lVar1 + 0x70);
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar3;
}



===== WinHvDetachDeviceRemote @ 14001ecb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvDetachDeviceRemote(undefined *param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  undefined8 *local_res18;
  undefined8 local_res20;
  undefined8 local_48 [3];
  undefined1 local_30;
  code *local_10;
  
                    /* 0x1ecb0  48  WinHvDetachDeviceRemote */
  memset(local_48,0,0x40);
  local_res18 = (undefined8 *)0x0;
  local_res20 = 0;
  cVar1 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar1 == '\0') {
    uVar2 = 0xc0350008;
  }
  else {
    uVar2 = WinHvpLookupRemotePartitionByLocalId(param_1,&local_res20,(undefined8 *)0x0);
    if (-1 < (int)uVar2) {
      local_30 = 1;
      WinHvpSetupHypercall(&local_res18,(undefined8 *)0x0,(longlong)local_48);
      *local_res18 = 0;
      local_res18[1] = 0;
      *local_res18 = local_res20;
      local_res18[1] = param_2;
      uVar2 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,0x83);
      (*local_10)(local_48[0]);
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar2;
}



===== WinHvMapGpaPagesFromMbpArrayScanLargePagesRemote @ 14001ed90 =====

uint WinHvMapGpaPagesFromMbpArrayScanLargePagesRemote
               (undefined *param_1,longlong param_2,uint param_3,ulonglong param_4,
               ulonglong *param_5,longlong *param_6)

{
  char cVar1;
  uint uVar2;
  undefined *local_18 [2];
  
                    /* 0x1ed90  111  WinHvMapGpaPagesFromMbpArrayScanLargePagesRemote */
  local_18[0] = (undefined *)0x0;
  cVar1 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar1 == '\0') {
    uVar2 = 0xc0350008;
  }
  else {
    uVar2 = WinHvpLookupRemotePartitionByLocalId(param_1,local_18,(undefined8 *)0x0);
    if (-1 < (int)uVar2) {
      uVar2 = WinHvpMapGpaPages(local_18[0],param_2,param_4,param_3,param_5,0x10,3,param_6);
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar2;
}



===== WinHvMapGpaPagesScanLargePagesRemote @ 14001ee60 =====

uint WinHvMapGpaPagesScanLargePagesRemote
               (undefined *param_1,longlong param_2,uint param_3,ulonglong param_4,
               ulonglong *param_5,longlong *param_6)

{
  char cVar1;
  uint uVar2;
  undefined *local_18 [2];
  
                    /* 0x1ee60  113  WinHvMapGpaPagesScanLargePagesRemote */
  local_18[0] = (undefined *)0x0;
  cVar1 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar1 == '\0') {
    uVar2 = 0xc0350008;
  }
  else {
    uVar2 = WinHvpLookupRemotePartitionByLocalId(param_1,local_18,(undefined8 *)0x0);
    if (-1 < (int)uVar2) {
      uVar2 = WinHvpMapGpaPages(local_18[0],param_2,param_4,param_3,param_5,8,3,param_6);
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar2;
}



===== WinHvRegisterRemoteHvCallInterface @ 14001ef30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WinHvRegisterRemoteHvCallInterface(char *param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((((*param_1 == '\x02') && (param_2 == 0x18)) && (*(longlong *)(param_1 + 8) != 0)) &&
     (*(longlong *)(param_1 + 0x10) != 0)) {
    _DAT_140015288 = 0;
    _WinHvpRemoteIdMapLock = 1;
    _DAT_140015290 = 0;
    KeInitializeEvent(&DAT_140015298,1,0);
    ExInitializeRundownProtection(&DAT_1400150b8);
    _DAT_1400150c0 = *(undefined8 *)param_1;
    DAT_1400150c8 = *(undefined8 *)(param_1 + 8);
    DAT_1400150d0 = *(undefined8 *)(param_1 + 0x10);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== WinHvReserveDeviceInterruptRemote @ 14001efd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvReserveDeviceInterruptRemote
               (undefined *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  undefined8 uVar1;
  undefined *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined *local_78;
  undefined8 *local_70;
  undefined8 local_68 [3];
  undefined1 local_50;
  code *local_30;
  
                    /* 0x1efd0  147  WinHvReserveDeviceInterruptRemote */
  memset(local_68,0,0x40);
  local_70 = (undefined8 *)0x0;
  local_78 = (undefined *)0x0;
  cVar3 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar3 == '\0') {
    uVar4 = 0xc0350008;
  }
  else {
    uVar4 = WinHvpLookupRemotePartitionByLocalId(param_1,&local_78,(undefined8 *)0x0);
    puVar2 = local_78;
    if (-1 < (int)uVar4) {
      iVar5 = 0;
      local_50 = 1;
      while( true ) {
        WinHvpSetupHypercall(&local_70,(undefined8 *)0x0,(longlong)local_68);
        *local_70 = 0;
        local_70[1] = 0;
        local_70[2] = 0;
        local_70[3] = 0;
        local_70[4] = 0;
        local_70[5] = 0;
        local_70[6] = 0;
        *local_70 = puVar2;
        local_70[1] = param_2;
        *(undefined4 *)(local_70 + 2) = param_3;
        local_70[3] = param_4;
        uVar1 = param_5[1];
        local_70[4] = *param_5;
        local_70[5] = uVar1;
        uVar4 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_68,0xea);
        (*local_30)(local_68[0]);
        if (((uVar4 != 0xc0350075) && (uVar4 != 0xc035000b)) && (1 < uVar4 + 0x3fcaff7f)) break;
        uVar4 = WinHvpRemotePartitionLowMemoryHandler(puVar2,-0x7fff0001,uVar4,0xea,iVar5);
        if ((int)uVar4 < 0) break;
        iVar5 = iVar5 + 1;
      }
    }
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar4;
}



===== WinHvUnregisterRemoteHvCallInterface @ 14001f140 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WinHvUnregisterRemoteHvCallInterface(void)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  ExWaitForRundownProtectionRelease(&DAT_1400150b8);
  ExAcquireFastMutex(&WinHvpRemoteIdMapLock);
  puVar5 = auStack_28;
  do {
    puVar4 = WinHvpRemoteIdMap;
    if ((undefined **)WinHvpRemoteIdMap == &WinHvpRemoteIdMap) {
LAB_14001f1b0:
      *(undefined8 *)(puVar5 + -8) = 0x14001f1be;
      ExReleaseFastMutex(&WinHvpRemoteIdMapLock);
      _DAT_1400150c0 = 0;
      DAT_1400150c8 = 0;
      DAT_1400150d0 = 0;
      *(undefined8 *)(puVar5 + -8) = 0x14001f1e4;
      ExRundownCompleted(&DAT_1400150b8);
      return 0;
    }
    lVar1 = *(longlong *)WinHvpRemoteIdMap;
    if ((*(undefined **)(lVar1 + 8) != WinHvpRemoteIdMap) ||
       (plVar2 = *(longlong **)(WinHvpRemoteIdMap + 8), (undefined *)*plVar2 != WinHvpRemoteIdMap))
    {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar5 = auStack_20;
      goto LAB_14001f1b0;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    ExFreePoolWithTag(puVar4,0x59764857);
  } while( true );
}



===== WinHvpAutoDepositRemote @ 14001f200 =====

uint WinHvpAutoDepositRemote(undefined8 param_1,undefined *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  longlong local_18;
  longlong local_10;
  
  local_18 = 0;
  local_10 = 0;
  uVar2 = WinHvpAllocateMemoryFromNumaNode(0x200,WinHvpMmFlags,param_3,&local_18);
  uVar1 = (uint)uVar2;
  if (-1 < (int)uVar1) {
    uVar1 = WinHvDepositMemoryFromMdlRemote(param_2,local_18,&local_10);
    if ((int)uVar1 < 0) {
      MmFreePagesFromMdl(local_18);
    }
    if (local_10 != 0) {
      uVar1 = 0;
    }
  }
  if (local_18 != 0) {
    ExFreePoolWithTag(local_18,0);
  }
  if ((int)uVar1 < 0) {
    uVar1 = param_4;
  }
  return uVar1;
}



===== WinHvpInitializePersistenceSupport @ 14001f2b0 =====

void WinHvpInitializePersistenceSupport(void)

{
  ExInitializeRundownProtection(&DAT_1400150b8);
  ExWaitForRundownProtectionRelease(&DAT_1400150b8);
  ExRundownCompleted(&DAT_1400150b8);
  return;
}



===== WinHvpLookupRemotePartitionByLocalId @ 14001f2fc =====

uint WinHvpLookupRemotePartitionByLocalId
               (undefined *param_1,undefined8 *param_2,undefined8 *param_3)

{
  byte bVar1;
  char cVar2;
  undefined **ppuVar3;
  
  bVar1 = 0;
  *param_2 = 0;
  ExAcquireFastMutex(&WinHvpRemoteIdMapLock);
  ppuVar3 = (undefined **)WinHvpRemoteIdMap;
  do {
    if (ppuVar3 == &WinHvpRemoteIdMap) {
LAB_14001f379:
      ExReleaseFastMutex(&WinHvpRemoteIdMapLock);
      return ~-(uint)bVar1 & 0xc035000d;
    }
    if (ppuVar3[2] == param_1) {
      *param_2 = ppuVar3[3];
      if (param_3 != (undefined8 *)0x0) {
        cVar2 = ExAcquireRundownProtection(ppuVar3 + 0xe);
        if (cVar2 == '\0') goto LAB_14001f379;
        *param_3 = ppuVar3;
      }
      bVar1 = 1;
      goto LAB_14001f379;
    }
    ppuVar3 = (undefined **)*ppuVar3;
  } while( true );
}



===== WinHvpPersistMirroringDeposit @ 14001f3bc =====

uint WinHvpPersistMirroringDeposit(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  *param_3 = 0;
  cVar1 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar1 != '\0') {
    uVar2 = WinHvpDepositMemoryFromMdl(param_1,param_2,'\x01','\x01',param_3);
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return uVar2;
}



===== WinHvpRemotePartitionLowMemoryHandler @ 14001f440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WinHvpRemotePartitionLowMemoryHandler
          (undefined *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  bool bVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  bVar1 = false;
  ExAcquireFastMutex(&WinHvpRemoteIdMapLock);
  ppuVar2 = (undefined **)WinHvpRemoteIdMap;
  do {
    ppuVar3 = (undefined **)0x0;
    if (ppuVar2 == &WinHvpRemoteIdMap) {
LAB_14001f49f:
      ExReleaseFastMutex(&WinHvpRemoteIdMapLock);
      if ((bVar1) && ((code *)ppuVar3[5] != (code *)0x0)) {
        if (param_2 == -0x7fff0001) {
          param_2 = *(int *)(ppuVar3 + 4);
        }
        param_3 = (*(code *)ppuVar3[5])(ppuVar3[6],ppuVar3[2],param_2,param_3,param_4,param_5);
      }
      return param_3;
    }
    if (ppuVar2[3] == param_1) {
      bVar1 = true;
      ppuVar3 = ppuVar2;
      goto LAB_14001f49f;
    }
    ppuVar2 = (undefined **)*ppuVar2;
  } while( true );
}



===== WinHvpRemoveRemotePartitionId @ 14001f514 =====

void WinHvpRemoveRemotePartitionId(undefined *param_1)

{
  undefined **ppuVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined **ppuVar4;
  
  ExAcquireFastMutex(&WinHvpRemoteIdMapLock);
  ppuVar4 = (undefined **)WinHvpRemoteIdMap;
  do {
    if (ppuVar4 == &WinHvpRemoteIdMap) {
LAB_14001f570:
      ExReleaseFastMutex(&WinHvpRemoteIdMapLock);
      if (ppuVar4 != &WinHvpRemoteIdMap) {
        ExWaitForRundownProtectionRelease(ppuVar4 + 0xe);
        ExFreePoolWithTag(ppuVar4,0x59764857);
      }
      return;
    }
    ppuVar1 = (undefined **)*ppuVar4;
    if (ppuVar4[2] == param_1) {
      if (((undefined **)ppuVar1[1] != ppuVar4) ||
         (plVar2 = (longlong *)ppuVar4[1], (undefined **)*plVar2 != ppuVar4)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *plVar2 = (longlong)ppuVar1;
      ppuVar1[1] = (undefined *)plVar2;
      goto LAB_14001f570;
    }
    ppuVar4 = ppuVar1;
  } while( true );
}



===== WinHvpUnpersistMirroringDeposit @ 14001f5cc =====

undefined8 WinHvpUnpersistMirroringDeposit(undefined8 param_1)

{
  char cVar1;
  
  cVar1 = ExAcquireRundownProtection(&DAT_1400150b8);
  if (cVar1 != '\0') {
    WinHvpFinalizePartitionRemote(param_1);
    ExReleaseRundownProtection(&DAT_1400150b8);
  }
  return 0;
}



===== WinHvpDeleteVpObject @ 14001f618 =====

void WinHvpDeleteVpObject(ulonglong param_1,uint param_2)

{
  undefined8 uVar1;
  ulonglong *local_res18 [2];
  
  local_res18[0] = (ulonglong *)0x0;
  uVar1 = WinHvpReferenceVp(param_1,param_2,(longlong *)local_res18);
  if (-1 < (int)uVar1) {
    uVar1 = WinHvpTerminateVpDispatchLoop(local_res18[0]);
    if (-1 < (int)uVar1) {
      WinHvpRemoveVpFromPartition(local_res18[0]);
      WinHvpDereferenceVp((longlong)local_res18[0]);
    }
    WinHvpDereferenceVp((longlong)local_res18[0]);
  }
  return;
}



===== WinHvpCleanupPortIdSupport @ 14001f668 =====

void WinHvpCleanupPortIdSupport(void)

{
  if (WinHvpPortTable != 0) {
    ExFreePoolWithTag(WinHvpPortTable,0x50764857);
    WinHvpPortTable = 0;
  }
  WinHvpPortTableUsed = 0;
  WinHvpPortTableCapacity = 0;
  return;
}



===== WinHvDepositMemory @ 14001f6b0 =====

void WinHvDepositMemory(undefined8 param_1,ulonglong param_2,uint param_3,char param_4,
                       longlong *param_5)

{
                    /* 0x1f6b0  44  WinHvDepositMemory */
  WinHvpDepositMemory(param_1,param_2,param_3,'\0',param_4,param_5);
  return;
}



===== WinHvDepositMemoryFromMdl @ 14001f6e0 =====

void WinHvDepositMemoryFromMdl(undefined8 param_1,longlong param_2,char param_3,longlong *param_4)

{
                    /* 0x1f6e0  45  WinHvDepositMemoryFromMdl */
  WinHvpDepositMemoryFromMdl(param_1,param_2,'\0',param_3,param_4);
  return;
}



===== WinHvPersistPartitionReservedPages @ 14001f700 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvPersistPartitionReservedPages(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStack_1048 [32];
  ushort local_1028 [8];
  undefined1 local_1018 [4096];
  ulonglong local_18;
  undefined8 local_10;
  
                    /* 0x1f700  127  WinHvPersistPartitionReservedPages */
  local_10 = 0x14001f715;
  local_18 = __security_cookie ^ (ulonglong)auStack_1048;
  uVar3 = 0;
  while( true ) {
    local_1028[0] = 0x1ff;
    uVar2 = WinHvQueryPartitionReservedPages(param_1,uVar3,local_1028,local_1018);
    if (((int)uVar2 < 0) || (local_1028[0] == 0)) break;
    uVar3 = (ulonglong)local_1028[0];
    iVar1 = WinHvpPersistPartitionReservedPages(param_1,uVar3,(longlong)local_1018);
    if (iVar1 < 0) {
      return;
    }
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return;
}



===== WinHvWaitForWithdrawAllowed @ 14001f7a0 =====

int WinHvWaitForWithdrawAllowed(void)

{
  int iVar1;
  
                    /* 0x1f7a0  197  WinHvWaitForWithdrawAllowed */
  iVar1 = 0;
  if (DAT_140015062 == '\0') {
    iVar1 = KeWaitForSingleObject(WinHvpWithdrawAllowedEvent,0,0,0,0);
    if (-1 < iVar1) {
      DAT_140015062 = '\x01';
    }
  }
  return iVar1;
}



===== WinHvWithdrawAllMemory @ 14001f7f0 =====

void WinHvWithdrawAllMemory(undefined8 param_1)

{
                    /* 0x1f7f0  198  WinHvWithdrawAllMemory */
  WinHvWithdrawAllMemoryWithCount(param_1,(longlong *)0x0);
  return;
}



===== WinHvWithdrawAllMemoryWithCount @ 14001f810 =====

int WinHvWithdrawAllMemoryWithCount(undefined8 param_1,longlong *param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong *plVar3;
  longlong local_res10 [3];
  
                    /* 0x1f810  199  WinHvWithdrawAllMemoryWithCount */
  local_res10[0] = 0;
  plVar3 = local_res10;
  if (param_2 != (longlong *)0x0) {
    plVar3 = param_2;
  }
  uVar1 = WinHvpWithdrawMemory(param_1,0xffffffffffffffff,0x80000000,'\0',plVar3);
  iVar2 = 0;
  if ((int)uVar1 != -0x3fcaffe3) {
    iVar2 = (int)uVar1;
  }
  return iVar2;
}



===== WinHvWithdrawMemory @ 14001f860 =====

void WinHvWithdrawMemory(undefined8 param_1,ulonglong param_2,uint param_3,longlong *param_4)

{
                    /* 0x1f860  200  WinHvWithdrawMemory */
  WinHvpWithdrawMemory(param_1,param_2,param_3,'\0',param_4);
  return;
}



===== WinHvpAddRemovePhysicalMemory @ 14001f880 =====

int WinHvpAddRemovePhysicalMemory
              (char param_1,undefined1 param_2,ulonglong param_3,ulonglong param_4,longlong *param_5
              )

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  iVar3 = 0;
  iVar1 = 0;
  *param_5 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_1 == '\0') {
    WinHvpInitializeFastHypercall(&local_38);
    local_38 = CONCAT71(local_38._1_7_,param_2);
  }
  else {
    WinHvpInitializeFastHypercall(&local_48);
    local_48 = CONCAT71(local_48._1_7_,param_2);
  }
  do {
    if (param_4 == 0) {
LAB_14001f9e5:
      if ((param_1 == '\0') && (*param_5 != 0)) {
        WinHvWithdrawAllMemoryWithCount(0xffffffffffffffff,(longlong *)0x0);
      }
      return iVar1;
    }
    uVar2 = 0;
    if ((0xfff < param_4) && ((param_3 & 0x1ff) == 0)) {
      uVar2 = 1;
    }
    if (param_1 == '\0') {
      local_38._0_2_ = CONCAT11(uVar2,(undefined1)local_38);
      uStack_30 = param_3;
    }
    else {
      local_48._0_2_ = CONCAT11(uVar2,(undefined1)local_48);
      uStack_40 = param_3;
    }
    iVar1 = WinHvpFastRepHypercall();
    *param_5 = *param_5;
    if (((iVar1 == -0x3fcaff8b) || (iVar1 == -0x3fcafff5)) || (iVar1 + 0x3fcaff7fU < 2)) {
      iVar1 = WinHvpLowMemoryHandler
                        ((undefined *)0xffffffffffffffff,0x8000ffff,iVar1,
                         (-(uint)(param_1 != '\0') & 0xffffffc5) + 0xf7,iVar3,'\0');
      if (iVar1 < 0) {
        iVar1 = -0x3fffff66;
        goto LAB_14001f9e5;
      }
    }
    else if (iVar1 < 0) goto LAB_14001f9e5;
    iVar3 = iVar3 + 1;
  } while( true );
}



===== WinHvpAllocateMemoryFromNumaNode @ 14001fa24 =====

undefined8
WinHvpAllocateMemoryFromNumaNode(ulonglong param_1,uint param_2,uint param_3,longlong *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = 0;
  *param_4 = 0;
  if ((param_2 & 0x30) == 0x30) {
    param_1 = param_1 + 0x1ff & 0xfffffffffffffe00;
  }
  uVar3 = 0x200000;
  if ((param_2 & 0x30) != 0x30) {
    uVar3 = 0;
  }
  if (param_3 < 0x40) {
    lVar1 = MmAllocateNodePagesForMdlEx
                      (0,0xffffffffffffffff,uVar3,param_1 << 0xc,1,param_3,param_2 | 1);
  }
  else {
    lVar1 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,uVar3,param_1 << 0xc,1,param_2 | 1);
  }
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *param_4 = lVar1;
  }
  return uVar2;
}



===== WinHvpCleanupRmSupport @ 14001fadc =====

void WinHvpCleanupRmSupport(void)

{
  if (WinHvpWithdrawAllowedEvent != 0) {
    ObfDereferenceObject();
  }
  if (DAT_140015120 != 0) {
    IoFreeWorkItem();
    DAT_140015120 = 0;
  }
  return;
}



===== WinHvpDepositMemory @ 14001fb24 =====

ulonglong WinHvpDepositMemory(undefined8 param_1,ulonglong param_2,uint param_3,char param_4,
                             char param_5,longlong *param_6)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong local_28 [2];
  
  if (WinHvpConnected == '\0') {
    *param_6 = 0;
    uVar1 = 0xc0350002;
  }
  else {
    lVar5 = 0;
    if (param_2 == 0) {
LAB_14001fc4c:
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      uVar3 = WinHvpMmFlags | 0x30;
      if (param_4 == '\0') {
        uVar3 = WinHvpMmFlags;
      }
      uVar4 = uVar3 | 0x40;
      if ((uVar3 & 0x20) == 0) {
        uVar4 = uVar3;
      }
      while (param_2 != 0) {
        local_28[0] = 0;
        uVar2 = WinHvpDepositMemoryFromNumaNode
                          (param_1,param_2,uVar4,param_3 & 0x7fffffff,param_5,local_28);
        uVar1 = uVar2 & 0xffffffff;
        lVar5 = lVar5 + local_28[0];
        if (param_2 <= local_28[0]) goto LAB_14001fc4c;
        if ((int)uVar2 != -0x3fffff66) break;
        param_2 = param_2 - local_28[0];
        if (((byte)uVar4 & 0x70) == 0x70) {
          uVar4 = uVar4 & 0xffffffbf;
        }
        else if ((param_4 == '\0') && (((byte)uVar4 & 0x30) == 0x30)) {
          uVar4 = uVar4 & 0xffffffdf;
        }
        else {
          if (-1 < (int)param_3 || (uVar4 & 2) == 0) {
            uVar1 = 0xc000009a;
            break;
          }
          uVar4 = WinHvpMmFlags & 0xfffffffd | 0x30;
          if (param_4 == '\0') {
            uVar4 = WinHvpMmFlags & 0xfffffffd;
          }
          if ((uVar4 & 0x20) != 0) {
            uVar4 = uVar4 | 0x40;
          }
        }
      }
    }
    *param_6 = lVar5;
  }
  return uVar1;
}



===== WinHvpDepositMemoryFromNumaNode @ 14001fc84 =====

ulonglong WinHvpDepositMemoryFromNumaNode
                    (undefined8 param_1,ulonglong param_2,uint param_3,uint param_4,char param_5,
                    ulonglong *param_6)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong local_18 [2];
  
  local_18[0] = 0;
  *param_6 = 0;
  uVar2 = WinHvpAllocateMemoryFromNumaNode(param_2,param_3,param_4,local_18);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = WinHvpDepositMemoryFromMdl(param_1,local_18[0],'\0',param_5,(longlong *)param_6);
    uVar3 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      MmFreePagesFromMdl(local_18[0]);
    }
    else if (*param_6 < param_2) {
      uVar3 = 0xc000009a;
    }
  }
  if (local_18[0] != 0) {
    ExFreePoolWithTag(local_18[0],0);
  }
  return uVar3;
}



===== WinHvpPersistPartitionReservedPages @ 14001fd44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WinHvpPersistPartitionReservedPages(undefined8 param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  int iVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_2a8 [32];
  ulonglong local_288;
  longlong local_280;
  undefined8 local_278;
  undefined8 local_268;
  short local_260;
  undefined2 local_25e;
  undefined8 local_248;
  int local_240;
  undefined4 local_23c;
  longlong local_238 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2a8;
  local_280 = param_3;
  local_278 = param_1;
  memset(&local_268,0,0x230);
  iVar1 = 0;
  uVar9 = 0;
  if (param_2 != 0) {
    uVar6 = 0;
    while( true ) {
      uVar2 = 0;
      iVar5 = (uint)((ulonglong)*(undefined8 *)(param_3 + uVar6 * 8) >> 0x28) + 1;
      while( true ) {
        iVar7 = (int)uVar2;
        if (iVar7 == iVar5) break;
        local_268 = 0;
        uVar8 = iVar5 - iVar7;
        local_25e = 0;
        local_248 = 0;
        local_23c = 0;
        if (0x40 < uVar8) {
          uVar8 = 0x40;
        }
        local_240 = uVar8 << 0xc;
        local_260 = ((short)uVar8 + 6) * 8;
        if (uVar8 != 0) {
          plVar4 = local_238;
          lVar3 = (*(ulonglong *)(local_280 + uVar6 * 8) & 0xffffffffff) + uVar2;
          uVar2 = (ulonglong)uVar8;
          do {
            *plVar4 = lVar3;
            lVar3 = lVar3 + 1;
            plVar4 = plVar4 + 1;
            uVar2 = uVar2 - 1;
          } while (uVar2 != 0);
        }
        local_288 = 0;
        iVar1 = WinHvpPersistMirroringDeposit(local_278,&local_268,&local_288);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (local_288 != uVar8) {
          return -0x3fffffff;
        }
        uVar2 = (ulonglong)(iVar7 + uVar8);
      }
      uVar9 = uVar9 + 1;
      uVar6 = (ulonglong)uVar9;
      if (param_2 <= uVar6) break;
      param_3 = local_280;
    }
  }
  return iVar1;
}



===== WinHvpWithdrawMemory @ 14001fec8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WinHvpWithdrawMemory
                    (undefined8 param_1,ulonglong param_2,uint param_3,char param_4,
                    longlong *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48 [3];
  char local_30;
  code *local_10;
  
  memset(local_48,0,0x40);
  local_50 = 0;
  local_res8 = 0;
  local_58 = param_1;
  local_30 = param_4;
  if ((param_4 == '\0') && (DAT_140015062 == '\0')) {
    uVar2 = KeWaitForSingleObject(WinHvpWithdrawAllowedEvent,0,0,0,&local_res8);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    DAT_140015062 = '\x01';
  }
  WinHvpSetProximityDomain(&local_50,param_3);
  uVar1 = WinHvpSpecialListRepHypercall
                    (0x49,param_2,&local_58,0x10,(longlong *)0x0,0,(void *)0x0,0,(undefined *)0x0,
                     (undefined *)0x0,(void *)0x0,8,WinHvpWithdrawMemoryConsumer,local_48,param_5);
  if (local_48[0] != 0) {
    (*local_10)();
  }
  return (ulonglong)uVar1;
}



===== WinHvpCompleteVpStatsDelete @ 140020020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpCompleteVpStatsDelete(int param_1,undefined8 param_2,uint param_3)

{
  ulonglong uVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_18 = local_18 & 0xffffffff00000000;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (-1 < param_1) {
    local_48 = 0x10002;
    uStack_30 = 0;
    local_38 = (ulonglong)param_3;
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    uStack_40 = param_2;
    uVar1 = Feature_450263353__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 == 0) {
      RtlDeleteElementGenericTable(&WinHvpStatsTable,&local_48);
    }
    else {
      WinHvpUnlinkStatsTableEntry(&local_48);
    }
    local_38 = CONCAT17(1,(undefined7)local_38);
    uVar1 = Feature_450263353__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 == 0) {
      RtlDeleteElementGenericTable(&WinHvpStatsTable,&local_48);
    }
    else {
      WinHvpUnlinkStatsTableEntry(&local_48);
    }
  }
  ExReleaseFastMutex(&WinHvpStatsTableLock);
  return;
}



===== WinHvpIssueMapStatsPageHypercall @ 1400200f8 =====

uint WinHvpIssueMapStatsPageHypercall
               (undefined8 param_1,undefined4 param_2,undefined8 *param_3,longlong *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  longlong local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  longlong local_18;
  
  local_res8 = 0;
  local_1c = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  cVar3 = WinHvIsOverlayMapLocationRequired();
  uVar1 = *param_3;
  uVar2 = param_3[1];
  if (cVar3 == '\0') {
    local_48 = CONCAT44(local_48._4_4_,param_2);
    uStack_40 = uVar1;
    local_38 = uVar2;
    uVar4 = WinHvpAllocatingHypercall
                      (0xffffffffffffffff,0x8000ffff,0x6c,'\0',&local_48,0x18,&local_res8,8);
    if (-1 < (int)uVar4) {
      *param_4 = local_res8;
    }
  }
  else {
    uStack_28 = (undefined4)uVar1;
    uStack_24 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uStack_20 = (undefined4)uVar2;
    local_1c = (undefined4)((ulonglong)uVar2 >> 0x20);
    local_30 = param_2;
    lVar5 = WinHvpAllocateOverlayPhysicalPage();
    if (lVar5 == -1) {
      return 0xc000009a;
    }
    local_18 = lVar5;
    uVar4 = WinHvpAllocatingHypercall
                      (0xffffffffffffffff,0x8000ffff,0x131,'\0',&local_30,0x20,(void *)0x0,0);
    if ((int)uVar4 < 0) {
      WinHvpFreeOverlayPhysicalPage(lVar5);
    }
    else {
      *param_4 = lVar5;
    }
  }
  return uVar4;
}



===== WinHvpUnlinkStatsTableEntry @ 140020224 =====

void WinHvpUnlinkStatsTableEntry(undefined8 param_1)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = RtlLookupElementGenericTable(&WinHvpStatsTable,param_1);
  if (lVar2 != 0) {
    lVar2 = *(longlong *)(lVar2 + 0x18);
    *(undefined1 *)(lVar2 + 0x31) = 1;
    cVar1 = RtlDeleteElementGenericTable(&WinHvpStatsTable,param_1);
    if (cVar1 == '\0') {
      *(undefined1 *)(lVar2 + 0x31) = 0;
    }
  }
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140020284 =====

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



===== WinHvCreateEventLogBuffer @ 140020350 =====

void WinHvCreateEventLogBuffer(undefined8 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined *local_res20;
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x20350  30  WinHvCreateEventLogBuffer */
  local_10 = 0;
  local_res20 = (undefined *)0x0;
  uVar1 = param_3;
  local_18 = WinHvpInitializeFastHypercall((undefined8 *)&local_18);
  local_14 = param_2;
  WinHvpSetProximityDomain(&local_10,uVar1);
  uVar1 = WinHvGetPartitionId((longlong *)&local_res20);
  if (-1 < (int)uVar1) {
    WinHvpFastAllocatingHypercall(local_res20,param_3,0x62,(undefined8 *)&local_18);
  }
  return;
}



===== WinHvCreateIptBuffers @ 1400203c0 =====

uint WinHvCreateIptBuffers(undefined4 param_1,undefined1 param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
                    /* 0x203c0  31  WinHvCreateIptBuffers */
  local_res20 = 0;
  if (param_3 == (undefined8 *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    local_res18 = (ulonglong)CONCAT14(param_2,param_1);
    uVar1 = WinHvpAllocatingHypercall
                      (0xffffffffffffffff,0x8000ffff,0xe7,'\0',&local_res18,8,&local_res20,8);
    if (-1 < (int)uVar1) {
      *param_3 = local_res20;
    }
  }
  return uVar1;
}



===== WinHvDeleteIptBuffers @ 140020440 =====

uint WinHvDeleteIptBuffers(void)

{
  uint uVar1;
  undefined8 local_18;
  undefined8 local_10;
  
                    /* 0x20440  39  WinHvDeleteIptBuffers */
  local_10 = 0;
  local_18 = WinHvpInitializeFastHypercall(&local_18);
  uVar1 = WinHvpFastHypercall(0xe8,&local_18);
  if (-1 < (int)uVar1) {
    WinHvWithdrawAllMemoryWithCount(0xffffffffffffffff,(longlong *)0x0);
  }
  return uVar1;
}



===== WinHvInitializeEventLogBufferGroup @ 140020490 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WinHvInitializeEventLogBufferGroup
               (undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6)

{
  uint uVar1;
  ulonglong local_38;
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined8 local_18;
  
                    /* 0x20490  94  WinHvInitializeEventLogBufferGroup */
  local_1c = 0;
  local_38 = 0;
  local_24 = param_5;
  local_20 = param_6;
  if (param_6 == 0) {
    local_18 = _DAT_fffff78000000014;
  }
  else {
    local_18 = 0;
  }
  local_30 = param_1;
  local_2e = param_2;
  local_2c = param_3;
  local_28 = param_4;
  uVar1 = WinHvGetPartitionId((longlong *)&local_38);
  if (-1 < (int)uVar1) {
    WinHvpAllocatingHypercall(local_38,0x8000ffff,0x60,'\0',&local_30,0x20,(void *)0x0,0);
  }
  return;
}



===== WinHvMapEventLogBuffer @ 140020530 =====

void WinHvMapEventLogBuffer(undefined4 param_1,undefined4 param_2,void *param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
                    /* 0x20530  107  WinHvMapEventLogBuffer */
  local_10 = 0xffffffffffffffff;
  local_18 = param_1;
  local_14 = param_2;
  WinHvpAllocatingHypercall(0xffffffffffffffff,0x8000ffff,100,'\0',&local_18,0x10,param_3,0x1000);
  return;
}



===== WinHvMapPartitionEventLogBuffer @ 140020580 =====

void WinHvMapPartitionEventLogBuffer
               (undefined4 param_1,undefined4 param_2,ulonglong param_3,void *param_4,
               longlong *param_5)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong local_28 [2];
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x20580  115  WinHvMapPartitionEventLogBuffer */
  local_28[0] = 0;
  local_28[1] = 0xffffffffffffffff;
  *param_5 = 0;
  iVar4 = 0;
  local_18 = param_1;
  local_14 = param_2;
  while( true ) {
    uVar2 = WinHvpSpecialListRepHypercall
                      (0x116,param_3,local_28 + 1,0x10,(longlong *)0x0,0,param_4,8,(undefined *)0x0,
                       (undefined *)0x0,(void *)0x0,0,(undefined *)0x0,(longlong *)0x0,local_28);
    lVar1 = local_28[0];
    *param_5 = *param_5 + local_28[0];
    if (((uVar2 != 0xc035000b) && (uVar2 != 0xc0350075)) && (1 < uVar2 + 0x3fcaff7f)) break;
    iVar3 = WinHvpLowMemoryHandler
                      ((undefined *)0xffffffffffffffff,0x8000ffff,uVar2,0x116,iVar4,'\0');
    if (iVar3 < 0) {
      return;
    }
    param_3 = param_3 - lVar1;
    param_4 = (void *)((longlong)param_4 + lVar1 * 8);
    iVar4 = iVar4 + 1;
  }
  return;
}



===== WinHvSetDispatchNotificationEvent @ 1400206a0 =====

undefined8 WinHvSetDispatchNotificationEvent(ulonglong param_1,uint param_2,undefined8 param_3)

{
  undefined8 uVar1;
  longlong local_res20;
  
                    /* 0x206a0  155  WinHvSetDispatchNotificationEvent */
  local_res20 = 0;
  uVar1 = WinHvpReferenceVp(param_1,param_2,&local_res20);
  if (-1 < (int)uVar1) {
    *(undefined8 *)(local_res20 + 0x90) = param_3;
    uVar1 = 0;
  }
  return uVar1;
}



===== WinHvSetSchedulerAssistData @ 1400206e0 =====

ulonglong WinHvSetSchedulerAssistData(ulonglong param_1,uint param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong local_res20;
  
                    /* 0x206e0  170  WinHvSetSchedulerAssistData */
  local_res20 = 0;
  uVar1 = WinHvpReferenceVp(param_1,param_2,&local_res20);
  if (-1 < (int)uVar1) {
    *(undefined8 *)(local_res20 + 0xc0) = param_3;
  }
  if (local_res20 != 0) {
    WinHvpDereferenceVp(local_res20);
  }
  return uVar1 & 0xffffffff;
}



===== WinHvSetSchedulerNotificationRoutine @ 140020730 =====

void WinHvSetSchedulerNotificationRoutine(undefined8 param_1)

{
                    /* 0x20730  171  WinHvSetSchedulerNotificationRoutine */
  DAT_140015190 = param_1;
  return;
}



===== WinHvpDisableVpDispatch @ 140020740 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpDisableVpDispatch(undefined8 *param_1)

{
  undefined1 auStackY_78 [32];
  undefined4 local_38 [2];
  longlong local_30 [6];
  
  local_30[3] = __security_cookie ^ (ulonglong)auStackY_78;
  local_38[0] = 3;
  local_30[2] = 0;
  local_30[0] = 0;
  local_30[1] = 1;
  WinHvSetVpRegisters(*param_1,*(undefined4 *)(param_1 + 1),0,1,local_38,local_30 + 1,local_30);
  return;
}



===== WinHvpGetHypervisorVpSignalCount @ 1400207b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvpGetHypervisorVpSignalCount(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_38 [2];
  longlong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38[0] = 0x90014;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = WinHvGetVpRegisters(*param_1,*(undefined4 *)(param_1 + 1),0,1,local_38,&local_30,&local_28
                             );
  if (iVar1 < 0) {
    local_28 = 0;
  }
  *param_2 = local_28;
  return;
}



===== WinHvpInitializeXSchedulerSupport @ 140020840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvpInitializeXSchedulerSupport(void)

{
  uint *_Dst;
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStackY_a8 [32];
  int local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 0;
  local_48 = 0;
  uStack_40 = uStack_40 & 0xffffffff00000000;
  local_78[1] = 0;
  local_78[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = (undefined *)0x0;
  uStack_50 = 0;
  uVar2 = WinHvGetSystemInformation(1,(void *)0x0,0,local_78,4,(uint *)0x0);
  if (-1 < (int)uVar2) {
    if (local_78[0] != 4) {
      return uVar2;
    }
    WinHvpDfssEnabled = '\x01';
    local_58 = &WinHvpRegistryPath;
    local_68 = CONCAT44(local_68._4_4_,0x30);
    uStack_50 = CONCAT44(uStack_50._4_4_,0x240);
    uStack_60 = 0;
    local_48 = 0;
    uStack_40 = 0;
    iVar3 = ZwOpenKey(&local_70,1,&local_68);
    if (-1 < iVar3) {
      iVar3 = ZwQueryValueKey(local_70,&DAT_14000f010,2,&local_38);
      if ((((-1 < iVar3) && (local_38._4_4_ == 4)) && ((int)uStack_30 == 4)) &&
         (uStack_30._4_4_ != 0)) {
        WinHvpDfssEnabled = '\0';
      }
      ZwClose(local_70);
    }
    uVar2 = 0;
    if (WinHvpDfssEnabled != '\0') {
      uVar2 = WinHvpGetVpRegister64Self(0x240,&DAT_140015138);
      DAT_140015138 = DAT_140015138 / 1000000;
      if ((int)uVar2 < 0) goto LAB_1400209fc;
      DAT_140015140 = KeQueryTimeIncrement();
      DAT_140015144 = DAT_140015140 / 2;
    }
    uVar1 = WinHvpMaximumProcessorCount;
    DAT_140015150 = ExAllocatePool2(0x42,(ulonglong)WinHvpMaximumProcessorCount * 0x170,0x58764857);
    if (DAT_140015150 != 0) {
      if (uVar1 != 0) {
        lVar5 = 0;
        do {
          _Dst = (uint *)(lVar5 + DAT_140015150);
          memset(_Dst,0,0x170);
          *_Dst = uVar4;
          KeGetProcessorNumberFromIndex(uVar4,_Dst + 1);
          *(longlong *)(_Dst + 2) = (longlong)(DAT_140015140 / 4);
          KeInitializeDpc(_Dst + 10,WinHvpXSchedulerDpcRoutine,_Dst);
          uVar4 = uVar4 + 1;
          lVar5 = lVar5 + 0x170;
        } while (uVar4 < uVar1);
      }
      WinHvpRootSchedulerActive = 1;
      return uVar2;
    }
    uVar2 = 0xc000009a;
    DAT_140015150 = 0;
  }
LAB_1400209fc:
  WinHvpTeardownXSchedulerSupport();
  return uVar2;
}



===== WinHvpTeardownXSchedulerSupport @ 140020ab8 =====

void WinHvpTeardownXSchedulerSupport(void)

{
  if (WinHvpRootSchedulerActive != '\0') {
    if (DAT_140015150 != 0) {
      ExFreePoolWithTag(DAT_140015150,0x58764857);
      DAT_140015150 = 0;
    }
    WinHvpRootSchedulerActive = '\0';
  }
  return;
}



===== WinHvImportIsolatedPages @ 140020b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvImportIsolatedPages
               (ulonglong param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4,
               longlong param_5,ulonglong *param_6)

{
  uint uVar1;
  int *piVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  uint local_98;
  uint local_94 [3];
  ulonglong *local_88 [2];
  longlong local_78 [7];
  code *local_40;
  
                    /* 0x20b00  93  WinHvImportIsolatedPages */
  local_94[0] = 0;
  memset(local_78,0,0x40);
  local_98 = 0;
  puVar9 = (ulonglong *)0x0;
  local_88[0] = (ulonglong *)0x0;
  uVar7 = 0;
  piVar2 = WinHvpReferencePartition(param_1);
  if (piVar2 == (int *)0x0) {
    uVar4 = 0xc035000d;
  }
  else {
    uVar4 = 0;
    if (param_4 != 0) {
      do {
        if ((int)uVar4 < 0) break;
        if (local_78[0] == 0) {
          WinHvpSetupHypercall(local_88,(undefined8 *)0x0,(longlong)local_78);
          *local_88[0] = param_1;
          *(undefined4 *)(local_88[0] + 1) = param_2;
          *(undefined4 *)((longlong)local_88[0] + 0xc) = param_3;
          puVar9 = local_88[0];
        }
        iVar6 = (int)uVar7;
        uVar4 = 0;
        if (param_4 - uVar7 < 0x1fe) {
          uVar5 = (int)param_4 - iVar6;
          if (uVar5 != 0) goto LAB_140020bc6;
        }
        else {
          uVar5 = 0x1fe;
LAB_140020bc6:
          puVar8 = puVar9 + 2;
          do {
            uVar1 = uVar4 + iVar6;
            uVar4 = uVar4 + 1;
            *puVar8 = *(ulonglong *)(param_5 + (ulonglong)uVar1 * 8);
            puVar8 = puVar8 + 1;
          } while (uVar4 < uVar5);
        }
        WinHvpAcquireAsyncMessage((longlong)piVar2);
        uVar4 = WinHvpRepPoolHypercall_CallViaMacro(local_78[0],0xef,uVar5,&local_98);
        uVar3 = WinHvpIsHypercallFallbackBuffer((longlong)local_78);
        if ((char)uVar3 != '\0') {
          (*local_40)(local_78[0]);
          local_78[0] = 0;
        }
        if (uVar4 == 0xc0350079) {
          uVar4 = WinHvpWaitForAsyncCall((longlong)piVar2,(undefined8 *)0x0,local_94);
          local_98 = local_94[0];
        }
        uVar5 = local_98;
        WinHvpReleaseAsyncMessage((longlong)piVar2);
        uVar7 = (ulonglong)(iVar6 + uVar5);
      } while (uVar7 < param_4);
    }
  }
  *param_6 = uVar7;
  if (local_78[0] != 0) {
    (*local_40)();
  }
  if (piVar2 != (int *)0x0) {
    WinHvpDereferencePartition(piVar2);
  }
  return uVar4;
}



===== WinHvIssueSnpPspGuestRequest @ 140020cc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvIssueSnpPspGuestRequest
               (ulonglong param_1,ulonglong param_2,ulonglong param_3,undefined4 *param_4)

{
  uint uVar1;
  int *piVar2;
  ulonglong *local_58;
  undefined8 local_50;
  undefined8 local_48 [7];
  code *local_10;
  
                    /* 0x20cc0  100  WinHvIssueSnpPspGuestRequest */
  memset(local_48,0,0x40);
  local_58 = (ulonglong *)0x0;
  local_50 = 0;
  piVar2 = WinHvpReferencePartition(param_1);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0xc035000d;
  }
  else {
    WinHvpSetupHypercall(&local_58,(undefined8 *)0x0,(longlong)local_48);
    *local_58 = param_1;
    local_58[1] = param_2;
    local_58[2] = param_3;
    WinHvpAcquireAsyncMessage((longlong)piVar2);
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_48,0xf2);
    (*local_10)(local_48[0]);
    if (uVar1 == 0xc0350079) {
      uVar1 = WinHvpWaitForAsyncCall((longlong)piVar2,&local_50,(undefined4 *)0x0);
      if (-1 < (int)uVar1) {
        *param_4 = (undefined4)local_50;
      }
    }
    else {
      *param_4 = 0;
    }
    WinHvpReleaseAsyncMessage((longlong)piVar2);
    WinHvpDereferencePartition(piVar2);
  }
  return uVar1;
}



===== WinHvUpdateSecFw @ 140020dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvUpdateSecFw(char param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                     undefined4 param_5)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  undefined8 *local_78 [2];
  longlong local_68 [7];
  code *local_30;
  
                    /* 0x20dc0  196  WinHvUpdateSecFw */
  memset(local_68,0,0x40);
  local_78[0] = (undefined8 *)0x0;
  iVar3 = (param_1 != '\0') + 2;
  iVar4 = 0;
  while( true ) {
    if (local_68[0] == 0) {
      WinHvpSetupHypercall(local_78,(undefined8 *)0x0,(longlong)local_68);
      *local_78[0] = 0;
      local_78[0][1] = 0;
      local_78[0][2] = 0;
      local_78[0][3] = 0;
      *(int *)(local_78[0] + 3) = iVar3;
      *(undefined4 *)local_78[0] = param_2;
      *(undefined4 *)((longlong)local_78[0] + 4) = param_3;
      local_78[0][1] = param_4;
      *(undefined4 *)(local_78[0] + 2) = param_5;
    }
    WinHvpAcquireAsyncMessage(0);
    uVar1 = WinHvpSimplePoolHypercall_CallViaMacro((longlong)local_68,7);
    uVar2 = WinHvpIsHypercallFallbackBuffer((longlong)local_68);
    if ((char)uVar2 != '\0') {
      (*local_30)();
      local_68[0] = 0;
    }
    if (uVar1 == 0xc0350079) break;
    WinHvpReleaseAsyncMessage(0);
    if (((uVar1 != 0xc0350075) && (uVar1 != 0xc035000b)) && (1 < uVar1 + 0x3fcaff7f))
    goto LAB_140020ee3;
    uVar1 = WinHvpLowMemoryHandler
                      ((undefined *)0xffffffffffffffff,0x8000ffff,uVar1,iVar3,iVar4,'\0');
    if ((int)uVar1 < 0) goto LAB_140020ee3;
    iVar4 = iVar4 + 1;
  }
  uVar1 = WinHvpWaitForAsyncCall(0,(undefined8 *)0x0,(undefined4 *)0x0);
  WinHvpReleaseAsyncMessage(0);
LAB_140020ee3:
  if (local_68[0] != 0) {
    (*local_30)();
  }
  return uVar1;
}



===== WinHvAllocatePortId @ 140020f20 =====

undefined8 WinHvAllocatePortId(undefined8 param_1,uint *param_2)

{
  void *pvVar1;
  void *_Dst;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 *puVar5;
  uint uVar6;
  longlong local_res18 [2];
  
                    /* 0x20f20  10  WinHvAllocatePortId */
  uVar3 = 0;
  local_res18[0] = 0;
  local_res18[1] = 0;
  if (WinHvpConnected == '\0') {
    return 0xc0350002;
  }
  *param_2 = 0;
  RtlGetCallersAddress(local_res18,local_res18 + 1);
  uVar2 = 1;
  if (local_res18[0] == 0) {
    local_res18[0] = 1;
  }
  ExAcquireFastMutex(&WinHvpPortTableAllocationMutex);
  uVar6 = WinHvpPortTableCapacity & 0xffffff;
  if ((WinHvpPortTableUsed & 0xffffff) < uVar6) {
    for (uVar2 = 0; uVar2 < uVar6; uVar2 = uVar2 ^ (uVar2 + 1 ^ uVar2) & 0xffffff) {
      puVar5 = (undefined8 *)((ulonglong)uVar2 * 0x10 + (longlong)WinHvpPortTable);
      if (puVar5[1] == 0) {
        puVar5[1] = local_res18[0];
        *puVar5 = param_1;
        break;
      }
    }
    if (uVar2 < (WinHvpPortTableCapacity & 0xffffff)) {
      WinHvpPortTableUsed = WinHvpPortTableUsed + 1 & 0xffffff | WinHvpPortTableUsed & 0xff000000;
      *param_2 = (uVar2 + 1 ^ *param_2) & 0xffffff ^ *param_2;
    }
    else {
      uVar3 = 0xc000009a;
    }
  }
  else {
    if (uVar6 == 0) {
      uVar4 = 1;
    }
    else {
      uVar2 = uVar6 * 2;
      uVar4 = uVar2 & 0xffffff;
      if (uVar4 < uVar6) {
        uVar3 = 0xc000009a;
        goto LAB_14002102f;
      }
    }
    _Dst = (void *)ExAllocatePool2(0x42,(ulonglong)(uVar2 & 0xffffff) << 4,0x50764857);
    pvVar1 = WinHvpPortTable;
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      if (WinHvpPortTable != (void *)0x0) {
        memmove(_Dst,WinHvpPortTable,(ulonglong)(WinHvpPortTableCapacity & 0xffffff) << 4);
      }
      *(longlong *)((longlong)_Dst + (ulonglong)(WinHvpPortTableCapacity & 0xffffff) * 0x10 + 8) =
           local_res18[0];
      *(undefined8 *)((longlong)_Dst + (ulonglong)(WinHvpPortTableCapacity & 0xffffff) * 0x10) =
           param_1;
      memset((void *)(((ulonglong)(WinHvpPortTableCapacity & 0xffffff) + 1) * 0x10 + (longlong)_Dst)
             ,0,(ulonglong)((uVar4 - (WinHvpPortTableCapacity & 0xffffff)) - 1) << 4);
      WinHvpPortTable = _Dst;
      KeGenericCallDpc(WinHvpSynchronizationDpc,0);
      *param_2 = (WinHvpPortTableCapacity + 1 ^ *param_2) & 0xffffff ^ *param_2;
      WinHvpPortTableCapacity = WinHvpPortTableCapacity & 0xff000000 | uVar4;
      WinHvpPortTableUsed = WinHvpPortTableUsed + 1 & 0xffffff | WinHvpPortTableUsed & 0xff000000;
      if (pvVar1 != (void *)0x0) {
        ExFreePoolWithTag(pvVar1,0x50764857);
      }
    }
  }
LAB_14002102f:
  ExReleaseFastMutex(&WinHvpPortTableAllocationMutex);
  return uVar3;
}



===== WinHvpMapLargeGpaPages @ 1400211fc =====

void WinHvpMapLargeGpaPages
               (undefined *param_1,longlong param_2,longlong param_3,uint param_4,ulonglong *param_5
               ,uint param_6,longlong *param_7,int *param_8,longlong *param_9)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined *puVar8;
  uint local_res18 [4];
  
  uVar7 = param_3 - 0x200;
  local_res18[0] = 0;
  uVar6 = (ulonglong)param_6;
  *param_9 = 0;
  uVar5 = 1;
  puVar8 = param_1;
  while (0x1ff < uVar7) {
    uVar2 = WinHvpCheckLargeSpaPage((ulonglong)param_4,param_5 + uVar5 * uVar6 * 0x40,param_6);
    if ((char)uVar2 == '\0') break;
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar4;
    uVar7 = uVar7 - 0x200;
    if (uVar4 == 0x1fd) {
      uVar4 = WinHvpMapGpaPagesHypercall
                        (puVar8,param_2,0x1fd,param_4 | 0x80000000,param_5,param_6,param_7,param_8,
                         local_res18);
      uVar5 = (ulonglong)(0x1fd - local_res18[0]);
      lVar3 = (ulonglong)local_res18[0] * 0x200;
      *param_9 = *param_9 + lVar3;
      param_2 = param_2 + lVar3;
      param_5 = param_5 + local_res18[0] * uVar6 * 0x40;
      if ((int)uVar4 < 0) {
        return;
      }
      puVar8 = param_1;
    }
  }
  do {
    uVar4 = (uint)uVar5;
    if (uVar4 == 0) {
      return;
    }
    uVar1 = WinHvpMapGpaPagesHypercall
                      (puVar8,param_2,uVar4,param_4 | 0x80000000,param_5,param_6,param_7,param_8,
                       local_res18);
    uVar5 = (ulonglong)(uVar4 - local_res18[0]);
    lVar3 = (ulonglong)local_res18[0] * 0x200;
    *param_9 = *param_9 + lVar3;
    param_2 = param_2 + lVar3;
    param_5 = param_5 + uVar6 * local_res18[0] * 0x40;
    puVar8 = param_1;
  } while (-1 < (int)uVar1);
  return;
}



===== WinHvMapGpaPagesFromMbpArrayScanLargePages @ 1400213b0 =====

void WinHvMapGpaPagesFromMbpArrayScanLargePages
               (undefined *param_1,longlong param_2,uint param_3,ulonglong param_4,
               ulonglong *param_5,longlong *param_6)

{
                    /* 0x213b0  110  WinHvMapGpaPagesFromMbpArrayScanLargePages */
  WinHvpMapGpaPages(param_1,param_2,param_4,param_3,param_5,0x10,1,param_6);
  return;
}



===== WinHvMapGpaPagesSpecial @ 140021400 =====

void WinHvMapGpaPagesSpecial
               (undefined *param_1,longlong param_2,uint param_3,ulonglong param_4,longlong *param_5
               )

{
                    /* 0x21400  114  WinHvMapGpaPagesSpecial */
  WinHvpMapGpaPages(param_1,param_2,param_4,param_3,(ulonglong *)0x0,0,1,param_5);
  return;
}



===== WinHvpMapGpaPages @ 14002143c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpMapGpaPages(undefined *param_1,longlong param_2,ulonglong param_3,uint param_4,
                      ulonglong *param_5,uint param_6,uint param_7,longlong *param_8)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong *plVar7;
  uint local_88 [2];
  longlong local_80;
  longlong local_78 [3];
  undefined1 local_60;
  code *local_40;
  
  memset(local_78,0,0x40);
  uVar6 = param_7;
  uVar1 = 0;
  local_88[0] = 0;
  local_80 = 0;
  *param_8 = 0;
  if ((param_7 & 2) != 0) {
    local_60 = 1;
  }
  param_7 = 0;
  if ((uVar6 & 1) == 0) {
    plVar7 = param_8;
  }
  else {
    uVar4 = (param_2 + 0x1ffU & 0xfffffffffffffe00) - param_2;
    if (param_3 <= uVar4) {
      uVar4 = param_3;
    }
    for (uVar5 = param_3 - uVar4; uVar5 != 0; uVar5 = uVar5 - uVar2) {
      while (0x1fc < uVar4) {
        uVar1 = WinHvpMapGpaPagesHypercall
                          (param_1,param_2,0x1fd,param_4,param_5,param_6,local_78,(int *)&param_7,
                           local_88);
        param_2 = param_2 + (ulonglong)local_88[0];
        uVar4 = uVar4 - local_88[0];
        *param_8 = *param_8 + (ulonglong)local_88[0];
        param_5 = (ulonglong *)((longlong)param_5 + (ulonglong)(local_88[0] * param_6));
        if ((int)uVar1 < 0) goto LAB_140021547;
      }
      if (0x1ff < uVar5) {
        uVar2 = (ulonglong)param_4;
        uVar3 = WinHvpCheckLargeSpaPage
                          (uVar2,(ulonglong *)(param_6 * uVar4 + (longlong)param_5),param_6);
        if ((char)uVar3 != '\0') {
          while (uVar4 != 0) {
            uVar1 = WinHvpMapGpaPagesHypercall
                              (param_1,param_2,(uint)uVar4,(uint)uVar2,param_5,param_6,local_78,
                               (int *)&param_7,local_88);
            param_2 = param_2 + (ulonglong)local_88[0];
            uVar4 = uVar4 - local_88[0];
            *param_8 = *param_8 + (ulonglong)local_88[0];
            param_5 = (ulonglong *)((longlong)param_5 + (ulonglong)(local_88[0] * param_6));
            if ((int)uVar1 < 0) goto LAB_140021547;
            uVar2 = (ulonglong)param_4;
          }
          WinHvpMapLargeGpaPages
                    (param_1,param_2,uVar5,(uint)uVar2,param_5,param_6,local_78,(int *)&param_7,
                     &local_80);
          param_2 = param_2 + local_80;
          *param_8 = *param_8 + local_80;
          param_5 = (ulonglong *)((longlong)param_5 + (ulonglong)param_6 * local_80);
          uVar5 = uVar5 - local_80;
          uVar4 = 0;
        }
      }
      uVar2 = uVar5 & 0xffffffff;
      if (0x200 < uVar5) {
        uVar2 = 0x200;
      }
      uVar4 = uVar4 + uVar2;
    }
    param_3 = uVar4;
    plVar7 = param_8;
  }
  do {
    if (param_3 == 0) break;
    uVar6 = 0x1fd;
    if (param_3 < 0x1fd) {
      uVar6 = (uint)param_3;
    }
    uVar1 = WinHvpMapGpaPagesHypercall
                      (param_1,param_2,uVar6,param_4,param_5,param_6,local_78,(int *)&param_7,
                       local_88);
    *plVar7 = *plVar7 + (ulonglong)local_88[0];
    param_2 = param_2 + (ulonglong)local_88[0];
    param_3 = param_3 - local_88[0];
    param_5 = (ulonglong *)((longlong)param_5 + (ulonglong)(local_88[0] * param_6));
  } while (-1 < (int)uVar1);
LAB_140021547:
  if (local_78[0] != 0) {
    (*local_40)();
  }
  return uVar1;
}



===== WinHvpMapGpaPagesHypercall @ 1400216f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpMapGpaPagesHypercall
               (undefined *param_1,undefined8 param_2,uint param_3,uint param_4,ulonglong *param_5,
               uint param_6,longlong *param_7,int *param_8,uint *param_9)

{
  ulonglong uVar1;
  bool bVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong *puVar5;
  ulonglong *puVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 *local_38 [2];
  
  local_38[0] = (undefined8 *)0x0;
  uVar8 = param_6 << 9;
  if (-1 < (int)param_4) {
    uVar8 = param_6;
  }
  bVar2 = false;
  do {
    if (*param_7 == 0) {
      WinHvpSetupHypercall(local_38,(undefined8 *)0x0,(longlong)param_7);
    }
    else {
      local_38[0] = (undefined8 *)param_7[1];
    }
    if (!bVar2) {
      *local_38[0] = param_1;
      local_38[0][1] = param_2;
      *(uint *)(local_38[0] + 2) = param_4;
      if (((param_4 & 0x30000) == 0) && (param_3 != 0)) {
        puVar6 = local_38[0] + 3;
        puVar5 = param_5;
        uVar7 = (ulonglong)param_3;
        do {
          uVar1 = *puVar5;
          puVar5 = (ulonglong *)((longlong)puVar5 + (ulonglong)uVar8);
          *puVar6 = uVar1 & 0xffffffffff;
          puVar6 = puVar6 + 1;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      bVar2 = true;
    }
    uVar3 = WinHvpRepPoolHypercall_CallViaMacro(*param_7,0x4b,param_3,param_9);
    uVar4 = WinHvpIsHypercallFallbackBuffer((longlong)param_7);
    if ((char)uVar4 != '\0') {
      (*(code *)param_7[7])(*param_7);
      *param_7 = 0;
      bVar2 = false;
    }
    if (((uVar3 == 0xc035000b) || (uVar3 == 0xc0350075)) || (uVar3 + 0x3fcaff7f < 2)) {
      uVar3 = WinHvpLowMemoryHandler(param_1,0x8000ffff,uVar3,0x4b,*param_8,(char)param_7[3]);
LAB_14002186b:
      *param_8 = *param_8 + 1;
    }
    else if ((uVar3 == 0xc0350073) || (uVar3 + 0x3fcaff7d < 3)) {
      uVar3 = WinHvpCurrentPartitionLowMemoryHandler(uVar3,0x8000ffff);
      goto LAB_14002186b;
    }
    if (((int)uVar3 < 0) || (*param_9 != 0)) {
      return uVar3;
    }
  } while( true );
}



===== WinHvPrecommitGpaPages @ 1400218c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvPrecommitGpaPages
               (undefined *param_1,undefined4 param_2,longlong param_3,ulonglong param_4,
               longlong *param_5)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStackY_e8 [32];
  longlong local_a8 [2];
  longlong local_98 [7];
  code *local_60;
  undefined *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48;
  ulonglong local_40;
  
                    /* 0x218c0  131  WinHvPrecommitGpaPages */
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  memset(local_98,0,0x40);
  local_4c = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  iVar3 = 0;
  local_58 = param_1;
  local_50 = param_2;
  local_48 = param_3;
  while( true ) {
    uVar2 = WinHvpRangeRepHypercall(0xbe,param_4,&local_58,0x18,&local_48,1,local_98,local_a8);
    lVar1 = local_a8[0];
    *param_5 = *param_5 + local_a8[0];
    if (((uVar2 != 0xc035000b) && (uVar2 != 0xc0350075)) && (1 < uVar2 + 0x3fcaff7f)) break;
    uVar2 = WinHvpLowMemoryHandler(param_1,0x8000ffff,uVar2,0xbe,iVar3,'\0');
    if ((int)uVar2 < 0) break;
    param_4 = param_4 - lVar1;
    iVar3 = iVar3 + 1;
  }
  if (local_98[0] != 0) {
    (*local_60)();
  }
  return uVar2;
}



===== WinHvConnectPort @ 1400219f0 =====

void WinHvConnectPort(ulonglong param_1,uint param_2,undefined4 param_3,undefined8 param_4,
                     undefined4 param_5,undefined8 *param_6,undefined1 param_7)

{
  ulonglong local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18 [2];
  
                    /* 0x219f0  27  WinHvConnectPort */
  memset(&local_58,0,0x48);
  local_40 = param_5;
  local_4c = param_7;
  local_38 = *param_6;
  uStack_30 = param_6[1];
  local_28 = param_6[2];
  uStack_20 = param_6[3];
  local_58 = param_1;
  local_50 = param_3;
  local_48 = param_4;
  WinHvpSetProximityDomain(local_18,param_2);
  WinHvpAllocatingHypercall(param_1,param_2,0x96,'\0',&local_58,0x48,(void *)0x0,0);
  return;
}



===== WinHvInstallIntercept @ 140021ac0 =====

void WinHvInstallIntercept(ulonglong param_1,undefined4 param_2,undefined4 *param_3)

{
  ulonglong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  
                    /* 0x21ac0  97  WinHvInstallIntercept */
  local_1c = *param_3;
  local_18 = *(undefined8 *)(param_3 + 2);
  local_28 = param_1;
  local_20 = param_2;
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0x4d,'\0',&local_28,0x18,(void *)0x0,0);
  return;
}



===== WinHvCreatePort @ 140021b20 =====

void WinHvCreatePort(ulonglong param_1,uint param_2,undefined4 param_3,undefined8 param_4,
                    undefined8 *param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18 [2];
  
                    /* 0x21b20  35  WinHvCreatePort */
  local_18[0] = 0;
  uStack_40 = (ulonglong)CONCAT24(CONCAT11(param_7,param_6),param_3);
  uStack_30 = *param_5;
  local_28 = param_5[1];
  uStack_20 = param_5[2];
  local_48 = param_1;
  local_38 = param_4;
  WinHvpSetProximityDomain(local_18,param_2);
  WinHvpAllocatingHypercall(param_1,param_2,0x95,'\0',&local_48,0x38,(void *)0x0,0);
  return;
}



===== WinHvFreePortId @ 140021bc0 =====

void WinHvFreePortId(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  
                    /* 0x21bc0  62  WinHvFreePortId */
  ExAcquireFastMutex(&WinHvpPortTableAllocationMutex);
  lVar1 = WinHvpPortTable;
  uVar2 = param_1 & 0xffffff;
  if ((uVar2 != 0) && (uVar2 <= (WinHvpPortTableCapacity & 0xffffff))) {
    *(undefined8 *)(WinHvpPortTable + (ulonglong)(uVar2 - 1) * 0x10) = 0;
    *(undefined8 *)(lVar1 + 8 + (ulonglong)(uVar2 - 1) * 0x10) = 0;
    WinHvpPortTableUsed = WinHvpPortTableUsed - 1 & 0xffffff | WinHvpPortTableUsed & 0xff000000;
  }
  ExReleaseFastMutex(&WinHvpPortTableAllocationMutex);
  return;
}



===== WinHvpSetupVpStatePfnBuffer @ 140021c44 =====

longlong WinHvpSetupVpStatePfnBuffer(int param_1,ulonglong *param_2,int *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  
  lVar1 = ExAllocatePool2(0x40,param_1 + 0xfffU & 0xfffff000,0x55764857);
  uVar4 = 0;
  if (lVar1 != 0) {
    uVar3 = param_1 + 0xfffU >> 0xc;
    if (uVar3 != 0) {
      do {
        uVar2 = MmGetPhysicalAddress((ulonglong)(uVar4 << 0xc) + lVar1);
        uVar4 = uVar4 + 1;
        *param_2 = uVar2 >> 0xc;
        param_2 = param_2 + 1;
      } while (uVar4 < uVar3);
    }
    *param_3 = uVar3 * 8;
  }
  return lVar1;
}



===== WinHvMapDeviceInterruptEx @ 140021cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvMapDeviceInterruptEx
               (undefined *param_1,undefined8 param_2,uint param_3,undefined8 *param_4,uint param_5,
               undefined8 *param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  int iVar7;
  undefined8 *local_98;
  undefined4 *local_90;
  ulonglong local_88;
  undefined8 local_78 [5];
  longlong local_50;
  code *local_40;
  
                    /* 0x21cf0  106  WinHvMapDeviceInterruptEx */
  memset(local_78,0,0x40);
  local_98 = (undefined8 *)0x0;
  local_90 = (undefined4 *)0x0;
  if (((param_3 & 0xc) == 0) || (param_6 != (undefined8 *)0x0)) {
    local_88 = (ulonglong)param_5;
    iVar7 = 0;
    while( true ) {
      WinHvpSetupHypercall(&local_98,&local_90,(longlong)local_78);
      puVar5 = local_98;
      memset(local_98,0,0x48);
      *puVar5 = param_1;
      puVar5[1] = param_2;
      *(uint *)(puVar5 + 2) = param_3;
      uVar4 = param_4[1];
      puVar5[5] = *param_4;
      puVar5[6] = uVar4;
      uVar4 = param_4[3];
      puVar5[7] = param_4[2];
      puVar5[8] = uVar4;
      if ((param_3 & 0xc) != 0) {
        uVar4 = param_6[1];
        puVar5[3] = *param_6;
        puVar5[4] = uVar4;
      }
      memmove(puVar5 + 5,param_4,local_88);
      uVar6 = WinHvpVariableHeaderHypercall
                        (0x7c,param_5 - 0x20,*(undefined8 *)(local_50 + 0x18),
                         *(undefined8 *)(local_50 + 0x28));
      if (-1 < (int)uVar6) {
        uVar1 = local_90[1];
        uVar2 = local_90[2];
        uVar3 = local_90[3];
        *param_7 = *local_90;
        param_7[1] = uVar1;
        param_7[2] = uVar2;
        param_7[3] = uVar3;
      }
      (*local_40)(local_78[0]);
      if ((((uVar6 != 0xc0350075) && (uVar6 != 0xc035000b)) && (1 < uVar6 + 0x3fcaff7f)) ||
         (uVar6 = WinHvpLowMemoryHandler(param_1,0x8000ffff,uVar6,0x7c,iVar7,'\0'), (int)uVar6 < 0))
      break;
      iVar7 = iVar7 + 1;
    }
  }
  else {
    uVar6 = 0xc00000f3;
  }
  return uVar6;
}



===== WinHvpCompareStatsTableEntry @ 140021e90 =====

int WinHvpCompareStatsTableEntry(undefined8 param_1,int *param_2,int *param_3)

{
  int iVar1;
  ulonglong uVar2;
  bool bVar3;
  bool bVar4;
  
  iVar1 = *param_2;
  if (*param_3 <= iVar1) {
    if (*param_3 < iVar1) {
      return 1;
    }
    if (iVar1 == 1) {
      if (*(byte *)((longlong)param_3 + 0x17) <= *(byte *)((longlong)param_2 + 0x17)) {
        return 2 - (uint)(*(byte *)((longlong)param_3 + 0x17) < *(byte *)((longlong)param_2 + 0x17))
        ;
      }
    }
    else {
      if (iVar1 == 2) {
        bVar3 = (uint)param_2[2] < (uint)param_3[2];
        bVar4 = param_2[2] == param_3[2];
      }
      else {
        uVar2 = *(ulonglong *)(param_2 + 2);
        if (iVar1 == 0x10001) {
          bVar3 = uVar2 < *(ulonglong *)(param_3 + 2);
          bVar4 = uVar2 == *(ulonglong *)(param_3 + 2);
        }
        else {
          if (*(ulonglong *)(param_3 + 2) < uVar2) {
            return 1;
          }
          if (uVar2 < *(ulonglong *)(param_3 + 2)) {
            return 0;
          }
          bVar3 = (uint)param_2[4] < (uint)param_3[4];
          bVar4 = param_2[4] == param_3[4];
        }
      }
      if (!bVar3) {
        if (bVar4) {
          if (*(byte *)((longlong)param_2 + 0x17) < *(byte *)((longlong)param_3 + 0x17)) {
            return 0;
          }
          if (*(byte *)((longlong)param_2 + 0x17) <= *(byte *)((longlong)param_3 + 0x17)) {
            return 2;
          }
        }
        return 1;
      }
    }
  }
  return 0;
}



===== WinHvRegisterInterceptResult @ 140021f10 =====

void WinHvRegisterInterceptResult
               (ulonglong param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  ulonglong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x21f10  140  WinHvRegisterInterceptResult */
  memset(&local_48,0,0x40);
  local_38 = *param_4;
  uStack_30 = param_4[1];
  local_28 = param_4[2];
  uStack_20 = param_4[3];
  local_18 = param_4[4];
  uStack_10 = param_4[5];
  local_48 = param_1;
  local_40 = param_2;
  local_3c = param_3;
  WinHvpAllocatingHypercall(param_1,0x8000ffff,0x91,'\0',&local_48,0x40,(void *)0x0,0);
  return;
}



===== WinHvpDepositMemoryFromMdl @ 140021fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvpDepositMemoryFromMdl
               (longlong *param_1,longlong param_2,char param_3,char param_4,longlong *param_5)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong local_res8;
  longlong local_68 [3];
  char local_50;
  code *local_30;
  
  memset(local_68,0,0x40);
  plVar2 = param_5;
  local_res8 = 0;
  *param_5 = 0;
  uVar4 = (ulonglong)*(uint *)(param_2 + 0x28) + 0xfff >> 0xc;
  param_5 = param_1;
  local_50 = param_3;
  uVar3 = WinHvpSpecialListRepHypercall
                    ((-(uint)(param_4 != '\0') & 0xb7) + 0x48,uVar4,&param_5,8,(longlong *)0x0,0,
                     (void *)(param_2 + 0x30),8,WinHvpDepositMemoryBuilder,
                     WinHvpDepositMemoryAdvancer,(void *)0x0,0,(undefined *)0x0,local_68,&local_res8
                    );
  if ((param_4 != '\0') && (param_3 == '\0')) {
    param_5 = (longlong *)0x0;
    WinHvpPersistMirroringDeposit(param_1,param_2,&param_5);
  }
  lVar1 = local_res8;
  *plVar2 = local_res8;
  if (((int)uVar3 < 0) && (((param_4 == '\0' || (param_3 == '\0')) && (local_res8 != 0)))) {
    memmove((void *)(param_2 + 0x30),(void *)(param_2 + (local_res8 + 6) * 8),
            (uVar4 - local_res8) * 8);
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + (int)lVar1 * -0x1000;
  }
  if (local_68[0] != 0) {
    (*local_30)();
  }
  return uVar3;
}



===== WinHvGetVpState @ 140022140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvGetVpState(undefined8 param_1,undefined4 param_2,undefined1 param_3,int *param_4,
                    void *param_5,uint param_6)

{
  undefined8 uVar1;
  uint uVar2;
  void *pvVar3;
  void *_Src;
  int iVar4;
  undefined8 *local_res8 [2];
  int local_res18 [2];
  void *local_res20;
  undefined8 local_78 [5];
  longlong local_50;
  code *local_40;
  
                    /* 0x22140  91  WinHvGetVpState */
  pvVar3 = (void *)0x0;
  memset(local_78,0,0x40);
  local_res8[0] = (undefined8 *)0x0;
  local_res20 = (void *)0x0;
  iVar4 = 0;
  local_res18[0] = 0;
  WinHvpSetupHypercall(local_res8,&local_res20,(longlong)local_78);
  *local_res8[0] = 0;
  local_res8[0][1] = 0;
  local_res8[0][2] = 0;
  local_res8[0][3] = 0;
  local_res8[0][4] = 0;
  *local_res8[0] = param_1;
  *(undefined4 *)(local_res8[0] + 1) = param_2;
  *(undefined1 *)((longlong)local_res8[0] + 0xc) = param_3;
  uVar1 = *(undefined8 *)(param_4 + 2);
  local_res8[0][2] = *(undefined8 *)param_4;
  local_res8[0][3] = uVar1;
  local_res8[0][4] = *(undefined8 *)(param_4 + 4);
  if (*param_4 < 0) {
    pvVar3 = (void *)WinHvpSetupVpStatePfnBuffer(param_6,local_res8[0] + 5,local_res18);
    if (pvVar3 == (void *)0x0) {
      uVar2 = 0xc000009a;
      goto LAB_140022242;
    }
    iVar4 = local_res18[0];
  }
  else if (0x1000 < param_6) {
    uVar2 = 0xc000000d;
    goto LAB_140022242;
  }
  uVar2 = WinHvpVariableHeaderHypercall
                    (0xe3,iVar4,*(undefined8 *)(local_50 + 0x18),*(undefined8 *)(local_50 + 0x28));
  if (-1 < (int)uVar2) {
    _Src = pvVar3;
    if (-1 < *param_4) {
      _Src = local_res20;
    }
    memmove(param_5,_Src,(ulonglong)param_6);
  }
  if (pvVar3 != (void *)0x0) {
    ExFreePoolWithTag(pvVar3,0x55764857);
  }
LAB_140022242:
  (*local_40)(local_78[0]);
  return uVar2;
}



===== WinHvMapVpStatePage @ 140022280 =====

void WinHvMapVpStatePage(undefined8 param_1,undefined4 param_2,undefined2 param_3,
                        undefined8 *param_4)

{
                    /* 0x22280  118  WinHvMapVpStatePage */
  WinHvMapVpStatePage2(param_1,param_2,param_3,0xf,-1,param_4);
  return;
}



===== WinHvSetVpState @ 1400222b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WinHvSetVpState(undefined8 param_1,undefined4 param_2,undefined1 param_3,int *param_4,
                    void *param_5,uint param_6)

{
  undefined8 uVar1;
  uint uVar2;
  void *_Dst;
  undefined8 *local_res8;
  uint local_res18 [2];
  undefined8 local_58 [5];
  longlong local_30;
  code *local_20;
  
                    /* 0x222b0  179  WinHvSetVpState */
  _Dst = (void *)0x0;
  memset(local_58,0,0x40);
  local_res8 = (undefined8 *)0x0;
  local_res18[0] = 0;
  WinHvpSetupHypercall(&local_res8,(undefined8 *)0x0,(longlong)local_58);
  *local_res8 = 0;
  local_res8[1] = 0;
  local_res8[2] = 0;
  local_res8[3] = 0;
  local_res8[4] = 0;
  *local_res8 = param_1;
  *(undefined4 *)(local_res8 + 1) = param_2;
  *(undefined1 *)((longlong)local_res8 + 0xc) = param_3;
  uVar1 = *(undefined8 *)(param_4 + 2);
  local_res8[2] = *(undefined8 *)param_4;
  local_res8[3] = uVar1;
  local_res8[4] = *(undefined8 *)(param_4 + 4);
  if (*param_4 < 0) {
    _Dst = (void *)WinHvpSetupVpStatePfnBuffer(param_6,local_res8 + 5,(int *)local_res18);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
      goto LAB_1400223f2;
    }
    memmove(_Dst,param_5,(ulonglong)param_6);
    uVar2 = local_res18[0];
  }
  else {
    uVar2 = param_6 + 7 & 0xfffffff8;
    if (0x1000 < (ulonglong)uVar2 + 0x28) {
      uVar2 = 0xc000000d;
      goto LAB_1400223f2;
    }
    memmove(local_res8 + 5,param_5,(ulonglong)param_6);
  }
  uVar2 = WinHvpVariableHeaderHypercall(0xe4,uVar2,*(undefined8 *)(local_30 + 0x18),0);
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x55764857);
  }
LAB_1400223f2:
  (*local_20)(local_58[0]);
  return uVar2;
}



===== WinHvMapStatsPage @ 140022420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WinHvMapStatsPage(uint param_1,undefined8 param_2,longlong *param_3,undefined8 *param_4)

{
  undefined1 auVar1 [16];
  bool bVar2;
  undefined1 auVar3 [16];
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint *puVar10;
  longlong lVar11;
  undefined *puVar12;
  longlong lVar13;
  bool bVar14;
  uint uVar15;
  uint uVar16;
  undefined1 auStack_f8 [32];
  char local_d8;
  char local_d7 [7];
  longlong *local_d0;
  undefined8 *local_c8;
  longlong local_c0;
  ulonglong local_b8;
  undefined8 uStack_b0;
  ulonglong local_a8;
  uint *local_a0;
  undefined1 local_98 [16];
  ulonglong local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  ulonglong local_50;
  
                    /* 0x22420  117  WinHvMapStatsPage */
  local_50 = __security_cookie ^ (ulonglong)auStack_f8;
  local_c0 = -1;
  *param_3 = 0;
  bVar14 = WinHvpConnected == '\0';
  uVar5 = 0;
  local_98._0_8_ = param_2;
  bVar2 = false;
  local_88 = 0;
  uStack_80 = 0;
  local_58 = local_58 & 0xffffffff00000000;
  local_78 = 0;
  uStack_70 = 0;
  local_a8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_a0 = (uint *)((ulonglong)local_a0 & 0xffffffff00000000);
  local_b8 = 0;
  uStack_b0 = 0;
  *param_4 = 0;
  local_d7[0] = '\0';
  if (bVar14) {
    return 0xc0350002;
  }
  local_d0 = param_3;
  local_c8 = param_4;
  uVar6 = Feature_450263353__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    plVar7 = (longlong *)ExAllocatePool2(0x102,8,0x4f764857);
  }
  else {
    plVar7 = (longlong *)ExAllocatePool2();
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = 0;
    }
  }
  if (plVar7 == (longlong *)0x0) {
LAB_1400224ea:
    uVar5 = 0xc000009a;
    cVar4 = '\0';
  }
  else {
    bVar2 = true;
    auVar1 = *(undefined1 (*) [16])local_98._0_8_;
    uVar6 = auVar1._8_8_;
    uVar15 = auVar1._0_4_;
    uVar16 = auVar1._4_4_;
    local_98 = auVar1;
    if (((param_1 == 0x10001) || (param_1 == 0x10002)) &&
       (((uVar6 & 0x100000000) != 0 || (auVar1._0_8_ == -1)))) {
      local_98._8_8_ = uVar6;
      local_98._0_8_ = 0xffffffffffffffff;
      auVar3 = local_98;
      local_98._0_4_ = 0xffffffff;
      local_98._4_4_ = 0xffffffff;
      uVar15 = local_98._0_4_;
      uVar16 = local_98._4_4_;
      local_98 = auVar3;
    }
    ExAcquireFastMutex();
    uVar8 = Feature_450263353__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar8 != 0) {
      local_a0 = (uint *)0x0;
      local_b8 = (ulonglong)param_1;
      uStack_b0 = CONCAT44(uVar16,uVar15);
      local_a8 = uVar6;
      lVar9 = RtlLookupElementGenericTable(&WinHvpStatsTable,&local_b8);
      if (lVar9 != 0) {
        lVar9 = *(longlong *)(lVar9 + 0x18);
        *(int *)(lVar9 + 0x20) = *(int *)(lVar9 + 0x20) + 1;
        *plVar7 = lVar9;
        *local_d0 = *(longlong *)(lVar9 + 0x28);
        goto LAB_1400225a6;
      }
      puVar10 = (uint *)ExAllocatePool2(0x102,0x38,0x4f764857);
      if (puVar10 != (uint *)0x0) {
        *plVar7 = (longlong)puVar10;
        puVar10[0] = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = 0;
        puVar12 = &WinHvpStatsTable;
        puVar10[4] = 0;
        puVar10[5] = 0;
        puVar10[6] = 0;
        puVar10[7] = 0;
        puVar10[8] = 0;
        puVar10[9] = 0;
        puVar10[10] = 0;
        puVar10[0xb] = 0;
        puVar10[0xc] = 0;
        puVar10[0xd] = 0;
        *puVar10 = param_1;
        puVar10[2] = uVar15;
        puVar10[3] = uVar16;
        puVar10[4] = auVar1._8_4_;
        puVar10[5] = auVar1._12_4_;
        puVar10[8] = 1;
        local_a0 = puVar10;
        lVar9 = RtlInsertElementGenericTable(&WinHvpStatsTable,&local_b8,0x20,local_d7);
        if (lVar9 != 0) {
          *plVar7 = (longlong)puVar10;
          goto LAB_14002262a;
        }
      }
      goto LAB_1400224ea;
    }
    local_58 = 0;
    uStack_60 = 0;
    local_68 = 0;
    uStack_70 = 0;
    puVar12 = &WinHvpStatsTable;
    local_88 = (ulonglong)param_1;
    uStack_80 = CONCAT44(uVar16,uVar15);
    local_78 = uVar6;
    lVar9 = RtlInsertElementGenericTable(&WinHvpStatsTable,&local_88,0x38,local_d7);
    *plVar7 = lVar9;
    if (lVar9 == 0) goto LAB_1400224ea;
    *(int *)(lVar9 + 0x20) = *(int *)(lVar9 + 0x20) + 1;
    if (local_d7[0] == '\0') {
      *local_d0 = *(longlong *)(*plVar7 + 0x28);
LAB_1400225a6:
      *local_c8 = plVar7;
      goto LAB_1400227dd;
    }
LAB_14002262a:
    local_d8 = '\x01';
    uVar5 = WinHvpIssueMapStatsPageHypercall(puVar12,param_1,(undefined8 *)local_98,&local_c0);
    lVar9 = local_c0;
    if (-1 < (int)uVar5) {
      lVar13 = local_c0 << 0xc;
      lVar11 = MmMapIoSpaceEx(lVar13,0x1000,4);
      if (lVar11 != 0) {
        uVar6 = Feature_450263353__private_IsEnabledDeviceUsageNoInline();
        lVar9 = *plVar7;
        lVar13 = lVar13 >> 0xc;
        *(undefined1 *)(lVar9 + 0x30) = 0;
        if ((int)uVar6 == 0) {
          *(longlong *)(*plVar7 + 0x28) = lVar11;
          *(longlong *)(*plVar7 + 0x18) = lVar13;
        }
        else {
          *(longlong *)(lVar9 + 0x28) = lVar11;
          *(longlong *)(lVar9 + 0x18) = lVar13;
        }
        *local_d0 = lVar11;
        goto LAB_1400225a6;
      }
      uVar5 = 0xc000009a;
    }
    if ((lVar9 != -1) && (cVar4 = WinHvIsOverlayMapLocationRequired(), cVar4 != '\0')) {
      WinHvpFreeOverlayPhysicalPage(lVar9);
    }
    cVar4 = local_d8;
  }
  uVar6 = Feature_450263353__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    if (plVar7 != (longlong *)0x0) {
      ExFreePoolWithTag(plVar7,0x4f764857);
    }
    if (cVar4 != '\0') {
      RtlDeleteElementGenericTable(&WinHvpStatsTable,&local_88);
    }
  }
  else {
    lVar9 = 0;
    if (plVar7 != (longlong *)0x0) {
      lVar9 = *plVar7;
      ExFreePoolWithTag(plVar7,0x4f764857);
    }
    if (cVar4 != '\0') {
      RtlDeleteElementGenericTable(&WinHvpStatsTable,&local_b8);
    }
    if (lVar9 != 0) {
      ExFreePoolWithTag(lVar9,0x4f764857);
    }
  }
  if (!bVar2) {
    return uVar5;
  }
LAB_1400227dd:
  ExReleaseFastMutex(&WinHvpStatsTableLock);
  return uVar5;
}



===== WinHvUnmapStatsPage @ 140022820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WinHvUnmapStatsPage(undefined8 *param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  char cVar4;
  ulonglong uVar5;
  undefined1 auStack_b8 [32];
  uint *local_98 [2];
  longlong local_88 [7];
  code *local_50;
  ulonglong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong local_10;
  
                    /* 0x22820  191  WinHvUnmapStatsPage */
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  local_98[0] = (uint *)0x0;
  memset(local_88,0,0x40);
  if (WinHvpConnected != '\0') {
    uVar5 = Feature_450263353__private_IsEnabledDeviceUsageNoInline();
    puVar2 = (uint *)*param_1;
    *param_1 = 0;
    if ((int)uVar5 == 0) {
      ExFreePoolWithTag(param_1);
      ExAcquireFastMutex(&WinHvpStatsTableLock);
      puVar1 = puVar2 + 8;
      *puVar1 = *puVar1 - 1;
      if (*puVar1 == 0) {
        WinHvpSetupHypercall(local_98,(undefined8 *)0x0,(longlong)local_88);
        *local_98[0] = *puVar2;
        uVar3 = *(undefined8 *)(puVar2 + 4);
        *(undefined8 *)(local_98[0] + 2) = *(undefined8 *)(puVar2 + 2);
        *(undefined8 *)(local_98[0] + 4) = uVar3;
        WinHvpSimplePoolHypercall_CallViaMacro(local_88[0],0x6d);
        (*local_50)(local_88[0]);
      }
      if (puVar2[8] == 0) {
        cVar4 = WinHvIsOverlayMapLocationRequired();
        if (cVar4 != '\0') {
          WinHvpFreeOverlayPhysicalPage(*(undefined8 *)(puVar2 + 6));
        }
        MmUnmapIoSpace(*(undefined8 *)(puVar2 + 10),0x1000);
        RtlDeleteElementGenericTable(&WinHvpStatsTable,puVar2);
      }
    }
    else {
      local_48 = 0;
      uStack_40 = 0;
      local_18 = local_18 & 0xffffffff00000000;
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      uStack_20 = 0;
      ExFreePoolWithTag();
      if (puVar2 == (uint *)0x0) {
        return;
      }
      ExAcquireFastMutex(&WinHvpStatsTableLock);
      puVar1 = puVar2 + 8;
      *puVar1 = *puVar1 - 1;
      if ((*puVar1 == 0) && (*(char *)((longlong)puVar2 + 0x31) == '\0')) {
        WinHvpSetupHypercall(local_98,(undefined8 *)0x0,(longlong)local_88);
        *local_98[0] = *puVar2;
        uVar3 = *(undefined8 *)(puVar2 + 4);
        *(undefined8 *)(local_98[0] + 2) = *(undefined8 *)(puVar2 + 2);
        *(undefined8 *)(local_98[0] + 4) = uVar3;
        WinHvpSimplePoolHypercall_CallViaMacro(local_88[0],0x6d);
        (*local_50)(local_88[0]);
      }
      if (puVar2[8] == 0) {
        if (*(char *)((longlong)puVar2 + 0x31) == '\0') {
          uStack_30 = 0;
          local_18 = 0;
          local_28 = 0;
          uStack_20 = 0;
          local_48 = (ulonglong)*puVar2;
          uStack_40 = *(undefined8 *)(puVar2 + 2);
          local_38 = *(undefined8 *)(puVar2 + 4);
          WinHvpUnlinkStatsTableEntry(&local_48);
        }
        cVar4 = WinHvIsOverlayMapLocationRequired();
        if (cVar4 != '\0') {
          WinHvpFreeOverlayPhysicalPage(*(undefined8 *)(puVar2 + 6));
        }
        MmUnmapIoSpace(*(undefined8 *)(puVar2 + 10),0x1000);
        ExFreePoolWithTag(puVar2,0x4f764857);
      }
    }
    ExReleaseFastMutex(&WinHvpStatsTableLock);
  }
  return;
}



===== entry @ 140025010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140025044 =====

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



===== DllInitialize @ 140025080 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DllInitialize(undefined2 *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
                    /* 0x25080  1  DllInitialize */
  __security_init_cookie();
  DAT_1400158f8 = ExAllocatePool2(0x40,*param_1,0x55764857);
  if (DAT_1400158f8 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    _DAT_1400158f2 = *param_1;
    RtlCopyUnicodeString(&WinHvpRegistryPath,param_1);
    wil_InitializeFeatureStaging();
    uVar2 = WinHvpInitialize();
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      ExFreePoolWithTag(DAT_1400158f8,0x55764857);
      DAT_1400158f8 = 0;
      wil_UninitializeFeatureStaging();
    }
  }
  return uVar1;
}



===== DriverEntry @ 140025120 =====

void DriverEntry(void)

{
  code *pcVar1;
  
                    /* 0x25120  3  DriverEntry */
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WinHvpHypervisorDriverInitialization @ 140025130 =====

undefined8 WinHvpHypervisorDriverInitialization(undefined8 param_1)

{
  WinHvpHypervisorDriver = param_1;
  return 0;
}



===== wil_InitializeFeatureStaging @ 140025144 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140025234 =====

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



===== WinHvpInitializeHypercallSupport @ 14002531c =====

int WinHvpInitializeHypercallSupport(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = WinHvpInitializeHypercallLookasideBuffer();
  if (-1 < iVar1) {
    uVar2 = WinHvpInitializeFallbackHypercallBuffers();
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  WinHvpCleanupHypercallSupport();
  return iVar1;
}



===== WinHvpInitializeOverlaySupport @ 14002534c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WinHvpInitializeOverlaySupport(void)

{
  _DAT_140015a88 = 0;
  _DAT_140015a90 = 0;
  _WinHvpOverlayTableLock = 1;
  KeInitializeEvent(&DAT_140015a98,1,0);
  RtlInitializeGenericTable
            (&WinHvpOverlayTable,WinHvpCompareOverlayTableEntry,WinHvpAllocateOverlayTableEntry,
             WinHvpFreeOverlayTableEntry,0);
  return;
}



===== WinHvpInitializeSynicSupport @ 1400253bc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WinHvpInitializeSynicSupport(void)

{
  WinHvpSynicProcessorsBitmap =
       ExAllocatePool2(0x40,(ulonglong)(WinHvpMaximumProcessorCount + 0x1fU >> 5) << 2,0x55764857);
  if (WinHvpSynicProcessorsBitmap != 0) {
    _DAT_140015948 = 0;
    _DAT_140015950 = 0;
    _WinHvpSynicChangeLock = 1;
    KeInitializeEvent(&DAT_140015958,1,0);
    WinHvpEventRingControl = ExAllocatePool2(0x40,WinHvpMaximumProcessorCount << 6,0x55764857);
    if (WinHvpEventRingControl != 0) {
      return 0;
    }
  }
  if (WinHvpSynicProcessorsBitmap != 0) {
    ExFreePoolWithTag(WinHvpSynicProcessorsBitmap,0x55764857);
    WinHvpSynicProcessorsBitmap = 0;
  }
  if (WinHvpEventRingControl != 0) {
    ExFreePoolWithTag(WinHvpEventRingControl,0x55764857);
    WinHvpEventRingControl = 0;
  }
  return 0xc000009a;
}



===== WinHvpAllocNumaMaps @ 1400254b4 =====

undefined8 WinHvpAllocNumaMaps(void)

{
  undefined8 uVar1;
  
  WinHvpMaximumProcessorCount = KeQueryMaximumProcessorCountEx(0xffff);
  WinHvpProcessorToNode = ExAllocatePool2(0x40,WinHvpMaximumProcessorCount * 2,0x55764857);
  if (WinHvpProcessorToNode == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    memset(&WinHvpNodeToProcessorMask,0,0x400);
    uVar1 = 0;
    WinHvpNodeCount = 1;
  }
  return uVar1;
}



===== WinHvpBuildNumaMaps @ 140025528 =====

undefined8 WinHvpBuildNumaMaps(void)

{
  undefined2 uVar1;
  ulonglong uVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ushort uVar7;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  uVar5 = WinHvpAllocNumaMaps();
  if (-1 < (int)uVar5) {
    uVar3 = KeQueryHighestNodeNumber();
    uVar7 = 0;
    WinHvpNodeCount = uVar3 + 1;
    if (WinHvpNodeCount != 0) {
      do {
        KeQueryNodeActiveAffinity(uVar7,&WinHvpNodeToProcessorMask + (ulonglong)uVar7 * 0x10,0);
        uVar6 = *(ulonglong *)(&WinHvpNodeToProcessorMask + (ulonglong)uVar7 * 0x10);
        uVar1 = *(undefined2 *)(&DAT_1400154e8 + (ulonglong)uVar7 * 0x10);
        while( true ) {
          uVar2 = 0;
          if (uVar6 != 0) {
            for (; (uVar6 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
            }
          }
          if (uVar6 == 0) break;
          uVar6 = uVar6 ^ 1L << (uVar2 & 0x3f);
          local_res8[0] = (uint)CONCAT12((char)uVar2,uVar1);
          uVar4 = KeGetProcessorIndexFromNumber(local_res8);
          *(ushort *)(WinHvpProcessorToNode + (ulonglong)uVar4 * 2) = uVar7;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < WinHvpNodeCount);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== WinHvpTeardownNumaMaps @ 140025600 =====

void WinHvpTeardownNumaMaps(void)

{
  if (WinHvpProcessorToNode != 0) {
    ExFreePoolWithTag(WinHvpProcessorToNode,0x55764857);
    WinHvpProcessorToNode = 0;
    WinHvpNodeCount = 0;
  }
  return;
}



===== WinHvpAllocateDataPageArray @ 14002563c =====

uint WinHvpAllocateDataPageArray(void)

{
  WinHvpVpDataPages = ExAllocatePool2(0x40,WinHvpMaximumProcessorCount * 0x30,0x55764857);
  return ~-(uint)(WinHvpVpDataPages != 0) & 0xc000009a;
}



===== WinHvpInitVmmCapabilities @ 140025684 =====

uint WinHvpInitVmmCapabilities(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (WinHvpVmManagement != '\0') {
    WinHvpVmmCapabilities = (void *)ExAllocatePool2(0x40,0xfe8);
    if (WinHvpVmmCapabilities == (void *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      uVar1 = WinHvGetPartitionPropertyEx(0xffffffffffffffff,0x90007,0,WinHvpVmmCapabilities);
      if ((int)uVar1 < 0) {
        memset(WinHvpVmmCapabilities,0,0xfe8);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



===== WinHvpInitialize @ 1400256fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WinHvpInitialize(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  HviGetHypervisorFeatures(&local_28);
  WinHvpCpuManagement = (byte)(local_28 >> 0x2c) & 1;
  WinHvpVmManagement = WinHvpCpuManagement;
  if ((local_28 >> 0x2c & 1) == 0) {
    local_28 = 0;
    uStack_20 = 0;
    HviGetHypervisorFeatures(&local_28);
    WinHvpVmManagement = (byte)(local_28 >> 0x20) & 1;
    if ((local_28 & 0x100000000) != 0) goto LAB_1400257e9;
    WinHvpRunningLoopback = 1;
    uVar2 = WinHvpAllocNumaMaps();
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_14002578d;
    uVar1 = WinHvpInitializeHypercallSupport();
    uVar4 = (ulonglong)uVar1;
  }
  else {
LAB_1400257e9:
    _WinHvpOsVersionInfo = 0x11c;
    RtlGetVersion(&WinHvpOsVersionInfo);
    uVar2 = WinHvpBuildNumaMaps();
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_14002578d;
    uVar1 = WinHvpEnvInit();
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_14002578d;
    uVar1 = WinHvpInitializeRmSupport();
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_14002578d;
    uVar1 = WinHvpInitializeSystemSupport();
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_14002578d;
    WinHvpInitializeStatsSupport();
    WinHvpInitializePartitionSupport();
    _DAT_140015248 = 0;
    _DAT_140015250 = 0;
    _WinHvpPortTableAllocationMutex = 1;
    KeInitializeEvent(&DAT_140015258,1);
    WinHvpInitializePersistenceSupport();
    uVar1 = WinHvpAllocateDataPageArray();
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_14002578d;
    uVar2 = WinHvpInitializeSynicSupport();
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_14002578d;
    uVar1 = WinHvpInitializeHypercallSupport();
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_14002578d;
    WinHvpInitializeOverlaySupport();
    uVar3 = HviIsAnyHypervisorPresent();
    if ((char)uVar3 == '\0') {
      WinHvpDllLoadSuccessful = 1;
      return 0;
    }
    uVar1 = WinHvpConnectToHypervisor();
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar2 = WinHvpBuildVpIndexCache();
      uVar4 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        WinHvpConnectToSynic();
        uVar1 = WinHvpBuildLpIndexCache();
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar1 = WinHvpInitializeXSchedulerSupport();
          uVar4 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = WinHvpInitVmmCapabilities();
            uVar4 = (ulonglong)uVar1;
          }
        }
      }
    }
    WinHvpPostHypervisorInitializationStatus = (uint)uVar4;
    uVar1 = WinHvpPostHypervisorInitializationStatus;
  }
  if (-1 < (int)uVar1) {
    WinHvpDllLoadSuccessful = 1;
    return 0;
  }
LAB_14002578d:
  WinHvpTeardownVpIndexCache();
  WinHvpCleanupSynicSupport();
  WinHvpTeardownXSchedulerSupport();
  WinHvpTeardownLpIndexCache();
  WinHvpCleanupPortIdSupport();
  WinHvpCleanupPartitionSupport();
  WinHvpCleanupRmSupport();
  WinHvpCleanupSystemSupport();
  WinHvpFreeVmmCapabilities();
  WinHvpCleanupHypercallSupport();
  WinHvpDisconnectFromHypervisor();
  WinHvpFreeAllVpDataPages();
  WinHvpTeardownNumaMaps();
  WinHvpEnvUninit();
  return uVar4;
}



===== WinHvpInitializePartitionSupport @ 14002591c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WinHvpInitializePartitionSupport(void)

{
  _WinHvpPartitionArrayLock = 0;
  KeInitializeEvent(&WinHvpGlobalAsyncEvent,1);
  KeInitializeDpc(&WinHvpGlobalAsyncDpc,WinHvpOnCallCompletionDpcRoutine,0);
  _DAT_140015348 = 0;
  _DAT_140015350 = 0;
  _WinHvpGlobalAsyncMutex = 1;
  KeInitializeEvent(&DAT_140015358,1);
  return;
}



===== WinHvpInitializeStatsSupport @ 1400259a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WinHvpInitializeStatsSupport(void)

{
  _DAT_1400151a8 = 0;
  _DAT_1400151b0 = 0;
  _WinHvpStatsTableLock = 1;
  KeInitializeEvent(&DAT_1400151b8,1,0);
  RtlInitializeGenericTable
            (&WinHvpStatsTable,WinHvpCompareStatsTableEntry,WinHvpAllocateStatsTableEntry,
             WinHvpFreeStatsTableEntry,0);
  return;
}


