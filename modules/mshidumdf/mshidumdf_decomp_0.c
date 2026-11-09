
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



===== HandleIdleNotification @ 1c0001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HandleIdleNotification(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  int iVar6;
  
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x10) {
    iVar6 = -0x3fffffdd;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
    goto LAB_1c00010ca;
  }
  puVar4 = *(undefined8 **)(*(longlong *)(param_2 + 0xb8) + 0x20);
  (*(code *)*puVar4)(puVar4[1]);
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x38);
  LOCK();
  *(code **)(param_2 + 0x68) = IdleNotificationCancellation;
  UNLOCK();
  if (*(char *)(param_2 + 0x44) == '\0') {
LAB_1c000109b:
    iVar6 = 0x103;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    *(longlong *)(lVar3 + 0x40) = param_2;
  }
  else {
    LOCK();
    lVar2 = *(longlong *)(param_2 + 0x68);
    *(longlong *)(param_2 + 0x68) = 0;
    UNLOCK();
    if (lVar2 == 0) goto LAB_1c000109b;
    iVar6 = -0x3ffffee0;
  }
  KeReleaseSpinLock(lVar3 + 0x38,uVar5);
  if (iVar6 != -0x3ffffee0) {
    return iVar6;
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  iVar6 = -0x3ffffee0;
LAB_1c00010ca:
  IofCompleteRequest(param_2,0);
  return iVar6;
}



===== HidUmdfCreateCleanupClose @ 1c0001100 =====

undefined4 HidUmdfCreateCleanupClose(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  if (((**(byte **)(param_2 + 0xb8) & 0xed) == 0) && (**(byte **)(param_2 + 0xb8) != 0x10)) {
    uVar1 = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  else {
    uVar1 = 0xc000000d;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== HidUmdfGetSettings @ 1c000114c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 HidUmdfGetSettings(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  lVar2 = puVar1[2];
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_38,L"EnableDefaultIdleNotificationHandler");
  local_40 = 0;
  iVar3 = IoOpenDeviceRegistryKey(*puVar1,1,0x20019,&local_40);
  if (-1 < iVar3) {
    local_50 = local_48;
    local_48[0] = 0;
    local_58 = 0x10;
    local_28 = 0;
    uStack_20 = 0;
    iVar3 = ZwQueryValueKey(local_40,&local_38,2,&local_28);
    if ((-1 < iVar3) && ((int)uStack_20 == 4)) {
      *(bool *)(lVar2 + 0x30) = uStack_20._4_4_ != 0;
    }
    ZwClose(local_40);
  }
  return 0;
}



===== HidUmdfInternalIoctl @ 1c0001240 =====

ulonglong HidUmdfInternalIoctl(longlong param_1,ulonglong param_2)

{
  byte *pbVar1;
  byte bVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  bVar2 = KeGetCurrentIrql();
  if (bVar2 < 2) {
    uVar3 = HidUmdfInternalIoctlWorker(param_1,param_2);
  }
  else {
    lVar4 = IoAllocateWorkItem();
    if (lVar4 == 0) {
      *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
      IofCompleteRequest(param_2,0);
      uVar3 = 0xc000009a;
    }
    else {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      IoQueueWorkItemEx(lVar4,IoctlWorkItemEx,1,param_2);
      uVar3 = 0x103;
    }
  }
  return uVar3;
}



===== HidUmdfInternalIoctlWorker @ 1c00012dc =====

ulonglong HidUmdfInternalIoctlWorker(longlong param_1,ulonglong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  undefined4 extraout_var;
  ulonglong uVar9;
  int local_res8 [2];
  
  bVar7 = false;
  bVar6 = 1;
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  puVar2[-9] = *puVar2;
  puVar2[-8] = puVar2[1];
  puVar2[-7] = puVar2[2];
  puVar2[-6] = puVar2[3];
  puVar2[-5] = puVar2[4];
  puVar2[-4] = puVar2[5];
  puVar2[-3] = puVar2[6];
  *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_res8[0] = *(int *)(lVar4 + -0x30);
  *(undefined1 *)(lVar4 + -0x48) = 0xe;
  if (local_res8[0] == 0xb000f) goto LAB_1c00013cf;
  if (local_res8[0] == 0xb0013) {
    puVar1 = (undefined8 *)(param_2 + 0x18);
    uVar5 = *puVar1;
    *puVar1 = puVar2[4];
    puVar2[4] = uVar5;
    *(undefined8 **)(lVar4 + -0x28) = puVar1;
LAB_1c0001394:
    *(undefined4 *)(lVar4 + -0x38) = 4;
LAB_1c00013ff:
    bVar7 = true;
    iVar8 = local_res8[0];
  }
  else {
    iVar8 = local_res8[0];
    if (local_res8[0] == 0xb002b) {
      if (*(char *)(lVar3 + 0x30) != '\0') {
        iVar8 = HandleIdleNotification(param_1,param_2);
        return CONCAT44(extraout_var,iVar8);
      }
    }
    else {
      if (((local_res8[0] == 0xb0191) || (local_res8[0] == 0xb0192)) || (local_res8[0] == 0xb0195))
      {
LAB_1c00013cf:
        uVar9 = UpdateBufferLocationAndIoctl(param_2,local_res8);
        if ((int)uVar9 < 0) {
          *(int *)(param_2 + 0x30) = (int)uVar9;
          IofCompleteRequest(param_2,0);
          return uVar9 & 0xffffffff;
        }
        goto LAB_1c00013ff;
      }
      if (local_res8[0] == 0xb019a) {
        iVar8 = 0xb0063;
      }
      else {
        if (local_res8[0] == 0xb01a2) goto LAB_1c00013cf;
        if (local_res8[0] == 0xb01e2) {
          puVar2[4] = *(undefined8 *)(param_2 + 0x18);
          *(longlong *)(param_2 + 0x18) = lVar4 + -0x28;
          goto LAB_1c0001394;
        }
      }
    }
  }
  *(int *)(lVar4 + -0x30) = iVar8;
  if (*(char *)(param_2 + 0x40) == '\x01') {
    *(undefined1 *)(param_2 + 0x40) = 0;
  }
  else {
    bVar6 = 0;
    if (!bVar7) goto LAB_1c000143c;
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = UserIoctlCompletion;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  *(ulonglong *)(lVar3 + -8) = -(ulonglong)bVar6 & param_2;
LAB_1c000143c:
  uVar9 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  return uVar9;
}



===== HidUmdfNotifyPresence @ 1c0001470 =====

void HidUmdfNotifyPresence(void)

{
  HidNotifyPresence();
  return;
}



===== HidUmdfPassThrough @ 1c0001490 =====

void HidUmdfPassThrough(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8));
  return;
}



===== HidUmdfPowerPassThrough @ 1c00014e0 =====

void HidUmdfPowerPassThrough(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  PoStartNextPowerIrp(param_2);
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  PoCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  return;
}



===== HidUmdfQuerySetFlush @ 1c0001560 =====

undefined8 HidUmdfQuerySetFlush(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  IofCompleteRequest(param_2,0);
  return 0xc0000010;
}



===== IdleNotificationCancellation @ 1c0001590 =====

void IdleNotificationCancellation(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x38);
  *(undefined8 *)(lVar1 + 0x40) = 0;
  KeReleaseSpinLock(lVar1 + 0x38,uVar2);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  return;
}



