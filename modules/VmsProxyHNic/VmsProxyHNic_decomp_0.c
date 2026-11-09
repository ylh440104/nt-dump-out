
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



===== VmsNicPxyAdapterShutdownEx @ 140001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyAdapterShutdownEx(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  bool bVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  *(undefined1 *)(param_1 + 0x92) = 0;
  lVar2 = param_1;
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Lq(lVar2,4,param_3,0x57,in_stack_ffffffffffffffd8,(char)param_2,(char)param_1)
      ;
    }
    (*DAT_1400081a0)(*(undefined8 *)(param_1 + 0x40),param_2);
    VmsNicPxyMiniportDeref(param_1);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Lq(lVar2,2,param_3,0x58,in_stack_ffffffffffffffd8,(char)param_2,(char)param_1);
  }
  return;
}



===== VmsNicPxyAllocateMiniport @ 1400010bc =====

longlong *
VmsNicPxyAllocateMiniport(longlong param_1,char param_2,ushort *param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong *plVar5;
  void *_Dst;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  uVar6 = 0x40;
  local_18 = 0;
  uVar9 = 0x6e536d56;
  plVar5 = (longlong *)ExAllocatePool2(0x40,0xd8);
  if (plVar5 == (longlong *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return (longlong *)0x0;
    }
    WPP_RECORDER_SF_(uVar6,2,uVar9,0x34);
    return (longlong *)0x0;
  }
  if (param_2 == '\0') {
    if ((*(longlong *)(param_3 + 4) == 0) || (0x7fff < *param_3)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0x35;
LAB_14000128f:
        WPP_RECORDER_SF_(uVar6,2,uVar9,uVar10);
      }
    }
    else {
      uVar6 = 0x40;
      uVar9 = 0x6e536d56;
      _Dst = (void *)ExAllocatePool2(0x40,*param_3);
      plVar5[4] = (longlong)_Dst;
      if (_Dst != (void *)0x0) {
        memmove(_Dst,*(void **)(param_3 + 4),(ulonglong)*param_3);
        *(ushort *)(plVar5 + 3) = *param_3;
        *(ushort *)((longlong)plVar5 + 0x1a) = *param_3;
        goto LAB_1400011bf;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0x36;
        goto LAB_14000128f;
      }
    }
    if (plVar5[4] != 0) {
      ExFreePoolWithTag(plVar5[4],0);
    }
    ExFreePoolWithTag(plVar5,0);
    plVar5 = (longlong *)0x0;
  }
  else {
    uVar2 = param_4[1];
    uVar3 = param_4[2];
    uVar4 = param_4[3];
    *(undefined4 *)(plVar5 + 5) = *param_4;
    *(undefined4 *)((longlong)plVar5 + 0x2c) = uVar2;
    *(undefined4 *)(plVar5 + 6) = uVar3;
    *(undefined4 *)((longlong)plVar5 + 0x34) = uVar4;
LAB_1400011bf:
    *(undefined4 *)((longlong)plVar5 + 0x9c) = 0;
    *(char *)(plVar5 + 2) = param_2;
    *(undefined2 *)((longlong)plVar5 + 0x91) = 1;
    plVar5[8] = param_1;
    KeInitializeSpinLock(plVar5 + 0x14);
    KeInitializeEvent(plVar5 + 0x15,0,0);
    KeInitializeEvent(plVar5 + 0x18,0,0);
    KeAcquireInStackQueuedSpinLock(&DAT_140008200,&local_28);
    puVar8 = auStack_58;
    puVar7 = &DAT_1400081f0;
    if ((longlong **)DAT_1400081f0[1] != &DAT_1400081f0) {
      puVar7 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      DAT_1400081f0 = (longlong *)(*pcVar1)();
      puVar8 = auStack_50;
    }
    plVar5[1] = (longlong)puVar7;
    *plVar5 = (longlong)DAT_1400081f0;
    DAT_1400081f0[1] = (longlong)plVar5;
    *(undefined8 *)(puVar8 + -8) = 0x14000126b;
    DAT_1400081f0 = plVar5;
    KeReleaseInStackQueuedSpinLock(puVar8 + 0x30);
    LOCK();
    DAT_140008208 = DAT_140008208 + 1;
    UNLOCK();
  }
  return plVar5;
}



===== VmsNicPxyCancelDirectOidRequest @ 1400012f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyCancelDirectOidRequest(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  lVar2 = param_1;
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(lVar2,4,param_3,0x4c,in_stack_ffffffffffffffe8,(char)param_1);
    }
    (*DAT_1400081b8)(*(undefined8 *)(param_1 + 0x40),param_2);
    VmsNicPxyMiniportDeref(param_1);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(lVar2,2,param_3,0x4d,in_stack_ffffffffffffffe8,(char)param_1);
  }
  return;
}



===== VmsNicPxyCancelOidRequest @ 140001380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyCancelOidRequest(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  lVar2 = param_1;
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(lVar2,4,param_3,0x48,in_stack_ffffffffffffffe8,(char)param_1);
    }
    (*DAT_1400081a8)(*(undefined8 *)(param_1 + 0x40),param_2);
    VmsNicPxyMiniportDeref(param_1);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(lVar2,2,param_3,0x49,in_stack_ffffffffffffffe8,(char)param_1);
  }
  return;
}



===== VmsNicPxyCancelSendNetBufferLists @ 140001410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyCancelSendNetBufferLists(longlong param_1)

{
  if ((DAT_140008180 != (code *)0x0) && (*(char *)(param_1 + 0x92) != '\0')) {
    (*DAT_140008180)(*(undefined8 *)(param_1 + 0x40));
  }
  return;
}



===== VmsNicPxyClose @ 140001440 =====

undefined8 VmsNicPxyClose(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(param_1,4,param_3,0x1b);
  }
  LOCK();
  DAT_140008120 = DAT_140008120 + -1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== VmsNicPxyCloseNDKAdapterHandler @ 1400014a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyCloseNDKAdapterHandler(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  lVar2 = param_1;
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(lVar2,4,param_3,0x5c,in_stack_ffffffffffffffe8,(char)param_1);
    }
    (*DAT_1400081d8)(*(undefined8 *)(param_1 + 0x40),param_2);
    LOCK();
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
    UNLOCK();
    VmsNicPxyMiniportDeref(param_1);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(lVar2,2,param_3,0x5d,in_stack_ffffffffffffffe8,(char)param_1);
  }
  return;
}



===== VmsNicPxyConfigRestore @ 140001540 =====

