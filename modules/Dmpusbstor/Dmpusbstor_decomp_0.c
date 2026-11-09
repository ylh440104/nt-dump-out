
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



===== DriverEntry @ 1c0001020 =====

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = DumpUsbStor_Setup(param_1,param_2);
  return iVar1;
}



===== DumpPreInitialize @ 1c0001060 =====

void DumpPreInitialize(void)

{
                    /* 0x1060  1  DumpPreInitialize */
  wil_InitializeFeatureStaging();
  return;
}



===== DumpUninitialize @ 1c0001080 =====

void DumpUninitialize(void)

{
                    /* 0x1080  2  DumpUninitialize */
  wil_UninitializeFeatureStaging();
  return;
}



===== wil_atomic_int32_exchange_release @ 1c00010a0 =====

undefined4 wil_atomic_int32_exchange_release(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  LOCK();
  uVar1 = *param_1;
  *param_1 = param_2;
  UNLOCK();
  return uVar1;
}



===== wil_atomic_pointer_store_relaxed @ 1c00010c0 =====

void wil_atomic_pointer_store_relaxed(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}



===== wil_atomic_uint32_compare_exchange_relaxed @ 1c00010e0 =====

bool wil_atomic_uint32_compare_exchange_relaxed(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  LOCK();
  if (iVar1 == *param_1) {
    *param_1 = param_3;
    iVar2 = iVar1;
  }
  else {
    iVar2 = *param_1;
  }
  UNLOCK();
  if (iVar2 != iVar1) {
    *param_2 = iVar2;
  }
  return iVar2 == iVar1;
}



===== wil_atomic_uint32_fetch_and_relaxed @ 1c0001150 =====

void wil_atomic_uint32_fetch_and_relaxed(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *param_1;
  do {
    LOCK();
    uVar1 = *param_1;
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *param_1 = uVar2 & param_2;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar3);
  return;
}



===== wil_atomic_uint32_fetch_or_relaxed @ 1c00011a0 =====

void wil_atomic_uint32_fetch_or_relaxed(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *param_1;
  do {
    LOCK();
    uVar1 = *param_1;
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *param_1 = uVar2 | param_2;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar3);
  return;
}



===== wil_atomic_uint32_fetch_xor_relaxed @ 1c00011f0 =====

void wil_atomic_uint32_fetch_xor_relaxed(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *param_1;
  do {
    LOCK();
    uVar1 = *param_1;
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *param_1 = uVar2 ^ param_2;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar3);
  return;
}



===== wil_atomic_uint32_load_relaxed @ 1c0001240 =====

undefined4 wil_atomic_uint32_load_relaxed(undefined4 *param_1)

{
  return *param_1;
}



===== wil_details_FeatureDescriptors_First @ 1c0001270 =====

void wil_details_FeatureDescriptors_First(void)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)wil_details_FeatureDescriptors_SectionBegin();
  wil_details_FeatureDescriptors_SkipPadding(plVar1);
  return;
}



===== wil_details_FeatureDescriptors_Next @ 1c00012a0 =====

void wil_details_FeatureDescriptors_Next(longlong param_1)

{
  wil_details_FeatureDescriptors_SkipPadding((longlong *)(param_1 + 0x38));
  return;
}



===== wil_details_FeatureDescriptors_SectionBegin @ 1c00012d0 =====

undefined * wil_details_FeatureDescriptors_SectionBegin(void)

{
  return &wil_details_featureDescriptors_z;
}



===== wil_details_FeatureDescriptors_SectionEnd @ 1c00012f0 =====

undefined * wil_details_FeatureDescriptors_SectionEnd(void)

{
  return &wil_details_featureDescriptors_z;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1c0001300 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  longlong *plVar1;
  longlong *local_res8;
  
  plVar1 = (longlong *)wil_details_FeatureDescriptors_SectionEnd();
  local_res8 = param_1;
  while( true ) {
    if (plVar1 <= local_res8) {
      return (longlong *)0x0;
    }
    if (*local_res8 != 0) break;
    local_res8 = local_res8 + 1;
  }
  return local_res8;
}



===== wil_details_RecordCachedUsage @ 1c0001360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2,undefined *param_3)

