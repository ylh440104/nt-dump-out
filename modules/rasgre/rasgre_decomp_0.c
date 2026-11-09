
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== GreScheduleWorkItem @ 1c0001020 =====

undefined8 GreScheduleWorkItem(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = NdisAllocateIoWorkItem(DAT_1c0007208);
  uVar2 = 0;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    NdisQueueIoWorkItem(lVar1,param_1,param_2);
  }
  return uVar2;
}



===== WPP_SF_D @ 1c0001084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 1c00010c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001110 =====

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



===== WPP_SF_ @ 1c0001144 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_qq @ 1c0001170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== GreAdapterDereferenceCleanup @ 1c00011c0 =====

void GreAdapterDereferenceCleanup(longlong param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + -8),&local_res8,0);
  *(undefined4 *)(param_1 + 0x10) = 1;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + -8),&local_res8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,(undefined8 *)(param_1 + -0x18));
  }
  NdisMPauseComplete(*(undefined8 *)(param_1 + -0x18));
  return;
}



===== GreCoDeactivateVc @ 1c0001260 =====

undefined8 GreCoDeactivateVc(void)

{
  return 0;
}



===== GreCoOidRequest @ 1c0001270 =====

undefined8 GreCoOidRequest(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_3 + 4);
  uVar2 = 0;
  if (iVar1 == 0) {
LAB_1c000129f:
    uVar3 = GreMpQueryInformation((ulonglong)uVar2,param_2,param_3);
  }
  else {
    if (iVar1 == 1) {
      if (*(int *)(param_3 + 0x20) == -0x2fefeff) {
        *(undefined8 *)(param_3 + 0x34) = 0;
        return 0;
      }
    }
    else {
      uVar2 = 1;
      if (iVar1 == 2) goto LAB_1c000129f;
    }
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== _guard_check_icall @ 1c00012b0 =====

void _guard_check_icall(void)

{
  return;
}



===== GreMiniportPause @ 1c00012c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GreMiniportPause(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x10),&local_res8,0);
  *(undefined4 *)(param_1 + 0x28) = 3;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res8);
  piVar1 = (int *)(param_1 + 0x18);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x20))();
  }
  return 0x103;
}



===== GreMiniportRestart @ 1c0001370 =====

undefined8 GreMiniportRestart(longlong param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x10),&local_res8,0);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(code **)(param_1 + 0x20) = GreAdapterDereferenceCleanup;
  LOCK();
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x28) = 2;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res8);
  return 0;
}



===== GreMpQueryInformation @ 1c0001414 =====

undefined8 GreMpQueryInformation(ulonglong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 *_Src;
  uint uVar3;
  undefined8 uVar4;
  undefined8 local_res8;
  
  uVar4 = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  uVar2 = local_res8;
  _Src = &local_res8;
  iVar1 = *(int *)(param_3 + 0x20);
  uVar3 = 4;
  local_res8._4_4_ = (undefined4)(param_1 >> 0x20);
  if (iVar1 == 0x10103) {
    local_res8 = CONCAT44(local_res8._4_4_,0xc);
  }
  else if (iVar1 == 0x1010c) {
    local_res8 = CONCAT44(local_res8._4_4_,0xffffff);
  }
  else if (iVar1 == 0x10111) {
    local_res8 = CONCAT44(local_res8._4_4_,0x5dc);
  }
  else if (iVar1 == 0x4010105) {
    local_res8 = CONCAT44(local_res8._4_4_,0xf);
  }
  else {
    if (iVar1 == 0x4010180) {
      _Src = (undefined8 *)&DAT_1c0009274;
    }
    else {
      if (iVar1 != 0x4010285) {
        return 0xc00000bb;
      }
      if (param_2 == 0) {
        return 0xc0010015;
      }
      _Src = (undefined8 *)(param_2 + 0x94);
    }
    uVar3 = 0x10;
    local_res8 = uVar2;
  }
  if (*(uint *)(param_3 + 0x30) < uVar3) {
    *(uint *)(param_3 + 0x38) = uVar3;
    uVar4 = 0xc0010016;
  }
  else {
    memcpy(*(void **)(param_3 + 0x28),_Src,(ulonglong)uVar3);
    *(uint *)(param_3 + 0x34) = uVar3;
  }
  return uVar4;
}



===== GreProcessPacket @ 1c00014f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GreProcessPacket(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  uint uVar11;
  bool bVar12;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined4 local_58;
  longlong local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  LOCK();
  _DAT_1c000933c = _DAT_1c000933c + 1;
  UNLOCK();
  KeGetProcessorNumberFromIndex(*(undefined4 *)(param_1 + 0x30),&local_58);
  local_50 = 1L << (local_58._2_1_ & 0x3f);
  uStack_48 = CONCAT62(uStack_48._2_6_,(undefined2)local_58);
  KeSetSystemGroupAffinityThread(&local_50,&local_40);
  puVar10 = auStack_78;
  plVar1 = (longlong *)(param_1 + 8);
  do {
    NdisWaitEvent(param_1 + 0x18,0);
    uVar9 = KfRaiseIrql(2);
    if ((longlong *)*plVar1 == plVar1) {
LAB_1c00016c1:
      *(undefined8 *)(puVar10 + -8) = 0x1c00016cb;
      KeLowerIrql(uVar9);
      *(undefined8 *)(puVar10 + -8) = 0x1c00016dc;
      KeRevertToUserGroupAffinityThread(puVar10 + 0x38);
      LOCK();
      _DAT_1c000933c = _DAT_1c000933c + -1;
      UNLOCK();
      *(undefined8 *)(puVar10 + -8) = 0x1c00016f1;
      PsTerminateSystemThread(0);
      *(undefined8 *)(puVar10 + -8) = 0x1c0001703;
      return;
    }
    uVar11 = 0;
    while ((plVar4 = (longlong *)*plVar1, plVar4 != plVar1 && (uVar11 = uVar11 + 1, uVar11 < 0x1a)))
    {
      if (((longlong *)plVar4[1] != plVar1) ||
         (lVar5 = *plVar4, *(longlong **)(lVar5 + 8) != plVar4)) {
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        puVar10 = auStack_70;
        goto LAB_1c00016c1;
      }
      *plVar1 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar1;
      if ((int)plVar4[6] == 0) {
        GreInjectSendPacket((longlong)plVar4);
      }
      else if ((int)plVar4[6] == 1) {
        GreIndicateRecvPacket((longlong)plVar4);
      }
      else {
        lVar5 = plVar4[5];
        lVar6 = plVar4[2];
        uVar7 = *(undefined8 *)(lVar6 + 0x18);
        NdisFreeNetBufferListContext(lVar6,0x40);
        NdisFreeCloneNetBufferList(lVar6,0);
        NdisMCoSendNetBufferListsComplete(*(undefined8 *)(lVar5 + 0x38),uVar7,1);
        piVar2 = (int *)(lVar5 + 0x40);
        LOCK();
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(lVar5 + 0x48))();
        }
        LOCK();
        iVar3 = DAT_1c0009260 + -1;
        UNLOCK();
        bVar12 = DAT_1c0009260 == 1;
        DAT_1c0009260 = iVar3;
        if (bVar12) {
          (*DAT_1c0009268)(&DAT_1c0009260);
        }
      }
    }
    if (uVar11 < 0x1a) {
      NdisResetEvent(param_1 + 0x18);
    }
    KeLowerIrql(uVar9);
  } while( true );
}



===== GreQueuePacket @ 1c0001724 =====

void GreQueuePacket(longlong param_1,undefined8 *param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeGetCurrentProcessorNumberEx(0);
  puVar6 = auStack_28;
  lVar5 = (ulonglong)
          (*(uint *)(param_1 + 0xd0) +
          ((-(uint)(uVar2 < DAT_1c0009338) & uVar2) - *(uint *)(param_1 + 0xd0) / 3) * 3) * 0x38;
  puVar4 = (undefined8 *)(DAT_1c0009340 + 8 + lVar5);
  puVar3 = (undefined8 *)puVar4[1];
  puVar7 = (undefined8 *)*puVar4;
  if ((undefined8 *)*puVar3 != puVar4) {
    puVar4 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar3 = (undefined8 *)(*pcVar1)();
    puVar6 = auStack_20;
  }
  *param_2 = puVar4;
  param_2[1] = puVar3;
  *puVar3 = param_2;
  puVar4[1] = param_2;
  if (puVar7 == puVar4) {
    *(undefined8 *)(puVar6 + -8) = 0x1c00017b4;
    NdisSetEvent(DAT_1c0009340 + 0x18 + lVar5);
  }
  return;
}



===== GreCheckTunnelState @ 1c00017cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GreCheckTunnelState(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockRead(DAT_1c0009258,&local_res10,1);
  if ((DAT_1c0009270 & 2) == 0) {
    NdisReleaseRWLock(DAT_1c0009258);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1,(char)DAT_1c0009270);
    }
    uVar2 = 0xc023002a;
  }
  else {
    LOCK();
    DAT_1c0009260 = DAT_1c0009260 + 1;
    UNLOCK();
    NdisReleaseRWLock(DAT_1c0009258,&local_res10);
    NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x20),&local_res10,1);
    if ((*(uint *)(param_1 + 0x58) & 0x40) == 0) {
      LOCK();
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      UNLOCK();
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res10);
      uVar2 = 0;
    }
    else {
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20));
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                  &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1,
                  (char)*(undefined4 *)(param_1 + 0x58));
      }
      LOCK();
      iVar1 = DAT_1c0009260 + -1;
      UNLOCK();
      bVar3 = DAT_1c0009260 == 1;
      DAT_1c0009260 = iVar1;
      if (bVar3) {
        (*DAT_1c0009268)(&DAT_1c0009260);
      }
      uVar2 = 0xc0000001;
    }
  }
  return uVar2;
}



===== GreCleanupTunnel @ 1c0001944 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GreCleanupTunnel(longlong param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_res8,0);
  piVar1 = (int *)(param_1 + 0x28);
  LOCK();
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar3 = *(uint *)(param_1 + 0x58);
  *(uint *)(param_1 + 0x58) = uVar3 | 0x40;
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 0x10) == 0) {
      if ((uVar3 & 4) != 0) {
        *(uint *)(param_1 + 0x58) = uVar3 & 0xfffffffb | 0x40;
        NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res8);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                   &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
        }
        NdisCmMakeCallComplete
                  (*(undefined4 *)(param_1 + 0x90),*(undefined8 *)(param_1 + 0x38),0,0,
                   *(undefined8 *)(param_1 + 0x50));
        NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_res8,0);
        *(undefined8 *)(param_1 + 0x50) = 0;
      }
      if ((*(uint *)(param_1 + 0x58) >> 8 & 1) != 0) {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xfffffeff;
        LOCK();
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res8);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                   &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
        }
        GreScheduleWorkItem(GreDeleteHostRouteWorkItem,param_1);
        NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_res8,0);
      }
      if ((char)*(uint *)(param_1 + 0x58) < '\0') {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffffff7f;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                   &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
        }
        GreRemoveTunnel(param_1);
      }
      if ((*(uint *)(param_1 + 0x58) & 0x20) != 0) {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffffffdf;
        NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res8);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                   &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
        }
        NdisCmCloseCallComplete(0,*(undefined8 *)(param_1 + 0x38),0);
        NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_res8,0);
      }
      uVar5 = *(undefined8 *)(param_1 + 0x20);
    }
    else {
      uVar5 = *(undefined8 *)(param_1 + 0x20);
      if ((uVar3 & 8) != 0) {
        *(uint *)(param_1 + 0x58) = uVar3 & 0xffffffef | 0x40;
        NdisReleaseRWLock();
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                   &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
        }
        iVar4 = NdisMCmDeactivateVc(*(undefined8 *)(param_1 + 0x38));
        if (iVar4 != 0x103) {
          GreCmDeactivateVcComplete((char)iVar4,param_1);
        }
        goto LAB_1c0001c63;
      }
    }
    NdisReleaseRWLock(uVar5,&local_res8);
  }
  else {
    *(uint *)(param_1 + 0x58) = uVar3 & 0xfffffffd | 0x50;
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res8);
    piVar2 = (int *)(param_1 + 0x40);
    LOCK();
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      (**(code **)(param_1 + 0x48))();
    }
  }
LAB_1c0001c63:
  LOCK();
  iVar4 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar4 == 1) {
    (**(code **)(param_1 + 0x30))(piVar1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  return;
}



===== GreCmCloseAf @ 1c0001cd0 =====

undefined8 GreCmCloseAf(void)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,DAT_1c0009328);
  }
  DAT_1c0009328 = 0;
  return 0;
}



===== GreCmCloseCall @ 1c0001d30 =====

undefined8 GreCmCloseCall(longlong param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_res8,0);
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x20;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res8);
  GreCleanupTunnel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  return 0x103;
}



===== GreCmCreateVc @ 1c0001e10 =====

undefined4 GreCmCreateVc(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined *puVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  undefined *puVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_2);
  }
  uVar9 = 0;
  puVar10 = (undefined *)0x30657247;
  *param_3 = 0;
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,0xa8);
  puVar8 = auStack_38;
  if (puVar5 == (undefined8 *)0x0) {
    uVar9 = 0xc000009a;
  }
  else {
    *(undefined4 *)(puVar5 + 5) = 0;
    puVar5[6] = GreTunnelDereferenceCleanup;
    puVar5[9] = GreVcDereferenceCleanup;
    *(undefined4 *)(puVar5 + 8) = 0;
    lVar6 = NdisAllocateRWLock(DAT_1c0009248);
    puVar5[4] = lVar6;
    if (lVar6 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar10 = &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,0);
      }
      uVar9 = 0xc000009a;
      ExFreePoolWithTag(puVar5,0x30657247);
      puVar8 = auStack_38;
    }
    else {
      puVar1 = puVar5 + 2;
      puVar5[7] = param_2;
      puVar5[3] = puVar1;
      *puVar1 = puVar1;
      puVar5[1] = puVar5;
      *puVar5 = puVar5;
      LOCK();
      *(int *)(puVar5 + 5) = *(int *)(puVar5 + 5) + 1;
      UNLOCK();
      *(undefined4 *)(puVar5 + 0xb) = 1;
      DAT_1c0007228 = KeAcquireSpinLockRaiseToDpc(&DAT_1c0007220);
      puVar8 = auStack_38;
      puVar7 = &DAT_1c0007230;
      if ((undefined *)*DAT_1c0007238 != &DAT_1c0007230) {
        puVar7 = (undefined *)0x3;
        pcVar4 = (code *)swi(0x29);
        DAT_1c0007238 = (undefined8 *)(*pcVar4)();
        puVar8 = auStack_30;
      }
      *puVar5 = puVar7;
      puVar5[1] = DAT_1c0007238;
      *DAT_1c0007238 = puVar5;
      *(undefined8 *)(puVar8 + -8) = 0x1c0001f98;
      DAT_1c0007238 = puVar5;
      KeReleaseSpinLock(&DAT_1c0007220,DAT_1c0007228);
      *param_3 = puVar5;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 2) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined4 *)(puVar8 + 0x28) = uVar9;
    *(undefined8 **)(puVar8 + 0x20) = puVar5;
    *(undefined8 *)(puVar8 + -8) = 0x1c0001fcf;
    WPP_SF_qqD(uVar3,(ulonglong)uVar2,puVar10,param_2,puVar8[0x20],puVar8[0x28]);
  }
  return uVar9;
}



