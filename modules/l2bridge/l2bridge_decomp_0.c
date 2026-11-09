
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== AddOrUpdateIPv6RewriteTable @ 140001030 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * AddOrUpdateIPv6RewriteTable
                 (longlong param_1,undefined4 *param_2,undefined4 *param_3,char param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  void *_Dst;
  undefined2 local_res20;
  undefined1 local_res22;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  local_40 = 0;
  local_res20 = 0;
  local_res22 = 0;
  uVar5 = RtlCompute37Hash(IPv6RewriteTableHashSeed,param_2,0x10);
  lVar4 = _DAT_fffff78000000008;
  uVar5 = uVar5 & 0xffffffff;
  if (uVar5 == 0) {
    uVar5 = 0xffffffffffffffff;
  }
  local_50 = 0;
  uStack_48 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0xd0),&local_res20,param_4 != '\0');
  if (10000000 < (ulonglong)(lVar4 - *(longlong *)(param_1 + 0xd8))) {
    RemoveUnusedEntries(*(undefined8 *)(param_1 + 200),IPv6RewriteTableShouldRemoveCallback,
                        MACAddressTableRemovedCallback);
    *(longlong *)(param_1 + 0xd8) = lVar4;
  }
  puVar6 = &local_50;
  _Dst = (void *)LookupTable(*(undefined8 *)(param_1 + 200),uVar5,param_2,IPv6RewriteTableComparator
                             ,puVar6);
  uVar7 = (undefined4)((ulonglong)puVar6 >> 0x20);
  if (_Dst == (void *)0x0) {
    _Dst = (void *)ExAllocatePoolWithTag(0x600,0x40,0x7242324c);
    if (_Dst == (void *)0x0) {
      DbgPrintEx(0x50,0,"Failed to allocate IPV6_REWRITE_TABLE_ENTRY\n");
      goto LAB_14000136d;
    }
    memset(_Dst,0,0x40);
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(undefined4 *)((longlong)_Dst + 0x1c) = *param_2;
    *(undefined4 *)((longlong)_Dst + 0x20) = uVar1;
    *(undefined4 *)((longlong)_Dst + 0x24) = uVar2;
    *(undefined4 *)((longlong)_Dst + 0x28) = uVar3;
    *(undefined4 *)((longlong)_Dst + 0x2c) = *param_3;
    *(undefined2 *)((longlong)_Dst + 0x30) = *(undefined2 *)(param_3 + 1);
    *(longlong *)((longlong)_Dst + 0x38) = lVar4;
    LOCK();
    *(int *)((longlong)_Dst + 0x18) = *(int *)((longlong)_Dst + 0x18) + 1;
    UNLOCK();
    RtlInsertEntryHashTable(*(undefined8 *)(param_1 + 200),_Dst,uVar5,&local_50);
    DbgPrintEx(0x50,0,
               "Adding Rewrite Entry:\n\t%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x\n\t%02x:%02x:%02x:%02x:%02x:%02x\n"
               ,*(undefined1 *)param_2,CONCAT44(uVar7,(uint)*(byte *)((longlong)param_2 + 1)),
               *(undefined1 *)((longlong)param_2 + 2),*(undefined1 *)((longlong)param_2 + 3),
               *(undefined1 *)(param_2 + 1),*(undefined1 *)((longlong)param_2 + 5),
               *(undefined1 *)((longlong)param_2 + 6),*(undefined1 *)((longlong)param_2 + 7),
               *(undefined1 *)(param_2 + 2),*(undefined1 *)((longlong)param_2 + 9),
               *(undefined1 *)((longlong)param_2 + 10),*(undefined1 *)((longlong)param_2 + 0xb),
               *(undefined1 *)(param_2 + 3),*(undefined1 *)((longlong)param_2 + 0xd),
               *(undefined1 *)((longlong)param_2 + 0xe),*(undefined1 *)((longlong)param_2 + 0xf),
               *(undefined1 *)param_3,*(undefined1 *)((longlong)param_3 + 1),
               *(undefined1 *)((longlong)param_3 + 2),*(undefined1 *)((longlong)param_3 + 3),
               *(undefined1 *)(param_3 + 1),*(undefined1 *)((longlong)param_3 + 5));
  }
  else {
    *(longlong *)((longlong)_Dst + 0x38) = lVar4;
  }
  LOCK();
  *(int *)((longlong)_Dst + 0x18) = *(int *)((longlong)_Dst + 0x18) + 1;
  UNLOCK();
LAB_14000136d:
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0xd0),&local_res20);
  return _Dst;
}



===== AddOrUpdateMACForwardingTable @ 1400013b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * AddOrUpdateMACForwardingTable
                 (longlong param_1,undefined4 *param_2,undefined1 param_3,undefined8 param_4,
                 char param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  void *_Dst;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_48 = 0;
  local_res8 = 0;
  local_resa = 0;
  uVar2 = RtlCompute37Hash(MACAddressTableHashSeed,param_2,6);
  lVar1 = _DAT_fffff78000000008;
  uVar2 = uVar2 & 0xffffffff;
  if (uVar2 == 0) {
    uVar2 = 0xffffffffffffffff;
  }
  local_58 = 0;
  uStack_50 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x20),&local_res8,param_5 != '\0');
  if (10000000 < (ulonglong)(lVar1 - *(longlong *)(param_1 + 0x28))) {
    RemoveUnusedEntries(*(undefined8 *)(param_1 + 0x18),MACAddressTableShouldRemoveCallback,
                        MACAddressTableRemovedCallback);
    *(longlong *)(param_1 + 0x28) = lVar1;
  }
  puVar3 = &local_58;
  _Dst = (void *)LookupTable(*(undefined8 *)(param_1 + 0x18),uVar2,param_2,MACAddressTableComparator
                             ,puVar3);
  uVar4 = (undefined4)((ulonglong)puVar3 >> 0x20);
  if (_Dst == (void *)0x0) {
    _Dst = (void *)ExAllocatePoolWithTag(0x600,0x40,0x7242324c);
    if (_Dst == (void *)0x0) {
      DbgPrintEx(0x50,0,"Failed to allocate MAC_FORWARDING_TABLE_ENTRY\n");
    }
    else {
      memset(_Dst,0,0x40);
      *(undefined4 *)((longlong)_Dst + 0x1c) = *param_2;
      *(undefined2 *)((longlong)_Dst + 0x20) = *(undefined2 *)(param_2 + 1);
      *(undefined1 *)((longlong)_Dst + 0x30) = param_3;
      *(undefined8 *)((longlong)_Dst + 0x38) = param_4;
      *(longlong *)((longlong)_Dst + 0x28) = lVar1;
      RtlInsertEntryHashTable(*(undefined8 *)(param_1 + 0x18),_Dst,uVar2,&local_58);
      LOCK();
      *(int *)((longlong)_Dst + 0x18) = *(int *)((longlong)_Dst + 0x18) + 1;
      UNLOCK();
      DbgPrintEx(0x50,0,"Adding MAC:\n\t%02x:%02x:%02x:%02x:%02x:%02x\n",*(undefined1 *)param_2,
                 CONCAT44(uVar4,(uint)*(byte *)((longlong)param_2 + 1)),
                 *(undefined1 *)((longlong)param_2 + 2),*(undefined1 *)((longlong)param_2 + 3),
                 *(undefined1 *)(param_2 + 1),*(undefined1 *)((longlong)param_2 + 5));
    }
  }
  else {
    *(longlong *)((longlong)_Dst + 0x28) = lVar1;
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res8);
  return _Dst;
}



===== CleanupMACAddressesTable @ 1400015c0 =====

void CleanupMACAddressesTable(longlong param_1)

{
  CleanupTable(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20),
               MACAddressTableRemovedCallback);
  return;
}



===== CleanupTable @ 1400015e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CleanupTable(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  char cVar1;
  longlong lVar2;
  undefined2 local_res20;
  undefined1 local_res22;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res20 = 0;
  local_res22 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  NdisAcquireRWLockWrite(param_2,&local_res20,0);
  cVar1 = RtlInitEnumerationHashTable(param_1,&local_38);
  if (cVar1 != '\0') {
    while (lVar2 = RtlEnumerateEntryHashTable(param_1,&local_38), lVar2 != 0) {
      RtlRemoveEntryHashTable(param_1,lVar2,0);
      (*(code *)param_3)(lVar2);
    }
    RtlEndEnumerationHashTable(param_1,&local_38);
  }
  NdisReleaseRWLock(param_2,&local_res20);
  return;
}



===== DEREF_FILTER_MODULE @ 1400016cc =====

void DEREF_FILTER_MODULE(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xb0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x98) != 0) {
      ExFreeCacheAwareRundownProtection();
      *(undefined8 *)(param_1 + 0x98) = 0;
    }
    if (*(longlong *)(param_1 + 0xa0) != 0) {
      ExFreeCacheAwareRundownProtection();
      *(undefined8 *)(param_1 + 0xa0) = 0;
    }
    if (*(longlong *)(param_1 + 200) != 0) {
      CleanupTable(*(longlong *)(param_1 + 200),*(undefined8 *)(param_1 + 0xd0),
                   MACAddressTableRemovedCallback);
      RtlDeleteHashTable(*(undefined8 *)(param_1 + 200));
      *(undefined8 *)(param_1 + 200) = 0;
    }
    if (*(longlong *)(param_1 + 0xd0) != 0) {
      NdisFreeRWLock();
      *(undefined8 *)(param_1 + 0xd0) = 0;
    }
    if (*(longlong *)(param_1 + 0x10) != 0) {
      NdisFreeRWLock();
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    if (*(longlong *)(param_1 + 0xb8) != 0) {
      NdisFreeNetBufferListPool();
      *(undefined8 *)(param_1 + 0xb8) = 0;
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== FilterOidRequest @ 1400017e0 =====

ulonglong FilterOidRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  uint local_res8 [2];
  longlong local_res10;
  
  local_res10 = 0;
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 == 1) {
    if (*(int *)(param_2 + 0x20) == 0x1010e) {
      if ((*(uint **)(param_2 + 0x28) != (uint *)0x0) && (3 < *(uint *)(param_2 + 0x30))) {
        *(undefined4 *)(param_2 + 0x34) = 4;
        local_res8[0] = **(uint **)(param_2 + 0x28) | 0x20;
        uVar3 = L2BridgeIssueOid(*(undefined8 *)(param_1 + 0x18),1,param_3,local_res8);
        if ((int)uVar3 == 0) {
          *(undefined4 *)(param_1 + 0xc0) = **(undefined4 **)(param_2 + 0x28);
          return uVar3 & 0xffffffff;
        }
        return uVar3 & 0xffffffff;
      }
      goto LAB_14000185e;
    }
LAB_140001878:
    if (iVar2 != 2) goto LAB_1400018ab;
  }
  else if (iVar2 != 0) goto LAB_140001878;
  if (*(int *)(param_2 + 0x20) == 0x1010e) {
    if ((*(undefined4 **)(param_2 + 0x28) != (undefined4 *)0x0) && (3 < *(uint *)(param_2 + 0x30)))
    {
      **(undefined4 **)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0xc0);
      *(undefined4 *)(param_2 + 0x34) = 4;
      return 0;
    }
LAB_14000185e:
    *(undefined4 *)(param_2 + 0x34) = 0;
    *(undefined4 *)(param_2 + 0x38) = 4;
    return 0xc0010016;
  }
LAB_1400018ab:
  uVar1 = NdisAllocateCloneOidRequest
                    (*(undefined8 *)(param_1 + 0x18),param_2,0x7242324c,&local_res10);
  if (uVar1 == 0) {
    *(longlong *)(local_res10 + 0xd8) = param_2;
    *(undefined8 *)(local_res10 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    iVar2 = NdisFOidRequest(*(undefined8 *)(param_1 + 0x18),local_res10);
    if (iVar2 == 0x103) {
      return 0x103;
    }
    FilterOidRequestComplete(param_1,local_res10,iVar2);
    return 0x103;
  }
  iVar2 = *(int *)(param_2 + 4);
  if ((((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) || (iVar2 != 0xc)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    *(undefined4 *)(param_2 + 0x38) = 0;
    return (ulonglong)uVar1;
  }
  *(undefined4 *)(param_2 + 0x40) = 0;
  *(undefined4 *)(param_2 + 0x44) = 0;
  *(undefined4 *)(param_2 + 0x3c) = 0;
  return (ulonglong)uVar1;
}



===== FilterOidRequestComplete @ 140001970 =====

void FilterOidRequestComplete(longlong param_1,longlong param_2,undefined4 param_3)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  if (lVar2 == 0) {
    *(undefined4 *)(param_2 + -8) = param_3;
    KeSetEvent(param_2 + -0x20,0,0);
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
    if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || (iVar1 != 0xc)) {
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_2 + 0x38);
    }
    else {
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar2 + 0x40) = *(undefined4 *)(param_2 + 0x40);
      *(undefined4 *)(lVar2 + 0x44) = *(undefined4 *)(param_2 + 0x44);
      *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
    }
    NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x18));
    NdisFOidRequestComplete(*(undefined8 *)(param_1 + 0x18),lVar2,param_3);
  }
  return;
}



===== FilterReceiveNetBufferLists @ 140001a30 =====

void FilterReceiveNetBufferLists
               (longlong param_1,undefined8 ***param_2,undefined4 param_3,int param_4,uint param_5)

{
  longlong lVar1;
  undefined8 ****ppppuVar2;
  undefined8 ***pppuVar3;
  undefined8 ****ppppuVar4;
  bool bVar5;
  undefined8 ****ppppuVar6;
  undefined8 ****ppppuVar7;
  int iVar8;
  undefined8 ***pppuVar9;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined8 ***local_48;
  undefined8 ****local_40;
  undefined8 ***local_38;
  undefined8 ****local_30;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(DebugLock,&local_res8,0);
  iVar8 = 0;
  local_30 = &local_38;
  local_38 = (undefined8 ***)0x0;
  pppuVar9 = (undefined8 ***)0x0;
  local_48 = (undefined8 ***)0x0;
  local_40 = &local_48;
  if ((((((ulonglong)param_2[0x10] & 0x8000) == 0) && (*(int *)(param_1 + 0x90) == 3)) &&
      (lVar1 = *(longlong *)(param_1 + 0xe0), lVar1 != 0)) &&
     (((*(char *)(lVar1 + 0x11) != '\0' && (*(int *)(*(longlong *)(lVar1 + 0x30) + 0x90) == 3)) &&
      (*(int *)(*(longlong *)(lVar1 + 0x38) + 0x90) == 3)))) {
    do {
      ppppuVar2 = (undefined8 ****)*param_2;
      *param_2 = (undefined8 ***)0x0;
      bVar5 = IsIPv6(param_1,(longlong)param_2);
      ppppuVar4 = (undefined8 ****)*param_2;
      ppppuVar7 = (undefined8 ****)param_2;
      if (bVar5) {
        while (ppppuVar6 = ppppuVar4, ppppuVar6 != (undefined8 ****)0x0) {
          ppppuVar7 = ppppuVar6;
          ppppuVar4 = (undefined8 ****)*ppppuVar6;
        }
        *local_30 = param_2;
        local_30 = ppppuVar7;
      }
      else {
        while (ppppuVar6 = ppppuVar4, ppppuVar6 != (undefined8 ****)0x0) {
          ppppuVar7 = ppppuVar6;
          ppppuVar4 = (undefined8 ****)*ppppuVar6;
        }
        iVar8 = iVar8 + 1;
        *local_40 = param_2;
        local_40 = ppppuVar7;
      }
      param_2 = ppppuVar2;
    } while (ppppuVar2 != (undefined8 ****)0x0);
    param_2 = local_48;
    pppuVar9 = local_38;
    param_4 = iVar8;
  }
  else {
  }
  local_30 = &local_38;
  local_38 = (undefined8 ***)0x0;
  local_40 = &local_48;
  local_48 = (undefined8 ***)0x0;
  if (param_2 != (undefined8 ***)0x0) {
    NdisFIndicateReceiveNetBufferLists
              (*(undefined8 *)(param_1 + 0x18),param_2,param_3,param_4,param_5);
  }
  while (pppuVar9 != (undefined8 ***)0x0) {
    pppuVar3 = (undefined8 ***)*pppuVar9;
    *pppuVar9 = (undefined8 **)0x0;
    ReceiveNetBufferList(param_1,(longlong)pppuVar9,param_3,param_5);
    pppuVar9 = pppuVar3;
  }
  NdisReleaseRWLock(DebugLock,&local_res8);
  return;
}



===== FilterReturnNetBufferLists @ 140001bf0 =====

void FilterReturnNetBufferLists(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  local_res18 = 0;
  local_res1a = 0;
  NdisAcquireRWLockWrite(DebugLock,&local_res18,0);
  while (param_2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_2;
    *param_2 = 0;
    if (*(longlong *)(param_1 + 0x18) == param_2[0xf]) {
      L2BridgeFreeNBL((longlong)param_2,(byte)param_3 & 1);
      ExReleaseRundownProtectionCacheAwareEx(*(undefined8 *)(param_1 + 0x98),1);
      LOCK();
      *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + -1;
      UNLOCK();
      param_2 = puVar1;
    }
    else {
      NdisFReturnNetBufferLists(*(longlong *)(param_1 + 0x18),param_2,param_3);
      param_2 = puVar1;
    }
  }
  NdisReleaseRWLock(DebugLock,&local_res18);
  return;
}



===== FilterSendNetBufferLists @ 140001cd0 =====

void FilterSendNetBufferLists
               (longlong param_1,undefined8 ***param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined8 ****ppppuVar2;
  undefined8 ***pppuVar3;
  undefined8 ****ppppuVar4;
  undefined8 ****ppppuVar5;
  undefined8 ****ppppuVar6;
  undefined8 ****ppppuVar7;
  undefined8 ***pppuVar8;
  bool bVar9;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined8 ***local_38;
  undefined8 ****local_30;
  undefined8 ***local_28;
  undefined8 ****local_20;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(DebugLock);
  local_20 = &local_28;
  pppuVar8 = (undefined8 ***)0x0;
  local_28 = (undefined8 ***)0x0;
  local_30 = &local_38;
  local_38 = (undefined8 ***)0x0;
  if ((((*(int *)(param_1 + 0x90) == 3) && (lVar1 = *(longlong *)(param_1 + 0xe0), lVar1 != 0)) &&
      (*(char *)(lVar1 + 0x11) != '\0')) &&
     ((*(int *)(*(longlong *)(lVar1 + 0x30) + 0x90) == 3 &&
      (*(int *)(*(longlong *)(lVar1 + 0x38) + 0x90) == 3)))) {
    bVar9 = param_2 != (undefined8 ***)0x0;
    pppuVar8 = (undefined8 ***)0x0;
    ppppuVar7 = (undefined8 ****)param_2;
    param_2 = (undefined8 ***)0x0;
    if (bVar9) {
      do {
        ppppuVar2 = (undefined8 ****)*ppppuVar7;
        *ppppuVar7 = (undefined8 ***)0x0;
        bVar9 = IsIPv6(param_1,(longlong)ppppuVar7);
        ppppuVar4 = (undefined8 ****)*ppppuVar7;
        ppppuVar6 = ppppuVar7;
        if (bVar9) {
          while (ppppuVar5 = ppppuVar4, ppppuVar5 != (undefined8 ****)0x0) {
            ppppuVar6 = ppppuVar5;
            ppppuVar4 = (undefined8 ****)*ppppuVar5;
          }
          *local_20 = ppppuVar7;
          local_20 = ppppuVar6;
        }
        else {
          while (ppppuVar5 = ppppuVar4, ppppuVar5 != (undefined8 ****)0x0) {
            ppppuVar6 = ppppuVar5;
            ppppuVar4 = (undefined8 ****)*ppppuVar5;
          }
          *local_30 = ppppuVar7;
          local_30 = ppppuVar6;
        }
        ppppuVar7 = ppppuVar2;
      } while (ppppuVar2 != (undefined8 ****)0x0);
      pppuVar8 = local_28;
      param_2 = local_38;
    }
  }
  local_20 = &local_28;
  local_28 = (undefined8 ***)0x0;
  local_30 = &local_38;
  local_38 = (undefined8 ***)0x0;
  if (param_2 != (undefined8 ***)0x0) {
    NdisFSendNetBufferLists(*(undefined8 *)(param_1 + 0x18),param_2,param_3,param_4);
  }
  while (pppuVar8 != (undefined8 ***)0x0) {
    pppuVar3 = (undefined8 ***)*pppuVar8;
    *pppuVar8 = (undefined8 **)0x0;
    SendNetBufferList(param_1,(longlong)pppuVar8,param_3,param_4);
    pppuVar8 = pppuVar3;
  }
  NdisReleaseRWLock(DebugLock,&local_res8);
  return;
}



===== FilterSendNetBufferListsComplete @ 140001e80 =====

void FilterSendNetBufferListsComplete(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  local_res18 = 0;
  local_res1a = 0;
  NdisAcquireRWLockWrite(DebugLock,&local_res18,0);
  while (param_2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_2;
    *param_2 = 0;
    if (*(longlong *)(param_1 + 0x18) == param_2[0xf]) {
      L2BridgeFreeNBL((longlong)param_2,(byte)param_3 & 1);
      ExReleaseRundownProtectionCacheAwareEx(*(undefined8 *)(param_1 + 0x98),1);
      LOCK();
      *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + -1;
      UNLOCK();
      param_2 = puVar1;
    }
    else {
      NdisFSendNetBufferListsComplete(*(longlong *)(param_1 + 0x18),param_2,param_3);
      param_2 = puVar1;
    }
  }
  NdisReleaseRWLock(DebugLock,&local_res18);
  return;
}



===== FilterStatus @ 140001f60 =====

void FilterStatus(longlong param_1,longlong param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  if (((*(int *)(param_2 + 0x14) == 0x40020006) &&
      (pcVar1 = *(char **)(param_2 + 0x30), pcVar1 != (char *)0x0)) && (*pcVar1 == -0x59)) {
    local_res8 = 0;
    local_resa = 0;
    NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x10),&local_res8,0);
    uVar2 = *(undefined4 *)(pcVar1 + 0x54);
    uVar3 = *(undefined4 *)(pcVar1 + 0x58);
    uVar4 = *(undefined4 *)(pcVar1 + 0x5c);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(pcVar1 + 0x50);
    *(undefined4 *)(param_1 + 0x74) = uVar2;
    *(undefined4 *)(param_1 + 0x78) = uVar3;
    *(undefined4 *)(param_1 + 0x7c) = uVar4;
    *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(pcVar1 + 0x60);
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(pcVar1 + 0x68);
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x10),&local_res8);
  }
  NdisFIndicateStatus(*(undefined8 *)(param_1 + 0x18),param_2);
  return;
}



===== ForwardNBLToFilterModule @ 14000200c =====

void ForwardNBLToFilterModule
               (longlong param_1,char param_2,char param_3,longlong param_4,undefined4 param_5,
               undefined4 param_6)

{
  short *psVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  ulonglong uVar6;
  char *pcVar7;
  
  bVar5 = (byte)param_6 & 1;
  if (*(char *)(param_1 + 0xaa) != '\0') {
    lVar3 = NdisGetDataBuffer(*(undefined8 *)(param_4 + 8),0xe,0,1,0);
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_4 + 8),0xe,0,0);
    lVar4 = NdisGetDataBuffer(*(undefined8 *)(param_4 + 8),0x28,0,1,0);
    NdisRetreatNetBufferDataStart(*(undefined8 *)(param_4 + 8),0xe);
    psVar1 = (short *)(lVar4 + 8);
    if ((((((*psVar1 != 0) || (*(short *)(lVar4 + 10) != 0)) || (*(short *)(lVar4 + 0xc) != 0)) ||
         ((*(short *)(lVar4 + 0xe) != 0 || (*(short *)(lVar4 + 0x10) != 0)))) ||
        ((*(short *)(lVar4 + 0x12) != 0 ||
         ((*(short *)(lVar4 + 0x14) != 0 || (*(short *)(lVar4 + 0x16) != 0)))))) &&
       (*(char *)psVar1 != -1)) {
      AddOrUpdateIPv6RewriteTable(param_1,(undefined4 *)psVar1,(undefined4 *)(lVar3 + 6),bVar5);
    }
  }
  if (param_2 != '\0') {
    lVar3 = *(longlong *)(param_4 + 0x10);
    uVar6 = (ulonglong)*(ushort *)(lVar3 + 10);
    lVar3 = L2BridgeCloneNBL(*(longlong *)(param_4 + 0x18),param_1,
                             *(undefined8 *)(uVar6 + 0x20 + lVar3),
                             *(undefined1 *)(uVar6 + 0x11 + lVar3),
                             *(undefined1 *)(uVar6 + 0x12 + lVar3),
                             *(undefined1 *)(uVar6 + 0x15 + lVar3));
    if (lVar3 == 0) {
      DbgPrintEx(0x50,0);
    }
    else {
      if (*(int *)(param_1 + 100) == 8) {
        L2BridgeConvertToRawIPv6(lVar3,0,0);
      }
      cVar2 = ExAcquireRundownProtectionCacheAwareEx(*(undefined8 *)(param_1 + 0x98),1);
      LOCK();
      *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
      UNLOCK();
      if (cVar2 == '\x01') {
        NdisFIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x18),lVar3,param_5,1,param_6);
      }
      else {
        L2BridgeFreeNBL(lVar3,bVar5);
      }
    }
  }
  if (param_3 == '\0') {
    return;
  }
  if (*(char *)(param_1 + 0xa8) == '\0') {
    lVar3 = *(longlong *)(param_4 + 0x10);
    uVar6 = (ulonglong)*(ushort *)(lVar3 + 10);
    lVar3 = L2BridgeCloneNBL(*(longlong *)(param_4 + 0x18),param_1,
                             *(undefined8 *)(uVar6 + 0x20 + lVar3),
                             *(undefined1 *)(uVar6 + 0x11 + lVar3),
                             *(undefined1 *)(uVar6 + 0x12 + lVar3),
                             *(undefined1 *)(uVar6 + 0x15 + lVar3));
    if (lVar3 == 0) {
      pcVar7 = "Failed to clone packet!\n";
      goto LAB_14000220c;
    }
  }
  else {
    lVar3 = L2BridgeDeepCopyNBL(param_4,param_1);
    if (lVar3 == 0) {
      pcVar7 = "Failed to copy packet!\n";
LAB_14000220c:
      DbgPrintEx(0x50,0,pcVar7);
      return;
    }
    RewritePacket(param_1,lVar3);
  }
  lVar4 = lVar3;
  if (*(short *)(lVar3 + 0x140) != 0) {
    lVar4 = HandleRSCPacket(param_1,lVar3,(uint)bVar5);
    if (lVar4 == 0) goto LAB_1400022ef;
  }
  if (*(int *)(param_1 + 100) == 8) {
    L2BridgeConvertToRawIPv6(lVar4,0,0);
  }
  cVar2 = ExAcquireRundownProtectionCacheAwareEx(*(undefined8 *)(param_1 + 0x98),1);
  LOCK();
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
  UNLOCK();
  lVar3 = lVar4;
  if (cVar2 == '\x01') {
    NdisFSendNetBufferLists(*(undefined8 *)(param_1 + 0x18),lVar4,param_5,bVar5);
    return;
  }