{
  longlong lVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint local_68;
  uint local_64;
  undefined4 *local_60;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_48;
  undefined4 local_40;
  ushort local_3c [2];
  undefined4 local_38 [10];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = &local_68;
  for (lVar1 = 4; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (uint *)((longlong)puVar2 + 1);
  }
  local_68 = 0xffc0401e;
  local_68 = wil_atomic_uint32_fetch_and_relaxed(param_2,0xffc0401e);
  puVar2 = &local_64;
  for (lVar1 = 4; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (uint *)((longlong)puVar2 + 1);
  }
  local_64 = local_68 >> 1 & 1 | (local_68 >> 2 & 1) << 1 | (local_68 >> 3 & 1) << 2 |
             (local_68 >> 4 & 1) << 3;
  if (local_64 != 0) {
    puVar2 = &local_58;
    for (lVar1 = 4; lVar1 != 0; lVar1 = lVar1 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (uint *)((longlong)puVar2 + 1);
    }
    local_58 = wil_atomic_uint32_fetch_or_relaxed(param_2 + 1,local_64);
    local_64 = local_64 & ~local_58;
  }
  local_60 = &local_40;
  if ((local_64 & 1) != 0) {
    local_3c[0] = 2;
    local_3c[1] = 1;
    local_60 = local_38;
    local_40 = param_1;
  }
  if ((local_64 >> 1 & 1) != 0) {
    *local_60 = param_1;
    *(undefined2 *)(local_60 + 1) = 6;
    *(undefined2 *)((longlong)local_60 + 6) = 1;
    local_60 = local_60 + 2;
  }
  if ((local_64 >> 2 & 1) != 0) {
    *local_60 = param_1;
    *(undefined2 *)(local_60 + 1) = 3;
    *(undefined2 *)((longlong)local_60 + 6) = 1;
    local_60 = local_60 + 2;
  }
  if ((local_64 >> 3 & 1) != 0) {
    *local_60 = param_1;
    *(undefined2 *)(local_60 + 1) = 7;
    *(undefined2 *)((longlong)local_60 + 6) = 1;
    local_60 = local_60 + 2;
  }
  if ((local_68 >> 5 & 0x1ff) != 0) {
    *local_60 = param_1;
    if ((local_68 >> 0xe & 1) == 0) {
      local_54 = 0;
    }
    else {
      local_54 = 4;
    }
    *(undefined2 *)(local_60 + 1) = (undefined2)local_54;
    *(ushort *)((longlong)local_60 + 6) = (ushort)(local_68 >> 5) & 0x1ff;
    local_60 = local_60 + 2;
  }
  if ((local_68 >> 0xf & 0x7f) != 0) {
    *local_60 = param_1;
    if ((local_68 >> 0x16 & 1) == 0) {
      local_50 = 1;
    }
    else {
      local_50 = 5;
    }
    *(undefined2 *)(local_60 + 1) = (undefined2)local_50;
    *(ushort *)((longlong)local_60 + 6) = (ushort)(local_68 >> 0xf) & 0x7f;
    local_60 = local_60 + 2;
  }
  if (0 < (longlong)local_60 - (longlong)&local_40 >> 3) {
    local_48 = param_3;
    (*(code *)param_3)(&local_40,(longlong)local_60 - (longlong)&local_40 >> 3);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 1c0001730 =====

void wil_details_RecordFeatureUsageReporting(undefined4 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int *in_stack_00000028;
  undefined4 local_18;
  undefined2 local_14;
  undefined2 local_12;
  
  puVar3 = &local_18;
  for (lVar2 = 8; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((longlong)puVar3 + 1);
  }
  if (*in_stack_00000028 != 0) {
    iVar1 = wil_atomic_int32_exchange_release((undefined4 *)&g_wil_details_featureUsageCached,1);
    if ((iVar1 == 0) && (g_wil_details_featureUsageProvider != 0)) {
      RtlArmFeatureUsageProviderFlushNotification(g_wil_details_featureUsageProvider,1);
    }
  }
  if (in_stack_00000028[1] != 0) {
    local_14 = (undefined2)in_stack_00000028[2];
    local_12 = (undefined2)in_stack_00000028[1];
    local_18 = param_1;
    RtlRecordFeatureUsage(&local_18,1);
  }
  return;
}



===== DumpUsbStor_AdapterState @ 1c00017f0 =====

undefined8 DumpUsbStor_AdapterState(void)

{
  return 1;
}



===== DumpUsbStor_BulkResetPipe @ 1c0001820 =====

/* WARNING: Removing unreachable block (ram,0x0001c0001865) */

int DumpUsbStor_BulkResetPipe(longlong param_1,void *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int local_28;
  
  lVar1 = *(longlong *)(param_1 + 8) + 0x20;
  local_28 = DumpUsbStor_ResetPipe(param_1,lVar1,param_3,param_4);
  if (local_28 < 0) {
    Log(param_1,0x44425231,(longlong)local_28,lVar1);
  }
  else {
    local_28 = DumpUsbStor_CswTransfer(param_1,param_2);
    if (local_28 < 0) {
      Log(param_1,0x44425232,(longlong)local_28,param_2);
    }
  }
  return local_28;
}



===== DumpUsbStor_CbwCompletion @ 1c0001910 =====

int DumpUsbStor_CbwCompletion(longlong param_1,void *param_2,longlong param_3,void *param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  void *pvVar4;
  void *pvVar5;
  int local_18;
  
  if (*(char *)((longlong)param_2 + 3) == '\x01') {
    if (((*(int *)((longlong)param_2 + 0x10) == 0) ||
        ((*(uint *)((longlong)param_2 + 0xc) & 0xc0) == 0)) &&
       (param_2 == *(void **)(param_1 + 0xc0))) {
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      local_18 = DumpUsbStor_CswTransfer(param_1,param_2);
      if (local_18 < 0) {
        Log(param_1,0x44434338,(longlong)local_18,param_2);
      }
    }
    else {
      uVar2 = DumpUsbStor_DataTransfer(param_1,(longlong)param_2);
      local_18 = (int)uVar2;
      if (local_18 < 0) {
        *(undefined1 *)((longlong)param_2 + 3) = 4;
        pvVar4 = param_2;
        iVar1 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
        if (iVar1 < 0) {
          param_3 = (longlong)iVar1;
          pvVar4 = (void *)0x44434335;
          param_4 = param_2;
          Log(param_1,0x44434335,param_3,param_2);
        }
        local_18 = DumpUsbStor_ResetDevice(param_1,pvVar4,param_3,param_4);
        if (local_18 < 0) {
          Log(param_1,0x44434336,(longlong)local_18,0);
        }
        Log(param_1,0x44434337,(longlong)local_18,(ulonglong)*(byte *)((longlong)param_2 + 3));
      }
    }
  }
  else {
    lVar3 = 0;
    pvVar5 = (void *)(ulonglong)*(byte *)((longlong)param_2 + 3);
    Log(param_1,0x44434331,0,pvVar5);
    pvVar4 = param_2;
    iVar1 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
    if (iVar1 < 0) {
      lVar3 = (longlong)iVar1;
      pvVar4 = (void *)0x44434332;
      pvVar5 = param_2;
      Log(param_1,0x44434332,lVar3,param_2);
    }
    iVar1 = DumpUsbStor_ResetDevice(param_1,pvVar4,lVar3,pvVar5);
    if (iVar1 < 0) {
      Log(param_1,0x44434333,(longlong)iVar1,0);
    }
    local_18 = -0x3ffffe7b;
    *(undefined1 *)((longlong)param_2 + 3) = 0xe;
    Log(param_1,0x44434334,0xffffffffc0000185,(ulonglong)*(byte *)((longlong)param_2 + 3));
  }
  return local_18;
}



===== DumpUsbStor_CbwTransfer @ 1c0001b30 =====

int DumpUsbStor_CbwTransfer(longlong param_1,void *param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  ulong uVar4;
  int iVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 local_40;
  
  lVar2 = *(longlong *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x2d8) = 0;
  uVar1 = *(undefined1 *)((longlong)param_2 + 7);
  puVar7 = (undefined1 *)(param_1 + 0xd8);
  for (lVar6 = 0x260; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puVar3 = *(undefined4 **)(lVar2 + 0x118);
  *puVar3 = 0x43425355;
  uVar4 = PtrToUlong(param_2);
  puVar3[1] = uVar4;
  puVar3[2] = *(undefined4 *)((longlong)param_2 + 0x10);
  if ((*(uint *)((longlong)param_2 + 0xc) & 0x40) == 0) {
    local_40 = 0;
  }
  else {
    local_40 = 0x80;
  }
  *(undefined1 *)(puVar3 + 3) = local_40;
  *(undefined1 *)((longlong)puVar3 + 0xd) = uVar1;
  *(undefined1 *)((longlong)puVar3 + 0xe) = *(undefined1 *)((longlong)param_2 + 10);
  puVar7 = (undefined1 *)((longlong)param_2 + 0x48);
  puVar8 = (undefined1 *)((longlong)puVar3 + 0xf);
  for (lVar6 = 0x10; lVar6 != 0; lVar6 = lVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar5 = DumpUsbStor_IssueBulkOrInterruptRequest
                    (param_1,(longlong)param_2,*(longlong *)(param_1 + 8) + 0x38,0,0x1f,puVar3,
                     lVar2 + 0x120,DumpUsbStor_CbwCompletion);
  if (iVar5 < 0) {
    Log(param_1,0x44434254,(longlong)iVar5,param_2);
  }
  return iVar5;
}



===== DumpUsbStor_CswCompletion @ 1c0001d10 =====

int DumpUsbStor_CswCompletion
              (longlong param_1,undefined2 *param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined2 *puVar5;
  longlong lVar6;
  undefined2 *puVar7;
  undefined2 *local_res10;
  int local_28;
  
  if (*(char *)((longlong)param_2 + 3) == '\x01') {
    if (*(char *)(param_1 + 0xe4) == '\0') {
      local_res10 = param_2;
      if (param_2 != *(undefined2 **)(param_1 + 0xc0)) {
        *(undefined1 *)(*(longlong *)(param_1 + 0xc0) + 0xb) = *(undefined1 *)(param_2 + 8);
        local_res10 = *(undefined2 **)(param_1 + 0xc0);
        *(byte *)((longlong)local_res10 + 3) = *(byte *)((longlong)local_res10 + 3) | 0x80;
      }
      iVar1 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)local_res10);
      if (iVar1 < 0) {
        Log(param_1,0x44535437,(longlong)iVar1,local_res10);
      }
      if (*(int *)(param_1 + 0x3b0) == 1) {
        *(undefined4 *)(param_1 + 0x3b0) = 0;
      }
      local_28 = 0;
    }
    else if ((*(char *)(param_1 + 0xe4) == '\x01') && (param_2 == *(undefined2 **)(param_1 + 0xc0)))
    {
      *(undefined1 *)((longlong)param_2 + 3) = 4;
      *(undefined1 *)(param_2 + 2) = 2;
      *(undefined4 *)(param_2 + 8) = 0;
      if (((*(uint *)(param_2 + 6) & 0x20) == 0) &&
         ((*(char *)((longlong)param_2 + 0xb) != '\0' && (*(longlong *)(param_2 + 0x10) != 0)))) {
        local_28 = DumpUsbStor_IssueRequestSense(param_1,param_2);
        if (local_28 < 0) {
          Log(param_1,0x44535438,(longlong)local_28,param_2);
        }
      }
      else {
        iVar1 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
        if (iVar1 < 0) {
          Log(param_1,0x44535439,(longlong)iVar1,param_2);
        }
        local_28 = -0x3ffffe7b;
      }
    }
    else {
      lVar2 = *(longlong *)(param_1 + 0xc0);
      *(undefined1 *)(lVar2 + 3) = 0xe;
      lVar6 = lVar2;
      iVar1 = DumpUsbStor_TranslateCDBComplete(param_1,lVar2);
      if (iVar1 < 0) {
        param_3 = (longlong)iVar1;
        lVar6 = 0x44535461;
        Log(param_1,0x44535461,param_3,lVar2);
        param_4 = lVar2;
      }
      iVar1 = DumpUsbStor_ResetDevice(param_1,lVar6,param_3,param_4);
      if (iVar1 < 0) {
        Log(param_1,0x44535462,(longlong)iVar1,0);
      }
      local_28 = -0x3ffffe7b;
    }
  }
  else {
    puVar7 = (undefined2 *)0x0;
    uVar3 = (ulonglong)*(byte *)((longlong)param_2 + 3);
    Log(param_1,0x44535431,uVar3,0);
    if (((*(uint *)(param_1 + 0x14) & 0xfffffff) == 4) && (*(uint *)(param_1 + 0x2d8) < 2)) {
      *(int *)(param_1 + 0x2d8) = *(int *)(param_1 + 0x2d8) + 1;
      local_28 = DumpUsbStor_BulkResetPipe(param_1,param_2,uVar3,puVar7);
      if (local_28 < 0) {
        lVar2 = (longlong)local_28;
        uVar4 = 0x44535432;
        puVar7 = param_2;
        Log(param_1,0x44535432,lVar2,param_2);
        iVar1 = DumpUsbStor_ResetDevice(param_1,uVar4,lVar2,puVar7);
        if (iVar1 < 0) {
          Log(param_1,0x44535433,(longlong)iVar1,0);
        }
        local_28 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
      }
    }
    else {
      puVar5 = param_2;
      iVar1 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
      if (iVar1 < 0) {
        uVar3 = (ulonglong)iVar1;
        puVar5 = (undefined2 *)0x44535434;
        puVar7 = param_2;
        Log(param_1,0x44535434,uVar3,param_2);
      }
      iVar1 = DumpUsbStor_ResetDevice(param_1,puVar5,uVar3,puVar7);
      if (iVar1 < 0) {
        Log(param_1,0x44535435,(longlong)iVar1,0);
      }
      local_28 = -0x3ffffe7b;
      *(undefined1 *)((longlong)param_2 + 3) = 0xe;
      Log(param_1,0x44535436,0xffffffffc0000185,(ulonglong)*(byte *)((longlong)param_2 + 3));
    }
  }
  return local_28;
}



===== DumpUsbStor_CswTransfer @ 1c0002140 =====

int DumpUsbStor_CswTransfer(longlong param_1,void *param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  ulong uVar3;
  int iVar4;
  
  lVar1 = *(longlong *)(param_1 + 8);
  puVar2 = *(undefined4 **)(lVar1 + 0x118);
  *puVar2 = 0x53425355;
  uVar3 = PtrToUlong(param_2);
  puVar2[1] = uVar3;
  puVar2[2] = 0;
  *(undefined1 *)(puVar2 + 3) = 0;
  iVar4 = DumpUsbStor_IssueBulkOrInterruptRequest
                    (param_1,(longlong)param_2,*(longlong *)(param_1 + 8) + 0x20,1,0xd,puVar2,
                     lVar1 + 0x120,DumpUsbStor_CswCompletion);
  return iVar4;
}



===== DumpUsbStor_DataCompletion @ 1c0002240 =====

int DumpUsbStor_DataCompletion(longlong param_1,void *param_2)

{
  int iVar1;
  ulonglong uVar2;
  void *pvVar3;
  void *pvVar4;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(char *)((longlong)param_2 + 3) == '\x01') {
    if (*(uint *)(param_1 + 0x34) < *(uint *)((longlong)param_2 + 0x10)) {
      *(undefined1 *)((longlong)param_2 + 3) = 0x12;
    }
    else {
      *(undefined1 *)((longlong)param_2 + 3) = 1;
    }
    if (*(uint *)(param_1 + 0x34) < *(uint *)((longlong)param_2 + 0x10)) {
      local_20 = *(undefined4 *)(param_1 + 0x34);
    }
    else {
      local_20 = *(undefined4 *)((longlong)param_2 + 0x10);
    }
    *(undefined4 *)((longlong)param_2 + 0x10) = local_20;
    local_28 = DumpUsbStor_CswTransfer(param_1,param_2);
    if (local_28 < 0) {
      Log(param_1,0x44444337,(longlong)local_28,param_2);
    }
  }
  else {
    pvVar4 = (void *)0x0;
    uVar2 = (ulonglong)*(byte *)((longlong)param_2 + 3);
    Log(param_1,0x44444331,uVar2,0);
    if ((*(uint *)(param_1 + 0x14) & 0xfffffff) == 4) {
      *(int *)(param_1 + 0x2d8) = *(int *)(param_1 + 0x2d8) + 1;
      if (*(uint *)(param_1 + 0x34) < *(uint *)((longlong)param_2 + 0x10)) {
        local_24 = *(undefined4 *)(param_1 + 0x34);
      }
      else {
        local_24 = *(undefined4 *)((longlong)param_2 + 0x10);
      }
      *(undefined4 *)((longlong)param_2 + 0x10) = local_24;
      *(undefined1 *)((longlong)param_2 + 3) = 0x12;
      local_28 = DumpUsbStor_BulkResetPipe(param_1,param_2,uVar2,pvVar4);
      if (local_28 < 0) {
        Log(param_1,0x44444332,(longlong)local_28,param_2);
        local_28 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
        if (local_28 < 0) {
          Log(param_1,0x44444333,(longlong)local_28,param_2);
        }
      }
    }
    else {
      pvVar3 = param_2;
      iVar1 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
      if (iVar1 < 0) {
        uVar2 = (ulonglong)iVar1;
        pvVar3 = (void *)0x44444334;
        pvVar4 = param_2;
        Log(param_1,0x44444334,uVar2,param_2);
      }
      iVar1 = DumpUsbStor_ResetDevice(param_1,pvVar3,uVar2,pvVar4);
      if (iVar1 < 0) {
        Log(param_1,0x44444335,(longlong)iVar1,0);
      }
      local_28 = -0x3ffffe7b;
      *(undefined1 *)((longlong)param_2 + 3) = 0xe;
      Log(param_1,0x44444336,0xffffffffc0000185,(ulonglong)*(byte *)((longlong)param_2 + 3));
    }
  }
  return local_28;
}



===== DumpUsbStor_DataTransfer @ 1c00024d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DumpUsbStor_DataTransfer(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_138 [32];
  uint local_e8;
  int local_e0;
  ulonglong local_d8;
  uint local_d0;
  undefined4 local_cc;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8 [20];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_138;
  local_cc = 0;
  for (local_e8 = 0; local_e8 < 0x14; local_e8 = local_e8 + 1) {
    local_b8[local_e8] = 0;
  }
  if ((*(uint *)(param_2 + 0xc) & 0xc0) == 0x40) {
    local_c8 = *(longlong *)(param_1 + 8) + 0x20;
    local_d0 = 3;
  }
  else {
    if ((*(uint *)(param_2 + 0xc) & 0xc0) != 0x80) {
      return 0xc000000d;
    }
    local_c8 = *(longlong *)(param_1 + 8) + 0x38;
    local_d0 = 0;
  }
  local_c0 = param_1 + 0x10;
  local_e0 = *(int *)(param_2 + 0x10);
  local_d8 = *(ulonglong *)(param_2 + 0x18);
  local_e8 = 0;
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x10);
  do {
    uVar2 = StorPortGetPhysicalAddress(param_1,param_2,local_d8,&local_cc);
    local_b8[local_e8] = uVar2;
    local_e0 = local_e0 - (((int)local_d8 + 0x1000U & 0xfffff000) - (int)local_d8);
    local_d8 = local_d8 + 0x1000 & 0xfffffffffffff000;
    local_e8 = local_e8 + 1;
    if (local_e0 < 1) break;
  } while (local_e8 < 0x14);
  if (local_e0 < 1) {
    iVar1 = DumpUsbStor_IssueBulkOrInterruptRequest
                      (param_1,param_2,local_c8,(ulonglong)local_d0,*(undefined4 *)(param_2 + 0x10),
                       *(undefined8 *)(param_2 + 0x18),local_b8,DumpUsbStor_DataCompletion);
    if (iVar1 < 0) {
      Log(param_1,0x44445431,(longlong)iVar1,param_2);
    }
    uVar2 = 0;
  }
  else {
    Log(param_1,0x44445430,0,param_2);
    uVar2 = 0x80000005;
  }
  return uVar2;
}



