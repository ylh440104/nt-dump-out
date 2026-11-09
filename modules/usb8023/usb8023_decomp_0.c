
===== ControlPipeReadCompletion @ 140001010 =====

undefined8 ControlPipeReadCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  int *piVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  
  lVar3 = *(longlong *)(param_3 + 0x50);
  iVar2 = *(int *)(param_2 + 0x30);
  KeAcquireSpinLockRaiseToDpc(lVar3 + 0x18);
  lVar4 = *(longlong *)(param_3 + 8);
  plVar1 = (longlong *)(param_3 + 8);
  if ((*(longlong **)(lVar4 + 8) != plVar1) ||
     (plVar5 = *(longlong **)(param_3 + 0x10), (longlong *)*plVar5 != plVar1)) {
LAB_140001201:
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3);
    pcVar7 = (code *)swi(3);
    uVar9 = (*pcVar7)();
    return uVar9;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  *(longlong **)(param_3 + 0x10) = plVar1;
  *plVar1 = (longlong)plVar1;
  *(int *)(lVar3 + 0xdc) = *(int *)(lVar3 + 0xdc) + -1;
  KeReleaseSpinLock(lVar3 + 0x18);
  if (*(char *)(param_3 + 0x58) != '\0') {
    *(undefined1 *)(param_3 + 0x58) = 0;
    EnqueueFreePacket(param_3);
    KeSetEvent(param_3 + 0x60,0,0);
    return 0xc0000016;
  }
  if ((*(char *)(lVar3 + 0x59) == '\0') && (*(int *)(lVar3 + 0x5c) == 0)) {
    if (iVar2 < 0) {
      EnqueueFreePacket(param_3);
      *(undefined1 *)(lVar3 + 0x27c) = 1;
      QueueAdapterWorkItem(lVar3,10,10);
      return 0xc0000016;
    }
    *(undefined4 *)(param_3 + 0x34) = *(undefined4 *)(*(longlong *)(param_3 + 0x20) + 0x24);
    piVar6 = *(int **)(param_3 + 0x28);
    if (*piVar6 == -0x7ffffffc) {
      *(longlong *)(lVar3 + 0x260) = param_3;
      *(int *)(lVar3 + 0x270) = piVar6[2];
    }
    if (*piVar6 == -0x7ffffffa) {
      KeAcquireSpinLockRaiseToDpc(lVar3 + 0x18);
      if (*(int *)(lVar3 + 0x248) == 0) {
        KeReleaseSpinLock();
        lVar3 = *(longlong *)(param_3 + 0x50);
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x18);
        plVar5 = *(longlong **)(lVar3 + 0x90);
        if (*plVar5 == lVar3 + 0x88) {
          *plVar1 = lVar3 + 0x88;
          *(longlong **)(param_3 + 0x10) = plVar5;
          *plVar5 = (longlong)plVar1;
          *(longlong **)(lVar3 + 0x90) = plVar1;
          *(int *)(lVar3 + 0xd8) = *(int *)(lVar3 + 0xd8) + 1;
          KeReleaseSpinLock(lVar3 + 0x18,uVar8);
          return 0xc0000016;
        }
        goto LAB_140001201;
      }
      *(int *)(lVar3 + 0x248) = *(int *)(lVar3 + 0x248) + -1;
      KeReleaseSpinLock(lVar3 + 0x18);
    }
    EnqueueCompletedReadPacket(param_3);
    uVar9 = IndicateRndisMessage(param_3,'\0');
    if ((int)uVar9 == 0x103) {
      return 0xc0000016;
    }
    DequeueCompletedReadPacket(param_3);
  }
  EnqueueFreePacket(param_3);
  return 0xc0000016;
}



===== SubmitUrbIrp @ 140001210 =====

ulonglong SubmitUrbIrp(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4,
                      undefined8 param_5,undefined8 param_6)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 local_res10 [3];
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(undefined1 *)(lVar1 + -0x48) = 0xf;
  *(undefined4 *)(lVar1 + -0x30) = 0x220003;
  *(undefined1 *)(param_2 + 0x44) = 0;
  *(undefined8 *)(lVar1 + -0x40) = param_3;
  if (param_4 == 0) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar1 + -0x10) = param_5;
    *(undefined8 *)(lVar1 + -8) = param_6;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    uVar3 = IofCallDriver(param_1);
    return uVar3;
  }
  local_18 = 0;
  local_38 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = param_4;
  KeInitializeEvent(&local_28,0,0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_res10[0] = 0xffffffffdc3cba00;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  *(code **)(lVar1 + -0x10) = CallDriverSyncCompletion;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  IofCallDriver(param_1,param_2);
  iVar2 = KeWaitForMultipleObjects
                    (2,&local_38,1,0,in_stack_ffffffffffffffa8 & 0xffffffffffffff00,0,local_res10,0)
  ;
  if ((iVar2 == 1) || (iVar2 == 0x102)) {
    IoCancelIrp(param_2);
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return (ulonglong)*(uint *)(param_2 + 0x30);
}



===== DequeueFreePacket @ 140001390 =====

longlong DequeueFreePacket(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  plVar1 = (longlong *)(param_1 + 0x88);
  plVar2 = (longlong *)*plVar1;
  if ((plVar2 == plVar1) || (*(int *)(param_1 + 0x5c) != 0)) {
    lVar6 = 0;
  }
  else {
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar5 = *plVar2, (longlong *)*(longlong *)(lVar5 + 8) != plVar2)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3,plVar2,uVar4);
      pcVar3 = (code *)swi(3);
      lVar5 = (*pcVar3)();
      return lVar5;
    }
    *plVar1 = lVar5;
    lVar6 = (longlong)(plVar2 + -1);
    *(longlong **)(lVar5 + 8) = plVar1;
    plVar2[1] = (longlong)plVar2;
    *plVar2 = (longlong)plVar2;
    *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + -1;
  }
  KeReleaseSpinLock(param_1 + 0x18,uVar4);
  return lVar6;
}



===== RNDISProcessNotification @ 140001430 =====

void RNDISProcessNotification(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  code *pcVar9;
  byte bVar10;
  undefined1 uVar11;
  undefined1 *puVar12;
  longlong *plVar13;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  cVar2 = **(char **)(param_1 + 0x140);
  if (cVar2 != '\x01') {
    if (cVar2 != -0x5f) {
      return;
    }
    if ((*(char **)(param_1 + 0x140))[1] != '\x01') {
      return;
    }
  }
  bVar10 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  plVar1 = (longlong *)(param_1 + 0x88);
  plVar13 = (longlong *)(ulonglong)bVar10;
  plVar3 = (longlong *)*plVar1;
  puVar12 = auStack_28;
  if ((plVar3 != plVar1) && (puVar12 = auStack_28, *(int *)(param_1 + 0x5c) == 0)) {
    if (((longlong *)plVar3[1] == plVar1) && (lVar4 = *plVar3, *(longlong **)(lVar4 + 8) == plVar3))
    {
      *plVar1 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar1;
      plVar3[1] = (longlong)plVar3;
      *plVar3 = (longlong)plVar3;
      *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + -1;
      KeReleaseSpinLock(param_1 + 0x18,plVar13);
      if (plVar3 + -1 == (longlong *)0x0) {
        return;
      }
      param_1 = plVar3[9];
      uVar11 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
      plVar13 = *(longlong **)(param_1 + 0xa0);
      if (*plVar13 == param_1 + 0x98) {
        *plVar3 = param_1 + 0x98;
        plVar3[1] = (longlong)plVar13;
        *plVar13 = (longlong)plVar3;
        *(longlong **)(param_1 + 0xa0) = plVar3;
        *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;
        KeReleaseSpinLock(param_1 + 0x18,uVar11);
        lVar4 = plVar3[9];
        lVar5 = plVar3[2];
        puVar6 = (undefined4 *)plVar3[3];
        lVar7 = *(longlong *)(lVar4 + 0x50);
        *puVar6 = 0x1b0088;
        *(undefined8 *)(puVar6 + 6) = 0;
        puVar6[8] = 3;
        puVar6[9] = 0x1000;
        *(longlong *)(puVar6 + 10) = plVar3[4];
        *(undefined8 *)(puVar6 + 0xc) = 0;
        *(undefined8 *)(puVar6 + 0xe) = 0;
        puVar6[0x20] = 0x100;
        *(ushort *)(puVar6 + 0x21) = (ushort)*(byte *)(lVar7 + 2);
        *(undefined2 *)((longlong)puVar6 + 0x86) = 0;
        uVar8 = *(undefined8 *)(lVar4 + 0x28);
        *(longlong *)(lVar4 + 0x128) = lVar5;
        *(undefined4 *)(lVar4 + 0x124) = 8;
        lVar4 = *(longlong *)(lVar5 + 0xb8);
        *(undefined1 *)(lVar4 + -0x48) = 0xf;
        *(undefined4 *)(lVar4 + -0x30) = 0x220003;
        *(undefined1 *)(lVar5 + 0x44) = 0;
        *(undefined4 **)(lVar4 + -0x40) = puVar6;
        lVar4 = *(longlong *)(lVar5 + 0xb8);
        *(undefined4 *)(lVar5 + 0x30) = 0xc00000bb;
        *(code **)(lVar4 + -0x10) = ControlPipeReadCompletion;
        *(longlong **)(lVar4 + -8) = plVar3 + -1;
        *(undefined1 *)(lVar4 + -0x45) = 0xe0;
        IofCallDriver(uVar8,lVar5);
        return;
      }
    }
    pcVar9 = (code *)swi(0x29);
    (*pcVar9)(3);
    puVar12 = auStack_20;
  }
  *(undefined8 *)(puVar12 + -8) = 0x140001619;
  KeReleaseSpinLock(param_1 + 0x18,(ulonglong)plVar13 & 0xff);
  return;
}



===== NotificationCompletion @ 140001630 =====

undefined8 NotificationCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  lVar2 = *(longlong *)(param_3 + 0x138);
  iVar1 = *(int *)(param_2 + 0x30);
  iVar4 = 10;
  KeAcquireSpinLockRaiseToDpc(param_3 + 0x18);
  if (*(char *)(param_3 + 0x14d) != '\0') {
    KeReleaseSpinLock();
    KeSetEvent(param_3 + 0x150,0,0);
    return 0xc0000016;
  }
  if (-1 < iVar1) {
    KeReleaseSpinLock(param_3 + 0x18);
    uVar5 = *(uint *)(lVar2 + 0x24);
    if (*(uint *)(param_3 + 0x80) < uVar5) {
      uVar5 = *(uint *)(param_3 + 0x80);
    }
    *(uint *)(param_3 + 0x148) = uVar5;
    RNDISProcessNotification(param_3);
    SubmitNotificationRead(param_3,'\0');
    return 0xc0000016;
  }
  *(undefined1 *)(param_3 + 0x14c) = 1;
  KeReleaseSpinLock();
  uVar5 = 0;
  uVar3 = *(uint *)(lVar2 + 4) & 0xfffffff;
  if (uVar3 == 2) {
LAB_1400016ee:
    iVar4 = 0;
    uVar5 = 7;
  }
  else if (uVar3 == 4) {
    uVar5 = 4;
  }
  else if (uVar3 == 5) {
    uVar5 = 5;
  }
  else {
    if (uVar3 == 0x11) {
      *(undefined1 *)(param_3 + 0x27d) = 1;
      goto LAB_1400016ee;
    }
    if (uVar3 != 0x30) goto LAB_1400016fb;
    uVar5 = 6;
  }
  *(undefined1 *)(param_3 + 0x27c) = 1;
LAB_1400016fb:
  QueueAdapterWorkItem(param_3,iVar4,uVar5);
  return 0xc0000016;
}



===== ReadPacketFromControlPipe @ 140001780 =====

