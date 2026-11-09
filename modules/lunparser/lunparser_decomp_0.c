
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



===== ContextListAdd @ 1c0001020 =====

undefined8 ContextListAdd(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar5 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&ContextListSpinLock,&local_28);
  puVar3 = auStack_48;
  puVar4 = auStack_48;
  if ((undefined8 **)ContextListHead != &ContextListHead) {
    puVar2 = ContextListHead;
    do {
      if (puVar2[2] == param_1[2]) goto LAB_1c000108f;
      puVar2 = (undefined8 *)*puVar2;
    } while ((undefined8 **)puVar2 != &ContextListHead);
  }
  if ((undefined8 **)ContextListHead[1] == &ContextListHead) {
    *param_1 = ContextListHead;
    param_1[1] = &ContextListHead;
    ContextListHead[1] = param_1;
    ContextListHead = param_1;
  }
  else {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(3);
    puVar3 = auStack_40;
LAB_1c000108f:
    uVar5 = 0xc0000043;
    puVar4 = puVar3;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c00010b4;
  KeReleaseInStackQueuedSpinLock(puVar4 + 0x20);
  return uVar5;
}



===== ContextListRemove @ 1c00010d0 =====

void ContextListRemove(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*param_1 != 0) && (param_1[1] != 0)) {
    KeAcquireInStackQueuedSpinLock(&ContextListSpinLock,&local_28);
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
    *param_1 = 0;
    param_1[1] = 0;
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return;
}



===== DriverEntry @ 1c0001154 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStackY_1a8 [32];
  short *local_178 [2];
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  longlong local_150;
  code *local_148;
  code *local_140;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_48;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1a8;
  memset(&local_168,0,0x140);
  _DAT_1c0007148 = 1;
  local_178[0] = (short *)0x0;
  DAT_1c0007128 = &WPP_ThisDir_CTLGUID_LunparserTraceGuid;
  _WPP_MAIN_CB = 0;
  DAT_1c0007130 = 0;
  _DAT_1c0007140 = 0;
  _DAT_1c0007160 = 0;
  _DAT_1c0007168 = 0;
  WppLoadTracingSupport();
  _DAT_1c0007140 = 0;
  WppInitKm(param_1,param_2);
  *(code **)(param_1 + 0x68) = LunParserUnload;
  iVar1 = IoGetDeviceInterfaces(&GUID_STORVSP,0,0,local_178);
  if ((iVar1 < 0) || (*local_178[0] == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,10,
                       &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
    }
    iVar1 = -0x3fffffff;
  }
  else {
    KeInitializeSpinLock(&ContextListSpinLock);
    local_168 = 0x140;
    _DAT_1c00070d8 = &ContextListHead;
    ContextListHead = &ContextListHead;
    local_148 = LunParserOpenDisk;
    local_140 = LunParserCloseDisk;
    local_130 = LunParserMountDisk;
    local_128 = LunParserDismountDisk;
    local_120 = LunParserQueryMountStatusDisk;
    local_118 = LunParserExecuteScsiRequestDisk;
    local_108 = LunParserQuerySaveVersionDisk;
    local_100 = LunParserSaveDisk;
    local_f8 = LunParserRestoreDisk;
    local_f0 = LunParserSetBehaviorDisk;
    local_48 = LunParserSupportsDataTransferDirectionValidation;
    local_164 = 6;
    local_160 = 0x2ed37f68;
    uStack_15c = 0x4c55a6e1;
    uStack_158 = 0x752802be;
    uStack_154 = 0x212656a3;
    local_150 = param_1;
    iVar1 = VstorRegisterParser(&local_168);
    if (-1 < iVar1) goto LAB_1c0001385;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xb,
                       &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
    }
  }
  WppCleanupKm(param_1);
LAB_1c0001385:
  if (local_178[0] != (short *)0x0) {
    ExFreePoolWithTag(local_178[0],0);
  }
  return iVar1;
}



===== LunParserExecuteScsiRequestDisk @ 1c00013d0 =====

void LunParserExecuteScsiRequestDisk(longlong param_1,undefined8 *param_2)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x16,
                     &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
  }
  LunParserHandleSRB(param_1,param_2);
  return;
}



===== LunParserSupportsDataTransferDirectionValidation @ 1c0001440 =====

undefined1 LunParserSupportsDataTransferDirectionValidation(void)

{
  return 1;
}



===== LunParserSyncIo @ 1c000144c =====

undefined4
LunParserSyncIo(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x10) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x4c)),0);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 0x48);
    *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) | 1;
    lVar2 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar3 + 0x98) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x10);
    *(undefined4 *)(lVar2 + -0x38) = 0;
    *(undefined8 *)(lVar2 + -0x20) = uVar1;
    *(undefined1 *)(lVar2 + -0x48) = 0xe;
    *(undefined4 *)(lVar2 + -0x40) = 8;
    *(undefined4 *)(lVar2 + -0x30) = 0x41018;
    *(undefined8 *)(lVar3 + 0x18) = param_4;
    IoSynchronousCallDriver(*(undefined8 *)(lVar2 + -0x20),lVar3);
    uVar4 = *(undefined4 *)(lVar3 + 0x30);
    IoFreeIrp(lVar3);
  }
  return uVar4;
}