===== DumpUsbStor_DmaStarted @ 1c00027a0 =====

void DumpUsbStor_DmaStarted(void)

{
  return;
}



===== DumpUsbStor_FindAdapter @ 1c00027b0 =====

undefined4 DumpUsbStor_FindAdapter(undefined1 *param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  longlong in_stack_00000028;
  undefined4 local_18;
  
  local_18 = 1;
  puVar2 = param_1;
  for (lVar1 = 0x13a0; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(in_stack_00000028 + 0x40);
  if (**(short **)(param_1 + 8) == 0x130) {
    StorPortMarkDumpMemory(param_1,*(longlong *)(param_1 + 8) + 0xd8,0x58,0);
    StorPortMarkDumpMemory(param_1,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0xf0),0,0);
  }
  else {
    Log((longlong)param_1,0x44464131,(ulonglong)**(ushort **)(param_1 + 8),0);
    local_18 = 2;
  }
  return local_18;
}



===== DumpUsbStor_Initialize @ 1c00028a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool DumpUsbStor_Initialize(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (GlobalDmpUsbStorExt == 0) {
    puVar5 = (undefined1 *)(param_1 + 0x3b8);
    GlobalDmpUsbStorExt = param_1;
    for (lVar3 = 0xfe8; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  uVar7 = 0;
  uVar6 = 0;
  uVar4 = 0x44496e5f;
  Log(param_1,0x44496e5f,0,0);
  if ((*(longlong *)(lVar1 + 0xe8) != 0) &&
     (iVar2 = (**(code **)(lVar1 + 0xe8))(*(undefined8 *)(lVar1 + 0xe0)), iVar2 < 0)) {
    Log(param_1,0x44494631,(longlong)iVar2,*(undefined8 *)(lVar1 + 0xe0));
    return false;
  }
  iVar2 = DumpUsbStor_ResetDevice(param_1,uVar4,uVar6,uVar7);
  if (-1 >= iVar2) {
    Log(param_1,0x44494632,(longlong)iVar2,0);
  }
  return -1 < iVar2;
}



===== DumpUsbStor_Interrupt @ 1c00029d0 =====

undefined8 DumpUsbStor_Interrupt(void)

{
  return 1;
}



===== DumpUsbStor_IssueBulkOrInterruptRequest @ 1c00029f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DumpUsbStor_IssueBulkOrInterruptRequest
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
              undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined *param_8)

{
  longlong lVar1;
  int iVar2;
  undefined2 *puVar3;
  longlong lVar4;
  undefined2 *puVar5;
  
  lVar1 = *(longlong *)(param_1 + 8);
  puVar3 = (undefined2 *)(param_1 + 0x10);
  puVar5 = puVar3;
  for (lVar4 = 0x80; lVar4 != 0; lVar4 = lVar4 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined2 *)((longlong)puVar5 + 1);
  }
  *puVar3 = 0x80;
  *(undefined2 *)(param_1 + 0x12) = 9;
  *(undefined8 *)(param_1 + 0x28) = param_3;
  *(int *)(param_1 + 0x30) = (int)param_4;
  *(undefined4 *)(param_1 + 0x34) = param_5;
  *(undefined8 *)(param_1 + 0x38) = param_6;
  *(undefined8 *)(param_1 + 0x40) = 0;
  iVar2 = (**(code **)(lVar1 + 0xf0))(*(undefined8 *)(lVar1 + 0xe0),puVar3,param_7,param_4,0);
  if (iVar2 < 0) {
    *(undefined1 *)(param_2 + 3) = 4;
    Log(param_1,0x44424931,(longlong)iVar2,puVar3);
    Log(param_1,0x44424931,param_7,param_2);
  }
  else {
    *(undefined1 *)(param_2 + 3) = 1;
  }
  *(int *)(param_1 + 0x14) = iVar2;
  if (param_8 != (undefined *)0x0) {
    iVar2 = (*(code *)param_8)(param_1,param_2);
  }
  return iVar2;
}