ulonglong ReadPacketFromControlPipe(longlong param_1,char param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 local_res8;
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_30 = *(longlong *)(param_1 + 0x50);
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  lVar2 = *(longlong *)(param_1 + 0x18);
  lVar5 = *(longlong *)(local_30 + 0x50);
  *puVar1 = 0x1b0088;
  *(undefined8 *)(puVar1 + 6) = 0;
  puVar1[8] = 3;
  puVar1[9] = 0x1000;
  *(undefined8 *)(puVar1 + 10) = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(puVar1 + 0xc) = 0;
  *(undefined8 *)(puVar1 + 0xe) = 0;
  puVar1[0x20] = 0x100;
  *(ushort *)(puVar1 + 0x21) = (ushort)*(byte *)(lVar5 + 2);
  *(undefined2 *)((longlong)puVar1 + 0x86) = 0;
  *(longlong *)(local_30 + 0x128) = lVar2;
  uVar3 = *(undefined8 *)(local_30 + 0x28);
  if (param_2 == '\0') {
    *(undefined4 *)(local_30 + 0x124) = 8;
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined1 *)(lVar5 + -0x48) = 0xf;
    *(undefined4 *)(lVar5 + -0x30) = 0x220003;
    *(undefined1 *)(lVar2 + 0x44) = 0;
    *(undefined4 **)(lVar5 + -0x40) = puVar1;
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
    *(code **)(lVar5 + -0x10) = ControlPipeReadCompletion;
    *(longlong *)(lVar5 + -8) = param_1;
  }
  else {
    *(undefined4 *)(local_30 + 0x124) = 7;
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined1 *)(lVar5 + -0x48) = 0xf;
    *(undefined4 *)(lVar5 + -0x30) = 0x220003;
    *(undefined1 *)(lVar2 + 0x44) = 0;
    *(undefined4 **)(lVar5 + -0x40) = puVar1;
    local_30 = local_30 + 800;
    if (local_30 != 0) {
      local_28 = 0;
      uStack_20 = 0;
      local_18 = 0;
      local_38 = &local_28;
      KeInitializeEvent(&local_28,0,0);
      lVar5 = *(longlong *)(lVar2 + 0xb8);
      local_res8 = 0xffffffffdc3cba00;
      *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
      *(code **)(lVar5 + -0x10) = CallDriverSyncCompletion;
      *(undefined8 **)(lVar5 + -8) = &local_28;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      IofCallDriver(uVar3,lVar2);
      iVar4 = KeWaitForMultipleObjects
                        (2,&local_38,1,0,in_stack_ffffffffffffffa8 & 0xffffffffffffff00,0,
                         &local_res8,0);
      if ((iVar4 == 1) || (iVar4 == 0x102)) {
        IoCancelIrp(lVar2);
        KeWaitForSingleObject(&local_28,0,0,0,0);
      }
      return (ulonglong)*(uint *)(lVar2 + 0x30);
    }
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar5 + -0x10) = 0;
    *(undefined8 *)(lVar5 + -8) = 0;
  }
  *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  uVar6 = IofCallDriver(uVar3,lVar2);
  return uVar6;
}



===== SubmitNotificationRead @ 1400019c0 =====

ulonglong SubmitNotificationRead(longlong param_1,char param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 local_res8;
  ulonglong in_stack_ffffffffffffff98;
  undefined8 *local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  puVar1 = *(undefined4 **)(param_1 + 0x138);
  lVar2 = *(longlong *)(param_1 + 0x130);
  memset(*(void **)(param_1 + 0x140),0xfe,(ulonglong)*(uint *)(param_1 + 0x80) + 4);
  *(undefined4 *)((ulonglong)*(uint *)(param_1 + 0x80) + *(longlong *)(param_1 + 0x140)) =
       0x64726147;
  *puVar1 = 0x90080;
  *(undefined8 *)(puVar1 + 6) = *(undefined8 *)(param_1 + 0x70);
  puVar1[9] = *(undefined4 *)(param_1 + 0x80);
  *(undefined8 *)(puVar1 + 0xc) = 0;
  *(undefined8 *)(puVar1 + 10) = *(undefined8 *)(param_1 + 0x140);
  puVar1[8] = 3;
  *(undefined8 *)(puVar1 + 0xe) = 0;
  if (param_2 == '\0') {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x148) = 0;
    *(undefined1 *)(param_1 + 0x14c) = 0;
    KeReleaseSpinLock(param_1 + 0x18,uVar3);
    uVar7 = *(undefined8 *)(param_1 + 0x28);
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined1 *)(lVar5 + -0x48) = 0xf;
    *(undefined4 *)(lVar5 + -0x30) = 0x220003;
    *(undefined1 *)(lVar2 + 0x44) = 0;
    *(undefined4 **)(lVar5 + -0x40) = puVar1;
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
    *(code **)(lVar5 + -0x10) = NotificationCompletion;
    *(longlong *)(lVar5 + -8) = param_1;
  }
  else {
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    local_40 = param_1 + 800;
    uVar7 = *(undefined8 *)(param_1 + 0x28);
    *(undefined1 *)(lVar5 + -0x48) = 0xf;
    *(undefined4 *)(lVar5 + -0x30) = 0x220003;
    *(undefined1 *)(lVar2 + 0x44) = 0;
    *(undefined4 **)(lVar5 + -0x40) = puVar1;
    if (local_40 != 0) {
      local_28 = 0;
      local_48 = &local_38;
      local_38 = 0;
      uStack_30 = 0;
      KeInitializeEvent(&local_38,0,0);
      lVar5 = *(longlong *)(lVar2 + 0xb8);
      local_res8 = 0xffffffffdc3cba00;
      *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
      *(code **)(lVar5 + -0x10) = CallDriverSyncCompletion;
      *(undefined8 **)(lVar5 + -8) = &local_38;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      IofCallDriver(uVar7,lVar2);
      iVar4 = KeWaitForMultipleObjects
                        (2,&local_48,1,0,in_stack_ffffffffffffff98 & 0xffffffffffffff00,0,
                         &local_res8,0);
      if ((iVar4 == 1) || (iVar4 == 0x102)) {
        IoCancelIrp(lVar2);
        KeWaitForSingleObject(&local_38,0,0,0,0);
      }
      return (ulonglong)*(uint *)(lVar2 + 0x30);
    }
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar5 + -0x10) = 0;
    *(undefined8 *)(lVar5 + -8) = 0;
  }
  *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  uVar6 = IofCallDriver(uVar7,lVar2);
  return uVar6;
}



===== CopyMdlToBuffer @ 140001c30 =====

uint CopyMdlToBuffer(longlong param_1,longlong *param_2,uint param_3)

{
  uint uVar1;
  void *_Src;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_2 == (longlong *)0x0) {
    return 0;
  }
  while( true ) {
    uVar1 = *(uint *)(param_2 + 5);
    uVar3 = uVar1 + uVar2;
    if (param_3 < uVar3) {
      return uVar2;
    }
    if (0xffffffff < (ulonglong)uVar1 + (ulonglong)uVar2) break;
    if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
      _Src = (void *)MmMapLockedPagesSpecifyCache(param_2,0,1,0,0,0x40000010);
    }
    else {
      _Src = (void *)param_2[3];
    }
    if (_Src == (void *)0x0) {
      return uVar2;
    }
    memmove((void *)((ulonglong)uVar2 + param_1),_Src,(ulonglong)uVar1);
    param_2 = (longlong *)*param_2;
    uVar2 = uVar3;
    if (param_2 == (longlong *)0x0) {
      return uVar3;
    }
  }
  return uVar2;
}



===== DequeueFreePacketLocked @ 140001d10 =====

longlong DequeueFreePacketLocked(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_1 + 0x88);
  plVar2 = (longlong *)*plVar1;
  if (((plVar2 != plVar1) && (*(char *)(param_1 + 0x59) == '\0')) && (*(int *)(param_1 + 0x5c) == 0)
     ) {
    if (((longlong *)plVar2[1] == plVar1) &&
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) == plVar2)) {
      *plVar1 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar1;
      plVar2[1] = (longlong)plVar2;
      *plVar2 = (longlong)plVar2;
      *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + -1;
      return (longlong)(plVar2 + -1);
    }
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
  }
  return 0;
}



===== IndicateRndisMessage @ 140001d70 =====

undefined8 IndicateRndisMessage(longlong param_1,char param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  
  uVar2 = *(ulonglong *)(param_1 + 0x28);
  lVar3 = *(longlong *)(param_1 + 0x50);
  uVar5 = (uint)uVar2;
  puVar4 = *(undefined8 **)(param_1 + 0x38);
  uVar1 = *(uint *)(param_1 + 0x34);
  *puVar4 = 0;
  *(undefined2 *)((longlong)puVar4 + 10) = 0;
  puVar4[4] = uVar2 & 0xfffffffffffff000;
  *(uint *)((longlong)puVar4 + 0x2c) = uVar5 & 0xfff;
  *(uint *)(puVar4 + 5) = uVar1;
  *(short *)(puVar4 + 1) =
       ((short)((ulonglong)uVar1 + 0xfff + (ulonglong)(uVar5 & 0xfff) >> 0xc) + 6) * 8;
  MmBuildMdlForNonPagedPool();
  RndisMIndicateReceive
            (*(undefined8 *)(*(longlong *)(param_1 + 0x50) + 0x170),*(undefined8 *)(param_1 + 0x38),
             param_1,param_2 == '\0',-(uint)(*(uint *)(lVar3 + 0xd8) < 4) & 0xc000009a);
  return 0x103;
}



===== RndisSendMessageHandler @ 140001e50 =====