===== WPP_RECORDER_SF_ @ 1c00014fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c00015d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_dddd @ 1c00016c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids,0x11,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids,0x11,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_id @ 1c00017d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_id(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids,param_4,&param_6,8,
                  &param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c00018b0 =====

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



===== LunParserBuildScsi @ 1c000190c =====

void LunParserBuildScsi(longlong param_1,undefined8 *param_2,longlong param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  longlong lVar5;
  size_t _Size;
  
  puVar3 = (undefined4 *)*param_2;
  lVar4 = param_2[1];
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x26,
                     &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
  }
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) | 1;
  *(undefined8 *)(param_3 + 8) = param_2[2];
  lVar5 = *(longlong *)(param_3 + 0xb8);
  *(code **)(lVar5 + -0x10) = LunParserCompleteIo;
  *(undefined8 **)(lVar5 + -8) = param_2;
  *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  memset(puVar3 + 1,0,0x54);
  *puVar3 = 0x58;
  *(undefined1 *)((longlong)puVar3 + 5) = *(undefined1 *)(param_1 + 0x25);
  *(undefined1 *)((longlong)puVar3 + 6) = *(undefined1 *)(param_1 + 0x26);
  *(undefined1 *)((longlong)puVar3 + 7) = *(undefined1 *)(param_1 + 0x27);
  *(undefined1 *)((longlong)puVar3 + 10) = *(undefined1 *)(lVar4 + 8);
  *(undefined1 *)((longlong)puVar3 + 0xb) = 0x14;
  *(undefined4 **)(puVar3 + 8) = puVar3 + 0x16;
  puVar3[4] = *(undefined4 *)(lVar4 + 0xc);
  *(undefined1 *)(puVar3 + 2) = *(undefined1 *)(lVar4 + 0x26);
  *(undefined1 *)((longlong)puVar3 + 9) = *(undefined1 *)(lVar4 + 0x27);
  uVar1 = *(uint *)(lVar4 + 0x28);
  puVar3[3] = uVar1;
  puVar3[5] = 0x28;
  uVar2 = *(undefined4 *)(lVar4 + 0x30);
  puVar3[3] = uVar1 & 0xffdffbff;
  *(undefined1 *)((longlong)puVar3 + 0xf) = 0;
  puVar3[3] = puVar3[3] | 0x100;
  puVar3[0x10] = uVar2;
  lVar5 = param_2[2];
  if (lVar5 != 0) {
    *(ulonglong *)(puVar3 + 6) = (ulonglong)*(uint *)(lVar5 + 0x2c) + *(longlong *)(lVar5 + 0x20);
  }
  *(longlong *)(puVar3 + 0xc) = param_3;
  _Size = 0x10;
  if (*(byte *)(lVar4 + 8) < 0x10) {
    _Size = (size_t)*(byte *)(lVar4 + 8);
  }
  memcpy(puVar3 + 0x12,(void *)(lVar4 + 0x10),_Size);
  lVar4 = *(longlong *)(param_3 + 0xb8);
  *(byte *)(lVar4 + -0x46) = *(byte *)(lVar4 + -0x46) | 2;
  *(undefined2 *)(lVar4 + -0x48) = 0x10f;
  *(undefined4 **)(lVar4 + -0x40) = puVar3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqDdddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== LunParserCompleteIo @ 1c0001ad0 =====