LAB_1400022ef:
  L2BridgeFreeNBL(lVar3,bVar5);
  return;
}



===== GetLinkLayerAddressFromND @ 140002320 =====

char * GetLinkLayerAddressFromND(longlong param_1)

{
  longlong lVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = (char *)0x0;
  NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_1 + 8),0xe,0,0);
  lVar1 = NdisGetDataBuffer(*(undefined8 *)(param_1 + 8),0x28,0,1,0);
  NdisRetreatNetBufferDataStart(*(undefined8 *)(param_1 + 8),0xe,0,0);
  if (*(char *)(lVar1 + 6) == ':') {
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_1 + 8),0x36,0,0);
    pcVar2 = (char *)NdisGetDataBuffer(*(undefined8 *)(param_1 + 8),0x20,0,1,0);
    NdisRetreatNetBufferDataStart(*(undefined8 *)(param_1 + 8),0x36,0,0);
    if ((((pcVar2 != (char *)0x0) && ((byte)(*pcVar2 + 0x79U) < 2)) &&
        ((byte)(pcVar2[0x18] - 1U) < 2)) && (pcVar2[0x19] == '\x01')) {
      pcVar3 = pcVar2 + 0x1a;
    }
  }
  return pcVar3;
}



===== HandleRSCPacket @ 14000241c =====

longlong HandleRSCPacket(longlong param_1,longlong param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined4 local_res20;
  longlong local_48;
  
  local_48 = 0;
  if (*(short *)(param_2 + 0x140) != 0) {
    lVar3 = *(longlong *)(param_2 + 8);
    local_res10 = 0;
    local_res12 = 0;
    bVar4 = false;
    NdisGetDataBuffer(lVar3,0xe,0,1,0);
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_2 + 8),0xe,0,0);
    NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x28,0,1,0);
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_2 + 8),0x28,0,0);
    lVar7 = NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x14,0,1,0);
    NdisRetreatNetBufferDataStart(*(undefined8 *)(param_2 + 8),0x36,0,0);
    bVar1 = *(byte *)(lVar7 + 0xc);
    iVar6 = *(int *)(lVar3 + 0x18);
    uVar9 = *(uint *)(param_2 + 0xa0) & 0xfffff | 0xc3600000;
    *(uint *)(param_2 + 0xa0) = uVar9;
    uVar11 = (uint)(bVar1 >> 4);
    uVar5 = (*(int *)(param_1 + 0x8c) + uVar11 * -4) - 0x36;
    uVar10 = (iVar6 + uVar11 * -4) - 0x36;
    *(uint *)(param_2 + 0xa0) = (uVar9 ^ uVar5) & 0xfffff ^ uVar9;
    NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x10),&local_res10,CONCAT71(0xfff,param_3 != 0))
    ;
    if ((((1 < *(uint *)(param_1 + 0x7c)) && (uVar10 < *(uint *)(param_1 + 0x80))) &&
        (*(uint *)(param_1 + 0x84) <= uVar10 / (uVar5 & 0xfffff) + 1)) &&
       ((uVar11 == 5 || ((*(uint *)(param_1 + 0x88) & 0xc) != 0)))) {
      bVar4 = true;
    }
    uVar8 = *(undefined8 *)(param_1 + 0x10);
    NdisReleaseRWLock(uVar8,&local_res10);
    if (bVar4) {
      local_48 = param_2;
    }
    else {
      local_48 = 0;
      local_res20 = 0;
      iVar6 = SegLibCreateMultiNbNblClone(uVar8,param_2);
      lVar3 = lRam0000000000000010;
      if (iVar6 < 0) {
        DbgPrintEx(0x50,0,"Failed to segment packet: 0x%x.\n",iVar6);
        local_48 = 0;
      }
      else {
        uVar2 = *(ushort *)(lRam0000000000000010 + 10);
        *(undefined1 *)((ulonglong)uVar2 + 0x16 + lRam0000000000000010) = 1;
        *(undefined4 *)((ulonglong)uVar2 + 0x18 + lVar3) = local_res20;
        uRam0000000000000078 = *(undefined8 *)(param_1 + 0x18);
      }
    }
  }
  return local_48;
}



===== IPv6RewriteTableComparator @ 140002670 =====

ulonglong IPv6RewriteTableComparator(longlong param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_1 + 0x24);
  if ((param_2[1] == uVar1) && (uVar1 = *(ulonglong *)(param_1 + 0x1c), *param_2 == uVar1)) {
    return CONCAT71((int7)(uVar1 >> 8),1);
  }
  return uVar1 & 0xffffffffffffff00;
}



===== MACAddressTableRemovedCallback @ 1400026a0 =====

void MACAddressTableRemovedCallback(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0x7242324c);
  }
  return;
}



===== IPv6RewriteTableShouldRemoveCallback @ 1400026d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong IPv6RewriteTableShouldRemoveCallback(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = _DAT_fffff78000000008;
  if ((_DAT_fffff78000000008 < 3000000000) ||
     (uVar1 = _DAT_fffff78000000008 - 3000000000, uVar1 < *(ulonglong *)(param_1 + 0x38))) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = DbgPrintEx(0x50,0,
                       "Aging out: %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x\n"
                       ,*(undefined1 *)(param_1 + 0x1c),*(undefined1 *)(param_1 + 0x1d),
                       *(undefined1 *)(param_1 + 0x1e),*(undefined1 *)(param_1 + 0x1f),
                       *(undefined1 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x21),
                       *(undefined1 *)(param_1 + 0x22),*(undefined1 *)(param_1 + 0x23),
                       *(undefined1 *)(param_1 + 0x24),*(undefined1 *)(param_1 + 0x25),
                       *(undefined1 *)(param_1 + 0x26),*(undefined1 *)(param_1 + 0x27),
                       *(undefined1 *)(param_1 + 0x28),*(undefined1 *)(param_1 + 0x29),
                       *(undefined1 *)(param_1 + 0x2a),*(undefined1 *)(param_1 + 0x2b));
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return uVar1;
}



===== IsIPv6 @ 140002814 =====

bool IsIPv6(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  ushort uVar3;
  bool bVar4;
  
  bVar4 = false;
  if (*(int *)(param_1 + 100) == 8) {
    if ((*(uint *)(param_2 + 0x80) >> 9 & 1) != 0) {
      return false;
    }
    if ((*(uint *)(param_2 + 0x80) >> 10 & 1) != 0) {
      lVar1 = NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x28,0,1,0);
      return lVar1 != 0;
    }
  }
  lVar1 = *(longlong *)(param_2 + 8);
  lVar2 = NdisGetDataBuffer(lVar1,0xe,0,1,0);
  if (lVar2 != 0) {
    uVar3 = *(ushort *)(lVar2 + 0xc) >> 8 | *(ushort *)(lVar2 + 0xc) << 8;
    if (uVar3 < 0x601) {
      if (*(uint *)(lVar1 + 0x18) < 0x16) {
        return false;
      }
      if (*(char *)(lVar2 + 0xe) != -0x56) {
        return false;
      }
      if (*(char *)(lVar2 + 0xf) != -0x56) {
        return false;
      }
      if (*(char *)(lVar2 + 0x10) != '\x03') {
        return false;
      }
      uVar3 = *(ushort *)(lVar2 + 0x14) >> 8 | *(ushort *)(lVar2 + 0x14) << 8;
    }
    if (uVar3 == 0x86dd) {
      NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_2 + 8),0xe,0);
      lVar1 = NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x28,0,1,0);
      if (lVar1 == 0) {
        NdisRetreatNetBufferDataStart();
      }
      else {
        NdisRetreatNetBufferDataStart(*(undefined8 *)(param_2 + 8),0xe,0);
        bVar4 = true;
      }
    }
  }
  return bVar4;
}



===== L2BridgeCloneIPv6NBL @ 140002968 =====

longlong L2BridgeCloneIPv6NBL
                   (longlong param_1,longlong param_2,undefined8 param_3,undefined1 param_4,
                   undefined1 param_5,char param_6)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  char *pcVar6;
  longlong lVar7;
  undefined8 *puVar8;
  uint uVar9;
  
  puVar8 = *(undefined8 **)(param_1 + 8);
  lVar7 = 0;
  uVar9 = 0;
  do {
    if (puVar8 == (undefined8 *)0x0) {
      *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xfffffbff;
      *(undefined8 *)(param_1 + 200) = 0;
      lVar7 = L2BridgeCloneNBL(param_1,param_2,param_3,param_4,param_5,1);
      if (lVar7 == 0) {
LAB_140002b24:
        L2BridgeConvertToRawIPv6(param_1,1,uVar9);
      }
      return lVar7;
    }
    lVar4 = NdisGetDataBuffer(puVar8,0x28,0,1,0);
    if (lVar4 == 0) {
      pcVar6 = "Failed to get ipv6 header.";
LAB_140002b63:
      DbgPrintEx(0x50,0,pcVar6);
      goto LAB_140002b24;
    }
    iVar3 = NdisRetreatNetBufferDataStart(puVar8,0xe);
    if (iVar3 != 0) {
      pcVar6 = "Failed to allocate ethernet header.";
      goto LAB_140002b63;
    }
    uVar9 = uVar9 + 1;
    puVar5 = (undefined8 *)NdisGetDataBuffer(puVar8,0xe,0,1,0);
    if (puVar5 == (undefined8 *)0x0) {
      pcVar6 = "Failed to get ethernet header.";
      goto LAB_140002b63;
    }
    *puVar5 = 0;
    *(undefined4 *)(puVar5 + 1) = 0;
    *(undefined2 *)((longlong)puVar5 + 0xc) = 0;
    pcVar6 = GetLinkLayerAddressFromND(param_1);
    if (pcVar6 == (char *)0x0) {
      *(undefined4 *)((longlong)puVar5 + 6) = *(undefined4 *)(param_2 + 0x68);
      *(undefined2 *)((longlong)puVar5 + 10) = *(undefined2 *)(param_2 + 0x6c);
      *(byte *)((longlong)puVar5 + 6) = *(byte *)((longlong)puVar5 + 6) | 2;
    }
    else {
      *(undefined4 *)((longlong)puVar5 + 6) = *(undefined4 *)pcVar6;
      *(undefined2 *)((longlong)puVar5 + 10) = *(undefined2 *)(pcVar6 + 4);
    }
    if ((*(char *)(lVar4 + 0x18) == -1) || (pcVar6 != (char *)0x0)) {
      *(undefined4 *)puVar5 = 0x3333;
      uVar2 = 0x100;
LAB_140002ad1:
      *(undefined2 *)((longlong)puVar5 + 4) = uVar2;
    }
    else {
      lVar4 = LookupIPv6AddressInTable(param_2,(char *)(lVar4 + 0x18),param_6);
      if (lVar4 == 0) {
        *(undefined4 *)puVar5 = *(undefined4 *)(param_2 + 0x68);
        uVar2 = *(undefined2 *)(param_2 + 0x6c);
        goto LAB_140002ad1;
      }
      *(undefined4 *)puVar5 = *(undefined4 *)(lVar4 + 0x2c);
      *(undefined2 *)((longlong)puVar5 + 4) = *(undefined2 *)(lVar4 + 0x30);
      LOCK();
      piVar1 = (int *)(lVar4 + 0x18);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        ExFreePoolWithTag(lVar4,0x7242324c);
      }
    }
    *(undefined2 *)((longlong)puVar5 + 0xc) = 0xdd86;
    puVar8 = (undefined8 *)*puVar8;
  } while( true );
}



===== L2BridgeCloneNBL @ 140002b7c =====

longlong L2BridgeCloneNBL(longlong param_1,longlong param_2,undefined8 param_3,undefined1 param_4,
                         undefined1 param_5,undefined1 param_6)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = NdisAllocateCloneNetBufferList(param_1,*(undefined8 *)(param_2 + 0xb8),0,0);
  if (lVar4 == 0) {
    DbgPrintEx(0x50,0,"Failed to clone NBL.\n");
  }
  else {
    iVar3 = NdisAllocateNetBufferListContext(lVar4,0x28,0,0x7242324c);
    if (iVar3 == 0) {
      *(uint *)(lVar4 + 0x80) = *(uint *)(lVar4 + 0x80) | *(uint *)(param_1 + 0x80) & 0x600;
      NdisCopySendNetBufferListInfo(lVar4,param_1);
      NdisCopyReceiveNetBufferListInfo(lVar4,param_1);
      *(longlong *)(lVar4 + 0x18) = param_1;
      LOCK();
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
      UNLOCK();
      lVar2 = *(longlong *)(lVar4 + 0x10);
      *(undefined8 *)(lVar4 + 0x78) = *(undefined8 *)(param_2 + 0x18);
      uVar5 = (ulonglong)*(ushort *)(lVar2 + 10);
      puVar1 = (undefined8 *)(uVar5 + 0x10 + lVar2);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1 = (undefined8 *)(uVar5 + 0x20 + lVar2);
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined8 *)(uVar5 + 0x30 + lVar2) = 0;
      *(undefined1 *)(uVar5 + 0x12 + lVar2) = param_5;
      *(undefined1 *)(uVar5 + 0x15 + lVar2) = param_6;
      *(undefined8 *)(uVar5 + 0x20 + lVar2) = param_3;
      *(undefined1 *)(uVar5 + 0x11 + lVar2) = param_4;
    }
    else {
      DbgPrintEx(0x50,0,"Failed to alloc context for cloned NBL.\n");
      NdisFreeCloneNetBufferList(lVar4,0);
      lVar4 = 0;
    }
  }
  return lVar4;
}



===== L2BridgeConvertToRawIPv6 @ 140002cd0 =====

void L2BridgeConvertToRawIPv6(longlong param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 8);
  for (uVar1 = 0; (puVar2 != (undefined8 *)0x0 && ((param_3 == 0 || (uVar1 < param_3))));
      uVar1 = uVar1 + 1) {
    NdisAdvanceNetBufferDataStart(puVar2,0xe,param_2);
    puVar2 = (undefined8 *)*puVar2;
  }
  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x400;
  *(undefined8 *)(param_1 + 200) = 0xdd86;
  return;
}



===== L2BridgeDeepCopyNBL @ 140002d5c =====

longlong L2BridgeDeepCopyNBL(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined4 local_res18 [4];
  
  lVar3 = NdisAllocateCloneNetBufferList(param_1,0,0,2);
  if (lVar3 != 0) {
    NdisCopySendNetBufferListInfo(lVar3,param_1);
    NdisCopyReceiveNetBufferListInfo(lVar3,param_1);
    for (puVar4 = *(undefined8 **)(lVar3 + 8); puVar4 != (undefined8 *)0x0;
        puVar4 = (undefined8 *)*puVar4) {
      puVar4[1] = 0;
      *(undefined4 *)(puVar4 + 2) = 0;
      *(undefined4 *)(puVar4 + 3) = 0;
      *(undefined4 *)(puVar4 + 5) = 0;
      puVar4[4] = 0;
    }
    iVar2 = NdisAllocateNetBufferListContext(lVar3,0x28,0,0x7242324c);
    if (iVar2 == 0) {
      lVar1 = *(longlong *)(lVar3 + 0x10);
      uVar5 = (ulonglong)*(ushort *)(lVar1 + 10);
      puVar4 = (undefined8 *)(uVar5 + 0x10 + lVar1);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4 = (undefined8 *)(uVar5 + 0x20 + lVar1);
      *puVar4 = 0;
      puVar4[1] = 0;
      *(undefined8 *)(uVar5 + 0x30 + lVar1) = 0;
      *(undefined1 *)(uVar5 + 0x10 + lVar1) = 1;
      puVar6 = *(undefined8 **)(lVar3 + 8);
      for (puVar4 = *(undefined8 **)(param_1 + 8); puVar4 != (undefined8 *)0x0;
          puVar4 = (undefined8 *)*puVar4) {
        local_res18[0] = 0;
        iVar2 = NdisRetreatNetBufferDataStart(puVar6,*(undefined4 *)(puVar4 + 3),0,0);
        if (iVar2 != 0) {
LAB_140002e9a:
          NdisFreeNetBufferListContext(lVar3,0x28);
          goto LAB_140002eae;
        }
        iVar2 = NdisCopyFromNetBufferToNetBuffer
                          (puVar6,0,*(undefined4 *)(puVar4 + 3),puVar4,0,local_res18);
        if (iVar2 != 0) goto LAB_140002e9a;
        puVar6 = (undefined8 *)*puVar6;
      }
      *(undefined8 *)(lVar3 + 0x78) = *(undefined8 *)(param_2 + 0x18);
      *(undefined4 *)(lVar3 + 0x80) = *(undefined4 *)(param_1 + 0x80);
    }
    else {
LAB_140002eae:
      for (puVar4 = *(undefined8 **)(lVar3 + 8); puVar4 != (undefined8 *)0x0;
          puVar4 = (undefined8 *)*puVar4) {
        if (*(int *)(puVar4 + 3) != 0) {
          NdisAdvanceNetBufferDataStart(puVar4,*(int *)(puVar4 + 3),1,0);
        }
      }
      NdisFreeNetBufferList(lVar3);
      lVar3 = 0;
    }
  }
  return lVar3;
}



===== L2BridgeFreeNBL @ 140002f08 =====

void L2BridgeFreeNBL(longlong param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  char *pcVar8;
  
  pcVar8 = (char *)(*(longlong *)(param_1 + 0x10) + 0x10 +
                   (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x10) + 10));
  cVar3 = pcVar8[6];
  while (cVar3 != '\0') {
    lVar4 = *(longlong *)(param_1 + 0x18);
    NdisFreeFragmentNetBufferList(param_1,*(undefined4 *)(pcVar8 + 8));
    lVar5 = *(longlong *)(lVar4 + 0x10);
    pcVar8 = (char *)(lVar5 + 0x10 + (ulonglong)*(ushort *)(lVar5 + 10));
    param_1 = lVar4;
    cVar3 = *(char *)((ulonglong)*(ushort *)(lVar5 + 10) + 0x16 + lVar5);
  }
  if (*pcVar8 == '\0') {
    if (*(int *)(param_1 + 0x84) == 0) {
      lVar4 = *(longlong *)(param_1 + 0x18);
      LOCK();
      piVar1 = (int *)(lVar4 + 0x84);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        puVar6 = (undefined4 *)NdisGetDataBuffer(*(undefined8 *)(param_1 + 8),0xe,0,1,0);
        if (pcVar8[3] != '\0') {
          *(undefined4 *)((longlong)puVar6 + 6) = *(undefined4 *)(pcVar8 + 0x18);
          *(undefined2 *)((longlong)puVar6 + 10) = *(undefined2 *)(pcVar8 + 0x1c);
        }
        if (pcVar8[4] != '\0') {
          *puVar6 = *(undefined4 *)(pcVar8 + 0x1e);
          *(undefined2 *)(puVar6 + 1) = *(undefined2 *)(pcVar8 + 0x22);
        }
        if (pcVar8[5] != '\0') {
          L2BridgeConvertToRawIPv6(lVar4,1,0);
        }
        if (pcVar8[2] != '\0') {
          NdisFReturnNetBufferLists
                    (*(undefined8 *)(*(longlong *)(pcVar8 + 0x10) + 0x18),lVar4,param_2 != '\0');
        }
        if (pcVar8[1] != '\0') {
          NdisFSendNetBufferListsComplete
                    (*(undefined8 *)(*(longlong *)(pcVar8 + 0x10) + 0x18),lVar4,param_2 != '\0');
        }
      }
      *(undefined8 *)(param_1 + 0x18) = 0;
      NdisFreeNetBufferListContext(param_1,0x28);
      NdisFreeCloneNetBufferList(param_1,0);
    }
  }
  else {
    NdisFreeNetBufferListContext(param_1,0x28);
    for (puVar7 = *(undefined8 **)(param_1 + 8); puVar7 != (undefined8 *)0x0;
        puVar7 = (undefined8 *)*puVar7) {
      if (*(int *)(puVar7 + 3) != 0) {
        NdisAdvanceNetBufferDataStart(puVar7,*(int *)(puVar7 + 3),1,0);
      }
    }
    NdisFreeNetBufferList(param_1);
  }
  return;
}



===== L2BridgeIssueOid @ 1400030d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong L2BridgeIssueOid(undefined8 param_1,undefined4 param_2,undefined8 param_3,
                          undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStack_168 [32];
  undefined8 local_148;
  undefined1 local_138 [24];
  uint local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  memset(local_138,0,0x118);
  local_118 = 0xf80196;
  local_f8 = 0x1010e;
  local_e8 = 4;
  local_114 = param_2;
  local_f0 = param_4;
  KeInitializeEvent(local_138,1);
  uVar1 = NdisFOidRequest(param_1,&local_118);
  if ((int)uVar1 == 0x103) {
    local_148 = 0;
    KeWaitForSingleObject(local_138,0,0,0);
    uVar1 = (ulonglong)local_120;
  }
  return uVar1;
}



===== LookupIPv6AddressInTable @ 1400031c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong LookupIPv6AddressInTable(longlong param_1,undefined8 param_2,char param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  local_res18 = 0;
  local_res1a = 0;
  uVar1 = RtlCompute37Hash(IPv6RewriteTableHashSeed,param_2,0x10);
  uVar1 = uVar1 & 0xffffffff;
  if (uVar1 == 0) {
    uVar1 = 0xffffffffffffffff;
  }
  NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0xd0),&local_res18,param_3 != '\0');
  lVar2 = LookupTable(*(undefined8 *)(param_1 + 200),uVar1,param_2,IPv6RewriteTableComparator,
                      (undefined8 *)0x0);
  lVar3 = 0;
  if (lVar2 != 0) {
    LOCK();
    *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + 1;
    UNLOCK();
    *(undefined8 *)(lVar2 + 0x38) = _DAT_fffff78000000008;
    lVar3 = lVar2;
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0xd0),&local_res18);
  return lVar3;
}



===== LookupMACAddressInTable @ 14000329c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong LookupMACAddressInTable(longlong param_1,undefined8 param_2,char param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  local_res18 = 0;
  local_res1a = 0;
  uVar1 = RtlCompute37Hash(MACAddressTableHashSeed,param_2,6);
  uVar1 = uVar1 & 0xffffffff;
  if (uVar1 == 0) {
    uVar1 = 0xffffffffffffffff;
  }
  NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x20),&local_res18,param_3 != '\0');
  lVar2 = LookupTable(*(undefined8 *)(param_1 + 0x18),uVar1,param_2,MACAddressTableComparator,
                      (undefined8 *)0x0);
  lVar3 = 0;
  if (lVar2 != 0) {
    LOCK();
    *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + 1;
    UNLOCK();
    *(undefined8 *)(lVar2 + 0x28) = _DAT_fffff78000000008;
    lVar3 = lVar2;
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x20),&local_res18);
  return lVar3;
}



===== LookupTable @ 140003370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong LookupTable(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined *param_4,
                    undefined8 *param_5)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar3 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  lVar2 = RtlLookupEntryHashTable(0,param_2,&local_28);
  do {
    if (lVar2 == 0) {
LAB_1400033e5:
      if (param_5 != (undefined8 *)0x0) {
        *param_5 = local_28;
        param_5[1] = uStack_20;
        param_5[2] = local_18;
      }
      return lVar3;
    }
    cVar1 = (*(code *)param_4)(lVar2,param_3);
    if (cVar1 != '\0') {
      lVar3 = lVar2;
      goto LAB_1400033e5;
    }
    lVar2 = RtlGetNextEntryHashTable(param_1,&local_28);
  } while( true );
}



===== MACAddressTableComparator @ 140003430 =====

bool MACAddressTableComparator(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = RtlCompareMemory(param_2,param_1 + 0x1c,6);
  return lVar1 == 6;
}



===== MACAddressTableShouldRemoveCallback @ 140003470 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 MACAddressTableShouldRemoveCallback(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if ((_DAT_fffff78000000008 < 3000000000) ||
     (_DAT_fffff78000000008 - 3000000000 < *(ulonglong *)(param_1 + 0x28))) {
    uVar1 = 0;
  }
  else {
    DbgPrintEx(0x50,0,"Aging out: %02x:%02x:%02x:%02x:%02x:%02x\n",*(undefined1 *)(param_1 + 0x1c),
               *(undefined1 *)(param_1 + 0x1d),*(undefined1 *)(param_1 + 0x1e),
               *(undefined1 *)(param_1 + 0x1f),*(undefined1 *)(param_1 + 0x20),
               *(undefined1 *)(param_1 + 0x21));
  }
  return uVar1;
}



===== MulticastNBLToFilterModules @ 140003504 =====

void MulticastNBLToFilterModules
               (longlong param_1,longlong param_2,undefined4 param_3,char param_4,char param_5)