undefined8 VmsNicPxyConfigRestore(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  uVar2 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(param_1,4,param_3,100,in_stack_ffffffffffffffe8,(char)param_1);
  }
  puVar1 = VmsNicPxyFindMiniportByHandle(param_1);
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = puVar1[0x11];
    puVar1[0x11] = 0;
  }
  return uVar2;
}



===== VmsNicPxyConfigSave @ 1400015a0 =====

undefined8 VmsNicPxyConfigSave(longlong param_1,void *param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  void *_Dst;
  undefined8 uVar2;
  ulonglong _Size;
  undefined8 in_stack_ffffffffffffffc8;
  
  _Size = param_3 & 0xffffffff;
  uVar2 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(param_1,4,param_3,0x60,in_stack_ffffffffffffffc8,(char)param_1,(char)param_3)
    ;
  }
  puVar1 = VmsNicPxyFindMiniportByHandle(param_1);
  if ((puVar1 == (undefined8 *)0x0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if (puVar1[0x11] != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(param_1,4,param_3,0x62);
    }
    ExFreePoolWithTag(puVar1[0x11],0);
    puVar1[0x11] = 0;
  }
  _Dst = (void *)ExAllocatePool2(0x40,_Size,0x6e536d56);
  puVar1[0x11] = _Dst;
  if (_Dst == (void *)0x0) {
    uVar2 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D();
    }
  }
  else {
    memmove(_Dst,param_2,_Size);
  }
  return uVar2;
}



===== VmsNicPxyCreate @ 1400016d0 =====

undefined8 VmsNicPxyCreate(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(param_1,4,param_3,0x1a);
  }
  LOCK();
  DAT_140008120 = DAT_140008120 + 1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== VmsNicPxyDeviceControl @ 140001730 =====

int VmsNicPxyDeviceControl(undefined4 *param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(param_1,4,param_3,0x2c);
  }
  if ((*(char *)(param_2 + 0x40) == '\0') &&
     (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x220047)) {
    iVar1 = VmsNicPxySwitchRegister(param_1,param_2,param_3);
  }
  else {
    iVar1 = -0x3ffffff0;
  }
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qqd();
  }
  return iVar1;
}



===== VmsNicPxyDevicePnPEvent @ 1400017f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyDevicePnPEvent(longlong param_1,longlong param_2,undefined8 param_3)

{
  bool bVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = param_1;
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Lq(lVar2,4,param_3,0x4e,in_stack_ffffffffffffffd8,
                         (char)*(undefined4 *)(param_2 + 8),(char)param_1);
    }
    (*DAT_140008198)(*(undefined8 *)(param_1 + 0x40),param_2);
    VmsNicPxyMiniportDeref(param_1);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Lq(lVar2,2,param_3,0x4f,in_stack_ffffffffffffffd8,
                       (char)*(undefined4 *)(param_2 + 8),(char)param_1);
  }
  return;
}



===== VmsNicPxyDirectOidRequest @ 140001890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyDirectOidRequest(longlong param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DLq();
  }
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    iVar2 = (*DAT_1400081b0)(*(undefined8 *)(param_1 + 0x40),param_2);
    VmsNicPxyMiniportDeref(param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    iVar2 = -0x3ffeffef;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Dd();
  }
  return iVar2;
}



===== VmsNicPxyDriverUnload @ 140001940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyDriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(param_1,4,param_3,0x59);
  }
  if (DAT_140008150 != (code *)0x0) {
    (*DAT_140008150)(param_1);
  }
  return;
}



===== VmsNicPxyFindMiniportByHandle @ 140001988 =====

undefined8 * VmsNicPxyFindMiniportByHandle(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_140008200,&local_28);
  for (puVar1 = DAT_1400081f0;
      (puVar2 = (undefined8 *)0x0, (undefined8 **)puVar1 != &DAT_1400081f0 &&
      (puVar2 = puVar1, puVar1[7] != param_1)); puVar1 = (undefined8 *)*puVar1) {
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return puVar2;
}



===== VmsNicPxyHaltEx @ 140001a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyHaltEx(longlong *param_1,undefined4 param_2,undefined8 param_3)

{
  bool bVar1;
  longlong *plVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  *(undefined1 *)((longlong)param_1 + 0x92) = 0;
  plVar2 = param_1;
  bVar1 = VmsNicPxyMiniportRef((longlong)param_1);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Lq(plVar2,4,param_3,0x55,in_stack_ffffffffffffffd8,(char)param_2,(char)param_1
                        );
    }
    (*DAT_140008148)(param_1[8],param_2);
    VmsNicPxyMiniportDeref((longlong)param_1);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Lq(plVar2,2,param_3,0x56,in_stack_ffffffffffffffd8,(char)param_2,(char)param_1);
  }
  VmsNicPxyRemoveMiniport(param_1);
  return;
}



===== VmsNicPxyIMInitDevInstance @ 140001ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyIMInitDevInstance(longlong param_1,ushort *param_2,longlong param_3)

{
  ushort uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined2 uVar7;
  undefined8 in_stack_ffffffffffffff98;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if ((param_1 != DAT_1400081e0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_140008200);
  puVar6 = (undefined8 *)0x0;
  if ((undefined8 **)DAT_1400081f0 != &DAT_1400081f0) {
    uVar1 = *param_2;
    puVar5 = DAT_1400081f0;
    do {
      if ((*(ushort *)(puVar5 + 3) == uVar1) &&
         (iVar2 = memcmp((void *)puVar5[4],*(void **)(param_2 + 4),(ulonglong)uVar1),
         puVar6 = puVar5, iVar2 == 0)) break;
      puVar5 = (undefined8 *)*puVar5;
      puVar6 = (undefined8 *)0x0;
    } while ((undefined8 **)puVar5 != &DAT_1400081f0);
  }
  KeReleaseInStackQueuedSpinLock(&local_48);
  if (puVar6 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Zq();
    }
    plVar3 = VmsNicPxyAllocateMiniport(param_3,'\0',param_2,(undefined4 *)0x0);
    if (plVar3 == (longlong *)0x0) {
      iVar2 = -0x3fffff66;
      goto LAB_140001c76;
    }
    lVar4 = param_1;
    iVar2 = NdisIMInitializeDeviceInstanceEx(param_1,param_2);
    if (iVar2 == 0) {
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar7 = 0x3c;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Zq();
    }
    lVar4 = puVar6[7];
    plVar3 = puVar6 + 9;
    *(undefined1 *)(puVar6 + 0x12) = 1;
    puVar6[8] = param_3;
    puVar6[0xb] = param_3;
    iVar2 = (*DAT_140008140)(lVar4,0);
    if (iVar2 == 0) {
      *(undefined1 *)((longlong)puVar6 + 0x92) = 1;
      VmsNicPxyMiniportRefOpen((longlong)puVar6);
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar7 = 0x3e;
    param_1 = puVar6[7];
  }
  WPP_RECORDER_SF_qd(lVar4,2,plVar3,uVar7,in_stack_ffffffffffffff98,(char)param_1,(char)iVar2);
LAB_140001c76:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Zqd();
  }
  return iVar2;
}