===== DumpUsbStor_IssueRequestSense @ 1c0002b80 =====

int DumpUsbStor_IssueRequestSense(longlong param_1,undefined2 *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined2 *puVar3;
  
  puVar3 = param_2;
  for (lVar2 = 0x58; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined2 *)((longlong)puVar3 + 1);
  }
  *param_2 = 0x58;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined1 *)(param_2 + 5) = 0xc;
  *(undefined4 *)(param_2 + 6) = 0x160;
  *(uint *)(param_2 + 8) = (uint)*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xb);
  *(undefined8 *)(param_2 + 0xc) = *(undefined8 *)(*(longlong *)(param_1 + 0xc0) + 0x20);
  *(undefined1 *)(param_2 + 0x24) = 3;
  *(undefined1 *)(param_2 + 0x26) = *(undefined1 *)(*(longlong *)(param_1 + 0xc0) + 0xb);
  iVar1 = DumpUsbStor_CbwTransfer(param_1,param_2);
  return iVar1;
}



===== DumpUsbStor_ResetBus @ 1c0002c60 =====

undefined8 DumpUsbStor_ResetBus(void)

{
  return 1;
}



===== DumpUsbStor_ResetDevice @ 1c0002c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DumpUsbStor_ResetDevice
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  int local_38;
  undefined1 local_30 [2];
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 *local_28;
  longlong local_20;
  code *local_18;
  code *local_10;
  
  local_38 = -0x3fffffff;
  local_20 = *(longlong *)(param_1 + 8) + 0xd8;
  puVar2 = local_30;
  for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_28 = (undefined2 *)0x0;
  if ((*(int *)(param_1 + 0x3b0) == 0) && (*(longlong *)(local_20 + 0x18) != 0)) {
    *(int *)(param_1 + 0x3b0) = *(int *)(param_1 + 0x3b0) + 1;
    puVar2 = local_30;
    for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    local_30[1] = 0xff;
    local_30[0] = 0x21;
    uStack_2e = 0;
    uStack_2c = 0;
    uStack_2a = 0;
    local_28 = (undefined2 *)(param_1 + 0x10);
    puVar3 = local_28;
    for (lVar1 = 0x88; lVar1 != 0; lVar1 = lVar1 + -1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined2 *)((longlong)puVar3 + 1);
    }
    *local_28 = 0x88;
    *(undefined2 *)(param_1 + 0x12) = 8;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined8 *)(param_1 + 0x90) = 0xff21;
    local_18 = *(code **)(local_20 + 0x18);
    uVar4 = 0;
    local_38 = (*local_18)(*(undefined8 *)(local_20 + 8),local_28);
    if (local_38 < 0) {
      Log(param_1,0x44524434,(longlong)local_38,*(undefined8 *)(param_1 + 8));
    }
    else {
      StorPortStallExecution(50000);
      local_38 = DumpUsbStor_ResetPipe(param_1,*(longlong *)(param_1 + 8) + 0x20,uVar4,param_4);
      if (local_38 < 0) {
        Log(param_1,0x44524433,(longlong)local_38,*(undefined8 *)(param_1 + 8));
      }
      else {
        local_38 = DumpUsbStor_ResetPipe(param_1,*(longlong *)(param_1 + 8) + 0x38,uVar4,param_4);
        if (-1 < local_38) {
          Log(param_1,0x44524431,(longlong)local_38,*(undefined8 *)(param_1 + 8));
          return local_38;
        }
        Log(param_1,0x44524432,(longlong)local_38,*(undefined8 *)(param_1 + 8));
      }
    }
  }
  *(int *)(param_1 + 0x3b0) = *(int *)(param_1 + 0x3b0) + 1;
  if (*(longlong *)(local_20 + 0x30) != 0) {
    local_10 = *(code **)(local_20 + 0x30);
    local_38 = (*local_10)(*(undefined8 *)(local_20 + 8));
    if (local_38 < 0) {
      Log(param_1,0x44524435,(longlong)local_38,*(undefined8 *)(local_20 + 8));
    }
  }
  return local_38;
}