{
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0xe0) + 0x30);
  if (param_1 == lVar4) {
    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0xe0) + 0x38);
  }
  lVar2 = *(longlong *)(param_2 + 0x10);
  uVar3 = (ulonglong)*(ushort *)(lVar2 + 10);
  lVar2 = L2BridgeCloneNBL(*(longlong *)(param_2 + 0x18),param_1,
                           *(undefined8 *)(uVar3 + 0x20 + lVar2),
                           *(undefined1 *)(uVar3 + 0x11 + lVar2),
                           *(undefined1 *)(uVar3 + 0x12 + lVar2),
                           *(undefined1 *)(uVar3 + 0x15 + lVar2));
  if (lVar2 == 0) {
    DbgPrintEx(0x50,0,"Failed to clone packet!\n");
  }
  else {
    cVar1 = ExAcquireRundownProtectionCacheAwareEx(*(undefined8 *)(param_1 + 0x98));
    LOCK();
    *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
    UNLOCK();
    if (cVar1 == '\x01') {
      if (*(int *)(param_1 + 100) == 8) {
        L2BridgeConvertToRawIPv6(lVar2,0,0);
      }
      if (param_5 == '\0') {
        NdisFIndicateReceiveNetBufferLists
                  (*(undefined8 *)(param_1 + 0x18),lVar2,param_3,1,param_4 != '\0');
      }
      else {
        NdisFSendNetBufferLists();
      }
    }
    else {
      L2BridgeFreeNBL(lVar2,param_4);
    }
  }
  ForwardNBLToFilterModule(lVar4,'\x01','\x01',param_2,param_3,(uint)(param_4 != '\0'));
  return;
}



===== ReceiveNetBufferList @ 14000366c =====

void ReceiveNetBufferList(longlong param_1,longlong param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  longlong lVar5;
  char *pcVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  byte bVar10;
  longlong lVar11;
  byte bVar12;
  uint uVar13;
  
  bVar10 = (byte)param_4;
  bVar12 = bVar10 & 1;
  uVar13 = param_4 & 0xfffffffd;
  lVar11 = 0;
  if ((*(uint *)(param_2 + 0x80) & 0x400) == 0) {
    lVar5 = L2BridgeCloneNBL(param_2,param_1,param_1,0,1,0);
  }
  else {
    lVar5 = L2BridgeCloneIPv6NBL(param_2,param_1,param_1,0,1,bVar10 & 1);
  }
  if (lVar5 == 0) {
    NdisFIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x18),param_2,param_3,1,uVar13);
  }
  else {
    lVar9 = (ulonglong)*(ushort *)(*(longlong *)(lVar5 + 0x10) + 10) + *(longlong *)(lVar5 + 0x10);
    pcVar6 = (char *)NdisGetDataBuffer(*(undefined8 *)(lVar5 + 8),0xe,0,1,0);
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(lVar5 + 8),0xe,0,0);
    lVar7 = NdisGetDataBuffer(*(undefined8 *)(lVar5 + 8),0x28,0,1,0);
    NdisRetreatNetBufferDataStart(*(undefined8 *)(lVar5 + 8),0xe);
    cVar4 = '\0';
    if (*(char *)(param_1 + 0xa9) != '\0') {
      bVar3 = pcVar6[6];
      if (((bVar3 & 1) == 0) &&
         (((((bVar3 != 0xff || (pcVar6[7] != -1)) || (pcVar6[8] != -1)) ||
           ((pcVar6[9] != -1 || (pcVar6[10] != -1)))) || (pcVar6[0xb] != -1)))) {
        AddOrUpdateMACForwardingTable
                  (*(longlong *)(param_1 + 0xe0),(undefined4 *)(pcVar6 + 6),0,param_1,bVar10 & 1);
      }
    }
    if ((*(char *)(param_1 + 0xa8) != '\0') &&
       (lVar8 = LookupIPv6AddressInTable(param_1,lVar7 + 0x18,bVar12), lVar8 != 0)) {
      if (*(char *)(lVar9 + 0x14) != '\0') {
        *(undefined4 *)(lVar9 + 0x2e) = *(undefined4 *)pcVar6;
        *(undefined2 *)(lVar9 + 0x32) = *(undefined2 *)(pcVar6 + 4);
      }
      *(undefined1 *)(lVar9 + 0x14) = 1;
      *(undefined4 *)pcVar6 = *(undefined4 *)(lVar8 + 0x2c);
      *(undefined2 *)(pcVar6 + 4) = *(undefined2 *)(lVar8 + 0x30);
      LOCK();
      piVar1 = (int *)(lVar8 + 0x18);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        ExFreePoolWithTag(lVar8,0x7242324c);
      }
    }
    if ((*(char *)(lVar7 + 0x18) == -1) || ((*pcVar6 == '3' && (pcVar6[1] == '3')))) {
      if ((*pcVar6 != '3') && (pcVar6[1] != '3')) {
        if (*(char *)(lVar9 + 0x14) != '\0') {
          *(undefined4 *)(lVar9 + 0x2e) = *(undefined4 *)pcVar6;
          *(undefined2 *)(lVar9 + 0x32) = *(undefined2 *)(pcVar6 + 4);
        }
        *(undefined1 *)(lVar9 + 0x14) = 1;
        pcVar6[0] = '3';
        pcVar6[1] = '3';
        pcVar6[2] = '\0';
        pcVar6[3] = '\0';
        pcVar6[4] = '\0';
        pcVar6[5] = '\x01';
      }
      MulticastNBLToFilterModules(param_1,lVar5,param_3,bVar12,'\0');
    }
    else {
      lVar9 = LookupMACAddressInTable(*(longlong *)(param_1 + 0xe0),pcVar6,bVar12);
      if (lVar9 != 0) {
        cVar4 = *(char *)(lVar9 + 0x30);
        lVar11 = *(longlong *)(lVar9 + 0x38);
        LOCK();
        piVar1 = (int *)(lVar9 + 0x18);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          ExFreePoolWithTag(lVar9,0x7242324c);
        }
      }
      if (lVar11 == param_1) {
        cVar4 = ExAcquireRundownProtectionCacheAwareEx(*(undefined8 *)(param_1 + 0x98));
        LOCK();
        *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
        UNLOCK();
        if (cVar4 == '\x01') {
          if (*(int *)(param_1 + 100) == 8) {
            L2BridgeConvertToRawIPv6(lVar5,0,0);
          }
          NdisFIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x18),lVar5,param_3,1,uVar13)
          ;
          lVar5 = 0;
        }
        if (lVar5 == 0) {
          return;
        }
      }
      else if (lVar11 == 0) {
        DbgPrintEx(0x50,0,
                   "Received Packet: Don\'t know what to do:\n\tSource MAC:%02x:%02x:%02x:%02x:%02x:%02x\n\tDest MAC:%02x:%02x:%02x:%02x:%02x:%02x\n\tSource IPV6: %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x\n\tDest IPV6: %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x\n"
                   ,pcVar6[6],pcVar6[7],pcVar6[8],pcVar6[9],pcVar6[10],pcVar6[0xb],*pcVar6,pcVar6[1]
                   ,pcVar6[2],pcVar6[3],pcVar6[4],pcVar6[5],*(undefined1 *)(lVar7 + 8),
                   *(undefined1 *)(lVar7 + 9),*(undefined1 *)(lVar7 + 10),
                   *(undefined1 *)(lVar7 + 0xb),*(undefined1 *)(lVar7 + 0xc),
                   *(undefined1 *)(lVar7 + 0xd),*(undefined1 *)(lVar7 + 0xe),
                   *(undefined1 *)(lVar7 + 0xf),*(undefined1 *)(lVar7 + 0x10),
                   *(undefined1 *)(lVar7 + 0x11),*(undefined1 *)(lVar7 + 0x12),
                   *(undefined1 *)(lVar7 + 0x13),*(undefined1 *)(lVar7 + 0x14),
                   *(undefined1 *)(lVar7 + 0x15),*(undefined1 *)(lVar7 + 0x16),
                   *(undefined1 *)(lVar7 + 0x17),*(undefined1 *)(lVar7 + 0x18),
                   *(undefined1 *)(lVar7 + 0x19),*(undefined1 *)(lVar7 + 0x1a),
                   *(undefined1 *)(lVar7 + 0x1b),*(undefined1 *)(lVar7 + 0x1c),
                   *(undefined1 *)(lVar7 + 0x1d),*(undefined1 *)(lVar7 + 0x1e),
                   *(undefined1 *)(lVar7 + 0x1f),*(undefined1 *)(lVar7 + 0x20),
                   *(undefined1 *)(lVar7 + 0x21),*(undefined1 *)(lVar7 + 0x22),
                   *(undefined1 *)(lVar7 + 0x23),*(undefined1 *)(lVar7 + 0x24),
                   *(undefined1 *)(lVar7 + 0x25),*(undefined1 *)(lVar7 + 0x26),
                   *(undefined1 *)(lVar7 + 0x27));
      }
      else {
        ForwardNBLToFilterModule(lVar11,cVar4,cVar4 == '\0',lVar5,param_3,uVar13);
      }
    }
    L2BridgeFreeNBL(lVar5,bVar10 & 1);
  }
  return;
}



===== RemoveUnusedEntries @ 140003dd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RemoveUnusedEntries(undefined8 param_1,undefined *param_2,undefined *param_3)

{
  char cVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  cVar1 = RtlInitEnumerationHashTable(0,&local_38);
  if (cVar1 != '\0') {
    while (lVar2 = RtlEnumerateEntryHashTable(param_1,&local_38), lVar2 != 0) {
      cVar1 = (*(code *)param_2)(lVar2);
      if (cVar1 != '\0') {
        RtlRemoveEntryHashTable(param_1,lVar2,0);
        (*(code *)param_3)(lVar2);
      }
    }
    RtlEndEnumerationHashTable(param_1,&local_38);
  }
  return;
}



===== RewritePacket @ 140003e98 =====

void RewritePacket(longlong param_1,longlong param_2)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  char *pcVar5;
  ushort *puVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  ushort *puVar10;
  uint uVar11;
  
  lVar9 = (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10) + *(longlong *)(param_2 + 0x10)
  ;
  lVar4 = NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0xe,0,1,0);
  if (*(char *)(lVar9 + 0x13) != '\0') {
    *(undefined4 *)(lVar9 + 0x28) = *(undefined4 *)(lVar4 + 6);
    *(undefined2 *)(lVar9 + 0x2c) = *(undefined2 *)(lVar4 + 10);
  }
  *(undefined1 *)(lVar9 + 0x13) = 1;
  *(undefined4 *)(lVar4 + 6) = *(undefined4 *)(param_1 + 0x68);
  *(undefined2 *)(lVar4 + 10) = *(undefined2 *)(param_1 + 0x6c);
  pcVar5 = GetLinkLayerAddressFromND(param_2);
  if (pcVar5 != (char *)0x0) {
    *(undefined4 *)pcVar5 = *(undefined4 *)(param_1 + 0x68);
    *(undefined2 *)(pcVar5 + 4) = *(undefined2 *)(param_1 + 0x6c);
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_2 + 8),0xe,0);
    lVar4 = NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),0x28,0,1,0);
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(param_2 + 8),0x28,0);
    lVar9 = 8;
    puVar6 = (ushort *)NdisGetDataBuffer(*(undefined8 *)(param_2 + 8),8,0,1,0);
    puVar6[1] = 0;
    uVar2 = *(ushort *)(*(longlong *)(param_2 + 8) + 0x18);
    uVar11 = (uint)(ushort)(uVar2 >> 8 | uVar2 << 8) + (uint)*(byte *)(lVar4 + 6) * 0x100;
    puVar10 = (ushort *)(lVar4 + 8);
    do {
      uVar3 = *puVar10;
      puVar1 = puVar10 + 8;
      puVar10 = puVar10 + 1;
      uVar11 = uVar11 + uVar3 + (uint)*puVar1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    if (uVar2 >> 1 != 0) {
      uVar8 = (ulonglong)(uint)(uVar2 >> 1);
      puVar10 = puVar6;
      do {
        uVar2 = *puVar10;
        puVar10 = puVar10 + 1;
        uVar11 = uVar11 + uVar2;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    iVar7 = (uVar11 >> 0x10) + (uVar11 & 0xffff);
    puVar6[1] = ~((short)((uint)iVar7 >> 0x10) + (short)iVar7);
    NdisRetreatNetBufferDataStart(*(undefined8 *)(param_2 + 8),0x28,0);
    NdisRetreatNetBufferDataStart(*(undefined8 *)(param_2 + 8),0xe,0);
  }
  return;
}



===== SendNetBufferList @ 140004070 =====

void SendNetBufferList(longlong param_1,longlong param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  longlong lVar4;
  char cVar5;
  longlong lVar6;
  char *pcVar7;
  longlong lVar8;
  byte bVar9;
  byte bVar10;
  
  bVar9 = (byte)param_4;
  bVar10 = bVar9 & 1;
  if ((*(uint *)(param_2 + 0x80) & 0x400) == 0) {
    lVar6 = L2BridgeCloneNBL(param_2,param_1,param_1,1,0,0);
  }
  else {
    lVar6 = L2BridgeCloneIPv6NBL(param_2,param_1,param_1,1,0,bVar9 & 1);
  }
  if (lVar6 == 0) {
    lVar6 = param_2;
LAB_1400040e1:
    NdisFSendNetBufferLists(*(undefined8 *)(param_1 + 0x18),lVar6,param_3,param_4);
  }
  else {
    pcVar7 = (char *)NdisGetDataBuffer(*(undefined8 *)(lVar6 + 8),0xe,0,1,0);
    NdisAdvanceNetBufferDataStart(*(undefined8 *)(lVar6 + 8),0xe,0,0);
    lVar8 = NdisGetDataBuffer(*(undefined8 *)(lVar6 + 8),0x28,0,1,0);
    NdisRetreatNetBufferDataStart(*(undefined8 *)(lVar6 + 8),0xe,0);
    if (*(char *)(param_1 + 0xa9) != '\0') {
      bVar3 = pcVar7[6];
      if (((bVar3 & 1) == 0) &&
         (((((bVar3 != 0xff || (pcVar7[7] != -1)) || (pcVar7[8] != -1)) ||
           ((pcVar7[9] != -1 || (pcVar7[10] != -1)))) || (pcVar7[0xb] != -1)))) {
        AddOrUpdateMACForwardingTable
                  (*(longlong *)(param_1 + 0xe0),(undefined4 *)(pcVar7 + 6),1,param_1,bVar9 & 1);
      }
    }
    if ((*(char *)(lVar8 + 0x18) == -1) || ((*pcVar7 == '3' && (pcVar7[1] == '3')))) {
      MulticastNBLToFilterModules(param_1,lVar6,param_3,bVar10,'\x01');
    }
    else {
      lVar8 = LookupMACAddressInTable(*(longlong *)(param_1 + 0xe0),pcVar7,bVar10);
      if (lVar8 != 0) {
        lVar4 = *(longlong *)(lVar8 + 0x38);
        cVar5 = *(char *)(lVar8 + 0x30);
        LOCK();
        piVar1 = (int *)(lVar8 + 0x18);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          ExFreePoolWithTag(lVar8,0x7242324c);
        }
        if ((lVar4 != 0) && (lVar4 != param_1)) {
          ForwardNBLToFilterModule(lVar4,cVar5,cVar5 == '\0',lVar6,param_3,(uint)bVar10);
          goto LAB_1400042a4;
        }
      }
      cVar5 = ExAcquireRundownProtectionCacheAwareEx(*(undefined8 *)(param_1 + 0x98));
      LOCK();
      *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
      UNLOCK();
      if (cVar5 == '\x01') {
        if (*(int *)(param_1 + 100) == 8) {
          L2BridgeConvertToRawIPv6(lVar6,0,0);
        }
        goto LAB_1400040e1;
      }
    }
LAB_1400042a4:
    L2BridgeFreeNBL(lVar6,bVar10);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_hL2BridgeProviderProv @ 1400042d8 =====

void _tlgDefineProvider_annotation__Tlgg_hL2BridgeProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 1400042e4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004440 =====

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



===== BLFlushBatchOpContextEx @ 1400044c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BLFlushBatchOpContextEx(longlong param_1,char param_2,char param_3)

{
  ulonglong *puVar1;
  bool bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  byte *pbVar9;
  uint uVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong *puVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  undefined8 *puVar20;
  uint local_res20;
  uint local_58;
  
  lVar11 = 0;
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x18) != 0) {
      BLFlushBatchOpContextEx(*(longlong *)(param_1 + 0x18),'\0',param_3);
    }
    puVar19 = (undefined8 *)(param_1 + 0x38);
    puVar20 = (undefined8 *)0x0;
    if ((*(int *)(param_1 + 0x14) != 0) ||
       ((*(longlong *)(param_1 + 0x30) != 0 && (param_2 == '\0')))) {
      lVar8 = *(longlong *)(param_1 + 0x50);
      if (*(char *)(lVar8 + 1) == '\x01') {
        lVar7 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) && (*(longlong *)(lVar8 + 0x18) != 0)) {
          lVar7 = *(longlong *)(lVar8 + 0x18) + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(int *)(lVar7 + 8) = *(int *)(lVar7 + 8) + 1;
        UNLOCK();
        lVar8 = *(longlong *)(param_1 + 0x50);
      }
      puVar13 = *(ulonglong **)(param_1 + 0x30);
      uVar17 = *(uint *)(param_1 + 0x2c);
      *(undefined8 *)(param_1 + 0x30) = 0;
      uVar12 = (*(char *)(param_1 + 0x28) != '\0') + 6;
      *(undefined4 *)(param_1 + 0x2c) = 0;
      bVar3 = (byte)*(undefined4 *)(param_1 + 8);
      if (((bVar3 & 5) == 5) || ((bVar3 & 6) == 6)) {
        bVar2 = true;
        (**(code **)(lVar8 + 0x20))();
      }
      else {
        bVar2 = false;
      }
      local_58 = 0;
      uVar16 = 0;
      local_res20 = 0;
      if (*(int *)(param_1 + 0x14) != 0) {
        puVar18 = puVar19;
        do {
          lVar8 = puVar18[2];
          uVar15 = (uint)uVar16;
          uVar5 = *(uint *)(lVar8 + 0x10 + uVar16 * 0x18);
          uVar10 = uVar5 & 0xf;
          if (uVar10 == 1) {
            memmove(*(void **)(lVar8 + uVar16 * 0x18),*(void **)(lVar8 + 8 + uVar16 * 0x18),
                    (ulonglong)(uVar5 >> 4));
          }
          else {
            uVar5 = uVar5 & 0xf;
            if (uVar5 == 2) {
              **(undefined2 **)(lVar8 + uVar16 * 0x18) = *(undefined2 *)(lVar8 + 8 + uVar16 * 0x18);
            }
            else if (uVar5 == 3) {
              **(undefined4 **)(lVar8 + uVar16 * 0x18) = *(undefined4 *)(lVar8 + 8 + uVar16 * 0x18);
            }
            else if ((uVar5 == 4) || (uVar10 == 5)) {
              uVar5 = *(uint *)(lVar8 + 8 + uVar16 * 0x18);
              uVar14 = uVar5 & 7;
              pbVar9 = (byte *)((ulonglong)(uVar5 >> 3) + *(longlong *)(lVar8 + uVar16 * 0x18));
              bVar3 = *pbVar9;
              if (uVar10 == 4) {
                bVar3 = bVar3 | (byte)(1 << uVar14);
              }
              else {
                bVar3 = bVar3 & ~(byte)(1 << uVar14);
              }
              *pbVar9 = bVar3;
            }
            else if (uVar10 - 6 < 2) {
              if ((puVar13 != (ulonglong *)0x0) &&
                 (*(ulonglong **)(lVar8 + uVar16 * 0x18) != puVar13)) {
                uVar4 = (ushort)*puVar13;
                if ((uVar17 & 1) != 0) {
                  uVar4 = uVar4 >> 8 | uVar4 << 8;
                }
                uVar4 = ~uVar4;
                if ((uVar12 == 7) && (uVar4 == 0)) {
                  uVar4 = 0xffff;
                }
                *(ushort *)puVar13 = uVar4;
                uVar17 = 0;
              }
              lVar8 = puVar18[2];
              uVar5 = *(uint *)(lVar8 + 0x10 + uVar16 * 0x18);
              puVar13 = *(ulonglong **)(lVar8 + uVar16 * 0x18);
              uVar12 = uVar5 & 0xf;
              puVar1 = *(ulonglong **)(lVar8 + 8 + uVar16 * 0x18);
              uVar5 = uVar5 >> 4;
              if ((puVar13 < puVar1) ||
                 (uVar4 = 0, (ulonglong *)((ulonglong)uVar5 + (longlong)puVar1) <= puVar13)) {
                uVar4 = (ushort)*puVar13;
              }
              iVar6 = tcpxsum(uVar4,puVar1,uVar5);
              uVar4 = (ushort)iVar6;
              *(ushort *)puVar13 = uVar4;
              uVar15 = local_res20;
              if ((uVar5 & 1) != 0) {
                *(ushort *)puVar13 = uVar4 >> 8 | uVar4 << 8;
                uVar17 = uVar17 + 1;
              }
            }
          }
          local_res20 = uVar15 + 1;
          uVar16 = (ulonglong)local_res20;
          puVar19 = puVar18;
          if (local_res20 == *(uint *)((longlong)puVar18 + 0xc)) {
            local_res20 = 0;
            puVar19 = (undefined8 *)*puVar18;
            uVar16 = 0;
            if (puVar18 != (undefined8 *)(param_1 + 0x38)) {
              *puVar18 = puVar20;
              puVar20 = puVar18;
            }
          }
          if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
            lVar8 = 0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar7 != 0)) {
              lVar8 = lVar7 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
            }
            LOCK();
            *(short *)(lVar8 + 0xe) = *(short *)(lVar8 + 0xe) + -1;
            UNLOCK();
          }
          local_58 = local_58 + 1;
          puVar18 = puVar19;
        } while (local_58 < *(uint *)(param_1 + 0x14));
      }
      if (puVar13 != (ulonglong *)0x0) {
        if (param_2 == '\0') {
          uVar4 = (ushort)*puVar13;
          if ((uVar17 & 1) != 0) {
            uVar4 = uVar4 >> 8 | uVar4 << 8;
          }
          uVar4 = ~uVar4;
          if ((uVar12 == 7) && (uVar4 == 0)) {
            uVar4 = 0xffff;
          }
          *(ushort *)puVar13 = uVar4;
        }
        else {
          *(ulonglong **)(param_1 + 0x30) = puVar13;
          *(uint *)(param_1 + 0x2c) = uVar17;
          *(bool *)(param_1 + 0x28) = uVar12 == 7;
        }
      }
      if (bVar2) {
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
      }
      if (puVar19 == (undefined8 *)0x0) goto joined_r0x000140004803;
      if (puVar19 == (undefined8 *)(param_1 + 0x38)) goto joined_r0x000140004803;
      *puVar19 = puVar20;
      do {
        puVar20 = (undefined8 *)*puVar19;
        ExFreeToNPagedLookasideList(*(longlong *)(param_1 + 0x50) + 0x40,puVar19);
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
        if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
          lVar8 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar7 != 0)) {
            lVar8 = lVar7 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(short *)(lVar8 + 0xc) = *(short *)(lVar8 + 0xc) + -1;
          UNLOCK();
        }
joined_r0x000140004803:
        puVar19 = puVar20;
      } while (puVar19 != (undefined8 *)0x0);
      *(longlong *)(param_1 + 0x20) = param_1 + 0x38;
      *(undefined8 *)(param_1 + 0x10) = 1;
      *(undefined8 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
  }
  if (((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') && (param_3 != '\0')) &&
     (*(char *)(param_1 + 4) != '\0')) {
    *(undefined1 *)(param_1 + 4) = 0;
    if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar8 != 0)) {
      lVar11 = lVar8 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
    }
    LOCK();
    *(short *)(lVar11 + 0x10) = *(short *)(lVar11 + 0x10) + -1;
    UNLOCK();
  }
  return;
}



===== BLUninitialize @ 1400048c8 =====

void BLUninitialize(void)

{
  if (DAT_14000d2d8 != 0) {
    ExFreePool();
    DAT_14000d2d8 = 0;
  }
  if (DAT_14000d2f0 != '\0') {
    ExDeleteNPagedLookasideList(&DAT_14000d300);
    DAT_14000d2f0 = '\0';
  }
  return;
}



===== Feature_TCPIP_2025_Wave2_SegLibHeap__private_IsEnabledDeviceUsageNoInline @ 14000491c =====