===== GreCmDeleteVc @ 1c0002000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GreCmDeleteVc(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(param_1[4],&local_res8,0);
  *(uint *)(param_1 + 0xb) = *(uint *)(param_1 + 0xb) & 0xfffffffe;
  param_1[7] = 0;
  NdisReleaseRWLock(param_1[4],&local_res8);
  DAT_1c0007228 = KeAcquireSpinLockRaiseToDpc(&DAT_1c0007220);
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
  KeReleaseSpinLock(&DAT_1c0007220,CONCAT71((int7)((ulonglong)lVar1 >> 8),DAT_1c0007228));
  plVar2 = param_1 + 5;
  LOCK();
  lVar1 = *plVar2;
  *(int *)plVar2 = (int)*plVar2 + -1;
  UNLOCK();
  if ((int)lVar1 == 1) {
    (*(code *)param_1[6])();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  return 0;
}



===== GreCmDeregisterSap @ 1c0002140 =====

undefined8 GreCmDeregisterSap(void)

{
  return 0xc00000bb;
}



===== GreCmMakeCall @ 1c0002150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GreCmMakeCall(longlong param_1,uint *param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short sVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  wchar_t *pwVar11;
  undefined4 *puVar12;
  short **ppsVar13;
  undefined1 auStackY_d8 [32];
  undefined2 local_98;
  undefined1 local_96;
  undefined4 local_94;
  short *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  char local_78 [48];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_90 = (short *)0x0;
  local_94 = 0;
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_98 = 0;
  local_88 = (short *)0x0;
  uStack_80 = 0;
  local_96 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  *param_4 = 0;
  if ((*param_2 & 0x19) != 0) {
    uVar10 = 0xc00000bb;
    goto LAB_1c00023d4;
  }
  lVar2 = *(longlong *)(param_2 + 4);
  if (((*(uint *)(lVar2 + 0x14) < 0x30) || (*(ushort *)(lVar2 + 0x38) < 0xb4)) ||
     ((lVar9 = *(longlong *)(lVar2 + 0x40) + 0x38 + lVar2,
      (*(uint *)(lVar9 + 0x10) & 0xfffffeef) != 0 || (*(uint *)(lVar9 + 0x68) < 0x24)))) {
    uVar10 = 0xc0010015;
    goto LAB_1c00023d4;
  }
  puVar12 = (undefined4 *)((ulonglong)*(uint *)(lVar9 + 0x6c) + lVar9);
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_98,0);
  ppsVar13 = (short **)&local_88;
  *(undefined4 *)(param_1 + 0x5c) = puVar12[1];
  *puVar12 = 0x53415252;
  *(byte *)(param_1 + 0x60) = *(byte *)(puVar12 + 2) & 1;
  uVar1 = puVar12[3];
  *(uint *)(param_1 + 100) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  pwVar11 = (wchar_t *)(lVar2 + 0x28 + *(longlong *)(lVar2 + 0x30));
  iVar7 = RtlIpv6StringToAddressW(pwVar11,&local_90);
  if ((iVar7 < 0) || (*local_90 != 0)) {
    ppsVar13 = &local_90;
    iVar7 = RtlIpv4StringToAddressW(pwVar11,1,ppsVar13,&local_94);
    if ((-1 < iVar7) && (*local_90 == 0)) {
      *(undefined4 *)(param_1 + 0x80) = local_94;
      sVar6 = 2;
      goto LAB_1c00022f2;
    }
  }
  else {
    sVar6 = 0x17;
    *(undefined4 *)(param_1 + 0x80) = (undefined4)local_88;
    *(undefined4 *)(param_1 + 0x84) = local_88._4_4_;
    *(undefined4 *)(param_1 + 0x88) = (undefined4)uStack_80;
    *(undefined4 *)(param_1 + 0x8c) = uStack_80._4_4_;
LAB_1c00022f2:
    *(short *)(param_1 + 0x7c) = sVar6;
    if (*(short *)(puVar12 + 4) == sVar6) {
      uVar3 = puVar12[5];
      uVar4 = puVar12[6];
      uVar5 = puVar12[7];
      *(undefined4 *)(param_1 + 0x68) = puVar12[4];
      *(undefined4 *)(param_1 + 0x6c) = uVar3;
      *(undefined4 *)(param_1 + 0x70) = uVar4;
      *(undefined4 *)(param_1 + 0x74) = uVar5;
      *(undefined4 *)(param_1 + 0x78) = puVar12[8];
      if (*(short *)(param_1 + 0x68) == 2) {
        RtlIpv4AddressToStringA();
      }
      else {
        RtlIpv6AddressToStringA(param_1 + 0x6c,local_78);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_sSdLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(byte *)(param_1 + 0x60)
                     ,ppsVar13,local_78,pwVar11,*(byte *)(param_1 + 0x60),(char)puVar12[3],
                     (char)*(undefined4 *)(param_1 + 0x5c));
      }
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 4;
      *(uint **)(param_1 + 0x50) = param_2;
      LOCK();
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
      UNLOCK();
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_98);
      uVar8 = GreScheduleWorkItem(GreCmMakeCallWorkItem,param_1);
      uVar10 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xfffffffb;
      }
      else {
        uVar10 = 0x103;
      }
      goto LAB_1c00023d4;
    }
  }
  uVar10 = 0xc0010015;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_98);
LAB_1c00023d4:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1,(char)uVar10);
  }
  return uVar10;
}



===== GreCmOidRequest @ 1c0002440 =====

undefined8
GreCmOidRequest(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (*(int *)(param_4 + 4) == 0) {
    uVar1 = GreCmQueryInformation(param_1,param_4);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== GreCmOpenAf @ 1c0002470 =====

undefined8 GreCmOpenAf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_3);
  }
  *param_4 = 0;
  DAT_1c0009328 = param_3;
  return 0;
}



===== GreCmQueryInformation @ 1c00024d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GreCmQueryInformation(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 *_Src;
  undefined1 auStack_2f8 [32];
  undefined8 local_2d8;
  undefined4 local_2d0;
  undefined4 local_2c8 [2];
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_24c;
  undefined4 local_1b4;
  wchar_t local_19c [4];
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_b8;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2f8;
  local_2d8 = 0;
  local_2d0 = 0;
  _Src = (undefined8 *)0x0;
  memset(local_2c8,0,0x1b0);
  uVar2 = 0xf0;
  memset(&local_118,0,0xf0);
  iVar1 = *(int *)(param_2 + 0x20);
  if (iVar1 == -0x1ffefff) {
    _Src = &local_2d8;
    local_2d8 = 0x100030000;
    uVar2 = 0xc;
  }
  else if (iVar1 == -0x1ffeffe) {
    uVar2 = 0x1b0;
    if (0x1af < *(uint *)(param_2 + 0x30)) {
      _Src = (undefined8 *)local_2c8;
      local_2c8[0] = **(undefined4 **)(param_2 + 0x28);
      local_2c0 = (*(undefined4 **)(param_2 + 0x28))[2];
      local_2bc = 0x1a8;
      local_2b8 = 0x1a8;
      builtin_wcsncpy(local_19c,L"GRE",4);
      local_2a0 = 8;
      local_28c = 8;
      local_29c = 0x124;
      local_298 = 3;
      local_290 = 1;
      local_288 = 100000000;
      local_284 = 0x102;
      local_24c = 1;
      local_1b4 = 0x10;
      local_2a4 = local_2c8[0];
    }
  }
  else {
    if (iVar1 != -0x1ffeffd) {
      return 0xc00000bb;
    }
    if (*(uint *)(param_2 + 0x30) < 0xf0) goto LAB_1c0002679;
    _Src = (undefined8 *)&local_118;
    local_118 = **(undefined4 **)(param_2 + 0x28);
    local_114 = (*(undefined4 **)(param_2 + 0x28))[1];
    local_10c = 0xe4;
    local_108 = 0xe4;
    local_104 = 0xe4;
    local_b8 = DAT_1c0009250;
    local_100 = local_118;
  }
  if (uVar2 <= *(uint *)(param_2 + 0x30)) {
    memcpy(*(void **)(param_2 + 0x28),_Src,(ulonglong)uVar2);
    *(uint *)(param_2 + 0x34) = uVar2;
    return 0;
  }
LAB_1c0002679:
  *(uint *)(param_2 + 0x38) = uVar2;
  return 0xc0010016;
}



===== GreTunnelDereferenceCleanup @ 1c00026c0 =====

void GreTunnelDereferenceCleanup(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1 + -0x28);
  }
  if ((*(uint *)(param_1 + 0x30) >> 9 & 1) != 0) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffdff;
    GreScheduleWorkItem(GreDeregisterWfpCalloutWorkItem,0);
  }
  NdisFreeRWLock(*(undefined8 *)(param_1 + -8));
  ExFreePoolWithTag(param_1 + -0x28,0x30657247);
  return;
}



===== GreVcDereferenceCleanup @ 1c0002760 =====

void GreVcDereferenceCleanup(longlong param_1)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1 + -0x40);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + -0x20),&local_res8,0);
  if ((*(uint *)(param_1 + 0x18) & 0x40) == 0) {
    NdisReleaseRWLock(*(undefined8 *)(param_1 + -0x20),&local_res8);
  }
  else {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
    NdisReleaseRWLock();
    GreCleanupTunnel(param_1 + -0x40);
  }
  return;
}



===== WPP_SF_qD @ 1c000280c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qqD @ 1c0002860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,0xc,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_sSdLL @ 1c00028c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sSdLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                 wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_4[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,0x12,param_4,lVar3,
             param_5,lVar1,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_DDDDDDDD @ 1c00029c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDDDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,0x11,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== WPP_SF_L @ 1c0002a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,0xe,local_res20,4,0);
  return;
}



===== FindGatewayForInterface @ 1c0002abc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

NTSTATUS FindGatewayForInterface(SOCKADDR_INET *param_1,NET_IFINDEX param_2,undefined4 *param_3)

{
  ADDRESS_FAMILY Family;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  NTSTATUS NVar5;
  SOCKADDR_INET *pSVar6;
  uint uVar7;
  undefined1 auStackY_118 [32];
  PMIB_IPFORWARD_TABLE2 local_d8;
  SOCKADDR_INET local_d0;
  _MIB_IPFORWARD_ROW2 local_a8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  Family = (param_1->Ipv4).sin_family;
  memset(&local_a8,0,0x68);
  local_d0._16_8_ = 0;
  local_d0.Ipv6.field4_0x18 = (_union_6653)0;
  local_d8 = (PMIB_IPFORWARD_TABLE2)0x0;
  local_d0._0_8_ = 0;
  local_d0.Ipv4.sin_zero[0] = '\0';
  local_d0.Ipv4.sin_zero[1] = '\0';
  local_d0.Ipv4.sin_zero[2] = '\0';
  local_d0.Ipv4.sin_zero[3] = '\0';
  local_d0.Ipv4.sin_zero[4] = '\0';
  local_d0.Ipv4.sin_zero[5] = '\0';
  local_d0.Ipv4.sin_zero[6] = '\0';
  local_d0.Ipv4.sin_zero[7] = '\0';
  NVar5 = GetBestRoute2((NET_LUID *)0x0,param_2,(SOCKADDR_INET *)0x0,param_1,0,&local_a8,&local_d0);
  if (NVar5 < 0) {
    NVar5 = GetIpForwardTable2(Family,&local_d8);
    if ((-1 < NVar5) && (uVar7 = 0, local_d8->NumEntries != 0)) {
      do {
        if (local_d8->Table[uVar7].InterfaceIndex == param_2) {
          if (local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv4.sin_family == 0x17) {
            if (((((*(short *)local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv4.sin_zero != 0) ||
                  (*(short *)(local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv4.sin_zero + 2) !=
                   0)) || (*(short *)(local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv4.sin_zero
                                     + 4) != 0)) ||
                ((*(short *)(local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv4.sin_zero + 6) != 0
                 || (local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv6.sin6_addr.u.Word[4] != 0))
                )) || ((local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv6.sin6_addr.u.Word[5] !=
                        0 || ((local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv6.sin6_addr.u.Word
                               [6] != 0 ||
                              (bVar4 = true,
                              local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv6.sin6_addr.u.Word
                              [7] != 0)))))) {
              bVar4 = false;
            }
            pSVar6 = &local_d8->Table[uVar7].NextHop;
            if (bVar4) goto LAB_1c0002c2e;
          }
          else {
            pSVar6 = &local_d8->Table[uVar7].NextHop;
            if (local_d8->Table[uVar7].DestinationPrefix.Prefix.Ipv6.sin6_flowinfo == 0) {
LAB_1c0002c2e:
              uVar1 = *(undefined4 *)(&pSVar6->si_family + 2);
              uVar2 = *(undefined4 *)(&pSVar6->si_family + 4);
              uVar3 = *(undefined4 *)(&pSVar6->si_family + 6);
              *param_3 = *(undefined4 *)&pSVar6->Ipv4;
              param_3[1] = uVar1;
              param_3[2] = uVar2;
              param_3[3] = uVar3;
              *(undefined8 *)(param_3 + 4) = *(undefined8 *)(&pSVar6->si_family + 8);
              param_3[6] = *(undefined4 *)(&pSVar6->si_family + 0xc);
              break;
            }
          }
          if ((pSVar6->Ipv4).sin_family == 0x17) {
            if (((((&pSVar6->si_family)[4] != 0) || ((&pSVar6->si_family)[5] != 0)) ||
                ((&pSVar6->si_family)[6] != 0)) ||
               ((((&pSVar6->si_family)[7] != 0 || ((&pSVar6->si_family)[8] != 0)) ||
                (((&pSVar6->si_family)[9] != 0 ||
                 (((&pSVar6->si_family)[10] != 0 || ((&pSVar6->si_family)[0xb] != 0))))))))
            goto LAB_1c0002ca0;
          }
          else if (*(int *)(&pSVar6->si_family + 2) != 0) {
LAB_1c0002ca0:
            uVar1 = *(undefined4 *)(&pSVar6->si_family + 2);
            uVar2 = *(undefined4 *)(&pSVar6->si_family + 4);
            uVar3 = *(undefined4 *)(&pSVar6->si_family + 6);
            *param_3 = *(undefined4 *)&pSVar6->Ipv4;
            param_3[1] = uVar1;
            param_3[2] = uVar2;
            param_3[3] = uVar3;
            *(undefined8 *)(param_3 + 4) = *(undefined8 *)(&pSVar6->si_family + 8);
            param_3[6] = *(undefined4 *)(&pSVar6->si_family + 0xc);
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < local_d8->NumEntries);
    }
  }
  else {
    *param_3 = local_a8.NextHop._0_4_;
    (((IN_ADDR *)(param_3 + 1))->S_un).S_un_b = (_struct_1249)local_a8.NextHop.Ipv4.sin_addr.S_un;
    param_3[2] = local_a8.NextHop.Ipv4.sin_zero._0_4_;
    param_3[3] = local_a8.NextHop.Ipv4.sin_zero._4_4_;
    *(undefined8 *)(param_3 + 4) = local_a8.NextHop._16_8_;
    ((_union_6653 *)(param_3 + 6))->sin6_scope_id = (ULONG)local_a8.NextHop.Ipv6.field4_0x18;
  }
  if (local_d8 != (PMIB_IPFORWARD_TABLE2)0x0) {
    FreeMibTable(local_d8);
  }
  return NVar5;
}



===== NsiCliAddOrDeleteHostRouteToInterface @ 1c0002cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Enum "enum_6678": Some values do not have unique names */

void NsiCliAddOrDeleteHostRouteToInterface(SOCKADDR_INET *param_1,NET_IFINDEX param_2,char param_3)

{
  CHAR (*paCVar1) [8];
  undefined2 uVar2;
  longlong lVar3;
  undefined1 auStack_b8 [32];
  _MIB_IPFORWARD_ROW2 local_98;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  memset(&local_98,0,0x68);
  uVar2 = (param_1->Ipv4).sin_family;
  InitializeIpForwardEntry(&local_98);
  local_98.Metric = 1;
  local_98.ValidLifetime = 0xffffffff;
  local_98.PreferredLifetime = 0xffffffff;
  local_98.Protocol = MIB_IPPROTO_NETMGMT;
  local_98.Immortal = '\x01';
  local_98.InterfaceIndex = param_2;
  FindGatewayForInterface(param_1,param_2,(undefined4 *)&local_98.NextHop);
  lVar3 = 8;
  if ((param_1->Ipv4).sin_family != 0x17) {
    lVar3 = 4;
  }
  if (uVar2 == 0x17) {
    paCVar1 = (CHAR (*) [8])((longlong)&(param_1->Ipv6).sin6_addr.u + lVar3 + -8);
    local_98.DestinationPrefix.Prefix.Ipv4.sin_zero = *paCVar1;
    local_98.DestinationPrefix.Prefix._16_8_ = paCVar1[1];
  }
  else {
    local_98.DestinationPrefix.Prefix.Ipv4.sin_addr.S_un =
         *(IN_ADDR *)
          &(((IN_ADDR *)((longlong)&(param_1->Ipv6).sin6_addr.u + lVar3 + -8))->S_un).S_un_b;
    local_98.DestinationPrefix.PrefixLength = ' ';
    if (uVar2 == 2) goto LAB_1c0002d86;
  }
  local_98.DestinationPrefix.PrefixLength = 0x80;
LAB_1c0002d86:
  local_98.DestinationPrefix.Prefix.Ipv4.sin_family = uVar2;
  if (param_3 == '\0') {
    DeleteIpForwardEntry2(&local_98);
  }
  else {
    InternalCreateOrRefIpForwardEntry2(1,&local_98);
  }
  return;
}



===== NsiCliAttachProvider @ 1c0002de0 =====

int NsiCliAttachProvider(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = ExAllocatePool2(0x40,0x18,NsiCliTag);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar2 + 0x10) = param_1;
    iVar1 = NmrClientAttachProvider(param_1,lVar2,&NsiCliDispatch,lVar2,lVar2 + 8);
    if (iVar1 < 0) {
      ExFreePoolWithTag(lVar2,0);
    }
  }
  return iVar1;
}