===== DumpUsbStor_ResetPipe @ 1c0002f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DumpUsbStor_ResetPipe(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(param_1 + 0x10);
  *puVar2 = 0x28;
  *(undefined2 *)(param_1 + 0x12) = 0x1e;
  *(undefined8 *)(param_1 + 0x28) = param_2;
  iVar1 = (**(code **)(*(longlong *)(param_1 + 8) + 0xf0))
                    (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0xe0),puVar2,0,param_4,0);
  if (iVar1 < 0) {
    Log(param_1,0x44525046,(longlong)iVar1,puVar2);
  }
  return iVar1;
}



===== DumpUsbStor_Setup @ 1c0003030 =====

int DumpUsbStor_Setup(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  undefined4 local_98;
  undefined4 local_90;
  
  puVar3 = &local_d8;
  for (lVar2 = 0xd0; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((longlong)puVar3 + 1);
  }
  puVar3 = &local_d8;
  for (lVar2 = 0xd0; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((longlong)puVar3 + 1);
  }
  local_d8 = 0xd0;
  local_d4 = 0xf;
  local_90 = 0x1000;
  local_d0 = DumpUsbStor_Initialize;
  local_c8 = DumpUsbStor_StartIo;
  local_c0 = DumpUsbStor_Interrupt;
  local_b8 = DumpUsbStor_FindAdapter;
  local_b0 = DumpUsbStor_ResetBus;
  local_a8 = DumpUsbStor_DmaStarted;
  local_a0 = DumpUsbStor_AdapterState;
  local_98 = 0x13a0;
  iVar1 = StorPortInitialize(param_1,param_2,&local_d8,0);
  if (iVar1 < 0) {
    Log(GlobalDmpUsbStorExt,0x44535346,(longlong)iVar1,param_1);
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xfe,9,1,(longlong)iVar1,GlobalDmpUsbStorExt);
  }
  return iVar1;
}



