
===== NpCancelWaiter @ 1c0001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NpCancelWaiter(longlong *param_1,ushort *param_2,undefined4 param_3,longlong param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *_Buf1;
  longlong *plVar9;
  ushort uVar10;
  undefined8 *puVar11;
  undefined1 auStack_178 [32];
  undefined1 local_158;
  ushort local_150;
  ushort local_14e;
  undefined4 local_14c;
  undefined8 *local_148;
  undefined4 local_140;
  longlong local_138;
  longlong *local_130;
  longlong *local_128;
  undefined8 local_118 [26];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  local_14c = 0;
  puVar11 = (undefined8 *)0x0;
  local_140 = param_3;
  local_138 = param_4;
  local_130 = param_1;
  if (*param_2 < 0xc9) {
    local_148 = local_118;
  }
  else {
    local_148 = (undefined8 *)ExAllocatePool2(0x40,*param_2,0x7446704e);
    if (local_148 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
  }
  local_14e = *param_2;
  local_150 = 0;
  RtlUpcaseUnicodeString(&local_150,param_2,0);
  local_128 = param_1 + 2;
  local_158 = KeAcquireSpinLockRaiseToDpc(local_128);
  plVar9 = (longlong *)*param_1;
  if (plVar9 != param_1) {
    uVar10 = local_150;
    do {
      plVar3 = plVar9 + -5;
      puVar8 = (undefined8 *)*plVar3;
      if (*(ushort *)(puVar8 + 0x13) == 0) {
        if (*(uint *)(plVar9[-0x12] + 8) == (uint)uVar10) {
          _Buf1 = (undefined8 *)(plVar9[-0x12] + 0xe);
          goto LAB_1c0001187;
        }
      }
      else if (uVar10 == *(ushort *)(puVar8 + 0x13)) {
        _Buf1 = puVar8 + 0x14;
LAB_1c0001187:
        iVar6 = memcmp(_Buf1,local_148,(ulonglong)uVar10);
        if (iVar6 == 0) {
          lVar1 = *plVar9;
          plVar2 = (longlong *)plVar9[1];
          if ((*(longlong **)(lVar1 + 8) != plVar9) || ((longlong *)*plVar2 != plVar9)) {
LAB_1c0001282:
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            pcVar4 = (code *)swi(3);
            uVar7 = (*pcVar4)();
            return uVar7;
          }
          *plVar2 = lVar1;
          *(longlong **)(lVar1 + 8) = plVar2;
          cVar5 = KeCancelTimer();
          if (cVar5 == '\0') {
            *puVar8 = 0;
            *plVar3 = 0;
          }
          else {
            puVar8[0x11] = puVar11;
            puVar11 = puVar8;
          }
          LOCK();
          lVar1 = plVar9[-8];
          plVar9[-8] = 0;
          UNLOCK();
          if (lVar1 == 0) {
            *plVar3 = 0;
          }
          else {
            plVar9[-0xe] = 0;
            *(undefined4 *)(plVar9 + -0xf) = local_140;
            plVar3 = *(longlong **)(local_138 + 8);
            if (*plVar3 != local_138) goto LAB_1c0001282;
            *plVar9 = local_138;
            plVar9[1] = (longlong)plVar3;
            *plVar3 = (longlong)plVar9;
            *(longlong **)(local_138 + 8) = plVar9;
          }
          plVar9 = plVar2;
          uVar10 = local_150;
        }
      }
      plVar9 = (longlong *)*plVar9;
    } while (plVar9 != local_130);
  }
  KeReleaseSpinLock(local_128,local_158);
  puVar8 = local_148;
  if (local_148 == local_118) goto LAB_1c00010ea;
  while( true ) {
    ExFreePoolWithTag(puVar8,0);
LAB_1c00010ea:
    puVar8 = puVar11;
    if (puVar8 == (undefined8 *)0x0) break;
    puVar11 = (undefined8 *)puVar8[0x11];
    ObfDereferenceObject(puVar8[0x12]);
  }
  return 0;
}



===== NpAddWaiter @ 1c0001290 =====

undefined8 NpAddWaiter(longlong param_1,undefined8 param_2,longlong param_3,ushort *param_4)

{
  byte *pbVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  void *_Src;
  code *pcVar5;
  undefined1 uVar6;
  ushort uVar7;
  undefined2 uVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined1 *puVar12;
  uint uVar13;
  ulonglong uVar14;
  longlong local_res18;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  
  if (param_4 == (ushort *)0x0) {
    lVar10 = 0xa0;
  }
  else {
    lVar10 = (ulonglong)*param_4 + 0xa0;
  }
  plVar9 = (longlong *)ExAllocatePool2(0x41,lVar10,0x7746704e);
  if (plVar9 == (longlong *)0x0) {
    uVar11 = 0xc000009a;
  }
  else {
    KeInitializeDpc(plVar9 + 1,NpTimerDispatch,plVar9);
    KeInitializeTimer(plVar9 + 9);
    puVar12 = auStack_48;
    plVar9[0x11] = param_1;
    *plVar9 = param_3;
    if (param_4 != (ushort *)0x0) goto LAB_1c0001470;
    uVar7 = 0;
    puVar12 = auStack_48;
    while( true ) {
      *(ushort *)(plVar9 + 0x13) = uVar7;
      puVar3 = *(undefined8 **)(param_3 + 0x18);
      if (*(char *)((longlong)puVar3 + 0xc) != '\0') {
        param_2 = *puVar3;
      }
      uVar14 = 0;
      if ((*(uint *)(puVar3 + 1) & 0xfffffffe) != 0) {
        do {
          uVar8 = *(undefined2 *)((longlong)puVar3 + uVar14 * 2 + 0xe);
          *(undefined8 *)(puVar12 + -8) = 0x1c0001363;
          uVar8 = RtlUpcaseUnicodeChar(uVar8);
          *(undefined2 *)((longlong)puVar3 + uVar14 * 2 + 0xe) = uVar8;
          uVar13 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar13;
        } while (uVar13 < *(uint *)(puVar3 + 1) >> 1);
      }
      *(longlong *)(param_3 + 0x78) = param_1;
      *(longlong **)(param_3 + 0x80) = plVar9;
      *(undefined8 *)(puVar12 + -8) = 0x1c0001392;
      uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
      LOCK();
      *(code **)(param_3 + 0x68) = NpCancelWaitQueueIrp;
      UNLOCK();
      if (*(char *)(param_3 + 0x44) != '\0') {
        LOCK();
        lVar10 = *(longlong *)(param_3 + 0x68);
        *(longlong *)(param_3 + 0x68) = 0;
        UNLOCK();
        if (lVar10 != 0) {
          uVar11 = 0xc0000120;
          goto LAB_1c000141a;
        }
      }
      plVar4 = *(longlong **)(param_1 + 8);
      plVar2 = (longlong *)(param_3 + 0xa8);
      if (*plVar4 == param_1) break;
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar12 = puVar12 + 8;
LAB_1c0001470:
      uVar7 = *param_4;
      _Src = *(void **)(param_4 + 4);
      *(undefined8 *)(puVar12 + -8) = 0x1c0001484;
      memcpy(plVar9 + 0x14,_Src,(ulonglong)uVar7);
      uVar7 = *param_4;
    }
    *plVar2 = param_1;
    *(longlong **)(param_3 + 0xb0) = plVar4;
    *plVar4 = (longlong)plVar2;
    *(longlong **)(param_1 + 8) = plVar2;
    lVar10 = *(longlong *)(puVar12 + 0x60);
    pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    plVar9[0x12] = *(longlong *)(lVar10 + 0x30);
    uVar11 = *(undefined8 *)(lVar10 + 0x30);
    *(undefined8 *)(puVar12 + -8) = 0x1c00013f7;
    ObfReferenceObject(uVar11);
    *(undefined8 *)(puVar12 + -8) = 0x1c000140e;
    KeSetTimer(plVar9 + 9,param_2,plVar9 + 1);
    plVar9 = (longlong *)0x0;
    uVar11 = 0x103;
LAB_1c000141a:
    *(undefined8 *)(puVar12 + -8) = 0x1c0001428;
    KeReleaseSpinLock(param_1 + 0x10,uVar6);
    if (plVar9 != (longlong *)0x0) {
      *(undefined8 *)(puVar12 + -8) = 0x1c00014b1;
      ExFreePoolWithTag(plVar9,0);
    }
  }
  return uVar11;
}



===== NpCancelDataQueueIrp @ 1c00014d0 =====

void NpCancelDataQueueIrp(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  longlong lVar12;
  ulonglong uVar13;
  char cVar14;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 *******local_38;
  undefined8 *******local_30;
  
  if (param_1 != 0) {
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  }
  plVar8 = *(longlong **)(param_2 + 0x88);
  local_30 = &local_38;
  lVar12 = 0;
  local_38 = &local_38;
  uVar13 = *(ulonglong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20) &
           0xfffffffffffffffc;
  if (param_1 != 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(uVar13 + 0x40);
  }
  puVar10 = auStack_58;
  puVar11 = auStack_58;
  plVar2 = *(longlong **)(param_2 + 0x90);
  if (plVar2 == (longlong *)0x0) goto LAB_1c00015cc;
  cVar14 = (longlong *)plVar2[1] == plVar8;
  if ((bool)cVar14) {
    *(undefined4 *)((longlong)plVar8 + 0x24) = 0;
  }
  lVar3 = *plVar2;
  if ((*(longlong **)(lVar3 + 8) == plVar2) &&
     (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 == plVar2)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    iVar7 = (int)plVar2[5];
    lVar12 = plVar2[3];
    puVar10 = auStack_58;
    if ((int)plVar8[2] == 1) goto LAB_1c00016ba;
LAB_1c00015ad:
    bVar6 = false;
  }
  else {
    iVar7 = 3;
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)();
    puVar11 = auStack_50;
LAB_1c00016ba:
    puVar10 = puVar11;
    if ((*(uint *)(plVar8 + 4) < *(uint *)((longlong)plVar8 + 0x1c)) ||
       (*(int *)((longlong)plVar2 + 0x24) == 0)) goto LAB_1c00015ad;
    bVar6 = true;
  }
  *(int *)(plVar8 + 4) = (int)plVar8[4] - *(int *)((longlong)plVar2 + 0x24);
  *(int *)((longlong)plVar8 + 0x14) = *(int *)((longlong)plVar8 + 0x14) - iVar7;
  *(int *)(plVar8 + 3) = (int)plVar8[3] + -1;
  if ((longlong *)*plVar8 == plVar8) {
    *(undefined4 *)(plVar8 + 2) = 2;
  }
  else {
    if (cVar14 != '\0') {
      *(undefined8 *)(puVar10 + -8) = 0x1c00016e5;
      NpGetNextRealDataQueueEntry(plVar8,(longlong)(puVar10 + 0x20));
    }
    if (bVar6) {
      *(undefined8 *)(puVar10 + -8) = 0x1c00016a0;
      NpCompleteStalledWrites(plVar8,(longlong)(puVar10 + 0x20));
    }
  }
LAB_1c00015cc:
  plVar4 = (longlong *)plVar8[5];
  if (plVar4 == plVar2) {
    LOCK();
    *(uint *)(plVar8 + 5) = *(uint *)(plVar8 + 5) | 1;
    UNLOCK();
  }
  plVar8 = (longlong *)0x0;
  if (plVar4 != plVar2) {
    plVar8 = plVar2;
  }
  if (param_1 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x1c00015f6;
    ExReleasePushLockExclusiveEx(uVar13 + 0x40,0);
    *(undefined8 *)(puVar10 + -8) = 0x1c0001602;
    KeLeaveCriticalRegion();
  }
  if (plVar8 != (longlong *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x1c000167f;
    ExFreePoolWithTag(plVar8,0);
  }
  *(undefined8 *)(puVar10 + -8) = 0x1c0001614;
  NpFreeClientSecurityContext(lVar12);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  *(undefined8 *)(puVar10 + -8) = 0x1c0001627;
  IofCompleteRequest(param_2,2);
  puVar9 = *(undefined8 **)(puVar10 + 0x20);
  while (puVar9 != (undefined8 *)(puVar10 + 0x20)) {
    puVar1 = puVar9 + -0x15;
    puVar9 = (undefined8 *)*puVar9;
    *(undefined8 *)(puVar10 + -8) = 0x1c0001646;
    IofCompleteRequest(puVar1,2);
  }
  return;
}



===== NpClearSecurity @ 1c00016f0 =====

void NpClearSecurity(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x108) != -1) {
    *(undefined8 *)(param_1 + 0x108) = 0;
  }
  return;
}



===== NpCancelListeningQueueIrp @ 1c0001710 =====

void NpCancelListeningQueueIrp(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar5 = *(ulonglong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20) &
          0xfffffffffffffffc;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(uVar5 + 0x40,0);
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExReleasePushLockExclusiveEx(uVar5 + 0x40,0);
    KeLeaveCriticalRegion();
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,2);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== NpTimerDispatch @ 1c00017d0 =====

void NpTimerDispatch(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar2 = param_2[0x11];
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x10);
  puVar9 = auStack_28;
  lVar7 = *param_2;
  puVar8 = auStack_28;
  if (lVar7 != 0) {
    plVar1 = (longlong *)(lVar7 + 0xa8);
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) == plVar1) &&
       (plVar4 = *(longlong **)(lVar7 + 0xb0), (longlong *)*plVar4 == plVar1)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      LOCK();
      lVar3 = *(longlong *)(lVar7 + 0x68);
      *(longlong *)(lVar7 + 0x68) = 0;
      UNLOCK();
      puVar8 = auStack_28;
      if (lVar3 != 0) goto LAB_1c0001833;
    }
    else {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar9 = auStack_20;
    }
    *(undefined8 *)(lVar7 + 0x80) = 0;
    lVar7 = 0;
    puVar8 = puVar9;
  }
LAB_1c0001833:
  *(undefined8 *)(puVar8 + -8) = 0x1c0001841;
  KeReleaseSpinLock(lVar2 + 0x10,uVar6);
  if (lVar7 != 0) {
    *(undefined4 *)(lVar7 + 0x30) = 0xc00000b5;
    *(undefined8 *)(puVar8 + -8) = 0x1c000185e;
    IofCompleteRequest(lVar7,2);
  }
  lVar2 = param_2[0x12];
  *(undefined8 *)(puVar8 + -8) = 0x1c0001871;
  ObfDereferenceObject(lVar2);
  *(undefined8 *)(puVar8 + -8) = 0x1c0001882;
  ExFreePoolWithTag(param_2,0);
  return;
}



===== RtlUnicodeStringPrintf @ 1c00018b4 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== NpCancelWaitQueueIrp @ 1c0001960 =====

void NpCancelWaitQueueIrp(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  char cVar7;
  undefined8 *puVar8;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  lVar2 = *(longlong *)(param_2 + 0x78);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x10);
  puVar8 = *(undefined8 **)(param_2 + 0x80);
  if (puVar8 != (undefined8 *)0x0) {
    plVar1 = (longlong *)(param_2 + 0xa8);
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    cVar7 = KeCancelTimer(puVar8 + 9);
    if (cVar7 == '\0') {
      *puVar8 = 0;
      puVar8 = (undefined8 *)0x0;
    }
  }
  KeReleaseSpinLock(lVar2 + 0x10,uVar6);
  if (puVar8 != (undefined8 *)0x0) {
    ObfDereferenceObject(puVar8[0x12]);
    ExFreePoolWithTag(puVar8,0);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,2);
  return;
}



===== __report_gsfailure @ 1c0001a80 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c0001a8d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001a8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== NpCancelChangeNotifyIrp @ 1c0001aa0 =====

void NpCancelChangeNotifyIrp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  lVar2 = *(longlong *)(param_1 + 0x40);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar2 + 0xa8,0);
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    ExReleasePushLockExclusiveEx(lVar2 + 0xa8,0);
    KeLeaveCriticalRegion();
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,2);
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== __GSHandlerCheck @ 1c0001b58 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0001b7c =====

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



===== __cpu_features_init @ 1c0001bf0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0001c5a) */
/* WARNING: Removing unreachable block (ram,0x0001c0001c09) */
/* WARNING: Removing unreachable block (ram,0x0001c0001bfa) */

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



===== _guard_check_icall @ 1c0001cc0 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c0001ce0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001d20 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001d20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001d50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c0001da0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c0001de3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0001e54;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0001e50:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0001e54;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c0001e4c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0001e50;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0001e4c;
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
LAB_1c0001e54:
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
LAB_1c0001de3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0001ec0 =====

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



===== memset @ 1c00021c0 =====

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



===== __memset_repmovs @ 1c0002300 =====

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



===== __memset_query @ 1c0002380 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002400 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0002540 =====

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



===== __memset_spec_plain @ 1c00025c0 =====

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



===== NpUninitializeAliases @ 1c000b008 =====

void NpUninitializeAliases(void)

{
  ExFreePoolWithTag(NpAliases,0);
  return;
}



===== NpDeleteCcb @ 1c000b030 =====

void NpDeleteCcb(longlong param_1,longlong param_2,longlong param_3)

{
  NpUnlinkCcb(param_1,param_2,param_3);
  NpFreeCcb(param_2);
  return;
}



===== NpCreateSymlinkFsCtl @ 1c000b054 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NpCreateSymlinkFsCtl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined1 auStackY_208 [32];
  ushort local_1d8;
  ushort local_1d6;
  undefined4 local_1d4;
  longlong local_1d0;
  ushort local_1c8;
  ushort local_1c6;
  undefined4 local_1c4;
  longlong local_1c0;
  undefined8 local_1b8 [2];
  undefined1 local_1a8 [160];
  undefined1 local_108 [224];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_208;
  memset(local_1a8,0,0xa0);
  memset(local_108,0,0xe0);
  local_1d4 = 0;
  local_1c4 = 0;
  local_1b8[0] = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((**(short **)(lVar1 + 0x18) == 0x201) && ((*(byte *)(lVar1 + 0x20) & 1) != 0)) {
    uVar4 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    if (0xb < uVar4) {
      puVar2 = *(ushort **)(param_2 + 0x18);
      uVar3 = (uint)puVar2[1] + (uint)*puVar2;
      if ((uint)puVar2[1] + (uint)*puVar2 <= (uint)puVar2[3] + (uint)puVar2[2]) {
        uVar3 = (uint)puVar2[3] + (uint)puVar2[2];
      }
      if (uVar3 <= uVar4) {
        uVar5 = IoGetFileObjectGenericMapping();
        uVar6 = SeCreateAccessState(local_1a8,local_108,2,uVar5);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        local_1d0 = (ulonglong)*puVar2 + (longlong)puVar2;
        local_1d8 = puVar2[1];
        local_1d6 = local_1d8;
        uVar5 = PsGetCurrentSilo();
        uVar4 = NpCreateSymlinkAccessCheck
                          ((undefined8 *)&local_1d8,(ulonglong)*(uint *)(puVar2 + 4),uVar5,
                           *(longlong *)(param_1 + 0x40),*(char *)(param_2 + 0x40),
                           (longlong)local_1a8);
        if (-1 < (int)uVar4) {
          local_1c0 = (ulonglong)puVar2[2] + (longlong)puVar2;
          local_1c8 = puVar2[3];
          local_1c6 = local_1c8;
          uVar4 = NpCreateSymlink(&local_1d8,&local_1c8,*(uint *)(puVar2 + 4),
                                  *(longlong *)(param_1 + 0x40),(longlong)local_1a8,local_1b8);
          if (-1 < (int)uVar4) {
            *(undefined8 *)(param_2 + 0x38) = 0;
          }
        }
        SeDeleteAccessState(local_1a8);
        return (ulonglong)uVar4;
      }
    }
    uVar6 = 0xc000000d;
  }
  else {
    uVar6 = 0xc00000af;
  }
  return uVar6;
}



===== NpDeleteSymlinkFsCtl @ 1c000b23c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NpDeleteSymlinkFsCtl(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ushort *puVar4;
  int iVar5;
  undefined8 uVar6;
  short *psVar7;
  undefined1 auStack_1f8 [32];
  ushort local_1d8;
  ushort local_1d6;
  undefined4 local_1d4;
  longlong local_1d0;
  short local_1c8 [8];
  undefined1 local_1b8 [160];
  undefined1 local_118 [224];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1f8;
  lVar2 = *(longlong *)(param_1 + 0x40);
  memset(local_1b8,0,0xa0);
  memset(local_118,0,0xe0);
  local_1d4 = 0;
  local_1c8[0] = 0;
  local_1c8[1] = 0;
  local_1c8[2] = 0;
  local_1c8[3] = 0;
  local_1c8[4] = 0;
  local_1c8[5] = 0;
  local_1c8[6] = 0;
  local_1c8[7] = 0;
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((**(short **)(lVar3 + 0x18) == 0x201) && ((*(byte *)(lVar3 + 0x20) & 1) != 0)) {
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    if ((3 < uVar1) &&
       (puVar4 = *(ushort **)(param_2 + 0x18), (uint)puVar4[1] + (uint)*puVar4 <= uVar1)) {
      uVar6 = IoGetFileObjectGenericMapping();
      iVar5 = SeCreateAccessState(local_1b8,local_118,0x10000,uVar6);
      if (iVar5 < 0) {
        return iVar5;
      }
      local_1d0 = (ulonglong)*puVar4 + (longlong)puVar4;
      local_1d8 = puVar4[1];
      local_1d6 = local_1d8;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(lVar2 + 0xc0,0);
      psVar7 = (short *)NpFindPrefix(lVar2,(undefined8 *)&local_1d8,'\x01',local_1c8);
      if ((psVar7 == (short *)0x0) || (local_1c8[0] != 0)) {
        iVar5 = -0x3fffffcc;
      }
      else if (*psVar7 == 0x207) {
        iVar5 = NpDeleteSymlinkAccessCheck
                          ((longlong)psVar7,*(undefined1 *)(param_2 + 0x40),(longlong)local_1b8);
        if (-1 < iVar5) {
          NpDeleteSymlink((longlong)psVar7,lVar2);
          *(undefined8 *)(param_2 + 0x38) = 0;
          iVar5 = 0;
        }
      }
      else {
        iVar5 = -0x3fffffcd;
      }
      ExReleasePushLockExclusiveEx(lVar2 + 0xc0,0);
      KeLeaveCriticalRegion();
      SeDeleteAccessState(local_1b8);
      return iVar5;
    }
    iVar5 = -0x3ffffff3;
  }
  else {
    iVar5 = -0x3fffff51;
  }
  return iVar5;
}



===== NpInternalWrite @ 1c000b438 =====

int NpInternalWrite(ulonglong param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  ulonglong local_res8;
  undefined8 local_res10;
  
  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffffbf;
  local_res8 = param_1 & 0xffffffff00000000;
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((*(byte *)(lVar3 + 0x20) & 1) == 0) || (**(short **)(lVar3 + 0x18) != 0x202)) {
    return -0x3fffff50;
  }
  lVar4 = *(longlong *)(param_2 + 0x18);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uVar8 = *(ulonglong *)(lVar3 + 0x20) & 0xfffffffffffffffc;
  local_res10 = *(undefined8 *)(param_2 + 0x98);
  uVar10 = *(ulonglong *)(lVar3 + 0x20) >> 1;
  uVar9 = (uint)uVar10 & 1;
  ExAcquirePushLockExclusiveEx(uVar8 + 0x40,0);
  if ((*(byte *)(lVar3 + 0x20) & 1) != 0) {
    uVar6 = *(uint *)(*(longlong *)(uVar8 + 0x28) + 0x100) & 0xffff;
    if ((uVar10 & 1) == 0) {
      uVar6 = uVar6 - 1;
    }
    if (uVar6 != 0) {
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar2;
      if ((uVar10 & 1) == 0) {
        bVar5 = *(byte *)(uVar8 + 10);
      }
      else {
        bVar5 = *(byte *)(uVar8 + 9);
      }
      cVar1 = *(char *)(uVar8 + 8);
      plVar11 = (longlong *)(uVar8 + 0x48 + (ulonglong)(-(uint)((uVar10 & 1) != 0) & 0x60));
      if (cVar1 == '\x03') {
        iVar7 = *(int *)(*(longlong *)(uVar8 + 0x28) + 0x104);
        if (((iVar7 == 0) && ((*(byte *)((ulonglong)uVar9 + 9 + uVar8) & 2) != 0)) &&
           (((int)plVar11[2] != 0 || (*(uint *)((longlong)plVar11 + 0x14) < uVar2)))) {
          *(undefined8 *)(param_2 + 0x38) = 0;
        }
        else {
          iVar7 = NpWriteDataQueue(plVar11,(ulonglong)(bVar5 & 1),lVar4,uVar2,iVar7,
                                   (uint *)&local_res8);
          if (iVar7 != -0x3fffffea) goto LAB_1c000b605;
          if ((*(byte *)((ulonglong)uVar9 + 9 + uVar8) & 2) == 0) {
            iVar7 = NpAddDataQueueEntry(uVar9,uVar8,(longlong)plVar11,1,1,uVar2,param_2,(void *)0x0,
                                        uVar2 - (int)local_res8);
            goto LAB_1c000b605;
          }
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)(uVar2 - (int)local_res8);
        }
        iVar7 = 0;
        goto LAB_1c000b605;
      }
      if (cVar1 != '\x01') {
        iVar7 = -0x3fffff4f;
        if (cVar1 == '\x02') {
          iVar7 = -0x3fffff4d;
        }
        goto LAB_1c000b605;
      }
    }
  }
  iVar7 = -0x3fffff50;
LAB_1c000b605:
  ExReleasePushLockExclusiveEx(uVar8 + 0x40,0);
  return iVar7;
}



===== NpRemoveAttributeFromList @ 1c000b640 =====

undefined8 NpRemoveAttributeFromList(undefined8 *param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong *plVar6;
  int iVar7;
  char *pcVar8;
  longlong lVar9;
  
  plVar6 = (longlong *)*param_1;
  do {
    if (plVar6 == param_1) {
      return 0xc0000225;
    }
    pcVar8 = (char *)plVar6[2];
    iVar7 = (int)pcVar8;
    if (iVar7 == 1) {
      pcVar8 = "ServerProcessId";
    }
    else if (iVar7 == 2) {
      pcVar8 = "ServerSessionId";
    }
    else if (iVar7 == 3) {
      pcVar8 = "ClientProcessId";
    }
    else if (iVar7 == 4) {
      pcVar8 = "ClientSessionId";
    }
    else if (iVar7 == 6) {
      pcVar8 = "ClientComputerName";
    }
    plVar3 = (longlong *)*plVar6;
    lVar9 = param_2 - (longlong)pcVar8;
    do {
      cVar1 = *pcVar8;
      cVar2 = pcVar8[lVar9];
      if (cVar1 != cVar2) break;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) {
      if (((longlong *)plVar3[1] == plVar6) &&
         (plVar4 = (longlong *)plVar6[1], (longlong *)*plVar4 == plVar6)) {
        *plVar4 = (longlong)plVar3;
        plVar3[1] = (longlong)plVar4;
        ExFreePoolWithTag(plVar6,0);
        return 0;
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      return 0xc0000225;
    }
    plVar6 = plVar3;
  } while( true );
}



===== NpSetAttribute @ 1c000b714 =====

ulonglong NpSetAttribute(longlong param_1,int param_2)

{
  uint uVar1;
  char *_Str1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  char *pcVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong local_res18;
  
  _Str1 = *(char **)(param_1 + 0x18);
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
  if ((uVar1 == 0) || (uVar3 = 0, uVar1 == 0)) {
    return 0xc000000d;
  }
  pcVar6 = _Str1;
  do {
    if (*pcVar6 == '\0') break;
    uVar3 = uVar3 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar3 < uVar1);
  if (uVar3 == 0) {
    return 0xc000000d;
  }
  if (uVar3 == uVar1) {
    return 0xc000000d;
  }
  uVar3 = uVar3 + 1;
  if (uVar3 < uVar1) {
    pcVar6 = _Str1 + uVar3;
    local_res18 = (ulonglong)(uVar1 - uVar3);
  }
  else {
    pcVar6 = (char *)0x0;
    local_res18 = 0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  if (**(short **)(lVar2 + 0x18) != 0x202) {
    return 0xc000000d;
  }
  uVar7 = *(ulonglong *)(lVar2 + 0x20) & 0xfffffffffffffffc;
  uVar10 = *(ulonglong *)(lVar2 + 0x20) >> 1;
  lVar5 = *(longlong *)(uVar7 + 0x28);
  if (param_2 == 0) {
    if ((((uVar10 & 1) == 0) || (iVar4 = _stricmp(_Str1,"ServerProcessId"), iVar4 == 0)) ||
       (iVar4 = _stricmp(_Str1,"ServerSessionId"), iVar4 == 0)) {
      return 0xc0000022;
    }
    plVar8 = (longlong *)(lVar5 + 0x128);
    ExAcquirePushLockExclusiveEx(lVar5 + 0x80);
LAB_1c000b8a9:
    if (pcVar6 == (char *)0x0) {
      NpRemoveAttributeFromList(plVar8,(longlong)_Str1);
      uVar9 = 0;
LAB_1c000b948:
      *(undefined8 *)(param_1 + 0x38) = 0;
    }
    else {
      uVar10 = NpSetAttributeInList(plVar8,(longlong *)0x0,_Str1,pcVar6,local_res18);
      uVar9 = uVar10 & 0xffffffff;
      if (-1 < (int)uVar10) goto LAB_1c000b948;
    }
    if (param_2 == 0) {
      lVar5 = lVar5 + 0x80;
      goto LAB_1c000b968;
    }
    if ((param_2 != 1) && (param_2 != 2)) {
      return uVar9;
    }
  }
  else {
    if (param_2 == 1) {
      if ((uVar10 & 1) == 0) {
        return 0xc0000022;
      }
      iVar4 = _stricmp(_Str1,"ClientComputerName");
      if (iVar4 == 0) {
        return 0xc0000022;
      }
      iVar4 = _stricmp(_Str1,"ClientProcessId");
      if (iVar4 == 0) {
        return 0xc0000022;
      }
      iVar4 = _stricmp(_Str1,"ClientSessionId");
      if (iVar4 == 0) {
        return 0xc0000022;
      }
      plVar8 = (longlong *)(uVar7 + 0x130);
      ExAcquirePushLockExclusiveEx(uVar7 + 0x40);
      goto LAB_1c000b8a9;
    }
    if (param_2 != 2) {
      return 0xc000000d;
    }
    plVar8 = (longlong *)(((ulonglong)((uint)uVar10 & 1) + 0x14) * 0x10 + uVar7);
    ExAcquirePushLockExclusiveEx(uVar7 + 0x40);
    if (((uVar10 & 1) != 0) || ((*(byte *)(lVar2 + 0x20) & 1) != 0)) goto LAB_1c000b8a9;
    uVar9 = 0xc00000b0;
  }
  lVar5 = uVar7 + 0x40;
LAB_1c000b968:
  ExReleasePushLockExclusiveEx(lVar5,0);
  return uVar9;
}



===== NpSiloArrivalFsCtl @ 1c000b9a4 =====

ulonglong NpSiloArrivalFsCtl(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res8;
  longlong local_res10;
  
  local_res10 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  if ((**(short **)(lVar1 + 0x18) == 0x201) && ((*(byte *)(lVar1 + 0x20) & 1) != 0)) {
    if ((*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 8) ||
       (**(longlong **)(param_1 + 0x18) == 0)) {
      uVar3 = 0xc000000d;
    }
    else {
      local_res8 = 0;
      uVar3 = ObReferenceObjectByHandleWithTag
                        (**(longlong **)(param_1 + 0x18),2,*(undefined8 *)PsJobType_exref,
                         *(undefined1 *)(param_1 + 0x40),0x4f66704e,&local_res8,0);
      if (-1 < (int)uVar3) {
        uVar2 = PsGetJobSilo(local_res8,&local_res10);
        uVar3 = (ulonglong)uVar2;
        if ((-1 < (int)uVar2) && (local_res8 == local_res10)) {
          uVar4 = NpSiloArrival(local_res10);
          uVar3 = uVar4 & 0xffffffff;
          if (-1 < (int)uVar4) {
            *(undefined8 *)(param_1 + 0x38) = 0;
          }
        }
        if (local_res8 != 0) {
          ObfDereferenceObjectWithTag(local_res8,0x4f66704e);
        }
      }
    }
  }
  else {
    uVar3 = 0xc00000af;
  }
  return uVar3;
}



===== NpDeleteDevice @ 1c000bab4 =====

void NpDeleteDevice(longlong param_1)

{
  undefined8 ****ppppuVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 ****ppppuVar4;
  undefined8 ****local_18;
  undefined8 ****local_10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_10 = &local_18;
  local_18 = &local_18;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar2 + 0xc0,0);
  while (plVar3 = *(longlong **)(lVar2 + 200), plVar3 != (longlong *)(lVar2 + 200)) {
    NpUnlinkNode((short *)(plVar3 + -0x11),lVar2,(longlong)&local_18);
  }
  ExReleasePushLockExclusiveEx(lVar2 + 0xc0,0);
  KeLeaveCriticalRegion();
  ppppuVar4 = local_18;
  while ((undefined8 *****)ppppuVar4 != &local_18) {
    ppppuVar1 = ppppuVar4 + -0x15;
    ppppuVar4 = (undefined8 ****)*ppppuVar4;
    IofCompleteRequest(ppppuVar1,2);
  }
  IoDeleteDevice(param_1);
  return;
}



===== NpSiloArrival @ 1c000bb9c =====

ulonglong NpSiloArrival(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong *local_res10;
  longlong local_res18 [2];
  
  local_res10 = (longlong *)0x0;
  uVar2 = PsAttachSiloToCurrentThread();
  local_res18[0] = 0;
  uVar3 = NpCreateDevice(local_res18);
  lVar4 = local_res18[0];
  uVar5 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
    uVar1 = PsCreateSiloContext(param_1,8,1,NpSiloContextCleanup,&local_res10);
    uVar5 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      *local_res10 = lVar4;
      uVar1 = PsInsertPermanentSiloContext(param_1,NpSiloSlot,local_res10);
      uVar5 = (ulonglong)uVar1;
      PsDereferenceSiloContext(local_res10);
      lVar4 = 0;
    }
  }
  if (lVar4 != 0) {
    NpDeleteDevice(lVar4);
  }
  PsDetachSiloFromCurrentThread(uVar2);
  return uVar5;
}



===== NpSiloContextCleanup @ 1c000bc80 =====

void NpSiloContextCleanup(longlong *param_1)

{
  NpDeleteDevice(*param_1);
  return;
}



===== NpInitializeVcb @ 1c000bc98 =====

void NpInitializeVcb(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  memset(param_1,0,0x1d8);
  puVar2 = param_1 + 0x3c;
  *puVar2 = 1;
  *(undefined8 *)(param_1 + 0x3e) = 0;
  param_1[0x40] = 0;
  KeInitializeEvent(param_1 + 0x42,1,0);
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 0x40;
  *(byte *)((longlong)param_1 + 6) = *(byte *)((longlong)param_1 + 6) | 2;
  *(byte *)((longlong)param_1 + 7) = *(byte *)((longlong)param_1 + 7) & 0xf | 0x50;
  puVar1 = param_1 + 0xe;
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 **)(param_1 + 0xc) = puVar2;
  }
  *(undefined8 *)(param_1 + 0x12) = 0;
  puVar1 = param_1 + 0x68;
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined8 *)(param_1 + 0x16) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  param_1[0x1a] = 0;
  *(undefined8 *)(param_1 + 0x1c) = 0;
  *param_1 = 0x1d80201;
  *puVar1 = 1;
  *(undefined8 *)(param_1 + 0x6a) = 0;
  param_1[0x6c] = 0;
  KeInitializeEvent(param_1 + 0x6e,1);
  *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) | 0x40;
  *(byte *)((longlong)param_1 + 0x12e) = *(byte *)((longlong)param_1 + 0x12e) | 2;
  *(byte *)((longlong)param_1 + 0x12f) = *(byte *)((longlong)param_1 + 0x12f) & 0xf | 0x50;
  puVar2 = param_1 + 0x58;
  *(undefined4 **)(param_1 + 0x5a) = puVar2;
  *(undefined4 **)puVar2 = puVar2;
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined4 **)(param_1 + 0x56) = puVar1;
  }
  *(undefined8 *)(param_1 + 0x5c) = 0;
  *(undefined8 *)(param_1 + 0x5e) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x62) = 0;
  param_1[100] = 0;
  *(undefined8 *)(param_1 + 0x66) = 0;
  param_1[0x4a] = 0xb00206;
  RtlInitializeUnicodePrefix(param_1 + 0x36);
  puVar1 = param_1 + 0x24;
  *(undefined8 *)(param_1 + 0x2a) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined4 **)(param_1 + 0x26) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  KeInitializeSpinLock(param_1 + 0x28);
  puVar1 = param_1 + 0x2c;
  *(undefined4 **)(param_1 + 0x2e) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  puVar1 = param_1 + 0x32;
  *(undefined4 **)(param_1 + 0x34) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  return;
}



===== NpCreateSymlink @ 1c000be3c =====

int NpCreateSymlink(ushort *param_1,ushort *param_2,uint param_3,longlong param_4,longlong param_5,
                   undefined8 *param_6)

{
  longlong *plVar1;
  longlong *plVar2;
  ushort *puVar3;
  ushort uVar4;
  short sVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  code *pcVar8;
  int iVar9;
  undefined4 *_Dst;
  undefined4 *puVar10;
  undefined8 uVar11;
  void *pvVar12;
  short *psVar13;
  short *psVar14;
  undefined8 local_48;
  short local_40 [12];
  
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  local_40[5] = 0;
  local_40[6] = 0;
  local_40[7] = 0;
  local_48 = 0;
  if ((((*param_1 < 2) || ((*param_1 & 1) != 0)) || (*param_2 < 2)) || ((*param_2 & 1) != 0)) {
    return -0x3fffffcd;
  }
  if ((param_3 & 0xfffffffc) != 0) {
    return -0x3ffffff3;
  }
  if (((byte)param_3 & 3) == 3) {
    return -0x3ffffff3;
  }
  _Dst = (undefined4 *)ExAllocatePool2(0x101,0x198,0x4c66704e);
  if (_Dst == (undefined4 *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,0x198);
  *(byte *)(_Dst + 1) = *(byte *)(_Dst + 1) | 0x40;
  *(byte *)((longlong)_Dst + 6) = *(byte *)((longlong)_Dst + 6) | 2;
  *(byte *)((longlong)_Dst + 7) = *(byte *)((longlong)_Dst + 7) & 0xf | 0x50;
  puVar10 = _Dst + 0xe;
  *(undefined4 **)(_Dst + 0x10) = puVar10;
  *(undefined4 **)puVar10 = puVar10;
  *(undefined8 *)(_Dst + 0x12) = 0;
  *(undefined8 *)(_Dst + 0x14) = 0;
  *(undefined8 *)(_Dst + 0x16) = 0;
  *(undefined8 *)(_Dst + 0x18) = 0;
  _Dst[0x1a] = 0;
  *(undefined8 *)(_Dst + 0x1c) = 0;
  puVar10 = (undefined4 *)ExAllocatePool2(0x41,0x38,0x4c66704e);
  *(undefined4 **)(_Dst + 0xc) = puVar10;
  if (puVar10 == (undefined4 *)0x0) goto LAB_1c000bf53;
  *puVar10 = 1;
  *(undefined8 *)(puVar10 + 2) = 0;
  puVar10[4] = 0;
  KeInitializeEvent(puVar10 + 6,1);
  *_Dst = 0x1980207;
  plVar1 = (longlong *)(_Dst + 0x22);
  _Dst[0x1e] = 1;
  plVar2 = (longlong *)(_Dst + 0x3a);
  _Dst[0x1f] = 1;
  *(undefined8 *)(_Dst + 0x20) = 0;
  *(longlong **)(_Dst + 0x24) = plVar1;
  *plVar1 = (longlong)plVar1;
  *(longlong **)(_Dst + 0x3c) = plVar2;
  *plVar2 = (longlong)plVar2;
  _Dst[0x3e] = param_3;
  uVar11 = IoGetFileObjectGenericMapping();
  iVar9 = SeAssignSecurity(0,*(undefined8 *)(param_5 + 0x40),&local_48,0,param_5 + 0x20,uVar11,1);
  if (iVar9 < 0) goto LAB_1c000bf58;
  iVar9 = ObLogSecurityDescriptor(local_48,_Dst + 0x26,1);
  ExFreePoolWithTag(local_48,0);
  if (iVar9 < 0) goto LAB_1c000bf58;
  uVar4 = *param_1;
  puVar3 = (ushort *)(_Dst + 0x28);
  *puVar3 = uVar4;
  *(ushort *)((longlong)_Dst + 0xa2) = *param_1;
  pvVar12 = (void *)ExAllocatePool2(0x101,uVar4,0x4c66704e);
  *(void **)(_Dst + 0x2a) = pvVar12;
  if (pvVar12 != (void *)0x0) {
    memcpy(pvVar12,*(void **)(param_1 + 4),(ulonglong)*puVar3);
    uVar4 = *param_2;
    *(ushort *)(_Dst + 0x40) = uVar4;
    *(ushort *)((longlong)_Dst + 0x102) = uVar4;
    pvVar12 = (void *)ExAllocatePool2(0x101,uVar4,0x4c66704e);
    *(void **)(_Dst + 0x42) = pvVar12;
    if (pvVar12 != (void *)0x0) {
      memcpy(pvVar12,*(void **)(param_2 + 4),(ulonglong)*(ushort *)(_Dst + 0x40));
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(param_4 + 0xc0,0);
      psVar13 = (short *)NpFindPrefix(param_4,(undefined8 *)param_1,'\x01',local_40);
      psVar14 = (short *)0x0;
      if (psVar13 == (short *)0x0) {
LAB_1c000c1d9:
        plVar6 = *(longlong **)(param_4 + 0xd0);
        if (*plVar6 != param_4 + 200) {
LAB_1c000c276:
          pcVar8 = (code *)swi(0x29);
          (*pcVar8)(3);
          return -0x3ffffff3;
        }
        *(longlong **)(_Dst + 0x24) = plVar6;
        *plVar1 = param_4 + 200;
        *plVar6 = (longlong)plVar1;
        *(longlong **)(param_4 + 0xd0) = plVar1;
        RtlInsertUnicodePrefix(param_4 + 0xd8,puVar3,_Dst + 0x2c);
        if (psVar14 != (short *)0x0) {
          puVar7 = *(undefined8 **)(psVar14 + 0x80);
          if ((short *)*puVar7 != psVar14 + 0x7c) goto LAB_1c000c276;
          *plVar2 = (longlong)(psVar14 + 0x7c);
          *(undefined8 **)(_Dst + 0x3c) = puVar7;
          *puVar7 = plVar2;
          *(longlong **)(psVar14 + 0x80) = plVar2;
        }
        iVar9 = 0;
        *param_6 = _Dst;
        _Dst = (undefined4 *)0x0;
      }
      else {
        sVar5 = *psVar13;
        if ((sVar5 != 0x202) && (sVar5 != 0x207)) {
          if (sVar5 == 0x203) {
            if (local_40[0] == 0) goto LAB_1c000c1cf;
            psVar14 = psVar13;
          }
          goto LAB_1c000c1d9;
        }
LAB_1c000c1cf:
        iVar9 = -0x3fffffcb;
      }
      ExReleasePushLockExclusiveEx(param_4 + 0xc0,0);
      KeLeaveCriticalRegion();
      if (_Dst == (undefined4 *)0x0) {
        return iVar9;
      }
      goto LAB_1c000bf58;
    }
  }
LAB_1c000bf53:
  iVar9 = -0x3fffff66;
LAB_1c000bf58:
  if (*(longlong *)(_Dst + 0x42) != 0) {
    ExFreePoolWithTag(*(longlong *)(_Dst + 0x42),0);
  }
  if (*(longlong *)(_Dst + 0x2a) != 0) {
    ExFreePoolWithTag(*(longlong *)(_Dst + 0x2a),0);
  }
  if (*(longlong *)(_Dst + 0x26) != 0) {
    ObDereferenceSecurityDescriptor(*(longlong *)(_Dst + 0x26),1);
  }
  if (*(longlong *)(_Dst + 0xc) != 0) {
    ExFreePoolWithTag(*(longlong *)(_Dst + 0xc),0);
  }
  ExFreePoolWithTag(_Dst,0);
  return iVar9;
}



===== NpCreateSymlinkAccessCheck @ 1c000c2b0 =====

undefined4
NpCreateSymlinkAccessCheck
          (undefined8 *param_1,ulonglong param_2,undefined8 param_3,longlong param_4,char param_5,
          longlong param_6)

{
  char cVar1;
  short *psVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint local_38;
  undefined4 local_34;
  short local_30 [12];
  
  local_38 = 0;
  local_34 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  if (param_5 != '\0') {
    cVar1 = SeSinglePrivilegeCheck(*(undefined8 *)(*(longlong *)SeExports_exref + 0x28),param_5);
    if (cVar1 == '\0') {
      return 0xc0000061;
    }
    if (((param_2 & 1) != 0) && (cVar1 = PsIsHostSilo(param_3), cVar1 == '\0')) {
      return 0xc0000022;
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_4 + 0xc0,0);
    psVar2 = (short *)NpFindPrefix(param_4,param_1,'\x01',local_30);
    ExReleasePushLockExclusiveEx(param_4 + 0xc0,0);
    KeLeaveCriticalRegion();
    if ((psVar2 == (short *)0x0) || (*psVar2 != 0x203)) {
      lVar4 = *(longlong *)(param_4 + 0x88);
    }
    else {
      lVar4 = *(longlong *)(psVar2 + 0x4c);
    }
    if (lVar4 != 0) {
      uVar3 = IoGetFileObjectGenericMapping();
      cVar1 = SeAccessCheck(lVar4,param_6 + 0x20,0,2,0,0,uVar3,param_5,&local_38,&local_34);
      if (cVar1 != '\0') {
        *(uint *)(param_6 + 0x14) = *(uint *)(param_6 + 0x14) | local_38;
        *(uint *)(param_6 + 0x10) = *(uint *)(param_6 + 0x10) & ~(local_38 | 0x2000000);
        local_34 = 0;
      }
      return local_34;
    }
  }
  return 0;
}



===== NpDeleteSymlink @ 1c000c454 =====

void NpDeleteSymlink(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_1 + 0xe8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_1 + 0xf0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    RtlRemoveUnicodePrefix(param_2 + 0xd8,param_1 + 0xb0);
    plVar1 = (longlong *)(param_1 + 0x88);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = *(longlong **)(param_1 + 0x90), (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x108),0);
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0xa8),0);
      ObDereferenceSecurityDescriptor(*(undefined8 *)(param_1 + 0x98),1);
      FsRtlTeardownPerStreamContexts(param_1);
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
      ExFreePoolWithTag(param_1,0);
      return;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== NpDeleteSymlinkAccessCheck @ 1c000c554 =====

undefined4 NpDeleteSymlinkAccessCheck(longlong param_1,undefined1 param_2,longlong param_3)

{
  char cVar1;
  undefined8 uVar2;
  uint local_res8 [2];
  undefined4 local_res18 [2];
  longlong local_res20;
  
  local_res8[0] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  uVar2 = IoGetFileObjectGenericMapping();
  cVar1 = SeAccessCheck(*(undefined8 *)(param_1 + 0x98),param_3 + 0x20,0,0x10000,0,&local_res20,
                        uVar2,param_2,local_res8,local_res18);
  if (local_res20 != 0) {
    SeAppendPrivileges(param_3);
    SeFreePrivileges(local_res20);
  }
  if (cVar1 != '\0') {
    *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | local_res8[0];
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & ~(local_res8[0] | 0x2000000);
    local_res18[0] = 0;
  }
  return local_res18[0];
}



===== NpOpenSymlink @ 1c000c638 =====

undefined8 NpOpenSymlink(longlong param_1,longlong param_2)

{
  ushort uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int iVar4;
  
  iVar4 = *(ushort *)(param_1 + 0x100) + 0x18;
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,iVar4,0x4c66704e);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    *(undefined4 *)puVar2 = 0xa000000c;
    *(short *)((longlong)puVar2 + 4) = (short)iVar4 + -8;
    uVar1 = *(ushort *)(param_1 + 0x100);
    *(ushort *)((longlong)puVar2 + 10) = uVar1;
    memcpy((void *)((longlong)puVar2 + 0x14),*(void **)(param_1 + 0x108),(ulonglong)uVar1);
    if ((*(uint *)(param_1 + 0xf8) & 1) == 0) {
      *(undefined8 *)(param_2 + 0x38) = 0xa000000c;
      if ((*(uint *)(param_1 + 0xf8) & 2) != 0) {
        *(uint *)(puVar2 + 2) = *(uint *)(puVar2 + 2) | 1;
      }
    }
    else {
      *(undefined8 *)(param_2 + 0x38) = 0xa0000019;
    }
    uVar3 = 0x104;
    *(undefined8 **)(param_2 + 0xa0) = puVar2;
    *(undefined4 *)(param_2 + 0x30) = 0x104;
  }
  return uVar3;
}



===== NpSetAttributeInList @ 1c000c720 =====

undefined8
NpSetAttributeInList
          (longlong *param_1,longlong *param_2,void *param_3,void *param_4,ulonglong param_5)

{
  char cVar1;
  char cVar2;
  code *pcVar3;
  longlong *plVar4;
  char *pcVar5;
  longlong *plVar6;
  int iVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  undefined1 *puVar11;
  longlong lVar12;
  size_t _Size;
  longlong lVar13;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  
  for (plVar10 = (longlong *)*param_1; plVar10 != param_1; plVar10 = (longlong *)*plVar10) {
    if (param_3 < (void *)0x7) {
      if ((void *)plVar10[2] == param_3) goto LAB_1c000c765;
    }
    else {
      pcVar5 = (char *)plVar10[2];
      iVar7 = (int)pcVar5;
      if (iVar7 == 1) {
        pcVar5 = "ServerProcessId";
      }
      else if (iVar7 == 2) {
        pcVar5 = "ServerSessionId";
      }
      else if (iVar7 == 3) {
        pcVar5 = "ClientProcessId";
      }
      else if (iVar7 == 4) {
        pcVar5 = "ClientSessionId";
      }
      else if (iVar7 == 6) {
        pcVar5 = "ClientComputerName";
      }
      lVar13 = (longlong)param_3 - (longlong)pcVar5;
      do {
        cVar1 = *pcVar5;
        cVar2 = pcVar5[lVar13];
        if (cVar1 != cVar2) break;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      if (cVar1 == cVar2) goto LAB_1c000c756;
    }
  }
  plVar10 = (longlong *)0x0;
LAB_1c000c756:
  if (param_3 < (void *)0x8) {
LAB_1c000c765:
    uVar8 = 0x28;
    _Size = 0;
  }
  else {
    lVar13 = -1;
    do {
      lVar12 = lVar13;
      lVar13 = lVar12 + 1;
    } while (*(char *)((longlong)param_3 + lVar12 + 1) != '\0');
    _Size = lVar12 + 2;
    uVar8 = lVar12 + 0x2a;
    if (uVar8 < 0x28) {
      return 0xc0000095;
    }
  }
  uVar9 = uVar8;
  if ((8 < param_5) && (uVar9 = uVar8 + param_5, uVar9 < uVar8)) {
    return 0xc0000095;
  }
  if (param_2 == (longlong *)0x0) {
    plVar4 = (longlong *)ExAllocatePool2(0x100,uVar9,0x7441704e);
    if (plVar4 == (longlong *)0x0) {
      return 0xc000009a;
    }
  }
  else {
    plVar4 = param_2;
  }
  puVar11 = auStack_48;
  if ((void *)0x7 < param_3) goto LAB_1c000c835;
  plVar4[2] = (longlong)param_3;
  puVar11 = auStack_48;
  do {
    if (param_5 < 9) {
      plVar6 = plVar4 + 4;
    }
    else {
      plVar6 = (longlong *)(_Size + 0x28 + (longlong)plVar4);
      plVar4[4] = (longlong)plVar6;
    }
    *(undefined8 *)(puVar11 + -8) = 0x1c000c7a9;
    memcpy(plVar6,param_4,param_5);
    plVar4[3] = param_5;
    if (plVar10 == (longlong *)0x0) {
LAB_1c000c7b6:
      plVar6 = (longlong *)param_1[1];
      if ((longlong *)*plVar6 == param_1) {
        plVar4[1] = (longlong)plVar6;
        *plVar4 = (longlong)param_1;
        *plVar6 = (longlong)plVar4;
        param_1[1] = (longlong)plVar4;
        return 0;
      }
    }
    else {
      lVar13 = *plVar10;
      if ((*(longlong **)(lVar13 + 8) == plVar10) &&
         (plVar6 = (longlong *)plVar10[1], (longlong *)*plVar6 == plVar10)) {
        *plVar6 = lVar13;
        *(longlong **)(lVar13 + 8) = plVar6;
        if (plVar10 != param_2) {
          *(undefined8 *)(puVar11 + -8) = 0x1c000c94f;
          ExFreePoolWithTag(plVar10,0);
        }
        goto LAB_1c000c7b6;
      }
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar11 = puVar11 + 8;
LAB_1c000c835:
    plVar4[2] = (longlong)(plVar4 + 5);
    *(undefined8 *)(puVar11 + -8) = 0x1c000c848;
    memcpy(plVar4 + 5,param_3,_Size);
  } while( true );
}



===== NpCreateNewNamedPipe @ 1c000c960 =====

int NpCreateNewNamedPipe
              (longlong param_1,longlong param_2,longlong param_3,ushort *param_4,uint param_5,
              longlong param_6,int param_7,short param_8,uint *param_9,undefined8 param_10,
              longlong param_11,int *param_12)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  code *pcVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 uVar10;
  longlong *plVar11;
  uint uVar12;
  undefined2 uVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  longlong *plVar16;
  undefined8 uStackY_c0;
  undefined1 auStackY_b8 [32];
  uint uStack_8c;
  undefined8 local_68;
  ulonglong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  local_68 = 0;
  local_50 = 0;
  local_58 = 0;
  local_60 = 0;
  if ((((char)param_9[8] != '\0') && (param_9[3] != 0)) && (*(longlong *)(param_9 + 6) < 0)) {
    if (param_7 == 1) {
      iVar9 = -0x3fffffcc;
      goto LAB_1c000ccc4;
    }
    if (param_8 == 3) {
      uVar13 = 2;
    }
    else if (param_8 == 1) {
      uVar13 = 1;
    }
    else {
      if (param_8 != 2) goto LAB_1c000cd14;
      uVar13 = 0;
    }
    uVar12 = *param_9 & 1;
    if ((uVar12 != 0) || (param_9[1] != 1)) {
      uVar10 = NpCreateFcb(param_1,param_2,param_4,param_9[3],*(undefined8 *)(param_9 + 6),uVar13,
                           uVar12 ^ 1,~(*param_9 >> 1) & 1);
      iVar9 = (int)uVar10;
      if (-1 < iVar9) {
        local_48 = PsGetProcessId(param_10);
        uVar8 = PsGetProcessSessionId(param_10);
        lVar7 = local_58;
        puVar15 = auStackY_b8;
        plVar1 = (longlong *)(local_58 + 0x128);
        plVar11 = (longlong *)(local_58 + 0x148);
        for (plVar14 = (longlong *)*plVar1; plVar14 != plVar1; plVar14 = (longlong *)*plVar14) {
          if (plVar14[2] == 1) goto LAB_1c000ca8e;
        }
        plVar14 = (longlong *)0x0;
LAB_1c000ca8e:
        plVar16 = plVar11;
        if (plVar11 == (longlong *)0x0) goto LAB_1c000cd22;
        puVar15 = auStackY_b8;
        do {
          plVar11[2] = 1;
          *(int *)(plVar11 + 4) = (int)local_48;
          plVar11[3] = 4;
          if (plVar14 == (longlong *)0x0) {
LAB_1c000caba:
            plVar2 = *(longlong **)(lVar7 + 0x130);
            if ((longlong *)*plVar2 == plVar1) {
              *plVar11 = (longlong)plVar1;
              plVar16 = (longlong *)(lVar7 + 0x170);
              plVar11[1] = (longlong)plVar2;
              *plVar2 = (longlong)plVar11;
              *(longlong **)(lVar7 + 0x130) = plVar11;
              for (plVar14 = (longlong *)*plVar1; plVar14 != plVar1; plVar14 = (longlong *)*plVar14)
              {
                if (plVar14[2] == 2) goto LAB_1c000caea;
              }
              plVar14 = (longlong *)0x0;
LAB_1c000caea:
              if (plVar16 == (longlong *)0x0) {
                *(undefined8 *)(puVar15 + -8) = 0x1c000cda6;
                plVar11 = (longlong *)ExAllocatePool2(0x100,0x28,0x7441704e);
                if (plVar11 == (longlong *)0x0) break;
              }
              else {
                plVar11 = plVar16;
              }
              plVar11[2] = 2;
              *(undefined4 *)(plVar11 + 4) = uVar8;
              plVar11[3] = 4;
              if (plVar14 != (longlong *)0x0) {
                lVar4 = *plVar14;
                if ((*(longlong **)(lVar4 + 8) != plVar14) ||
                   (plVar2 = (longlong *)plVar14[1], (longlong *)*plVar2 != plVar14))
                goto LAB_1c000cd1b;
                *plVar2 = lVar4;
                *(longlong **)(lVar4 + 8) = plVar2;
                if (plVar14 != plVar16) {
                  *(undefined8 *)(puVar15 + -8) = 0x1c000cdee;
                  ExFreePoolWithTag(plVar14,0);
                }
              }
              puVar3 = *(undefined8 **)(lVar7 + 0x130);
              if ((longlong *)*puVar3 == plVar1) {
                *plVar11 = (longlong)plVar1;
                plVar11[1] = (longlong)puVar3;
                *puVar3 = plVar11;
                *(longlong **)(lVar7 + 0x130) = plVar11;
                uVar12 = param_9[1];
                *(ulonglong **)(puVar15 + 0x38) = &local_60;
                *(uint *)(puVar15 + 0x30) = param_9[5];
                *(uint *)(puVar15 + 0x28) = param_9[4];
                *(uint *)(puVar15 + 0x20) = param_9[2];
                *(undefined8 *)(puVar15 + -8) = 0x1c000cb7e;
                uVar10 = NpCreateCcb(lVar7,param_3,((param_5 & 0xf2000003) != 0) + 1,(byte)uVar12,
                                     puVar15[0x20],*(undefined4 *)(puVar15 + 0x28),
                                     *(undefined4 *)(puVar15 + 0x30),
                                     *(undefined8 **)(puVar15 + 0x38));
                iVar9 = (int)uVar10;
                if (-1 < iVar9) {
                  *(undefined8 *)(puVar15 + -8) = 0x1c000cb8f;
                  uVar10 = IoGetFileObjectGenericMapping();
                  *(undefined4 *)(puVar15 + 0x30) = 1;
                  *(undefined8 *)(puVar15 + 0x28) = uVar10;
                  uVar10 = *(undefined8 *)(param_6 + 0x40);
                  *(longlong *)(puVar15 + 0x20) = param_6 + 0x20;
                  *(undefined8 *)(puVar15 + -8) = 0x1c000cbbe;
                  iVar9 = SeAssignSecurity(0,uVar10,&local_68,0);
                  uVar10 = local_68;
                  if (-1 < iVar9) {
                    *(undefined8 *)(puVar15 + -8) = 0x1c000cbdf;
                    iVar9 = ObLogSecurityDescriptor(uVar10,&local_50,1);
                    uVar10 = local_68;
                    *(undefined8 *)(puVar15 + -8) = 0x1c000cbf3;
                    ExFreePoolWithTag(uVar10,0);
                    if (-1 < iVar9) {
                      *(undefined8 *)(lVar7 + 0x98) = local_50;
                      uVar10 = *(undefined8 *)(local_60 + 0x28);
                      *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 0x80;
                      *(undefined8 *)(param_3 + 0x18) = uVar10;
                      *(undefined8 *)(param_3 + 0x30) = 1;
                      *(ulonglong *)(param_3 + 0x20) = local_60 | 3;
                      *(longlong *)(local_60 + 0x38) = param_3;
                      if (*param_4 != 0) {
                        *(undefined4 *)(puVar15 + 0x20) = 1;
                        *(undefined8 *)(puVar15 + -8) = 0x1c000cc51;
                        NpCheckForNotifyWithFilter(param_1,param_11,1,param_4);
                      }
                      *param_12 = 0;
                      param_12[2] = 2;
                      param_12[3] = 0;
                      return 0;
                    }
                  }
                  uVar6 = local_60;
                  *(int *)(lVar7 + 0xf8) = *(int *)(lVar7 + 0xf8) + -1;
                  *(undefined8 *)(puVar15 + -8) = 0x1c000cd0b;
                  NpDeleteCcb(param_1,uVar6,param_11);
                }
                goto LAB_1c000ccaa;
              }
            }
          }
          else {
            lVar4 = *plVar14;
            if ((*(longlong **)(lVar4 + 8) == plVar14) &&
               (plVar2 = (longlong *)plVar14[1], (longlong *)*plVar2 == plVar14)) {
              *plVar2 = lVar4;
              *(longlong **)(lVar4 + 8) = plVar2;
              if (plVar14 != plVar16) {
                *(undefined8 *)(puVar15 + -8) = 0x1c000cd85;
                ExFreePoolWithTag(plVar14,0);
              }
              goto LAB_1c000caba;
            }
          }
LAB_1c000cd1b:
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          puVar15 = puVar15 + 8;
LAB_1c000cd22:
          *(undefined8 *)(puVar15 + -8) = 0x1c000cd39;
          plVar11 = (longlong *)ExAllocatePool2(0x100,0x28,0x7441704e);
        } while (plVar11 != (longlong *)0x0);
        iVar9 = -0x3fffff66;
LAB_1c000ccaa:
        *(undefined8 *)(puVar15 + -8) = 0x1c000ccbc;
        NpUnlinkFcb(param_1,lVar7,param_11);
        *(undefined8 *)(puVar15 + -8) = 0x1c000ccc4;
        NpFreeFcb(lVar7);
      }
      goto LAB_1c000ccc4;
    }
  }
LAB_1c000cd14:
  iVar9 = -0x3ffffff3;
LAB_1c000ccc4:
  param_12[2] = 0;
  param_12[3] = 0;
  *param_12 = iVar9;
  return iVar9;
}



===== NpCreateFcb @ 1c000ce00 =====

undefined8
NpCreateFcb(longlong param_1,longlong param_2,ushort *param_3,undefined4 param_4,undefined8 param_5,
           undefined2 param_6,undefined4 param_7,undefined4 param_8)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined4 *_Dst;
  undefined4 *puVar5;
  void *_Dst_00;
  undefined1 *puVar6;
  undefined1 *puVar7;
  ushort uVar8;
  longlong lVar9;
  undefined1 auStack_48 [32];
  
  uVar8 = *param_3;
  if ((uVar8 < 2) || (**(short **)(param_3 + 4) != 0x5c)) {
    lVar9 = 0;
  }
  else {
    uVar8 = uVar8 - 2;
    if (uVar8 < 2) {
      return 0xc000000d;
    }
    lVar9 = 2;
  }
  _Dst = (undefined4 *)ExAllocatePool2(0x101,0x198,0x4666704e);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x198);
    *(byte *)(_Dst + 1) = *(byte *)(_Dst + 1) | 0x40;
    *(byte *)((longlong)_Dst + 6) = *(byte *)((longlong)_Dst + 6) | 2;
    *(byte *)((longlong)_Dst + 7) = *(byte *)((longlong)_Dst + 7) & 0xf | 0x50;
    puVar5 = _Dst + 0xe;
    *(undefined4 **)(_Dst + 0x10) = puVar5;
    *(undefined4 **)puVar5 = puVar5;
    *(undefined8 *)(_Dst + 0x12) = 0;
    *(undefined8 *)(_Dst + 0x14) = 0;
    *(undefined8 *)(_Dst + 0x16) = 0;
    *(undefined8 *)(_Dst + 0x18) = 0;
    _Dst[0x1a] = 0;
    *(undefined8 *)(_Dst + 0x1c) = 0;
    puVar5 = (undefined4 *)ExAllocatePool2(0x41,0x38,0x4666704e);
    *(undefined4 **)(_Dst + 0xc) = puVar5;
    if (puVar5 != (undefined4 *)0x0) {
      *(undefined8 *)(puVar5 + 2) = 0;
      *puVar5 = 1;
      puVar5[4] = 0;
      KeInitializeEvent(puVar5 + 6,1,0);
      *(undefined8 *)(_Dst + 0x44) = param_5;
      puVar5 = _Dst + 0x46;
      *(undefined8 *)(_Dst + 0x20) = 0;
      plVar3 = (longlong *)(_Dst + 0x22);
      _Dst[0x3f] = param_4;
      plVar1 = (longlong *)(_Dst + 0x3a);
      *_Dst = 0x1980202;
      _Dst[0x1f] = 1;
      *(longlong **)(_Dst + 0x24) = plVar3;
      *plVar3 = (longlong)plVar3;
      *(longlong **)(_Dst + 0x3c) = plVar1;
      *plVar1 = (longlong)plVar1;
      *(undefined4 **)(_Dst + 0x48) = puVar5;
      *(undefined4 **)puVar5 = puVar5;
      puVar5 = _Dst + 0x4a;
      *(undefined4 **)(_Dst + 0x4c) = puVar5;
      *(undefined4 **)puVar5 = puVar5;
      puVar5 = _Dst + 0x4e;
      *(undefined4 **)(_Dst + 0x50) = puVar5;
      *(undefined4 **)puVar5 = puVar5;
      *(undefined2 *)(_Dst + 0x40) = param_6;
      _Dst[0x41] = param_7;
      _Dst[0x42] = param_8;
      puVar6 = auStack_48;
      if (uVar8 == 0) {
LAB_1c000d03d:
        **(undefined8 **)(puVar6 + 0x90) = _Dst;
        return 0;
      }
      _Dst_00 = (void *)ExAllocatePool2(0x41,uVar8,0x6e46704e);
      if (_Dst_00 != (void *)0x0) {
        memcpy(_Dst_00,(void *)(*(longlong *)(param_3 + 4) + lVar9),(ulonglong)uVar8);
        *(ushort *)((longlong)_Dst + 0xa2) = uVar8;
        *(ushort *)(_Dst + 0x28) = uVar8;
        *(void **)(_Dst + 0x2a) = _Dst_00;
        RtlInsertUnicodePrefix(param_1 + 0xd8,_Dst + 0x28,_Dst + 0x2c);
        puVar7 = auStack_48;
        plVar2 = *(longlong **)(param_1 + 0xd0);
        puVar6 = auStack_48;
        if (*plVar2 != param_1 + 200) goto LAB_1c000d0a1;
        *plVar3 = param_1 + 200;
        *(longlong **)(_Dst + 0x24) = plVar2;
        *plVar2 = (longlong)plVar3;
        *(longlong **)(param_1 + 0xd0) = plVar3;
        puVar6 = auStack_48;
        if (param_2 != 0) {
          while( true ) {
            plVar3 = *(longlong **)(param_2 + 0x100);
            puVar6 = puVar7;
            if (*plVar3 == param_2 + 0xf8) break;
LAB_1c000d0a1:
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            puVar7 = puVar6 + 8;
          }
          *plVar1 = param_2 + 0xf8;
          *(longlong **)(_Dst + 0x3c) = plVar3;
          *plVar3 = (longlong)plVar1;
          *(longlong **)(param_2 + 0x100) = plVar1;
        }
        goto LAB_1c000d03d;
      }
      ExFreePoolWithTag(*(undefined8 *)(_Dst + 0xc),0);
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return 0xc000009a;
}



===== NpCreateExistingNamedPipe @ 1c000d0d4 =====

int * NpCreateExistingNamedPipe
                (int *param_1,longlong param_2,longlong param_3,longlong param_4,uint param_5,
                longlong param_6,undefined1 param_7,int param_8,short param_9,longlong param_10,
                undefined8 param_11,longlong param_12)

{
  longlong lVar1;
  int *piVar2;
  char cVar3;
  undefined8 uVar4;
  short sVar5;
  uint uVar6;
  uint local_res8 [2];
  longlong local_res18;
  ulonglong local_res20;
  undefined8 in_stack_ffffffffffffff88;
  longlong *plVar7;
  undefined4 local_48;
  undefined4 local_44;
  wchar_t *local_40;
  
  uVar6 = (uint)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_res8[0] = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  local_44 = 0;
  lVar1 = param_6 + 0x20;
  local_res20 = 0;
  local_res18 = 0;
  SeLockSubjectContext(lVar1);
  uVar4 = IoGetFileObjectGenericMapping();
  plVar7 = &local_res18;
  cVar3 = SeAccessCheck(*(undefined8 *)(param_3 + 0x98),lVar1,1,param_5 | 4,(ulonglong)uVar6 << 0x20
                        ,plVar7,uVar4,param_7,local_res8,param_1);
  if (local_res18 != 0) {
    SeAppendPrivileges(param_6);
    SeFreePrivileges(local_res18);
  }
  if (cVar3 != '\0') {
    *(uint *)(param_6 + 0x14) = *(uint *)(param_6 + 0x14) | local_res8[0];
    *(uint *)(param_6 + 0x10) = *(uint *)(param_6 + 0x10) & ~(local_res8[0] | 0x2000000);
  }
  local_40 = L"NamedPipe";
  local_48 = 0x140012;
  SeOpenObjectAuditAlarm
            (&local_48,0,param_4 + 0x58,*(undefined8 *)(param_3 + 0x98),param_6,
             (ulonglong)plVar7 & 0xffffffffffffff00,cVar3,param_7,param_6 + 10);
  SeUnlockSubjectContext(lVar1);
  if (cVar3 != '\0') {
    if (*(uint *)(param_3 + 0x78) < *(uint *)(param_3 + 0xfc)) {
      sVar5 = 2;
      if (param_8 != 2) {
        uVar6 = *(uint *)(param_3 + 0x100) & 0xffff;
        if (uVar6 == 1) {
          sVar5 = 1;
        }
        else if (uVar6 != 0) {
          sVar5 = 3;
        }
        if (sVar5 == param_9) {
          uVar4 = NpCreateCcb(param_3,param_4,((param_5 & 0xf2000003) != 0) + 1,
                              (byte)*(undefined4 *)(param_10 + 4),
                              (char)*(undefined4 *)(param_10 + 8),*(undefined4 *)(param_10 + 0x10),
                              *(undefined4 *)(param_10 + 0x14),&local_res20);
          *param_1 = (int)uVar4;
          if ((int)uVar4 < 0) {
            return param_1;
          }
          uVar4 = NpCancelWaiter((longlong *)(param_2 + 0x90),(ushort *)(param_3 + 0xa0),0,param_12)
          ;
          *param_1 = (int)uVar4;
          if ((int)uVar4 < 0) {
            piVar2 = (int *)(*(longlong *)(local_res20 + 0x28) + 0xf8);
            *piVar2 = *piVar2 + -1;
            NpDeleteCcb(param_2,local_res20,param_12);
            return param_1;
          }
          LOCK();
          *(int *)(param_3 + 0x7c) = *(int *)(param_3 + 0x7c) + 1;
          UNLOCK();
          uVar4 = *(undefined8 *)(local_res20 + 0x28);
          *(uint *)(param_4 + 0x50) = *(uint *)(param_4 + 0x50) | 0x80;
          *(undefined8 *)(param_4 + 0x18) = uVar4;
          *(undefined8 *)(param_4 + 0x30) = 1;
          *(ulonglong *)(param_4 + 0x20) = local_res20 | 3;
          *(longlong *)(local_res20 + 0x38) = param_4;
          NpCheckForNotifyWithFilter(param_2,param_12,0x40,(ushort *)(param_3 + 0xa0));
          *param_1 = 0;
          param_1[2] = 1;
          param_1[3] = 0;
          return param_1;
        }
      }
      *param_1 = -0x3fffffde;
    }
    else {
      *param_1 = -0x3fffff55;
    }
  }
  return param_1;
}



===== NpCreateCcb @ 1c000d39c =====

undefined8
NpCreateCcb(longlong param_1,undefined8 param_2,int param_3,byte param_4,char param_5,
           undefined4 param_6,undefined4 param_7,undefined8 *param_8)

{
  undefined2 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  undefined2 *_Dst;
  undefined8 uVar6;
  byte bVar7;
  
  _Dst = (undefined2 *)ExAllocatePool2(0x101,0x1d0,0x6346704e);
  if (_Dst == (undefined2 *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    memset(_Dst,0,0x1d0);
    *_Dst = 0x204;
    *(longlong *)(_Dst + 0x14) = param_1;
    *(undefined4 *)(_Dst + 2) = 1;
    *(undefined8 *)(_Dst + 0x1c) = param_2;
    *(char *)(_Dst + 4) = (char)param_3;
    bVar7 = (*(byte *)(_Dst + 5) ^ param_4) & 1 ^ *(byte *)(_Dst + 5);
    puVar1 = _Dst + 0x24;
    *(byte *)(_Dst + 5) = (param_5 * '\x02' ^ bVar7) & 2 ^ bVar7;
    *(undefined4 *)(_Dst + 0x2e) = 0;
    *(undefined4 *)(_Dst + 0x30) = 0;
    *(undefined4 *)(_Dst + 0x34) = 0;
    *(undefined4 *)(_Dst + 0x32) = param_6;
    *(undefined4 *)(_Dst + 0x2c) = 2;
    *(undefined2 **)(_Dst + 0x28) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    *(undefined4 *)(_Dst + 0x36) = 0;
    *(ulonglong *)(_Dst + 0x38) = (ulonglong)(_Dst + 0x3c) | 1;
    puVar1 = _Dst + 0x54;
    *(undefined4 *)(_Dst + 0x5e) = 0;
    *(undefined4 *)(_Dst + 0x60) = 0;
    *(undefined4 *)(_Dst + 100) = 0;
    *(undefined4 *)(_Dst + 0x62) = param_7;
    *(undefined4 *)(_Dst + 0x5c) = 2;
    *(undefined2 **)(_Dst + 0x58) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    *(undefined4 *)(_Dst + 0x66) = 0;
    *(ulonglong *)(_Dst + 0x68) = (ulonglong)(_Dst + 0x6c) | 1;
    plVar3 = *(longlong **)(param_1 + 0x120);
    plVar2 = (longlong *)(_Dst + 0xc);
    if (*plVar3 != param_1 + 0x118) {
LAB_1c000d586:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar6 = (*pcVar4)();
      return uVar6;
    }
    *plVar2 = param_1 + 0x118;
    *(longlong **)(_Dst + 0x10) = plVar3;
    *plVar3 = (longlong)plVar2;
    *(longlong **)(param_1 + 0x120) = plVar2;
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
    if (param_3 == 2) {
      plVar2 = (longlong *)(_Dst + 0x90);
      plVar3 = *(longlong **)(param_1 + 0x140);
      if (*plVar3 != param_1 + 0x138) goto LAB_1c000d586;
      *plVar2 = param_1 + 0x138;
      *(longlong **)(_Dst + 0x94) = plVar3;
      *plVar3 = (longlong)plVar2;
      *(longlong **)(param_1 + 0x140) = plVar2;
    }
    do {
      LOCK();
      UNLOCK();
      iVar5 = NpCcbIndexGenerator + 1;
      NpCcbIndexGenerator = NpCcbIndexGenerator + 1;
      *(int *)(_Dst + 0xe4) = iVar5;
    } while (iVar5 == 0);
    puVar1 = _Dst + 0x88;
    *(undefined2 **)(_Dst + 0x8c) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    puVar1 = _Dst + 0x98;
    *(undefined2 **)(_Dst + 0x9c) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    puVar1 = _Dst + 0xa0;
    *(undefined2 **)(_Dst + 0xa4) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    puVar1 = _Dst + 0xa8;
    *(undefined2 **)(_Dst + 0xac) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    *(undefined8 *)(_Dst + 0xd8) = 0;
    *(undefined8 *)(_Dst + 0xdc) = 0;
    *(undefined8 *)(_Dst + 0xe0) = 0;
    *param_8 = _Dst;
    uVar6 = 0;
  }
  return uVar6;
}



===== NpCheckForNotifyWithFilter @ 1c000d594 =====

void NpCheckForNotifyWithFilter(longlong param_1,longlong param_2,uint param_3,ushort *param_4)

{
  longlong *plVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  ushort *puVar8;
  void *_Src;
  code *pcVar9;
  void *_Dst;
  longlong *plVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  longlong *plVar13;
  undefined1 auStack_68 [48];
  
  plVar1 = (longlong *)(param_1 + 0xb0);
  if ((longlong *)*plVar1 != plVar1) {
    ExAcquirePushLockExclusiveEx(param_1 + 0xa8);
    puVar11 = auStack_68;
    plVar10 = (longlong *)*plVar1;
    plVar13 = *(longlong **)*plVar1;
    while (plVar10 != plVar1) {
      lVar5 = plVar10[2];
      if ((*(uint *)(lVar5 + 0x10) & param_3) != 0) {
        lVar6 = *plVar10;
        uVar12 = 0;
        if (*(longlong **)(lVar6 + 8) != plVar10) goto LAB_1c000d751;
        plVar7 = (longlong *)plVar10[1];
        if ((longlong *)*plVar7 != plVar10) goto LAB_1c000d751;
        *plVar7 = lVar6;
        *(longlong **)(lVar6 + 8) = plVar7;
        if (param_4 == (ushort *)0x0) goto LAB_1c000d6e5;
        if (*(uint *)(lVar5 + 8) == 0) goto LAB_1c000d6e5;
        uVar2 = *param_4;
        if (*(uint *)(lVar5 + 8) < uVar2 + 0x10) goto LAB_1c000d758;
        _Dst = (void *)plVar10[-0x12];
        if (_Dst == (void *)0x0) {
          lVar6 = plVar10[-0x14];
          if (lVar6 != 0) {
            if ((*(byte *)(lVar6 + 10) & 5) == 0) {
              *(undefined4 *)(puVar11 + 0x28) = 0x40000010;
              *(undefined4 *)(puVar11 + 0x20) = 0;
              *(undefined8 *)(puVar11 + -8) = 0x1c000d68c;
              _Dst = (void *)MmMapLockedPagesSpecifyCache(lVar6,0,1,0);
            }
            else {
              _Dst = *(void **)(lVar6 + 0x18);
            }
            if (_Dst != (void *)0x0) goto LAB_1c000d699;
          }
        }
        else {
LAB_1c000d699:
          uVar4 = *(uint *)(lVar5 + 8);
          *(undefined8 *)(puVar11 + -8) = 0x1c000d6a7;
          memset(_Dst,0,(ulonglong)uVar4);
          puVar8 = *(ushort **)(puVar11 + 0x88);
          *(uint *)((longlong)_Dst + 8) = (uint)*puVar8;
          uVar3 = *puVar8;
          _Src = *(void **)(puVar8 + 4);
          *(undefined8 *)(puVar11 + -8) = 0x1c000d6c6;
          memcpy((void *)((longlong)_Dst + 0xc),_Src,(ulonglong)uVar3);
          *(undefined4 *)((longlong)_Dst + 4) = *(undefined4 *)(puVar11 + 0x90);
          plVar10[-0xe] = (ulonglong)(uVar2 + 0x10);
        }
        param_4 = *(ushort **)(puVar11 + 0x88);
        uVar12 = 0;
        while( true ) {
          param_3 = *(uint *)(puVar11 + 0x80);
LAB_1c000d6e5:
          LOCK();
          lVar5 = plVar10[-8];
          plVar10[-8] = 0;
          UNLOCK();
          if (lVar5 == 0) {
            plVar10[1] = (longlong)plVar10;
            *plVar10 = (longlong)plVar10;
            goto LAB_1c000d70b;
          }
          *(undefined4 *)(plVar10 + -0xf) = uVar12;
          plVar7 = *(longlong **)(param_2 + 8);
          if (*plVar7 == param_2) break;
LAB_1c000d751:
          pcVar9 = (code *)swi(0x29);
          (*pcVar9)(3);
          puVar11 = puVar11 + 8;
LAB_1c000d758:
          uVar12 = 0xc0000023;
        }
        *plVar10 = param_2;
        plVar10[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar10;
        *(longlong **)(param_2 + 8) = plVar10;
      }
LAB_1c000d70b:
      plVar10 = plVar13;
      plVar13 = (longlong *)*plVar13;
    }
    *(undefined8 *)(puVar11 + -8) = 0x1c000d724;
    ExReleasePushLockExclusiveEx(*(undefined8 *)(puVar11 + 0x70),0);
  }
  return;
}



===== NpFsdClose @ 1c000d770 =====

undefined8 NpFsdClose(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  longlong lVar4;
  short *psVar5;
  ulonglong uVar6;
  undefined8 ****local_18;
  undefined8 ****local_10;
  
  KeEnterCriticalRegion();
  local_10 = &local_18;
  local_18 = &local_18;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  psVar5 = *(short **)(lVar4 + 0x18);
  sVar3 = *psVar5;
  if (sVar3 == 0x206) {
    uVar6 = *(ulonglong *)(lVar4 + 0x20);
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x40) + 0x78);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    uVar6 = uVar6 & 0xfffffffffffffffe;
    if (uVar6 != 0) {
      if (*(longlong *)(uVar6 + 0x10) != 0) {
        ExFreePoolWithTag(*(longlong *)(uVar6 + 0x10),0);
      }
      ExFreePoolWithTag(uVar6,0);
    }
  }
  else if (sVar3 == 0x201) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x40) + 0x78);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  else if (sVar3 == 0x202) {
    uVar6 = *(ulonglong *)(lVar4 + 0x20) & 0xfffffffffffffffc;
    LOCK();
    piVar1 = (int *)(uVar6 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      lVar4 = *(longlong *)(uVar6 + 0x28);
      LOCK();
      piVar1 = (int *)(lVar4 + 0x7c);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        NpFreeFcb(lVar4);
      }
      NpFreeCcb(uVar6);
    }
  }
  else if (sVar3 == 0x203) {
    LOCK();
    piVar1 = (int *)(psVar5 + 0x3e);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      NpFreeProtectedPrefix((longlong)psVar5);
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,2);
  KeLeaveCriticalRegion();
  return 0;
}



===== NpFreeCcb @ 1c000d8a8 =====

void NpFreeCcb(longlong param_1)

{
  longlong *plVar1;
  
  NpRemoveAllAttributesFromList((longlong *)(param_1 + 0x130));
  plVar1 = *(longlong **)(param_1 + 0x1b0);
  if (plVar1 != (longlong *)0x0) {
    if (*plVar1 != 0) {
      ObfDereferenceObject();
    }
    ExFreePoolWithTag(plVar1,0);
    *(undefined8 *)(param_1 + 0x1b0) = 0;
  }
  plVar1 = *(longlong **)(param_1 + 0x1b8);
  if (plVar1 != (longlong *)0x0) {
    if (*plVar1 != 0) {
      ObfDereferenceObject();
    }
    ExFreePoolWithTag(plVar1,0);
    *(undefined8 *)(param_1 + 0x1b8) = 0;
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== NpFreeFcb @ 1c000d95c =====

void NpFreeFcb(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x98) != 0) {
    ObDereferenceSecurityDescriptor(*(longlong *)(param_1 + 0x98),1);
  }
  NpRemoveAllAttributesFromList((longlong *)(param_1 + 0x128));
  if (*(longlong *)(param_1 + 0xa8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xa8),0);
  }
  FsRtlTeardownPerStreamContexts(param_1);
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== NpFreeProtectedPrefix @ 1c000d9e8 =====

void NpFreeProtectedPrefix(longlong param_1)

{
  FsRtlTeardownPerStreamContexts();
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
  ObDereferenceSecurityDescriptor(*(undefined8 *)(param_1 + 0x98),1);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== NpCreateClientEnd @ 1c000da48 =====

/* WARNING: Removing unreachable block (ram,0x0001c000df19) */

int * NpCreateClientEnd(int *param_1,longlong param_2,longlong *param_3,undefined4 param_4,
                       ulonglong param_5,uint *param_6,char param_7,undefined8 param_8,
                       undefined8 param_9,uint *param_10,undefined8 param_11,longlong param_12)

{
  byte bVar1;
  ushort uVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 uVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  uint uVar19;
  undefined2 local_res8 [4];
  uint local_res10;
  longlong *local_res18;
  undefined1 auStackY_a8 [32];
  ulonglong local_58;
  undefined4 local_48;
  undefined4 local_44;
  wchar_t *local_40;
  
  local_res10 = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  local_44 = 0;
  puVar14 = param_6 + 8;
  local_res8[0] = 0;
  uVar19 = *(uint *)(param_2 + 0x100) & 0xffff;
  local_res18 = param_3;
  SeLockSubjectContext(puVar14);
  IoGetFileObjectGenericMapping();
  cVar7 = SeAccessCheck(*(undefined8 *)(param_2 + 0x98),puVar14,1,param_4);
  puVar18 = auStackY_a8;
  puVar17 = auStackY_a8;
  puVar16 = auStackY_a8;
  puVar15 = auStackY_a8;
  if (cVar7 != '\0') {
    param_6[5] = param_6[5] | local_res10;
    param_6[4] = param_6[4] & ~(local_res10 | 0x2000000);
  }
  local_40 = L"NamedPipe";
  local_48 = 0x140012;
  SeOpenObjectAuditAlarm(&local_48,0,local_res18 + 0xb,*(undefined8 *)(param_2 + 0x98));
  SeUnlockSubjectContext(puVar14);
  if (cVar7 == '\0') {
    return param_1;
  }
  if ((((local_res10 & 1) != 0) && (uVar19 == 0)) || (((local_res10 & 2) != 0 && (uVar19 == 1)))) {
    *param_1 = -0x3fffffde;
    return param_1;
  }
  uVar19 = local_res10 & 3;
  plVar3 = *(longlong **)(param_2 + 0x138);
  if (plVar3 == (longlong *)(param_2 + 0x138)) {
    *param_1 = -0x3fffff54;
    return param_1;
  }
  ExAcquirePushLockExclusiveEx(plVar3 + -0x1c,0);
  puVar14 = param_10;
  if (param_10 != (uint *)0x0) {
    while( true ) {
      param_6 = (uint *)((longlong)puVar14 + (ulonglong)*(byte *)((longlong)puVar14 + 5) + 9);
      iVar8 = strncmp((char *)(puVar14 + 2),"ClientComputerName",
                      (ulonglong)*(byte *)((longlong)puVar14 + 5));
      if (iVar8 == 0) break;
      if (*puVar14 == 0) goto LAB_1c000dc1f;
      puVar14 = (uint *)((longlong)puVar14 + (ulonglong)*puVar14);
    }
    uVar2 = *(ushort *)((longlong)puVar14 + 6);
    puVar18 = auStackY_a8;
    if (((param_7 != '\0') && (puVar18 = auStackY_a8, (uVar2 & 1) == 0)) &&
       (puVar18 = auStackY_a8, 3 < (ulonglong)uVar2)) {
      lVar10 = RtlCompareMemory((void *)((longlong)param_6 + ((ulonglong)(uVar2 >> 1) - 1) * 2),
                                local_res8,2);
      puVar18 = auStackY_a8;
      if (lVar10 == 2) {
        if (*(int *)(param_2 + 0x108) == 0) {
          iVar8 = -0x3fffffde;
          goto LAB_1c000df45;
        }
        uVar11 = NpSetAttributeInList
                           (plVar3 + 2,(longlong *)0x0,(void *)0x6,param_6,(ulonglong)uVar2);
        iVar8 = (int)uVar11;
        puVar17 = auStackY_a8;
        if (iVar8 < 0) goto LAB_1c000df45;
        puVar14 = param_10;
        while( true ) {
          bVar1 = *(byte *)((longlong)puVar14 + 5);
          iVar8 = strncmp((char *)(puVar14 + 2),"ClientProcessId",(ulonglong)bVar1);
          if (iVar8 == 0) break;
          if (*puVar14 == 0) goto LAB_1c000de6d;
          puVar14 = (uint *)((longlong)puVar14 + (ulonglong)*puVar14);
        }
        puVar18 = auStackY_a8;
        if (3 < *(ushort *)((longlong)puVar14 + 6)) {
          uVar11 = NpSetAttributeInList
                             (plVar3 + 2,plVar3 + 8,(void *)0x3,
                              (char *)((longlong)(puVar14 + 2) + (ulonglong)bVar1 + 1),4);
          iVar8 = (int)uVar11;
          puVar17 = auStackY_a8;
          if (-1 < iVar8) {
LAB_1c000de6d:
            while( true ) {
              local_58 = (ulonglong)*(byte *)((longlong)param_10 + 5);
              param_6 = param_10 + 2;
              iVar8 = strncmp((char *)param_6,"ClientSessionId",
                              (ulonglong)*(byte *)((longlong)param_10 + 5));
              if (iVar8 == 0) goto LAB_1c000deb8;
              if (*param_10 == 0) break;
              param_10 = (uint *)((longlong)param_10 + (ulonglong)*param_10);
            }
LAB_1c000dcfd:
            *(undefined8 *)(puVar15 + -8) = 0x1c000dd10;
            iVar8 = NpInitializeSecurity
                              ((longlong)(plVar3 + -0x24),
                               (undefined8 *)(-(ulonglong)(uVar19 != 0) & param_5),param_9);
            puVar17 = puVar15;
            if (-1 < iVar8) {
              *(undefined8 *)(puVar15 + -8) = 0x1c000dd2d;
              NpSetConnectedPipeState((ulonglong)(plVar3 + -0x24),local_res18,param_12);
              *(undefined8 *)(puVar15 + -8) = 0x1c000dd3a;
              ExReleasePushLockExclusiveEx(plVar3 + -0x1c,0);
              *param_1 = 0;
              param_1[2] = 1;
              param_1[3] = 0;
              return param_1;
            }
          }
          goto LAB_1c000df45;
        }
      }
    }
LAB_1c000dfa1:
    iVar8 = -0x3ffffff3;
    puVar17 = puVar18;
    goto LAB_1c000df45;
  }
LAB_1c000dc1f:
  uVar9 = PsGetThreadProcessId(param_9);
  puVar14 = (uint *)(plVar3 + 2);
  puVar13 = (uint *)(plVar3 + 8);
  for (puVar12 = *(uint **)puVar14; puVar12 != puVar14; puVar12 = *(uint **)puVar12) {
    if (*(longlong *)(puVar12 + 4) == 3) goto LAB_1c000dc51;
  }
  puVar12 = (uint *)0x0;
LAB_1c000dc51:
  if (puVar13 == (uint *)0x0) {
    param_10 = (uint *)ExAllocatePool2(0x100,0x28,0x7441704e);
    if (param_10 != (uint *)0x0) goto LAB_1c000dc5d;
  }
  else {
    param_10 = puVar13;
LAB_1c000dc5d:
    param_10[4] = 3;
    param_10[5] = 0;
    param_10[8] = uVar9;
    param_10[6] = 4;
    param_10[7] = 0;
    if (puVar12 != (uint *)0x0) {
      lVar10 = *(longlong *)puVar12;
      puVar17 = auStackY_a8;
      if (*(uint **)(lVar10 + 8) != puVar12) goto LAB_1c000deb1;
      plVar5 = *(longlong **)(puVar12 + 2);
      puVar17 = auStackY_a8;
      if ((uint *)*plVar5 != puVar12) goto LAB_1c000deb1;
      *plVar5 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar5;
      if (puVar12 != puVar13) {
        ExFreePoolWithTag(puVar12,0);
      }
    }
    puVar4 = (undefined8 *)plVar3[3];
    puVar17 = auStackY_a8;
    if ((uint *)*puVar4 != puVar14) goto LAB_1c000deb1;
    *(uint **)param_10 = puVar14;
    *(undefined8 **)(param_10 + 2) = puVar4;
    *puVar4 = param_10;
    plVar3[3] = (longlong)param_10;
    uVar9 = PsGetThreadSessionId(param_9);
    puVar13 = *(uint **)puVar14;
    param_10 = (uint *)(plVar3 + 0xd);
    param_6 = (uint *)CONCAT44(param_6._4_4_,uVar9);
    for (; puVar13 != puVar14; puVar13 = *(uint **)puVar13) {
      if (*(longlong *)(puVar13 + 4) == 4) goto LAB_1c000dcc2;
    }
    puVar13 = (uint *)0x0;
LAB_1c000dcc2:
    if (param_10 != (uint *)0x0) {
LAB_1c000dcce:
      param_10[4] = 4;
      param_10[5] = 0;
      param_10[8] = uVar9;
      param_10[6] = 4;
      param_10[7] = 0;
      puVar15 = auStackY_a8;
      do {
        puVar17 = puVar15;
        if (puVar13 == (uint *)0x0) {
LAB_1c000dce2:
          plVar5 = (longlong *)plVar3[3];
          if ((longlong *)*plVar5 == plVar3 + 2) {
            *(longlong **)param_10 = plVar3 + 2;
            *(longlong **)(param_10 + 2) = plVar5;
            *plVar5 = (longlong)param_10;
            plVar3[3] = (longlong)param_10;
            goto LAB_1c000dcfd;
          }
        }
        else {
          lVar10 = *(longlong *)puVar13;
          if ((*(uint **)(lVar10 + 8) == puVar13) &&
             (plVar5 = *(longlong **)(puVar13 + 2), (uint *)*plVar5 == puVar13)) {
            *plVar5 = lVar10;
            *(longlong **)(lVar10 + 8) = plVar5;
            if (puVar13 != (uint *)(plVar3 + 0xd)) {
              *(undefined8 *)(puVar15 + -8) = 0x1c000e0a9;
              ExFreePoolWithTag(puVar13,0);
            }
            goto LAB_1c000dce2;
          }
        }
LAB_1c000deb1:
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar16 = puVar17 + 8;
LAB_1c000deb8:
        puVar18 = puVar16;
        if (*(ushort *)((longlong)param_10 + 6) < 8) goto LAB_1c000dfa1;
        param_10 = (uint *)(plVar3 + 0xd);
        for (puVar13 = (uint *)plVar3[2]; puVar13 != (uint *)(plVar3 + 2);
            puVar13 = *(uint **)puVar13) {
          if (*(longlong *)(puVar13 + 4) == 4) goto LAB_1c000ded8;
        }
        puVar13 = (uint *)0x0;
LAB_1c000ded8:
        if (param_10 == (uint *)0x0) {
          *(undefined8 *)(puVar16 + -8) = 0x1c000dfbf;
          param_10 = (uint *)ExAllocatePool2(0x100,0x28,0x7441704e);
          if (param_10 == (uint *)0x0) goto LAB_1c000dfd0;
        }
        param_10[4] = 4;
        param_10[5] = 0;
        *(longlong *)(param_10 + 8) = *(longlong *)(local_58 + 1 + (longlong)param_6);
        param_10[6] = 8;
        param_10[7] = 0;
        puVar15 = puVar16;
      } while( true );
    }
    param_10 = (uint *)ExAllocatePool2(0x100,0x28,0x7441704e);
    puVar18 = auStackY_a8;
    if (param_10 != (uint *)0x0) goto LAB_1c000dcce;
  }
LAB_1c000dfd0:
  iVar8 = -0x3fffff66;
  puVar17 = puVar18;
LAB_1c000df45:
  *(undefined8 *)(puVar17 + -8) = 0x1c000df51;
  NpRemoveAllAttributesFromList(plVar3 + 2);
  *(undefined8 *)(puVar17 + -8) = 0x1c000df5e;
  ExReleasePushLockExclusiveEx(plVar3 + -0x1c,0);
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = iVar8;
  return param_1;
}



===== NpInitializeSecurity @ 1c000e0bc =====

int NpInitializeSecurity(longlong param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  
  puVar1 = (undefined8 *)(param_1 + 0xc);
  if (param_2 == (undefined8 *)0x0) {
    *(undefined4 *)puVar1 = 0xc;
    *(undefined4 *)(param_1 + 0x10) = 2;
    *(undefined2 *)(param_1 + 0x14) = 0x101;
  }
  else {
    *puVar1 = *param_2;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 1);
  }
  if ((*(char *)(param_1 + 0x14) == '\0') && (*(longlong *)(param_1 + 0x108) != -1)) {
    lVar3 = ExAllocatePool2(0x101,0x48,0x7346704e);
    *(longlong *)(param_1 + 0x108) = lVar3;
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = SeCreateClientSecurity(param_3,puVar1,0,lVar3);
      if (iVar2 < 0) {
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x108),0);
        *(undefined8 *)(param_1 + 0x108) = 0;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== NpSetConnectedPipeState @ 1c000e19c =====

void NpSetConnectedPipeState(ulonglong param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_1 + 0x120);
  lVar1 = *plVar4;
  if (*(longlong **)(lVar1 + 8) != plVar4) goto LAB_1c000e243;
  plVar2 = *(longlong **)(param_1 + 0x128);
  if ((longlong *)*plVar2 != plVar4) goto LAB_1c000e243;
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xfc;
  *(undefined1 *)(param_1 + 8) = 3;
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  param_2[3] = *(longlong *)(param_1 + 0x28);
  param_2[6] = 1;
  *(uint *)(param_2 + 10) = *(uint *)(param_2 + 10) | 0x80;
  param_2[4] = param_1 | 1;
  *(longlong **)(param_1 + 0x30) = param_2;
  param_2 = (longlong *)(param_1 + 0x110);
LAB_1c000e1fb:
  do {
    plVar4 = (longlong *)*param_2;
    if (plVar4 == param_2) {
      return;
    }
    if (((longlong *)plVar4[1] == param_2) &&
       (lVar1 = *plVar4, (longlong *)*(longlong *)(lVar1 + 8) == plVar4)) {
      *param_2 = lVar1;
      *(longlong **)(lVar1 + 8) = param_2;
      LOCK();
      lVar1 = plVar4[-8];
      plVar4[-8] = 0;
      UNLOCK();
      if (lVar1 != 0) {
        *(undefined4 *)(plVar4 + -0xf) = 0;
        plVar2 = *(longlong **)(param_3 + 8);
        if (*plVar2 != param_3) goto LAB_1c000e243;
        *plVar4 = param_3;
        plVar4[1] = (longlong)plVar2;
        *plVar2 = (longlong)plVar4;
        *(longlong **)(param_3 + 8) = plVar4;
        goto LAB_1c000e1fb;
      }
    }
    else {
LAB_1c000e243:
      plVar4 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)();
    }
    *(longlong **)((longlong)plVar4 + 8) = plVar4;
    *plVar4 = (longlong)plVar4;
  } while( true );
}



===== NpFsdFlushBuffers @ 1c000e260 =====

int NpFsdFlushBuffers(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  KeEnterCriticalRegion();
  iVar1 = NpCommonFlushBuffers(param_1,param_2);
  KeLeaveCriticalRegion();
  if (iVar1 != 0x103) {
    *(int *)(param_2 + 0x30) = iVar1;
    IofCompleteRequest(param_2,2);
  }
  return iVar1;
}



===== NpCommonFlushBuffers @ 1c000e2c0 =====

int NpCommonFlushBuffers(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((**(short **)(lVar1 + 0x18) == 0x202) && ((*(byte *)(lVar1 + 0x20) & 1) != 0)) {
    uVar3 = *(ulonglong *)(lVar1 + 0x20) & 0xfffffffffffffffc;
    uVar4 = *(ulonglong *)(lVar1 + 0x20) >> 1;
    lVar5 = uVar3 + 0x48 + (ulonglong)(-(uint)((uVar4 & 1) != 0) & 0x60);
    ExAcquirePushLockExclusiveEx(uVar3 + 0x40,0);
    if ((*(byte *)(lVar1 + 0x20) & 1) == 0) {
      iVar2 = -0x3fffff50;
    }
    else {
      iVar2 = 0;
      if (*(int *)(lVar5 + 0x10) == 1) {
        iVar2 = NpAddDataQueueEntry((uint)uVar4 & 1,uVar3,lVar5,1,2,0,param_2,(void *)0x0,0);
      }
    }
    ExReleasePushLockExclusiveEx(uVar3 + 0x40,0);
  }
  else {
    iVar2 = -0x3fffff50;
  }
  return iVar2;
}



===== NpFsdCreate @ 1c000e3c0 =====

int NpFsdCreate(longlong param_1,longlong param_2)

{
  longlong ****pppplVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  short *psVar9;
  bool bVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  int *piVar13;
  uint uVar14;
  longlong lVar15;
  longlong ****pppplVar16;
  int iVar17;
  undefined1 uVar18;
  short sVar19;
  int local_res18 [2];
  short *local_res20;
  undefined7 in_stack_ffffffffffffff31;
  undefined8 in_stack_ffffffffffffff48;
  undefined8 local_90;
  undefined8 uStack_88;
  longlong local_80;
  short *psStack_78;
  longlong ****local_70;
  longlong ****pppplStack_68;
  short local_60 [16];
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_res18[0] = 0;
  local_70 = (longlong ****)0x0;
  pppplStack_68 = (longlong ****)0x0;
  plVar5 = *(longlong **)(lVar3 + 0x30);
  uVar18 = 1;
  bVar10 = false;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  local_60[5] = 0;
  local_60[6] = 0;
  local_60[7] = 0;
  local_80 = plVar5[0xb];
  psStack_78 = (short *)plVar5[0xc];
  lVar6 = plVar5[8];
  uVar14 = *(uint *)(lVar3 + 0x10) >> 0x18;
  puVar7 = *(uint **)(*(longlong *)(lVar3 + 8) + 8);
  uVar2 = *(uint *)(*(longlong *)(lVar3 + 8) + 0x10);
  if ((*(byte *)(lVar3 + 2) & 1) == 0) {
    uVar18 = *(undefined1 *)(param_2 + 0x40);
  }
  puVar8 = *(uint **)(param_2 + 0x18);
  sVar19 = 0;
  if (lVar6 != 0) {
    if ((*(byte *)(lVar6 + 0x20) & 1) != 0) {
      sVar19 = **(short **)(lVar6 + 0x18);
      goto LAB_1c000e4a3;
    }
LAB_1c000e461:
    iVar17 = -0x3fffffcd;
    goto LAB_1c000e466;
  }
LAB_1c000e4a3:
  if ((ushort)local_80 == 0) {
    if ((lVar6 == 0) || (sVar19 == 0x201)) {
      plVar5[4] = 1;
      plVar5[3] = lVar4;
LAB_1c000e526:
      LOCK();
      *(int *)(lVar4 + 0x78) = *(int *)(lVar4 + 0x78) + 1;
      UNLOCK();
      local_90 = 0;
      uStack_88 = 1;
    }
    else {
LAB_1c000e7ed:
      if (sVar19 != 0x206) goto LAB_1c000e54a;
LAB_1c000e4cd:
      uStack_88 = 0;
      puVar11 = (undefined8 *)ExAllocatePool2(0x101,0x18,0x4346704e);
      if (puVar11 != (undefined8 *)0x0) {
        *puVar11 = 0;
        puVar11[1] = 0;
        puVar11[2] = 0;
        *(undefined2 *)puVar11 = 0x205;
        plVar5[3] = lVar4 + 0x128;
        plVar5[4] = (ulonglong)puVar11 | 1;
        goto LAB_1c000e526;
      }
      local_90 = 0xc000009a;
    }
    *(undefined8 *)(param_2 + 0x30) = local_90;
    *(undefined8 *)(param_2 + 0x38) = uStack_88;
    iVar17 = *(int *)(param_2 + 0x30);
    goto LAB_1c000e466;
  }
  if ((ushort)local_80 == 2) {
    if ((*psStack_78 == 0x5c) && (lVar6 == 0)) goto LAB_1c000e4cd;
  }
  else if ((ushort)local_80 == 0) goto LAB_1c000e7ed;
LAB_1c000e54a:
  if ((*(uint *)(lVar3 + 0x10) & 1) != 0) {
    if (lVar6 == 0) {
      if (uVar14 == 1) {
        puVar11 = NpOpenNamedPipePrefix
                            ((undefined8 *)local_60,lVar4,(longlong)plVar5,(longlong)puVar7,uVar2,
                             uVar18);
        uVar12 = puVar11[1];
        *(undefined8 *)(param_2 + 0x30) = *puVar11;
        *(undefined8 *)(param_2 + 0x38) = uVar12;
        iVar17 = *(int *)(param_2 + 0x30);
        goto LAB_1c000e466;
      }
      if (uVar14 - 2 < 2) {
        piVar13 = NpCreateNamedPipePrefix
                            ((int *)local_60,lVar4,(longlong)plVar5,(longlong)puVar7,uVar2,uVar18,
                             uVar14);
        uVar12 = *(undefined8 *)(piVar13 + 2);
        *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)piVar13;
        *(undefined8 *)(param_2 + 0x38) = uVar12;
        iVar17 = *(int *)(param_2 + 0x30);
        goto LAB_1c000e466;
      }
    }
    goto LAB_1c000e461;
  }
  if (*(char *)(param_2 + 0x40) == '\x01') {
    lVar15 = *(longlong *)(puVar7 + 8);
    if (lVar15 == 0) {
      lVar15 = *(longlong *)(puVar7 + 0xc);
    }
  }
  else {
    lVar15 = 0;
  }
  uVar12 = NpTranslateAlias((uint *)&local_80,lVar15,local_res18);
  iVar17 = (int)uVar12;
  if (iVar17 < 0) goto LAB_1c000e466;
  pppplStack_68 = (longlong ****)&local_70;
  local_70 = (longlong ****)&local_70;
  if (lVar6 == 0) {
    if (((ushort)local_80 < 3) || (*psStack_78 != 0x5c)) goto LAB_1c000e461;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar4 + 0xc0,0);
    local_res20 = (short *)NpFindPrefix(lVar4,&local_80,'\x01',local_60);
    if (local_res20 != (short *)0x0) {
      if (*local_res20 == 0x202) {
        ExAcquirePushLockExclusiveEx(local_res20 + 0x40,0);
      }
      else {
        if (*local_res20 == 0x207) {
          bVar10 = true;
          goto LAB_1c000e627;
        }
        local_res20 = (short *)0x0;
      }
    }
    ExReleasePushLockExclusiveEx(lVar4 + 0xc0,0);
LAB_1c000e627:
    if (local_60[0] == 0) goto LAB_1c000e63a;
    iVar17 = (local_res20 == (short *)0x0) + 0xc0000033;
  }
  else {
    if (sVar19 == 0x206) {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(lVar4 + 0xc0,0);
      local_res20 = (short *)NpFindPrefix(lVar4,&local_80,'\x01',local_60);
      if (local_res20 != (short *)0x0) {
        if (*local_res20 == 0x202) {
          ExAcquirePushLockExclusiveEx(local_res20 + 0x40,0);
        }
        else {
          if (*local_res20 == 0x207) {
            bVar10 = true;
            goto LAB_1c000e627;
          }
          local_res20 = (short *)0x0;
        }
      }
      ExReleasePushLockExclusiveEx(lVar4 + 0xc0,0);
      goto LAB_1c000e627;
    }
    if ((sVar19 != 0x202) || ((ushort)local_80 != 0)) goto LAB_1c000e461;
    psVar9 = *(short **)((*(ulonglong *)(lVar6 + 0x20) & 0xfffffffffffffffc) + 0x28);
    local_res20 = psVar9;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(psVar9 + 0x40,0);
LAB_1c000e63a:
    if (local_res20 == (short *)0x0) {
      iVar17 = -0x3fffffcd;
    }
    else if (*local_res20 == 0x202) {
      if (*(int *)(local_res20 + 0x7c) == 0) {
        iVar17 = -0x3fffffcc;
      }
      else {
        piVar13 = NpCreateClientEnd((int *)local_60,(longlong)local_res20,plVar5,uVar2 & 0xfffffffb,
                                    **(ulonglong **)(lVar3 + 8),puVar7,
                                    *(char *)(param_2 + 0x40) == '\0',
                                    CONCAT71(in_stack_ffffffffffffff31,uVar18),
                                    *(undefined8 *)(param_2 + 0x98),puVar8,in_stack_ffffffffffffff48
                                    ,(longlong)&local_70);
        uVar12 = *(undefined8 *)(piVar13 + 2);
        *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)piVar13;
        *(undefined8 *)(param_2 + 0x38) = uVar12;
        iVar17 = *(int *)(param_2 + 0x30);
      }
    }
    else if (*local_res20 == 0x207) {
      uVar12 = NpOpenSymlink((longlong)local_res20,param_2);
      iVar17 = (int)uVar12;
    }
  }
  if (bVar10) {
    ExReleasePushLockExclusiveEx(lVar4 + 0xc0,0);
  }
  if ((local_res20 != (short *)0x0) && (*local_res20 == 0x202)) {
    ExReleasePushLockExclusiveEx(local_res20 + 0x40,0);
  }
  pppplVar16 = local_70;
  if ((longlong *****)local_70 != &local_70) {
    do {
      pppplVar1 = pppplVar16 + -0x15;
      pppplVar16 = (longlong ****)*pppplVar16;
      IofCompleteRequest(pppplVar1,2);
    } while ((longlong *****)pppplVar16 != &local_70);
  }
  KeLeaveCriticalRegion();
LAB_1c000e466:
  *(int *)(param_2 + 0x30) = iVar17;
  IofCompleteRequest(param_2,2);
  if (local_res18[0] != 0) {
    RtlFreeUnicodeString(&local_80);
  }
  return iVar17;
}



===== NpUnlinkProtectedPrefix @ 1c000e9ec =====

void NpUnlinkProtectedPrefix(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  short *psVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined8 uStack_30;
  undefined1 auStack_28 [32];
  
  puVar10 = auStack_28;
  puVar1 = (undefined8 *)(param_2 + 0xf8);
LAB_1c000ea15:
  puVar8 = (undefined8 *)*puVar1;
  puVar9 = puVar1;
LAB_1c000ea1b:
  if (puVar8 == puVar9) {
    if (puVar9 != puVar1) goto LAB_1c000ea15;
    puVar9 = (undefined8 *)0x0;
    if (*(short *)(param_2 + 0xa0) == 0) {
      return;
    }
    plVar2 = (longlong *)(param_2 + 0xe8);
    lVar5 = *plVar2;
    if ((*(longlong **)(lVar5 + 8) == plVar2) &&
       (plVar6 = *(longlong **)(param_2 + 0xf0), (longlong *)*plVar6 == plVar2)) {
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      *(undefined8 *)(puVar10 + -8) = 0x1c000ea65;
      RtlRemoveUnicodePrefix(param_1 + 0xd8,param_2 + 0xb0);
      *(undefined2 *)(param_2 + 0xa0) = 0;
      return;
    }
    pcVar7 = (code *)swi(0x29);
    puVar8 = (undefined8 *)(*pcVar7)(3);
    puVar10 = puVar10 + 8;
  }
  psVar3 = (short *)(puVar8 + -0x1d);
  if (*psVar3 == 0x203) {
    puVar4 = puVar8 + 2;
    puVar8 = (undefined8 *)*puVar4;
    if (puVar8 == puVar4) goto LAB_1c000eabd;
    puVar9 = puVar4;
  }
  else {
LAB_1c000eabd:
    *(undefined8 *)(puVar10 + -8) = 0x1c000eacb;
    NpUnlinkNode(psVar3,param_1,param_3);
    puVar8 = (undefined8 *)*puVar9;
  }
  goto LAB_1c000ea1b;
}



===== NpFindPrefix @ 1c000eae0 =====

longlong NpFindPrefix(longlong param_1,undefined8 *param_2,char param_3,short *param_4)

{
  longlong lVar1;
  short sVar2;
  ushort uVar3;
  ushort local_18;
  short sStack_16;
  undefined4 uStack_14;
  short *psStack_10;
  
  uStack_14 = *(undefined4 *)((longlong)param_2 + 4);
  psStack_10 = (short *)param_2[1];
  local_18 = (ushort)*(undefined4 *)param_2;
  sStack_16 = (short)((uint)*(undefined4 *)param_2 >> 0x10);
  if ((1 < local_18) && (*psStack_10 == 0x5c)) {
    sStack_16 = (short)((ulonglong)*param_2 >> 0x10) + -2;
    local_18 = local_18 - 2;
    psStack_10 = psStack_10 + 1;
  }
  if (param_3 == '\0') {
    uVar3 = local_18;
  }
  else {
    uVar3 = 0;
  }
  lVar1 = RtlFindUnicodePrefix(param_1 + 0xd8,&local_18,uVar3);
  if (lVar1 == 0) {
    *(ulonglong *)param_4 = CONCAT44(uStack_14,CONCAT22(sStack_16,local_18));
    *(short **)(param_4 + 4) = psStack_10;
    lVar1 = 0;
  }
  else {
    uVar3 = *(ushort *)(lVar1 + -0x10);
    lVar1 = lVar1 + -0xb0;
    sVar2 = local_18 - uVar3;
    *param_4 = sVar2;
    param_4[1] = sVar2;
    *(short **)(param_4 + 4) = psStack_10 + (uVar3 >> 1);
  }
  return lVar1;
}



===== NpFsdCreateNamedPipe @ 1c000eba0 =====

int NpFsdCreateNamedPipe(longlong param_1,longlong param_2)

{
  undefined8 ****ppppuVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  undefined8 uVar11;
  short *psVar12;
  int *piVar13;
  ushort uVar14;
  longlong lVar15;
  uint uVar16;
  undefined8 ****ppppuVar17;
  longlong lVar18;
  undefined1 local_res10;
  int local_res20 [2];
  undefined8 in_stack_ffffffffffffff38;
  int local_b4 [3];
  undefined8 local_a8;
  short *psStack_a0;
  undefined8 ****local_98;
  undefined8 ****local_90;
  undefined8 local_88;
  short *psStack_80;
  undefined4 local_78 [2];
  longlong local_70;
  uint *local_68;
  longlong local_60;
  short *local_58;
  undefined8 local_50;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  bVar8 = false;
  local_78[0] = 0;
  local_70 = 0;
  bVar9 = false;
  local_b4[0] = 0;
  local_58 = (short *)0x0;
  local_90 = &local_98;
  local_98 = &local_98;
  local_60 = *(longlong *)(lVar2 + 0x30);
  local_a8 = *(undefined8 *)(local_60 + 0x58);
  psStack_a0 = *(short **)(local_60 + 0x60);
  lVar18 = *(longlong *)(local_60 + 0x40);
  local_68 = *(uint **)(lVar2 + 0x20);
  uVar16 = *(uint *)(lVar2 + 0x10);
  local_50 = IoGetRequestorProcess(param_2);
  if ((*(byte *)(lVar2 + 2) & 1) == 0) {
    local_res10 = *(undefined1 *)(param_2 + 0x40);
  }
  else {
    local_res10 = 1;
  }
  uVar16 = uVar16 >> 0x18;
  psVar12 = (short *)0x0;
  local_88 = 0;
  psStack_80 = (short *)0x0;
  lVar4 = *(longlong *)(*(longlong *)(lVar2 + 8) + 8);
  KeEnterCriticalRegion();
  if (*(char *)(param_2 + 0x40) == '\x01') {
    lVar15 = *(longlong *)(lVar4 + 0x20);
    if (lVar15 == 0) {
      lVar15 = *(longlong *)(lVar4 + 0x30);
    }
  }
  else {
    lVar15 = 0;
  }
  uVar11 = NpTranslateAlias((uint *)&local_a8,lVar15,local_b4);
  local_res20[0] = (int)uVar11;
  if (local_res20[0] < 0) goto LAB_1c000ecae;
  if (lVar18 != 0) {
    if ((**(short **)(lVar18 + 0x18) == 0x206) && ((*(byte *)(lVar18 + 0x20) & 1) != 0)) {
      if ((ushort)local_a8 == 0) goto LAB_1c000ed59;
      if ((1 < (ushort)local_a8) && (*psStack_a0 != 0x5c)) goto LAB_1c000ed0d;
    }
    local_res20[0] = -0x3fffffcd;
    goto LAB_1c000ecae;
  }
  if (((ushort)local_a8 < 3) || (*psStack_a0 != 0x5c)) {
LAB_1c000ef81:
    local_res20[0] = -0x3fffffcd;
LAB_1c000ef86:
    if (bVar9) {
      ExReleasePushLockExclusiveEx(psVar12 + 0x40,0);
    }
  }
  else {
LAB_1c000ed0d:
    ExAcquirePushLockExclusiveEx(lVar3 + 0xc0);
    bVar8 = true;
    psVar12 = (short *)NpFindPrefix(lVar3,&local_a8,'\x01',(short *)&local_88);
    if ((psVar12 != (short *)0x0) && (*psVar12 == 0x202)) {
      if ((ushort)local_88 != 0) goto LAB_1c000ef81;
      ExAcquirePushLockExclusiveEx(psVar12 + 0x40);
      bVar9 = true;
      ExReleasePushLockExclusiveEx(lVar3 + 0xc0,0);
      bVar8 = false;
      piVar13 = NpCreateExistingNamedPipe
                          ((int *)&local_88,lVar3,(longlong)psVar12,local_60,
                           *(uint *)(*(longlong *)(lVar2 + 8) + 0x10),lVar4,local_res10,uVar16,
                           *(short *)(lVar2 + 0x1a),(longlong)local_68,in_stack_ffffffffffffff38,
                           (longlong)&local_98);
      iVar5 = piVar13[1];
      iVar6 = piVar13[2];
      iVar7 = piVar13[3];
      *(int *)(param_2 + 0x30) = *piVar13;
      *(int *)(param_2 + 0x34) = iVar5;
      *(int *)(param_2 + 0x38) = iVar6;
      *(int *)(param_2 + 0x3c) = iVar7;
      local_res20[0] = *(int *)(param_2 + 0x30);
      goto LAB_1c000ef86;
    }
LAB_1c000ed59:
    if ((ushort)local_88 == 0) {
LAB_1c000ee45:
      if (psVar12 == (short *)0x0) {
LAB_1c000ee4e:
        local_88 = local_a8;
        psStack_80 = psStack_a0;
        local_res20[0] =
             NpCreateNewNamedPipe
                       (lVar3,(longlong)local_58,local_60,(ushort *)&local_88,
                        *(uint *)(*(longlong *)(lVar2 + 8) + 0x10),lVar4,uVar16,
                        *(short *)(lVar2 + 0x1a),local_68,local_50,(longlong)&local_98,
                        (int *)(param_2 + 0x30));
      }
      else {
        if (*psVar12 != 0x207) goto LAB_1c000effe;
        uVar11 = NpOpenSymlink((longlong)psVar12,param_2);
        local_res20[0] = (int)uVar11;
      }
    }
    else {
      uVar14 = (ushort)local_88;
      if (*psStack_80 == 0x5c) {
        uVar14 = (ushort)local_88 - 2;
      }
      if (uVar14 == 0) goto LAB_1c000ee45;
      if (psVar12 == (short *)0x0) {
        lVar18 = *(longlong *)(lVar3 + 0x88);
LAB_1c000ed8d:
        if (lVar18 != 0) {
          uVar11 = IoGetFileObjectGenericMapping();
          cVar10 = SeAccessCheck(lVar18,lVar4 + 0x20,0,2,0,&local_70,uVar11,local_res10,local_78,
                                 local_res20);
          if (local_70 != 0) {
            SeFreePrivileges();
          }
          if (cVar10 != '\0') goto LAB_1c000ee4e;
          goto LAB_1c000edff;
        }
        goto LAB_1c000ee4e;
      }
      if (*psVar12 == 0x203) {
        lVar18 = *(longlong *)(psVar12 + 0x4c);
        local_58 = psVar12;
        goto LAB_1c000ed8d;
      }
LAB_1c000effe:
      local_res20[0] = -0x3fffffcd;
    }
  }
LAB_1c000edff:
  if (bVar8) {
    ExReleasePushLockExclusiveEx(lVar3 + 0xc0,0);
  }
  ppppuVar17 = local_98;
  while ((undefined8 *****)ppppuVar17 != &local_98) {
    ppppuVar1 = ppppuVar17 + -0x15;
    ppppuVar17 = (undefined8 ****)*ppppuVar17;
    IofCompleteRequest(ppppuVar1,2);
  }
LAB_1c000ecae:
  KeLeaveCriticalRegion();
  *(int *)(param_2 + 0x30) = local_res20[0];
  IofCompleteRequest(param_2,2);
  if (local_b4[0] != 0) {
    RtlFreeUnicodeString(&local_a8);
  }
  return local_res20[0];
}



===== NpFsdCleanup @ 1c000f040 =====

ulonglong NpFsdCleanup(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  KeEnterCriticalRegion();
  uVar1 = NpCommonCleanup(param_1,param_2);
  KeLeaveCriticalRegion();
  *(int *)(param_2 + 0x30) = (int)uVar1;
  IofCompleteRequest(param_2,2);
  return uVar1 & 0xffffffff;
}



===== NpCommonCleanup @ 1c000f0a0 =====

undefined8 NpCommonCleanup(longlong param_1,longlong param_2)

{
  int *piVar1;
  short sVar2;
  uint uVar3;
  longlong *****ppppplVar4;
  longlong ****pppplVar5;
  longlong ***ppplVar6;
  longlong ***ppplVar7;
  code *pcVar8;
  void *_Src;
  longlong lVar9;
  char cVar10;
  longlong ****pppplVar11;
  uint uVar12;
  undefined4 uVar13;
  longlong *****ppppplVar14;
  longlong *****ppppplVar15;
  longlong *****ppppplVar16;
  ulonglong uVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  longlong *****ppppplVar21;
  longlong unaff_R13;
  ulonglong uVar22;
  longlong *****ppppplVar23;
  longlong unaff_R15;
  int local_res10;
  int local_res18;
  undefined1 auStack_b8 [48];
  longlong *****local_88;
  longlong local_80;
  longlong ****local_78;
  longlong *****local_70;
  longlong *****local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  
  puVar18 = auStack_b8;
  ppppplVar16 = *(longlong ******)(param_1 + 0x40);
  local_68 = (longlong *****)&local_70;
  local_70 = (longlong *****)&local_70;
  ppppplVar21 = *(longlong ******)(*(longlong *)(param_2 + 0xb8) + 0x30);
  pppplVar11 = ppppplVar21[3];
  sVar2 = *(short *)pppplVar11;
  if (sVar2 == 0x206) {
    ppppplVar23 = ppppplVar16 + 0x15;
    ppppplVar15 = (longlong *****)((ulonglong)ppppplVar21[4] & 0xfffffffffffffffe);
    ExAcquirePushLockExclusiveEx(ppppplVar23,0);
    ppppplVar16 = ppppplVar16 + 0x16;
    ppppplVar4 = (longlong *****)*ppppplVar16;
    while (ppppplVar4 != ppppplVar16) {
      if ((ppppplVar15 == (longlong *****)0x0) ||
         (ppppplVar14 = ppppplVar4, ppppplVar15 == (longlong *****)ppppplVar4[-6])) {
        ppppplVar14 = (longlong *****)ppppplVar4[1];
        pppplVar11 = *ppppplVar14;
        ppplVar6 = *pppplVar11;
        puVar20 = auStack_b8;
        if (((longlong ****)ppplVar6[1] != pppplVar11) ||
           (ppplVar7 = pppplVar11[1], puVar20 = auStack_b8, (longlong ****)*ppplVar7 != pppplVar11))
        {
LAB_1c000f56c:
          pcVar8 = (code *)swi(0x29);
          (*pcVar8)(3);
          puVar20 = puVar20 + 8;
          do {
            uVar13 = 0xc0000023;
LAB_1c000f370:
            do {
              LOCK();
              pppplVar11 = ppppplVar21[-8];
              ppppplVar21[-8] = (longlong ****)0x0;
              UNLOCK();
              if (pppplVar11 == (longlong ****)0x0) {
                ppppplVar21[1] = (longlong ****)ppppplVar21;
                *ppppplVar21 = (longlong ****)ppppplVar21;
              }
              else {
                *(undefined4 *)(ppppplVar21 + -0xf) = uVar13;
                if ((longlong ******)*local_68 != &local_70) goto LAB_1c000f56c;
                ppppplVar21[1] = (longlong ****)local_68;
                *ppppplVar21 = (longlong ****)&local_70;
                *local_68 = (longlong ****)ppppplVar21;
                local_68 = ppppplVar21;
              }
              do {
                ppppplVar21 = ppppplVar23;
                local_88 = (longlong *****)*ppppplVar21;
                puVar18 = puVar20;
                if (ppppplVar21 == ppppplVar15) goto LAB_1c000f3b9;
LAB_1c000f291:
                uVar13 = 0;
                local_78 = ppppplVar21[2];
                ppppplVar23 = local_88;
              } while (((ulonglong)local_78[2] & 0x10) == 0);
              pppplVar11 = *ppppplVar21;
              if (((longlong *****)pppplVar11[1] != ppppplVar21) ||
                 (pppplVar5 = ppppplVar21[1], (longlong *****)*pppplVar5 != ppppplVar21))
              goto LAB_1c000f56c;
              *pppplVar5 = (longlong ***)pppplVar11;
              pppplVar11[1] = (longlong ***)pppplVar5;
            } while (*(uint *)(local_78 + 1) == 0);
            uVar12 = (local_60 >> 0x10) + 0x10;
          } while (*(uint *)(local_78 + 1) < uVar12);
          pppplVar11 = ppppplVar21[-0x12];
          if (pppplVar11 == (longlong ****)0x0) {
            pppplVar11 = ppppplVar21[-0x14];
            if (pppplVar11 == (longlong ****)0x0) goto LAB_1c000f370;
            if ((*(byte *)((longlong)pppplVar11 + 10) & 5) == 0) {
              *(undefined4 *)(puVar20 + 0x28) = 0x40000010;
              *(undefined4 *)(puVar20 + 0x20) = 0;
              *(undefined8 *)(puVar20 + -8) = 0x1c000f321;
              pppplVar11 = (longlong ****)MmMapLockedPagesSpecifyCache(pppplVar11,0,1,0);
            }
            else {
              pppplVar11 = (longlong ****)pppplVar11[3];
            }
            ppppplVar23 = local_88;
            if (pppplVar11 == (longlong ****)0x0) goto LAB_1c000f370;
          }
          uVar3 = *(uint *)(local_78 + 1);
          *(undefined8 *)(puVar20 + -8) = 0x1c000f340;
          memset(pppplVar11,0,(ulonglong)uVar3);
          uVar17 = (ulonglong)local_60._2_2_;
          _Src = (void *)CONCAT44(uStack_54,uStack_58);
          *(uint *)(pppplVar11 + 1) = (uint)local_60._2_2_;
          *(undefined8 *)(puVar20 + -8) = 0x1c000f35a;
          memcpy((void *)((longlong)pppplVar11 + 0xc),_Src,uVar17);
          *(undefined4 *)((longlong)pppplVar11 + 4) = 3;
          ppppplVar21[-0xe] = (longlong ****)(ulonglong)uVar12;
          ppppplVar23 = local_88;
          goto LAB_1c000f370;
        }
        *ppplVar7 = (longlong **)ppplVar6;
        ppplVar6[1] = (longlong **)ppplVar7;
        LOCK();
        pppplVar11 = ppppplVar4[-8];
        ppppplVar4[-8] = (longlong ****)0x0;
        UNLOCK();
        if (pppplVar11 == (longlong ****)0x0) {
          ppppplVar4[1] = (longlong ****)ppppplVar4;
          *ppppplVar4 = (longlong ****)ppppplVar4;
        }
        else {
          *(undefined4 *)(ppppplVar4 + -0xf) = 0x10b;
          puVar20 = auStack_b8;
          if ((longlong ******)*local_68 != &local_70) goto LAB_1c000f56c;
          ppppplVar4[1] = (longlong ****)local_68;
          *ppppplVar4 = (longlong ****)&local_70;
          *local_68 = (longlong ****)ppppplVar4;
          local_68 = ppppplVar4;
        }
      }
      ppppplVar4 = (longlong *****)*ppppplVar14;
    }
    ExReleasePushLockExclusiveEx(ppppplVar23,0);
    ExAcquirePushLockExclusiveEx(ppppplVar15 + 1,0);
    ppppplVar21[4] = (longlong ****)((ulonglong)ppppplVar21[4] & 0xfffffffffffffffe);
    ppppplVar15 = ppppplVar15 + 1;
  }
  else {
    if (sVar2 == 0x201) {
      ppppplVar21[4] = (longlong ****)((ulonglong)ppppplVar21[4] & 0xfffffffffffffffe);
      goto LAB_1c000f153;
    }
    if (sVar2 == 0x202) {
      local_80 = 0;
      uVar22 = (ulonglong)ppppplVar21[4] & 0xfffffffffffffffc;
      uVar17 = (ulonglong)ppppplVar21[4] >> 1;
      local_res18 = 0;
      local_res10 = 0;
      unaff_R15 = *(longlong *)(uVar22 + 0x28);
      if ((uVar17 & 1) != 0) {
        ExAcquirePushLockExclusiveEx(unaff_R15 + 0x80,0);
        local_res18 = 1;
        if ((*(short *)(unaff_R15 + 0xa0) != 0) && (*(int *)(unaff_R15 + 0xf8) == 1)) {
          cVar10 = ExTryAcquirePushLockExclusiveEx(ppppplVar16 + 0x18,0);
          if (cVar10 == '\0') {
            ExReleasePushLockExclusiveEx(unaff_R15 + 0x80,0);
            ExAcquirePushLockExclusiveEx(ppppplVar16 + 0x18,0);
            local_res10 = 1;
            ExAcquirePushLockExclusiveEx(unaff_R15 + 0x80,0);
            local_res18 = 1;
            if (1 < *(uint *)(unaff_R15 + 0xf8)) {
              ExReleasePushLockExclusiveEx(ppppplVar16 + 0x18,0);
              local_res10 = 0;
            }
          }
          else {
            local_res10 = 1;
          }
        }
      }
      puVar20 = auStack_b8;
      puVar18 = auStack_b8;
      unaff_R13 = uVar22 + 0x40;
      ExAcquirePushLockExclusiveEx(unaff_R13,0);
      if (((ulonglong)ppppplVar21[4] & 1) != 0) {
        NpSetClosingPipeState(uVar22,(uint)uVar17 & 1,(longlong)&local_70,&local_80);
      }
      if ((uVar17 & 1) == 0) {
        puVar19 = auStack_b8;
        if (*(longlong *)(uVar22 + 0x1c0) != 0) {
          local_60 = *(uint *)(unaff_R15 + 0xa0);
          uStack_5c = *(undefined4 *)(unaff_R15 + 0xa4);
          uStack_58 = *(undefined4 *)(unaff_R15 + 0xa8);
          uStack_54 = *(undefined4 *)(unaff_R15 + 0xac);
          ppppplVar15 = ppppplVar16 + 0x16;
          puVar19 = auStack_b8;
          if ((longlong *****)*ppppplVar15 != ppppplVar15) {
            ExAcquirePushLockExclusiveEx(ppppplVar16 + 0x15,0);
            ppppplVar21 = (longlong *****)*ppppplVar15;
            local_88 = (longlong *****)*ppppplVar21;
            if (ppppplVar21 != ppppplVar15) goto LAB_1c000f291;
LAB_1c000f3b9:
            *(undefined8 *)(puVar18 + -8) = 0x1c000f3c9;
            ExReleasePushLockExclusiveEx(ppppplVar16 + 0x15,0);
            puVar19 = puVar18;
          }
        }
      }
      else {
        NpUnlinkCcb((longlong)ppppplVar16,uVar22,(longlong)&local_70);
        piVar1 = (int *)(unaff_R15 + 0xf8);
        *piVar1 = *piVar1 + -1;
        puVar19 = auStack_b8;
        if (*piVar1 == 0) {
          NpUnlinkFcb((longlong)ppppplVar16,unaff_R15,(longlong)&local_70);
          puVar19 = auStack_b8;
        }
      }
      if (local_res10 != 0) {
        *(undefined8 *)(puVar19 + -8) = 0x1c000f40e;
        ExReleasePushLockExclusiveEx(ppppplVar16 + 0x18,0);
      }
      *(undefined8 *)(puVar19 + -8) = 0x1c000f41f;
      ExReleasePushLockExclusiveEx(unaff_R13,0);
      if (local_res18 != 0) {
        *(undefined8 *)(puVar19 + -8) = 0x1c000f43a;
        ExReleasePushLockExclusiveEx(unaff_R15 + 0x80,0);
      }
      lVar9 = local_80;
      *(undefined8 *)(puVar19 + -8) = 0x1c000f448;
      NpFreeClientSecurityContext(lVar9);
      puVar18 = puVar19;
      goto LAB_1c000f153;
    }
    puVar18 = auStack_b8;
    if (sVar2 != 0x203) goto LAB_1c000f153;
    ExAcquirePushLockExclusiveEx(ppppplVar16 + 0x18,0);
    pppplVar5 = pppplVar11 + 0xf;
    *(int *)pppplVar5 = *(int *)pppplVar5 + -1;
    if (*(int *)pppplVar5 == 0) {
      NpUnlinkProtectedPrefix((longlong)ppppplVar16,(longlong)pppplVar11,(longlong)&local_70);
    }
    ppppplVar15 = ppppplVar16 + 0x18;
  }
  ExReleasePushLockExclusiveEx(ppppplVar15,0);
  puVar18 = auStack_b8;
LAB_1c000f153:
  ppppplVar16 = local_70;
  if ((longlong ******)local_70 != &local_70) {
    do {
      ppppplVar21 = ppppplVar16 + -0x15;
      ppppplVar16 = (longlong *****)*ppppplVar16;
      *(undefined8 *)(puVar18 + -8) = 0x1c000f173;
      IofCompleteRequest(ppppplVar21,2);
    } while ((longlong ******)ppppplVar16 != &local_70);
  }
  return 0;
}



===== NpFsdFileSystemControl @ 1c000f5f0 =====

ulonglong NpFsdFileSystemControl(ulonglong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  KeEnterCriticalRegion();
  uVar1 = NpCommonFileSystemControl(param_1,param_2);
  KeLeaveCriticalRegion();
  if ((int)uVar1 != 0x103) {
    *(int *)(param_2 + 0x30) = (int)uVar1;
    IofCompleteRequest(param_2,2);
  }
  return uVar1 & 0xffffffff;
}



===== NpCommonFileSystemControl @ 1c000f660 =====

ulonglong NpCommonFileSystemControl(ulonglong param_1,longlong param_2)

{
  longlong ******pppppplVar1;
  undefined8 *_Dst;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  void *pvVar6;
  longlong lVar7;
  longlong ******pppppplVar8;
  ulonglong uVar9;
  size_t _Size;
  char cVar10;
  undefined8 *puVar11;
  ulonglong local_res10;
  void *local_res18;
  undefined8 in_stack_ffffffffffffffa8;
  longlong ******local_38;
  longlong ******local_30;
  
  local_30 = (longlong ******)&local_38;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  cVar10 = '\0';
  local_38 = (longlong ******)&local_38;
  uVar2 = *(uint *)(lVar4 + 0x18);
  if (uVar2 == 0x110024) {
    uVar2 = *(uint *)(lVar4 + 8);
    lVar4 = *(longlong *)(lVar4 + 0x30);
    if (0xf < uVar2) {
      _Dst = *(undefined8 **)(param_2 + 0x18);
      _Size = 0x38;
      if (uVar2 < 0x38) {
        _Size = 0x10;
      }
      memset(_Dst,0,_Size);
      puVar11 = _Dst + 2;
      pvVar6 = (void *)((longlong)_Dst + 0x12);
      if (uVar2 < 0x38) {
        puVar11 = (undefined8 *)0x0;
        pvVar6 = (void *)0x0;
      }
      uVar3 = NpQueryClientProcessImpl
                        (lVar4,_Dst,puVar11,_Dst + 1,in_stack_ffffffffffffffa8,pvVar6,
                         (undefined2 *)puVar11);
      uVar3 = uVar3 & 0xffffffff;
      *(size_t *)(param_2 + 0x38) = _Size;
      goto LAB_1c000f6d6;
    }
LAB_1c000fa05:
    uVar3 = 0xc000000d;
    goto LAB_1c000f6d6;
  }
  if (uVar2 == 0x11400c) {
    uVar2 = NpPeek(param_1,param_2,(longlong)&local_38);
    uVar3 = (ulonglong)uVar2;
    goto LAB_1c000f6d6;
  }
  if (uVar2 == 0x110004) {
    lVar4 = *(longlong *)(lVar4 + 0x30);
    if ((**(short **)(lVar4 + 0x18) == 0x202) && ((*(byte *)(lVar4 + 0x20) & 1) != 0)) {
      if (((byte)*(ulonglong *)(lVar4 + 0x20) >> 1 & 1) == 0) {
        uVar3 = 0xc00000af;
        goto LAB_1c000f6d6;
      }
      uVar9 = *(ulonglong *)(lVar4 + 0x20) & 0xfffffffffffffffc;
      ExAcquirePushLockExclusiveEx(*(longlong *)(uVar9 + 0x28) + 0x80,0);
      lVar7 = uVar9 + 0x40;
      ExAcquirePushLockExclusiveEx(lVar7,0);
      if ((*(byte *)(lVar4 + 0x20) & 1) != 0) {
        uVar3 = NpSetDisconnectedPipeState(uVar9,(longlong)&local_38);
        uVar3 = uVar3 & 0xffffffff;
        ExReleasePushLockExclusiveEx(*(longlong *)(uVar9 + 0x28) + 0x80,0);
        lVar4 = NpClearSecurity(uVar9);
        ExReleasePushLockExclusiveEx(lVar7,0);
        NpFreeClientSecurityContext(lVar4);
        goto LAB_1c000f6d6;
      }
      ExReleasePushLockExclusiveEx(lVar7,0);
      ExReleasePushLockExclusiveEx(*(longlong *)(uVar9 + 0x28) + 0x80,0);
    }
    uVar3 = 0xc00000b0;
    goto LAB_1c000f6d6;
  }
  if (uVar2 == 0x110018) {
    uVar3 = NpWaitForNamedPipe(param_1,param_2);
    uVar3 = uVar3 & 0xffffffff;
    goto LAB_1c000f6d6;
  }
  if (uVar2 < 0x112ffd) {
    if (uVar2 != 0x112ffc) {
      if (0x4c < uVar2 - 0x110008) {
LAB_1c000f709:
        return 0xc00000bb;
      }
      lVar7 = (ulonglong)
              (&switchD_1c000f810::switchdataD_1c0004480)
              [(&switchD_1c000f810::switchdataD_1c00044b4)[uVar2 - 0x110008]] + 0x1c0000000;
      switch(uVar2) {
      case 0x110008:
        uVar3 = NpListen(param_1,param_2,(longlong)&local_38);
        uVar3 = uVar3 & 0xffffffff;
        break;
      default:
        goto LAB_1c000f709;
      case 0x11001c:
        uVar2 = NpImpersonate(lVar7,param_2,0);
        uVar3 = (ulonglong)uVar2;
        break;
      case 0x110028:
        uVar3 = NpGetAttribute(param_2,0);
        uVar3 = uVar3 & 0xffffffff;
        break;
      case 0x11002c:
        uVar3 = NpSetAttribute(param_2,0);
        uVar3 = uVar3 & 0xffffffff;
        break;
      case 0x110030:
        uVar2 = *(uint *)(lVar4 + 8);
        local_res18 = (void *)0x0;
        local_res10 = 0;
        if (((*(int *)(lVar4 + 0x10) != 0) &&
            (pvVar6 = *(void **)(param_2 + 0x18),
            *(char *)((ulonglong)(*(int *)(lVar4 + 0x10) - 1) + (longlong)pvVar6) == '\0')) &&
           (lVar4 = *(longlong *)(lVar4 + 0x30), **(short **)(lVar4 + 0x18) == 0x202)) {
          uVar3 = *(ulonglong *)(lVar4 + 0x20);
          uVar9 = uVar3 & 0xfffffffffffffffc;
          lVar7 = uVar9 + 0x40;
          ExAcquirePushLockSharedEx(lVar7,0);
          if (((uVar3 >> 1 & 1) == 0) && ((*(byte *)(lVar4 + 0x20) & 1) == 0)) {
            uVar3 = 0xc00000b0;
          }
          else {
            uVar5 = NpGetAttributeFromList
                              ((undefined8 *)(uVar9 + 0x130),(ulonglong)pvVar6,
                               (longlong *)&local_res18,&local_res10);
            uVar9 = local_res10;
            uVar3 = uVar5 & 0xffffffff;
            if (-1 < (int)uVar5) {
              if (uVar2 < local_res10) {
                uVar3 = 0xc0000023;
              }
              else {
                memcpy(pvVar6,local_res18,local_res10);
                *(ulonglong *)(param_2 + 0x38) = uVar9;
              }
            }
          }
          ExReleasePushLockSharedEx(lVar7,0);
          break;
        }
        goto LAB_1c000fa05;
      case 0x110034:
        uVar3 = NpSetAttribute(param_2,1);
        uVar3 = uVar3 & 0xffffffff;
        break;
      case 0x110038:
        uVar3 = NpGetAttribute(param_2,2);
        uVar3 = uVar3 & 0xffffffff;
        break;
      case 0x11003c:
        uVar3 = NpSetAttribute(param_2,2);
        uVar3 = uVar3 & 0xffffffff;
        break;
      case 0x110044:
        uVar2 = NpImpersonate(lVar7,param_2,1);
        uVar3 = (ulonglong)uVar2;
        break;
      case 0x11004c:
        uVar3 = NpCreateSymlinkFsCtl(param_1,param_2);
        uVar3 = uVar3 & 0xffffffff;
        break;
      case 0x110050:
        uVar2 = NpDeleteSymlinkFsCtl(param_1,param_2);
        uVar3 = (ulonglong)uVar2;
        break;
      case 0x110054:
        uVar3 = NpQueryClientProcess(lVar7,param_2);
        uVar3 = uVar3 & 0xffffffff;
      }
      goto LAB_1c000f6d6;
    }
  }
  else {
    if (uVar2 < 0x118049) {
      if (uVar2 == 0x118048) {
        uVar3 = NpSiloArrivalFsCtl(param_2);
        uVar3 = uVar3 & 0xffffffff;
        goto LAB_1c000f6d6;
      }
      if (uVar2 == 0x113000) {
LAB_1c000fa1e:
        uVar3 = NpEnumEvents(param_2);
        uVar3 = uVar3 & 0xffffffff;
      }
      else {
        if (uVar2 != 0x115ff4) {
          if (uVar2 != 0x116000) {
            if (uVar2 != 0x117000) {
              if (uVar2 != 0x118040) {
                return 0xc00000bb;
              }
              uVar2 = NpCommonFlushBuffers(param_1,param_2);
              uVar3 = (ulonglong)uVar2;
              goto LAB_1c000f6d6;
            }
            goto LAB_1c000fa1e;
          }
          cVar10 = '\x01';
        }
        uVar2 = NpInternalRead(param_1,param_2,cVar10,(longlong)&local_38);
        uVar3 = (ulonglong)uVar2;
      }
      goto LAB_1c000f6d6;
    }
    if (uVar2 == 0x11c017) {
      uVar2 = NpTransceive(param_1,param_2,(longlong)&local_38);
      uVar3 = (ulonglong)uVar2;
      goto LAB_1c000f6d6;
    }
    if (uVar2 != 0x11affc) {
      if (uVar2 == 0x11dfff) {
        uVar2 = NpInternalTransceive(param_1,param_2,(longlong)&local_38);
        uVar3 = (ulonglong)uVar2;
      }
      else {
        if (uVar2 != 0x119ff8) {
          return 0xc00000bb;
        }
        uVar2 = NpInternalWrite(param_1,param_2);
        uVar3 = (ulonglong)uVar2;
      }
      goto LAB_1c000f6d6;
    }
  }
  uVar3 = NpSelectEvents(param_2);
  uVar3 = uVar3 & 0xffffffff;
LAB_1c000f6d6:
  pppppplVar8 = local_38;
  if ((longlong *******)local_38 != &local_38) {
    do {
      pppppplVar1 = pppppplVar8 + -0x15;
      pppppplVar8 = (longlong ******)*pppppplVar8;
      IofCompleteRequest(pppppplVar1,2);
    } while ((longlong *******)pppppplVar8 != &local_38);
  }
  return uVar3;
}



===== NpPeek @ 1c000fba0 =====

uint NpPeek(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  uint *puVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  longlong *plVar9;
  ulonglong uVar10;
  undefined4 in_stack_ffffffffffffffac;
  undefined8 local_38 [2];
  
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  uVar6 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((*(byte *)(lVar3 + 0x20) & 1) == 0) {
    return 0xc00000b0;
  }
  if (**(short **)(lVar3 + 0x18) == 0x202) {
    uVar5 = *(ulonglong *)(lVar3 + 0x20) & 0xfffffffffffffffc;
    if (0xf < uVar6) {
      puVar4 = *(uint **)(param_2 + 0x18);
      uVar10 = 0x10;
      lVar8 = 0x48;
      if ((*(ulonglong *)(lVar3 + 0x20) >> 1 & 1) == 0) {
        lVar8 = 0xa8;
      }
      plVar9 = (longlong *)(lVar8 + uVar5);
      puVar4[0] = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      ExAcquirePushLockExclusiveEx(uVar5 + 0x40,0);
      if ((*(byte *)(lVar3 + 0x20) & 1) == 0) {
        uVar6 = 0xc00000b0;
      }
      else {
        uVar7 = 0;
        iVar2 = *(int *)(*(longlong *)(uVar5 + 0x28) + 0x104);
        bVar1 = *(byte *)(uVar5 + 8);
        if (bVar1 == 3) {
LAB_1c000fc65:
          *puVar4 = (uint)bVar1;
          if ((int)plVar9[2] == 1) {
            uVar7 = *(int *)((longlong)plVar9 + 0x14) - *(int *)((longlong)plVar9 + 0x24);
            lVar3 = *plVar9;
            puVar4[1] = uVar7;
            if (iVar2 == 0) {
              puVar4[2] = *(uint *)(plVar9 + 3);
              puVar4[3] = *(int *)(lVar3 + 0x28) - *(int *)((longlong)plVar9 + 0x24);
            }
            uVar6 = uVar6 - 0x10;
            if (uVar6 == 0) {
              uVar7 = -(uint)(uVar7 != 0) & 0x80000005;
            }
            else {
              puVar4 = (uint *)NpReadDataQueue(local_38,plVar9,'\x01','\0',puVar4 + 4,uVar6,
                                               CONCAT44(in_stack_ffffffffffffffac,(uint)(iVar2 == 0)
                                                       ),uVar5,param_3);
              uVar7 = *puVar4;
              uVar10 = (ulonglong)((int)*(undefined8 *)(puVar4 + 2) + 0x10);
            }
          }
          ExReleasePushLockExclusiveEx(uVar5 + 0x40,0);
          *(ulonglong *)(param_2 + 0x38) = uVar10;
          return uVar7;
        }
        if (bVar1 == 4) {
          if ((int)plVar9[2] == 1) goto LAB_1c000fc65;
          uVar6 = 0xc000014b;
        }
        else {
          uVar6 = 0xc00000ad;
        }
      }
      ExReleasePushLockExclusiveEx(uVar5 + 0x40,0);
      return uVar6;
    }
  }
  return 0xc000000d;
}



===== NpWaitForNamedPipe @ 1c000fda0 =====

ulonglong NpWaitForNamedPipe(longlong param_1,longlong param_2)

{
  short *psVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ushort *puVar8;
  uint uVar9;
  undefined1 local_res8 [8];
  undefined1 local_res10 [8];
  int local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 local_68;
  short *psStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  short *psStack_50;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar7 = 0;
  local_res8[0] = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  local_res18[0] = 0;
  if ((**(short **)(lVar4 + 0x18) != 0x206) || ((*(byte *)(lVar4 + 0x20) & 1) == 0)) {
    return 0xc00000af;
  }
  uVar9 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (uVar9 < 0x10) {
    return 0xc000000d;
  }
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0x18) + 8);
  if (0xfffd < uVar2) {
    return 0xc000000d;
  }
  if (uVar9 < uVar2 + 0xe) {
    return 0xc000000d;
  }
  lVar5 = 0;
  psVar1 = (short *)(*(longlong *)(param_2 + 0x18) + 0xe);
  local_68 = (ulonglong)(ushort)uVar2;
  psStack_60 = psVar1;
  if (*(char *)(param_2 + 0x40) == '\x01') {
    lVar5 = PsReferenceImpersonationToken(SystemReserved1[0xf],local_res10,local_res8,local_res20);
    if (lVar5 == 0) {
      uVar6 = PsGetCurrentProcess();
      lVar5 = PsReferencePrimaryToken(uVar6);
      goto LAB_1c000fe8d;
    }
    uVar6 = NpTranslateAlias((uint *)&local_68,lVar5,local_res18);
    uVar9 = (uint)uVar6;
    PsDereferenceImpersonationToken(lVar5);
  }
  else {
LAB_1c000fe8d:
    uVar6 = NpTranslateAlias((uint *)&local_68,lVar5,local_res18);
    uVar9 = (uint)uVar6;
    if (lVar5 != 0) {
      PsDereferencePrimaryToken(lVar5);
    }
  }
  if ((int)uVar9 < 0) {
    return (ulonglong)uVar9;
  }
  ExAcquirePushLockExclusiveEx(lVar3 + 0xc0,0);
  local_58 = (uint)local_68;
  uStack_54 = local_68._4_4_;
  psStack_50 = psStack_60;
  if ((1 < (ushort)local_68) && (*psStack_60 == 0x5c)) {
    local_58 = CONCAT22((short)(local_68 >> 0x10) + -2,(ushort)local_68 - 2);
    psStack_50 = psStack_60 + 1;
  }
  lVar5 = RtlFindUnicodePrefix(lVar3 + 0xd8,&local_58,0);
  if (lVar5 == 0) {
LAB_1c000ff33:
    ExReleasePushLockExclusiveEx(lVar3 + 0xc0,0);
    return 0xc0000034;
  }
  if ((*(short *)(lVar5 + -0xb0) != 0x202) || ((short)local_58 != *(short *)(lVar5 + -0x10)))
  goto LAB_1c000ff33;
  ExAcquirePushLockSharedEx(lVar5 + -0x30,0);
  if ((*(byte *)(lVar4 + 0x20) & 1) == 0) {
    uVar7 = 0xc00000af;
  }
  else if (*(longlong **)(lVar5 + 0x88) == (longlong *)(lVar5 + 0x88)) {
    ExReleasePushLockExclusiveEx(lVar3 + 0xc0,0);
    puVar8 = (ushort *)&local_68;
    if (psStack_60 == psVar1) {
      puVar8 = (ushort *)0x0;
    }
    uVar7 = NpAddWaiter(lVar3 + 0x90,*(undefined8 *)(lVar5 + 0x60),param_2,puVar8);
    uVar7 = uVar7 & 0xffffffff;
    ExReleasePushLockSharedEx(lVar5 + -0x30,0);
    goto LAB_1c0010023;
  }
  ExReleasePushLockSharedEx(lVar5 + -0x30,0);
  ExReleasePushLockExclusiveEx(lVar3 + 0xc0,0);
LAB_1c0010023:
  if (local_res18[0] == 0) {
    return uVar7;
  }
  RtlFreeUnicodeString(&local_68);
  return uVar7;
}



===== NpTranslateAlias @ 1c00100b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NpTranslateAlias(uint *param_1,longlong param_2,undefined4 *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  undefined8 uVar7;
  ushort uVar8;
  ushort *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  uint uStack_74;
  short *psStack_70;
  undefined8 local_68;
  ushort *puStack_60;
  undefined8 local_58;
  wchar_t *local_50;
  ushort local_48 [12];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_58 = 0xe000c;
  local_50 = L"LOCAL\\";
  local_68 = 0;
  puStack_60 = (ushort *)0x0;
  *param_3 = 0;
  local_78 = *param_1;
  uStack_74 = param_1[1];
  psStack_70 = *(short **)(param_1 + 2);
  if (((ushort)local_78 < 2) || (*psStack_70 != 0x5c)) {
    bVar4 = false;
    uVar11 = local_78;
  }
  else {
    psStack_70 = psStack_70 + 1;
    uVar8 = (ushort)local_78 - 2;
    uVar11 = (uint)uVar8;
    local_78._2_2_ = (short)(local_78 >> 0x10);
    bVar4 = true;
    local_78 = CONCAT22(local_78._2_2_ + -2,uVar8);
  }
  uVar8 = (ushort)uVar11;
  if (uVar8 != 0) {
    if ((param_2 != 0) && (0xc < uVar8)) {
      cVar6 = RtlPrefixUnicodeString(&local_58,&local_78,1);
      if (cVar6 != '\0') {
        uVar7 = NpTranslateContainerLocalAlias((undefined8 *)param_1,param_2,param_3);
        return uVar7;
      }
      uVar8 = (ushort)local_78;
    }
    uVar11 = uVar8 + 2;
    if (uVar8 - 8 < 9) {
      puVar10 = *(undefined8 **)(&NpAliasListByLength + ((ulonglong)uVar11 - 10 >> 1) * 8);
      if (puVar10 != (undefined8 *)0x0) {
LAB_1c00101af:
        if (uVar8 < 0x13) {
          local_68._0_4_ = CONCAT22(0x12,(undefined2)local_68);
          puStack_60 = local_48;
          RtlUpcaseUnicodeString(&local_68,&local_78,0);
          bVar5 = false;
        }
        else {
          uVar7 = RtlUpcaseUnicodeString(&local_68,&local_78,1);
          if ((int)uVar7 < 0) {
            return uVar7;
          }
          bVar5 = true;
        }
        do {
          puVar9 = puStack_60;
          while( true ) {
            uVar8 = *(ushort *)((puVar10[3] - (longlong)puStack_60) + 2 + (longlong)puVar9);
            if (uVar8 == 0) {
              puVar1 = (uint *)puVar10[1];
              uVar11 = puVar1[1];
              uVar2 = puVar1[2];
              uVar3 = puVar1[3];
              *param_1 = *puVar1;
              param_1[1] = uVar11;
              param_1[2] = uVar2;
              param_1[3] = uVar3;
              if (!bVar4) {
                *(short *)param_1 = (short)*param_1 + -2;
                *(short *)((longlong)param_1 + 2) = *(short *)((longlong)param_1 + 2) + -2;
                *(longlong *)(param_1 + 2) = *(longlong *)(param_1 + 2) + 2;
              }
              goto LAB_1c0010204;
            }
            if (*puVar9 < uVar8) goto LAB_1c0010204;
            if (uVar8 < *puVar9) break;
            puVar9 = puVar9 + 1;
          }
          puVar10 = (undefined8 *)*puVar10;
        } while ((puVar10 != (undefined8 *)0x0) && (*(ushort *)(puVar10 + 2) == uVar11));
LAB_1c0010204:
        if (bVar5) {
          RtlFreeUnicodeString(&local_68);
        }
      }
    }
    else {
      for (puVar10 = NpAliasList;
          (puVar10 != (undefined8 *)0x0 && (*(ushort *)(puVar10 + 2) <= uVar11));
          puVar10 = (undefined8 *)*puVar10) {
        if (*(ushort *)(puVar10 + 2) == uVar11) goto LAB_1c00101af;
      }
    }
  }
  return 0;
}



===== NpSetDisconnectedPipeState @ 1c00102d0 =====

undefined8 NpSetDisconnectedPipeState(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 == '\x01') {
    uVar7 = 0xc00000b0;
  }
  else if (cVar1 == '\x02') {
    plVar3 = (longlong *)(param_1 + 0x110);
    uVar7 = 0;
    while (plVar6 = (longlong *)*plVar3, plVar6 != plVar3) {
      if (((longlong *)plVar6[1] != plVar3) ||
         (lVar5 = *plVar6, (longlong *)*(longlong *)(lVar5 + 8) != plVar6)) goto LAB_1c0010517;
      *plVar3 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar3;
      LOCK();
      lVar5 = plVar6[-8];
      plVar6[-8] = 0;
      UNLOCK();
      if (lVar5 == 0) {
        plVar6[1] = (longlong)plVar6;
        *plVar6 = (longlong)plVar6;
      }
      else {
        *(undefined4 *)(plVar6 + -0xf) = 0xc00000b0;
        plVar2 = *(longlong **)(param_2 + 8);
        if (*plVar2 != param_2) goto LAB_1c0010517;
        *plVar6 = param_2;
        plVar6[1] = (longlong)plVar2;
        *plVar2 = (longlong)plVar6;
        *(longlong **)(param_2 + 8) = plVar6;
      }
    }
    plVar3 = (longlong *)(param_1 + 0x120);
    lVar5 = *plVar3;
    if ((*(longlong **)(lVar5 + 8) != plVar3) ||
       (plVar6 = *(longlong **)(param_1 + 0x128), (longlong *)*plVar6 != plVar3)) {
LAB_1c0010517:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar7 = (*pcVar4)();
      return uVar7;
    }
    *plVar6 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar6;
  }
  else {
    if (cVar1 == '\x03') {
      while (*(int *)(param_1 + 0x58) != 2) {
        lVar5 = NpRemoveDataQueueEntry((longlong *)(param_1 + 0x48),'\0',param_2);
        if (lVar5 != 0) {
          *(undefined4 *)(lVar5 + 0x30) = 0xc00000b0;
          plVar6 = (longlong *)(lVar5 + 0xa8);
          plVar3 = *(longlong **)(param_2 + 8);
          if (*plVar3 != param_2) goto LAB_1c0010517;
          *plVar6 = param_2;
          *(longlong **)(lVar5 + 0xb0) = plVar3;
          *plVar3 = (longlong)plVar6;
          *(longlong **)(param_2 + 8) = plVar6;
        }
      }
      while (*(int *)(param_1 + 0xb8) != 2) {
        lVar5 = NpRemoveDataQueueEntry((longlong *)(param_1 + 0xa8),'\0',param_2);
        if (lVar5 != 0) {
          *(undefined4 *)(lVar5 + 0x30) = 0xc00000b0;
          plVar6 = (longlong *)(lVar5 + 0xa8);
          plVar3 = *(longlong **)(param_2 + 8);
          if (*plVar3 != param_2) goto LAB_1c0010517;
          *plVar6 = param_2;
          *(longlong **)(lVar5 + 0xb0) = plVar3;
          *plVar3 = (longlong)plVar6;
          *(longlong **)(param_2 + 8) = plVar6;
        }
      }
      NpEventsDisconnectCompleted(param_1,1);
      lVar5 = *(longlong *)(param_1 + 0x30);
    }
    else {
      uVar7 = 0;
      if (cVar1 != '\x04') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x25,0x1602bb,cVar1,0,0);
      }
      while (*(int *)(param_1 + 0x58) != 2) {
        lVar5 = NpRemoveDataQueueEntry((longlong *)(param_1 + 0x48),'\0',param_2);
        if (lVar5 != 0) {
          *(undefined4 *)(lVar5 + 0x30) = 0xc00000b0;
          plVar6 = (longlong *)(lVar5 + 0xa8);
          plVar3 = *(longlong **)(param_2 + 8);
          if (*plVar3 != param_2) goto LAB_1c0010517;
          *plVar6 = param_2;
          *(longlong **)(lVar5 + 0xb0) = plVar3;
          *plVar3 = (longlong)plVar6;
          *(longlong **)(param_2 + 8) = plVar6;
        }
      }
      lVar5 = *(longlong *)(param_1 + 0x30);
      if (lVar5 == 0) goto LAB_1c0010338;
    }
    uVar7 = 0;
    *(ulonglong *)(lVar5 + 0x20) = *(ulonglong *)(lVar5 + 0x20) & 0xfffffffffffffffe;
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
LAB_1c0010338:
  NpRemoveAllAttributesFromList((longlong *)(param_1 + 0x130));
  *(undefined1 *)(param_1 + 8) = 1;
  return uVar7;
}



===== NpFreeClientSecurityContext @ 1c0010530 =====

void NpFreeClientSecurityContext(longlong param_1)

{
  if (param_1 - 1U < 0xfffffffffffffffe) {
    SeDeleteClientSecurity();
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== NpTranslateContainerLocalAlias @ 1c0010570 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
NpTranslateContainerLocalAlias(undefined8 *param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined2 uVar9;
  int iVar10;
  wchar_t *pwVar11;
  ushort uVar12;
  undefined8 *puVar13;
  bool bVar14;
  undefined1 auStack_318 [32];
  undefined8 *local_2f8;
  undefined8 *local_2f0;
  undefined4 local_2e8;
  undefined8 *local_2d8;
  undefined8 local_2d0;
  undefined2 *puStack_2c8;
  int local_2c0 [2];
  longlong local_2b8;
  longlong local_2b0;
  undefined8 local_2a8;
  undefined1 *puStack_2a0;
  ulonglong local_298;
  undefined8 local_290;
  short *psStack_288;
  undefined8 *local_280;
  longlong local_278;
  undefined8 local_270;
  longlong lStack_268;
  undefined8 local_260;
  longlong lStack_258;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_318;
  local_2d8 = (undefined8 *)0x0;
  local_2c0[0] = 0;
  local_278 = 0;
  local_260 = 0;
  lStack_258 = 0;
  bVar4 = false;
  local_2a8 = 0;
  puStack_2a0 = (undefined1 *)0x0;
  local_2d0 = 0;
  puStack_2c8 = (undefined2 *)0x0;
  local_290 = 0;
  psStack_288 = (short *)0x0;
  memset(local_248,0,0x200);
  local_2b8 = 0;
  local_280 = (undefined8 *)0x0;
  *param_3 = 0;
  local_2b0 = 0;
  local_270 = 0;
  lStack_268 = 0;
  local_298 = 0;
  uVar6 = SeQueryInformationToken(param_2,0x1d,&local_2b0);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  uVar6 = SeQueryInformationToken(param_2,0x2a,&local_2b8);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  if ((local_2b0 == 0) && (local_2b8 == 0)) {
    return 0;
  }
  uVar6 = SeQueryInformationToken(param_2,0xc,&local_298);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  if (local_2b0 != 0) {
    iVar5 = SeQueryInformationToken(param_2,0x1f,&local_2d8);
    if ((iVar5 < 0) || (iVar5 = RtlGetAppContainerSidType(*local_2d8,local_2c0), iVar5 < 0))
    goto LAB_1c001069b;
    if (local_2c0[0] == 1) {
      iVar5 = RtlGetAppContainerParent(*local_2d8,&local_278);
      if ((iVar5 < 0) || (iVar5 = RtlConvertSidToUnicodeString(&local_260,local_278,1), iVar5 < 0))
      goto LAB_1c001069b;
      puStack_2a0 = local_248;
      local_2a8 = CONCAT44(local_2a8._4_4_,0x2000000);
      puVar7 = (undefined4 *)RtlSubAuthoritySid(*local_2d8,0xb);
      uVar1 = *puVar7;
      puVar7 = (undefined4 *)RtlSubAuthoritySid(*local_2d8,10);
      uVar2 = *puVar7;
      puVar7 = (undefined4 *)RtlSubAuthoritySid(*local_2d8,9);
      uVar3 = *puVar7;
      puVar8 = (uint *)RtlSubAuthoritySid(*local_2d8,8);
      local_2f0 = (undefined8 *)CONCAT44(local_2f0._4_4_,uVar2);
      local_2f8 = (undefined8 *)CONCAT44(local_2f8._4_4_,uVar3);
      local_2e8 = uVar1;
      uVar6 = RtlUnicodeStringPrintf
                        ((ushort *)&local_2a8,L"%wZ\\%lu-%lu-%lu-%lu",&local_260,(ulonglong)*puVar8)
      ;
      iVar5 = (int)uVar6;
      if (iVar5 < 0) goto LAB_1c001069b;
    }
    else {
      iVar5 = RtlConvertSidToUnicodeString(&local_2a8,*local_2d8,1);
      if (iVar5 < 0) goto LAB_1c001069b;
      bVar4 = true;
    }
  }
  if ((local_2b8 == 0) ||
     ((iVar5 = SeQueryInformationToken(param_2,1,&local_280), -1 < iVar5 &&
      (iVar5 = RtlConvertSidToUnicodeString(&local_270,*local_280,1), -1 < iVar5)))) {
    psStack_288 = (short *)param_1[1];
    local_290._0_2_ = (short)*(undefined4 *)param_1;
    bVar14 = *psStack_288 == 0x5c;
    if (bVar14) {
      psStack_288 = psStack_288 + 1;
      local_290._0_2_ = (short)local_290 + -2;
    }
    uVar12 = (short)local_290 - 0xc;
    local_290._4_4_ = (undefined4)((ulonglong)*param_1 >> 0x20);
    local_290._0_4_ = CONCAT22(uVar12,uVar12);
    psStack_288 = psStack_288 + 6;
    if (local_2b8 == 0) {
      iVar5 = (ushort)local_2a8 + 0x70;
      iVar10 = (ushort)local_2a8 + 0x72;
    }
    else if (local_2b0 == 0) {
      iVar5 = (ushort)local_270 + 0x60;
      iVar10 = (ushort)local_270 + 0x62;
    }
    else {
      iVar5 = (uint)(ushort)local_270 + (uint)(ushort)local_2a8 + 0x78;
      iVar10 = (uint)(ushort)local_270 + (uint)(ushort)local_2a8 + 0x7a;
    }
    if (!bVar14) {
      iVar10 = iVar5;
    }
    if (iVar10 + (uint)uVar12 < 0xffff) {
      uVar9 = (undefined2)(iVar10 + (uint)uVar12);
      local_2d0._0_4_ = CONCAT22(uVar9,(ushort)local_2d0);
      puStack_2c8 = (undefined2 *)ExAllocatePool2(0x100,uVar9,0x6e46704e);
      if (puStack_2c8 == (undefined2 *)0x0) {
        iVar5 = -0x3fffff66;
      }
      else {
        if (bVar14) {
          puStack_2c8 = puStack_2c8 + 1;
          local_2d0._0_4_ = CONCAT22(local_2d0._2_2_ + -2,(ushort)local_2d0);
        }
        if (local_2b8 == 0) {
          puVar13 = &local_2a8;
          pwVar11 = L"Sessions\\%ld\\AppContainerNamedObjects\\%wZ\\%wZ";
LAB_1c0010802:
          local_2f8 = &local_290;
          uVar6 = RtlUnicodeStringPrintf
                            ((ushort *)&local_2d0,pwVar11,local_298 & 0xffffffff,puVar13);
          iVar5 = (int)uVar6;
        }
        else {
          puVar13 = &local_270;
          if (local_2b0 == 0) {
            pwVar11 = L"Sessions\\%ld\\BaseNamedObjects\\%wZ\\%wZ";
            goto LAB_1c0010802;
          }
          local_2f8 = &local_2a8;
          local_2f0 = &local_290;
          uVar6 = RtlUnicodeStringPrintf
                            ((ushort *)&local_2d0,
                             L"Sessions\\%ld\\AppContainerNamedObjects\\%wZ\\%wZ\\%wZ",
                             local_298 & 0xffffffff,puVar13);
          iVar5 = (int)uVar6;
        }
        if (bVar14) {
          puStack_2c8 = puStack_2c8 + -1;
          local_2d0._0_4_ = CONCAT22(local_2d0._2_2_ + 2,(ushort)local_2d0);
        }
        if (-1 < iVar5) {
          if (bVar14) {
            *puStack_2c8 = 0x5c;
            local_2d0 = CONCAT62(local_2d0._2_6_,(ushort)local_2d0 + 2);
          }
          *param_1 = local_2d0;
          param_1[1] = puStack_2c8;
          *param_3 = 1;
        }
      }
    }
    else {
      iVar5 = -0x3ffffefa;
    }
  }
  if (bVar4) {
    RtlFreeUnicodeString(&local_2a8);
  }
LAB_1c001069b:
  if (lStack_268 != 0) {
    RtlFreeUnicodeString(&local_270);
  }
  if (iVar5 < 0) {
    RtlFreeUnicodeString(&local_2d0);
  }
  if (local_2d8 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_2d8,0);
  }
  if (local_280 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_280,0);
  }
  if (local_278 != 0) {
    ExFreePoolWithTag(local_278,0);
  }
  if (lStack_258 != 0) {
    RtlFreeUnicodeString(&local_260);
  }
  return 0;
}



===== NpListen @ 1c0010b20 =====

ulonglong NpListen(longlong param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  ulonglong uVar13;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((**(short **)(lVar4 + 0x18) != 0x202) || ((*(byte *)(lVar4 + 0x20) & 1) == 0)) ||
     (((byte)*(ulonglong *)(lVar4 + 0x20) >> 1 & 1) == 0)) {
    return 0xc00000af;
  }
  uVar13 = *(ulonglong *)(lVar4 + 0x20) & 0xfffffffffffffffc;
  ExAcquirePushLockExclusiveEx(*(longlong *)(uVar13 + 0x28) + 0x80,0);
  ExAcquirePushLockExclusiveEx(uVar13 + 0x40,0);
  puVar11 = auStack_48;
  puVar9 = auStack_48;
  if ((*(byte *)(lVar4 + 0x20) & 1) == 0) {
    uVar8 = 0xc00000af;
    goto LAB_1c0010bbe;
  }
  cVar2 = *(char *)(uVar13 + 8);
  if (cVar2 == '\x03') {
    uVar8 = 0xc00000b2;
    puVar9 = auStack_48;
    goto LAB_1c0010bbe;
  }
  if (cVar2 == '\x01') {
    uVar7 = NpCancelWaiter((longlong *)(lVar3 + 0x90),
                           (ushort *)(*(longlong *)(uVar13 + 0x28) + 0xa0),0,param_3);
    puVar9 = auStack_48;
    puVar11 = auStack_48;
    puVar10 = auStack_48;
    uVar8 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) goto LAB_1c0010bbe;
    if ((*(byte *)(uVar13 + 10) & 2) != 0) goto LAB_1c0010d37;
    LOCK();
    *(code **)(param_2 + 0x68) = NpCancelListeningQueueIrp;
    UNLOCK();
    if (*(char *)(param_2 + 0x44) != '\0') {
      LOCK();
      lVar3 = *(longlong *)(param_2 + 0x68);
      *(longlong *)(param_2 + 0x68) = 0;
      UNLOCK();
      if (lVar3 != 0) {
LAB_1c0010cf5:
        uVar8 = 0xc0000120;
        puVar9 = auStack_48;
        goto LAB_1c0010bbe;
      }
    }
    lVar3 = *(longlong *)(uVar13 + 0x28);
    plVar5 = (longlong *)(uVar13 + 0x120);
    *(undefined1 *)(uVar13 + 8) = 2;
    plVar12 = *(longlong **)(lVar3 + 0x140);
    if (*plVar12 == lVar3 + 0x138) {
      *plVar5 = lVar3 + 0x138;
      *(longlong **)(uVar13 + 0x128) = plVar12;
      *plVar12 = (longlong)plVar5;
      *(longlong **)(lVar3 + 0x140) = plVar5;
LAB_1c0010c9f:
      plVar12 = (longlong *)(param_2 + 0xa8);
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      plVar5 = *(longlong **)(uVar13 + 0x118);
      puVar10 = auStack_48;
      if (*plVar5 == uVar13 + 0x110) {
        *plVar12 = uVar13 + 0x110;
        uVar8 = 0x103;
        *(longlong **)(param_2 + 0xb0) = plVar5;
        *plVar5 = (longlong)plVar12;
        *(longlong **)(uVar13 + 0x118) = plVar12;
        puVar9 = auStack_48;
        goto LAB_1c0010bbe;
      }
    }
    do {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar11 = puVar10 + 8;
LAB_1c0010d37:
      lVar3 = *(longlong *)(uVar13 + 0x28);
      plVar5 = (longlong *)(uVar13 + 0x120);
      *(undefined1 *)(uVar13 + 8) = 2;
      plVar12 = *(longlong **)(lVar3 + 0x140);
      puVar10 = puVar11;
    } while (*plVar12 != lVar3 + 0x138);
    *plVar5 = lVar3 + 0x138;
    *(longlong **)(uVar13 + 0x128) = plVar12;
    *plVar12 = (longlong)plVar5;
    *(longlong **)(lVar3 + 0x140) = plVar5;
  }
  else {
    if (cVar2 != '\x02') {
      if (cVar2 != '\x04') {
        local_28 = 0;
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x25,0x1600c3,cVar2,0);
      }
      uVar8 = 0xc00000b1;
      puVar9 = auStack_48;
      goto LAB_1c0010bbe;
    }
    if ((*(byte *)(uVar13 + 10) & 2) == 0) {
      LOCK();
      *(code **)(param_2 + 0x68) = NpCancelListeningQueueIrp;
      UNLOCK();
      if (*(char *)(param_2 + 0x44) != '\0') {
        LOCK();
        lVar3 = *(longlong *)(param_2 + 0x68);
        *(longlong *)(param_2 + 0x68) = 0;
        UNLOCK();
        if (lVar3 != 0) goto LAB_1c0010cf5;
      }
      goto LAB_1c0010c9f;
    }
  }
  uVar8 = 0xc00000b3;
  puVar9 = puVar11;
LAB_1c0010bbe:
  *(undefined8 *)(puVar9 + -8) = 0x1c0010bcb;
  ExReleasePushLockExclusiveEx(uVar13 + 0x40,0);
  lVar3 = *(longlong *)(uVar13 + 0x28);
  *(undefined8 *)(puVar9 + -8) = 0x1c0010be1;
  ExReleasePushLockExclusiveEx(lVar3 + 0x80,0);
  return uVar8;
}



===== NpSetClosingPipeState @ 1c0010d8c =====

undefined8 NpSetClosingPipeState(longlong param_1,uint param_2,longlong param_3,undefined8 *param_4)

{
  ulonglong *puVar1;
  char cVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 *puVar12;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  puVar12 = auStack_48;
  *param_4 = 0;
  cVar2 = *(char *)(param_1 + 8);
  if (cVar2 != '\x01') {
    if (cVar2 != '\x02') {
      if (cVar2 == '\x03') {
        if (param_2 == 1) {
          lVar11 = 0x48;
          puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x38) + 0x20);
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          lVar10 = 0xa8;
          *(undefined8 *)(param_1 + 0x38) = 0;
        }
        else {
          lVar11 = 0xa8;
          puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x30) + 0x20);
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          lVar10 = 0x48;
          *(undefined8 *)(param_1 + 0x30) = 0;
        }
        *(undefined1 *)(param_1 + 8) = 4;
        NpEventsDisconnectCompleted(param_1,param_2);
        while ((int)((longlong *)(param_1 + lVar11))[2] != 2) {
          lVar8 = NpRemoveDataQueueEntry((longlong *)(param_1 + lVar11),'\0',param_3);
          if (lVar8 != 0) {
            *(undefined4 *)(lVar8 + 0x30) = 0xc000014b;
            plVar7 = (longlong *)(lVar8 + 0xa8);
            plVar4 = *(longlong **)(param_3 + 8);
            if (*plVar4 != param_3) goto LAB_1c0010fdd;
            *plVar7 = param_3;
            *(longlong **)(lVar8 + 0xb0) = plVar4;
            *plVar4 = (longlong)plVar7;
            *(longlong **)(param_3 + 8) = plVar7;
          }
        }
        while ((iVar3 = (int)((longlong *)(param_1 + lVar10))[2], iVar3 != 2 && (iVar3 == 0))) {
          lVar11 = NpRemoveDataQueueEntry((longlong *)(param_1 + lVar10),'\0',param_3);
          if (lVar11 != 0) {
            *(undefined4 *)(lVar11 + 0x30) = 0xc000014b;
            plVar7 = (longlong *)(lVar11 + 0xa8);
            plVar4 = *(longlong **)(param_3 + 8);
            if (*plVar4 != param_3) goto LAB_1c0010fdd;
            *plVar7 = param_3;
            *(longlong **)(lVar11 + 0xb0) = plVar4;
            *plVar4 = (longlong)plVar7;
            *(longlong **)(param_3 + 8) = plVar7;
          }
        }
      }
      else {
        if (cVar2 != '\x04') goto LAB_1c0010fe4;
        if (param_2 == 1) {
          puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x38) + 0x20);
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          lVar10 = 0x48;
          *(undefined8 *)(param_1 + 0x38) = 0;
        }
        else {
          puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x30) + 0x20);
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          lVar10 = 0xa8;
          *(undefined8 *)(param_1 + 0x30) = 0;
        }
        while ((int)((longlong *)(lVar10 + param_1))[2] != 2) {
          lVar11 = NpRemoveDataQueueEntry((longlong *)(lVar10 + param_1),'\0',param_3);
          if (lVar11 != 0) {
            *(undefined4 *)(lVar11 + 0x30) = 0xc000014b;
            plVar7 = (longlong *)(lVar11 + 0xa8);
            plVar4 = *(longlong **)(param_3 + 8);
            if (*plVar4 != param_3) goto LAB_1c0010fdd;
            *plVar7 = param_3;
            *(longlong **)(lVar11 + 0xb0) = plVar4;
            *plVar4 = (longlong)plVar7;
            *(longlong **)(param_3 + 8) = plVar7;
          }
        }
        uVar9 = NpClearSecurity(param_1);
        *param_4 = uVar9;
      }
      goto LAB_1c0010e20;
    }
    plVar4 = (longlong *)(param_1 + 0x110);
    while (plVar7 = (longlong *)*plVar4, plVar7 != plVar4) {
      if (((longlong *)plVar7[1] != plVar4) ||
         (lVar10 = *plVar7, (longlong *)*(longlong *)(lVar10 + 8) != plVar7)) goto LAB_1c0010fdd;
      *plVar4 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar4;
      LOCK();
      lVar10 = plVar7[-8];
      plVar7[-8] = 0;
      UNLOCK();
      if (lVar10 == 0) {
        plVar7[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar7;
      }
      else {
        *(undefined4 *)(plVar7 + -0xf) = 0xc000014b;
        plVar5 = *(longlong **)(param_3 + 8);
        if (*plVar5 != param_3) goto LAB_1c0010fdd;
        *plVar7 = param_3;
        plVar7[1] = (longlong)plVar5;
        *plVar5 = (longlong)plVar7;
        *(longlong **)(param_3 + 8) = plVar7;
      }
    }
  }
  puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x38) + 0x20);
  *puVar1 = *puVar1 & 0xfffffffffffffffe;
  *(undefined8 *)(param_1 + 0x38) = 0;
LAB_1c0010e20:
  NpRemoveAllAttributesFromList((longlong *)(((ulonglong)param_2 + 0x14) * 0x10 + param_1));
  return 0;
LAB_1c0010fdd:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar12 = auStack_40;
LAB_1c0010fe4:
  *(undefined8 *)(puVar12 + 0x20) = 0;
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar12 + -8) = 0x1c0010ffd;
  KeBugCheckEx(0x25,0x160203);
}



===== NpRemoveAllAttributesFromList @ 1c001100c =====

void NpRemoveAllAttributesFromList(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    if (5 < (ulonglong)plVar1[2]) {
      ExFreePoolWithTag(plVar1,0);
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== NpEventsDisconnectCompleted @ 1c0011060 =====

void NpEventsDisconnectCompleted(longlong param_1,uint param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x1b0 + (ulonglong)param_2 * 8);
  if (plVar1 != (longlong *)0x0) {
    if (*plVar1 != 0) {
      ObfDereferenceObject();
    }
    ExFreePoolWithTag(plVar1,0);
    *(undefined8 *)(param_1 + 0x1b0 + (ulonglong)param_2 * 8) = 0;
  }
  lVar2 = 0x1b0;
  if (param_2 != 1) {
    lVar2 = 0x1b8;
  }
  plVar1 = *(longlong **)(lVar2 + param_1);
  if ((plVar1 != (longlong *)0x0) && ((*(uint *)(plVar1 + 1) & 8) != 0)) {
    lVar2 = 0x30;
    if (param_2 != 1) {
      lVar2 = 0x38;
    }
    if (((*(longlong *)(lVar2 + param_1) != 0) &&
        ((*(byte *)(*(longlong *)(lVar2 + param_1) + 0x20) & 1) != 0)) && (*plVar1 != 0)) {
      KeSetEvent(*plVar1,2);
    }
  }
  return;
}



===== NpUnlinkCcb @ 1c0011130 =====

void NpUnlinkCcb(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  
  plVar1 = (longlong *)(param_2 + 0x18);
  lVar5 = *plVar1;
  if ((*(longlong **)(lVar5 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_2 + 0x20), (longlong *)*plVar3 != plVar1)) {
LAB_1c00111d4:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar3;
  piVar2 = (int *)(*(longlong *)(param_2 + 0x28) + 0x78);
  *piVar2 = *piVar2 + -1;
  if (*(char *)(param_2 + 8) == '\x02') {
    plVar1 = (longlong *)(param_2 + 0x120);
    lVar5 = *plVar1;
    if ((*(longlong **)(lVar5 + 8) != plVar1) ||
       (plVar3 = *(longlong **)(param_2 + 0x128), (longlong *)*plVar3 != plVar1))
    goto LAB_1c00111d4;
    *plVar3 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar3;
  }
  if (*(longlong *)(param_2 + 0x1c0) != 0) {
    NpCheckForNotifyWithFilter
              (param_1,param_3,0x10,(ushort *)(*(longlong *)(param_2 + 0x28) + 0xa0));
  }
  lVar5 = NpClearSecurity(param_2);
  NpFreeClientSecurityContext(lVar5);
  return;
}



===== NpUnlinkFcb @ 1c00111e4 =====

void NpUnlinkFcb(longlong param_1,longlong param_2,longlong param_3)

{
  ushort *puVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  puVar1 = (ushort *)(param_2 + 0xa0);
  if (*puVar1 == 0) {
    return;
  }
  NpCancelWaiter((longlong *)(param_1 + 0x90),puVar1,0xc0000034,param_3);
  plVar2 = (longlong *)(param_2 + 0x88);
  lVar3 = *plVar2;
  if ((*(longlong **)(lVar3 + 8) == plVar2) &&
     (plVar4 = *(longlong **)(param_2 + 0x90), (longlong *)*plVar4 == plVar2)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    RtlRemoveUnicodePrefix(param_1 + 0xd8,param_2 + 0xb0);
    plVar2 = (longlong *)(param_2 + 0xe8);
    lVar3 = *plVar2;
    if ((*(longlong **)(lVar3 + 8) == plVar2) &&
       (plVar4 = *(longlong **)(param_2 + 0xf0), (longlong *)*plVar4 == plVar2)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      NpCheckForNotifyWithFilter(param_1,param_3,1,puVar1);
      *puVar1 = 0;
      return;
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== NpGetAttribute @ 1c00112d8 =====

ulonglong NpGetAttribute(longlong param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  void *_Dst;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong local_res18;
  void *local_res20;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  local_res20 = (void *)0x0;
  local_res18 = 0;
  uVar1 = *(uint *)(lVar2 + 8);
  if (((*(int *)(lVar2 + 0x10) == 0) ||
      (_Dst = *(void **)(param_1 + 0x18),
      *(char *)((ulonglong)(*(int *)(lVar2 + 0x10) - 1) + (longlong)_Dst) != '\0')) ||
     (lVar2 = *(longlong *)(lVar2 + 0x30), **(short **)(lVar2 + 0x18) != 0x202)) {
    return 0xc000000d;
  }
  uVar7 = *(ulonglong *)(lVar2 + 0x20) & 0xfffffffffffffffc;
  uVar8 = *(ulonglong *)(lVar2 + 0x20) >> 1;
  lVar5 = *(longlong *)(uVar7 + 0x28);
  if (param_2 == 0) {
    puVar6 = (undefined8 *)(lVar5 + 0x128);
    ExAcquirePushLockSharedEx(lVar5 + 0x80);
    if (((uVar8 & 1) != 0) || ((*(byte *)(lVar2 + 0x20) & 1) != 0)) goto LAB_1c0011385;
    uVar8 = 0xc00000b0;
LAB_1c0011426:
    lVar5 = lVar5 + 0x80;
  }
  else {
    if (param_2 == 1) {
      puVar6 = (undefined8 *)(uVar7 + 0x130);
    }
    else {
      if (param_2 != 2) {
        return 0xc000000d;
      }
      puVar6 = (undefined8 *)(((ulonglong)((uint)uVar8 & 1) + 0x14) * 0x10 + uVar7);
    }
    ExAcquirePushLockSharedEx(uVar7 + 0x40);
    if (((uVar8 & 1) == 0) && ((*(byte *)(lVar2 + 0x20) & 1) == 0)) {
      uVar8 = 0xc00000b0;
    }
    else {
LAB_1c0011385:
      uVar4 = NpGetAttributeFromList(puVar6,(ulonglong)_Dst,(longlong *)&local_res20,&local_res18);
      uVar3 = local_res18;
      uVar8 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        if (uVar1 < local_res18) {
          uVar8 = 0xc0000023;
        }
        else {
          memcpy(_Dst,local_res20,local_res18);
          *(ulonglong *)(param_1 + 0x38) = uVar3;
        }
      }
      if (param_2 == 0) goto LAB_1c0011426;
      if ((param_2 != 1) && (param_2 != 2)) {
        return uVar8;
      }
    }
    lVar5 = uVar7 + 0x40;
  }
  ExReleasePushLockSharedEx(lVar5,0);
  return uVar8;
}



===== NpGetAttributeFromList @ 1c0011484 =====

undefined8
NpGetAttributeFromList(undefined8 *param_1,ulonglong param_2,longlong *param_3,undefined8 *param_4)

{
  char cVar1;
  char cVar2;
  longlong *plVar3;
  int iVar4;
  char *pcVar5;
  longlong lVar6;
  undefined8 *puVar7;
  bool bVar8;
  
  puVar7 = (undefined8 *)*param_1;
  do {
    if (puVar7 == param_1) {
      return 0xc0000225;
    }
    if (param_2 < 7) {
      bVar8 = puVar7[2] == param_2;
    }
    else {
      pcVar5 = (char *)puVar7[2];
      iVar4 = (int)pcVar5;
      if (iVar4 == 1) {
        pcVar5 = "ServerProcessId";
      }
      else if (iVar4 == 2) {
        pcVar5 = "ServerSessionId";
      }
      else if (iVar4 == 3) {
        pcVar5 = "ClientProcessId";
      }
      else if (iVar4 == 4) {
        pcVar5 = "ClientSessionId";
      }
      else if (iVar4 == 6) {
        pcVar5 = "ClientComputerName";
      }
      lVar6 = param_2 - (longlong)pcVar5;
      do {
        cVar1 = *pcVar5;
        cVar2 = pcVar5[lVar6];
        if (cVar1 != cVar2) break;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      bVar8 = cVar1 == cVar2;
    }
    if (bVar8) {
      plVar3 = puVar7 + 4;
      if (8 < (ulonglong)puVar7[3]) {
        plVar3 = (longlong *)*plVar3;
      }
      *param_3 = (longlong)plVar3;
      *param_4 = puVar7[3];
      return 0;
    }
    puVar7 = (undefined8 *)*puVar7;
  } while( true );
}



===== NpTransceive @ 1c0011550 =====

int NpTransceive(longlong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  void *_Dst;
  byte bVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  uint uVar15;
  ulonglong uVar16;
  uint local_res20 [2];
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  
  local_res20[0] = 0;
  lVar8 = *(longlong *)(param_2 + 0xb8);
  uVar1 = *(uint *)(lVar8 + 0x10);
  lVar2 = *(longlong *)(lVar8 + 0x20);
  if (*(char *)(param_2 + 0x40) != '\0') {
    ProbeForWrite(*(undefined8 *)(param_2 + 0x70),*(undefined4 *)(lVar8 + 8));
  }
  lVar8 = *(longlong *)(lVar8 + 0x30);
  if (((*(byte *)(lVar8 + 0x20) & 1) == 0) || (**(short **)(lVar8 + 0x18) != 0x202)) {
    return -0x3fffff50;
  }
  uVar11 = *(ulonglong *)(lVar8 + 0x20) & 0xfffffffffffffffc;
  uVar16 = *(ulonglong *)(lVar8 + 0x20) >> 1;
  uVar15 = (uint)uVar16 & 1;
  uVar3 = *(undefined8 *)(param_2 + 0x98);
  ExAcquirePushLockExclusiveEx(uVar11 + 0x40,0);
  puVar14 = auStackY_c8;
  if ((*(byte *)(lVar8 + 0x20) & 1) == 0) {
    iVar7 = -0x3fffff50;
    goto LAB_1c0011873;
  }
  if (*(char *)(uVar11 + 8) == '\x03') {
    if ((uVar16 & 1) == 0) {
      bVar9 = *(byte *)(uVar11 + 9);
    }
    else {
      bVar9 = *(byte *)(uVar11 + 10);
    }
    plVar13 = (longlong *)((ulonglong)(-(uint)((uVar16 & 1) != 0) & 0x60) + 0x48 + uVar11);
    if (((short)*(undefined4 *)(*(longlong *)(uVar11 + 0x28) + 0x100) == 2) && ((bVar9 & 1) != 0)) {
      if (*(int *)((-(ulonglong)((uVar16 & 1) != 0) & 0xffffffffffffffa0) + uVar11 + 0xb8) == 2) {
        iVar7 = NpWriteDataQueue(plVar13,(ulonglong)(bVar9 & 1),lVar2,uVar1,
                                 *(int *)(*(longlong *)(uVar11 + 0x28) + 0x104),local_res20);
        puVar14 = auStackY_c8;
        if (iVar7 == -0x3fffffea) {
          lVar8 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),1);
          uVar6 = local_res20[0];
          if (lVar8 == 0) {
            iVar7 = -0x3fffff66;
            puVar14 = auStackY_c8;
            goto LAB_1c0011873;
          }
          lVar4 = *(longlong *)(lVar8 + 0xb8);
          *(code **)(lVar4 + -0x10) = NpCompleteTransceiveIrp;
          *(undefined8 *)(lVar4 + -8) = 0;
          *(undefined1 *)(lVar4 + -0x45) = 0xe0;
          lVar4 = *(longlong *)(lVar8 + 0xb8);
          puVar14 = (undefined1 *)(lVar4 + -0x48);
          uVar16 = (ulonglong)local_res20[0];
          if (local_res20[0] == 0) {
            *(undefined8 *)(lVar8 + 0x18) = 0;
          }
          else {
            _Dst = (void *)ExAllocatePool2(0x101,local_res20[0],0x7746704e);
            *(void **)(lVar8 + 0x18) = _Dst;
            if (_Dst == (void *)0x0) {
              ExReleasePushLockExclusiveEx(uVar11 + 0x40,0);
              IoFreeIrp(lVar8);
              return -0x3fffff66;
            }
            memcpy(_Dst,(void *)((ulonglong)(uVar1 - uVar6) + lVar2),(ulonglong)uVar6);
          }
          *(char *)(lVar8 + 0x43) = *(char *)(lVar8 + 0x43) + -1;
          *(undefined1 **)(lVar8 + 0xb8) = puVar14;
          *(undefined8 *)(lVar8 + 0x98) = uVar3;
          *(ulonglong *)(lVar8 + 0x38) = uVar16;
          *(uint *)(lVar4 + -0x40) = uVar6;
          *puVar14 = 4;
          if (uVar6 != 0) {
            *(undefined4 *)(lVar8 + 0x10) = 0x30;
          }
          *(undefined **)(lVar8 + 0x48) = &DAT_1c0006080;
          iVar7 = NpAddDataQueueEntry(uVar15,uVar11,(longlong)plVar13,1,1,uVar6,lVar8,(void *)0x0,0)
          ;
          puVar10 = auStackY_c8;
          puVar14 = auStackY_c8;
          if (iVar7 != 0x103) {
            *(int *)(lVar8 + 0x30) = iVar7;
            plVar12 = (longlong *)(lVar8 + 0xa8);
            plVar13 = *(longlong **)(param_3 + 8);
            if (*plVar13 != param_3) {
              param_3 = 3;
              pcVar5 = (code *)swi(0x29);
              plVar13 = (longlong *)(*pcVar5)();
              puVar10 = auStackY_c0;
            }
            *plVar12 = param_3;
            *(longlong **)(lVar8 + 0xb0) = plVar13;
            *plVar13 = (longlong)plVar12;
            *(longlong **)(param_3 + 8) = plVar12;
            puVar14 = puVar10;
          }
          param_2 = *(longlong *)(puVar14 + 0xd8);
        }
        if (-1 < iVar7) {
          *(undefined4 *)(puVar14 + 0x40) = 0;
          *(undefined8 *)(puVar14 + 0x38) = 0;
          *(longlong *)(puVar14 + 0x30) = param_2;
          *(undefined4 *)(puVar14 + 0x28) = *(undefined4 *)(puVar14 + 0x50);
          *(undefined4 *)(puVar14 + 0x20) = 0;
          *(undefined8 *)(puVar14 + -8) = 0x1c0011871;
          iVar7 = NpAddDataQueueEntry(uVar15,uVar11,*(longlong *)(puVar14 + 0x88),0,
                                      *(int *)(puVar14 + 0x20),*(uint *)(puVar14 + 0x28),
                                      *(longlong *)(puVar14 + 0x30),*(void **)(puVar14 + 0x38),
                                      *(int *)(puVar14 + 0x40));
        }
      }
      else {
        iVar7 = -0x3fffff52;
        puVar14 = auStackY_c8;
      }
      goto LAB_1c0011873;
    }
  }
  iVar7 = -0x3fffff53;
  puVar14 = auStackY_c8;
LAB_1c0011873:
  *(undefined8 *)(puVar14 + -8) = 0x1c0011881;
  ExReleasePushLockExclusiveEx(*(undefined8 *)(puVar14 + 0x58),0);
  return iVar7;
}



===== NpFastWrite @ 1c0011980 =====

bool NpFastWrite(longlong param_1,undefined8 param_2,uint param_3,undefined8 param_4,
                undefined8 param_5,void *param_6,int *param_7)

{
  longlong ***ppplVar1;
  undefined8 uVar2;
  longlong ***ppplVar3;
  longlong ***local_20;
  longlong ***local_18;
  
  local_18 = (longlong ***)&local_20;
  local_20 = (longlong ***)&local_20;
  KeEnterCriticalRegion();
  uVar2 = NpCommonWrite(param_1,param_6,param_3,SystemReserved1[0xf],param_7,0);
  ppplVar3 = local_20;
  if ((longlong ****)local_20 != &local_20) {
    do {
      ppplVar1 = ppplVar3 + -0x15;
      ppplVar3 = (longlong ***)*ppplVar3;
      IofCompleteRequest(ppplVar1,2);
    } while ((longlong ****)ppplVar3 != &local_20);
  }
  KeLeaveCriticalRegion();
  return (char)uVar2 != '\0';
}



===== NpFastRead @ 1c0011a50 =====

undefined8
NpFastRead(longlong param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,int *param_7)

{
  longlong ****pppplVar1;
  char cVar2;
  byte bVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  ulonglong uVar11;
  longlong ****pppplVar12;
  longlong lVar13;
  longlong *plVar14;
  uint uVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  undefined4 in_stack_ffffffffffffffac;
  longlong ****local_38;
  longlong ****local_30;
  undefined8 local_28 [2];
  
  local_30 = (longlong ****)&local_38;
  local_38 = (longlong ****)&local_38;
  KeEnterCriticalRegion();
  param_7[2] = 0;
  param_7[3] = 0;
  if (**(short **)(param_1 + 0x18) != 0x202) {
    *param_7 = -0x3ffffff3;
    uVar17 = 1;
    goto LAB_1c0011bce;
  }
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    *param_7 = -0x3fffff50;
    uVar17 = 1;
    goto LAB_1c0011bce;
  }
  uVar11 = *(ulonglong *)(param_1 + 0x20) & 0xfffffffffffffffc;
  uVar16 = *(ulonglong *)(param_1 + 0x20) >> 1;
  uVar15 = (uint)uVar16 & 1;
  ExAcquirePushLockExclusiveEx(uVar11 + 0x40,0);
  if (((*(byte *)(param_1 + 0x20) & 1) == 0) || (cVar2 = *(char *)(uVar11 + 8), cVar2 == '\x01')) {
    *param_7 = -0x3fffff50;
  }
  else if (cVar2 == '\x02') {
    *param_7 = -0x3fffff4d;
  }
  else {
    uVar8 = *(uint *)(*(longlong *)(uVar11 + 0x28) + 0x100) & 0xffff;
    if ((uVar16 & 1) == 0) {
      if (uVar8 == 0) goto LAB_1c0011c37;
    }
    else if (uVar8 == 1) {
LAB_1c0011c37:
      *param_7 = -0x3ffffff3;
      goto LAB_1c0011bac;
    }
    bVar3 = *(byte *)((ulonglong)uVar15 + 9 + uVar11);
    lVar13 = 0x48;
    if ((uVar16 & 1) == 0) {
      lVar13 = 0xa8;
    }
    plVar14 = (longlong *)(lVar13 + uVar11);
    if ((int)plVar14[2] == 1) {
      piVar10 = (int *)NpReadDataQueue(local_28,plVar14,'\0','\0',param_6,param_3,
                                       CONCAT44(in_stack_ffffffffffffffac,(uint)bVar3) &
                                       0xffffffff00000001,uVar11,(longlong)&local_38);
      iVar9 = piVar10[1];
      iVar6 = piVar10[2];
      iVar7 = piVar10[3];
      *param_7 = *piVar10;
      param_7[1] = iVar9;
      param_7[2] = iVar6;
      param_7[3] = iVar7;
    }
    else {
      if (cVar2 == '\x04') {
        iVar9 = -0x3ffffeb5;
      }
      else {
        if ((bVar3 & 2) == 0) {
          ExReleasePushLockExclusiveEx(uVar11 + 0x40,0);
          uVar17 = 0;
          goto LAB_1c0011bce;
        }
        iVar9 = -0x3fffff27;
      }
      *param_7 = iVar9;
    }
    if (plVar14 != (longlong *)0x0) {
      puVar4 = *(undefined8 **)(uVar11 + 0x1b0 + (ulonglong)uVar15 * 8);
      lVar13 = *(longlong *)(param_7 + 2);
      iVar9 = *param_7;
      if (((puVar4 != (undefined8 *)0x0) && ((*(uint *)(puVar4 + 1) & 2) != 0)) &&
         ((int)plVar14[2] == 1)) {
        KeSetEvent(*puVar4,2);
      }
      puVar4 = *(undefined8 **)(uVar11 + 0x1b0 + ((ulonglong)uVar15 ^ 1) * 8);
      if (((((puVar4 != (undefined8 *)0x0) && (uVar8 = *(uint *)(puVar4 + 1), (uVar8 & 1) != 0)) &&
           ((lVar5 = *(longlong *)(uVar11 + 0x30 + ((ulonglong)uVar15 ^ 1) * 8), lVar5 != 0 &&
            (((*(byte *)(lVar5 + 0x20) & 1) != 0 && (-1 < iVar9)))))) && (lVar13 != 0)) &&
         (*(uint *)(puVar4 + 1) = uVar8 & 0xfffffffe, (uVar8 & 4) != 0)) {
        KeSetEvent(*puVar4,2);
      }
    }
  }
LAB_1c0011bac:
  ExReleasePushLockExclusiveEx(uVar11 + 0x40,0);
  uVar17 = 1;
LAB_1c0011bce:
  pppplVar12 = local_38;
  if ((longlong *****)local_38 != &local_38) {
    do {
      pppplVar1 = pppplVar12 + -0x15;
      pppplVar12 = (longlong ****)*pppplVar12;
      IofCompleteRequest(pppplVar1,2);
    } while ((longlong *****)pppplVar12 != &local_38);
  }
  KeLeaveCriticalRegion();
  return uVar17;
}



===== NpFsdRead @ 1c0011d70 =====

int NpFsdRead(undefined8 param_1,longlong param_2)

{
  longlong ****pppplVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  ulonglong uVar10;
  longlong ****pppplVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar17;
  longlong ****local_58;
  longlong ****local_50;
  undefined8 local_48 [2];
  
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_50 = (longlong ****)&local_58;
  lVar15 = *(longlong *)(param_2 + 0xb8);
  local_58 = (longlong ****)&local_58;
  KeEnterCriticalRegion();
  uVar4 = *(uint *)(lVar15 + 8);
  lVar14 = 0;
  lVar15 = *(longlong *)(lVar15 + 0x30);
  uVar5 = *(undefined8 *)(param_2 + 0x70);
  if (**(short **)(lVar15 + 0x18) != 0x202) {
    iVar8 = -0x3ffffff3;
    goto LAB_1c0011f24;
  }
  if ((*(byte *)(lVar15 + 0x20) & 1) == 0) {
    iVar8 = -0x3fffff50;
    goto LAB_1c0011f24;
  }
  uVar10 = *(ulonglong *)(lVar15 + 0x20) & 0xfffffffffffffffc;
  uVar13 = *(ulonglong *)(lVar15 + 0x20) >> 1;
  uVar12 = (uint)uVar13 & 1;
  ExAcquirePushLockExclusiveEx(uVar10 + 0x40,0);
  if (((*(byte *)(lVar15 + 0x20) & 1) == 0) || (cVar2 = *(char *)(uVar10 + 8), cVar2 == '\x01')) {
    iVar8 = -0x3fffff50;
  }
  else if (cVar2 == '\x02') {
    iVar8 = -0x3fffff4d;
  }
  else {
    uVar7 = *(uint *)(*(longlong *)(uVar10 + 0x28) + 0x100) & 0xffff;
    if ((uVar13 & 1) == 0) {
      if (uVar7 == 0) goto LAB_1c0011fa0;
    }
    else if (uVar7 == 1) {
LAB_1c0011fa0:
      iVar8 = -0x3ffffff3;
      goto LAB_1c0011ef8;
    }
    bVar3 = *(byte *)((ulonglong)uVar12 + 9 + uVar10);
    lVar15 = 0x48;
    if ((uVar13 & 1) == 0) {
      lVar15 = 0xa8;
    }
    plVar16 = (longlong *)(lVar15 + uVar10);
    if ((int)plVar16[2] == 1) {
      piVar9 = (int *)NpReadDataQueue(local_48,plVar16,'\0','\0',uVar5,uVar4,
                                      CONCAT44(uVar17,(uint)bVar3) & 0xffffffff00000001,uVar10,
                                      (longlong)&local_58);
      lVar14 = *(longlong *)(piVar9 + 2);
      iVar8 = *piVar9;
    }
    else if (cVar2 == '\x04') {
      iVar8 = -0x3ffffeb5;
    }
    else if ((bVar3 & 2) == 0) {
      iVar8 = NpAddDataQueueEntry(uVar12,uVar10,(longlong)plVar16,0,0,uVar4,param_2,(void *)0x0,0);
    }
    else {
      iVar8 = -0x3fffff27;
    }
    if (plVar16 != (longlong *)0x0) {
      puVar6 = *(undefined8 **)(uVar10 + 0x1b0 + (ulonglong)uVar12 * 8);
      if (((puVar6 != (undefined8 *)0x0) && ((*(uint *)(puVar6 + 1) & 2) != 0)) &&
         ((int)plVar16[2] == 1)) {
        KeSetEvent(*puVar6,2);
      }
      puVar6 = *(undefined8 **)(uVar10 + 0x1b0 + ((ulonglong)uVar12 ^ 1) * 8);
      if (((((puVar6 != (undefined8 *)0x0) && (uVar4 = *(uint *)(puVar6 + 1), (uVar4 & 1) != 0)) &&
           ((lVar15 = *(longlong *)(uVar10 + 0x30 + ((ulonglong)uVar12 ^ 1) * 8), lVar15 != 0 &&
            (((*(byte *)(lVar15 + 0x20) & 1) != 0 && (-1 < iVar8)))))) && (lVar14 != 0)) &&
         (*(uint *)(puVar6 + 1) = uVar4 & 0xfffffffe, (uVar4 & 4) != 0)) {
        KeSetEvent(*puVar6,2);
      }
    }
  }
LAB_1c0011ef8:
  ExReleasePushLockExclusiveEx(uVar10 + 0x40,0);
LAB_1c0011f24:
  pppplVar11 = local_58;
  if ((longlong *****)local_58 != &local_58) {
    do {
      pppplVar1 = pppplVar11 + -0x15;
      pppplVar11 = (longlong ****)*pppplVar11;
      IofCompleteRequest(pppplVar1,2);
    } while ((longlong *****)pppplVar11 != &local_58);
  }
  KeLeaveCriticalRegion();
  if (iVar8 != 0x103) {
    *(longlong *)(param_2 + 0x38) = lVar14;
    *(int *)(param_2 + 0x30) = iVar8;
    IofCompleteRequest(param_2,2);
  }
  return iVar8;
}



===== NpReadDataQueue @ 1c00120d0 =====

undefined8 *
NpReadDataQueue(undefined8 *param_1,longlong *param_2,char param_3,char param_4,undefined8 param_5,
               uint param_6,undefined8 param_7,undefined8 param_8,longlong param_9)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  longlong *plVar12;
  longlong *plVar13;
  uint uVar14;
  ulonglong uVar15;
  uint uVar16;
  ulonglong uVar17;
  uint uVar18;
  ulonglong _Size;
  char cVar19;
  undefined1 auStack_78 [32];
  uint local_58;
  undefined4 local_54;
  
  puVar9 = auStack_78;
  *param_1 = 0;
  cVar19 = '\x01';
  if (param_4 == '\0') {
    cVar19 = param_3;
  }
  uVar15 = (ulonglong)param_6;
  local_58 = param_6;
  param_1[1] = 0;
  uVar10 = 0;
  local_54 = 0;
  plVar12 = (longlong *)*param_2;
  puVar3 = auStack_78;
  uVar17 = uVar15;
  if (cVar19 == '\0') {
    puVar3 = auStack_78;
    if (plVar12 == param_2) goto LAB_1c00122e0;
    do {
      if (*(uint *)(plVar12 + 4) < 2) break;
      lVar6 = NpRemoveDataQueueEntry(param_2,'\0',param_9);
      if (lVar6 != 0) {
        *(undefined4 *)(lVar6 + 0x30) = 0;
        plVar7 = (longlong *)(lVar6 + 0xa8);
        plVar8 = *(longlong **)(param_9 + 8);
        if (*plVar8 != param_9) goto LAB_1c00124fb;
        *plVar7 = param_9;
        *(longlong **)(lVar6 + 0xb0) = plVar8;
        *plVar8 = (longlong)plVar7;
        *(longlong **)(param_9 + 8) = plVar7;
      }
      plVar12 = (longlong *)*param_2;
    } while (plVar12 != param_2);
    uVar15 = (ulonglong)local_58;
    uVar17 = (ulonglong)local_58;
    puVar3 = auStack_78;
  }
LAB_1c0012144:
  do {
    puVar9 = puVar3;
    puVar3 = puVar9;
    if (plVar12 == param_2) goto LAB_1c00122e0;
    if ((cVar19 != '\0') && (1 < *(uint *)(plVar12 + 4))) goto LAB_1c0012290;
    if ((int)plVar12[4] == 1) {
      plVar8 = *(longlong **)(plVar12[2] + 0x18);
    }
    else {
      plVar8 = plVar12 + 6;
    }
    uVar10 = *(uint *)(plVar12 + 5);
    *(uint *)(puVar9 + 0x28) = uVar10;
    uVar11 = uVar10;
    if (plVar12 == (longlong *)*param_2) {
      uVar11 = uVar10 - *(int *)((longlong)param_2 + 0x24);
    }
    _Size = (ulonglong)uVar11;
    if ((uint)uVar15 <= uVar11) {
      _Size = uVar15;
    }
    uVar18 = (uint)_Size;
    *(undefined8 *)(puVar9 + -8) = 0x1c001219c;
    memcpy((void *)((ulonglong)((int)uVar17 - (uint)uVar15) + *(longlong *)(puVar9 + 0xa0)),
           (void *)((ulonglong)(uVar10 - uVar11) + (longlong)plVar8),_Size);
    *(uint *)(puVar9 + 0x20) = *(int *)(puVar9 + 0x20) - uVar18;
    *(uint *)(puVar9 + 0x24) = *(int *)(puVar9 + 0x24) + uVar18;
    if (cVar19 == '\0') {
      uVar10 = *(uint *)((longlong)plVar12 + 0x24);
      if (uVar18 < uVar10) {
        uVar16 = uVar18;
      }
      else {
        uVar16 = uVar10;
      }
      *(uint *)((longlong)plVar12 + 0x24) = uVar10 - uVar16;
      *(uint *)(param_2 + 4) = (int)param_2[4] - uVar16;
      *(int *)((longlong)param_2 + 0x24) = *(int *)((longlong)param_2 + 0x24) + uVar18;
      puVar9[0x90] = 1;
    }
    lVar6 = plVar12[3];
    if (lVar6 != 0) {
      lVar1 = *(longlong *)(*(longlong *)(puVar9 + 0xb8) + 0x108);
      *(longlong *)(puVar9 + 0x30) = lVar1;
      if (lVar1 - 1U < 0xfffffffffffffffe) {
        *(undefined8 *)(puVar9 + -8) = 0x1c0012460;
        SeDeleteClientSecurity();
        *(undefined8 *)(puVar9 + -8) = 0x1c0012473;
        ExFreePoolWithTag(*(undefined8 *)(puVar9 + 0x30));
      }
      if (*(longlong *)(*(longlong *)(puVar9 + 0xb8) + 0x108) == -1) {
        *(undefined8 *)(puVar9 + -8) = 0x1c001252f;
        NpFreeClientSecurityContext(lVar6);
      }
      else {
        *(longlong *)(*(longlong *)(puVar9 + 0xb8) + 0x108) = lVar6;
      }
    }
    plVar12[3] = 0;
    uVar10 = *(uint *)(puVar9 + 0x24);
    if (uVar11 != uVar18) goto LAB_1c001243e;
    uVar17 = (ulonglong)(byte)puVar9[0x98];
    if (puVar9[0x98] != 0) goto LAB_1c0012502;
LAB_1c0012228:
    if ((cVar19 == '\0') || ((char)uVar17 != '\0')) {
      if ((char)uVar17 != '\0') {
        *(undefined8 *)(puVar9 + -8) = 0x1c0012522;
        NpGetNextRealDataQueueEntry(param_2,param_9);
      }
      *(undefined8 *)(puVar9 + -8) = 0x1c0012247;
      lVar6 = NpRemoveDataQueueEntry(param_2,'\x01',param_9);
      if (lVar6 != 0) {
        *(ulonglong *)(lVar6 + 0x38) = (ulonglong)*(uint *)(puVar9 + 0x28);
        *(undefined4 *)(lVar6 + 0x30) = 0;
        plVar7 = (longlong *)(lVar6 + 0xa8);
        plVar8 = *(longlong **)(param_9 + 8);
        if (*plVar8 != param_9) goto LAB_1c00124fb;
        *plVar7 = param_9;
        *(longlong **)(lVar6 + 0xb0) = plVar8;
        *plVar8 = (longlong)plVar7;
        *(longlong **)(param_9 + 8) = plVar7;
      }
    }
    if (*(int *)(puVar9 + 0xb0) == 1) {
      *(undefined4 *)param_1 = 0;
      puVar3 = puVar9;
      goto LAB_1c00122e0;
    }
    while( true ) {
      uVar17 = (ulonglong)*(uint *)(puVar9 + 0xa8);
      uVar15 = (ulonglong)*(uint *)(puVar9 + 0x20);
LAB_1c0012290:
      puVar3 = puVar9;
      if ((int)uVar15 == 0) goto LAB_1c00122e0;
      if (cVar19 != '\0') {
        plVar12 = (longlong *)*plVar12;
        goto LAB_1c0012144;
      }
      plVar12 = (longlong *)*param_2;
      if (plVar12 == param_2) break;
      while( true ) {
        if (*(uint *)(plVar12 + 4) < 2) goto LAB_1c00122ca;
        *(undefined8 *)(puVar9 + -8) = 0x1c00122b9;
        lVar6 = NpRemoveDataQueueEntry(param_2,'\0',param_9);
        if (lVar6 != 0) break;
LAB_1c00122c2:
        plVar12 = (longlong *)*param_2;
        if (plVar12 == param_2) {
LAB_1c00122ca:
          uVar15 = (ulonglong)*(uint *)(puVar9 + 0x20);
          goto LAB_1c00122cf;
        }
      }
      *(undefined4 *)(lVar6 + 0x30) = 0;
      plVar7 = (longlong *)(lVar6 + 0xa8);
      plVar8 = *(longlong **)(param_9 + 8);
      if (*plVar8 == param_9) {
        *plVar7 = param_9;
        *(longlong **)(lVar6 + 0xb0) = plVar8;
        *plVar8 = (longlong)plVar7;
        *(longlong **)(param_9 + 8) = plVar7;
        goto LAB_1c00122c2;
      }
LAB_1c00124fb:
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar9 = puVar9 + 8;
LAB_1c0012502:
      if (uVar10 != 0) goto LAB_1c0012228;
LAB_1c001243e:
      if (*(int *)(puVar9 + 0xb0) == 1) {
        *(undefined4 *)param_1 = 0x80000005;
        puVar3 = puVar9;
LAB_1c00122e0:
        puVar9 = puVar3;
        param_1[1] = (ulonglong)uVar10;
        if (puVar9[0x90] != '\0') {
          uVar11 = *(int *)((longlong)param_2 + 0x1c) - (int)param_2[4];
          iVar4 = *(int *)((longlong)param_2 + 0x24);
          plVar8 = (longlong *)*param_2;
          if (plVar8 != param_2) {
            do {
              if (uVar11 == 0) break;
              lVar6 = plVar8[2];
              if (((int)plVar8[4] == 0) && (lVar6 != 0)) {
                uVar16 = (int)plVar8[5] - iVar4;
                uVar17 = (ulonglong)uVar16;
                uVar18 = *(uint *)((longlong)plVar8 + 0x24);
                if (uVar18 < uVar16) {
                  uVar14 = ((int)plVar8[5] - uVar18) - iVar4;
                  uVar5 = uVar11;
                  if (uVar14 <= uVar11) {
                    uVar5 = uVar14;
                  }
                  uVar11 = uVar11 - uVar5;
                  *(uint *)((longlong)plVar8 + 0x24) = uVar5 + uVar18;
                  if (uVar5 + uVar18 == uVar16) {
                    LOCK();
                    lVar1 = *(longlong *)(lVar6 + 0x68);
                    *(longlong *)(lVar6 + 0x68) = 0;
                    UNLOCK();
                    if (lVar1 != 0) {
                      plVar8[2] = 0;
                      *(ulonglong *)(lVar6 + 0x38) = (ulonglong)*(uint *)(plVar8 + 5);
                      *(undefined4 *)(lVar6 + 0x30) = 0;
                      plVar13 = (longlong *)(lVar6 + 0xa8);
                      plVar7 = *(longlong **)(param_9 + 8);
                      if (*plVar7 != param_9) goto LAB_1c00124fb;
                      *plVar13 = param_9;
                      *(longlong **)(lVar6 + 0xb0) = plVar7;
                      *plVar7 = (longlong)plVar13;
                      *(longlong **)(param_9 + 8) = plVar13;
                    }
                  }
                }
              }
              plVar8 = (longlong *)*plVar8;
              iVar4 = 0;
              if (plVar8 == param_2) break;
            } while( true );
          }
          *(uint *)(param_2 + 4) = *(int *)((longlong)param_2 + 0x1c) - uVar11;
        }
        return param_1;
      }
    }
LAB_1c00122cf:
    uVar17 = (ulonglong)*(uint *)(puVar9 + 0xa8);
  } while( true );
}



===== NpFsdWrite @ 1c0012540 =====

ulonglong NpFsdWrite(undefined8 param_1,longlong param_2)

{
  longlong ****pppplVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong ****pppplVar4;
  longlong ****local_28;
  longlong ****local_20;
  ulonglong local_18;
  undefined8 uStack_10;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_20 = (longlong ****)&local_28;
  local_28 = (longlong ****)&local_28;
  local_18 = 0;
  uStack_10 = 0;
  KeEnterCriticalRegion();
  NpCommonWrite(*(longlong *)(lVar2 + 0x30),*(void **)(param_2 + 0x70),*(uint *)(lVar2 + 8),
                *(undefined8 *)(param_2 + 0x98),(int *)&local_18,param_2);
  pppplVar4 = local_28;
  if ((longlong *****)local_28 != &local_28) {
    do {
      pppplVar1 = pppplVar4 + -0x15;
      pppplVar4 = (longlong ****)*pppplVar4;
      IofCompleteRequest(pppplVar1,2);
    } while ((longlong *****)pppplVar4 != &local_28);
  }
  KeLeaveCriticalRegion();
  uVar3 = local_18;
  if ((int)local_18 != 0x103) {
    *(undefined8 *)(param_2 + 0x38) = uStack_10;
    *(int *)(param_2 + 0x30) = (int)local_18;
    IofCompleteRequest(param_2,2);
  }
  return uVar3 & 0xffffffff;
}



===== NpGetNextRealDataQueueEntry @ 1c0012630 =====

void NpGetNextRealDataQueueEntry(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar1 = (longlong *)*param_1;
  while ((plVar1 != param_1 && (1 < *(uint *)(plVar1 + 4)))) {
    lVar3 = NpRemoveDataQueueEntry(param_1,'\0',param_2);
    if (lVar3 != 0) {
      *(undefined4 *)(lVar3 + 0x30) = 0;
      plVar4 = (longlong *)(lVar3 + 0xa8);
      plVar1 = *(longlong **)(param_2 + 8);
      if (*plVar1 != param_2) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      *plVar4 = param_2;
      *(longlong **)(lVar3 + 0xb0) = plVar1;
      *plVar1 = (longlong)plVar4;
      *(longlong **)(param_2 + 8) = plVar4;
    }
    plVar1 = (longlong *)*param_1;
  }
  return;
}



===== NpCommonWrite @ 1c00126b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
NpCommonWrite(longlong param_1,void *param_2,uint param_3,undefined8 param_4,int *param_5,
             longlong param_6)

{
  char cVar1;
  byte bVar2;
  short *psVar3;
  longlong lVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  param_5[2] = 0;
  param_5[3] = 0;
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    *param_5 = -0x3fffff50;
    return 1;
  }
  psVar3 = *(short **)(param_1 + 0x18);
  if (*psVar3 != 0x202) {
    *param_5 = -0x3ffffff3;
    return CONCAT71((int7)((ulonglong)psVar3 >> 8),1);
  }
  uVar8 = *(ulonglong *)(param_1 + 0x20) & 0xfffffffffffffffc;
  uVar12 = *(ulonglong *)(param_1 + 0x20) >> 1;
  uVar11 = (uint)uVar12 & 1;
  uVar13 = (ulonglong)uVar11;
  lVar4 = *(longlong *)(uVar8 + 0x28);
  uVar10 = *(uint *)(lVar4 + 0x100) & 0xffff;
  ExAcquirePushLockExclusiveEx(uVar8 + 0x40,0);
  if ((*(byte *)(param_1 + 0x20) & 1) != 0) {
    cVar1 = *(char *)(uVar8 + 8);
    if (cVar1 == '\x03') {
      if ((uVar12 & 1) == 0) {
        if (uVar10 == 1) goto LAB_1c0012a32;
        bVar2 = *(byte *)(uVar8 + 10);
        plVar9 = (longlong *)(uVar8 + 0x48);
      }
      else {
        if (uVar10 == 0) {
LAB_1c0012a32:
          *param_5 = -0x3ffffff3;
          goto LAB_1c0012840;
        }
        bVar2 = *(byte *)(uVar8 + 9);
        plVar9 = (longlong *)(uVar8 + 0xa8);
      }
      *param_5 = 0;
      *(ulonglong *)(param_5 + 2) = (ulonglong)param_3;
      if ((int)plVar9[2] == 0) {
        if ((param_3 <= *(uint *)((longlong)plVar9 + 0x14)) ||
           (param_3 - *(uint *)((longlong)plVar9 + 0x14) <= *(uint *)((longlong)plVar9 + 0x1c)))
        goto LAB_1c00127ab;
LAB_1c0012919:
        if ((*(int *)(lVar4 + 0x104) != 0) || ((*(byte *)(uVar13 + 9 + uVar8) & 2) == 0)) {
          if (param_6 == 0) {
            uVar8 = ExReleasePushLockExclusiveEx(uVar8 + 0x40,0);
            return uVar8 & 0xffffffffffffff00;
          }
          goto LAB_1c00127ab;
        }
        param_5[2] = 0;
        param_5[3] = 0;
        iVar6 = 0;
      }
      else {
        if ((uint)(*(int *)((longlong)plVar9 + 0x1c) - (int)plVar9[4]) < param_3)
        goto LAB_1c0012919;
LAB_1c00127ab:
        iVar6 = NpWriteDataQueue(plVar9,(ulonglong)(bVar2 & 1),(longlong)param_2,param_3,
                                 *(int *)(lVar4 + 0x104),local_res8);
        *param_5 = iVar6;
        if (iVar6 == -0x3fffffea) {
          if ((((*(byte *)(uVar13 + 9 + uVar8) & 2) == 0) && (param_6 != 0)) ||
             (local_res8[0] <= (uint)(*(int *)((longlong)plVar9 + 0x1c) - (int)plVar9[4]))) {
            iVar6 = NpAddDataQueueEntry(uVar11,uVar8,(longlong)plVar9,1,0,param_3,param_6,param_2,
                                        param_3 - local_res8[0]);
            *param_5 = iVar6;
          }
          else {
            *param_5 = 0;
            *(ulonglong *)(param_5 + 2) = (ulonglong)(param_3 - local_res8[0]);
            iVar6 = 0;
          }
        }
      }
      if (param_3 != 0) {
        if ((int)plVar9[2] == 1) {
          lVar4 = *(longlong *)(uVar8 + 0x1b0 + uVar13 * 8);
          if (((lVar4 != 0) && (*(longlong *)(param_5 + 2) == 0)) &&
             ((-1 < iVar6 && ((*(uint *)(lVar4 + 8) & 1) == 0)))) {
            *(uint *)(lVar4 + 8) = *(uint *)(lVar4 + 8) | 1;
          }
          puVar5 = *(undefined8 **)(uVar8 + 0x1b0 + (uVar13 ^ 1) * 8);
          if (((puVar5 != (undefined8 *)0x0) && ((*(uint *)(puVar5 + 1) & 2) != 0)) &&
             ((lVar4 = *(longlong *)(uVar8 + 0x30 + (uVar13 ^ 1) * 8), lVar4 != 0 &&
              ((*(byte *)(lVar4 + 0x20) & 1) != 0)))) {
            KeSetEvent(*puVar5,2);
          }
        }
        *(undefined8 *)(uVar8 + 0x1c0) = _DAT_fffff78000000014;
      }
      goto LAB_1c0012840;
    }
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        *param_5 = -0x3fffff4d;
      }
      else {
        *param_5 = -0x3fffff4f;
      }
      goto LAB_1c0012840;
    }
  }
  *param_5 = -0x3fffff50;
LAB_1c0012840:
  uVar7 = ExReleasePushLockExclusiveEx(uVar8 + 0x40,0);
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== NpWriteDataQueue @ 1c0012a50 =====

int NpWriteDataQueue(longlong *param_1,undefined8 param_2,longlong param_3,uint param_4,int param_5,
                    uint *param_6)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  longlong lVar6;
  void *_Dst;
  longlong *plVar7;
  longlong *plVar8;
  char cVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  longlong in_stack_00000050;
  undefined1 auStack_68 [48];
  
  puVar12 = auStack_68;
  *param_6 = param_4;
  if ((param_5 == 0) && (param_4 == 0)) {
    cVar9 = '\x01';
  }
  else {
    cVar9 = '\0';
  }
  plVar7 = (longlong *)*param_1;
  puVar11 = auStack_68;
  if (plVar7 == param_1) goto LAB_1c0012af1;
  do {
    puVar11 = auStack_68;
    if (*(uint *)(plVar7 + 4) < 2) break;
    lVar6 = NpRemoveDataQueueEntry(param_1,'\0',in_stack_00000050);
    if (lVar6 != 0) {
      *(undefined4 *)(lVar6 + 0x30) = 0;
      plVar8 = (longlong *)(lVar6 + 0xa8);
      plVar7 = *(longlong **)(in_stack_00000050 + 8);
      if (*plVar7 != in_stack_00000050) goto LAB_1c0012ddc;
      *plVar8 = in_stack_00000050;
      *(longlong **)(lVar6 + 0xb0) = plVar7;
      *plVar7 = (longlong)plVar8;
      *(longlong **)(in_stack_00000050 + 8) = plVar8;
    }
    plVar7 = (longlong *)*param_1;
    puVar11 = auStack_68;
  } while (plVar7 != param_1);
  do {
    param_4 = *(uint *)(puVar11 + 0x88);
    cVar9 = puVar11[0x90];
    param_3 = *(longlong *)(puVar11 + 0x80);
LAB_1c0012af1:
    puVar12 = puVar11;
    iVar5 = 0;
    if (((int)param_1[2] != 0) || ((*param_6 == 0 && (cVar9 == '\0')))) {
      if ((*param_6 == 0) && (cVar9 == '\0')) {
        return 0;
      }
      return -0x3fffffea;
    }
    uVar13 = *(uint *)(plVar7 + 5);
    pcVar2 = *(char **)(plVar7[2] + 0xb8);
    if (((*pcVar2 == '\r') && (*(int *)(pcVar2 + 0x18) == 0x116000)) &&
       ((uVar13 < param_4 || (cVar9 != '\0')))) {
      *(undefined8 *)(puVar12 + -8) = 0x1c0012ccb;
      lVar6 = NpRemoveDataQueueEntry(param_1,'\x01',in_stack_00000050);
      if (lVar6 != 0) {
        *(undefined4 *)(lVar6 + 0x30) = 0x80000005;
        plVar7 = (longlong *)(lVar6 + 0xa8);
LAB_1c0012dcf:
        plVar8 = *(longlong **)(in_stack_00000050 + 8);
        if (*plVar8 != in_stack_00000050) goto LAB_1c0012ddc;
LAB_1c0012c24:
        *plVar7 = in_stack_00000050;
        plVar7[1] = (longlong)plVar8;
        *plVar8 = (longlong)plVar7;
        *(longlong **)(in_stack_00000050 + 8) = plVar7;
      }
    }
    else {
      iVar10 = (int)plVar7[4];
      if (iVar10 == 1) {
        *(undefined8 *)(plVar7[2] + 0x58) = 0;
        iVar10 = (int)plVar7[4];
      }
      if (*param_6 < uVar13) {
        uVar13 = *param_6;
      }
      if ((iVar10 == 1) || (uVar13 == 0)) {
        _Dst = *(void **)(plVar7[2] + 0x18);
        *(void **)(puVar12 + 0x20) = _Dst;
        cVar9 = '\0';
      }
      else {
        *(undefined8 *)(puVar12 + -8) = 0x1c0012b53;
        _Dst = (void *)ExAllocatePool2(0x40,uVar13,0x5246704e);
        *(void **)(puVar12 + 0x20) = _Dst;
        if (_Dst == (void *)0x0) {
          return -0x3fffff66;
        }
        cVar9 = '\x01';
        param_4 = *(uint *)(puVar12 + 0x88);
        param_3 = *(longlong *)(puVar12 + 0x80);
      }
      puVar12[0x98] = cVar9;
      uVar1 = *param_6;
      *(undefined8 *)(puVar12 + -8) = 0x1c0012b97;
      memcpy(_Dst,(void *)((ulonglong)(param_4 - uVar1) + param_3),(ulonglong)uVar13);
      if (puVar12[0x70] == '\0') {
        puVar12[0x70] = 1;
        if (((*(int *)(puVar12 + 0xa8) == 0) &&
            (*(char *)(*(longlong *)(puVar12 + 0xa0) + 0x14) == '\x01')) &&
           (*(longlong *)(*(longlong *)(puVar12 + 0xa0) + 0x108) != -1)) {
          *(undefined8 *)(puVar12 + -8) = 0x1c0012e41;
          lVar6 = ExAllocatePool2(0x101,0x48,0x7346704e);
          *(longlong *)(puVar12 + 0x98) = lVar6;
          if (lVar6 == 0) {
            iVar5 = -0x3fffff66;
LAB_1c0012f14:
            if (cVar9 != '\0') {
              *(undefined8 *)(puVar12 + -8) = 0x1c0012f29;
              ExFreePoolWithTag(_Dst,0);
            }
            return iVar5;
          }
          *(undefined8 *)(puVar12 + -8) = 0x1c0012e78;
          iVar5 = SeCreateClientSecurity
                            (*(undefined8 *)(puVar12 + 0xb0),*(longlong *)(puVar12 + 0xa0) + 0xc,0,
                             lVar6);
          lVar6 = *(longlong *)(puVar12 + 0x98);
          if (iVar5 < 0) {
            *(undefined8 *)(puVar12 + -8) = 0x1c0012e99;
            ExFreePoolWithTag(lVar6,0);
            goto LAB_1c0012d29;
          }
        }
        else {
LAB_1c0012d29:
          lVar6 = 0;
          *(undefined8 *)(puVar12 + 0x98) = 0;
        }
        if (iVar5 < 0) goto LAB_1c0012f14;
        if (lVar6 != 0) {
          lVar3 = *(longlong *)(*(longlong *)(puVar12 + 0xa0) + 0x108);
          if (lVar3 - 1U < 0xfffffffffffffffe) {
            *(undefined8 *)(puVar12 + -8) = 0x1c0012ebb;
            SeDeleteClientSecurity(lVar3);
            *(undefined8 *)(puVar12 + -8) = 0x1c0012ecc;
            ExFreePoolWithTag(lVar3,0);
            lVar6 = *(longlong *)(puVar12 + 0x98);
          }
          if (*(longlong *)(*(longlong *)(puVar12 + 0xa0) + 0x108) == -1) {
            *(undefined8 *)(puVar12 + -8) = 0x1c0012f09;
            NpFreeClientSecurityContext(lVar6);
          }
          else {
            *(longlong *)(*(longlong *)(puVar12 + 0xa0) + 0x108) = lVar6;
          }
        }
      }
      *(undefined8 *)(puVar12 + -8) = 0x1c0012bd7;
      lVar6 = NpRemoveDataQueueEntry(param_1,'\x01',in_stack_00000050);
      if (lVar6 != 0) {
        *param_6 = *param_6 - uVar13;
        *(ulonglong *)(lVar6 + 0x38) = (ulonglong)uVar13;
        if (cVar9 != '\0') {
          *(void **)(lVar6 + 0x18) = _Dst;
          *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) | 0x70;
        }
        plVar7 = (longlong *)(lVar6 + 0xa8);
        if (*param_6 != 0) {
          if (*(int *)(puVar12 + 0x78) == 1) {
            *(undefined4 *)(lVar6 + 0x30) = 0x80000005;
          }
          else {
            *(undefined4 *)(lVar6 + 0x30) = 0;
          }
          goto LAB_1c0012dcf;
        }
        *(undefined4 *)(lVar6 + 0x30) = 0;
        plVar8 = *(longlong **)(in_stack_00000050 + 8);
        if (*plVar8 != in_stack_00000050) goto LAB_1c0012ddc;
        puVar12[0x90] = 0;
        goto LAB_1c0012c24;
      }
      if (cVar9 != '\0') {
        *(undefined8 *)(puVar12 + -8) = 0x1c0012cfb;
        ExFreePoolWithTag(_Dst);
      }
    }
    plVar7 = (longlong *)*param_1;
    while ((puVar11 = puVar12, plVar7 != param_1 && (1 < *(uint *)(plVar7 + 4)))) {
      *(undefined8 *)(puVar12 + -8) = 0x1c0012c57;
      lVar6 = NpRemoveDataQueueEntry(param_1,'\0',in_stack_00000050);
      if (lVar6 != 0) {
        while( true ) {
          *(undefined4 *)(lVar6 + 0x30) = 0;
          plVar8 = (longlong *)(lVar6 + 0xa8);
          plVar7 = *(longlong **)(in_stack_00000050 + 8);
          if (*plVar7 == in_stack_00000050) break;
LAB_1c0012ddc:
          pcVar4 = (code *)swi(0x29);
          lVar6 = (*pcVar4)(3);
          puVar12 = puVar12 + 8;
        }
        *plVar8 = in_stack_00000050;
        *(longlong **)(lVar6 + 0xb0) = plVar7;
        *plVar7 = (longlong)plVar8;
        *(longlong **)(in_stack_00000050 + 8) = plVar8;
      }
      plVar7 = (longlong *)*param_1;
    }
  } while( true );
}



===== NpRemoveDataQueueEntry @ 1c0012f40 =====

longlong NpRemoveDataQueueEntry(longlong *param_1,char param_2,longlong param_3)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  
  if ((int)param_1[2] == 2) {
    lVar6 = 0;
  }
  else {
    plVar1 = (longlong *)*param_1;
    if (((longlong *)plVar1[1] != param_1) || (lVar6 = *plVar1, *(longlong **)(lVar6 + 8) != plVar1)
       ) {
LAB_1c0013100:
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      lVar6 = (*pcVar2)();
      return lVar6;
    }
    *param_1 = lVar6;
    *(longlong **)(lVar6 + 8) = param_1;
    *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) - (int)plVar1[5];
    *(int *)(param_1 + 3) = (int)param_1[3] + -1;
    if (((int)param_1[2] == 1) &&
       ((*(uint *)((longlong)param_1 + 0x1c) <= *(uint *)(param_1 + 4) &&
        (*(int *)((longlong)plVar1 + 0x24) != 0)))) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    *(int *)(param_1 + 4) = (int)param_1[4] - *(int *)((longlong)plVar1 + 0x24);
    if ((longlong *)*param_1 == param_1) {
      *(undefined4 *)(param_1 + 2) = 2;
      bVar3 = false;
    }
    lVar4 = plVar1[3];
    lVar6 = plVar1[2];
    if (lVar4 - 1U < 0xfffffffffffffffe) {
      SeDeleteClientSecurity(lVar4);
      ExFreePoolWithTag(lVar4);
    }
    if (lVar6 != 0) {
      LOCK();
      lVar4 = *(longlong *)(lVar6 + 0x68);
      *(longlong *)(lVar6 + 0x68) = 0;
      UNLOCK();
      if (lVar4 == 0) {
        *(undefined8 *)(lVar6 + 0x90) = 0;
        lVar6 = 0;
      }
    }
    if ((longlong *)param_1[5] == plVar1) {
      LOCK();
      *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 1;
      UNLOCK();
    }
    else {
      ExFreePoolWithTag(plVar1);
    }
    if (param_2 != '\0') {
      plVar1 = (longlong *)*param_1;
      while ((plVar1 != param_1 && (1 < *(uint *)(plVar1 + 4)))) {
        lVar4 = NpRemoveDataQueueEntry(param_1,'\0',param_3);
        if (lVar4 != 0) {
          *(undefined4 *)(lVar4 + 0x30) = 0;
          plVar5 = (longlong *)(lVar4 + 0xa8);
          plVar1 = *(longlong **)(param_3 + 8);
          if (*plVar1 != param_3) goto LAB_1c0013100;
          *plVar5 = param_3;
          *(longlong **)(lVar4 + 0xb0) = plVar1;
          *plVar1 = (longlong)plVar5;
          *(longlong **)(param_3 + 8) = plVar5;
        }
        plVar1 = (longlong *)*param_1;
      }
    }
    if (bVar3) {
      NpCompleteStalledWrites(param_1,param_3);
    }
  }
  *(undefined4 *)((longlong)param_1 + 0x24) = 0;
  return lVar6;
}



===== NpAddDataQueueEntry @ 1c0013110 =====

int NpAddDataQueueEntry(int param_1,longlong param_2,longlong param_3,int param_4,int param_5,
                       uint param_6,longlong param_7,void *param_8,int param_9)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  longlong *plVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  longlong *plVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint uVar15;
  void *pvVar16;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  longlong *local_38;
  longlong local_30;
  
  lVar8 = 0;
  local_30 = 0;
  if ((param_4 == 1) && (param_5 != 2)) {
    if (param_7 == 0) {
      pvVar16 = SystemReserved1[0xf];
    }
    else {
      pvVar16 = *(void **)(param_7 + 0x98);
    }
    if (((param_1 == 0) && (*(char *)(param_2 + 0x14) == '\x01')) &&
       (*(longlong *)(param_2 + 0x108) != -1)) {
      lVar8 = ExAllocatePool2(0x101,0x48,0x7346704e);
      if (lVar8 == 0) {
        return -0x3fffff66;
      }
      iVar7 = SeCreateClientSecurity(pvVar16,param_2 + 0xc,0,lVar8);
      if (iVar7 < 0) {
        ExFreePoolWithTag(lVar8);
        lVar8 = 0;
      }
    }
    else {
      iVar7 = 0;
    }
    local_30 = lVar8;
    if (iVar7 < 0) {
      return iVar7;
    }
  }
  lVar8 = local_30;
  puVar12 = auStack_58;
  puVar13 = auStack_58;
  puVar11 = auStack_58;
  plVar9 = (longlong *)0x0;
  if (param_5 != 0) {
    LOCK();
    puVar1 = (uint *)(param_3 + 0x28);
    uVar10 = *puVar1;
    *puVar1 = *puVar1 & 0xfffffffe;
    UNLOCK();
    if ((uVar10 & 1) != 0) {
      plVar9 = *(longlong **)(param_3 + 0x28);
    }
    if (plVar9 == (longlong *)0x0) goto LAB_1c00134c2;
    goto LAB_1c0013499;
  }
  uVar10 = 0x30;
  if ((param_4 != 0) && (uVar10 = param_6 + 0x30, uVar10 < param_6)) {
    if (local_30 - 1U < 0xfffffffffffffffe) {
      SeDeleteClientSecurity(local_30);
      ExFreePoolWithTag(lVar8,0);
    }
    return -0x3ffffff3;
  }
  uVar15 = *(int *)(param_3 + 0x1c) - *(int *)(param_3 + 0x20);
  uVar14 = param_6 - param_9;
  uVar6 = uVar14;
  if (uVar15 < uVar14) {
    uVar6 = uVar15;
  }
  if (uVar10 == 0x30) {
    LOCK();
    puVar1 = (uint *)(param_3 + 0x28);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 & 0xfffffffe;
    UNLOCK();
    if ((uVar3 & 1) != 0) {
      plVar9 = *(longlong **)(param_3 + 0x28);
    }
  }
  local_38 = plVar9;
  if ((plVar9 == (longlong *)0x0) &&
     (local_38 = (longlong *)ExAllocatePool2(0x41,uVar10,0x7246704e), local_38 == (longlong *)0x0))
  {
    if (lVar8 - 1U < 0xfffffffffffffffe) {
      SeDeleteClientSecurity(lVar8);
      ExFreePoolWithTag(lVar8,0);
      return -0x3fffff66;
    }
    return -0x3fffff66;
  }
  plVar9 = local_38;
  *(uint *)((longlong)local_38 + 0x24) = uVar6;
  local_38[2] = param_7;
  *(undefined4 *)(local_38 + 4) = 0;
  local_38[3] = lVar8;
  *(uint *)(local_38 + 5) = param_6;
  if (param_4 == 0) {
    param_5 = 0x103;
    puVar11 = auStack_58;
  }
  else {
    if (param_7 != 0) {
      param_8 = *(void **)(param_7 + 0x70);
    }
    memcpy(local_38 + 6,param_8,(ulonglong)param_6);
    if ((uVar15 < uVar14) && (param_7 != 0)) {
      param_5 = 0x103;
    }
    else {
      plVar9[2] = 0;
      param_5 = 0;
      puVar11 = auStack_58;
    }
  }
  while( true ) {
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + *(int *)((longlong)plVar9 + 0x24);
    *(int *)(param_3 + 0x10) = param_4;
    *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + (int)plVar9[5];
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
    if (*(int *)(puVar11 + 0xa0) != 0) {
      *(int *)(param_3 + 0x24) = *(int *)(puVar11 + 0xa0);
    }
    plVar4 = *(longlong **)(param_3 + 8);
    if (*plVar4 == param_3) break;
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3,0,param_3);
    puVar13 = puVar11 + 8;
LAB_1c00134c2:
    *(undefined8 *)(puVar13 + -8) = 0x1c00134d7;
    plVar9 = (longlong *)ExAllocatePool2(0x41,0x30,0x7246704e);
    puVar12 = puVar13;
    if (plVar9 == (longlong *)0x0) {
      *(undefined8 *)(puVar13 + -8) = 0x1c00134ee;
      NpFreeClientSecurityContext(lVar8);
      return -0x3fffff66;
    }
LAB_1c0013499:
    *(int *)(plVar9 + 4) = param_5;
    *(undefined4 *)((longlong)plVar9 + 0x24) = 0;
    plVar9[2] = param_7;
    *(undefined4 *)(plVar9 + 5) = *(undefined4 *)(puVar12 + 0x88);
    plVar9[3] = lVar8;
    param_5 = 0x103;
    puVar11 = puVar12;
  }
  *plVar9 = param_3;
  plVar9[1] = (longlong)plVar4;
  *plVar4 = (longlong)plVar9;
  *(longlong **)(param_3 + 8) = plVar9;
  if (param_5 == 0x103) {
    pbVar2 = (byte *)(*(longlong *)(param_7 + 0xb8) + 3);
    *pbVar2 = *pbVar2 | 1;
    *(longlong *)(param_7 + 0x88) = param_3;
    *(longlong **)(param_7 + 0x90) = plVar9;
    LOCK();
    *(code **)(param_7 + 0x68) = NpCancelDataQueueIrp;
    UNLOCK();
    if (*(char *)(param_7 + 0x44) != '\0') {
      LOCK();
      lVar8 = *(longlong *)(param_7 + 0x68);
      *(longlong *)(param_7 + 0x68) = 0;
      UNLOCK();
      if (lVar8 != 0) {
        *(undefined8 *)(puVar11 + -8) = 0x1c0013532;
        NpCancelDataQueueIrp(0,param_7);
      }
    }
  }
  return param_5;
}



===== NpInternalTransceive @ 1c0013540 =====

int NpInternalTransceive(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  code *pcVar5;
  int iVar6;
  void *_Dst;
  byte bVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  uint uVar14;
  ulonglong uVar15;
  uint local_res10 [4];
  uint local_res20;
  undefined1 auStackY_d8 [8];
  undefined1 auStackY_d0 [24];
  
  local_res10[0] = 0;
  if (*(char *)(param_2 + 0x40) == '\0') {
    lVar11 = *(longlong *)(param_2 + 0xb8);
    local_res20 = *(uint *)(lVar11 + 0x10);
    lVar2 = *(longlong *)(lVar11 + 0x20);
    lVar11 = *(longlong *)(lVar11 + 0x30);
    if ((*(byte *)(lVar11 + 0x20) & 1) == 0) {
      return -0x3fffff50;
    }
    if (**(short **)(lVar11 + 0x18) == 0x202) {
      uVar10 = *(ulonglong *)(lVar11 + 0x20) & 0xfffffffffffffffc;
      uVar15 = *(ulonglong *)(lVar11 + 0x20) >> 1;
      uVar14 = (uint)uVar15 & 1;
      uVar3 = *(undefined8 *)(param_2 + 0x98);
      lVar1 = uVar10 + 0x40;
      ExAcquirePushLockExclusiveEx(lVar1,0);
      puVar8 = auStackY_d8;
      if ((*(byte *)(lVar11 + 0x20) & 1) == 0) {
        iVar6 = -0x3fffff50;
      }
      else if (*(char *)(uVar10 + 8) == '\x03') {
        if ((uVar15 & 1) == 0) {
          bVar7 = *(byte *)(uVar10 + 9);
        }
        else {
          bVar7 = *(byte *)(uVar10 + 10);
        }
        plVar13 = (longlong *)((ulonglong)(-(uint)((uVar15 & 1) != 0) & 0x60) + 0x48 + uVar10);
        lVar11 = (-(ulonglong)((uVar15 & 1) != 0) & 0xffffffffffffffa0) + 0xa8 + uVar10;
        if (((short)*(undefined4 *)(*(longlong *)(uVar10 + 0x28) + 0x100) == 2) &&
           ((bVar7 & 1) != 0)) {
          if (*(int *)(lVar11 + 0x10) == 2) {
            iVar6 = NpWriteDataQueue(plVar13,(ulonglong)(bVar7 & 1),lVar2,local_res20,
                                     *(int *)(*(longlong *)(uVar10 + 0x28) + 0x104),local_res10);
            puVar8 = auStackY_d8;
            if (iVar6 == -0x3fffffea) {
              lVar11 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),1);
              if (lVar11 == 0) {
                iVar6 = -0x3fffff66;
                puVar8 = auStackY_d8;
                goto LAB_1c00136f5;
              }
              lVar4 = *(longlong *)(lVar11 + 0xb8);
              *(code **)(lVar4 + -0x10) = NpCompleteTransceiveIrp;
              *(undefined8 *)(lVar4 + -8) = 0;
              *(undefined1 *)(lVar4 + -0x45) = 0xe0;
              puVar8 = (undefined1 *)(*(longlong *)(lVar11 + 0xb8) + -0x48);
              uVar15 = (ulonglong)local_res10[0];
              if (local_res10[0] == 0) {
                *(undefined8 *)(lVar11 + 0x18) = 0;
              }
              else {
                _Dst = (void *)ExAllocatePool2(0x101,local_res10[0],0x7746704e);
                *(undefined8 *)(lVar11 + 0x18) = _Dst;
                if (_Dst == (void *)0x0) {
                  ExReleasePushLockExclusiveEx(lVar1,0);
                  IoFreeIrp(lVar11);
                  return -0x3fffff66;
                }
                memcpy(_Dst,(void *)((ulonglong)(local_res20 - local_res10[0]) + lVar2),uVar15);
                *(undefined4 *)(lVar11 + 0x10) = 0x30;
              }
              *(char *)(lVar11 + 0x43) = *(char *)(lVar11 + 0x43) + -1;
              *(undefined1 **)(lVar11 + 0xb8) = puVar8;
              *(undefined8 *)(lVar11 + 0x98) = uVar3;
              *puVar8 = 4;
              *(undefined **)(lVar11 + 0x48) = &DAT_1c0006090;
              iVar6 = NpAddDataQueueEntry(uVar14,uVar10,(longlong)plVar13,1,1,local_res10[0],lVar11,
                                          (void *)0x0,0);
              puVar9 = auStackY_d8;
              puVar8 = auStackY_d8;
              if (iVar6 != 0x103) {
                *(int *)(lVar11 + 0x30) = iVar6;
                plVar12 = (longlong *)(lVar11 + 0xa8);
                plVar13 = *(longlong **)(param_3 + 8);
                if (*plVar13 != param_3) {
                  pcVar5 = (code *)swi(0x29);
                  plVar13 = (longlong *)(*pcVar5)(3);
                  puVar9 = auStackY_d0;
                }
                *plVar12 = param_3;
                *(longlong **)(lVar11 + 0xb0) = plVar13;
                *plVar13 = (longlong)plVar12;
                *(longlong **)(param_3 + 8) = plVar12;
                puVar8 = puVar9;
              }
              lVar11 = *(longlong *)(puVar8 + 0x68);
            }
            if (-1 < iVar6) {
              *(undefined4 *)(puVar8 + 0x40) = 0;
              *(undefined8 *)(puVar8 + 0x38) = 0;
              *(longlong *)(puVar8 + 0x30) = param_2;
              *(undefined4 *)(puVar8 + 0x28) = *(undefined4 *)(puVar8 + 0x50);
              *(undefined4 *)(puVar8 + 0x20) = 1;
              *(undefined8 *)(puVar8 + -8) = 0x1c00136f3;
              iVar6 = NpAddDataQueueEntry(uVar14,uVar10,lVar11,0,*(int *)(puVar8 + 0x20),
                                          *(uint *)(puVar8 + 0x28),*(longlong *)(puVar8 + 0x30),
                                          *(void **)(puVar8 + 0x38),*(int *)(puVar8 + 0x40));
            }
          }
          else {
            iVar6 = -0x3fffff52;
            puVar8 = auStackY_d8;
          }
        }
        else {
          iVar6 = -0x3fffff4c;
          puVar8 = auStackY_d8;
        }
      }
      else {
        iVar6 = -0x3fffff53;
        puVar8 = auStackY_d8;
      }
LAB_1c00136f5:
      *(undefined8 *)(puVar8 + -8) = 0x1c0013701;
      ExReleasePushLockExclusiveEx(lVar1,0);
      return iVar6;
    }
  }
  return -0x3ffffff3;
}



===== NpInternalRead @ 1c001393c =====

int NpInternalRead(undefined8 param_1,longlong param_2,char param_3,longlong param_4)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  bool bVar13;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar14;
  undefined8 local_48 [2];
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((*(byte *)(lVar4 + 0x20) & 1) == 0) {
    return -0x3fffff50;
  }
  if (**(short **)(lVar4 + 0x18) != 0x202) {
    return -0x3ffffff3;
  }
  uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar9 = *(ulonglong *)(lVar4 + 0x20) & 0xfffffffffffffffc;
  uVar11 = *(ulonglong *)(lVar4 + 0x20) >> 1;
  uVar10 = (uint)uVar11 & 1;
  uVar5 = *(undefined8 *)(param_2 + 0x18);
  plVar12 = (longlong *)(uVar9 + 0xa8 + (-(ulonglong)((uVar11 & 1) != 0) & 0xffffffffffffffa0));
  ExAcquirePushLockExclusiveEx(uVar9 + 0x40,0);
  if (((*(byte *)(lVar4 + 0x20) & 1) == 0) || (cVar1 = *(char *)(uVar9 + 8), cVar1 == '\x01')) {
    iVar7 = -0x3fffff50;
  }
  else if (cVar1 == '\x02') {
    iVar7 = -0x3fffff4d;
  }
  else {
    if ((cVar1 != '\x03') && (cVar1 != '\x04')) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x25,0xd06fa,cVar1,0,0);
    }
    uVar6 = *(uint *)(*(longlong *)(uVar9 + 0x28) + 0x100) & 0xffff;
    if ((uVar11 & 1) == 0) {
      bVar13 = uVar6 == 0;
    }
    else {
      bVar13 = uVar6 == 1;
    }
    if (bVar13) {
      iVar7 = -0x3ffffff3;
    }
    else {
      bVar2 = *(byte *)((ulonglong)uVar10 + 9 + uVar9);
      if ((param_3 == '\x01') && ((bVar2 & 1) == 0)) {
        iVar7 = -0x3fffff4c;
      }
      else if ((int)plVar12[2] == 1) {
        puVar8 = NpReadDataQueue(local_48,plVar12,'\0',param_3,uVar5,uVar3,
                                 CONCAT44(uVar14,(uint)bVar2) & 0xffffffff00000001,uVar9,param_4);
        uVar5 = puVar8[1];
        *(undefined8 *)(param_2 + 0x30) = *puVar8;
        *(undefined8 *)(param_2 + 0x38) = uVar5;
        iVar7 = *(int *)(param_2 + 0x30);
        *(ulonglong *)(param_2 + 0x58) =
             (ulonglong)
             (uint)(*(int *)((longlong)plVar12 + 0x14) - *(int *)((longlong)plVar12 + 0x24));
      }
      else if (cVar1 == '\x04') {
        iVar7 = -0x3ffffeb5;
      }
      else if ((bVar2 & 2) == 0) {
        iVar7 = NpAddDataQueueEntry(uVar10,uVar9,(longlong)plVar12,0,1,uVar3,param_2,(void *)0x0,0);
      }
      else {
        iVar7 = -0x3fffff27;
      }
    }
  }
  ExReleasePushLockExclusiveEx(uVar9 + 0x40,0);
  return iVar7;
}



===== NpFsdDirectoryControl @ 1c0013b60 =====

uint NpFsdDirectoryControl(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((((*(byte *)(lVar2 + 0x20) & 1) == 0) || (**(short **)(lVar2 + 0x18) != 0x206)) ||
     (uVar5 = *(ulonglong *)(lVar2 + 0x20) & 0xfffffffffffffffe, uVar5 == 0)) {
    uVar3 = 0xc000000d;
  }
  else {
    cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
    if (cVar1 == '\x01') {
      uVar3 = NpQueryDirectory(*(longlong *)(param_1 + 0x40),uVar5,param_2);
    }
    else if (cVar1 == '\x02') {
      uVar4 = NpNotifyChangeDirectory(*(longlong *)(param_1 + 0x40),uVar5,param_2);
      uVar3 = (uint)uVar4;
    }
    else {
      uVar3 = 0xc0000010;
    }
    if (uVar3 == 0x103) {
      return 0x103;
    }
  }
  *(uint *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,2);
  return uVar3;
}



===== NpQueryDirectory @ 1c0013c10 =====

uint NpQueryDirectory(longlong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  longlong lVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  char cVar5;
  ushort uVar6;
  undefined2 *puVar7;
  longlong lVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  undefined2 *puVar14;
  uint uVar15;
  uint uVar16;
  undefined2 *puVar17;
  uint uVar18;
  uint local_88;
  uint local_84;
  uint local_7c;
  ulonglong local_78;
  undefined *puStack_70;
  uint local_68;
  longlong local_60;
  uint local_58;
  int local_54;
  undefined2 *local_50;
  undefined2 *local_48;
  undefined8 *local_40;
  
  lVar8 = *(longlong *)(param_3 + 0xb8);
  local_58 = *(uint *)(lVar8 + 8);
  local_7c = *(uint *)(lVar8 + 0x20);
  local_54 = *(int *)(lVar8 + 0x18);
  bVar1 = *(byte *)(lVar8 + 2);
  lVar2 = *(longlong *)(lVar8 + 0x30);
  puVar3 = *(ulonglong **)(lVar8 + 0x10);
  if (puVar3 == (ulonglong *)0x0) {
    puVar9 = (undefined *)0x0;
    uVar4 = local_78;
    uVar11 = 0;
  }
  else {
    puVar9 = (undefined *)puVar3[1];
    if (((uint)*puVar3 & 1) != 0) {
      return 0xc000000d;
    }
    local_78._0_2_ = (ushort)*puVar3;
    uVar4 = *puVar3;
    puStack_70 = puVar9;
    uVar11 = (ushort)local_78;
  }
  local_78 = uVar4;
  puVar14 = (undefined2 *)0x0;
  local_60 = *(longlong *)(param_3 + 0x70);
  local_68 = 0;
  local_84 = 0;
  if (local_54 == 3) {
    local_88 = 0x5e;
  }
  else if (local_54 == 1) {
    local_88 = 0x40;
  }
  else if (local_54 == 2) {
    local_88 = 0x44;
  }
  else {
    if (local_54 != 0xc) {
      return 0xc0000003;
    }
    local_88 = 0xc;
  }
  local_50 = (undefined2 *)0x0;
  puVar7 = puVar14;
  if (*(longlong *)(param_2 + 0x10) == 0) {
    if (uVar11 == 0) {
      uVar6 = 2;
      puVar9 = &DAT_1c0006010;
    }
    else {
      uVar6 = uVar11;
    }
    local_78 = (ulonglong)uVar6;
    puStack_70 = puVar9;
    puVar7 = (undefined2 *)ExAllocatePool2(0x101,(ulonglong)uVar6 + 0x10,0x7146704e);
    if (puVar7 == (undefined2 *)0x0) {
      return 0xc000009a;
    }
    *puVar7 = 0;
    puVar7[1] = (ushort)local_78;
    *(undefined2 **)(puVar7 + 4) = puVar7 + 8;
    local_50 = puVar7;
    if (((NpCompatFlags & 1) == 0) && (uVar11 != 0)) {
      RtlUpcaseUnicodeString(puVar7,&local_78,0);
    }
    else {
      memcpy(puVar7 + 8,puStack_70,local_78 & 0xffff);
      *puVar7 = (ushort)local_78;
    }
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1 + 0xc0,0);
  ExAcquirePushLockExclusiveEx(param_2 + 8,0);
  local_48 = puVar7;
  if ((*(byte *)(lVar2 + 0x20) & 1) != 0) {
    puVar17 = *(undefined2 **)(param_2 + 0x10);
    if (puVar17 == (undefined2 *)0x0) {
      local_48 = (undefined2 *)0x0;
      *(undefined2 **)(param_2 + 0x10) = puVar7;
      puVar17 = puVar7;
    }
    else {
      local_50 = puVar17;
    }
    if ((bVar1 & 1) == 0) {
      if ((bVar1 & 4) == 0) {
        local_7c = *(uint *)(param_2 + 4);
      }
    }
    else {
      local_7c = 0;
    }
    local_40 = (undefined8 *)(param_1 + 200);
    puVar10 = (undefined8 *)*local_40;
LAB_1c0013d60:
    do {
      if (puVar10 == local_40) goto LAB_1c001408f;
      cVar5 = FsRtlIsNameInExpression(puVar17,puVar10 + 3,1,0);
      if (cVar5 != '\0') {
        uVar18 = (uint)puVar14;
        if (local_7c <= uVar18) {
          uVar12 = local_58 - local_84;
          if ((local_84 != 0) &&
             ((uVar12 < *(ushort *)(puVar10 + 3) + local_88 || (local_58 < local_84)))) {
            uVar15 = 0;
            goto LAB_1c0013f48;
          }
          uVar13 = (uint)*(ushort *)(puVar10 + 3);
          uVar16 = *(ushort *)(puVar10 + 3) + local_88;
          if (uVar12 < uVar16) {
            uVar13 = uVar12 - local_88;
          }
          uVar15 = -(uint)(uVar12 < uVar16) & 0x80000005;
          memset((void *)((ulonglong)local_84 + local_60),0,(ulonglong)local_88);
          if (((local_54 == 1) || (local_54 == 2)) || (local_54 == 3)) {
            lVar8 = (ulonglong)local_84 + local_60;
            if (*(short *)(puVar10 + -0x11) == 0x202) {
              *(ulonglong *)(lVar8 + 0x28) = (ulonglong)*(uint *)(puVar10 + -2);
              *(ulonglong *)(lVar8 + 0x30) = (ulonglong)*(uint *)((longlong)puVar10 + 0x74);
            }
            else {
              if (*(short *)(puVar10 + -0x11) != 0x207) goto LAB_1c0013e7e;
              *(ulonglong *)(lVar8 + 0x28) = (ulonglong)*(uint *)(puVar10 + -2);
              *(undefined8 *)(lVar8 + 0x30) = 1;
            }
            *(undefined4 *)(lVar8 + 0x38) = 0x80;
            *(uint *)(lVar8 + 0x3c) = (uint)*(ushort *)(puVar10 + 3);
          }
          else {
            *(uint *)((ulonglong)local_84 + 8 + local_60) = (uint)*(ushort *)(puVar10 + 3);
          }
LAB_1c0013e7e:
          memcpy((void *)((ulonglong)(local_88 + local_84) + local_60),(void *)puVar10[4],
                 (ulonglong)uVar13);
          *(uint *)((ulonglong)local_68 + local_60) = local_84 - local_68;
          *(ulonglong *)(param_3 + 0x38) = (ulonglong)(uVar13 + local_88 + local_84);
          if (uVar12 < uVar16) goto LAB_1c0013f48;
          *(uint *)(param_2 + 4) = uVar18 + 1;
          if ((bVar1 & 2) != 0) {
            uVar15 = 0;
            goto LAB_1c0013f48;
          }
          local_68 = local_84;
          local_84 = local_84 + (uVar13 + local_88 + 7 & 0xfffffff8);
          puVar14 = (undefined2 *)(ulonglong)(uVar18 + 1);
          puVar10 = (undefined8 *)*puVar10;
          puVar17 = local_50;
          goto LAB_1c0013d60;
        }
        puVar14 = (undefined2 *)(ulonglong)(uVar18 + 1);
      }
      puVar10 = (undefined8 *)*puVar10;
    } while( true );
  }
  uVar15 = 0xc000000d;
LAB_1c0013f48:
  ExReleasePushLockExclusiveEx(param_2 + 8,0);
  ExReleasePushLockSharedEx(param_1 + 0xc0,0);
  KeLeaveCriticalRegion();
  if (local_48 != (undefined2 *)0x0) {
    ExFreePoolWithTag(local_48,0);
  }
  return uVar15;
LAB_1c001408f:
  uVar15 = 0;
  if (local_84 == 0) {
    uVar15 = 0x80000006;
  }
  goto LAB_1c0013f48;
}



===== NpNotifyChangeDirectory @ 1c0014160 =====

undefined8 NpNotifyChangeDirectory(longlong param_1,undefined8 param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong lVar6;
  longlong *plVar7;
  
  lVar6 = *(longlong *)(param_3 + 0xb8);
  iVar3 = *(int *)(lVar6 + 8);
  if (((iVar3 != 0) && (*(longlong *)(param_3 + 8) == 0)) && (*(longlong *)(param_3 + 0x18) == 0)) {
    if (*(longlong *)(param_3 + 0x70) == 0) {
      return 0xc000000d;
    }
    if (*(char *)(param_3 + 0x40) == '\x01') {
      ProbeForWrite(*(longlong *)(param_3 + 0x70),iVar3,4);
    }
    lVar6 = IoAllocateMdl(*(undefined8 *)(param_3 + 0x70),*(undefined4 *)(lVar6 + 8),0,0,param_3);
    if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000009a);
    }
    MmProbeAndLockPages(lVar6,*(undefined1 *)(param_3 + 0x40),1);
  }
  KeEnterCriticalRegion();
  lVar6 = param_1 + 0xa8;
  ExAcquirePushLockExclusiveEx(lVar6,0);
  LOCK();
  *(code **)(param_3 + 0x68) = NpCancelChangeNotifyIrp;
  UNLOCK();
  if (*(char *)(param_3 + 0x44) != '\0') {
    LOCK();
    lVar2 = *(longlong *)(param_3 + 0x68);
    *(longlong *)(param_3 + 0x68) = 0;
    UNLOCK();
    if (lVar2 != 0) {
      ExReleasePushLockExclusiveEx(lVar6,0);
      KeLeaveCriticalRegion();
      return 0xc0000120;
    }
  }
  pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  *(undefined8 *)(param_3 + 0x78) = param_2;
  plVar7 = (longlong *)(param_3 + 0xa8);
  plVar4 = *(longlong **)(param_1 + 0xb8);
  if (*plVar4 == param_1 + 0xb0) {
    *plVar7 = param_1 + 0xb0;
    *(longlong **)(param_3 + 0xb0) = plVar4;
    *plVar4 = (longlong)plVar7;
    *(longlong **)(param_1 + 0xb8) = plVar7;
    ExReleasePushLockExclusiveEx(lVar6,0);
    KeLeaveCriticalRegion();
    return 0x103;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  return 0xc000000d;
}



===== NpCompleteStalledWrites @ 1c0014340 =====

void NpCompleteStalledWrites(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar9 = *(int *)((longlong)param_1 + 0x1c) - *(int *)(param_1 + 4);
  iVar7 = *(int *)((longlong)param_1 + 0x24);
  puVar3 = (undefined8 *)*param_1;
  while ((puVar3 != param_1 && (uVar9 != 0))) {
    lVar4 = puVar3[2];
    if ((*(int *)(puVar3 + 4) == 0) && (lVar4 != 0)) {
      uVar2 = *(uint *)((longlong)puVar3 + 0x24);
      uVar11 = *(int *)(puVar3 + 5) - iVar7;
      if (uVar2 < uVar11) {
        uVar10 = (*(int *)(puVar3 + 5) - uVar2) - iVar7;
        if (uVar9 < uVar10) {
          uVar10 = uVar9;
        }
        uVar9 = uVar9 - uVar10;
        *(uint *)((longlong)puVar3 + 0x24) = uVar2 + uVar10;
        if (uVar2 + uVar10 == uVar11) {
          LOCK();
          lVar1 = *(longlong *)(lVar4 + 0x68);
          *(longlong *)(lVar4 + 0x68) = 0;
          UNLOCK();
          if (lVar1 != 0) {
            puVar3[2] = 0;
            *(ulonglong *)(lVar4 + 0x38) = (ulonglong)*(uint *)(puVar3 + 5);
            *(undefined4 *)(lVar4 + 0x30) = 0;
            plVar8 = (longlong *)(lVar4 + 0xa8);
            plVar5 = *(longlong **)(param_2 + 8);
            if (*plVar5 != param_2) {
              pcVar6 = (code *)swi(0x29);
              (*pcVar6)(3);
              pcVar6 = (code *)swi(3);
              (*pcVar6)();
              return;
            }
            *plVar8 = param_2;
            *(longlong **)(lVar4 + 0xb0) = plVar5;
            *plVar5 = (longlong)plVar8;
            *(longlong **)(param_2 + 8) = plVar8;
          }
        }
      }
    }
    puVar3 = (undefined8 *)*puVar3;
    iVar7 = 0;
  }
  *(uint *)(param_1 + 4) = *(int *)((longlong)param_1 + 0x1c) - uVar9;
  return;
}



===== NpFsdQuerySecurityInfo @ 1c0014420 =====

int NpFsdQuerySecurityInfo(longlong param_1,longlong param_2)

{
  int iVar1;
  
  KeEnterCriticalRegion();
  iVar1 = NpCommonQuerySecurityInfo(param_1,param_2);
  KeLeaveCriticalRegion();
  if (iVar1 != 0x103) {
    *(int *)(param_2 + 0x30) = iVar1;
    IofCompleteRequest(param_2,2);
  }
  return iVar1;
}



===== NpCommonQuerySecurityInfo @ 1c0014488 =====

int NpCommonQuerySecurityInfo(longlong param_1,longlong param_2)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  short *psVar5;
  char cVar6;
  int iVar7;
  short *psVar8;
  undefined1 uVar9;
  longlong local_res10;
  
  local_res10 = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(lVar2 + 0x30);
  if ((*(byte *)(lVar3 + 0x20) & 1) == 0) {
    return -0x3fffff50;
  }
  lVar4 = *(longlong *)(param_1 + 0x40);
  psVar5 = *(short **)(lVar3 + 0x18);
  sVar1 = *psVar5;
  if (sVar1 == 0x202) {
    psVar8 = psVar5 + 0x40;
    ExAcquirePushLockSharedEx(psVar8,0);
    if ((*(byte *)(lVar3 + 0x20) & 1) == 0) {
      ExReleasePushLockSharedEx(psVar8,0);
      return -0x3fffff50;
    }
LAB_1c0014621:
    local_res10 = *(longlong *)(psVar5 + 0x4c);
  }
  else {
    if (sVar1 == 0x203) {
      psVar8 = (short *)(lVar4 + 0xc0);
      ExAcquirePushLockSharedEx(psVar8,0);
      goto LAB_1c0014621;
    }
    if (sVar1 != 0x206) {
      return -0x3ffffff3;
    }
    if ((*(byte *)(lVar2 + 2) & 1) == 0) {
      uVar9 = *(undefined1 *)(param_2 + 0x40);
    }
    else {
      uVar9 = 1;
    }
    cVar6 = SeSinglePrivilegeCheck(*(undefined8 *)(*(longlong *)SeExports_exref + 0x28),uVar9);
    if (cVar6 == '\0') {
      return -0x3ffffff3;
    }
    psVar8 = (short *)(lVar4 + 0x80);
    ExAcquirePushLockSharedEx(psVar8,0);
    local_res10 = *(longlong *)(lVar4 + 0x88);
    if (local_res10 == 0) goto LAB_1c0014552;
  }
  ObReferenceSecurityDescriptor(local_res10,1);
LAB_1c0014552:
  ExReleasePushLockSharedEx(psVar8,0);
  iVar7 = SeQuerySecurityDescriptorInfo
                    (lVar2 + 8,*(undefined8 *)(param_2 + 0x70),lVar2 + 0x10,&local_res10);
  if (local_res10 != 0) {
    ObDereferenceSecurityDescriptor(local_res10,1);
  }
  if (iVar7 == -0x3fffffdd) {
    iVar7 = -0x7ffffffb;
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar2 + 0x10);
  }
  return iVar7;
}



===== NpFsdQueryInformation @ 1c0014640 =====

ulonglong NpFsdQueryInformation(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  
  KeEnterCriticalRegion();
  uVar1 = NpCommonQueryInformation(param_1,param_2);
  KeLeaveCriticalRegion();
  if ((int)uVar1 != 0x103) {
    *(int *)(param_2 + 0x30) = (int)uVar1;
    IofCompleteRequest(param_2,2);
  }
  return uVar1 & 0xffffffff;
}



===== NpCommonQueryInformation @ 1c00146a0 =====

ulonglong NpCommonQueryInformation(undefined8 param_1,longlong param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined8 local_res8;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  puVar5 = *(ulonglong **)(param_2 + 0x18);
  lVar6 = *(longlong *)(lVar4 + 0x30);
  iVar2 = *(int *)(lVar4 + 8);
  iVar3 = *(int *)(lVar4 + 0x10);
  local_res8._4_4_ = (undefined4)((ulonglong)param_1 >> 0x20);
  local_res8 = CONCAT44(local_res8._4_4_,iVar2);
  sVar1 = **(short **)(lVar6 + 0x18);
  if (sVar1 == 0x202) {
    uVar11 = *(ulonglong *)(lVar6 + 0x20) & 0xfffffffffffffffc;
    uVar12 = (uint)(*(ulonglong *)(lVar6 + 0x20) >> 1) & 1;
  }
  else {
    if (sVar1 != 0x206) {
      return 0xc000000d;
    }
    uVar11 = 0;
    uVar12 = 0;
  }
  if ((*(byte *)(lVar6 + 0x20) & 1) == 0) {
    return 0xc00000b0;
  }
  if (iVar3 == 4) {
    local_res8 = (ulonglong)(iVar2 - 0x28);
    *(undefined4 *)((longlong)puVar5 + 0x24) = 0;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    *(uint *)(puVar5 + 4) = (-(uint)(uVar11 != 0) & 0x70) + 0x10;
  }
  else {
    if (iVar3 == 5) {
      uVar7 = NpQueryStandardInfo(lVar6,uVar11,puVar5,(int *)&local_res8,uVar12);
      uVar12 = (uint)uVar7;
      goto LAB_1c001477e;
    }
    if (iVar3 == 6) {
      local_res8 = (ulonglong)(iVar2 - 8);
      uVar10 = 0;
      *puVar5 = 0;
      if (uVar11 != 0) {
        uVar10 = (ulonglong)*(int *)(uVar11 + 0x1c8);
      }
      *puVar5 = uVar10;
    }
    else {
      if (iVar3 != 7) {
        if (iVar3 == 9) {
          uVar12 = NpQueryNameInfo(lVar6,uVar11,(uint *)puVar5,(uint *)&local_res8);
        }
        else if (iVar3 == 0xe) {
          uVar7 = NpQueryPositionInfo(lVar6,uVar11,puVar5,(int *)&local_res8,uVar12);
          uVar12 = (uint)uVar7;
        }
        else if (iVar3 == 0x12) {
          local_res8._0_4_ = iVar2 - 0x34;
          *(undefined4 *)((longlong)puVar5 + 0x24) = 0;
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0;
          *(uint *)(puVar5 + 4) = (-(uint)(uVar11 != 0) & 0x70) + 0x10;
          uVar7 = NpQueryStandardInfo(lVar6,uVar11,puVar5 + 5,(int *)&local_res8,uVar12);
          uVar9 = 0;
          if ((int)(uint)uVar7 < 0) {
            uVar9 = (uint)uVar7;
          }
          uVar10 = 0;
          puVar5[8] = 0;
          if (uVar11 != 0) {
            uVar10 = (ulonglong)*(int *)(uVar11 + 0x1c8);
          }
          puVar5[8] = uVar10;
          local_res8 = CONCAT44(local_res8._4_4_,(uint)local_res8 - 0xc);
          *(undefined4 *)(puVar5 + 9) = 0;
          uVar8 = NpQueryPositionInfo(lVar6,uVar11,puVar5 + 10,(int *)&local_res8,uVar12);
          uVar10 = (ulonglong)uVar9;
          if ((int)uVar8 < 0) {
            uVar10 = uVar8 & 0xffffffff;
          }
          uVar12 = NpQueryNameInfo(lVar6,uVar11,(uint *)(puVar5 + 0xc),(uint *)&local_res8);
          if (-1 < (int)uVar12) goto LAB_1c0014780;
        }
        else if (iVar3 == 0x17) {
          if (sVar1 != 0x202) goto LAB_1c00147ac;
          uVar7 = NpQueryPipeInfo(lVar6,uVar11,(uint *)puVar5,(int *)&local_res8,uVar12);
          uVar12 = (uint)uVar7;
        }
        else {
          if ((iVar3 != 0x18) || (sVar1 != 0x202)) {
LAB_1c00147ac:
            uVar10 = 0xc000000d;
            goto LAB_1c0014780;
          }
          uVar7 = NpQueryPipeLocalInfo(lVar6,uVar11,(uint *)puVar5,(int *)&local_res8,uVar12);
          uVar12 = (uint)uVar7;
        }
LAB_1c001477e:
        uVar10 = (ulonglong)uVar12;
        goto LAB_1c0014780;
      }
      local_res8 = (ulonglong)(iVar2 - 4);
      *(undefined4 *)puVar5 = 0;
    }
  }
  uVar10 = 0;
LAB_1c0014780:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)(*(int *)(lVar4 + 8) - (uint)local_res8);
  return uVar10;
}



===== NpQueryPipeLocalInfo @ 1c0014958 =====

undefined8
NpQueryPipeLocalInfo(longlong param_1,longlong param_2,uint *param_3,int *param_4,uint param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  
  *param_4 = *param_4 + -0x28;
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  param_3[8] = 0;
  param_3[9] = 0;
  lVar1 = *(longlong *)(param_2 + 0x28);
  uVar2 = 0;
  ExAcquirePushLockSharedEx(lVar1 + 0x80,0);
  ExAcquirePushLockSharedEx(param_2 + 0x40,0);
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    uVar2 = 0xc00000b0;
  }
  else {
    if (*(int *)(lVar1 + 0x104) != 1) {
      *param_3 = *param_3 | 1;
    }
    if (*(int *)(lVar1 + 0x108) == 0) {
      *param_3 = *param_3 | 2;
    }
    param_3[1] = *(uint *)(lVar1 + 0x100) & 0xffff;
    param_3[2] = *(uint *)(lVar1 + 0xfc);
    param_3[3] = *(uint *)(lVar1 + 0x78);
    param_3[4] = *(uint *)(param_2 + 100);
    param_3[6] = *(uint *)(param_2 + 0xc4);
    param_3[8] = (uint)*(byte *)(param_2 + 8);
    param_3[9] = param_5;
    if (param_5 == 0) {
      if (*(int *)(param_2 + 0xb8) == 1) {
        param_3[5] = *(int *)(param_2 + 0xbc) - *(int *)(param_2 + 0xcc);
      }
      param_3[7] = *(int *)(param_2 + 100) - *(int *)(param_2 + 0x68);
    }
    else {
      if (*(int *)(param_2 + 0x58) == 1) {
        param_3[5] = *(int *)(param_2 + 0x5c) - *(int *)(param_2 + 0x6c);
      }
      param_3[7] = *(int *)(param_2 + 0xc4) - *(int *)(param_2 + 200);
    }
  }
  ExReleasePushLockSharedEx(param_2 + 0x40,0);
  ExReleasePushLockSharedEx(lVar1 + 0x80,0);
  return uVar2;
}



===== NpQueryNameInfo @ 1c0014abc =====

uint NpQueryNameInfo(longlong param_1,longlong param_2,uint *param_3,uint *param_4)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = *param_4;
  uVar3 = uVar5 - 4;
  uVar6 = 0;
  *param_4 = uVar3;
  if (param_2 == 0) {
    if (uVar3 < 2) {
      uVar6 = 0x80000005;
    }
    else {
      *(undefined2 *)(param_3 + 1) = 0x5c;
      *param_4 = uVar5 - 6;
      *param_3 = 2;
    }
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0x28);
    if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
      uVar6 = 0xc00000b0;
    }
    else {
      uVar1 = *(ushort *)(lVar2 + 0xa0);
      uVar5 = uVar1 + 2;
      if (uVar1 == 0) {
        uVar5 = 0;
      }
      uVar4 = uVar3;
      if (uVar3 >= uVar5) {
        uVar4 = uVar5;
      }
      uVar6 = -(uint)(uVar3 < uVar5) & 0x80000005;
      if (1 < uVar4) {
        *(undefined2 *)(param_3 + 1) = 0x5c;
        memcpy((void *)((longlong)param_3 + 6),*(void **)(lVar2 + 0xa8),(ulonglong)uVar4 - 2);
      }
      *param_3 = uVar5;
      *param_4 = uVar3 - uVar4;
    }
  }
  return uVar6;
}



===== NpQueryStandardInfo @ 1c0014b94 =====

undefined8
NpQueryStandardInfo(longlong param_1,longlong param_2,ulonglong *param_3,int *param_4,int param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  
  *param_4 = *param_4 + -0x18;
  uVar2 = 0;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_3 + 2) = 1;
    *(undefined1 *)((longlong)param_3 + 0x15) = 1;
  }
  else {
    lVar1 = param_2 + 0x40;
    ExAcquirePushLockSharedEx(lVar1,0);
    if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
      ExReleasePushLockSharedEx(lVar1,0);
      uVar2 = 0xc00000b0;
    }
    else {
      *param_3 = (ulonglong)(uint)(*(int *)(param_2 + 0xc4) + *(int *)(param_2 + 100));
      if (*(int *)((-(ulonglong)(param_5 != 0) & 0xffffffffffffffa0) + 0xb8 + param_2) == 1) {
        param_3[1] = (ulonglong)
                     (uint)(*(int *)((-(ulonglong)(param_5 != 0) & 0xffffffffffffffa0) + 0xbc +
                                    param_2) -
                           *(int *)((-(ulonglong)(param_5 != 0) & 0xffffffffffffffa0) + 0xcc +
                                   param_2));
      }
      ExReleasePushLockSharedEx(lVar1,0);
      uVar2 = 0;
      *(undefined4 *)(param_3 + 2) = 1;
      *(undefined2 *)((longlong)param_3 + 0x14) = 1;
    }
  }
  return uVar2;
}



===== NpQueryPositionInfo @ 1c0014c98 =====

undefined8
NpQueryPositionInfo(longlong param_1,longlong param_2,ulonglong *param_3,int *param_4,int param_5)

{
  undefined8 uVar1;
  
  *param_4 = *param_4 + -8;
  uVar1 = 0;
  *param_3 = 0;
  if (param_2 != 0) {
    ExAcquirePushLockSharedEx();
    if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
      uVar1 = 0xc00000b0;
    }
    else {
      uVar1 = 0;
      if (*(int *)((-(ulonglong)(param_5 != 0) & 0xffffffffffffffa0) + 0xb8 + param_2) == 1) {
        *param_3 = (ulonglong)
                   (uint)(*(int *)((-(ulonglong)(param_5 != 0) & 0xffffffffffffffa0) + 0xbc +
                                  param_2) -
                         *(int *)((-(ulonglong)(param_5 != 0) & 0xffffffffffffffa0) + 0xcc + param_2
                                 ));
      }
    }
    ExReleasePushLockSharedEx(param_2 + 0x40,0);
  }
  return uVar1;
}



===== NpQueryPipeInfo @ 1c0014d68 =====

undefined8
NpQueryPipeInfo(longlong param_1,longlong param_2,uint *param_3,int *param_4,uint param_5)

{
  undefined8 uVar1;
  
  *param_4 = *param_4 + -8;
  param_3[0] = 0;
  param_3[1] = 0;
  uVar1 = 0;
  ExAcquirePushLockSharedEx(param_2 + 0x40,0);
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    uVar1 = 0xc00000b0;
  }
  else {
    *param_3 = *(byte *)((ulonglong)param_5 + 9 + param_2) & 1;
    param_3[1] = *(byte *)((ulonglong)param_5 + 9 + param_2) >> 1 & 1;
  }
  ExReleasePushLockSharedEx(param_2 + 0x40,0);
  return uVar1;
}



===== NpFsdSetInformation @ 1c0014e10 =====

ulonglong NpFsdSetInformation(undefined8 param_1,longlong param_2)

{
  undefined8 ****ppppuVar1;
  ulonglong uVar2;
  undefined8 ****ppppuVar3;
  undefined8 ****local_18;
  undefined8 ****local_10;
  
  local_10 = &local_18;
  local_18 = &local_18;
  KeEnterCriticalRegion();
  uVar2 = NpCommonSetInformation(param_1,param_2);
  ppppuVar3 = local_18;
  while ((undefined8 *****)ppppuVar3 != &local_18) {
    ppppuVar1 = ppppuVar3 + -0x15;
    ppppuVar3 = (undefined8 ****)*ppppuVar3;
    IofCompleteRequest(ppppuVar1,2);
  }
  KeLeaveCriticalRegion();
  if ((int)uVar2 != 0x103) {
    *(int *)(param_2 + 0x30) = (int)uVar2;
    IofCompleteRequest(param_2,2);
  }
  return uVar2 & 0xffffffff;
}



===== NpCommonSetInformation @ 1c0014eb4 =====

undefined8 NpCommonSetInformation(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((*(byte *)(lVar2 + 0x20) & 1) == 0) {
    return 0xc00000b0;
  }
  if (**(short **)(lVar2 + 0x18) == 0x202) {
    iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    if (iVar1 == 0x17) {
      uVar3 = NpSetPipeInfo(lVar2,*(ulonglong *)(lVar2 + 0x20) & 0xfffffffffffffffc,
                            *(uint **)(param_2 + 0x18),(uint)(*(ulonglong *)(lVar2 + 0x20) >> 1) & 1
                           );
      return uVar3;
    }
    if (iVar1 == 4) {
      return 0;
    }
  }
  return 0xc000000d;
}



===== NpSetPipeInfo @ 1c0014f24 =====

undefined8 NpSetPipeInfo(longlong param_1,longlong param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  byte bVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  
  uVar1 = *param_3;
  uVar7 = (ulonglong)param_4;
  if ((1 < uVar1) || (uVar2 = param_3[1], 1 < uVar2)) {
    return 0xc000000d;
  }
  uVar6 = 0;
  ExAcquirePushLockExclusiveEx(param_2 + 0x40,0);
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    uVar6 = 0xc00000b0;
    goto LAB_1c0014fd1;
  }
  if ((uVar1 == 1) && (*(int *)(*(longlong *)(param_2 + 0x28) + 0x104) == 1)) {
    uVar6 = 0xc000000d;
    goto LAB_1c0014fd1;
  }
  if ((uVar2 == 1) && ((*(byte *)(uVar7 + 9 + param_2) & 2) == 0)) {
    lVar4 = 0x58;
    if (param_4 != 1) {
      lVar4 = 0xb8;
    }
    if (*(int *)(lVar4 + param_2) != 0) {
      lVar4 = 0xb8;
      if (param_4 != 1) {
        lVar4 = 0x58;
      }
      if (*(int *)(lVar4 + param_2) != 1) goto LAB_1c0014f9f;
    }
    uVar6 = 0xc00000ae;
  }
  else {
LAB_1c0014f9f:
    bVar5 = *(byte *)(uVar7 + 9 + param_2);
    bVar5 = (bVar5 ^ (byte)uVar1) & 1 ^ bVar5;
    *(byte *)(uVar7 + 9 + param_2) = ((char)uVar2 * '\x02' ^ bVar5) & 2 ^ bVar5;
    if ((uVar2 != 1) &&
       (plVar3 = *(longlong **)(param_2 + 0x1b0 + uVar7 * 8), plVar3 != (longlong *)0x0)) {
      if (*plVar3 != 0) {
        ObfDereferenceObject();
      }
      ExFreePoolWithTag(plVar3,0);
      *(undefined8 *)(param_2 + 0x1b0 + uVar7 * 8) = 0;
    }
  }
LAB_1c0014fd1:
  ExReleasePushLockExclusiveEx(param_2 + 0x40,0);
  return uVar6;
}



===== NpQueryClientProcess @ 1c0015088 =====

undefined8 NpQueryClientProcess(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *_Dst;
  undefined8 uVar4;
  void *pvVar5;
  undefined8 *puVar6;
  size_t _Size;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(lVar2 + 0x30);
  uVar1 = *(uint *)(lVar2 + 8);
  if (*(int *)(lVar2 + 0x18) == 0x110054) {
    if (uVar1 == 0x10) {
      puVar6 = *(undefined8 **)(param_2 + 0x18);
      *puVar6 = 0;
      puVar6[1] = 0;
      uVar4 = NpQueryClientProcessImpl
                        (lVar3,puVar6,0,puVar6 + 1,in_stack_ffffffffffffffd8,(void *)0x0,
                         (undefined2 *)0x0);
      *(undefined8 *)(param_2 + 0x38) = 0x10;
      return uVar4;
    }
  }
  else if ((*(int *)(lVar2 + 0x18) == 0x110024) && (0xf < uVar1)) {
    _Dst = *(undefined8 **)(param_2 + 0x18);
    _Size = (-(ulonglong)(uVar1 < 0x38) & 0xffffffffffffffd8) + 0x38;
    memset(_Dst,0,_Size);
    puVar6 = _Dst + 2;
    pvVar5 = (void *)((longlong)_Dst + 0x12);
    if (uVar1 < 0x38) {
      puVar6 = (undefined8 *)0x0;
      pvVar5 = (void *)0x0;
    }
    uVar4 = NpQueryClientProcessImpl
                      (lVar3,_Dst,0,_Dst + 1,in_stack_ffffffffffffffd8,pvVar5,(undefined2 *)puVar6);
    *(size_t *)(param_2 + 0x38) = _Size;
    return uVar4;
  }
  return 0xc000000d;
}



===== NpQueryClientProcessImpl @ 1c001517c =====

undefined8
NpQueryClientProcessImpl
          (longlong param_1,undefined8 *param_2,undefined8 param_3,void *param_4,undefined8 param_5,
          void *param_6,undefined2 *param_7)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  size_t _Size;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  longlong *plVar10;
  size_t local_res8;
  undefined8 *local_38 [2];
  
  uVar9 = 0;
  local_38[0] = (undefined8 *)0x0;
  local_res8 = 0;
  plVar10 = (longlong *)0x0;
  if ((**(short **)(param_1 + 0x18) == 0x202) && ((*(byte *)(param_1 + 0x20) & 1) != 0)) {
    uVar7 = *(ulonglong *)(param_1 + 0x20) & 0xfffffffffffffffc;
    lVar1 = uVar7 + 0x40;
    ExAcquirePushLockSharedEx(lVar1,0);
    if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
      uVar9 = 0xc00000b0;
    }
    else {
      puVar8 = (undefined8 *)(uVar7 + 0x130);
      puVar4 = (undefined8 *)*puVar8;
      for (puVar3 = puVar4; puVar3 != puVar8; puVar3 = (undefined8 *)*puVar3) {
        if (puVar3[2] == 6) {
          plVar10 = puVar3 + 4;
          if (8 < (ulonglong)puVar3[3]) {
            plVar10 = (longlong *)*plVar10;
          }
          iVar2 = 0;
          goto LAB_1c001521d;
        }
      }
      iVar2 = -0x3ffffddb;
LAB_1c001521d:
      lVar6 = 0;
      if (-1 < iVar2) {
        lVar6 = (longlong)plVar10;
      }
      for (; puVar4 != puVar8; puVar4 = (undefined8 *)*puVar4) {
        if (puVar4[2] == 3) {
          local_res8 = puVar4[3];
          local_38[0] = puVar4 + 4;
          if (local_res8 < 9) {
            memcpy(param_4,local_38[0],local_res8);
          }
          else {
            local_38[0] = (undefined8 *)*local_38[0];
          }
          break;
        }
      }
      if (lVar6 != 0) {
        for (puVar4 = (undefined8 *)*puVar8; puVar4 != puVar8; puVar4 = (undefined8 *)*puVar4) {
          if (puVar4[2] == 4) {
            local_res8 = puVar4[3];
            local_38[0] = puVar4 + 4;
            if (8 < local_res8) {
              local_38[0] = (undefined8 *)*local_38[0];
            }
            if (local_res8 == 8) {
              *param_2 = *local_38[0];
            }
            break;
          }
        }
      }
      if ((param_6 != (void *)0x0) &&
         (uVar5 = NpGetAttributeFromList(puVar8,6,(longlong *)local_38,&local_res8), -1 < (int)uVar5
         )) {
        _Size = local_res8;
        if (0x1e < local_res8) {
          _Size = 0x1e;
        }
        memcpy(param_6,local_38[0],_Size);
        *param_7 = (short)_Size;
      }
    }
    ExReleasePushLockSharedEx(lVar1,0);
  }
  else {
    uVar9 = 0xc00000b0;
  }
  return uVar9;
}



===== NpImpersonate @ 1c001535c =====

undefined4 NpImpersonate(undefined8 param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((**(short **)(lVar1 + 0x18) == 0x202) && ((*(byte *)(lVar1 + 0x20) & 1) != 0)) {
    uVar2 = 0;
    uVar3 = *(ulonglong *)(lVar1 + 0x20) & 0xfffffffffffffffc;
    if (((*(ulonglong *)(lVar1 + 0x20) >> 1 & 1) != 0) || (param_3 != 0)) {
      lVar1 = uVar3 + 0x40;
      if (param_3 == 0) {
        ExAcquirePushLockSharedEx();
        if (*(longlong *)(uVar3 + 0x108) - 1U < 0xfffffffffffffffe) {
          uVar2 = SeImpersonateClientEx(*(longlong *)(uVar3 + 0x108),0);
        }
        else {
          uVar2 = 0xc000010d;
        }
        ExReleasePushLockSharedEx(lVar1,0);
      }
      else {
        ExAcquirePushLockExclusiveEx(lVar1,0);
        NpFreeClientSecurityContext(*(longlong *)(uVar3 + 0x108));
        *(undefined8 *)(uVar3 + 0x108) = 0xffffffffffffffff;
        ExReleasePushLockExclusiveEx(lVar1,0);
      }
      return uVar2;
    }
  }
  return 0xc00000af;
}



===== NpCompleteTransceiveIrp @ 1c0015460 =====

undefined8 NpCompleteTransceiveIrp(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x18),0);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== NpFsdSetSecurityInfo @ 1c00154b0 =====

int NpFsdSetSecurityInfo(longlong param_1,longlong param_2)

{
  int iVar1;
  
  KeEnterCriticalRegion();
  iVar1 = NpCommonSetSecurityInfo(param_1,param_2);
  KeLeaveCriticalRegion();
  if (iVar1 != 0x103) {
    *(int *)(param_2 + 0x30) = iVar1;
    IofCompleteRequest(param_2,2);
  }
  return iVar1;
}



===== NpCommonSetSecurityInfo @ 1c0015518 =====

int NpCommonSetSecurityInfo(longlong param_1,longlong param_2)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  short *psVar8;
  short *psVar9;
  undefined1 uVar10;
  longlong *plVar11;
  short *psVar12;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_res10 = 0;
  local_res18 = 0;
  local_res20 = 0;
  lVar3 = *(longlong *)(lVar2 + 0x30);
  if ((*(byte *)(lVar3 + 0x20) & 1) == 0) {
    return -0x3fffff50;
  }
  lVar4 = *(longlong *)(param_1 + 0x40);
  psVar8 = (short *)0x0;
  psVar9 = *(short **)(lVar3 + 0x18);
  psVar12 = (short *)0x0;
  sVar1 = *psVar9;
  if (sVar1 == 0x202) {
    psVar8 = psVar9;
  }
  else {
    if (sVar1 != 0x203) {
      if (sVar1 != 0x206) {
        return -0x3ffffff3;
      }
      if ((*(byte *)(lVar2 + 2) & 1) == 0) {
        uVar10 = *(undefined1 *)(param_2 + 0x40);
      }
      else {
        uVar10 = 1;
      }
      cVar5 = SeSinglePrivilegeCheck(*(undefined8 *)(*(longlong *)SeExports_exref + 0x28),uVar10);
      if (cVar5 == '\0') {
        return -0x3ffffff3;
      }
      plVar11 = (longlong *)(lVar4 + 0x88);
      goto LAB_1c001557c;
    }
    psVar12 = psVar9;
  }
  plVar11 = (longlong *)(psVar9 + 0x4c);
LAB_1c001557c:
  do {
    if (psVar8 == (short *)0x0) {
      psVar9 = (short *)(lVar4 + 0xc0);
      if (psVar12 == (short *)0x0) {
        psVar9 = (short *)(lVar4 + 0x80);
      }
    }
    else {
      psVar9 = psVar8 + 0x40;
    }
    ExAcquirePushLockSharedEx(psVar9,0);
    local_res10 = *plVar11;
    if (local_res10 != 0) {
      ObReferenceSecurityDescriptor(local_res10,1);
    }
    if (psVar8 == (short *)0x0) {
      psVar9 = (short *)(lVar4 + 0xc0);
      if (psVar12 == (short *)0x0) {
        psVar9 = (short *)(lVar4 + 0x80);
      }
    }
    else {
      psVar9 = psVar8 + 0x40;
    }
    ExReleasePushLockSharedEx(psVar9,0);
    if ((local_res10 == 0) && (iVar6 = NpCreateDefaultRootSecurity(&local_res10), iVar6 < 0)) {
      return iVar6;
    }
    local_res18 = local_res10;
    uVar7 = IoGetFileObjectGenericMapping();
    iVar6 = SeSetSecurityDescriptorInfo
                      (0,lVar2 + 8,*(undefined8 *)(lVar2 + 0x10),&local_res18,1,uVar7);
    if (iVar6 < 0) {
LAB_1c0015621:
      cVar5 = '\x01';
      goto LAB_1c0015626;
    }
    iVar6 = ObLogSecurityDescriptor(local_res18,&local_res20,1);
    ExFreePoolWithTag(local_res18,0);
    if (iVar6 < 0) goto LAB_1c0015621;
    if (psVar8 == (short *)0x0) {
      psVar9 = (short *)(lVar4 + 0xc0);
      if (psVar12 == (short *)0x0) {
        psVar9 = (short *)(lVar4 + 0x80);
      }
    }
    else {
      psVar9 = psVar8 + 0x40;
    }
    ExAcquirePushLockExclusiveEx(psVar9,0);
    local_res18 = *plVar11;
    if (((*(byte *)(lVar3 + 0x20) & 1) != 0) && ((local_res18 == local_res10 || (local_res18 == 0)))
       ) {
      *plVar11 = local_res20;
      if (psVar8 == (short *)0x0) {
        psVar8 = (short *)(lVar4 + 0xc0);
        if (psVar12 == (short *)0x0) {
          psVar8 = (short *)(lVar4 + 0x80);
        }
      }
      else {
        psVar8 = psVar8 + 0x40;
      }
      ExReleasePushLockExclusiveEx(psVar8,0);
      cVar5 = (local_res18 != 0) + '\x01';
LAB_1c0015626:
      ObDereferenceSecurityDescriptor(local_res10,cVar5);
      return iVar6;
    }
    if (psVar8 == (short *)0x0) {
      psVar9 = (short *)(lVar4 + 0xc0);
      if (psVar12 == (short *)0x0) {
        psVar9 = (short *)(lVar4 + 0x80);
      }
    }
    else {
      psVar9 = psVar8 + 0x40;
    }
    ExReleasePushLockExclusiveEx(psVar9,0);
    ObDereferenceSecurityDescriptor(local_res10,1);
    ObDereferenceSecurityDescriptor(local_res20);
  } while( true );
}



===== NpCreateDefaultRootSecurity @ 1c0015868 =====

undefined4 NpCreateDefaultRootSecurity(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res10 [2];
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
  RtlCreateSecurityDescriptor(&local_38,1);
  iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
  lVar3 = ExAllocatePool2(0x100,iVar1 + 0x14,0x6c636144);
  if (lVar3 != 0) {
    RtlCreateAcl(lVar3,iVar1 + 0x14,2);
    RtlAddAccessAllowedAce(lVar3,2,0x1f01fb,*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
    RtlSetDaclSecurityDescriptor(&local_38,1,lVar3,0);
    RtlSetOwnerSecurityDescriptor(&local_38,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108),0)
    ;
    RtlSetGroupSecurityDescriptor(&local_38,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108),0)
    ;
    local_res10[0] = 0;
    RtlAbsoluteToSelfRelativeSD(&local_38,0,local_res10);
    lVar4 = ExAllocatePool2(0x100,local_res10[0],0x6453704e);
    if (lVar4 != 0) {
      RtlAbsoluteToSelfRelativeSD(&local_38,lVar4,local_res10);
      ExFreePoolWithTag(lVar3,0);
      uVar2 = ObLogSecurityDescriptor(lVar4,param_1,1);
      ExFreePoolWithTag(lVar4,0);
      return uVar2;
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return 0xc000009a;
}



===== NpCreateNamedPipePrefix @ 1c0015a58 =====

int * NpCreateNamedPipePrefix
                (int *param_1,longlong param_2,longlong param_3,longlong param_4,undefined4 param_5,
                undefined1 param_6,int param_7)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  char cVar4;
  short sVar5;
  undefined4 *_Dst;
  undefined4 *puVar6;
  longlong lVar7;
  short *psVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  ushort uVar11;
  short *psVar12;
  int local_res18 [2];
  longlong local_res20;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [24];
  ulonglong local_d8;
  longlong *local_d0;
  undefined8 local_c8;
  undefined1 local_c0;
  undefined4 *local_b8;
  int *local_b0;
  undefined4 local_a8 [2];
  longlong local_a0;
  undefined4 local_98;
  undefined4 uStack_94;
  short *psStack_90;
  undefined8 local_88 [2];
  ushort local_78;
  short sStack_76;
  undefined4 uStack_74;
  short *psStack_70;
  undefined8 local_68;
  short *psStack_60;
  longlong local_58;
  ulonglong local_50;
  longlong local_48;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  local_68 = 0;
  psStack_60 = (short *)0x0;
  uStack_74 = *(undefined4 *)(param_3 + 0x5c);
  local_88[0] = 0;
  local_a0 = 0;
  local_a8[0] = 0;
  sStack_76 = (short)((uint)*(undefined4 *)(param_3 + 0x58) >> 0x10);
  uVar11 = (ushort)*(undefined4 *)(param_3 + 0x58);
  if ((uVar11 < 3) || (**(short **)(param_3 + 0x60) != 0x5c)) {
    local_res18[0] = -0x3ffffff3;
    goto LAB_1c0015f61;
  }
  psVar8 = *(short **)(param_3 + 0x60) + 1;
  uVar11 = uVar11 - 2;
  sStack_76 = sStack_76 + -2;
  local_50 = (ulonglong)uVar11;
  local_res20 = param_4;
  local_78 = uVar11;
  psStack_70 = psVar8;
  _Dst = (undefined4 *)ExAllocatePool2(0x101,(ulonglong)uVar11 + 0x198,0x7050704e);
  if (_Dst == (undefined4 *)0x0) {
    local_res18[0] = -0x3fffff66;
    goto LAB_1c0015f61;
  }
  memset(_Dst,0,0x198);
  *(byte *)(_Dst + 1) = *(byte *)(_Dst + 1) | 0x40;
  *(byte *)((longlong)_Dst + 6) = *(byte *)((longlong)_Dst + 6) | 2;
  *(byte *)((longlong)_Dst + 7) = *(byte *)((longlong)_Dst + 7) & 0xf | 0x50;
  puVar6 = _Dst + 0xe;
  *(undefined4 **)(_Dst + 0x10) = puVar6;
  *(undefined4 **)puVar6 = puVar6;
  *(undefined8 *)(_Dst + 0x12) = 0;
  *(undefined8 *)(_Dst + 0x14) = 0;
  *(undefined8 *)(_Dst + 0x16) = 0;
  *(undefined8 *)(_Dst + 0x18) = 0;
  _Dst[0x1a] = 0;
  *(undefined8 *)(_Dst + 0x1c) = 0;
  puVar6 = (undefined4 *)ExAllocatePool2(0x41,0x38,0x7050704e);
  puVar10 = auStack_f8;
  *(undefined4 **)(_Dst + 0xc) = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
LAB_1c0015fef:
    local_res18[0] = -0x3fffff66;
  }
  else {
    *puVar6 = 1;
    *(undefined8 *)(puVar6 + 2) = 0;
    puVar6[4] = 0;
    KeInitializeEvent(puVar6 + 6,1,0);
    puVar6 = _Dst + 0x3e;
    *_Dst = 0x1980203;
    puVar1 = (undefined8 *)(_Dst + 0x3a);
    _Dst[0x1e] = 1;
    _Dst[0x1f] = 1;
    *(undefined8 **)(_Dst + 0x3c) = puVar1;
    *puVar1 = puVar1;
    *(undefined4 **)(_Dst + 0x40) = puVar6;
    *(undefined4 **)puVar6 = puVar6;
    *(undefined4 **)(_Dst + 0x2a) = _Dst + 0x66;
    *(ushort *)(_Dst + 0x28) = uVar11;
    *(ushort *)((longlong)_Dst + 0xa2) = uVar11;
    memcpy(_Dst + 0x66,psVar8,(ulonglong)uVar11);
    lVar7 = local_res20;
    local_58 = local_res20 + 0x20;
    local_d0 = (longlong *)IoGetFileObjectGenericMapping();
    local_c8 = CONCAT44(local_c8._4_4_,1);
    local_d8 = lVar7 + 0x20;
    local_res18[0] = SeAssignSecurity(0,*(undefined8 *)(lVar7 + 0x40),local_88,0);
    puVar10 = auStack_f8;
    psVar12 = (short *)0x0;
    if (-1 < local_res18[0]) {
      local_res18[0] = ObLogSecurityDescriptor(local_88[0],_Dst + 0x26,1);
      ExFreePoolWithTag(local_88[0],0);
      puVar10 = auStack_f8;
      if (-1 < local_res18[0]) {
        KeEnterCriticalRegion();
        local_48 = param_2 + 0xc0;
        ExAcquirePushLockExclusiveEx(local_48,0);
        local_98 = CONCAT22(sStack_76,local_78);
        uStack_94 = uStack_74;
        psStack_90 = psStack_70;
        if (((ushort)local_50 < 2) || (*psVar8 != 0x5c)) {
          uVar11 = local_78;
        }
        else {
          psStack_90 = psStack_70 + 1;
          local_98 = CONCAT22(sStack_76 + -2,local_78 - 2);
          uVar11 = local_78 - 2;
        }
        lVar7 = RtlFindUnicodePrefix(param_2 + 0xd8,&local_98,uVar11);
        if (lVar7 == 0) {
          local_68 = CONCAT44(uStack_94,local_98);
          psStack_60 = psStack_90;
        }
        else {
          psVar12 = (short *)(lVar7 + -0xb0);
          sVar5 = (short)local_98 - *(ushort *)(lVar7 + -0x10);
          local_68._0_4_ = CONCAT22(sVar5,sVar5);
          psStack_60 = psStack_90 + (*(ushort *)(lVar7 + -0x10) >> 1);
          if (*psVar12 != 0x203) {
            psVar12 = (short *)0x0;
          }
        }
        cVar4 = SeSinglePrivilegeCheck(*(undefined8 *)(*(longlong *)SeExports_exref + 0x28),param_6)
        ;
        if (cVar4 == '\0') {
          if (psVar12 == (short *)0x0) {
            local_res18[0] = -0x3fffff9f;
          }
          else {
            local_c8 = IoGetFileObjectGenericMapping();
            local_b0 = local_res18;
            local_b8 = local_a8;
            local_c0 = param_6;
            local_d0 = &local_a0;
            local_d8 = local_d8 & 0xffffffff00000000;
            cVar4 = SeAccessCheck(*(undefined8 *)(psVar12 + 0x4c),local_58,0,4);
            if (local_a0 != 0) {
              SeFreePrivileges();
            }
            if (cVar4 != '\0') goto LAB_1c0015dfc;
          }
        }
        else {
LAB_1c0015dfc:
          cVar4 = RtlInsertUnicodePrefix(param_2 + 0xd8,_Dst + 0x28);
          if (cVar4 == '\0') {
            if (param_7 == 3) {
              psVar8 = (short *)NpFindPrefix(param_2,(undefined8 *)(param_3 + 0x58),'\0',
                                             (short *)&local_68);
              if (((psVar8 == (short *)0x0) || (*psVar8 != 0x203)) || ((short)local_68 != 0)) {
                local_res18[0] = -0x3fffffcc;
              }
              else {
                local_a0 = 0;
                local_c8 = IoGetFileObjectGenericMapping();
                local_b0 = local_res18;
                local_b8 = local_a8;
                local_c0 = param_6;
                local_d0 = &local_a0;
                local_d8 = local_d8 & 0xffffffff00000000;
                cVar4 = SeAccessCheck(*(undefined8 *)(psVar8 + 0x4c),local_58,0,param_5);
                if (local_a0 != 0) {
                  SeFreePrivileges();
                }
                if (cVar4 != '\0') {
                  uVar9 = 1;
                  *(short **)(param_3 + 0x18) = psVar8;
                  *(undefined8 *)(param_3 + 0x20) = 1;
                  *(int *)(psVar8 + 0x3c) = *(int *)(psVar8 + 0x3c) + 1;
                  LOCK();
                  *(int *)(psVar8 + 0x3e) = *(int *)(psVar8 + 0x3e) + 1;
                  UNLOCK();
                  goto LAB_1c0015eee;
                }
              }
            }
            else {
              local_res18[0] = -0x3fffffcb;
            }
          }
          else {
            if (psVar12 != (short *)0x0) {
              puVar2 = *(undefined8 **)(psVar12 + 0x80);
              if ((short *)*puVar2 != psVar12 + 0x7c) {
                pcVar3 = (code *)swi(0x29);
                (*pcVar3)(3);
                puVar10 = auStack_f0;
                goto LAB_1c0015fef;
              }
              *puVar1 = psVar12 + 0x7c;
              *(undefined8 **)(_Dst + 0x3c) = puVar2;
              *puVar2 = puVar1;
              *(undefined8 **)(psVar12 + 0x80) = puVar1;
            }
            *(undefined4 **)(param_3 + 0x18) = _Dst;
            *(undefined8 *)(param_3 + 0x20) = 1;
            _Dst = (undefined4 *)0x0;
            uVar9 = 2;
LAB_1c0015eee:
            *(undefined8 *)(param_1 + 2) = uVar9;
            local_res18[0] = 0;
          }
        }
        puVar10 = auStack_f8;
        ExReleasePushLockExclusiveEx(local_48,0);
        KeLeaveCriticalRegion();
        if (_Dst == (undefined4 *)0x0) goto LAB_1c0015f61;
      }
    }
  }
  lVar7 = *(longlong *)(_Dst + 0x26);
  if (lVar7 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x1c0015f31;
    ObDereferenceSecurityDescriptor(lVar7,1);
  }
  lVar7 = *(longlong *)(_Dst + 0xc);
  if (lVar7 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x1c0015f48;
    ExFreePoolWithTag(lVar7,0);
  }
  *(undefined8 *)(puVar10 + -8) = 0x1c0015f59;
  ExFreePoolWithTag(_Dst,0);
LAB_1c0015f61:
  *param_1 = local_res18[0];
  return param_1;
}



===== NpEnumEvents @ 1c0016040 =====

ulonglong NpEnumEvents(longlong param_1)

{
  longlong lVar1;
  uint *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong local_res8;
  
  lVar5 = *(longlong *)(param_1 + 0xb8);
  lVar1 = *(longlong *)(lVar5 + 0x30);
  if (7 < *(uint *)(lVar5 + 0x10)) {
    puVar2 = *(uint **)(param_1 + 0x18);
    lVar3 = *(longlong *)puVar2;
    if (3 < *(uint *)(lVar5 + 8)) {
      lVar5 = 0;
      if (lVar3 != 0) {
        local_res8 = 0;
        uVar4 = ObReferenceObjectByHandle
                          (lVar3,2,*(undefined8 *)ExEventObjectType_exref,
                           *(undefined1 *)(param_1 + 0x40),&local_res8,0);
        lVar5 = local_res8;
        if ((int)uVar4 < 0) {
          return uVar4;
        }
      }
      uVar4 = NpEventsEnum(lVar1,lVar5,puVar2);
      if (-1 < (int)uVar4) {
        *(undefined8 *)(param_1 + 0x38) = 4;
      }
      if (lVar5 != 0) {
        ObfDereferenceObject(lVar5);
      }
      return uVar4 & 0xffffffff;
    }
  }
  return 0xc000000d;
}



===== NpEventsEnum @ 1c0016110 =====

undefined8 NpEventsEnum(longlong param_1,longlong param_2,uint *param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar3 = 0;
  *param_3 = 0;
  if (**(short **)(param_1 + 0x18) == 0x202) {
    uVar4 = *(ulonglong *)(param_1 + 0x20) & 0xfffffffffffffffc;
    uVar5 = *(ulonglong *)(param_1 + 0x20) >> 1;
    ExAcquirePushLockExclusiveEx(uVar4 + 0x40,0);
    lVar1 = *(longlong *)(uVar4 + 0x1b0 + (ulonglong)((uint)uVar5 & 1) * 8);
    if (lVar1 == 0) {
      uVar3 = 0xc000000d;
    }
    else {
      uVar2 = *(uint *)(lVar1 + 8) >> 1;
      if (((uVar2 & 4) != 0) && (*(char *)(uVar4 + 8) != '\x03')) {
        *param_3 = *param_3 | 4;
      }
      if (((uVar2 & 1) != 0) &&
         (*(int *)((-(ulonglong)((uVar5 & 1) != 0) & 0xffffffffffffffa0) + 0xb8 + uVar4) == 1)) {
        *param_3 = *param_3 | 1;
      }
      if ((*(byte *)(lVar1 + 8) & 1) == 0 && (uVar2 & 2) != 0) {
        *param_3 = *param_3 | 2;
      }
      if (param_2 != 0) {
        KeResetEvent(param_2);
      }
    }
    ExReleasePushLockExclusiveEx(uVar4 + 0x40,0);
  }
  else {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== NpSelectEvents @ 1c0016220 =====

ulonglong NpSelectEvents(longlong param_1)

{
  longlong lVar1;
  uint *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong local_res8;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x10) {
    uVar5 = 0xc000000d;
  }
  else {
    puVar2 = *(uint **)(param_1 + 0x18);
    lVar3 = *(longlong *)(puVar2 + 2);
    lVar6 = 0;
    if (lVar3 != 0) {
      local_res8 = 0;
      uVar5 = ObReferenceObjectByHandle
                        (lVar3,2,*(undefined8 *)ExEventObjectType_exref,
                         *(undefined1 *)(param_1 + 0x40),&local_res8,0);
      lVar6 = local_res8;
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
    uVar4 = NpEventsSelect(lVar1,lVar6,*puVar2);
    uVar5 = uVar4 & 0xffffffff;
    if (((int)uVar4 < 0) && (lVar6 != 0)) {
      ObfDereferenceObject(lVar6);
    }
  }
  return uVar5;
}



===== NpEventsSelect @ 1c00162e0 =====

undefined8 NpEventsSelect(longlong param_1,longlong param_2,uint param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar5 = 0;
  if (param_2 == 0) {
    param_3 = 0;
  }
  else {
    if ((param_3 & 0xfffffff8) != 0) {
      return 0xc000000d;
    }
    if (param_3 == 0) {
      return 0xc000000d;
    }
  }
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    return 0xc00000b0;
  }
  if (**(short **)(param_1 + 0x18) != 0x202) {
    return 0xc000000d;
  }
  uVar3 = *(ulonglong *)(param_1 + 0x20);
  uVar4 = uVar3 & 0xfffffffffffffffc;
  ExAcquirePushLockExclusiveEx(uVar4 + 0x40,0);
  if (((*(byte *)(param_1 + 0x20) & 1) == 0) || (*(char *)(uVar4 + 8) != '\x03')) {
    uVar2 = 0xc00000b0;
  }
  else {
    uVar3 = (ulonglong)((uint)(uVar3 >> 1) & 1);
    if ((*(byte *)(uVar3 + 9 + uVar4) & 2) == 0) {
      uVar2 = 0xc000000d;
    }
    else {
      if (param_2 == 0) {
        plVar1 = *(longlong **)(uVar4 + 0x1b0 + uVar3 * 8);
        if (plVar1 != (longlong *)0x0) {
          if (*plVar1 != 0) {
            ObfDereferenceObject();
          }
          ExFreePoolWithTag(plVar1,0);
          *(undefined8 *)(uVar4 + 0x1b0 + uVar3 * 8) = 0;
        }
      }
      else {
        plVar1 = *(longlong **)(uVar4 + 0x1b0 + uVar3 * 8);
        if (plVar1 == (longlong *)0x0) {
          plVar1 = (longlong *)ExAllocatePool2(0x101,0x10,0x7645704e);
          if (plVar1 == (longlong *)0x0) {
            uVar2 = 0xc000009a;
            goto LAB_1c00163c9;
          }
          *(longlong **)(uVar4 + 0x1b0 + uVar3 * 8) = plVar1;
        }
        else {
          lVar5 = *plVar1;
        }
        *plVar1 = param_2;
        *(uint *)(plVar1 + 1) =
             ((param_3 & 7) * 2 ^ *(uint *)(plVar1 + 1) & 0xfffffff1) & 0xfffffffe;
      }
      uVar2 = 0;
    }
  }
LAB_1c00163c9:
  ExReleasePushLockExclusiveEx(uVar4 + 0x40,0);
  if (lVar5 != 0) {
    ObfDereferenceObject(lVar5);
  }
  return uVar2;
}



===== NpOpenNamedPipePrefix @ 1c00164a4 =====

undefined8 *
NpOpenNamedPipePrefix
          (undefined8 *param_1,longlong param_2,longlong param_3,longlong param_4,undefined4 param_5
          ,undefined1 param_6)

{
  longlong lVar1;
  char cVar2;
  short *psVar3;
  undefined8 uVar4;
  undefined4 local_res8 [2];
  uint local_res10 [2];
  longlong local_res18;
  short local_48 [8];
  
  *param_1 = 0;
  param_1[1] = 0;
  local_res8[0] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_res10[0] = 0;
  local_res18 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_2 + 0xc0,0);
  psVar3 = (short *)NpFindPrefix(param_2,(undefined8 *)(param_3 + 0x58),'\0',local_48);
  if (((psVar3 == (short *)0x0) || (*psVar3 != 0x203)) || (local_48[0] != 0)) {
    local_res8[0] = 0xc0000034;
  }
  else {
    lVar1 = param_4 + 0x20;
    SeLockSubjectContext(lVar1);
    uVar4 = IoGetFileObjectGenericMapping();
    cVar2 = SeAccessCheck(*(undefined8 *)(psVar3 + 0x4c),lVar1,1,param_5,0,&local_res18,uVar4,
                          param_6,local_res10,local_res8);
    if (local_res18 != 0) {
      SeAppendPrivileges(param_4);
      SeFreePrivileges(local_res18);
    }
    if (cVar2 != '\0') {
      *(uint *)(param_4 + 0x14) = *(uint *)(param_4 + 0x14) | local_res10[0];
      *(uint *)(param_4 + 0x10) = *(uint *)(param_4 + 0x10) & ~(local_res10[0] | 0x2000000);
    }
    SeUnlockSubjectContext(lVar1);
    if (cVar2 != '\0') {
      *(int *)(psVar3 + 0x3c) = *(int *)(psVar3 + 0x3c) + 1;
      LOCK();
      *(int *)(psVar3 + 0x3e) = *(int *)(psVar3 + 0x3e) + 1;
      UNLOCK();
      local_res8[0] = 0;
      *(short **)(param_3 + 0x18) = psVar3;
      *(undefined8 *)(param_3 + 0x20) = 1;
      param_1[1] = 1;
    }
  }
  ExReleasePushLockExclusiveEx(param_2 + 0xc0,0);
  KeLeaveCriticalRegion();
  *(undefined4 *)param_1 = local_res8[0];
  return param_1;
}



===== NpFsdQueryVolumeInformation @ 1c0016670 =====

uint NpFsdQueryVolumeInformation(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = NpCommonQueryVolumeInformation(param_2);
  if (uVar1 != 0x103) {
    *(uint *)(param_2 + 0x30) = uVar1;
    IofCompleteRequest(param_2,2);
  }
  return uVar1;
}



===== NpCommonQueryVolumeInformation @ 1c00166b8 =====

uint NpCommonQueryVolumeInformation(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_res8 [2];
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x18);
  iVar1 = *(int *)(lVar2 + 0x10);
  local_res8[0] = *(uint *)(lVar2 + 8);
  if (iVar1 == 1) {
    uVar4 = NpQueryFsVolumeInfo(puVar3,(int *)local_res8);
  }
  else if (iVar1 == 3) {
    uVar4 = 0;
    *puVar3 = 0;
    local_res8[0] = local_res8[0] - 0x18;
    puVar3[1] = 0;
    *(undefined4 *)(puVar3 + 2) = 1;
    *(undefined4 *)((longlong)puVar3 + 0x14) = 1;
  }
  else if (iVar1 == 4) {
    if (local_res8[0] < 8) {
      uVar4 = 0x80000005;
    }
    else {
      uVar4 = 0;
      *puVar3 = 0;
      local_res8[0] = local_res8[0] - 8;
      *(undefined4 *)puVar3 = 0x11;
    }
  }
  else if (iVar1 == 5) {
    uVar4 = local_res8[0] - 0xc;
    uVar5 = 8;
    if (uVar4 < 8) {
      uVar5 = local_res8[0] - 0xc;
    }
    *(undefined4 *)puVar3 = 2;
    uVar6 = local_res8[0] - 0x14;
    *(undefined4 *)(puVar3 + 1) = 8;
    if (uVar4 < 8) {
      uVar6 = 0;
    }
    *(undefined4 *)((longlong)puVar3 + 4) = 0xffffffff;
    memcpy((void *)((longlong)puVar3 + 0xc),L"NPFS",(ulonglong)uVar5);
    uVar4 = -(uint)(uVar4 < 8) & 0x80000005;
    local_res8[0] = uVar6;
  }
  else if (iVar1 == 7) {
    *puVar3 = 0;
    puVar3[1] = 0;
    uVar4 = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    local_res8[0] = local_res8[0] - 0x20;
  }
  else {
    uVar4 = 0xc00000bb;
  }
  *(ulonglong *)(param_1 + 0x38) = (ulonglong)(*(int *)(lVar2 + 8) - local_res8[0]);
  return uVar4;
}



===== NpQueryFsVolumeInfo @ 1c00167d4 =====

uint NpQueryFsVolumeInfo(undefined8 *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  uVar1 = *param_2 - 0x12;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0x12;
  uVar2 = uVar1;
  if (0x11 < uVar1) {
    uVar2 = 0x12;
  }
  if (uVar2 != 0) {
    memcpy((void *)((longlong)param_1 + 0x12),L"NamedPipe",(ulonglong)uVar2);
  }
  *param_2 = uVar1 - uVar2;
  return -(uint)(uVar1 < 0x12) & 0x80000005;
}



===== NpUnlinkNode @ 1c0016850 =====

void NpUnlinkNode(short *param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  
  sVar1 = *param_1;
  if (sVar1 == 0x202) {
    NpUnlinkFcb(param_2,(longlong)param_1,param_3);
  }
  else if (sVar1 == 0x203) {
    NpUnlinkProtectedPrefix(param_2,(longlong)param_1,param_3);
  }
  else if (sVar1 == 0x207) {
    NpDeleteSymlink((longlong)param_1,param_2);
  }
  return;
}



===== NpCreateDevice @ 1c001689c =====

ulonglong NpCreateDevice(longlong *param_1)

{
  ulonglong uVar1;
  longlong local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"\\Device\\NamedPipe");
  uVar1 = IoCreateDevice(NpfsDriverObject,0x1d8,&local_18,0x11,0x20000,0,local_res10);
  if (-1 < (int)uVar1) {
    *(uint *)(local_res10[0] + 0x30) = *(uint *)(local_res10[0] + 0x30) | 0x200;
    NpInitializeVcb(*(undefined4 **)(local_res10[0] + 0x40));
    *param_1 = local_res10[0];
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}



===== entry @ 1c0018010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c0018044 =====

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



===== DriverEntry @ 1c0018080 =====

ulonglong DriverEntry(longlong param_1)

{
  int iVar1;
  undefined4 extraout_var;
  undefined4 *_Dst;
  ulonglong uVar2;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  NpReadParameters();
  iVar1 = NpInitializeAliases();
  uVar2 = CONCAT44(extraout_var,iVar1);
  if (-1 < iVar1) {
    _Dst = (undefined4 *)ExAllocatePool2(0x40,0xe0,0x7366704e);
    if (_Dst == (undefined4 *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,0xe0);
      *_Dst = 0xe0;
      *(code **)(_Dst + 4) = NpFastRead;
      NpfsDriverObject = param_1;
      *(code **)(_Dst + 6) = NpFastWrite;
      *(code **)(param_1 + 0x70) = NpFsdCreate;
      *(code **)(param_1 + 0x78) = NpFsdCreateNamedPipe;
      *(code **)(param_1 + 0x80) = NpFsdClose;
      *(code **)(param_1 + 0x88) = NpFsdRead;
      *(code **)(param_1 + 0x90) = NpFsdWrite;
      *(code **)(param_1 + 0x98) = NpFsdQueryInformation;
      *(code **)(param_1 + 0xa0) = NpFsdSetInformation;
      *(code **)(param_1 + 0xc0) = NpFsdQueryVolumeInformation;
      *(code **)(param_1 + 0x100) = NpFsdCleanup;
      *(code **)(param_1 + 0xb8) = NpFsdFlushBuffers;
      *(code **)(param_1 + 0xd0) = NpFsdDirectoryControl;
      *(code **)(param_1 + 0xd8) = NpFsdFileSystemControl;
      *(code **)(param_1 + 0x110) = NpFsdQuerySecurityInfo;
      *(code **)(param_1 + 0x118) = NpFsdSetSecurityInfo;
      uVar2 = NpCreateDevice(local_res18);
      if (-1 < (int)uVar2) {
        *(undefined4 **)(param_1 + 0x50) = _Dst;
        uVar2 = PsAllocSiloContextSlot(0,&NpSiloSlot);
        if (-1 < (int)uVar2) {
          return uVar2;
        }
      }
      uVar2 = uVar2 & 0xffffffff;
      ExFreePoolWithTag(_Dst,0);
    }
    NpUninitializeAliases();
  }
  return uVar2;
}



===== NpInitializeAliases @ 1c0018224 =====

int NpInitializeAliases(void)

{
  ushort uVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 *puVar8;
  int local_c8;
  int iStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  undefined8 *local_b8;
  longlong lStack_b0;
  undefined8 *local_a8;
  code *local_98;
  undefined4 local_90;
  undefined4 local_78;
  
  local_a8 = (undefined8 *)((ulonglong)local_a8 & 0xffffff0000000000);
  local_c8 = 0;
  iStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  local_b8 = (undefined8 *)0x0;
  lStack_b0 = 0;
  memset(&local_98,0,0x70);
  local_90 = 0x10;
  local_78 = 0;
  local_98 = NpReadAlias;
  local_c8._0_1_ = 1;
  iStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  iVar3 = RtlQueryRegistryValuesEx(0x80000001,L"Npfs\\Aliases",&local_98,&local_c8,0);
  if (iVar3 < 0) {
    iVar4 = 0;
    if (iVar3 != -0x3fffffcc) {
      iVar4 = iVar3;
    }
    return iVar4;
  }
  if (iStack_c4 != 0) {
    NpAliases = ExAllocatePool2(0x40,iStack_c4,0x7366704e);
    if (NpAliases == 0) {
      return -0x3fffff66;
    }
    puVar5 = (undefined8 *)((ulonglong)uStack_bc * 0x10 + NpAliases);
    local_c8 = (uint)local_c8._1_3_ << 8;
    local_a8 = puVar5 + (ulonglong)uStack_c0 * 4;
    local_b8 = puVar5;
    lStack_b0 = NpAliases;
    iVar3 = RtlQueryRegistryValuesEx(0x80000001,L"Npfs\\Aliases",&local_98,&local_c8,0);
    if (iVar3 < 0) {
      ExFreePoolWithTag(NpAliases,0);
      NpAliases = 0;
      return iVar3;
    }
    uVar7 = 0;
    if (uStack_c0 != 0) {
      do {
        uVar1 = *(ushort *)(puVar5 + 2);
        if ((ushort)(uVar1 - 10) < 9) {
          puVar8 = (undefined8 *)(&NpAliasListByLength + ((ulonglong)uVar1 - 10 >> 1) * 8);
        }
        else {
          puVar8 = &NpAliasList;
        }
        puVar2 = (undefined8 *)*puVar8;
        while (((puVar6 = puVar2, puVar6 != (undefined8 *)0x0 && (*(ushort *)(puVar6 + 2) <= uVar1))
               && ((*(ushort *)(puVar6 + 2) < uVar1 ||
                   (iVar3 = _wcsicmp((wchar_t *)puVar5[3],(wchar_t *)puVar6[3]), -1 < iVar3))))) {
          puVar2 = (undefined8 *)*puVar6;
          puVar8 = puVar6;
        }
        uVar7 = uVar7 + 1;
        *puVar5 = *puVar8;
        *puVar8 = puVar5;
        puVar5 = puVar5 + 4;
      } while (uVar7 < uStack_c0);
    }
  }
  return 0;
}



===== NpReadParameters @ 1c001841c =====

void NpReadParameters(void)

{
  undefined4 local_res8 [8];
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48;
  
  local_res8[0] = 0;
  memset(local_78,0,0x70);
  local_68 = L"CompatFlags";
  local_70 = 0x130;
  local_60 = &NpCompatFlags;
  local_50 = local_res8;
  local_58 = 0x4000000;
  local_48 = 4;
  RtlQueryRegistryValuesEx(0x80000001,L"Npfs\\Parameters",local_78,0,0);
  return;
}



===== NpReadAlias @ 1c00184b0 =====

undefined8 NpReadAlias(void *param_1,int param_2,short *param_3,undefined8 param_4,char *param_5)

{
  short *psVar1;
  short *psVar2;
  ushort uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  int iVar9;
  
  if (param_2 == 7) {
    if (*param_5 == '\0') {
      psVar2 = *(short **)(param_5 + 0x18);
      lVar5 = -1;
      *(short **)(param_5 + 0x18) = psVar2 + 8;
      do {
        lVar5 = lVar5 + 1;
      } while (*(short *)((longlong)param_1 + lVar5 * 2) != 0);
      uVar3 = ((short)lVar5 + 2) * 2;
      psVar2[1] = uVar3;
      *psVar2 = uVar3 - 2;
      *(undefined8 *)(psVar2 + 4) = *(undefined8 *)(param_5 + 0x20);
      *(ulonglong *)(param_5 + 0x20) = *(longlong *)(param_5 + 0x20) + (ulonglong)uVar3;
      **(undefined2 **)(psVar2 + 4) = 0x5c;
      memcpy((void *)(*(longlong *)(psVar2 + 4) + 2),param_1,(ulonglong)uVar3 - 2);
      RtlUpcaseUnicodeString(psVar2,psVar2,0);
      for (; *param_3 != 0; param_3 = (short *)((longlong)param_3 + (uVar8 - 2))) {
        lVar5 = *(longlong *)(param_5 + 0x10);
        lVar6 = -1;
        *(longlong *)(param_5 + 0x10) = lVar5 + 0x20;
        *(short **)(lVar5 + 8) = psVar2;
        do {
          lVar6 = lVar6 + 1;
        } while (param_3[lVar6] != 0);
        psVar1 = (short *)(lVar5 + 0x10);
        uVar3 = ((short)lVar6 + 2) * 2;
        *(ushort *)(lVar5 + 0x12) = uVar3;
        uVar8 = (ulonglong)uVar3;
        *psVar1 = uVar3 - 2;
        *(undefined8 *)(lVar5 + 0x18) = *(undefined8 *)(param_5 + 0x20);
        *(ulonglong *)(param_5 + 0x20) = *(longlong *)(param_5 + 0x20) + uVar8;
        **(undefined2 **)(lVar5 + 0x18) = 0x5c;
        memcpy((void *)(*(longlong *)(lVar5 + 0x18) + 2),param_3,uVar8 - 2);
        RtlUpcaseUnicodeString(psVar1,psVar1,0);
      }
    }
    else {
      *(int *)(param_5 + 0xc) = *(int *)(param_5 + 0xc) + 1;
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (*(short *)((longlong)param_1 + lVar5 * 2) != 0);
      iVar7 = *(int *)(param_5 + 4) + 0x10 + (uint)(ushort)(((short)lVar5 + 2) * 2);
      *(int *)(param_5 + 4) = iVar7;
      if (*param_3 != 0) {
        iVar9 = *(int *)(param_5 + 8);
        do {
          iVar9 = iVar9 + 1;
          lVar5 = -1;
          *(int *)(param_5 + 8) = iVar9;
          do {
            lVar5 = lVar5 + 1;
          } while (param_3[lVar5] != 0);
          uVar3 = ((short)lVar5 + 1) * 2;
          iVar7 = iVar7 + uVar3 + 0x22;
          param_3 = (short *)((longlong)param_3 + (ulonglong)uVar3);
          *(int *)(param_5 + 4) = iVar7;
        } while (*param_3 != 0);
      }
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}