===== NsiCliCleanupProviderContext @ 1c0002e70 =====

void NsiCliCleanupProviderContext(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== NsiCliDeregisterClient @ 1c0002e90 =====

void NsiCliDeregisterClient(void)

{
  int iVar1;
  bool bVar2;
  
  if (NsiCliHandle != 0) {
    NmrDeregisterClient();
    NmrWaitForClientDeregisterComplete(NsiCliHandle);
    LOCK();
    iVar1 = NsiCliDriverRefCount + -1;
    UNLOCK();
    bVar2 = NsiCliDriverRefCount == 1;
    NsiCliDriverRefCount = iVar1;
    if (bVar2) {
      KeSetEvent(&NsiCliDriverUnloadEvent,0,0);
    }
    NsiCliHandle = 0;
    KeWaitForSingleObject(&NsiCliDriverUnloadEvent,0,0,0,0);
  }
  return;
}



===== GetWskClientContext @ 1c0002f1c =====

undefined8 GetWskClientContext(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (g_bWskAttachComplete != '\0') {
    uVar1 = g_pWskState;
  }
  return uVar1;
}



===== WskClientEvent @ 1c0002f40 =====

undefined8 WskClientEvent(void)

{
  return 0xc0000002;
}



===== WskNotifyAttachProvider @ 1c0002f50 =====

int WskNotifyAttachProvider(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  
  if ((*(longlong *)(param_3 + 0x20) == 0) ||
     (0x100 < *(ushort *)(*(longlong *)(param_3 + 0x20) + 2))) {
    iVar1 = -0x3ffffd47;
  }
  else {
    lVar2 = ExAllocatePool2(0x40,0x18,0x77534152);
    g_pWskState = lVar2;
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(lVar2 + 0x10) = param_1;
      iVar1 = NmrClientAttachProvider(param_1,lVar2,&DAT_1c0005048,lVar2,lVar2 + 8);
      if (-1 < iVar1) {
        g_bWskAttachComplete = 1;
        return iVar1;
      }
    }
  }
  if (g_pWskState != 0) {
    ExFreePoolWithTag(g_pWskState,0);
    g_pWskState = 0;
  }
  return iVar1;
}



===== WskNotifyDetachProvider @ 1c0003010 =====

undefined8 WskNotifyDetachProvider(void)

{
  g_pWskState = 0;
  g_bWskAttachComplete = 0;
  return 0;
}



===== WskStopClientModule @ 1c000302c =====

void WskStopClientModule(void)

{
  if (WskClientHandle != 0) {
    NmrDeregisterClient();
    NmrWaitForClientDeregisterComplete(WskClientHandle);
    WskClientHandle = 0;
  }
  return;
}



===== WskCreateAndIntializeSockContext @ 1c0003070 =====

void WskCreateAndIntializeSockContext(void)

{
  undefined4 *puVar1;
  
  if (g_fWSKPagesLocked == '\0') {
    MmLockPagableDataSection(WskCreateSocket);
    g_fWSKPagesLocked = '\x01';
  }
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x240,0x36657247);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x434b5357;
    *(code **)(puVar1 + 0xc) = WskLibDummyLogger;
    *(code **)(puVar1 + 0x82) = FreeSockHandle;
    puVar1[0x80] = 1;
  }
  return;
}



===== __GSHandlerCheck @ 1c00030f8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000311c =====

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



===== __cpu_features_init @ 1c0003190 =====

/* WARNING: Removing unreachable block (ram,0x0001c00031fa) */
/* WARNING: Removing unreachable block (ram,0x0001c00031a9) */
/* WARNING: Removing unreachable block (ram,0x0001c000319a) */

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



===== __security_check_cookie @ 1c0003260 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00032a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00032d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00032d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003300 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0003380 =====

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



===== memset @ 1c0003680 =====

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



===== __memset_repmovs @ 1c00037c0 =====

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



===== __memset_query @ 1c0003840 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00038c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003a00 =====

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



===== __memset_spec_plain @ 1c0003a80 =====

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



===== WppInitKm @ 1c000d008 =====

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



===== WppLoadTracingSupport @ 1c000d098 =====

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



===== WppTraceCallback @ 1c000d1e0 =====

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



===== GreUninitializeWfp @ 1c000d468 =====

void GreUninitializeWfp(void)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids);
  }
  NdisFreeNetBufferListPool(DAT_1c00092d0);
  return;
}



===== GreMiniportHaltEx @ 1c000d4c0 =====

void GreMiniportHaltEx(undefined8 *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids);
  }
  *param_1 = 0;
  *(undefined4 *)(param_1 + 5) = 0;
  return;
}



===== GreMiniportInitializeEx @ 1c000d520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GreMiniportInitializeEx(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStack_1a8 [32];
  undefined4 local_188;
  undefined4 local_184;
  undefined8 *local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168 [2];
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_118;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined2 local_b4;
  undefined4 local_ac;
  undefined4 *local_a0;
  undefined4 local_98;
  undefined8 *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_184 = 0;
  local_16c = 0;
  local_48 = 0;
  local_40 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  memset(local_168,0,0xe0);
  local_88 = 0x801;
  local_84 = 6;
  local_80 = 0x1e;
  local_38 = 0x10103;
  local_34 = 0x4010105;
  local_30 = 0x10111;
  local_2c = 0x1010c;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids);
  }
  local_170 = 0;
  DAT_1c0009250 = 30000;
  local_178 = 0x20;
  local_188 = 0x20029e;
  local_180 = &DAT_1c0009248;
  local_174 = 0x10;
  iVar1 = NdisMSetMiniportAttributes(param_1,&local_188);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000d7be;
    uVar2 = 0xf;
  }
  else {
    uStack_50 = 0;
    local_48 = local_48 & 0xffffffff00000000;
    local_15c = 0;
    local_130 = 0;
    local_12c = 0;
    local_bc = 0;
    local_ac = 0;
    local_150 = 0xffffffffffffffff;
    local_148 = 0xffffffffffffffff;
    local_140 = 0xffffffffffffffff;
    local_138 = 0xffffffffffffffff;
    local_b4 = 0x83;
    local_a0 = &local_38;
    local_90 = &local_78;
    local_78 = CONCAT44(local_78._4_4_,0x3c0280);
    local_168[0] = 0xe0029f;
    local_160 = 0xc;
    local_158 = 0x5ac;
    local_128 = 0x5c4;
    local_118 = 5;
    local_c0 = 3;
    local_b8 = 1;
    local_98 = 0x10;
    iVar1 = NdisMSetMiniportAttributes(param_1,local_168);
    if (iVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_1c000d7be;
      uVar2 = 0x10;
    }
    else {
      iVar1 = NdisMCmRegisterAddressFamilyEx(param_1,&local_88);
      if (-1 < iVar1) {
        _DAT_1c000927c = 0x10000000;
        _DAT_1c0009274 = 0x5dc;
        _DAT_1c0009278 = 0x20;
        DAT_1c0009270 = 1;
        DAT_1c0009248 = param_1;
        goto LAB_1c000d7be;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_1c000d7be;
      uVar2 = 0x11;
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,iVar1);
LAB_1c000d7be:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,iVar1);
  }
  return iVar1;
}



===== GreMiniportSetOptions @ 1c000d820 =====

int GreMiniportSetOptions(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  undefined4 local_98 [2];
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  code *local_10;
  
  local_d4 = 0;
  memset(local_98,0,0x90);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids);
  }
  local_d8 = 0x380191;
  local_d0 = GreCoDeactivateVc;
  local_c8 = GreCoDeactivateVc;
  local_c0 = GreCoDeactivateVc;
  local_b8 = GreCoDeactivateVc;
  local_b0 = GreCoSendNetBufferLists;
  local_a8 = GreCoOidRequest;
  iVar1 = NdisSetOptionalHandlers(param_1,&local_d8);
  if (iVar1 == 0) {
    local_98[0] = 0x9001a5;
    local_90 = GreCmCreateVc;
    local_88 = GreCmDeleteVc;
    local_80 = GreCmOpenAf;
    local_78 = GreCmCloseAf;
    local_70 = GreCmDeregisterSap;
    local_68 = GreCmDeregisterSap;
    local_60 = GreCmMakeCall;
    local_58 = GreCmCloseCall;
    local_50 = GreCmIncomingCallComplete;
    local_38 = GreCmActivateVcComplete;
    local_30 = GreCmDeactivateVcComplete;
    local_28 = GreCoDeactivateVc;
    local_20 = GreCmOidRequest;
    local_18 = _guard_check_icall;
    local_10 = _guard_check_icall;
    iVar1 = NdisSetOptionalHandlers(param_1,local_98);
    if (iVar1 == 0) goto LAB_1c000da17;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000da17;
    uVar2 = 0xc;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000da17;
    uVar2 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,iVar1);
LAB_1c000da17:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,iVar1);
  }
  return iVar1;
}



===== GreMiniportUnload @ 1c000da70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GreMiniportUnload(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined *puVar4;
  longlong lVar5;
  undefined8 local_res10;
  
  local_res10 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,param_1);
  }
  uVar3 = 0;
  if (DAT_1c0009338 * 3 != 0) {
    do {
      lVar5 = uVar3 * 0x38;
      iVar1 = ObReferenceObjectByHandle(*(undefined8 *)(lVar5 + DAT_1c0009340),0,0,0,&local_res10,0)
      ;
      if (iVar1 == 0) {
        NdisSetEvent(DAT_1c0009340 + 0x18 + lVar5);
        KeWaitForSingleObject(local_res10);
        ObfDereferenceObject(local_res10);
      }
      ZwClose(*(undefined8 *)(lVar5 + DAT_1c0009340));
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < (uint)(DAT_1c0009338 * 3));
  }
  NdisFreeMemoryWithTagPriority(DAT_1c0007208,DAT_1c0009340,0x37657247);
  GreUninitializeWfp();
  NdisFreeRWLock(DAT_1c0009258);
  NdisMDeregisterMiniportDriver(DAT_1c0007208);
  NsiCliDeregisterClient();
  NdisFreeNetBufferListPool(DAT_1c0007210);
  NdisFreeNetBufferPool(DAT_1c0007218);
  NdisFreeRWLock(DAT_1c0007240);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar4 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar4 != (undefined *)0x0; puVar4 = *(undefined **)(puVar4 + 0x10)) {
        if (*(longlong *)(puVar4 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar4 + 0x38) = 0;
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



===== WskStartClientModule @ 1c000dc7c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WskStartClientModule(void)

{
  int iVar1;
  
  _DAT_1c00070f0 = (undefined4)GRE_WSK_CLI_GUID;
  uRam00000001c00070f4 = GRE_WSK_CLI_GUID._4_4_;
  uRam00000001c00070f8 = uRam00000001c00070a8;
  uRam00000001c00070fc = uRam00000001c00070ac;
  iVar1 = NmrRegisterClient(&WskClientNotify,0,&WskClientHandle);
  if (-1 < iVar1) {
    KeInitializeSpinLock(&RouteListLock);
    _DAT_1c00071b8 = &RouteList;
    _RouteList = &RouteList;
  }
  return iVar1;
}



===== GreCreateSockets @ 1c000e008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GreCreateSockets(void)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_98 [32];
  short local_68 [8];
  undefined4 *local_58;
  undefined4 local_50;
  undefined8 local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined8 local_2c;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 2;
  local_4c = 0;
  local_68[1] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_44 = 0;
  local_40 = 0x17;
  local_3c = 0;
  uStack_34 = 0;
  local_2c = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids);
  }
  iVar1 = WskStartClientModule();
  if (-1 < iVar1) {
    local_68[2] = 0x2f;
    local_68[3] = 0;
    local_68[0] = 3;
    local_58 = &local_50;
    local_68[4] = 4;
    local_68[5] = 0;
    lVar2 = WskCreateAndIntializeSockContext();
    if (lVar2 == 0) {
LAB_1c000e0cd:
      iVar1 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(lVar2 + 0x40) = 0;
      *(undefined8 *)(lVar2 + 0x18) = 0;
      *(code **)(lVar2 + 0x10) = GreSocketReceive;
      *(undefined8 *)(lVar2 + 8) = 0;
      *(undefined **)(lVar2 + 0x48) = &DAT_1c0009318;
      *(code **)(lVar2 + 0x30) = GreCmIncomingCallComplete;
      uVar3 = WskCreateSocket(local_68,0,4,lVar2,0);
      iVar1 = (int)uVar3;
      if (-1 < iVar1) {
        local_58 = &local_40;
        DAT_1c0009308 = lVar2;
        lVar2 = WskCreateAndIntializeSockContext();
        if (lVar2 == 0) goto LAB_1c000e0cd;
        *(code **)(lVar2 + 0x10) = GreSocketReceive;
        *(undefined8 *)(lVar2 + 0x40) = 0;
        *(undefined8 *)(lVar2 + 0x18) = 0;
        *(undefined8 *)(lVar2 + 8) = 0;
        *(undefined **)(lVar2 + 0x48) = &DAT_1c0009318;
        *(code **)(lVar2 + 0x30) = GreCmIncomingCallComplete;
        uVar3 = WskCreateSocket(local_68,0,4,lVar2,0);
        iVar1 = (int)uVar3;
        if (-1 < iVar1) {
          DAT_1c0009310 = lVar2;
          goto LAB_1c000e0e3;
        }
      }
    }
  }
  if (DAT_1c0009308 != 0) {
    WskCloseSocketContextAndFreeSocket(DAT_1c0009308);
  }
LAB_1c000e0e3:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids,iVar1);
  }
  return iVar1;
}



===== GreDeregisterWfpCallout @ 1c000e204 =====

void GreDeregisterWfpCallout(void)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids);
  }
  iVar2 = KeWaitForSingleObject(&DAT_1c0009288,0,0,0,0);
  if (iVar2 == 0) {
    DAT_1c00092c0 = DAT_1c00092c0 + -1;
    if (DAT_1c00092c0 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids);
      }
      WskCloseSocketContextAndFreeSocket(DAT_1c0009308);
      DAT_1c0009308 = 0;
      WskCloseSocketContextAndFreeSocket(DAT_1c0009310);
      DAT_1c0009310 = 0;
      WskStopClientModule();
      uVar1 = DAT_1c00092c8;
      FwpmFilterDeleteById0(DAT_1c00092c8,DAT_1c00092e8);
      FwpiCalloutUnregisterAndDeleteByKey0(uVar1,&GRE_IPv4_CALLOUT_GUID);
      FwpmFilterDeleteById0(uVar1,DAT_1c00092f0);
      FwpiCalloutUnregisterAndDeleteByKey0(uVar1,&GRE_IPv6_CALLOUT_GUID);
      FwpmEngineClose0(uVar1);
      DAT_1c00092c8 = 0;
      FwpsInjectionHandleDestroy0(DAT_1c00092f8);
      DAT_1c00092f8 = 0;
      FwpsInjectionHandleDestroy0(DAT_1c0009300);
      DAT_1c0009300 = 0;
    }
    KeReleaseMutex(&DAT_1c0009288,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids,0);
    }
  }
  return;
}



===== GreDeregisterWfpCalloutWorkItem @ 1c000e3e0 =====

void GreDeregisterWfpCalloutWorkItem(undefined8 param_1,undefined8 param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids);
  }
  NdisFreeIoWorkItem(param_2);
  GreDeregisterWfpCallout();
  return;
}