void RndisSendMessageHandler(longlong param_1,longlong *param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  int *piVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  longlong lVar14;
  undefined8 uVar15;
  longlong *plVar16;
  char cVar17;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  if (*(char *)(param_1 + 0x5a) != '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,param_3,0xe,
                       &WPP_52dc62eeed23351655f7cdf7713150ab_Traceguids);
    }
    RndisMSendComplete(*(undefined8 *)(param_1 + 0x170),param_3,0x40010011);
    return;
  }
  if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
    piVar7 = (int *)MmMapLockedPagesSpecifyCache(param_2,0,1);
  }
  else {
    piVar7 = (int *)param_2[3];
  }
  if (piVar7 == (int *)0x0) {
    uVar15 = 0xc001000f;
  }
  else {
    if (*(uint *)(param_1 + 0xe0) < 0x19) {
      uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
      lVar8 = DequeueFreePacketLocked(param_1);
      puVar13 = auStackY_58;
      if (lVar8 == 0) {
        plVar12 = *(longlong **)(param_1 + 0x88);
        *(undefined8 *)(param_1 + 0x250) = param_3;
        KeReleaseSpinLock(param_1 + 0x18,uVar5);
        uVar15 = 0xc000009a;
        if (plVar12 != (longlong *)(param_1 + 0x88)) {
          uVar15 = 0xc0010018;
        }
        RndisMSendComplete(*(undefined8 *)(param_1 + 0x170),param_3,uVar15);
        return;
      }
      lVar14 = *(longlong *)(lVar8 + 0x50);
      plVar12 = (longlong *)(lVar8 + 8);
      *(undefined8 *)(lVar8 + 0x78) = param_3;
      lVar11 = lVar14 + 0xa8;
      plVar16 = *(longlong **)(lVar14 + 0xb0);
      lVar9 = lVar8;
      if (*plVar16 != lVar11) {
        lVar11 = 3;
        pcVar4 = (code *)swi(0x29);
        lVar9 = (*pcVar4)();
        puVar13 = auStackY_50;
      }
      *plVar12 = lVar11;
      plVar12[1] = (longlong)plVar16;
      *plVar16 = (longlong)plVar12;
      *(longlong **)(lVar11 + 8) = plVar12;
      *(int *)(lVar14 + 0xe0) = *(int *)(lVar14 + 0xe0) + 1;
      *(undefined8 *)(puVar13 + -8) = 0x140001f3d;
      GetSystemUpTime((longlong *)(lVar9 + 0x80));
      *(longlong *)(param_1 + 600) = lVar8;
      *(undefined8 *)(puVar13 + -8) = 0x140001f53;
      KeReleaseSpinLock(param_1 + 0x18,uVar5);
      if (param_4 == 0) {
        uVar6 = *(uint *)(lVar8 + 0x30);
        lVar11 = *(longlong *)(lVar8 + 0x28);
        *(longlong **)(lVar8 + 0x40) = param_2;
        *(undefined8 *)(puVar13 + -8) = 0x140001f71;
        uVar6 = CopyMdlToBuffer(lVar11,param_2,uVar6);
        *(uint *)(lVar8 + 0x34) = uVar6;
        *(undefined8 *)(puVar13 + -8) = 0x140001f7d;
        SubmitUSBWritePacket(lVar8);
        return;
      }
      iVar1 = *piVar7;
      cVar17 = '\0';
      if (iVar1 == 2) {
        cVar17 = '\x01';
        iVar2 = piVar7[5];
        *(int *)(param_1 + 0x178) = piVar7[3];
        *(int *)(param_1 + 0x17c) = piVar7[4];
        *(int *)(param_1 + 0x180) = iVar2;
      }
      else if ((iVar1 == 4) || (iVar1 == 5)) {
        iVar2 = piVar7[3];
        iVar3 = piVar7[2];
        if (iVar2 == 0x1010e) {
          *(undefined4 *)(param_1 + 0x184) =
               *(undefined4 *)((ulonglong)(uint)piVar7[5] + 8 + (longlong)piVar7);
          *(undefined1 *)(param_1 + 0x5b) = 1;
        }
        else if ((iVar2 == 0x1010102) && (iVar1 == 5)) {
          uVar6 = piVar7[5];
          *(undefined8 *)(puVar13 + -8) = 0x1400020a6;
          memmove((void *)(param_1 + 0x188),(void *)((ulonglong)uVar6 + 8 + (longlong)piVar7),6);
          *(undefined4 *)(param_1 + 400) = 0x1010102;
          goto LAB_1400020cc;
        }
        *(int *)(param_1 + 400) = iVar2;
        if (iVar1 == 4) {
          *(int *)(param_1 + 0x278) = iVar2;
          *(int *)(param_1 + 0x274) = iVar3;
          *(longlong *)(param_1 + 0x268) = lVar8;
          *(undefined8 *)(param_1 + 0x260) = 0;
          *(undefined4 *)(param_1 + 0x270) = 0;
        }
      }
      else if (iVar1 == 6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          *(undefined **)(puVar13 + 0x20) = &WPP_52dc62eeed23351655f7cdf7713150ab_Traceguids;
          uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(undefined8 *)(puVar13 + -8) = 0x140001ff5;
          WPP_RECORDER_SF_(uVar15,3,lVar14,0xd,*(undefined8 *)(puVar13 + 0x20));
        }
        *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
        *(undefined8 *)(puVar13 + -8) = 0x140002006;
        uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
        *(int *)(param_1 + 0x248) = *(int *)(param_1 + 0x248) + 1;
        *(undefined8 *)(puVar13 + -8) = 0x14000201f;
        KeReleaseSpinLock(param_1 + 0x18,uVar5);
      }
LAB_1400020cc:
      uVar6 = *(uint *)(lVar8 + 0x30);
      lVar11 = *(longlong *)(lVar8 + 0x28);
      *(undefined8 *)(puVar13 + -8) = 0x1400020dc;
      uVar6 = CopyMdlToBuffer(lVar11,param_2,uVar6);
      *(uint *)(lVar8 + 0x34) = uVar6;
      *(undefined8 *)(puVar13 + -8) = 0x1400020ef;
      uVar10 = SubmitPacketToControlPipe(lVar8,cVar17,'\0');
      if ((iVar1 == 2) && (-1 < (int)uVar10)) {
        *(undefined1 *)(param_1 + 0x58) = 1;
        *(undefined8 *)(puVar13 + -8) = 0x14000210f;
        SubmitNotificationRead(param_1,'\0');
      }
      return;
    }
    uVar15 = 0xc000009a;
  }
  RndisMSendComplete(*(undefined8 *)(param_1 + 0x170),param_3,uVar15);
  return;
}



===== GetSystemUpTime @ 140002200 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetSystemUpTime(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = _DAT_fffff78000000320;
  uVar2 = KeQueryTimeIncrement();
  *param_1 = (longlong)((ulonglong)uVar2 * lVar1) / 10000;
  return;
}



===== SubmitUSBWritePacket @ 140002260 =====

void SubmitUSBWritePacket(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x50);
  puVar3 = *(undefined4 **)(param_1 + 0x20);
  lVar4 = *(longlong *)(param_1 + 0x18);
  uVar6 = (ulonglong)*(uint *)(param_1 + 0x34) % (ulonglong)*(uint *)(lVar2 + 0x7c);
  if ((int)uVar6 == 0) {
    *(char *)((ulonglong)*(uint *)(param_1 + 0x34) + *(longlong *)(param_1 + 0x28)) = (char)uVar6;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  }
  *puVar3 = 0x90080;
  *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(lVar2 + 0x68);
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  *(undefined8 *)(puVar3 + 0xc) = 0;
  puVar3[9] = uVar1;
  uVar5 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(puVar3 + 0xe) = 0;
  *(undefined8 *)(puVar3 + 10) = uVar5;
  puVar3[8] = 2;
  uVar5 = *(undefined8 *)(lVar2 + 0x28);
  *(longlong *)(lVar2 + 0x128) = lVar4;
  *(undefined4 *)(lVar2 + 0x124) = 2;
  lVar2 = *(longlong *)(lVar4 + 0xb8);
  *(undefined1 *)(lVar2 + -0x48) = 0xf;
  *(undefined4 *)(lVar2 + -0x30) = 0x220003;
  *(undefined1 *)(lVar4 + 0x44) = 0;
  *(undefined4 **)(lVar2 + -0x40) = puVar3;
  lVar2 = *(longlong *)(lVar4 + 0xb8);
  *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
  *(code **)(lVar2 + -0x10) = WritePipeCompletion;
  *(longlong *)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  IofCallDriver(uVar5,lVar4);
  return;
}



===== DequeuePendingReadPacket @ 140002330 =====

void DequeuePendingReadPacket(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x50);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x18);
  lVar3 = *(longlong *)(param_1 + 8);
  lVar1 = param_1 + 8;
  if ((*(longlong *)(lVar3 + 8) == lVar1) &&
     (plVar4 = *(longlong **)(param_1 + 0x10), *plVar4 == lVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(longlong *)(param_1 + 0x10) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(int *)(lVar2 + 0xdc) = *(int *)(lVar2 + 0xdc) + -1;
    KeReleaseSpinLock(lVar2 + 0x18,uVar6);
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== EnqueueFreePacket @ 1400023c0 =====

void EnqueueFreePacket(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong *plVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = *(longlong *)(param_1 + 0x50);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x18);
  puVar6 = auStack_28;
  lVar5 = lVar1 + 0x88;
  plVar7 = *(longlong **)(lVar1 + 0x90);
  plVar4 = (longlong *)(param_1 + 8);
  if (*plVar7 != lVar5) {
    plVar4 = (longlong *)0x3;
    pcVar2 = (code *)swi(0x29);
    uVar3 = (*pcVar2)();
    puVar6 = auStack_20;
  }
  *plVar4 = lVar5;
  plVar4[1] = (longlong)plVar7;
  *plVar7 = (longlong)plVar4;
  *(longlong **)(lVar5 + 8) = plVar4;
  *(int *)(lVar1 + 0xd8) = *(int *)(lVar1 + 0xd8) + 1;
  *(undefined8 *)(puVar6 + -8) = 0x140002423;
  KeReleaseSpinLock(lVar1 + 0x18,uVar3);
  return;
}



===== CallDriverSync @ 140002440 =====

undefined4 CallDriverSync(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_res10 [3];
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = param_3;
  KeInitializeEvent(&local_28,0,0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_res10[0] = 0xffffffffdc3cba00;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  *(code **)(lVar1 + -0x10) = CallDriverSyncCompletion;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  IofCallDriver(param_1,param_2);
  iVar2 = KeWaitForMultipleObjects
                    (2,&local_38,1,0,in_stack_ffffffffffffffa8 & 0xffffffffffffff00,0,local_res10,0)
  ;
  if ((iVar2 == 1) || (iVar2 == 0x102)) {
    IoCancelIrp(param_2);
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return *(undefined4 *)(param_2 + 0x30);
}



===== TryReadUSB @ 140002560 =====

void TryReadUSB(longlong param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined1 uVar4;
  byte bVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x244);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 < 4) {
    bVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    uVar12 = (ulonglong)bVar5;
    if ((*(char *)(param_1 + 0x59) == '\0') && (*(int *)(param_1 + 0x5c) == 0)) {
      lVar6 = DequeueFreePacketLocked(param_1);
      puVar10 = auStack_28;
      if (lVar6 == 0) {
        *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
        KeReleaseSpinLock(param_1 + 0x18,uVar12 & 0xff);
        QueueAdapterWorkItem(param_1,10,3);
      }
      else {
        lVar9 = *(longlong *)(lVar6 + 0x50);
        plVar8 = (longlong *)(lVar6 + 8);
        lVar7 = lVar9 + 0x98;
        plVar11 = *(longlong **)(lVar9 + 0xa0);
        if (*plVar11 != lVar7) {
          plVar8 = (longlong *)0x3;
          pcVar3 = (code *)swi(0x29);
          lVar7 = (*pcVar3)();
          puVar10 = auStack_20;
        }
        *plVar8 = lVar7;
        plVar8[1] = (longlong)plVar11;
        *plVar11 = (longlong)plVar8;
        *(longlong **)(lVar7 + 8) = plVar8;
        *(int *)(lVar9 + 0xdc) = *(int *)(lVar9 + 0xdc) + 1;
        *(undefined8 *)(puVar10 + -8) = 0x14000263b;
        KeReleaseSpinLock(param_1 + 0x18,uVar12 & 0xff);
        *(undefined8 *)(puVar10 + -8) = 0x140002648;
        SubmitUSBReadPacket(lVar6);
      }
    }
    else {
      KeReleaseSpinLock(param_1 + 0x18,uVar12);
    }
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc();
    *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
    KeReleaseSpinLock(param_1 + 0x18,uVar4);
    QueueAdapterWorkItem(param_1,10,2);
  }
  LOCK();
  *(int *)(param_1 + 0x244) = *(int *)(param_1 + 0x244) + -1;
  UNLOCK();
  return;
}



===== SubmitUSBReadPacket @ 1400026b0 =====

void SubmitUSBReadPacket(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  puVar3 = *(undefined4 **)(param_1 + 0x20);
  lVar4 = *(longlong *)(param_1 + 0x50);
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  *puVar3 = 0x90080;
  *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 0x60);
  puVar3[9] = uVar1;
  *(undefined8 *)(puVar3 + 0xc) = 0;
  *(undefined8 *)(puVar3 + 10) = *(undefined8 *)(param_1 + 0x28);
  puVar3[8] = 3;
  *(undefined8 *)(puVar3 + 0xe) = 0;
  *(longlong *)(lVar4 + 0x128) = lVar2;
  *(undefined4 *)(lVar4 + 0x124) = 1;
  uVar5 = *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 0x28);
  lVar4 = *(longlong *)(lVar2 + 0xb8);
  *(undefined1 *)(lVar4 + -0x48) = 0xf;
  *(undefined4 *)(lVar4 + -0x30) = 0x220003;
  *(undefined1 *)(lVar2 + 0x44) = 0;
  *(undefined4 **)(lVar4 + -0x40) = puVar3;
  lVar4 = *(longlong *)(lVar2 + 0xb8);
  *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
  *(code **)(lVar4 + -0x10) = ReadPipeCompletion;
  *(longlong *)(lVar4 + -8) = param_1;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  IofCallDriver(uVar5,lVar2);
  return;
}



===== QueueAdapterWorkItem @ 140002770 =====

void QueueAdapterWorkItem(longlong param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)param_3;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  if ((((*(char *)(param_1 + 0x1a0) != '\0') || (*(char *)(param_1 + 0x59) != '\0')) ||
      (*(char *)(param_1 + 0x5a) != '\0')) || (*(int *)(param_1 + 0x5c) != 0)) {
    KeReleaseSpinLock(param_1 + 0x18,uVar3);
    return;
  }
  uVar2 = *(uint *)(param_1 + 0xf0);
  *(undefined1 *)(param_1 + 0x1a0) = 1;
  KeReleaseSpinLock(param_1 + 0x18,uVar3);
  if (9 < param_3 - 1) {
    uVar4 = 0;
  }
  piVar1 = (int *)(param_1 + 0xf4 + uVar4 * 4);
  *piVar1 = *piVar1 + 1;
  *(int *)(param_1 + 0x120) = (int)uVar4;
  KeInitializeEvent(param_1 + 0x1a8,0,0);
  if (uVar2 < 0x32) {
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0x198),BackoffTimerDpc,1,param_1);
  }
  else {
    KeInitializeTimer(param_1 + 0x1c0);
    KeInitializeDpc(param_1 + 0x200,BackoffTimerDpc,param_1);
    KeSetTimer(param_1 + 0x1c0,CONCAT44(0xffffffff,param_2 * -10000000),param_1 + 0x200);
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x240) = 1;
    KeReleaseSpinLock(param_1 + 0x18,uVar3);
  }
  return;
}