ulonglong Feature_TCPIP_2025_Wave2_SegLibHeap__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState;
  if ((Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState & 0x10) == 0) {
    uVar1 = Feature_TCPIP_2025_Wave2_SegLibHeap__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_TCPIP_2025_Wave2_SegLibHeap__private_IsEnabledFallback @ 140004954 =====

void Feature_TCPIP_2025_Wave2_SegLibHeap__private_IsEnabledFallback
               (undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== SegLibCreateMultiNbNblClone @ 14000496c =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SegLibCreateMultiNbNblClone(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  code *pcVar3;
  longlong lVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  int iVar8;
  longlong lVar9;
  ulonglong *puVar10;
  byte bVar11;
  int iVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  void *pvVar15;
  void *pvVar16;
  undefined8 uVar17;
  undefined8 *puVar18;
  longlong lVar19;
  int *piVar20;
  char cVar21;
  uint uVar22;
  undefined1 *puVar23;
  ulonglong _Size;
  ushort uVar24;
  uint uVar25;
  ulonglong *puVar26;
  undefined2 *puVar27;
  ulonglong _Size_00;
  longlong *plVar28;
  longlong lVar29;
  longlong *in_stack_00000050;
  uint *in_stack_00000058;
  undefined8 uStackY_180;
  undefined1 auStackY_178 [32];
  char acStack_12e [6];
  char local_128 [8];
  ulonglong *local_120;
  undefined2 local_118 [2];
  ushort local_114 [2];
  void *local_110;
  ulonglong local_108;
  uint local_100 [4];
  undefined8 local_f0;
  undefined4 local_e8;
  ushort local_e0;
  ushort local_de;
  void *local_d8;
  int local_d0;
  int local_cc;
  longlong local_c8;
  void *local_c0;
  ulonglong *local_b8;
  longlong *local_b0;
  uint *local_a8;
  undefined4 local_98;
  char local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  int iStack_84;
  undefined8 local_80;
  undefined8 *local_78;
  undefined1 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  uint local_54;
  char *local_50;
  longlong local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_128;
  local_b0 = in_stack_00000050;
  local_a8 = in_stack_00000058;
  uVar14 = 0;
  local_100[0] = 0;
  local_100[1] = 0;
  local_100[2] = 0;
  local_100[3] = 0;
  local_f0 = 0;
  local_e8 = 0;
  uStackY_180 = 0x1400049ea;
  local_c8 = param_2;
  memset(&local_98,0,0x60);
  puVar27 = local_118;
  local_128[4] = '\0';
  puVar26 = &local_108;
  local_108 = 0;
  local_118[0] = 0;
  local_114[0] = 0;
  local_128[6] = 0;
  local_128[5] = '\0';
  local_128[2] = 0;
  local_128[1] = '\0';
  uStackY_180 = 0x140004a4c;
  SegLibPvtProcessAdditionalOffloadInfo
            (param_2,uVar14,puVar26,puVar27,local_114,(byte *)(local_128 + 6),local_128 + 5,
             local_128 + 4,local_128 + 2);
  local_48 = DAT_14000d268;
  local_54 = 4;
  if ((DAT_14000d268 != 0) && (*(char *)(DAT_14000d268 + 0x30) != '\0')) {
    local_54 = *(uint *)(DAT_14000d268 + 0x10);
  }
  uVar13 = (ulonglong)local_54 * 0x18 + 0xf;
  if (uVar13 <= (ulonglong)local_54 * 0x18) {
    uVar13 = 0xffffffffffffff0;
  }
  uStackY_180 = 0x140004a8c;
  lVar4 = -(uVar13 & 0xfffffffffffffff0);
  local_98 = 0xf00df00d;
  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004aa7;
  local_8c = KeGetCurrentProcessorNumberEx();
  local_94 = '\0';
  local_80 = 0;
  local_88 = 1;
  iStack_84 = 0;
  local_68 = 0;
  local_6c = 0;
  local_70 = 0;
  local_90 = -(uint)(*(longlong *)(local_48 + 0x20) != 0) & 4;
  local_60 = 0;
  local_58 = 0;
  local_78 = &local_60;
  if (local_128 + lVar4 == (char *)0x0) {
    local_54 = 0;
    local_50 = (char *)0x0;
  }
  else {
    local_50 = local_128 + lVar4;
  }
  auStackY_178[lVar4 + 0x30] = local_128[2];
  lVar29 = 0;
  *(undefined2 *)(auStackY_178 + lVar4 + 0x28) = local_118[0];
  cVar21 = '\0';
  *(ulonglong *)(auStackY_178 + lVar4 + 0x20) = local_108;
  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004b62;
  uVar14 = SegLibPvtLsoInitialize
                     (local_100,param_2,puVar26,puVar27,*(ulonglong *)(auStackY_178 + lVar4 + 0x20),
                      *(undefined2 *)(auStackY_178 + lVar4 + 0x28),auStackY_178[lVar4 + 0x30]);
  uVar22 = local_e8;
  iVar12 = (int)uVar14;
  puVar23 = auStackY_178 + lVar4;
  if (-1 < iVar12) {
    uVar25 = local_100[0];
    pcVar1 = local_128 + lVar4 + -0x18;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    *(undefined4 *)(auStackY_178 + lVar4 + 0x30) = 0;
    *(uint *)(auStackY_178 + lVar4 + 0x28) = uVar22 & 0xffff;
    *(uint *)(auStackY_178 + lVar4 + 0x20) = uVar25;
    *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004b96;
    lVar29 = NdisAllocateFragmentNetBufferList(param_2);
    if (lVar29 == 0) {
      iVar12 = -0x3fffff66;
      puVar23 = auStackY_178 + lVar4;
    }
    else {
      *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004bbf;
      NdisAdvanceNetBufferListDataStart(lVar29,0,0,0);
      *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004bdb;
      iVar12 = NdisAllocateNetBufferListContext(lVar29);
      puVar23 = auStackY_178 + lVar4;
      if (-1 < iVar12) {
        plVar28 = *(longlong **)(lVar29 + 8);
        local_e0 = local_f0._6_2_ - local_e8._2_1_;
        local_c0 = (void *)0x0;
        local_b8 = (ulonglong *)0x0;
        local_d8 = (void *)0x0;
        local_128[3] = '\0';
        local_d0 = 0;
        local_cc = 0;
        local_de = (ushort)local_e8 - local_f0._6_2_;
        local_128[0] = '\x01';
        if (plVar28 == (longlong *)0x0) {
        }
        else {
          do {
            uVar24 = local_de;
            uVar5 = local_e0;
            uVar22 = local_e8;
            _Size_00 = (ulonglong)local_de;
            uVar13 = (ulonglong)(ushort)local_e8;
            *(undefined4 *)(auStackY_178 + lVar4 + 0x20) = 0;
            *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004c52;
            pvVar15 = (void *)NdisGetDataBuffer(plVar28,uVar13);
            bVar11 = local_e8._2_1_;
            if (pvVar15 == (void *)0x0) {
              local_128[1] = '\x01';
              *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004c7d;
              NdisAdvanceNetBufferDataStart(plVar28,bVar11);
              *(undefined4 *)(auStackY_178 + lVar4 + 0x20) = 0;
              *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004c9d;
              local_120 = (ulonglong *)NdisGetDataBuffer(plVar28,uVar5,0,1);
              if (local_120 != (ulonglong *)0x0) {
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004cc1;
                NdisAdvanceNetBufferDataStart(plVar28,uVar5,0,0);
                *(undefined4 *)(auStackY_178 + lVar4 + 0x20) = 0;
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004ce3;
                pvVar16 = (void *)NdisGetDataBuffer(plVar28,_Size_00);
                local_110 = pvVar16;
                if (pvVar16 != (void *)0x0) {
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004d0c;
                  NdisRetreatNetBufferDataStart();
                  goto LAB_140004d33;
                }
              }
              iVar12 = -0x3fffff66;
              *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140005669;
              NdisRetreatNetBufferDataStart(plVar28);
              goto LAB_1400057cb;
            }
            pvVar16 = (void *)((local_f0 >> 0x30) + (longlong)pvVar15);
            local_120 = (ulonglong *)((ulonglong)local_e8._2_1_ + (longlong)pvVar15);
            local_110 = pvVar16;
LAB_140004d33:
            lVar19 = local_c8;
            cVar21 = local_128[1];
            _Size = (ulonglong)uVar5;
            if (local_d8 == (void *)0x0) {
              if (local_128[1] == '\0') {
                *(void **)(auStackY_178 + lVar4 + 0x20) = pvVar15;
                uVar25 = *(uint *)(*(longlong *)(lVar19 + 8) + 0x10);
                puVar18 = *(undefined8 **)(*(longlong *)(lVar19 + 8) + 8);
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004e68;
                uVar14 = SegLibPvtDeferredCopyMdlChainData
                                   ((longlong)&local_98,puVar18,uVar25,uVar22 & 0xffff,
                                    *(void **)(auStackY_178 + lVar4 + 0x20));
                iVar12 = (int)uVar14;
              }
              else {
                uVar7 = local_e8._2_1_;
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004d60;
                NdisAdvanceNetBufferDataStart(plVar28,uVar7,0,0);
                lVar9 = local_c8;
                uVar14 = *(undefined8 *)(local_c8 + 8);
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004d7c;
                NdisAdvanceNetBufferDataStart(uVar14,uVar7,0,0);
                lVar19 = *(longlong *)(lVar9 + 8);
                *(ulonglong **)(auStackY_178 + lVar4 + 0x20) = local_120;
                uVar22 = *(uint *)(lVar19 + 0x10);
                puVar18 = *(undefined8 **)(lVar19 + 8);
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004da5;
                uVar17 = SegLibPvtDeferredCopyMdlChainData
                                   ((longlong)&local_98,puVar18,uVar22,(uint)uVar5,
                                    *(void **)(auStackY_178 + lVar4 + 0x20));
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004db9;
                NdisAdvanceNetBufferDataStart(plVar28,_Size,0,0);
                uVar14 = *(undefined8 *)(lVar9 + 8);
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004dd1;
                NdisAdvanceNetBufferDataStart(uVar14,_Size,0,0);
                lVar19 = *(longlong *)(lVar9 + 8);
                *(void **)(auStackY_178 + lVar4 + 0x20) = local_110;
                uVar22 = *(uint *)(lVar19 + 0x10);
                puVar18 = *(undefined8 **)(lVar19 + 8);
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004dfa;
                uVar14 = SegLibPvtDeferredCopyMdlChainData
                                   ((longlong)&local_98,puVar18,uVar22,(uint)uVar24,
                                    *(void **)(auStackY_178 + lVar4 + 0x20));
                uVar6 = local_f0._6_2_;
                iVar12 = (int)uVar14;
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004e12;
                NdisRetreatNetBufferDataStart(plVar28,uVar6,0,0);
                uVar14 = *(undefined8 *)(local_c8 + 8);
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004e2e;
                NdisRetreatNetBufferDataStart(uVar14,uVar6,0,0);
                if ((int)uVar17 < 0) goto LAB_1400057cb;
                cVar21 = local_128[1];
              }
              if (iVar12 < 0) goto LAB_1400057cb;
              *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004e86;
              BLFlushBatchOpContextEx((longlong)&local_98,'\0','\x01');
              pvVar16 = local_110;
              puVar26 = local_120;
              *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004e97;
              uVar14 = SegLibPvtParseHeaders((longlong)local_100,puVar26,(longlong)pvVar16);
              iVar12 = (int)uVar14;
              if (iVar12 < 0) goto LAB_1400057cb;
              local_c0 = pvVar15;
              local_b8 = local_120;
              local_d8 = local_110;
              local_128[3] = cVar21;
              puVar26 = local_120;
            }
            else if ((local_128[3] == '\0') && (local_128[1] == '\0')) {
              if ((*(char *)(local_48 + 1) == '\x01') && (local_94 == '\0')) {
                lVar19 = 0;
                local_94 = '\x01';
                if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                  lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                }
                LOCK();
                *(short *)(lVar19 + 0x10) = *(short *)(lVar19 + 0x10) + 1;
                UNLOCK();
              }
              if (*(uint *)(local_48 + 4) == 0) {
                if (iStack_84 != 0) {
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004f4d;
                  BLFlushBatchOpContextEx((longlong)&local_98,'\x01','\0');
                }
                pvVar16 = local_c0;
                if ((((byte)local_90 & 5) == 5) || (((byte)local_90 & 6) == 6)) {
                  pcVar3 = *(code **)(local_48 + 0x20);
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004f8c;
                  (*pcVar3)();
                  pvVar16 = local_c0;
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004f9b;
                  memmove(pvVar15,pvVar16,uVar13);
                  pcVar3 = *(code **)(local_48 + 0x28);
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004fab;
                  (*pcVar3)();
                }
                else {
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004f7a;
                  memmove(pvVar15,pvVar16,uVar13);
                }
              }
              else {
                uVar25 = *(uint *)(local_78 + 1);
                puVar18 = local_78;
                if (*(uint *)((longlong)local_78 + 0xc) <= uVar25) {
                  uVar25 = 0;
                  if (local_88 < *(uint *)(local_48 + 4)) {
                    lVar19 = local_48 + 0x40;
                    *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004fd6;
                    puVar18 = (undefined8 *)ExAllocateFromNPagedLookasideList(lVar19);
                    if (puVar18 != (undefined8 *)0x0) {
                      *puVar18 = 0;
                      *(undefined4 *)(puVar18 + 1) = 0;
                      uVar2 = *(undefined4 *)(local_48 + 8);
                      puVar18[2] = puVar18 + 3;
                      *(undefined4 *)((longlong)puVar18 + 0xc) = uVar2;
                      *local_78 = puVar18;
                      local_88 = local_88 + 1;
                      local_78 = puVar18;
                      if (*(char *)(local_48 + 1) == '\x01') {
                        lVar19 = 0;
                        if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                          lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                        }
                        LOCK();
                        *(short *)(lVar19 + 0xc) = *(short *)(lVar19 + 0xc) + 1;
                        UNLOCK();
                        piVar20 = (int *)0x0;
                        if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                          piVar20 = (int *)(*(longlong *)(local_48 + 0x18) +
                                           (ulonglong)local_8c * 0x14);
                        }
                        LOCK();
                        *piVar20 = *piVar20 + 1;
                        UNLOCK();
                      }
                      goto LAB_140005096;
                    }
                  }
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140004ff5;
                  BLFlushBatchOpContextEx((longlong)&local_98,'\x01','\0');
                  puVar18 = &local_60;
                }
LAB_140005096:
                iStack_84 = iStack_84 + 1;
                *(int *)(puVar18 + 1) = *(int *)(puVar18 + 1) + 1;
                if (*(char *)(local_48 + 1) == '\x01') {
                  lVar19 = 0;
                  if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                    lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                  }
                  LOCK();
                  *(short *)(lVar19 + 0xe) = *(short *)(lVar19 + 0xe) + 1;
                  UNLOCK();
                  lVar19 = 0;
                  if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                    lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                  }
                  LOCK();
                  *(int *)(lVar19 + 4) = *(int *)(lVar19 + 4) + 1;
                  UNLOCK();
                }
                uVar13 = (ulonglong)uVar25;
                lVar19 = puVar18[2];
                *(void **)(lVar19 + uVar13 * 0x18) = pvVar15;
                *(uint *)(lVar19 + 0x10 + uVar13 * 0x18) = (uVar22 & 0xffff) << 4 | 1;
                *(void **)(lVar19 + 8 + uVar13 * 0x18) = local_c0;
              }
              puVar26 = local_120;
            }
            else {
              if ((*(char *)(local_48 + 1) == '\x01') && (local_94 == '\0')) {
                lVar19 = 0;
                local_94 = '\x01';
                if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                  lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                }
                LOCK();
                *(short *)(lVar19 + 0x10) = *(short *)(lVar19 + 0x10) + 1;
                UNLOCK();
              }
              if (*(uint *)(local_48 + 4) == 0) {
                if (iStack_84 != 0) {
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x1400051a4;
                  BLFlushBatchOpContextEx((longlong)&local_98,'\x01','\0');
                }
                puVar10 = local_b8;
                puVar26 = local_120;
                if ((((byte)local_90 & 5) == 5) || (((byte)local_90 & 6) == 6)) {
                  pcVar3 = *(code **)(local_48 + 0x20);
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x1400051ea;
                  (*pcVar3)();
                  puVar10 = local_b8;
                  puVar26 = local_120;
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x1400051fa;
                  memmove(puVar26,puVar10,_Size);
                  pcVar3 = *(code **)(local_48 + 0x28);
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x14000520a;
                  (*pcVar3)();
                }
                else {
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x1400051d2;
                  memmove(puVar26,puVar10,_Size);
                }
              }
              else {
                uVar22 = *(uint *)(local_78 + 1);
                puVar18 = local_78;
                if (*(uint *)((longlong)local_78 + 0xc) <= uVar22) {
                  uVar22 = 0;
                  if (local_88 < *(uint *)(local_48 + 4)) {
                    lVar19 = local_48 + 0x40;
                    *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x14000523a;
                    puVar18 = (undefined8 *)ExAllocateFromNPagedLookasideList(lVar19);
                    if (puVar18 != (undefined8 *)0x0) {
                      *puVar18 = 0;
                      *(undefined4 *)(puVar18 + 1) = 0;
                      uVar2 = *(undefined4 *)(local_48 + 8);
                      puVar18[2] = puVar18 + 3;
                      *(undefined4 *)((longlong)puVar18 + 0xc) = uVar2;
                      *local_78 = puVar18;
                      local_88 = local_88 + 1;
                      local_78 = puVar18;
                      if (*(char *)(local_48 + 1) == '\x01') {
                        lVar19 = 0;
                        if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                          lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                        }
                        LOCK();
                        *(short *)(lVar19 + 0xc) = *(short *)(lVar19 + 0xc) + 1;
                        UNLOCK();
                        piVar20 = (int *)0x0;
                        if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                          piVar20 = (int *)(*(longlong *)(local_48 + 0x18) +
                                           (ulonglong)local_8c * 0x14);
                        }
                        LOCK();
                        *piVar20 = *piVar20 + 1;
                        UNLOCK();
                      }
                      goto LAB_14000530d;
                    }
                  }
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x14000525c;
                  BLFlushBatchOpContextEx((longlong)&local_98,'\x01','\0');
                  puVar18 = &local_60;
                }
LAB_14000530d:
                iStack_84 = iStack_84 + 1;
                *(int *)(puVar18 + 1) = *(int *)(puVar18 + 1) + 1;
                if (*(char *)(local_48 + 1) == '\x01') {
                  lVar19 = 0;
                  if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                    lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                  }
                  LOCK();
                  *(short *)(lVar19 + 0xe) = *(short *)(lVar19 + 0xe) + 1;
                  UNLOCK();
                  lVar19 = 0;
                  if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                    lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                  }
                  LOCK();
                  *(int *)(lVar19 + 4) = *(int *)(lVar19 + 4) + 1;
                  UNLOCK();
                }
                uVar13 = (ulonglong)uVar22;
                lVar19 = puVar18[2];
                *(ulonglong **)(lVar19 + uVar13 * 0x18) = local_120;
                *(uint *)(lVar19 + 0x10 + uVar13 * 0x18) = (uint)uVar5 << 4 | 1;
                *(ulonglong **)(lVar19 + 8 + uVar13 * 0x18) = local_b8;
              }
              puVar26 = local_120;
              if ((*(char *)(local_48 + 1) == '\x01') && (local_94 == '\0')) {
                lVar19 = 0;
                local_94 = '\x01';
                if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                  lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                }
                LOCK();
                *(short *)(lVar19 + 0x10) = *(short *)(lVar19 + 0x10) + 1;
                UNLOCK();
              }
              if (*(uint *)(local_48 + 4) == 0) {
                if (iStack_84 != 0) {
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140005414;
                  BLFlushBatchOpContextEx((longlong)&local_98,'\x01','\0');
                }
                pvVar15 = local_d8;
                if ((((byte)local_90 & 5) == 5) || (((byte)local_90 & 6) == 6)) {
                  pcVar3 = *(code **)(local_48 + 0x20);
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x14000544f;
                  (*pcVar3)();
                  pvVar15 = local_d8;
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x14000545e;
                  memmove(pvVar16,pvVar15,_Size_00);
                  pcVar3 = *(code **)(local_48 + 0x28);
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x14000546e;
                  (*pcVar3)();
                }
                else {
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140005441;
                  memmove(pvVar16,pvVar15,_Size_00);
                }
              }
              else {
                uVar22 = *(uint *)(local_78 + 1);
                puVar18 = local_78;
                if (*(uint *)((longlong)local_78 + 0xc) <= uVar22) {
                  uVar22 = 0;
                  if (local_88 < *(uint *)(local_48 + 4)) {
                    lVar19 = local_48 + 0x40;
                    *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x1400054a0;
                    puVar18 = (undefined8 *)ExAllocateFromNPagedLookasideList(lVar19);
                    if (puVar18 != (undefined8 *)0x0) {
                      *puVar18 = 0;
                      *(undefined4 *)(puVar18 + 1) = 0;
                      uVar2 = *(undefined4 *)(local_48 + 8);
                      puVar18[2] = puVar18 + 3;
                      *(undefined4 *)((longlong)puVar18 + 0xc) = uVar2;
                      *local_78 = puVar18;
                      local_88 = local_88 + 1;
                      local_78 = puVar18;
                      if (*(char *)(local_48 + 1) == '\x01') {
                        lVar19 = 0;
                        if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                          lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                        }
                        LOCK();
                        *(short *)(lVar19 + 0xc) = *(short *)(lVar19 + 0xc) + 1;
                        UNLOCK();
                        piVar20 = (int *)0x0;
                        if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                          piVar20 = (int *)(*(longlong *)(local_48 + 0x18) +
                                           (ulonglong)local_8c * 0x14);
                        }
                        LOCK();
                        *piVar20 = *piVar20 + 1;
                        UNLOCK();
                      }
                      goto LAB_14000556e;
                    }
                  }
                  *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x1400054bf;
                  BLFlushBatchOpContextEx((longlong)&local_98,'\x01','\0');
                  puVar18 = &local_60;
                }
LAB_14000556e:
                iStack_84 = iStack_84 + 1;
                *(int *)(puVar18 + 1) = *(int *)(puVar18 + 1) + 1;
                if (*(char *)(local_48 + 1) == '\x01') {
                  lVar19 = 0;
                  if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                    lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                  }
                  LOCK();
                  *(short *)(lVar19 + 0xe) = *(short *)(lVar19 + 0xe) + 1;
                  UNLOCK();
                  lVar19 = 0;
                  if ((local_8c != 0xffffffff) && (*(longlong *)(local_48 + 0x18) != 0)) {
                    lVar19 = *(longlong *)(local_48 + 0x18) + (ulonglong)local_8c * 0x14;
                  }
                  LOCK();
                  *(int *)(lVar19 + 4) = *(int *)(lVar19 + 4) + 1;
                  UNLOCK();
                }
                uVar13 = (ulonglong)uVar22;
                lVar19 = puVar18[2];
                *(void **)(lVar19 + uVar13 * 0x18) = pvVar16;
                *(uint *)(lVar19 + 0x10 + uVar13 * 0x18) = (uint)uVar24 << 4 | 1;
                *(void **)(lVar19 + 8 + uVar13 * 0x18) = local_d8;
              }
            }
            iVar8 = local_cc;
            iVar12 = local_d0;
            pvVar15 = local_110;
            *(int *)(auStackY_178 + lVar4 + 0x28) = local_cc;
            *(int *)(auStackY_178 + lVar4 + 0x20) = iVar12;
            *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140005634;
            SegLibPvtLsoDeferredFixHeaders
                      ((longlong)&local_98,(short *)local_100,(longlong)puVar26,(longlong)pvVar15,
                       *(int *)(auStackY_178 + lVar4 + 0x20),*(int *)(auStackY_178 + lVar4 + 0x28));
            local_cc = iVar8 + local_100[0];
            local_d0 = iVar12 + 1;
            plVar28 = (longlong *)*plVar28;
          } while (plVar28 != (longlong *)0x0);
          param_2 = local_c8;
        }
        cVar21 = local_128[4];
        if (local_128[4] == '\0') {
          *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x1400056a0;
          NdisCopySendNetBufferListInfo(lVar29);
          *(undefined8 *)(lVar29 + 0xa0) = 0;
        }
        else {
          *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140005692;
          NdisCopyReceiveNetBufferListInfo();
        }
        uVar5 = local_114[0];
        if (local_128[5] == '\0') {
          if (cVar21 == '\0') {
            local_108 = (ulonglong)
                        (((local_f0._6_2_ & 0x3ff) << 0xf | local_e8._3_1_ & 1) * 2 |
                         (byte)~local_e8._3_1_ & 1 | 4);
            *(ulonglong *)(lVar29 + 0x90) = local_108;
          }
        }
        else {
          plVar28 = *(longlong **)(lVar29 + 8);
          if (plVar28 != (longlong *)0x0) {
            uVar22 = ((local_f0._6_2_ & 0x3ff) << 0xf | local_e8._3_1_ & 1) * 2;
            bVar11 = ~local_e8._3_1_;
            do {
              local_108 = (ulonglong)(uVar22 | bVar11 & 1 | 4);
              if (local_108 != 0) {
                uVar24 = uVar5;
                if (uVar5 == 0) {
                  uVar24 = (ushort)(uVar22 >> 0x10);
                }
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x140005726;
                lVar19 = SegLibPvtGetDataBufferWithOffset(plVar28,(ulonglong)uVar24,0x14);
                if (lVar19 == 0) {
                  iVar12 = -0x3fffffdd;
                  goto LAB_1400057cb;
                }
                *(longlong *)(auStackY_178 + lVar4 + 0x20) = lVar19 + 0x10;
                *(undefined8 *)(auStackY_178 + lVar4 + -8) = 0x14000574a;
                iVar12 = SegLibPvtDeferredChecksumTransport
                                   ((longlong)&local_98,(longlong)plVar28,uVar24,'\0',
                                    *(ulonglong **)(auStackY_178 + lVar4 + 0x20));
                if (iVar12 < 0) goto LAB_1400057cb;
              }
              plVar28 = (longlong *)*plVar28;
            } while (plVar28 != (longlong *)0x0);
          }
          *(undefined8 *)(lVar29 + 0x90) = 0;
          param_2 = local_c8;
        }
        iVar12 = 0;
        *(longlong *)(lVar29 + 0x18) = param_2;
        *local_b0 = lVar29;
        *local_a8 = local_e8 & 0xffff;
LAB_1400057cb:
        puVar23 = auStackY_178 + lVar4;
        cVar21 = local_128[0];
      }
    }
  }
  *(undefined8 *)(puVar23 + -8) = 0x1400057e0;
  BLFlushBatchOpContextEx((longlong)&local_98,'\0','\x01');
  if ((iVar12 < 0) && (lVar29 != 0)) {
    if (cVar21 != '\0') {
      *(undefined8 *)(puVar23 + -8) = 0x1400057fc;
      NdisFreeNetBufferListContext(lVar29,0x28);
    }
    uVar6 = (ushort)local_e8;
    *(undefined8 *)(puVar23 + -8) = 0x140005812;
    NdisFreeFragmentNetBufferList(lVar29,uVar6,0);
  }
  *(undefined8 *)(puVar23 + -8) = 0x140005828;
  return iVar12;
}



===== SegLibGetModuleBase @ 140005858 =====

undefined8 SegLibGetModuleBase(ulonglong param_1)

{
  int iVar1;
  uint *puVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  ulonglong local_res8;
  
  uVar3 = 0;
  uVar5 = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  puVar2 = (uint *)0x0;
  do {
    iVar1 = ZwQuerySystemInformation(0xb,puVar2,uVar5,&local_res8);
    if (-1 < iVar1) break;
    if (puVar2 != (uint *)0x0) {
      ExFreePoolWithTag(puVar2,0);
    }
    if (iVar1 != -0x3ffffffc) {
      return 0;
    }
    uVar5 = (undefined4)local_res8;
    puVar2 = (uint *)ExAllocatePool2(0x40,local_res8 & 0xffffffff,0x6f6d734c);
  } while (puVar2 != (uint *)0x0);
  if (puVar2 != (uint *)0x0) {
    puVar6 = puVar2 + 2;
    uVar4 = 0;
    if (*puVar2 != 0) {
      do {
        iVar1 = _strnicmp((char *)(puVar6 + 10),"\\SystemRoot\\system32\\DRIVERS\\NETIO.SYS",0x100);
        if (iVar1 == 0) {
          uVar3 = *(undefined8 *)(puVar6 + 4);
          break;
        }
        uVar4 = uVar4 + 1;
        puVar6 = puVar6 + 0x4a;
      } while (uVar4 < *puVar2);
    }
    ExFreePoolWithTag(puVar2,0);
  }
  return uVar3;
}