===== GreRegisterWfpCallout @ 1c000e440 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GreRegisterWfpCallout(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined2 uVar10;
  int unaff_retaddr;
  undefined1 auStack_228 [32];
  longlong *local_208;
  longlong local_1f8;
  longlong local_1f0;
  longlong local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  code *pcStack_1b8;
  code *local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_198;
  undefined8 uStack_190;
  wchar_t *local_188;
  wchar_t *local_180;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 local_138 [16];
  wchar_t *local_128;
  wchar_t *local_120;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_d8;
  undefined4 local_c8;
  undefined8 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined8 *local_a0;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_228;
  memset(local_138,0,200);
  local_1d0 = 0;
  uStack_1c8 = 0;
  local_1c0 = 0;
  pcStack_1b8 = (code *)0x0;
  local_1b0 = (code *)0x0;
  uStack_1a8 = 0;
  memset(&local_198,0,0x58);
  local_48 = 0;
  local_1f8 = 0;
  bVar7 = false;
  local_1e8 = 0;
  bVar6 = false;
  local_1f0 = 0;
  bVar5 = false;
  bVar4 = false;
  local_1d8 = 0;
  bVar3 = false;
  local_1e0 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids);
  }
  local_208 = (longlong *)0x0;
  iVar9 = KeWaitForSingleObject(&DAT_1c0009288,0,0,0);
  if (iVar9 != 0) {
    return unaff_retaddr;
  }
  iVar9 = 0;
  if (DAT_1c00092c0 != 0) {
LAB_1c000eb4b:
    DAT_1c00092c0 = DAT_1c00092c0 + 1;
    goto LAB_1c000eb52;
  }
  iVar9 = GreCreateSockets();
  if (-1 < iVar9) {
    local_208 = &local_1f8;
    iVar9 = FwpmEngineOpen0(0,10,0);
    if (iVar9 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar10 = 0xe;
        bVar4 = bVar5;
        bVar7 = false;
LAB_1c000e5c4:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                 &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids,iVar9);
      }
    }
    else {
      local_1d0 = CONCAT44(uRam00000001c00070b4,_GRE_IPv4_CALLOUT_GUID);
      uStack_1c8 = CONCAT44(uRam00000001c00070bc,uRam00000001c00070b8);
      pcStack_1b8 = GreWfpIpv4CalloutClassify;
      local_1b0 = GreWfpCalloutNotify;
      local_1c0 = 0;
      uStack_1a8 = 0;
      local_158 = 0x5926dfc8;
      uStack_154 = 0x4426e3cf;
      uStack_150 = 0x39dc83a2;
      uStack_14c = 0x9d0f5d3f;
      local_188 = L"RASGRE IPv4 callout";
      local_180 = L"RASGRE IPv4 callout";
      local_208 = (longlong *)0x0;
      local_198 = local_1d0;
      uStack_190 = uStack_1c8;
      iVar9 = FwpiCalloutRegisterAndAddWithoutDevice0(local_1f8,&local_1d0,&local_198,0);
      if (iVar9 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar10 = 0xf;
          bVar4 = bVar5;
          bVar7 = false;
          goto LAB_1c000e5c4;
        }
      }
      else {
        uVar1 = CONCAT44(uRam00000001c00070c4,_GRE_IPv6_CALLOUT_GUID);
        uVar2 = CONCAT44(uRam00000001c00070cc,uRam00000001c00070c8);
        local_1c0 = 0;
        uStack_1a8 = 0;
        pcStack_1b8 = GreWfpIpv6CalloutClassify;
        bVar8 = true;
        bVar7 = true;
        local_1b0 = GreWfpCalloutNotify;
        local_1d0 = uVar1;
        uStack_1c8 = uVar2;
        memset(&local_198,0,0x58);
        local_188 = L"RASGRE IPv6 callout";
        local_180 = L"RASGRE IPv6 callout";
        local_208 = (longlong *)0x0;
        local_158 = 0x634a869f;
        uStack_154 = 0x4b90fc23;
        uStack_150 = 0x62bfc1b0;
        uStack_14c = 0x6fae360a;
        local_198 = uVar1;
        uStack_190 = uVar2;
        iVar9 = FwpiCalloutRegisterAndAddWithoutDevice0(local_1f8,&local_1d0,&local_198,0);
        if (iVar9 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar10 = 0x10;
            bVar4 = bVar5;
            bVar7 = bVar8;
            goto LAB_1c000e5c4;
          }
        }
        else {
          bVar6 = true;
          iVar9 = FwpmTransactionBegin0(local_1f8,0);
          if (iVar9 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar10 = 0x11;
              bVar4 = bVar5;
              bVar7 = bVar8;
              goto LAB_1c000e5c4;
            }
          }
          else {
            local_128 = L"RASGRE IPv4 filter";
            local_68 = 0x4f9a623e3971ef2b;
            uStack_60 = 0xa7b906b8796eb18c;
            local_120 = L"RASGRE IPv4 filter";
            local_c0 = &local_68;
            local_58 = local_58 & 0xffffffff00000000;
            local_f8 = 0x4426e3cf5926dfc8;
            uStack_f0 = 0x9d0f5d3f39dc83a2;
            uStack_50 = CONCAT44(uStack_50._4_4_,1);
            local_48 = CONCAT71(local_48._1_7_,0x2f);
            local_d8 = 0;
            local_b4 = _GRE_IPv4_CALLOUT_GUID;
            uStack_b0 = uRam00000001c00070b4;
            uStack_ac = uRam00000001c00070b8;
            uStack_a8 = uRam00000001c00070bc;
            local_c8 = 1;
            local_b8 = 0x4005;
            local_a0 = &DAT_1c0009248;
            iVar9 = FwpmFilterAdd0(local_1f8,local_138,0,&local_1d8);
            if (iVar9 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar10 = 0x12;
                bVar4 = bVar5;
                bVar7 = bVar8;
                goto LAB_1c000e5c4;
              }
            }
            else {
              bVar5 = true;
              bVar4 = true;
              local_58 = 0;
              local_68 = 0x4f9a623e3971ef2b;
              uStack_60 = 0xa7b906b8796eb18c;
              uStack_50 = 1;
              local_48 = 0x2f;
              memset(local_138,0,200);
              local_128 = L"RASGRE IPv6 filter";
              local_120 = L"RASGRE IPv6 filter";
              local_f8 = 0x4b90fc23634a869f;
              uStack_f0 = 0x6fae360a62bfc1b0;
              local_c0 = &local_68;
              local_d8 = 0;
              local_b4 = _GRE_IPv6_CALLOUT_GUID;
              uStack_b0 = uRam00000001c00070c4;
              uStack_ac = uRam00000001c00070c8;
              uStack_a8 = uRam00000001c00070cc;
              local_c8 = 1;
              local_b8 = 0x4005;
              local_a0 = &DAT_1c0009248;
              iVar9 = FwpmFilterAdd0(local_1f8,local_138,0,&local_1e0);
              if (iVar9 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar10 = 0x13;
                  bVar4 = bVar5;
                  bVar7 = bVar8;
                  goto LAB_1c000e5c4;
                }
              }
              else {
                bVar3 = true;
                iVar9 = FwpmTransactionCommit0(local_1f8);
                if (iVar9 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar10 = 0x14;
                    bVar4 = bVar5;
                    bVar7 = bVar8;
                    goto LAB_1c000e5c4;
                  }
                }
                else {
                  iVar9 = FwpsInjectionHandleCreate0(2,4,&local_1e8);
                  if (iVar9 < 0) {
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar10 = 0x15;
                      bVar4 = bVar5;
                      bVar7 = bVar8;
                      goto LAB_1c000e5c4;
                    }
                  }
                  else {
                    iVar9 = FwpsInjectionHandleCreate0(0x17,4,&local_1f0);
                    if (-1 < iVar9) {
                      DAT_1c00092c8 = local_1f8;
                      DAT_1c00092e8 = local_1d8;
                      DAT_1c00092f0 = local_1e0;
                      DAT_1c00092f8 = local_1e8;
                      DAT_1c0009300 = local_1f0;
                      goto LAB_1c000eb4b;
                    }
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar10 = 0x16;
                      bVar4 = bVar5;
                      bVar7 = bVar8;
                      goto LAB_1c000e5c4;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_1f0 != 0) {
    FwpsInjectionHandleDestroy0();
  }
  if (local_1e8 != 0) {
    FwpsInjectionHandleDestroy0();
  }
  if (bVar3) {
    FwpmFilterDeleteById0(local_1f8,local_1e0);
  }
  if (bVar4) {
    FwpmFilterDeleteById0(local_1f8,local_1d8);
  }
  if (bVar6) {
    FwpiCalloutUnregisterAndDeleteByKey0(local_1f8,&GRE_IPv6_CALLOUT_GUID);
  }
  if (bVar7) {
    FwpiCalloutUnregisterAndDeleteByKey0(local_1f8,&GRE_IPv4_CALLOUT_GUID);
  }
  if (local_1f8 != 0) {
    FwpmEngineClose0();
  }
LAB_1c000eb52:
  KeReleaseMutex(&DAT_1c0009288,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids,iVar9);
  }
  return unaff_retaddr;
}



===== GreSocketReceive @ 1c000ebe0 =====

undefined8 GreSocketReceive(void)

{
  return 0xc0000001;
}



===== GreCmIncomingCallComplete @ 1c000ebf0 =====

void GreCmIncomingCallComplete(void)

{
  return;
}



===== GreWfpCalloutClassify @ 1c000ebfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GreWfpCalloutClassify(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  ushort uVar3;
  undefined2 *puVar4;
  undefined8 *puVar5;
  bool bVar6;
  int iVar7;
  ushort *puVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  bool bVar15;
  undefined4 *in_stack_00000038;
  char in_stack_00000040;
  undefined1 auStack_a8 [32];
  ushort local_70 [2];
  undefined4 uStack_6c;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined1 local_58 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar7 = 0;
  local_60 = 0;
  bVar6 = false;
  puVar11 = local_58;
  puVar9 = (undefined8 *)0x0;
  _local_70 = 0;
  uStack_68 = 0;
  puVar8 = (ushort *)NdisGetDataBuffer(param_3[1],0x10,puVar11,2);
  if ((puVar8 != (ushort *)0x0) &&
     ((((puVar8[1] == 8 || (puVar8[1] == 0xdd86)) && (uVar3 = *puVar8, (uVar3 & 0x700) == 0)) &&
      (((uVar3 & 0x4f) == 0 && (uVar3 < 0x800)))))) {
    if (in_stack_00000040 == '\0') {
      puVar4 = *(undefined2 **)(*(longlong *)(param_1 + 8) + 0x28);
      _local_70 = CONCAT62(stack0xffffffffffffff92,0x17);
      _local_70 = CONCAT26(puVar4[1],CONCAT24(*puVar4,local_70));
      uStack_68 = *(undefined8 *)(puVar4 + 2);
      local_60 = *(undefined4 *)(puVar4 + 6);
    }
    else {
      uVar12 = *(uint *)(*(longlong *)(param_1 + 8) + 0x28);
      _local_70 = CONCAT44(uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 |
                           uVar12 << 0x18,local_70);
      _local_70 = CONCAT62(stack0xffffffffffffff92,2);
    }
    uVar12 = -(uint)((uVar3 & 0x80) != 0) & 4;
    uVar13 = uVar12 + 4;
    uVar14 = (ulonglong)uVar13;
    if ((uVar3 & 0x20) == 0) {
      puVar9 = GreFindTunnelByIpAddr(local_70);
    }
    else {
      uVar13 = uVar12 + 8;
      puVar9 = GreFindTunnelByGreKey(*(int *)(uVar14 + (longlong)puVar8),local_70,puVar11);
    }
    if (puVar9 != (undefined8 *)0x0) {
      bVar6 = true;
      uVar10 = GreCheckTunnelState((longlong)puVar9);
      iVar7 = (int)uVar10;
      if (-1 < iVar7) {
        piVar1 = (int *)(puVar9 + 8);
        uVar12 = uVar13 + 4;
        if ((*puVar8 & 0x10) == 0) {
          uVar12 = uVar13;
        }
        do {
          puVar5 = (undefined8 *)*param_3;
          *param_3 = 0;
          FwpsReferenceNetBufferList0(param_3,1);
          LOCK();
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          LOCK();
          DAT_1c0009260 = DAT_1c0009260 + 1;
          UNLOCK();
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                      &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids,puVar9,(char)param_3);
          }
          GreQueueRecvPacket((longlong)param_3,uVar12,(longlong)puVar9);
          param_3 = puVar5;
        } while (puVar5 != (undefined8 *)0x0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (*(code *)puVar9[9])(piVar1);
        }
        LOCK();
        iVar2 = DAT_1c0009260 + -1;
        UNLOCK();
        bVar15 = DAT_1c0009260 == 1;
        param_3 = (undefined8 *)0x0;
        DAT_1c0009260 = iVar2;
        if (bVar15) {
          (*DAT_1c0009268)(&DAT_1c0009260);
        }
      }
    }
  }
  *(undefined8 *)(in_stack_00000038 + 2) = 0;
  if (bVar6) {
    in_stack_00000038[7] = in_stack_00000038[7] | 1;
    *in_stack_00000038 = 0x1001;
    in_stack_00000038[6] = in_stack_00000038[6] & 0xfffffffe;
    if (iVar7 < 0) {
      while (param_3 != (undefined8 *)0x0) {
        *(int *)((longlong)param_3 + 0x8c) = iVar7;
        param_3 = (undefined8 *)*param_3;
        LOCK();
        *(int *)((longlong)puVar9 + 0x94) = *(int *)((longlong)puVar9 + 0x94) + 1;
        UNLOCK();
      }
    }
    piVar1 = (int *)(puVar9 + 5);
    LOCK();
    iVar7 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar7 == 1) {
      (*(code *)puVar9[6])();
    }
  }
  else {
    *in_stack_00000038 = 0x2006;
    in_stack_00000038[6] = in_stack_00000038[6] & 1;
  }
  return;
}



===== GreWfpCalloutNotify @ 1c000eec0 =====

undefined8 GreWfpCalloutNotify(void)

{
  return 0;
}



===== GreWfpIpv4CalloutClassify @ 1c000eed0 =====

void GreWfpIpv4CalloutClassify(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  GreWfpCalloutClassify(param_1,param_2,param_3);
  return;
}



===== GreWfpIpv6CalloutClassify @ 1c000ef00 =====

void GreWfpIpv6CalloutClassify(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  GreWfpCalloutClassify(param_1,param_2,param_3);
  return;
}



===== GreCoSendNetBufferLists @ 1c000ef30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GreCoSendNetBufferLists(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  bool bVar7;
  
  uVar4 = GreCheckTunnelState(param_1);
  puVar2 = param_2;
  if ((int)uVar4 < 0) {
    for (; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2) {
      *(int *)((longlong)puVar2 + 0x8c) = (int)uVar4;
    }
    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x38),param_2,0);
  }
  else {
    piVar1 = (int *)(param_1 + 0x40);
    while (param_2 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*param_2;
      *param_2 = 0;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      LOCK();
      DAT_1c0009260 = DAT_1c0009260 + 1;
      UNLOCK();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                  &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,param_1,(char)param_2);
      }
      lVar5 = NdisAllocateCloneNetBufferList(param_2,DAT_1c0007210,DAT_1c0007218,0);
      if (lVar5 == 0) {
        iVar3 = -0x3fffff66;
LAB_1c000f029:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_4620cae832b835f523eaf94c8b7cc7f6_Traceguids,param_2);
        }
        *(int *)((longlong)param_2 + 0x8c) = iVar3;
        NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x38),param_2,0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(param_1 + 0x48))(piVar1);
        }
        LOCK();
        iVar3 = DAT_1c0009260 + -1;
        UNLOCK();
        bVar7 = DAT_1c0009260 == 1;
        param_2 = puVar2;
        DAT_1c0009260 = iVar3;
        if (bVar7) {
          (*DAT_1c0009268)(&DAT_1c0009260);
        }
      }
      else {
        *(undefined8 **)(lVar5 + 0x18) = param_2;
        iVar3 = NdisAllocateNetBufferListContext(lVar5,0x40);
        if (iVar3 < 0) {
          NdisFreeCloneNetBufferList(lVar5,0);
          goto LAB_1c000f029;
        }
        puVar6 = (undefined8 *)
                 (*(longlong *)(lVar5 + 0x10) + 0x10 +
                 (ulonglong)*(ushort *)(*(longlong *)(lVar5 + 0x10) + 10));
        puVar6[3] = 0;
        *(undefined4 *)(puVar6 + 4) = 0;
        *(undefined4 *)(puVar6 + 6) = 0;
        puVar6[2] = lVar5;
        *(undefined4 *)((longlong)puVar6 + 0x24) = 1;
        puVar6[5] = param_1;
        GreQueuePacket((longlong)param_2,puVar6);
        param_2 = puVar2;
      }
    }
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (**(code **)(param_1 + 0x48))(piVar1);
    }
    LOCK();
    iVar3 = DAT_1c0009260 + -1;
    UNLOCK();
    bVar7 = DAT_1c0009260 == 1;
    DAT_1c0009260 = iVar3;
    if (bVar7) {
      (*DAT_1c0009268)(&DAT_1c0009260);
    }
  }
  return;
}