===== DequeuePendingWritePacket @ 140002920 =====

void DequeuePendingWritePacket(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  
  lVar3 = *(longlong *)(param_1 + 0x50);
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x18);
  lVar4 = *(longlong *)(param_1 + 8);
  lVar1 = param_1 + 8;
  lVar5 = *(longlong *)(param_1 + 0x50);
  if ((*(longlong *)(lVar4 + 8) == lVar1) &&
     (plVar6 = *(longlong **)(param_1 + 0x10), *plVar6 == lVar1)) {
    *plVar6 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar6;
    piVar2 = (int *)(lVar5 + 0xe0);
    *piVar2 = *piVar2 + -1;
    *(longlong *)(param_1 + 0x10) = lVar1;
    *(longlong *)lVar1 = lVar1;
    KeReleaseSpinLock(lVar3 + 0x18,uVar8);
    return;
  }
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== DequeueCompletedReadPacket @ 1400029a0 =====

void DequeueCompletedReadPacket(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x50);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x18);
  lVar3 = *(longlong *)(param_1 + 8);
  lVar1 = param_1 + 8;
  if ((*(longlong *)(lVar3 + 8) == lVar1) &&
     (plVar4 = *(longlong **)(param_1 + 0x10), *plVar4 == lVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(longlong *)(param_1 + 0x10) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(int *)(lVar2 + 0xe4) = *(int *)(lVar2 + 0xe4) + -1;
    KeReleaseSpinLock(lVar2 + 0x18,uVar6);
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== DequeuePendingWritePacketLocked @ 140002a30 =====

void DequeuePendingWritePacketLocked(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  
  lVar3 = *(longlong *)(param_1 + 8);
  lVar1 = param_1 + 8;
  lVar4 = *(longlong *)(param_1 + 0x50);
  if ((*(longlong *)(lVar3 + 8) == lVar1) &&
     (plVar5 = *(longlong **)(param_1 + 0x10), *plVar5 == lVar1)) {
    *plVar5 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar5;
    piVar2 = (int *)(lVar4 + 0xe0);
    *piVar2 = *piVar2 + -1;
    *(longlong *)(param_1 + 0x10) = lVar1;
    *(longlong *)lVar1 = lVar1;
    return;
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== __report_gsfailure @ 140002a80 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== Feature_92507448__private_IsEnabledDeviceUsageNoInline @ 140002a90 =====

ulonglong Feature_92507448__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_92507448__private_featureState;
  if ((Feature_92507448__private_featureState & 0x10) == 0) {
    uVar1 = Feature_92507448__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_92507448__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_92507448__private_IsEnabledFallback @ 140002ac8 =====

void Feature_92507448__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140002ae0 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140008b57 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140002b08 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140002be0 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140002cc4 =====

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
LAB_140002e1c:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140002e0f:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140002e1c;
      if (uVar5 == 5) goto LAB_140002e0f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140002e44 =====

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
              (0x3bf3e5f,&Feature_92507448_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140002ec0 =====

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
                     (local_50,(uint *)&Feature_92507448__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3bf3e5f,param_3 & 0xffffffff,1,&Feature_92507448__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3bf3e5f);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140002fac =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400030bc =====

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
  if ((Feature_92507448__private_featureState & 2) != 0) {
    uVar1 = Feature_92507448__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_92507448__private_featureState;
      if (bVar3) {
        Feature_92507448__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_92507448__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 140003110 =====

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



===== wil_details_IsEnabledFallback @ 140003270 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_92507448__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_92507448__private_featureState,(ulonglong)param_1,0x140008b20)
    ;
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



===== wil_details_MapReportingKind @ 140003300 =====

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



===== wil_details_RecordCachedUsage @ 1400033a0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140003500 =====

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



===== BackoffTimerDpc @ 140003590 =====

void BackoffTimerDpc(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  ProcessWorkItemOrTimerCallback(param_2,param_2,param_3);
  return;
}



===== FreeAdapter @ 1400035a8 =====

void FreeAdapter(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = 0xdeaddead;
  while( true ) {
    puVar1 = (undefined4 *)DequeueFreePacketForHalt((longlong)param_1);
    if (puVar1 == (undefined4 *)0x0) break;
    *puVar1 = 0xdeaddead;
    IoFreeIrp(*(undefined8 *)(puVar1 + 6));
    ExFreePool(*(undefined8 *)(puVar1 + 8));
    IoFreeMdl(*(undefined8 *)(puVar1 + 0xe));
    ExFreePool(*(undefined8 *)(puVar1 + 10));
    ExFreePool(puVar1);
  }
  if (*(longlong *)(param_1 + 0xc) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0xe) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0x50) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0x4c) != 0) {
    IoFreeIrp();
  }
  if (*(longlong *)(param_1 + 0x4e) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0x12) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0x14) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0x66) != 0) {
    IoFreeWorkItem();
  }
  ExFreePool(param_1);
  return;
}



===== NewAdapter @ 1400036f8 =====

undefined4 * NewAdapter(undefined8 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  longlong lVar5;
  
  puVar3 = AllocPool(0x338);
  if (puVar3 != (undefined4 *)0x0) {
    puVar1 = puVar3 + 2;
    *puVar3 = 0x32303855;
    *(undefined8 *)(puVar3 + 10) = param_1;
    *(undefined8 *)(puVar3 + 8) = param_1;
    *(undefined4 **)(puVar3 + 4) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    KeInitializeSpinLock(puVar3 + 6);
    puVar1 = puVar3 + 0x22;
    *(undefined4 **)(puVar3 + 0x24) = puVar1;
    puVar2 = puVar3 + 0x26;
    *(undefined4 **)puVar1 = puVar1;
    *(undefined4 **)(puVar3 + 0x28) = puVar2;
    *(undefined4 **)puVar2 = puVar2;
    puVar1 = puVar3 + 0x2a;
    *(undefined4 **)(puVar3 + 0x2c) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    puVar1 = puVar3 + 0x2e;
    *(undefined4 **)(puVar3 + 0x30) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    puVar1 = puVar3 + 0x32;
    *(undefined4 **)(puVar3 + 0x34) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    *(undefined2 *)(puVar3 + 0x16) = 0;
    puVar3[0x91] = 0;
    *(undefined1 *)((longlong)puVar3 + 0x5b) = 0;
    *(undefined8 *)(puVar3 + 0x3d) = 0;
    *(undefined8 *)(puVar3 + 0x3f) = 0;
    *(undefined8 *)(puVar3 + 0x41) = 0;
    *(undefined8 *)(puVar3 + 0x43) = 0;
    *(undefined8 *)(puVar3 + 0x45) = 0;
    puVar3[0x47] = 0;
    *(undefined2 *)(puVar3 + 0x9f) = 0;
    KeInitializeEvent(puVar3 + 200,0,0);
    KeInitializeEvent(puVar3 + 0xc0,0,0);
    KeInitializeTimer(puVar3 + 0xa0);
    KeInitializeDpc(puVar3 + 0xb0,CancelSendsTimerDpc,puVar3);
    puVar3[0xc6] = 0;
    pvVar4 = AllocPool(0x12);
    *(void **)(puVar3 + 0xc) = pvVar4;
    lVar5 = IoAllocateWorkItem(*(undefined8 *)(puVar3 + 8));
    *(longlong *)(puVar3 + 0x66) = lVar5;
    if ((*(longlong *)(puVar3 + 0xc) == 0) || (lVar5 == 0)) {
      FreeAdapter(puVar3);
      puVar3 = (undefined4 *)0x0;
    }
  }
  return puVar3;
}



===== ProcessWorkItemOrTimerCallback @ 140003878 =====

void ProcessWorkItemOrTimerCallback(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if (((*(char *)(param_1 + 0x58) != '\0') && (*(char *)(param_1 + 0x59) == '\0')) &&
     (*(int *)(param_1 + 0x5c) == 0)) {
    ServiceReadDeficit(param_1);
    if (*(char *)(param_1 + 0x27c) != '\0') {
      bVar2 = KeGetCurrentIrql();
      if (bVar2 < 2) {
        AdapterFullResetAndRestore(param_1,param_2,param_3);
      }
    }
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x1a0) = 0;
  *(undefined1 *)(param_1 + 0x240) = 0;
  KeSetEvent(param_1 + 0x1a8,0,0);
  iVar1 = *(int *)(param_1 + 0x194);
  KeReleaseSpinLock(param_1 + 0x18,uVar3);
  if (((iVar1 != 0) && (*(char *)(param_1 + 0x59) == '\0')) && (*(int *)(param_1 + 0x5c) == 0)) {
    QueueAdapterWorkItem(param_1,10,1);
  }
  return;
}



===== AbortRndisResetMsg @ 140003958 =====

void AbortRndisResetMsg(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  puVar1 = (uint *)(param_1 + 0x248);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_2 = (ulonglong)*puVar1;
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0xe,
                      in_stack_ffffffffffffffd8,(char)*puVar1);
  }
  uVar2 = *puVar1;
  if (uVar2 != 0) {
    *puVar1 = uVar2 - 1;
  }
  uVar6 = CONCAT71((int7)(param_2 >> 8),uVar4);
  KeReleaseSpinLock(param_1 + 0x18);
  if (uVar2 != 0) {
    lVar5 = DequeueFreePacketForHalt(param_1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,param_3,0xf,
                        &WPP_95bf8256b7ec391a05eaa3a7ce4553b3_Traceguids,(char)param_1);
    }
    if (lVar5 != 0) {
      puVar3 = *(undefined4 **)(lVar5 + 0x28);
      puVar3[2] = 0;
      puVar3[3] = 0;
      *puVar3 = 0x80000006;
      puVar3[1] = 0x10;
      EnqueueCompletedReadPacket(lVar5);
      uVar4 = KfRaiseIrql(2);
      uVar6 = IndicateRndisMessage(lVar5,'\0');
      KeLowerIrql(uVar4);
      if ((int)uVar6 != 0x103) {
        DequeueCompletedReadPacket(lVar5);
        EnqueueFreePacket(lVar5);
      }
    }
  }
  return;
}



===== CallDriverSyncCompletion @ 140003ab0 =====

undefined8 CallDriverSyncCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== ControlPipeWriteCompletion @ 140003ae0 =====

undefined8 ControlPipeWriteCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar4 = *(uint *)(param_2 + 0x30);
  lVar1 = *(longlong *)(param_3 + 0x50);
  piVar2 = *(int **)(param_3 + 0x28);
  lVar5 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,10,
                      in_stack_ffffffffffffffd8,(char)*piVar2);
  }
  if ((*piVar2 == 6) && (uVar4 != 0)) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x18);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,lVar5,0xb,
                        in_stack_ffffffffffffffd8,(char)*(undefined4 *)(lVar1 + 0x248));
    }
    if (*(int *)(lVar1 + 0x248) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,lVar5,0xc,
                          in_stack_ffffffffffffffd8,0);
      }
      uVar4 = 0;
    }
    else {
      *(int *)(lVar1 + 0x248) = *(int *)(lVar1 + 0x248) + -1;
    }
    KeReleaseSpinLock(lVar1 + 0x18,uVar3);
  }
  uVar6 = (ulonglong)uVar4;
  *(undefined8 *)(param_3 + 0x40) = 0;
  RndisMSendComplete(*(undefined8 *)(*(longlong *)(param_3 + 0x50) + 0x170),
                     *(undefined8 *)(param_3 + 0x78));
  DequeuePendingWritePacket(param_3);
  if (*(char *)(param_3 + 0x58) == '\0') {
    EnqueueFreePacket(param_3);
  }
  else {
    *(undefined1 *)(param_3 + 0x58) = 0;
    EnqueueFreePacket(param_3);
    uVar6 = 0;
    KeSetEvent(param_3 + 0x60,0);
  }
  if ((int)uVar4 < 0) {
    *(undefined1 *)(lVar1 + 0x27c) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar6,0xd,
                       &WPP_95bf8256b7ec391a05eaa3a7ce4553b3_Traceguids);
    }
    QueueAdapterWorkItem(lVar1,10,9);
  }
  return 0xc0000016;
}