===== DumpUsbStor_StartIo @ 1c0003180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 DumpUsbStor_StartIo(longlong param_1,undefined1 *param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined1 local_36;
  int local_34;
  
  local_36 = 1;
  lVar2 = *(longlong *)(param_1 + 8);
  bVar4 = false;
  if ((param_2[2] == '\0') && (param_2[0x48] == '5')) {
    param_2[4] = 1;
    local_34 = DumpUsbStor_TranslateCDBComplete(param_1,(longlong)param_2);
    if (local_34 < 0) {
      Log(param_1,0x44534931,(longlong)local_34,param_2);
    }
  }
  else {
    if (param_2[2] == '\a') {
      cVar1 = param_2[7];
      uVar3 = *(undefined8 *)(param_2 + 0x38);
      puVar6 = param_2;
      for (lVar5 = 0x58; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      puVar6 = param_2 + 0x48;
      for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      param_2[2] = 0;
      *(undefined4 *)(param_2 + 0xc) = 0x80028;
      param_2[10] = 6;
      param_2[3] = 0;
      param_2[4] = 0;
      *(undefined8 *)(param_2 + 0x28) = 0;
      *(undefined4 *)(param_2 + 0x14) = 10;
      *(undefined8 *)(param_2 + 0x38) = uVar3;
      param_2[0x49] = param_2[0x49] & 0x1f | cVar1 << 5;
      param_2[0x48] = '\x1b';
      bVar4 = true;
    }
    *(undefined1 **)(param_1 + 0xc0) = param_2;
    local_34 = DumpUsbStor_CbwTransfer(param_1,param_2);
    if (local_34 < 0) {
      Log(param_1,0x44534932,(longlong)local_34,param_2);
      local_36 = 0;
    }
  }
  if ((bVar4) && ((**(code **)(lVar2 + 0x110))(*(undefined8 *)(lVar2 + 0xe0)), local_34 < 0)) {
    StorPortStallExecution(100000);
  }
  return local_36;
}



===== DumpUsbStor_TranslateCDBComplete @ 1c00033c0 =====

undefined4 DumpUsbStor_TranslateCDBComplete(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined4 local_18;
  
  local_18 = 0;
  if ((*(byte *)(param_2 + 3) & 0x3f) != 1) {
    uVar1 = DumpUsbStor_TranslateSrbStatus(param_2);
    local_18 = (undefined4)uVar1;
  }
  StorPortNotification(0,param_1,param_2);
  return local_18;
}



===== DumpUsbStor_TranslateSrbStatus @ 1c0003420 =====

undefined8 DumpUsbStor_TranslateSrbStatus(longlong param_1)

{
  undefined8 uVar1;
  
  switch(*(byte *)(param_1 + 3) & 0x3f) {
  case 8:
  case 0x11:
  case 0x20:
  case 0x21:
    uVar1 = 0xc00000c0;
    break;
  case 9:
  case 0xb:
  case 0xe:
    uVar1 = 0xc00000b5;
    break;
  case 10:
    uVar1 = 0xc000009d;
    break;
  default:
    uVar1 = 0xc0000185;
    break;
  case 0x12:
    uVar1 = 0x80000005;
    break;
  case 0x15:
  case 0x22:
    uVar1 = 0xc0000010;
  }
  return uVar1;
}



===== Log @ 1c00034a0 =====

void Log(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0x3c0 + (ulonglong)*(uint *)(param_1 + 0x3b8) * 0x20);
  *(uint *)(param_1 + 0x3b8) = (*(int *)(param_1 + 0x3b8) + 1U) % 0x7f;
  *puVar1 = param_2;
  *(undefined8 *)(puVar1 + 4) = param_3;
  *(undefined8 *)(puVar1 + 6) = param_4;
  return;
}



===== PtrToUlong @ 1c0003540 =====

ulong PtrToUlong(void *p)

{
  ulong local_res8;
  
  local_res8 = (ulong)p;
  return local_res8;
}



===== StorPortMarkDumpMemory @ 1c0003560 =====

void StorPortMarkDumpMemory
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  StorPortExtendedFunction(0x2d,param_1,param_2,param_3,param_4);
  return;
}



===== _guard_check_icall @ 1c00035c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c00035d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00035fc =====

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



===== __security_check_cookie @ 1c0003670 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00036b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00036e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00036e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003710 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== wil_UninitializeFeatureStaging @ 1c0009010 =====

void wil_UninitializeFeatureStaging(void)