undefined8 LunParserCompleteIo(undefined8 param_1,longlong param_2,longlong *param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  uint uVar10;
  undefined **ppuVar11;
  longlong *plVar12;
  undefined1 uVar13;
  byte bVar14;
  undefined8 in_stack_ffffffffffffff98;
  
  lVar3 = *param_3;
  bVar9 = false;
  lVar4 = param_3[1];
  bVar14 = 0;
  iVar2 = *(int *)(param_2 + 0x30);
  lVar5 = *(longlong *)(lVar3 + 0x70);
  pbVar1 = (byte *)(lVar3 + 0x58);
  uVar13 = 0;
  plVar12 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  ppuVar11 = &WPP_RECORDER_INITIALIZED;
  if (*(longlong *)(param_2 + 8) != 0) {
    *(undefined8 *)(param_2 + 8) = 0;
  }
  *(undefined1 *)(lVar4 + 3) = *(undefined1 *)(lVar3 + 4);
  *(undefined1 *)(lVar4 + 2) = *(undefined1 *)(lVar3 + 3);
  *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(lVar3 + 0x10);
  uVar6 = *(undefined4 *)(lVar3 + 0x5c);
  uVar7 = *(undefined4 *)(lVar3 + 0x60);
  uVar8 = *(undefined4 *)(lVar3 + 100);
  *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)pbVar1;
  *(undefined4 *)(lVar4 + 0x14) = uVar6;
  *(undefined4 *)(lVar4 + 0x18) = uVar7;
  *(undefined4 *)(lVar4 + 0x1c) = uVar8;
  *(undefined4 *)(lVar4 + 0x20) = *(undefined4 *)(lVar3 + 0x68);
  if (-1 < *(char *)(lVar3 + 3)) goto LAB_1c0001c19;
  if ((byte)((*pbVar1 & 0x7f) + 0x8e) < 2) {
    if (lVar3 + 0x60U <= lVar3 + 0x6cU) {
      uVar13 = *(undefined1 *)(lVar3 + 0x5a);
      bVar14 = *(byte *)(lVar3 + 0x59) & 0xf;
      goto LAB_1c0001bdb;
    }
  }
  else if (lVar3 + 0x60U <= lVar3 + 0x6cU) {
    uVar10 = *(byte *)(lVar3 + 0x5f) + 8;
    if (0x14 < uVar10) {
      uVar10 = 0x14;
    }
    bVar14 = *(byte *)(lVar3 + 0x5a) & 0xf;
    if ((byte *)(lVar3 + 0x65U) <= pbVar1 + uVar10) {
      uVar13 = *(undefined1 *)(lVar3 + 100);
    }
LAB_1c0001bdb:
    bVar9 = true;
  }
  if ((bVar9) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,plVar12
                        ,0x30,in_stack_ffffffffffffff98,(char)*(undefined4 *)(param_2 + 0x38),bVar14
                        ,uVar13);
  }
LAB_1c0001c19:
  if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),ppuVar11,4,0x31,
                      &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,(char)iVar2);
  }
  if (bVar9) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (-1 < iVar2) {
    UpdatePR(lVar5,param_3);
  }
  VstorCompleteScsiRequest(param_3);
  return 0xc0000016;
}



===== LunParserHandleSRB @ 1c0001d08 =====

void LunParserHandleSRB(longlong param_1,undefined8 *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  void *_Dst;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  bool bVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined1 uVar12;
  undefined8 uVar13;
  ulonglong in_stack_ffffffffffffffa8;
  
  _Dst = (void *)*param_2;
  lVar5 = param_2[1];
  bVar8 = false;
  pcVar1 = (char *)(lVar5 + 0x10);
  TraceSrb(lVar5);
  uVar11 = 0;
  *(undefined1 *)(lVar5 + 3) = 0;
  uVar13 = 0x90;
  memset(_Dst,0,0x90);
  *(longlong *)((longlong)_Dst + 0x70) = param_1;
  if ((*pcVar1 == -0x7d) && (iVar9 = LunParserVerifyExCopyCdb((longlong)param_2), iVar9 < 0)) {
    if (iVar9 == -0x3fffff45) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x29,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar11,4,0x2a,
                          &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,(char)iVar9);
      }
LAB_1c0001ece:
      if (iVar9 == -0x7ffffffb) {
        uVar12 = 0x12;
        goto LAB_1c00020dc;
      }
      if (iVar9 == -0x7fffffef) {
        uVar12 = 5;
        goto LAB_1c00020dc;
      }
      if (iVar9 == -0x3ffffff0) goto LAB_1c0001fce;
      if (iVar9 == -0x3fffffdd) goto LAB_1c0002068;
      if (iVar9 == -0x3fffff66) goto LAB_1c00020d9;
      if (iVar9 == -0x3fffff63) {
        uVar12 = 10;
        goto LAB_1c00020dc;
      }
      if (iVar9 == -0x3fffff4b) {
        uVar12 = 9;
        goto LAB_1c00020dc;
      }
      if (iVar9 == -0x3fffff40) {
        uVar12 = 8;
        goto LAB_1c00020dc;
      }
    }
    uVar12 = 4;
  }
  else {
    cVar2 = *pcVar1;
    if ((((cVar2 == '\b') ||
         ((((cVar2 == '\n' || (cVar2 == '(')) || (cVar2 == '*')) ||
          ((cVar2 == -0x78 || (cVar2 == -0x76)))))) || (cVar2 == -0x58)) || (cVar2 == -0x56)) {
      bVar8 = true;
    }
    lVar6 = param_2[2];
    uVar3 = *(uint *)(lVar5 + 0xc);
    if (lVar6 != 0) {
      if (((char)*(undefined4 *)(lVar6 + 0x2c) + *(char *)(lVar6 + 0x20) & 1U) == 0) {
        if (((uVar3 & 1) == 0) || (!bVar8)) goto LAB_1c0001f52;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      iVar9 = -0x3ffffff0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x2b,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
      }
      goto LAB_1c0001ece;
    }
LAB_1c0001f52:
    if ((*(char *)(param_1 + 0x28) == '\0') && (uVar3 != 0)) {
      uVar4 = *(uint *)(lVar5 + 0x28);
      if ((uVar4 & 0xc0) == 0) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar4,uVar13,
                                0x28,in_stack_ffffffffffffffa8,*(undefined1 *)(lVar5 + 0x10),
                                (char)uVar4,(char)uVar3),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x2c,
                           &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
        }
