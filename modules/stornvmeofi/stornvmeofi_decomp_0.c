
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



===== Feature_1687679290__private_IsEnabledDeviceUsageNoInline @ 140001020 =====

ulonglong Feature_1687679290__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1687679290__private_featureState;
  if ((Feature_1687679290__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1687679290__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1687679290__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1687679290__private_IsEnabledFallback @ 140001058 =====

void Feature_1687679290__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1687679290__private_descriptor);
  return;
}



===== Feature_983534905__private_IsEnabledDeviceUsageNoInline @ 140001074 =====

ulonglong Feature_983534905__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_983534905__private_featureState;
  if (((uint)Feature_983534905__private_featureState & 0x10) == 0) {
    uVar1 = Feature_983534905__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_983534905__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_983534905__private_IsEnabledFallback @ 1400010ac =====

void Feature_983534905__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_983534905__private_descriptor);
  return;
}



===== NvmofiAllocateQueueResources @ 1400010c8 =====

int NvmofiAllocateQueueResources(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar5 = 0;
  iVar1 = 0;
  InitializeSListHead((PSLIST_HEADER)(param_1 + 0x3a));
  lVar2 = ExAllocatePool2(0x40,(ulonglong)*(ushort *)((longlong)param_1 + 0x2c) << 3,0x7143664e);
  param_1[0x3c] = lVar2;
  if (lVar2 == 0) {
LAB_140001127:
    iVar1 = -0x3fffffe9;
  }
  else {
    uVar4 = 0;
    if (*(short *)((longlong)param_1 + 0x2c) != 0) {
      do {
        uVar3 = NvmofiAllocateWskPacket(param_1,(longlong *)(param_1[0x3c] + (ulonglong)uVar4 * 8));
        iVar1 = (int)uVar3;
        if (iVar1 < 0) goto LAB_140001127;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(ushort *)((longlong)param_1 + 0x2c));
      if (*(ushort *)((longlong)param_1 + 0x2c) != 0) {
        do {
          ExpInterlockedPushEntrySList
                    ((PSLIST_HEADER)(param_1 + 0x3a),*(undefined8 *)(param_1[0x3c] + uVar5 * 8));
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(ushort *)((longlong)param_1 + 0x2c));
      }
    }
  }
  return iVar1;
}



===== NvmofiAllocateWskPacket @ 1400011b0 =====

undefined8 NvmofiAllocateWskPacket(longlong *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong local_res8;
  
  uVar4 = 0;
  iVar1 = **(int **)(*(longlong *)(*param_1 + 0x18) + 0x10);
  *param_2 = 0;
  lVar2 = ExAllocatePool2(0x40,0x418,0x7357664e);
  if (lVar2 == 0) {
    return 0xc0000017;
  }
  local_res8 = lVar2;
  if (iVar1 == 3) {
    lVar3 = IoAllocateMdl(lVar2 + 0x70,0x184,0,0,0);
    *(longlong *)(lVar2 + 0x1f8) = lVar3;
    if (lVar3 != 0) {
      lVar3 = IoAllocateMdl(lVar2 + 0x200,4,0,0,0);
      *(longlong *)(lVar2 + 0x204) = lVar3;
      if (lVar3 != 0) {
        MmBuildMdlForNonPagedPool(lVar3);
        goto LAB_14000128a;
      }
    }
    uVar4 = 0xc0000017;
    NvmofiReleaseWskPacket(&local_res8);
  }
  else {
LAB_14000128a:
    *(longlong **)(lVar2 + 0x20) = param_1;
    *(undefined8 *)(lVar2 + 0x2c) = 0;
    KeInitializeEvent(lVar2 + 0x48,1);
    IoInitializeIrp(lVar2 + 0x230,0x118,1);
    *(undefined8 *)(lVar2 + 0x60) = 0;
    *(undefined8 *)(lVar2 + 0x68) = 0;
    *param_2 = lVar2;
  }
  return uVar4;
}



===== NvmofiBuildWskBuffer @ 1400012ec =====

undefined4 NvmofiBuildWskBuffer(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar2 = *(uint *)(param_1 + 0x28);
  uVar7 = 0;
  uVar6 = 0;
  if ((uVar2 & 2) == 0) {
    if ((uVar2 & 0x40) == 0) {
      uVar2 = *(uint *)(param_1 + 500);
      uVar1 = param_1 + 0x70;
      puVar3 = *(undefined8 **)(param_1 + 0x1f8);
      *puVar3 = 0;
      *(undefined2 *)((longlong)puVar3 + 10) = 0;
      *(short *)(puVar3 + 1) = ((short)((ulonglong)uVar2 + 0xfff + (uVar1 & 0xfff) >> 0xc) + 6) * 8;
      puVar3[4] = uVar1 & 0xfffffffffffff000;
      *(uint *)((longlong)puVar3 + 0x2c) = (uint)uVar1 & 0xfff;
      *(uint *)(puVar3 + 5) = uVar2;
      MmBuildMdlForNonPagedPool(*(undefined8 *)(param_1 + 0x1f8));
      uVar7 = *(uint *)(param_1 + 500);
      if ((*(byte *)(param_1 + 0x28) & 0x10) != 0) {
        uVar8 = 0;
        lVar5 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x3c),0,0,0)
        ;
        *(longlong *)(param_1 + 0x40) = lVar5;
        if (lVar5 == 0) goto LAB_14000150b;
        MmBuildMdlForNonPagedPool(lVar5);
        **(undefined8 **)(param_1 + 0x1f8) = *(undefined8 *)(param_1 + 0x40);
        uVar7 = uVar7 + *(int *)(param_1 + 0x3c);
        if ((*(byte *)(param_1 + 0x28) & 0x20) != 0) {
          uVar7 = uVar7 + 4;
          **(undefined8 **)(param_1 + 0x40) = *(undefined8 *)(param_1 + 0x204);
        }
      }
      if ((*(byte *)(param_1 + 0x28) & 0x40) != 0) {
        return 0;
      }
      uVar6 = *(undefined8 *)(param_1 + 0x1f8);
    }
    else if (((*(longlong *)(param_1 + 0x34) != 0) && (*(int *)(param_1 + 0x3c) != 0)) &&
            ((uVar2 & 0x10) == 0)) {
      uVar8 = 0;
      lVar5 = IoAllocateMdl(*(longlong *)(param_1 + 0x34),*(int *)(param_1 + 0x3c),0,0,0);
      *(longlong *)(param_1 + 0x40) = lVar5;
      if (lVar5 == 0) goto LAB_14000150b;
      MmBuildMdlForNonPagedPool(lVar5);
    }
  }
  else {
    uVar2 = *(uint *)(param_1 + 500);
    puVar3 = (undefined8 *)(param_1 + 0x1f8);
    if (uVar2 != 0) {
      puVar4 = (undefined8 *)*puVar3;
      uVar1 = param_1 + 0x70;
      *puVar4 = 0;
      *(undefined2 *)((longlong)puVar4 + 10) = 0;
      puVar4[4] = uVar1 & 0xfffffffffffff000;
      *(short *)(puVar4 + 1) = ((short)((uVar1 & 0xfff) + 0xfff + (ulonglong)uVar2 >> 0xc) + 6) * 8;
      *(uint *)((longlong)puVar4 + 0x2c) = (uint)uVar1 & 0xfff;
      *(uint *)(puVar4 + 5) = uVar2;
      MmBuildMdlForNonPagedPool(*puVar3);
      uVar7 = *(uint *)(param_1 + 500);
    }
    uVar8 = 0;
    lVar5 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x3c),0,0,0);
    *(longlong *)(param_1 + 0x40) = lVar5;
    if (lVar5 == 0) {
LAB_14000150b:
      StorPortExtendedFunction
                (0x80,NvmofiAdapterExtension,*(undefined8 *)(**(longlong **)(param_1 + 0x20) + 0xa0)
                 ,0,CONCAT44(uVar8,1),0x1c,L"NvmofiBuildWskBuffer failure",0x200,2,0,L"NtStatus",
                 0xffffffffc0000017,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
      return 0xc0000017;
    }
    MmBuildMdlForNonPagedPool(lVar5);
    uVar7 = uVar7 + *(int *)(param_1 + 0x3c);
    if ((*(byte *)(param_1 + 0x28) & 0x20) != 0) {
      uVar7 = uVar7 + 4;
      **(undefined8 **)(param_1 + 0x40) = *(undefined8 *)(param_1 + 0x204);
    }
    uVar6 = *(undefined8 *)(param_1 + 0x40);
    if (*(int *)(param_1 + 500) != 0) {
      *(undefined8 *)*puVar3 = uVar6;
      uVar6 = *puVar3;
    }
  }
  if ((*(byte *)(param_1 + 0x28) & 0x40) == 0) {
    *(ulonglong *)(param_1 + 0x21c) = (ulonglong)uVar7;
    *(undefined8 *)(param_1 + 0x20c) = uVar6;
    *(undefined4 *)(param_1 + 0x214) = 0;
  }
  return 0;
}



===== NvmofiCleanupPackets @ 140001670 =====

void NvmofiCleanupPackets(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  longlong lVar6;
  longlong local_res8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar5 = auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((*(byte *)(param_1 + 8) & 1) != 0) {
    KeAcquireInStackQueuedSpinLock(param_1 + 0x1f8,&local_28);
    puVar5 = auStack_48;
    plVar1 = (longlong *)(param_1 + 0x1e8);
    while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar6 = *plVar2, (longlong *)*(longlong *)(lVar6 + 8) != plVar2)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar5 = auStack_40;
        break;
      }
      *plVar1 = lVar6;
      *(longlong **)(lVar6 + 8) = plVar1;
      KeReleaseInStackQueuedSpinLock(&local_28);
      lVar6 = (longlong)(plVar2 + -2);
      local_res8 = lVar6;
      if (lVar6 != 0) {
        IoCancelIrp(plVar2 + 0x44);
        NvmofiCleanupWskPacket(lVar6);
        NvmofiReturnQueuePacket(&local_res8);
      }
      KeAcquireInStackQueuedSpinLock(param_1 + 0x1f8,&local_28);
    }
    *(undefined8 *)(puVar5 + -8) = 0x140001748;
    KeReleaseInStackQueuedSpinLock(puVar5 + 0x20);
  }
  *(undefined8 *)(puVar5 + -8) = 0x140001752;
  uVar4 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    lVar6 = *(longlong *)(param_1 + 0x19c);
    if (lVar6 != 0) {
      *(undefined8 *)(puVar5 + -8) = 0x140001774;
      IoCancelIrp(lVar6 + 0x230);
      lVar6 = *(longlong *)(param_1 + 0x19c);
      *(undefined8 *)(puVar5 + -8) = 0x140001785;
      NvmofiCleanupWskPacket(lVar6);
    }
  }
  else {
    lVar6 = *(longlong *)(param_1 + 0x1ac);
    if ((lVar6 != 0) && ((*(byte *)(lVar6 + 0x28) & 1) != 0)) {
      *(undefined8 *)(puVar5 + -8) = 0x1400017a7;
      IoCancelIrp(lVar6 + 0x230);
    }
    lVar6 = *(longlong *)(param_1 + 0x1b4);
    if ((lVar6 != 0) && ((*(byte *)(lVar6 + 0x28) & 1) != 0)) {
      *(undefined8 *)(puVar5 + -8) = 0x1400017cc;
      IoCancelIrp(lVar6 + 0x230);
    }
    lVar6 = *(longlong *)(param_1 + 0x1bc);
    if ((lVar6 != 0) && ((*(byte *)(lVar6 + 0x28) & 1) != 0)) {
      *(undefined8 *)(puVar5 + -8) = 0x1400017f1;
      IoCancelIrp(lVar6 + 0x230);
    }
  }
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  return;
}



===== NvmofiCleanupQueue @ 140001820 =====

void NvmofiCleanupQueue(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  
  NvmofiFreeQueueResources(param_1);
  if (*(longlong *)(param_1 + 0x17c) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0x17c) = 0;
  }
  if (*(longlong *)(param_1 + 0x15c) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0x15c) = 0;
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    IoFreeIrp();
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  uVar1 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    plVar2 = (longlong *)(param_1 + 0x19c);
  }
  else {
    if (*(longlong *)(param_1 + 0x1a4) != 0) {
      NvmofiReleaseWskPacket((longlong *)(param_1 + 0x1a4));
    }
    if (*(longlong *)(param_1 + 0x1ac) != 0) {
      NvmofiReleaseWskPacket((longlong *)(param_1 + 0x1ac));
    }
    if (*(longlong *)(param_1 + 0x1b4) != 0) {
      NvmofiReleaseWskPacket((longlong *)(param_1 + 0x1b4));
    }
    plVar2 = (longlong *)(param_1 + 0x1bc);
  }
  if (*plVar2 != 0) {
    NvmofiReleaseWskPacket(plVar2);
  }
  *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) & 0xfffffffffffffffe;
  return;
}



===== NvmofiCleanupWskPacket @ 1400018f4 =====

void NvmofiCleanupWskPacket(longlong param_1)

{
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
  *(undefined8 *)(param_1 + 0x2c) = 0;
  *(undefined8 *)(param_1 + 0x20c) = 0;
  *(undefined8 *)(param_1 + 0x214) = 0;
  *(undefined8 *)(param_1 + 0x21c) = 0;
  if (*(longlong *)(param_1 + 0x40) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  *(undefined8 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}



===== NvmofiCompleteSrb @ 14000194c =====

void NvmofiCompleteSrb(longlong *param_1,longlong param_2,int *param_3)

{
  ulonglong *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar2 = *(undefined8 *)(*param_1 + 0x10);
  puVar3 = *(undefined8 **)(param_2 + 0x68);
  puVar1 = puVar3 + 1;
  *puVar1 = *puVar1 | 0x10;
  *puVar3 = 0;
  if ((*(char *)(param_2 + 2) == '(') && (*(uint *)(param_2 + 0x38) != 0)) {
    uVar6 = 0;
    do {
      uVar5 = *(uint *)(param_2 + 0x78 + uVar6 * 4);
      if (((0x7f < uVar5) && (uVar5 < *(uint *)(param_2 + 0x10))) &&
         (piVar4 = (int *)((ulonglong)uVar5 + param_2), *piVar4 == 0x43)) goto LAB_1400019a2;
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(param_2 + 0x38));
  }
  piVar4 = (int *)0x0;
LAB_1400019a2:
  piVar4[0x18] = *param_3;
  piVar4[0x19] = param_3[1];
  *(short *)(piVar4 + 0x1a) = (short)param_3[2];
  *(undefined2 *)((longlong)piVar4 + 0x56) = *(undefined2 *)((longlong)param_3 + 0xe);
  *(undefined1 *)(param_2 + 3) = 1;
  LOCK();
  *(short *)((longlong)param_1 + 0x2e) = *(short *)((longlong)param_1 + 0x2e) + -1;
  UNLOCK();
  StorPortNotification(0,uVar2,param_2);
  return;
}



===== NvmofiCreateQueue @ 1400019f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NvmofiCreateQueue(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
  }
  if (*(ushort *)(lVar3 + 4) == 0) {
    plVar2 = *(longlong **)(*(longlong *)(lVar3 + 8) + 0xbc);
  }
  else {
    plVar2 = (longlong *)
             (*(longlong *)(*(longlong *)(lVar3 + 8) + 0xc4) + -0x270 +
             (ulonglong)*(ushort *)(lVar3 + 4) * 0x270);
  }
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(*plVar2 + 0x18) + 0x10) + 0x20) +
                      0x18))(param_1,plVar2,param_2);
  if (-1 < iVar1) {
    *(undefined4 *)(plVar2 + 4) = 2;
    *(undefined1 *)(param_2 + 3) = 1;
    *(undefined2 *)(lVar3 + 0x10) = *(undefined2 *)((longlong)plVar2 + 0x2c);
  }
  StorPortNotification(0,param_1,param_2);
  StorPortExtendedFunction(0x1f,param_1,param_3);
  return;
}



===== NvmofiDeferPDUProcessing @ 140001ad4 =====

undefined8 NvmofiDeferPDUProcessing(longlong param_1,uint param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  lVar3 = ExAllocatePool2(0x40,0x119,0x6450664e);
  if (lVar3 == 0) {
    uVar4 = 0xc000021b;
  }
  else {
    *(ushort *)(lVar3 + 0x10) = *(ushort *)(lVar3 + 0x10) & 0xfffe;
    memmove((void *)(lVar3 + 0x19),param_3,(ulonglong)param_2);
    ExInterlockedInsertTailList(param_1 + 0x210,lVar3,param_1 + 0x220);
    LOCK();
    piVar1 = (int *)(param_1 + 0x34);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      KeClearEvent(param_1 + 0x164);
      IoQueueWorkItem(*(undefined8 *)(param_1 + 0x15c),NvmofiProcessDeferredPDU,1,param_1);
    }
  }
  return uVar4;
}



===== NvmofiDeferR2TProcessing @ 140001bc0 =====

undefined8 NvmofiDeferR2TProcessing(longlong param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  lVar3 = ExAllocatePool2(0x40,0x119,0x6450664e);
  if (lVar3 == 0) {
    uVar4 = 0xc000021b;
  }
  else {
    memmove((void *)(lVar3 + 0x19),param_2,(ulonglong)*(byte *)((longlong)param_2 + 2));
    ExInterlockedInsertTailList(param_1 + 0x228,lVar3,param_1 + 0x238);
    LOCK();
    piVar1 = (int *)(param_1 + 0x38);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      KeClearEvent(param_1 + 0x184);
      IoQueueWorkItem(*(undefined8 *)(param_1 + 0x17c),NvmofiProcessDeferredR2T,1,param_1);
    }
  }
  return uVar4;
}



===== NvmofiDeferResumeReceive @ 140001c98 =====

void NvmofiDeferResumeReceive(longlong *param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = *(undefined8 *)(*param_1 + 0x10);
  iVar2 = NvmofiQueueWorkItem(uVar1,NvmofiResumeReceive,param_1);
  if (iVar2 != 0) {
    StorPortExtendedFunction
              (0x80,uVar1,*(undefined8 *)(*param_1 + 0xa0),0,1,0x1b,
               L"QueueWorkItem failure - ResumeReceive",0x200,3,0xf0,L"QueueId",
               *(undefined2 *)((longlong)param_1 + 0x26),L"StorStatus",iVar2,L"",0,L"",0,L"",0,L"",0
               ,L"",0,L"",0);
  }
  return;
}



===== NvmofiDeferSendH2CTermReq @ 140001dc4 =====

undefined8
NvmofiDeferSendH2CTermReq
          (longlong *param_1,undefined2 param_2,undefined4 param_3,byte param_4,void *param_5)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  uVar3 = *(undefined8 *)(*param_1 + 0x10);
  if ((param_1[1] & 8U) == 0) {
    param_1[1] = param_1[1] | 8;
    StorPortExtendedFunction
              (0x80,uVar3,*(undefined8 *)(*param_1 + 0xa0),0,1,0x19,L"H2CTerm request send",0x200,3,
               9,L"Queue Id",*(undefined2 *)((longlong)param_1 + 0x26),L"",0,L"",0,L"",0,L"",0,L"",0
               ,L"",0,L"",0);
    lVar4 = ExAllocatePool2(0x40,0x119,0x6450664e);
    if (lVar4 == 0) {
      uVar5 = 0xc000021b;
    }
    else {
      *(ushort *)(lVar4 + 0x10) = *(ushort *)(lVar4 + 0x10) | 1;
      *(undefined2 *)(lVar4 + 0x12) = param_2;
      *(undefined4 *)(lVar4 + 0x14) = param_3;
      if ((param_4 < 8) || (param_5 == (void *)0x0)) {
        *(undefined1 *)(lVar4 + 0x18) = 0;
      }
      else {
        *(byte *)(lVar4 + 0x18) = param_4;
        memmove((void *)(lVar4 + 0x19),param_5,(ulonglong)param_4);
      }
      ExInterlockedInsertHeadList(param_1 + 0x42,lVar4,param_1 + 0x44);
      LOCK();
      piVar1 = (int *)((longlong)param_1 + 0x34);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (iVar2 == 0) {
        KeClearEvent((longlong)param_1 + 0x164);
        IoQueueWorkItem(*(undefined8 *)((longlong)param_1 + 0x15c),NvmofiProcessDeferredPDU,1,
                        param_1);
      }
    }
  }
  NvmofiNotifyQueueTransportFatalError(param_1,0x1400122b0);
  return uVar5;
}



===== NvmofiDeleteQueue @ 140001fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NvmofiDeleteQueue(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
  }
  if (*(ushort *)(lVar3 + 4) == 0) {
    plVar2 = *(longlong **)(*(longlong *)(lVar3 + 8) + 0xbc);
  }
  else {
    plVar2 = (longlong *)
             (*(longlong *)(*(longlong *)(lVar3 + 8) + 0xc4) + -0x270 +
             (ulonglong)*(ushort *)(lVar3 + 4) * 0x270);
  }
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(*plVar2 + 0x18) + 0x10) + 0x20);
  if ((int)plVar2[4] != 0) {
    *(undefined4 *)(plVar2 + 4) = 3;
    (**(code **)(lVar1 + 0x28))(plVar2);
    *(undefined4 *)(plVar2 + 4) = 0;
    plVar2[2] = 0;
  }
  NvmofiCleanupQueue((longlong)plVar2);
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(lVar3 + 0x10) = 0;
  StorPortNotification(0,param_1,param_2);
  StorPortExtendedFunction(0x1f,param_1,param_3);
  return;
}



===== NvmofiDisconnectQueue @ 1400020b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NvmofiDisconnectQueue(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
  }
  if (*(ushort *)(lVar3 + 4) == 0) {
    plVar2 = *(longlong **)(*(longlong *)(lVar3 + 8) + 0xbc);
  }
  else {
    plVar2 = (longlong *)
             (*(longlong *)(*(longlong *)(lVar3 + 8) + 0xc4) + -0x270 +
             (ulonglong)*(ushort *)(lVar3 + 4) * 0x270);
  }
  plVar2[1] = plVar2[1] | 0x200;
  NvmofiCleanupPackets((longlong)plVar2);
  NvmofiDrainDeferredRequests(plVar2);
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(*plVar2 + 0x18) + 0x10) + 0x20);
  if ((int)plVar2[4] != 0) {
    *(undefined4 *)(plVar2 + 4) = 3;
    (**(code **)(lVar1 + 0x28))(plVar2);
    *(undefined4 *)(plVar2 + 4) = 0;
    plVar2[2] = 0;
  }
  plVar2[1] = plVar2[1] & 0xfffffffffffffdff;
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(lVar3 + 0x10) = 0;
  StorPortNotification(0,param_1,param_2);
  StorPortExtendedFunction(0x1f,param_1,param_3);
  return;
}



===== NvmofiDrainDeferredRequests @ 1400021b4 =====

void NvmofiDrainDeferredRequests(longlong *param_1)

{
  longlong lVar1;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  if (**(int **)(*(longlong *)(*param_1 + 0x18) + 0x10) == 3) {
    KeWaitForSingleObject((longlong)param_1 + 0x164,0,0,0,0);
    while( true ) {
      lVar1 = ExInterlockedRemoveHeadList(param_1 + 0x42,param_1 + 0x44);
      if (lVar1 == 0) break;
      LOCK();
      *(int *)((longlong)param_1 + 0x34) = *(int *)((longlong)param_1 + 0x34) + -1;
      UNLOCK();
      if (*(char *)(lVar1 + 0x19) == '\x05') {
        NvmofiProcessCommandResponse(param_1,(char *)(lVar1 + 0x19),local_res8);
      }
      ExFreePoolWithTag(lVar1,0);
    }
    KeWaitForSingleObject((longlong)param_1 + 0x184,0,0,0,0);
    while( true ) {
      lVar1 = ExInterlockedRemoveHeadList(param_1 + 0x45,param_1 + 0x47);
      if (lVar1 == 0) break;
      LOCK();
      *(int *)(param_1 + 7) = (int)param_1[7] + -1;
      UNLOCK();
      ExFreePoolWithTag(lVar1,0);
    }
  }
  return;
}



===== NvmofiDrainQueue @ 1400022e0 =====

void NvmofiDrainQueue(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar2 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0x18);
  }
  if (*(ushort *)(lVar2 + 4) == 0) {
    plVar1 = *(longlong **)(*(longlong *)(lVar2 + 8) + 0xbc);
  }
  else {
    plVar1 = (longlong *)
             (*(longlong *)(*(longlong *)(lVar2 + 8) + 0xc4) + -0x270 +
             (ulonglong)*(ushort *)(lVar2 + 4) * 0x270);
  }
  plVar1[1] = plVar1[1] | 0x200;
  NvmofiCleanupPackets((longlong)plVar1);
  NvmofiDrainDeferredRequests(plVar1);
  plVar1[1] = plVar1[1] & 0xfffffffffffffdff;
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(lVar2 + 0x10) = 0;
  StorPortNotification(0,param_1,param_2);
  StorPortExtendedFunction(0x1f,param_1,param_3);
  return;
}



===== NvmofiFreeQueueResources @ 1400023b4 =====

void NvmofiFreeQueueResources(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (*(longlong *)(param_1 + 0x1e0) != 0) {
    ExpInterlockedFlushSList(param_1 + 0x1d0);
    uVar3 = 0;
    if (*(short *)(param_1 + 0x2c) != 0) {
      do {
        plVar1 = (longlong *)(*(longlong *)(param_1 + 0x1e0) + uVar3 * 8);
        if (*plVar1 != 0) {
          NvmofiReleaseWskPacket(plVar1);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(ushort *)(param_1 + 0x2c));
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x1e0),0);
    *(undefined8 *)(param_1 + 0x1e0) = 0;
  }
  return;
}



===== NvmofiInitializeWskSendPacket @ 140002440 =====

void NvmofiInitializeWskSendPacket
               (longlong param_1,undefined8 param_2,char param_3,char param_4,longlong param_5,
               int param_6,char param_7)

{
  longlong lVar1;
  uint uVar2;
  
  if ((param_5 == 0) || (param_6 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  *(int *)(param_1 + 0x3c) = param_6;
  *(undefined8 *)(param_1 + 0x2c) = param_2;
  *(longlong *)(param_1 + 0x34) = param_5;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(uint *)(param_1 + 0x28) =
       *(uint *)(param_1 + 0x28) & 0xffffff81 | 1 | uVar2 | -(uint)(param_3 != '\0') & 8 |
       -(uint)(param_4 != '\0') & 0x10 | -(uint)(param_7 != '\0') & 0x40;
  KeClearEvent(param_1 + 0x48,param_2,-param_3,-param_4);
  IoReuseIrp(param_1 + 0x230,0xc0000001);
  lVar1 = *(longlong *)(param_1 + 0x2e8);
  *(code **)(lVar1 + -0x10) = NvmofiWskPacketCompletion;
  *(longlong *)(lVar1 + -8) = param_1;
  *(undefined1 *)(lVar1 + -0x45) = 0xc0;
  return;
}



===== NvmofiNotifyQueueTransportFatalError @ 14000251c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvmofiNotifyQueueTransportFatalError(longlong *param_1,longlong param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  char *pcVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auStack_b8 [32];
  undefined4 local_98 [2];
  undefined4 local_90;
  undefined8 local_78;
  uint local_70;
  undefined4 local_6c;
  char local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar6 = 0xffffffffffffffff;
  uVar1 = *(undefined8 *)(*param_1 + 0x10);
  local_98[0] = 0x720001;
  local_90 = 2;
  local_78 = *(undefined8 *)(*param_1 + 0xa0);
  local_70 = (uint)*(ushort *)((longlong)param_1 + 0x26);
  uVar2 = 0xffffffffffffffff;
  local_6c = 0x10042;
  do {
    uVar2 = uVar2 + 1;
  } while (*(char *)(param_2 + uVar2) != '\0');
  lVar5 = 0x40;
  if (uVar2 < 0x41) {
    do {
      uVar6 = uVar6 + 1;
    } while (*(char *)(param_2 + uVar6) != '\0');
    if (0x7ffffffe < uVar6) {
      local_68[0] = '\0';
      goto LAB_1400025c8;
    }
  }
  else {
    uVar6 = 0x40;
  }
  pcVar4 = local_68;
  do {
    if ((lVar5 + -0x40 + uVar6 == 0) || (pcVar4[param_2 - (longlong)local_68] == '\0')) break;
    *pcVar4 = pcVar4[param_2 - (longlong)local_68];
    pcVar4 = pcVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  pcVar3 = pcVar4 + -1;
  if (lVar5 != 0) {
    pcVar3 = pcVar4;
  }
  *pcVar3 = '\0';
LAB_1400025c8:
  StorPortNotification(0x100f,uVar1,local_98);
  return;
}



===== NvmofiPrepareQueue @ 14000261c =====

ulonglong NvmofiPrepareQueue(longlong *param_1)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  
  uVar7 = 0;
  uVar2 = **(undefined8 **)(*param_1 + 0x10);
  piVar3 = *(int **)(*(longlong *)(*param_1 + 0x18) + 0x10);
  if (param_1[3] == 0) {
    lVar4 = IoAllocateIrp(1,0);
    param_1[3] = lVar4;
    if (lVar4 != 0) goto LAB_14000267a;
LAB_140002670:
    uVar7 = 0xc0000017;
  }
  else {
LAB_14000267a:
    iVar1 = *piVar3;
    if (iVar1 == 3) {
      uVar5 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        plVar6 = (longlong *)((longlong)param_1 + 0x19c);
        lVar4 = *plVar6;
      }
      else {
        if (*(longlong *)((longlong)param_1 + 0x1a4) == 0) {
          uVar5 = NvmofiAllocateWskPacket(param_1,(longlong *)((longlong)param_1 + 0x1a4));
          uVar7 = uVar5 & 0xffffffff;
          if ((int)uVar5 < 0) {
            return uVar7;
          }
        }
        if (*(longlong *)((longlong)param_1 + 0x1ac) == 0) {
          uVar5 = NvmofiAllocateWskPacket(param_1,(longlong *)((longlong)param_1 + 0x1ac));
          uVar7 = uVar5 & 0xffffffff;
          if ((int)uVar5 < 0) {
            return uVar7;
          }
        }
        if (*(longlong *)((longlong)param_1 + 0x1b4) == 0) {
          uVar5 = NvmofiAllocateWskPacket(param_1,(longlong *)((longlong)param_1 + 0x1b4));
          uVar7 = uVar5 & 0xffffffff;
          if ((int)uVar5 < 0) {
            return uVar7;
          }
        }
        plVar6 = (longlong *)((longlong)param_1 + 0x1bc);
        lVar4 = *plVar6;
      }
      if (lVar4 == 0) {
        uVar5 = NvmofiAllocateWskPacket(param_1,plVar6);
        uVar7 = uVar5 & 0xffffffff;
        if ((int)uVar5 < 0) {
          return uVar7;
        }
      }
      if (*(longlong *)((longlong)param_1 + 0x15c) == 0) {
        lVar4 = IoAllocateWorkItem(uVar2);
        *(longlong *)((longlong)param_1 + 0x15c) = lVar4;
        if (lVar4 == 0) goto LAB_140002670;
      }
      if (*(longlong *)((longlong)param_1 + 0x17c) == 0) {
        lVar4 = IoAllocateWorkItem(uVar2);
        *(longlong *)((longlong)param_1 + 0x17c) = lVar4;
        if (lVar4 == 0) goto LAB_140002670;
      }
      *(undefined2 *)((longlong)param_1 + 0x24) = 1;
    }
    else if ((iVar1 == 1) && (param_1[0x4c] == 0)) {
      lVar4 = IoAllocateWorkItem(uVar2);
      param_1[0x4c] = lVar4;
      if (lVar4 == 0) goto LAB_140002670;
    }
    plVar6 = param_1 + 0x3d;
    param_1[0x3e] = (longlong)plVar6;
    *plVar6 = (longlong)plVar6;
    KeInitializeSpinLock(param_1 + 0x3f);
    *(undefined4 *)((longlong)param_1 + 0x34) = 0;
    plVar6 = param_1 + 0x42;
    param_1[0x43] = (longlong)plVar6;
    *plVar6 = (longlong)plVar6;
    KeInitializeSpinLock(param_1 + 0x44);
    *(undefined4 *)(param_1 + 7) = 0;
    plVar6 = param_1 + 0x45;
    param_1[0x46] = (longlong)plVar6;
    *plVar6 = (longlong)plVar6;
    KeInitializeSpinLock(param_1 + 0x47);
    KeInitializeEvent((longlong)param_1 + 0x3c,1,0);
    KeInitializeEvent((longlong)param_1 + 0x164,0,1);
    KeInitializeEvent((longlong)param_1 + 0x184,0,1);
    param_1[1] = param_1[1] & 0xfffffffffffffdffU | 1;
  }
  return uVar7;
}



===== NvmofiProcessC2HData @ 140002884 =====

void NvmofiProcessC2HData(longlong *param_1,void *param_2,undefined1 *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  wchar_t *pwVar9;
  int *piVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  longlong lVar14;
  undefined2 uVar15;
  byte bVar16;
  undefined4 uVar17;
  char local_res8 [8];
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff18;
  
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  lVar14 = *(longlong *)((longlong)param_1 + 0x1ac);
  local_res8[0] = '\0';
  uVar4 = *(undefined8 *)(*param_1 + 0x10);
  local_res20 = 0;
  uVar8 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 == 0) {
    lVar14 = *(longlong *)((longlong)param_1 + 0x19c);
  }
  uVar8 = Feature_1687679290__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar8 != 0) && ((*(byte *)(param_1 + 1) & 2) != 0)) {
    *param_3 = 1;
    return;
  }
  iVar7 = StorPortNvmeofExtendedFunction
                    (7,uVar4,*(undefined8 *)(*param_1 + 0xa0),
                     *(undefined2 *)((longlong)param_1 + 0x26),
                     CONCAT44(uVar17,(uint)*(ushort *)((longlong)param_2 + 8)),&local_res20);
  if ((iVar7 != 0) || (local_res20 == 0)) {
    *param_3 = 1;
    uVar8 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
    bVar16 = *(byte *)((longlong)param_2 + 2);
    if ((int)uVar8 == 0) {
      uVar15 = 1;
      uVar17 = 8;
      goto LAB_140002f0d;
    }
    uVar15 = 1;
    uVar17 = 8;
    goto LAB_140002986;
  }
  puVar5 = *(undefined8 **)(local_res20 + 0x68);
  uVar12 = *(int *)(puVar5 + 3) + *(int *)((longlong)puVar5 + 0x1c);
  *(undefined4 *)(puVar5 + 2) = *(undefined4 *)((longlong)param_2 + 0xc);
  *(undefined4 *)((longlong)puVar5 + 0x14) = *(undefined4 *)((longlong)param_2 + 0x10);
  uVar13 = *(uint *)((longlong)param_2 + 0xc);
  if (uVar13 == uVar12) {
    uVar2 = *(uint *)((longlong)param_2 + 0x10);
    if (uVar2 <= *(int *)(local_res20 + 0x3c) - uVar12) {
      bVar16 = *(byte *)((longlong)param_2 + 1);
      bVar1 = *(byte *)((longlong)param_2 + 3);
      lVar6 = *(longlong *)(local_res20 + 0x40);
      *(undefined8 *)(lVar14 + 0x2c) = 0;
      *(ulonglong *)(lVar14 + 0x34) = (ulonglong)uVar13 + lVar6;
      *(uint *)(lVar14 + 0x3c) = uVar2;
      *(undefined8 *)(lVar14 + 0x40) = 0;
      *(uint *)(lVar14 + 0x28) =
           ((bVar16 & 2) << 4 ^ (*(uint *)(lVar14 + 0x28) & 0xffffffc7 | 7)) & 0xffffffbf;
      *(undefined8 *)(lVar14 + 0x60) = 0;
      *(undefined8 *)(lVar14 + 0x68) = 0;
      *(uint *)(lVar14 + 500) = (uint)bVar1 + (bVar16 & 1) * -4 + -0x18;
      KeClearEvent(lVar14 + 0x48);
      IoReuseIrp(lVar14 + 0x230,0xc0000001);
      lVar6 = *(longlong *)(lVar14 + 0x2e8);
      *(code **)(lVar6 + -0x10) = NvmofiWskPacketCompletion;
      *(longlong *)(lVar6 + -8) = lVar14;
      *(undefined1 *)(lVar6 + -0x45) = 0xc0;
      iVar7 = NvmofiBuildWskBuffer(lVar14);
      if (iVar7 < 0) {
        puVar5[1] = puVar5[1] | 0x100;
        param_1[1] = param_1[1] | 0x100;
        uVar15 = *(undefined2 *)((longlong)param_1 + 0x26);
        pwVar9 = L"C2HData NvmofiBuildWskBuffer";
      }
      else {
        iVar7 = NvmofiWskTcpReceive(lVar14,local_res8);
        if (local_res8[0] != '\0') {
          uVar8 = NvmofiWskWaitForCompletion(lVar14);
          iVar7 = (int)uVar8;
          NvmofiCleanupWskPacket(lVar14);
          if (iVar7 < 0) {
            puVar5[1] = puVar5[1] | 0x200;
            param_1[1] = param_1[1] | 0x100;
            uVar15 = *(undefined2 *)((longlong)param_1 + 0x26);
            pwVar9 = L"C2HData NvmofiWskWaitForCompletion";
            uVar11 = 0x19;
          }
          else {
            iVar7 = *(int *)((longlong)param_2 + 0xc);
            *(int *)(puVar5 + 3) = iVar7;
            iVar3 = *(int *)((longlong)param_2 + 0x10);
            *(int *)((longlong)puVar5 + 0x1c) = iVar3;
            if (iVar7 + iVar3 == *(int *)(local_res20 + 0x3c)) {
              puVar5[1] = puVar5[1] | 0x20;
            }
            if ((*(byte *)((longlong)param_2 + 1) & 0xc) == 0xc) {
              puVar5[1] = puVar5[1] | 0x10;
              *puVar5 = 0;
              if ((*(char *)(local_res20 + 2) == '(') && (*(uint *)(local_res20 + 0x38) != 0)) {
                uVar13 = 0;
                do {
                  uVar12 = *(uint *)(local_res20 + 0x78 + (ulonglong)uVar13 * 4);
                  if (((0x7f < uVar12) && (uVar12 < *(uint *)(local_res20 + 0x10))) &&
                     (piVar10 = (int *)(local_res20 + (ulonglong)uVar12), *piVar10 == 0x43))
                  goto LAB_140002dc7;
                  uVar13 = uVar13 + 1;
                } while (uVar13 < *(uint *)(local_res20 + 0x38));
              }
              piVar10 = (int *)0x0;
LAB_140002dc7:
              piVar10[0x18] = 0;
              piVar10[0x19] = 0;
              *(undefined2 *)((longlong)piVar10 + 0x56) = 0;
              *(undefined1 *)(local_res20 + 3) = 1;
              LOCK();
              *(short *)((longlong)param_1 + 0x2e) = *(short *)((longlong)param_1 + 0x2e) + -1;
              UNLOCK();
              StorPortNotification(0,uVar4);
            }
            param_1[1] = param_1[1] & 0xffffffffffffff7f;
            NvmofiWskTcpSetReceiveEvent((longlong)param_1,'\x01','\0');
            uVar11 = NvmofiWskResumeReceiveEvent((longlong)param_1);
            iVar7 = (int)uVar11;
            if (-1 < iVar7) {
              return;
            }
            uVar15 = *(undefined2 *)((longlong)param_1 + 0x26);
            pwVar9 = L"ResumeReceiveEvent failure";
            uVar11 = 0x16;
          }
          StorPortExtendedFunction
                    (0x80,uVar4,*(undefined8 *)(*param_1 + 0xa0),0,1,uVar11,pwVar9,0x200,2,0xf0,
                     L"QueueId",uVar15,L"NtStatus",(longlong)iVar7,L"",0,L"",0,L"",0,L"",0,L"",0,L""
                     ,0);
          return;
        }
        puVar5[1] = puVar5[1] | 0x200;
        param_1[1] = param_1[1] | 0x100;
        uVar15 = *(undefined2 *)((longlong)param_1 + 0x26);
        pwVar9 = L"C2HData NvmofiWskReceive";
      }
      StorPortExtendedFunction
                (0x80,uVar4,*(undefined8 *)(*param_1 + 0xa0),0,1,0x19,pwVar9,0x200,2,0xf0,L"QueueId"
                 ,uVar15,L"NtStatus",(longlong)iVar7,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
      NvmofiCleanupWskPacket(lVar14);
      return;
    }
    puVar5[1] = puVar5[1] | 0x80;
    *param_3 = 1;
    uVar8 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
    bVar16 = *(byte *)((longlong)param_2 + 2);
    if ((int)uVar8 == 0) {
      uVar15 = 4;
      goto LAB_14000299a;
    }
    uVar15 = 4;
  }
  else {
    puVar5[1] = puVar5[1] | 0x40;
    *param_3 = 1;
    uVar8 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
    bVar16 = *(byte *)((longlong)param_2 + 2);
    if ((int)uVar8 == 0) {
      uVar15 = 2;
LAB_14000299a:
      uVar17 = 0;
LAB_140002f0d:
      NvmofiSendH2CTermReq(param_1,uVar15,uVar17,bVar16,param_2);
      return;
    }
    uVar15 = 2;
  }
  uVar17 = 0;
LAB_140002986:
  NvmofiSendH2CTermReqWithDedicatedPacket
            (param_1,*(longlong *)((longlong)param_1 + 0x1b4),uVar15,uVar17,bVar16,param_2);
  return;
}



===== NvmofiProcessCommandResponse @ 140002f3c =====

void NvmofiProcessCommandResponse(longlong *param_1,void *param_2,undefined1 *param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong local_res8;
  
  local_res8 = 0;
  iVar1 = StorPortNvmeofExtendedFunction
                    (7,*(undefined8 *)(*param_1 + 0x10),*(undefined8 *)(*param_1 + 0xa0),
                     *(undefined2 *)((longlong)param_1 + 0x26),
                     *(undefined2 *)((longlong)param_2 + 0x14),&local_res8);
  if ((iVar1 == 0) && (local_res8 != 0)) {
    NvmofiCompleteSrb(param_1,local_res8,(int *)((longlong)param_2 + 8));
  }
  else {
    *param_3 = 1;
    uVar2 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      NvmofiSendH2CTermReq(param_1,1,8,*(byte *)((longlong)param_2 + 2),param_2);
    }
    else {
      NvmofiSendH2CTermReqWithDedicatedPacket
                (param_1,*(longlong *)((longlong)param_1 + 0x1b4),1,8,
                 *(byte *)((longlong)param_2 + 2),param_2);
    }
  }
  return;
}



===== NvmofiProcessDeferredPDU @ 140003020 =====

void NvmofiProcessDeferredPDU(undefined8 param_1,longlong *param_2)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  longlong lVar6;
  ulonglong uVar7;
  char *pcVar8;
  char cVar9;
  char local_res10 [24];
  
  pcVar8 = (char *)0x0;
  local_res10[0] = '\0';
  bVar5 = false;
  if ((*(uint *)(param_2 + 1) >> 9 & 1) == 0) {
    lVar6 = ExInterlockedRemoveHeadList(param_2 + 0x42,param_2 + 0x44);
    cVar9 = '\0';
    if (lVar6 != 0) {
      do {
        pcVar1 = (char *)(lVar6 + 0x19);
        if ((*(byte *)(lVar6 + 0x10) & 1) == 0) {
          cVar4 = *pcVar1;
          if (cVar4 == '\x03') {
            StorPortExtendedFunction
                      (0x80,*(undefined8 *)(*param_2 + 0x10),*(undefined8 *)(*param_2 + 0xa0),0,1,
                       0x19,L"C2HTermReq",0x200,2,0xf0,L"QueueId",
                       *(undefined2 *)((longlong)param_2 + 0x26),L"FatalErrorStatus",
                       *(undefined2 *)(lVar6 + 0x21),L"FatalErrorInfo",*(undefined4 *)(lVar6 + 0x23)
                       ,L"",0,L"",0,L"",0,L"",0,L"",0);
            pcVar8 = "C2HTermReq";
            goto LAB_14000324c;
          }
          if (cVar4 == '\x05') {
            NvmofiProcessCommandResponse(param_2,pcVar1,local_res10);
            cVar9 = local_res10[0];
            if (local_res10[0] != '\0') {
              pcVar8 = "CapsuleResp";
            }
          }
          else if (cVar4 == '\a') {
            NvmofiProcessC2HData(param_2,pcVar1,local_res10);
            cVar9 = local_res10[0];
            if (local_res10[0] != '\0') {
              pcVar8 = "C2HData";
            }
          }
        }
        else {
          uVar7 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar7 == 0) {
            NvmofiSendH2CTermReq
                      (param_2,*(undefined2 *)(lVar6 + 0x12),*(undefined4 *)(lVar6 + 0x14),
                       *(byte *)(lVar6 + 0x18),pcVar1);
          }
          else {
            NvmofiSendH2CTermReqWithDedicatedPacket
                      (param_2,*(longlong *)((longlong)param_2 + 0x1b4),
                       *(undefined2 *)(lVar6 + 0x12),*(undefined4 *)(lVar6 + 0x14),
                       *(byte *)(lVar6 + 0x18),pcVar1);
          }
          pcVar8 = "H2CTermReq";
          bVar5 = true;
LAB_14000324c:
          local_res10[0] = '\x01';
          cVar9 = '\x01';
        }
        ExFreePoolWithTag(lVar6,0);
        if (cVar9 != '\0') {
          param_2[1] = param_2[1] | 8;
          LOCK();
          *(int *)((longlong)param_2 + 0x34) = *(int *)((longlong)param_2 + 0x34) + -1;
          UNLOCK();
          if (!bVar5) {
            NvmofiNotifyQueueTransportFatalError(param_2,(longlong)pcVar8);
          }
          break;
        }
        LOCK();
        piVar2 = (int *)((longlong)param_2 + 0x34);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if ((iVar3 == 1) || ((*(uint *)(param_2 + 1) >> 9 & 1) != 0)) break;
        lVar6 = ExInterlockedRemoveHeadList(param_2 + 0x42);
        if (lVar6 == 0) break;
        cVar9 = local_res10[0];
      } while( true );
    }
  }
  KeSetEvent((longlong)param_2 + 0x164,0,0);
  return;
}



===== NvmofiProcessDeferredR2T @ 140003300 =====

void NvmofiProcessDeferredR2T(undefined8 param_1,longlong *param_2)

{
  void *pvVar1;
  longlong *plVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  longlong local_res18;
  undefined8 local_res20;
  
  bVar4 = false;
  uVar8 = *(undefined8 *)(*param_2 + 0x10);
  local_res18 = 0;
  local_res20 = uVar8;
  if ((*(uint *)(param_2 + 1) >> 9 & 1) == 0) {
    lVar6 = ExInterlockedRemoveHeadList(param_2 + 0x45,param_2 + 0x47);
    while (lVar6 != 0) {
      pvVar1 = (void *)(lVar6 + 0x19);
      iVar5 = StorPortNvmeofExtendedFunction
                        (7,uVar8,*(undefined8 *)(*param_2 + 0xa0),
                         *(undefined2 *)((longlong)param_2 + 0x26),*(undefined2 *)(lVar6 + 0x21),
                         &local_res18);
      if ((iVar5 == 0) && (local_res18 != 0)) {
        lVar3 = *(longlong *)(local_res18 + 0x68);
        iVar5 = *(int *)(lVar3 + 0x18) + *(int *)(lVar3 + 0x1c);
        *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(lVar6 + 0x25);
        *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(lVar6 + 0x29);
        if (*(int *)(lVar6 + 0x25) != iVar5) {
          *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x40;
          bVar4 = true;
          uVar7 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar7 == 0) {
            NvmofiSendH2CTermReq(param_2,2,0,*(byte *)(lVar6 + 0x1b),pvVar1);
          }
          else {
            NvmofiSendH2CTermReqWithDedicatedPacket
                      (param_2,*(longlong *)((longlong)param_2 + 0x1bc),2,0,*(byte *)(lVar6 + 0x1b),
                       pvVar1);
          }
        }
        if ((uint)(*(int *)(local_res18 + 0x3c) - iVar5) < *(uint *)(lVar6 + 0x29)) {
          *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x80;
          bVar4 = true;
          uVar7 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar7 == 0) {
            NvmofiSendH2CTermReq(param_2,4,0,*(byte *)(lVar6 + 0x1b),pvVar1);
          }
          else {
            NvmofiSendH2CTermReqWithDedicatedPacket
                      (param_2,*(longlong *)((longlong)param_2 + 0x1bc),4,0,*(byte *)(lVar6 + 0x1b),
                       pvVar1);
          }
        }
        uVar9 = *(uint *)(lVar6 + 0x25);
        uVar11 = *(uint *)(lVar6 + 0x29);
        if (!bVar4) {
          while (uVar11 != 0) {
            uVar10 = *(uint *)(param_2 + 6);
            if (uVar11 <= *(uint *)(param_2 + 6)) {
              uVar10 = uVar11;
            }
            uVar10 = uVar10 & 0xfffffffc;
            uVar7 = NvmofiSendH2CData(param_2,local_res18,*(undefined2 *)(lVar6 + 0x21),
                                      *(undefined2 *)(lVar6 + 0x23),uVar10 == uVar11,uVar9,uVar10);
            iVar5 = (int)uVar7;
            if (iVar5 < 0) {
              if ((iVar5 == -0x3ffffdf4) || (iVar5 == -0x7fffffef)) {
                bVar4 = false;
              }
              else {
                bVar4 = true;
              }
              break;
            }
            *(uint *)(lVar3 + 0x18) = uVar9;
            uVar9 = uVar9 + uVar10;
            *(uint *)(lVar3 + 0x1c) = uVar10;
            uVar11 = uVar11 - uVar10;
            if (uVar11 == 0) {
              *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x20;
            }
          }
        }
      }
      else {
        bVar4 = true;
        uVar7 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar7 == 0) {
          NvmofiSendH2CTermReq(param_2,1,8,*(byte *)(lVar6 + 0x1b),pvVar1);
        }
        else {
          NvmofiSendH2CTermReqWithDedicatedPacket
                    (param_2,*(longlong *)((longlong)param_2 + 0x1bc),1,8,*(byte *)(lVar6 + 0x1b),
                     pvVar1);
        }
      }
      ExFreePoolWithTag(lVar6,0);
      if (bVar4) {
        param_2[1] = param_2[1] | 8;
        LOCK();
        *(int *)(param_2 + 7) = (int)param_2[7] + -1;
        UNLOCK();
        NvmofiNotifyQueueTransportFatalError(param_2,0x140012368);
        break;
      }
      LOCK();
      plVar2 = param_2 + 7;
      lVar6 = *plVar2;
      *(int *)plVar2 = (int)*plVar2 + -1;
      UNLOCK();
      if (((int)lVar6 == 1) || ((*(uint *)(param_2 + 1) >> 9 & 1) != 0)) break;
      lVar6 = ExInterlockedRemoveHeadList(param_2 + 0x45,param_2 + 0x47);
      uVar8 = local_res20;
    }
  }
  KeSetEvent((longlong)param_2 + 0x184,0,0);
  return;
}



===== NvmofiProcessQueueCommand @ 140003610 =====

ulonglong NvmofiProcessQueueCommand(longlong *param_1,longlong param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  int *piVar9;
  undefined1 uVar10;
  char cVar11;
  char cVar12;
  longlong local_res18;
  longlong local_res20;
  undefined8 in_stack_fffffffffffffef8;
  undefined4 uVar13;
  
  uVar13 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);
  puVar2 = *(undefined8 **)(param_2 + 0x68);
  lVar5 = 0;
  local_res18 = 0;
  local_res20 = *param_1;
  cVar11 = '\0';
  cVar12 = '\0';
  uVar8 = 0xc0000001;
  iVar4 = **(int **)(*(longlong *)(local_res20 + 0x18) + 0x10);
  uVar3 = *(undefined8 *)(local_res20 + 0x10);
  if ((param_1[1] & 0xcU) != 0) goto LAB_140003806;
  if (((ulonglong)param_1[1] >> 9 & 1) != 0) {
    *(undefined1 *)(param_2 + 3) = 5;
    goto LAB_14000382c;
  }
  lVar5 = ExpInterlockedPopEntrySList(param_1 + 0x3a);
  if (lVar5 == 0) {
    lVar5 = 0;
    local_res18 = 0;
    StorPortExtendedFunction
              (0x80,uVar3,*(undefined8 *)(local_res20 + 0xa0),0,CONCAT44(uVar13,1),0,
               L"Process queue command no packet",0x200,3,9,L"Queue Id",
               *(undefined2 *)((longlong)param_1 + 0x26),L"",0,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
    uVar10 = 0x26;
    goto LAB_14000380e;
  }
  if ((*(char *)(param_2 + 2) == '(') && (*(uint *)(param_2 + 0x38) != 0)) {
    uVar7 = 0;
    do {
      uVar1 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar7 * 4);
      if (((0x7f < uVar1) && (uVar1 < *(uint *)(param_2 + 0x10))) &&
         (piVar9 = (int *)(param_2 + (ulonglong)uVar1), *piVar9 == 0x43)) goto LAB_1400036fe;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_2 + 0x38));
  }
  piVar9 = (int *)0x0;
LAB_1400036fe:
  if (((*(longlong *)(param_2 + 0x40) != 0) && (*(int *)(param_2 + 0x3c) != 0)) &&
     ((char)*(undefined4 *)(param_2 + 0x18) < '\0')) {
    uVar7 = *(uint *)(param_2 + 0x3c);
    cVar12 = '\0';
    if (*(short *)((longlong)param_1 + 0x26) == 0) {
      if (uVar7 < 0x2001) goto LAB_140003733;
    }
    else if (uVar7 <= *(uint *)(*param_1 + 0xb0)) {
LAB_140003733:
      cVar12 = '\x01';
    }
    cVar11 = '\x01';
    if ((iVar4 == 1) &&
       (((byte)((char)piVar9[0x14] - 1U) < 2 ||
        (*(uint *)(*(longlong *)(*(longlong *)(*(longlong *)(*param_1 + 0x18) + 0x10) + 0xc0) + 0x5c
                  ) < uVar7)))) {
      cVar12 = '\0';
      cVar11 = '\x01';
    }
  }
  local_res18 = lVar5;
  NvmofiInitializeWskSendPacket
            (lVar5,param_2,cVar11,cVar12,*(longlong *)(param_2 + 0x40),*(int *)(param_2 + 0x3c),
             iVar4 == 1);
  if (iVar4 == 1) {
    uVar8 = InitializeRdmaCapsuleCommand((longlong)piVar9,lVar5);
    iVar4 = (int)uVar8;
    uVar8 = uVar8 & 0xffffffff;
    if (-1 < iVar4) goto LAB_1400038b7;
    if (iVar4 < -0x3fffff4a) {
      if (iVar4 == -0x3fffff4b) {
        uVar10 = 9;
        goto LAB_14000380e;
      }
      if (iVar4 == -0x7ffffffb) {
        uVar10 = 0x12;
        goto LAB_14000380e;
      }
      if (iVar4 == -0x7fffffef) {
        uVar10 = 5;
        goto LAB_14000380e;
      }
      if (iVar4 == -0x3ffffff0) {
        uVar10 = 0x22;
        goto LAB_14000380e;
      }
      if (iVar4 == -0x3fffffde) {
        uVar10 = 0x17;
        goto LAB_14000380e;
      }
      if (iVar4 != -0x3fffff66) {
        if (iVar4 != -0x3fffff63) goto LAB_140003897;
        goto LAB_140003806;
      }
      goto LAB_140003843;
    }
    if (iVar4 == -0x3fffff4a) {
LAB_140003806:
      uVar10 = 0x25;
    }
    else if (iVar4 == -0x3fffff40) {
      uVar10 = 8;
    }
    else {
      if (((iVar4 == -0x3ffffe7c) || (iVar4 == -0x3ffffdf4)) || (iVar4 == -0x3ffffdbf))
      goto LAB_140003806;
      if (iVar4 == -0x3ffffb8a) {
        uVar10 = 0x18;
      }
      else {
LAB_140003897:
        uVar10 = 4;
      }
    }
  }
  else {
    InitializeTcpCapsuleCommand((longlong)piVar9,lVar5);
LAB_1400038b7:
    *puVar2 = param_1;
    uVar8 = (ulonglong)(*(uint *)(lVar5 + 0x28) >> 2);
    uVar8 = (uVar8 ^ puVar2[1]) & 0xfffffffffffffffe ^ uVar8;
    puVar2[1] = uVar8;
    uVar6 = (ulonglong)(*(uint *)(lVar5 + 0x28) >> 2);
    uVar6 = (uVar8 ^ uVar6) & 0xfffffffffffffffd ^ uVar6;
    puVar2[1] = uVar6;
    uVar7 = *(uint *)(lVar5 + 0x28);
    puVar2[2] = 0;
    puVar2[3] = 0;
    uVar8 = (ulonglong)(uVar7 >> 2);
    puVar2[4] = 0;
    puVar2[1] = (uVar6 ^ uVar8) & 0xfffffffffffffc03 ^ uVar8 & 0xfffffffffffffc07;
    uVar7 = NvmofiBuildWskBuffer(lVar5);
    uVar8 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) {
      puVar2[1] = puVar2[1] | 0x100;
LAB_140003843:
      uVar10 = 0x26;
    }
    else {
      puVar2[1] = puVar2[1] | 8;
      LOCK();
      *(short *)((longlong)param_1 + 0x2e) = *(short *)((longlong)param_1 + 0x2e) + 1;
      UNLOCK();
      iVar4 = NvmofiSendQueuePacket(lVar5);
      uVar8 = (ulonglong)iVar4;
      if (-1 < iVar4) {
        uVar8 = 0;
        goto LAB_14000382c;
      }
      puVar2[1] = puVar2[1] & 0xfffffffffffffff7;
      LOCK();
      *(short *)((longlong)param_1 + 0x2e) = *(short *)((longlong)param_1 + 0x2e) + -1;
      UNLOCK();
      uVar10 = 0x17;
      StorPortExtendedFunction
                (0x80,uVar3,*(undefined8 *)(local_res20 + 0xa0),0,1,0x17,
                 L"Process queue command NvmofiSendQueuePacket",0x200,2,9,L"QueueId",
                 *(undefined2 *)((longlong)param_1 + 0x26),L"NtStatus",uVar8,L"",0,L"",0,L"",0,L"",0
                 ,L"",0,L"",0);
      if (iVar4 < -0x3fffff4a) {
        if (iVar4 == -0x3fffff4b) {
          uVar10 = 9;
        }
        else if (iVar4 == -0x7ffffffb) {
          uVar10 = 0x12;
        }
        else if (iVar4 == -0x7fffffef) {
          uVar10 = 5;
        }
        else if (iVar4 == -0x3ffffff0) {
          uVar10 = 0x22;
        }
        else if (iVar4 != -0x3fffffde) {
          if (iVar4 != -0x3fffff66) {
            if (iVar4 != -0x3fffff63) goto LAB_140003ad6;
            goto LAB_140003a7d;
          }
          uVar10 = 0x26;
        }
      }
      else if (iVar4 == -0x3fffff4a) {
LAB_140003a7d:
        uVar10 = 0x25;
      }
      else if (iVar4 == -0x3fffff40) {
        uVar10 = 8;
      }
      else {
        if (((iVar4 == -0x3ffffe7c) || (iVar4 == -0x3ffffdf4)) || (iVar4 == -0x3ffffdbf))
        goto LAB_140003a7d;
        if (iVar4 == -0x3ffffb8a) {
          uVar10 = 0x18;
        }
        else {
LAB_140003ad6:
          uVar10 = 4;
        }
      }
      lVar5 = local_res18;
    }
  }
LAB_14000380e:
  *(undefined1 *)(param_2 + 3) = uVar10;
  if (lVar5 != 0) {
    NvmofiCleanupWskPacket(lVar5);
    NvmofiReturnQueuePacket(&local_res18);
  }
LAB_14000382c:
  return uVar8 & 0xffffffff;
}



===== NvmofiRdmaInitializeNvme @ 140003bf0 =====

undefined8 NvmofiRdmaInitializeNvme(longlong param_1)

{
  *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) & 0xfffffffffffffff7;
  return 0;
}



===== NvmofiReconnectQueue @ 140003c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NvmofiReconnectQueue(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  if (*(char *)(param_2 + 2) == '(') {
    lVar6 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x18);
  }
  if (*(ushort *)(lVar6 + 4) == 0) {
    plVar5 = *(longlong **)(*(longlong *)(lVar6 + 8) + 0xbc);
  }
  else {
    plVar5 = (longlong *)
             (*(longlong *)(*(longlong *)(lVar6 + 8) + 0xc4) + -0x270 +
             (ulonglong)*(ushort *)(lVar6 + 4) * 0x270);
  }
  lVar1 = *(longlong *)(*(longlong *)(*plVar5 + 0x18) + 0x10);
  *(undefined4 *)(plVar5 + 4) = 1;
  iVar4 = (**(code **)(*(longlong *)(lVar1 + 0x20) + 0x20))
                    (plVar5,lVar1 + 0x38,*plVar5 + 0x20,local_res8);
  if (-1 < iVar4) {
    iVar4 = (*(code *)**(undefined8 **)(*(longlong *)(*(longlong *)(*plVar5 + 0x18) + 0x10) + 0x20))
                      (plVar5);
    if (-1 < iVar4) {
      *(undefined4 *)(plVar5 + 4) = 2;
      cVar3 = '\x01';
      goto LAB_140003ccc;
    }
  }
  cVar3 = '\x04';
LAB_140003ccc:
  *(char *)(param_2 + 3) = cVar3;
  *(undefined4 *)(lVar6 + 0x10) = local_res8[0];
  if (*(char *)(param_2 + 3) != '\x01') {
    if (plVar5[2] != 0) {
      piVar2 = *(int **)(*(longlong *)(*plVar5 + 0x18) + 0x10);
      if (*piVar2 == 3) {
        NvmofiWskTcpSetReceiveEvent((longlong)plVar5,'\0','\0');
      }
      (**(code **)(*(longlong *)(piVar2 + 8) + 0x10))(plVar5,1);
    }
    *(undefined4 *)(plVar5 + 4) = 0;
    plVar5[2] = 0;
  }
  StorPortNotification(0,param_1,param_2);
  StorPortExtendedFunction(0x1f,param_1,param_3);
  return;
}



===== NvmofiReleaseWskPacket @ 140003d64 =====

void NvmofiReleaseWskPacket(longlong *param_1)

{
  if (*(longlong *)(*param_1 + 0x1f8) != 0) {
    IoFreeMdl();
    *(undefined8 *)(*param_1 + 0x1f8) = 0;
  }
  if (*(longlong *)(*param_1 + 0x204) != 0) {
    IoFreeMdl();
    *(undefined8 *)(*param_1 + 0x204) = 0;
  }
  ExFreePoolWithTag(*param_1,0);
  *param_1 = 0;
  return;
}



===== NvmofiResumeReceive @ 140003de0 =====

void NvmofiResumeReceive(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = NvmofiWskResumeReceiveEvent((longlong)param_2);
  if ((int)uVar1 < 0) {
    StorPortExtendedFunction
              (0x80,param_1,*(undefined8 *)(*param_2 + 0xa0),0,1,0x16,L"ResumeReceiveEvent failure",
               0x200,2,0xf0,L"QueueId",*(undefined2 *)((longlong)param_2 + 0x26),L"NtStatus",
               (longlong)(int)uVar1,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
  }
  StorPortExtendedFunction(0x1f,param_1,param_3);
  return;
}



===== NvmofiReturnQueuePacket @ 140003f20 =====

void NvmofiReturnQueuePacket(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  *(undefined8 *)(lVar1 + 0x2c) = 0;
  ExpInterlockedPushEntrySList(*(longlong *)(lVar1 + 0x20) + 0x1d0,*param_1);
  *param_1 = 0;
  return;
}



===== NvmofiSendH2CData @ 140003f5c =====

ulonglong NvmofiSendH2CData(longlong *param_1,longlong param_2,undefined2 param_3,undefined2 param_4
                           ,char param_5,uint param_6,int param_7)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 in_stack_ffffffffffffff18;
  undefined4 uVar8;
  undefined2 uVar9;
  longlong local_30;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  uVar6 = 0xc0000001;
  uVar1 = *(undefined8 *)(*param_1 + 0x10);
  if ((param_1[1] & 0xcU) != 0) {
    uVar6 = 0xc000020c;
    goto LAB_1400043d6;
  }
  if (((ulonglong)param_1[1] >> 9 & 1) != 0) {
    uVar6 = 0x80000011;
    goto LAB_1400043d6;
  }
  lVar3 = ExpInterlockedPopEntrySList(param_1 + 0x3a);
  lVar7 = 0;
  if (lVar3 != 0) {
    lVar7 = lVar3;
  }
  local_30 = lVar7;
  if (lVar7 == 0) {
    StorPortExtendedFunction
              (0x80,uVar1,*(undefined8 *)(*param_1 + 0xa0),0,CONCAT44(uVar8,1),0,
               L"Send H2CData no packet",0x200,3,9,L"Queue Id",
               *(undefined2 *)((longlong)param_1 + 0x26),L"CmdCapsuleId",param_3,L"TransferTag",
               param_4,L"Offset",(ulonglong)param_6,L"Length",param_7,L"",0,L"",0,L"",0);
    *(undefined1 *)(param_2 + 3) = 0x26;
    goto LAB_1400043d6;
  }
  lVar3 = *(longlong *)(param_2 + 0x68);
  NvmofiInitializeWskSendPacket
            (lVar7,0,'\x01','\x01',*(longlong *)(param_2 + 0x40) + (ulonglong)param_6,param_7,'\0');
  InitializeH2CData(lVar7,param_3,param_4,param_5,param_6);
  iVar2 = NvmofiBuildWskBuffer(lVar7);
  uVar6 = (ulonglong)iVar2;
  if (iVar2 < 0) {
    *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x100;
    uVar9 = *(undefined2 *)((longlong)param_1 + 0x26);
    pwVar4 = L"H2CData NvmofiBuildWskBuffer";
LAB_14000436a:
    StorPortExtendedFunction
              (0x80,uVar1,*(undefined8 *)(*param_1 + 0xa0),0,1,0x19,pwVar4,0x200,2,9,L"QueueId",
               uVar9,L"NtStatus",uVar6,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
  }
  else {
    iVar2 = NvmofiSendQueuePacket(lVar7);
    uVar6 = (ulonglong)iVar2;
    if (iVar2 < 0) {
      *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x200;
      uVar9 = *(undefined2 *)((longlong)param_1 + 0x26);
      pwVar4 = L"H2CData NvmofiSendQueuePacket";
      goto LAB_14000436a;
    }
    uVar5 = NvmofiWskWaitForCompletion(lVar7);
    uVar6 = (ulonglong)(int)uVar5;
    if ((int)uVar5 < 0) {
      *(ulonglong *)(lVar3 + 8) = *(ulonglong *)(lVar3 + 8) | 0x200;
      uVar9 = *(undefined2 *)((longlong)param_1 + 0x26);
      pwVar4 = L"H2CData NvmofiWskWaitForCompletion";
      goto LAB_14000436a;
    }
  }
  NvmofiCleanupWskPacket(lVar7);
  NvmofiReturnQueuePacket(&local_30);
LAB_1400043d6:
  return uVar6 & 0xffffffff;
}



===== NvmofiSendH2CTermReq @ 1400043fc =====

void NvmofiSendH2CTermReq
               (longlong *param_1,undefined2 param_2,undefined4 param_3,byte param_4,void *param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  wchar_t *pwVar6;
  char local_res8 [8];
  undefined2 uVar7;
  
  lVar1 = *(longlong *)((longlong)param_1 + 0x19c);
  uVar2 = *(undefined8 *)(*param_1 + 0x10);
  local_res8[0] = '\0';
  uVar4 = Feature_1687679290__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) && ((*(byte *)(param_1 + 1) & 2) != 0)) {
    return;
  }
  StorPortExtendedFunction(0x80);
  NvmofiInitializeWskSendPacket(lVar1,0,'\0','\0',0,0,'\0');
  InitializeH2CTermReq(lVar1,param_2,param_3,param_4,param_5);
  iVar3 = NvmofiBuildWskBuffer(lVar1);
  if (iVar3 < 0) {
    uVar7 = *(undefined2 *)((longlong)param_1 + 0x26);
    lVar5 = (longlong)iVar3;
    pwVar6 = L"H2CTermReq NvmofiBuildWskBuffer";
  }
  else {
    iVar3 = NvmofiWskTcpSend(lVar1,local_res8);
    if (local_res8[0] == '\0') {
      uVar7 = *(undefined2 *)((longlong)param_1 + 0x26);
      lVar5 = (longlong)iVar3;
      pwVar6 = L"H2CTermReq NvmofiWskSend";
    }
    else {
      uVar4 = NvmofiWskWaitForCompletion(lVar1);
      if (-1 < (int)uVar4) goto LAB_1400047a5;
      uVar7 = *(undefined2 *)((longlong)param_1 + 0x26);
      lVar5 = (longlong)(int)uVar4;
      pwVar6 = L"H2CTermReq NvmofiWskWaitForCompletion";
    }
  }
  StorPortExtendedFunction
            (0x80,uVar2,*(undefined8 *)(*param_1 + 0xa0),0,1,0x19,pwVar6,0x200,2,9,L"QueueId",uVar7,
             L"NtStatus",lVar5,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
LAB_1400047a5:
  NvmofiCleanupWskPacket(lVar1);
  return;
}



===== NvmofiSendH2CTermReqWithDedicatedPacket @ 1400047d8 =====

void NvmofiSendH2CTermReqWithDedicatedPacket
               (longlong *param_1,longlong param_2,undefined2 param_3,undefined4 param_4,
               byte param_5,void *param_6)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  char local_res8 [8];
  undefined2 uVar6;
  
  local_res8[0] = '\0';
  uVar1 = *(undefined8 *)(*param_1 + 0x10);
  uVar3 = Feature_1687679290__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 != 0) && ((*(byte *)(param_1 + 1) & 2) != 0)) {
    return;
  }
  StorPortExtendedFunction(0x80);
  NvmofiInitializeWskSendPacket(param_2,0,'\0','\0',0,0,'\0');
  InitializeH2CTermReq(param_2,param_3,param_4,param_5,param_6);
  iVar2 = NvmofiBuildWskBuffer(param_2);
  if (iVar2 < 0) {
    uVar6 = *(undefined2 *)((longlong)param_1 + 0x26);
    lVar4 = (longlong)iVar2;
    pwVar5 = L"H2CTermReq NvmofiBuildWskBuffer";
  }
  else {
    iVar2 = NvmofiWskTcpSend(param_2,local_res8);
    if (local_res8[0] == '\0') {
      uVar6 = *(undefined2 *)((longlong)param_1 + 0x26);
      lVar4 = (longlong)iVar2;
      pwVar5 = L"H2CTermReq NvmofiWskSend";
    }
    else {
      uVar3 = NvmofiWskWaitForCompletion(param_2);
      if (-1 < (int)uVar3) goto LAB_140004b7a;
      uVar6 = *(undefined2 *)((longlong)param_1 + 0x26);
      lVar4 = (longlong)(int)uVar3;
      pwVar5 = L"H2CTermReq NvmofiWskWaitForCompletion";
    }
  }
  StorPortExtendedFunction
            (0x80,uVar1,*(undefined8 *)(*param_1 + 0xa0),0,1,0x19,pwVar5,0x200,2,9,L"QueueId",uVar6,
             L"NtStatus",lVar4,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
LAB_140004b7a:
  NvmofiCleanupWskPacket(param_2);
  return;
}



===== NvmofiSendQueueNextPacket @ 140004bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NvmofiSendQueueNextPacket(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  char local_res10 [8];
  undefined8 local_res18;
  undefined1 auStack_128 [8];
  undefined1 auStack_120 [24];
  undefined4 local_108;
  undefined4 local_100;
  wchar_t *local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  wchar_t *local_d8;
  ulonglong local_d0;
  wchar_t *local_c8;
  ulonglong local_c0;
  wchar_t *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  undefined8 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_res18 = param_3;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_res10[0] = '\0';
  bVar6 = false;
  piVar2 = *(int **)(*(longlong *)(*param_2 + 0x18) + 0x10);
  while( true ) {
    bVar7 = false;
    puVar10 = auStack_128;
    if (((param_2[1] & 0xcU) != 0) || (puVar10 = auStack_128, ((ulonglong)param_2[1] >> 9 & 1) != 0)
       ) goto LAB_140004ecc;
    KeAcquireInStackQueuedSpinLock(param_2 + 0x3f,&local_58);
    plVar1 = param_2 + 0x3d;
    plVar11 = (longlong *)*plVar1;
    puVar10 = auStack_128;
    if (plVar11 == plVar1) break;
    if (*piVar2 == 1) {
      puVar10 = auStack_128;
      if ((int)param_2[0x40] < *(int *)((longlong)param_2 + 0x204)) {
        if (((longlong *)plVar11[1] != plVar1) ||
           (lVar3 = *plVar11, (longlong *)*(longlong *)(lVar3 + 8) != plVar11)) {
LAB_140004eb1:
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          puVar10 = auStack_120;
          break;
        }
        *plVar1 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar1;
        if ((plVar11 != (longlong *)0x10) && ((*(byte *)(plVar11 + 3) & 8) != 0)) {
          if (*(int *)((longlong)param_2 + 0x20c) <= (int)param_2[0x41]) {
            lVar3 = *plVar1;
            if (*(longlong **)(lVar3 + 8) != plVar1) goto LAB_140004eb1;
            *plVar11 = lVar3;
            plVar11[1] = (longlong)plVar1;
            *(longlong **)(lVar3 + 8) = plVar11;
            *plVar1 = (longlong)plVar11;
            KeReleaseInStackQueuedSpinLock(&local_58);
            uVar9 = NvmofiQueueWorkItem(*(undefined8 *)(*param_2 + 0x10),NvmofiSendQueueNextPacket,
                                        param_2);
            puVar10 = auStack_128;
            if (uVar9 != 0) {
              local_d0 = (ulonglong)*(ushort *)((longlong)param_2 + 0x26);
              local_60 = 0;
              local_68 = L"";
              local_70 = 0;
              local_78 = L"";
              local_80 = 0;
              local_88 = L"";
              local_90 = 0;
              local_98 = L"";
              local_a0 = 0;
              local_a8 = L"";
              local_b0 = 0;
              local_b8 = L"";
              local_c0 = (ulonglong)uVar9;
              local_c8 = L"StorStatus";
              local_d8 = L"QueueId";
              local_e0 = 9;
              local_e8 = 3;
              local_f0 = 0x200;
              local_f8 = L"QueueWorkItem failure - NvmofiSendQueueNextPacket";
              local_100 = 0x1b;
              local_108 = 1;
              StorPortExtendedFunction
                        (0x80,*(undefined8 *)(*param_2 + 0x10),*(undefined8 *)(*param_2 + 0xa0),0);
              puVar10 = auStack_128;
            }
            goto LAB_140004ecc;
          }
          LOCK();
          *(int *)(param_2 + 0x41) = (int)param_2[0x41] + 1;
          UNLOCK();
          bVar6 = true;
        }
        *(int *)(param_2 + 0x40) = (int)param_2[0x40] + 1;
        bVar7 = true;
        goto LAB_140004cbb;
      }
      break;
    }
    *(int *)(param_2 + 0x40) = (int)param_2[0x40] + 1;
LAB_140004cbb:
    plVar11 = plVar11 + -2;
    KeReleaseInStackQueuedSpinLock(&local_58);
    puVar10 = auStack_128;
    if (plVar11 == (longlong *)0x0) goto LAB_140004ecc;
    iVar8 = (**(code **)(*(longlong *)(piVar2 + 8) + 0x30))(plVar11,local_res10);
    puVar10 = auStack_128;
    if ((local_res10[0] != '\0') || (puVar10 = auStack_128, iVar8 == -0x3ffffdf4))
    goto LAB_140004ecc;
    KeAcquireInStackQueuedSpinLock(param_2 + 0x3f,&local_58);
    *(int *)(param_2 + 0x40) = (int)param_2[0x40] + -1;
    if (bVar6) {
      LOCK();
      *(int *)(param_2 + 0x41) = (int)param_2[0x41] + -1;
      UNLOCK();
    }
    if (!bVar7) {
      plVar4 = (longlong *)*plVar1;
      if (((longlong *)plVar4[1] != plVar1) ||
         (lVar3 = *plVar4, *(longlong **)(lVar3 + 8) != plVar4)) goto LAB_140004eb1;
      *plVar1 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar1;
    }
    KeReleaseInStackQueuedSpinLock(&local_58);
    NvmofiWskPacketPostCompletion((longlong)plVar11,iVar8);
  }
  *(undefined8 *)(puVar10 + -8) = 0x140004ec7;
  KeReleaseInStackQueuedSpinLock(puVar10 + 0xd0);
LAB_140004ecc:
  *(undefined8 *)(puVar10 + -8) = 0x140004ee8;
  StorPortExtendedFunction(0x1f,*(undefined8 *)(puVar10 + 0x130),*(undefined8 *)(puVar10 + 0x140));
  return;
}



===== NvmofiSendQueuePacket @ 140004f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiSendQueuePacket(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  longlong *plVar11;
  bool bVar12;
  char local_res8 [8];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  plVar2 = *(longlong **)(param_1 + 0x20);
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_res8[0] = '\0';
  bVar12 = false;
  lVar3 = *(longlong *)(*(longlong *)(*plVar2 + 0x18) + 0x10);
  if ((plVar2[1] & 0xcU) != 0) {
    return -0x3ffffdf4;
  }
  if (((ulonglong)plVar2[1] >> 9 & 1) != 0) {
    return -0x7fffffef;
  }
  KeAcquireInStackQueuedSpinLock(plVar2 + 0x3f,&local_38);
  if ((*(uint *)(param_1 + 0x28) & 0x40) == 0) {
    plVar11 = plVar2 + 0x3d;
    plVar4 = (longlong *)plVar2[0x3e];
    plVar1 = (longlong *)(param_1 + 0x10);
    plVar5 = (longlong *)*plVar11;
    if ((longlong *)*plVar4 != plVar11) goto LAB_140005210;
    *plVar1 = (longlong)plVar11;
    bVar12 = plVar5 == plVar11;
    *(longlong **)(param_1 + 0x18) = plVar4;
    bVar7 = true;
    *plVar4 = (longlong)plVar1;
    plVar2[0x3e] = (longlong)plVar1;
    bVar8 = true;
    if (bVar12) goto LAB_14000501b;
  }
  else if ((((*(uint *)(param_1 + 0x28) & 8) == 0) ||
           ((int)plVar2[0x41] < *(int *)((longlong)plVar2 + 0x20c))) &&
          ((int)plVar2[0x40] < *(int *)((longlong)plVar2 + 0x204))) {
    bVar12 = true;
    bVar8 = false;
LAB_14000501b:
    bVar7 = bVar8;
    *(int *)(plVar2 + 0x40) = (int)plVar2[0x40] + 1;
    if (((byte)*(undefined4 *)(param_1 + 0x28) & 0x48) == 0x48) {
      LOCK();
      *(int *)(plVar2 + 0x41) = (int)plVar2[0x41] + 1;
      UNLOCK();
    }
  }
  else {
    plVar11 = (longlong *)plVar2[0x3e];
    plVar1 = (longlong *)(param_1 + 0x10);
    if ((longlong *)*plVar11 != plVar2 + 0x3d) goto LAB_140005210;
    *plVar1 = (longlong)(plVar2 + 0x3d);
    bVar7 = true;
    *(longlong **)(param_1 + 0x18) = plVar11;
    *plVar11 = (longlong)plVar1;
    plVar2[0x3e] = (longlong)plVar1;
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  if (!bVar12) {
    return 0;
  }
  iVar9 = (**(code **)(*(longlong *)(lVar3 + 0x20) + 0x30))(param_1,local_res8);
  if (local_res8[0] != '\0') {
    return 0;
  }
  if (iVar9 == -0x3ffffdf4) {
    return -0x3ffffdf4;
  }
  KeAcquireInStackQueuedSpinLock(plVar2 + 0x3f,&local_38);
  *(int *)(plVar2 + 0x40) = (int)plVar2[0x40] + -1;
  if (((byte)*(undefined4 *)(param_1 + 0x28) & 0x48) == 0x48) {
    LOCK();
    *(int *)(plVar2 + 0x41) = (int)plVar2[0x41] + -1;
    UNLOCK();
  }
  if (bVar7) {
    plVar11 = (longlong *)(param_1 + 0x10);
    plVar1 = (longlong *)*plVar11;
    if (((longlong *)plVar1[1] != plVar11) || (lVar3 = *plVar1, *(longlong **)(lVar3 + 8) != plVar1)
       ) {
LAB_140005210:
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      return -0x3ffffdf4;
    }
    *plVar11 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar11;
  }
  plVar1 = (longlong *)plVar2[0x3d];
  KeReleaseInStackQueuedSpinLock(&local_38);
  if (plVar1 == plVar2 + 0x3d) {
    return iVar9;
  }
  iVar10 = NvmofiQueueWorkItem(*(undefined8 *)(*plVar2 + 0x10),NvmofiSendQueueNextPacket,plVar2);
  if (iVar10 == 0) {
    return iVar9;
  }
  StorPortExtendedFunction
            (0x80,*(undefined8 *)(*plVar2 + 0x10),*(undefined8 *)(*plVar2 + 0xa0),0,1,0x1b,
             L"QueueWorkItem failure - NvmofiSendQueueNextPacket",0x200,3,9,L"QueueId",
             *(undefined2 *)((longlong)plVar2 + 0x26),L"StorStatus",iVar10,L"",0,L"",0,L"",0,L"",0,
             L"",0,L"",0);
  return iVar9;
}



===== NvmofiTcpInitializeNvme @ 140005250 =====

int NvmofiTcpInitializeNvme(longlong param_1,undefined4 *param_2)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  char local_res8 [8];
  
  lVar4 = *(longlong *)(param_1 + 0x1a4);
  local_res8[0] = '\0';
  uVar3 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    lVar4 = *(longlong *)(param_1 + 0x19c);
  }
  *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) | 2;
  NvmofiInitializeWskSendPacket(lVar4,0,'\0','\0',0,0,'\0');
  memset((void *)(lVar4 + 0x71),0,0x183);
  *(undefined1 *)(lVar4 + 0x70) = 0;
  *(undefined1 *)(lVar4 + 0x72) = 0x80;
  *(undefined4 *)(lVar4 + 0x74) = 0x80;
  *(undefined2 *)(lVar4 + 0x78) = 0;
  *(undefined1 *)(lVar4 + 0x7a) = 0;
  uVar1 = *(ushort *)(*(longlong *)(lVar4 + 0x20) + 0x24);
  *(byte *)(lVar4 + 0x7b) = *(byte *)(lVar4 + 0x7b) & 0xfc;
  *(uint *)(lVar4 + 0x7c) = uVar1 - 1;
  *(undefined4 *)(lVar4 + 500) = 0x80;
  iVar2 = NvmofiBuildWskBuffer(lVar4);
  if (iVar2 < 0) {
    *param_2 = 0xe;
  }
  else {
    iVar2 = NvmofiWskTcpSend(lVar4,local_res8);
    if (local_res8[0] != '\0') {
      uVar3 = NvmofiWskWaitForCompletion(lVar4);
      iVar2 = (int)uVar3;
      NvmofiCleanupWskPacket(lVar4);
      if (iVar2 < 0) {
        *param_2 = 0xf;
      }
      else {
        iVar2 = KeWaitForSingleObject(param_1 + 0x3c,0,0,0,&NvmofiWskTcpSendReceiveTimeout);
        if (iVar2 == 0x102) {
          *param_2 = 0x10;
          iVar2 = -0x3fffff4b;
        }
        else {
          iVar2 = *(int *)(param_1 + 0x54);
          if (iVar2 < 0) {
            *param_2 = 0x11;
          }
          else {
            *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) & 0xfffffffffffffff7;
            KeSetEvent(param_1 + 0x164,0,0);
            KeSetEvent(param_1 + 0x184,0,0);
          }
        }
      }
      goto LAB_1400053c3;
    }
    *param_2 = 0xf;
  }
  NvmofiCleanupWskPacket(lVar4);
LAB_1400053c3:
  *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) & 0xfffffffffffffffd;
  return iVar2;
}



===== NvmofiWskPacketCompletion @ 1400053f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 NvmofiWskPacketCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  bool bVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar2 = *(longlong **)(param_3 + 0x20);
  local_18 = 0;
  bVar8 = false;
  local_28 = 0;
  uStack_20 = 0;
  if (*(code **)(param_3 + 0x60) != (code *)0x0) {
    (**(code **)(param_3 + 0x60))(*(undefined8 *)(param_3 + 0x68));
  }
  if ((*(byte *)(param_3 + 0x28) & 2) == 0) {
    KeAcquireInStackQueuedSpinLock(plVar2 + 0x3f,&local_28);
    *(int *)(plVar2 + 0x40) = (int)plVar2[0x40] + -1;
    plVar1 = plVar2 + 0x3d;
    plVar3 = (longlong *)*plVar1;
    if (((longlong *)plVar3[1] != plVar1) || (lVar4 = *plVar3, *(longlong **)(lVar4 + 8) != plVar3))
    {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar7 = (*pcVar5)();
      return uVar7;
    }
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    plVar3 = (longlong *)*plVar1;
    KeReleaseInStackQueuedSpinLock(&local_28);
    bVar8 = plVar3 != plVar1;
  }
  NvmofiWskPacketPostCompletion(param_3,*(int *)(param_2 + 0x30));
  if (bVar8) {
    iVar6 = NvmofiQueueWorkItem(*(undefined8 *)(*plVar2 + 0x10),NvmofiSendQueueNextPacket,plVar2);
    if (iVar6 != 0) {
      StorPortExtendedFunction
                (0x80,*(undefined8 *)(*plVar2 + 0x10),*(undefined8 *)(*plVar2 + 0xa0),0,1,0x1b,
                 L"QueueWorkItem failure - NvmofiSendQueueNextPacket",0x200,3,0,L"QueueId",
                 *(undefined2 *)((longlong)plVar2 + 0x26),L"StorStatus",iVar6,L"",0,L"",0,L"",0,L"",
                 0,L"",0,L"",0);
    }
  }
  return 0xc0000016;
}



===== NvmofiWskPacketPostCompletion @ 1400055ec =====

void NvmofiWskPacketPostCompletion(longlong param_1,int param_2)

{
  byte *pbVar1;
  ulonglong *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  longlong local_res8;
  
  plVar3 = *(longlong **)(param_1 + 0x20);
  pbVar1 = (byte *)(param_1 + 0x28);
  local_res8 = param_1;
  if ((*pbVar1 & 2) != 0) {
    KeSetEvent(param_1 + 0x48,0,0);
    return;
  }
  if (param_2 < 0) {
    uVar5 = 0x17;
    uVar4 = *(undefined8 *)(*plVar3 + 0x10);
    StorPortExtendedFunction
              (0x80,uVar4,*(undefined8 *)(*plVar3 + 0xa0),0,1,0x17,
               L"WskPacketCompletion send failure",0x200,3,0,L"Queue Id",
               *(undefined2 *)((longlong)plVar3 + 0x26),L"NtStatus",(longlong)param_2,L"",0,L"",0,
               L"",0,L"",0,L"",0,L"",0);
    if (*(longlong *)(param_1 + 0x2c) != 0) {
      LOCK();
      *(short *)((longlong)plVar3 + 0x2e) = *(short *)((longlong)plVar3 + 0x2e) + -1;
      UNLOCK();
      puVar2 = (ulonglong *)(*(longlong *)(*(longlong *)(param_1 + 0x2c) + 0x68) + 8);
      *puVar2 = *puVar2 & 0xfffffffffffffff7;
      if (param_2 < -0x3fffff4a) {
        if (param_2 == -0x3fffff4b) {
          uVar5 = 9;
        }
        else if (param_2 == -0x7ffffffb) {
          uVar5 = 0x12;
        }
        else if (param_2 == -0x7fffffef) {
          uVar5 = 5;
        }
        else if (param_2 == -0x3ffffff0) {
          uVar5 = 0x22;
        }
        else if (param_2 != -0x3fffffde) {
          if (param_2 != -0x3fffff66) {
            if (param_2 != -0x3fffff63) goto LAB_140005820;
            goto LAB_140005755;
          }
          uVar5 = 0x26;
        }
      }
      else if (param_2 == -0x3fffff4a) {
LAB_140005755:
        uVar5 = 0x25;
      }
      else if (param_2 == -0x3fffff40) {
        uVar5 = 8;
      }
      else {
        if (((param_2 == -0x3ffffe7c) || (param_2 == -0x3ffffdf4)) || (param_2 == -0x3ffffdbf))
        goto LAB_140005755;
        if (param_2 == -0x3ffffb8a) {
          uVar5 = 0x18;
        }
        else {
LAB_140005820:
          uVar5 = 4;
        }
      }
      *(undefined1 *)(*(longlong *)(param_1 + 0x2c) + 3) = uVar5;
      StorPortNotification(0,uVar4,*(undefined8 *)(param_1 + 0x2c));
      goto LAB_14000577d;
    }
  }
  else {
LAB_14000577d:
    param_1 = local_res8;
    if (*(longlong *)(local_res8 + 0x2c) != 0) goto LAB_140005799;
  }
  KeSetEvent(param_1 + 0x48,0,0);
LAB_140005799:
  if (((*pbVar1 & 0x40) != 0) || (*(longlong *)(param_1 + 0x2c) != 0)) {
    NvmofiCleanupWskPacket(param_1);
    NvmofiReturnQueuePacket(&local_res8);
  }
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140005874 =====

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
LAB_140005a7d:
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
LAB_14000594f:
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
      if (param_3 == 4) goto LAB_140005a7d;
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
        goto LAB_14000594f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140005b68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_140005c39;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140005c39;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140005c39;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140005c39;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140005c39;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140005c39;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140005c39;
    }
  }
  uVar3 = 0xff;
LAB_140005c39:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140005c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140005d80 =====

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
LAB_140005e33:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140005e61;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140005e33;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140005e61:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140005fec =====

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



===== wil_details_IsEnabledFallback @ 140006050 =====

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



===== NvmofiAdapterControl @ 1400060f0 =====

uint NvmofiAdapterControl(longlong param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar1 = *param_3;
    if (uVar1 != 0) {
      *(undefined1 *)(param_3 + 1) = 1;
    }
    if (1 < uVar1) {
      *(undefined1 *)((longlong)param_3 + 5) = 1;
    }
    if (2 < uVar1) {
      *(undefined1 *)((longlong)param_3 + 6) = 1;
    }
    if (0x14 < uVar1) {
      *(undefined1 *)(param_3 + 6) = 1;
    }
    if (uVar1 < 0x1d) {
      return 0;
    }
    *(undefined1 *)(param_3 + 8) = 1;
    return 0;
  }
  if (param_2 == 1) {
    return 0;
  }
  if (param_2 == 2) {
    return 0;
  }
  if (param_2 != 0x14) {
    if (param_2 == 0x1c) {
      uVar1 = NvmofiAdapterOperation(param_1,(short *)param_3);
      return uVar1 >> 0x1f;
    }
    return 1;
  }
  if (param_3 == (uint *)0x0) {
    return 1;
  }
  if (*param_3 == 1) {
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = ((byte)param_3[1] ^ uVar1) & 1;
  }
  else {
    if (*param_3 != 0) {
      return 0;
    }
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = ((uint)(byte)param_3[1] * 2 ^ uVar1) & 2;
  }
  *(uint *)(param_1 + 0x10) = uVar2 ^ uVar1;
  return 0;
}



===== NvmofiFindAdapter @ 1400061c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
NvmofiFindAdapter(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,longlong param_6)

{
  undefined8 *puVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  *param_1 = param_3;
  param_1[1] = param_2;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeSpinLock(param_1 + 0xb);
  puVar1 = param_1 + 0xc;
  param_1[0xd] = puVar1;
  *puVar1 = puVar1;
  *(undefined4 *)(param_6 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_6 + 0x18) = 0x100000;
  *(undefined4 *)(param_6 + 0x30) = 3;
  *(undefined1 *)(param_6 + 0x51) = 1;
  *(undefined1 *)(param_6 + 0xc4) = 1;
  *(undefined4 *)(param_6 + 0x84) = 0x70;
  *(undefined1 *)(param_6 + 0x93) = 0;
  StorPortExtendedFunction(0x40,param_1);
  uStack_20._0_6_ = CONCAT15(1,(undefined5)uStack_20);
  local_28._0_4_ = CONCAT13(1,(undefined3)local_28);
  StorPortExtendedFunction(0x67,param_1,0x10,&local_28);
  return 1;
}



===== NvmofiFreeAdapterResources @ 1400062a0 =====

void NvmofiFreeAdapterResources(longlong param_1)

{
  NvmofiWskCleanup(param_1,'\x01');
  return;
}



===== NvmofiInitialize @ 1400062c0 =====

undefined1 NvmofiInitialize(undefined8 param_1)

{
  undefined4 local_res10 [6];
  
  local_res10[0] = 0;
  StorPortNotification(0x1000,param_1,NvmofiPassiveInitialize,local_res10);
  return 1;
}



===== NvmofiPassiveInitialize @ 140006300 =====

undefined8 NvmofiPassiveInitialize(longlong *param_1)

{
  int iVar1;
  undefined4 extraout_var;
  ulonglong uVar2;
  undefined4 extraout_var_00;
  undefined1 uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  uVar3 = 1;
  local_38 = 8;
  local_34 = 0x28;
  local_30 = 1;
  local_2c = 1;
  local_28 = 0;
  uStack_20 = 0;
  StorPortExtendedFunction(0xe,param_1,0,&local_38);
  iVar1 = NvmofiWskCommonInitialize((longlong)param_1);
  uVar2 = CONCAT44(extraout_var,iVar1);
  if (-1 < iVar1) {
    uVar2 = NvmofiWskTcpInitialize((longlong)param_1);
    if (-1 < (int)uVar2) {
      iVar1 = NvmofiWskRdmaInitialize(param_1);
      uVar2 = CONCAT44(extraout_var_00,iVar1);
      goto LAB_140006372;
    }
  }
  uVar3 = 0;
LAB_140006372:
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== NvmofiResetBus @ 140006390 =====

undefined1 NvmofiResetBus(void)

{
  return 1;
}



===== NvmofiStartIo @ 1400063a0 =====

undefined8 NvmofiStartIo(undefined8 param_1,short *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_var;
  longlong lVar5;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  short *psVar6;
  int *piVar7;
  uint uVar8;
  code *pcVar9;
  
  if ((((*param_2 == 8) && ((char)param_2[1] == '(')) && (*(int *)(param_2 + 4) == 0x53524258)) &&
     ((*(int *)(param_2 + 6) == 1 && (0x7f < *(uint *)(param_2 + 8))))) {
    *(undefined1 *)((longlong)param_2 + 3) = 0;
    if (*(int *)(param_2 + 10) == 0x2c) {
      if (*(uint *)(param_2 + 0x1c) != 0) {
        uVar8 = 0;
        do {
          uVar2 = *(uint *)(param_2 + (ulonglong)uVar8 * 2 + 0x3c);
          if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 8))) &&
             (piVar7 = (int *)((ulonglong)uVar2 + (longlong)param_2), *piVar7 == 0x44))
          goto LAB_140006439;
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_2 + 0x1c));
      }
      piVar7 = (int *)0x0;
LAB_140006439:
      iVar3 = piVar7[4];
      if (iVar3 == 2) {
        iVar3 = NvmofiAdapterNvmeControllerCreateQueue(param_1,(longlong)param_2);
        psVar6 = (short *)CONCAT44(extraout_var_01,iVar3);
        goto LAB_14000657c;
      }
      if (iVar3 == 3) {
        iVar3 = NvmofiAdapterNvmeControllerDeleteQueue(param_1,(longlong)param_2);
        psVar6 = (short *)CONCAT44(extraout_var_00,iVar3);
        goto LAB_14000657c;
      }
      if (iVar3 != 4) {
        if (iVar3 == 5) {
          psVar6 = *(short **)(param_2 + 0x20);
          if ((*psVar6 == 1) && (psVar6[1] == 0x58)) {
            uVar1 = psVar6[2];
            lVar5 = *(longlong *)(psVar6 + 4);
            if (uVar1 == 0) {
              lVar5 = *(longlong *)(lVar5 + 0xbc);
            }
            else {
              if (*(ushort *)(lVar5 + 0xae) < uVar1) goto LAB_140006552;
              lVar5 = *(longlong *)(lVar5 + 0xc4) + -0x270 + (ulonglong)uVar1 * 0x270;
            }
            psVar6 = (short *)0x0;
            if (lVar5 != 0) {
              pcVar9 = NvmofiDisconnectQueue;
              goto LAB_1400064da;
            }
          }
          goto LAB_140006552;
        }
        if (iVar3 == 6) {
          iVar3 = NvmofiAdapterNvmeControllerReconnectQueueTransport(param_1,(longlong)param_2);
          psVar6 = (short *)CONCAT44(extraout_var,iVar3);
          goto LAB_14000657c;
        }
        *(undefined1 *)((longlong)param_2 + 3) = 6;
        goto LAB_140006588;
      }
      psVar6 = *(short **)(param_2 + 0x20);
      if ((*psVar6 == 1) && (psVar6[1] == 0x58)) {
        uVar1 = psVar6[2];
        lVar5 = *(longlong *)(psVar6 + 4);
        if (uVar1 == 0) {
          lVar5 = *(longlong *)(lVar5 + 0xbc);
        }
        else {
          if (*(ushort *)(lVar5 + 0xae) < uVar1) goto LAB_140006552;
          lVar5 = *(longlong *)(lVar5 + 0xc4) + -0x270 + (ulonglong)uVar1 * 0x270;
        }
        psVar6 = (short *)0x0;
        if (lVar5 == 0) goto LAB_140006552;
        pcVar9 = NvmofiDrainQueue;
LAB_1400064da:
        psVar6 = (short *)NvmofiQueueWorkItem(param_1,pcVar9,param_2);
        iVar3 = (int)psVar6;
        if (iVar3 != 0) {
          *(undefined1 *)((longlong)param_2 + 3) = 0x26;
        }
      }
      else {
LAB_140006552:
        iVar3 = -0x3effffff;
        *(undefined1 *)((longlong)param_2 + 3) = 6;
      }
    }
    else {
      if (*(int *)(param_2 + 10) != 10) goto LAB_140006584;
      uVar4 = NvmofiAdapterNvmeControllerSendCommand(param_1,(longlong)param_2);
      psVar6 = (short *)CONCAT44(extraout_var_02,uVar4);
LAB_14000657c:
      iVar3 = (int)psVar6;
    }
    if (iVar3 == 0) goto LAB_14000659c;
  }
  else {
LAB_140006584:
    *(undefined1 *)((longlong)param_2 + 3) = 6;
  }
LAB_140006588:
  psVar6 = (short *)StorPortNotification(0,param_1,param_2);
LAB_14000659c:
  return CONCAT71((int7)((ulonglong)psVar6 >> 8),1);
}



===== NvmofiWskDefaultConnect @ 1400065c0 =====

undefined8 NvmofiWskDefaultConnect(void)

{
  return 0xc0000002;
}



===== StorNVMeOfDriverUnload @ 1400065d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorNVMeOfDriverUnload(void)

{
  (*StorPortDriverUnload)();
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



===== wil_details_RecordCachedUsage @ 140006634 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140006790 =====

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



===== InitializeRdmaCapsuleCommand @ 140006814 =====

undefined8 InitializeRdmaCapsuleCommand(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong local_res10;
  
  uVar1 = *(uint *)(param_2 + 0x3c);
  local_res10 = 0;
  uVar2 = *(uint *)(**(longlong **)(param_2 + 0x20) + 0xb4);
  KrdmaAllocateFromResourcePool
            (*(longlong *)
              (*(longlong *)(*(longlong *)(**(longlong **)(param_2 + 0x20) + 0x18) + 0x10) + 0xc0) +
             0x140,&local_res10);
  *(longlong *)(param_2 + 0x70) = local_res10;
  if (local_res10 == 0) {
    uVar5 = 0xc000009a;
  }
  else {
    puVar3 = *(uint **)(local_res10 + 8);
    uVar8 = 0x40;
    uVar5 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)puVar3 = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(puVar3 + 2) = uVar5;
    uVar5 = *(undefined8 *)(param_1 + 0x28);
    *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(puVar3 + 6) = uVar5;
    uVar5 = *(undefined8 *)(param_1 + 0x38);
    *(undefined8 *)(puVar3 + 8) = *(undefined8 *)(param_1 + 0x30);
    *(undefined8 *)(puVar3 + 10) = uVar5;
    uVar5 = *(undefined8 *)(param_1 + 0x48);
    *(undefined8 *)(puVar3 + 0xc) = *(undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(puVar3 + 0xe) = uVar5;
    *puVar3 = *puVar3 & 0xffff7fff | 0x4000;
    lVar4 = *(longlong *)(param_2 + 0x70);
    if (lVar4 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(uint *)(lVar4 + 0x14);
    }
    if (((*(byte *)(param_2 + 0x28) & 0x10) == 0) || (uVar7 = uVar1 + 0x40 + uVar2, uVar6 < uVar7))
    {
      *(byte *)(*(longlong *)(lVar4 + 8) + 0x27) =
           *(byte *)(*(longlong *)(lVar4 + 8) + 0x27) & 0xf | 0x40;
    }
    else {
      memmove((void *)((longlong)puVar3 + (ulonglong)uVar2 + 0x40),*(void **)(param_2 + 0x34),
              (ulonglong)uVar1);
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x70) + 8);
      *(undefined1 *)(lVar4 + 0x27) = 1;
      *(ulonglong *)(lVar4 + 0x18) = (ulonglong)*(uint *)(**(longlong **)(param_2 + 0x20) + 0xb4);
      *(undefined4 *)(lVar4 + 0x20) = *(undefined4 *)(param_2 + 0x3c);
      uVar8 = uVar7;
    }
    if (*(longlong *)(param_2 + 0x70) != 0) {
      *(uint *)(*(longlong *)(param_2 + 0x70) + 0x10) = uVar8;
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== _guard_check_icall @ 140006950 =====

void _guard_check_icall(void)

{
  return;
}



===== NvmofiRdmaGetConnectionData @ 14000695c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiRdmaGetConnectionData(longlong *param_1,uint *param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [4];
  undefined4 local_48 [4];
  
  *param_2 = 0;
  *param_3 = 0;
  local_res8[0] = 0;
  iVar4 = (**(code **)(*(longlong *)(param_1[0x19] + 0x28) + 0x38))(param_1[0x19],0,0,0,local_res8);
  if (-1 < iVar4) {
    puVar6 = (undefined4 *)ExAllocatePool2(0x40,local_res8[0],0x6352664e);
    if (puVar6 == (undefined4 *)0x0) {
      iVar4 = -0x3fffff66;
    }
    else {
      iVar4 = (**(code **)(*(longlong *)(param_1[0x19] + 0x28) + 0x38))
                        (param_1[0x19],0,0,puVar6,local_res8);
      if (-1 < iVar4) {
        uVar1 = puVar6[1];
        uVar2 = puVar6[2];
        uVar3 = puVar6[3];
        local_res10[0] = 0;
        local_res18[0] = 0;
        local_48[0] = 0;
        *param_4 = *puVar6;
        param_4[1] = uVar1;
        param_4[2] = uVar2;
        param_4[3] = uVar3;
        uVar1 = puVar6[5];
        uVar2 = puVar6[6];
        uVar3 = puVar6[7];
        param_4[4] = puVar6[4];
        param_4[5] = uVar1;
        param_4[6] = uVar2;
        param_4[7] = uVar3;
        *param_2 = 0;
        *param_3 = 0;
        iVar4 = (**(code **)(*(longlong *)(param_1[0x19] + 0x28) + 0x38))
                          (param_1[0x19],local_res10,local_res18,0,local_48);
        if (-1 < iVar4) {
          uVar5 = local_res10[0];
          if (*(uint *)(*param_1 + 0x60) < local_res10[0]) {
            uVar5 = *(uint *)(*param_1 + 0x60);
          }
          *param_2 = uVar5;
          uVar5 = local_res18[0];
          if (*(uint *)(*param_1 + 100) < local_res18[0]) {
            uVar5 = *(uint *)(*param_1 + 100);
          }
          *param_3 = uVar5;
        }
      }
      ExFreePoolWithTag(puVar6,0x6352664e);
    }
  }
  return iVar4;
}



===== NvmofiRdmaSendCompletionCallback @ 140006ab0 =====

void NvmofiRdmaSendCompletionCallback(int param_1,undefined8 param_2,longlong param_3)

{
  int *piVar1;
  longlong lVar2;
  
  if (*(longlong *)(param_3 + 0x70) != 0) {
    lVar2 = *(longlong *)
             (*(longlong *)(*(longlong *)(**(longlong **)(param_3 + 0x20) + 0x18) + 0x10) + 0xc0);
    ExpInterlockedPushEntrySList(lVar2 + 0x140);
    LOCK();
    piVar1 = (int *)(lVar2 + 0x174);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    *(undefined8 *)(param_3 + 0x70) = 0;
  }
  NvmofiWskRdmaPacketCompletion(param_3,param_1);
  return;
}



===== NvmofiWskRdmaDispatchPacket @ 140006b24 =====

int NvmofiWskRdmaDispatchPacket(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  plVar2 = *(longlong **)(param_1 + 0x20);
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(*plVar2 + 0x18) + 0x10) + 0xc0);
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x2c) + 0x68);
  if (*(longlong *)(param_1 + 0x40) != 0) {
    iVar8 = KrdmaSocketFastRegisterMDL
                      (*(longlong **)plVar2[2],*(longlong *)(param_1 + 0x40),
                       *(uint *)(param_1 + 0x3c),(byte)(*(uint *)(param_1 + 0x28) >> 3) & 1,
                       in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                       (undefined8 *)(lVar4 + 0x20),in_stack_ffffffffffffffe0,param_1);
    if (iVar8 < 0) goto LAB_140006bfc;
    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x2c) + 0x68);
    plVar6 = *(longlong **)(lVar5 + 0x20);
    if (plVar6 == (longlong *)0x0) {
      iVar8 = -0x3ffffff3;
      goto LAB_140006bfc;
    }
    uVar1 = *(uint *)(*plVar6 + 0x2c);
    param_3 = (ulonglong)uVar1;
    lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x70) + 8);
    *(undefined1 *)(lVar7 + 0x27) = 0x4f;
    plVar6 = *(longlong **)(lVar5 + 0x20);
    uVar9 = 0;
    if (plVar6 != (longlong *)0x0) {
      uVar9 = *(undefined8 *)(*plVar6 + 0x20);
    }
    *(undefined8 *)(lVar7 + 0x18) = uVar9;
    *(undefined2 *)(lVar7 + 0x20) = *(undefined2 *)(param_1 + 0x3c);
    *(undefined1 *)(lVar7 + 0x22) = *(undefined1 *)(param_1 + 0x3e);
    *(uint *)(lVar7 + 0x23) = uVar1;
  }
  iVar8 = KrdmaSocketSendLAMBuffer
                    (*(longlong *)plVar2[2],*(longlong *)(param_1 + 0x70),param_3,param_1);
  if (-1 < iVar8) {
    return iVar8;
  }
LAB_140006bfc:
  if (*(longlong **)(lVar4 + 0x20) != (longlong *)0x0) {
    KrdmaFreeBufferRegistration(lVar3,*(longlong **)(lVar4 + 0x20));
    *(undefined8 *)(lVar4 + 0x20) = 0;
  }
  if (*(longlong *)(param_1 + 0x70) != 0) {
    ExpInterlockedPushEntrySList(lVar3 + 0x140);
    LOCK();
    *(int *)(lVar3 + 0x174) = *(int *)(lVar3 + 0x174) + -1;
    UNLOCK();
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  return iVar8;
}



===== InitializeH2CData @ 140006c68 =====

void InitializeH2CData(longlong param_1,undefined2 param_2,undefined2 param_3,char param_4,
                      undefined4 param_5)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  memset((void *)(param_1 + 0x71),0,0x183);
  *(undefined1 *)(param_1 + 0x70) = 6;
  bVar5 = (*(byte *)(lVar1 + 8) >> 4 ^ *(byte *)(param_1 + 0x71)) & 1 ^ *(byte *)(param_1 + 0x71);
  *(byte *)(param_1 + 0x71) = bVar5;
  bVar2 = *(byte *)(lVar1 + 8);
  *(undefined1 *)(param_1 + 0x72) = 0x18;
  bVar2 = ((bVar2 >> 4 ^ bVar5) & 2 ^ bVar5) & 0xfb | -(param_4 != '\0') & 4U;
  *(byte *)(param_1 + 0x71) = bVar2;
  uVar3 = *(ushort *)(lVar1 + 0x2a) + 0x17 + (bVar2 & 1) * 4 & -(uint)*(ushort *)(lVar1 + 0x2a);
  *(char *)(param_1 + 0x73) = (char)uVar3;
  *(uint *)(param_1 + 500) = uVar3;
  iVar4 = uVar3 + *(int *)(param_1 + 0x3c);
  bVar2 = *(byte *)(param_1 + 0x71) & 2;
  if (bVar2 != 0) {
    iVar4 = iVar4 + 4;
  }
  uVar3 = *(uint *)(param_1 + 0x28) | 0x20;
  if (bVar2 == 0) {
    uVar3 = *(uint *)(param_1 + 0x28) & 0xffffffdf;
  }
  *(uint *)(param_1 + 0x28) = uVar3;
  *(undefined2 *)(param_1 + 0x7a) = param_3;
  *(int *)(param_1 + 0x74) = iVar4;
  *(undefined2 *)(param_1 + 0x78) = param_2;
  *(undefined4 *)(param_1 + 0x7c) = param_5;
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x3c);
  return;
}



===== InitializeH2CTermReq @ 140006d64 =====

void InitializeH2CTermReq
               (longlong param_1,undefined2 param_2,undefined4 param_3,byte param_4,void *param_5)

{
  uint uVar1;
  
  memset((void *)(param_1 + 0x71),0,0x183);
  *(undefined1 *)(param_1 + 0x70) = 2;
  *(uint *)(param_1 + 0x74) = param_4 + 0x18;
  *(undefined1 *)(param_1 + 0x72) = 0x18;
  *(undefined2 *)(param_1 + 0x78) = param_2;
  *(undefined4 *)(param_1 + 0x7a) = param_3;
  if (param_4 != 0) {
    uVar1 = 0x80;
    if (param_4 < 0x80) {
      uVar1 = (uint)param_4;
    }
    memmove((void *)(param_1 + 0x88),param_5,(ulonglong)uVar1);
  }
  return;
}



===== InitializeTcpCapsuleCommand @ 140006dec =====

void InitializeTcpCapsuleCommand(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  
  lVar2 = *(longlong *)(param_2 + 0x20);
  memset((void *)(param_2 + 0x71),0,0x183);
  *(undefined1 *)(param_2 + 0x70) = 4;
  bVar4 = (*(byte *)(lVar2 + 8) >> 4 ^ *(byte *)(param_2 + 0x71)) & 1 ^ *(byte *)(param_2 + 0x71);
  *(byte *)(param_2 + 0x71) = bVar4;
  if (((*(byte *)(param_2 + 0x28) & 0x10) == 0) || (bVar5 = 2, (*(byte *)(lVar2 + 8) & 0x20) == 0))
  {
    bVar5 = 0;
  }
  *(undefined1 *)(param_2 + 0x72) = 0x48;
  bVar5 = bVar4 & 0xfd | bVar5;
  *(byte *)(param_2 + 0x71) = bVar5;
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_2 + 0x80) = uVar3;
  iVar7 = (bVar5 & 1) * 4;
  iVar1 = iVar7 + 0x48;
  uVar3 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(param_2 + 0x88) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(param_2 + 0x90) = uVar3;
  uVar3 = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(param_2 + 0xa0) = uVar3;
  uVar3 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(param_2 + 0xa8) = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(param_2 + 0xb0) = uVar3;
  if ((*(uint *)(param_2 + 0x28) & 4) == 0) {
    *(undefined1 *)(param_2 + 0x73) = 0;
    *(int *)(param_2 + 0x74) = iVar1;
    *(int *)(param_2 + 500) = iVar1;
  }
  else {
    if ((*(uint *)(param_2 + 0x28) & 0x10) == 0) {
      *(undefined1 *)(param_2 + 0x73) = 0;
      *(int *)(param_2 + 0x74) = iVar1;
      *(int *)(param_2 + 500) = iVar1;
      *(undefined1 *)(param_2 + 0x9f) = 0x5a;
    }
    else {
      uVar6 = iVar7 + 0x47 + (uint)*(ushort *)(lVar2 + 0x2a) & -(uint)*(ushort *)(lVar2 + 0x2a);
      *(char *)(param_2 + 0x73) = (char)uVar6;
      *(uint *)(param_2 + 500) = uVar6;
      iVar7 = uVar6 + *(int *)(param_2 + 0x3c);
      bVar4 = *(byte *)(param_2 + 0x71) & 2;
      if (bVar4 != 0) {
        iVar7 = iVar7 + 4;
      }
      uVar6 = *(uint *)(param_2 + 0x28) | 0x20;
      if (bVar4 == 0) {
        uVar6 = *(uint *)(param_2 + 0x28) & 0xffffffdf;
      }
      *(uint *)(param_2 + 0x28) = uVar6;
      *(int *)(param_2 + 0x74) = iVar7;
      *(undefined1 *)(param_2 + 0x9f) = 1;
      *(undefined8 *)(param_2 + 0x90) = 0;
    }
    *(undefined4 *)(param_2 + 0x98) = *(undefined4 *)(param_2 + 0x3c);
  }
  *(uint *)(param_2 + 0x78) = *(uint *)(param_2 + 0x78) & 0xffff7fff | 0x4000;
  return;
}



===== IsHeaderValid @ 140006f30 =====

undefined8 IsHeaderValid(ushort param_1,char *param_2,char param_3,char param_4,undefined2 *param_5)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  
  uVar6 = 0;
  uVar5 = (ulonglong)param_1;
  cVar1 = *param_2;
  *param_5 = 0;
  if (cVar1 == '\x01') {
    if (param_1 < 0x80) goto LAB_140007179;
    if (param_2[1] != '\0') goto LAB_140006f73;
    if (param_2[2] != -0x80) goto LAB_140006f82;
    if (param_2[3] != '\0') {
      *param_5 = 3;
      goto LAB_140007179;
    }
    if (*(int *)(param_2 + 4) == 0x80) {
      if (*(short *)(param_2 + 8) != 0) {
        *param_5 = 8;
        goto LAB_140007179;
      }
      if (0x1f < (byte)param_2[10]) {
        *param_5 = 10;
        goto LAB_140007179;
      }
      goto LAB_140007014;
    }
LAB_140006fa4:
    *param_5 = 4;
    goto LAB_140007179;
  }
  if (cVar1 == '\x03') {
    if (param_1 < 0x18) goto LAB_140007179;
    if (param_2[1] != '\0') goto LAB_140006f73;
    if (param_2[2] != '\x18') goto LAB_140006f82;
    if (param_2[3] == '\0') {
      uVar5 = (ulonglong)(*(int *)(param_2 + 4) - 0x18U);
      if (0x80 < *(int *)(param_2 + 4) - 0x18U) goto LAB_140006fa4;
LAB_140007014:
      uVar6 = 1;
      goto LAB_140007179;
    }
LAB_140006ffb:
    *param_5 = 3;
    goto LAB_140007179;
  }
  uVar3 = (undefined1)(param_1 >> 8);
  if (cVar1 == '\x05') {
    if (param_1 < 0x18) goto LAB_140007179;
    if (param_2[2] != '\x18') goto LAB_140006f82;
    bVar4 = param_2[1] & 1;
    uVar5 = (ulonglong)CONCAT11(uVar3,param_2[1]) & 0xffffffffffffff01;
    if (param_3 == '\0') {
      if (bVar4 == 0) goto LAB_140007054;
    }
    else if (bVar4 != 0) {
LAB_140007054:
      if (param_2[3] != '\0') goto LAB_140006ffb;
      uVar5 = (ulonglong)(*(int *)(param_2 + 4) - 0x18U);
      if (*(int *)(param_2 + 4) - 0x18U < 5) goto LAB_140007014;
      goto LAB_140007175;
    }
LAB_140006f73:
    *param_5 = 1;
  }
  else {
    if (cVar1 == '\a') {
      if (param_1 < 0x18) goto LAB_140007179;
      if (param_2[2] != '\x18') goto LAB_140006f82;
      bVar4 = param_2[1];
      uVar5 = (ulonglong)CONCAT11(uVar3,bVar4) & 0xffffffffffffff01;
      if (param_3 == '\0') {
        if ((bVar4 & 1) == 0) goto LAB_1400070ae;
      }
      else if ((bVar4 & 1) != 0) {
LAB_1400070ae:
        uVar5 = 0;
        if (param_4 == '\0') {
          if ((bVar4 & 2) == 0) goto LAB_1400070cf;
        }
        else if ((bVar4 & 2) != 0) {
LAB_1400070cf:
          bVar2 = param_2[3];
          if (((bVar2 < 0x18) || ((bVar2 & 3) != 0)) || (((bVar4 & 1) != 0 && (bVar2 < 0x1c))))
          goto LAB_140006ffb;
          if ((*(uint *)(param_2 + 4) < (uint)bVar2) ||
             (((bVar4 & 2) != 0 &&
              (uVar5 = (ulonglong)(bVar2 + 4), *(uint *)(param_2 + 4) < bVar2 + 4))))
          goto LAB_140006fa4;
          if (((bVar4 & 4) != 0) || (uVar5 = 0, (bVar4 & 8) == 0)) goto LAB_140007125;
        }
      }
      goto LAB_140006f73;
    }
    if ((cVar1 != '\t') || (param_1 < 0x18)) goto LAB_140007179;
    if (param_2[2] != '\x18') {
LAB_140006f82:
      *param_5 = 2;
      goto LAB_140007179;
    }
    if (param_2[3] != '\0') goto LAB_140006ffb;
    uVar5 = (ulonglong)(*(int *)(param_2 + 4) - 0x18U);
    if (*(int *)(param_2 + 4) - 0x18U < 5) {
LAB_140007125:
      if ((param_2[0xc] & 3U) != 0) {
        *param_5 = 0xc;
        goto LAB_140007179;
      }
      if ((param_2[0x10] & 3U) != 0) {
        *param_5 = 0x10;
        goto LAB_140007179;
      }
      goto LAB_140007014;
    }
LAB_140007175:
    *param_5 = 4;
  }
LAB_140007179:
  return CONCAT71((int7)(uVar5 >> 8),uVar6);
}



===== NvmofiAdapterAddNvmeController @ 140007194 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NvmofiAdapterAddNvmeController(longlong param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [24];
  uint local_b8 [2];
  undefined8 local_b0;
  undefined1 *puStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined1 local_78 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar1 = *(longlong *)(param_2 + 8);
  uVar8 = 0;
  local_80 = 0;
  local_90 = 0;
  uStack_88 = 0;
  plVar4 = (longlong *)ExAllocatePool2(0x40,0xcc,0x7243664e);
  puVar9 = auStack_d8;
  if (plVar4 == (longlong *)0x0) {
    iVar3 = -0x3fffffe9;
    uVar8 = 6;
  }
  else {
    plVar4[2] = param_1;
    plVar4[3] = lVar1;
    plVar4[0x14] = *(longlong *)(param_2 + 0x10);
    uVar7 = *(uint *)(lVar1 + 0x38);
    *(undefined4 *)(plVar4 + 0x16) = 0;
    local_b8[0] = 0;
    *(uint *)(plVar4 + 0x15) = (~uVar7 & 1) + 1;
    local_a0 = 0;
    uStack_98 = 0;
    local_b0 = 0;
    puStack_a8 = (undefined1 *)0x0;
    RtlInitAnsiString(&local_a0,param_2 + 0x34);
    puStack_a8 = local_78;
    local_b0._0_4_ = CONCAT22(0x40,(undefined2)local_b0);
    RtlAnsiStringToUnicodeString(&local_b0,&local_a0,0);
    iVar3 = RtlUnicodeStringToInteger(&local_b0,0,local_b8);
    puVar9 = auStack_d8;
    uVar7 = local_b8[0];
    if ((-1 < iVar3) && (0xffff < local_b8[0])) {
      uVar7 = 0;
    }
    if ((ushort)uVar7 == 0) {
      iVar3 = -0x3ffffff3;
      uVar8 = 1;
    }
    else {
      iVar3 = NvmofiWskInitializeSockAddr(lVar1 + 0x13e,(ushort)uVar7,(undefined2 *)(plVar4 + 4));
      puVar9 = auStack_d8;
      if (iVar3 < 0) {
        uVar8 = 3;
      }
      else {
        *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 1;
        *(undefined4 *)(param_2 + 0x22) = 0;
        *(undefined2 *)(param_2 + 0x26) = 0;
        *(undefined8 *)(param_2 + 0x2c) = 0;
        plVar5 = (longlong *)ExAllocatePool2(0x40,0x270,0x7143664e);
        puVar9 = auStack_d8;
        *(longlong **)((longlong)plVar4 + 0xbc) = plVar5;
        if (plVar5 == (longlong *)0x0) {
          iVar3 = -0x3fffffe9;
          uVar8 = 7;
        }
        else {
          *plVar5 = (longlong)plVar4;
          iVar3 = 0;
          *(undefined4 *)(*(longlong *)((longlong)plVar4 + 0xbc) + 0x20) = 0;
          *(undefined2 *)(*(longlong *)((longlong)plVar4 + 0xbc) + 0x26) = 0;
          *(undefined4 *)(plVar4 + 0x17) = *(undefined4 *)(param_2 + 0x28);
          KeAcquireInStackQueuedSpinLock(lVar1 + 0x20,&local_90);
          puVar9 = auStack_d8;
          lVar6 = lVar1 + 0x28;
          plVar5 = *(longlong **)(lVar1 + 0x30);
          if (*plVar5 != lVar6) {
            plVar5 = (longlong *)0x3;
            pcVar2 = (code *)swi(0x29);
            lVar6 = (*pcVar2)();
            puVar9 = auStack_d0;
          }
          plVar4[1] = (longlong)plVar5;
          *plVar4 = lVar6;
          *plVar5 = (longlong)plVar4;
          *(longlong **)(lVar6 + 8) = plVar4;
          *(undefined8 *)(puVar9 + -8) = 0x140007381;
          KeReleaseInStackQueuedSpinLock(&local_90);
          *(longlong **)(param_2 + 0x18) = plVar4;
        }
      }
    }
  }
  *(undefined4 *)(param_2 + 0x54) = uVar8;
  *(undefined8 *)(puVar9 + -8) = 0x14000739c;
  return iVar3;
}



===== NvmofiAdapterAddSubsystemPort @ 1400073c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NvmofiAdapterAddSubsystemPort(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  char *pcVar2;
  longlong lVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int iVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  undefined4 uVar16;
  longlong lVar17;
  char *pcVar18;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [24];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  short local_b8 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(local_b8,0,0x80);
  puVar15 = auStack_f8;
  lVar3 = *(longlong *)(param_2 + 8);
  pcVar18 = (char *)(param_2 + 0x124);
  uVar16 = 0;
  local_c8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  if ((*pcVar18 == '\0') || (*(char *)(param_2 + 0x224) == '\0')) {
    iVar9 = -0x3ffffff3;
    uVar16 = 1;
  }
  else {
    iVar9 = NvmofiWskInitializeSockAddr(pcVar18,0,local_b8);
    puVar15 = auStack_f8;
    if (iVar9 < 0) {
      uVar16 = 3;
      puVar15 = auStack_f8;
    }
    else if (local_b8[0] == *(short *)(lVar3 + 0x38)) {
      plVar10 = (longlong *)ExAllocatePool2(0x40,0x260,0x7450664e);
      puVar15 = auStack_f8;
      if (plVar10 == (longlong *)0x0) {
        iVar9 = -0x3fffffe9;
        uVar16 = 2;
      }
      else {
        KeInitializeSpinLock(plVar10 + 4);
        plVar14 = plVar10 + 5;
        plVar10[2] = lVar3;
        plVar10[6] = (longlong)plVar14;
        *plVar14 = (longlong)plVar14;
        plVar10[3] = *(longlong *)(param_2 + 0x10);
        if ((*(uint *)(param_2 + 4) & 1) != 0) {
          *(uint *)(plVar10 + 7) = *(uint *)(plVar10 + 7) | 1;
        }
        puVar12 = (undefined8 *)(param_2 + 0x24);
        lVar13 = 2;
        *(undefined2 *)((longlong)plVar10 + 0x3c) = *(undefined2 *)(param_2 + 0x20);
        lVar17 = 2;
        puVar11 = (undefined8 *)((longlong)plVar10 + 0x3e);
        do {
          uVar8 = puVar12[1];
          *puVar11 = *puVar12;
          puVar11[1] = uVar8;
          uVar8 = puVar12[3];
          puVar11[2] = puVar12[2];
          puVar11[3] = uVar8;
          uVar8 = puVar12[5];
          puVar11[4] = puVar12[4];
          puVar11[5] = uVar8;
          uVar8 = puVar12[7];
          puVar11[6] = puVar12[6];
          puVar11[7] = uVar8;
          uVar8 = puVar12[9];
          puVar11[8] = puVar12[8];
          puVar11[9] = uVar8;
          uVar8 = puVar12[0xb];
          puVar11[10] = puVar12[10];
          puVar11[0xb] = uVar8;
          uVar8 = puVar12[0xd];
          puVar11[0xc] = puVar12[0xc];
          puVar11[0xd] = uVar8;
          puVar1 = puVar12 + 0xe;
          uVar8 = puVar12[0xf];
          puVar12 = puVar12 + 0x10;
          puVar11[0xe] = *puVar1;
          puVar11[0xf] = uVar8;
          lVar17 = lVar17 + -1;
          puVar11 = puVar11 + 0x10;
        } while (lVar17 != 0);
        puVar12 = (undefined8 *)((longlong)plVar10 + 0x13e);
        do {
          uVar8 = *(undefined8 *)(pcVar18 + 8);
          *puVar12 = *(undefined8 *)pcVar18;
          puVar12[1] = uVar8;
          uVar8 = *(undefined8 *)(pcVar18 + 0x18);
          puVar12[2] = *(undefined8 *)(pcVar18 + 0x10);
          puVar12[3] = uVar8;
          uVar8 = *(undefined8 *)(pcVar18 + 0x28);
          puVar12[4] = *(undefined8 *)(pcVar18 + 0x20);
          puVar12[5] = uVar8;
          uVar8 = *(undefined8 *)(pcVar18 + 0x38);
          puVar12[6] = *(undefined8 *)(pcVar18 + 0x30);
          puVar12[7] = uVar8;
          uVar8 = *(undefined8 *)(pcVar18 + 0x48);
          puVar12[8] = *(undefined8 *)(pcVar18 + 0x40);
          puVar12[9] = uVar8;
          uVar8 = *(undefined8 *)(pcVar18 + 0x58);
          puVar12[10] = *(undefined8 *)(pcVar18 + 0x50);
          puVar12[0xb] = uVar8;
          uVar8 = *(undefined8 *)(pcVar18 + 0x68);
          puVar12[0xc] = *(undefined8 *)(pcVar18 + 0x60);
          puVar12[0xd] = uVar8;
          pcVar2 = pcVar18 + 0x70;
          uVar8 = *(undefined8 *)(pcVar18 + 0x78);
          pcVar18 = pcVar18 + 0x80;
          puVar12[0xe] = *(undefined8 *)pcVar2;
          puVar12[0xf] = uVar8;
          lVar13 = lVar13 + -1;
          puVar12 = puVar12 + 0x10;
        } while (lVar13 != 0);
        uVar5 = *(undefined4 *)(param_2 + 0x228);
        uVar6 = *(undefined4 *)(param_2 + 0x22c);
        uVar7 = *(undefined4 *)(param_2 + 0x230);
        *(undefined4 *)((longlong)plVar10 + 0x23e) = *(undefined4 *)(param_2 + 0x224);
        *(undefined4 *)((longlong)plVar10 + 0x242) = uVar5;
        *(undefined4 *)((longlong)plVar10 + 0x246) = uVar6;
        *(undefined4 *)((longlong)plVar10 + 0x24a) = uVar7;
        uVar5 = *(undefined4 *)(param_2 + 0x238);
        uVar6 = *(undefined4 *)(param_2 + 0x23c);
        uVar7 = *(undefined4 *)(param_2 + 0x240);
        *(undefined4 *)((longlong)plVar10 + 0x24e) = *(undefined4 *)(param_2 + 0x234);
        *(undefined4 *)((longlong)plVar10 + 0x252) = uVar5;
        *(undefined4 *)((longlong)plVar10 + 0x256) = uVar6;
        *(undefined4 *)((longlong)plVar10 + 0x25a) = uVar7;
        KeAcquireInStackQueuedSpinLock(lVar3 + 0xe0,&local_d8);
        puVar15 = auStack_f8;
        lVar13 = lVar3 + 0xe8;
        plVar14 = *(longlong **)(lVar3 + 0xf0);
        if (*plVar14 != lVar13) {
          plVar14 = (longlong *)0x3;
          pcVar4 = (code *)swi(0x29);
          lVar13 = (*pcVar4)();
          puVar15 = auStack_f0;
        }
        plVar10[1] = (longlong)plVar14;
        *plVar10 = lVar13;
        *plVar14 = (longlong)plVar10;
        *(longlong **)(lVar13 + 8) = plVar10;
        *(undefined8 *)(puVar15 + -8) = 0x1400075f2;
        KeReleaseInStackQueuedSpinLock(puVar15 + 0x20);
        *(longlong **)(param_2 + 0x18) = plVar10;
      }
    }
    else {
      iVar9 = -0x3fffff45;
      uVar16 = 4;
    }
  }
  *(undefined4 *)(param_2 + 0x244) = uVar16;
  *(undefined8 *)(puVar15 + -8) = 0x14000761f;
  return iVar9;
}



===== NvmofiAdapterNvmeControllerCreateQueue @ 140007644 =====

int NvmofiAdapterNvmeControllerCreateQueue(undefined8 param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  longlong *plVar6;
  short *psVar7;
  
  iVar4 = -0x3effffff;
  if (*(char *)(param_2 + 2) == '(') {
    psVar7 = *(short **)(param_2 + 0x40);
  }
  else {
    psVar7 = *(short **)(param_2 + 0x18);
  }
  if ((*psVar7 == 1) && (psVar7[1] == 0x80)) {
    uVar1 = psVar7[2];
    lVar2 = *(longlong *)(psVar7 + 4);
    if (uVar1 == 0) {
      plVar6 = *(longlong **)(lVar2 + 0xbc);
    }
    else {
      if (*(ushort *)(lVar2 + 0xae) < uVar1) goto LAB_140007743;
      plVar6 = (longlong *)(*(longlong *)(lVar2 + 0xc4) + -0x270 + (ulonglong)uVar1 * 0x270);
    }
    if ((plVar6 != (longlong *)0x0) && ((int)plVar6[4] == 0)) {
      uVar5 = NvmofiPrepareQueue(plVar6);
      if (-1 < (int)uVar5) {
        if (**(int **)(*(longlong *)(lVar2 + 0x18) + 0x10) == 1) {
          lVar3 = *(longlong *)(psVar7 + 0x10);
          plVar6[0x48] = *(longlong *)(psVar7 + 0xc);
          plVar6[0x49] = lVar3;
          lVar3 = *(longlong *)(psVar7 + 0x18);
          plVar6[0x4a] = *(longlong *)(psVar7 + 0x14);
          plVar6[0x4b] = lVar3;
          iVar4 = NvmofiQueueWorkItemToNode
                            (param_1,NvmofiCreateQueue,param_2,*(undefined4 *)(lVar2 + 0xb8));
        }
        else {
          iVar4 = NvmofiQueueWorkItem(param_1,NvmofiCreateQueue,param_2);
        }
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 3) = 0x26;
      return iVar4;
    }
  }
LAB_140007743:
  *(undefined1 *)(param_2 + 3) = 6;
  return -0x3effffff;
}



===== NvmofiAdapterNvmeControllerDeleteQueue @ 140007770 =====

int NvmofiAdapterNvmeControllerDeleteQueue(undefined8 param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  short *psVar3;
  longlong lVar4;
  
  if (*(char *)(param_2 + 2) == '(') {
    psVar3 = *(short **)(param_2 + 0x40);
  }
  else {
    psVar3 = *(short **)(param_2 + 0x18);
  }
  if ((*psVar3 != 1) || (psVar3[1] != 0x58)) {
    *(undefined1 *)(param_2 + 3) = 6;
    return -0x3effffff;
  }
  uVar1 = psVar3[2];
  lVar4 = *(longlong *)(psVar3 + 4);
  if (uVar1 == 0) {
    lVar4 = *(longlong *)(lVar4 + 0xbc);
  }
  else {
    if (*(ushort *)(lVar4 + 0xae) < uVar1) goto LAB_140007806;
    lVar4 = *(longlong *)(lVar4 + 0xc4) + -0x270 + (ulonglong)uVar1 * 0x270;
  }
  if ((lVar4 != 0) && ((*(uint *)(lVar4 + 0x20) & 0xfffffffd) == 0)) {
    iVar2 = NvmofiQueueWorkItem(param_1,NvmofiDeleteQueue,param_2);
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined1 *)(param_2 + 3) = 0x26;
    return iVar2;
  }
LAB_140007806:
  *(undefined1 *)(param_2 + 3) = 6;
  return -0x3effffff;
}



===== NvmofiAdapterNvmeControllerReconnectQueueTransport @ 140007828 =====

int NvmofiAdapterNvmeControllerReconnectQueueTransport(undefined8 param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  short *psVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  iVar3 = -0x3effffff;
  if (*(char *)(param_2 + 2) == '(') {
    psVar4 = *(short **)(param_2 + 0x40);
  }
  else {
    psVar4 = *(short **)(param_2 + 0x18);
  }
  if ((*psVar4 == 1) && (psVar4[1] == 0x58)) {
    uVar1 = psVar4[2];
    lVar2 = *(longlong *)(psVar4 + 4);
    if (uVar1 == 0) {
      plVar6 = *(longlong **)(lVar2 + 0xbc);
    }
    else {
      if (*(ushort *)(lVar2 + 0xae) < uVar1) goto LAB_1400078fc;
      plVar6 = (longlong *)((ulonglong)uVar1 * 0x270 + -0x270 + *(longlong *)(lVar2 + 0xc4));
    }
    if ((plVar6 != (longlong *)0x0) && ((int)plVar6[4] == 0)) {
      uVar5 = NvmofiPrepareQueue(plVar6);
      if (-1 < (int)uVar5) {
        if (**(int **)(*(longlong *)(lVar2 + 0x18) + 0x10) == 1) {
          iVar3 = NvmofiQueueWorkItemToNode
                            (param_1,NvmofiReconnectQueue,param_2,*(undefined4 *)(lVar2 + 0xb8));
        }
        else {
          iVar3 = NvmofiQueueWorkItem(param_1,NvmofiReconnectQueue,param_2);
        }
        if (iVar3 == 0) {
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 3) = 0x26;
      return iVar3;
    }
  }
LAB_1400078fc:
  *(undefined1 *)(param_2 + 3) = 6;
  return -0x3effffff;
}



===== NvmofiAdapterNvmeControllerSendCommand @ 140007924 =====

undefined4 NvmofiAdapterNvmeControllerSendCommand(undefined8 param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  int *piVar4;
  ulonglong uVar5;
  longlong *plVar6;
  undefined4 uVar7;
  uint uVar8;
  
  plVar6 = (longlong *)0x0;
  uVar7 = 0xc1000001;
  if ((*(char *)(param_2 + 2) == '(') && (*(uint *)(param_2 + 0x38) != 0)) {
    uVar8 = 0;
    do {
      uVar2 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar8 * 4);
      if (((0x7f < uVar2) && (uVar2 < *(uint *)(param_2 + 0x10))) &&
         (piVar4 = (int *)(param_2 + (ulonglong)uVar2), *piVar4 == 0x43)) goto LAB_140007988;
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_2 + 0x38));
  }
  piVar4 = (int *)0x0;
LAB_140007988:
  uVar1 = *(ushort *)((longlong)piVar4 + 0x6a);
  lVar3 = *(longlong *)(piVar4 + 2);
  if (uVar1 == 0) {
    plVar6 = *(longlong **)(lVar3 + 0xbc);
  }
  else if (uVar1 <= *(ushort *)(lVar3 + 0xae)) {
    plVar6 = (longlong *)(*(longlong *)(lVar3 + 0xc4) + -0x270 + (ulonglong)uVar1 * 0x270);
  }
  if (plVar6 == (longlong *)0x0) {
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else if ((int)plVar6[4] == 2) {
    *(undefined1 *)(param_2 + 3) = 0;
    uVar5 = NvmofiProcessQueueCommand(plVar6,param_2);
    if ((int)uVar5 < 0) {
      StorPortExtendedFunction
                (0x80,param_1,*(undefined8 *)(lVar3 + 0xa0),0,1,0,L"Process queue command failure",
                 0x200,3,9,L"Queue Id",*(undefined2 *)((longlong)plVar6 + 0x26),L"NtStatus",
                 (longlong)(int)uVar5,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
    }
    else {
      uVar7 = 0;
    }
  }
  else {
    *(undefined1 *)(param_2 + 3) = 0x25;
  }
  return uVar7;
}



===== NvmofiAdapterOperation @ 140007af4 =====

uint NvmofiAdapterOperation(longlong param_1,short *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  if (*param_2 != 1) {
    return 0xc000000d;
  }
  if ((ushort)param_2[1] < 0xc) {
    return 0xc000000d;
  }
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 1) {
    if (param_2[6] != 0x288) {
      return 0xc000000d;
    }
    uVar2 = NvmofiAdapterAddSubsystemPort(param_1,(longlong)(param_2 + 7));
  }
  else if (iVar1 == 2) {
    if (param_2[6] != 0x58) {
      return 0xc000000d;
    }
    uVar4 = NvmofiAdapterRemoveSubsystemPort(param_1,(longlong)(param_2 + 7));
    uVar2 = (uint)uVar4;
  }
  else if (iVar1 == 3) {
    if (param_2[6] != 0x98) {
      return 0xc000000d;
    }
    uVar2 = NvmofiAdapterAddNvmeController(param_1,(longlong)(param_2 + 7));
  }
  else if (iVar1 == 4) {
    if (param_2[6] != 0x58) {
      return 0xc000000d;
    }
    uVar3 = NvmofiAdapterRemoveNvmeController(param_1,(longlong)(param_2 + 7));
    uVar2 = (uint)uVar3;
  }
  else {
    if (iVar1 != 5) {
      return 0xc00000bb;
    }
    if (param_2[6] != 0x68) {
      return 0xc000000d;
    }
    uVar2 = NvmofiAdapterUpdateNvmeController(param_1,(longlong)(param_2 + 7));
  }
  return uVar2;
}



===== NvmofiAdapterRemoveNvmeController @ 140007bb0 =====

undefined8 NvmofiAdapterRemoveNvmeController(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  ushort uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar1 = *(longlong **)(param_2 + 8);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(plVar1[3] + 0x20,&local_28);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    uVar5 = (*pcVar4)();
    return uVar5;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (*(longlong *)((longlong)plVar1 + 0xc4) != 0) {
    uVar6 = 0;
    if (*(short *)((longlong)plVar1 + 0xae) != 0) {
      do {
        NvmofiCleanupQueue((ulonglong)uVar6 * 0x270 + *(longlong *)((longlong)plVar1 + 0xc4));
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ushort *)((longlong)plVar1 + 0xae));
    }
    ExFreePoolWithTag(*(undefined8 *)((longlong)plVar1 + 0xc4),0);
    *(undefined8 *)((longlong)plVar1 + 0xc4) = 0;
    *(undefined2 *)((longlong)plVar1 + 0xae) = 0;
  }
  if (*(longlong *)((longlong)plVar1 + 0xbc) != 0) {
    NvmofiCleanupQueue(*(longlong *)((longlong)plVar1 + 0xbc));
    ExFreePoolWithTag(*(undefined8 *)((longlong)plVar1 + 0xbc),0);
    *(undefined8 *)((longlong)plVar1 + 0xbc) = 0;
  }
  ExFreePoolWithTag(plVar1,0);
  *(undefined4 *)(param_2 + 0x10) = 0;
  return 0;
}



===== NvmofiAdapterRemoveSubsystemPort @ 140007ce8 =====

ulonglong NvmofiAdapterRemoveSubsystemPort(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar1 = *(longlong **)(param_2 + 8);
  uVar7 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar6 = 0;
  if ((longlong *)plVar1[5] == plVar1 + 5) {
    KeAcquireInStackQueuedSpinLock(plVar1[2] + 0xe0,&local_28);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar5 = (*pcVar4)();
      return uVar5;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseInStackQueuedSpinLock(&local_28);
    ExFreePoolWithTag(plVar1,0);
  }
  else {
    uVar6 = 0xc00000bb;
    uVar7 = 5;
  }
  *(undefined4 *)(param_2 + 0x10) = uVar7;
  return (ulonglong)uVar6;
}



===== NvmofiAdapterUpdateNvmeController @ 140007dac =====

uint NvmofiAdapterUpdateNvmeController(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ushort uVar5;
  undefined4 uVar6;
  ushort uVar7;
  ulonglong uVar8;
  
  lVar1 = *(longlong *)(param_2 + 8);
  uVar6 = 0;
  uVar8 = 0;
  uVar3 = 0;
  *(undefined2 *)(lVar1 + 0xac) = *(undefined2 *)(param_2 + 0x10);
  if (0x3f < *(uint *)(param_2 + 0x14)) {
    *(uint *)(lVar1 + 0xb0) = *(uint *)(param_2 + 0x14) - 0x40;
  }
  *(undefined4 *)(lVar1 + 0xb4) = *(undefined4 *)(param_2 + 0x1c);
  if (*(short *)(param_2 + 0x12) != 0) {
    if (*(longlong *)(lVar1 + 0xc4) != 0) {
      if (*(short *)(param_2 + 0x12) == *(short *)(lVar1 + 0xae)) goto LAB_140007f55;
      if (*(short *)(lVar1 + 0xae) != 0) {
        do {
          NvmofiCleanupQueue(uVar8 * 0x270 + *(longlong *)(lVar1 + 0xc4));
          uVar7 = (short)uVar8 + 1;
          uVar8 = (ulonglong)uVar7;
        } while (uVar7 < *(ushort *)(lVar1 + 0xae));
      }
      ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0xc4),0);
      *(undefined8 *)(lVar1 + 0xc4) = 0;
      *(undefined2 *)(lVar1 + 0xae) = 0;
    }
    uVar7 = *(ushort *)(param_2 + 0x12);
    lVar4 = ExAllocatePool2(0x40,(ulonglong)uVar7 * 0x270,0x7143664e);
    *(longlong *)(lVar1 + 0xc4) = lVar4;
    if (lVar4 == 0) {
      uVar3 = 0xc0000017;
      uVar6 = 8;
    }
    else {
      *(ushort *)(lVar1 + 0xae) = uVar7;
      uVar5 = 0;
      if (uVar7 != 0) {
        lVar4 = 0;
        do {
          uVar5 = uVar5 + 1;
          *(longlong *)(lVar4 + *(longlong *)(lVar1 + 0xc4)) = lVar1;
          *(undefined4 *)(lVar4 + 0x20 + *(longlong *)(lVar1 + 0xc4)) = 0;
          *(ushort *)(lVar4 + 0x26 + *(longlong *)(lVar1 + 0xc4)) = uVar5;
          lVar4 = lVar4 + 0x270;
        } while (uVar5 < uVar7);
      }
      uVar3 = 0;
      lVar4 = *(longlong *)(*(longlong *)(lVar1 + 0x18) + 0x10);
      lVar2 = *(longlong *)(lVar4 + 0xc0);
      if (lVar2 != 0) {
        uVar3 = KrdmaUpdatePoolCount(lVar2 + 0x140,(uint)*(ushort *)(lVar1 + 0xae) << 6);
        if ((int)uVar3 < 0) {
          uVar6 = 0x21;
        }
        else {
          uVar3 = KrdmaUpdatePoolCount
                            (*(longlong *)(lVar4 + 0xc0) + 0x100,
                             (uint)*(ushort *)(lVar1 + 0xae) << 5);
          uVar6 = 0;
          if ((int)uVar3 < 0) {
            uVar6 = 0x22;
          }
        }
      }
    }
  }
LAB_140007f55:
  *(undefined4 *)(param_2 + 0x24) = uVar6;
  if (((int)uVar3 < 0) && (*(longlong *)(lVar1 + 0xc4) != 0)) {
    uVar7 = 0;
    if (*(short *)(lVar1 + 0xae) != 0) {
      do {
        NvmofiCleanupQueue((ulonglong)uVar7 * 0x270 + *(longlong *)(lVar1 + 0xc4));
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(lVar1 + 0xae));
    }
    ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0xc4),0);
    *(undefined8 *)(lVar1 + 0xc4) = 0;
    *(undefined2 *)(lVar1 + 0xae) = 0;
  }
  return uVar3;
}



===== NvmofiFreeHostGateway @ 140007fdc =====

void NvmofiFreeHostGateway(longlong *param_1)

{
  LOCK();
  *(undefined4 *)(*param_1 + 200) = *(undefined4 *)(*param_1 + 200);
  UNLOCK();
  RtlFreeUnicodeString(*param_1 + 0x28);
  ExFreePoolWithTag(*param_1,0);
  *param_1 = 0;
  return;
}



===== NvmofiQueueWorkItem @ 140008028 =====

void NvmofiQueueWorkItem(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_res20;
  
  local_res20 = 0;
  iVar1 = StorPortExtendedFunction(0x1d,param_1,&local_res20);
  if (iVar1 == 0) {
    StorPortExtendedFunction(0x1e,param_1,param_2,local_res20,param_3);
  }
  return;
}



===== NvmofiQueueWorkItemToNode @ 140008098 =====

void NvmofiQueueWorkItemToNode
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 local_18 [2];
  
  local_18[0] = 0;
  iVar1 = StorPortExtendedFunction(0x1d,param_1,local_18);
  if (iVar1 == 0) {
    StorPortExtendedFunction(0x88,param_1,param_2,local_18[0],param_3,param_4);
  }
  return;
}



===== NvmofiRemoveHostGatewayWorker @ 140008120 =====

void NvmofiRemoveHostGatewayWorker(longlong param_1,longlong *param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong local_res8;
  
  lVar1 = *param_2;
  local_res8 = lVar1;
  TdiPnPPowerComplete(*(undefined8 *)(param_1 + 0x48),param_2[1],0);
  StorPortNvmeofExtendedFunction(3,param_1,*(undefined8 *)(lVar1 + 0xd8));
  NvmofiFreeHostGateway(&local_res8);
  StorPortExtendedFunction(0x1f,param_1,param_3);
  return;
}



===== Feature_729018683__private_IsEnabledDeviceUsageNoInline @ 1400081a8 =====

ulonglong Feature_729018683__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_729018683__private_featureState;
  if ((Feature_729018683__private_featureState & 0x10) == 0) {
    uVar1 = Feature_729018683__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_729018683__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_729018683__private_IsEnabledFallback @ 1400081e0 =====

void Feature_729018683__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== NvmofiWskCopyIndicationListToBuffer @ 1400081fc =====

undefined8
NvmofiWskCopyIndicationListToBuffer
          (longlong *param_1,undefined8 *param_2,ulonglong param_3,ulonglong param_4,
          ulonglong *param_5,longlong param_6)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  lVar1 = *param_1;
  uVar5 = 0;
  uVar8 = 0;
  uVar2 = *(undefined8 *)(lVar1 + 0x10);
  if (*param_5 < param_4) {
    uVar5 = 0xc0000023;
  }
  else {
    while ((param_2 != (undefined8 *)0x0 && (uVar8 < param_4))) {
      uVar6 = param_2[3];
      uVar9 = (ulonglong)*(uint *)(param_2 + 2);
      if (param_3 < uVar6) {
        puVar3 = (undefined8 *)param_2[1];
        while( true ) {
          if (((puVar3 == (undefined8 *)0x0) || (param_4 <= uVar8)) || (uVar6 == 0))
          goto LAB_140008384;
          uVar7 = (ulonglong)*(uint *)(puVar3 + 5);
          if (uVar7 < uVar9) {
            StorPortExtendedFunction
                      (0x80,uVar2,*(undefined8 *)(lVar1 + 0xa0),0,1,0,
                       L"MdlByteCount or WskBufOffset invalid",0x200,2,0,L"QueueId",
                       *(undefined2 *)((longlong)param_1 + 0x26),L"MdlByteCount",uVar7,
                       L"WskBufOffset",uVar9,L"",0,L"",0,L"",0,L"",0,L"",0);
            return 0xc00000c3;
          }
          uVar7 = uVar7 - uVar9;
          if ((*(byte *)((longlong)puVar3 + 10) & 5) == 0) {
            lVar4 = MmMapLockedPagesSpecifyCache(puVar3,0,1,0,0,0x40000000);
          }
          else {
            lVar4 = puVar3[3];
          }
          if (lVar4 == 0) {
            StorPortExtendedFunction
                      (0x80,uVar2,*(undefined8 *)(lVar1 + 0xa0),0,1,0,
                       L"MmGetSystemAddressForMdlSafe error",0x200,2,0,L"QueueId",
                       *(undefined2 *)((longlong)param_1 + 0x26),L"Mdl",puVar3,L"",0,L"",0,L"",0,L""
                       ,0,L"",0,L"",0);
            return 0xc000009a;
          }
          if (uVar6 < uVar7) break;
          if (param_3 < uVar7) {
            uVar7 = uVar7 - param_3;
            if (param_4 - uVar8 <= uVar7) {
              uVar7 = param_4 - uVar8;
            }
            memmove((void *)(param_6 + uVar8),(void *)(lVar4 + uVar9 + param_3),uVar7);
            uVar8 = uVar8 + uVar7;
            param_3 = 0;
          }
          else {
            param_3 = param_3 - uVar7;
          }
          puVar3 = (undefined8 *)*puVar3;
          uVar6 = uVar6 - uVar7;
          uVar9 = 0;
        }
        uVar7 = uVar6 - param_3;
        if (param_4 - uVar8 <= uVar6 - param_3) {
          uVar7 = param_4 - uVar8;
        }
        memmove((void *)(param_6 + uVar8),(void *)(lVar4 + uVar9 + param_3),uVar7);
        uVar8 = uVar8 + uVar7;
        param_3 = 0;
      }
      else {
        param_3 = param_3 - uVar6;
      }
LAB_140008384:
      param_2 = (undefined8 *)*param_2;
    }
    *param_5 = uVar8;
  }
  return uVar5;
}



===== NvmofiWskDisconnectEvent @ 1400085b0 =====

undefined8 NvmofiWskDisconnectEvent(longlong *param_1,undefined4 param_2)

{
  if ((int)param_1[4] == 2) {
    StorPortExtendedFunction
              (0x80,NvmofiAdapterExtension,*(undefined8 *)(*param_1 + 0xa0),0,1,0x1e,
               L"NvmofiWskDisconnectEvent",0x200,2,0,L"Flags",param_2,L"QueueId",
               *(undefined2 *)((longlong)param_1 + 0x26),L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
    param_1[1] = param_1[1] | 4;
    NvmofiNotifyQueueTransportFatalError(param_1,0x140012ec8);
  }
  return 0;
}



===== NvmofiWskInitializeSockAddr @ 1400086a4 =====

void NvmofiWskInitializeSockAddr(undefined8 param_1,ushort param_2,undefined2 *param_3)

{
  int iVar1;
  undefined6 in_register_00000012;
  ushort uVar2;
  undefined2 local_res18 [4];
  undefined4 local_res20 [2];
  
  *param_3 = 2;
  uVar2 = param_2 >> 8 | param_2 << 8;
  param_3[1] = uVar2;
  local_res18[0] = 0;
  local_res20[0] = 0;
  iVar1 = RtlIpv4StringToAddressExA
                    (param_1,CONCAT71((int7)(CONCAT62(in_register_00000012,param_2) >> 8),1),
                     param_3 + 2,local_res18);
  if (iVar1 == -0x3ffffff3) {
    *param_3 = 0x17;
    param_3[1] = uVar2;
    RtlIpv6StringToAddressExA(param_1,param_3 + 4,local_res20,local_res18);
  }
  return;
}



===== NvmofiWskReceiveEvent @ 140008740 =====

ulonglong NvmofiWskReceiveEvent
                    (longlong *param_1,undefined8 param_2,undefined8 *param_3,byte *param_4,
                    undefined8 *param_5)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  short sVar14;
  byte *pbVar15;
  ushort uVar16;
  uint local_res8;
  ushort local_54 [2];
  byte *local_50;
  longlong local_48;
  longlong local_40;
  
  local_54[0] = 0;
  pbVar15 = (byte *)0x0;
  bVar4 = false;
  uVar13 = 0;
  bVar5 = false;
  if ((*(byte *)(param_1 + 1) & 0xc0) == 0) {
    *param_5 = 0;
    local_48 = *param_1;
    local_40 = *(longlong *)(local_48 + 0x10);
    if (param_3 == (undefined8 *)0x0) {
      if ((int)param_1[4] == 2) {
        StorPortExtendedFunction
                  (0x80,local_40,*(undefined8 *)(local_48 + 0xa0),0,1,0x1e,L"NvmofiWskReceiveEvent",
                   0x200,2,0xf0,L"QueueId",*(undefined2 *)((longlong)param_1 + 0x26),L"",0,L"",0,L""
                   ,0,L"",0,L"",0,L"",0,L"",0);
        param_1[1] = param_1[1] | 4;
        NvmofiNotifyQueueTransportFatalError(param_1,0x140012d08);
      }
      *param_5 = 0;
    }
    else if ((param_1[1] & 8U) == 0) {
      if ((param_1[1] & 0x200U) == 0) {
        do {
          if ((param_4 <= pbVar15) || (bVar5)) goto LAB_140008e88;
          lVar11 = (ulonglong)*(ushort *)(param_1 + 0xb) + 0x5c + (longlong)param_1;
          local_50 = (byte *)(ulonglong)*(ushort *)((longlong)param_1 + 0x5a);
          if (param_4 + -(longlong)pbVar15 <
              (byte *)(ulonglong)*(ushort *)((longlong)param_1 + 0x5a)) {
            local_50 = param_4 + -(longlong)pbVar15;
          }
          uVar8 = NvmofiWskCopyIndicationListToBuffer
                            (param_1,param_3,(ulonglong)pbVar15,(ulonglong)local_50,
                             (ulonglong *)&local_50,lVar11);
          pbVar6 = local_50;
          uVar13 = (ulonglong)(int)uVar8;
          uVar12 = (uint)((ulonglong)lVar11 >> 0x20);
          if ((int)uVar8 < 0) {
            StorPortExtendedFunction
                      (0x80,local_40,*(undefined8 *)(local_48 + 0xa0),0,1,(ulonglong)uVar12 << 0x20,
                       L"NvmofiWskCopyIndicationListToBuffer failure",0x200,3,0xf0,L"QueueId",
                       *(undefined2 *)((longlong)param_1 + 0x26),L"NtStatus",uVar13,L"",0,L"",0,L"",
                       0,L"",0,L"",0,L"",0);
LAB_140008d47:
            uVar13 = 0;
            bVar4 = true;
LAB_140008d52:
            *param_5 = pbVar15;
            goto LAB_14000889f;
          }
          sVar14 = (short)local_50;
          if (local_50 + *(ushort *)(param_1 + 0xb) < (byte *)0x8) {
LAB_140009021:
            *(ushort *)(param_1 + 0xb) = *(ushort *)(param_1 + 0xb) + sVar14;
LAB_140009028:
            *(short *)((longlong)param_1 + 0x5a) = *(short *)((longlong)param_1 + 0x5a) - sVar14;
            pbVar15 = pbVar15 + (longlong)pbVar6;
            *param_5 = pbVar15;
            goto LAB_14000912f;
          }
          pcVar1 = (char *)((longlong)param_1 + 0x5c);
          if (local_50 + *(ushort *)(param_1 + 0xb) <
              (byte *)(ulonglong)*(byte *)((longlong)param_1 + 0x5e)) goto LAB_140009021;
          local_50 = (byte *)((longlong)param_1 + 0x5d);
          if ((*(uint *)(local_40 + 0x10) & 2) != 0) {
            StorPortExtendedFunction
                      (0x80,local_40,*(undefined8 *)(local_48 + 0xa0),0,1,(ulonglong)uVar12 << 0x20,
                       L"Receive event",0x200,5,0xf0,L"DataIndication",param_3,L"Offset",pbVar15,
                       L"Queue Id",*(undefined2 *)((longlong)param_1 + 0x26),L"HLEN",
                       (byte *)(ulonglong)*(byte *)((longlong)param_1 + 0x5e),L"PDUType",*pcVar1,
                       L"Flags",*local_50,L"PDO",*(undefined1 *)((longlong)param_1 + 0x5f),L"PLEN",
                       (int)param_1[0xc]);
          }
          bVar2 = *(byte *)((longlong)param_1 + 0x5e);
          uVar10 = param_1[1];
          uVar8 = IsHeaderValid((ushort)bVar2,pcVar1,(byte)uVar10 >> 4 & 1,(byte)uVar10 >> 5 & 1,
                                local_54);
          if ((char)uVar8 == '\0') goto LAB_140008e98;
          cVar3 = *pcVar1;
          if (cVar3 == '\x03') {
            if (pbVar6 + *(ushort *)(param_1 + 0xb) < (byte *)(ulonglong)*(uint *)(param_1 + 0xc)) {
              *(ushort *)(param_1 + 0xb) = *(ushort *)(param_1 + 0xb) + sVar14;
              goto LAB_140009028;
            }
            param_1[1] = uVar10 | 8;
            StorPortExtendedFunction
                      (0x80,local_40,*(undefined8 *)(local_48 + 0xa0),0,1,0x19,
                       L"C2HTerm request received",0x200,3,0xf0,L"Queue Id",
                       *(undefined2 *)((longlong)param_1 + 0x26),L"",0,L"",0,L"",0,L"",0,L"",0,L"",0
                       ,L"",0);
            uVar10 = NvmofiDeferPDUProcessing((longlong)param_1,*(uint *)(param_1 + 0xc),pcVar1);
            pbVar15 = pbVar15 + ((int)param_1[0xc] - (uint)*(ushort *)(param_1 + 0xb));
            uVar13 = 0;
            if (-1 < (int)uVar10) {
              uVar13 = uVar10 & 0xffffffff;
            }
            goto LAB_140008e88;
          }
          if (cVar3 == '\x01') {
            uVar9 = (ulonglong)*(byte *)((longlong)param_1 + 0x67) << 4;
            uVar9 = (uVar10 ^ uVar9) & 0xffffffffffffffef ^ uVar9;
            param_1[1] = uVar9;
            uVar10 = (ulonglong)*(byte *)((longlong)param_1 + 0x67) << 4;
            param_1[1] = (uVar9 ^ uVar10) & 0xffffffffffffffdf ^ uVar10;
            *(ushort *)((longlong)param_1 + 0x2a) = (*(byte *)((longlong)param_1 + 0x66) + 1) * 4;
            uVar12 = *(uint *)(param_1 + 0xd);
            if (((uVar12 & 3) == 0) && (0xfff < uVar12)) {
              *(uint *)(param_1 + 6) = uVar12;
              uVar7 = 0;
            }
            else {
              uVar7 = 0xc000009c;
            }
            *(undefined4 *)((longlong)param_1 + 0x54) = uVar7;
            KeSetEvent((longlong)param_1 + 0x3c,0);
            local_res8 = (int)param_1[0xc] - (uint)*(ushort *)(param_1 + 0xb);
          }
          else if (cVar3 == '\x05') {
            uVar12 = (uint)bVar2;
            local_res8 = uVar12;
            if ((*local_50 & 1) != 0) {
              uVar16 = *(ushort *)(param_1 + 0xb);
              local_res8 = uVar12 + 4;
              if (pbVar6 + uVar16 < (byte *)(ulonglong)local_res8) {
LAB_140008d0f:
                *(ushort *)(param_1 + 0xb) = uVar16 + sVar14;
LAB_140008d18:
                *(short *)((longlong)param_1 + 0x5a) = *(short *)((longlong)param_1 + 0x5a) - sVar14
                ;
                pbVar15 = pbVar15 + (longlong)pbVar6;
                *param_5 = pbVar15;
                goto LAB_14000912f;
              }
            }
            uVar8 = NvmofiDeferPDUProcessing
                              ((longlong)param_1,uVar12,(void *)((longlong)param_1 + 0x5c));
            uVar12 = (uint)uVar8;
LAB_140008cd0:
            uVar13 = (ulonglong)uVar12;
            if ((int)uVar12 < 0) goto LAB_140008d47;
            local_res8 = local_res8 - *(ushort *)(param_1 + 0xb);
          }
          else {
            if (cVar3 != '\a') {
              if (cVar3 == '\t') {
                local_res8 = (uint)bVar2;
                if ((*local_50 & 1) != 0) {
                  uVar16 = *(ushort *)(param_1 + 0xb);
                  local_res8 = local_res8 + 4;
                  if (pbVar6 + uVar16 < (byte *)(ulonglong)local_res8) goto LAB_140008d0f;
                }
                uVar8 = NvmofiDeferR2TProcessing
                                  ((longlong)param_1,(void *)((longlong)param_1 + 0x5c));
                uVar12 = (uint)uVar8;
                goto LAB_140008cd0;
              }
              goto LAB_140008d52;
            }
            local_res8 = (uint)bVar2;
            if ((*local_50 & 1) != 0) {
              local_res8 = local_res8 + 4;
              if (pbVar6 + *(ushort *)(param_1 + 0xb) < (byte *)(ulonglong)local_res8) {
                *(ushort *)(param_1 + 0xb) = *(ushort *)(param_1 + 0xb) + sVar14;
                goto LAB_140008d18;
              }
            }
            param_1[1] = uVar10 | 0x80;
            NvmofiWskTcpSetReceiveEvent((longlong)param_1,'\0','\0');
            uVar10 = NvmofiDeferPDUProcessing
                               ((longlong)param_1,(uint)*(byte *)((longlong)param_1 + 0x5e),
                                (void *)((longlong)param_1 + 0x5c));
            uVar13 = uVar10 & 0xffffffff;
            if ((int)uVar10 < 0) {
              param_1[1] = param_1[1] & 0xffffffffffffff7f;
              NvmofiWskTcpSetReceiveEvent((longlong)param_1,'\x01','\0');
              goto LAB_140008d47;
            }
            local_res8 = local_res8 - *(ushort *)(param_1 + 0xb);
            bVar5 = true;
          }
          pbVar15 = pbVar15 + local_res8;
          *(undefined4 *)(param_1 + 0xb) = 0x1000000;
        } while( true );
      }
      *param_5 = param_4;
      goto LAB_1400088b6;
    }
  }
  else {
    uVar10 = Feature_729018683__private_IsEnabledDeviceUsageNoInline();
    *param_5 = 0;
    if ((int)uVar10 == 0) goto LAB_14000912f;
  }
  uVar13 = 0xc000021b;
  goto LAB_14000889f;
LAB_140008e98:
  StorPortExtendedFunction
            (0x80,local_40,*(undefined8 *)(local_48 + 0xa0),0,1,0x1d,
             L"Receive event - Invalid header",0x200,1,0xf0,L"Queue Id",
             *(undefined2 *)((longlong)param_1 + 0x26),L"HLEN",bVar2,L"PDUType",*pcVar1,L"Flags",
             *local_50,L"PDO",*(undefined1 *)((longlong)param_1 + 0x5f),L"PLEN",(int)param_1[0xc],
             L"FieldOffset",local_54[0],L"",0);
  uVar10 = NvmofiDeferSendH2CTermReq
                     (param_1,1,(uint)local_54[0],*(byte *)((longlong)param_1 + 0x5e),pcVar1);
  uVar13 = 0;
  if (-1 < (int)uVar10) {
    uVar13 = uVar10 & 0xffffffff;
  }
  uVar10 = Feature_729018683__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar10 == 0) ||
     (*(ushort *)(param_1 + 0xb) <= (ushort)*(byte *)((longlong)param_1 + 0x5e))) {
    pbVar15 = pbVar15 + ((ulonglong)*(byte *)((longlong)param_1 + 0x5e) -
                        (ulonglong)*(ushort *)(param_1 + 0xb));
  }
  else {
    pbVar15 = pbVar15 + (longlong)pbVar6;
  }
LAB_140008e88:
  *param_5 = pbVar15;
  if (-1 < (int)uVar13) {
LAB_14000912f:
    if (param_4 <= pbVar15) goto LAB_1400088b6;
  }
LAB_14000889f:
  param_1[1] = param_1[1] | 0x40;
  if (bVar4) {
    NvmofiDeferResumeReceive(param_1);
  }
LAB_1400088b6:
  return uVar13 & 0xffffffff;
}



===== NvmofiWskResumeReceiveEvent @ 140009148 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 NvmofiWskResumeReceiveEvent(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  
  local_28 = 0;
  local_18 = 0;
  local_20 = 0;
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_1c = 0;
  if ((*(longlong *)(param_1 + 0x10) == 0) || ((*(byte *)(param_1 + 8) & 4) != 0)) {
    uVar3 = 0xc000020c;
  }
  else {
    IoReuseIrp(lVar1,0xc0000001);
    lVar2 = *(longlong *)(lVar1 + 0xb8);
    *(code **)(lVar2 + -0x10) = NvmofiWskResumeReceiveEventCompletion;
    *(longlong *)(lVar2 + -8) = param_1;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    uVar3 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x38))
                      (*(longlong **)(param_1 + 0x10),&local_28,0,lVar1);
    if (-1 < (int)uVar3) {
      *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) & 0xffffffffffffffbf;
    }
  }
  return uVar3;
}



===== NvmofiWskResumeReceiveEventCompletion @ 1400091f0 =====

undefined8 NvmofiWskResumeReceiveEventCompletion(void)

{
  return 0xc0000016;
}



===== NvmofiWskTcpConnect @ 140009200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpConnect(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar1 = NvmofiAdapterExtension;
  lVar4 = *(longlong *)(param_1 + 0x1a4);
  uVar3 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    lVar4 = *(longlong *)(param_1 + 0x19c);
  }
  NvmofiInitializeWskSendPacket(lVar4,0,'\0','\0',0,0,'\0');
  iVar2 = (**(code **)(*(longlong *)(lVar1 + 0x38) + 0x10))
                    (*(undefined8 *)(lVar1 + 0x30),1,6,param_2,param_3,0,param_1,
                     &NvmofiWskConnectionEvents,0,0,0,lVar4 + 0x230);
  if (-1 < iVar2) {
    iVar2 = KeWaitForSingleObject(lVar4 + 0x48,0,0,0,&NvmofiWskTcpConnectTimeout);
    if (iVar2 == 0x102) {
      IoCancelIrp(lVar4 + 0x230);
      iVar2 = -0x3fffff4b;
    }
    else if (-1 < iVar2) {
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(lVar4 + 0x268);
      iVar2 = *(int *)(lVar4 + 0x260);
    }
  }
  NvmofiCleanupWskPacket(lVar4);
  return iVar2;
}



===== NvmofiWskTcpConnectQueue @ 140009340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong NvmofiWskTcpConnectQueue
                    (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong in_stack_ffffffffffffff20;
  undefined8 uVar8;
  wchar_t *pwVar9;
  ulonglong in_stack_ffffffffffffff40;
  wchar_t *pwVar10;
  undefined *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar3 = *(undefined8 *)(*param_1 + 0x10);
  *(undefined4 *)(param_1 + 4) = 1;
  iVar4 = NvmofiWskTcpConnect((longlong)param_1,param_2,param_3);
  uVar7 = (ulonglong)iVar4;
  if (iVar4 < 0) {
    *param_4 = 9;
    uVar2 = *(undefined2 *)((longlong)param_1 + 0x26);
    pwVar10 = L"Queue Id";
    pwVar9 = L"WskConnect failure";
    uVar8 = 0x14;
    uVar6 = uVar7;
  }
  else {
    puVar1 = (undefined2 *)((longlong)param_1 + 0x26);
    iVar4 = NvmofiWskTcpGetPort((longlong)param_1);
    if (-1 < iVar4) {
      in_stack_ffffffffffffff40 = in_stack_ffffffffffffff40 & 0xffffffff00000000;
      StorPortExtendedFunction
                (0x80,uVar3,*(undefined8 *)(*param_1 + 0xa0),0,1,
                 in_stack_ffffffffffffff20 & 0xffffffff00000000,L"Queue port number",0x200,5,
                 in_stack_ffffffffffffff40,L"Queue Id",*puVar1,L"Port Number",(short)param_1[5],L"",
                 0,L"",0,L"",0,L"",0,L"",0,L"",0);
    }
    iVar4 = NvmofiWskTcpDisableNagle((longlong)param_1);
    if (iVar4 < 0) {
      StorPortExtendedFunction
                (0x80,uVar3,*(undefined8 *)(*param_1 + 0xa0),0,1,0x16,L"DisableNagle failure",0x200,
                 3,in_stack_ffffffffffffff40 & 0xffffffff00000000,L"QueueId",*puVar1,L"NtStatus",
                 (longlong)iVar4,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
    }
    in_stack_ffffffffffffff40 = 0;
    local_2c = 0;
    local_38 = &NPI_WSK_INTERFACE_ID;
    local_30 = 0xc0;
    uVar5 = (*(code *)**(undefined8 **)param_1[2])
                      ((undefined8 *)param_1[2],0,0x4002,0xffff,0x10,&local_38,0,0,0,0);
    uVar7 = (ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      param_1[1] = param_1[1] & 0xffffffffffffffbf;
      param_1[1] = param_1[1] & 0xfffffffffffffffb;
      *(undefined4 *)(param_1 + 0xb) = 0x1000000;
      *(undefined2 *)((longlong)param_1 + 0x2e) = 0;
      param_1[1] = param_1[1] & 0xfffffffffffffe7f;
      goto LAB_14000978c;
    }
    uVar6 = (ulonglong)(int)uVar5;
    *param_4 = 10;
    uVar2 = *puVar1;
    pwVar10 = L"QueueId";
    pwVar9 = L"EnableConnectionEvents failure";
    uVar8 = 0x16;
  }
  StorPortExtendedFunction
            (0x80,uVar3,*(undefined8 *)(*param_1 + 0xa0),0,1,uVar8,pwVar9,0x200,2,
             in_stack_ffffffffffffff40 & 0xffffffff00000000,pwVar10,uVar2,L"NtStatus",uVar6,L"",0,
             L"",0,L"",0,L"",0,L"",0,L"",0);
LAB_14000978c:
  return uVar7 & 0xffffffff;
}



===== NvmofiWskTcpCreateQueue @ 1400097c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpCreateQueue(undefined8 param_1,longlong *param_2,longlong param_3)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  ushort local_res10 [4];
  undefined4 local_res18 [2];
  
  local_res18[0] = 0;
  local_res10[0] = 0;
  lVar3 = *(longlong *)(*(longlong *)(*param_2 + 0x18) + 0x10);
  *(undefined4 *)(param_2 + 4) = 1;
  iVar2 = (**(code **)(*(longlong *)(lVar3 + 0x20) + 0x20))
                    (param_2,lVar3 + 0x38,*param_2 + 0x20,local_res18);
  if (iVar2 < 0) {
    *(undefined1 *)(param_3 + 3) = 4;
  }
  else {
    NvmofiWskTcpGetIdealBacklogSize((longlong)param_2,local_res10);
    if (*(char *)(param_3 + 2) == '(') {
      lVar3 = *(longlong *)(param_3 + 0x40);
    }
    else {
      lVar3 = *(longlong *)(param_3 + 0x18);
    }
    if ((local_res10[0] == 0) || (*(ushort *)(lVar3 + 0x10) <= local_res10[0])) {
      *(undefined2 *)((longlong)param_2 + 0x2c) = *(undefined2 *)(lVar3 + 0x10);
    }
    else {
      *(ushort *)((longlong)param_2 + 0x2c) = local_res10[0];
    }
    iVar2 = NvmofiAllocateQueueResources(param_2);
    if (iVar2 < 0) {
      local_res18[0] = 0xb;
      *(undefined1 *)(param_3 + 3) = 0x26;
    }
    else {
      plVar1 = param_2 + 0x42;
      *(undefined8 *)((longlong)param_2 + 0x34) = 0;
      param_2[0x43] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
      plVar1 = param_2 + 0x45;
      param_2[0x46] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
      iVar2 = NvmofiTcpInitializeNvme((longlong)param_2,local_res18);
      if (iVar2 < 0) {
        *(undefined1 *)(param_3 + 3) = 4;
      }
      else {
        *(undefined4 *)((longlong)param_2 + 0x204) = 1;
        *(undefined4 *)((longlong)param_2 + 0x20c) = 1;
        *(undefined1 *)(param_3 + 3) = 1;
      }
    }
    *(undefined4 *)(lVar3 + 0x38) = local_res18[0];
  }
  if (*(char *)(param_3 + 3) != '\x01') {
    NvmofiFreeQueueResources((longlong)param_2);
    if (param_2[2] != 0) {
      NvmofiWskTcpSetReceiveEvent((longlong)param_2,'\0','\0');
      NvmofiWskTcpDisconnect((longlong)param_2,'\x01');
    }
    *(undefined4 *)(param_2 + 4) = 0;
    param_2[2] = 0;
  }
  return iVar2;
}



===== NvmofiWskTcpDisableNagle @ 140009920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpDisableNagle(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 local_res8 [2];
  
  lVar3 = *(longlong *)(param_1 + 0x1a4);
  local_res8[0] = 1;
  uVar2 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x19c);
  }
  NvmofiInitializeWskSendPacket(lVar3,0,'\0','\0',0,0,'\0');
  iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x10))
                    (*(undefined8 **)(param_1 + 0x10),0,1,6,4,local_res8,0,0,0,lVar3 + 0x230);
  if (-1 < iVar1) {
    iVar1 = KeWaitForSingleObject(lVar3 + 0x48,0,0,0,0);
    if (-1 < iVar1) {
      iVar1 = *(int *)(lVar3 + 0x260);
    }
  }
  NvmofiCleanupWskPacket(lVar3);
  return iVar1;
}



===== NvmofiWskTcpDisconnect @ 140009a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpDisconnect(longlong param_1,char param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x1a4);
  iVar1 = 0;
  uVar2 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x19c);
  }
  if (*(longlong *)(param_1 + 0x10) != 0) {
    NvmofiInitializeWskSendPacket(lVar3,0,'\0','\0',0,0,'\0');
    iVar1 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x40))
                      (*(longlong **)(param_1 + 0x10),0,param_2 != '\0',lVar3 + 0x230);
    if (-1 < iVar1) {
      iVar1 = KeWaitForSingleObject(lVar3 + 0x48,0,0,0,&NvmofiWskTcpDisconnectTimeout);
      if (iVar1 == 0x102) {
        IoCancelIrp(lVar3 + 0x230);
        iVar1 = -0x3fffff4b;
      }
      else if ((-1 < iVar1) && (iVar1 = *(int *)(lVar3 + 0x260), iVar1 == -0x3ffffdf3)) {
        iVar1 = 0;
      }
    }
  }
  NvmofiCleanupWskPacket(lVar3);
  return iVar1;
}



===== NvmofiWskTcpDisconnectQueue @ 140009b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpDisconnectQueue(longlong *param_1)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 in_stack_ffffffffffffff38;
  undefined4 uVar5;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
  uVar1 = *(undefined8 *)(*param_1 + 0x10);
  iVar2 = NvmofiWskTcpSetReceiveEvent((longlong)param_1,'\0','\x01');
  if (iVar2 < 0) {
    StorPortExtendedFunction(0x80);
  }
  iVar2 = NvmofiWskTcpDisconnect((longlong)param_1,'\0');
  if ((iVar2 < 0) && (iVar2 = NvmofiWskTcpDisconnect((longlong)param_1,'\x01'), iVar2 < 0)) {
    StorPortExtendedFunction(0x80);
  }
  lVar4 = *(longlong *)((longlong)param_1 + 0x1a4);
  iVar2 = 0;
  uVar3 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    lVar4 = *(longlong *)((longlong)param_1 + 0x19c);
  }
  if (param_1[2] != 0) {
    uVar5 = 0;
    NvmofiInitializeWskSendPacket(lVar4,0,'\0','\0',0,0,'\0');
    iVar2 = (**(code **)(*(longlong *)param_1[2] + 8))((longlong *)param_1[2],lVar4 + 0x230);
    if (-1 < iVar2) {
      uVar5 = 1;
      iVar2 = KeWaitForSingleObject(lVar4 + 0x48,0,0,0,&NvmofiWskTcpCloseTimeout);
      if (iVar2 == 0x102) {
        IoCancelIrp(lVar4 + 0x230);
        iVar2 = -0x3fffff4b;
      }
      else if (-1 < iVar2) {
        iVar2 = *(int *)(lVar4 + 0x260);
      }
    }
  }
  NvmofiCleanupWskPacket(lVar4);
  param_1[2] = 0;
  if (iVar2 < 0) {
    StorPortExtendedFunction
              (0x80,uVar1,*(undefined8 *)(*param_1 + 0xa0),0,CONCAT44(uVar5,1),0x1a,
               L"WskClose failure",0x200,2,0,L"Queue Id",*(undefined2 *)((longlong)param_1 + 0x26),
               L"NtStatus",(longlong)iVar2,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
  }
  return iVar2;
}



===== NvmofiWskTcpGetIdealBacklogSize @ 140009ee8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NvmofiWskTcpGetIdealBacklogSize(longlong param_1,undefined2 *param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined2 uVar4;
  ulonglong local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x1a4);
  local_res8 = 0;
  uVar2 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x19c);
  }
  *param_2 = 0;
  NvmofiInitializeWskSendPacket(lVar3,0,'\0','\0',0,0,'\0');
  uVar4 = 0xffff;
  iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x10))
                    (*(undefined8 **)(param_1 + 0x10),2,0x4f000003,0xffff,0,0,8,&local_res8,0,
                     lVar3 + 0x230);
  if (-1 < iVar1) {
    iVar1 = KeWaitForSingleObject(lVar3 + 0x48,0,0,0,0);
    if ((-1 < iVar1) && (-1 < *(int *)(lVar3 + 0x260))) {
      if (local_res8 < 0x10000) {
        uVar4 = (undefined2)local_res8;
      }
      *param_2 = uVar4;
    }
  }
  NvmofiCleanupWskPacket(lVar3);
  return;
}



===== NvmofiWskTcpGetPort @ 140009ffc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NvmofiWskTcpGetPort(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 auStackY_e8 [32];
  short local_a8;
  undefined2 local_a6;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  memset(&local_a8,0,0x80);
  lVar3 = *(longlong *)(param_1 + 0x1a4);
  uVar2 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x19c);
  }
  *(undefined2 *)(param_1 + 0x28) = 0;
  NvmofiInitializeWskSendPacket(lVar3,0,'\0','\0',0,0,'\0');
  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x20))
                    (*(longlong **)(param_1 + 0x10),&local_a8,lVar3 + 0x230);
  if (-1 < iVar1) {
    iVar1 = KeWaitForSingleObject(lVar3 + 0x48,0,0,0);
    if ((-1 < iVar1) && (iVar1 = *(int *)(lVar3 + 0x260), -1 < iVar1)) {
      iVar1 = 0;
      if ((local_a8 == 2) || (local_a8 == 0x17)) {
        *(undefined2 *)(param_1 + 0x28) = local_a6;
      }
      else {
        iVar1 = -0x3fffff45;
      }
    }
  }
  NvmofiCleanupWskPacket(lVar3);
  return iVar1;
}



===== NvmofiWskTcpInitialize @ 14000a124 =====

ulonglong NvmofiWskTcpInitialize(longlong param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  undefined8 local_18;
  undefined *local_10;
  
  local_10 = &WskClientDispatch;
  local_18 = 0;
  iVar1 = WskRegister(&local_18,param_1 + 0x18);
  uVar3 = (ulonglong)iVar1;
  if (iVar1 < 0) {
    pwVar2 = L"WskRegister failure";
  }
  else {
    *(undefined1 *)(param_1 + 0x40) = 1;
    iVar1 = WskCaptureProviderNPI(param_1 + 0x18,0xffffffff,param_1 + 0x30);
    uVar3 = (ulonglong)iVar1;
    if (-1 < iVar1) {
      *(undefined1 *)(param_1 + 0x41) = 1;
      goto LAB_14000a2f6;
    }
    pwVar2 = L"WskCaptureProviderNPI failure";
  }
  StorPortExtendedFunction
            (0x80,param_1,0,0,1,0x12,pwVar2,0x200,1,0,L"NtStatus",uVar3,L"",0,L"",0,L"",0,L"",0,L"",
             0,L"",0,L"",0);
  NvmofiWskCleanup(param_1,'\0');
LAB_14000a2f6:
  return uVar3 & 0xffffffff;
}



===== NvmofiWskTcpReceive @ 14000a320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpReceive(longlong param_1,undefined1 *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  
  plVar1 = *(longlong **)(param_1 + 0x20);
  *param_2 = 0;
  plVar2 = (longlong *)plVar1[2];
  if ((plVar2 == (longlong *)0x0) || ((*(byte *)(plVar1 + 1) & 4) != 0)) {
    iVar3 = -0x3ffffdf4;
  }
  else {
    iVar3 = (**(code **)(*plVar2 + 0x38))(plVar2,param_1 + 0x20c,2,param_1 + 0x230);
    *param_2 = 1;
    if (-1 < iVar3) {
      return iVar3;
    }
  }
  StorPortExtendedFunction
            (0x80,NvmofiAdapterExtension,*(undefined8 *)(*plVar1 + 0xa0),0,1,0x18,
             L"NvmofiWskReceive failure",0x200,2,0xf0,L"NtStatus",(longlong)iVar3,L"",0,L"",0,L"",0,
             L"",0,L"",0,L"",0,L"",0);
  return iVar3;
}



===== NvmofiWskTcpSend @ 14000a480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpSend(longlong param_1,undefined1 *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  
  plVar1 = *(longlong **)(param_1 + 0x20);
  *param_2 = 0;
  plVar2 = (longlong *)plVar1[2];
  if ((plVar2 == (longlong *)0x0) || ((*(byte *)(plVar1 + 1) & 4) != 0)) {
    iVar3 = -0x3ffffdf4;
  }
  else {
    iVar3 = (**(code **)(*plVar2 + 0x30))(plVar2,param_1 + 0x20c,0,param_1 + 0x230);
    *param_2 = 1;
    if (-1 < iVar3) {
      return iVar3;
    }
  }
  StorPortExtendedFunction
            (0x80,NvmofiAdapterExtension,*(undefined8 *)(*plVar1 + 0xa0),0,1,0x17,
             L"NvmofiWskSend failure",0x200,2,9,L"NtStatus",(longlong)iVar3,L"",0,L"",0,L"",0,L"",0,
             L"",0,L"",0,L"",0);
  return iVar3;
}



===== NvmofiWskTcpSetReceiveEvent @ 14000a5e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskTcpSetReceiveEvent(longlong param_1,char param_2,char param_3)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  lVar5 = 0;
  lVar4 = *(longlong *)(param_1 + 0x1a4);
  iVar2 = 0;
  uVar3 = Feature_983534905__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    lVar4 = *(longlong *)(param_1 + 0x19c);
  }
  if (*(undefined8 **)(param_1 + 0x10) != (undefined8 *)0x0) {
    pcVar1 = *(code **)**(undefined8 **)(param_1 + 0x10);
    local_28 = &NPI_WSK_INTERFACE_ID;
    if (param_2 == '\0') {
      local_20 = 0x80000040;
      if (param_3 != '\0') {
        NvmofiInitializeWskSendPacket(lVar4,0,'\0','\0',0,0,'\0');
        lVar5 = lVar4 + 0x230;
      }
    }
    else {
      local_20 = 0x40;
    }
    iVar2 = (*pcVar1)(*(undefined8 *)(param_1 + 0x10),0,0x4002,0xffff,0x10,&local_28,0,0,0,lVar5);
    if (-1 < iVar2) {
      if (param_2 == '\0') {
        if (param_3 != '\0') {
          KeWaitForSingleObject(lVar4 + 0x48,0,0,0,&NvmofiWskTcpSendReceiveTimeout);
        }
        *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) | 0x40;
      }
      else {
        *(ulonglong *)(param_1 + 8) = *(ulonglong *)(param_1 + 8) & 0xffffffffffffffbf;
      }
    }
  }
  return iVar2;
}



===== NvmofiWskWaitForCompletion @ 14000a72c =====

ulonglong NvmofiWskWaitForCompletion(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = KeWaitForSingleObject(param_1 + 0x48,0,0,0,&NvmofiWskTcpSendReceiveTimeout);
  if (-1 < (int)uVar1) {
    uVar1 = (ulonglong)*(uint *)(param_1 + 0x260);
  }
  return uVar1;
}



===== NvmofiWskRdmaCloseAdapter @ 14000a770 =====

void NvmofiWskRdmaCloseAdapter(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  LOCK();
  piVar1 = (int *)(param_1 + 200);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0xd0,0);
    puVar3 = *(undefined8 **)(param_1 + 0xc0);
    puVar4 = (undefined8 *)0x0;
    if (puVar3 != (undefined8 *)0x0) {
      *(undefined8 *)(param_1 + 0xc0) = 0;
      puVar4 = puVar3;
    }
    ExReleasePushLockExclusiveEx(param_1 + 0xd0,0);
    KeLeaveCriticalRegion();
    if (puVar4 != (undefined8 *)0x0) {
      KrdmaCloseAdapter(puVar4);
    }
  }
  return;
}



===== NvmofiWskRdmaConnect @ 14000a810 =====

uint NvmofiWskRdmaConnect
               (longlong *param_1,undefined8 param_2,undefined4 *param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *local_res8;
  
  lVar1 = *param_1;
  local_res8 = (longlong *)0x0;
  bVar3 = false;
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x18) + 0x10);
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x3c,0x6352664e);
  if (puVar5 == (undefined8 *)0x0) {
    return 0xc000009a;
  }
  lVar6 = ExAllocatePool2(0x40,0x20,0x6352664e);
  *(longlong *)((longlong)puVar5 + 0x24) = lVar6;
  plVar7 = (longlong *)0x0;
  if (lVar6 == 0) {
LAB_14000a893:
    uVar4 = 0xc000009a;
  }
  else {
    lVar6 = ExAllocatePool2(0x40,0x20,0x6352664e);
    *(longlong *)((longlong)puVar5 + 0x2c) = lVar6;
    if (lVar6 == 0) goto LAB_14000a893;
    uVar4 = NvmofiWskRdmaFindOrOpenAdapter
                      (lVar2,*(NET_IFINDEX *)(lVar2 + 0xb8),(undefined4 *)(lVar2 + 0x38),param_4);
    if (-1 < (int)uVar4) {
      lVar1 = lVar1 + 0xb8;
      bVar3 = true;
      plVar9 = param_1;
      uVar4 = KrdmaCreateSocket(*(undefined8 **)(lVar2 + 0xc0),lVar1,&local_res8,(longlong)param_1,
                                (undefined2 *)lVar1,param_1 + 0x48,param_1 + 0x4a,&local_res8);
      if ((int)uVar4 < 0) {
        plVar7 = local_res8;
      }
      else {
        uVar8 = 0;
        KeInitializeEvent(puVar5 + 1,0);
        plVar7 = local_res8;
        **(undefined2 **)((longlong)puVar5 + 0x24) = 0;
        *(undefined2 *)(*(longlong *)((longlong)puVar5 + 0x24) + 2) =
             *(undefined2 *)((longlong)param_1 + 0x26);
        *(undefined2 *)(*(longlong *)((longlong)puVar5 + 0x24) + 8) =
             *(undefined2 *)(*param_1 + 0xac);
        if (*(short *)((longlong)param_1 + 0x26) ==
            *(short *)(*(longlong *)(*param_1 + 0xbc) + 0x26)) {
          *(undefined2 *)(*(longlong *)((longlong)puVar5 + 0x24) + 4) = 0x20;
          *(undefined2 *)(*(longlong *)((longlong)puVar5 + 0x24) + 6) = 0x1f;
        }
        else {
          *(undefined2 *)(*(longlong *)((longlong)puVar5 + 0x24) + 4) =
               *(undefined2 *)((longlong)param_1 + 0x2c);
          *(short *)(*(longlong *)((longlong)puVar5 + 0x24) + 6) =
               *(short *)((longlong)param_1 + 0x2c) + -1;
        }
        uVar4 = KrdmaSocketConnect((undefined *)local_res8,param_3,uVar8,plVar9,(longlong)puVar5,
                                   *(undefined8 *)((longlong)puVar5 + 0x24));
        if (-1 < (int)uVar4) {
          KeWaitForSingleObject(puVar5 + 1,0,0,0,0);
          uVar4 = *(uint *)(puVar5 + 4);
          if ((-1 < (int)uVar4) &&
             (uVar4 = NvmofiRdmaGetConnectionData
                                (plVar7,(uint *)((longlong)puVar5 + 0x34),(uint *)(puVar5 + 7),
                                 *(undefined4 **)((longlong)puVar5 + 0x2c)), -1 < (int)uVar4)) {
            *puVar5 = plVar7;
            plVar7 = (longlong *)0x0;
            param_1[2] = (longlong)puVar5;
            goto LAB_14000aa7a;
          }
        }
      }
    }
  }
  if (*(longlong *)((longlong)puVar5 + 0x24) != 0) {
    ExFreePoolWithTag(*(longlong *)((longlong)puVar5 + 0x24),0x6352664e);
    *(undefined8 *)((longlong)puVar5 + 0x24) = 0;
  }
  if (*(longlong *)((longlong)puVar5 + 0x2c) != 0) {
    ExFreePoolWithTag(*(longlong *)((longlong)puVar5 + 0x2c),0x6352664e);
    *(undefined8 *)((longlong)puVar5 + 0x2c) = 0;
  }
  ExFreePoolWithTag(puVar5,0x6352664e);
LAB_14000aa7a:
  if (plVar7 != (longlong *)0x0) {
    KrdmaCloseSocket(plVar7);
  }
  if (((int)uVar4 < 0) && (bVar3)) {
    NvmofiWskRdmaCloseAdapter(lVar2);
  }
  return uVar4;
}



===== NvmofiWskRdmaConnectCallback @ 14000aac0 =====

void NvmofiWskRdmaConnectCallback(undefined4 param_1,undefined8 param_2,longlong param_3)

{
  *(undefined4 *)(param_3 + 0x20) = param_1;
  KeSetEvent(param_3 + 8,0,0);
  return;
}



===== NvmofiWskRdmaConnectQueue @ 14000aaf0 =====

uint NvmofiWskRdmaConnectQueue
               (longlong *param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar1 = *(undefined8 *)(*param_1 + 0x10);
  *(undefined4 *)(param_1 + 4) = 1;
  *param_4 = 0;
  uVar2 = NvmofiWskRdmaConnect(param_1,param_2,param_3,param_4);
  if ((int)uVar2 < 0) {
    *param_4 = 0x14;
    StorPortExtendedFunction
              (0x80,uVar1,*(undefined8 *)(*param_1 + 0xa0),0,1,0x14,L"WskRdmaConnectQueue failure",
               0x200,2,0,L"Queue Id",*(undefined2 *)((longlong)param_1 + 0x26),L"NtStatus",
               (longlong)(int)uVar2,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
  }
  else {
    param_1[1] = param_1[1] & 0xfffffffffffffffb;
    *(undefined2 *)((longlong)param_1 + 0x2e) = 0;
  }
  return uVar2;
}



===== NvmofiWskRdmaCreateQueue @ 14000ac50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NvmofiWskRdmaCreateQueue(undefined8 param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 local_res10 [2];
  
  if (*(char *)(param_3 + 2) == '(') {
    lVar4 = *(longlong *)(param_3 + 0x40);
  }
  else {
    lVar4 = *(longlong *)(param_3 + 0x18);
  }
  local_res10[0] = 0;
  *(undefined2 *)((longlong)param_2 + 0x2c) = *(undefined2 *)(lVar4 + 0x10);
  lVar1 = *(longlong *)(*(longlong *)(*param_2 + 0x18) + 0x10);
  *(undefined4 *)(param_2 + 4) = 1;
  iVar2 = (**(code **)(*(longlong *)(lVar1 + 0x20) + 0x20))
                    (param_2,lVar1 + 0x38,*param_2 + 0x20,local_res10);
  if (iVar2 < 0) {
    *(undefined1 *)(param_3 + 3) = 4;
  }
  else {
    iVar2 = NvmofiAllocateQueueResources(param_2);
    if (iVar2 < 0) {
      local_res10[0] = 0xb;
      *(undefined1 *)(param_3 + 3) = 0x26;
    }
    else {
      param_2[1] = param_2[1] & 0xfffffffffffffff7;
      iVar2 = 0;
      *(undefined4 *)((longlong)param_2 + 0x204) = 0x20;
      uVar3 = 0x20;
      if (*(uint *)(param_2[2] + 0x34) < 0x20) {
        uVar3 = *(uint *)(param_2[2] + 0x34);
      }
      *(uint *)((longlong)param_2 + 0x20c) = uVar3;
      *(undefined1 *)(param_3 + 3) = 1;
    }
  }
  *(undefined4 *)(lVar4 + 0x38) = local_res10[0];
  if (*(char *)(param_3 + 3) != '\x01') {
    NvmofiFreeQueueResources((longlong)param_2);
    *(undefined4 *)(param_2 + 4) = 0;
    param_2[2] = 0;
  }
  return iVar2;
}



===== NvmofiWskRdmaDisconnect @ 14000ad50 =====

undefined8 NvmofiWskRdmaDisconnect(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(longlong **)(param_1 + 0x10) != (longlong *)0x0) {
    KrdmaInternalDisconnect(**(longlong **)(param_1 + 0x10));
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



===== NvmofiWskRdmaDisconnectCallback @ 14000ad80 =====

void NvmofiWskRdmaDisconnectCallback(longlong *param_1)

{
  if ((int)param_1[4] == 2) {
    StorPortExtendedFunction
              (0x80,NvmofiAdapterExtension,*(undefined8 *)(*param_1 + 0xa0),0,1,0x1e,
               L"NvmofiWskRdmaDisconnectEvent",0x200,2,0,L"QueueId",
               *(undefined2 *)((longlong)param_1 + 0x26),L"",0,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
    param_1[1] = param_1[1] | 4;
    NvmofiNotifyQueueTransportFatalError(param_1,0x1400130d0);
  }
  return;
}



===== NvmofiWskRdmaDisconnectQueue @ 14000ae70 =====

undefined8 NvmofiWskRdmaDisconnectQueue(longlong *param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = (longlong *)param_1[2];
  if ((plVar1 == (longlong *)0x0) || (*plVar1 == 0)) {
    uVar2 = 0xc000000d;
  }
  else {
    if (*(longlong *)((longlong)plVar1 + 0x24) != 0) {
      ExFreePoolWithTag(*(longlong *)((longlong)plVar1 + 0x24),0x6352664e);
      *(undefined8 *)(param_1[2] + 0x24) = 0;
    }
    if (*(undefined8 **)param_1[2] != (undefined8 *)0x0) {
      KrdmaCloseSocket(*(undefined8 **)param_1[2]);
      *(undefined8 *)param_1[2] = 0;
    }
    NvmofiWskRdmaCloseAdapter(*(longlong *)(*(longlong *)(*param_1 + 0x18) + 0x10));
    ExFreePoolWithTag(param_1[2],0x6352664e);
    param_1[2] = 0;
    uVar2 = 0;
  }
  return uVar2;
}



===== NvmofiWskRdmaFindOrOpenAdapter @ 14000af04 =====

int NvmofiWskRdmaFindOrOpenAdapter
              (longlong param_1,NET_IFINDEX param_2,undefined4 *param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)0x0;
  LOCK();
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
  UNLOCK();
  puVar4 = param_3;
  KeEnterCriticalRegion();
  lVar1 = param_1 + 0xd0;
  ExAcquirePushLockSharedEx(lVar1);
  if (*(longlong *)(param_1 + 0xc0) == 0) {
    ExReleasePushLockSharedEx(lVar1);
    KeLeaveCriticalRegion();
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1,0);
    if (*(longlong *)(param_1 + 0xc0) == 0) {
      iVar2 = KrdmaOpenAdapter(param_2,param_3,puVar4,param_4,&local_res8);
      if (iVar2 < 0) {
        ExReleasePushLockExclusiveEx(lVar1,0);
        KeLeaveCriticalRegion();
        LOCK();
        *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + -1;
        UNLOCK();
        puVar3 = local_res8;
      }
      else {
        if (*(longlong *)(param_1 + 0xc0) == 0) {
          *(undefined8 **)(param_1 + 0xc0) = local_res8;
          puVar3 = (undefined8 *)0x0;
        }
        else {
          puVar3 = local_res8;
        }
        ExReleasePushLockExclusiveEx(lVar1,0);
        KeLeaveCriticalRegion();
      }
      if (puVar3 != (undefined8 *)0x0) {
        KrdmaCloseAdapter(puVar3);
      }
      return iVar2;
    }
    ExReleasePushLockExclusiveEx(lVar1,0);
  }
  else {
    ExReleasePushLockSharedEx();
  }
  KeLeaveCriticalRegion();
  return 0;
}



===== NvmofiWskRdmaInitialize @ 14000b07c =====

int NvmofiWskRdmaInitialize(longlong *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 in_stack_fffffffffffffee8;
  undefined4 uVar4;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined1 local_48 [64];
  
  uVar4 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);
  lVar1 = *param_1;
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  memset(local_48,0,0x40);
  if (lVar1 == 0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    KrdmaDeviceObject = lVar1;
    iVar3 = KrdmaNdkInitialize();
    if (-1 < iVar3) {
      KeInitializeEvent(&local_68,0,0);
      KeInitializeDpc(local_48,KrdmaComputeDpcWatchdogLimitsDeferredRoutine,&local_68);
      KeSetImportanceDpc(local_48,2);
      KeInsertQueueDpc(local_48,0,0);
      KeWaitForSingleObject(&local_68,0,0,0,0);
      uVar2 = 1;
      goto LAB_14000b195;
    }
  }
  StorPortExtendedFunction
            (0x80,param_1,0,0,CONCAT44(uVar4,1),0x1f,L"KrdmaInitialize failure",0x200,1,0,
             L"NtStatus",(longlong)iVar3,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
  NvmofiWskCleanup((longlong)param_1,'\0');
  uVar2 = 0;
LAB_14000b195:
  *(undefined1 *)(param_1 + 10) = uVar2;
  return iVar3;
}



===== NvmofiWskRdmaIsSupported @ 14000b264 =====

bool NvmofiWskRdmaIsSupported
               (NET_IFINDEX param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *local_res18 [2];
  
  local_res18[0] = (undefined8 *)0x0;
  iVar1 = KrdmaOpenAdapter(param_1,param_2,param_3,param_4,local_res18);
  if (local_res18[0] != (undefined8 *)0x0) {
    KrdmaCloseAdapter(local_res18[0]);
  }
  return iVar1 == 0;
}



===== NvmofiWskRdmaPacketCompletion @ 14000b2a4 =====

void NvmofiWskRdmaPacketCompletion(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar1 = *(longlong **)(param_1 + 0x20);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(plVar1 + 0x3f,&local_28);
  *(int *)(plVar1 + 0x40) = (int)plVar1[0x40] + -1;
  if ((*(byte *)(param_1 + 0x28) & 0x10) != 0) {
    LOCK();
    *(int *)(plVar1 + 0x41) = (int)plVar1[0x41] + -1;
    UNLOCK();
  }
  plVar2 = (longlong *)plVar1[0x3d];
  KeReleaseInStackQueuedSpinLock(&local_28);
  NvmofiWskPacketPostCompletion(param_1,param_2);
  if (plVar2 != plVar1 + 0x3d) {
    iVar3 = NvmofiQueueWorkItem(*(undefined8 *)(*plVar1 + 0x10),NvmofiSendQueueNextPacket,plVar1);
    if (iVar3 != 0) {
      StorPortExtendedFunction
                (0x80,*(undefined8 *)(*plVar1 + 0x10),*(undefined8 *)(*plVar1 + 0xa0),0,1,0x1b,
                 L"QueueWorkItem failure - NvmofiSendQueueNextPacket",0x200,3,0,L"QueueId",
                 *(undefined2 *)((longlong)plVar1 + 0x26),L"StorStatus",iVar3,L"",0,L"",0,L"",0,L"",
                 0,L"",0,L"",0);
    }
  }
  return;
}



===== NvmofiWskRdmaReceiveCallback @ 14000b460 =====

void NvmofiWskRdmaReceiveCallback(undefined8 param_1,int *param_2,longlong *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  
  local_res10 = 0;
  iVar2 = StorPortNvmeofExtendedFunction
                    (7,*(undefined8 *)(*param_3 + 0x10),*(undefined8 *)(*param_3 + 0xa0),
                     *(undefined2 *)((longlong)param_3 + 0x26),(short)param_2[3],&local_res10);
  if ((iVar2 == 0) && (local_res10 != 0)) {
    lVar1 = *(longlong *)(local_res10 + 0x68);
    if (*(longlong *)(lVar1 + 0x20) != 0) {
      if ((*(byte *)(lVar1 + 8) & 2) != 0) {
        LOCK();
        *(int *)(param_3 + 0x41) = (int)param_3[0x41] + -1;
        UNLOCK();
      }
      KrdmaFreeBufferRegistration
                (*(longlong *)(*(longlong *)(*(longlong *)(*param_3 + 0x18) + 0x10) + 0xc0),
                 *(longlong **)(lVar1 + 0x20));
      *(undefined8 *)(lVar1 + 0x20) = 0;
    }
    NvmofiCompleteSrb(param_3,local_res10,param_2);
  }
  return;
}



===== NvmofiWskRdmaSend @ 14000b520 =====

int NvmofiWskRdmaSend(longlong param_1,undefined1 *param_2,ulonglong param_3)

{
  longlong *plVar1;
  int iVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x20);
  *param_2 = 0;
  if ((((longlong *)plVar1[2] == (longlong *)0x0) || (*(longlong *)plVar1[2] == 0)) ||
     ((*(byte *)(plVar1 + 1) & 4) != 0)) {
    iVar2 = -0x3ffffdf4;
  }
  else {
    iVar2 = NvmofiWskRdmaDispatchPacket(param_1,param_2,param_3);
    if (-1 < iVar2) {
      *param_2 = 1;
      return iVar2;
    }
  }
  StorPortExtendedFunction
            (0x80,NvmofiAdapterExtension,*(undefined8 *)(*plVar1 + 0xa0),0,1,0x17,
             L"NvmofiWskRdmaSend failure",0x200,2,0,L"NtStatus",(longlong)iVar2,L"",0,L"",0,L"",0,
             L"",0,L"",0,L"",0,L"",0);
  return iVar2;
}



===== KrdmaCloseAdapter @ 14000b664 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaCloseAdapter(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_1 != (undefined8 *)0x0) {
    while( true ) {
      lVar2 = ExpInterlockedPopEntrySList(param_1 + 0x20);
      if (lVar2 == 0) break;
      LOCK();
      *(int *)(param_1 + 0x26) = *(int *)(param_1 + 0x26) + -1;
      UNLOCK();
      (*(code *)param_1[0x24])(lVar2);
    }
    while( true ) {
      lVar2 = ExpInterlockedPopEntrySList(param_1 + 0x28);
      if (lVar2 == 0) break;
      LOCK();
      *(int *)(param_1 + 0x2e) = *(int *)(param_1 + 0x2e) + -1;
      UNLOCK();
      (*(code *)param_1[0x2c])(lVar2);
    }
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p WAITING at %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
               "KrdmaWaitForRundownProtectionRelease",0x455,param_1,*param_1);
    ExWaitForRundownProtectionRelease(param_1);
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p WAIT RELEASE at %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
               "KrdmaWaitForRundownProtectionRelease",0x457,param_1,*param_1);
    lVar2 = param_1[0x18];
    if (lVar2 != 0) {
      local_18 = 0;
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      uStack_20 = 0;
      KeInitializeEvent(&local_38,1,0);
      iVar1 = (*(code *)**(undefined8 **)(lVar2 + 0x28))
                        (lVar2,KrdmaNdkCloseFnCompletionCallback,&local_38);
      if (iVar1 == 0x103) {
        KeWaitForSingleObject(&local_38,0,0,0,0);
      }
      param_1[0x18] = 0;
    }
    if (param_1[0x13] != 0) {
      KrdmaNdkCloseProtectionDomain(param_1[0x13]);
      param_1[0x13] = 0;
    }
    if (param_1[0x14] != 0) {
      KrdmaNdkCloseQueuePair(param_1[0x14]);
      param_1[0x14] = 0;
    }
    if (param_1[0x12] != 0) {
      KrdmaNdkCloseAdapter(param_1[0x12]);
      param_1[0x12] = 0;
    }
    if (param_1[1] != 0) {
      ExFreePoolWithTag(param_1[1],0x20204b50);
    }
    param_1[1] = 0;
    ExFreePoolWithTag(param_1,0x20204b50);
  }
  return;
}



===== KrdmaCloseSocket @ 14000b880 =====

void KrdmaCloseSocket(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined4 uVar3;
  undefined8 uVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Closing Socket\n",
               "onecore\\drivers\\storage\\krdma\\krdma.c","KrdmaCloseSocket",0x2c1,param_1,
               *(undefined4 *)(param_1 + 1),*(undefined4 *)((longlong)param_1 + 0x84));
    KrdmaInternalDisconnect((longlong)param_1);
    puVar1 = param_1 + 0x1a;
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p WAITING at %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
               "KrdmaWaitForRundownProtectionRelease",0x455,puVar1,*puVar1);
    ExWaitForRundownProtectionRelease(puVar1);
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p WAIT RELEASE at %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
               "KrdmaWaitForRundownProtectionRelease",0x457,puVar1,*puVar1);
    puVar1 = param_1 + 0x1b;
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p WAITING at %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
               "KrdmaWaitForRundownProtectionRelease",0x455,puVar1,*puVar1);
    ExWaitForRundownProtectionRelease(puVar1);
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p WAIT RELEASE at %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
               "KrdmaWaitForRundownProtectionRelease",0x457,puVar1,*puVar1);
    if (param_1[0x2c] != 0) {
      ExFreePoolWithTag(param_1[0x2c],0x20734b50);
    }
    param_1[0x2c] = 0;
    if (param_1[0x21] != 0) {
      ExFreePoolWithTag(param_1[0x21],0x20734b50);
    }
    param_1[0x21] = 0;
    KrdmaNdkCloseQueuePair(param_1[0x18]);
    param_1[0x18] = 0;
    KrdmaNdkCloseQueuePair(param_1[0x28]);
    param_1[0x28] = 0;
    KrdmaNdkCloseQueuePair(param_1[0x20]);
    param_1[0x20] = 0;
    IoFreeWorkItem(param_1[10]);
    param_1[10] = 0;
    IoFreeWorkItem(param_1[0xb]);
    param_1[0xb] = 0;
    IoFreeWorkItem(param_1[0xd]);
    param_1[0xd] = 0;
    IoFreeWorkItem(param_1[0xc]);
    puVar1 = (undefined8 *)*param_1;
    param_1[0xc] = 0;
    uVar2 = *puVar1;
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection",
               0x448,puVar1,uVar2);
    uVar3 = (undefined4)((ulonglong)uVar2 >> 0x20);
    ExReleaseRundownProtection(puVar1);
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Socket closed. Releasing memory next\n",
               "onecore\\drivers\\storage\\krdma\\krdma.c","KrdmaCloseSocket",0x2e4,param_1,
               CONCAT44(uVar3,*(undefined4 *)(param_1 + 1)),
               *(undefined4 *)((longlong)param_1 + 0x84));
    ExFreePoolWithTag(param_1,0x20204b50);
  }
  return;
}



===== KrdmaComputeDpcWatchdogLimitsDeferredRoutine @ 14000bbd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void KrdmaComputeDpcWatchdogLimitsDeferredRoutine(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  if (param_2 != 0) {
    local_10 = __security_cookie ^ (ulonglong)auStack_48;
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    iVar1 = KeQueryDpcWatchdogInformation(&local_28);
    if (-1 < iVar1) {
      KrdmaCqNotificationMinDpcWatchdogCount = (uint)((int)uStack_20 * 0x28) / 100;
    }
    KeSetEvent(param_2,0,0);
  }
  return;
}



===== KrdmaCreateSocket @ 14000bc58 =====

int KrdmaCreateSocket(undefined8 *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                     undefined2 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 in_stack_ffffffffffffffa0;
  longlong *plVar6;
  undefined4 uVar8;
  undefined8 uVar7;
  undefined8 *puVar9;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  local_38 = 1;
  uStack_30 = 0x10;
  *param_8 = 0;
  plVar4 = (longlong *)ExAllocatePool3(0x48,0x180,0x20734b50,&local_38,1);
  if (plVar4 == (longlong *)0x0) {
    return -0x3fffff66;
  }
  *(undefined4 *)((longlong)plVar4 + 0x84) = 0;
  if (param_5 != (undefined2 *)0x0) {
    *(undefined2 *)(plVar4 + 0x10) = *param_5;
  }
  uVar7 = KrdmaDeviceObject;
  plVar1 = plVar4 + 2;
  plVar4[3] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  lVar5 = IoAllocateWorkItem(uVar7);
  plVar4[10] = lVar5;
  if (lVar5 != 0) {
    lVar5 = IoAllocateWorkItem(KrdmaDeviceObject);
    plVar4[0xb] = lVar5;
    if (lVar5 != 0) {
      lVar5 = IoAllocateWorkItem(KrdmaDeviceObject);
      plVar4[0xd] = lVar5;
      if (lVar5 != 0) {
        lVar5 = IoAllocateWorkItem(KrdmaDeviceObject);
        plVar4[0xc] = lVar5;
        if (lVar5 != 0) {
          uVar7 = *param_1;
          puVar9 = param_1;
          DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p acquired %I64x \n\n",
                     "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
                     "KrdmaAcquireRundownProtection",CONCAT44(uVar8,0x43a));
          ExAcquireRundownProtection(param_1);
          *plVar4 = (longlong)param_1;
          *(undefined4 *)(plVar4 + 0x1c) = *(undefined4 *)(param_1 + 0x15);
          uVar8 = *(undefined4 *)((longlong)param_1 + 0xb4);
          *(undefined4 *)(plVar4 + 0xe) = uVar8;
          iVar3 = KrdmaNdkCreateCompletionQueue
                            (param_1[0x12],uVar8,KrdmaNdkRcqNotificationEventCallback,plVar4,param_6
                             ,plVar4 + 0x28);
          if (iVar3 < 0) goto LAB_14000bd13;
          plVar1 = plVar4 + 0x20;
          uVar8 = *(undefined4 *)(*plVar4 + 0xb8);
          *(undefined4 *)((longlong)plVar4 + 0x74) = uVar8;
          plVar6 = plVar1;
          iVar3 = KrdmaNdkCreateCompletionQueue
                            (*(longlong *)(*plVar4 + 0x90),uVar8,
                             KrdmaNdkScqNotificationEventCallback,plVar4,param_7,plVar1);
          if (iVar3 < 0) goto LAB_14000bd13;
          lVar5 = *plVar4;
          lVar2 = plVar4[0x28];
          uVar8 = (undefined4)((ulonglong)plVar6 >> 0x20);
          if (*(longlong *)(lVar5 + 0xc0) == 0) {
            iVar3 = KrdmaNdkCreateQueuePair
                              (*(longlong *)(lVar5 + 0x98),lVar2,*plVar1,plVar4,(int)plVar4[0xe],
                               *(undefined4 *)((longlong)plVar4 + 0x74),puVar9,uVar7,
                               *(undefined4 *)(lVar5 + 0x5c),plVar4 + 0x18);
          }
          else {
            iVar3 = KrdmaNdkCreateQueuePairWithSrq
                              (*(longlong *)(lVar5 + 0x98),lVar2,*plVar1,*(longlong *)(lVar5 + 0xc0)
                               ,plVar4,*(undefined4 *)((longlong)plVar4 + 0x74),puVar9,
                               *(undefined4 *)(lVar5 + 0x5c),plVar4 + 0x18);
          }
          if (iVar3 < 0) goto LAB_14000bd13;
          local_28 = 1;
          uStack_20 = 0x10;
          lVar5 = ExAllocatePool3(0x40,0xc00,0x20734b50,&local_28,1);
          plVar4[0x2c] = lVar5;
          if (lVar5 != 0) {
            local_28 = 1;
            uStack_20 = 0x10;
            lVar5 = ExAllocatePool3(0x40,0xc00,0x20734b50,&local_28,1);
            plVar4[0x21] = lVar5;
            if (lVar5 != 0) {
              iVar3 = KrdmaNdkCreateConnector(*(longlong *)(*plVar4 + 0x90),plVar4 + 0x19);
              if (-1 < iVar3) {
                plVar4[0x2a] = param_4;
                plVar4[0x11] = (longlong)NvmofiWskRdmaDisconnectCallback;
                plVar4[0x2b] = (longlong)NvmofiWskRdmaReceiveCallback;
                plVar4[0x29] = (longlong)KrdmaPreEnableReceiveRcqCompletionProcessor;
                InitializeSListHead((PSLIST_HEADER)(plVar4 + 0x24));
                plVar4[0x26] = 0;
                *(undefined4 *)(plVar4 + 0x27) = 0;
                *(undefined4 *)(plVar4 + 0x13) = 0;
                *(undefined4 *)((longlong)plVar4 + 0x9c) = 0;
                uVar7 = CONCAT44(uVar8,0x42c);
                DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p initialized \n\n",
                           "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
                           "KrdmaInitializeRundownProtection",uVar7,plVar4 + 0x1a);
                uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
                ExInitializeRundownProtection(plVar4 + 0x1a);
                DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p initialized \n\n",
                           "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
                           "KrdmaInitializeRundownProtection",CONCAT44(uVar8,0x42c),plVar4 + 0x1b);
                ExInitializeRundownProtection(plVar4 + 0x1b);
                *(undefined4 *)((longlong)plVar4 + 0x84) = 1;
                *param_8 = plVar4;
                return 0;
              }
              goto LAB_14000bd13;
            }
          }
        }
      }
    }
  }
  iVar3 = -0x3fffff66;
LAB_14000bd13:
  KrdmaCloseSocket(plVar4);
  return iVar3;
}



===== KrdmaOpenAdapter @ 14000c0b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaOpenAdapter(NET_IFINDEX param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 *param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 *_Dst;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  code *pcVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  undefined4 uVar14;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar15;
  NET_LUID local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  local_58.Value = 0;
  uVar12 = (ulonglong)param_1;
  uVar11 = 1;
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Open adapter at index %u\n",
             "onecore\\drivers\\storage\\krdma\\krdma.c","KrdmaOpenAdapter",0xd8,uVar12);
  local_50 = 1;
  *param_5 = 0;
  uStack_48 = 0x10;
  _Dst = (undefined8 *)ExAllocatePool3(0x48,0x180,0x20204b50,&local_50,CONCAT44(uVar11,1));
  if (_Dst == (undefined8 *)0x0) {
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u AllocateWithPoolTag returned NULL\n",
               "onecore\\drivers\\storage\\krdma\\krdma.c","KrdmaOpenAdapter",0xe6,uVar12);
    return -0x3fffff66;
  }
  memset(_Dst,0,0x180);
  uVar11 = 1;
  puVar13 = _Dst;
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p initialized \n\n",
             "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaInitializeRundownProtection",
             0x42c,_Dst);
  uVar14 = (undefined4)((ulonglong)puVar13 >> 0x20);
  ExInitializeRundownProtection(_Dst);
  plVar1 = _Dst + 0x12;
  *(NET_IFINDEX *)(_Dst + 2) = param_1;
  iVar5 = KrdmaNdkOpenAdapter(param_1,plVar1);
  if (iVar5 < 0) {
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Failed to open NDK adapter index:%x, error:%x\n",
               "onecore\\drivers\\storage\\krdma\\krdma.c","KrdmaOpenAdapter",0xf2,
               CONCAT44(uVar14,param_1),CONCAT44(uVar15,iVar5));
  }
  else {
    iVar5 = KrdmaNdkQueryAdapterInfo(*plVar1,_Dst + 5);
    if (-1 < iVar5) {
      uVar15 = param_2[1];
      uVar14 = param_2[2];
      uVar4 = param_2[3];
      local_40 = 1;
      uStack_38 = 0x10;
      *(undefined4 *)((longlong)_Dst + 0x14) = *param_2;
      *(undefined4 *)(_Dst + 3) = uVar15;
      *(undefined4 *)((longlong)_Dst + 0x1c) = uVar14;
      *(undefined4 *)(_Dst + 4) = uVar4;
      lVar6 = ExAllocatePool3(0x40,0x202,0x20204b50,&local_40,CONCAT44(uVar11,1));
      _Dst[1] = lVar6;
      if (lVar6 == 0) {
        iVar5 = -0x3fffff66;
      }
      else {
        iVar5 = ConvertInterfaceIndexToLuid(param_1,&local_58);
        if ((-1 < iVar5) &&
           (iVar5 = ConvertInterfaceLuidToAlias(&local_58,(PWSTR)_Dst[1],0x101), -1 < iVar5)) {
          plVar2 = _Dst + 0x13;
          iVar5 = KrdmaNdkCreateProtectionDomain(*plVar1,plVar2);
          if (iVar5 < 0) {
            pcVar9 = "%s:%s:%u Failed to create protection domain error:%x\n";
            uVar11 = 0x125;
          }
          else {
            (**(code **)(*(longlong *)(*plVar2 + 0x28) + 0x38))(*plVar2,_Dst + 0x15);
            iVar5 = InitializeResourcePool
                              ((PSLIST_HEADER)(_Dst + 0x28),KrdmaLAMPoolAllocateFn,0x14000e530,_Dst)
            ;
            if (-1 < iVar5) {
              pcVar10 = KrdmaFRMRFreeFn;
              iVar5 = InitializeResourcePool
                                ((PSLIST_HEADER)(_Dst + 0x20),KrdmaFRMRAllocateFn,0x14000e4d0,_Dst);
              if ((-1 < iVar5) &&
                 (iVar5 = KrdmaNdkCreateSharedEndpoint
                                    (*plVar1,(longlong)_Dst + 0x14,pcVar10,_Dst + 0x14), -1 < iVar5)
                 ) {
                uVar8 = 0x100;
                if (*(uint *)(_Dst + 0xd) < 0x100) {
                  uVar8 = *(uint *)(_Dst + 0xd);
                }
                *(uint *)((longlong)_Dst + 0xb4) = uVar8;
                uVar7 = 0x100;
                if (*(uint *)((longlong)_Dst + 0x6c) < 0x100) {
                  uVar7 = *(uint *)((longlong)_Dst + 0x6c);
                }
                uVar3 = *(uint *)(_Dst + 0xe);
                *(uint *)(_Dst + 0x17) = uVar7;
                if (uVar3 == 0) {
LAB_14000c482:
                  *param_5 = _Dst;
                  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u KRDMA initialized on interface index :%x\n",
                             "onecore\\drivers\\storage\\krdma\\krdma.c","KrdmaOpenAdapter",0x189,
                             param_1);
                  return iVar5;
                }
                uVar7 = uVar8 << 2;
                if (uVar3 <= uVar8 << 2) {
                  uVar7 = uVar3;
                }
                *(uint *)((longlong)_Dst + 0xd4) = uVar7;
                iVar5 = KrdmaNdkCreateSharedReceiveQueue(*plVar2,uVar7);
                if (-1 < iVar5) {
                  KeInitializeSpinLock(_Dst + 0x19);
                  iVar5 = KrdmaAllocateAndPostSharedReceives((longlong)_Dst);
                  if (-1 < iVar5) goto LAB_14000c482;
                }
              }
              goto LAB_14000c249;
            }
            pcVar9 = "%s:%s:%u Failed to initialize LAM Pool error:%x\n";
            uVar11 = 0x137;
          }
          DbgPrintEx(0x50,0xfffffffe,pcVar9,"onecore\\drivers\\storage\\krdma\\krdma.c",
                     "KrdmaOpenAdapter",uVar11,iVar5);
        }
      }
    }
  }
LAB_14000c249:
  KrdmaCloseAdapter(_Dst);
  return iVar5;
}



===== KrdmaUninitialize @ 14000c4c8 =====

void KrdmaUninitialize(void)

{
  KrdmaNdkUninitialize();
  return;
}



===== KrdmaFreeBufferRegistration @ 14000c4e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaFreeBufferRegistration(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  if (param_2 != (longlong *)0x0) {
    if (*param_2 != 0) {
      ExpInterlockedPushEntrySList(param_1 + 0x100);
      LOCK();
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + -1;
      UNLOCK();
      *param_2 = 0;
    }
    lVar1 = param_2[1];
    if (lVar1 != 0) {
      if ((*(byte *)(lVar1 + 0x24) & 2) != 0) {
        (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x40))
                  (*(longlong *)(lVar1 + 8),*(undefined8 *)(lVar1 + 0x10));
      }
      if (((*(byte *)(lVar1 + 0x24) & 1) != 0) && (*(longlong *)(lVar1 + 0x10) != 0)) {
        ExFreePoolWithTag(*(longlong *)(lVar1 + 0x10),0x20204b50);
      }
      ExFreePoolWithTag(lVar1,0x20204b50);
      param_2[1] = 0;
    }
    ExFreePoolWithTag(param_2,0x20734b50);
  }
  return;
}



===== KrdmaFreeWQE @ 14000c5a0 =====

void KrdmaFreeWQE(longlong param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) == 2) {
      KrdmaFreeBufferRegistration(**(longlong **)(param_1 + 0x28),*(longlong **)(param_1 + 0x40));
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
    ExFreePoolWithTag(param_1,0x20734b50);
  }
  return;
}



===== KrdmaNdkScqNotificationEventCallback @ 14000c5f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkScqNotificationEventCallback(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStack_68 [32];
  char *local_48;
  undefined4 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  if (-1 < param_2) {
    local_10 = __security_cookie ^ (ulonglong)auStack_68;
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    if (param_1 != 0) {
      puVar1 = (undefined8 *)(param_1 + 0xd0);
      local_30 = *puVar1;
      local_40 = 0x43a;
      local_48 = "KrdmaAcquireRundownProtection";
      local_38 = puVar1;
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p acquired %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h");
      ExAcquireRundownProtection(puVar1);
      iVar3 = KeQueryDpcWatchdogInformation(&local_28);
      if ((((iVar3 < 0) || (KrdmaCqNotificationMinDpcWatchdogCount == 0)) ||
          (uStack_20._4_4_ <= KrdmaCqNotificationMinDpcWatchdogCount)) ||
         (bVar2 = KrdmaProcessBatchScqCompletions(param_1,0x40), !bVar2)) {
        (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x100) + 0x28) + 0x18))
                  (*(longlong *)(param_1 + 0x100),1);
        local_30 = *puVar1;
        local_40 = 0x448;
        local_48 = "KrdmaReleaseRundownProtection";
        local_38 = puVar1;
        DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
                   "onecore\\drivers\\storage\\krdma\\krdmainternal.h");
        ExReleaseRundownProtection(puVar1);
      }
      else {
        local_48 = (char *)CONCAT44(local_48._4_4_,(uint)*(ushort *)(param_1 + 0x80));
        IoQueueWorkItemToNode
                  (*(undefined8 *)(param_1 + 0x50),KrdmaProcessScqCompletionsIoWorkItemRoutine,0,
                   param_1);
      }
    }
  }
  return;
}



===== KrdmaProcessBatchScqCompletions @ 14000c774 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool KrdmaProcessBatchScqCompletions(longlong param_1,uint param_2)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  bVar5 = false;
  *(undefined1 *)(param_1 + 0x79) = 1;
  iVar8 = 0;
  plVar1 = (longlong *)(param_1 + 0x108);
  uVar7 = 0;
  do {
    uVar6 = *(uint *)(param_1 + 0x110);
    if (uVar6 <= *(uint *)(param_1 + 0x114)) {
      *(undefined4 *)(param_1 + 0x114) = 0;
      uVar6 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x100) + 0x28) + 0x20))
                        (*(longlong *)(param_1 + 0x100),*plVar1,param_2);
      *(uint *)(param_1 + 0x110) = uVar6;
      if (uVar6 == 0) {
LAB_14000c8cf:
        *(undefined1 *)(param_1 + 0x79) = 0;
        return *(uint *)(param_1 + 0x114) < uVar6;
      }
    }
    if (param_2 <= uVar7) goto LAB_14000c8cf;
    lVar4 = *(longlong *)(*plVar1 + 0x10 + (ulonglong)*(uint *)(param_1 + 0x114) * 0x18);
    if ((*(uint *)(lVar4 + 0x30) & 1) == 0) {
      LOCK();
      piVar2 = (int *)(param_1 + 0x130 + (longlong)*(int *)(lVar4 + 8) * 4);
      iVar8 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      iVar8 = iVar8 + -1;
    }
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Completing Wqe 0x%p, Type: %u, Context: %p Count: %u\n"
               ,"onecore\\drivers\\storage\\krdma\\send.c","KrdmaProcessBatchScqCompletions",0xf4,
               param_1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84),lVar4,
               *(undefined4 *)(lVar4 + 8),*(undefined8 *)(lVar4 + 0x10),iVar8);
    iVar3 = *(int *)(*plVar1 + (ulonglong)*(uint *)(param_1 + 0x114) * 0x18);
    if ((iVar3 < 0) && (!bVar5)) {
      bVar5 = true;
      KrdmaInternalDisconnect(param_1);
    }
    (**(code **)(lVar4 + 0x18))(iVar3,*(undefined8 *)(lVar4 + 0x20),*(undefined8 *)(lVar4 + 0x10));
    KrdmaFreeWQE(lVar4);
    *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
    uVar7 = uVar7 + 1;
  } while( true );
}



===== KrdmaProcessScqCompletionsIoWorkItemRoutine @ 14000c910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaProcessScqCompletionsIoWorkItemRoutine(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  undefined8 *puVar2;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  if (param_2 != 0) {
    bVar1 = KrdmaProcessBatchScqCompletions(param_2,0x80);
    if (bVar1) {
      IoQueueWorkItemToNode
                (*(undefined8 *)(param_2 + 0x50),KrdmaProcessScqCompletionsIoWorkItemRoutine,0,
                 param_2,CONCAT44(uVar3,(uint)*(ushort *)(param_2 + 0x80)));
    }
    else {
      (**(code **)(*(longlong *)(*(longlong *)(param_2 + 0x100) + 0x28) + 0x18))
                (*(longlong *)(param_2 + 0x100),1);
      puVar2 = (undefined8 *)(param_2 + 0xd0);
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection"
                 ,0x448,puVar2,*puVar2);
      ExReleaseRundownProtection(puVar2);
    }
  }
  return;
}



===== KrdmaSocketDispatchNDKIO @ 14000c9e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaSocketDispatchNDKIO(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar10;
  longlong lVar9;
  
  piVar1 = (int *)(param_2 + 8);
  iVar3 = 0;
  iVar4 = 0;
  if ((*(uint *)(param_2 + 0x30) & 1) == 0) {
    LOCK();
    piVar5 = (int *)(param_1 + 0x130 + (longlong)*piVar1 * 4);
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + 1;
    UNLOCK();
    iVar4 = iVar4 + 1;
  }
  uVar7 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20),*(undefined4 *)(param_1 + 8))
  ;
  uVar6 = 1;
  lVar9 = param_2;
  DbgPrintEx(0x50,0xfffffffe,
             "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Dispatching Wqe 0x%p, Type: %u, Count: %u\n",
             "onecore\\drivers\\storage\\krdma\\send.c","KrdmaSocketDispatchNDKIO",0x30c,param_1,
             uVar7,*(undefined4 *)(param_1 + 0x84),param_2,*piVar1,iVar4);
  uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar10 = (undefined4)((ulonglong)lVar9 >> 0x20);
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    iVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xc0) + 0x28) + 0x18))
                      (*(longlong *)(param_1 + 0xc0),param_2,param_2 + 0x40,
                       *(undefined4 *)(param_2 + 0x38),
                       CONCAT44(uVar6,*(undefined4 *)(param_2 + 0x30)));
  }
  else if (iVar2 == 1) {
    uVar7 = *(undefined8 *)(param_2 + 0x48);
    iVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xc0) + 0x28) + 0x30))
                      (*(longlong *)(param_1 + 0xc0),param_2,*(undefined8 *)(param_2 + 0x38),
                       *(undefined4 *)(param_2 + 0x58),*(undefined8 *)(param_2 + 0x40),
                       *(undefined4 *)(param_2 + 0x5c),*(undefined8 *)(param_2 + 0x50),uVar7,
                       *(undefined4 *)(param_2 + 0x30));
    uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
  }
  else {
    if (iVar2 != 2) goto LAB_14000cb99;
    iVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xc0) + 0x28) + 0x38))
                      (*(longlong *)(param_1 + 0xc0),param_2,*(undefined8 *)(param_2 + 0x38),
                       *(undefined4 *)(param_2 + 0x30));
  }
  if (iVar3 < 0) {
    if ((*(uint *)(param_2 + 0x30) & 1) == 0) {
      piVar5 = (int *)(longlong)*(int *)(param_1 + 0x130 + (longlong)*piVar1 * 4);
      LOCK();
      *piVar5 = *piVar5 + -1;
      UNLOCK();
    }
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Ndk Dispatch of Type:%u Failed with status:%x\n",
               "onecore\\drivers\\storage\\krdma\\send.c","KrdmaSocketDispatchNDKIO",0x33c,param_1,
               CONCAT44(uVar8,*(undefined4 *)(param_1 + 8)),*(undefined4 *)(param_1 + 0x84),
               CONCAT44(uVar10,*piVar1),iVar3,iVar4);
    KrdmaInternalDisconnect(param_1);
    return iVar3;
  }
LAB_14000cb99:
  DbgPrintEx(0x50,0xfffffffe,
             "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Ndk Dispatch of Type:%u succeeded with status:%x\n",
             "onecore\\drivers\\storage\\krdma\\send.c","KrdmaSocketDispatchNDKIO",0x346,param_1,
             CONCAT44(uVar8,*(undefined4 *)(param_1 + 8)),*(undefined4 *)(param_1 + 0x84),
             CONCAT44(uVar10,*piVar1),iVar3,iVar4);
  return 0x103;
}



===== KrdmaSocketFastRegisterMDL @ 14000cc18 =====

int KrdmaSocketFastRegisterMDL
              (longlong *param_1,longlong param_2,uint param_3,char param_4,undefined8 param_5,
              undefined8 param_6,undefined8 *param_7,undefined8 param_8,undefined8 param_9)

{
  longlong *plVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong *plVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  puVar4 = param_7;
  uVar7 = 0;
  *param_7 = 0;
  local_48 = 1;
  uStack_40 = 0x10;
  plVar6 = (longlong *)ExAllocatePool3(0x48,0x20,0x20734b50,&local_48,1);
  param_7 = (undefined8 *)0x0;
  KrdmaAllocateFromResourcePool(*param_1 + 0x100,(longlong *)&param_7);
  *plVar6 = (longlong)param_7;
  if (param_7 != (undefined8 *)0x0) {
    plVar1 = plVar6 + 1;
    iVar5 = KrdmaAllocateLam(param_2,param_3,plVar1);
    if ((iVar5 < 0) ||
       (iVar5 = KrdmaBuildLam(*(longlong *)(*param_1 + 0x90),param_2,param_3,*plVar1), iVar5 < 0))
    goto LAB_14000ce11;
    local_38 = 1;
    uStack_30 = 0x10;
    uVar7 = ExAllocatePool3(0x48,0x80,0x20734b50,&local_38,1);
    if (uVar7 != 0) {
      *(undefined8 *)(uVar7 + 0x20) = 0;
      *(undefined4 *)(uVar7 + 8) = 1;
      *(undefined8 *)(uVar7 + 0x10) = param_9;
      *(code **)(uVar7 + 0x18) = _guard_check_icall;
      *(longlong **)(uVar7 + 0x28) = param_1;
      uVar8 = *(uint *)(uVar7 + 0x30) | 8;
      if (param_4 == '\0') {
        uVar8 = *(uint *)(uVar7 + 0x30) | 0x30;
      }
      *(uint *)(uVar7 + 0x30) = uVar8 | 0x201;
      uVar2 = *(undefined4 *)(*(longlong *)(*plVar1 + 0x10) + 8);
      uVar3 = *(ulonglong *)(*plVar6 + 0x10);
      *(ulonglong *)(uVar7 + 0x38) = uVar3;
      lVar10 = *(longlong *)(*plVar1 + 0x10);
      *(undefined4 *)(uVar7 + 0x58) = uVar2;
      uVar9 = lVar10 + 0x10;
      *(ulonglong *)(uVar7 + 0x40) = uVar9;
      uVar8 = *(uint *)(*plVar1 + 0x1c);
      *(ulonglong *)(uVar7 + 0x50) = (ulonglong)param_3;
      lVar10 = ((uVar9 ^ uVar3 ^ uVar7) & 0x7ffffffffffff) * 0x1000 + (ulonglong)uVar8;
      *(longlong *)(uVar7 + 0x48) = lVar10;
      *(undefined4 *)(uVar7 + 0x5c) = *(undefined4 *)(*plVar1 + 0x1c);
      *(longlong *)(*plVar6 + 0x20) = lVar10;
      *puVar4 = plVar6;
      iVar5 = KrdmaSocketPostSQWQE((longlong)param_1,uVar7);
      if ((*(uint *)(uVar7 + 0x30) & 1) != 0) {
        KrdmaFreeWQE(uVar7);
        uVar7 = 0;
      }
      if (-1 < iVar5) {
        return iVar5;
      }
      goto LAB_14000ce11;
    }
  }
  iVar5 = -0x3fffff66;
LAB_14000ce11:
  KrdmaFreeBufferRegistration(*param_1,plVar6);
  if (uVar7 != 0) {
    KrdmaFreeWQE(uVar7);
  }
  *puVar4 = 0;
  return iVar5;
}



===== KrdmaSocketPostSQWQE @ 14000ce58 =====

int KrdmaSocketPostSQWQE(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x20,&local_28);
  if (*(int *)(param_1 + 0x84) == 3) {
    iVar1 = KrdmaSocketDispatchNDKIO(param_1,param_2);
  }
  else {
    iVar1 = -0x3ffffdf4;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return iVar1;
}



===== KrdmaSocketSendLAMBuffer @ 14000ced8 =====

int KrdmaSocketSendLAMBuffer
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar6 = 0;
  if ((param_1 == 0) || ((param_2 != 0 && (0x4000 < *(uint *)(param_2 + 0x10))))) {
    iVar4 = -0x3ffffff3;
  }
  else {
    local_28 = 1;
    uStack_20 = 0x10;
    lVar5 = ExAllocatePool3(0x48,0x80,0x20734b50,&local_28,1);
    if (lVar5 == 0) {
      iVar4 = -0x3fffff66;
    }
    else {
      *(undefined4 *)(lVar5 + 8) = 0;
      *(undefined8 *)(lVar5 + 0x20) = 0;
      *(undefined4 *)(lVar5 + 0x30) = 0;
      *(undefined8 *)(lVar5 + 0x10) = param_4;
      *(code **)(lVar5 + 0x18) = NvmofiRdmaSendCompletionCallback;
      *(longlong *)(lVar5 + 0x28) = param_1;
      if (param_2 != 0) {
        uVar7 = *(uint *)(param_2 + 0x10);
        uVar2 = 0;
        while (uVar7 != 0) {
          lVar1 = uVar2 + 4;
          if ((int)uVar2 == 0) {
            uVar8 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x18) + 0x1c);
          }
          else {
            uVar8 = 0;
          }
          *(undefined4 *)(lVar5 + 0xc + lVar1 * 0x10) =
               *(undefined4 *)(param_2 + 0x2c + uVar2 * 0x10);
          *(ulonglong *)(lVar5 + lVar1 * 0x10) =
               uVar8 + *(longlong *)
                        (*(longlong *)(*(longlong *)(param_2 + 0x18) + 0x10) + 0x10 + uVar2 * 8);
          uVar3 = uVar7;
          if (0x1000 < uVar7) {
            uVar3 = 0x1000;
          }
          uVar6 = (int)uVar2 + 1;
          *(uint *)(lVar5 + 8 + lVar1 * 0x10) = uVar3;
          uVar7 = uVar7 - *(int *)(lVar5 + 0x48 + uVar2 * 0x10);
          uVar2 = (ulonglong)uVar6;
        }
      }
      *(uint *)(lVar5 + 0x38) = uVar6;
      iVar4 = KrdmaSocketPostSQWQE(param_1,lVar5);
      if (iVar4 == 0x103) {
        return 0x103;
      }
      ExFreePoolWithTag(lVar5,0x20734b50);
    }
  }
  return iVar4;
}



===== KrdmaAllocateLam @ 14000d044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 KrdmaAllocateLam(longlong param_1,uint param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_3 = 0;
  uStack_30 = 0x10;
  local_38 = 1;
  lVar1 = ExAllocatePool3(0x48,0x58,0x20204b50,&local_38,1);
  if (lVar1 == 0) {
    return 0xc000009a;
  }
  *(undefined4 *)(lVar1 + 0x18) = 0x30;
  *(longlong *)(lVar1 + 0x10) = lVar1 + 0x28;
  *(undefined2 *)(lVar1 + 0x24) = 0;
  uVar3 = (uint)((ulonglong)param_2 + 0xfff +
                 (ulonglong)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x20) & 0xfff) >> 0xc);
  if (uVar3 < 5) {
LAB_14000d15e:
    *param_3 = lVar1;
    return 0;
  }
  uVar4 = (ulonglong)(uVar3 - 1) * 8;
  if (uVar4 < 0x100000000) {
    uVar3 = (int)uVar4 + 0x18;
    if (0x17 < uVar3) {
      *(uint *)(lVar1 + 0x18) = uVar3;
      local_28 = 1;
      uStack_20 = 0x10;
      lVar2 = ExAllocatePool3(0x48,uVar3,0x20204b50,&local_28,1);
      *(longlong *)(lVar1 + 0x10) = lVar2;
      if (lVar2 != 0) {
        *(ushort *)(lVar1 + 0x24) = *(ushort *)(lVar1 + 0x24) | 1;
        goto LAB_14000d15e;
      }
      uVar5 = 0xc000009a;
      goto LAB_14000d18b;
    }
    *(undefined4 *)(lVar1 + 0x18) = 0xffffffff;
  }
  uVar5 = 0xc0000095;
LAB_14000d18b:
  if ((*(byte *)(lVar1 + 0x24) & 2) != 0) {
    (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x40))
              (*(longlong *)(lVar1 + 8),*(undefined8 *)(lVar1 + 0x10));
  }
  if (((*(byte *)(lVar1 + 0x24) & 1) != 0) && (*(longlong *)(lVar1 + 0x10) != 0)) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x10),0x20204b50);
  }
  ExFreePoolWithTag(lVar1,0x20204b50);
  return uVar5;
}



===== KrdmaAllocateLamBuffer @ 14000d1f0 =====

int KrdmaAllocateLamBuffer(longlong param_1,uint param_2,undefined8 param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_4 = 0;
  local_28 = 1;
  uStack_20 = 0x10;
  lVar2 = ExAllocatePool3(0x48,0x4060,0x20724b50,&local_28,1);
  if (lVar2 != 0) {
    *param_4 = lVar2 + 0x4000;
    *(longlong *)(lVar2 + 0x4008) = lVar2;
    *(undefined4 *)(*param_4 + 0x14) = 0x4000;
    lVar3 = IoAllocateMdl(*(undefined8 *)(*param_4 + 8),*(undefined4 *)(*param_4 + 0x14),0,0,0);
    if (lVar3 != 0) {
      MmBuildMdlForNonPagedPool(lVar3);
      iVar1 = KrdmaAllocateLam(lVar3,0x4000,(longlong *)(*param_4 + 0x18));
      if (-1 < iVar1) {
        uVar4 = 0x4000;
        iVar1 = KrdmaBuildLam(param_1,lVar3,0x4000,*(longlong *)(*param_4 + 0x18));
        if (-1 < iVar1) {
          uVar4 = KrdmaInitializeSglForLam
                            (*(longlong *)(*param_4 + 0x18),param_2,uVar4,
                             (longlong *)(*param_4 + 0x20));
          iVar1 = (int)uVar4;
        }
      }
      IoFreeMdl(lVar3);
      if (-1 < iVar1) {
        return iVar1;
      }
      goto LAB_14000d310;
    }
  }
  iVar1 = -0x3fffff66;
LAB_14000d310:
  if (*param_4 == 0) {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0x20724b50);
    }
  }
  else {
    KrdmaFreeLamBuffer(*param_4);
    *param_4 = 0;
  }
  return iVar1;
}



===== KrdmaBuildLam @ 14000d360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaBuildLam(longlong param_1,undefined8 param_2,undefined4 param_3,longlong param_4)

{
  int iVar1;
  undefined4 local_res18 [4];
  
  local_res18[0] = *(undefined4 *)(param_4 + 0x18);
  *(longlong *)(param_4 + 8) = param_1;
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x38))
                    (param_1,param_2,param_3,KrdmaNdkBuildLamAsyncCompletion,0,
                     *(undefined8 *)(param_4 + 0x10),local_res18,param_4 + 0x1c);
  if (iVar1 == 0x103) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x54,"onecore\\drivers\\storage\\krdma\\ndkutil.c",0x734,0,0);
  }
  if (-1 < iVar1) {
    *(ushort *)(param_4 + 0x24) = *(ushort *)(param_4 + 0x24) | 2;
    *(undefined4 *)(param_4 + 0x20) = param_3;
  }
  return;
}



===== KrdmaFreeLamBuffer @ 14000d404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaFreeLamBuffer(longlong param_1)

{
  longlong lVar1;
  
  if (param_1 != 0) {
    lVar1 = *(longlong *)(param_1 + 0x18);
    if (lVar1 != 0) {
      if ((*(byte *)(lVar1 + 0x24) & 2) != 0) {
        (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x40))
                  (*(longlong *)(lVar1 + 8),*(undefined8 *)(lVar1 + 0x10));
      }
      if (((*(byte *)(lVar1 + 0x24) & 1) != 0) && (*(longlong *)(lVar1 + 0x10) != 0)) {
        ExFreePoolWithTag(*(longlong *)(lVar1 + 0x10),0x20204b50);
      }
      ExFreePoolWithTag(lVar1,0x20204b50);
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0x20724b50);
  }
  return;
}



===== KrdmaInitializeSglForLam @ 14000d49c =====

undefined8
KrdmaInitializeSglForLam(longlong param_1,uint param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint *puVar5;
  longlong lVar6;
  uint *puVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0x10) + 8);
  if (uVar2 < 5) {
    uVar8 = *(uint *)(param_1 + 0x20);
    puVar7 = (uint *)(param_4 + 1);
    *(uint *)((longlong)param_4 + 0xc) = param_2;
    *param_4 = (ulonglong)*(uint *)(param_1 + 0x1c) +
               *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
    uVar4 = 0x1000 - *(int *)(param_1 + 0x1c);
    uVar1 = uVar8;
    if (uVar4 <= uVar8) {
      uVar1 = uVar4;
    }
    *puVar7 = uVar1;
    if (1 < uVar2) {
      lVar6 = 0x18;
      puVar5 = (uint *)(param_4 + 3);
      uVar9 = (ulonglong)(uVar2 - 1);
      do {
        uVar8 = uVar8 - *puVar7;
        puVar7 = puVar7 + 4;
        puVar5[1] = param_2;
        uVar2 = uVar8;
        if (0x1000 < uVar8) {
          uVar2 = 0x1000;
        }
        *(undefined8 *)(puVar5 + -2) = *(undefined8 *)(lVar6 + *(longlong *)(param_1 + 0x10));
        *puVar5 = uVar2;
        puVar5 = puVar5 + 4;
        lVar6 = lVar6 + 8;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0000023;
  }
  return uVar3;
}



===== KrdmaInvokeConnectCompletionCallback @ 14000d55c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaInvokeConnectCompletionCallback(longlong param_1,int param_2)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (param_2 < 0) {
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Connect completion callback invoked with error %x\n"
               ,"onecore\\drivers\\storage\\krdma\\connect.c","KrdmaInvokeConnectCompletionCallback"
               ,0x24,param_1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84),param_2);
  }
  else {
    KeAcquireInStackQueuedSpinLock(param_1 + 0x20,&local_28);
    *(undefined1 *)(param_1 + 0x7b) = 1;
    KeReleaseInStackQueuedSpinLock(&local_28);
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Connect completion callback with success\n",
               "onecore\\drivers\\storage\\krdma\\connect.c","KrdmaInvokeConnectCompletionCallback",
               0x32,param_1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84));
  }
  (**(code **)(param_1 + 0x28))
            (param_2,*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x30));
  KrdmaReleaseDisconnectCallbackProtection(param_1);
  return;
}



===== KrdmaNdkCompleteConnectCompletionCallback @ 14000d680 =====

void KrdmaNdkCompleteConnectCompletionCallback(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  if (param_1 != 0) {
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    if (param_2 == 0) {
      KeAcquireInStackQueuedSpinLock(param_1 + 0x20,&local_28);
      if (*(int *)(param_1 + 0x84) == 2) {
        KeReleaseInStackQueuedSpinLock(&local_28);
        IoQueueWorkItemToNode
                  (*(undefined8 *)(param_1 + 0x60),KrdmaTransitionToConnectedState,1,param_1,
                   CONCAT44(uVar2,(uint)*(ushort *)(param_1 + 0x80)));
        return;
      }
      KeReleaseInStackQueuedSpinLock();
      param_2 = 0xc000020c;
    }
    else {
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:NdkCompleteConnect completed with %x\n",
                 "onecore\\drivers\\storage\\krdma\\connect.c",
                 "KrdmaNdkCompleteConnectCompletionCallback",0x112,param_1,
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84),0);
      if ((param_2 & 0xc0000000) != 0xc0000000) {
        return;
      }
    }
    KrdmaInternalDisconnect(param_1);
    KrdmaInvokeConnectCompletionCallback(param_1,param_2);
    puVar1 = (undefined8 *)(param_1 + 0xd0);
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection",
               0x448,puVar1,*puVar1);
    ExReleaseRundownProtection(puVar1);
  }
  return;
}



===== KrdmaNdkConnectCompletionCallback @ 14000d810 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkConnectCompletionCallback(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar9;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  if (param_1 == 0) {
    return;
  }
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_2 == 0) {
    KeAcquireInStackQueuedSpinLock(param_1 + 0x20,&local_28);
    if (*(int *)(param_1 + 0x84) != 2) {
      KeReleaseInStackQueuedSpinLock(&local_28);
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Connect completed but socket in invalid state\n",
                 "onecore\\drivers\\storage\\krdma\\connect.c","KrdmaNdkConnectCompletionCallback",
                 0xda,param_1,CONCAT44(uVar9,*(undefined4 *)(param_1 + 8)),
                 *(undefined4 *)(param_1 + 0x84));
      param_2 = 0xc000020c;
      goto LAB_14000d9ef;
    }
    uVar4 = *(uint *)(param_1 + 0x98);
    if ((*(uint *)(param_1 + 0x98) & 1) == 0) {
      while (uVar4 < 0xfffffffe) {
        LOCK();
        uVar3 = *(uint *)(param_1 + 0x98);
        if (uVar4 == uVar3) {
          *(uint *)(param_1 + 0x98) = uVar4 + 2;
          uVar3 = uVar4;
        }
        else {
        }
        UNLOCK();
        if ((uVar4 == uVar3) || (uVar4 = uVar3, (uVar3 & 1) != 0)) break;
      }
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
    param_2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 200) + 0x28) + 0x20))
                        (*(longlong *)(param_1 + 200),KrdmaNdkDisconnectEventCallback,param_1,
                         KrdmaNdkCompleteConnectCompletionCallback,param_1);
    LOCK();
    piVar1 = (int *)(param_1 + 0x98);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -2;
    UNLOCK();
    if (iVar2 == 3) {
      KrdmaContinueDisconnect(param_1);
    }
    if (param_2 == 0) {
      KrdmaNdkCompleteConnectCompletionCallback(param_1,0);
    }
    else if (param_2 != 0x103) {
      uVar9 = *(undefined4 *)(param_1 + 0x84);
      pcVar6 = "%s:%s:%u:Socket:[%p:%I32u:%I32u]:NdkCompleteConnect call failed with %x\n";
      uVar8 = *(undefined4 *)(param_1 + 8);
      uVar7 = 0xf1;
      goto LAB_14000d9b9;
    }
  }
  else {
    uVar9 = *(undefined4 *)(param_1 + 0x84);
    pcVar6 = "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Connect completed with error %x\n";
    uVar8 = *(undefined4 *)(param_1 + 8);
    uVar7 = 0xce;
LAB_14000d9b9:
    DbgPrintEx(0x50,0xfffffffe,pcVar6,"onecore\\drivers\\storage\\krdma\\connect.c",
               "KrdmaNdkConnectCompletionCallback",uVar7,param_1,uVar8,uVar9,param_2);
  }
  if ((param_2 & 0xc0000000) != 0xc0000000) {
    return;
  }
LAB_14000d9ef:
  KrdmaInternalDisconnect(param_1);
  KrdmaInvokeConnectCompletionCallback(param_1,param_2);
  puVar5 = (undefined8 *)(param_1 + 0xd0);
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
             "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection",
             0x448,puVar5,*puVar5);
  ExReleaseRundownProtection(puVar5);
  return;
}



===== KrdmaSocketConnect @ 14000da74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint KrdmaSocketConnect(undefined *param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4
                       ,longlong param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar11;
  undefined8 *puVar12;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar14;
  undefined8 uVar13;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar15;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar17;
  code *pcVar16;
  code *pcVar18;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x20,&local_28);
  if (*(int *)(param_1 + 0x84) == 1) {
    *(undefined4 *)(param_1 + 0x84) = 2;
    KrdmaAcquireDisconnectCallbackProtection((longlong)param_1);
    KeReleaseInStackQueuedSpinLock(&local_28);
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(code **)(param_1 + 0x28) = NvmofiWskRdmaConnectCallback;
    *(longlong *)(param_1 + 0x30) = param_5;
    local_38 = 1;
    uStack_30 = 0x10;
    puVar9 = (undefined4 *)ExAllocatePool3(0x40,0x10,0x20734b50,&local_38,CONCAT44(uVar11,1));
    *(undefined4 **)(param_1 + 0x48) = puVar9;
    if (puVar9 != (undefined4 *)0x0) {
      uVar11 = param_2[1];
      uVar14 = param_2[2];
      uVar6 = param_2[3];
      puVar1 = (undefined8 *)(param_1 + 0xd0);
      *puVar9 = *param_2;
      puVar9[1] = uVar11;
      puVar9[2] = uVar14;
      puVar9[3] = uVar6;
      uVar13 = *puVar1;
      puVar12 = puVar1;
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p acquired %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaAcquireRundownProtection"
                 ,0x43a,puVar1,uVar13);
      uVar11 = (undefined4)((ulonglong)puVar12 >> 0x20);
      uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
      ExAcquireRundownProtection(puVar1);
      uVar8 = *(uint *)(param_1 + 0x98);
      do {
        if (((uVar8 & 1) != 0) || (0xfffffffd < uVar8)) {
          DbgPrintEx(0x50,0xfffffffe,
                     "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Could not acquire CloseNdkConnector Protection\n"
                     ,"onecore\\drivers\\storage\\krdma\\connect.c","KrdmaSocketConnect",0x7b,
                     param_1,CONCAT44(uVar14,*(undefined4 *)(param_1 + 8)),
                     CONCAT44(uVar15,*(undefined4 *)(param_1 + 0x84)));
          uVar8 = 0xc000020c;
          goto LAB_14000dca2;
        }
        LOCK();
        uVar7 = *(uint *)(param_1 + 0x98);
        if (uVar8 == uVar7) {
          *(uint *)(param_1 + 0x98) = uVar8 + 2;
          uVar7 = uVar8;
        }
        else {
        }
        UNLOCK();
        bVar10 = uVar8 != uVar7;
        uVar8 = uVar7;
      } while (bVar10);
      lVar4 = *(longlong *)param_1;
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 200) + 0x28);
      if (*(longlong *)(lVar4 + 0xa0) == 0) {
        pcVar18 = KrdmaNdkConnectCompletionCallback;
        pcVar16 = (code *)CONCAT44(uVar17,0x20);
        uVar13 = CONCAT44(uVar14,*(undefined4 *)(lVar4 + 100));
        uVar8 = (**(code **)(lVar5 + 0x10))
                          (*(longlong *)(param_1 + 200),*(undefined8 *)(param_1 + 0xc0),lVar4 + 0x14
                           ,0x10,*(undefined8 *)(param_1 + 0x48),0x10,
                           CONCAT44(uVar11,*(undefined4 *)(lVar4 + 0x60)),uVar13,param_6,pcVar16,
                           KrdmaNdkConnectCompletionCallback,param_1);
        uVar11 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar15 = (undefined4)((ulonglong)param_6 >> 0x20);
      }
      else {
        pcVar16 = KrdmaNdkConnectCompletionCallback;
        pcVar18 = (code *)param_1;
        uVar8 = (**(code **)(lVar5 + 0x18))();
        uVar11 = (undefined4)((ulonglong)param_6 >> 0x20);
      }
      LOCK();
      piVar2 = (int *)(param_1 + 0x98);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -2;
      UNLOCK();
      if (iVar3 == 3) {
        KrdmaContinueDisconnect((longlong)param_1);
      }
      if (uVar8 == 0) {
        KrdmaNdkConnectCompletionCallback((longlong)param_1,0);
      }
      else if (uVar8 != 0x103) {
        DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Connect call failed\n",
                   "onecore\\drivers\\storage\\krdma\\connect.c","KrdmaSocketConnect",0xa6,param_1,
                   CONCAT44(uVar11,*(undefined4 *)(param_1 + 8)),
                   CONCAT44(uVar15,*(undefined4 *)(param_1 + 0x84)),pcVar16,pcVar18);
        if ((uVar8 & 0xc0000000) != 0xc0000000) {
          return uVar8;
        }
        goto LAB_14000dca2;
      }
      return 0x103;
    }
    uVar8 = 0xc000009a;
  }
  else {
    KeReleaseInStackQueuedSpinLock(&local_28);
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Invalid socket state %u\n",
               "onecore\\drivers\\storage\\krdma\\connect.c","KrdmaSocketConnect",0x5c,param_1,
               CONCAT44(uVar14,*(undefined4 *)(param_1 + 8)),
               CONCAT44(uVar15,*(undefined4 *)(param_1 + 0x84)),
               CONCAT44(uVar17,*(undefined4 *)(param_1 + 0x84)));
    uVar8 = 0xc0000184;
  }
LAB_14000dca2:
  KrdmaReleaseDisconnectCallbackProtection((longlong)param_1);
  KrdmaInternalDisconnect((longlong)param_1);
  puVar1 = (undefined8 *)(param_1 + 0xd0);
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
             "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection",
             0x448,puVar1,*puVar1);
  ExReleaseRundownProtection(puVar1);
  return uVar8;
}



===== KrdmaTransitionToConnectedState @ 14000dea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaTransitionToConnectedState(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  if (param_2 != (longlong *)0x0) {
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    if (*(longlong *)(*param_2 + 0xc0) == 0) {
      iVar2 = KrdmaAllocateAndPostReceives(param_2);
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 < 0) {
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Failed to Transition to connected state :%x\n",
                 "onecore\\drivers\\storage\\krdma\\connect.c","KrdmaTransitionToConnectedState",
                 0x16e,param_2,CONCAT44(uVar3,(int)param_2[1]),
                 *(undefined4 *)((longlong)param_2 + 0x84),iVar2);
      KrdmaInternalDisconnect((longlong)param_2);
    }
    else {
      (**(code **)(*(longlong *)(param_2[0x28] + 0x28) + 0x18))(param_2[0x28],1);
      (**(code **)(*(longlong *)(param_2[0x20] + 0x28) + 0x18))(param_2[0x20],1);
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Transition to connected state\n",
                 "onecore\\drivers\\storage\\krdma\\connect.c","KrdmaTransitionToConnectedState",
                 0x179,param_2,CONCAT44(uVar3,(int)param_2[1]),
                 *(undefined4 *)((longlong)param_2 + 0x84));
    }
    KeAcquireInStackQueuedSpinLock(param_2 + 4,&local_28);
    if (*(int *)((longlong)param_2 + 0x84) == 2) {
      *(undefined4 *)((longlong)param_2 + 0x84) = 3;
    }
    else {
      iVar2 = -0x3ffffdf4;
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
    KrdmaInvokeConnectCompletionCallback((longlong)param_2,iVar2);
    param_2[0x29] = (longlong)KrdmaReceiveRcqCompletionProcessor;
    (**(code **)(*(longlong *)(param_2[0x28] + 0x28) + 0x18))(param_2[0x28],1);
    plVar1 = param_2 + 0x1a;
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection",
               0x448,plVar1,*plVar1);
    ExReleaseRundownProtection(plVar1);
  }
  return;
}



===== KrdmaNdkBuildLamAsyncCompletion @ 14000e0c0 =====

void KrdmaNdkBuildLamAsyncCompletion(void)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x54,"onecore\\drivers\\storage\\krdma\\ndkutil.c",0x11a,0,0);
}



===== KrdmaNdkCloseFnCompletionCallback @ 14000e100 =====

void KrdmaNdkCloseFnCompletionCallback(undefined8 param_1)

{
  KeSetEvent(param_1,0,0);
  return;
}



===== KrdmaNdkCreateFnCompletionCallback @ 14000e130 =====

void KrdmaNdkCreateFnCompletionCallback(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 0x20) = param_3;
  KeSetEvent(param_1,0,0);
  return;
}



===== KrdmaNdkCreateQueuePairWithSrq @ 14000e158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateQueuePairWithSrq
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8,
              undefined8 *param_9)

{
  int iVar1;
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
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x30))
                    (param_1,param_2,param_3,param_4,param_5,param_6,4,param_8,
                     KrdmaNdkCreateFnCompletionCallback,&local_38,param_9);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_9 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_9 = 0;
  }
  return iVar1;
}



===== KrdmaNdkCreateSharedReceiveQueue @ 14000e278 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateSharedReceiveQueue(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 *in_stack_00000040;
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
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x20))
                    (param_1,param_2,4,0x20,0,0,0,KrdmaNdkCreateFnCompletionCallback,&local_38,
                     in_stack_00000040);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *in_stack_00000040 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *in_stack_00000040 = 0;
  }
  return iVar1;
}



===== KrdmaNdkFnCompletionCallback @ 14000e370 =====

void KrdmaNdkFnCompletionCallback(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  KeSetEvent(param_1,0,0);
  return;
}



===== InitializeResourcePool @ 14000e394 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InitializeResourcePool
              (PSLIST_HEADER param_1,undefined8 param_2,ULONGLONG param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 local_res8;
  
  local_res8 = 0;
  InitializeSListHead(param_1);
  KeInitializeSpinLock(param_1 + 1);
  param_1[2].s.Alignment = param_3;
  uVar2 = 0;
  *(undefined8 *)((longlong)param_1 + 0x18) = param_2;
  *(undefined8 *)((longlong)param_1 + 0x28) = param_4;
  do {
    iVar1 = (**(code **)((longlong)param_1 + 0x18))
                      (*(undefined8 *)((longlong)param_1 + 0x28),&local_res8);
    if (iVar1 < 0) {
      return iVar1;
    }
    ExpInterlockedPushEntrySList(param_1,local_res8);
    LOCK();
    *(int *)&param_1[3].s.Alignment = (int)param_1[3].s.Alignment + 1;
    UNLOCK();
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x400);
  return iVar1;
}



===== KrdmaAllocateFromResourcePool @ 14000e43c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 KrdmaAllocateFromResourcePool(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = ExpInterlockedPopEntrySList();
  uVar2 = 0;
  if (lVar1 == 0) {
    uVar2 = (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),param_2);
    LOCK();
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    UNLOCK();
  }
  else {
    *param_2 = lVar1;
  }
  LOCK();
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  UNLOCK();
  return uVar2;
}



===== KrdmaFRMRAllocateFn @ 14000e4a0 =====

ulonglong KrdmaFRMRAllocateFn(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = KrdmaAllocateFRMR(param_1,param_2);
  }
  return uVar1;
}



===== KrdmaFRMRFreeFn @ 14000e4d0 =====

void KrdmaFRMRFreeFn(longlong param_1)

{
  if (param_1 != 0) {
    KrdmaFreeFrmr(param_1);
  }
  return;
}



===== KrdmaLAMPoolAllocateFn @ 14000e4f0 =====

int KrdmaLAMPoolAllocateFn(longlong param_1,longlong *param_2,undefined8 param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = KrdmaAllocateLamBuffer
                      (*(longlong *)(param_1 + 0x90),*(uint *)(param_1 + 0xa8),param_3,param_2);
  }
  return iVar1;
}



===== KrdmaLAMPoolFreeFn @ 14000e530 =====

void KrdmaLAMPoolFreeFn(longlong param_1)

{
  if (param_1 != 0) {
    KrdmaFreeLamBuffer(param_1);
  }
  return;
}



===== KrdmaUpdatePoolCount @ 14000e54c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint KrdmaUpdatePoolCount(longlong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 local_res8;
  
  uVar6 = 0;
  iVar2 = 0;
  LOCK();
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x30) = 0;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  uVar5 = param_2 - iVar2;
  uVar4 = 0;
  if ((int)uVar5 < 0) {
    if (-uVar5 != 0) {
      do {
        lVar3 = ExpInterlockedPopEntrySList(param_1);
        if (lVar3 == 0) {
          return 0;
        }
        LOCK();
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
        UNLOCK();
        (**(code **)(param_1 + 0x20))(lVar3);
        uVar4 = uVar4 + 1;
      } while (uVar4 < -uVar5);
    }
  }
  else {
    local_res8 = 0;
    uVar6 = 0;
    if (uVar5 != 0) {
      do {
        uVar4 = (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),&local_res8);
        if ((int)uVar4 < 0) break;
        ExpInterlockedPushEntrySList(param_1,local_res8);
        LOCK();
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
        UNLOCK();
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar5);
    }
    uVar6 = uVar4;
  }
  return uVar6;
}



===== KrdmaAcquireDisconnectCallbackProtection @ 14000e604 =====

undefined8 KrdmaAcquireDisconnectCallbackProtection(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = *(uint *)(param_1 + 0x9c);
  do {
    if (((uVar1 & 1) != 0) || (0xfffffffd < uVar1)) {
      return 0xc000020c;
    }
    LOCK();
    uVar2 = *(uint *)(param_1 + 0x9c);
    if (uVar1 == uVar2) {
      *(uint *)(param_1 + 0x9c) = uVar1 + 2;
      uVar2 = uVar1;
    }
    else {
    }
    UNLOCK();
    bVar3 = uVar1 != uVar2;
    uVar1 = uVar2;
  } while (bVar3);
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Disconnect protection acquired %x\n",
             "onecore\\drivers\\storage\\krdma\\disconnect.c",
             "KrdmaAcquireDisconnectCallbackProtection",0x26c,param_1,*(undefined4 *)(param_1 + 8),
             *(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x9c));
  return 0;
}



===== KrdmaCompleteDisconnectIoWorkItemRoutine @ 14000e6b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaCompleteDisconnectIoWorkItemRoutine(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  undefined8 *puVar3;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar5;
  undefined8 uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  if (param_2 != 0) {
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    KeAcquireInStackQueuedSpinLock(param_2 + 0x20,&local_28);
    *(undefined4 *)(param_2 + 0x84) = 5;
    uVar4 = CONCAT44(uVar5,*(undefined4 *)(param_2 + 8));
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Final disconnect called\n",
               "onecore\\drivers\\storage\\krdma\\disconnect.c",
               "KrdmaCompleteDisconnectIoWorkItemRoutine",0x8a,param_2,uVar4,5);
    uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
    lVar1 = *(longlong *)(param_2 + 0x40);
    bVar2 = false;
    if (*(longlong *)(param_2 + 0x88) != 0) {
      bVar2 = false;
      if (*(char *)(param_2 + 0x7b) != '\0') {
        bVar2 = true;
      }
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
    if (lVar1 != 0) {
      (**(code **)(param_2 + 0x40))(0,0,*(undefined8 *)(param_2 + 0x90));
    }
    if (bVar2) {
      (**(code **)(param_2 + 0x88))(*(undefined8 *)(param_2 + 0x150));
    }
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Final disconnect complete\n",
               "onecore\\drivers\\storage\\krdma\\disconnect.c",
               "KrdmaCompleteDisconnectIoWorkItemRoutine",0x120,param_2,
               CONCAT44(uVar5,*(undefined4 *)(param_2 + 8)),*(undefined4 *)(param_2 + 0x84));
    puVar3 = (undefined8 *)(param_2 + 0xd0);
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection",
               0x448,puVar3,*puVar3);
    ExReleaseRundownProtection(puVar3);
  }
  return;
}



===== KrdmaContinueDisconnect @ 14000e86c =====

void KrdmaContinueDisconnect(longlong param_1)

{
  if (param_1 != 0) {
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Queueing disconnect work DisconnectIoWorkItem\n",
               "onecore\\drivers\\storage\\krdma\\disconnect.c","KrdmaContinueDisconnect",0x17c,
               param_1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84));
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0x68),KrdmaContinueDisconnectIoWorkItemRoutine,1,
                    param_1);
  }
  return;
}



===== KrdmaInternalDisconnect @ 14000e8f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 KrdmaInternalDisconnect(longlong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 *puVar8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x20,&local_28);
  uVar10 = *(undefined4 *)(param_1 + 0x84);
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Internal Disconnect called\n",
             "onecore\\drivers\\storage\\krdma\\disconnect.c","KrdmaInternalDisconnect",0x1b2,
             param_1,CONCAT44(uVar9,*(undefined4 *)(param_1 + 8)),uVar10);
  iVar3 = *(int *)(param_1 + 0x84);
  if ((iVar3 == 0) || (iVar3 == 1)) {
    lVar4 = *(longlong *)(param_1 + 200);
    if (lVar4 != 0) {
      (*(code *)**(undefined8 **)(lVar4 + 0x28))(lVar4,_guard_check_icall,0);
    }
    *(undefined8 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0x84) = 5;
    KeReleaseInStackQueuedSpinLock(&local_28);
    uVar6 = 0;
  }
  else {
    if ((iVar3 == 4) || (iVar3 == 5)) {
      KeReleaseInStackQueuedSpinLock(&local_28);
    }
    else {
      puVar1 = (undefined8 *)(param_1 + 0xd0);
      *(undefined4 *)(param_1 + 0x84) = 4;
      uVar6 = *puVar1;
      puVar8 = puVar1;
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p acquired %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaAcquireRundownProtection"
                 ,0x43a,puVar1,uVar6,uVar10);
      uVar9 = (undefined4)((ulonglong)puVar8 >> 0x20);
      ExAcquireRundownProtection(puVar1);
      if (*(char *)(param_1 + 0x78) != '\0') {
        uVar6 = *puVar1;
        puVar8 = puVar1;
        DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p acquired %I64x \n\n",
                   "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
                   "KrdmaAcquireRundownProtection",0x43a,puVar1,uVar6,uVar10);
        uVar9 = (undefined4)((ulonglong)puVar8 >> 0x20);
        ExAcquireRundownProtection(puVar1);
      }
      KeReleaseInStackQueuedSpinLock(&local_28);
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Action triggered %x\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaTriggerAction",0x412,
                 CONCAT44(uVar9,*(undefined4 *)(param_1 + 0x98)),uVar6);
      uVar5 = *(uint *)(param_1 + 0x98);
      do {
        LOCK();
        uVar2 = *(uint *)(param_1 + 0x98);
        bVar7 = uVar5 == uVar2;
        if (bVar7) {
          *(uint *)(param_1 + 0x98) = uVar5 | 1;
        }
        else {
          uVar5 = uVar2;
        }
        UNLOCK();
      } while (!bVar7);
      if (uVar5 == 0) {
        KrdmaContinueDisconnect(param_1);
      }
    }
    uVar6 = 0x103;
  }
  return uVar6;
}



===== KrdmaNdkCloseConnectorCompletionCallback @ 14000eb50 =====

void KrdmaNdkCloseConnectorCompletionCallback(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 200) = 0;
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Disconnect step 2 complete\n",
               "onecore\\drivers\\storage\\krdma\\disconnect.c",
               "KrdmaNdkCloseConnectorCompletionCallback",0x14c,param_1,*(undefined4 *)(param_1 + 8)
               ,*(undefined4 *)(param_1 + 0x84));
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Action triggered %x\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaTriggerAction",0x412,
               *(undefined4 *)(param_1 + 0x9c));
    uVar2 = *(uint *)(param_1 + 0x9c);
    do {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x9c);
      bVar3 = uVar2 == uVar1;
      if (bVar3) {
        *(uint *)(param_1 + 0x9c) = uVar2 | 1;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (!bVar3);
    if (uVar2 == 0) {
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:After trigger action Queueing disconnect work DisconnectIoWorkItem\n"
                 ,"onecore\\drivers\\storage\\krdma\\disconnect.c",
                 "KrdmaNdkCloseConnectorCompletionCallback",0x150,param_1,
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84));
      IoQueueWorkItem(*(undefined8 *)(param_1 + 0x68),KrdmaCompleteDisconnectIoWorkItemRoutine,1,
                      param_1);
    }
  }
  return;
}



===== KrdmaNdkDisconnectEventCallback @ 14000eca0 =====

void KrdmaNdkDisconnectEventCallback(longlong param_1)

{
  if (param_1 != 0) {
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Ndk Indicated Disconnect Triggering KrdmaInternalDisconnect\n"
               ,"onecore\\drivers\\storage\\krdma\\disconnect.c","KrdmaNdkDisconnectEventCallback",
               0x196,param_1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84));
    KrdmaInternalDisconnect(param_1);
  }
  return;
}



===== KrdmaReleaseDisconnectCallbackProtection @ 14000ed10 =====

void KrdmaReleaseDisconnectCallbackProtection(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  DbgPrintEx(0x50,0xfffffffe,
             "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Disconnect protection release called at %x\n",
             "onecore\\drivers\\storage\\krdma\\disconnect.c",
             "KrdmaReleaseDisconnectCallbackProtection",0x282,param_1,*(undefined4 *)(param_1 + 8),
             *(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x9c));
  LOCK();
  piVar1 = (int *)(param_1 + 0x9c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Disconnect protection released %x\n",
               "onecore\\drivers\\storage\\krdma\\disconnect.c",
               "KrdmaReleaseDisconnectCallbackProtection",0x287,param_1,*(undefined4 *)(param_1 + 8)
               ,*(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x9c));
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0x68),KrdmaCompleteDisconnectIoWorkItemRoutine,1,
                    param_1);
  }
  return;
}



===== KrdmaAllocateAndPostReceives @ 14000ee10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaAllocateAndPostReceives(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong local_res8;
  longlong lVar5;
  undefined4 uVar6;
  
  iVar4 = 0;
  lVar2 = *param_1;
  if ((uint)*(ushort *)((longlong)param_1 + 0x16c) < *(uint *)(param_1 + 0xe)) {
    do {
      local_res8 = 0;
      KrdmaAllocateFromResourcePool(lVar2 + 0x140,&local_res8);
      lVar3 = local_res8;
      if (local_res8 == 0) {
        DbgPrintEx(0x50,0xfffffffe,
                   "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Failed to allocate Lam with Error:%u\n",
                   "onecore\\drivers\\storage\\krdma\\receive.c","KrdmaAllocateAndPostReceives",0x7b
                   ,param_1,(int)param_1[1],*(undefined4 *)((longlong)param_1 + 0x84),0xc000009a);
        return -0x3fffff66;
      }
      plVar1 = param_1 + 0x1b;
      lVar5 = *plVar1;
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p acquired %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaAcquireRundownProtection"
                 ,0x43a,plVar1,lVar5);
      uVar6 = (undefined4)((ulonglong)lVar5 >> 0x20);
      ExAcquireRundownProtection(plVar1);
      iVar4 = (**(code **)(*(longlong *)(param_1[0x18] + 0x28) + 0x20))
                        (param_1[0x18],lVar3,lVar3 + 0x20,
                         *(undefined4 *)(*(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x10) + 8));
      if (iVar4 < 0) {
        DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Receive with Error:%u\n",
                   "onecore\\drivers\\storage\\krdma\\receive.c","KrdmaAllocateAndPostReceives",0x88
                   ,param_1,CONCAT44(uVar6,(int)param_1[1]),
                   *(undefined4 *)((longlong)param_1 + 0x84),iVar4);
        ExpInterlockedPushEntrySList(lVar2 + 0x140,lVar3);
        LOCK();
        *(int *)(lVar2 + 0x174) = *(int *)(lVar2 + 0x174) + -1;
        UNLOCK();
        DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
                   "onecore\\drivers\\storage\\krdma\\krdmainternal.h",
                   "KrdmaReleaseRundownProtection",0x448,plVar1,*plVar1);
        ExReleaseRundownProtection(plVar1);
        KrdmaInternalDisconnect((longlong)param_1);
        return iVar4;
      }
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Posted receive current count: %u, maximum receive queue depth: %u\n"
                 ,"onecore\\drivers\\storage\\krdma\\receive.c","KrdmaAllocateAndPostReceives",0x93,
                 param_1,CONCAT44(uVar6,(int)param_1[1]),*(undefined4 *)((longlong)param_1 + 0x84),
                 *(undefined2 *)((longlong)param_1 + 0x16c),(int)param_1[0xe]);
      *(short *)((longlong)param_1 + 0x16c) = *(short *)((longlong)param_1 + 0x16c) + 1;
    } while ((uint)*(ushort *)((longlong)param_1 + 0x16c) < *(uint *)(param_1 + 0xe));
  }
  return iVar4;
}



===== KrdmaAllocateAndPostSharedReceives @ 14000f0a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaAllocateAndPostSharedReceives(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  longlong local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  iVar4 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0xd0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1U <= *(uint *)(param_1 + 0xd4)) {
    do {
      local_res8 = 0;
      KrdmaAllocateFromResourcePool(param_1 + 0x140,&local_res8);
      lVar3 = local_res8;
      if (local_res8 == 0) {
        iVar4 = -0x3fffff66;
        break;
      }
      KeAcquireInStackQueuedSpinLock(param_1 + 200,&local_28);
      iVar4 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xc0) + 0x28) + 0x18))
                        (*(longlong *)(param_1 + 0xc0),lVar3,lVar3 + 0x20,
                         *(undefined4 *)(*(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x10) + 8));
      KeReleaseInStackQueuedSpinLock(&local_28);
      if (iVar4 < 0) {
        ExpInterlockedPushEntrySList(param_1 + 0x140,lVar3);
        LOCK();
        *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x174) + -1;
        UNLOCK();
        break;
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xd0);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    } while (iVar2 + 1U <= *(uint *)(param_1 + 0xd4));
  }
  LOCK();
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + -1;
  UNLOCK();
  return iVar4;
}



===== KrdmaNdkRcqNotificationEventCallback @ 14000f1d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkRcqNotificationEventCallback(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = (undefined8 *)(param_1 + 0xd8);
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p acquired %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaAcquireRundownProtection",
               0x43a,puVar1,*puVar1);
    ExAcquireRundownProtection(puVar1);
    (**(code **)(param_1 + 0x148))(param_1,param_2);
  }
  return;
}



===== KrdmaPreEnableReceiveRcqCompletionProcessor @ 14000f270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaPreEnableReceiveRcqCompletionProcessor(longlong param_1)

{
  if (param_1 != 0) {
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:Receive completion callback pre-enable\n",
               "onecore\\drivers\\storage\\krdma\\receive.c",
               "KrdmaPreEnableReceiveRcqCompletionProcessor",0x1f7,param_1,
               *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x84));
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x140) + 0x28) + 0x18))
              (*(longlong *)(param_1 + 0x140),1);
  }
  return;
}



===== KrdmaProcessBatchReceiveCompletions @ 14000f2f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 KrdmaProcessBatchReceiveCompletions(longlong *param_1,uint param_2,char param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  ushort uVar10;
  uint local_res18;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  lVar2 = *param_1;
  *(undefined1 *)((longlong)param_1 + 0x7a) = 1;
  local_58 = 0;
  uStack_50 = 0;
  uVar10 = 0;
  local_res18 = 0;
  local_48 = 0;
  plVar9 = (undefined8 *)0x0;
  do {
    if (*(uint *)(param_1 + 0x2d) <= *(uint *)(param_1 + 0x23)) {
      *(undefined4 *)(param_1 + 0x23) = 0;
      iVar6 = (**(code **)(*(longlong *)(param_1[0x28] + 0x28) + 0x20))(param_1[0x28],param_1[0x2c])
      ;
      *(int *)(param_1 + 0x2d) = iVar6;
      if (iVar6 == 0) break;
    }
    if (param_2 <= uVar10) break;
    if (*(longlong *)(*param_1 + 0xc0) == 0) {
      *(short *)((longlong)param_1 + 0x16c) = *(short *)((longlong)param_1 + 0x16c) + -1;
    }
    else {
      LOCK();
      *(int *)(lVar2 + 0xd0) = *(int *)(lVar2 + 0xd0) + -1;
      UNLOCK();
    }
    lVar3 = param_1[0x2c];
    uVar7 = (ulonglong)*(uint *)(param_1 + 0x23);
    plVar4 = *(longlong **)(lVar3 + 0x10 + uVar7 * 0x18);
    *(undefined4 *)(plVar4 + 2) = *(undefined4 *)(lVar3 + 4 + uVar7 * 0x18);
    iVar6 = *(int *)(lVar3 + uVar7 * 0x18);
    *plVar4 = (longlong)plVar9;
    if (iVar6 < 0) {
      if (iVar6 != -0x3ffffee0) {
        DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Receive with Error:%u\n",
                   "onecore\\drivers\\storage\\krdma\\receive.c",
                   "KrdmaProcessBatchReceiveCompletions",0xee,param_1,(int)param_1[1],
                   *(undefined4 *)((longlong)param_1 + 0x84),iVar6);
      }
      param_3 = '\x01';
      KrdmaInternalDisconnect((longlong)param_1);
    }
    else if (param_3 == '\0') {
      (*(code *)param_1[0x2b])((int)plVar4[2],plVar4[1]);
    }
    *(int *)(param_1 + 0x23) = (int)param_1[0x23] + 1;
    uVar10 = uVar10 + 1;
    plVar9 = plVar4;
  } while( true );
  *(undefined1 *)((longlong)param_1 + 0x7a) = 0;
  if (param_3 == '\0') {
    if (*(longlong *)(lVar2 + 0xc0) == 0) {
      while ((plVar9 != (undefined8 *)0x0 &&
             ((uint)*(ushort *)((longlong)param_1 + 0x16c) < *(uint *)(param_1 + 0xe)))) {
        puVar8 = plVar9;
        if (plVar9 != (undefined8 *)0x0) {
          puVar8 = (undefined8 *)*plVar9;
        }
        iVar6 = (**(code **)(*(longlong *)(param_1[0x18] + 0x28) + 0x20))
                          (param_1[0x18],plVar9,plVar9 + 4,
                           *(undefined4 *)(*(longlong *)(plVar9[3] + 0x10) + 8));
        if (iVar6 < 0) {
          ExpInterlockedPushEntrySList(lVar2 + 0x140,plVar9);
          goto LAB_14000f572;
        }
        *(short *)((longlong)param_1 + 0x16c) = *(short *)((longlong)param_1 + 0x16c) + 1;
        plVar9 = puVar8;
      }
      if ((uint)*(ushort *)((longlong)param_1 + 0x16c) < *(uint *)(param_1 + 0xe)) {
        KrdmaAllocateAndPostReceives(param_1);
      }
    }
    else {
      do {
        puVar5 = plVar9;
        if (puVar5 == (undefined8 *)0x0) {
LAB_14000f5de:
          plVar9 = puVar5;
          if (local_res18 < *(uint *)(lVar2 + 0xd4)) {
            KrdmaAllocateAndPostSharedReceives(lVar2);
          }
          goto LAB_14000f661;
        }
        LOCK();
        piVar1 = (int *)(lVar2 + 0xd0);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        local_res18 = iVar6 + 1;
        if (*(uint *)(lVar2 + 0xd4) < local_res18) {
          LOCK();
          *(int *)(lVar2 + 0xd0) = *(int *)(lVar2 + 0xd0) + -1;
          UNLOCK();
          goto LAB_14000f5de;
        }
        puVar8 = puVar5;
        if (puVar5 != (undefined8 *)0x0) {
          puVar8 = (undefined8 *)*puVar5;
        }
        KeAcquireInStackQueuedSpinLock(lVar2 + 200,&local_58);
        iVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 0xc0) + 0x28) + 0x18))
                          (*(longlong *)(lVar2 + 0xc0),puVar5,puVar5 + 4,
                           *(undefined4 *)(*(longlong *)(puVar5[3] + 0x10) + 8));
        KeReleaseInStackQueuedSpinLock(&local_58);
        plVar9 = puVar8;
      } while (-1 < iVar6);
      LOCK();
      *(int *)(lVar2 + 0xd0) = *(int *)(lVar2 + 0xd0) + -1;
      UNLOCK();
      ExpInterlockedPushEntrySList(lVar2 + 0x140,puVar5);
LAB_14000f572:
      LOCK();
      *(int *)(lVar2 + 0x174) = *(int *)(lVar2 + 0x174) + -1;
      UNLOCK();
      plVar9 = param_1 + 0x1b;
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection"
                 ,0x448,plVar9,*plVar9);
      ExReleaseRundownProtection(plVar9);
      KrdmaInternalDisconnect((longlong)param_1);
      plVar9 = puVar8;
    }
  }
LAB_14000f661:
  if (plVar9 != (undefined8 *)0x0) {
    plVar4 = param_1 + 0x1b;
    do {
      puVar8 = (undefined8 *)*plVar9;
      ExpInterlockedPushEntrySList(lVar2 + 0x140,plVar9);
      LOCK();
      *(int *)(lVar2 + 0x174) = *(int *)(lVar2 + 0x174) + -1;
      UNLOCK();
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection"
                 ,0x448,plVar4,*plVar4);
      ExReleaseRundownProtection(plVar4);
      plVar9 = puVar8;
    } while (puVar8 != (undefined8 *)0x0);
  }
  return CONCAT31((int3)(*(uint *)(param_1 + 0x2d) >> 8),
                  *(uint *)(param_1 + 0x23) < *(uint *)(param_1 + 0x2d));
}



===== KrdmaProcessRcqCompletionsIoWorkItemRoutine @ 14000f730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaProcessRcqCompletionsIoWorkItemRoutine(undefined8 param_1,ulonglong param_2)

{
  undefined4 uVar1;
  longlong *plVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  
  if (param_2 != 0) {
    plVar2 = (longlong *)(param_2 & 0xfffffffffffffffe);
    uVar4 = *(undefined4 *)((longlong)plVar2 + 0x84);
    uVar5 = *(undefined4 *)((longlong)plVar2 + 0x9c);
    bVar3 = (param_2 & 1) == 0;
    uVar6 = param_2;
    if (bVar3) {
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVRTN: Failed Acquired Disconnect protection %x Context:%p\n"
                 ,"onecore\\drivers\\storage\\krdma\\receive.c",
                 "KrdmaProcessRcqCompletionsIoWorkItemRoutine",0x1aa,plVar2,(int)plVar2[1],uVar4,
                 uVar5,param_2);
    }
    else {
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVRTN: Acquired Disconnect protection %x Context:%p\n"
                 ,"onecore\\drivers\\storage\\krdma\\receive.c",
                 "KrdmaProcessRcqCompletionsIoWorkItemRoutine",0x1a2,plVar2,(int)plVar2[1],uVar4,
                 uVar5,param_2);
    }
    uVar1 = KrdmaProcessBatchReceiveCompletions(plVar2,0x80,bVar3);
    if ((char)uVar1 == '\0') {
      if (!bVar3) {
        uVar5 = *(undefined4 *)((longlong)plVar2 + 0x9c);
        uVar4 = *(undefined4 *)((longlong)plVar2 + 0x84);
        DbgPrintEx(0x50,0xfffffffe,
                   "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVRTN: release disconnect protection %x\n",
                   "onecore\\drivers\\storage\\krdma\\receive.c",
                   "KrdmaProcessRcqCompletionsIoWorkItemRoutine",0x1c5,plVar2,(int)plVar2[1],uVar4,
                   uVar5,uVar6);
        KrdmaReleaseDisconnectCallbackProtection((longlong)plVar2);
      }
      (**(code **)(*(longlong *)(plVar2[0x28] + 0x28) + 0x18))(plVar2[0x28],1);
      plVar2 = plVar2 + 0x1b;
      DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
                 "onecore\\drivers\\storage\\krdma\\krdmainternal.h","KrdmaReleaseRundownProtection"
                 ,0x448,plVar2,*plVar2,uVar4,uVar5);
      ExReleaseRundownProtection(plVar2);
    }
    else {
      IoQueueWorkItemToNode
                (plVar2[0xb],KrdmaProcessRcqCompletionsIoWorkItemRoutine,0,param_2,
                 (short)plVar2[0x10]);
    }
  }
  return;
}



===== KrdmaReceiveRcqCompletionProcessor @ 14000f920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void KrdmaReceiveRcqCompletionProcessor(longlong *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  char *pcVar5;
  bool bVar6;
  undefined1 auStack_78 [32];
  char *local_58;
  undefined4 local_50;
  longlong *local_48;
  longlong local_40;
  undefined4 local_38;
  longlong *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar3 = KrdmaAcquireDisconnectCallbackProtection((longlong)param_1);
  local_38 = *(undefined4 *)((longlong)param_1 + 0x84);
  local_30 = (longlong *)CONCAT44(local_30._4_4_,*(undefined4 *)((longlong)param_1 + 0x9c));
  local_40 = CONCAT44(local_40._4_4_,(int)param_1[1]);
  bVar6 = (int)uVar3 < 0;
  local_48 = param_1;
  if (bVar6) {
    local_50 = 0x22b;
    local_58 = "KrdmaReceiveRcqCompletionProcessor";
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVDPC: Failed to Acquire Disconnect protection %x\n"
               ,"onecore\\drivers\\storage\\krdma\\receive.c");
  }
  else {
    local_50 = 0x224;
    local_58 = "KrdmaReceiveRcqCompletionProcessor";
    DbgPrintEx(0x50,0xfffffffe,
               "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVDPC: Acquired Disconnect protection %x\n");
  }
  iVar1 = KeQueryDpcWatchdogInformation(&local_28);
  if ((((-1 < iVar1) && (KrdmaCqNotificationMinDpcWatchdogCount != 0)) &&
      (KrdmaCqNotificationMinDpcWatchdogCount < uStack_20._4_4_)) &&
     (uVar2 = KrdmaProcessBatchReceiveCompletions(param_1,0x40,bVar6), (char)uVar2 == '\0')) {
    if (!bVar6) {
      local_30 = (longlong *)CONCAT44(local_30._4_4_,*(undefined4 *)((longlong)param_1 + 0x9c));
      local_38 = *(undefined4 *)((longlong)param_1 + 0x84);
      local_40 = CONCAT44(local_40._4_4_,(int)param_1[1]);
      local_50 = 0x26c;
      local_58 = "KrdmaReceiveRcqCompletionProcessor";
      local_48 = param_1;
      DbgPrintEx(0x50,0xfffffffe,
                 "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVDPC: release disconnect protection %x\n",
                 "onecore\\drivers\\storage\\krdma\\receive.c");
      KrdmaReleaseDisconnectCallbackProtection((longlong)param_1);
    }
    (**(code **)(*(longlong *)(param_1[0x28] + 0x28) + 0x18))(param_1[0x28],1);
    plVar4 = param_1 + 0x1b;
    local_40 = *plVar4;
    local_50 = 0x448;
    local_58 = "KrdmaReleaseRundownProtection";
    local_48 = plVar4;
    DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Rundown protection %p release %I64x \n\n",
               "onecore\\drivers\\storage\\krdma\\krdmainternal.h");
    ExReleaseRundownProtection(plVar4);
    return;
  }
  local_38 = *(undefined4 *)((longlong)param_1 + 0x84);
  if (bVar6) {
    pcVar5 = 
    "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVDPC: scheduled routine with context %p no disconnect protection\n"
    ;
    local_50 = 0x25b;
    local_30 = param_1;
  }
  else {
    local_30 = (longlong *)((ulonglong)param_1 | 1);
    pcVar5 = 
    "%s:%s:%u:Socket:[%p:%I32u:%I32u]:RECVDPC: scheduled routine with context %p with disconnect protection\n"
    ;
    local_50 = 0x254;
  }
  plVar4 = local_30;
  local_40 = CONCAT44(local_40._4_4_,(int)param_1[1]);
  local_58 = "KrdmaReceiveRcqCompletionProcessor";
  local_48 = param_1;
  DbgPrintEx(0x50,0xfffffffe,pcVar5,"onecore\\drivers\\storage\\krdma\\receive.c");
  local_58 = (char *)CONCAT44(local_58._4_4_,(uint)*(ushort *)(param_1 + 0x10));
  IoQueueWorkItemToNode(param_1[0xb],KrdmaProcessRcqCompletionsIoWorkItemRoutine,0,plVar4);
  return;
}



===== KrdmaAllocateFRMR @ 14000fbcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong KrdmaAllocateFRMR(longlong param_1,longlong *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar5 = 0x30;
  local_18 = 1;
  uStack_10 = 0x10;
  lVar3 = ExAllocatePool3(0x40,0x30,0x20664b50,&local_18,1);
  *param_2 = lVar3;
  if (lVar3 == 0) {
    uVar6 = 0xc000009a;
  }
  else {
    uVar1 = KrdmaNdkCreateMemoryRegion
                      (*(longlong *)(param_1 + 0x98),uVar5,(undefined8 *)(lVar3 + 0x10));
    uVar6 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar4 = KrdmaNdkInitializeFastRegisterMemoryRegion
                        (*(longlong *)(*param_2 + 0x10),*(undefined4 *)(param_1 + 0x48));
      uVar6 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        uVar2 = (**(code **)(*(longlong *)(*(longlong *)(*param_2 + 0x10) + 0x28) + 0x28))();
        *(undefined4 *)(*param_2 + 0x2c) = uVar2;
        return uVar6;
      }
    }
  }
  KrdmaFreeFrmr(*param_2);
  *param_2 = 0;
  return uVar6;
}



===== KrdmaFreeFrmr @ 14000fc94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaFreeFrmr(longlong param_1)

{
  longlong lVar1;
  
  if (param_1 != 0) {
    lVar1 = *(longlong *)(param_1 + 0x10);
    if (lVar1 != 0) {
      (*(code *)**(undefined8 **)(lVar1 + 0x28))(lVar1,_guard_check_icall,0);
    }
    *(undefined8 *)(param_1 + 0x10) = 0;
    ExFreePoolWithTag(param_1,0x20664b50);
  }
  return;
}



===== __GSHandlerCheck @ 14000fce8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000fd0c =====

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



===== __cpu_features_init @ 14000fd80 =====

/* WARNING: Removing unreachable block (ram,0x00014000fdea) */
/* WARNING: Removing unreachable block (ram,0x00014000fd99) */
/* WARNING: Removing unreachable block (ram,0x00014000fd8a) */

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



===== __security_check_cookie @ 14000fe50 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000fe90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000fec0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000fec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000fef0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000ff40 =====

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



===== memset @ 140010240 =====

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



===== __memset_repmovs @ 140010380 =====

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



===== __memset_query @ 140010400 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140010480 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400105c0 =====

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



===== __memset_spec_plain @ 140010640 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14001a008 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001a043;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001a0bd:
  while( true ) {
    if (&UNK_140015587 < ppuVar3) {
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
      if (&UNK_140015587 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001a043:
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
      if (&UNK_140015587 < ppuVar2) goto LAB_14001a0bd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001a0bd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001a0f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001a190;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001a190;
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
LAB_14001a190:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001a1e0 =====

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
              if (&UNK_140015587 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001a260 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001a35d;
  }
LAB_14001a366:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001a35d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001a366;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001a32e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001a32e;
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
    if (&UNK_140015587 < ppuVar3) goto LAB_14001a366;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001a35d;
}



===== NvmofiFindHostGateway @ 14001a38c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NvmofiFindHostGateway(longlong param_1,undefined8 param_2)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  short sVar11;
  bool bVar12;
  undefined1 auStack_288 [32];
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_288;
  local_258 = 0;
  plVar8 = (longlong *)0x0;
  lVar10 = 0;
  lVar7 = 0;
  local_268 = 0;
  uStack_260 = 0;
  if (*(short *)(param_1 + 2) == 2) {
    lVar10 = param_1 + 4;
    sVar11 = 2;
    bVar12 = *(char *)(param_1 + 6) == '\x7f';
  }
  else {
    if (*(short *)(param_1 + 2) != 0x17) {
      return 0;
    }
    lVar7 = param_1 + 4;
    sVar11 = 0x17;
    if (((((*(short *)(param_1 + 10) != 0) || (*(short *)(param_1 + 0xc) != 0)) ||
         (*(short *)(param_1 + 0xe) != 0)) ||
        ((*(short *)(param_1 + 0x10) != 0 || (*(short *)(param_1 + 0x12) != 0)))) ||
       ((*(short *)(param_1 + 0x14) != 0 || (*(short *)(param_1 + 0x16) != 0)))) goto LAB_14001a446;
    bVar12 = *(short *)(param_1 + 0x18) == 0x100;
  }
  if (bVar12) {
    return 0;
  }
LAB_14001a446:
  KeAcquireInStackQueuedSpinLock(NvmofiAdapterExtension + 0x58,&local_268);
  plVar4 = (longlong *)(NvmofiAdapterExtension + 0x60);
  plVar9 = (longlong *)*plVar4;
  do {
    bVar2 = 0;
    if (plVar9 == plVar4) {
LAB_14001a4f9:
      KeReleaseInStackQueuedSpinLock(&local_268);
      return -(ulonglong)bVar2 & (ulonglong)plVar8;
    }
    plVar8 = plVar9 + -1;
    iVar3 = RtlCompareUnicodeString(param_2,plVar9 + 4,1);
    if ((iVar3 == 0) && ((short)plVar9[6] == sVar11)) {
      if (sVar11 == 2) {
        if (*(int *)((longlong)plVar9 + 0x34) == *(int *)(lVar10 + 2)) {
          RtlIpv4AddressToStringW((int *)((longlong)plVar9 + 0x34),local_248);
          goto LAB_14001a56d;
        }
      }
      else if ((sVar11 == 0x17) &&
              (lVar5 = RtlCompareMemory(plVar9 + 7,lVar7 + 6,0x10), lVar5 == 0x10)) {
        RtlIpv6AddressToStringW(plVar9 + 7,local_248);
LAB_14001a56d:
        bVar2 = 1;
        lVar7 = *plVar9;
        if ((*(longlong **)(lVar7 + 8) != plVar9) ||
           (plVar4 = (longlong *)plVar9[1], (longlong *)*plVar4 != plVar9)) {
          pcVar1 = (code *)swi(0x29);
          (*pcVar1)(3);
          pcVar1 = (code *)swi(3);
          uVar6 = (*pcVar1)();
          return uVar6;
        }
        *plVar4 = lVar7;
        *(longlong **)(lVar7 + 8) = plVar4;
        goto LAB_14001a4f9;
      }
    }
    plVar9 = (longlong *)*plVar9;
    plVar4 = (longlong *)(NvmofiAdapterExtension + 0x60);
  } while( true );
}



===== NvmofiGetAdapterInterfaceIndex @ 14001a598 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NvmofiGetAdapterInterfaceIndex(longlong param_1,short param_2,ULONG *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_68 [32];
  ULONG local_48 [2];
  NET_LUID local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  GUID local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48[0] = 0;
  local_40.Value = 0;
  local_28.Data1 = 0;
  local_28.Data2 = 0;
  local_28.Data3 = 0;
  local_28.Data4[0] = '\0';
  local_28.Data4[1] = '\0';
  local_28.Data4[2] = '\0';
  local_28.Data4[3] = '\0';
  local_28.Data4[4] = '\0';
  local_28.Data4[5] = '\0';
  local_28.Data4[6] = '\0';
  local_28.Data4[7] = '\0';
  *param_3 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_2 == 2) {
    lVar2 = 0x1c;
  }
  else {
    if (param_2 != 0x17) {
      return 0;
    }
    lVar2 = 0x1e;
  }
  RtlInitUnicodeString(&local_38,*(longlong *)(param_1 + 8) + lVar2);
  iVar1 = RtlGUIDFromString(&local_38,&local_28);
  if (((-1 < iVar1) && (iVar1 = ConvertInterfaceGuidToLuid(&local_28,&local_40), -1 < iVar1)) &&
     (iVar1 = ConvertInterfaceLuidToIndex(&local_40,local_48), -1 < iVar1)) {
    *param_3 = local_48[0];
  }
  return iVar1;
}



===== NvmofiNotifyInterfaceArrival @ 14001a680 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvmofiNotifyInterfaceArrival
               (longlong param_1,longlong param_2,longlong param_3,longlong *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  longlong *plVar12;
  undefined **ppuVar13;
  char *pcVar14;
  longlong lVar15;
  wchar_t *pwVar16;
  char *pcVar17;
  longlong lVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  longlong *plVar22;
  ULONG *pUVar23;
  NET_IFINDEX NVar24;
  undefined1 auStack_4a8 [8];
  undefined1 auStack_4a0 [24];
  undefined4 local_488;
  undefined4 local_480;
  wchar_t *local_478;
  undefined8 local_470;
  undefined4 local_468;
  undefined4 local_460;
  wchar_t *local_458;
  ulonglong local_450;
  wchar_t *local_448;
  undefined8 local_440;
  wchar_t *local_438;
  undefined8 local_430;
  wchar_t *local_428;
  undefined8 local_420;
  wchar_t *local_418;
  undefined8 local_410;
  wchar_t *local_408;
  undefined8 local_400;
  wchar_t *local_3f8;
  undefined8 local_3f0;
  wchar_t *local_3e8;
  undefined8 local_3e0;
  ULONG local_3d8 [2];
  longlong *local_3d0;
  longlong local_3c8;
  undefined8 local_3c0;
  wchar_t *pwStack_3b8;
  undefined8 local_3b0;
  undefined8 uStack_3a8;
  undefined8 local_3a0;
  undefined8 uStack_398;
  undefined8 local_390;
  undefined4 local_388 [2];
  longlong *local_380;
  undefined2 local_376;
  undefined1 local_374;
  undefined1 local_373;
  undefined1 local_372 [256];
  char local_272 [42];
  wchar_t local_248 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_4a8;
  local_3d8[0] = 0;
  local_390 = 0;
  NVar24 = 0;
  local_3b0 = 0;
  uStack_3a8 = 0;
  bVar7 = false;
  local_3a0 = 0;
  uStack_398 = 0;
  local_3c8 = param_2;
  memset(local_388,0,0x138);
  puVar19 = auStack_4a8;
  puVar20 = auStack_4a8;
  bVar8 = false;
  local_3c0 = 0;
  pwStack_3b8 = (wchar_t *)0x0;
  puVar21 = auStack_4a8;
  if (((*(short *)(param_3 + 2) == 3) &&
      (puVar21 = auStack_4a8, (longlong *)(param_3 + 8) != (longlong *)0x0)) &&
     (lVar1 = *(longlong *)(param_3 + 8), puVar21 = auStack_4a8,
     (*(uint *)(lVar1 + 0x30) & 0x1000) != 0)) {
    if (*(short *)(param_1 + 2) == 2) {
      puVar21 = auStack_4a8;
      if (*(char *)(param_1 + 6) == '\x7f') goto LAB_14001ad3a;
    }
    else {
      puVar21 = auStack_4a8;
      if ((*(short *)(param_1 + 2) != 0x17) ||
         (((((*(short *)(param_1 + 10) == 0 && (*(short *)(param_1 + 0xc) == 0)) &&
            ((*(short *)(param_1 + 0xe) == 0 &&
             ((*(short *)(param_1 + 0x10) == 0 && (*(short *)(param_1 + 0x12) == 0)))))) &&
           (*(short *)(param_1 + 0x14) == 0)) &&
          ((*(short *)(param_1 + 0x16) == 0 &&
           (puVar21 = auStack_4a8, *(short *)(param_1 + 0x18) == 0x100)))))) goto LAB_14001ad3a;
    }
    do {
      plVar12 = (longlong *)ExAllocatePool2(0x40,0xf8,0x7747664e);
      lVar18 = local_3c8;
      local_3d0 = plVar12;
      if (plVar12 == (longlong *)0x0) {
        local_3e0 = 0;
        local_3e8 = L"";
        local_3f0 = 0;
        local_3f8 = L"";
        local_400 = 0;
        local_408 = L"";
        local_410 = 0;
        local_418 = L"";
        local_420 = 0;
        local_428 = L"";
        local_430 = 0;
        local_438 = L"";
        local_440 = 0;
        local_448 = L"";
        local_450 = 0;
        local_458 = L"";
        local_460 = 0;
        local_468 = 1;
        local_470 = 0x200;
        pwVar16 = L"ExAllocatePool2 failure";
        puVar20 = auStack_4a8;
LAB_14001acfd:
        *(wchar_t **)(puVar20 + 0x30) = pwVar16;
        *(undefined4 *)(puVar20 + 0x28) = 0x13;
        *(undefined4 *)(puVar20 + 0x20) = 1;
        *(undefined8 *)(puVar20 + -8) = 0x14001ad27;
        StorPortExtendedFunction(0x80,NvmofiAdapterExtension,0,0);
        break;
      }
      pUVar23 = (ULONG *)(plVar12 + 5);
      iVar10 = RtlDuplicateUnicodeString(1,local_3c8);
      plVar22 = plVar12;
      if (iVar10 < 0) {
LAB_14001abc9:
        *(undefined8 *)(puVar19 + 200) = 0;
        *(wchar_t **)(puVar19 + 0xc0) = L"";
        *(undefined8 *)(puVar19 + 0xb8) = 0;
        *(wchar_t **)(puVar19 + 0xb0) = L"";
        *(undefined8 *)(puVar19 + 0xa8) = 0;
        *(wchar_t **)(puVar19 + 0xa0) = L"";
        *(undefined8 *)(puVar19 + 0x98) = 0;
        *(wchar_t **)(puVar19 + 0x90) = L"";
        *(undefined8 *)(puVar19 + 0x88) = 0;
        *(wchar_t **)(puVar19 + 0x80) = L"";
        *(undefined8 *)(puVar19 + 0x78) = 0;
        *(wchar_t **)(puVar19 + 0x70) = L"";
        *(undefined8 *)(puVar19 + 0x68) = 0;
        *(wchar_t **)(puVar19 + 0x60) = L"";
        *(longlong *)(puVar19 + 0x58) = (longlong)iVar10;
        *(wchar_t **)(puVar19 + 0x50) = L"NtStatus";
        *(undefined4 *)(puVar19 + 0x48) = 0;
        *(undefined4 *)(puVar19 + 0x40) = 1;
        *(undefined8 *)(puVar19 + 0x38) = 0x200;
        pwVar16 = L"RtlDuplicateUnicodeString failure";
        puVar20 = puVar19;
        plVar12 = plVar22;
        goto LAB_14001acfd;
      }
      plVar12[3] = NvmofiAdapterExtension;
      if (*(short *)(param_1 + 2) == 2) {
        *(undefined2 *)(plVar12 + 7) = 2;
        *(undefined4 *)((longlong)plVar12 + 0x3c) = *(undefined4 *)(param_1 + 6);
        local_373 = 1;
        RtlIpv4AddressToStringA((undefined4 *)((longlong)plVar12 + 0x3c),local_372);
      }
      else if (*(short *)(param_1 + 2) == 0x17) {
        *(undefined2 *)(plVar12 + 7) = 0x17;
        uVar4 = *(undefined4 *)(param_1 + 0xe);
        uVar5 = *(undefined4 *)(param_1 + 0x12);
        uVar6 = *(undefined4 *)(param_1 + 0x16);
        *(undefined4 *)(plVar12 + 8) = *(undefined4 *)(param_1 + 10);
        *(undefined4 *)((longlong)plVar12 + 0x44) = uVar4;
        *(undefined4 *)(plVar12 + 9) = uVar5;
        *(undefined4 *)((longlong)plVar12 + 0x4c) = uVar6;
        local_373 = 2;
        RtlIpv6AddressToStringA(plVar12 + 8,local_372);
      }
      if (bVar7) {
LAB_14001a84e:
        if (((NVar24 == 0) || (bVar7)) || (*(char *)(plVar12[3] + 0x50) == '\0'))
        goto LAB_14001a87a;
        bVar9 = NvmofiWskRdmaIsSupported(NVar24,(undefined4 *)(plVar12 + 7),pUVar23,param_4);
        iVar10 = (-(uint)bVar9 & 0xfffffffe) + 3;
      }
      else {
        pUVar23 = local_3d8;
        iVar10 = NvmofiGetAdapterInterfaceIndex(lVar18,*(short *)(param_1 + 2),pUVar23);
        NVar24 = local_3d8[0];
        if (-1 < iVar10) goto LAB_14001a84e;
LAB_14001a87a:
        iVar10 = 3;
      }
      *(NET_IFINDEX *)(plVar12 + 0x17) = NVar24;
      *(int *)plVar12 = iVar10;
      if (iVar10 == 1) {
        ppuVar13 = &NvmofiRdmaTransportOps;
        bVar7 = true;
      }
      else if (iVar10 == 3) {
        ppuVar13 = &NvmofiTcpTransportOps;
        bVar8 = true;
      }
      else {
        ppuVar13 = &NvmofiDefaultTransportOps;
      }
      plVar12[4] = (longlong)ppuVar13;
      KeInitializeSpinLock(plVar12 + 0x1c);
      plVar22 = plVar12 + 0x1d;
      plVar12[0x1e] = (longlong)plVar22;
      *plVar22 = (longlong)plVar22;
      plVar12[0x1a] = 0;
      IoGetDeviceNumaNode(lVar1,(undefined2 *)((longlong)plVar12 + 0xbc));
      local_388[0] = 0x1380001;
      pcVar17 = local_272;
      local_374 = (undefined1)*plVar12;
      local_376 = *(undefined2 *)((longlong)plVar12 + 0xbc);
      lVar18 = 0x20;
      do {
        if ((lVar18 == -0x7fffffde) || (pcVar17[(longlong)"4420" - (longlong)local_272] == '\0'))
        break;
        *pcVar17 = pcVar17[(longlong)"4420" - (longlong)local_272];
        pcVar17 = pcVar17 + 1;
        lVar18 = lVar18 + -1;
      } while (lVar18 != 0);
      pcVar14 = pcVar17 + -1;
      if (lVar18 != 0) {
        pcVar14 = pcVar17;
      }
      *pcVar14 = '\0';
      local_380 = plVar12;
      RtlInitAnsiString(&local_3b0,local_372);
      local_3c0._0_4_ = CONCAT22(0x200,(undefined2)local_3c0);
      pwStack_3b8 = local_248;
      RtlAnsiStringToUnicodeString(&local_3c0,&local_3b0,0);
      local_3e0 = 0;
      local_3e8 = L"";
      local_3f0 = 0;
      local_3f8 = L"";
      local_400 = 0;
      local_408 = L"";
      local_410 = 0;
      local_418 = L"";
      local_420 = 0;
      local_428 = L"";
      local_430 = 0;
      local_438 = L"";
      local_440 = 0;
      local_448 = L"";
      local_458 = local_248;
      local_450 = 0;
      local_460 = 0;
      local_468 = 5;
      local_470 = 0x200;
      local_478 = L"TDI Interface arrival";
      local_480 = 0;
      local_488 = 1;
      StorPortExtendedFunction(0x80,NvmofiAdapterExtension,0,0);
      param_4 = plVar12 + 0x1b;
      uVar11 = StorPortNvmeofExtendedFunction(2,NvmofiAdapterExtension,local_388);
      if (uVar11 == 0) {
        KeAcquireInStackQueuedSpinLock(NvmofiAdapterExtension + 0x58,&local_3a0);
        lVar18 = NvmofiAdapterExtension;
        plVar22 = plVar12 + 1;
        lVar15 = NvmofiAdapterExtension + 0x60;
        plVar2 = *(longlong **)(NvmofiAdapterExtension + 0x68);
        if (*plVar2 != lVar15) {
          pcVar3 = (code *)swi(0x29);
          iVar10 = (*pcVar3)(3);
          puVar19 = auStack_4a0;
          goto LAB_14001abc9;
        }
        plVar12[2] = (longlong)plVar2;
        *plVar22 = lVar15;
        *plVar2 = (longlong)plVar22;
        *(longlong **)(lVar18 + 0x68) = plVar22;
        plVar12 = (longlong *)0x0;
        local_3d0 = (longlong *)0x0;
        KeReleaseInStackQueuedSpinLock(&local_3a0);
      }
      else {
        local_3e0 = 0;
        param_4 = (longlong *)0x0;
        local_3e8 = L"";
        local_3f0 = 0;
        local_3f8 = L"";
        local_400 = 0;
        local_408 = L"";
        local_410 = 0;
        local_418 = L"";
        local_420 = 0;
        local_428 = L"";
        local_430 = 0;
        local_438 = L"";
        local_440 = 0;
        local_448 = L"";
        local_450 = (ulonglong)uVar11;
        local_458 = L"StorStatus";
        local_460 = 0;
        local_468 = 1;
        local_470 = 0x200;
        local_478 = L"StorPortAddNvmeofHostGateway failure";
        local_480 = 0x13;
        local_488 = 1;
        StorPortExtendedFunction(0x80,NvmofiAdapterExtension,0);
      }
    } while (!bVar8);
    puVar21 = puVar20;
    if (plVar12 != (longlong *)0x0) {
      *(undefined8 *)(puVar20 + -8) = 0x14001ad3a;
      NvmofiFreeHostGateway((longlong *)&local_3d0);
    }
  }
LAB_14001ad3a:
  *(undefined8 *)(puVar21 + -8) = 0x14001ad49;
  return;
}



===== NvmofiNotifyInterfaceRemoval @ 14001ad70 =====

void NvmofiNotifyInterfaceRemoval(longlong param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = NvmofiRemoveHostGateway(param_1,param_2,0);
  if (-1 < iVar1) {
    StorPortExtendedFunction
              (0x80,NvmofiAdapterExtension,0,0,1,0,L"TDI Interface removal",0x200,5,0,param_1 + 4,0,
               L"",0,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
  }
  return;
}



===== NvmofiNotifyPnPChange @ 14001ae70 =====

int NvmofiNotifyPnPChange(undefined8 param_1,int *param_2,ushort *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if ((((*param_2 == 1) || (*param_2 == 2)) && (param_3 != (ushort *)0x0)) && (param_3[1] == 2)) {
    if (*param_3 < 0xc) {
      iVar1 = -0x3fffffdd;
    }
    else if (param_3 == (ushort *)0xfffffffffffffff8) {
      iVar1 = -0x3ffffff3;
    }
    else {
      iVar1 = NvmofiRemoveHostGateway((longlong)(param_3 + 6),param_1,(ulonglong)param_2);
    }
  }
  return iVar1;
}



===== NvmofiRemoveHostGateway @ 14001aed8 =====

int NvmofiRemoveHostGateway(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  ulonglong local_res20;
  
  uVar2 = NvmofiFindHostGateway(param_1,param_2);
  if (uVar2 != 0) {
    local_res20 = uVar2;
    if (param_3 != 0) {
      puVar3 = (ulonglong *)ExAllocatePool2(0x40,0x10,0x7747664e);
      if (puVar3 == (ulonglong *)0x0) {
        return -0x3fffff66;
      }
      *puVar3 = uVar2;
      puVar3[1] = param_3;
      iVar1 = NvmofiQueueWorkItem(*(undefined8 *)(uVar2 + 0x18),NvmofiRemoveHostGatewayWorker,puVar3
                                 );
      return (-(uint)(iVar1 != 0) & 0xbfffff97) + 0x103;
    }
    StorPortNvmeofExtendedFunction(3,*(undefined8 *)(uVar2 + 0x18),*(undefined8 *)(uVar2 + 0xd8));
    NvmofiFreeHostGateway((longlong *)&local_res20);
  }
  return 0;
}



===== NvmofiWskCleanup @ 14001af88 =====

undefined8 NvmofiWskCleanup(longlong param_1,char param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 *puVar5;
  longlong local_res8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(char *)(param_1 + 0x41) != '\0') {
    WskReleaseProviderNPI(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x41) = 0;
  }
  if (*(char *)(param_1 + 0x40) != '\0') {
    WskDeregister(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x40) = 0;
  }
  if (*(longlong *)(param_1 + 0x48) != 0) {
    TdiDeregisterPnPHandlers();
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  puVar5 = auStack_28;
  plVar1 = (longlong *)(param_1 + 0x60);
  do {
    plVar2 = (longlong *)*plVar1;
    if (plVar2 == plVar1) {
LAB_14001b049:
      *(undefined8 *)(puVar5 + -8) = 0x14001b04e;
      KrdmaUninitialize();
      NvmofiAdapterExtension = 0;
      return 0;
    }
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar5 = auStack_20;
      goto LAB_14001b049;
    }
    *plVar1 = lVar3;
    local_res8 = (longlong)(plVar2 + -1);
    *(longlong **)(lVar3 + 8) = plVar1;
    if (param_2 == '\0') {
      StorPortNvmeofExtendedFunction(3,param_1,plVar2[0x1a]);
    }
    NvmofiFreeHostGateway(&local_res8);
  } while( true );
}



===== NvmofiWskCommonInitialize @ 14001b070 =====

int NvmofiWskCommonInitialize(longlong param_1)

{
  int iVar1;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined2 local_48;
  undefined4 local_46;
  undefined2 local_42;
  undefined8 *local_40;
  code *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  code *local_20;
  code *local_18;
  
  local_46 = 0;
  local_42 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_58 = 0;
  uStack_50 = 0;
  NvmofiAdapterExtension = param_1;
  RtlInitUnicodeString(&local_58,L"StorNvmeOfi");
  local_40 = &local_58;
  local_48 = 2;
  local_20 = NvmofiNotifyInterfaceArrival;
  local_18 = NvmofiNotifyInterfaceRemoval;
  local_38 = NvmofiNotifyPnPChange;
  iVar1 = TdiRegisterPnPHandlers(&local_48,0x38,param_1 + 0x48);
  if (iVar1 < 0) {
    StorPortExtendedFunction
              (0x80,param_1,0,0,1,0x20,L"TdiRegisterPnPHandlers failure",0x200,1,0,L"NtStatus",
               (longlong)iVar1,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0,L"",0);
    NvmofiAdapterExtension = 0;
  }
  return iVar1;
}



===== KrdmaNdkCloseAdapter @ 14001b200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkCloseAdapter(longlong param_1)

{
  if (param_1 != 0) {
    (*DAT_1400160f8)(KrdmaWskProviderNpi,param_1);
  }
  return;
}



===== KrdmaNdkCloseQueuePair @ 14001b22c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkCloseQueuePair(longlong param_1)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_1 != 0) {
    local_18 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeInitializeEvent(&local_38,1,0);
    iVar1 = (*(code *)**(undefined8 **)(param_1 + 0x28))
                      (param_1,KrdmaNdkCloseFnCompletionCallback,&local_38);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
    }
  }
  return;
}



===== KrdmaNdkCloseProtectionDomain @ 14001b2b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkCloseProtectionDomain(longlong param_1)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Entry\n","onecore\\drivers\\storage\\krdma\\ndkutil.c",
             "KrdmaNdkCloseProtectionDomain",0x315);
  if (param_1 != 0) {
    KeInitializeEvent(&local_38,1);
    iVar1 = (*(code *)**(undefined8 **)(param_1 + 0x28))
                      (param_1,KrdmaNdkCloseFnCompletionCallback,&local_38);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
    }
  }
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u Cleanup\n","onecore\\drivers\\storage\\krdma\\ndkutil.c",
             "KrdmaNdkCloseProtectionDomain",0x323);
  return;
}



===== KrdmaNdkCreateCompletionQueue @ 14001b3ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateCompletionQueue
              (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 *param_6)

{
  int iVar1;
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
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x10))
                    (param_1,param_2,param_3,param_4,param_5,KrdmaNdkCreateFnCompletionCallback,
                     &local_38,param_6);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_6 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_6 = 0;
  }
  return iVar1;
}



===== KrdmaNdkCreateConnector @ 14001b4a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateConnector(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x28))
                    (param_1,KrdmaNdkCreateFnCompletionCallback,&local_38,param_2);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_2 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_2 = 0;
  }
  return iVar1;
}



===== KrdmaNdkCreateMemoryRegion @ 14001b554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateMemoryRegion(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x10))
                    (param_1,1,KrdmaNdkCreateFnCompletionCallback,&local_38,param_3);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_3 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_3 = 0;
  }
  return iVar1;
}



===== KrdmaNdkCreateProtectionDomain @ 14001b604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateProtectionDomain(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x18))
                    (param_1,KrdmaNdkCreateFnCompletionCallback,&local_38,param_2);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_2 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_2 = 0;
  }
  return iVar1;
}



===== KrdmaNdkCreateQueuePair @ 14001b6b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateQueuePair
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8,
              undefined4 param_9,undefined8 *param_10)

{
  int iVar1;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x28))
                    (param_1,param_2,param_3,param_4,CONCAT44(uVar2,param_5),param_6,4,4,param_9,
                     KrdmaNdkCreateFnCompletionCallback,&local_38,param_10);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_10 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_10 = 0;
  }
  return iVar1;
}



===== KrdmaNdkCreateSharedEndpoint @ 14001b7d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkCreateSharedEndpoint
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
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
  KeInitializeEvent(&local_38,1,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x20))
                    (param_1,param_2,0x10,KrdmaNdkCreateFnCompletionCallback,&local_38,param_4);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_4 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_4 = 0;
  }
  return iVar1;
}



===== KrdmaNdkInitialize @ 14001b89c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KrdmaNdkInitialize(void)

{
  int iVar1;
  undefined8 local_18;
  undefined *local_10;
  
  local_18 = 0;
  local_10 = &KrdmaWskClientDispatch;
  iVar1 = WskRegister(&local_18,&KrdmaWskRegistration);
  if (-1 < iVar1) {
    KrdmaWskRegistered = 1;
    iVar1 = WskCaptureProviderNPI(&KrdmaWskRegistration,0,&KrdmaWskProviderNpi);
    if (-1 < iVar1) {
      KrdmaWskProviderNpiCaptured = 1;
      iVar1 = (**(code **)(DAT_1400160e8 + 0x18))
                        (KrdmaWskProviderNpi,0x4e444b44,0,0,0x10,&KrdmaWskNdkDispatch,0,0);
      if (-1 < iVar1) {
        return iVar1;
      }
    }
  }
  KrdmaNdkUninitialize();
  return iVar1;
}



===== KrdmaNdkInitializeFastRegisterMemoryRegion @ 14001b960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong KrdmaNdkInitializeFastRegisterMemoryRegion(longlong param_1,undefined4 param_2)

{
  ulonglong uVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,1,0);
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x20))
                    (param_1,param_2,1,KrdmaNdkFnCompletionCallback,&local_38);
  if ((int)uVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    uVar1 = uStack_20 & 0xffffffff;
  }
  return uVar1;
}



===== KrdmaNdkOpenAdapter @ 14001b9fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkOpenAdapter(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = (*KrdmaWskNdkDispatch)(KrdmaWskProviderNpi,2,param_1,param_2);
  if (iVar1 == -0x3ffefffc) {
    (*KrdmaWskNdkDispatch)(KrdmaWskProviderNpi,1,param_1,param_2);
  }
  return;
}



===== KrdmaNdkQueryAdapterInfo @ 14001ba70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaNdkQueryAdapterInfo(longlong param_1,void *param_2)

{
  undefined4 local_res8 [2];
  
  local_res8[0] = 0x68;
  memset(param_2,0,0x68);
  (**(code **)(*(longlong *)(param_1 + 0x28) + 8))(param_1,param_2,local_res8);
  return;
}



===== KrdmaNdkUninitialize @ 14001bac0 =====

void KrdmaNdkUninitialize(void)

{
  if (KrdmaWskProviderNpiCaptured != '\0') {
    WskReleaseProviderNPI(&KrdmaWskRegistration);
    KrdmaWskProviderNpiCaptured = '\0';
  }
  if (KrdmaWskRegistered != '\0') {
    WskDeregister(&KrdmaWskRegistration);
    KrdmaWskRegistered = '\0';
  }
  return;
}



===== KrdmaContinueDisconnectIoWorkItemRoutine @ 14001bb20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KrdmaContinueDisconnectIoWorkItemRoutine(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  DbgPrintEx(0x50,0xfffffffe,"%s:%s:%u:Socket:[%p:%I32u:%I32u]:Disconnect step 2 enter\n",
             "onecore\\drivers\\storage\\krdma\\disconnect.c",
             "KrdmaContinueDisconnectIoWorkItemRoutine",0x34,param_2,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x84));
  (**(code **)(*(longlong *)(*(longlong *)(param_2 + 0xc0) + 0x28) + 0x10))();
  iVar1 = (*(code *)**(undefined8 **)(*(longlong *)(param_2 + 200) + 0x28))
                    (*(longlong *)(param_2 + 200),KrdmaNdkCloseConnectorCompletionCallback,param_2);
  if (iVar1 != 0x103) {
    KrdmaNdkCloseConnectorCompletionCallback(param_2);
  }
  return;
}



===== entry @ 14001c010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001c044 =====

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



===== DriverEntry @ 14001c078 =====

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 local_90;
  undefined1 local_80;
  undefined2 local_7e;
  undefined1 local_7c;
  code *local_60;
  code *local_50;
  uint local_20;
  undefined4 local_1c;
  
  memset(&local_d8,0,0xd0);
  wil_InitializeFeatureStaging();
  local_d4 = 0;
  local_20 = local_20 | 0x6001;
  local_d0 = NvmofiInitialize;
  local_d8 = 0xd0;
  local_c8 = NvmofiStartIo;
  local_98 = 0x70;
  local_b8 = NvmofiFindAdapter;
  local_90 = 0x28;
  local_b0 = NvmofiResetBus;
  local_60 = NvmofiAdapterControl;
  local_50 = NvmofiFreeAdapterResources;
  local_80 = 3;
  local_7e = 0x101;
  local_7c = 1;
  local_1c = 2;
  iVar1 = StorPortInitialize(param_1,param_2,&local_d8,0);
  if (iVar1 == 0) {
    StorPortDriverUnload = *(longlong *)(param_1 + 0x68);
    if (StorPortDriverUnload != 0) {
      *(code **)(param_1 + 0x68) = StorNVMeOfDriverUnload;
    }
  }
  else {
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
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14001c1c4 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001c24b;
    }
LAB_14001c285:
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
LAB_14001c24b:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001c285;
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
    goto LAB_14001c285;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140015587 < ppuVar3) goto LAB_14001c285;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001c24b;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001c2d8 =====

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
            if (&UNK_140015587 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001c3c2;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001c3c2;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001c3c2:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140015587 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