===== SegLibPvtDeferredChecksumMdlChain @ 140005954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SegLibPvtDeferredChecksumMdlChain
          (longlong param_1,char param_2,longlong *param_3,uint param_4,uint param_5,
          undefined8 param_6,ulonglong *param_7)

{
  undefined4 uVar1;
  ulonglong *puVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  ushort uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  void *_Dst;
  uint uVar15;
  undefined8 uVar16;
  ulonglong *puVar17;
  void *local_38;
  
  uVar16 = 0;
  if (param_5 != 0) {
    if (param_3 == (longlong *)0x0) {
      uVar16 = 0xc000000d;
    }
    else {
      if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
        lVar6 = MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000000);
      }
      else {
        lVar6 = param_3[3];
      }
      if ((lVar6 != 0) && (param_4 < *(uint *)(param_3 + 5))) {
        uVar12 = *(uint *)(param_3 + 5) - param_4;
        param_6._0_4_ = param_5;
        puVar17 = (ulonglong *)(lVar6 + (ulonglong)param_4);
        local_38 = (void *)0x0;
        _Dst = (void *)0x0;
        do {
          uVar14 = (uint)param_6;
          if (uVar12 <= (uint)param_6) {
            uVar14 = uVar12;
          }
          uVar8 = (ulonglong)uVar14;
          if (_Dst == (void *)0x0) {
            lVar6 = *(longlong *)(param_1 + 0x50);
            if ((*(char *)(lVar6 + 1) == '\x01') && (*(char *)(param_1 + 4) == '\0')) {
              lVar9 = 0;
              *(undefined1 *)(param_1 + 4) = 1;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 != 0)) {
                lVar9 = lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar9 + 0x10) = *(short *)(lVar9 + 0x10) + 1;
              UNLOCK();
            }
            lVar6 = *(longlong *)(param_1 + 0x50);
            uVar12 = *(uint *)(lVar6 + 4);
            if (uVar12 == 0) {
              if (*(int *)(param_1 + 0x14) != 0) {
                BLFlushBatchOpContextEx(param_1,'\x01','\0');
              }
              bVar3 = (byte)*(undefined4 *)(param_1 + 8);
              if (((bVar3 & 5) == 5) || (bVar4 = false, (bVar3 & 6) == 6)) {
                bVar4 = true;
              }
              puVar2 = *(ulonglong **)(param_1 + 0x30);
              if ((puVar2 != (ulonglong *)0x0) && (puVar2 != param_7)) {
                if (bVar4) {
                  (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
                  uVar11 = **(ushort **)(param_1 + 0x30);
                  if ((*(uint *)(param_1 + 0x2c) & 1) != 0) {
                    uVar11 = uVar11 >> 8 | uVar11 << 8;
                  }
                  uVar11 = ~uVar11;
                  if ((*(char *)(param_1 + 0x28) != '\0') && (uVar11 == 0)) {
                    uVar11 = 0xffff;
                  }
                  **(ushort **)(param_1 + 0x30) = uVar11;
                  *(undefined8 *)(param_1 + 0x30) = 0;
                  *(undefined4 *)(param_1 + 0x2c) = 0;
                  (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
                }
                else {
                  uVar11 = (ushort)*puVar2;
                  if ((*(uint *)(param_1 + 0x2c) & 1) != 0) {
                    uVar11 = uVar11 >> 8 | uVar11 << 8;
                  }
                  uVar11 = ~uVar11;
                  if ((*(char *)(param_1 + 0x28) != '\0') && (uVar11 == 0)) {
                    uVar11 = 0xffff;
                  }
                  *(ushort *)puVar2 = uVar11;
                  *(undefined4 *)(param_1 + 0x2c) = 0;
                }
              }
              *(ulonglong **)(param_1 + 0x30) = param_7;
              *(bool *)(param_1 + 0x28) = param_2 != '\0';
              if (bVar4) {
                (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
                if ((param_7 < puVar17) ||
                   (uVar11 = 0, (ulonglong *)(uVar8 + (longlong)puVar17) <= param_7)) {
                  uVar11 = (ushort)*param_7;
                }
                iVar5 = tcpxsum(uVar11,puVar17,uVar14);
                uVar11 = (ushort)iVar5;
                *(ushort *)param_7 = uVar11;
                if ((uVar14 & 1) != 0) {
                  *(ushort *)param_7 = uVar11 >> 8 | uVar11 << 8;
                  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
                }
                (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
              }
              else {
                if ((param_7 < puVar17) ||
                   (uVar11 = 0, (ulonglong *)(uVar8 + (longlong)puVar17) <= param_7)) {
                  uVar11 = (ushort)*param_7;
                }
                iVar5 = tcpxsum(uVar11,puVar17,uVar14);
                uVar11 = (ushort)iVar5;
                *(ushort *)param_7 = uVar11;
                if ((uVar14 & 1) != 0) {
                  *(ushort *)param_7 = uVar11 >> 8 | uVar11 << 8;
                  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
                }
              }
            }
            else {
              puVar10 = *(undefined8 **)(param_1 + 0x20);
              uVar15 = *(uint *)(puVar10 + 1);
              if (*(uint *)((longlong)puVar10 + 0xc) <= uVar15) {
                uVar15 = 0;
                if ((*(uint *)(param_1 + 0x10) < uVar12) &&
                   (puVar10 = (undefined8 *)ExAllocateFromNPagedLookasideList(lVar6 + 0x40),
                   puVar10 != (undefined8 *)0x0)) {
                  *puVar10 = 0;
                  *(undefined4 *)(puVar10 + 1) = 0;
                  uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x50) + 8);
                  puVar10[2] = puVar10 + 3;
                  *(undefined4 *)((longlong)puVar10 + 0xc) = uVar1;
                  **(undefined8 **)(param_1 + 0x20) = puVar10;
                  lVar6 = *(longlong *)(param_1 + 0x50);
                  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
                  *(undefined8 **)(param_1 + 0x20) = puVar10;
                  if (*(char *)(lVar6 + 1) == '\x01') {
                    lVar9 = 0;
                    if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                       (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 != 0)) {
                      lVar9 = lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                    }
                    LOCK();
                    *(short *)(lVar9 + 0xc) = *(short *)(lVar9 + 0xc) + 1;
                    UNLOCK();
                    piVar13 = (int *)0x0;
                    if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar6 != 0)) {
                      piVar13 = (int *)(lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
                    }
                    LOCK();
                    *piVar13 = *piVar13 + 1;
                    UNLOCK();
                  }
                }
                else {
                  BLFlushBatchOpContextEx(param_1,'\x01','\0');
                  puVar10 = (undefined8 *)(param_1 + 0x38);
                }
              }
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(int *)(puVar10 + 1) = *(int *)(puVar10 + 1) + 1;
              lVar6 = *(longlong *)(param_1 + 0x50);
              if (*(char *)(lVar6 + 1) == '\x01') {
                lVar9 = 0;
                if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                   (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 != 0)) {
                  lVar9 = lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                }
                LOCK();
                *(short *)(lVar9 + 0xe) = *(short *)(lVar9 + 0xe) + 1;
                UNLOCK();
                lVar6 = 0;
                if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                   (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar9 != 0)) {
                  lVar6 = lVar9 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                }
                LOCK();
                *(int *)(lVar6 + 4) = *(int *)(lVar6 + 4) + 1;
                UNLOCK();
              }
              lVar9 = puVar10[2];
              uVar8 = (ulonglong)uVar15;
              lVar6 = lVar9 + uVar8 * 0x18;
              if (param_2 == '\0') {
                uVar12 = *(uint *)(lVar6 + 0x10) & 0xfffffff6 | 6;
              }
              else {
                uVar12 = *(uint *)(lVar6 + 0x10) & 0xfffffff7 | 7;
              }
              *(uint *)(lVar6 + 0x10) = uVar12;
              *(ulonglong **)(lVar9 + 8 + uVar8 * 0x18) = puVar17;
              *(ulonglong **)(lVar9 + uVar8 * 0x18) = param_7;
              *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) & 0xf | uVar14 << 4;
              _Dst = local_38;
            }
          }
          else {
            if (param_1 == 0) {
LAB_140005c24:
              memmove(_Dst,puVar17,uVar8);
            }
            else {
              if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
                 (*(char *)(param_1 + 4) == '\0')) {
                lVar6 = 0;
                *(undefined1 *)(param_1 + 4) = 1;
                if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                   (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar9 != 0)) {
                  lVar6 = lVar9 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                }
                LOCK();
                *(short *)(lVar6 + 0x10) = *(short *)(lVar6 + 0x10) + 1;
                UNLOCK();
              }
              uVar12 = *(uint *)(*(longlong *)(param_1 + 0x50) + 4);
              if (uVar12 == 0) {
                if (*(int *)(param_1 + 0x14) != 0) {
                  BLFlushBatchOpContextEx(param_1,'\x01','\0');
                }
                if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
                   ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6))))
                goto LAB_140005c24;
                (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
                memmove(_Dst,puVar17,uVar8);
                (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
              }
              else {
                puVar10 = *(undefined8 **)(param_1 + 0x20);
                uVar15 = *(uint *)(puVar10 + 1);
                if (*(uint *)((longlong)puVar10 + 0xc) <= uVar15) {
                  uVar15 = 0;
                  if ((*(uint *)(param_1 + 0x10) < uVar12) &&
                     (puVar10 = (undefined8 *)
                                ExAllocateFromNPagedLookasideList
                                          (*(longlong *)(param_1 + 0x50) + 0x40),
                     puVar10 != (undefined8 *)0x0)) {
                    *puVar10 = 0;
                    *(undefined4 *)(puVar10 + 1) = 0;
                    uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x50) + 8);
                    puVar10[2] = puVar10 + 3;
                    *(undefined4 *)((longlong)puVar10 + 0xc) = uVar1;
                    **(undefined8 **)(param_1 + 0x20) = puVar10;
                    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
                    *(undefined8 **)(param_1 + 0x20) = puVar10;
                    if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
                      lVar6 = 0;
                      if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                         (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar9 != 0))
                      {
                        lVar6 = lVar9 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                      }
                      LOCK();
                      *(short *)(lVar6 + 0xc) = *(short *)(lVar6 + 0xc) + 1;
                      UNLOCK();
                      piVar13 = (int *)0x0;
                      if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                         (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar6 != 0))
                      {
                        piVar13 = (int *)(lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
                      }
                      LOCK();
                      *piVar13 = *piVar13 + 1;
                      UNLOCK();
                    }
                  }
                  else {
                    BLFlushBatchOpContextEx(param_1,'\x01','\0');
                    puVar10 = (undefined8 *)(param_1 + 0x38);
                  }
                }
                *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                *(int *)(puVar10 + 1) = *(int *)(puVar10 + 1) + 1;
                if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
                  lVar6 = 0;
                  if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                     (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar9 != 0)) {
                    lVar6 = lVar9 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                  }
                  LOCK();
                  *(short *)(lVar6 + 0xe) = *(short *)(lVar6 + 0xe) + 1;
                  UNLOCK();
                  lVar6 = 0;
                  if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                     (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar9 != 0)) {
                    lVar6 = lVar9 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                  }
                  LOCK();
                  *(int *)(lVar6 + 4) = *(int *)(lVar6 + 4) + 1;
                  UNLOCK();
                }
                lVar6 = puVar10[2];
                uVar7 = (ulonglong)uVar15;
                *(void **)(lVar6 + uVar7 * 0x18) = _Dst;
                *(ulonglong **)(lVar6 + 8 + uVar7 * 0x18) = puVar17;
                *(uint *)(lVar6 + 0x10 + uVar7 * 0x18) = uVar14 << 4 | 1;
              }
            }
            local_38 = (void *)((longlong)_Dst + uVar8);
            _Dst = local_38;
          }
          param_6._0_4_ = (uint)param_6 - uVar14;
          if ((uint)param_6 == 0) {
            if (_Dst == (void *)0x0) {
              return 0;
            }
            lVar6 = *(longlong *)(param_1 + 0x50);
            if ((*(char *)(lVar6 + 1) == '\x01') && (*(char *)(param_1 + 4) == '\0')) {
              lVar9 = 0;
              *(undefined1 *)(param_1 + 4) = 1;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 != 0)) {
                lVar9 = lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar9 + 0x10) = *(short *)(lVar9 + 0x10) + 1;
              UNLOCK();
            }
            lVar6 = *(longlong *)(param_1 + 0x50);
            uVar12 = *(uint *)(lVar6 + 4);
            if (uVar12 != 0) {
              puVar10 = *(undefined8 **)(param_1 + 0x20);
              uVar14 = *(uint *)(puVar10 + 1);
              if (*(uint *)((longlong)puVar10 + 0xc) <= uVar14) {
                uVar14 = 0;
                if ((*(uint *)(param_1 + 0x10) < uVar12) &&
                   (puVar10 = (undefined8 *)ExAllocateFromNPagedLookasideList(lVar6 + 0x40),
                   puVar10 != (undefined8 *)0x0)) {
                  *puVar10 = 0;
                  *(undefined4 *)(puVar10 + 1) = 0;
                  uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x50) + 8);
                  puVar10[2] = puVar10 + 3;
                  *(undefined4 *)((longlong)puVar10 + 0xc) = uVar1;
                  **(undefined8 **)(param_1 + 0x20) = puVar10;
                  lVar6 = *(longlong *)(param_1 + 0x50);
                  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
                  *(undefined8 **)(param_1 + 0x20) = puVar10;
                  if (*(char *)(lVar6 + 1) == '\x01') {
                    lVar9 = 0;
                    if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                       (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 != 0)) {
                      lVar9 = lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                    }
                    LOCK();
                    *(short *)(lVar9 + 0xc) = *(short *)(lVar9 + 0xc) + 1;
                    UNLOCK();
                    piVar13 = (int *)0x0;
                    if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar6 != 0)) {
                      piVar13 = (int *)(lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
                    }
                    LOCK();
                    *piVar13 = *piVar13 + 1;
                    UNLOCK();
                  }
                }
                else {
                  BLFlushBatchOpContextEx(param_1,'\x01','\0');
                  puVar10 = (undefined8 *)(param_1 + 0x38);
                }
              }
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(int *)(puVar10 + 1) = *(int *)(puVar10 + 1) + 1;
              lVar6 = *(longlong *)(param_1 + 0x50);
              if (*(char *)(lVar6 + 1) == '\x01') {
                lVar9 = 0;
                if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                   (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 != 0)) {
                  lVar9 = lVar6 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                }
                LOCK();
                *(short *)(lVar9 + 0xe) = *(short *)(lVar9 + 0xe) + 1;
                UNLOCK();
                lVar6 = 0;
                if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                   (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar9 != 0)) {
                  lVar6 = lVar9 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                }
                LOCK();
                *(int *)(lVar6 + 4) = *(int *)(lVar6 + 4) + 1;
                UNLOCK();
              }
              lVar9 = puVar10[2];
              uVar8 = (ulonglong)uVar14;
              lVar6 = lVar9 + uVar8 * 0x18;
              if (param_2 == '\0') {
                uVar12 = *(uint *)(lVar6 + 0x10) & 0xfffffff6 | 6;
              }
              else {
                uVar12 = *(uint *)(lVar6 + 0x10) & 0xfffffff7 | 7;
              }
              *(uint *)(lVar6 + 0x10) = uVar12;
              uVar12 = *(uint *)(lVar6 + 0x10);
              *(undefined8 *)(lVar9 + 8 + uVar8 * 0x18) = 0;
              *(uint *)(lVar6 + 0x10) = uVar12 & 0xf | param_5 << 4;
              *(ulonglong **)(lVar9 + uVar8 * 0x18) = param_7;
              return 0;
            }
            if (*(int *)(param_1 + 0x14) != 0) {
              BLFlushBatchOpContextEx(param_1,'\x01','\0');
            }
            bVar3 = (byte)*(undefined4 *)(param_1 + 8);
            if (((bVar3 & 5) == 5) || (bVar4 = false, (bVar3 & 6) == 6)) {
              bVar4 = true;
            }
            puVar17 = *(ulonglong **)(param_1 + 0x30);
            if ((puVar17 != (ulonglong *)0x0) && (puVar17 != param_7)) {
              if (bVar4) {
                (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
                uVar11 = **(ushort **)(param_1 + 0x30);
                if ((*(uint *)(param_1 + 0x2c) & 1) != 0) {
                  uVar11 = uVar11 >> 8 | uVar11 << 8;
                }
                uVar11 = ~uVar11;
                if ((*(char *)(param_1 + 0x28) != '\0') && (uVar11 == 0)) {
                  uVar11 = 0xffff;
                }
                **(ushort **)(param_1 + 0x30) = uVar11;
                *(undefined8 *)(param_1 + 0x30) = 0;
                *(undefined4 *)(param_1 + 0x2c) = 0;
                (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
              }
              else {
                uVar11 = (ushort)*puVar17;
                if ((*(uint *)(param_1 + 0x2c) & 1) != 0) {
                  uVar11 = uVar11 >> 8 | uVar11 << 8;
                }
                uVar11 = ~uVar11;
                if ((*(char *)(param_1 + 0x28) != '\0') && (uVar11 == 0)) {
                  uVar11 = 0xffff;
                }
                *(ushort *)puVar17 = uVar11;
                *(undefined4 *)(param_1 + 0x2c) = 0;
              }
            }
            *(ulonglong **)(param_1 + 0x30) = param_7;
            *(bool *)(param_1 + 0x28) = param_2 != '\0';
            if (bVar4) {
              (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
              uVar11 = 0;
              if ((ulonglong *)(ulonglong)param_5 <= param_7) {
                uVar11 = (ushort)*param_7;
              }
              iVar5 = tcpxsum(uVar11,(ulonglong *)0x0,param_5);
              uVar11 = (ushort)iVar5;
              *(ushort *)param_7 = uVar11;
              if ((param_5 & 1) != 0) {
                *(ushort *)param_7 = uVar11 >> 8 | uVar11 << 8;
                *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
              }
              (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
              return 0;
            }
            uVar11 = 0;
            if ((ulonglong *)(ulonglong)param_5 <= param_7) {
              uVar11 = (ushort)*param_7;
            }
            iVar5 = tcpxsum(uVar11,(ulonglong *)0x0,param_5);
            uVar11 = (ushort)iVar5;
            *(ushort *)param_7 = uVar11;
            if ((param_5 & 1) == 0) {
              return 0;
            }
            *(ushort *)param_7 = uVar11 >> 8 | uVar11 << 8;
            *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
            return 0;
          }
          param_3 = (longlong *)*param_3;
          if (param_3 == (longlong *)0x0) break;
          if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
            puVar17 = (ulonglong *)MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000000);
          }
          else {
            puVar17 = (ulonglong *)param_3[3];
          }
          uVar12 = *(uint *)(param_3 + 5);
        } while (puVar17 != (ulonglong *)0x0);
      }
      uVar16 = 0xc000009a;
    }
    BLFlushBatchOpContextEx(param_1,'\0','\x01');
  }
  return uVar16;
}



===== SegLibPvtDeferredChecksumTransport @ 140006360 =====

void SegLibPvtDeferredChecksumTransport
               (longlong param_1,longlong param_2,ushort param_3,char param_4,ulonglong *param_5)

{
  longlong *plVar1;
  uint uVar2;
  undefined8 in_stack_ffffffffffffffe0;
  
  uVar2 = *(int *)(param_2 + 0x10) + (uint)param_3;
  for (plVar1 = *(longlong **)(param_2 + 8);
      (plVar1 != (longlong *)0x0 && (*(uint *)(plVar1 + 5) <= uVar2)); plVar1 = (longlong *)*plVar1)
  {
    uVar2 = uVar2 - *(uint *)(plVar1 + 5);
  }
  SegLibPvtDeferredChecksumMdlChain
            (param_1,param_4,plVar1,uVar2,*(int *)(param_2 + 0x18) - (uint)param_3,
             in_stack_ffffffffffffffe0,param_5);
  return;
}



===== SegLibPvtDeferredCopyMdlChainData @ 1400063c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SegLibPvtDeferredCopyMdlChainData
          (longlong param_1,undefined8 *param_2,uint param_3,uint param_4,void *param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint uVar6;
  int *piVar7;
  undefined8 uVar8;
  uint uVar9;
  void *_Src;
  uint uVar10;
  
  uVar8 = 0;
  if (param_4 != 0) {
    for (; (param_2 != (undefined8 *)0x0 && (*(uint *)(param_2 + 5) <= param_3));
        param_2 = (undefined8 *)*param_2) {
      param_3 = param_3 - *(uint *)(param_2 + 5);
    }
    if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
      lVar3 = MmMapLockedPagesSpecifyCache(param_2,0,1,0,0,0x40000000);
    }
    else {
      lVar3 = param_2[3];
    }
    if (lVar3 != 0) {
      uVar6 = *(int *)(param_2 + 5) - param_3;
      _Src = (void *)(lVar3 + (ulonglong)param_3);
      do {
        uVar9 = param_4;
        if (uVar6 <= param_4) {
          uVar9 = uVar6;
        }
        if (param_1 == 0) {
LAB_14000666a:
          memmove(param_5,_Src,(ulonglong)uVar9);
        }
        else {
          if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
             (*(char *)(param_1 + 4) == '\0')) {
            lVar3 = 0;
            *(undefined1 *)(param_1 + 4) = 1;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar2 != 0)) {
              lVar3 = lVar2 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
            }
            LOCK();
            *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
            UNLOCK();
          }
          uVar6 = *(uint *)(*(longlong *)(param_1 + 0x50) + 4);
          if (uVar6 == 0) {
            if (*(int *)(param_1 + 0x14) != 0) {
              BLFlushBatchOpContextEx(param_1,'\x01','\0');
            }
            if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
               ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6))))
            goto LAB_14000666a;
            (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
            memmove(param_5,_Src,(ulonglong)uVar9);
            (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
          }
          else {
            puVar4 = *(undefined8 **)(param_1 + 0x20);
            uVar10 = *(uint *)(puVar4 + 1);
            if (*(uint *)((longlong)puVar4 + 0xc) <= uVar10) {
              uVar10 = 0;
              if ((*(uint *)(param_1 + 0x10) < uVar6) &&
                 (puVar4 = (undefined8 *)
                           ExAllocateFromNPagedLookasideList(*(longlong *)(param_1 + 0x50) + 0x40),
                 puVar4 != (undefined8 *)0x0)) {
                *puVar4 = 0;
                *(undefined4 *)(puVar4 + 1) = 0;
                uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x50) + 8);
                puVar4[2] = puVar4 + 3;
                *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
                **(undefined8 **)(param_1 + 0x20) = puVar4;
                *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
                *(undefined8 **)(param_1 + 0x20) = puVar4;
                if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
                  lVar3 = 0;
                  if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar2 != 0)) {
                    lVar3 = lVar2 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
                  }
                  LOCK();
                  *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
                  UNLOCK();
                  piVar7 = (int *)0x0;
                  if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
                    piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
                  }
                  LOCK();
                  *piVar7 = *piVar7 + 1;
                  UNLOCK();
                }
              }
              else {
                BLFlushBatchOpContextEx(param_1,'\x01','\0');
                puVar4 = (undefined8 *)(param_1 + 0x38);
              }
            }
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
            if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
              lVar3 = 0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar2 != 0)) {
                lVar3 = lVar2 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar3 + 0xe) = *(short *)(lVar3 + 0xe) + 1;
              UNLOCK();
              lVar3 = 0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar2 != 0)) {
                lVar3 = lVar2 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
              UNLOCK();
            }
            lVar3 = puVar4[2];
            uVar5 = (ulonglong)uVar10;
            *(void **)(lVar3 + uVar5 * 0x18) = param_5;
            *(void **)(lVar3 + 8 + uVar5 * 0x18) = _Src;
            *(uint *)(lVar3 + 0x10 + uVar5 * 0x18) = uVar9 << 4 | 1;
          }
        }
        param_5 = (void *)((longlong)param_5 + (ulonglong)uVar9);
        param_4 = param_4 - uVar9;
        if (param_4 == 0) {
          return 0;
        }
        param_2 = (undefined8 *)*param_2;
        if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
          _Src = (void *)MmMapLockedPagesSpecifyCache(param_2,0,1,0,0,0x40000000);
        }
        else {
          _Src = (void *)param_2[3];
        }
        uVar6 = *(uint *)(param_2 + 5);
      } while (_Src != (void *)0x0);
    }
    uVar8 = 0xc000009a;
    BLFlushBatchOpContextEx(param_1,'\0','\x01');
  }
  return uVar8;
}



===== SegLibPvtGetDataBufferWithOffset @ 140006708 =====

undefined8 SegLibPvtGetDataBufferWithOffset(undefined8 param_1,ulonglong param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  NdisAdvanceNetBufferDataStart(param_1,param_2,0,0);
  uVar1 = NdisGetDataBuffer(param_1,param_3,0,1,0);
  NdisRetreatNetBufferDataStart(param_1,param_2 & 0xffffffff,0,0);
  return uVar1;
}



===== SegLibPvtLsoDeferredFixHeaders @ 140006784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SegLibPvtLsoDeferredFixHeaders
               (longlong param_1,short *param_2,longlong param_3,longlong param_4,int param_5,
               int param_6)