{
  wil_details_UnregisterFeatureStagingChangeNotification();
  wil_details_UnregisterFeatureUsageProvider();
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== wil_details_BuildFeatureStateCacheFromDefaults @ 1c0009040 =====

void wil_details_BuildFeatureStateCacheFromDefaults(uint *param_1)

{
  longlong lVar1;
  uint *puVar2;
  
  puVar2 = param_1;
  for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (uint *)((longlong)puVar2 + 1);
  }
  *param_1 = *param_1 | 2;
  *param_1 = *param_1 | 4;
  *param_1 = *param_1 | 0x200;
  *param_1 = *param_1 & 0xfffffe7f;
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1c00090b0 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  longlong lVar1;
  uint *puVar2;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    wil_details_BuildFeatureStateCacheFromDefaults(param_3);
  }
  else if (param_1 == 0) {
    puVar2 = param_3;
    for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (uint *)((longlong)puVar2 + 1);
    }
    *param_3 = *param_3 | 2;
    *param_3 = *param_3 | 4;
    *param_3 = *param_3 | 0x200;
    *param_3 = *param_3 & 0xfffffe7f | (*(uint *)(param_2 + 4) >> 4 & 3) << 7;
    *param_3 = *param_3 & 0xfffff7ff | (*(uint *)(param_2 + 4) >> 6 & 1) << 0xb;
    *param_3 = *param_3 & 0xfffffbff | (*(uint *)(param_2 + 4) >> 7 & 1) << 10;
  }
  else if (param_1 == 0x117) {
    puVar2 = param_3;
    for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (uint *)((longlong)puVar2 + 1);
    }
    *param_3 = *param_3 | 2;
    *param_3 = *param_3 | 4;
    *param_3 = *param_3 | 0x200;
    *param_3 = *param_3 & 0xfffffe7f;
    *param_3 = *param_3 & 0xfffffbff | (*(uint *)(param_2 + 4) >> 7 & 1) << 10;
  }
  else {
    wil_details_BuildFeatureStateCacheFromDefaults(param_3);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1c0009270 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  wil_details_EvaluateFeatureDependencies_UpdateFeatureDesiredStates();
  wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates();
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c0009290 =====

undefined8
wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState(int *param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  uint *puVar3;
  uint local_18;
  undefined4 uStack_14;
  
  puVar3 = &local_18;
  for (lVar2 = 8; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (uint *)((longlong)puVar3 + 1);
  }
  local_18 = wil_atomic_uint32_load_relaxed(param_1);
  if ((local_18 >> 9 & 1) == 0) {
    uVar1 = CONCAT44(uStack_14,local_18);
  }
  else {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,local_18,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1c0009300 =====

undefined8
wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
          (int *param_1,uint param_2,longlong param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_28;
  undefined4 uStack_24;
  longlong *local_20;
  uint local_18 [2];
  ulonglong local_10;
  
  puVar4 = local_18;
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (uint *)((longlong)puVar4 + 1);
  }
  puVar4 = &local_28;
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (uint *)((longlong)puVar4 + 1);
  }
  local_38 = param_2 >> 6 & 1;
  if ((local_38 != 0) && (*(longlong *)(param_3 + 0x20) != 0)) {
    for (local_20 = *(longlong **)(param_3 + 0x20); (local_38 != 0 && (*local_20 != 0));
        local_20 = local_20 + 1) {
      if ((*(char *)(*local_20 + 0x1e) == '\0') && (*(char *)(*local_20 + 0x1d) == '\0')) {
        local_10 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                             (*(int **)*local_20,*local_20);
        if ((local_38 == 0) || ((local_10 & 1) == 0)) {
          local_30 = 0;
        }
        else {
          local_30 = 1;
        }
        local_38 = local_30;
      }
      else {
        if ((local_38 == 0) || (*(char *)(*local_20 + 0x1f) == '\0')) {
          local_34 = 0;
        }
        else {
          local_34 = 1;
        }
        local_38 = local_34;
      }
    }
  }
  local_18[0] = param_2;
  do {
    uVar2 = local_18[0] & 0xfffffffe;
    if ((local_18[0] & 1) != local_38) {
      uVar2 = local_18[0] & 0xffffffce;
    }
    local_28 = uVar2 & 0xfffffdff | local_38;
    bVar1 = wil_atomic_uint32_compare_exchange_relaxed(param_1,(int *)local_18,local_28);
  } while ((int)CONCAT71(extraout_var,bVar1) == 0);
  return CONCAT44(uStack_24,local_28);
}



===== wil_details_EvaluateFeatureDependencies_UpdateFeatureDesiredStates @ 1c00094d0 =====

void wil_details_EvaluateFeatureDependencies_UpdateFeatureDesiredStates(void)

{
  longlong lVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  undefined8 *local_28;
  uint local_20 [2];
  uint local_18 [2];
  undefined4 local_10 [2];
  
  puVar2 = local_20;
  for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (uint *)((longlong)puVar2 + 1);
  }
  puVar2 = local_18;
  for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (uint *)((longlong)puVar2 + 1);
  }
  for (local_28 = (undefined8 *)wil_details_FeatureDescriptors_First();
      local_28 != (undefined8 *)0x0;
      local_28 = (undefined8 *)wil_details_FeatureDescriptors_Next((longlong)local_28)) {
    local_20[0] = wil_atomic_uint32_load_relaxed((undefined4 *)*local_28);
    if ((local_20[0] >> 9 & 1) != 0) {
      if ((local_20[0] >> 7 & 3) == 0) {
        local_34 = (uint)(*(char *)((longlong)local_28 + 0x1f) != '\0');
        local_38 = local_34;
      }
      else {
        local_30 = (uint)((local_20[0] >> 7 & 3) == 2);
        local_38 = local_30;
      }
      local_2c = (uint)((local_20[0] >> 6 & 1) != local_38);
      local_18[0] = local_18[0] & 0xffffffbf | local_2c << 6;
      puVar3 = local_10;
      for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((longlong)puVar3 + 1);
      }
      local_10[0] = wil_atomic_uint32_fetch_xor_relaxed((uint *)*local_28,local_18[0]);
    }
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates @ 1c0009630 =====

void wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates(void)