LAB_1c0001fce:
        uVar12 = 0x22;
        goto LAB_1c00020dc;
      }
    }
    lVar6 = (longlong)_Dst + 0x90;
    IoInitializeIrp(lVar6,*(undefined2 *)(param_1 + 0x2a),
                    CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x10) >> 8),
                             *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x4c)));
    *(undefined8 *)((longlong)_Dst + 0x128) = *(undefined8 *)(param_1 + 0x48);
    LunParserBuildScsi(param_1,param_2,lVar6);
    if ((param_2[2] == 0) || (*pcVar1 != '_')) {
LAB_1c0002108:
      IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar6);
      return;
    }
    if (0x17 < *(uint *)(lVar5 + 0xc)) {
      lVar7 = *(longlong *)((longlong)_Dst + 0x98);
      if ((*(byte *)(lVar7 + 10) & 5) == 0) {
        puVar10 = (undefined1 *)
                  MmMapLockedPagesSpecifyCache
                            (lVar7,0,1,0,in_stack_ffffffffffffffa8 & 0xffffffff00000000,0x40000010);
      }
      else {
        puVar10 = *(undefined1 **)(lVar7 + 0x18);
      }
      if (puVar10 != (undefined1 *)0x0) {
        TrackPROut(pcVar1,puVar10,(undefined1 *)((longlong)_Dst + 0x78));
        goto LAB_1c0002108;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x2e,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
      }
LAB_1c00020d9:
      uVar12 = 0x30;
      goto LAB_1c00020dc;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x2d,
                       &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
    }
LAB_1c0002068:
    uVar12 = 6;
  }
LAB_1c00020dc:
  *(undefined1 *)(lVar5 + 2) = uVar12;
  VstorCompleteScsiRequest(param_2);
  return;
}



===== LunParserVerifyExCopyCdb @ 1c000213c =====

undefined4 LunParserVerifyExCopyCdb(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  
  lVar1 = *(longlong *)(param_1 + 8);
  lVar2 = 0;
  uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar1 + 0x1a),*(undefined1 *)(lVar1 + 0x1b)),
                            *(undefined1 *)(lVar1 + 0x1c)),*(undefined1 *)(lVar1 + 0x1d));
  if (uVar4 <= *(uint *)(lVar1 + 0xc)) {
    bVar3 = *(byte *)(lVar1 + 0x11) & 0x1f;
    if ((bVar3 == 0x10) || (bVar3 == 0x11)) {
      lVar2 = *(longlong *)(param_1 + 0x10);
      if (lVar2 == 0) {
        return 0xc000000d;
      }
      if ((*(byte *)(lVar2 + 10) & 5) == 0) {
        lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
      }
      else {
        lVar2 = *(longlong *)(lVar2 + 0x18);
      }
      if (lVar2 == 0) {
        return 0xc000009a;
      }
    }
    bVar3 = *(byte *)(lVar1 + 0x11) & 0x1f;
    if (bVar3 == 0x10) {
      if (0x1f < uVar4) {
        if ((*(byte *)(lVar2 + 2) & 1) == 0) {
          return 0;
        }
        return 0xc00000bb;
      }
    }
    else {
      if (bVar3 != 0x11) {
        if (bVar3 == 0x1c) {
          return 0;
        }
        return 0xc0000002;
      }
      if (0x227 < uVar4) {
        if ((*(byte *)(lVar2 + 2) & 1) == 0) {
          return 0;
        }
        return 0xc00000bb;
      }
    }
  }
  return 0x80000005;
}



===== TraceSrb @ 1c0002248 =====