===== GreMiniportReturnNetBufferLists @ 1c000f190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GreMiniportReturnNetBufferLists(longlong param_1,undefined8 *param_2,undefined1 param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (param_2 != (undefined8 *)0x0) {
    piVar1 = (int *)(param_1 + 0x18);
    do {
      puVar3 = (undefined8 *)*param_2;
      *param_2 = 0;
      uVar4 = param_2[3];
      NdisRetreatNetBufferListDataStart
                (param_2,*(undefined4 *)
                          ((ulonglong)*(ushort *)(param_2[2] + 10) + 0x30 + param_2[2]),0,0,0);
      NdisFreeNetBufferListContext(param_2,0x40);
      uVar5 = 0;
      NdisFreeCloneNetBufferList(param_2,2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar5 = 0;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_89c97e6ea79631498ea3fe44c6f1e348_Traceguids,uVar4);
      }
      FwpsDereferenceNetBufferList0
                (uVar4,CONCAT71((int7)((ulonglong)uVar5 >> 8),param_3) & 0xffffffffffffff01);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(param_1 + 0x20))(piVar1);
      }
      param_2 = puVar3;
    } while (puVar3 != (undefined8 *)0x0);
  }
  return;
}



===== GreCmActivateVcComplete @ 1c000f2a0 =====

void GreCmActivateVcComplete(int param_1,longlong param_2)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_2);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_2 + 0x20),&local_res8,0);
  if (param_1 == 0) {
    *(uint *)(param_2 + 0x58) = *(uint *)(param_2 + 0x58) & 0xfffffffb | 2;
    LOCK();
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
    UNLOCK();
    NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x20),&local_res8);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_2);
    }
    NdisCmMakeCallComplete(0,*(undefined8 *)(param_2 + 0x38),0,0,*(undefined8 *)(param_2 + 0x50));
  }
  else {
    *(int *)(param_2 + 0x90) = param_1;
    NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x20));
    GreCleanupTunnel(param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_2,(char)param_1);
  }
  return;
}



===== GreCmDeactivateVcComplete @ 1c000f400 =====

void GreCmDeactivateVcComplete(undefined1 param_1,longlong param_2)

{
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_2);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(param_2 + 0x20),&local_res10,0);
  *(uint *)(param_2 + 0x58) = *(uint *)(param_2 + 0x58) & 0xfffffff7;
  NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x20),&local_res10);
  GreCleanupTunnel(param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_2,param_1);
  }
  return;
}



===== GreCmMakeCallWorkItem @ 1c000f4e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GreCmMakeCallWorkItem(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  uint uVar2;
  int extraout_EAX;
  SOCKADDR_INET *pSVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_98 [32];
  undefined2 local_68;
  undefined1 local_66;
  undefined1 local_60 [24];
  undefined8 uStack_48;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_40 = 0;
  local_60._0_8_ = 0;
  local_60[8] = '\0';
  local_60[9] = '\0';
  local_60[10] = '\0';
  local_60[0xb] = '\0';
  local_60[0xc] = '\0';
  local_60[0xd] = '\0';
  local_60[0xe] = '\0';
  local_60[0xf] = '\0';
  local_38 = 0;
  local_60._16_8_ = 0;
  uStack_48 = 0;
  local_68 = 0;
  local_66 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  NdisFreeIoWorkItem(param_2);
  if (DAT_1c0009330 == 0) {
    DAT_1c0009330 = MmLockPagableDataSection(GreCmActivateVcComplete);
  }
  iVar4 = GreRegisterWfpCallout();
  lVar5 = CONCAT44((int)((ulonglong)param_1 >> 0x20),iVar4);
  iVar4 = extraout_EAX;
  if (-1 < extraout_EAX) {
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar5 + 0x20),&local_68,0);
    uVar2 = *(uint *)(lVar5 + 0x58);
    *(uint *)(lVar5 + 0x58) = uVar2 | 0x200;
    if ((uVar2 & 0x40) == 0) {
      NdisReleaseRWLock(*(undefined8 *)(lVar5 + 0x20),&local_68);
      iVar4 = GreAddTunnel(lVar5);
      if (-1 < iVar4) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                   &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,lVar5);
        }
        NdisAcquireRWLockWrite(*(undefined8 *)(lVar5 + 0x20),&local_68,0);
        *(uint *)(lVar5 + 0x58) = *(uint *)(lVar5 + 0x58) | 0x80;
        NdisReleaseRWLock(*(undefined8 *)(lVar5 + 0x20),&local_68);
        if (*(short *)(lVar5 + 0x7c) == 2) {
          pSVar3 = (SOCKADDR_INET *)local_60;
          local_60._4_4_ = *(undefined4 *)(lVar5 + 0x80);
          local_60._0_2_ = 2;
        }
        else {
          uStack_48 = *(undefined8 *)(lVar5 + 0x80);
          local_40 = *(undefined8 *)(lVar5 + 0x88);
          pSVar3 = (SOCKADDR_INET *)(local_60 + 0x10);
          local_60._16_2_ = 0x17;
        }
        iVar4 = NsiCliAddOrDeleteHostRouteToInterface(pSVar3,*(NET_IFINDEX *)(lVar5 + 0x5c),'\x01');
        if (-1 < iVar4) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                     &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,lVar5);
          }
          NdisAcquireRWLockWrite(*(undefined8 *)(lVar5 + 0x20),&local_68,0);
          *(uint *)(lVar5 + 0x58) = *(uint *)(lVar5 + 0x58) | 0x100;
          NdisReleaseRWLock(*(undefined8 *)(lVar5 + 0x20),&local_68);
          iVar4 = NdisMCmActivateVc(*(undefined8 *)(lVar5 + 0x38),*(undefined8 *)(lVar5 + 0x50));
          if (iVar4 != 0x103) {
            GreCmActivateVcComplete(iVar4,lVar5);
          }
          goto LAB_1c000f61e;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                    &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,lVar5,(char)iVar4);
        }
      }
    }
    else {
      NdisReleaseRWLock();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                 &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,lVar5);
      }
      iVar4 = -0x3fffffff;
    }
  }
  *(int *)(lVar5 + 0x90) = iVar4;
  GreCleanupTunnel(lVar5);
LAB_1c000f61e:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,lVar5,(char)iVar4);
  }
  piVar1 = (int *)(lVar5 + 0x28);
  LOCK();
  iVar4 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar4 == 1) {
    (**(code **)(lVar5 + 0x30))();
  }
  return;
}



===== GreDeleteHostRouteWorkItem @ 1c000f830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GreDeleteHostRouteWorkItem(longlong param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  SOCKADDR_INET *pSVar3;
  undefined1 auStack_78 [56];
  undefined1 local_40 [24];
  undefined8 uStack_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_20 = 0;
  local_40._0_8_ = 0;
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  local_18 = 0;
  local_40._16_8_ = 0;
  uStack_28 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
             &WPP_4d15ee7c219b3251ae20befe7a857582_Traceguids,param_1);
  }
  NdisFreeIoWorkItem(param_2);
  if (*(short *)(param_1 + 0x7c) == 2) {
    pSVar3 = (SOCKADDR_INET *)local_40;
    local_40._4_4_ = *(undefined4 *)(param_1 + 0x80);
    local_40._0_2_ = 2;
  }
  else {
    uStack_28 = *(undefined8 *)(param_1 + 0x80);
    local_20 = *(undefined8 *)(param_1 + 0x88);
    pSVar3 = (SOCKADDR_INET *)(local_40 + 0x10);
    local_40._16_2_ = 0x17;
  }
  NsiCliAddOrDeleteHostRouteToInterface(pSVar3,*(NET_IFINDEX *)(param_1 + 0x5c),'\0');
  piVar1 = (int *)(param_1 + 0x28);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x30))();
  }
  return;
}



===== GreAddIpv4AndGreHeader @ 1c000f93c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GreAddIpv4AndGreHeader(longlong param_1,longlong param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  uint *puVar6;
  void *_Dst;
  byte bVar7;
  size_t _Size;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_58 = 0;
  _Size = 0x18;
  local_68 = (undefined8 *)((ulonglong)local_68 & 0xffffffff00000000);
  local_40 = 0;
  local_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  pbVar5 = (byte *)NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x14,0,4);
  if (pbVar5 == (byte *)0x0) {
LAB_1c000faf0:
    iVar4 = -0x3fffffff;
  }
  else {
    if ((*pbVar5 & 0xf0) == 0x40) {
      uVar3 = 8;
      bVar7 = pbVar5[1] >> 2;
    }
    else {
      local_68 = (undefined8 *)((ulonglong)local_68 & 0xffffffff00000000);
      puVar6 = (uint *)NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x28,0,4);
      if ((puVar6 == (uint *)0x0) || (((byte)*puVar6 & 0xf0) != 0x60)) goto LAB_1c000faf0;
      bVar7 = (byte)(*puVar6 >> 0x16);
      uVar3 = 0xdd86;
    }
    local_40 = CONCAT26(uVar3,(undefined6)local_40);
    if (*(char *)(param_1 + 0x60) != '\0') {
      local_38 = *(undefined4 *)(param_1 + 100);
      _Size = 0x1c;
      local_40 = CONCAT26(uVar3,(undefined6)local_40) | 0x2000000000;
    }
    local_68 = (undefined8 *)0x0;
    iVar4 = NdisRetreatNetBufferListDataStart(param_2,_Size,0,0);
    if (-1 < iVar4) {
      uStack_48 = CONCAT44(*(undefined4 *)(param_1 + 0x6c),(undefined4)uStack_48);
      local_40 = CONCAT44(local_40._4_4_,*(undefined4 *)(param_1 + 0x80));
      puVar1 = *(undefined8 **)(param_2 + 8);
      uStack_48 = CONCAT62(uStack_48._2_6_,0x2f80);
      local_50._0_2_ = CONCAT11(local_50._1_1_ & 3 | bVar7 << 2,0x45);
      uVar2 = local_50;
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
        local_68 = (undefined8 *)((ulonglong)local_68 & 0xffffffff00000000);
        local_50._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
        local_50._0_2_ = (undefined2)uVar2;
        local_50._0_4_ =
             CONCAT22(*(ushort *)(puVar1 + 3) >> 8 | *(ushort *)(puVar1 + 3) << 8,
                      (undefined2)local_50);
        _Dst = (void *)NdisGetDataBuffer(puVar1,_Size,0,1);
        if (_Dst == (void *)0x0) {
          local_68 = &local_58;
          RtlCopyBufferToMdl(&local_50,puVar1[1],*(undefined4 *)(puVar1 + 2),_Size);
        }
        else {
          memcpy(_Dst,&local_50,_Size);
        }
        uVar2 = local_50;
      }
      *param_3 = (int)_Size;
    }
  }
  return iVar4;
}



===== GreAddIpv6AndGreHeader @ 1c000fb24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GreAddIpv6AndGreHeader(longlong param_1,longlong param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  uint *puVar6;
  void *_Dst;
  size_t _Size;
  uint uVar7;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_68 = 0;
  local_78 = (undefined8 *)((ulonglong)local_78 & 0xffffffff00000000);
  _Size = 0x2c;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  pbVar5 = (byte *)NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x14,0,4);
  if (pbVar5 == (byte *)0x0) {
LAB_1c000fcef:
    iVar4 = -0x3fffffff;
  }
  else {
    if ((*pbVar5 & 0xf0) == 0x40) {
      uVar3 = 8;
      uVar7 = (uint)(pbVar5[1] >> 2);
    }
    else {
      local_78 = (undefined8 *)((ulonglong)local_78 & 0xffffffff00000000);
      puVar6 = (uint *)NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x28,0,4);
      if ((puVar6 == (uint *)0x0) || (((byte)*puVar6 & 0xf0) != 0x60)) goto LAB_1c000fcef;
      uVar7 = *puVar6 >> 0x16;
      uVar3 = 0xdd86;
    }
    uStack_38._0_4_ = CONCAT22(uVar3,(undefined2)uStack_38);
    if (*(char *)(param_1 + 0x60) != '\0') {
      _Size = 0x30;
      uStack_38 = CONCAT44(*(undefined4 *)(param_1 + 100),
                           (int)CONCAT62(uStack_38._2_6_,(undefined2)uStack_38)) | 0x20;
    }
    local_78 = (undefined8 *)0x0;
    iVar4 = NdisRetreatNetBufferListDataStart(param_2,_Size,0,0);
    if (-1 < iVar4) {
      uStack_58 = *(undefined8 *)(param_1 + 0x6c);
      local_50 = *(undefined8 *)(param_1 + 0x74);
      uStack_48 = *(undefined8 *)(param_1 + 0x80);
      local_40 = *(undefined8 *)(param_1 + 0x88);
      puVar1 = *(undefined8 **)(param_2 + 8);
      local_60 = CONCAT44(0x802f0000,(uVar7 & 0x3f | 0x180) >> 2 | (uVar7 & 3) << 0xe);
      uVar2 = local_60;
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
        local_78 = (undefined8 *)((ulonglong)local_78 & 0xffffffff00000000);
        local_60._6_2_ = (undefined2)((ulonglong)uVar2 >> 0x30);
        local_60._0_6_ =
             CONCAT24((ushort)(*(short *)(puVar1 + 3) - 0x28U) >> 8 |
                      (*(short *)(puVar1 + 3) - 0x28U) * 0x100,(int)uVar2);
        _Dst = (void *)NdisGetDataBuffer(puVar1,_Size,0,1);
        if (_Dst == (void *)0x0) {
          local_78 = &local_68;
          RtlCopyBufferToMdl(&local_60,puVar1[1],*(undefined4 *)(puVar1 + 2),_Size);
        }
        else {
          memcpy(_Dst,&local_60,_Size);
        }
        uVar2 = local_60;
      }
      *param_3 = (int)_Size;
    }
  }
  return iVar4;
}



===== GreInjectSendPacket @ 1c000fd24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GreInjectSendPacket(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined4 local_res8 [4];
  longlong local_res18;
  ulonglong in_stack_ffffffffffffffa8;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(param_1 + 0x28);
  iVar7 = 0;
  local_res8[0] = 0;
  lVar4 = *(longlong *)(lVar2 + 0x18);
  local_res18 = 0;
  if (((*(uint *)(lVar3 + 0x58) & 0x40) == 0) &&
     (iVar7 = FwpsAllocateNetBufferAndNetBufferList0
                        (DAT_1c00092d0,0,0,0,in_stack_ffffffffffffffa8 & 0xffffffff00000000,0,
                         &local_res18), -1 < iVar7)) {
    *(ulonglong *)(local_res18 + 0xd0) = (ulonglong)*(uint *)(lVar4 + 0xd0);
    *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(local_res18 + 8);
    *(undefined8 *)(local_res18 + 8) = *(undefined8 *)(lVar2 + 8);
    uVar8 = DAT_1c0009300;
    uVar5 = DAT_1c00092f8;
    if (*(short *)(lVar3 + 0x7c) == 2) {
      iVar7 = GreAddIpv4AndGreHeader(lVar3,local_res18,local_res8);
      uVar8 = uVar5;
    }
    else {
      iVar7 = GreAddIpv6AndGreHeader(lVar3,local_res18,local_res8);
    }
    uVar6 = local_res8[0];
    if (-1 < iVar7) {
      *(undefined4 *)(param_1 + 0x20) = local_res8[0];
      iVar7 = FwpsInjectNetworkSendAsync0(uVar8,0,0,1,local_res18,GreSendComplete,param_1);
      if (-1 < iVar7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
          return;
        }
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_4620cae832b835f523eaf94c8b7cc7f6_Traceguids,lVar4);
        return;
      }
      NdisAdvanceNetBufferListDataStart(local_res18,uVar6,1,0);
    }
    *(undefined8 *)(local_res18 + 8) = *(undefined8 *)(param_1 + 0x18);
    FwpsFreeNetBufferList0(local_res18);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_4620cae832b835f523eaf94c8b7cc7f6_Traceguids,lVar4,(char)iVar7);
  }
  NdisFreeNetBufferListContext(lVar2,0x40);
  NdisFreeCloneNetBufferList(lVar2,0);
  NdisMCoSendNetBufferListsComplete(*(undefined8 *)(lVar3 + 0x38),lVar4,0);
  LOCK();
  *(int *)(lVar3 + 0x98) = *(int *)(lVar3 + 0x98) + 1;
  UNLOCK();
  piVar1 = (int *)(lVar3 + 0x40);
  LOCK();
  iVar7 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar7 == 1) {
    (**(code **)(lVar3 + 0x48))();
  }
  LOCK();
  iVar7 = DAT_1c0009260 + -1;
  UNLOCK();
  bVar9 = DAT_1c0009260 == 1;
  DAT_1c0009260 = iVar7;
  if (bVar9) {
    (*DAT_1c0009268)(&DAT_1c0009260);
  }
  return;
}