{
  undefined8 *local_18;
  
  for (local_18 = (undefined8 *)wil_details_FeatureDescriptors_First();
      local_18 != (undefined8 *)0x0;
      local_18 = (undefined8 *)wil_details_FeatureDescriptors_Next((longlong)local_18)) {
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((int *)*local_18,(longlong)local_18);
  }
  return;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c0009680 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  uint local_18 [2];
  longlong local_10;
  
  if ((param_1 == 1) &&
     (iVar1 = wil_atomic_int32_exchange_release((undefined4 *)&g_wil_details_featureUsageCached,0),
     iVar1 != 0)) {
    local_10 = 0;
    for (local_10 = wil_details_FeatureDescriptors_First(); local_10 != 0;
        local_10 = wil_details_FeatureDescriptors_Next(local_10)) {
      puVar3 = local_18;
      for (lVar2 = 4; lVar2 != 0; lVar2 = lVar2 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (uint *)((longlong)puVar3 + 1);
      }
      local_18[0] = wil_atomic_uint32_load_relaxed(*(undefined4 **)(local_10 + 8));
      if ((local_18[0] & 1) != 0) {
        wil_details_RecordCachedUsage
                  (*(undefined4 *)(local_10 + 0x18),*(uint **)(local_10 + 8),
                   wil_details_RecordFeatureUsageCallback);
      }
    }
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 1c0009740 =====

void wil_details_RecordFeatureUsageCallback(undefined8 param_1,undefined8 param_2)

{
  RtlRecordFeatureUsage(param_1,param_2);
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c0009770 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_RegisterFeatureStagingChangeNotification @ 1c0009790 =====

int wil_details_RegisterFeatureStagingChangeNotification(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = RtlRegisterFeatureConfigurationChangeNotification
                    (param_1,0,param_2,&g_wil_details_featureChangeNotification,0);
  if (iVar1 != 0) {
    g_wil_details_featureChangeNotification = 0;
  }
  return iVar1;
}



===== wil_details_RegisterFeatureUsageProvider @ 1c00097f0 =====

int wil_details_RegisterFeatureUsageProvider(void)

{
  int iVar1;
  undefined8 in_R9;
  undefined4 uVar2;
  
  uVar2 = 0;
  wil_atomic_pointer_store_relaxed
            ((undefined8 *)&g_wil_details_recordFeatureUsage,wil_details_RecordFeatureUsageReporting
            );
  iVar1 = RtlRegisterFeatureUsageProvider
                    (wil_details_OnFeatureUsageProviderFlushNotification,0,
                     &g_wil_details_featureUsageProvider,in_R9,uVar2);
  if (iVar1 != 0) {
    g_wil_details_featureUsageProvider = 0;
  }
  return iVar1;
}



===== wil_details_ShouldRegisterFeatureStagingChangeNotification @ 1c0009860 =====

undefined8 wil_details_ShouldRegisterFeatureStagingChangeNotification(void)

{
  longlong local_18;
  
  local_18 = wil_details_FeatureDescriptors_First();
  while( true ) {
    if (local_18 == 0) {
      return 0;
    }
    if (((*(char *)(local_18 + 0x1d) == '\0') && (*(char *)(local_18 + 0x1e) == '\0')) &&
       (*(char *)(local_18 + 0x1c) == '\0')) break;
    local_18 = wil_details_FeatureDescriptors_Next(local_18);
  }
  return 1;
}



===== wil_details_UnregisterFeatureStagingChangeNotification @ 1c00098d0 =====

void wil_details_UnregisterFeatureStagingChangeNotification(void)

{
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification(g_wil_details_featureChangeNotification);
    g_wil_details_featureChangeNotification = 0;
  }
  return;
}



===== wil_details_UnregisterFeatureUsageProvider @ 1c0009910 =====

void wil_details_UnregisterFeatureUsageProvider(void)

{
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider(g_wil_details_featureUsageProvider);
    g_wil_details_featureUsageProvider = 0;
  }
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1c0009950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  longlong lVar1;
  undefined1 *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined1 auStack_88 [32];
  undefined4 local_68 [2];
  undefined8 *local_60;
  int local_58;
  uint local_50 [2];
  uint local_48 [2];
  uint local_40 [2];
  undefined8 local_38;
  undefined4 local_30 [2];
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_60 = (undefined8 *)0x0;
  local_58 = 0;
  for (local_60 = (undefined8 *)wil_details_FeatureDescriptors_First();
      local_60 != (undefined8 *)0x0;
      local_60 = (undefined8 *)wil_details_FeatureDescriptors_Next((longlong)local_60)) {
    if (((*(char *)((longlong)local_60 + 0x1d) == '\0') &&
        (*(char *)((longlong)local_60 + 0x1e) == '\0')) &&
       (*(char *)((longlong)local_60 + 0x1c) == '\0')) {
      puVar2 = local_28;
      for (lVar1 = 0xc; lVar1 != 0; lVar1 = lVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      local_38 = 0;
      local_58 = RtlQueryFeatureConfiguration(*(undefined4 *)(local_60 + 3),1,&local_38,local_28);
      puVar3 = local_50;
      for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (uint *)((longlong)puVar3 + 1);
      }
      wil_details_BuildFeatureStateCacheFromQueryResults(local_58,(longlong)local_28,local_50);
      puVar3 = local_48;
      for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (uint *)((longlong)puVar3 + 1);
      }
      local_48[0] = wil_atomic_uint32_load_relaxed((undefined4 *)*local_60);
      puVar4 = local_68;
      for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((longlong)puVar4 + 1);
      }
      local_68[0] = 0xf80;
      puVar3 = local_40;
      for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (uint *)((longlong)puVar3 + 1);
      }
      local_40[0] = (local_48[0] ^ local_50[0]) & 0xf80;
      puVar4 = local_30;
      for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((longlong)puVar4 + 1);
      }
      local_30[0] = wil_atomic_uint32_fetch_xor_relaxed((uint *)*local_60,local_40[0]);
    }
  }
  return;
}



===== entry @ 1c000b010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000b044 =====

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



===== wil_InitializeFeatureStaging @ 1c000b080 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_10 [2];
  
  bVar1 = false;
  local_10[0] = 0;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_10[0] = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    uVar3 = wil_details_ShouldRegisterFeatureStagingChangeNotification();
    if (((int)uVar3 != 0) &&
       (iVar2 = wil_details_RegisterFeatureStagingChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,local_10), iVar2 == 0)
       ) {
      bVar1 = true;
    }
    iVar2 = wil_details_RegisterFeatureUsageProvider();
    if (iVar2 == 0) {
      bVar1 = true;
    }
    if (bVar1) {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c000b140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined8 *puVar3;
  undefined1 auStack_68 [32];
  undefined8 *local_48;
  int local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = (undefined8 *)0x0;
  local_40 = 0;
  local_48 = (undefined8 *)wil_details_FeatureDescriptors_First();
  while( true ) {
    if (local_48 == (undefined8 *)0x0) {
      return;
    }
    puVar2 = local_28;
    for (lVar1 = 0xc; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    local_30 = 0;
    puVar3 = &local_38;
    for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined8 *)((longlong)puVar3 + 1);
    }
    if ((*(char *)((longlong)local_48 + 0x1d) == '\0') &&
       (*(char *)((longlong)local_48 + 0x1e) == '\0')) {
      if ((*(char *)((longlong)local_48 + 0x1c) == '\x03') ||
         (*(char *)((longlong)local_48 + 0x1c) == '\x02')) {
        local_3c = 0;
      }
      else {
        local_3c = 1;
      }
      local_40 = RtlQueryFeatureConfiguration
                           (*(undefined4 *)(local_48 + 3),local_3c,&local_30,local_28);
    }
    else {
      local_40 = -0x3ffffddb;
    }
    if (local_40 == -0x7fffffde) break;
    wil_details_BuildFeatureStateCacheFromQueryResults
              (local_40,(longlong)local_28,(uint *)&local_38);
    *(undefined8 *)*local_48 = local_38;
    local_48 = (undefined8 *)wil_details_FeatureDescriptors_Next((longlong)local_48);
  }
  wil_details_PopulateInitialConfiguredFeatureStatesWithDefaults(local_48);
  return;
}



===== wil_details_PopulateInitialConfiguredFeatureStatesWithDefaults @ 1c000b290 =====

void wil_details_PopulateInitialConfiguredFeatureStatesWithDefaults(undefined8 *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *local_18;
  undefined8 local_10;
  
  puVar2 = &local_10;
  for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined8 *)((longlong)puVar2 + 1);
  }
  wil_details_BuildFeatureStateCacheFromDefaults((uint *)&local_10);
  for (local_18 = param_1; local_18 != (undefined8 *)0x0;
      local_18 = (undefined8 *)wil_details_FeatureDescriptors_Next((longlong)local_18)) {
    *(undefined8 *)*local_18 = local_10;
  }
  return;
}