void TraceSrb(longlong param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if ((((((cVar1 == '\b') || (cVar1 == '\n')) || (cVar1 == '(')) ||
       ((cVar1 == '*' || (cVar1 == '5')))) ||
      ((cVar1 == -0x78 || ((cVar1 == -0x76 || (cVar1 == -0x58)))))) || (cVar1 == -0x56)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dDDDDDDDDDDDDDDDDsDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dDDDDDDDDDDDDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== TrackPROut @ 1c000280c =====

void TrackPROut(char *param_1,undefined1 *param_2,undefined1 *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  undefined *in_stack_ffffffffffffffd8;
  
  if (param_2 == (undefined1 *)0x0) {
    return;
  }
  if (param_3 == (undefined1 *)0x0) {
    return;
  }
  if (*param_1 != '_') {
    return;
  }
  *param_3 = 0;
  bVar1 = param_1[1];
  uVar4 = (ulonglong)bVar1;
  bVar2 = bVar1 & 0x1f;
  puVar5 = param_3;
  if ((bVar1 & 0x1f) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffffd8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
      uVar4 = 4;
      puVar5 = (undefined1 *)0x5;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,10,
                       &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
    }
LAB_1c0002ad1:
    param_3[0xf] = *param_2;
    param_3[0xe] = param_2[1];
    param_3[0xd] = param_2[2];
    param_3[0xc] = param_2[3];
    param_3[0xb] = param_2[4];
    param_3[10] = param_2[5];
    param_3[9] = param_2[6];
    param_3[8] = param_2[7];
LAB_1c0002b00:
    param_3[0x17] = param_2[8];
    param_3[0x16] = param_2[9];
    param_3[0x15] = param_2[10];
    param_3[0x14] = param_2[0xb];
    param_3[0x13] = param_2[0xc];
    param_3[0x12] = param_2[0xd];
    param_3[0x11] = param_2[0xe];
    param_3[0x10] = param_2[0xf];
  }
  else {
    if (bVar2 == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffffd8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
        uVar4 = 4;
        puVar5 = (undefined1 *)0x5;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xd,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
      }
      bVar1 = param_1[2];
      uVar3 = (uint)bVar1;
      if (((bVar1 & 0xf0) != 0) || ((bVar1 & 0xf) != 5)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar6 = 0xe;
        goto LAB_1c0002a74;
      }
    }
    else if (bVar2 == 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffffd8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
        uVar4 = 4;
        puVar5 = (undefined1 *)0x5;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xf,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
      }
      bVar1 = param_1[2];
      uVar3 = (uint)bVar1;
      if (((bVar1 & 0xf0) != 0) || ((bVar1 & 0xf) != 5)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar6 = 0x10;
        goto LAB_1c0002a74;
      }
    }
    else {
      if (bVar2 != 3) {
        if ((bVar2 == 4) || (bVar2 == 5)) {
          uVar4 = (ulonglong)(bVar1 & 0x1f);
          if ((bVar1 & 0x1f) == 5) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar6 = 0x11;
LAB_1c00028f9:
              puVar5 = (undefined1 *)0x5;
              in_stack_ffffffffffffffd8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
              uVar4 = 4;
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,uVar6,
                               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
            }
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar6 = 0x12;
            goto LAB_1c00028f9;
          }
          bVar1 = param_1[2];
          uVar3 = (uint)bVar1;
          if (((bVar1 & 0xf0) != 0) || ((bVar1 & 0xf) != 5)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return;
            }
            uVar6 = 0x13;
LAB_1c0002a74:
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,puVar5,uVar6,
                               in_stack_ffffffffffffffd8,(char)(uVar3 >> 4),(byte)uVar3 & 0xf);
            return;
          }
          goto LAB_1c0002ad1;
        }
        if (bVar2 != 6) {
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 4;
          puVar5 = (undefined1 *)0x5;
          in_stack_ffffffffffffffd8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xb,
                           &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
        }
        goto LAB_1c0002b00;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffffd8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
        uVar4 = 4;
        puVar5 = (undefined1 *)0x5;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xc,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
      }
    }
    param_3[0xf] = *param_2;
    param_3[0xe] = param_2[1];
    param_3[0xd] = param_2[2];
    param_3[0xc] = param_2[3];
    param_3[0xb] = param_2[4];
    param_3[10] = param_2[5];
    param_3[9] = param_2[6];
    param_3[8] = param_2[7];
  }
  *param_3 = 1;
  param_3[1] = param_1[1] & 0x1f;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,puVar5,0x14,
                       in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_3 + 8),
                       (char)*(undefined8 *)(param_3 + 0x10));
  }
  return;
}



===== UpdatePR @ 1c0002b88 =====

void UpdatePR(longlong param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined *puVar8;
  
  lVar2 = *param_2;
  lVar3 = param_2[1];
  if (*(char *)(lVar2 + 0x78) == '\0') {
    return;
  }
  if ((*(char *)(lVar3 + 3) != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,5,0x15,
                      &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,*(char *)(lVar3 + 3));
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x30);
  cVar1 = *(char *)(lVar2 + 0x79);
  if (cVar1 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 5;
      puVar8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
      uVar5 = 4;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x16,
                       &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x17,puVar8,
                           (char)*(undefined8 *)(lVar2 + 0x80),(char)*(undefined8 *)(lVar2 + 0x88));
      }
    }