===== VmsNicPxyIndicateStatus @ 140001cd0 =====

void VmsNicPxyIndicateStatus(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined8 in_stack_ffffffffffffffd8;
  
  puVar2 = VmsNicPxyFindMiniportByHandle(param_1);
  if ((puVar2 == (undefined8 *)0x0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if (*(int *)(param_2 + 0x14) == 0x40010017) {
    uVar4 = *(ulonglong *)(param_2 + 0x30);
    *(undefined4 *)((longlong)puVar2 + 0x94) = *(undefined4 *)(uVar4 + 4);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140001da6;
    uVar1 = (undefined1)*(undefined4 *)(uVar4 + 4);
    uVar5 = 0x51;
  }
  else {
    uVar3 = *(int *)(param_2 + 0x14) + 0xbffeffe8;
    uVar4 = (ulonglong)uVar3;
    if (uVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140001da6;
      uVar5 = 0x52;
    }
    else {
      if (uVar3 != 0x10048) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dq();
        }
        goto LAB_140001da6;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140001da6;
      uVar5 = 0x53;
    }
    uVar1 = (undefined1)**(undefined4 **)(param_2 + 0x30);
  }
  WPP_RECORDER_SF_Lq(uVar4,4,param_3,uVar5,in_stack_ffffffffffffffd8,uVar1,(char)param_1);
LAB_140001da6:
  NdisMIndicateStatusEx(param_1,param_2);
  return;
}



===== VmsNicPxyInitializeEx @ 140001de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyInitializeEx(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq();
  }
  lVar1 = param_3[2];
  *(undefined8 *)(lVar1 + 0x38) = param_1;
  param_3[2] = *(longlong *)(lVar1 + 0x40);
  uVar6 = param_3[1];
  *(undefined8 *)(lVar1 + 0x48) = *param_3;
  *(undefined8 *)(lVar1 + 0x50) = uVar6;
  uVar6 = param_3[3];
  *(undefined8 *)(lVar1 + 0x58) = param_3[2];
  *(undefined8 *)(lVar1 + 0x60) = uVar6;
  uVar2 = *(undefined4 *)((longlong)param_3 + 0x24);
  uVar3 = *(undefined4 *)(param_3 + 5);
  uVar4 = *(undefined4 *)((longlong)param_3 + 0x2c);
  *(undefined4 *)(lVar1 + 0x68) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(lVar1 + 0x6c) = uVar2;
  *(undefined4 *)(lVar1 + 0x70) = uVar3;
  *(undefined4 *)(lVar1 + 0x74) = uVar4;
  uVar2 = *(undefined4 *)((longlong)param_3 + 0x34);
  uVar3 = *(undefined4 *)(param_3 + 7);
  uVar4 = *(undefined4 *)((longlong)param_3 + 0x3c);
  *(undefined4 *)(lVar1 + 0x78) = *(undefined4 *)(param_3 + 6);
  *(undefined4 *)(lVar1 + 0x7c) = uVar2;
  *(undefined4 *)(lVar1 + 0x80) = uVar3;
  *(undefined4 *)(lVar1 + 0x84) = uVar4;
  uVar6 = param_1;
  iVar5 = (*DAT_140008140)(param_1,param_2);
  if ((iVar5 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(uVar6,2,param_3,0x2f,in_stack_ffffffffffffffc8,(char)param_1,(char)iVar5);
  }
  *(undefined1 *)(lVar1 + 0x92) = 1;
  VmsNicPxyMiniportRefOpen(lVar1);
  return iVar5;
}



===== VmsNicPxyIsMiniportReloaded @ 140001ec0 =====

undefined8 VmsNicPxyIsMiniportReloaded(longlong param_1,undefined1 *param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar3 = (undefined7)((ulonglong)param_1 >> 8);
  uVar2 = (char)param_1;
  puVar1 = VmsNicPxyFindMiniportByHandle(param_1);
  uVar4 = 0;
  if (puVar1 == (undefined8 *)0x0) {
    uVar4 = 0xc0010006;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(CONCAT71(uVar3,uVar2),2,param_3,0x71,in_stack_ffffffffffffffd8,
                         (char)param_1,6);
    }
  }
  else {
    *param_2 = *(undefined1 *)(puVar1 + 0x12);
  }
  return uVar4;
}



===== VmsNicPxyLWMInitialize @ 140001f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyLWMInitialize(longlong param_1,longlong param_2,longlong *param_3,longlong *param_4)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  iVar1 = 0;
  if ((param_1 != DAT_1400081e8) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_140008200,&local_38);
  for (plVar3 = DAT_1400081f0;
      (plVar2 = (longlong *)0x0, (longlong **)plVar3 != &DAT_1400081f0 &&
      ((plVar3[5] != *param_3 || (plVar2 = plVar3, plVar3[6] != param_3[1]))));
      plVar3 = (longlong *)*plVar3) {
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  if (plVar2 == (longlong *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF__guid_q();
    }
    plVar2 = VmsNicPxyAllocateMiniport(param_2,'\x01',(ushort *)0x0,(undefined4 *)param_3);
    if (plVar2 == (longlong *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = (*VmsNdisLWMInitializeNetworkInterface)(param_1,plVar2,param_3,plVar2 + 7);
      if (iVar1 == 0) goto LAB_1400020bb;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF__guid_d();
      }
      VmsNicPxyRemoveMiniport(plVar2);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF__guid_qd();
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF__guid_q();
    }
    *(undefined1 *)(plVar2 + 0x12) = 1;
    plVar2[8] = param_2;
LAB_1400020bb:
    *param_4 = plVar2[7];
  }
  return iVar1;
}