{
  undefined4 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  int *piVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  ushort uVar12;
  short sVar13;
  uint *puVar14;
  short *psVar15;
  byte bVar16;
  longlong *plVar17;
  uint uVar18;
  ushort *puVar19;
  short local_res8;
  uint local_58;
  
  lVar11 = 0;
  local_58 = 0xcccc;
  if (param_5 == *(int *)(param_2 + 4)) {
    local_res8 = param_2[0xc] + (param_2[2] - (short)param_6);
    bVar16 = *(byte *)((longlong)param_2 + 0x1b) & 2;
    if (param_1 == 0) {
LAB_1400069ee:
      if (bVar16 == 0) {
        bVar16 = *(byte *)(param_4 + 0xd) & 0xfe;
      }
      else {
        bVar16 = *(byte *)(param_4 + 0xd) | 1;
      }
      *(byte *)(param_4 + 0xd) = bVar16;
    }
    else {
      if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
         (*(char *)(param_1 + 4) == '\0')) {
        lVar3 = 0;
        *(undefined1 *)(param_1 + 4) = 1;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
        UNLOCK();
      }
      uVar10 = *(uint *)(*(longlong *)(param_1 + 0x50) + 4);
      if (uVar10 == 0) {
        if (*(int *)(param_1 + 0x14) != 0) {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
        }
        if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
           ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_1400069ee;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
        if (bVar16 == 0) {
          bVar16 = *(byte *)(param_4 + 0xd) & 0xfe;
        }
        else {
          bVar16 = *(byte *)(param_4 + 0xd) | 1;
        }
        *(byte *)(param_4 + 0xd) = bVar16;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
      }
      else {
        puVar4 = *(undefined8 **)(param_1 + 0x20);
        uVar9 = *(uint *)(puVar4 + 1);
        if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
          uVar9 = 0;
          if ((*(uint *)(param_1 + 0x10) < uVar10) &&
             (puVar4 = (undefined8 *)
                       ExAllocateFromNPagedLookasideList(*(longlong *)(param_1 + 0x50) + 0x40),
             puVar4 != (undefined8 *)0x0)) {
            *puVar4 = 0;
            *(undefined4 *)(puVar4 + 1) = 0;
            uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x50) + 8);
            puVar4[2] = puVar4 + 3;
            *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
            **(undefined8 **)(param_1 + 0x20) = puVar4;
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
            *(undefined8 **)(param_1 + 0x20) = puVar4;
            if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
              lVar3 = 0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
                lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
              UNLOCK();
              piVar7 = (int *)0x0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
                piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
              }
              LOCK();
              *piVar7 = *piVar7 + 1;
              UNLOCK();
            }
          }
          else {
            BLFlushBatchOpContextEx(param_1,'\x01','\0');
            puVar4 = (undefined8 *)(param_1 + 0x38);
          }
        }
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
        if (*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') {
          lVar3 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
            lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(short *)(lVar3 + 0xe) = *(short *)(lVar3 + 0xe) + 1;
          UNLOCK();
          lVar3 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
            lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
          UNLOCK();
        }
        lVar3 = puVar4[2];
        uVar2 = (ulonglong)uVar9;
        *(longlong *)(lVar3 + uVar2 * 0x18) = param_4;
        *(undefined4 *)(lVar3 + 8 + uVar2 * 0x18) = 0x68;
        *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
             5 - (bVar16 != 0) | *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff0;
      }
    }
    bVar8 = *(byte *)((longlong)param_2 + 0x1b) & 4;
    if (param_1 == 0) {
LAB_140006c1e:
      bVar16 = *(byte *)(param_4 + 0xd);
      if (bVar8 == 0) goto LAB_140007012;
      bVar16 = bVar16 | 8;
      goto LAB_140007016;
    }
    if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') && (*(char *)(param_1 + 4) == '\0')
       ) {
      lVar3 = 0;
      *(undefined1 *)(param_1 + 4) = 1;
      if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
        lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
      }
      LOCK();
      *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
      UNLOCK();
    }
    plVar17 = (longlong *)(param_1 + 0x50);
    uVar10 = *(uint *)(*plVar17 + 4);
    if (uVar10 == 0) {
      if (*(int *)(param_1 + 0x14) != 0) {
        BLFlushBatchOpContextEx(param_1,'\x01','\0');
      }
      if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
         ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_140006c1e;
      (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
      bVar16 = *(byte *)(param_4 + 0xd);
      if (bVar8 == 0) goto LAB_140006c03;
      bVar16 = bVar16 | 8;
LAB_140006c07:
      *(byte *)(param_4 + 0xd) = bVar16;
      (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
    }
    else {
      puVar4 = *(undefined8 **)(param_1 + 0x20);
      uVar9 = *(uint *)(puVar4 + 1);
      if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
        uVar9 = 0;
        if ((*(uint *)(param_1 + 0x10) < uVar10) &&
           (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
           puVar4 != (undefined8 *)0x0)) {
          *puVar4 = 0;
          *(undefined4 *)(puVar4 + 1) = 0;
          uVar1 = *(undefined4 *)(*plVar17 + 8);
          puVar4[2] = puVar4 + 3;
          *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
          **(undefined8 **)(param_1 + 0x20) = puVar4;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined8 **)(param_1 + 0x20) = puVar4;
          if (*(char *)(*plVar17 + 1) == '\x01') {
            lVar3 = 0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
              lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
            }
            LOCK();
            *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
            UNLOCK();
            piVar7 = (int *)0x0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
              piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
            }
            LOCK();
            *piVar7 = *piVar7 + 1;
            UNLOCK();
          }
        }
        else {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
          puVar4 = (undefined8 *)(param_1 + 0x38);
        }
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      lVar3 = *(longlong *)(param_1 + 0x50);
      if (*(char *)(lVar3 + 1) == '\x01') {
        lVar5 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
          lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
        UNLOCK();
        lVar3 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
        UNLOCK();
      }
      lVar3 = puVar4[2];
      uVar2 = (ulonglong)uVar9;
      *(longlong *)(lVar3 + uVar2 * 0x18) = param_4;
      *(undefined4 *)(lVar3 + 8 + uVar2 * 0x18) = 0x6b;
      *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
           5 - (bVar8 != 0) | *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff0;
    }
  }
  else {
    local_res8 = param_2[0xc] + *param_2;
    if (param_1 == 0) {
LAB_140006e2b:
      *(byte *)(param_4 + 0xd) = *(byte *)(param_4 + 0xd) & 0xfe;
LAB_140006e3a:
      if (param_1 != 0) goto LAB_140006e43;
    }
    else {
      if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
         (*(char *)(param_1 + 4) == '\0')) {
        lVar3 = 0;
        *(undefined1 *)(param_1 + 4) = 1;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
        UNLOCK();
      }
      plVar17 = (longlong *)(param_1 + 0x50);
      uVar10 = *(uint *)(*plVar17 + 4);
      if (uVar10 == 0) {
        if (*(int *)(param_1 + 0x14) != 0) {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
        }
        if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
           ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_140006e2b;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
        *(byte *)(param_4 + 0xd) = *(byte *)(param_4 + 0xd) & 0xfe;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
        goto LAB_140006e3a;
      }
      puVar4 = *(undefined8 **)(param_1 + 0x20);
      uVar9 = *(uint *)(puVar4 + 1);
      if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
        uVar9 = 0;
        if ((*(uint *)(param_1 + 0x10) < uVar10) &&
           (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
           puVar4 != (undefined8 *)0x0)) {
          *puVar4 = 0;
          *(undefined4 *)(puVar4 + 1) = 0;
          uVar1 = *(undefined4 *)(*plVar17 + 8);
          puVar4[2] = puVar4 + 3;
          *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
          **(undefined8 **)(param_1 + 0x20) = puVar4;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined8 **)(param_1 + 0x20) = puVar4;
          if (*(char *)(*plVar17 + 1) == '\x01') {
            lVar3 = 0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
              lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
            }
            LOCK();
            *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
            UNLOCK();
            piVar7 = (int *)0x0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
              piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
            }
            LOCK();
            *piVar7 = *piVar7 + 1;
            UNLOCK();
          }
        }
        else {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
          puVar4 = (undefined8 *)(param_1 + 0x38);
        }
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      lVar3 = *(longlong *)(param_1 + 0x50);
      if (*(char *)(lVar3 + 1) == '\x01') {
        lVar5 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
          lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
        UNLOCK();
        lVar3 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
        UNLOCK();
      }
      lVar3 = puVar4[2];
      uVar2 = (ulonglong)uVar9;
      *(longlong *)(lVar3 + uVar2 * 0x18) = param_4;
      *(undefined4 *)(lVar3 + 8 + uVar2 * 0x18) = 0x68;
      *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
           *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff5 | 5;
LAB_140006e43:
      if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
         (*(char *)(param_1 + 4) == '\0')) {
        lVar3 = 0;
        *(undefined1 *)(param_1 + 4) = 1;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
        UNLOCK();
      }
      plVar17 = (longlong *)(param_1 + 0x50);
      uVar10 = *(uint *)(*plVar17 + 4);
      if (uVar10 != 0) {
        puVar4 = *(undefined8 **)(param_1 + 0x20);
        uVar9 = *(uint *)(puVar4 + 1);
        if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
          uVar9 = 0;
          if ((*(uint *)(param_1 + 0x10) < uVar10) &&
             (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
             puVar4 != (undefined8 *)0x0)) {
            *puVar4 = 0;
            *(undefined4 *)(puVar4 + 1) = 0;
            uVar1 = *(undefined4 *)(*plVar17 + 8);
            puVar4[2] = puVar4 + 3;
            *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
            **(undefined8 **)(param_1 + 0x20) = puVar4;
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
            *(undefined8 **)(param_1 + 0x20) = puVar4;
            if (*(char *)(*plVar17 + 1) == '\x01') {
              lVar3 = 0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
                lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
              UNLOCK();
              piVar7 = (int *)0x0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
                piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
              }
              LOCK();
              *piVar7 = *piVar7 + 1;
              UNLOCK();
            }
          }
          else {
            BLFlushBatchOpContextEx(param_1,'\x01','\0');
            puVar4 = (undefined8 *)(param_1 + 0x38);
          }
        }
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
        lVar3 = *(longlong *)(param_1 + 0x50);
        if (*(char *)(lVar3 + 1) == '\x01') {
          lVar5 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
            lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
          UNLOCK();
          lVar3 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
            lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
          UNLOCK();
        }
        lVar3 = puVar4[2];
        uVar2 = (ulonglong)uVar9;
        *(longlong *)(lVar3 + uVar2 * 0x18) = param_4;
        *(undefined4 *)(lVar3 + 8 + uVar2 * 0x18) = 0x6b;
        *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
             *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff5 | 5;
        goto LAB_14000701b;
      }
      if (*(int *)(param_1 + 0x14) != 0) {
        BLFlushBatchOpContextEx(param_1,'\x01','\0');
      }
      if ((((byte)*(undefined4 *)(param_1 + 8) & 5) == 5) ||
         ((param_1 != 0 && (((byte)*(undefined4 *)(param_1 + 8) & 6) == 6)))) {
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
        bVar16 = *(byte *)(param_4 + 0xd);
LAB_140006c03:
        bVar16 = bVar16 & 0xf7;
        goto LAB_140006c07;
      }
    }
    bVar16 = *(byte *)(param_4 + 0xd);
LAB_140007012:
    bVar16 = bVar16 & 0xf7;
LAB_140007016:
    *(byte *)(param_4 + 0xd) = bVar16;
  }
LAB_14000701b:
  puVar14 = (uint *)(param_4 + 4);
  uVar10 = param_6 + *(int *)(param_2 + 6);
  uVar10 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 * 0x1000000;
  if (param_1 == 0) {
LAB_14000720f:
    *puVar14 = uVar10;
  }
  else {
    if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') && (*(char *)(param_1 + 4) == '\0')
       ) {
      lVar3 = 0;
      *(undefined1 *)(param_1 + 4) = 1;
      if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
        lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
      }
      LOCK();
      *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
      UNLOCK();
    }
    plVar17 = (longlong *)(param_1 + 0x50);
    uVar9 = *(uint *)(*plVar17 + 4);
    if (uVar9 == 0) {
      if (*(int *)(param_1 + 0x14) != 0) {
        BLFlushBatchOpContextEx(param_1,'\x01','\0');
      }
      if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
         ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_14000720f;
      (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
      *puVar14 = uVar10;
      (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
    }
    else {
      puVar4 = *(undefined8 **)(param_1 + 0x20);
      uVar18 = *(uint *)(puVar4 + 1);
      if (*(uint *)((longlong)puVar4 + 0xc) <= uVar18) {
        uVar18 = 0;
        if ((*(uint *)(param_1 + 0x10) < uVar9) &&
           (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
           puVar4 != (undefined8 *)0x0)) {
          *puVar4 = 0;
          *(undefined4 *)(puVar4 + 1) = 0;
          uVar1 = *(undefined4 *)(*plVar17 + 8);
          puVar4[2] = puVar4 + 3;
          *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
          **(undefined8 **)(param_1 + 0x20) = puVar4;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined8 **)(param_1 + 0x20) = puVar4;
          if (*(char *)(*plVar17 + 1) == '\x01') {
            lVar3 = 0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
              lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
            }
            LOCK();
            *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
            UNLOCK();
            piVar7 = (int *)0x0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
              piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
            }
            LOCK();
            *piVar7 = *piVar7 + 1;
            UNLOCK();
          }
        }
        else {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
          puVar4 = (undefined8 *)(param_1 + 0x38);
        }
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      lVar3 = *(longlong *)(param_1 + 0x50);
      if (*(char *)(lVar3 + 1) == '\x01') {
        lVar5 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
          lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
        UNLOCK();
        lVar3 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
        UNLOCK();
      }
      lVar3 = puVar4[2];
      uVar2 = (ulonglong)uVar18;
      *(uint **)(lVar3 + uVar2 * 0x18) = puVar14;
      *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
           *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff3 | 3;
      *(uint *)(lVar3 + 8 + uVar2 * 0x18) = uVar10;
    }
  }
  if ((*(byte *)((longlong)param_2 + 0x1b) & 1) == 0) {
    uVar12 = (short)param_5 + param_2[8];
    uVar12 = (uVar12 & 0x7fff) >> 8 | uVar12 * 0x100;
    puVar19 = (ushort *)(param_3 + 4);
    local_58 = (uint)uVar12;
    if (param_1 == 0) {
LAB_140007424:
      *puVar19 = uVar12;
    }
    else {
      if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
         (*(char *)(param_1 + 4) == '\0')) {
        lVar3 = 0;
        *(undefined1 *)(param_1 + 4) = 1;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
        UNLOCK();
      }
      plVar17 = (longlong *)(param_1 + 0x50);
      uVar10 = *(uint *)(*plVar17 + 4);
      if (uVar10 == 0) {
        if (*(int *)(param_1 + 0x14) != 0) {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
        }
        if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
           ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_140007424;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
        *puVar19 = uVar12;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
      }
      else {
        puVar4 = *(undefined8 **)(param_1 + 0x20);
        uVar9 = *(uint *)(puVar4 + 1);
        if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
          uVar9 = 0;
          if ((*(uint *)(param_1 + 0x10) < uVar10) &&
             (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
             puVar4 != (undefined8 *)0x0)) {
            *puVar4 = 0;
            *(undefined4 *)(puVar4 + 1) = 0;
            uVar1 = *(undefined4 *)(*plVar17 + 8);
            puVar4[2] = puVar4 + 3;
            *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
            **(undefined8 **)(param_1 + 0x20) = puVar4;
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
            *(undefined8 **)(param_1 + 0x20) = puVar4;
            if (*(char *)(*plVar17 + 1) == '\x01') {
              lVar3 = 0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
                lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
              UNLOCK();
              piVar7 = (int *)0x0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
                piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
              }
              LOCK();
              *piVar7 = *piVar7 + 1;
              UNLOCK();
            }
          }
          else {
            BLFlushBatchOpContextEx(param_1,'\x01','\0');
            puVar4 = (undefined8 *)(param_1 + 0x38);
          }
        }
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
        lVar3 = *(longlong *)(param_1 + 0x50);
        if (*(char *)(lVar3 + 1) == '\x01') {
          lVar5 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
            lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
          UNLOCK();
          lVar3 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
            lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
          UNLOCK();
        }
        lVar3 = puVar4[2];
        uVar2 = (ulonglong)uVar9;
        *(ushort **)(lVar3 + uVar2 * 0x18) = puVar19;
        *(ushort *)(lVar3 + 8 + uVar2 * 0x18) = uVar12;
        *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
             *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff2 | 2;
      }
    }
  }
  if ((*(byte *)((longlong)param_2 + 0x1b) & 0x10) != 0) {
    return;
  }
  psVar15 = (short *)(param_4 + 0x10);
  iVar6 = (uint)(ushort)((ushort)(local_res8 - param_2[0xb]) >> 8 |
                        (local_res8 - param_2[0xb]) * 0x100) + (uint)(ushort)param_2[10];
  sVar13 = (short)((uint)iVar6 >> 0x10) + (short)iVar6;
  if (param_1 == 0) {
LAB_14000765c:
    *psVar15 = sVar13;
  }
  else {
    if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') && (*(char *)(param_1 + 4) == '\0')
       ) {
      lVar3 = 0;
      *(undefined1 *)(param_1 + 4) = 1;
      if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
        lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
      }
      LOCK();
      *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
      UNLOCK();
    }
    plVar17 = (longlong *)(param_1 + 0x50);
    uVar10 = *(uint *)(*plVar17 + 4);
    if (uVar10 == 0) {
      if (*(int *)(param_1 + 0x14) != 0) {
        BLFlushBatchOpContextEx(param_1,'\x01','\0');
      }
      if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
         ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_14000765c;
      (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
      *psVar15 = sVar13;
      (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
    }
    else {
      puVar4 = *(undefined8 **)(param_1 + 0x20);
      uVar9 = *(uint *)(puVar4 + 1);
      if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
        uVar9 = 0;
        if ((*(uint *)(param_1 + 0x10) < uVar10) &&
           (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
           puVar4 != (undefined8 *)0x0)) {
          *puVar4 = 0;
          *(undefined4 *)(puVar4 + 1) = 0;
          uVar1 = *(undefined4 *)(*plVar17 + 8);
          puVar4[2] = puVar4 + 3;
          *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
          **(undefined8 **)(param_1 + 0x20) = puVar4;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined8 **)(param_1 + 0x20) = puVar4;
          if (*(char *)(*plVar17 + 1) == '\x01') {
            lVar3 = 0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
              lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
            }
            LOCK();
            *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
            UNLOCK();
            piVar7 = (int *)0x0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
              piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
            }
            LOCK();
            *piVar7 = *piVar7 + 1;
            UNLOCK();
          }
        }
        else {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
          puVar4 = (undefined8 *)(param_1 + 0x38);
        }
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      lVar3 = *(longlong *)(param_1 + 0x50);
      if (*(char *)(lVar3 + 1) == '\x01') {
        lVar5 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
          lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
        UNLOCK();
        lVar3 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
        UNLOCK();
      }
      lVar3 = puVar4[2];
      uVar2 = (ulonglong)uVar9;
      *(short **)(lVar3 + uVar2 * 0x18) = psVar15;
      *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
           *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff2 | 2;
      *(short *)(lVar3 + 8 + uVar2 * 0x18) = sVar13;
    }
  }
  uVar12 = local_res8 - (ushort)*(byte *)(param_2 + 0xd);
  if ((*(byte *)((longlong)param_2 + 0x1b) & 1) == 0) {
    uVar12 = uVar12 >> 8 | uVar12 * 0x100;
    puVar19 = (ushort *)(param_3 + 2);
    if (param_1 == 0) {
LAB_140007a99:
      *puVar19 = uVar12;
    }
    else {
      if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
         (*(char *)(param_1 + 4) == '\0')) {
        *(undefined1 *)(param_1 + 4) = 1;
        lVar3 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
        UNLOCK();
      }
      else if (param_1 == 0) goto LAB_140007a99;
      plVar17 = (longlong *)(param_1 + 0x50);
      uVar10 = *(uint *)(*plVar17 + 4);
      if (uVar10 == 0) {
        if (*(int *)(param_1 + 0x14) != 0) {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
        }
        if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
           ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_140007a99;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
        *puVar19 = uVar12;
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
      }
      else {
        puVar4 = *(undefined8 **)(param_1 + 0x20);
        uVar9 = *(uint *)(puVar4 + 1);
        if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
          uVar9 = 0;
          if ((*(uint *)(param_1 + 0x10) < uVar10) &&
             (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
             puVar4 != (undefined8 *)0x0)) {
            *puVar4 = 0;
            *(undefined4 *)(puVar4 + 1) = 0;
            uVar1 = *(undefined4 *)(*plVar17 + 8);
            puVar4[2] = puVar4 + 3;
            *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
            **(undefined8 **)(param_1 + 0x20) = puVar4;
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
            *(undefined8 **)(param_1 + 0x20) = puVar4;
            if (*(char *)(*plVar17 + 1) == '\x01') {
              lVar3 = 0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
                lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
              UNLOCK();
              piVar7 = (int *)0x0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
                piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
              }
              LOCK();
              *piVar7 = *piVar7 + 1;
              UNLOCK();
            }
          }
          else {
            BLFlushBatchOpContextEx(param_1,'\x01','\0');
            puVar4 = (undefined8 *)(param_1 + 0x38);
          }
        }
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
        lVar3 = *(longlong *)(param_1 + 0x50);
        if (*(char *)(lVar3 + 1) == '\x01') {
          lVar5 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
            lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
          UNLOCK();
          lVar3 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
            lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
          UNLOCK();
        }
        lVar3 = puVar4[2];
        uVar2 = (ulonglong)uVar9;
        *(ushort **)(lVar3 + uVar2 * 0x18) = puVar19;
        *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) =
             *(uint *)(lVar3 + 0x10 + uVar2 * 0x18) & 0xfffffff2 | 2;
        *(ushort *)(lVar3 + 8 + uVar2 * 0x18) = uVar12;
      }
    }
    puVar19 = (ushort *)(param_3 + 10);
    uVar10 = (ushort)param_2[9] + local_58 + (uint)uVar12;
    uVar12 = ~(ushort)((uVar10 >> 0x10 | uVar10 * 0x10000) + uVar10 >> 0x10);
    if (param_1 != 0) {
      if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') &&
         (*(char *)(param_1 + 4) == '\0')) {
        lVar3 = 0;
        *(undefined1 *)(param_1 + 4) = 1;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
          lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
        UNLOCK();
      }
      plVar17 = (longlong *)(param_1 + 0x50);
      uVar10 = *(uint *)(*plVar17 + 4);
      if (uVar10 != 0) {
        puVar4 = *(undefined8 **)(param_1 + 0x20);
        uVar9 = *(uint *)(puVar4 + 1);
        if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
          uVar9 = 0;
          if ((*(uint *)(param_1 + 0x10) < uVar10) &&
             (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
             puVar4 != (undefined8 *)0x0)) {
            *puVar4 = 0;
            *(undefined4 *)(puVar4 + 1) = 0;
            uVar1 = *(undefined4 *)(*plVar17 + 8);
            puVar4[2] = puVar4 + 3;
            *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
            **(undefined8 **)(param_1 + 0x20) = puVar4;
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
            *(undefined8 **)(param_1 + 0x20) = puVar4;
            if (*(char *)(*plVar17 + 1) == '\x01') {
              lVar3 = 0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
                lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
              }
              LOCK();
              *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
              UNLOCK();
              piVar7 = (int *)0x0;
              if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
                 (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
                piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
              }
              LOCK();
              *piVar7 = *piVar7 + 1;
              UNLOCK();
            }
          }
          else {
            BLFlushBatchOpContextEx(param_1,'\x01','\0');
            puVar4 = (undefined8 *)(param_1 + 0x38);
          }
        }
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
        lVar3 = *(longlong *)(param_1 + 0x50);
        if (*(char *)(lVar3 + 1) == '\x01') {
          lVar5 = 0;
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
            lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
          UNLOCK();
          if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
             (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
            lVar11 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
          }
          LOCK();
          *(int *)(lVar11 + 4) = *(int *)(lVar11 + 4) + 1;
          UNLOCK();
        }
        lVar11 = puVar4[2];
        uVar2 = (ulonglong)uVar9;
        *(ushort **)(lVar11 + uVar2 * 0x18) = puVar19;
        *(ushort *)(lVar11 + 8 + uVar2 * 0x18) = uVar12;
        *(uint *)(lVar11 + 0x10 + uVar2 * 0x18) =
             *(uint *)(lVar11 + 0x10 + uVar2 * 0x18) & 0xfffffff2 | 2;
        return;
      }
      if (*(int *)(param_1 + 0x14) != 0) {
        BLFlushBatchOpContextEx(param_1,'\x01','\0');
      }
      if ((((byte)*(undefined4 *)(param_1 + 8) & 5) == 5) ||
         ((param_1 != 0 && (((byte)*(undefined4 *)(param_1 + 8) & 6) == 6)))) {
        (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
        *puVar19 = uVar12;
        goto LAB_140007731;
      }
    }
    *puVar19 = uVar12;
  }
  else {
    uVar12 = (ushort)(uVar12 - 0x28) >> 8 | (uVar12 - 0x28) * 0x100;
    puVar19 = (ushort *)(param_3 + 4);
    if (param_1 == 0) {
LAB_140007881:
      *puVar19 = uVar12;
      return;
    }
    if ((*(char *)(*(longlong *)(param_1 + 0x50) + 1) == '\x01') && (*(char *)(param_1 + 4) == '\0')
       ) {
      lVar3 = 0;
      *(undefined1 *)(param_1 + 4) = 1;
      if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar5 != 0)) {
        lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
      }
      LOCK();
      *(short *)(lVar3 + 0x10) = *(short *)(lVar3 + 0x10) + 1;
      UNLOCK();
    }
    plVar17 = (longlong *)(param_1 + 0x50);
    uVar10 = *(uint *)(*plVar17 + 4);
    if (uVar10 != 0) {
      puVar4 = *(undefined8 **)(param_1 + 0x20);
      uVar9 = *(uint *)(puVar4 + 1);
      if (*(uint *)((longlong)puVar4 + 0xc) <= uVar9) {
        uVar9 = 0;
        if ((*(uint *)(param_1 + 0x10) < uVar10) &&
           (puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar17 + 0x40),
           puVar4 != (undefined8 *)0x0)) {
          *puVar4 = 0;
          *(undefined4 *)(puVar4 + 1) = 0;
          uVar1 = *(undefined4 *)(*plVar17 + 8);
          puVar4[2] = puVar4 + 3;
          *(undefined4 *)((longlong)puVar4 + 0xc) = uVar1;
          **(undefined8 **)(param_1 + 0x20) = puVar4;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined8 **)(param_1 + 0x20) = puVar4;
          if (*(char *)(*plVar17 + 1) == '\x01') {
            lVar3 = 0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar5 = *(longlong *)(*plVar17 + 0x18), lVar5 != 0)) {
              lVar3 = lVar5 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
            }
            LOCK();
            *(short *)(lVar3 + 0xc) = *(short *)(lVar3 + 0xc) + 1;
            UNLOCK();
            piVar7 = (int *)0x0;
            if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
              piVar7 = (int *)(lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14);
            }
            LOCK();
            *piVar7 = *piVar7 + 1;
            UNLOCK();
          }
        }
        else {
          BLFlushBatchOpContextEx(param_1,'\x01','\0');
          puVar4 = (undefined8 *)(param_1 + 0x38);
        }
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      lVar3 = *(longlong *)(param_1 + 0x50);
      if (*(char *)(lVar3 + 1) == '\x01') {
        lVar5 = 0;
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
          lVar5 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(short *)(lVar5 + 0xe) = *(short *)(lVar5 + 0xe) + 1;
        UNLOCK();
        if ((*(uint *)(param_1 + 0xc) != 0xffffffff) &&
           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x18), lVar3 != 0)) {
          lVar11 = lVar3 + (ulonglong)*(uint *)(param_1 + 0xc) * 0x14;
        }
        LOCK();
        *(int *)(lVar11 + 4) = *(int *)(lVar11 + 4) + 1;
        UNLOCK();
      }
      lVar11 = puVar4[2];
      uVar2 = (ulonglong)uVar9;
      *(ushort **)(lVar11 + uVar2 * 0x18) = puVar19;
      *(uint *)(lVar11 + 0x10 + uVar2 * 0x18) =
           *(uint *)(lVar11 + 0x10 + uVar2 * 0x18) & 0xfffffff2 | 2;
      *(ushort *)(lVar11 + 8 + uVar2 * 0x18) = uVar12;
      return;
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      BLFlushBatchOpContextEx(param_1,'\x01','\0');
    }
    if ((((byte)*(undefined4 *)(param_1 + 8) & 5) != 5) &&
       ((param_1 == 0 || (((byte)*(undefined4 *)(param_1 + 8) & 6) != 6)))) goto LAB_140007881;
    (**(code **)(*(longlong *)(param_1 + 0x50) + 0x20))();
    *puVar19 = uVar12;