===== GreSendComplete @ 1c000ff80 =====

void GreSendComplete(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = param_1[2];
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_4620cae832b835f523eaf94c8b7cc7f6_Traceguids,param_1[5],
              (char)*(undefined8 *)(lVar1 + 0x18));
  }
  NdisAdvanceNetBufferListDataStart(param_2,*(undefined4 *)(param_1 + 4),1,0);
  *(undefined8 *)(param_2 + 8) = param_1[3];
  FwpsFreeNetBufferList0(param_2);
  *(undefined4 *)(param_1 + 6) = 2;
  GreQueuePacket(lVar1,param_1);
  return;
}



===== GreIndicateRecvPacket @ 1c0010034 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GreIndicateRecvPacket(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  lVar4 = *(longlong *)(param_1 + 0x28);
  uVar5 = *(undefined8 *)(lVar3 + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_3420acb9a09d3316d45be4afca933d19_Traceguids,uVar5);
  }
  piVar1 = (int *)(lVar4 + 0x40);
  if ((*(uint *)(lVar4 + 0x58) & 0x40) == 0) {
    NdisAdvanceNetBufferListDataStart(lVar3,*(undefined4 *)(param_1 + 0x20),0,0);
    NdisMCoIndicateReceiveNetBufferLists(*(undefined8 *)(lVar4 + 0x38),lVar3,1);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(lVar4 + 0x48))(piVar1);
    }
  }
  else {
    NdisFreeNetBufferListContext();
    NdisFreeCloneNetBufferList(lVar3,2);
    FwpsDereferenceNetBufferList0(uVar5,0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(lVar4 + 0x48))(piVar1);
    }
    LOCK();
    iVar2 = DAT_1c0009260 + -1;
    UNLOCK();
    bVar6 = DAT_1c0009260 == 1;
    DAT_1c0009260 = iVar2;
    if (bVar6) {
      (*DAT_1c0009268)(&DAT_1c0009260);
    }
    LOCK();
    *(int *)(lVar4 + 0x94) = *(int *)(lVar4 + 0x94) + 1;
    UNLOCK();
  }
  return;
}



===== GreQueueRecvPacket @ 1c0010178 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GreQueueRecvPacket(longlong param_1,undefined4 param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  bool bVar5;
  
  lVar3 = NdisAllocateCloneNetBufferList(param_1,DAT_1c0007210,DAT_1c0007218,2);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    *(ulonglong *)(lVar3 + 0xd0) = (ulonglong)*(uint *)(param_1 + 0xd0);
    *(longlong *)(lVar3 + 0x18) = param_1;
    iVar2 = NdisAllocateNetBufferListContext(lVar3,0x40,0,0x32657247);
    if (-1 < iVar2) {
      puVar4 = (undefined8 *)
               (*(longlong *)(lVar3 + 0x10) + 0x10 +
               (ulonglong)*(ushort *)(*(longlong *)(lVar3 + 0x10) + 10));
      puVar4[3] = 0;
      puVar4[2] = lVar3;
      *(undefined4 *)(puVar4 + 4) = param_2;
      *(undefined4 *)((longlong)puVar4 + 0x24) = 2;
      puVar4[5] = param_3;
      *(undefined4 *)(puVar4 + 6) = 1;
      GreQueuePacket(param_1,puVar4);
      return;
    }
    NdisFreeCloneNetBufferList(lVar3,2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_3420acb9a09d3316d45be4afca933d19_Traceguids,param_1);
  }
  *(int *)(param_1 + 0x8c) = iVar2;
  LOCK();
  *(int *)(param_3 + 0x94) = *(int *)(param_3 + 0x94) + 1;
  UNLOCK();
  piVar1 = (int *)(param_3 + 0x40);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_3 + 0x48))();
  }
  LOCK();
  iVar2 = DAT_1c0009260 + -1;
  UNLOCK();
  bVar5 = DAT_1c0009260 == 1;
  DAT_1c0009260 = iVar2;
  if (bVar5) {
    (*DAT_1c0009268)(&DAT_1c0009260);
  }
  FwpsDereferenceNetBufferList0(param_1,0);
  return;
}



===== GreAddTunnel @ 1c00102f0 =====

undefined4 GreAddTunnel(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 *puVar5;
  ushort uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  uVar10 = 0;
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(DAT_1c0007240,&local_res8,0);
  puVar9 = auStack_48;
  cVar1 = *(char *)(param_1 + 0x60);
  if (cVar1 == '\0') {
    if (*(short *)(param_1 + 0x7c) == 2) {
      uVar6 = *(ushort *)(param_1 + 0x82);
    }
    else {
      uVar6 = *(ushort *)(param_1 + 0x8e);
    }
    uVar8 = (uint)(ushort)(uVar6 >> 8 | uVar6 << 8) +
            (uint)(ushort)(*(ushort *)(param_1 + 0x80) >> 8 | *(ushort *)(param_1 + 0x80) << 8) *
            0x25;
  }
  else {
    uVar8 = (uint)(ushort)(*(ushort *)(param_1 + 100) >> 8 | *(ushort *)(param_1 + 100) << 8) * 0x25
            + (uint)(ushort)(*(ushort *)(param_1 + 0x66) >> 8 | *(ushort *)(param_1 + 0x66) << 8);
  }
  plVar13 = &DAT_1c0007248 + (ulonglong)(uVar8 & 0x1ff) * 2;
  plVar11 = (longlong *)*plVar13;
  plVar12 = plVar11;
  if (plVar11 != plVar13) {
    do {
      uVar7 = GreCompareTunnelAddr((ushort *)((longlong)plVar11 + 0x6c),(ushort *)(param_1 + 0x7c));
      if (((char)uVar7 == '\x01') &&
         ((puVar5 = auStack_48, (char)plVar11[10] != cVar1 ||
          (puVar5 = auStack_48, *(int *)((longlong)plVar11 + 0x54) == *(int *)(param_1 + 100)))))
      goto LAB_1c0010424;
      plVar11 = (longlong *)*plVar11;
    } while (plVar11 != plVar13);
  }
  lVar2 = *plVar12;
  plVar11 = (longlong *)(param_1 + 0x10);
  if (*(longlong **)(lVar2 + 8) == plVar12) {
    *plVar11 = lVar2;
    *(longlong **)(param_1 + 0x18) = plVar12;
    *(longlong **)(lVar2 + 8) = plVar11;
    *plVar12 = (longlong)plVar11;
    LOCK();
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    UNLOCK();
  }
  else {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar5 = auStack_40;
LAB_1c0010424:
    puVar9 = puVar5;
    uVar10 = 0xc000022a;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar9 + -8) = 0x1c001045a;
      WPP_SF_q(uVar3,0xb,&WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,param_1);
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x1c0010481;
  NdisReleaseRWLock(DAT_1c0007240,puVar9 + 0x50);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined4 *)(puVar9 + 0x20) = uVar10;
    *(undefined8 *)(puVar9 + -8) = 0x1c00104bc;
    WPP_SF_qD(uVar3,0xc,&WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,param_1,puVar9[0x20]);
  }
  return uVar10;
}



===== GreCompareTunnelAddr @ 1c00104d8 =====

ulonglong GreCompareTunnelAddr(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar1 = *param_1;
  uVar2 = (ulonglong)uVar1;
  if (uVar1 != *param_2) {
LAB_1c0010515:
    return uVar2 & 0xffffffffffffff00;
  }
  if (uVar1 == 2) {
    uVar2 = (ulonglong)*(uint *)(param_2 + 2);
    if (*(uint *)(param_1 + 2) != *(uint *)(param_2 + 2)) goto LAB_1c0010515;
  }
  else if (uVar1 == 0x17) {
    lVar3 = *(longlong *)(param_1 + 2) - *(longlong *)(param_2 + 2);
    if (lVar3 == 0) {
      lVar3 = *(longlong *)(param_1 + 6) - *(longlong *)(param_2 + 6);
    }
    return (ulonglong)(lVar3 == 0);
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== GreFindTunnelByGreKey @ 1c0010520 =====

undefined8 * GreFindTunnelByGreKey(int param_1,ushort *param_2,undefined8 param_3)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  ushort uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  puVar2 = (undefined8 *)0x0;
  uVar3 = (ushort)((uint)param_1 >> 0x10);
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1);
  }
  NdisAcquireRWLockRead(DAT_1c0007240,&local_res8,1);
  puVar5 = &DAT_1c0007248 +
           (ulonglong)
           ((uint)(ushort)((ushort)param_1 >> 8 | (ushort)param_1 << 8) * 0x25 +
            (uint)(ushort)(uVar3 >> 8 | uVar3 << 8) & 0x1ff) * 2;
  puVar4 = (undefined8 *)*puVar5;
  do {
    if (puVar4 == puVar5) {
LAB_1c00105f2:
      NdisReleaseRWLock(DAT_1c0007240,&local_res8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,puVar2);
      }
      return puVar2;
    }
    if (((*(char *)(puVar4 + 10) == '\x01') && (param_1 == *(int *)((longlong)puVar4 + 0x54))) &&
       (uVar1 = GreCompareTunnelAddr((ushort *)((longlong)puVar4 + 0x6c),param_2),
       (char)uVar1 == '\x01')) {
      puVar2 = puVar4 + -2;
      LOCK();
      *(int *)(puVar4 + 3) = *(int *)(puVar4 + 3) + 1;
      UNLOCK();
      goto LAB_1c00105f2;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== GreFindTunnelByIpAddr @ 1c0010660 =====

undefined8 * GreFindTunnelByIpAddr(ushort *param_1)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  puVar3 = (undefined8 *)0x0;
  local_res8 = 0;
  local_resa = 0;
  if (*param_1 == 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,*(undefined4 *)(param_1 + 2));
    }
    uVar2 = (uint)(ushort)(param_1[2] >> 8 | param_1[2] << 8) * 0x25 +
            (uint)(ushort)(param_1[3] >> 8 | param_1[3] << 8);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)param_1[8],
                      (ulonglong)param_1[7],(uint)param_1[2],(char)param_1[3],(char)param_1[4],
                      (char)param_1[5],(char)param_1[6],(char)param_1[7],(char)param_1[8],
                      (char)param_1[9]);
    }
    uVar2 = (uint)(ushort)(param_1[9] >> 8 | param_1[9] << 8) +
            (uint)(ushort)(param_1[2] >> 8 | param_1[2] << 8) * 0x25;
  }
  NdisAcquireRWLockRead(DAT_1c0007240,&local_res8,1);
  puVar5 = &DAT_1c0007248 + (ulonglong)(uVar2 & 0x1ff) * 2;
  puVar4 = (undefined8 *)*puVar5;
  do {
    if (puVar4 == puVar5) {
LAB_1c00107cb:
      NdisReleaseRWLock(DAT_1c0007240,&local_res8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,puVar3);
      }
      return puVar3;
    }
    if ((*(char *)(puVar4 + 10) == '\0') &&
       (uVar1 = GreCompareTunnelAddr((ushort *)((longlong)puVar4 + 0x6c),param_1),
       (char)uVar1 == '\x01')) {
      puVar3 = puVar4 + -2;
      LOCK();
      *(int *)(puVar4 + 3) = *(int *)(puVar4 + 3) + 1;
      UNLOCK();
      goto LAB_1c00107cb;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== GreRemoveTunnel @ 1c0010838 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GreRemoveTunnel(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  char cVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_1ee05a30180435e9c9e60199094f9636_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(DAT_1c0007240,&local_res8,0);
  plVar1 = (longlong *)(param_1 + 0x10);
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) != plVar1) ||
     (plVar5 = *(longlong **)(param_1 + 0x18), (longlong *)*plVar5 != plVar1)) {
    pcVar6 = (code *)swi(0x29);
    pcVar8 = (char *)(*pcVar6)(3);
    cVar7 = (char)pcVar8;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    *pcVar8 = *pcVar8 + cVar7;
    pcVar6 = (code *)swi(3);
    uVar9 = (*pcVar6)();
    return uVar9;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  piVar2 = (int *)(param_1 + 0x28);
  LOCK();
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    (**(code **)(param_1 + 0x30))();
  }
  NdisReleaseRWLock(DAT_1c0007240,&local_res8);
  return 0;
}



===== FreeSockContextCommon @ 1c0011008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeSockContextCommon(longlong param_1)

{
  undefined1 uVar1;
  
  (**(code **)(param_1 + 0x30))("FreeSockContextCommon..Freeing the Socket Context");
  if ((*(uint *)(param_1 + 0x188) & 0x800) != 0) {
    (**(code **)(param_1 + 0x30))("FreeSockContextCommon..Freeing Socket Lists and locks");
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1c8);
    *(undefined1 *)(param_1 + 0x1d0) = uVar1;
    ExDeleteNPagedLookasideList(param_1 + 0x80);
    ExDeleteNPagedLookasideList(param_1 + 0x100);
    *(undefined8 *)(param_1 + 0x180) = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    KeReleaseSpinLock(param_1 + 0x1c8,*(undefined1 *)(param_1 + 0x1d0));
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== FreeSockHandle @ 1c00110d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeSockHandle(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x180) == 0) {
    FreeSockContextCommon(param_1);
  }
  else if (((*(uint *)(param_1 + 0x188) & 0x10) == 0) || ((*(uint *)(param_1 + 0x188) & 2) != 0)) {
    WskCloseSocketAndFreeSocketContext(param_1);
  }
  else {
    (**(code **)(param_1 + 0x30))("FreeSockHandle..Issuing Disconnect for Connected Sockets");
    WskDisconnectSocket(param_1);
  }
  return;
}



===== ReceiveData @ 1c001112c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ReceiveData(longlong param_1,undefined8 param_2,int param_3,longlong *param_4,longlong *param_5)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 auStack_c8 [32];
  ulonglong local_a8;
  ulonglong *local_a0;
  int local_98;
  int local_94;
  ulonglong local_90;
  longlong local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar9 = 0;
  local_80 = param_5;
  local_88 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x188) & 0x20) == 0) {
      return 0;
    }
    if (param_4 == (longlong *)0x0) {
      return 0;
    }
    local_94 = param_3;
    do {
      if (((param_3 == 2) && (param_4[4] != 0)) && (*(int *)(param_4[4] + 0xc) != 0x13)) {
        return 0;
      }
      if (((ulonglong)param_4[3] <= (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 8)) ||
         (param_3 == 1)) {
        plVar8 = (longlong *)ExAllocateFromNPagedLookasideList(param_1 + 0x80);
        if (plVar8 == (longlong *)0x0) {
          return 0;
        }
        *plVar8 = param_1;
        if (param_3 == 2) {
          psVar2 = (short *)param_4[6];
          lVar3 = param_4[4];
          plVar8[1] = (longlong)psVar2;
          sVar1 = *psVar2;
          if (sVar1 == 0x17) {
            if (((lVar3 != 0) && (*(int *)(lVar3 + 0xc) == 0x13)) &&
               ((undefined8 *)(lVar3 + 0x10) != (undefined8 *)0x0)) {
              uStack_60 = *(undefined8 *)(lVar3 + 0x10);
              local_58 = *(undefined8 *)(lVar3 + 0x18);
              local_68 = CONCAT62(local_68._2_6_,0x17);
              plVar8[3] = (longlong)&local_68;
              uVar6 = *(undefined4 *)(lVar3 + 0x20);
LAB_1c0011273:
              *(undefined4 *)(plVar8 + 2) = uVar6;
            }
          }
          else if (((sVar1 == 2) && (lVar3 != 0)) &&
                  ((*(int *)(lVar3 + 0xc) == 0x13 &&
                   ((undefined4 *)(lVar3 + 0x10) != (undefined4 *)0x0)))) {
            local_78 = CONCAT44(*(undefined4 *)(lVar3 + 0x10),(undefined4)local_78);
            local_78 = CONCAT62(local_78._2_6_,2);
            plVar8[3] = (longlong)&local_78;
            uVar6 = *(undefined4 *)(lVar3 + 0x14);
            goto LAB_1c0011273;
          }
        }
        uVar10 = *(uint *)(param_4 + 3);
        local_98 = (int)param_4[2];
        if (uVar10 != 0) {
          do {
            puVar4 = *(undefined8 **)(param_1 + 0x48);
            uVar5 = uVar10;
            if (*(uint *)(puVar4 + 1) <= uVar10) {
              uVar5 = *(uint *)(puVar4 + 1);
            }
            uVar11 = (ulonglong)uVar5;
            lVar9 = NdisAllocateNetBufferList(*puVar4,*(undefined2 *)((longlong)puVar4 + 0xc),0);
            if (lVar9 == 0) goto LAB_1c00113cf;
            local_a8 = 0;
            iVar7 = NdisRetreatNetBufferListDataStart(lVar9,uVar11,0,0);
            if (iVar7 < 0) {
LAB_1c00113c0:
              NdisFreeNetBufferList(lVar9);
LAB_1c00113cf:
              ExFreeToNPagedLookasideList(param_1 + 0x80,plVar8);
              return 0;
            }
            local_a0 = &local_90;
            local_90 = 0;
            local_a8 = uVar11;
            RtlCopyMdlToMdl(param_4[1],local_98,*(undefined8 *)(*(longlong *)(lVar9 + 8) + 8));
            if (local_90 != uVar11) goto LAB_1c00113c0;
            local_98 = local_98 + uVar5;
            plVar8[4] = lVar9;
            LOCK();
            *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
            UNLOCK();
            (**(code **)(param_1 + 0x10))(param_1 + 8,plVar8);
            uVar10 = uVar10 - uVar5;
          } while (uVar10 != 0);
          lVar9 = local_88;
          param_3 = local_94;
        }
        lVar9 = lVar9 + param_4[3];
        local_88 = lVar9;
        ExFreeToNPagedLookasideList(param_1 + 0x80,plVar8);
      }
      param_4 = (longlong *)*param_4;
    } while (param_4 != (longlong *)0x0);
    param_5 = local_80;
  }
  if (param_5 != (longlong *)0x0) {
    *param_5 = lVar9;
  }
  return 0;
}