===== FindUSBPipeHandles @ 140003c98 =====

undefined8 FindUSBPipeHandles(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  lVar1 = *(longlong *)(param_1 + 0x48);
  uVar9 = 0;
  lVar2 = *(longlong *)(param_1 + 0x50);
  iVar10 = -1;
  iVar13 = -1;
  uVar11 = 0;
  uVar14 = 0;
  uVar12 = 0;
  iVar7 = 0;
  if (0 < *(int *)(lVar1 + 0x10)) {
    pcVar3 = (char *)(lVar1 + 0x1a);
    iVar10 = -1;
    iVar13 = -1;
    do {
      if (*(int *)(pcVar3 + 2) - 2U < 2) {
        uVar5 = (uint)*(ushort *)(pcVar3 + -2);
        if (*pcVar3 < '\0') {
          iVar6 = iVar7;
          if (uVar5 <= uVar11) {
            uVar5 = uVar11;
            iVar6 = iVar10;
          }
          uVar11 = uVar5;
          iVar10 = iVar6;
        }
        else if (uVar14 < uVar5) {
          uVar14 = uVar5;
          iVar13 = iVar7;
        }
      }
      iVar7 = iVar7 + 1;
      pcVar3 = pcVar3 + 0x18;
    } while (iVar7 < *(int *)(lVar1 + 0x10));
  }
  pcVar3 = (char *)(lVar2 + 0x1a);
  iVar7 = 0;
  lVar8 = (longlong)iVar10;
  lVar4 = 0;
  do {
    iVar6 = -1;
    if (*(int *)(lVar2 + 0x10) <= lVar4) {
LAB_140003d60:
      if (((iVar10 < 0) || (iVar13 < 0)) || (iVar6 < 0)) {
        uVar9 = 0xc000009c;
      }
      else {
        *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(lVar1 + 0x20 + lVar8 * 0x18);
        *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(lVar1 + 0x20 + (longlong)iVar13 * 0x18);
        *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(lVar2 + 0x20 + (longlong)iVar6 * 0x18);
        *(uint *)(param_1 + 0x78) = uVar11;
        *(uint *)(param_1 + 0x7c) = uVar14;
        *(uint *)(param_1 + 0x80) = uVar12;
        *(undefined1 *)(param_1 + 0x84) = *(undefined1 *)(lVar1 + 0x1a + lVar8 * 0x18);
        *(undefined1 *)(param_1 + 0x85) = *(undefined1 *)(lVar1 + 0x1a + (longlong)iVar13 * 0x18);
        *(undefined1 *)(param_1 + 0x86) = *(undefined1 *)(lVar2 + 0x1a + (longlong)iVar6 * 0x18);
      }
      return uVar9;
    }
    if (((*(int *)(pcVar3 + 2) == 3) && (*pcVar3 < '\0')) && ((lVar2 != lVar1 || (lVar4 != lVar8))))
    {
      uVar12 = (uint)*(ushort *)(pcVar3 + -2);
      iVar6 = iVar7;
      goto LAB_140003d60;
    }
    iVar7 = iVar7 + 1;
    lVar4 = lVar4 + 1;
    pcVar3 = pcVar3 + 0x18;
  } while( true );
}



===== GetConfigDescriptor @ 140003dfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GetConfigDescriptor(longlong param_1)

{
  int iVar1;
  void *_Dst;
  undefined1 auStack_118 [48];
  undefined4 local_e8 [9];
  uint local_c4;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_66;
  undefined8 local_48;
  undefined1 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  memset(local_e8,0,0x98);
  local_e8[0] = 0xb0088;
  local_48 = 0;
  local_40 = 0;
  local_c0 = &local_48;
  local_c4 = 9;
  local_b8 = 0;
  local_66 = 0x200;
  local_b0 = 0;
  iVar1 = SubmitUrb(*(longlong *)(param_1 + 0x28),local_e8,param_1 + 800);
  if (-1 < iVar1) {
    _Dst = AllocPool((uint)local_48._2_2_);
    *(void **)(param_1 + 0x38) = _Dst;
    if (_Dst == (void *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      memset(_Dst,0,local_48 >> 0x10 & 0xffff);
      local_c4 = (uint)local_48._2_2_;
      local_c0 = *(undefined8 **)(param_1 + 0x38);
      local_e8[0] = 0xb0088;
      local_b8 = 0;
      local_66 = 0x200;
      local_b0 = 0;
      iVar1 = SubmitUrb(*(longlong *)(param_1 + 0x28),local_e8,param_1 + 800);
      if (iVar1 < 0) {
        ExFreePool(*(undefined8 *)(param_1 + 0x38));
        *(undefined8 *)(param_1 + 0x38) = 0;
      }
    }
  }
  return iVar1;
}



===== InitUSB @ 140003f38 =====

undefined8 InitUSB(longlong param_1)

{
  int iVar1;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  void *pvVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined4 local_a8 [9];
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_26;
  
  uVar4 = 0;
  memset(local_a8,0,0x98);
  local_80 = *(undefined8 *)(param_1 + 0x30);
  local_a8[0] = 0xb0088;
  local_84 = 0x12;
  local_78 = 0;
  local_26 = 0x100;
  local_70 = 0;
  iVar1 = SubmitUrb(*(longlong *)(param_1 + 0x28),local_a8,param_1 + 800);
  pvVar2 = (void *)CONCAT44(extraout_var,iVar1);
  if (-1 < iVar1) {
    iVar1 = GetConfigDescriptor(param_1);
    pvVar2 = (void *)CONCAT44(extraout_var_00,iVar1);
    if (-1 < iVar1) {
      iVar1 = SelectConfiguration(param_1);
      pvVar2 = (void *)CONCAT44(extraout_var_01,iVar1);
      if (-1 < iVar1) {
        pvVar2 = (void *)FindUSBPipeHandles(param_1);
        if (-1 < (int)pvVar2) {
          pvVar2 = (void *)((ulonglong)*(uint *)(param_1 + 0x80) + 4);
          if (pvVar2 < (void *)0x100000000) {
            pvVar2 = AllocPool(*(uint *)(param_1 + 0x80) + 4);
            *(void **)(param_1 + 0x140) = pvVar2;
            uVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                           *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0)
            ;
            *(undefined8 *)(param_1 + 0x130) = uVar3;
            pvVar2 = AllocPool(0x98);
            *(void **)(param_1 + 0x138) = pvVar2;
            if (((*(longlong *)(param_1 + 0x140) != 0) && (*(longlong *)(param_1 + 0x130) != 0)) &&
               (pvVar2 != (void *)0x0)) {
              pvVar2 = (void *)KeInitializeEvent(param_1 + 0x150,0,0);
              *(undefined1 *)(param_1 + 0x14d) = 0;
              uVar4 = 1;
            }
          }
        }
      }
    }
  }
  return CONCAT71((int7)((ulonglong)pvVar2 >> 8),uVar4);
}



===== ReadPipeCompletion @ 140004080 =====

undefined8 ReadPipeCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  
  lVar2 = *(longlong *)(param_3 + 0x50);
  uVar7 = 0;
  iVar1 = *(int *)(param_2 + 0x30);
  iVar8 = 10;
  DequeuePendingReadPacket(param_3);
  if (*(char *)(param_3 + 0x58) != '\0') {
    *(undefined1 *)(param_3 + 0x58) = 0;
    EnqueueFreePacket(param_3);
    KeSetEvent(param_3 + 0x60,0,0);
    return 0xc0000016;
  }
  if ((*(char *)(lVar2 + 0x59) != '\0') || (*(int *)(lVar2 + 0x5c) != 0)) {
    EnqueueFreePacket(param_3);
    return 0xc0000016;
  }
  lVar3 = *(longlong *)(param_3 + 0x20);
  if (-1 < iVar1) {
    *(undefined4 *)(lVar2 + 0xf0) = 0;
    uVar7 = *(uint *)(lVar3 + 0x24);
    *(uint *)(param_3 + 0x34) = uVar7;
    if (0x3b < uVar7) {
      EnqueueCompletedReadPacket(param_3);
      uVar6 = IndicateRndisMessage(param_3,'\x01');
      if ((int)uVar6 == 0x103) goto LAB_140004132;
      DequeueCompletedReadPacket(param_3);
    }
    EnqueueFreePacket(param_3);
LAB_140004132:
    TryReadUSB(lVar2);
    return 0xc0000016;
  }
  uVar5 = *(uint *)(lVar3 + 4) & 0xfffffff;
  if (uVar5 == 2) {
LAB_14000416c:
    uVar7 = 7;
    iVar8 = 0;
  }
  else if (uVar5 == 4) {
    uVar7 = 4;
  }
  else if (uVar5 == 5) {
    uVar7 = 5;
  }
  else {
    if (uVar5 == 0x11) {
      *(undefined1 *)(lVar2 + 0x27d) = 1;
      goto LAB_14000416c;
    }
    if (uVar5 != 0x30) goto LAB_14000417b;
    uVar7 = 6;
  }
  *(undefined1 *)(lVar2 + 0x27c) = 1;
LAB_14000417b:
  EnqueueFreePacket(param_3);
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x18);
  *(int *)(lVar2 + 0xf0) = *(int *)(lVar2 + 0xf0) + 1;
  *(int *)(lVar2 + 0x194) = *(int *)(lVar2 + 0x194) + 1;
  KeReleaseSpinLock(lVar2 + 0x18,uVar4);
  QueueAdapterWorkItem(lVar2,iVar8,uVar7);
  return 0xc0000016;
}



===== SelectConfiguration @ 140004200 =====

int SelectConfiguration(longlong param_1)