LAB_140007731:
    (**(code **)(*(longlong *)(param_1 + 0x50) + 0x28))();
  }
  return;
}



===== SegLibPvtLsoInitialize @ 140007cb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
SegLibPvtLsoInitialize
          (uint *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,ulonglong param_5,
          undefined2 param_6,byte param_7)

{
  longlong lVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined8 uVar7;
  byte bVar8;
  byte bVar9;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  longlong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  if (param_5 == 0) {
    param_5 = *(ulonglong *)(param_2 + 0xa0);
  }
  *(undefined1 *)((longlong)param_1 + 0x1a) = 0xe;
  uVar5 = (uint)param_5;
  uVar6 = (ushort)(param_5 >> 0x14) & 0x3ff;
  *(ushort *)((longlong)param_1 + 0x16) = uVar6;
  lVar1 = *(longlong *)(param_2 + 8);
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (*(uint *)(lVar1 + 0x18) < uVar6 + 0x14) {
    uVar7 = 0xc0000023;
  }
  else {
    NdisAdvanceNetBufferDataStart(lVar1,uVar6,0,0);
    bVar9 = 1;
    local_78 = 0;
    local_68 = NdisGetDataBuffer(lVar1,0x14,&local_60,1);
    NdisRetreatNetBufferDataStart(lVar1,uVar6,0,0);
    if (local_68 == 0) {
      uVar7 = 0xc000009a;
    }
    else {
      iVar3 = (uint)(*(byte *)(local_68 + 0xc) >> 4) * 4;
      uVar2 = (ushort)iVar3;
      if (((0x13 < uVar2) && (uVar4 = iVar3 + (uint)uVar6, uVar6 <= uVar4)) &&
         (uVar4 <= *(uint *)(lVar1 + 0x18))) {
        uVar2 = uVar2 + uVar6;
        if (uVar2 < uVar6) {
          *(undefined2 *)(param_1 + 6) = 0xffff;
          return 0xc0000095;
        }
        *(ushort *)(param_1 + 6) = uVar2;
        bVar8 = (param_7 & 1) << 5 ^ *(byte *)((longlong)param_1 + 0x1b) & 0xdf;
        *param_1 = uVar5 & 0xfffff;
        *(byte *)((longlong)param_1 + 0x1b) = bVar8 & 0xef;
        if ((ushort)(*(byte *)((longlong)param_1 + 0x1a) + 0x14) <=
            *(ushort *)((longlong)param_1 + 0x16)) {
          uVar4 = *(int *)(*(longlong *)(param_2 + 8) + 0x18) - (uint)(ushort)param_1[6];
          param_1[2] = 0;
          param_1[1] = uVar4;
          if (uVar4 != 0) {
            param_1[2] = (uVar4 - 1) / (uVar5 & 0xfffff);
          }
          if (((uVar5 >> 0x1e & 1) == 0) || (-1 < (int)uVar5)) {
            bVar9 = 0;
          }
          *(undefined2 *)(param_1 + 5) = param_6;
          *(byte *)((longlong)param_1 + 0x1b) = bVar8 & 0xe6 | bVar9;
          return 0;
        }
      }
      uVar7 = 0xc0230015;
    }
  }
  return uVar7;
}



===== SegLibPvtParseHeaders @ 140007eb4 =====

undefined8 SegLibPvtParseHeaders(longlong param_1,ulonglong *param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  
  uVar1 = *(uint *)(param_3 + 4);
  *(uint *)(param_1 + 0xc) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  bVar4 = (*(char *)(param_3 + 0xd) * '\x02' ^ *(byte *)(param_1 + 0x1b)) & 2 ^
          *(byte *)(param_1 + 0x1b);
  *(byte *)(param_1 + 0x1b) = bVar4;
  *(byte *)(param_1 + 0x1b) = *(byte *)(param_3 + 0xd) >> 1 & 4 | bVar4 & 0xfb;
  if (*(short *)(param_1 + 0x14) == 0) {
    *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_3 + 0x10);
  }
  if ((bVar4 & 1) == 0) {
    uVar1 = (uint)((byte)*param_2 & 0xf) * 4;
    if ((uint)*(ushort *)(param_1 + 0x18) < *(byte *)(param_1 + 0x1a) + uVar1) {
      return 0xc0230015;
    }
    *(ushort *)(param_1 + 0x10) =
         *(ushort *)((longlong)param_2 + 4) >> 8 | *(ushort *)((longlong)param_2 + 4) << 8;
    if ((*(byte *)(param_1 + 0x1b) & 0x10) == 0) {
      uVar3 = (uint)*(ushort *)((longlong)param_2 + 10) + (uint)*(ushort *)((longlong)param_2 + 2) +
              (uint)*(ushort *)((longlong)param_2 + 4);
      iVar2 = tcpxsum(~(ushort)((uVar3 >> 0x10 | uVar3 * 0x10000) + uVar3 >> 0x10),param_2,uVar1);
      *(short *)(param_1 + 0x12) = (short)iVar2;
    }
  }
  *(byte *)(param_1 + 0x1b) = *(byte *)(param_1 + 0x1b) | 8;
  return 0;
}



===== SegLibPvtProcessAdditionalOffloadInfo @ 140007f90 =====

void SegLibPvtProcessAdditionalOffloadInfo
               (longlong param_1,undefined8 param_2,undefined8 *param_3,undefined2 *param_4,
               ushort *param_5,byte *param_6,undefined1 *param_7,undefined1 *param_8,
               undefined1 *param_9)

{
  ulonglong uVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  
  bVar3 = 0;
  uVar4 = 0;
  if (*(int *)(param_1 + 0xa0) == 0) {
    uVar1 = *(ulonglong *)(param_1 + 0x90);
    if ((uVar1 & 0x1c) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      bVar3 = (byte)(uVar1 >> 1) & 1;
      if ((uVar1 & 4) != 0) {
        uVar4 = (ushort)(uVar1 >> 0x10) & 0x3ff;
      }
    }
  }
  else {
    uVar2 = 1;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
    *param_4 = 0;
    *param_9 = 0;
  }
  if (param_5 != (ushort *)0x0) {
    *param_5 = uVar4;
    *param_6 = bVar3;
  }
  if (param_7 != (undefined1 *)0x0) {
    *param_7 = uVar2;
  }
  if (param_8 != (undefined1 *)0x0) {
    *param_8 = 0;
  }
  return;
}



===== SegLibUninitialize @ 140008028 =====

void SegLibUninitialize(void)

{
  DAT_14000d268 = 0;
  if ((DAT_14000d278 != '\0') && (DAT_14000d270 != 0)) {
    MdpDestroyPool();
    DAT_14000d270 = 0;
  }
  IppSegLibContext = 0;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140008070 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
LAB_140008279:
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar6 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar6 = uVar3 | uVar6 & 0xffffbfff;
      }
      uVar5 = uVar6 >> 5 & 0x1ff;
      uVar3 = uVar5 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 5 ^ uVar6) & 0x3fe0 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_14000814b:
        uVar6 = 0;
        if (param_3 == 2) {
          uVar6 = 2;
        }
        else if (param_3 == 3) {
          uVar6 = 8;
        }
        else if (param_3 == 6) {
          uVar6 = 4;
        }
        else if (param_3 == 7) {
          uVar6 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar6 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar5 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar5 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar5;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_140008279;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar6 = param_3 - 0x140;
          if ((int)uVar6 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
                uVar3 = 0;
              }
              else {
                uVar3 = 1;
              }
              param_1[4] = uVar3;
              LOCK();
              uVar3 = param_2[1];
              bVar7 = uVar4 == uVar3;
              if (bVar7) {
                param_2[1] = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
              }
              else {
                uVar4 = uVar3;
              }
              UNLOCK();
            } while (!bVar7);
            if (param_1[4] != 0) {
              return param_1;
            }
          }
          param_1[2] = param_3;
          param_1[1] = 1;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_14000814b;
      }
    }
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar6 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar6 = uVar3 | uVar6 & 0xffbfffff;
      }
      uVar5 = uVar6 >> 0xf & 0x7f;
      uVar3 = uVar5 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 0xf ^ uVar6) & 0x3f8000 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140008364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_140008427;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140008427;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140008427;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140008427;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140008427;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140008427;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140008427;
    }
  }
  uVar2 = 0xff;