===== SendIrpSynchronously @ 1c0001610 =====

ulonglong SendIrpSynchronously(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar1 + -0x10) = SyncIrpCompletion;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  uVar2 = IofCallDriver(param_1,param_2);
  if ((int)uVar2 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar2 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar2;
}



===== SyncIrpCompletion @ 1c00016c0 =====

undefined8 SyncIrpCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  if ((param_3 != 0) && (*(char *)(param_2 + 0x41) == '\x01')) {
    KeSetEvent(param_3,0,0);
  }
  return 0xc0000016;
}



===== UpdateBufferLocationAndIoctl @ 1c00016f8 =====

undefined8 UpdateBufferLocationAndIoctl(longlong param_1,int *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x70);
  iVar4 = *(int *)(lVar2 + -0x30);
  if (puVar3 == (undefined8 *)0x0) {
    return 0xc000000d;
  }
  iVar1 = *(int *)(lVar2 + 0x18);
  *(undefined8 **)(lVar2 + 0x20) = puVar3;
  if ((iVar1 == 0xb000f) || (iVar1 == 0xb0191)) {
LAB_1c0001766:
    if (*(uint *)(lVar2 + 0x10) < 0x10) {
      return 0xc000000d;
    }
    *(undefined8 *)(lVar2 + -0x28) = *puVar3;
    *(undefined4 *)(lVar2 + -0x38) = *(undefined4 *)(puVar3 + 1);
    *(uint *)(lVar2 + -0x40) = (uint)*(byte *)((longlong)puVar3 + 0xc);
    *(undefined **)(param_1 + 0x70) = &G_ScratchBuffer;
  }
  else {
    if (iVar1 != 0xb0192) {
      if (iVar1 == 0xb0195) goto LAB_1c0001766;
      if (iVar1 != 0xb01a2) goto LAB_1c0001790;
    }
    if (*(uint *)(lVar2 + 8) < 0x10) {
      return 0xc000000d;
    }
    *(undefined4 *)(lVar2 + -0x38) = 1;
    *(longlong *)(lVar2 + -0x28) = (longlong)puVar3 + 0xc;
    *(undefined8 *)(param_1 + 0x70) = *puVar3;
    *(undefined4 *)(lVar2 + -0x40) = *(undefined4 *)(puVar3 + 1);
  }