{
  ushort *puVar1;
  ushort uVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  void *pvVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  ushort *puVar12;
  
  lVar3 = *(longlong *)(param_1 + 0x38);
  uVar9 = 0;
  if ((1 < *(byte *)(lVar3 + 4)) &&
     (pvVar6 = AllocPool((*(byte *)(lVar3 + 4) + 1) * 0x10), pvVar6 != (void *)0x0)) {
    uVar10 = 0;
    if (*(char *)(lVar3 + 4) != '\0') {
      do {
        lVar7 = USBD_ParseConfigurationDescriptorEx
                          (lVar3,lVar3,uVar10,0,0xffffffff,0xffffffff,0xffffffff);
        *(longlong *)((longlong)pvVar6 + (ulonglong)uVar10 * 0x10) = lVar7;
        if (lVar7 == 0) break;
        uVar9 = uVar9 + 1;
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(byte *)(lVar3 + 4));
    }
    *(undefined8 *)((longlong)pvVar6 + (ulonglong)uVar10 * 0x10) = 0;
    lVar7 = USBD_CreateConfigurationRequestEx(lVar3,pvVar6);
    ExFreePool(pvVar6);
    if (lVar7 != 0) {
      uVar10 = 0;
      puVar1 = (ushort *)(lVar7 + 0x28);
      puVar12 = puVar1;
      if (uVar9 != 0) {
        do {
          lVar8 = USBD_ParseConfigurationDescriptorEx
                            (lVar3,lVar3,uVar10,0,0xffffffff,0xffffffff,0xffffffff);
          uVar4 = 0;
          if (lVar8 != 0) {
            uVar4 = *(undefined1 *)(lVar8 + 5);
          }
          *(undefined1 *)(puVar12 + 2) = uVar4;
          uVar10 = uVar10 + 1;
          puVar12 = (ushort *)((longlong)puVar12 + (ulonglong)*puVar12);
        } while (uVar10 < uVar9);
      }
      if (uVar9 < 2) {
        iVar5 = -0x3fffff64;
      }
      else {
        puVar12 = puVar1;
        if (*(char *)(lVar7 + 0x2c) != '\n') {
          puVar12 = (ushort *)((longlong)puVar1 + (ulonglong)*puVar1);
        }
        if ((char)puVar12[2] == '\n') {
          uVar11 = 0;
          if (*(int *)(puVar12 + 8) != 0) {
            do {
              uVar9 = (int)uVar11 + 1;
              (puVar12 + uVar11 * 0xc + 0x14)[0] = 0x4000;
              (puVar12 + uVar11 * 0xc + 0x14)[1] = 0;
              uVar11 = (ulonglong)uVar9;
            } while (uVar9 < *(uint *)(puVar12 + 8));
          }
          iVar5 = SubmitUrb(*(longlong *)(param_1 + 0x28),lVar7,param_1 + 800);
        }
        else {
          iVar5 = -0x3fffff64;
        }
        if (-1 < iVar5) {
          *(undefined8 *)(param_1 + 0x40) = *(undefined8 *)(lVar7 + 0x20);
          uVar2 = *puVar1;
          puVar12 = (ushort *)((longlong)puVar1 + (ulonglong)uVar2);
          if ((char)puVar12[2] == '\n') {
            pvVar6 = MemDup(puVar1,(uint)uVar2);
            *(void **)(param_1 + 0x50) = pvVar6;
            pvVar6 = MemDup(puVar12,(uint)*puVar12);
            *(void **)(param_1 + 0x48) = pvVar6;
          }
          else if (*(char *)(lVar7 + 0x2c) == '\n') {
            pvVar6 = MemDup(puVar1,(uint)uVar2);
            *(void **)(param_1 + 0x48) = pvVar6;
            pvVar6 = MemDup(puVar12,(uint)*puVar12);
            *(void **)(param_1 + 0x50) = pvVar6;
          }
          else {
            *(undefined8 *)(param_1 + 0x48) = 0;
            *(undefined8 *)(param_1 + 0x50) = 0;
          }
          if ((*(longlong *)(param_1 + 0x48) == 0) || (*(longlong *)(param_1 + 0x50) == 0)) {
            if (*(longlong *)(param_1 + 0x50) != 0) {
              ExFreePool();
            }
            if (*(longlong *)(param_1 + 0x48) != 0) {
              ExFreePool();
            }
            iVar5 = -0x3fffff66;
          }
        }
      }
      ExFreePool(lVar7);
      return iVar5;
    }
  }
  return -0x3fffff66;
}



===== StartUSBReadLoop @ 140004464 =====

void StartUSBReadLoop(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = 4;
  do {
    TryReadUSB(param_1);
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  return;
}



===== SubmitPacketToControlPipe @ 140004498 =====

ulonglong SubmitPacketToControlPipe(longlong param_1,char param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x50);
  lVar2 = *(longlong *)(param_1 + 0x18);
  puVar3 = *(undefined4 **)(param_1 + 0x20);
  lVar4 = *(longlong *)(lVar1 + 0x50);
  *puVar3 = 0x1b0088;
  *(undefined8 *)(puVar3 + 6) = 0;
  puVar3[8] = 0;
  puVar3[9] = *(undefined4 *)(param_1 + 0x34);
  *(undefined8 *)(puVar3 + 10) = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(puVar3 + 0xc) = 0;
  *(undefined8 *)(puVar3 + 0xe) = 0;
  puVar3[0x20] = 0;
  *(ushort *)(puVar3 + 0x21) = (ushort)*(byte *)(lVar4 + 2);
  *(undefined2 *)((longlong)puVar3 + 0x86) = 0;
  *(longlong *)(lVar1 + 0x128) = lVar2;
  if (param_2 == '\0') {
    *(undefined4 *)(lVar1 + 0x124) = 6;
    uVar5 = SubmitUrbIrp(*(undefined8 *)(lVar1 + 0x28),lVar2,puVar3,0,ControlPipeWriteCompletion,
                         param_1);
    uVar5 = uVar5 & 0xffffffff;
  }
  else {
    *(undefined4 *)(lVar1 + 0x124) = 5;
    uVar5 = SubmitUrbIrp(*(undefined8 *)(lVar1 + 0x28),lVar2,puVar3,lVar1 + 800,0,0);
    uVar5 = uVar5 & 0xffffffff;
    if (param_3 == '\0') {
      ControlPipeWriteCompletion(*(undefined8 *)(lVar1 + 0x28),lVar2,param_1);
    }
  }
  return uVar5;
}



===== SubmitUrb @ 14000459c =====

undefined4 SubmitUrb(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar3 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x220003;
    *(undefined8 *)(lVar1 + -0x40) = param_2;
    if (param_3 == 0) {
      *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
      lVar3 = *(longlong *)(lVar3 + 0xb8);
      *(undefined8 *)(lVar3 + -0x10) = 0;
      *(undefined8 *)(lVar3 + -8) = 0;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      uVar2 = IofCallDriver();
    }
    else {
      uVar2 = CallDriverSync(param_1,lVar3,param_3);
      IoFreeIrp(lVar3);
    }
  }
  return uVar2;
}



===== WPP_RECORDER_SF_ @ 140004660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                     undefined8 param_5)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1400046f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_95bf8256b7ec391a05eaa3a7ce4553b3_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_95bf8256b7ec391a05eaa3a7ce4553b3_Traceguids,param_4,&param_6,4,0)
  ;
  return;
}



===== WPP_RECORDER_SF_q @ 14000479c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,3,1,param_5,param_4,&param_6,8,0);
  return;
}



===== WritePipeCompletion @ 140004850 =====

undefined8 WritePipeCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int iVar5;
  int iVar4;
  uint uVar6;
  
  iVar1 = *(int *)(param_2 + 0x30);
  lVar2 = *(longlong *)(param_3 + 0x50);
  iVar5 = 10;
  iVar4 = 10;
  *(undefined8 *)(param_3 + 0x40) = 0;
  RndisMSendComplete(*(undefined8 *)(lVar2 + 0x170),*(undefined8 *)(param_3 + 0x78));
  DequeuePendingWritePacket(param_3);
  if (-1 < iVar1) goto LAB_1400048eb;
  uVar6 = 0;
  uVar3 = *(uint *)(*(longlong *)(param_3 + 0x20) + 4) & 0xfffffff;
  if (uVar3 == 2) {
LAB_1400048d4:
    uVar6 = 7;
    iVar4 = 0;
LAB_1400048da:
    *(undefined1 *)(lVar2 + 0x27c) = 1;
  }
  else {
    if (uVar3 == 4) {
      uVar6 = 4;
      iVar4 = iVar5;
      goto LAB_1400048da;
    }
    if (uVar3 == 5) {
      uVar6 = 5;
      iVar4 = iVar5;
      goto LAB_1400048da;
    }
    if (uVar3 == 0x11) {
      *(undefined1 *)(lVar2 + 0x27d) = 1;
      goto LAB_1400048d4;
    }
    if (uVar3 == 0x30) {
      uVar6 = 6;
      iVar4 = iVar5;
      goto LAB_1400048da;
    }
  }
  QueueAdapterWorkItem(lVar2,iVar4,uVar6);
LAB_1400048eb:
  if (*(char *)(param_3 + 0x58) == '\0') {
    EnqueueFreePacket(param_3);
  }
  else {
    *(undefined1 *)(param_3 + 0x58) = 0;
    EnqueueFreePacket(param_3);
    KeSetEvent(param_3 + 0x60,0,0);
  }
  return 0xc0000016;
}



===== CancelAllPendingPackets @ 14000494c =====

void CancelAllPendingPackets(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined1 *puVar9;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  
  lVar1 = param_1 + 0x18;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar9 = auStack_48;
  plVar2 = (longlong *)(param_1 + 0x98);
  while( true ) {
    plVar3 = (longlong *)*plVar2;
    if (plVar3 == plVar2) break;
    if (((longlong *)plVar3[1] != plVar2) || (lVar4 = *plVar3, *(longlong **)(lVar4 + 8) != plVar3))
    goto LAB_140004b18;
    *plVar2 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar2;
    plVar5 = *(longlong **)(param_1 + 0xa0);
    lVar4 = plVar3[2];
    if ((longlong *)*plVar5 != plVar2) goto LAB_140004b18;
    *plVar3 = (longlong)plVar2;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(param_1 + 0xa0) = plVar3;
    KeInitializeEvent(plVar3 + 0xb,0);
    *(undefined1 *)(plVar3 + 10) = 1;
    KeReleaseSpinLock(lVar1);
    IoCancelIrp(lVar4);
    local_28 = 0;
    KeWaitForSingleObject(plVar3 + 0xb);
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
  plVar2 = (longlong *)(param_1 + 0xa8);
  while (plVar3 = (longlong *)*plVar2, plVar3 != plVar2) {
    if (((longlong *)plVar3[1] != plVar2) || (lVar4 = *plVar3, *(longlong **)(lVar4 + 8) != plVar3))
    goto LAB_140004b18;
    *plVar2 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar2;
    plVar5 = *(longlong **)(param_1 + 0xb0);
    lVar4 = plVar3[2];
    if ((longlong *)*plVar5 != plVar2) goto LAB_140004b18;
    *plVar3 = (longlong)plVar2;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(param_1 + 0xb0) = plVar3;
    if ((char)plVar3[10] == '\0') {
      KeInitializeEvent(plVar3 + 0xb,0,0);
      *(undefined1 *)(plVar3 + 10) = 1;
      KeReleaseSpinLock(lVar1);
      IoCancelIrp(lVar4);
    }
    else {
      KeReleaseSpinLock(lVar1);
    }
    local_28 = 0;
    KeWaitForSingleObject(plVar3 + 0xb,0,0,0);
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
LAB_140004b1f:
  while( true ) {
    plVar2 = *(longlong **)(param_1 + 200);
    if (plVar2 == (longlong *)(param_1 + 200)) break;
    *(undefined8 *)(puVar9 + -8) = 0x140004b3b;
    KeReleaseSpinLock(lVar1);
    *(undefined8 *)(puVar9 + 0x20) = 0;
    *(undefined8 *)(puVar9 + -8) = 0x140004b59;
    KeWaitForSingleObject(plVar2 + 0xb);
    *(undefined8 *)(puVar9 + -8) = 0x140004b68;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
  if (((*(longlong *)(param_1 + 0x70) != 0) && (*(char *)(param_1 + 0x58) != '\0')) &&
     (*(char *)(param_1 + 0x14c) == '\0')) {
    *(undefined8 *)(puVar9 + -8) = 0x140004ba6;
    KeInitializeEvent(param_1 + 0x150,0,0);
    *(undefined2 *)(param_1 + 0x14c) = 0x101;
    *(undefined8 *)(puVar9 + -8) = 0x140004bc1;
    KeReleaseSpinLock(lVar1,uVar8);
    uVar6 = *(undefined8 *)(param_1 + 0x130);
    *(undefined8 *)(puVar9 + -8) = 0x140004bd4;
    IoCancelIrp(uVar6);
    *(undefined8 *)(puVar9 + 0x20) = 0;
    *(undefined8 *)(puVar9 + -8) = 0x140004bf1;
    KeWaitForSingleObject(param_1 + 0x150,0,0,0);
    *(undefined8 *)(puVar9 + -8) = 0x140004c00;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x14d) = 0;
  }
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined8 *)(puVar9 + -8) = 0x140004c23;
  KeReleaseSpinLock(lVar1,uVar8);
  return;
LAB_140004b18:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar9 = auStack_40;
  goto LAB_140004b1f;
}



===== CancelSendsTimerDpc @ 140004c50 =====

void CancelSendsTimerDpc(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 *puVar7;
  longlong local_res10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  local_res10 = 0;
  lVar1 = param_2 + 0x18;
  KeAcquireSpinLockAtDpcLevel(lVar1);
  if ((*(char *)(param_2 + 0x59) == '\0') && (*(int *)(param_2 + 0x5c) == 0)) {
    GetSystemUpTime(&local_res10);
    while( true ) {
      plVar2 = *(longlong **)(param_2 + 0xa8);
      puVar7 = auStack_38;
      if (((plVar2 == (longlong *)(param_2 + 0xa8)) ||
          (puVar7 = auStack_38, (char)plVar2[10] != '\0')) ||
         (puVar7 = auStack_38, local_res10 - plVar2[0xf] < 10000)) goto LAB_140004d60;
      lVar3 = plVar2[2];
      DequeuePendingWritePacketLocked((longlong)(plVar2 + -1));
      KeInitializeEvent(plVar2 + 0xb,0,0);
      lVar4 = plVar2[9];
      *(undefined1 *)(plVar2 + 10) = 1;
      plVar5 = *(longlong **)(lVar4 + 0xd0);
      if (*plVar5 != lVar4 + 200) break;
      *plVar2 = lVar4 + 200;
      plVar2[1] = (longlong)plVar5;
      *plVar5 = (longlong)plVar2;
      *(longlong **)(lVar4 + 0xd0) = plVar2;
      *(int *)(lVar4 + 0xe0) = *(int *)(lVar4 + 0xe0) + 1;
      KeReleaseSpinLockFromDpcLevel(lVar1);
      IoCancelIrp(lVar3);
      KeAcquireSpinLockAtDpcLevel(lVar1);
      *(int *)(param_2 + 0x318) = *(int *)(param_2 + 0x318) + 1;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar7 = auStack_30;
LAB_140004d60:
    *(undefined8 *)(puVar7 + -8) = 0x140004d7c;
    KeSetTimer(param_2 + 0x280,0xfffffffffa0a1f00,param_2 + 0x2c0);
  }
  else {
    KeSetEvent(param_2 + 0x300,0,0);
    puVar7 = auStack_38;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140004da5;
  KeReleaseSpinLockFromDpcLevel(lVar1);
  return;
}



===== DequeueFreePacketForHalt @ 140004dcc =====

longlong DequeueFreePacketForHalt(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  
  plVar1 = (longlong *)(param_1 + 0x88);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 == plVar1) {
    lVar4 = 0;
  }
  else {
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar4 = *plVar2, (longlong *)*(longlong *)(lVar4 + 8) != plVar2)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      lVar4 = (*pcVar3)();
      return lVar4;
    }
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    lVar4 = (longlong)(plVar2 + -1);
    plVar2[1] = (longlong)plVar2;
    *plVar2 = (longlong)plVar2;
    *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + -1;
  }
  return lVar4;
}