LAB_1c0002f21:
    if (*(char *)(lVar3 + 3) != '\0') goto LAB_1c0002f32;
    uVar5 = *(undefined8 *)(lVar2 + 0x88);
  }
  else {
    if (cVar1 == '\x01') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 5;
        puVar8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
        uVar5 = 4;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1c,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x1d,puVar8,
                            (char)*(undefined8 *)(lVar2 + 0x80));
        }
      }
    }
    else {
      if (cVar1 == '\x02') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 5;
          puVar8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
          uVar5 = 4;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1e,
                           &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x1f,puVar8,
                              (char)*(undefined8 *)(lVar2 + 0x80));
          }
        }
        if (*(char *)(lVar3 + 3) != '\0') goto LAB_1c0002f32;
        uVar5 = *(undefined8 *)(lVar2 + 0x80);
        *(undefined1 *)(param_1 + 0x40) = 0;
        goto LAB_1c0002f2e;
      }
      if (cVar1 == '\x03') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 5;
          puVar8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
          uVar5 = 4;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1a,
                           &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x1b,puVar8,
                              (char)*(undefined8 *)(lVar2 + 0x80));
          }
        }
        if (*(char *)(lVar3 + 3) == '\0') {
          *(undefined8 *)(param_1 + 0x38) = 0;
          *(undefined1 *)(param_1 + 0x40) = 0;
        }
        goto LAB_1c0002f32;
      }
      if (cVar1 != '\x04') {
        if (cVar1 != '\x05') {
          if (cVar1 != '\x06') goto LAB_1c0002f32;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar6 = 5;
            puVar8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
            uVar5 = 4;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x18,
                             &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x19,puVar8,
                                (char)*(undefined8 *)(lVar2 + 0x88));
            }
          }
          goto LAB_1c0002f21;
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 4;
        uVar7 = 0x20;
        if (cVar1 != '\x05') {
          uVar7 = 0x21;
        }
        uVar6 = 5;
        puVar8 = &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,uVar7,
                         &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x22,puVar8,
                             (char)*(undefined8 *)(lVar2 + 0x80),(char)*(undefined8 *)(lVar2 + 0x88)
                            );
        }
      }
    }
    if (*(char *)(lVar3 + 3) != '\0') goto LAB_1c0002f32;
    uVar5 = *(undefined8 *)(lVar2 + 0x80);
    *(undefined1 *)(param_1 + 0x40) = 1;
  }
LAB_1c0002f2e:
  *(undefined8 *)(param_1 + 0x38) = uVar5;
LAB_1c0002f32:
  KeReleaseSpinLock(param_1 + 0x30,uVar4);
  return;
}



===== WPP_RECORDER_SF_D @ 1c0002f6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x23,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x23,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_DD @ 1c0003018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x33,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x33,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_DDD @ 1c00030e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,4,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_DDDD @ 1c00031d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x32,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x32,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_dDDDDDDDDDDDDDDDDDDDDD @ 1c00032d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dDDDDDDDDDDDDDDDDDDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  undefined1 uStack0000000000000088;
  undefined1 uStack0000000000000090;
  undefined1 uStack0000000000000098;
  undefined1 uStack00000000000000a0;
  undefined1 uStack00000000000000a8;
  undefined1 uStack00000000000000b0;
  undefined1 uStack00000000000000b8;
  undefined1 uStack00000000000000c0;
  undefined1 uStack00000000000000c8;
  undefined1 uStack00000000000000d0;
  undefined1 uStack00000000000000d8;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x25,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,&uStack0000000000000090,4,
               &uStack0000000000000098,4,&uStack00000000000000a0,4,&uStack00000000000000a8,4,
               &uStack00000000000000b0,4,&uStack00000000000000b8,4,&uStack00000000000000c0,4,
               &uStack00000000000000c8,4,&uStack00000000000000d0,4,&uStack00000000000000d8,4,0);
  }
  WppAutoLogTrace(param_1,4,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x25,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                  &uStack0000000000000090,4,&uStack0000000000000098,4,&uStack00000000000000a0,4,
                  &uStack00000000000000a8,4,&uStack00000000000000b0,4,&uStack00000000000000b8,4,
                  &uStack00000000000000c0,4,&uStack00000000000000c8,4,&uStack00000000000000d0,4,
                  &uStack00000000000000d8,4,0);
  return;
}