===== WskBindCompletion @ 1c00113f0 =====

undefined8 WskBindCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,2);
  return 0xc0000016;
}



===== WskCloseSocketAndFreeSocketContext @ 1c001141c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WskCloseSocketAndFreeSocketContext(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if (*(longlong *)(param_1 + 0x180) != 0) {
    lVar2 = IoAllocateIrp(1,0);
    if (lVar2 != 0) {
      lVar1 = **(longlong **)(param_1 + 0x180);
      lVar2 = *(longlong *)(lVar2 + 0xb8);
      *(code **)(lVar2 + -0x10) = WskCloseSocketIrpCompletion;
      *(longlong *)(lVar2 + -8) = param_1;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      (**(code **)(lVar1 + 8))(*(undefined8 *)(param_1 + 0x180));
    }
  }
  return;
}



===== WskCloseSocketContextAndFreeSocket @ 1c0011488 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskCloseSocketContextAndFreeSocket(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong *plVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  
  (**(code **)(param_1 + 0x30))("WskCloseSocketContextAndFreeSocketEx..Enter");
  (**(code **)(param_1 + 0x30))("WskCloseSocketContext..Enter");
  lVar1 = param_1 + 0x1c8;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar5 = *(uint *)(param_1 + 0x188);
  *(undefined1 *)(param_1 + 0x1d0) = uVar8;
  if ((uVar5 & 0x40) == 0) {
    *(uint *)(param_1 + 0x188) = uVar5 & 0xffffffdf | 0x40;
    KeReleaseSpinLock(lVar1,CONCAT31((int3)((uVar5 & 0xffffffdf) >> 8),uVar8));
    if (*(longlong *)(param_1 + 0x180) != 0) {
      if (((byte)*(uint *)(param_1 + 0x188) & 0x12) == 0x12) {
        (**(code **)(param_1 + 0x30))("WskCloseSocketContext..Close on Stream Server Socket");
        WskCloseStreamServerSocketContext(param_1);
      }
      else if ((*(uint *)(param_1 + 0x188) & 4) != 0) {
        (**(code **)(param_1 + 0x30))("WskCloseSocketContext..Close on Stream Socket");
        uVar8 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x1f8) + 0x1c8);
        *(undefined1 *)(*(longlong *)(param_1 + 0x1f8) + 0x1d0) = uVar8;
        plVar3 = (longlong *)(param_1 + 0x1a8);
        lVar1 = *plVar3;
        if ((*(longlong **)(lVar1 + 8) != plVar3) ||
           (plVar6 = *(longlong **)(param_1 + 0x1b0), (longlong *)*plVar6 != plVar3)) {
          pcVar7 = (code *)swi(0x29);
          (*pcVar7)(3);
          pcVar7 = (code *)swi(3);
          uVar9 = (*pcVar7)();
          return uVar9;
        }
        *plVar6 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar6;
        lVar1 = *(longlong *)(param_1 + 0x1f8);
        KeReleaseSpinLock(lVar1 + 0x1c8,
                          CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x1d0)));
      }
      LOCK();
      piVar2 = (int *)(param_1 + 0x200);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        (**(code **)(param_1 + 0x208))(param_1);
      }
    }
  }
  else {
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar5 >> 8),uVar8));
  }
  LOCK();
  piVar2 = (int *)(param_1 + 0x200);
  iVar4 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar4 == 1) {
    (**(code **)(param_1 + 0x208))(param_1);
  }
  return 0;
}



===== WskCloseSocketIrpCompletion @ 1c0011620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskCloseSocketIrpCompletion(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  IoFreeIrp(param_2);
  *(undefined8 *)(param_3 + 0x180) = 0;
  (**(code **)(param_3 + 0x30))("WskCloseSocket Done");
  (**(code **)(param_3 + 0x30))("Freeing Sock Context");
  FreeSockContextCommon(param_3);
  return 0xc0000016;
}



===== WskCloseStreamServerSocketContext @ 1c001167c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskCloseStreamServerSocketContext(longlong param_1)

{
  undefined8 ****ppppuVar1;
  undefined8 ****ppppuVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 ****ppppuVar5;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 ***pppuVar8;
  undefined1 uVar9;
  undefined8 ****ppppuVar10;
  undefined8 ****local_18;
  undefined8 ****local_10;
  
  (**(code **)(param_1 + 0x30))("WskCloseStreamServerSocketContext..Enter");
  local_10 = &local_18;
  local_18 = &local_18;
  uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1c8);
  *(undefined1 *)(param_1 + 0x1d0) = uVar9;
  puVar7 = *(undefined8 **)(param_1 + 0x1a8);
  while (puVar7 != (undefined8 *)(param_1 + 0x1a8)) {
    puVar4 = (undefined8 *)*puVar7;
    ppppuVar1 = (undefined8 ****)(puVar7 + 2);
    puVar7[3] = ppppuVar1;
    *ppppuVar1 = ppppuVar1;
    if ((undefined8 *****)local_18[1] != &local_18) goto LAB_1c00117e6;
    *ppppuVar1 = local_18;
    puVar7[3] = &local_18;
    local_18[1] = ppppuVar1;
    LOCK();
    *(int *)(puVar7 + 0xb) = *(int *)(puVar7 + 0xb) + 1;
    UNLOCK();
    puVar7 = puVar4;
    local_18 = ppppuVar1;
  }
  KeReleaseSpinLock(param_1 + 0x1c8,
                    CONCAT71((int7)((ulonglong)puVar7 >> 8),*(undefined1 *)(param_1 + 0x1d0)));
  while( true ) {
    ppppuVar1 = local_18;
    if ((undefined8 *****)local_18 == &local_18) {
      return 0;
    }
    if (((undefined8 *****)local_18[1] != &local_18) ||
       (ppppuVar5 = (undefined8 ****)*local_18, (undefined8 ****)ppppuVar5[1] != local_18)) break;
    ppppuVar5[1] = &local_18;
    ppppuVar10 = local_18 + -0x37;
    ppppuVar2 = local_18 + 2;
    local_18 = ppppuVar5;
    uVar9 = KeAcquireSpinLockRaiseToDpc(ppppuVar2);
    pppuVar8 = ppppuVar1[-6];
    *(undefined1 *)(ppppuVar1 + 3) = uVar9;
    KeReleaseSpinLock(ppppuVar2,uVar9);
    if ((((ulonglong)pppuVar8 & 0x40) == 0) && (ppppuVar1[-0x34] != (undefined8 ***)0x0)) {
      (*(code *)ppppuVar1[-0x34])(ppppuVar1 + -0x36);
    }
    LOCK();
    ppppuVar5 = ppppuVar1 + 9;
    iVar3 = *(int *)ppppuVar5;
    *(int *)ppppuVar5 = *(int *)ppppuVar5 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)ppppuVar1[10])(ppppuVar10);
    }
  }
LAB_1c00117e6:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  return 0;
}



===== WskConnDisconnectEvent @ 1c0011810 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskConnDisconnectEvent(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  
  (**(code **)(param_1 + 0x30))("WskConnDisconnectEvent..Enter");
  lVar1 = param_1 + 0x1c8;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar3 = *(uint *)(param_1 + 0x188);
  *(undefined1 *)(param_1 + 0x1d0) = uVar2;
  if ((uVar3 & 0x140) == 0) {
    uVar3 = uVar3 & 0xffffffdf | 0x100;
    *(uint *)(param_1 + 0x188) = uVar3;
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar3 >> 8),uVar2));
    if (((byte)*(undefined4 *)(param_1 + 0x188) & 0x12) == 0x12) {
      (**(code **)(param_1 + 0x30))("WskConnDisconnectEvent..Server Sock..");
      WskCloseSocketContextAndFreeSocket(param_1);
    }
    else if (*(longlong *)(param_1 + 0x18) != 0) {
      (**(code **)(param_1 + 0x30))
                ("WskConnDisconnectEvent..Non-Server Sock..Calling DisconnectHandler");
      (**(code **)(param_1 + 0x18))(param_1 + 8);
    }
  }
  else {
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar3 >> 8),uVar2));
  }
  return 0;
}



===== WskConnReceiveEvent @ 1c00118f0 =====

void WskConnReceiveEvent(longlong param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
                        longlong *param_5)

{
  ReceiveData(param_1,param_2,1,param_3,param_5);
  return;
}



===== WskConnSendBacklogEvent @ 1c0011920 =====

undefined8 WskConnSendBacklogEvent(void)

{
  return 0;
}



===== WskConnectControlCompletion @ 1c0011930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskConnectControlCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x1c8);
  *(uint *)(param_3 + 0x188) = *(uint *)(param_3 + 0x188) | 0x20;
  *(undefined1 *)(param_3 + 0x1d0) = uVar4;
  KeReleaseSpinLock(param_3 + 0x1c8,uVar4);
  if (*(code **)(param_3 + 0x28) != (code *)0x0) {
    (**(code **)(param_3 + 0x28))(*(undefined8 *)(param_3 + 8),param_3,uVar3);
  }
  LOCK();
  piVar1 = (int *)(param_3 + 0x200);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_3 + 0x208))(param_3);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WskControlSocket @ 1c00119e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskControlSocket(undefined8 *param_1,undefined8 param_2,undefined4 param_3,
                          undefined4 param_4,undefined8 param_5,undefined8 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong in_stack_00000050;
  undefined8 in_stack_00000058;
  
  KeResetEvent(in_stack_00000058);
  IoReuseIrp(in_stack_00000050,0xc0000001);
  lVar1 = *(longlong *)(in_stack_00000050 + 0xb8);
  *(code **)(lVar1 + -0x10) = WskBindCompletion;
  *(undefined8 *)(lVar1 + -8) = in_stack_00000058;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  uVar2 = (**(code **)*param_1)(param_1,0,param_3,param_4,param_5,param_6,0,0,0,in_stack_00000050);
  if (-1 < (int)uVar2) {
    KeWaitForSingleObject(in_stack_00000058,0,0,0,0);
    uVar2 = (ulonglong)*(uint *)(in_stack_00000050 + 0x30);
  }
  return uVar2;
}



===== WskCreateSocket @ 1c0011af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskCreateSocket(short *param_1,undefined8 param_2,byte param_3,longlong param_4,
                         uint param_5)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  short *psVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar13;
  
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  psVar8 = param_1;
  lVar11 = param_4;
  puVar6 = (undefined8 *)GetWskClientContext();
  if (puVar6 == (undefined8 *)0x0) {
    uVar9 = 0xc00002b9;
  }
  else if ((ushort)(*psVar8 - 1U) < 3) {
    *(uint *)(lVar11 + 0x188) = *(uint *)(lVar11 + 0x188) | 1;
    LOCK();
    *(int *)(lVar11 + 0x200) = *(int *)(lVar11 + 0x200) + 1;
    UNLOCK();
    NdisGetVersion();
    uVar10 = CONCAT44(uVar13,0x72774152);
    ExInitializeNPagedLookasideList
              (param_4 + 0x80,0,0,0x200,(ulonglong)param_5 + 0x37 & 0xfffffffffffffff8,uVar10,10);
    uVar13 = (undefined4)((ulonglong)uVar10 >> 0x20);
    NdisGetVersion();
    uVar12 = 0x200;
    uVar10 = 0;
    ExInitializeNPagedLookasideList(param_4 + 0x100,0,0,0x200,0x40,CONCAT44(uVar13,0x73774152),10);
    lVar11 = param_4 + 0x1c8;
    KeInitializeSpinLock(lVar11);
    lVar1 = param_4 + 0x1a8;
    *(longlong *)(param_4 + 0x1b0) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(uint *)(param_4 + 0x188) = *(uint *)(param_4 + 0x188) | 0x800;
    if (*param_1 == 1) {
      uVar7 = WskOpenConnectedSocket(puVar6,*(undefined8 *)(param_1 + 8),param_2,uVar12,param_4);
      uVar9 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        *(uint *)(param_4 + 0x188) = *(uint *)(param_4 + 0x188) | 0x10;
        return uVar9;
      }
      LOCK();
      piVar2 = (int *)(param_4 + 0x200);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    else {
      uVar7 = WskOpenSocket(puVar6,param_1,uVar10,param_4,param_3 | 8,
                            (undefined8 *)(param_4 + 0x180));
      uVar9 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar11);
        *(uint *)(param_4 + 0x188) = *(uint *)(param_4 + 0x188) | 0x20;
        *(undefined1 *)(param_4 + 0x1d0) = uVar5;
        KeReleaseSpinLock(lVar11,uVar5);
        uVar4 = *(uint *)(param_4 + 0x188);
        *(uint *)(param_4 + 0x188) = uVar4 | 8;
        if (*param_1 == 3) {
          *(uint *)(param_4 + 0x188) = uVar4 | 0x408;
          return uVar9;
        }
        return uVar9;
      }
      LOCK();
      piVar2 = (int *)(param_4 + 0x200);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar3 == 1) {
      (**(code **)(param_4 + 0x208))(param_4);
    }
  }
  else {
    uVar9 = 0xc000000d;
  }
  return uVar9;
}



===== WskDisconnectSocket @ 1c0011d18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WskDisconnectSocket(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  
  (**(code **)(param_1 + 0x30))("WskDisconnectSocket..Enter");
  if (*(longlong *)(param_1 + 0x180) != 0) {
    lVar5 = IoAllocateIrp(1,0);
    if (lVar5 != 0) {
      lVar3 = **(longlong **)(param_1 + 0x180);
      *(code **)(param_1 + 0x218) = WskSocketDisconnectDone;
      *(undefined4 *)(param_1 + 0x210) = 1;
      LOCK();
      *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 1;
      UNLOCK();
      lVar4 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar4 + -0x10) = WskSocketDisconnectCompletion;
      *(longlong *)(lVar4 + -8) = param_1;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      bVar6 = (*(uint *)(param_1 + 0x188) & 0x1000) != 0;
      if (bVar6) {
        (**(code **)(param_1 + 0x30))("WskDisconnectSocket..Issuing ABORTIVE Disconnect");
        *(uint *)(param_1 + 0x188) = *(uint *)(param_1 + 0x188) & 0xffffefff;
      }
      (**(code **)(lVar3 + 0x40))(*(undefined8 *)(param_1 + 0x180),0,bVar6,lVar5);
      (**(code **)(param_1 + 0x30))("WskDisconnectSocket..Issuing reref for DISC Initial");
      LOCK();
      piVar1 = (int *)(param_1 + 0x210);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(param_1 + 0x218))(param_1);
      }
    }
  }
  return;
}



===== WskLibDummyLogger @ 1c0011e40 =====

void WskLibDummyLogger(void)