===== EnqueueCompletedReadPacket @ 140004e1c =====

void EnqueueCompletedReadPacket(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = *(longlong *)(param_1 + 0x50);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x18);
  puVar7 = auStack_28;
  lVar4 = lVar1 + 0xb8;
  plVar6 = (longlong *)(param_1 + 8);
  plVar5 = *(longlong **)(lVar1 + 0xc0);
  if (*plVar5 != lVar4) {
    lVar4 = 3;
    pcVar2 = (code *)swi(0x29);
    uVar3 = (*pcVar2)();
    puVar7 = auStack_20;
  }
  *plVar6 = lVar4;
  *(longlong **)(param_1 + 0x10) = plVar5;
  *plVar5 = (longlong)plVar6;
  *(longlong **)(lVar4 + 8) = plVar6;
  *(int *)(lVar1 + 0xe4) = *(int *)(lVar1 + 0xe4) + 1;
  *(undefined8 *)(puVar7 + -8) = 0x140004e7e;
  KeReleaseSpinLock(lVar1 + 0x18,uVar3);
  return;
}



===== NewPacket @ 140004e9c =====

undefined4 * NewPacket(longlong param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  void *pvVar4;
  
  puVar2 = AllocPool(0x88);
  if (puVar2 != (undefined4 *)0x0) {
    puVar1 = puVar2 + 2;
    *puVar2 = 0x32303855;
    *(undefined4 **)(puVar2 + 4) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    *(longlong *)(puVar2 + 0x14) = param_1;
    *(undefined1 *)(puVar2 + 0x16) = 0;
    uVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                   *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
    *(undefined8 *)(puVar2 + 6) = uVar3;
    pvVar4 = AllocPool(0x98);
    *(void **)(puVar2 + 8) = pvVar4;
    pvVar4 = AllocPool((g_Feature_MSRC124032_IsEnabled != '\0') + 0x4000);
    *(void **)(puVar2 + 10) = pvVar4;
    puVar2[0xc] = 0x4000;
    if (pvVar4 != (void *)0x0) {
      uVar3 = IoAllocateMdl(pvVar4,0x4000,0,0,0);
      *(undefined8 *)(puVar2 + 0xe) = uVar3;
    }
    puVar2[0xd] = 0;
    if (*(longlong *)(puVar2 + 6) != 0) {
      if (((*(longlong *)(puVar2 + 8) != 0) && (*(longlong *)(puVar2 + 10) != 0)) &&
         (*(longlong *)(puVar2 + 0xe) != 0)) {
        uniquePacketId = uniquePacketId + 1;
        puVar2[0x12] = uniquePacketId;
        return puVar2;
      }
      IoFreeIrp();
    }
    if (*(longlong *)(puVar2 + 8) != 0) {
      ExFreePool();
    }
    if (*(longlong *)(puVar2 + 10) != 0) {
      ExFreePool();
    }
    if (*(longlong *)(puVar2 + 0xe) != 0) {
      IoFreeMdl();
    }
    ExFreePool(puVar2);
  }
  return (undefined4 *)0x0;
}



===== RegisterRNDISMicroport @ 140004fec =====

bool RegisterRNDISMicroport(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res18 [2];
  undefined4 local_58;
  undefined4 local_54;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  
  local_res18[0] = 0;
  local_54 = 0;
  local_50 = RndisInitializeHandler;
  local_58 = 0x2000;
  local_48 = RndisInitCompleteNotify;
  local_40 = RndisHalt;
  local_38 = _guard_check_icall;
  local_30 = RndisDriverUnload;
  local_28 = RndisSendMessageHandler;
  local_20 = RndisReturnMessageHandler;
  local_18 = RndisPnPNotify;
  iVar1 = RndisMInitializeWrapper(local_res18,0,param_1,param_2,&local_58);
  return iVar1 == 0;
}



===== RndisDriverUnload @ 1400050a0 =====

void RndisDriverUnload(void)

{
  wil_details_UnregisterFeatureStagingChangeNotification();
  wil_details_UnregisterFeatureUsageProvider();
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== RndisHalt @ 1400050d0 =====

void RndisHalt(undefined4 *param_1)

{
  undefined4 *puVar1;
  longlong *plVar2;
  char cVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  char cVar8;
  char cVar9;
  
  puVar1 = param_1 + 6;
  uVar7 = KeAcquireSpinLockRaiseToDpc(puVar1);
  cVar3 = *(char *)(param_1 + 0x68);
  cVar9 = *(char *)(param_1 + 0x90);
  KeReleaseSpinLock(puVar1,uVar7);
  KeSetEvent(param_1 + 200,0,0);
  cVar8 = KeCancelTimer(param_1 + 0xa0);
  if (cVar8 == '\0') {
    KeWaitForSingleObject(param_1 + 0xc0,0,0,0,0);
  }
  if (cVar9 != '\0') {
    cVar9 = KeCancelTimer(param_1 + 0x70);
    if (cVar9 != '\0') goto LAB_1400051ab;
  }
  if (cVar3 != '\0') {
    KeWaitForSingleObject(param_1 + 0x6a,0,0,0,0);
  }
LAB_1400051ab:
  uVar7 = KeAcquireSpinLockRaiseToDpc(puVar1);
  *(undefined1 *)((longlong)param_1 + 0x59) = 1;
  KeReleaseSpinLock(puVar1,uVar7);
  CancelAllPendingPackets((longlong)param_1);
  *(undefined1 *)(param_1 + 0x16) = 0;
  uVar7 = KeAcquireSpinLockRaiseToDpc(&globalSpinLock);
  plVar2 = (longlong *)(param_1 + 2);
  lVar4 = *plVar2;
  if ((*(longlong **)(lVar4 + 8) == plVar2) &&
     (plVar5 = *(longlong **)(param_1 + 4), (longlong *)*plVar5 == plVar2)) {
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    *(longlong **)(param_1 + 4) = plVar2;
    *plVar2 = (longlong)plVar2;
    KeReleaseSpinLock(&globalSpinLock,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar7));
    FreeAdapter(param_1);
    return;
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== RndisInitCompleteNotify @ 140005260 =====

undefined8 RndisInitCompleteNotify(longlong param_1,undefined8 param_2,uint *param_3)

{
  if (0x4000 < *param_3) {
    *param_3 = 0x4000;
  }
  StartUSBReadLoop(param_1);
  return 0;
}



===== RndisInitializeHandler @ 140005290 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RndisInitializeHandler
              (undefined8 *param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,10,
                     &WPP_52dc62eeed23351655f7cdf7713150ab_Traceguids);
  }
  puVar3 = NewAdapter(param_6);
  if (puVar3 == (undefined4 *)0x0) {
    return 0x10003;
  }
  *(undefined8 *)(puVar3 + 0x5a) = param_4;
  *(undefined8 *)(puVar3 + 0x5c) = param_3;
  uVar4 = InitUSB((longlong)puVar3);
  puVar10 = auStackY_48;
  if ((char)uVar4 == '\0') {
    iVar9 = 0x10003;
    puVar10 = auStackY_48;
  }
  else {
    for (uVar8 = 0; uVar8 < 0x20; uVar8 = uVar8 + 1) {
      puVar5 = NewPacket((longlong)puVar3);
      if (puVar5 == (undefined4 *)0x0) {
        iVar9 = 0x10003;
        goto LAB_1400053ca;
      }
      EnqueueFreePacket((longlong)puVar5);
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(&globalSpinLock);
    puVar11 = &allAdaptersList;
    puVar7 = (undefined8 *)(puVar3 + 2);
    puVar6 = DAT_140009118;
    puVar10 = auStackY_48;
    if ((undefined *)*DAT_140009118 != &allAdaptersList) {
      puVar6 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      uVar2 = (*pcVar1)();
      puVar10 = auStackY_40;
    }
    puVar7[1] = puVar6;
    *puVar7 = puVar11;
    *puVar6 = puVar7;
    *(undefined8 *)(puVar10 + -8) = 0x140005398;
    DAT_140009118 = puVar7;
    KeReleaseSpinLock(&globalSpinLock,uVar2);
    *(undefined8 *)(puVar10 + -8) = 0x1400053b9;
    KeSetTimer(puVar3 + 0xa0,0xfffffffffa0a1f00,puVar3 + 0xb0);
    *param_1 = puVar3;
    iVar9 = 0;
    *param_2 = 0x4000;
LAB_1400053ca:
    if (iVar9 == 0) goto LAB_1400053e1;
  }
  *(undefined8 *)(puVar10 + -8) = 0x1400053dd;
  FreeAdapter(puVar3);
  if (iVar9 != 0) {
    return iVar9;
  }
LAB_1400053e1:
  _numAdapters = _numAdapters + 1;
  return 0;
}



===== RndisPnPNotify @ 140005420 =====

void RndisPnPNotify(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((int)param_2 == 1) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    uVar3 = (undefined4)((ulonglong)param_2 >> 0x20);
    *(undefined4 *)(param_1 + 0x5c) = 1;
    uVar2 = CONCAT31((int3)((ulonglong)param_2 >> 8),uVar1);
    KeReleaseSpinLock(param_1 + 0x18);
    CancelAllPendingPackets(param_1);
    AbortRndisResetMsg(param_1,CONCAT44(uVar3,uVar2),param_3);
  }
  return;
}



===== RndisReturnMessageHandler @ 140005480 =====

void RndisReturnMessageHandler(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  DequeueCompletedReadPacket(param_3);
  EnqueueFreePacket(param_3);
  return;
}



===== _guard_check_icall @ 1400054b0 =====

void _guard_check_icall(void)

{
  return;
}



===== SimulateRNDISInit @ 1400054bc =====