===== WPP_RECORDER_SF_dDDDDDDDDDDDDDDDDsDDDDDDDD @ 1c000366c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dDDDDDDDDDDDDDDDDsDDDDDDDD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  undefined1 uStack0000000000000088;
  undefined1 uStack0000000000000090;
  undefined1 uStack0000000000000098;
  undefined1 uStack00000000000000a0;
  undefined1 uStack00000000000000a8;
  undefined1 uStack00000000000000b0;
  char *in_stack_000000b8;
  undefined1 uStack00000000000000c0;
  undefined1 uStack00000000000000c8;
  undefined1 uStack00000000000000d0;
  undefined1 uStack00000000000000d8;
  undefined1 uStack00000000000000e0;
  undefined1 uStack00000000000000e8;
  undefined1 uStack00000000000000f0;
  undefined1 uStack00000000000000f8;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_000000b8 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_000000b8[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_000000b8;
    if (in_stack_000000b8 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x24,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,&uStack0000000000000090,4,
               &uStack0000000000000098,4,&uStack00000000000000a0,4,&uStack00000000000000a8,4,
               &uStack00000000000000b0,4,pcVar1,lVar3,&uStack00000000000000c0,4,
               &uStack00000000000000c8,4,&uStack00000000000000d0,4,&uStack00000000000000d8,4,
               &uStack00000000000000e0,4,&uStack00000000000000e8,4,&uStack00000000000000f0,4,
               &uStack00000000000000f8,4,0);
  }
  lVar3 = -1;
  if (in_stack_000000b8 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_000000b8[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_000000b8 == (char *)0x0) {
    in_stack_000000b8 = "NULL";
  }
  WppAutoLogTrace(param_1,4,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x24,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                  &uStack0000000000000090,4,&uStack0000000000000098,4,&uStack00000000000000a0,4,
                  &uStack00000000000000a8,4,&uStack00000000000000b0,4,in_stack_000000b8,lVar2,
                  &uStack00000000000000c0,4,&uStack00000000000000c8,4,&uStack00000000000000d0,4,
                  &uStack00000000000000d8,4,&uStack00000000000000e0,4,&uStack00000000000000e8,4,
                  &uStack00000000000000f0,4,&uStack00000000000000f8,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 1c0003b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,3,5,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_i @ 1c0003c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_i(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_ii @ 1c0003cdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c0003dac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x2f,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x2f,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_qqDdddd @ 1c0003e7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqDdddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x27,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_1,4,4,&WPP_1aadb3db1da037be85de3c75ec1e45a2_Traceguids,0x27,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== _guard_check_icall @ 1c0004000 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0004018 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000403c =====

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



===== __cpu_features_init @ 1c00040b0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000411a) */
/* WARNING: Removing unreachable block (ram,0x0001c00040c9) */
/* WARNING: Removing unreachable block (ram,0x0001c00040ba) */

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



===== __security_check_cookie @ 1c0004180 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00041c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00041f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00041f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004220 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004280 =====

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



===== memset @ 1c0004580 =====

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



===== __memset_repmovs @ 1c00046c0 =====

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



===== __memset_query @ 1c0004740 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00047c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004900 =====

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



===== __memset_spec_plain @ 1c0004980 =====

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



===== LunParserCloseDisk @ 1c000a010 =====

void LunParserCloseDisk(longlong *param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x15,
                     &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
  }
  ContextListRemove(param_1);
  if (param_1[2] != 0) {
    ObfDereferenceObject();
    param_1[2] = 0;
  }
  if (param_1[9] != 0) {
    ObfDereferenceObject();
    param_1[9] = 0;
  }
  ExFreePoolWithTag(param_1,0x7372504c);
  return;
}



===== LunParserDismountDisk @ 1c000a0b0 =====

void LunParserDismountDisk(longlong param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x13,
                     &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
  }
  *(undefined1 *)(param_1 + 0x1c) = 0;
  return;
}



===== LunParserMountDisk @ 1c000a110 =====

undefined8 LunParserMountDisk(longlong param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x12,
                     &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
  }
  *(undefined1 *)(param_1 + 0x1c) = 1;
  *param_4 = *(ushort *)(param_1 + 0x2a) + 0x90;
  *(undefined1 *)(param_4 + 1) = 1;
  return 0;
}



===== LunParserOpenDisk @ 1c000a180 =====

ulonglong LunParserOpenDisk(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                           undefined8 *param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  undefined8 *puVar10;
  uint uVar11;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar12;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  local_54 = 0;
  puVar10 = (undefined8 *)0x0;
  local_3c = 0;
  lVar6 = 0;
  plVar3 = (longlong *)0x0;
  local_res8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0xd,
                     &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
  }
  puVar1 = param_5;
  *param_5 = 0;
  local_50 = 0;
  uVar11 = ~(param_2 << 0x1c) & 0xc0000000 | 0x80000000;
  local_58 = 0x30;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = param_1;
  uVar2 = IoCreateFile(&local_res8,uVar11,&local_58,&local_68,0,CONCAT44(uVar12,0x80),
                       (param_2 & 1) * 2 + 1,1,0x48,0,0,0,0,0x101);
  uVar7 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a47a;
    uVar9 = 0xe;
  }
  else {
    param_5 = (undefined8 *)0x0;
    uVar2 = ObReferenceObjectByHandle
                      (local_res8,0,*(undefined8 *)IoFileObjectType_exref,0,&param_5,0);
    puVar10 = param_5;
    uVar7 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      lVar6 = param_5[1];
      ObfReferenceObject(lVar6);
      uVar5 = 0x50;
      uVar8 = 0x7372504c;
      plVar3 = (longlong *)ExAllocatePool2(0x40);
      if (plVar3 == (longlong *)0x0) {
        uVar7 = 0xc000009a;
      }
      else {
        plVar3[2] = lVar6;
        lVar6 = 0;
        *(uint *)(plVar3 + 3) = uVar11;
        KeInitializeSpinLock(plVar3 + 6);
        *(short *)((longlong)plVar3 + 0x2a) = *(char *)(plVar3[2] + 0x4c) * 0x48 + 0xd0;
        plVar3[9] = (longlong)SystemReserved1[0xf];
        ObfReferenceObject();
        uVar2 = LunParserSyncIo((longlong)plVar3,uVar5,uVar8,plVar3 + 4);
        uVar7 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,3,0x10,
                              &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids,(char)uVar2);
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          if ((param_2 & 1) == 0) {
            uVar4 = ContextListAdd(plVar3);
            uVar7 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) goto LAB_1c000a47a;
          }
          *puVar1 = plVar3;
          plVar3 = (longlong *)0x0;
          uVar7 = 0;
        }
      }
      goto LAB_1c000a47a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a47a;
    uVar9 = 0xf;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar9,
                   &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