===== VmsNicPxyLWMStart @ 1400020f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyLWMStart(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 in_stack_ffffffffffffffd8;
  undefined1 uVar3;
  
  iVar1 = 0;
  uVar3 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(param_1,4,param_3,0x6c,in_stack_ffffffffffffffd8,uVar3);
  }
  puVar2 = VmsNicPxyFindMiniportByHandle(param_1);
  if ((puVar2 == (undefined8 *)0x0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  *(undefined1 *)((longlong)puVar2 + 0x92) = 1;
  VmsNicPxyMiniportRefOpen((longlong)puVar2);
  if (*(char *)(puVar2 + 0x12) != '\x01') {
    iVar1 = (*VmsNdisLWMStartNetworkInterface)();
    if ((iVar1 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(param_1,2,param_3,0x6e,in_stack_ffffffffffffffd8,uVar3,(char)iVar1);
    }
  }
  return iVar1;
}



===== VmsNicPxyLWMUninitialize @ 1400021c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyLWMUninitialize(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  undefined8 in_stack_ffffffffffffffe8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(param_1,4,param_3,0x6f,in_stack_ffffffffffffffe8,(char)param_1);
  }
  plVar1 = VmsNicPxyFindMiniportByHandle(param_1);
  if ((plVar1 == (longlong *)0x0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  (*VmsNdisLWMUninitializeNetworkInterface)(param_1);
  (*DAT_140008148)(plVar1[8],1);
  VmsNicPxyRemoveMiniport(plVar1);
  return;
}



===== VmsNicPxyMiniportDeref @ 140002268 =====

void VmsNicPxyMiniportDeref(longlong param_1)

{
  int *piVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xa0,&local_28);
  piVar1 = (int *)(param_1 + 0x9c);
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if (*(int *)(param_1 + 0x9c) == 0) {
    KeSetEvent(param_1 + 0xc0,0,0);
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== VmsNicPxyMiniportRef @ 140002308 =====

bool VmsNicPxyMiniportRef(longlong param_1)

{
  char cVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    KeWaitForSingleObject(param_1 + 0xa8,0,0,0,0);
  }
  KeAcquireInStackQueuedSpinLock(param_1 + 0xa0,&local_28);
  iVar2 = KeReadStateEvent(param_1 + 0xa8);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + 1;
    KeClearEvent(param_1 + 0xc0);
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return iVar2 != 0;
}



===== VmsNicPxyMiniportRefOpen @ 1400023d0 =====

void VmsNicPxyMiniportRefOpen(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xa0,&local_28);
  if ((*(int *)(param_1 + 0x9c) != 0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  KeSetEvent(param_1 + 0xa8,0,0);
  KeSetEvent(param_1 + 0xc0,0,0);
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== VmsNicPxyMiniportUnload @ 140002480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyMiniportUnload(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(param_1,4,param_3,0x65,in_stack_ffffffffffffffc8,(char)param_1);
  }
  puVar1 = VmsNicPxyFindMiniportByHandle(param_1);
  if ((puVar1 == (undefined8 *)0x0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  *(undefined1 *)((longlong)puVar1 + 0x92) = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(puVar1 + 0x14,&local_28);
  KeClearEvent(puVar1 + 0x15);
  KeReleaseInStackQueuedSpinLock(&local_28);
  KeWaitForSingleObject(puVar1 + 0x18,0,0,0,0);
  (*DAT_140008148)(puVar1[8],1);
  puVar1[8] = 0;
  puVar1[0xb] = 0;
  return;
}



===== VmsNicPxyNetPnPEvent @ 140002590 =====

int VmsNicPxyNetPnPEvent(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar2 = param_1;
  iVar1 = NdisMNetPnPEvent();
  if (iVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Lq(uVar2,4,&WPP_RECORDER_INITIALIZED,0x5f,in_stack_ffffffffffffffd8,
                         (char)*(undefined4 *)(param_2 + 8),(char)param_1);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Lqd();
  }
  return iVar1;
}



===== VmsNicPxyOidRequest @ 140002620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyOidRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_2 + 4);
  bVar2 = VmsNicPxyMiniportRef(param_1);
  if (bVar2) {
    iVar3 = (*DAT_140008168)(*(undefined8 *)(param_1 + 0x40),param_2);
    VmsNicPxyMiniportDeref(param_1);
  }
  else {
    iVar3 = -0x3ffeffef;
  }
  if ((iVar1 != 2) && (iVar3 != -0x3fffff45)) {
    if (iVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DL();
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DLd();
    }
  }
  return iVar3;
}



===== VmsNicPxyOpenNDKAdapterHandler @ 1400026e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyOpenNDKAdapterHandler(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(param_1,4,param_3,0x5a,in_stack_ffffffffffffffe8,(char)param_1);
  }
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    iVar2 = (*DAT_1400081d0)(*(undefined8 *)(param_1 + 0x40),param_2,param_3);
    if (iVar2 == 0) {
      LOCK();
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
      UNLOCK();
    }
    VmsNicPxyMiniportDeref(param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    iVar2 = -0x3ffeffef;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D();
  }
  return iVar2;
}



===== VmsNicPxyPause @ 1400027a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyPause(longlong param_1,longlong param_2,undefined8 param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Lq(param_1,4,param_3,0x40,in_stack_ffffffffffffffd8,
                       (char)*(undefined4 *)(param_2 + 8),(char)param_1);
  }
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    if ((*(char *)(param_1 + 0x91) != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
    iVar2 = (*DAT_140008158)(*(undefined8 *)(param_1 + 0x40),param_2);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x91) = 1;
    }
    VmsNicPxyMiniportDeref(param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    iVar2 = -0x3ffeffef;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D();
  }
  return iVar2;
}



===== VmsNicPxyRemoveMiniport @ 140002878 =====

void VmsNicPxyRemoveMiniport(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_140008200,&local_28);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) != param_1) ||
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  KeReleaseInStackQueuedSpinLock(&local_28);
  LOCK();
  iVar5 = DAT_140008208 + -1;
  UNLOCK();
  iVar3 = DAT_140008208 + -1;
  DAT_140008208 = iVar5;
  if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if ((*(int *)((longlong)param_1 + 0x9c) != 0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if (((int)param_1[0x13] != 0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if (param_1[4] != 0) {
    ExFreePoolWithTag(param_1[4],0);
  }
  if (param_1[0x11] != 0) {
    ExFreePoolWithTag(param_1[0x11],0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== VmsNicPxyRestart @ 1400029d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmsNicPxyRestart(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 in_stack_ffffffffffffffe8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(param_1,4,param_3,0x43,in_stack_ffffffffffffffe8,(char)param_1);
  }
  bVar1 = VmsNicPxyMiniportRef(param_1);
  if (bVar1) {
    if ((*(char *)(param_1 + 0x91) != '\x01') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
    iVar2 = (*DAT_140008160)(*(undefined8 *)(param_1 + 0x40),param_2);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x91) = 0;
    }
    VmsNicPxyMiniportDeref(param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    iVar2 = -0x3ffeffef;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D();
  }
  return iVar2;
}



===== VmsNicPxyReturnNetBufferLists @ 140002aa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyReturnNetBufferLists(longlong param_1)

{
  if ((DAT_140008178 != (code *)0x0) && (*(char *)(param_1 + 0x92) != '\0')) {
    (*DAT_140008178)(*(undefined8 *)(param_1 + 0x40));
  }
  return;
}



===== VmsNicPxySendNetBufferLists @ 140002ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxySendNetBufferLists(longlong param_1)

{
  if ((DAT_140008170 != (code *)0x0) && (*(char *)(param_1 + 0x92) != '\0')) {
    (*DAT_140008170)(*(undefined8 *)(param_1 + 0x40));
  }
  return;
}



===== VmsNicPxySetMiniportAttributes @ 140002b00 =====

int VmsNicPxySetMiniportAttributes(longlong param_1,char *param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 in_stack_ffffffffffffffc8;
  
  cVar1 = *param_2;
  iVar2 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(param_1,4,param_3,0x30,in_stack_ffffffffffffffc8,cVar1);
  }
  puVar3 = VmsNicPxyFindMiniportByHandle(param_1);
  if ((puVar3 == (undefined8 *)0x0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if (cVar1 == -0x62) {
    if ((puVar3[8] != *(longlong *)(param_2 + 8)) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
    *(undefined8 **)(param_2 + 8) = puVar3;
  }
  if (*(char *)(puVar3 + 0x12) == '\0') {
    lVar4 = param_1;
    iVar2 = NdisMSetMiniportAttributes(param_1,param_2);
    if ((iVar2 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(lVar4,2,param_3,0x33,in_stack_ffffffffffffffc8,(char)param_1,(char)iVar2);
    }
  }
  return iVar2;
}



===== VmsNicPxySetOptionalHandlers @ 140002c10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VmsNicPxySetOptionalHandlers(undefined8 param_1,char *param_2,undefined8 param_3)

{
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL();
  }
  if (*param_2 == -0x4e) {
    if ((*(short *)(param_2 + 2) == 0x18) && (param_2[1] == '\x01')) {
      _DAT_1400081c8 = *(undefined8 *)param_2;
      DAT_1400081d0 = *(undefined8 *)(param_2 + 8);
      DAT_1400081d8 = *(undefined8 *)(param_2 + 0x10);
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_Hc();
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    WPP_RECORDER_SF_L(param_1,2,param_3,0x13,in_stack_ffffffffffffffd8,*param_2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLd();
  }
  return 0xc000000d;
}



===== VmsNicPxySetOptionsHandler @ 140002d00 =====

int VmsNicPxySetOptionsHandler(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 in_stack_ffffffffffffffc8;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  code *local_18;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(param_1,4,param_3,0x10,in_stack_ffffffffffffffc8,(char)param_1);
  }
  local_24 = 0;
  local_20 = VmsNicPxyOpenNDKAdapterHandler;
  local_28 = 0x1801b2;
  local_18 = VmsNicPxyCloseNDKAdapterHandler;
  iVar1 = NdisSetOptionalHandlers(param_1,&local_28);
  if ((iVar1 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_D();
  }
  return iVar1;
}



===== VmsNicPxySwitchRegister @ 140002d9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int VmsNicPxySwitchRegister(undefined4 *param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  uint *puVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  undefined2 uVar6;
  code *pcVar7;
  bool bVar8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(param_1,4,param_3,0x1e);
  }
  lVar1 = *(longlong *)(param_2 + 0xb8);
  pcVar5 = (code *)0xa8;
  if ((*(uint *)(lVar1 + 0x10) < 0xa8) || (*(uint *)(lVar1 + 8) < 0x90)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D();
    }
    iVar3 = -0x3ffffff3;
    goto LAB_140003048;
  }
  if (DAT_140008124 != '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(param_1,2,0xa8,0x21);
    }
    iVar3 = -0x3fffffc8;
    goto LAB_140003048;
  }
  puVar2 = *(uint **)(lVar1 + 0x20);
  if ((puVar2[1] == 0) || (*puVar2 < 0xa8)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x22;
LAB_14000303c:
      WPP_RECORDER_SF_(param_1,2,pcVar5,uVar6);
    }
  }
  else {
    bVar8 = g_IsLWMSupported == '\0';
    param_1 = *(undefined4 **)(param_2 + 0x70);
    *(code **)(param_1 + 0x22) = VmsNicPxySwitchUnregister;
    *(code **)(param_1 + 0x20) = VmsNicPxyMiniportUnload;
    *(code **)(param_1 + 10) = VmsNicPxySetMiniportAttributes;
    *(code **)(param_1 + 0xc) = VmsNicPxyIndicateStatus;
    *(code **)(param_1 + 0x12) = VmsNicPxyNetPnPEvent;
    *(code **)(param_1 + 0xe) = VmsNicPxyIMInitDevInstance;
    *(code **)(param_1 + 0x10) = VmsNicPxySetOptionalHandlers;
    *(code **)(param_1 + 0x1c) = VmsNicPxyConfigSave;
    *(code **)(param_1 + 0x1e) = VmsNicPxyConfigRestore;
    *param_1 = 0x90;
    param_1[1] = 1;
    param_1[2] = 0xa8;
    param_1[3] = 1;
    if (bVar8) {
      pcVar4 = (code *)0x0;
      pcVar5 = (code *)0x0;
      pcVar7 = (code *)0x0;
    }
    else {
      pcVar4 = VmsNicPxyLWMUninitialize;
      pcVar5 = VmsNicPxyLWMStart;
      pcVar7 = VmsNicPxyLWMInitialize;
    }
    *(code **)(param_1 + 0x14) = pcVar7;
    *(code **)(param_1 + 0x16) = pcVar5;
    *(code **)(param_1 + 0x18) = pcVar4;
    *(code **)(param_1 + 0x1a) = VmsNicPxyIsMiniportReloaded;
    *(undefined8 *)(param_1 + 4) = DAT_1400081e0;
    *(undefined8 *)(param_1 + 6) = DAT_1400081e8;
    if (0 < DAT_140008108) {
      *(undefined1 *)(param_1 + 8) = 1;
    }
    if ((2 < *(byte *)((longlong)puVar2 + 9)) && (0x9f < *(ushort *)((longlong)puVar2 + 10))) {
      _DAT_140008128 = *(undefined8 *)(puVar2 + 2);
      uRam0000000140008130 = *(undefined8 *)(puVar2 + 4);
      DAT_140008138 = *(code **)(puVar2 + 6);
      DAT_140008140 = *(undefined8 *)(puVar2 + 8);
      DAT_140008148 = *(undefined8 *)(puVar2 + 10);
      DAT_140008150 = *(undefined8 *)(puVar2 + 0xc);
      DAT_140008158 = *(undefined8 *)(puVar2 + 0xe);
      DAT_140008160 = *(undefined8 *)(puVar2 + 0x10);
      DAT_140008168 = *(undefined8 *)(puVar2 + 0x12);
      DAT_140008170 = *(undefined8 *)(puVar2 + 0x14);
      DAT_140008178 = *(undefined8 *)(puVar2 + 0x16);
      DAT_140008180 = *(undefined8 *)(puVar2 + 0x18);
      _DAT_140008188 = *(undefined8 *)(puVar2 + 0x1a);
      uRam0000000140008190 = *(undefined8 *)(puVar2 + 0x1c);
      DAT_140008198 = *(undefined8 *)(puVar2 + 0x1e);
      DAT_1400081a0 = *(undefined8 *)(puVar2 + 0x20);
      DAT_1400081a8._0_4_ = puVar2[0x22];
      DAT_1400081a8._4_4_ = puVar2[0x23];
      DAT_1400081b0._0_4_ = puVar2[0x24];
      DAT_1400081b0._4_4_ = puVar2[0x25];
      DAT_1400081b8._0_4_ = puVar2[0x26];
      DAT_1400081b8._4_4_ = puVar2[0x27];
      uRam00000001400081c0 = puVar2[0x28];
      uRam00000001400081c4 = puVar2[0x29];
      iVar3 = (*DAT_140008138)(DAT_1400081e0,0);
      if (iVar3 == 0) {
        *(undefined8 *)(param_2 + 0x38) = 0x90;
        LOCK();
        DAT_140008108 = DAT_140008108 + 1;
        UNLOCK();
        DAT_140008124 = 1;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D();
      }
      if (-1 < iVar3) {
        return iVar3;
      }
      goto LAB_140003048;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x23;
      goto LAB_14000303c;
    }
  }
  iVar3 = -0x3fffffa8;
LAB_140003048:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd();
  }
  return iVar3;
}



===== VmsNicPxySwitchUnregister @ 140003090 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VmsNicPxySwitchUnregister(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(param_1,4,param_3,0x2b);
  }
  DAT_140008124 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_140008200);
  for (puVar1 = DAT_1400081f0; (undefined8 **)puVar1 != &DAT_1400081f0;
      puVar1 = (undefined8 *)*puVar1) {
    if ((*(char *)((longlong)puVar1 + 0x91) == '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
    if ((*(char *)((longlong)puVar1 + 0x92) != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
    if ((*(int *)((longlong)puVar1 + 0x9c) != 0) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
    if ((*(int *)(puVar1 + 0x13) != 0) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
    if ((puVar1[8] != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_s();
    }
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  memset(&DAT_140008128,0,0xa0);
  _DAT_1400081c8 = 0;
  DAT_1400081d0 = 0;
  DAT_1400081d8 = 0;
  return;
}



===== VmsNicPxyUnload @ 140003230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmsNicPxyUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(param_1,4,param_3,0x16);
  }
  if ((DAT_140008120 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
  {
    WPP_RECORDER_SF_s();
  }
  if ((DAT_140008208 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
  {
    WPP_RECORDER_SF_s();
  }
  if ((DAT_140008124 != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_s();
  }
  if (DAT_140008118 != 0) {
    NdisDeregisterDeviceEx();
    DAT_140008118 = 0;
  }
  if (DAT_1400081e0 != 0) {
    NdisMDeregisterMiniportDriver();
    DAT_1400081e0 = 0;
  }
  if ((g_IsLWMSupported != '\0') && (DAT_1400081e8 != 0)) {
    (*VmsNdisLWMDeregisterMiniportDriver)();
    DAT_1400081e8 = 0;
  }
  WppCleanupKm(param_1);
  return;
}



===== WPP_RECORDER_SF_ @ 140003358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4)

{
  undefined8 uVar1;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,0);
  }
  WppAutoLogTrace(uVar1,param_2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1400033f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(void)

{
  undefined8 uVar1;
  undefined2 in_R9W;
  undefined1 uStack0000000000000030;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_DL @ 1400034a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DL(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x47,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x47,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_DLd @ 140003574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DLd(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x46,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x46,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_DLq @ 140003664 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DLq(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x4a,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x4a,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_Dd @ 14000375c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x4b,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x4b,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_Hc @ 140003830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Hc(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x14,&uStack0000000000000030,2,
               &uStack0000000000000038,1,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x14,
                  &uStack0000000000000030,2,&uStack0000000000000038,1,0);
  return;
}



===== WPP_RECORDER_SF_L @ 140003908 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  undefined8 uVar1;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(uVar1,param_2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,
                  4,0);
  return;
}



===== WPP_RECORDER_SF_Lq @ 1400039c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lq(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 uVar1;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(uVar1,param_2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,
                  4,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_Lqd @ 140003aa4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lqd(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x5e,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x5e,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_Zq @ 140003b9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Zq(void)

{
  undefined8 uVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  undefined2 in_R9W;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = VmsNicPrxyIfrLog;
  pwVar4 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  goto LAB_140003c69;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    wVar3 = L'\b';
LAB_140003c0e:
    pwVar5 = L"NULL";
  }
  else {
    wVar3 = *in_stack_00000030;
    if (*in_stack_00000030 == L'\0') goto LAB_140003c0e;
    pwVar5 = *(wchar_t **)(in_stack_00000030 + 4);
  }
  pwVar2 = in_stack_00000030;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,pwVar2,2,pwVar5,wVar3,
             &uStack0000000000000038,8,0);
LAB_140003c69:
  if (in_stack_00000030 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *in_stack_00000030;
    if (*in_stack_00000030 != L'\0') {
      pwVar4 = *(wchar_t **)(in_stack_00000030 + 4);
    }
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"\b";
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,
                  in_stack_00000030,2,pwVar4,wVar3,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_Zqd @ 140003d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Zqd(void)

{
  undefined8 uVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = VmsNicPrxyIfrLog;
  pwVar4 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  goto LAB_140003dea;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    wVar3 = L'\b';
LAB_140003d73:
    pwVar5 = L"NULL";
  }
  else {
    wVar3 = *in_stack_00000030;
    if (*in_stack_00000030 == L'\0') goto LAB_140003d73;
    pwVar5 = *(wchar_t **)(in_stack_00000030 + 4);
  }
  pwVar2 = in_stack_00000030;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x3f,pwVar2,2,pwVar5,wVar3,
             &uStack0000000000000038,8,&uStack0000000000000040,4,0);
LAB_140003dea:
  if (in_stack_00000030 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *in_stack_00000030;
    if (*in_stack_00000030 != L'\0') {
      pwVar4 = *(wchar_t **)(in_stack_00000030 + 4);
    }
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"\b";
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x3f,in_stack_00000030,
                  2,pwVar4,wVar3,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF__guid_d @ 140003e94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_d(void)

{
  undefined8 uVar1;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x69);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x69);
  return;
}



===== WPP_RECORDER_SF__guid_q @ 140003f74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_q(void)

{
  undefined8 uVar1;
  undefined2 in_R9W;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W);
  return;
}



===== WPP_RECORDER_SF__guid_qd @ 140004050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_qd(void)

{
  undefined8 uVar1;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x6b);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x6b);
  return;
}



===== WPP_RECORDER_SF_dq @ 140004158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dq(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x54,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x54,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_q @ 140004230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  undefined8 uVar1;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(uVar1,param_2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,
                  8,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 1400042e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x12,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x12,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qLd @ 1400043c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLd(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x15,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x15,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qZd @ 1400044b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qZd(void)

{
  undefined8 uVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = VmsNicPrxyIfrLog;
  pwVar4 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  goto LAB_1400045a2;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar3 = L'\b';
LAB_14000452b:
    pwVar5 = L"NULL";
  }
  else {
    wVar3 = *in_stack_00000038;
    if (*in_stack_00000038 == L'\0') goto LAB_14000452b;
    pwVar5 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  pwVar2 = in_stack_00000038;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0xe,&uStack0000000000000030,8,pwVar2,2
             ,pwVar5,wVar3,&uStack0000000000000040,4,0);
LAB_1400045a2:
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *in_stack_00000038;
    if (*in_stack_00000038 != L'\0') {
      pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
    }
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"\b";
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0xe,
                  &uStack0000000000000030,8,in_stack_00000038,2,pwVar4,wVar3,&uStack0000000000000040
                  ,4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 14000464c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 uVar1;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(uVar1,param_2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,param_4,&param_6,
                  8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 140004730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x2e,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,0x2e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 140004804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(void)

{
  undefined8 uVar1;
  undefined2 in_R9W;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_s @ 140004900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(void)

{
  undefined8 uVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined2 in_R9W;
  char *in_stack_00000030;
  
  uVar1 = VmsNicPrxyIfrLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000030[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar2 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,pcVar2,lVar4,0);
  }
  lVar4 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar4;
      lVar4 = lVar3 + 1;
    } while (in_stack_00000030[lVar4] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(uVar1,1,2,&WPP_e253201fc8ca302e1ad6f33d7cbd661a_Traceguids,in_R9W,
                  in_stack_00000030,lVar3,0);
  return;
}



===== WppClassicProviderCallback @ 140004a20 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== _guard_check_icall @ 140004a90 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140004aa8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140004acc =====

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



===== __cpu_features_init @ 140004b40 =====

/* WARNING: Removing unreachable block (ram,0x000140004baa) */
/* WARNING: Removing unreachable block (ram,0x000140004b59) */
/* WARNING: Removing unreachable block (ram,0x000140004b4a) */

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



===== __security_check_cookie @ 140004c10 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140004c50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140004c80 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140004c80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140004cb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140004ce0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140004d23;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140004d94;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140004d90:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140004d94;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140004d8c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140004d90;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140004d8c;
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
LAB_140004d94:
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
LAB_140004d23:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140004e00 =====

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



===== memset @ 140005100 =====

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



===== __memset_repmovs @ 140005240 =====

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



===== __memset_query @ 1400052c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140005340 =====

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



===== __memset_spec_ermsb_repmovsb @ 140005480 =====

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



===== __memset_spec_plain @ 140005500 =====

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



===== WppCleanupKm @ 14000b008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 14000b0b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 14000b194 =====

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



===== WppTraceCallback @ 14000b2e0 =====

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



===== entry @ 14000c010 =====

void entry(longlong param_1,undefined8 *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14000c044 =====

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



===== DriverEntry @ 14000c078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  undefined *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined1 auStack_348 [32];
  undefined8 *local_328;
  longlong local_320;
  undefined8 *local_318;
  int local_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 *puStack_2f0;
  undefined8 *local_2e8;
  code **ppcStack_2e0;
  undefined8 local_2d8;
  undefined *puStack_2d0;
  undefined8 local_2c8;
  undefined8 local_2c0;
  undefined8 uStack_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined8 local_2a0;
  undefined8 uStack_298;
  undefined8 local_288;
  undefined4 local_280;
  undefined4 local_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  code *local_268;
  code *local_260;
  code *local_258;
  code *local_250;
  code *local_248;
  code *local_240;
  code *local_238;
  code *local_230;
  code *local_228;
  code *local_220;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  code *local_1f8;
  code *local_1f0;
  code *local_1e8;
  code *local_1e0;
  code *local_1d8;
  code *local_1d0;
  code *local_1c8;
  code *local_1c0;
  code *local_1b8;
  code *local_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  code *local_198;
  code *local_190;
  code *local_188;
  code *local_180;
  code *local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  ulonglong local_138 [4];
  code *local_118 [2];
  code *local_108;
  code *local_a8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_348;
  local_138[2] = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138[0] = 0;
  local_138[1] = 0;
  local_2b0 = 0;
  uStack_2a8 = 0;
  local_2a0 = 0;
  uStack_298 = 0;
  memset(local_118,0,0xe0);
  local_1fc = 0;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_170 = 0;
  local_2c0 = 0;
  uStack_2b8 = 0;
  memset(&local_288,0,0x78);
  _DAT_140008268 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140008250 = 0;
  local_2c8 = 0;
  DAT_140008248 = &WPP_ThisDir_CTLGUID_VmsNicProxy;
  local_2f8 = 0;
  puStack_2f0 = (undefined8 *)0x0;
  _DAT_140008260 = 0;
  local_2e8 = (undefined8 *)0x0;
  ppcStack_2e0 = (code **)0x0;
  _DAT_140008280 = 0;
  local_2d8 = 0;
  puStack_2d0 = (undefined *)0x0;
  _DAT_140008288 = 0;
  local_308 = 0;
  uStack_300 = 0;
  WppLoadTracingSupport();
  _DAT_140008260 = 0;
  WppInitKm(param_1,param_2);
  local_158 = 0x38;
  local_138[0] = local_138[0] & 0xffffffffffffff00;
  uStack_140 = CONCAT44(0x10,(undefined4)uStack_140);
  local_148 = 0;
  uStack_140 = uStack_140 & 0xffffffffffffff00;
  puVar4 = local_138;
  lVar6 = 0x10;
  do {
    if ((lVar6 == -0x7fffffee) ||
       (cVar1 = *(char *)((longlong)puVar4 + ((longlong)"Global" - (longlong)local_138)),
       cVar1 == '\0')) break;
    *(char *)puVar4 = cVar1;
    puVar4 = (ulonglong *)((longlong)puVar4 + 1);
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  puVar7 = &VmsNicPrxyIfrLog;
  puVar3 = (ulonglong *)((longlong)puVar4 + -1);
  if (lVar6 != 0) {
    puVar3 = puVar4;
  }
  *(char *)puVar3 = '\0';
  local_138[2] = 0x200000002;
  uStack_150 = 0x333300010000;
  iVar2 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_158);
  puVar5 = WPP_GLOBAL_Control;
  if (iVar2 == 0) {
    uStack_160 = 0x200000002;
    local_168 = CONCAT35(local_168._5_3_,0x10);
    imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_168);
  }
  else {
    cVar1 = imp_WppRecorderIsDefaultLogAvailable();
    if (cVar1 != '\0') {
      puVar5 = WPP_GLOBAL_Control;
      VmsNicPrxyIfrLog = imp_WppRecorderLogGetDefault();
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(puVar5,4,puVar7,10);
  }
  RtlInitUnicodeString(&local_308,L"NdisLWMRegisterMiniportDriver");
  VmsNdisLWMRegisterMiniportDriver = (code *)NdisGetRoutineAddress(&local_308);
  RtlInitUnicodeString(&local_308,L"NdisLWMDeregisterMiniportDriver");
  VmsNdisLWMDeregisterMiniportDriver = NdisGetRoutineAddress(&local_308);
  RtlInitUnicodeString(&local_308,L"NdisLWMInitializeNetworkInterface");
  VmsNdisLWMInitializeNetworkInterface = NdisGetRoutineAddress(&local_308);
  RtlInitUnicodeString(&local_308,L"NdisLWMStartNetworkInterface");
  VmsNdisLWMStartNetworkInterface = NdisGetRoutineAddress(&local_308);
  RtlInitUnicodeString(&local_308,L"NdisLWMUninitializeNetworkInterface");
  VmsNdisLWMUninitializeNetworkInterface = NdisGetRoutineAddress(&local_308);
  if ((((VmsNdisLWMRegisterMiniportDriver == (code *)0x0) ||
       (VmsNdisLWMDeregisterMiniportDriver == 0)) || (VmsNdisLWMInitializeNetworkInterface == 0)) ||
     ((VmsNdisLWMStartNetworkInterface == 0 ||
      (g_IsLWMSupported = '\x01', VmsNdisLWMUninitializeNetworkInterface == 0)))) {
    g_IsLWMSupported = '\0';
  }
  local_208 = 0xa0038a;
  local_1f0 = VmsNicPxyInitializeEx;
  local_204 = 0x1015306;
  local_1e8 = VmsNicPxyHaltEx;
  puVar8 = (undefined8 *)0x0;
  local_1d8 = VmsNicPxyPause;
  local_1e0 = VmsNicPxyDriverUnload;
  local_200 = 1;
  local_1d0 = VmsNicPxyRestart;
  local_1c8 = VmsNicPxyOidRequest;
  local_188 = VmsNicPxyCancelOidRequest;
  local_180 = VmsNicPxyDirectOidRequest;
  local_178 = VmsNicPxyCancelDirectOidRequest;
  local_1c0 = VmsNicPxySendNetBufferLists;
  local_1b8 = VmsNicPxyReturnNetBufferLists;
  local_1b0 = VmsNicPxyCancelSendNetBufferLists;
  local_198 = VmsNicPxyDevicePnPEvent;
  local_190 = VmsNicPxyAdapterShutdownEx;
  local_1f8 = VmsNicPxySetOptionsHandler;
  local_328 = &DAT_1400081e0;
  puVar7 = param_2;
  iVar2 = NdisMRegisterMiniportDriver(param_1,param_2,0,&local_208);
  if (iVar2 == 0) {
    if (g_IsLWMSupported != '\0') {
      local_288._0_4_ = 0x7801c7;
      local_288._4_4_ = 0x1015106;
      RtlInitUnicodeString(&local_2c0,L"VMSNPXY");
      local_260 = VmsNicPxyPause;
      local_258 = VmsNicPxyRestart;
      puVar8 = &DAT_1400081e8;
      local_280 = 1;
      local_250 = VmsNicPxyOidRequest;
      puVar7 = &local_288;
      local_230 = VmsNicPxyCancelOidRequest;
      local_228 = VmsNicPxyDirectOidRequest;
      local_220 = VmsNicPxyCancelDirectOidRequest;
      local_248 = VmsNicPxySendNetBufferLists;
      local_240 = VmsNicPxyReturnNetBufferLists;
      local_238 = VmsNicPxyCancelSendNetBufferLists;
      local_268 = VmsNicPxySetOptionsHandler;
      local_278 = (undefined4)local_2c0;
      uStack_274 = local_2c0._4_4_;
      uStack_270 = (undefined4)uStack_2b8;
      uStack_26c = uStack_2b8._4_4_;
      iVar2 = (*VmsNdisLWMRegisterMiniportDriver)(0);
      if (iVar2 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000c6e7;
        goto LAB_14000c6c2;
      }
    }
    local_2f8 = 0x380185;
    local_2d8 = 0;
    local_2c8 = 0;
    RtlInitUnicodeString(&local_2b0,L"\\Device\\VmsNicProxy");
    RtlInitUnicodeString(&local_2a0,L"\\DosDevices\\VmsNicProxy");
    puStack_2f0 = &local_2b0;
    local_2e8 = &local_2a0;
    puVar8 = (undefined8 *)&DAT_140008110;
    local_118[0] = VmsNicPxyCreate;
    puVar7 = &local_2f8;
    local_108 = VmsNicPxyClose;
    local_a8 = VmsNicPxyDeviceControl;
    ppcStack_2e0 = local_118;
    puStack_2d0 = &VmsNicPxyDeviceSddlString;
    iVar2 = NdisRegisterDeviceEx(DAT_1400081e0,puVar7,&DAT_140008110,&DAT_140008118);
    if (iVar2 == 0) {
      puVar5 = &DAT_140008200;
      _DAT_1400081f8 = &DAT_1400081f0;
      DAT_1400081f0 = &DAT_1400081f0;
      _Driver = param_1;
      KeInitializeSpinLock();
      *(code **)(param_1 + 0x68) = VmsNicPxyUnload;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_(puVar5,2,puVar8,0xf);
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000c6e7;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000c6e7;
LAB_14000c6c2:
  local_320 = CONCAT44(local_320._4_4_,iVar2);
  WPP_RECORDER_SF_D();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    local_320 = param_1;
    local_318 = param_2;
    local_310 = iVar2;
    WPP_RECORDER_SF_qZd();
  }
LAB_14000c6e7:
  VmsNicPxyUnload(param_1,puVar7,puVar8);
  return iVar2;
}