ulonglong SimulateRNDISInit(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  lVar2 = DequeueFreePacket(param_1);
  if (lVar2 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    puVar1 = *(undefined4 **)(lVar2 + 0x28);
    puVar1[1] = 0x18;
    *puVar1 = 2;
    puVar1[2] = 1;
    puVar1[3] = *(undefined4 *)(param_1 + 0x178);
    puVar1[4] = *(undefined4 *)(param_1 + 0x17c);
    puVar1[5] = *(undefined4 *)(param_1 + 0x180);
    *(undefined4 *)(lVar2 + 0x34) = 0x18;
    uVar3 = SubmitPacketToControlPipe(lVar2,'\x01','\x01');
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      uVar3 = SubmitNotificationRead(param_1,'\x01');
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar3 = ReadPacketFromControlPipe(lVar2,'\x01');
        uVar4 = uVar3 & 0xffffffff;
        if (-1 < (int)uVar3) {
          uVar4 = (ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x28) + 0xc);
        }
      }
    }
    EnqueueFreePacket(lVar2);
  }
  return uVar4;
}



===== SimulateRNDISSetCurrentAddress @ 140005578 =====

int SimulateRNDISSetCurrentAddress(longlong param_1)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x188);
  if (uVar5 == 0) {
    uVar5 = (uint)*(ushort *)(param_1 + 0x18c);
  }
  if (uVar5 == 0) {
    iVar2 = 0;
  }
  else {
    lVar3 = DequeueFreePacket(param_1);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      puVar1 = *(undefined4 **)(lVar3 + 0x28);
      *puVar1 = 5;
      puVar1[1] = 0x22;
      puVar1[2] = 1;
      puVar1[3] = 0x1010102;
      puVar1[4] = 6;
      puVar1[5] = 0x14;
      memmove(puVar1 + 7,(uint *)(param_1 + 0x188),6);
      *(undefined4 *)(lVar3 + 0x34) = 0x22;
      uVar4 = SubmitPacketToControlPipe(lVar3,'\x01','\x01');
      iVar2 = (int)uVar4;
      if (-1 < iVar2) {
        uVar4 = SubmitNotificationRead(param_1,'\x01');
        iVar2 = (int)uVar4;
        if (-1 < iVar2) {
          uVar4 = ReadPacketFromControlPipe(lVar3,'\x01');
          iVar2 = (int)uVar4;
          if (-1 < iVar2) {
            iVar2 = *(int *)(*(longlong *)(lVar3 + 0x28) + 0xc);
          }
        }
      }
      EnqueueFreePacket(lVar3);
    }
  }
  return iVar2;
}



===== SimulateRNDISSetPacketFilter @ 140005674 =====

ulonglong SimulateRNDISSetPacketFilter(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  lVar2 = DequeueFreePacket(param_1);
  if (lVar2 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    puVar1 = *(undefined4 **)(lVar2 + 0x28);
    puVar1[1] = 0x20;
    *puVar1 = 5;
    puVar1[2] = 1;
    puVar1[3] = 0x1010e;
    puVar1[4] = 4;
    puVar1[5] = 0x14;
    puVar1[7] = *(undefined4 *)(param_1 + 0x184);
    *(undefined4 *)(lVar2 + 0x34) = 0x20;
    uVar3 = SubmitPacketToControlPipe(lVar2,'\x01','\x01');
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      uVar3 = SubmitNotificationRead(param_1,'\x01');
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar3 = ReadPacketFromControlPipe(lVar2,'\x01');
        uVar4 = uVar3 & 0xffffffff;
        if (-1 < (int)uVar3) {
          uVar4 = (ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x28) + 0xc);
        }
      }
    }
    EnqueueFreePacket(lVar2);
  }
  return uVar4;
}



===== AbortPipe @ 140005730 =====

undefined4 AbortPipe(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  uint local_res18 [4];
  undefined4 local_b8 [6];
  undefined8 local_a0;
  
  uVar3 = 0;
  local_res18[0] = 0;
  iVar2 = GetUSBPortStatus(param_1,local_res18);
  if ((-1 < iVar2) && ((local_res18[0] & 2) != 0)) {
    lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                   *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)));
    if (lVar4 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      memset(local_b8,0,0x98);
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      local_b8[0] = 0x20028;
      *(undefined1 *)(lVar1 + -0x48) = 0xf;
      *(undefined4 *)(lVar1 + -0x30) = 0x220003;
      *(undefined4 **)(lVar1 + -0x40) = local_b8;
      local_a0 = param_2;
      uVar3 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar4,param_1 + 800);
      IoFreeIrp(lVar4);
    }
  }
  return uVar3;
}



===== AdapterFullResetAndRestore @ 140005818 =====

void AdapterFullResetAndRestore(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,10,
                      &WPP_ea5c8cde73f239b6a56eca3b059900bd_Traceguids,(char)param_1);
  }
  *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + 1;
  *(undefined1 *)(param_1 + 0x27c) = 0;
  if ((*(char *)(param_1 + 0x59) == '\0') && (*(int *)(param_1 + 0x5c) == 0)) {
    local_res8[0] = 0;
    *(undefined1 *)(param_1 + 0x5a) = 1;
    AbortRndisResetMsg(param_1,param_2,param_3);
    iVar1 = GetUSBPortStatus(param_1,local_res8);
    if ((-1 < iVar1) && ((local_res8[0] & 2) != 0)) {
      CancelAllPendingPackets(param_1);
      AbortPipe(param_1,*(undefined8 *)(param_1 + 0x60));
      ResetPipe(param_1,*(undefined8 *)(param_1 + 0x60));
      AbortPipe(param_1,*(undefined8 *)(param_1 + 0x68));
      ResetPipe(param_1,*(undefined8 *)(param_1 + 0x68));
      if (*(longlong *)(param_1 + 0x70) != 0) {
        AbortPipe(param_1,*(longlong *)(param_1 + 0x70));
        ResetPipe(param_1,*(undefined8 *)(param_1 + 0x70));
      }
      if (*(char *)(param_1 + 0x27d) == '\0') {
        ResetPort(param_1);
      }
      else {
        *(undefined1 *)(param_1 + 0x27d) = 0;
      }
      if (*(char *)(param_1 + 0x58) != '\0') {
        uVar2 = SimulateRNDISInit(param_1);
        if ((int)uVar2 < 0) {
          *(undefined1 *)(param_1 + 0x58) = 0;
        }
        else {
          SimulateRNDISSetPacketFilter(param_1);
          SimulateRNDISSetCurrentAddress(param_1);
          if (*(longlong *)(param_1 + 0x70) != 0) {
            SubmitNotificationRead(param_1,'\0');
          }
          StartUSBReadLoop(param_1);
        }
      }
    }
    *(undefined1 *)(param_1 + 0x5a) = 0;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== GetUSBPortStatus @ 1400059a0 =====

undefined4 GetUSBPortStatus(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  *param_2 = 0;
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
  if (lVar3 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x220013;
    *(undefined4 **)(lVar1 + -0x40) = param_2;
    uVar2 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar3,param_1 + 800);
    IoFreeIrp(lVar3);
  }
  return uVar2;
}



===== ResetPipe @ 140005a30 =====

undefined4 ResetPipe(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  uint local_res18 [2];
  undefined4 local_a8 [6];
  undefined8 local_90;
  
  uVar3 = 0;
  local_res18[0] = 0;
  iVar2 = GetUSBPortStatus(param_1,local_res18);
  if ((-1 < iVar2) && ((local_res18[0] & 2) != 0)) {
    lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                   *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)));
    if (lVar4 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      memset(local_a8,0,0x98);
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      local_a8[0] = 0x1e0028;
      *(undefined1 *)(lVar1 + -0x48) = 0xf;
      *(undefined4 *)(lVar1 + -0x30) = 0x220003;
      *(undefined4 **)(lVar1 + -0x40) = local_a8;
      local_90 = param_2;
      uVar3 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar4,param_1 + 800);
      IoFreeIrp(lVar4);
    }
  }
  return uVar3;
}



===== ResetPort @ 140005b18 =====

undefined4 ResetPort(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  uint local_res10 [2];
  
  uVar3 = 0;
  local_res10[0] = 0;
  iVar2 = GetUSBPortStatus(param_1,local_res10);
  if ((-1 < iVar2) && ((local_res10[0] & 2) != 0)) {
    lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                   *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
    if (lVar4 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      *(undefined1 *)(lVar1 + -0x48) = 0xf;
      *(undefined4 *)(lVar1 + -0x30) = 0x220007;
      uVar3 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar4,param_1 + 800);
      IoFreeIrp(lVar4);
    }
  }
  return uVar3;
}



===== ServiceReadDeficit @ 140005bb8 =====

void ServiceReadDeficit(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  lVar1 = param_1 + 0x18;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  iVar4 = *(int *)(param_1 + 0x194);
  if (iVar4 != 0) {
    iVar3 = iVar4;
    do {
      if (((iVar4 == 0) || (*(char *)(param_1 + 0x59) != '\0')) || (*(int *)(param_1 + 0x5c) != 0))
      break;
      *(int *)(param_1 + 0x194) = iVar3 + -1;
      iVar4 = iVar4 + -1;
      KeReleaseSpinLock(lVar1,uVar2);
      TryReadUSB(param_1);
      uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
      iVar3 = *(int *)(param_1 + 0x194);
    } while (iVar3 != 0);
  }
  KeReleaseSpinLock(lVar1);
  return;
}



===== WPP_RECORDER_SF_dd @ 140005c60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ea5c8cde73f239b6a56eca3b059900bd_Traceguids,0xb,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_ea5c8cde73f239b6a56eca3b059900bd_Traceguids,0xb,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== AllocPool @ 140005d30 =====

void * AllocPool(uint param_1)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocatePool2(0x40,param_1,0x32303855);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,(ulonglong)param_1);
  }
  return _Dst;
}



===== MemDup @ 140005d80 =====

void * MemDup(void *param_1,uint param_2)

{
  void *_Dst;
  
  _Dst = AllocPool(param_2);
  if (_Dst != (void *)0x0) {
    memmove(_Dst,param_1,(ulonglong)param_2);
  }
  return _Dst;
}



===== __GSHandlerCheck @ 140005dd8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140005dfc =====

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



===== __cpu_features_init @ 140005e70 =====

/* WARNING: Removing unreachable block (ram,0x000140005eda) */
/* WARNING: Removing unreachable block (ram,0x000140005e89) */
/* WARNING: Removing unreachable block (ram,0x000140005e7a) */

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



===== __security_check_cookie @ 140005f40 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005f80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005fb0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005fb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005fe0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140006040 =====

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



===== memset @ 140006340 =====

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



===== __memset_repmovs @ 140006480 =====

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



===== __memset_query @ 140006500 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006580 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400066c0 =====

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



===== __memset_spec_plain @ 140006740 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14000c008 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000c0d4 =====

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
      goto LAB_14000c131;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000c131;
    }
  }
  uVar1 = 0x206;
LAB_14000c131:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000c13c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_92507448__private_descriptor);
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
  ppuVar2 = &Feature_92507448__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000c1f4 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000c22c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000c2ae;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000c2ae;
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
LAB_14000c2ae:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000c300 =====

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
      ppuVar3 = &Feature_92507448__private_descriptor;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000c360 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UnregisterFeatureStagingChangeNotification @ 14000c37c =====

void wil_details_UnregisterFeatureStagingChangeNotification(void)

{
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  return;
}



===== wil_details_UnregisterFeatureUsageProvider @ 14000c3ac =====

void wil_details_UnregisterFeatureUsageProvider(void)

{
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000c3dc =====

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
  ppuVar3 = &Feature_92507448__private_descriptor;
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



===== entry @ 14000d010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14000d044 =====

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



===== DriverEntry @ 14000d078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  KeInitializeSpinLock(&globalSpinLock);
  DAT_140009118 = &allAdaptersList;
  _allAdaptersList = &allAdaptersList;
  wil_InitializeFeatureStaging();
  uVar2 = Feature_92507448__private_IsEnabledDeviceUsageNoInline();
  g_Feature_MSRC124032_IsEnabled = (int)uVar2 != 0;
  bVar1 = RegisterRNDISMicroport(param_1,param_2);
  if (bVar1) {
    uVar3 = 0;
  }
  else {
    wil_details_UnregisterFeatureStagingChangeNotification();
    wil_details_UnregisterFeatureUsageProvider();
    g_wil_details_isFeatureStagingInitialized = 0;
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== wil_InitializeFeatureStaging @ 14000d100 =====

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
    ppuVar4 = &Feature_92507448__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000d1f0 =====

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
  ppuVar3 = &Feature_92507448__private_descriptor;
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