LAB_1c0001790:
  if (iVar4 == 0xb0191) {
    iVar4 = 0xb0053;
  }
  else if (iVar4 == 0xb0192) {
    iVar4 = 0xb0057;
  }
  else if (iVar4 == 0xb0195) {
    iVar4 = 0xb005b;
  }
  else if (iVar4 == 0xb01a2) {
    iVar4 = 0xb005f;
  }
  *param_2 = iVar4;
  return 0;
}



===== UserIoctlCompletion @ 1c00017e0 =====

undefined8 UserIoctlCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (param_3 != 0) {
    *(undefined1 *)(param_2 + 0x40) = 1;
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  iVar2 = *(int *)(lVar3 + 0x18);
  if (iVar2 == 0xb000f) {
LAB_1c000183a:
    *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(lVar3 + 0x20);
  }
  else {
    if (iVar2 != 0xb0013) {
      if ((((iVar2 == 0xb0191) || (iVar2 == 0xb0192)) || (iVar2 == 0xb0195)) || (iVar2 == 0xb01a2))
      goto LAB_1c000183a;
      if (iVar2 != 0xb01e2) {
        return 0;
      }
    }
    *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(lVar3 + 0x20);
  }
  return 0;
}



===== _guard_check_icall @ 1c0001860 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0001878 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000189c =====

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



===== __cpu_features_init @ 1c0001910 =====

/* WARNING: Removing unreachable block (ram,0x0001c000197a) */
/* WARNING: Removing unreachable block (ram,0x0001c0001929) */
/* WARNING: Removing unreachable block (ram,0x0001c000191a) */

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



===== __security_check_cookie @ 1c00019e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001a20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001a50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001a80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1c0001b00 =====

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



===== __memset_repmovs @ 1c0001c40 =====

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



===== __memset_query @ 1c0001cc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0001d40 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0001e80 =====

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



===== __memset_spec_plain @ 1c0001f00 =====

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



===== HandleQueryId @ 1c0007008 =====

undefined4 HandleQueryId(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  
  puVar3 = *(undefined8 **)(param_2 + 0xb8);
  iVar1 = *(int *)(puVar3 + 1);
  puVar3[-9] = *puVar3;
  puVar3[-8] = puVar3[1];
  puVar3[-7] = puVar3[2];
  puVar3[-6] = puVar3[3];
  puVar3[-5] = puVar3[4];
  puVar3[-4] = puVar3[5];
  puVar3[-3] = puVar3[6];
  *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
  uVar4 = SendIrpSynchronously(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  if (((iVar1 != 0) && (iVar1 == 1)) && ((int)uVar4 < 0)) {
    puVar5 = (undefined4 *)ExAllocatePool2(0x100,6,0x55646948);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = 0;
      *(undefined2 *)(puVar5 + 1) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(undefined4 **)(param_2 + 0x38) = puVar5;
    }
  }
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== HidUmdfAddDevice @ 1c00070c0 =====

void HidUmdfAddDevice(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  puVar1 = *(undefined8 **)(*(longlong *)(param_2 + 0x40) + 0x10);
  *(undefined8 *)((longlong)puVar1 + 4) = 0;
  *(undefined8 *)((longlong)puVar1 + 0xc) = 0;
  *(undefined8 *)((longlong)puVar1 + 0x14) = 0;
  *(undefined4 *)((longlong)puVar1 + 0x1c) = 0;
  puVar1[5] = param_2;
  *(undefined4 *)puVar1 = 0x10030;
  puVar1[4] = HidUmdfNotifyPresence;
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 8);
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar3 >> 8),*(undefined1 *)(lVar3 + 0x4c)));
  if (lVar3 != 0) {
    lVar2 = *(longlong *)(lVar3 + 0xb8);
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    memset((undefined2 *)(lVar2 + -0x48),0,0x48);
    *(undefined8 *)(lVar2 + -0x28) = 0;
    *(undefined **)(lVar2 + -0x40) = &GUID_WDF_HID_INTERFACE_STANDARD;
    *(undefined2 *)(lVar2 + -0x48) = 0x81b;
    *(undefined4 *)(lVar2 + -0x38) = 0x10030;
    *(undefined8 **)(lVar2 + -0x30) = puVar1;
    uVar4 = SendIrpSynchronously(*(undefined8 *)(*(longlong *)(param_2 + 0x40) + 8),lVar3);
    if ((int)uVar4 < 0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
    }
    IoFreeIrp(lVar3);
  }
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x10);
  *(undefined8 *)(lVar3 + 0x40) = 0;
  *(undefined1 *)(lVar3 + 0x30) = 0;
  KeInitializeSpinLock(lVar3 + 0x38);
  uVar5 = HidUmdfGetSettings(param_2);
  if (-1 < (int)uVar5) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xffffff7f;
  }
  return;
}