LAB_140008427:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x2f01c1e,&Feature_TCPIP_2025_Wave2_SegLibHeap_logged_traits,0,uVar4,local_res18,0,0,
               1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140008480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

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
                     (local_50,(uint *)&Feature_TCPIP_2025_Wave2_SegLibHeap__private_reporting,
                      param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x2f01c1e,param_3,1,&Feature_TCPIP_2025_Wave2_SegLibHeap__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x2f01c1e);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000856c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_14000861f:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_14000864d;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000861f;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_14000864d:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400087d8 =====

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
  if ((Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState & 2) != 0) {
    uVar1 = Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState;
      if (bVar3) {
        Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState;
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



===== wil_details_IsEnabledFallback @ 14000882c =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState,
                             (ulonglong)param_1,0x14000c1d8);
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



===== _guard_check_icall @ 1400088d0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400088e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000890c =====

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



===== __chkstk @ 140008972 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140008972. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== __cpu_features_init @ 140008990 =====

/* WARNING: Removing unreachable block (ram,0x0001400089fa) */
/* WARNING: Removing unreachable block (ram,0x0001400089a9) */
/* WARNING: Removing unreachable block (ram,0x00014000899a) */

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



===== tcpxsum @ 140008a60 =====

int tcpxsum(ushort param_1,ulonglong *param_2,uint param_3)

{
  ulonglong uVar1;
  ushort uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong *puVar8;
  bool bVar9;
  bool bVar10;
  
  uVar3 = 0;
  if (param_3 == 0) goto LAB_140008b91;
  puVar8 = param_2;
  if (((ulonglong)param_2 & 1) == 0) {
LAB_140008a98:
    uVar4 = param_3 >> 1;
    uVar5 = (ulonglong)uVar4;
    if (((param_3 & 1) == 0) ||
       (uVar3 = CONCAT71((int7)(uVar3 >> 8),(char)*(ushort *)((longlong)puVar8 + uVar5 * 2)),
       uVar4 != 0)) {
joined_r0x000140008aaa:
      if (((ulonglong)puVar8 & 6) != 0) goto LAB_140008aac;
      if (uVar4 >> 2 != 0) {
        uVar7 = uVar4 >> 6;
        bVar9 = false;
        uVar6 = uVar4 >> 2 & 0xf;
        if (uVar6 == 0) goto LAB_140008b00;
        puVar8 = puVar8 + ((ulonglong)uVar6 - 0x10);
        bVar10 = 0xfffffffe < uVar7;
        uVar7 = uVar7 + 1;
        switch(uVar6) {
        case 2:
          goto switchD_140008af6_caseD_2;
        case 3:
          goto switchD_140008af6_caseD_3;
        case 4:
          goto switchD_140008af6_caseD_4;
        case 5:
          goto switchD_140008af6_caseD_5;
        case 6:
          goto switchD_140008af6_caseD_6;
        case 7:
          goto switchD_140008af6_caseD_7;
        case 8:
          goto switchD_140008af6_caseD_8;
        case 9:
          goto switchD_140008af6_caseD_9;
        case 10:
          goto switchD_140008af6_caseD_a;
        case 0xb:
          goto switchD_140008af6_caseD_b;
        case 0xc:
          goto switchD_140008af6_caseD_c;
        case 0xd:
          goto switchD_140008af6_caseD_d;
        case 0xe:
          goto switchD_140008af6_caseD_e;
        case 0xf:
          goto switchD_140008af6_caseD_f;
        }
        while( true ) {
          uVar5 = uVar3 + puVar8[0xf];
          bVar9 = CARRY8(uVar3,puVar8[0xf]) || CARRY8(uVar5,(ulonglong)bVar10);
          uVar3 = uVar5 + bVar10;
          puVar8 = puVar8 + 0x10;
          uVar7 = uVar7 - 1;
          if (uVar7 == 0) break;
LAB_140008b00:
          bVar10 = CARRY8(uVar3,*puVar8) || CARRY8(uVar3 + *puVar8,(ulonglong)bVar9);
          uVar3 = uVar3 + *puVar8 + (ulonglong)bVar9;
switchD_140008af6_caseD_f:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[1];
          bVar10 = CARRY8(uVar3,puVar8[1]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_e:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[2];
          bVar10 = CARRY8(uVar3,puVar8[2]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_d:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[3];
          bVar10 = CARRY8(uVar3,puVar8[3]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_c:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[4];
          bVar10 = CARRY8(uVar3,puVar8[4]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_b:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[5];
          bVar10 = CARRY8(uVar3,puVar8[5]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_a:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[6];
          bVar10 = CARRY8(uVar3,puVar8[6]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_9:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[7];
          bVar10 = CARRY8(uVar3,puVar8[7]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_8:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[8];
          bVar10 = CARRY8(uVar3,puVar8[8]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_7:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[9];
          bVar10 = CARRY8(uVar3,puVar8[9]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_6:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[10];
          bVar10 = CARRY8(uVar3,puVar8[10]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_5:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xb];
          bVar10 = CARRY8(uVar3,puVar8[0xb]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_4:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xc];
          bVar10 = CARRY8(uVar3,puVar8[0xc]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_3:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xd];
          bVar10 = CARRY8(uVar3,puVar8[0xd]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140008af6_caseD_2:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xe];
          bVar10 = CARRY8(uVar3,puVar8[0xe]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
        }
        uVar3 = uVar3 + bVar9;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = CONCAT62((int6)(uVar3 >> 0x10),
                         (ushort)uVar3 + (ushort)*puVar8 +
                         (ushort)CARRY2((ushort)uVar3,(ushort)*puVar8));
        puVar8 = (ulonglong *)((longlong)puVar8 + 2);
      }
    }
  }
  else {
    uVar3 = (ulonglong)(byte)*param_2 << 8;
    puVar8 = (ulonglong *)((longlong)param_2 + 1);
    param_3 = param_3 - 1;
    if (param_3 != 0) goto LAB_140008a98;
  }
LAB_140008b6f:
  uVar4 = (uint)(uVar3 + (uVar3 >> 0x20 | uVar3 << 0x20) >> 0x20);
  uVar4 = uVar4 + (uVar4 >> 0x10 | uVar4 << 0x10);
  uVar3 = (ulonglong)(uVar4 >> 0x10);
  if (((ulonglong)param_2 & 1) != 0) {
    uVar2 = (ushort)(uVar4 >> 0x10);
    uVar3 = (ulonglong)(ushort)(uVar2 >> 8 | uVar2 << 8);
  }
LAB_140008b91:
  return (uint)(ushort)((ushort)uVar3 + param_1) + (uint)CARRY2((ushort)uVar3,param_1);
LAB_140008aac:
  uVar3 = (ulonglong)
          ((int)CONCAT62((int6)(uVar3 >> 0x10),(ushort)uVar3 + (ushort)*puVar8) +
          (uint)CARRY2((ushort)uVar3,(ushort)*puVar8));
  puVar8 = (ulonglong *)((longlong)puVar8 + 2);
  uVar4 = (int)uVar5 - 1;
  uVar5 = (ulonglong)uVar4;
  if (uVar4 == 0) goto LAB_140008b6f;
  goto joined_r0x000140008aaa;
}



===== __security_check_cookie @ 140008bb0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140008bf0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140008c20 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140008c20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140008c50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140008cc0 =====

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



===== memset @ 140008fc0 =====

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



===== __memset_repmovs @ 140009100 =====

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



===== __memset_query @ 140009180 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140009200 =====

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



===== __memset_spec_ermsb_repmovsb @ 140009340 =====

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



===== __memset_spec_plain @ 1400093c0 =====

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



===== CreateBridge @ 140011008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CreateBridge(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  longlong *_Dst;
  longlong lVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  *param_3 = 0;
  _Dst = (longlong *)ExAllocatePoolWithTag(0x600,0x40,0x7242324c);
  if (_Dst == (longlong *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,0x40);
  uVar7 = 0;
  _Dst[5] = _DAT_fffff78000000008;
  uVar6 = 0;
  cVar2 = RtlCreateHashTable(_Dst + 3);
  if (cVar2 != '\0') {
    lVar4 = NdisAllocateRWLock(0);
    _Dst[4] = lVar4;
    if (lVar4 != 0) {
      *(undefined2 *)(param_1 + 0xa8) = 0x101;
      *(undefined1 *)(param_1 + 0xaa) = 1;
      *(undefined2 *)(param_2 + 0xa8) = 0x100;
      *(undefined1 *)(param_2 + 0xaa) = 0;
      if (1 < *(int *)(param_1 + 100) - 8U) {
        uVar6 = 4;
        iVar3 = UpdatePacketFilter(param_1,4,uVar7);
        if (iVar3 < 0) goto LAB_14001110c;
      }
      if (*(int *)(param_2 + 100) - 8U < 2) {
LAB_140011132:
        _Dst[6] = param_1;
        LOCK();
        *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + 1;
        UNLOCK();
        _Dst[7] = param_2;
        LOCK();
        *(int *)(param_2 + 0xb0) = *(int *)(param_2 + 0xb0) + 1;
        UNLOCK();
        puVar5 = &BridgeList;
        *(longlong **)(_Dst[6] + 0xe0) = _Dst;
        *(longlong **)(_Dst[7] + 0xe0) = _Dst;
        if ((undefined *)*DAT_14000d3c8 != &BridgeList) {
          puVar5 = (undefined *)0x3;
          pcVar1 = (code *)swi(0x29);
          DAT_14000d3c8 = (longlong *)(*pcVar1)();
        }
        *_Dst = (longlong)puVar5;
        _Dst[1] = (longlong)DAT_14000d3c8;
        *DAT_14000d3c8 = (longlong)_Dst;
        DAT_14000d3c8 = _Dst;
        *(undefined2 *)(_Dst + 2) = 0x101;
        *param_3 = _Dst;
        return 0;
      }
      uVar6 = 0x20;
      iVar3 = UpdatePacketFilter(param_2,0x20,uVar7);
      if (-1 < iVar3) goto LAB_140011132;
      goto LAB_14001110c;
    }
  }
  iVar3 = -0x3fffff66;
LAB_14001110c:
  if (_Dst[6] != 0) {
    DisconnectInterfaceFromBridge(_Dst[6],uVar6,uVar7);
  }
  if (_Dst[7] != 0) {
    DisconnectInterfaceFromBridge(_Dst[7],uVar6,uVar7);
  }
  FreeBridgeResources(_Dst);
  return iVar3;
}



===== DisconnectInterfaceFromBridge @ 1400111b8 =====

void DisconnectInterfaceFromBridge(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  plVar2 = *(longlong **)(param_1 + 0xe0);
  if (plVar2 != (longlong *)0x0) {
    lVar3 = plVar2[6];
    plVar1 = plVar2 + 7;
    if ((lVar3 == param_1) || (lVar3 = *plVar1, lVar3 == param_1)) {
      *(undefined1 *)((longlong)plVar2 + 0x11) = 0;
      RestorePacketFilter(lVar3,param_2,param_3);
      *(undefined8 *)(lVar3 + 0xe0) = 0;
      DEREF_FILTER_MODULE(lVar3);
      if (plVar2[6] == param_1) {
        plVar2[6] = 0;
      }
      else {
        *plVar1 = 0;
        if (plVar2[6] != 0) {
          return;
        }
      }
      if (*plVar1 == 0) {
        FreeBridgeResources(plVar2);
      }
    }
  }
  return;
}



===== DriverUnload @ 140011250 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DriverUnload(void)

{
  undefined8 uVar1;
  
  if (NdisFilterDeviceHandle != 0) {
    NdisDeregisterDeviceEx();
    NdisFilterDeviceHandle = 0;
  }
  if (FilterDriverHandle != 0) {
    NdisFDeregisterFilterDriver();
    FilterDriverHandle = 0;
  }
  if (SegLibInitialized != '\0') {
    SegLibUninitialize();
    BLUninitialize();
  }
  if (FeatureStagingEnabled != '\0') {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  uVar1 = DAT_14000d100;
  if (TraceLoggingRegistered != '\0') {
    DAT_14000d100 = 0;
    _DAT_14000d0e0 = 0;
    EtwUnregister(uVar1);
  }
  return;
}



===== FilterAttach @ 140011330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FilterAttach(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  ushort uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  undefined8 *_Dst;
  longlong lVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  puVar10 = auStack_58;
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0;
  if (((*(int *)(param_3 + 0x48) != 0) && (*(int *)(param_3 + 0x48) != 9)) ||
     (*(short *)(param_3 + 0x60) != 6)) {
    iVar7 = -0x3ffffff3;
    goto LAB_1400114b3;
  }
  _Dst = (undefined8 *)
         ExAllocatePoolWithTag
                   (0x600,(ulonglong)**(ushort **)(param_3 + 0x10) +
                          (ulonglong)**(ushort **)(param_3 + 0x20) +
                          (ulonglong)**(ushort **)(param_3 + 0x28) + 0xe8,0x7242324c);
  puVar10 = auStack_58;
  if (_Dst == (undefined8 *)0x0) {
    iVar7 = -0x3fffff66;
    goto LAB_1400114b3;
  }
  memset(_Dst,0,0xe8);
  *(undefined4 *)(_Dst + 0x16) = 1;
  uVar1 = **(ushort **)(param_3 + 0x10);
  *(ushort *)((longlong)_Dst + 0x22) = uVar1;
  *(ushort *)(_Dst + 4) = uVar1;
  _Dst[5] = _Dst + 0x1d;
  memmove(_Dst + 0x1d,*(void **)(*(longlong *)(param_3 + 0x10) + 8),(ulonglong)uVar1);
  uVar1 = **(ushort **)(param_3 + 0x20);
  *(ushort *)((longlong)_Dst + 0x32) = uVar1;
  *(ushort *)(_Dst + 6) = uVar1;
  _Dst[7] = (void *)((ulonglong)*(ushort *)(_Dst + 4) + _Dst[5]);
  memmove((void *)((ulonglong)*(ushort *)(_Dst + 4) + _Dst[5]),
          *(void **)(*(longlong *)(param_3 + 0x20) + 8),(ulonglong)uVar1);
  uVar1 = **(ushort **)(param_3 + 0x28);
  *(ushort *)((longlong)_Dst + 0x42) = uVar1;
  *(ushort *)(_Dst + 8) = uVar1;
  _Dst[9] = (void *)((ulonglong)*(ushort *)(_Dst + 6) + _Dst[7]);
  memmove((void *)((ulonglong)*(ushort *)(_Dst + 6) + _Dst[7]),
          *(void **)(*(longlong *)(param_3 + 0x28) + 8),(ulonglong)uVar1);
  *(undefined4 *)(_Dst + 10) = *(undefined4 *)(param_3 + 0x18);
  _Dst[0xb] = *(undefined8 *)(param_3 + 0x88);
  *(undefined4 *)(_Dst + 0xc) = *(undefined4 *)(param_3 + 0x48);
  *(undefined4 *)((longlong)_Dst + 100) = *(undefined4 *)(param_3 + 0x4c);
  memmove(_Dst + 0xd,(void *)(param_3 + 0x62),(ulonglong)*(ushort *)(param_3 + 0x60));
  _Dst[3] = param_1;
  lVar8 = NdisAllocateRWLock(0);
  _Dst[2] = lVar8;
  if (lVar8 == 0) {
LAB_1400114a6:
    iVar7 = -0x3fffff66;
  }
  else {
    lVar8 = ExAllocateCacheAwareRundownProtection(0x200,0x7242324c);
    _Dst[0x13] = lVar8;
    if (lVar8 == 0) goto LAB_1400114a6;
    lVar8 = ExAllocateCacheAwareRundownProtection(0x200,0x7242324c);
    _Dst[0x14] = lVar8;
    if (lVar8 == 0) goto LAB_1400114a6;
    ExWaitForRundownProtectionReleaseCacheAware(_Dst[0x13]);
    lVar8 = *(longlong *)(param_3 + 0x58);
    if (lVar8 != 0) {
      uVar3 = *(undefined4 *)(lVar8 + 0x54);
      uVar4 = *(undefined4 *)(lVar8 + 0x58);
      uVar5 = *(undefined4 *)(lVar8 + 0x5c);
      *(undefined4 *)(_Dst + 0xe) = *(undefined4 *)(lVar8 + 0x50);
      *(undefined4 *)((longlong)_Dst + 0x74) = uVar3;
      *(undefined4 *)(_Dst + 0xf) = uVar4;
      *(undefined4 *)((longlong)_Dst + 0x7c) = uVar5;
      _Dst[0x10] = *(undefined8 *)(lVar8 + 0x60);
      *(undefined4 *)(_Dst + 0x11) = *(undefined4 *)(lVar8 + 0x68);
    }
    local_38 = 0x8018d;
    iVar7 = NdisFSetAttributes(param_1,_Dst,&local_38);
    if (iVar7 == 0) {
      local_24 = 0;
      local_30 = 0x100180;
      local_2c = 0x280100;
      local_28 = 0x7242324c;
      lVar8 = NdisAllocateNetBufferListPool(_Dst[3],&local_30);
      _Dst[0x17] = lVar8;
      if (lVar8 != 0) {
        _Dst[0x1b] = _DAT_fffff78000000008;
        cVar6 = RtlCreateHashTable(_Dst + 0x19,0,0);
        if (cVar6 != '\0') {
          lVar8 = NdisAllocateRWLock(0);
          _Dst[0x1a] = lVar8;
          if (lVar8 != 0) {
            *(undefined4 *)(_Dst + 0x12) = 1;
            KeEnterCriticalRegion();
            ExAcquirePushLockExclusiveEx(&FilterModuleListLock,0);
            puVar10 = auStack_58;
            puVar9 = &FilterModuleList;
            if ((undefined8 *)*DAT_14000d298 != &FilterModuleList) {
              puVar9 = (undefined8 *)0x3;
              pcVar2 = (code *)swi(0x29);
              DAT_14000d298 = (undefined8 *)(*pcVar2)();
              puVar10 = auStack_50;
            }
            *_Dst = puVar9;
            _Dst[1] = DAT_14000d298;
            *DAT_14000d298 = _Dst;
            *(undefined8 *)(puVar10 + -8) = 0x140011667;
            DAT_14000d298 = _Dst;
            ExReleasePushLockExclusiveEx(&FilterModuleListLock,0);
            *(undefined8 *)(puVar10 + -8) = 0x140011673;
            KeLeaveCriticalRegion();
            goto LAB_1400114b3;
          }
        }
      }
      goto LAB_1400114a6;
    }
  }
  puVar10 = auStack_58;
  DEREF_FILTER_MODULE((longlong)_Dst);
LAB_1400114b3:
  *(undefined8 *)(puVar10 + -8) = 0x1400114c1;
  return iVar7;
}



===== FilterDeregisterDevice @ 140011684 =====

void FilterDeregisterDevice(void)

{
  if (NdisFilterDeviceHandle != 0) {
    NdisDeregisterDeviceEx();
    NdisFilterDeviceHandle = 0;
  }
  return;
}



===== FilterDetach @ 1400116c0 =====

void FilterDetach(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  ExWaitForRundownProtectionReleaseCacheAware(param_1[0x14]);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&FilterModuleListLock,0);
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
  uVar4 = 0;
  ExReleasePushLockExclusiveEx(&FilterModuleListLock);
  KeLeaveCriticalRegion();
  RestorePacketFilter((longlong)param_1,uVar4,param_3);
  if (param_1[0x1c] != 0) {
    KeEnterCriticalRegion();
    uVar4 = 0;
    ExAcquirePushLockExclusiveEx(&BridgeLock);
    DisconnectInterfaceFromBridge((longlong)param_1,uVar4,param_3);
    ExReleasePushLockExclusiveEx(&BridgeLock,0);
    KeLeaveCriticalRegion();
  }
  DEREF_FILTER_MODULE((longlong)param_1);
  return;
}



===== FilterDispatchNotSupported @ 1400117c0 =====

undefined8 FilterDispatchNotSupported(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
  return 0xc00000bb;
}



===== FilterDispatchSuccess @ 140011800 =====

undefined8 FilterDispatchSuccess(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== FilterFastDeviceIoControl @ 140011830 =====

undefined8
FilterFastDeviceIoControl
          (undefined8 param_1,undefined8 param_2,longlong *param_3,ulonglong param_4,
          longlong *param_5,int param_6,int param_7,undefined4 *param_8)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 extraout_var;
  
  cVar1 = IoIs32bitProcess(0);
  if (cVar1 == '\0') {
    if (param_7 == 0x12a000) {
      iVar2 = L2BridgeCtlBridgeInterfaces_Handler
                        (param_3,(undefined4 *)(param_4 & 0xffffffff),param_5,param_6);
      uVar3 = CONCAT44(extraout_var,iVar2);
    }
    else {
      uVar3 = 0xc0000010;
    }
  }
  else {
    uVar3 = 0xc00000bb;
  }
  *(undefined8 *)(param_8 + 2) = 0;
  *param_8 = (int)uVar3;
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== FilterPause @ 1400118a0 =====

undefined8 FilterPause(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x90) = 2;
  ExWaitForRundownProtectionReleaseCacheAware(*(undefined8 *)(param_1 + 0x98));
  *(undefined4 *)(param_1 + 0x90) = 1;
  if (*(longlong *)(param_1 + 0xe0) != 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 0xe0) + 0x11) = 0;
  }
  return 0;
}



===== FilterRestart @ 1400118f0 =====

undefined8 FilterRestart(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar5 = auStack_28;
  for (puVar3 = *(undefined8 **)(param_2 + 0x10);
      (puVar3 != (undefined8 *)0x0 && (*(int *)(puVar3 + 1) != 0x1021d));
      puVar3 = (undefined8 *)*puVar3) {
  }
  if (puVar3 == (undefined8 *)0x0) {
    pcVar2 = (code *)swi(0x2c);
    (*pcVar2)();
    puVar5 = auStack_20;
    uVar4 = 0x5dc;
  }
  else {
    uVar4 = *(undefined4 *)((longlong)puVar3 + 0x14);
  }
  *(undefined4 *)(param_1 + 0x8c) = uVar4;
  uVar1 = *(undefined8 *)(param_1 + 0x98);
  *(undefined8 *)(puVar5 + -8) = 0x140011935;
  ExReInitializeRundownProtectionCacheAware(uVar1);
  *(undefined4 *)(param_1 + 0x90) = 3;
  return 0;
}



===== FreeBridgeResources @ 140011954 =====

void FreeBridgeResources(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  
  if ((char)param_1[2] != '\0') {
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
  }
  if (param_1[3] != 0) {
    CleanupMACAddressesTable((longlong)param_1);
    RtlDeleteHashTable(param_1[3]);
    param_1[3] = 0;
  }
  if (param_1[4] != 0) {
    NdisFreeRWLock();
    param_1[4] = 0;
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== L2BridgeCtlBridgeInterfaces_Handler @ 1400119e0 =====

int L2BridgeCtlBridgeInterfaces_Handler
              (longlong *param_1,undefined4 *param_2,longlong *param_3,int param_4)

{
  longlong *plVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  undefined7 uVar7;
  longlong local_48 [3];
  longlong local_30;
  longlong lStack_28;
  
  uVar5 = 0;
  local_48[1] = 0;
  puVar6 = (undefined4 *)0x0;
  local_48[0] = 0;
  bVar2 = false;
  if (((((uint)param_2 < 0x10) || (param_1 == (longlong *)0x0)) || (param_4 != 0)) ||
     (param_3 != (longlong *)0x0)) {
    iVar4 = -0x3ffffff3;
LAB_140011b5b:
    if (-1 < iVar4) goto LAB_140011b92;
  }
  else {
    cVar3 = ExGetPreviousMode();
    if ((cVar3 != '\0') && (((ulonglong)param_1 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_30 = *param_1;
    lStack_28 = param_1[1];
    uVar5 = L2BridgeFindandReferenceFilterModule(local_30);
    if ((uVar5 == 0) ||
       (puVar6 = (undefined4 *)L2BridgeFindandReferenceFilterModule(lStack_28),
       puVar6 == (undefined4 *)0x0)) {
      iVar4 = -0x3ffffddb;
    }
    else {
      if (*(int *)(uVar5 + 0x8c) == puVar6[0x23]) {
        KeEnterCriticalRegion();
        param_2 = (undefined4 *)0x0;
        ExAcquirePushLockExclusiveEx(&BridgeLock);
        bVar2 = true;
        if (*(longlong *)(uVar5 + 0xe0) == 0) {
          if (*(longlong *)(puVar6 + 0x38) == 0) {
            param_3 = local_48;
            param_2 = puVar6;
            iVar4 = CreateBridge(uVar5,(longlong)puVar6,param_3);
            if (-1 < iVar4) {
              uVar7 = (undefined7)((ulonglong)param_3 >> 8);
              AddOrUpdateMACForwardingTable
                        (*(longlong *)(uVar5 + 0xe0),(undefined4 *)(uVar5 + 0x68),1,uVar5,'\0');
              param_2 = puVar6 + 0x1a;
              param_3 = (longlong *)CONCAT71(uVar7,1);
              AddOrUpdateMACForwardingTable(*(longlong *)(puVar6 + 0x38),param_2,1,puVar6,'\0');
              iVar4 = 0;
            }
            goto LAB_140011b5b;
          }
          iVar4 = -0x3fffff10;
          goto LAB_140011b5f;
        }
      }
      iVar4 = -0x3fffff11;
    }
  }
LAB_140011b5f:
  if (local_48[0] != 0) {
    plVar1 = *(longlong **)(uVar5 + 0xe0);
    if (plVar1[6] != 0) {
      DisconnectInterfaceFromBridge(plVar1[6],param_2,param_3);
    }
    if (plVar1[7] != 0) {
      DisconnectInterfaceFromBridge(plVar1[7],param_2,param_3);
    }
    FreeBridgeResources(plVar1);
  }
LAB_140011b92:
  if (bVar2) {
    ExReleasePushLockExclusiveEx(&BridgeLock,0);
    KeLeaveCriticalRegion();
  }
  if (uVar5 != 0) {
    ExReleaseRundownProtectionCacheAware(*(undefined8 *)(uVar5 + 0xa0));
  }
  if (puVar6 != (undefined4 *)0x0) {
    ExReleaseRundownProtectionCacheAware(*(undefined8 *)(puVar6 + 0x28));
  }
  return iVar4;
}



===== L2BridgeFindandReferenceFilterModule @ 140011c08 =====

ulonglong L2BridgeFindandReferenceFilterModule(longlong param_1)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&FilterModuleListLock);
  puVar2 = FilterModuleList;
  if ((undefined8 **)FilterModuleList != &FilterModuleList) {
    do {
      puVar3 = puVar2;
      if (puVar2[0xb] == param_1) break;
      puVar2 = (undefined8 *)*puVar2;
      puVar3 = (undefined8 *)0x0;
    } while ((undefined8 **)puVar2 != &FilterModuleList);
    uVar4 = 0;
    if (puVar3 != (undefined8 *)0x0) {
      cVar1 = ExAcquireRundownProtectionCacheAware(puVar3[0x14]);
      uVar4 = (ulonglong)puVar3 & -(ulonglong)(cVar1 != '\0');
    }
  }
  ExReleasePushLockExclusiveEx(&FilterModuleListLock,0);
  KeLeaveCriticalRegion();
  return uVar4;
}



===== RestorePacketFilter @ 140011cb4 =====

void RestorePacketFilter(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong uVar2;
  
  if (*(char *)(param_1 + 0xc4) != '\0') {
    uVar2 = L2BridgeIssueOid(*(undefined8 *)(param_1 + 0x18),1,param_3,param_1 + 0xc0);
    iVar1 = NdisConvertNdisStatusToNtStatus(uVar2 & 0xffffffff);
    if (-1 < iVar1) {
      *(undefined1 *)(param_1 + 0xc4) = 0;
    }
  }
  return;
}



===== UpdatePacketFilter @ 140011d00 =====

void UpdatePacketFilter(longlong param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  
  uVar2 = L2BridgeIssueOid(*(undefined8 *)(param_1 + 0x18),0,param_3,(uint *)(param_1 + 0xc0));
  iVar1 = NdisConvertNdisStatusToNtStatus(uVar2 & 0xffffffff);
  if (-1 < iVar1) {
    local_res8[0] = param_2 | *(uint *)(param_1 + 0xc0);
    uVar2 = L2BridgeIssueOid(*(undefined8 *)(param_1 + 0x18),1,param_3,local_res8);
    iVar1 = NdisConvertNdisStatusToNtStatus(uVar2 & 0xffffffff);
    if (-1 < iVar1) {
      *(undefined1 *)(param_1 + 0xc4) = 1;
    }
  }
  return;
}



===== _tlgEnableCallback @ 140011d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140011e0c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140011e47;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140011ec1:
  while( true ) {
    if (&UNK_14000c20f < ppuVar3) {
      return;
    }
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  do {
    if (ppuVar3 == (undefined **)0x0) {
      return;
    }
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*ppuVar3,(longlong)ppuVar3);
    ppuVar3 = ppuVar3 + 7;
    while( true ) {
      if (&UNK_14000c20f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140011e47:
  while (ppuVar2 != (undefined **)0x0) {
    uVar1 = *(uint *)*ppuVar2;
    if ((uVar1 >> 9 & 1) != 0) {
      if ((uVar1 & 0x180) == 0) {
        bVar5 = *(char *)((longlong)ppuVar2 + 0x1f) != '\0';
      }
      else {
        bVar5 = (uVar1 & 0x180) == 0x100;
      }
      LOCK();
      *(uint *)*ppuVar2 = *(uint *)*ppuVar2 ^ uVar1 & 0x40 ^ (uint)bVar5 << 6;
      UNLOCK();
    }
    ppuVar2 = ppuVar2 + 7;
    while( true ) {
      if (&UNK_14000c20f < ppuVar2) goto LAB_140011ec1;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140011ec1;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140011efc =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = *param_1;
  if ((uVar6 >> 9 & 1) == 0) {
    uVar3 = uVar6;
  }
  else {
    uVar4 = uVar6 >> 6 & 1;
    if ((uVar4 != 0) && (plVar5 = *(longlong **)(param_2 + 0x20), plVar5 != (longlong *)0x0)) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)*plVar5;
          if (puVar1 == (undefined8 *)0x0) goto LAB_140011f94;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140011f94;
          }
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
        uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                          ((uint *)*puVar1,(longlong)puVar1);
        if ((uVar4 == 0) || ((uVar2 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        plVar5 = plVar5 + 1;
      } while (uVar4 != 0);
    }
LAB_140011f94:
    do {
      uVar2 = uVar6 & 0xffffffce;
      if ((uVar6 & 1) == uVar4) {
        uVar2 = uVar6 & 0xfffffffe;
      }
      uVar3 = uVar2 & 0xfffffdff | uVar4;
      LOCK();
      uVar2 = *param_1;
      bVar7 = uVar6 == uVar2;
      if (bVar7) {
        *param_1 = uVar3;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140011fe0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
        if (*ppuVar2 != (undefined *)0x0) {
          do {
            if (ppuVar2 == (undefined **)0x0) {
              return;
            }
            if ((*(uint *)ppuVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage(*(undefined4 *)(ppuVar2 + 3),(uint *)ppuVar2[1]);
            }
            ppuVar2 = ppuVar2 + 7;
            while( true ) {
              if (&UNK_14000c20f < ppuVar2) {
                return;
              }
              if (*ppuVar2 != (undefined *)0x0) break;
              ppuVar2 = ppuVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140012060 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001215d;
  }
LAB_140012166:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001215d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140012166;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001212e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001212e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000c20f < ppuVar3) goto LAB_140012166;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001215d;
}



===== entry @ 140013010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140013044 =====

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



===== DriverEntry @ 140013078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  code *pcVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_1b8 [8];
  undefined1 auStack_1b0 [56];
  undefined8 local_178;
  undefined8 local_168;
  undefined8 local_158;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined8 local_124;
  undefined2 local_118;
  undefined2 local_116;
  undefined4 local_114;
  wchar_t *local_110;
  undefined2 local_108;
  undefined2 local_106;
  undefined4 local_104;
  wchar_t *local_100;
  undefined2 local_f8;
  undefined2 local_f6;
  undefined4 local_f4;
  wchar_t *local_f0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_68;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  puVar9 = auStack_1b8;
  local_28 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_158 = 0x120010;
  local_168 = 0x4e004c;
  local_38 = *(undefined8 *)(PTR_DAT_14000d0e8 + -0x10);
  uStack_30 = *(undefined8 *)(PTR_DAT_14000d0e8 + -8);
  local_178 = 0x240022;
  if (DAT_14000d100 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar9 = auStack_1b0;
  }
  _DAT_14000d108 = 0;
  uRam000000014000d110 = 0;
  *(undefined8 *)(puVar9 + -8) = 0x14001311b;
  iVar2 = EtwRegister(&local_38,_tlgEnableCallback,&DAT_14000d0e0,&DAT_14000d100);
  if (iVar2 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000d0e8;
    *(undefined8 *)(puVar9 + -8) = 0x140013140;
    EtwSetInformation(DAT_14000d100,2,PTR_DAT_14000d0e8,uVar1);
  }
  TraceLoggingRegistered = 1;
  *(undefined8 *)(puVar9 + -8) = 0x140013151;
  wil_InitializeFeatureStaging();
  FeatureStagingEnabled = 1;
  if ((DAT_14000d2f0 == '\0') && (DAT_14000d150 == '\x01')) {
    _DAT_14000d2e0 = 0;
    uRam000000014000d2e8 = 0;
    if (DAT_14000d151 != '\0') {
      *(undefined8 *)(puVar9 + -8) = 0x14001319f;
      DAT_14000d2d8 = ExAllocatePool2(0x40,0xa000,0x6c746142);
      if (DAT_14000d2d8 == 0) goto LAB_14001320e;
    }
    _IppBatchingLibContext = CONCAT62(uRam000000014000d152,CONCAT11(DAT_14000d151,DAT_14000d150));
    _DAT_14000d2d0 = DAT_14000d160;
    *(undefined2 *)(puVar9 + 0x30) = 0;
    uRam000000014000d2c8 = uRam000000014000d158;
    *(undefined4 *)(puVar9 + 0x28) = 0x6c746142;
    *(ulonglong *)(puVar9 + 0x20) = (ulonglong)(uint)(((int)uRam000000014000d158 + 1) * 0x18);
    *(undefined8 *)(puVar9 + -8) = 0x140013202;
    ExInitializeNPagedLookasideList(&DAT_14000d300,0,0,0x200);
    DAT_14000d2f0 = '\x01';
  }
LAB_14001320e:
  DAT_14000d268 = &IppBatchingLibContext;
  _IppSegLibContext = 0;
  uStack_138 = 0;
  uStack_130 = 0;
  *(undefined8 *)(puVar9 + 0x70) = 0;
  *(undefined8 *)(puVar9 + 0x78) = 0;
  DAT_14000d270 = 0;
  _DAT_14000d278 = 0;
  if (NetioCopyNetBufferListQosInformationFnPtr == 0) {
    *(undefined8 *)(puVar9 + -8) = 0x14001325a;
    RtlInitUnicodeString(puVar9 + 0x70);
    puVar8 = puVar9 + 0x70;
    *(undefined8 *)(puVar9 + -8) = 0x14001326b;
    pcVar5 = (code *)MmGetSystemRoutineAddress();
    if (pcVar5 == (code *)0x0) {
      *(undefined8 *)(puVar9 + -8) = 0x1400132a9;
      lVar6 = SegLibGetModuleBase((ulonglong)puVar8);
      if (lVar6 == 0) goto LAB_1400132d2;
      *(undefined8 *)(puVar9 + -8) = 0x1400132bf;
      lVar6 = RtlFindExportedRoutineByName(lVar6);
    }
    else {
      *(undefined8 *)(puVar9 + -8) = 0x14001328a;
      RtlInitUnicodeString(&uStack_138,L"netio.sys");
      *(undefined8 *)(puVar9 + -8) = 0x1400132a2;
      lVar6 = (*pcVar5)(&uStack_138);
    }
    LOCK();
    if (NetioCopyNetBufferListQosInformationFnPtr == 0) {
      NetioCopyNetBufferListQosInformationFnPtr = lVar6;
    }
    UNLOCK();
  }
LAB_1400132d2:
  if ((Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState & 0x10) == 0) {
    *(undefined8 *)(puVar9 + -8) = 0x1400132e7;
    uVar7 = Feature_TCPIP_2025_Wave2_SegLibHeap__private_IsEnabledDeviceUsageNoInline();
    uVar3 = (uint)uVar7;
  }
  else {
    uVar3 = Feature_TCPIP_2025_Wave2_SegLibHeap__private_featureState & 1;
  }
  if (uVar3 != 0) {
    _DAT_14000d278 = CONCAT71(DAT_14000d278_1,1);
    *(undefined8 *)(puVar9 + -8) = 0x140013303;
    DAT_14000d270 = MdpCreatePool(0x708);
  }
  _IppSegLibContext = CONCAT71(IppSegLibContext_1,1);
  SegLibInitialized = 1;
  *(undefined8 *)(puVar9 + -8) = 0x140013335;
  FilterDriverObject = param_1;
  memset(&local_128,0,0xf0);
  local_118 = *(undefined2 *)(puVar9 + 0x40);
  local_116 = *(undefined2 *)(puVar9 + 0x42);
  local_114 = *(undefined4 *)(puVar9 + 0x44);
  local_110 = L"L2Bridge NDIS LWF";
  local_108 = *(undefined2 *)(puVar9 + 0x50);
  local_106 = *(undefined2 *)(puVar9 + 0x52);
  local_104 = *(undefined4 *)(puVar9 + 0x54);
  local_100 = L"{F15DC512-1E94-4CDB-9B42-27A953C64E67}";
  local_f8 = *(undefined2 *)(puVar9 + 0x60);
  local_f6 = *(undefined2 *)(puVar9 + 0x62);
  local_f4 = *(undefined4 *)(puVar9 + 100);
  local_f0 = L"L2BRIDGE";
  local_d8 = FilterAttach;
  local_d0 = FilterDetach;
  local_c8 = FilterRestart;
  local_c0 = FilterPause;
  local_b8 = FilterSendNetBufferLists;
  local_98 = FilterReturnNetBufferLists;
  local_b0 = FilterSendNetBufferListsComplete;
  local_a0 = FilterReceiveNetBufferLists;
  local_90 = FilterOidRequest;
  local_88 = FilterOidRequestComplete;
  local_68 = FilterStatus;
  *(code **)(param_1 + 0x68) = DriverUnload;
  DAT_14000d298 = &FilterModuleList;
  FilterModuleList = &FilterModuleList;
  DAT_14000d3c8 = &BridgeList;
  _BridgeList = &BridgeList;
  local_128 = 0xf0038b;
  local_124 = 0x15306;
  FilterDriverHandle = 0;
  _FilterModuleListLock = 0;
  _BridgeLock = 0;
  MACAddressTableHashSeed = (undefined4)_DAT_fffff78000000008;
  *(undefined8 *)(puVar9 + -8) = 0x14001349c;
  IPv6RewriteTableHashSeed = MACAddressTableHashSeed;
  DebugLock = NdisAllocateRWLock(0);
  *(undefined8 *)(puVar9 + -8) = 0x1400134c4;
  uVar4 = NdisFRegisterFilterDriver(param_1,FilterDriverObject,&local_128,&FilterDriverHandle);
  *(undefined8 *)(puVar9 + -8) = 0x1400134d2;
  iVar2 = NdisConvertNdisStatusToNtStatus(uVar4);
  if (-1 < iVar2) {
    *(undefined8 *)(puVar9 + -8) = 0x1400134e2;
    iVar2 = FilterRegisterDevice();
    *(undefined8 *)(puVar9 + -8) = 0x1400134eb;
    iVar2 = NdisConvertNdisStatusToNtStatus(iVar2);
    if (-1 < iVar2) {
      iVar2 = 0;
      goto LAB_140013502;
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x140013502;
  DriverUnload();
LAB_140013502:
  *(undefined8 *)(puVar9 + -8) = 0x140013513;
  return iVar2;
}



===== FilterRegisterDevice @ 140013534 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FilterRegisterDevice(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  undefined4 local_154;
  undefined8 *local_150;
  undefined8 *local_148;
  code **local_140;
  undefined4 local_138;
  undefined8 local_134;
  undefined8 uStack_12c;
  undefined4 local_124;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  code *local_f8 [2];
  code *local_e8;
  code *local_88;
  code *local_68;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_178;
  local_154 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_134 = 0;
  uStack_12c = 0;
  memset(local_f8,0,0xe0);
  local_f8[0] = FilterDispatchSuccess;
  local_68 = FilterDispatchSuccess;
  local_e8 = FilterDispatchSuccess;
  local_88 = FilterDispatchNotSupported;
  RtlInitUnicodeString(&local_120,L"\\device\\l2bridge");
  RtlInitUnicodeString(&local_110,L"\\DosDevices\\L2BRIDGE");
  local_150 = &local_120;
  local_154 = 0;
  local_124 = 0;
  local_148 = &local_110;
  local_158 = 0x380185;
  local_140 = local_f8;
  local_138 = 0x10;
  local_134 = 0;
  uStack_12c = 0;
  iVar1 = NdisRegisterDeviceEx(FilterDriverHandle,&local_158,&DeviceObject,&NdisFilterDeviceHandle);
  if (iVar1 == 0) {
    *(undefined **)(*(longlong *)(DeviceObject + 8) + 0x50) = &FilterFastIoDispatch;
    puVar2 = (undefined4 *)NdisGetDeviceReservedExtension(DeviceObject);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0x7242324c;
      *(undefined8 *)(puVar2 + 2) = FilterDriverHandle;
      return 0;
    }
    iVar1 = -0x3fffff66;
  }
  FilterDeregisterDevice();
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1400136b4 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001373b;
    }
LAB_140013775:
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
LAB_14001373b:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140013775;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140013775;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000c20f < ppuVar3) goto LAB_140013775;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001373b;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400137c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  do {
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14000c20f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1400138b2;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1400138b2;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1400138b2:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000c20f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