LAB_1c000a47a:
  if (local_res8 != 0) {
    ZwClose();
  }
  if (puVar10 != (undefined8 *)0x0) {
    ObfDereferenceObject(puVar10);
  }
  if (plVar3 != (longlong *)0x0) {
    LunParserCloseDisk(plVar3);
  }
  if (lVar6 != 0) {
    ObfDereferenceObject(lVar6);
  }
  if (((int)uVar7 == -0x3fffffcc) || ((int)uVar7 == -0x3fffffc6)) {
    uVar7 = 0xe03a0019;
  }
  return uVar7;
}



===== LunParserQueryMountStatusDisk @ 1c000a510 =====

undefined8 LunParserQueryMountStatusDisk(void)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x14,
                     &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
  }
  return 0;
}



===== LunParserQuerySaveVersionDisk @ 1c000a560 =====

undefined8 LunParserQuerySaveVersionDisk(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}



===== LunParserRestoreDisk @ 1c000a570 =====

undefined8 LunParserRestoreDisk(longlong param_1,undefined8 param_2,undefined8 *param_3,int param_4)

{
  undefined8 uVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((int)param_2 == 1) {
    if (param_4 == 0x10) {
      uVar1 = param_3[1];
      *(undefined8 *)(param_1 + 0x38) = *param_3;
      *(undefined8 *)(param_1 + 0x40) = uVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x18,
                           in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_1 + 0x38),
                           *(undefined1 *)(param_1 + 0x40));
      }
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc0000206;
    }
  }
  else {
    uVar1 = 0xc0000059;
  }
  return uVar1;
}



===== LunParserSaveDisk @ 1c000a5e0 =====

undefined8
LunParserSaveDisk(longlong param_1,undefined8 *param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar2 = 0;
  if ((uint)param_3 < 0x10) {
    uVar2 = 0xc0000023;
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 0x40);
    *param_2 = *(undefined8 *)(param_1 + 0x38);
    param_2[1] = uVar1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x17,
                         in_stack_ffffffffffffffd8,(char)*param_2,*(undefined1 *)(param_2 + 1));
    }
    *param_4 = 0x10;
  }
  return uVar2;
}



===== LunParserSetBehaviorDisk @ 1c000a660 =====

undefined8 LunParserSetBehaviorDisk(longlong param_1,int param_2,undefined1 *param_3,int param_4)

{
  if (param_2 != 0x40000001) {
    return 0xc0000010;
  }
  if (param_4 == 0) {
    return 0xc000000d;
  }
  *(undefined1 *)(param_1 + 0x28) = *param_3;
  return 0;
}



===== LunParserUnload @ 1c000a690 =====

void LunParserUnload(undefined8 param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0xc,
                     &WPP_ea493f99c0ec31c130031f8fc6653eef_Traceguids);
  }
  WppCleanupKm(param_1);
  return;
}



===== WppCleanupKm @ 1c000a6e8 =====

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



===== WppInitKm @ 1c000a798 =====

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



===== WppLoadTracingSupport @ 1c000a874 =====

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



===== WppTraceCallback @ 1c000a9c0 =====

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



===== entry @ 1c000b010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000b044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  char cVar4;
  byte *pbVar5;
  undefined7 uVar7;
  char *pcVar6;
  char in_DL;
  byte in_DH;
  byte *unaff_RBX;
  undefined1 *unaff_RSI;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar2 = (code *)swi(0x29);
    pbVar5 = (byte *)(*pcVar2)(6);
    bVar3 = (byte)pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    bVar1 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + in_DL + CARRY1(bVar1,bVar3);
    bVar1 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    *unaff_RBX = *unaff_RBX << 1 | CARRY1(bVar1,bVar3);
    bVar1 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    uVar7 = (undefined7)((ulonglong)pbVar5 >> 8);
    cVar4 = bVar3 + CARRY1(bVar1,bVar3);
    pcVar6 = (char *)CONCAT71(uVar7,cVar4);
    pbVar5 = (byte *)(pcVar6 + -0x2fffffe8);
    bVar1 = *pbVar5;
    *pbVar5 = *pbVar5 + in_DH;
    cVar4 = (cVar4 - *pcVar6) - CARRY1(bVar1,in_DH);
    pcVar6 = (char *)CONCAT71(uVar7,cVar4);
    *pcVar6 = *pcVar6 + cVar4;
    *pcVar6 = *pcVar6 + cVar4;
    *(char *)CONCAT71(uVar7,0x40) = *(char *)CONCAT71(uVar7,0x40) + '@';
    *unaff_RSI = *unaff_RSI;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


