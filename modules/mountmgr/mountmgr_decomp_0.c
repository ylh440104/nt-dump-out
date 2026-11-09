
===== MountMgrCleanup @ 140001010 =====

undefined8 MountMgrCleanup(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  local_res8[0] = 0;
  IoAcquireCancelSpinLock(local_res8);
  plVar4 = (longlong *)(lVar1 + 0x98);
  while (plVar3 = (longlong *)*plVar4, plVar3 != plVar4) {
    while (*(longlong *)(plVar3[2] + 0x30) != lVar2) {
      plVar3 = (longlong *)*plVar3;
      if (plVar3 == plVar4) goto LAB_14000105f;
    }
    *(undefined1 *)((longlong)plVar3 + -100) = 1;
    *(undefined1 *)((longlong)plVar3 + -99) = local_res8[0];
    plVar3[-8] = 0;
    MountMgrCancel(param_1,(longlong)(plVar3 + -0x15));
    IoAcquireCancelSpinLock(local_res8);
  }
LAB_14000105f:
  IoReleaseCancelSpinLock(local_res8[0]);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== WorkerThread @ 1400010f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WorkerThread(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined8 local_res10 [3];
  undefined8 uStack_b0;
  undefined1 auStack_a8 [32];
  undefined *local_88 [8];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_88[5] = (undefined *)0x30;
  local_48 = 0x240;
  local_88[2] = (undefined *)0x0;
  local_88[3] = (undefined *)0x0;
  local_88[4] = (undefined *)0x0;
  local_88[6] = (undefined *)0x0;
  local_88[7] = &DAT_1400090a8;
  local_res10[0] = 0;
  local_40 = 0;
  uStack_38 = 0;
  KeInitializeEvent(local_88 + 2,0,0);
  puVar10 = auStack_a8;
  local_res10[1] = 0xffffffffff676980;
  uVar11 = 0;
  do {
    puVar9 = auStack_a8;
    if (gUnloading != 0) break;
    iVar8 = ZwOpenEvent(local_res10,0x1f0003,local_88 + 5);
    if (-1 < iVar8) {
      puVar9 = auStack_a8;
      if (uVar11 < 1000) goto LAB_1400012b0;
      break;
    }
    local_88[0] = (undefined *)(local_res10 + 1);
    KeWaitForSingleObject(local_88 + 2,0,0,0);
    uVar11 = uVar11 + 1;
    puVar9 = auStack_a8;
  } while (uVar11 < 1000);
  do {
    plVar1 = (longlong *)(param_2 + 200);
    LOCK();
    *(undefined4 *)(param_2 + 0x118) = 1;
    UNLOCK();
    while( true ) {
      *(undefined8 *)(puVar9 + 0x20) = 0;
      *(undefined8 *)(puVar9 + -8) = 0x1400011ce;
      KeWaitForSingleObject(param_2 + 0xd8,0,0,0);
      *(undefined8 *)(puVar9 + -8) = 0x1400011e1;
      uVar7 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x100);
      plVar3 = (longlong *)*plVar1;
      if (plVar3 == plVar1) {
        *(undefined8 *)(puVar9 + -8) = 0x140001203;
        KeReleaseSpinLock(param_2 + 0x100,uVar7);
        LOCK();
        *(int *)(param_2 + 0xf8) = *(int *)(param_2 + 0xf8) + -1;
        UNLOCK();
        *(undefined8 *)(puVar9 + -8) = 0x140001222;
        KeSetEvent(&gUnloadEvent,0,0);
        return;
      }
      if (((longlong *)plVar3[1] != plVar1) ||
         (lVar5 = *plVar3, (longlong *)*(longlong *)(lVar5 + 8) != plVar3)) break;
      *plVar1 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar1;
      *(undefined8 *)(puVar9 + -8) = 0x140001241;
      KeReleaseSpinLock(param_2 + 0x100);
      pcVar6 = (code *)plVar3[3];
      uVar4 = plVar3[4];
      *(undefined8 *)(puVar9 + -8) = 0x140001253;
      (*pcVar6)(uVar4);
      uVar4 = plVar3[2];
      *(undefined8 *)(puVar9 + -8) = 0x14000125e;
      IoFreeWorkItem(uVar4);
      *(undefined8 *)(puVar9 + -8) = 0x14000126f;
      ExFreePoolWithTag(plVar3);
      LOCK();
      piVar2 = (int *)(param_2 + 0xf8);
      iVar8 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar8 + -1 < 0) {
        return;
      }
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar10 = puVar9 + 8;
LAB_1400012b0:
    do {
      *(undefined8 *)(puVar10 + -8) = 0x1400012c9;
      iVar8 = ZwWaitForSingleObject(*(undefined8 *)(puVar10 + 0xb8));
      if (iVar8 != 0x102) break;
    } while (gUnloading == 0);
    *(undefined8 *)(puVar10 + -8) = 0x1400012e4;
    ZwClose(*(undefined8 *)(puVar10 + 0xb8));
    puVar9 = puVar10;
  } while( true );
}



===== QueueWorkItem @ 140001350 =====

undefined8 QueueWorkItem(longlong param_1,longlong *param_2,longlong param_3)

{
  int *piVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  param_2[4] = param_3;
  LOCK();
  piVar1 = (int *)(param_1 + 0xf8);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*piVar1 == 0) {
    IoQueueWorkItem(param_2[2],WorkerThread,1,param_1);
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  plVar2 = *(longlong **)(param_1 + 0xd0);
  if (*plVar2 == param_1 + 200) {
    *param_2 = param_1 + 200;
    param_2[1] = (longlong)plVar2;
    *plVar2 = (longlong)param_2;
    *(longlong **)(param_1 + 0xd0) = param_2;
    KeReleaseSpinLock(param_1 + 0x100,uVar4);
    KeReleaseSemaphore(param_1 + 0xd8,0,1);
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar5 = (*pcVar3)();
  return uVar5;
}



===== SendOnlineNotificationWorker @ 140001420 =====

void SendOnlineNotificationWorker(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 uVar7;
  
  lVar3 = *(longlong *)(param_1 + 0x20);
  SendOnlineNotification(param_1 + 0x28,'\x01');
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x100);
  piVar1 = (int *)(lVar3 + 0x134);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    KeSetEvent(lVar3 + 0x138,0,0);
  }
  plVar2 = (longlong *)(lVar3 + 0x120);
  plVar4 = (longlong *)*plVar2;
  if (plVar4 == plVar2) {
    *(undefined1 *)(lVar3 + 0x130) = 0;
    KeReleaseSpinLock(lVar3 + 0x100,uVar7);
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
    ExFreePoolWithTag(param_1,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x167);
    }
  }
  else {
    if (((longlong *)plVar4[1] != plVar2) || (lVar5 = *plVar4, *(longlong **)(lVar5 + 8) != plVar4))
    {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    *plVar2 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar2;
    KeReleaseSpinLock(lVar3 + 0x100,uVar7);
    *plVar4 = 0;
    plVar4[1] = 0;
    ExQueueWorkItem(plVar4,1);
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== PostOnlineNotification @ 1400015a0 =====

void PostOnlineNotification(longlong param_1,short *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 uVar4;
  short sVar5;
  longlong *plVar6;
  void *_Dst;
  longlong *plVar7;
  undefined2 uVar8;
  undefined1 *puVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar6 = (longlong *)ExAllocatePool2(0x42,0x38,0x41746e4d);
  if (plVar6 == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x168);
    }
  }
  else {
    plVar6[3] = (longlong)plVar6;
    plVar6[2] = (longlong)SendOnlineNotificationWorker;
    *plVar6 = 0;
    plVar6[4] = param_1;
    sVar5 = *param_2;
    *(short *)(plVar6 + 5) = sVar5;
    sVar5 = sVar5 + 2;
    *(short *)((longlong)plVar6 + 0x2a) = sVar5;
    _Dst = (void *)ExAllocatePool2(0x42,sVar5,0x41746e4d);
    plVar6[6] = (longlong)_Dst;
    if (_Dst == (void *)0x0) {
      ExFreePoolWithTag(plVar6,0);
      puVar9 = auStack_28;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return;
      }
      uVar8 = 0x169;
    }
    else {
      memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)*(ushort *)(plVar6 + 5));
      lVar1 = param_1 + 0x100;
      *(undefined2 *)(plVar6[6] + (ulonglong)(*(ushort *)(plVar6 + 5) >> 1) * 2) = 0;
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
      puVar9 = auStack_28;
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
      if (*(char *)(param_1 + 0x130) == '\0') {
        *(undefined1 *)(param_1 + 0x130) = 1;
        ExQueueWorkItem(plVar6,1);
        KeReleaseSpinLock(lVar1,uVar4);
        puVar9 = auStack_28;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return;
        }
        uVar8 = 0x16a;
      }
      else {
        plVar7 = *(longlong **)(param_1 + 0x128);
        if (*plVar7 != param_1 + 0x120) {
          pcVar3 = (code *)swi(0x29);
          plVar7 = (longlong *)(*pcVar3)(3);
          puVar9 = auStack_20;
        }
        *plVar6 = param_1 + 0x120;
        plVar6[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar6;
        *(longlong **)(param_1 + 0x128) = plVar6;
        *(undefined8 *)(puVar9 + -8) = 0x140001766;
        KeReleaseSpinLock(lVar1,uVar4);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return;
        }
        uVar8 = 0x16b;
      }
    }
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar9 + -8) = 0x140001799;
    WPP_SF_(uVar2,uVar8);
  }
  return;
}



===== MountMgrChangeNotify @ 1400017c0 =====

undefined8 MountMgrChangeNotify(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 local_res10 [24];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res10[0] = 0;
  if ((*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 4) ||
     (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 4)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16c,param_3,0xc000000d);
    }
    uVar3 = 0xc000000d;
  }
  else {
    if (**(int **)(param_2 + 0x18) != *(int *)(param_1 + 0xa8)) {
      **(int **)(param_2 + 0x18) = *(int *)(param_1 + 0xa8);
      *(undefined8 *)(param_2 + 0x38) = 4;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16d,param_3,0);
      }
      return 0;
    }
    IoAcquireCancelSpinLock(local_res10);
    puVar6 = auStack_28;
    if (*(char *)(param_2 + 0x44) == '\0') {
      plVar4 = (longlong *)(param_2 + 0xa8);
      plVar5 = *(longlong **)(param_1 + 0xa0);
      if (*plVar5 != param_1 + 0x98) {
        plVar5 = (longlong *)0x3;
        pcVar2 = (code *)swi(0x29);
        plVar4 = (longlong *)(*pcVar2)();
        puVar6 = auStack_20;
      }
      plVar4[1] = (longlong)plVar5;
      *plVar4 = param_1 + 0x98;
      *plVar5 = (longlong)plVar4;
      *(longlong **)(param_1 + 0xa0) = plVar4;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      LOCK();
      *(code **)(param_2 + 0x68) = MountMgrCancel;
      UNLOCK();
      *(undefined8 *)(puVar6 + -8) = 0x1400018f5;
      IoReleaseCancelSpinLock(puVar6[0x38]);
      uVar3 = 0x103;
    }
    else {
      IoReleaseCancelSpinLock(local_res10[0]);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16e,param_3,0xc0000120);
      }
      uVar3 = 0xc0000120;
    }
  }
  return uVar3;
}



===== WPP_SF_LL @ 140001950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x163,local_res20,4,
             &param_5,4,0);
  return;
}



===== MountMgrNotify @ 1400019b0 =====

void MountMgrNotify(longlong param_1)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  longlong ****pppplVar5;
  undefined1 local_res8 [32];
  longlong ****local_18;
  longlong ****local_10;
  
  *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + 1;
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  local_res8[0] = 0;
  IoAcquireCancelSpinLock(local_res8);
  pppplVar1 = (longlong ****)(param_1 + 0x98);
  while (pppplVar2 = (longlong ****)*pppplVar1, pppplVar2 != pppplVar1) {
    if (((longlong ****)pppplVar2[1] != pppplVar1) ||
       (ppplVar3 = *pppplVar2, (longlong ****)ppplVar3[1] != pppplVar2)) goto LAB_140001ab2;
    *pppplVar1 = ppplVar3;
    ppplVar3[1] = (longlong **)pppplVar1;
    LOCK();
    pppplVar2[-8] = (longlong ***)0x0;
    UNLOCK();
    if ((longlong *****)*local_10 != &local_18) goto LAB_140001ab2;
    pppplVar2[1] = (longlong ***)local_10;
    *pppplVar2 = (longlong ***)&local_18;
    *local_10 = (longlong ***)pppplVar2;
    local_10 = pppplVar2;
  }
  IoReleaseCancelSpinLock(local_res8[0]);
  while( true ) {
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar1 = (longlong ****)*local_18, (longlong ****)pppplVar1[1] != local_18)) break;
    pppplVar1[1] = (longlong ***)&local_18;
    pppplVar5 = local_18 + -0x15;
    *(undefined4 *)local_18[-0x12] = *(undefined4 *)(param_1 + 0xa8);
    pppplVar2 = local_18 + -0xe;
    local_18 = pppplVar1;
    *pppplVar2 = (longlong ***)0x4;
    IofCompleteRequest(pppplVar5,0);
  }
LAB_140001ab2:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== WPP_SF_L @ 140001ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_ @ 140001b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2)

{
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,param_2,0);
  return;
}



===== __report_gsfailure @ 140001b60 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== Feature_1006081336__private_IsEnabledDeviceUsageNoInline @ 140001b70 =====

ulonglong Feature_1006081336__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1006081336__private_featureState;
  if ((Feature_1006081336__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1006081336__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1006081336__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1006081336__private_IsEnabledFallback @ 140001ba8 =====

void Feature_1006081336__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1006081336__private_descriptor);
  return;
}



===== Feature_1610585402__private_IsEnabledDeviceUsageNoInline @ 140001bc4 =====

ulonglong Feature_1610585402__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1610585402__private_featureState;
  if ((Feature_1610585402__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1610585402__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1610585402__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1610585402__private_IsEnabledFallback @ 140001bfc =====

void Feature_1610585402__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== Feature_3131020603__private_IsEnabledDeviceUsageNoInline @ 140001c18 =====

ulonglong Feature_3131020603__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3131020603__private_featureState;
  if ((Feature_3131020603__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3131020603__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3131020603__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3131020603__private_IsEnabledFallback @ 140001c50 =====

void Feature_3131020603__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3131020603__private_descriptor);
  return;
}



===== MountMgrCancel @ 140001c70 =====

void MountMgrCancel(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    IoReleaseCancelSpinLock
              (CONCAT71((int7)((ulonglong)plVar3 >> 8),*(undefined1 *)(param_2 + 0x45)));
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,0);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== MountMgrFreeSiloDeviceExtension @ 140001cdc =====

void MountMgrFreeSiloDeviceExtension(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x110) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x110),0);
      *(undefined8 *)(param_1 + 0x110) = 0;
    }
    local_18 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar5 = 0;
    KeWaitForSingleObject(param_1 + 0x38,0);
    if (((*(longlong **)(param_1 + 0x20) != (longlong *)(param_1 + 0x20)) &&
        ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar5 = 0x172;
      uVar8 = 0xc0000184;
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x172,uVar7,0xc0000184);
    }
    puVar6 = auStack_38;
    plVar1 = (longlong *)(param_1 + 0x10);
    while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_30;
        break;
      }
      *plVar1 = lVar3;
      uVar5 = CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
      *(longlong **)(lVar3 + 8) = plVar1;
      MountMgrFreeMountedDeviceInfo((longlong)plVar2,uVar5,uVar7,uVar8);
    }
    if (((*(longlong **)(param_1 + 0xb0) != (longlong *)(param_1 + 0xb0)) &&
        ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar6 + -8) = 0x140001dd8;
      WPP_SF_L(uVar5,0x173,uVar7,0xc0000184);
    }
    *(undefined8 *)(puVar6 + -8) = 0x140001de5;
    KeReleaseMutex(param_1 + 0x38,0);
  }
  return;
}



===== MountMgrInitSiloDeviceExtension @ 140001e08 =====

undefined8
MountMgrInitSiloDeviceExtension(longlong param_1,longlong param_2,longlong param_3,ushort *param_4)

{
  longlong *plVar1;
  ushort uVar2;
  longlong *_Dst;
  short sVar3;
  void *_Dst_00;
  undefined8 uVar4;
  
  _Dst = *(longlong **)(param_2 + 0x40);
  memset(_Dst,0,0x178);
  *_Dst = param_2;
  plVar1 = _Dst + 2;
  _Dst[1] = param_1;
  _Dst[3] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = _Dst + 4;
  _Dst[5] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  KeInitializeMutex(_Dst + 7,0);
  KeInitializeSemaphore(_Dst + 0xe,1,1);
  plVar1 = _Dst + 0x13;
  _Dst[0x14] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  *(undefined4 *)(_Dst + 0x15) = 1;
  plVar1 = _Dst + 0x16;
  _Dst[0x17] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = _Dst + 0x19;
  _Dst[0x1a] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  KeInitializeSemaphore(_Dst + 0x1b,0,0x7fffffff);
  *(undefined4 *)(_Dst + 0x1f) = 0xffffffff;
  KeInitializeSpinLock(_Dst + 0x20);
  plVar1 = _Dst + 0x24;
  _Dst[0x25] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  *(undefined4 *)((longlong)_Dst + 0x134) = 1;
  KeInitializeEvent(_Dst + 0x2b,0,0);
  uVar2 = *param_4;
  *(ushort *)(_Dst + 0x21) = uVar2;
  sVar3 = uVar2 + 2;
  *(short *)((longlong)_Dst + 0x10a) = sVar3;
  _Dst_00 = (void *)ExAllocatePool2(0x102,sVar3,0x41746e4d);
  _Dst[0x22] = (longlong)_Dst_00;
  if (_Dst_00 == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x171);
    }
    uVar4 = 0xc000009a;
  }
  else {
    memmove(_Dst_00,*(void **)(param_4 + 4),(ulonglong)*param_4);
    *(undefined2 *)(_Dst[0x22] + (ulonglong)(*param_4 >> 1) * 2) = 0;
    uVar4 = 0;
    _Dst[0x2a] = 1;
    _Dst[0x2e] = param_3;
  }
  return uVar4;
}



===== MountMgrSiloArrival @ 140001fdc =====

ulonglong MountMgrSiloArrival(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  code *pcVar7;
  longlong local_res8;
  longlong local_res10;
  longlong *local_res18;
  longlong local_res20;
  undefined4 uVar8;
  ulonglong uVar9;
  ushort local_38 [8];
  
  uVar4 = 0;
  local_res10 = 0;
  local_res8 = 0;
  bVar1 = false;
  local_res18 = (longlong *)0x0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  if ((*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 8) ||
     (**(longlong **)(param_2 + 0x18) == 0)) {
    return 0xc000000d;
  }
  uVar9 = 0;
  local_res20 = 0;
  plVar6 = &local_res20;
  uVar3 = ObReferenceObjectByHandle
                    (**(longlong **)(param_2 + 0x18),2,*(undefined8 *)PsJobType_exref,
                     *(undefined1 *)(param_2 + 0x40),plVar6,0);
  lVar2 = local_res20;
  uVar8 = (undefined4)((ulonglong)plVar6 >> 0x20);
  uVar5 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
LAB_1400021f1:
    if (local_res8 != 0) {
      MountMgrFreeSiloDeviceExtension(*(longlong *)(local_res8 + 0x40));
      IoDeleteDevice(local_res8);
    }
    if (!bVar1) goto LAB_140002227;
  }
  else {
    uVar3 = PsGetJobSilo(local_res20,&local_res10);
    uVar5 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_1400021f1;
    uVar4 = PsAttachSiloToCurrentThread(local_res10);
    bVar1 = true;
    RtlCreateRegistryKey(0,L"\\Registry\\Machine\\System\\MountedDevices");
    uVar3 = IoCreateDevice(*(undefined8 *)(gDeviceObject + 8),0x178,&DAT_140009000,0x12,
                           CONCAT44(uVar8,0x100),uVar9 & 0xffffffffffffff00,&local_res8);
    uVar5 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      RtlInitUnicodeString(local_38,L"\\Registry\\Machine\\System\\MountedDevices");
      uVar9 = MountMgrInitSiloDeviceExtension
                        (*(longlong *)(gDeviceObject + 8),local_res8,local_res10,local_38);
      uVar5 = uVar9 & 0xffffffff;
      if (-1 < (int)uVar9) {
        pcVar7 = MountMgrSiloContextCleanupCallback;
        uVar3 = PsCreateSiloContext(local_res10,8,1,MountMgrSiloContextCleanupCallback,&local_res18)
        ;
        uVar5 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          *local_res18 = local_res8;
          plVar6 = local_res18;
          uVar3 = PsInsertPermanentSiloContext(local_res10,gSiloSlot);
          uVar5 = (ulonglong)uVar3;
          *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) & 0xffffff7f;
          local_res8 = 0;
          PsDereferenceSiloContext(local_res18);
          if (-1 < (int)uVar3) {
            GlobalCreateSymbolicLink
                      ((undefined1 (*) [16])&DAT_140009078,(undefined8 *)&DAT_140009000,plVar6,
                       pcVar7);
          }
        }
      }
      goto LAB_1400021f1;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x170);
    }
    local_res8 = 0;
  }
  PsDetachSiloFromCurrentThread(uVar4);
LAB_140002227:
  if (lVar2 != 0) {
    ObfDereferenceObject(lVar2);
  }
  return uVar5;
}



===== MountMgrSiloContextCleanupCallback @ 140002250 =====

void MountMgrSiloContextCleanupCallback(longlong *param_1)

{
  if (*param_1 != 0) {
    MountMgrFreeSiloDeviceExtension(*(longlong *)(*param_1 + 0x40));
    IoDeleteDevice(*param_1);
  }
  return;
}



===== RtlUnicodeStringValidateEx @ 140002288 =====

undefined8 RtlUnicodeStringValidateEx(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if ((param_1 != (ushort *)0x0) &&
     (((((uVar1 = *param_1, (uVar1 & 1) != 0 || (uVar2 = param_1[1], (uVar2 & 1) != 0)) ||
        (uVar2 < uVar1)) || (uVar2 == 0xffff)) ||
      ((*(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))))) {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== WPP_SF_LS @ 1400022d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0xf,local_res20,4,param_5
             ,lVar1,0);
  return;
}



===== WPP_SF_LSsd @ 14000236c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LSsd(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *in_stack_00000028;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined4 local_18 [4];
  
  lVar1 = -1;
  local_18[0] = 0;
  if (in_stack_00000030 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (in_stack_00000030[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  if (in_stack_00000028 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x68,local_18,4,
             in_stack_00000028,lVar1,in_stack_00000030,lVar3,&uStack0000000000000038,4,0);
  return;
}



===== WPP_SF_LsL @ 14000245c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LsL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               char *param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  
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
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x164,local_res20,4,
             param_5,lVar2,&param_6,4,0);
  return;
}



===== WPP_SF_SL @ 140002500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SL(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
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
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0xb3,param_4,lVar1,
             &param_5,4,0);
  return;
}



===== WPP_SF_Si @ 140002590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Si(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
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
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x158,param_4,lVar1,
             &param_5,8,0);
  return;
}



===== WPP_SF_Ss @ 140002620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Ss(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = -1;
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x155,param_4,lVar1,
             param_5,lVar3,0);
  return;
}



===== WPP_SF_ddL @ 1400026d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x33,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_iSsdsssssdiDDDD @ 14000273c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iSsdsssssdiDDDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,char *param_6,undefined1 param_7,char *param_8,char *param_9,
               char *param_10,char *param_11,char *param_12,undefined1 param_13,undefined1 param_14,
               undefined1 param_15,undefined1 param_16,undefined1 param_17,undefined1 param_18)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  char *pcVar6;
  char *pcVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  char *pcVar11;
  char *pcVar12;
  undefined8 local_res20;
  
  lVar1 = -1;
  lVar2 = 5;
  if (param_12 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_12[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  if (param_12 == (char *)0x0) {
    param_12 = "NULL";
  }
  if (param_11 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar10 = -1;
    do {
      lVar4 = lVar10;
      lVar10 = lVar4 + 1;
    } while (param_11[lVar10] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar12 = param_11;
  if (param_11 == (char *)0x0) {
    pcVar12 = "NULL";
  }
  if (param_10 == (char *)0x0) {
    lVar10 = 5;
  }
  else {
    lVar9 = -1;
    do {
      lVar10 = lVar9;
      lVar9 = lVar10 + 1;
    } while (param_10[lVar9] != '\0');
    lVar10 = lVar10 + 2;
  }
  pcVar11 = param_10;
  if (param_10 == (char *)0x0) {
    pcVar11 = "NULL";
  }
  if (param_9 == (char *)0x0) {
    lVar9 = 5;
  }
  else {
    lVar8 = -1;
    do {
      lVar9 = lVar8;
      lVar8 = lVar9 + 1;
    } while (param_9[lVar8] != '\0');
    lVar9 = lVar9 + 2;
  }
  pcVar6 = param_9;
  if (param_9 == (char *)0x0) {
    pcVar6 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    lVar8 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar8 = lVar3;
      lVar3 = lVar8 + 1;
    } while (param_8[lVar3] != '\0');
    lVar8 = lVar8 + 2;
  }
  pcVar7 = param_8;
  if (param_8 == (char *)0x0) {
    pcVar7 = "NULL";
  }
  if (param_6 != (char *)0x0) {
    lVar3 = -1;
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x156,&local_res20,8,
             param_5,lVar1,param_6,lVar2,&param_7,4,pcVar7,lVar8,pcVar6,lVar9,pcVar11,lVar10,pcVar12
             ,lVar4,param_12,lVar5,&param_13,4,&param_14,8,&param_15,4,&param_16,4,&param_17,4,
             &param_18,4,0);
  return;
}



===== WPP_SF_qL @ 140002a28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1)

{
  undefined1 uStack0000000000000028;
  undefined8 local_18 [3];
  
  local_18[0] = 0;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x162,local_18,8,
             &uStack0000000000000028,4,0);
  return;
}



===== WPP_SF_qqL @ 140002a84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0xc000000d;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x23,&local_res20,8,
             &param_5,8,local_18,4,0);
  return;
}



===== WPP_SF_sssi @ 140002af4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sssi(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                char *param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (param_6 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_6[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_5[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar1 = -1;
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
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
            (param_1,0x2b,&WPP_f33b808dea083a26c8d39d383599c2cf_Traceguids,0x154,param_4,lVar2,
             param_5,lVar3,param_6,lVar4,&param_7,8,0);
  return;
}



===== WaitForOnlinesToComplete @ 140002bfc =====

void WaitForOnlinesToComplete(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  KeInitializeEvent(param_1 + 0x138,0,0);
  lVar1 = param_1 + 0x100;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(int *)(param_1 + 0x134) != 1) {
    *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + -1;
    KeReleaseSpinLock(lVar1,uVar2);
    KeWaitForSingleObject(param_1 + 0x138,0,0,0,0);
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
  }
  KeReleaseSpinLock(lVar1,uVar2);
  return;
}



===== WppClassicProviderCallback @ 140002cc0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140002cf4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1400081e7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140002d1c =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140002df4 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140002ed8 =====

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
LAB_140003030:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140003023:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140003030;
      if (uVar5 == 5) goto LAB_140003023;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140003058 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400030dc =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400031cc =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400032dc =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140003340 =====

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



===== wil_details_IsEnabledFallback @ 1400034a0 =====

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



===== wil_details_MapReportingKind @ 140003534 =====

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



===== wil_details_RecordCachedUsage @ 1400035d4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140003730 =====

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



===== _guard_check_icall @ 1400037c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400037d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400037fc =====

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



===== __cpu_features_init @ 140003870 =====

/* WARNING: Removing unreachable block (ram,0x0001400038da) */
/* WARNING: Removing unreachable block (ram,0x000140003889) */
/* WARNING: Removing unreachable block (ram,0x00014000387a) */

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



===== __security_check_cookie @ 140003940 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140003980 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400039b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400039b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400039e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140003a40 =====

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



===== memset @ 140003d40 =====

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



===== __memset_repmovs @ 140003e80 =====

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



===== __memset_query @ 140003f00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003f80 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400040c0 =====

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



===== __memset_spec_plain @ 140004140 =====

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



===== MountMgrFindBootVolume @ 14000d010 =====

undefined8 MountMgrFindBootVolume(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *param_2 = 0;
  while( true ) {
    if (puVar1 == (undefined8 *)(param_1 + 0x10)) {
      return 0xc0000225;
    }
    if ((*(uint *)(puVar1 + 0xf) & 0x100) != 0) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  *param_2 = puVar1;
  return 0;
}



===== TruncateRemoteDatabase @ 14000d050 =====

int TruncateRemoteDatabase(undefined8 param_1,ulonglong param_2)

{
  int iVar1;
  ulonglong *puVar2;
  ulonglong local_res18;
  ulonglong local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18 = param_2 & 0xffffffff;
  puVar2 = &local_res18;
  local_18 = 0;
  uStack_10 = 0;
  local_res20 = local_res18;
  iVar1 = ZwSetInformationFile(0,&local_18,puVar2,8,0x14);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,puVar2,iVar1);
    }
  }
  else {
    puVar2 = &local_res20;
    iVar1 = ZwSetInformationFile(param_1,&local_18,puVar2,8,0x13);
    if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,puVar2,iVar1);
    }
  }
  return iVar1;
}



===== MountMgrMountedDeviceRemoval @ 14000d140 =====

undefined8 MountMgrMountedDeviceRemoval(longlong param_1,undefined8 param_2,char param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  code *pcVar7;
  int iVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  longlong *plVar12;
  longlong lVar13;
  
  plVar9 = (longlong *)0x0;
  lVar13 = 0;
  uVar10 = 0;
  KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
  plVar3 = *(longlong **)(param_1 + 0x10);
  plVar1 = (longlong *)(param_1 + 0x10);
  *(longlong *)(param_1 + 0x150) = *(longlong *)(param_1 + 0x150) + 1;
  for (; plVar3 != plVar1; plVar3 = (longlong *)*plVar3) {
    lVar13 = CONCAT71((int7)((ulonglong)lVar13 >> 8),1);
    uVar11 = param_2;
    iVar8 = RtlCompareUnicodeString(plVar3 + 8);
    if (iVar8 == 0) {
      if (*(char *)((longlong)plVar3 + 0x81) != param_3) goto LAB_14000d1fc;
      if (*(char *)((longlong)plVar3 + 0x87) != '\0') {
        plVar9 = plVar3 + 2;
        goto LAB_14000d24d;
      }
      if (*(char *)((longlong)plVar3 + 0x82) != '\0') {
        uVar11 = 0x28;
        lVar13 = 0x41746e4d;
        plVar9 = (longlong *)ExAllocatePool2(0x102);
        if (plVar9 == (longlong *)0x0) {
          *(undefined1 *)((longlong)plVar3 + 0x82) = 0;
        }
      }
      if (*(char *)((longlong)plVar3 + 0x82) == '\0') {
        plVar9 = plVar3 + 2;
        goto LAB_14000d41c;
      }
      plVar4 = *(longlong **)(param_1 + 0xb8);
      if (*plVar4 != param_1 + 0xb0) goto LAB_14000d614;
      *plVar9 = param_1 + 0xb0;
      plVar12 = plVar9 + 2;
      plVar9[1] = (longlong)plVar4;
      plVar2 = plVar3 + 2;
      *plVar4 = (longlong)plVar9;
      *(longlong **)(param_1 + 0xb8) = plVar9;
      plVar9[3] = (longlong)plVar12;
      *plVar12 = (longlong)plVar12;
      plVar9[4] = plVar3[0xc];
      goto LAB_14000d397;
    }
  }
  if (param_3 == '\0') {
    plVar1 = *(longlong **)(param_1 + 0x20);
    do {
      plVar3 = plVar1;
      if (plVar3 == (longlong *)(param_1 + 0x20)) goto LAB_14000d1fc;
      iVar8 = RtlCompareUnicodeString(plVar3 + 8,param_2,1);
      plVar1 = (longlong *)*plVar3;
    } while (iVar8 != 0);
    if (((longlong *)plVar1[1] == plVar3) &&
       (plVar9 = (longlong *)plVar3[1], (longlong *)*plVar9 == plVar3)) {
      *plVar9 = (longlong)plVar1;
      plVar1[1] = (longlong)plVar9;
      MountMgrFreeDeadDeviceInfo((longlong)plVar3);
      goto LAB_14000d1fc;
    }
    goto LAB_14000d614;
  }
  goto LAB_14000d1fc;
LAB_14000d24d:
  plVar4 = (longlong *)*plVar9;
  if (plVar4 == plVar9) goto LAB_14000d2bc;
  if (((longlong *)plVar4[1] != plVar9) || (lVar5 = *plVar4, *(longlong **)(lVar5 + 8) != plVar4))
  goto LAB_14000d614;
  *plVar9 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar9;
  GlobalDeleteSymbolicLink((undefined1 (*) [16])(plVar4 + 3),uVar11,lVar13,uVar10);
  lVar13 = plVar4[4];
  RtlDeleteRegistryValue(0);
  ExFreePoolWithTag(plVar4[4]);
  uVar11 = 0;
  ExFreePoolWithTag(plVar4);
  goto LAB_14000d24d;
LAB_14000d2bc:
  DeleteNoDriveLetterEntry(plVar3[0xc]);
  goto LAB_14000d2c5;
LAB_14000d41c:
  plVar4 = (longlong *)*plVar9;
  if (plVar4 == plVar9) goto LAB_14000d2c5;
  if (((longlong *)plVar4[1] != plVar9) || (lVar5 = *plVar4, *(longlong **)(lVar5 + 8) != plVar4))
  goto LAB_14000d614;
  *plVar9 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar9;
  GlobalDeleteSymbolicLink((undefined1 (*) [16])(plVar4 + 3),uVar11,lVar13,uVar10);
  ExFreePoolWithTag(plVar4[4]);
  uVar11 = 0;
  ExFreePoolWithTag(plVar4);
  goto LAB_14000d41c;
LAB_14000d397:
  plVar4 = (longlong *)*plVar2;
  if (plVar4 != plVar2) {
    if (((longlong *)plVar4[1] != plVar2) || (lVar5 = *plVar4, *(longlong **)(lVar5 + 8) != plVar4))
    goto LAB_14000d614;
    *plVar2 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar2;
    if ((char)plVar4[2] == '\0') {
      GlobalDeleteSymbolicLink((undefined1 (*) [16])(plVar4 + 3),uVar11,lVar13,uVar10);
      ExFreePoolWithTag(plVar4[4]);
      uVar11 = 0;
      ExFreePoolWithTag(plVar4);
    }
    else {
      puVar6 = (undefined8 *)plVar9[3];
      if ((longlong *)*puVar6 != plVar12) goto LAB_14000d614;
      *plVar4 = (longlong)plVar12;
      plVar4[1] = (longlong)puVar6;
      *puVar6 = plVar4;
      plVar9[3] = (longlong)plVar4;
    }
    goto LAB_14000d397;
  }
LAB_14000d2c5:
  plVar9 = plVar3 + 4;
  while (plVar4 = (longlong *)*plVar9, plVar4 != plVar9) {
    if (((longlong *)plVar4[1] != plVar9) ||
       (lVar13 = *plVar4, *(longlong **)(lVar13 + 8) != plVar4)) goto LAB_14000d614;
    *plVar9 = lVar13;
    *(longlong **)(lVar13 + 8) = plVar9;
    ExFreePoolWithTag(plVar4[2]);
    ExFreePoolWithTag(plVar4);
  }
  plVar9 = plVar3 + 6;
  while (plVar4 = (longlong *)*plVar9, plVar4 != plVar9) {
    if (((longlong *)plVar4[1] != plVar9) ||
       (lVar13 = *plVar4, *(longlong **)(lVar13 + 8) != plVar4)) goto LAB_14000d614;
    *plVar9 = lVar13;
    *(longlong **)(lVar13 + 8) = plVar9;
    *(undefined1 *)(plVar4[2] + 0x84) = 1;
    ExFreePoolWithTag(plVar4[4]);
    ExFreePoolWithTag(plVar4);
  }
  lVar13 = *plVar3;
  if ((*(longlong **)(lVar13 + 8) != plVar3) ||
     (plVar9 = (longlong *)plVar3[1], (longlong *)*plVar9 != plVar3)) {
LAB_14000d614:
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3);
    pcVar7 = (code *)swi(3);
    uVar10 = (*pcVar7)();
    return uVar10;
  }
  *plVar9 = lVar13;
  *(longlong **)(lVar13 + 8) = plVar9;
  for (plVar9 = (longlong *)*plVar1; plVar9 != plVar1; plVar9 = (longlong *)*plVar9) {
    plVar4 = (longlong *)plVar9[6];
    while (plVar4 != plVar9 + 6) {
      plVar12 = plVar4;
      if ((longlong *)plVar4[2] == plVar3) {
        *(longlong *)(param_1 + 0x150) = *(longlong *)(param_1 + 0x150) + 1;
        plVar9[0x16] = *(longlong *)(param_1 + 0x150);
        lVar13 = *plVar4;
        plVar12 = (longlong *)plVar4[1];
        if ((*(longlong **)(lVar13 + 8) != plVar4) || ((longlong *)*plVar12 != plVar4))
        goto LAB_14000d614;
        *plVar12 = lVar13;
        *(longlong **)(lVar13 + 8) = plVar12;
        ExFreePoolWithTag(plVar4[4],0);
        ExFreePoolWithTag(plVar4);
      }
      plVar4 = (longlong *)*plVar12;
    }
  }
  ExFreePoolWithTag(plVar3[9],0);
  if (*(char *)((longlong)plVar3 + 0x82) == '\0') {
    ExFreePoolWithTag(plVar3[0xc],0);
  }
  ExFreePoolWithTag(plVar3[0xb],0);
  if (plVar3[0x12] != 0) {
    IoUnregisterPlugPlayNotification();
  }
  ExFreePoolWithTag(plVar3,0);
LAB_14000d1fc:
  KeReleaseMutex(param_1 + 0x38,0);
  return 0;
}



===== HasNoDriveLetterEntry @ 14000d630 =====

undefined1 HasNoDriveLetterEntry(undefined8 param_1)

{
  undefined1 local_res10 [24];
  code *local_78 [3];
  undefined1 *local_60;
  
  memset(local_78,0,0x70);
  local_res10[0] = 0;
  local_78[0] = CheckForNoDriveLetterEntry;
  local_60 = local_res10;
  RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\MountedDevices",local_78,param_1,0);
  return local_res10[0];
}



===== WppLoadTracingSupport @ 14000d6b0 =====

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



===== MountMgrFreeDeadDeviceInfo @ 14000d800 =====

void MountMgrFreeDeadDeviceInfo(longlong param_1)

{
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x48),0);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== AddRemoteDatabaseEntry @ 14000d83c =====

ulonglong AddRemoteDatabaseEntry(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  
  lVar1 = *(longlong *)(param_1 + 0x98);
  lVar7 = *(longlong *)(param_1 + 0xb0);
  local_38 = 0;
  uStack_30 = 0;
  lVar2 = *(longlong *)(lVar1 + 0x150);
  KeReleaseMutex(lVar1 + 0x38,0);
  local_res8 = GetRemoteDatabaseSize();
  local_res8 = local_res8 & 0xffffffff;
  uVar6 = 0;
  uVar3 = ZwWriteFile(param_2,0,0,0,&local_38,param_3,*param_3,&local_res8,0);
  if ((((int)uVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,uVar6,uVar3);
  }
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  uVar4 = VerifyEpoch(lVar1,lVar2,lVar7);
  uVar5 = (ulonglong)uVar3;
  if ((int)uVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,lVar7,(int)uVar4);
    }
    if (-1 < (int)uVar3) {
      uVar5 = uVar4 & 0xffffffff;
    }
  }
  return uVar5;
}



===== ChangeRemoteDatabaseUniqueId @ 14000d988 =====

ulonglong ChangeRemoteDatabaseUniqueId(longlong param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int *piVar5;
  undefined2 uVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  int *piVar10;
  char local_res20 [8];
  longlong local_38;
  int *local_30;
  
  local_38 = 0;
  local_30 = (int *)0x0;
  local_res20[0] = '\0';
  pcVar8 = local_res20;
  uVar3 = OpenRemoteDatabase(param_1,0,pcVar8,&local_38);
  uVar4 = uVar3 & 0xffffffff;
  if (local_res20[0] == '\0') {
    if (local_38 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,pcVar8,0xc000009a);
      }
      uVar4 = 0xc000009a;
    }
    else {
      piVar10 = (int *)0x0;
      while( true ) {
        piVar9 = piVar10;
        uVar3 = GetRemoteDatabaseEntry(param_1,local_38,(uint)piVar10,(longlong *)&local_30);
        piVar2 = local_30;
        uVar4 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) break;
        if (local_30 == (int *)0x0) goto LAB_14000dc42;
        if ((*(ushort *)((longlong)local_30 + 0xe) == *param_2) &&
           (uVar3 = RtlCompareMemory(param_2 + 1,
                                     (ulonglong)*(ushort *)(local_30 + 3) + (longlong)local_30,
                                     *(ushort *)((longlong)local_30 + 0xe)),
           uVar3 == *(ushort *)((longlong)piVar2 + 0xe))) {
          iVar7 = ((uint)*param_3 - (uint)*param_2) + *piVar2;
          piVar5 = (int *)ExAllocatePool2(0x102,iVar7,0x41746e4d);
          if (piVar5 == (int *)0x0) goto LAB_14000db70;
          *piVar5 = iVar7;
          piVar5[1] = piVar2[1];
          *(undefined2 *)(piVar5 + 2) = 0x10;
          uVar1 = *(ushort *)((longlong)piVar2 + 10);
          *(ushort *)((longlong)piVar5 + 10) = uVar1;
          *(ushort *)(piVar5 + 3) = uVar1 + 0x10;
          *(ushort *)((longlong)piVar5 + 0xe) = *param_3;
          memmove(piVar5 + 4,(void *)((ulonglong)*(ushort *)(piVar2 + 2) + (longlong)piVar2),
                  (ulonglong)uVar1);
          memmove((void *)((ulonglong)*(ushort *)(piVar5 + 3) + (longlong)piVar5),param_3 + 1,
                  (ulonglong)*(ushort *)((longlong)piVar5 + 0xe));
          piVar9 = piVar10;
          uVar3 = DeleteRemoteDatabaseEntry(param_1,local_38,(ulonglong)piVar10);
          uVar4 = uVar3 & 0xffffffff;
          if ((int)uVar3 < 0) {
            ExFreePoolWithTag(piVar2,0);
            ExFreePoolWithTag(piVar5,0);
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_14000dc42;
            uVar6 = 0x48;
            goto LAB_14000dc36;
          }
          piVar9 = piVar5;
          uVar3 = AddRemoteDatabaseEntry(param_1,local_38,piVar5);
          uVar4 = uVar3 & 0xffffffff;
          if ((int)uVar3 < 0) {
            ExFreePoolWithTag(piVar2,0);
            ExFreePoolWithTag(piVar5,0);
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000dc42;
            uVar6 = 0x49;
            goto LAB_14000dc36;
          }
          ExFreePoolWithTag(piVar5);
        }
        else {
LAB_14000db70:
          piVar10 = (int *)(ulonglong)((uint)piVar10 + *piVar2);
        }
        ExFreePoolWithTag(piVar2,0);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar6 = 0x47;
LAB_14000dc36:
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,piVar9,(int)uVar4);
      }
LAB_14000dc42:
      CloseFileHandleOutsideExtensionMutexLock(*(longlong *)(param_1 + 0x98),local_38);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,pcVar8,(int)uVar3);
  }
  return uVar4;
}



===== ChangeUniqueIdRoutine @ 14000dc80 =====

undefined8
ChangeUniqueIdRoutine
          (undefined8 param_1,int param_2,undefined8 param_3,uint param_4,ushort *param_5,
          undefined2 *param_6)

{
  ulonglong uVar1;
  
  if ((param_2 == 3) && (*param_5 == param_4)) {
    uVar1 = RtlCompareMemory(param_5 + 1,param_3,param_4);
    if (uVar1 == param_4) {
      RtlWriteRegistryValue
                (0,L"\\Registry\\Machine\\System\\MountedDevices",param_1,3,param_6 + 1,*param_6);
    }
  }
  return 0;
}



===== CreateNewDriveLetterName @ 14000dd08 =====

ulonglong CreateNewDriveLetterName
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  
  uVar6 = (undefined1)param_3;
  uVar7 = (undefined7)((ulonglong)param_3 >> 8);
  uVar4 = 0;
  if ((*(uint *)(param_1 + 0x78) & 0x100) != 0) {
    uVar3 = MountMgrQueryBootDriveLetter((undefined1 *)(param_1 + 0x80));
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      *(undefined1 *)(param_1 + 0x80) = 0;
      uVar4 = 0;
    }
  }
  bVar1 = *(byte *)(param_1 + 0x80);
  if (bVar1 == 0xff) {
    CreateNoDriveLetterEntry
              (*(ushort **)(param_1 + 0x60),CONCAT71((int7)((ulonglong)param_2 >> 8),bVar1),
               CONCAT71(uVar7,uVar6));
  }
  else {
    bVar5 = 0x41;
    if ((bVar1 < 0x41) || (0x5a < bVar1)) {
      *(undefined1 *)(param_1 + 0x80) = 0;
    }
    else {
      uVar3 = CreateNewDriveLetterHelper(param_1,bVar1,CONCAT71(uVar7,uVar6),param_4);
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) goto LAB_14000ddd8;
    }
    uVar6 = 1;
    cVar2 = RtlPrefixUnicodeString(&DAT_140009088,param_1 + 0x50);
    if (cVar2 == '\0') {
      uVar6 = 1;
      cVar2 = RtlPrefixUnicodeString(&DAT_140009040,param_1 + 0x50);
      bVar5 = (cVar2 != '\0') + 0x43;
    }
    do {
      uVar3 = CreateNewDriveLetterHelper(param_1,bVar5,CONCAT71(uVar7,uVar6),param_4);
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) break;
      bVar5 = bVar5 + 1;
    } while (bVar5 < 0x5b);
  }
LAB_14000ddd8:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,CONCAT71(uVar7,uVar6),(int)uVar4);
  }
  return uVar4;
}



===== CreateNoDriveLetterEntry @ 14000de24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CreateNoDriveLetterEntry(ushort *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined1 auStack_68 [32];
  ushort *local_48;
  uint local_40;
  ulonglong local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  iVar1 = ExUuidCreate(&local_28);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    uVar3 = 0x52;
  }
  else {
    iVar1 = RtlStringFromGUID(&local_28,&local_38);
    if (-1 < iVar1) {
      puVar2 = (undefined2 *)ExAllocatePool2(0x102,(local_38 & 0xffff) + 4,0x41746e4d);
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = 0x23;
        memmove(puVar2 + 1,pvStack_30,local_38 & 0xffff);
        puVar2[(local_38 >> 1 & 0x7fff) + 1] = 0;
        ExFreePoolWithTag(pvStack_30,0);
        local_48 = param_1 + 1;
        local_40 = (uint)*param_1;
        RtlWriteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices",puVar2,3);
        ExFreePoolWithTag(puVar2,0);
        return;
      }
      ExFreePoolWithTag(pvStack_30,0);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return;
      }
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54);
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    uVar3 = 0x53;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,param_3,iVar1);
  return;
}



===== CreateRemoteDatabase @ 14000dff0 =====

int CreateRemoteDatabase(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined2 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  plVar1 = (longlong *)ExAllocatePool2(0x40,0x28,0x41746e4d);
  if (plVar1 == (longlong *)0x0) {
    iVar4 = -0x3fffff66;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      uVar3 = 0x20;
LAB_14000e0cf:
      iVar4 = -0x3fffff66;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3);
    }
  }
  else {
    plVar1[1] = param_1;
    plVar1[2] = (longlong)&local_28;
    lVar2 = IoAllocateWorkItem(**(undefined8 **)(param_1 + 0x98));
    *plVar1 = lVar2;
    if (lVar2 == 0) {
      iVar4 = -0x3fffff66;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        uVar3 = 0x21;
        goto LAB_14000e0cf;
      }
    }
    else {
      IoQueueWorkItem(lVar2,CreateRemoteDatabaseWorker,1,plVar1);
      uVar5 = 0;
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar4 = (int)plVar1[3];
      if (-1 < iVar4) {
        *param_2 = plVar1[4];
        goto LAB_14000e15c;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,uVar5,iVar4);
      }
    }
  }
  *param_2 = 0;
  if (plVar1 == (longlong *)0x0) {
    return iVar4;
  }
LAB_14000e15c:
  ExFreePoolWithTag(plVar1,0);
  return iVar4;
}



===== CreateRemoteDatabaseWorker @ 14000e190 =====

void CreateRemoteDatabaseWorker(undefined8 param_1,undefined8 *param_2)

{
  ushort *puVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 local_res10;
  ushort local_78;
  short local_76;
  undefined4 local_74;
  void *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ushort *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  lVar2 = param_2[1];
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_res10 = 0;
  puVar1 = (ushort *)(lVar2 + 0x50);
  local_58 = 0;
  uStack_50 = 0;
  local_74 = 0;
  local_48 = (ushort *)0x0;
  uStack_40 = 0;
  uVar4 = 0x42746e4d;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = DAT_140009030 + *puVar1;
  local_76 = local_78 + 2;
  local_70 = (void *)ExAllocatePool2(0x102);
  if (local_70 == (void *)0x0) {
    iVar3 = -0x3fffff66;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d);
    }
  }
  else {
    iVar3 = RtlCreateSystemVolumeInformationFolder(puVar1);
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,uVar4,iVar3);
      }
    }
    else {
      memmove(local_70,*(void **)(lVar2 + 0x58),(ulonglong)*puVar1);
      memmove((void *)((ulonglong)*puVar1 + (longlong)local_70),PTR_u__System_Volume__140009038,
              (ulonglong)DAT_140009030);
      puVar5 = &local_58;
      *(undefined2 *)((longlong)local_70 + (ulonglong)(local_78 >> 1) * 2) = 0;
      local_48 = &local_78;
      local_58 = CONCAT44(local_58._4_4_,0x30);
      uStack_50 = 0;
      uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
      local_38 = 0;
      uStack_30 = 0;
      iVar3 = IoCreateFile(&local_res10,0x12019f,puVar5,&local_68,0,0x86,0,2,0x60,0,0,0,0,0x108);
      if (iVar3 < 0) {
        if (iVar3 == -0x7fffffd3) {
          DetectedSymlinkOnRemoteDatabaseFile();
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,puVar5,iVar3);
        }
        local_res10 = 0;
      }
    }
  }
  if (local_70 != (void *)0x0) {
    ExFreePoolWithTag(local_70,0);
  }
  if (-1 < iVar3) {
    *(undefined1 *)(lVar2 + 0x86) = 1;
  }
  IoFreeWorkItem(*param_2);
  param_2[4] = local_res10;
  *param_2 = 0;
  *(int *)(param_2 + 3) = iVar3;
  KeSetEvent(param_2[2],0,0);
  return;
}



===== DeleteDriveLetterRoutine @ 14000e420 =====

undefined8
DeleteDriveLetterRoutine
          (undefined8 param_1,int param_2,undefined8 param_3,uint param_4,ushort *param_5)

{
  bool bVar1;
  ulonglong uVar2;
  short local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  if (((param_2 == 3) && (param_4 == *param_5)) &&
     (uVar2 = RtlCompareMemory(param_5 + 1,param_3,param_4), uVar2 == param_4)) {
    RtlInitUnicodeString(local_18,param_1);
    bVar1 = IsDriveLetter(local_18);
    if (bVar1) {
      RtlDeleteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices",param_1);
      return 0;
    }
    return 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67);
  }
  return 0;
}



===== DeleteFromLocalDatabase @ 14000e4e0 =====

void DeleteFromLocalDatabase(longlong param_1,undefined8 param_2)

{
  code *local_78 [2];
  undefined8 local_68;
  
  memset(local_78,0,0x70);
  local_78[0] = DeleteFromLocalDatabaseRoutine;
  local_68 = *(undefined8 *)(param_1 + 8);
  RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\MountedDevices",local_78,param_2,0);
  return;
}



===== DeleteFromLocalDatabaseRoutine @ 14000e560 =====

undefined8
DeleteFromLocalDatabaseRoutine
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4,ushort *param_5)

{
  ulonglong uVar1;
  
  if (*param_5 == param_4) {
    uVar1 = RtlCompareMemory(param_5 + 1,param_3,param_4);
    if (uVar1 == param_4) {
      RtlDeleteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices",param_1);
    }
  }
  return 0;
}



===== DeleteNoDriveLetterEntry @ 14000e5c8 =====

void DeleteNoDriveLetterEntry(undefined8 param_1)

{
  code *local_78;
  undefined1 local_70 [104];
  
  memset(local_70,0,0x68);
  local_78 = DeleteNoDriveLetterEntryRoutine;
  RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\MountedDevices",&local_78,param_1,0);
  return;
}



===== DeleteRemoteDatabaseEntry @ 14000e624 =====

ulonglong DeleteRemoteDatabaseEntry(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined2 uVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  int *piVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  int *local_res8;
  ulonglong local_res20;
  undefined8 local_50;
  ulonglong uStack_48;
  
  lVar2 = *(longlong *)(param_1 + 0x98);
  local_res20 = 0;
  local_res8 = (int *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  lVar3 = *(longlong *)(lVar2 + 0x150);
  lVar1 = lVar2 + 0x38;
  uVar15 = *(ulonglong *)(param_1 + 0xb0);
  uVar9 = param_3;
  KeReleaseMutex(lVar1,0);
  uVar8 = GetRemoteDatabaseSize();
  uVar6 = (uint)uVar8;
  if (uVar6 == 0) {
    uVar12 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar8 + 0x38,uVar9,0xc000000d);
    }
    goto LAB_14000e950;
  }
  KeWaitForSingleObject(lVar1,0,0,0,0);
  uVar9 = uVar15;
  uVar12 = VerifyEpoch(lVar2,lVar3,uVar15);
  iVar5 = (int)uVar12;
  uVar12 = uVar12 & 0xffffffff;
  if (iVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar10 = 0x39;
LAB_14000e730:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,uVar9,iVar5);
    }
LAB_14000e739:
    KeReleaseMutex(lVar1,0);
    goto LAB_14000e950;
  }
  uVar7 = (uint)param_3;
  uVar9 = param_3 & 0xffffffff;
  uVar8 = GetRemoteDatabaseEntry(param_1,param_2,uVar7,(longlong *)&local_res8);
  piVar4 = local_res8;
  uVar12 = uVar8 & 0xffffffff;
  if ((int)uVar8 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,uVar9,(int)uVar8);
    }
    KeReleaseMutex(lVar1,0);
    goto LAB_14000e93a;
  }
  if (local_res8 == (int *)0x0) {
    uVar12 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar10 = 0x3b;
      iVar5 = -0x3ffffff3;
      goto LAB_14000e730;
    }
    goto LAB_14000e739;
  }
  KeReleaseMutex(lVar1,0);
  if (*piVar4 + uVar7 < uVar6) {
    uVar6 = (uVar6 - *piVar4) - uVar7;
    local_res8 = (int *)ExAllocatePool2(0x102,uVar6);
    if (local_res8 == (int *)0x0) {
      uVar12 = 0xc000009a;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d);
      }
    }
    else {
      local_res20 = (ulonglong)(*piVar4 + uVar7);
      uVar14 = 0;
      uVar7 = ZwReadFile(param_2,0,0,0,&local_50,local_res8,uVar6,&local_res20,0);
      uVar12 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar10 = 0x3e;
LAB_14000e919:
          uVar11 = (undefined4)uVar12;
LAB_14000e91c:
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,uVar14,uVar11);
        }
LAB_14000e925:
        piVar13 = local_res8;
      }
      else {
        if (uStack_48 < uVar6) {
          uVar12 = 0xc000000d;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar10 = 0x3f;
            uVar11 = 0xc000000d;
            goto LAB_14000e91c;
          }
          goto LAB_14000e925;
        }
        uVar7 = TruncateRemoteDatabase(param_2,param_3 & 0xffffffff);
        piVar13 = local_res8;
        uVar12 = (ulonglong)uVar7;
        if ((int)uVar7 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar10 = 0x40;
            goto LAB_14000e919;
          }
          goto LAB_14000e925;
        }
        uVar14 = 0;
        local_res20 = param_3 & 0xffffffff;
        uVar6 = ZwWriteFile(param_2,0,0,0,&local_50,local_res8,uVar6,&local_res20,0);
        uVar12 = (ulonglong)uVar6;
        if ((((int)uVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,uVar14,uVar6);
        }
      }
      ExFreePoolWithTag(piVar13,0);
    }
  }
  else {
    uVar6 = TruncateRemoteDatabase(param_2,param_3 & 0xffffffff);
    uVar12 = (ulonglong)uVar6;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,uVar9,uVar6);
    }
  }
LAB_14000e93a:
  if (piVar4 != (int *)0x0) {
    ExFreePoolWithTag(piVar4,0);
  }
LAB_14000e950:
  KeWaitForSingleObject(lVar1,0,0,0,0);
  uVar9 = VerifyEpoch(lVar2,lVar3,uVar15);
  if ((int)uVar9 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,uVar15,(int)uVar9);
    }
    if (-1 < (int)uVar12) {
      uVar12 = uVar9 & 0xffffffff;
    }
  }
  return uVar12;
}



===== DetectedSymlinkOnRemoteDatabaseFile @ 14000eabc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DetectedSymlinkOnRemoteDatabaseFile(void)

{
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  undefined2 local_48 [4];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  uint local_28;
  undefined4 local_24;
  undefined2 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (gEtwProvRegHandle != 0) {
    RtlInitUnicodeString(&local_40,L"CVE-2015-1769");
    local_30 = uStack_38;
    local_28 = (uint)(ushort)local_40;
    local_20 = local_48;
    local_58 = &local_30;
    local_24 = 0;
    local_18 = 2;
    EtwWrite(gEtwProvRegHandle,&MOUNTMGR_CVE_DETECT,0);
  }
  return;
}



===== GetRemoteDatabaseSize @ 14000eb70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetRemoteDatabaseSize(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 5;
  local_18 = 0;
  puVar2 = &local_28;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = ZwQueryInformationFile(0,&local_38,puVar2,0x18);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,puVar2,iVar1);
    }
    uStack_20 = 0;
  }
  else {
    uStack_20 = uStack_20 & 0xffffffff;
  }
  return uStack_20;
}



===== HasDriveLetter @ 14000ec14 =====

undefined1 HasDriveLetter(longlong param_1,undefined1 *param_2)

{
  bool bVar1;
  undefined8 *puVar2;
  
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  while( true ) {
    if (puVar2 == (undefined8 *)(param_1 + 0x10)) {
      return 0;
    }
    if ((*(char *)(puVar2 + 2) != '\0') && (bVar1 = IsDriveLetter((short *)(puVar2 + 3)), bVar1))
    break;
    puVar2 = (undefined8 *)*puVar2;
  }
  if (param_2 == (undefined1 *)0x0) {
    return 1;
  }
  *param_2 = *(undefined1 *)(puVar2[4] + 0x18);
  return 1;
}



===== IsUniqueIdPresent @ 14000ec8c =====

ulonglong IsUniqueIdPresent(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ulonglong in_RAX;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  while( true ) {
    if (puVar2 == (undefined8 *)(param_1 + 0x10)) {
      return in_RAX & 0xffffffffffffff00;
    }
    uVar1 = *(ushort *)(param_2 + 0xe);
    in_RAX = (ulonglong)uVar1;
    if ((uVar1 == *(ushort *)puVar2[0xc]) &&
       (in_RAX = RtlCompareMemory((ulonglong)*(ushort *)(param_2 + 0xc) + param_2,
                                  (ushort *)puVar2[0xc] + 1,uVar1),
       in_RAX == *(ushort *)(param_2 + 0xe))) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== MountMgrCreatePoint @ 14000ecfc =====

int MountMgrCreatePoint(undefined8 *param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong *puVar8;
  undefined2 uVar9;
  undefined8 *puVar10;
  ushort *puVar11;
  ulonglong local_38;
  short *psStack_30;
  ulonglong local_28;
  longlong lStack_20;
  ulonglong local_18;
  longlong lStack_10;
  
  puVar11 = *(ushort **)(param_2 + 0x18);
  local_28 = 0;
  lStack_20 = 0;
  local_18 = 0;
  lStack_10 = 0;
  uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  local_38 = 0;
  psStack_30 = (short *)0x0;
  if (uVar3 < 8) {
LAB_14000ee75:
    iVar5 = -0x3ffffff3;
  }
  else {
    uVar1 = puVar11[1];
    uVar2 = puVar11[3];
    uVar6 = (ulonglong)uVar2;
    uVar4 = (uint)*puVar11 + (uint)uVar1;
    uVar7 = (uint)puVar11[2] + (uint)uVar2;
    if ((uint)puVar11[2] + (uint)uVar2 <= uVar4) {
      uVar7 = uVar4;
    }
    if (uVar3 < uVar7) {
      iVar5 = -0x3ffffff3;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_14000ee7a;
      uVar9 = 0xca;
      iVar5 = -0x3ffffff3;
    }
    else {
      psStack_30 = (short *)((longlong)puVar11 + (ulonglong)*puVar11);
      local_38 = (ulonglong)CONCAT22(uVar1,uVar1);
      if ((uVar1 < 2) || (*psStack_30 == 0)) goto LAB_14000ee75;
      local_28 = (ulonglong)CONCAT22(uVar2,uVar2);
      puVar8 = &local_28;
      lStack_20 = (ulonglong)puVar11[2] + (longlong)puVar11;
      iVar5 = QueryDeviceName(puVar8,&local_18);
      if (-1 < iVar5) {
        for (puVar10 = (undefined8 *)param_1[2]; puVar10 != param_1 + 2;
            puVar10 = (undefined8 *)*puVar10) {
          puVar8 = &local_18;
          iVar5 = RtlCompareUnicodeString(puVar8,puVar10 + 10,1);
          if (iVar5 == 0) {
            uVar6 = MountMgrCreatePointWorker(param_1,&local_38,(longlong)puVar10,uVar6);
            iVar5 = (int)uVar6;
            goto LAB_14000ee7a;
          }
        }
        iVar5 = MountMgrCreatePointWorkerLegacy(puVar8,(ushort *)&local_38,&local_18,uVar6);
        goto LAB_14000ee7a;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000ee7a;
      uVar9 = 0xcb;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar11,iVar5);
  }
LAB_14000ee7a:
  if (lStack_10 != 0) {
    ExFreePoolWithTag(lStack_10,0);
  }
  return iVar5;
}



===== MountMgrCreatePointWorker @ 14000eeb4 =====

ulonglong MountMgrCreatePointWorker
                    (undefined8 *param_1,ulonglong *param_2,longlong param_3,undefined8 param_4)

{
  ushort *puVar1;
  short sVar2;
  ushort *puVar3;
  code *pcVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  short *_Dst;
  ulonglong uVar8;
  longlong *plVar9;
  void *_Dst_00;
  longlong lVar10;
  wchar_t *pwVar11;
  undefined8 uVar12;
  longlong *plVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  undefined8 *puVar16;
  short *psVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  ushort *local_48;
  uint local_40;
  undefined8 local_38;
  short *psStack_30;
  
  local_38 = *param_2;
  psStack_30 = (short *)param_2[1];
  MountmgrSetDLStringCase((short *)&local_38,param_2,param_3);
  _Dst = (short *)ExAllocatePool2(0x102,(local_38 & 0xffff) + 2,0x41746e4d);
  if (_Dst == (short *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e);
    }
    return 0xc000009a;
  }
  uVar19 = local_38 & 0xffff;
  memmove(_Dst,psStack_30,uVar19);
  _Dst[(ushort)local_38 >> 1] = 0;
  sVar2 = local_38._2_2_ + 2;
  local_38._0_4_ = CONCAT22(sVar2,(ushort)local_38);
  psStack_30 = _Dst;
  bVar5 = IsDriveLetter((short *)&local_38);
  if ((bVar5) && (cVar6 = HasDriveLetter(param_3,(undefined1 *)0x0), cVar6 != '\0')) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,uVar19,0);
    }
    uVar14 = 0xc000000d;
  }
  else {
    uVar8 = GlobalCreateSymbolicLink
                      ((undefined1 (*) [16])&local_38,(undefined8 *)(param_3 + 0x50),uVar19,param_4)
    ;
    uVar14 = uVar8 & 0xffffffff;
    if ((int)uVar8 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,uVar19,(int)uVar8);
      }
    }
    else {
      puVar3 = *(ushort **)(param_3 + 0x60);
      pwVar11 = L"\\Registry\\Machine\\System\\MountedDevices";
      uVar19 = 3;
      local_48 = puVar3 + 1;
      local_40 = (uint)*puVar3;
      psVar17 = _Dst;
      uVar7 = RtlWriteRegistryValue(0);
      uVar14 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          pwVar11 = (wchar_t *)0x71;
          uVar19 = (ulonglong)uVar7;
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,psVar17,uVar7);
        }
        GlobalDeleteSymbolicLink((undefined1 (*) [16])&local_38,pwVar11,psVar17,uVar19);
      }
      else {
        uVar18 = 0x41746e4d;
        uVar12 = 0x28;
        plVar9 = (longlong *)ExAllocatePool2(0x102);
        if (plVar9 == (longlong *)0x0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            uVar12 = 0x72;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72);
          }
        }
        else {
          puVar1 = (ushort *)(plVar9 + 3);
          *puVar1 = (ushort)local_38;
          uVar18 = 0x41746e4d;
          *(ushort *)((longlong)plVar9 + 0x1a) = (ushort)local_38 + 2;
          _Dst_00 = (void *)ExAllocatePool2(0x102);
          plVar9[4] = (longlong)_Dst_00;
          if (_Dst_00 != (void *)0x0) {
            memmove(_Dst_00,psStack_30,local_38 & 0xffff);
            puVar15 = auStack_68;
            *(undefined2 *)(plVar9[4] + (ulonglong)(*puVar1 >> 1) * 2) = 0;
            lVar10 = param_3 + 0x10;
            *(undefined1 *)(plVar9 + 2) = 1;
            plVar13 = *(longlong **)(param_3 + 0x18);
            if (*plVar13 != lVar10) {
              pcVar4 = (code *)swi(0x29);
              lVar10 = (*pcVar4)(3);
              puVar15 = auStack_60;
            }
            *plVar9 = lVar10;
            plVar9[1] = (longlong)plVar13;
            *plVar13 = (longlong)plVar9;
            *(longlong **)(lVar10 + 8) = plVar9;
            uVar12 = param_1[0x2e];
            *(undefined8 *)(puVar15 + -8) = 0x14000f1c0;
            cVar6 = PsIsHostSilo();
            if (cVar6 != '\0') {
              *(undefined8 *)(puVar15 + -8) = 0x14000f1d1;
              SendLinkCreated(uVar12,puVar1);
            }
            *(undefined8 *)(puVar15 + -8) = 0x14000f1da;
            bVar5 = IsDriveLetter((short *)&local_38);
            if (bVar5) {
              *(undefined8 *)(puVar15 + -8) = 0x14000f1e9;
              DeleteNoDriveLetterEntry(puVar3);
              if (*(char *)(param_3 + 0x85) == '\0') {
                *(undefined8 *)(puVar15 + -8) = 0x14000f1fe;
                PostOnlineNotification((longlong)param_1,(short *)(param_3 + 0x40));
              }
            }
            if (((((((ushort)local_38 == 0x60) ||
                   (((ushort)local_38 == 0x62 && (psStack_30[0x30] == 0x5c)))) &&
                  (*psStack_30 == 0x5c)) &&
                 ((((sVar2 = psStack_30[1], sVar2 == 0x3f || (sVar2 == 0x5c)) &&
                   (psStack_30[2] == 0x3f)) && ((psStack_30[3] == 0x5c && (psStack_30[4] == 0x56))))
                 )) && ((((psStack_30[5] == 0x6f &&
                          ((psStack_30[6] == 0x6c && (psStack_30[7] == 0x75)))) &&
                         ((psStack_30[8] == 0x6d &&
                          ((((psStack_30[9] == 0x65 && (psStack_30[10] == 0x7b)) &&
                            (psStack_30[0x13] == 0x2d)) &&
                           (((psStack_30[0x18] == 0x2d && (psStack_30[0x1d] == 0x2d)) &&
                            ((psStack_30[0x22] == 0x2d &&
                             ((psStack_30[0x2f] == 0x7d && ((ushort)local_38 == 0x60)))))))))))) &&
                        (sVar2 == 0x3f)))) && (*(char *)(param_1 + 0x12) != '\0')) {
              for (puVar16 = (undefined8 *)param_1[2]; puVar16 != param_1 + 2;
                  puVar16 = (undefined8 *)*puVar16) {
                if (*(char *)((longlong)puVar16 + 0x84) != '\0') {
                  *(undefined8 *)(puVar15 + -8) = 0x14000f2eb;
                  ReconcileThisDatabaseWithMaster(param_1,(longlong)puVar16);
                }
              }
            }
            *(undefined8 *)(puVar15 + -8) = 0x14000f2ff;
            ExFreePoolWithTag(_Dst,0);
            *(undefined8 *)(puVar15 + -8) = 0x14000f30c;
            MountMgrNotify((longlong)param_1);
            if (*(char *)(param_3 + 0x81) == '\0') {
              *(undefined8 *)(puVar15 + -8) = 0x14000f324;
              MountMgrNotifyNameChange((longlong)param_1,param_3 + 0x50,'\0');
              return uVar14;
            }
            return uVar14;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73);
          }
          uVar12 = 0;
          ExFreePoolWithTag(plVar9);
        }
        GlobalDeleteSymbolicLink((undefined1 (*) [16])&local_38,uVar12,uVar18,uVar19);
        uVar14 = 0xc000009a;
      }
    }
  }
  ExFreePoolWithTag(_Dst,0);
  return uVar14;
}



===== MountMgrCreatePointWorkerLegacy @ 14000f34c =====

int MountMgrCreatePointWorkerLegacy
              (undefined8 param_1,ushort *param_2,undefined8 *param_3,undefined8 param_4)

{
  ushort uVar1;
  undefined2 *puVar2;
  bool bVar3;
  int iVar4;
  void *_Dst;
  ulonglong uVar5;
  undefined2 uVar6;
  void *_Src;
  undefined8 *puVar7;
  undefined2 *local_res8;
  short local_a8 [4];
  void *pvStack_a0;
  code *local_98;
  undefined1 local_90 [104];
  
  local_res8 = (undefined2 *)0x0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  pvStack_a0 = (void *)0x0;
  puVar7 = param_3;
  iVar4 = QueryUniqueId(param_3,&local_res8);
  puVar2 = local_res8;
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,puVar7,iVar4);
    }
    goto LAB_14000f561;
  }
  local_a8 = *(short (*) [4])param_2;
  pvStack_a0 = *(void **)(param_2 + 4);
  _Dst = (void *)ExAllocatePool2(0x102,(ulonglong)*param_2 + 2,0x41746e4d);
  if (_Dst == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75);
    }
    iVar4 = -0x3fffff66;
    goto LAB_14000f561;
  }
  uVar1 = *param_2;
  _Src = *(void **)(param_2 + 4);
  uVar5 = (ulonglong)uVar1;
  memmove(_Dst,_Src,uVar5);
  *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar1 >> 1) * 2) = 0;
  local_a8[1] = local_a8[1] + 2;
  pvStack_a0 = _Dst;
  MountmgrSetDLStringCase(local_a8,_Src,uVar5);
  uVar5 = GlobalCreateSymbolicLink((undefined1 (*) [16])local_a8,param_3,uVar5,param_4);
  iVar4 = (int)uVar5;
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar6 = 0x76;
LAB_14000f544:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,WPP_GLOBAL_Control,iVar4);
    }
  }
  else {
    bVar3 = IsDriveLetter(local_a8);
    if (bVar3) {
      memset(local_90,0,0x68);
      local_98 = DeleteDriveLetterRoutine;
      RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\MountedDevices",&local_98,puVar2,0);
    }
    iVar4 = RtlWriteRegistryValue
                      (0,L"\\Registry\\Machine\\System\\MountedDevices",_Dst,3,puVar2 + 1,*puVar2);
    if (((iVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar6 = 0x77;
      goto LAB_14000f544;
    }
  }
  ExFreePoolWithTag(_Dst,0);
LAB_14000f561:
  if (puVar2 != (undefined2 *)0x0) {
    ExFreePoolWithTag(puVar2,0);
  }
  return iVar4;
}



===== MountMgrDeletePointsDbOnly @ 14000f5a4 =====

int MountMgrDeletePointsDbOnly(longlong param_1,longlong param_2,void *param_3)

{
  short sVar1;
  ushort uVar2;
  longlong lVar3;
  bool bVar4;
  short sVar5;
  int iVar6;
  ushort *puVar7;
  ulonglong uVar8;
  undefined2 uVar9;
  void *_Src;
  uint uVar10;
  ulonglong _Size;
  undefined8 local_28;
  void *pvStack_20;
  
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  iVar6 = MountMgrQueryPoints(param_1,param_2,(ulonglong)param_3);
  if (iVar6 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar9 = 0xe6;
LAB_14000f5f7:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,param_3,iVar6);
    }
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
    for (uVar10 = 0; uVar10 < *(uint *)(lVar3 + 4); uVar10 = uVar10 + 1) {
      uVar8 = (ulonglong)uVar10;
      sVar1 = *(short *)(lVar3 + 0xc + uVar8 * 0x18);
      sVar5 = sVar1 + 2;
      local_28._0_4_ = CONCAT22(sVar5,sVar1);
      pvStack_20 = (void *)ExAllocatePool2(0x102,sVar5,0x41746e4d);
      if (pvStack_20 == (void *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe7);
        }
        return -0x3fffff66;
      }
      memmove(pvStack_20,(void *)((ulonglong)*(uint *)(lVar3 + 8 + uVar8 * 0x18) + lVar3),
              local_28 & 0xffff);
      *(undefined2 *)((longlong)pvStack_20 + (local_28 >> 1 & 0x7fff) * 2) = 0;
      if ((((*(int *)(lVar3 + 4) == 1) && (bVar4 = IsDriveLetter((short *)&local_28), bVar4)) &&
          (uVar2 = *(ushort *)(lVar3 + 0x14 + uVar8 * 0x18), uVar2 != 0)) &&
         (puVar7 = (ushort *)ExAllocatePool2(0x102,(ulonglong)uVar2 + 4,0x41746e4d),
         puVar7 != (ushort *)0x0)) {
        uVar2 = *(ushort *)(lVar3 + 0x14 + uVar8 * 0x18);
        *puVar7 = uVar2;
        _Size = (ulonglong)uVar2;
        _Src = (void *)((ulonglong)*(uint *)(lVar3 + 0x10 + uVar8 * 0x18) + lVar3);
        memmove(puVar7 + 1,_Src,_Size);
        CreateNoDriveLetterEntry(puVar7,_Src,_Size);
        ExFreePoolWithTag(puVar7,0);
      }
      uVar8 = DeleteSymbolicLinkNameFromMemory(param_1,(ushort *)&local_28,'\x01');
      iVar6 = (int)uVar8;
      param_3 = pvStack_20;
      RtlDeleteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices");
      ExFreePoolWithTag(pvStack_20,0);
      if (iVar6 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar6;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return iVar6;
        }
        uVar9 = 0xe8;
        goto LAB_14000f5f7;
      }
    }
  }
  return iVar6;
}



===== MountMgrDriverReinitialization @ 14000f7c0 =====

void MountMgrDriverReinitialization(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined2 local_res10 [4];
  
  uVar4 = 0;
  puVar3 = (undefined8 *)0x0;
  uVar1 = 0;
  KeWaitForSingleObject(param_2 + 7);
  *(undefined1 *)(param_2 + 0x12) = 1;
  local_res10[0] = 0;
  ProcessSuggestedDriveLetters(param_2,uVar1,puVar3,uVar4);
  puVar3 = param_2 + 2;
  for (puVar2 = (undefined8 *)*puVar3; puVar2 != puVar3; puVar2 = (undefined8 *)*puVar2) {
    MountMgrNextDriveLetterWorker(param_2,(longlong)puVar2,local_res10,uVar4);
  }
  for (puVar2 = (undefined8 *)*puVar3; puVar2 != puVar3; puVar2 = (undefined8 *)*puVar2) {
    ReconcileThisDatabaseWithMaster(param_2,(longlong)puVar2);
  }
  KeReleaseMutex(param_2 + 7,0);
  WaitForOnlinesToComplete((longlong)param_2);
  return;
}



===== MountMgrFreeMountedDeviceInfo @ 14000f878 =====

void MountMgrFreeMountedDeviceInfo
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar7 = auStack_28;
  cVar6 = (char)param_2;
  plVar1 = (longlong *)(param_1 + 0x10);
  while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) goto LAB_14000f97d;
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    if (cVar6 == '\0') {
      GlobalDeleteSymbolicLink((undefined1 (*) [16])(plVar2 + 3),param_2,param_3,param_4);
    }
    ExFreePoolWithTag(plVar2[4]);
    param_2 = 0;
    ExFreePoolWithTag(plVar2);
  }
  plVar1 = (longlong *)(param_1 + 0x20);
  while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) goto LAB_14000f97d;
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    ExFreePoolWithTag(plVar2[2]);
    ExFreePoolWithTag(plVar2);
  }
  plVar1 = (longlong *)(param_1 + 0x30);
  while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) goto LAB_14000f97d;
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    ExFreePoolWithTag(plVar2[4],0);
    ExFreePoolWithTag(plVar2);
  }
LAB_14000f984:
  uVar4 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(puVar7 + -8) = 0x14000f991;
  ExFreePoolWithTag(uVar4,0);
  if (*(char *)(param_1 + 0x82) == '\0') {
    uVar4 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(puVar7 + -8) = 0x14000f9ac;
    ExFreePoolWithTag(uVar4,0);
  }
  uVar4 = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(puVar7 + -8) = 0x14000f9be;
  ExFreePoolWithTag(uVar4,0);
  if (*(longlong *)(param_1 + 0x90) != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x14000f9d6;
    IoUnregisterPlugPlayNotification();
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000f9e7;
  ExFreePoolWithTag(param_1,0);
  return;
LAB_14000f97d:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar7 = auStack_20;
  goto LAB_14000f984;
}



===== MountMgrFreeSavedLink @ 14000fa08 =====

void MountMgrFreeSavedLink
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar6 = auStack_28;
  plVar1 = (longlong *)(param_1 + 0x10);
  do {
    plVar2 = (longlong *)*plVar1;
    if (plVar2 == plVar1) {
LAB_14000fa71:
      uVar4 = *(undefined8 *)(param_1 + 0x20);
      *(undefined8 *)(puVar6 + -8) = 0x14000fa7e;
      ExFreePoolWithTag(uVar4,0);
      *(undefined8 *)(puVar6 + -8) = 0x14000fa8f;
      ExFreePoolWithTag(param_1,0);
      return;
    }
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStack_20;
      goto LAB_14000fa71;
    }
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    GlobalDeleteSymbolicLink((undefined1 (*) [16])(plVar2 + 3),param_2,param_3,param_4);
    ExFreePoolWithTag(plVar2[4]);
    param_2 = 0;
    ExFreePoolWithTag(plVar2);
  } while( true );
}



===== MountMgrKeepLinksWhenOffline @ 14000faac =====

int MountMgrKeepLinksWhenOffline(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  ushort *puVar5;
  longlong local_res10 [3];
  ulonglong local_18;
  ushort *puStack_10;
  
  puVar5 = *(ushort **)(param_2 + 0x18);
  local_res10[0] = 0;
  local_18 = 0;
  puStack_10 = (ushort *)0x0;
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (uVar2 < 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar4 = 0x122;
  }
  else {
    uVar1 = *puVar5;
    if (uVar1 + 2 <= uVar2) {
      puStack_10 = puVar5 + 1;
      local_18 = (ulonglong)CONCAT22(uVar1,uVar1);
      iVar3 = FindDeviceInfo(param_1,&local_18,puVar5,local_res10);
      if (-1 < iVar3) {
        *(undefined1 *)(local_res10[0] + 0x82) = 1;
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x124,puVar5,iVar3);
      }
      return iVar3;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar4 = 0x123;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,puVar5,0xc000000d);
  return -0x3ffffff3;
}



===== MountMgrPrepareVolumeDelete @ 14000fbb0 =====

int MountMgrPrepareVolumeDelete(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  undefined2 uVar6;
  ushort *puVar7;
  longlong local_res10 [3];
  ulonglong local_18;
  ushort *puStack_10;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_res10[0] = 0;
  puVar7 = *(ushort **)(param_2 + 0x18);
  local_18 = 0;
  puStack_10 = (ushort *)0x0;
  uVar2 = *(uint *)(lVar4 + 0x10);
  if (uVar2 < 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar6 = 0xdf;
  }
  else {
    uVar1 = *puVar7;
    if (uVar1 + 2 <= uVar2) {
      puStack_10 = puVar7 + 1;
      local_18 = (ulonglong)CONCAT22(uVar1,uVar1);
      iVar5 = FindDeviceInfo(param_1,&local_18,puVar7,local_res10);
      if (iVar5 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe1,puVar7,iVar5);
        }
      }
      else {
        iVar3 = *(int *)(lVar4 + 0x18);
        if (iVar3 == 0x6dc04c) {
          *(undefined1 *)(local_res10[0] + 0x87) = 1;
        }
        else if (iVar3 == 0x6dc050) {
          *(undefined1 *)(local_res10[0] + 0x87) = 0;
        }
      }
      return iVar5;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar6 = 0xe0;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar7,0xc000000d);
  return -0x3ffffff3;
}



===== MountMgrQueryAutoMount @ 14000fcdc =====

undefined8 MountMgrQueryAutoMount(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 4) {
    uVar2 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x152,param_3,0xc000000d);
    }
  }
  else {
    **(uint **)(param_2 + 0x18) = (uint)(*(char *)(param_1 + 0xc0) != '\0');
    uVar1 = 4;
  }
  *(undefined8 *)(param_2 + 0x38) = uVar1;
  return uVar2;
}



===== MountMgrQueryBootDriveLetter @ 14000fd68 =====

ulonglong MountMgrQueryBootDriveLetter(undefined1 *param_1)

{
  ulonglong uVar1;
  int local_res8 [8];
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  int *local_60;
  undefined4 local_58;
  
  local_res8[0] = 0;
  memset(local_78,0,0x70);
  local_68 = L"SystemBootDriveLetter";
  local_60 = local_res8;
  local_70 = 0x124;
  local_58 = 0x4000000;
  uVar1 = RtlQueryRegistryValuesEx(2,0,local_78,0,0);
  if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, 0x19 < local_res8[0] - 0x41U)) {
    uVar1 = 0xc000090b;
  }
  *param_1 = (char)local_res8[0];
  return uVar1;
}



===== MountMgrQuerySymbolicLink @ 14000fe00 =====

int MountMgrQuerySymbolicLink(undefined8 param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 local_res8;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_res8 = 0;
  local_30 = 0;
  local_20 = 0x240;
  puVar3 = &local_38;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_1;
  iVar2 = ZwOpenSymbolicLinkObject(&local_res8,0x80000000);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xfe,puVar3,iVar2);
    }
  }
  else {
    uVar4 = 0;
    iVar2 = ZwQuerySymbolicLinkObject(local_res8,param_2);
    if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xff,uVar4,iVar2);
    }
    ZwClose(local_res8);
    if (((-1 < iVar2) && (uVar1 = *param_2, 2 < uVar1)) &&
       (*(short *)(*(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar1 >> 1) * 2) == 0x5c)) {
      *param_2 = uVar1 - 2;
      *(undefined2 *)(*(longlong *)(param_2 + 4) + (ulonglong)((ushort)(uVar1 - 2) >> 1) * 2) = 0;
    }
  }
  return iVar2;
}



===== MountMgrScrubRegistry @ 14000ff40 =====

void MountMgrScrubRegistry(undefined8 param_1)

{
  char local_res10 [24];
  code *local_78 [3];
  char *local_60;
  
  do {
    memset(local_78,0,0x70);
    local_78[0] = ScrubRegistryRoutine;
    local_60 = local_res10;
    local_res10[0] = '\0';
    RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\MountedDevices",local_78,param_1,0);
  } while (local_res10[0] != '\0');
  return;
}



===== MountMgrSetAutoMount @ 14000ffbc =====

undefined4 MountMgrSetAutoMount(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_res10 [6];
  
  uVar2 = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 4) {
    uVar2 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x153,*(int **)(param_2 + 0x18),0xc000000d
              );
    }
  }
  else {
    iVar1 = **(int **)(param_2 + 0x18);
    if ((iVar1 == 1) != (bool)*(char *)(param_1 + 0xc0)) {
      *(bool *)(param_1 + 0xc0) = iVar1 == 1;
      local_res10[0] = (uint)(iVar1 != 1);
      uVar2 = RtlWriteRegistryValue
                        (0,*(undefined8 *)(param_1 + 0x110),L"NoAutoMount",4,local_res10,4);
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  return uVar2;
}



===== MountMgrShutdown @ 140010090 =====

undefined8 MountMgrShutdown(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  gUnloading = 1;
  UNLOCK();
  KeInitializeEvent(&gUnloadEvent,0,0);
  LOCK();
  piVar1 = (int *)(lVar3 + 0xf8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*piVar1 == 0 || SCARRY4(iVar2,1) != *piVar1 < 0) {
    LOCK();
    *(int *)(lVar3 + 0xf8) = *(int *)(lVar3 + 0xf8) + -1;
    UNLOCK();
  }
  else {
    KeReleaseSemaphore(lVar3 + 0xd8,0,1);
    KeWaitForSingleObject(&gUnloadEvent,0,0,0,0);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== MountMgrTraceDeviceExtension @ 140010144 =====

undefined8 MountMgrTraceDeviceExtension(longlong param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar3 = "TRUE";
    pcVar2 = "TRUE";
    if (*(int *)(param_1 + 0x118) == 0) {
      pcVar2 = "FALSE";
    }
    pcVar1 = "TRUE";
    if (*(char *)(param_1 + 0xc0) == '\0') {
      pcVar1 = "FALSE";
    }
    if (*(char *)(param_1 + 0x90) == '\0') {
      pcVar3 = "FALSE";
    }
    WPP_SF_sssi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar1,pcVar2,pcVar3,pcVar1,pcVar2,
                (char)*(undefined8 *)(param_1 + 0x150));
  }
  return 0;
}



===== MountMgrTraceMountedDevice @ 1400101d0 =====

undefined8 MountMgrTraceMountedDevice(ulonglong param_1,ulonglong param_2)

{
  char *pcVar1;
  undefined8 *puVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  wchar_t *pwVar7;
  char *pcVar8;
  char *pcVar9;
  
  pcVar6 = "FALSE";
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar3 = "TRUE";
    pcVar4 = "TRUE";
    if (*(char *)(param_2 + 0x86) == '\0') {
      pcVar3 = "FALSE";
    }
    pcVar5 = "TRUE";
    pcVar1 = "TRUE";
    pcVar9 = "TRUE";
    if (*(char *)(param_2 + 0x85) == '\0') {
      pcVar4 = "FALSE";
    }
    pcVar8 = "TRUE";
    if (*(char *)(param_2 + 0x84) == '\0') {
      pcVar5 = "FALSE";
    }
    if (*(char *)(param_2 + 0x83) == '\0') {
      pcVar1 = "FALSE";
    }
    if (*(char *)(param_2 + 0x7c) == '\0') {
      pcVar9 = "FALSE";
    }
    if (*(char *)(param_2 + 0x82) == '\0') {
      pcVar8 = "FALSE";
    }
    pcVar6 = (char *)L"NULL";
    if (*(wchar_t **)(param_2 + 0x58) != (wchar_t *)0x0) {
      pcVar6 = (char *)*(wchar_t **)(param_2 + 0x58);
    }
    WPP_SF_iSsdsssssdiDDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(byte *)(param_2 + 0x80),
               pcVar6,param_1 ^ param_2,(wchar_t *)pcVar6,pcVar8,*(byte *)(param_2 + 0x80),pcVar9,
               pcVar1,pcVar5,pcVar4,pcVar3,(char)*(undefined4 *)(param_2 + 0x88),
               (char)*(undefined8 *)(param_2 + 0xb0),(char)*(undefined4 *)(param_2 + 0xa0),
               (char)*(undefined4 *)(param_2 + 0xa4),(char)*(undefined4 *)(param_2 + 0xa8),
               (char)*(undefined4 *)(param_2 + 0xac));
  }
  for (puVar2 = *(undefined8 **)(param_2 + 0x10); puVar2 != (undefined8 *)(param_2 + 0x10);
      puVar2 = (undefined8 *)*puVar2) {
    pcVar3 = "TRUE";
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      if (*(char *)(puVar2 + 2) == '\0') {
        pcVar3 = "FALSE";
      }
      pwVar7 = L"NONE";
      if ((wchar_t *)puVar2[4] != (wchar_t *)0x0) {
        pwVar7 = (wchar_t *)puVar2[4];
      }
      WPP_SF_Ss(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),pcVar3,pcVar6,pwVar7,pcVar3);
    }
  }
  pcVar3 = "TRUE";
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar3 = (char *)0x157;
    WPP_SF_(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x157);
  }
  for (puVar2 = *(undefined8 **)(param_2 + 0x30); puVar2 != (undefined8 *)(param_2 + 0x30);
      puVar2 = (undefined8 *)*puVar2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pwVar7 = L"NONE";
      if ((wchar_t *)puVar2[4] != (wchar_t *)0x0) {
        pwVar7 = (wchar_t *)puVar2[4];
      }
      WPP_SF_Si(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar3,pcVar6,pwVar7,
                (byte)param_1 ^ (byte)puVar2[2]);
    }
  }
  return 0;
}



===== MountMgrTracelogCache @ 14001044c =====

undefined8 MountMgrTracelogCache(ulonglong param_1)

{
  undefined8 *puVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x159);
  }
  MountMgrTraceDeviceExtension(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15a);
  }
  for (puVar1 = *(undefined8 **)(param_1 + 0x10); puVar1 != (undefined8 *)(param_1 + 0x10);
      puVar1 = (undefined8 *)*puVar1) {
    MountMgrTraceMountedDevice(param_1,(ulonglong)puVar1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15b);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15c);
  }
  return 0;
}



===== MountMgrUniqueIdChangeRoutine @ 14001054c =====

ulonglong MountMgrUniqueIdChangeRoutine(longlong param_1,ushort *param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  bool bVar4;
  ulonglong uVar5;
  ushort *puVar6;
  undefined2 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  code **ppcVar10;
  ushort *puVar11;
  uint local_res18;
  code *local_b8 [3];
  ushort *local_a0;
  
  puVar2 = *(undefined8 **)(param_1 + 0x98);
  bVar3 = false;
  bVar4 = false;
  puVar11 = (ushort *)0x0;
  uVar5 = WaitForRemoteDatabaseSemaphore((longlong)puVar2);
  local_res18 = (uint)uVar5;
  uVar5 = uVar5 & 0xffffffff;
  if ((int)local_res18 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,param_3,local_res18);
    }
  }
  else {
    bVar3 = true;
    bVar4 = true;
  }
  KeWaitForSingleObject(puVar2 + 7,0,0,0,0);
  memset(local_b8,0,0x70);
  ppcVar10 = local_b8;
  local_b8[0] = ChangeUniqueIdRoutine;
  local_a0 = param_2;
  RtlQueryRegistryValuesEx
            (0,L"\\Registry\\Machine\\System\\MountedDevices",ppcVar10,
             *(undefined8 *)(param_1 + 0x60),0);
  if (bVar3) {
    ppcVar10 = (code **)0x41746e4d;
    puVar6 = (ushort *)ExAllocatePool2(0x102,(ulonglong)*param_2 + 2);
    if (puVar6 != (ushort *)0x0) {
      puVar11 = *(ushort **)(param_1 + 0x60);
      *(ushort **)(param_1 + 0x60) = puVar6;
      *puVar6 = *param_2;
      memmove((void *)(*(longlong *)(param_1 + 0x60) + 2),param_2 + 1,(ulonglong)*param_2);
      puVar8 = (undefined8 *)puVar2[2];
      if (puVar8 != puVar2 + 2) {
        do {
          puVar1 = puVar8 + 4;
          puVar9 = (undefined8 *)*puVar1;
          if (puVar9 != puVar1) {
            bVar3 = false;
            do {
              if (((*(ushort *)puVar9[2] == *puVar11) &&
                  (uVar5 = RtlCompareMemory((ushort *)puVar9[2] + 1,puVar11 + 1,*puVar11),
                  uVar5 == *puVar11)) &&
                 (puVar6 = (ushort *)ExAllocatePool2(0x102,(ulonglong)*param_2 + 2,0x41746e4d),
                 puVar6 != (ushort *)0x0)) {
                bVar3 = true;
                ExFreePoolWithTag(puVar9[2],0);
                puVar9[2] = puVar6;
                *puVar6 = *param_2;
                memmove((void *)(puVar9[2] + 2),param_2 + 1,(ulonglong)*param_2);
              }
              puVar9 = (undefined8 *)*puVar9;
            } while (puVar9 != puVar1);
            uVar5 = (ulonglong)local_res18;
            if (bVar3) {
              uVar5 = ChangeRemoteDatabaseUniqueId((longlong)puVar8,puVar11,param_2);
              local_res18 = (uint)uVar5;
              uVar5 = uVar5 & 0xffffffff;
            }
          }
          puVar8 = (undefined8 *)*puVar8;
        } while (puVar8 != puVar2 + 2);
        bVar3 = bVar4;
      }
      goto LAB_1400107f8;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400107f8;
    uVar7 = 0x4d;
  }
  else {
    ReconcileThisDatabaseWithMaster(puVar2,param_1);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400107f8;
    uVar7 = 0x4c;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,ppcVar10,local_res18);
LAB_1400107f8:
  KeReleaseMutex(puVar2 + 7,0);
  if (bVar3) {
    KeReleaseSemaphore(puVar2 + 0xe,0,1);
  }
  if (puVar11 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar11,0);
  }
  return uVar5;
}



===== MountMgrUnload @ 140010860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MountMgrUnload(void)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  longlong *plVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  if (gEtwProvRegHandle != 0) {
    EtwUnregister();
    gEtwProvRegHandle = 0;
  }
  IoUnregisterShutdownNotification(gDeviceObject);
  lVar3 = *(longlong *)(gDeviceObject + 0x40);
  if (*(longlong *)(lVar3 + 0x110) != 0) {
    ExFreePoolWithTag();
    *(undefined8 *)(lVar3 + 0x110) = 0;
  }
  LOCK();
  gUnloading = 1;
  UNLOCK();
  KeInitializeEvent(&gUnloadEvent);
  LOCK();
  piVar1 = (int *)(lVar3 + 0xf8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 < 1) {
    LOCK();
    *(int *)(lVar3 + 0xf8) = *(int *)(lVar3 + 0xf8) + -1;
    UNLOCK();
  }
  else {
    KeReleaseSemaphore(lVar3 + 0xd8);
    local_18 = 0;
    KeWaitForSingleObject(&gUnloadEvent);
  }
  IoUnregisterPlugPlayNotification(*(undefined8 *)(lVar3 + 0x30));
  local_18 = 0;
  uVar12 = 0;
  uVar11 = 0;
  uVar7 = 0;
  KeWaitForSingleObject(lVar3 + 0x38);
  puVar10 = auStack_38;
  plVar8 = (longlong *)(lVar3 + 0x20);
  while (plVar4 = (longlong *)*plVar8, plVar4 != plVar8) {
    if (((longlong *)plVar4[1] != plVar8) ||
       (lVar5 = *plVar4, (longlong *)*(longlong *)(lVar5 + 8) != plVar4)) goto LAB_1400109fa;
    *plVar8 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar8;
    MountMgrFreeDeadDeviceInfo((longlong)plVar4);
  }
  plVar8 = (longlong *)(lVar3 + 0x10);
  while (plVar4 = (longlong *)*plVar8, plVar4 != plVar8) {
    if (((longlong *)plVar4[1] != plVar8) ||
       (lVar5 = *plVar4, (longlong *)*(longlong *)(lVar5 + 8) != plVar4)) goto LAB_1400109fa;
    *plVar8 = lVar5;
    uVar7 = 0;
    *(longlong **)(lVar5 + 8) = plVar8;
    MountMgrFreeMountedDeviceInfo((longlong)plVar4,0,uVar11,uVar12);
  }
  plVar8 = (longlong *)(lVar3 + 0xb0);
  while (plVar4 = (longlong *)*plVar8, plVar4 != plVar8) {
    if (((longlong *)plVar4[1] != plVar8) ||
       (lVar5 = *plVar4, (longlong *)*(longlong *)(lVar5 + 8) != plVar4)) goto LAB_1400109fa;
    *plVar8 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar8;
    MountMgrFreeSavedLink((longlong)plVar4,uVar7,uVar11,uVar12);
  }
LAB_140010a01:
  uVar7 = 0;
  *(undefined8 *)(puVar10 + -8) = 0x140010a0d;
  KeReleaseMutex(lVar3 + 0x38);
  *(undefined8 *)(puVar10 + -8) = 0x140010a1f;
  PsFreeSiloContextSlot(gSiloSlot);
  *(undefined8 *)(puVar10 + -8) = 0x140010a30;
  GlobalDeleteSymbolicLink((undefined1 (*) [16])&DAT_140009078,uVar7,uVar11,uVar12);
  *(undefined8 *)(puVar10 + -8) = 0x140010a3e;
  IoDeleteDevice(gDeviceObject);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar9 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar9 != (undefined *)0x0; puVar9 = *(undefined **)(puVar9 + 0x10)) {
        if (*(longlong *)(puVar9 + 0x38) != 0) {
          *(undefined8 *)(puVar10 + -8) = 0x140010aac;
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar9 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      *(undefined8 *)(puVar10 + -8) = 0x140010a75;
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  *(undefined8 *)(puVar10 + -8) = 0x140010a86;
  wil_UninitializeFeatureStaging();
  return;
LAB_1400109fa:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar10 = auStack_30;
  goto LAB_140010a01;
}



===== MountMgrVolumeArrivalNotification @ 140010ac4 =====

int MountMgrVolumeArrivalNotification(undefined **param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  ushort *puVar7;
  undefined8 local_res10;
  longlong local_res18;
  ulonglong local_28;
  ushort *puStack_20;
  
  local_res18 = 0;
  puVar7 = *(ushort **)(param_2 + 0x18);
  local_res10 = 0;
  local_28 = 0;
  puStack_20 = (ushort *)0x0;
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (uVar2 < 4) {
    iVar4 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140010c41;
    uVar6 = 0x128;
LAB_140010b2f:
    iVar4 = -0x3ffffff3;
  }
  else {
    uVar1 = *puVar7;
    if (uVar2 < uVar1 + 2) {
      iVar4 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140010c41;
      uVar6 = 0x129;
      goto LAB_140010b2f;
    }
    puStack_20 = puVar7 + 1;
    local_28 = (ulonglong)CONCAT22(uVar1,uVar1);
    uVar3 = PsGetThreadHardErrorsAreDisabled(SystemReserved1[0xf]);
    PsSetThreadHardErrorsAreDisabled(SystemReserved1[0xf],1);
    puVar7 = (ushort *)&local_res10;
    iVar4 = OpenDevice(&local_28,&local_res18,(undefined8 *)puVar7);
    if (-1 < iVar4) {
      puVar7 = (ushort *)CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
      uVar5 = MountMgrMountedDeviceArrival(param_1,&local_28,'\x01');
      iVar4 = (int)uVar5;
      ObfDereferenceObject(local_res10);
      ObfDereferenceObject(local_res18);
    }
    PsSetThreadHardErrorsAreDisabled(SystemReserved1[0xf],uVar3);
    if (((-1 < iVar4) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140010c41;
    uVar6 = 0x12a;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar7,iVar4);
LAB_140010c41:
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== MountMgrVolumeMountPointChanged @ 140010c74 =====

int MountMgrVolumeMountPointChanged
              (undefined8 *param_1,longlong param_2,int param_3,undefined8 param_4,ushort *param_5,
              ushort *param_6)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  ushort *puVar6;
  int iVar7;
  undefined8 uVar8;
  ushort *_Dst;
  longlong lVar9;
  undefined2 uVar10;
  uint uVar11;
  ulonglong *puVar12;
  ushort *puVar13;
  ulonglong uVar14;
  longlong lVar15;
  uint uVar16;
  longlong local_res10;
  int local_res18;
  undefined8 local_res20;
  undefined4 uVar18;
  longlong *plVar17;
  uint local_110 [2];
  undefined8 local_108;
  longlong local_100;
  ulonglong local_f8;
  ushort *local_f0;
  longlong local_e8;
  ushort local_e0 [4];
  longlong lStack_d8;
  ushort local_d0;
  ushort local_ce;
  undefined4 local_cc;
  longlong local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  longlong local_a8;
  ulonglong local_90 [2];
  ushort *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  local_f0 = *(ushort **)(param_2 + 0x18);
  local_108 = 0;
  local_70 = 0;
  uStack_68 = uStack_68 & 0xffffffff00000000;
  puVar13 = local_f0 + 1;
  puVar1 = local_f0 + 3;
  local_110[0] = 0;
  local_90[0] = 0;
  local_90[1] = 0;
  local_b0 = 0;
  iVar7 = 0;
  local_80 = (ushort *)0x0;
  uStack_78 = 0;
  local_f8 = 0;
  _Dst = (ushort *)0x0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_a8 = 0;
  bVar4 = false;
  local_e0[0] = 0;
  local_e0[1] = 0;
  local_e0[2] = 0;
  local_e0[3] = 0;
  lStack_d8 = 0;
  local_100 = 0;
  local_60 = 0;
  uStack_58 = 0;
  uVar16 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  puVar2 = local_f0 + 2;
  local_e8 = 0;
  local_cc = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  if (uVar16 < 8) {
LAB_140010d3d:
    iVar7 = -0x3ffffff3;
    puVar12 = (ulonglong *)WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xee,WPP_GLOBAL_Control,0xc000000d);
    }
  }
  else {
    uVar11 = (uint)*puVar2 + (uint)*puVar1;
    uVar3 = (uint)*puVar13 + (uint)*local_f0;
    if ((uint)*puVar13 + (uint)*local_f0 <= uVar11) {
      uVar3 = uVar11;
    }
    puVar12 = (ulonglong *)(ulonglong)uVar11;
    if (uVar16 < uVar3) goto LAB_140010d3d;
  }
  uVar16 = 0;
  KeReleaseMutex(param_1 + 7,0);
  puVar6 = local_f0;
  if (iVar7 < 0) {
    lVar15 = 0;
    goto LAB_140011141;
  }
  local_e0[1] = *puVar13;
  local_e0[0] = *puVar13;
  lStack_d8 = (ulonglong)*local_f0 + (longlong)local_f0;
  uVar8 = RtlUnicodeStringValidateEx(local_e0);
  iVar7 = (int)uVar8;
  if (iVar7 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar10 = 0xef;
LAB_140010f19:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,puVar12,iVar7);
    }
LAB_140010f22:
    lVar15 = 0;
    bVar4 = false;
  }
  else {
    local_d0 = *puVar1;
    local_c8 = (ulonglong)*puVar2 + (longlong)puVar6;
    local_ce = local_d0;
    uVar8 = RtlUnicodeStringValidateEx(&local_d0);
    iVar7 = (int)uVar8;
    if (iVar7 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar10 = 0xf0;
        goto LAB_140010f19;
      }
      goto LAB_140010f22;
    }
    local_90[1] = 0;
    local_80 = local_e0;
    puVar12 = local_90;
    local_90[0] = CONCAT44(local_90[0]._4_4_,0x30);
    uStack_78 = CONCAT44(uStack_78._4_4_,0x240);
    local_70 = 0;
    uStack_68 = 0;
    iVar7 = ZwOpenFile(&local_108,0x100080,puVar12,&local_c0,7,0x200020);
    if (iVar7 < 0) {
      local_108 = 0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar10 = 0xf1;
        goto LAB_140010f19;
      }
      goto LAB_140010f22;
    }
    puVar12 = &local_f8;
    iVar7 = ZwQueryVolumeInformationFile(local_108,&local_c0,puVar12,8,4);
    if (iVar7 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar10 = 0xf2;
        goto LAB_140010f19;
      }
      goto LAB_140010f22;
    }
    if ((((int)local_f8 != 7) && ((int)local_f8 != 0x24)) || ((local_f8 & 0x1100000000) != 0)) {
      iVar7 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar10 = 0xf3;
        iVar7 = -0x3ffffff3;
        goto LAB_140010f19;
      }
      goto LAB_140010f22;
    }
    local_res10 = 0;
    plVar17 = &local_res10;
    iVar7 = ObReferenceObjectByHandle(local_108,0,*(undefined8 *)IoFileObjectType_exref,0,plVar17,0)
    ;
    lVar15 = local_res10;
    uVar18 = (undefined4)((ulonglong)plVar17 >> 0x20);
    if (-1 < iVar7) {
      uVar16 = 8;
      _Dst = (ushort *)ExAllocatePool2(0x102,8);
      if (_Dst == (ushort *)0x0) {
        iVar7 = -0x3fffff66;
        bVar4 = true;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          uVar10 = 0xf4;
LAB_140011000:
          iVar7 = -0x3fffff66;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10);
          bVar4 = true;
        }
      }
      else {
        uVar8 = CONCAT44(uVar18,9);
        puVar13 = _Dst;
        iVar7 = ZwQueryInformationFile(local_108,&local_c0,_Dst,8,uVar8);
        uVar18 = (undefined4)((ulonglong)uVar8 >> 0x20);
        if (iVar7 == -0x7ffffffb) {
          uVar16 = *(int *)_Dst + 8;
          ExFreePoolWithTag(_Dst,0);
          _Dst = (ushort *)ExAllocatePool2(0x102,uVar16);
          if (_Dst != (ushort *)0x0) goto LAB_1400110dc;
          iVar7 = -0x3fffff66;
          bVar4 = true;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            uVar10 = 0xf5;
            goto LAB_140011000;
          }
        }
        else if (iVar7 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf6,puVar13,iVar7);
          }
          bVar4 = true;
        }
        else {
LAB_1400110dc:
          puVar13 = _Dst;
          iVar7 = ZwQueryInformationFile(local_108,&local_c0,_Dst,uVar16,CONCAT44(uVar18,9));
          bVar4 = true;
          bVar5 = true;
          if (((iVar7 < 0) &&
              (bVar4 = bVar5, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf7,puVar13,iVar7);
          }
        }
      }
    }
  }
LAB_140011141:
  CloseFileHandleOutsideExtensionMutexLock(0,local_108);
  if (iVar7 < 0) {
LAB_14001120b:
    lVar9 = local_100;
  }
  else {
    uVar8 = 0x10;
    iVar7 = ObQueryNameString(*(undefined8 *)(lVar15 + 8),&local_60,0x10,local_110);
    uVar3 = local_110[0];
    if (iVar7 == -0x3ffffffc) {
      uVar14 = 0x41746e4d;
      lVar9 = ExAllocatePool2(0x102,local_110[0]);
      uVar16 = uVar3;
      if (lVar9 != 0) goto LAB_140011281;
      iVar7 = -0x3fffff66;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140011210;
      uVar10 = 0xf8;
      iVar7 = -0x3fffff66;
    }
    else {
      if (iVar7 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf9,uVar8,iVar7);
        }
        goto LAB_14001120b;
      }
      lVar9 = local_100;
LAB_140011281:
      uVar14 = (ulonglong)uVar16;
      iVar7 = ObQueryNameString(*(undefined8 *)(lVar15 + 8),lVar9,uVar14,local_110);
      if (((-1 < iVar7) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140011210;
      uVar10 = 0xfa;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,uVar14,iVar7);
  }
LAB_140011210:
  uVar8 = 0;
  KeWaitForSingleObject(param_1 + 7,0,0,0,0);
  if (iVar7 < 0) goto LAB_1400113d0;
  iVar7 = QueryDeviceName(lVar9,local_res20);
  if (iVar7 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400113d0;
    uVar10 = 0xfb;
  }
  else {
    *param_6 = puVar6[3];
    param_6[1] = puVar6[3];
    *(ulonglong *)(param_6 + 4) = (ulonglong)puVar6[2] + (longlong)puVar6;
    iVar7 = QueryDeviceName(param_6,&local_b0);
    if (iVar7 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400113d0;
      uVar10 = 0xfc;
    }
    else {
      uVar14 = (ulonglong)*_Dst;
      *param_5 = *_Dst;
      param_5[1] = *_Dst;
      *(ushort **)(param_5 + 4) = _Dst;
      memmove(_Dst,_Dst + 2,uVar14);
      _Dst = (ushort *)0x0;
      MountMgrNotify((longlong)param_1);
      uVar8 = CONCAT71((int7)(uVar14 >> 8),1);
      MountMgrNotifyNameChange((longlong)param_1,&local_b0,'\x01');
      if (-1 < local_res18) goto LAB_1400113d0;
      iVar7 = FindDeviceInfo((longlong)param_1,local_res20,uVar8,&local_e8);
      if (-1 < iVar7) {
        ReconcileThisDatabaseWithMaster(param_1,local_e8);
        iVar7 = 0x103;
        goto LAB_1400113d0;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1400113d0;
      uVar10 = 0xfd;
    }
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,uVar8,iVar7);
LAB_1400113d0:
  if (local_a8 != 0) {
    ExFreePoolWithTag(local_a8,0);
  }
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0);
  }
  if (_Dst != (ushort *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  if (bVar4) {
    ObfDereferenceObject(lVar15);
  }
  return iVar7;
}



===== MountMgrVolumeMountPointCreated @ 140011444 =====

ulonglong MountMgrVolumeMountPointCreated(undefined8 *param_1,longlong param_2,uint param_3)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  uint *puVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *plVar9;
  void *_Dst;
  longlong lVar10;
  undefined2 uVar11;
  ushort *puVar12;
  longlong *plVar13;
  char *pcVar14;
  char *pcVar15;
  uint *puVar16;
  longlong lVar17;
  char local_res20 [8];
  ushort *local_e8;
  uint local_e0;
  longlong local_d8;
  longlong local_d0;
  uint *local_c8;
  ushort *local_c0;
  ushort local_b8 [4];
  void *pvStack_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  longlong local_98;
  longlong local_90;
  ulonglong local_88;
  void *pvStack_80;
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  longlong lStack_60;
  uint *local_58;
  ushort local_50 [4];
  longlong lStack_48;
  
  local_res20[0] = '\0';
  local_d8 = 0;
  local_98 = 0;
  local_c8 = (uint *)0x0;
  pcVar15 = (char *)(ulonglong)param_3;
  local_e8 = (ushort *)0x0;
  local_c0 = (ushort *)0x0;
  lStack_70 = 0;
  local_d0 = 0;
  local_78 = 0xc80000;
  pcVar14 = (char *)0x41746e4d;
  plVar9 = (longlong *)0x0;
  local_a8 = 0;
  lStack_a0 = 0;
  local_88 = 0;
  pvStack_80 = (void *)0x0;
  local_b8[0] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  pvStack_b0 = (void *)0x0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  lStack_48 = 0;
  local_68 = 0;
  lStack_60 = 0;
  lStack_70 = ExAllocatePool2(0x102);
  if (lStack_70 == 0) {
    uVar3 = 0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar11 = 0x100;
      pcVar15 = pcVar14;
LAB_14001150e:
      uVar3 = 0xc000009a;
      goto LAB_14001184c;
    }
  }
  else {
    uVar3 = MountMgrVolumeMountPointChanged
                      (param_1,param_2,param_3,&local_a8,(ushort *)&local_88,local_b8);
    if (uVar3 == 0x103) {
      uVar3 = 0;
    }
    else if ((int)uVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar11 = 0x101;
        goto LAB_14001184c;
      }
    }
    else {
      iVar4 = FindDeviceInfo((longlong)param_1,&local_a8,pcVar15,&local_d8);
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x102,pcVar15,iVar4);
        }
        pcVar15 = (char *)0x0;
        uVar5 = QueryVolumeName((longlong)param_1,0,0,0,&local_a8,(ushort *)&local_78,local_50);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x103,pcVar15,(int)uVar5);
        }
        if (((int)uVar5 < 0) &&
           (uVar3 = MountMgrQuerySymbolicLink(&local_a8,(ushort *)&local_78), (int)uVar3 < 0)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar11 = 0x104;
            goto LAB_14001184c;
          }
        }
        else {
          ExFreePoolWithTag(lStack_a0,0);
          local_a8 = local_78;
          lStack_a0 = lStack_70;
          lStack_70 = 0;
          uVar3 = FindDeviceInfo((longlong)param_1,&local_a8,pcVar15,&local_d8);
          if (-1 < (int)uVar3) goto LAB_1400116c1;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar11 = 0x105;
            goto LAB_14001184c;
          }
        }
      }
      else {
LAB_1400116c1:
        puVar12 = local_b8;
        uVar3 = FindDeviceInfo((longlong)param_1,puVar12,pcVar15,&local_98);
        lVar17 = local_98;
        if ((int)uVar3 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar11 = 0x106;
LAB_14001184c:
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,pcVar15,uVar3);
          }
        }
        else {
          if (*(char *)(local_98 + 0x85) == '\0') {
            puVar12 = (ushort *)(local_98 + 0x40);
            PostOnlineNotification((longlong)param_1,(short *)puVar12);
          }
          lVar10 = local_d8;
          local_90 = param_1[0x2a];
          pcVar15 = local_res20;
          local_58 = *(uint **)(lVar17 + 0xb0);
          uVar5 = OpenRemoteDatabase(local_d8,CONCAT71((int7)((ulonglong)puVar12 >> 8),1),pcVar15,
                                     &local_d0);
          uVar3 = (uint)uVar5;
          if (local_res20[0] == '\0') {
            if (local_d0 == 0) {
              uVar3 = 0xc000009a;
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400118ae;
              uVar11 = 0x108;
              goto LAB_14001150e;
            }
            local_e0 = 0;
            pcVar15 = (char *)0x0;
            while( true ) {
              uVar5 = GetRemoteDatabaseEntry(lVar10,local_d0,(uint)pcVar15,(longlong *)&local_c8);
              puVar16 = local_c8;
              uVar3 = (uint)uVar5;
              if ((int)uVar3 < 0) break;
              if (local_c8 == (uint *)0x0) {
                uVar3 = QueryUniqueId(local_b8,&local_c0);
                local_e8 = local_c0;
                if ((int)uVar3 < 0) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10a,pcVar15,uVar3);
                  }
                  local_e8 = local_c0;
                }
                else {
                  puVar16 = (uint *)0x41746e4d;
                  uVar3 = local_b8[0] + 0x10 + (uint)*local_c0;
                  puVar6 = (uint *)ExAllocatePool2(0x102,uVar3);
                  local_c8 = puVar6;
                  if (puVar6 == (uint *)0x0) {
                    uVar3 = 0xc000009a;
                    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001185a;
                    uVar11 = 0x10b;
                  }
                  else {
                    *puVar6 = uVar3;
                    puVar6[1] = 1;
                    *(undefined2 *)(puVar6 + 2) = 0x10;
                    *(ushort *)((longlong)puVar6 + 10) = local_b8[0];
                    *(ushort *)(puVar6 + 3) = local_b8[0] + (short)puVar6[2];
                    *(ushort *)((longlong)puVar6 + 0xe) = *local_e8;
                    memmove((void *)((ulonglong)(ushort)puVar6[2] + (longlong)puVar6),pvStack_b0,
                            (ulonglong)*(ushort *)((longlong)puVar6 + 10));
                    memmove((void *)((ulonglong)(ushort)puVar6[3] + (longlong)puVar6),local_e8 + 1,
                            (ulonglong)*(ushort *)((longlong)puVar6 + 0xe));
                    uVar5 = AddRemoteDatabaseEntry(local_d8,local_d0,puVar6);
                    uVar3 = (uint)uVar5;
                    ExFreePoolWithTag(local_c8,0);
                    if ((int)uVar3 < 0) {
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                        uVar11 = 0x10c;
                        goto LAB_140011aad;
                      }
                      goto LAB_14001185a;
                    }
                    puVar6 = (uint *)0x41746e4d;
                    plVar7 = (longlong *)ExAllocatePool2(0x102,0x18);
                    if (plVar7 != (longlong *)0x0) {
                      plVar7[2] = (longlong)local_e8;
                      plVar13 = *(longlong **)(local_d8 + 0x28);
                      if (*plVar13 == local_d8 + 0x20) {
                        *plVar7 = local_d8 + 0x20;
                        plVar7[1] = (longlong)plVar13;
                        *plVar13 = (longlong)plVar7;
                        *(longlong **)(local_d8 + 0x28) = plVar7;
                        goto LAB_140011b2d;
                      }
                      goto LAB_140011d45;
                    }
                    uVar3 = 0xc000009a;
                    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001185a;
                    uVar11 = 0x10d;
                    puVar16 = puVar6;
                  }
                  uVar3 = 0xc000009a;
LAB_140011a01:
                  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,puVar16,uVar3);
                }
                goto LAB_14001185a;
              }
              local_68 = CONCAT62(CONCAT42(local_68._4_4_,*(undefined2 *)((longlong)local_c8 + 10)),
                                  *(undefined2 *)((longlong)local_c8 + 10));
              lStack_60 = (ulonglong)(ushort)local_c8[2] + (longlong)local_c8;
              cVar2 = RtlEqualUnicodeString(local_b8,&local_68,1);
              if (cVar2 != '\0') {
                puVar16[1] = puVar16[1] + 1;
                puVar6 = (uint *)(ulonglong)local_e0;
                uVar5 = WriteRemoteDatabaseEntry(local_d8,local_d0,(ulonglong)puVar6,puVar16);
                uVar3 = (uint)uVar5;
                ExFreePoolWithTag(puVar16,0);
LAB_140011b2d:
                local_e8 = (ushort *)0x0;
                CloseFileHandleOutsideExtensionMutexLock((longlong)param_1,local_d0);
                local_d0 = 0;
                if ((int)uVar3 < 0) {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400118ae;
                  uVar11 = 0x10e;
                }
                else {
                  puVar6 = local_58;
                  uVar8 = VerifyEpoch((longlong)param_1,local_90,(longlong)local_58);
                  uVar3 = (uint)uVar8;
                  if (-1 < (int)uVar3) {
                    plVar9 = (longlong *)ExAllocatePool2(0x102,0x28,0x41746e4d);
                    if (plVar9 == (longlong *)0x0) {
                      uVar3 = 0xc000009a;
                      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_14001185a;
                      uVar11 = 0x111;
                    }
                    else {
                      *(short *)(plVar9 + 3) = (short)local_88;
                      *(short *)((longlong)plVar9 + 0x1a) = (short)local_88 + 2;
                      _Dst = (void *)ExAllocatePool2(0x102,(short)local_88 + 2,0x41746e4d);
                      plVar9[4] = (longlong)_Dst;
                      if (_Dst != (void *)0x0) {
                        memmove(_Dst,pvStack_80,local_88 & 0xffff);
                        *(undefined2 *)(plVar9[4] + (local_88 >> 1 & 0x7fff) * 2) = 0;
                        plVar9[2] = local_d8;
                        plVar7 = (longlong *)(lVar17 + 0x30);
                        plVar13 = (longlong *)*plVar7;
                        if (plVar13 == plVar7) goto LAB_140011cfa;
                        goto LAB_140011cc3;
                      }
                      uVar3 = 0xc000009a;
                      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_14001185a;
                      uVar11 = 0x112;
                    }
                    uVar3 = 0xc000009a;
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11);
                    goto LAB_14001185a;
                  }
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001185a;
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
                     (WPP_GLOBAL_Control[0x29] != '\0')) {
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10f);
                  }
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001185a;
                  uVar11 = 0x110;
                }
LAB_140011aad:
                puVar16 = puVar6;
                goto LAB_140011a01;
              }
              local_e0 = local_e0 + *puVar16;
              ExFreePoolWithTag(puVar16,0);
              pcVar15 = (char *)(ulonglong)local_e0;
              lVar10 = local_d8;
            }
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar11 = 0x109;
              goto LAB_14001184c;
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar11 = 0x107;
            goto LAB_14001184c;
          }
        }
      }
    }
  }
  goto LAB_14001185a;
  while (plVar13 = (longlong *)*plVar13, plVar13 != plVar7) {
LAB_140011cc3:
    if ((plVar13[2] == plVar9[2]) &&
       (cVar2 = RtlEqualUnicodeString(plVar13 + 3,plVar9 + 3,1), cVar2 != '\0')) break;
  }
  lVar17 = local_98;
LAB_140011cfa:
  if (plVar13 == (longlong *)(lVar17 + 0x30)) {
    plVar7 = *(longlong **)(lVar17 + 0x38);
    if (*plVar7 != lVar17 + 0x30) {
LAB_140011d45:
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(3);
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    *plVar9 = lVar17 + 0x30;
    plVar9[1] = (longlong)plVar7;
    *plVar7 = (longlong)plVar9;
    *(longlong **)(lVar17 + 0x38) = plVar9;
    plVar9 = (longlong *)0x0;
    lVar10 = param_1[0x2a];
    param_1[0x2a] = lVar10 + 1;
    *(longlong *)(lVar17 + 0xb0) = lVar10 + 1;
  }
LAB_14001185a:
  if (local_d0 != 0) {
    CloseFileHandleOutsideExtensionMutexLock((longlong)param_1,local_d0);
  }
  if (plVar9 != (longlong *)0x0) {
    if (plVar9[4] != 0) {
      ExFreePoolWithTag(plVar9[4],0);
    }
    ExFreePoolWithTag(plVar9,0);
  }
  if (local_e8 != (ushort *)0x0) {
    ExFreePoolWithTag(local_e8,0);
  }
LAB_1400118ae:
  if (lStack_48 != 0) {
    ExFreePoolWithTag(lStack_48,0);
  }
  if (pvStack_80 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_80,0);
  }
  if (lStack_a0 != 0) {
    ExFreePoolWithTag(lStack_a0,0);
  }
  if (lStack_70 != 0) {
    ExFreePoolWithTag(lStack_70,0);
  }
  return (ulonglong)uVar3;
}



===== MountMgrVolumeMountPointCreatedIoctl @ 140011d54 =====

ulonglong MountMgrVolumeMountPointCreatedIoctl
                    (undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar2 = WaitForRemoteDatabaseSemaphore((longlong)param_1);
  uVar1 = (uint)uVar2;
  if (((((int)uVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15d,param_3,uVar1);
  }
  KeWaitForSingleObject(param_1 + 7,0,0,0,0);
  uVar2 = uVar2 & 0xffffffff;
  uVar3 = MountMgrVolumeMountPointCreated(param_1,param_2,uVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15e,uVar2,(int)uVar3);
  }
  if (-1 < (int)uVar1) {
    KeReleaseSemaphore(param_1 + 0xe,0,1);
  }
  return uVar3 & 0xffffffff;
}



===== MountMgrVolumeMountPointDeleted @ 140011e40 =====

int MountMgrVolumeMountPointDeleted(undefined8 *param_1,longlong param_2,uint param_3)

{
  uint *puVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 *puVar6;
  char cVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined2 uVar13;
  ushort *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  longlong *plVar18;
  char *pcVar19;
  longlong lVar20;
  uint *puVar21;
  char local_res20 [8];
  undefined1 auStackY_108 [8];
  undefined1 auStackY_100 [24];
  longlong local_c8;
  ulonglong local_c0;
  uint *local_b8 [2];
  undefined8 local_a8;
  longlong lStack_a0;
  longlong local_98 [2];
  undefined8 local_88;
  longlong lStack_80;
  longlong *local_78;
  longlong local_70;
  undefined8 local_68;
  longlong lStack_60;
  ushort local_58 [8];
  undefined8 local_48;
  longlong lStack_40;
  ushort local_38 [4];
  longlong lStack_30;
  
  local_res20[0] = '\0';
  local_98[0] = 0;
  local_c0 = 0;
  pcVar19 = (char *)(ulonglong)param_3;
  local_c8 = 0;
  local_b8[0] = (uint *)0x0;
  lStack_80 = 0;
  local_78 = (longlong *)0x0;
  local_88 = 0xc80000;
  local_a8 = 0;
  lStack_a0 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  lStack_30 = 0;
  local_68 = 0;
  lStack_60 = 0;
  lStack_80 = ExAllocatePool2(0x102,200,0x41746e4d);
  if (lStack_80 == 0) {
    iVar8 = -0x3fffff66;
    puVar15 = auStackY_108;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x113);
      puVar15 = auStackY_108;
    }
  }
  else {
    iVar8 = MountMgrVolumeMountPointChanged
                      (param_1,param_2,param_3,&local_a8,(ushort *)&local_48,local_58);
    if (iVar8 == 0x103) {
      iVar8 = 0;
      puVar15 = auStackY_108;
    }
    else {
      if (iVar8 < 0) {
        puVar15 = auStackY_108;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
        goto LAB_140012204;
        uVar13 = 0x114;
      }
      else {
        iVar8 = FindDeviceInfo((longlong)param_1,&local_a8,pcVar19,local_98);
        if (iVar8 < 0) {
          pcVar19 = (char *)0x0;
          uVar9 = QueryVolumeName((longlong)param_1,0,0,0,&local_a8,(ushort *)&local_88,local_38);
          if ((int)uVar9 < 0) {
            iVar8 = MountMgrQuerySymbolicLink(&local_a8,(ushort *)&local_88);
            if (iVar8 < 0) {
              puVar15 = auStackY_108;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                uVar13 = 0x115;
                goto LAB_140011f65;
              }
              goto LAB_140012204;
            }
          }
          ExFreePoolWithTag(lStack_a0,0);
          local_a8 = local_88;
          lStack_a0 = lStack_80;
          lStack_80 = 0;
          iVar8 = FindDeviceInfo((longlong)param_1,&local_a8,pcVar19,local_98);
          if (iVar8 < 0) {
            puVar15 = auStackY_108;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar13 = 0x116;
              goto LAB_140011f65;
            }
            goto LAB_140012204;
          }
        }
        puVar14 = local_58;
        iVar8 = FindDeviceInfo((longlong)param_1,puVar14,pcVar19,&local_c0);
        lVar3 = local_98[0];
        if (iVar8 < 0) {
          puVar15 = auStackY_108;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
          goto LAB_140012204;
          uVar13 = 0x117;
        }
        else {
          lVar20 = param_1[0x2a];
          pcVar19 = local_res20;
          local_c0 = *(ulonglong *)(local_c0 + 0xb0);
          local_70 = lVar20;
          uVar9 = OpenRemoteDatabase(local_98[0],CONCAT71((int7)((ulonglong)puVar14 >> 8),1),pcVar19
                                     ,&local_c8);
          puVar15 = auStackY_108;
          puVar16 = auStackY_108;
          iVar8 = (int)uVar9;
          if (local_res20[0] == '\0') {
            if (local_c8 != 0) {
              uVar9 = 0;
              uVar11 = 0;
              while( true ) {
                uVar10 = GetRemoteDatabaseEntry(lVar3,local_c8,(uint)uVar11,(longlong *)local_b8);
                puVar21 = local_b8[0];
                iVar8 = (int)uVar10;
                if (iVar8 < 0) break;
                puVar6 = auStackY_108;
                if (local_b8[0] == (uint *)0x0) goto LAB_140012589;
                local_68 = CONCAT62(CONCAT42(local_68._4_4_,
                                             *(undefined2 *)((longlong)local_b8[0] + 10)),
                                    *(undefined2 *)((longlong)local_b8[0] + 10));
                lStack_60 = (ulonglong)(ushort)local_b8[0][2] + (longlong)local_b8[0];
                cVar7 = RtlEqualUnicodeString(local_58,&local_68,1);
                if (cVar7 != '\0') {
                  puVar1 = puVar21 + 1;
                  *puVar1 = *puVar1 - 1;
                  if (*puVar1 != 0) {
                    uVar11 = WriteRemoteDatabaseEntry(lVar3,local_c8,uVar9,puVar21);
                    iVar8 = (int)uVar11;
                    goto LAB_1400123d2;
                  }
                  uVar11 = DeleteRemoteDatabaseEntry(lVar3,local_c8,uVar9);
                  iVar8 = (int)uVar11;
                  if (-1 < iVar8) {
                    plVar18 = *(longlong **)(lVar3 + 0x20);
                    goto LAB_140012334;
                  }
                  puVar15 = auStackY_108;
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
                  goto LAB_1400121ee;
                  uVar13 = 0x11c;
                  goto LAB_1400125bb;
                }
                uVar17 = (int)uVar9 + *puVar21;
                uVar9 = (ulonglong)uVar17;
                ExFreePoolWithTag(puVar21,0);
                local_b8[0] = (uint *)0x0;
                uVar11 = (ulonglong)uVar17;
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11a,uVar11,iVar8);
              }
              puVar15 = auStackY_108;
              puVar21 = local_b8[0];
              goto LAB_1400121ee;
            }
            iVar8 = -0x3fffff66;
            puVar15 = auStackY_108;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
            goto LAB_140012215;
            uVar13 = 0x119;
            iVar8 = -0x3fffff66;
          }
          else {
            puVar15 = auStackY_108;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
            goto LAB_140012204;
            uVar13 = 0x118;
          }
        }
      }
LAB_140011f65:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,pcVar19,iVar8);
      puVar15 = auStackY_108;
    }
  }
  goto LAB_140012204;
LAB_140012334:
  if (plVar18 == (longlong *)(lVar3 + 0x20)) goto LAB_140012339;
  local_78 = plVar18;
  if (plVar18 == (longlong *)0x0) goto LAB_140012377;
  if (*(ushort *)plVar18[2] == *(ushort *)((longlong)puVar21 + 0xe)) {
    uVar9 = (ulonglong)*(ushort *)((longlong)puVar21 + 0xe);
    uVar11 = RtlCompareMemory((ushort *)plVar18[2] + 1,
                              (ulonglong)(ushort)puVar21[3] + (longlong)puVar21);
    if (uVar11 == *(ushort *)((longlong)puVar21 + 0xe)) goto LAB_140012339;
  }
  plVar18 = (longlong *)*plVar18;
  goto LAB_140012334;
LAB_140012339:
  plVar4 = local_78;
  if (plVar18 == (longlong *)(lVar3 + 0x20)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11d,uVar9,iVar8);
    }
    iVar8 = -0x3fffffff;
    puVar15 = auStackY_108;
  }
  else {
    lVar20 = *plVar18;
    if ((*(longlong **)(lVar20 + 8) == plVar18) &&
       (plVar2 = (longlong *)plVar18[1], (longlong *)*plVar2 == plVar18)) {
      *plVar2 = lVar20;
      *(longlong **)(lVar20 + 8) = plVar2;
      if (local_78 != (longlong *)0x0) {
        ExFreePoolWithTag(local_78[2],0);
        ExFreePoolWithTag(plVar4,0);
      }
      lVar20 = local_70;
LAB_1400123d2:
      CloseFileHandleOutsideExtensionMutexLock((longlong)param_1,local_c8);
      local_c8 = 0;
      if (iVar8 < 0) {
        puVar15 = auStackY_108;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar13 = 0x11e;
          goto LAB_1400125bb;
        }
      }
      else {
        uVar9 = local_c0;
        uVar12 = VerifyEpoch((longlong)param_1,lVar20,local_c0);
        iVar8 = (int)uVar12;
        if (iVar8 < 0) {
          puVar15 = auStackY_108;
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11f);
            }
            puVar15 = auStackY_108;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar13 = 0x120;
              goto LAB_1400125bb;
            }
          }
        }
        else {
          local_c0 = 0;
          iVar8 = FindDeviceInfo((longlong)param_1,local_58,uVar9,&local_c0);
          uVar11 = local_c0;
          if (iVar8 < 0) {
            if (local_c0 == 0) goto LAB_140012551;
          }
          else {
            if (local_c0 != 0) {
              for (plVar18 = *(longlong **)(local_c0 + 0x30); plVar18 != (longlong *)(uVar11 + 0x30)
                  ; plVar18 = (longlong *)*plVar18) {
                if (plVar18 == (longlong *)0x0) goto LAB_140012377;
                if (plVar18[2] == lVar3) {
                  uVar9 = CONCAT71((int7)(uVar9 >> 8),1);
                  cVar7 = RtlEqualUnicodeString(plVar18 + 3,&local_48);
                  if (cVar7 != '\0') {
                    lVar3 = param_1[0x2a];
                    param_1[0x2a] = lVar3 + 1;
                    *(longlong *)(uVar11 + 0xb0) = lVar3 + 1;
                    lVar3 = *plVar18;
                    if ((*(longlong **)(lVar3 + 8) != plVar18) ||
                       (plVar4 = (longlong *)plVar18[1], (longlong *)*plVar4 != plVar18))
                    goto LAB_140012582;
                    *plVar4 = lVar3;
                    *(longlong **)(lVar3 + 8) = plVar4;
                    ExFreePoolWithTag(plVar18[4],0);
                    ExFreePoolWithTag(plVar18,0);
                    puVar15 = auStackY_108;
                    break;
                  }
                }
              }
              goto LAB_1400121ee;
            }
LAB_140012551:
            iVar8 = -0x3ffffd8e;
          }
          puVar15 = auStackY_108;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (puVar15 = auStackY_108, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar13 = 0x121;
            goto LAB_1400125bb;
          }
        }
      }
    }
    else {
LAB_140012582:
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStackY_100;
      uVar11 = uVar9;
LAB_140012589:
      uVar9 = uVar11;
      puVar16 = puVar6;
      iVar8 = -0x3ffffff3;
      puVar15 = puVar16;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar13 = 0x11b;
        iVar8 = -0x3ffffff3;
LAB_1400125bb:
        uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar16 + -8) = 0x1400125c4;
        WPP_SF_L(uVar12,uVar13,uVar9,iVar8);
        puVar15 = puVar16;
      }
    }
  }
  goto LAB_1400121ee;
LAB_140012377:
  iVar8 = -0x3ffffddb;
  puVar15 = auStackY_108;
LAB_1400121ee:
  if (puVar21 != (uint *)0x0) {
    *(undefined8 *)(puVar15 + -8) = 0x1400121ff;
    ExFreePoolWithTag(puVar21,0);
  }
LAB_140012204:
  if (local_c8 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x140012215;
    CloseFileHandleOutsideExtensionMutexLock((longlong)param_1,local_c8);
  }
LAB_140012215:
  if (lStack_30 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x140012227;
    ExFreePoolWithTag(lStack_30,0);
  }
  if (lStack_40 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x14001223e;
    ExFreePoolWithTag(lStack_40,0);
  }
  if (lStack_a0 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x140012255;
    ExFreePoolWithTag(lStack_a0,0);
  }
  if (lStack_80 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x14001226c;
    ExFreePoolWithTag(lStack_80,0);
  }
  return iVar8;
}



===== MountMgrVolumeMountPointDeletedIoctl @ 1400125d0 =====

int MountMgrVolumeMountPointDeletedIoctl(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = WaitForRemoteDatabaseSemaphore((longlong)param_1);
  uVar1 = (uint)uVar3;
  if (((((int)uVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15f,param_3,uVar1);
  }
  KeWaitForSingleObject(param_1 + 7,0,0,0,0);
  uVar3 = uVar3 & 0xffffffff;
  iVar2 = MountMgrVolumeMountPointDeleted(param_1,param_2,uVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x160,uVar3,iVar2);
  }
  if (-1 < (int)uVar1) {
    KeReleaseSemaphore(param_1 + 0xe,0,1);
  }
  return iVar2;
}



===== MountMgrVolumeRemovalNotification @ 1400126bc =====

int MountMgrVolumeRemovalNotification(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  int iVar6;
  ushort *puVar7;
  ulonglong local_18;
  ushort *puStack_10;
  
  puVar7 = *(ushort **)(param_2 + 0x18);
  local_18 = 0;
  puStack_10 = (ushort *)0x0;
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (uVar2 < 4) {
    iVar6 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400127f6;
    uVar5 = 0x125;
LAB_140012718:
    iVar6 = -0x3ffffff3;
  }
  else {
    uVar1 = *puVar7;
    if (uVar2 < uVar1 + 2) {
      iVar6 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400127f6;
      uVar5 = 0x126;
      goto LAB_140012718;
    }
    puStack_10 = puVar7 + 1;
    local_18 = (ulonglong)CONCAT22(uVar1,uVar1);
    uVar3 = PsGetThreadHardErrorsAreDisabled(SystemReserved1[0xf]);
    PsSetThreadHardErrorsAreDisabled(SystemReserved1[0xf],1);
    puVar7 = (ushort *)CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
    uVar4 = MountMgrMountedDeviceRemoval(param_1,&local_18,'\x01');
    iVar6 = (int)uVar4;
    PsSetThreadHardErrorsAreDisabled(SystemReserved1[0xf],uVar3);
    if (((-1 < iVar6) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400127f6;
    uVar5 = 0x127;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,puVar7,iVar6);
LAB_1400127f6:
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  return iVar6;
}



===== OnlineMountedVolumes @ 140012824 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void OnlineMountedVolumes(longlong param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStackY_178 [32];
  undefined8 local_118;
  ushort local_110;
  short local_10e;
  undefined4 local_10c;
  void *local_108;
  ushort local_100 [4];
  longlong local_f8;
  longlong local_f0;
  longlong local_e8;
  longlong local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 *local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  int iStack_b0;
  undefined4 uStack_ac;
  ushort local_a8 [4];
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  ushort *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_54;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  local_110 = DAT_140009010 + *(short *)(param_2 + 0x50);
  local_10e = local_110 + 2;
  local_e0 = 0;
  local_118 = 0;
  local_10c = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  uStack_a0 = 0;
  local_94 = 0;
  local_7c = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_100[2] = 0;
  local_100[3] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_54 = 0;
  local_d4 = 0;
  local_108 = (void *)ExAllocatePool2(0x102,local_10e,0x41746e4d);
  if (local_108 == (void *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return;
    }
    uVar7 = 0x9a;
LAB_1400128f0:
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7);
    return;
  }
  memmove(local_108,*(void **)(param_2 + 0x58),(ulonglong)*(ushort *)(param_2 + 0x50));
  memmove((void *)((ulonglong)*(ushort *)(param_2 + 0x50) + (longlong)local_108),
          PTR_u___Extend__Repar_140009018,(ulonglong)DAT_140009010);
  lVar1 = param_1 + 0x38;
  *(undefined2 *)((longlong)local_108 + (ulonglong)(local_110 >> 1) * 2) = 0;
  local_88 = &local_110;
  lVar9 = *(longlong *)(param_1 + 0x150);
  lVar8 = *(longlong *)(param_2 + 0xb0);
  local_98 = 0x30;
  local_90 = 0;
  local_80 = 0x240;
  local_78 = 0;
  uStack_70 = 0;
  local_f0 = lVar8;
  local_e8 = lVar9;
  KeReleaseMutex(lVar1,0);
  iVar3 = ZwOpenFile(&local_118,0x120089,&local_98,&local_c8);
  ExFreePoolWithTag(local_108,0);
  KeWaitForSingleObject(lVar1,0,0,0);
  uVar5 = VerifyEpoch(param_1,lVar9,lVar8);
  iVar4 = (int)uVar5;
  if (iVar4 < 0) {
    iVar3 = iVar4;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9b,lVar8,iVar4);
    }
  }
  else if (-1 < iVar3) {
    local_d0 = &local_58;
    local_54 = 0;
    local_58 = 0xa0000003;
    local_d8 = 0xc000c;
    KeReleaseMutex(lVar1);
    iVar3 = ZwQueryDirectoryFile(local_118,0,0,0);
    KeWaitForSingleObject(lVar1,0,0,0);
    lVar8 = local_f0;
    uVar5 = VerifyEpoch(param_1,local_e8,local_f0);
    iVar4 = (int)uVar5;
    if (iVar4 < 0) {
      iVar3 = iVar4;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9d,lVar8,iVar4);
      }
    }
    else if (-1 < iVar3) {
      local_100[0] = 0;
      local_100[1] = 200;
      local_f8 = ExAllocatePool2(0x102,200,0x41746e4d);
      if (local_f8 != 0) {
        bVar2 = true;
        do {
          local_b8 = (undefined4)local_68;
          uStack_b4 = local_68._4_4_;
          iStack_b0 = (int)uStack_60;
          uStack_ac = uStack_60._4_4_;
          KeReleaseMutex(lVar1,0);
          iVar4 = ZwQueryDirectoryFile(local_118,0,0,0);
          KeWaitForSingleObject(lVar1,0,0,0);
          lVar9 = local_f0;
          uVar5 = VerifyEpoch(param_1,local_e8,local_f0);
          iVar3 = (int)uVar5;
          if (iVar3 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar7 = 0xa0;
LAB_140012e06:
              WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,lVar9,iVar3);
            }
LAB_140012e0f:
            ExFreePoolWithTag(local_f8,0);
            CloseFileHandleOutsideExtensionMutexLock(param_1,local_118);
            return;
          }
          if (bVar2) {
            bVar2 = false;
          }
          else if ((CONCAT44(uStack_b4,local_b8) == local_68) && (iStack_b0 == (int)uStack_60))
          goto LAB_140012e0f;
          if (iVar4 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140012e0f;
            uVar7 = 0xa1;
            iVar3 = iVar4;
            goto LAB_140012e06;
          }
          if ((int)uStack_60 != -0x5ffffffd) goto LAB_140012e0f;
          uVar5 = local_118;
          uVar6 = QueryVolumeName(param_1,param_2,local_118,&local_68,(undefined8 *)0x0,local_100,
                                  local_a8);
          iVar3 = (int)uVar6;
          if (iVar3 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              uVar7 = 0xa2;
LAB_140012d41:
              WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,uVar5,iVar3);
            }
          }
          else {
            ExFreePoolWithTag(uStack_a0,0);
            iVar3 = FindDeviceInfo(param_1,local_100,uVar5,&local_e0);
            if (iVar3 < 0) {
              *(undefined1 *)(param_2 + 0x84) = 1;
            }
            else {
              if (*(char *)(local_e0 + 0x85) == '\0') {
                PostOnlineNotification(param_1,(short *)(local_e0 + 0x40));
              }
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                uVar7 = 0xa3;
                goto LAB_140012d41;
              }
            }
          }
        } while( true );
      }
      CloseFileHandleOutsideExtensionMutexLock(param_1,local_118);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return;
      }
      uVar7 = 0x9f;
      goto LAB_1400128f0;
    }
    CloseFileHandleOutsideExtensionMutexLock(param_1,local_118);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return;
    }
    uVar7 = 0x9e;
    goto LAB_140012a64;
  }
  *(undefined1 *)(param_2 + 0x84) = 0;
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
    return;
  }
  uVar7 = 0x9c;
LAB_140012a64:
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,lVar8,iVar3);
  return;
}



===== ProcessSuggestedDriveLetters @ 140012e5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ProcessSuggestedDriveLetters
               (undefined8 *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined1 auStack_88 [32];
  ulonglong local_68;
  wchar_t *pwStack_60;
  wchar_t local_58 [13];
  undefined2 local_3e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  puVar3 = (undefined8 *)param_1[2];
  local_68 = 0;
  pwStack_60 = (wchar_t *)0x0;
  do {
    if (puVar3 == param_1 + 2) {
      return;
    }
    uVar2 = 0;
    cVar1 = HasDriveLetter((longlong)puVar3,(undefined1 *)0x0);
    if (cVar1 == '\0') {
      cVar1 = HasNoDriveLetterEntry(puVar3[0xc]);
      if (cVar1 != '\0') goto LAB_140012f21;
      if (*(char *)(puVar3 + 0x10) == -1) {
        CreateNoDriveLetterEntry((ushort *)puVar3[0xc],uVar2,param_3);
        goto LAB_140012f2a;
      }
      if (*(char *)(puVar3 + 0x10) != '\0') {
        pwStack_60 = local_58;
        local_68 = CONCAT44(local_68._4_4_,0x1c001c);
        builtin_wcsncpy(local_58,L"\\DosDevices\\",0xc);
        local_58[0xc] = (wchar_t)*(byte *)(puVar3 + 0x10);
        local_3e = 0x3a;
        param_3 = puVar3;
        MountMgrCreatePointWorker(param_1,&local_68,(longlong)puVar3,param_4);
      }
    }
    else {
LAB_140012f21:
      if (*(char *)(puVar3 + 0x10) == -1) {
LAB_140012f2a:
        *(undefined1 *)(puVar3 + 0x10) = 0;
      }
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== QueryUniqueId @ 140012f6c =====

int QueryUniqueId(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  longlong local_res10;
  longlong local_res18 [2];
  
  *param_2 = 0;
  local_res10 = 0;
  local_res18[0] = 0;
  iVar1 = OpenDevice(param_1,local_res18,&local_res10);
  if (-1 < iVar1) {
    iVar1 = QueryUniqueIdInternal(local_res18[0],local_res10,param_2);
  }
  if (local_res10 != 0) {
    ObfDereferenceObject(local_res10);
  }
  if (local_res18[0] != 0) {
    ObfDereferenceObject(local_res18[0]);
  }
  return iVar1;
}



===== QueryUniqueIdQueryRoutine @ 140013000 =====

undefined8
QueryUniqueIdQueryRoutine
          (undefined8 param_1,undefined8 param_2,void *param_3,uint param_4,longlong *param_5)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  
  if (param_4 < 0x10000) {
    puVar1 = (undefined2 *)ExAllocatePool2(0x102,(ulonglong)param_4 + 4,0x41746e4d);
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = (short)param_4;
      memmove(puVar1 + 1,param_3,(ulonglong)param_4);
      *param_5 = (longlong)puVar1;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 0;
    }
    uVar2 = 100;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0;
    }
    uVar2 = 99;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2);
  return 0;
}



===== RedirectSavedLink @ 1400130c8 =====

undefined1
RedirectSavedLink(longlong param_1,undefined1 (*param_2) [16],undefined8 *param_3,undefined8 param_4
                 )

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  char cVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 uVar7;
  undefined7 uVar8;
  
  uVar8 = (undefined7)((ulonglong)param_3 >> 8);
  plVar6 = *(longlong **)(param_1 + 0x10);
  while( true ) {
    if (plVar6 == (longlong *)(param_1 + 0x10)) {
      return 0;
    }
    plVar5 = plVar6 + 3;
    uVar7 = 1;
    cVar4 = RtlEqualUnicodeString(param_2);
    if (cVar4 != '\0') break;
    plVar6 = (longlong *)*plVar6;
  }
  if (plVar6 == (longlong *)0x0) {
    return 0;
  }
  lVar1 = *plVar6;
  if ((*(longlong **)(lVar1 + 8) == plVar6) &&
     (plVar2 = (longlong *)plVar6[1], (longlong *)*plVar2 == plVar6)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    MountmgrSetDLStringCase((short *)param_2,plVar5,CONCAT71(uVar8,uVar7));
    GlobalDeleteSymbolicLink(param_2,plVar5,CONCAT71(uVar8,uVar7),param_4);
    GlobalCreateSymbolicLink(param_2,param_3,CONCAT71(uVar8,uVar7),param_4);
    ExFreePoolWithTag(plVar6[4],0);
    ExFreePoolWithTag(plVar6,0);
    return 1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar7 = (*pcVar3)();
  return uVar7;
}



===== ScrubRegistryRoutine @ 1400131b0 =====

int ScrubRegistryRoutine
              (undefined8 param_1,int param_2,undefined8 param_3,uint param_4,longlong param_5,
              undefined1 *param_6)

{
  ushort *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  if (param_2 == 3) {
    for (puVar4 = *(undefined8 **)(param_5 + 0x10); puVar4 != (undefined8 *)(param_5 + 0x10);
        puVar4 = (undefined8 *)*puVar4) {
      puVar1 = (ushort *)puVar4[0xc];
      if (((puVar1 != (ushort *)0x0) && (*puVar1 == param_4)) &&
         (uVar3 = RtlCompareMemory(puVar1 + 1,param_3,(ulonglong)param_4), uVar3 == param_4))
      goto LAB_140013280;
    }
    iVar2 = RtlDeleteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices");
    if (iVar2 < 0) {
      *param_6 = 0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x151,param_1,iVar2);
      }
    }
    else {
      *param_6 = 1;
      iVar2 = -0x3fffffff;
    }
  }
  else {
LAB_140013280:
    iVar2 = 0;
  }
  return iVar2;
}



===== WppInitKm @ 1400132a4 =====

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



===== WppTraceCallback @ 140013340 =====

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



===== WriteUniqueIdToMaster @ 1400135c8 =====

ulonglong WriteUniqueIdToMaster(undefined8 *param_1,longlong param_2)

{
  longlong *plVar1;
  uint uVar2;
  void *_Dst;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong *plVar7;
  void *pvVar8;
  ulonglong uVar9;
  undefined8 local_28;
  longlong lStack_20;
  
  plVar7 = (longlong *)0x0;
  local_28 = 0;
  lStack_20 = 0;
  _Dst = (void *)ExAllocatePool2(0x102,(ulonglong)*(ushort *)(param_2 + 10) + 2,0x41746e4d);
  if (_Dst == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78);
    }
    uVar3 = 0xc000009a;
  }
  else {
    memmove(_Dst,(void *)((ulonglong)*(ushort *)(param_2 + 8) + param_2),
            (ulonglong)*(ushort *)(param_2 + 10));
    uVar9 = 3;
    *(undefined2 *)((longlong)_Dst + (ulonglong)(*(ushort *)(param_2 + 10) >> 1) * 2) = 0;
    pvVar8 = _Dst;
    uVar2 = RtlWriteRegistryValue
                      (0,L"\\Registry\\Machine\\System\\MountedDevices",_Dst,3,
                       (ulonglong)*(ushort *)(param_2 + 0xc) + param_2,
                       *(undefined2 *)(param_2 + 0xe));
    uVar3 = (ulonglong)uVar2;
    if ((((int)uVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar9 = uVar3;
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,pvVar8,uVar2);
    }
    ExFreePoolWithTag(_Dst,0);
    plVar1 = param_1 + 2;
    plVar6 = (longlong *)*plVar1;
    local_28 = CONCAT62(CONCAT42(local_28._4_4_,*(undefined2 *)(param_2 + 10)),
                        *(undefined2 *)(param_2 + 10));
    lStack_20 = (ulonglong)*(ushort *)(param_2 + 8) + param_2;
    if (plVar6 != plVar1) {
      uVar5 = (ulonglong)*(ushort *)(param_2 + 0xe);
      do {
        plVar7 = plVar6;
        if ((short)uVar5 == *(short *)plVar7[0xc]) {
          uVar4 = RtlCompareMemory((ulonglong)*(ushort *)(param_2 + 0xc) + param_2,
                                   (short *)plVar7[0xc] + 1,uVar5);
          uVar5 = (ulonglong)*(ushort *)(param_2 + 0xe);
          plVar6 = plVar7;
          if (uVar4 == uVar5) break;
        }
        plVar6 = (longlong *)*plVar7;
      } while (plVar6 != plVar1);
    }
    if (plVar6 != param_1 + 2) {
      MountMgrCreatePointWorker(param_1,&local_28,(longlong)plVar7,uVar9);
    }
  }
  return uVar3;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001377c =====

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



===== wil_UninitializeFeatureStaging @ 140013848 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400138a0 =====

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
      goto LAB_1400138fd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400138fd;
    }
  }
  uVar1 = 0x206;
LAB_1400138fd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140013908 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400139c0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1400139f8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140013a7a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140013a7a;
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
LAB_140013a7a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140013ad0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140013b30 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140013b4c =====

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



===== MntMgrFindDevice @ 140013c00 =====

void MntMgrFindDevice(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  for (puVar1 = *(undefined8 **)(param_1 + 0x10);
      (puVar1 != (undefined8 *)(param_1 + 0x10) && (puVar1 != param_2));
      puVar1 = (undefined8 *)*puVar1) {
  }
  return;
}



===== CloseFileHandleOutsideExtensionMutexLock @ 140013c30 =====

void CloseFileHandleOutsideExtensionMutexLock(longlong param_1,undefined8 param_2)

{
  if (param_1 == 0) {
    ZwClose(param_2);
  }
  else {
    KeReleaseMutex(param_1 + 0x38,0);
    ZwClose(param_2);
    KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
  }
  return;
}



===== UpdateReplicatedUniqueIds @ 140013cb0 =====

void UpdateReplicatedUniqueIds(longlong param_1,longlong param_2)

{
  short sVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined2 *puVar6;
  longlong *plVar7;
  
  for (puVar2 = *(undefined8 **)(param_1 + 0x20); puVar2 != (undefined8 *)(param_1 + 0x20);
      puVar2 = (undefined8 *)*puVar2) {
    sVar1 = *(short *)puVar2[2];
    if ((sVar1 == *(short *)(param_2 + 0xe)) &&
       (uVar4 = RtlCompareMemory((short *)puVar2[2] + 1,
                                 (ulonglong)*(ushort *)(param_2 + 0xc) + param_2,sVar1),
       uVar4 == *(ushort *)puVar2[2])) break;
  }
  if (puVar2 == (undefined8 *)(param_1 + 0x20)) {
    plVar5 = (longlong *)ExAllocatePool2(0x102,0x18,0x41746e4d);
    if (plVar5 == (longlong *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a);
      }
    }
    else {
      puVar6 = (undefined2 *)
               ExAllocatePool2(0x102,(ulonglong)*(ushort *)(param_2 + 0xe) + 4,0x41746e4d);
      plVar5[2] = (longlong)puVar6;
      if (puVar6 == (undefined2 *)0x0) {
        ExFreePoolWithTag(plVar5,0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b);
        }
      }
      else {
        *puVar6 = *(undefined2 *)(param_2 + 0xe);
        memmove((ushort *)plVar5[2] + 1,(void *)((ulonglong)*(ushort *)(param_2 + 0xc) + param_2),
                (ulonglong)*(ushort *)plVar5[2]);
        plVar7 = *(longlong **)(param_1 + 0x28);
        if (*plVar7 != param_1 + 0x20) {
          pcVar3 = (code *)swi(0x29);
          plVar7 = (longlong *)(*pcVar3)(3);
        }
        *plVar5 = param_1 + 0x20;
        plVar5[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar5;
        *(longlong **)(param_1 + 0x28) = plVar5;
      }
    }
  }
  return;
}



===== QueryUniqueIdFromMaster @ 140013e40 =====

int QueryUniqueIdFromMaster(longlong param_1,longlong param_2,longlong *param_3)

{
  ushort *puVar1;
  longlong lVar2;
  int iVar3;
  undefined2 *puVar4;
  code **ppcVar5;
  longlong local_res10;
  code *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined1 local_60 [88];
  
  local_res10 = 0;
  local_70 = 0;
  memset(local_60,0,0x58);
  local_78 = QueryUniqueIdQueryRoutine;
  ppcVar5 = &local_78;
  local_68 = *(undefined8 *)(param_2 + 8);
  *param_3 = 0;
  RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\MountedDevices",ppcVar5,param_3,0);
  if (*param_3 == 0) {
    iVar3 = FindDeviceInfo(param_1,param_2,ppcVar5,&local_res10);
    lVar2 = local_res10;
    if (iVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,ppcVar5,iVar3);
      }
      return iVar3;
    }
    puVar4 = (undefined2 *)
             ExAllocatePool2(0x102,(ulonglong)**(ushort **)(local_res10 + 0x60) + 4,0x41746e4d);
    *param_3 = (longlong)puVar4;
    if (puVar4 == (undefined2 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66);
      }
      return -0x3fffff66;
    }
    *puVar4 = **(undefined2 **)(lVar2 + 0x60);
    puVar1 = *(ushort **)(lVar2 + 0x60);
    memmove((void *)(*param_3 + 2),puVar1 + 1,(ulonglong)*puVar1);
  }
  return 0;
}



===== FindDeviceInfo @ 140013fb0 =====

int FindDeviceInfo(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  ushort *puVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  longlong lVar10;
  int local_res18;
  longlong local_80;
  longlong local_78;
  undefined8 local_70;
  ushort *puStack_68;
  longlong local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_60 = 0;
  uStack_58 = 0;
  RtlInitUnicodeString(&local_60,0);
  local_78 = 0;
  plVar9 = &local_80;
  local_80 = 0;
  lVar4 = 0;
  lVar10 = 0;
  iVar3 = IoGetDeviceObjectPointer(param_2,0x80,plVar9,&local_78);
  if (iVar3 < 0) {
LAB_140014300:
    if (local_80 != 0) {
      ObfDereferenceObject();
    }
    if (iVar3 < 0) goto LAB_1400141af;
  }
  else {
    if (*(short *)(local_80 + 0x58) != 0) {
      iVar3 = -0x3fffffcc;
      goto LAB_140014300;
    }
    lVar4 = IoGetAttachedDeviceReference(*(undefined8 *)(local_80 + 8));
    lVar10 = local_80;
    local_80 = 0;
  }
  local_70 = 0;
  puStack_68 = (ushort *)0x0;
  local_res18 = 0x102;
  puVar7 = (ushort *)0x0;
  iVar3 = 0;
  for (uVar6 = 0; uVar6 < 2; uVar6 = uVar6 + 1) {
    plVar9 = (longlong *)0x41746e4d;
    puVar7 = (ushort *)ExAllocatePool2(0x102,local_res18);
    if (puVar7 == (ushort *)0x0) {
      iVar3 = -0x3fffff66;
      goto LAB_140014187;
    }
    local_30 = 0;
    local_40 = 0;
    uStack_38 = 0;
    local_50 = 0;
    uStack_48 = 0;
    KeInitializeEvent(&local_40,0);
    plVar9 = (longlong *)0x0;
    lVar5 = IoBuildDeviceIoControlRequest
                      (0x4d0008,lVar4,0,0,puVar7,local_res18,0,&local_40,&local_50);
    if (lVar5 == 0) {
      iVar3 = -0x3fffff66;
      goto LAB_140014176;
    }
    if (lVar10 != 0) {
      *(longlong *)(*(longlong *)(lVar5 + 0xb8) + -0x18) = lVar10;
    }
    iVar3 = IofCallDriver(lVar4,lVar5);
    if (iVar3 == 0x103) {
      plVar9 = (longlong *)0x0;
      KeWaitForSingleObject(&local_40,0,0,0,0);
      iVar3 = (int)local_50;
    }
    if (-1 < iVar3) goto LAB_140014140;
    if (iVar3 != -0x7ffffffb) goto LAB_140014176;
    local_res18 = (*puVar7 & 0xfffffffe) + 2;
    ExFreePoolWithTag(puVar7,0);
  }
  if (-1 < iVar3) {
LAB_140014140:
    plVar9 = &local_60;
    local_70._0_4_ = CONCAT22(*puVar7,*puVar7);
    puStack_68 = puVar7 + 1;
    iVar3 = RtlDuplicateUnicodeString(1,&local_70);
  }
  if (puVar7 != (ushort *)0x0) {
LAB_140014176:
    ExFreePoolWithTag(puVar7,0);
  }
LAB_140014187:
  if (lVar4 != 0) {
    ObfDereferenceObject(lVar4);
  }
  if (lVar10 != 0) {
    ObfDereferenceObject(lVar10);
  }
LAB_1400141af:
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,plVar9,iVar3);
    }
  }
  else {
    puVar1 = *(undefined8 **)(param_1 + 0x10);
    puVar8 = (undefined8 *)0x0;
    while( true ) {
      if (puVar1 == (undefined8 *)(param_1 + 0x10)) break;
      plVar9 = (longlong *)CONCAT71((int7)((ulonglong)plVar9 >> 8),1);
      cVar2 = RtlEqualUnicodeString(&local_60,puVar1 + 10);
      puVar8 = puVar1;
      if (cVar2 != '\0') break;
      puVar1 = (undefined8 *)*puVar1;
    }
    ExFreePoolWithTag(uStack_58,0);
    if (puVar1 == (undefined8 *)(param_1 + 0x10)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,plVar9,0xc0000034);
      }
      iVar3 = -0x3fffffcc;
    }
    else {
      *param_4 = puVar8;
      iVar3 = 0;
    }
  }
  return iVar3;
}



===== WriteRemoteDatabaseEntry @ 140014360 =====

ulonglong WriteRemoteDatabaseEntry
                    (longlong param_1,undefined8 param_2,ulonglong param_3,uint *param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong local_res8;
  undefined8 local_38;
  ulonglong uStack_30;
  
  lVar1 = *(longlong *)(param_1 + 0x98);
  lVar8 = *(longlong *)(param_1 + 0xb0);
  local_res8 = param_3 & 0xffffffff;
  local_38 = 0;
  uStack_30 = 0;
  lVar2 = *(longlong *)(lVar1 + 0x150);
  KeReleaseMutex(lVar1 + 0x38,0);
  uVar7 = 0;
  uVar3 = ZwWriteFile(param_2,0,0,0,&local_38,param_4,*param_4,&local_res8,0);
  uVar6 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001440f;
    uVar5 = 0x35;
  }
  else {
    if (((*param_4 <= uStack_30) ||
        (uVar6 = 0xc000009a, (undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001440f;
    uVar5 = 0x36;
    uVar3 = 0xc000009a;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,uVar7,uVar3);
LAB_14001440f:
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  uVar4 = VerifyEpoch(lVar1,lVar2,lVar8);
  if ((int)uVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,lVar8,(int)uVar4);
    }
    if (-1 < (int)uVar6) {
      uVar6 = uVar4 & 0xffffffff;
    }
  }
  return uVar6;
}



===== GetRemoteDatabaseEntry @ 1400144f0 =====

ulonglong GetRemoteDatabaseEntry(longlong param_1,undefined8 param_2,uint param_3,longlong *param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined8 uVar9;
  longlong lVar10;
  uint uVar11;
  uint local_res8 [2];
  ulonglong local_res20;
  undefined8 local_50;
  ulonglong uStack_48;
  
  lVar1 = *(longlong *)(param_1 + 0x98);
  local_50 = 0;
  uStack_48 = 0;
  uVar6 = (ulonglong)param_3;
  lVar4 = 0;
  local_res8[0] = 0;
  lVar10 = *(longlong *)(param_1 + 0xb0);
  lVar2 = *(longlong *)(lVar1 + 0x150);
  KeReleaseMutex(lVar1 + 0x38,0);
  uVar9 = 0;
  local_res20 = uVar6;
  iVar3 = ZwReadFile(param_2,0,0,0,&local_50,local_res8,4,&local_res20,0);
  if (iVar3 < 0) {
    if (iVar3 == -0x3fffffef) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140014667;
      uVar7 = 0x2d;
      iVar3 = -0x3fffffef;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140014667;
      uVar7 = 0x2c;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,uVar9,iVar3);
  }
  else if (local_res8[0] == 0) {
    TruncateRemoteDatabase(param_2,uVar6);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e);
    }
  }
  else {
    lVar4 = ExAllocatePool2(0x102,local_res8[0]);
    if (lVar4 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f);
      }
    }
    else {
      uVar9 = 0;
      iVar3 = ZwReadFile(param_2,0,0,0,&local_50,lVar4,local_res8[0],&local_res20,0);
      if (iVar3 < 0) {
        TruncateRemoteDatabase(param_2,uVar6);
        ExFreePoolWithTag(lVar4,0);
        lVar4 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,uVar9,iVar3);
        }
      }
      else {
        uVar5 = (ulonglong)local_res8[0];
        if (uStack_48 < uVar5) {
          TruncateRemoteDatabase(param_2,uVar6);
          ExFreePoolWithTag(lVar4,0);
          lVar4 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,uVar5,iVar3);
          }
        }
        else if (local_res8[0] < 0x10) {
          TruncateRemoteDatabase(param_2,uVar6);
          ExFreePoolWithTag(lVar4,0);
          lVar4 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,uVar5,iVar3);
          }
        }
        else {
          uVar11 = (uint)*(ushort *)(lVar4 + 10) + (uint)*(ushort *)(lVar4 + 8);
          uVar8 = (uint)*(ushort *)(lVar4 + 0xe) + (uint)*(ushort *)(lVar4 + 0xc);
          if (uVar11 <= uVar8) {
            uVar11 = uVar8;
          }
          if (local_res8[0] < uVar11) {
            TruncateRemoteDatabase(param_2,(ulonglong)param_3);
            uVar9 = 0;
            ExFreePoolWithTag(lVar4);
            lVar4 = 0;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              WPP_SF_ddL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,uVar5,uVar11,
                         (char)local_res8[0],(char)iVar3);
            }
          }
        }
      }
    }
  }
LAB_140014667:
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  uVar5 = VerifyEpoch(lVar1,lVar2,lVar10);
  uVar6 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,lVar10,(int)uVar5);
    }
    if (lVar4 != 0) {
      ExFreePoolWithTag(lVar4,0);
    }
    *param_4 = 0;
  }
  else {
    *param_4 = lVar4;
    uVar6 = uVar5;
  }
  return uVar6;
}



===== OpenRemoteDatabase @ 140014940 =====

ulonglong OpenRemoteDatabase(longlong param_1,undefined8 param_2,undefined1 *param_3,
                            longlong *param_4)

{
  longlong lVar1;
  ushort uVar2;
  undefined1 uVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  longlong lVar11;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  undefined8 local_90;
  void *pvStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  
  local_a8 = 0;
  local_50 = 0;
  uStack_48 = uStack_48 & 0xffffffff00000000;
  local_90 = 0;
  pvStack_88 = (void *)0x0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = (undefined8 *)0x0;
  uStack_58 = 0;
  local_80 = 0;
  uStack_78 = 0;
  if ((param_4 == (longlong *)0x0) || (param_3 == (undefined1 *)0x0)) {
    uVar9 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_4,(char)param_3);
    }
    goto LAB_140014b88;
  }
  *param_3 = 0;
  uVar2 = DAT_140009030;
  *param_4 = 0;
  sVar4 = uVar2 + *(short *)(param_1 + 0x50);
  lVar1 = *(longlong *)(param_1 + 0x98);
  sVar5 = sVar4 + 2;
  local_90 = (ulonglong)CONCAT22(sVar5,sVar4);
  pvStack_88 = (void *)ExAllocatePool2(0x102,sVar5,0x41746e4d);
  if (pvStack_88 == (void *)0x0) {
    uVar9 = 0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24);
    }
    goto LAB_140014b88;
  }
  memmove(pvStack_88,*(void **)(param_1 + 0x58),(ulonglong)*(ushort *)(param_1 + 0x50));
  memmove((void *)((ulonglong)*(ushort *)(param_1 + 0x50) + (longlong)pvStack_88),
          PTR_u__System_Volume__140009038,(ulonglong)DAT_140009030);
  *(undefined2 *)((longlong)pvStack_88 + (local_90 >> 1 & 0x7fff) * 2) = 0;
  local_60 = &local_90;
  local_70 = CONCAT44(local_70._4_4_,0x30);
  uStack_68 = 0;
  uStack_58 = CONCAT44(uStack_58._4_4_,0x240);
  local_50 = 0;
  uStack_48 = 0;
  uVar3 = IoSetThreadHardErrorMode(0);
  if (((char)param_2 == '\0') || (uVar8 = 3, *(char *)(param_1 + 0x86) == '\0')) {
    uVar8 = 1;
  }
  local_98 = *(longlong *)(lVar1 + 0x150);
  local_a0 = *(longlong *)(param_1 + 0xb0);
  KeReleaseMutex(lVar1 + 0x38,0);
  puVar10 = &local_70;
  uVar6 = IoCreateFile(&local_a8,0x12019f,puVar10,&local_80,0,0x86,0,uVar8,0x60,0,0,0,0,0x108);
  uVar9 = (ulonglong)uVar6;
  if ((int)uVar6 < 0) {
    if (uVar6 == 0x8000002d) {
      DetectedSymlinkOnRemoteDatabaseFile();
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,puVar10,uVar6);
    }
  }
  KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
  lVar11 = local_a0;
  uVar7 = VerifyEpoch(lVar1,local_98,local_a0);
  if ((int)uVar7 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,lVar11,(int)uVar7);
    }
    *param_3 = 1;
joined_r0x000140014bfe:
    uVar9 = uVar7 & 0xffffffff;
    if (local_a8 != 0) {
      CloseFileHandleOutsideExtensionMutexLock(lVar1,local_a8);
      local_a8 = 0;
    }
    IoSetThreadHardErrorMode(uVar3);
  }
  else {
    if (((char)param_2 != '\0') && ((int)uVar6 < 0)) {
      KeReleaseMutex(lVar1 + 0x38,0);
      uVar6 = CreateRemoteDatabase(param_1,&local_a8);
      uVar9 = (ulonglong)uVar6;
      if (((int)uVar6 < 0) &&
         ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
         )) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,lVar11,uVar6);
      }
      KeWaitForSingleObject(lVar1 + 0x38,0,0,0,0);
      lVar11 = local_a0;
      uVar7 = VerifyEpoch(lVar1,local_98,local_a0);
      if ((int)uVar7 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,lVar11,(int)uVar7);
        }
        *param_3 = 1;
        goto joined_r0x000140014bfe;
      }
    }
    IoSetThreadHardErrorMode(uVar3);
    if (-1 < (int)uVar9) {
      *param_4 = local_a8;
    }
  }
LAB_140014b88:
  if (pvStack_88 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_88,0);
  }
  return uVar9;
}



===== ReconcileThisDatabaseWithMasterWorker @ 140014df0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReconcileThisDatabaseWithMasterWorker
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined *puVar2;
  code *pcVar3;
  bool bVar4;
  undefined1 uVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined **ppuVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  ushort **ppuVar15;
  undefined2 uVar16;
  uint uVar17;
  ushort **ppuVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined **ppuVar23;
  undefined **ppuVar24;
  longlong lVar25;
  ushort **ppuVar26;
  ushort **ppuVar27;
  undefined8 *puVar28;
  undefined **ppuVar29;
  undefined1 auStackY_288 [8];
  undefined1 auStackY_280 [24];
  ushort *local_228 [2];
  ushort **local_218;
  int iStack_210;
  undefined4 uStack_20c;
  char local_208;
  longlong local_200;
  ushort **local_1f8;
  ushort *local_1f0;
  longlong local_1e8;
  undefined8 local_1e0;
  undefined1 *puStack_1d8;
  ulonglong local_1d0;
  undefined8 local_1c8;
  void *pvStack_1c0;
  longlong local_1b8;
  longlong lStack_1b0;
  longlong local_1a8;
  undefined **local_1a0;
  undefined **local_198;
  ushort *local_190;
  undefined8 local_188;
  undefined4 *puStack_180;
  undefined8 local_178;
  longlong lStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 *local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  ushort **local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 local_110;
  undefined1 local_108 [208];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_288;
  puVar1 = (undefined8 *)*param_1;
  puVar28 = (undefined8 *)param_1[1];
  local_1a0 = (undefined **)0x0;
  cVar6 = false;
  local_200 = 0;
  local_1d0 = local_1d0 & 0xffffffff00000000;
  ppuVar24 = (undefined **)0x0;
  local_1e8 = 0;
  local_218 = (ushort **)0x0;
  local_1f8 = (ushort **)0x0;
  local_1f0 = (ushort *)0x0;
  local_190 = (ushort *)0x0;
  local_1a8 = 0;
  local_228[0]._0_1_ = '\0';
  local_1c8 = 0;
  pvStack_1c0 = (void *)0x0;
  local_118 = 0;
  uStack_114 = 0;
  local_1b8 = 0;
  lStack_1b0 = 0;
  local_110 = 0;
  local_1e0 = 0;
  puStack_1d8 = (undefined1 *)0x0;
  local_178 = 0;
  lStack_170 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = (undefined8 *)0x0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_128 = (ushort **)0x0;
  uStack_120 = 0;
  local_188 = 0;
  puStack_180 = (undefined4 *)0x0;
  puVar20 = auStackY_288;
  if (gUnloading != 0) goto LAB_140016180;
  uVar10 = WaitForRemoteDatabaseSemaphore((longlong)puVar1);
  if ((int)uVar10 < 0) {
    puVar20 = auStackY_288;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar20 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,param_3,(int)uVar10);
      puVar20 = auStackY_288;
    }
    goto LAB_140016180;
  }
  puVar20 = auStackY_288;
  if (gUnloading == 0) {
    KeWaitForSingleObject(puVar1 + 7,0,0,0);
    ppuVar23 = (undefined **)(puVar1 + 2);
    ppuVar11 = (undefined **)MntMgrFindDevice((longlong)puVar1,puVar28);
    if (((ppuVar11 == ppuVar23) || (*(char *)((longlong)puVar28 + 0x7c) != '\0')) ||
       (*(char *)((longlong)puVar28 + 0x7d) != '\0')) {
      KeReleaseMutex(puVar1 + 7,0);
      puVar20 = auStackY_288;
      goto LAB_140015029;
    }
    ppuVar26 = &local_190;
    iVar8 = IoGetDeviceObjectPointer(puVar28 + 10,0x80,ppuVar26,&local_1a8);
    if (iVar8 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar16 = 0x7d;
LAB_140015a71:
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,ppuVar26,iVar8);
      }
LAB_14001564a:
      puVar20 = auStackY_288;
      ppuVar18 = local_218;
      goto LAB_14001564f;
    }
    if ((local_1a8 != 0) && (*(longlong *)(local_1a8 + 0x38) != 0)) {
      cVar6 = (*(byte *)(*(longlong *)(local_1a8 + 0x38) + 4) & 1) != 0;
      local_1d0 = CONCAT44(local_1d0._4_4_,(uint)(byte)cVar6);
    }
    ObfDereferenceObject(local_190);
    puVar22 = auStackY_288;
    puVar20 = auStackY_288;
    puVar21 = auStackY_288;
    *(undefined2 *)((longlong)puVar28 + 0x83) = 0x101;
    local_208 = '\0';
    ppuVar11 = (undefined **)*ppuVar23;
    if ((undefined **)*ppuVar23 != ppuVar23) {
      do {
        ppuVar24 = ppuVar11;
        ppuVar11 = ppuVar24 + 6;
        local_1a0 = ppuVar24;
        for (ppuVar29 = (undefined **)ppuVar24[6]; ppuVar29 != ppuVar11;
            ppuVar29 = (undefined **)*ppuVar29) {
          if ((undefined8 *)ppuVar29[2] == puVar28) {
            puVar1[0x2a] = puVar1[0x2a] + 1;
            ppuVar24[0x16] = (undefined *)puVar1[0x2a];
            puVar2 = *ppuVar29;
            local_198 = (undefined **)ppuVar29[1];
            if ((*(undefined ***)(puVar2 + 8) != ppuVar29) || ((undefined **)*local_198 != ppuVar29)
               ) goto LAB_14001600c;
            *local_198 = puVar2;
            *(undefined ***)(puVar2 + 8) = local_198;
            ExFreePoolWithTag(ppuVar29[4]);
            ppuVar29[4] = (undefined *)0x0;
            ExFreePoolWithTag(ppuVar29);
            ppuVar29 = local_198;
          }
        }
        ppuVar11 = (undefined **)*ppuVar24;
      } while ((undefined **)*ppuVar24 != ppuVar23);
      cVar6 = (char)local_1d0;
    }
    ppuVar27 = local_228;
    uVar12 = OpenRemoteDatabase((longlong)puVar28,0,(undefined1 *)ppuVar27,&local_200);
    iVar8 = (int)uVar12;
    if ((char)local_228[0] != '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar16 = 0x7e;
LAB_140015a84:
        ppuVar26 = ppuVar27;
        goto LAB_140015a71;
      }
      goto LAB_14001564a;
    }
    if ((((local_1a8 == 0) || (*(longlong *)(local_1a8 + 0x38) == 0)) || (local_200 == 0)) ||
       ((cVar6 != '\0' || ((*(byte *)(*(longlong *)(local_1a8 + 0x38) + 4) & 1) == 0)))) {
      ppuVar18 = local_218;
    }
    else {
      LOCK();
      *(int *)(ppuVar24 + 0x11) = *(int *)(ppuVar24 + 0x11) + 1;
      UNLOCK();
      ppuVar18 = local_1f8;
    }
    sVar7 = DAT_140009010 + *(short *)(puVar28 + 10) + 2;
    local_1c8._0_4_ = CONCAT22(sVar7,DAT_140009010 + *(short *)(puVar28 + 10));
    pvStack_1c0 = (void *)ExAllocatePool2(0x102,sVar7,0x41746e4d);
    if (pvStack_1c0 == (void *)0x0) {
      KeReleaseMutex(puVar1 + 7,0);
      puVar20 = auStackY_288;
      if (local_200 != 0) {
        CloseFileHandleOutsideExtensionMutexLock(0,local_200);
        puVar20 = auStackY_288;
      }
      goto LAB_140015029;
    }
    memmove(pvStack_1c0,(void *)puVar28[0xb],(ulonglong)*(ushort *)(puVar28 + 10));
    memmove((void *)((ulonglong)*(ushort *)(puVar28 + 10) + (longlong)pvStack_1c0),
            PTR_u___Extend__Repar_140009018,(ulonglong)DAT_140009010);
    *(undefined2 *)((longlong)pvStack_1c0 + (local_1c8 >> 1 & 0x7fff) * 2) = 0;
    local_148 = &local_1c8;
    local_158 = CONCAT44(local_158._4_4_,0x30);
    uStack_150 = 0;
    uStack_140 = CONCAT44(uStack_140._4_4_,0x240);
    local_138 = 0;
    uStack_130 = 0;
    uVar12 = puVar1[0x2a];
    ppuVar24 = (undefined **)puVar28[0x16];
    local_1d0 = uVar12;
    local_198 = ppuVar24;
    KeReleaseMutex(puVar1 + 7);
    uVar5 = IoSetThreadHardErrorMode(0);
    iVar9 = ZwOpenFile(&local_1e8,0x120089,&local_158,&local_168);
    IoSetThreadHardErrorMode(uVar5);
    ExFreePoolWithTag(pvStack_1c0,0);
    ppuVar27 = (ushort **)0x0;
    pvStack_1c0 = (void *)0x0;
    KeWaitForSingleObject(puVar1 + 7,0,0,0);
    ppuVar23 = ppuVar24;
    uVar10 = VerifyEpoch((longlong)puVar1,uVar12,(longlong)ppuVar24);
    iVar8 = (int)uVar10;
    if (iVar8 < 0) {
      ppuVar27 = (ushort **)0x1;
      puVar19 = auStackY_288;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar19 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,ppuVar23,iVar8);
        puVar19 = auStackY_288;
      }
      goto LAB_140015651;
    }
    if (iVar9 < 0) {
      ppuVar27 = (ushort **)0x1;
      puVar19 = auStackY_288;
      iVar8 = iVar9;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar19 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,ppuVar23,iVar9);
        puVar19 = auStackY_288;
      }
      goto LAB_140015651;
    }
    puStack_180 = &local_118;
    uStack_114 = 0;
    local_110 = 0;
    local_118 = 0xa0000003;
    local_188 = CONCAT44(local_188._4_4_,0xc000c);
    KeReleaseMutex(puVar1 + 7,0);
    iVar9 = ZwQueryDirectoryFile(local_1e8,0,0,0);
    KeWaitForSingleObject(puVar1 + 7,0,0,0);
    uVar10 = VerifyEpoch((longlong)puVar1,uVar12,(longlong)ppuVar24);
    iVar8 = (int)uVar10;
    if (iVar8 < 0) {
      ppuVar27 = (ushort **)0x1;
      puVar19 = auStackY_288;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar19 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,ppuVar24,iVar8);
        puVar19 = auStackY_288;
      }
      goto LAB_140015651;
    }
    if (-1 < iVar9) {
      if (local_200 == 0) {
        uVar12 = OpenRemoteDatabase((longlong)puVar28,1,(undefined1 *)local_228,&local_200);
        puVar19 = auStackY_288;
        iVar8 = (int)uVar12;
        if (((char)local_228[0] != '\0') || (puVar19 = auStackY_288, local_200 == 0))
        goto LAB_140015651;
      }
      while( true ) {
        uVar17 = (uint)ppuVar27;
        ppuVar26 = ppuVar27;
        uVar12 = GetRemoteDatabaseEntry((longlong)puVar28,local_200,uVar17,(longlong *)&local_1f8);
        ppuVar18 = local_1f8;
        iVar8 = (int)uVar12;
        if (iVar8 < 0) break;
        local_218 = local_1f8;
        if (local_1f8 == (ushort **)0x0) {
          puStack_1d8 = local_108;
          ppuVar29 = &WPP_GLOBAL_Control;
          local_1e0 = CONCAT44(local_1e0._4_4_,0xc80000);
          bVar4 = true;
          goto LAB_1400152f2;
        }
        *(undefined4 *)((longlong)local_1f8 + 4) = 0;
        uVar12 = WriteRemoteDatabaseEntry
                           ((longlong)puVar28,local_200,(ulonglong)ppuVar27,(uint *)local_1f8);
        iVar8 = (int)uVar12;
        if (iVar8 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
          uVar16 = 0x85;
          goto LAB_140015a84;
        }
        ppuVar27 = (ushort **)(ulonglong)(uVar17 + *(int *)ppuVar18);
        ExFreePoolWithTag(ppuVar18,0);
        local_1f8 = (ushort **)0x0;
      }
      puVar20 = auStackY_288;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar20 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar16 = 0x84;
        goto LAB_1400160f9;
      }
      goto LAB_140016105;
    }
    ppuVar27 = (ushort **)0x1;
    cVar6 = '\x01';
    if (iVar9 != -0x3ffffff1) {
      puVar19 = auStackY_288;
      iVar8 = iVar9;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar19 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,ppuVar24,iVar9);
        puVar19 = auStackY_288;
      }
      goto LAB_140015651;
    }
    puVar20 = auStackY_288;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (puVar20 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (puVar20 = auStackY_288, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,ppuVar24,0xc000000f);
      puVar20 = auStackY_288;
    }
    goto LAB_140015706;
  }
  goto LAB_140015029;
LAB_1400152f2:
LAB_140015300:
  local_218 = local_128;
  iStack_210 = (int)uStack_120;
  uStack_20c = uStack_120._4_4_;
  KeReleaseMutex(puVar1 + 7,0);
  iVar9 = ZwQueryDirectoryFile(local_1e8,0,0,0);
  KeWaitForSingleObject(puVar1 + 7,0,0,0);
  ppuVar24 = local_198;
  uVar10 = VerifyEpoch((longlong)puVar1,local_1d0,(longlong)local_198);
  iVar8 = (int)uVar10;
  if (iVar8 < 0) {
    puVar20 = auStackY_288;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar20 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x86,ppuVar24,iVar8);
      puVar20 = auStackY_288;
    }
    goto LAB_14001564f;
  }
  if (!bVar4) {
    if ((local_218 != local_128) || (iStack_210 != (int)uStack_120)) goto LAB_1400153c2;
LAB_140015464:
    puVar13 = (undefined8 *)MntMgrFindDevice((longlong)puVar1,puVar28);
    if (puVar13 == puVar1 + 2) {
      puVar28 = (undefined8 *)0x0;
      puVar20 = auStackY_288;
      iVar8 = iVar9;
      goto LAB_14001564f;
    }
    ppuVar18 = (ushort **)0x0;
    goto LAB_140015482;
  }
  bVar4 = false;
LAB_1400153c2:
  if (iVar9 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar16 = 0x87;
LAB_140016084:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,ppuVar24,iVar9);
    }
    goto LAB_140015464;
  }
  if (gUnloading != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      uVar16 = 0x88;
      goto LAB_140016084;
    }
    goto LAB_140015464;
  }
  if ((int)uStack_120 != -0x5ffffffd) goto LAB_140015464;
  lVar25 = local_1e8;
  uVar12 = QueryVolumeName((longlong)puVar1,(longlong)puVar28,local_1e8,&local_128,(undefined8 *)0x0
                           ,(ushort *)&local_1e0,(ushort *)&local_1b8);
  if ((int)uVar12 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x89,lVar25,(int)uVar12);
    }
    goto LAB_140015300;
  }
  ppuVar27 = (ushort **)0x0;
  while( true ) {
    ppuVar26 = ppuVar27;
    uVar12 = GetRemoteDatabaseEntry
                       ((longlong)puVar28,local_200,(uint)ppuVar27,(longlong *)&local_1f8);
    ppuVar15 = local_1f8;
    iVar8 = (int)uVar12;
    if (iVar8 < 0) goto LAB_140016013;
    local_218 = local_1f8;
    if (local_1f8 == (ushort **)0x0) {
      ppuVar27 = &local_1f0;
      iVar8 = QueryUniqueIdFromMaster((longlong)puVar1,(longlong)&local_1e0,(longlong *)ppuVar27);
      if (iVar8 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,ppuVar27,iVar8);
        }
      }
      else {
        ppuVar27 = (ushort **)0x41746e4d;
        iVar8 = (uint)*local_1f0 + (ushort)local_1e0 + 0x10;
        ppuVar26 = (ushort **)ExAllocatePool2(0x102,iVar8);
        local_218 = ppuVar26;
        local_1f8 = ppuVar26;
        if (ppuVar26 != (ushort **)0x0) {
          *(int *)ppuVar26 = iVar8;
          *(undefined4 *)((longlong)ppuVar26 + 4) = 1;
          *(undefined2 *)(ppuVar26 + 1) = 0x10;
          *(ushort *)((longlong)ppuVar26 + 10) = (ushort)local_1e0;
          *(ushort *)((longlong)ppuVar26 + 0xc) = (ushort)local_1e0 + *(short *)(ppuVar26 + 1);
          *(ushort *)((longlong)ppuVar26 + 0xe) = *local_1f0;
          memmove((void *)((ulonglong)*(ushort *)(ppuVar26 + 1) + (longlong)ppuVar26),puStack_1d8,
                  (ulonglong)*(ushort *)((longlong)ppuVar26 + 10));
          memmove((void *)((ulonglong)*(ushort *)((longlong)ppuVar26 + 0xc) + (longlong)ppuVar26),
                  local_1f0 + 1,(ulonglong)*(ushort *)((longlong)ppuVar26 + 0xe));
          ppuVar27 = ppuVar26;
          uVar12 = AddRemoteDatabaseEntry((longlong)puVar28,local_200,(undefined4 *)ppuVar26);
          iVar8 = (int)uVar12;
          ExFreePoolWithTag(ppuVar26,0);
          local_1f8 = (ushort **)0x0;
          ppuVar18 = (ushort **)0x0;
          ExFreePoolWithTag(local_1f0,0);
          local_1f0 = (ushort *)0x0;
          if (-1 < iVar8) goto LAB_14001590f;
          puVar20 = auStackY_288;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (puVar20 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8d,ppuVar27,iVar8);
            puVar20 = auStackY_288;
          }
          goto LAB_14001564f;
        }
        ExFreePoolWithTag(local_1f0,0);
        local_1f0 = (ushort *)0x0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8c);
        }
      }
      ppuVar18 = local_218;
      goto LAB_14001590f;
    }
    local_178 = CONCAT62(CONCAT42(local_178._4_4_,*(undefined2 *)((longlong)local_1f8 + 10)),
                         *(undefined2 *)((longlong)local_1f8 + 10));
    lStack_170 = (ulonglong)*(ushort *)(local_1f8 + 1) + (longlong)local_1f8;
    cVar6 = RtlEqualUnicodeString(&local_178,&local_1e0,1);
    if (cVar6 != '\0') break;
    ppuVar27 = (ushort **)(ulonglong)((uint)ppuVar27 + *(int *)ppuVar15);
    ExFreePoolWithTag(ppuVar15,0);
    local_1f8 = (ushort **)0x0;
  }
  if (*(int *)((longlong)ppuVar15 + 4) == 0) {
    ppuVar26 = &local_1f0;
    iVar8 = QueryUniqueIdFromMaster((longlong)puVar1,(longlong)&local_1e0,(longlong *)ppuVar26);
    if (iVar8 < 0) {
      uVar12 = WriteUniqueIdToMaster(puVar1,(longlong)ppuVar15);
      iVar8 = (int)uVar12;
      if (iVar8 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
        uVar16 = 0x95;
        ppuVar27 = ppuVar26;
        goto LAB_140015a84;
      }
      *(int *)((longlong)ppuVar15 + 4) = *(int *)((longlong)ppuVar15 + 4) + 1;
      uVar12 = WriteRemoteDatabaseEntry
                         ((longlong)puVar28,local_200,(ulonglong)ppuVar27,(uint *)ppuVar15);
      iVar8 = (int)uVar12;
      if (iVar8 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
        uVar16 = 0x96;
        goto LAB_140015a84;
      }
    }
    else {
      if (*local_1f0 == *(ushort *)((longlong)ppuVar15 + 0xe)) {
        ppuVar26 = (ushort **)(ulonglong)*(ushort *)((longlong)ppuVar15 + 0xe);
        uVar12 = RtlCompareMemory(local_1f0 + 1,
                                  (ulonglong)*(ushort *)((longlong)ppuVar15 + 0xc) +
                                  (longlong)ppuVar15);
        if (uVar12 != *(ushort *)((longlong)ppuVar15 + 0xe)) goto LAB_140015bc4;
        *(int *)((longlong)ppuVar15 + 4) = *(int *)((longlong)ppuVar15 + 4) + 1;
        uVar12 = WriteRemoteDatabaseEntry
                           ((longlong)puVar28,local_200,(ulonglong)ppuVar27,(uint *)ppuVar15);
        iVar8 = (int)uVar12;
        if (iVar8 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
          uVar16 = 0x8f;
          goto LAB_140015a84;
        }
      }
      else {
LAB_140015bc4:
        uVar10 = IsUniqueIdPresent((longlong)puVar1,(longlong)ppuVar15);
        if ((char)uVar10 == '\0') {
          uVar12 = DeleteRemoteDatabaseEntry((longlong)puVar28,local_200,(ulonglong)ppuVar27);
          iVar8 = (int)uVar12;
          if (iVar8 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
            uVar16 = 0x92;
            goto LAB_140015a84;
          }
          ExFreePoolWithTag(ppuVar15,0);
          iVar8 = (uint)*local_1f0 + (ushort)local_1e0 + 0x10;
          ppuVar15 = (ushort **)ExAllocatePool2(0x102,iVar8,0x41746e4d);
          local_218 = ppuVar15;
          if (ppuVar15 == (ushort **)0x0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x93);
            }
            cVar6 = '\0';
            puVar20 = auStackY_288;
            ppuVar18 = local_218;
            goto LAB_140015706;
          }
          *(int *)ppuVar15 = iVar8;
          *(undefined4 *)((longlong)ppuVar15 + 4) = 1;
          *(undefined2 *)(ppuVar15 + 1) = 0x10;
          *(ushort *)((longlong)ppuVar15 + 10) = (ushort)local_1e0;
          *(ushort *)((longlong)ppuVar15 + 0xc) = (ushort)local_1e0 + *(short *)(ppuVar15 + 1);
          *(ushort *)((longlong)ppuVar15 + 0xe) = *local_1f0;
          memmove((void *)((ulonglong)*(ushort *)(ppuVar15 + 1) + (longlong)ppuVar15),puStack_1d8,
                  (ulonglong)*(ushort *)((longlong)ppuVar15 + 10));
          memmove((void *)((ulonglong)*(ushort *)((longlong)ppuVar15 + 0xc) + (longlong)ppuVar15),
                  local_1f0 + 1,(ulonglong)*(ushort *)((longlong)ppuVar15 + 0xe));
          ppuVar27 = ppuVar15;
          uVar12 = AddRemoteDatabaseEntry((longlong)puVar28,local_200,(undefined4 *)ppuVar15);
          iVar8 = (int)uVar12;
          if (iVar8 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
            uVar16 = 0x94;
            goto LAB_140015a84;
          }
        }
        else {
          uVar12 = WriteUniqueIdToMaster(puVar1,(longlong)ppuVar15);
          iVar8 = (int)uVar12;
          if (iVar8 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
            uVar16 = 0x90;
            ppuVar27 = ppuVar26;
            goto LAB_140015a84;
          }
          *(int *)((longlong)ppuVar15 + 4) = *(int *)((longlong)ppuVar15 + 4) + 1;
          uVar12 = WriteRemoteDatabaseEntry
                             ((longlong)puVar28,local_200,(ulonglong)ppuVar27,(uint *)ppuVar15);
          iVar8 = (int)uVar12;
          if (iVar8 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
            uVar16 = 0x91;
            goto LAB_140015a84;
          }
        }
      }
      ExFreePoolWithTag(local_1f0,0);
      local_1f0 = (ushort *)0x0;
    }
  }
  else {
    *(int *)((longlong)ppuVar15 + 4) = *(int *)((longlong)ppuVar15 + 4) + 1;
    uVar12 = WriteRemoteDatabaseEntry
                       ((longlong)puVar28,local_200,(ulonglong)ppuVar27,(uint *)ppuVar15);
    iVar8 = (int)uVar12;
    if (iVar8 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
      uVar16 = 0x8e;
      goto LAB_140015a84;
    }
  }
  ppuVar18 = (ushort **)0x0;
  ExFreePoolWithTag(ppuVar15,0);
  local_1f8 = (ushort **)0x0;
LAB_14001590f:
  iVar8 = FindDeviceInfo((longlong)puVar1,&local_1e0,ppuVar27,&local_1a0);
  if (-1 < iVar8) {
    ppuVar26 = (ushort **)0x41746e4d;
    plVar14 = (longlong *)ExAllocatePool2(0x102);
    ppuVar24 = local_1a0;
    if (plVar14 == (longlong *)0x0) {
      ExFreePoolWithTag(lStack_1b0);
    }
    else {
      puVar13 = (undefined8 *)local_1a0[7];
      ppuVar11 = local_1a0;
      if ((undefined **)*puVar13 != local_1a0 + 6) goto LAB_14001600c;
      *plVar14 = (longlong)(local_1a0 + 6);
      plVar14[1] = (longlong)puVar13;
      *puVar13 = plVar14;
      local_1a0[7] = (undefined *)plVar14;
      plVar14[2] = (longlong)puVar28;
      plVar14[3] = local_1b8;
      plVar14[4] = lStack_1b0;
      puVar1[0x2a] = puVar1[0x2a] + 1;
      local_1a0[0x16] = (undefined *)puVar1[0x2a];
    }
    lStack_1b0 = 0;
    if (*(char *)((longlong)ppuVar24 + 0x85) == '\0') {
      PostOnlineNotification((longlong)puVar1,(short *)(ppuVar24 + 8));
    }
    goto LAB_1400152f2;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x97,ppuVar27,0);
  }
  local_208 = '\x01';
  ExFreePoolWithTag(lStack_1b0);
  lStack_1b0 = 0;
  goto LAB_1400152f2;
LAB_140015482:
  ppuVar26 = ppuVar18;
  uVar12 = GetRemoteDatabaseEntry((longlong)puVar28,local_200,(uint)ppuVar18,(longlong *)&local_1f8)
  ;
  ppuVar15 = local_1f8;
  iVar8 = (int)uVar12;
  if (iVar8 < 0) goto LAB_1400160da;
  local_218 = local_1f8;
  if (local_1f8 == (ushort **)0x0) {
    if (local_208 == '\0') {
      *(undefined1 *)((longlong)puVar28 + 0x84) = 0;
    }
    KeReleaseMutex(puVar1 + 7,0);
    ZwClose(local_1e8);
    local_1e8 = 0;
    ZwClose(local_200);
    local_200 = 0;
    goto LAB_140015029;
  }
  if (*(int *)((longlong)local_1f8 + 4) == 0) {
    ppuVar27 = ppuVar18;
    uVar12 = DeleteRemoteDatabaseEntry((longlong)puVar28,local_200,(ulonglong)ppuVar18);
    iVar8 = (int)uVar12;
    if (iVar8 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001564a;
      uVar16 = 0x99;
      goto LAB_140015a84;
    }
  }
  else {
    UpdateReplicatedUniqueIds((longlong)puVar28,(longlong)local_1f8);
    ppuVar18 = (ushort **)(ulonglong)((uint)ppuVar18 + *(int *)ppuVar15);
  }
  ExFreePoolWithTag(ppuVar15,0);
  local_1f8 = (ushort **)0x0;
  goto LAB_140015482;
LAB_1400160da:
  puVar20 = auStackY_288;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (puVar20 = auStackY_288, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    uVar16 = 0x98;
    puVar22 = auStackY_288;
    goto LAB_1400160f9;
  }
  goto LAB_140016105;
LAB_14001600c:
  iVar8 = (int)ppuVar11;
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  puVar21 = auStackY_280;
LAB_140016013:
  puVar20 = puVar21;
  if (((undefined **)WPP_GLOBAL_Control != ppuVar29) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    uVar16 = 0x8a;
    puVar22 = puVar21;
LAB_1400160f9:
    uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar22 + -8) = 0x140016105;
    WPP_SF_L(uVar10,uVar16,ppuVar26,iVar8);
    puVar20 = puVar22;
  }
LAB_140016105:
  ppuVar18 = local_1f8;
LAB_14001564f:
  ppuVar27 = (ushort **)0x0;
  puVar19 = puVar20;
LAB_140015651:
  cVar6 = (char)ppuVar27;
  puVar20 = puVar19;
  if (iVar8 != -0x3ffffff2) {
LAB_140015706:
    if (puVar28 != (undefined8 *)0x0) {
      *(undefined8 *)(puVar20 + -8) = 0x14001571a;
      puVar13 = (undefined8 *)MntMgrFindDevice((longlong)puVar1,puVar28);
      if (puVar13 != puVar1 + 2) {
        *(undefined1 *)((longlong)puVar28 + 0x84) = 0;
      }
    }
  }
  *(undefined8 *)(puVar20 + -8) = 0x14001566a;
  KeReleaseMutex(puVar1 + 7,0);
  if (local_1f0 != (ushort *)0x0) {
    *(undefined8 *)(puVar20 + -8) = 0x140016133;
    ExFreePoolWithTag(local_1f0,0);
    local_1f0 = (ushort *)0x0;
  }
  if (ppuVar18 != (ushort **)0x0) {
    *(undefined8 *)(puVar20 + -8) = 0x14001614f;
    ExFreePoolWithTag(ppuVar18,0);
  }
  if (lStack_1b0 != 0) {
    *(undefined8 *)(puVar20 + -8) = 0x140016162;
    ExFreePoolWithTag(lStack_1b0,0);
    lStack_1b0 = 0;
  }
  if (local_1e8 != 0) {
    *(undefined8 *)(puVar20 + -8) = 0x140016177;
    CloseFileHandleOutsideExtensionMutexLock(0,local_1e8);
    local_1e8 = 0;
  }
  if (local_200 != 0) {
    if (cVar6 == '\x01') {
      *(undefined8 *)(puVar20 + -8) = 0x1400156bd;
      TruncateRemoteDatabase(local_200,0);
    }
    *(undefined8 *)(puVar20 + -8) = 0x1400156cb;
    CloseFileHandleOutsideExtensionMutexLock(0,local_200);
    local_200 = 0;
  }
LAB_140015029:
  *(undefined8 *)(puVar20 + -8) = 0x14001503d;
  KeReleaseSemaphore(puVar1 + 0xe,0,1);
LAB_140016180:
  *(undefined8 *)(puVar20 + -8) = 0x14001618f;
  return;
}



===== VerifyEpoch @ 1400161b0 =====

undefined8 VerifyEpoch(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (*(longlong *)(param_1 + 0x150) == param_2) {
LAB_1400161bd:
    uVar2 = 0;
  }
  else {
    for (puVar1 = *(undefined8 **)(param_1 + 0x10); puVar1 != (undefined8 *)(param_1 + 0x10);
        puVar1 = (undefined8 *)*puVar1) {
      if (param_3 == puVar1[0x16]) goto LAB_1400161bd;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_3,0xc000000e);
    }
    uVar2 = 0xc000000e;
  }
  return uVar2;
}



===== QueryVolumeName @ 140016220 =====

ulonglong QueryVolumeName(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                         undefined8 *param_5,ushort *param_6,ushort *param_7)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  void *_Dst;
  ulonglong uVar6;
  ushort uVar7;
  undefined2 uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  uint *_Size;
  longlong local_res8;
  longlong local_res10;
  undefined8 in_stack_ffffffffffffff38;
  undefined4 uVar12;
  undefined8 *puVar11;
  undefined4 uVar13;
  longlong local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  uint local_70 [2];
  undefined8 local_68;
  undefined8 *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
  local_70[1] = 0;
  local_54 = 0;
  local_res8 = 0;
  local_98 = 0;
  local_res10 = 0;
  puVar5 = (uint *)0x0;
  lVar4 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  if (param_2 != 0) {
    local_98 = *(longlong *)(param_1 + 0x150);
    local_res10 = *(longlong *)(param_2 + 0xb0);
  }
  KeReleaseMutex(param_1 + 0x38,0);
  local_70[0] = 0x30;
  _Size = local_70;
  local_50 = 0;
  uStack_48 = 0;
  if (param_5 == (undefined8 *)0x0) {
    local_80 = CONCAT44(local_80._4_4_,0x80008);
    param_5 = &local_80;
    local_58 = 0x200;
    uVar13 = 0x202020;
    uStack_78 = param_4;
    local_68 = param_3;
  }
  else {
    local_68 = 0;
    local_58 = 0x240;
    uVar13 = 0x200020;
  }
  local_60 = param_5;
  uVar3 = ZwOpenFile(&local_res8,0x100080,_Size,&local_90,CONCAT44(uVar12,7),uVar13);
  uVar9 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140016809;
    uVar8 = 0x57;
    goto LAB_1400167fe;
  }
  lVar4 = ExAllocatePool2(0x102,0x4000);
  if (lVar4 == 0) {
    uVar9 = 0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58);
    }
    goto LAB_140016809;
  }
  puVar11 = &local_90;
  uVar10 = 0;
  uVar3 = ZwFsControlFile(local_res8,0,0,0,puVar11,0x900a8,0,0,lVar4,0x4000);
  uVar12 = (undefined4)((ulonglong)puVar11 >> 0x20);
  uVar9 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,uVar10,uVar3);
    }
    goto LAB_140016809;
  }
  _Size = (uint *)(ulonglong)*(ushort *)(lVar4 + 10);
  if ((short *)(ulonglong)param_6[1] < (short *)((longlong)_Size + 2U)) {
    uVar9 = 0xc0000023;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140016809;
    uVar8 = 0x5a;
    uVar3 = 0xc0000023;
    goto LAB_1400167fe;
  }
  *param_6 = *(ushort *)(lVar4 + 10);
  memmove(*(void **)(param_6 + 4),(void *)((ulonglong)*(ushort *)(lVar4 + 8) + 0x10 + lVar4),
          (size_t)_Size);
  if (*(short *)(*(longlong *)(param_6 + 4) + -2 + (ulonglong)(*param_6 >> 1) * 2) == 0x5c) {
    uVar7 = *param_6 - 2;
    *param_6 = uVar7;
    *(undefined2 *)(*(longlong *)(param_6 + 4) + (ulonglong)(uVar7 >> 1) * 2) = 0;
    if (((((*param_6 != 0x60) &&
          ((*param_6 != 0x62 || (*(short *)(*(longlong *)(param_6 + 4) + 0x60) != 0x5c)))) ||
         ((psVar2 = *(short **)(param_6 + 4), *psVar2 != 0x5c ||
          (((((((sVar1 = psVar2[1], sVar1 != 0x3f && (sVar1 != 0x5c)) || (psVar2[2] != 0x3f)) ||
              ((psVar2[3] != 0x5c || (psVar2[4] != 0x56)))) || (psVar2[5] != 0x6f)) ||
            (((psVar2[6] != 0x6c || (psVar2[7] != 0x75)) ||
             ((psVar2[8] != 0x6d ||
              (((psVar2[9] != 0x65 || (psVar2[10] != 0x7b)) || (psVar2[0x13] != 0x2d)))))))) ||
           ((psVar2[0x18] != 0x2d || (psVar2[0x1d] != 0x2d)))))))) || (psVar2[0x22] != 0x2d)) ||
       (((psVar2[0x2f] != 0x7d || (*param_6 != 0x60)) || (sVar1 != 0x3f)))) {
      uVar9 = 0xc000000d;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140016809;
      uVar8 = 0x5c;
      goto LAB_1400167f8;
    }
    puVar5 = (uint *)ExAllocatePool2(0x102,8,0x41746e4d);
    if (puVar5 == (uint *)0x0) {
      uVar9 = 0xc000009a;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d);
      }
      goto LAB_140016809;
    }
    uVar10 = CONCAT44(uVar12,9);
    _Size = puVar5;
    uVar3 = ZwQueryInformationFile(local_res8,&local_90,puVar5,8,uVar10);
    uVar12 = (undefined4)((ulonglong)uVar10 >> 0x20);
    if (uVar3 == 0x80000005) {
      uVar9 = Feature_1006081336__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar9 == 0) || (*puVar5 < 0xfffe)) {
        uVar3 = *puVar5;
        ExFreePoolWithTag(puVar5,0);
        _Size = (uint *)0x41746e4d;
        puVar5 = (uint *)ExAllocatePool2(0x102,uVar3 + 8);
        if (puVar5 != (uint *)0x0) {
          _Size = puVar5;
          uVar3 = ZwQueryInformationFile(local_res8,&local_90,puVar5,uVar3 + 8,CONCAT44(uVar12,9));
          goto LAB_140016723;
        }
        uVar9 = 0xc000009a;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0')
           ) goto LAB_140016809;
        uVar8 = 0x5f;
        uVar3 = 0xc000009a;
      }
      else {
        uVar9 = 0xc0000106;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140016809;
        uVar8 = 0x5e;
        uVar3 = 0xc0000106;
      }
    }
    else {
LAB_140016723:
      uVar9 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar3 = *puVar5;
        *param_7 = (ushort)uVar3;
        uVar7 = (ushort)uVar3 + 2;
        param_7[1] = uVar7;
        _Dst = (void *)ExAllocatePool2(0x102,uVar7,0x41746e4d);
        *(void **)(param_7 + 4) = _Dst;
        if (_Dst == (void *)0x0) {
          uVar9 = 0xc000009a;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61);
          }
        }
        else {
          uVar7 = *param_7;
          memmove(_Dst,puVar5 + 1,(ulonglong)uVar7);
          *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar7 >> 1) * 2) = 0;
        }
        goto LAB_140016809;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140016809;
      uVar8 = 0x60;
    }
  }
  else {
    uVar9 = 0xc000000d;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_140016809;
    uVar8 = 0x5b;
LAB_1400167f8:
    uVar9 = 0xc000000d;
    uVar3 = 0xc000000d;
  }
LAB_1400167fe:
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,_Size,uVar3);
LAB_140016809:
  if (local_res8 != 0) {
    ZwClose();
    local_res8 = 0;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (puVar5 != (uint *)0x0) {
    ExFreePoolWithTag(puVar5,0);
  }
  KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
  if (param_2 != 0) {
    lVar4 = local_res10;
    uVar6 = VerifyEpoch(param_1,local_98,local_res10);
    if ((int)uVar6 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,lVar4,(int)uVar6);
      }
      if (-1 < (int)uVar9) {
        uVar9 = uVar6 & 0xffffffff;
      }
    }
  }
  return uVar9;
}



===== WaitForRemoteDatabaseSemaphore @ 1400168e0 =====

undefined8 WaitForRemoteDatabaseSemaphore(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0xfffffffffa0a1f00;
  uVar2 = 0;
  uVar1 = KeWaitForSingleObject(param_1 + 0x70,0,0,0,local_res8);
  if ((int)uVar1 == 0x102) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,uVar2,0xc00000b5);
    }
    uVar1 = 0xc00000b5;
  }
  return uVar1;
}



===== MountMgrQueryDosVolumePaths @ 140016960 =====

/* WARNING: Type propagation algorithm not settling */

int MountMgrQueryDosVolumePaths(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint *puVar2;
  undefined8 ****ppppuVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 **********ppppppppppuVar10;
  undefined8 ****ppppuVar11;
  bool bVar12;
  uint local_res18 [2];
  uint *local_res20;
  longlong local_88;
  undefined8 **********local_80;
  undefined8 **********local_78;
  undefined8 **********ppppppppppuStack_70;
  undefined8 local_68;
  ushort *puStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  longlong local_48;
  longlong lStack_40;
  
  ppppppppppuVar10 = *(undefined8 ***********)(param_2 + 0xb8);
  puVar2 = *(uint **)(param_2 + 0x18);
  local_88 = 0;
  local_res20 = (uint *)0x0;
  local_res18[0] = 0;
  local_68 = 0;
  puStack_60 = (ushort *)0x0;
  bVar12 = false;
  local_78 = (undefined8 **********)0x0;
  ppppppppppuStack_70 = (undefined8 **********)0x0;
  local_48 = 0;
  lStack_40 = 0;
  local_80 = ppppppppppuVar10;
  if (*(uint *)(ppppppppppuVar10 + 2) < 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar7 = 0x141;
  }
  else {
    uVar1 = (ushort)*puVar2;
    if ((uVar1 & 1) == 0) {
      if (*(uint *)(ppppppppppuVar10 + 2) < uVar1 + 2) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3ffffff3;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return -0x3ffffff3;
        }
        uVar7 = 0x143;
      }
      else {
        if (3 < *(uint *)(ppppppppppuVar10 + 1)) {
          puStack_60 = (ushort *)((longlong)puVar2 + 2);
          uVar9 = 0;
          local_68 = (ulonglong)CONCAT22(uVar1,uVar1);
          while( true ) {
            if (999 < uVar9) break;
            local_58 = 0;
            uStack_50 = 0;
            iVar5 = QueryDeviceName(&local_68,&local_58);
            if (iVar5 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,ppppppppppuVar10,iVar5);
              }
LAB_140016b81:
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar5;
              }
              if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                return iVar5;
              }
              if (WPP_GLOBAL_Control[0x29] == '\0') {
                return iVar5;
              }
              WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x145,ppppppppppuVar10,iVar5);
              return iVar5;
            }
            ppppuVar11 = (undefined8 ****)0x0;
            for (ppppuVar3 = *(undefined8 *****)(param_1 + 0x10);
                ppppuVar3 != (undefined8 ****)(param_1 + 0x10);
                ppppuVar3 = (undefined8 ****)*ppppuVar3) {
              ppppppppppuVar10 =
                   (undefined8 **********)CONCAT71((int7)((ulonglong)ppppppppppuVar10 >> 8),1);
              cVar4 = RtlEqualUnicodeString(&local_58,ppppuVar3 + 10);
              ppppuVar11 = ppppuVar3;
              if (cVar4 != '\0') break;
            }
            ExFreePoolWithTag(uStack_50,0);
            if (ppppuVar3 == (undefined8 ****)(param_1 + 0x10)) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,ppppppppppuVar10,0xc0000034
                        );
              }
              iVar5 = -0x3fffffcc;
              goto LAB_140016b81;
            }
            ppppppppppuStack_70 = &local_78;
            local_88 = 0;
            local_78 = &local_78;
            ppppppppppuVar10 = &local_78;
            uVar6 = MountMgrQueryVolumePaths
                              (param_1,ppppuVar11,ppppppppppuVar10,&local_res20,local_res18,
                               &local_88);
            iVar5 = (int)uVar6;
            if (-1 < iVar5) goto LAB_140016ac9;
            if (iVar5 != -0x3ffffdd3) goto LAB_140016d59;
            if (local_88 == 0) {
              uVar9 = uVar9 + 1;
            }
            else {
              cVar4 = *(char *)((longlong)ppppuVar11 + 0x81);
              uVar8 = 0;
              lStack_40 = local_88;
              local_48 = param_1;
              KeReleaseMutex(param_1 + 0x38);
              ReconcileThisDatabaseWithMasterWorker(&local_48,uVar8,ppppppppppuVar10);
              ppppppppppuVar10 = (undefined8 **********)0x0;
              KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
              bVar12 = cVar4 == '\0';
              uVar9 = uVar9 + 1;
            }
          }
          if (uVar9 == 1000) {
            iVar5 = -0x3fffffff;
LAB_140016d59:
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar5;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
              return iVar5;
            }
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x146,ppppppppppuVar10,iVar5);
            return iVar5;
          }
LAB_140016ac9:
          if (bVar12) {
            MountMgrNotifyNameChange(param_1,&local_68,'\0');
          }
          uVar9 = *local_res20;
          *puVar2 = uVar9;
          if (0xfffffffb < uVar9) {
            *puVar2 = 0xfffffffb;
            uVar9 = 0xfffffffb;
          }
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)(uVar9 + 4);
          if ((ulonglong)*(uint *)(local_80 + 1) < (ulonglong)(uVar9 + 4)) {
            ExFreePoolWithTag(local_res20,0);
            *(undefined8 *)(param_2 + 0x38) = 4;
            return -0x7ffffffb;
          }
          memmove(puVar2 + 1,local_res20 + 1,(ulonglong)*puVar2);
          ExFreePoolWithTag(local_res20,0);
          return 0;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3ffffff3;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return -0x3ffffff3;
        }
        uVar7 = 0x144;
      }
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3ffffff3;
      }
      uVar7 = 0x142;
    }
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,ppppppppppuVar10,0xc000000d);
  return -0x3ffffff3;
}



===== MountMgrQueryVolumePaths @ 140016dc0 =====

ulonglong MountMgrQueryVolumePaths
                    (longlong param_1,undefined8 ****param_2,undefined8 *****param_3,
                    undefined8 *param_4,uint *param_5,longlong *param_6)

{
  undefined8 *****pppppuVar1;
  undefined8 *********pppppppppuVar2;
  undefined8 ***pppuVar3;
  code *pcVar4;
  undefined8 *****pppppuVar5;
  undefined8 ****ppppuVar6;
  ulonglong uVar7;
  longlong *plVar8;
  uint *puVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  longlong *plVar14;
  undefined8 ****ppppuVar15;
  ulonglong uVar16;
  undefined8 *****pppppuVar17;
  uint *puVar18;
  undefined8 *****pppppuVar19;
  undefined4 uVar20;
  ulonglong uVar21;
  char local_98 [4];
  uint local_94;
  uint local_90;
  longlong *local_88;
  uint local_80;
  uint local_7c;
  undefined8 *********local_78;
  undefined8 *********local_70;
  undefined8 ****local_68;
  longlong local_60;
  undefined8 *****local_58;
  
  local_70 = &local_78;
  pppppuVar17 = (undefined8 *****)(param_2 + 2);
  local_68 = (undefined8 ****)0x0;
  local_80 = 0;
  local_78 = &local_78;
  local_88 = (longlong *)0x0;
  local_90 = 0;
  local_98[0] = '\0';
  local_94 = 0;
  uVar21 = 0;
  uVar13 = 2;
  pppppuVar5 = (undefined8 *****)*pppppuVar17;
  pppppuVar19 = (undefined8 *****)0x0;
  while( true ) {
    if (pppppuVar5 == pppppuVar17) break;
    pppppuVar19 = pppppuVar5;
    if ((((((*(short *)(pppppuVar5 + 3) == 0x1c) &&
           (ppppuVar15 = pppppuVar5[4], *(short *)ppppuVar15 == 0x5c)) &&
          (*(short *)((longlong)ppppuVar15 + 2) == 0x44)) &&
         ((*(short *)((longlong)ppppuVar15 + 4) == 0x6f &&
          (*(short *)((longlong)ppppuVar15 + 6) == 0x73)))) &&
        (((*(short *)(ppppuVar15 + 1) == 0x44 &&
          ((*(short *)((longlong)ppppuVar15 + 10) == 0x65 &&
           (*(short *)((longlong)ppppuVar15 + 0xc) == 0x76)))) &&
         (*(short *)((longlong)ppppuVar15 + 0xe) == 0x69)))) &&
       ((((*(short *)(ppppuVar15 + 2) == 99 && (*(short *)((longlong)ppppuVar15 + 0x12) == 0x65)) &&
         (*(short *)((longlong)ppppuVar15 + 0x14) == 0x73)) &&
        (((*(short *)((longlong)ppppuVar15 + 0x16) == 0x5c &&
          ((ushort)(*(short *)(ppppuVar15 + 3) - 0x41U) < 0x1a)) &&
         ((*(short *)((longlong)ppppuVar15 + 0x1a) == 0x3a && (*(char *)(pppppuVar5 + 2) != '\0'))))
        )))) {
      uVar13 = 8;
      break;
    }
    pppppuVar5 = (undefined8 *****)*pppppuVar5;
  }
  pppppuVar1 = (undefined8 *****)*param_3;
  local_58 = (undefined8 *****)0x0;
  if (pppppuVar5 != pppppuVar17) {
    local_58 = pppppuVar19;
  }
  for (; pppppuVar1 != param_3; pppppuVar1 = (undefined8 *****)*pppppuVar1) {
    if (pppppuVar1[2] == param_2) goto LAB_14001733e;
  }
  ppppuVar6 = (undefined8 ****)param_2[6];
  ppppuVar15 = param_2 + 6;
  uVar10 = 0;
  local_80 = 0;
  if (ppppuVar6 == ppppuVar15) {
LAB_140016f87:
    pppppppppuVar2 = (undefined8 *********)param_3[1];
    local_68 = param_2;
    if (*pppppppppuVar2 != (undefined8 ********)param_3) goto LAB_140017573;
    *pppppppppuVar2 = &local_78;
    param_3[1] = &local_78;
    local_60 = *(longlong *)(param_1 + 0x150);
    pppuVar3 = param_2[0x16];
    uVar16 = 0;
    ppppuVar6 = (undefined8 ****)*ppppuVar15;
    local_7c = 0;
    local_70 = pppppppppuVar2;
    local_78 = (undefined8 *********)param_3;
    for (; ppppuVar6 != ppppuVar15; ppppuVar6 = (undefined8 ****)*ppppuVar6) {
      pppppuVar17 = (undefined8 *****)local_98;
      local_98[0] = '\0';
      uVar7 = MountMgrValidateBackPointer
                        ((longlong)ppppuVar6,(longlong)param_2,(undefined1 *)pppppuVar17);
      uVar21 = uVar7 & 0xffffffff;
      if (*(longlong *)(param_1 + 0x150) != local_60) {
        plVar8 = *(longlong **)(param_1 + 0x10);
        if (plVar8 != (longlong *)(param_1 + 0x10)) {
          while (pppuVar3 != (undefined8 ***)plVar8[0x16]) {
            plVar8 = (longlong *)*plVar8;
            if (plVar8 == (longlong *)(param_1 + 0x10)) goto LAB_140017031;
          }
          goto LAB_140017092;
        }
LAB_140017031:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,pppppuVar17,0xc000000e);
        }
        uVar21 = 0xc000022d;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400174f3;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x137,pppppuVar17,0xc000022d);
        }
LAB_14001730b:
        uVar20 = (undefined4)uVar21;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400174f3;
        uVar11 = 0x138;
        goto LAB_1400174ea;
      }
LAB_140017092:
      if ((int)uVar7 == -0x3ffffff2) {
LAB_140017305:
        uVar21 = 0xc000022d;
        goto LAB_14001730b;
      }
      if ((int)uVar7 < 0) goto LAB_14001730b;
      if (local_98[0] != '\0') {
        *param_6 = (longlong)ppppuVar6[2];
        goto LAB_140017305;
      }
      pppppuVar17 = param_3;
      uVar21 = MountMgrQueryVolumePaths
                         (param_1,(undefined8 ****)ppppuVar6[2],param_3,local_88 + uVar16,&local_94,
                          param_6);
      local_90 = (uint)uVar21;
      uVar21 = uVar21 & 0xffffffff;
      if (*(longlong *)(param_1 + 0x150) != local_60) {
        plVar8 = *(longlong **)(param_1 + 0x10);
        if (plVar8 != (longlong *)(param_1 + 0x10)) {
          while (pppuVar3 != (undefined8 ***)plVar8[0x16]) {
            plVar8 = (longlong *)*plVar8;
            if (plVar8 == (longlong *)(param_1 + 0x10)) goto LAB_140017125;
          }
          goto LAB_1400171a5;
        }
LAB_140017125:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,pppppuVar17,0xc000000e);
        }
        uVar21 = 0xc000022d;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400174f3;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x139,pppppuVar17,0xc000022d);
        }
LAB_14001717d:
        uVar20 = (undefined4)uVar21;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400174f3;
        uVar11 = 0x13a;
        goto LAB_1400174ea;
      }
LAB_1400171a5:
      if ((int)local_90 < 0) goto LAB_14001717d;
      uVar7 = Feature_3131020603__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 == 0) {
        uVar10 = (uVar13 - 2) + *(ushort *)(ppppuVar6 + 3) * local_94 + *(int *)local_88[uVar16];
      }
      else {
        if (0xffffffff < (ulonglong)*(ushort *)(ppppuVar6 + 3) * (ulonglong)local_94) {
          uVar21 = 0xc0000095;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400174f3;
          uVar11 = 0x13b;
          goto LAB_1400174e4;
        }
        uVar12 = (uint)((ulonglong)*(ushort *)(ppppuVar6 + 3) * (ulonglong)local_94);
        uVar10 = *(int *)local_88[uVar16] + uVar12;
        if (uVar10 < uVar12) {
          uVar21 = 0xc0000095;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400174f3;
          uVar11 = 0x13c;
          goto LAB_1400174e4;
        }
        if (uVar10 < 2) {
          uVar21 = 0xc0000095;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400174f3;
          uVar11 = 0x13d;
          goto LAB_1400174e4;
        }
        uVar10 = (uVar10 - 2) + uVar13;
        if (uVar10 < uVar13) {
          uVar21 = 0xc0000095;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400174f3;
          uVar11 = 0x13e;
          goto LAB_1400174e4;
        }
        uVar21 = 0;
        local_90 = 0;
      }
      local_7c = local_7c + 1;
      uVar16 = (ulonglong)local_7c;
      uVar13 = uVar10;
    }
LAB_14001733e:
    pppppuVar5 = local_58;
    plVar8 = local_88;
    uVar16 = Feature_3131020603__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar16 == 0) {
LAB_14001735b:
      puVar9 = (uint *)ExAllocatePool2(0x102,uVar13 + 4,0x41746e4d);
      if (puVar9 == (uint *)0x0) {
        uVar21 = 0xc000009a;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x140);
        }
      }
      else {
        *puVar9 = uVar13;
        uVar16 = 0;
        if (pppppuVar5 != (undefined8 *****)0x0) {
          uVar16 = 3;
          *(undefined2 *)(puVar9 + 1) = *(undefined2 *)(pppppuVar5[4] + 3);
          *(undefined4 *)((longlong)puVar9 + 6) = 0x3a;
        }
        local_94 = (uint)(pppppuVar5 != (undefined8 *****)0x0);
        if (plVar8 != (longlong *)0x0) {
          uVar7 = 0;
          ppppuVar6 = param_2 + 6;
          ppppuVar15 = (undefined8 ****)*ppppuVar6;
          if (ppppuVar15 != ppppuVar6) {
            do {
              uVar21 = 0;
              puVar18 = (uint *)plVar8[uVar7];
              if (*puVar18 >> 1 != 1) {
                do {
                  uVar13 = (uint)uVar16;
                  if (*(short *)((longlong)puVar18 + uVar21 * 2 + 4) == 0) {
                    memmove((void *)((longlong)puVar9 + uVar16 * 2 + 4),ppppuVar15[4],
                            (ulonglong)*(ushort *)(ppppuVar15 + 3));
                    uVar13 = uVar13 + (*(ushort *)(ppppuVar15 + 3) >> 1);
                    *(undefined2 *)((longlong)puVar9 + (ulonglong)uVar13 * 2 + 4) = 0;
                    local_94 = local_94 + 1;
                  }
                  else {
                    *(undefined2 *)((longlong)puVar9 + uVar16 * 2 + 4) =
                         *(undefined2 *)((longlong)puVar18 + uVar21 * 2 + 4);
                  }
                  puVar18 = (uint *)plVar8[uVar7];
                  uVar21 = (ulonglong)((int)uVar21 + 1);
                  uVar16 = (ulonglong)(uVar13 + 1);
                } while (uVar21 < (ulonglong)(*puVar18 >> 1) - 1);
              }
              ppppuVar15 = (undefined8 ****)*ppppuVar15;
              uVar7 = (ulonglong)((int)uVar7 + 1);
              plVar8 = local_88;
            } while (ppppuVar15 != ppppuVar6);
            uVar21 = (ulonglong)local_90;
          }
        }
        *(undefined2 *)((longlong)puVar9 + uVar16 * 2 + 4) = 0;
        *param_4 = puVar9;
        *param_5 = local_94;
      }
    }
    else {
      if (3 < uVar13 + 4) {
        uVar21 = 0;
        local_90 = 0;
        goto LAB_14001735b;
      }
      uVar21 = 0xc0000095;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar11 = 0x13f;
LAB_1400174e4:
        uVar21 = 0xc0000095;
        uVar20 = 0xc0000095;
LAB_1400174ea:
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,pppppuVar17,uVar20);
      }
    }
LAB_1400174f3:
    plVar8 = local_88;
    if (local_88 != (longlong *)0x0) {
      if (local_80 != 0) {
        uVar16 = (ulonglong)local_80;
        plVar14 = local_88;
        do {
          if (*plVar14 != 0) {
            ExFreePoolWithTag(*plVar14,0);
          }
          plVar14 = plVar14 + 1;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
      ExFreePoolWithTag(plVar8,0);
    }
  }
  else {
    do {
      ppppuVar6 = (undefined8 ****)*ppppuVar6;
      uVar10 = uVar10 + 1;
    } while (ppppuVar6 != ppppuVar15);
    local_80 = uVar10;
    if (uVar10 == 0) goto LAB_140016f87;
    pppppuVar17 = (undefined8 *****)0x41746e4d;
    local_88 = (longlong *)ExAllocatePool2(0x100,uVar10 * 8);
    if (local_88 != (longlong *)0x0) goto LAB_140016f87;
    uVar21 = 0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x136);
    }
  }
  if (((undefined8 **********)local_78[1] == &local_78) &&
     ((undefined8 **********)*local_70 == &local_78)) {
    *local_70 = local_78;
    local_78[1] = local_70;
    return uVar21;
  }
LAB_140017573:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar21 = (*pcVar4)();
  return uVar21;
}



===== QueryDeviceName @ 140017580 =====

int QueryDeviceName(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ushort *puVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  longlong local_res18 [2];
  undefined8 local_78;
  ushort *puStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  RtlInitUnicodeString(param_2,0);
  local_res18[1] = 0;
  local_res18[0] = 0;
  lVar2 = 0;
  lVar6 = 0;
  iVar1 = IoGetDeviceObjectPointer(param_1,0x80,local_res18,local_res18 + 1);
  if (-1 < iVar1) {
    if (*(short *)(local_res18[0] + 0x58) == 0) {
      lVar2 = IoGetAttachedDeviceReference(*(undefined8 *)(local_res18[0] + 8));
      lVar6 = local_res18[0];
      local_res18[0] = 0;
      goto LAB_140017623;
    }
    iVar1 = -0x3fffffcc;
  }
  if (local_res18[0] != 0) {
    ObfDereferenceObject();
  }
  if (iVar1 < 0) {
    return iVar1;
  }
LAB_140017623:
  puVar4 = (ushort *)0x0;
  iVar1 = 0;
  uVar7 = 0;
  iVar5 = 0x102;
  local_78 = 0;
  puStack_70 = (ushort *)0x0;
  do {
    if (1 < uVar7) {
      if (-1 < iVar1) {
LAB_140017729:
        local_78._0_4_ = CONCAT22(*puVar4,*puVar4);
        puStack_70 = puVar4 + 1;
        iVar1 = RtlDuplicateUnicodeString(1,&local_78,param_2);
      }
      if (puVar4 != (ushort *)0x0) {
LAB_140017762:
        ExFreePoolWithTag(puVar4,0);
      }
LAB_140017773:
      if (lVar2 != 0) {
        ObfDereferenceObject(lVar2);
      }
      if (lVar6 != 0) {
        ObfDereferenceObject(lVar6);
      }
      return iVar1;
    }
    puVar4 = (ushort *)ExAllocatePool2(0x102,iVar5,0x41746e4d);
    if (puVar4 == (ushort *)0x0) {
      iVar1 = -0x3fffff66;
      goto LAB_140017773;
    }
    local_48 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    KeInitializeEvent(&local_58,0,0);
    lVar3 = IoBuildDeviceIoControlRequest(0x4d0008,lVar2,0,0,puVar4,iVar5,0,&local_58,&local_68);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
      goto LAB_140017762;
    }
    if (lVar6 != 0) {
      *(longlong *)(*(longlong *)(lVar3 + 0xb8) + -0x18) = lVar6;
    }
    iVar1 = IofCallDriver(lVar2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_58,0,0,0,0);
      iVar1 = (int)local_68;
    }
    if (-1 < iVar1) goto LAB_140017729;
    if (iVar1 != -0x7ffffffb) goto LAB_140017762;
    iVar5 = (*puVar4 & 0xfffffffe) + 2;
    ExFreePoolWithTag(puVar4,0);
    uVar7 = uVar7 + 1;
  } while( true );
}



===== MountMgrDeviceControl @ 140017880 =====

ulonglong MountMgrDeviceControl(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined **ppuVar1;
  undefined8 ****ppppuVar2;
  byte *pbVar3;
  uint uVar4;
  undefined **ppuVar5;
  undefined8 ****ppppuVar6;
  code *pcVar7;
  undefined8 ****ppppuVar8;
  char cVar9;
  uint uVar10;
  ushort *puVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  longlong lVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  ulonglong uVar21;
  ushort *puVar22;
  char *pcVar23;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  undefined8 ****local_38;
  undefined8 ****local_30;
  
  uVar21 = 0;
  ppuVar5 = *(undefined ***)(param_1 + 0x40);
  *(undefined8 *)(param_2 + 0x38) = 0;
  pcVar23 = (char *)0x0;
  uVar4 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x161,param_3,uVar4);
  }
  puVar16 = auStack_68;
  puVar19 = auStack_68;
  puVar17 = auStack_68;
  puVar20 = auStack_68;
  puVar18 = auStack_68;
  uVar14 = 0;
  puVar22 = (ushort *)0x0;
  local_48 = 0;
  KeWaitForSingleObject(ppuVar5 + 7);
  cVar9 = PsIsHostSilo(ppuVar5[0x2e]);
  if (cVar9 == '\0') {
    uVar13 = PsAttachSiloToCurrentThread(ppuVar5[0x2e]);
    if (uVar4 < 0x6dc001) {
      if (uVar4 == 0x6dc000) {
        pcVar23 = "IOCTL_MOUNTMGR_CREATE_POINT";
        uVar10 = MountMgrCreatePoint(ppuVar5,param_2);
        uVar21 = (ulonglong)uVar10;
      }
      else if (uVar4 < 0x6d4021) {
        if (uVar4 != 0x6d4020) {
          if (uVar4 == 0x6d0008) {
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_POINTS";
            uVar10 = MountMgrQueryPoints((longlong)ppuVar5,param_2,(ulonglong)puVar22);
            uVar21 = (ulonglong)uVar10;
          }
          else if (uVar4 == 0x6d0030) {
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATH";
            puVar11 = MountMgrQueryDosVolumePath((longlong)ppuVar5,param_2);
            uVar21 = (ulonglong)puVar11 & 0xffffffff;
          }
          else if (uVar4 == 0x6d0034) {
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATHS";
            uVar10 = MountMgrQueryDosVolumePaths((longlong)ppuVar5,param_2);
            uVar21 = (ulonglong)uVar10;
          }
          else if (uVar4 == 0x6d003c) {
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_AUTO_MOUNT";
            uVar21 = MountMgrQueryAutoMount((longlong)ppuVar5,param_2,puVar22);
            uVar21 = uVar21 & 0xffffffff;
          }
          else {
            if (uVar4 != 0x6d4008) goto switchD_140017d36_caseD_6dc005;
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_POINTS_ADMIN";
            uVar10 = MountMgrQueryPoints((longlong)ppuVar5,param_2,(ulonglong)puVar22);
            uVar21 = (ulonglong)uVar10;
          }
        }
      }
      else if (uVar4 != 0x6d4028) {
        if (uVar4 == 0x6d402c) {
          pcVar23 = "IOCTL_MOUNTMGR_VOLUME_ARRIVAL_NOTIFICATION";
          KeReleaseMutex(ppuVar5 + 7,0);
          uVar10 = MountMgrVolumeArrivalNotification(ppuVar5,param_2);
          lVar15 = param_2;
        }
        else {
          if (uVar4 == 0x6d4048) {
            pcVar23 = "IOCTL_MOUNTMGR_TRACELOG_CACHE";
            uVar21 = MountMgrTracelogCache((ulonglong)ppuVar5);
            uVar21 = uVar21 & 0xffffffff;
            goto switchD_140017d36_caseD_6dc014;
          }
          if (uVar4 != 0x6d4058) goto switchD_140017d36_caseD_6dc005;
          pcVar23 = "IOCTL_MOUNTMGR_VOLUME_REMOVAL_NOTIFICATION";
          KeReleaseMutex(ppuVar5 + 7,0);
          uVar10 = MountMgrVolumeRemovalNotification((longlong)ppuVar5,param_2);
          lVar15 = param_2;
        }
        uVar21 = (ulonglong)uVar10;
        PsDetachSiloFromCurrentThread(uVar13);
        goto LAB_140017a3b;
      }
    }
    else {
      switch(uVar4) {
      case 0x6dc004:
      case 0x6dc00c:
      case 0x6dc040:
      case 0x6dc044:
      case 0x6dc04c:
      case 0x6dc050:
      case 0x6dc054:
        uVar21 = 0xc00000bb;
        break;
      default:
switchD_140017d36_caseD_6dc005:
        pcVar23 = "IOCTL UNKNOWN";
        uVar21 = 0xc0000010;
        break;
      case 0x6dc010:
        pcVar23 = "IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER";
        uVar10 = MountMgrNextDriveLetter(ppuVar5,param_2,puVar22,uVar14);
        uVar21 = (ulonglong)uVar10;
        break;
      case 0x6dc014:
      case 0x6dc018:
      case 0x6dc01c:
      case 0x6dc024:
      case 0x6dc038:
        break;
      }
    }
switchD_140017d36_caseD_6dc014:
    PsDetachSiloFromCurrentThread(uVar13);
    puVar18 = auStack_68;
LAB_1400179f9:
    lVar15 = 0;
    *(undefined8 *)(puVar18 + -8) = 0x140017a08;
    KeReleaseMutex(ppuVar5 + 7);
    puVar20 = puVar18;
    if ((int)uVar21 == -1) {
      if (gBreakOnFunction == MountMgrDeviceControl) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140017a26;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined4 *)(puVar18 + 0x20) = 0xffffffff;
          *(undefined8 *)(puVar18 + -8) = 0x14001801b;
          WPP_SF_qL(uVar14);
        }
      }
LAB_140017adc:
      puVar18 = puVar20;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(int *)(puVar20 + 0x20) = (int)uVar21;
        *(undefined8 *)(puVar20 + -8) = 0x140017b07;
        WPP_SF_LL(uVar14,lVar15,puVar22,uVar4,puVar20[0x20]);
      }
    }
    else if ((int)uVar21 < 0) goto LAB_140017adc;
    puVar19 = puVar18;
    if ((int)uVar21 == 0x103) goto LAB_140017a3b;
  }
  else {
    if (uVar4 == 0x6d0030) {
LAB_1400179e5:
      pcVar23 = "IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATH";
      *(undefined8 *)(puVar16 + -8) = 0x1400179f7;
      puVar11 = MountMgrQueryDosVolumePath((longlong)ppuVar5,param_2);
      uVar10 = (uint)puVar11;
      puVar17 = puVar16;
      goto LAB_1400179f7;
    }
    if (uVar4 != 0x6d4028) {
      if (uVar4 == 0x6d0008) {
        pcVar23 = "IOCTL_MOUNTMGR_QUERY_POINTS";
        uVar10 = MountMgrQueryPoints((longlong)ppuVar5,param_2,(ulonglong)puVar22);
        puVar17 = auStack_68;
LAB_1400179f7:
        uVar21 = (ulonglong)uVar10;
        puVar18 = puVar17;
        goto LAB_1400179f9;
      }
      if (uVar4 < 0x6dc001) {
        if (uVar4 == 0x6dc000) {
          pcVar23 = "IOCTL_MOUNTMGR_CREATE_POINT";
          uVar10 = MountMgrCreatePoint(ppuVar5,param_2);
          puVar17 = auStack_68;
        }
        else if (uVar4 == 0x6d4020) {
          pcVar23 = "IOCTL_MOUNTMGR_CHANGE_NOTIFY";
          uVar14 = MountMgrChangeNotify((longlong)ppuVar5,param_2,puVar22);
          uVar10 = (uint)uVar14;
          puVar17 = auStack_68;
        }
        else if (uVar4 < 0x6d4021) {
          if (uVar4 == 0x6d0034) {
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATHS";
            uVar10 = MountMgrQueryDosVolumePaths((longlong)ppuVar5,param_2);
            puVar17 = auStack_68;
          }
          else if (uVar4 == 0x6d003c) {
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_AUTO_MOUNT";
            uVar14 = MountMgrQueryAutoMount((longlong)ppuVar5,param_2,puVar22);
            uVar10 = (uint)uVar14;
            puVar17 = auStack_68;
          }
          else {
            if (uVar4 != 0x6d4008) goto switchD_140017e79_caseD_6dc005;
            pcVar23 = "IOCTL_MOUNTMGR_QUERY_POINTS_ADMIN";
            uVar10 = MountMgrQueryPoints((longlong)ppuVar5,param_2,(ulonglong)puVar22);
            puVar17 = auStack_68;
          }
        }
        else {
          if (uVar4 == 0x6d402c) {
            pcVar23 = "IOCTL_MOUNTMGR_VOLUME_ARRIVAL_NOTIFICATION";
            KeReleaseMutex(ppuVar5 + 7,0);
            uVar10 = MountMgrVolumeArrivalNotification(ppuVar5,param_2);
            uVar21 = (ulonglong)uVar10;
            lVar15 = param_2;
            puVar19 = auStack_68;
            goto LAB_140017a3b;
          }
          if (uVar4 != 0x6d4048) {
            if (uVar4 == 0x6d4058) {
              pcVar23 = "IOCTL_MOUNTMGR_VOLUME_REMOVAL_NOTIFICATION";
              KeReleaseMutex(ppuVar5 + 7,0);
              uVar10 = MountMgrVolumeRemovalNotification((longlong)ppuVar5,param_2);
              uVar21 = (ulonglong)uVar10;
              lVar15 = param_2;
              puVar19 = auStack_68;
              goto LAB_140017a3b;
            }
            goto switchD_140017e79_caseD_6dc005;
          }
          pcVar23 = "IOCTL_MOUNTMGR_TRACELOG_CACHE";
          uVar14 = MountMgrTracelogCache((ulonglong)ppuVar5);
          uVar10 = (uint)uVar14;
          puVar17 = auStack_68;
        }
        goto LAB_1400179f7;
      }
      if (uVar4 - 0x6dc004 < 0x51) {
        switch(uVar4) {
        case 0x6dc004:
          pcVar23 = "IOCTL_MOUNTMGR_DELETE_POINTS";
          uVar10 = MountMgrDeletePoints((longlong)ppuVar5,param_2,(ulonglong)puVar22,uVar14);
          break;
        default:
          goto switchD_140017e79_caseD_6dc005;
        case 0x6dc00c:
          pcVar23 = "IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY";
          uVar10 = MountMgrDeletePointsDbOnly((longlong)ppuVar5,param_2,puVar22);
          puVar17 = auStack_68;
          break;
        case 0x6dc010:
          pcVar23 = "IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER";
          uVar10 = MountMgrNextDriveLetter(ppuVar5,param_2,puVar22,uVar14);
          puVar17 = auStack_68;
          break;
        case 0x6dc014:
          pcVar23 = "IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS";
          KeReleaseMutex(ppuVar5 + 7);
          goto LAB_140017a26;
        case 0x6dc018:
          pcVar23 = "IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED";
          KeReleaseMutex(ppuVar5 + 7,0);
          uVar21 = MountMgrVolumeMountPointCreatedIoctl(ppuVar5,param_2,puVar22);
          uVar10 = (uint)uVar21;
          puVar17 = auStack_68;
          break;
        case 0x6dc01c:
          pcVar23 = "IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED";
          KeReleaseMutex(ppuVar5 + 7,0);
          uVar10 = MountMgrVolumeMountPointDeletedIoctl(ppuVar5,param_2,puVar22);
          puVar17 = auStack_68;
          break;
        case 0x6dc024:
          pcVar23 = "IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE";
          uVar10 = MountMgrKeepLinksWhenOffline((longlong)ppuVar5,param_2);
          puVar17 = auStack_68;
          break;
        case 0x6dc038:
          pcVar23 = "IOCTL_MOUNTMGR_SCRUB_REGISTRY";
          uVar10 = MountMgrScrubRegistry(ppuVar5);
          puVar17 = auStack_68;
          break;
        case 0x6dc040:
          pcVar23 = "IOCTL_MOUNTMGR_SET_AUTO_MOUNT";
          uVar10 = MountMgrSetAutoMount((longlong)ppuVar5,param_2);
          puVar17 = auStack_68;
          break;
        case 0x6dc044:
          pcVar23 = "IOCTL_MOUNTMGR_BOOT_DL_ASSIGNMENT";
          uVar21 = MountMgrBootDriveLetterAssignment((longlong)ppuVar5,param_2);
          uVar10 = (uint)uVar21;
          puVar17 = auStack_68;
          break;
        case 0x6dc04c:
        case 0x6dc050:
          pcVar23 = "IOCTL_MOUNTMGR_PREPARE_VOLUME_REMOVAL";
          uVar10 = MountMgrPrepareVolumeDelete((longlong)ppuVar5,param_2);
          puVar17 = auStack_68;
          break;
        case 0x6dc054:
          pcVar23 = "IOCTL_MOUNTMGR_SILO_ARRIVAL";
          uVar21 = MountMgrSiloArrival(IMAGE_DOS_HEADER_140000000.e_magic +
                                       (&switchD_140017e79::switchdataD_140006be1)
                                       [(&switchD_140017e79::switchdataD_140006c15)
                                        [uVar4 - 0x6dc004]],param_2);
          uVar10 = (uint)uVar21;
          puVar17 = auStack_68;
        }
        goto LAB_1400179f7;
      }
switchD_140017e79_caseD_6dc005:
      lVar15 = 0;
      pcVar23 = "IOCTL UNKNOWN";
      uVar21 = 0xc0000010;
      KeReleaseMutex(ppuVar5 + 7);
      goto LAB_140017adc;
    }
    pcVar23 = "IOCTL_MOUNTMGR_CHECK_UNPROCESSED_VOLUMES";
    KeReleaseMutex(ppuVar5 + 7);
    local_30 = &local_38;
    local_48 = 0;
    local_38 = &local_38;
    puVar22 = (ushort *)0x0;
    KeWaitForSingleObject(ppuVar5 + 7,0,0,0);
    ppuVar1 = ppuVar5 + 4;
    if ((undefined **)*ppuVar1 != ppuVar1) {
      local_38 = (undefined8 ****)*ppuVar1;
      local_30 = (undefined8 ****)ppuVar5[5];
      *local_30 = &local_38;
      local_38[1] = &local_38;
      ppuVar5[5] = (undefined *)ppuVar1;
      *ppuVar1 = (undefined *)ppuVar1;
    }
    KeReleaseMutex(ppuVar5 + 7);
    while (ppppuVar8 = local_38, puVar18 = auStack_68, (undefined8 *****)local_38 != &local_38) {
      if (((undefined8 *****)local_38[1] != &local_38) ||
         (ppppuVar6 = (undefined8 ****)*local_38, (undefined8 ****)ppppuVar6[1] != local_38)) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        puVar16 = auStack_60;
        goto LAB_1400179e5;
      }
      ppppuVar6[1] = &local_38;
      ppppuVar2 = local_38 + 8;
      pbVar3 = (byte *)((longlong)local_38 + 0x81);
      puVar22 = (ushort *)(ulonglong)*pbVar3;
      local_38 = ppppuVar6;
      uVar12 = MountMgrMountedDeviceArrival(ppuVar5,ppppuVar2,*pbVar3);
      MountMgrFreeDeadDeviceInfo((longlong)ppppuVar8);
      if (-1 < (int)uVar21) {
        uVar21 = uVar12 & 0xffffffff;
      }
    }
  }
LAB_140017a26:
  lVar15 = 0;
  *(int *)(param_2 + 0x30) = (int)uVar21;
  *(undefined8 *)(puVar18 + -8) = 0x140017a36;
  IofCompleteRequest(param_2);
  puVar19 = puVar18;
LAB_140017a3b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(int *)(puVar19 + 0x28) = (int)uVar21;
    *(char **)(puVar19 + 0x20) = pcVar23;
    *(undefined8 *)(puVar19 + -8) = 0x14001803f;
    WPP_SF_LsL(uVar14,lVar15,puVar22,uVar4,*(char **)(puVar19 + 0x20),puVar19[0x28]);
  }
  return uVar21;
}



===== MountMgrMountedDeviceArrival @ 140018050 =====

ulonglong MountMgrMountedDeviceArrival(undefined **param_1,undefined8 param_2,char param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  short *psVar3;
  code *pcVar4;
  undefined *puVar5;
  bool bVar6;
  char cVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  longlong *plVar11;
  undefined **ppuVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  longlong *plVar15;
  undefined *puVar16;
  undefined **ppuVar17;
  undefined2 uVar18;
  char *pcVar19;
  ushort *puVar20;
  undefined1 *puVar21;
  uint uVar22;
  longlong *plVar23;
  longlong lVar24;
  undefined ***pppuVar25;
  undefined **ppuVar26;
  undefined **ppuVar27;
  undefined **ppuVar28;
  uint uVar29;
  uint local_res8 [2];
  undefined8 local_res10;
  char local_res18;
  char local_res20 [8];
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [24];
  undefined **local_78;
  longlong local_70;
  longlong lStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  local_78 = (undefined **)0x0;
  local_res8[0] = 0;
  local_res20[0] = '\0';
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  lStack_68 = 0;
  local_res10 = param_2;
  local_res18 = param_3;
  plVar11 = (longlong *)ExAllocatePool2(0x100,0xb8,0x41746e4d);
  if (plVar11 == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xab);
    }
    plVar23 = (longlong *)0xc000009a;
    goto LAB_140018e43;
  }
  ppuVar28 = (undefined **)(plVar11 + 2);
  plVar11[3] = (longlong)ppuVar28;
  plVar15 = plVar11 + 8;
  *ppuVar28 = (undefined *)ppuVar28;
  plVar23 = plVar11 + 4;
  plVar11[5] = (longlong)plVar23;
  *plVar23 = (longlong)plVar23;
  plVar23 = plVar11 + 6;
  plVar11[7] = (longlong)plVar23;
  *plVar23 = (longlong)plVar23;
  uVar9 = RtlDuplicateUnicodeString(1,param_2);
  plVar23 = (longlong *)(ulonglong)uVar9;
  if ((int)uVar9 < 0) {
    ExFreePoolWithTag(plVar11,0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xac,plVar15,uVar9);
    }
    goto LAB_140018e43;
  }
  *(char *)((longlong)plVar11 + 0x81) = param_3;
  plVar11[0x13] = (longlong)param_1;
  uVar9 = QueryDeviceInformation(param_2,(longlong)plVar11);
  ppuVar26 = (undefined **)0x0;
  pppuVar25 = (undefined ***)0x0;
  ppuVar12 = param_1 + 7;
  plVar23 = (longlong *)(ulonglong)uVar9;
  if ((int)uVar9 < 0) {
    KeWaitForSingleObject();
    ppuVar27 = param_1 + 4;
    for (ppuVar28 = (undefined **)param_1[4]; ppuVar28 != ppuVar27;
        ppuVar28 = (undefined **)*ppuVar28) {
      pppuVar25 = (undefined ***)CONCAT71((int7)((ulonglong)pppuVar25 >> 8),1);
      cVar7 = RtlEqualUnicodeString(plVar11 + 8,ppuVar28 + 8);
      if (cVar7 != '\0') {
        MountMgrFreeDeadDeviceInfo((longlong)plVar11);
        goto LAB_1400181fa;
      }
    }
    puVar2 = (undefined8 *)param_1[5];
    if ((undefined **)*puVar2 == ppuVar27) {
      *plVar11 = (longlong)ppuVar27;
      plVar11[1] = (longlong)puVar2;
      *puVar2 = plVar11;
      param_1[5] = (undefined *)plVar11;
LAB_1400181fa:
      KeReleaseMutex(ppuVar12,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xad,pppuVar25,uVar9);
      }
      goto LAB_140018e43;
    }
LAB_140018c08:
    cVar7 = '\x03';
    pcVar4 = (code *)swi(0x29);
    puVar16 = (undefined *)(*pcVar4)();
    puVar21 = auStack_b0;
    param_1 = ppuVar27;
  }
  else {
    ppuVar17 = ppuVar12;
    KeWaitForSingleObject(ppuVar12,0);
    puVar21 = auStack_b8;
    ppuVar26 = (undefined **)param_1[2];
    if (ppuVar26 != param_1 + 2) {
      do {
        ppuVar17 = ppuVar26 + 10;
        pppuVar25 = (undefined ***)CONCAT71((int7)((ulonglong)pppuVar25 >> 8),1);
        iVar10 = RtlCompareUnicodeString(ppuVar17,plVar11 + 10);
        if (iVar10 == 0) {
          KeReleaseMutex(ppuVar12,0);
          ExFreePoolWithTag(plVar11[0xc],0);
          ExFreePoolWithTag(plVar11[0xb],0);
          ExFreePoolWithTag(plVar11[9],0);
          ExFreePoolWithTag(plVar11,0);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xae,pppuVar25,uVar9);
          }
          plVar23 = (longlong *)0x0;
          goto LAB_140018e43;
        }
        ppuVar26 = (undefined **)*ppuVar26;
      } while (ppuVar26 != param_1 + 2);
      param_3 = local_res18;
    }
    param_1[0x2a] = param_1[0x2a] + 1;
    ppuVar26 = (undefined **)local_res8;
    pppuVar25 = &local_78;
    plVar11[0x16] = (longlong)param_1[0x2a];
    uVar9 = QuerySymbolicLinkNamesFromStorage
                      ((ulonglong)ppuVar17,(longlong)plVar11,(longlong *)pppuVar25,
                       (undefined4 *)ppuVar26);
    if ((int)uVar9 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        ppuVar26 = (undefined **)(ulonglong)uVar9;
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xaf,pppuVar25,uVar9);
      }
      uVar9 = 0;
      ppuVar12 = (undefined **)0x0;
      uVar29 = 0;
    }
    else {
      ppuVar12 = local_78;
      uVar29 = local_res8[0];
    }
    puVar20 = (ushort *)plVar11[0xc];
    ppuVar17 = param_1;
    local_78 = (undefined **)RemoveSavedLinks((longlong)param_1,puVar20);
    plVar23 = (longlong *)0x0;
    local_res8[0] = local_res8[0] & 0xffffff00;
    bVar6 = false;
    ppuVar27 = param_1;
    if (uVar29 != 0) {
      do {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          ppuVar26 = (undefined **)0x0;
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb0,pppuVar25,0);
        }
        if ((((*(short *)(ppuVar12 + (longlong)plVar23 * 2) == 0x60) ||
             ((*(short *)(ppuVar12 + (longlong)plVar23 * 2) == 0x62 &&
              (*(short *)(ppuVar12[(longlong)plVar23 * 2 + 1] + 0x60) == 0x5c)))) &&
            ((psVar3 = (short *)ppuVar12[(longlong)plVar23 * 2 + 1], *psVar3 == 0x5c &&
             (((((((psVar3[1] == 0x3f || (psVar3[1] == 0x5c)) && (psVar3[2] == 0x3f)) &&
                 ((psVar3[3] == 0x5c && (psVar3[4] == 0x56)))) && (psVar3[5] == 0x6f)) &&
               ((psVar3[6] == 0x6c && (psVar3[7] == 0x75)))) &&
              ((psVar3[8] == 0x6d &&
               (((psVar3[9] == 0x65 && (psVar3[10] == 0x7b)) && (psVar3[0x13] == 0x2d)))))))))) &&
           ((((psVar3[0x18] == 0x2d && (psVar3[0x1d] == 0x2d)) && (psVar3[0x22] == 0x2d)) &&
            (psVar3[0x2f] == 0x7d)))) {
          bVar6 = true;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            ppuVar26 = (undefined **)(ulonglong)uVar9;
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb1,pppuVar25,uVar9);
          }
LAB_140018664:
          uVar13 = GlobalCreateSymbolicLink
                             ((undefined1 (*) [16])(ppuVar12 + (longlong)plVar23 * 2),plVar11 + 10,
                              pppuVar25,ppuVar26);
          uVar9 = (uint)uVar13;
          if ((int)uVar9 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              ppuVar26 = (undefined **)(uVar13 & 0xffffffff);
              WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb4,pppuVar25,uVar9);
            }
            if (local_78 != (undefined **)0x0) {
              pppuVar25 = (undefined ***)(plVar11 + 10);
              cVar7 = RedirectSavedLink((longlong)local_78,
                                        (undefined1 (*) [16])(ppuVar12 + (longlong)plVar23 * 2),
                                        pppuVar25,ppuVar26);
              if (cVar7 != '\0') goto LAB_14001885d;
            }
            uVar9 = QueryDeviceName(ppuVar12 + (longlong)plVar23 * 2,&local_60);
            if ((int)uVar9 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                ppuVar26 = (undefined **)(ulonglong)uVar9;
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb5,pppuVar25,uVar9);
              }
            }
            else {
              pppuVar25 = (undefined ***)CONCAT71((int7)((ulonglong)pppuVar25 >> 8),1);
              cVar7 = RtlEqualUnicodeString(plVar11 + 10);
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                ppuVar26 = (undefined **)(ulonglong)uVar9;
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb6,pppuVar25,uVar9);
              }
              ExFreePoolWithTag(uStack_58);
              if (cVar7 != '\0') goto LAB_14001885d;
            }
            bVar8 = IsDriveLetter((short *)(ppuVar12 + (longlong)plVar23 * 2));
            if (bVar8) {
              local_res8[0] = local_res8[0] & 0xffffff00;
              DeleteFromLocalDatabase((longlong)(ppuVar12 + (longlong)plVar23 * 2),plVar11[0xc]);
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                ppuVar26 = (undefined **)(ulonglong)uVar9;
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb7,pppuVar25,uVar9);
              }
            }
            puVar20 = (ushort *)0x0;
            ExFreePoolWithTag(ppuVar12[(longlong)plVar23 * 2 + 1]);
            ppuVar17 = (undefined **)WPP_GLOBAL_Control;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              ppuVar17 = *(undefined ***)(WPP_GLOBAL_Control + 0x18);
              puVar20 = (ushort *)0xb8;
              ppuVar26 = (undefined **)(ulonglong)uVar9;
              WPP_SF_L(ppuVar17,0xb8,pppuVar25,uVar9);
            }
          }
          else {
LAB_14001885d:
            uVar14 = IsOffline((longlong)(ppuVar12 + (longlong)plVar23 * 2));
            if ((((char)uVar14 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)
                ) && (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
              ppuVar26 = (undefined **)(ulonglong)uVar9;
              WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb9,pppuVar25,uVar9);
            }
            puVar20 = (ushort *)0x28;
            pppuVar25 = (undefined ***)0x41746e4d;
            plVar15 = (longlong *)ExAllocatePool2(0x102);
            if (plVar15 == (longlong *)0x0) {
              GlobalDeleteSymbolicLink
                        ((undefined1 (*) [16])(ppuVar12 + (longlong)plVar23 * 2),puVar20,pppuVar25,
                         ppuVar26);
              puVar20 = (ushort *)0x0;
              ExFreePoolWithTag(ppuVar12[(longlong)plVar23 * 2 + 1]);
              ppuVar17 = (undefined **)WPP_GLOBAL_Control;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
                ppuVar17 = *(undefined ***)(WPP_GLOBAL_Control + 0x18);
                puVar20 = (ushort *)0xba;
                WPP_SF_(ppuVar17,0xba);
              }
            }
            else {
              puVar16 = ppuVar12[(longlong)plVar23 * 2];
              puVar5 = (ppuVar12 + (longlong)plVar23 * 2)[1];
              *(undefined1 *)(plVar15 + 2) = 1;
              plVar15[3] = (longlong)puVar16;
              plVar15[4] = (longlong)puVar5;
              ppuVar17 = (undefined **)WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                ppuVar17 = *(undefined ***)(WPP_GLOBAL_Control + 0x18);
                puVar20 = (ushort *)0xbb;
                ppuVar26 = (undefined **)(ulonglong)uVar9;
                WPP_SF_L(ppuVar17,0xbb,pppuVar25,uVar9);
              }
              puVar2 = (undefined8 *)plVar11[3];
              if ((undefined **)*puVar2 != ppuVar28) goto LAB_140018c08;
              *plVar15 = (longlong)ppuVar28;
              plVar15[1] = (longlong)puVar2;
              *puVar2 = plVar15;
              plVar11[3] = (longlong)plVar15;
            }
          }
        }
        else {
          bVar8 = IsDriveLetter((short *)(ppuVar12 + (longlong)plVar23 * 2));
          if (!bVar8) goto LAB_140018664;
          if (*(char *)((longlong)plVar11 + 0x7e) == '\0') {
            if ((char)local_res8[0] == '\0') {
              pcVar19 = local_res20;
              local_res20[0] = '\0';
              uVar9 = ObIsDosDeviceLocallyMapped();
              if ((int)uVar9 < 0) {
                local_res20[0] = '\0';
                uVar9 = 0;
              }
              if (local_res20[0] == '\0') {
                MountmgrSetDLStringCase
                          ((short *)(ppuVar12 + (longlong)plVar23 * 2),pcVar19,pppuVar25);
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  ppuVar26 = (undefined **)ppuVar12[(longlong)plVar23 * 2 + 1];
                  WPP_SF_SL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar19,pppuVar25,
                            (wchar_t *)ppuVar26,(char)uVar9);
                }
                local_res8[0] = CONCAT31(local_res8[0]._1_3_,1);
                goto LAB_140018664;
              }
              puVar16 = ppuVar12[(longlong)plVar23 * 2 + 1];
              goto LAB_14001853d;
            }
            puVar20 = (ushort *)plVar11[0xc];
            DeleteFromLocalDatabase((longlong)(ppuVar12 + (longlong)plVar23 * 2),puVar20);
            ppuVar17 = (undefined **)WPP_GLOBAL_Control;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              ppuVar17 = *(undefined ***)(WPP_GLOBAL_Control + 0x18);
              puVar20 = (ushort *)0xb2;
              ppuVar26 = (undefined **)(ulonglong)uVar9;
              WPP_SF_L(ppuVar17,0xb2,pppuVar25,uVar9);
            }
          }
          else {
            puVar16 = ppuVar12[(longlong)plVar23 * 2 + 1];
LAB_14001853d:
            ExFreePoolWithTag(puVar16);
            puVar20 = (ushort *)0x0;
            ppuVar12[(longlong)plVar23 * 2 + 1] = (undefined *)0x0;
            *(undefined2 *)(ppuVar12 + (longlong)plVar23 * 2) = 0;
            ppuVar17 = ppuVar12;
          }
        }
        uVar22 = (int)plVar23 + 1;
        plVar23 = (longlong *)(ulonglong)uVar22;
      } while (uVar22 < uVar29);
    }
    plVar23 = plVar11 + 2;
    ppuVar28 = &WPP_GLOBAL_Control;
    for (plVar15 = (longlong *)plVar11[2]; plVar15 != plVar23; plVar15 = (longlong *)*plVar15) {
      puVar20 = (ushort *)(plVar15 + 3);
      SendLinkCreated(ppuVar17,puVar20);
      ppuVar17 = (undefined **)WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        ppuVar17 = *(undefined ***)(WPP_GLOBAL_Control + 0x18);
        puVar20 = (ushort *)0xbc;
        ppuVar26 = (undefined **)(ulonglong)uVar9;
        WPP_SF_L(ppuVar17,0xbc,pppuVar25,uVar9);
      }
    }
    if (local_78 != (undefined **)0x0) {
      MountMgrFreeSavedLink((longlong)local_78,puVar20,pppuVar25,ppuVar26);
    }
    if (!bVar6) {
      puVar20 = (ushort *)0x0;
      uVar9 = CreateNewVolumeName((ushort *)&local_70,(undefined8 *)0x0,pppuVar25);
      if ((int)uVar9 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          puVar20 = (ushort *)0xbd;
          ppuVar26 = (undefined **)(ulonglong)uVar9;
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbd,pppuVar25,uVar9);
        }
      }
      else {
        ppuVar26 = (undefined **)0x3;
        lVar24 = lStack_68;
        RtlWriteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices");
        GlobalCreateSymbolicLink((undefined1 (*) [16])&local_70,plVar11 + 10,lVar24,ppuVar26);
        pppuVar25 = (undefined ***)0x41746e4d;
        plVar15 = (longlong *)ExAllocatePool2(0x102);
        if (plVar15 == (longlong *)0x0) {
          puVar20 = (ushort *)0x0;
          ExFreePoolWithTag(lStack_68);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            puVar20 = (ushort *)0xbe;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbe);
          }
        }
        else {
          plVar1 = plVar11 + 2;
          *(undefined1 *)(plVar15 + 2) = 1;
          plVar15[3] = local_70;
          plVar15[4] = lStack_68;
          puVar2 = (undefined8 *)plVar11[3];
          if ((longlong *)*puVar2 != plVar1) goto LAB_140018c08;
          plVar15[1] = (longlong)puVar2;
          *plVar15 = (longlong)plVar1;
          *puVar2 = plVar15;
          puVar20 = (ushort *)&local_70;
          plVar11[3] = (longlong)plVar15;
          SendLinkCreated(plVar1,puVar20);
        }
      }
    }
    if ((char)local_res8[0] == '\0') {
      if ((*(uint *)(plVar11 + 0xf) & 0x100) != 0) {
LAB_140018b91:
        CreateNewDriveLetterName((longlong)plVar11,puVar20,pppuVar25,ppuVar26);
        goto LAB_140018b99;
      }
      cVar7 = '\0';
      if ((((*(char *)(param_1 + 0x18) != '\0') || (*(char *)((longlong)plVar11 + 0x7c) != '\0')) &&
          (*(char *)(param_1 + 0x12) != '\0')) && (*(char *)((longlong)plVar11 + 0x7f) == '\0')) {
        cVar7 = HasNoDriveLetterEntry(plVar11[0xc]);
        if (cVar7 != '\0') goto LAB_140018b99;
        goto LAB_140018b91;
      }
    }
    else {
      *(undefined1 *)(plVar11 + 0x10) = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbf,pppuVar25,uVar9);
      }
LAB_140018b99:
      cVar7 = (char)local_res8[0];
    }
    if (param_3 == '\0') {
      RegisterForTargetDeviceNotification((longlong)param_1,(longlong)plVar11);
      cVar7 = (char)local_res8[0];
    }
    ppuVar26 = (undefined **)param_1[3];
    plVar23 = (longlong *)0x0;
    if (ppuVar26 != param_1 + 2) {
      do {
        uVar9 = 0;
        while( true ) {
          if (3 < uVar9) goto LAB_140018bf7;
          uVar22 = *(uint *)((longlong)plVar11 + (ulonglong)uVar9 * 4 + 0xa0);
          uVar29 = *(uint *)((longlong)ppuVar26 + (ulonglong)uVar9 * 4 + 0xa0);
          if (uVar22 < uVar29) break;
          if (uVar29 < uVar22) goto LAB_140018bf7;
          uVar9 = uVar9 + 1;
        }
        ppuVar26 = (undefined **)ppuVar26[1];
      } while (ppuVar26 != param_1 + 2);
LAB_140018bf7:
      cVar7 = (char)local_res8[0];
    }
    puVar16 = *ppuVar26;
    if (*(undefined ***)(puVar16 + 8) != ppuVar26) goto LAB_140018c08;
  }
  *plVar11 = (longlong)puVar16;
  plVar11[1] = (longlong)ppuVar26;
  *(longlong **)(puVar16 + 8) = plVar11;
  *ppuVar26 = (undefined *)plVar11;
  if ((*(uint *)(plVar11 + 0xf) >> 8 & 1) == 0) {
    if ((*(uint *)(plVar11 + 0xf) >> 0x15 & 1) == 0) {
      if (puVar21[0x31] == '\0') {
        if (((*(char *)(param_1 + 0x18) == '\0') && (*(char *)((longlong)plVar11 + 0x7c) == '\0'))
           && (cVar7 == '\0')) {
          cVar7 = '\0';
          if ((((undefined **)WPP_GLOBAL_Control != ppuVar28) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar18 = 0xc4;
            cVar7 = '\0';
LAB_140018d34:
            uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            *(undefined8 *)(puVar21 + -8) = 0x140018d40;
            WPP_SF_L(uVar14,uVar18,pppuVar25,0);
          }
        }
        else {
          cVar7 = '\x01';
          if ((((undefined **)WPP_GLOBAL_Control != ppuVar28) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar18 = 0xc3;
            cVar7 = '\x01';
            goto LAB_140018d34;
          }
        }
      }
      else {
        *(undefined1 *)((longlong)plVar11 + 0x85) = 1;
        cVar7 = '\0';
        if ((((undefined **)WPP_GLOBAL_Control != ppuVar28) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar18 = 0xc2;
          cVar7 = '\0';
          goto LAB_140018d34;
        }
      }
    }
    else {
      cVar7 = '\x01';
      if ((((undefined **)WPP_GLOBAL_Control != ppuVar28) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar18 = 0xc1;
        cVar7 = '\x01';
        goto LAB_140018d34;
      }
    }
  }
  else {
    pppuVar25 = (undefined ***)0x0;
    *(undefined8 *)(puVar21 + -8) = 0x140018c39;
    KeSetEvent(param_1 + 0x2b,0);
    cVar7 = '\x01';
    if ((((undefined **)WPP_GLOBAL_Control != ppuVar28) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar18 = 0xc0;
      cVar7 = '\x01';
      goto LAB_140018d34;
    }
  }
  *(undefined8 *)(puVar21 + -8) = 0x140018d4d;
  KeReleaseMutex(param_1 + 7,0);
  *(undefined8 *)(puVar21 + -8) = 0x140018d63;
  SendOnlineNotification(*(undefined8 *)(puVar21 + 200),cVar7);
  if ((((undefined **)WPP_GLOBAL_Control != ppuVar28) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar21 + -8) = 0x140018d8d;
    WPP_SF_L(uVar14,0xc5,pppuVar25,0);
  }
  if (*(longlong *)(puVar21 + 0x38) != 0) {
    *(undefined8 *)(puVar21 + -8) = 0x140018da3;
    ExFreePoolWithTag(*(longlong *)(puVar21 + 0x38),0);
  }
  if (*(char *)(param_1 + 0x12) != '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != ppuVar28) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar21 + -8) = 0x140018de0;
      WPP_SF_L(uVar14,0xc6,pppuVar25,0);
    }
    *(longlong **)(puVar21 + 0x20) = plVar23;
    *(undefined8 *)(puVar21 + -8) = 0x140018df8;
    KeWaitForSingleObject(param_1 + 7,0,0,0);
    *(undefined8 *)(puVar21 + -8) = 0x140018e08;
    ReconcileThisDatabaseWithMaster(param_1,(longlong)plVar11);
    for (ppuVar28 = (undefined **)param_1[2]; ppuVar28 != param_1 + 2;
        ppuVar28 = (undefined **)*ppuVar28) {
      if (*(char *)((longlong)ppuVar28 + 0x84) != '\0') {
        *(undefined8 *)(puVar21 + -8) = 0x140018e29;
        ReconcileThisDatabaseWithMaster(param_1,(longlong)ppuVar28);
      }
    }
    *(undefined8 *)(puVar21 + -8) = 0x140018e3e;
    KeReleaseMutex(param_1 + 7,0);
  }
LAB_140018e43:
  return (ulonglong)plVar23 & 0xffffffff;
}



===== MountMgrQueryDosVolumePath @ 140018e60 =====

ushort * MountMgrQueryDosVolumePath(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ushort *puVar2;
  short *psVar3;
  undefined8 *puVar4;
  void *pvVar5;
  int iVar6;
  undefined6 uVar7;
  longlong lVar8;
  longlong *plVar9;
  char cVar10;
  ushort uVar11;
  uint uVar12;
  ushort *puVar13;
  longlong lVar14;
  ushort uVar15;
  longlong *plVar16;
  ulonglong uVar17;
  ushort *puVar18;
  undefined2 uVar19;
  undefined8 *puVar20;
  ushort *puVar21;
  longlong *_Size;
  undefined8 *puVar22;
  longlong lVar23;
  int local_res10;
  longlong local_res20;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  longlong *local_a8;
  longlong local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  ushort *puStack_88;
  undefined8 local_80;
  ushort *puStack_78;
  longlong local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  puVar2 = *(ushort **)(param_2 + 0x18);
  local_90 = 0;
  puStack_88 = (ushort *)0x0;
  local_c8 = 0;
  uStack_c0 = (undefined2 *)0x0;
  uVar12 = *(uint *)(lVar1 + 0x10);
  local_a8 = (longlong *)0x0;
  if (uVar12 < 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return (ushort *)0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return (ushort *)0xc000000d;
    }
    uVar19 = 0x147;
LAB_140019685:
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar19,(ulonglong)uVar12,0xc000000d);
    return (ushort *)0xc000000d;
  }
  uVar11 = *puVar2;
  if ((uVar11 & 1) != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return (ushort *)0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return (ushort *)0xc000000d;
    }
    uVar19 = 0x148;
    goto LAB_140019685;
  }
  if (uVar12 < uVar11 + 2) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return (ushort *)0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return (ushort *)0xc000000d;
    }
    uVar19 = 0x149;
    goto LAB_140019685;
  }
  if (*(uint *)(lVar1 + 8) < 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return (ushort *)0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return (ushort *)0xc000000d;
    }
    uVar19 = 0x14a;
    goto LAB_140019685;
  }
  puStack_88 = puVar2 + 1;
  local_90 = (ulonglong)CONCAT22(uVar11,uVar11);
  local_70 = 0;
  uStack_68 = 0;
  local_98 = (undefined8 *)0x0;
  RtlInitUnicodeString(&local_70,0);
  local_b8 = 0;
  _Size = &local_res20;
  local_res20 = 0;
  local_a0 = 0;
  lVar23 = 0;
  uVar12 = IoGetDeviceObjectPointer(&local_90,0x80,_Size,&local_b8);
  puVar21 = (ushort *)(ulonglong)uVar12;
  if ((int)uVar12 < 0) {
LAB_14001972b:
    if (local_res20 != 0) {
      ObfDereferenceObject();
    }
    if (-1 < (int)puVar21) goto LAB_140018f62;
  }
  else {
    if (*(short *)(local_res20 + 0x58) != 0) {
      puVar21 = (ushort *)0xc0000034;
      goto LAB_14001972b;
    }
    local_a0 = IoGetAttachedDeviceReference();
    lVar23 = local_res20;
    local_res20 = 0;
LAB_140018f62:
    local_80 = 0;
    puStack_78 = (ushort *)0x0;
    local_res10 = 0x102;
    puVar18 = (ushort *)0x0;
    puVar21 = puVar18;
    puVar13 = puVar18;
    for (; (uint)puVar18 < 2; puVar18 = (ushort *)(ulonglong)((uint)puVar18 + 1)) {
      _Size = (longlong *)0x41746e4d;
      puVar13 = (ushort *)ExAllocatePool2(0x102,local_res10);
      if (puVar13 == (ushort *)0x0) {
        puVar21 = (ushort *)0xc000009a;
        goto LAB_14001909a;
      }
      local_50 = 0;
      local_60 = 0;
      uStack_58 = 0;
      local_48 = 0;
      uStack_40 = 0;
      KeInitializeEvent(&local_60,0);
      lVar8 = local_a0;
      _Size = (longlong *)0x0;
      lVar14 = IoBuildDeviceIoControlRequest
                         (0x4d0008,local_a0,0,0,puVar13,local_res10,0,&local_60,&local_48);
      if (lVar14 == 0) {
        puVar21 = (ushort *)0xc000009a;
        goto LAB_140019089;
      }
      if (lVar23 != 0) {
        *(longlong *)(*(longlong *)(lVar14 + 0xb8) + -0x18) = lVar23;
      }
      uVar12 = IofCallDriver(lVar8,lVar14);
      if (uVar12 == 0x103) {
        _Size = (longlong *)0x0;
        KeWaitForSingleObject(&local_60,0,0,0,0);
        uVar12 = (uint)local_48;
      }
      puVar21 = (ushort *)(ulonglong)uVar12;
      if (-1 < (int)uVar12) goto LAB_14001904e;
      if (uVar12 != 0x80000005) goto LAB_140019089;
      local_res10 = (*puVar13 & 0xfffffffe) + 2;
      ExFreePoolWithTag(puVar13,0);
    }
    if (-1 < (int)puVar21) {
LAB_14001904e:
      _Size = &local_70;
      local_80._0_4_ = CONCAT22(*puVar13,*puVar13);
      puStack_78 = puVar13 + 1;
      uVar12 = RtlDuplicateUnicodeString(1,&local_80);
      puVar21 = (ushort *)(ulonglong)uVar12;
    }
    if (puVar13 != (ushort *)0x0) {
LAB_140019089:
      ExFreePoolWithTag(puVar13,0);
    }
LAB_14001909a:
    if (local_a0 != 0) {
      ObfDereferenceObject(local_a0);
    }
    if (lVar23 != 0) {
      ObfDereferenceObject(lVar23);
    }
    if (-1 < (int)puVar21) {
      puVar20 = *(undefined8 **)(param_1 + 0x10);
      puVar22 = local_98;
      while( true ) {
        if (puVar20 == (undefined8 *)(param_1 + 0x10)) break;
        _Size = (longlong *)CONCAT71((int7)((ulonglong)_Size >> 8),1);
        cVar10 = RtlEqualUnicodeString(&local_70,puVar20 + 10);
        puVar22 = puVar20;
        if (cVar10 != '\0') break;
        puVar20 = (undefined8 *)*puVar20;
      }
      ExFreePoolWithTag(uStack_68,0);
      if (puVar20 != (undefined8 *)(param_1 + 0x10)) {
        RtlInitUnicodeString(&local_c8,0);
        puVar20 = puVar22;
        for (uVar12 = 0; uVar12 < 1000; uVar12 = uVar12 + 1) {
          _Size = puVar20 + 2;
          iVar6 = (int)local_c8;
          uVar7 = local_c8._2_6_;
          uVar11 = (ushort)local_c8;
          plVar16 = (longlong *)puVar20[2];
          if ((longlong *)puVar20[2] != _Size) {
            do {
              local_a8 = plVar16;
              if ((((((((short)local_a8[3] == 0x1c) &&
                      (psVar3 = (short *)local_a8[4], *psVar3 == 0x5c)) && (psVar3[1] == 0x44)) &&
                    (((psVar3[2] == 0x6f && (psVar3[3] == 0x73)) &&
                     ((psVar3[4] == 0x44 && ((psVar3[5] == 0x65 && (psVar3[6] == 0x76)))))))) &&
                   (psVar3[7] == 0x69)) &&
                  (((((psVar3[8] == 99 && (psVar3[9] == 0x65)) && (psVar3[10] == 0x73)) &&
                    ((psVar3[0xb] == 0x5c && ((ushort)(psVar3[0xc] - 0x41U) < 0x1a)))) &&
                   (psVar3[0xd] == 0x3a)))) && (plVar16 = local_a8, (char)local_a8[2] != '\0'))
              break;
              plVar16 = (longlong *)*local_a8;
            } while (plVar16 != _Size);
            if (plVar16 != _Size) {
              local_b8 = local_c8;
              uStack_b0 = (undefined4)uStack_c0;
              uStack_ac = uStack_c0._4_4_;
              uVar15 = (ushort)(iVar6 + 4U);
              if (uVar15 < uVar11) {
                local_c8 = CONCAT62(uVar7,0xffff);
                if (uStack_c0 != (undefined2 *)0x0) {
                  ExFreePoolWithTag(uStack_c0,0);
                }
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return (ushort *)0xc0000095;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                  return (ushort *)0xc0000095;
                }
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14c,_Size,0xc0000095);
                return (ushort *)0xc0000095;
              }
              _Size = (longlong *)0x41746e4d;
              local_c8._0_4_ = CONCAT22(uVar15,uVar15);
              uStack_c0 = (undefined2 *)ExAllocatePool2(0x102,iVar6 + 4U & 0xffff);
              plVar16 = local_a8;
              if (uStack_c0 == (undefined2 *)0x0) {
                if (CONCAT44(uStack_ac,uStack_b0) != 0) {
                  ExFreePoolWithTag(CONCAT44(uStack_ac,uStack_b0),0);
                }
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return (ushort *)0xc000009a;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
                  return (ushort *)0xc000009a;
                }
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14d);
                return (ushort *)0xc000009a;
              }
              pvVar5 = (void *)CONCAT44(uStack_ac,uStack_b0);
              *uStack_c0 = *(undefined2 *)(local_a8[4] + 0x18);
              uStack_c0[1] = 0x3a;
              if (pvVar5 != (void *)0x0) {
                _Size = (longlong *)(local_b8 & 0xffff);
                memmove(uStack_c0 + 2,pvVar5,(size_t)_Size);
                ExFreePoolWithTag(pvVar5,0);
              }
              goto LAB_14001928b;
            }
          }
          puVar4 = (undefined8 *)puVar20[6];
          if (puVar4 == puVar20 + 6) break;
          local_b8 = local_c8;
          uStack_b0 = (undefined4)uStack_c0;
          uStack_ac = uStack_c0._4_4_;
          uVar15 = uVar11 + *(short *)(puVar4 + 3);
          if (uVar15 < uVar11) {
            local_c8 = CONCAT62(uVar7,0xffff);
            if (uStack_c0 != (undefined2 *)0x0) {
              ExFreePoolWithTag(uStack_c0,0);
            }
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) {
              return (ushort *)0xc0000095;
            }
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14e,_Size,0xc0000095);
            return (ushort *)0xc0000095;
          }
          local_c8._0_4_ = CONCAT22(uVar15,uVar15);
          uStack_c0 = (undefined2 *)ExAllocatePool2(0x102,uVar15,0x41746e4d);
          if (uStack_c0 == (undefined2 *)0x0) {
            if (CONCAT44(uStack_ac,uStack_b0) != 0) {
              ExFreePoolWithTag(CONCAT44(uStack_ac,uStack_b0),0);
            }
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return (ushort *)0xc000009a;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
              return (ushort *)0xc000009a;
            }
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14f);
            return (ushort *)0xc000009a;
          }
          _Size = (longlong *)(ulonglong)*(ushort *)(puVar4 + 3);
          memmove(uStack_c0,(void *)puVar4[4],(size_t)_Size);
          pvVar5 = (void *)CONCAT44(uStack_ac,uStack_b0);
          if (pvVar5 != (void *)0x0) {
            _Size = (longlong *)(local_b8 & 0xffff);
            memmove(uStack_c0 + (*(ushort *)(puVar4 + 3) >> 1),pvVar5,(size_t)_Size);
            ExFreePoolWithTag(pvVar5);
          }
          puVar20 = (undefined8 *)puVar4[2];
        }
        plVar16 = local_a8;
LAB_14001928b:
        if (((ushort)local_c8 < 4) || (uStack_c0[1] != 0x3a)) {
          if (uStack_c0 != (undefined2 *)0x0) {
            ExFreePoolWithTag(uStack_c0,0);
            RtlInitUnicodeString(&local_c8,0);
          }
          plVar9 = (longlong *)puVar22[2];
          while( true ) {
            if (plVar9 == puVar22 + 2) break;
            plVar16 = plVar9;
            if ((((short)plVar9[3] == 0x60) ||
                (((short)plVar9[3] == 0x62 && (*(short *)(plVar9[4] + 0x60) == 0x5c)))) &&
               (psVar3 = (short *)plVar9[4], *psVar3 == 0x5c)) {
              uVar11 = psVar3[1];
              _Size = (longlong *)(ulonglong)uVar11;
              if (((((uVar11 == 0x3f) || (uVar11 == 0x5c)) && (psVar3[2] == 0x3f)) &&
                  (((psVar3[3] == 0x5c && (psVar3[4] == 0x56)) &&
                   ((psVar3[5] == 0x6f && ((psVar3[6] == 0x6c && (psVar3[7] == 0x75)))))))) &&
                 (((psVar3[8] == 0x6d &&
                   ((((psVar3[9] == 0x65 && (psVar3[10] == 0x7b)) && (psVar3[0x13] == 0x2d)) &&
                    ((psVar3[0x18] == 0x2d && (psVar3[0x1d] == 0x2d)))))) &&
                  ((psVar3[0x22] == 0x2d && (psVar3[0x2f] == 0x7d)))))) break;
            }
            plVar9 = (longlong *)*plVar9;
          }
          if (plVar9 != puVar22 + 2) {
            uVar11 = *(ushort *)(plVar16 + 3);
            local_c8 = CONCAT62(local_c8._2_6_,uVar11);
            if (uVar11 < 4) {
              uVar11 = 4;
              local_c8 = CONCAT62(local_c8._2_6_,4);
            }
            local_c8._0_4_ = CONCAT22(uVar11,(ushort)local_c8);
            uStack_c0 = (undefined2 *)ExAllocatePool2(0x102,uVar11,0x41746e4d);
            if (uStack_c0 == (undefined2 *)0x0) {
              return (ushort *)0xc000009a;
            }
            _Size = (longlong *)(local_c8 & 0xffff);
            memmove(uStack_c0,(void *)plVar16[4],(size_t)_Size);
            uStack_c0[1] = 0x5c;
          }
        }
        if (uStack_c0 == (undefined2 *)0x0) {
          return (ushort *)0xc0000225;
        }
        *(uint *)puVar2 = (ushort)local_c8 + 4;
        uVar17 = (ulonglong)((ushort)local_c8 + 8);
        *(ulonglong *)(param_2 + 0x38) = uVar17;
        if (uVar17 <= *(uint *)(lVar1 + 8)) {
          uVar11 = 0;
          if ((ushort)local_c8 != 0) {
            memmove(puVar2 + 2,uStack_c0,local_c8 & 0xffff);
            uVar11 = (ushort)local_c8;
          }
          if (uStack_c0 != (undefined2 *)0x0) {
            ExFreePoolWithTag(uStack_c0,0);
            uVar11 = (ushort)local_c8;
          }
          puVar2[(ulonglong)(uVar11 >> 1) + 2] = 0;
          puVar2[(local_c8 >> 1 & 0x7fff) + 3] = 0;
          return (ushort *)0x0;
        }
        ExFreePoolWithTag(uStack_c0,0);
        *(undefined8 *)(param_2 + 0x38) = 4;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x150,_Size,0x80000005);
        }
        return (ushort *)0x80000005;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,_Size,0xc0000034);
      }
      puVar21 = (ushort *)0xc0000034;
      goto LAB_1400194e9;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,_Size,(int)puVar21);
  }
LAB_1400194e9:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14b,_Size,(int)puVar21);
  }
  return puVar21;
}



===== MountMgrQueryPoints @ 140019a00 =====

int MountMgrQueryPoints(longlong param_1,longlong param_2,ulonglong param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  uint *puVar5;
  int iVar6;
  ushort *puVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined8 local_38;
  void *pvStack_30;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_24 = 0;
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  if (*(uint *)(lVar4 + 0x10) < 0x18) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar9 = 0xd2;
LAB_140019ca9:
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,param_3,0xc000000d);
    return -0x3ffffff3;
  }
  puVar5 = *(uint **)(param_2 + 0x18);
  uVar1 = (ushort)puVar5[1];
  param_3 = (ulonglong)uVar1;
  if (uVar1 == 0) {
    *puVar5 = 0;
    uVar12 = 0;
  }
  else {
    uVar12 = (ulonglong)*puVar5;
  }
  uVar2 = (ushort)puVar5[3];
  if (uVar2 == 0) {
    puVar5[2] = 0;
  }
  uVar3 = (ushort)puVar5[5];
  if (uVar3 == 0) {
    puVar5[4] = 0;
  }
  if ((((uVar12 & 1) != 0 || (uVar1 & 1) != 0) || ((uVar2 & 1) != 0 || (puVar5[2] & 1) != 0)) ||
     ((uVar3 & 1) != 0 || (puVar5[4] & 1) != 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar9 = 0xd3;
    goto LAB_140019ca9;
  }
  uVar10 = (ulonglong)uVar2 + (ulonglong)puVar5[2];
  uVar14 = (ulonglong)uVar3 + (ulonglong)puVar5[4];
  uVar13 = uVar12 + param_3;
  if (uVar12 + param_3 <= uVar10) {
    uVar13 = uVar10;
  }
  if (uVar13 <= uVar14) {
    uVar13 = uVar14;
  }
  if (*(uint *)(lVar4 + 0x10) < uVar13) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd4,param_3,0xc000000d);
    return -0x3ffffff3;
  }
  if (*(uint *)(lVar4 + 8) < 0x20) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd5,param_3,0xc000000d);
    return -0x3ffffff3;
  }
  if (uVar1 == 0) {
    puVar11 = (undefined8 *)0x0;
    uVar12 = 0;
  }
  else {
    if (0xf000 < uVar1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3ffffff3;
      }
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd6,param_3,0xc000000d);
      return -0x3ffffff3;
    }
    local_38 = (ulonglong)CONCAT22(uVar1 + 2,uVar1);
    pvStack_30 = (void *)ExAllocatePool2(0x102,uVar1 + 2,0x41746e4d);
    if (pvStack_30 == (void *)0x0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffff66;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return -0x3fffff66;
      }
      uVar9 = 0xd7;
      goto LAB_140019c86;
    }
    uVar12 = local_38 & 0xffff;
    memmove(pvStack_30,(void *)((ulonglong)*puVar5 + (longlong)puVar5),uVar12);
    puVar11 = &local_38;
    *(undefined2 *)((longlong)pvStack_30 + (local_38 >> 1 & 0x7fff) * 2) = 0;
  }
  if ((ushort)puVar5[3] != 0) {
    puVar7 = (ushort *)ExAllocatePool2(0x102,(ulonglong)(ushort)puVar5[3] + 2,0x41746e4d);
    if (puVar7 != (ushort *)0x0) {
      *puVar7 = (ushort)puVar5[3];
      memmove(puVar7 + 1,(void *)((ulonglong)puVar5[2] + (longlong)puVar5),
              (ulonglong)(ushort)puVar5[3]);
      iVar6 = QueryPointsFromMemory(param_1,param_2,(longlong)puVar11,puVar7,0);
      ExFreePoolWithTag(puVar7,0);
      return iVar6;
    }
    if (puVar11 == (undefined8 *)0x0) {
      return -0x3fffff66;
    }
    ExFreePoolWithTag(pvStack_30,0);
    return -0x3fffff66;
  }
  local_28 = (ushort)puVar5[5];
  if (local_28 == 0) {
    if ((short)puVar5[1] == 0) {
      iVar6 = QueryPointsFromMemory(param_1,param_2,0,(ushort *)0x0,0);
    }
    else {
      uVar8 = QueryPointsFromSymbolicLinkName(param_1,puVar11,param_2);
      iVar6 = (int)uVar8;
      ExFreePoolWithTag(puVar11[1],0);
    }
    return iVar6;
  }
  if (0xf000 < local_28) {
    if (puVar11 != (undefined8 *)0x0) {
      ExFreePoolWithTag(pvStack_30,0);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd8,uVar12,0xc000000d);
    return -0x3ffffff3;
  }
  local_26 = local_28 + 2;
  local_20 = (void *)ExAllocatePool2(0x102,local_26,0x41746e4d);
  if (local_20 != (void *)0x0) {
    memmove(local_20,(void *)((ulonglong)puVar5[4] + (longlong)puVar5),(ulonglong)local_28);
    *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
    iVar6 = QueryPointsFromMemory
                      (param_1,param_2,(longlong)puVar11,(ushort *)0x0,(longlong)&local_28);
    ExFreePoolWithTag(local_20,0);
    return iVar6;
  }
  if (puVar11 != (undefined8 *)0x0) {
    ExFreePoolWithTag(pvStack_30,0);
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return -0x3fffff66;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
    return -0x3fffff66;
  }
  uVar9 = 0xd9;
LAB_140019c86:
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9);
  return -0x3fffff66;
}



===== QueryPointsFromMemory @ 140019f20 =====

int QueryPointsFromMemory
              (longlong param_1,longlong param_2,longlong param_3,ushort *param_4,longlong param_5)

{
  ushort uVar1;
  uint *puVar2;
  ushort uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  void *_Dst;
  ushort uVar12;
  ushort *puVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong **pplVar17;
  int iVar18;
  longlong *plVar19;
  uint local_b8;
  longlong *local_b0;
  ushort local_a8;
  uint local_a4;
  longlong *local_a0;
  longlong lStack_98;
  ulonglong local_90;
  undefined8 local_88;
  ushort *puStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  local_a0 = (longlong *)0x0;
  lStack_98 = 0;
  if (param_5 != 0) {
    RtlInitUnicodeString(&local_a0,0);
    local_90 = 0;
    pplVar17 = &local_b0;
    local_b0 = (longlong *)0x0;
    lVar7 = 0;
    plVar19 = (longlong *)0x0;
    iVar5 = IoGetDeviceObjectPointer(param_5,0x80,pplVar17,&local_90);
    if (iVar5 < 0) {
LAB_14001a5f3:
      if (local_b0 != (longlong *)0x0) {
        ObfDereferenceObject();
      }
      if (iVar5 < 0) goto LAB_14001a60c;
    }
    else {
      if ((short)local_b0[0xb] != 0) {
        iVar5 = -0x3fffffcc;
        goto LAB_14001a5f3;
      }
      lVar7 = IoGetAttachedDeviceReference(local_b0[1]);
      plVar19 = local_b0;
      local_b0 = (longlong *)0x0;
    }
    puVar13 = (ushort *)0x0;
    iVar5 = 0;
    local_88 = (longlong *)0x0;
    puStack_80 = (ushort *)0x0;
    iVar18 = 0x102;
    for (uVar11 = 0; uVar11 < 2; uVar11 = uVar11 + 1) {
      pplVar17 = (longlong **)0x41746e4d;
      puVar13 = (ushort *)ExAllocatePool2(0x102,iVar18);
      if (puVar13 == (ushort *)0x0) {
        iVar5 = -0x3fffff66;
        goto LAB_14001a108;
      }
      local_68 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_60 = 0;
      uStack_58 = 0;
      KeInitializeEvent(&local_78,0);
      pplVar17 = (longlong **)0x0;
      lVar8 = IoBuildDeviceIoControlRequest(0x4d0008,lVar7,0,0,puVar13,iVar18,0,&local_78,&local_60)
      ;
      if (lVar8 == 0) {
        iVar5 = -0x3fffff66;
        goto LAB_14001a0f7;
      }
      if (plVar19 != (longlong *)0x0) {
        *(longlong **)(*(longlong *)(lVar8 + 0xb8) + -0x18) = plVar19;
      }
      iVar5 = IofCallDriver(lVar7);
      if (iVar5 == 0x103) {
        pplVar17 = (longlong **)0x0;
        KeWaitForSingleObject(&local_78,0,0,0,0);
        iVar5 = (int)local_60;
      }
      if (-1 < iVar5) goto LAB_14001a0c1;
      if (iVar5 != -0x7ffffffb) goto LAB_14001a0f7;
      iVar18 = (*puVar13 & 0xfffffffe) + 2;
      ExFreePoolWithTag(puVar13,0);
    }
    if (-1 < iVar5) {
LAB_14001a0c1:
      pplVar17 = &local_a0;
      local_88._0_4_ = CONCAT22(*puVar13,*puVar13);
      puStack_80 = puVar13 + 1;
      iVar5 = RtlDuplicateUnicodeString(1,&local_88);
    }
    if (puVar13 != (ushort *)0x0) {
LAB_14001a0f7:
      ExFreePoolWithTag(puVar13,0);
    }
LAB_14001a108:
    if (lVar7 != 0) {
      ObfDereferenceObject(lVar7);
    }
    if (plVar19 != (longlong *)0x0) {
      ObfDereferenceObject(plVar19);
    }
    if (iVar5 < 0) {
LAB_14001a60c:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar5;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar5;
      }
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xcf,pplVar17,iVar5);
      return iVar5;
    }
  }
  iVar5 = 0;
  plVar16 = *(longlong **)(param_1 + 0x10);
  plVar19 = (longlong *)(param_1 + 0x10);
  local_b8 = 0;
  uVar9 = 0;
  local_b0 = plVar19;
  if (plVar16 != plVar19) {
    do {
      if (param_4 == (ushort *)0x0) {
        if (param_5 == 0) goto LAB_14001a223;
        cVar4 = RtlEqualUnicodeString(&local_a0,plVar16 + 10,CONCAT71((int7)(uVar9 >> 8),1));
        if (cVar4 != '\0') goto LAB_14001a21f;
      }
      else if ((*param_4 == *(ushort *)plVar16[0xc]) &&
              (uVar9 = RtlCompareMemory(param_4 + 1,(ushort *)plVar16[0xc] + 1,*param_4),
              uVar9 == *param_4)) {
LAB_14001a21f:
        uVar9 = (ulonglong)local_b8;
LAB_14001a223:
        plVar15 = plVar16 + 2;
        plVar14 = (longlong *)*plVar15;
        iVar5 = iVar5 + (uint)*(ushort *)(plVar16 + 10) + (uint)*(ushort *)plVar16[0xc];
        if (plVar14 != plVar15) {
          do {
            uVar11 = (uint)uVar9;
            if (param_3 == 0) {
LAB_14001a24e:
              local_b8 = uVar11 + 1;
              iVar5 = iVar5 + (uint)*(ushort *)(plVar14 + 3);
            }
            else {
              cVar4 = RtlEqualUnicodeString(param_3,plVar14 + 3,CONCAT71((int7)(uVar9 >> 8),1));
              uVar11 = local_b8;
              if (cVar4 != '\0') goto LAB_14001a24e;
            }
            uVar9 = (ulonglong)local_b8;
            plVar14 = (longlong *)*plVar14;
          } while (plVar14 != plVar15);
          plVar19 = local_b0;
        }
        if ((param_4 != (ushort *)0x0) || (param_5 != 0)) goto LAB_14001a27e;
      }
      plVar16 = (longlong *)*plVar16;
      uVar9 = (ulonglong)local_b8;
    } while (plVar16 != plVar19);
  }
  if (param_4 == (ushort *)0x0) {
    if (param_5 != 0) {
LAB_14001a27e:
      if (plVar16 == (longlong *)(param_1 + 0x10)) goto LAB_14001a1ab;
      if ((param_3 != 0) && ((int)uVar9 == 0)) {
        if ((param_5 != 0) && (lStack_98 != 0)) {
          ExFreePoolWithTag(lStack_98,0);
        }
        return -0x3fffffcc;
      }
    }
    puVar2 = *(uint **)(param_2 + 0x18);
    lVar7 = *(longlong *)(param_2 + 0xb8);
    uVar11 = ((uint)uVar9 * 3 + 1) * 8 + iVar5;
    *puVar2 = uVar11;
    puVar2[1] = (uint)uVar9;
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar11;
    if (*(uint *)(lVar7 + 8) < *puVar2) {
      *(undefined8 *)(param_2 + 0x38) = 8;
      if (param_5 != 0) {
        ExFreePoolWithTag(lStack_98,0);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd1,uVar9,0x80000005);
      }
      iVar5 = -0x7ffffffb;
    }
    else {
      memset((void *)(*(longlong *)(param_2 + 0x18) + 8),0,uVar9 * 0x18);
      plVar16 = *(longlong **)(param_1 + 0x10);
      uVar9 = (ulonglong)(*puVar2 - iVar5);
      plVar19 = (longlong *)(param_1 + 0x10);
      local_90 = local_90 & 0xffffffff00000000;
      local_88 = plVar19;
      if (plVar16 != plVar19) {
        do {
          if (param_4 == (ushort *)0x0) {
            if ((param_5 == 0) ||
               (cVar4 = RtlEqualUnicodeString(&local_a0,plVar16 + 10,1), cVar4 != '\0'))
            goto LAB_14001a394;
          }
          else if ((*param_4 == *(ushort *)plVar16[0xc]) &&
                  (uVar10 = RtlCompareMemory(param_4 + 1,(ushort *)plVar16[0xc] + 1,*param_4),
                  uVar10 == *param_4)) {
LAB_14001a394:
            uVar1 = *(ushort *)(plVar16 + 10);
            iVar5 = (int)uVar9;
            local_b0 = (longlong *)CONCAT44(local_b0._4_4_,iVar5);
            _Dst = (void *)(uVar9 + (longlong)puVar2);
            local_a8 = *(ushort *)plVar16[0xc];
            local_a4 = (uint)local_a8 + iVar5;
            uVar9 = (ulonglong)(iVar5 + (uint)local_a8 + (uint)uVar1);
            memmove(_Dst,(ushort *)plVar16[0xc] + 1,(ulonglong)local_a8);
            memmove((void *)((ulonglong)local_a4 + (longlong)puVar2),(void *)plVar16[0xb],
                    (ulonglong)uVar1);
            uVar3 = local_a8;
            plVar15 = (longlong *)plVar16[2];
            if (plVar15 != plVar16 + 2) {
              uVar11 = (uint)local_90;
              do {
                if ((param_3 == 0) ||
                   (cVar4 = RtlEqualUnicodeString(param_3,plVar15 + 3,1), cVar4 != '\0')) {
                  uVar10 = (ulonglong)uVar11;
                  puVar2[uVar10 * 6 + 2] = (uint)uVar9;
                  *(short *)(puVar2 + uVar10 * 6 + 3) = (short)plVar15[3];
                  if ((char)plVar15[2] == '\0') {
                    uVar6 = 0;
                    uVar12 = 0;
                  }
                  else {
                    uVar6 = (uint)local_b0;
                    uVar12 = uVar3;
                  }
                  puVar2[uVar10 * 6 + 4] = uVar6;
                  *(ushort *)(puVar2 + uVar10 * 6 + 5) = uVar12;
                  puVar2[uVar10 * 6 + 6] = local_a4;
                  *(ushort *)(puVar2 + uVar10 * 6 + 7) = uVar1;
                  memmove((void *)(uVar9 + (longlong)puVar2),(void *)plVar15[4],
                          (ulonglong)*(ushort *)(plVar15 + 3));
                  uVar9 = (ulonglong)((uint)uVar9 + (uint)*(ushort *)(plVar15 + 3));
                  uVar11 = uVar11 + 1;
                }
                plVar15 = (longlong *)*plVar15;
              } while (plVar15 != plVar16 + 2);
              local_90 = CONCAT44(local_90._4_4_,uVar11);
              plVar19 = local_88;
            }
            if (param_4 != (ushort *)0x0) break;
            if (param_5 != 0) goto LAB_14001a487;
          }
          plVar16 = (longlong *)*plVar16;
        } while (plVar16 != plVar19);
      }
      if (param_5 != 0) {
LAB_14001a487:
        ExFreePoolWithTag(lStack_98,0);
      }
      iVar5 = 0;
    }
  }
  else {
LAB_14001a1ab:
    if ((param_5 != 0) && (lStack_98 != 0)) {
      ExFreePoolWithTag(lStack_98,0);
      lStack_98 = 0;
      local_a0 = (longlong *)((ulonglong)local_a0 & 0xffffffff00000000);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd0,uVar9,0xc000000d);
    }
    iVar5 = -0x3ffffff3;
  }
  return iVar5;
}



===== QueryPointsFromSymbolicLinkName @ 14001a690 =====

undefined8 QueryPointsFromSymbolicLinkName(longlong param_1,undefined8 param_2,longlong param_3)

{
  ushort uVar1;
  uint *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined8 *puVar12;
  ushort uVar13;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar13 = 0;
  puVar9 = (undefined8 *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  lVar11 = param_3;
  iVar6 = QueryDeviceName(param_2,&local_38);
  puVar10 = *(undefined8 **)(param_1 + 0x10);
  puVar12 = (undefined8 *)(param_1 + 0x10);
  if (iVar6 < 0) {
    for (; puVar10 != puVar12; puVar10 = (undefined8 *)*puVar10) {
      for (puVar9 = (undefined8 *)puVar10[2]; puVar9 != puVar10 + 2; puVar9 = (undefined8 *)*puVar9)
      {
        if (puVar9 == (undefined8 *)0x0) {
          return 0xc0000225;
        }
        lVar11 = CONCAT71((int7)((ulonglong)lVar11 >> 8),1);
        cVar5 = RtlEqualUnicodeString(param_2,puVar9 + 3);
        if (cVar5 != '\0') goto LAB_14001a7da;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xcd,lVar11,0xc0000034);
    }
    uVar7 = 0xc0000034;
  }
  else {
    while( true ) {
      puVar4 = puVar10;
      puVar10 = puVar9;
      if (puVar4 == puVar12) break;
      lVar11 = CONCAT71((int7)((ulonglong)lVar11 >> 8),1);
      iVar6 = RtlCompareUnicodeString(&local_38,puVar4 + 10);
      puVar10 = puVar4;
      if (iVar6 == 0) break;
      puVar10 = (undefined8 *)*puVar4;
      puVar9 = puVar4;
    }
    ExFreePoolWithTag(uStack_30,0);
    if (puVar4 == puVar12) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xcc,lVar11,0xc000000d);
      }
    }
    else {
      for (puVar9 = (undefined8 *)puVar10[2]; puVar9 != puVar10 + 2; puVar9 = (undefined8 *)*puVar9)
      {
        if (puVar9 == (undefined8 *)0x0) {
          return 0xc0000225;
        }
        lVar11 = CONCAT71((int7)((ulonglong)lVar11 >> 8),1);
        cVar5 = RtlEqualUnicodeString(param_2,puVar9 + 3);
        if (cVar5 != '\0') {
LAB_14001a7da:
          if ((puVar10 == (undefined8 *)0x0) || (puVar9 == (undefined8 *)0x0)) {
            return 0xc0000225;
          }
          puVar2 = *(uint **)(param_3 + 0x18);
          uVar8 = (uint)*(ushort *)(puVar10 + 10) +
                  (uint)*(ushort *)puVar10[0xc] + *(ushort *)(puVar9 + 3) + 0x20;
          lVar3 = *(longlong *)(param_3 + 0xb8);
          *puVar2 = uVar8;
          puVar2[1] = 1;
          *(ulonglong *)(param_3 + 0x38) = (ulonglong)uVar8;
          if (uVar8 <= *(uint *)(lVar3 + 8)) {
            lVar11 = *(longlong *)(param_3 + 0x18);
            *(undefined8 *)(lVar11 + 8) = 0;
            *(undefined8 *)(lVar11 + 0x10) = 0;
            *(undefined8 *)(lVar11 + 0x18) = 0;
            puVar2[2] = 0x20;
            uVar1 = *(ushort *)(puVar9 + 3);
            *(ushort *)(puVar2 + 3) = uVar1;
            if (*(char *)(puVar9 + 2) == '\0') {
              puVar2[4] = 0;
            }
            else {
              puVar2[4] = uVar1 + 0x20;
              uVar13 = *(ushort *)puVar10[0xc];
            }
            *(ushort *)(puVar2 + 5) = uVar13;
            puVar2[6] = uVar1 + 0x20 + (uint)uVar13;
            *(undefined2 *)(puVar2 + 7) = *(undefined2 *)(puVar10 + 10);
            memmove(puVar2 + 8,(void *)puVar9[4],(ulonglong)uVar1);
            if (*(char *)(puVar9 + 2) != '\0') {
              memmove((void *)((ulonglong)puVar2[4] + (longlong)puVar2),(void *)(puVar10[0xc] + 2),
                      (ulonglong)(ushort)puVar2[5]);
            }
            memmove((void *)((ulonglong)puVar2[6] + (longlong)puVar2),(void *)puVar10[0xb],
                    (ulonglong)(ushort)puVar2[7]);
            return 0;
          }
          *(undefined8 *)(param_3 + 0x38) = 0x20;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xce,lVar11,0x80000005);
          }
          return 0x80000005;
        }
      }
    }
    uVar7 = 0xc000000d;
  }
  return uVar7;
}



===== MountMgrDeletePoints @ 14001a970 =====

int MountMgrDeletePoints(longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4)

{
  longlong lVar1;
  short sVar2;
  ushort uVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  short sVar7;
  int iVar8;
  ushort *puVar9;
  void *pvVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 local_38;
  void *pvStack_30;
  undefined8 local_28;
  longlong lStack_20;
  
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  local_28 = 0;
  lStack_20 = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe2,param_3,0xc000000d);
    }
    return -0x3ffffff3;
  }
  if ((**(int **)(param_2 + 0x18) == 0) || ((short)(*(int **)(param_2 + 0x18))[1] == 0)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  iVar8 = MountMgrQueryPoints(param_1,param_2,param_3);
  if (iVar8 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe3,param_3,iVar8);
    }
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0x18);
    for (uVar11 = 0; uVar11 < *(uint *)(lVar4 + 4); uVar11 = uVar11 + 1) {
      sVar2 = *(short *)(lVar4 + 0xc + (ulonglong)uVar11 * 0x18);
      lVar1 = lVar4 + (ulonglong)uVar11 * 0x18;
      sVar7 = sVar2 + 2;
      local_38._0_4_ = CONCAT22(sVar7,sVar2);
      pvStack_30 = (void *)ExAllocatePool2(0x102,sVar7,0x41746e4d);
      if (pvStack_30 == (void *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe4);
        }
        return -0x3fffff66;
      }
      uVar12 = local_38 & 0xffff;
      pvVar10 = (void *)((ulonglong)*(uint *)(lVar1 + 8) + lVar4);
      memmove(pvStack_30,pvVar10,uVar12);
      *(undefined2 *)((longlong)pvStack_30 + (local_38 >> 1 & 0x7fff) * 2) = 0;
      if ((bVar5) && (bVar6 = IsDriveLetter((short *)&local_38), bVar6)) {
        pvVar10 = (void *)((ulonglong)*(ushort *)(lVar1 + 0x14) + 4);
        uVar12 = 0x41746e4d;
        puVar9 = (ushort *)ExAllocatePool2(0x102);
        if (puVar9 != (ushort *)0x0) {
          uVar3 = *(ushort *)(lVar1 + 0x14);
          *puVar9 = uVar3;
          uVar12 = (ulonglong)uVar3;
          pvVar10 = (void *)((ulonglong)*(uint *)(lVar1 + 0x10) + lVar4);
          memmove(puVar9 + 1,pvVar10,uVar12);
          CreateNoDriveLetterEntry(puVar9,pvVar10,uVar12);
          pvVar10 = (void *)0x0;
          ExFreePoolWithTag(puVar9);
        }
      }
      if ((uVar11 == 0) && (!bVar5)) {
        pvVar10 = (void *)((ulonglong)*(ushort *)(lVar1 + 0x14) + 4);
        uVar12 = 0x41746e4d;
        puVar9 = (ushort *)ExAllocatePool2(0x102);
        if (puVar9 != (ushort *)0x0) {
          uVar3 = *(ushort *)(lVar1 + 0x14);
          *puVar9 = uVar3;
          uVar12 = (ulonglong)uVar3;
          memmove(puVar9 + 1,(void *)((ulonglong)*(uint *)(lVar1 + 0x10) + lVar4),uVar12);
          DeleteNoDriveLetterEntry(puVar9);
          pvVar10 = (void *)0x0;
          ExFreePoolWithTag(puVar9);
        }
      }
      GlobalDeleteSymbolicLink((undefined1 (*) [16])&local_38,pvVar10,uVar12,param_4);
      uVar12 = DeleteSymbolicLinkNameFromMemory(param_1,(ushort *)&local_38,'\0');
      iVar8 = (int)uVar12;
      pvVar10 = pvStack_30;
      RtlDeleteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices");
      ExFreePoolWithTag(pvStack_30,0);
      if (iVar8 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe5,pvVar10,iVar8);
        }
        goto LAB_14001ac8b;
      }
      local_28._0_4_ = CONCAT22(*(undefined2 *)(lVar1 + 0x1c),*(undefined2 *)(lVar1 + 0x1c));
      lStack_20 = (ulonglong)*(uint *)(lVar1 + 0x18) + lVar4;
      MountMgrNotifyNameChange(param_1,&local_28,'\x01');
    }
    MountMgrNotify(param_1);
  }
LAB_14001ac8b:
  return iVar8;
}



===== GetDriveLayoutInternal @ 14001acb0 =====

ulonglong GetDriveLayoutInternal(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  
  *param_2 = 0;
  iVar3 = 0x1000;
  while( true ) {
    lVar1 = ExAllocatePool2(0x102,iVar3);
    if (lVar1 == 0) {
      return 0xc000009a;
    }
    uVar2 = MountMgrSendDeviceControl(param_1,0x70050,0,0,lVar1,iVar3,0);
    if (-1 < (int)uVar2) break;
    if ((int)uVar2 != -0x3fffffdd) {
      ExFreePoolWithTag(lVar1,0);
      return uVar2 & 0xffffffff;
    }
    iVar3 = iVar3 * 2;
    ExFreePoolWithTag();
  }
  *param_2 = lVar1;
  return uVar2;
}



===== SendOnlineNotification @ 14001ad80 =====

void SendOnlineNotification(undefined8 param_1,char param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  longlong local_res20;
  
  plVar4 = &local_res20;
  local_res20 = 0;
  iVar1 = IoGetDeviceObjectPointer(param_1,0x80);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa6,plVar4,iVar1);
    }
  }
  else {
    uVar2 = IoGetAttachedDeviceReference(*(undefined8 *)(local_res20 + 8));
    if (param_2 != '\0') {
      uVar5 = 0;
      uVar3 = MountMgrSendDeviceControl(uVar2,0x56c008,0,0,0,0,local_res20);
      if (((((int)uVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa7,uVar5,(int)uVar3);
      }
    }
    uVar5 = 0;
    uVar3 = MountMgrSendDeviceControl(uVar2,0x56c064,0,0,0,0,local_res20);
    if ((((int)uVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (WPP_GLOBAL_Control[0x29] != '\0')))) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa8,uVar5,(int)uVar3);
    }
    ObfDereferenceObject(uVar2);
    ObfDereferenceObject(local_res20);
  }
  return;
}



===== QueryDeviceInformation @ 14001af10 =====

int QueryDeviceInformation(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  uint local_res18 [2];
  undefined4 local_res20 [2];
  longlong local_38;
  longlong local_30;
  ulonglong local_28 [2];
  
  local_28[0] = 0;
  local_38 = 0;
  local_30 = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  iVar3 = OpenDevice(param_1,&local_30,&local_38);
  lVar2 = local_30;
  lVar1 = local_38;
  if (-1 < iVar3) {
    iVar3 = QueryDeviceNameInternal(local_30,local_38,param_2 + 0x50);
    if (-1 < iVar3) {
      iVar3 = QueryUniqueIdInternal(lVar2,lVar1,(undefined8 *)(param_2 + 0x60));
      if (-1 < iVar3) {
        MountMgrSendDeviceControl(lVar1,0x4d0018,0,0,param_2 + 0x68,0x10,lVar2);
        lVar4 = IoGetDeviceAttachmentBaseRef(lVar1);
        *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(lVar4 + 0x30);
        ObfDereferenceObject(lVar4);
        bVar6 = *(byte *)(lVar1 + 0x34) & 1;
        *(byte *)(param_2 + 0x7c) = bVar6;
        *(byte *)(param_2 + 0x7d) = *(byte *)(lVar1 + 0x36) & 1;
        if (bVar6 == 0) {
          uVar5 = MountMgrSendDeviceControl(lVar1,0x560038,0,0,local_28,8,0);
          if ((-1 < (int)uVar5) && ((local_28[0] & 0x8000000000000000) != 0)) {
            *(undefined1 *)(param_2 + 0x7f) = 1;
          }
          iVar3 = 0;
        }
        if ((*(char *)(param_2 + 0x81) == '\0') && ((*(uint *)(param_2 + 0x78) & 0x100) == 0)) {
          iVar3 = FsRtlGetVirtualDiskNestingLevel(lVar1,local_res20,local_res18);
          if ((-1 < iVar3) && ((local_res18[0] & 6) != 0)) {
            *(undefined2 *)(param_2 + 0x7e) = 0x101;
          }
          iVar3 = 0;
        }
        QuerySuggestedLinkNameInternal(lVar2,lVar1,param_2);
        QueryDeviceSortOrderInternal(lVar1,param_2);
      }
    }
  }
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  if (lVar2 != 0) {
    ObfDereferenceObject(lVar2);
  }
  return iVar3;
}



===== QueryUniqueIdInternal @ 14001b0f0 =====

int QueryUniqueIdInternal(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  ushort *puVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = (ushort *)0x0;
  iVar1 = 0;
  *param_3 = 0;
  iVar5 = 0x82;
  for (uVar4 = 0; uVar4 < 2; uVar4 = uVar4 + 1) {
    puVar2 = (ushort *)ExAllocatePool2(0x102,iVar5);
    if (puVar2 == (ushort *)0x0) {
      return -0x3fffff66;
    }
    uVar3 = MountMgrSendDeviceControl(param_2,0x4d0000,0,0,puVar2,iVar5,param_1);
    iVar1 = (int)uVar3;
    if (-1 < iVar1) goto LAB_14001b127;
    if (iVar1 != -0x7ffffffb) goto LAB_14001b149;
    iVar5 = *puVar2 + 2;
    ExFreePoolWithTag(puVar2,0);
  }
  if (iVar1 < 0) {
    if (puVar2 != (ushort *)0x0) {
LAB_14001b149:
      ExFreePoolWithTag(puVar2,0);
    }
  }
  else {
LAB_14001b127:
    *param_3 = puVar2;
  }
  return iVar1;
}



===== QueryDeviceNameInternal @ 14001b1e0 =====

int QueryDeviceNameInternal(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ushort *puVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  undefined8 local_58;
  ushort *puStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  puVar2 = (ushort *)0x0;
  iVar1 = 0;
  uVar5 = 0;
  local_58 = 0;
  puStack_50 = (ushort *)0x0;
  iVar4 = 0x102;
  do {
    if (1 < uVar5) {
      if (-1 < iVar1) {
LAB_14001b2f2:
        local_58._0_4_ = CONCAT22(*puVar2,*puVar2);
        puStack_50 = puVar2 + 1;
        iVar1 = RtlDuplicateUnicodeString(1,&local_58,param_3);
      }
      if (puVar2 != (ushort *)0x0) {
LAB_14001b32b:
        ExFreePoolWithTag(puVar2,0);
      }
      return iVar1;
    }
    puVar2 = (ushort *)ExAllocatePool2(0x102,iVar4,0x41746e4d);
    if (puVar2 == (ushort *)0x0) {
      return -0x3fffff66;
    }
    local_28 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_48 = 0;
    uStack_40 = 0;
    KeInitializeEvent(&local_38,0,0);
    lVar3 = IoBuildDeviceIoControlRequest(0x4d0008,param_2,0,0,puVar2,iVar4,0,&local_38,&local_48);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
      goto LAB_14001b32b;
    }
    if (param_1 != 0) {
      *(longlong *)(*(longlong *)(lVar3 + 0xb8) + -0x18) = param_1;
    }
    iVar1 = IofCallDriver(param_2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
      iVar1 = (int)local_48;
    }
    if (-1 < iVar1) goto LAB_14001b2f2;
    if (iVar1 != -0x7ffffffb) goto LAB_14001b32b;
    iVar4 = (*puVar2 & 0xfffffffe) + 2;
    ExFreePoolWithTag(puVar2,0);
    uVar5 = uVar5 + 1;
  } while( true );
}



===== OpenDevice @ 14001b3e0 =====

int OpenDevice(undefined8 param_1,longlong *param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res10 [2];
  
  *param_3 = 0;
  *param_2 = 0;
  local_res10[1] = 0;
  local_res10[0] = 0;
  iVar1 = IoGetDeviceObjectPointer(param_1,0x80,local_res10,local_res10 + 1);
  if (-1 < iVar1) {
    if (*(short *)(local_res10[0] + 0x58) == 0) {
      uVar2 = IoGetAttachedDeviceReference(*(undefined8 *)(local_res10[0] + 8));
      *param_3 = uVar2;
      *param_2 = local_res10[0];
      return iVar1;
    }
    iVar1 = -0x3fffffcc;
  }
  if (local_res10[0] != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== QueryDeviceSortOrderInternal @ 14001b480 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int QueryDeviceSortOrderInternal(longlong param_1,longlong param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  char *pcVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined1 auStackY_138 [32];
  char local_f8 [8];
  longlong local_f0;
  int local_e8 [2];
  longlong local_e0;
  int local_d0;
  byte local_c8;
  char cStack_c7;
  undefined6 uStack_c6;
  longlong local_c0;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  bVar2 = false;
  local_e8[1] = 0;
  uVar9 = 0;
  local_f8[0] = '\0';
  local_f0 = 0;
  local_58 = 0;
  uStack_50 = 0;
  bVar1 = false;
  local_48 = 0;
  uStack_40 = 0;
  memset(local_e8,0,0x8c);
  *(undefined8 *)(param_2 + 0xa8) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0xa0) = 0xffffffffffffffff;
  if ((*(uint *)(param_1 + 0x34) & 4) != 0) {
    *(undefined4 *)(param_2 + 0xa0) = 1;
    return 0;
  }
  if (*(int *)(param_1 + 0x48) == 2) {
    *(undefined4 *)(param_2 + 0xa0) = 2;
    return 0;
  }
  if (*(int *)(param_1 + 0x48) != 7) {
    return 0;
  }
  *(undefined4 *)(param_2 + 0xa0) = 0;
  uVar5 = MountMgrSendDeviceControl(param_1,0x560048,0,0,local_f8,1,0);
  iVar3 = (int)uVar5;
  if (iVar3 < 0) {
    return iVar3;
  }
  if (local_f8[0] != '\0') {
    return iVar3;
  }
  uVar5 = MountMgrSendDeviceControl(param_1,0x560000,0,0,&local_58,0x20,0);
  if ((int)uVar5 < 0) {
    return (int)uVar5;
  }
  *(undefined4 *)(param_2 + 0xa8) = (undefined4)uStack_50;
  uVar5 = MountMgrSendDeviceControl(param_1,0x70048,0,0,local_e8,0x90,0);
  iVar3 = (int)uVar5;
  if (iVar3 < 0) {
    return iVar3;
  }
  *(int *)(param_2 + 0xac) = local_d0;
  if (local_e8[0] == 1) {
    lVar7 = CONCAT62(uStack_c6,CONCAT11(cStack_c7,local_c8));
    lVar6 = lVar7 + -0x45b94df957434f53;
    if (lVar6 == 0) {
      lVar6 = local_c0 + -0x7c4506f070239e8e;
    }
    if (lVar6 != 0) {
      lVar6 = lVar7 + -0x43f094cb57434f53;
      if (lVar6 == 0) {
        lVar6 = local_c0 + -0x7da5cf103cd733a5;
      }
      if (lVar6 != 0) {
        lVar6 = lVar7 + -0x4433b9e5ebd0a0a2;
        if (lVar6 == 0) {
          lVar6 = local_c0 + 0x3866d94849973f79;
        }
        if (lVar6 != 0) {
          lVar6 = lVar7 + -0x405e8f4557434f53;
          if (lVar6 == 0) {
            lVar6 = local_c0 + 0x2ccfbc7592e7dc76;
          }
          if (lVar6 != 0) {
            lVar6 = lVar7 + -0x4d4006d1de94bba4;
            if (lVar6 == 0) {
              lVar6 = local_c0 + 0x532986fe2a40955f;
            }
            if (lVar6 != 0) {
              lVar6 = lVar7 + -0x44d523f257434f53;
              if (lVar6 == 0) {
                lVar6 = local_c0 + 0x6f659254498cf58;
              }
              if (lVar6 != 0) {
                lVar6 = lVar7 + -0x41967fe057434f53;
                if (lVar6 == 0) {
                  lVar6 = local_c0 + 0x7bcb9bae84bdbd65;
                }
                if (lVar6 != 0) {
                  lVar6 = lVar7 + -0x4014432e57434f53;
                  if (lVar6 == 0) {
                    lVar6 = local_c0 + -0x6a00c0a9ea8d4cae;
                  }
                  if (lVar6 != 0) {
                    lVar6 = lVar7 + -0x4a05c69157434f53;
                    if (lVar6 == 0) {
                      lVar6 = local_c0 + 0x31d62d50c28fb145;
                    }
                    if (lVar6 != 0) {
                      lVar6 = lVar7 + -0x460b4b8157434f53;
                      if (lVar6 == 0) {
                        lVar6 = local_c0 + -0x146d13feb6ff19a3;
                      }
                      if (lVar6 != 0) {
                        lVar6 = lVar7 + -0x4e84e84d57434f53;
                        if (lVar6 == 0) {
                          lVar6 = local_c0 + 0x2046fb4244130c56;
                        }
                        if (lVar6 != 0) {
                          lVar7 = lVar7 + -0x4631e3e357434f53;
                          if (lVar7 == 0) {
                            lVar7 = local_c0 + 0x558cc7db2dd93a5b;
                          }
                          if (lVar7 != 0) {
                            return iVar3;
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
      }
    }
    *(undefined4 *)(param_2 + 0xa4) = 0;
    return iVar3;
  }
  if (local_e8[0] != 0) {
    return iVar3;
  }
  if (((0x2d < local_c8) || ((0x3f80000058d2U >> ((ulonglong)local_c8 & 0x3f) & 1) == 0)) &&
     (local_c8 != 0xef)) {
    return iVar3;
  }
  uVar5 = GetDriveLayoutInternal(param_1,&local_f0);
  if ((int)uVar5 < 0) goto LAB_14001b835;
  uVar4 = *(uint *)(local_f0 + 4);
  if (uVar4 < 5) {
    if (uVar4 != 0) goto LAB_14001b7d6;
  }
  else {
    uVar4 = 4;
LAB_14001b7d6:
    uVar10 = (ulonglong)uVar4;
    pcVar8 = (char *)(local_f0 + 0x51);
    do {
      if (local_e0 == *(longlong *)(pcVar8 + -0x19)) {
        bVar1 = true;
      }
      if (*pcVar8 != '\0') {
        bVar2 = true;
      }
      uVar10 = uVar10 - 1;
      pcVar8 = pcVar8 + 0x90;
    } while (uVar10 != 0);
    if (bVar1) {
      if ((cStack_c7 == '\0') && ((bVar2 || (local_d0 != 1)))) {
        uVar9 = 2;
      }
      *(undefined4 *)(param_2 + 0xa4) = uVar9;
      goto LAB_14001b835;
    }
  }
  *(undefined4 *)(param_2 + 0xa4) = 1;
LAB_14001b835:
  if (local_f0 != 0) {
    ExFreePoolWithTag(local_f0,0);
  }
  return (int)uVar5;
}



===== QuerySuggestedLinkNameInternal @ 14001b880 =====

ulonglong QuerySuggestedLinkNameInternal(longlong param_1,undefined8 param_2,longlong param_3)

{
  bool bVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  short local_18 [4];
  longlong lStack_10;
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  lStack_10 = 0;
  if (*(char *)(param_3 + 0x7f) != '\0') {
    return 0;
  }
  lVar2 = ExAllocatePool2(0x102,0x20);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar4 = MountMgrSendDeviceControl(param_2,0x4d000c,0,0,lVar2,0x20,param_1);
    uVar3 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      if (*(short *)(lVar2 + 2) == 0) {
        *(undefined1 *)(param_3 + 0x7f) = 1;
      }
      else {
        local_18[1] = *(undefined2 *)(lVar2 + 2);
        local_18[0] = *(short *)(lVar2 + 2);
        lStack_10 = lVar2 + 4;
        bVar1 = IsDriveLetter(local_18);
        if (bVar1) {
          *(undefined1 *)(param_3 + 0x80) = *(undefined1 *)(lStack_10 + 0x18);
        }
      }
    }
    ExFreePoolWithTag(lVar2,0);
  }
  return uVar3;
}



===== SendLinkCreated @ 14001b990 =====

void SendLinkCreated(undefined8 param_1,ushort *param_2)

{
  int iVar1;
  ushort *puVar2;
  ulonglong uVar3;
  int iVar4;
  longlong *plVar5;
  ushort *puVar6;
  longlong local_res8;
  undefined8 local_res10;
  
  iVar4 = *param_2 + 2;
  local_res8 = 0;
  local_res10 = 0;
  puVar2 = (ushort *)ExAllocatePool2(0x102,iVar4,0x41746e4d);
  if (puVar2 == (ushort *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e);
    }
  }
  else {
    *puVar2 = *param_2;
    memmove(puVar2 + 1,*(void **)(param_2 + 4),(ulonglong)*param_2);
    plVar5 = &local_res8;
    iVar1 = IoGetDeviceObjectPointer(param_2,0x80,plVar5,&local_res10);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,plVar5,iVar1);
      }
      ExFreePoolWithTag(puVar2,0);
    }
    else {
      local_res10 = IoGetAttachedDeviceReference(*(undefined8 *)(local_res8 + 8));
      puVar6 = puVar2;
      uVar3 = MountMgrSendDeviceControl(local_res10,0x4dc010,puVar2,iVar4,0,0,local_res8);
      iVar1 = (int)uVar3;
      if ((((iVar1 < 0) && (iVar1 != -0x3ffffffe)) && (iVar1 != -0x3ffffff0)) &&
         ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
         )) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,puVar6,iVar1);
      }
      puVar6 = puVar2;
      uVar3 = MountMgrSendDeviceControl(local_res10,0x4d0010,puVar2,iVar4,0,0,local_res8);
      if ((((int)uVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,puVar6,(int)uVar3);
      }
      ExFreePoolWithTag(puVar2,0);
      ObfDereferenceObject(local_res10);
      ObfDereferenceObject(local_res8);
    }
  }
  return;
}



===== MountMgrSendDeviceControl @ 14001bbb0 =====

ulonglong MountMgrSendDeviceControl
                    (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 param_6,longlong param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,0,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    if (param_7 != 0) {
      *(longlong *)(*(longlong *)(lVar1 + 0xb8) + -0x18) = param_7;
    }
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== MountMgrCreateClose @ 14001bcd0 =====

uint MountMgrCreateClose(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  if (**(char **)(param_2 + 0xb8) == '\0') {
    uVar1 = -(uint)((*(uint *)(*(char **)(param_2 + 0xb8) + 0x10) & 1) != 0) & 0xc0000103;
  }
  else {
    uVar1 = 0;
  }
  *(uint *)(param_2 + 0x30) = uVar1;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== CreateNewDriveLetterHelper @ 14001bd30 =====

ulonglong CreateNewDriveLetterHelper
                    (longlong param_1,byte param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong *plVar2;
  ushort *puVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  longlong *plVar7;
  void *_Dst;
  ulonglong uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  ulonglong _Size;
  char local_res10 [8];
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  undefined8 uStack_28;
  uint local_20 [2];
  
  local_res10[0] = '\0';
  iVar5 = ObIsDosDeviceLocallyMapped(param_2 - 0x40,local_res10);
  if (iVar5 < 0) {
    local_res10[0] = '\0';
  }
  else if (local_res10[0] != '\0') {
    return 0xc0000035;
  }
  plVar7 = (longlong *)ExAllocatePool2(0x102,0x28,0x41746e4d);
  if (plVar7 == (longlong *)0x0) {
    uVar11 = 0xc000009a;
  }
  else {
    *(undefined2 *)(plVar7 + 3) = DAT_1400090b8;
    _Size = 0x41746e4d;
    pcVar9 = (char *)(ulonglong)DAT_1400090ba;
    *(ushort *)((longlong)plVar7 + 0x1a) = DAT_1400090ba;
    _Dst = (void *)ExAllocatePool2(0x102);
    puVar10 = auStack_48;
    plVar7[4] = (longlong)_Dst;
    if (_Dst == (void *)0x0) {
      uVar11 = 0xc000009a;
    }
    else {
      _Size = (ulonglong)DAT_1400090ba;
      memmove(_Dst,PTR_u__DosDevices_A__1400090c0,_Size);
      pcVar9 = (char *)(param_1 + 0x50);
      *(ushort *)(plVar7[4] + 0x18) = (ushort)param_2;
      uVar8 = GlobalCreateSymbolicLink
                        ((undefined1 (*) [16])(plVar7 + 3),(undefined8 *)pcVar9,_Size,param_4);
      puVar10 = auStack_48;
      uVar11 = uVar8 & 0xffffffff;
      if (-1 < (int)uVar8) {
        pcVar9 = local_res10;
        uVar6 = ObIsDosDeviceLocallyMapped(param_2 - 0x40);
        puVar10 = auStack_48;
        uVar8 = (ulonglong)uVar6;
        if (-1 < (int)uVar6) goto LAB_14001bea0;
        local_res10[0] = '\0';
        uVar8 = 0;
        puVar10 = auStack_48;
        do {
          plVar2 = *(longlong **)(param_1 + 0x18);
          if (*plVar2 == param_1 + 0x10) {
            *plVar7 = param_1 + 0x10;
            plVar7[1] = (longlong)plVar2;
            *plVar2 = (longlong)plVar7;
            *(longlong **)(param_1 + 0x18) = plVar7;
            *(undefined1 *)(plVar7 + 2) = 1;
            *(undefined8 *)(puVar10 + -8) = 0x14001becc;
            SendLinkCreated(plVar2,(ushort *)(plVar7 + 3));
            puVar3 = *(ushort **)(param_1 + 0x60);
            lVar1 = plVar7[4];
            *(uint *)(puVar10 + 0x28) = (uint)*puVar3;
            *(ushort **)(puVar10 + 0x20) = puVar3 + 1;
            *(undefined8 *)(puVar10 + -8) = 0x14001befa;
            RtlWriteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices",lVar1,3);
            return uVar8;
          }
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          puVar10 = puVar10 + 8;
LAB_14001bea0:
        } while (puVar10[0x58] == '\0');
        uVar11 = 0xc0000035;
      }
    }
    if (plVar7[4] != 0) {
      if (puVar10[0x58] != '\0') {
        *(undefined8 *)(puVar10 + -8) = 0x14001bdfc;
        GlobalDeleteSymbolicLink((undefined1 (*) [16])(plVar7 + 3),pcVar9,_Size,param_4);
      }
      lVar1 = plVar7[4];
      *(undefined8 *)(puVar10 + -8) = 0x14001be09;
      ExFreePoolWithTag(lVar1,0);
    }
    *(undefined8 *)(puVar10 + -8) = 0x14001be1a;
    ExFreePoolWithTag(plVar7,0);
  }
  return uVar11;
}



===== GlobalDeleteSymbolicLink @ 14001bf10 =====

ulonglong GlobalDeleteSymbolicLink
                    (undefined1 (*param_1) [16],undefined8 param_2,undefined8 param_3,
                    undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 local_18;
  longlong lStack_10;
  
  local_18 = 0;
  lStack_10 = 0;
  uVar3 = CreateStringWithGlobal(param_1,&local_18,param_3,param_4);
  uVar4 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    uVar2 = IoDeleteSymbolicLink(&local_18);
    uVar4 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) goto LAB_14001bfb3;
  }
  lVar1 = *(longlong *)(*param_1 + 8);
  if ((lVar1 == 0) || (*(short *)*param_1 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,param_3,(int)uVar4);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_LS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar1,param_3,(int)uVar4,(wchar_t *)lVar1);
  }
LAB_14001bfb3:
  if (lStack_10 != 0) {
    ExFreePoolWithTag(lStack_10,0);
  }
  return uVar4;
}



===== GlobalCreateSymbolicLink @ 14001bfe0 =====

ulonglong GlobalCreateSymbolicLink
                    (undefined1 (*param_1) [16],undefined8 *param_2,undefined8 param_3,
                    undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_38 = 0;
  lStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = CreateStringWithGlobal(param_1,&local_38,param_3,param_4);
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001c03c;
    uVar3 = 0xd;
  }
  else {
    uStack_20 = *param_2;
    local_18 = *(undefined4 *)(param_2 + 1);
    uStack_14 = *(undefined4 *)((longlong)param_2 + 0xc);
    local_28 = CONCAT44(local_28._4_4_,1);
    uVar1 = IoCreateSymbolicLink2(&local_38,&local_28);
    uVar4 = (ulonglong)uVar1;
    if ((((-1 < (int)uVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_14001c03c;
    uVar3 = 0xe;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,param_3,(int)uVar4);
LAB_14001c03c:
  if (lStack_30 != 0) {
    ExFreePoolWithTag(lStack_30,0);
  }
  return uVar4;
}



===== CreateStringWithGlobal @ 14001c0c0 =====

undefined8
CreateStringWithGlobal
          (undefined1 (*param_1) [16],undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auVar1 [16];
  char cVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  void *pvStack_10;
  
  cVar2 = RtlPrefixUnicodeString(&DAT_140009068,param_1,1,param_4,0);
  if (cVar2 == '\0') {
    cVar2 = RtlPrefixUnicodeString(&DAT_140009058,param_1,1);
    if (cVar2 == '\0') {
      auVar1 = *param_1;
      pvStack_10 = (void *)ExAllocatePool2(0x102,auVar1._2_2_,0x41746e4d);
      uVar6 = auVar1._0_8_;
      if (pvStack_10 != (void *)0x0) {
        memmove(pvStack_10,*(void **)(*param_1 + 8),(ulonglong)*(ushort *)(*param_1 + 2));
        goto LAB_14001c301;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0xc000009a;
      }
      uVar3 = 0xc;
    }
    else {
      uVar4 = (*(short *)*param_1 - DAT_140009058) + DAT_140009020;
      uVar6 = (ulonglong)CONCAT22(uVar4 + 2,uVar4);
      pvStack_10 = (void *)ExAllocatePool2();
      if (pvStack_10 != (void *)0x0) {
        uVar5 = (uint)DAT_140009020;
        memmove(pvStack_10,PTR_u__GLOBAL____140009028,(ulonglong)uVar5);
        memmove((void *)((ulonglong)uVar5 + (longlong)pvStack_10),
                (void *)((ulonglong)(uint)DAT_140009058 + *(longlong *)(*param_1 + 8)),
                (ulonglong)*(ushort *)*param_1 - (ulonglong)(uint)DAT_140009058);
        *(undefined2 *)((longlong)pvStack_10 + (ulonglong)(uVar4 >> 1) * 2) = 0;
LAB_14001c301:
        *param_2 = uVar6;
        param_2[1] = pvStack_10;
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0xc000009a;
      }
      uVar3 = 0xb;
    }
  }
  else {
    uVar4 = (*(short *)*param_1 - (ushort)DAT_140009068) + DAT_140009020;
    uVar6 = (ulonglong)CONCAT22(uVar4 + 2,uVar4);
    pvStack_10 = (void *)ExAllocatePool2(0x102,uVar4 + 2,0x41746e4d);
    if (pvStack_10 != (void *)0x0) {
      uVar5 = (uint)DAT_140009020;
      memmove(pvStack_10,PTR_u__GLOBAL____140009028,(ulonglong)uVar5);
      memmove((void *)((ulonglong)uVar5 + (longlong)pvStack_10),
              (void *)((ulonglong)(uint)(ushort)DAT_140009068 + *(longlong *)(*param_1 + 8)),
              (ulonglong)*(ushort *)*param_1 - (ulonglong)(uint)(ushort)DAT_140009068);
      *(undefined2 *)((longlong)pvStack_10 + (ulonglong)(uVar4 >> 1) * 2) = 0;
      goto LAB_14001c301;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000009a;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 0xc000009a;
    }
    uVar3 = 10;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3);
  return 0xc000009a;
}



===== ReconcileThisDatabaseWithMaster @ 14001c330 =====

void ReconcileThisDatabaseWithMaster(undefined8 *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  if ((*(char *)(param_2 + 0x7c) == '\0') && (*(char *)(param_2 + 0x7d) == '\0')) {
    plVar1 = (longlong *)ExAllocatePool2(0x42,0x38,0x41746e4d);
    if (plVar1 == (longlong *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa4);
      }
    }
    else {
      lVar2 = IoAllocateWorkItem(*param_1);
      plVar1[2] = lVar2;
      if (lVar2 == 0) {
        ExFreePoolWithTag(plVar1,0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa5);
        }
      }
      else {
        plVar1[5] = (longlong)param_1;
        plVar1[3] = (longlong)ReconcileThisDatabaseWithMasterWorker;
        plVar1[6] = param_2;
        QueueWorkItem((longlong)param_1,plVar1,(longlong)(plVar1 + 5));
        if (((*(int *)(param_1 + 0x23) == 0) && (*(char *)(param_1 + 0x12) == '\x01')) &&
           (*(char *)(param_1 + 0x18) == '\0')) {
          OnlineMountedVolumes((longlong)param_1,param_2);
        }
      }
    }
  }
  return;
}



===== SymbolicLinkNamesFromUniqueIdCount @ 14001c460 =====

undefined8
SymbolicLinkNamesFromUniqueIdCount
          (short *param_1,int param_2,undefined8 param_3,uint param_4,ushort *param_5,int *param_6)

{
  ulonglong uVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if (((*param_1 != 0x23) && (param_2 == 3)) && (*param_5 == param_4)) {
    uVar1 = RtlCompareMemory(param_5 + 1,param_3,param_4);
    if (uVar1 == param_4) {
      RtlInitUnicodeString(&local_18,param_1);
      *param_6 = *param_6 + 1;
    }
  }
  return 0;
}



===== QuerySymbolicLinkNamesFromStorage @ 14001c4e0 =====

int QuerySymbolicLinkNamesFromStorage
              (ulonglong param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong *puVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  code **ppcVar10;
  ulonglong local_res8;
  code *local_98 [3];
  ulonglong *local_80;
  
  lVar4 = *(longlong *)(param_2 + 0x68);
  bVar1 = false;
  if (lVar4 == 0) {
    lVar4 = *(longlong *)(param_2 + 0x70);
  }
  local_res8 = param_1;
  memset(local_98,0,0x70);
  local_98[0] = SymbolicLinkNamesFromUniqueIdCount;
  ppcVar10 = local_98;
  local_80 = &local_res8;
  local_res8 = local_res8 & 0xffffffff00000000;
  iVar2 = RtlQueryRegistryValuesEx
                    (0,L"\\Registry\\Machine\\System\\MountedDevices",ppcVar10,
                     *(undefined8 *)(param_2 + 0x60),0);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,ppcVar10,iVar2);
    }
    local_res8 = local_res8 & 0xffffffff00000000;
    iVar3 = 0;
  }
  else {
    bVar1 = false;
    iVar3 = (uint)local_res8;
    if ((uint)local_res8 != 0) {
      bVar1 = true;
    }
  }
  if (lVar4 == 0) {
    if (iVar3 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,ppcVar10,iVar2);
      }
      return -0x3ffffddb;
    }
  }
  else {
    local_res8 = CONCAT44(local_res8._4_4_,iVar3 + 1);
  }
  ppcVar10 = (code **)0x41746e4d;
  puVar5 = (ulonglong *)ExAllocatePool2(0x100);
  if (puVar5 == (ulonglong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a);
    }
    return -0x3fffff66;
  }
  if (bVar1) {
    memset(local_98,0,0x70);
    local_98[0] = SymbolicLinkNamesFromUniqueIdQuery;
    ppcVar10 = local_98;
    local_80 = puVar5;
    iVar2 = RtlQueryRegistryValuesEx
                      (0,L"\\Registry\\Machine\\System\\MountedDevices",ppcVar10,
                       *(undefined8 *)(param_2 + 0x60),0);
    if (-1 < iVar2) goto LAB_14001c6ed;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar6 = 0x1b;
LAB_14001c735:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,ppcVar10,iVar2);
    }
LAB_14001c741:
    uVar9 = 0;
    uVar7 = (uint)local_res8;
    if ((uint)local_res8 != 0) {
      do {
        if (puVar5[uVar9 * 2 + 1] != 0) {
          ExFreePoolWithTag(puVar5[uVar9 * 2 + 1],0);
          uVar7 = (uint)local_res8;
        }
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < uVar7);
    }
    ExFreePoolWithTag(puVar5,0);
  }
  else {
LAB_14001c6ed:
    if (lVar4 != 0) {
      iVar2 = CreateNewVolumeName((ushort *)(puVar5 + (ulonglong)((uint)local_res8 - 1) * 2),
                                  (undefined8 *)(param_2 + 0x68),ppcVar10);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar6 = 0x1c;
          goto LAB_14001c735;
        }
        goto LAB_14001c741;
      }
    }
    *param_4 = (uint)local_res8;
    *param_3 = (longlong)puVar5;
  }
  return iVar2;
}



===== CreateNewVolumeName @ 14001c7d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CreateNewVolumeName(ushort *param_1,undefined8 *param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_2 == (undefined8 *)0x0) {
    iVar1 = ExUuidCreate(&local_28);
    if (iVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar1;
      }
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,param_3,iVar1);
      return iVar1;
    }
  }
  else {
    local_28 = *param_2;
    uStack_20 = param_2[1];
  }
  iVar1 = RtlStringFromGUID(&local_28,&local_38);
  if (-1 < iVar1) {
    param_1[1] = 0x60;
    lVar2 = ExAllocatePool2(0x102,0x62,0x41746e4d);
    *(longlong *)(param_1 + 4) = lVar2;
    if (lVar2 != 0) {
      RtlCopyUnicodeString(param_1,&DAT_140009098);
      RtlAppendUnicodeStringToString(param_1);
      *(undefined2 *)(*(longlong *)(param_1 + 4) + (ulonglong)(*param_1 >> 1) * 2) = 0;
      ExFreePoolWithTag(uStack_30);
      return 0;
    }
    ExFreePoolWithTag(uStack_30,0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17);
    }
    return -0x3fffff66;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) {
    return iVar1;
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,param_3,iVar1);
  return iVar1;
}



===== SymbolicLinkNamesFromUniqueIdQuery @ 14001c980 =====

undefined8
SymbolicLinkNamesFromUniqueIdQuery
          (short *param_1,int param_2,undefined8 param_3,uint param_4,ushort *param_5,
          ulonglong *param_6)

{
  short sVar1;
  ulonglong uVar2;
  undefined8 local_18;
  void *pvStack_10;
  
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  if ((((*param_1 != 0x23) && (param_2 == 3)) && (*param_5 == param_4)) &&
     (uVar2 = RtlCompareMemory(param_5 + 1,param_3,param_4), uVar2 == param_4)) {
    RtlInitUnicodeString(&local_18,param_1);
    pvStack_10 = (void *)ExAllocatePool2(0x102,local_18._2_2_,0x41746e4d);
    if (pvStack_10 == (void *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14);
      }
      return 0xc000009a;
    }
    memmove(pvStack_10,param_1,local_18 & 0xffff);
    *(undefined2 *)((longlong)pvStack_10 + (local_18 >> 1 & 0x7fff) * 2) = 0;
    sVar1 = (short)*param_6;
    while (sVar1 != 0) {
      param_6 = param_6 + 2;
      sVar1 = (short)*param_6;
    }
    *param_6 = local_18;
    param_6[1] = (ulonglong)pvStack_10;
  }
  return 0;
}



===== IsOffline @ 14001cab0 =====

undefined8 IsOffline(longlong param_1)

{
  undefined8 uVar1;
  uint7 uVar2;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined8 local_68;
  int *local_60;
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48;
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  memset(local_78,0,0x70);
  local_68 = *(undefined8 *)(param_1 + 8);
  local_60 = local_res8;
  local_70 = 0x120;
  local_50 = local_res10;
  local_58 = 0x4000004;
  local_48 = 4;
  uVar1 = RtlQueryRegistryValuesEx
                    (0,L"\\Registry\\Machine\\System\\MountedDevices\\Offline",local_78,0,0);
  uVar2 = (uint7)((ulonglong)uVar1 >> 8);
  if (((int)uVar1 < 0) || (local_res8[0] == 0)) {
    return (ulonglong)uVar2 << 8;
  }
  return CONCAT71(uVar2,1);
}



===== MountMgrMountedDeviceNotification @ 14001cb80 =====

undefined8 MountMgrMountedDeviceNotification(longlong param_1,undefined **param_2)

{
  undefined1 uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  longlong lVar7;
  
  uVar1 = PsGetThreadHardErrorsAreDisabled(SystemReserved1[0xf]);
  PsSetThreadHardErrorsAreDisabled(SystemReserved1[0xf],1);
  lVar7 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
  if (lVar7 == 0) {
    lVar7 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar7 == 0) {
    uVar3 = MountMgrMountedDeviceArrival(param_2,*(undefined8 *)(param_1 + 0x28),'\0');
    iVar2 = (int)uVar3;
    if (((-1 < iVar2) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
    goto LAB_14001ccbe;
    uVar6 = 199;
  }
  else {
    lVar4 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4005;
    if (lVar4 == 0) {
      lVar4 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
    }
    if (lVar4 == 0) {
      lVar7 = 0;
      uVar5 = MountMgrMountedDeviceRemoval((longlong)param_2,*(undefined8 *)(param_1 + 0x28),'\0');
      iVar2 = (int)uVar5;
      if (((-1 < iVar2) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2)))
         ) goto LAB_14001ccbe;
      uVar6 = 200;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_14001ccbe;
      uVar6 = 0xc9;
      iVar2 = -0x3ffffff3;
    }
  }
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,lVar7,iVar2);
LAB_14001ccbe:
  PsSetThreadHardErrorsAreDisabled(SystemReserved1[0xf],uVar1);
  return 0;
}



===== MountMgrNextDriveLetterWorker @ 14001ccf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong MountMgrNextDriveLetterWorker
                    (undefined8 *param_1,longlong param_2,undefined2 *param_3,undefined8 param_4)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  ulonglong uVar4;
  byte bVar5;
  undefined8 *puVar6;
  undefined1 auStack_a8 [32];
  ulonglong local_88;
  undefined8 *puStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ushort local_60;
  undefined2 local_5e;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  puVar6 = *(undefined8 **)(param_2 + 0x10);
  local_88 = 0;
  puStack_80 = (undefined8 *)0x0;
  while( true ) {
    if (puVar6 == (undefined8 *)(param_2 + 0x10)) {
      if (((*(uint *)(param_2 + 0x78) & 0x100) != 0) ||
         (((*(char *)(param_2 + 0x7f) == '\0' &&
           (cVar3 = HasNoDriveLetterEntry(*(undefined8 *)(param_2 + 0x60)), cVar3 == '\0')) &&
          ((*(char *)(param_1 + 0x18) != '\0' || (*(char *)(param_2 + 0x7c) != '\0')))))) {
        *(undefined1 *)param_3 = 1;
        cVar3 = RtlPrefixUnicodeString(&DAT_140009088,param_2 + 0x50,1);
        if (cVar3 == '\0') {
          cVar3 = RtlPrefixUnicodeString(&DAT_140009040,param_2 + 0x50,1);
          bVar5 = (cVar3 != '\0') + 0x43;
        }
        else {
          bVar5 = 0x41;
        }
        puStack_80 = &local_78;
        local_88 = CONCAT44(local_88._4_4_,0x1c001c);
        local_78 = *(undefined8 *)PTR_u__DosDevices__140009070;
        uStack_70 = *(undefined8 *)(PTR_u__DosDevices__140009070 + 8);
        local_68 = *(undefined8 *)(PTR_u__DosDevices__140009070 + 0x10);
        local_5e = 0x3a;
        bVar1 = *(byte *)(param_2 + 0x80);
        if (bVar1 != 0) {
          *(byte *)((longlong)param_3 + 1) = bVar1;
          local_60 = (ushort)bVar1;
          uVar4 = MountMgrCreatePointWorker(param_1,&local_88,param_2,param_4);
          if (-1 < (int)uVar4) {
            return uVar4;
          }
        }
        *(byte *)((longlong)param_3 + 1) = bVar5;
        while (bVar5 < 0x5b) {
          *(ushort *)(puStack_80 + 3) = (ushort)bVar5;
          uVar4 = MountMgrCreatePointWorker(param_1,&local_88,param_2,param_4);
          if (-1 < (int)uVar4) {
            return uVar4;
          }
          *(char *)((longlong)param_3 + 1) = *(char *)((longlong)param_3 + 1) + '\x01';
          bVar5 = *(byte *)((longlong)param_3 + 1);
        }
      }
      *param_3 = 0;
      return 0;
    }
    bVar2 = IsDriveLetter((short *)(puVar6 + 3));
    if ((bVar2) && (*(char *)(puVar6 + 2) != '\0')) break;
    puVar6 = (undefined8 *)*puVar6;
  }
  *(undefined1 *)param_3 = 0;
  *(undefined1 *)((longlong)param_3 + 1) = *(undefined1 *)(puVar6[4] + 0x18);
  return 0;
}



===== IsDriveLetter @ 14001ce90 =====

bool IsDriveLetter(short *param_1)

{
  short sVar1;
  char cVar2;
  
  if (*param_1 == 0x1c) {
    sVar1 = *(short *)(*(longlong *)(param_1 + 4) + 0x18);
    if ((((ushort)(sVar1 - 0x41U) < 0x1a) || (sVar1 == 0xff)) &&
       (*(short *)(*(longlong *)(param_1 + 4) + 0x1a) == 0x3a)) {
      cVar2 = RtlPrefixUnicodeString
                        (&DAT_140009068,param_1,CONCAT71((uint7)(byte)((ushort)sVar1 >> 8),1));
      return cVar2 != '\0';
    }
  }
  return false;
}



===== CheckForNoDriveLetterEntry @ 14001cef0 =====

undefined8
CheckForNoDriveLetterEntry
          (short *param_1,int param_2,ulonglong param_3,uint param_4,ushort *param_5,
          undefined1 *param_6)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = param_3;
  if (((*param_1 == 0x23) && (param_2 == 3)) && (param_4 == *param_5)) {
    uVar2 = (ulonglong)param_4;
    uVar1 = RtlCompareMemory(param_5 + 1,param_3);
    if (uVar1 == param_4) {
      *param_6 = 1;
      return 0;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,uVar2,0);
  }
  return 0;
}



===== RemoveSavedLinks @ 14001cf80 =====

longlong * RemoveSavedLinks(longlong param_1,ushort *param_2)

{
  longlong lVar1;
  code *pcVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong *plVar7;
  
  plVar5 = (longlong *)(param_1 + 0xb0);
  plVar4 = (longlong *)0x0;
  plVar7 = (longlong *)*plVar5;
  if (plVar7 != plVar5) {
    uVar6 = (ulonglong)*param_2;
    do {
      plVar4 = plVar7;
      if (*(short *)plVar4[4] == (short)uVar6) {
        uVar3 = RtlCompareMemory((short *)plVar4[4] + 1,param_2 + 1,uVar6);
        uVar6 = (ulonglong)*param_2;
        plVar7 = plVar4;
        if (uVar3 == uVar6) break;
      }
      plVar7 = (longlong *)*plVar4;
    } while (plVar7 != plVar5);
  }
  if (plVar7 == (longlong *)(param_1 + 0xb0)) {
    plVar4 = (longlong *)0x0;
  }
  else {
    lVar1 = *plVar7;
    if ((*(longlong **)(lVar1 + 8) != plVar7) ||
       (plVar5 = (longlong *)plVar7[1], (longlong *)*plVar5 != plVar7)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      plVar5 = (longlong *)(*pcVar2)();
      return plVar5;
    }
    *plVar5 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar5;
  }
  return plVar4;
}



===== MountMgrTargetDeviceNotification @ 14001d040 =====

undefined8 MountMgrTargetDeviceNotification(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  bool bVar3;
  
  lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4008;
  puVar1 = *(undefined8 **)(param_2 + 0x98);
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar2 == 0) {
    MountMgrMountedDeviceRemoval((longlong)puVar1,param_2 + 0x40,'\0');
    return 0;
  }
  lVar2 = *(longlong *)(param_1 + 4) + -0x11d21a96b5804878;
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(param_1 + 0xc) + -0x326da0c9a000fd8f;
  }
  if (lVar2 == 0) {
    LOCK();
    bVar3 = *(int *)(param_2 + 0x88) == 0;
    if (bVar3) {
      *(int *)(param_2 + 0x88) = 0;
    }
    UNLOCK();
    if (bVar3) {
      if (*(char *)(param_2 + 0x83) != '\0') {
        *(undefined1 *)(param_2 + 0x83) = 0;
        KeWaitForSingleObject(puVar1 + 7,0,0,0,0);
        ReconcileThisDatabaseWithMaster(puVar1,param_2);
        KeReleaseMutex(puVar1 + 7,0);
      }
    }
    else {
      LOCK();
      *(int *)(param_2 + 0x88) = *(int *)(param_2 + 0x88) + -1;
      UNLOCK();
    }
  }
  else {
    lVar2 = *(longlong *)(param_1 + 4) + -0x41f56622af39da42;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0xc) + 0x265cd0f662ecf469;
    }
    if (lVar2 == 0) {
      MountMgrUniqueIdChangeRoutine(param_2,(ushort *)(param_1 + 0x24),param_3);
    }
    else {
      lVar2 = *(longlong *)(param_1 + 4) + -0x4c814a9aac0707fb;
      if (lVar2 == 0) {
        lVar2 = *(longlong *)(param_1 + 0xc) + -0x28fda8795b382e9e;
      }
      if (lVar2 == 0) {
        *(undefined1 *)(param_2 + 0x87) = 1;
      }
    }
  }
  return 0;
}



===== DeleteNoDriveLetterEntryRoutine @ 14001d180 =====

undefined8
DeleteNoDriveLetterEntryRoutine
          (short *param_1,int param_2,undefined8 param_3,uint param_4,ushort *param_5)

{
  ulonglong uVar1;
  
  if ((((param_2 == 3) && (*param_1 == 0x23)) && (param_4 == *param_5)) &&
     (uVar1 = RtlCompareMemory(param_5 + 1,param_3,param_4), uVar1 == param_4)) {
    RtlDeleteRegistryValue(0,L"\\Registry\\Machine\\System\\MountedDevices",param_1);
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
  {
    WPP_SF_LSsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
  }
  return 0;
}



===== DeleteSymbolicLinkNameFromMemory @ 14001d260 =====

ulonglong DeleteSymbolicLinkNameFromMemory(longlong param_1,ushort *param_2,char param_3)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  ulonglong uVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  
  puVar8 = *(undefined8 **)(param_1 + 0x10);
  do {
    if (puVar8 == (undefined8 *)(param_1 + 0x10)) {
      return 0;
    }
    for (plVar6 = (longlong *)puVar8[2]; plVar6 != puVar8 + 2; plVar6 = (longlong *)*plVar6) {
      iVar4 = RtlCompareUnicodeString(param_2,plVar6 + 3,1);
      if (iVar4 == 0) {
        *(longlong *)(param_1 + 0x150) = *(longlong *)(param_1 + 0x150) + 1;
        puVar8[0x16] = *(undefined8 *)(param_1 + 0x150);
        if (param_3 != '\0') {
          *(undefined1 *)(plVar6 + 2) = 0;
          return 0;
        }
        lVar1 = *plVar6;
        if ((*(longlong **)(lVar1 + 8) != plVar6) ||
           (plVar2 = (longlong *)plVar6[1], (longlong *)*plVar2 != plVar6)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          return 0;
        }
        *plVar2 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar2;
        ExFreePoolWithTag(plVar6[4]);
        uVar7 = 0;
        ExFreePoolWithTag();
        puVar8 = puVar8 + 8;
        uVar5 = SendLinkDeleted(plVar6,uVar7,puVar8,param_2);
        if (((int)uVar5 < 0) &&
           (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xde,puVar8,(int)uVar5);
        }
        return uVar5 & 0xffffffff;
      }
    }
    puVar8 = (undefined8 *)*puVar8;
  } while( true );
}



===== MountMgrBootDriveLetterAssignment @ 14001d3a0 =====

ulonglong MountMgrBootDriveLetterAssignment(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined1 local_res8 [16];
  undefined8 *local_res18 [2];
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar4 = 0;
  local_res8[0] = 0;
  if (*(char *)(param_1 + 0x90) == '\0') {
    puVar5 = *(undefined8 **)(param_1 + 0x10);
    local_res18[0] = (undefined8 *)0x0;
    for (; puVar5 != (undefined8 *)(param_1 + 0x10); puVar5 = (undefined8 *)*puVar5) {
      if ((*(uint *)(puVar5 + 0xf) & 0x100) != 0) goto LAB_14001d45f;
    }
    KeReleaseMutex(param_1 + 0x38,0);
    KeWaitForSingleObject(param_1 + 0x158,0,0,0,0);
    KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
    uVar3 = MountMgrFindBootVolume(param_1,local_res18);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    puVar5 = local_res18[0];
LAB_14001d45f:
    cVar2 = HasDriveLetter((longlong)puVar5,local_res8);
    if (cVar2 == '\0') {
      return 0xc0000034;
    }
    if (*(int *)(lVar1 + 8) == 1) {
      **(undefined1 **)(param_2 + 0x18) = local_res8[0];
      *(undefined8 *)(param_2 + 0x38) = 1;
    }
  }
  return uVar4;
}



===== MountmgrSetDLStringCase @ 14001d4b0 =====

void MountmgrSetDLStringCase(short *param_1,undefined8 param_2,undefined8 param_3)

{
  wchar_t *pwVar1;
  char cVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  undefined4 local_30;
  
  if (*param_1 == 0x1c) {
    uVar4 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
    *param_1 = 0x18;
    cVar2 = RtlEqualUnicodeString();
    *param_1 = 0x1c;
    if (cVar2 == '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x166,uVar4,0);
      }
    }
    else {
      uVar3 = RtlUpcaseUnicodeChar(*(undefined2 *)(*(longlong *)(param_1 + 4) + 0x18));
      local_30 = CONCAT22(0x3a,uVar3);
      memset(*(void **)(param_1 + 4),0,(ulonglong)(ushort)param_1[1]);
      pwVar1 = *(wchar_t **)(param_1 + 4);
      pwVar1[0] = L'\\';
      pwVar1[1] = L'D';
      pwVar1[2] = L'o';
      pwVar1[3] = L's';
      pwVar1[4] = L'D';
      pwVar1[5] = L'e';
      pwVar1[6] = L'v';
      pwVar1[7] = L'i';
      pwVar1[8] = L'c';
      pwVar1[9] = L'e';
      pwVar1[10] = L's';
      pwVar1[0xb] = L'\\';
      *(undefined4 *)(pwVar1 + 0xc) = local_30;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x165,param_3,0);
  }
  return;
}



===== MountMgrNotifyNameChange @ 14001d5e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MountMgrNotifyNameChange(longlong param_1,undefined8 param_2,char param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined4 local_b0;
  undefined1 local_a8;
  undefined8 *local_a0;
  undefined8 *local_98;
  undefined8 local_88;
  longlong local_80;
  undefined8 local_78;
  int *piStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  local_80 = 0;
  local_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  local_78 = 0;
  piStack_70 = (int *)0x0;
  local_3c = 0;
  local_2c = 0;
  cVar3 = PsIsHostSilo(*(undefined8 *)(param_1 + 0x170));
  if (cVar3 == '\0') {
    return;
  }
  if (param_3 != '\0') {
    puVar1 = *(undefined8 **)(param_1 + 0x10);
    while( true ) {
      if (puVar1 == (undefined8 *)(param_1 + 0x10)) {
        return;
      }
      iVar4 = RtlCompareUnicodeString(param_2,puVar1 + 10,1);
      if (iVar4 == 0) break;
      puVar1 = (undefined8 *)*puVar1;
    }
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
    if (*(char *)((longlong)puVar1 + 0x81) != '\0') {
      return;
    }
  }
  plVar6 = &local_80;
  iVar4 = IoGetDeviceObjectPointer(param_2,0x80,plVar6,&local_88);
  if (iVar4 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,plVar6,iVar4);
    return;
  }
  local_88 = IoGetAttachedDeviceReference(*(undefined8 *)(local_80 + 8));
  KeInitializeEvent(&local_68,0);
  local_98 = &local_78;
  local_a0 = &local_68;
  uVar7 = 0;
  local_a8 = 0;
  local_b0 = 0;
  local_b8 = 0;
  lVar5 = IoBuildDeviceIoControlRequest(0,local_88,0,0);
  if (lVar5 == 0) {
    ObfDereferenceObject(local_88);
    ObfDereferenceObject(local_80);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a);
    return;
  }
  lVar2 = *(longlong *)(lVar5 + 0xb8);
  *(undefined4 *)(lVar5 + 0x30) = 0xc00000bb;
  *(undefined8 *)(lVar5 + 0x38) = 0;
  *(undefined2 *)(lVar2 + -0x48) = 0x71b;
  *(undefined4 *)(lVar2 + -0x40) = 4;
  *(longlong *)(lVar2 + -0x18) = local_80;
  iVar4 = IofCallDriver(local_88,lVar5);
  if (iVar4 == 0x103) {
    local_b8 = 0;
    uVar7 = 0;
    KeWaitForSingleObject(&local_68,0,0,0);
    iVar4 = (int)local_78;
  }
  else if (((iVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,uVar7,iVar4);
    ObfDereferenceObject(local_88);
    ObfDereferenceObject(local_80);
    goto LAB_14001d84a;
  }
  ObfDereferenceObject(local_88);
  ObfDereferenceObject(local_80);
  if (-1 < iVar4) {
    if (*piStack_70 != 0) {
      local_88 = *(undefined8 *)(piStack_70 + 2);
      ExFreePoolWithTag(piStack_70,0);
      local_50 = 0x240001;
      local_38 = 0;
      local_4c = 0x2de97f83;
      uStack_48 = 0x11d24c06;
      uStack_44 = 0x600032a5;
      uStack_40 = 0x5a051397;
      local_30 = 0xffffffff;
      IoReportTargetDeviceChangeAsynchronous(local_88,&local_50,0,0);
      ObfDereferenceObject(local_88);
      return;
    }
    ExFreePoolWithTag();
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,uVar7,iVar4);
    return;
  }
LAB_14001d84a:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,uVar7,iVar4);
  }
  return;
}



===== RegisterForTargetDeviceNotification @ 14001d990 =====

void RegisterForTargetDeviceNotification(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  puVar2 = &local_res10;
  local_res10 = 0;
  local_res18[0] = 0;
  iVar1 = IoGetDeviceObjectPointer(param_2 + 0x50,0x80,puVar2,local_res18);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa9,puVar2,iVar1);
    }
  }
  else {
    uVar3 = local_res10;
    iVar1 = IoRegisterPlugPlayNotification
                      (3,0,local_res10,*(undefined8 *)(param_1 + 8),MountMgrTargetDeviceNotification
                       ,param_2,(undefined8 *)(param_2 + 0x90));
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xaa,uVar3,iVar1);
      }
      *(undefined8 *)(param_2 + 0x90) = 0;
    }
    ObfDereferenceObject(local_res10);
  }
  return;
}



===== SendLinkDeleted @ 14001daa0 =====

ulonglong SendLinkDeleted(undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort *param_4)

{
  ulonglong uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  int iVar4;
  longlong *plVar5;
  ushort *puVar6;
  longlong local_res8;
  undefined8 local_res10;
  
  uVar3 = 0;
  plVar5 = &local_res8;
  local_res8 = 0;
  local_res10 = 0;
  iVar4 = *param_4 + 2;
  uVar1 = IoGetDeviceObjectPointer(param_3,0x80,plVar5,&local_res10);
  if ((int)uVar1 < 0) {
    uVar3 = uVar1;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xda,plVar5,(int)uVar1);
      }
      uVar3 = uVar1 & 0xffffffff;
    }
  }
  else {
    local_res10 = IoGetAttachedDeviceReference(*(undefined8 *)(local_res8 + 8));
    puVar2 = (ushort *)ExAllocatePool2(0x102,iVar4,0x41746e4d);
    if (puVar2 == (ushort *)0x0) {
      uVar3 = 0xc000009a;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xdb);
      }
    }
    else {
      *puVar2 = *param_4;
      memmove(puVar2 + 1,*(void **)(param_4 + 4),(ulonglong)*param_4);
      puVar6 = puVar2;
      uVar1 = MountMgrSendDeviceControl(local_res10,0x4dc014,puVar2,iVar4,0,0,local_res8);
      if (((((int)uVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xdc,puVar6,(int)uVar1);
      }
      puVar6 = puVar2;
      uVar1 = MountMgrSendDeviceControl(local_res10,0x4d0014,puVar2,iVar4,0,0,local_res8);
      if ((((int)uVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))))
      {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xdd,puVar6,(int)uVar1);
      }
      ExFreePoolWithTag(puVar2,0);
    }
    ObfDereferenceObject(local_res10);
    ObfDereferenceObject(local_res8);
  }
  return uVar3;
}



===== MountMgrNextDriveLetter @ 14001dcc0 =====

int MountMgrNextDriveLetter(undefined8 *param_1,longlong param_2,ushort *param_3,undefined8 param_4)

{
  ushort uVar1;
  uint uVar2;
  undefined8 *puVar3;
  int iVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  ushort local_res10 [4];
  undefined8 local_28;
  ushort *puStack_20;
  undefined8 local_18;
  longlong lStack_10;
  
  local_28 = 0;
  puStack_20 = (ushort *)0x0;
  local_res10[0] = 0;
  local_18 = 0;
  lStack_10 = 0;
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if ((uVar2 < 4) || (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 2)) {
    iVar4 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001de8b;
    uVar6 = 0xe9;
LAB_14001de7c:
    iVar4 = -0x3ffffff3;
  }
  else {
    param_3 = *(ushort **)(param_2 + 0x18);
    uVar1 = *param_3;
    if (uVar2 < uVar1 + 2) {
      iVar4 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001de8b;
      uVar6 = 0xea;
      goto LAB_14001de7c;
    }
    puStack_20 = param_3 + 1;
    local_28 = (ulonglong)CONCAT22(uVar1,uVar1);
    iVar4 = QueryDeviceName(&local_28,&local_18);
    if (iVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001de8b;
      uVar6 = 0xeb;
    }
    else {
      for (puVar3 = (undefined8 *)param_1[2]; puVar3 != param_1 + 2; puVar3 = (undefined8 *)*puVar3)
      {
        param_3 = (ushort *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
        iVar4 = RtlCompareUnicodeString(&local_18,puVar3 + 10);
        if (iVar4 == 0) {
          param_3 = local_res10;
          uVar5 = MountMgrNextDriveLetterWorker(param_1,(longlong)puVar3,param_3,param_4);
          iVar4 = (int)uVar5;
          if (-1 < iVar4) {
            **(ushort **)(param_2 + 0x18) = local_res10[0];
            *(undefined8 *)(param_2 + 0x38) = 2;
            goto LAB_14001de8b;
          }
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001de8b;
          uVar6 = 0xed;
          goto LAB_14001de82;
        }
      }
      iVar4 = -0x3fffffcc;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001de8b;
      uVar6 = 0xec;
      iVar4 = -0x3fffffcc;
    }
  }
LAB_14001de82:
  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,param_3,iVar4);
LAB_14001de8b:
  if (lStack_10 != 0) {
    ExFreePoolWithTag(lStack_10,0);
  }
  return iVar4;
}



===== MountMgrValidateBackPointer @ 14001ded0 =====

ulonglong MountMgrValidateBackPointer(longlong param_1,longlong param_2,undefined1 *param_3)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  undefined1 *puVar14;
  undefined8 uVar15;
  longlong lVar16;
  longlong local_res18;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff28;
  undefined4 uVar17;
  ushort local_a0;
  short local_9e;
  undefined4 local_9c;
  void *local_98;
  undefined8 local_90;
  short *psStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  ushort *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff28 >> 0x20);
  local_9c = 0;
  *param_3 = 0;
  local_6c = 0;
  local_54 = 0;
  local_90 = 0;
  psStack_88 = (short *)0x0;
  local_res18 = 0;
  local_80 = 0;
  uStack_78 = 0;
  puVar14 = param_3;
  uVar10 = Feature_1610585402__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 != 0) {
    uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x10) + 0x50);
    if (0xfffb < uVar1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000106;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc0000106;
      }
      uVar12 = 0x12d;
LAB_14001df77:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,puVar14,0xc0000106);
      return 0xc0000106;
    }
    if (0xfffb - (ulonglong)uVar1 < (ulonglong)*(ushort *)(param_1 + 0x18)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000106;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc0000106;
      }
      uVar12 = 0x12e;
      goto LAB_14001df77;
    }
  }
  uVar15 = 0x41746e4d;
  local_9e = *(short *)(*(longlong *)(param_1 + 0x10) + 0x50) + *(short *)(param_1 + 0x18) + 4;
  local_98 = (void *)ExAllocatePool2(0x102);
  if (local_98 == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12f,uVar15,0xc000009a);
      return 0xc000009a;
    }
LAB_14001e254:
    uVar10 = 0xc000009a;
  }
  else {
    memmove(local_98,*(void **)(*(longlong *)(param_1 + 0x10) + 0x58),
            (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x10) + 0x50));
    local_a0 = *(ushort *)(*(longlong *)(param_1 + 0x10) + 0x50);
    *(undefined2 *)((longlong)local_98 + (ulonglong)(local_a0 >> 1) * 2) = 0x5c;
    local_a0 = local_a0 + 2;
    memmove((void *)((ulonglong)local_a0 + (longlong)local_98),*(void **)(param_1 + 0x20),
            (ulonglong)*(ushort *)(param_1 + 0x18));
    local_a0 = local_a0 + *(short *)(param_1 + 0x18);
    *(undefined2 *)((longlong)local_98 + (ulonglong)(local_a0 >> 1) * 2) = 0;
    local_60 = &local_a0;
    lVar4 = *(longlong *)(param_2 + 0x98);
    local_res20 = *(longlong *)(param_2 + 0xb0);
    local_70 = 0x30;
    local_68 = 0;
    local_58 = 0x240;
    local_50 = 0;
    uStack_48 = 0;
    lVar5 = *(longlong *)(lVar4 + 0x150);
    KeReleaseMutex(lVar4 + 0x38,0);
    uVar7 = IoSetThreadHardErrorMode(0);
    iVar9 = ZwOpenFile(&local_res18,0x100080,&local_70,&local_80,CONCAT44(uVar17,7),0x200020);
    IoSetThreadHardErrorMode(uVar7);
    ExFreePoolWithTag(local_98,0);
    KeWaitForSingleObject(lVar4 + 0x38,0,0,0,0);
    lVar16 = local_res20;
    uVar10 = VerifyEpoch(lVar4,lVar5,local_res20);
    if ((int)uVar10 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x130,lVar16,(int)uVar10);
      }
      if (local_res18 == 0) {
        return uVar10 & 0xffffffff;
      }
      CloseFileHandleOutsideExtensionMutexLock(lVar4,local_res18);
      return uVar10 & 0xffffffff;
    }
    if (iVar9 < 0) {
      *param_3 = 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar12 = 0x131;
LAB_14001e521:
        iVar9 = 0;
LAB_14001e524:
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,lVar16,iVar9);
      }
    }
    else {
      lVar11 = ExAllocatePool2(0x102,0x4000,0x41746e4d);
      if (lVar11 == 0) {
        CloseFileHandleOutsideExtensionMutexLock(lVar4,local_res18);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x132);
        }
        goto LAB_14001e254;
      }
      KeReleaseMutex(lVar4 + 0x38,0);
      iVar9 = ZwFsControlFile(local_res18,0,0,0,&local_80,0x900a8,0,0,lVar11,0x4000);
      ZwClose(local_res18);
      KeWaitForSingleObject(lVar4 + 0x38,0,0,0,0);
      lVar16 = local_res20;
      uVar10 = VerifyEpoch(lVar4,lVar5,local_res20);
      uVar13 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) {
        ExFreePoolWithTag(lVar11,0);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar13;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return uVar13;
        }
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x133,lVar16,(int)uVar10);
        return uVar13;
      }
      if (iVar9 < 0) {
        *param_3 = 1;
        ExFreePoolWithTag(lVar11,0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar12 = 0x134;
          goto LAB_14001e524;
        }
      }
      else {
        sVar2 = *(short *)(lVar11 + 10);
        local_90._0_4_ = CONCAT22(sVar2,sVar2);
        uVar10 = (ulonglong)*(ushort *)(lVar11 + 8);
        psStack_88 = (short *)(uVar10 + 0x10 + lVar11);
        if (((((sVar2 == 0x60) || ((sVar2 == 0x62 && (*(short *)(uVar10 + 0x70 + lVar11) == 0x5c))))
             && (*psStack_88 == 0x5c)) &&
            ((((sVar3 = *(short *)(uVar10 + 0x12 + lVar11), sVar3 == 0x3f || (sVar3 == 0x5c)) &&
              (*(short *)(uVar10 + 0x14 + lVar11) == 0x3f)) &&
             ((*(short *)(uVar10 + 0x16 + lVar11) == 0x5c &&
              (*(short *)(uVar10 + 0x18 + lVar11) == 0x56)))))) &&
           ((((*(short *)(uVar10 + 0x1a + lVar11) == 0x6f &&
              ((*(short *)(uVar10 + 0x1c + lVar11) == 0x6c &&
               (*(short *)(uVar10 + 0x1e + lVar11) == 0x75)))) &&
             ((*(short *)(uVar10 + 0x20 + lVar11) == 0x6d &&
              ((((*(short *)(uVar10 + 0x22 + lVar11) == 0x65 &&
                 (*(short *)(uVar10 + 0x24 + lVar11) == 0x7b)) &&
                (*(short *)(uVar10 + 0x36 + lVar11) == 0x2d)) &&
               (((*(short *)(uVar10 + 0x40 + lVar11) == 0x2d &&
                 (*(short *)(uVar10 + 0x4a + lVar11) == 0x2d)) &&
                ((*(short *)(uVar10 + 0x54 + lVar11) == 0x2d &&
                 ((*(short *)(uVar10 + 0x6e + lVar11) == 0x7d && (sVar2 == 0x62)))))))))))) &&
            (sVar3 == 0x3f)))) {
          puVar6 = *(undefined8 **)(param_2 + 0x10);
          local_90 = CONCAT62(local_90._2_6_,0x60);
          for (; puVar6 != (undefined8 *)(param_2 + 0x10); puVar6 = (undefined8 *)*puVar6) {
            cVar8 = RtlEqualUnicodeString(&local_90,puVar6 + 3,1);
            if (cVar8 != '\0') {
              ExFreePoolWithTag(lVar11,0);
              goto LAB_14001e52d;
            }
          }
          ExFreePoolWithTag(lVar11,0);
          *param_3 = 1;
        }
        else {
          ExFreePoolWithTag(lVar11,0);
          *param_3 = 1;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar12 = 0x135;
            goto LAB_14001e521;
          }
        }
      }
    }
LAB_14001e52d:
    uVar10 = 0;
  }
  return uVar10;
}



===== entry @ 14001f010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001f044 =====

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



===== DriverEntry @ 14001f078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2)

{
  longlong *plVar1;
  ushort uVar2;
  longlong *_Dst;
  short sVar3;
  int iVar4;
  longlong lVar5;
  void *_Dst_00;
  undefined2 uVar6;
  undefined *_Size;
  undefined8 uVar7;
  longlong local_res18 [2];
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar8;
  ulonglong in_stack_ffffffffffffffc0;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  local_res18[0] = 0;
  wil_InitializeFeatureStaging();
  RtlCreateRegistryKey(0,L"\\Registry\\Machine\\System\\MountedDevices");
  uVar7 = 0x12;
  iVar4 = IoCreateDevice(param_1,0x178,&DAT_140009000,0x12,CONCAT44(uVar8,0x100),
                         in_stack_ffffffffffffffc0 & 0xffffffffffffff00,local_res18);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x174);
    }
  }
  else {
    *(code **)(param_1 + 0x68) = MountMgrUnload;
    _Dst = *(longlong **)(local_res18[0] + 0x40);
    memset(_Dst,0,0x178);
    lVar5 = PsGetHostSilo();
    _Dst[0x2e] = lVar5;
    *_Dst = local_res18[0];
    plVar1 = _Dst + 2;
    _Dst[3] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    plVar1 = _Dst + 4;
    _Dst[5] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    _Dst[1] = param_1;
    KeInitializeMutex(_Dst + 7,0);
    KeInitializeSemaphore(_Dst + 0xe,1,1);
    plVar1 = _Dst + 0x13;
    *(undefined4 *)(_Dst + 0x15) = 1;
    _Dst[0x14] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    plVar1 = _Dst + 0x16;
    _Dst[0x17] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    plVar1 = _Dst + 0x19;
    _Dst[0x1a] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    KeInitializeSemaphore(_Dst + 0x1b,0,0x7fffffff);
    *(undefined4 *)(_Dst + 0x1f) = 0xffffffff;
    KeInitializeSpinLock(_Dst + 0x20);
    plVar1 = _Dst + 0x24;
    *(undefined4 *)((longlong)_Dst + 0x134) = 1;
    _Dst[0x25] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    KeInitializeEvent(_Dst + 0x2b,0,0);
    uVar2 = *param_2;
    *(ushort *)(_Dst + 0x21) = uVar2;
    sVar3 = uVar2 + 2;
    *(short *)((longlong)_Dst + 0x10a) = sVar3;
    _Dst_00 = (void *)ExAllocatePool2(0x102,sVar3,0x41746e4d);
    _Dst[0x22] = (longlong)_Dst_00;
    if (_Dst_00 == (void *)0x0) {
      IoDeleteDevice(local_res18[0]);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x175);
      }
      iVar4 = -0x3fffff66;
    }
    else {
      _Size = (undefined *)(ulonglong)*param_2;
      memmove(_Dst_00,*(void **)(param_2 + 4),(size_t)_Size);
      *(undefined2 *)(_Dst[0x22] + (ulonglong)(*param_2 >> 1) * 2) = 0;
      iVar4 = MountmgrReadNoAutoMount((longlong)(_Dst + 0x21));
      _Dst[0x2a] = 1;
      *(bool *)(_Dst + 0x18) = iVar4 == 0;
      DAT_140009248 = &WPP_ThisDir_CTLGUID_Mountmgr;
      _WPP_MAIN_CB = 0;
      DAT_140009250 = 0;
      _DAT_140009260 = 0;
      _DAT_140009268 = 1;
      WppLoadTracingSupport();
      _DAT_140009260 = 0;
      WppInitKm();
      GlobalCreateSymbolicLink
                ((undefined1 (*) [16])&DAT_140009078,(undefined8 *)&DAT_140009000,_Size,uVar7);
      iVar4 = PsAllocSiloContextSlot(0,&gSiloSlot);
      if (iVar4 < 0) {
        IoDeleteDevice(local_res18[0]);
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001f506;
        uVar6 = 0x176;
      }
      else {
        _Size = &MOUNTDEV_MOUNTED_DEVICE_GUID;
        iVar4 = IoRegisterPlugPlayNotification
                          (2,1,&MOUNTDEV_MOUNTED_DEVICE_GUID,param_1,
                           MountMgrMountedDeviceNotification,_Dst,_Dst + 6);
        if (iVar4 < 0) {
          PsFreeSiloContextSlot(gSiloSlot);
          gSiloSlot = 0xffffffff;
          IoDeleteDevice(local_res18[0]);
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001f506;
          uVar6 = 0x177;
        }
        else {
          *(code **)(param_1 + 0x70) = MountMgrCreateClose;
          *(code **)(param_1 + 0x80) = MountMgrCreateClose;
          *(code **)(param_1 + 0xe0) = MountMgrDeviceControl;
          *(code **)(param_1 + 0x100) = MountMgrCleanup;
          *(code **)(param_1 + 0xf0) = MountMgrShutdown;
          gDeviceObject = local_res18[0];
          iVar4 = IoRegisterShutdownNotification();
          if (-1 < iVar4) {
            IoRegisterDriverReinitialization(param_1,MountMgrDriverReinitialization,_Dst);
            iVar4 = EtwRegister(&MountMgrEventProvider,0,0,&gEtwProvRegHandle);
            if (iVar4 < 0) {
              gEtwProvRegHandle = 0;
            }
            return 0;
          }
          PsFreeSiloContextSlot(gSiloSlot);
          gSiloSlot = 0xffffffff;
          IoDeleteDevice(local_res18[0]);
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14001f506;
          uVar6 = 0x178;
        }
      }
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,_Size,iVar4);
    }
  }
LAB_14001f506:
  wil_UninitializeFeatureStaging();
  return iVar4;
}



===== MountmgrReadNoAutoMount @ 14001f574 =====

undefined4 MountmgrReadNoAutoMount(longlong param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48;
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  memset(local_78,0,0x70);
  puVar2 = local_78;
  local_68 = L"NoAutoMount";
  local_60 = local_res8;
  local_70 = 0x120;
  local_50 = local_res10;
  local_58 = 0x4000004;
  local_48 = 4;
  iVar1 = RtlQueryRegistryValuesEx(0,*(undefined8 *)(param_1 + 8),puVar2,0,0);
  if (iVar1 < 0) {
    local_res8[0] = local_res10[0];
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16f,puVar2,iVar1);
    }
  }
  return local_res8[0];
}



===== wil_InitializeFeatureStaging @ 14001f648 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001f738 =====

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