{
  return;
}



===== WskOpenConnectedSocket @ 1c0011e4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskOpenConnectedSocket
                    (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    longlong param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  KeInitializeEvent(param_5 + 400,0,0);
  lVar3 = IoAllocateIrp(1,0);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    LOCK();
    *(int *)(param_5 + 0x200) = *(int *)(param_5 + 0x200) + 1;
    UNLOCK();
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = WskOpenConnectedSocketCompletion;
    *(longlong *)(lVar1 + -8) = param_5;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    uVar4 = (**(code **)(param_1[1] + 0x10))
                      (*param_1,1,6,param_2,param_3,0,param_5,&g_WskClientConnDispatch,0,0,0,lVar3);
    iVar2 = (int)uVar4;
    if (-1 < iVar2) {
      if (*(char *)(param_5 + 0x38) == '\0') {
        uVar4 = KeWaitForSingleObject(param_5 + 400,0,0,0,0);
      }
      else {
        uVar4 = uVar4 & 0xffffffff;
        if (iVar2 == 0x103) {
          uVar4 = 0;
        }
      }
    }
  }
  return uVar4;
}



===== WskOpenConnectedSocketCompletion @ 1c0011f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskOpenConnectedSocketCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  bool bVar5;
  longlong lVar6;
  undefined *local_18;
  undefined8 uStack_10;
  
  bVar5 = true;
  local_18 = (undefined *)0x0;
  uStack_10 = 0;
  if (-1 < *(int *)(param_2 + 0x30)) {
    puVar3 = *(undefined8 **)(param_2 + 0x38);
    *(undefined8 **)(param_3 + 0x180) = puVar3;
    lVar6 = IoAllocateIrp(1,0);
    if (lVar6 != 0) {
      local_18 = &NPI_WSK_INTERFACE_ID;
      uStack_10 = CONCAT44(uStack_10._4_4_,0xc0);
      lVar4 = *(longlong *)(lVar6 + 0xb8);
      *(code **)(lVar4 + -0x10) = WskConnectControlCompletion;
      *(longlong *)(lVar4 + -8) = param_3;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      (**(code **)*puVar3)(puVar3,0,0x4002,0xffff,0x10,&local_18,0,0,0,lVar6);
      bVar5 = false;
      goto LAB_1c0011ff1;
    }
  }
  if (*(code **)(param_3 + 0x28) != (code *)0x0) {
    (**(code **)(param_3 + 0x28))(*(undefined8 *)(param_3 + 8),param_3);
  }
LAB_1c0011ff1:
  KeSetEvent(param_3 + 400,2);
  if (bVar5) {
    LOCK();
    piVar1 = (int *)(param_3 + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_3 + 0x208))(param_3);
    }
    LOCK();
    piVar1 = (int *)(param_3 + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_3 + 0x208))(param_3);
    }
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WskOpenSocket @ 1c00120fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskOpenSocket(undefined8 *param_1,undefined2 *param_2,undefined8 param_3,
                       undefined8 param_4,byte param_5,undefined8 *param_6)

{
  short sVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 local_res18;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar11;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_res18 = param_3;
  KeInitializeEvent(&local_38,0,0);
  sVar1 = **(short **)(param_2 + 8);
  lVar6 = IoAllocateIrp(1,0);
  if (lVar6 == 0) {
    return 0xc000009a;
  }
  lVar8 = *(longlong *)(lVar6 + 0xb8);
  *(code **)(lVar8 + -0x10) = WskBindCompletion;
  *(undefined8 **)(lVar8 + -8) = &local_38;
  *(undefined1 *)(lVar8 + -0x45) = 0xe0;
  uVar5 = (**(code **)(param_1[1] + 8))
                    (*param_1,**(undefined2 **)(param_2 + 8),*param_2,*(undefined4 *)(param_2 + 2),
                     CONCAT44(uVar11,*(undefined4 *)(param_2 + 4)),param_4,&g_WskClientDgramDispatch
                     ,0,0,0,lVar6);
  uVar10 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) goto LAB_1c001249d;
  uVar9 = 0;
  KeWaitForSingleObject(&local_38,0,0,0,0);
  uVar10 = (ulonglong)*(uint *)(lVar6 + 0x30);
  if ((int)*(uint *)(lVar6 + 0x30) < 0) goto LAB_1c001249d;
  plVar2 = *(longlong **)(lVar6 + 0x38);
  if ((param_5 & 2) == 0) {
LAB_1c0012268:
    KeResetEvent(&local_38);
    IoReuseIrp(lVar6,0xc0000001);
    lVar8 = *(longlong *)(lVar6 + 0xb8);
    *(code **)(lVar8 + -0x10) = WskBindCompletion;
    *(undefined8 **)(lVar8 + -8) = &local_38;
    *(undefined1 *)(lVar8 + -0x45) = 0xe0;
    uVar5 = (**(code **)(*plVar2 + 0x10))(plVar2,*(undefined8 *)(param_2 + 8),0);
    uVar10 = (ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      uVar9 = 0;
      KeWaitForSingleObject(&local_38,0,0,0,0);
      uVar10 = (ulonglong)*(uint *)(lVar6 + 0x30);
      if (-1 < (int)*(uint *)(lVar6 + 0x30)) {
        if ((param_5 & 1) != 0) {
          local_res18 = CONCAT44(local_res18._4_4_,1);
          uVar7 = WskControlSocket(plVar2,uVar9,0x13,-(uint)(sVar1 != 2) & 0x29,4,&local_res18);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c0012453;
        }
        if ((param_5 & 8) != 0) {
          local_3c = 0;
          local_48 = &NPI_WSK_INTERFACE_ID;
          local_40 = 0x100;
          uVar7 = WskControlSocket(plVar2,uVar9,0x4002,0xffff,0x10,&local_48);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c0012453;
        }
        if ((param_5 & 0x10) != 0) {
          local_3c = 0;
          local_48 = &NPI_WSK_INTERFACE_ID;
          local_40 = 0x200;
          uVar7 = WskControlSocket(plVar2,uVar9,0x4002,0xffff,0x10,&local_48);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c0012453;
        }
        if ((param_5 & 4) != 0) {
          local_res18 = CONCAT44(local_res18._4_4_,1);
          uVar7 = WskControlSocket(plVar2,uVar9,2,-(uint)(sVar1 != 2) & 0x29,4,&local_res18);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c0012453;
        }
        *param_6 = plVar2;
        goto LAB_1c001249d;
      }
    }
  }
  else {
    local_res18 = CONCAT44(local_res18._4_4_,1);
    uVar7 = WskControlSocket(plVar2,uVar9,4,0xffff,4,&local_res18);
    uVar10 = uVar7 & 0xffffffff;
    if (-1 < (int)uVar7) goto LAB_1c0012268;
  }
LAB_1c0012453:
  if ((plVar2 != (longlong *)0x0) && (lVar8 = IoAllocateIrp(1,0), lVar8 != 0)) {
    lVar3 = *(longlong *)(lVar8 + 0xb8);
    lVar4 = *plVar2;
    *(undefined8 *)(lVar3 + -8) = 0;
    *(code **)(lVar3 + -0x10) = WskSocketIrpCompletion;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    (**(code **)(lVar4 + 8))(plVar2,lVar8);
  }
LAB_1c001249d:
  IoFreeIrp(lVar6);
  return uVar10;
}



===== WskReceiveDataGramFromEvent @ 1c00124e0 =====

void WskReceiveDataGramFromEvent(longlong param_1,undefined8 param_2,longlong *param_3)

{
  ReceiveData(param_1,param_2,2,param_3,(longlong *)0x0);
  return;
}



===== WskSocketDisconnectCompletion @ 1c0012510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskSocketDisconnectCompletion(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  
  IoFreeIrp(param_2);
  (**(code **)(param_3 + 0x30))("WskSocketDisconnectCompletion..Deref for DISC Pending");
  LOCK();
  piVar1 = (int *)(param_3 + 0x210);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_3 + 0x218))(param_3);
  }
  return 0xc0000016;
}



===== WskSocketDisconnectDone @ 1c0012570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WskSocketDisconnectDone(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x188) & 4) != 0) {
    (**(code **)(param_1 + 0x30))("In WskSocketDisconnectDone..removing ref on serversock");
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x1f8) + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(*(longlong *)(param_1 + 0x1f8) + 0x208))();
    }
  }
  WskCloseSocketAndFreeSocketContext(param_1);
  return;
}



===== WskSocketIrpCompletion @ 1c00125e0 =====

undefined8 WskSocketIrpCompletion(undefined8 param_1,undefined8 param_2)

{
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== entry @ 1c0013010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0013044 =====

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



===== DriverEntry @ 1c0013078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint DriverEntry(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  byte bVar6;
  undefined1 auStack_178 [32];
  undefined8 *local_158;
  code *local_150;
  void *local_148;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 local_f4;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_88;
  code *local_80;
  code *local_78;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_178;
  memset(&local_f8,0,0x98);
  local_58 = 0x100180;
  local_130 = 0;
  local_54 = 0x400100;
  local_50 = 0x34657247;
  local_48 = 0xc0180;
  local_44 = 0x35657247;
  _WPP_MAIN_CB = 0;
  DAT_1c0009368 = &WPP_ThisDir_CTLGUID_GreTraceGuid;
  DAT_1c0009370 = 0;
  _DAT_1c0009380 = 0;
  _DAT_1c0009388 = 1;
  WppLoadTracingSupport();
  _DAT_1c0009380 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_ceeb3f528cc733bf1a867b4bd3b91a36_Traceguids,param_1);
  }
  _GreCB = param_1;
  KeInitializeSpinLock(&DAT_1c0007220);
  DAT_1c0007238 = &DAT_1c0007230;
  _DAT_1c0007230 = &DAT_1c0007230;
  DAT_1c0007240 = NdisAllocateRWLock(DAT_1c0009248);
  if (DAT_1c0007240 == 0) {
    uVar1 = 0xc000009a;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_ceeb3f528cc733bf1a867b4bd3b91a36_Traceguids,0xc000009a);
    }
    goto LAB_1c00136c9;
  }
  puVar2 = &DAT_1c0007248;
  lVar3 = 0x200;
  do {
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar2 + 2;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  lVar3 = NdisAllocateNetBufferListPool(DAT_1c0009248,&local_58);
  if (lVar3 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    bVar6 = 0xc0;
    DAT_1c0007210 = lVar3;
    lVar3 = NdisAllocateNetBufferPool(DAT_1c0009248,&local_48);
    if (lVar3 == 0) {
      uVar1 = 0xc000009a;
LAB_1c001369e:
      NdisFreeNetBufferListPool(DAT_1c0007210);
    }
    else {
      NsiCliTag = 0x31657247;
      bVar6 = 0xe0;
      DAT_1c0007218 = lVar3;
      KeInitializeEvent(&NsiCliDriverUnloadEvent,0,0);
      _DAT_1c00070d8 = _GRE_NSI_CLI_GUID;
      uRam00000001c00070dc = DAT_1c0007094;
      uRam00000001c00070e0 = uRam00000001c0007098;
      uRam00000001c00070e4 = uRam00000001c000709c;
      uVar1 = NmrRegisterClient(&NsiCliNotify,0,&NsiCliHandle);
      if (uVar1 == 0) {
        LOCK();
        NsiCliDriverRefCount = NsiCliDriverRefCount + 1;
        UNLOCK();
LAB_1c00132d7:
        local_f8 = 0x98028a;
        local_e8 = GreMiniportSetOptions;
        local_f4 = 0x11e06;
        local_e0 = GreMiniportInitializeEx;
        local_d8 = GreMiniportHaltEx;
        local_d0 = GreMiniportUnload;
        local_c8 = GreMiniportPause;
        local_c0 = GreMiniportRestart;
        local_b0 = GreCmIncomingCallComplete;
        local_a8 = GreMiniportReturnNetBufferLists;
        local_a0 = GreCmIncomingCallComplete;
        local_88 = _guard_check_icall;
        local_80 = _guard_check_icall;
        local_78 = _guard_check_icall;
        local_158 = &DAT_1c0007208;
        uVar1 = NdisMRegisterMiniportDriver(param_1,param_2,&local_130,&local_f8);
        if (uVar1 == 0) {
          bVar6 = 0xf4;
          DAT_1c0009258 = NdisAllocateRWLock(DAT_1c0009248);
          if (DAT_1c0009258 == 0) {
            uVar1 = 0xc000009a;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                       &WPP_ceeb3f528cc733bf1a867b4bd3b91a36_Traceguids,0xc000009a);
            }
          }
          else {
            bVar6 = 0xfc;
            uVar1 = GreInitializeWfp();
            if ((int)uVar1 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                         &WPP_ceeb3f528cc733bf1a867b4bd3b91a36_Traceguids,uVar1);
              }
            }
            else {
              DAT_1c0009338 = KeQueryActiveProcessorCountEx(0xffff);
              DAT_1c0009340 =
                   (void *)NdisAllocateMemoryWithTagPriority
                                     (DAT_1c0007208,DAT_1c0009338 * 0xa8,0x37657247,0x10);
              if (DAT_1c0009340 == (void *)0x0) goto LAB_1c00136c9;
              bVar6 = 0xff;
              memset(DAT_1c0009340,0,(ulonglong)(uint)(DAT_1c0009338 * 3) * 0x38);
              uVar5 = 0;
              if (DAT_1c0009338 * 3 == 0) {
                return uVar1;
              }
              while( true ) {
                lVar4 = (ulonglong)uVar5 * 0x38;
                *(uint *)(lVar4 + 0x30 + (longlong)DAT_1c0009340) = uVar5 / 3;
                NdisInitializeEvent((longlong)DAT_1c0009340 + lVar4 + 0x18);
                local_128 = 0x30;
                lVar3 = (longlong)DAT_1c0009340 + lVar4 + 8;
                local_110 = 0x200;
                local_120 = 0;
                local_118 = 0;
                *(longlong *)(lVar3 + 8) = lVar3;
                *(longlong *)lVar3 = lVar3;
                local_148 = (void *)((longlong)DAT_1c0009340 + lVar4);
                local_150 = GreProcessPacket;
                local_158 = (undefined8 *)0x0;
                local_108 = 0;
                uStack_100 = 0;
                uVar1 = PsCreateSystemThread(local_148,0x1fffff,&local_128,0);
                if ((int)uVar1 < 0) break;
                uVar5 = uVar5 + 1;
                if ((uint)(DAT_1c0009338 * 3) <= uVar5) {
                  return uVar1;
                }
              }
              NdisFreeMemoryWithTagPriority(DAT_1c0007208,DAT_1c0009340,0x37657247);
              GreUninitializeWfp();
            }
            NdisFreeRWLock(DAT_1c0009258);
            if ((bVar6 & 4) == 0) goto LAB_1c001367a;
          }
          NdisMDeregisterMiniportDriver(DAT_1c0007208);
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_ceeb3f528cc733bf1a867b4bd3b91a36_Traceguids,uVar1);
          }
          if (-1 < (int)uVar1) goto LAB_1c00136c9;
          bVar6 = 0xf0;
        }
LAB_1c001367a:
        NsiCliDeregisterClient();
        if ((bVar6 & 0x20) != 0) goto LAB_1c0013685;
      }
      else {
        if (-1 < (int)uVar1) goto LAB_1c00132d7;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_ceeb3f528cc733bf1a867b4bd3b91a36_Traceguids,uVar1);
        }
LAB_1c0013685:
        NdisFreeNetBufferPool(DAT_1c0007218);
      }
      if ((bVar6 & 0x40) != 0) goto LAB_1c001369e;
    }
    if (-1 < (char)bVar6) goto LAB_1c00136c9;
  }
  NdisFreeRWLock(DAT_1c0007240);
LAB_1c00136c9:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_ceeb3f528cc733bf1a867b4bd3b91a36_Traceguids,uVar1);
  }
  return uVar1;
}



===== GreInitializeWfp @ 1c001372c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint GreInitializeWfp(void)

{
  longlong lVar1;
  uint uVar2;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0x100180;
  local_24 = 0x100;
  local_20 = 0x33657247;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids);
  }
  KeInitializeMutex(&DAT_1c0009288,0);
  lVar1 = NdisAllocateNetBufferListPool(DAT_1c0009248,&local_28);
  if (lVar1 != 0) {
    DAT_1c00092d0 = lVar1;
  }
  uVar2 = ~-(uint)(lVar1 != 0) & 0xc000009a;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_c701387adac13150c7f9fa6bad9fdf50_Traceguids,uVar2);
  }
  return uVar2;
}


