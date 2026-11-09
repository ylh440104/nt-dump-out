
===== DfscGetContainerContextFromIrp @ 140001010 =====

void DfscGetContainerContextFromIrp(longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = IoGetSiloParameters(*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30));
  if ((lVar3 != 0) && (*(longlong *)(lVar3 + 8) != 0)) {
    uVar1 = PsGetSiloMonitorContextSlot(DAT_14000d838);
    iVar2 = PsGetPermanentSiloContext(*(undefined8 *)(lVar3 + 8),uVar1,param_2);
    if (-1 < iVar2) {
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,param_1,(char)iVar2);
    }
  }
  *param_2 = 0;
  return;
}



===== DfscScavenger @ 1400010d0 =====

void DfscScavenger(void)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (g_DfscTimerSet != '\0') {
    uVar3 = DfscAgeOutExpiredCacheEntries(DAT_14000d6d0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_3fb209eb6de739644fdff57447ad0b44_Traceguids,(int)uVar3);
    }
    if (((g_DfscTimerSet != '\0') &&
        (uVar3 = DfscAgeOutExpiredCacheEntries(DAT_14000d6c8),
        (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_3fb209eb6de739644fdff57447ad0b44_Traceguids,(int)uVar3);
    }
  }
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(&DAT_14000d658,1);
  puVar4 = DAT_14000d828;
  if ((undefined8 **)DAT_14000d828 != &DAT_14000d828) {
    do {
      puVar1 = (undefined8 *)*puVar4;
      if (g_DfscTimerSet != '\0') {
        uVar3 = DfscAgeOutExpiredCacheEntries(puVar4[0x11]);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_3fb209eb6de739644fdff57447ad0b44_Traceguids,(int)uVar3);
        }
        if (((g_DfscTimerSet != '\0') &&
            (uVar3 = DfscAgeOutExpiredCacheEntries(puVar4[0x10]),
            (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_3fb209eb6de739644fdff57447ad0b44_Traceguids,(int)uVar3);
        }
      }
      puVar4 = puVar1;
    } while ((undefined8 **)puVar1 != &DAT_14000d828);
  }
  ExReleaseResourceLite(&DAT_14000d658);
  KeLeaveCriticalRegion();
  uVar2 = KeAcquireSpinLockRaiseToDpc(&g_DfscTimerSpinLock);
  g_DfscTimerPosted = 0;
  if ((g_DfscTimerSet == '\0') || (DAT_14000d794 == 0)) {
    if (g_DfscTimerCompleteEvent != 0) {
      KeSetEvent(g_DfscTimerCompleteEvent,0,0);
    }
  }
  else {
    KeSetCoalescableTimer(&g_DfscTimer,(ulonglong)DAT_14000d794 * -10000000,0,1000,&g_DfscTimerDpc);
  }
  KeReleaseSpinLock(&g_DfscTimerSpinLock,uVar2);
  return;
}



===== DfscCmCompletionRoutine @ 140001340 =====

undefined8 DfscCmCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== DfscReferralSetCurrentAccessStatus @ 14000136c =====

void DfscReferralSetCurrentAccessStatus(longlong param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = (ulonglong)*(ushort *)(param_1 + 0x20) * 0x70;
  if (*(int *)(lVar1 + 0xa8 + *(longlong *)(param_1 + 0x10)) != param_2) {
    *(int *)(lVar1 + 0xa8 + *(longlong *)(param_1 + 0x10)) = param_2;
  }
  return;
}



===== RtlStringCbLengthW @ 140001394 =====

uint RtlStringCbLengthW(short *param_1,ulonglong param_2,longlong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = param_2 >> 1;
  uVar2 = 0;
  if ((param_1 == (short *)0x0) || (uVar1 = uVar4, 0x7fffffff < uVar4)) {
    uVar3 = 0xc000000d;
  }
  else {
    for (; (uVar1 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
      uVar1 = uVar1 - 1;
    }
    uVar3 = ~-(uint)(uVar1 != 0) & 0xc000000d;
    uVar2 = -(ulonglong)(uVar1 != 0) & uVar4 - uVar1;
  }
  if (param_3 != (longlong *)0x0) {
    if ((int)uVar3 < 0) {
      *param_3 = 0;
    }
    else {
      *param_3 = uVar2 * 2;
    }
  }
  return uVar3;
}



===== DfscReferralReference @ 14000140c =====

void DfscReferralReference(longlong param_1)

{
  if (param_1 != 0) {
    LOCK();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    UNLOCK();
  }
  return;
}



===== DfscNetUseIncrementOpenHandleCount @ 140001420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscNetUseIncrementOpenHandleCount
              (longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined1 auStackY_c8 [32];
  undefined8 local_80;
  wchar_t local_78 [4];
  undefined2 *puStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined2 local_48;
  undefined4 local_46;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_80 = 0;
  local_78[0] = L'\0';
  local_78[1] = L'\0';
  local_78[2] = L'\0';
  local_78[3] = L'\0';
  puStack_70 = (undefined2 *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  iVar1 = DfscGetLogonId((longlong)&local_68 + 4);
  if (-1 < iVar1) {
    iVar1 = DfscGetEffectiveRequestorSessionId(param_4,(undefined4 *)&local_68);
    if (-1 < iVar1) {
      local_48 = *(undefined2 *)(*(longlong *)(param_2 + 8) + 4);
      local_46 = 0x3a;
      uVar2 = DfscGetDriveLetterNetUseTable(param_1);
      uStack_50 = CONCAT44(uStack_50._4_4_,1);
      local_78[0] = L'\x06';
      local_78[1] = L'\x06';
      local_78[2] = L'\0';
      local_78[3] = L'\0';
      puStack_70 = &local_48;
      KeEnterCriticalRegion();
      puVar5 = &DAT_14000d6e0;
      puVar4 = (undefined *)(param_1 + 0x98);
      if (param_1 == 0) {
        puVar4 = &DAT_14000d6e0;
      }
      ExAcquireResourceExclusiveLite(puVar4,1);
      lVar3 = DfscNetUseTableLookup(uVar2,local_78,(longlong)&local_80);
      if (lVar3 == 0) {
        iVar1 = -0x3fffffcc;
      }
      else {
        *(int *)(lVar3 + 0x90) = *(int *)(lVar3 + 0x90) + 1;
        *(longlong *)(param_3 + 8) = lVar3;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_qZq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,lVar3 + 0x58,lVar3,
                     (wchar_t *)(lVar3 + 0x58),(char)*(undefined8 *)(lVar3 + 0x70));
        }
      }
      if (param_1 != 0) {
        puVar5 = (undefined *)(param_1 + 0x98);
      }
      ExReleaseResourceLite(puVar5);
      KeLeaveCriticalRegion();
    }
  }
  return iVar1;
}



===== DfscGetReferralFromPath @ 1400015bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DfscGetReferralFromPath
              (longlong param_1,undefined2 *param_2,ushort *param_3,undefined4 param_4,
              longlong param_5,longlong *param_6,longlong param_7,short *param_8)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  short *psVar6;
  longlong local_28 [2];
  
  local_28[0] = 0;
  iVar3 = DfscCmInitializeContext
                    (param_1,param_2,param_5,(undefined4 *)param_3,(longlong *)0x0,param_7,local_28)
  ;
  lVar2 = local_28[0];
  if (iVar3 < 0) {
    if (iVar3 == -0x3fffffea) {
      iVar3 = -0x3fffffcc;
    }
  }
  else {
    *(undefined4 *)(local_28[0] + 0x124) = param_4;
    lVar5 = 0;
    do {
      iVar4 = (int)lVar5;
      iVar3 = (*(code *)(&DfscCmDispatchTable)[iVar4])(lVar2);
      lVar5 = (longlong)iVar3;
      *(int *)(lVar2 + 0x138) = iVar4;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_qDSS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,param_5,lVar2,
                    (char)*(undefined4 *)(lVar2 + 0x13c),(wchar_t *)(&DfscStateTextTable)[iVar4],
                    (wchar_t *)(&DfscStateTextTable)[lVar5]);
      }
    } while (iVar3 != 10);
    iVar3 = *(int *)(lVar2 + 0x13c);
    if (-1 < iVar3) {
      *param_6 = *(longlong *)(lVar2 + 0x110);
      *(undefined8 *)(lVar2 + 0x110) = 0;
      if (*param_6 != 0) {
        *(undefined2 *)(*param_6 + 0x20) = 0xffff;
      }
      if (param_8 != (short *)0x0) {
        sVar1 = *(short *)(lVar2 + 0xe0);
        param_8[1] = sVar1;
        *param_8 = sVar1;
        psVar6 = (short *)((*(longlong *)(param_3 + 4) - (ulonglong)*(ushort *)(lVar2 + 0xe0)) +
                          (ulonglong)*param_3);
        *(short **)(param_8 + 4) = psVar6;
        if ((sVar1 == 2) && (*psVar6 == 0x5c)) {
          *param_8 = 0;
        }
      }
    }
    DfscCmReleaseContext(lVar2);
  }
  return iVar3;
}



===== DfscCachePurge @ 140001758 =====

void DfscCachePurge(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  char cVar4;
  
  cVar3 = '\0';
  cVar4 = '\0';
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0x38,1);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0xa0,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    param_3 = &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_1);
  }
  uVar2 = 1;
  while( true ) {
    lVar1 = RtlNextUnicodePrefix(param_1,uVar2);
    if (lVar1 == 0) break;
    if (*(char *)(lVar1 + -0x34) == '\0') {
      DfscRmUnlinkReferral(lVar1 + -0x48);
      DfscRmDereferenceReferral(lVar1 + -0x48);
      cVar3 = cVar3 + '\x01';
    }
    else {
      cVar4 = cVar4 + '\x01';
    }
    uVar2 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,param_3,param_1,cVar3,cVar4);
  }
  ExReleaseResourceLite(param_1 + 0xa0);
  KeLeaveCriticalRegion();
  ExReleaseResourceLite(param_1 + 0x38);
  KeLeaveCriticalRegion();
  return;
}



===== DfscTimerDispatch @ 1400018c0 =====

void DfscTimerDispatch(void)

{
  KeAcquireSpinLockAtDpcLevel(&g_DfscTimerSpinLock);
  if (g_DfscTimerPosted == '\0') {
    if ((g_DfscTimerSet != '\0') && (DAT_14000d794 != 0)) {
      g_DfscTimerPosted = 1;
      KeReleaseSpinLockFromDpcLevel(&g_DfscTimerSpinLock);
      IoQueueWorkItem(g_DfscTimerWorkItem,DfscScavenger,1);
      return;
    }
    if (g_DfscTimerCompleteEvent != 0) {
      KeSetEvent(g_DfscTimerCompleteEvent,0,0);
    }
  }
  KeReleaseSpinLockFromDpcLevel(&g_DfscTimerSpinLock);
  return;
}



===== DfscGetDCName @ 14000196c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

RPC_STATUS DfscGetDCName(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  RPC_STATUS RVar2;
  undefined1 auStack_f8 [32];
  RPC_BINDING_HANDLE local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  int local_b8;
  RPC_BINDING_HANDLE local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  _RPC_ASYNC_STATE local_88;
  
  local_88.Reserved[2] = __security_cookie ^ (ulonglong)auStack_f8;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  memset(&local_88,0,0x58);
  local_b0 = (RPC_BINDING_HANDLE)0x0;
  local_a8 = 0;
  iVar1 = DfscRpcConnect(&local_b0);
  if (iVar1 == 0) {
    KeInitializeEvent(&local_a0,0,0);
    iVar1 = RpcAsyncInitializeHandle(&local_88,0x58);
    local_b8 = iVar1;
    if (iVar1 == 0) {
      local_88.NotificationType = RpcNotificationTypeEvent;
      local_88.u.APC.NotificationRoutine = (PFN_RPCNOTIFICATION_ROUTINE)&local_a0;
      local_d8 = local_b0;
      local_d0 = param_1;
      local_c8 = param_3;
      local_c0 = param_2;
      Ndr64AsyncClientCall((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140009000,0,(void *)0x0);
      local_d8 = (RPC_BINDING_HANDLE)0x0;
      KeWaitForSingleObject(&local_a0,0,0,0);
      RVar2 = RpcAsyncCompleteCall(&local_88,(void *)0x0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,RVar2);
      }
      iVar1 = 0;
      if (RVar2 != 0) {
        iVar1 = -0x3fffffde;
      }
      local_b8 = iVar1;
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,iVar1);
    }
    RpcBindingUnbind(local_b0);
    local_a8 = 1;
    RpcBindingFree(&local_b0);
  }
  return iVar1;
}



===== DfscRpcConnect @ 140001c00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscRpcConnect(undefined8 *param_1)

{
  int iVar1;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  RPC_BINDING_HANDLE local_c0;
  int local_b8;
  undefined4 local_b0;
  undefined8 local_ac;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined4 *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  local_c8 = 0;
  local_c0 = (RPC_BINDING_HANDLE)0x0;
  *param_1 = 0;
  local_58 = 3;
  local_38 = 0;
  uStack_30 = 0;
  local_60 = 1;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 3;
  local_84 = 1;
  local_80 = 1;
  local_7c = 3;
  local_68 = &NetworkService;
  local_ac = 0;
  local_a4 = 0;
  local_98 = 0;
  local_b0 = 1;
  local_a0 = 6;
  local_9c = 10;
  local_90 = &local_88;
  local_28 = 1;
  local_24 = 1;
  local_20 = 5;
  iVar1 = RpcBindingCreateW(&local_60,&local_b0,&local_28,&local_c0);
  local_b8 = iVar1;
  if (iVar1 == 0) {
    local_c8 = 1;
    iVar1 = RpcBindingBind(0,local_c0,&DAT_140009030);
    if (iVar1 == 0) {
      *param_1 = local_c0;
    }
    else {
      local_b8 = iVar1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,iVar1);
      }
      RpcBindingFree(&local_c0);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,iVar1);
  }
  return iVar1;
}



===== DfscRmGenerateDomainDcReferralFromDCName @ 140001e30 =====

ulonglong DfscRmGenerateDomainDcReferralFromDCName
                    (ushort *param_1,wchar_t *param_2,undefined8 *param_3,undefined1 param_4,
                    undefined1 param_5)

{
  undefined2 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  void *_Dst;
  uint uVar4;
  wchar_t local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar4 = DAT_14000d788;
  local_24 = 0;
  puVar1 = DfscRmAllocateReferral((uint)(ushort)*param_2 + *param_1 + 0x114,0x72436644);
  if (puVar1 == (undefined2 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    puVar1[8] = puVar1[8] | 8;
    *(undefined1 *)(puVar1 + 9) = param_4;
    *(undefined4 *)(puVar1 + 0xe) = 1;
    if (600 < uVar4) {
      uVar4 = 600;
    }
    *(undefined1 *)((longlong)puVar1 + 0x13) = param_5;
    *(undefined2 **)(puVar1 + 0x4c) = puVar1 + 0x88;
    *(uint *)(puVar1 + 0x14) = uVar4;
    puVar1[0x49] = *param_1 + 2;
    RtlCopyUnicodeString(puVar1 + 0x48,param_1);
    _Dst = (void *)((ulonglong)(ushort)puVar1[0x49] + *(longlong *)(puVar1 + 0x4c));
    memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)(ushort)*param_2);
    *(undefined2 *)((longlong)_Dst + (ulonglong)((ushort)*param_2 >> 1) * 2) = 0;
    local_28 = *param_2;
    local_26 = local_28 + L'\x02';
    local_20 = _Dst;
    uVar2 = DfscInitDfsPath(&local_28,puVar1 + 0x58);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      DfscRmDereferenceReferral((longlong)puVar1);
    }
    else {
      *(undefined4 *)(puVar1 + 0x54) = 0xffffffff;
      *(undefined4 *)(puVar1 + 6) = 0;
      *(undefined8 *)(puVar1 + 0x40) = *(undefined8 *)(puVar1 + 0x48);
      *(undefined8 *)(puVar1 + 0x44) = *(undefined8 *)(puVar1 + 0x4c);
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar1;
      }
    }
  }
  return uVar3;
}



===== DfscRmGenerateSysvolNetlogonReferral @ 140001f98 =====

ulonglong DfscRmGenerateSysvolNetlogonReferral
                    (longlong param_1,ushort *param_2,undefined1 param_3,undefined8 *param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong local_98;
  longlong lStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  
  local_98 = 0;
  lStack_90 = 0;
  memset(&local_88,0,0x60);
  uVar6 = DAT_14000d788;
  puVar1 = (ushort *)(param_1 + 0x30);
  puVar2 = (ushort *)(param_1 + 0x10);
  puVar3 = DfscRmAllocateReferral((uint)*param_2 + (uint)*puVar1 + *puVar2 + 0x11c,0x72436644);
  if (puVar3 == (undefined2 *)0x0) {
    uVar5 = 0xc000009a;
  }
  else {
    puVar3[8] = puVar3[8] | 8;
    *(undefined1 *)(puVar3 + 9) = param_3;
    *(undefined4 *)(puVar3 + 0xe) = 1;
    if (900 < uVar6) {
      uVar6 = 900;
    }
    *(undefined2 **)(puVar3 + 0x4c) = puVar3 + 0x88;
    *(uint *)(puVar3 + 0x14) = uVar6;
    puVar3[0x49] = *puVar1 + 2;
    RtlCopyUnicodeString(puVar3 + 0x48,puVar1);
    uVar4 = DfscInitDfsPath(puVar3 + 0x48,(short *)&local_88);
    uVar5 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      lStack_90 = (ulonglong)(ushort)puVar3[0x49] + *(longlong *)(puVar3 + 0x4c);
      local_98 = (ulonglong)CONCAT42((int)(local_98 >> 0x20),*puVar2 + *param_2 + 10) << 0x10;
      RtlAppendUnicodeToString(&local_98,L"\\");
      RtlAppendUnicodeStringToString(&local_98,param_2);
      RtlAppendUnicodeToString(&local_98,L"\\");
      RtlAppendUnicodeStringToString(&local_98,puVar2);
      *(undefined2 *)(lStack_90 + -2 + (local_98 >> 0x11 & 0x7fff) * 2) = 0;
      uVar4 = DfscInitDfsPath((wchar_t *)&local_98,puVar3 + 0x58);
      uVar5 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        *(undefined4 *)(puVar3 + 0x54) = 0xffffffff;
        puVar3[8] = puVar3[8] & 0xfffd;
        *(undefined8 *)(puVar3 + 0x40) = local_88;
        *(undefined8 *)(puVar3 + 0x44) = uStack_80;
        *(undefined4 *)(puVar3 + 6) = 1;
        if (param_4 == (undefined8 *)0x0) {
          return uVar5;
        }
        *param_4 = puVar3;
        return uVar5;
      }
    }
    DfscRmDereferenceReferral((longlong)puVar3);
  }
  return uVar5;
}



===== DfscRmAllocateReferral @ 140002198 =====

undefined2 * DfscRmAllocateReferral(uint param_1,undefined4 param_2)

{
  undefined2 *_Dst;
  ulonglong uVar1;
  
  _Dst = (undefined2 *)ExAllocatePool2(0x102,param_1,param_2);
  if (_Dst != (undefined2 *)0x0) {
    memset(_Dst,0,(ulonglong)param_1);
    *_Dst = 0x8103;
    _Dst[1] = (short)param_1;
    *(undefined4 *)(_Dst + 2) = 1;
    uVar1 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 != 0) {
      *(uint *)(_Dst + 4) = param_1;
    }
  }
  return _Dst;
}



===== WPP_SF_ZqsZZD @ 14000220c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZqsZZD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
                  undefined1 param_5,char *param_6,wchar_t *param_7,wchar_t *param_8,
                  undefined1 param_9)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  char *pcVar4;
  wchar_t wVar5;
  longlong lVar6;
  longlong lVar7;
  wchar_t *pwVar8;
  wchar_t wVar9;
  wchar_t *pwVar10;
  wchar_t *pwVar11;
  
  pwVar3 = L"NULL";
  wVar5 = L'\b';
  if (param_8 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_8;
    if (*param_8 != L'\0') {
      pwVar11 = *(wchar_t **)(param_8 + 4);
      goto LAB_140002273;
    }
  }
  pwVar11 = L"NULL";
LAB_140002273:
  pwVar2 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  if ((param_7 == (wchar_t *)0x0) || (wVar5 = *param_7, *param_7 == L'\0')) {
    pwVar10 = L"NULL";
  }
  else {
    pwVar10 = *(wchar_t **)(param_7 + 4);
  }
  pwVar8 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar8 = L"\b";
  }
  if (param_6 == (char *)0x0) {
    lVar7 = 5;
  }
  else {
    lVar6 = -1;
    do {
      lVar7 = lVar6;
      lVar6 = lVar7 + 1;
    } while (param_6[lVar6] != '\0');
    lVar7 = lVar7 + 2;
  }
  pcVar4 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  if (param_4 == (wchar_t *)0x0) {
    wVar9 = L'\b';
  }
  else {
    wVar9 = *param_4;
    if (*param_4 != L'\0') {
      pwVar3 = *(wchar_t **)(param_4 + 4);
    }
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_d29483b364bf358e773d59db54935b3a_Traceguids,0xb,param_4,2,pwVar3,
             wVar9,&param_5,8,pcVar4,lVar7,pwVar8,2,pwVar10,wVar5,pwVar2,2,pwVar11,wVar1,&param_9,4,
             0);
  return;
}



===== WPP_SF_qd @ 1400023d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== DfscPathPrefixMatch @ 140002424 =====

ulonglong DfscPathPrefixMatch(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar1 = *param_1;
  uVar3 = (ulonglong)uVar1;
  if (1 < uVar1) {
    uVar2 = *param_2;
    uVar4 = (ulonglong)uVar2;
    if ((1 < uVar2) && (uVar1 <= uVar2)) {
      if (uVar1 != uVar2) {
        uVar3 = *(ulonglong *)(param_2 + 4);
        uVar2 = *(ushort *)(uVar3 + (ulonglong)(uVar1 >> 1) * 2);
        uVar4 = (ulonglong)uVar2;
        if (((uVar2 != 0x5c) && (uVar2 != 0x3a)) &&
           (*(short *)((uVar3 - 2) + (ulonglong)(uVar1 >> 1) * 2) != 0x5c)) goto LAB_140002484;
      }
      uVar3 = RtlPrefixUnicodeString(param_1,param_2,CONCAT71((int7)(uVar4 >> 8),1));
      if ((char)uVar3 != '\0') {
        return CONCAT71((int7)(uVar3 >> 8),1);
      }
    }
  }
LAB_140002484:
  return uVar3 & 0xffffffffffffff00;
}



===== __report_gsfailure @ 1400024a0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400024ad =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400024ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== DfscClusterSetCachePurge @ 1400024c0 =====

void DfscClusterSetCachePurge(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  char cVar4;
  
  cVar3 = '\0';
  cVar4 = '\0';
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0x38,1);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0xa0,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    param_3 = &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_1);
  }
  uVar2 = 1;
  while( true ) {
    lVar1 = RtlNextUnicodePrefix(param_1,uVar2);
    if (lVar1 == 0) break;
    if (*(char *)(lVar1 + -0x34) == '\0') {
      cVar4 = cVar4 + '\x01';
    }
    else {
      DfscRmUnlinkReferral(lVar1 + -0x48);
      DfscRmDereferenceReferral(lVar1 + -0x48);
      cVar3 = cVar3 + '\x01';
    }
    uVar2 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,param_3,param_1,cVar3,cVar4);
  }
  ExReleaseResourceLite(param_1 + 0xa0);
  KeLeaveCriticalRegion();
  ExReleaseResourceLite(param_1 + 0x38);
  KeLeaveCriticalRegion();
  return;
}



===== Feature_3910819131__private_IsEnabledDeviceUsageNoInline @ 14000261c =====

ulonglong Feature_3910819131__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3910819131__private_featureState;
  if ((Feature_3910819131__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3910819131__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3910819131__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3910819131__private_IsEnabledFallback @ 140002654 =====

void Feature_3910819131__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== WPP_SF_ @ 140002670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_LL @ 14000269c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_q @ 1400026ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qDD @ 140002730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qZ @ 140002798 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400027d1;
    }
  }
  pwVar1 = L"NULL";
LAB_1400027d1:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,param_5,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_qqZ @ 140002838 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar1 = *(wchar_t **)(param_6 + 4);
      goto LAB_140002874;
    }
  }
  pwVar1 = L"NULL";
LAB_140002874:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,0xc,&local_res20,8,
             &param_5,8,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400028f0 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 1400029c8 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140002aac =====

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
LAB_140002c04:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140002bf7:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140002c04;
      if (uVar5 == 5) goto LAB_140002bf7;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140002c2c =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140002cb0 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140002da0 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002eb0 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140002f14 =====

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



===== wil_details_IsEnabledFallback @ 140003074 =====

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



===== wil_details_MapReportingKind @ 140003108 =====

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



===== WPP_SF_D @ 1400031a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDZ @ 1400031ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar1 = *(wchar_t **)(param_6 + 4);
      goto LAB_140003226;
    }
  }
  pwVar1 = L"NULL";
LAB_140003226:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== WPP_SF_DZ @ 14000329c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400032d6;
    }
  }
  pwVar1 = L"NULL";
LAB_1400032d6:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,param_5,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_DZsq @ 140003338 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DZsq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                wchar_t *param_5,char *param_6,undefined1 param_7)

{
  wchar_t wVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  undefined4 local_res20 [2];
  
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar4 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400033aa;
    }
  }
  pwVar4 = L"NULL";
LAB_1400033aa:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,0x19,local_res20,4,
             param_5,2,pwVar4,wVar1,param_6,lVar3,&param_7,8,0);
  return;
}



===== WPP_SF_Z @ 140003444 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140003471;
    }
  }
  pwVar1 = L"NULL";
LAB_140003471:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_ZZ @ 1400034c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  
  pwVar3 = L"NULL";
  wVar2 = L'\b';
  if (param_5 == (wchar_t *)0x0) {
    wVar4 = L'\b';
  }
  else {
    wVar4 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_140003511;
    }
  }
  pwVar1 = L"NULL";
LAB_140003511:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  if ((param_4 != (wchar_t *)0x0) && (wVar2 = *param_4, *param_4 != L'\0')) {
    pwVar3 = *(wchar_t **)(param_4 + 4);
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,param_4,2,pwVar3,wVar2,param_5,2,pwVar1,wVar4,0);
  return;
}



===== WPP_SF_qZs @ 1400035a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,char *param_6)

{
  wchar_t wVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  undefined8 local_res20;
  
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar4 = *(wchar_t **)(param_5 + 4);
      goto LAB_140003613;
    }
  }
  pwVar4 = L"NULL";
LAB_140003613:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,0x18,&local_res20,8,
             param_5,2,pwVar4,wVar1,param_6,lVar3,0);
  return;
}



===== DfscCmGetSysvolNetlogonReferralState @ 1400036a0 =====

undefined4 DfscCmGetSysvolNetlogonReferralState(longlong param_1)

{
  ushort *puVar1;
  ushort uVar2;
  RPC_STATUS RVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  ushort uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  ulonglong local_res8;
  undefined8 local_res10;
  ushort local_38 [4];
  longlong local_30;
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  uVar8 = 9;
  local_res8 = 0;
  uVar4 = 0;
  local_res10 = 0;
  if ((param_1 == 0) || (2 < *(int *)(param_1 + 0x124) - 2U)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
    }
    *(undefined4 *)(param_1 + 0x144) = 1;
    local_30 = ExAllocatePool2(0x102,0x208,0x4d436644);
    if (local_30 == 0) {
      RVar3 = -0x3fffff66;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
    }
    else {
      local_38[1] = 0x208;
      RVar3 = DfscGetDCName(param_1 + 0x70,local_38,0x210);
      if (-1 < RVar3) {
        puVar1 = (ushort *)(param_1 + 0xd0);
        *(undefined2 *)(param_1 + 0xe2) = 0;
        RtlInitUnicodeString(puVar1,0);
        uVar4 = DfscRmGenerateSysvolNetlogonReferral(param_1 + 0x70,local_38,0,&local_res8);
        if ((int)uVar4 < 0) {
          RVar3 = 0;
          uVar4 = local_res8;
          uVar8 = 1;
        }
        else {
          uVar2 = *(ushort *)(param_1 + 0xa0);
          uVar7 = *(short *)(param_1 + 0x60) - uVar2;
          *(ushort *)(param_1 + 0xe2) = uVar2;
          *(ushort *)(param_1 + 0xd2) = uVar7;
          *puVar1 = uVar7;
          if (uVar7 == 0) {
            lVar5 = 0;
          }
          else {
            lVar5 = (ulonglong)uVar2 + *(longlong *)(param_1 + 0x68);
          }
          *(longlong *)(param_1 + 0xd8) = lVar5;
          uVar2 = *(ushort *)(param_1 + 0xe0);
          if (uVar7 < uVar2) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
              WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                        &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,(uint)uVar2,(char)uVar7);
            }
            *(ushort *)(param_1 + 0xe0) = *puVar1;
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                      &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,(uint)uVar2,(char)uVar7);
          }
          uVar9 = 9;
          if (*(int *)(param_1 + 0x124) != 1) {
            uVar9 = 5;
          }
          uVar4 = DfscRefCacheStore(*(longlong *)(param_1 + 0xf8),0,local_res8);
          uVar6 = DfscRmCreateRefContext(uVar4,'\0',&local_res10);
          RVar3 = (RPC_STATUS)uVar6;
          if (-1 < RVar3) {
            if (*(longlong *)(param_1 + 0x110) != 0) {
              DfscReferralRelease(*(longlong *)(param_1 + 0x110));
            }
            *(undefined8 *)(param_1 + 0x110) = local_res10;
            uVar8 = uVar9;
          }
        }
      }
    }
    *(RPC_STATUS *)(param_1 + 0x13c) = RVar3;
    if (local_30 != 0) {
      ExFreePoolWithTag(local_30,0);
    }
    if ((RVar3 < 0) && (uVar4 != 0)) {
      DfscRmDereferenceReferral(uVar4);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
    }
    *(undefined4 *)(param_1 + 0x13c) = 0xc00000be;
  }
  return uVar8;
}



===== WPP_SF_qq @ 140003994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== DfscValidateSysvolNetlogonReferral @ 1400039e4 =====

int DfscValidateSysvolNetlogonReferral(longlong param_1,longlong *param_2,undefined8 *param_3)

{
  ushort uVar1;
  longlong lVar2;
  RPC_STATUS RVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ushort uVar7;
  ushort *puVar8;
  char local_res10 [16];
  ulonglong local_res20;
  undefined8 local_58;
  undefined8 local_50;
  longlong lStack_48;
  
  local_res10[0] = '\0';
  local_res20 = 0;
  local_58 = 0;
  local_50 = 0;
  lStack_48 = 0;
  lVar4 = 0;
  RtlInitUnicodeString(&local_50,0);
  lVar2 = *param_2;
  if ((*(char *)(*(longlong *)(lVar2 + 0x10) + 0x12) == '\0') || ((*(uint *)(lVar2 + 8) & 8) != 0))
  {
LAB_140003a6b:
    if (local_res10[0] == '\0') {
      *(undefined1 *)(*(longlong *)(lVar2 + 0x10) + 0x12) = 0;
      goto LAB_140003a80;
    }
LAB_140003ae5:
    if (local_res10[0] != '\0') goto LAB_140003aea;
    puVar8 = (ushort *)&local_50;
  }
  else {
    lVar4 = DfscReferralGetPrimaryTarget(lVar2);
    RVar3 = DfscIsDomainController(param_1 + 0x68,lVar4 + 0x10,local_res10);
    if (-1 < RVar3) goto LAB_140003a6b;
LAB_140003a80:
    if (local_res10[0] == '\0') {
      lStack_48 = ExAllocatePool2(0x102,0x208,0x4d436644);
      uVar5 = 0;
      if (lStack_48 == 0) {
        RVar3 = -0x3fffff66;
        goto LAB_140003c13;
      }
      local_50 = CONCAT44(local_50._4_4_,0x2080000);
      RVar3 = DfscGetDCName(param_1 + 0x68,&local_50,0x210);
      if (RVar3 < 0) goto LAB_140003c13;
      goto LAB_140003ae5;
    }
LAB_140003aea:
    puVar8 = (ushort *)(lVar4 + 0x10);
  }
  uVar5 = DfscRmGenerateSysvolNetlogonReferral(param_1 + 0x68,puVar8,local_res10[0],&local_res20);
  RVar3 = (RPC_STATUS)uVar5;
  if (RVar3 == 0) {
    uVar1 = *(ushort *)(param_1 + 0x98);
    uVar7 = *(short *)(param_1 + 0x58) - uVar1;
    *(ushort *)(param_1 + 0xda) = uVar1;
    *(ushort *)(param_1 + 0xca) = uVar7;
    *(ushort *)(param_1 + 200) = uVar7;
    if (uVar7 == 0) {
      lVar4 = 0;
    }
    else {
      lVar4 = (ulonglong)uVar1 + *(longlong *)(param_1 + 0x60);
    }
    *(longlong *)(param_1 + 0xd0) = lVar4;
    uVar1 = *(ushort *)(param_1 + 0xd8);
    if (uVar7 < uVar1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,(uint)uVar1,(char)uVar7);
      }
      *(undefined2 *)(param_1 + 0xd8) = *(undefined2 *)(param_1 + 200);
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,(uint)uVar1,(char)uVar7);
    }
    uVar5 = DfscRefCacheStore(*(longlong *)(param_1 + 0xf0),*(ulonglong *)(lVar2 + 0x10),local_res20
                             );
    uVar6 = DfscRmCreateRefContext(uVar5,'\0',&local_58);
    RVar3 = (RPC_STATUS)uVar6;
    if ((-1 < RVar3) && (param_3 != (undefined8 *)0x0)) {
      *param_3 = local_58;
    }
  }
  else {
    uVar5 = local_res20;
  }
LAB_140003c13:
  if (lStack_48 != 0) {
    ExFreePoolWithTag(lStack_48,0);
  }
  if ((RVar3 < 0) && (uVar5 != 0)) {
    DfscRmDereferenceReferral(uVar5);
  }
  return RVar3;
}



===== WPP_SF_S @ 140003c5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar1,0);
  return;
}



===== DfscGetIpcConnectionSmbProtocolVersion @ 140003ccc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscGetIpcConnectionSmbProtocolVersion(longlong param_1,ushort *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStackY_e8 [32];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [8];
  ushort local_a0;
  undefined2 local_9e;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  memset(local_a8,0,0x74);
  puVar2 = local_a8;
  local_b8 = 0;
  uStack_b0 = 0;
  iVar1 = ZwQueryInformationFile(*(undefined8 *)(param_1 + 0x28),&local_b8,puVar2,0x74);
  if (-1 < iVar1) {
    *param_2 = local_a0;
    *param_3 = local_9e;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_Ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*param_2,puVar2,iVar1,
               (char)*param_2,(char)*param_3);
  }
  return iVar1;
}



===== WPP_SF_Ddd @ 140003da4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_d29483b364bf358e773d59db54935b3a_Traceguids,0xc,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_ZsZq @ 140003e08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZsZq(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
                char *param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  
  pwVar3 = L"NULL";
  if (param_6 == (wchar_t *)0x0) {
    wVar5 = L'\b';
  }
  else {
    wVar5 = *param_6;
    if (*param_6 != L'\0') {
      pwVar4 = *(wchar_t **)(param_6 + 4);
      goto LAB_140003e5f;
    }
  }
  pwVar4 = L"NULL";
LAB_140003e5f:
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"\b";
  }
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  if (param_4 == (wchar_t *)0x0) {
    wVar6 = L'\b';
  }
  else {
    wVar6 = *param_4;
    if (*param_4 != L'\0') {
      pwVar3 = *(wchar_t **)(param_4 + 4);
    }
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,0x15,param_4,2,pwVar3,
             wVar6,param_5,lVar2,param_6,2,pwVar4,wVar5,&param_7,8,0);
  return;
}



===== WPP_SF_s @ 140003f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,0x13,param_4,lVar2,0);
  return;
}



===== WPP_SF_dDDZ @ 140003fbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,wchar_t *param_7)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined4 local_res20 [2];
  
  if (param_7 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_7;
    if (*param_7 != L'\0') {
      pwVar1 = *(wchar_t **)(param_7 + 4);
      goto LAB_140003ff9;
    }
  }
  pwVar1 = L"NULL";
LAB_140003ff9:
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,pwVar2,2,pwVar1,wVar3,
             0);
  return;
}



===== WPP_SF_dqZdDDd @ 140004084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqZdDDd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar1 = *(wchar_t **)(param_6 + 4);
      goto LAB_1400040c5;
    }
  }
  pwVar1 = L"NULL";
LAB_1400040c5:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,pwVar2,2,pwVar1,wVar3,&param_7,4,
             &param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_SF_dsZ @ 1400041a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dsZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               char *param_5,wchar_t *param_6)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  undefined4 local_res20 [2];
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar4 = *(wchar_t **)(param_6 + 4);
      goto LAB_1400041e9;
    }
  }
  pwVar4 = L"NULL";
LAB_1400041e9:
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"\b";
  }
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,0x10,local_res20,4,
             param_5,lVar2,param_6,2,pwVar4,wVar3,0);
  return;
}



===== WPP_SF_Dd @ 140004294 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,0x14,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_qDSS @ 1400042ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDSS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,wchar_t *param_6,wchar_t *param_7)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined8 local_res20;
  
  lVar1 = -1;
  if (param_7 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_7[lVar2] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  pwVar3 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  if (param_6 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar4 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar4 = L"NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,10,&local_res20,8,
             &param_5,4,pwVar4,lVar1,pwVar3,lVar2,0);
  return;
}



===== WPP_SF_qqd @ 1400043e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,0x18,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 140004450 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140004484 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000c86f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 1400044ac =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004600 =====

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



===== RtlStringCbCopyW @ 140004684 =====

uint RtlStringCbCopyW(short *param_1)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = 0x19;
  lVar4 = (longlong)L"\\??\\X:" - (longlong)param_1;
  do {
    if ((lVar3 == -0x7fffffe5) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0))
    break;
    *param_1 = sVar1;
    param_1 = param_1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  psVar2 = param_1 + -1;
  if (lVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(lVar3 != 0) & 0x80000005;
}



===== RtlStringCbPrintfW @ 1400046dc =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== WPP_SF_SD @ 140004758 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,0x16,param_4,lVar1,
             &param_5,4,0);
  return;
}



===== WPP_SF_ZD @ 1400047e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
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
      goto LAB_140004810;
    }
  }
  pwVar2 = L"NULL";
LAB_140004810:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,0x1d,param_4,2,pwVar2,
             wVar1,&param_5,4,0);
  return;
}



===== WPP_SF_ZZD @ 140004880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZZD(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
               wchar_t *param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  
  pwVar2 = L"NULL";
  wVar4 = L'\b';
  if (param_5 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400048cc;
    }
  }
  pwVar1 = L"NULL";
LAB_1400048cc:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  if ((param_4 != (wchar_t *)0x0) && (wVar4 = *param_4, *param_4 != L'\0')) {
    pwVar2 = *(wchar_t **)(param_4 + 4);
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,param_2,param_4,2,pwVar2,
             wVar4,param_5,2,pwVar1,wVar3,&param_6,4,0);
  return;
}



===== WPP_SF_ZsZ @ 14000497c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZsZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               char *param_5,wchar_t *param_6)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t wVar6;
  
  pwVar4 = L"NULL";
  wVar6 = L'\b';
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar5 = *(wchar_t **)(param_6 + 4);
      goto LAB_1400049d5;
    }
  }
  pwVar5 = L"NULL";
LAB_1400049d5:
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"\b";
  }
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  if ((param_4 != (wchar_t *)0x0) && (wVar6 = *param_4, *param_4 != L'\0')) {
    pwVar4 = *(wchar_t **)(param_4 + 4);
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,0x1c,param_4,2,pwVar4,
             wVar6,param_5,lVar2,param_6,2,pwVar5,wVar3,0);
  return;
}



===== WPP_SF_l @ 140004aa8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_l(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,0x1f,local_res20,4,0);
  return;
}



===== DfscFsctrlGetUseInfo @ 140004af4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DfscFsctrlGetUseInfo
                    (longlong param_1,wint_t *param_2,uint param_3,ushort *param_4,uint *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  short sVar3;
  ulonglong uVar4;
  undefined1 auStackY_98 [32];
  wchar_t local_68;
  undefined1 auStack_66 [6];
  wint_t *pwStack_60;
  longlong local_58;
  wint_t local_50 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  _local_68 = 0;
  pwStack_60 = (wint_t *)0x0;
  local_58 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,param_3);
  }
  if (((((param_3 < 2) || ((param_3 & 1) != 0)) || (0xfffe < param_3)) ||
      ((param_2 == (wint_t *)0x0 || (param_4 == (ushort *)0x0)))) || (*param_2 == 0)) {
    uVar4 = 0xc000000d;
  }
  else if (*param_5 < 4) {
    uVar4 = 0xc0000023;
  }
  else {
    if (((*param_2 == 0x5c) || (param_3 < 3)) || (param_2[1] != 0x3a)) {
      sVar3 = (short)param_3;
      _local_68 = CONCAT62(CONCAT42(auStack_66._2_4_,sVar3),sVar3);
      pwStack_60 = param_2;
      if (*(short *)((longlong)param_2 + (((ulonglong)param_3 & 0xfffe) - 2)) == 0x5c) {
        _local_68 = CONCAT62(CONCAT42(auStack_66._2_4_,sVar3),sVar3 + -2);
      }
    }
    else {
      uVar2 = DfscGetNormalizedDriveLetterUnicodeString(param_2,param_3,local_50,&local_68);
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 != 0) goto LAB_140004c36;
    }
    uVar1 = DfscGetContainerContextFromIrp(param_1,&local_58);
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = DfscGetUseInfo(local_58,param_1,&local_68,param_4,param_5);
      uVar4 = (ulonglong)uVar1;
    }
  }
LAB_140004c36:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,(int)uVar4,(char)*param_5);
  }
  return uVar4;
}



===== DfscFsctrlSqmGetData @ 140004c94 =====

undefined8
DfscFsctrlSqmGetData(longlong param_1,char *param_2,uint param_3,undefined2 *param_4,uint param_5)

{
  if ((((param_2 == (char *)0x0) || (param_3 < 4)) || (param_4 == (undefined2 *)0x0)) ||
     (param_5 < 2)) {
    return 0xc000000d;
  }
  *param_4 = DAT_14000d7ac;
  *(undefined8 *)(param_1 + 0x38) = 2;
  if (*param_2 != '\0') {
    DAT_14000d7ac = 0;
  }
  return 0;
}



===== DfscFsctrlSqmGetReg @ 140004ce0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DfscFsctrlSqmGetReg(longlong param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  
  uVar1 = _DAT_14000d788;
  if ((param_2 == (undefined8 *)0x0) || (param_3 < 0x2c)) {
    return 0xc000000d;
  }
  *param_2 = _DAT_14000d780;
  param_2[1] = uVar1;
  uVar1 = _DAT_14000d798;
  param_2[2] = _DAT_14000d790;
  param_2[3] = uVar1;
  param_2[4] = _DAT_14000d7a0;
  *(undefined4 *)(param_2 + 5) = DAT_14000d7a8;
  *(undefined8 *)(param_1 + 0x38) = 0x2c;
  return 0;
}



===== WPP_SF_DS @ 140004d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              wchar_t *param_5)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  
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
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,0x1d,local_res20,4,
             param_5,lVar1,0);
  return;
}



===== WPP_SF_DZDD @ 140004dc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DZDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                wchar_t *param_5,undefined1 param_6,undefined1 param_7)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar2 = *(wchar_t **)(param_5 + 4);
      goto LAB_140004e02;
    }
  }
  pwVar2 = L"NULL";
LAB_140004e02:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,0x1a,local_res20,4,
             param_5,2,pwVar2,wVar1,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_Dq @ 140004e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,0x36,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_Zq @ 140004ef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zq(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140004f22;
    }
  }
  pwVar1 = L"NULL";
LAB_140004f22:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,8,0);
  return;
}



===== WPP_SF_dD @ 140004f84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,0xb,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_ddd @ 140004fdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,0x1f,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_h @ 140005040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_h(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined2 local_res20 [4];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,0x1e,local_res20,2,0);
  return;
}



===== WPP_SF_qS @ 14000508c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  longlong lVar1;
  undefined8 local_res20;
  
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
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,param_5,lVar1,0);
  return;
}



===== DfscFindEa @ 14000511c =====

uint * DfscFindEa(uint *param_1)

{
  int iVar1;
  
  while( true ) {
    if (param_1 == (uint *)0x0) {
      return (uint *)0x0;
    }
    if ((*(char *)((longlong)param_1 + 5) == '\r') &&
       (iVar1 = strncmp((char *)(param_1 + 2),"TransportInfo",0xd), iVar1 == 0)) break;
    if (*param_1 == 0) {
      return (uint *)0x0;
    }
    param_1 = (uint *)((longlong)param_1 + (ulonglong)*param_1);
  }
  return param_1;
}



===== DfscTransportConflictDetect @ 140005170 =====

undefined4 DfscTransportConflictDetect(longlong param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 == (uint *)0x0) {
    uVar3 = 0;
  }
  else {
    puVar2 = DfscFindEa((uint *)((ulonglong)*param_2 + (longlong)param_2));
    if ((puVar2 != (uint *)0x0) && (*(short *)((longlong)puVar2 + 6) == 0x10)) {
      iVar1 = *(int *)((ulonglong)*(byte *)((longlong)puVar2 + 5) + 9 + (longlong)puVar2);
      if (iVar1 != 0) {
        if (iVar1 == *(int *)(param_1 + 0x98)) {
          uVar3 = 0;
          if (*(char *)((ulonglong)*(byte *)((longlong)puVar2 + 5) + 0xd + (longlong)puVar2) !=
              *(char *)(param_1 + 0x9c)) {
            uVar3 = 0xc00001b5;
          }
        }
        else {
          uVar3 = 0xc00001b4;
        }
      }
    }
  }
  return uVar3;
}



===== WPP_SF_dSZ @ 1400051e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dSZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               wchar_t *param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_6;
    if (*param_6 != L'\0') {
      pwVar3 = *(wchar_t **)(param_6 + 4);
      goto LAB_14000522c;
    }
  }
  pwVar3 = L"NULL";
LAB_14000522c:
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"\b";
  }
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
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,0x17,local_res20,4,
             param_5,lVar1,param_6,2,pwVar3,wVar2,0);
  return;
}



===== WPP_SF_qZD @ 1400052d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_140005311;
    }
  }
  pwVar1 = L"NULL";
LAB_140005311:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,10,&local_res20,8,param_5
             ,2,pwVar1,wVar2,&param_6,4,0);
  return;
}



===== WPP_SF_qZq @ 140005398 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400053d4;
    }
  }
  pwVar1 = L"NULL";
LAB_1400053d4:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,param_2,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,0);
  return;
}



===== WPP_SF_qZqD @ 140005450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                wchar_t *param_5,undefined1 param_6,undefined1 param_7)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_14000548f;
    }
  }
  pwVar1 = L"NULL";
LAB_14000548f:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,0xc,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qdd @ 140005528 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qdq @ 140005590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,0x16,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_dDDd @ 1400055f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dqZq @ 140005668 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqZq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,wchar_t *param_6,undefined1 param_7)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar1 = *(wchar_t **)(param_6 + 4);
      goto LAB_1400056a7;
    }
  }
  pwVar1 = L"NULL";
LAB_1400056a7:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,param_2,local_res20,4,
             &param_5,8,pwVar2,2,pwVar1,wVar3,&param_7,8,0);
  return;
}



===== WPP_SF_SS @ 14000573c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *in_stack_00000028;
  
  if (in_stack_00000028 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_55706db06074317498eaf8c01331c814_Traceguids,0x17,L"ROOT_REF",0x12,
             in_stack_00000028,lVar1,0);
  return;
}



===== WPP_SF_qZZ @ 1400057d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,wchar_t *param_6)

{
  wchar_t wVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined8 local_res20;
  
  pwVar3 = L"NULL";
  if (param_6 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_6;
    if (*param_6 != L'\0') {
      pwVar4 = *(wchar_t **)(param_6 + 4);
      goto LAB_14000582a;
    }
  }
  pwVar4 = L"NULL";
LAB_14000582a:
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"\b";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar3 = *(wchar_t **)(param_5 + 4);
    }
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_55706db06074317498eaf8c01331c814_Traceguids,0x14,&local_res20,8,
             param_5,2,pwVar3,wVar1,param_6,2,pwVar4,wVar2,0);
  return;
}



===== WPP_SF_qqDZ @ 1400058dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,wchar_t *param_7)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined8 local_res20;
  
  if (param_7 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_7;
    if (*param_7 != L'\0') {
      pwVar1 = *(wchar_t **)(param_7 + 4);
      goto LAB_14000591b;
    }
  }
  pwVar1 = L"NULL";
LAB_14000591b:
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_55706db06074317498eaf8c01331c814_Traceguids,0x16,&local_res20,8,
             &param_5,8,&param_6,4,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== DfscRmGenerateClusterSetReferralFromName @ 1400059b0 =====

ulonglong DfscRmGenerateClusterSetReferralFromName
                    (ushort *param_1,wchar_t *param_2,undefined8 *param_3)

{
  wchar_t wVar1;
  undefined2 *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t local_38;
  short local_36;
  undefined4 local_34;
  void *local_30;
  
  local_34 = 0;
  puVar2 = DfscRmAllocateReferral((uint)(ushort)*param_2 + *param_1 + 0x114,0x72436644);
  if (puVar2 == (undefined2 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    *(undefined4 *)(puVar2 + 0x14) = 0xffffffff;
    *(undefined1 *)(puVar2 + 9) = 0;
    *(undefined4 *)(puVar2 + 0xe) = 1;
    puVar2[8] = puVar2[8] & 0xfff7;
    *(undefined2 *)((longlong)puVar2 + 0x13) = 0x100;
    *(undefined2 **)(puVar2 + 0x4c) = puVar2 + 0x88;
    puVar2[0x49] = *param_1 + 2;
    RtlCopyUnicodeString(puVar2 + 0x48,param_1);
    _Dst = (void *)((ulonglong)(ushort)puVar2[0x49] + *(longlong *)(puVar2 + 0x4c));
    wVar1 = *param_2;
    memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)(ushort)wVar1);
    *(undefined2 *)((longlong)_Dst + (ulonglong)((ushort)wVar1 >> 1) * 2) = 0;
    local_36 = wVar1 + L'\x02';
    local_38 = wVar1;
    local_30 = _Dst;
    uVar3 = DfscInitDfsPath(&local_38,puVar2 + 0x58);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      DfscRmDereferenceReferral((longlong)puVar2);
    }
    else {
      *(undefined4 *)(puVar2 + 0x54) = 0;
      *(undefined4 *)(puVar2 + 6) = 1;
      *(undefined8 *)(puVar2 + 0x40) = *(undefined8 *)(puVar2 + 0x48);
      *(undefined8 *)(puVar2 + 0x44) = *(undefined8 *)(puVar2 + 0x4c);
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar2;
      }
    }
  }
  return uVar4;
}



===== Feature_102208826__private_IsEnabledDeviceUsageNoInline @ 140005b04 =====

ulonglong Feature_102208826__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_102208826__private_featureState;
  if ((Feature_102208826__private_featureState & 0x10) == 0) {
    uVar1 = Feature_102208826__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_102208826__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_102208826__private_IsEnabledFallback @ 140005b3c =====

void Feature_102208826__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_102208826__private_descriptor);
  return;
}



===== Feature_170808633__private_IsEnabledDeviceUsageNoInline @ 140005b58 =====

ulonglong Feature_170808633__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_170808633__private_featureState;
  if ((Feature_170808633__private_featureState & 0x10) == 0) {
    uVar1 = Feature_170808633__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_170808633__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_170808633__private_IsEnabledFallback @ 140005b90 =====

void Feature_170808633__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_170808633__private_descriptor);
  return;
}



===== Feature_468612410__private_IsEnabledDeviceUsageNoInline @ 140005bac =====

ulonglong Feature_468612410__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_468612410__private_featureState;
  if ((Feature_468612410__private_featureState & 0x10) == 0) {
    uVar1 = Feature_468612410__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_468612410__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_468612410__private_IsEnabledFallback @ 140005be4 =====

void Feature_468612410__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_468612410__private_descriptor);
  return;
}



===== WPP_SF_Dqq @ 140005c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_af603b4b97893b05877342047baf7746_Traceguids,0x21,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== DfscRmCheckReferralTargetAddressSyntax @ 140005c68 =====

ulonglong DfscRmCheckReferralTargetAddressSyntax(short *param_1,uint param_2)

{
  ulonglong in_RAX;
  uint uVar1;
  ulonglong uVar2;
  short *psVar3;
  
  if (((4 < param_2) && (*param_1 == 0x5c)) && (param_1[1] != 0x5c)) {
    uVar2 = 2;
    psVar3 = param_1 + 2;
    in_RAX = in_RAX & 0xffffffffffffff00;
    do {
      if ((char)in_RAX != '\0') goto LAB_140005cb1;
      in_RAX = in_RAX & 0xff;
      if (*psVar3 == 0x5c) {
        in_RAX = 1;
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
      psVar3 = psVar3 + 1;
    } while (uVar1 < param_2);
    if ((char)in_RAX != '\0') {
LAB_140005cb1:
      if ((((uint)uVar2 != param_2) && (param_1[uVar2] != 0x5c)) && (param_1[uVar2] != 0)) {
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== DfscTearDownTimer @ 140005cd4 =====

void DfscTearDownTimer(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (DAT_14000d794 != 0) {
    KeInitializeEvent(&local_28,0,0);
    uVar1 = KeAcquireSpinLockRaiseToDpc(&g_DfscTimerSpinLock);
    g_DfscTimerCompleteEvent = &local_28;
    g_DfscTimerSet = 0;
    KeReleaseSpinLock(&g_DfscTimerSpinLock,uVar1);
    cVar2 = KeCancelTimer(&g_DfscTimer);
    uVar1 = KeAcquireSpinLockRaiseToDpc(&g_DfscTimerSpinLock);
    if ((cVar2 == '\0') || (g_DfscTimerPosted != '\0')) {
      KeReleaseSpinLock(&g_DfscTimerSpinLock,uVar1);
      KeWaitForSingleObject(g_DfscTimerCompleteEvent,0,0,0,0);
    }
    else {
      KeReleaseSpinLock(&g_DfscTimerSpinLock,uVar1);
    }
    g_DfscTimerCompleteEvent = (undefined8 *)0x0;
  }
  if (g_DfscTimerWorkItem != 0) {
    IoFreeWorkItem();
    g_DfscTimerWorkItem = 0;
  }
  return;
}



===== DfscCredDelete @ 140005dfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscCredDelete(void)

{
  int iVar1;
  RPC_STATUS RVar2;
  undefined1 auStack_e8 [32];
  RPC_BINDING_HANDLE local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  _RPC_ASYNC_STATE local_78;
  
  local_78.Reserved[2] = __security_cookie ^ (ulonglong)auStack_e8;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  memset(&local_78,0,0x58);
  local_a0 = (RPC_BINDING_HANDLE)0x0;
  local_98 = 0;
  iVar1 = DfscRpcConnect(&local_a0);
  if (iVar1 == 0) {
    KeInitializeEvent(&local_90,0,0);
    iVar1 = RpcAsyncInitializeHandle(&local_78,0x58);
    if (iVar1 == 0) {
      local_78.NotificationType = RpcNotificationTypeEvent;
      local_78.u.APC.NotificationRoutine = (PFN_RPCNOTIFICATION_ROUTINE)&local_90;
      Ndr64AsyncClientCall((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140009000,3,(void *)0x0);
      KeWaitForSingleObject(&local_90,0,0,0);
      RVar2 = RpcAsyncCompleteCall(&local_78,(void *)0x0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,RVar2,0);
      }
      iVar1 = 0;
      if (RVar2 != 0) {
        iVar1 = -0x3fffffde;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,iVar1);
    }
    RpcBindingUnbind(local_a0);
    local_98 = 1;
    RpcBindingFree(&local_a0);
  }
  return iVar1;
}



===== DfscCredWrite @ 140006094 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscCredWrite(void)

{
  int iVar1;
  RPC_STATUS RVar2;
  undefined1 auStack_f8 [32];
  RPC_BINDING_HANDLE local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  _RPC_ASYNC_STATE local_88;
  
  local_88.Reserved[2] = __security_cookie ^ (ulonglong)auStack_f8;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  memset(&local_88,0,0x58);
  local_b0 = (RPC_BINDING_HANDLE)0x0;
  local_a8 = 0;
  iVar1 = DfscRpcConnect(&local_b0);
  if (iVar1 == 0) {
    KeInitializeEvent(&local_a0,0,0);
    iVar1 = RpcAsyncInitializeHandle(&local_88,0x58);
    if (iVar1 == 0) {
      local_88.NotificationType = RpcNotificationTypeEvent;
      local_88.u.APC.NotificationRoutine = (PFN_RPCNOTIFICATION_ROUTINE)&local_a0;
      Ndr64AsyncClientCall((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140009000,2,(void *)0x0);
      KeWaitForSingleObject(&local_a0,0,0,0);
      RVar2 = RpcAsyncCompleteCall(&local_88,(void *)0x0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,RVar2,0);
      }
      iVar1 = 0;
      if (RVar2 != 0) {
        iVar1 = -0x3fffffde;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,iVar1);
    }
    RpcBindingUnbind(local_b0);
    local_a8 = 1;
    RpcBindingFree(&local_b0);
  }
  return iVar1;
}



===== DfscIsDomainController @ 140006330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

RPC_STATUS DfscIsDomainController(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  RPC_STATUS RVar2;
  undefined1 auStack_f8 [32];
  RPC_BINDING_HANDLE local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  int local_b8;
  RPC_BINDING_HANDLE local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  _RPC_ASYNC_STATE local_88;
  
  local_88.Reserved[2] = __security_cookie ^ (ulonglong)auStack_f8;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  memset(&local_88,0,0x58);
  local_b0 = (RPC_BINDING_HANDLE)0x0;
  local_a8 = 0;
  iVar1 = DfscRpcConnect(&local_b0);
  if (iVar1 == 0) {
    KeInitializeEvent(&local_a0,0,0);
    iVar1 = RpcAsyncInitializeHandle(&local_88,0x58);
    local_b8 = iVar1;
    if (iVar1 == 0) {
      local_88.NotificationType = RpcNotificationTypeEvent;
      local_88.u.APC.NotificationRoutine = (PFN_RPCNOTIFICATION_ROUTINE)&local_a0;
      local_d8 = local_b0;
      local_d0 = param_1;
      local_c8 = param_2;
      local_c0 = param_3;
      Ndr64AsyncClientCall((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140009000,1,(void *)0x0);
      local_d8 = (RPC_BINDING_HANDLE)0x0;
      KeWaitForSingleObject(&local_a0,0,0,0);
      RVar2 = RpcAsyncCompleteCall(&local_88,(void *)0x0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                 &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,RVar2);
      }
      iVar1 = 0;
      if (RVar2 != 0) {
        iVar1 = -0x3fffffde;
      }
      local_b8 = iVar1;
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_647e9e2fa1ea3758e828fdefd6c76ce6_Traceguids,iVar1);
    }
    RpcBindingUnbind(local_b0);
    local_a8 = 1;
    RpcBindingFree(&local_b0);
  }
  return iVar1;
}



===== MIDL_user_allocate @ 1400065d0 =====

void * __stdcall MIDL_user_allocate(size_t size)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x102,size,0x4e436644);
  return pvVar1;
}



===== MIDL_user_free @ 140006600 =====

void __stdcall MIDL_user_free(void *param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== _guard_check_icall @ 140006630 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140006648 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000666c =====

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



===== __GSHandlerCheck_SEH @ 1400066d4 =====

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



===== strcmp @ 140006766 =====

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140006766. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 140006780 =====

/* WARNING: Removing unreachable block (ram,0x0001400067ea) */
/* WARNING: Removing unreachable block (ram,0x000140006799) */
/* WARNING: Removing unreachable block (ram,0x00014000678a) */

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



===== __security_check_cookie @ 140006850 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140006890 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400068c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400068c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400068f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140006940 =====

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



===== memset @ 140006c40 =====

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



===== __memset_repmovs @ 140006d80 =====

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



===== __memset_query @ 140006e00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006e80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006fc0 =====

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



===== __memset_spec_plain @ 140007040 =====

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



===== DfscGetDCName$filt$0 @ 14000713d =====

void DfscGetDCName_filt_0(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== DfscGetDCName$filt$1 @ 14000715f =====

void DfscGetDCName_filt_1(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== DfscRpcConnect$filt$0 @ 140007187 =====

void DfscRpcConnect_filt_0(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== DfscCredDelete$filt$0 @ 1400071af =====

void DfscCredDelete_filt_0(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== DfscCredDelete$filt$1 @ 1400071d1 =====

void DfscCredDelete_filt_1(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== DfscRmValidateRootGetParent @ 140012010 =====

int DfscRmValidateRootGetParent(longlong *param_1)

{
  longlong *plVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  iVar3 = 0;
  bVar2 = DfscIsKnownDomainName(*param_1,(ushort *)(*param_1 + 0x68));
  if (!bVar2) {
    iVar4 = 1;
    goto LAB_140012086;
  }
  plVar1 = param_1 + 1;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
  uVar5 = DfscDomainCacheLookup(*param_1,(ushort *)(*param_1 + 0x68),plVar1);
  iVar3 = (int)uVar5;
  if (iVar3 < 0) {
LAB_140012066:
    iVar3 = DfscValidateReferral(*param_1,0,plVar1);
  }
  else {
    uVar6 = DfscReferralIsValid(*plVar1,*(uint *)(*param_1 + 0xe8));
    if ((char)uVar6 == '\0') goto LAB_140012066;
  }
  iVar4 = (iVar3 >> 0x1f & 0xfffffffeU) + 1;
LAB_140012086:
  *(int *)((longlong)param_1 + 0x24) = iVar3;
  return iVar4;
}



===== DfscIsKnownDomainName @ 1400120a0 =====

bool DfscIsKnownDomainName(longlong param_1,ushort *param_2)

{
  undefined8 uVar1;
  bool bVar2;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar1 = DfscDomainCacheLookup(param_1,param_2,local_res18);
  bVar2 = -1 < (int)uVar1;
  if (bVar2) {
    DfscReferralRelease(local_res18[0]);
  }
  return bVar2;
}



===== DfscSetMatchingTarget @ 1400120d8 =====

uint DfscSetMatchingTarget(longlong param_1,longlong param_2,undefined8 param_3)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined2 uVar9;
  uint uVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(param_2 + 0x10);
  if (lVar3 == lVar2) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) == 0) {
      return 0;
    }
    uVar9 = 0x1d;
  }
  else {
    if (*(int *)(lVar3 + 0xc) == *(int *)(lVar2 + 0xc)) {
      if ((*(int *)(lVar2 + 0xc) == 0) && (*(short *)(lVar2 + 0x1c) == 0)) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) == 0) {
          return 0;
        }
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_af603b4b97893b05877342047baf7746_Traceguids,param_1);
        return 0;
      }
      lVar7 = param_2;
      lVar5 = DfscReferralGetPrimaryTarget(param_1);
      uVar10 = ~-(uint)(lVar5 != 0) & 0x8000001a;
      do {
        if (uVar10 != 0) goto LAB_140012333;
        lVar8 = param_2;
        uVar6 = DfscReferralIterate(param_2);
        uVar10 = (uint)uVar6;
        if (uVar10 != 0) {
          if (uVar10 == 0x8000001a) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
              WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                        &WPP_af603b4b97893b05877342047baf7746_Traceguids,param_1,(char)param_2);
            }
            uVar10 = 0xc0000034;
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
            WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar7,param_3,uVar10,(char)param_1
                       ,(char)param_2);
          }
          goto LAB_140012333;
        }
        lVar7 = DfscReferralGetCurrentTarget(lVar8);
        param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
        lVar7 = lVar7 + 0x50;
        iVar4 = RtlCompareUnicodeString(lVar5 + 0x50);
      } while (iVar4 != 0);
      *(undefined2 *)(*(longlong *)(param_2 + 0x10) + 0x1e) = *(undefined2 *)(param_2 + 0x20);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar6 + 0x22,
                 &WPP_af603b4b97893b05877342047baf7746_Traceguids,param_2);
      }
      if ((*(uint *)(param_1 + 8) & 8) == 0) {
        *(undefined1 *)(lVar3 + 0x12) = *(undefined1 *)(lVar2 + 0x12);
      }
      else if ((*(byte *)(lVar2 + 0x10) & 8) != 0) {
        uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x10) + 0x1e);
        *(ushort *)(param_2 + 0x1a) = uVar1;
        *(ushort *)(param_2 + 0x20) = uVar1;
        *(undefined4 *)(param_2 + 0x1c) =
             *(undefined4 *)((ulonglong)uVar1 * 0x70 + 0xa4 + *(longlong *)(param_2 + 0x10));
        if (uVar1 == 0) {
          return 0;
        }
        *(ushort *)(param_2 + 0x18) = *(ushort *)(param_2 + 0x18) & 0xfffe | 4;
        return 0;
      }
LAB_140012333:
      DfscReferralIterateInitialize(param_2);
      return uVar10;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
      return 0;
    }
    uVar9 = 0x1e;
  }
  WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
            &WPP_af603b4b97893b05877342047baf7746_Traceguids,param_2,(char)param_1);
  return 0;
}



===== DfscIsValidDriveLetter @ 140012364 =====

int DfscIsValidDriveLetter(longlong param_1,wchar_t *param_2,longlong param_3)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined8 local_res20;
  wchar_t local_48 [20];
  ulonglong uStack_20;
  
  local_res20 = 0;
  local_48[0] = L'\0';
  local_48[1] = L'\0';
  local_48[2] = L'\0';
  local_48[3] = L'\0';
  local_48[4] = L'\0';
  local_48[5] = L'\0';
  local_48[6] = L'\0';
  local_48[7] = L'\0';
  lVar3 = 0;
  local_48[8] = L'\0';
  local_48[9] = L'\0';
  local_48[10] = L'\0';
  local_48[0xb] = L'\0';
  local_48[0xc] = L'\0';
  local_48[0xd] = L'\0';
  local_48[0xe] = L'\0';
  local_48[0xf] = L'\0';
  bVar1 = false;
  local_48[0x10] = L'\0';
  local_48[0x11] = L'\0';
  local_48[0x12] = L'\0';
  local_48[0x13] = L'\0';
  uStack_20 = 0;
  iVar2 = DfscNetUseGetSearchKey
                    (param_1,(undefined8 *)param_2,param_3,&local_res20,(undefined8 *)local_48);
  puVar5 = &DAT_14000d6e0;
  if (iVar2 == 0) {
    if ((uStack_20 & 1) == 0) {
      iVar2 = -0x3ffffff3;
    }
    else {
      KeEnterCriticalRegion();
      puVar4 = (undefined *)(param_1 + 0x98);
      if (param_1 == 0) {
        puVar4 = &DAT_14000d6e0;
      }
      ExAcquireResourceExclusiveLite(puVar4,1);
      bVar1 = true;
      lVar3 = DfscNetUseTableLookup(local_res20,local_48,0);
      if (lVar3 == 0) {
        iVar2 = -0x3ffffff2;
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
    WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar2,param_2);
  }
  if (bVar1) {
    if (param_1 != 0) {
      puVar5 = (undefined *)(param_1 + 0x98);
    }
    ExReleaseResourceLite(puVar5);
    KeLeaveCriticalRegion();
  }
  if (lVar3 != 0) {
    DfscNetUseRelease(param_1,lVar3,0,'\0');
  }
  return iVar2;
}



===== DfscRmSetReferralType @ 1400124c0 =====

ulonglong DfscRmSetReferralType(longlong param_1,int param_2,int param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_78;
  undefined8 uStack_70;
  ushort local_68 [8];
  short local_58;
  
  memset(&local_78,0,0x60);
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  uVar1 = DfscInitDfsPath((wchar_t *)(param_1 + 0x90),(short *)&local_78);
  uVar3 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    if (local_58 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_SS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
      }
      if (param_2 != 1) {
        uVar3 = 0xc00000be;
      }
      if ((param_3 != 0) && (uVar2 = DfscIsSpecialShare(local_68), (char)uVar2 != '\0')) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                    &WPP_55706db06074317498eaf8c01331c814_Traceguids,(wchar_t *)&local_78,
                    (char)param_1);
        }
        *(undefined8 *)(param_1 + 0x80) = local_78;
        *(undefined8 *)(param_1 + 0x88) = uStack_70;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 2;
    }
  }
  return uVar3;
}



===== DfscRmValidateLinkIterate @ 140012600 =====

undefined8 DfscRmValidateLinkIterate(undefined8 *param_1)

{
  uint uVar1;
  
  uVar1 = DfscIterateAndGetReferral(0,(longlong *)*param_1,2,param_1[1],param_1[3],param_1 + 2);
  *(uint *)((longlong)param_1 + 0x24) = uVar1;
  return 0xffffffff;
}



===== DfscRmGetDomainDcReferral @ 140012644 =====

int DfscRmGetDomainDcReferral
              (ulonglong param_1,ushort *param_2,wchar_t *param_3,longlong param_4,
              undefined8 *param_5)

{
  ushort *puVar1;
  int iVar2;
  ulonglong uVar3;
  uint local_res18 [4];
  ushort *local_28;
  undefined8 local_20;
  
  local_28 = (ushort *)0x0;
  local_20 = 0;
  local_res18[0] = 0;
  if ((((param_3 == (wchar_t *)0x0) || (*param_3 == L'\0')) ||
      (*(short **)(param_3 + 4) == (short *)0x0)) || (**(short **)(param_3 + 4) == 0)) {
    iVar2 = DfscRmGenerateReferral(param_1,param_2,param_4,3,(longlong *)&local_28,local_res18);
  }
  else {
    iVar2 = DfscRmGenerateReferralEx
                      (param_1,param_2,(ushort *)param_3,param_4,3,&local_28,local_res18);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_af603b4b97893b05877342047baf7746_Traceguids,iVar2,param_3);
    }
  }
  puVar1 = local_28;
  if (-1 < iVar2) {
    *local_28 = 0;
    uVar3 = DfscRmGenerateDomainDcReferralFromResponse(param_1,local_28,local_res18[0],&local_20);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      *param_5 = local_20;
    }
  }
  if (puVar1 != (ushort *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_af603b4b97893b05877342047baf7746_Traceguids,puVar1);
    }
    ExFreePoolWithTag(puVar1,0);
  }
  return iVar2;
}



===== DfscGetUlongRegistryParameter @ 1400127a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DfscGetUlongRegistryParameter(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  undefined4 local_88 [4];
  undefined1 local_78 [4];
  int local_74;
  undefined4 local_6c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88[0] = 0;
  local_90 = local_88;
  local_98 = 0x60;
  uVar1 = ZwQueryValueKey(param_1,param_2,2,local_78);
  if (-1 < (int)uVar1) {
    if (local_74 == 4) {
      *param_3 = local_6c;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== DfscGetLinkReferral @ 140012828 =====

uint DfscGetLinkReferral(longlong *param_1,ushort *param_2,longlong param_3,undefined8 *param_4)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  longlong lVar4;
  
  lVar4 = 0;
  uVar2 = DfscRmGetReferral(2,param_1,(wchar_t *)(param_1 + 0x15),param_2,(wchar_t *)0x0,param_3,
                            param_4);
  if (-1 < (int)uVar2) {
    uVar3 = (short)param_1[0xb] - *(ushort *)((longlong)param_1 + 0xda);
    *(ushort *)((longlong)param_1 + 0xca) = uVar3;
    *(ushort *)(param_1 + 0x19) = uVar3;
    if (uVar3 != 0) {
      lVar4 = (ulonglong)*(ushort *)((longlong)param_1 + 0xda) + param_1[0xc];
    }
    param_1[0x1a] = lVar4;
    uVar1 = *(ushort *)(param_1 + 0x1b);
    if (uVar3 < uVar1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar1,(char)uVar3);
      }
      *(short *)(param_1 + 0x1b) = (short)param_1[0x19];
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar1,(char)uVar3);
    }
  }
  return uVar2;
}



===== DfscReferralGetPrimaryTarget @ 140012944 =====

longlong DfscReferralGetPrimaryTarget(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  
  lVar2 = 0;
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x10) + 0x1e);
  if (uVar1 != 0xffff) {
    lVar2 = (ulonglong)uVar1 * 0x70 + 0xa0 + *(longlong *)(param_1 + 0x10);
  }
  return lVar2;
}



===== DfscReferralIterateInitialize @ 140012970 =====

undefined8 DfscReferralIterateInitialize(longlong param_1)

{
  if ((*(uint *)(param_1 + 8) & 6) == 0) {
    *(undefined2 *)(param_1 + 0x20) = 0xffff;
    return 0;
  }
  return 0xc0000008;
}



===== DfscGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities @ 140012990 =====

byte DfscGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities(byte param_1)

{
  if ((param_1 & 4) == 0) {
    return param_1 & 2;
  }
  return 3;
}



===== DfscGetCredTable @ 1400129ac =====

undefined8 DfscGetCredTable(longlong param_1)

{
  if (param_1 == 0) {
    return DAT_14000d6d8;
  }
  return *(undefined8 *)(param_1 + 0x90);
}



===== DfscReleaseTreeConnectionHandle @ 1400129cc =====

void DfscReleaseTreeConnectionHandle(longlong param_1)

{
  if (param_1 != 0) {
    ZwClose();
  }
  return;
}



===== DfscCacheDelete @ 1400129f0 =====

void DfscCacheDelete(longlong param_1,undefined8 param_2,undefined *param_3)

{
  DfscCachePurge(param_1,param_2,param_3);
  ExDeleteResourceLite(param_1 + 0x38);
  ExDeleteResourceLite(param_1 + 0xa0);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== DfscCacheInitialize @ 140012a40 =====

undefined8 DfscCacheInitialize(undefined8 *param_1,char param_2,undefined4 param_3)

{
  longlong lVar1;
  void *_Dst;
  undefined8 uVar2;
  
  *param_1 = 0;
  _Dst = (void *)ExAllocatePool2(0x42,0x108,0x67436644);
  if (_Dst == (void *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,0x108);
    lVar1 = (longlong)_Dst + 0x18;
    *(longlong *)((longlong)_Dst + 0x20) = lVar1;
    *(longlong *)lVar1 = lVar1;
    ExInitializeResourceLite((longlong)_Dst + 0x38);
    ExInitializeResourceLite((longlong)_Dst + 0xa0);
    RtlInitializeUnicodePrefix(_Dst);
    if (param_2 != '\0') {
      *(uint *)((longlong)_Dst + 0x28) = *(uint *)((longlong)_Dst + 0x28) | 1;
    }
    *(undefined4 *)((longlong)_Dst + 0x34) = param_3;
    uVar2 = 0;
    *param_1 = _Dst;
  }
  return uVar2;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140012b08 =====

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



===== DfscCmGetLinkReferralState @ 140012be0 =====

int DfscCmGetLinkReferralState(longlong param_1)

{
  longlong lVar1;
  uint extraout_EAX;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  longlong local_138 [12];
  longlong local_d8;
  ushort local_70 [36];
  
  iVar11 = 9;
  plVar10 = (longlong *)(param_1 + 8);
  lVar8 = 2;
  plVar3 = plVar10;
  plVar7 = local_138;
  do {
    lVar13 = plVar3[1];
    lVar4 = plVar3[2];
    lVar5 = plVar3[3];
    *plVar7 = *plVar3;
    plVar7[1] = lVar13;
    lVar13 = plVar3[4];
    lVar1 = plVar3[5];
    plVar7[2] = lVar4;
    plVar7[3] = lVar5;
    lVar4 = plVar3[6];
    lVar5 = plVar3[7];
    plVar7[4] = lVar13;
    plVar7[5] = lVar1;
    lVar13 = plVar3[8];
    lVar1 = plVar3[9];
    plVar7[6] = lVar4;
    plVar7[7] = lVar5;
    lVar4 = plVar3[10];
    lVar5 = plVar3[0xb];
    plVar7[8] = lVar13;
    plVar7[9] = lVar1;
    lVar13 = plVar3[0xc];
    lVar1 = plVar3[0xd];
    plVar7[10] = lVar4;
    plVar7[0xb] = lVar5;
    lVar4 = plVar3[0xe];
    lVar5 = plVar3[0xf];
    plVar3 = plVar3 + 0x10;
    plVar7[0xc] = lVar13;
    plVar7[0xd] = lVar1;
    plVar9 = plVar7 + 0x10;
    plVar7[0xe] = lVar4;
    plVar7[0xf] = lVar5;
    lVar8 = lVar8 + -1;
    plVar7 = plVar9;
  } while (lVar8 != 0);
  *plVar9 = *plVar3;
  memset((void *)(param_1 + 0x10),0,0x60);
  memset((void *)(param_1 + 0x70),0,0x60);
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined2 *)(param_1 + 0xe2) = 0;
  DfscRewritePath(param_1,(ushort *)(*(longlong *)(param_1 + 0x118) + 0x60),local_70,'\x01');
  uVar2 = extraout_EAX;
  if (extraout_EAX == 0) {
    if (*(int *)(param_1 + 0x124) - 2U < 3) {
      uVar2 = 0xc00000be;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                  &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,0xbe);
      }
    }
    else {
      plVar3 = (longlong *)(param_1 + 0x110);
      lVar8 = *plVar3;
      *plVar3 = 0;
      uVar2 = DfscGetLinkReferral(plVar10,(ushort *)(param_1 + 0x70),0,plVar3);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                  &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)uVar2);
      }
      if (uVar2 == 0) {
        lVar13 = lVar8;
        DfscReferralSetCurrentAccessStatus(lVar8,0);
        lVar4 = DfscReferralGetPrimaryTarget(lVar13);
        lVar13 = lVar8;
        lVar5 = DfscReferralGetCurrentTarget(lVar8);
        if (lVar5 != lVar4) {
          *(undefined2 *)(*(longlong *)(lVar8 + 0x10) + 0x1e) = *(undefined2 *)(lVar8 + 0x20);
        }
        DfscReferralRelease(lVar13);
        iVar11 = 5;
      }
      else {
        uVar6 = DfscIsErrorInList(uVar2,0x14000d110,0x1e);
        if ((char)uVar6 != '\0') {
          DfscReferralSetCurrentAccessStatus(lVar8,uVar2);
          if (*(longlong *)(param_1 + 0x68) != 0) {
            ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0);
          }
          plVar7 = local_138;
          lVar13 = 2;
          do {
            lVar12 = lVar13;
            lVar13 = plVar7[1];
            lVar4 = plVar7[2];
            lVar5 = plVar7[3];
            *plVar10 = *plVar7;
            plVar10[1] = lVar13;
            lVar13 = plVar7[4];
            lVar1 = plVar7[5];
            plVar10[2] = lVar4;
            plVar10[3] = lVar5;
            lVar4 = plVar7[6];
            lVar5 = plVar7[7];
            plVar10[4] = lVar13;
            plVar10[5] = lVar1;
            lVar13 = plVar7[8];
            lVar1 = plVar7[9];
            plVar10[6] = lVar4;
            plVar10[7] = lVar5;
            lVar4 = plVar7[10];
            lVar5 = plVar7[0xb];
            plVar10[8] = lVar13;
            plVar10[9] = lVar1;
            lVar13 = plVar7[0xc];
            lVar1 = plVar7[0xd];
            plVar10[10] = lVar4;
            plVar10[0xb] = lVar5;
            lVar4 = plVar7[0xe];
            lVar5 = plVar7[0xf];
            plVar7 = plVar7 + 0x10;
            plVar10[0xc] = lVar13;
            plVar10[0xd] = lVar1;
            plVar9 = plVar10 + 0x10;
            plVar10[0xe] = lVar4;
            plVar10[0xf] = lVar5;
            lVar13 = lVar12 + -1;
            plVar10 = plVar9;
          } while (lVar13 != 0);
          iVar11 = (int)lVar12 + 4;
          *plVar9 = *plVar7;
          uVar2 = 0xc00000be;
          *plVar3 = lVar8;
          goto LAB_140012e87;
        }
        DfscReferralSetCurrentAccessStatus(lVar8,0);
        DfscReferralRelease(lVar8);
      }
    }
  }
  if (local_d8 != 0) {
    ExFreePoolWithTag(local_d8,0);
  }
LAB_140012e87:
  *(uint *)(param_1 + 0x13c) = uVar2;
  return iVar11;
}



===== DfscRmValidateDomainGetParent @ 140012ec0 =====

undefined8 DfscRmValidateDomainGetParent(void)

{
  return 1;
}



===== DfscRmValidateLinkGetParent @ 140012ed0 =====

int DfscRmValidateLinkGetParent(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  plVar1 = param_1 + 1;
  uVar3 = DfscRefCacheLookup(*param_1,(ushort *)(*param_1 + 0x98),(undefined8 *)0x0,plVar1);
  iVar2 = (int)uVar3;
  if (-1 < iVar2) {
    uVar4 = DfscReferralIsValid(*plVar1,*(uint *)(*param_1 + 0xe8));
    if ((char)uVar4 != '\0') goto LAB_140012f25;
  }
  iVar2 = DfscValidateReferral(*param_1,1,plVar1);
LAB_140012f25:
  *(int *)((longlong)param_1 + 0x24) = iVar2;
  return (iVar2 >> 0x1f & 0xfffffffeU) + 1;
}



===== DfscGetIpcConnectionHandle @ 140012f48 =====

int DfscGetIpcConnectionHandle
              (undefined8 param_1,short *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5)

{
  int iVar1;
  undefined2 local_18;
  short local_16;
  undefined4 local_14;
  longlong local_10;
  
  local_14 = 0;
  local_18 = 0;
  local_16 = *param_2 + 0x28;
  local_10 = ExAllocatePool2(0x102);
  if (local_10 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    RtlAppendUnicodeToString(&local_18,L"\\Device\\Mup");
    RtlAppendUnicodeToString(&local_18,L"\\");
    RtlAppendUnicodeStringToString(&local_18,param_2);
    RtlAppendUnicodeToString(&local_18,L"\\IPC$");
    iVar1 = DfscConnOpenIpcConnection(param_1,&local_18,0,0,param_3,0,param_4,param_5);
    ExFreePoolWithTag(local_10,0);
  }
  return iVar1;
}



===== DfscCredCreateTargetNameCopy @ 140013078 =====

ulonglong DfscCredCreateTargetNameCopy(longlong param_1,ulonglong *param_2,uint *param_3)

{
  ushort *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  puVar1 = (ushort *)(param_1 + 8);
  if (*param_3 < *puVar1 + 2) {
    uVar3 = 0x80000005;
    *param_3 = *puVar1 + 2;
  }
  else {
    uVar2 = DfscCreateNameFromUnicodeString(param_2,puVar1,0x78436644,param_2);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      *param_3 = *puVar1 + 2;
    }
  }
  return uVar3;
}



===== DfscCredGetKeymgrCredentials @ 1400130dc =====

int DfscCredGetKeymgrCredentials
              (longlong param_1,undefined4 param_2,undefined8 param_3,wchar_t *param_4,
              longlong param_5,longlong *param_6)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 local_res8;
  undefined4 local_res10 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  plVar1 = param_6;
  local_res8 = 0;
  local_res10[0] = 0;
  local_38 = 0;
  *param_6 = 0;
  iVar2 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlCopyLuid((longlong)&local_48 + 4,param_3);
  local_58 = *(undefined8 *)param_4;
  uStack_50 = *(undefined8 *)(param_4 + 4);
  local_48 = CONCAT44(local_48._4_4_,param_2);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0x68,1);
  plVar7 = (longlong *)local_res10;
  plVar6 = (longlong *)0x0;
  lVar3 = RtlLookupElementGenericTableFullAvl(param_1,&local_58,&local_res8);
  if (lVar3 != 0) {
    plVar6 = *(longlong **)(lVar3 + 0x20);
    LOCK();
    *(int *)((longlong)plVar6 + 4) = *(int *)((longlong)plVar6 + 4) + 1;
    UNLOCK();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      plVar7 = plVar6;
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,plVar6,
                (char)*(undefined4 *)((longlong)plVar6 + 4));
    }
  }
  param_6 = plVar6;
  if (plVar6 == (longlong *)0x0) {
    if (*(int *)(param_5 + 0x28) != 1) goto LAB_1400132d0;
    uVar4 = DfscCredCreateKeymgrCredentials((ushort *)param_4,param_5,&param_6,plVar7);
    plVar6 = param_6;
    iVar2 = (int)uVar4;
    if (iVar2 != 0) goto LAB_1400132d0;
    uVar5 = DfscCredTableStore(param_1,(longlong)param_6,&local_58,local_res8,local_res10[0]);
    iVar2 = (int)uVar5;
    if (iVar2 != 0) goto LAB_1400132d0;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0) {
        WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar5 + 0xc,
                  &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,plVar6,param_4);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                  &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,plVar6,
                  (char)*(undefined4 *)((longlong)plVar6 + 4));
      }
    }
  }
  else {
    LOCK();
    *(int *)((longlong)plVar6 + 4) = *(int *)((longlong)plVar6 + 4) + 1;
    UNLOCK();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,plVar6,
                (char)*(undefined4 *)((longlong)plVar6 + 4));
    }
    plVar6 = param_6;
    iVar2 = 0;
  }
  *plVar1 = (longlong)plVar6;
LAB_1400132d0:
  ExReleaseResourceLite(param_1 + 0x68);
  KeLeaveCriticalRegion();
  if (plVar6 != (longlong *)0x0) {
    DfscCredRelease((longlong)plVar6);
  }
  if (((iVar2 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
    WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,iVar2,param_4);
  }
  return iVar2;
}



===== DfscCredTableAllocateEntry @ 140013360 =====

void DfscCredTableAllocateEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x102,param_2,0x44436644);
  return;
}



===== DfscCredTableCompareEntries @ 140013390 =====

bool DfscCredTableCompareEntries(undefined8 param_1,wchar_t *param_2,wchar_t *param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(uint *)(param_3 + 8) < *(uint *)(param_2 + 8)) {
    return true;
  }
  if (*(uint *)(param_3 + 8) <= *(uint *)(param_2 + 8)) {
    uVar1 = *(uint *)(param_3 + 10);
    if ((*(uint *)(param_2 + 10) == uVar1) && (*(int *)(param_2 + 0xc) == *(int *)(param_3 + 0xc)))
    {
      if (*param_2 == *param_3) {
        iVar2 = RtlCompareUnicodeString(param_2,param_3,CONCAT71((uint7)(uint3)(uVar1 >> 8),1));
        if (0 < iVar2) {
          return true;
        }
        if (-1 < iVar2) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_dDDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                        &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,
                        *(undefined4 *)(param_2 + 8),(char)*(undefined4 *)(param_2 + 0xc),
                        (char)*(undefined4 *)(param_2 + 10),param_2);
          }
          return true;
        }
      }
      else if ((ushort)*param_3 < (ushort)*param_2) {
        return true;
      }
    }
    else {
      if (*(int *)(param_2 + 0xc) == *(int *)(param_3 + 0xc)) {
        return uVar1 < *(uint *)(param_2 + 10);
      }
      if (*(int *)(param_3 + 0xc) < *(int *)(param_2 + 0xc)) {
        return true;
      }
    }
  }
  return false;
}



===== DfscCredTableDelete @ 140013468 =====

void DfscCredTableDelete(undefined8 param_1,longlong param_2)

{
  char cVar1;
  
  cVar1 = RtlDeleteElementGenericTableAvl(param_1,*(undefined8 *)(param_2 + 0x20));
  if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x10b,1,param_1,param_2,param_2 + 8);
  }
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  return;
}



===== DfscCredTableFree @ 1400134d0 =====

void DfscCredTableFree(longlong param_1)

{
  if (param_1 != 0) {
    DfscCredTablePurge(param_1);
    ExDeleteResourceLite(param_1 + 0x68);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== DfscNetUseTableFreeEntry @ 140013510 =====

void DfscNetUseTableFreeEntry(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0);
  return;
}



===== DfscCredTableInitialize @ 140013534 =====

int DfscCredTableInitialize(undefined8 *param_1)

{
  int iVar1;
  void *_Dst;
  
  *param_1 = 0;
  _Dst = (void *)ExAllocatePool2(0x42,0xd0,0x43436644);
  if (_Dst == (void *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0xd0);
    iVar1 = ExInitializeResourceLite((longlong)_Dst + 0x68);
    if (iVar1 == 0) {
      RtlInitializeGenericTableAvl
                (_Dst,DfscCredTableCompareEntries,DfscCredTableAllocateEntry,
                 DfscNetUseTableFreeEntry,0);
      *param_1 = _Dst;
    }
    else {
      ExFreePoolWithTag(_Dst,0);
    }
  }
  return iVar1;
}



===== DfscCredTablePurge @ 1400135f0 =====

void DfscCredTablePurge(undefined8 param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    uVar2 = RtlNumberGenericTableElementsAvl();
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,uVar2);
  }
  lVar3 = RtlEnumerateGenericTableAvl(param_1,1);
  while (lVar3 != 0) {
    lVar3 = *(longlong *)(lVar3 + 0x20);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      lVar1 = *(longlong *)(lVar3 + 0x20);
      WPP_SF_dqZdDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,iVar4,(char)lVar3,
                     (wchar_t *)(lVar3 + 8),(char)*(undefined4 *)(lVar1 + 0x10),
                     (char)*(undefined4 *)(lVar1 + 0x18),(char)*(undefined4 *)(lVar1 + 0x14),
                     (char)*(undefined4 *)(lVar3 + 4));
    }
    DfscCredTableDelete(param_1,lVar3);
    DfscCredRelease(lVar3);
    lVar3 = RtlEnumerateGenericTableAvl(param_1,0);
    iVar4 = iVar4 + 1;
  }
  return;
}



===== DfscCredTableStore @ 140013714 =====

undefined8
DfscCredTableStore(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  char local_res8 [8];
  
  uVar3 = 0;
  local_res8[0] = '\0';
  puVar2 = (undefined8 *)
           RtlInsertElementGenericTableFullAvl(param_1,param_3,0x28,local_res8,param_4,param_5);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    if (local_res8[0] == '\0') {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x10b,1,param_1,param_2,param_2 + 8);
    }
    LOCK();
    *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
    UNLOCK();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,param_2,
                (char)*(undefined4 *)(param_2 + 4));
    }
    puVar2[4] = param_2;
    uVar1 = *(undefined8 *)(param_2 + 0x10);
    *puVar2 = *(undefined8 *)(param_2 + 8);
    puVar2[1] = uVar1;
    *(undefined8 **)(param_2 + 0x20) = puVar2;
    *(undefined8 *)(param_2 + 0x18) = param_1;
  }
  return uVar3;
}



===== DfscRestartCreateViaReparse @ 140013810 =====

undefined8 DfscRestartCreateViaReparse(longlong param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong local_res10;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res10 = 0;
  iVar1 = IoGetIrpExtraCreateParameter(param_1,local_res18);
  if (iVar1 == 0) {
    if (local_res18[0] != 0) {
      uVar3 = FsRtlFindExtraCreateParameter
                        (local_res18[0],&GUID_ECP_NETWORK_OPEN_CONTEXT,&local_res10,0);
      if (((int)uVar3 != 0) && ((int)uVar3 != -0x3ffffddb)) {
        return uVar3;
      }
    }
    if (local_res10 != 0) {
      uVar2 = 1;
      if ((*(uint *)(local_res10 + 8) & 0xfffffffb) != 0) {
        uVar2 = *(uint *)(local_res10 + 8);
      }
      *(uint *)(local_res10 + 0x14) = uVar2;
      if ((*(uint *)(local_res10 + 0xc) & 8) != 0) {
        *(uint *)(local_res10 + 0x18) = *(uint *)(local_res10 + 0x18) | 8;
      }
      FsRtlAcknowledgeEcp(local_res10);
    }
    uVar3 = MupSurrogateRestoreFileNameInFileObject(param_1);
    if ((int)uVar3 == 0) {
      *(undefined8 *)(param_1 + 0x38) = 0;
      uVar3 = 0x104;
    }
  }
  else {
    uVar3 = 0xc00000e5;
  }
  return uVar3;
}



===== DfscInitUnwind @ 1400138e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DfscInitUnwind(undefined8 param_1,undefined *param_2,undefined *param_3)

{
  wchar_t *pwVar1;
  undefined *puVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  DfscTearDownTimer();
  if ((DfscGlobalData & 1) != 0) {
    pwVar1 = L"\\Device\\DfsClient";
    local_28 = 0;
    uStack_20 = 0;
    RtlInitUnicodeString(&local_28);
    MupSurrogateDeregisterProvider(&local_28);
    DfscGlobalData = DfscGlobalData & 0xfffffffe;
    param_2 = (undefined *)pwVar1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    param_3 = &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids;
    param_2 = (undefined *)0x19;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids);
  }
  if (DAT_14000d838 != 0) {
    PsUnregisterSiloMonitor();
    DAT_14000d838 = 0;
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar2 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
        if (*(longlong *)(puVar2 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar2 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      param_2 = (undefined *)0x80000002;
      IoWMIRegistrationControl(WPP_GLOBAL_Control);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  if ((DfscInitializationStatus & 4) != 0) {
    DfscCacheDelete(DAT_14000d6c8,param_2,param_3);
    DfscInitializationStatus = DfscInitializationStatus & 0xfffffffb;
  }
  if ((DfscInitializationStatus & 8) != 0) {
    DfscCacheDelete(DAT_14000d6d0,param_2,param_3);
    DfscInitializationStatus = DfscInitializationStatus & 0xfffffff7;
  }
  if (DAT_14000d770 != 0) {
    ExFreePoolWithTag(DAT_14000d770,0);
    DAT_14000d770 = 0;
  }
  if ((DfscInitializationStatus & 0x100) != 0) {
    DfscDeInitSiteNameMonitoring();
  }
  if ((DfscInitializationStatus & 0x10) != 0) {
    DfscNetUseTableFree(0,DAT_14000d748,param_3);
    DfscInitializationStatus = DfscInitializationStatus & 0xffffffef;
  }
  if ((DfscInitializationStatus & 0x20) != 0) {
    DfscNetUseTableFree(0,DAT_14000d750,param_3);
    DfscInitializationStatus = DfscInitializationStatus & 0xffffffdf;
  }
  if ((DfscInitializationStatus & 0x40) != 0) {
    DfscCredTableFree(DAT_14000d6d8);
    DfscInitializationStatus = DfscInitializationStatus & 0xffffffbf;
  }
  if ((DfscInitializationStatus & 2) != 0) {
    ExDeletePagedLookasideList(&DfscPathNameLookasideList);
    DfscInitializationStatus = DfscInitializationStatus & 0xfffffffd;
  }
  if ((DfscInitializationStatus & 1) != 0) {
    ExDeleteResourceLite(&DAT_14000d658);
    ExDeleteResourceLite(&DAT_14000d6e0);
    DfscInitializationStatus = DfscInitializationStatus & 0xfffffffe;
  }
  if ((char)DfscInitializationStatus < '\0') {
    KeFreeCalloutStack(DAT_14000d778);
    DAT_14000d778 = 0;
    DfscInitializationStatus = DfscInitializationStatus & 0xffffff7f;
  }
  if (DAT_14000d648 != 0) {
    RtlInitUnicodeString(&local_18,L"\\Dfs");
    IoDeleteSymbolicLink(&local_18);
    IoDeleteDevice(DAT_14000d648);
    DAT_14000d648 = 0;
  }
  wil_UninitializeFeatureStaging();
  return;
}



===== DfscSystemControl @ 140013bb0 =====

undefined8 DfscSystemControl(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
  return 0xc00000bb;
}



===== DriverUnload @ 140013be0 =====

void DriverUnload(undefined8 param_1,undefined *param_2,undefined *param_3)

{
  DfscInitUnwind(param_1,param_2,param_3);
  return;
}



===== WppInitKm @ 140013bf8 =====

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



===== WppLoadTracingSupport @ 140013c88 =====

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



===== WppTraceCallback @ 140013dd0 =====

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



===== wil_UninitializeFeatureStaging @ 140014058 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400140b0 =====

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
      goto LAB_14001410d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001410d;
    }
  }
  uVar1 = 0x206;
LAB_14001410d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140014118 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400141d0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140014208 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001428a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001428a;
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
LAB_14001428a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400142e0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140014340 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001435c =====

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



===== DfscReferenceDcContext @ 140014410 =====

void DfscReferenceDcContext(longlong param_1)

{
  if (param_1 != 0) {
    LOCK();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    UNLOCK();
  }
  return;
}



===== DfscSetCurrentDcContext @ 140014424 =====

void DfscSetCurrentDcContext(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined *puVar2;
  bool bVar3;
  
  if (param_2 == 0) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000d658,1);
    DfscReferenceDcContext(param_1);
    lVar1 = DAT_14000d6c0;
    bVar3 = DAT_14000d6c0 != 0;
    DAT_14000d6c0 = param_1;
    if (bVar3) {
      DfscReleaseDcContext(lVar1);
    }
    puVar2 = &DAT_14000d658;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(param_2 + 0x10,1);
    DfscReferenceDcContext(param_1);
    lVar1 = *(longlong *)(param_2 + 0x78);
    *(longlong *)(param_2 + 0x78) = param_1;
    if (lVar1 != 0) {
      DfscReleaseDcContext(lVar1);
    }
    puVar2 = (undefined *)(param_2 + 0x10);
  }
  ExReleaseResourceLite(puVar2);
  KeLeaveCriticalRegion();
  return;
}



===== DfscCreateEas @ 1400144f4 =====

undefined8
DfscCreateEas(char param_1,longlong param_2,void *param_3,uint param_4,undefined8 *param_5,
             uint *param_6)

{
  uint *_Dst;
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  uint *_Dst_00;
  uint uVar4;
  
  uVar1 = 0;
  uVar2 = -(uint)(param_1 != '\0') & 0x14;
  uVar3 = uVar2;
  if ((param_2 != 0) && (*(int *)(param_2 + 0x48) != 0)) {
    uVar3 = *(int *)(param_2 + 0x48) + uVar2;
  }
  if ((param_3 != (void *)0x0) && (param_4 != 0)) {
    uVar3 = uVar3 + param_4;
  }
  if ((uVar3 < uVar2) || (0xffff < uVar3)) {
    uVar1 = 0xc000000d;
  }
  else {
    _Dst = (uint *)ExAllocatePool2(0x102,uVar3,0x65436644);
    if (_Dst == (uint *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)uVar3);
      uVar4 = 0;
      if (param_1 != '\0') {
        *(undefined8 *)(_Dst + 2) = 0x7461657243534644;
        *(undefined2 *)(_Dst + 4) = 0x65;
        *(undefined1 *)((longlong)_Dst + 5) = 10;
        *(undefined2 *)((longlong)_Dst + 6) = 0;
        *_Dst = 0;
        uVar4 = uVar2;
      }
      _Dst_00 = _Dst;
      if (param_2 != 0) {
        *_Dst = uVar4;
        _Dst_00 = (uint *)((longlong)_Dst + (ulonglong)uVar4);
        memmove(_Dst_00,(void *)(param_2 + 0x50),(ulonglong)*(uint *)(param_2 + 0x48));
        *_Dst_00 = 0;
        uVar4 = *(uint *)(param_2 + 0x48);
      }
      if ((param_3 != (void *)0x0) && (param_4 != 0)) {
        *_Dst_00 = uVar4;
        memmove((void *)((ulonglong)uVar4 + (longlong)_Dst_00),param_3,(ulonglong)param_4);
      }
      *param_5 = _Dst;
      *param_6 = uVar3;
    }
  }
  return uVar1;
}



===== DfscCreateNetUseConnection @ 140014640 =====

int DfscCreateNetUseConnection
              (longlong param_1,longlong param_2,ushort *param_3,wchar_t *param_4,longlong param_5,
              uint param_6,uint param_7,char param_8,uint *param_9)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ushort *puVar6;
  char local_58;
  char local_57;
  char local_56 [2];
  uint local_54;
  int *local_50;
  ushort local_48 [4];
  undefined8 local_40;
  longlong lStack_38;
  
  local_54 = 0;
  local_57 = '\0';
  local_50 = (int *)0x0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_40 = 0;
  lStack_38 = 0;
  local_58 = '\0';
  local_56[0] = '\0';
  puVar6 = param_3;
  RtlInitUnicodeStringEx(&local_40,0);
  iVar2 = DfscGetEffectiveRequestorSessionId(param_2,&local_54);
  if ((iVar2 == 0) && (iVar2 = DfscGetLogonId(local_48), iVar2 == 0)) {
    puVar6 = (ushort *)(ulonglong)local_54;
    uVar3 = DfscCreateTreeConnectName
                      ((ushort *)(param_4 + 0x28),param_3,local_54,(ushort *)&local_40);
    iVar2 = (int)uVar3;
    if (iVar2 == 0) {
      if (param_3 != (ushort *)0x0) {
        if ((param_8 == '\0') && (iVar2 = DfscImpersonateCaller(param_2,local_56), iVar2 != 0)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            puVar6 = (ushort *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                     &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar2);
          }
          goto LAB_140014902;
        }
        iVar2 = DfscCreateSymbolicLink(**(undefined2 **)(param_3 + 4),&local_40);
        if (iVar2 != 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            puVar6 = (ushort *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
            WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                     &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,(wchar_t *)&local_40);
          }
          goto LAB_140014902;
        }
        local_57 = '\x01';
      }
      while( true ) {
        puVar6 = (ushort *)(ulonglong)param_6;
        uVar3 = DfscCreateNetUseTreeConnection
                          ((wchar_t *)&local_40,param_5,param_6,param_7,param_9,&local_50);
        iVar2 = (int)uVar3;
        if (iVar2 != 0) break;
        if (param_6 != 2) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,(wchar_t *)&local_40);
          }
          piVar1 = local_50;
          puVar6 = local_48;
          iVar2 = DfscNetUseAdd(param_1,local_54,(int *)puVar6,param_4,local_50,
                                (undefined4 *)param_3,param_5,param_7,param_9,&local_58);
          if (((local_58 != '\x01') &&
              (DfscReleaseTreeConnectionHandle((longlong)piVar1),
              (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            puVar6 = (ushort *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
            WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                     &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,(wchar_t *)&local_40);
          }
          if (iVar2 == 0) goto LAB_14001492f;
          break;
        }
        DfscReleaseTreeConnectionHandle((longlong)local_50);
        local_50 = (int *)0x0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar3 + 0xc,
                   &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,(wchar_t *)&local_40);
        }
        param_6 = 1;
      }
      if (local_57 != '\0') {
        DfscDeleteSymbolicLink(**(undefined2 **)(param_3 + 4));
      }
    }
  }
LAB_140014902:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    puVar6 = (ushort *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar2);
  }
LAB_14001492f:
  if (local_56[0] != '\0') {
    PsRevertToSelf();
  }
  if (lStack_38 != 0) {
    ExFreePoolWithTag(lStack_38,0);
  }
  lVar5 = param_1;
  uVar4 = DfscGetDriveLetterNetUseTable(param_1);
  DfscNetUseTableDump(lVar5,uVar4,(undefined *)puVar6);
  lVar5 = param_1;
  uVar4 = DfscGetDevicelessNetUseTable(param_1);
  DfscNetUseTableDump(lVar5,uVar4,(undefined *)puVar6);
  lVar5 = DfscGetCredTable(param_1);
  DfscCredTableDump(lVar5,uVar4,(undefined *)puVar6);
  return iVar2;
}



===== DfscCreateNetUseTreeConnection @ 1400149b4 =====

ulonglong DfscCreateNetUseTreeConnection
                    (wchar_t *param_1,longlong param_2,int param_3,uint param_4,uint *param_5,
                    undefined8 *param_6)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  void *pvVar10;
  undefined8 *puVar11;
  longlong local_res8;
  uint local_res18 [2];
  undefined8 local_88;
  wchar_t local_80;
  undefined1 auStack_7e [6];
  longlong lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  wchar_t *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_88 = 0;
  local_res8 = 0;
  local_res18[0] = 0;
  local_44 = 0;
  local_58 = 0;
  local_60 = 0x30;
  local_48 = 0x240;
  local_70 = 0;
  uStack_68 = 0;
  _local_80 = 0;
  lStack_78 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (param_5 == (uint *)0x0) {
    uVar5 = 0;
    pvVar10 = (void *)0x0;
  }
  else {
    uVar5 = param_5[1];
    pvVar10 = (void *)((ulonglong)*param_5 + (longlong)param_5);
  }
  local_50 = param_1;
  uVar3 = DfscCreateEas(param_3 == 3,param_2,pvVar10,uVar5,&local_res8,local_res18);
  lVar1 = local_res8;
  uVar9 = uVar3 & 0xffffffff;
  if ((int)uVar3 == 0) {
    if (local_res8 != 0) {
      _local_80 = CONCAT62(CONCAT42(auStack_7e._2_4_,*(undefined2 *)(local_res8 + 6)),
                           *(undefined2 *)(local_res8 + 6));
      lStack_78 = (ulonglong)*(byte *)(local_res8 + 5) + 9 + local_res8;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      pwVar4 = &local_80;
      pcVar7 = (char *)(local_res8 + 8);
      if (local_res8 == 0) {
        pwVar4 = (wchar_t *)&DfscDefaultLogString;
        pcVar7 = "<Def>";
      }
      WPP_SF_ZsZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar7,pvVar10,param_1,pcVar7,pwVar4);
    }
    uVar6 = 0x4a1;
    if (param_3 != 2) {
      uVar6 = 0xa1;
    }
    uVar2 = (param_4 & 2) << 0xe;
    uVar5 = uVar2 | 0x4080;
    if ((param_4 & 4) == 0) {
      uVar5 = uVar2 | 0x80;
    }
    if (param_5 != (uint *)0x0) {
      uVar5 = uVar5 | param_5[3];
    }
    puVar11 = &local_60;
    uVar8 = 0x100000;
    uVar5 = ZwCreateFile(&local_88,0x100000,puVar11,&local_70,0,uVar5,7,3,uVar6,lVar1,local_res18[0]
                        );
    uVar9 = (ulonglong)uVar5;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,puVar11,param_1,(char)uVar5);
    }
    if (-1 < (int)uVar5) {
      *param_6 = local_88;
    }
  }
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return uVar9;
}



===== DfscCreateSymbolicLink @ 140014bc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscCreateSymbolicLink(undefined2 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  ulonglong local_90;
  longlong lStack_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  ulonglong *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  short local_50 [28];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_98 = 0;
  local_64 = 0;
  local_7c = 0;
  local_90 = 0;
  lStack_88 = 0;
  RtlStringCbCopyW(local_50);
  RtlInitUnicodeStringEx(&local_90,local_50);
  *(undefined2 *)(lStack_88 + -4 + (local_90 >> 1 & 0x7fff) * 2) = param_1;
  local_70 = &local_90;
  local_78 = 0;
  local_80 = 0x30;
  local_68 = 0x650;
  local_60 = 0;
  uStack_58 = 0;
  iVar1 = ZwCreateSymbolicLinkObject(&local_98,0xf0001,&local_80,param_2);
  if (-1 < iVar1) {
    ZwClose(local_98);
  }
  return iVar1;
}



===== DfscCreateTreeConnectName @ 140014cb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DfscCreateTreeConnectName
                    (ushort *param_1,ushort *param_2,undefined4 param_3,ushort *param_4)

{
  ushort uVar1;
  short *psVar2;
  int iVar3;
  undefined4 extraout_var;
  ulonglong uVar4;
  wchar_t *pwVar5;
  uint uVar6;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  ulonglong local_88;
  undefined8 local_80;
  wchar_t *pwStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  wchar_t local_60 [20];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  pwStack_78 = (wchar_t *)0x0;
  if ((((*param_1 < 6) || (psVar2 = *(short **)(param_1 + 4), *psVar2 != 0x5c)) ||
      (psVar2[1] == 0x5c)) || (psVar2[(ulonglong)(*param_1 >> 1) - 1] == 0)) {
    return 0xc00000e8;
  }
  if (param_2 != (ushort *)0x0) {
    if (*param_2 < 2) {
      return 0xc00000e8;
    }
    if (DfsLUIDDeviceMapsEnabled == 1) {
      iVar3 = DfscGetLogonId(&local_88);
      if (iVar3 != 0) {
        return CONCAT44(extraout_var,iVar3);
      }
      local_98 = (undefined4)local_88;
      uVar4 = RtlStringCbPrintfW(local_60,0x22,L"%08x%08x",local_88 >> 0x20);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      uVar4 = RtlInitUnicodeStringEx(&local_80,local_60);
    }
    else {
      local_80 = 0x220000;
      pwStack_78 = local_60;
      uVar4 = RtlIntegerToUnicodeString(param_3,10,&local_80);
    }
    if ((int)uVar4 != 0) {
      return uVar4;
    }
  }
  pwVar5 = wcschr(L"Device\\DfsClient",L'\\');
  if ((pwVar5 != (wchar_t *)0x0) && (pwVar5[1] != L'\0')) {
    iVar3 = RtlInitUnicodeStringEx(&local_70,pwVar5);
    if (iVar3 != 0) {
      return 0xc0000420;
    }
    uVar6 = (ushort)local_80 + 0x1e + (uint)*param_1 + (uint)(ushort)local_70;
    if (uVar6 < 0x10000) {
      param_4[1] = (ushort)uVar6;
      pwVar5 = (wchar_t *)ExAllocatePool2(0x102,uVar6 & 0xffff,0x74436644);
      *(wchar_t **)(param_4 + 4) = pwVar5;
      if (pwVar5 == (wchar_t *)0x0) {
        return 0xc000009a;
      }
      *param_4 = 0x16;
      builtin_wcsncpy(pwVar5,L"\\Device\\Mup",0xb);
      uVar4 = RtlAppendUnicodeStringToString(param_4,&local_70);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      uVar4 = RtlAppendUnicodeToString(param_4,L"\\;");
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      if (param_2 != (ushort *)0x0) {
        *(undefined2 *)(*(longlong *)(param_4 + 4) + (ulonglong)(*param_4 >> 1) * 2) =
             **(undefined2 **)(param_2 + 4);
        *param_4 = *param_4 + 2;
      }
      *(undefined2 *)(*(longlong *)(param_4 + 4) + (ulonglong)(*param_4 >> 1) * 2) = 0x3a;
      uVar1 = *param_4;
      *param_4 = uVar1 + 2;
      if ((ushort)local_80 == 0) {
        *(undefined2 *)(*(longlong *)(param_4 + 4) + (ulonglong)((ushort)(uVar1 + 2) >> 1) * 2) =
             0x30;
        *param_4 = *param_4 + 2;
      }
      else {
        RtlAppendUnicodeStringToString(param_4,&local_80);
      }
      RtlAppendUnicodeToString(param_4,*(undefined8 *)(param_1 + 4));
      return 0;
    }
  }
  return 0xc000000d;
}



===== DfscDeleteSymbolicLink @ 140014f7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscDeleteSymbolicLink(undefined2 param_1)

{
  int iVar1;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  ulonglong local_90;
  longlong lStack_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  ulonglong *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  short local_50 [28];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_98 = 0;
  local_64 = 0;
  local_7c = 0;
  local_90 = 0;
  lStack_88 = 0;
  RtlStringCbCopyW(local_50);
  RtlInitUnicodeStringEx(&local_90,local_50);
  *(undefined2 *)(lStack_88 + -4 + (local_90 >> 1 & 0x7fff) * 2) = param_1;
  local_70 = &local_90;
  local_78 = 0;
  local_80 = 0x30;
  local_68 = 0x650;
  local_60 = 0;
  uStack_58 = 0;
  iVar1 = ZwOpenSymbolicLinkObject(&local_98,0x10001,&local_80);
  if (-1 < iVar1) {
    iVar1 = ZwMakeTemporaryObject(local_98);
    ZwClose(local_98);
  }
  return iVar1;
}



===== DfscGetUseInfo @ 140015070 =====

int DfscGetUseInfo(longlong param_1,longlong param_2,wchar_t *param_3,ushort *param_4,uint *param_5)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined *puVar9;
  short *psVar10;
  ushort uVar11;
  undefined *puVar12;
  uint uVar13;
  ulonglong local_res20;
  wchar_t local_70 [28];
  
  puVar4 = param_5;
  puVar12 = &DAT_14000d6e0;
  local_res20 = 0;
  lVar6 = 0;
  local_70[0] = L'\0';
  local_70[1] = L'\0';
  local_70[2] = L'\0';
  local_70[3] = L'\0';
  local_70[4] = L'\0';
  local_70[5] = L'\0';
  local_70[6] = L'\0';
  local_70[7] = L'\0';
  local_70[8] = L'\0';
  local_70[9] = L'\0';
  local_70[10] = L'\0';
  local_70[0xb] = L'\0';
  local_70[0xc] = L'\0';
  local_70[0xd] = L'\0';
  local_70[0xe] = L'\0';
  local_70[0xf] = L'\0';
  local_70[0x10] = L'\0';
  local_70[0x11] = L'\0';
  local_70[0x12] = L'\0';
  local_70[0x13] = L'\0';
  local_70[0x14] = L'\0';
  local_70[0x15] = L'\0';
  local_70[0x16] = L'\0';
  local_70[0x17] = L'\0';
  bVar2 = false;
  if (*param_5 < 0x20) {
    iVar5 = -0x7ffffffb;
  }
  else {
    iVar5 = DfscNetUseGetSearchKey
                      (param_1,(undefined8 *)param_3,param_2,&local_res20,(undefined8 *)local_70);
    if (iVar5 == 0) {
      KeEnterCriticalRegion();
      puVar9 = (undefined *)(param_1 + 0x98);
      if (param_1 == 0) {
        puVar9 = &DAT_14000d6e0;
      }
      bVar3 = true;
      ExAcquireResourceExclusiveLite(puVar9,1);
      lVar6 = DfscNetUseTableLookup(local_res20,local_70,0);
      bVar2 = true;
      if (lVar6 == 0) {
        iVar5 = -0x3fffffcc;
      }
      else {
        uVar13 = *puVar4;
        local_res20 = CONCAT44(local_res20._4_4_,0x1c);
        param_4[0] = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        param_4[3] = 0;
        param_4[4] = 0;
        param_4[5] = 0;
        param_4[6] = 0;
        param_4[7] = 0;
        param_4[8] = 0;
        param_4[9] = 0;
        param_4[10] = 0;
        param_4[0xb] = 0;
        param_4[0xc] = 0;
        param_4[0xd] = 0;
        param_4[0xe] = 0;
        param_4[0xf] = 0;
        uVar7 = DfscPackString((short *)(lVar6 + 0x68),(longlong)param_4,uVar13,4,
                               (uint *)&local_res20,param_4);
        iVar5 = (int)uVar7;
        if (-1 < iVar5) {
          *(uint *)(param_4 + 8) = (uint)*param_4 + *(int *)(param_4 + 6);
          uVar13 = *(ushort *)(lVar6 + 0x58) + 4;
          bVar2 = bVar3;
          if (uVar13 < 0x10000) {
            if (((uint)local_res20 <= uVar13 + (uint)local_res20) &&
               (uVar8 = *puVar4, uVar13 + (uint)local_res20 <= uVar8)) {
              *(undefined2 *)((local_res20 & 0xffffffff) + (longlong)param_4) = 0x5c;
              local_res20 = CONCAT44(local_res20._4_4_,(uint)local_res20 + 2);
              uVar7 = DfscPackString(*(short **)(lVar6 + 0x60),(longlong)param_4,uVar8,
                                     *(ushort *)(lVar6 + 0x58),(uint *)&local_res20,
                                     (ushort *)&param_5);
              iVar5 = (int)uVar7;
              if (-1 < iVar5) {
                *(undefined2 *)((local_res20 & 0xffffffff) + (longlong)param_4) = 0;
                uVar8 = (uint)local_res20 + 2;
                param_4[1] = (ushort)uVar13;
                *(uint *)(param_4 + 10) = (uVar13 & 0xffff) + *(int *)(param_4 + 8);
                lVar1 = *(longlong *)(lVar6 + 0x70);
                local_res20 = CONCAT44(local_res20._4_4_,uVar8);
                if (lVar1 != 0) {
                  psVar10 = *(short **)(lVar1 + 0x40);
                  uVar11 = *(ushort *)(lVar1 + 0x38);
                  if (*psVar10 == 0x5c) {
                    psVar10 = psVar10 + 1;
                    uVar11 = uVar11 - 2;
                  }
                  uVar7 = DfscPackString(psVar10,(longlong)param_4,*puVar4,uVar11,
                                         (uint *)&local_res20,param_4 + 2);
                  iVar5 = (int)uVar7;
                  if (iVar5 < 0) goto LAB_1400151b3;
                  uVar8 = (uint)local_res20;
                }
                *(undefined4 *)(param_4 + 4) = *(undefined4 *)(lVar6 + 0x90);
                *puVar4 = uVar8;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
                  WPP_SF_ZZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,WPP_GLOBAL_Control,
                             (wchar_t *)
                             (-(ulonglong)(*(longlong *)(lVar6 + 0x70) != 0) &
                             *(longlong *)(lVar6 + 0x70) + 0x38U),param_3,(char)uVar8);
                }
              }
              goto LAB_1400151b3;
            }
          }
          iVar5 = -0x7ffffffb;
        }
      }
    }
  }
LAB_1400151b3:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
    WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar5,param_3);
  }
  if (bVar2) {
    if (param_1 != 0) {
      puVar12 = (undefined *)(param_1 + 0x98);
    }
    ExReleaseResourceLite(puVar12);
    KeLeaveCriticalRegion();
  }
  if (lVar6 != 0) {
    DfscNetUseRelease(param_1,lVar6,0,'\0');
  }
  return iVar5;
}



===== DfscImpersonateCaller @ 140015370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscImpersonateCaller(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined2 local_80;
  undefined2 local_7e;
  undefined1 local_78 [12];
  undefined4 local_6c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_6c = 0;
  memset(local_78,0,0x44);
  *param_2 = 0;
  local_7e = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((*(void **)(param_1 + 0x98) == (void *)0x0) ||
     (*(void **)(param_1 + 0x98) == SystemReserved1[0xf])) {
    iVar1 = 0;
  }
  else {
    uVar2 = IoThreadToProcess();
    SeCaptureSubjectContextEx(*(undefined8 *)(param_1 + 0x98),uVar2,&local_a8);
    local_88 = 0xc;
    local_84 = 2;
    local_80 = 1;
    iVar1 = SeCreateClientSecurityFromSubjectContext(&local_a8,&local_88,0,local_78);
    if (-1 < iVar1) {
      iVar1 = SeImpersonateClientEx(local_78,0);
      if (-1 < iVar1) {
        *param_2 = 1;
      }
      SeDeleteClientSecurity(local_78);
    }
    SeReleaseSubjectContext(&local_a8);
  }
  return iVar1;
}



===== DfscPackString @ 1400154a4 =====

undefined8
DfscPackString(short *param_1,longlong param_2,uint param_3,ushort param_4,uint *param_5,
              ushort *param_6)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  *param_6 = 0;
  if ((param_4 != 0) && (*param_1 != 0)) {
    uVar2 = *param_5 + (uint)param_4;
    if ((uVar2 < param_4) || (param_3 < uVar2)) {
      uVar1 = 0x80000005;
    }
    else {
      memmove((void *)(param_2 + (ulonglong)*param_5),param_1,(ulonglong)param_4);
      uVar1 = 0;
      *param_5 = uVar2;
      *param_6 = param_4;
    }
  }
  return uVar1;
}



===== DfscCopyDcList @ 140015528 =====

undefined8 DfscCopyDcList(longlong param_1,longlong param_2)

{
  wchar_t *pwVar1;
  void *_Dst;
  
  if (*(longlong *)(param_2 + 0x30) != 0) {
    _Dst = (void *)ExAllocatePool2(0x102,*(undefined2 *)(param_2 + 0x40),0x6c436644);
    *(void **)(param_1 + 0x30) = _Dst;
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    *(undefined2 *)(param_1 + 0x40) = *(undefined2 *)(param_2 + 0x40);
    memmove(_Dst,*(void **)(param_2 + 0x30),(ulonglong)*(ushort *)(param_2 + 0x40));
    pwVar1 = (wchar_t *)
             (*(longlong *)(param_1 + 0x30) +
             (*(longlong *)(param_2 + 8) - *(longlong *)(param_2 + 0x30) >> 1 & 0xfffffffffffffffeU)
             );
    *(wchar_t **)(param_1 + 8) = pwVar1;
    *(ulonglong *)(param_1 + 0x38) =
         *(longlong *)(param_1 + 0x30) +
         (*(longlong *)(param_2 + 0x38) - *(longlong *)(param_2 + 0x30) >> 1 & 0xfffffffffffffffeU);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,pwVar1);
    }
  }
  return 0;
}



===== DfscCreateLinkedConnection @ 1400155fc =====

int DfscCreateLinkedConnection
              (longlong param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5,
              longlong param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  longlong *plVar2;
  longlong local_28;
  longlong local_20;
  
  local_28 = 0;
  local_20 = 0;
  plVar2 = (longlong *)ExAllocatePool2(0x42,0x68,0x4c436644);
  if (plVar2 == (longlong *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = ZwOpenThreadTokenEx(0xfffffffffffffffe,8,1,0x200,&local_28);
    if (iVar1 == -0x3fffff84) {
      iVar1 = ZwOpenProcessTokenEx(0xffffffffffffffff,8,0x200,&local_28);
    }
    if (iVar1 < 0) {
      ExFreePoolWithTag(plVar2,0);
    }
    else {
      plVar2[5] = param_2;
      *plVar2 = (longlong)&local_28;
      plVar2[8] = param_5;
      plVar2[9] = param_6;
      *(undefined4 *)(plVar2 + 10) = param_7;
      *(undefined4 *)(plVar2 + 0xc) = param_8;
      plVar2[6] = param_3;
      plVar2[7] = param_4;
      plVar2[0xb] = param_1;
      KeInitializeEvent(plVar2 + 1,1);
      iVar1 = PsCreateSystemThread(&local_20,0x1fffff,0,0,0,DfscCreateLinkedConnectionWorker,plVar2)
      ;
      if ((-1 < iVar1) && (iVar1 = KeWaitForSingleObject(plVar2 + 1,0,0,0,0), -1 < iVar1)) {
        iVar1 = (int)plVar2[4];
      }
      ExFreePoolWithTag(plVar2,0);
      if (local_28 != 0) {
        ZwClose();
      }
      if (local_20 != 0) {
        ZwClose();
      }
    }
  }
  return iVar1;
}



===== DfscCreateLinkedConnectionWorker @ 1400157f0 =====

void DfscCreateLinkedConnectionWorker(undefined8 *param_1)

{
  longlong lVar1;
  short *psVar2;
  int iVar3;
  wchar_t *pwVar4;
  
  iVar3 = DfscImpersonateLinkedToken((undefined8 *)*param_1);
  if (iVar3 < 0) {
    if (iVar3 == -0x3fffffdc) {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = DfscCreateNetUseConnection
                      (param_1[0xb],param_1[5],(ushort *)param_1[6],(wchar_t *)param_1[7],param_1[8]
                       ,*(uint *)(param_1 + 10),*(uint *)(param_1 + 0xc),'\x01',(uint *)0x0);
    if ((((((-1 < iVar3) && (lVar1 = param_1[8], *(int *)(lVar1 + 0x34) == 0)) &&
          ((short *)(lVar1 + 0x38) != (short *)0x0)) &&
         ((*(short *)(lVar1 + 0x38) != 0 && (*(short **)(lVar1 + 0x40) != (short *)0x0)))) &&
        ((**(short **)(lVar1 + 0x40) != 0 &&
         ((psVar2 = (short *)param_1[9], psVar2 != (short *)0x0 && (*psVar2 != 0)))))) &&
       ((*(short **)(psVar2 + 4) != (short *)0x0 && (**(short **)(psVar2 + 4) != 0)))) {
      iVar3 = DfscCredWrite();
      if (iVar3 < 0) {
        pwVar4 = (wchar_t *)param_1[6];
        if (pwVar4 == (wchar_t *)0x0) {
          pwVar4 = (wchar_t *)(param_1[7] + 0x50);
        }
        DfscDeleteNetUseConnection
                  (param_1[0xb],pwVar4,(uint *)param_1[5],2,(undefined4 *)0x0,(uint *)0x0,'\x01');
      }
    }
    DfscRevert();
  }
  *(int *)(param_1 + 4) = iVar3;
  KeSetEvent(param_1 + 1,0,0);
  PsTerminateSystemThread(0);
  return;
}



===== DfscDeleteLinkedConnection @ 140015928 =====

int DfscDeleteLinkedConnection
              (longlong param_1,longlong param_2,longlong param_3,undefined4 param_4)

{
  int iVar1;
  longlong *plVar2;
  longlong local_28;
  longlong local_20;
  
  local_28 = 0;
  local_20 = 0;
  plVar2 = (longlong *)ExAllocatePool2(0x42,0x48,0x4c436644);
  if (plVar2 == (longlong *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = ZwOpenThreadTokenEx(0xfffffffffffffffe,8,1,0x200,&local_28);
    if (iVar1 == -0x3fffff84) {
      iVar1 = ZwOpenProcessTokenEx(0xffffffffffffffff,8,0x200,&local_28);
    }
    if (iVar1 < 0) {
      ExFreePoolWithTag(plVar2,0);
    }
    else {
      plVar2[5] = param_3;
      plVar2[6] = param_2;
      *plVar2 = (longlong)&local_28;
      *(undefined4 *)(plVar2 + 7) = param_4;
      plVar2[8] = param_1;
      KeInitializeEvent(plVar2 + 1,1);
      iVar1 = PsCreateSystemThread(&local_20,0x1fffff,0,0,0,DfscDeleteLinkedConnectionWorker,plVar2)
      ;
      if ((-1 < iVar1) && (iVar1 = KeWaitForSingleObject(plVar2 + 1,0,0,0,0), -1 < iVar1)) {
        iVar1 = (int)plVar2[4];
      }
      ExFreePoolWithTag(plVar2,0);
      if (local_28 != 0) {
        ZwClose();
      }
      if (local_20 != 0) {
        ZwClose();
      }
    }
  }
  return iVar1;
}



===== DfscDeleteLinkedConnectionWorker @ 140015ae0 =====

void DfscDeleteLinkedConnectionWorker(undefined8 *param_1)

{
  int iVar1;
  undefined4 *_Dst;
  uint local_res8 [2];
  
  iVar1 = DfscImpersonateLinkedToken((undefined8 *)*param_1);
  if (iVar1 < 0) {
    if (iVar1 == -0x3fffffdc) {
      iVar1 = 0;
    }
  }
  else {
    local_res8[0] = 0x210;
    _Dst = (undefined4 *)ExAllocatePool2(0x102,0x210,0x4c436644);
    if (_Dst == (undefined4 *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      memset(_Dst,0,0x210);
      iVar1 = DfscDeleteNetUseConnection
                        (param_1[8],(wchar_t *)param_1[6],(uint *)param_1[5],*(int *)(param_1 + 7),
                         _Dst,local_res8,'\x01');
      if (-1 < iVar1) {
        DfscCredDelete();
      }
      ExFreePoolWithTag(_Dst,0);
    }
    DfscRevert();
  }
  *(int *)(param_1 + 4) = iVar1;
  KeSetEvent(param_1 + 1,0,0);
  PsTerminateSystemThread(0);
  return;
}



===== DfscFsctrlFlushClusterSetCache @ 140015be8 =====

uint DfscFsctrlFlushClusterSetCache(longlong param_1,short *param_2,undefined *param_3)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  ushort uVar12;
  ulonglong uVar13;
  longlong local_res10 [2];
  longlong local_res20;
  undefined8 local_58;
  short *psStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res20 = 0;
  uVar13 = (ulonglong)param_3 & 0xffffffff;
  local_res10[0] = 0;
  local_58 = 0;
  psStack_50 = (short *)0x0;
  if ((((((ulonglong)param_3 & 1) != 0) || (iVar6 = (int)param_3, 0xfffc < iVar6 - 2U)) ||
      (param_2 == (short *)0x0)) || (*param_2 == 0)) {
    return 0xc000000d;
  }
  uVar5 = DfscGetContainerContextFromIrp(param_1,local_res10);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  lVar11 = local_res10[0];
  lVar7 = DfscGetReferralCache(local_res10[0]);
  if ((iVar6 == 2) && (*param_2 == 0x2a)) {
    DfscClusterSetCachePurge(lVar7,lVar11,param_3);
    return uVar5;
  }
  uVar12 = (ushort)uVar13;
  local_58._0_4_ = CONCAT22(uVar12,uVar12);
  psStack_50 = param_2;
  if (((4 < uVar12) && (psStack_50 = param_2, *param_2 == 0x5c)) &&
     (psStack_50 = param_2, param_2[1] == 0x5c)) {
    uVar12 = uVar12 - 2;
    uVar13 = (ulonglong)uVar12;
    local_58._0_4_ = CONCAT22(uVar12,uVar12);
    psStack_50 = param_2 + 1;
  }
  local_48 = 0;
  uStack_40 = 0;
  if ((2 < (ushort)uVar13) && (*(short *)((longlong)psStack_50 + ((uVar13 & 0xfffe) - 2)) == 0x5c))
  {
    uVar12 = (ushort)uVar13 - 2;
    uVar13 = (ulonglong)uVar12;
    local_58 = CONCAT62(local_58._2_6_,uVar12);
  }
  if ((((ushort)uVar13 < 4) || (uVar8 = (uVar13 & 0xffff) >> 1, psStack_50[uVar8 - 2] != 0x5c)) ||
     (psStack_50[uVar8 - 1] != 0x2a)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
    local_58 = CONCAT62(local_58._2_6_,(ushort)uVar13 - 4);
  }
  bVar4 = 0;
  iVar6 = DfscGetReferralFromPath
                    (param_1,(undefined2 *)0x0,(ushort *)&local_58,3,lVar11,&local_res20,0,
                     (short *)&local_48);
  lVar11 = local_res20;
  if (iVar6 < 0) {
    return 0xc0000034;
  }
  lVar2 = *(longlong *)(local_res20 + 0x10);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar7 + 0x38,1);
  if ((!bVar3) || (*(int *)(lVar2 + 0xc) == 2)) {
    if (((short)local_48 == 0) &&
       (((*(byte *)(lVar2 + 0x10) & 1) != 0 && (*(char *)(lVar2 + 0x14) != '\0')))) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                  &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,lVar2,(char)param_1);
      }
      DfscRmUnlinkReferral(lVar2);
      DfscRmDereferenceReferral(lVar2);
      bVar4 = 1;
    }
    if (!bVar3) goto LAB_140015ea7;
  }
  if (*(int *)(lVar2 + 0xc) == 1) {
    lVar9 = RtlNextUnicodePrefix(lVar7,1);
    while (lVar9 != 0) {
      lVar1 = lVar9 + -0x48;
      if (((*(int *)(lVar9 + -0x3c) == 2) && (*(char *)(lVar9 + -0x34) != '\0')) &&
         (uVar10 = DfscPathPrefixMatch((ushort *)
                                       (((ulonglong)*(ushort *)(lVar2 + 0x1e) + 2) * 0x70 + lVar2),
                                       (ushort *)(lVar9 + 0x48)), (char)uVar10 != '\0')) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                    &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,lVar1,(char)param_1);
        }
        DfscRmUnlinkReferral(lVar1);
        DfscRmDereferenceReferral(lVar1);
        bVar4 = 1;
      }
      lVar9 = RtlNextUnicodePrefix(lVar7,0);
    }
  }
LAB_140015ea7:
  ExReleaseResourceLite(lVar7 + 0x38);
  KeLeaveCriticalRegion();
  DfscReferralRelease(lVar11);
  return ~-(uint)bVar4 & 0xc0000034;
}



===== DfscFsctrlFlushDomainCache @ 140015f08 =====

uint DfscFsctrlFlushDomainCache(longlong param_1,short *param_2,undefined *param_3)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  uint uVar7;
  longlong local_res10;
  undefined8 local_28;
  short *psStack_20;
  
  local_res10 = 0;
  uVar7 = (uint)param_3;
  local_28 = 0;
  psStack_20 = (short *)0x0;
  if ((((uVar7 < 2) || (((ulonglong)param_3 & 1) != 0)) || (0xfffe < uVar7)) ||
     ((param_2 == (short *)0x0 || (*param_2 == 0)))) {
    uVar3 = 0xc000000d;
  }
  else {
    plVar6 = &local_res10;
    uVar3 = DfscGetContainerContextFromIrp(param_1,plVar6);
    if (-1 < (int)uVar3) {
      if ((uVar7 == 2) && (*param_2 == 0x2a)) {
        lVar4 = DfscGetDomainCache(local_res10);
        DfscCachePurge(lVar4,plVar6,param_3);
        uVar3 = DfscPopulateDomainNameCache(param_1,local_res10);
      }
      else {
        uVar3 = 0;
        if (uVar7 >> 1 != 0) {
          do {
            if (param_2[uVar3] == 0) break;
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar7 >> 1);
        }
        sVar2 = (short)uVar3 * 2;
        local_28._0_4_ = CONCAT22(sVar2,sVar2);
        psStack_20 = param_2;
        lVar4 = DfscGetDomainCache(local_res10);
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(lVar4 + 0x38,1);
        uVar3 = 0xc000003a;
        lVar5 = RtlFindUnicodePrefix(lVar4,&local_28,0);
        if (((lVar5 != 0) && (lVar1 = lVar5 + -0x48, (*(byte *)(lVar5 + -0x38) & 1) != 0)) &&
           (*(short *)(lVar5 + 0x48) == (short)local_28)) {
          uVar3 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                      &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,lVar1,(char)param_1);
          }
          DfscRmUnlinkReferral(lVar1);
          DfscRmDereferenceReferral(lVar1);
        }
        ExReleaseResourceLite(lVar4 + 0x38);
        KeLeaveCriticalRegion();
      }
    }
  }
  return uVar3;
}



===== DfscFsctrlFlushRefCache @ 1400160c4 =====

uint DfscFsctrlFlushRefCache(longlong param_1,short *param_2,undefined *param_3)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  ushort uVar12;
  ulonglong uVar13;
  longlong local_res10 [2];
  longlong local_res20;
  undefined8 local_58;
  short *psStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res20 = 0;
  uVar13 = (ulonglong)param_3 & 0xffffffff;
  local_res10[0] = 0;
  local_58 = 0;
  psStack_50 = (short *)0x0;
  if ((((((ulonglong)param_3 & 1) != 0) || (iVar6 = (int)param_3, 0xfffc < iVar6 - 2U)) ||
      (param_2 == (short *)0x0)) || (*param_2 == 0)) {
    return 0xc000000d;
  }
  uVar5 = DfscGetContainerContextFromIrp(param_1,local_res10);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  lVar11 = local_res10[0];
  lVar7 = DfscGetReferralCache(local_res10[0]);
  if ((iVar6 == 2) && (*param_2 == 0x2a)) {
    DfscCachePurge(lVar7,lVar11,param_3);
    return uVar5;
  }
  uVar12 = (ushort)uVar13;
  local_58._0_4_ = CONCAT22(uVar12,uVar12);
  psStack_50 = param_2;
  if (((4 < uVar12) && (psStack_50 = param_2, *param_2 == 0x5c)) &&
     (psStack_50 = param_2, param_2[1] == 0x5c)) {
    uVar12 = uVar12 - 2;
    uVar13 = (ulonglong)uVar12;
    local_58._0_4_ = CONCAT22(uVar12,uVar12);
    psStack_50 = param_2 + 1;
  }
  local_48 = 0;
  uStack_40 = 0;
  if ((2 < (ushort)uVar13) && (*(short *)((longlong)psStack_50 + ((uVar13 & 0xfffe) - 2)) == 0x5c))
  {
    uVar12 = (ushort)uVar13 - 2;
    uVar13 = (ulonglong)uVar12;
    local_58 = CONCAT62(local_58._2_6_,uVar12);
  }
  if ((((ushort)uVar13 < 4) || (uVar8 = (uVar13 & 0xffff) >> 1, psStack_50[uVar8 - 2] != 0x5c)) ||
     (psStack_50[uVar8 - 1] != 0x2a)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
    local_58 = CONCAT62(local_58._2_6_,(ushort)uVar13 - 4);
  }
  bVar4 = 0;
  iVar6 = DfscGetReferralFromPath
                    (param_1,(undefined2 *)0x0,(ushort *)&local_58,3,lVar11,&local_res20,0,
                     (short *)&local_48);
  lVar11 = local_res20;
  if (iVar6 < 0) {
    return 0xc0000034;
  }
  lVar2 = *(longlong *)(local_res20 + 0x10);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar7 + 0x38,1);
  if ((!bVar3) || (*(int *)(lVar2 + 0xc) == 2)) {
    if (((short)local_48 == 0) && ((*(byte *)(lVar2 + 0x10) & 1) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                  &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,lVar2,(char)param_1);
      }
      DfscRmUnlinkReferral(lVar2);
      DfscRmDereferenceReferral(lVar2);
      bVar4 = 1;
    }
    if (!bVar3) goto LAB_140016378;
  }
  if (*(int *)(lVar2 + 0xc) == 1) {
    lVar9 = RtlNextUnicodePrefix(lVar7,1);
    while (lVar9 != 0) {
      lVar1 = lVar9 + -0x48;
      if ((*(int *)(lVar9 + -0x3c) == 2) &&
         (uVar10 = DfscPathPrefixMatch((ushort *)
                                       (((ulonglong)*(ushort *)(lVar2 + 0x1e) + 2) * 0x70 + lVar2),
                                       (ushort *)(lVar9 + 0x48)), (char)uVar10 != '\0')) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                    &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,lVar1,(char)param_1);
        }
        DfscRmUnlinkReferral(lVar1);
        DfscRmDereferenceReferral(lVar1);
        bVar4 = 1;
      }
      lVar9 = RtlNextUnicodePrefix(lVar7,0);
    }
  }
LAB_140016378:
  ExReleaseResourceLite(lVar7 + 0x38);
  KeLeaveCriticalRegion();
  DfscReferralRelease(lVar11);
  return ~-(uint)bVar4 & 0xc0000034;
}



===== DfscFsctrlGetClientInfo @ 1400163d8 =====

int DfscFsctrlGetClientInfo
              (longlong param_1,void *param_2,uint param_3,ulonglong *param_4,uint param_5)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  ushort *_Dst;
  ulonglong uVar5;
  ushort uVar6;
  longlong lVar7;
  int iVar8;
  uint local_84;
  ushort local_80;
  undefined1 auStack_7e [6];
  ushort *puStack_78;
  int local_70;
  int local_6c;
  longlong local_68;
  undefined8 local_60;
  longlong lStack_58;
  undefined8 local_50;
  longlong lStack_48;
  longlong local_40;
  ushort *local_38;
  short local_30 [12];
  
  _local_80 = 0;
  puStack_78 = (ushort *)0x0;
  local_50 = 0;
  lStack_48 = 0;
  local_60 = 0;
  lStack_58 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  local_84 = 0;
  _Dst = (ushort *)0x0;
  local_38 = (ushort *)0x0;
  lVar7 = 0;
  local_68 = 0;
  local_40 = 0;
  if (((param_2 == (void *)0x0) || (param_3 < 0x10)) || (param_4 == (ulonglong *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
               &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,param_3);
    }
    iVar4 = -0x3ffffff3;
    *(undefined8 *)(param_1 + 0x38) = 0;
    goto LAB_14001679c;
  }
  _Dst = (ushort *)ExAllocatePool2(0x102,(ulonglong)param_3,0x69436644);
  local_38 = _Dst;
  if (_Dst == (ushort *)0x0) {
    iVar4 = -0x3fffff66;
    goto LAB_14001679c;
  }
  memmove(_Dst,param_2,(ulonglong)param_3);
  iVar4 = *(int *)(_Dst + 4);
  if ((((3 < iVar4 - 1U) && (iVar4 != 0x65)) || ((uVar6 = _Dst[1], uVar6 == 0 && (_Dst[2] != 0))))
     || ((((uVar1 = *_Dst, (uVar1 & 1) != 0 || ((uVar6 & 1) != 0)) || ((_Dst[2] & 1) != 0)) ||
         (param_3 - 0xc < (uint)_Dst[2] + (uint)uVar1 + (uint)uVar6)))) {
    iVar4 = -0x3ffffff3;
    goto LAB_14001679c;
  }
  iVar8 = iVar4;
  if (iVar4 == 0x65) {
    iVar8 = 1;
  }
  local_70 = 4 - (uint)(iVar4 != 0x65);
  _local_80 = CONCAT62(CONCAT42(auStack_7e._2_4_,uVar1),uVar1);
  puStack_78 = _Dst + 6;
  uVar6 = uVar1;
  if ((4 < uVar1) && (*puStack_78 == 0x5c)) {
    if (_Dst[7] == 0x5c) {
      uVar6 = uVar1 - 2;
      _local_80 = CONCAT22(uVar1 - 2,uVar6);
      puStack_78 = _Dst + 7;
    }
  }
  if ((2 < uVar6) && (puStack_78[(ulonglong)(uVar6 >> 1) - 1] == 0x5c)) {
    _local_80 = CONCAT62(auStack_7e,uVar6 - 2);
  }
  local_6c = iVar8;
  RtlInitUnicodeString(&local_50,0);
  RtlInitUnicodeString(&local_60,0);
  if (_Dst[1] != 0) {
    lStack_48 = (ulonglong)*_Dst + 0xc + (longlong)_Dst;
    local_50 = CONCAT62(CONCAT42(local_50._4_4_,_Dst[1]),_Dst[1]);
    if (_Dst[2] != 0) {
      local_60 = CONCAT62(CONCAT42(local_60._4_4_,_Dst[2]),_Dst[2]);
      lStack_58 = lStack_48 + (ulonglong)_Dst[1];
    }
  }
  cVar3 = IoIs32bitProcess(param_1);
  iVar4 = DfscGetContainerContextFromIrp(param_1,&local_40);
  if (iVar4 < 0) {
LAB_1400166fd:
    iVar4 = -0x3fffffcc;
  }
  else {
    iVar4 = DfscGetReferralFromPath
                      (param_1,(undefined2 *)0x0,&local_80,local_70,local_40,&local_68,0,local_30);
    lVar7 = local_68;
    if (iVar4 < 0) goto LAB_1400166fd;
    _local_80 = CONCAT62(auStack_7e,local_80 - local_30[0]);
    iVar4 = DfscReferralGetClientInfoSize
                      (local_68,&local_80,iVar8,cVar3 != '\0',&local_50,&local_60,(int *)&local_84);
    if ((-1 < iVar4) && (param_5 < local_84)) {
      if (param_5 < 4) {
        iVar4 = -0x3fffffdd;
        goto LAB_14001679c;
      }
      iVar4 = -0x7ffffffb;
      *(uint *)param_4 = local_84;
      *(undefined8 *)(param_1 + 0x38) = 4;
    }
  }
  uVar2 = local_84;
  if (-1 < iVar4) {
    uVar5 = DfscReferralGetClientInfoMarshall
                      (lVar7,&local_80,local_6c,cVar3 != '\0',&local_50,&local_60,param_4,local_84);
    iVar4 = (int)uVar5;
    if (-1 < iVar4) {
      *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar2;
    }
  }
LAB_14001679c:
  if (_Dst != (ushort *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  if (lVar7 != 0) {
    DfscReferralRelease(lVar7);
  }
  return iVar4;
}



===== DfscFsctrlGetRefCache @ 1400167ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DfscFsctrlGetRefCache(longlong param_1,wchar_t *param_2,uint param_3,int param_4)

{
  longlong lVar1;
  wchar_t *pwVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  wchar_t *pwVar11;
  wchar_t wVar12;
  longlong lVar13;
  undefined8 uVar14;
  uint uVar15;
  longlong lVar16;
  int iVar17;
  wchar_t *_Dst;
  bool bVar18;
  uint local_res10;
  uint local_a8 [2];
  longlong local_a0;
  wchar_t *local_98;
  wchar_t *local_90;
  wchar_t *local_88;
  wchar_t *local_80;
  ulonglong local_78;
  longlong local_70;
  longlong local_68;
  ulonglong local_60;
  longlong local_58;
  longlong local_50;
  ulonglong local_48;
  
  local_a8[0] = 0;
  local_58 = 0;
  local_98 = (wchar_t *)0x0;
  pwVar11 = (wchar_t *)0x0;
  local_80 = (wchar_t *)0x0;
  local_50 = 0;
  local_90 = (wchar_t *)0x0;
  local_88 = (wchar_t *)0x0;
  local_70 = 0;
  local_68 = 0;
  if (param_2 == (wchar_t *)0x0) {
    uVar7 = 0xc000000d;
  }
  else {
    uVar7 = DfscGetContainerContextFromIrp(param_1,&local_68);
    if (-1 < (int)uVar7) {
      lVar8 = DfscGetReferralCache(local_68);
      local_a0 = lVar8;
      cVar3 = IoIs32bitProcess(param_1);
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(lVar8 + 0x38,1);
      uVar9 = DfscGetRefCacheSizeLocked(lVar8,local_a8,cVar3 != '\0',param_4);
      uVar7 = uVar9 & 0xffffffff;
      uVar10 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
      uVar5 = local_a8[0];
      if (((int)uVar10 == 0) || (-1 < (int)uVar9)) {
        uVar7 = (ulonglong)local_a8[0];
        if (param_3 < local_a8[0]) {
          ExReleaseResourceLite(local_a0 + 0x38);
          KeLeaveCriticalRegion();
          if (param_3 < 4) {
            uVar7 = 0xc0000023;
          }
          else {
            *(uint *)param_2 = uVar5;
            uVar7 = 0x80000005;
            *(undefined8 *)(param_1 + 0x38) = 4;
          }
        }
        else {
          local_48 = (ulonglong)param_3;
          memset(param_2,0,(ulonglong)param_3);
          if (cVar3 == '\0') {
            bVar18 = uVar5 < 0x48;
            local_80 = param_2;
          }
          else {
            bVar18 = uVar5 < 0x34;
            local_88 = param_2;
          }
          if (bVar18) {
LAB_14001695c:
            uVar7 = 0xc00000e5;
          }
          else {
            _Dst = (wchar_t *)(uVar7 + (longlong)param_2);
            uVar5 = 0;
            uVar14 = 1;
            local_60 = uVar7;
            while( true ) {
              lVar8 = RtlNextUnicodePrefix(local_a0,uVar14);
              iVar17 = (int)param_2;
              if (lVar8 == 0) break;
              if ((*(byte *)(lVar8 + -0x38) & 1) != 0) {
                if (cVar3 == '\0') {
                  local_98 = local_80 + (ulonglong)uVar5 * 0x20 + 4;
                }
                else {
                  pwVar11 = local_88 + (ulonglong)uVar5 * 0x18 + 2;
                  local_90 = pwVar11;
                }
                if (cVar3 == '\0') {
                  _Dst = _Dst + (ulonglong)*(ushort *)(lVar8 + -0x2c) * -4;
                  if (uVar7 < (ulonglong)((longlong)local_98 + (0x40 - (longlong)param_2)))
                  goto LAB_14001695c;
                  *(ulonglong *)(local_98 + 0x1c) = (ulonglong)(uint)((int)_Dst - iVar17);
                }
                else {
                  _Dst = _Dst + (ulonglong)*(ushort *)(lVar8 + -0x2c) * -2;
                  if (uVar7 < (ulonglong)((longlong)pwVar11 + (0x30 - (longlong)param_2)))
                  goto LAB_14001695c;
                  *(int *)(pwVar11 + 0x16) = (int)_Dst - iVar17;
                }
                uVar5 = uVar5 + 1;
              }
              uVar14 = 0;
            }
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                      &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids);
            }
            local_res10 = 0;
            lVar8 = RtlNextUnicodePrefix(local_a0,1);
            uVar5 = 0;
            if (lVar8 != 0) {
              while( true ) {
                lVar1 = lVar8 + -0x48;
                if ((*(byte *)(lVar8 + -0x38) & 1) != 0) {
                  if (cVar3 == '\0') {
                    local_98 = local_80 + (ulonglong)local_res10 * 0x20 + 4;
                  }
                  else {
                    pwVar11 = local_88 + (ulonglong)local_res10 * 0x18 + 2;
                    local_90 = pwVar11;
                  }
                  pwVar2 = local_98;
                  _Dst = (wchar_t *)
                         ((longlong)_Dst -
                         ((ulonglong)*(ushort *)(lVar8 + 0x48) + 5 & 0xfffffffffffffffc));
                  if (cVar3 == '\0') {
                    if (local_60 < (ulonglong)((longlong)local_98 + (0x40 - (longlong)param_2)))
                    goto LAB_14001695c;
                    uVar7 = (ulonglong)(uint)((int)_Dst - iVar17);
                    *(ulonglong *)local_98 = uVar7;
                    *(ulonglong *)(local_98 + 4) = uVar7;
                  }
                  else {
                    if (local_60 < (ulonglong)((longlong)pwVar11 + (0x30 - (longlong)param_2)))
                    goto LAB_14001695c;
                    iVar4 = (int)_Dst - iVar17;
                    *(int *)pwVar11 = iVar4;
                    *(int *)(pwVar11 + 2) = iVar4;
                  }
                  memmove(_Dst,*(void **)(lVar8 + 0x50),(ulonglong)*(ushort *)(lVar8 + 0x48));
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
                    WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                              &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,lVar1,_Dst);
                  }
                  iVar4 = *(int *)(lVar8 + -0x44) + -1;
                  if (cVar3 == '\0') {
                    *(int *)(pwVar2 + 0xe) = iVar4;
                  }
                  else {
                    *(int *)(pwVar11 + 10) = iVar4;
                  }
                  DfscRmGetReferralTtlTickCounts(lVar1,(longlong *)0x0,&local_58);
                  if (local_58 == 0) {
                    iVar4 = -1;
                  }
                  else {
                    local_78 = 0;
                    DfscRmGetReferralTtlTickCounts(lVar1,(longlong *)&local_78,(longlong *)0x0);
                    uVar7 = local_78;
                    lVar13 = _DAT_fffff78000000320;
                    if (_DAT_fffff78000000320 < (longlong)local_78) {
                      uVar5 = KeQueryTimeIncrement();
                      lVar13 = (ulonglong)uVar5 * (uVar7 - lVar13);
                      lVar13 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar13),8) + lVar13;
                      uVar7 = (lVar13 >> 0x17) - (lVar13 >> 0x3f);
                      iVar4 = (int)uVar7;
                      if (0xfffffffe < uVar7) {
                        iVar4 = -1;
                      }
                    }
                    else {
                      iVar4 = 0;
                    }
                    pwVar11 = local_90;
                  }
                  if (cVar3 == '\0') {
                    *(int *)(local_98 + 0xc) = iVar4;
                  }
                  else {
                    *(int *)(pwVar11 + 8) = iVar4;
                  }
                  if (cVar3 == '\0') {
                    *(uint *)(local_98 + 0x18) = (uint)*(ushort *)(lVar8 + -0x2c);
                  }
                  else {
                    *(uint *)(pwVar11 + 0x14) = (uint)*(ushort *)(lVar8 + -0x2c);
                  }
                  if ((*(short *)(lVar8 + -0x2c) == 0) || ((*(uint *)(lVar8 + 0x58) & 1) == 0)) {
                    uVar5 = 1;
                    if ((*(int *)(lVar8 + -0x3c) == 1) &&
                       (uVar5 = 1, (*(byte *)(lVar8 + -0x38) & 2) != 0)) {
                      uVar5 = 0x81;
                    }
                  }
                  else {
                    uVar5 = 0x10;
                  }
                  uVar15 = uVar5 | 0x8000;
                  if ((*(ushort *)(lVar8 + -0x38) & 4) == 0) {
                    uVar15 = uVar5;
                  }
                  uVar5 = uVar15 | 0x200;
                  if ((*(ushort *)(lVar8 + -0x38) & 1) != 0) {
                    uVar5 = uVar15;
                  }
                  if (cVar3 == '\0') {
                    local_50 = *(ulonglong *)(local_98 + 0x1c) + (longlong)param_2;
                    *(uint *)(local_98 + 8) = uVar5;
                  }
                  else {
                    local_70 = (ulonglong)*(uint *)(local_90 + 0x16) + (longlong)param_2;
                    *(uint *)(local_90 + 4) = uVar5;
                  }
                  uVar15 = 0;
                  if (*(short *)(lVar8 + -0x2c) != 0) {
                    local_78 = 0xfffffffffffffffc;
                    if (param_4 != 0x60140) {
                      local_78 = 0xfffffffffffffffe;
                    }
                    do {
                      uVar7 = (ulonglong)uVar15;
                      lVar16 = uVar7 * 0x70;
                      lVar13 = 0xb;
                      if (param_4 != 0x60140) {
                        lVar13 = 5;
                      }
                      uVar9 = lVar13 + (ulonglong)*(ushort *)(lVar16 + 0x100 + lVar1) & local_78;
                      _Dst = (wchar_t *)((longlong)_Dst - uVar9);
                      if (_Dst < param_2) goto LAB_14001695c;
                      uVar6 = (int)_Dst - iVar17;
                      if (local_48 < uVar6 + uVar9) goto LAB_14001695c;
                      if (cVar3 == '\0') {
                        *(ulonglong *)(local_50 + uVar7 * 8) = (ulonglong)uVar6;
                      }
                      else {
                        *(uint *)(local_70 + uVar7 * 4) = uVar6;
                      }
                      wVar12 = L'\0';
                      if (((uVar5 & 0x10) == 0) && (*(ushort *)(lVar8 + -0x2a) == uVar15)) {
                        wVar12 = L'\x10';
                      }
                      if ((*(uint *)(lVar16 + 0xa0 + lVar1) & 2) != 0) {
                        wVar12 = wVar12 | 0x100;
                      }
                      if (param_4 == 0x60140) {
                        _Dst[2] = wVar12;
                        pwVar11 = _Dst + 3;
                        *(undefined4 *)_Dst = *(undefined4 *)(lVar16 + 0xa8 + lVar1);
                      }
                      else {
                        *_Dst = wVar12;
                        pwVar11 = _Dst + 1;
                      }
                      memmove(pwVar11,*(void **)(lVar16 + 0x108 + lVar1),
                              (ulonglong)*(ushort *)(lVar16 + 0x100 + lVar1));
                      uVar15 = uVar15 + 1;
                    } while (uVar15 < *(ushort *)(lVar8 + -0x2c));
                  }
                  local_res10 = local_res10 + 1;
                }
                lVar8 = RtlNextUnicodePrefix(local_a0,0);
                if (lVar8 == 0) break;
                pwVar11 = local_90;
              }
              uVar7 = (ulonglong)local_a8[0];
              uVar5 = local_res10;
            }
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                      &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids);
            }
            pwVar11 = local_88;
            if (cVar3 == '\0') {
              pwVar11 = local_80;
            }
            *(uint *)pwVar11 = uVar5;
            *(ulonglong *)(param_1 + 0x38) = uVar7;
            uVar7 = 0;
          }
          ExReleaseResourceLite(local_a0 + 0x38);
          KeLeaveCriticalRegion();
        }
      }
      else {
        ExReleaseResourceLite(local_a0 + 0x38);
        KeLeaveCriticalRegion();
      }
    }
  }
  return uVar7;
}



===== DfscFsctrlIsDfsPath @ 140016e84 =====

int DfscFsctrlIsDfsPath(longlong param_1,ushort *param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  longlong local_res10 [2];
  longlong local_res20;
  undefined8 local_28;
  ushort *puStack_20;
  
  local_res20 = 0;
  local_res10[0] = 0;
  if ((((3 < param_3) && (param_2 != (ushort *)0x0)) && (uVar1 = *param_2, uVar1 != 0)) &&
     ((uVar1 & 1) == 0)) {
    puStack_20 = param_2 + 1;
    if ((*puStack_20 != 0) && (uVar1 + 2 <= param_3)) {
      local_28 = (ulonglong)CONCAT22(uVar1,uVar1);
      if (*puStack_20 == 0x5c) {
        uVar2 = uVar1;
        if (((3 < uVar1) && (param_2[2] == 0x5c)) && (puStack_20 != (ushort *)0x0)) {
          puStack_20 = param_2 + 2;
          uVar2 = uVar1 - 2;
          local_28 = (ulonglong)CONCAT22(uVar1 - 2,uVar2);
        }
        if ((uVar2 < 4) || (puStack_20[1] != 0x5c)) {
          iVar3 = DfscGetContainerContextFromIrp(param_1,local_res10);
          if (iVar3 < 0) {
            return iVar3;
          }
          iVar3 = DfscGetReferralFromPath
                            (param_1,(undefined2 *)0x0,(ushort *)&local_28,1,local_res10[0],
                             &local_res20,0,(short *)0x0);
          if (iVar3 < 0) {
            iVar3 = -0x3fffffcc;
          }
          if (local_res20 == 0) {
            return iVar3;
          }
          DfscReferralRelease(local_res20);
          return iVar3;
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== DfscFsctrlSetClientInfo @ 140016fc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DfscFsctrlSetClientInfo(longlong param_1,ushort *param_2,uint param_3)

{
  undefined1 auVar1 [16];
  ushort uVar2;
  ulonglong uVar3;
  undefined1 auVar4 [16];
  int iVar5;
  int iVar6;
  RPC_STATUS RVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ushort uVar11;
  undefined2 uVar12;
  short sVar13;
  uint uVar14;
  undefined8 *puVar15;
  wchar_t *pwVar16;
  short *psVar17;
  char local_res20 [8];
  ushort local_120;
  undefined1 auStack_11e [6];
  short *psStack_118;
  longlong local_110;
  undefined4 local_108;
  wchar_t local_100;
  undefined1 auStack_fe [6];
  ushort *puStack_f8;
  undefined1 local_f0 [16];
  int local_e0;
  longlong local_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  short *psStack_c0;
  undefined8 local_b8;
  short *psStack_b0;
  short local_a8 [4];
  short *psStack_a0;
  short local_98 [4];
  short *psStack_90;
  ulonglong local_88 [2];
  short local_78 [8];
  ushort local_68 [40];
  
  local_108 = 0;
  _local_100 = 0;
  puStack_f8 = (ushort *)0x0;
  _local_120 = 0;
  psStack_118 = (short *)0x0;
  local_b8 = 0;
  psStack_b0 = (short *)0x0;
  local_c8 = 0;
  psStack_c0 = (short *)0x0;
  local_f0 = ZEXT816(0);
  local_110 = 0;
  memset(local_78,0,0x60);
  local_res20[0] = '\0';
  local_d0 = 0;
  local_d8 = 0;
  if ((param_2 == (ushort *)0x0) || (param_3 < 0x14)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
               &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,param_3);
    }
    iVar5 = -0x3ffffff3;
    *(undefined8 *)(param_1 + 0x38) = 0;
    goto LAB_14001793c;
  }
  RtlInitUnicodeString(&local_120,0);
  RtlInitUnicodeString(&local_100,0);
  RtlInitUnicodeString(&local_b8,0);
  uVar14 = 0;
  uVar11 = 0;
  local_e0 = *(int *)(param_2 + 4);
  if (local_e0 == 0x65) {
    if (*(int *)(param_2 + 6) == 4) {
      uVar14 = (uint)param_2[1];
      if (param_2[1] == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
          uVar12 = 0x2a;
          goto LAB_140017124;
        }
      }
      else {
        uVar11 = param_2[2];
        if (uVar11 != 0) goto LAB_14001717a;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
          uVar12 = 0x2b;
          goto LAB_140017124;
        }
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
      uVar12 = 0x29;
      iVar5 = *(int *)(param_2 + 6);
      goto LAB_1400170dc;
    }
  }
  else if (local_e0 == 0x66) {
    local_108 = *(undefined4 *)(param_2 + 6);
LAB_14001717a:
    uVar2 = *param_2;
    if ((uVar2 & 1) == 0) {
      if ((uVar14 & 1) == 0) {
        if ((uVar11 & 1) == 0) {
          sVar13 = (short)uVar14;
          if (param_3 - 0x10 < (uint)uVar11 + (uint)uVar2 + uVar14) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
              uVar12 = 0x30;
              goto LAB_140017124;
            }
          }
          else {
            _local_100 = CONCAT62(CONCAT42(auStack_fe._2_4_,uVar2),uVar2);
            puStack_f8 = param_2 + 8;
            if ((((4 < uVar2) && (*puStack_f8 == 0x5c)) && (param_2[9] == 0x5c)) &&
               (puStack_f8 != (ushort *)0x0)) {
              _local_100 = CONCAT22(uVar2 - 2,uVar2 - 2);
              puStack_f8 = param_2 + 9;
            }
            if (sVar13 == 0) goto LAB_14001740d;
            local_a8[0] = 0;
            local_a8[1] = 0;
            local_a8[2] = 0;
            local_a8[3] = 0;
            psStack_a0 = (short *)0x0;
            local_98[0] = 0;
            local_98[1] = 0;
            local_98[2] = 0;
            local_98[3] = 0;
            psStack_90 = (short *)0x0;
            psVar17 = (short *)((ulonglong)uVar2 + 0x10 + (longlong)param_2);
            _local_120 = CONCAT62(CONCAT42(auStack_11e._2_4_,sVar13),sVar13);
            psStack_118 = psVar17;
            RtlInitUnicodeStringEx(local_a8,0);
            RtlInitUnicodeStringEx(local_98,0);
            if (((3 < local_120) && (*psStack_118 == 0x5c)) &&
               ((psStack_118[1] == 0x5c && (2 < local_120)))) {
              _local_120 = CONCAT22(auStack_11e._0_2_ + -2,local_120 - 2);
              psStack_118 = psStack_118 + 1;
            }
            uVar8 = DfscGetPathComponents(&local_120,local_a8,local_98,(short *)0x0,(short *)0x0);
            if (-1 < (int)uVar8) {
              if (((local_a8[0] != 0) && (psStack_a0 != (short *)0x0)) &&
                 ((*psStack_a0 != 0 &&
                  (((local_98[0] == 0 || (psStack_90 == (short *)0x0)) || (*psStack_90 == 0)))))) {
                psVar17 = (short *)((longlong)psVar17 + (ulonglong)param_2[1]);
                if (uVar11 != 0) {
                  local_b8 = CONCAT62(CONCAT42(local_b8._4_4_,uVar11),uVar11);
                  psStack_b0 = psVar17;
                  if (*psVar17 == 0x5c) goto LAB_1400170ec;
                }
LAB_14001740d:
                local_88[0] = 0;
                local_88[1] = 0;
                iVar5 = DfscGetContainerContextFromIrp(param_1,&local_d8);
                if (iVar5 < 0) goto LAB_14001793c;
                pwVar16 = &local_100;
                puVar15 = (undefined8 *)0x0;
                iVar5 = DfscGetReferralFromPath
                                  (param_1,(undefined2 *)0x0,(ushort *)pwVar16,3,local_d8,&local_110
                                   ,0,(short *)local_88);
                if (iVar5 < 0) {
                  iVar5 = -0x3fffffcc;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)) {
                    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                             &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,param_1);
                  }
                  goto LAB_14001793c;
                }
                uVar3 = *(ulonglong *)(local_110 + 0x10);
                local_88[0] = uVar3;
                if (local_e0 == 0x66) {
                  *(undefined4 *)(uVar3 + 0x28) = local_108;
                  *(undefined8 *)(uVar3 + 0x20) = _DAT_fffff78000000320;
                  iVar5 = 0;
                  goto LAB_14001793c;
                }
                if (((*(int *)(uVar3 + 0xc) == 0) && (*(short *)(uVar3 + 0x1c) == 0)) &&
                   ((iVar5 = -0x3fffffcc, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)))) {
                  puVar15 = (undefined8 *)0x32;
                  pwVar16 = L"톉\xf31a겵㞷䈬\xeb26鷚\xe69c牔湡灳牯䥴普o";
                  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                           &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,param_1);
                }
                uVar11 = local_120;
                if (((2 < local_120) && (psStack_118 != (short *)0x0)) && (*psStack_118 == 0x5c)) {
                  psStack_118 = psStack_118 + 1;
                  uVar11 = local_120 - 2;
                  _local_120 = CONCAT22(auStack_11e._0_2_ + -2,uVar11);
                }
                if (uVar11 == 0) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
                    uVar12 = 0x33;
LAB_140017124:
                    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                             &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,param_1);
                  }
                }
                else {
                  if ((short)local_b8 != 0) {
                    do {
                      do {
                        if (iVar5 != 0) goto LAB_140017682;
                        uVar8 = DfscReferralIterate(local_110);
                        iVar5 = (int)uVar8;
                        if (iVar5 != 0) {
                          if (iVar5 != -0x7fffffe6) {
                            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)) {
                              WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar15,pwVar16,
                                        iVar5,(char)param_1);
                            }
                            goto LAB_14001767a;
                          }
                          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
                            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                                     &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,param_1);
                          }
                          iVar5 = -0x3fffffcc;
                          goto LAB_140017682;
                        }
                        lVar10 = DfscReferralGetCurrentTarget(local_110);
                        psStack_c0 = *(short **)(lVar10 + 0x28);
                        uVar11 = (*(short *)(lVar10 + 0x68) + *(short *)(lVar10 + 0x60)) -
                                 *(short *)(lVar10 + 0x28);
                        uVar9 = (ulonglong)uVar11;
                        local_c8._0_4_ = CONCAT22(uVar11,uVar11);
                        auVar1 = *(undefined1 (*) [16])(lVar10 + 0x10);
                        if (2 < auVar1._0_2_) {
                          local_f0._8_8_ = auVar1._8_8_;
                          if (((short *)local_f0._8_8_ != (short *)0x0) &&
                             (*(short *)local_f0._8_8_ == 0x5c)) {
                            local_f0._0_8_ = auVar1._0_8_;
                            local_f0._8_8_ = (short *)(local_f0._8_8_ + 2);
                            auVar4 = local_f0;
                            local_f0._2_2_ = auVar1._2_2_;
                            local_f0._4_12_ = auVar4._4_12_;
                            local_f0._2_2_ = local_f0._2_2_ + -2;
                            local_f0._0_2_ = auVar1._0_2_ - 2;
                            auVar1 = local_f0;
                          }
                        }
                        local_f0 = auVar1;
                        if (((2 < uVar11) && (psStack_c0 != (short *)0x0)) && (*psStack_c0 == 0x5c))
                        {
                          psStack_c0 = psStack_c0 + 1;
                          uVar9 = (ulonglong)(ushort)(uVar11 - 2);
                          local_c8._0_4_ = CONCAT22(uVar11 - 2,uVar11 - 2);
                        }
                        pwVar16 = (wchar_t *)CONCAT71((int7)(uVar9 >> 8),1);
                        puVar15 = (undefined8 *)local_f0;
                        iVar6 = RtlCompareUnicodeString(&local_120);
                      } while (iVar6 != 0);
                      pwVar16 = (wchar_t *)CONCAT71((int7)((ulonglong)pwVar16 >> 8),1);
                      puVar15 = &local_c8;
                      iVar6 = RtlCompareUnicodeString(&local_b8);
                    } while (iVar6 != 0);
                    *(undefined2 *)(*(longlong *)(local_110 + 0x10) + 0x1e) =
                         *(undefined2 *)(local_110 + 0x20);
                    *(undefined1 *)(uVar3 + 0x12) = 1;
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)) {
                      WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                                &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,(wchar_t *)local_f0
                                ,(char)param_1);
                    }
LAB_14001767a:
                    if (iVar5 != 0) {
LAB_140017682:
                      uVar9 = DfscInitDfsPath(&local_100,local_78);
                      if ((((int)uVar9 == 0) &&
                          (uVar8 = DfscIsSpecialShare(local_68), (char)uVar8 != '\0')) &&
                         (iVar6 = RtlCompareUnicodeString(local_68,&local_b8,1), iVar6 == 0)) {
                        RVar7 = DfscIsDomainController(local_78,&local_120,local_res20);
                        if ((RVar7 == 0) && (local_res20[0] != '\0')) {
                          uVar9 = DfscRmGenerateSysvolNetlogonReferral
                                            ((longlong)local_78,&local_120,1,&local_d0);
                          RVar7 = (RPC_STATUS)uVar9;
                          if (RVar7 == 0) {
                            local_d0 = DfscRefCacheStore(local_d8,uVar3,local_d0);
                            DfscRmDereferenceReferral(local_d0);
                          }
                        }
                        if ((RVar7 != 0) || (iVar5 = 0, local_res20[0] == '\0')) {
                          iVar5 = -0x3fffffcc;
                        }
                      }
                    }
                    goto LAB_14001793c;
                  }
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
                    uVar12 = 0x34;
                    goto LAB_140017124;
                  }
                }
              }
            }
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
          uVar12 = 0x2f;
          goto LAB_140017124;
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
        uVar12 = 0x2e;
        goto LAB_140017124;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
      uVar12 = 0x2d;
      goto LAB_140017124;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x14 & 1) != 0)) {
    uVar12 = 0x2c;
    iVar5 = local_e0;
LAB_1400170dc:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
             &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,iVar5);
  }
LAB_1400170ec:
  iVar5 = -0x3ffffff3;
LAB_14001793c:
  if (local_110 != 0) {
    DfscReferralRelease(local_110);
  }
  return iVar5;
}



===== DfscFsctrlSetClusterSetName @ 140017978 =====

ulonglong DfscFsctrlSetClusterSetName(longlong param_1,uint *param_2,undefined *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong *plVar8;
  wchar_t *pwVar9;
  uint uVar10;
  uint uVar11;
  ulonglong *puVar12;
  ulonglong local_res10;
  longlong local_res20;
  wchar_t local_38 [4];
  longlong lStack_30;
  ushort local_28 [4];
  longlong lStack_20;
  
  local_res10 = 0;
  local_res20 = 0;
  uVar11 = (uint)param_3;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  lStack_20 = 0;
  local_38[0] = L'\0';
  local_38[1] = L'\0';
  local_38[2] = L'\0';
  local_38[3] = L'\0';
  lStack_30 = 0;
  if ((uVar11 == 0) || (*param_2 == 0)) {
    uVar5 = 0xc000000d;
  }
  else {
    plVar8 = &local_res20;
    uVar5 = DfscGetContainerContextFromIrp(param_1,plVar8);
    if (-1 < (int)uVar5) {
      lVar6 = DfscGetReferralCache(local_res20);
      if ((char)param_2[1] != '\0') {
        DfscClusterSetCachePurge(lVar6,plVar8,param_3);
      }
      uVar7 = 0;
      uVar5 = uVar5 & 0xffffffff;
      while (uVar10 = (uint)uVar7, uVar10 < *param_2) {
        uVar3 = param_2[uVar7 * 5 + 3];
        uVar1 = (ushort)param_2[uVar7 * 5 + 4];
        if (uVar1 + uVar3 < uVar3) {
LAB_140017ad0:
          uVar5 = 0xc0000095;
          break;
        }
        uVar4 = param_2[uVar7 * 5 + 5];
        uVar2 = (ushort)param_2[uVar7 * 5 + 6];
        if (uVar2 + uVar4 < uVar4) goto LAB_140017ad0;
        if ((uVar11 < uVar1 + uVar3) || (uVar11 < uVar2 + uVar4)) {
          uVar5 = 0xc000000d;
          break;
        }
        lStack_20 = (ulonglong)uVar3 + (longlong)param_2;
        pwVar9 = local_38;
        lStack_30 = (longlong)param_2 + (ulonglong)uVar4;
        local_28[1] = uVar1;
        local_28[0] = uVar1;
        puVar12 = &local_res10;
        local_38[1] = uVar2;
        local_38[0] = uVar2;
        uVar7 = DfscRmGenerateClusterSetReferralFromName(local_28,pwVar9,puVar12);
        uVar5 = uVar7 & 0xffffffff;
        if ((int)uVar7 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar9,puVar12,uVar10,(char)uVar7);
          }
          DfscRmDereferenceReferral(local_res10);
          break;
        }
        local_res10 = DfscRefCacheStore(local_res20,local_res10,local_res10);
        DfscRmDereferenceReferral(local_res10);
        uVar7 = (ulonglong)(uVar10 + 1);
      }
    }
  }
  return uVar5;
}



===== DfscFsctrlSpecialSetDc @ 140017afc =====

RPC_STATUS DfscFsctrlSpecialSetDc(longlong param_1,ushort *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  RPC_STATUS RVar3;
  ushort uVar4;
  ushort *puVar5;
  ushort *puVar6;
  longlong local_res20;
  ushort local_38;
  undefined1 auStack_36 [6];
  ulonglong uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  _local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  cVar1 = IoIs32bitProcess();
  local_res20 = 0;
  if (cVar1 == '\0') {
    if (param_3 < 0x20) {
      return -0x3ffffff3;
    }
    uVar4 = *param_2;
    puVar6 = param_2;
  }
  else {
    if (param_3 < 0x10) {
      return -0x3ffffff3;
    }
    uVar4 = *param_2;
    uStack_30 = (ulonglong)*(uint *)(param_2 + 2);
    local_28 = CONCAT44(local_28._4_4_,*(undefined4 *)(param_2 + 4));
    uStack_20 = (ulonglong)*(uint *)(param_2 + 6);
    _local_38 = CONCAT62(CONCAT42(auStack_36._2_4_,param_2[1]),uVar4);
    puVar6 = &local_38;
  }
  puVar5 = (ushort *)(*(longlong *)(puVar6 + 4) + (longlong)param_2);
  *(ushort **)(puVar6 + 4) = puVar5;
  if (((uVar4 <= param_3) && (param_2 <= puVar5)) &&
     (puVar5 <= (ushort *)((ulonglong)(param_3 - uVar4) + (longlong)param_2))) {
    puVar5 = (ushort *)(*(longlong *)(puVar6 + 0xc) + (longlong)param_2);
    *(ushort **)(puVar6 + 0xc) = puVar5;
    if (((puVar6[8] <= param_3) && (param_2 <= puVar5)) &&
       (puVar5 <= (ushort *)((ulonglong)(param_3 - puVar6[8]) + (longlong)param_2))) {
      iVar2 = DfscGetContainerContextFromIrp(param_1,&local_res20);
      if (iVar2 < 0) {
        return iVar2;
      }
      RVar3 = DfscSetActiveDcForDomain(local_res20,puVar6,(wchar_t *)(puVar6 + 8));
      return RVar3;
    }
  }
  return -0x3ffffff3;
}



===== DfscGetActiveDcInfo @ 140017c18 =====

undefined8 DfscGetActiveDcInfo(longlong param_1,uint *param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  ushort uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  lVar1 = DfscGetCurrentDcContext(param_4);
  if (lVar1 == 0) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar2 = 0x8000001a;
  }
  else if ((param_2 == (uint *)0x0) || (param_3 == 0)) {
    uVar2 = 0xc000000d;
  }
  else {
    if (*(longlong *)(lVar1 + 8) == 0) {
      uVar3 = 0;
    }
    else {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (*(short *)(*(longlong *)(lVar1 + 8) + lVar4 * 2) != 0);
      uVar3 = (short)lVar4 * 2;
    }
    uVar6 = (uint)uVar3 + *(ushort *)(lVar1 + 0x20) + 0xe + (uint)*(ushort *)(lVar1 + 0x10);
    if (param_3 < uVar6) {
      DfscReleaseDcContext(lVar1);
      if (param_3 < 4) {
        uVar2 = 0xc0000023;
      }
      else {
        *param_2 = uVar6;
        uVar2 = 0x80000005;
        *(undefined8 *)(param_1 + 0x38) = 4;
      }
    }
    else {
      memset(param_2,0,(ulonglong)param_3);
      *(undefined2 *)param_2 = 0x2a;
      puVar5 = (undefined4 *)((longlong)param_2 + 2);
      if (uVar3 != 0) {
        memmove(puVar5,*(void **)(lVar1 + 8),(ulonglong)uVar3);
        puVar5 = (undefined4 *)((longlong)puVar5 + (ulonglong)(uVar3 >> 1) * 2);
      }
      *puVar5 = 0x2a0000;
      memmove(puVar5 + 1,*(void **)(lVar1 + 0x28),(ulonglong)*(ushort *)(lVar1 + 0x20));
      puVar5 = (undefined4 *)
               ((longlong)(puVar5 + 1) + (ulonglong)(*(ushort *)(lVar1 + 0x20) >> 1) * 2);
      *puVar5 = 0x2a0000;
      memmove(puVar5 + 1,*(void **)(lVar1 + 0x18),(ulonglong)*(ushort *)(lVar1 + 0x10));
      *(undefined4 *)((longlong)puVar5 + (ulonglong)(*(ushort *)(lVar1 + 0x10) >> 1) * 2 + 4) = 0;
      DfscReleaseDcContext(lVar1);
      *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar6;
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== DfscGetDomainCacheNames @ 140017d94 =====

int DfscGetDomainCacheNames(longlong param_1,longlong param_2,uint *param_3,uint param_4)

{
  longlong lVar1;
  short *psVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  iVar4 = 0;
  KeEnterCriticalRegion();
  lVar1 = param_1 + 0x38;
  ExAcquireResourceExclusiveLite(lVar1,1);
  uVar5 = 2;
  while (lVar3 = RtlNextUnicodePrefix(param_1), lVar3 != 0) {
    if ((*(byte *)(lVar3 + -0x38) & 1) != 0) {
      uVar5 = uVar5 + 4 + (uint)*(ushort *)(lVar3 + 0x48);
    }
  }
  if (param_4 < uVar5) {
    if (param_4 < 4) {
      iVar4 = -0x3fffffdd;
    }
    else {
      *param_3 = uVar5;
      iVar4 = -0x7ffffffb;
      *(undefined8 *)(param_2 + 0x38) = 4;
    }
    ExReleaseResourceLite(lVar1);
    KeLeaveCriticalRegion();
  }
  else {
    memset(param_3,0,(ulonglong)param_4);
    puVar6 = param_3;
    while (lVar3 = RtlNextUnicodePrefix(param_1), lVar3 != 0) {
      if ((*(byte *)(lVar3 + -0x38) & 1) != 0) {
        *(ushort *)puVar6 = (-(ushort)(*(short *)(lVar3 + -0x2c) != 0) & 0xfffe) + 0x2d;
        if ((ulonglong)param_4 + (longlong)param_3 <
            ((ulonglong)*(ushort *)(lVar3 + 0x48) & 0xfffffffffffffffe) + 6 + (longlong)puVar6) {
          iVar4 = -0x7ffffffb;
          break;
        }
        memmove((short *)((longlong)puVar6 + 2),*(void **)(lVar3 + 0x50),
                (ulonglong)*(ushort *)(lVar3 + 0x48));
        psVar2 = (short *)((longlong)puVar6 + 2) + (*(ushort *)(lVar3 + 0x48) >> 1);
        *psVar2 = 0;
        puVar6 = (uint *)(psVar2 + 1);
      }
    }
    *(short *)puVar6 = 0;
    ExReleaseResourceLite(lVar1);
    KeLeaveCriticalRegion();
    if (-1 < iVar4) {
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar5;
    }
  }
  return iVar4;
}



===== DfscGetRefCacheSizeLocked @ 140017f38 =====

undefined8 DfscGetRefCacheSizeLocked(undefined8 param_1,uint *param_2,char param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  uVar8 = 0;
  iVar10 = 0;
  uVar7 = 1;
  while( true ) {
    uVar5 = 0;
    lVar4 = RtlNextUnicodePrefix(param_1,uVar7);
    if (lVar4 == 0) break;
    if ((*(byte *)(lVar4 + -0x38) & 1) != 0) {
      uVar3 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
      uVar9 = (*(ushort *)(lVar4 + 0x48) + 5 & 0xfffffffc) + uVar8;
      if (((int)uVar3 != 0) && (uVar9 < uVar8)) goto LAB_1400180f8;
      if (param_3 == '\0') {
        uVar3 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
        iVar1 = (int)uVar3;
        uVar6 = *(ushort *)(lVar4 + -0x2c);
        iVar2 = (uint)uVar6 * 8;
      }
      else {
        uVar3 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
        iVar1 = (int)uVar3;
        uVar6 = *(ushort *)(lVar4 + -0x2c);
        iVar2 = (uint)uVar6 * 4;
      }
      uVar8 = uVar9 + iVar2;
      if ((iVar1 != 0) && (uVar8 < uVar9)) goto LAB_1400180f8;
      if (uVar6 != 0) {
        uVar9 = 3;
        if (param_4 != 0x60140) {
          uVar9 = 1;
        }
        uVar11 = uVar8;
        do {
          iVar2 = 0xc;
          if (param_4 != 0x60140) {
            iVar2 = 6;
          }
          uVar8 = ((uint)*(ushort *)(uVar5 * 0x70 + 0xb8 + lVar4) + iVar2 + -1 & ~uVar9) + uVar11;
          uVar3 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar3 != 0) && (uVar8 < uVar11)) goto LAB_1400180f8;
          uVar12 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar12;
          uVar11 = uVar8;
        } while (uVar12 < *(ushort *)(lVar4 + -0x2c));
      }
      iVar10 = iVar10 + 1;
    }
    uVar7 = 0;
  }
  if (param_3 == '\0') {
    uVar9 = iVar10 * 0x40 + 8 + uVar8;
    uVar5 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar5 == 0) || (uVar8 <= uVar9)) {
      if ((uVar9 & 7) != 0) {
        uVar9 = uVar9 + 8 & 0xfffffff8;
      }
      if (uVar9 < 0x48) {
        uVar9 = 0x48;
      }
      goto LAB_1400180d9;
    }
  }
  else {
    uVar9 = iVar10 * 0x30 + 4 + uVar8;
    uVar5 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar5 == 0) || (uVar8 <= uVar9)) {
      if ((uVar9 & 3) != 0) {
        uVar9 = uVar9 + 4 & 0xfffffffc;
      }
      if (uVar9 < 0x34) {
        uVar9 = 0x34;
      }
LAB_1400180d9:
      *param_2 = uVar9;
      return 0;
    }
  }
LAB_1400180f8:
  *param_2 = 0;
  return 0xc0000095;
}



===== DfscImpersonateLinkedToken @ 14001810c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscImpersonateLinkedToken(undefined8 *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 auStack_d8 [32];
  undefined4 *local_b8;
  longlong *local_b0;
  undefined4 local_a8;
  int local_a4;
  longlong local_a0;
  longlong local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar1 = *param_1;
  local_a0 = 0;
  local_a8 = 0;
  local_98 = 0;
  local_a4 = 0;
  local_20 = 0;
  local_70 = 0;
  local_68 = (undefined8 *)((ulonglong)local_68 & 0xffffffff00000000);
  local_60 = 0;
  local_58 = 0;
  local_b8 = &local_a8;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  iVar2 = ZwQueryInformationToken(uVar1,10,&local_50);
  if (-1 < iVar2) {
    local_b8 = &local_a8;
    iVar2 = ZwQueryInformationToken(uVar1,0x12,&local_a4);
    if (-1 < iVar2) {
      if (local_a4 == 1) {
        iVar2 = -0x3fffffdc;
      }
      else {
        local_b8 = &local_a8;
        iVar2 = ZwQueryInformationToken(uVar1,0x13,&local_98);
        if (-1 < iVar2) {
          uStack_88 = 0;
          local_68 = &local_60;
          local_80 = 0;
          local_70 = 0;
          local_b0 = &local_a0;
          local_58 = CONCAT22(local_58._2_2_,1);
          local_60 = 0x20000000c;
          local_b8 = (undefined4 *)CONCAT44(local_b8._4_4_,2);
          local_90 = CONCAT44(local_90._4_4_,0x30);
          uStack_78 = CONCAT44(uStack_78._4_4_,0x200);
          iVar2 = ZwDuplicateToken(local_98,0xc,&local_90,0);
          if (-1 < iVar2) {
            iVar2 = ZwSetInformationThread(0xfffffffffffffffe,5,&local_a0);
          }
        }
      }
    }
  }
  if (local_a0 != 0) {
    ZwClose();
  }
  if (local_98 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== DfscRevert @ 1400182ec =====

void DfscRevert(void)

{
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  ZwSetInformationThread(0xfffffffffffffffe,5,local_res8);
  if (local_res8[0] != 0) {
    ZwClose();
  }
  return;
}



===== DfscSetActiveDcForDomain @ 140018340 =====

RPC_STATUS DfscSetActiveDcForDomain(longlong param_1,ushort *param_2,wchar_t *param_3)

{
  int iVar1;
  RPC_STATUS RVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  longlong lVar7;
  char local_res20 [8];
  ulonglong local_38 [2];
  
  lVar7 = 0;
  local_38[0] = 0;
  local_res20[0] = '\0';
  lVar3 = DfscGetDomainCache(param_1);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar3 + 0x38,1);
  lVar4 = RtlFindUnicodePrefix(lVar3,param_2,0);
  if (lVar4 != 0) {
    lVar7 = lVar4 + -0x48;
    if ((*(byte *)(lVar4 + -0x38) & 1) == 0) {
      lVar7 = 0;
    }
    else {
      LOCK();
      *(int *)(lVar4 + -0x44) = *(int *)(lVar4 + -0x44) + 1;
      UNLOCK();
    }
  }
  ExReleaseResourceLite(lVar3 + 0x38);
  KeLeaveCriticalRegion();
  if (lVar7 == 0) {
    RVar2 = -0x3ffffddb;
  }
  else {
    for (uVar6 = 0; uVar6 < *(ushort *)(lVar7 + 0x1c); uVar6 = uVar6 + 1) {
      iVar1 = RtlCompareUnicodeString((ulonglong)uVar6 * 0x70 + 0x100 + lVar7,param_3,1);
      if (iVar1 == 0) {
        *(ushort *)(lVar7 + 0x1e) = uVar6;
        RVar2 = 0;
        *(undefined1 *)(lVar7 + 0x12) = 1;
        goto LAB_14001848f;
      }
    }
    RVar2 = DfscIsDomainController(param_2,param_3,local_res20);
    if ((-1 < RVar2) && (local_res20[0] != '\0')) {
      uVar5 = DfscRmGenerateDomainDcReferralFromDCName(param_2,param_3,local_38,1,1);
      RVar2 = (RPC_STATUS)uVar5;
      if (-1 < RVar2) {
        lVar3 = DfscDomainCacheStore(param_1,local_38[0]);
        DfscRmDereferenceReferral(lVar3);
      }
    }
LAB_14001848f:
    DfscRmDereferenceReferral(lVar7);
  }
  return RVar2;
}



===== DfscNetUseAdd @ 1400184c0 =====

int DfscNetUseAdd(longlong param_1,uint param_2,int *param_3,wchar_t *param_4,int *param_5,
                 undefined4 *param_6,longlong param_7,undefined4 param_8,uint *param_9,
                 undefined1 *param_10)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  int *piVar10;
  undefined *puVar11;
  longlong local_res8;
  undefined4 local_res10;
  longlong local_88;
  undefined8 local_80;
  undefined8 local_78;
  int local_70 [5];
  undefined1 auStack_5c [4];
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  local_res8 = 0;
  local_78 = 0;
  *param_10 = 0;
  local_res10 = 0;
  lVar3 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  stack0xffffffffffffffa0 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (param_6 == (undefined4 *)0x0) {
    pwVar9 = param_4;
    local_80 = DfscGetDevicelessNetUseTable(param_1);
    local_70[0] = *(int *)(pwVar9 + 0x28);
    local_70[1] = *(int *)(pwVar9 + 0x2a);
    local_70[2] = *(int *)(pwVar9 + 0x2c);
    local_70[3] = *(int *)(pwVar9 + 0x2e);
  }
  else {
    puVar7 = param_6;
    local_80 = DfscGetDriveLetterNetUseTable(param_1);
    local_70[0] = *puVar7;
    local_70[1] = puVar7[1];
    local_70[2] = puVar7[2];
    local_70[3] = puVar7[3];
    uStack_48 = CONCAT44(uStack_48._4_4_,1);
  }
  RtlCopyLuid(auStack_5c,param_3);
  stack0xffffffffffffffa0 = CONCAT44(auStack_5c,param_2);
  KeEnterCriticalRegion();
  puVar11 = &DAT_14000d6e0;
  puVar6 = (undefined *)(param_1 + 0x98);
  if (param_1 == 0) {
    puVar6 = &DAT_14000d6e0;
  }
  ExAcquireResourceExclusiveLite(puVar6,1);
  lVar2 = DfscGetCredTable(param_1);
  piVar10 = param_3;
  iVar1 = DfscCredGetKeymgrCredentials(lVar2,param_2,param_3,param_4,param_7,&local_res8);
  if (iVar1 == 0) {
    piVar10 = (int *)&local_78;
    pwVar9 = (wchar_t *)local_70;
    lVar3 = DfscNetUseTableLookup(local_80,pwVar9,(longlong)piVar10);
    local_88 = lVar3;
    if (lVar3 != 0) {
      param_5 = piVar10;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
        param_5 = (int *)(lVar3 + 0x58);
        pwVar9 = (wchar_t *)0xb;
        WPP_SF_qZq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,param_5,lVar3,(wchar_t *)param_5,
                   (char)*(undefined8 *)(lVar3 + 0x70));
      }
      lVar2 = local_res8;
      if ((local_res8 != 0) && (*(longlong *)(lVar3 + 0x70) == 0)) {
        LOCK();
        *(int *)(local_res8 + 4) = *(int *)(local_res8 + 4) + 1;
        UNLOCK();
        *(longlong *)(lVar3 + 0x70) = local_res8;
        lVar3 = local_88;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
          WPP_SF_qZqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar9,param_5,local_88,
                      (wchar_t *)(local_88 + 0x58),(char)local_res8,0);
        }
      }
      iVar1 = DfscTransportConflictDetect(lVar3,param_9);
      goto LAB_14001879b;
    }
    uVar4 = DfscGetDriveLetterNetUseTable(param_1);
    piVar10 = (int *)(ulonglong)param_2;
    iVar1 = DfscNetUseTableConflictDetect(uVar4,param_7,piVar10,param_3,param_9);
    if (iVar1 == 0) {
      uVar4 = DfscGetDevicelessNetUseTable(param_1);
      piVar10 = (int *)(ulonglong)param_2;
      iVar1 = DfscNetUseTableConflictDetect(uVar4,param_7,piVar10,param_3,param_9);
      lVar2 = local_res8;
      if (iVar1 == 0) {
        uVar5 = DfscNetUseCreate((longlong)param_4,(longlong)param_6,(longlong)param_5,local_res8,
                                 param_8,param_9,&local_88);
        lVar3 = local_88;
        iVar1 = (int)uVar5;
        if (iVar1 == 0) {
          param_5 = local_70;
          lVar8 = local_88;
          uVar4 = DfscNetUseTableStore(local_80,local_88,param_5,local_78,local_res10);
          iVar1 = (int)uVar4;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
            WPP_SF_qZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar8,param_5,lVar3,param_4 + 0x28
                       ,(char)uVar4);
          }
          if (iVar1 == 0) {
            *param_10 = 1;
          }
        }
        goto LAB_14001879b;
      }
    }
  }
  param_5 = piVar10;
  lVar2 = local_res8;
LAB_14001879b:
  if (lVar2 != 0) {
    DfscCredRelease(lVar2);
  }
  if (lVar3 != 0) {
    DfscNetUseRelease(param_1,lVar3,CONCAT71((int7)((ulonglong)param_5 >> 8),iVar1 != 0),'\0');
  }
  if (param_1 != 0) {
    puVar11 = (undefined *)(param_1 + 0x98);
  }
  ExReleaseResourceLite(puVar11);
  KeLeaveCriticalRegion();
  return iVar1;
}



===== DfscNetUseCreate @ 14001880c =====

ulonglong DfscNetUseCreate(longlong param_1,longlong param_2,longlong param_3,longlong param_4,
                          undefined4 param_5,uint *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  uint uVar2;
  undefined2 *_Dst;
  ulonglong uVar3;
  uint *puVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  void *_Dst_00;
  undefined8 *puVar9;
  wchar_t local_38;
  ushort local_36;
  undefined4 local_34;
  void *local_30;
  
  local_34 = 0;
  uVar7 = *(ushort *)(param_1 + 0x50) + 0xb2;
  if (param_6 == (uint *)0x0) {
LAB_140018925:
    _Dst = (undefined2 *)ExAllocatePool2(0x102,uVar7,0x45436644);
    if (_Dst == (undefined2 *)0x0) {
      uVar8 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)uVar7);
      _Dst[1] = (short)uVar7;
      *_Dst = 0x8108;
      _Dst_00 = (void *)((longlong)_Dst + 0xb1U & 0xfffffffffffffffe);
      *(undefined4 *)(_Dst + 2) = 1;
      local_38 = *(wchar_t *)(param_1 + 0x50);
      local_30 = _Dst_00;
      memmove(_Dst_00,*(void **)(param_1 + 0x58),(ulonglong)(ushort)local_38);
      *(undefined2 *)((longlong)local_30 + (ulonglong)((ushort)local_38 >> 1) * 2) = 0;
      local_36 = local_38 + L'\x02';
      puVar9 = (undefined8 *)((ulonglong)local_36 + 0xf + (longlong)_Dst_00 & 0xfffffffffffffff0);
      uVar3 = DfscInitDfsPath(&local_38,_Dst + 4);
      uVar8 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        if (param_2 == 0) {
          _Dst[0x34] = 0;
        }
        else {
          memmove(_Dst + 0x34,*(void **)(param_2 + 8),(ulonglong)*(ushort *)(param_2 + 2));
        }
        if (param_4 != 0) {
          LOCK();
          *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + 1;
          UNLOCK();
          *(longlong *)(_Dst + 0x38) = param_4;
        }
        if (param_3 != 0) {
          *(longlong *)(_Dst + 0x44) = param_3;
        }
        *(undefined4 *)(_Dst + 0x4a) = param_5;
        if (param_6 != (uint *)0x0) {
          *(undefined8 **)(_Dst + 0x54) = puVar9;
          uVar1 = *(undefined8 *)(param_6 + 2);
          *puVar9 = *(undefined8 *)param_6;
          puVar9[1] = uVar1;
          memmove((void *)((ulonglong)**(uint **)(_Dst + 0x54) + (longlong)*(uint **)(_Dst + 0x54)),
                  (void *)((ulonglong)*param_6 + (longlong)param_6),(ulonglong)param_6[1]);
        }
        *(undefined4 *)(_Dst + 0x4c) = 0;
        *(undefined1 *)(_Dst + 0x4e) = 0;
        if ((((param_6 != (uint *)0x0) &&
             (puVar4 = DfscFindEa((uint *)((ulonglong)*param_6 + (longlong)param_6)),
             puVar4 != (uint *)0x0)) && (*(short *)((longlong)puVar4 + 6) == 0x10)) &&
           (*(int *)((ulonglong)*(byte *)((longlong)puVar4 + 5) + 9 + (longlong)puVar4) != 0)) {
          puVar9 = (undefined8 *)((ulonglong)*(byte *)((longlong)puVar4 + 5) + 9 + (longlong)puVar4)
          ;
          uVar1 = puVar9[1];
          *(undefined8 *)(_Dst + 0x4c) = *puVar9;
          *(undefined8 *)(_Dst + 0x50) = uVar1;
        }
        *param_7 = _Dst;
      }
      else {
        ExFreePoolWithTag(_Dst,0);
      }
    }
  }
  else {
    uVar6 = *(ushort *)(param_1 + 0x50) + 0xc1;
    if (uVar6 < uVar7) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000095;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
        return 0xc0000095;
      }
      uVar5 = 0x13;
    }
    else {
      uVar2 = *param_6;
      uVar6 = uVar6 & 0xfffffff0;
      if (uVar2 < 0x10) {
        uVar2 = 0x10;
      }
      uVar2 = uVar2 + uVar6;
      if (uVar2 < uVar6) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000095;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
          return 0xc0000095;
        }
        uVar5 = 0x14;
      }
      else {
        uVar7 = param_6[1] + uVar2;
        if (uVar2 <= uVar7) goto LAB_140018925;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000095;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
          return 0xc0000095;
        }
        uVar5 = 0x15;
      }
    }
    uVar8 = 0xc0000095;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
             &WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,0xc0000095);
  }
  return uVar8;
}



===== DfscNetUseEnum @ 140018adc =====

int DfscNetUseEnum(longlong param_1,longlong param_2,undefined8 param_3,uint param_4,int param_5,
                  int *param_6,uint *param_7)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  int *piVar6;
  undefined8 uVar7;
  undefined *puVar8;
  uint uVar9;
  ulonglong uVar10;
  int local_28;
  uint local_24;
  undefined8 local_20;
  
  local_28 = 0;
  local_20 = 0;
  piVar6 = &local_28;
  local_24 = 0;
  uVar4 = param_3;
  iVar2 = DfscGetEffectiveRequestorSessionId(param_2,piVar6);
  if ((iVar2 == 0) && (iVar2 = DfscGetLogonId(&local_20), iVar2 == 0)) {
    KeEnterCriticalRegion();
    puVar8 = &DAT_14000d6e0;
    puVar5 = (undefined *)(param_1 + 0x98);
    if (param_1 == 0) {
      puVar5 = &DAT_14000d6e0;
    }
    uVar7 = CONCAT71((int7)((ulonglong)piVar6 >> 8),1);
    ExAcquireResourceExclusiveLite(puVar5,uVar7);
    uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
    lVar3 = RtlEnumerateGenericTableAvl(param_3);
    for (uVar9 = 0; (lVar3 != 0 && (uVar9 < param_4)); uVar9 = uVar9 + 1) {
      uVar7 = 0;
      lVar3 = RtlEnumerateGenericTableAvl(param_3);
    }
    while( true ) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,uVar4,param_3,(char)param_4,
                   (char)lVar3);
      }
      if (lVar3 == 0) {
        iVar2 = -0x7fffffe6;
        goto LAB_140018c8f;
      }
      param_4 = param_4 + 1;
      lVar1 = *(longlong *)(lVar3 + 0x20);
      if ((((local_28 == -1) || (local_28 == *(int *)(lVar3 + 0x10))) &&
          ((int)local_20 == *(int *)(lVar3 + 0x14))) && (local_20._4_4_ == *(int *)(lVar3 + 0x18)))
      break;
      uVar7 = 0;
      lVar3 = RtlEnumerateGenericTableAvl(param_3);
    }
    uVar9 = *param_7;
    uVar10 = (ulonglong)uVar9;
    *param_6 = param_5 + param_4;
    uVar4 = DfscNetUseCopyEnumEntry(lVar1,(longlong)param_6,uVar9,(int *)&local_24);
    iVar2 = (int)uVar4;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_dSZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar1 + 0x68,uVar10,*param_6,
                 (wchar_t *)(lVar1 + 0x68),(wchar_t *)(lVar1 + 0x58));
    }
LAB_140018c8f:
    if (param_1 != 0) {
      puVar8 = (undefined *)(param_1 + 0x98);
    }
    ExReleaseResourceLite(puVar8);
    KeLeaveCriticalRegion();
    if (iVar2 == 0) goto LAB_140018cc2;
  }
  if (iVar2 != -0x7ffffffb) {
    return iVar2;
  }
LAB_140018cc2:
  *param_7 = local_24;
  return iVar2;
}



===== DfscIsPathEqualString @ 140018cf4 =====

void DfscIsPathEqualString(undefined1 (*param_1) [16],undefined4 *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  short sVar3;
  short *psVar4;
  ushort uVar5;
  ulonglong uVar6;
  undefined4 local_28;
  undefined4 uStack_24;
  short *psStack_20;
  undefined1 local_18 [16];
  
  local_18 = *param_1;
  uVar1 = *param_2;
  uStack_24 = param_2[1];
  psStack_20 = *(short **)(param_2 + 2);
  uVar6 = (ulonglong)local_18._0_4_;
  psVar4 = (short *)local_18._8_8_;
  if (2 < local_18._0_2_) {
    uVar2 = local_18._2_2_;
    if (((short *)local_18._8_8_ == (short *)0x0) || (*(short *)local_18._8_8_ != 0x5c)) {
      sVar3 = local_18._2_2_;
    }
    else {
      psVar4 = (short *)(local_18._8_8_ + 2);
      uVar5 = local_18._0_2_ - 2;
      uVar6 = (ulonglong)uVar5;
      local_18._8_8_ = psVar4;
      local_18._2_2_ = uVar2 + -2;
      local_18._0_2_ = uVar5;
      sVar3 = uVar2 + -2;
    }
    if (((2 < (ushort)uVar6) && (psVar4 != (short *)0x0)) && (*psVar4 == 0x5c)) {
      psVar4 = psVar4 + 1;
      uVar5 = (ushort)uVar6 - 2;
      uVar6 = (ulonglong)uVar5;
      local_18._8_8_ = psVar4;
      local_18._2_2_ = sVar3 + -2;
      local_18._0_2_ = uVar5;
    }
  }
  local_28._0_2_ = (ushort)uVar1;
  uVar5 = (ushort)local_28;
  if (2 < (ushort)local_28) {
    local_28._2_2_ = (short)((uint)uVar1 >> 0x10);
    if ((psStack_20 == (short *)0x0) || (*psStack_20 != 0x5c)) {
      sVar3 = local_28._2_2_;
      local_28 = uVar1;
    }
    else {
      psStack_20 = psStack_20 + 1;
      uVar5 = (ushort)local_28 - 2;
      sVar3 = local_28._2_2_ + -2;
      local_28 = CONCAT22(sVar3,uVar5);
    }
    uVar1 = local_28;
    if (((2 < uVar5) && (psStack_20 != (short *)0x0)) && (*psStack_20 == 0x5c)) {
      psStack_20 = psStack_20 + 1;
      uVar5 = uVar5 - 2;
      local_28 = CONCAT22(sVar3 + -2,uVar5);
      uVar1 = local_28;
    }
  }
  local_28 = uVar1;
  if (((2 < (ushort)uVar6) && (psVar4 != (short *)0x0)) &&
     (*(short *)((longlong)psVar4 + ((uVar6 & 0xfffe) - 2)) == 0)) {
    local_18._0_2_ = (ushort)uVar6 - 2;
  }
  if (((2 < uVar5) && (psStack_20 != (short *)0x0)) &&
     (psStack_20[(ulonglong)(uVar5 >> 1) - 1] == 0)) {
    local_28 = CONCAT22(local_28._2_2_,uVar5 - 2);
  }
  RtlCompareUnicodeString(local_18,&local_28,CONCAT71((int7)((ulonglong)psStack_20 >> 8),1));
  return;
}



===== DfscNetUseTableAllocateEntry @ 140018e60 =====

void DfscNetUseTableAllocateEntry(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x102,param_2,0x46436644);
  return;
}



===== DfscNetUseTableConflictDetect @ 140018e8c =====

int DfscNetUseTableConflictDetect
              (undefined8 param_1,longlong param_2,undefined8 param_3,int *param_4,uint *param_5)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  wchar_t *pwVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar6 = (int)param_3;
  iVar4 = 0;
  iVar9 = 0;
  pwVar5 = (wchar_t *)RtlEnumerateGenericTableAvl(param_1,1);
  do {
    if (pwVar5 == (wchar_t *)0x0) {
      return iVar4;
    }
    lVar1 = *(longlong *)(pwVar5 + 0x10);
    lVar2 = *(longlong *)(lVar1 + 0x70);
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
        WPP_SF_dqZq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,param_3,iVar9,(char)lVar1,pwVar5
                    ,(char)lVar2);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_dDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_3,
                    *(undefined4 *)(pwVar5 + 8),(char)*(undefined4 *)(pwVar5 + 0xc),
                    (char)*(undefined4 *)(pwVar5 + 10),(char)*(undefined4 *)(lVar1 + 4));
      }
    }
    if ((((iVar6 == -1) || (iVar6 == *(int *)(pwVar5 + 8))) && (*param_4 == *(int *)(pwVar5 + 10)))
       && (param_4[1] == *(int *)(pwVar5 + 0xc))) {
      iVar3 = DfscIsPathEqualString((undefined1 (*) [16])(param_2 + 8),(undefined4 *)(lVar1 + 8));
      uVar8 = (undefined4)((ulonglong)param_3 >> 0x20);
      if (iVar3 == 0) {
        if (lVar2 == 0) {
          if (((param_2 != 0) && (*(int *)(param_2 + 0x28) == 1)) && (*(int *)(param_2 + 0x2c) == 0)
             ) {
            return -0x3ffffe6b;
          }
        }
        else {
          if ((*(int *)(lVar2 + 0x28) == 1) && (*(int *)(lVar2 + 0x2c) == 0)) {
            if (param_2 == 0) {
              return -0x3ffffe6b;
            }
          }
          else if (param_2 == 0) goto LAB_14001901a;
          if (((*(int *)(param_2 + 0x28) == 1) && (lVar2 != 0)) && (*(int *)(lVar2 + 0x28) == 1)) {
            uVar7 = CONCAT31((int3)((ulonglong)param_3 >> 8),1);
            iVar4 = RtlCompareUnicodeString(param_2 + 0x38,lVar2 + 0x38);
            param_3 = CONCAT44(uVar8,uVar7);
            if (iVar4 != 0) {
              return -0x3ffffe6b;
            }
          }
        }
LAB_14001901a:
        iVar4 = DfscTransportConflictDetect(lVar1,param_5);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
    }
    pwVar5 = (wchar_t *)RtlEnumerateGenericTableAvl(param_1,0);
    iVar9 = iVar9 + 1;
  } while( true );
}



===== DfscNetUseTableDelete @ 140019054 =====

void DfscNetUseTableDelete(undefined8 param_1,longlong param_2)

{
  char cVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,(wchar_t *)(param_2 + 0x58),
              (char)param_2);
  }
  cVar1 = RtlDeleteElementGenericTableAvl(param_1,*(undefined8 *)(param_2 + 0x80));
  if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x10b,1,param_1,param_2,param_2 + 0x58);
  }
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(undefined8 *)(param_2 + 0x80) = 0;
  return;
}



===== DfscNetUseTableFree @ 140019100 =====

void DfscNetUseTableFree(longlong param_1,longlong param_2,undefined *param_3)

{
  if (param_2 != 0) {
    DfscNetUseTablePurge(param_1,param_2,param_3);
    ExFreePoolWithTag(param_2,0);
  }
  return;
}



===== DfscNetUseTableInitialize @ 140019130 =====

undefined8 DfscNetUseTableInitialize(undefined8 *param_1)

{
  void *_Dst;
  undefined8 uVar1;
  
  uVar1 = 0;
  *param_1 = 0;
  _Dst = (void *)ExAllocatePool2(0x42,0x68,0x42436644);
  if (_Dst == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memset(_Dst,0,0x68);
    RtlInitializeGenericTableAvl
              (_Dst,DfscNetUseTableCompareEntries,DfscNetUseTableAllocateEntry,
               DfscNetUseTableFreeEntry,0);
    *param_1 = _Dst;
  }
  return uVar1;
}



===== DfscNetUseTablePurge @ 1400191c4 =====

void DfscNetUseTablePurge(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  int iVar5;
  
  iVar5 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    uVar3 = RtlNumberGenericTableElementsAvl(param_2);
    param_3 = &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,uVar3);
  }
  pwVar4 = (wchar_t *)RtlEnumerateGenericTableAvl(param_2,1);
  while (pwVar4 != (wchar_t *)0x0) {
    lVar1 = *(longlong *)(pwVar4 + 0x10);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      lVar2 = *(longlong *)(lVar1 + 0x80);
      param_3 = &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids;
      WPP_SF_dqZdDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,iVar5,(char)lVar1,pwVar4,
                     (char)*(undefined4 *)(lVar2 + 0x10),(char)*(undefined4 *)(lVar2 + 0x18),
                     (char)*(undefined4 *)(lVar2 + 0x14),(char)*(undefined4 *)(lVar1 + 4));
    }
    DfscNetUseTableDelete(param_2,lVar1);
    param_3 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
    DfscNetUseRelease(param_1,lVar1,param_3,'\0');
    pwVar4 = (wchar_t *)RtlEnumerateGenericTableAvl(param_2,0);
    iVar5 = iVar5 + 1;
  }
  return;
}



===== DfscNetUseTableStore @ 140019304 =====

undefined8
DfscNetUseTableStore
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  char local_res8 [8];
  
  uVar3 = 0;
  local_res8[0] = '\0';
  puVar2 = (undefined8 *)
           RtlInsertElementGenericTableFullAvl(param_1,param_3,0x30,local_res8,param_4,param_5);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    if (local_res8[0] == '\0') {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x10b,1,param_1,param_2,param_3);
    }
    LOCK();
    *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
    UNLOCK();
    puVar2[4] = param_2;
    if ((*(uint *)(puVar2 + 5) & 1) == 0) {
      uVar1 = *(undefined8 *)(param_2 + 0x60);
      *puVar2 = *(undefined8 *)(param_2 + 0x58);
      puVar2[1] = uVar1;
    }
    else {
      *(undefined4 *)puVar2 = 0x60004;
      puVar2[1] = param_2 + 0x68;
    }
    *(undefined8 **)(param_2 + 0x80) = puVar2;
    *(undefined8 *)(param_2 + 0x78) = param_1;
  }
  return uVar3;
}



===== DfscDAConnectivityChangeHandler @ 1400193e0 =====

void DfscDAConnectivityChangeHandler(void)

{
  bool bVar1;
  undefined8 uVar2;
  int *piVar3;
  bool bVar4;
  int local_res10 [6];
  undefined4 local_18;
  undefined4 local_14;
  wchar_t *local_10;
  
  local_res10[0] = 0;
  bVar1 = false;
  local_14 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000d7c0,1);
  if (DAConnectivityMonitor == 0) goto LAB_14001950b;
  local_18 = 0x280028;
  piVar3 = local_res10;
  local_10 = L"UseDcLocatorSiteName";
  uVar2 = DfscGetUlongRegistryParameter(DAConnectivityMonitor,&local_18,piVar3);
  if ((int)uVar2 < 0) {
    DAT_14000d7ae = '\0';
LAB_140019479:
    if (DAT_14000d7b8 != 0) {
      ExFreePoolWithTag();
      uVar2 = 0;
      RtlInitUnicodeString(&DAT_14000d7b0);
      DfscCachePurge(DAT_14000d6d0,uVar2,(undefined *)piVar3);
      DfscCachePurge(DAT_14000d6c8,uVar2,(undefined *)piVar3);
    }
  }
  else {
    bVar4 = local_res10[0] != 0;
    if ((bool)DAT_14000d7ae != bVar4) {
      DAT_14000d7ae = bVar4;
      if (bVar4) {
        DfscInitializeSiteNameAndRegisterChangeNotification();
      }
      else {
        bVar1 = true;
      }
    }
    if (bVar1) goto LAB_140019479;
  }
  ZwNotifyChangeKey(DAConnectivityMonitor,0,&DAT_14000d548,1,&DAT_14000d568,4,0,0,0,1);
LAB_14001950b:
  ExReleaseResourceLite(&DAT_14000d7c0);
  KeLeaveCriticalRegion();
  return;
}



===== DfscDeInitSiteNameMonitoring @ 140019538 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DfscDeInitSiteNameMonitoring(void)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000d7c0,1);
  if (SiteNameRegKeyMonitor != 0) {
    ZwClose();
  }
  if (DAConnectivityMonitor != 0) {
    ZwClose();
  }
  if (DAT_14000d7b8 != 0) {
    ExFreePoolWithTag(DAT_14000d7b8,0);
    DAT_14000d7b8 = 0;
    _DAT_14000d7b0 = 0;
  }
  ExReleaseResourceLite(&DAT_14000d7c0);
  KeLeaveCriticalRegion();
  ExDeleteResourceLite(&DAT_14000d7c0);
  return;
}



===== DfscInitializeAndRegisterDAKeyChangeNotification @ 1400195f8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DfscInitializeAndRegisterDAKeyChangeNotification(void)

{
  int iVar1;
  undefined8 uVar2;
  int local_res8 [2];
  undefined4 local_48;
  undefined4 local_44;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_20 = 0x240;
  local_res8[0] = 0;
  local_44 = 0;
  DAConnectivityMonitor = 0;
  SiteNameRegKeyMonitor = 0;
  local_30 = 0;
  local_28 = &DAT_14000d768;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&DAConnectivityMonitor,0x10,&local_38);
  if (iVar1 < 0) {
    return;
  }
  _DAT_14000d560 = 0;
  _DAT_14000d558 = DfscDAConnectivityChangeHandler;
  _DAT_14000d548 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000d7c0,1);
  ZwNotifyChangeKey(DAConnectivityMonitor,0,&DAT_14000d548,1,&DAT_14000d568,4,0,0,0,1);
  local_40 = L"UseDcLocatorSiteName";
  local_48 = 0x280028;
  uVar2 = DfscGetUlongRegistryParameter(DAConnectivityMonitor,&local_48,local_res8);
  if ((int)uVar2 < 0) {
LAB_14001972a:
    if (DAT_14000d7ae == '\0') goto LAB_140019737;
  }
  else {
    if (local_res8[0] == 0) {
      DAT_14000d7ae = '\0';
      goto LAB_14001972a;
    }
    DAT_14000d7ae = '\x01';
  }
  DfscInitializeSiteNameAndRegisterChangeNotification();
LAB_140019737:
  ExReleaseResourceLite(&DAT_14000d7c0);
  KeLeaveCriticalRegion();
  return;
}



===== DfscInitializeSiteNameAndRegisterChangeNotification @ 140019770 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DfscInitializeSiteNameAndRegisterChangeNotification(void)

{
  int iVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (SiteNameRegKeyMonitor == 0) {
    RtlInitUnicodeString
              (&local_48,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Netlogon\\Parameters");
    local_30 = 0;
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwOpenKey(&SiteNameRegKeyMonitor,0x10,&local_38);
    if (iVar1 < 0) {
      SiteNameRegKeyMonitor = 0;
    }
    if (SiteNameRegKeyMonitor == 0) {
      return;
    }
    _DAT_14000d5a0 = 0;
    _DAT_14000d588 = 0;
    _DAT_14000d598 = DfscSiteNameChangeHandler;
    ZwNotifyChangeKey(SiteNameRegKeyMonitor,0,&DAT_14000d588,1,&DAT_14000d5a8,4,0,0,0,1);
  }
  DfscUpdateSiteNameFromRegistry();
  return;
}



===== DfscReadLinkedConnectionPolicy @ 140019884 =====

void DfscReadLinkedConnectionPolicy(void)

{
  int iVar1;
  undefined8 uVar2;
  int local_res8 [2];
  undefined8 local_res10 [3];
  undefined4 local_48;
  undefined4 local_44;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_1c = 0;
  local_44 = 0;
  local_30 = 0;
  local_40 = L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x240;
  local_48 = 0x960096;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(local_res10,0x20019,&local_38);
  if (-1 < iVar1) {
    local_40 = L"EnableLinkedConnections";
    local_48 = 0x2e002e;
    uVar2 = DfscGetUlongRegistryParameter(local_res10[0],&local_48,local_res8);
    if (-1 < (int)uVar2) {
      DfscGlobalData = DfscGlobalData & 0xfffffffd | 4 | -(uint)(local_res8[0] != 0) & 2;
    }
    ZwClose(local_res10[0]);
  }
  return;
}



===== DfscSiteNameChangeHandler @ 140019960 =====

void DfscSiteNameChangeHandler(void)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000d7c0,1);
  if (SiteNameRegKeyMonitor != 0) {
    if (DAT_14000d7ae == '\0') {
      ZwClose();
      SiteNameRegKeyMonitor = 0;
    }
    else {
      DfscUpdateSiteNameFromRegistry();
      ZwNotifyChangeKey(SiteNameRegKeyMonitor,0,&DAT_14000d588,1,&DAT_14000d5a8,4,0,0,0,1);
    }
  }
  ExReleaseResourceLite(&DAT_14000d7c0);
  KeLeaveCriticalRegion();
  return;
}



===== DfscUpdateSiteNameFromRegistry @ 140019a2c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DfscUpdateSiteNameFromRegistry(void)

{
  char cVar1;
  int iVar2;
  void *_Dst;
  undefined8 *puVar3;
  void *pvVar4;
  uint uVar5;
  undefined *puVar6;
  ulonglong _Size;
  undefined4 local_res8 [2];
  undefined8 local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  local_res8[0] = 0;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  RtlInitUnicodeString(&local_28,L"SiteName");
  RtlInitUnicodeString(&local_38,0);
  puVar6 = (undefined *)0x1;
  iVar2 = ZwQueryValueKey(SiteNameRegKeyMonitor,&local_28,1,0,0,local_res8);
  if (iVar2 == -0x3fffffdd) {
    puVar6 = (undefined *)0x4b436644;
    _Dst = (void *)ExAllocatePool2(0x102);
    pvVar4 = _Dst;
    if (_Dst == (void *)0x0) goto LAB_140019be1;
    puVar6 = (undefined *)0x1;
    iVar2 = ZwQueryValueKey(SiteNameRegKeyMonitor,&local_28,1,_Dst,local_res8[0],local_res8);
    if (((iVar2 < 0) || (uVar5 = *(uint *)((longlong)_Dst + 0xc), *(int *)((longlong)_Dst + 4) != 1)
        ) || ((uVar5 & 1) != 0)) goto LAB_140019be1;
    _Size = (ulonglong)uVar5;
    memmove(_Dst,(void *)((ulonglong)*(uint *)((longlong)_Dst + 8) + (longlong)_Dst),_Size);
    if (1 < uVar5) {
      if (*(short *)((longlong)_Dst + (ulonglong)(uVar5 >> 1) * 2 + -2) == 0) {
        uVar5 = uVar5 - 2;
        if (uVar5 < 2) goto LAB_140019b7c;
      }
      else {
        *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar5 >> 1) * 2) = 0;
      }
      local_38._0_4_ = CONCAT22((short)local_res8[0] + 2,(short)uVar5);
      pvStack_30 = _Dst;
    }
LAB_140019b7c:
    puVar6 = (undefined *)CONCAT71((int7)(_Size >> 8),1);
    puVar3 = &local_38;
    cVar1 = RtlEqualUnicodeString(&DAT_14000d7b0);
    if (cVar1 != '\0') goto LAB_140019c2d;
    if (DAT_14000d7b8 != (void *)0x0) {
      puVar3 = (undefined8 *)0x0;
      ExFreePoolWithTag();
    }
    _DAT_14000d7b2 = (short)local_res8[0] + 2;
    pvVar4 = (void *)0x0;
    DAT_14000d7b0 = (undefined2)uVar5;
    DAT_14000d7b8 = _Dst;
LAB_140019c10:
    DfscCachePurge(DAT_14000d6d0,puVar3,puVar6);
    DfscCachePurge(DAT_14000d6c8,puVar3,puVar6);
  }
  else {
    pvVar4 = (void *)0x0;
    if (-1 < iVar2) {
      return;
    }
LAB_140019be1:
    if (DAT_14000d7b8 != (void *)0x0) {
      ExFreePoolWithTag();
      puVar3 = (undefined8 *)0x0;
      RtlInitUnicodeString(&DAT_14000d7b0);
      goto LAB_140019c10;
    }
  }
  if (pvVar4 == (void *)0x0) {
    return;
  }
LAB_140019c2d:
  ExFreePoolWithTag(pvVar4,0);
  return;
}



===== DfscCleanupGetClientInfoParameters @ 140019c60 =====

void DfscCleanupGetClientInfoParameters
               (undefined8 *param_1,undefined8 *param_2,short *param_3,ushort *param_4,
               short *param_5)

{
  undefined8 uVar1;
  short sVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar1 = param_1[1];
  uVar4 = 0;
  *(undefined8 *)param_3 = *param_1;
  *(undefined8 *)(param_3 + 4) = uVar1;
  uVar1 = param_2[1];
  *(undefined8 *)param_4 = *param_2;
  *(undefined8 *)(param_4 + 4) = uVar1;
  sVar2 = *param_3;
  while ((sVar2 != 0 && (**(short **)(param_3 + 4) == 0x5c))) {
    sVar2 = sVar2 + -2;
    param_3[1] = param_3[1] + -2;
    *(short **)(param_3 + 4) = *(short **)(param_3 + 4) + 1;
    *param_3 = sVar2;
  }
  uVar5 = *param_4;
  while ((uVar5 != 0 && (**(short **)(param_4 + 4) == 0x5c))) {
    uVar5 = uVar5 - 2;
    param_4[1] = param_4[1] - 2;
    *(short **)(param_4 + 4) = *(short **)(param_4 + 4) + 1;
    *param_4 = uVar5;
  }
  *param_5 = 0;
  if (uVar5 != 0) {
    for (; uVar3 = (ulonglong)uVar4, uVar3 < (ulonglong)(*param_4 >> 1) - 1; uVar4 = uVar4 + 1) {
      if (*(short *)(*(longlong *)(param_4 + 4) + uVar3 * 2) == 0x5c) {
        *(ulonglong *)(param_5 + 4) = *(longlong *)(param_4 + 4) + (uVar3 + 1) * 2;
        sVar2 = *param_4 + uVar4 * -2 + -2;
        *param_5 = sVar2;
        param_5[1] = sVar2;
        *param_4 = uVar4 * 2;
        return;
      }
    }
  }
  return;
}



===== DfscGetSiteName @ 140019d2c =====

void DfscGetSiteName(undefined2 *param_1)

{
  longlong lVar1;
  
  if ((((param_1 != (undefined2 *)0x0) && (DAT_14000d7b0 != 0)) && (DAT_14000d7b8 != (short *)0x0))
     && (*DAT_14000d7b8 != 0)) {
    lVar1 = ExAllocatePool2(0x102,(ulonglong)DAT_14000d7b0 + 2,0x4b436644);
    *(longlong *)(param_1 + 4) = lVar1;
    if (lVar1 != 0) {
      *param_1 = 0;
      param_1[1] = DAT_14000d7b0 + 2;
      RtlCopyUnicodeString(param_1,&DAT_14000d7b0);
    }
  }
  return;
}



===== DfscReferralGetClientInfoMarshall @ 140019dcc =====

ulonglong DfscReferralGetClientInfoMarshall
                    (longlong param_1,ushort *param_2,int param_3,char param_4,undefined8 *param_5,
                    undefined8 *param_6,ulonglong *param_7,uint param_8)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  bool bVar12;
  ulonglong *local_98;
  ulonglong *local_90;
  ushort local_68 [8];
  undefined8 local_58;
  undefined8 uStack_50;
  ushort local_48 [8];
  
  uVar4 = (ulonglong)param_8;
  local_90 = (ulonglong *)0x0;
  local_98 = (ulonglong *)0x0;
  puVar7 = (ulonglong *)0x0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_58 = 0;
  uStack_50 = 0;
  memset(param_7,0,(ulonglong)param_8);
  if (param_4 == '\0') {
    if ((param_3 == 4) && (param_8 < 0x50)) {
      return 0x80000005;
    }
    if ((param_3 == 3) && (param_8 < 0x38)) {
      return 0x80000005;
    }
    puVar8 = param_7;
    if (1 < param_3 - 1U) goto LAB_140019ea5;
    bVar12 = param_8 < 0x20;
  }
  else {
    if ((param_3 == 4) && (param_8 < 0x34)) {
      return 0x80000005;
    }
    if ((param_3 == 3) && (param_8 < 0x20)) {
      return 0x80000005;
    }
    puVar7 = param_7;
    puVar8 = (ulonglong *)0x0;
    if (1 < param_3 - 1U) goto LAB_140019ea5;
    bVar12 = param_8 < 0x14;
  }
  if (bVar12) {
    return 0x80000005;
  }
LAB_140019ea5:
  lVar6 = *(longlong *)(param_1 + 0x10);
  uVar9 = (param_8 - *param_2) - 2;
  memmove((void *)((longlong)param_7 + (ulonglong)uVar9),*(void **)(param_2 + 4),(ulonglong)*param_2
         );
  if (param_3 == 1) {
    if (param_4 == '\0') {
      *puVar8 = (ulonglong)uVar9;
    }
    else {
      *(uint *)puVar7 = uVar9;
    }
  }
  else {
    if (param_3 != 2) {
      if (param_3 == 3) {
        if (param_4 == '\0') {
          *puVar8 = (ulonglong)uVar9;
          puVar8[1] = 0;
          *(undefined4 *)(puVar8 + 2) = 1;
          *(uint *)((longlong)puVar8 + 0x14) = (uint)*(ushort *)(lVar6 + 0x1c);
          local_90 = puVar8 + 4;
          puVar8[3] = (ulonglong)(uint)((int)local_90 - (int)param_7);
        }
        else {
          *(uint *)puVar7 = uVar9;
          *(uint *)((longlong)puVar7 + 4) = 0;
          *(uint *)(puVar7 + 1) = 1;
          *(uint *)((longlong)puVar7 + 0xc) = (uint)*(ushort *)(lVar6 + 0x1c);
          local_98 = (ulonglong *)((longlong)puVar7 + 0x14);
          *(int *)(puVar7 + 2) = (int)local_98 - (int)param_7;
        }
      }
      else if (param_3 == 4) {
        if (param_4 == '\0') {
          local_90 = puVar8 + 7;
          *puVar8 = (ulonglong)uVar9;
          puVar8[1] = 0;
          *(undefined4 *)(puVar8 + 2) = 1;
          *(undefined4 *)((longlong)puVar8 + 0x14) = *(undefined4 *)(lVar6 + 0x28);
          *(uint *)(puVar8 + 5) = (uint)*(ushort *)(lVar6 + 0x1c);
          puVar8[6] = (ulonglong)(uint)((int)local_90 - (int)param_7);
        }
        else {
          *(uint *)puVar7 = uVar9;
          local_98 = puVar7 + 5;
          *(uint *)((longlong)puVar7 + 4) = 0;
          *(uint *)(puVar7 + 1) = 1;
          *(uint *)((longlong)puVar7 + 0xc) = *(uint *)(lVar6 + 0x28);
          *(uint *)(puVar7 + 4) = (uint)*(ushort *)(lVar6 + 0x1c);
          *(int *)((longlong)puVar7 + 0x24) = (int)local_98 - (int)param_7;
        }
      }
      else if (1 < param_3 - 3U) {
        return 0;
      }
      *(undefined2 *)(param_1 + 0x20) = 0xffff;
      lVar6 = param_1;
      DfscCleanupGetClientInfoParameters
                (param_5,param_6,(short *)local_68,(ushort *)&local_58,(short *)local_48);
      uVar11 = 0;
LAB_140019fec:
      uVar2 = DfscReferralIterate(lVar6);
      uVar10 = 0;
      if ((int)uVar2 < 0) {
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 == -0x7fffffe6) {
          uVar4 = 0;
        }
        if (param_3 == 3) {
          if (param_4 == '\0') {
            *(uint *)((longlong)puVar8 + 0x14) = uVar11;
            return uVar4;
          }
          *(uint *)((longlong)puVar7 + 0xc) = uVar11;
          return uVar4;
        }
        if (param_3 != 4) {
          return uVar4;
        }
        if (param_4 == '\0') {
          *(uint *)(puVar8 + 5) = uVar11;
          return uVar4;
        }
        *(uint *)(puVar7 + 4) = uVar11;
        return uVar4;
      }
      lVar3 = DfscReferralGetCurrentTarget(lVar6);
      if (local_68[0] != uVar10) goto code_r0x00014001a00f;
      goto LAB_14001a035;
    }
    if (param_4 == '\0') {
      *puVar8 = (ulonglong)uVar9;
      puVar8[1] = 0;
      *(undefined4 *)(puVar8 + 2) = 1;
      *(uint *)((longlong)puVar8 + 0x14) = (uint)*(ushort *)(lVar6 + 0x1c);
    }
    else {
      *(uint *)puVar7 = uVar9;
      *(uint *)((longlong)puVar7 + 4) = 0;
      *(uint *)(puVar7 + 1) = 1;
      *(uint *)((longlong)puVar7 + 0xc) = (uint)*(ushort *)(lVar6 + 0x1c);
    }
  }
  return 0;
code_r0x00014001a00f:
  iVar1 = RtlCompareUnicodeString(local_68,lVar3 + 0x10,1);
  uVar10 = 0;
  lVar6 = param_1;
  if (iVar1 == 0) {
LAB_14001a035:
    if ((ushort)local_58 != uVar10) {
      iVar1 = RtlCompareUnicodeString(&local_58,lVar3 + 0x20,1);
      uVar10 = 0;
      lVar6 = param_1;
      if (iVar1 != 0) goto LAB_140019fec;
    }
    if (local_48[0] != uVar10) {
      iVar1 = RtlCompareUnicodeString(local_48,lVar3 + 0x30,1);
      lVar6 = param_1;
      if (iVar1 != 0) goto LAB_140019fec;
    }
    if (param_4 == '\0') {
      if (uVar4 < (ulonglong)((0x18 - (longlong)param_7) + (longlong)local_90)) {
        return 0x80000005;
      }
      *(uint *)local_90 = 2;
    }
    else {
      *(uint *)local_98 = 2;
      if (uVar4 < (ulonglong)((0xc - (longlong)param_7) + (longlong)local_98)) {
        return 0x80000005;
      }
    }
    if (*(short *)(param_1 + 0x20) == *(short *)(param_1 + 0x1a)) {
      if (param_4 == '\0') {
        *(uint *)local_90 = (uint)*local_90 | 4;
      }
      else {
        *(uint *)local_98 = (uint)*local_98 | 4;
      }
    }
    uVar9 = uVar9 + (-2 - (uint)*(ushort *)(lVar3 + 0x10));
    memmove((void *)((ulonglong)uVar9 + (longlong)param_7),*(void **)(lVar3 + 0x18),
            (ulonglong)*(ushort *)(lVar3 + 0x10));
    if (param_4 == '\0') {
      local_90[1] = (ulonglong)uVar9;
    }
    else {
      *(uint *)((longlong)local_98 + 4) = uVar9;
    }
    uVar9 = uVar9 + (-2 - (uint)*(ushort *)(lVar3 + 0x20));
    if (*(ushort *)(lVar3 + 0x30) != 0) {
      uVar9 = uVar9 + (-2 - (uint)*(ushort *)(lVar3 + 0x30));
    }
    memmove((void *)((ulonglong)uVar9 + (longlong)param_7),*(void **)(lVar3 + 0x28),
            (ulonglong)*(ushort *)(lVar3 + 0x20));
    if (*(short *)(lVar3 + 0x30) != 0) {
      uVar5 = *(ushort *)(lVar3 + 0x20) + uVar9;
      if (uVar4 < (ulonglong)uVar5 + 2) {
        return 0x80000005;
      }
      *(undefined2 *)((longlong)param_7 + (ulonglong)(uVar5 >> 1) * 2) = 0x5c;
      memmove((void *)((ulonglong)(uVar5 + 2) + (longlong)param_7),*(void **)(lVar3 + 0x38),
              (ulonglong)*(ushort *)(lVar3 + 0x30));
    }
    if (param_4 == '\0') {
      local_90[2] = (ulonglong)uVar9;
      local_90 = local_90 + 3;
    }
    else {
      *(uint *)(local_98 + 1) = uVar9;
      local_98 = (ulonglong *)((longlong)local_98 + 0xc);
    }
    uVar11 = uVar11 + 1;
    lVar6 = param_1;
  }
  goto LAB_140019fec;
}



===== DfscReferralGetClientInfoSize @ 14001a27c =====

int DfscReferralGetClientInfoSize
              (longlong param_1,ushort *param_2,int param_3,char param_4,undefined8 *param_5,
              undefined8 *param_6,int *param_7)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar5;
  int iVar4;
  int iVar6;
  short local_48 [8];
  undefined8 local_38;
  undefined8 uStack_30;
  short local_28 [8];
  
  uVar5 = (uint)*param_2;
  iVar4 = uVar5 + 2;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 == 1) {
    if (param_4 == '\0') {
      iVar4 = uVar5 + 10;
    }
    else {
      iVar4 = uVar5 + 6;
    }
LAB_14001a3f7:
    *param_7 = iVar4;
    return 0;
  }
  if (param_3 == 2) {
    iVar4 = iVar4 + (-(uint)(param_4 != '\0') & 0xfffffff8) + 0x18;
    goto LAB_14001a3f7;
  }
  if (param_3 == 3) {
    iVar1 = (-(uint)(param_4 != '\0') & 0xfffffff4) + 0x20;
  }
  else {
    if (param_3 != 4) {
      if ((param_3 != 3) && (param_3 != 4)) goto LAB_14001a3f7;
      goto LAB_14001a303;
    }
    iVar1 = (-(uint)(param_4 != '\0') & 0xfffffff0) + 0x38;
  }
  iVar4 = iVar4 + iVar1;
LAB_14001a303:
  *(undefined2 *)(param_1 + 0x20) = 0xffff;
  DfscCleanupGetClientInfoParameters(param_5,param_6,local_48,(ushort *)&local_38,local_28);
  uVar2 = DfscReferralIterate(param_1);
  while (iVar1 = (int)uVar2, -1 < iVar1) {
    lVar3 = DfscReferralGetCurrentTarget(param_1);
    if ((((local_48[0] == 0) ||
         (iVar1 = RtlCompareUnicodeString(local_48,lVar3 + 0x10,1), iVar1 == 0)) &&
        (((ushort)local_38 == 0 ||
         (iVar1 = RtlCompareUnicodeString(&local_38,lVar3 + 0x20,1), iVar1 == 0)))) &&
       ((local_28[0] == 0 || (iVar1 = RtlCompareUnicodeString(local_28,lVar3 + 0x30,1), iVar1 == 0))
       )) {
      if (param_4 == '\0') {
        iVar4 = iVar4 + 0x1a;
      }
      else {
        iVar4 = iVar4 + 0xe;
      }
      iVar4 = iVar4 + (uint)*(ushort *)(lVar3 + 0x60);
    }
    uVar2 = DfscReferralIterate(param_1);
  }
  iVar6 = 0;
  if (iVar1 != -0x7fffffe6) {
    iVar6 = iVar1;
  }
  *param_7 = iVar4;
  return iVar6;
}



===== DfscRmGenerateDomainDcReferralFromResponse @ 14001a420 =====

ulonglong DfscRmGenerateDomainDcReferralFromResponse
                    (longlong param_1,ushort *param_2,uint param_3,undefined8 *param_4)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_var;
  ulonglong uVar4;
  undefined4 extraout_var_00;
  undefined2 *puVar5;
  ulonglong uVar6;
  short *_Src;
  void *_Dst;
  ushort uVar7;
  short sVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_68 [2];
  void *local_60;
  size_t local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  wchar_t local_40;
  undefined1 auStack_3e [6];
  void *pvStack_38;
  
  local_60 = (void *)CONCAT44(local_60._4_4_,DAT_14000d788);
  local_68[0] = 0;
  _local_40 = 0;
  pvStack_38 = (void *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  iVar2 = DfscRmCheckReferralSyntax((longlong)param_2,param_3,'\x01',(int *)local_68);
  if (iVar2 < 0) {
    return CONCAT44(extraout_var,iVar2);
  }
  uVar4 = Feature_102208826__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    bVar10 = param_2[1] == 1;
  }
  else {
    if (param_2[1] != 1) {
      return 0xc00000c3;
    }
    bVar10 = param_2[4] == 3;
  }
  if (((!bVar10) || ((param_2[7] & 2) == 0)) || (param_2[0xb] == 0)) {
    return 0xc00000c3;
  }
  uVar3 = DfscRmGetDomainDcReferralSize((longlong)param_2,(int *)local_68);
  if ((int)uVar3 < 0) {
    return CONCAT44(extraout_var_00,uVar3);
  }
  uVar4 = DfscRmGetPathConsumed(param_1,param_2,&local_50,'\0');
  uVar6 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  puVar5 = DfscRmAllocateReferral((uint)(ushort)local_50 + local_68[0] + 2,0x72436644);
  if (puVar5 == (undefined2 *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    uVar7 = param_2[0xb];
    puVar5[0xe] = uVar7;
    puVar5[0xf] = 0;
    uVar3 = (uint)local_60;
    if (*(uint *)(param_2 + 8) < (uint)local_60) {
      uVar3 = *(uint *)(param_2 + 8);
    }
    *(uint *)(puVar5 + 0x14) = uVar3;
    *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)(param_1 + 0xe8);
    *(undefined2 **)(puVar5 + 0x4c) = puVar5 + (ulonglong)uVar7 * 0x38 + 0x50;
    *(undefined1 *)((longlong)puVar5 + 0x13) = 1;
    puVar5[0x49] = (ushort)local_50 + 2;
    RtlCopyUnicodeString(puVar5 + 0x48,&local_50);
    _Src = (short *)((ulonglong)param_2[0xc] + (longlong)(param_2 + 4));
    _Dst = (void *)((ulonglong)(ushort)puVar5[0x49] + *(longlong *)(puVar5 + 0x4c));
    uVar7 = ((short)param_3 - (short)_Src) + (short)param_2;
    local_68[0] = 0;
    if (puVar5[0xe] != 0) {
      puVar9 = (undefined4 *)(puVar5 + 0x54);
      local_60 = _Dst;
      do {
        for (; *_Src == 0x5c; _Src = _Src + 1) {
          uVar7 = uVar7 - 2;
        }
        local_58 = 0;
        uVar3 = RtlStringCbLengthW(_Src,(ulonglong)uVar7,(longlong *)&local_58);
        sVar1 = local_58;
        uVar6 = (ulonglong)uVar3;
        if ((local_58 == 0) || (uVar3 != 0)) {
          uVar4 = Feature_468612410__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar4 == 0) || (uVar3 != 0)) {
            if (-1 < (int)uVar3) break;
          }
          else {
            uVar6 = 0xc00000c3;
          }
LAB_14001a6b4:
          DfscRmDereferenceReferral((longlong)puVar5);
          return uVar6;
        }
        memmove(_Dst,_Src,local_58);
        local_58 = sVar1 >> 1;
        *(undefined2 *)((longlong)local_60 + local_58 * 2) = 0;
        pvStack_38 = local_60;
        sVar8 = (short)sVar1;
        _local_40 = CONCAT62(CONCAT42(auStack_3e._2_4_,sVar8),sVar8);
        uVar4 = DfscInitDfsPath(&local_40,(short *)(puVar9 + 2));
        uVar6 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) goto LAB_14001a6b4;
        *puVar9 = 0xffffffff;
        puVar9 = puVar9 + 0x1c;
        local_68[0] = local_68[0] + 1;
        _Dst = (void *)((longlong)local_60 + sVar1 + 2);
        uVar7 = uVar7 + (-2 - sVar8);
        _Src = _Src + local_58 + 1;
        local_60 = _Dst;
      } while (local_68[0] < (ushort)puVar5[0xe]);
    }
    *param_4 = puVar5;
  }
  return uVar6;
}



===== DfscRmGenerateReferralEx @ 14001a6e8 =====

int DfscRmGenerateReferralEx
              (ulonglong param_1,ushort *param_2,ushort *param_3,longlong param_4,undefined2 param_5
              ,undefined8 *param_6,undefined4 *param_7)

{
  ushort uVar1;
  int iVar2;
  undefined2 *_Dst;
  ushort uVar3;
  uint uVar4;
  wchar_t *pwVar5;
  uint uVar6;
  ulonglong local_res8;
  
  uVar6 = *param_3 + 0x11 + (uint)*param_2;
  local_res8 = param_1 & 0xffffffff00000000;
  uVar4 = uVar6;
  if (uVar6 < 0x1000) {
    uVar4 = 0x1000;
  }
  do {
    _Dst = (undefined2 *)ExAllocatePool2(0x102,uVar4,0x6a436644);
    if (_Dst == (undefined2 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                 &WPP_af603b4b97893b05877342047baf7746_Traceguids,uVar4);
      }
      iVar2 = -0x3fffff66;
LAB_14001a9b1:
      *param_6 = _Dst;
      return iVar2;
    }
    memset(_Dst,0,(ulonglong)uVar4);
    _Dst[1] = 0;
    *_Dst = param_5;
    uVar3 = *param_2 + 2;
    _Dst[4] = uVar3;
    pwVar5 = _Dst + 5;
    if (*param_2 != 0) {
      memmove(pwVar5,*(void **)(param_2 + 4),(ulonglong)*param_2);
    }
    pwVar5[*param_2 >> 1] = L'\0';
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_af603b4b97893b05877342047baf7746_Traceguids,_Dst,pwVar5);
    }
    *(uint *)(_Dst + 2) = uVar3 + 2;
    uVar1 = *param_3;
    *(ushort *)((longlong)pwVar5 + (ulonglong)uVar3) = uVar1 + 2;
    pwVar5 = (wchar_t *)((ushort *)((longlong)pwVar5 + (ulonglong)uVar3) + 1);
    if (*param_3 != 0) {
      memmove(pwVar5,*(void **)(param_3 + 4),(ulonglong)*param_3);
      _Dst[1] = _Dst[1] | 1;
    }
    pwVar5[*param_3 >> 1] = L'\0';
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_af603b4b97893b05877342047baf7746_Traceguids,_Dst,pwVar5);
    }
    *(uint *)(_Dst + 2) = *(int *)(_Dst + 2) + (ushort)(uVar1 + 2) + 2;
    iVar2 = DfscRmSendSynchFsctlIrp
                      (0x601b0,*(undefined8 *)(param_4 + 0x30),_Dst,uVar6,_Dst,uVar4,
                       (undefined4 *)&local_res8);
    if (iVar2 != -0x7ffffffb) {
      if (iVar2 < 0) {
LAB_14001a92e:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                   &WPP_af603b4b97893b05877342047baf7746_Traceguids,_Dst);
        }
        ExFreePoolWithTag(_Dst,0);
        _Dst = (undefined2 *)0x0;
      }
      else {
        *param_7 = (undefined4)local_res8;
      }
      goto LAB_14001a9b1;
    }
    if (0xdfff < uVar4) goto LAB_14001a92e;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_af603b4b97893b05877342047baf7746_Traceguids,_Dst);
    }
    ExFreePoolWithTag(_Dst,0);
    uVar4 = uVar4 * 2;
    if (0xe000 < uVar4) {
      uVar4 = 0xe000;
    }
  } while( true );
}



===== DfscRmGetDomainDcReferralSize @ 14001a9e4 =====

uint DfscRmGetDomainDcReferralSize(longlong param_1,int *param_2)

{
  uint uVar1;
  longlong lVar3;
  longlong lVar2;
  short *psVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  longlong local_res8;
  
  psVar4 = (short *)(param_1 + 8);
  uVar1 = 0;
  iVar6 = 0xa0;
  uVar5 = 0;
  if (*(short *)(param_1 + 2) != 0) {
    do {
      if ((*psVar4 == 3) && ((*(byte *)(psVar4 + 3) & 2) != 0)) {
        uVar8 = 0;
        psVar7 = (short *)((ulonglong)(ushort)psVar4[8] + (longlong)psVar4);
        if (psVar4[7] != 0) {
          do {
            iVar6 = iVar6 + 0x70;
            for (; *psVar7 == 0x5c; psVar7 = psVar7 + 1) {
            }
            local_res8 = 0;
            uVar1 = RtlStringCbLengthW(psVar7,0xffff,&local_res8);
            if (uVar1 != 0) break;
            iVar6 = iVar6 + (int)local_res8 + 2;
            lVar2 = -1;
            do {
              lVar3 = lVar2;
              lVar2 = lVar3 + 1;
            } while (psVar7[lVar2] != 0);
            psVar7 = psVar7 + lVar3 + 2;
            uVar8 = uVar8 + 1;
          } while (uVar8 < (ushort)psVar4[7]);
        }
      }
      uVar5 = uVar5 + 1;
      psVar4 = (short *)((longlong)psVar4 + (ulonglong)(ushort)psVar4[1]);
    } while (uVar5 < *(ushort *)(param_1 + 2));
  }
  *param_2 = iVar6;
  return uVar1;
}



===== DfscRmGetNormalReferralSize @ 14001aad0 =====

uint DfscRmGetNormalReferralSize(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  ulonglong uVar5;
  short *psVar6;
  longlong lVar7;
  short *psVar8;
  ulonglong local_res8;
  
  uVar5 = (ulonglong)*(ushort *)(param_1 + 2);
  psVar8 = (short *)(param_1 + 8);
  uVar4 = 0;
  lVar7 = uVar5 * 0x70 + 0xa0;
  do {
    if ((int)uVar5 == 0) {
LAB_14001ab93:
      *param_2 = (int)lVar7;
      return uVar4;
    }
    sVar2 = *psVar8;
    uVar5 = (ulonglong)((int)uVar5 - 1);
    if (sVar2 == 1) {
      psVar6 = psVar8 + 4;
LAB_14001ab2b:
      if (psVar6 != (short *)0x0) {
        local_res8 = 0;
        uVar4 = RtlStringCbLengthW(psVar6,0xffff,(longlong *)&local_res8);
        if ((uVar4 != 0) || (local_res8 == 0)) {
          uVar5 = Feature_170808633__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar5 != 0) && (uVar4 == 0)) {
            return 0xc00000c3;
          }
          if ((int)uVar4 < 0) {
            return uVar4;
          }
          goto LAB_14001ab93;
        }
        lVar1 = local_res8 + lVar7;
        lVar7 = lVar1 + 2;
        if (*(short *)((longlong)psVar6 + ((local_res8 & 0xfffffffffffffffe) - 2)) == 0x5c) {
          lVar7 = lVar1;
        }
      }
    }
    else {
      if (sVar2 == 2) {
        uVar3 = psVar8[10];
LAB_14001ab22:
        psVar6 = (short *)((ulonglong)uVar3 + (longlong)psVar8);
        goto LAB_14001ab2b;
      }
      if ((sVar2 == 3) || (sVar2 == 4)) {
        uVar3 = psVar8[8];
        goto LAB_14001ab22;
      }
    }
    psVar8 = (short *)((longlong)psVar8 + (ulonglong)(ushort)psVar8[1]);
  } while( true );
}



===== DfscRmReferralTargetSortFunc @ 14001abc0 =====

undefined8 DfscRmReferralTargetSortFunc(longlong *param_1,longlong *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *param_1;
  uVar1 = *(uint *)(*param_2 + 4);
  if (*(uint *)(lVar2 + 4) < uVar1) {
    uVar3 = 0xffffffff;
  }
  else if (uVar1 < *(uint *)(lVar2 + 4)) {
    uVar3 = 1;
  }
  else {
    uVar3 = RtlCompareUnicodeString
                      (lVar2 + 0x60,*param_2 + 0x60,CONCAT71((int7)((ulonglong)lVar2 >> 8),1));
  }
  return uVar3;
}



===== DfscRmUnlinkReferral @ 14001ac04 =====

void DfscRmUnlinkReferral(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (lVar1 != 0) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar1 + 0x38,1);
    if (*(longlong *)(param_1 + 0x40) != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                  &WPP_af603b4b97893b05877342047baf7746_Traceguids,param_1,
                  (wchar_t *)(param_1 + 0x90));
      }
      *(int *)(lVar1 + 0x2c) = *(int *)(lVar1 + 0x2c) + -1;
      uVar5 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        *(int *)(lVar1 + 0x30) = *(int *)(lVar1 + 0x30) - (uint)*(ushort *)(param_1 + 2);
      }
      else if (*(uint *)(lVar1 + 0x30) < *(uint *)(param_1 + 8)) {
        *(undefined4 *)(lVar1 + 0x30) = 0xffffffff;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
          WPP_SF_DDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                     &WPP_af603b4b97893b05877342047baf7746_Traceguids,0xffffffff,
                     (char)*(undefined4 *)(param_1 + 8),(wchar_t *)(param_1 + 0x90));
        }
      }
      else {
        *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) - *(uint *)(param_1 + 8);
      }
      if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
        RtlRemoveUnicodePrefix(lVar1,param_1 + 0x48);
        *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xfffe;
      }
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
    ExReleaseResourceLite(lVar1 + 0x38);
    KeLeaveCriticalRegion();
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar1 + 0xa0,1);
    plVar6 = (longlong *)(param_1 + 0x30);
    lVar2 = *plVar6;
    if (lVar2 != 0) {
      if ((*(longlong **)(lVar2 + 8) != plVar6) ||
         (plVar3 = *(longlong **)(param_1 + 0x38), (longlong *)*plVar3 != plVar6)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      *plVar6 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0;
    }
    ExReleaseResourceLite(lVar1 + 0xa0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DfscRmCheckReferralSyntaxV1 @ 14001adcc =====

undefined8 DfscRmCheckReferralSyntaxV1(ushort param_1,short *param_2,ushort param_3,int *param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  longlong local_38 [2];
  
  uVar2 = 0;
  local_38[0] = 0;
  iVar6 = 0;
  if ((ulonglong)param_1 * 10 < (ulonglong)param_3) {
    *param_4 = 0;
    uVar5 = (uint)param_3;
    for (uVar7 = 0; uVar7 < param_1; uVar7 = uVar7 + 1) {
      if (((uVar5 < 10) || (*param_2 != 1)) || (2 < (ushort)param_2[2])) {
LAB_14001ae8c:
        uVar2 = 0xc00000c3;
        goto LAB_14001ae99;
      }
      uVar1 = param_2[1];
      if (((uVar1 < 10) || (uVar5 < uVar1)) ||
         (uVar3 = DfscRmCheckReferralString((ulonglong)(param_2 + 4),uVar1 - 8,local_38),
         (char)uVar3 == '\0')) goto LAB_14001ae8c;
      uVar4 = DfscRmCheckReferralTargetAddressSyntax(param_2 + 4,(uint)local_38[0] >> 1);
      if ((char)uVar4 == '\0') goto LAB_14001ae8c;
      uVar5 = uVar5 - uVar1;
      iVar6 = iVar6 + (uint)(ushort)local_38[0];
      param_2 = (short *)((longlong)param_2 + (ulonglong)uVar1);
    }
    *param_4 = iVar6;
  }
  else {
    uVar2 = 0xc00000c3;
  }
LAB_14001ae99:
  return uVar2;
}



===== DfscRmCheckReferralSyntaxV2 @ 14001aec0 =====

undefined8
DfscRmCheckReferralSyntaxV2(ushort param_1,short *param_2,ushort param_3,undefined4 *param_4)

{
  ushort *puVar1;
  short *psVar2;
  short *psVar3;
  ulonglong uVar4;
  ushort uVar5;
  ulonglong uVar6;
  ulonglong local_res10;
  
  local_res10 = 0;
  *param_4 = 0;
  uVar6 = 0;
  uVar5 = 0;
  psVar3 = param_2;
  while( true ) {
    if (param_1 <= uVar5) {
      uVar5 = 0;
      psVar3 = param_2;
      while( true ) {
        if (param_1 <= uVar5) {
          *param_4 = (int)uVar6;
          return 0;
        }
        uVar6 = ((ulonglong)param_3 - (longlong)psVar3) + (longlong)param_2;
        if ((((*psVar3 != 2) || ((ushort)psVar3[1] < 0x16)) || (2 < (ushort)psVar3[2])) ||
           (((uVar4 = DfscRmIntegratedStringCheck((longlong)psVar3,psVar3[8],uVar6,(longlong *)0x0),
             (char)uVar4 == '\0' ||
             (uVar4 = DfscRmIntegratedStringCheck((longlong)psVar3,psVar3[9],uVar6,(longlong *)0x0),
             (char)uVar4 == '\0')) ||
            ((uVar4 = DfscRmIntegratedStringCheck
                                ((longlong)psVar3,psVar3[10],uVar6,(longlong *)&local_res10),
             uVar6 = local_res10, (char)uVar4 == '\0' ||
             (uVar4 = DfscRmCheckReferralTargetAddressSyntax
                                ((short *)((ulonglong)(ushort)psVar3[10] + (longlong)psVar3),
                                 (uint)(local_res10 >> 1) & 0x7fffffff), (char)uVar4 == '\0'))))))
        break;
        uVar5 = uVar5 + 1;
        psVar3 = (short *)((longlong)psVar3 + (ulonglong)(ushort)psVar3[1]);
      }
      return 0xc00000c3;
    }
    if (psVar3 < param_2) {
      return 0xc00000c3;
    }
    if (psVar3 + 0xb < param_2) {
      return 0xc00000c3;
    }
    psVar2 = (short *)((ulonglong)param_3 + (longlong)param_2);
    if (psVar2 <= psVar3) {
      return 0xc00000c3;
    }
    if (psVar2 < psVar3 + 0xb) {
      return 0xc00000c3;
    }
    puVar1 = (ushort *)(psVar3 + 1);
    psVar3 = (short *)((longlong)psVar3 + (ulonglong)*puVar1);
    if (psVar2 < psVar3) {
      return 0xc00000c3;
    }
    if (*puVar1 < 0x16) break;
    uVar5 = uVar5 + 1;
  }
  return 0xc00000c3;
}



===== DfscRegisterMup @ 14001b01c =====

void DfscRegisterMup(void)

{
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  code *local_18;
  ulonglong local_10;
  
  local_24 = 0;
  local_10 = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_38,L"\\Device\\DfsClient");
  local_10 = local_10 | 0x100000007;
  local_20 = DfscSurrogatePreProcess;
  local_28 = 0x2010020;
  local_18 = DfscSurrogatePostProcess;
  MupSurrogateRegisterProviderEx(&local_38,2,&local_28);
  return;
}



===== DfscInitializeTimer @ 14001b098 =====

undefined8 DfscInitializeTimer(void)

{
  if (DAT_14000d794 != 0) {
    g_DfscTimerWorkItem = IoAllocateWorkItem(DAT_14000d648);
    if (g_DfscTimerWorkItem == 0) {
      return 0xc000009a;
    }
    KeInitializeSpinLock(&g_DfscTimerSpinLock);
    KeInitializeDpc(&g_DfscTimerDpc,DfscTimerDispatch,0);
    KeInitializeTimer(&g_DfscTimer);
    g_DfscTimerCompleteEvent = 0;
    g_DfscTimerSet = 1;
    g_DfscTimerPosted = 0;
    KeSetCoalescableTimer(&g_DfscTimer,(ulonglong)DAT_14000d794 * -10000000,0,1000,&g_DfscTimerDpc);
  }
  return 0;
}



===== DfscpContainerCleanupNotify @ 14001b170 =====

void DfscpContainerCleanupNotify(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    param_3 = &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids;
    param_2 = 0;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,param_1);
  }
  KeEnterCriticalRegion();
  uVar4 = CONCAT71((int7)((ulonglong)param_2 >> 8),1);
  ExAcquireResourceExclusiveLite(&DAT_14000d658);
  plVar1 = (longlong *)*param_1;
  if (plVar1 != param_1) {
    if (((longlong *)plVar1[1] != param_1) ||
       (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = (longlong)plVar1;
    plVar1[1] = (longlong)plVar2;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
  }
  ExReleaseResourceLite(&DAT_14000d658);
  KeLeaveCriticalRegion();
  if (param_1[0x10] != 0) {
    DfscCacheDelete(param_1[0x10],uVar4,param_3);
    param_1[0x10] = 0;
  }
  if (param_1[0x11] != 0) {
    DfscCacheDelete(param_1[0x11],uVar4,param_3);
    param_1[0x11] = 0;
  }
  if (param_1[0x20] != 0) {
    DfscNetUseTableFree((longlong)param_1,param_1[0x20],param_3);
    param_1[0x20] = 0;
  }
  if (param_1[0x21] != 0) {
    DfscNetUseTableFree((longlong)param_1,param_1[0x21],param_3);
    param_1[0x21] = 0;
  }
  if (param_1[0x12] != 0) {
    DfscCredTableFree(param_1[0x12]);
    param_1[0x12] = 0;
  }
  ExDeleteResourceLite(param_1 + 2);
  ExDeleteResourceLite(param_1 + 0x13);
  return;
}



===== DfscpContainerCreateNotify @ 14001b2e0 =====

/* WARNING: Removing unreachable block (ram,0x00014001b6ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DfscpContainerCreateNotify(undefined8 param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined2 uVar7;
  undefined7 uVar9;
  undefined8 *puVar8;
  undefined1 *puVar10;
  undefined8 *local_res10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10 = (undefined8 *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,param_1);
  }
  uVar2 = PsCreateSiloContext(param_1,0x110,0x200,DfscpContainerCleanupNotify);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    puVar10 = auStack_68;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar10 = auStack_68, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,param_1,(char)uVar2);
      puVar10 = auStack_68;
    }
    goto LAB_14001b6e3;
  }
  memset((void *)0x0,0,0x110);
  uRam0000000000000008 = 0;
  uRam0000000000000000 = 0;
  ExInitializeResourceLite(0x10);
  ExInitializeResourceLite(0x98);
  uVar4 = PsAttachSiloToCurrentThread(param_1);
  RtlInitUnicodeString(&local_28,L"\\Device\\DfsClient");
  RtlInitUnicodeString(&local_38,L"\\Dfs");
  IoDeleteSymbolicLink(&local_38);
  uVar2 = IoCreateSymbolicLink(&local_38);
  uVar5 = (ulonglong)uVar2;
  PsDetachSiloFromCurrentThread(uVar4);
  if ((int)uVar2 < 0) {
    puVar10 = auStack_68;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar10 = auStack_68, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,uVar2);
      puVar10 = auStack_68;
    }
    goto LAB_14001b6e3;
  }
  uVar4 = 0;
  uVar5 = DfscCacheInitialize((undefined8 *)0x80,'\0',_DAT_14000d7a4 << 10);
  uVar2 = (uint)uVar5;
  uVar5 = uVar5 & 0xffffffff;
  if ((int)uVar2 < 0) {
    puVar10 = auStack_68;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar10 = auStack_68, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      uVar7 = 0xc;
      puVar10 = auStack_68;
LAB_14001b674:
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar10 + -8) = 0x14001b683;
      WPP_SF_D(uVar4,uVar7,&WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,uVar2);
    }
  }
  else {
    uVar9 = (undefined7)((ulonglong)uVar4 >> 8);
    uVar5 = DfscCacheInitialize((undefined8 *)0x88,'\x01',DAT_14000d7a0 << 10);
    uVar2 = (uint)uVar5;
    uVar5 = uVar5 & 0xffffffff;
    if ((int)uVar2 < 0) {
      puVar10 = auStack_68;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar10 = auStack_68, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        uVar7 = 0xd;
        puVar10 = auStack_68;
        goto LAB_14001b674;
      }
    }
    else {
      uVar5 = DfscNetUseTableInitialize((undefined8 *)0x100);
      uVar2 = (uint)uVar5;
      uVar5 = uVar5 & 0xffffffff;
      if ((int)uVar2 < 0) {
        puVar10 = auStack_68;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (puVar10 = auStack_68, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
          uVar7 = 0xe;
          puVar10 = auStack_68;
          goto LAB_14001b674;
        }
      }
      else {
        uVar5 = DfscNetUseTableInitialize((undefined8 *)0x108);
        uVar2 = (uint)uVar5;
        uVar5 = uVar5 & 0xffffffff;
        if ((int)uVar2 < 0) {
          puVar10 = auStack_68;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (puVar10 = auStack_68, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
            uVar7 = 0xf;
            puVar10 = auStack_68;
            goto LAB_14001b674;
          }
        }
        else {
          uVar2 = DfscCredTableInitialize((undefined8 *)0x90);
          uVar5 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            puVar10 = auStack_68;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (puVar10 = auStack_68, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
              uVar7 = 0x10;
              puVar10 = auStack_68;
              goto LAB_14001b674;
            }
          }
          else {
            KeEnterCriticalRegion();
            ExAcquireResourceExclusiveLite(&DAT_14000d658,CONCAT71(uVar9,1));
            puVar10 = auStack_68;
            puVar8 = &DAT_14000d828;
            puVar6 = DAT_14000d830;
            if ((undefined8 *)*DAT_14000d830 != &DAT_14000d828) {
              puVar6 = (undefined8 *)0x3;
              pcVar1 = (code *)swi(0x29);
              local_res10 = (undefined8 *)(*pcVar1)();
              puVar10 = auStack_60;
            }
            local_res10[1] = puVar6;
            *local_res10 = puVar8;
            *puVar6 = local_res10;
            *(undefined8 *)(puVar10 + -8) = 0x14001b617;
            DAT_14000d830 = local_res10;
            ExReleaseResourceLite(&DAT_14000d658);
            *(undefined8 *)(puVar10 + -8) = 0x14001b623;
            KeLeaveCriticalRegion();
            *(undefined8 *)(puVar10 + -8) = 0x14001b636;
            uVar3 = PsGetSiloMonitorContextSlot(DAT_14000d838);
            *(undefined8 *)(puVar10 + -8) = 0x14001b64b;
            uVar2 = PsInsertPermanentSiloContext(param_1,uVar3,0);
            uVar5 = (ulonglong)uVar2;
            if (-1 < (int)uVar2) goto LAB_14001b6e3;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
              uVar7 = 0x11;
              goto LAB_14001b674;
            }
          }
        }
      }
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x14001b68d;
  uVar4 = PsAttachSiloToCurrentThread(param_1);
  *(undefined8 *)(puVar10 + -8) = 0x14001b6a0;
  IoDeleteSymbolicLink(&local_38);
  *(undefined8 *)(puVar10 + -8) = 0x14001b6af;
  PsDetachSiloFromCurrentThread(uVar4);
LAB_14001b6e3:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(int *)(puVar10 + 0x20) = (int)uVar5;
    *(undefined8 *)(puVar10 + -8) = 0x14001b725;
    WPP_SF_qd(uVar4,0x13,&WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,param_1,puVar10[0x20]);
  }
  return uVar5;
}



===== DfscpContainerTerminateNotify @ 14001b750 =====

void DfscpContainerTerminateNotify(undefined8 param_1)

{
  longlong *plVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong **pplVar6;
  longlong *local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = (longlong *)0x0;
  uVar3 = PsGetSiloMonitorContextSlot(DAT_14000d838);
  pplVar6 = local_res10;
  PsGetPermanentSiloContext(param_1,uVar3);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    pplVar6 = (longlong **)&WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,param_1,(char)local_res10[0]);
  }
  if (local_res10[0] != (longlong *)0x0) {
    local_18 = 0;
    uStack_10 = 0;
    uVar4 = PsAttachSiloToCurrentThread(param_1);
    RtlInitUnicodeString(&local_18,L"\\Dfs");
    IoDeleteSymbolicLink(&local_18);
    PsDetachSiloFromCurrentThread(uVar4);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000d658,1);
    plVar5 = (longlong *)*local_res10[0];
    if (plVar5 != local_res10[0]) {
      if (((longlong *)plVar5[1] != local_res10[0]) ||
         (plVar1 = (longlong *)local_res10[0][1], (longlong *)*plVar1 != local_res10[0])) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      *plVar1 = (longlong)plVar5;
      plVar5[1] = (longlong)plVar1;
      local_res10[0][1] = (longlong)local_res10[0];
      *local_res10[0] = (longlong)local_res10[0];
    }
    ExReleaseResourceLite(&DAT_14000d658);
    KeLeaveCriticalRegion();
    if (local_res10[0][0x10] != 0) {
      DfscCachePurge(local_res10[0][0x10],plVar5,(undefined *)pplVar6);
    }
    if (local_res10[0][0x11] != 0) {
      DfscCachePurge(local_res10[0][0x11],plVar5,(undefined *)pplVar6);
    }
  }
  return;
}



===== DfscPopulateDomainNameCache @ 14001b8d4 =====

uint DfscPopulateDomainNameCache(undefined8 param_1,longlong param_2)

{
  wchar_t *pwVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  wchar_t local_158 [8];
  undefined8 local_148;
  undefined8 uStack_140;
  longlong local_138;
  short local_130 [48];
  short local_d0 [68];
  longlong local_48;
  undefined8 local_40;
  
  uVar2 = 0;
  local_148 = 0;
  uStack_140 = 0;
  memset(&local_138,0,0x108);
  local_158[0] = L'\0';
  local_158[1] = L'\0';
  local_158[2] = L'\0';
  local_158[3] = L'\0';
  local_158[4] = L'\0';
  local_158[5] = L'\0';
  local_158[6] = L'\0';
  local_158[7] = L'\0';
  lVar3 = DfscGetCurrentDcContext(param_2);
  if (lVar3 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids);
    }
    return 0;
  }
  pwVar1 = *(wchar_t **)(lVar3 + 8);
  if (pwVar1 != (wchar_t *)0x0) {
    RtlInitUnicodeString(local_158,0);
    DfscInitDfsPath(local_158,local_130);
    DfscInitDfsPath(local_158,local_d0);
    local_48 = param_2;
    local_40 = param_1;
    RtlInitUnicodeString(&local_148,pwVar1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,(wchar_t *)&local_148);
    }
    uVar2 = DfscGetDomainReferral(&local_138,(ushort *)&local_148,(wchar_t *)(lVar3 + 0x10));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,uVar2);
    }
    pwVar6 = *(wchar_t **)(lVar3 + 0x30);
    pwVar7 = pwVar1;
    if ((int)uVar2 < 0) {
      do {
        pwVar7 = pwVar6;
        if (*(wchar_t **)(lVar3 + 0x38) < pwVar7) goto LAB_14001bbab;
        pwVar6 = pwVar7;
        if (pwVar7 != pwVar1) {
          memset(&local_138,0,0x108);
          RtlInitUnicodeString(local_158,0);
          DfscInitDfsPath(local_158,local_130);
          DfscInitDfsPath(local_158,local_d0);
          RtlInitUnicodeString(&local_148,pwVar7);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,(wchar_t *)&local_148);
          }
          uVar2 = DfscGetDomainReferral(&local_138,(ushort *)&local_148,(wchar_t *)(lVar3 + 0x10));
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                     &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,uVar2);
          }
        }
        for (; *pwVar6 != L'\0'; pwVar6 = pwVar6 + 1) {
        }
        pwVar6 = pwVar6 + 1;
      } while ((int)uVar2 < 0);
    }
    iVar5 = 0;
    lVar4 = DfscGetDomainCache(param_2);
    if (pwVar7 != *(wchar_t **)(lVar3 + 8)) {
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0) {
          WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,pwVar7);
        }
        iVar5 = 0;
      }
      *(wchar_t **)(lVar3 + 8) = pwVar7;
    }
    if (*(int *)(lVar4 + 0x2c) == iVar5) {
      uVar2 = 0xc00000c4;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001bbd4;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids);
      }
    }
  }
LAB_14001bbab:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,uVar2);
  }
LAB_14001bbd4:
  DfscReleaseDcContext(lVar3);
  return uVar2;
}



===== DfscRmValidateRootIterate @ 14001bc10 =====

undefined8 DfscRmValidateRootIterate(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  uint *puVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  plVar1 = param_1 + 1;
  plVar4 = (longlong *)*param_1;
  plVar2 = param_1 + 2;
  if (*plVar1 == 0) {
    uVar6 = DfscGetRootReferral(plVar4,(ushort *)(plVar4 + 0xd),0,param_1[3],plVar2);
    goto LAB_14001bce7;
  }
  uVar7 = DfscIterateAndGetReferral(0,plVar4,1,*plVar1,param_1[3],plVar2);
  if ((-1 < (int)uVar7) ||
     (lVar5 = *plVar1, (*(byte *)(*(longlong *)(lVar5 + 0x10) + 0x10) & 8) == 0))
  goto LAB_14001bce9;
  uVar8 = DfscIsErrorInList(uVar7,0x14000d110,0x1e);
  if ((char)uVar8 == '\0') goto LAB_14001bce9;
  puVar3 = (uint *)(lVar5 + 8);
  *puVar3 = *puVar3 | 8;
  uVar6 = DfscValidateReferral(*param_1,0,plVar1);
  if (-1 < (int)uVar6) {
    if (*plVar1 != 0) {
      uVar6 = DfscIterateAndGetReferral(0,(longlong *)*param_1,1,*plVar1,param_1[3],plVar2);
      if ((int)uVar6 < 0) goto LAB_14001bce7;
    }
    if (*plVar2 == 0) goto LAB_14001bce9;
  }
LAB_14001bce7:
  uVar7 = uVar6;
LAB_14001bce9:
  *(uint *)((longlong)param_1 + 0x24) = uVar7;
  return 0xffffffff;
}



===== DfscGetDomainReferral @ 14001bd0c =====

uint DfscGetDomainReferral(longlong *param_1,ushort *param_2,wchar_t *param_3)

{
  uint uVar1;
  wchar_t local_18 [8];
  
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  local_18[2] = L'\0';
  local_18[3] = L'\0';
  local_18[4] = L'\0';
  local_18[5] = L'\0';
  local_18[6] = L'\0';
  local_18[7] = L'\0';
  RtlInitUnicodeString(local_18,0);
  uVar1 = DfscRmGetReferral(0,param_1,local_18,param_2,param_3,0,(undefined8 *)0x0);
  if (-1 < (int)uVar1) {
    *(undefined2 *)((longlong)param_1 + 0xda) = 0;
    RtlInitUnicodeString(param_1 + 0x19,0);
  }
  return uVar1;
}



===== DfscRmGetDomainReferral @ 14001bda8 =====

uint DfscRmGetDomainReferral(longlong param_1,ushort *param_2,longlong param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  uint local_res20 [2];
  undefined2 *local_18 [2];
  
  local_18[0] = (undefined2 *)0x0;
  local_res20[0] = 0;
  uVar2 = DfscRmGenerateReferral(param_1,param_2,param_3,3,(longlong *)local_18,local_res20);
  puVar1 = local_18[0];
  if (-1 < (int)uVar2) {
    *local_18[0] = 0;
    uVar2 = DfscRmGenerateDomainReferralsFromResponse(param_1,(longlong)local_18[0],local_res20[0]);
  }
  if (puVar1 != (undefined2 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_af603b4b97893b05877342047baf7746_Traceguids,puVar1);
    }
    ExFreePoolWithTag(puVar1,0);
  }
  return uVar2;
}



===== DfscGetRootReferral @ 14001be70 =====

uint DfscGetRootReferral(longlong *param_1,ushort *param_2,longlong param_3,longlong param_4,
                        undefined8 *param_5)

{
  ushort uVar1;
  short *psVar2;
  uint uVar3;
  ushort uVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  
  lVar6 = 0;
  pwVar5 = (wchar_t *)0x0;
  if (param_3 != 0) {
    pwVar5 = (wchar_t *)(*(longlong *)(param_3 + 0x10) + 0x80);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_55706db06074317498eaf8c01331c814_Traceguids,pwVar5,
                (char)*(longlong *)(param_3 + 0x10));
    }
  }
  uVar3 = DfscRmGetReferral(1,param_1,(wchar_t *)(param_1 + 0x13),param_2,pwVar5,param_4,param_5);
  if (-1 < (int)uVar3) {
    psVar2 = (short *)param_1[0xc];
    if (((*psVar2 == 0x5c) && (2 < *(ushort *)(param_1 + 0xb))) && (psVar2[1] == 0x5c)) {
      *(short *)((longlong)param_1 + 0xda) = *(short *)((longlong)param_1 + 0xda) + 2;
    }
    uVar4 = (short)param_1[0xb] - *(ushort *)((longlong)param_1 + 0xda);
    *(ushort *)((longlong)param_1 + 0xca) = uVar4;
    *(ushort *)(param_1 + 0x19) = uVar4;
    if (uVar4 != 0) {
      lVar6 = (longlong)psVar2 + (ulonglong)*(ushort *)((longlong)param_1 + 0xda);
    }
    param_1[0x1a] = lVar6;
    uVar1 = *(ushort *)(param_1 + 0x1b);
    if (uVar4 < uVar1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar1,(char)uVar4);
      }
      *(short *)(param_1 + 0x1b) = (short)param_1[0x19];
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar1,(char)uVar4);
    }
  }
  return uVar3;
}



===== DfscCmGetRootReferralState @ 14001c050 =====

int DfscCmGetRootReferralState(longlong param_1)

{
  longlong *plVar1;
  ushort uVar2;
  uint uVar3;
  short *psVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  RPC_STATUS RVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 uVar12;
  ushort uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  ulonglong local_res8;
  longlong local_res10;
  undefined8 local_48;
  longlong lStack_40;
  
  iVar14 = 0;
  plVar1 = (longlong *)(param_1 + 0x110);
  lVar11 = *plVar1;
  local_res10 = 0;
  local_res8 = 0;
  iVar16 = 9;
  local_48 = 0;
  lStack_40 = 0;
  if ((lVar11 == 0) || (*(int *)(*(longlong *)(lVar11 + 0x10) + 0xc) != 0)) {
    if (1 < *(uint *)(param_1 + 0x124)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
      *(undefined4 *)(param_1 + 0x13c) = 0xc00000be;
      return 9;
    }
    uVar7 = DfscRmGetReferral(1,(longlong *)(param_1 + 8),(wchar_t *)(param_1 + 0xa0),
                              (ushort *)(param_1 + 0x70),(wchar_t *)0x0,0,plVar1);
    if (-1 < (int)uVar7) {
      psVar4 = *(short **)(param_1 + 0x68);
      if (((*psVar4 == 0x5c) && (2 < *(ushort *)(param_1 + 0x60))) && (psVar4[1] == 0x5c)) {
        *(short *)(param_1 + 0xe2) = *(short *)(param_1 + 0xe2) + 2;
      }
      uVar13 = *(short *)(param_1 + 0x60) - *(ushort *)(param_1 + 0xe2);
      *(ushort *)(param_1 + 0xd2) = uVar13;
      *(ushort *)(param_1 + 0xd0) = uVar13;
      if (uVar13 == 0) {
        lVar11 = 0;
      }
      else {
        lVar11 = (ulonglong)*(ushort *)(param_1 + 0xe2) + (longlong)psVar4;
      }
      *(longlong *)(param_1 + 0xd8) = lVar11;
      uVar2 = *(ushort *)(param_1 + 0xe0);
      if (uVar13 < uVar2) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar2,(char)uVar13);
        }
        *(undefined2 *)(param_1 + 0xe0) = *(undefined2 *)(param_1 + 0xd0);
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar2,(char)uVar13);
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)uVar7);
    }
    if ((((uVar7 == 0xc0000201) || (uVar7 == 0xc000018b)) || (uVar7 == 0xc00000bb)) &&
       ((*(uint *)(param_1 + 0xf0) & 1) != 0)) {
      RtlInitUnicodeString(&local_48,0);
      lStack_40 = ExAllocatePool2(0x102,0x208,0x4d436644);
      if (lStack_40 == 0) {
        uVar7 = 0xc000009a;
      }
      else {
        local_48 = CONCAT44(local_48._4_4_,0x2080000);
        RVar9 = DfscGetDCName(param_1 + 0x70,&local_48,0x11);
        if ((RVar9 == 0) || (-1 < (int)uVar7)) {
          *(undefined4 *)(param_1 + 0x144) = 1;
          *(undefined2 *)(param_1 + 0xe2) = 0;
          RtlInitUnicodeString(param_1 + 0xd0,0);
          uVar10 = DfscRmGenerateDomainDcReferralFromDCName
                             ((ushort *)(param_1 + 0x70),(wchar_t *)&local_48,&local_res8,0,0);
          uVar7 = (uint)uVar10;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                      &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)uVar10);
          }
        }
      }
      if (lStack_40 != 0) {
        ExFreePoolWithTag(lStack_40,0);
      }
      if (uVar7 == 0) {
        *(undefined4 *)(param_1 + 0x13c) = 0;
        lVar11 = DfscDomainCacheStore(*(longlong *)(param_1 + 0xf8),local_res8);
        uVar12 = DfscRmCreateRefContext(lVar11,'\0',&local_res10);
        if (-1 < (int)uVar12) {
          *plVar1 = local_res10;
        }
        if ((*(int *)(lVar11 + 0xc) == 0) &&
           (uVar12 = DfscIsSpecialShare((ushort *)(param_1 + 0x20)), (char)uVar12 != '\0')) {
          return 4;
        }
        return 3;
      }
    }
    if ((int)uVar7 < 0) {
      iVar15 = 0x1d;
      while( true ) {
        iVar8 = (iVar15 + iVar14) / 2;
        uVar3 = *(uint *)(&DfscFailoverErrorList + (longlong)iVar8 * 4);
        if (uVar3 == uVar7) break;
        iVar6 = iVar8 + -1;
        if ((int)uVar3 < (int)uVar7) {
          iVar6 = iVar15;
        }
        iVar15 = iVar6;
        if ((int)uVar3 <= (int)uVar7) {
          iVar14 = iVar8 + 1;
        }
        if (iVar15 < iVar14) {
          *(uint *)(param_1 + 0x13c) = uVar7;
          return 9;
        }
      }
      if (*(int *)(param_1 + 0x144) == 0) {
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                     &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                     &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
          }
        }
        *(undefined4 *)(param_1 + 0x144) = 2;
        *(uint *)(param_1 + 0x13c) = uVar7;
        return 9;
      }
    }
    goto LAB_14001c1a2;
  }
  *(undefined4 *)(param_1 + 0x144) = 1;
  *plVar1 = 0;
  uVar7 = DfscIterateAndGetReferral(param_1,(longlong *)(param_1 + 8),1,lVar11,0,plVar1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)uVar7);
  }
  if (uVar7 == 0) {
    if (*plVar1 == 0) {
      uVar3 = *(uint *)(param_1 + 0x140);
      if ((((int)uVar3 < 0) &&
          (uVar7 = uVar3, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                  &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)uVar3);
      }
      goto LAB_14001c39c;
    }
LAB_14001c3ed:
    DfscReferralRelease(lVar11);
  }
  else {
LAB_14001c39c:
    if (*plVar1 != 0) goto LAB_14001c3ed;
    *plVar1 = lVar11;
    lVar5 = *(longlong *)(lVar11 + 0x10);
    if ((((*(byte *)(lVar5 + 0x10) & 8) != 0) &&
        (uVar10 = DfscIsErrorInList(uVar7,0x14000d110,0x1e), (char)uVar10 != '\0')) &&
       ((2 < *(int *)(param_1 + 0x124) - 2U &&
        ((*(char *)(lVar5 + 0x13) != '\0' || (*(ushort *)(lVar11 + 0x26) < 10)))))) {
      *(uint *)(lVar11 + 8) = *(uint *)(lVar11 + 8) | 8;
      iVar16 = 1;
    }
  }
  if (uVar7 == 0xc0000001) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
    }
    uVar7 = 0xc000003a;
  }
LAB_14001c1a2:
  if (uVar7 == 0) {
    iVar16 = 9;
    if (*(int *)(param_1 + 0x124) != 1) {
      iVar16 = 5;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
    }
    *(undefined4 *)(param_1 + 0x144) = 1;
  }
  *(uint *)(param_1 + 0x13c) = uVar7;
  if (iVar16 == 1) {
    *(uint *)(param_1 + 0x140) = uVar7;
  }
  return iVar16;
}



===== DfscRmGetReferral @ 14001c710 =====

uint DfscRmGetReferral(int param_1,longlong *param_2,wchar_t *param_3,ushort *param_4,
                      wchar_t *param_5,longlong param_6,undefined8 *param_7)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  undefined4 *_Dst;
  void *_Dst_00;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  int iVar10;
  char cStack0000000000000040;
  wchar_t *in_stack_ffffffffffffff30;
  ushort local_c8 [2];
  ushort local_c4 [2];
  ulonglong local_c0;
  wchar_t local_b8 [4];
  longlong local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  longlong local_88;
  undefined4 *local_80;
  wchar_t *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 *local_60;
  undefined1 local_58;
  undefined4 local_57;
  undefined2 local_53;
  undefined1 local_51;
  longlong local_50;
  undefined8 local_48;
  
  puVar9 = (undefined4 *)0x0;
  uVar7 = 0;
  cStack0000000000000040 = '\0';
  local_c0 = 0;
  local_a0 = 0;
  local_b8[2] = L'\0';
  local_b8[3] = L'\0';
  local_c8[0] = 0;
  local_c4[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    in_stack_ffffffffffffff30 = param_5;
    WPP_SF_qZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_2,param_3,param_5);
  }
  local_b0 = 0;
  local_b8[0] = L'\0';
  local_b8[1] = L'\0';
  local_a8 = 0;
  local_98 = 0;
  uStack_90 = 0;
  _Dst = (undefined4 *)ExAllocatePool2(0x102,0x40,0x63436644);
  if (_Dst == (undefined4 *)0x0) {
LAB_14001cd15:
    uVar3 = 0xc000009a;
    DfscConnFree((longlong)_Dst);
    goto LAB_14001c8d1;
  }
  memset(_Dst,0,0x40);
  if (param_4[1] == 0) {
    _Dst_00 = (void *)0x0;
  }
  else {
    _Dst_00 = (void *)ExAllocatePool2(0x102,param_4[1],0x76436644);
    *(void **)(_Dst + 4) = _Dst_00;
    if (_Dst_00 == (void *)0x0) goto LAB_14001cd15;
  }
  iVar10 = 1;
  _Dst[1] = 1;
  *_Dst = 0x408105;
  if ((*param_4 == 0) || (param_4[1] == 0)) {
    param_4[1] = 0;
    *(undefined2 *)(_Dst + 2) = 0;
  }
  else {
    memmove(_Dst_00,*(void **)(param_4 + 4),(ulonglong)*param_4);
    *(ushort *)(_Dst + 2) = *param_4;
    *(ushort *)((longlong)_Dst + 10) = param_4[1];
  }
  *(longlong *)(_Dst + 0xe) = param_2[0x1c];
  uVar3 = RtlInitUnicodeStringEx(&local_98);
  if ((int)uVar3 < 0) {
LAB_14001c87c:
    DfscReleaseIpcConnection((longlong)_Dst);
    _Dst = (undefined4 *)0x0;
  }
  else {
    puVar9 = _Dst + 6;
    *(undefined2 *)puVar9 = 0;
    sVar2 = (short)local_98 + 0x12 + *param_4;
    *(short *)((longlong)_Dst + 0x1a) = sVar2;
    lVar4 = ExAllocatePool2(0x102,sVar2,0x70436644);
    *(longlong *)(_Dst + 8) = lVar4;
    if (lVar4 == 0) {
      *puVar9 = 0;
      uVar3 = 0xc000009a;
      goto LAB_14001c87c;
    }
    RtlAppendUnicodeStringToString(puVar9,&local_98);
    RtlAppendUnicodeToString(puVar9,L"\\");
    RtlAppendUnicodeStringToString(puVar9,param_4);
    RtlAppendUnicodeToString(puVar9);
    local_58 = 0;
    if ((longlong *)*param_2 != (longlong *)0x0) {
      local_58 = 0;
      if ((*(uint *)(*(longlong *)(*(longlong *)*param_2 + 0xb8) + 0x10) & 0x400) != 0) {
        local_58 = 1;
      }
    }
    local_6c = 0;
    local_57 = 0;
    local_53 = 0;
    local_51 = 0;
    local_48 = 0;
    local_88 = param_2[0x1f];
    local_78 = param_5;
    local_70 = (undefined4)param_2[0x1d];
    local_68 = *(undefined8 *)(_Dst + 0xe);
    local_60 = &local_a8;
    local_50 = param_2[0x20];
    local_80 = puVar9;
    uVar3 = KeExpandKernelStackAndCalloutEx
                      (DfscConnOpenIpcConnectionCallout,&local_88,0x6000,0,DAT_14000d778);
    if (uVar3 == 0) {
      uVar3 = (uint)local_48;
    }
    if ((int)uVar3 < 0) goto LAB_14001c87c;
    *(undefined8 *)(_Dst + 10) = local_a8;
    in_stack_ffffffffffffff30 = (wchar_t *)0x0;
    uVar3 = ObReferenceObjectByHandle(local_a8,0,0,0,_Dst + 0xc);
    if ((int)uVar3 < 0) goto LAB_14001c87c;
  }
  uVar8 = 0;
  if (-1 < (int)uVar3) {
    if ((((param_3 != (wchar_t *)0x0) && (*param_3 != L'\0')) &&
        (*(short **)(param_3 + 4) != (short *)0x0)) && (**(short **)(param_3 + 4) != 0)) {
      KeEnterCriticalRegion();
      ExAcquireResourceSharedLite(&DAT_14000d7c0);
      if (DAT_14000d7ae != '\0') {
        DfscGetIpcConnectionSmbProtocolVersion((longlong)_Dst,local_c8,local_c4);
        if ((2 < local_c8[0]) || ((local_c8[0] == 2 && (1 < local_c4[0])))) {
          DfscGetSiteName(local_b8);
          cStack0000000000000040 = '\x01';
        }
      }
      ExReleaseResourceLite(&DAT_14000d7c0);
      KeLeaveCriticalRegion();
    }
    if (param_6 != 0) {
      uVar8 = *(ulonglong *)(param_6 + 0x10);
    }
    if (param_1 == 1) {
LAB_14001caa1:
      uVar3 = DfscRmGetNormalReferral
                        ((longlong)param_2,param_3,local_b8,(longlong)_Dst,&local_c0,
                         (longlong)in_stack_ffffffffffffff30);
      uVar7 = local_c0;
      if ((int)uVar3 < 0) {
LAB_14001cac7:
        uVar7 = local_c0;
      }
      else {
        if ((param_1 == 1) && (*(short *)((longlong)param_2 + 0xda) == 0)) {
          *(short *)((longlong)param_2 + 0xda) = (short)param_2[0x13];
        }
        if ((((param_5 == (wchar_t *)0x0) || (*param_5 == L'\0')) ||
            (*(short **)(param_5 + 4) == (short *)0x0)) || (**(short **)(param_5 + 4) == 0)) {
          iVar10 = 0;
        }
        uVar6 = DfscRmSetReferralType(local_c0,param_1,iVar10);
        uVar3 = (uint)uVar6;
        if (-1 < (int)uVar3) {
          KeEnterCriticalRegion();
          ExAcquireResourceSharedLite(&DAT_14000d7c0,1);
          if ((cStack0000000000000040 == '\0') ||
             (cVar1 = RtlEqualUnicodeString(&DAT_14000d7b0,local_b8,1), cVar1 != '\0')) {
            uVar7 = DfscRefCacheStore(param_2[0x1e],uVar8,uVar7);
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                     &WPP_55706db06074317498eaf8c01331c814_Traceguids,uVar7);
          }
LAB_14001ccd2:
          ExReleaseResourceLite(&DAT_14000d7c0);
          KeLeaveCriticalRegion();
          goto LAB_14001cada;
        }
      }
    }
    else {
      if (param_1 == 0) {
        if (((param_3 == (wchar_t *)0x0) || (*param_3 == L'\0')) ||
           ((*(short **)(param_3 + 4) == (short *)0x0 || (**(short **)(param_3 + 4) == 0)))) {
          uVar3 = DfscRmGetDomainReferral((longlong)param_2,(ushort *)param_3,(longlong)_Dst);
          goto LAB_14001c8c9;
        }
        uVar3 = DfscRmGetDomainDcReferral
                          ((ulonglong)param_2,(ushort *)param_3,local_b8,(longlong)_Dst,&local_c0);
        uVar7 = local_c0;
        if (-1 < (int)uVar3) {
          *(undefined4 *)(local_c0 + 0x80) = *(undefined4 *)(local_c0 + 0x90);
          *(undefined4 *)(local_c0 + 0x84) = *(undefined4 *)(local_c0 + 0x94);
          *(undefined4 *)(local_c0 + 0x88) = *(undefined4 *)(local_c0 + 0x98);
          *(undefined4 *)(local_c0 + 0x8c) = *(undefined4 *)(local_c0 + 0x9c);
          *(undefined4 *)(local_c0 + 0xc) = 0;
          KeEnterCriticalRegion();
          ExAcquireResourceSharedLite(&DAT_14000d7c0,1);
          cVar1 = RtlEqualUnicodeString(&DAT_14000d7b0,local_b8,1);
          if (cVar1 != '\0') {
            DfscDomainCacheStore(param_2[0x1e],uVar7);
          }
          goto LAB_14001ccd2;
        }
        goto LAB_14001cac7;
      }
      if (param_1 == 2) goto LAB_14001caa1;
LAB_14001cada:
      uVar5 = DfscRmCreateRefContext(uVar7,'\0',&local_a0);
      uVar3 = (uint)uVar5;
      if ((-1 < (int)uVar3) && (uVar7 = 0, param_7 != (undefined8 *)0x0)) {
        *param_7 = local_a0;
      }
    }
  }
LAB_14001c8c9:
  puVar9 = _Dst;
LAB_14001c8d1:
  if (local_b0 != 0) {
    ExFreePoolWithTag(local_b0,0);
  }
  if (((int)uVar3 < 0) && (uVar7 != 0)) {
    DfscRmDereferenceReferral(uVar7);
  }
  if (puVar9 != (undefined4 *)0x0) {
    DfscReleaseIpcConnection((longlong)puVar9);
  }
  return uVar3;
}



===== DfscReleaseIpcConnection @ 14001ce60 =====

void DfscReleaseIpcConnection(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x30) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    if (*(longlong *)(param_1 + 0x28) != 0) {
      ZwClose();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
    if (*(longlong *)(param_1 + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    if (*(longlong *)(param_1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0);
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== DfscRmGetNormalReferral @ 14001cf0c =====

int DfscRmGetNormalReferral
              (longlong param_1,wchar_t *param_2,wchar_t *param_3,longlong param_4,
              undefined8 *param_5,longlong param_6)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined *puVar4;
  uint local_res18 [4];
  undefined8 local_38 [2];
  
  param_6 = 0;
  local_38[0] = 0;
  local_res18[0] = 0;
  puVar4 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)) {
    puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_ZZ(puVar4,10,&WPP_af603b4b97893b05877342047baf7746_Traceguids,param_2,
              (wchar_t *)(param_4 + 8));
  }
  if ((((param_3 == (wchar_t *)0x0) || (*param_3 == L'\0')) ||
      (*(short **)(param_3 + 4) == (short *)0x0)) || (**(short **)(param_3 + 4) == 0)) {
    iVar2 = DfscRmGenerateReferral(puVar4,(ushort *)param_2,param_4,4,&param_6,local_res18);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_af603b4b97893b05877342047baf7746_Traceguids,iVar2);
    }
  }
  else {
    iVar2 = DfscRmGenerateReferralEx
                      ((ulonglong)puVar4,(ushort *)param_2,(ushort *)param_3,param_4,4,&param_6,
                       local_res18);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)) {
      WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_af603b4b97893b05877342047baf7746_Traceguids,iVar2,param_3);
    }
  }
  lVar1 = param_6;
  if (-1 < iVar2) {
    if (((ushort)*param_2 < (ushort)*(wchar_t *)param_6) || ((*(wchar_t *)param_6 & 1U) != 0)) {
      iVar2 = -0x3fffff3d;
    }
    else {
      uVar3 = DfscRmGenerateReferralFromResponse(param_1,(ushort *)param_6,local_res18[0],local_38);
      iVar2 = (int)uVar3;
      if (-1 < iVar2) {
        *param_5 = local_38[0];
      }
    }
  }
  if (lVar1 != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x15 & 1) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_af603b4b97893b05877342047baf7746_Traceguids,lVar1);
    }
    ExFreePoolWithTag(lVar1,0);
  }
  return iVar2;
}



===== DfscRmGenerateReferral @ 14001d0fc =====

int DfscRmGenerateReferral
              (undefined8 param_1,ushort *param_2,longlong param_3,undefined2 param_4,
              longlong *param_5,undefined4 *param_6)

{
  wchar_t *_Dst;
  ushort uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  void *pvVar5;
  char cVar6;
  int iVar7;
  undefined2 *puVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  uVar11 = *param_2 + 5;
  if (uVar11 < 0x1000) {
    uVar11 = 0x1000;
  }
  do {
    puVar8 = (undefined2 *)ExAllocatePool2(0x102,uVar11,0x6a436644);
    if (puVar8 == (undefined2 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_af603b4b97893b05877342047baf7746_Traceguids,uVar11);
      }
      iVar7 = -0x3fffff66;
LAB_14001d2fd:
      *param_5 = (longlong)puVar8;
      return iVar7;
    }
    *puVar8 = param_4;
    _Dst = puVar8 + 1;
    if (*param_2 != 0) {
      memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)*param_2);
    }
    _Dst[*param_2 >> 1] = L'\0';
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_af603b4b97893b05877342047baf7746_Traceguids,puVar8,_Dst);
    }
    uVar1 = *param_2;
    uVar3 = *(undefined8 *)(param_3 + 0x30);
    local_38 = 0;
    local_48 = 0;
    uStack_40 = 0;
    KeInitializeEvent(&local_48,1,0);
    lVar9 = IoGetRelatedDeviceObject(uVar3);
    lVar10 = IoAllocateIrp(*(char *)(lVar9 + 0x4c) + '\x01',0);
    if (lVar10 == 0) {
      iVar7 = -0x3fffff66;
LAB_14001d2c9:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_af603b4b97893b05877342047baf7746_Traceguids,puVar8);
      }
      ExFreePoolWithTag(puVar8,0);
      puVar8 = (undefined2 *)0x0;
      goto LAB_14001d2fd;
    }
    *(undefined8 *)(lVar10 + 0xc0) = uVar3;
    *(undefined1 *)(lVar10 + 0x40) = 0;
    pvVar5 = SystemReserved1[0xf];
    *(char *)(lVar10 + 0x43) = *(char *)(lVar10 + 0x43) + -1;
    *(void **)(lVar10 + 0x98) = pvVar5;
    lVar4 = *(longlong *)(lVar10 + 0xb8);
    *(longlong *)(lVar10 + 0xb8) = lVar4 + -0x48;
    *(longlong *)(lVar4 + -0x20) = lVar9;
    lVar4 = *(longlong *)(lVar10 + 0xb8);
    *(code **)(lVar4 + -0x10) = DfscCmCompletionRoutine;
    *(undefined8 **)(lVar4 + -8) = &local_48;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    lVar4 = *(longlong *)(lVar10 + 0xb8);
    *(undefined8 *)(lVar4 + -0x18) = uVar3;
    *(undefined2 *)(lVar4 + -0x48) = 0xd;
    *(longlong *)(lVar4 + -0x20) = lVar9;
    *(uint *)(lVar4 + -0x40) = uVar11;
    *(uint *)(lVar4 + -0x38) = uVar1 + 4;
    *(undefined4 *)(lVar4 + -0x30) = 0x60194;
    *(undefined8 *)(lVar10 + 8) = 0;
    *(undefined2 **)(lVar10 + 0x18) = puVar8;
    *(undefined2 **)(lVar10 + 0x70) = puVar8;
    *(undefined4 *)(lVar10 + 0x10) = 0x50;
    iVar7 = IofCallDriver(lVar9,lVar10);
    if (iVar7 == 0x103) {
      iVar7 = FsRtlCancellableWaitForSingleObject(&local_48,0,0);
      if (((iVar7 == -0x3ffffee0) || (iVar7 == -0x3fffffb5)) &&
         ((cVar6 = IoCancelIrp(lVar10), cVar6 == '\0' ||
          (iVar7 = KeReadStateEvent(&local_48), iVar7 == 0)))) {
        KeWaitForSingleObject(&local_48,0,0,0,0);
      }
      iVar7 = *(int *)(lVar10 + 0x30);
    }
    uVar2 = *(undefined4 *)(lVar10 + 0x38);
    IoFreeIrp(lVar10);
    if (iVar7 != -0x7ffffffb) {
      if (iVar7 < 0) goto LAB_14001d2c9;
      *param_6 = uVar2;
      goto LAB_14001d2fd;
    }
    if (0xdfff < uVar11) goto LAB_14001d2c9;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_af603b4b97893b05877342047baf7746_Traceguids,puVar8);
    }
    ExFreePoolWithTag(puVar8,0);
    uVar11 = uVar11 * 2;
    if (0xe000 < uVar11) {
      uVar11 = 0xe000;
    }
  } while( true );
}



===== DfscRmGenerateDomainReferralsFromResponse @ 14001d4d4 =====

uint DfscRmGenerateDomainReferralsFromResponse(longlong param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined2 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong lVar9;
  short *psVar10;
  short *_Src;
  uint uVar11;
  uint uVar12;
  ulonglong local_res20;
  
  uVar1 = DAT_14000d78c;
  local_res20 = local_res20 & 0xffffffff00000000;
  uVar4 = DfscRmCheckReferralSyntax(param_2,param_3,'\x01',(int *)&local_res20);
  if (-1 < (int)uVar4) {
    lVar9 = param_2 + 8;
    if (((*(byte *)(param_2 + 0xe) & 2) == 0) || (*(short *)(param_2 + 0x16) != 0)) {
      uVar4 = 0xc00000c3;
    }
    else {
      uVar12 = 0;
      if (*(short *)(param_2 + 2) != 0) {
        do {
          local_res20 = 0;
          psVar10 = (short *)((ulonglong)*(ushort *)(lVar9 + 0xc) + lVar9);
          uVar2 = ((short)param_2 - (short)psVar10) + (short)param_3;
          _Src = psVar10;
          uVar3 = uVar2;
          if (*psVar10 == 0x5c) {
            _Src = psVar10 + 1;
            uVar3 = uVar2 - 2;
            if (*_Src == 0x5c) {
              _Src = psVar10 + 2;
              uVar3 = uVar2 - 4;
            }
          }
          uVar4 = RtlStringCbLengthW(_Src,(ulonglong)uVar3,(longlong *)&local_res20);
          uVar7 = local_res20;
          if ((local_res20 == 0) || (uVar4 != 0)) {
            uVar7 = Feature_468612410__private_IsEnabledDeviceUsageNoInline();
            if (((int)uVar7 != 0) && (uVar4 == 0)) {
              uVar4 = 0xc00000c3;
            }
            break;
          }
          puVar5 = DfscRmAllocateReferral((int)local_res20 + 0xa2,0x7a436644);
          if (puVar5 == (undefined2 *)0x0) {
            uVar4 = 0xc000009a;
            break;
          }
          puVar5[0xe] = 0;
          *(undefined4 *)(puVar5 + 6) = 0;
          uVar11 = *(uint *)(lVar9 + 8);
          if (uVar11 == 0) {
            uVar11 = 0;
          }
          uVar8 = uVar1;
          if (uVar11 < uVar1) {
            uVar8 = uVar11;
          }
          *(uint *)(puVar5 + 0x14) = uVar8;
          *(undefined2 **)(puVar5 + 0x4c) = puVar5 + 0x50;
          memmove(puVar5 + 0x50,_Src,uVar7);
          *(undefined2 *)(*(longlong *)(puVar5 + 0x4c) + (uVar7 & 0xfffffffffffffffe)) = 0;
          puVar5[0x48] = (short)uVar7;
          puVar5[0x49] = (short)uVar7 + 2;
          *(undefined1 *)((longlong)puVar5 + 0x13) = 1;
          lVar6 = DfscDomainCacheStore(*(longlong *)(param_1 + 0xf0),(ulonglong)puVar5);
          DfscRmDereferenceReferral(lVar6);
          uVar12 = uVar12 + 1;
          lVar9 = lVar9 + (ulonglong)*(ushort *)(lVar9 + 2);
        } while (uVar12 < *(ushort *)(param_2 + 2));
      }
    }
  }
  return uVar4;
}



===== DfscRefCacheStore @ 14001d6b8 =====

void DfscRefCacheStore(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = param_3;
  lVar1 = DfscGetReferralCache(param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_3,(wchar_t *)(uVar2 + 0x90));
  }
  DfscCacheStore(param_2,param_3,lVar1);
  return;
}



===== DfscFileSystemControl @ 14001d740 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Switch with 1 destination removed at 0x00014001db89 : 21 cases all go to same
   destination */

uint DfscFileSystemControl(undefined8 param_1,uint *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  wint_t wVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined1 auStackY_118 [32];
  uint local_e8;
  int local_e4;
  int local_e0;
  uint local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  wint_t *pwStack_b0;
  undefined8 local_a8;
  wint_t *pwStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  ulonglong uStack_80;
  longlong local_78 [8];
  wint_t local_38 [4];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar2 = *(longlong *)(param_2 + 0x2e);
  lVar15 = 0;
  local_c8 = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  uVar5 = *(uint *)(lVar2 + 0x18);
  uVar13 = *(uint *)(lVar2 + 8);
  pwVar3 = *(wchar_t **)(param_2 + 6);
  uVar11 = *(uint *)(lVar2 + 0x10);
  local_e8 = uVar13;
  if (uVar5 == 0x601f0) {
    local_c0 = 0;
    local_b8 = 0;
    pwStack_b0 = (wint_t *)0x0;
    if (((((uVar11 < 6) || (pwVar3 == (wchar_t *)0x0)) || (pwVar3[1] != L':')) ||
        ((pwVar3[2] != L'\0' || (wVar4 = towupper(*pwVar3), wVar4 < 0x41)))) || (0x5a < wVar4)) {
LAB_14001db3c:
      uVar5 = 0xc000000d;
      goto LAB_14001dafd;
    }
    local_38[0] = towupper(*pwVar3);
    local_38[1] = 0x3a;
    local_38[2] = 0;
    RtlInitUnicodeStringEx(&local_b8,local_38);
    uVar5 = DfscGetContainerContextFromIrp((longlong)param_2,&local_c0);
    lVar2 = local_c0;
    if (-1 < (int)uVar5) {
      uVar8 = 0;
      iVar12 = 0;
      local_a8 = 0;
      pwStack_a0 = (wint_t *)0x0;
      local_98 = 0;
      uStack_90 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_d0 = uVar13;
      if ((pwStack_b0 == (wint_t *)0x0) || (wVar4 = *pwStack_b0, wVar4 == 0)) {
        uVar5 = 0xc000000d;
      }
      else {
        if (((wVar4 == 0x5c) || (pwStack_b0[1] == 0x5c)) || (pwStack_b0[1] != 0x3a)) {
          local_e0 = 0;
LAB_14001d8cb:
          local_a8 = 0;
          pwStack_a0 = (wint_t *)0x0;
          local_98 = 0;
          uStack_90 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_78[0] = 0;
          local_78[1] = 0;
          local_78[2] = 0;
          local_78[3] = 0;
          cVar1 = **(char **)(param_2 + 0x2e);
          if ((((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x13')) &&
             (lVar6 = *(longlong *)(*(char **)(param_2 + 0x2e) + 8), lVar6 != 0)) {
            plVar14 = (longlong *)(*(longlong *)(lVar6 + 8) + 0x20);
          }
          else {
            SeCaptureSubjectContext(local_78);
            plVar14 = local_78;
          }
          lVar6 = *plVar14;
          if (lVar6 == 0) {
            lVar6 = plVar14[2];
          }
          puVar10 = &local_98;
          uVar5 = SeQuerySessionIdToken(lVar6);
          if ((int)uVar5 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                       &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,uVar5);
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar10,uVar8,(undefined4)local_98);
          }
          if (plVar14 == local_78) {
            SeReleaseSubjectContext(local_78);
          }
          if (uVar5 == 0) {
            local_78[4] = 0;
            local_78[5] = 0;
            local_78[6] = 0;
            local_78[7] = 0;
            SeCaptureSubjectContext(local_78 + 4);
            lVar6 = local_78[4];
            if (local_78[4] == 0) {
              lVar6 = local_78[6];
            }
            uVar5 = SeQueryAuthenticationIdToken(lVar6,(longlong)&local_98 + 4);
            SeReleaseSubjectContext(local_78 + 4);
            if (uVar5 == 0) {
              if (local_e0 == 0) {
                uVar8 = DfscGetDevicelessNetUseTable(lVar2);
                uStack_80 = uStack_80 & 0xffffffff00000000;
              }
              else {
                if (lVar2 == 0) {
                  uVar8 = DAT_14000d748;
                }
                else {
                  uVar8 = *(undefined8 *)(lVar2 + 0x100);
                }
                uStack_80 = CONCAT44(uStack_80._4_4_,1);
              }
              local_a8 = local_b8;
              pwStack_a0 = pwStack_b0;
              KeEnterCriticalRegion();
              if (lVar2 == 0) {
                puVar9 = &DAT_14000d6e0;
              }
              else {
                puVar9 = (undefined *)(lVar2 + 0x98);
              }
              ExAcquireResourceExclusiveLite(puVar9,1);
              local_e4 = 1;
              lVar6 = RtlLookupElementGenericTableAvl(uVar8,&local_a8);
              uVar11 = uVar13;
              if (lVar6 != 0) {
                lVar15 = *(longlong *)(lVar6 + 0x20);
                LOCK();
                *(int *)(lVar15 + 4) = *(int *)(lVar15 + 4) + 1;
                UNLOCK();
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
                  WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                            &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,(wchar_t *)&local_a8,
                            (char)lVar15);
                }
                uVar11 = local_e8;
              }
              if (lVar15 == 0) {
                uVar5 = 0xc0000034;
                uVar13 = uVar11;
              }
              else {
                uVar13 = *(ushort *)(lVar15 + 0x58) + 4;
                if (uVar11 < uVar13) {
                  uVar5 = 0x80000005;
                }
                else {
                  *pwVar3 = L'\\';
                  memmove(pwVar3 + 1,*(void **)(lVar15 + 0x60),(ulonglong)*(ushort *)(lVar15 + 0x58)
                         );
                  *(undefined2 *)((longlong)pwVar3 + ((ulonglong)uVar13 - 2 & 0xfffffffffffffffe)) =
                       0;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
                    WPP_SF_ZZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,0,
                               (wchar_t *)(lVar15 + 0x58),(wchar_t *)&local_b8,(char)uVar13);
                  }
                }
              }
              iVar12 = local_e4;
              goto LAB_14001da61;
            }
          }
          iVar12 = 0;
        }
        else {
          wVar4 = towupper(wVar4);
          if ((0x40 < wVar4) && (wVar4 < 0x5b)) {
            local_e0 = 1;
            goto LAB_14001d8cb;
          }
          uVar5 = 0xc000000d;
        }
LAB_14001da61:
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                  &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,uVar5,(wchar_t *)&local_b8);
      }
      puVar9 = &DAT_14000d6e0;
      if (iVar12 != 0) {
        if (lVar2 != 0) {
          puVar9 = (undefined *)(lVar2 + 0x98);
        }
        ExReleaseResourceLite(puVar9);
        KeLeaveCriticalRegion();
      }
      if (lVar15 != 0) {
        DfscNetUseRelease(lVar2,lVar15,0,'\0');
      }
      if (uVar5 == 0x80000005) {
        if (local_d0 < 4) {
          uVar5 = 0xc0000023;
        }
        else {
          *(uint *)pwVar3 = uVar13;
          uVar5 = 0x80000005;
          param_2[0xe] = 4;
          param_2[0xf] = 0;
        }
        goto LAB_14001dafd;
      }
    }
    if (uVar5 != 0) goto LAB_14001dafd;
    goto LAB_14001daf9;
  }
  if (0x6811c < uVar5) {
    if (uVar5 < 0x6a011) {
      if (uVar5 == 0x6a010) {
        uVar5 = DfscFsctrlFlushClusterSetCache
                          ((longlong)param_2,pwVar3,(undefined *)(ulonglong)uVar11);
        goto LAB_14001dafd;
      }
      if (uVar5 < 0x69fc1) {
        if (uVar5 == 0x69fc0) {
          uVar5 = DfscFsctrlSetClientInfo((longlong)param_2,(ushort *)pwVar3,uVar11);
          goto LAB_14001dafd;
        }
        if (uVar5 == 0x68120) {
          uVar7 = DfscFsctrlSetDomainNameDns((longlong)param_2,pwVar3,uVar11,param_4);
          uVar5 = (uint)uVar7;
          goto LAB_14001dafd;
        }
        if (uVar5 == 0x68128) {
          uVar5 = DfscFsctrlSpecialSetDc((longlong)param_2,(ushort *)pwVar3,uVar11);
          goto LAB_14001dafd;
        }
        if (uVar5 == 0x68148) {
          uVar7 = DfscFsctrlSetClusterSetName
                            ((longlong)param_2,(uint *)pwVar3,(undefined *)(ulonglong)uVar11);
          uVar5 = (uint)uVar7;
          goto LAB_14001dafd;
        }
      }
      else {
        if (uVar5 == 0x69ff0) {
          uVar5 = DfscFsctrlFlushRefCache((longlong)param_2,pwVar3,(undefined *)(ulonglong)uVar11);
          goto LAB_14001dafd;
        }
        if (uVar5 == 0x69ff4) {
          uVar5 = DfscFsctrlStateTransition((longlong)param_2,(uint *)pwVar3,(ulonglong)uVar11);
          goto LAB_14001dafd;
        }
        if (uVar5 == 0x6a00c) {
          uVar5 = DfscFsctrlFlushDomainCache
                            ((longlong)param_2,pwVar3,(undefined *)(ulonglong)uVar11);
          goto LAB_14001dafd;
        }
      }
    }
    goto switchD_14001dbef_caseD_60125;
  }
  if (uVar5 == 0x6811c) {
    uVar7 = DfscFsctrlSetDomainNameFlat((longlong)param_2,pwVar3,uVar11,param_4);
    uVar5 = (uint)uVar7;
    goto LAB_14001dafd;
  }
  if (uVar5 < 0x60119) {
    if (uVar5 == 0x60118) {
switchD_14001dbef_caseD_60140:
      uVar7 = DfscFsctrlGetRefCache((longlong)param_2,pwVar3,uVar13,uVar5);
      uVar5 = (uint)uVar7;
      goto LAB_14001dafd;
    }
    if (uVar5 == 0x600c0) {
      uVar8 = DfscFsctrlGetServerName((longlong)param_2,pwVar3,uVar11,(uint *)pwVar3,uVar13);
      uVar5 = (uint)uVar8;
      goto LAB_14001dafd;
    }
switchD_14001dbef_caseD_60125:
    uVar5 = 0xc0000010;
    goto LAB_14001dafd;
  }
  if (0x61fbc < uVar5) {
    if (uVar5 == 0x680a4) {
      uVar5 = DfscGetContainerContextFromIrp((longlong)param_2,&local_c8);
      if (-1 < (int)uVar5) {
        uVar7 = DfscFsctrlSetDcName(param_2,pwVar3,uVar11,'\x01',local_c8);
        uVar5 = (uint)uVar7;
        local_c8 = 0;
      }
      goto LAB_14001dafd;
    }
    goto switchD_14001dbef_caseD_60125;
  }
  if (uVar5 == 0x61fbc) {
    uVar5 = DfscFsctrlGetClientInfo((longlong)param_2,pwVar3,uVar11,(ulonglong *)pwVar3,uVar13);
    goto LAB_14001dafd;
  }
  switch(uVar5) {
  case 0x60124:
  case 0x60144:
    uVar7 = DfscFsctrlGetDomainCache((longlong)param_2,pwVar3,uVar11,(uint *)pwVar3,uVar13,uVar5);
    uVar5 = (uint)uVar7;
    break;
  default:
    goto switchD_14001dbef_caseD_60125;
  case 0x60140:
    goto switchD_14001dbef_caseD_60140;
  case 0x60168:
    uVar8 = DfscFsctrlSqmGetReg((longlong)param_2,(undefined8 *)pwVar3,uVar13);
    uVar5 = (uint)uVar8;
    break;
  case 0x6016c:
    uVar8 = DfscFsctrlSqmGetData((longlong)param_2,(char *)pwVar3,uVar11,pwVar3,uVar13);
    uVar5 = (uint)uVar8;
    break;
  case 0x601a8:
    if (5 < uVar11) {
      uVar5 = DfscFsctrlIsDfsPath((longlong)param_2,(ushort *)(pwVar3 + 1),uVar11 - 2);
      break;
    }
    goto LAB_14001db3c;
  case 0x601e0:
    uVar7 = DfscFsctrlCreateDriveLetter((longlong)param_2,(char *)pwVar3,uVar11);
    uVar5 = (uint)uVar7;
    break;
  case 0x601e4:
    uVar5 = DfscFsctrlRemoveDriveLetter(param_2,(int *)pwVar3,uVar11,(uint *)pwVar3,&local_e8);
    break;
  case 0x601e8:
    uVar5 = DfscFsctrlGetNetUses
                      ((longlong)param_2,(uint *)pwVar3,(ulonglong)uVar11,(uint *)pwVar3,&local_e8);
    goto LAB_14001dd57;
  case 0x601ec:
    uVar5 = DfscFsctrlIsValidDriveLetterConnection
                      ((longlong)param_2,(wint_t *)pwVar3,(ulonglong)uVar11);
    break;
  case 0x601f4:
    uVar7 = DfscFsctrlGetUseInfo
                      ((longlong)param_2,(wint_t *)pwVar3,uVar11,(ushort *)pwVar3,&local_e8);
    uVar5 = (uint)uVar7;
LAB_14001dd57:
    if (uVar5 == 0) {
      uVar13 = local_e8;
LAB_14001daf9:
      *(ulonglong *)(param_2 + 0xe) = (ulonglong)uVar13;
    }
  }
LAB_14001dafd:
  param_2[0xc] = uVar5;
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== DfscFsctrlStateTransition @ 14001e098 =====

int DfscFsctrlStateTransition(longlong param_1,uint *param_2,undefined *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  if ((param_2 == (uint *)0x0) || ((uint)param_3 < 4)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = DfscGetContainerContextFromIrp(param_1,local_res10);
    if (-1 < iVar2) {
      lVar3 = DfscGetReferralCache(local_res10[0]);
      uVar1 = *param_2;
      if (uVar1 - 3 < 2) {
        DfscCacheExpire(lVar3);
      }
      else if ((uVar1 < 3) || (uVar1 == 5)) {
        DfscCachePurge(lVar3,(ulonglong)uVar1,param_3);
      }
      else {
        iVar2 = -0x3ffffff3;
      }
    }
  }
  return iVar2;
}



===== DfscGetReferralCache @ 14001e118 =====

undefined8 DfscGetReferralCache(longlong param_1)

{
  if (param_1 == 0) {
    return DAT_14000d6d0;
  }
  return *(undefined8 *)(param_1 + 0x88);
}



===== DfscCacheExpire @ 14001e138 =====

void DfscCacheExpire(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  
  cVar3 = '\0';
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0x38,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_1);
  }
  uVar2 = 1;
  while( true ) {
    lVar1 = RtlNextUnicodePrefix(param_1,uVar2);
    if (lVar1 == 0) break;
    *(undefined8 *)(lVar1 + -0x28) = 0;
    cVar3 = cVar3 + '\x01';
    uVar2 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_1,cVar3);
  }
  ExReleaseResourceLite(param_1 + 0x38);
  KeLeaveCriticalRegion();
  return;
}



===== DfscFsctrlGetServerName @ 14001e234 =====

undefined8
DfscFsctrlGetServerName(longlong param_1,short *param_2,uint param_3,uint *param_4,uint param_5)

{
  uint uVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 uVar7;
  ushort uVar8;
  longlong local_68;
  longlong local_60;
  undefined8 local_58;
  short *psStack_50;
  short local_48 [4];
  short *psStack_40;
  short local_38 [4];
  short *psStack_30;
  ulonglong local_28;
  short *psStack_20;
  
  uVar7 = 0;
  local_68 = 0;
  local_60 = 0;
  local_28 = 0;
  psStack_20 = (short *)0x0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  psStack_40 = (short *)0x0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  psStack_30 = (short *)0x0;
  if (((((param_3 != 0) && (bVar2 = true, (param_3 & 1) == 0)) && (param_3 < 0xffff)) &&
      ((param_2 != (short *)0x0 && (param_4 != (uint *)0x0)))) &&
     (uVar8 = (ushort)param_3, *param_2 == 0x5c)) {
    local_58 = (ulonglong)CONCAT22(uVar8,uVar8);
    uVar3 = uVar8;
    psStack_50 = param_2;
    if (3 < uVar8) {
      local_58 = (ulonglong)CONCAT22(uVar8,uVar8);
      psStack_50 = param_2;
      if (param_2[1] == 0x5c) {
        uVar3 = uVar8 - 2;
        local_58 = (ulonglong)CONCAT22(uVar8 - 2,uVar3);
        psStack_50 = param_2 + 1;
      }
    }
    if ((((uVar3 < 4) || (psStack_50[1] != 0x5c)) &&
        ((uVar5 = DfscGetPathComponents
                            ((ushort *)&local_58,local_48,local_38,(short *)0x0,(short *)0x0),
         -1 < (int)uVar5 &&
         (((local_48[0] != 0 && (psStack_40 != (short *)0x0)) && (local_38[0] != 0)))))) &&
       (((*psStack_40 != 0 && (psStack_30 != (short *)0x0)) && (*psStack_30 != 0)))) {
      uVar5 = DfscGetContainerContextFromIrp(param_1,&local_60);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      iVar4 = DfscGetReferralFromPath
                        (param_1,(undefined2 *)0x0,(ushort *)&local_58,3,local_60,&local_68,0,
                         (short *)&local_28);
      if (iVar4 < 0) {
        return 0xc0000034;
      }
      uVar5 = DfscReferralIterate(local_68);
      if ((int)uVar5 < 0) {
        uVar7 = 0xc0000034;
      }
      else {
        local_58 = DfscReferralGetCurrentTarget(local_68);
        uVar6 = (uint)*(ushort *)(local_58 + 0x60);
        if (((ushort)local_28 == 0) || (*psStack_20 == 0x5c)) {
          bVar2 = false;
        }
        else {
          uVar6 = *(ushort *)(local_58 + 0x60) + 2;
        }
        uVar6 = uVar6 + 2;
        uVar1 = uVar6 + (ushort)local_28 + 2;
        if (uVar6 <= uVar1) {
          if (param_5 < uVar1) {
            if (param_5 < 4) {
              uVar7 = 0xc0000023;
            }
            else {
              *param_4 = uVar1;
              uVar7 = 0x80000005;
              *(undefined8 *)(param_1 + 0x38) = 4;
            }
          }
          else {
            memmove((void *)((ulonglong)uVar6 + (longlong)param_4),psStack_20,local_28 & 0xffff);
            if (bVar2) {
              *(undefined2 *)((longlong)((ulonglong)uVar6 + (longlong)param_4) + -2) = 0x5c;
            }
            *(undefined2 *)(((ulonglong)uVar1 - 2) + (longlong)param_4) = 0;
            *(undefined2 *)param_4 = 0x5c;
            memmove((void *)((longlong)param_4 + 2),*(void **)(local_58 + 0x68),
                    (ulonglong)*(ushort *)(local_58 + 0x60));
            *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar1;
          }
          DfscReferralRelease(local_68);
          return uVar7;
        }
        uVar7 = 0xc000000d;
      }
      DfscReferralRelease(local_68);
      return uVar7;
    }
  }
  return 0xc000000d;
}



===== DfscFsctrlRemoveDriveLetter @ 14001e4d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscFsctrlRemoveDriveLetter(uint *param_1,int *param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  wint_t *pwVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStackY_98 [32];
  longlong local_58;
  wchar_t local_50 [12];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = 0;
  local_50[0] = L'\0';
  local_50[1] = L'\0';
  local_50[2] = L'\0';
  local_50[3] = L'\0';
  local_50[4] = L'\0';
  local_50[5] = L'\0';
  local_50[6] = L'\0';
  local_50[7] = L'\0';
  if ((((((param_3 & 1) == 0) && (param_3 - 8 < 0xfff7)) && (param_2 != (int *)0x0)) &&
      ((7 < *param_5 && (param_4 != (uint *)0x0)))) &&
     ((*(short *)((longlong)param_2 + (ulonglong)((param_3 - 4 >> 1) - 1) * 2 + 4) == 0 &&
      (uVar1 = *param_5 - 4, (uVar1 & 1) == 0)))) {
    if (uVar1 < 4) {
      iVar3 = -0x3fffffdd;
    }
    else {
      pwVar2 = (wint_t *)(param_2 + 1);
      if ((*pwVar2 == 0x5c) || (*(short *)((longlong)param_2 + 6) != 0x3a)) {
        iVar3 = RtlInitUnicodeStringEx(local_50,pwVar2);
      }
      else {
        uVar4 = DfscGetNormalizedDriveLetterUnicodeString
                          (pwVar2,param_3,(wint_t *)(local_50 + 8),local_50);
        iVar3 = (int)uVar4;
      }
      if (iVar3 == 0) {
        iVar3 = DfscGetContainerContextFromIrp((longlong)param_1,&local_58);
        if (-1 < iVar3) {
          iVar3 = DfscDeleteNetUseConnection
                            (local_58,local_50,param_1,*param_2,param_4,param_5,'\0');
          if (iVar3 == 0) {
            *(ulonglong *)(param_1 + 0xe) = (ulonglong)*param_5;
            if ((DfscGlobalData & 4) == 0) {
              DfscReadLinkedConnectionPolicy();
            }
            if ((DfscGlobalData & 2) != 0) {
              DfscDeleteLinkedConnection(local_58,(longlong)local_50,(longlong)param_1,*param_2);
            }
          }
          else if (iVar3 == -0x7ffffffb) {
            *param_4 = *param_5;
            param_1[0xe] = 4;
            param_1[0xf] = 0;
          }
        }
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
  return iVar3;
}



===== DfscFsctrlGetNetUses @ 14001e680 =====

int DfscFsctrlGetNetUses
              (longlong param_1,uint *param_2,undefined8 param_3,uint *param_4,uint *param_5)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  longlong *plVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  bool bVar11;
  bool bVar12;
  longlong local_res10;
  uint local_res18;
  
  local_res10 = 0;
  if ((((uint)param_3 < 0x10) || (param_2 == (uint *)0x0)) || (param_4 == (uint *)0x0)) {
    iVar4 = -0x3ffffff3;
  }
  else if (*param_5 < 4) {
    iVar4 = -0x3fffffdd;
  }
  else {
    plVar7 = &local_res10;
    iVar4 = DfscGetContainerContextFromIrp(param_1,plVar7);
    if (-1 < iVar4) {
      if (local_res10 == 0) {
        uVar9 = DAT_14000d750;
        uVar1 = DAT_14000d748;
      }
      else {
        uVar1 = *(undefined8 *)(local_res10 + 0x100);
        uVar9 = *(undefined8 *)(local_res10 + 0x108);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar2 = RtlNumberGenericTableElementsAvl(uVar9);
        uVar3 = RtlNumberGenericTableElementsAvl(uVar1);
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),plVar7,param_3,*param_2,uVar3,uVar2);
      }
      uVar6 = *param_2;
      uVar5 = RtlNumberGenericTableElementsAvl(uVar1);
      uVar10 = uVar9;
      if (uVar6 < uVar5) {
        uVar10 = uVar1;
      }
      uVar8 = uVar6 - uVar5;
      if (uVar6 < uVar5) {
        uVar8 = uVar6;
      }
      bVar11 = uVar5 <= uVar6;
      uVar6 = 0;
      if (bVar11) {
        uVar6 = uVar5;
      }
      local_res18 = (uint)bVar11;
      while( true ) {
        uVar5 = RtlNumberGenericTableElementsAvl(uVar10);
        if (uVar8 < uVar5) {
          iVar4 = DfscNetUseEnum(local_res10,param_1,uVar10,uVar8,uVar6,(int *)param_4,param_5);
          if (iVar4 != -0x7fffffe6) {
            if (iVar4 == -0x7ffffffb) {
              iVar4 = -0x7ffffffb;
              *param_4 = *param_5;
              *(undefined8 *)(param_1 + 0x38) = 4;
            }
            return iVar4;
          }
        }
        else {
          iVar4 = -0x7fffffe6;
        }
        if (bVar11) break;
        uVar6 = RtlNumberGenericTableElementsAvl(uVar10);
        bVar12 = uVar8 < uVar6;
        bVar11 = true;
        uVar10 = uVar9;
        uVar8 = uVar8 - uVar6;
        if (bVar12) {
          uVar8 = 0;
        }
      }
      return iVar4;
    }
  }
  return iVar4;
}



===== DfscDomainCacheStore @ 14001e89c =====

void DfscDomainCacheStore(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = param_2;
  lVar1 = DfscGetDomainCache(param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_2,(wchar_t *)(uVar2 + 0x90));
  }
  DfscCacheStore(0,param_2,lVar1);
  return;
}



===== DfscGetDomainCache @ 14001e910 =====

undefined8 DfscGetDomainCache(longlong param_1)

{
  if (param_1 == 0) {
    return DAT_14000d6c8;
  }
  return *(undefined8 *)(param_1 + 0x80);
}



===== DfscCacheStore @ 14001e930 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DfscCacheStore(ulonglong param_1,ulonglong param_2,longlong param_3)

{
  longlong lVar1;
  ushort uVar2;
  longlong lVar3;
  code *pcVar4;
  char cVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  longlong lVar15;
  uint uVar16;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  uVar16 = 0;
  uVar11 = param_2;
  lVar15 = param_3;
  KeEnterCriticalRegion();
  uVar12 = CONCAT71((int7)(uVar11 >> 8),1);
  ExAcquireResourceExclusiveLite(param_3 + 0x38);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qqZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,lVar15,param_1,(char)param_2,
               (wchar_t *)(param_2 + 0x90));
  }
  uVar7 = param_2 + 0x90;
  uVar6 = RtlFindUnicodePrefix(param_3,uVar7,0);
  uVar11 = 0;
  if (uVar6 != 0) {
    uVar11 = uVar6 - 0x48;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,uVar11,(wchar_t *)(uVar6 + 0x48));
    }
    uVar2 = *(ushort *)(param_2 + 0x90);
    uVar7 = (ulonglong)uVar2;
    if (*(ushort *)(uVar6 + 0x48) < uVar2) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar7 = 0;
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,(uint)*(ushort *)(uVar6 + 0x48),
                  (char)uVar2);
      }
      uVar11 = 0;
    }
    else {
      if (*(char *)(param_2 + 0x13) != '\0') {
        *(undefined1 *)(uVar6 - 0x35) = 1;
      }
      if ((*(int *)(param_2 + 0xc) == 0) && (*(short *)(param_2 + 0x1c) == 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          uVar7 = 0;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids);
        }
        DfscRmDereferenceReferral(param_2);
        param_2 = uVar11;
        uVar11 = 0;
      }
      else if ((*(uint *)(param_3 + 0x28) & 1) == 0) {
LAB_14001eb30:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                   &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,uVar11);
        }
        uVar7 = uVar6;
        RtlRemoveUnicodePrefix(param_3,uVar6);
        *(ushort *)(uVar6 - 0x38) = *(ushort *)(uVar6 - 0x38) & 0xfffe;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          uVar7 = 0;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids);
        }
        if (param_1 == uVar11) {
          uVar7 = uVar11;
          cVar5 = DfscRmEquivalentReferral(param_2,uVar11);
          if (cVar5 == '\0') {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                      &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids);
            }
            goto LAB_14001eb30;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            uVar7 = 0;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                    &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids);
          }
          if ((*(char *)(uVar6 - 0x34) == '\0') || (*(char *)(param_2 + 0x14) != '\0')) {
            *(undefined4 *)(uVar6 - 0x20) = *(undefined4 *)(param_2 + 0x28);
            *(undefined8 *)(uVar6 - 0x28) = _DAT_fffff78000000320;
          }
          cVar5 = *(char *)(param_2 + 0x14);
          if (cVar5 != '\0') {
            *(char *)(uVar6 - 0x34) = cVar5;
            DfscRmDereferenceReferral(param_2);
            param_2 = uVar11;
            uVar11 = 0;
            goto LAB_14001eb83;
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          uVar7 = 0;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids);
        }
        DfscRmDereferenceReferral(param_2);
        param_2 = uVar11;
        uVar11 = 0;
      }
    }
  }
LAB_14001eb83:
  puVar14 = auStackY_58;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    uVar7 = 0;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_2);
  }
  LOCK();
  *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
  UNLOCK();
  if ((*(byte *)(param_2 + 0x10) & 1) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_2);
    }
    *(ushort *)(param_2 + 0x10) = *(ushort *)(param_2 + 0x10) | 1;
    *(undefined8 *)(param_2 + 0x20) = _DAT_fffff78000000320;
    cVar5 = RtlInsertUnicodePrefix(param_3,param_2 + 0x90,param_2 + 0x48);
    if (cVar5 == '\0') {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x10b,1,param_3,param_2);
    }
    *(longlong *)(param_2 + 0x40) = param_3;
    *(int *)(param_3 + 0x2c) = *(int *)(param_3 + 0x2c) + 1;
    uVar7 = Feature_3910819131__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar7 == 0) {
      uVar7 = (ulonglong)((uint)*(ushort *)(param_2 + 2) + *(int *)(param_3 + 0x30));
    }
    else {
      uVar10 = *(int *)(param_2 + 8) + *(uint *)(param_3 + 0x30);
      uVar7 = (ulonglong)uVar10;
      if (uVar10 < *(uint *)(param_3 + 0x30)) {
        uVar7 = 0xffffffff;
      }
    }
    *(uint *)(param_3 + 0x30) = (uint)uVar7;
    if ((*(uint *)(param_3 + 0x34) != 0) && (*(uint *)(param_3 + 0x34) < (uint)uVar7)) {
      KeEnterCriticalRegion();
      uVar7 = CONCAT71((int7)(uVar7 >> 8),1);
      ExAcquireResourceExclusiveLite(param_3 + 0xa0,uVar7);
      uVar10 = *(uint *)(param_3 + 0x34);
      lVar15 = *(longlong *)(param_3 + 0x20);
      while ((((uVar10 != 0 && (uVar10 < *(uint *)(param_3 + 0x30))) && (uVar16 < DAT_14000d7a8)) &&
             (lVar15 != *(longlong *)(param_3 + 0x18)))) {
        lVar1 = lVar15 + -0x30;
        lVar3 = *(longlong *)(lVar15 + 8);
        if ((((*(byte *)(lVar15 + -0x20) & 1) != 0) && (*(int *)(lVar15 + -0x2c) < 2)) &&
           (*(char *)(lVar15 + -0x1c) != '\x01')) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            uVar7 = 0;
            WPP_SF_qZ(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x1f,
                      &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,lVar1,
                      (wchar_t *)(lVar15 + 0x60));
          }
          uVar16 = uVar16 + 1;
          DfscRmUnlinkReferral(lVar1);
          DfscRmDereferenceReferral(lVar1);
        }
        uVar10 = *(uint *)(param_3 + 0x34);
        lVar15 = lVar3;
      }
      ExReleaseResourceLite(param_3 + 0xa0);
      KeLeaveCriticalRegion();
    }
  }
  KeEnterCriticalRegion();
  plVar13 = (longlong *)CONCAT71((int7)(uVar7 >> 8),1);
  ExAcquireResourceExclusiveLite(param_3 + 0xa0);
  if (uVar11 != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      plVar13 = (longlong *)0x17;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,uVar11);
    }
    DfscRmUnlinkReferral(uVar11);
    DfscRmDereferenceReferral(uVar11);
  }
  lVar15 = *(longlong *)(param_2 + 0x30);
  puVar8 = (undefined8 *)(param_2 + 0x30);
  if (lVar15 == 0) {
LAB_14001ee9e:
    plVar13 = *(longlong **)(param_3 + 0x18);
    puVar9 = (undefined8 *)(param_3 + 0x18);
    if ((undefined8 *)plVar13[1] == puVar9) goto LAB_14001eeb3;
  }
  else if ((*(undefined8 **)(lVar15 + 8) == puVar8) &&
          (plVar13 = *(longlong **)(param_2 + 0x38), (undefined8 *)*plVar13 == puVar8)) {
    *plVar13 = lVar15;
    *(longlong **)(lVar15 + 8) = plVar13;
    goto LAB_14001ee9e;
  }
  puVar9 = (undefined8 *)0x3;
  pcVar4 = (code *)swi(0x29);
  puVar8 = (undefined8 *)(*pcVar4)();
  puVar14 = auStackY_50;
LAB_14001eeb3:
  puVar8[1] = puVar9;
  *puVar8 = plVar13;
  plVar13[1] = (longlong)puVar8;
  *puVar9 = puVar8;
  *(undefined8 *)(puVar14 + -8) = 0x14001eecf;
  ExReleaseResourceLite(param_3 + 0xa0);
  *(undefined8 *)(puVar14 + -8) = 0x14001eedb;
  KeLeaveCriticalRegion();
  *(undefined8 *)(puVar14 + -8) = 0x14001eeeb;
  ExReleaseResourceLite(param_3 + 0x38);
  *(undefined8 *)(puVar14 + -8) = 0x14001eef7;
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar14 + -8) = 0x14001ef29;
    WPP_SF_q(uVar12,0x18,&WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,param_2);
  }
  return param_2;
}



===== DfscRmValidateDomainIterate @ 14001ef50 =====

undefined8 DfscRmValidateDomainIterate(longlong *param_1)

{
  longlong *plVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  short local_res8;
  ushort local_48 [8];
  
  lVar10 = param_1[3];
  local_res8 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  if (lVar10 != 0) {
    lVar3 = *(longlong *)(lVar10 + 0x10);
    local_res8 = *(short *)(lVar10 + 0x26);
    if (((((*(char *)(lVar3 + 0x12) != '\0') || (*(char *)(lVar3 + 0x13) == '\0')) ||
         ((*(uint *)(lVar10 + 8) & 8) == 0)) || ((*(byte *)(lVar3 + 0x10) & 8) == 0)) &&
       (iVar6 = DfscGetDsDCReferral(*param_1,param_1 + 3,(byte)(*(uint *)(lVar10 + 8) >> 3) & 1,
                                    param_1 + 2), -1 < iVar6)) {
      *(int *)((longlong)param_1 + 0x24) = iVar6;
      *(short *)(param_1[2] + 0x26) = local_res8 + 1;
      return 0xffffffff;
    }
  }
  lVar10 = DfscGetCurrentDcContext(*(longlong *)(*param_1 + 0xf0));
  if (lVar10 == 0) {
    uVar7 = 0xc0000233;
    goto LAB_14001f16f;
  }
  pwVar4 = *(wchar_t **)(lVar10 + 8);
  RtlInitUnicodeString(local_48,pwVar4);
  plVar1 = param_1 + 2;
  pwVar2 = (wchar_t *)(lVar10 + 0x10);
  uVar7 = DfscGetDomainDCReferral((longlong *)*param_1,local_48,pwVar2,plVar1);
  uVar11 = DfscIsErrorInList(uVar7,0x14000d110,0x1e);
  uVar8 = uVar7;
  if (((char)uVar11 == '\0') ||
     (pwVar5 = *(wchar_t **)(lVar10 + 0x30),
     *(wchar_t **)(lVar10 + 0x30) == *(wchar_t **)(lVar10 + 0x38))) {
LAB_14001f124:
    if ((int)uVar7 < 0) {
LAB_14001f128:
      uVar11 = DfscIsErrorInList(uVar7,0x14000d110,0x1e);
      if (((char)uVar11 != '\0') &&
         (uVar9 = DfscRefreshBootstrapDCAndGetDCReferral
                            ((longlong *)*param_1,(longlong)local_48,pwVar2,plVar1), uVar7 = uVar8,
         -1 < (int)uVar9)) {
        uVar7 = uVar9;
      }
    }
  }
  else {
    do {
      pwVar12 = pwVar5;
      pwVar13 = pwVar12;
      if (pwVar12 != pwVar4) {
        if (*plVar1 != 0) {
          DfscReferralRelease(*plVar1);
          *plVar1 = 0;
        }
        RtlInitUnicodeString(local_48,pwVar12);
        uVar8 = DfscGetDomainDCReferral((longlong *)*param_1,local_48,pwVar2,plVar1);
        uVar7 = uVar8;
      }
      for (; *pwVar13 != L'\0'; pwVar13 = pwVar13 + 1) {
      }
      uVar11 = DfscIsErrorInList(uVar7,0x14000d110,0x1e);
    } while (((char)uVar11 != '\0') &&
            (pwVar5 = pwVar13 + 1, pwVar13 + 1 <= *(wchar_t **)(lVar10 + 0x38)));
    if (pwVar12 == *(wchar_t **)(lVar10 + 8)) goto LAB_14001f124;
    if ((int)uVar7 < 0) goto LAB_14001f128;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,pwVar12);
    }
    *(wchar_t **)(lVar10 + 8) = pwVar12;
  }
  DfscReleaseDcContext(lVar10);
  if (-1 < (int)uVar7) {
    *(short *)(*plVar1 + 0x26) = local_res8 + 1;
  }
LAB_14001f16f:
  *(uint *)((longlong)param_1 + 0x24) = uVar7;
  return 0xffffffff;
}



===== DfscFsctrlSetDomainNameDns @ 14001f198 =====

ulonglong DfscFsctrlSetDomainNameDns
                    (longlong param_1,short *param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  short *psVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong local_res10;
  ushort local_28 [8];
  
  local_res10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  if (((param_3 & 1) == 0) && (param_3 - 1 < 0xfffe)) {
    uVar8 = param_3 >> 1;
    uVar1 = 0;
    if (uVar8 != 0) {
      psVar6 = param_2;
      do {
        if (*psVar6 == 0) break;
        uVar1 = uVar1 + 1;
        psVar6 = psVar6 + 1;
      } while (uVar1 < uVar8);
    }
    if (uVar1 < uVar8) {
      psVar6 = param_2;
      if ((*param_2 == 0x5c) && (psVar6 = param_2 + 1, *psVar6 == 0x5c)) {
        psVar6 = param_2 + 2;
      }
      uVar1 = RtlInitUnicodeStringEx(local_28,psVar6);
      if (uVar1 != 0) {
        return (ulonglong)uVar1;
      }
      puVar3 = DfscCreateDcContext();
      if (puVar3 == (undefined4 *)0x0) {
        return 0xc000009a;
      }
      uVar4 = DfscCreateNameFromUnicodeString((ulonglong *)(puVar3 + 4),local_28,0x6e436644,param_4)
      ;
      uVar7 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        uVar1 = DfscGetContainerContextFromIrp(param_1,&local_res10);
        uVar7 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          lVar5 = DfscGetCurrentDcContext(local_res10);
          if (lVar5 != 0) {
            iVar2 = RtlCompareUnicodeString(lVar5 + 0x10,puVar3 + 4,0);
            if (iVar2 == 0) {
              DfscReleaseDcContext(lVar5);
              goto LAB_14001f2e7;
            }
            uVar4 = DfscCreateNameFromUnicodeString
                              ((ulonglong *)(puVar3 + 8),(ushort *)(lVar5 + 0x20),0x6e436644,param_4
                              );
            if (-1 < (int)uVar4) {
              uVar4 = DfscCopyDcList((longlong)puVar3,lVar5);
            }
            uVar7 = uVar4 & 0xffffffff;
            DfscReleaseDcContext(lVar5);
            if ((int)uVar4 < 0) goto LAB_14001f2e7;
          }
          DfscSetCurrentDcContext((longlong)puVar3,local_res10);
        }
      }
LAB_14001f2e7:
      DfscReleaseDcContext((longlong)puVar3);
      return uVar7;
    }
  }
  return 0xc000000d;
}



===== DfscFsctrlSetDcName @ 14001f314 =====

ulonglong DfscFsctrlSetDcName(undefined8 param_1,void *param_2,uint param_3,char param_4,
                             longlong param_5)

{
  uint uVar1;
  wchar_t *_Dst;
  longlong lVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  int iVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  
  uVar7 = 0;
  pwVar10 = (wchar_t *)0x0;
  if (((param_3 & 1) != 0) || (0xfffa < param_3 - 4)) {
    return 0xc000000d;
  }
  _Dst = (wchar_t *)ExAllocatePool2(0x102,(ulonglong)param_3,0x6c436644);
  if (_Dst == (wchar_t *)0x0) {
    return 0xc000009a;
  }
  memmove(_Dst,param_2,(ulonglong)param_3);
  pwVar9 = (wchar_t *)((ulonglong)(param_3 >> 1) - 1);
  if (_Dst[(longlong)pwVar9] != L'\0') {
LAB_14001f3a2:
    uVar7 = 0xc000000d;
LAB_14001f3a7:
    ExFreePoolWithTag(_Dst,0);
    return uVar7;
  }
  iVar8 = 0;
  lVar2 = 0;
  while (lVar2 <= (longlong)pwVar9) {
    lVar5 = lVar2;
    iVar6 = iVar8;
    do {
      if (_Dst[lVar5] == L'\0') break;
      iVar6 = iVar6 + 1;
      lVar5 = lVar5 + 1;
    } while (lVar5 <= (longlong)pwVar9);
    if ((lVar5 == lVar2) || (0xfffc < (uint)(iVar6 - iVar8))) goto LAB_14001f3a2;
    lVar2 = (longlong)iVar8;
    iVar8 = iVar6 + 1;
    pwVar10 = _Dst + lVar2;
    lVar2 = lVar5 + 1;
  }
  puVar3 = DfscCreateDcContext();
  if (puVar3 == (undefined4 *)0x0) {
    uVar7 = 0xc000009a;
    goto LAB_14001f3a7;
  }
  *(wchar_t **)(puVar3 + 0xc) = _Dst;
  *(short *)(puVar3 + 0x10) = (short)param_3;
  *(wchar_t **)(puVar3 + 2) = _Dst;
  *(wchar_t **)(puVar3 + 0xe) = pwVar10;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,_Dst);
    pwVar9 = _Dst;
  }
  lVar2 = DfscGetCurrentDcContext(param_5);
  if (lVar2 != 0) {
    uVar4 = DfscCreateNameFromUnicodeString
                      ((ulonglong *)(puVar3 + 4),(ushort *)(lVar2 + 0x10),0x6e436644,pwVar9);
    if (-1 < (int)uVar4) {
      uVar4 = DfscCreateNameFromUnicodeString
                        ((ulonglong *)(puVar3 + 8),(ushort *)(lVar2 + 0x20),0x6e436644,pwVar9);
    }
    uVar7 = uVar4 & 0xffffffff;
    DfscReleaseDcContext(lVar2);
    if ((int)uVar4 < 0) goto LAB_14001f4ca;
  }
  DfscSetCurrentDcContext((longlong)puVar3,param_5);
  if (param_4 != '\0') {
    uVar1 = DfscPopulateDomainNameCache(param_1,param_5);
    uVar7 = (ulonglong)uVar1;
  }
LAB_14001f4ca:
  DfscReleaseDcContext((longlong)puVar3);
  return uVar7;
}



===== DfscReleaseDcContext @ 14001f4f8 =====

void DfscReleaseDcContext(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(longlong *)(param_1 + 0x30) != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,*(longlong *)(param_1 + 0x30));
        }
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
        *(undefined8 *)(param_1 + 0x30) = 0;
        *(undefined8 *)(param_1 + 0x38) = 0;
        *(undefined8 *)(param_1 + 8) = 0;
      }
      if (*(longlong *)(param_1 + 0x18) != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                   &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,*(longlong *)(param_1 + 0x18));
        }
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x18),0);
        *(undefined8 *)(param_1 + 0x18) = 0;
      }
      if (*(longlong *)(param_1 + 0x28) != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                   &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,*(longlong *)(param_1 + 0x28));
        }
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x28),0);
        *(undefined8 *)(param_1 + 0x28) = 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,param_1);
      }
      ExFreePoolWithTag(param_1,0);
    }
  }
  return;
}



===== DfscGetCurrentDcContext @ 14001f660 =====

longlong DfscGetCurrentDcContext(longlong param_1)

{
  undefined *puVar1;
  longlong lVar2;
  
  if (param_1 == 0) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000d658,1);
    lVar2 = DAT_14000d6c0;
    if (DAT_14000d6c0 != 0) {
      DfscReferenceDcContext(DAT_14000d6c0);
    }
    puVar1 = &DAT_14000d658;
  }
  else {
    KeEnterCriticalRegion();
    puVar1 = (undefined *)(param_1 + 0x10);
    ExAcquireResourceExclusiveLite(puVar1,1);
    lVar2 = *(longlong *)(param_1 + 0x78);
    if (lVar2 != 0) {
      DfscReferenceDcContext(lVar2);
    }
  }
  ExReleaseResourceLite(puVar1);
  KeLeaveCriticalRegion();
  return lVar2;
}



===== DfscCredCreateExplicitCredentials @ 14001f714 =====

ulonglong DfscCredCreateExplicitCredentials
                    (ushort *param_1,short param_2,ushort *param_3,ushort *param_4,
                    undefined4 param_5,void *param_6,uint param_7,int param_8,uint param_9,
                    undefined8 *param_10)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  void *_Dst;
  void *_Dst_00;
  undefined2 *_Dst_01;
  undefined2 uVar7;
  ushort *puVar8;
  wchar_t *pwVar9;
  ulonglong uVar10;
  ushort *puVar11;
  uint local_58;
  longlong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  longlong lStack_30;
  
  local_58 = 0;
  local_50 = 0;
  bVar1 = false;
  *param_10 = 0;
  local_48 = 0;
  uStack_40 = 0;
  _Dst = (void *)0x0;
  _Dst_00 = (void *)0x0;
  local_38 = 0;
  lStack_30 = 0;
  puVar11 = param_4;
  RtlInitUnicodeStringEx(&local_48,0);
  RtlInitUnicodeStringEx(&local_38,0);
  uVar6 = DfscCreateNameFromUnicodeString(&local_48,param_4,0x78436644,puVar11);
  uVar2 = param_9;
  uVar10 = uVar6 & 0xffffffff;
  if ((int)uVar6 == 0) {
    if (param_8 == 1) {
      puVar8 = (ushort *)&ExplicitNullCredentials;
      if (*param_1 != 0) {
        puVar8 = param_1;
      }
      uVar6 = DfscCreateNameFromUnicodeString(&local_38,puVar8,0x78436644,puVar11);
      uVar10 = uVar6 & 0xffffffff;
      local_58 = uVar2 >> 2 & 1;
      if ((int)uVar6 != 0) goto LAB_14001faf7;
    }
    if ((param_6 != (void *)0x0) || (param_1[1] == 0)) {
LAB_14001f9d5:
      iVar5 = param_7 + 0x2d;
      if (((uVar2 & 2) != 0) || (*param_3 != 0)) {
        iVar5 = param_7 + 0x46;
      }
      uVar4 = iVar5 + 1U & 0xfffffffe;
      if (0xffff < uVar4) {
        return 0xc000000d;
      }
      uVar4 = param_7 + 0x58 + uVar4;
      _Dst_01 = (undefined2 *)ExAllocatePool2(0x42,uVar4,0x78436644);
      if (_Dst_01 == (undefined2 *)0x0) {
        uVar10 = 0xc000009a;
      }
      else {
        memset(_Dst_01,0,(ulonglong)uVar4);
        *_Dst_01 = 0x8104;
        _Dst_01[1] = (short)uVar4;
        uVar4 = 0;
        *(undefined4 *)(_Dst_01 + 2) = 1;
        if (param_6 != (void *)0x0) {
          memmove(_Dst_01 + 0x2c,"AuthIdentity",0xd);
          *(undefined1 *)((longlong)_Dst_01 + 0x55) = 0xc;
          if (param_7 != 0) {
            memmove((void *)((longlong)_Dst_01 + 0x65),param_6,(ulonglong)param_7);
          }
          _Dst_01[0x2b] = (short)param_7;
          *(undefined1 *)(_Dst_01 + 0x2a) = 0;
          uVar4 = param_7 + 0x18 & 0xfffffffc;
        }
        *(undefined4 *)(_Dst_01 + 0x28) = 0;
        *(uint *)(_Dst_01 + 0x24) = uVar4;
        *(int *)(_Dst_01 + 0x14) = param_8;
        *(uint *)(_Dst_01 + 0x16) = local_58;
        *(undefined4 *)(_Dst_01 + 0x18) = param_5;
        *(uint *)(_Dst_01 + 0x1a) = uVar2 >> 4 & 1;
        *(undefined8 *)(_Dst_01 + 0xc) = 0;
        *param_10 = _Dst_01;
        *(undefined4 *)(_Dst_01 + 4) = (undefined4)local_48;
        *(undefined4 *)(_Dst_01 + 6) = local_48._4_4_;
        *(undefined4 *)(_Dst_01 + 8) = (undefined4)uStack_40;
        *(undefined4 *)(_Dst_01 + 10) = uStack_40._4_4_;
        *(ulonglong *)(_Dst_01 + 0x1c) = local_38;
        *(longlong *)(_Dst_01 + 0x20) = lStack_30;
      }
      if (_Dst != (void *)0x0) {
LAB_14001f89b:
        ExFreePoolWithTag(_Dst,0);
      }
      if (_Dst_00 != (void *)0x0) {
        ExFreePoolWithTag(_Dst_00,0);
      }
      goto LAB_14001faf7;
    }
    _Dst = (void *)ExAllocatePool2(0x102,(ulonglong)*param_1 + 2,0x78436644);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,(ulonglong)*param_1 + 2);
      memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
      if ((*param_3 == 0) && ((uVar2 & 2) == 0)) {
LAB_14001f8f0:
        pwVar9 = (wchar_t *)0x0;
        if (param_2 == 0) {
          pwVar9 = L"";
        }
        uVar3 = SspiEncodeStringsAsAuthIdentity(_Dst,pwVar9,_Dst_00,&local_50);
        uVar4 = MapSecurityError(uVar3);
        uVar10 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            uVar7 = 10;
LAB_14001f957:
            WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                      &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,uVar4,(char)uVar3);
          }
        }
        else {
          uVar3 = SspiMarshalAuthIdentity(local_50,&param_7,&param_6);
          uVar4 = MapSecurityError(uVar3);
          uVar10 = (ulonglong)uVar4;
          if (-1 < (int)uVar4) {
            bVar1 = true;
            goto LAB_14001f9d5;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            uVar7 = 0xb;
            goto LAB_14001f957;
          }
        }
      }
      else {
        _Dst_00 = (void *)ExAllocatePool2(0x102,(ulonglong)*param_3 + 2,0x78436644);
        if (_Dst_00 != (void *)0x0) {
          memset(_Dst_00,0,(ulonglong)*param_3 + 2);
          memmove(_Dst_00,*(void **)(param_3 + 4),(ulonglong)*param_3);
          goto LAB_14001f8f0;
        }
        uVar10 = 0xc000009a;
      }
      goto LAB_14001f89b;
    }
    uVar10 = 0xc000009a;
  }
  else {
LAB_14001faf7:
    if ((int)uVar10 == 0) goto LAB_14001fb31;
  }
  if (uStack_40 != 0) {
    ExFreePoolWithTag(uStack_40,0);
    uStack_40 = 0;
  }
  if (lStack_30 != 0) {
    ExFreePoolWithTag(lStack_30,0);
    lStack_30 = 0;
  }
LAB_14001fb31:
  if (local_50 != 0) {
    SspiFreeAuthIdentity();
  }
  if (bVar1) {
    SspiLocalFree(param_6);
  }
  return uVar10;
}



===== DfscCreateNameFromUnicodeString @ 14001fb90 =====

undefined8
DfscCreateNameFromUnicodeString
          (ulonglong *param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  longlong lVar2;
  void *_Dst;
  ushort uVar3;
  ulonglong uVar4;
  void *pvVar5;
  
  uVar1 = *param_2;
  if (uVar1 == 0) {
    RtlInitUnicodeString(0,0,param_3,param_4,0,0);
    return 0;
  }
  lVar2 = (ulonglong)(uVar1 >> 1) * 2;
  uVar3 = uVar1;
  if ((*(short *)(*(longlong *)(param_2 + 4) + -2 + lVar2) == 0) ||
     (uVar3 = uVar1 + 2, uVar1 <= uVar3)) {
    uVar4 = (ulonglong)CONCAT22(uVar3,uVar1);
    _Dst = (void *)ExAllocatePool2(0x102,uVar3);
    if (_Dst != (void *)0x0) {
      pvVar5 = _Dst;
      memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)uVar1);
      if (uVar1 < uVar3) {
        *(undefined2 *)((longlong)_Dst + lVar2) = 0;
      }
      *param_1 = uVar4;
      param_1[1] = (ulonglong)pvVar5;
      return 0;
    }
  }
  return 0xc000009a;
}



===== DfscCreateDcContext @ 14001fc7c =====

undefined4 * DfscCreateDcContext(void)

{
  undefined4 *_Dst;
  
  _Dst = (undefined4 *)ExAllocatePool2(0x102,0x48,0x64436644);
  if (_Dst == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids);
    }
  }
  else {
    memset(_Dst,0,0x48);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,_Dst);
    }
    *_Dst = 0x488106;
    _Dst[1] = 1;
  }
  return _Dst;
}



===== DfscGetDomainDCReferral @ 14001fd40 =====

uint DfscGetDomainDCReferral(longlong *param_1,ushort *param_2,wchar_t *param_3,undefined8 *param_4)

{
  uint uVar1;
  
  uVar1 = DfscRmGetReferral(0,param_1,(wchar_t *)(param_1 + 0xd),param_2,param_3,0,param_4);
  if (-1 < (int)uVar1) {
    *(undefined2 *)((longlong)param_1 + 0xda) = 0;
    RtlInitUnicodeString(param_1 + 0x19,0);
  }
  return uVar1;
}



===== DfscGetDsDCReferral @ 14001fdb0 =====

int DfscGetDsDCReferral(longlong param_1,longlong *param_2,char param_3,undefined8 *param_4)

{
  longlong lVar1;
  RPC_STATUS RVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  wchar_t *pwVar7;
  bool bVar8;
  char local_res10 [8];
  char local_res18;
  ulonglong local_58;
  undefined8 local_50;
  undefined8 local_48;
  longlong lStack_40;
  
  local_58 = 0;
  local_50 = 0;
  local_res10[0] = '\0';
  uVar5 = 0;
  local_48 = 0;
  lStack_40 = 0;
  lVar4 = 0;
  local_res18 = param_3;
  RtlInitUnicodeString(&local_48,0);
  lVar1 = *param_2;
  if ((*(char *)(*(longlong *)(lVar1 + 0x10) + 0x12) == '\0') || ((*(uint *)(lVar1 + 8) & 8) != 0))
  {
LAB_14001fe52:
    if (local_res10[0] == '\0') {
      lStack_40 = ExAllocatePool2(0x102,0x208);
      if (lStack_40 == 0) {
        iVar3 = -0x3fffff66;
        goto LAB_14001ff45;
      }
      bVar8 = local_res18 != '\0';
      local_res18 = -local_res18;
      local_48 = CONCAT44(local_48._4_4_,0x2080000);
      iVar3 = DfscGetDCName(param_1 + 0x68,&local_48,bVar8 + 0x210);
      if (iVar3 < 0) goto LAB_14001ff45;
    }
  }
  else {
    lVar4 = DfscReferralGetPrimaryTarget(lVar1);
    RVar2 = DfscIsDomainController(param_1 + 0x68,lVar4 + 0x10,local_res10);
    if (RVar2 < 0) goto LAB_14001fe52;
    if (local_res10[0] == '\0') {
      *(undefined1 *)(*(longlong *)(lVar1 + 0x10) + 0x12) = 0;
      goto LAB_14001fe52;
    }
  }
  *(undefined2 *)(param_1 + 0xda) = 0;
  RtlInitUnicodeString(param_1 + 200,0);
  pwVar7 = (wchar_t *)(lVar4 + 0x10);
  if (local_res10[0] == '\0') {
    pwVar7 = (wchar_t *)&local_48;
  }
  uVar5 = DfscRmGenerateDomainDcReferralFromDCName
                    ((ushort *)(param_1 + 0x68),pwVar7,&local_58,local_res10[0],
                     *(undefined1 *)(*(longlong *)(lVar1 + 0x10) + 0x13));
  iVar3 = (int)uVar5;
  if (iVar3 < 0) {
    uVar5 = local_58;
  }
  else {
    uVar5 = DfscDomainCacheStore(*(longlong *)(param_1 + 0xf0),local_58);
    uVar6 = DfscRmCreateRefContext(uVar5,'\0',&local_50);
    iVar3 = (int)uVar6;
    if ((-1 < iVar3) && (param_4 != (undefined8 *)0x0)) {
      *param_4 = local_50;
    }
  }
LAB_14001ff45:
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0);
  }
  if ((iVar3 < 0) && (uVar5 != 0)) {
    DfscRmDereferenceReferral(uVar5);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_55706db06074317498eaf8c01331c814_Traceguids,iVar3);
  }
  return iVar3;
}



===== DfscIsErrorInList @ 14001ffd0 =====

ulonglong DfscIsErrorInList(int param_1,longlong param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong in_RAX;
  int iVar4;
  uint uVar5;
  
  if (param_1 < 0) {
    uVar5 = 0;
    iVar4 = param_3 + -1;
    do {
      iVar1 = iVar4 + uVar5;
      iVar3 = iVar1 / 2;
      iVar2 = *(int *)(param_2 + (longlong)iVar3 * 4);
      if (iVar2 == param_1) {
        return CONCAT71((uint7)(uint3)(iVar1 - (iVar1 >> 0x1f) >> 9),1);
      }
      iVar1 = iVar3 + -1;
      if (iVar2 < param_1) {
        iVar1 = iVar4;
      }
      iVar4 = iVar1;
      in_RAX = (ulonglong)(iVar3 + 1U);
      if (iVar2 <= param_1) {
        uVar5 = iVar3 + 1U;
      }
    } while ((int)uVar5 <= iVar4);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== DfscCopyTargetAccessStatus @ 14002001c =====

void DfscCopyTargetAccessStatus(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(param_2 + 0x10);
  if (lVar3 == lVar2) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) == 0) {
      return;
    }
    uVar5 = 0x23;
  }
  else {
    if (*(int *)(lVar3 + 0xc) == *(int *)(lVar2 + 0xc)) {
      if ((*(ushort *)(lVar3 + 0x1c) == 0) || (*(short *)(lVar2 + 0x1c) == 0)) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) == 0) {
          return;
        }
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                  &WPP_af603b4b97893b05877342047baf7746_Traceguids,(uint)*(ushort *)(lVar3 + 0x1c),
                  (char)*(undefined2 *)(lVar2 + 0x1c));
        return;
      }
      lVar2 = param_1;
      DfscReferralIterateInitialize(param_1);
      do {
        uVar4 = DfscReferralIterate(lVar2);
        if ((int)uVar4 != 0) {
          DfscReferralIterateInitialize(param_2);
          return;
        }
        lVar2 = DfscReferralGetCurrentTarget(param_1);
        if (*(int *)(lVar2 + 8) != -1) {
          lVar3 = param_2;
          DfscReferralIterateInitialize(param_2);
          while (uVar4 = DfscReferralIterate(lVar3), (int)uVar4 == 0) {
            lVar3 = DfscReferralGetCurrentTarget(param_2);
            iVar1 = RtlCompareUnicodeString(lVar2 + 0x50,lVar3 + 0x50,1);
            if (iVar1 == 0) {
              *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(lVar2 + 8);
              break;
            }
            lVar3 = param_2;
          }
        }
        lVar2 = param_1;
      } while( true );
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
      return;
    }
    uVar5 = 0x24;
  }
  WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
            &WPP_af603b4b97893b05877342047baf7746_Traceguids,param_2,(char)param_1);
  return;
}



===== DfscReferralGetCurrentTarget @ 1400201b0 =====

longlong DfscReferralGetCurrentTarget(longlong param_1)

{
  if (*(ushort *)(param_1 + 0x20) == 0xffff) {
    return 0;
  }
  return *(longlong *)(param_1 + 0x10) + 0xa0 + (ulonglong)*(ushort *)(param_1 + 0x20) * 0x70;
}



===== DfscIterateAndGetReferral @ 1400201dc =====

uint DfscIterateAndGetReferral
               (longlong param_1,longlong *param_2,int param_3,longlong param_4,longlong param_5,
               longlong *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  uVar1 = 0;
  if ((param_1 == 0) || (2 < *(int *)(param_1 + 0x124) - 2U)) {
    while( true ) {
      lVar3 = param_4;
      uVar2 = DfscReferralIterate(param_4);
      if ((int)uVar2 != 0) break;
      lVar3 = DfscReferralGetCurrentTarget(lVar3);
      if (param_3 == 1) {
        uVar1 = DfscGetRootReferral(param_2,(ushort *)(lVar3 + 0x10),param_4,param_5,param_6);
      }
      else {
        uVar1 = DfscGetLinkReferral(param_2,(ushort *)(lVar3 + 0x10),param_5,param_6);
      }
      if (-1 < (int)uVar1) {
        lVar5 = param_4;
        DfscReferralSetCurrentAccessStatus(param_4,uVar1);
        lVar5 = DfscReferralGetPrimaryTarget(lVar5);
        if (lVar3 == lVar5) {
          return uVar1;
        }
        *(undefined2 *)(*(longlong *)(param_4 + 0x10) + 0x1e) = *(undefined2 *)(param_4 + 0x20);
        if (*(char *)(*(longlong *)(param_4 + 0x10) + 0x12) == '\0') {
          return uVar1;
        }
        *(undefined1 *)(*(longlong *)(param_4 + 0x10) + 0x12) = 0;
        return uVar1;
      }
      if (*param_6 != 0) {
        DfscReferralRelease(*param_6);
        *param_6 = 0;
      }
      uVar4 = DfscIsErrorInList(uVar1,0x14000d110,0x1e);
      if ((char)uVar4 == '\0') {
        DfscReferralSetCurrentAccessStatus(param_4,0);
        return uVar1;
      }
      DfscReferralSetCurrentAccessStatus(param_4,uVar1);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                 &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,uVar1);
      }
    }
    if ((int)uVar2 != -0x3fffffc6) {
      return uVar1;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_25814b49fee93ed9772097e36f5d22dd_Traceguids,param_1);
  }
  return 0xc00000be;
}



===== DfscQueryInformationFile @ 140020390 =====

uint DfscQueryInformationFile(longlong *param_1)

{
  ushort uVar1;
  longlong lVar2;
  ushort *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  lVar2 = *param_1;
  puVar3 = (ushort *)param_1[6];
  uVar1 = *puVar3;
  uVar6 = *(uint *)(*(longlong *)(lVar2 + 0xb8) + 8);
  if (uVar6 < 4) {
    uVar6 = 0xc0000023;
    *(undefined8 *)(lVar2 + 0x38) = 0;
  }
  else {
    puVar4 = *(uint **)(lVar2 + 0x18);
    uVar5 = (uVar6 & 0xfffffffe) - 4;
    uVar6 = (uint)uVar1;
    if (uVar5 < uVar1) {
      uVar6 = uVar5;
    }
    uVar5 = (uint)uVar1;
    *puVar4 = uVar5;
    if (uVar6 != 0) {
      memmove(puVar4 + 1,*(void **)(puVar3 + 4),(ulonglong)uVar6);
    }
    uVar7 = uVar6;
    if (uVar5 <= uVar6) {
      uVar7 = uVar5;
    }
    *(ulonglong *)(lVar2 + 0x38) = (ulonglong)(uVar7 + 4);
    uVar6 = -(uint)(uVar6 < uVar5) & 0x80000005;
  }
  return uVar6;
}



===== DfscCmReleaseHandleContext @ 140020430 =====

void DfscCmReleaseHandleContext(undefined8 param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,param_1);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== DfscSurrogatePostProcess @ 140020490 =====

ulonglong DfscSurrogatePostProcess(longlong *param_1)

{
  char cVar1;
  longlong lVar2;
  char *pcVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 local_res8;
  longlong local_res10;
  
  lVar2 = *param_1;
  pcVar3 = *(char **)(lVar2 + 0xb8);
  cVar1 = *pcVar3;
  if ((cVar1 != '\x01') && (cVar1 != '\0')) {
    if (cVar1 == '\x02') {
      DfscSurrogateClose(param_1);
      return 0xc0000016;
    }
    if (cVar1 != '\x13') {
      return 0xc0000016;
    }
  }
  local_res10 = 0;
  iVar4 = IoGetIrpExtraCreateParameter(lVar2,&local_res10);
  if ((iVar4 == 0) && (local_res10 != 0)) {
    local_res8 = 0;
    iVar4 = FsRtlFindExtraCreateParameter(local_res10,&DFSC_DFS_SHARE_CHECK_ECP_GUID,&local_res8,0);
    if (iVar4 == 0) {
      if (*(int *)(lVar2 + 0x30) == -0x3fffffdc) {
        MupSurrogatePurgeNegativeCacheEntry(param_1,*(longlong *)(pcVar3 + 0x30) + 0x58);
        uVar5 = DfscRestartCreateViaReparse(lVar2);
        uVar6 = uVar5 & 0xffffffff;
        if ((int)uVar5 != 0x104) {
          local_res8 = 0;
          iVar4 = FsRtlRemoveExtraCreateParameter
                            (local_res10,&DFSC_DFS_SHARE_CHECK_ECP_GUID,&local_res8,0);
          if (iVar4 == 0) {
            FsRtlFreeExtraCreateParameter(local_res8);
          }
          uVar6 = 0xc0000016;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar6;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
          return uVar6;
        }
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,lVar2);
        return uVar6;
      }
      local_res8 = 0;
      iVar4 = FsRtlRemoveExtraCreateParameter
                        (local_res10,&DFSC_DFS_SHARE_CHECK_ECP_GUID,&local_res8,0);
      if (iVar4 == 0) {
        FsRtlFreeExtraCreateParameter(local_res8);
      }
    }
  }
  return 0xc0000016;
}



===== DfscSurrogateClose @ 140020650 =====

int DfscSurrogateClose(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong local_res8;
  
  iVar2 = 0;
  local_res8 = 0;
  if (*(int *)((longlong)param_1 + 0x3c) == -0x3fffffea) {
    return 0;
  }
  plVar1 = (longlong *)param_1[0xb];
  if (*plVar1 != 0) {
    DfscReferralRelease(*plVar1);
    if (plVar1[1] != 0) {
      iVar2 = DfscGetContainerContextFromIrp(*param_1,&local_res8);
      if (-1 < iVar2) {
        DfscNetUseRelease(local_res8,plVar1[1],0,'\x01');
      }
    }
    DfscCmReleaseHandleContext(plVar1);
    param_1[0xb] = 0;
  }
  return iVar2;
}



===== DfscCmIterateState @ 140020700 =====

int DfscCmIterateState(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  uint *puVar6;
  
  iVar4 = 9;
  uVar5 = DfscReferralIterate(*(longlong *)(param_1 + 0x110));
  iVar3 = (int)uVar5;
  if (iVar3 == -0x3fffffc6) {
    iVar3 = -0x3fffff42;
  }
  else {
    if (iVar3 == 0) {
      lVar1 = *(longlong *)(param_1 + 0x110);
      puVar6 = (uint *)0x0;
      if (*(ushort *)(lVar1 + 0x20) != 0xffff) {
        puVar6 = (uint *)((ulonglong)*(ushort *)(lVar1 + 0x20) * 0x70 +
                         *(longlong *)(lVar1 + 0x10) + 0xa0);
      }
      *(uint **)(param_1 + 0x118) = puVar6;
      if (((*puVar6 & 1) == 0) || (*(int *)(param_1 + 0x124) == 3)) {
        if ((*(int *)(param_1 + 0x138) == 7) && (*(int *)(param_1 + 0x13c) != 0)) {
          iVar4 = 7;
        }
        else {
          iVar4 = 6;
          if ((((*(ushort *)(param_1 + 0x122) < 0x10) && ((*(byte *)(lVar1 + 0x18) & 1) == 0)) &&
              (lVar1 != 0)) && (*(int *)(*(longlong *)(lVar1 + 0x10) + 0xc) == 1)) {
            iVar4 = DfscLookupRootTarget(param_1);
          }
        }
      }
      else {
        iVar4 = 8;
      }
      goto LAB_1400207ca;
    }
    if ((iVar3 != -0x7fffffe6) && (iVar3 != -0x3fffff42)) {
      *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x13c);
      return 9;
    }
  }
  lVar1 = *(longlong *)(param_1 + 0x110);
  if (*(char *)(*(longlong *)(lVar1 + 0x10) + 0x12) != '\0') {
    *(undefined1 *)(*(longlong *)(lVar1 + 0x10) + 0x12) = 0;
  }
  if ((iVar3 == -0x7fffffe6) && ((*(byte *)(*(longlong *)(lVar1 + 0x10) + 0x10) & 8) != 0)) {
    *(uint *)(lVar1 + 8) = *(uint *)(lVar1 + 8) | 8;
    iVar4 = 1;
    if ((*(int *)(param_1 + 0x138) == 6) && ((*(byte *)(param_1 + 0x120) & 4) != 0)) {
      DfscRemoveEcpFromIrp(*(undefined8 *)(param_1 + 0x150),&GUID_ECP_DOMAIN_SERVICE_NAME_CONTEXT);
      *(ushort *)(param_1 + 0x120) = *(ushort *)(param_1 + 0x120) & 0xfffb;
      *(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0x50) = 0;
    }
  }
  iVar2 = *(int *)(param_1 + 0x13c);
  if ((*(int *)(param_1 + 0x13c) < 0) ||
     (iVar2 = *(int *)(param_1 + 0x140), *(int *)(param_1 + 0x140) < 0)) {
    iVar3 = iVar2;
  }
LAB_1400207ca:
  *(int *)(param_1 + 0x13c) = iVar3;
  if (iVar4 == 1) {
    *(int *)(param_1 + 0x140) = iVar3;
  }
  return iVar4;
}



===== DfscReferralIterate @ 1400208e0 =====

undefined8 DfscReferralIterate(longlong param_1)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  ulonglong uVar6;
  
  if ((*(uint *)(param_1 + 8) & 6) != 0) {
    return 0xc000000d;
  }
  uVar6 = (ulonglong)*(ushort *)(param_1 + 0x20);
  if (*(ushort *)(param_1 + 0x20) == 0xffff) {
    if (*(short *)(*(longlong *)(param_1 + 0x10) + 0x1c) == 0) {
      return 0xc000003a;
    }
    uVar2 = *(ushort *)(*(longlong *)(param_1 + 0x10) + 0x1e);
    *(ushort *)(param_1 + 0x1a) = uVar2;
    uVar3 = *(uint *)((ulonglong)uVar2 * 0x70 + 0xa4 + *(longlong *)(param_1 + 0x10));
    uVar5 = *(ushort *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x1c) = uVar3;
    if (((uVar5 & 1) == 0) || (uVar3 < 2)) {
      *(ushort *)(param_1 + 0x20) = uVar2;
      *(ushort *)(param_1 + 0x18) = uVar5 & 0xfffe;
      if (uVar2 == 0) {
        return 0;
      }
      *(ushort *)(param_1 + 0x18) = uVar5 & 0xfffe | 4;
      return 0;
    }
    *(ushort *)(param_1 + 0x18) = uVar5 | 2;
    uVar4 = 0;
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x18);
    if ((uVar2 & 4) != 0) {
      *(ushort *)(param_1 + 0x18) = uVar2 & 0xfffb;
      if ((uVar2 & 1) == 0) {
        *(undefined2 *)(param_1 + 0x20) = 0;
      }
      else {
        iVar1 = *(int *)(uVar6 * 0x70 + 0x34 + *(longlong *)(param_1 + 0x10));
        while (*(int *)(param_1 + 0x1c) == iVar1) {
          uVar5 = (short)uVar6 - 1;
          uVar6 = (ulonglong)uVar5;
          *(ushort *)(param_1 + 0x20) = uVar5;
          iVar1 = *(int *)(uVar6 * 0x70 + 0x34 + *(longlong *)(param_1 + 0x10));
        }
      }
      *(ushort *)(param_1 + 0x18) = uVar2 & 0xfffb | 8;
      return 0;
    }
    do {
      uVar5 = (short)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
      *(ushort *)(param_1 + 0x20) = uVar5;
      if (*(ushort *)(*(longlong *)(param_1 + 0x10) + 0x1c) <= uVar5) {
        return 0x8000001a;
      }
    } while (((uVar2 & 8) != 0) && (uVar5 == *(ushort *)(param_1 + 0x1a)));
    if ((uVar2 & 2) == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) !=
        *(int *)((ulonglong)uVar5 * 0x70 + 0xa4 + *(longlong *)(param_1 + 0x10))) {
      return 0;
    }
    uVar4 = *(ushort *)(param_1 + 0x1a);
    *(ushort *)(param_1 + 0x18) = uVar2 & 0xfffd;
    if (uVar5 == uVar4) {
      return 0;
    }
    *(ushort *)(param_1 + 0x18) = uVar2 & 0xfffd | 4;
  }
  *(ushort *)(param_1 + 0x20) = uVar4;
  return 0;
}



===== DfscReferralRelease @ 140020a60 =====

void DfscReferralRelease(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  if (param_1 != 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      lVar3 = *(longlong *)(param_1 + 0x10);
      if (lVar3 != 0) {
        LOCK();
        piVar1 = (int *)(lVar3 + 4);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
            WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                      &WPP_af603b4b97893b05877342047baf7746_Traceguids,lVar3,
                      (wchar_t *)(lVar3 + 0x90));
          }
          ExFreePoolWithTag(lVar3,0);
        }
        *(undefined8 *)(param_1 + 0x10) = 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_55706db06074317498eaf8c01331c814_Traceguids,param_1);
      }
      ExFreePoolWithTag(param_1,0);
    }
  }
  return;
}



===== DfscLookupRootTarget @ 140020b60 =====

int DfscLookupRootTarget(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  short sVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int extraout_EAX;
  int iVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  wchar_t *pwVar12;
  ushort uVar13;
  undefined8 *puVar14;
  ushort uVar15;
  undefined2 uVar16;
  longlong lVar17;
  longlong lVar18;
  undefined8 *puVar19;
  int iVar20;
  longlong lVar21;
  int local_res8 [2];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  longlong lStack_140;
  undefined8 local_138;
  undefined1 auStack_130 [88];
  longlong local_d8;
  undefined1 auStack_d0 [96];
  ushort local_70 [4];
  longlong lStack_68;
  undefined2 local_5e;
  
  local_res8[0] = 0;
  iVar20 = 6;
  memset(&local_138,0,0x108);
  if (*(short *)(param_1 + 0xd0) == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 6;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
      return 6;
    }
    uVar16 = 0x27;
    pwVar12 = (wchar_t *)(*(longlong *)(param_1 + 0x118) + 0x60);
    goto LAB_140020ff2;
  }
  lVar18 = *(longlong *)(param_1 + 0x118);
  uVar13 = *(ushort *)(param_1 + 0xb0) >> 1;
  local_158 = 0;
  uStack_150 = 0;
  uVar15 = *(ushort *)(lVar18 + 0x50) >> 1;
  local_148 = 0;
  lStack_140 = 0;
  if (uVar15 != 0) {
    do {
      sVar4 = *(short *)(*(longlong *)(lVar18 + 0x58) + -2 + (ulonglong)uVar15 * 2);
      if ((sVar4 != 0x5c) && (sVar4 != 0)) break;
      uVar15 = uVar15 - 1;
    } while (uVar15 != 0);
  }
  if (uVar13 == 0) {
LAB_1400210b7:
    if (uVar15 == 0) {
LAB_140020fbe:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 6;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
        return 6;
      }
      uVar16 = 0x28;
      pwVar12 = (wchar_t *)(*(longlong *)(param_1 + 0x118) + 0x50);
LAB_140020ff2:
      WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,
                &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,pwVar12);
      return 6;
    }
  }
  else {
    do {
      sVar4 = *(short *)(*(longlong *)(param_1 + 0xb8) + -2 + (ulonglong)uVar13 * 2);
      if ((sVar4 != 0x5c) && (sVar4 != 0)) break;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
    if (uVar13 == 0) goto LAB_1400210b7;
    if ((uVar13 == uVar15) && (uVar15 != 0)) {
      uStack_150 = *(undefined8 *)(lVar18 + 0x58);
      local_158._2_6_ = (undefined6)((ulonglong)*(undefined8 *)(lVar18 + 0x50) >> 0x10);
      local_158 = CONCAT62(local_158._2_6_,uVar15 * 2);
      lStack_140 = *(longlong *)(param_1 + 0xb8);
      local_148._2_6_ = (undefined6)((ulonglong)*(undefined8 *)(param_1 + 0xb0) >> 0x10);
      local_148 = CONCAT62(local_148._2_6_,uVar13 * 2);
      iVar9 = RtlCompareUnicodeString
                        (&local_158,&local_148,CONCAT71((int7)((ulonglong)lVar18 >> 8),1));
      if (iVar9 != 0) goto LAB_140020c37;
      goto LAB_140020fbe;
    }
  }
LAB_140020c37:
  puVar19 = (undefined8 *)(param_1 + 8);
  lVar21 = 2;
  puVar10 = &local_138;
  puVar14 = puVar19;
  lVar18 = 2;
  do {
    lVar17 = lVar18;
    puVar1 = puVar10 + 0x10;
    uVar5 = puVar14[1];
    uVar6 = puVar14[2];
    uVar7 = puVar14[3];
    puVar2 = puVar14 + 0x10;
    *puVar10 = *puVar14;
    puVar10[1] = uVar5;
    uVar5 = puVar14[4];
    uVar8 = puVar14[5];
    puVar10[2] = uVar6;
    puVar10[3] = uVar7;
    uVar6 = puVar14[6];
    uVar7 = puVar14[7];
    puVar10[4] = uVar5;
    puVar10[5] = uVar8;
    uVar5 = puVar14[8];
    uVar8 = puVar14[9];
    puVar10[6] = uVar6;
    puVar10[7] = uVar7;
    uVar6 = puVar14[10];
    uVar7 = puVar14[0xb];
    puVar10[8] = uVar5;
    puVar10[9] = uVar8;
    uVar5 = puVar14[0xc];
    uVar8 = puVar14[0xd];
    puVar10[10] = uVar6;
    puVar10[0xb] = uVar7;
    uVar6 = puVar14[0xe];
    uVar7 = puVar14[0xf];
    puVar10[0xc] = uVar5;
    puVar10[0xd] = uVar8;
    puVar10[0xe] = uVar6;
    puVar10[0xf] = uVar7;
    lVar18 = lVar17 + -1;
    puVar10 = puVar1;
    puVar14 = puVar2;
  } while (lVar18 != 0);
  *puVar1 = *puVar2;
  memset((void *)(param_1 + 0x10),0,(ulonglong)((int)lVar17 + 0x5f));
  memset((void *)(param_1 + 0x70),0,0x60);
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined2 *)(param_1 + 0xe2) = 0;
  DfscRewritePath(param_1,(ushort *)(*(longlong *)(param_1 + 0x118) + 0x60),local_70,'\x01');
  plVar3 = (longlong *)(param_1 + 0x110);
  lVar18 = *plVar3;
  *plVar3 = 0;
  if (extraout_EAX < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)extraout_EAX);
    }
    goto LAB_140020e9f;
  }
  uVar11 = DfscGetCacheReferral(puVar19,plVar3,local_res8);
  iVar9 = (int)uVar11;
  if (iVar9 == 0) {
    if (local_res8[0] == 2) {
      uVar13 = local_70[0] >> 1;
      uVar15 = *(ushort *)(param_1 + 0xd0) >> 1;
      uVar11 = (ulonglong)uVar15;
      local_158 = 0;
      uStack_150 = 0;
      if (uVar15 != 0) {
        do {
          sVar4 = *(short *)(*(longlong *)(param_1 + 0xd8) + -2 + uVar11 * 2);
          if ((sVar4 != 0x5c) && (sVar4 != 0)) break;
          uVar15 = (short)uVar11 - 1;
          uVar11 = (ulonglong)uVar15;
        } while (uVar15 != 0);
      }
      uVar15 = (ushort)uVar11;
      if (uVar13 == 0) {
LAB_1400210d4:
        if (uVar15 == 0) {
LAB_14002105e:
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                      &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,
                      (wchar_t *)(param_1 + 0x60));
          }
          goto LAB_140020df9;
        }
      }
      else {
        do {
          sVar4 = *(short *)(lStack_68 + -2 + (ulonglong)uVar13 * 2);
          if ((sVar4 != 0x5c) && (sVar4 != 0)) break;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
        if (uVar13 == 0) goto LAB_1400210d4;
        if ((uVar13 == uVar15) && (uVar15 != 0)) {
          uStack_150 = *(undefined8 *)(param_1 + 0xd8);
          local_158._2_6_ = (undefined6)((ulonglong)*(undefined8 *)(param_1 + 0xd0) >> 0x10);
          local_158 = CONCAT62(local_158._2_6_,uVar15 * 2);
          lStack_140 = lStack_68;
          local_148._2_6_ = local_70._2_6_;
          local_148 = CONCAT62(local_148._2_6_,uVar13 * 2);
          iVar9 = RtlCompareUnicodeString
                            (&local_158,&local_148,CONCAT71((uint7)(byte)((ushort)sVar4 >> 8),1));
          if (iVar9 != 0) goto LAB_140020dd4;
          goto LAB_14002105e;
        }
      }
LAB_140020dd4:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                  &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)*plVar3);
      }
      iVar20 = 1;
    }
    else if (local_res8[0] == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar16 = 0x2c;
LAB_1400211ac:
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,
                 &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
    }
    else if (local_res8[0] == 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar16 = 0x2b;
        goto LAB_1400211ac;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      uVar16 = 0x2d;
      iVar9 = local_res8[0];
      goto LAB_140020f51;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    uVar16 = 0x2e;
LAB_140020f51:
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,
              &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)iVar9);
  }
LAB_140020df9:
  if (iVar20 != 6) {
    if (local_d8 != 0) {
      ExFreePoolWithTag();
    }
    memset(auStack_130,0,0x60);
    memset(auStack_d0,0,0x60);
    local_5e = 0;
    local_70[0] = 0;
    local_70[1] = 0;
    local_70[2] = 0;
    local_70[3] = 0;
    lStack_68 = 0;
    if (lVar18 != 0) {
      DfscReferralRelease(lVar18);
    }
    *(short *)(param_1 + 0x122) = *(short *)(param_1 + 0x122) + 1;
    return iVar20;
  }
LAB_140020e9f:
  if (*(longlong *)(param_1 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0);
  }
  puVar10 = &local_138;
  do {
    puVar14 = puVar19 + 0x10;
    uVar5 = puVar10[1];
    uVar6 = puVar10[2];
    uVar7 = puVar10[3];
    puVar1 = puVar10 + 0x10;
    *puVar19 = *puVar10;
    puVar19[1] = uVar5;
    uVar5 = puVar10[4];
    uVar8 = puVar10[5];
    puVar19[2] = uVar6;
    puVar19[3] = uVar7;
    uVar6 = puVar10[6];
    uVar7 = puVar10[7];
    puVar19[4] = uVar5;
    puVar19[5] = uVar8;
    uVar5 = puVar10[8];
    uVar8 = puVar10[9];
    puVar19[6] = uVar6;
    puVar19[7] = uVar7;
    uVar6 = puVar10[10];
    uVar7 = puVar10[0xb];
    puVar19[8] = uVar5;
    puVar19[9] = uVar8;
    uVar5 = puVar10[0xc];
    uVar8 = puVar10[0xd];
    puVar19[10] = uVar6;
    puVar19[0xb] = uVar7;
    uVar6 = puVar10[0xe];
    uVar7 = puVar10[0xf];
    puVar19[0xc] = uVar5;
    puVar19[0xd] = uVar8;
    puVar19[0xe] = uVar6;
    puVar19[0xf] = uVar7;
    lVar21 = lVar21 + -1;
    puVar10 = puVar1;
    puVar19 = puVar14;
  } while (lVar21 != 0);
  *puVar14 = *puVar1;
  if (*plVar3 != 0) {
    DfscReferralRelease(*plVar3);
  }
  *plVar3 = lVar18;
  return iVar20;
}



===== DfscSurrogatePreProcess @ 140021250 =====

uint DfscSurrogatePreProcess(longlong *******param_1,undefined8 param_2,longlong *******param_3)

{
  char cVar1;
  longlong *****ppppplVar2;
  uint uVar3;
  
  ppppplVar2 = (*param_1)[0x17];
  if (DAT_14000d780 == 0) {
    cVar1 = *(char *)ppppplVar2;
    if ((cVar1 == '\x01') || (cVar1 == '\0')) {
LAB_140021279:
      uVar3 = DfscSurrogateCreate(param_1,ppppplVar2,param_3);
      return uVar3;
    }
    if (cVar1 == '\x05') {
      if (*(int *)(ppppplVar2 + 2) == 9) {
        uVar3 = DfscQueryInformationFile((longlong *)param_1);
        return uVar3;
      }
    }
    else if (cVar1 == '\x13') goto LAB_140021279;
  }
  return 0xc0000016;
}



===== DfscSurrogateCreate @ 1400212b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DfscSurrogateCreate(longlong *******param_1,undefined8 param_2,longlong *******param_3)

{
  int *piVar1;
  longlong *plVar2;
  char cVar3;
  int iVar4;
  longlong *****ppppplVar5;
  longlong ***********ppppppppppplVar6;
  longlong *plVar7;
  undefined8 uVar8;
  code *pcVar9;
  int iVar10;
  undefined1 uVar11;
  int iVar12;
  int iVar13;
  ulonglong uVar14;
  longlong ************pppppppppppplVar15;
  longlong ************pppppppppppplVar16;
  int iVar17;
  longlong lVar18;
  undefined1 *puVar19;
  longlong lVar20;
  char cVar21;
  undefined1 uVar22;
  longlong ******pppppplVar23;
  longlong ***********local_res8;
  longlong ************local_res10;
  longlong local_res18;
  longlong ***********local_res20;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  longlong local_58;
  longlong **********local_50 [2];
  
  lVar18 = 0;
  local_res18 = 0;
  cVar21 = '\0';
  lVar20 = 0;
  local_res10 = (longlong ************)((ulonglong)local_res10 & 0xffffffffffffff00);
  local_res20 = (longlong ***********)0x0;
  local_58 = 0;
  local_res8 = (longlong ***********)param_1;
  iVar12 = IoGetIrpExtraCreateParameter(*param_1,&local_58);
  if ((iVar12 == 0) && (local_58 != 0)) {
    local_50[0] = (longlong **********)0x0;
    param_3 = (longlong *******)local_50;
    iVar12 = FsRtlFindExtraCreateParameter(local_58,&DFSC_DFS_SHARE_CHECK_ECP_GUID);
    if (iVar12 == 0) {
      uVar14 = DfscRemoveEcpFromIrp(*param_1,&DFSC_DFS_SHARE_CHECK_ECP_GUID);
      cVar21 = '\x01';
      local_res10 = (longlong ************)CONCAT71(local_res10._1_7_,1);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        param_3 = (longlong *******)&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids;
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,*param_1,(char)uVar14);
      }
    }
  }
  puVar19 = auStackY_98;
  pppppppppppplVar16 = &local_res20;
  pppppplVar23 = (longlong ******)0x0;
  iVar12 = DfscGetContainerContextFromIrp((longlong)*param_1,pppppppppppplVar16);
  if (-1 < iVar12) {
    pppppppppppplVar16 = (longlong ************)0x0;
    param_3 = (longlong *******)local_res20;
    iVar12 = DfscCmInitializeContext
                       (0,(undefined2 *)0x0,(longlong)local_res20,(undefined4 *)0x0,
                        (longlong *)param_1,0,&local_res18);
    lVar20 = local_res18;
    if (-1 < iVar12) {
      pppppplVar23 = param_1[0xb];
      do {
        iVar17 = (int)lVar18;
        iVar12 = (*(code *)(&DfscCmDispatchTable)[iVar17])(lVar20);
        lVar18 = (longlong)iVar12;
        *(int *)(lVar20 + 0x138) = iVar17;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_qDSS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pppppppppppplVar16,param_3,lVar20,
                      (char)*(undefined4 *)(lVar20 + 0x13c),(wchar_t *)(&DfscStateTextTable)[iVar17]
                      ,(wchar_t *)(&DfscStateTextTable)[lVar18]);
        }
      } while (iVar12 != 10);
      iVar12 = *(int *)(lVar20 + 0x13c);
      param_1 = (longlong *******)local_res8;
      cVar21 = (char)local_res10;
    }
  }
  cVar3 = *(char *)((longlong)param_1 + 0x4f);
  if ((-1 < iVar12) && (iVar12 != 0x104)) {
    ppppplVar5 = *(longlong ******)(lVar20 + 0x110);
    *pppppplVar23 = ppppplVar5;
    DfscReferralReference((longlong)ppppplVar5);
    uVar11 = 1;
    goto LAB_140021561;
  }
  if (pppppplVar23 != (longlong ******)0x0) {
    if (pppppplVar23[1] != (longlong *****)0x0) {
      param_3 = (longlong *******)0x0;
      DfscNetUseRelease((longlong)local_res20,(longlong)pppppplVar23[1],0,'\x01');
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      param_3 = (longlong *******)&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,pppppplVar23);
    }
    pppppppppppplVar16 = (longlong ************)0x0;
    ExFreePoolWithTag();
    param_1[0xb] = (longlong ******)0x0;
  }
  pppppppppppplVar15 = (longlong ************)0x0;
  if (cVar3 == '\0') {
    if ((lVar20 == 0) || (*(int *)(lVar20 + 0x144) == 0)) {
      if (iVar12 < 0) {
        iVar17 = 5;
        do {
          iVar13 = (iVar17 + (int)pppppppppppplVar15) / 2;
          iVar4 = *(int *)(&DfscCreatePathErrorList + (longlong)iVar13 * 4);
          if (iVar4 == iVar12) goto LAB_140021559;
          iVar10 = iVar13 + -1;
          if (iVar4 < iVar12) {
            iVar10 = iVar17;
          }
          iVar17 = iVar10;
          if (iVar4 <= iVar12) {
            pppppppppppplVar15 = (longlong ************)(ulonglong)(iVar13 + 1);
          }
        } while ((int)pppppppppppplVar15 <= iVar17);
      }
    }
    else if (*(int *)(lVar20 + 0x144) == 2) {
      if (cVar21 == '\0') {
        ppppppppppplVar6 = (longlong ***********)*param_1;
        local_res8 = (longlong ***********)0x0;
        local_res10 = (longlong ************)0x0;
        if ((char)*(undefined4 *)(ppppppppppplVar6 + 2) < '\0') {
          pppppppppppplVar16 = &local_res8;
          iVar12 = IoGetIrpExtraCreateParameter(ppppppppppplVar6);
          if (iVar12 == 0) {
            if (local_res8 == (longlong ***********)0x0) {
              pppppppppppplVar16 = &local_res8;
              iVar12 = FsRtlAllocateExtraCreateParameterList(0);
              if (iVar12 == 0) {
                pppppppppppplVar16 = (longlong ************)local_res8;
                iVar12 = IoSetIrpExtraCreateParameter(ppppppppppplVar6);
                if (iVar12 == 0) goto LAB_1400214d2;
                FsRtlFreeExtraCreateParameterList(local_res8);
              }
              goto LAB_14002152a;
            }
LAB_1400214d2:
            param_3 = (longlong *******)&local_res10;
            iVar12 = FsRtlFindExtraCreateParameter
                               (local_res8,&DFSC_DFS_SHARE_CHECK_ECP_GUID,param_3,0);
            if (iVar12 != 0) {
              param_3 = (longlong *******)0x0;
              pppppppppppplVar16 = (longlong ************)0x0;
              iVar12 = FsRtlAllocateExtraCreateParameter(&DFSC_DFS_SHARE_CHECK_ECP_GUID,0,0,0);
              if (iVar12 == 0) {
                pppppppppppplVar16 = local_res10;
                iVar12 = FsRtlInsertExtraCreateParameter(local_res8);
                if (iVar12 == 0) {
                  pppppppppppplVar15 = local_res10;
                  goto LAB_140021539;
                }
                FsRtlFreeExtraCreateParameter(local_res10);
              }
              goto LAB_14002152a;
            }
          }
          else {
LAB_14002152a:
            if (iVar12 != 0x40000000) goto LAB_140021539;
          }
          uVar22 = 0;
          pppppppppppplVar16 = (longlong ************)&DFSC_DFS_SHARE_CHECK_ECP_GUID;
          uVar14 = DfscRemoveEcpFromIrp(ppppppppppplVar6,&DFSC_DFS_SHARE_CHECK_ECP_GUID);
          uVar11 = (undefined1)uVar14;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            pppppppppppplVar16 = (longlong ************)0x17;
            param_3 = (longlong *******)&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids;
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                     &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,ppppppppppplVar6);
          }
        }
        else {
          iVar12 = -0x3ffffff0;
LAB_140021539:
          uVar11 = (undefined1)iVar12;
          uVar22 = SUB81(pppppppppppplVar15,0);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pppppppppppplVar16,param_3,
                     ppppppppppplVar6,uVar22,uVar11);
        }
      }
LAB_140021559:
      iVar12 = -0x3fffffea;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    if (lVar20 == 0) {
      uVar11 = 0xff;
    }
    else {
      uVar11 = (undefined1)*(undefined4 *)(lVar20 + 0x144);
    }
    WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pppppppppppplVar16,param_3,iVar12,uVar11);
  }
  uVar11 = 0;
LAB_140021561:
  *(undefined1 *)((longlong)param_1 + 0x4e) = uVar11;
  if ((lVar20 != 0) && (iVar12 != -0x3fffffea)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,(uint)*(ushort *)(lVar20 + 0xe0));
    }
    *(undefined2 *)((longlong)param_1 + 0x4c) = *(undefined2 *)(lVar20 + 0xe0);
  }
  if (lVar20 != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,lVar20,
                (char)*(undefined4 *)(lVar20 + 4));
    }
    LOCK();
    piVar1 = (int *)(lVar20 + 4);
    iVar17 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar17 != 1) {
      return iVar12;
    }
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000d658,1);
    lVar18 = local_res18;
    plVar2 = (longlong *)(local_res18 + 0x170);
    lVar20 = *plVar2;
    if ((*(longlong **)(lVar20 + 8) == plVar2) &&
       (plVar7 = *(longlong **)(local_res18 + 0x178), (longlong *)*plVar7 == plVar2)) {
      *plVar7 = lVar20;
      *(longlong **)(lVar20 + 8) = plVar7;
      ExReleaseResourceLite(&DAT_14000d658);
      KeLeaveCriticalRegion();
      if (*(longlong *)(lVar18 + 0x68) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar18 + 0x68),0);
      }
      *(undefined8 *)(lVar18 + 0x10) = 0;
      *(undefined8 *)(lVar18 + 0x18) = 0;
      *(undefined8 *)(lVar18 + 0x20) = 0;
      *(undefined8 *)(lVar18 + 0x28) = 0;
      *(undefined8 *)(lVar18 + 0x30) = 0;
      *(undefined8 *)(lVar18 + 0x38) = 0;
      *(undefined8 *)(lVar18 + 0x40) = 0;
      *(undefined8 *)(lVar18 + 0x48) = 0;
      *(undefined8 *)(lVar18 + 0x50) = 0;
      *(undefined8 *)(lVar18 + 0x58) = 0;
      *(undefined8 *)(lVar18 + 0x60) = 0;
      *(undefined8 *)(lVar18 + 0x68) = 0;
      *(undefined8 *)(lVar18 + 0x70) = 0;
      *(undefined8 *)(lVar18 + 0x78) = 0;
      *(undefined8 *)(lVar18 + 0x80) = 0;
      *(undefined8 *)(lVar18 + 0x88) = 0;
      *(undefined8 *)(lVar18 + 0x90) = 0;
      *(undefined8 *)(lVar18 + 0x98) = 0;
      *(undefined8 *)(lVar18 + 0xa0) = 0;
      *(undefined8 *)(lVar18 + 0xa8) = 0;
      *(undefined8 *)(lVar18 + 0xb0) = 0;
      *(undefined8 *)(lVar18 + 0xb8) = 0;
      *(undefined8 *)(lVar18 + 0xc0) = 0;
      *(undefined8 *)(lVar18 + 200) = 0;
      *(undefined8 *)(lVar18 + 0xd0) = 0;
      *(undefined8 *)(lVar18 + 0xd8) = 0;
      *(undefined2 *)(lVar18 + 0xe2) = 0;
      lVar20 = *(longlong *)(lVar18 + 0xe8);
      if (lVar20 != 0) {
        lVar18 = *(longlong *)(lVar20 + 0x18);
        if (lVar18 != 0) {
          KeEnterCriticalRegion();
          ExAcquireResourceExclusiveLite(lVar18 + 0x68,1);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                    &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,lVar20,
                    (char)*(undefined4 *)(lVar20 + 4));
        }
        LOCK();
        piVar1 = (int *)(lVar20 + 4);
        iVar17 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar17 == 1) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,lVar20);
          }
          if ((lVar18 != 0) && (*(longlong *)(lVar20 + 0x18) != 0)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                       &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,lVar20);
            }
            DfscCredTableDelete(*(undefined8 *)(lVar20 + 0x18),lVar20);
          }
          if (*(longlong *)(lVar20 + 0x10) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar20 + 0x10),0);
            *(undefined8 *)(lVar20 + 0x10) = 0;
          }
          if (*(longlong *)(lVar20 + 0x40) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar20 + 0x40),0);
            *(undefined8 *)(lVar20 + 0x40) = 0;
          }
          ExFreePoolWithTag(lVar20,0);
        }
        if (lVar18 != 0) {
          ExReleaseResourceLite(lVar18 + 0x68);
          KeLeaveCriticalRegion();
        }
        *(undefined8 *)(local_res18 + 0xe8) = 0;
        lVar18 = local_res18;
      }
      lVar20 = *(longlong *)(lVar18 + 0x110);
      if (lVar20 != 0) {
        LOCK();
        piVar1 = (int *)(lVar20 + 4);
        iVar17 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar17 == 1) {
          lVar18 = *(longlong *)(lVar20 + 0x10);
          if (lVar18 != 0) {
            LOCK();
            piVar1 = (int *)(lVar18 + 4);
            iVar17 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar17 == 1) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
                WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                          &WPP_af603b4b97893b05877342047baf7746_Traceguids,lVar18,
                          (wchar_t *)(lVar18 + 0x90));
              }
              ExFreePoolWithTag(lVar18,0);
            }
            *(undefined8 *)(lVar20 + 0x10) = 0;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                     &WPP_55706db06074317498eaf8c01331c814_Traceguids,lVar20);
          }
          ExFreePoolWithTag(lVar20,0);
        }
        *(undefined8 *)(local_res18 + 0x110) = 0;
        lVar18 = local_res18;
      }
      if (*(longlong *)(lVar18 + 0xf8) != 0) {
        PsDereferenceSiloContext();
        *(undefined8 *)(lVar18 + 0xf8) = 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,lVar18);
      }
      ExFreePoolWithTag(lVar18,0);
      return iVar12;
    }
    pcVar9 = (code *)swi(0x29);
    (*pcVar9)(3);
    puVar19 = auStackY_90;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar19 + -8) = 0x140021cb5;
    WPP_SF_(uVar8,0x11,&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids);
  }
  return iVar12;
}



===== DfscCmInitializeContext @ 140021cc0 =====

int DfscCmInitializeContext
              (longlong param_1,undefined2 *param_2,longlong param_3,undefined4 *param_4,
              longlong *param_5,longlong param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  short *psVar2;
  char *pcVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  longlong *plVar9;
  ushort uVar10;
  undefined1 *puVar11;
  int extraout_EAX;
  int iVar12;
  undefined8 *puVar13;
  undefined4 *puVar14;
  undefined8 uVar15;
  void *pvVar16;
  undefined2 *_Dst;
  longlong lVar17;
  undefined *puVar18;
  ulonglong uVar19;
  uint *puVar20;
  undefined1 *puVar21;
  undefined8 uVar22;
  longlong lVar23;
  ushort uVar24;
  uint uVar25;
  uint uVar26;
  undefined1 auStack_128 [8];
  undefined1 auStack_120 [88];
  undefined8 local_c8;
  ulonglong local_b8;
  void *pvStack_b0;
  undefined8 *local_a8;
  ulonglong local_a0;
  short *psStack_98;
  undefined8 local_90;
  longlong lStack_88;
  undefined8 local_78;
  longlong lStack_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  ushort local_58 [16];
  
  plVar9 = param_5;
  puVar14 = (undefined4 *)0x0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  local_a0 = 0;
  psStack_98 = (short *)0x0;
  if (param_5 == (longlong *)0x0) {
    lVar23 = 0;
    param_5._0_4_ = 0;
    local_c8 = 0;
    local_a8 = (undefined8 *)0x0;
LAB_140021d95:
    puVar21 = auStack_128;
    puVar14 = (undefined4 *)ExAllocatePool2(0x102);
    if (puVar14 == (undefined4 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids);
      }
      iVar12 = -0x3fffff66;
    }
    else {
      memset(puVar14 + 2,0,0x178);
      *puVar14 = 0x1808102;
      puVar14[1] = 1;
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_14000d658,1);
      puVar13 = (undefined8 *)(puVar14 + 0x5c);
      if ((undefined *)*DAT_14000d760 == &DAT_14000d758) {
        *(undefined8 **)(puVar14 + 0x5e) = DAT_14000d760;
        *puVar13 = &DAT_14000d758;
        *DAT_14000d760 = puVar13;
        DAT_14000d760 = puVar13;
        ExReleaseResourceLite(&DAT_14000d658);
        KeLeaveCriticalRegion();
        puVar21 = auStack_128;
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          puVar18 = WPP_GLOBAL_Control;
          puVar21 = auStack_128;
          puVar11 = auStack_128;
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0) goto LAB_1400226ae;
        }
      }
      else {
        puVar18 = (undefined *)0x3;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar11 = auStack_120;
LAB_1400226ae:
        puVar21 = puVar11;
        uVar15 = *(undefined8 *)(puVar18 + 0x18);
        *(undefined8 *)(puVar21 + -8) = 0x1400226c6;
        WPP_SF_q(uVar15,0xd,&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,puVar14);
      }
      puVar14[0x4f] = 0;
      puVar14[0x51] = 0;
      *(longlong **)(puVar14 + 0x52) = plVar9;
      *(longlong *)(puVar14 + 0x54) = lVar23;
      puVar14[0x49] = 0;
      if (lVar23 == 0) {
LAB_140021e94:
        puVar14[0x3c] = puVar14[0x3c] | (uint)param_5;
        lVar17 = *(longlong *)(puVar21 + 0x60);
        if (param_6 != 0) {
          lVar17 = param_6;
        }
        *(longlong *)(puVar14 + 0x42) = lVar17;
        local_58[0] = 0;
        local_58[1] = 0;
        local_58[2] = 0;
        local_58[3] = 0;
        local_58[4] = 0;
        local_58[5] = 0;
        local_58[6] = 0;
        local_58[7] = 0;
        uVar5 = *param_4;
        uVar6 = param_4[1];
        uVar7 = param_4[2];
        uVar8 = param_4[3];
        if (param_2 != (undefined2 *)0x0) {
          LOCK();
          *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 1;
          UNLOCK();
        }
        *(undefined8 *)(puVar21 + 0x20) = 0;
        uVar22 = 0;
        *(undefined8 *)(puVar21 + -8) = 0x140021ee4;
        local_68 = uVar5;
        uStack_64 = uVar6;
        uStack_60 = uVar7;
        uStack_5c = uVar8;
        uVar15 = DfscGetPathComponents
                           ((ushort *)&local_68,(short *)&local_a0,(short *)0x0,(short *)0x0,
                            *(short **)(puVar21 + 0x20));
        if (((((int)uVar15 != 0) || ((ushort)local_a0 == (short)uVar15)) ||
            (psStack_98 == (short *)0x0)) || (*psStack_98 == 0)) {
          iVar12 = -0x3fffffea;
          goto LAB_14002254b;
        }
        if (param_2 == (undefined2 *)0x0) {
          param_2 = (undefined2 *)0x0;
          if (lVar23 == 0) {
            lVar17 = param_1;
            if (param_1 != 0) goto LAB_140021f31;
          }
          else {
            lVar17 = lVar23;
LAB_140021f31:
            pcVar3 = *(char **)(lVar17 + 0xb8);
            *(char **)(puVar21 + 0x50) = pcVar3;
            if ((*pcVar3 == '\0') && (*(int *)(pcVar3 + 0x20) != 0)) {
              puVar20 = *(uint **)(lVar17 + 0x18);
              do {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
                  uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                  *(undefined8 *)(puVar21 + -8) = 0x1400226fa;
                  WPP_SF_s(uVar15,puVar20,uVar22,(char *)(puVar20 + 2));
                }
                *(uint **)(puVar21 + 0x40) = puVar20 + 2;
                *(undefined8 *)(puVar21 + -8) = 0x1400222a1;
                iVar12 = strcmp((char *)(puVar20 + 2),"Principal");
                if (iVar12 == 0) {
LAB_1400222a9:
                  if (*(short *)((longlong)puVar20 + 6) != 0) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
                      uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                      *(undefined8 *)(puVar21 + -8) = 0x140022718;
                      WPP_SF_(uVar15,0x14,&WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids);
                    }
                    *(undefined8 *)(puVar21 + 0x40) = *(undefined8 *)(lVar17 + 0x18);
                    local_78 = 0;
                    lStack_70 = 0;
                    *(undefined4 *)(puVar21 + 0x60) =
                         *(undefined4 *)(*(longlong *)(puVar21 + 0x50) + 0x20);
                    local_90 = 0;
                    lStack_88 = 0;
                    *(undefined8 *)(puVar21 + -8) = 0x140022308;
                    RtlInitUnicodeStringEx(&local_78,0);
                    uVar10 = (ushort)local_a0;
                    uVar19 = local_a0 & 0xffff;
                    *(undefined8 *)(puVar21 + 0x50) = 0;
                    *(undefined8 *)(puVar21 + 0x58) = 0;
                    if ((ushort)local_a0 == 0) {
                      *(undefined8 *)(puVar21 + -8) = 0x1400225f3;
                      RtlInitUnicodeString(&local_78,0);
LAB_1400223ba:
                      uVar26 = *(uint *)(puVar21 + 0x60);
                      uVar19 = (ulonglong)uVar26;
                      if (((0xffff < uVar26) ||
                          (local_b8 = uVar19,
                          uVar19 < (ulonglong)*(ushort *)(*(longlong *)(puVar21 + 0x40) + 6) + 9 +
                                   (ulonglong)*(byte *)(*(longlong *)(puVar21 + 0x40) + 5))) ||
                         (0xffff < uVar26 + 0x58)) {
                        param_5._0_4_ = -0x3ffffff3;
                        goto LAB_14002275b;
                      }
                      *(ulonglong *)(puVar21 + 0x50) = (ulonglong)(uVar26 + 0x58);
                      *(undefined8 *)(puVar21 + -8) = 0x140022417;
                      _Dst = (undefined2 *)ExAllocatePool2(0x42);
                      if (_Dst == (undefined2 *)0x0) {
                        param_5._0_4_ = -0x3fffff66;
                        goto LAB_14002275b;
                      }
                      *(undefined8 *)(puVar21 + -8) = 0x140022437;
                      memset(_Dst,0,*(size_t *)(puVar21 + 0x50));
                      uVar1 = *(undefined4 *)(puVar21 + 0x60);
                      pvVar16 = *(void **)(puVar21 + 0x40);
                      *_Dst = 0x8104;
                      *(undefined4 *)(_Dst + 2) = 1;
                      _Dst[1] = (short)uVar1 + 0x58;
                      *(undefined8 *)(_Dst + 0xc) = 0;
                      *(undefined4 *)(_Dst + 0x24) = uVar1;
                      *(undefined8 *)(_Dst + 4) = local_78;
                      *(longlong *)(_Dst + 8) = lStack_70;
                      *(undefined8 *)(puVar21 + -8) = 0x140022476;
                      uVar19 = local_b8;
                      memmove(_Dst + 0x28,pvVar16,local_b8);
                      lVar17 = *(longlong *)(puVar21 + 0x40);
                      local_90 = CONCAT62(CONCAT42(local_90._4_4_,*(undefined2 *)(lVar17 + 6)),
                                          *(undefined2 *)(lVar17 + 6));
                      lStack_88 = lVar17 + 9 + (ulonglong)*(byte *)(lVar17 + 5);
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
                        uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                        *(undefined2 **)(puVar21 + 0x30) = _Dst;
                        *(undefined8 **)(puVar21 + 0x28) = &local_90;
                        *(longlong *)(puVar21 + 0x20) = lVar17 + 8;
                        *(undefined8 *)(puVar21 + -8) = 0x140022750;
                        WPP_SF_ZsZq(uVar15,&local_90,uVar19,_Dst + 4,*(char **)(puVar21 + 0x20),
                                    *(wchar_t **)(puVar21 + 0x28),puVar21[0x30]);
                      }
                      param_5._0_4_ = 0;
                      param_2 = _Dst;
                    }
                    else {
                      uVar26 = (uint)(ushort)local_a0;
                      *(ushort *)(puVar21 + 0x52) = (ushort)local_a0;
                      *(ushort *)(puVar21 + 0x50) = (ushort)local_a0;
                      if (psStack_98[(ulonglong)((ushort)local_a0 >> 1) - 1] == 0) {
LAB_14002235d:
                        *(undefined8 *)(puVar21 + -8) = 0x140022373;
                        pvVar16 = (void *)ExAllocatePool2(0x102,uVar19 & 0xffff);
                        *(void **)(puVar21 + 0x58) = pvVar16;
                        if (pvVar16 != (void *)0x0) {
                          *(undefined8 *)(puVar21 + -8) = 0x140022397;
                          memmove(pvVar16,psStack_98,(ulonglong)uVar26);
                          if (uVar10 < (ushort)uVar19) {
                            *(undefined2 *)
                             (*(longlong *)(puVar21 + 0x58) + (ulonglong)(uVar10 >> 1) * 2) = 0;
                          }
                          local_78 = *(undefined8 *)(puVar21 + 0x50);
                          lStack_70 = *(longlong *)(puVar21 + 0x58);
                          goto LAB_1400223ba;
                        }
                        param_5._0_4_ = -0x3fffff66;
                      }
                      else {
                        uVar25 = uVar26 + 2;
                        uVar19 = (ulonglong)uVar25;
                        uVar24 = (ushort)uVar25;
                        *(ushort *)(puVar21 + 0x52) = uVar24;
                        if ((ushort)local_a0 <= uVar24) goto LAB_14002235d;
                        param_5._0_4_ = -0x3fffff66;
                      }
LAB_14002275b:
                      if (lStack_70 != 0) {
                        *(undefined8 *)(puVar21 + -8) = 0x140022771;
                        ExFreePoolWithTag(lStack_70,0);
                      }
                    }
                    if ((uint)param_5 == 0) goto LAB_14002213a;
                    break;
                  }
                }
                else {
                  *(undefined8 *)(puVar21 + -8) = 0x1400224dc;
                  iVar12 = strcmp(*(char **)(puVar21 + 0x40),"UserName");
                  if (iVar12 == 0) goto LAB_1400222a9;
                  *(undefined8 *)(puVar21 + -8) = 0x1400224f5;
                  iVar12 = strcmp(*(char **)(puVar21 + 0x40),"Password");
                  if (iVar12 == 0) goto LAB_1400222a9;
                  *(undefined8 *)(puVar21 + -8) = 0x14002250e;
                  iVar12 = strcmp(*(char **)(puVar21 + 0x40),"AuthIdentity");
                  if (iVar12 == 0) goto LAB_1400222a9;
                }
                if (*puVar20 == 0) break;
                puVar20 = (uint *)((longlong)puVar20 + (ulonglong)*puVar20);
              } while( true );
            }
          }
          local_b8 = 0;
          pvStack_b0 = (void *)0x0;
          local_90 = 0;
          lStack_88 = 0;
          *(undefined8 *)(puVar21 + -8) = 0x140021f76;
          RtlInitUnicodeStringEx(&local_b8,0);
          *(undefined8 *)(puVar21 + -8) = 0x140021f88;
          RtlInitUnicodeStringEx(&local_90,0);
          uVar10 = (ushort)local_a0;
          uVar19 = local_a0 & 0xffff;
          *(undefined8 *)(puVar21 + 0x50) = 0;
          *(undefined8 *)(puVar21 + 0x58) = 0;
          if ((ushort)local_a0 == 0) {
            *(undefined8 *)(puVar21 + -8) = 0x1400225d7;
            RtlInitUnicodeString(&local_b8,0);
LAB_14002203f:
            param_5._0_4_ = 0;
            uVar26 = (ushort)local_b8 + 0x17 & 0xfffffffc;
            if (0xffff < uVar26) {
              param_5._0_4_ = -0x3ffffff3;
              goto LAB_14002278a;
            }
            *(ulonglong *)(puVar21 + 0x50) = (ulonglong)(uVar26 + 0x58);
            *(undefined8 *)(puVar21 + -8) = 0x140022076;
            param_2 = (undefined2 *)ExAllocatePool2(0x42);
            if (param_2 == (undefined2 *)0x0) goto LAB_140022787;
            *(undefined8 *)(puVar21 + -8) = 0x140022096;
            memset(param_2,0,*(size_t *)(puVar21 + 0x50));
            *param_2 = 0x8104;
            param_2[1] = (short)uVar26 + 0x58;
            *(undefined4 *)(param_2 + 2) = 1;
            *(undefined8 *)(param_2 + 0xc) = 0;
            *(ulonglong *)(param_2 + 4) = local_b8;
            *(void **)(param_2 + 8) = pvStack_b0;
            *(undefined8 *)(param_2 + 0x2c) = 0x617069636e697250;
            *(undefined1 *)(param_2 + 0x30) = 0x6c;
            *(undefined1 *)((longlong)param_2 + 0x55) = 0xb;
            param_2[0x2b] = (ushort)local_b8;
            *(undefined8 *)(puVar21 + -8) = 0x1400220f4;
            memmove(param_2 + 0x32,pvStack_b0,local_b8 & 0xffff);
            *(undefined4 *)(param_2 + 0x28) = 0;
            *(uint *)(param_2 + 0x24) = uVar26;
            *(undefined8 *)(param_2 + 0x1c) = local_90;
            *(longlong *)(param_2 + 0x20) = lStack_88;
          }
          else {
            uVar26 = (uint)(ushort)local_a0;
            *(ushort *)(puVar21 + 0x52) = (ushort)local_a0;
            *(ushort *)(puVar21 + 0x50) = (ushort)local_a0;
            if (psStack_98[(ulonglong)((ushort)local_a0 >> 1) - 1] == 0) {
LAB_140021fdd:
              *(undefined8 *)(puVar21 + -8) = 0x140021ff3;
              pvVar16 = (void *)ExAllocatePool2(0x102,uVar19 & 0xffff);
              *(void **)(puVar21 + 0x58) = pvVar16;
              if (pvVar16 != (void *)0x0) {
                *(undefined8 *)(puVar21 + -8) = 0x140022017;
                memmove(pvVar16,psStack_98,(ulonglong)uVar26);
                if (uVar10 < (ushort)uVar19) {
                  *(undefined2 *)(*(longlong *)(puVar21 + 0x58) + (ulonglong)(uVar10 >> 1) * 2) = 0;
                }
                local_b8 = *(ulonglong *)(puVar21 + 0x50);
                pvStack_b0 = *(void **)(puVar21 + 0x58);
                goto LAB_14002203f;
              }
            }
            else {
              uVar25 = uVar26 + 2;
              uVar19 = (ulonglong)uVar25;
              uVar24 = (ushort)uVar25;
              *(ushort *)(puVar21 + 0x52) = uVar24;
              if ((ushort)local_a0 <= uVar24) goto LAB_140021fdd;
            }
LAB_140022787:
            param_5._0_4_ = -0x3fffff66;
LAB_14002278a:
            param_2 = (undefined2 *)0x0;
            if (pvStack_b0 != (void *)0x0) {
              *(undefined8 *)(puVar21 + -8) = 0x14002279c;
              ExFreePoolWithTag(pvStack_b0,0);
              pvStack_b0 = (void *)0x0;
            }
            if (lStack_88 != 0) {
              *(undefined8 *)(puVar21 + -8) = 0x1400227c1;
              ExFreePoolWithTag(lStack_88,0);
              lStack_88 = 0;
            }
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            *(undefined8 *)(puVar21 + -8) = 0x1400227e7;
            WPP_SF_q(uVar15,0x12,&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,param_2);
          }
          iVar12 = (uint)param_5;
          if ((uint)param_5 != 0) goto LAB_14002218e;
        }
LAB_14002213a:
        *(longlong **)(puVar14 + 2) = plVar9;
        *(undefined2 **)(puVar14 + 0x3a) = param_2;
        *(longlong *)(puVar14 + 0x3e) = param_3;
        puVar14[0x4a] = uVar5;
        puVar14[0x4b] = uVar6;
        puVar14[0x4c] = uVar7;
        puVar14[0x4d] = uVar8;
        if (param_3 != 0) {
          *(undefined8 *)(puVar21 + -8) = 0x1400227f6;
          PsReferenceSiloContext(param_3);
        }
        *(undefined2 *)(puVar14 + 0x38) = 0xffff;
        if (lVar23 != 0) {
          param_1 = lVar23;
        }
        *(longlong *)(puVar14 + 0x40) = param_1;
        *(undefined8 *)(puVar21 + -8) = 0x14002218c;
        DfscRewritePath((longlong)puVar14,(ushort *)&local_68,local_58,'\0');
        iVar12 = extraout_EAX;
      }
      else {
        local_b8 = 0;
        *(undefined8 *)(puVar21 + 0x50) = 0;
        *(undefined8 *)(puVar21 + -8) = 0x140022210;
        iVar12 = IoGetIrpExtraCreateParameter(lVar23,&local_b8);
        if (iVar12 != 0) {
          iVar12 = -0x3fffff1b;
          goto LAB_14002254b;
        }
        iVar12 = 0;
        if (local_b8 == 0) {
LAB_14002257c:
          lVar17 = *(longlong *)(puVar21 + 0x50);
          if (lVar17 != 0) {
            uVar26 = 0;
            if (*(int *)(lVar17 + 8) == 3) {
              uVar26 = 6;
            }
            else if (*(int *)(lVar17 + 8) == 2) {
              uVar26 = 2;
            }
            if ((*(uint *)(lVar17 + 0xc) & 8) != 0) {
              uVar26 = uVar26 | 1;
            }
            puVar14[0x3c] = uVar26;
            goto LAB_140021e94;
          }
        }
        else {
          *(undefined8 *)(puVar21 + -8) = 0x140022242;
          iVar12 = FsRtlFindExtraCreateParameter(local_b8,&GUID_ECP_NETWORK_OPEN_CONTEXT);
          if (iVar12 == -0x3ffffddb) {
            puVar14[0x3c] = 0;
            goto LAB_140021e94;
          }
          if (iVar12 == 0) goto LAB_14002257c;
        }
        if (iVar12 == 0) goto LAB_140021e94;
      }
LAB_14002218e:
      if (-1 < iVar12) goto LAB_140022196;
    }
LAB_14002254b:
    puVar13 = local_a8;
    if (local_a8 == (undefined8 *)0x0) goto LAB_140022196;
  }
  else {
    lVar23 = *param_5;
    puVar13 = (undefined8 *)ExAllocatePool2(0x102,0x10,0x47436644);
    if (puVar13 == (undefined8 *)0x0) {
      return -0x3fffff66;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,puVar13);
    }
    puVar21 = auStack_128;
    *puVar13 = 0;
    puVar13[1] = 0;
    param_4 = (undefined4 *)param_5[3];
    param_5[0xb] = (longlong)puVar13;
    if ((((*(ushort *)param_5[2] < 8) ||
         (psVar2 = *(short **)((ushort *)param_5[2] + 4), *psVar2 != 0x5c)) || (psVar2[1] != 0x3b))
       || (psVar2[3] != 0x3a)) {
      param_5._0_4_ = 0;
      local_c8 = 0;
      local_a8 = puVar13;
      goto LAB_140021d95;
    }
    iVar12 = DfscNetUseIncrementOpenHandleCount(param_3,param_5[5],(longlong)puVar13,*param_5);
    if ((-1 < iVar12) || (iVar12 == -0x3fffffcc)) {
      lVar17 = puVar13[1];
      param_5._0_4_ = 0;
      local_c8 = 0;
      local_a8 = puVar13;
      if (lVar17 != 0) {
        param_5._0_4_ = *(uint *)(lVar17 + 0x94);
        local_c8 = *(undefined8 *)(lVar17 + 0xa8);
      }
      goto LAB_140021d95;
    }
  }
  lVar23 = puVar13[1];
  if (lVar23 != 0) {
    *(undefined8 *)(puVar21 + -8) = 0x140022835;
    DfscNetUseRelease(param_3,lVar23,0,'\x01');
  }
  *(undefined8 *)(puVar21 + -8) = 0x14002256d;
  DfscCmReleaseHandleContext(puVar13);
  plVar9[0xb] = 0;
LAB_140022196:
  if (puVar14 != (undefined4 *)0x0) {
    if (iVar12 < 0) {
      *(undefined8 *)(puVar21 + -8) = 0x140022842;
      DfscCmReleaseContext((longlong)puVar14);
    }
    else {
      *param_7 = puVar14;
    }
  }
  return iVar12;
}



===== DfscInitDfsPath @ 140022850 =====

ulonglong DfscInitDfsPath(wchar_t *param_1,short *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  bool bVar3;
  uint uVar4;
  ulonglong uVar5;
  
  bVar3 = false;
  uVar2 = *(undefined8 *)(param_1 + 4);
  *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)param_1;
  *(undefined8 *)(param_2 + 0x2c) = uVar2;
  uVar5 = DfscGetPathComponents
                    ((ushort *)(param_2 + 0x28),param_2,param_2 + 8,param_2 + 0x18,param_2 + 0x10);
  if (((((int)uVar5 < 0) || (param_2 == (short *)0x0)) || (*param_2 == 0)) ||
     ((*(short **)(param_2 + 4) == (short *)0x0 || (**(short **)(param_2 + 4) == 0)))) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_1bce9a35ce9f35cd7964d25412ee5844_Traceguids,param_1);
    }
    return 0xc000000d;
  }
  if (param_2[0x10] != 0) {
    *(undefined8 *)(param_2 + 0x24) = *(undefined8 *)(param_1 + 4);
    uVar4 = ((ushort)*param_1 >> 1) - 1;
    if ((ushort)param_2[0x18] >> 1 <= uVar4) {
      do {
        lVar1 = (ulonglong)uVar4 * 2;
        if (*(short *)(lVar1 + *(longlong *)(param_1 + 4)) == 0x3a) {
          param_2[0x21] = (short)lVar1;
          bVar3 = true;
          param_2[0x20] = (short)lVar1;
        }
      } while ((*(short *)(lVar1 + *(longlong *)(param_1 + 4)) != 0x5c) &&
              (uVar4 = uVar4 - 1, (ushort)param_2[0x18] >> 1 <= uVar4));
      if (bVar3) {
        return uVar5 & 0xffffffff;
      }
    }
  }
  uVar2 = *(undefined8 *)(param_1 + 4);
  *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)param_1;
  *(undefined8 *)(param_2 + 0x24) = uVar2;
  return uVar5 & 0xffffffff;
}



===== DfscRewritePath @ 140022990 =====

undefined4 DfscRewritePath(longlong param_1,ushort *param_2,ushort *param_3,char param_4)

{
  short *psVar1;
  short *psVar2;
  longlong lVar3;
  bool bVar4;
  void *_Dst;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_R12D;
  undefined8 local_48;
  void *pvStack_40;
  ushort local_38 [8];
  
  local_48 = 0;
  pvStack_40 = (void *)0x0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  if (((param_4 == '\0') || (*(longlong *)(param_1 + 0x110) == 0)) ||
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x110) + 0x10), *(int *)(lVar3 + 0xc) != 1)) {
    uVar6 = (uint)*param_2;
  }
  else {
    DfscGetPathComponents
              ((ushort *)(lVar3 + 0x90),(short *)0x0,(short *)local_38,(short *)0x0,(short *)0x0);
    DfscGetPathComponents(param_2,(short *)&local_48,(short *)0x0,(short *)0x0,(short *)0x0);
    uVar6 = (ushort)(wchar_t)local_48 + 4;
  }
  if (*param_3 == 0) {
    uVar7 = 0;
  }
  else if (**(short **)(param_3 + 4) == 0x5c) {
    uVar7 = 0;
  }
  else if (local_38[0] == 0) {
    uVar7 = (uint)(*(short *)(*(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar6 >> 1) * 2) != 0x5c
                  );
  }
  else {
    uVar7 = 1;
  }
  uVar8 = uVar6 + *param_3 + (uVar7 + 1) * 2 + (uint)local_38[0];
  if (0xffff < uVar8) {
    return unaff_R12D;
  }
  _Dst = (void *)ExAllocatePool2(0x102,uVar8,0x6b436644);
  if (_Dst == (void *)0x0) {
    return unaff_R12D;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_a8b72ae5a54533de05be1b18d60e4877_Traceguids,param_1,(char)_Dst);
  }
  local_48._0_4_ = CONCAT22((short)uVar8,(short)uVar6);
  pvStack_40 = _Dst;
  memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)uVar6);
  if (local_38[0] != 0) {
    RtlAppendUnicodeStringToString(&local_48,local_38);
  }
  if (*param_3 != 0) {
    if ((char)uVar7 != '\0') {
      RtlAppendUnicodeToString(&local_48,L"\\");
    }
    RtlAppendUnicodeStringToString(&local_48,param_3);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_a8b72ae5a54533de05be1b18d60e4877_Traceguids,param_1,(wchar_t *)&local_48);
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0);
  }
  psVar1 = (short *)(param_1 + 0x10);
  psVar1[0] = 0;
  psVar1[1] = 0;
  psVar1[2] = 0;
  psVar1[3] = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  psVar2 = (short *)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  bVar4 = false;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  psVar2[0] = 0;
  psVar2[1] = 0;
  psVar2[2] = 0;
  psVar2[3] = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined2 *)(param_1 + 0xe2) = 0;
  *(undefined8 *)(param_1 + 0x60) = local_48;
  *(void **)(param_1 + 0x68) = pvStack_40;
  uVar5 = DfscGetPathComponents
                    ((ushort *)(param_1 + 0x60),psVar1,(short *)(param_1 + 0x20),
                     (short *)(param_1 + 0x40),(short *)(param_1 + 0x30));
  if (((((int)uVar5 < 0) || (psVar1 == (short *)0x0)) || (*psVar1 == 0)) ||
     ((*(short **)(param_1 + 0x18) == (short *)0x0 || (**(short **)(param_1 + 0x18) == 0)))) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_1bce9a35ce9f35cd7964d25412ee5844_Traceguids,(wchar_t *)&local_48);
    }
  }
  else {
    if (*(short *)(param_1 + 0x30) != 0) {
      uVar6 = ((ushort)(wchar_t)local_48 >> 1) - 1;
      uVar7 = (uint)(*(ushort *)(param_1 + 0x40) >> 1);
      *(void **)(param_1 + 0x58) = pvStack_40;
      if (uVar7 <= uVar6) {
        do {
          lVar3 = (ulonglong)uVar6 * 2;
          if (*(short *)(lVar3 + (longlong)pvStack_40) == 0x3a) {
            *(short *)(param_1 + 0x52) = (short)lVar3;
            bVar4 = true;
            *(short *)(param_1 + 0x50) = (short)lVar3;
          }
        } while ((*(short *)(lVar3 + (longlong)pvStack_40) != 0x5c) &&
                (uVar6 = uVar6 - 1, uVar7 <= uVar6));
        if (bVar4) goto LAB_140022bb3;
      }
    }
    *(undefined8 *)(param_1 + 0x50) = local_48;
    *(void **)(param_1 + 0x58) = pvStack_40;
  }
LAB_140022bb3:
  bVar4 = false;
  *(undefined8 *)(param_1 + 0xc0) = local_48;
  *(void **)(param_1 + 200) = pvStack_40;
  uVar5 = DfscGetPathComponents
                    ((ushort *)(param_1 + 0xc0),psVar2,(short *)(param_1 + 0x80),
                     (short *)(param_1 + 0xa0),(short *)(param_1 + 0x90));
  if (((((int)uVar5 < 0) || (psVar2 == (short *)0x0)) || (*psVar2 == 0)) ||
     ((*(short **)(param_1 + 0x78) == (short *)0x0 || (**(short **)(param_1 + 0x78) == 0)))) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_1bce9a35ce9f35cd7964d25412ee5844_Traceguids,(wchar_t *)&local_48);
    }
  }
  else {
    if (*(short *)(param_1 + 0x90) != 0) {
      uVar6 = ((ushort)(wchar_t)local_48 >> 1) - 1;
      uVar7 = (uint)(*(ushort *)(param_1 + 0xa0) >> 1);
      *(void **)(param_1 + 0xb8) = pvStack_40;
      if (uVar7 <= uVar6) {
        do {
          lVar3 = (ulonglong)uVar6 * 2;
          if (*(short *)(lVar3 + (longlong)pvStack_40) == 0x3a) {
            *(short *)(param_1 + 0xb2) = (short)lVar3;
            bVar4 = true;
            *(short *)(param_1 + 0xb0) = (short)lVar3;
          }
        } while ((*(short *)(lVar3 + (longlong)pvStack_40) != 0x5c) &&
                (uVar6 = uVar6 - 1, uVar7 <= uVar6));
        if (bVar4) {
          return unaff_R12D;
        }
      }
    }
    *(undefined8 *)(param_1 + 0xb0) = local_48;
    *(void **)(param_1 + 0xb8) = pvStack_40;
  }
  return unaff_R12D;
}



===== DfscGetPathComponents @ 140022e70 =====

undefined8
DfscGetPathComponents(ushort *param_1,short *param_2,short *param_3,short *param_4,short *param_5)

{
  short *psVar1;
  longlong lVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  undefined8 uVar7;
  ushort uVar8;
  ulonglong uVar9;
  ushort uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  uVar7 = 0;
  bVar11 = param_2 != (short *)0x0;
  bVar12 = param_3 != (short *)0x0;
  psVar1 = *(short **)(param_1 + 4);
  bVar13 = param_4 != (short *)0x0;
  bVar14 = param_5 != (short *)0x0;
  if ((psVar1 != (short *)0x0) && (uVar5 = *param_1, uVar5 != 0)) {
    uVar6 = 0;
    if ((1 < uVar5) && (*psVar1 == 0x5c)) {
      uVar6 = 1;
    }
    if ((uVar5 < 4) || (psVar1[uVar6] != 0x5c)) {
      uVar3 = uVar6;
      if (uVar6 < uVar5 >> 1) {
        do {
          if (psVar1[uVar3] == 0x5c) break;
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar5 >> 1);
        if (uVar3 != uVar6) {
          if (param_2 != (short *)0x0) {
            *(short **)(param_2 + 4) = psVar1 + uVar6;
            sVar4 = (uVar3 - uVar6) * 2;
            *param_2 = sVar4;
            param_2[1] = sVar4;
          }
          bVar11 = false;
          uVar3 = uVar3 + 1;
          uVar9 = (ulonglong)uVar3;
          uVar5 = 0;
          while( true ) {
            uVar8 = (ushort)uVar9;
            uVar10 = 0;
            if (*param_1 >> 1 <= uVar8) break;
            sVar4 = *(short *)(*(longlong *)(param_1 + 4) + uVar9 * 2);
            if (sVar4 == 0x3a) {
              if (uVar5 != 0) goto LAB_140022fa5;
              uVar9 = (ulonglong)(ushort)(uVar8 + 1);
              uVar5 = uVar8;
            }
            else {
              if (sVar4 == 0x5c) {
                uVar10 = uVar8;
                break;
              }
LAB_140022fa5:
              uVar9 = (ulonglong)(ushort)(uVar8 + 1);
            }
          }
          if (uVar3 < uVar8) {
            if ((uVar10 == 0) && (uVar10 = uVar8, uVar5 != 0)) {
              uVar10 = uVar5;
            }
            if (param_3 != (short *)0x0) {
              *(ulonglong *)(param_3 + 4) = *(longlong *)(param_1 + 4) + (ulonglong)uVar3 * 2;
              sVar4 = (uVar10 - uVar3) * 2;
              *param_3 = sVar4;
              param_3[1] = sVar4;
            }
            bVar12 = false;
            if (param_4 != (short *)0x0) {
              lVar2 = *(longlong *)(param_2 + 4);
              bVar13 = false;
              *(longlong *)(param_4 + 4) = lVar2;
              sVar4 = *param_2;
              *param_4 = sVar4;
              if (uVar6 != 0) {
                sVar4 = sVar4 + 2;
                *(longlong *)(param_4 + 4) = lVar2 + -2;
                *param_4 = sVar4;
              }
              if (*param_3 != 0) {
                *param_4 = sVar4 + 2;
                sVar4 = sVar4 + 2 + *param_3;
                *param_4 = sVar4;
              }
              param_4[1] = sVar4;
            }
            uVar5 = *param_1 >> 1;
            if ((uVar10 < uVar5) &&
               (*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar10 * 2) == 0x5c)) {
              uVar10 = uVar10 + 1;
            }
            if ((param_5 != (short *)0x0) && (uVar10 < uVar5)) {
              lVar2 = *(longlong *)(param_1 + 4);
              sVar4 = (uVar5 - uVar10) * 2;
              bVar14 = false;
              *param_5 = sVar4;
              param_5[1] = sVar4;
              *(ulonglong *)(param_5 + 4) = lVar2 + (ulonglong)uVar10 * 2;
            }
          }
          goto LAB_14002309b;
        }
      }
      uVar7 = 0xc000000d;
    }
    else {
      uVar7 = 0xc000000d;
    }
  }
LAB_14002309b:
  if (bVar11) {
    RtlInitUnicodeString(param_2,0);
  }
  if (bVar12) {
    RtlInitUnicodeString(param_3,0);
  }
  if (bVar13) {
    RtlInitUnicodeString(param_4,0);
  }
  if (bVar14) {
    RtlInitUnicodeString(param_5,0);
  }
  return uVar7;
}



===== DfscNetUseRelease @ 1400231b0 =====

ulonglong DfscNetUseRelease(longlong param_1,longlong param_2,undefined8 param_3,char param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  undefined8 uVar8;
  char cVar9;
  longlong lVar10;
  
  lVar3 = *(longlong *)(param_2 + 0x78);
  uVar4 = 0;
  lVar10 = 0;
  uVar8 = param_3;
  KeEnterCriticalRegion();
  puVar6 = &DAT_14000d6e0;
  if (param_1 == 0) {
    puVar5 = &DAT_14000d6e0;
  }
  else {
    puVar5 = (undefined *)(param_1 + 0x98);
  }
  ExAcquireResourceExclusiveLite(puVar5,1);
  LOCK();
  piVar1 = (int *)(param_2 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  iVar7 = iVar2 + -1;
  if (param_4 == '\x01') {
    *(int *)(param_2 + 0x90) = *(int *)(param_2 + 0x90) + -1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,uVar8,param_2,(char)iVar7,
               (char)*(undefined4 *)(param_2 + 0x90));
  }
  cVar9 = (char)param_3;
  if ((iVar7 == 0) || (cVar9 == '\x01')) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,uVar8,param_2,(char)iVar7,cVar9);
    }
    if ((lVar3 != 0) && (*(longlong *)(param_2 + 0x78) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,param_2);
      }
      DfscNetUseTableDelete(*(undefined8 *)(param_2 + 0x78),param_2);
    }
    if (cVar9 != '\0') {
      if (*(longlong *)(param_2 + 0x70) != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                    &WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,*(longlong *)(param_2 + 0x70),
                    (char)param_2);
        }
        uVar4 = DfscCredRelease(*(longlong *)(param_2 + 0x70));
        uVar4 = uVar4 & 0xffffffff;
        *(undefined8 *)(param_2 + 0x70) = 0;
      }
      lVar10 = *(longlong *)(param_2 + 0x88);
      *(undefined8 *)(param_2 + 0x88) = 0;
    }
    if (param_1 != 0) {
      puVar6 = (undefined *)(param_1 + 0x98);
    }
    ExReleaseResourceLite(puVar6);
    KeLeaveCriticalRegion();
    if (lVar10 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,lVar10,(char)param_2);
      }
      ZwClose(lVar10);
    }
    if (iVar7 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)iVar2 + 0x11,
                 &WPP_87cf2b6004dc3e7f3eb3e63342a64277_Traceguids,param_2);
      }
      ExFreePoolWithTag(param_2,0);
    }
  }
  else {
    if (param_1 != 0) {
      puVar6 = (undefined *)(param_1 + 0x98);
    }
    ExReleaseResourceLite(puVar6);
    KeLeaveCriticalRegion();
  }
  return uVar4;
}



===== DfscGetCacheReferral @ 140023470 =====

ulonglong DfscGetCacheReferral(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  short sVar4;
  wchar_t wVar5;
  wchar_t wVar6;
  code *pcVar7;
  bool bVar8;
  ushort uVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  longlong lVar15;
  undefined *puVar16;
  ushort uVar17;
  longlong *plVar18;
  uint uVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  short *psVar22;
  ulonglong uVar23;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [56];
  ushort local_98;
  undefined2 uStack_96;
  undefined4 uStack_94;
  longlong lStack_90;
  undefined8 local_88;
  longlong lStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined *puStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined *puStack_40;
  
  puVar21 = auStack_d8;
  *param_3 = 0;
  local_88 = 0;
  lStack_80 = 0;
  for (uVar19 = 0; uVar19 < 4; uVar19 = uVar19 + 1) {
    uVar23 = (ulonglong)uVar19;
    uVar12 = (ulonglong)(*(ushort *)(param_1 + 0xf) >> 1);
    local_68 = 0;
    puStack_60 = (undefined *)0x0;
    local_78 = 0;
    uStack_70 = 0;
    uVar17 = (ushort)(&DAT_14000d080)[uVar23 * 8] >> 1;
    if (uVar17 != 0) {
      do {
        if ((*(short *)((&PTR_u_PIPE_14000d088)[uVar23 * 2] + (ulonglong)uVar17 * 2 + -2) != 0x5c)
           && (*(short *)((&PTR_u_PIPE_14000d088)[uVar23 * 2] + (ulonglong)uVar17 * 2 + -2) != 0))
        break;
        uVar17 = uVar17 - 1;
      } while (uVar17 != 0);
    }
    if (*(ushort *)(param_1 + 0xf) >> 1 == 0) {
LAB_140023597:
      if (uVar17 == 0) goto LAB_1400235bc;
    }
    else {
      do {
        sVar4 = *(short *)(param_1[0x10] + -2 + uVar12 * 2);
        if ((sVar4 != 0x5c) && (sVar4 != 0)) break;
        uVar9 = (short)uVar12 - 1;
        uVar12 = (ulonglong)uVar9;
      } while (uVar9 != 0);
      uVar9 = (ushort)uVar12;
      if (uVar9 == 0) goto LAB_140023597;
      if ((uVar9 == uVar17) && (uVar17 != 0)) {
        puStack_60 = (&PTR_u_PIPE_14000d088)[uVar23 * 2];
        local_68 = CONCAT62((int6)((ulonglong)*(undefined8 *)(&DAT_14000d080 + uVar23 * 8) >> 0x10),
                            uVar17 * 2);
        uStack_70 = param_1[0x10];
        local_78 = CONCAT62((int6)((ulonglong)param_1[0xf] >> 0x10),uVar9 * 2);
        iVar10 = RtlCompareUnicodeString(&local_68,&local_78);
        if (iVar10 == 0) goto LAB_1400235bc;
      }
    }
  }
  for (uVar19 = 0; uVar19 < 3; uVar19 = uVar19 + 1) {
    uVar12 = (ulonglong)uVar19;
    uVar17 = *(ushort *)(param_1 + 0xd) >> 1;
    local_48 = 0;
    puStack_40 = (undefined *)0x0;
    local_58 = 0;
    uStack_50 = 0;
    uVar9 = *(ushort *)(&DAT_14000d048 + uVar12 * 2) >> 1;
    if (uVar9 != 0) {
      do {
        if ((*(short *)((&PTR_u_TSCLIENT_14000d050)[uVar12 * 2] + (ulonglong)uVar9 * 2 + -2) != 0x5c
            ) && (*(short *)((&PTR_u_TSCLIENT_14000d050)[uVar12 * 2] + (ulonglong)uVar9 * 2 + -2) !=
                  0)) break;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    if (uVar17 == 0) {
LAB_1400236c3:
      if (uVar9 == 0) goto LAB_1400235bc;
    }
    else {
      do {
        sVar4 = *(short *)(param_1[0xe] + -2 + (ulonglong)uVar17 * 2);
        if ((sVar4 != 0x5c) && (sVar4 != 0)) break;
        uVar17 = uVar17 - 1;
      } while (uVar17 != 0);
      if (uVar17 == 0) goto LAB_1400236c3;
      if ((uVar17 == uVar9) && (uVar9 != 0)) {
        puStack_40 = (&PTR_u_TSCLIENT_14000d050)[uVar12 * 2];
        local_48 = CONCAT62((int6)((ulonglong)(&DAT_14000d048)[uVar12 * 2] >> 0x10),uVar9 * 2);
        uStack_50 = param_1[0xe];
        local_58 = CONCAT62((int6)((ulonglong)param_1[0xd] >> 0x10),uVar17 * 2);
        iVar10 = RtlCompareUnicodeString(&local_48,&local_58);
        if (iVar10 == 0) goto LAB_1400235bc;
      }
    }
  }
  iVar10 = MupSurrogateCheckNegativeCache(*param_1,param_1 + 0x17);
  if (iVar10 == 0) {
LAB_1400235bc:
    *param_3 = 1;
    return 0;
  }
  puVar3 = param_1 + 0x19;
  if (param_1[0x1e] == 0) {
    puVar13 = DAT_14000d6d0;
  }
  else {
    puVar13 = *(undefined4 **)(param_1[0x1e] + 0x88);
  }
  lStack_90 = param_1[10];
  uStack_96 = *(undefined2 *)((longlong)param_1 + 0x4a);
  uStack_94 = 0;
  local_98 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(puVar13 + 0xe,1);
  lVar11 = RtlFindUnicodePrefix(puVar13,param_1 + 9,0);
  if ((lVar11 == 0) || ((*(byte *)(lVar11 + -0x38) & 1) == 0)) {
    ExReleaseResourceLite(puVar13 + 0xe);
    KeLeaveCriticalRegion();
LAB_14002377a:
    uVar12 = DfscDomainCacheLookup((longlong)param_1,(ushort *)(param_1 + 1),param_2);
    uVar23 = uVar12 & 0xffffffff;
    if (-1 < (int)uVar12) {
      *param_3 = 2;
      RtlInitUnicodeString(puVar3,0);
    }
  }
  else {
    uVar17 = *(ushort *)(lVar11 + 0x48);
    uVar23 = (ulonglong)uVar17;
    uVar9 = *(ushort *)(param_1 + 9);
    uVar12 = (ulonglong)uVar9;
    if (uVar17 < uVar9) {
      local_98 = uVar9 - uVar17;
      uVar12 = (ulonglong)local_98;
      lVar15 = param_1[10] + (ulonglong)(uVar17 >> 1) * 2;
LAB_1400237e3:
      lStack_90 = lVar15;
    }
    else if ((uVar17 == uVar9) &&
            (lVar15 = param_1[10] + -2 + (ulonglong)(uVar9 >> 1) * 2,
            *(short *)(param_1[10] + -2 + (ulonglong)(uVar9 >> 1) * 2) == 0x5c)) {
      local_98 = 2;
      goto LAB_1400237e3;
    }
    LOCK();
    *(int *)(lVar11 + -0x44) = *(int *)(lVar11 + -0x44) + 1;
    UNLOCK();
    ExReleaseResourceLite(puVar13 + 0xe);
    KeLeaveCriticalRegion();
    KeEnterCriticalRegion();
    plVar18 = (longlong *)CONCAT71((int7)(uVar12 >> 8),1);
    ExAcquireResourceExclusiveLite(puVar13 + 0x28);
    if (puVar13 == *(undefined4 **)(lVar11 + -8)) {
      lVar15 = *(longlong *)(lVar11 + -0x18);
      puVar1 = (undefined8 *)(lVar11 + -0x18);
      if (lVar15 == 0) {
LAB_140023860:
        if ((*(byte *)(lVar11 + -0x38) & 1) != 0) {
          plVar18 = *(longlong **)(puVar13 + 6);
          puVar2 = (undefined8 *)(puVar13 + 6);
          if ((undefined8 *)plVar18[1] != puVar2) goto LAB_140023b40;
          *puVar1 = plVar18;
          *(undefined8 **)(lVar11 + -0x10) = puVar2;
          plVar18[1] = (longlong)puVar1;
          *puVar2 = puVar1;
        }
        goto LAB_140023886;
      }
      if ((*(undefined8 **)(lVar15 + 8) == puVar1) &&
         (plVar18 = *(longlong **)(lVar11 + -0x10), (undefined8 *)*plVar18 == puVar1)) {
        *plVar18 = lVar15;
        *(longlong **)(lVar15 + 8) = plVar18;
        *puVar1 = 0;
        goto LAB_140023860;
      }
LAB_140023b40:
      puVar16 = (undefined *)0x3;
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)();
      puVar21 = auStack_d0;
LAB_140023b47:
      uVar14 = *(undefined8 *)(puVar16 + 0x18);
      *(longlong *)(puVar21 + 0x30) = lVar11 + 0x48;
      *(undefined4 *)(puVar21 + 0x28) = puVar13[2];
      *(undefined8 *)(puVar21 + 0x20) = *(undefined8 *)(puVar13 + 4);
      *(undefined8 *)(puVar21 + -8) = 0x140023b6f;
      WPP_SF_qqDZ(uVar14,plVar18,uVar23,puVar13,puVar21[0x20],puVar21[0x28],
                  *(wchar_t **)(puVar21 + 0x30));
      puVar20 = puVar21;
    }
    else {
LAB_140023886:
      ExReleaseResourceLite(puVar13 + 0x28);
      KeLeaveCriticalRegion();
      plVar18 = (longlong *)0x28;
      uVar23 = 0x62436644;
      puVar13 = (undefined4 *)ExAllocatePool2(0x102);
      if (puVar13 == (undefined4 *)0x0) {
        DfscRmDereferenceReferral(lVar11 + -0x48);
        goto LAB_14002377a;
      }
      *(undefined8 *)(puVar13 + 2) = 0;
      *(undefined8 *)(puVar13 + 6) = 0;
      *(undefined8 *)(puVar13 + 8) = 0;
      *puVar13 = 0x288103;
      puVar13[1] = 1;
      *(longlong *)(puVar13 + 4) = lVar11 + -0x48;
      DfscRmIsTimeToRefresh((longlong)puVar13);
      puVar20 = auStack_d8;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar16 = WPP_GLOBAL_Control, puVar20 = auStack_d8,
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) goto LAB_140023b47;
    }
    if ((*(int *)(lVar11 + -0x3c) == 0) && (*(short *)(lVar11 + -0x2c) == 0)) {
      puVar13[2] = puVar13[2] | 2;
    }
    *(undefined2 *)(puVar13 + 8) = 0xffff;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = CONCAT44(uStack_94,CONCAT22(uStack_96,local_98));
      param_1[0x1a] = lStack_90;
    }
    *param_2 = puVar13;
    wVar5 = *(wchar_t *)(param_1 + 0xb);
    wVar6 = *(wchar_t *)(param_1 + 9);
    *param_3 = 2;
    if ((ushort)wVar6 < (ushort)wVar5) {
      if (*(short *)(param_1 + 0x19) == 0) {
        param_1[0x1a] = (ulonglong)(ushort)wVar6 + param_1[10];
      }
      *(wchar_t *)(param_1 + 0x19) = (wVar5 - wVar6) + *(short *)(param_1 + 0x19);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 **)(puVar20 + 0x20) = puVar3;
        *(undefined8 *)(puVar20 + -8) = 0x140023bfa;
        WPP_SF_ZZ(uVar14,0xb,&WPP_55706db06074317498eaf8c01331c814_Traceguids,
                  (wchar_t *)(param_1 + 0xb),*(wchar_t **)(puVar20 + 0x20));
      }
    }
    uVar17 = *(ushort *)(param_1 + 0x1b);
    uVar9 = *(ushort *)(param_1 + 0x19);
    if (uVar9 < uVar17) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(uint *)(puVar20 + 0x20) = (uint)uVar9;
        *(undefined8 *)(puVar20 + -8) = 0x140023c25;
        WPP_SF_LL(uVar14,0xc,&WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar17,
                  puVar20[0x20]);
      }
      *(undefined2 *)(param_1 + 0x1b) = *(undefined2 *)(param_1 + 0x19);
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(uint *)(puVar20 + 0x20) = (uint)uVar9;
      *(undefined8 *)(puVar20 + -8) = 0x140023af4;
      WPP_SF_LL(uVar14,0xd,&WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar17,
                puVar20[0x20]);
    }
    bVar8 = false;
    lStack_80 = param_1[0xc];
    psVar22 = (short *)(param_1 + 0xd);
    local_88._0_4_ =
         CONCAT22(*(short *)((longlong)param_1 + 0x5a) - *(short *)(param_1 + 0x19),
                  *(short *)(param_1 + 0xb) - *(short *)(param_1 + 0x19));
    *(undefined8 **)(puVar20 + 0x20) = param_1 + 0x11;
    param_1[0x17] = local_88;
    param_1[0x18] = lStack_80;
    *(undefined8 *)(puVar20 + -8) = 0x1400239f1;
    uVar14 = DfscGetPathComponents
                       ((ushort *)(param_1 + 0x17),psVar22,(short *)(param_1 + 0xf),
                        (short *)(param_1 + 0x13),*(short **)(puVar20 + 0x20));
    if (((((int)uVar14 < 0) || (psVar22 == (short *)0x0)) || (*psVar22 == 0)) ||
       (((short *)param_1[0xe] == (short *)0x0 || (*(short *)param_1[0xe] == 0)))) {
      uVar23 = 0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar20 + -8) = 0x140023c67;
        WPP_SF_Z(uVar14,10,&WPP_1bce9a35ce9f35cd7964d25412ee5844_Traceguids,(wchar_t *)&local_88);
      }
    }
    else {
      uVar23 = 0;
      if (*(short *)(param_1 + 0x11) != 0) {
        uVar19 = ((ushort)(wchar_t)local_88 >> 1) - 1;
        param_1[0x16] = lStack_80;
        if (*(ushort *)(param_1 + 0x13) >> 1 <= uVar19) {
          do {
            lVar11 = (ulonglong)uVar19 * 2;
            if (*(short *)(lVar11 + lStack_80) == 0x3a) {
              *(short *)((longlong)param_1 + 0xaa) = (short)lVar11;
              bVar8 = true;
              *(short *)(param_1 + 0x15) = (short)lVar11;
            }
          } while ((*(short *)(lVar11 + lStack_80) != 0x5c) &&
                  (uVar19 = uVar19 - 1, *(ushort *)(param_1 + 0x13) >> 1 <= uVar19));
          if (bVar8) {
            return 0;
          }
        }
      }
      param_1[0x15] = local_88;
      param_1[0x16] = lStack_80;
    }
  }
  return uVar23;
}



===== DfscCmInitState @ 140023c80 =====

undefined8 DfscCmInitState(longlong param_1)

{
  short *psVar1;
  undefined8 *puVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  short sVar5;
  short sVar6;
  longlong *plVar7;
  code *pcVar8;
  bool bVar9;
  ushort uVar10;
  int iVar11;
  longlong lVar12;
  undefined4 *puVar13;
  longlong lVar14;
  undefined8 uVar15;
  longlong lVar16;
  undefined *puVar17;
  ushort uVar18;
  undefined2 uVar19;
  uint uVar20;
  ulonglong *puVar21;
  uint uVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  ulonglong uVar25;
  short sVar26;
  int unaff_R12D;
  int iVar27;
  undefined8 uVar28;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [56];
  short local_88;
  undefined2 uStack_86;
  undefined4 uStack_84;
  longlong lStack_80;
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined *puStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined *puStack_30;
  
  puVar24 = auStack_c8;
  puVar23 = auStack_c8;
  if (0x10 < *(ushort *)(param_1 + 0x122)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
    }
    iVar11 = -0x3fffff42;
    uVar28 = 9;
    goto LAB_140023e24;
  }
  if (*(short *)(param_1 + 0x20) == 0) {
    uVar28 = 9;
    *(undefined4 *)(param_1 + 0x144) = 2;
    iVar11 = -0x3fffffff;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
    }
    goto LAB_140023e24;
  }
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  local_78 = 0;
  lStack_70 = 0;
  for (uVar22 = 0; uVar22 < 4; uVar22 = uVar22 + 1) {
    uVar25 = (ulonglong)uVar22;
    uVar10 = *(ushort *)(param_1 + 0x80) >> 1;
    local_58 = 0;
    puStack_50 = (undefined *)0x0;
    local_68 = 0;
    uStack_60 = 0;
    uVar18 = (ushort)(&DAT_14000d080)[uVar25 * 8] >> 1;
    if (uVar18 != 0) {
      do {
        if ((*(short *)((&PTR_u_PIPE_14000d088)[uVar25 * 2] + (ulonglong)uVar18 * 2 + -2) != 0x5c)
           && (*(short *)((&PTR_u_PIPE_14000d088)[uVar25 * 2] + (ulonglong)uVar18 * 2 + -2) != 0))
        break;
        uVar18 = uVar18 - 1;
      } while (uVar18 != 0);
    }
    if (uVar10 == 0) {
LAB_140023dd1:
      if (uVar18 == 0) goto LAB_140023dd6;
    }
    else {
      do {
        sVar26 = *(short *)(*(longlong *)(param_1 + 0x88) + -2 + (ulonglong)uVar10 * 2);
        if ((sVar26 != 0x5c) && (sVar26 != 0)) break;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
      if (uVar10 == 0) goto LAB_140023dd1;
      if ((uVar10 == uVar18) && (uVar18 != 0)) {
        puStack_50 = (&PTR_u_PIPE_14000d088)[uVar25 * 2];
        local_58 = CONCAT62((int6)((ulonglong)*(undefined8 *)(&DAT_14000d080 + uVar25 * 8) >> 0x10),
                            uVar18 * 2);
        uStack_60 = *(undefined8 *)(param_1 + 0x88);
        local_68 = CONCAT62((int6)((ulonglong)*(undefined8 *)(param_1 + 0x80) >> 0x10),uVar10 * 2);
        iVar11 = RtlCompareUnicodeString(&local_58,&local_68);
        if (iVar11 == 0) goto LAB_140023dd6;
      }
    }
  }
  for (uVar22 = 0; uVar22 < 3; uVar22 = uVar22 + 1) {
    uVar25 = (ulonglong)uVar22;
    uVar10 = *(ushort *)(param_1 + 0x70) >> 1;
    local_38 = 0;
    puStack_30 = (undefined *)0x0;
    local_48 = 0;
    uStack_40 = 0;
    uVar18 = *(ushort *)(&DAT_14000d048 + uVar25 * 2) >> 1;
    if (uVar18 != 0) {
      do {
        if ((*(short *)((&PTR_u_TSCLIENT_14000d050)[uVar25 * 2] + (ulonglong)uVar18 * 2 + -2) !=
             0x5c) &&
           (*(short *)((&PTR_u_TSCLIENT_14000d050)[uVar25 * 2] + (ulonglong)uVar18 * 2 + -2) != 0))
        break;
        uVar18 = uVar18 - 1;
      } while (uVar18 != 0);
    }
    if (uVar10 == 0) {
LAB_140024048:
      if (uVar18 == 0) goto LAB_140023dd6;
    }
    else {
      do {
        sVar26 = *(short *)(*(longlong *)(param_1 + 0x78) + -2 + (ulonglong)uVar10 * 2);
        if ((sVar26 != 0x5c) && (sVar26 != 0)) break;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
      if (uVar10 == 0) goto LAB_140024048;
      if ((uVar10 == uVar18) && (uVar18 != 0)) {
        puStack_30 = (&PTR_u_TSCLIENT_14000d050)[uVar25 * 2];
        local_38 = CONCAT62((int6)((ulonglong)(&DAT_14000d048)[uVar25 * 2] >> 0x10),uVar18 * 2);
        uStack_40 = *(undefined8 *)(param_1 + 0x78);
        local_48 = CONCAT62((int6)((ulonglong)*(undefined8 *)(param_1 + 0x70) >> 0x10),uVar10 * 2);
        iVar11 = RtlCompareUnicodeString(&local_38,&local_48);
        if (iVar11 == 0) goto LAB_140023dd6;
      }
    }
  }
  iVar11 = MupSurrogateCheckNegativeCache(*(undefined8 *)(param_1 + 8),param_1 + 0xc0);
  if (iVar11 == 0) {
LAB_140023dd6:
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
    }
    *(undefined4 *)(param_1 + 0x144) = 2;
    iVar11 = -0x3fffffff;
    uVar28 = 9;
    goto LAB_140023e24;
  }
  if (*(longlong *)(param_1 + 0xf8) == 0) {
    puVar13 = DAT_14000d6d0;
  }
  else {
    puVar13 = *(undefined4 **)(*(longlong *)(param_1 + 0xf8) + 0x88);
  }
  lStack_80 = *(longlong *)(param_1 + 0x58);
  uStack_86 = *(undefined2 *)(param_1 + 0x52);
  uStack_84 = 0;
  local_88 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(puVar13 + 0xe,1);
  lVar12 = RtlFindUnicodePrefix(puVar13,param_1 + 0x50,0);
  if ((lVar12 == 0) || ((*(byte *)(lVar12 + -0x38) & 1) == 0)) {
    ExReleaseResourceLite(puVar13 + 0xe);
    KeLeaveCriticalRegion();
LAB_140023ff9:
    iVar27 = 2;
    uVar28 = DfscDomainCacheLookup
                       (param_1 + 8,(ushort *)(param_1 + 0x10),(undefined8 *)(param_1 + 0x110));
    iVar11 = (int)uVar28;
    if (iVar11 < 0) {
      iVar27 = 0;
      puVar23 = auStack_c8;
    }
    else {
      RtlInitUnicodeString(param_1 + 0xd0,0);
    }
  }
  else {
    uVar10 = *(ushort *)(lVar12 + 0x48);
    uVar25 = (ulonglong)uVar10;
    uVar18 = *(ushort *)(param_1 + 0x50);
    if (uVar10 < uVar18) {
      local_88 = uVar18 - uVar10;
      lVar16 = *(longlong *)(param_1 + 0x58) + (ulonglong)(uVar10 >> 1) * 2;
LAB_1400240af:
      lStack_80 = lVar16;
    }
    else if ((uVar10 == uVar18) &&
            (lVar14 = *(longlong *)(param_1 + 0x58) + -2,
            lVar16 = lVar14 + (ulonglong)(uVar18 >> 1) * 2,
            *(short *)(lVar14 + (ulonglong)(uVar18 >> 1) * 2) == 0x5c)) {
      local_88 = 2;
      goto LAB_1400240af;
    }
    LOCK();
    *(int *)(lVar12 + -0x44) = *(int *)(lVar12 + -0x44) + 1;
    UNLOCK();
    ExReleaseResourceLite(puVar13 + 0xe);
    KeLeaveCriticalRegion();
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(puVar13 + 0x28,1);
    if (puVar13 == *(undefined4 **)(lVar12 + -8)) {
      lVar16 = *(longlong *)(lVar12 + -0x18);
      puVar21 = (ulonglong *)(lVar12 + -0x18);
      if (lVar16 == 0) {
LAB_14002412c:
        if ((*(byte *)(lVar12 + -0x38) & 1) != 0) {
          uVar25 = *(ulonglong *)(puVar13 + 6);
          puVar2 = (undefined8 *)(puVar13 + 6);
          if (*(undefined8 **)(uVar25 + 8) != puVar2) goto LAB_1400245af;
          *puVar21 = uVar25;
          *(undefined8 **)(lVar12 + -0x10) = puVar2;
          *(ulonglong **)(uVar25 + 8) = puVar21;
          *puVar2 = puVar21;
        }
        goto LAB_140024152;
      }
      if ((*(ulonglong **)(lVar16 + 8) == puVar21) &&
         (plVar7 = *(longlong **)(lVar12 + -0x10), (ulonglong *)*plVar7 == puVar21)) {
        *plVar7 = lVar16;
        *(longlong **)(lVar16 + 8) = plVar7;
        *puVar21 = 0;
        goto LAB_14002412c;
      }
LAB_1400245af:
      puVar17 = (undefined *)0x3;
      pcVar8 = (code *)swi(0x29);
      (*pcVar8)();
      puVar24 = auStack_c0;
LAB_1400245b6:
      iVar11 = unaff_R12D;
      uVar28 = *(undefined8 *)(puVar17 + 0x18);
      *(longlong *)(puVar24 + 0x30) = lVar12 + 0x48;
      *(undefined4 *)(puVar24 + 0x28) = puVar13[2];
      *(undefined8 *)(puVar24 + 0x20) = *(undefined8 *)(puVar13 + 4);
      *(undefined8 *)(puVar24 + -8) = 0x1400245df;
      WPP_SF_qqDZ(uVar28,puVar21,uVar25,puVar13,puVar24[0x20],puVar24[0x28],
                  *(wchar_t **)(puVar24 + 0x30));
      puVar23 = puVar24;
    }
    else {
LAB_140024152:
      ExReleaseResourceLite(puVar13 + 0x28);
      KeLeaveCriticalRegion();
      puVar21 = (ulonglong *)0x28;
      uVar25 = 0x62436644;
      puVar13 = (undefined4 *)ExAllocatePool2(0x102);
      if (puVar13 == (undefined4 *)0x0) {
        DfscRmDereferenceReferral(lVar12 + -0x48);
        goto LAB_140023ff9;
      }
      iVar11 = 0;
      *(undefined8 *)(puVar13 + 2) = 0;
      *(undefined8 *)(puVar13 + 6) = 0;
      *(undefined8 *)(puVar13 + 8) = 0;
      *puVar13 = 0x288103;
      puVar13[1] = 1;
      *(longlong *)(puVar13 + 4) = lVar12 + -0x48;
      DfscRmIsTimeToRefresh((longlong)puVar13);
      puVar23 = auStack_c8;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        puVar17 = WPP_GLOBAL_Control;
        puVar23 = auStack_c8;
        unaff_R12D = 0;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0) goto LAB_1400245b6;
      }
    }
    sVar26 = (short)iVar11;
    if ((*(int *)(lVar12 + -0x3c) == iVar11) && (*(short *)(lVar12 + -0x2c) == sVar26)) {
      puVar13[2] = puVar13[2] | 2;
    }
    puVar2 = (undefined8 *)(param_1 + 0xd0);
    *(undefined2 *)(puVar13 + 8) = 0xffff;
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = CONCAT44(uStack_84,CONCAT22(uStack_86,local_88));
      *(longlong *)(param_1 + 0xd8) = lStack_80;
    }
    *(undefined4 **)(param_1 + 0x110) = puVar13;
    wVar3 = *(wchar_t *)(param_1 + 0x60);
    wVar4 = *(wchar_t *)(param_1 + 0x50);
    if ((ushort)wVar4 < (ushort)wVar3) {
      if (*(short *)(param_1 + 0xd0) == 0) {
        *(ulonglong *)(param_1 + 0xd8) = (ulonglong)(ushort)wVar4 + *(longlong *)(param_1 + 0x58);
      }
      *(wchar_t *)(param_1 + 0xd0) = (*(short *)(param_1 + 0xd0) - wVar4) + wVar3;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar28 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 **)(puVar23 + 0x20) = puVar2;
        *(undefined8 *)(puVar23 + -8) = 0x140024665;
        WPP_SF_ZZ(uVar28,0xb,&WPP_55706db06074317498eaf8c01331c814_Traceguids,
                  (wchar_t *)(param_1 + 0x60),*(wchar_t **)(puVar23 + 0x20));
      }
    }
    uVar10 = *(ushort *)(param_1 + 0xe0);
    uVar18 = *(ushort *)(param_1 + 0xd0);
    if (uVar18 < uVar10) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        uVar28 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(uint *)(puVar23 + 0x20) = (uint)uVar18;
        *(undefined8 *)(puVar23 + -8) = 0x140024689;
        WPP_SF_LL(uVar28,0xc,&WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar10,
                  puVar23[0x20]);
      }
      *(undefined2 *)(param_1 + 0xe0) = *(undefined2 *)(param_1 + 0xd0);
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      uVar28 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(uint *)(puVar23 + 0x20) = (uint)uVar18;
      *(undefined8 *)(puVar23 + -8) = 0x1400243ad;
      WPP_SF_LL(uVar28,0xd,&WPP_55706db06074317498eaf8c01331c814_Traceguids,(uint)uVar10,
                puVar23[0x20]);
    }
    sVar5 = *(short *)(param_1 + 0xd0);
    psVar1 = (short *)(param_1 + 0x70);
    lStack_70 = *(longlong *)(param_1 + 0x68);
    sVar6 = *(short *)(param_1 + 0x60);
    *(short **)(puVar23 + 0x20) = (short *)(param_1 + 0x90);
    local_78._0_4_ = CONCAT22(*(short *)(param_1 + 0x62) - sVar5,sVar6 - sVar5);
    *(undefined8 *)(param_1 + 0xc0) = local_78;
    *(longlong *)(param_1 + 200) = lStack_70;
    *(undefined8 *)(puVar23 + -8) = 0x1400242b4;
    uVar28 = DfscGetPathComponents
                       ((ushort *)(param_1 + 0xc0),psVar1,(short *)(param_1 + 0x80),
                        (short *)(param_1 + 0xa0),*(short **)(puVar23 + 0x20));
    iVar27 = 2;
    if (((((int)uVar28 < 0) || (psVar1 == (short *)0x0)) || (*psVar1 == sVar26)) ||
       ((*(short **)(param_1 + 0x78) == (short *)0x0 || (**(short **)(param_1 + 0x78) == sVar26))))
    {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        uVar28 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar23 + -8) = 0x1400246bf;
        WPP_SF_Z(uVar28,10,&WPP_1bce9a35ce9f35cd7964d25412ee5844_Traceguids,(wchar_t *)&local_78);
      }
    }
    else {
      if (*(short *)(param_1 + 0x90) != sVar26) {
        uVar22 = ((ushort)(wchar_t)local_78 >> 1) - 1;
        uVar20 = (uint)(*(ushort *)(param_1 + 0xa0) >> 1);
        *(longlong *)(param_1 + 0xb8) = lStack_70;
        if (uVar20 <= uVar22) {
          bVar9 = false;
          do {
            lVar12 = (ulonglong)uVar22 * 2;
            if (*(short *)(lVar12 + lStack_70) == 0x3a) {
              *(short *)(param_1 + 0xb2) = (short)lVar12;
              bVar9 = true;
              *(short *)(param_1 + 0xb0) = (short)lVar12;
            }
          } while ((*(short *)(lVar12 + lStack_70) != 0x5c) &&
                  (uVar22 = uVar22 - 1, uVar20 <= uVar22));
          if (bVar9) goto LAB_14002401a;
        }
      }
      *(undefined8 *)(param_1 + 0xb0) = local_78;
      *(longlong *)(param_1 + 0xb8) = lStack_70;
    }
  }
LAB_14002401a:
  if (iVar11 == 0) {
    if (iVar27 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        uVar28 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar23 + -8) = 0x140024733;
        WPP_SF_q(uVar28,0x10,&WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
      }
    }
    else {
      if (iVar27 == 2) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
          uVar28 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar23 + 0x20) = *(undefined8 *)(param_1 + 0x110);
          *(undefined8 *)(puVar23 + -8) = 0x1400244d4;
          WPP_SF_qq(uVar28,0xd,&WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,
                    puVar23[0x20]);
        }
        if ((*(longlong *)(param_1 + 0x110) != 0) &&
           (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x110) + 0x10) + 0xc) == 0)) {
          *(undefined8 *)(puVar23 + -8) = 0x1400246eb;
          uVar15 = DfscIsSpecialShare((ushort *)(param_1 + 0x20));
          uVar28 = 4;
          if ((char)uVar15 != '\0') goto LAB_140023e24;
        }
        uVar28 = 1;
        goto LAB_140023e24;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
        uVar19 = 0x11;
        *(int *)(puVar23 + 0x20) = iVar27;
        goto LAB_140024068;
      }
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    uVar19 = 0x12;
    *(int *)(puVar23 + 0x20) = iVar11;
LAB_140024068:
    uVar28 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar23 + -8) = 0x14002407b;
    WPP_SF_qd(uVar28,uVar19,&WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,puVar23[0x20]);
  }
  uVar28 = 3;
LAB_140023e24:
  *(int *)(param_1 + 0x13c) = iVar11;
  return uVar28;
}



===== DfscRmCreateRefContext @ 140024740 =====

undefined8 DfscRmCreateRefContext(longlong param_1,char param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = 0x28;
  uVar3 = 0x62436644;
  puVar1 = (undefined4 *)ExAllocatePool2(0x102);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined8 *)(puVar1 + 2) = 0;
    *(undefined8 *)(puVar1 + 6) = 0;
    *(undefined8 *)(puVar1 + 8) = 0;
    *puVar1 = 0x288103;
    puVar1[1] = 1;
    *(longlong *)(puVar1 + 4) = param_1;
    if (param_2 != '\0') {
      DfscRmIsTimeToRefresh((longlong)puVar1);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qqDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,uVar3,puVar1,
                  (char)*(undefined8 *)(puVar1 + 4),(char)puVar1[2],(wchar_t *)(param_1 + 0x90));
    }
    if ((*(int *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 0x1c) == 0)) {
      puVar1[2] = puVar1[2] | 2;
    }
    *(undefined2 *)(puVar1 + 8) = 0xffff;
    uVar2 = 0;
    *param_3 = puVar1;
  }
  return uVar2;
}



===== DfscRmIsTimeToRefresh @ 140024840 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DfscRmIsTimeToRefresh(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint7 uVar7;
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x28);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20);
  uVar4 = KeQueryTimeIncrement();
  uVar5 = KeQueryTimeIncrement();
  uVar3 = _DAT_fffff78000000320;
  uVar6 = ((ulonglong)(uVar1 * DAT_14000d79c) * 10000000) / (ulonglong)uVar5;
  if ((*(uint *)(param_1 + 8) & 4) == 0) {
    uVar5 = *(uint *)(param_1 + 8);
    if ((longlong)_DAT_fffff78000000320 < (longlong)(lVar2 + uVar6)) {
      uVar6 = uVar3;
      if ((uVar5 & 1) == 0) {
        uVar7 = (uint7)(_DAT_fffff78000000320 >> 8);
        if ((longlong)_DAT_fffff78000000320 <
            (longlong)(lVar2 + ((ulonglong)uVar1 * 10000000) / (ulonglong)uVar4)) {
          return (ulonglong)uVar7 << 8;
        }
        *(uint *)(param_1 + 8) = uVar5 | 1;
        return CONCAT71(uVar7,1);
      }
    }
    else {
      *(uint *)(param_1 + 8) = uVar5 | 5;
      uVar6 = uVar3;
    }
  }
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== DfscRmDereferenceReferral @ 140024910 =====

void DfscRmDereferenceReferral(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                  &WPP_af603b4b97893b05877342047baf7746_Traceguids,param_1,
                  (wchar_t *)(param_1 + 0x90));
      }
      ExFreePoolWithTag(param_1,0);
    }
  }
  return;
}



===== DfscRefCacheLookup @ 140024990 =====

undefined8
DfscRefCacheLookup(longlong param_1,ushort *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ushort uVar3;
  ushort uVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined *puVar10;
  ulonglong uVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  ulonglong uVar15;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [56];
  ushort local_38;
  ushort uStack_36;
  undefined4 uStack_34;
  longlong lStack_30;
  
  if (*(longlong *)(param_1 + 0xf0) == 0) {
    puVar8 = DAT_14000d6d0;
  }
  else {
    puVar8 = *(undefined4 **)(*(longlong *)(param_1 + 0xf0) + 0x88);
  }
  lStack_30 = *(longlong *)(param_2 + 4);
  uStack_36 = param_2[1];
  uStack_34 = 0;
  local_38 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(puVar8 + 0xe,1);
  lVar7 = RtlFindUnicodePrefix(puVar8,param_2,0);
  if ((lVar7 == 0) || ((*(byte *)(lVar7 + -0x38) & 1) == 0)) {
    ExReleaseResourceLite(puVar8 + 0xe);
    KeLeaveCriticalRegion();
    return 0xc000003a;
  }
  uVar3 = *(ushort *)(lVar7 + 0x48);
  uVar15 = (ulonglong)uVar3;
  uVar4 = *param_2;
  uVar11 = (ulonglong)uVar4;
  if (uVar3 < uVar4) {
    local_38 = uVar4 - uVar3;
    uVar11 = (ulonglong)local_38;
    lVar9 = *(longlong *)(param_2 + 4) + (ulonglong)(uVar3 >> 1) * 2;
LAB_140024aa4:
    lStack_30 = lVar9;
  }
  else if ((uVar3 == uVar4) &&
          (lVar9 = *(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar4 >> 1) * 2,
          *(short *)(*(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar4 >> 1) * 2) == 0x5c)) {
    local_38 = 2;
    goto LAB_140024aa4;
  }
  LOCK();
  *(int *)(lVar7 + -0x44) = *(int *)(lVar7 + -0x44) + 1;
  UNLOCK();
  ExReleaseResourceLite(puVar8 + 0xe);
  KeLeaveCriticalRegion();
  KeEnterCriticalRegion();
  plVar12 = (longlong *)CONCAT71((int7)(uVar11 >> 8),1);
  ExAcquireResourceExclusiveLite(puVar8 + 0x28);
  if (puVar8 == *(undefined4 **)(lVar7 + -8)) {
    lVar9 = *(longlong *)(lVar7 + -0x18);
    puVar1 = (undefined8 *)(lVar7 + -0x18);
    if (lVar9 == 0) {
LAB_140024b1e:
      if ((*(byte *)(lVar7 + -0x38) & 1) != 0) {
        plVar12 = *(longlong **)(puVar8 + 6);
        puVar2 = (undefined8 *)(puVar8 + 6);
        if ((undefined8 *)plVar12[1] != puVar2) goto LAB_140024c46;
        *puVar1 = plVar12;
        *(undefined8 **)(lVar7 + -0x10) = puVar2;
        plVar12[1] = (longlong)puVar1;
        *puVar2 = puVar1;
      }
      goto LAB_140024b44;
    }
    if ((*(undefined8 **)(lVar9 + 8) == puVar1) &&
       (plVar12 = *(longlong **)(lVar7 + -0x10), (undefined8 *)*plVar12 == puVar1)) {
      *plVar12 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar12;
      *puVar1 = 0;
      goto LAB_140024b1e;
    }
LAB_140024c46:
    puVar10 = (undefined *)0x3;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)();
    puVar14 = auStack_70;
  }
  else {
LAB_140024b44:
    ExReleaseResourceLite(puVar8 + 0x28);
    KeLeaveCriticalRegion();
    plVar12 = (longlong *)0x28;
    uVar15 = 0x62436644;
    puVar8 = (undefined4 *)ExAllocatePool2(0x102);
    if (puVar8 == (undefined4 *)0x0) {
      DfscRmDereferenceReferral(lVar7 + -0x48);
      return 0xc000009a;
    }
    *(undefined8 *)(puVar8 + 2) = 0;
    *(undefined8 *)(puVar8 + 6) = 0;
    *(undefined8 *)(puVar8 + 8) = 0;
    *puVar8 = 0x288103;
    puVar8[1] = 1;
    *(longlong *)(puVar8 + 4) = lVar7 + -0x48;
    DfscRmIsTimeToRefresh((longlong)puVar8);
    puVar14 = auStack_78;
    puVar13 = auStack_78;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar10 = WPP_GLOBAL_Control, puVar13 = auStack_78,
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0)) goto LAB_140024bcc;
  }
  uVar5 = *(undefined8 *)(puVar10 + 0x18);
  *(longlong *)(puVar14 + 0x30) = lVar7 + 0x48;
  *(undefined4 *)(puVar14 + 0x28) = puVar8[2];
  *(undefined8 *)(puVar14 + 0x20) = *(undefined8 *)(puVar8 + 4);
  *(undefined8 *)(puVar14 + -8) = 0x140024c75;
  WPP_SF_qqDZ(uVar5,plVar12,uVar15,puVar8,puVar14[0x20],puVar14[0x28],*(wchar_t **)(puVar14 + 0x30))
  ;
  puVar13 = puVar14;
LAB_140024bcc:
  if ((*(int *)(lVar7 + -0x3c) == 0) && (*(short *)(lVar7 + -0x2c) == 0)) {
    puVar8[2] = puVar8[2] | 2;
  }
  *(undefined2 *)(puVar8 + 8) = 0xffff;
  if (param_3 != (undefined8 *)0x0) {
    uVar5 = *(undefined8 *)(puVar13 + 0x48);
    *param_3 = *(undefined8 *)(puVar13 + 0x40);
    param_3[1] = uVar5;
  }
  *param_4 = puVar8;
  return 0;
}



===== DfscDomainCacheLookup @ 140024ca0 =====

undefined8 DfscDomainCacheLookup(longlong param_1,ushort *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  short sVar3;
  short sVar4;
  longlong lVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  undefined8 uVar14;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  ushort local_18 [2];
  undefined4 uStack_14;
  short *psStack_10;
  
  _local_18 = 0;
  psStack_10 = (short *)0x0;
  if ((2 < *param_2) && (**(short **)(param_2 + 4) == 0x5c)) {
    uVar8 = *(undefined4 *)param_2;
    uVar14 = *(undefined8 *)param_2;
    psStack_10 = *(short **)(param_2 + 4) + 1;
    param_2 = local_18;
    local_18[0] = (ushort)uVar8;
    sVar3 = local_18[0] - 2;
    local_18[1] = (ushort)((ulonglong)uVar14 >> 0x10);
    sVar4 = local_18[1] + -2;
    uStack_14 = (undefined4)((ulonglong)uVar14 >> 0x20);
    local_18 = (ushort  [2])CONCAT22(sVar4,sVar3);
  }
  if (*(longlong *)(param_1 + 0xf0) == 0) {
    puVar10 = DAT_14000d6c8;
  }
  else {
    puVar10 = *(undefined4 **)(*(longlong *)(param_1 + 0xf0) + 0x80);
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(puVar10 + 0xe,1);
  uVar14 = 0;
  lVar9 = RtlFindUnicodePrefix(puVar10,param_2);
  if ((lVar9 == 0) || ((*(byte *)(lVar9 + -0x38) & 1) == 0)) {
    ExReleaseResourceLite();
    KeLeaveCriticalRegion();
    return 0xc000003a;
  }
  LOCK();
  *(int *)(lVar9 + -0x44) = *(int *)(lVar9 + -0x44) + 1;
  UNLOCK();
  ExReleaseResourceLite(puVar10 + 0xe);
  KeLeaveCriticalRegion();
  KeEnterCriticalRegion();
  plVar12 = (longlong *)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
  ExAcquireResourceExclusiveLite(puVar10 + 0x28);
  if (puVar10 == *(undefined4 **)(lVar9 + -8)) {
    lVar5 = *(longlong *)(lVar9 + -0x18);
    puVar1 = (undefined8 *)(lVar9 + -0x18);
    if (lVar5 == 0) {
LAB_140024de7:
      if ((*(byte *)(lVar9 + -0x38) & 1) != 0) {
        plVar12 = *(longlong **)(puVar10 + 6);
        puVar2 = (undefined8 *)(puVar10 + 6);
        if ((undefined8 *)plVar12[1] != puVar2) goto LAB_140024ef0;
        *puVar1 = plVar12;
        *(undefined8 **)(lVar9 + -0x10) = puVar2;
        plVar12[1] = (longlong)puVar1;
        *puVar2 = puVar1;
      }
      goto LAB_140024e0d;
    }
    if ((*(undefined8 **)(lVar5 + 8) == puVar1) &&
       (plVar12 = *(longlong **)(lVar9 + -0x10), (undefined8 *)*plVar12 == puVar1)) {
      *plVar12 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar12;
      *puVar1 = 0;
      goto LAB_140024de7;
    }
LAB_140024ef0:
    puVar11 = (undefined *)0x3;
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)();
    puVar13 = auStack_50;
  }
  else {
LAB_140024e0d:
    ExReleaseResourceLite(puVar10 + 0x28);
    KeLeaveCriticalRegion();
    plVar12 = (longlong *)0x28;
    uVar14 = 0x62436644;
    puVar10 = (undefined4 *)ExAllocatePool2(0x102);
    if (puVar10 == (undefined4 *)0x0) {
      DfscRmDereferenceReferral(lVar9 + -0x48);
      return 0xc000009a;
    }
    *(undefined8 *)(puVar10 + 2) = 0;
    *(undefined8 *)(puVar10 + 6) = 0;
    *(undefined8 *)(puVar10 + 8) = 0;
    *puVar10 = 0x288103;
    puVar10[1] = 1;
    *(longlong *)(puVar10 + 4) = lVar9 + -0x48;
    DfscRmIsTimeToRefresh((longlong)puVar10);
    puVar13 = auStack_58;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar11 = WPP_GLOBAL_Control, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0))
    goto LAB_140024e91;
  }
  uVar6 = *(undefined8 *)(puVar11 + 0x18);
  *(longlong *)(puVar13 + 0x30) = lVar9 + 0x48;
  *(undefined4 *)(puVar13 + 0x28) = puVar10[2];
  *(undefined8 *)(puVar13 + 0x20) = *(undefined8 *)(puVar10 + 4);
  *(undefined8 *)(puVar13 + -8) = 0x140024f1f;
  WPP_SF_qqDZ(uVar6,plVar12,uVar14,puVar10,puVar13[0x20],puVar13[0x28],*(wchar_t **)(puVar13 + 0x30)
             );
LAB_140024e91:
  if ((*(int *)(lVar9 + -0x3c) == 0) && (*(short *)(lVar9 + -0x2c) == 0)) {
    puVar10[2] = puVar10[2] | 2;
  }
  *(undefined2 *)(puVar10 + 8) = 0xffff;
  *param_3 = puVar10;
  return 0;
}



===== DfscCompareStringsIgnoreTrailingChars @ 140024f40 =====

undefined8 DfscCompareStringsIgnoreTrailingChars(ushort *param_1,ushort *param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  short sVar5;
  ulonglong uVar6;
  short local_28;
  undefined6 uStack_26;
  undefined8 uStack_20;
  short local_18;
  undefined6 uStack_16;
  undefined8 uStack_10;
  
  uVar4 = (ulonglong)(*param_2 >> 1);
  uVar6 = (ulonglong)(*param_1 >> 1);
  if (*param_1 >> 1 != 0) {
    do {
      sVar5 = *(short *)(*(longlong *)(param_1 + 4) + -2 + uVar6 * 2);
      if ((sVar5 != 0x5c) && (sVar5 != 0)) break;
      uVar2 = (short)uVar6 - 1;
      uVar6 = (ulonglong)uVar2;
    } while (uVar2 != 0);
  }
  sVar5 = (short)uVar6;
  if (*param_2 >> 1 != 0) {
    do {
      sVar1 = *(short *)(*(longlong *)(param_2 + 4) + -2 + uVar4 * 2);
      if ((sVar1 != 0x5c) && (sVar1 != 0)) break;
      uVar2 = (short)uVar4 - 1;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 != 0);
    sVar1 = (short)uVar4;
    if (sVar1 != 0) {
      if (sVar1 != sVar5) {
        return 0;
      }
      if (sVar5 == 0) {
        return 0;
      }
      uStack_10 = *(undefined8 *)(param_1 + 4);
      _local_18 = CONCAT62((int6)((ulonglong)*(undefined8 *)param_1 >> 0x10),sVar5 * 2);
      uStack_20 = *(undefined8 *)(param_2 + 4);
      _local_28 = CONCAT62((int6)((ulonglong)*(undefined8 *)param_2 >> 0x10),sVar1 * 2);
      iVar3 = RtlCompareUnicodeString
                        (&local_18,&local_28,CONCAT71((uint7)(byte)((ushort)(sVar5 * 2) >> 8),1));
      if (iVar3 == 0) {
        return 1;
      }
      return 0;
    }
  }
  if (sVar5 == 0) {
    return 1;
  }
  return 0;
}



===== DfscCmDataAccessState @ 140025050 =====

undefined8 DfscCmDataAccessState(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined2 *_Dst;
  wchar_t *_Dst_00;
  undefined8 uVar11;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  wchar_t wVar12;
  uint uVar13;
  char *pcVar14;
  char *pcVar15;
  undefined8 *puVar16;
  wchar_t *pwVar17;
  undefined1 uVar18;
  ulonglong uVar19;
  char cVar20;
  wchar_t *pwVar21;
  uint *puVar22;
  longlong lVar23;
  undefined8 *local_res8;
  undefined1 local_res10;
  undefined8 *local_res18;
  wchar_t *local_res20;
  undefined8 in_stack_fffffffffffffef8;
  undefined4 uVar24;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  longlong local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined8 local_90;
  longlong local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined2 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  
  uVar24 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  _Dst_00 = (wchar_t *)0x0;
  local_res10 = 0;
  local_e8 = 0;
  uStack_e0 = (undefined2 *)0x0;
  local_res8 = (undefined8 *)0x0;
  if (*(int *)(param_1 + 0x124) != 0) {
    *(undefined4 *)(param_1 + 0x13c) = 0;
    return 9;
  }
  lVar2 = *(longlong *)(param_1 + 0x150);
  pcVar14 = *(char **)(lVar2 + 0xb8);
  local_b8 = *(longlong *)(pcVar14 + 0x30);
  if (*(longlong *)(param_1 + 0x148) == 0) {
    lVar23 = 0;
  }
  else {
    lVar23 = *(longlong *)(*(longlong *)(param_1 + 0x148) + 0x58);
    if (((lVar23 != 0) && (*(longlong *)(lVar23 + 8) != 0)) &&
       (*(int *)(*(longlong *)(lVar23 + 8) + 0x94) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids);
      }
      uVar19 = DfscAddEcpToIrp(lVar2,&GUID_ECP_NETWORK_OPEN_CONTEXT,0x1c,&local_res8);
      if ((int)uVar19 == 0) {
        *local_res8 = 0;
        local_res8[1] = 0;
        local_res8[2] = 0;
        *(undefined4 *)(local_res8 + 3) = 0;
        *local_res8 = 0x1c;
        puVar16 = local_res8;
        bVar5 = DfscGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities
                          ((byte)*(undefined4 *)(*(longlong *)(lVar23 + 8) + 0x94));
        *(int *)(puVar16 + 1) = (int)CONCAT71(extraout_var,bVar5);
      }
      else {
        if ((int)uVar19 != 0x40000000) {
          iVar8 = -0x3fffff66;
          goto LAB_140025817;
        }
        bVar5 = DfscGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities
                          ((byte)*(undefined4 *)(*(longlong *)(lVar23 + 8) + 0x94));
        iVar8 = *(int *)(local_res8 + 1);
        iVar10 = (int)CONCAT71(extraout_var_00,bVar5);
        if (iVar8 == 4) {
          if (iVar10 == 3) {
            *(undefined4 *)(local_res8 + 1) = 3;
          }
        }
        else {
          if (iVar10 < iVar8) {
            iVar10 = iVar8;
          }
          *(int *)(local_res8 + 1) = iVar10;
        }
      }
    }
  }
  uVar7 = *(ushort *)(param_1 + 0x120);
  if (((uVar7 & 2) == 0) && (DAT_14000d784 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids);
    }
    local_res8 = (undefined8 *)0x0;
    local_res18 = (undefined8 *)0x0;
    if ((char)*(undefined4 *)(lVar2 + 0x10) < '\0') {
      iVar8 = IoGetIrpExtraCreateParameter(lVar2,&local_res8);
      if (iVar8 == 0) {
        if (local_res8 == (undefined8 *)0x0) {
          iVar8 = FsRtlAllocateExtraCreateParameterList(0,&local_res8);
          if (iVar8 != 0) goto LAB_140025192;
          iVar8 = IoSetIrpExtraCreateParameter(lVar2,local_res8);
          if (iVar8 == 0) goto LAB_14002513c;
          FsRtlFreeExtraCreateParameterList(local_res8);
          goto LAB_140025196;
        }
LAB_14002513c:
        iVar8 = FsRtlFindExtraCreateParameter
                          (local_res8,&GUID_ECP_NETWORK_OPEN_CONTEXT,&local_res18,0);
        if (iVar8 != 0) {
          uVar11 = CONCAT44(uVar24,0x48436644);
          iVar8 = FsRtlAllocateExtraCreateParameter
                            (&GUID_ECP_NETWORK_OPEN_CONTEXT,0x1c,0,0,uVar11,&local_res18);
          uVar24 = (undefined4)((ulonglong)uVar11 >> 0x20);
          if (iVar8 != 0) goto LAB_140025192;
          iVar8 = FsRtlInsertExtraCreateParameter(local_res8,local_res18);
          if (iVar8 != 0) {
            FsRtlFreeExtraCreateParameter(local_res18);
            goto LAB_140025196;
          }
          puVar16 = local_res18;
          goto LAB_1400251ce;
        }
        puVar16 = local_res18;
LAB_140025947:
        *(undefined4 *)((longlong)puVar16 + 4) = 1;
      }
      else {
LAB_140025192:
        puVar16 = (undefined8 *)0x0;
        if (iVar8 != 0) {
LAB_140025196:
          puVar16 = (undefined8 *)0x0;
          if (iVar8 != 0x40000000) goto LAB_1400251a2;
          goto LAB_140025947;
        }
LAB_1400251ce:
        *puVar16 = 0;
        puVar16[1] = 0;
        puVar16[2] = 0;
        *(undefined4 *)(puVar16 + 3) = 0;
        *(undefined4 *)puVar16 = 0x1c;
        *(undefined8 *)((longlong)puVar16 + 4) = 1;
      }
      *(ushort *)(param_1 + 0x120) = *(ushort *)(param_1 + 0x120) | 2;
      uVar7 = *(ushort *)(param_1 + 0x120);
      goto LAB_140025209;
    }
LAB_1400251a2:
    iVar8 = -0x3fffff42;
    goto LAB_140025817;
  }
LAB_140025209:
  if (((uVar7 & 4) == 0) && ((*(uint *)(param_1 + 0xf0) & 1) != 0)) {
    if (*(longlong *)(param_1 + 0x110) == 0) {
      pwVar17 = (wchar_t *)0x0;
    }
    else {
      pwVar17 = (wchar_t *)(*(longlong *)(*(longlong *)(param_1 + 0x110) + 0x10) + 0x80);
    }
    if (*pwVar17 != L'\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,pwVar17);
      }
      local_res18 = (undefined8 *)0x0;
      local_res8 = (undefined8 *)CONCAT44(local_res8._4_4_,(ushort)*pwVar17 + 2);
      local_res20 = (wchar_t *)0x0;
      if (-1 < (char)*(undefined4 *)(lVar2 + 0x10)) goto LAB_1400251a2;
      iVar8 = IoGetIrpExtraCreateParameter(lVar2,&local_res18);
      if (iVar8 == 0) {
        if (local_res18 == (undefined8 *)0x0) {
          iVar8 = FsRtlAllocateExtraCreateParameterList(0,&local_res18);
          if (iVar8 != 0) goto LAB_1400252f3;
          iVar8 = IoSetIrpExtraCreateParameter(lVar2,local_res18);
          if (iVar8 == 0) goto LAB_14002529d;
          FsRtlFreeExtraCreateParameterList(local_res18);
          goto LAB_140025b1c;
        }
LAB_14002529d:
        iVar8 = FsRtlFindExtraCreateParameter
                          (local_res18,&GUID_ECP_DOMAIN_SERVICE_NAME_CONTEXT,&local_res20,0);
        if (iVar8 != 0) {
          uVar11 = CONCAT44(uVar24,0x48436644);
          iVar8 = FsRtlAllocateExtraCreateParameter
                            (&GUID_ECP_DOMAIN_SERVICE_NAME_CONTEXT,
                             (ulonglong)local_res8 & 0xffffffff,0,0,uVar11,&local_res20);
          uVar24 = (undefined4)((ulonglong)uVar11 >> 0x20);
          if (iVar8 != 0) goto LAB_1400252f3;
          iVar8 = FsRtlInsertExtraCreateParameter(local_res18,local_res20);
          if (iVar8 != 0) {
            FsRtlFreeExtraCreateParameter(local_res20);
            goto LAB_140025b1c;
          }
          pwVar21 = local_res20;
          goto LAB_1400252ff;
        }
      }
      else {
LAB_1400252f3:
        if (iVar8 == 0) {
          pwVar21 = _Dst_00;
LAB_1400252ff:
          memmove(pwVar21 + 1,*(void **)(pwVar17 + 4),(ulonglong)(ushort)*pwVar17);
          *pwVar21 = *pwVar17;
        }
        else {
LAB_140025b1c:
          if (iVar8 != 0x40000000) goto LAB_1400251a2;
        }
      }
      *(wchar_t **)(*(longlong *)(param_1 + 0x148) + 0x50) = pwVar17;
      *(ushort *)(param_1 + 0x120) = *(ushort *)(param_1 + 0x120) | 4;
    }
  }
  if ((((lVar23 == 0) || (*(longlong *)(lVar23 + 8) == 0)) ||
      (lVar3 = *(longlong *)(*(longlong *)(lVar23 + 8) + 0xa8), lVar3 == 0)) ||
     (*(int *)(lVar3 + 4) == 0)) {
    cVar20 = '\0';
    local_res8 = (undefined8 *)((ulonglong)local_res8._1_7_ << 8);
LAB_14002533c:
    *(undefined8 *)(param_1 + 0x158) = 0;
    *(undefined8 *)(param_1 + 0x160) = 0;
    lVar23 = *(longlong *)(param_1 + 0x110);
    *(undefined8 *)(param_1 + 0x168) = 0;
    uVar18 = 0xff;
    if (lVar23 != 0) {
      uVar18 = (undefined1)*(undefined4 *)(*(longlong *)(lVar23 + 0x10) + 0xc);
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,param_1,uVar18);
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
          pwVar17 = (wchar_t *)(*(longlong *)(param_1 + 0x118) + 0x60);
          WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                    &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,(uint)(ushort)*pwVar17,pwVar17)
          ;
        }
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
            pwVar17 = (wchar_t *)(*(longlong *)(lVar23 + 0x10) + 0x90);
            WPP_SF_DDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                       &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,
                       *(ushort *)(*(longlong *)(lVar23 + 0x10) + 0x10) >> 1 & 1,(char)*pwVar17,
                       pwVar17);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
            WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                      &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,
                      (uint)(ushort)*(wchar_t *)(param_1 + 0xd0),(wchar_t *)(param_1 + 0xd0));
          }
        }
      }
    }
    if ((*(byte *)(*(longlong *)(lVar23 + 0x10) + 0x10) & 2) == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = (uint)*(ushort *)(*(longlong *)(lVar23 + 0x10) + 0x90);
    }
    uVar13 = *(ushort *)(*(longlong *)(param_1 + 0x118) + 0x60) + uVar13 +
             *(ushort *)(param_1 + 0xd0) + 4;
    if (0xffff < uVar13) {
      *(undefined4 *)(param_1 + 0x13c) = 0xc0000106;
      return 9;
    }
    uVar19 = 0x66436644;
    local_e8._0_4_ = CONCAT22((short)uVar13,(wchar_t)local_e8);
    _Dst = (undefined2 *)ExAllocatePool2(0x102);
    if (_Dst == (undefined2 *)0x0) {
      iVar8 = -0x3fffff66;
      goto LAB_14002580e;
    }
    uVar7 = *(ushort *)(*(longlong *)(param_1 + 0x118) + 0x60);
    uStack_e0 = _Dst;
    if (uVar7 == 0) {
      *_Dst = 0x5c;
      wVar12 = L'\x02';
    }
    else {
      uVar19 = (ulonglong)uVar7;
      memmove(_Dst,*(void **)(*(longlong *)(param_1 + 0x118) + 0x68),uVar19);
      wVar12 = *(wchar_t *)(*(longlong *)(param_1 + 0x118) + 0x60);
    }
    local_e8 = CONCAT62(local_e8._2_6_,wVar12);
    pcVar15 = *(char **)(lVar23 + 0x10);
    if ((*(uint *)((longlong)pcVar15 + 0x10) & 2) != 0) {
      pcVar15 = (char *)((longlong)pcVar15 + 0x90);
      RtlAppendUnicodeStringToString(&local_e8);
      wVar12 = (wchar_t)local_e8;
    }
    if (*(short *)(param_1 + 0xd0) != 0) {
      if (((*(short *)((longlong)uStack_e0 + ((ulonglong)(ushort)wVar12 - 2 & 0xfffffffffffffffe))
            != 0x5c) && (**(short **)(param_1 + 0xd8) != 0x5c)) &&
         (**(short **)(param_1 + 0xd8) != 0x3a)) {
        RtlAppendUnicodeToString(&local_e8,L"\\");
      }
      pcVar15 = (char *)(param_1 + 0xd0);
      RtlAppendUnicodeStringToString(&local_e8);
    }
    uVar11 = *(undefined8 *)(local_b8 + 0x60);
    *(undefined8 *)(param_1 + 0x158) = *(undefined8 *)(local_b8 + 0x58);
    *(undefined8 *)(param_1 + 0x160) = uVar11;
    *(undefined8 *)(param_1 + 0x168) = *(undefined8 *)(local_b8 + 0x40);
    *(undefined8 *)(local_b8 + 0x40) = 0;
    *(undefined4 *)(local_b8 + 0x58) = (undefined4)local_e8;
    *(undefined4 *)(local_b8 + 0x5c) = local_e8._4_4_;
    *(undefined4 *)(local_b8 + 0x60) = (undefined4)uStack_e0;
    *(undefined4 *)(local_b8 + 100) = uStack_e0._4_4_;
    *(ushort *)(param_1 + 0x120) = *(ushort *)(param_1 + 0x120) | 1;
    if ((*pcVar14 == '\0') && (uVar13 = *(uint *)(pcVar14 + 0x20), uVar13 != 0)) {
      iVar8 = *(int *)(*(longlong *)(param_1 + 0xe8) + 0x48);
      if (iVar8 == 0) {
        pwVar17 = *(wchar_t **)(lVar2 + 0x18);
        goto LAB_14002561b;
      }
      uVar9 = iVar8 + 3U & 0xfffffffc;
      uVar1 = uVar13 + uVar9;
      local_res18 = (undefined8 *)CONCAT44(local_res18._4_4_,uVar1);
      if ((uVar1 < uVar9) || (uVar1 < uVar13)) {
        iVar8 = -0x7ffffffb;
      }
      else {
        _Dst_00 = (wchar_t *)ExAllocatePool2(0x42,uVar1,0x65436644);
        if (_Dst_00 != (wchar_t *)0x0) {
          lVar23 = *(longlong *)(param_1 + 0xe8);
          uVar19 = (ulonglong)*(uint *)(lVar23 + 0x48);
          memmove(_Dst_00,(void *)(lVar23 + 0x50),uVar19);
          uVar13 = *(uint *)_Dst_00;
          local_res20 = _Dst_00;
          if (uVar13 != 0) {
            do {
              local_res20 = (wchar_t *)((longlong)local_res20 + (ulonglong)uVar13);
              uVar13 = *(uint *)local_res20;
            } while (uVar13 != 0);
          }
          puVar22 = *(uint **)(lVar2 + 0x18);
          local_res20[0] = L'\0';
          local_res20[1] = L'\0';
          pwVar17 = local_res20;
          while( true ) {
            pcVar15 = "Principal";
            iVar8 = strcmp((char *)(puVar22 + 2),"Principal");
            if (iVar8 != 0) {
              pcVar15 = "UserName";
              iVar8 = strcmp((char *)(puVar22 + 2),"UserName");
              if (iVar8 != 0) {
                pcVar15 = "Password";
                iVar8 = strcmp((char *)(puVar22 + 2),"Password");
                if (iVar8 != 0) {
                  uVar13 = (uint)*(byte *)((longlong)pwVar17 + 5) + (ushort)pwVar17[3] + 0xc &
                           0xfffffffc;
                  *(uint *)pwVar17 = uVar13;
                  pwVar17 = (wchar_t *)((longlong)pwVar17 + (ulonglong)uVar13);
                  if (*puVar22 == 0) {
                    uVar19 = (ulonglong)*(byte *)((longlong)puVar22 + 5) + 9 +
                             (ulonglong)*(ushort *)((longlong)puVar22 + 6);
                  }
                  else {
                    uVar19 = (ulonglong)*(byte *)((longlong)puVar22 + 5) + 0xc +
                             (ulonglong)*(ushort *)((longlong)puVar22 + 6) & 0xfffffffc;
                  }
                  pcVar15 = (char *)puVar22;
                  memmove(pwVar17,puVar22,uVar19);
                  pwVar17[0] = L'\0';
                  pwVar17[1] = L'\0';
                }
              }
            }
            if (*puVar22 == 0) break;
            puVar22 = (uint *)((longlong)puVar22 + (ulonglong)*puVar22);
          }
          pwVar17 = _Dst_00;
          cVar20 = (char)local_res8;
          uVar13 = (uint)local_res18;
          goto LAB_14002561b;
        }
        iVar8 = -0x3fffff66;
      }
    }
    else {
      uVar13 = *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x48);
      pwVar17 = (wchar_t *)(*(longlong *)(param_1 + 0xe8) + 0x50);
LAB_14002561b:
      *(wchar_t **)(*(longlong *)(param_1 + 0x148) + 0x40) = pwVar17;
      *(uint *)(*(longlong *)(param_1 + 0x148) + 0x48) = uVar13;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        if (*(longlong *)(*(longlong *)(param_1 + 0x148) + 0x40) == 0) {
          pcVar14 = "<nada>";
        }
        else {
          pcVar14 = (char *)(*(longlong *)(param_1 + 0xe8) + 0x58);
        }
        WPP_SF_qZs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar15,uVar19,param_1,
                   (wchar_t *)&local_e8,pcVar14);
      }
      iVar8 = MupSurrogateResolvePrefix(*(undefined8 *)(param_1 + 0x148));
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        lVar23 = *(longlong *)(param_1 + 0xe8);
        pcVar14 = (char *)(lVar23 + 0x58);
        if (lVar23 == 0) {
          pcVar14 = "<none>";
        }
        WPP_SF_DZsq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),**(undefined8 **)(param_1 + 0x148),
                    WPP_GLOBAL_Control,iVar8,(wchar_t *)&local_e8,pcVar14,
                    (char)**(undefined8 **)(param_1 + 0x148));
      }
      if (-1 < iVar8) {
        uVar11 = MupSurrogateGetUncProviderDeviceObject(*(undefined8 *)(param_1 + 0x148));
        local_res8 = (undefined8 *)IoGetAttachedDevice(uVar11);
        local_d8 = 0;
        uStack_d0 = 0;
        local_c8 = 0;
        lVar23 = *(longlong *)(*(longlong *)(lVar2 + 0xb8) + 0x30);
        memset(&local_a8,0,0x58);
        local_a8 = *(undefined8 *)(lVar23 + 0x58);
        uStack_a0 = *(undefined8 *)(lVar23 + 0x60);
        local_58 = *(undefined8 *)(param_1 + 0x168);
        lVar3 = *(longlong *)(param_1 + 0x110);
        lVar4 = *(longlong *)(param_1 + 0xe8);
        local_98 = 0xbbbbbbbb;
        local_68 = *(undefined8 *)(lVar4 + 8);
        uStack_60 = *(undefined8 *)(lVar4 + 0x10);
        local_88 = lVar3;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                    &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,(wchar_t *)&local_a8,
                    (wchar_t *)&local_68);
        }
        *(undefined8 **)(lVar23 + 0x18) = &local_a8;
        local_80 = *(undefined4 *)(param_1 + 0x128);
        uStack_7c = *(undefined4 *)(param_1 + 300);
        uStack_78 = *(undefined4 *)(param_1 + 0x130);
        uStack_74 = *(undefined4 *)(param_1 + 0x134);
        local_90 = 0x11444653;
        if ((*(byte *)(*(longlong *)(lVar3 + 0x10) + 0x10) & 2) != 0) {
          local_90 = 0xff444653;
        }
        local_70 = *(undefined2 *)(param_1 + 0xe0);
        KeInitializeEvent(&local_d8,1);
        puVar16 = *(undefined8 **)(lVar2 + 0xb8);
        puVar16[-9] = *puVar16;
        puVar16[-8] = puVar16[1];
        puVar16[-7] = puVar16[2];
        puVar16[-6] = puVar16[3];
        *(undefined4 *)(puVar16 + -5) = *(undefined4 *)(puVar16 + 4);
        *(undefined4 *)((longlong)puVar16 + -0x24) = *(undefined4 *)((longlong)puVar16 + 0x24);
        *(undefined4 *)(puVar16 + -4) = *(undefined4 *)(puVar16 + 5);
        *(undefined4 *)((longlong)puVar16 + -0x1c) = *(undefined4 *)((longlong)puVar16 + 0x2c);
        puVar16[-3] = puVar16[6];
        *(undefined1 *)((longlong)puVar16 + -0x45) = 0;
        lVar23 = *(longlong *)(lVar2 + 0xb8);
        *(code **)(lVar23 + -0x10) = DfscCmCompletionRoutine;
        *(undefined8 **)(lVar23 + -8) = &local_d8;
        *(undefined1 *)(lVar23 + -0x45) = 0xe0;
        iVar8 = IofCallDriver(local_res8,lVar2);
        if (((iVar8 == 0x103) &&
            ((iVar8 = FsRtlCancellableWaitForSingleObject(&local_d8,0,lVar2), iVar8 == -0x3ffffee0
             || (iVar8 == -0x3fffffb5)))) &&
           ((cVar6 = IoCancelIrp(lVar2), cVar6 == '\0' ||
            (iVar8 = KeReadStateEvent(&local_d8), iVar8 == 0)))) {
          KeWaitForSingleObject(&local_d8,0,0,0,0);
        }
        iVar8 = *(int *)(lVar2 + 0x30);
      }
      if (_Dst_00 != (wchar_t *)0x0) {
        ExFreePoolWithTag(_Dst_00,0);
        *(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0x40) = 0;
        *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x48) = 0;
      }
    }
LAB_14002580e:
    if (cVar20 == '\0') goto LAB_140025817;
  }
  else {
    cVar20 = '\x01';
    local_res8 = (undefined8 *)CONCAT71(local_res8._1_7_,1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids);
    }
    local_res18 = (undefined8 *)0x0;
    local_res20 = (wchar_t *)0x0;
    iVar8 = *(int *)(*(longlong *)(*(longlong *)(lVar23 + 8) + 0xa8) + 4);
    if (((char)*(undefined4 *)(lVar2 + 0x10) < '\0') &&
       (iVar10 = IoGetIrpExtraCreateParameter(lVar2,&local_res18), iVar10 == 0)) {
      if (local_res18 == (undefined8 *)0x0) {
        iVar10 = FsRtlAllocateExtraCreateParameterList(0,&local_res18);
        if (iVar10 == 0) {
          iVar10 = IoSetIrpExtraCreateParameter(lVar2,local_res18);
          if (iVar10 == 0) goto LAB_1400259db;
          FsRtlFreeExtraCreateParameterList(local_res18);
        }
      }
      else {
LAB_1400259db:
        iVar10 = FsRtlFindExtraCreateParameter
                           (local_res18,&GUID_ECP_SMB_TREE_CONNECT_CONTEXT,&local_res20,0);
        if ((iVar10 != 0) &&
           (iVar8 = FsRtlAllocateExtraCreateParameter
                              (&GUID_ECP_SMB_TREE_CONNECT_CONTEXT,iVar8 + 0x18,0,0,
                               CONCAT44(uVar24,0x48436644),&local_res20), iVar8 == 0)) {
          iVar8 = FsRtlInsertExtraCreateParameter(local_res18,local_res20);
          if (iVar8 == 0) {
            puVar16 = *(undefined8 **)(*(longlong *)(lVar23 + 8) + 0xa8);
            uVar11 = puVar16[1];
            *(undefined8 *)local_res20 = *puVar16;
            *(undefined8 *)(local_res20 + 4) = uVar11;
            *(undefined8 *)(local_res20 + 8) = puVar16[2];
            *(wchar_t **)local_res20 = local_res20 + 0xc;
            puVar22 = *(uint **)(*(longlong *)(lVar23 + 8) + 0xa8);
            memmove(local_res20 + 0xc,(void *)((ulonglong)*puVar22 + (longlong)puVar22),
                    (ulonglong)puVar22[1]);
            goto LAB_14002533c;
          }
          FsRtlFreeExtraCreateParameter(local_res20);
        }
      }
    }
    iVar8 = -0x3fffff42;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids);
  }
  DfscRemoveEcpFromIrp(lVar2,&GUID_ECP_SMB_TREE_CONNECT_CONTEXT);
LAB_140025817:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,iVar8);
  }
  *(int *)(param_1 + 0x13c) = iVar8;
  uVar11 = DfscPostProcessDataAccessState(param_1);
  return uVar11;
}



===== DfscPostProcessDataAccessState @ 140026020 =====

undefined8 DfscPostProcessDataAccessState(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  int iVar10;
  longlong local_res8;
  undefined8 local_res10;
  
  iVar1 = *(int *)(param_1 + 0x13c);
  lVar2 = *(longlong *)(param_1 + 0x150);
  lVar3 = *(longlong *)(param_1 + 0x110);
  lVar4 = *(longlong *)(*(longlong *)(lVar2 + 0xb8) + 0x30);
  iVar10 = iVar1;
  if (iVar1 < 0) {
    DfscReplaceFileObjectInformation(param_1,lVar4);
    if (iVar1 == -0x3fffffdc) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,param_1);
      }
      uVar9 = 8;
      iVar10 = 0;
    }
    else {
      if (iVar1 != -0x3ffffda9) {
        if ((iVar1 == -0x3fffffc6) && (*(ushort *)(param_1 + 0xd0) < 3)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,param_1);
          }
          *(undefined1 *)(*(longlong *)(lVar3 + 0x10) + 0x12) = 0;
LAB_1400261fd:
          uVar9 = 5;
          goto LAB_140026121;
        }
        iVar8 = 0;
        iVar6 = 0x1d;
        do {
          iVar7 = (iVar6 + iVar8) / 2;
          if (*(int *)(&DfscFailoverErrorList + (longlong)iVar7 * 4) == iVar1) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
              WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                        &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,param_1,(char)iVar1);
            }
            *(undefined1 *)(*(longlong *)(lVar3 + 0x10) + 0x12) = 0;
            goto LAB_1400261fd;
          }
          iVar5 = iVar7 + -1;
          if (*(int *)(&DfscFailoverErrorList + (longlong)iVar7 * 4) < iVar1) {
            iVar8 = iVar7 + 1;
            iVar5 = iVar6;
          }
          iVar6 = iVar5;
        } while (iVar8 <= iVar6);
        goto LAB_1400261b7;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,param_1,0x57);
      }
      uVar9 = 7;
      iVar10 = 0;
    }
  }
  else {
    if (iVar1 == 0x104) {
      DfscReplaceFileObjectInformation(param_1,lVar4);
LAB_1400261b7:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_437e7fbce0fd321920764c6a18cc1998_Traceguids,param_1,(char)iVar1);
      }
      iVar10 = 0;
    }
    else if (*(longlong *)(param_1 + 0x160) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x160),0);
      *(undefined8 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x158) = 0;
    }
    uVar9 = 9;
  }
  *(undefined2 *)(*(longlong *)(*(longlong *)(param_1 + 0x110) + 0x10) + 0x1e) =
       *(undefined2 *)(*(longlong *)(param_1 + 0x110) + 0x20);
  if ((*(byte *)(param_1 + 0x120) & 4) != 0) {
    local_res10 = 0;
    local_res8 = 0;
    iVar6 = IoGetIrpExtraCreateParameter(lVar2,&local_res8);
    if (((iVar6 == 0) && (local_res8 != 0)) &&
       (iVar6 = FsRtlRemoveExtraCreateParameter
                          (local_res8,&GUID_ECP_DOMAIN_SERVICE_NAME_CONTEXT,&local_res10,0),
       iVar6 == 0)) {
      FsRtlFreeExtraCreateParameter(local_res10);
    }
    *(ushort *)(param_1 + 0x120) = *(ushort *)(param_1 + 0x120) & 0xfffb;
  }
LAB_140026121:
  DfscReferralSetCurrentAccessStatus(*(longlong *)(param_1 + 0x110),iVar10);
  *(int *)(param_1 + 0x13c) = iVar1;
  return uVar9;
}



===== DfscAddEcpToIrp @ 140026340 =====

ulonglong DfscAddEcpToIrp(longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4
                         )

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res8;
  undefined8 local_res20;
  
  local_res8 = 0;
  local_res20 = 0;
  *param_4 = 0;
  if ((char)*(undefined4 *)(param_1 + 0x10) < '\0') {
    uVar3 = IoGetIrpExtraCreateParameter(param_1,&local_res8);
    if ((int)uVar3 == 0) {
      if (local_res8 == 0) {
        uVar3 = FsRtlAllocateExtraCreateParameterList(0,&local_res8);
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        uVar2 = IoSetIrpExtraCreateParameter(param_1,local_res8);
        if (uVar2 != 0) {
          FsRtlFreeExtraCreateParameterList(local_res8);
          return (ulonglong)uVar2;
        }
      }
      iVar1 = FsRtlFindExtraCreateParameter(local_res8,param_2,&local_res20,0);
      if (iVar1 == 0) {
        *param_4 = local_res20;
        uVar3 = 0x40000000;
      }
      else {
        uVar3 = FsRtlAllocateExtraCreateParameter(param_2,param_3,0,0,0x48436644,&local_res20);
        if ((int)uVar3 == 0) {
          uVar2 = FsRtlInsertExtraCreateParameter(local_res8,local_res20);
          uVar3 = (ulonglong)uVar2;
          if (uVar2 == 0) {
            *param_4 = local_res20;
            return 0;
          }
          FsRtlFreeExtraCreateParameter(local_res20);
        }
      }
    }
  }
  else {
    uVar3 = 0xc0000010;
  }
  return uVar3;
}



===== DfscReplaceFileObjectInformation @ 1400264a4 =====

void DfscReplaceFileObjectInformation(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if ((*(byte *)(param_1 + 0x120) & 1) != 0) {
    if (*(longlong *)(param_2 + 0x60) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x60),0);
    }
    uVar1 = *(undefined8 *)(param_1 + 0x160);
    *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_1 + 0x158);
    *(undefined8 *)(param_2 + 0x60) = uVar1;
    *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_1 + 0x168);
    *(ushort *)(param_1 + 0x120) = *(ushort *)(param_1 + 0x120) & 0xfffe;
    *(undefined8 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined8 *)(param_1 + 0x168) = 0;
  }
  return;
}



===== DfscRemoveEcpFromIrp @ 14002652c =====

ulonglong DfscRemoveEcpFromIrp(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = 0;
  uVar2 = IoGetIrpExtraCreateParameter(param_1,&local_res18);
  if ((int)uVar2 == 0) {
    if (local_res18 == 0) {
      uVar2 = 0xc0000225;
    }
    else {
      uVar1 = FsRtlRemoveExtraCreateParameter(local_res18,param_2,&local_res20,0);
      uVar2 = (ulonglong)uVar1;
      if (uVar1 == 0) {
        FsRtlFreeExtraCreateParameter(local_res20);
      }
    }
  }
  return uVar2;
}



===== DfscCmReleaseContext @ 1400265b0 =====

undefined8 DfscCmReleaseContext(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined1 *puVar9;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  puVar9 = auStackY_48;
  if (param_1 != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,param_1,
                (char)*(undefined4 *)(param_1 + 4));
    }
    LOCK();
    piVar1 = (int *)(param_1 + 4);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 != 1) {
      return 0;
    }
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000d658,1);
    plVar2 = (longlong *)(param_1 + 0x170);
    lVar4 = *plVar2;
    if ((*(longlong **)(lVar4 + 8) == plVar2) &&
       (plVar5 = *(longlong **)(param_1 + 0x178), (longlong *)*plVar5 == plVar2)) {
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      ExReleaseResourceLite(&DAT_14000d658);
      KeLeaveCriticalRegion();
      if (*(longlong *)(param_1 + 0x68) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0);
      }
      *(undefined8 *)(param_1 + 0x10) = 0;
      *(undefined8 *)(param_1 + 0x18) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
      *(undefined8 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined8 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x88) = 0;
      *(undefined8 *)(param_1 + 0x90) = 0;
      *(undefined8 *)(param_1 + 0x98) = 0;
      *(undefined8 *)(param_1 + 0xa0) = 0;
      *(undefined8 *)(param_1 + 0xa8) = 0;
      *(undefined8 *)(param_1 + 0xb0) = 0;
      *(undefined8 *)(param_1 + 0xb8) = 0;
      *(undefined8 *)(param_1 + 0xc0) = 0;
      *(undefined8 *)(param_1 + 200) = 0;
      *(undefined8 *)(param_1 + 0xd0) = 0;
      *(undefined8 *)(param_1 + 0xd8) = 0;
      *(undefined2 *)(param_1 + 0xe2) = 0;
      lVar4 = *(longlong *)(param_1 + 0xe8);
      if (lVar4 != 0) {
        lVar6 = *(longlong *)(lVar4 + 0x18);
        if (lVar6 != 0) {
          KeEnterCriticalRegion();
          ExAcquireResourceExclusiveLite(lVar6 + 0x68,1);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                    &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,lVar4,
                    (char)*(undefined4 *)(lVar4 + 4));
        }
        LOCK();
        piVar1 = (int *)(lVar4 + 4);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,lVar4);
          }
          if ((lVar6 != 0) && (*(longlong *)(lVar4 + 0x18) != 0)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                       &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,lVar4);
            }
            DfscCredTableDelete(*(undefined8 *)(lVar4 + 0x18),lVar4);
          }
          if (*(longlong *)(lVar4 + 0x10) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar4 + 0x10),0);
            *(undefined8 *)(lVar4 + 0x10) = 0;
          }
          if (*(longlong *)(lVar4 + 0x40) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar4 + 0x40),0);
            *(undefined8 *)(lVar4 + 0x40) = 0;
          }
          ExFreePoolWithTag(lVar4,0);
        }
        if (lVar6 != 0) {
          ExReleaseResourceLite(lVar6 + 0x68);
          KeLeaveCriticalRegion();
        }
        *(undefined8 *)(param_1 + 0xe8) = 0;
      }
      lVar4 = *(longlong *)(param_1 + 0x110);
      if (lVar4 != 0) {
        LOCK();
        piVar1 = (int *)(lVar4 + 4);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          lVar6 = *(longlong *)(lVar4 + 0x10);
          if (lVar6 != 0) {
            LOCK();
            piVar1 = (int *)(lVar6 + 4);
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
                WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                          &WPP_af603b4b97893b05877342047baf7746_Traceguids,lVar6,
                          (wchar_t *)(lVar6 + 0x90));
              }
              ExFreePoolWithTag(lVar6,0);
            }
            *(undefined8 *)(lVar4 + 0x10) = 0;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                     &WPP_55706db06074317498eaf8c01331c814_Traceguids,lVar4);
          }
          ExFreePoolWithTag(lVar4,0);
        }
        *(undefined8 *)(param_1 + 0x110) = 0;
      }
      if (*(longlong *)(param_1 + 0xf8) != 0) {
        PsDereferenceSiloContext();
        *(undefined8 *)(param_1 + 0xf8) = 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids,param_1);
      }
      ExFreePoolWithTag(param_1,0);
      return 1;
    }
    pcVar8 = (code *)swi(0x29);
    (*pcVar8)(3);
    puVar9 = auStackY_40;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar9 + -8) = 0x140026a5a;
    WPP_SF_(uVar7,0x11,&WPP_ebcd762151e9386222af4ed73f8d8f74_Traceguids);
  }
  return 1;
}



===== DfscIsReservedShare @ 140026a70 =====

ulonglong DfscIsReservedShare(ushort *param_1)

{
  short sVar1;
  ushort uVar2;
  ulonglong in_RAX;
  ushort uVar3;
  uint uVar4;
  ulonglong uVar5;
  short local_28;
  undefined6 uStack_26;
  undefined8 uStack_20;
  short local_18;
  undefined6 uStack_16;
  undefined *puStack_10;
  
  uVar4 = 0;
  do {
    if (3 < uVar4) {
      return in_RAX & 0xffffffffffffff00;
    }
    uVar5 = (ulonglong)uVar4;
    in_RAX = (ulonglong)(*param_1 >> 1);
    uVar3 = (ushort)(&DAT_14000d080)[uVar5 * 8] >> 1;
    if (uVar3 != 0) {
      do {
        if ((*(short *)((&PTR_u_PIPE_14000d088)[uVar5 * 2] + (ulonglong)uVar3 * 2 + -2) != 0x5c) &&
           (*(short *)((&PTR_u_PIPE_14000d088)[uVar5 * 2] + (ulonglong)uVar3 * 2 + -2) != 0)) break;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    if (*param_1 >> 1 == 0) {
LAB_140026b77:
      if (uVar3 == 0) {
LAB_140026b7c:
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
    }
    else {
      do {
        sVar1 = *(short *)(*(longlong *)(param_1 + 4) + -2 + in_RAX * 2);
        if ((sVar1 != 0x5c) && (sVar1 != 0)) break;
        uVar2 = (short)in_RAX - 1;
        in_RAX = (ulonglong)uVar2;
      } while (uVar2 != 0);
      uVar2 = (ushort)in_RAX;
      if (uVar2 == 0) goto LAB_140026b77;
      if ((uVar2 == uVar3) && (uVar3 != 0)) {
        puStack_10 = (&PTR_u_PIPE_14000d088)[uVar5 * 2];
        _local_18 = CONCAT62((int6)((ulonglong)*(undefined8 *)(&DAT_14000d080 + uVar5 * 8) >> 0x10),
                             uVar3 * 2);
        uStack_20 = *(undefined8 *)(param_1 + 4);
        _local_28 = CONCAT62((int6)((ulonglong)*(undefined8 *)param_1 >> 0x10),uVar2 * 2);
        in_RAX = RtlCompareUnicodeString(&local_18,&local_28,CONCAT71((int7)(uVar5 * 2 >> 8),1));
        if ((int)in_RAX == 0) goto LAB_140026b7c;
      }
    }
    uVar4 = uVar4 + 1;
  } while( true );
}



===== DfscCredCreateKeymgrCredentials @ 140026bb0 =====

ulonglong DfscCredCreateKeymgrCredentials
                    (ushort *param_1,longlong param_2,undefined8 *param_3,undefined8 param_4)

{
  uint uVar1;
  ushort *puVar2;
  ushort uVar3;
  longlong lVar4;
  void *_Dst;
  undefined2 *_Dst_00;
  ulonglong uVar5;
  ushort uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong local_58;
  void *pvStack_50;
  undefined8 local_48;
  void *pvStack_40;
  ulonglong local_38;
  longlong lStack_30;
  
  *param_3 = 0;
  local_58 = 0;
  pvStack_50 = (void *)0x0;
  local_38 = 0;
  lStack_30 = 0;
  RtlInitUnicodeStringEx(&local_58,0);
  RtlInitUnicodeStringEx(&local_38,0);
  uVar3 = *param_1;
  local_48 = 0;
  pvStack_40 = (void *)0x0;
  if (uVar3 == 0) {
    RtlInitUnicodeString(&local_58,0);
  }
  else {
    local_48 = (ulonglong)CONCAT22(uVar3,uVar3);
    lVar4 = (ulonglong)(uVar3 >> 1) * 2;
    uVar8 = (ulonglong)uVar3;
    if (*(short *)(*(longlong *)(param_1 + 4) + -2 + lVar4) != 0) {
      uVar8 = (ulonglong)(uVar3 + 2);
      uVar6 = (ushort)(uVar3 + 2);
      local_48 = (ulonglong)CONCAT22(uVar6,uVar3);
      if (uVar6 < uVar3) {
        uVar8 = 0xc000009a;
        goto LAB_140026dbc;
      }
    }
    _Dst = (void *)ExAllocatePool2(0x102,uVar8 & 0xffff,0x78436644);
    pvStack_40 = _Dst;
    if (_Dst == (void *)0x0) {
      uVar8 = 0xc000009a;
      goto LAB_140026dbc;
    }
    memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)uVar3);
    if (uVar3 < (ushort)uVar8) {
      *(undefined2 *)(lVar4 + (longlong)_Dst) = 0;
    }
    local_58 = local_48;
    pvStack_50 = pvStack_40;
  }
  uVar8 = 0;
  if ((((param_2 != 0) && (puVar2 = (ushort *)(param_2 + 0x38), puVar2 != (ushort *)0x0)) &&
      (*puVar2 != 0)) &&
     ((*(short **)(param_2 + 0x40) != (short *)0x0 && (**(short **)(param_2 + 0x40) != 0)))) {
    uVar5 = DfscCreateNameFromUnicodeString(&local_38,puVar2,0x78436644,param_4);
    uVar8 = uVar5 & 0xffffffff;
    if ((int)uVar5 != 0) goto LAB_140026dbc;
  }
  uVar7 = (ushort)local_58 + 0x17 & 0xfffffffc;
  if (uVar7 < 0x10000) {
    uVar1 = uVar7 + 0x58;
    _Dst_00 = (undefined2 *)ExAllocatePool2(0x42,uVar1,0x78436644);
    if (_Dst_00 == (undefined2 *)0x0) {
      uVar8 = 0xc000009a;
    }
    else {
      memset(_Dst_00,0,(ulonglong)uVar1);
      *_Dst_00 = 0x8104;
      _Dst_00[1] = (short)uVar1;
      *(undefined4 *)(_Dst_00 + 2) = 1;
      *(undefined8 *)(_Dst_00 + 0xc) = 0;
      *(ulonglong *)(_Dst_00 + 4) = local_58;
      *(void **)(_Dst_00 + 8) = pvStack_50;
      *(undefined8 *)(_Dst_00 + 0x2c) = 0x617069636e697250;
      *(undefined1 *)(_Dst_00 + 0x30) = 0x6c;
      *(undefined1 *)((longlong)_Dst_00 + 0x55) = 0xb;
      _Dst_00[0x2b] = (ushort)local_58;
      memmove(_Dst_00 + 0x32,pvStack_50,local_58 & 0xffff);
      *(undefined4 *)(_Dst_00 + 0x28) = 0;
      *(uint *)(_Dst_00 + 0x24) = uVar7;
      if (param_2 != 0) {
        *(undefined4 *)(_Dst_00 + 0x14) = *(undefined4 *)(param_2 + 0x28);
        *(undefined4 *)(_Dst_00 + 0x16) = *(undefined4 *)(param_2 + 0x2c);
        *(undefined4 *)(_Dst_00 + 0x1a) = *(undefined4 *)(param_2 + 0x34);
        *(undefined4 *)(_Dst_00 + 0x18) = *(undefined4 *)(param_2 + 0x30);
      }
      *(ulonglong *)(_Dst_00 + 0x1c) = local_38;
      *(longlong *)(_Dst_00 + 0x20) = lStack_30;
      *param_3 = _Dst_00;
      if ((int)uVar8 == 0) {
        return uVar8;
      }
    }
  }
  else {
    uVar8 = 0xc000000d;
  }
LAB_140026dbc:
  if (pvStack_50 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_50,0);
    pvStack_50 = (void *)0x0;
  }
  if (lStack_30 != 0) {
    ExFreePoolWithTag(lStack_30,0);
  }
  return uVar8;
}



===== DfscCredRelease @ 140026e90 =====

undefined8 DfscCredRelease(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  uVar4 = 0;
  if (lVar3 != 0) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar3 + 0x68,1);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,param_1,
              (char)*(undefined4 *)(param_1 + 4));
  }
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,param_1);
    }
    if ((lVar3 != 0) && (*(longlong *)(param_1 + 0x18) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_dc6425c9357830de2cb01d836e426dd9_Traceguids,param_1);
      }
      DfscCredTableDelete(*(undefined8 *)(param_1 + 0x18),param_1);
    }
    if (*(longlong *)(param_1 + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    if (*(longlong *)(param_1 + 0x40) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x40),0);
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
    ExFreePoolWithTag(param_1,0);
    uVar4 = 1;
  }
  if (lVar3 != 0) {
    ExReleaseResourceLite(lVar3 + 0x68);
    KeLeaveCriticalRegion();
  }
  return uVar4;
}



===== DfscDeleteNetUseConnection @ 140027050 =====

int DfscDeleteNetUseConnection
              (longlong param_1,wchar_t *param_2,uint *param_3,int param_4,undefined4 *param_5,
              uint *param_6,char param_7)

{
  longlong lVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  undefined *puVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined *puVar9;
  short *psVar10;
  undefined *puVar11;
  uint *_Size;
  uint *puVar12;
  wchar_t *pwVar13;
  char local_98 [4];
  uint local_94;
  undefined4 local_90;
  undefined8 local_88;
  ulonglong local_80;
  short *psStack_78;
  wchar_t local_70 [28];
  
  local_88 = 0;
  lVar8 = 0;
  local_70[0] = L'\0';
  local_70[1] = L'\0';
  local_70[2] = L'\0';
  local_70[3] = L'\0';
  local_70[4] = L'\0';
  local_70[5] = L'\0';
  local_70[6] = L'\0';
  local_70[7] = L'\0';
  local_94 = 0;
  local_70[8] = L'\0';
  local_70[9] = L'\0';
  local_70[10] = L'\0';
  local_70[0xb] = L'\0';
  local_70[0xc] = L'\0';
  local_70[0xd] = L'\0';
  local_70[0xe] = L'\0';
  local_70[0xf] = L'\0';
  local_90 = 0;
  local_70[0x10] = L'\0';
  local_70[0x11] = L'\0';
  local_70[0x12] = L'\0';
  local_70[0x13] = L'\0';
  local_70[0x14] = L'\0';
  local_70[0x15] = L'\0';
  local_70[0x16] = L'\0';
  local_70[0x17] = L'\0';
  local_98[0] = '\0';
  local_80 = 0;
  psStack_78 = (short *)0x0;
  _Size = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    _Size = (uint *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,param_2);
  }
  RtlInitUnicodeStringEx(&local_80,0);
  if (param_5 == (undefined4 *)0x0) {
LAB_140027118:
    puVar12 = param_3;
    iVar4 = DfscNetUseGetSearchKey
                      (param_1,(undefined8 *)param_2,(longlong)param_3,&local_88,
                       (undefined8 *)local_70);
    if (iVar4 != 0) goto LAB_140027498;
    KeEnterCriticalRegion();
    puVar11 = &DAT_14000d6e0;
    puVar5 = (undefined *)(param_1 + 0x98);
    if (param_1 == 0) {
      puVar9 = &DAT_14000d6e0;
      puVar5 = (undefined *)0x98;
    }
    else {
      puVar9 = (undefined *)(param_1 + 0x98);
    }
    ExAcquireResourceExclusiveLite(puVar9,1);
    _Size = (uint *)0x0;
    lVar8 = DfscNetUseTableLookup(local_88,local_70,0);
    if (lVar8 == 0) {
      iVar4 = -0x3fffffcc;
    }
    else {
      if ((param_4 != 0) || (*(int *)(lVar8 + 0x90) == 0)) {
        lVar1 = *(longlong *)(lVar8 + 0x70);
        if ((lVar1 != 0) && (*(int *)(lVar1 + 0x34) != 1)) {
          _Size = &local_94;
          uVar6 = DfscCredCreateTargetNameCopy(lVar1,&local_80,_Size);
          uVar2 = local_94;
          iVar4 = (int)uVar6;
          if (iVar4 != 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
              _Size = (uint *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
              WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                        &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar4,(char)local_94);
            }
            if (iVar4 == -0x7ffffffb) {
              *param_6 = uVar2 + 4;
            }
            goto LAB_14002723d;
          }
          local_90 = *(undefined4 *)(*(longlong *)(lVar8 + 0x70) + 0x30);
        }
        DfscNetUseTableDelete(local_88,lVar8);
        puVar12 = (uint *)0x0;
        DfscNetUseRelease(param_1,lVar8,0,'\0');
        if (param_1 != 0) {
          puVar11 = puVar5;
        }
        ExReleaseResourceLite(puVar11);
        KeLeaveCriticalRegion();
        if ((param_7 == '\0') &&
           (iVar4 = DfscImpersonateCaller((longlong)param_3,local_98), iVar4 != 0)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            puVar12 = (uint *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                     &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar4);
          }
          goto LAB_140027498;
        }
        iVar4 = DfscDeleteSymbolicLink(**(undefined2 **)(param_2 + 4));
        if (((iVar4 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
          puVar12 = (uint *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
          WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                    &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar4,param_2);
        }
        iVar4 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          puVar12 = (uint *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
          WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                    &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,lVar8,param_2);
        }
        puVar12 = (uint *)CONCAT71((int7)((ulonglong)puVar12 >> 8),1);
        uVar6 = DfscNetUseRelease(param_1,lVar8,puVar12,'\0');
        lVar8 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          pwVar13 = L"WAS";
          if ((int)uVar6 == 0) {
            pwVar13 = L"WAS NOT";
          }
          puVar12 = (uint *)&WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids;
          WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                   &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,pwVar13);
        }
        if ((int)uVar6 != 0) {
          uVar3 = (ushort)local_80;
          _Size = (uint *)(local_80 & 0xffff);
          if (((((ushort)local_80 != 0) && (psStack_78 != (short *)0x0)) && (*psStack_78 != 0)) &&
             (param_5 != (undefined4 *)0x0)) {
            psVar10 = psStack_78;
            memmove(param_5 + 1,psStack_78,(size_t)_Size);
            *param_5 = local_90;
            *param_6 = uVar3 + 6;
            *(undefined2 *)((longlong)param_5 + (ulonglong)(uVar3 >> 1) * 2 + 4) = 0;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
              WPP_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),psVar10,_Size,
                        (wchar_t *)(param_5 + 1),(char)*param_6);
            }
            goto LAB_14002710b;
          }
        }
        *param_6 = 0;
        if (param_5 != (undefined4 *)0x0) {
          *(undefined2 *)(param_5 + 1) = 0;
          *param_5 = 0;
        }
        goto LAB_140027498;
      }
      iVar4 = -0x7fffffef;
    }
LAB_14002723d:
    if (param_1 != 0) {
      puVar11 = (undefined *)(param_1 + 0x98);
    }
    ExReleaseResourceLite(puVar11);
    KeLeaveCriticalRegion();
  }
  else {
    if (7 < *param_6) {
      local_94 = *param_6 - 4;
      goto LAB_140027118;
    }
    *param_6 = 8;
    iVar4 = -0x7ffffffb;
  }
LAB_14002710b:
  puVar12 = _Size;
LAB_140027498:
  if (local_98[0] != '\0') {
    PsRevertToSelf();
  }
  if (lVar8 != 0) {
    puVar12 = (uint *)0x0;
    DfscNetUseRelease(param_1,lVar8,0,'\0');
  }
  if (psStack_78 != (short *)0x0) {
    ExFreePoolWithTag(psStack_78,0);
    psStack_78 = (short *)0x0;
  }
  lVar8 = param_1;
  uVar7 = DfscGetDriveLetterNetUseTable(param_1);
  DfscNetUseTableDump(lVar8,uVar7,(undefined *)puVar12);
  lVar8 = param_1;
  uVar7 = DfscGetDevicelessNetUseTable(param_1);
  DfscNetUseTableDump(lVar8,uVar7,(undefined *)puVar12);
  lVar8 = DfscGetCredTable(param_1);
  DfscCredTableDump(lVar8,uVar7,(undefined *)puVar12);
  return iVar4;
}



===== DfscGetDevicelessNetUseTable @ 140027530 =====

undefined8 DfscGetDevicelessNetUseTable(longlong param_1)

{
  if (param_1 == 0) {
    return DAT_14000d750;
  }
  return *(undefined8 *)(param_1 + 0x108);
}



===== DfscNetUseGetSearchKey @ 140027550 =====

int DfscNetUseGetSearchKey
              (longlong param_1,undefined8 *param_2,longlong param_3,undefined8 *param_4,
              undefined8 *param_5)

{
  char cVar1;
  wint_t *pwVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  bool bVar5;
  wint_t wVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong local_68 [8];
  
  pwVar2 = (wint_t *)param_2[1];
  if ((pwVar2 == (wint_t *)0x0) || (wVar6 = *pwVar2, wVar6 == 0)) {
    return -0x3ffffff3;
  }
  uVar13 = 1;
  lVar10 = param_3;
  if (((wVar6 == 0x5c) || (pwVar2[1] == 0x5c)) || (pwVar2[1] != 0x3a)) {
    bVar5 = false;
  }
  else {
    wVar6 = towupper(wVar6);
    if ((wVar6 < 0x41) || (0x5a < wVar6)) {
      return -0x3ffffff3;
    }
    bVar5 = true;
  }
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  *param_5 = 0;
  param_5[1] = 0;
  param_5[2] = 0;
  param_5[3] = 0;
  param_5[4] = 0;
  param_5[5] = 0;
  cVar1 = **(char **)(param_3 + 0xb8);
  if ((((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x13')) &&
     (lVar9 = *(longlong *)(*(char **)(param_3 + 0xb8) + 8), lVar9 != 0)) {
    plVar12 = (longlong *)(*(longlong *)(lVar9 + 8) + 0x20);
  }
  else {
    SeCaptureSubjectContext(local_68);
    plVar12 = local_68;
  }
  lVar9 = *plVar12;
  if (lVar9 == 0) {
    lVar9 = plVar12[2];
  }
  puVar11 = param_5 + 2;
  iVar7 = SeQuerySessionIdToken(lVar9);
  if (iVar7 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar7);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar11,lVar10,*(undefined4 *)(param_5 + 2))
    ;
  }
  if (plVar12 == local_68) {
    SeReleaseSubjectContext(local_68);
  }
  if (iVar7 == 0) {
    local_68[4] = 0;
    local_68[5] = 0;
    local_68[6] = 0;
    local_68[7] = 0;
    SeCaptureSubjectContext(local_68 + 4);
    lVar10 = local_68[4];
    if (local_68[4] == 0) {
      lVar10 = local_68[6];
    }
    iVar7 = SeQueryAuthenticationIdToken(lVar10,(longlong)param_5 + 0x14);
    SeReleaseSubjectContext(local_68 + 4);
    if (iVar7 == 0) {
      if (bVar5) {
        if (param_1 == 0) {
          uVar8 = DAT_14000d748;
        }
        else {
          uVar8 = *(undefined8 *)(param_1 + 0x100);
        }
      }
      else {
        uVar8 = DfscGetDevicelessNetUseTable(param_1);
        uVar13 = 0;
      }
      *(undefined4 *)(param_5 + 5) = uVar13;
      uVar3 = *param_2;
      uVar4 = param_2[1];
      *param_4 = uVar8;
      *param_5 = uVar3;
      param_5[1] = uVar4;
    }
  }
  return iVar7;
}



===== DfscNetUseTableDump @ 140027814 =====

void DfscNetUseTableDump(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  
  iVar6 = 0;
  KeEnterCriticalRegion();
  puVar5 = &DAT_14000d6e0;
  puVar4 = (undefined *)(param_1 + 0x98);
  if (param_1 == 0) {
    puVar4 = &DAT_14000d6e0;
  }
  ExAcquireResourceExclusiveLite(puVar4,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    uVar2 = RtlNumberGenericTableElementsAvl(param_2);
    param_3 = &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,uVar2);
  }
  pwVar3 = (wchar_t *)RtlEnumerateGenericTableAvl(param_2,1);
  while (pwVar3 != (wchar_t *)0x0) {
    lVar1 = *(longlong *)(pwVar3 + 0x10);
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
        WPP_SF_dqZq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,param_3,iVar6,(char)lVar1,pwVar3
                    ,(char)*(undefined8 *)(lVar1 + 0x70));
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
        WPP_SF_dDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,param_3,
                    *(undefined4 *)(pwVar3 + 8),(char)*(undefined4 *)(pwVar3 + 0xc),
                    (char)*(undefined4 *)(pwVar3 + 10),(char)*(undefined4 *)(lVar1 + 4));
      }
    }
    pwVar3 = (wchar_t *)RtlEnumerateGenericTableAvl(param_2,0);
    iVar6 = iVar6 + 1;
  }
  if (param_1 != 0) {
    puVar5 = (undefined *)(param_1 + 0x98);
  }
  ExReleaseResourceLite(puVar5);
  KeLeaveCriticalRegion();
  return;
}



===== DfscCredTableDump @ 1400279b4 =====

void DfscCredTableDump(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  int iVar4;
  undefined8 local_18;
  longlong lStack_10;
  
  local_18 = 0;
  lStack_10 = 0;
  iVar4 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0x68,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    uVar2 = RtlNumberGenericTableElementsAvl(param_1);
    param_3 = &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,uVar2);
  }
  lVar3 = RtlEnumerateGenericTableAvl(param_1,1);
  while (lVar3 != 0) {
    lVar3 = *(longlong *)(lVar3 + 0x20);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      lVar1 = *(longlong *)(lVar3 + 0x20);
      param_3 = &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids;
      WPP_SF_dqZdDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_521f112f0c4c3c3f435a4c29cad4d330_Traceguids,iVar4,(char)lVar3,
                     (wchar_t *)(lVar3 + 8),(char)*(undefined4 *)(lVar1 + 0x10),
                     (char)*(undefined4 *)(lVar1 + 0x18),(char)*(undefined4 *)(lVar1 + 0x14),
                     (char)*(undefined4 *)(lVar3 + 4));
    }
    local_18 = CONCAT62(CONCAT42(local_18._4_4_,*(undefined2 *)(lVar3 + 0x56)),
                        *(undefined2 *)(lVar3 + 0x56));
    lStack_10 = (ulonglong)*(byte *)(lVar3 + 0x55) + 0x59 + lVar3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
      WPP_SF_dsZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&local_18,param_3,
                 *(undefined4 *)(lVar3 + 0x48),(char *)(lVar3 + 0x58),(wchar_t *)&local_18);
    }
    lVar3 = RtlEnumerateGenericTableAvl(param_1,0);
    iVar4 = iVar4 + 1;
  }
  ExReleaseResourceLite(param_1 + 0x68);
  KeLeaveCriticalRegion();
  return;
}



===== DfscGetDriveLetterNetUseTable @ 140027b64 =====

undefined8 DfscGetDriveLetterNetUseTable(longlong param_1)

{
  if (param_1 == 0) {
    return DAT_14000d748;
  }
  return *(undefined8 *)(param_1 + 0x100);
}



===== DfscGetEffectiveRequestorSessionId @ 140027b90 =====

int DfscGetEffectiveRequestorSessionId(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  char *pcVar6;
  longlong local_28 [4];
  
  pcVar6 = *(char **)(param_1 + 0xb8);
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  cVar1 = *pcVar6;
  if ((((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x13')) &&
     (*(longlong *)(pcVar6 + 8) != 0)) {
    plVar5 = (longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 8) + 8) + 0x20);
  }
  else {
    SeCaptureSubjectContext(local_28);
    plVar5 = local_28;
  }
  lVar3 = *plVar5;
  if (lVar3 == 0) {
    lVar3 = plVar5[2];
  }
  puVar4 = param_2;
  iVar2 = SeQuerySessionIdToken(lVar3);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_e46d4985b5833ed4089f95e69d42a73f_Traceguids,iVar2);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar4,pcVar6,*param_2);
  }
  if (plVar5 == local_28) {
    SeReleaseSubjectContext(local_28);
  }
  return iVar2;
}



===== DfscConnOpenIpcConnectionCallout @ 140027cc0 =====

void DfscConnOpenIpcConnectionCallout(longlong *param_1)

{
  ulonglong uVar1;
  
  uVar1 = DfscConnOpenIpcConnectionCallin
                    (*param_1,(wchar_t *)param_1[1],(wchar_t *)param_1[2],*(uint *)(param_1 + 3),
                     param_1[4],(char)param_1[6],(uint *)param_1[7],param_1[5]);
  *(int *)(param_1 + 8) = (int)uVar1;
  return;
}



===== DfscConnOpenIpcConnectionCallin @ 140027d10 =====

ulonglong DfscConnOpenIpcConnectionCallin
                    (longlong param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                    longlong param_5,char param_6,uint *param_7,undefined8 param_8)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  char *pcVar6;
  undefined7 extraout_var;
  ulonglong uVar7;
  uint uVar8;
  wchar_t *pwVar9;
  ulonglong uVar10;
  undefined8 *local_res8;
  wchar_t *local_res10;
  uint local_res20 [2];
  undefined8 in_stack_fffffffffffffef0;
  undefined4 uVar14;
  wchar_t **ppwVar11;
  undefined8 **ppuVar12;
  uint *puVar13;
  longlong local_b8;
  wchar_t local_b0;
  undefined1 auStack_ae [6];
  longlong lStack_a8;
  undefined8 local_a0;
  longlong alStack_98 [8];
  wchar_t *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar14 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);
  alStack_98[6] = 0x30;
  local_50 = 0x240;
  local_res10 = (wchar_t *)0x0;
  local_res8 = (undefined8 *)0x0;
  local_b8 = 0;
  lVar5 = 0;
  local_res20[0] = 0;
  alStack_98[7] = 0;
  alStack_98[3] = 1;
  alStack_98[0] = 0;
  local_a0 = 0x28;
  alStack_98[4] = 0;
  alStack_98[5] = 0;
  _local_b0 = 0;
  lStack_a8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  alStack_98[1] = 0;
  alStack_98[2] = 0;
  local_58 = param_2;
  if (param_1 != 0) {
    lVar4 = IoGetSiloParameters(*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30));
    if (lVar4 == 0) {
      alStack_98[3] = 0;
    }
    else {
      alStack_98[3] = *(undefined8 *)(lVar4 + 8);
    }
  }
  if (param_4 != 0) {
    uVar2 = FsRtlAllocateExtraCreateParameterList(0,alStack_98);
    uVar10 = (ulonglong)uVar2;
    if (uVar2 != 0) goto LAB_140027e8d;
  }
  if (((param_3 != (wchar_t *)0x0) && (*param_3 != L'\0')) && ((param_4 & 1) != 0)) {
    ppwVar11 = &local_res10;
    uVar2 = FsRtlAllocateExtraCreateParameter
                      (&GUID_ECP_DOMAIN_SERVICE_NAME_CONTEXT,(ushort)*param_3 + 2,0,0,0x4a436644,
                       ppwVar11);
    uVar14 = (undefined4)((ulonglong)ppwVar11 >> 0x20);
    uVar10 = (ulonglong)uVar2;
    if (uVar2 != 0) goto LAB_140027e8d;
    *local_res10 = *param_3;
    memmove(local_res10 + 1,*(void **)(param_3 + 4),(ulonglong)(ushort)*param_3);
    iVar3 = FsRtlInsertExtraCreateParameter(alStack_98[0],local_res10);
    if (iVar3 == 0) goto LAB_140027dd9;
LAB_140028019:
    uVar10 = 0xc00000e5;
    goto LAB_140027e8d;
  }
LAB_140027dd9:
  if (param_4 != 0) {
    ppuVar12 = &local_res8;
    uVar2 = FsRtlAllocateExtraCreateParameter
                      (&GUID_ECP_NETWORK_OPEN_CONTEXT,0x1c,0,0,0x4a436644,ppuVar12);
    uVar14 = (undefined4)((ulonglong)ppuVar12 >> 0x20);
    uVar10 = (ulonglong)uVar2;
    if (uVar2 != 0) goto LAB_140027e8d;
    *local_res8 = 0;
    local_res8[1] = 0;
    local_res8[2] = 0;
    *(undefined4 *)(local_res8 + 3) = 0;
    *(undefined2 *)local_res8 = 0x1c;
    *(undefined2 *)((longlong)local_res8 + 2) = 0;
    bVar1 = DfscGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities((byte)param_4);
    *(int *)(local_res8 + 1) = (int)CONCAT71(extraout_var,bVar1);
    *(uint *)((longlong)local_res8 + 0xc) = (param_4 & 1) << 3;
    iVar3 = FsRtlInsertExtraCreateParameter(alStack_98[0],local_res8);
    if (iVar3 != 0) goto LAB_140028019;
  }
  uVar2 = 0x4a0;
  if (param_6 == '\0') {
    uVar2 = 0xa0;
  }
  lVar4 = param_5 + 0x50;
  if (param_5 == 0) {
    lVar4 = 0;
    uVar8 = 0;
  }
  else {
    uVar8 = *(uint *)(param_5 + 0x48);
  }
  if (param_7 == (uint *)0x0) {
LAB_140027e13:
    uVar2 = IoCreateFileEx(param_8,0x100000,alStack_98 + 6,alStack_98 + 4,0,CONCAT44(uVar14,0x80),7,
                           3,uVar2,lVar4,uVar8,0,0,0,&local_a0);
    uVar10 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar10 = alStack_98[4] & 0xffffffff;
    }
  }
  else {
    if (param_7[1] == 0) {
      if (param_7 != (uint *)0x0) goto LAB_140028142;
      goto LAB_140027e13;
    }
    puVar13 = local_res20;
    uVar7 = DfscCreateEas('\0',param_5,(void *)((ulonglong)*param_7 + (longlong)param_7),param_7[1],
                          &local_b8,puVar13);
    uVar14 = (undefined4)((ulonglong)puVar13 >> 0x20);
    uVar10 = uVar7 & 0xffffffff;
    if (-1 < (int)uVar7) {
      lVar4 = local_b8;
      lVar5 = local_b8;
      uVar8 = local_res20[0];
LAB_140028142:
      uVar2 = uVar2 | param_7[2];
      goto LAB_140027e13;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_d29483b364bf358e773d59db54935b3a_Traceguids,(int)uVar7);
    }
    lVar5 = local_b8;
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
LAB_140027e8d:
  if (alStack_98[0] != 0) {
    FsRtlFreeExtraCreateParameterList();
  }
  lVar5 = param_5 + 0x50;
  if (param_5 == 0) {
    lVar5 = 0;
  }
  if (lVar5 != 0) {
    lStack_a8 = (ulonglong)*(byte *)(lVar5 + 5) + 9 + lVar5;
    _local_b0 = CONCAT62(CONCAT42(auStack_ae._2_4_,*(undefined2 *)(lVar5 + 6)),
                         *(undefined2 *)(lVar5 + 6));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    pwVar9 = &local_b0;
    if (lVar5 == 0) {
      pwVar9 = (wchar_t *)&DfscDefaultLogString;
      pcVar6 = "<Def>";
    }
    else {
      pcVar6 = (char *)(lVar5 + 8);
    }
    WPP_SF_ZqsZZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,
                  &DfscDefaultLogString,param_2,(char)param_5,pcVar6,pwVar9,param_3,(char)uVar10);
  }
  return uVar10;
}



===== DfscGetNormalizedDriveLetterUnicodeString @ 140028180 =====

undefined8
DfscGetNormalizedDriveLetterUnicodeString
          (wint_t *param_1,uint param_2,wint_t *param_3,undefined8 param_4)

{
  wint_t wVar1;
  
  if ((((param_2 < 6) || (param_1[1] != 0x3a)) || (param_1[2] != 0)) ||
     ((wVar1 = towupper(*param_1), wVar1 < 0x41 || (0x5a < wVar1)))) {
    return 0xc000000d;
  }
  wVar1 = towupper(*param_1);
  param_3[1] = 0x3a;
  param_3[2] = 0;
  *param_3 = wVar1;
  RtlInitUnicodeStringEx(param_4,param_3);
  return 0;
}



===== DfscNetUseTableCompareEntries @ 140028220 =====

bool DfscNetUseTableCompareEntries
               (undefined8 param_1,undefined1 (*param_2) [16],undefined4 *param_3)

{
  wint_t wVar1;
  wint_t wVar2;
  int iVar3;
  
  if ((uint)param_3[4] < *(uint *)param_2[1]) {
    return true;
  }
  if ((uint)param_3[4] <= *(uint *)param_2[1]) {
    if ((*(uint *)(param_2[1] + 4) == param_3[5]) && (*(int *)(param_2[1] + 8) == param_3[6])) {
      if ((*(uint *)(param_2[2] + 8) & 1) == 0) {
        iVar3 = DfscIsPathEqualString(param_2,param_3);
      }
      else {
        wVar1 = towupper(**(wint_t **)(param_3 + 2));
        wVar2 = towupper(**(wint_t **)(*param_2 + 8));
        iVar3 = (uint)wVar2 - (uint)wVar1;
      }
      if (0 < iVar3) {
        return true;
      }
      if (-1 < iVar3) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_dDDZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                      &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,*(undefined4 *)param_2[1],
                      (char)*(undefined4 *)(param_2[1] + 8),(char)*(undefined4 *)(param_2[1] + 4),
                      (wchar_t *)param_2);
        }
        return true;
      }
    }
    else {
      if (*(int *)(param_2[1] + 8) == param_3[6]) {
        return (uint)param_3[5] < *(uint *)(param_2[1] + 4);
      }
      if ((int)param_3[6] < *(int *)(param_2[1] + 8)) {
        return true;
      }
    }
  }
  return false;
}



===== DfscRmGetReferralTtlTickCounts @ 140028330 =====

void DfscRmGetReferralTtlTickCounts(longlong param_1,longlong *param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x28);
  lVar2 = *(longlong *)(param_1 + 0x20);
  if (param_2 != (longlong *)0x0) {
    uVar3 = KeQueryTimeIncrement();
    *param_2 = ((ulonglong)uVar1 * 10000000) / (ulonglong)uVar3 + lVar2;
  }
  if (param_3 != (longlong *)0x0) {
    uVar3 = KeQueryTimeIncrement();
    *param_3 = ((ulonglong)(uVar1 * DAT_14000d79c) * 10000000) / (ulonglong)uVar3 + lVar2;
  }
  return;
}



===== DfscCmValidateState @ 1400283c0 =====

int DfscCmValidateState(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(uint *)(param_1 + 0x124) < 2) {
    lVar1 = *(longlong *)(param_1 + 0x110);
    if (((lVar1 == 0) || ((*(uint *)(lVar1 + 8) & 0xf) != 0)) ||
       ((*(uint *)(param_1 + 0xf0) != 0 &&
        (((lVar1 = *(longlong *)(lVar1 + 0x10), (*(byte *)(lVar1 + 0x10) & 8) == 0 &&
          (*(char *)(lVar1 + 0x14) == '\0')) &&
         ((*(uint *)(param_1 + 0xf0) & ~*(uint *)(lVar1 + 0x18)) != 0)))))) {
      iVar2 = DfscValidateReferral(param_1 + 8,-1,(longlong *)(param_1 + 0x110));
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)iVar2);
      }
      goto LAB_1400283eb;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
  }
LAB_1400283eb:
  *(int *)(param_1 + 0x13c) = iVar2;
  return (iVar2 >> 0x1f & 7U) + 2;
}



===== DfscValidateReferral @ 1400284d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DfscValidateReferral(longlong param_1,int param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 uVar4;
  int iVar5;
  undefined **ppuVar6;
  longlong *plVar7;
  longlong local_48;
  longlong local_40;
  longlong lStack_38;
  longlong local_30;
  undefined4 local_28;
  int iStack_24;
  
  local_30 = *param_3;
  if (param_2 == -1) {
    param_2 = *(int *)(*(longlong *)(local_30 + 0x10) + 0xc);
  }
  _local_28 = 0;
  local_40 = 0;
  lStack_38 = 0;
  plVar7 = param_3;
  local_48 = param_1;
  if (param_2 == 0) {
    ppuVar6 = &DfscValidateDomainStatesTable;
LAB_1400285c4:
    iVar5 = 0;
    do {
      iVar5 = (*(code *)ppuVar6[iVar5])(&local_48);
    } while (iVar5 != -1);
    iVar5 = iStack_24;
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 2) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x10b,2,param_3,(longlong)param_2,0);
      }
      ppuVar6 = (undefined **)&DfscValidateLinkStatesTable;
      goto LAB_1400285c4;
    }
    if ((local_30 == 0) ||
       ((((*(uint *)(local_30 + 8) & 8) != 0 &&
         ((*(byte *)(*(longlong *)(local_30 + 0x10) + 0x10) & 8) != 0)) &&
        (*(char *)(*(longlong *)(local_30 + 0x10) + 0x12) == '\0')))) {
LAB_1400285b4:
      ppuVar6 = &DfscValidateRootStatesTable;
      goto LAB_1400285c4;
    }
    bVar3 = DfscIsKnownDomainName(param_1,(ushort *)(param_1 + 0x68));
    if (!bVar3) goto LAB_1400285b4;
    uVar4 = DfscIsSpecialShare((ushort *)(param_1 + 0x78));
    if ((char)uVar4 == '\0') goto LAB_1400285b4;
    plVar7 = &lStack_38;
    iVar5 = DfscValidateSysvolNetlogonReferral(local_48,&local_30,plVar7);
    if (iVar5 < 0) goto LAB_1400285b4;
    _local_28 = CONCAT44(iVar5,local_28);
  }
  lVar1 = *param_3;
  if (iVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,&local_48,(char)iVar5);
    }
    if ((param_2 == 0) && (iVar5 == -0x3fffffde)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,lVar1);
      }
      DfscReferralRelease(lVar1);
      *param_3 = 0;
    }
    else {
      if (((local_30 == 0) || ((*(uint *)(local_30 + 8) & 0xe) != 0)) ||
         (((*(uint *)(local_48 + 0xe8) != 0 &&
           ((*(byte *)(*(longlong *)(local_30 + 0x10) + 0x10) & 8) == 0)) &&
          ((*(uint *)(local_48 + 0xe8) & ~*(uint *)(*(longlong *)(local_30 + 0x10) + 0x18)) != 0))))
      goto LAB_140028780;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,local_30,(char)iVar5);
      }
    }
    iVar5 = 0;
  }
  else {
    if (lVar1 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
        plVar7 = (longlong *)&WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids;
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,lVar1,(char)lStack_38);
      }
      DfscCopyTargetAccessStatus(lVar1,lStack_38);
      DfscSetMatchingTarget(lVar1,lStack_38,plVar7);
      DfscReferralRelease(lVar1);
    }
    lVar2 = lStack_38;
    if (((*(byte *)(*(longlong *)(lStack_38 + 0x10) + 0x10) & 4) != 0) &&
       ((*(ushort *)(lStack_38 + 0x18) & 4) == 0)) {
      *(ushort *)(lStack_38 + 0x18) = *(ushort *)(lStack_38 + 0x18) | 1;
    }
    lStack_38 = 0;
    *param_3 = lVar2;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_26fa6a0d37ad369cda189c6e0c147b04_Traceguids,lVar1);
    }
  }
LAB_140028780:
  if (local_40 != 0) {
    DfscReferralRelease(local_40);
  }
  if (lStack_38 != 0) {
    DfscReferralRelease(lStack_38);
  }
  return iVar5;
}



===== DfscNetUseTableLookup @ 1400287d0 =====

longlong DfscNetUseTableLookup(undefined8 param_1,wchar_t *param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_3 == 0) {
    lVar1 = RtlLookupElementGenericTableAvl();
  }
  else {
    lVar1 = RtlLookupElementGenericTableFullAvl();
  }
  lVar2 = 0;
  if (lVar1 != 0) {
    lVar2 = *(longlong *)(lVar1 + 0x20);
    LOCK();
    *(int *)(lVar2 + 4) = *(int *)(lVar2 + 4) + 1;
    UNLOCK();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_4cbf8115eb6f3bebf2b1c99b588386c6_Traceguids,param_2,(char)lVar2);
    }
  }
  return lVar2;
}



===== DfscAgeOutExpiredCacheEntries @ 140028860 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DfscAgeOutExpiredCacheEntries(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  
  lVar4 = _DAT_fffff78000000320;
  uVar8 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0x38,1);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1 + 0xa0);
  if (DAT_14000d798 != 0) {
    lVar7 = *(longlong *)(param_1 + 0x20);
    do {
      if (lVar7 == param_1 + 0x18) break;
      lVar1 = lVar7 + -0x30;
      lVar3 = *(longlong *)(lVar7 + 8);
      if (((*(byte *)(lVar7 + -0x20) & 1) != 0) && (*(int *)(lVar7 + -0x2c) < 2)) {
        iVar2 = *(int *)(lVar7 + -8);
        lVar6 = *(longlong *)(lVar7 + -0x10);
        uVar5 = KeQueryTimeIncrement();
        lVar6 = ((ulonglong)(uint)(iVar2 * DAT_14000d79c) * 10000000) / (ulonglong)uVar5 + lVar6;
        if ((lVar6 != 0) && (lVar6 <= lVar4)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
            WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                      &WPP_e4f552137a6436e2731a426bf3a44208_Traceguids,lVar1,
                      (wchar_t *)(lVar7 + 0x60));
          }
          uVar8 = uVar8 + 1;
          DfscRmUnlinkReferral(lVar1);
          DfscRmDereferenceReferral(lVar1);
        }
      }
      lVar7 = lVar3;
    } while (uVar8 < DAT_14000d798);
  }
  ExReleaseResourceLite(param_1 + 0xa0);
  KeLeaveCriticalRegion();
  ExReleaseResourceLite(param_1 + 0x38);
  KeLeaveCriticalRegion();
  return 0;
}



===== DfscGetLogonId @ 140028a10 =====

undefined4 DfscGetLogonId(undefined8 param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong local_28 [4];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  SeCaptureSubjectContext(local_28);
  lVar2 = local_28[0];
  if (local_28[0] == 0) {
    lVar2 = local_28[2];
  }
  uVar1 = SeQueryAuthenticationIdToken(lVar2,param_1);
  SeReleaseSubjectContext(local_28);
  return uVar1;
}



===== DfscCmDoneState @ 140028a80 =====

undefined8 DfscCmDoneState(void)

{
  return 10;
}



===== DfscCmCheckRefTypeState @ 140028a90 =====

undefined8 DfscCmCheckRefTypeState(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(longlong *)(param_1 + 0x110) == 0) ||
     ((iVar1 = *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x110) + 0x10) + 0xc), iVar1 != 2 &&
      (iVar1 != 1)))) {
    uVar2 = 3;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1);
    }
    *(undefined4 *)(param_1 + 0x144) = 1;
    uVar2 = 5;
    if (*(int *)(param_1 + 0x124) == 1) {
      uVar2 = 9;
    }
  }
  *(undefined4 *)(param_1 + 0x13c) = 0;
  return uVar2;
}



===== DfscConnFree @ 140028b30 =====

void DfscConnFree(longlong param_1)

{
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    if (*(longlong *)(param_1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0);
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== DfscReferralIsValid @ 140028ba0 =====

ulonglong DfscReferralIsValid(longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 8);
    in_RAX = (ulonglong)uVar1;
    if (((uVar1 & 0xf) == 0) &&
       ((((param_2 == 0 ||
          (lVar2 = *(longlong *)(param_1 + 0x10), (*(byte *)(lVar2 + 0x10) & 8) != 0)) ||
         (*(char *)(lVar2 + 0x14) != '\0')) || ((param_2 & ~*(uint *)(lVar2 + 0x18)) == 0)))) {
      return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== DfscClose @ 140028be0 =====

undefined4 DfscClose(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) != param_1) {
    uVar1 = 0xc0000010;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== DfscCreate @ 140028c30 =====

undefined4 DfscCreate(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (*(short *)(lVar1 + 0x58) == 0) {
    *(undefined8 *)(lVar1 + 0x18) = param_1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000010;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== DfscConnOpenIpcConnection @ 140028c7c =====

int DfscConnOpenIpcConnection
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined8 param_5,undefined1 param_6,undefined8 param_7,undefined8 param_8)

{
  int iVar1;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_28;
  undefined8 local_20;
  int local_18;
  
  memset(&local_58,0,0x48);
  local_38 = param_5;
  local_30 = param_8;
  local_28 = param_6;
  local_20 = param_7;
  local_58 = param_1;
  local_50 = param_2;
  local_48 = param_3;
  local_40 = param_4;
  iVar1 = KeExpandKernelStackAndCalloutEx
                    (DfscConnOpenIpcConnectionCallout,&local_58,0x6000,0,DAT_14000d778);
  if (iVar1 != 0) {
    local_18 = iVar1;
  }
  return local_18;
}



===== DfscRmIntegratedStringCheck @ 140028d4c =====

ulonglong DfscRmIntegratedStringCheck
                    (longlong param_1,ushort param_2,ulonglong param_3,longlong *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_2;
  if (uVar2 < param_3) {
    uVar1 = param_3 - uVar2;
    if (0xffff < uVar1) {
      uVar1 = 0xffff;
    }
    uVar2 = DfscRmCheckReferralString(param_1 + uVar2,(ushort)uVar1,param_4);
  }
  else {
    uVar2 = param_3 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== DfscRmCheckReferralString @ 140028d8c =====

ulonglong DfscRmCheckReferralString(ulonglong param_1,ushort param_2,longlong *param_3)

{
  ulonglong in_RAX;
  ushort uVar1;
  ushort uVar2;
  
  if (((param_1 & 1) == 0) && (param_2 != 0)) {
    uVar2 = param_2 >> 1;
    uVar1 = 0;
    if (uVar2 != 0) {
      do {
        in_RAX = (ulonglong)uVar1;
        if (*(short *)(param_1 + in_RAX * 2) == 0) break;
        uVar1 = uVar1 + 1;
      } while (uVar1 < uVar2);
    }
    if (uVar1 != uVar2) {
      if (param_3 != (longlong *)0x0) {
        *param_3 = (ulonglong)uVar1 * 2 + 2;
      }
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== DfscRmSendSynchFsctlIrp @ 140028de4 =====

int DfscRmSendSynchFsctlIrp
              (undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  longlong lVar1;
  void *pvVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeInitializeEvent(&local_38,1,0);
  lVar5 = IoGetRelatedDeviceObject(param_2);
  lVar6 = IoAllocateIrp(*(char *)(lVar5 + 0x4c) + '\x01',0);
  if (lVar6 == 0) {
    return -0x3fffff66;
  }
  *(undefined1 *)(lVar6 + 0x40) = 0;
  *(undefined8 *)(lVar6 + 0xc0) = param_2;
  pvVar2 = SystemReserved1[0xf];
  *(char *)(lVar6 + 0x43) = *(char *)(lVar6 + 0x43) + -1;
  *(void **)(lVar6 + 0x98) = pvVar2;
  lVar1 = *(longlong *)(lVar6 + 0xb8);
  *(longlong *)(lVar6 + 0xb8) = lVar1 + -0x48;
  *(longlong *)(lVar1 + -0x20) = lVar5;
  lVar1 = *(longlong *)(lVar6 + 0xb8);
  *(code **)(lVar1 + -0x10) = DfscCmCompletionRoutine;
  *(undefined8 **)(lVar1 + -8) = &local_38;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  lVar1 = *(longlong *)(lVar6 + 0xb8);
  *(undefined4 *)(lVar1 + -0x40) = param_6;
  *(undefined2 *)(lVar1 + -0x48) = 0xd;
  *(undefined8 *)(lVar1 + -0x18) = param_2;
  *(longlong *)(lVar1 + -0x20) = lVar5;
  *(undefined4 *)(lVar1 + -0x38) = param_4;
  *(undefined4 *)(lVar1 + -0x30) = param_1;
  *(undefined8 *)(lVar6 + 8) = 0;
  *(undefined8 *)(lVar6 + 0x70) = param_5;
  *(undefined8 *)(lVar6 + 0x18) = param_3;
  *(undefined4 *)(lVar6 + 0x10) = 0x50;
  iVar4 = IofCallDriver(lVar5,lVar6);
  if (iVar4 == 0x103) {
    iVar4 = FsRtlCancellableWaitForSingleObject(&local_38,0,0);
    if (((iVar4 == -0x3ffffee0) || (iVar4 == -0x3fffffb5)) &&
       ((cVar3 = IoCancelIrp(lVar6), cVar3 == '\0' ||
        (iVar4 = KeReadStateEvent(&local_38), iVar4 == 0)))) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
    }
    iVar4 = *(int *)(lVar6 + 0x30);
  }
  *param_7 = *(undefined4 *)(lVar6 + 0x38);
  IoFreeIrp(lVar6);
  return iVar4;
}



===== DfscCleanup @ 140028fd0 =====

uint DfscCleanup(longlong param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = -(uint)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) !=
                 param_1) & 0xc0000010;
  *(uint *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== DfscRmCheckReferralSyntax @ 14002901c =====

int DfscRmCheckReferralSyntax(longlong param_1,uint param_2,char param_3,int *param_4)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar6;
  ushort uVar7;
  int local_res10 [6];
  
  local_res10[0] = 0;
  iVar4 = 0;
  if (7 < param_2) {
    uVar2 = *(ushort *)(param_1 + 2);
    uVar7 = (short)param_2 - 8;
    *param_4 = (uint)uVar2 * 0x70 + 0xa0;
    iVar6 = 0;
    if (uVar2 == 0) goto LAB_1400290c5;
    puVar1 = (ushort *)(param_1 + 8);
    if ((param_3 != '\x01') || (2 < *puVar1)) {
      uVar3 = *puVar1;
      if (uVar3 == 1) {
        uVar5 = DfscRmCheckReferralSyntaxV1(uVar2,(short *)puVar1,uVar7,local_res10);
        iVar4 = (int)uVar5;
      }
      else if (uVar3 == 2) {
        uVar5 = DfscRmCheckReferralSyntaxV2(uVar2,(short *)puVar1,uVar7,local_res10);
        iVar4 = (int)uVar5;
      }
      else {
        if ((uVar3 != 3) && (uVar3 != 4)) goto LAB_14002903f;
        uVar5 = DfscRmCheckReferralSyntaxV34(uVar2,(short *)puVar1,uVar7,local_res10);
        iVar4 = (int)uVar5;
      }
      if (-1 < iVar4) {
        iVar6 = local_res10[0];
LAB_1400290c5:
        *param_4 = *param_4 + iVar6;
        return iVar4;
      }
      goto LAB_1400290bd;
    }
  }
LAB_14002903f:
  iVar4 = -0x3fffff3d;
LAB_1400290bd:
  *param_4 = 0;
  return iVar4;
}



===== DfscRmCheckReferralSyntaxV34 @ 1400290dc =====

undefined8
DfscRmCheckReferralSyntaxV34(ushort param_1,short *param_2,ushort param_3,undefined4 *param_4)

{
  short sVar1;
  ulonglong uVar2;
  short *psVar3;
  short *psVar4;
  longlong lVar5;
  ushort uVar6;
  ushort uVar7;
  ulonglong uVar8;
  bool bVar9;
  ulonglong local_res10;
  ushort local_res18;
  undefined4 *local_res20;
  
  uVar8 = 0;
  local_res10 = 0;
  *param_4 = 0;
  psVar4 = param_2;
  for (uVar7 = 0; uVar7 < param_1; uVar7 = uVar7 + 1) {
    if (psVar4 < param_2) {
      return 0xc00000c3;
    }
    if (psVar4 + 0x11 < param_2) {
      return 0xc00000c3;
    }
    psVar3 = (short *)((ulonglong)param_3 + (longlong)param_2);
    if (psVar3 <= psVar4) {
      return 0xc00000c3;
    }
    if (psVar3 < psVar4 + 9) {
      return 0xc00000c3;
    }
    uVar6 = psVar4[1];
    if (psVar3 < (short *)((ulonglong)uVar6 + (longlong)psVar4)) {
      return 0xc00000c3;
    }
    if ((*(byte *)(psVar4 + 3) & 2) == 0) {
      bVar9 = uVar6 < 0x22;
    }
    else {
      bVar9 = uVar6 < 0x12;
    }
    if (bVar9) {
      return 0xc00000c3;
    }
    psVar4 = (short *)((ulonglong)uVar6 + (longlong)psVar4);
  }
  sVar1 = *param_2;
  uVar7 = 0;
  psVar4 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  do {
    uVar6 = 0;
    if (param_1 <= uVar7) {
      *local_res20 = (int)uVar8;
      return 0;
    }
    if ((*psVar4 != sVar1) || (2 < (ushort)psVar4[2])) {
      return 0xc00000c3;
    }
    uVar8 = ((ulonglong)local_res18 - (longlong)psVar4) + (longlong)param_2;
    if ((*(byte *)(psVar4 + 3) & 2) == 0) {
      uVar2 = DfscRmIntegratedStringCheck((longlong)psVar4,psVar4[6],uVar8,(longlong *)0x0);
      if ((char)uVar2 == '\0') {
        return 0xc00000c3;
      }
      uVar2 = DfscRmIntegratedStringCheck((longlong)psVar4,psVar4[7],uVar8,(longlong *)0x0);
      if ((char)uVar2 == '\0') {
        return 0xc00000c3;
      }
      uVar2 = DfscRmIntegratedStringCheck((longlong)psVar4,psVar4[8],uVar8,(longlong *)&local_res10)
      ;
      uVar8 = local_res10;
      if ((char)uVar2 == '\0') {
        return 0xc00000c3;
      }
      uVar2 = DfscRmCheckReferralTargetAddressSyntax
                        ((short *)((ulonglong)(ushort)psVar4[8] + (longlong)psVar4),
                         (uint)(local_res10 >> 1) & 0x7fffffff);
      if ((char)uVar2 == '\0') {
        return 0xc00000c3;
      }
    }
    else {
      if (psVar4[7] == 0) {
        bVar9 = psVar4[8] == 0;
      }
      else {
        bVar9 = param_1 == 1;
      }
      if (!bVar9) {
        return 0xc00000c3;
      }
      uVar2 = DfscRmIntegratedStringCheck((longlong)psVar4,psVar4[6],uVar8,(longlong *)&local_res10)
      ;
      if ((char)uVar2 == '\0') {
        return 0xc00000c3;
      }
      if (psVar4[7] == 0) {
        uVar8 = local_res10;
      }
      else {
        uVar2 = DfscRmIntegratedStringCheck((longlong)psVar4,psVar4[8],uVar8,(longlong *)0x0);
        if ((char)uVar2 == '\0') {
          return 0xc00000c3;
        }
        uVar8 = uVar8 - (ushort)psVar4[8];
        lVar5 = (ulonglong)(ushort)psVar4[8] + (longlong)psVar4;
        for (; uVar6 < (ushort)psVar4[7]; uVar6 = uVar6 + 1) {
          uVar2 = DfscRmIntegratedStringCheck(lVar5,0,uVar8,(longlong *)&local_res10);
          if ((char)uVar2 == '\0') {
            return 0xc00000c3;
          }
          lVar5 = lVar5 + local_res10;
          uVar8 = uVar8 - (local_res10 & 0xffff);
        }
        if (uVar6 != psVar4[7]) {
          return 0xc00000c3;
        }
        uVar8 = local_res10;
      }
    }
    uVar7 = uVar7 + 1;
    psVar4 = (short *)((longlong)psVar4 + (ulonglong)(ushort)psVar4[1]);
  } while( true );
}



===== DfscCredVerify @ 1400292f0 =====

int DfscCredVerify(longlong param_1,longlong param_2,ushort *param_3,undefined2 *param_4,
                  longlong param_5)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong local_58;
  longlong local_50;
  ushort local_48 [24];
  
  iVar3 = 0;
  local_50 = 0;
  local_58 = 0;
  local_48[0x10] = 0;
  local_48[0x11] = 0;
  local_48[0x12] = 0;
  local_48[0x13] = 0;
  local_48[0x14] = 0;
  local_48[0x15] = 0;
  local_48[0x16] = 0;
  local_48[0x17] = 0;
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_48[0xc] = 0;
  local_48[0xd] = 0;
  local_48[0xe] = 0;
  local_48[0xf] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  uVar4 = DfscGetPathComponents
                    (param_3,(short *)(local_48 + 0x10),(short *)(local_48 + 8),(short *)local_48,
                     (short *)0x0);
  iVar2 = (int)uVar4;
  if (iVar2 == 0) {
    iVar2 = DfscGetReferralFromPath
                      (param_1,param_4,local_48,1,param_2,&local_50,param_5,(short *)0x0);
    lVar1 = local_50;
    if (iVar2 == 0) {
      do {
        local_58 = 0;
        lVar5 = lVar1;
        uVar4 = DfscReferralIterate(lVar1);
        if ((int)uVar4 != 0) {
          iVar2 = -0x7fffffe6;
          break;
        }
        lVar5 = DfscReferralGetCurrentTarget(lVar5);
        iVar3 = DfscGetIpcConnectionHandle
                          (param_1,(short *)(lVar5 + 0x10),param_4,param_5,&local_58);
        iVar2 = 0;
        if (iVar3 == 0) {
          if (local_58 != 0) {
            DfscReleaseTreeConnectionHandle(local_58);
            local_58 = 0;
          }
          break;
        }
        uVar6 = DfscIsErrorInList(iVar3,0x14000d110,0x1e);
      } while ((char)uVar6 != '\0');
    }
    if (lVar1 != 0) {
      DfscReferralRelease(lVar1);
    }
    if (iVar3 != 0) {
      return iVar3;
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  return iVar2;
}



===== DfscFsctrlGetDomainCache @ 140029444 =====

ulonglong DfscFsctrlGetDomainCache
                    (longlong param_1,short *param_2,uint param_3,uint *param_4,uint param_5,
                    int param_6)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  uint uVar5;
  longlong lVar6;
  ushort uVar7;
  longlong local_38;
  ulonglong local_30;
  short *psStack_28;
  
  local_38 = 0;
  if (((((param_3 < 0xffff) && ((param_3 & 1) == 0)) && (param_2 != (short *)0x0)) &&
      ((param_3 != 0 && (1 < param_5)))) && (param_4 != (uint *)0x0)) {
    if (2 < param_3) {
      uVar1 = 0;
      uVar5 = param_3 >> 1;
      psVar3 = param_2;
      if (uVar5 != 0) {
        do {
          if (*psVar3 == 0) break;
          uVar1 = uVar1 + 1;
          psVar3 = psVar3 + 1;
        } while (uVar1 < uVar5);
      }
      if (uVar5 <= uVar1) goto LAB_1400295d7;
    }
    if (param_3 == 0x1000) {
      lVar6 = 0x7fff;
      psVar3 = param_2;
      do {
        if (*psVar3 == 0) break;
        psVar3 = psVar3 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      if (lVar6 == 0) goto LAB_1400295d7;
      param_3 = (ushort)(-(ushort)(lVar6 != 0) & (short)lVar6 * -2 - 2U) + 2;
    }
    uVar7 = (ushort)param_3;
    local_30 = (ulonglong)CONCAT22(uVar7,uVar7);
    if ((2 < uVar7) && (param_2[(ulonglong)((param_3 & 0xffff) >> 1) - 1] == 0)) {
      local_30 = (ulonglong)CONCAT22(uVar7,uVar7 - 2);
    }
    psStack_28 = param_2;
    uVar4 = DfscGetContainerContextFromIrp(param_1,&local_38);
    if (-1 < (int)uVar4) {
      if (*param_2 == 0) {
        lVar6 = DfscGetDomainCache(local_38);
        iVar2 = DfscGetDomainCacheNames(lVar6,param_1,param_4,param_5);
        uVar4 = CONCAT44(extraout_var,iVar2);
      }
      else if ((*psStack_28 == 0x2a) && (((short)local_30 == 2 || (psStack_28[1] == 0)))) {
        uVar4 = DfscGetActiveDcInfo(param_1,param_4,param_5,local_38);
      }
      else {
        lVar6 = DfscGetDomainCache(local_38);
        uVar4 = DfscGetDcListForDomain(lVar6,&local_30,param_1,param_4,param_5,param_6);
      }
    }
  }
  else {
LAB_1400295d7:
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== DfscCmInterLinkState @ 140029610 =====

undefined8 DfscCmInterLinkState(longlong param_1)

{
  int extraout_EAX;
  ushort uVar1;
  undefined8 uVar2;
  
  uVar2 = 9;
  DfscRewritePath(param_1,(ushort *)(*(longlong *)(param_1 + 0x118) + 0x60),
                  (ushort *)(param_1 + 0xd0),'\0');
  if (*(longlong *)(param_1 + 0x110) != 0) {
    DfscReferralRelease(*(longlong *)(param_1 + 0x110));
    *(undefined8 *)(param_1 + 0x110) = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_05cba1b763293f8d98259e004f8588c9_Traceguids,param_1,(char)extraout_EAX);
  }
  if (-1 < extraout_EAX) {
    uVar2 = 0;
    uVar1 = *(short *)(param_1 + 0x122) + 1;
    *(ushort *)(param_1 + 0x122) = uVar1;
    if (DAT_14000d7ac < uVar1) {
      DAT_14000d7ac = uVar1;
    }
  }
  *(int *)(param_1 + 0x13c) = extraout_EAX;
  return uVar2;
}



===== DfscFsctrlSetDomainNameFlat @ 1400296dc =====

ulonglong DfscFsctrlSetDomainNameFlat
                    (longlong param_1,short *param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  short *psVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong local_res10;
  ushort local_28 [8];
  
  local_res10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  if (((param_3 & 1) == 0) && (param_3 - 1 < 0xfffe)) {
    uVar8 = param_3 >> 1;
    uVar1 = 0;
    if (uVar8 != 0) {
      psVar6 = param_2;
      do {
        if (*psVar6 == 0) break;
        uVar1 = uVar1 + 1;
        psVar6 = psVar6 + 1;
      } while (uVar1 < uVar8);
    }
    if (uVar1 < uVar8) {
      psVar6 = param_2;
      if ((*param_2 == 0x5c) && (psVar6 = param_2 + 1, *psVar6 == 0x5c)) {
        psVar6 = param_2 + 2;
      }
      uVar1 = RtlInitUnicodeStringEx(local_28,psVar6);
      if (uVar1 != 0) {
        return (ulonglong)uVar1;
      }
      puVar3 = DfscCreateDcContext();
      if (puVar3 == (undefined4 *)0x0) {
        return 0xc000009a;
      }
      uVar4 = DfscCreateNameFromUnicodeString((ulonglong *)(puVar3 + 8),local_28,0x6e436644,param_4)
      ;
      uVar7 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        uVar1 = DfscGetContainerContextFromIrp(param_1,&local_res10);
        uVar7 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          lVar5 = DfscGetCurrentDcContext(local_res10);
          if (lVar5 != 0) {
            iVar2 = RtlCompareUnicodeString(lVar5 + 0x20,puVar3 + 8,0);
            if (iVar2 == 0) {
              DfscReleaseDcContext(lVar5);
              goto LAB_14002982b;
            }
            uVar4 = DfscCreateNameFromUnicodeString
                              ((ulonglong *)(puVar3 + 4),(ushort *)(lVar5 + 0x10),0x6e436644,param_4
                              );
            if (-1 < (int)uVar4) {
              uVar4 = DfscCopyDcList((longlong)puVar3,lVar5);
            }
            uVar7 = uVar4 & 0xffffffff;
            DfscReleaseDcContext(lVar5);
            if ((int)uVar4 < 0) goto LAB_14002982b;
          }
          DfscSetCurrentDcContext((longlong)puVar3,local_res10);
        }
      }
LAB_14002982b:
      DfscReleaseDcContext((longlong)puVar3);
      return uVar7;
    }
  }
  return 0xc000000d;
}



===== DfscFsctrlIsValidDriveLetterConnection @ 140029858 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscFsctrlIsValidDriveLetterConnection(longlong param_1,wint_t *param_2,undefined8 param_3)

{
  wint_t wVar1;
  int iVar2;
  undefined1 auStack_68 [32];
  longlong local_48;
  wchar_t local_40 [9];
  undefined4 local_2e;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  local_40[0] = L'\0';
  local_40[1] = L'\0';
  local_40[2] = L'\0';
  local_40[3] = L'\0';
  local_40[4] = L'\0';
  local_40[5] = L'\0';
  local_40[6] = L'\0';
  local_40[7] = L'\0';
  if ((param_2 != (wint_t *)0x0) && (5 < (uint)param_3)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_h(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,*param_2);
    }
    if ((((param_2[1] == 0x3a) && (param_2[2] == 0)) && (wVar1 = towupper(*param_2), 0x40 < wVar1))
       && (wVar1 < 0x5b)) {
      local_40[8] = towupper(*param_2);
      local_2e = 0x3a;
      RtlInitUnicodeStringEx(local_40,local_40 + 8);
      iVar2 = DfscGetContainerContextFromIrp(param_1,&local_48);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = DfscIsValidDriveLetter(local_48,local_40,param_1);
      return iVar2;
    }
  }
  return -0x3ffffff3;
}



===== DfscIsSpecialShare @ 14002996c =====

undefined8 DfscIsSpecialShare(ushort *param_1)

{
  undefined8 in_RAX;
  undefined1 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  do {
    if (1 < uVar2) {
LAB_1400299a9:
      return CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar1);
    }
    in_RAX = DfscCompareStringsIgnoreTrailingChars
                       ((ushort *)(&DAT_14000d0c0 + (ulonglong)uVar2 * 0x10),param_1);
    if ((int)in_RAX != 0) {
      uVar1 = 1;
      goto LAB_1400299a9;
    }
    uVar2 = uVar2 + 1;
  } while( true );
}



===== DfscPolicyReadRegistryParameters @ 1400299c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DfscPolicyReadRegistryParameters(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_128 [32];
  undefined4 local_108;
  undefined4 *local_100;
  undefined4 local_f8;
  uint local_f4 [3];
  wchar_t *local_e8;
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  longlong local_c0;
  uint *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [4];
  int local_94;
  uint local_8c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  _g_OsVersionInfo = 0x11c;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_f4[0] = 0;
  local_c4 = 0;
  local_ac = 0;
  local_f4[2] = 0;
  RtlGetVersion(&g_OsVersionInfo);
  local_f4[1] = 0x6e006e;
  local_c0 = 0;
  local_b0 = 0x240;
  local_c8 = 0x30;
  DAT_14000d784 = (uint)((byte)(DAT_14000d53a - 2U) < 2);
  local_e8 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Mup";
  local_b8 = local_f4 + 1;
  local_a8 = 0;
  uStack_a0 = 0;
  iVar1 = ZwOpenKey(&local_d8,0x20019,&local_c8);
  if (-1 < iVar1) {
    local_e8 = L"DisableDfs";
    local_f4[1] = 0x140014;
    uVar2 = DfscGetUlongRegistryParameter(local_d8,local_f4 + 1,local_f4);
    if ((-1 < (int)uVar2) && (local_f4[0] != 0)) {
      DAT_14000d780 = 1;
    }
  }
  local_c8 = 0x30;
  local_b8 = (uint *)&DAT_14000d768;
  local_c0 = 0;
  local_b0 = 0x240;
  local_a8 = 0;
  uStack_a0 = 0;
  iVar1 = ZwOpenKey(&local_e0,0x20019,&local_c8);
  if (-1 < iVar1) {
    local_e8 = L"MaxReferralTTLInSeconds";
    local_100 = &local_f8;
    local_f4[1] = 0x2e002e;
    local_f8 = 0;
    local_108 = 0x60;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      DAT_14000d788 = local_8c;
      local_f4[0] = local_8c;
    }
    local_e8 = L"MaxDomainTTLInSeconds";
    local_100 = &local_f8;
    local_f4[1] = 0x2a002a;
    local_108 = 0x60;
    local_f8 = 0;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      DAT_14000d78c = local_8c;
      local_f4[0] = local_8c;
    }
    local_e8 = L"ReferralTTLMultiplier";
    local_100 = &local_f8;
    local_f4[1] = 0x2a002a;
    local_108 = 0x60;
    local_f8 = 0;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      local_f4[0] = local_8c;
      if (local_8c == 0) {
        DAT_14000d79c = 1;
      }
      else {
        DAT_14000d79c = local_8c;
        if (0x400 < local_8c) {
          DAT_14000d79c = 0x400;
        }
      }
    }
    local_e8 = L"DomainTTLMultiplier";
    local_100 = &local_f8;
    local_f4[1] = 0x260026;
    local_108 = 0x60;
    local_f8 = 0;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      local_f4[0] = local_8c;
      if (local_8c == 0) {
        _DAT_14000d790 = 1;
      }
      else {
        _DAT_14000d790 = local_8c;
        if (0x400 < local_8c) {
          _DAT_14000d790 = 0x400;
        }
      }
    }
    local_e8 = L"MaxReferralCacheKBytes";
    local_100 = &local_f8;
    local_f4[1] = 0x2c002c;
    local_108 = 0x60;
    local_f8 = 0;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      local_f4[0] = local_8c;
      if ((local_8c <= local_8c << 10) && (DAT_14000d7a0 = local_8c, local_8c - 1 < 0xf)) {
        DAT_14000d7a0 = 0x10;
      }
    }
    local_e8 = L"MaxDomainCacheKBytes";
    local_100 = &local_f8;
    local_f4[1] = 0x280028;
    local_108 = 0x60;
    local_f8 = 0;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      local_f4[0] = local_8c;
      if ((local_8c <= local_8c << 10) && (_DAT_14000d7a4 = local_8c, local_8c - 1 < 0xf)) {
        _DAT_14000d7a4 = 0x10;
      }
    }
    local_e8 = L"ScavengerThreadIntervalSeconds";
    local_100 = &local_f8;
    local_f4[1] = 0x3c003c;
    local_108 = 0x60;
    local_f8 = 0;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      DAT_14000d794 = local_8c;
      local_f4[0] = local_8c;
      if (local_8c - 1 < 0x1d) {
        DAT_14000d794 = 0x1e;
      }
    }
    local_e8 = L"MaxEntriesDeletedPerInterval";
    local_100 = &local_f8;
    local_f4[1] = 0x380038;
    local_108 = 0x60;
    local_f8 = 0;
    iVar1 = ZwQueryValueKey(local_e0,local_f4 + 1,2,local_98);
    if ((-1 < iVar1) && (local_94 == 4)) {
      if (local_8c == 0) {
        local_8c = 1;
      }
      DAT_14000d798 = local_8c;
      local_f4[0] = local_8c;
    }
  }
  if (local_d8 != 0) {
    local_c0 = local_d8;
    local_e8 = L"Parameters";
    local_b8 = local_f4 + 1;
    local_f4[1] = 0x140014;
    local_c8 = 0x30;
    local_b0 = 0x240;
    local_a8 = 0;
    uStack_a0 = 0;
    iVar1 = ZwOpenKey(&local_d0,0x20019,&local_c8);
    if (-1 < iVar1) {
      local_e8 = L"EnableDfsLoopbackTargets";
      local_f4[1] = 0x300030;
      uVar2 = DfscGetUlongRegistryParameter(local_d0,local_f4 + 1,local_f4);
      if (-1 < (int)uVar2) {
        DAT_14000d784 = (uint)(local_f4[0] != 0);
      }
    }
    if (local_d8 != 0) {
      ZwClose();
    }
  }
  if (local_e0 != 0) {
    ZwClose();
  }
  if (local_d0 != 0) {
    ZwClose();
  }
  return;
}



===== DfscNetUseCopyEnumEntry @ 140029f90 =====

undefined8 DfscNetUseCopyEnumEntry(longlong param_1,longlong param_2,uint param_3,int *param_4)

{
  ushort uVar1;
  wint_t wVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  uVar6 = 0;
  lVar7 = 0xc;
  if (0xb < param_3) {
    if (*(wint_t *)(param_1 + 0x68) == 0) {
      uVar3 = 0;
    }
    else {
      lVar7 = 0x12;
      if (param_3 < 0x12) goto LAB_14002a00e;
      wVar2 = towupper(*(wint_t *)(param_1 + 0x68));
      *(wint_t *)(param_2 + 0xc) = wVar2;
      uVar3 = 6;
      *(undefined4 *)(param_2 + 0xe) = 0x3a;
    }
    *(undefined4 *)(param_2 + 4) = uVar3;
    uVar1 = *(ushort *)(param_1 + 0x58);
    if ((ulonglong)uVar1 + 4 + lVar7 <= (ulonglong)param_3) {
      *(undefined2 *)(lVar7 + param_2) = 0x5c;
      memmove((void *)(param_2 + 2 + lVar7),*(void **)(param_1 + 0x60),(ulonglong)uVar1);
      uVar5 = uVar1 + 2 + (int)lVar7;
      *(undefined2 *)((ulonglong)uVar5 + param_2) = 0;
      *(uint *)(param_2 + 8) = uVar1 + 4;
      iVar4 = uVar5 + 2;
      goto LAB_14002a059;
    }
  }
LAB_14002a00e:
  uVar6 = 0x80000005;
  iVar4 = (-(uint)(*(short *)(param_1 + 0x68) != 0) & 6) + 0x10 + (uint)*(ushort *)(param_1 + 0x58);
LAB_14002a059:
  *param_4 = iVar4;
  return uVar6;
}



===== DfscRmEquivalentReferral @ 14002a088 =====

undefined1 DfscRmEquivalentReferral(longlong param_1,longlong param_2)

{
  longlong *_Base;
  ushort uVar1;
  void *_Base_00;
  undefined8 uVar2;
  byte bVar3;
  longlong *plVar4;
  ulonglong _NumOfElements;
  ushort uVar5;
  byte bVar6;
  longlong lVar7;
  ulonglong uVar8;
  ushort uVar9;
  undefined1 uVar10;
  longlong local_res8;
  longlong local_res10;
  
  uVar1 = *(ushort *)(param_1 + 0x1c);
  _NumOfElements = (ulonglong)uVar1;
  if (uVar1 == *(ushort *)(param_2 + 0x1c)) {
    bVar3 = (byte)*(undefined2 *)(param_1 + 0x10);
    bVar6 = (byte)*(undefined2 *)(param_2 + 0x10);
    if ((((((bVar3 ^ bVar6) & 4) == 0) && (((bVar3 ^ bVar6) & 8) == 0)) &&
        (*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18))) &&
       (*(char *)(param_1 + 0x13) == *(char *)(param_2 + 0x13))) {
      if ((uVar1 == 0) && (*(ushort *)(param_2 + 0x1c) == 0)) {
        return 1;
      }
      if ((uVar1 < 3) ||
         (_Base_00 = (void *)ExAllocatePool2(0x102,_NumOfElements << 4,0x41436644),
         _Base_00 == (void *)0x0)) {
        uVar5 = 0;
        do {
          if (uVar1 <= uVar5) {
            return 1;
          }
          uVar9 = 0;
          local_res10 = (ulonglong)uVar5 * 0x70 + 0xa0 + param_1;
          while( true ) {
            if (uVar1 <= uVar9) {
              return 0;
            }
            local_res8 = (ulonglong)uVar9 * 0x70 + 0xa0 + param_2;
            uVar2 = DfscRmReferralTargetSortFunc(&local_res10,&local_res8);
            if ((int)uVar2 == 0) break;
            uVar9 = uVar9 + 1;
          }
          uVar5 = uVar5 + 1;
        } while( true );
      }
      _Base = (longlong *)((longlong)_Base_00 + _NumOfElements * 8);
      lVar7 = param_2 + 0xa0;
      plVar4 = _Base;
      uVar8 = _NumOfElements;
      do {
        *(longlong *)(((longlong)_Base_00 - (longlong)_Base) + (longlong)plVar4) =
             (param_1 - param_2) + lVar7;
        *plVar4 = lVar7;
        lVar7 = lVar7 + 0x70;
        plVar4 = plVar4 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      qsort(_Base_00,_NumOfElements,8,DfscRmReferralTargetSortFunc);
      qsort(_Base,_NumOfElements,8,DfscRmReferralTargetSortFunc);
      uVar10 = 1;
      uVar5 = 0;
      do {
        if (uVar1 <= uVar5) {
LAB_14002a1cf:
          ExFreePoolWithTag(_Base_00,0);
          return uVar10;
        }
        uVar2 = DfscRmReferralTargetSortFunc
                          ((longlong *)((longlong)_Base_00 + (ulonglong)uVar5 * 8),_Base + uVar5);
        if ((int)uVar2 != 0) {
          uVar10 = 0;
          goto LAB_14002a1cf;
        }
        uVar5 = uVar5 + 1;
      } while( true );
    }
  }
  return 0;
}



===== DfscGetDcListForDomain @ 14002a270 =====

undefined8
DfscGetDcListForDomain
          (longlong param_1,undefined8 param_2,longlong param_3,uint *param_4,uint param_5,
          int param_6)

{
  undefined2 *puVar1;
  ushort uVar2;
  ushort uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined2 uVar6;
  longlong lVar7;
  uint uVar8;
  int iVar10;
  uint uVar9;
  ushort *puVar11;
  ulonglong uVar12;
  
  lVar7 = 0;
  if (param_4 == (uint *)0x0) {
    uVar4 = 0xc000000d;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(param_1 + 0x38,1);
    lVar5 = RtlFindUnicodePrefix(param_1,param_2,0);
    if (lVar5 != 0) {
      lVar7 = lVar5 + -0x48;
      if ((*(byte *)(lVar5 + -0x38) & 1) == 0) {
        lVar7 = 0;
      }
      else {
        LOCK();
        *(int *)(lVar5 + -0x44) = *(int *)(lVar5 + -0x44) + 1;
        UNLOCK();
      }
    }
    ExReleaseResourceLite(param_1 + 0x38);
    KeLeaveCriticalRegion();
    if (lVar7 == 0) {
      uVar4 = 0xc000003a;
    }
    else {
      uVar2 = *(ushort *)(lVar7 + 0x1c);
      uVar9 = 2;
      if (uVar2 != 0) {
        puVar11 = (ushort *)(lVar7 + 0x100);
        uVar12 = (ulonglong)uVar2;
        do {
          uVar3 = *puVar11;
          puVar11 = puVar11 + 0x38;
          iVar10 = uVar3 + uVar9 + 4;
          if (param_6 != 0x60144) {
            iVar10 = uVar3 + uVar9;
          }
          uVar9 = iVar10 + 4;
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
      }
      if (param_5 < uVar9) {
        if (param_5 < 4) {
          uVar4 = 0xc0000023;
        }
        else {
          *param_4 = uVar9;
          uVar4 = 0x80000005;
          *(undefined8 *)(param_3 + 0x38) = 4;
        }
        DfscRmDereferenceReferral(lVar7);
      }
      else {
        uVar8 = 0;
        if (uVar2 != 0) {
          do {
            uVar6 = 0x2b;
            if (uVar8 != *(ushort *)(lVar7 + 0x1e)) {
              uVar6 = 0x2d;
            }
            *(undefined2 *)param_4 = uVar6;
            lVar5 = (ulonglong)uVar8 * 0x70;
            memmove((undefined2 *)((longlong)param_4 + 2),*(void **)(lVar5 + 0x108 + lVar7),
                    (ulonglong)*(ushort *)(lVar5 + 0x100 + lVar7));
            puVar1 = (undefined2 *)((longlong)param_4 + 2) +
                     (*(ushort *)(lVar5 + 0x100 + lVar7) >> 1);
            *puVar1 = 0;
            param_4 = (uint *)(puVar1 + 1);
            if (param_6 == 0x60144) {
              *param_4 = *(uint *)(lVar5 + 0xa8 + lVar7);
              param_4 = (uint *)(puVar1 + 3);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(ushort *)(lVar7 + 0x1c));
        }
        *(undefined2 *)param_4 = 0;
        DfscRmDereferenceReferral(lVar7);
        *(ulonglong *)(param_3 + 0x38) = (ulonglong)uVar9;
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



===== DfscRefreshBootstrapDCAndGetDCReferral @ 14002a448 =====

uint DfscRefreshBootstrapDCAndGetDCReferral
               (longlong *param_1,longlong param_2,wchar_t *param_3,undefined8 *param_4)

{
  char cVar1;
  uint uVar2;
  undefined8 local_28;
  void *pvStack_20;
  
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  RtlInitUnicodeString(&local_28,0);
  pvStack_20 = (void *)ExAllocatePool2(0x102,0x208,0x4d436644);
  if (pvStack_20 == (void *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    local_28 = CONCAT44(local_28._4_4_,0x2080000);
    uVar2 = DfscGetDCName(0,&local_28,0x11);
    if (-1 < (int)uVar2) {
      if (param_2 != 0) {
        cVar1 = RtlEqualUnicodeString(param_2,&local_28,1);
        if (cVar1 != '\0') {
          uVar2 = 0xc0000001;
          goto LAB_14002a53f;
        }
      }
      uVar2 = DfscGetDomainDCReferral(param_1,(ushort *)&local_28,param_3,param_4);
      if (-1 < (int)uVar2) {
        DfscFsctrlSetDcName(param_1[0x1f],pvStack_20,(ushort)local_28 + 2,'\0',param_1[0x1e]);
      }
    }
  }
LAB_14002a53f:
  if (pvStack_20 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_20,0);
  }
  return uVar2;
}



===== DfscFsctrlCreateDriveLetter @ 14002a580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

ulonglong DfscFsctrlCreateDriveLetter(longlong param_1,char *param_2,uint param_3)

{
  wint_t *pwVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  uint *puVar8;
  longlong lVar9;
  wint_t wVar10;
  uint uVar11;
  int iVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  uint uVar16;
  short sVar17;
  undefined2 uVar18;
  uint uVar19;
  longlong lVar20;
  undefined2 *puVar21;
  uint uVar22;
  undefined2 **ppuVar23;
  ushort *puVar24;
  undefined4 uVar25;
  wint_t *pwVar26;
  ushort *puVar27;
  undefined1 auStackY_188 [32];
  int local_138;
  undefined2 *local_128;
  wchar_t *local_120;
  longlong local_118;
  undefined2 *local_110;
  wchar_t *pwStack_108;
  uint local_100;
  uint *local_f8;
  wint_t *local_f0;
  wint_t *local_e8;
  longlong local_e0;
  ushort local_d8;
  ushort local_d6;
  undefined4 local_d4;
  wint_t *local_d0;
  undefined2 local_c8;
  undefined2 local_c6;
  undefined4 local_c4;
  wint_t *local_c0;
  ushort local_b8 [8];
  undefined8 local_a8;
  undefined8 uStack_a0;
  wchar_t local_98 [36];
  short *psStack_50;
  wint_t local_48 [4];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_188;
  local_128 = (undefined2 *)0x0;
  local_d4 = 0;
  local_c4 = 0;
  local_138 = 0;
  local_e8 = (wint_t *)0x0;
  local_f8 = (uint *)0x0;
  local_118 = 0;
  local_b8[0] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  local_b8[6] = 0;
  local_b8[7] = 0;
  local_110 = (undefined2 *)0x0;
  pwStack_108 = (wchar_t *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98[0] = L'\0';
  local_98[1] = L'\0';
  local_98[2] = L'\0';
  local_98[3] = L'\0';
  local_98[4] = L'\0';
  local_98[5] = L'\0';
  local_98[6] = L'\0';
  local_98[7] = L'\0';
  local_98[8] = L'\0';
  local_98[9] = L'\0';
  local_98[10] = L'\0';
  local_98[0xb] = L'\0';
  local_98[0xc] = L'\0';
  local_98[0xd] = L'\0';
  local_98[0xe] = L'\0';
  local_98[0xf] = L'\0';
  local_98[0x10] = L'\0';
  local_98[0x11] = L'\0';
  local_98[0x12] = L'\0';
  local_98[0x13] = L'\0';
  local_98[0x14] = L'\0';
  local_98[0x15] = L'\0';
  local_98[0x16] = L'\0';
  local_98[0x17] = L'\0';
  local_98[0x18] = L'\0';
  local_98[0x19] = L'\0';
  local_98[0x1a] = L'\0';
  local_98[0x1b] = L'\0';
  local_98[0x1c] = L'\0';
  local_98[0x1d] = L'\0';
  local_98[0x1e] = L'\0';
  local_98[0x1f] = L'\0';
  local_98[0x20] = L'\0';
  local_98[0x21] = L'\0';
  local_98[0x22] = L'\0';
  local_98[0x23] = L'\0';
  psStack_50 = (short *)0x0;
  if (param_3 < 0x18) {
    return 0xc000000d;
  }
  local_100 = param_3 - 0x16;
  if ((param_3 & 1) != 0) {
    return 0xc000000d;
  }
  if ((int)param_3 < 0) {
    return 0xc000000d;
  }
  if (param_2 == (char *)0x0) {
    return 0xc000000d;
  }
  uVar3 = *(ushort *)(param_2 + 10);
  if (uVar3 == 0) {
    return 0xc000000d;
  }
  uVar4 = *(ushort *)(param_2 + 8);
  if ((uVar4 & 1) != 0) {
    return 0xc000000d;
  }
  if ((uVar3 & 1) != 0) {
    return 0xc000000d;
  }
  uVar5 = *(ushort *)(param_2 + 0xc);
  uVar15 = (ulonglong)uVar5;
  if ((uVar5 & 1) != 0) {
    return 0xc000000d;
  }
  uVar6 = *(ushort *)(param_2 + 0xe);
  if ((uVar6 & 1) != 0) {
    return 0xc000000d;
  }
  uVar7 = *(ushort *)(param_2 + 0x10);
  if ((uVar7 & 1) != 0) {
    return 0xc000000d;
  }
  if (uVar4 == 0xffff) {
    return 0xc000000d;
  }
  if (uVar3 == 0xffff) {
    return 0xc000000d;
  }
  if (uVar5 == 0xffff) {
    return 0xc000000d;
  }
  if (uVar6 == 0xffff) {
    return 0xc000000d;
  }
  if (uVar7 == 0xffff) {
    return 0xc000000d;
  }
  if (local_100 <
      (uint)*(ushort *)(param_2 + 0x14) + (uint)uVar7 + (uint)uVar5 + (uint)uVar4 + (uint)uVar3 +
      (uint)*(ushort *)(param_2 + 0x12)) {
    return 0xc000000d;
  }
  if ((uVar6 != 0) && (uVar15 <= (ulonglong)uVar6 + 2)) {
    return 0xc000000d;
  }
  local_e0 = param_1;
  uVar11 = DfscGetContainerContextFromIrp(param_1,&local_118);
  if ((int)uVar11 < 0) {
    return (ulonglong)uVar11;
  }
  uVar3 = *(ushort *)(param_2 + 8);
  pwVar1 = (wint_t *)(param_2 + 0x16);
  if (uVar3 == 0) {
    local_f0 = (wint_t *)0x0;
  }
  else {
    if (*(short *)(param_2 + 0x18) != 0x3a) {
      return 0xc00000be;
    }
    if (*(short *)(param_2 + 0x1a) != 0) {
      return 0xc00000be;
    }
    local_f0 = pwVar1;
    wVar10 = towupper(*pwVar1);
    if (wVar10 < 0x41) {
      return 0xc00000be;
    }
    if (0x5a < wVar10) {
      return 0xc00000be;
    }
    local_48[0] = towupper(*pwVar1);
    local_48[1] = 0x3a;
    local_48[2] = 0;
    RtlInitUnicodeStringEx(local_b8,local_48);
  }
  uVar4 = *(ushort *)(param_2 + 10);
  uVar5 = *(ushort *)(param_2 + 0xc);
  local_120 = (wchar_t *)(pwVar1 + (uVar3 >> 1));
  if (uVar5 == 0) {
    pwVar26 = (wint_t *)0x0;
  }
  else {
    pwVar26 = pwVar1 + ((uint)uVar3 + (uint)uVar4 >> 1);
  }
  uVar19 = (uint)*(ushort *)(param_2 + 0x10);
  uVar11 = (uint)uVar3 + (uint)uVar4 + (uint)uVar5;
  if (*(ushort *)(param_2 + 0x10) == 0) {
    local_c0 = (wint_t *)0x0;
    uVar19 = 0;
    if (pwVar26 == (wint_t *)0x0) {
      local_138 = 2;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
        sVar17 = 0x11;
        goto LAB_14002a86c;
      }
    }
    else if ((((uVar5 == 2) && ((byte)(param_2[2] & (byte)uVar5) != 0)) &&
             (local_138 = 1, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      sVar17 = uVar5 + 0x10;
LAB_14002a86c:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),sVar17,
              &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids);
      local_c0 = (wint_t *)0x0;
    }
  }
  else {
    local_c0 = pwVar1 + (uVar11 >> 1);
    if (((pwVar26 != (wint_t *)0x0) &&
        (local_138 = 1, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids);
    }
  }
  uVar3 = *(ushort *)(param_2 + 0x12);
  local_c8 = (undefined2)uVar19;
  uVar11 = uVar11 + uVar19;
  if (uVar3 != 0) {
    local_138 = 1;
    local_e8 = pwVar1 + (uVar11 >> 1);
  }
  uVar11 = (uVar3 + 0x25 + uVar11 & 0xfffffff0) - 0x16;
  if (*(short *)(param_2 + 0x14) != 0) {
    if (*(short *)(param_2 + 0x14) == 0x10) {
      local_f8 = (uint *)(pwVar1 + (uVar11 >> 1));
      if (*(int *)(param_2 + (ulonglong)(uVar11 >> 1) * 2 + 0x1e) != 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000000d;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
          return 0xc000000d;
        }
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,
                  *(int *)(param_2 + (ulonglong)(uVar11 >> 1) * 2 + 0x1e),0xd);
        return 0xc000000d;
      }
      uVar19 = *local_f8 + uVar11;
      if (uVar19 < uVar11) {
        uVar15 = 0xc0000095;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000095;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
          return 0xc0000095;
        }
        uVar18 = 0x15;
        uVar25 = 0xc0000095;
        goto LAB_14002a8fd;
      }
      if (local_f8[1] + uVar19 < uVar19) {
        uVar15 = 0xc0000095;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000095;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
          return 0xc0000095;
        }
        uVar18 = 0x16;
        uVar25 = 0xc0000095;
        goto LAB_14002a8fd;
      }
      uVar15 = 0;
      if (local_f8[1] + uVar19 <= local_100) goto LAB_14002aa2e;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
        return 0xc000000d;
      }
      uVar18 = 0x17;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
        return 0xc000000d;
      }
      uVar18 = 0x13;
    }
    uVar15 = 0xc000000d;
    uVar25 = 0xc000000d;
LAB_14002a8fd:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar18,
             &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,uVar25);
    return uVar15;
  }
LAB_14002aa2e:
  if (uVar5 == 0) {
    local_d8 = 0;
  }
  else {
    local_d8 = uVar5 - 2;
  }
  if ((((ushort)(uVar4 - 2) < 4) || (*local_120 != L'\\')) ||
     (pwStack_108 = local_120 + 1, local_120[1] != L'\\')) {
    return 0xc000000d;
  }
  local_110 = (undefined2 *)
              CONCAT62(CONCAT42((int)((ulonglong)local_110 >> 0x20),uVar4 - 2),uVar4 - 4);
  local_d6 = uVar5;
  local_d0 = pwVar26;
  local_c6 = local_c8;
  uVar13 = DfscInitDfsPath((wchar_t *)&local_110,(short *)&local_a8);
  if ((int)uVar13 != 0) {
    return 0xc00000be;
  }
  if ((wchar_t)local_a8 == (wchar_t)uVar13) {
    return 0xc00000be;
  }
  if (local_98[0] == (wchar_t)uVar13) {
    return 0xc00000be;
  }
  if ((ushort)local_98[0x20] < 2) {
    return 0xc00000be;
  }
  if (*psStack_50 != 0x5c) {
    return 0xc00000be;
  }
  uVar14 = DfscIsReservedShare((ushort *)local_98);
  if ((char)uVar14 != '\0') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000be;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0) {
      return 0xc00000be;
    }
    WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,0xc00000be,local_98);
    return 0xc00000be;
  }
  if (local_138 == 2) {
    ppuVar23 = &local_128;
    uVar15 = DfscCredCreateKeymgrCredentials((ushort *)&local_a8,0,ppuVar23,uVar15);
    puVar21 = local_128;
    iVar12 = (int)uVar15;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
      ppuVar23 = (undefined2 **)&WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids;
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,local_128,(char)uVar15);
    }
  }
  else {
    ppuVar23 = (undefined2 **)&local_c8;
    uVar15 = DfscCredCreateExplicitCredentials
                       (&local_d8,*(short *)(param_2 + 0xe),(ushort *)ppuVar23,(ushort *)&local_a8,
                        *(undefined4 *)(param_2 + 4),local_e8,(uint)uVar3,(uint)(local_138 == 1),
                        (uint)*(ushort *)(param_2 + 2),&local_128);
    iVar12 = (int)uVar15;
    puVar21 = local_128;
  }
  lVar9 = local_e0;
  puVar8 = local_f8;
  uVar15 = uVar15 & 0xffffffff;
  if (iVar12 != 0) goto LAB_14002ae24;
  cVar2 = *param_2;
  uVar11 = (cVar2 != '\0') + 1;
  if ((param_2[2] & 8U) == 0) {
    ppuVar23 = &local_110;
    uVar19 = DfscCredVerify(local_e0,local_118,(ushort *)ppuVar23,puVar21,(longlong)local_f8);
  }
  else {
    uVar19 = 0xc00000be;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x16 & 1) != 0)) {
    WPP_SF_DZDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(ushort *)(param_2 + 2),
                ppuVar23,uVar19,(wchar_t *)&local_110,(char)*(ushort *)(param_2 + 2),(char)uVar11);
  }
  if (uVar19 == 0) {
LAB_14002acb6:
    uVar3 = *(ushort *)(param_2 + 2);
    uVar16 = uVar3 >> 4 & 2;
    uVar22 = uVar16 | 4;
    if ((uVar3 & 0x40) == 0) {
      uVar22 = uVar16;
    }
    if ((uVar22 == 0) || (local_f0 != (wint_t *)0x0)) {
      if (-1 < (char)uVar3) {
        puVar27 = local_b8;
        if (local_f0 == (wint_t *)0x0) {
          puVar27 = (ushort *)0x0;
        }
        lVar20 = lVar9;
        puVar24 = puVar27;
        uVar16 = DfscCreateNetUseConnection
                           (local_118,lVar9,puVar27,(wchar_t *)&local_a8,(longlong)puVar21,uVar11,
                            uVar22,'\0',puVar8);
        uVar15 = (ulonglong)uVar16;
        if (uVar16 == 0) {
          if ((DfscGlobalData & 4) == 0) {
            DfscReadLinkedConnectionPolicy();
          }
          if ((DfscGlobalData & 2) != 0) {
            DfscCreateLinkedConnection
                      (local_118,lVar9,(longlong)puVar27,(longlong)&local_a8,(longlong)puVar21,
                       (longlong)&local_c8,uVar11,uVar22);
          }
          goto LAB_14002ae24;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) != 0)) {
          WPP_SF_DS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar20,puVar24,uVar16,local_120);
        }
        if ((uVar19 == 0) || (uVar11 == 3)) goto LAB_14002ae24;
        goto LAB_14002addb;
      }
      uVar15 = 0xc00000bb;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0)) goto LAB_14002ae24;
      uVar18 = 0x1c;
      uVar25 = 0xc00000bb;
    }
    else {
      uVar15 = 0xc0000201;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400000) == 0)) goto LAB_14002ae24;
      uVar18 = 0x1b;
      uVar25 = 0xc0000201;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar18,
             &WPP_f31ad189acb537b72c4226ebda9d9ce6_Traceguids,uVar25);
  }
  else {
    uVar15 = DfscIsErrorInList(uVar19,0x14000d1a0,8);
    if (((char)uVar15 != '\0') && (cVar2 == '\0')) {
      uVar11 = 3;
      goto LAB_14002acb6;
    }
LAB_14002addb:
    uVar15 = (ulonglong)uVar19;
  }
LAB_14002ae24:
  if (puVar21 == (undefined2 *)0x0) {
    return uVar15;
  }
  DfscCredRelease((longlong)puVar21);
  return uVar15;
}



===== DfscRmGenerateReferralFromResponse @ 14002ae70 =====

ulonglong DfscRmGenerateReferralFromResponse
                    (longlong param_1,ushort *param_2,uint param_3,undefined8 *param_4)

{
  void *pvVar1;
  bool bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar7;
  undefined2 *puVar8;
  ulonglong uVar9;
  ushort uVar10;
  ulonglong uVar11;
  ushort *_Src;
  uint *puVar12;
  ushort *puVar13;
  ushort uVar14;
  short local_res18;
  ushort uStack0000000000000028;
  ulonglong local_88;
  uint local_80;
  uint local_7c;
  void *local_78;
  ulonglong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  wchar_t local_58;
  undefined1 auStack_56 [6];
  void *pvStack_50;
  
  uVar10 = param_2[1];
  local_88 = local_88 & 0xffffffff00000000;
  local_80 = 0;
  local_7c = DAT_14000d788;
  uVar14 = 0;
  _local_58 = 0;
  pvStack_50 = (void *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  uStack0000000000000028 = uVar10;
  iVar4 = DfscRmCheckReferralSyntax((longlong)param_2,param_3,'\0',(int *)&local_88);
  uVar7 = CONCAT44(extraout_var,iVar4);
  if (-1 < iVar4) {
    uVar5 = DfscRmGetNormalReferralSize((longlong)param_2,(undefined4 *)&local_88);
    uVar7 = CONCAT44(extraout_var_00,uVar5);
    if (-1 < (int)uVar5) {
      uVar7 = DfscRmGetPathConsumed(param_1,param_2,&local_68,'\x01');
      uVar11 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        puVar8 = DfscRmAllocateReferral((uint)(ushort)local_68 + (int)local_88 + 2,0x72436644);
        if (puVar8 == (undefined2 *)0x0) {
          uVar7 = 0xc000009a;
        }
        else {
          puVar8[0xe] = uVar10;
          uVar5 = 0;
          if (uVar10 == 0) {
            uVar5 = 300;
          }
          uVar3 = 0;
          if (uVar10 == 0) {
            uVar3 = 0xffff;
          }
          puVar8[0xf] = uVar3;
          uVar6 = *(uint *)(param_2 + 2);
          local_88 = 0;
          if (((uVar6 & 1) != 0) && (local_88 = 0, (uVar6 & 2) == 0)) {
            local_88 = (ulonglong)(uVar10 == 1);
          }
          if ((uVar6 & 4) != 0) {
            puVar8[8] = puVar8[8] | 4;
          }
          *(undefined2 **)(puVar8 + 0x4c) = puVar8 + (ulonglong)uVar10 * 0x38 + 0x50;
          puVar8[0x49] = (ushort)local_68 + 2;
          RtlCopyUnicodeString(puVar8 + 0x48,&local_68);
          local_78 = (void *)((ulonglong)(ushort)puVar8[0x49] + *(longlong *)(puVar8 + 0x4c));
          if (uVar10 != 0) {
            puVar13 = param_2 + 4;
            puVar12 = (uint *)(puVar8 + 0x50);
            if (uStack0000000000000028 == 0) {
              puVar13 = (ushort *)0x0;
            }
            do {
              _Src = (ushort *)0x0;
              uStack0000000000000028 = uStack0000000000000028 - 1;
              uVar10 = *puVar13;
              if (uVar10 == 1) {
                _Src = puVar13 + 4;
                uVar14 = puVar13[1] - 8;
              }
              else {
                if (uVar10 == 2) {
                  uVar6 = *(uint *)(puVar13 + 6);
                  uVar10 = puVar13[10];
                }
                else {
                  if (uVar10 != 3) {
                    if (uVar10 != 4) goto LAB_14002b08b;
                    if ((puVar13[3] & 4) != 0) {
                      *puVar12 = *puVar12 | 2;
                      local_80 = local_80 + 1;
                    }
                    puVar12[1] = local_80;
                  }
                  uVar6 = *(uint *)(puVar13 + 4);
                  uVar10 = puVar13[8];
                }
                local_res18 = (short)param_3;
                _Src = (ushort *)((ulonglong)uVar10 + (longlong)puVar13);
                uVar14 = (local_res18 - (short)_Src) + (short)param_2;
                if (uVar6 < uVar5) {
                  uVar6 = uVar5;
                }
                uVar5 = uVar6;
              }
LAB_14002b08b:
              local_70 = 0;
              uVar6 = RtlStringCbLengthW((short *)_Src,(ulonglong)uVar14,(longlong *)&local_70);
              pvVar1 = local_78;
              uVar11 = (ulonglong)uVar6;
              if ((local_70 == 0) || (uVar6 != 0)) {
                uVar7 = Feature_170808633__private_IsEnabledDeviceUsageNoInline();
                if (((int)uVar7 != 0) && (uVar6 == 0)) {
                  uVar11 = 0xc00000c3;
                }
                break;
              }
              uVar7 = local_70;
              if (*(short *)((longlong)_Src + ((local_70 & 0xfffffffffffffffe) - 2)) == 0x5c) {
                uVar7 = local_70 - 2;
              }
              memmove(local_78,_Src,uVar7);
              *(undefined2 *)((longlong)pvVar1 + (uVar7 & 0xfffffffffffffffe)) = 0;
              pvStack_50 = pvVar1;
              _local_58 = CONCAT62(CONCAT42(auStack_56._2_4_,(short)uVar7),(short)uVar7);
              uVar9 = DfscInitDfsPath(&local_58,(short *)(puVar12 + 4));
              uVar11 = uVar9 & 0xffffffff;
              if ((int)uVar9 < 0) break;
              puVar12[2] = 0xffffffff;
              if ((local_88 != 0) ||
                 ((puVar8[0xe] == 1 &&
                  (bVar2 = DfscIsKnownDomainName(param_1,(ushort *)(puVar12 + 4)), bVar2)))) {
                *puVar12 = *puVar12 | 1;
              }
              uVar10 = puVar8[8] | 2;
              if (puVar13[2] != 1) {
                uVar10 = puVar8[8] & 0xfffd;
              }
              local_78 = (void *)((longlong)local_78 + uVar7 + 2);
              puVar8[8] = uVar10;
              puVar12 = puVar12 + 0x1c;
              puVar13 = (ushort *)((longlong)puVar13 + (ulonglong)puVar13[1]);
            } while (uStack0000000000000028 != 0);
          }
          if (local_7c <= uVar5) {
            uVar5 = local_7c;
          }
          *(uint *)(puVar8 + 0x14) = uVar5;
          *(undefined4 *)(puVar8 + 0xc) = *(undefined4 *)(param_1 + 0xe8);
          uVar7 = uVar11;
          if ((int)uVar11 < 0) {
            DfscRmDereferenceReferral((longlong)puVar8);
          }
          else {
            *param_4 = puVar8;
          }
        }
      }
    }
  }
  return uVar7;
}



===== DfscRmGetPathConsumed @ 14002b1f0 =====

undefined8 DfscRmGetPathConsumed(longlong param_1,ushort *param_2,undefined8 *param_3,char param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ushort uVar3;
  ushort *puVar4;
  bool bVar5;
  ushort local_58;
  undefined1 auStack_56 [6];
  short *psStack_50;
  ushort local_48 [4];
  longlong lStack_40;
  undefined8 local_38;
  short *psStack_30;
  
  bVar5 = false;
  _local_58 = 0;
  psStack_50 = (short *)0x0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  lStack_40 = 0;
  local_38 = 0;
  psStack_30 = (short *)0x0;
  RtlInitUnicodeString(&local_58,0);
  RtlInitUnicodeString(local_48,0);
  *(undefined2 *)(param_1 + 0xda) = 0;
  if (param_2[1] != 0) {
    puVar4 = param_2 + 4;
    uVar3 = *puVar4;
    if (uVar3 != 1) {
      if (uVar3 == 2) {
        uVar3 = *param_2;
        uVar2 = RtlInitUnicodeStringEx(&local_58,(ulonglong)param_2[0xc] + (longlong)puVar4);
        if ((int)uVar2 != 0) {
          return uVar2;
        }
        uVar2 = RtlInitUnicodeStringEx(local_48,(ulonglong)param_2[0xd] + (longlong)puVar4);
        if ((int)uVar2 != 0) {
          return uVar2;
        }
        bVar5 = uVar3 == 0;
      }
      else {
        if ((uVar3 != 3) && (uVar3 != 4)) {
          return 0xc000000d;
        }
        uVar3 = param_2[7];
        bVar5 = (uVar3 & 2) != 0;
        uVar2 = RtlInitUnicodeStringEx(&local_58,(ulonglong)param_2[10] + (longlong)puVar4);
        if ((int)uVar2 != 0) {
          return uVar2;
        }
        if (((uVar3 & 2) == 0) &&
           (uVar2 = RtlInitUnicodeStringEx(local_48,(ulonglong)param_2[0xb] + (longlong)puVar4),
           (int)uVar2 != 0)) {
          return uVar2;
        }
      }
      uVar3 = local_58;
      goto LAB_14002b358;
    }
  }
  uVar3 = *param_2;
  psStack_50 = *(short **)(param_1 + 0xc0);
  _local_58 = CONCAT22(uVar3 + 2,uVar3);
LAB_14002b358:
  if (((2 < local_48[0]) && (lStack_40 != 0)) &&
     (*(short *)(lStack_40 + -2 + (ulonglong)(local_48[0] >> 1) * 2) == 0x5c)) {
    local_48[0] = local_48[0] - 2;
  }
  if (((2 < uVar3) && (psStack_50 != (short *)0x0)) &&
     (psStack_50[(ulonglong)(uVar3 >> 1) - 1] == 0x5c)) {
    uVar3 = uVar3 - 2;
    _local_58 = CONCAT62(auStack_56,uVar3);
  }
  if ((bVar5) && (param_4 == '\0')) {
    if (((2 < uVar3) && (psStack_50 != (short *)0x0)) && (*psStack_50 == 0x5c)) {
      uVar3 = uVar3 - 2;
      psStack_50 = psStack_50 + 1;
      _local_58 = CONCAT62(CONCAT42(auStack_56._2_4_,auStack_56._0_2_ + -2),uVar3);
    }
    puVar4 = &local_58;
    local_58 = uVar3;
  }
  else {
    puVar4 = (ushort *)(param_1 + 0xa8);
    uVar3 = *puVar4;
    uVar2 = *(undefined8 *)puVar4;
    psStack_30 = *(short **)(param_1 + 0xb0);
    local_38 = uVar2;
    if ((3 < uVar3) && (((*psStack_30 == 0x5c && (psStack_30[1] == 0x5c)) && (2 < uVar3)))) {
      local_38._2_2_ = (short)((uint6)*(undefined6 *)puVar4 >> 0x10);
      local_38._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
      local_38 = CONCAT62(CONCAT42(local_38._4_4_,local_38._2_2_ + -2),uVar3 - 2);
      psStack_30 = psStack_30 + 1;
    }
    uVar2 = DfscPathPrefixMatch(&local_58,(ushort *)&local_38);
    if ((char)uVar2 == '\0') {
      uVar2 = DfscPathPrefixMatch(local_48,(ushort *)&local_38);
      if ((char)uVar2 == '\0') {
        return 0xc00000c3;
      }
      puVar4 = local_48;
      local_58 = local_48[0];
    }
    else {
      puVar4 = &local_58;
    }
  }
  uVar2 = *(undefined8 *)puVar4;
  uVar1 = *(undefined8 *)(puVar4 + 4);
  *(ushort *)(param_1 + 0xda) = -(ushort)(*param_2 != 0) & local_58;
  *param_3 = uVar2;
  param_3[1] = uVar1;
  return 0;
}



===== DfscFsctrlGetClientInfo$fin$0 @ 14002b4a0 =====

void DfscFsctrlGetClientInfo_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x90) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x90),0);
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    DfscReferralRelease(*(longlong *)(param_2 + 0x60));
  }
  return;
}



===== DfscFsctrlSetClientInfo$fin$0 @ 14002b4e0 =====

void DfscFsctrlSetClientInfo_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x58) != 0) {
    DfscReferralRelease(*(longlong *)(param_2 + 0x58));
  }
  return;
}



===== entry @ 14002c010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002c044 =====

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



===== DfscApplyDeviceAcl @ 14002c078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DfscApplyDeviceAcl(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined1 auStack_98 [32];
  int local_78;
  int local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined2 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_40 = 0;
  local_3c = 0x500;
  local_38 = 0;
  lVar6 = 0;
  local_34 = 0x100;
  lVar7 = 0;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  lVar9 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_70 = param_1;
  local_74 = RtlLengthRequiredSid(6);
  lVar4 = ExAllocatePool2(0x102,local_74,0x49436644);
  if (lVar4 == 0) {
    return 0xc000009a;
  }
  iVar1 = RtlLengthRequiredSid(1);
  lVar5 = ExAllocatePool2(0x102,iVar1,0x49436644);
  if (lVar5 != 0) {
    local_78 = RtlLengthRequiredSid(2);
    lVar6 = ExAllocatePool2(0x102,local_78,0x49436644);
    if (lVar6 != 0) {
      iVar2 = RtlLengthRequiredSid(1);
      lVar7 = ExAllocatePool2(0x102,iVar2,0x49436644);
      if (lVar7 != 0) {
        RtlInitializeSid(lVar4,&local_40,6);
        RtlInitializeSid(lVar5,&local_40,1);
        RtlInitializeSid(lVar6,&local_40,2);
        RtlInitializeSid(lVar7,&local_38,1);
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar4,0);
        *puVar8 = 0x50;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar4,1);
        *puVar8 = 0x2aea4d57;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar4,2);
        *puVar8 = 0xa8e6d4cb;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar4,3);
        *puVar8 = 0x5d63bd2f;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar4,4);
        *puVar8 = 0xf4049bf1;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar4,5);
        *puVar8 = 0x54485448;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar5,0);
        *puVar8 = 0x12;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar6,0);
        *puVar8 = 0x20;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar6,1);
        *puVar8 = 0x220;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar7,0);
        *puVar8 = 0;
        iVar1 = local_74 + 0x30 + local_78 + iVar2 + iVar1;
        lVar9 = ExAllocatePool2(0x102,iVar1,0x49436644);
        if (lVar9 != 0) {
          RtlCreateAcl(lVar9,iVar1,2);
          RtlAddAccessAllowedAce(lVar9,2,0x1f01ff,lVar4);
          RtlAddAccessAllowedAce(lVar9,2,0x1f01ff,lVar5);
          RtlAddAccessAllowedAce(lVar9,2,0x1f01ff,lVar6);
          RtlAddAccessAllowedAce(lVar9,2,0x1200a0,lVar7);
          RtlCreateSecurityDescriptor(&local_68,1);
          RtlSetDaclSecurityDescriptor(&local_68,1,lVar9,0);
          uVar3 = ObSetSecurityObjectByPointer(local_70,4,&local_68);
          goto LAB_14002c402;
        }
      }
    }
  }
  uVar3 = 0xc000009a;
LAB_14002c402:
  ExFreePoolWithTag(lVar4,0);
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0);
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0);
  }
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0);
  }
  return uVar3;
}



===== DfscInitVariables @ 14002c4a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DfscInitVariables(short *param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  int local_res8 [2];
  
  DAT_14000d79c = 0x100;
  DAT_14000d788 = 0x93a80;
  DAT_14000d78c = 0x93a80;
  DAT_14000d780 = 0;
  DAT_14000d7a0 = 0x800;
  _DAT_14000d7a4 = 0x800;
  _DAT_14000d790 = 0x100;
  DAT_14000d794 = 900;
  DAT_14000d798 = 100;
  DAT_14000d7a8 = 10;
  _DAT_14000d768 = 0;
  _DAT_14000d76a = *param_1 + 0x18;
  DAT_14000d770 = ExAllocatePool2(0x102,_DAT_14000d76a,0x6f436644);
  if (DAT_14000d770 != 0) {
    RtlCopyUnicodeString(&DAT_14000d768,param_1);
    iVar1 = RtlAppendUnicodeToString(&DAT_14000d768,L"\\Parameters");
    if (iVar1 == 0) {
      DfscPolicyReadRegistryParameters();
    }
  }
  DfscGlobalData = DfscGlobalData & 0xfffffff9;
  DfscReadLinkedConnectionPolicy();
  local_res8[0] = 0;
  DAT_14000d760 = &DAT_14000d758;
  _DAT_14000d758 = &DAT_14000d758;
  DAT_14000d830 = &DAT_14000d828;
  DAT_14000d828 = &DAT_14000d828;
  iVar1 = ZwQueryInformationProcess(0xffffffffffffffff,0x1c,local_res8,4,0);
  DfsLUIDDeviceMapsEnabled = 0;
  if (-1 < iVar1) {
    DfsLUIDDeviceMapsEnabled = (uint)(local_res8[0] != 0);
  }
  _DfscPathNameMaxDepth = 4;
  ExInitializePagedLookasideList(&DfscPathNameLookasideList,0,0,0,0x60,0x70634644,4);
  DfscInitializationStatus = DfscInitializationStatus | 2;
  ExInitializeResourceLite(&DAT_14000d658);
  ExInitializeResourceLite(&DAT_14000d6e0);
  DfscInitializationStatus = DfscInitializationStatus | 1;
  uVar3 = DfscCacheInitialize(&DAT_14000d6c8,'\0',_DAT_14000d7a4 << 10);
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
      return uVar5;
    }
    uVar4 = 10;
  }
  else {
    DfscInitializationStatus = DfscInitializationStatus | 4;
    uVar3 = DfscCacheInitialize(&DAT_14000d6d0,'\x01',DAT_14000d7a0 << 10);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar5;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
        return uVar5;
      }
      uVar4 = 0xb;
    }
    else {
      DfscInitializationStatus = DfscInitializationStatus | 8;
      uVar3 = DfscNetUseTableInitialize(&DAT_14000d748);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        DfscInitializationStatus = DfscInitializationStatus | 0x10;
        uVar3 = DfscNetUseTableInitialize(&DAT_14000d750);
        uVar5 = uVar3 & 0xffffffff;
        if ((int)uVar3 == 0) {
          DfscInitializationStatus = DfscInitializationStatus | 0x20;
          uVar2 = DfscCredTableInitialize(&DAT_14000d6d8);
          uVar5 = (ulonglong)uVar2;
          if (uVar2 == 0) {
            DfscInitializationStatus = DfscInitializationStatus | 0x40;
            DAT_14000d778 = KeAllocateCalloutStack(0);
            if (DAT_14000d778 == 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) != 0)) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                        &WPP_cfcaa481b12a333e9e16f5fa170721f9_Traceguids);
              }
              return 0xc000009a;
            }
            DfscInitializationStatus = DfscInitializationStatus | 0x80;
            ExInitializeResourceLite(&DAT_14000d7c0);
            DAT_14000d7ae = 0;
            RtlInitUnicodeString(&DAT_14000d7b0,0);
            DfscInitializeAndRegisterDAKeyChangeNotification();
            DfscInitializationStatus = DfscInitializationStatus | 0x100;
            uVar2 = DfscInitializeContainerModule();
            uVar3 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return uVar3;
              }
              if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
                return uVar3;
              }
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                      &WPP_cfcaa481b12a333e9e16f5fa170721f9_Traceguids);
              return uVar3;
            }
            uVar2 = DfscRegisterMup();
            uVar5 = (ulonglong)uVar2;
            if (uVar2 == 0) {
              DfscGlobalData = DfscGlobalData | 1;
              return 0;
            }
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return uVar5;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
              return uVar5;
            }
            uVar4 = 0x11;
          }
          else {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return uVar5;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
              return uVar5;
            }
            uVar4 = 0xe;
          }
        }
        else {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar5;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
            return uVar5;
          }
          uVar4 = 0xd;
        }
      }
      else {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar5;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
          return uVar5;
        }
        uVar4 = 0xc;
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_cfcaa481b12a333e9e16f5fa170721f9_Traceguids,(int)uVar5);
  return uVar5;
}



===== DriverEntry @ 14002c914 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,short *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  wil_InitializeFeatureStaging();
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_28,L"\\Device\\DfsClient");
  puVar5 = &local_28;
  uVar1 = IoCreateDevice(param_1,0,puVar5,8,0x110,0,&DAT_14000d648);
  if (-1 < (int)uVar1) {
    uVar1 = DfscApplyDeviceAcl(DAT_14000d648);
    if (-1 < (int)uVar1) {
      RtlInitUnicodeString(&local_18,L"\\Dfs");
      IoDeleteSymbolicLink(&local_18);
      puVar3 = &local_28;
      uVar1 = IoCreateSymbolicLink(&local_18);
      if (-1 < (int)uVar1) {
        DAT_14000d650 = param_1;
        *(code **)(param_1 + 0x68) = DriverUnload;
        *(code **)(param_1 + 0x70) = DfscCreate;
        *(code **)(param_1 + 0x100) = DfscCleanup;
        *(code **)(param_1 + 0x80) = DfscClose;
        *(code **)(param_1 + 0x128) = DfscSystemControl;
        *(code **)(param_1 + 0xd8) = DfscFileSystemControl;
        *(undefined8 *)(param_1 + 0x50) = 0;
        *(undefined1 *)(DAT_14000d648 + 0x4c) = 1;
        *(uint *)(DAT_14000d648 + 0x30) = *(uint *)(DAT_14000d648 + 0x30) & 0xffffff7f;
        DAT_14000d5c8 = &WPP_ThisDir_CTLGUID_MupLog;
        DAT_14000d5d0 = &DAT_14000d600;
        _DAT_14000d608 = &WPP_ThisDir_CTLGUID_RFSMon;
        _WPP_MAIN_CB = 0;
        _DAT_14000d5e0 = 0;
        _DAT_14000d5e8 = 1;
        _DAT_14000d600 = 0;
        _DAT_14000d610 = 0;
        _DAT_14000d620 = 0;
        _DAT_14000d628 = 1;
        WppLoadTracingSupport();
        _DAT_14000d5e0 = 0;
        WppInitKm();
        uVar2 = DfscInitVariables(param_2);
        uVar4 = uVar2 & 0xffffffff;
        if (-1 < (int)uVar2) {
          uVar2 = DfscInitializeTimer();
          uVar4 = uVar2 & 0xffffffff;
          if (-1 < (int)uVar2) {
            return uVar4;
          }
        }
        DfscInitUnwind(param_2,(undefined *)puVar3,(undefined *)puVar5);
        return uVar4;
      }
    }
    IoDeleteDevice(DAT_14000d648);
  }
  wil_UninitializeFeatureStaging();
  return (ulonglong)uVar1;
}



===== wil_InitializeFeatureStaging @ 14002cb30 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002cc20 =====

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



===== DfscInitializeContainerModule @ 14002cd08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DfscInitializeContainerModule(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStack_58 [32];
  undefined1 local_38;
  undefined4 local_37;
  undefined2 local_33;
  undefined1 local_31;
  longlong local_30;
  code *local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids);
  }
  local_30 = DAT_14000d650 + 0x38;
  local_38 = 1;
  local_28 = DfscpContainerCreateNotify;
  local_20 = DfscpContainerTerminateNotify;
  local_37 = 0;
  local_33 = 0;
  local_31 = 0;
  iVar1 = PsRegisterSiloMonitor(&local_38,&DAT_14000d838);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
      return iVar1;
    }
    uVar2 = 0x18;
  }
  else {
    iVar1 = PsStartSiloMonitor(DAT_14000d838);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100000) == 0) {
      return iVar1;
    }
    uVar2 = 0x17;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_32bb75f7aa823fb724b87f7e3287c67a_Traceguids,iVar1);
  return iVar1;
}