===== HidUmdfPnp @ 1c00071f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HidUmdfPnp(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  short *psVar2;
  
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  if (*(char *)((longlong)puVar1 + 1) == '\x02') {
    psVar2 = *(short **)(*(longlong *)(param_1 + 0x40) + 0x10);
    if ((*psVar2 == 0x30) && (psVar2[1] == 1)) {
      (**(code **)(psVar2 + 0xc))(*(undefined8 *)(psVar2 + 4));
      psVar2[0] = 0;
      psVar2[1] = 0;
      psVar2[2] = 0;
      psVar2[3] = 0;
      psVar2[4] = 0;
      psVar2[5] = 0;
      psVar2[6] = 0;
      psVar2[7] = 0;
      psVar2[8] = 0;
      psVar2[9] = 0;
      psVar2[10] = 0;
      psVar2[0xb] = 0;
      psVar2[0xc] = 0;
      psVar2[0xd] = 0;
      psVar2[0xe] = 0;
      psVar2[0xf] = 0;
      psVar2[0x10] = 0;
      psVar2[0x11] = 0;
      psVar2[0x12] = 0;
      psVar2[0x13] = 0;
      psVar2[0x14] = 0;
      psVar2[0x15] = 0;
      psVar2[0x16] = 0;
      psVar2[0x17] = 0;
    }
  }
  else if ((*(char *)((longlong)puVar1 + 1) == '\x13') &&
          ((*(int *)(puVar1 + 1) == 0 || (*(int *)(puVar1 + 1) == 1)))) {
    HandleQueryId(param_1,param_2);
    return;
  }
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  return;
}



===== HidUmdfUnload @ 1c00072c0 =====

void HidUmdfUnload(void)

{
  return;
}



===== IoctlWorkItemEx @ 1c00072d0 =====

void IoctlWorkItemEx(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    HidUmdfInternalIoctlWorker(param_1,param_2);
  }
  IoFreeWorkItem(param_3);
  return;
}



===== entry @ 1c0008010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0008044 =====

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



===== DriverEntry @ 1c0008078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DriverEntry(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_1c;
  undefined2 local_1b;
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  puVar2 = (undefined8 *)(param_1 + 0x70);
  for (lVar1 = 0x1c; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = HidUmdfPassThrough;
    puVar2 = puVar2 + 1;
  }
  *(code **)(param_1 + 0x80) = HidUmdfCreateCleanupClose;
  *(code **)(param_1 + 0x100) = HidUmdfCreateCleanupClose;
  *(code **)(param_1 + 0x70) = HidUmdfCreateCleanupClose;
  *(code **)(param_1 + 0xa0) = HidUmdfQuerySetFlush;
  *(code **)(param_1 + 0x98) = HidUmdfQuerySetFlush;
  *(code **)(param_1 + 0xb8) = HidUmdfQuerySetFlush;
  *(code **)(param_1 + 0xe8) = HidUmdfInternalIoctl;
  *(code **)(param_1 + 0x148) = HidUmdfPnp;
  *(code **)(param_1 + 0x120) = HidUmdfPowerPassThrough;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = HidUmdfAddDevice;
  local_38 = 1;
  *(code **)(param_1 + 0x68) = HidUmdfUnload;
  local_1b = 0;
  local_19 = 0;
  local_20 = 0x48;
  local_1c = 0;
  local_30 = param_1;
  local_28 = param_2;
  HidRegisterMinidriver(&local_38);
  return;
}


