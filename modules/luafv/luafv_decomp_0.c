
===== _tlgKeywordOn @ 140001008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_14000b020 & 0x400000000000) == 0) ||
     (in_RAX = DAT_14000b028 & 0x400000000000, in_RAX != DAT_14000b028)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 14000103c =====

void _tlgWriteTransfer_EtwWriteTransfer(undefined8 param_1,byte *param_2)

{
  undefined4 uStack0000000000000028;
  undefined8 *in_stack_00000030;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *in_stack_00000030 = PTR_DAT_14000b018;
  *(uint *)(in_stack_00000030 + 1) = (uint)*(ushort *)PTR_DAT_14000b018;
  in_stack_00000030[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)in_stack_00000030 + 0xc) = 2;
  *(uint *)(in_stack_00000030 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)in_stack_00000030 + 0x1c) = 1;
  uStack0000000000000028 = 0x16c;
  EtwWriteTransfer(DAT_14000b030,&local_18,0,0,6);
  return;
}



===== LuafvPreRedirectWithCallback @ 1400010f0 =====

undefined8 LuafvPreRedirectWithCallback(longlong param_1,longlong param_2,undefined8 *param_3)

{
  short *psVar1;
  
  if (((*(longlong *)(param_2 + 0x20) == 0) ||
      (psVar1 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x18), psVar1 == (short *)0x0)) ||
     (*psVar1 != 0x7666)) {
    return 1;
  }
  if (*(longlong *)(psVar1 + 0x78) == 0) {
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(psVar1 + 0x7c);
    *(undefined8 *)(param_1 + 0x20) = 0;
    return 4;
  }
  *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = *(longlong *)(psVar1 + 0x78);
  FltSetCallbackDataDirty();
  *param_3 = psVar1;
  return 0;
}



===== LuafvPreWrite @ 140001190 =====

undefined8 LuafvPreWrite(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  short *psVar2;
  longlong *plVar3;
  int iVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  uVar5 = 1;
  if (((lVar1 != 0) && (psVar2 = *(short **)(lVar1 + 0x18), psVar2 != (short *)0x0)) &&
     (*psVar2 == 0x7666)) {
    plVar3 = *(longlong **)(psVar2 + 0x80);
    if (*(longlong *)(psVar2 + 0x78) == 0) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(psVar2 + 0x7c);
      *(undefined8 *)(param_1 + 0x20) = 0;
      return 4;
    }
    if ((*(char *)(*(longlong *)(param_1 + 0x10) + 4) == '\b') && (*(char *)(lVar1 + 0x4b) == '\0'))
    {
      *(undefined4 *)(param_1 + 0x18) = 0xc0000043;
      *(undefined8 *)(param_1 + 0x20) = 0;
      return 4;
    }
    if (((char)psVar2[0x7e] == '\0') &&
       (iVar4 = LuafvPerformDelayedVirtualization(param_2,param_1,(longlong)psVar2), iVar4 < 0)) {
      *(int *)(param_1 + 0x18) = iVar4;
      *(undefined8 *)(param_1 + 0x20) = 0;
      LuafvLogFileError(param_1,*plVar3,&LuafvPerformDelayedFailed,iVar4);
      return 4;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = *(undefined8 *)(psVar2 + 0x78);
    FltSetCallbackDataDirty(param_1);
    if (*(char *)(*(longlong *)(param_1 + 0x10) + 4) == '\x04') {
      *param_3 = psVar2;
      uVar5 = 0;
    }
  }
  return uVar5;
}



===== LuafvPreRedirect @ 1400012b0 =====

undefined8 LuafvPreRedirect(longlong param_1,longlong param_2)

{
  short *psVar1;
  
  if (((*(longlong *)(param_2 + 0x20) != 0) &&
      (psVar1 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x18), psVar1 != (short *)0x0)) &&
     (*psVar1 == 0x7666)) {
    if (*(longlong *)(psVar1 + 0x78) == 0) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(psVar1 + 0x7c);
      *(undefined8 *)(param_1 + 0x20) = 0;
      return 4;
    }
    *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = *(longlong *)(psVar1 + 0x78);
    FltSetCallbackDataDirty();
  }
  return 1;
}



===== RemoveMruListNode @ 140001320 =====

void RemoveMruListNode(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_1 + 0xd0);
  lVar1 = *plVar4;
  if (lVar1 != 0) {
    if ((*(longlong **)(lVar1 + 8) != plVar4) ||
       (plVar2 = *(longlong **)(param_1 + 0xd8), (longlong *)*plVar2 != plVar4)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    *plVar4 = 0;
  }
  return;
}



===== AsyncIoCompletion @ 140001360 =====

void AsyncIoCompletion(undefined8 param_1,longlong param_2)

{
  KeSetEvent(param_2 + 0x98,0,0);
  return;
}



===== LuafvCalculateHash @ 140001388 =====

uint LuafvCalculateHash(ushort *param_1,uint param_2)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((((ulonglong)param_1 & 1) != 0) || (param_2 == 0)) {
    return 0;
  }
  uVar4 = param_2 & 3;
  for (uVar5 = param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    uVar2 = *param_1;
    puVar1 = param_1 + 1;
    param_1 = param_1 + 2;
    uVar3 = (param_2 + uVar2) * 0x10000 ^ (uint)*puVar1 << 0xb ^ param_2 + uVar2;
    param_2 = uVar3 + (uVar3 >> 0xb);
  }
  if (uVar4 == 1) {
    uVar4 = param_2 + (byte)*param_1;
    uVar4 = uVar4 ^ uVar4 * 0x400;
    uVar5 = uVar4 >> 1;
  }
  else if (uVar4 == 2) {
    uVar4 = param_2 + *param_1 ^ (param_2 + *param_1) * 0x800;
    uVar5 = uVar4 >> 0x11;
  }
  else {
    if (uVar4 != 3) goto LAB_1400013da;
    uVar4 = param_2 + *param_1 ^ (uint)(byte)param_1[1] << 0x12 ^ (param_2 + *param_1) * 0x10000;
    uVar5 = uVar4 >> 0xb;
  }
  param_2 = uVar4 + uVar5;
LAB_1400013da:
  uVar5 = param_2 ^ param_2 * 8;
  uVar5 = uVar5 + (uVar5 >> 5);
  uVar5 = uVar5 ^ uVar5 * 4;
  uVar5 = uVar5 + (uVar5 >> 0xf);
  return uVar5 * 0x400 ^ uVar5;
}



===== LuafvResumeUsn @ 140001450 =====

undefined8 LuafvResumeUsn(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong local_res8;
  
  local_res8 = 0;
  uVar3 = FltGetInstanceContext(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),&local_res8);
  lVar2 = local_res8;
  if (-1 < (int)uVar3) {
    lVar1 = local_res8 + 0x108;
    FltAcquirePushLockExclusiveEx(lVar1,0);
    if ((*(int *)(lVar2 + 0x340) == 3) &&
       (*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) == *(longlong *)(lVar2 + 0x50))) {
      *(undefined8 *)(lVar2 + 0x50) = 0;
      KeClearEvent(lVar2 + 0xb8);
      KeSetEvent(lVar2 + 0xb8,0,0);
    }
    FltReleasePushLockEx(lVar1,0);
    FltReleaseContext(local_res8);
    uVar3 = 0;
  }
  return uVar3;
}



===== LuafvRunScavenger @ 140001528 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LuafvRunScavenger(void)

{
  bool bVar1;
  bool bVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  
  lVar3 = _DAT_fffff78000000014;
  cVar5 = '\0';
  bVar1 = false;
  if ((_DAT_fffff78000000014 < NextFileTableTime) && (DAT_14000c2a4 <= DAT_14000c2a8)) {
    if (0 < DAT_14000c2a0) {
      bVar1 = true;
      cVar5 = '\x01';
    }
  }
  else {
    bVar1 = true;
  }
  if (_DAT_fffff78000000014 < NextUserTime) {
    bVar2 = false;
    if (!bVar1) {
      return;
    }
  }
  else {
    bVar2 = true;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(&ScavengerSpinLock);
  if (ScavengerInitialized != '\0') {
    if ((bVar1) && (RunFileTableAlgorithm = 1, InactiveJournalsOnly = cVar5, cVar5 == '\0')) {
      NextFileTableTime = lVar3 + 150000000;
    }
    if (bVar2) {
      RunUserAlgorithm = 1;
      NextUserTime = NextUserTime + lVar3 + 300000000;
    }
    if (ScavengerRunning == '\0') {
      ScavengerRunning = '\x01';
      ExQueueWorkItem(&ScavengerWorkItem,1);
    }
  }
  KeReleaseSpinLock(&ScavengerSpinLock,uVar4);
  return;
}



===== ScavengerThreadRoutine @ 140001680 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScavengerThreadRoutine(void)

{
  bool bVar1;
  undefined1 uVar2;
  
  bVar1 = true;
  LOCK();
  _ScavengerCount = _ScavengerCount + 1;
  UNLOCK();
  uVar2 = IoSetThreadHardErrorMode();
  do {
    if (RunFileTableAlgorithm != '\0') {
      RunFileTableAlgorithm = '\0';
      LuafvScavengeFileTable();
    }
    if (RunUserAlgorithm != '\0') {
      RunUserAlgorithm = '\0';
      LuafvScavengeUserList('\0');
    }
    KeAcquireSpinLockRaiseToDpc(&ScavengerSpinLock);
    if ((RunFileTableAlgorithm == '\0') && (RunUserAlgorithm == '\0')) {
      bVar1 = false;
      ScavengerRunning = 0;
      if (ScavengerInitialized == '\0') {
        KeSetEvent(&ScavengerThreadTerminationEvent,0,0);
      }
    }
    KeReleaseSpinLock();
  } while (bVar1);
  IoSetThreadHardErrorMode(uVar2);
  LOCK();
  _ScavengerCount = _ScavengerCount + -1;
  UNLOCK();
  return;
}



===== LuafvPostQueryInformation @ 140001780 =====

undefined8 LuafvPostQueryInformation(longlong param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x7ffffffb)) {
    lVar4 = *(longlong *)(param_1 + 0x10);
    lVar5 = 0;
    iVar3 = *(int *)(lVar4 + 0x20);
    if ((iVar3 == 4) || (iVar3 == 0x12)) {
      lVar5 = 0x20;
    }
    else if (iVar3 == 0x22) {
      lVar5 = 0x30;
    }
    if ((iVar2 != -0x7ffffffb) || (lVar5 + 4U <= (ulonglong)*(uint *)(lVar4 + 0x18))) {
      puVar1 = (uint *)(*(longlong *)(lVar4 + 0x28) + lVar5);
      *puVar1 = *puVar1 | 0x10000;
    }
  }
  return 0;
}



===== LuafvPathGetFileNamePart_UStr @ 1400017ec =====

undefined8 LuafvPathGetFileNamePart_UStr(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar5 = *(longlong *)(param_2 + 4);
  uVar1 = 0;
  if ((lVar5 == 0) || (uVar2 = *param_2, uVar2 < 2)) {
    uVar2 = 0;
    lVar5 = 0;
  }
  else {
    uVar3 = (ulonglong)(uVar2 >> 1);
    for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + 1) {
      if (*(short *)(lVar5 + -2 + (uVar3 - uVar4) * 2) == 0x5c) {
        if ((uVar4 == 0) && (uVar2 == param_2[1])) {
          uVar2 = 0;
          lVar5 = 0;
        }
        else {
          uVar2 = (short)uVar4 * 2;
          uVar1 = (param_2[1] - *param_2) + uVar2;
          lVar5 = lVar5 + (uVar3 - uVar4) * 2;
        }
        goto LAB_14000188a;
      }
    }
    uVar1 = param_2[1];
  }
LAB_14000188a:
  *(longlong *)(param_1 + 4) = lVar5;
  *param_1 = uVar2;
  param_1[1] = uVar1;
  return 0;
}



===== LuafvPostSetInformation @ 1400018b0 =====

undefined4 LuafvPostSetInformation(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  
  if ((*(int *)(param_1 + 0x18) < 0) || (cVar1 = FltDoCompletionProcessingWhenSafe(), cVar1 == '\0')
     ) {
    FltReleaseContext(param_3);
  }
  return 0;
}



===== LuafvIsFileWRP @ 140001920 =====

ulonglong LuafvIsFileWRP(ulonglong *param_1,longlong param_2,undefined *param_3,undefined1 *param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong *local_res10;
  longlong local_48 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar1 = *(undefined8 *)(param_2 + 0x18);
  plVar8 = (longlong *)0x0;
  local_res10 = (longlong *)0x0;
  uVar3 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar5 = LuafvFindTableNode(param_3,param_1,4,local_48);
  lVar2 = local_48[0];
  uVar7 = uVar5 & 0xffffffff;
  if (-1 < (int)uVar5) {
    if (((*(byte *)(local_48[0] + 0x1e) & 1) != 0) && ((short)local_38 == 0)) {
      if (*(longlong *)(local_48[0] + 0xf8) == 0) {
        uVar5 = Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 == 0) {
          uVar6 = LuafvBuildTableNodeName
                            (lVar2,0,(ushort *)0x0,(ushort *)0x0,'\0',(undefined2 *)(lVar2 + 0xf0));
          uVar4 = (uint)uVar6;
        }
        else {
          uVar6 = LuafvBuildTableNodeName2
                            (lVar2,0,(ushort *)0x0,(ushort *)0x0,'\0','\x01',
                             (undefined2 *)(lVar2 + 0xf0));
          uVar4 = (uint)uVar6;
        }
        uVar7 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) goto LAB_140001a1c;
      }
      uVar4 = LuafvReadAndCacheSecurityDescriptor
                        (uVar1,lVar2,(ushort *)(lVar2 + 0xf0),'\0',(longlong *)&local_res10);
      plVar8 = local_res10;
      uVar7 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) goto LAB_140001a1c;
      uVar5 = LuafvIsWrpFileDescriptor(local_res10[2]);
      uVar3 = (undefined1)uVar5;
    }
    uVar7 = 0;
  }
LAB_140001a1c:
  if (lVar2 != 0) {
    LuafvDereferenceTableNodeEx(lVar2,'\0','\0');
  }
  if (plVar8 != (longlong *)0x0) {
    LuafvDereferenceCachedSecurityDescriptor(plVar8);
  }
  *param_4 = uVar3;
  return uVar7;
}



===== LuafvUpdateFileTableForFileObject @ 140001a64 =====

void LuafvUpdateFileTableForFileObject(longlong *param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  int iVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  short *psVar5;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  if (param_1 == (longlong *)0x0) {
    if (param_3 == 0) {
LAB_140001ad7:
      psVar5 = (short *)0x0;
      local_res8 = (longlong *)0x0;
LAB_140001adb:
      if (psVar5 == (short *)0x0) goto LAB_140001aca;
      cVar1 = (char)psVar5[0x7e];
    }
    else {
      psVar5 = *(short **)(param_3 + 0x18);
      if ((psVar5 != (short *)0x0) && (*psVar5 == 0x7666)) {
        local_res8 = *(longlong **)(psVar5 + 0x80);
        goto LAB_140001adb;
      }
      if ((param_2 == 0) ||
         (iVar2 = FltGetStreamHandleContext(param_2,param_3,&local_res8), iVar2 < 0))
      goto LAB_140001ad7;
      psVar5 = (short *)0x0;
LAB_140001aca:
      if (local_res8 != (longlong *)0x0) goto LAB_140001af4;
      cVar1 = '\0';
    }
    if (cVar1 == '\0') goto LAB_140001b1d;
  }
  else {
    psVar5 = (short *)0x0;
    local_res8 = param_1;
  }
LAB_140001af4:
  if ((*(byte *)((longlong)local_res8 + 0x14) & 2) == 0) {
    puVar3 = (ulonglong *)*local_res8;
    uVar4 = puVar3[4];
  }
  else {
    uVar4 = *(ulonglong *)(*local_res8 + 0x50);
    puVar3 = (ulonglong *)(*local_res8 + 0x30);
  }
  LuafvUpdateFileTableForFileChange(puVar3,uVar4);
  if (param_1 != (longlong *)0x0) {
    return;
  }
LAB_140001b1d:
  if ((psVar5 == (short *)0x0) && (local_res8 != (longlong *)0x0)) {
    FltReleaseContext();
  }
  return;
}



===== __report_gsfailure @ 140001b50 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140001b5d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001b5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== _guard_check_icall @ 140001b80 =====

void _guard_check_icall(void)

{
  return;
}



===== ProbeForRead @ 140001b96 =====

void ProbeForRead(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001b96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ProbeForRead();
  return;
}



===== __cpu_features_init @ 140001bc0 =====

/* WARNING: Removing unreachable block (ram,0x000140001c2a) */
/* WARNING: Removing unreachable block (ram,0x000140001bd9) */
/* WARNING: Removing unreachable block (ram,0x000140001bca) */

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



===== AllocateDataBuffer @ 140001c88 =====

undefined8 AllocateDataBuffer(longlong *param_1,undefined4 *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  uVar2 = 0x4000;
  lVar1 = ExAllocatePool2(0x40,0x4000,0x6661754c);
  if (lVar1 == 0) {
    uVar2 = 0x1000;
    lVar1 = ExAllocatePool2(0x40,0x1000,0x6661754c);
    if (lVar1 == 0) {
      return 0xc000009a;
    }
  }
  *param_1 = lVar1;
  *param_2 = uVar2;
  return 0;
}



===== LuafvCopySaclWithAudit @ 140001d08 =====

int LuafvCopySaclWithAudit
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  uint *puVar2;
  char local_res20 [8];
  undefined1 local_98 [4];
  uint local_94;
  longlong local_90;
  undefined8 local_88;
  longlong local_80 [3];
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_64 = 0;
  local_4c = 0;
  local_94 = 0;
  local_res20[0] = '\0';
  local_80[1] = 0;
  local_80[2] = 0;
  local_88 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_98[0] = 0;
  local_80[0] = 0;
  local_90 = 0;
  RtlInitUnicodeString(local_80 + 1,0);
  local_58 = local_80 + 1;
  local_68 = 0x30;
  local_50 = 0x240;
  local_48 = 0;
  uStack_40 = 0;
  local_60 = param_4;
  iVar1 = FltCreateFileEx2(LuafvDriverData,param_1,local_80,&local_90,0x140000,&local_68,&local_38,0
                           ,0,7,1,0x4020,0,0,0x100,0);
  if (-1 < iVar1) {
    iVar1 = FltQuerySecurityObject(param_1,param_3,8,0,0,&local_94);
    if (iVar1 == -0x3fffffdd) {
      puVar2 = LuafvAllocatePool(1,local_94,'\x04');
      if (puVar2 == (uint *)0x0) {
        iVar1 = -0x3fffff66;
      }
      else {
        iVar1 = FltQuerySecurityObject(param_1,param_3,8,puVar2,local_94,&local_94);
        if (-1 < iVar1) {
          iVar1 = RtlGetSaclSecurityDescriptor(puVar2,local_res20,&local_88,local_98);
          if ((-1 < iVar1) && (local_res20[0] != '\0')) {
            iVar1 = FltSetSecurityObject(param_1,local_90,8,puVar2);
            if (-1 < iVar1) {
              LuafvReportAuditVirtualizationEvent(local_88,param_2,param_5,param_6);
            }
          }
        }
        LuafvFreePool((longlong)puVar2);
      }
    }
  }
  if (local_90 != 0) {
    ObfDereferenceObject();
  }
  if (local_80[0] != 0) {
    FltClose();
  }
  return iVar1;
}



===== Feature_2961076537__private_IsEnabledDeviceUsageNoInline @ 140001f4c =====

ulonglong Feature_2961076537__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2961076537__private_featureState;
  if ((Feature_2961076537__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2961076537__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2961076537__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2961076537__private_IsEnabledFallback @ 140001f84 =====

void Feature_2961076537__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline @ 140001fa0 =====

ulonglong Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Bugfix_LuafvUMA__private_featureState;
  if ((Feature_Bugfix_LuafvUMA__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Bugfix_LuafvUMA__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Bugfix_LuafvUMA__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Bugfix_LuafvUMA__private_IsEnabledFallback @ 140001fd8 =====

void Feature_Bugfix_LuafvUMA__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_Bugfix_LuafvUMA__private_descriptor);
  return;
}



===== LuafvMarkVirtualDirectoryEntries @ 140001ff4 =====

uint LuafvMarkVirtualDirectoryEntries(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar1 = (uint *)((ulonglong)param_2 + (longlong)param_1);
  puVar3 = (uint *)0xffffffffffffffff;
  if (puVar1 >= param_1) {
    puVar3 = puVar1;
  }
  uVar2 = -(uint)(puVar1 < param_1) & 0xc0000095;
  if (param_1 <= puVar1) {
    for (; param_1 + 0x12 <= puVar3; param_1 = (uint *)((longlong)param_1 + (ulonglong)*param_1)) {
      param_1[0xe] = param_1[0xe] | 0x10000;
      if (*param_1 == 0) {
        return uVar2;
      }
    }
  }
  return uVar2;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140002048 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140002120 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140002204 =====

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
LAB_14000235c:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000234f:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000235c;
      if (uVar5 == 5) goto LAB_14000234f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140002384 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140002408 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400024f8 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002608 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 14000266c =====

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



===== wil_details_IsEnabledFallback @ 1400027cc =====

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



===== wil_details_MapReportingKind @ 140002860 =====

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



===== CountPermanentNodesPreWorker @ 140002900 =====

void CountPermanentNodesPreWorker(longlong param_1,int *param_2)

{
  if ((*(byte *)(param_1 + 0x1e) & 2) != 0) {
    *param_2 = *param_2 + 1;
  }
  return;
}



===== Feature_218091834__private_IsEnabledDeviceUsageNoInline @ 140002910 =====

ulonglong Feature_218091834__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_218091834__private_featureState;
  if ((Feature_218091834__private_featureState & 0x10) == 0) {
    uVar1 = Feature_218091834__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_218091834__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_218091834__private_IsEnabledFallback @ 140002948 =====

void Feature_218091834__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_218091834__private_descriptor);
  return;
}



===== Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline @ 140002964 =====

ulonglong Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Bugfix_LuafvTableNode__private_featureState;
  if ((Feature_Bugfix_LuafvTableNode__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Bugfix_LuafvTableNode__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Bugfix_LuafvTableNode__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Bugfix_LuafvTableNode__private_IsEnabledFallback @ 14000299c =====

void Feature_Bugfix_LuafvTableNode__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_Bugfix_LuafvTableNode__private_descriptor);
  return;
}



===== Feature_3278626104__private_IsEnabledDeviceUsageNoInline @ 1400029b8 =====

ulonglong Feature_3278626104__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3278626104__private_featureState;
  if ((Feature_3278626104__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3278626104__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3278626104__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3278626104__private_IsEnabledFallback @ 1400029f0 =====

void Feature_3278626104__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3278626104__private_descriptor);
  return;
}



===== Feature_Bugfix_LuafvStreamRename__private_IsEnabledDeviceUsageNoInline @ 140002a0c =====

ulonglong Feature_Bugfix_LuafvStreamRename__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Bugfix_LuafvStreamRename__private_featureState;
  if ((Feature_Bugfix_LuafvStreamRename__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Bugfix_LuafvStreamRename__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Bugfix_LuafvStreamRename__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Bugfix_LuafvStreamRename__private_IsEnabledFallback @ 140002a44 =====

void Feature_Bugfix_LuafvStreamRename__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Bugfix_LuafvStreamRename__private_descriptor);
  return;
}



===== LuafvPostDirectoryControl @ 140002a60 =====

undefined4 LuafvPostDirectoryControl(uint *param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  ulonglong in_stack_ffffffffffffffe8;
  
  if (((param_1[6] + 0x80000000 & 0x80000000) == 0) && (param_1[6] != 0x80000005)) {
    return 0;
  }
  lVar1 = *(longlong *)(param_1 + 4);
  lVar2 = *(longlong *)(lVar1 + 0x40);
  if (lVar2 == 0) {
    if ((*param_1 & 10) == 0) {
      cVar3 = FltDoCompletionProcessingWhenSafe(param_1);
      if (cVar3 != '\0') {
        return 0;
      }
      uVar4 = 0xc0000001;
      goto LAB_140002b22;
    }
    puVar5 = *(uint **)(lVar1 + 0x38);
LAB_140002b16:
    uVar4 = LuafvMarkVirtualDirectoryEntries(puVar5,*(uint *)(lVar1 + 0x18));
  }
  else {
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      puVar5 = (uint *)MmMapLockedPagesSpecifyCache
                                 (lVar2,0,1,0,in_stack_ffffffffffffffe8 & 0xffffffff00000000,
                                  0x40000010);
    }
    else {
      puVar5 = *(uint **)(lVar2 + 0x18);
    }
    if (puVar5 != (uint *)0x0) goto LAB_140002b16;
    uVar4 = 0xc000009a;
  }
  if (-1 < (int)uVar4) {
    return 0;
  }
LAB_140002b22:
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = uVar4;
  return 0;
}



===== LuafvPostReadWrite @ 140002b40 =====

undefined8 LuafvPostReadWrite(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  if (((lVar1 != 0) && (param_3 != 0)) && (lVar2 = *(longlong *)(param_3 + 0xf0), lVar2 != 0)) {
    if ((((*(uint *)(lVar1 + 0x50) & 2) != 0) && ((**(uint **)(param_1 + 0x10) & 2) == 0)) &&
       (-1 < *(int *)(param_1 + 0x18))) {
      *(undefined8 *)(lVar1 + 0x68) = *(undefined8 *)(lVar2 + 0x68);
    }
    *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(lVar2 + 0x28);
    *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(lVar2 + 0x30);
  }
  return 0;
}



===== _tlgDefineProvider_annotation__TlgLUAFV_INSTRUMENTATION_PROVIDERProv @ 140002b9c =====

void _tlgDefineProvider_annotation__TlgLUAFV_INSTRUMENTATION_PROVIDERProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140002ba8 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000a057 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140002bd0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002d30 =====

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



===== LuafvTerminateScavenger @ 140002db4 =====

void LuafvTerminateScavenger(void)

{
  char cVar1;
  undefined1 uVar2;
  
  if (ScavengerInitialized != '\0') {
    KeInitializeEvent(&ScavengerThreadTerminationEvent,0,0);
    uVar2 = KeAcquireSpinLockRaiseToDpc(&ScavengerSpinLock);
    cVar1 = ScavengerRunning;
    ScavengerInitialized = '\0';
    KeReleaseSpinLock(&ScavengerSpinLock,uVar2);
    if (cVar1 != '\0') {
      KeWaitForSingleObject(&ScavengerThreadTerminationEvent,0,0,0,0);
    }
  }
  return;
}



===== LuafvPauseUsn @ 140002e44 =====

undefined8 LuafvPauseUsn(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong local_res8;
  
  local_res8 = 0;
  uVar4 = FltGetInstanceContext(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),&local_res8);
  lVar3 = local_res8;
  if (-1 < (int)uVar4) {
    lVar1 = local_res8 + 0x108;
    FltAcquirePushLockExclusiveEx(lVar1,0);
    iVar2 = *(int *)(lVar3 + 0x340);
    if (iVar2 == 1) {
      *(undefined4 *)(lVar3 + 0x340) = 2;
      *(undefined8 *)(lVar3 + 0x50) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8);
      KeClearEvent(lVar3 + 0xa0);
      KeClearEvent(lVar3 + 0xb8);
      KeSetEvent(lVar3 + 0x88,0,0);
    }
    FltReleasePushLockEx(lVar1,0);
    if (iVar2 == 1 || iVar2 == 2) {
      KeWaitForSingleObject(lVar3 + 0xa0,0,0,0,0);
    }
    FltReleaseContext(local_res8);
    uVar4 = 0;
  }
  return uVar4;
}



===== __GSHandlerCheck @ 140002f78 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140002f9c =====

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



===== __GSHandlerCheck_SEH @ 140003004 =====

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



===== __security_check_cookie @ 1400030a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlCopyVolatileMemory @ 1400030d0 =====

void * __cdecl RtlCopyVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 1400030e0 =====

void * __cdecl RtlMoveVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlSetVolatileMemory @ 1400030f0 =====

void * __cdecl RtlSetVolatileMemory(void *_Dst,int _Val,size_t _Size)

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



===== _guard_dispatch_icall @ 140003120 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140003120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003150 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140003180 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140003200 =====

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



===== memset @ 140003500 =====

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



===== __memset_repmovs @ 140003640 =====

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



===== __memset_query @ 1400036c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003740 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003880 =====

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



===== __memset_spec_plain @ 140003900 =====

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



===== memset$thunk$772440563353939046 @ 140004060 =====

void * __cdecl memset_thunk_772440563353939046(void *_Dst,int _Val,size_t _Size)

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



===== InitializeUsn @ 140010008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong InitializeUsn(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStackY_128 [32];
  undefined8 local_68 [2];
  undefined8 local_58;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  memset(local_68,0,0x40);
  plVar1 = (longlong *)(param_1 + 0x38);
  if (*plVar1 == 0) {
    iVar2 = KeReadStateEvent(param_1 + 0x70);
    if (iVar2 != 0) {
      return 1;
    }
    iVar2 = KeReadStateEvent(param_1 + 0x88);
    if (iVar2 != 0) {
      KeClearEvent(param_1 + 0x88);
      AcknowledgePauseRequest(param_1);
      return 2;
    }
    uVar3 = FltCreateFileEx2(LuafvDriverData,*(undefined8 *)(param_1 + 0x10),plVar1);
    if ((int)uVar3 < 0) {
      *plVar1 = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      return uVar3;
    }
  }
  do {
    uVar3 = SynchronousFsControl(param_1,(undefined4 *)0x0,0x900f4,0,0,local_68,0x40);
    iVar2 = (int)uVar3;
    if (iVar2 - 1U < 2) {
      return uVar3;
    }
    if (-1 < iVar2) {
      *(undefined8 *)(param_1 + 0xf8) = local_68[0];
      *(undefined8 *)(param_1 + 0x100) = local_58;
      return 0;
    }
    if (iVar2 == -0x3ffffd48) {
      uVar3 = CreateUsn(param_1);
    }
    else {
      if (iVar2 != -0x3ffffd49) {
        return uVar3;
      }
      uVar3 = WaitForUsnDeletion(param_1);
    }
  } while (((int)uVar3 == 0) || (2 < (int)uVar3));
  return uVar3;
}



===== DereferenceDvfcb @ 140010200 =====

void DereferenceDvfcb(int *param_1)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  
  uVar3 = param_1[0xe];
  FltAcquirePushLockExclusiveEx(&DAT_14000b310 + (ulonglong)(uVar3 & 0xf) * 0x18,0);
  LOCK();
  iVar2 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x1c) != 0) {
      ZwClose();
    }
    FsRtlTeardownPerFileContexts(param_1 + 0x1a);
    plVar1 = (longlong *)(param_1 + 2);
    lVar4 = *plVar1;
    if ((*(longlong **)(lVar4 + 8) != plVar1) ||
       (plVar5 = *(longlong **)(param_1 + 4), (longlong *)*plVar5 != plVar1)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    LuafvFreePool((longlong)param_1);
    LOCK();
    LuafvActiveDvfcbCount = LuafvActiveDvfcbCount + -1;
    UNLOCK();
  }
  FltReleasePushLockEx(&DAT_14000b310 + (ulonglong)(uVar3 & 0xf) * 0x18,0);
  return;
}



===== LuafvReadDwordValue @ 1400102bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LuafvReadDwordValue(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38[0] = 0;
  local_20 = 0;
  local_40 = local_38;
  local_48 = 0x14;
  local_30 = 0;
  uStack_28 = 0;
  uVar1 = ZwQueryValueKey(0,param_2,2,&local_30);
  if (-1 < (int)uVar1) {
    if ((local_30._4_4_ == 4) && ((int)uStack_28 == 4)) {
      *param_3 = uStack_28._4_4_;
    }
    else {
      uVar1 = 0xc0000001;
    }
  }
  return uVar1;
}



===== LuafvCopyShortName @ 140010348 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LuafvCopyShortName(undefined8 param_1,ulonglong *param_2,undefined8 param_3)

{
  longlong *plVar1;
  int *piVar2;
  ushort uVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort uVar7;
  ushort uVar8;
  short sVar9;
  longlong lVar10;
  undefined1 auStack_188 [32];
  undefined4 local_168;
  undefined4 *local_160;
  undefined8 *local_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined4 local_118;
  undefined8 local_110;
  longlong local_108;
  undefined8 local_100;
  longlong lStack_f8;
  undefined8 local_f0;
  longlong lStack_e8;
  undefined8 local_e0;
  longlong local_d8 [4];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_188;
  local_b8 = 0;
  local_9c = 0;
  local_84 = 0;
  local_e0 = 0;
  local_d8[0] = 0;
  local_d8[1] = 0;
  local_f0 = 0;
  lStack_e8 = 0;
  local_100 = 0;
  lStack_f8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  uVar6 = LuafvFindTableNode((undefined *)0x0,param_2,1,local_d8);
  lVar10 = local_d8[0];
  uVar5 = (uint)uVar6;
  if ((int)uVar5 < 0) {
    return uVar6;
  }
  if (((char)local_b8 == '\0') || ((*(byte *)(local_d8[0] + 0x1e) & 8) == 0)) {
    uVar5 = 0xc0000034;
  }
  else {
    plVar1 = (longlong *)(local_d8[0] + 8);
    if ((void *)*plVar1 == SystemReserved1[0xf]) {
      *(int *)(local_d8[0] + 0x10) = *(int *)(local_d8[0] + 0x10) + 1;
    }
    else {
      FltAcquirePushLockSharedEx(local_d8[0]);
    }
    uVar3 = *(ushort *)(lVar10 + 0x80);
    local_60 = CONCAT44(local_60._4_4_,(uint)uVar3);
    if (uVar3 < 0x1d) {
      memmove((void *)((longlong)&local_60 + 4),*(void **)(lVar10 + 0x88),(ulonglong)uVar3);
    }
    else {
      uVar5 = 0xc0000001;
    }
    lVar10 = local_d8[0];
    if ((void *)*plVar1 == SystemReserved1[0xf]) {
      piVar2 = (int *)(local_d8[0] + 0x10);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 != 0) goto LAB_14001046b;
      *plVar1 = 0;
    }
    FltReleasePushLockEx(local_d8[0]);
  }
LAB_14001046b:
  LuafvDereferenceTableNodeEx(lVar10,'\0','\0');
  if ((int)uVar5 < 0) {
    uVar6 = (ulonglong)uVar5;
  }
  else {
    RtlInitUnicodeString(&local_b0,0);
    local_90 = &local_b0;
    local_110 = 0;
    local_118 = 0x100;
    local_120 = 0;
    local_128 = 0;
    local_130 = 0x4020;
    local_138 = 1;
    local_140 = 7;
    local_148 = 0;
    local_158 = &local_70;
    local_150 = 0;
    local_160 = &local_a0;
    local_168 = 0x100100;
    local_a0 = 0x30;
    local_88 = 0x240;
    local_80 = 0;
    uStack_78 = 0;
    local_108 = 0;
    local_98 = param_3;
    uVar5 = FltCreateFileEx2(LuafvDriverData,param_1,&local_e0,&local_108);
    uVar6 = (ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      uVar3 = (ushort)*param_2 >> 1;
      do {
        uVar7 = uVar3;
        if (uVar7 == 0) break;
        uVar3 = uVar7 - 1;
      } while (*(short *)(param_2[1] + (ulonglong)(ushort)(uVar7 - 1) * 2) != 0x5c);
      lStack_e8 = param_2[1] + (ulonglong)uVar7 * 2;
      sVar9 = (ushort)*param_2 + uVar7 * -2;
      local_f0._4_4_ = (undefined4)(*param_2 >> 0x20);
      local_f0._0_4_ = CONCAT22(sVar9,sVar9);
      uVar3 = *(ushort *)(local_108 + 0x58) >> 1;
      do {
        uVar8 = uVar3;
        if (uVar8 == 0) break;
        uVar3 = uVar8 - 1;
      } while (*(short *)(*(longlong *)(local_108 + 0x60) + (ulonglong)(ushort)(uVar8 - 1) * 2) !=
               0x5c);
      lStack_f8 = *(longlong *)(local_108 + 0x60) + (ulonglong)uVar8 * 2;
      sVar9 = *(short *)(local_108 + 0x58) + uVar8 * -2;
      local_100 = CONCAT44(*(undefined4 *)(local_108 + 0x5c),CONCAT22(sVar9,sVar9));
      cVar4 = RtlEqualUnicodeString
                        (&local_f0,&local_100,CONCAT71((uint7)(byte)((ushort)(uVar7 * 2) >> 8),1));
      if (cVar4 == '\0') {
        uVar6 = 0xc0000001;
      }
      else {
        local_168 = 0x28;
        uVar5 = FltSetInformationFile(param_1,local_108,&local_60,0x20);
        uVar6 = (ulonglong)uVar5;
      }
      ObfDereferenceObject(local_108);
      FltClose(local_e0);
    }
  }
  return uVar6;
}



===== LuafvQueryShortNameFromGlobal @ 140010668 =====

undefined8 LuafvQueryShortNameFromGlobal(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint local_res10 [2];
  undefined8 local_res20;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  uVar2 = 0;
  uVar3 = 4;
  local_68 = 0;
  local_50 = 0x30;
  local_38 = 0x240;
  local_60 = 0;
  uStack_58 = 0;
  local_res10[0] = 0;
  local_res20 = 0;
  local_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = param_2;
  iVar1 = FltCreateFileEx2(LuafvDriverData,param_1,&local_68,&local_res20,0x100000,&local_50,
                           &local_60,0,0,7,1,0x20,0,0,0x901,0);
  if (iVar1 < 0) {
    if ((iVar1 == -0x3fffffcc) || (iVar1 == -0x3fffffc6)) {
      uVar3 = 1;
    }
    else {
      *(undefined8 *)(param_3 + 0x18) = local_60;
      *(undefined8 *)(param_3 + 0x20) = uStack_58;
    }
  }
  else {
    iVar1 = FltQueryInformationFile
                      (param_1,local_res20,*(undefined8 *)(*(longlong *)(param_3 + 0x10) + 0x28),
                       *(undefined4 *)(*(longlong *)(param_3 + 0x10) + 0x18),0x15,local_res10);
    ObfDereferenceObject(local_res20);
    FltClose(local_68);
    *(int *)(param_3 + 0x18) = iVar1;
    if (-1 < iVar1) {
      uVar2 = (ulonglong)local_res10[0];
    }
    *(ulonglong *)(param_3 + 0x20) = uVar2;
  }
  return uVar3;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1400107d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_14000b018 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000b018 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000b018 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000b018 + -4);
  if (DAT_14000b030 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14000b038 = 0;
  uRam000000014000b040 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x140010833;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14000b010,&DAT_14000b030);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000b018;
    *(undefined8 *)(puVar4 + -8) = 0x14001085a;
    EtwSetInformation(DAT_14000b030,2,PTR_DAT_14000b018,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14001086e;
  return iVar3;
}



===== LuafvRemoveEcp @ 14001087c =====

void LuafvRemoveEcp(undefined8 param_1)

{
  int iVar1;
  longlong local_res10;
  undefined8 local_res18 [2];
  
  local_res10 = 0;
  local_res18[0] = 0;
  FltGetEcpListFromCallbackData(LuafvDriverData,param_1,&local_res10);
  if (local_res10 != 0) {
    iVar1 = FltRemoveExtraCreateParameter(LuafvDriverData,local_res10,&LuafvEcpType,local_res18,0);
    if (-1 < iVar1) {
      FltFreeExtraCreateParameter(LuafvDriverData,local_res18[0]);
    }
  }
  return;
}



===== LuafvExtractFileNameFromPath @ 140010900 =====

void LuafvExtractFileNameFromPath(ushort *param_1,ushort *param_2)

{
  short sVar1;
  undefined8 uVar2;
  ushort uVar3;
  
  uVar3 = *param_2;
  if (1 < uVar3) {
    do {
      sVar1 = *(short *)(*(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar3 >> 1) * 2);
      if (((sVar1 != 0x5c) && (sVar1 != 0x2f)) && (sVar1 != 0)) break;
      uVar3 = uVar3 - 2;
      *param_2 = uVar3;
    } while (1 < uVar3);
  }
  uVar2 = LuafvPathGetFileNamePart_UStr(param_1,param_2);
  if ((int)uVar2 < 0) {
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[0] = 0;
    param_1[1] = 0;
  }
  return;
}



===== LuafvOpenKey @ 140010970 =====

void LuafvOpenKey(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_1c = 0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_1;
  local_28 = param_2;
  ZwOpenKey(param_3,0x20019,&local_38);
  return;
}



===== RtlCopyToUser @ 1400109cc =====

/* WARNING: Removing unreachable block (ram,0x0001400109f0) */

void RtlCopyToUser(void *param_1,void *param_2,size_t param_3)

{
  if (param_3 != 0) {
    ProbeForRead(param_1,param_3,1);
    RtlCopyVolatileMemory(param_1,param_2,param_3);
  }
  return;
}



===== RtlReadULongFromUser @ 140010a30 =====

/* WARNING: Removing unreachable block (ram,0x000140010a45) */

ulonglong RtlReadULongFromUser(uint *param_1)

{
  ProbeForRead(param_1,4,1);
  return (ulonglong)*param_1;
}



===== RtlSetUserMemory @ 140010a6c =====

/* WARNING: Removing unreachable block (ram,0x000140010a90) */

void RtlSetUserMemory(void *param_1,undefined8 param_2,size_t param_3)

{
  ProbeForRead(param_1,param_3,1);
  RtlSetVolatileMemory(param_1,(uint)param_2 & 0xff,param_3);
  return;
}



===== RtlWriteULongToUser @ 140010acc =====

/* WARNING: Removing unreachable block (ram,0x000140010ae7) */

void RtlWriteULongToUser(undefined4 *param_1,undefined4 param_2)

{
  ProbeForRead(param_1,4,1);
  *param_1 = param_2;
  return;
}



===== LuafvCopyStreamData @ 140010b10 =====

undefined8
LuafvCopyStreamData(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                   undefined8 param_5,undefined4 param_6)

{
  undefined8 uVar1;
  ulonglong uVar2;
  uint local_res20 [2];
  longlong local_28;
  undefined8 local_20;
  
  local_20 = *param_4;
  local_res20[0] = 0;
  uVar1 = FltSetInformationFile(param_1,param_3,&local_20,8,0x14);
  if (-1 < (int)uVar1) {
    local_28 = 0;
    while( true ) {
      uVar1 = FltReadFile(param_1,param_2,&local_28,param_6,param_5,0,local_res20,0,0);
      if ((int)uVar1 == -0x3fffffef) break;
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      if (local_res20[0] == 0) break;
      uVar2 = (ulonglong)local_res20[0];
      uVar1 = FltWriteFile(param_1,param_3,&local_28,local_res20[0],param_5,0,local_res20,0,0);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      local_28 = local_28 + uVar2;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140010c34 =====

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



===== FindOrCreateDvfcb @ 140010d00 =====

uint * FindOrCreateDvfcb(ushort *param_1,uint *param_2)

{
  ulonglong *puVar1;
  longlong *plVar2;
  code *pcVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint *_Dst;
  uint *puVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong *puVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  puVar11 = auStack_48;
  puVar14 = *(ulonglong **)(param_1 + 4);
  uVar12 = (uint)(*param_1 >> 1);
  uVar9 = 0;
  uVar6 = (uint)(*param_1 >> 3);
  if (uVar6 != 0) {
    uVar13 = 0;
    puVar1 = puVar14 + uVar6;
    do {
      uVar10 = *puVar14;
      if ((uVar10 & 0xff80ff80ff80ff80) == 0) {
        uVar10 = uVar10 & 0xffdfffdfffdfffdf;
      }
      else {
        lVar15 = 4;
        do {
          uVar7 = uVar10 & 0xffff;
          uVar6 = (uint)uVar7;
          if (0x60 < uVar6) {
            if (uVar6 < 0x7b) {
              uVar7 = (ulonglong)(uVar6 - 0x20);
            }
            else {
              uVar5 = RtlUpcaseUnicodeChar(uVar10 & 0xffff);
              uVar7 = (ulonglong)uVar5;
            }
          }
          uVar10 = uVar10 >> 0x10 | uVar7 << 0x30;
          lVar15 = lVar15 + -1;
        } while (lVar15 != 0);
      }
      puVar14 = puVar14 + 1;
      uVar13 = (uVar13 << 1 | (ulonglong)((longlong)uVar13 < 0)) ^ uVar10;
    } while (puVar14 < puVar1);
    uVar12 = uVar12 & 3;
    uVar9 = ((uint)(uVar13 >> 0x21) | (uint)(uVar13 << 0x1f)) ^ (uint)uVar13;
    uVar9 = uVar9 ^ (uVar9 >> 0x11 | uVar9 << 0xf);
  }
  puVar1 = (ulonglong *)((longlong)puVar14 + (ulonglong)uVar12 * 2);
  for (; puVar14 < puVar1; puVar14 = (ulonglong *)((longlong)puVar14 + 2)) {
    uVar5 = (ushort)*puVar14;
    uVar6 = (uint)uVar5;
    if (0x60 < uVar5) {
      if (uVar5 < 0x7b) {
        uVar6 = uVar5 - 0x20;
      }
      else {
        uVar5 = RtlUpcaseUnicodeChar(uVar5);
        uVar6 = (uint)uVar5;
      }
    }
    uVar9 = (uVar9 << 1 | (uint)((int)uVar9 < 0)) ^ uVar6;
  }
  uVar9 = (uVar9 >> 8 | uVar9 << 0x18) ^ uVar9;
  *param_2 = uVar9;
  plVar2 = &LuafvDvfcbHashTable + (ulonglong)(uVar9 & 0xf) * 3;
  FltAcquirePushLockExclusiveEx(&DAT_14000b310 + (ulonglong)(uVar9 & 0xf) * 0x18,0);
  plVar16 = (longlong *)*plVar2;
  do {
    if (plVar16 == plVar2) {
      uVar5 = *param_1;
      _Dst = LuafvAllocatePool(1,uVar5 + 0x7a,'\a');
      if (_Dst == (uint *)0x0) {
        _Dst = (uint *)0x0;
        puVar11 = auStack_48;
      }
      else {
        LOCK();
        LuafvActiveDvfcbCount = LuafvActiveDvfcbCount + 1;
        UNLOCK();
        memset(_Dst,0,(ulonglong)(uVar5 + 0x7a));
        *_Dst = 1;
        puVar8 = _Dst + 6;
        *(uint **)(_Dst + 8) = puVar8;
        *(uint **)puVar8 = puVar8;
        *(ushort *)(_Dst + 10) = *param_1;
        uVar5 = *param_1;
        *(uint **)(_Dst + 0xc) = _Dst + 0x1e;
        *(ushort *)((longlong)_Dst + 0x2a) = uVar5 + 2;
        memmove(_Dst + 0x1e,*(void **)(param_1 + 4),(ulonglong)*param_1);
        *(undefined2 *)(*(longlong *)(_Dst + 0xc) + (ulonglong)(*param_1 >> 1) * 2) = 0;
        _Dst[0xe] = uVar9;
        FltInitializePushLock(_Dst + 0x10);
        _Dst[0x1c] = 0;
        _Dst[0x1d] = 0;
        puVar8 = _Dst + 2;
        lVar15 = *plVar2;
        if (*(longlong **)(lVar15 + 8) != plVar2) {
          pcVar3 = (code *)swi(0x29);
          puVar8 = (uint *)(*pcVar3)(3);
          puVar11 = auStack_40;
        }
        *(longlong *)puVar8 = lVar15;
        *(longlong **)(puVar8 + 2) = plVar2;
        *(uint **)(lVar15 + 8) = puVar8;
        *plVar2 = (longlong)puVar8;
      }
LAB_140010f26:
      *(undefined8 *)(puVar11 + -8) = 0x140010f32;
      FltReleasePushLockEx(&DAT_14000b310 + (ulonglong)(uVar9 & 0xf) * 0x18,0);
      return _Dst;
    }
    _Dst = (uint *)(plVar16 + -1);
    if ((*(uint *)(plVar16 + 6) == uVar9) && (*(ushort *)(plVar16 + 4) == *param_1)) {
      cVar4 = RtlEqualUnicodeString(plVar16 + 4,param_1,1);
      if (cVar4 != '\0') {
        LOCK();
        *_Dst = *_Dst + 1;
        UNLOCK();
        puVar11 = auStack_48;
        goto LAB_140010f26;
      }
    }
    plVar16 = (longlong *)*plVar16;
  } while( true );
}



===== LuafvPerformDelayedVirtualization @ 140010f60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvPerformDelayedVirtualization(longlong param_1,longlong param_2,longlong param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  char cVar11;
  bool bVar12;
  undefined1 auStack_1e8 [32];
  undefined4 local_1c8;
  undefined8 *local_1c0;
  longlong *local_1b8;
  undefined8 local_1b0;
  undefined4 local_1a8;
  undefined4 local_1a0;
  undefined4 local_198;
  undefined4 local_190;
  undefined8 local_188;
  undefined4 local_180;
  undefined4 local_178;
  undefined8 local_170;
  char local_168;
  undefined1 local_167;
  undefined1 local_166 [2];
  undefined4 local_164;
  longlong local_160;
  undefined8 local_158;
  longlong local_150;
  ulonglong local_148;
  longlong local_140;
  longlong local_138;
  longlong local_130;
  longlong local_128;
  ulonglong *local_120;
  longlong local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  longlong local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  longlong local_e0 [7];
  undefined4 local_a8;
  undefined1 local_98 [12];
  undefined4 local_8c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1e8;
  iVar4 = 0;
  local_158 = 0;
  local_e0[6] = 0;
  local_a8 = 0;
  local_8c = 0;
  local_e0[0] = 0;
  local_e0[1] = 0;
  local_e0[2] = 0;
  local_e0[3] = 0;
  local_140 = param_2;
  local_130 = param_1;
  local_118 = param_3;
  memset(local_98,0,0x44);
  local_138 = 0;
  local_f0 = 0;
  uStack_e8 = (ulonglong)uStack_e8._4_4_ << 0x20;
  local_150 = *(longlong *)(param_3 + 0xc0);
  lVar5 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_160 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_128 = 0;
  local_e0[4] = 0;
  local_e0[5] = 0;
  local_166[0] = 0;
  local_167 = 0;
  local_164 = 2;
  FltAcquirePushLockExclusiveEx(local_150 + 0x40,0);
  if ((*(uint *)(*(longlong *)(param_1 + 0x20) + 0x50) & 0x4000) != 0) {
    iVar4 = -0x3fffffff;
LAB_140011118:
    FltReleasePushLockEx(local_150 + 0x40,0);
    return iVar4;
  }
  if (*(char *)(param_3 + 0xfc) != '\0') goto LAB_140011118;
  puVar1 = *(ulonglong **)(param_3 + 0x100);
  plVar8 = local_e0;
  cVar11 = '\0';
  local_168 = '\0';
  local_148 = *puVar1;
  bVar12 = *(char *)(*(longlong *)(param_2 + 0x10) + 4) != '\0';
  local_120 = puVar1;
  if (bVar12) {
    SeCaptureSubjectContext(local_e0);
  }
  else {
    plVar8 = (longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18) + 8) + 0x20);
  }
  lVar7 = *plVar8;
  if (lVar7 == 0) {
    lVar7 = plVar8[2];
  }
  SeQueryAuthenticationIdToken(lVar7,&local_158);
  if (bVar12) {
    SeReleaseSubjectContext(local_e0);
  }
  uVar2 = local_148;
  lVar7 = *(longlong *)(*(longlong *)(local_148 + 0x68) + 0x10);
  if ((*(int *)(lVar7 + 0x30) != (int)local_158) || (*(int *)(lVar7 + 0x34) != local_158._4_4_)) {
    local_e0[6] = 0x20000000c;
    local_a8 = CONCAT22(local_a8._2_2_,1);
    iVar4 = SeCreateClientSecurityFromSubjectContext(param_3 + 0x108,local_e0 + 6,0,local_98);
    if (iVar4 < 0) goto LAB_140011118;
    lVar5 = PsReferenceImpersonationToken(SystemReserved1[0xf],local_166,&local_167,&local_164);
    local_128 = lVar5;
    iVar4 = SeImpersonateClientEx(local_98,0);
    SeDeleteClientSecurity(local_98);
    if (iVar4 < 0) goto LAB_1400112f4;
    cVar11 = '\x01';
    local_168 = '\x01';
  }
  lVar9 = local_130;
  uVar6 = LuafvCreateVirtualFile(local_130,local_140,puVar1,*(longlong *)(param_3 + 0xd0));
  puVar1 = local_120;
  lVar7 = local_140;
  uVar3 = local_148;
  iVar4 = (int)uVar6;
  if (-1 < iVar4) {
    local_100 = uVar2 + 0x30;
    local_110 = CONCAT44(local_110._4_4_,0x30);
    plVar10 = (longlong *)(local_150 + 0x18);
    uStack_108 = 0;
    uStack_f8 = CONCAT44(uStack_f8._4_4_,0x240);
    local_f0 = 0;
    uStack_e8 = 0;
    plVar8 = (longlong *)*plVar10;
    if (plVar8 != plVar10) {
      do {
        local_190 = (undefined4)plVar8[0x10];
        local_170 = 0;
        local_178 = 1;
        local_180 = 0;
        local_188 = 0;
        local_1a0 = *(undefined4 *)((longlong)plVar8 + 0x7c);
        local_198 = 1;
        local_1b8 = local_e0 + 4;
        local_1a8 = 0;
        local_1b0 = 0;
        local_1c0 = &local_110;
        local_1c8 = (undefined4)plVar8[0xf];
        iVar4 = FltCreateFileEx2(LuafvDriverData,*(undefined8 *)(lVar9 + 0x18),&local_138,&local_160
                                );
        if (iVar4 < 0) {
          LuafvLogFileError(lVar7,uVar3,&LuafvDelayedSwitchFailed,iVar4);
          plVar8[8] = 0;
          *(int *)(plVar8 + 9) = iVar4;
        }
        else {
          plVar8[6] = local_138;
          plVar8[7] = local_160;
          plVar8[8] = local_160;
          *(undefined1 *)((longlong)plVar8 + 0x4c) = 1;
          *(byte *)((longlong)puVar1 + 0x14) = *(byte *)((longlong)puVar1 + 0x14) | 2;
          lVar5 = plVar8[3];
          *(undefined8 *)(lVar5 + 0x28) = *(undefined8 *)(local_160 + 0x28);
          *(undefined8 *)(lVar5 + 0x30) = *(undefined8 *)(local_160 + 0x30);
        }
        plVar8 = (longlong *)*plVar8;
        lVar9 = local_130;
      } while (plVar8 != plVar10);
      param_3 = local_118;
      lVar5 = local_128;
      cVar11 = local_168;
    }
    iVar4 = 0;
  }
  if (cVar11 != '\0') {
    PsRevertToSelf();
  }
LAB_1400112f4:
  if (lVar5 != 0) {
    if (cVar11 != '\0') {
      local_1c8 = local_164;
      PsImpersonateClient(SystemReserved1[0xf],lVar5,local_166[0],local_167);
    }
    PsDereferenceImpersonationToken(lVar5);
  }
  FltReleasePushLockEx(local_150 + 0x40,0);
  if ((iVar4 < 0) || (*(longlong *)(param_3 + 0xf0) != 0)) {
    return iVar4;
  }
  return *(int *)(param_3 + 0xf8);
}



===== LuafvPrepareDelayedVirtualization @ 140011394 =====

int LuafvPrepareDelayedVirtualization
              (longlong param_1,longlong param_2,longlong *param_3,longlong param_4)

{
  uint *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  longlong lVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  longlong *local_58;
  undefined8 local_50;
  uint local_48 [2];
  longlong local_40;
  longlong local_38;
  
  lVar12 = *param_3;
  local_48[0] = 0;
  local_40 = 0;
  puVar9 = (uint *)0x0;
  local_38 = lVar12;
  puVar8 = FindOrCreateDvfcb((ushort *)(lVar12 + 0x30),local_48);
  if (puVar8 == (uint *)0x0) {
LAB_1400113e8:
    iVar7 = -0x3fffff66;
  }
  else {
    local_58 = &local_40;
    local_50 = 0;
    iVar7 = ObReferenceObjectByHandle(param_4,0x80000000,*(undefined8 *)IoFileObjectType_exref,0);
    if (iVar7 < 0) {
      local_40 = 0;
    }
    else {
      puVar9 = LuafvAllocatePool(0x200,0x138,'\x06');
      if (puVar9 == (uint *)0x0) goto LAB_1400113e8;
      lVar12 = *(longlong *)(param_1 + 0x20);
      uVar14 = *(uint *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18) + 0x10);
      if ((uVar14 >> 0x19 & 1) != 0) {
        uVar14 = uVar14 & 0xfdffffff | 0x1f01ff;
      }
      puVar1 = puVar8 + 0x10;
      uVar15 = (uint)*(ushort *)(*(longlong *)(param_2 + 0x10) + 0x2a);
      local_48[0] = uVar15;
      FltAcquirePushLockExclusiveEx(puVar1,0);
      local_58 = (longlong *)CONCAT71(local_58._1_7_,1);
      iVar7 = IoCheckShareAccess(uVar14,uVar15,lVar12,puVar8 + 0x12);
      if (-1 < iVar7) {
        puVar11 = puVar9 + 0x1e;
        puVar9[0x20] = 0;
        puVar9[0x21] = 0;
        puVar9[0x22] = 0;
        uVar16 = 0;
        *puVar11 = 1;
        KeInitializeEvent(puVar9 + 0x24);
        puVar2 = *(undefined8 **)(local_40 + 0x18);
        uVar6 = puVar2[1];
        *(undefined8 *)puVar9 = *puVar2;
        *(undefined8 *)(puVar9 + 2) = uVar6;
        uVar15 = *(uint *)((longlong)puVar2 + 0x14);
        uVar4 = *(uint *)(puVar2 + 3);
        uVar5 = *(uint *)((longlong)puVar2 + 0x1c);
        puVar9[4] = *(uint *)(puVar2 + 2);
        puVar9[5] = uVar15;
        puVar9[6] = uVar4;
        puVar9[7] = uVar5;
        uVar15 = *(uint *)((longlong)puVar2 + 0x24);
        uVar4 = *(uint *)(puVar2 + 5);
        uVar5 = *(uint *)((longlong)puVar2 + 0x2c);
        puVar9[8] = *(uint *)(puVar2 + 4);
        puVar9[9] = uVar15;
        puVar9[10] = uVar4;
        puVar9[0xb] = uVar5;
        *puVar9 = 0x1387666;
        *(byte *)(puVar9 + 1) = (byte)puVar9[1] | 0x40;
        *(byte *)((longlong)puVar9 + 6) = *(byte *)((longlong)puVar9 + 6) | 2;
        *(byte *)((longlong)puVar9 + 7) = *(byte *)((longlong)puVar9 + 7) & 0xf | 0x50;
        puVar10 = puVar9 + 0xe;
        *(uint **)(puVar9 + 0x10) = puVar10;
        *(uint **)puVar10 = puVar10;
        if (puVar11 != (uint *)0x0) {
          *(uint **)(puVar9 + 0xc) = puVar11;
        }
        puVar9[0x12] = 0;
        puVar9[0x13] = 0;
        puVar9[0x14] = 0;
        puVar9[0x15] = 0;
        puVar9[0x16] = 0;
        puVar9[0x17] = 0;
        puVar9[0x18] = 0;
        puVar9[0x19] = 0;
        puVar9[0x1a] = 0;
        puVar9[0x1c] = 0;
        puVar9[0x1d] = 0;
        if (puVar8 + 0x1a != (uint *)0x0) {
          *(uint **)(puVar9 + 0x14) = puVar8 + 0x1a;
        }
        *(longlong *)(puVar9 + 0x34) = param_4;
        puVar9[0x38] = 0;
        puVar9[0x39] = 0;
        puVar9[0x3a] = 0;
        puVar9[0x3b] = 0;
        *(longlong *)(puVar9 + 0x36) = local_40;
        *(undefined1 *)(puVar9 + 0x3f) = 0;
        *(longlong **)(puVar9 + 0x40) = param_3;
        *(longlong *)(puVar9 + 0x3c) = local_40;
        FltReferenceContext();
        SeCaptureSubjectContext(puVar9 + 0x42);
        puVar13 = auStack_78;
        puVar9[0x4b] = local_48[0];
        puVar9[0x4a] = uVar14;
        uVar14 = *(uint *)(*(longlong *)(param_2 + 0x10) + 0x20);
        *(longlong *)(puVar9 + 0x32) = lVar12;
        puVar9[0x4c] = uVar14 & 0xffffff;
        *(undefined8 *)(lVar12 + 0x20) = 0;
        *(uint **)(lVar12 + 0x18) = puVar9;
        puVar10 = puVar9 + 0x2c;
        *(undefined8 *)(lVar12 + 0x28) = *(undefined8 *)(local_40 + 0x28);
        puVar11 = puVar8 + 6;
        lVar12 = *(longlong *)puVar11;
        if (*(uint **)(lVar12 + 8) != puVar11) {
          puVar11 = (uint *)0x3;
          pcVar3 = (code *)swi(0x29);
          puVar10 = (uint *)(*pcVar3)();
          puVar13 = auStack_70;
        }
        *(longlong *)puVar10 = lVar12;
        *(uint **)(puVar10 + 2) = puVar11;
        *(uint **)(lVar12 + 8) = puVar10;
        *(uint **)puVar11 = puVar10;
        *(uint **)(puVar9 + 0x30) = puVar8;
        *(undefined8 *)(puVar13 + -8) = 0x1400116ac;
        FltReleasePushLockEx(puVar1,0);
        *(undefined4 *)(puVar13 + 0x28) = 3;
        *(undefined8 *)(puVar13 + 0x20) = *(undefined8 *)(puVar13 + 0x40);
        *(undefined8 *)(puVar13 + -8) = 0x1400116d9;
        LuafvLogUtcEvent((uint *)&DAT_14000b1e8,0x14000b1f0,uVar16,param_2,
                         *(longlong *)(puVar13 + 0x20),*(int *)(puVar13 + 0x28));
        return 0;
      }
      FltReleasePushLockEx(puVar1,0);
      lVar12 = local_38;
    }
    if (iVar7 == -0x3fffffbd) goto LAB_1400114e4;
  }
  LuafvLogFileError(param_2,lVar12,&LuafvPrepareDelayedFailed,iVar7);
LAB_1400114e4:
  *(int *)(param_2 + 0x18) = iVar7;
  *(undefined8 *)(param_2 + 0x20) = 0;
  if (puVar9 != (uint *)0x0) {
    LuafvFreePool((longlong)puVar9);
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  if (param_4 != 0) {
    FltClose(param_4);
  }
  if (puVar8 != (uint *)0x0) {
    DereferenceDvfcb((int *)puVar8);
  }
  return iVar7;
}



===== LuafvUnlinkFsContextFromDvfcb @ 140011700 =====

void LuafvUnlinkFsContextFromDvfcb(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  piVar1 = *(int **)(param_1 + 0xc0);
  FltAcquirePushLockExclusiveEx(piVar1 + 0x10,0);
  plVar5 = (longlong *)(param_1 + 0xb0);
  lVar2 = *plVar5;
  if ((*(longlong **)(lVar2 + 8) == plVar5) &&
     (plVar3 = *(longlong **)(param_1 + 0xb8), (longlong *)*plVar3 == plVar5)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    FltReleasePushLockEx(piVar1 + 0x10,0);
    DereferenceDvfcb(piVar1);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== LuafvIsIncludedVolume @ 140011784 =====

ulonglong LuafvIsIncludedVolume(ulonglong *param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong local_38 [4];
  undefined8 local_18;
  
  uVar1 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_18 = 0;
  if (((short)*param_1 != 0) &&
     (uVar1 = LuafvFindTableNode((undefined *)0x0,param_1,0,local_38), -1 < (int)uVar1)) {
    if (((char)local_18 != '\0') &&
       (((*(longlong *)(local_38[0] + 0x28) != 0 || (*(short *)(local_38[0] + 0x1c) == 0)) ||
        ((*(byte *)(local_38[0] + 0x1c) & 8) != 0)))) {
      *param_2 = local_38[0];
      return CONCAT71((int7)(uVar1 >> 8),1);
    }
    uVar1 = LuafvDereferenceTableNodeEx(local_38[0],'\0','\0');
  }
  return uVar1 & 0xffffffffffffff00;
}



===== GetVolumeRootFileId @ 140011800 =====

ulonglong GetVolumeRootFileId(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 local_res8;
  longlong local_res18;
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffff38;
  undefined4 uVar5;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffff48;
  undefined2 *puVar6;
  undefined4 uVar7;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar8;
  undefined8 in_stack_ffffffffffffff60;
  undefined4 uVar9;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar10;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  local_54 = 0;
  local_3c = 0;
  local_res8 = 0;
  local_res20 = 0;
  local_res18 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar3 = *(ulonglong *)(param_1 + 0xa8) & 0xfffffffffffffff8;
  if ((uVar3 == 0) || (*(longlong *)(uVar3 + 0x20) != param_1)) {
    uVar2 = 0xc000000d;
  }
  else {
    if (*(longlong *)(param_1 + 0xf8) == 0) {
      uVar2 = Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline();
      puVar6 = (undefined2 *)(param_1 + 0xf0);
      if ((int)uVar2 == 0) {
        uVar2 = LuafvBuildTableNodeName(param_1,0,(ushort *)0x0,(ushort *)0x0,'\x01',puVar6);
      }
      else {
        uVar2 = LuafvBuildTableNodeName2(param_1,0,(ushort *)0x0,(ushort *)0x0,'\x01','\x01',puVar6)
        ;
        uVar7 = (undefined4)((ulonglong)puVar6 >> 0x20);
      }
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    local_48 = param_1 + 0xf0;
    local_58 = 0x30;
    local_50 = 0;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    if (LuafvDriverData == 0) {
      uVar5 = 0;
      local_res18 = 0;
      uVar2 = IoCreateFileEx(&local_res8,0x100001,&local_58,&local_68,0,0x80,CONCAT44(uVar7,7),
                             CONCAT44(uVar8,1),0x21,0,0,0,0,0x800,0);
    }
    else {
      uVar4 = CONCAT44(uVar5,0x100001);
      uVar2 = FltCreateFileEx2(LuafvDriverData,*(undefined8 *)(uVar3 + 0x10),&local_res8,
                               &local_res18,uVar4,&local_58,&local_68,0,0x80,CONCAT44(uVar9,7),1,
                               0x21,0,0,CONCAT44(uVar10,0x800),0);
      uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
    }
    if (-1 < (int)uVar2) {
      if (local_res18 == 0) {
        uVar1 = ZwQueryInformationFile(local_res8,&local_68,&local_res20,8,CONCAT44(uVar5,6));
      }
      else {
        uVar1 = FltQueryInformationFile(*(undefined8 *)(uVar3 + 0x10));
      }
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        *param_2 = local_res20;
      }
      if (local_res18 != 0) {
        ObfDereferenceObject();
      }
      if (LuafvDriverData == 0) {
        ZwClose(local_res8);
      }
      else {
        FltClose();
      }
    }
  }
  return uVar2;
}



===== LuafvBuildTableNodeName2 @ 140011a78 =====

undefined8
LuafvBuildTableNodeName2
          (longlong param_1,longlong param_2,ushort *param_3,ushort *param_4,char param_5,
          char param_6,undefined2 *param_7)

{
  ushort *puVar1;
  int *piVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined2 *_Dst;
  void *_Dst_00;
  bool bVar14;
  longlong local_res10;
  
  if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  }
  else {
    FltAcquirePushLockSharedEx(param_1,0);
  }
  FltAcquirePushLockSharedEx(&DAT_14000c280,0);
  uVar12 = 0;
  lVar4 = *(longlong *)(param_1 + 0x20);
  lVar5 = param_1;
  while( true ) {
    local_res10 = param_2;
    if ((lVar4 == 0) || (local_res10 = param_2, lVar5 == param_2)) goto LAB_140011b12;
    if (*(longlong *)(lVar5 + 0xf8) != 0) break;
    puVar1 = (ushort *)(lVar5 + 0x50);
    lVar5 = *(longlong *)(lVar5 + 0x20);
    uVar12 = uVar12 + 2 + (uint)*puVar1;
    lVar4 = *(longlong *)(lVar5 + 0x20);
  }
  param_3 = (ushort *)(lVar5 + 0xf0);
  local_res10 = lVar5;
LAB_140011b12:
  if ((param_3 == (ushort *)0x0) || (*param_3 == 0)) {
    bVar8 = false;
    bVar14 = false;
  }
  else {
    bVar14 = *(short *)(*(longlong *)(param_3 + 4) + -2 + (ulonglong)(*param_3 >> 1) * 2) == 0x5c;
    bVar8 = true;
    uVar12 = uVar12 + *param_3;
    if (bVar14) {
      uVar12 = uVar12 - 2;
    }
  }
  if ((param_4 == (ushort *)0x0) || (*param_4 == 0)) {
    bVar7 = false;
    bVar9 = false;
  }
  else {
    bVar6 = true;
    sVar3 = **(short **)(param_4 + 4);
    if ((sVar3 == 0x5c) || (bVar7 = false, sVar3 == 0x3a)) {
      bVar7 = true;
    }
    bVar9 = true;
    if ((*(short **)(param_4 + 4))[(ulonglong)(*param_4 >> 1) - 1] == 0x5c) {
      bVar9 = true;
      goto LAB_140011baa;
    }
  }
  bVar6 = bVar9;
  bVar9 = false;
LAB_140011baa:
  if ((bVar6) && (uVar12 = uVar12 + *param_4, !bVar7)) {
    uVar12 = uVar12 + 2;
  }
  if ((param_5 != '\0') && (!bVar9)) {
    uVar12 = uVar12 + 2;
  }
  puVar10 = LuafvAllocatePool(1,uVar12,'\x02');
  if (puVar10 == (uint *)0x0) {
    uVar13 = 0xc000009a;
  }
  else {
    _Dst = (undefined2 *)((longlong)puVar10 + (ulonglong)uVar12);
    if ((param_5 != '\0') && (!bVar9)) {
      _Dst = _Dst + -1;
      *_Dst = 0x5c;
    }
    if (bVar6) {
      _Dst = (undefined2 *)((longlong)_Dst + (longlong)(int)-(uint)*param_4);
      memmove(_Dst,*(void **)(param_4 + 4),(ulonglong)*param_4);
      if (!bVar7) {
        _Dst = _Dst + -1;
        *_Dst = 0x5c;
      }
    }
    lVar4 = *(longlong *)(param_1 + 0x20);
    lVar5 = param_1;
    while ((lVar4 != 0 && (lVar5 != local_res10))) {
      _Dst_00 = (void *)((longlong)_Dst + (longlong)(int)-(uint)*(ushort *)(lVar5 + 0x50));
      memmove(_Dst_00,*(void **)(lVar5 + 0x58),(ulonglong)*(ushort *)(lVar5 + 0x50));
      _Dst = (undefined2 *)((longlong)_Dst_00 + -2);
      *_Dst = 0x5c;
      lVar5 = *(longlong *)(lVar5 + 0x20);
      lVar4 = *(longlong *)(lVar5 + 0x20);
    }
    if (bVar8) {
      uVar11 = *param_3 - 2;
      if (!bVar14) {
        uVar11 = (uint)*param_3;
      }
      _Dst = (undefined2 *)((longlong)_Dst + (longlong)(int)-uVar11);
      memmove(_Dst,*(void **)(param_3 + 4),(longlong)(int)uVar11);
    }
    if (param_6 != '\0') {
      FltReleasePushLockEx(&DAT_14000c280,0);
      FltAcquirePushLockExclusiveEx(&DAT_14000c280,0);
    }
    *(undefined2 **)(param_7 + 4) = _Dst;
    uVar13 = 0;
    *param_7 = (short)uVar12;
    param_7[1] = (short)uVar12;
  }
  FltReleasePushLockEx(&DAT_14000c280,0);
  if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
    piVar2 = (int *)(param_1 + 0x10);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 != 0) {
      return uVar13;
    }
    *(undefined8 *)(param_1 + 8) = 0;
  }
  FltReleasePushLockEx(param_1,0);
  return uVar13;
}



===== LuafvInitializeFileTableForVolume @ 140011d60 =====

void LuafvInitializeFileTableForVolume(undefined8 *param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  lVar3 = param_1[4];
  uVar8 = 0;
  LuafvEnumerateFileTable(lVar3,'\0',InitializeFileTableForVolumePreWorker,(undefined *)0x0,param_1)
  ;
  puVar1 = param_1 + 5;
  param_1[6] = puVar1;
  *puVar1 = puVar1;
  FltAcquirePushLockExclusiveEx(&DAT_14000c278);
  puVar7 = auStackY_38;
  puVar6 = &DAT_14000c268;
  if ((undefined *)*DAT_14000c270 != &DAT_14000c268) {
    puVar6 = (undefined *)0x3;
    pcVar5 = (code *)swi(0x29);
    DAT_14000c270 = (undefined8 *)(*pcVar5)();
    puVar7 = auStackY_30;
  }
  *param_1 = puVar6;
  param_1[1] = DAT_14000c270;
  *DAT_14000c270 = param_1;
  *(undefined8 *)(puVar7 + -8) = 0x140011de5;
  DAT_14000c270 = param_1;
  FltReleasePushLockEx(&DAT_14000c278);
  lVar4 = *(longlong *)(lVar3 + 0x20);
  if (lVar4 != 0) {
    if (*(void **)(lVar4 + 8) == SystemReserved1[0xf]) {
      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    }
    else {
      *(undefined8 *)(puVar7 + -8) = 0x140011e13;
      FltAcquirePushLockExclusiveEx(lVar4);
      *(void **)(lVar4 + 8) = SystemReserved1[0xf];
      *(undefined4 *)(lVar4 + 0x10) = 1;
    }
  }
  if (*(void **)(lVar3 + 8) == SystemReserved1[0xf]) {
    *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
  }
  else {
    *(undefined8 *)(puVar7 + -8) = 0x140011e4c;
    FltAcquirePushLockExclusiveEx(lVar3);
    *(void **)(lVar3 + 8) = SystemReserved1[0xf];
    *(undefined4 *)(lVar3 + 0x10) = 1;
  }
  *(ushort *)(lVar3 + 0x1e) = *(ushort *)(lVar3 + 0x1e) | 0x80;
  *(undefined8 *)(puVar7 + -8) = 0x140011e7b;
  UpdateTableNode(lVar3,(uint *)0x0,(longlong *)0x0,uVar8);
  if (*(void **)(lVar3 + 8) == SystemReserved1[0xf]) {
    piVar2 = (int *)(lVar3 + 0x10);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 != 0) goto LAB_140011ea6;
    *(undefined8 *)(lVar3 + 8) = 0;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140011ea1;
  FltReleasePushLockEx(lVar3,0);
LAB_140011ea6:
  lVar3 = *(longlong *)(lVar3 + 0x20);
  if (lVar3 != 0) {
    if (*(void **)(lVar3 + 8) == SystemReserved1[0xf]) {
      piVar2 = (int *)(lVar3 + 0x10);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 != 0) {
        return;
      }
      *(undefined8 *)(lVar3 + 8) = 0;
    }
    *(undefined8 *)(puVar7 + -8) = 0x140011ed2;
    FltReleasePushLockEx(lVar3,0);
  }
  return;
}



===== LuafvTerminateFileTableForVolume @ 140011eec =====

void LuafvTerminateFileTableForVolume(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  lVar1 = param_1[4];
  FltAcquirePushLockExclusiveEx(&DAT_14000c278,0);
  lVar2 = *param_1;
  if ((*(longlong **)(lVar2 + 8) == param_1) &&
     (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 == param_1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *param_1 = 0;
    FltReleasePushLockEx(&DAT_14000c278);
    LuafvEnumerateFileTable(lVar1,'\0',(undefined *)0x0,ClearFileTablePostWorker,4);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== ResolveTableNodeConflict @ 140011f7c =====

longlong ResolveTableNodeConflict(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int local_res8 [2];
  int local_res10 [2];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  LuafvEnumerateFileTable(param_1,'\x01',CountPermanentNodesPreWorker,(undefined *)0x0,local_res8);
  lVar1 = param_2;
  if (local_res8[0] == 0) {
    LuafvEnumerateFileTable
              (param_2,'\x01',CountPermanentNodesPreWorker,(undefined *)0x0,local_res10);
    if (local_res10[0] != 0) {
      lVar1 = param_1;
      param_1 = param_2;
    }
  }
  RemoveTableNode(lVar1,'\0');
  LuafvDereferenceTableNodeEx(lVar1,'\x01','\0');
  return param_1;
}



===== LuafvLogDelayedOnly @ 14001201c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvLogDelayedOnly(longlong param_1,longlong *param_2)

{
  undefined1 auStackY_e8 [32];
  longlong local_a8 [18];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  LuafvSetFileCreateEvent(param_1,param_2,(longlong)local_a8);
  LuafvLogFileEvent(param_1,*param_2,(longlong)param_2,0,&LuafvDelayedOnlyEvent,local_a8,9);
  return;
}



===== LuafvLogVirtualCreate @ 140012094 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvLogVirtualCreate(longlong param_1,longlong *param_2)

{
  undefined1 auStackY_f8 [32];
  longlong local_b8 [18];
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_1c = 0;
  local_28 = *(longlong *)(param_1 + 0x10) + 4;
  local_20 = 1;
  LuafvSetFileCreateEvent(param_1,param_2,(longlong)local_b8);
  LuafvLogFileEvent(param_1,*param_2,(longlong)param_2,0,&LuafvVirtualCreateEvent,local_b8,10);
  return;
}



===== LuafvLogVirtualRename @ 140012130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvLogVirtualRename(longlong param_1,longlong *param_2,char param_3,char param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 auStackY_f8 [32];
  ushort local_b8 [8];
  longlong local_a8 [14];
  ushort *local_38;
  undefined8 local_30;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar4 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
  local_b8[0] = *(ushort *)(lVar1 + 0x10) >> 1;
  local_38 = local_b8;
  local_30 = 2;
  local_28 = lVar1 + 0x14;
  local_20 = *(undefined4 *)(lVar1 + 0x10);
  uVar2 = -(uint)(param_3 != '\0') & 0x100;
  local_1c = 0;
  uVar3 = uVar2 | 0x200;
  if (param_4 == '\0') {
    uVar3 = uVar2;
  }
  if (param_2 != (longlong *)0x0) {
    lVar4 = *param_2;
  }
  LuafvLogFileEvent(param_1,lVar4,(longlong)param_2,uVar3,&LuafvVirtualRenameEvent,local_a8,9);
  return;
}



===== LuafvInstanceCleanup @ 140012210 =====

void LuafvInstanceCleanup(longlong *param_1)

{
  ExWaitForRundownProtectionRelease(param_1 + 0x69);
  LuafvTerminateUsn((longlong)param_1);
  if (param_1[4] != 0) {
    LuafvTerminateUserStoresForVolume((longlong)param_1);
    LuafvTerminateFileTableForVolume(param_1);
    LuafvDereferenceTableNodeEx(param_1[4],'\0','\0');
  }
  LuafvFreePool(param_1[3]);
  return;
}



===== LuafvPostAcquireForSectionSynchronization @ 140012270 =====

undefined8
LuafvPostAcquireForSectionSynchronization
          (longlong param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = Feature_3278626104__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar1 != 0) && ((*(int *)(param_1 + 0x18) < 0 || ((param_4 & 1) != 0)))) {
    FltReleasePushLockEx(param_3 + 0x40,0);
  }
  return 0;
}



===== LuafvPostDirectoryControlSafe @ 1400122d0 =====

undefined8 LuafvPostDirectoryControlSafe(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = FltLockUserBuffer();
  if (-1 < (int)uVar3) {
    lVar1 = *(longlong *)(param_1 + 0x10);
    lVar2 = *(longlong *)(lVar1 + 0x40);
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      puVar4 = (uint *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      puVar4 = *(uint **)(lVar2 + 0x18);
    }
    if (puVar4 == (uint *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      uVar3 = LuafvMarkVirtualDirectoryEntries(puVar4,*(uint *)(lVar1 + 0x18));
      if (-1 < (int)uVar3) {
        return 0;
      }
    }
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(uint *)(param_1 + 0x18) = uVar3;
  return 0;
}



===== LuafvPostFileSystemControl @ 140012360 =====

undefined8
LuafvPostFileSystemControl(longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4)

{
  int iVar1;
  
  if ((param_4 & 1) != 0) {
    return 0;
  }
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x28);
  if (iVar1 != 0x90018) {
    if (iVar1 == 0x9001c) {
      if (*(int *)(param_1 + 0x18) < 0) {
        return 0;
      }
      goto LAB_14001238d;
    }
    if (iVar1 != 0x90020) {
      return 0;
    }
  }
  if (-1 < *(int *)(param_1 + 0x18)) {
    return 0;
  }
LAB_14001238d:
  LuafvResumeUsn(param_1);
  return 0;
}



===== LuafvUnload @ 1400123b0 =====

undefined8 LuafvUnload(void)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong *plVar6;
  uint uVar7;
  
  ExWaitForRundownProtectionRelease(&DAT_14000c0e8);
  while (LuafvActiveDvfcbCount != 0) {
    DbgPrint("***\n*** LUAFV stalling unload due to delayed virtualization\n***\n");
    KeDelayExecutionThread(0);
  }
  LuafvTerminateScavenger();
  SeUnregisterLogonSessionTerminatedRoutineEx(UserLogoffCallback);
  LuafvScavengeUserList('\x01');
  if (LuafvDriverData != 0) {
    FltUnregisterFilter();
  }
  if (DAT_14000b8c0 != 0) {
    LuafvFreePool(DAT_14000b8c0);
  }
  if (DAT_14000c2b8 != 0) {
    LuafvFreePool(DAT_14000c2b8);
  }
  DAT_14000c2b8 = 0;
  if (DAT_14000c288 != 0) {
    LuafvFreePool(DAT_14000c288);
    DAT_14000c288 = 0;
  }
  if (DAT_14000c110 != 0) {
    LuafvFreePool(DAT_14000c110);
    DAT_14000c110 = 0;
  }
  if (DAT_14000c120 != 0) {
    LuafvFreePool(DAT_14000c120);
    DAT_14000c120 = 0;
  }
  LuafvEnumerateFileTable(0x14000c128,'\0',(undefined *)0x0,ClearFileTablePostWorker,2);
  uVar7 = 0;
  plVar6 = &SdTable;
  while( true ) {
    while (plVar3 = (longlong *)*plVar6, plVar3 == plVar6) {
      uVar7 = uVar7 + 1;
      plVar6 = plVar6 + 3;
      if (0xf < uVar7) {
        LuafvTerminatePool();
        if (DAT_14000c100 != 0) {
          EtwUnregister();
        }
        uVar5 = DAT_14000b030;
        DAT_14000b030 = 0;
        DAT_14000b010 = 0;
        EtwUnregister(uVar5);
        wil_UninitializeFeatureStaging();
        return 0;
      }
    }
    lVar1 = *plVar3;
    if ((*(longlong **)(lVar1 + 8) != plVar3) ||
       (plVar2 = (longlong *)plVar3[1], (longlong *)*plVar2 != plVar3)) break;
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    LuafvFreePool((longlong)plVar3);
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
}



===== wil_UninitializeFeatureStaging @ 140012578 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400125d0 =====

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
      goto LAB_14001262d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001262d;
    }
  }
  uVar1 = 0x206;
LAB_14001262d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140012638 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400126f0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140012728 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400127aa;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400127aa;
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
LAB_1400127aa:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140012800 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140012860 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001287c =====

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



===== LuafvTerminatePool @ 140012930 =====

void LuafvTerminatePool(void)

{
  undefined *puVar1;
  longlong lVar2;
  
  FltAcquirePushLockExclusiveEx(&PoolLock,0);
  ExDeletePagedLookasideList(&StoreFileLookaside);
  ExDeletePagedLookasideList(&TableNodeLookaside);
  puVar1 = &StringLookaside;
  lVar2 = 5;
  do {
    ExDeletePagedLookasideList(puVar1);
    puVar1 = puVar1 + 0x80;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  FltReleasePushLockEx(&PoolLock,0);
  return;
}



===== LuafvCreateTrustedInstallerSid @ 1400129c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LuafvCreateTrustedInstallerSid(undefined8 *param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  uVar4 = 0;
  local_14 = 0x500;
  local_18 = 0;
  uVar1 = RtlLengthRequiredSid(6);
  puVar2 = LuafvAllocatePool(1,uVar1,'\r');
  if (puVar2 == (uint *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    RtlInitializeSid(puVar2,&local_18,6);
    puVar3 = (undefined4 *)RtlSubAuthoritySid(puVar2,0);
    *puVar3 = 0x50;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(puVar2,1);
    *puVar3 = 0x38fb89b5;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(puVar2,2);
    *puVar3 = 0xcbc28419;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(puVar2,3);
    *puVar3 = 0x6d236c5c;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(puVar2,4);
    *puVar3 = 0x6e770057;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(puVar2,5);
    *puVar3 = 0x876402c0;
    *param_1 = puVar2;
  }
  return uVar4;
}



===== LuafvReportAuditVirtualizationEvent @ 140012afc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvReportAuditVirtualizationEvent
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  undefined1 auStack_4f8 [32];
  undefined4 local_4d8;
  char *local_4d0;
  char *local_4c8;
  char local_4b8;
  char local_4b7 [7];
  longlong local_4b0 [3];
  longlong local_498 [4];
  undefined4 local_478;
  undefined8 local_474;
  undefined4 local_46c;
  undefined8 local_468;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_4f8;
  local_4b8 = '\0';
  local_4b7[0] = '\0';
  local_498[0] = 0;
  local_498[1] = 0;
  local_498[2] = 0;
  local_498[3] = 0;
  local_4b0[2] = param_4;
  memset(&local_478,0,0x418);
  plVar4 = local_498;
  local_4b0[1] = 0;
  iVar1 = 0;
  local_4b0[0] = 0;
  bVar5 = *(char *)(*(longlong *)(param_2 + 0x10) + 4) != '\0';
  if (bVar5) {
    SeCaptureSubjectContext(local_498);
  }
  else {
    plVar4 = (longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18) + 8) + 0x20);
  }
  lVar3 = *plVar4;
  if (lVar3 == 0) {
    lVar3 = plVar4[2];
  }
  local_4c8 = local_4b7;
  local_4d0 = &local_4b8;
  local_4d8 = CONCAT31(local_4d8._1_3_,1);
  SeExamineSacl(param_1,param_1,lVar3,0x1f01ff);
  if (bVar5) {
    SeReleaseSubjectContext(local_498);
  }
  if ((local_4b8 != '\0') || (local_4b7[0] != '\0')) {
    local_478 = 3;
    local_474 = 0x13bb;
    local_46c = 0;
    local_468 = 0x80000;
    iVar1 = SeQueryAuthenticationIdToken(lVar3,local_4b0 + 1);
    if (-1 < iVar1) {
      iVar1 = SeSetAuditParameter(&local_478,5,local_474._4_4_,local_4b0 + 1);
      if (-1 < iVar1) {
        iVar1 = local_474._4_4_ + 1;
        local_474 = CONCAT44(iVar1,(undefined4)local_474);
        iVar1 = SeSetAuditParameter(&local_478,2,iVar1,param_3);
        if (-1 < iVar1) {
          iVar1 = local_474._4_4_ + 1;
          local_474 = CONCAT44(iVar1,(undefined4)local_474);
          iVar1 = SeSetAuditParameter(&local_478,2,iVar1,local_4b0[2]);
          if (-1 < iVar1) {
            local_474 = CONCAT44(local_474._4_4_ + 1,(undefined4)local_474);
            uVar2 = FltGetRequestorProcessId(param_2);
            iVar1 = SeSetAuditParameter(&local_478,0xb,local_474._4_4_,uVar2);
            if (-1 < iVar1) {
              local_474 = CONCAT44(local_474._4_4_ + 1,(undefined4)local_474);
              lVar3 = FltGetRequestorProcess(param_2);
              if (lVar3 == 0) {
                iVar1 = -0x3ffff8e4;
              }
              else {
                iVar1 = SeLocateProcessImageName(lVar3,local_4b0);
                if (-1 < iVar1) {
                  iVar1 = SeSetAuditParameter(&local_478,2,local_474._4_4_,local_4b0[0]);
                  if (-1 < iVar1) {
                    local_474 = CONCAT44(local_474._4_4_ + 1,(undefined4)local_474);
                    local_4d8 = 0x75;
                    iVar1 = SeReportSecurityEventWithSubCategory(0,&LuafvAuditSource,0,&local_478);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_4b0[0] != 0) {
    ExFreePoolWithTag(local_4b0[0],0x61506553);
  }
  return iVar1;
}



===== LuafvBuildSecurityDescriptor @ 140012dc8 =====

int LuafvBuildSecurityDescriptor
              (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  
  iVar6 = 0;
  puVar4 = param_1;
  lVar8 = 3;
  do {
    lVar7 = lVar8;
    iVar2 = RtlLengthSid(*puVar4);
    puVar4 = puVar4 + 2;
    iVar6 = iVar6 + 0xc + iVar2;
    lVar8 = lVar7 + -1;
  } while (lVar8 != 0);
  puVar3 = LuafvAllocatePool((int)lVar7,iVar6 + 0x30,'\x04');
  if (puVar3 == (uint *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = RtlCreateSecurityDescriptor(puVar3,1);
    if (-1 < iVar2) {
      puVar1 = puVar3 + 10;
      iVar2 = RtlCreateAcl(puVar1,iVar6,2);
      if (-1 < iVar2) {
        uVar5 = 0;
        puVar4 = param_1 + 1;
        do {
          iVar2 = RtlAddAccessAllowedAceEx
                            (puVar1,2,*(undefined4 *)puVar4,*(undefined4 *)((longlong)puVar4 + 4),
                             puVar4[-1]);
          if (iVar2 < 0) goto LAB_140012ee5;
          uVar5 = uVar5 + 1;
          puVar4 = puVar4 + 2;
        } while (uVar5 < 3);
        iVar2 = RtlSetDaclSecurityDescriptor(puVar3,1,puVar1,0);
        if ((-1 < iVar2) && (iVar2 = RtlSetOwnerSecurityDescriptor(puVar3,param_3,0), -1 < iVar2)) {
          *param_4 = puVar3;
          return iVar2;
        }
      }
    }
LAB_140012ee5:
    LuafvFreePool((longlong)puVar3);
  }
  return iVar2;
}



===== LuafvCreateStoreRootPath @ 140012f1c =====

int LuafvCreateStoreRootPath(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  lVar2 = FltAllocateGenericWorkItem();
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    KeInitializeEvent(&local_28,0,0);
    uStack_30 = param_2;
    iVar1 = FltQueueGenericWorkItem(lVar2,param_1,LuafvCreateStoreRootPathWorker,1,&local_38);
    if (-1 < iVar1) {
      iVar1 = KeWaitForSingleObject(&local_28,0,0,0,0);
      if (-1 < iVar1) {
        iVar1 = (int)local_38;
      }
    }
    FltFreeGenericWorkItem(lVar2);
  }
  return iVar1;
}



===== LuafvCreateStoreRootPathWorker @ 140013000 =====

void LuafvCreateStoreRootPathWorker(undefined8 param_1,undefined8 param_2,int *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_res10;
  longlong local_res18;
  longlong local_res20;
  undefined8 local_88;
  longlong lStack_80;
  longlong local_78;
  undefined2 *local_70;
  longlong local_68 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  longlong local_38;
  ulonglong local_30;
  
  local_res18 = 0;
  local_res10 = 0;
  local_res20 = 0;
  local_38 = 0;
  local_30 = local_30 & 0xffffffff00000000;
  local_88 = 0;
  lStack_80 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  iVar2 = FltGetInstanceContext(param_2,&local_res18);
  if (-1 < iVar2) {
    local_78 = *(longlong *)(local_res18 + 0x18) + 0x38;
    local_70 = &LuafvStoreRoot;
    iVar2 = LuafvAllocateAndBuildString(&local_78,2,&local_88);
    if (-1 < iVar2) {
      iVar2 = LuafvCreateStoreRootSecurityDescriptor(&local_res20);
      lVar1 = local_res20;
      if (-1 < iVar2) {
        local_48 = &local_88;
        uStack_50 = 0;
        local_30 = 0;
        local_58 = CONCAT44(local_58._4_4_,0x30);
        uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
        local_38 = local_res20;
        iVar2 = FltCreateFileEx2(LuafvDriverData,param_2,&local_res10,0,0x1c0100,&local_58,local_68,
                                 0,0x12,7,3,0x4021,0,0,0x900,0);
        if (-1 < iVar2) {
          if (*(undefined8 **)(param_3 + 2) == (undefined8 *)0x0) {
            FltClose(local_res10);
          }
          else {
            **(undefined8 **)(param_3 + 2) = local_res10;
          }
        }
        LuafvFreePool(lVar1);
      }
      LuafvFreePool(lStack_80);
    }
    FltReleaseContext(local_res18);
  }
  *param_3 = iVar2;
  KeSetEvent(param_3 + 4,1);
  return;
}



===== LuafvCreateStoreRootSecurityDescriptor @ 1400131c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvCreateStoreRootSecurityDescriptor(undefined8 *param_1)

{
  longlong lVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  lVar1 = *(longlong *)SeExports_exref;
  local_48 = *(undefined8 *)(lVar1 + 0x108);
  local_38 = *(undefined8 *)(lVar1 + 0x110);
  local_3c = 0x1fffff;
  local_40 = 3;
  local_2c = 0x1fffff;
  local_28 = *(undefined8 *)(lVar1 + 0xc0);
  local_30 = 3;
  local_20 = 0;
  local_1c = 0x1200a9;
  LuafvBuildSecurityDescriptor(&local_48,3,local_38,param_1);
  return;
}



===== LuafvCreateUserStoreSecurityDescriptor @ 140013250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvCreateUserStoreSecurityDescriptor(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_28 = *(undefined8 *)(param_1 + 0x50);
  local_40 = 3;
  local_3c = 0x1fffff;
  lVar1 = *(longlong *)SeExports_exref;
  local_30 = 3;
  local_2c = 0x1fffff;
  local_48 = *(undefined8 *)(lVar1 + 0x108);
  local_38 = *(undefined8 *)(lVar1 + 0x110);
  local_20 = 3;
  local_1c = 0x1fffff;
  LuafvBuildSecurityDescriptor(&local_48,lVar1,local_28,param_2);
  return;
}



===== LuafvCreateVirtualPath @ 1400132e0 =====

int LuafvCreateVirtualPath(undefined8 param_1,longlong param_2,ulonglong *param_3)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ushort uVar8;
  uint uVar9;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  ulonglong uStack_50;
  ushort local_48 [16];
  
  uVar6 = param_3[0xd];
  uVar1 = *(ushort *)(uVar6 + 0x28);
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_48[0xc] = 0;
  local_48[0xd] = 0;
  local_48[0xe] = 0;
  local_48[0xf] = 0;
  if (*(char *)(uVar6 + 0x50) == '\0') {
    uVar9 = ((uint)uVar1 - (uint)*(ushort *)(*(longlong *)(uVar6 + 0x10) + 0x58)) - 2;
  }
  else {
    uVar9 = 0;
  }
  local_68 = param_3[6];
  uStack_60 = param_3[7];
  iVar5 = 0;
  bVar2 = true;
  local_58 = *param_3;
  uStack_50 = param_3[1];
  uVar8 = (ushort)*param_3;
  if ((1 < uVar8) &&
     (*(short *)((uStack_50 - 2) + (ulonglong)(((uint)*param_3 & 0xffff) >> 1) * 2) == 0x5c)) {
    uVar6 = local_68 >> 0x10;
    local_68 = CONCAT62((int6)uVar6,(ushort)local_68 + -2);
    uVar6 = local_58 >> 0x10;
    local_58 = CONCAT62((int6)uVar6,uVar8 - 2);
  }
  do {
    while( true ) {
      if (bVar2) {
        uVar6 = LuafvSplitRootPathLeft((ushort *)&local_68,(short *)local_48);
        cVar3 = (char)uVar6;
      }
      else {
        uVar7 = LuafvSplitPathRight((short *)&local_68,local_48);
        cVar3 = (char)uVar7;
      }
      if ((cVar3 == '\0') || ((!bVar2 && (local_48[0] == 0)))) {
        if (-1 < iVar5) {
          LuafvLogUtcEvent((uint *)&DAT_14000b230,0x14000b240,0,param_2,(longlong)param_3,2);
        }
        return iVar5;
      }
      if ((uint)uVar1 < (uint)(ushort)local_68) break;
      if (uVar9 < (ushort)local_68) {
        if (bVar2) {
          LuafvSplitRootPathLeft((ushort *)&local_58,(short *)(local_48 + 8));
        }
        uVar6 = LuafvCreateUserStorePath(param_1,0,param_3[0xd]);
        iVar5 = (int)uVar6;
        goto LAB_14001346a;
      }
      if ((ushort)local_68 == uVar9) {
        iVar5 = LuafvCreateStoreRootPath(param_1,0);
        goto LAB_14001346a;
      }
      iVar5 = 0;
LAB_140013484:
      bVar2 = false;
    }
    if (bVar2) {
      LuafvSplitRootPathLeft((ushort *)&local_58,(short *)(local_48 + 8));
    }
    else {
      LuafvSplitPathRight((short *)&local_58,local_48 + 8);
    }
    iVar4 = LuafvCopyFile(param_1,param_2,&local_58,&local_68,0,'\x01');
    if (-1 < iVar4) {
      LuafvUpdateFileTableForFileChange(&local_68,0);
    }
    iVar5 = 0;
    if (iVar4 != -0x3fffffcb) {
      iVar5 = iVar4;
    }
LAB_14001346a:
    if (-1 < iVar5) goto LAB_140013484;
    if (!bVar2) {
      return iVar5;
    }
    if (iVar5 != -0x3fffffc6) {
      return iVar5;
    }
  } while( true );
}



===== LuafvSplitPathRight @ 1400134dc =====

ulonglong LuafvSplitPathRight(short *param_1,ushort *param_2)

{
  short *psVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  ulonglong uVar3;
  ushort uVar4;
  
  uVar4 = *param_2;
  if (uVar4 == 0) {
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  else {
    psVar1 = *(short **)(param_2 + 4);
    for (uVar3 = (ulonglong)(*psVar1 == 0x5c);
        ((uint)uVar3 < (uint)(uVar4 >> 1) && (in_RAX = uVar3, psVar1[uVar3] != 0x5c));
        uVar3 = (ulonglong)((uint)uVar3 + 1)) {
    }
    uVar2 = CONCAT71((int7)(in_RAX >> 8),1);
    *param_1 = *param_1 + (short)uVar3 * 2;
    uVar4 = uVar4 + (short)uVar3 * -2;
    *param_2 = uVar4;
    param_2[1] = uVar4;
    *(short **)(param_2 + 4) = psVar1 + uVar3;
  }
  return uVar2;
}



===== LuafvDereferenceUser @ 140013550 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LuafvDereferenceUser(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  *(undefined8 *)(param_1 + 0x10) = _DAT_fffff78000000014;
  LOCK();
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x38) != 0) {
      ObfDereferenceObjectWithTag(*(longlong *)(param_1 + 0x38),0x6661754c);
    }
    if (*(longlong *)(param_1 + 0x48) != 0) {
      LuafvFreePool(*(longlong *)(param_1 + 0x48));
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(undefined8 *)(param_1 + 0x48) = 0;
    }
    LuafvFreePool(param_1);
  }
  return;
}



===== LuafvTerminateUserStoresForVolume @ 1400135b8 =====

void LuafvTerminateUserStoresForVolume(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  FltAcquirePushLockExclusiveEx(&UserListLock,0);
  puVar6 = UserList;
  do {
    if ((undefined8 **)puVar6 == &UserList) {
      FltReleasePushLockEx(&UserListLock,0);
      return;
    }
    puVar1 = (undefined8 *)*puVar6;
    puVar5 = puVar6 + 4;
    puVar4 = (undefined8 *)*puVar5;
    while (puVar6 = puVar1, puVar4 != puVar5) {
      if (puVar4[4] == param_1) {
        puVar6 = (undefined8 *)*puVar4;
        if (((undefined8 *)puVar6[1] != puVar4) ||
           (puVar2 = (undefined8 *)puVar4[1], (undefined8 *)*puVar2 != puVar4)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        *puVar2 = puVar6;
        puVar6[1] = puVar2;
        LuafvDereferenceUserStore((longlong)puVar4);
        puVar4 = puVar6;
      }
    }
  } while( true );
}



===== AcknowledgePauseRequest @ 14001367c =====

void AcknowledgePauseRequest(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    FltClose();
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  FltAcquirePushLockExclusiveEx(param_1 + 0x108,0);
  *(undefined4 *)(param_1 + 0x340) = 3;
  KeSetEvent(param_1 + 0xa0,0,0);
  FltReleasePushLockEx(param_1 + 0x108,0);
  return;
}



===== CreateUsn @ 14001371c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CreateUsn(longlong param_1)

{
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = 0;
  uStack_20 = 0;
  SynchronousFsControl(param_1,(undefined4 *)0x0,0x900e7,&local_28,0x10,0,0);
  return;
}



===== LuafvTerminateUsn @ 140013778 =====

void LuafvTerminateUsn(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = param_1 + 0x108;
  FltAcquirePushLockExclusiveEx(lVar1);
  if (*(int *)(param_1 + 0x340) == 0) {
    *(undefined4 *)(param_1 + 0x340) = 5;
    FltReleasePushLockEx(lVar1);
  }
  else {
    *(undefined4 *)(param_1 + 0x340) = 4;
    KeSetEvent(param_1 + 0x70,0,0);
    FltReleasePushLockEx(lVar1,0);
    KeWaitForSingleObject(*(undefined8 *)(param_1 + 0x48),0,0,0,0);
    ObfDereferenceObject(*(undefined8 *)(param_1 + 0x48));
  }
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_1 + 0xe8) != 0) {
    LuafvFreePool(*(longlong *)(param_1 + 0xe8));
  }
  return;
}



===== WaitForUsnDeletion @ 14001386c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WaitForUsnDeletion(longlong param_1)

{
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_20 = 2;
  local_28 = 0;
  SynchronousFsControl(param_1,(undefined4 *)0x0,0x900f8,&local_28,0x10,0,0);
  return;
}



===== LuafvUpdateFileTableForFileChange @ 1400138d0 =====

void LuafvUpdateFileTableForFileChange(ulonglong *param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  longlong local_38 [4];
  undefined8 local_18;
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_18 = 0;
  if (param_2 == 0) {
    uVar3 = LuafvFindTableNode((undefined *)0x0,param_1,5,local_38);
    if ((int)uVar3 < 0) {
      return;
    }
    lVar5 = local_38[0];
    if (((char)local_18 == '\0') || (local_18._2_1_ != '\0')) {
      cVar4 = '\0';
      goto LAB_1400139ec;
    }
  }
  else {
    lVar5 = param_2;
  }
  lVar2 = *(longlong *)(lVar5 + 0x20);
  if (*(void **)(lVar2 + 8) == SystemReserved1[0xf]) {
    *(int *)(lVar2 + 0x10) = *(int *)(lVar2 + 0x10) + 1;
  }
  else {
    FltAcquirePushLockExclusiveEx(lVar2,0);
    *(void **)(lVar2 + 8) = SystemReserved1[0xf];
    *(undefined4 *)(lVar2 + 0x10) = 1;
  }
  if (*(void **)(lVar5 + 8) == SystemReserved1[0xf]) {
    *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
  }
  else {
    FltAcquirePushLockExclusiveEx(lVar5,0);
    *(void **)(lVar5 + 8) = SystemReserved1[0xf];
    *(undefined4 *)(lVar5 + 0x10) = 1;
  }
  if ((*(byte *)(lVar5 + 0x1e) & 0x84) == 0) {
    RemoveTableNode(lVar5,'\x01');
  }
  lVar2 = *(longlong *)(lVar5 + 0x20);
  if (*(void **)(lVar2 + 8) == SystemReserved1[0xf]) {
    piVar1 = (int *)(lVar2 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined8 *)(lVar2 + 8) = 0;
      goto LAB_1400139d4;
    }
  }
  else {
LAB_1400139d4:
    FltReleasePushLockEx(lVar2,0);
  }
  if (param_2 != 0) {
    if (*(void **)(lVar5 + 8) == SystemReserved1[0xf]) {
      piVar1 = (int *)(lVar5 + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 != 0) {
        return;
      }
      *(undefined8 *)(lVar5 + 8) = 0;
    }
    FltReleasePushLockEx(lVar5,0);
    return;
  }
  cVar4 = '\x01';
LAB_1400139ec:
  LuafvDereferenceTableNodeEx(lVar5,cVar4,'\0');
  return;
}



===== LuafvSplitPathLeft @ 140013a38 =====

ulonglong LuafvSplitPathLeft(ushort *param_1,short *param_2)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *param_1;
  uVar4 = (uint)(uVar1 >> 1);
  uVar5 = (ulonglong)uVar4;
  if (uVar4 == 0) {
    uVar3 = in_RAX & 0xffffffffffffff00;
  }
  else {
    do {
      if ((int)uVar5 == 0) break;
      uVar5 = (ulonglong)((int)uVar5 - 1);
    } while (*(short *)(*(longlong *)(param_1 + 4) + uVar5 * 2) != 0x5c);
    lVar2 = *(longlong *)(param_1 + 4);
    *param_1 = (short)uVar5 * 2;
    *param_2 = *param_2 + uVar1 + (short)uVar5 * -2;
    param_2[1] = *param_2;
    uVar3 = CONCAT71((uint7)(byte)((ushort)*param_2 >> 8),1);
    *(ulonglong *)(param_2 + 4) = lVar2 + uVar5 * 2;
  }
  return uVar3;
}



===== GetLocalAppDataStorePath @ 140013aa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetLocalAppDataStorePath(undefined8 param_1,short *param_2)

{
  ushort *puVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint uVar7;
  undefined **ppuVar8;
  uint *puVar9;
  short sVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 auStack_e8 [32];
  uint local_c8;
  uint *local_c0;
  uint local_b8 [2];
  ushort local_b0;
  undefined1 auStack_ae [6];
  uint *puStack_a8;
  undefined8 local_a0;
  undefined2 local_98;
  undefined2 uStack_96;
  undefined4 uStack_94;
  uint *puStack_90;
  short local_88 [4];
  longlong lStack_80;
  undefined8 local_78;
  uint *puStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38 [3];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_e8;
  local_68 = 0x30;
  local_a0 = 0;
  local_78 = 0;
  local_b8[0] = 0;
  puStack_70 = (uint *)0x0;
  local_60 = 0;
  local_58 = &HiveListKey;
  local_50 = 0x240;
  _local_b0 = 0;
  puStack_a8 = (uint *)0x0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  lStack_80 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar5 = ZwOpenKey(&local_a0,0x20019,&local_68);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  local_38[1] = (undefined *)param_1;
  local_38[0] = (undefined *)&HiveListValuePrefix;
  ppuVar8 = local_38;
  uStack_94 = 0;
  local_38[2] = &HiveListValueSuffix;
  uVar7 = 0;
  lVar12 = 3;
  do {
    lVar11 = lVar12;
    puVar1 = (ushort *)*ppuVar8;
    ppuVar8 = ppuVar8 + 1;
    uVar7 = uVar7 + *puVar1;
    lVar12 = lVar11 + -1;
  } while (lVar12 != 0);
  if (uVar7 < 0xffff) {
    uStack_96 = (undefined2)uVar7;
    local_98 = 0;
    puStack_90 = LuafvAllocatePool((int)lVar11,uVar7 & 0xffff,'\x02');
    if (puStack_90 == (uint *)0x0) {
      uVar5 = 0xc000009a;
    }
    else {
      uVar7 = 0;
      ppuVar8 = local_38;
      do {
        uVar4 = RtlAppendUnicodeStringToString(&local_98,*ppuVar8);
        uVar5 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          LuafvFreePool((longlong)puStack_90);
          goto LAB_140013bed;
        }
        uVar7 = uVar7 + 1;
        ppuVar8 = ppuVar8 + 1;
      } while (uVar7 < 3);
      local_78 = CONCAT44(uStack_94,CONCAT22(uStack_96,local_98));
      puStack_70 = puStack_90;
    }
LAB_140013bed:
    if (-1 < (int)uVar5) {
      uVar7 = 0xd8;
      while ((7 < uVar7 + 8 &&
             (puVar6 = (uint *)ExAllocatePool2(0x100,uVar7 + 8,0x6661754c), puVar6 != (uint *)0x0)))
      {
        *puVar6 = uVar7;
        *(undefined1 *)(puVar6 + 1) = 0xff;
        FltAcquirePushLockExclusiveEx(&PoolLock,0);
        DAT_14000c2a4 = DAT_14000c2a4 + uVar7;
        FltReleasePushLockEx(&PoolLock,0);
        puVar9 = puVar6 + 2;
        if (puVar9 == (uint *)0x0) break;
        local_c0 = local_b8;
        local_c8 = uVar7;
        uVar7 = ZwQueryValueKey(local_a0,&local_78,2,puVar9);
        uVar5 = (ulonglong)uVar7;
        if (-1 < (int)uVar7) {
          if (puVar6[3] != 1) {
            uVar5 = 0xc0000024;
            goto LAB_140013e32;
          }
          uVar7 = puVar6[4];
          if (((uVar7 & 1) != 0) || (uVar7 < 4)) goto LAB_140013e2d;
          _local_b0 = CONCAT22((short)uVar7,(short)uVar7);
          puStack_a8 = puVar6 + 5;
          cVar2 = RtlPrefixUnicodeString(&DAT_14000c118,&local_b0,1);
          if (cVar2 == '\0') {
            uVar5 = 0xc0000012;
            goto LAB_140013e32;
          }
          uVar3 = local_b0 - DAT_14000c108;
          puStack_a8 = (uint *)((longlong)puStack_a8 + (ulonglong)DAT_14000c108);
          uVar5 = (ulonglong)(uint)(uVar3 >> 1);
          _local_b0 = CONCAT62(CONCAT42(auStack_ae._2_4_,uVar3),uVar3);
          if (uVar3 >> 1 != 0) goto LAB_140013d4b;
          goto LAB_140013e2d;
        }
        if ((uVar7 != 0xc0000023) && (uVar7 != 0x80000005)) goto LAB_140013e32;
        LuafvFreePool((longlong)puVar9);
        uVar7 = local_b8[0];
      }
      uVar5 = 0xc000009a;
    }
  }
  else {
    uVar5 = 0xc0000001;
  }
  goto LAB_140013e48;
  while (uVar5 = (ulonglong)((int)uVar5 - 1), *(short *)((longlong)puStack_a8 + uVar5 * 2) != 0x5c)
  {
LAB_140013d4b:
    if ((int)uVar5 == 0) break;
  }
  lStack_80 = (longlong)puStack_a8 + uVar5 * 2;
  sVar10 = uVar3 + (short)uVar5 * -2;
  _local_b0 = CONCAT62(CONCAT42(auStack_ae._2_4_,uVar3),(short)uVar5 * 2);
  local_88[1] = sVar10;
  local_88[0] = sVar10;
  uVar5 = LuafvSplitPathLeft(&local_b0,local_88);
  if (((((char)uVar5 == '\0') ||
       (uVar5 = LuafvSplitPathLeft(&local_b0,local_88), (char)uVar5 == '\0')) ||
      (cVar2 = RtlPrefixUnicodeString(&MicrosoftWindows,local_88,1), cVar2 == '\0')) ||
     (local_b0 == 0)) {
LAB_140013e2d:
    uVar5 = 0xc0000033;
  }
  else {
    local_b8[0] = (uint)LuafvStoreRoot + (uint)local_b0;
    puVar6 = LuafvAllocatePool(1,local_b8[0],'\x02');
    if (puVar6 == (uint *)0x0) {
      uVar5 = 0xc000009a;
    }
    else {
      *(uint **)(param_2 + 4) = puVar6;
      param_2[1] = (short)local_b8[0];
      RtlCopyUnicodeString(param_2,&local_b0);
      uVar7 = RtlAppendUnicodeStringToString(param_2,&LuafvStoreRoot);
      *param_2 = *param_2 + -2;
      uVar5 = (ulonglong)uVar7;
    }
  }
LAB_140013e32:
  LuafvFreePool((longlong)puVar9);
LAB_140013e48:
  if (puStack_70 != (uint *)0x0) {
    LuafvFreePool((longlong)puStack_70);
  }
  ZwClose(local_a0);
  return uVar5;
}



===== LuafvSplitRootPathLeft @ 140013e98 =====

ulonglong LuafvSplitRootPathLeft(ushort *param_1,short *param_2)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (uint)(*param_1 >> 1);
  if (uVar4 == 0) {
LAB_140013eef:
    uVar1 = in_RAX & 0xffffffffffffff00;
  }
  else {
    if (**(short **)(param_1 + 4) == 0x5c) {
      uVar3 = 1;
      for (uVar5 = 0; uVar5 < 2; uVar5 = uVar5 + 1) {
        if (uVar3 < uVar4) {
          in_RAX = (ulonglong)uVar3;
          psVar2 = *(short **)(param_1 + 4) + in_RAX;
          do {
            if (*psVar2 == 0x5c) break;
            uVar3 = uVar3 + 1;
            psVar2 = psVar2 + 1;
          } while (uVar3 < uVar4);
        }
        uVar3 = uVar3 + 1;
        if (uVar4 <= uVar3) goto LAB_140013eef;
      }
    }
    uVar1 = LuafvSplitPathLeft(param_1,param_2);
  }
  return uVar1;
}



===== LuafvCompleteStoreFileDetails @ 140013f08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvCompleteStoreFileDetails(char param_1,ushort *param_2,ushort *param_3)

{
  ushort *puVar1;
  short sVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  short local_48 [8];
  ushort *local_38 [3];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  puVar1 = param_3 + 8;
  local_38[1] = (ushort *)0x0;
  local_38[2] = (ushort *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  if (param_1 == '\0') {
    iVar3 = 0;
    *(undefined8 *)param_3 = *(undefined8 *)puVar1;
    *(undefined8 *)(param_3 + 4) = *(undefined8 *)(param_3 + 0xc);
  }
  else {
    uVar5 = 1;
    if (1 < *param_2) {
      sVar2 = *(short *)(*(longlong *)(param_3 + 0xc) + -2 + (ulonglong)(*puVar1 >> 1) * 2);
      local_38[1] = (ushort *)&LuafvPathSeparator;
      if (sVar2 == 0x5c) {
        local_38[1] = (ushort *)(undefined *)0x0;
      }
      lVar4 = 0x10;
      if (sVar2 == 0x5c) {
        lVar4 = 8;
      }
      uVar5 = (sVar2 != 0x5c) + 2;
      *(ushort **)((longlong)local_38 + lVar4) = param_2;
    }
    local_38[0] = puVar1;
    iVar3 = LuafvAllocateAndBuildString(local_38,uVar5,&local_58);
    if (-1 < iVar3) {
      LuafvFreePool(*(longlong *)(param_3 + 0xc));
      *(undefined4 *)puVar1 = (undefined4)local_58;
      *(undefined4 *)(param_3 + 10) = local_58._4_4_;
      *(undefined4 *)(param_3 + 0xc) = (undefined4)uStack_50;
      *(undefined4 *)(param_3 + 0xe) = uStack_50._4_4_;
      *(undefined4 *)param_3 = (undefined4)local_58;
      *(undefined4 *)(param_3 + 2) = local_58._4_4_;
      *(undefined4 *)(param_3 + 4) = (undefined4)uStack_50;
      *(undefined4 *)(param_3 + 6) = uStack_50._4_4_;
      RtlInitUnicodeString(local_48,0);
      LuafvSplitRootPathLeft(param_3,local_48);
      *param_3 = *param_3 + 2;
    }
  }
  return iVar3;
}



===== LuafvAllocateAndBuildString @ 140014028 =====

int LuafvAllocateAndBuildString(undefined8 *param_1,uint param_2,undefined8 *param_3)

{
  ushort *puVar1;
  int iVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 local_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  uint *puStack_20;
  
  uStack_24 = 0;
  uVar4 = 0;
  if (param_2 != 0) {
    uVar5 = (ulonglong)param_2;
    puVar3 = param_1;
    do {
      puVar1 = (ushort *)*puVar3;
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 + *puVar1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
    if (0xfffe < uVar4) {
      return -0x3fffffff;
    }
  }
  uStack_26 = (undefined2)uVar4;
  iVar2 = 0;
  local_28 = 0;
  puStack_20 = LuafvAllocatePool(1,uVar4 & 0xffff,'\x02');
  if (puStack_20 == (uint *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    uVar4 = 0;
    if (param_2 != 0) {
      do {
        iVar2 = RtlAppendUnicodeStringToString(&local_28,*param_1);
        if (iVar2 < 0) {
          LuafvFreePool((longlong)puStack_20);
          return iVar2;
        }
        uVar4 = uVar4 + 1;
        param_1 = param_1 + 1;
      } while (uVar4 < param_2);
    }
    *param_3 = CONCAT44(uStack_24,CONCAT22(uStack_26,local_28));
    param_3[1] = puStack_20;
  }
  return iVar2;
}



===== UpdateTableNode @ 140014118 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong UpdateTableNode(longlong param_1,uint *param_2,longlong *param_3,undefined8 param_4)

{
  longlong lVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint *puVar6;
  longlong lVar7;
  uint uVar8;
  uint *puVar9;
  longlong lVar10;
  bool bVar11;
  bool bVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined1 auStackY_1a8 [32];
  undefined1 local_167 [3];
  uint local_164;
  undefined4 local_160 [2];
  uint *local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  int local_140;
  uint *local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  longlong *local_120;
  ulonglong local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined4 uStack_104;
  uint *local_100;
  uint local_f8 [24];
  undefined8 local_98 [10];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_158 = (uint *)0x0;
  local_167[0] = 0;
  local_108 = 0;
  local_130 = 0;
  uStack_128 = (uint *)0x0;
  local_150 = 0;
  uStack_148 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_100 = param_2;
  memset(local_f8,0,0xb0);
  lVar10 = param_1 + 0x80;
  lVar1 = *(longlong *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x100) == 2) {
    uVar4 = GetVolumeRootFileId(param_1,local_98);
    if ((int)uVar4 < 0) {
      return param_1;
    }
    puVar9 = local_f8;
    local_158 = puVar9;
  }
  else {
    puVar9 = (uint *)0x0;
    if (((*(byte *)(lVar1 + 0x1e) & 1) != 0) && ((*(uint *)(lVar1 + 0x18) & 0x410) == 0x10)) {
      if (param_2 == (uint *)0x0) {
        uVar4 = GetFileInformation(lVar1,param_1 + 0x50,local_f8,param_4,&local_158,0,param_3);
        if ((int)uVar4 < 0) {
          return param_1;
        }
        puVar9 = local_158;
      }
      else {
        puVar9 = param_2;
        local_158 = param_2;
      }
    }
    if (puVar9 == (uint *)0x0) {
      if ((*(byte *)(param_1 + 0x1e) & 0x10) != 0) {
        uVar4 = Feature_218091834__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 == 0) {
          RemoveFileIdTableNode(param_1);
        }
        else {
          FltAcquirePushLockExclusiveEx(&DAT_14000c260,0);
          RemoveFileIdTableNode(param_1);
          FltReleasePushLockEx(&DAT_14000c260,0);
        }
      }
      uVar2 = *(ushort *)(param_1 + 0x1e);
      if ((uVar2 & 8) != 0) {
        LuafvDeleteElementTable(*(longlong *)(lVar1 + 0x28),param_1 + 0x60);
        uVar2 = *(ushort *)(param_1 + 0x1e) & 0xfff7;
      }
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(ushort *)(param_1 + 0x1e) = uVar2 & 0xff7e;
      return param_1;
    }
  }
  if (*(uint *)(param_1 + 0x100) < 3) {
    uVar8 = *(uint *)(param_1 + 0x18);
  }
  else {
    local_130._0_4_ = CONCAT22((short)puVar9[0xf],(short)puVar9[0xf]);
    bVar12 = true;
    uStack_128 = puVar9 + 0x1a;
    local_150._0_4_ = CONCAT22((short)(char)puVar9[0x11],(short)(char)puVar9[0x11]);
    uStack_148 = (longlong)puVar9 + 0x46;
    local_164 = puVar9[0xe];
    local_140 = RtlCompareUnicodeString(&local_130,param_1 + 0x50,1);
    bVar11 = local_140 != 0;
    if ((ushort)local_150 == 0) {
      bVar12 = false;
    }
    else if ((*(byte *)(param_1 + 0x1e) & 8) != 0) {
      iVar3 = RtlCompareUnicodeString(lVar10,&local_150,1);
      bVar12 = iVar3 != 0;
    }
    if (local_140 == 0) {
      if (bVar12) {
        uVar13 = (undefined4)local_150;
        uVar14 = local_150._4_4_;
        local_108 = (undefined4)uStack_148;
        uStack_104 = uStack_148._4_4_;
        goto LAB_14001436d;
      }
      local_120 = (longlong *)(lVar1 + 0x28);
    }
    else {
      uVar13 = (undefined4)local_130;
      uVar14 = local_130._4_4_;
      local_108 = (undefined4)uStack_128;
      uStack_104 = uStack_128._4_4_;
LAB_14001436d:
      local_120 = (longlong *)(lVar1 + 0x28);
      local_138 = (uint *)0x0;
      local_160[0] = 0;
      uStack_110 = CONCAT44(uVar14,uVar13);
      lVar5 = LuafvLookupElementTableFull
                        ((longlong *)*local_120,&local_118,(longlong *)&local_138,local_160);
      if (lVar5 != 0) {
        lVar5 = lVar5 - ((ulonglong)(-(uint)((*(byte *)(lVar5 + 0x18) & 7) != 0) & 0x30) + 0x30);
        if (*(void **)(lVar5 + 8) == SystemReserved1[0xf]) {
          *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
        }
        else {
          FltAcquirePushLockExclusiveEx(lVar5);
          *(void **)(lVar5 + 8) = SystemReserved1[0xf];
          *(undefined4 *)(lVar5 + 0x10) = 1;
        }
        if (local_140 == 0) {
          lVar7 = param_1;
        }
        else {
          lVar7 = lVar5;
          lVar5 = param_1;
        }
        lVar5 = ResolveTableNodeConflict(lVar7,lVar5);
        if (lVar5 == param_1) {
          puVar9 = local_158;
        }
        else {
          bVar12 = true;
          lVar10 = lVar5 + 0x80;
          iVar3 = RtlCompareUnicodeString(&local_130,lVar5 + 0x50,1);
          bVar11 = iVar3 != 0;
          if ((ushort)local_150 == 0) {
            bVar12 = false;
          }
          else if ((*(byte *)(lVar5 + 0x1e) & 8) != 0) {
            iVar3 = RtlCompareUnicodeString(lVar10,&local_150,1);
            bVar12 = iVar3 != 0;
          }
          *(ushort *)(lVar5 + 0x1e) = *(ushort *)(lVar5 + 0x1e) | 0x80;
          param_1 = lVar5;
          puVar9 = local_158;
        }
      }
    }
    if (((*(byte *)(param_1 + 0x1e) & 8) != 0) && ((bVar12 || ((ushort)local_150 == 0)))) {
      LuafvDeleteElementTable(*(longlong *)(lVar1 + 0x28),param_1 + 0x60);
      *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xfff7;
    }
    if (bVar11) {
      local_138 = LuafvAllocatePool(1,(uint)(ushort)local_130,'\x12');
      if (local_138 == (uint *)0x0) goto LAB_1400146f3;
      LuafvDeleteElementTable(*local_120,param_1 + 0x30);
      FltAcquirePushLockExclusiveEx(&DAT_14000c280,0);
      if ((*(byte *)(param_1 + 0x1e) & 0x20) != 0) {
        LuafvFreePool(*(longlong *)(param_1 + 0x58));
        *(undefined8 *)(param_1 + 0x58) = 0;
        *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xffdf;
      }
      *(ushort *)(param_1 + 0x52) = (ushort)local_130;
      *(uint **)(param_1 + 0x58) = local_138;
      RtlCopyUnicodeString(param_1 + 0x50,&local_130);
      FltReleasePushLockEx(&DAT_14000c280,0);
      LuafvInsertElementTable
                (*(longlong **)(lVar1 + 0x28),(longlong *)(param_1 + 0x30),(longlong)local_167);
      *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) | 0x20;
      uVar4 = LuafvIsExcludedName((ushort *)&local_130);
      *(byte *)(param_1 + 0x1d) =
           (*(byte *)(param_1 + 0x1d) ^ (byte)uVar4) & 1 ^ *(byte *)(param_1 + 0x1d);
    }
    else {
      RtlCopyUnicodeString(param_1 + 0x50,&local_130);
    }
    if (bVar12) {
      puVar6 = LuafvAllocatePool(1,(uint)(ushort)local_150,'\x12');
      if (puVar6 == (uint *)0x0) goto LAB_1400146f3;
      if ((*(byte *)(param_1 + 0x1e) & 0x40) != 0) {
        LuafvFreePool(*(longlong *)(lVar10 + 8));
        *(undefined8 *)(lVar10 + 8) = 0;
        *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xffbf;
      }
      *(ushort *)(lVar10 + 2) = (ushort)local_150;
      *(uint **)(lVar10 + 8) = puVar6;
      RtlCopyUnicodeString(lVar10,&local_150);
      LuafvInsertElementTable
                (*(longlong **)(lVar1 + 0x28),(longlong *)(param_1 + 0x60),(longlong)local_167);
      *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) | 0x48;
    }
    else if ((*(byte *)(param_1 + 0x1e) & 8) != 0) {
      RtlCopyUnicodeString(lVar10,&local_150);
    }
    uVar8 = local_164;
  }
  if ((*(byte *)(param_1 + 0x1e) & 0x10) == 0) {
LAB_1400146c9:
    *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(puVar9 + 0x18);
    InsertFileIdTableNode(param_1);
  }
  else {
    if (*(longlong *)(param_1 + 0xb0) != *(longlong *)(puVar9 + 0x18)) {
      uVar4 = Feature_218091834__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
        RemoveFileIdTableNode(param_1);
      }
      else {
        FltAcquirePushLockExclusiveEx(&DAT_14000c260,0);
        RemoveFileIdTableNode(param_1);
        FltReleasePushLockEx(&DAT_14000c260,0);
      }
    }
    if ((*(byte *)(param_1 + 0x1e) & 0x10) == 0) goto LAB_1400146c9;
  }
  *(uint *)(param_1 + 0x18) = uVar8;
  *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xff7f | 1;
LAB_1400146f3:
  if ((puVar9 != local_100) && (puVar9 != local_f8)) {
    LuafvFreePool((longlong)puVar9);
  }
  return param_1;
}



===== LuafvFindTableNodeEx @ 14001473c =====

ulonglong LuafvFindTableNodeEx
                    (undefined *param_1,undefined8 *param_2,undefined8 param_3,uint param_4,
                    undefined8 *param_5)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  short *psVar4;
  ushort *puVar5;
  ushort uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint *_Dst;
  uint uVar9;
  undefined2 *puVar10;
  undefined2 *_Dst_00;
  uint uVar11;
  uint uVar12;
  undefined *puVar13;
  undefined8 *puVar14;
  undefined *local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  void *pvStack_38;
  undefined8 local_30;
  
  local_50 = (undefined *)0x0;
  uStack_48 = 0;
  local_40 = 0;
  pvStack_38 = (void *)0x0;
  local_30 = 0;
  uVar8 = LuafvFindTableNode(param_1,(ulonglong *)*param_2,param_4,&local_50);
  if (-1 < (int)uVar8) {
    uVar12 = 1;
    while (((puVar13 = local_50, (char)local_30 != '\0' && (uVar12 < 2)) &&
           ((uVar12 != 1 ||
            ((*(ushort *)param_2[1] < 2 || (**(short **)((ushort *)param_2[1] + 4) != 0x3a))))))) {
      uVar8 = LuafvFindTableNode(local_50,(ulonglong *)param_2[uVar12],param_4,&local_50);
      LuafvDereferenceTableNodeEx((longlong)puVar13,'\0','\0');
      if ((int)uVar8 < 0) {
        return uVar8 & 0xffffffff;
      }
      uVar12 = uVar12 + 1;
    }
    uVar8 = local_40 & 0xffff;
    if ((ushort)local_40 == 0) {
      *(undefined4 *)(param_5 + 2) = 0;
      param_5[3] = 0;
      *param_5 = local_50;
      param_5[1] = local_50;
      *(undefined1 *)(param_5 + 4) = 1;
    }
    else {
      uVar7 = (uint)(ushort)local_40;
      uVar6 = (ushort)local_40 >> 1;
      sVar1 = *(short *)((longlong)pvStack_38 + (ulonglong)uVar6 * 2 + -2);
      for (uVar9 = uVar12; uVar11 = 2, uVar9 < 2; uVar9 = uVar9 + 1) {
        uVar2 = *(ushort *)param_2[uVar9];
        if (uVar2 == 0) {
          uVar11 = uVar9;
          break;
        }
        psVar4 = *(short **)((ushort *)param_2[uVar9] + 4);
        uVar11 = uVar7 + uVar2;
        sVar3 = *psVar4;
        if (sVar1 == 0x5c) {
          uVar7 = uVar11 - 2;
          if (sVar3 != 0x5c) {
            uVar7 = uVar11;
          }
        }
        else {
          uVar7 = uVar11;
          if (sVar3 != 0x5c) {
            uVar7 = uVar11 + 2;
          }
        }
        sVar1 = psVar4[(ulonglong)(uVar2 >> 1) - 1];
      }
      _Dst = LuafvAllocatePool(1,uVar7,'\x02');
      if (_Dst == (uint *)0x0) {
        LuafvDereferenceTableNodeEx((longlong)puVar13,'\0','\0');
        return 0xc000009a;
      }
      *(short *)((longlong)param_5 + 0x12) = (short)uVar7;
      *(short *)(param_5 + 2) = (short)uVar7;
      param_5[3] = _Dst;
      memmove(_Dst,pvStack_38,uVar8);
      puVar10 = (undefined2 *)((longlong)_Dst + uVar8);
      sVar1 = *(short *)((longlong)pvStack_38 + (ulonglong)uVar6 * 2 + -2);
      if (uVar12 < uVar11) {
        uVar8 = (ulonglong)(uVar11 - uVar12);
        puVar14 = param_2 + uVar12;
        do {
          puVar5 = (ushort *)*puVar14;
          if (sVar1 == 0x5c) {
            _Dst_00 = puVar10 + -1;
            if (**(short **)(puVar5 + 4) != 0x5c) {
              _Dst_00 = puVar10;
            }
          }
          else {
            _Dst_00 = puVar10;
            if (**(short **)(puVar5 + 4) != 0x5c) {
              *puVar10 = 0x5c;
              _Dst_00 = puVar10 + 1;
            }
          }
          memmove(_Dst_00,*(void **)(puVar5 + 4),(ulonglong)*puVar5);
          puVar14 = puVar14 + 1;
          puVar10 = (undefined2 *)((longlong)_Dst_00 + (ulonglong)*puVar5);
          sVar1 = *(short *)(*(longlong *)(puVar5 + 4) + -2 + (ulonglong)(*puVar5 >> 1) * 2);
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
        puVar13 = local_50;
      }
      param_5[1] = uStack_48;
      *(char *)(param_5 + 4) = (char)local_30;
      *param_5 = puVar13;
    }
    uVar8 = 0;
  }
  return uVar8;
}



===== LuafvAllocatePool @ 140014a00 =====

uint * LuafvAllocatePool(int param_1,uint param_2,char param_3)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  
  if (param_2 + 8 < 8) {
    return (uint *)0x0;
  }
  cVar4 = -1;
  if (param_3 == '\x02') {
    if (param_2 < 0xb9) {
      uVar5 = 0;
      uVar1 = 0x38;
      do {
        if (param_2 <= uVar1) break;
        uVar5 = uVar5 + 1;
        uVar1 = uVar1 + 0x20;
      } while (uVar5 < 5);
      puVar2 = (uint *)ExAllocateFromPagedLookasideList(&StringLookaside + (ulonglong)uVar5 * 0x80);
      cVar4 = (char)uVar5 + '\x02';
      if (cVar4 != -1) goto LAB_140014a6c;
    }
  }
  else if (param_3 == '\n') {
    if (param_2 < 0x121) {
      puVar2 = (uint *)ExAllocateFromPagedLookasideList(&TableNodeLookaside);
      cVar4 = '\x01';
      goto LAB_140014a6c;
    }
  }
  else if (param_3 == '\x03') {
    puVar2 = (uint *)ExAllocateFromPagedLookasideList(&StoreFileLookaside);
    cVar4 = '\0';
    goto LAB_140014a6c;
  }
  uVar3 = 0x100;
  if (param_1 != 1) {
    uVar3 = 0x40;
  }
  puVar2 = (uint *)ExAllocatePool2(uVar3,param_2 + 8,0x6661754c);
LAB_140014a6c:
  if (puVar2 == (uint *)0x0) {
    return (uint *)0x0;
  }
  *puVar2 = param_2;
  *(char *)(puVar2 + 1) = cVar4;
  FltAcquirePushLockExclusiveEx(&PoolLock,0);
  DAT_14000c2a4 = DAT_14000c2a4 + param_2;
  FltReleasePushLockEx(&PoolLock,0);
  return puVar2 + 2;
}



===== LuafvReadAndCacheSecurityDescriptor @ 140014b70 =====

int LuafvReadAndCacheSecurityDescriptor
              (undefined8 param_1,longlong param_2,ushort *param_3,char param_4,longlong *param_5)

{
  int *piVar1;
  short *psVar2;
  uint *puVar3;
  longlong lVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  uint *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  undefined1 auStack_118 [8];
  undefined1 auStack_110 [24];
  uint local_f8;
  uint *local_f0;
  undefined8 *local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  uint local_98 [2];
  longlong local_90;
  longlong local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  uint local_60 [4];
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_80 = 0;
  uStack_78 = 0;
  local_60[1] = 0;
  local_44 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_98[0] = 0;
  if (*(void **)(param_2 + 8) == SystemReserved1[0xf]) {
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
  }
  else {
    FltAcquirePushLockSharedEx(param_2,0);
  }
  lVar10 = *(longlong *)(param_2 + 0xe8);
  if (lVar10 != 0) {
    LOCK();
    *(int *)(lVar10 + 0x20) = *(int *)(lVar10 + 0x20) + 1;
    UNLOCK();
    puVar12 = auStack_118;
    if (*(void **)(param_2 + 8) == SystemReserved1[0xf]) {
      piVar1 = (int *)(param_2 + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 != 0) goto LAB_140014c19;
      *(undefined8 *)(param_2 + 8) = 0;
      puVar12 = auStack_118;
    }
LAB_140014c08:
    *(undefined8 *)(puVar12 + -8) = 0x140014c14;
    FltReleasePushLockEx(param_2,0);
LAB_140014c19:
    *param_5 = lVar10;
    return 0;
  }
  if (*(void **)(param_2 + 8) == SystemReserved1[0xf]) {
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined8 *)(param_2 + 8) = 0;
      goto LAB_140014c5d;
    }
  }
  else {
LAB_140014c5d:
    FltReleasePushLockEx(param_2,0);
  }
  local_80 = *(undefined8 *)param_3;
  uStack_78 = *(undefined8 *)(param_3 + 4);
  uVar11 = *(ulonglong *)(param_3 + 4);
  local_88 = 0;
  local_90 = 0;
  uVar9 = *param_3 + uVar11;
  if (uVar11 < uVar9) {
    lVar10 = uVar9 - uVar11;
    do {
      psVar2 = (short *)(uVar9 - 2);
      uVar9 = uVar9 - 2;
      lVar10 = lVar10 + -2;
      if (*psVar2 == 0x5c) break;
      if (*psVar2 == 0x3a) {
        local_80 = CONCAT62(local_80._2_6_,(short)(lVar10 >> 1) * 2);
      }
    } while (uVar11 < uVar9);
  }
  local_60[0] = 0x30;
  local_50 = &local_80;
  local_60[2] = 0;
  local_60[3] = 0;
  local_a8 = 0x901;
  local_48 = 0x240;
  local_40 = 0;
  uStack_38 = 0;
  if (param_4 != '\0') {
    local_a8 = 0x905;
  }
  local_a0 = 0;
  local_b0 = 0;
  local_e8 = &local_70;
  local_b8 = 0;
  local_c0 = 0x20;
  local_c8 = 1;
  local_d0 = 7;
  local_d8 = 0x80;
  local_e0 = 0;
  local_f0 = local_60;
  local_f8 = 0x120000;
  iVar7 = FltCreateFileEx2(LuafvDriverData,param_1,&local_88,&local_90);
  if (iVar7 < 0) {
    local_88 = 0;
    goto LAB_140014d6b;
  }
  local_f0 = local_98;
  local_f8 = 0;
  iVar7 = FltQuerySecurityObject(param_1,local_90,0x1f);
  if (iVar7 != -0x3fffffdd) goto LAB_140014d6b;
  uVar13 = local_98[0] + 0x28;
  if (uVar13 < 0x28) {
    iVar7 = -0x3fffff6b;
    goto LAB_140014d6b;
  }
  if ((7 < local_98[0] + 0x30) &&
     (puVar8 = (uint *)ExAllocatePool2(0x100,local_98[0] + 0x30,0x6661754c), puVar8 != (uint *)0x0))
  {
    *puVar8 = uVar13;
    *(undefined1 *)(puVar8 + 1) = 0xff;
    FltAcquirePushLockExclusiveEx(&PoolLock,0);
    DAT_14000c2a4 = DAT_14000c2a4 + uVar13;
    FltReleasePushLockEx(&PoolLock,0);
    puVar15 = puVar8 + 2;
    if (puVar15 != (uint *)0x0) {
      local_f0 = local_98;
      local_f8 = local_98[0];
      iVar7 = FltQuerySecurityObject(param_1,local_90,0x1f,puVar8 + 0xc);
      if (iVar7 < 0) {
        LuafvFreePool((longlong)puVar15);
        goto LAB_140014d6b;
      }
      ObfDereferenceObject(local_90);
      local_90 = 0;
      FltClose(local_88);
      local_88 = 0;
      uVar13 = LuafvCalculateHash((ushort *)(puVar8 + 0xc),local_98[0]);
      lVar10 = (ulonglong)(uVar13 & 0xf) * 0x18;
      puVar3 = (uint *)(&SdTable + (ulonglong)(uVar13 & 0xf) * 3);
      if (*(void **)(param_2 + 8) == SystemReserved1[0xf]) {
        *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
      }
      else {
        FltAcquirePushLockExclusiveEx(param_2,0);
        *(void **)(param_2 + 8) = SystemReserved1[0xf];
        *(undefined4 *)(param_2 + 0x10) = 1;
      }
      puVar12 = auStack_118;
      if (*(longlong *)(param_2 + 0xe8) == 0) {
        FltAcquirePushLockSharedEx(&DAT_14000b8f0 + lVar10,0);
        bVar6 = false;
        while( true ) {
          uVar11 = (ulonglong)local_98[0];
          for (puVar14 = *(uint **)puVar3; puVar14 != puVar3; puVar14 = *(uint **)puVar14) {
            if ((puVar14[7] == uVar13) && (puVar14[6] == (uint)uVar11)) {
              uVar9 = RtlCompareMemory(*(longlong *)(puVar14 + 4),puVar8 + 0xc,uVar11);
              uVar11 = (ulonglong)local_98[0];
              if (uVar9 == uVar11) {
                LuafvFreePool((longlong)puVar15);
                LOCK();
                puVar14[8] = puVar14[8] + 1;
                UNLOCK();
                LOCK();
                puVar14[8] = puVar14[8] + 1;
                UNLOCK();
                puVar15 = puVar14;
                goto LAB_140014f6f;
              }
            }
          }
          if (bVar6) break;
          FltReleasePushLockEx(&DAT_14000b8f0 + lVar10,0);
          FltAcquirePushLockExclusiveEx(&DAT_14000b8f0 + lVar10,0);
          bVar6 = true;
        }
        puVar8[10] = 2;
        puVar8[9] = uVar13;
        puVar8[8] = local_98[0];
        *(uint **)(puVar8 + 6) = puVar8 + 0xc;
        lVar4 = *(longlong *)puVar3;
        if (*(uint **)(lVar4 + 8) == puVar3) {
          *(longlong *)puVar15 = lVar4;
          *(uint **)(puVar8 + 4) = puVar3;
          *(uint **)(lVar4 + 8) = puVar15;
          *(uint **)puVar3 = puVar15;
LAB_140014f6f:
          FltReleasePushLockEx(&DAT_14000b8f0 + lVar10,0);
          *(uint **)(param_2 + 0xe8) = puVar15;
          if (*(void **)(param_2 + 8) == SystemReserved1[0xf]) {
            piVar1 = (int *)(param_2 + 0x10);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              *(undefined8 *)(param_2 + 8) = 0;
              goto LAB_140014fa5;
            }
          }
          else {
LAB_140014fa5:
            FltReleasePushLockEx(param_2,0);
          }
          iVar7 = 0;
          *param_5 = (longlong)puVar15;
          goto LAB_140014d6b;
        }
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar12 = auStack_110;
      }
      *(undefined8 *)(puVar12 + -8) = 0x140015021;
      LuafvFreePool((longlong)puVar15);
      lVar10 = *(longlong *)(param_2 + 0xe8);
      LOCK();
      *(int *)(lVar10 + 0x20) = *(int *)(lVar10 + 0x20) + 1;
      UNLOCK();
      if (*(void **)(param_2 + 8) == SystemReserved1[0xf]) {
        piVar1 = (int *)(param_2 + 0x10);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 != 0) goto LAB_140014c19;
        *(undefined8 *)(param_2 + 8) = 0;
      }
      goto LAB_140014c08;
    }
  }
  iVar7 = -0x3fffff66;
LAB_140014d6b:
  if (local_90 != 0) {
    ObfDereferenceObject();
  }
  if (local_88 != 0) {
    FltClose();
  }
  return iVar7;
}



===== LuafvFindTableNode @ 1400150f0 =====

ulonglong LuafvFindTableNode(undefined *param_1,ulonglong *param_2,uint param_3,undefined8 *param_4)

{
  int *piVar1;
  int iVar2;
  uint6 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined *puVar9;
  ulonglong uVar10;
  uint *puVar11;
  longlong lVar12;
  short *psVar13;
  short sVar14;
  undefined1 uVar15;
  short *psVar16;
  ulonglong uVar17;
  uint *puVar18;
  ushort uVar19;
  short sVar20;
  ulonglong uVar21;
  ulonglong *puVar22;
  undefined8 *puVar23;
  uint *puVar24;
  undefined *puVar25;
  bool bVar26;
  undefined *local_res8;
  byte local_res10;
  undefined1 local_c7;
  undefined8 local_b8;
  short *psStack_b0;
  longlong local_a8;
  longlong local_a0;
  undefined *local_98 [2];
  undefined8 local_88;
  short *psStack_80;
  ulonglong local_78;
  short *psStack_70;
  ulonglong local_68;
  ulonglong uStack_60;
  short *local_58;
  
  local_58 = (short *)((ulonglong)local_58 & 0xffffffff00000000);
  local_98[0] = (undefined *)0x0;
  local_a8 = 0;
  local_a0 = 0;
  puVar24 = (uint *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_88 = 0;
  psStack_80 = (short *)0x0;
  puVar23 = param_4;
  if (param_1 == (undefined *)0x0) {
    puVar7 = (undefined *)0x0;
    param_1 = &DAT_14000c128;
LAB_140015152:
    local_res8 = param_1;
  }
  else {
    puVar7 = *(undefined **)(param_1 + 0x20);
    local_res8 = param_1;
    if (puVar7 != (undefined *)0x0) {
      if (*(void **)(puVar7 + 8) == SystemReserved1[0xf]) {
        *(int *)(puVar7 + 0x10) = *(int *)(puVar7 + 0x10) + 1;
      }
      else {
        FltAcquirePushLockExclusiveEx(puVar7,0);
        *(void **)(puVar7 + 8) = SystemReserved1[0xf];
        *(undefined4 *)(puVar7 + 0x10) = 1;
      }
      goto LAB_140015152;
    }
  }
  if (*(void **)(local_res8 + 8) == SystemReserved1[0xf]) {
    *(int *)(local_res8 + 0x10) = *(int *)(local_res8 + 0x10) + 1;
  }
  else {
    FltAcquirePushLockExclusiveEx(local_res8,0);
    *(void **)(local_res8 + 8) = SystemReserved1[0xf];
    *(undefined4 *)(local_res8 + 0x10) = 1;
  }
  local_b8 = *param_2;
  psVar16 = (short *)param_2[1];
  local_res10 = 0;
  local_c7 = 0;
  uVar21 = local_b8 & 0xffffffff;
  puVar9 = local_res8;
  local_78 = local_b8;
  psStack_70 = psVar16;
  if (((short)local_b8 != 0) && (((short)local_b8 != 2 || (*psVar16 != 0x5c)))) {
    bVar26 = (param_3 & 2) == 0;
    puVar22 = (ulonglong *)CONCAT71((int7)((ulonglong)puVar23 >> 8),bVar26);
    puVar25 = puVar7;
    psStack_b0 = psVar16;
    do {
      puVar18 = (uint *)0x0;
      uVar19 = *(ushort *)(puVar9 + 0x1e);
      local_c7 = 0;
      if (((uVar19 & 1) == 0) && ((param_3 & 8) != 0)) {
        uVar19 = uVar19 | 0x80;
        *(ushort *)(puVar9 + 0x1e) = uVar19;
      }
      local_res10 = 0;
      puVar7 = puVar9;
      if (((byte)puVar22 & (uVar19 >> 7 & 1) != 0) != 0) {
        puVar7 = (undefined *)UpdateTableNode((longlong)puVar9,(uint *)0x0,&local_a8,puVar22);
        puVar22 = (ulonglong *)(ulonglong)bVar26;
        local_res10 = ~((byte)*(ushort *)(puVar7 + 0x1e) >> 7) & 1;
        if ((*(ushort *)(puVar7 + 0x1e) & 1) != 0) {
          local_78 = local_b8;
          psStack_70 = psStack_b0;
          local_res8 = puVar7;
        }
      }
      if (*psVar16 == 0x5c) {
        psVar16 = psVar16 + 1;
        uVar19 = (short)uVar21 - 2;
        uVar21 = (ulonglong)uVar19;
        local_b8 = CONCAT62(local_b8._2_6_,uVar19);
        psStack_b0 = psVar16;
      }
      psVar13 = psStack_b0;
      sVar20 = (short)uVar21;
      local_b8._0_4_ = CONCAT22(sVar20,(undefined2)local_b8);
      sVar14 = 0;
      psStack_80 = psStack_b0;
      local_88._2_6_ = (uint6)(local_b8 >> 0x10);
      uVar3 = local_88._2_6_;
      local_88 = (ulonglong)local_88._2_6_ << 0x10;
      if (sVar20 != 0) {
        if (*psVar16 == 0x5c) {
          puVar11 = (uint *)0x1;
LAB_14001525b:
          uVar5 = (uint)puVar11;
          while (uVar5 < (uint)((uVar21 & 0xffff) >> 1)) {
            uVar5 = (uint)puVar11;
            if ((psVar16[(longlong)puVar11] == 0x5c) || (psVar16[(longlong)puVar11] == 0x3a)) break;
            uVar5 = uVar5 + 1;
            puVar11 = (uint *)(ulonglong)uVar5;
          }
        }
        else {
          puVar11 = puVar18;
          if (*psVar16 != 0x3a) goto LAB_14001525b;
          uVar5 = (uint)((uVar21 & 0xffff) >> 1);
        }
        sVar14 = (short)uVar5 * 2;
        uVar19 = sVar20 + (short)uVar5 * -2;
        uVar21 = (ulonglong)uVar19;
        local_88 = CONCAT62(uVar3,sVar14);
        psVar16 = psVar16 + uVar5;
        local_b8._0_4_ = CONCAT22(uVar19,uVar19);
        psStack_b0 = psVar16;
      }
      local_88._0_4_ = CONCAT22(sVar14,(undefined2)local_88);
      puVar9 = puVar7;
      if ((sVar14 == 0) || (((short)uVar21 == 2 && (*psVar16 == 0x3a)))) goto LAB_140015385;
      if ((*(longlong *)(puVar7 + 0x28) == 0) ||
         (((byte)puVar22 & (*(ushort *)(puVar7 + 0x1e) & 1) == 0) != 0)) {
        puVar24 = puVar18;
      }
      else {
        uStack_60 = local_88;
        local_58 = psVar13;
        puVar23 = *(undefined8 **)(puVar7 + 0x28);
        if (*(int *)(puVar23 + 2) == 0) {
          puVar18 = (uint *)0x0;
        }
        else {
          iVar2 = *(int *)((longlong)puVar23 + 0x14);
          puVar24 = (uint *)*puVar23;
          while( true ) {
            while( true ) {
              if (iVar2 == 0) {
                iVar6 = RtlCompareUnicodeString(&uStack_60,puVar24 + 8,1);
                lVar12 = (longlong)iVar6;
              }
              else {
                lVar12 = uStack_60 - *(longlong *)(puVar24 + 8);
                if (lVar12 == 0) {
                  lVar12 = (local_68 & 0xfffffffffffffff8) -
                           (*(ulonglong *)(puVar24 + 6) & 0xfffffffffffffff8);
                }
              }
              if (lVar12 < 0) break;
              if (lVar12 < 1) {
                puVar18 = (uint *)0x1;
                uVar8 = RtlSplay(puVar24);
                *puVar23 = uVar8;
                if (puVar24 == (uint *)0x0) goto LAB_1400152cd;
                lVar12 = 0x30;
                if ((puVar24[6] & 7) != 0) {
                  lVar12 = 0x60;
                }
                puVar9 = (undefined *)((longlong)puVar24 - lVar12);
                local_98[0] = puVar9;
                if (*(void **)(puVar9 + 8) == SystemReserved1[0xf]) {
                  *(int *)(puVar9 + 0x10) = *(int *)(puVar9 + 0x10) + 1;
                }
                else {
                  FltAcquirePushLockExclusiveEx(puVar9,0);
                  *(void **)(puVar9 + 8) = SystemReserved1[0xf];
                  *(undefined4 *)(puVar9 + 0x10) = 1;
                }
                uVar21 = local_b8 & 0xffff;
                psVar16 = psStack_b0;
                goto LAB_14001560e;
              }
              if (*(uint **)(puVar24 + 4) == (uint *)0x0) {
                puVar18 = (uint *)0x3;
                goto LAB_1400152cd;
              }
              puVar24 = *(uint **)(puVar24 + 4);
            }
            if (*(uint **)(puVar24 + 2) == (uint *)0x0) break;
            puVar24 = *(uint **)(puVar24 + 2);
          }
          puVar18 = (uint *)0x2;
        }
      }
LAB_1400152cd:
      if (((param_3 & 1) != 0) ||
         ((((param_3 & 2) == 0 &&
           ((((((param_3 & 4) == 0 && (puVar7[0x1c] != 0)) && ((puVar7[0x1c] & 8) == 0)) ||
             (((puVar7[0x1e] & 1) == 0 || ((*(uint *)(puVar7 + 0x18) & 0x10) == 0)))) ||
            ((*(uint *)(puVar7 + 0x18) >> 10 & 1) != 0)))) ||
          (cVar4 = FsRtlDoesNameContainWildCards(&local_88), cVar4 != '\0')))) {
        uVar15 = 0;
        puVar7 = puVar25;
        goto LAB_1400152df;
      }
      puVar22 = &local_88;
      uVar10 = CreateTableNode((longlong)puVar7,puVar24,(int)puVar18,puVar22,(longlong *)local_98,
                               local_a8,&local_a0);
      uVar17 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) goto LAB_14001538a;
      local_c7 = 1;
LAB_14001560e:
      if (puVar25 != (undefined *)0x0) {
        if (*(void **)(puVar25 + 8) == SystemReserved1[0xf]) {
          piVar1 = (int *)(puVar25 + 0x10);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(undefined8 *)(puVar25 + 8) = 0;
            FltReleasePushLockEx(puVar25,0);
            uVar21 = local_b8 & 0xffff;
            psVar16 = psStack_b0;
            goto LAB_140015655;
          }
        }
        else {
          FltReleasePushLockEx(puVar25,0);
        }
        uVar21 = local_b8 & 0xffff;
        psVar16 = psStack_b0;
      }
LAB_140015655:
      puVar9 = local_98[0];
      if (local_a8 != 0) {
        if (LuafvDriverData == 0) {
          ZwClose(local_a8);
        }
        else {
          FltClose();
        }
      }
      local_a8 = local_a0;
      local_a0 = 0;
      if ((puVar9[0x1e] & 1) != 0) {
        local_78 = local_b8;
        psStack_70 = psStack_b0;
        local_res8 = puVar9;
      }
      if (((short)uVar21 == 0) || ((short)uVar21 == 2)) goto LAB_1400156f6;
      puVar25 = puVar7;
      if (*psVar16 == 0x3a) goto LAB_14001576a;
      puVar22 = (ulonglong *)(ulonglong)bVar26;
    } while( true );
  }
  uVar15 = 1;
  goto LAB_1400152e7;
LAB_14001576a:
  psVar13 = (short *)((uVar21 & 0xffff) + (longlong)psVar16);
  do {
    psVar16 = psVar16 + 1;
    if (psVar13 <= psVar16) goto LAB_1400156f6;
  } while (*psVar16 != 0x5c);
LAB_140015385:
  uVar17 = 0xc0000033;
  goto LAB_14001538a;
LAB_1400156f6:
  uVar19 = *(ushort *)(puVar9 + 0x1e);
  uVar15 = 1;
  if ((param_3 & 8) != 0 && (uVar19 & 1) == 0) {
    uVar19 = uVar19 | 0x80;
    *(ushort *)(puVar9 + 0x1e) = uVar19;
  }
  local_res10 = 0;
  if ((param_3 & 2) == 0 && (uVar19 >> 7 & 1) != 0) {
    puVar9 = (undefined *)UpdateTableNode((longlong)puVar9,(uint *)0x0,&local_a8,puVar22);
    if ((*(ushort *)(puVar9 + 0x1e) & 1) != 0) {
      local_78 = local_b8;
      psStack_70 = psStack_b0;
      local_res8 = puVar9;
    }
  }
LAB_1400152df:
LAB_1400152e7:
  uVar17 = 0;
  param_4[1] = local_res8;
  *(undefined1 *)((longlong)param_4 + 0x21) = local_c7;
  *param_4 = puVar9;
  param_4[2] = local_78;
  param_4[3] = psStack_70;
  *(undefined1 *)(param_4 + 4) = uVar15;
  *(byte *)((longlong)param_4 + 0x22) = local_res10;
  LOCK();
  *(int *)(puVar9 + 0x14) = *(int *)(puVar9 + 0x14) + 1;
  UNLOCK();
  puVar25 = puVar7;
LAB_14001538a:
  if (*(void **)(puVar9 + 8) == SystemReserved1[0xf]) {
    piVar1 = (int *)(puVar9 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined8 *)(puVar9 + 8) = 0;
      FltReleasePushLockEx(puVar9,0);
    }
  }
  else {
    FltReleasePushLockEx(puVar9,0);
  }
  if (puVar25 != (undefined *)0x0) {
    if (*(void **)(puVar25 + 8) == SystemReserved1[0xf]) {
      piVar1 = (int *)(puVar25 + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 != 0) goto LAB_1400153f2;
      *(undefined8 *)(puVar25 + 8) = 0;
    }
    FltReleasePushLockEx(puVar25,0);
  }
LAB_1400153f2:
  if (local_a0 != 0) {
    if (LuafvDriverData == 0) {
      ZwClose();
    }
    else {
      FltClose();
    }
  }
  if (local_a8 != 0) {
    if (LuafvDriverData == 0) {
      ZwClose();
    }
    else {
      FltClose();
    }
  }
  return uVar17;
}



===== CreateTableNode @ 14001588c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CreateTableNode(longlong param_1,uint *param_2,undefined4 param_3,ulonglong *param_4,
                         longlong *param_5,longlong param_6,longlong *param_7)

{
  longlong *plVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint *puVar6;
  undefined8 uVar7;
  ushort *puVar8;
  ulonglong uVar9;
  uint *_Dst;
  uint *puVar10;
  undefined1 uVar11;
  ulonglong *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  ushort uVar15;
  undefined1 auStackY_1a8 [32];
  undefined1 local_168 [4];
  uint local_164;
  uint *local_160;
  undefined8 local_158;
  uint *puStack_150;
  uint *local_148;
  undefined4 local_140 [2];
  ushort local_138 [4];
  longlong lStack_130;
  longlong *local_128;
  longlong local_120 [3];
  undefined4 local_108;
  ushort uStack_104;
  ushort uStack_102;
  uint local_f8 [44];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_128 = param_5;
  local_160 = (uint *)CONCAT44(local_160._4_4_,param_3);
  local_108 = 0;
  local_168[0] = 0;
  local_138[0] = 0;
  local_138[1] = 0;
  local_138[2] = 0;
  local_138[3] = 0;
  lStack_130 = 0;
  local_120[1] = 0;
  local_120[2] = 0;
  puVar12 = param_4;
  memset(local_f8,0,0xb0);
  puVar10 = (uint *)0x0;
  local_158 = *param_4;
  puStack_150 = (uint *)param_4[1];
  local_148 = (uint *)0x0;
  uVar11 = 1;
  if (*(uint *)(param_1 + 0x100) < 2) {
    local_164 = 0x10;
LAB_140015a3f:
    uVar15 = 1;
    goto LAB_140015a42;
  }
  if (((*(byte *)(param_1 + 0x1e) & 1) == 0) || ((*(uint *)(param_1 + 0x18) & 0x410) != 0x10)) {
LAB_140015df3:
    uVar15 = 0;
    local_164 = 0;
    puVar10 = local_148;
LAB_140015a42:
    if (*(longlong *)(param_1 + 0x28) == 0) {
      uVar4 = CreateChildTable(param_1);
      uVar9 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) goto LAB_140015a73;
    }
    uVar14 = (uint)local_138[0] + (ushort)local_158 + 0x108;
    if (7 < uVar14 + 8) {
      if (uVar14 < 0x121) {
        puVar6 = (uint *)ExAllocateFromPagedLookasideList(&TableNodeLookaside);
      }
      else {
        puVar6 = (uint *)ExAllocatePool2(0x100,uVar14 + 8,0x6661754c);
        uVar11 = 0xff;
      }
      if (puVar6 != (uint *)0x0) {
        *puVar6 = uVar14;
        *(undefined1 *)(puVar6 + 1) = uVar11;
        FltAcquirePushLockExclusiveEx(&PoolLock);
        DAT_14000c2a4 = DAT_14000c2a4 + uVar14;
        FltReleasePushLockEx(&PoolLock);
        _Dst = puVar6 + 2;
        if (_Dst != (uint *)0x0) {
          memset(_Dst,0,0x108);
          ExInitializePushLock(_Dst);
          *(byte *)(puVar6 + 0x14) = (byte)puVar6[0x14] & 0xf8;
          puVar6[7] = 1;
          *(byte *)(puVar6 + 0x20) = (byte)puVar6[0x20] & 0xf9 | 1;
          puVar6[8] = local_164;
          bVar2 = (byte)puVar6[0x2c] & 0xfa | 2;
          *(byte *)(puVar6 + 0x2c) = bVar2;
          *(ushort *)((longlong)puVar6 + 0x26) =
               *(ushort *)((longlong)puVar6 + 0x26) & 0xfffe | uVar15;
          *(undefined1 *)(puVar6 + 9) = *(undefined1 *)(param_1 + 0x1c);
          *(longlong *)(puVar6 + 10) = param_1;
          *(ulonglong *)(puVar6 + 0x2c) =
               ((ulonglong)bVar2 ^ *(ulonglong *)(param_1 + 0xa8)) & 0xfffffffffffffff8 ^
               (ulonglong)bVar2;
          puVar6[0x42] = *(int *)(param_1 + 0x100) + 1;
          *(undefined8 *)(puVar6 + 0x3a) = _DAT_fffff78000000014;
          if ((local_164 & 0x10) != 0) {
            *(byte *)(puVar6 + 9) = (byte)puVar6[9] & 0xf7;
          }
          if (*(void **)(puVar6 + 4) == SystemReserved1[0xf]) {
            puVar6[6] = puVar6[6] + 1;
          }
          else {
            FltAcquirePushLockExclusiveEx(_Dst,0);
            *(void **)(puVar6 + 4) = SystemReserved1[0xf];
            puVar6[6] = 1;
          }
          uVar4 = LuafvIsExcludedName((ushort *)&local_158);
          *(byte *)((longlong)puVar6 + 0x25) =
               (*(byte *)((longlong)puVar6 + 0x25) ^ (byte)uVar4) & 1 ^
               *(byte *)((longlong)puVar6 + 0x25);
          if (*(longlong *)(param_1 + 0xd0) != 0) {
            FltAcquirePushLockExclusiveEx(&DAT_14000c278,0);
            RemoveMruListNode(param_1);
            FltReleasePushLockEx(&DAT_14000c278,0);
          }
          *(ushort *)((longlong)puVar6 + 0x5a) = (ushort)local_158;
          *(uint **)(puVar6 + 0x18) = puVar6 + 0x44;
          RtlCopyUnicodeString(puVar6 + 0x16,&local_158);
          plVar1 = *(longlong **)(param_1 + 0x28);
          if (param_2 == (uint *)0x0) {
            LuafvInsertElementTable(plVar1,(longlong *)(puVar6 + 0xe),(longlong)local_168);
          }
          else {
            if ((int)local_160 != 1) {
              puVar10 = puVar6 + 0xe;
              *(uint **)puVar10 = puVar10;
              puVar6[0x10] = 0;
              puVar6[0x11] = 0;
              puVar6[0x12] = 0;
              puVar6[0x13] = 0;
              *(int *)(plVar1 + 2) = (int)plVar1[2] + 1;
              if ((int)local_160 == 0) {
                *plVar1 = (longlong)puVar10;
                param_2 = puVar10;
              }
              else {
                if ((int)local_160 == 2) {
                  *(uint **)(param_2 + 2) = puVar10;
                }
                else {
                  *(uint **)(param_2 + 4) = puVar10;
                }
                *(uint **)puVar10 = param_2;
                param_2 = puVar10;
              }
            }
            lVar5 = RtlSplay(param_2);
            *plVar1 = lVar5;
          }
          LOCK();
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          UNLOCK();
          if (local_138[0] != 0) {
            *(ushort *)((longlong)puVar6 + 0x8a) = local_138[0];
            *(ulonglong *)(puVar6 + 0x24) = (local_158 & 0xffff) + *(longlong *)(puVar6 + 0x18);
            RtlCopyUnicodeString(puVar6 + 0x22,local_138);
            plVar1 = *(longlong **)(param_1 + 0x28);
            puVar10 = puVar6 + 0x1a;
            local_160 = (uint *)0x0;
            uVar7 = FindNodeOrParent(plVar1,(ulonglong *)(puVar6 + 0x20),(longlong *)&local_160);
            iVar3 = (int)uVar7;
            if (iVar3 == 1) {
              puVar10 = local_160;
            }
            else {
              *(uint **)puVar10 = puVar10;
              puVar6[0x1c] = 0;
              puVar6[0x1d] = 0;
              puVar6[0x1e] = 0;
              puVar6[0x1f] = 0;
              *(int *)(plVar1 + 2) = (int)plVar1[2] + 1;
              if (iVar3 == 0) {
                *plVar1 = (longlong)puVar10;
              }
              else {
                if (iVar3 == 2) {
                  *(uint **)(local_160 + 2) = puVar10;
                }
                else {
                  *(uint **)(local_160 + 4) = puVar10;
                }
                *(uint **)puVar10 = local_160;
              }
            }
            lVar5 = RtlSplay(puVar10);
            *plVar1 = lVar5;
            *(ushort *)((longlong)puVar6 + 0x26) = *(ushort *)((longlong)puVar6 + 0x26) | 8;
          }
          puVar10 = local_148;
          if (local_148 != (uint *)0x0) {
            *(undefined8 *)(puVar6 + 0x2e) = *(undefined8 *)(local_148 + 0x18);
            InsertFileIdTableNode((longlong)_Dst);
          }
          *local_128 = (longlong)_Dst;
          LuafvRunScavenger();
          goto LAB_140015d9f;
        }
      }
    }
    uVar9 = 0xc000009a;
  }
  else {
    uVar4 = GetFileInformation(param_1,param_4,local_f8,puVar12,&local_148,param_6,param_7);
    puVar10 = local_148;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    if (local_148 == (uint *)0x0) goto LAB_140015df3;
    local_158._0_4_ = CONCAT22((short)local_148[0xf],(short)local_148[0xf]);
    puStack_150 = local_148 + 0x1a;
    local_138[1] = (short)(char)local_148[0x11];
    local_138[0] = (short)(char)local_148[0x11];
    lStack_130 = (longlong)local_148 + 0x46;
    local_164 = local_148[0xe];
    if ((*(longlong *)(param_1 + 0x28) == 0) ||
       (*(int *)(*(longlong *)(param_1 + 0x28) + 0x10) == 0)) {
      uVar15 = 1;
      goto LAB_140015a42;
    }
    iVar3 = RtlCompareUnicodeString(&local_158,param_4,1);
    puVar8 = (ushort *)&local_158;
    if (iVar3 == 0) {
      puVar8 = local_138;
    }
    local_120[2] = *(longlong *)puVar8;
    local_108 = *(undefined4 *)(puVar8 + 4);
    uStack_104 = puVar8[6];
    uStack_102 = puVar8[7];
    if (*puVar8 == 0) {
LAB_140015a32:
      uVar15 = 1;
      if (iVar3 == 0) goto LAB_140015a3f;
      param_2 = (uint *)0x0;
      goto LAB_140015a42;
    }
    puVar13 = local_140;
    local_120[0] = 0;
    local_140[0] = 0;
    lVar5 = LuafvLookupElementTableFull
                      (*(longlong **)(param_1 + 0x28),(ulonglong *)(local_120 + 1),local_120,puVar13
                      );
    if (lVar5 == 0) goto LAB_140015a32;
    lVar5 = lVar5 - ((ulonglong)(-(uint)((*(byte *)(lVar5 + 0x18) & 7) != 0) & 0x30) + 0x30);
    if (*(void **)(lVar5 + 8) == SystemReserved1[0xf]) {
      *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
    }
    else {
      FltAcquirePushLockExclusiveEx(lVar5);
      *(void **)(lVar5 + 8) = SystemReserved1[0xf];
      *(undefined4 *)(lVar5 + 0x10) = 1;
    }
    *(ushort *)(lVar5 + 0x1e) = *(ushort *)(lVar5 + 0x1e) | 0x80;
    lVar5 = UpdateTableNode(lVar5,(uint *)0x0,param_7,puVar13);
    puVar10 = local_148;
    if ((*(ushort *)(lVar5 + 0x1e) & 1) == 0) {
      *(ushort *)(lVar5 + 0x1e) = *(ushort *)(lVar5 + 0x1e) | 0x80;
      lVar5 = UpdateTableNode(lVar5,local_148,(longlong *)0x0,puVar13);
    }
    *local_128 = lVar5;
LAB_140015d9f:
    uVar9 = 0;
  }
LAB_140015a73:
  if ((puVar10 != (uint *)0x0) && (puVar10 != local_f8)) {
    LuafvFreePool((longlong)puVar10);
  }
  return uVar9;
}



===== LuafvIsExcludedName @ 140015f10 =====

ulonglong LuafvIsExcludedName(ushort *param_1)

{
  short sVar1;
  short *psVar2;
  short *in_RAX;
  ulonglong uVar3;
  short *psVar4;
  short *psVar5;
  uint uVar6;
  short *psVar7;
  
  if ((DAT_14000c0fd != '\0') && (in_RAX = (short *)(ulonglong)*param_1, *param_1 != 0)) {
    psVar2 = *(short **)(param_1 + 4);
    psVar7 = (short *)((longlong)psVar2 + (longlong)in_RAX);
    in_RAX = psVar7 + -1;
    psVar4 = (short *)0x0;
    if (psVar2 <= in_RAX) {
      do {
        sVar1 = *in_RAX;
        psVar5 = psVar4;
        if (sVar1 == 0x2e) {
          psVar5 = in_RAX;
          if (psVar4 != (short *)0x0) {
            psVar5 = psVar4;
          }
        }
        else if (sVar1 == 0x3a) {
          psVar5 = (short *)0x0;
          psVar7 = in_RAX;
        }
        else if (sVar1 == 0x5c) break;
        in_RAX = in_RAX + -1;
        psVar4 = psVar5;
      } while (psVar2 <= in_RAX);
      if (psVar5 != (short *)0x0) {
        uVar6 = (uint)((longlong)psVar7 - (longlong)(psVar5 + 1) >> 1);
        if (uVar6 != 0) {
          uVar3 = IsExcludedExtension(psVar5 + 1,uVar6,(undefined1 *)0x0,(int *)0x0);
          return uVar3;
        }
      }
    }
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== IsExcludedExtension @ 140015fac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong IsExcludedExtension(undefined2 *param_1,uint param_2,undefined1 *param_3,int *param_4)

{
  ulonglong uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  ulonglong local_38;
  undefined8 local_30;
  undefined2 *puStack_28;
  
  local_30 = 0;
  puStack_28 = (undefined2 *)0x0;
  puVar5 = (undefined1 *)register0x00000020;
  if (param_2 < 5) {
    local_38 = 0;
    uVar6 = 0;
    if (param_2 != 0) {
      lVar9 = (longlong)&local_38 - (longlong)param_1;
      do {
        puVar5 = (undefined1 *)RtlUpcaseUnicodeChar(*param_1);
        *(short *)(lVar9 + (longlong)param_1) = (short)puVar5;
        param_1 = param_1 + 1;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
      uVar6 = local_38;
    }
    iVar7 = 0;
    iVar8 = DAT_14000c298 + -1;
    while (iVar7 <= iVar8) {
      uVar1 = (longlong)(iVar8 + iVar7) / 2;
      puVar5 = (undefined1 *)(uVar1 & 0xffffffff);
      iVar3 = (int)uVar1;
      uVar1 = *(ulonglong *)(DAT_14000c288 + (longlong)iVar3 * 8);
      if (uVar1 == uVar6) {
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = 1;
          *param_4 = iVar3;
        }
LAB_1400160b7:
        return CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
      }
      if (uVar1 < uVar6) {
        iVar7 = iVar3 + 1;
      }
      else {
        iVar8 = iVar3 + -1;
      }
    }
  }
  else {
    sVar2 = (short)param_2 * 2;
    local_30 = (ulonglong)CONCAT22(sVar2,sVar2);
    iVar7 = DAT_14000c29c + -1;
    iVar8 = 0;
    puStack_28 = param_1;
    while (iVar3 = iVar8, iVar3 <= iVar7) {
      iVar4 = (iVar7 + iVar3) / 2;
      puVar5 = (undefined1 *)
               RtlCompareUnicodeString((longlong)iVar4 * 0x10 + _DAT_14000c290,&local_30,1);
      if ((int)puVar5 == 0) {
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = (char)puVar5;
          *param_4 = iVar4;
        }
        goto LAB_1400160b7;
      }
      iVar8 = iVar4 + 1;
      if (-1 < (int)puVar5) {
        iVar7 = iVar4 + -1;
        iVar8 = iVar3;
      }
    }
  }
  return (ulonglong)puVar5 & 0xffffffffffffff00;
}



===== InsertFileIdTableNode @ 1400160fc =====

void InsertFileIdTableNode(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *local_res8;
  
  FltAcquirePushLockExclusiveEx(&DAT_14000c260,0);
  local_res8 = (longlong *)0x0;
  plVar6 = (longlong *)(param_1 + 0x90);
  uVar5 = FindNodeOrParent((longlong *)&DAT_14000c248,(ulonglong *)(param_1 + 0xa8),
                           (longlong *)&local_res8);
  iVar4 = (int)uVar5;
  if (iVar4 == 1) {
    plVar6 = local_res8;
  }
  else {
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0;
    *plVar6 = (longlong)plVar6;
    DAT_14000c258._0_4_ = (int)DAT_14000c258 + 1;
    if (iVar4 == 0) {
      DAT_14000c248 = plVar6;
    }
    else {
      if (iVar4 == 2) {
        local_res8[1] = (longlong)plVar6;
      }
      else {
        local_res8[2] = (longlong)plVar6;
      }
      *plVar6 = (longlong)local_res8;
    }
  }
  DAT_14000c248 = (longlong *)RtlSplay(plVar6);
  plVar1 = (longlong *)(param_1 + 0xc0);
  if (iVar4 == 1) {
    *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xfdff;
    plVar2 = (longlong *)plVar6[7];
    if ((longlong *)*plVar2 != plVar6 + 6) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar1 = (longlong)(plVar6 + 6);
    *(longlong **)(param_1 + 200) = plVar2;
    *plVar2 = (longlong)plVar1;
    plVar6[7] = (longlong)plVar1;
  }
  else {
    *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) | 0x200;
    *(longlong **)(param_1 + 200) = plVar1;
    *plVar1 = (longlong)plVar1;
  }
  *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) | 0x10;
  FltReleasePushLockEx(&DAT_14000c260,0);
  return;
}



===== GetFileInformation @ 14001622c =====

ulonglong GetFileInformation(longlong param_1,undefined8 param_2,uint *param_3,undefined8 param_4,
                            undefined8 *param_5,longlong param_6,longlong *param_7)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  uint *_Dst;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 in_stack_ffffffffffffff28;
  undefined2 *puVar11;
  undefined4 uVar12;
  undefined8 in_stack_ffffffffffffff30;
  undefined4 uVar13;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 uVar14;
  undefined8 in_stack_ffffffffffffff68;
  undefined4 uVar15;
  longlong local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  
  plVar1 = param_7;
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff28 >> 0x20);
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff30 >> 0x20);
  local_5c = 0;
  local_44 = 0;
  local_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_58 = *param_7;
  if (*param_7 == 0) {
    if (param_6 == 0) {
      if (*(longlong *)(param_1 + 0xf8) == 0) {
        uVar6 = Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline();
        puVar11 = (undefined2 *)(param_1 + 0xf0);
        if ((int)uVar6 == 0) {
          uVar6 = LuafvBuildTableNodeName(param_1,0,(ushort *)0x0,(ushort *)0x0,'\x01',puVar11);
        }
        else {
          uVar6 = LuafvBuildTableNodeName2
                            (param_1,0,(ushort *)0x0,(ushort *)0x0,'\x01','\x01',puVar11);
          uVar12 = (undefined4)((ulonglong)puVar11 >> 0x20);
        }
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      uVar7 = *(undefined4 *)(param_1 + 0xf0);
      uVar8 = *(undefined4 *)(param_1 + 0xf4);
      uVar9 = *(undefined4 *)(param_1 + 0xf8);
      uVar10 = *(undefined4 *)(param_1 + 0xfc);
      param_6 = 0;
    }
    else {
      uVar7 = *(undefined4 *)(param_1 + 0x50);
      uVar8 = *(undefined4 *)(param_1 + 0x54);
      uVar9 = *(undefined4 *)(param_1 + 0x58);
      uVar10 = *(undefined4 *)(param_1 + 0x5c);
    }
    local_80 = CONCAT44(uVar8,uVar7);
    uStack_78 = CONCAT44(uVar10,uVar9);
    local_58 = param_6;
  }
  local_50 = &local_80;
  local_60 = 0x30;
  local_48 = 0x240;
  param_7 = (longlong *)0x0;
  local_40 = 0;
  uStack_38 = 0;
  uVar6 = *(ulonglong *)(param_1 + 0xa8) & 0xfffffffffffffff8;
  if (uVar6 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined8 *)(uVar6 + 0x10);
  }
  if (LuafvDriverData == 0) {
    uVar2 = IoCreateFileEx(&local_88,0x100001,&local_60,&local_70,0,0x80,CONCAT44(uVar12,7),
                           CONCAT44(uVar13,1),0x21,0,0,0,0,0x800,0);
  }
  else {
    uVar2 = FltCreateFileEx2(LuafvDriverData,uVar4,&local_88,&param_7,0x100001,&local_60,&local_70,0
                             ,0x80,CONCAT44(uVar14,7),1,0x21,0,0,CONCAT44(uVar15,0x800),0);
  }
  if (*plVar1 != 0) {
    if (LuafvDriverData == 0) {
      ZwClose();
    }
    else {
      FltClose();
    }
  }
  if ((int)uVar2 < 0) {
    *plVar1 = 0;
    if ((uVar2 != 0xc0000034) && (uVar2 != 0xc000003a)) {
      return (ulonglong)uVar2;
    }
    uVar5 = 0;
  }
  else {
    *plVar1 = local_88;
    uVar2 = 0xb0;
    _Dst = param_3;
    while( true ) {
      if (param_7 == (longlong *)0x0) {
        uVar3 = ZwQueryDirectoryFile(local_88,0,0,0,&local_70,_Dst,uVar2,0x25,1,param_2,1);
      }
      else {
        uVar3 = FltQueryDirectoryFile
                          (*(undefined8 *)(uVar6 + 0x10),param_7,_Dst,uVar2,0x25,1,param_2,1,0);
      }
      uVar5 = (ulonglong)uVar3;
      if ((uVar3 != 0x80000005) && (uVar3 != 0xc0000023)) goto LAB_140016532;
      if (_Dst != param_3) {
        LuafvFreePool((longlong)_Dst);
      }
      uVar2 = uVar2 * 2;
      _Dst = LuafvAllocatePool(1,uVar2,'\x01');
      if (_Dst == (uint *)0x0) break;
      memset(_Dst,0,(ulonglong)uVar2);
    }
    uVar5 = 0xc000009a;
LAB_140016532:
    if (param_7 != (longlong *)0x0) {
      ObfDereferenceObject();
    }
    if (-1 < (int)uVar5) {
      *param_5 = _Dst;
      return uVar5;
    }
    if ((_Dst != param_3) && (_Dst != (uint *)0x0)) {
      LuafvFreePool((longlong)_Dst);
    }
    if ((int)uVar5 == -0x3ffffff1) {
      uVar5 = 0;
    }
  }
  *param_5 = 0;
  return uVar5;
}



===== LuafvInsertElementTable @ 1400165a4 =====

void LuafvInsertElementTable(longlong *param_1,longlong *param_2,longlong param_3)

{
  undefined8 uVar1;
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  uVar1 = FindNodeOrParent(param_1,(ulonglong *)(param_2 + 3),(longlong *)&local_res10);
  LuafvInsertElementTableFull(param_1,param_2,param_3,local_res10,(int)uVar1);
  return;
}



===== FindNodeOrParent @ 140016600 =====

undefined8 FindNodeOrParent(longlong *param_1,ulonglong *param_2,longlong *param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  if ((int)param_1[2] == 0) {
    uVar4 = 0;
  }
  else {
    iVar1 = *(int *)((longlong)param_1 + 0x14);
    lVar5 = *param_1;
    while( true ) {
      while( true ) {
        if (iVar1 == 0) {
          iVar2 = RtlCompareUnicodeString(param_2 + 1,lVar5 + 0x20,1);
          lVar3 = (longlong)iVar2;
        }
        else {
          lVar3 = param_2[1] - *(longlong *)(lVar5 + 0x20);
          if (lVar3 == 0) {
            lVar3 = (*param_2 & 0xfffffffffffffff8) -
                    (*(ulonglong *)(lVar5 + 0x18) & 0xfffffffffffffff8);
          }
        }
        if (lVar3 < 0) break;
        if (lVar3 < 1) {
          uVar4 = 1;
          goto LAB_140016690;
        }
        if (*(longlong *)(lVar5 + 0x10) == 0) {
          uVar4 = 3;
          goto LAB_140016690;
        }
        lVar5 = *(longlong *)(lVar5 + 0x10);
      }
      if (*(longlong *)(lVar5 + 8) == 0) break;
      lVar5 = *(longlong *)(lVar5 + 8);
    }
    uVar4 = 2;
LAB_140016690:
    *param_3 = lVar5;
  }
  return uVar4;
}



===== LuafvInsertElementTableFull @ 1400166cc =====

longlong *
LuafvInsertElementTableFull
          (longlong *param_1,longlong *param_2,longlong param_3,longlong *param_4,int param_5)

{
  longlong lVar1;
  
  if (param_5 == 1) {
    param_2 = param_4;
  }
  else {
    param_2[1] = 0;
    param_2[2] = 0;
    *param_2 = (longlong)param_2;
    *(int *)(param_1 + 2) = (int)param_1[2] + 1;
    if (param_5 == 0) {
      *param_1 = (longlong)param_2;
    }
    else {
      if (param_5 == 2) {
        param_4[1] = (longlong)param_2;
      }
      else {
        param_4[2] = (longlong)param_2;
      }
      *param_2 = (longlong)param_4;
    }
  }
  lVar1 = RtlSplay(param_2);
  *param_1 = lVar1;
  if (param_3 != 0) {
    *(bool *)param_3 = param_5 != 1;
  }
  return param_2;
}



===== RemoveTableNode @ 140016760 =====

void RemoveTableNode(longlong param_1,char param_2)

{
  longlong lVar1;
  ushort uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x28);
  FltAcquirePushLockExclusiveEx(&DAT_14000c260,0);
  FltAcquirePushLockExclusiveEx(&DAT_14000c278,0);
  if (*(longlong **)(param_1 + 0xe8) != (longlong *)0x0) {
    LuafvDereferenceCachedSecurityDescriptor(*(longlong **)(param_1 + 0xe8));
    *(undefined8 *)(param_1 + 0xe8) = 0;
  }
  if ((*(byte *)(param_1 + 0x1e) & 0x10) != 0) {
    RemoveFileIdTableNode(param_1);
  }
  uVar2 = *(ushort *)(param_1 + 0x1e);
  if ((uVar2 & 8) != 0) {
    LuafvDeleteElementTable(lVar1,param_1 + 0x60);
    *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xfff7;
    uVar2 = *(ushort *)(param_1 + 0x1e);
  }
  if (param_2 == '\0') {
    RemoveMruListNode(param_1);
    LuafvDeleteElementTable(lVar1,param_1 + 0x30);
    *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) | 4;
  }
  else if (2 < *(uint *)(param_1 + 0x100)) {
    *(ushort *)(param_1 + 0x1e) = uVar2 | 0x80;
  }
  FltReleasePushLockEx(&DAT_14000c278,0);
  FltReleasePushLockEx(&DAT_14000c260,0);
  return;
}



===== LuafvStreamHandleCleanup @ 140016870 =====

void LuafvStreamHandleCleanup(longlong *param_1)

{
  if (*param_1 != 0) {
    LuafvFreeStoreFile(*param_1);
  }
  return;
}



===== LuafvFreeStoreFile @ 140016890 =====

void LuafvFreeStoreFile(longlong param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x20) != 0) {
    LuafvDereferenceTableNodeEx(*(longlong *)(param_1 + 0x20),'\0','\0');
  }
  if (*(longlong *)(param_1 + 0x50) != 0) {
    LuafvDereferenceTableNodeEx(*(longlong *)(param_1 + 0x50),'\0','\0');
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    LuafvDereferenceUserStore(*(longlong *)(param_1 + 0x68));
  }
  if (*(longlong **)(param_1 + 0x60) != (longlong *)0x0) {
    if (**(longlong **)(param_1 + 0x60) != 0) {
      FltClose();
    }
    if (*(longlong *)(*(longlong *)(param_1 + 0x60) + 0x20) != 0) {
      FltClose();
    }
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 0x10);
    if (lVar1 != 0) {
      LuafvFreePool(lVar1);
    }
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x60) + 0x30);
    if (lVar1 != 0) {
      LuafvFreePool(lVar1);
    }
    LuafvFreePool(*(longlong *)(param_1 + 0x60));
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    LuafvFreePool(*(longlong *)(param_1 + 0x18));
  }
  if (*(longlong *)(param_1 + 0x48) != 0) {
    LuafvFreePool(*(longlong *)(param_1 + 0x48));
  }
  LuafvFreePool(param_1);
  return;
}



===== FreeTableNode @ 140016968 =====

void FreeTableNode(longlong param_1)

{
  if (*(longlong *)(param_1 + 0xf8) != 0) {
    LuafvFreePool(*(longlong *)(param_1 + 0xf8));
  }
  if (((*(byte *)(param_1 + 0x1e) & 0x20) != 0) && (*(longlong *)(param_1 + 0x58) != 0)) {
    LuafvFreePool(*(longlong *)(param_1 + 0x58));
  }
  if (((*(byte *)(param_1 + 0x1e) & 0x40) != 0) && (*(longlong *)(param_1 + 0x88) != 0)) {
    LuafvFreePool(*(longlong *)(param_1 + 0x88));
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    LuafvFreePool(*(longlong *)(param_1 + 0x28));
  }
  LuafvFreePool(param_1);
  return;
}



===== LuafvDereferenceCachedSecurityDescriptor @ 1400169e0 =====

void LuafvDereferenceCachedSecurityDescriptor(longlong *param_1)

{
  uint uVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  
  uVar1 = *(uint *)((longlong)param_1 + 0x1c);
  FltAcquirePushLockExclusiveEx(&DAT_14000b8f0 + (ulonglong)(uVar1 & 0xf) * 0x18,0);
  LOCK();
  plVar2 = param_1 + 4;
  lVar4 = *plVar2;
  *(int *)plVar2 = (int)*plVar2 + -1;
  UNLOCK();
  if ((int)lVar4 == 1) {
    lVar4 = *param_1;
    if ((*(longlong **)(lVar4 + 8) != param_1) ||
       (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar2;
    LuafvFreePool((longlong)param_1);
  }
  FltReleasePushLockEx(&DAT_14000b8f0 + (ulonglong)(uVar1 & 0xf) * 0x18,0);
  return;
}



===== LuafvFreePool @ 140016a70 =====

void LuafvFreePool(longlong param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + -8);
  FltAcquirePushLockExclusiveEx(&PoolLock,0);
  DAT_14000c2a4 = DAT_14000c2a4 - *piVar1;
  FltReleasePushLockEx(&PoolLock,0);
  if (*(byte *)(param_1 + -4) < 7) {
    ExFreeToPagedLookasideList
              (*(undefined8 *)(&LookasideLists + (ulonglong)*(byte *)(param_1 + -4) * 8),piVar1);
  }
  else {
    ExFreePoolWithTag(piVar1,0x6661754c);
  }
  return;
}



===== RemoveFileIdTableNode @ 140016af4 =====

void RemoveFileIdTableNode(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  plVar1 = (longlong *)(param_1 + 0xc0);
  if ((*(ushort *)(param_1 + 0x1e) & 0x200) == 0) {
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar2 = *(longlong **)(param_1 + 200), (longlong *)*plVar2 != plVar1)) {
LAB_140016b98:
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
  }
  else {
    plVar2 = (longlong *)*plVar1;
    if (plVar2 == plVar1) {
      LuafvDeleteElementTable(0x14000c248,param_1 + 0x90);
      *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xfdff;
    }
    else {
      *(ushort *)((longlong)plVar2 + -0xa2) = *(ushort *)((longlong)plVar2 + -0xa2) | 0x200;
      lVar3 = *plVar1;
      if ((*(longlong **)(lVar3 + 8) != plVar1) ||
         (plVar4 = *(longlong **)(param_1 + 200), (longlong *)*plVar4 != plVar1))
      goto LAB_140016b98;
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      LuafvReplaceElementTable(&DAT_14000c248,(longlong *)(param_1 + 0x90),plVar2 + -6);
    }
  }
  *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_1 + 0x1e) & 0xffef;
  return;
}



===== LuafvDeleteElementTable @ 140016ba8 =====

void LuafvDeleteElementTable(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if (param_2 == *(longlong *)(param_1 + 8)) {
    uVar1 = RtlRealPredecessor(param_2);
    *(undefined8 *)(param_1 + 8) = uVar1;
  }
  RtlDeleteNoSplay(param_2,param_1);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  return;
}



===== LuafvScavengeFileTable @ 140016bfc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LuafvScavengeFileTable(void)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  longlong lVar8;
  char cVar9;
  int iVar10;
  longlong lVar11;
  undefined *puVar12;
  
  lVar8 = _DAT_fffff78000000014;
  cVar7 = InactiveJournalsOnly;
  bVar5 = DAT_14000c2a8 < DAT_14000c2a4;
  if (bVar5) {
    iVar10 = (DAT_14000c2a8 * 7) / 8;
  }
  else {
    iVar10 = 0;
  }
  FltAcquirePushLockSharedEx(&DAT_14000c278);
  puVar12 = DAT_14000c270;
  do {
    if (puVar12 == &DAT_14000c268) {
      FltReleasePushLockEx(&DAT_14000c278,0);
      return;
    }
    if (((cVar7 == '\0') || (puVar12[0x344] == '\0')) &&
       (cVar9 = ExAcquireRundownProtection(puVar12 + 0x348), cVar9 != '\0')) {
      if (puVar12[0x344] == '\0') {
        lVar11 = lVar8 + 1;
      }
      else {
        lVar11 = lVar8 + -3000000000;
      }
      plVar3 = *(longlong **)(puVar12 + 0x30);
      while (plVar3 != (longlong *)(puVar12 + 0x28)) {
        plVar2 = plVar3 + -0x1a;
        if ((bVar5) && (iVar10 < DAT_14000c2a4)) {
          bVar6 = true;
        }
        else {
          bVar6 = false;
          if (lVar11 <= plVar3[2]) break;
        }
        if (*(int *)((longlong)plVar3 + -0xbc) < 2) {
          LOCK();
          *(int *)((longlong)plVar3 + -0xbc) = *(int *)((longlong)plVar3 + -0xbc) + 1;
          UNLOCK();
          FltReleasePushLockEx(&DAT_14000c278);
          lVar4 = plVar3[-0x16];
          if (*(void **)(lVar4 + 8) == SystemReserved1[0xf]) {
            *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
          }
          else {
            FltAcquirePushLockExclusiveEx(lVar4);
            *(void **)(lVar4 + 8) = SystemReserved1[0xf];
            *(undefined4 *)(lVar4 + 0x10) = 1;
          }
          if ((void *)plVar3[-0x19] == SystemReserved1[0xf]) {
            *(int *)(plVar3 + -0x18) = (int)plVar3[-0x18] + 1;
          }
          else {
            FltAcquirePushLockExclusiveEx(plVar2);
            plVar3[-0x19] = (longlong)SystemReserved1[0xf];
            *(undefined4 *)(plVar3 + -0x18) = 1;
          }
          if (((*plVar3 == 0) || (*(int *)((longlong)plVar3 + -0xbc) != 2)) ||
             ((!bVar6 && (lVar11 <= plVar3[2])))) {
            lVar4 = plVar3[-0x16];
            if (*(void **)(lVar4 + 8) == SystemReserved1[0xf]) {
              piVar1 = (int *)(lVar4 + 0x10);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined8 *)(lVar4 + 8) = 0;
                goto LAB_140016e8e;
              }
            }
            else {
LAB_140016e8e:
              FltReleasePushLockEx(lVar4,0);
            }
          }
          else {
            RemoveTableNode((longlong)plVar2,'\0');
            lVar4 = plVar3[-0x16];
            if (*(void **)(lVar4 + 8) == SystemReserved1[0xf]) {
              piVar1 = (int *)(lVar4 + 0x10);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                *(undefined8 *)(lVar4 + 8) = 0;
                goto LAB_140016e1c;
              }
            }
            else {
LAB_140016e1c:
              FltReleasePushLockEx(lVar4,0);
            }
            LuafvDereferenceTableNodeEx((longlong)plVar2,'\x01','\x01');
          }
          LuafvDereferenceTableNodeEx((longlong)plVar2,'\x01','\0');
          FltAcquirePushLockSharedEx(&DAT_14000c278);
          plVar3 = *(longlong **)(puVar12 + 0x30);
        }
        else {
          plVar3 = (longlong *)plVar3[1];
        }
      }
      ExReleaseRundownProtection(puVar12 + 0x348);
    }
    puVar12 = *(undefined **)(puVar12 + 8);
  } while( true );
}



===== LuafvDereferenceTableNodeEx @ 140016f00 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LuafvDereferenceTableNodeEx(longlong param_1,char param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (param_2 == '\0') {
    if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    }
    else {
      FltAcquirePushLockExclusiveEx();
      *(void **)(param_1 + 8) = SystemReserved1[0xf];
      *(undefined4 *)(param_1 + 0x10) = 1;
    }
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x14);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 != 1) {
    puVar7 = auStack_28;
    if ((((iVar2 == 2) && (puVar7 = auStack_28, (*(ushort *)(param_1 + 0x1e) & 4) == 0)) &&
        (puVar7 = auStack_28, (*(ushort *)(param_1 + 0x1e) & 2) == 0)) &&
       (puVar7 = auStack_28, (*(ulonglong *)(param_1 + 0xa8) & 0xfffffffffffffff8) != 0)) {
      FltAcquirePushLockExclusiveEx(&DAT_14000c278,0);
      puVar7 = auStack_28;
      if ((*(ulonglong *)(param_1 + 0xa8) & 0xfffffffffffffff8) != 0) {
        RemoveMruListNode(param_1);
        puVar6 = auStack_28;
        plVar8 = (longlong *)(*(ulonglong *)(param_1 + 0xa8) & 0xfffffffffffffff8);
        puVar7 = auStack_28;
        if (*plVar8 != 0) {
          lVar4 = plVar8[5];
          plVar5 = (longlong *)(param_1 + 0xd0);
          plVar8 = plVar8 + 5;
          if (*(longlong **)(lVar4 + 8) != plVar8) {
            plVar5 = (longlong *)0x3;
            pcVar3 = (code *)swi(0x29);
            lVar4 = (*pcVar3)();
            puVar6 = auStack_20;
          }
          *plVar5 = lVar4;
          plVar5[1] = (longlong)plVar8;
          *(longlong **)(lVar4 + 8) = plVar5;
          *plVar8 = (longlong)plVar5;
          puVar7 = puVar6;
        }
      }
      *(undefined8 *)(param_1 + 0xe0) = _DAT_fffff78000000014;
      *(undefined8 *)(puVar7 + -8) = 0x140017011;
      FltReleasePushLockEx(&DAT_14000c278,0);
    }
    if (param_3 != '\0') {
      return;
    }
    if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
      piVar1 = (int *)(param_1 + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 != 0) {
        return;
      }
      *(undefined8 *)(param_1 + 8) = 0;
    }
    *(undefined8 *)(puVar7 + -8) = 0x140017042;
    FltReleasePushLockEx(param_1,0);
    return;
  }
  if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
    piVar1 = (int *)(param_1 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) goto LAB_14001707f;
    *(undefined8 *)(param_1 + 8) = 0;
  }
  FltReleasePushLockEx(param_1);
LAB_14001707f:
  if (*(longlong *)(param_1 + 0x20) == 0) {
    return;
  }
  LuafvDereferenceTableNodeEx(*(longlong *)(param_1 + 0x20),'\0','\0');
  FreeTableNode(param_1);
  return;
}



===== LuafvDereferenceUserStore @ 1400170b4 =====

void LuafvDereferenceUserStore(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x48) != 0) {
      LuafvDereferenceTableNodeEx(*(longlong *)(param_1 + 0x48),'\0','\0');
    }
    LuafvDereferenceUser(*(longlong *)(param_1 + 0x10));
    LuafvFreePool(param_1);
  }
  return;
}



===== LuafvLookupElementTableFull @ 140017100 =====

longlong LuafvLookupElementTableFull
                   (longlong *param_1,ulonglong *param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  if ((int)param_1[2] == 0) {
    *param_4 = 0;
  }
  else {
    iVar1 = *(int *)((longlong)param_1 + 0x14);
    lVar4 = *param_1;
    while( true ) {
      while( true ) {
        if (iVar1 == 0) {
          iVar2 = RtlCompareUnicodeString(param_2 + 1,lVar4 + 0x20,1);
          lVar3 = (longlong)iVar2;
        }
        else {
          lVar3 = param_2[1] - *(longlong *)(lVar4 + 0x20);
          if (lVar3 == 0) {
            lVar3 = (*param_2 & 0xfffffffffffffff8) -
                    (*(ulonglong *)(lVar4 + 0x18) & 0xfffffffffffffff8);
          }
        }
        if (lVar3 < 0) break;
        if (lVar3 < 1) {
          *param_3 = lVar4;
          *param_4 = 1;
          lVar4 = RtlSplay(lVar4);
          *param_1 = lVar4;
          return *param_3;
        }
        if (*(longlong *)(lVar4 + 0x10) == 0) {
          *param_4 = 3;
          *param_3 = lVar4;
          return 0;
        }
        lVar4 = *(longlong *)(lVar4 + 0x10);
      }
      if (*(longlong *)(lVar4 + 8) == 0) break;
      lVar4 = *(longlong *)(lVar4 + 8);
    }
    *param_4 = 2;
    *param_3 = lVar4;
  }
  return 0;
}



===== CreateChildTable @ 1400171fc =====

undefined8 CreateChildTable(longlong param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)ExAllocatePool2(0x100,0x20,0x6661754c);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0x18;
    *(undefined1 *)(puVar2 + 1) = 0xff;
    FltAcquirePushLockExclusiveEx(&PoolLock,0);
    DAT_14000c2a4 = DAT_14000c2a4 + 0x18;
    FltReleasePushLockEx(&PoolLock,0);
    puVar1 = (undefined8 *)(puVar2 + 2);
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined8 **)(param_1 + 0x28) = puVar1;
      *puVar1 = 0;
      *(undefined8 *)(puVar2 + 4) = 0;
      *(undefined8 *)(puVar2 + 6) = 0;
      puVar2[7] = 0;
      return 0;
    }
  }
  return 0xc000009a;
}



===== UsnThread @ 1400172a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsnThread(ulonglong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStackY_c8 [32];
  longlong local_88;
  longlong lStack_80;
  undefined8 local_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  iVar1 = *(int *)(param_1 + 0xf0);
  puVar2 = *(undefined8 **)(param_1 + 0xe8);
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0x340) = 1;
  *(undefined1 *)(param_1 + 0x344) = 1;
  local_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_88 = 0;
  lStack_80 = 0;
  KeSetEvent(param_1 + 0x58,0,0);
  local_60 = *(undefined8 *)(param_1 + 0x100);
  local_40 = *(undefined8 *)(param_1 + 0xf8);
  local_50 = 0;
  local_38 = 0x20002;
  local_58 = 0x1bb00;
  local_48 = 1;
  uVar4 = SynchronousFsControl(param_1,(undefined4 *)&local_70,0x900bb,&local_60,0x30,puVar2,iVar1);
  iVar3 = (int)uVar4;
  do {
    if (iVar3 == 1) {
LAB_1400173e6:
      FltAcquirePushLockExclusiveEx(param_1 + 0x108,0);
      *(undefined4 *)(param_1 + 0x340) = 5;
      FltReleasePushLockEx(param_1 + 0x108,0);
      PsTerminateSystemThread(0);
      return;
    }
    if (((int)uVar4 < 0) || ((int)uVar4 == 2)) {
      *(undefined1 *)(param_1 + 0x344) = 0;
      LOCK();
      DAT_14000c2a0 = DAT_14000c2a0 + 1;
      UNLOCK();
      LuafvEnumerateFileTable
                (*(longlong *)(param_1 + 0x20),'\0',(undefined *)0x0,ClearFileTablePostWorker,1);
      do {
        if ((int)uVar4 == 2) goto LAB_14001748c;
        while( true ) {
          uVar4 = InitializeUsn(param_1);
          iVar3 = (int)uVar4;
          if (iVar3 == 1) goto LAB_1400173e6;
          if (iVar3 == 2) break;
          if (-1 < iVar3) {
            *(undefined1 *)(param_1 + 0x344) = 1;
            LOCK();
            DAT_14000c2a0 = DAT_14000c2a0 + -1;
            UNLOCK();
            goto LAB_1400173a1;
          }
          local_88 = param_1 + 0x70;
          lStack_80 = param_1 + 0x88;
          local_78 = 0xfffffffffa0a1f00;
          iVar3 = KeWaitForMultipleObjects(2,&local_88,1);
          if (iVar3 == 0) goto LAB_1400173e6;
          if (iVar3 == 1) {
            AcknowledgePauseRequest(param_1);
LAB_14001748c:
            local_88 = param_1 + 0x70;
            lStack_80 = param_1 + 0xb8;
            iVar3 = KeWaitForMultipleObjects(2,&local_88,1);
            if (iVar3 == 0) goto LAB_1400173e6;
          }
        }
      } while( true );
    }
    ProcessUsnData(param_1,puVar2,uStack_68);
LAB_1400173a1:
    local_60 = *(undefined8 *)(param_1 + 0x100);
    local_40 = *(undefined8 *)(param_1 + 0xf8);
    uVar4 = SynchronousFsControl
                      (param_1,(undefined4 *)&local_70,0x900bb,&local_60,0x30,puVar2,iVar1);
    iVar3 = (int)uVar4;
  } while( true );
}



===== SynchronousFsControl @ 140017570 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynchronousFsControl
                    (longlong param_1,undefined4 *param_2,int param_3,undefined8 param_4,
                    undefined4 param_5,undefined8 param_6,int param_7)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStack_a8 [32];
  ulonglong local_88;
  undefined1 local_80;
  undefined8 local_78;
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  longlong lStack_50;
  longlong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  local_48 = 0;
  local_68 = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_60 = param_4;
  iVar6 = KeReadStateEvent(param_1 + 0x70);
  if (iVar6 == 0) {
    lVar1 = param_1 + 0x88;
    iVar6 = KeReadStateEvent(lVar1);
    if (iVar6 == 0) {
      lVar2 = param_1 + 0xd0;
      KeClearEvent(lVar2);
      uVar8 = FltAllocateCallbackData
                        (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x40),&local_68);
      if (-1 < (int)uVar8) {
        *(undefined1 *)(*(longlong *)(local_68 + 0x10) + 4) = 0xd;
        *(undefined1 *)(*(longlong *)(local_68 + 0x10) + 5) = 0;
        if ((param_3 == 0x900e7) || (param_3 == 0x900bb)) {
          **(undefined4 **)(local_68 + 0x10) = 0;
          *(int *)(*(longlong *)(local_68 + 0x10) + 0x28) = param_3;
          *(undefined4 *)(*(longlong *)(local_68 + 0x10) + 0x20) = param_5;
          *(int *)(*(longlong *)(local_68 + 0x10) + 0x18) = param_7;
          *(undefined8 *)(*(longlong *)(local_68 + 0x10) + 0x30) = local_60;
          *(undefined8 *)(*(longlong *)(local_68 + 0x10) + 0x38) = param_6;
          *(undefined8 *)(*(longlong *)(local_68 + 0x10) + 0x40) = 0;
        }
        else {
          if ((param_3 != 0x900f4) && (param_3 != 0x900f8)) {
            FltFreeCallbackData(local_68);
            return 0xc000000d;
          }
          **(undefined4 **)(local_68 + 0x10) = 0x10;
          *(int *)(*(longlong *)(local_68 + 0x10) + 0x28) = param_3;
          *(undefined4 *)(*(longlong *)(local_68 + 0x10) + 0x20) = param_5;
          *(int *)(*(longlong *)(local_68 + 0x10) + 0x18) = param_7;
          if (param_7 == 0) {
            *(undefined8 *)(*(longlong *)(local_68 + 0x10) + 0x30) = local_60;
          }
          else {
            *(undefined8 *)(*(longlong *)(local_68 + 0x10) + 0x30) = param_6;
            **(uint **)(local_68 + 0x10) = **(uint **)(local_68 + 0x10) | 0x40;
          }
        }
        uVar7 = FltPerformAsynchronousIo(local_68,AsyncIoCompletion,param_1 + 0x38);
        if (uVar7 == 0x103) {
          local_70 = 0;
          local_78 = 0;
          local_80 = 0;
          local_88 = local_88 & 0xffffffffffffff00;
          local_58 = param_1 + 0x70;
          lStack_50 = lVar1;
          local_48 = lVar2;
          uVar7 = KeWaitForMultipleObjects(3,&local_58,1);
          if (uVar7 != 2) {
            FltCancelIo(local_68);
            local_88 = 0;
            KeWaitForSingleObject(lVar2,0,0,0);
            if (uVar7 == 1) {
              AcknowledgePauseRequest(param_1);
            }
            if (param_2 != (undefined4 *)0x0) {
              uVar3 = *(undefined4 *)(local_68 + 0x1c);
              uVar4 = *(undefined4 *)(local_68 + 0x20);
              uVar5 = *(undefined4 *)(local_68 + 0x24);
              *param_2 = *(undefined4 *)(local_68 + 0x18);
              param_2[1] = uVar3;
              param_2[2] = uVar4;
              param_2[3] = uVar5;
            }
            FltFreeCallbackData();
            return (ulonglong)(uVar7 + 1);
          }
        }
        if (-1 < (int)uVar7) {
          uVar7 = *(uint *)(local_68 + 0x18);
        }
        uVar8 = (ulonglong)uVar7;
        if (param_2 != (undefined4 *)0x0) {
          uVar3 = *(undefined4 *)(local_68 + 0x1c);
          uVar4 = *(undefined4 *)(local_68 + 0x20);
          uVar5 = *(undefined4 *)(local_68 + 0x24);
          *param_2 = *(undefined4 *)(local_68 + 0x18);
          param_2[1] = uVar3;
          param_2[2] = uVar4;
          param_2[3] = uVar5;
        }
        FltFreeCallbackData();
      }
    }
    else {
      KeClearEvent(lVar1);
      AcknowledgePauseRequest(param_1);
      uVar8 = 2;
    }
  }
  else {
    uVar8 = 1;
  }
  return uVar8;
}



===== ProcessUsnData @ 140017890 =====

void ProcessUsnData(ulonglong param_1,undefined8 *param_2,ulonglong param_3)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  uint *puVar11;
  uint *puVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  
  if (7 < param_3) {
    puVar10 = auStack_48;
    *(undefined8 *)(param_1 + 0x100) = *param_2;
    lVar14 = param_3 - 8;
    if (lVar14 != 0) {
      puVar12 = (uint *)(param_2 + 1);
      plVar1 = (longlong *)(param_1 + 0x310);
LAB_1400178ea:
      uVar6 = 0;
      plVar13 = (longlong *)0x0;
      for (plVar9 = (longlong *)*plVar1; plVar9 != plVar1; plVar9 = (longlong *)*plVar9) {
        if (plVar9[2] == *(longlong *)(puVar12 + 2)) {
          uVar6 = 1;
          goto LAB_140017a5e;
        }
      }
      for (plVar9 = *(longlong **)(param_1 + 800); plVar9 != (longlong *)(param_1 + 800);
          plVar9 = (longlong *)*plVar9) {
        if (plVar9[2] == *(longlong *)(puVar12 + 2)) goto LAB_140017a5e;
      }
      goto LAB_140017922;
    }
  }
  return;
LAB_140017a5e:
  plVar13 = plVar9;
  if ((~*(uint *)(plVar9 + 3) & puVar12[10] & 0x1bb00) != 0) {
LAB_140017922:
    *(undefined8 *)(puVar10 + -8) = 0x14001792d;
    uVar6 = LuafvUpdateFileTableForChangeRecord(param_1,(longlong)puVar12);
    uVar6 = uVar6 & 0xff;
  }
  puVar11 = puVar12 + 10;
  if (plVar13 != (longlong *)0x0) goto LAB_1400179a6;
  if (-1 < (int)*puVar11) {
    plVar8 = (longlong *)(param_1 + 0x330);
    if ((longlong *)*plVar8 == plVar8) {
      plVar8 = (longlong *)(param_1 + 800);
      if ((longlong *)*plVar8 == plVar8) {
        if ((char)uVar6 == '\0') goto LAB_1400179e3;
        plVar8 = plVar1;
      }
    }
    if (plVar8 != (longlong *)0x0) {
      plVar3 = (longlong *)plVar8[1];
      if (((longlong *)*plVar3 == plVar8) &&
         (puVar4 = (undefined8 *)plVar3[1], (longlong *)*puVar4 == plVar3)) {
        plVar8[1] = (longlong)puVar4;
        *puVar4 = plVar8;
        plVar3[2] = *(longlong *)(puVar12 + 2);
        *(uint *)(plVar3 + 3) = *puVar11;
        plVar8 = plVar1;
        if ((char)uVar6 == '\0') {
          plVar8 = (longlong *)(param_1 + 800);
        }
        lVar7 = *plVar8;
        if (*(longlong **)(lVar7 + 8) == plVar8) {
          *plVar3 = lVar7;
          plVar3[1] = (longlong)plVar8;
          *(longlong **)(lVar7 + 8) = plVar3;
          *plVar8 = (longlong)plVar3;
          goto LAB_1400179e3;
        }
      }
      do {
        while( true ) {
          do {
            pcVar5 = (code *)swi(0x29);
            (*pcVar5)(3);
            puVar10 = puVar10 + 8;
LAB_1400179a6:
            lVar7 = *plVar9;
          } while ((*(longlong **)(lVar7 + 8) != plVar9) ||
                  (plVar8 = (longlong *)plVar9[1], (longlong *)*plVar8 != plVar9));
          *plVar8 = lVar7;
          *(longlong **)(lVar7 + 8) = plVar8;
          if (-1 < (int)*puVar11) break;
          plVar8 = *(longlong **)(param_1 + 0x338);
          if (*plVar8 == param_1 + 0x330) {
            *plVar9 = param_1 + 0x330;
            plVar9[1] = (longlong)plVar8;
            *plVar8 = (longlong)plVar9;
            *(longlong **)(param_1 + 0x338) = plVar9;
            goto LAB_1400179e3;
          }
        }
        *(uint *)(plVar13 + 3) = *(uint *)(plVar13 + 3) | *puVar11;
        lVar7 = 0x310;
        if ((char)uVar6 == '\0') {
          lVar7 = 800;
        }
        plVar8 = (longlong *)(lVar7 + param_1);
        lVar7 = *plVar8;
      } while (*(longlong **)(lVar7 + 8) != plVar8);
      *plVar9 = lVar7;
      plVar9[1] = (longlong)plVar8;
      *(longlong **)(lVar7 + 8) = plVar9;
      *plVar8 = (longlong)plVar9;
    }
  }
LAB_1400179e3:
  uVar2 = *puVar12;
  puVar12 = (uint *)((longlong)puVar12 + (ulonglong)uVar2);
  lVar14 = lVar14 - (ulonglong)uVar2;
  if (lVar14 == 0) {
    return;
  }
  goto LAB_1400178ea;
}



===== LuafvUpdateFileTableForChangeRecord @ 140017ac0 =====

undefined8 LuafvUpdateFileTableForChangeRecord(ulonglong param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  longlong local_res18 [2];
  ulonglong local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_68 = (ulonglong)(uint)local_68;
  local_58 = local_58 & 0xffffffff00000000;
  FltAcquirePushLockSharedEx(&DAT_14000c260,0);
  iVar3 = DAT_14000c258._4_4_;
  uVar9 = 0;
  local_68 = param_1;
  if ((*(uint *)(param_2 + 0x28) & 0x2100) == 0) {
    lVar6 = *(longlong *)(param_2 + 8);
    local_60 = lVar6;
    if ((int)DAT_14000c258 != 0) {
      lVar7 = DAT_14000c248;
      do {
        if (iVar3 == 0) {
          iVar4 = RtlCompareUnicodeString(&local_60,lVar7 + 0x20,1);
          lVar5 = (longlong)iVar4;
          lVar6 = local_60;
          param_1 = local_68;
        }
        else {
          lVar5 = lVar6 - *(longlong *)(lVar7 + 0x20);
          if (lVar5 == 0) {
            lVar5 = (param_1 & 0xfffffffffffffff8) -
                    (*(ulonglong *)(lVar7 + 0x18) & 0xfffffffffffffff8);
          }
        }
        if (lVar5 < 0) {
          lVar7 = *(longlong *)(lVar7 + 8);
        }
        else {
          if (lVar5 < 1) {
            DAT_14000c248 = RtlSplay(lVar7);
            if (lVar7 != 0) goto LAB_140017dd2;
            break;
          }
          lVar7 = *(longlong *)(lVar7 + 0x10);
        }
      } while (lVar7 != 0);
    }
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x10);
    local_60 = lVar6;
    if ((int)DAT_14000c258 != 0) {
      lVar7 = DAT_14000c248;
      do {
        while( true ) {
          if (iVar3 == 0) {
            iVar4 = RtlCompareUnicodeString(&local_60,lVar7 + 0x20,1);
            lVar5 = (longlong)iVar4;
            lVar6 = local_60;
            param_1 = local_68;
          }
          else {
            lVar5 = lVar6 - *(longlong *)(lVar7 + 0x20);
            if (lVar5 == 0) {
              lVar5 = (param_1 & 0xfffffffffffffff8) -
                      (*(ulonglong *)(lVar7 + 0x18) & 0xfffffffffffffff8);
            }
          }
          if (lVar5 < 0) break;
          if (lVar5 < 1) {
            DAT_14000c248 = RtlSplay(lVar7);
            if (((lVar7 != 0) && ((*(byte *)(lVar7 + -0x72) & 4) == 0)) &&
               (*(longlong *)(lVar7 + -0x68) != 0)) {
              LOCK();
              *(int *)(lVar7 + -0x7c) = *(int *)(lVar7 + -0x7c) + 1;
              UNLOCK();
              FltReleasePushLockEx(&DAT_14000c260,0);
              if (*(void **)(lVar7 + -0x88) == SystemReserved1[0xf]) {
                *(int *)(lVar7 + -0x80) = *(int *)(lVar7 + -0x80) + 1;
              }
              else {
                FltAcquirePushLockExclusiveEx(lVar7 + -0x90,0);
                *(void **)(lVar7 + -0x88) = SystemReserved1[0xf];
                *(undefined4 *)(lVar7 + -0x80) = 1;
              }
              if (((*(byte *)(lVar7 + -0x72) & 4) == 0) && (*(longlong *)(lVar7 + -0x68) != 0)) {
                local_60._0_4_ =
                     CONCAT22(*(undefined2 *)(param_2 + 0x38),*(undefined2 *)(param_2 + 0x38));
                local_58 = (ulonglong)*(ushort *)(param_2 + 0x3a) + param_2;
                local_res18[1] = 0;
                local_res10[0] = 0;
                lVar6 = LuafvLookupElementTableFull
                                  (*(longlong **)(lVar7 + -0x68),&local_68,local_res18 + 1,
                                   local_res10);
                if (lVar6 != 0) {
                  uVar9 = 1;
                  lVar5 = 0x30;
                  if ((*(byte *)(lVar6 + 0x18) & 7) != 0) {
                    lVar5 = 0x60;
                  }
                  lVar6 = lVar6 - lVar5;
                  if (*(void **)(lVar6 + 8) == SystemReserved1[0xf]) {
                    *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
                  }
                  else {
                    FltAcquirePushLockExclusiveEx(lVar6,0);
                    *(void **)(lVar6 + 8) = SystemReserved1[0xf];
                    *(undefined4 *)(lVar6 + 0x10) = 1;
                  }
                  if ((*(byte *)(lVar6 + 0x1e) & 0x84) == 0) {
                    RemoveTableNode(lVar6,'\x01');
                  }
                  if (*(void **)(lVar6 + 8) == SystemReserved1[0xf]) {
                    piVar1 = (int *)(lVar6 + 0x10);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 != 0) goto LAB_140017d03;
                    *(undefined8 *)(lVar6 + 8) = 0;
                  }
                  FltReleasePushLockEx(lVar6,0);
                }
              }
LAB_140017d03:
              LuafvDereferenceTableNodeEx(lVar7 + -0x90,'\x01','\0');
              return uVar9;
            }
            goto LAB_140017ba7;
          }
          lVar7 = *(longlong *)(lVar7 + 0x10);
          if (lVar7 == 0) goto LAB_140017ba7;
        }
        lVar7 = *(longlong *)(lVar7 + 8);
      } while (lVar7 != 0);
    }
  }
LAB_140017ba7:
  FltReleasePushLockEx(&DAT_14000c260,0);
  return uVar9;
  while( true ) {
    LuafvDereferenceTableNodeEx(lVar5,'\x01','\0');
    FltAcquirePushLockSharedEx(&DAT_14000c260,0);
    local_res18[0] = 0;
    local_res8[0] = 0;
    lVar7 = LuafvLookupElementTableFull(&DAT_14000c248,&local_68,local_res18,local_res8);
    if (lVar7 == 0) break;
LAB_140017dd2:
    lVar5 = lVar7 + -0x90;
    uVar9 = 1;
    LOCK();
    *(int *)(lVar7 + -0x7c) = *(int *)(lVar7 + -0x7c) + 1;
    UNLOCK();
    FltReleasePushLockEx(&DAT_14000c260,0);
    lVar6 = *(longlong *)(lVar7 + -0x70);
    if (*(void **)(lVar6 + 8) == SystemReserved1[0xf]) {
      *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
    }
    else {
      FltAcquirePushLockExclusiveEx(lVar6,0);
      *(void **)(lVar6 + 8) = SystemReserved1[0xf];
      *(undefined4 *)(lVar6 + 0x10) = 1;
    }
    if (*(void **)(lVar7 + -0x88) == SystemReserved1[0xf]) {
      *(int *)(lVar7 + -0x80) = *(int *)(lVar7 + -0x80) + 1;
    }
    else {
      FltAcquirePushLockExclusiveEx(lVar5,0);
      *(void **)(lVar7 + -0x88) = SystemReserved1[0xf];
      *(undefined4 *)(lVar7 + -0x80) = 1;
    }
    if ((*(byte *)(lVar7 + -0x72) & 0x84) == 0) {
      if (((*(uint *)(param_2 + 0x28) & 0x1000) != 0) && (*(longlong *)(lVar7 + -0x68) != 0)) {
        lVar6 = *(longlong *)(lVar7 + -0x70);
        if (lVar6 != 0) {
          if (*(void **)(lVar6 + 8) == SystemReserved1[0xf]) {
            *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
          }
          else {
            FltAcquirePushLockExclusiveEx(lVar6,0);
            *(void **)(lVar6 + 8) = SystemReserved1[0xf];
            *(undefined4 *)(lVar6 + 0x10) = 1;
          }
        }
        if (*(void **)(lVar7 + -0x88) == SystemReserved1[0xf]) {
          *(int *)(lVar7 + -0x80) = *(int *)(lVar7 + -0x80) + 1;
        }
        else {
          FltAcquirePushLockExclusiveEx(lVar5,0);
          *(void **)(lVar7 + -0x88) = SystemReserved1[0xf];
          *(undefined4 *)(lVar7 + -0x80) = 1;
        }
        lVar6 = lVar5;
        do {
          plVar2 = *(longlong **)(lVar6 + 0x28);
          if (plVar2 == (longlong *)0x0) {
            lVar8 = 0;
            goto LAB_140017f84;
          }
          plVar2[1] = 0;
          lVar8 = LuafvEnumerateTableWithoutSplaying(plVar2,plVar2 + 1);
          if (lVar8 == 0) goto LAB_140017f84;
          do {
            if ((*(byte *)(lVar8 + 0x18) & 7) != 1) goto LAB_140017f89;
            lVar8 = LuafvEnumerateTable(plVar2,'\0');
            lVar10 = lVar6;
          } while (lVar8 != 0);
          do {
            lVar6 = *(longlong *)(lVar10 + 0x20);
            ClearFileTablePostWorker(lVar10,1);
            if (lVar10 == lVar5) {
              if (lVar6 == 0) goto LAB_140017e87;
              if (*(void **)(lVar6 + 8) == SystemReserved1[0xf]) {
                piVar1 = (int *)(lVar6 + 0x10);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 != 0) goto LAB_140017e87;
                *(undefined8 *)(lVar6 + 8) = 0;
              }
              FltReleasePushLockEx(lVar6,0);
              goto LAB_140017e87;
            }
            plVar2 = *(longlong **)(lVar6 + 0x28);
            lVar8 = LuafvEnumerateTableWithoutSplaying(plVar2,plVar2 + 1);
            while ((lVar8 != 0 && ((*(byte *)(lVar8 + 0x18) & 7) == 1))) {
              lVar8 = LuafvEnumerateTableWithoutSplaying(plVar2,plVar2 + 1);
            }
LAB_140017f84:
            lVar10 = lVar6;
          } while (lVar8 == 0);
LAB_140017f89:
          lVar6 = lVar8 + -0x30;
          if (*(void **)(lVar8 + -0x28) == SystemReserved1[0xf]) {
            *(int *)(lVar8 + -0x20) = *(int *)(lVar8 + -0x20) + 1;
          }
          else {
            FltAcquirePushLockExclusiveEx(lVar6,0);
            *(void **)(lVar8 + -0x28) = SystemReserved1[0xf];
            *(undefined4 *)(lVar8 + -0x20) = 1;
          }
        } while( true );
      }
      RemoveTableNode(lVar5,'\x01');
    }
LAB_140017e87:
    lVar6 = *(longlong *)(lVar7 + -0x70);
    if (*(void **)(lVar6 + 8) == SystemReserved1[0xf]) {
      piVar1 = (int *)(lVar6 + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined8 *)(lVar6 + 8) = 0;
        goto LAB_140017ea4;
      }
    }
    else {
LAB_140017ea4:
      FltReleasePushLockEx(lVar6,0);
    }
  }
  goto LAB_140017ba7;
}



===== LuafvCheckAdminAccess @ 140018114 =====

int LuafvCheckAdminAccess(longlong param_1,undefined8 param_2,ushort *param_3,undefined1 *param_4)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined4 local_res8 [2];
  undefined4 local_res18 [4];
  longlong **pplVar6;
  longlong *local_58;
  longlong local_50;
  longlong local_48;
  
  local_50 = 0;
  bVar5 = false;
  local_res18[0] = 0;
  local_res8[0] = 0;
  local_58 = (longlong *)0x0;
  local_48 = *(longlong *)(param_1 + 0x10);
  cVar2 = '\x02';
  if ((param_3[0x14] & 1) == 0) {
LAB_14001823c:
    if ((param_3[0x14] & 2) != 0) {
      pplVar6 = &local_58;
      iVar3 = LuafvReadAndCacheSecurityDescriptor
                        (param_2,*(longlong *)(*(longlong *)(param_3 + 0x10) + 0x20),param_3,'\x01',
                         (longlong *)pplVar6);
      cVar2 = (-((*(byte *)(local_48 + 0x20) & 1) != 0) & 2U) + 2;
      goto LAB_14001818a;
    }
LAB_140018299:
    bVar5 = true;
  }
  else {
    pplVar6 = &local_58;
    iVar3 = LuafvReadAndCacheSecurityDescriptor
                      (param_2,*(longlong *)(param_3 + 0x10),param_3,'\0',(longlong *)pplVar6);
    if (iVar3 == -0x3fffffcc) goto LAB_14001823c;
LAB_14001818a:
    if (-1 < iVar3) {
      iVar3 = LuafvBuildAdminInformation(param_1,&local_50);
      plVar1 = local_58;
      if (-1 < iVar3) {
        uVar4 = IoGetFileObjectGenericMapping();
        cVar2 = SeAccessCheckFromState
                          (plVar1[2],local_50,0,cVar2,(ulonglong)pplVar6 & 0xffffffff00000000,0,
                           uVar4,1,local_res18,local_res8);
        LuafvFreePool(local_50);
        bVar5 = cVar2 != '\0';
      }
      LuafvDereferenceCachedSecurityDescriptor(plVar1);
      if (iVar3 < 0) {
        return iVar3;
      }
      goto LAB_14001821d;
    }
    if ((iVar3 + 0x3fffffcdU < 2) || (iVar3 == -0x3fffffc6)) goto LAB_140018299;
    if (iVar3 != -0x3fffffde) {
      return iVar3;
    }
  }
  iVar3 = 0;
LAB_14001821d:
  *param_4 = bVar5;
  return iVar3;
}



===== LuafvBuildAdminInformation @ 1400182a8 =====

/* WARNING: Type propagation algorithm not settling */

int LuafvBuildAdminInformation(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  longlong *plVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  undefined8 *puVar18;
  bool bVar19;
  undefined4 local_res8 [2];
  undefined8 *local_res10;
  uint local_res18;
  undefined8 *local_res20;
  undefined8 local_a8;
  uint *local_a0;
  uint *local_98;
  undefined8 local_90;
  longlong local_88 [9];
  
  plVar9 = local_88 + 3;
  iVar14 = 0;
  local_88[3] = 0;
  local_88[4] = 0;
  local_res20 = (undefined8 *)0x0;
  local_88[5] = 0;
  local_88[6] = 0;
  local_a8 = 0;
  local_res8[0] = 0;
  bVar19 = *(char *)(*(longlong *)(param_1 + 0x10) + 4) != '\0';
  local_res10 = param_2;
  if (bVar19) {
    SeCaptureSubjectContext(local_88 + 3);
  }
  else {
    plVar9 = (longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x20);
  }
  lVar17 = *plVar9;
  if (lVar17 == 0) {
    lVar17 = plVar9[2];
  }
  iVar5 = SeQueryInformationToken(lVar17,0x16,&local_res20);
  if (bVar19) {
    SeReleaseSubjectContext(local_88 + 3);
  }
  if (iVar5 < 0) {
    return iVar5;
  }
  uVar13 = 0xffffffff;
  local_res18 = 0xffffffff;
  uVar15 = 0xffffffff;
  local_a0 = (uint *)*local_res20;
  local_98 = (uint *)local_res20[2];
  uVar16 = *local_a0;
  uVar10 = (ulonglong)uVar16 * 0x10;
  if (uVar10 < 0x100000000) {
    uVar12 = 0;
    if (uVar16 != 0) {
      lVar17 = 0;
      do {
        local_a8 = *(undefined8 *)(lVar17 + *(longlong *)(local_a0 + 2));
        iVar5 = RtlLengthSid();
        uVar10 = (ulonglong)(uint)((int)uVar10 + iVar5);
        if ((uVar13 == 0xffffffff) &&
           (cVar4 = RtlEqualSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110),local_a8),
           cVar4 != '\0')) {
          uVar13 = uVar12;
        }
        else if ((uVar15 == 0xffffffff) &&
                ((*(byte *)(lVar17 + 8 + *(longlong *)(local_a0 + 2)) & 0x60) == 0x60)) {
          uVar15 = uVar12;
        }
        uVar12 = uVar12 + 1;
        lVar17 = lVar17 + 0x10;
      } while (uVar12 < uVar16);
      local_res18 = uVar13;
    }
    uVar16 = (uint)uVar10;
    if (local_res18 == 0xffffffff) {
      local_90 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x110);
      local_88[0]._0_4_ = 7;
    }
    uVar13 = (uint)(local_res18 == 0xffffffff);
    if (uVar15 == 0xffffffff) {
      uVar10 = (ulonglong)uVar13;
      uVar13 = uVar13 + 1;
      local_88[uVar10 * 2 + -1] = *(undefined8 *)(*(longlong *)SeExports_exref + 0x1f0);
      *(undefined4 *)(local_88 + uVar10 * 2) = 0x60;
    }
    if (uVar13 != 0) {
      uVar10 = (ulonglong)uVar13;
      puVar18 = &local_90;
      uVar16 = uVar16 + uVar13 * 0x10;
      do {
        iVar5 = RtlLengthSid(*puVar18);
        uVar16 = uVar16 + iVar5;
        puVar18 = puVar18 + 2;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    if (uVar16 + 8 < uVar16) {
      iVar14 = -0x3fffff6b;
      goto LAB_140018411;
    }
    uVar16 = uVar16 + 8 & 0xfffffff8;
    if ((ulonglong)*local_98 * 0xc < 0x100000000) {
      iVar5 = (int)((ulonglong)*local_98 * 0xc);
      iVar6 = iVar5 + 0x398 + uVar16;
      iVar8 = iVar6 + -0xc;
      if (iVar5 == 0) {
        iVar8 = iVar6;
      }
      if ((7 < iVar8 + 8U) &&
         (piVar7 = (int *)ExAllocatePool2(0x100,iVar8 + 8U,0x6661754c), piVar7 != (int *)0x0)) {
        *piVar7 = iVar8;
        *(undefined1 *)(piVar7 + 1) = 0xff;
        FltAcquirePushLockExclusiveEx(&PoolLock);
        DAT_14000c2a4 = DAT_14000c2a4 + iVar8;
        FltReleasePushLockEx(&PoolLock);
        plVar9 = (longlong *)(piVar7 + 2);
        if (plVar9 != (longlong *)0x0) {
          memset(plVar9,0,0x58);
          puVar3 = local_a0;
          piVar1 = piVar7 + 0x18;
          piVar2 = piVar7 + 0x5c;
          *(undefined8 *)(piVar7 + 8) = local_res20[3];
          piVar7[10] = *(int *)(local_res20 + 4);
          piVar7[0xb] = *(int *)((longlong)local_res20 + 0x24);
          piVar7[0xc] = *(int *)(local_res20 + 5);
          piVar7[0xd] = *(uint *)((longlong)local_res20 + 0x2c) & 0xffffbfff | 0x2000;
          iVar5 = *local_a0 + uVar13;
          *(int **)(piVar7 + 0x1a) = piVar2;
          *piVar1 = iVar5;
          RtlCopySidAndAttributesArray
                    (*local_a0,*(undefined8 *)(local_a0 + 2),uVar16 + iVar5 * -0x10,piVar2,
                     (ulonglong)(uint)(iVar5 * 0x10) + (longlong)piVar2,&local_a8,local_res8);
          if (local_res18 != 0xffffffff) {
            *(undefined4 *)(*(longlong *)(piVar7 + 0x1a) + 8 + (ulonglong)local_res18 * 0x10) = 7;
          }
          if (uVar15 != 0xffffffff) {
            *(undefined8 *)(*(longlong *)(piVar7 + 0x1a) + (ulonglong)uVar15 * 0x10) =
                 *(undefined8 *)(*(longlong *)SeExports_exref + 0x1f0);
            *(undefined4 *)(*(longlong *)(piVar7 + 0x1a) + 8 + (ulonglong)uVar15 * 0x10) = 0x60;
          }
          if (uVar13 != 0) {
            RtlCopySidAndAttributesArray
                      (uVar13,&local_90,local_res8[0],
                       (ulonglong)*puVar3 * 0x10 + *(longlong *)(piVar7 + 0x1a),local_a8,&local_a8,
                       local_res8);
          }
          RtlSidHashInitialize(*(undefined8 *)(piVar7 + 0x1a),*piVar1,piVar1);
          *plVar9 = (longlong)piVar1;
          puVar11 = (undefined4 *)((ulonglong)uVar16 + *(longlong *)(piVar7 + 0x1a));
          *puVar11 = 0;
          *(undefined8 *)(puVar11 + 2) = 0;
          *(undefined4 **)(piVar7 + 4) = puVar11;
          puVar11[0x44] = 0;
          *(undefined8 *)(puVar11 + 0x46) = 0;
          *(undefined4 **)(piVar7 + 0x12) = puVar11 + 0x44;
          piVar7[0x10] = 0;
          piVar7[0x11] = 0;
          uVar16 = *local_98;
          puVar11[0x88] = uVar16;
          RtlCopyLuidAndAttributesArray(uVar16,local_98 + 1,puVar11 + 0x89);
          *(undefined4 **)(piVar7 + 6) = puVar11 + 0x88;
          *local_res10 = plVar9;
          goto LAB_140018411;
        }
      }
      iVar14 = -0x3fffff66;
      goto LAB_140018411;
    }
  }
  iVar14 = -0x3ffffff3;
LAB_140018411:
  ExFreePoolWithTag(local_res20,0);
  return iVar14;
}



===== LuafvReplaceElementTable @ 14001876c =====

void LuafvReplaceElementTable(undefined8 *param_1,longlong *param_2,longlong *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)*param_2;
  puVar1 = (undefined8 *)param_2[1];
  puVar2 = (undefined8 *)param_2[2];
  if (plVar3 == param_2) {
    *param_1 = param_3;
    plVar3 = param_3;
  }
  else if ((longlong *)plVar3[1] == param_2) {
    plVar3[1] = (longlong)param_3;
  }
  else {
    plVar3[2] = (longlong)param_3;
  }
  *param_3 = (longlong)plVar3;
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = param_3;
  }
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = param_3;
  }
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  return;
}



===== LuafvFindUserStore @ 1400187c0 =====

int LuafvFindUserStore(undefined8 param_1,longlong param_2,longlong param_3,undefined8 *param_4)

{
  ushort uVar1;
  code *pcVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint *puVar9;
  longlong *plVar10;
  longlong lVar11;
  void *_Src;
  short sVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  ushort *puVar15;
  uint uVar16;
  void *_Dst;
  uint *_Dst_00;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  ushort local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50 [4];
  undefined8 local_30;
  
  local_58 = 0;
  local_60 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_30 = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  cVar4 = ExAcquireRundownProtection(&DAT_14000c0e8);
  if (cVar4 == '\0') {
    *param_4 = 0;
    return 0;
  }
  cVar4 = '\0';
  _Dst_00 = (uint *)0x0;
  FltAcquirePushLockSharedEx(&UserListLock,0);
  puVar13 = auStack_88;
  puVar14 = auStack_88;
  do {
    iVar5 = FindUser(param_2,cVar4,&local_58);
    lVar3 = local_58;
    if (iVar5 < 0) {
      if (_Dst_00 != (uint *)0x0) {
LAB_140018b55:
        LuafvFreePool((longlong)_Dst_00);
        puVar13 = auStack_88;
      }
LAB_1400188a3:
      *(undefined8 *)(puVar13 + -8) = 0x1400188b3;
      FltReleasePushLockEx(&UserListLock,0);
      *(undefined8 *)(puVar13 + -8) = 0x1400188c6;
      ExReleaseRundownProtection(&DAT_14000c0e8);
      return iVar5;
    }
    if (local_58 != 0) {
      puVar7 = *(uint **)(local_58 + 0x20);
      while (puVar9 = puVar7, puVar9 != (uint *)(local_58 + 0x20)) {
        if (*(longlong *)(puVar9 + 8) == param_3) {
          iVar5 = 0;
          if (*(char *)((longlong)puVar9 + 0x51) == '\0') {
            LOCK();
            puVar9[6] = puVar9[6] + 1;
            UNLOCK();
            *param_4 = puVar9;
            puVar13 = auStack_88;
          }
          else {
            *param_4 = 0;
            puVar13 = auStack_88;
          }
          goto LAB_1400188a3;
        }
        _Dst_00 = puVar9;
        puVar7 = *(uint **)puVar9;
      }
      if (cVar4 != '\0') {
        cVar4 = *(char *)(param_3 + 0x350);
        if (cVar4 == '\0') {
          *(undefined8 *)(local_58 + 0x40) = 0;
          *(undefined8 *)(local_58 + 0x48) = 0;
          local_68 = *(short *)(local_58 + 0x58) + LuafvStoreRoot;
LAB_140018940:
          puVar15 = (ushort *)(*(longlong *)(param_3 + 0x18) + 0x38);
          if (local_68 == 0) goto LAB_140018975;
          uVar16 = (uint)local_68 + *puVar15 + 0x58;
          uVar6 = uVar16 + 8;
          if (7 < uVar6) goto LAB_14001897a;
        }
        else {
          if (*(longlong *)(local_58 + 0x48) != 0) {
LAB_14001893b:
            local_68 = *(ushort *)(lVar3 + 0x40);
            goto LAB_140018940;
          }
          uVar8 = GetLocalAppDataStorePath(local_58 + 0x58,(short *)(local_58 + 0x40));
          if (-1 < (int)uVar8) goto LAB_14001893b;
          if ((int)uVar8 == -0x3fffffcc) {
            *param_4 = 0;
            iVar5 = 0;
            puVar13 = auStack_88;
            goto LAB_1400188a3;
          }
          local_68 = 0;
          puVar15 = (ushort *)(*(longlong *)(param_3 + 0x18) + 0x38);
LAB_140018975:
          uVar16 = 0x58;
          uVar6 = 0x60;
LAB_14001897a:
          uVar1 = local_68;
          puVar7 = (uint *)ExAllocatePool2(0x100,uVar6,0x6661754c);
          if (puVar7 != (uint *)0x0) {
            *puVar7 = uVar16;
            *(undefined1 *)(puVar7 + 1) = 0xff;
            FltAcquirePushLockExclusiveEx(&PoolLock);
            DAT_14000c2a4 = DAT_14000c2a4 + uVar16;
            FltReleasePushLockEx(&PoolLock);
            _Dst_00 = puVar7 + 2;
            if (_Dst_00 != (uint *)0x0) {
              memset(_Dst_00,0,(ulonglong)uVar16);
              puVar9 = puVar7 + 0x18;
              if (uVar1 == 0) {
                *(undefined1 *)((longlong)puVar7 + 0x59) = 1;
              }
              else {
                sVar12 = uVar1 + *puVar15;
                *(short *)((longlong)puVar7 + 0x32) = sVar12;
                *(short *)(puVar7 + 0xc) = sVar12;
                *(uint **)(puVar7 + 0xe) = puVar9;
                memmove(puVar9,*(void **)(puVar15 + 4),(ulonglong)*puVar15);
                _Dst = (void *)((longlong)puVar9 + (ulonglong)*puVar15);
                *(ushort *)((longlong)puVar7 + 0x42) = local_68;
                *(ushort *)(puVar7 + 0x10) = local_68;
                *(void **)(puVar7 + 0x12) = _Dst;
                if (cVar4 == '\0') {
                  memmove(_Dst,PTR_u__VirtualStore__14000b090,(ulonglong)LuafvStoreRoot);
                  uVar1 = *(ushort *)(lVar3 + 0x58);
                  _Dst = (void *)((ulonglong)LuafvStoreRoot + (longlong)_Dst);
                  _Src = *(void **)(lVar3 + 0x60);
                }
                else {
                  uVar1 = *(ushort *)(lVar3 + 0x40);
                  _Src = *(void **)(lVar3 + 0x48);
                }
                memmove(_Dst,_Src,(ulonglong)uVar1);
              }
              *(longlong *)(puVar7 + 6) = lVar3;
              *(longlong *)(puVar7 + 10) = param_3;
              *(char *)(puVar7 + 0x16) = cVar4;
              if (*(char *)((longlong)puVar7 + 0x59) == '\0') {
                if ((cVar4 == '\0') &&
                   (iVar5 = LuafvCreateStoreRootPath(param_1,&local_60), iVar5 < 0))
                goto LAB_140018b55;
                uVar8 = LuafvCreateUserStorePath(param_1,local_60,(longlong)_Dst_00);
                iVar5 = (int)uVar8;
                if (local_60 != 0) {
                  FltClose();
                }
                if (iVar5 < 0) goto LAB_140018b55;
                uVar8 = LuafvFindTableNode(*(undefined **)(param_3 + 0x20),
                                           (ulonglong *)(puVar7 + 0x10),4,local_50);
                iVar5 = (int)uVar8;
                if (iVar5 < 0) goto LAB_140018b55;
                if ((char)local_30 == '\0') {
                  iVar5 = -0x3fffffff;
                  goto LAB_140018b55;
                }
                uVar6 = 2;
                *(longlong *)(puVar7 + 0x14) = local_50[0];
                *(byte *)(local_50[0] + 0x1c) = *(byte *)(local_50[0] + 0x1c) | 4;
                puVar9 = _Dst_00;
              }
              else {
                uVar6 = 1;
                puVar9 = (uint *)0x0;
              }
              iVar5 = 0;
              puVar7[8] = uVar6;
              *param_4 = puVar9;
              plVar10 = (longlong *)(lVar3 + 0x20);
              lVar11 = *plVar10;
              if (*(longlong **)(lVar11 + 8) != plVar10) {
                lVar11 = 3;
                pcVar2 = (code *)swi(0x29);
                iVar5 = 0;
                plVar10 = (longlong *)(*pcVar2)();
                puVar14 = auStack_80;
              }
              *(longlong *)_Dst_00 = lVar11;
              *(longlong **)(puVar7 + 4) = plVar10;
              *(uint **)(lVar11 + 8) = _Dst_00;
              *plVar10 = (longlong)_Dst_00;
              LOCK();
              *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + 1;
              UNLOCK();
              puVar13 = puVar14;
              goto LAB_1400188a3;
            }
          }
        }
        iVar5 = -0x3fffff66;
        puVar13 = auStack_88;
        goto LAB_1400188a3;
      }
    }
    FltReleasePushLockEx(&UserListLock,0);
    FltAcquirePushLockExclusiveEx(&UserListLock,0);
    cVar4 = '\x01';
  } while( true );
}



===== FindUser @ 140018c30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FindUser(longlong param_1,char param_2,undefined8 *param_3)

{
  uint *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  uint *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  longlong *plVar9;
  void *_Dst;
  undefined1 *puVar10;
  undefined1 *puVar11;
  longlong lVar12;
  uint *_Dst_00;
  bool bVar13;
  longlong local_res8;
  undefined8 local_res20;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [24];
  undefined8 *local_78;
  ulonglong local_70;
  void *local_68;
  longlong local_60 [5];
  
  plVar9 = local_60;
  local_60[0] = 0;
  local_60[1] = 0;
  local_res20 = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_70 = 0;
  local_res8 = 0;
  local_78 = (undefined8 *)0x0;
  local_68 = (void *)0x0;
  bVar13 = *(char *)(*(longlong *)(param_1 + 0x10) + 4) != '\0';
  if (bVar13) {
    SeCaptureSubjectContext(local_60);
  }
  else {
    plVar9 = (longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x20);
  }
  puVar11 = auStack_98;
  lVar12 = *plVar9;
  if (lVar12 == 0) {
    lVar12 = plVar9[2];
  }
  iVar5 = SeQueryInformationToken(lVar12,1,&local_78);
  puVar10 = auStack_98;
  if (-1 < iVar5) {
    iVar5 = SeQueryAuthenticationIdToken(lVar12,&local_res20);
    puVar10 = auStack_98;
    if (-1 < iVar5) {
      iVar5 = SeQueryServerSiloToken(lVar12,&local_res8);
      puVar10 = auStack_98;
      if (-1 < iVar5) {
        uVar2 = *local_78;
        for (puVar6 = UserList; (uint **)puVar6 != &UserList; puVar6 = *(uint **)puVar6) {
          cVar4 = RtlEqualSid(*(undefined8 *)(puVar6 + 0x14),uVar2);
          if ((cVar4 != '\0') && (*(longlong *)(puVar6 + 0xe) == local_res8)) {
            *(undefined8 *)(puVar6 + 4) = _DAT_fffff78000000014;
            *param_3 = puVar6;
            iVar5 = 0;
            puVar10 = auStack_98;
            goto LAB_140018d47;
          }
        }
        if (param_2 == '\0') {
          *param_3 = 0;
          iVar5 = 0;
          puVar10 = auStack_98;
        }
        else {
          iVar5 = RtlConvertSidToUnicodeString(&local_70,uVar2,1);
          puVar10 = auStack_98;
          if (-1 < iVar5) {
            iVar5 = RtlLengthSid(uVar2);
            uVar8 = (ushort)local_70 + 0x68 + (iVar5 + 1U & 0xfffffffe);
            if (7 < uVar8 + 8) {
              puVar6 = (uint *)ExAllocatePool2(0x100,uVar8 + 8,0x6661754c);
              if (puVar6 != (uint *)0x0) {
                *puVar6 = uVar8;
                *(undefined1 *)(puVar6 + 1) = 0xff;
                FltAcquirePushLockExclusiveEx(&PoolLock);
                DAT_14000c2a4 = DAT_14000c2a4 + uVar8;
                FltReleasePushLockEx(&PoolLock);
                _Dst_00 = puVar6 + 2;
                if (_Dst_00 != (uint *)0x0) {
                  memset(_Dst_00,0,(ulonglong)uVar8);
                  puVar6[8] = 1;
                  *(undefined8 *)(puVar6 + 6) = _DAT_fffff78000000014;
                  puVar1 = puVar6 + 10;
                  *(uint **)(puVar6 + 0xc) = puVar1;
                  *(uint **)puVar1 = puVar1;
                  *(undefined8 *)(puVar6 + 0xe) = local_res20;
                  if (local_res8 != 0) {
                    ObfReferenceObjectWithTag(local_res8,0x6661754c);
                    *(longlong *)(puVar6 + 0x10) = local_res8;
                  }
                  puVar1 = puVar6 + 0x1c;
                  *(uint **)(puVar6 + 0x16) = puVar1;
                  RtlCopySid(iVar5,puVar1,uVar2);
                  *(ushort *)((longlong)puVar6 + 0x62) = (ushort)local_70;
                  _Dst = (void *)((longlong)puVar1 + ((ulonglong)(iVar5 + 1U) & 0xfffffffe));
                  *(ushort *)(puVar6 + 0x18) = (ushort)local_70;
                  *(void **)(puVar6 + 0x1a) = _Dst;
                  memmove(_Dst,local_68,local_70 & 0xffff);
                  puVar7 = &UserList;
                  if ((uint **)*(undefined8 **)(UserList + 2) != &UserList) {
                    puVar7 = (undefined8 *)0x3;
                    pcVar3 = (code *)swi(0x29);
                    UserList = (uint *)(*pcVar3)();
                    puVar11 = auStack_90;
                  }
                  *(undefined8 **)(puVar6 + 4) = puVar7;
                  *(uint **)_Dst_00 = UserList;
                  *(uint **)(UserList + 2) = _Dst_00;
                  UserList = _Dst_00;
                  *param_3 = _Dst_00;
                  *(undefined8 *)(puVar11 + -8) = 0x140018f55;
                  SeMarkLogonSessionForTerminationNotificationEx(&local_res20,local_res8);
                  *(undefined8 *)(puVar11 + -8) = 0x140018f5f;
                  LuafvRunScavenger();
                  iVar5 = 0;
                  puVar10 = puVar11;
                  goto LAB_140018d47;
                }
              }
            }
            iVar5 = -0x3fffff66;
            puVar10 = auStack_98;
          }
        }
      }
    }
  }
LAB_140018d47:
  if (bVar13) {
    *(undefined8 *)(puVar10 + -8) = 0x140018e1d;
    SeReleaseSubjectContext(local_60);
  }
  if (local_68 != (void *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x140018f98;
    ExFreePoolWithTag(local_68,0);
  }
  if (local_78 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x140018d6f;
    ExFreePoolWithTag(local_78,0);
  }
  return iVar5;
}



===== ClearFileTablePostWorker @ 140018fb0 =====

void ClearFileTablePostWorker(longlong param_1,ulonglong param_2)

{
  int *piVar1;
  bool bVar2;
  
  if (*(longlong *)(param_1 + 0x20) == 0) goto LAB_140019021;
  if ((param_2 & 1) == 0) {
    if ((*(byte *)(param_1 + 0x1e) & 2) == 0) {
      if ((*(longlong *)(param_1 + 0x28) != 0) &&
         (*(int *)(*(longlong *)(param_1 + 0x28) + 0x10) != 0)) goto LAB_140018ffa;
      bVar2 = false;
    }
    else {
      bVar2 = (param_2 & 2) == 0;
    }
  }
  else {
LAB_140018ffa:
    bVar2 = true;
  }
  RemoveTableNode(param_1,bVar2);
  if (bVar2 == false) {
    LuafvDereferenceTableNodeEx(param_1,'\x01','\0');
    return;
  }
LAB_140019021:
  if ((param_2 & 4) != 0) {
    *(ulonglong *)(param_1 + 0xa8) = (ulonglong)(*(byte *)(param_1 + 0xa8) & 7);
  }
  if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
    piVar1 = (int *)(param_1 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) {
      return;
    }
    *(undefined8 *)(param_1 + 8) = 0;
  }
  FltReleasePushLockEx(param_1,0);
  return;
}



===== LuafvEnumerateTable @ 140019078 =====

void LuafvEnumerateTable(longlong *param_1,char param_2)

{
  if (param_2 != '\0') {
    param_1[1] = 0;
  }
  LuafvEnumerateTableWithoutSplaying(param_1,param_1 + 1);
  return;
}



===== LuafvEnumerateTableWithoutSplaying @ 14001909c =====

longlong LuafvEnumerateTableWithoutSplaying(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if ((int)param_1[2] == 0) {
    lVar1 = 0;
  }
  else if (*param_2 == 0) {
    lVar1 = *param_1;
    for (lVar2 = *(longlong *)(*param_1 + 8); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 8)) {
      lVar1 = lVar2;
    }
    *param_2 = lVar1;
  }
  else {
    lVar1 = RtlRealSuccessor();
    if (lVar1 != 0) {
      *param_2 = lVar1;
    }
  }
  return lVar1;
}



===== LuafvEnumerateFileTable @ 1400190f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void LuafvEnumerateFileTable
               (longlong param_1,char param_2,undefined *param_3,undefined *param_4,
               undefined8 param_5)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (param_2 == '\0') {
    lVar5 = *(longlong *)(param_1 + 0x20);
    if (lVar5 != 0) {
      if (*(void **)(lVar5 + 8) == SystemReserved1[0xf]) {
        *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
      }
      else {
        FltAcquirePushLockExclusiveEx(lVar5);
        *(void **)(lVar5 + 8) = SystemReserved1[0xf];
        *(undefined4 *)(lVar5 + 0x10) = 1;
      }
    }
    if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    }
    else {
      FltAcquirePushLockExclusiveEx(param_1);
      *(void **)(param_1 + 8) = SystemReserved1[0xf];
      *(undefined4 *)(param_1 + 0x10) = 1;
    }
  }
  lVar5 = param_1;
  do {
    if (param_3 != (undefined *)0x0) {
      (*(code *)param_3)(lVar5);
    }
    plVar2 = *(longlong **)(lVar5 + 0x28);
    if (plVar2 == (longlong *)0x0) {
      lVar4 = 0;
    }
    else {
      plVar2[1] = 0;
      lVar4 = LuafvEnumerateTableWithoutSplaying(plVar2,plVar2 + 1);
      while ((lVar4 != 0 && ((*(byte *)(lVar4 + 0x18) & 7) == 1))) {
        lVar4 = LuafvEnumerateTable(plVar2,'\0');
      }
    }
LAB_1400191f4:
    if (lVar4 == 0) {
      lVar3 = *(longlong *)(lVar5 + 0x20);
      if (param_4 == (undefined *)0x0) {
        if ((lVar5 == param_1) && (param_2 != '\0')) {
          return;
        }
        if (*(void **)(lVar5 + 8) == SystemReserved1[0xf]) {
          piVar1 = (int *)(lVar5 + 0x10);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 != 0) goto LAB_140019251;
          *(undefined8 *)(lVar5 + 8) = 0;
        }
        FltReleasePushLockEx(lVar5,0);
      }
      else {
        (*(code *)param_4)(lVar5,param_5);
      }
LAB_140019251:
      if (lVar5 == param_1) {
        if ((param_2 == '\0') && (lVar3 != 0)) {
          if (*(void **)(lVar3 + 8) == SystemReserved1[0xf]) {
            piVar1 = (int *)(lVar3 + 0x10);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 != 0) {
              return;
            }
            *(undefined8 *)(lVar3 + 8) = 0;
          }
          FltReleasePushLockEx(lVar3,0);
        }
        return;
      }
      plVar2 = *(longlong **)(lVar3 + 0x28);
      do {
        lVar4 = LuafvEnumerateTableWithoutSplaying(plVar2,plVar2 + 1);
        lVar5 = lVar3;
        if (lVar4 == 0) break;
      } while ((*(byte *)(lVar4 + 0x18) & 7) == 1);
      goto LAB_1400191f4;
    }
    lVar5 = lVar4 + -0x30;
    if (*(void **)(lVar4 + -0x28) == SystemReserved1[0xf]) {
      *(int *)(lVar4 + -0x20) = *(int *)(lVar4 + -0x20) + 1;
    }
    else {
      FltAcquirePushLockExclusiveEx(lVar5);
      *(void **)(lVar4 + -0x28) = SystemReserved1[0xf];
      *(undefined4 *)(lVar4 + -0x20) = 1;
    }
  } while( true );
}



===== LuafvLogDeleteFilePCAEvent @ 140019324 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvLogDeleteFilePCAEvent(longlong param_1)

{
  undefined1 auStackY_c8 [32];
  longlong local_88 [14];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  memset(local_88,0,0x70);
  LuafvLogFileEvent(param_1,0,0,0,&LuafvDeleteFileAccessDeniedEvent,local_88,7);
  return;
}



===== LuafvPostCreate @ 1400193a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 LuafvPostCreate(longlong param_1,longlong param_2,ulonglong *param_3)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  ushort *puVar5;
  longlong lVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  byte local_res18 [8];
  char local_38;
  char local_37 [15];
  
  puVar5 = (ushort *)*param_3;
  local_38 = '\0';
  iVar7 = *(int *)(param_1 + 0x18);
  if (puVar5 == (ushort *)0x0) {
    if (iVar7 != -0x3fffffde) goto LAB_1400193e6;
    if ((int)param_3[2] != 0) {
      LuafvLogExclusion(param_1,0,(longlong *)param_3,(int)param_3[2]);
    }
  }
  else {
    if (-1 < iVar7) {
      if (iVar7 == 0x104) {
        LuafvRemoveEcp(param_1);
      }
      else {
        pbVar1 = (byte *)((longlong)param_3 + 0x14);
        if ((*pbVar1 & 10) != 0) {
          if ((*pbVar1 & 4) != 0) {
            FltDeleteContext(param_3);
            *pbVar1 = *pbVar1 & 0xfb;
          }
          iVar7 = FltSetStreamHandleContext
                            (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),1,
                             param_3,0);
          if (iVar7 < 0) {
            LuafvLogFileError(param_1,0,&LuafvSetStreamHandleContextFailed,iVar7);
            FltCancelFileOpen(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
            *(undefined8 *)(param_1 + 0x20) = 0;
            *(int *)(param_1 + 0x18) = iVar7;
          }
          bVar2 = *pbVar1;
          *pbVar1 = bVar2 | 4;
          if (((bVar2 & 2) != 0) && (*(longlong *)(param_1 + 0x20) == 2)) {
            *(byte *)((longlong)param_3 + 0x14) = bVar2 | 0x24;
            LuafvUpdateFileTableForFileChange
                      ((ulonglong *)(puVar5 + 0x18),*(longlong *)(puVar5 + 0x28));
            if ((DAT_14000c0f8 & 1) != 0) {
              LuafvLogVirtualCreate(param_1,(longlong *)param_3);
            }
          }
        }
      }
      goto LAB_1400193e6;
    }
    bVar2 = *(byte *)((longlong)param_3 + 0x14);
    if (((bVar2 & 2) != 0) ||
       ((((uint)param_3[2] != 0 && ((bVar2 & 0x10) == 0)) && ((DAT_14000c0f8 & 8) == 0)))) {
      if ((((DAT_14000c0f8 & 4) != 0) && (((uint)param_3[2] >> 10 & 1) != 0)) &&
         (iVar7 == -0x3fffffde)) {
        LuafvLogExclusion(param_1,0,(longlong *)param_3,(uint)param_3[2]);
      }
      goto LAB_1400193e6;
    }
    local_37[0] = '\0';
    if (iVar7 != -0x3fffffde) {
      if ((iVar7 != -0x3fffffc6) || ((puVar5[0x2c] & 2) == 0)) goto LAB_1400193e6;
      if (((DAT_14000c0f8 & 8) != 0) && (((uint)param_3[2] >> 10 & 1) != 0)) {
        *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
        goto LAB_1400193e6;
      }
LAB_1400196a9:
      *(byte *)((longlong)param_3 + 0x14) = *(byte *)((longlong)param_3 + 0x14) | 2;
      uVar10 = LuafvReparse(param_1,(longlong *)param_3,'\x01');
      if ((int)uVar10 < 0) {
        *(int *)(param_1 + 0x18) = (int)uVar10;
        *(undefined8 *)(param_1 + 0x20) = 0;
      }
      goto LAB_1400193e6;
    }
    lVar6 = *(longlong *)(param_1 + 0x10);
    local_res18[0] = 0;
    uVar4 = *(uint *)(*(longlong *)(lVar6 + 0x18) + 0x10);
    if ((DAT_14000c0f8 & 8) == 0) {
LAB_140019579:
      if ((bVar2 & 1) == 0) goto LAB_14001959e;
      cVar3 = *(char *)(lVar6 + 0x23);
      if ((_DAT_14000c0f0 & *(uint *)(*(longlong *)(lVar6 + 0x18) + 0x10)) == 0) {
        if (cVar3 != '\x01') goto LAB_140019790;
        local_res18[0] = 0;
        goto LAB_14001959e;
      }
      if (cVar3 == '\x01') {
LAB_140019607:
        local_res18[0] = 1;
      }
      else {
LAB_140019790:
        local_res18[0] = 0;
        if (cVar3 == '\x03') goto LAB_140019607;
      }
LAB_14001960c:
      iVar7 = LuafvCheckAdminAccess(param_1,*(undefined8 *)(param_2 + 0x18),puVar5,&local_38);
      if (iVar7 < 0) {
        LuafvLogFileError(param_1,(longlong)puVar5,&LuafvAdminAccessCheckFailed,iVar7);
      }
      else {
        if ((DAT_14000c0f8 & 8) == 0) {
LAB_140019638:
          if ((local_38 == '\0') && ((DAT_14000c0f8 & 8) == 0)) goto LAB_140019692;
        }
        else if (local_38 == '\0') {
          *(uint *)(param_3 + 2) = (uint)param_3[2] | 0x20;
          goto LAB_140019638;
        }
        if (((puVar5[0x14] & 8) == 0) ||
           (((puVar5[0x14] & 4) != 0 || ((*(uint *)(*(longlong *)(lVar6 + 0x18) + 0x10) & 6) == 0)))
           ) {
          uVar9 = LuafvDelayOrVirtualizeFile
                            (param_1,param_2,param_3,local_res18,local_37,(uint *)(param_3 + 2));
          if ((int)uVar9 < 0) {
            *(int *)(param_1 + 0x18) = (int)uVar9;
            *(undefined8 *)(param_1 + 0x20) = 0;
          }
          else if (local_res18[0] != 0) {
            *(byte *)((longlong)param_3 + 0x14) = *(byte *)((longlong)param_3 + 0x14) | 0x80;
          }
        }
        else if ((DAT_14000c0f8 & 8) != 0) {
          *(uint *)(param_3 + 2) = (uint)param_3[2] | 0x200;
        }
      }
LAB_140019692:
      if (((int)param_3[2] != 0) && ((DAT_14000c0f8 & 8) != 0)) {
        LuafvLogExclusion(param_1,(longlong)puVar5,(longlong *)param_3,(int)param_3[2]);
      }
      if (local_37[0] != '\0') goto LAB_1400196a9;
    }
    else {
      if ((bVar2 & 1) != 0) {
        uVar8 = *(uint *)(lVar6 + 0x20) >> 0x18;
        if ((_DAT_14000c0f0 & uVar4) == 0) {
          if (uVar8 == 1) {
            if ((uVar4 & 0xd0156) != 0) {
              *(uint *)(param_3 + 2) = (uint)param_3[2] | 0x80;
            }
            goto LAB_140019579;
          }
LAB_14001977e:
          local_res18[0] = 0;
          if (uVar8 != 3) goto LAB_140019579;
        }
        else if (uVar8 != 1) goto LAB_14001977e;
        local_res18[0] = 1;
        goto LAB_140019579;
      }
LAB_14001959e:
      if (((DAT_14000c0f8 & 8) != 0) &&
         (((*(uint *)(*(longlong *)(lVar6 + 0x18) + 0x10) & 0xd0156) != 0 ||
          ((*(uint *)(lVar6 + 0x20) & 0xff000000) != 0x1000000)))) goto LAB_14001960c;
    }
    if ((uVar4 & 0x10000) != 0) {
      LuafvLogDeleteFilePCAEvent(param_1);
    }
  }
  if ((*(byte *)((longlong)param_3 + 0x14) & 0x10) != 0) {
    LuafvLogWRPPCAEvent(param_1);
  }
LAB_1400193e6:
  FltReleaseContext(param_3);
  return 0;
}



===== LuafvLogExclusion @ 140019860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvLogExclusion(longlong param_1,longlong param_2,longlong *param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_118 [32];
  longlong local_d8 [2];
  longlong local_c8 [14];
  longlong *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  local_28 = local_res20;
  local_20 = 4;
  local_d8[0]._0_4_ = 0;
  local_30 = 1;
  local_38 = (char *)(*(longlong *)(param_1 + 0x10) + 4);
  if (param_3 == (longlong *)0x0) {
    if (*local_38 != '\0') {
      local_58 = local_d8;
      local_48 = (undefined4 *)local_d8;
      goto LAB_1400198c4;
    }
    param_3 = (longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
    local_48 = (undefined4 *)(*param_3 + 0x10);
  }
  else {
    local_48 = (undefined4 *)((longlong)param_3 + 0xc);
  }
  local_58 = param_3 + 1;
LAB_1400198c4:
  local_40 = 4;
  local_50 = 4;
  local_res20[0] = param_4;
  LuafvLogFileEvent(param_1,param_2,0,0,&LuafvExclusionEvent,local_c8,0xb);
  return;
}



===== LuafvPerformRename @ 140019944 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvPerformRename(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  byte bVar2;
  int extraout_EAX;
  int iVar3;
  uint uVar4;
  int extraout_EAX_00;
  ulonglong uVar5;
  int *piVar6;
  ushort uVar7;
  short sVar8;
  int iVar9;
  longlong lVar10;
  short *psVar11;
  undefined *puVar12;
  byte *pbVar13;
  bool bVar14;
  undefined1 auStackY_118 [32];
  uint local_d8;
  char local_d4;
  char local_d3 [3];
  int local_d0;
  ulonglong *local_c8;
  longlong *local_c0;
  uint local_b8;
  int local_b4;
  undefined8 local_b0;
  byte *pbStack_a8;
  undefined8 local_98;
  byte *pbStack_90;
  longlong local_88;
  ulonglong local_78;
  byte *pbStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_78 = 0;
  local_c8 = (ulonglong *)0x0;
  local_d8 = 0;
  pbVar13 = (byte *)0x0;
  pbStack_70 = (byte *)0x0;
  local_c0 = (longlong *)0x0;
  local_b8 = 0;
  local_48 = 0;
  local_b0 = 0;
  pbStack_a8 = (byte *)0x0;
  local_d3[0] = '\0';
  lVar10 = *(longlong *)(param_1 + 0x10);
  local_68 = 0;
  uStack_60 = 0;
  local_d0 = 4;
  local_58 = 0;
  uStack_50 = 0;
  local_88 = *(longlong *)(lVar10 + 8);
  pbVar1 = *(byte **)(lVar10 + 0x38);
  local_98 = 0;
  pbStack_90 = (byte *)0x0;
  if ((*(longlong *)(lVar10 + 0x28) == 0) &&
     ((*(uint *)(pbVar1 + 0x10) < 2 || (*(short *)(pbVar1 + 0x14) != 0x5c)))) {
    bVar14 = true;
    lVar10 = local_88;
  }
  else {
    bVar14 = false;
    lVar10 = *(longlong *)(lVar10 + 0x28);
  }
  if (lVar10 == 0) {
    local_d4 = '\0';
  }
  else {
    local_d4 = LuafvIsVirtualFileObject(*(longlong *)(param_2 + 0x18),lVar10);
  }
  if (bVar14) {
    LuafvGetNameFileObject(*(longlong *)(param_2 + 0x18),lVar10,&local_98);
    iVar3 = extraout_EAX_00;
    if (-1 < extraout_EAX_00) {
      uVar7 = (ushort)local_98;
      goto LAB_140019a13;
    }
LAB_140019bf4:
    iVar9 = local_d0;
LAB_140019b38:
    if (local_c0 != (longlong *)0x0) {
      FltReleaseContext();
    }
    if (iVar9 != 4) goto LAB_140019b4e;
  }
  else {
    uVar7 = *(ushort *)(pbVar1 + 0x10);
    pbStack_90 = pbVar1 + 0x14;
    local_98._0_4_ = CONCAT22(uVar7,uVar7);
LAB_140019a13:
    uVar5 = (ulonglong)(uint)(uVar7 >> 1);
    if (uVar7 >> 1 != 0) {
      do {
        if ((int)uVar5 == 0) break;
        uVar5 = (ulonglong)((int)uVar5 - 1);
      } while (*(short *)(pbStack_90 + uVar5 * 2) != 0x5c);
      sVar8 = uVar7 + (short)uVar5 * -2;
      pbStack_a8 = pbStack_90 + uVar5 * 2;
      local_98 = CONCAT62(local_98._2_6_,(short)uVar5 * 2);
      local_b0._0_4_ = CONCAT22(sVar8,sVar8);
    }
    if (bVar14) {
      pbStack_a8 = pbVar1 + 0x14;
      local_78 = local_98;
      pbStack_70 = pbStack_90;
      uVar7 = *(ushort *)(pbVar1 + 0x10);
      local_b0._0_4_ = CONCAT22(uVar7,uVar7);
      for (uVar5 = 0; (uint)uVar5 < (uint)(uVar7 >> 1); uVar5 = (ulonglong)((uint)uVar5 + 1)) {
        if ((*(short *)(pbStack_a8 + uVar5 * 2) == 0x5c) ||
           (*(short *)(pbStack_a8 + uVar5 * 2) == 0x3a)) {
          iVar3 = -0x3fffffcd;
          goto LAB_140019bf4;
        }
      }
    }
    else {
      LuafvGetNameFileObject(*(longlong *)(param_2 + 0x18),lVar10,&local_78);
      iVar3 = extraout_EAX;
      if (extraout_EAX < 0) goto LAB_140019bf4;
      if ((1 < (ushort)local_b0) && (*(short *)pbStack_a8 == 0x5c)) {
        pbStack_a8 = pbStack_a8 + 2;
        local_b0 = CONCAT62(local_b0._2_6_,(ushort)local_b0 - 2);
      }
    }
    bVar14 = local_d4 != '\0';
    iVar3 = FltQueryInformationFile(*(undefined8 *)(param_2 + 0x18),local_88,&local_68,0x28);
    if (iVar3 < 0) {
      puVar12 = &LuafvQueryInformationFailed;
LAB_140019bae:
      LuafvLogFileError(param_1,0,puVar12,iVar3);
      goto LAB_140019bf4;
    }
    uVar4 = bVar14 | 2;
    if ((local_48 & 0x10) == 0) {
      uVar4 = (uint)bVar14;
    }
    uVar5 = LuafvQueryStoreFile(*(undefined8 *)(param_2 + 0x18),param_1,&local_78,&local_b0,uVar4,
                                &local_c8,&local_b8,&local_d8);
    iVar3 = (int)uVar5;
    if (iVar3 < 0) {
      puVar12 = &LuafvQueryStoreFileFailed;
      goto LAB_140019bae;
    }
    if ((local_b8 & 2) != 0) {
      iVar3 = -0x3fffffde;
      goto LAB_140019bf4;
    }
    if (local_c8 == (ulonglong *)0x0) {
      iVar9 = 1;
      goto LAB_140019b38;
    }
    if (((((byte)local_c8[5] & 1) != 0) && (((byte)local_c8[0xb] & 1) != 0)) &&
       (((~(byte)local_c8[0xb] ^ ~(byte)local_c8[5]) & 4) != 0)) {
      local_d8 = local_d8 | 0x100;
    }
    iVar3 = (ushort)local_c8[6] + 0x14;
    uVar4 = (ushort)local_c8[6] + 0x1c;
    local_b4 = iVar3;
    if ((uVar4 < 8) || (piVar6 = (int *)ExAllocatePool2(0x100,uVar4), piVar6 == (int *)0x0)) {
LAB_140019bef:
      iVar3 = -0x3fffff66;
      goto LAB_140019bf4;
    }
    *piVar6 = iVar3;
    *(undefined1 *)(piVar6 + 1) = 0xff;
    FltAcquirePushLockExclusiveEx(&PoolLock,0);
    DAT_14000c2a4 = DAT_14000c2a4 + iVar3;
    FltReleasePushLockEx(&PoolLock,0);
    pbVar13 = (byte *)(piVar6 + 2);
    if (pbVar13 == (byte *)0x0) goto LAB_140019bef;
    bVar2 = *pbVar1;
    if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x20) == 0x41) {
      bVar2 = bVar2 & 1;
    }
    *pbVar13 = bVar2;
    bVar14 = false;
    piVar6[4] = 0;
    piVar6[5] = 0;
    lVar10 = *(longlong *)(param_2 + 0x20);
    if (lVar10 == 0) {
LAB_140019c8e:
      psVar11 = (short *)0x0;
      local_c0 = (longlong *)0x0;
LAB_140019c92:
      if (psVar11 == (short *)0x0) goto LAB_140019e03;
      bVar14 = (char)psVar11[0x7e] != '\0';
    }
    else {
      psVar11 = *(short **)(lVar10 + 0x18);
      if ((psVar11 != (short *)0x0) && (*psVar11 == 0x7666)) {
        local_c0 = *(longlong **)(psVar11 + 0x80);
        goto LAB_140019c92;
      }
      if ((*(longlong *)(param_2 + 0x18) == 0) ||
         (iVar3 = FltGetStreamHandleContext(*(longlong *)(param_2 + 0x18),lVar10,&local_c0),
         iVar3 < 0)) goto LAB_140019c8e;
      psVar11 = (short *)0x0;
LAB_140019e03:
      if (local_c0 != (longlong *)0x0) {
        bVar14 = (*(byte *)((longlong)local_c0 + 0x14) & 2) != 0;
      }
    }
    if ((local_d8 == 0) && ((local_c8[0xb] & 1) != 0)) goto LAB_140019cc1;
    uVar5 = *local_c8;
    piVar6[6] = (uint)(ushort)uVar5;
    memmove(piVar6 + 7,(void *)local_c8[1],(ulonglong)(uint)(ushort)uVar5);
    iVar3 = FltSetInformationFile(*(undefined8 *)(param_2 + 0x18),local_88);
    if (iVar3 < 0) {
      if ((iVar3 != -0x3fffffde) || (uVar5 = local_c8[5], (uVar5 & 1) == 0)) goto LAB_140019d9e;
      if (*pbVar1 == 0) {
        iVar3 = -0x3fffffcb;
      }
      else if ((((uVar5 & 4) == 0) && ((local_48 & 0x10) == 0)) && ((uVar5 & 8) == 0))
      goto LAB_140019d9e;
    }
    else {
      if (((DAT_14000c0f8 & 1) != 0) && (bVar14 != false)) {
        LuafvLogVirtualRename(param_1,local_c0,'\x01','\0');
      }
      LuafvUpdateFileTableForFileChange(local_c8,local_c8[4]);
LAB_140019d9e:
      if (local_d8 == 0) {
        if (iVar3 == -0x3fffffc6) {
          if ((local_c8[0xb] & 2) != 0) goto LAB_140019cc1;
        }
        else if (iVar3 == -0x3fffffde) {
LAB_140019cc1:
          iVar3 = LuafvCheckAdminAccess
                            (param_1,*(undefined8 *)(param_2 + 0x18),(ushort *)local_c8,local_d3);
          if (-1 < iVar3) {
            if (local_d3[0] == '\0') {
              iVar3 = -0x3fffffde;
              if ((DAT_14000c0f8 & 8) != 0) {
                local_d8 = local_d8 | 0x20;
              }
            }
            else if (bVar14 == false) {
              iVar3 = FltQueryInformationFile
                                (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                                 &local_68,0x28);
              if (iVar3 < 0) {
                LuafvLogFileError(param_1,0,&LuafvQueryInformationFailed,iVar3);
              }
              else {
                if ((local_48 & 0x10) == 0) goto LAB_14001a05b;
                local_d8 = local_d8 | 0x4000;
                iVar3 = -0x3fffffde;
              }
            }
            else {
LAB_14001a05b:
              if ((((local_c8[5] & 2) == 0) || ((local_c8[0xb] & 2) != 0)) ||
                 (iVar3 = LuafvCreateVirtualPath(*(undefined8 *)(param_2 + 0x18),param_1,local_c8),
                 -1 < iVar3)) {
                uVar5 = local_c8[6];
                piVar6[6] = (uint)(ushort)uVar5;
                memmove(piVar6 + 7,(void *)local_c8[7],(ulonglong)(uint)(ushort)uVar5);
                iVar3 = FltSetInformationFile
                                  (*(undefined8 *)(param_2 + 0x18),local_88,pbVar13,local_b4);
                if (-1 < iVar3) {
                  if ((DAT_14000c0f8 & 1) != 0) {
                    LuafvLogVirtualRename(param_1,local_c0,bVar14,'\x01');
                  }
                  LuafvUpdateFileTableForFileChange(local_c8 + 6,local_c8[10]);
                }
              }
            }
          }
        }
      }
    }
    iVar9 = local_d0;
    if (psVar11 == (short *)0x0) goto LAB_140019b38;
  }
  if (-1 < iVar3) {
    LuafvUpdateFileTableForFileObject
              ((longlong *)0x0,*(longlong *)(param_2 + 0x18),*(longlong *)(param_2 + 0x20));
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(int *)(param_1 + 0x18) = iVar3;
  if ((iVar3 == -0x3fffffde) &&
     ((((DAT_14000c0f8 & 8) != 0 && (local_d8 != 0)) ||
      (((DAT_14000c0f8 & 4) != 0 && ((local_d8 & 0x4400) != 0)))))) {
    LuafvLogExclusion(param_1,(longlong)local_c8,(longlong *)0x0,local_d8);
  }
LAB_140019b4e:
  if (pbVar13 != (byte *)0x0) {
    LuafvFreePool((longlong)pbVar13);
  }
  if (local_c8 != (ulonglong *)0x0) {
    LuafvFreeStoreFile((longlong)local_c8);
  }
  if (pbStack_70 != (byte *)0x0) {
    LuafvFreePool((longlong)pbStack_70);
  }
  return iVar9;
}



===== LuafvPreSetInformation @ 14001a120 =====

ulonglong LuafvPreSetInformation(longlong param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong unaff_RBX;
  short *psVar7;
  char local_res8 [8];
  uint local_res20 [2];
  longlong local_48 [2];
  
  lVar6 = *(longlong *)(param_1 + 0x10);
  local_48[0] = 0;
  local_res8[0] = '\0';
  iVar1 = *(int *)(lVar6 + 0x20);
  lVar2 = *(longlong *)(lVar6 + 8);
  if ((((((iVar1 == 4) && (lVar2 != 0)) && (*(short **)(lVar2 + 0x18) != (short *)0x0)) &&
       ((**(short **)(lVar2 + 0x18) == 0x7666 &&
        (plVar3 = *(longlong **)(lVar6 + 0x38), (int)plVar3[4] == 0)))) &&
      ((*plVar3 + 1U < 2 && ((plVar3[1] + 1U < 2 && (plVar3[2] + 1U < 2)))))) &&
     (plVar3[3] + 1U < 2)) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
    return unaff_RBX;
  }
  uVar5 = LuafvPreWrite(param_1,param_2,param_3);
  if ((int)uVar5 == 4) {
    return unaff_RBX;
  }
  if (((DisableVirt == '\0') && (lVar6 = IoGetTopLevelIrp(), lVar6 == 0)) &&
     ((iVar1 == 0x41 || (iVar1 == 10)))) {
    local_res20[0] = 0;
    iVar4 = LuafvQueryVirtualizationCaller(param_1,local_res8,local_res20);
    if (-1 < iVar4) {
      if (local_res8[0] == '\0') {
        if (((DAT_14000c0f8 & 8) != 0) && (local_res20[0] != 0)) {
          return unaff_RBX;
        }
      }
      else {
        iVar4 = LuafvPerformRename(param_1,param_2);
        if (iVar4 == 4) {
          *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = lVar2;
          return unaff_RBX;
        }
      }
    }
  }
  if ((((DAT_14000c0f8 & 1) == 0) && (iVar1 != 0x40)) && (iVar1 != 0xd)) {
    return unaff_RBX;
  }
  if (lVar2 == 0) {
LAB_14001a1bb:
    local_48[0] = 0;
  }
  else {
    psVar7 = *(short **)(lVar2 + 0x18);
    if ((psVar7 == (short *)0x0) || (*psVar7 != 0x7666)) {
      if ((*(longlong *)(param_2 + 0x18) == 0) ||
         (iVar4 = FltGetStreamHandleContext(*(longlong *)(param_2 + 0x18),lVar2,local_48), iVar4 < 0
         )) goto LAB_14001a1bb;
      psVar7 = (short *)0x0;
      if (local_48[0] == 0) {
        return unaff_RBX;
      }
      if ((*(byte *)(local_48[0] + 0x14) & 2) == 0) goto LAB_14001a1ca;
    }
    else {
      local_48[0] = *(longlong *)(psVar7 + 0x80);
      if ((char)psVar7[0x7e] == '\0') {
        return unaff_RBX;
      }
    }
    if ((iVar1 - 10U < 0x38) && ((0xc0000000000009U >> ((ulonglong)(iVar1 - 10U) & 0x3f) & 1) != 0))
    {
      FltReferenceContext();
      *param_3 = local_48[0];
    }
    if (psVar7 != (short *)0x0) {
      return unaff_RBX;
    }
  }
LAB_14001a1ca:
  if (local_48[0] != 0) {
    FltReleaseContext();
  }
  return unaff_RBX;
}



===== LuafvPreQueryOpen @ 14001a3b0 =====

undefined8 LuafvPreQueryOpen(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  char local_res20 [8];
  uint local_18 [4];
  
  local_18[0] = 0;
  uVar2 = 1;
  local_res20[0] = '\0';
  if (DisableVirt == '\0') {
    iVar1 = LuafvQueryVirtualizationCaller(param_1,local_res20,local_18);
    if (iVar1 < 0) {
      LuafvLogFileError(param_1,0,&LuafvQueryVirtualizationFailed,iVar1);
      if ((iVar1 == -0x3fffff66) || (iVar1 == -0x3fffffcd)) {
        *(undefined8 *)(param_1 + 0x20) = 0;
        uVar2 = 4;
        *(int *)(param_1 + 0x18) = iVar1;
      }
    }
    else if ((local_res20[0] != '\0') && (uVar2 = 1, (local_18[0] & 1) == 0)) {
      uVar2 = 6;
    }
  }
  return uVar2;
}



===== LuafvQueryVirtualizationCaller @ 14001a450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014001a540) */
/* WARNING: Removing unreachable block (ram,0x00014001a5b0) */
/* WARNING: Removing unreachable block (ram,0x00014001a5ba) */
/* WARNING: Removing unreachable block (ram,0x00014001a547) */
/* WARNING: Removing unreachable block (ram,0x00014001a5ce) */
/* WARNING: Removing unreachable block (ram,0x00014001a5e0) */
/* WARNING: Removing unreachable block (ram,0x00014001a549) */
/* WARNING: Removing unreachable block (ram,0x00014001a54e) */
/* WARNING: Removing unreachable block (ram,0x00014001a558) */

int LuafvQueryVirtualizationCaller(longlong param_1,undefined1 *param_2,uint *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  bool bVar4;
  undefined1 auStackY_138 [32];
  int local_f0 [2];
  longlong local_e8 [18];
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  plVar3 = local_e8;
  local_e8[0] = 0;
  local_e8[1] = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  bVar4 = *(char *)(*(longlong *)(param_1 + 0x10) + 4) != '\0';
  if (bVar4) {
    SeCaptureSubjectContext(local_e8);
  }
  else {
    plVar3 = (longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x20);
  }
  lVar2 = *plVar3;
  if (lVar2 == 0) {
    lVar2 = plVar3[2];
  }
  iVar1 = SeQueryInformationToken(lVar2);
  if (bVar4) {
    SeReleaseSubjectContext(local_e8);
  }
  if (iVar1 < 0) {
    local_58 = local_f0;
    local_50 = 4;
    local_f0[0] = iVar1;
    LuafvLogFileEvent(param_1,0,0,0,&LuafvQueryVirtualizationFailed,local_e8 + 4,8);
  }
  else {
    *param_2 = 0;
  }
  return iVar1;
}



===== LuafvPreCreate @ 14001a5f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvPreCreate(longlong param_1,longlong param_2,longlong *param_3)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int extraout_EAX;
  undefined4 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  byte bVar9;
  ushort *puVar10;
  byte bVar11;
  ulonglong *puVar12;
  short *psVar13;
  undefined *puVar14;
  byte bVar15;
  longlong lVar16;
  byte bVar17;
  byte bVar18;
  longlong *plVar19;
  byte bVar20;
  bool bVar21;
  int local_res18;
  undefined1 auStackY_1b8 [32];
  char local_178;
  byte local_177;
  byte local_176;
  char local_175;
  byte local_174 [4];
  uint local_170;
  byte local_16c [4];
  ushort *local_168;
  int local_160 [2];
  ulonglong *local_158;
  longlong *local_150;
  uint local_148 [2];
  longlong local_140;
  longlong *local_138;
  longlong local_130;
  longlong local_128;
  longlong local_120;
  undefined8 local_118;
  longlong lStack_110;
  ulonglong local_108;
  longlong local_100;
  longlong *local_f8;
  longlong local_f0 [5];
  longlong local_c8 [14];
  ulonglong **local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_138 = (longlong *)0x0;
  local_108 = 0;
  local_140 = 0;
  local_150 = (longlong *)0x0;
  bVar20 = 0;
  local_128 = 0;
  bVar15 = 0;
  bVar17 = 0;
  local_100 = 0;
  bVar9 = 0;
  local_168 = (ushort *)0x0;
  bVar11 = 1;
  local_148[0] = 0;
  local_118 = 0;
  lStack_110 = 0;
  local_170 = 0;
  local_16c[0] = 0;
  local_174[0] = 0;
  local_176 = 0;
  local_177 = 0;
  local_120 = param_2;
  local_f8 = param_3;
  FltGetEcpListFromCallbackData(LuafvDriverData,param_1,&local_140);
  if (local_140 == 0) {
LAB_14001a704:
    if ((DisableVirt == '\0') && (lVar6 = IoGetTopLevelIrp(), lVar6 == 0)) {
      if (((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0xd0156) != 0)
         || ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0xff000000) != 0x1000000)) {
        local_160[0] = -1;
        local_178 = '\0';
        local_175 = '\0';
        local_158 = (ulonglong *)0x0;
        if (*(char *)(param_1 + 0x50) == '\0') {
          local_178 = '\x01';
LAB_14001b059:
          if (local_178 != '\0') goto LAB_14001a74e;
        }
        else {
          local_130 = FltGetRequestorProcess(param_1);
          if (local_130 == 0) {
LAB_14001b066:
            iVar4 = 0;
            local_178 = '\x01';
          }
          else {
            iVar4 = FltGetRequestorSessionId(param_1,local_160);
            if (-1 < iVar4) {
              if (0xfffffffd < local_160[0] - 1U) goto LAB_14001b066;
              iVar4 = SeLocateProcessImageName(local_130,&local_158);
              if (-1 < iVar4) {
                cVar2 = RtlPrefixUnicodeString(&DAT_14000c118,local_158);
                if (cVar2 == '\0') {
                  iVar4 = 0;
                }
                else {
                  uVar7 = LuafvIsFileWRP(local_158,param_2,(undefined *)0x0,&local_175);
                  iVar4 = (int)uVar7;
                  local_178 = local_175;
                  if (-1 < iVar4) {
                    iVar4 = 0;
                  }
                }
              }
            }
          }
          if (local_158 != (ulonglong *)0x0) {
            ExFreePoolWithTag(local_158,0);
          }
          if (-1 < iVar4) goto LAB_14001b059;
        }
        uVar7 = LuafvIsTargetWRP(param_1,param_2,&local_176);
        iVar4 = (int)uVar7;
        if (iVar4 < 0) {
          if ((iVar4 != -0x3fffffcd) && (iVar4 != -0x3fffffde)) {
            LuafvLogFileError(param_1,0,&LuafvIsTargetWRPFailed,iVar4);
          }
        }
        else {
          bVar9 = local_176;
        }
      }
LAB_14001a74e:
      plVar19 = local_f0;
      local_160[0] = 0;
      local_f0[0] = 0;
      local_f0[1] = 0;
      local_f0[2] = 0;
      local_f0[3] = 0;
      bVar21 = *(char *)(*(longlong *)(param_1 + 0x10) + 4) != '\0';
      if (bVar21) {
        SeCaptureSubjectContext(local_f0);
      }
      else {
        plVar19 = (longlong *)
                  (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x20);
      }
      local_130 = *plVar19;
      local_176 = bVar21;
      iVar4 = SeQueryInformationToken();
      if (local_176 != 0) {
        SeReleaseSubjectContext();
      }
      lVar6 = local_120;
      if (iVar4 < 0) {
        local_58 = &local_158;
        local_50 = 4;
        local_158._0_4_ = iVar4;
        LuafvLogFileEvent(param_1,0,0,0,&LuafvQueryVirtualizationFailed,local_c8,8);
        local_58 = &local_158;
        local_158 = (ulonglong *)CONCAT44(local_158._4_4_,iVar4);
        local_50 = 4;
        LuafvLogFileEvent(param_1,0,0,0,&LuafvQueryVirtualizationFailed,local_c8,8);
        goto LAB_14001ab8d;
      }
      bVar18 = 0;
      if (local_160[0] != 0) {
        if (((*(char *)(param_1 + 0x50) == '\x01') || ((DAT_14000c0f4 & 2) != 0)) ||
           ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 5) == 5)) {
          bVar18 = 1;
        }
        else {
          local_170 = local_170 | 1;
          if ((DAT_14000c0f8 & 8) == 0) goto LAB_14001a7d6;
        }
        if ((local_130 != 0) && ((DAT_14000c0f4 & 4) == 0)) {
          bVar18 = 0;
          local_170 = local_170 | 2;
        }
      }
LAB_14001a7d6:
      if (bVar18 == 0) {
        if (bVar9 == 0) {
          if (((DAT_14000c0f8 & 8) == 0) || (local_170 == 0)) goto LAB_14001a7fb;
          goto LAB_14001a8c3;
        }
LAB_14001ac09:
        iVar4 = LuafvCreateStreamHandleContext(&local_138);
        plVar19 = local_138;
        if (iVar4 < 0) {
          puVar14 = &LuafvCreateStreamHandleContextFailed;
          puVar10 = local_168;
          goto LAB_14001ad82;
        }
        *local_138 = (longlong)local_168;
        local_168 = (ushort *)0x0;
        *(undefined4 *)(local_138 + 1) = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
        *(undefined4 *)((longlong)local_138 + 0xc) =
             *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10);
        *(uint *)(local_138 + 2) = local_170;
        *(undefined4 *)((longlong)local_138 + 0x14) = 0;
        *(byte *)((longlong)local_138 + 0x14) = bVar18;
        *(byte *)((longlong)local_138 + 0x14) =
             (bVar9 & 1) << 4 | (bVar17 & 1) << 3 | (bVar20 & 1) * '\x02' | bVar18;
        bVar9 = (byte)(*(uint *)(local_138 + 1) >> 9) & 8 |
                *(byte *)((longlong)local_138 + 0x15) & 0xf7;
        *(byte *)((longlong)local_138 + 0x15) = bVar9;
        if (*(char *)(param_1 + 0x50) != '\x01') {
          *(byte *)((longlong)local_138 + 0x15) = bVar9 | 1;
        }
        if (local_177 == 0) {
          *local_f8 = (longlong)local_138;
          goto LAB_14001a7fb;
        }
        uVar8 = LuafvReparse(param_1,local_138,bVar20);
        iVar4 = (int)uVar8;
        FltReleaseContext(plVar19);
        if (-1 < iVar4) goto LAB_14001a7fb;
      }
      else {
LAB_14001a8c3:
        if ((local_170 & 1) != 0) goto LAB_14001ac09;
        bVar21 = false;
        if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x2000) != 0) {
          local_170 = local_170 | 4;
          if ((DAT_14000c0f8 & 8) != 0) goto LAB_14001a8e3;
LAB_14001ae2f:
          if (((DAT_14000c0f8 & 8) == 0) && (bVar9 == 0)) goto LAB_14001a7fb;
          goto LAB_14001ac09;
        }
        bVar21 = true;
LAB_14001a8e3:
        lVar16 = *(longlong *)(local_120 + 0x20);
        if ((*(uint *)(lVar16 + 0x50) & 0x800) != 0) {
          local_170 = local_170 | 8;
          goto LAB_14001ae2f;
        }
        if (!bVar21) goto LAB_14001ae2f;
        local_158 = *(ulonglong **)(lVar16 + 0x40);
        if (local_158 == (ulonglong *)0x0) {
          local_176 = 0;
        }
        else {
          iVar4 = LuafvGetNameFileObject
                            (*(longlong *)(local_120 + 0x18),(longlong)local_158,&local_108);
          bVar11 = (byte)iVar4;
          if (extraout_EAX < 0) goto LAB_14001a7fb;
          local_176 = LuafvIsVirtualFileObject(*(longlong *)(lVar6 + 0x18),(longlong)local_158);
          lVar16 = *(longlong *)(lVar6 + 0x20);
        }
        puVar12 = &local_108;
        if (local_158 == (ulonglong *)0x0) {
          puVar12 = (ulonglong *)0x0;
        }
        uVar7 = LuafvQueryStoreFile(*(undefined8 *)(lVar6 + 0x18),param_1,puVar12,
                                    (ulonglong *)(lVar16 + 0x58),(uint)(local_176 != 0),&local_168,
                                    local_148,&local_170);
        iVar4 = (int)uVar7;
        if (-1 < iVar4) {
          local_177 = (byte)local_148[0] & bVar11;
          if ((local_148[0] & 2) != 0) {
            uVar5 = 0xc0000022;
            if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0xff000000) == 0x1000000) {
              uVar5 = 0xc0000034;
            }
            *(undefined4 *)(param_1 + 0x18) = uVar5;
            *(undefined8 *)(param_1 + 0x20) = 0;
            if (((DAT_14000c0f8 & 4) != 0) || ((DAT_14000c0f8 & 8) != 0)) {
              LuafvLogExclusion(param_1,(longlong)local_168,(longlong *)0x0,local_170);
            }
            goto LAB_14001a7fb;
          }
          if (local_168 == (ushort *)0x0) {
            if ((((DAT_14000c0f8 & 4) == 0) || ((local_170 & 0x400) == 0)) && (bVar9 == 0))
            goto LAB_14001a804;
            goto LAB_14001ac09;
          }
          bVar17 = bVar15;
          if (local_177 == 0) {
            if ((local_170 == 0) || ((DAT_14000c0f8 & 8) != 0)) {
              iVar4 = LuafvSelectFile(param_1,local_120,local_168,local_16c,local_174,&local_170);
              if (iVar4 < 0) {
                if (iVar4 != -0x3fffffcd) {
                  LuafvLogFileError(param_1,(longlong)local_168,&LuafvSelectFileFailed,iVar4);
                }
                goto LAB_14001ab8d;
              }
              local_177 = 0;
              bVar20 = local_16c[0];
              bVar17 = local_174[0];
              if (local_16c[0] != local_176) {
                local_177 = bVar11;
                goto LAB_14001abf9;
              }
            }
            else {
              bVar15 = (byte)local_168[0x14] >> 2 & bVar11;
              if (((bVar15 != 0) && ((bVar11 & (byte)local_168[0x2c]) != 0)) &&
                 (bVar15 == ((byte)local_168[0x2c] >> 2 & bVar11))) {
                bVar17 = bVar11;
              }
            }
            if ((DAT_14000c0f8 & 8) == 0) {
              if ((local_170 == 0) || (bVar17 != 0)) goto LAB_14001ac09;
              if (bVar9 == 0) goto LAB_14001a7fb;
            }
          }
          else {
            bVar15 = (byte)local_168[0x14] >> 2 & bVar11;
            if (((bVar15 != 0) && ((bVar11 & (byte)local_168[0x2c]) != 0)) &&
               (bVar17 = 0, bVar15 == ((byte)local_168[0x2c] >> 2 & bVar11))) {
              bVar17 = bVar11;
            }
          }
LAB_14001abf9:
          if ((((DAT_14000c0f8 & 8) != 0) && (bVar17 != 0)) && ((local_170 & 0xfffffd4f) != 0)) {
            bVar17 = 0;
          }
          goto LAB_14001ac09;
        }
        if ((iVar4 == -0x3fffffde) || (iVar4 == -0x3fffffcd)) goto LAB_14001ab8d;
        puVar14 = &LuafvQueryStoreFileFailed;
        puVar10 = (ushort *)0x0;
LAB_14001ad82:
        LuafvLogFileError(param_1,(longlong)puVar10,puVar14,iVar4);
      }
LAB_14001ab8d:
      if ((iVar4 == -0x3fffff66) || (iVar4 == -0x3fffffcd)) {
        *(int *)(param_1 + 0x18) = iVar4;
        *(undefined8 *)(param_1 + 0x20) = 0;
      }
    }
  }
  else {
    iVar4 = FltFindExtraCreateParameter
                      (LuafvDriverData,local_140,&GUID_ECP_PREFETCH_OPEN,&local_150);
    if ((-1 < iVar4) && (cVar2 = FltIsEcpFromUserMode(LuafvDriverData,local_150), cVar2 == '\0')) {
      return local_res18;
    }
    iVar4 = FltFindExtraCreateParameter(LuafvDriverData,local_140,&LuafvEcpType);
    if (iVar4 < 0) goto LAB_14001a704;
    cVar2 = FltIsEcpFromUserMode(LuafvDriverData,local_150);
    if (cVar2 != '\0') {
LAB_14001af1b:
      LuafvRemoveEcp(param_1);
      goto LAB_14001a704;
    }
    if ((*(uint *)(*local_150 + 0x10) != 0) && ((DAT_14000c0f8 & 8) == 0)) {
      if ((DAT_14000c0f8 & 4) == 0) {
        return local_res18;
      }
      if ((*(uint *)(*local_150 + 0x10) >> 10 & 1) == 0) {
        return local_res18;
      }
    }
    if (*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x40) != 0) goto LAB_14001af1b;
    iVar4 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_128);
    if (-1 < iVar4) {
      lVar6 = *(longlong *)*local_150;
      psVar13 = (short *)(lVar6 + 0x40);
      if ((*(byte *)(*local_150 + 0x14) & 2) == 0) {
        psVar13 = (short *)(lVar6 + 0x10);
      }
      uVar1 = *(ushort *)(*(longlong *)(local_128 + 0x18) + 0x38);
      sVar3 = *psVar13 - uVar1;
      local_118._0_4_ = CONCAT22(sVar3,sVar3);
      lStack_110 = (ulonglong)uVar1 + *(longlong *)(psVar13 + 4);
      FltReleaseContext(local_128);
      cVar2 = RtlEqualUnicodeString(&local_118,*(longlong *)(param_2 + 0x20) + 0x58,1);
      if (cVar2 != '\0') {
        FltReferenceContext(*local_150);
        *param_3 = *local_150;
        return local_res18;
      }
      goto LAB_14001af1b;
    }
  }
LAB_14001a7fb:
  if (local_168 != (ushort *)0x0) {
    LuafvFreeStoreFile((longlong)local_168);
  }
LAB_14001a804:
  if (local_100 != 0) {
    LuafvFreePool(local_100);
  }
  return local_res18;
}



===== LuafvReparse @ 14001b0cc =====

undefined8 LuafvReparse(longlong param_1,longlong *param_2,char param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar2 = LuafvSetEcp(param_1,param_2);
  if (-1 < (int)uVar2) {
    lVar4 = *param_2 + 0x30;
    if (param_3 == '\0') {
      lVar4 = *param_2;
    }
    lVar3 = ExAllocatePool2(0x100,*(undefined2 *)(lVar4 + 0x10),0x6661754c);
    if (lVar3 == 0) {
      uVar2 = 0xc000009a;
      LuafvRemoveEcp(param_1);
    }
    else {
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
      if (*(longlong *)(lVar1 + 0x60) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar1 + 0x60),0);
      }
      *(undefined2 *)(lVar1 + 0x5a) = *(undefined2 *)(lVar4 + 0x10);
      *(longlong *)(lVar1 + 0x60) = lVar3;
      RtlCopyUnicodeString(lVar1 + 0x58,lVar4 + 0x10);
      *(undefined8 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0x104;
      FltSetCallbackDataDirty(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== LuafvIsTargetWRP @ 14001b1c0 =====

ulonglong LuafvIsTargetWRP(longlong param_1,longlong param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  short *psVar3;
  ushort uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong local_res8;
  short *local_res10;
  undefined8 local_58;
  uint *puStack_50;
  undefined8 local_48;
  longlong lStack_40;
  
  uVar1 = *(undefined8 *)(param_2 + 0x18);
  local_res8 = 0;
  uVar7 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  *param_3 = 0;
  local_58 = 0;
  puStack_50 = (uint *)0x0;
  local_48 = 0;
  lStack_40 = 0;
  if (((((uVar7 >> 0xd & 1) != 0) ||
       ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x800) != 0)) ||
      (*(short **)(lVar2 + 0x60) == (short *)0x0)) || (**(short **)(lVar2 + 0x60) == 0)) {
    uVar11 = 0;
    goto LAB_14001b36b;
  }
  cVar5 = RtlCreateUnicodeString(&local_48,L"windows");
  if (cVar5 != '\0') {
    psVar3 = *(short **)(lVar2 + 0x60);
    uVar4 = *(ushort *)(lVar2 + 0x58);
    local_res10 = psVar3 + 1;
    if (*psVar3 != 0x5c) {
      uVar4 = *(ushort *)(lVar2 + 0x58) + 2;
      local_res10 = psVar3;
    }
    if (7 < uVar4 + 8) {
      cVar5 = -1;
      uVar7 = (uint)uVar4;
      if (uVar7 < 0xb9) {
        uVar10 = 0;
        uVar6 = 0x38;
        do {
          if (uVar7 <= uVar6) break;
          uVar10 = uVar10 + 1;
          uVar6 = uVar6 + 0x20;
        } while (uVar10 < 5);
        puVar8 = (uint *)ExAllocateFromPagedLookasideList
                                   (&StringLookaside + (ulonglong)uVar10 * 0x80);
        cVar5 = (char)uVar10 + '\x02';
        if (cVar5 == -1) goto LAB_14001b2a7;
      }
      else {
LAB_14001b2a7:
        puVar8 = (uint *)ExAllocatePool2(0x100,uVar4 + 8,0x6661754c);
      }
      if (puVar8 != (uint *)0x0) {
        *puVar8 = uVar7;
        *(char *)(puVar8 + 1) = cVar5;
        FltAcquirePushLockExclusiveEx(&PoolLock,0);
        DAT_14000c2a4 = DAT_14000c2a4 + uVar7;
        FltReleasePushLockEx(&PoolLock,0);
        puStack_50 = puVar8 + 2;
        if (puStack_50 != (uint *)0x0) {
          local_58._0_4_ = CONCAT22(uVar4,uVar4 - 2);
          memmove(puStack_50,local_res10,(ulonglong)(ushort)(uVar4 - 2));
          *(undefined2 *)((longlong)puStack_50 + (local_58 >> 1 & 0x7fff) * 2) = 0;
          cVar5 = RtlPrefixUnicodeString(&local_48,&local_58,1);
          if (cVar5 != '\0') {
            uVar7 = FltGetInstanceContext(uVar1,&local_res8);
            uVar11 = (ulonglong)uVar7;
            if ((int)uVar7 < 0) goto LAB_14001b36b;
            uVar9 = LuafvIsFileWRP((ulonglong *)(lVar2 + 0x58),param_2,
                                   *(undefined **)(local_res8 + 0x20),param_3);
            uVar11 = uVar9 & 0xffffffff;
            if ((int)uVar9 < 0) {
              *param_3 = 0;
              goto LAB_14001b36b;
            }
          }
          uVar11 = 0;
          goto LAB_14001b36b;
        }
      }
    }
  }
  uVar11 = 0xc000009a;
LAB_14001b36b:
  if (lStack_40 != 0) {
    RtlFreeUnicodeString(&local_48);
  }
  puVar8 = puStack_50;
  if (puStack_50 != (uint *)0x0) {
    FltAcquirePushLockExclusiveEx(&PoolLock,0);
    DAT_14000c2a4 = DAT_14000c2a4 - puVar8[-2];
    FltReleasePushLockEx(&PoolLock,0);
    if ((byte)puVar8[-1] < 7) {
      ExFreeToPagedLookasideList
                (*(undefined8 *)(&LookasideLists + (ulonglong)(byte)puVar8[-1] * 8),puVar8 + -2);
    }
    else {
      ExFreePoolWithTag(puVar8 + -2,0x6661754c);
    }
  }
  if (local_res8 != 0) {
    FltReleaseContext();
  }
  return uVar11;
}



===== LuafvQueryStoreFile @ 14001b500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LuafvQueryStoreFile(undefined8 param_1,longlong param_2,ulonglong *param_3,
                             ulonglong *param_4,uint param_5,undefined8 *param_6,uint *param_7,
                             uint *param_8)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong *puVar10;
  short sVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  uint *puVar16;
  char cVar17;
  ushort uVar18;
  byte bVar19;
  byte bVar20;
  longlong lVar21;
  ushort uVar22;
  short *psVar23;
  byte bVar24;
  ushort *puVar25;
  longlong lVar26;
  bool bVar27;
  undefined1 auStackY_1b8 [32];
  byte local_176;
  char local_175;
  bool local_172;
  longlong local_170;
  ushort local_168;
  undefined1 auStack_166 [6];
  short *psStack_160;
  undefined *local_158;
  longlong local_150;
  longlong local_148;
  ushort auStack_140 [4];
  longlong local_138;
  undefined8 local_130;
  undefined8 local_128;
  longlong lStack_120;
  longlong local_118;
  undefined8 local_110;
  longlong lStack_108;
  undefined8 local_100;
  longlong lStack_f8;
  longlong local_f0;
  longlong local_e8;
  ushort auStack_e0 [4];
  longlong local_d8;
  undefined8 local_d0;
  ulonglong local_c8;
  short *psStack_c0;
  ulonglong local_b8;
  ulonglong uStack_b0;
  ulonglong *local_a8;
  undefined *local_a0;
  short *local_98;
  longlong local_90;
  ushort *local_88;
  undefined8 *local_80;
  uint *local_78;
  ulonglong *local_70;
  ulonglong *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_80 = param_6;
  local_78 = param_7;
  local_98 = (short *)0x0;
  puVar16 = (uint *)0x0;
  local_c8 = 0;
  psStack_c0 = (short *)0x0;
  lVar21 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  lVar26 = 0;
  _local_168 = 0;
  psStack_160 = (short *)0x0;
  local_130 = 0;
  local_128 = 0;
  lStack_120 = 0;
  local_d0 = 0;
  local_148 = 0;
  auStack_140[0] = 0;
  auStack_140[1] = 0;
  auStack_140[2] = 0;
  auStack_140[3] = 0;
  local_110 = 0;
  local_e8 = 0;
  auStack_e0[0] = 0;
  auStack_e0[1] = 0;
  auStack_e0[2] = 0;
  auStack_e0[3] = 0;
  local_100 = 0;
  local_60 = 0;
  local_170 = 0;
  local_118 = 0;
  local_150 = 0;
  local_f0 = 0;
  local_138 = 0;
  local_d8 = 0;
  local_172 = false;
  bVar6 = false;
  lStack_108 = 0;
  lStack_f8 = 0;
  bVar27 = false;
  bVar5 = false;
  bVar3 = true;
  if ((*(char *)(*(longlong *)(param_2 + 0x10) + 4) != '\0') ||
     (local_175 = '\x01', (*(byte *)(*(longlong *)(param_2 + 0x10) + 6) & 4) == 0)) {
    local_175 = '\0';
  }
  local_a8 = param_3;
  local_90 = param_2;
  uVar12 = FltGetInstanceContext(param_1);
  uVar13 = (ulonglong)uVar12;
  if ((int)uVar12 < 0) {
LAB_14001bf61:
    if (-1 < (int)uVar13) {
LAB_14001bef3:
      cVar17 = (char)local_130;
      goto LAB_14001bef7;
    }
  }
  else {
    local_88 = (ushort *)(*(longlong *)(local_98 + 0xc) + 0x38);
    local_a0 = *(undefined **)(local_98 + 0x10);
    psVar23 = local_98;
    uVar12 = LuafvFindUserStore(param_1,local_90,(longlong)local_98,&local_118);
    puVar10 = local_a8;
    lVar7 = local_118;
    uVar13 = (ulonglong)uVar12;
    if ((int)uVar12 < 0) {
      local_170 = local_118;
      goto LAB_14001bf61;
    }
    local_170 = local_118;
    if (local_118 == 0) goto LAB_14001bef3;
    local_158 = *(undefined **)(local_118 + 0x48);
    local_c8 = *param_4;
    psStack_c0 = (short *)param_4[1];
    if (local_a8 != (ulonglong *)0x0) {
      local_b8 = *local_a8;
      uStack_b0 = local_a8[1];
    }
    if (local_175 == '\0') {
      if ((param_5 & 2) == 0) {
        LuafvRemoveExtraStreamName((ushort *)&local_c8,&LuafvDataAttribute);
        goto LAB_14001b7a6;
      }
      LuafvRemoveExtraStreamName((ushort *)&local_c8,&LuafvIndexAllocationAttribute);
      bVar3 = true;
    }
    else {
      RtlInitUnicodeString(&local_168,0);
      psVar23 = psStack_c0;
      if (((ushort)local_c8 < 3) && (((ushort)local_c8 != 2 || (*psStack_c0 == 0x5c)))) {
        if (puVar10 != (ulonglong *)0x0) {
          uVar13 = (ulonglong)(uint)((ushort)local_b8 >> 1);
          psVar23 = (short *)(local_b8 & 0xffff);
          if ((ushort)local_b8 >> 1 != 0) {
            do {
              uVar12 = (int)uVar13 - 1;
              uVar13 = (ulonglong)uVar12;
              if (*(short *)(uStack_b0 + uVar13 * 2) == 0x5c) break;
            } while (uVar12 != 0);
            psStack_160 = (short *)(uStack_b0 + uVar13 * 2);
            uVar22 = (ushort)local_b8 + (short)uVar12 * -2;
            uVar18 = local_168 + uVar22;
            local_b8 = CONCAT62(local_b8._2_6_,(short)uVar12 * 2);
            _local_168 = CONCAT62(CONCAT42(auStack_166._2_4_,uVar18),uVar18);
            psVar23 = (short *)(ulonglong)uVar22;
            goto LAB_14001b742;
          }
        }
LAB_14001b73d:
        uVar18 = local_168;
      }
      else {
        uVar13 = (ulonglong)(uint)((ushort)local_c8 >> 1);
        if ((ushort)local_c8 >> 1 == 0) goto LAB_14001b73d;
        do {
          uVar12 = (int)uVar13 - 1;
          uVar13 = (ulonglong)uVar12;
          if (psStack_c0[uVar13] == 0x5c) break;
        } while (uVar12 != 0);
        psStack_160 = psStack_c0 + uVar13;
        uVar18 = local_168 + (ushort)local_c8 + (short)uVar12 * -2;
        local_c8 = CONCAT62(local_c8._2_6_,(short)uVar12 * 2);
        _local_168 = CONCAT62(CONCAT42(auStack_166._2_4_,uVar18),uVar18);
      }
LAB_14001b742:
      if ((1 < uVar18) && (*psStack_160 == 0x5c)) {
        psStack_160 = psStack_160 + 1;
        _local_168 = CONCAT62(auStack_166,uVar18 - 2);
      }
      if ((param_5 & 2) == 0) {
LAB_14001b7a6:
        if ((*(char *)(*(longlong *)(local_90 + 0x10) + 4) != '\0') ||
           ((*(uint *)(*(longlong *)(local_90 + 0x10) + 0x20) & 1) == 0)) {
          bVar3 = false;
          goto LAB_14001b7c1;
        }
      }
      bVar3 = true;
    }
LAB_14001b7c1:
    if ((local_175 != '\0') || (bVar3)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    bVar24 = 0;
    if ((param_5 & 1) != 0) {
      sVar11 = (ushort)local_b8 - *(ushort *)(lVar7 + 0x38);
      local_128._0_4_ = CONCAT22(sVar11,sVar11);
      lStack_120 = uStack_b0 + *(ushort *)(lVar7 + 0x38);
      local_70 = &local_128;
      local_68 = &local_c8;
      uVar15 = LuafvFindTableNodeEx(local_158,&local_70,psVar23,4,&local_f0);
      lVar26 = local_f0;
      uVar13 = uVar15 & 0xffffffff;
      bVar6 = true;
      if ((int)uVar15 < 0) goto LAB_14001bf61;
      if (((char)local_d0 == '\0') || ((*(byte *)(local_f0 + 0x1e) & 1) == 0)) {
        bVar4 = false;
        bVar27 = true;
        local_176 = 0;
      }
      else {
        bVar27 = (*(uint *)(local_f0 + 0x18) & 0x400) != 0;
        bVar4 = true;
        local_176 = 1;
        if (bVar27) {
          *param_8 = *param_8 | 0x1000;
        }
        if ((*(uint *)(local_f0 + 0x18) & 0x4000) != 0) {
          *param_8 = *param_8 | 0x2000;
          bVar27 = true;
        }
      }
      if ((!bVar3) && (bVar4)) {
        if (((*(uint *)(local_f0 + 0x18) & 0x10) == 0) && ((*(byte *)(local_f0 + 0x1d) & 1) != 0)) {
          *param_8 = *param_8 | 0x400;
          bVar27 = true;
        }
        bVar3 = true;
      }
      uVar13 = Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar13 == 0) {
        uVar14 = LuafvBuildTableNodeName
                           (local_e8,(longlong)local_158,(ushort *)(lVar7 + 0x28),auStack_e0,'\0',
                            (undefined2 *)&local_100);
        uVar12 = (uint)uVar14;
      }
      else {
        uVar14 = LuafvBuildTableNodeName2
                           (local_e8,(longlong)local_158,(ushort *)(lVar7 + 0x28),auStack_e0,'\0',
                            '\0',(undefined2 *)&local_100);
        uVar12 = (uint)uVar14;
      }
      uVar13 = (ulonglong)uVar12;
      if ((int)uVar12 < 0) goto LAB_14001bf85;
      sVar11 = (short)local_100 - *(ushort *)(lVar7 + 0x28);
      local_128._0_4_ = CONCAT22(sVar11,sVar11);
      lStack_120 = (ulonglong)*(ushort *)(lVar7 + 0x28) + lStack_f8;
      uVar15 = LuafvFindTableNode(local_a0,&local_128,0,&local_150);
      lVar21 = local_150;
      uVar13 = uVar15 & 0xffffffff;
      if ((int)uVar15 < 0) goto LAB_14001bf61;
      if ((*(byte *)(local_150 + 0x1c) != 0) && ((*(byte *)(local_150 + 0x1c) & 8) == 0)) {
        *param_8 = *param_8 | 0x10;
        bVar27 = true;
      }
      cVar17 = (char)local_130;
      if ((cVar17 == '\0') || ((*(byte *)(local_150 + 0x1e) & 1) == 0)) {
        bVar20 = 0;
      }
      else {
        bVar20 = 1;
      }
      if (!bVar3) {
        if (cVar17 == '\0') {
          uVar13 = LuafvIsExcludedName(auStack_140);
          bVar24 = (byte)uVar13;
          cVar17 = (char)local_130;
LAB_14001bccd:
          if (bVar24 != 0) {
            *param_8 = *param_8 | 0x400;
            bVar27 = true;
          }
        }
        else if (((*(byte *)(local_150 + 0x1e) & 1) == 0) ||
                ((*(uint *)(local_150 + 0x18) & 0x10) == 0)) {
          bVar24 = *(byte *)(local_150 + 0x1d) & 1;
          goto LAB_14001bccd;
        }
        bVar3 = true;
      }
      if ((((*param_8 >> 10 & 1) != 0) &&
          ((((cVar17 == '\0' || ((*(byte *)(*(longlong *)(lVar21 + 0x20) + 0x1e) & 1) == 0)) &&
            ((char)local_d0 != '\0')) && ((*(byte *)(*(longlong *)(lVar26 + 0x20) + 0x1e) & 1) != 0)
           ))) && (((DAT_14000c0f8 & 8) == 0 || ((*param_8 & 0x10) == 0)))) {
        bVar5 = true;
        bVar27 = false;
      }
      uVar13 = Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar13 == 0) {
        uVar14 = LuafvBuildTableNodeName
                           (local_148,0,(ushort *)0x0,auStack_140,'\0',(undefined2 *)&local_110);
        uVar12 = (uint)uVar14;
      }
      else {
        uVar14 = LuafvBuildTableNodeName2
                           (local_148,0,(ushort *)0x0,auStack_140,'\0','\0',(undefined2 *)&local_110
                           );
        uVar12 = (uint)uVar14;
      }
      uVar13 = (ulonglong)uVar12;
      if ((int)uVar12 < 0) goto LAB_14001bf85;
LAB_14001bd71:
      puVar16 = LuafvAllocatePool(1,0x78,'\x03');
      lVar9 = lStack_f8;
      lVar8 = lStack_108;
      if (puVar16 == (uint *)0x0) {
        uVar13 = 0xc000009a;
      }
      else {
        puVar16[0] = 0;
        puVar16[1] = 0;
        puVar16[2] = 0;
        puVar16[3] = 0;
        puVar16[8] = 0;
        puVar16[9] = 0;
        puVar16[10] = 0;
        puVar16[0xb] = 0;
        puVar16[0xc] = 0;
        puVar16[0xd] = 0;
        puVar16[0xe] = 0;
        puVar16[0xf] = 0;
        puVar16[0x10] = 0;
        puVar16[0x11] = 0;
        puVar16[0x12] = 0;
        puVar16[0x13] = 0;
        puVar16[0x14] = 0;
        puVar16[0x15] = 0;
        puVar16[0x16] = 0;
        puVar16[0x17] = 0;
        puVar16[0x18] = 0;
        puVar16[0x19] = 0;
        puVar16[0x1a] = 0;
        puVar16[0x1b] = 0;
        puVar16[0x1c] = 0;
        puVar16[0x1d] = 0;
        bVar24 = (byte)puVar16[10];
        lStack_108 = 0;
        bVar19 = bVar24 & 0xfe | bVar20;
        *(byte *)(puVar16 + 10) = bVar19;
        *(undefined8 *)(puVar16 + 4) = local_110;
        *(longlong *)(puVar16 + 6) = lVar8;
        if (bVar20 != 0) {
          bVar19 = (byte)(*(uint *)(lVar21 + 0x18) >> 2) & 4;
          *(byte *)(puVar16 + 10) = bVar19 | bVar24 & 0xfa | bVar20;
          bVar19 = (*(byte *)(lVar21 + 0x18) & 1) << 3 | bVar19 | bVar24 & 0xf2 | bVar20;
          *(byte *)(puVar16 + 10) = bVar19;
        }
        if ((char)local_130 != '\0') {
          local_150 = 0;
          cVar17 = *(char *)(*(longlong *)(lVar21 + 0x20) + 0x1e);
          *(longlong *)(puVar16 + 8) = lVar21;
          lVar21 = 0;
          *(byte *)(puVar16 + 10) = (cVar17 * '\x02' ^ bVar19) & 2 ^ bVar19;
        }
        bVar24 = (byte)puVar16[0x16];
        lStack_f8 = 0;
        bVar20 = bVar24 & 0xfe | local_176;
        *(byte *)(puVar16 + 0x16) = bVar20;
        *(undefined8 *)(puVar16 + 0x10) = local_100;
        *(longlong *)(puVar16 + 0x12) = lVar9;
        if (local_176 != 0) {
          bVar20 = (byte)(*(uint *)(lVar26 + 0x18) >> 2) & 4;
          *(byte *)(puVar16 + 0x16) = bVar20 | bVar24 & 0xfa | local_176;
          bVar20 = (*(byte *)(lVar26 + 0x18) & 1) << 3 | bVar20 | bVar24 & 0xf2 | local_176;
          *(byte *)(puVar16 + 0x16) = bVar20;
        }
        if ((char)local_d0 != '\0') {
          local_f0 = 0;
          cVar17 = *(char *)(*(longlong *)(lVar26 + 0x20) + 0x1e);
          *(longlong *)(puVar16 + 0x14) = lVar26;
          lVar26 = 0;
          *(byte *)(puVar16 + 0x16) = (cVar17 * '\x02' ^ bVar20) & 2 ^ bVar20;
        }
        puVar25 = &local_168;
        if (local_175 == '\0') {
          puVar25 = (ushort *)0x0;
        }
        uVar12 = LuafvCompleteStoreFileDetails(local_175,puVar25,(ushort *)puVar16);
        uVar13 = (ulonglong)uVar12;
        if (-1 < (int)uVar12) {
          uVar12 = LuafvCompleteStoreFileDetails(local_175,puVar25,(ushort *)(puVar16 + 0xc));
          uVar13 = (ulonglong)uVar12;
          if (-1 < (int)uVar12) {
            LOCK();
            *(int *)(lVar7 + 0x18) = *(int *)(lVar7 + 0x18) + 1;
            UNLOCK();
            local_170 = local_118;
            *(longlong *)(puVar16 + 0x1a) = local_118;
            lVar21 = local_150;
            lVar26 = local_f0;
          }
        }
        if (-1 < (int)uVar13) goto LAB_14001bef3;
        LuafvFreeStoreFile((longlong)puVar16);
      }
      goto LAB_14001bf85;
    }
    if (puVar10 == (ulonglong *)0x0) {
      uVar13 = LuafvFindTableNode(local_a0,&local_c8,0,&local_150);
      uVar12 = (uint)uVar13;
    }
    else {
      local_68 = &local_c8;
      local_70 = &local_b8;
      uVar13 = LuafvFindTableNodeEx(local_a0,&local_70,psVar23,0,&local_150);
      uVar12 = (uint)uVar13;
    }
    lVar21 = local_150;
    local_172 = puVar10 != (ulonglong *)0x0;
    uVar13 = (ulonglong)uVar12;
    if ((int)uVar12 < 0) goto LAB_14001bf85;
    if ((*(byte *)(local_150 + 0x1c) & 4) != 0) {
      if (local_130._2_1_ == '\0') {
        LuafvUpdateFileTableForFileChange((ulonglong *)0x0,local_150);
      }
      *param_8 = *param_8 | 0x800;
      if ((DAT_14000c0f8 & 8) == 0) goto LAB_14001bef3;
    }
    if ((((*(byte *)(lVar21 + 0x1c) != 0) && ((*(byte *)(lVar21 + 0x1c) & 8) == 0)) &&
        ((*param_8 = *param_8 | 0x10, (*(ushort *)(lVar21 + 0x1e) >> 8 & 1) == 0 &&
         ((DAT_14000c0f8 & 8) == 0)))) ||
       (((*(uint *)(lVar21 + 0x18) & 0x400) != 0 &&
        (*param_8 = *param_8 | 0x1000, (DAT_14000c0f8 & 8) == 0)))) goto LAB_14001bef3;
    cVar17 = (char)local_130;
    if ((cVar17 == '\0') || ((*(byte *)(lVar21 + 0x1e) & 1) == 0)) {
      bVar20 = 0;
    }
    else {
      bVar20 = 1;
    }
    if (bVar3) {
      if (bVar20 != 0) goto LAB_14001b8f3;
LAB_14001b910:
      uVar13 = Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar13 == 0) {
        uVar14 = LuafvBuildTableNodeName
                           (local_148,0,(ushort *)0x0,auStack_140,'\0',(undefined2 *)&local_110);
        uVar12 = (uint)uVar14;
      }
      else {
        uVar14 = LuafvBuildTableNodeName2
                           (local_148,0,(ushort *)0x0,auStack_140,'\0','\0',(undefined2 *)&local_110
                           );
        uVar12 = (uint)uVar14;
      }
      uVar13 = (ulonglong)uVar12;
      if ((int)uVar12 < 0) goto LAB_14001bf85;
      sVar11 = (short)local_110 - *local_88;
      local_128._0_4_ = CONCAT22(sVar11,sVar11);
      lStack_120 = (ulonglong)*local_88 + lStack_108;
      uVar15 = LuafvFindTableNode(local_158,&local_128,4,&local_f0);
      lVar26 = local_f0;
      uVar13 = uVar15 & 0xffffffff;
      if ((int)uVar15 < 0) goto LAB_14001bf61;
      cVar17 = (char)local_d0;
      if ((cVar17 == '\0') || (local_176 = 1, (*(byte *)(local_f0 + 0x1e) & 1) == 0)) {
        local_176 = 0;
      }
      if (!bVar3) {
        bVar24 = 0;
        if (cVar17 == '\0') {
          uVar15 = LuafvIsExcludedName(auStack_e0);
          cVar17 = (char)local_d0;
          bVar24 = (byte)uVar15;
LAB_14001b9f1:
          if (bVar24 != 0) {
            *param_8 = *param_8 | 0x400;
          }
        }
        else if (((*(byte *)(local_f0 + 0x1e) & 1) == 0) ||
                ((*(uint *)(local_f0 + 0x18) & 0x10) == 0)) {
          bVar24 = *(byte *)(local_f0 + 0x1d) & 1;
          goto LAB_14001b9f1;
        }
        bVar3 = true;
      }
      if (((local_176 != 0) &&
          ((((*(uint *)(lVar26 + 0x18) & 0x400) != 0 &&
            (*param_8 = *param_8 | 0x1000, (DAT_14000c0f8 & 8) == 0)) ||
           (((*(uint *)(lVar26 + 0x18) & 0x4000) != 0 &&
            (*param_8 = *param_8 | 0x2000, (DAT_14000c0f8 & 8) == 0)))))) ||
         ((((*(byte *)(lVar21 + 0x1c) != 0 && ((*(byte *)(lVar21 + 0x1c) & 8) == 0)) &&
           (((*(uint *)(lVar26 + 0x18) & 0x10) == 0 || ((*(byte *)(lVar26 + 0x1e) & 1) == 0)))) &&
          ((DAT_14000c0f8 & 8) == 0)))) goto LAB_14001bef3;
      if (bVar24 != 0) {
        if (((((char)local_130 == '\0') ||
             ((*(byte *)(*(longlong *)(lVar21 + 0x20) + 0x1e) & 1) == 0)) && (cVar17 != '\0')) &&
           ((*(byte *)(*(longlong *)(lVar26 + 0x20) + 0x1e) & 1) != 0)) {
          if (((DAT_14000c0f8 & 8) != 0) && ((*param_8 & 0x10) != 0)) goto LAB_14001bab7;
          bVar5 = true;
        }
        if ((DAT_14000c0f8 & 8) == 0) goto LAB_14001bef3;
      }
LAB_14001bab7:
      uVar13 = Feature_Bugfix_LuafvTableNode__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar13 == 0) {
        uVar14 = LuafvBuildTableNodeName
                           (local_e8,(longlong)local_158,(ushort *)(lVar7 + 0x28),auStack_e0,'\0',
                            (undefined2 *)&local_100);
        uVar12 = (uint)uVar14;
      }
      else {
        uVar14 = LuafvBuildTableNodeName2
                           (local_e8,(longlong)local_158,(ushort *)(lVar7 + 0x28),auStack_e0,'\0',
                            '\0',(undefined2 *)&local_100);
        uVar12 = (uint)uVar14;
      }
      uVar13 = (ulonglong)uVar12;
      if ((int)uVar12 < 0) goto LAB_14001bf61;
      goto LAB_14001bd71;
    }
    if (bVar20 == 0) goto LAB_14001b910;
    if (((*(uint *)(lVar21 + 0x18) & 0x10) == 0) && ((*(byte *)(lVar21 + 0x1d) & 1) != 0)) {
      *param_8 = *param_8 | 0x400;
      bVar24 = 1;
    }
    bVar3 = true;
LAB_14001b8f3:
    if (((*(uint *)(lVar21 + 0x18) & 0x4000) == 0) ||
       (*param_8 = *param_8 | 0x2000, (DAT_14000c0f8 & 8) != 0)) goto LAB_14001b910;
LAB_14001bef7:
    *local_80 = puVar16;
    uVar12 = bVar27 | 2;
    if (!bVar5) {
      uVar12 = (uint)bVar27;
    }
    *local_78 = uVar12;
    if (((DAT_14000c0f8 & 4) != 0) && (!bVar3)) {
      if (lVar21 == 0) goto LAB_14001bf97;
      if (cVar17 == '\0') {
        uVar15 = LuafvIsExcludedName(auStack_140);
        bVar24 = (byte)uVar15;
      }
      else {
        if (((*(byte *)(lVar21 + 0x1e) & 1) != 0) && ((*(uint *)(lVar21 + 0x18) & 0x10) != 0))
        goto LAB_14001bf85;
        bVar24 = *(byte *)(lVar21 + 0x1d) & 1;
      }
      if (bVar24 != 0) {
        *param_8 = *param_8 | 0x400;
      }
    }
  }
LAB_14001bf85:
  if (lVar21 != 0) {
    LuafvDereferenceTableNodeEx(lVar21,'\0','\0');
  }
LAB_14001bf97:
  if (lVar26 != 0) {
    LuafvDereferenceTableNodeEx(lVar26,'\0','\0');
  }
  if ((local_172) && (local_138 != 0)) {
    LuafvFreePool(local_138);
  }
  if ((bVar6) && (local_d8 != 0)) {
    LuafvFreePool(local_d8);
  }
  if (lStack_108 != 0) {
    LuafvFreePool(lStack_108);
  }
  if (lStack_f8 != 0) {
    LuafvFreePool(lStack_f8);
  }
  lVar21 = local_118;
  if (local_170 != 0) {
    LOCK();
    piVar1 = (int *)(local_170 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(longlong *)(local_118 + 0x48) != 0) {
        LuafvDereferenceTableNodeEx(*(longlong *)(local_118 + 0x48),'\0','\0');
      }
      LuafvDereferenceUser(*(longlong *)(lVar21 + 0x10));
      LuafvFreePool(lVar21);
    }
  }
  if (local_98 != (short *)0x0) {
    FltReleaseContext();
  }
  return uVar13;
}



===== LuafvCreateStreamHandleContext @ 14001c070 =====

void LuafvCreateStreamHandleContext(undefined8 *param_1)

{
  int iVar1;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = FltAllocateContext(LuafvDriverData,0x10,0x18,1,local_res10);
  if (-1 < iVar1) {
    *param_1 = local_res10[0];
  }
  return;
}



===== LuafvLogFileEvent @ 14001c0c4 =====

int LuafvLogFileEvent(longlong param_1,longlong param_2,longlong param_3,uint param_4,
                     undefined8 param_5,longlong *param_6,undefined4 param_7)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  bool bVar8;
  uint local_res20 [2];
  ushort local_78 [2];
  ushort local_74 [2];
  undefined4 local_70 [2];
  longlong *local_68;
  ushort *local_60;
  ulonglong local_58;
  longlong lStack_50;
  longlong local_48 [4];
  
  local_60 = (ushort *)0x0;
  local_58 = 0;
  lStack_50 = 0;
  local_78[0] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_68 = (longlong *)0x0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_70[0] = 0;
  local_res20[0] = param_4;
  lVar5 = FltGetRequestorProcess();
  if (lVar5 == 0) {
    return -0x3ffff8e4;
  }
  iVar4 = SeLocateProcessImageName(lVar5,&local_60);
  if (iVar4 < 0) {
    return iVar4;
  }
  plVar7 = local_48;
  local_74[0] = *local_60 >> 1;
  bVar8 = *(char *)(*(longlong *)(param_1 + 0x10) + 4) != '\0';
  if (bVar8) {
    SeCaptureSubjectContext(local_48);
  }
  else {
    plVar7 = (longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8) + 0x20);
  }
  lVar5 = *plVar7;
  lVar6 = lVar5;
  if (lVar5 == 0) {
    lVar6 = plVar7[2];
  }
  iVar4 = SeQueryInformationToken(lVar6,1,&local_68);
  if (bVar8) {
    SeReleaseSubjectContext(local_48);
  }
  if (param_3 == 0) {
    if (*(char *)(param_1 + 0x50) != '\x01') {
      local_res20[0] = local_res20[0] | 1;
    }
    if (lVar5 != 0) {
      local_res20[0] = local_res20[0] | 2;
    }
  }
  else {
    bVar1 = *(byte *)(param_3 + 0x15);
    if ((bVar1 & 1) != 0) {
      local_res20[0] = local_res20[0] | 1;
    }
    if ((bVar1 & 2) != 0) {
      local_res20[0] = local_res20[0] | 2;
    }
    if ((char)*(byte *)(param_3 + 0x14) < '\0') {
      local_res20[0] = local_res20[0] | 0x10;
    }
    if ((bVar1 & 4) != 0) {
      local_res20[0] = local_res20[0] | 0x20;
    }
    if ((*(byte *)(param_3 + 0x14) & 0x40) != 0) {
      local_res20[0] = local_res20[0] | 0x80;
    }
  }
  if (-1 < iVar4) {
    local_70[0] = RtlLengthSid(*local_68);
    if (param_3 != 0) {
      if ((*(uint *)(param_3 + 8) & 1) == 0) {
        if ((*(uint *)(param_3 + 8) & 0x40) != 0) {
          local_res20[0] = local_res20[0] | 8;
        }
      }
      else {
        local_res20[0] = local_res20[0] | 4;
      }
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 4) != 0) {
      local_res20[0] = local_res20[0] | 0x40;
    }
    if (param_2 == 0) {
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
      local_58 = *(ulonglong *)(lVar5 + 0x58);
      lStack_50 = *(longlong *)(lVar5 + 0x60);
      cVar3 = LuafvSupplyFullPath(param_1,&local_58);
    }
    else {
      local_58 = *(ulonglong *)(param_2 + 0x10);
      lStack_50 = *(longlong *)(param_2 + 0x18);
      cVar3 = '\0';
    }
    local_78[0] = (ushort)local_58 >> 1;
    *param_6 = (longlong)local_res20;
    param_6[1] = 4;
    param_6[2] = (longlong)local_70;
    param_6[3] = 4;
    lVar5 = *local_68;
    *(undefined4 *)(param_6 + 5) = local_70[0];
    param_6[4] = lVar5;
    *(undefined4 *)((longlong)param_6 + 0x2c) = 0;
    param_6[6] = (longlong)local_78;
    param_6[7] = 2;
    param_6[8] = lStack_50;
    *(uint *)(param_6 + 9) = (uint)(ushort)local_58;
    *(undefined4 *)((longlong)param_6 + 0x4c) = 0;
    param_6[10] = (longlong)local_74;
    param_6[0xb] = 2;
    uVar2 = *local_60;
    param_6[0xc] = *(longlong *)(local_60 + 4);
    *(uint *)(param_6 + 0xd) = (uint)uVar2;
    *(undefined4 *)((longlong)param_6 + 0x6c) = 0;
    iVar4 = EtwWrite(DAT_14000c100,param_5,0,param_7,param_6);
    ExFreePoolWithTag(local_68,0);
    if (cVar3 != '\0') {
      LuafvFreePool(lStack_50);
    }
  }
  ExFreePoolWithTag(local_60,0x61506553);
  return iVar4;
}



===== LuafvSelectFile @ 14001c418 =====

int LuafvSelectFile(longlong param_1,longlong param_2,ushort *param_3,byte *param_4,byte *param_5,
                   uint *param_6)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char local_res18 [8];
  
  iVar2 = 0;
  local_res18[0] = '\0';
  bVar4 = 0;
  bVar5 = 0;
  if (((param_3[0x2c] & 1) != 0) || ((DAT_14000c0f8 & 8) != 0)) {
    iVar2 = LuafvCheckAdminAccess(param_1,*(undefined8 *)(param_2 + 0x18),param_3,local_res18);
    if (iVar2 < 0) {
      LuafvLogFileError(param_1,(longlong)param_3,&LuafvAdminAccessCheckFailed,iVar2);
    }
    else if ((local_res18[0] != '\0') || (*param_6 = *param_6 | 0x20, (DAT_14000c0f8 & 8) != 0)) {
      bVar1 = (byte)param_3[0x2c];
      if ((bVar1 & (byte)param_3[0x14] & 1) == 0) {
        bVar4 = 1;
      }
      else {
        bVar3 = (byte)param_3[0x14] >> 2 & 1;
        if (bVar3 == (bVar1 >> 2 & 1)) {
          bVar4 = bVar3 ^ 1;
          bVar5 = bVar3;
        }
        else {
          *param_6 = *param_6 | 0x100;
        }
      }
    }
  }
  if (((DAT_14000c0f8 & 8) != 0) && ((*param_6 != 0 || ((param_3[0x2c] & 1) == 0)))) {
    bVar4 = 0;
  }
  if (-1 < iVar2) {
    *param_4 = bVar4;
    *param_5 = bVar5;
  }
  return iVar2;
}



===== LuafvLogFileError @ 14001c538 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvLogFileError(longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_d8 [32];
  longlong local_98 [14];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_1c = 0;
  local_28 = local_res20;
  local_20 = 4;
  local_res20[0] = param_4;
  LuafvLogFileEvent(param_1,param_2,0,0,param_3,local_98,8);
  return;
}



===== LuafvSupplyFullPath @ 14001c5b0 =====

char LuafvSupplyFullPath(longlong param_1,ulonglong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  short *_Src;
  char cVar3;
  ushort uVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  ushort uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  char cVar9;
  longlong local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  short *psStack_20;
  
  local_res10 = 0;
  cVar9 = '\0';
  local_28 = 0;
  psStack_20 = (short *)0x0;
  local_38 = 0;
  uStack_30 = (uint *)0x0;
  if (((ushort)*param_2 < 2) || (*(short *)param_2[1] != 0x5c)) {
    lVar1 = *(longlong *)(param_1 + 0x10);
    lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 0x40);
    uVar7 = (undefined4)((ulonglong)param_2 >> 0x20);
    if ((lVar2 == 0) || (*(char *)(lVar1 + 4) != '\0')) {
      iVar6 = LuafvGetNameFileObject(*(longlong *)(lVar1 + 0x10),*(longlong *)(lVar1 + 8),&local_38)
      ;
      param_2 = (ulonglong *)CONCAT44(uVar7,iVar6);
      if (-1 < extraout_EAX_00) {
        if ((1 < (ushort)local_38) && ((short)*uStack_30 == 0x5c)) {
          cVar9 = '\x01';
          *(undefined4 *)param_2 = (undefined4)local_38;
          *(undefined4 *)((longlong)param_2 + 4) = local_38._4_4_;
          *(undefined4 *)(param_2 + 1) = (undefined4)uStack_30;
          *(undefined4 *)((longlong)param_2 + 0xc) = uStack_30._4_4_;
          goto LAB_14001c733;
        }
        LuafvFreePool((longlong)uStack_30);
      }
    }
    else {
      iVar6 = LuafvGetNameFileObject(*(longlong *)(lVar1 + 0x10),lVar2,&local_28);
      _Src = psStack_20;
      param_2 = (ulonglong *)CONCAT44(uVar7,iVar6);
      if (-1 < extraout_EAX) {
        uVar5 = (ushort)local_28;
        uVar8 = (uint)(ushort)local_28;
        if (((1 < uVar8) && (*psStack_20 == 0x5c)) && ((ushort)local_28 < 0x1001)) {
          uVar4 = (ushort)local_28 + 2 + (ushort)*param_2;
          local_38._0_4_ = CONCAT22(uVar4,(ushort)local_38);
          uStack_30 = LuafvAllocatePool(1,(uint)uVar4,'\x02');
          if (uStack_30 != (uint *)0x0) {
            local_38 = CONCAT62(local_38._2_6_,uVar5);
            memmove(uStack_30,_Src,(ulonglong)uVar8);
            if (*(short *)((longlong)uStack_30 + (local_38 >> 1 & 0x7fff) * 2 + -2) != 0x5c) {
              RtlAppendUnicodeToString(&local_38,L"\\");
            }
            iVar6 = RtlAppendUnicodeStringToString(&local_38,param_2);
            if (iVar6 < 0) {
              LuafvFreePool((longlong)uStack_30);
            }
            else {
              cVar9 = '\x01';
              *param_2 = local_38;
              param_2[1] = (ulonglong)uStack_30;
            }
          }
        }
        LuafvFreePool((longlong)_Src);
        if (cVar9 != '\0') goto LAB_14001c733;
      }
    }
  }
  else {
LAB_14001c733:
    cVar3 = RtlPrefixUnicodeString(&LuafvDeviceNamePrefix,param_2,1);
    if ((cVar3 != '\0') ||
       (iVar6 = FltGetInstanceContext
                          (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),&local_res10),
       iVar6 < 0)) goto LAB_14001c829;
    lVar1 = *(longlong *)(local_res10 + 0x18);
    uVar5 = (ushort)*param_2 + *(short *)(lVar1 + 0x38);
    if ((ushort)*param_2 <= uVar5) {
      local_38._0_4_ = CONCAT22(uVar5,(ushort)local_38);
      uStack_30 = LuafvAllocatePool(1,(uint)uVar5,'\x02');
      if (uStack_30 != (uint *)0x0) {
        local_38 = CONCAT62(local_38._2_6_,*(ushort *)(lVar1 + 0x38));
        memmove(uStack_30,*(void **)(lVar1 + 0x40),(ulonglong)*(ushort *)(lVar1 + 0x38));
        iVar6 = RtlAppendUnicodeStringToString(&local_38,param_2);
        if (iVar6 < 0) {
          LuafvFreePool((longlong)uStack_30);
        }
        else {
          if (cVar9 == '\0') {
            cVar9 = '\x01';
          }
          else {
            LuafvFreePool(param_2[1]);
          }
          *param_2 = local_38;
          param_2[1] = (ulonglong)uStack_30;
        }
      }
      FltReleaseContext(local_res10);
      goto LAB_14001c829;
    }
    FltReleaseContext();
  }
  cVar9 = '\0';
LAB_14001c829:
  return cVar9;
}



===== LuafvLogWRPPCAEvent @ 14001c84c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LuafvLogWRPPCAEvent(longlong param_1)

{
  undefined1 auStackY_c8 [32];
  longlong local_88 [14];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  memset(local_88,0,0x70);
  LuafvLogFileEvent(param_1,0,0,0,&LuafvWRPAccessDeniedEvent,local_88,7);
  return;
}



===== LuafvIsVirtualFileObject @ 14001c8c8 =====

undefined1 LuafvIsVirtualFileObject(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined1 uVar2;
  short *psVar3;
  longlong local_res10;
  
  local_res10 = 0;
  if (param_2 != 0) {
    psVar3 = *(short **)(param_2 + 0x18);
    if ((psVar3 != (short *)0x0) && (*psVar3 == 0x7666)) {
      local_res10 = *(longlong *)(psVar3 + 0x80);
      goto LAB_14001c8e3;
    }
    if ((param_1 != 0) && (iVar1 = FltGetStreamHandleContext(), -1 < iVar1)) {
      psVar3 = (short *)0x0;
      goto LAB_14001c8e3;
    }
  }
  psVar3 = (short *)0x0;
  local_res10 = 0;
LAB_14001c8e3:
  if ((local_res10 == 0) || ((*(byte *)(local_res10 + 0x14) & 2) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  if ((psVar3 == (short *)0x0) && (local_res10 != 0)) {
    FltReleaseContext();
  }
  return uVar2;
}



===== LuafvGetNameFileObject @ 14001c95c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvGetNameFileObject(longlong param_1,longlong param_2,undefined8 *param_3)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  uint *puVar4;
  int unaff_ESI;
  short *psVar5;
  short *psVar6;
  uint *_Src;
  ushort uVar7;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  uint *local_d0;
  uint local_c8 [2];
  undefined8 *local_c0;
  longlong local_b8;
  undefined8 local_b0;
  uint *puStack_a8;
  uint local_98 [20];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  local_b8 = 0;
  local_c0 = (undefined8 *)0x0;
  local_c8[0] = 0;
  local_b0 = 0;
  puStack_a8 = (uint *)0x0;
  memset(local_98,0,0x48);
  uVar3 = Feature_Bugfix_LuafvStreamRename__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 != 0) && (param_2 == 0)) {
    return unaff_ESI;
  }
  puVar4 = local_98;
  if (param_2 == 0) {
LAB_14001ca16:
    psVar5 = (short *)0x0;
    local_c0 = (undefined8 *)0x0;
  }
  else {
    psVar5 = *(short **)(param_2 + 0x18);
    if ((psVar5 == (short *)0x0) || (*psVar5 != 0x7666)) {
      if ((param_1 == 0) ||
         (iVar2 = FltGetStreamHandleContext(param_1,param_2,&local_c0), iVar2 < 0))
      goto LAB_14001ca16;
      psVar5 = (short *)0x0;
    }
    else {
      local_c0 = *(undefined8 **)(psVar5 + 0x80);
    }
  }
  if (local_c0 == (undefined8 *)0x0) {
    local_c8[0] = 0x48;
    puVar4 = local_98;
    do {
      local_d0 = local_c8;
      local_d8 = 9;
      iVar2 = FltQueryInformationFile(param_1,param_2,puVar4,local_c8[0]);
      if (iVar2 != -0x7ffffffb) {
        if (-1 < iVar2) {
          uVar7 = (ushort)*puVar4;
          _Src = puVar4 + 1;
          goto LAB_14001caff;
        }
        break;
      }
      if (puVar4 == local_98) {
        local_c8[0] = 0x200;
      }
      else {
        LuafvFreePool((longlong)puVar4);
        local_c8[0] = local_c8[0] * 2;
      }
      puVar4 = LuafvAllocatePool(1,local_c8[0],'\x01');
    } while (puVar4 != (uint *)0x0);
  }
  else {
    iVar2 = FltGetInstanceContext(param_1,&local_b8);
    if (iVar2 < 0) goto LAB_14001cb5c;
    psVar6 = (short *)*local_c0;
    if ((*(byte *)((longlong)local_c0 + 0x14) & 2) != 0) {
      psVar6 = psVar6 + 0x18;
    }
    uVar1 = *(ushort *)(*(longlong *)(local_b8 + 0x18) + 0x38);
    uVar7 = *psVar6 - uVar1;
    _Src = (uint *)((ulonglong)uVar1 + *(longlong *)(psVar6 + 4));
    FltReleaseContext();
LAB_14001caff:
    local_c8[0] = (uint)uVar7;
    puStack_a8 = LuafvAllocatePool(1,local_c8[0],'\x02');
    if (puStack_a8 != (uint *)0x0) {
      local_b0._0_4_ = CONCAT22((short)local_c8[0],(short)local_c8[0]);
      memmove(puStack_a8,_Src,(ulonglong)local_c8[0]);
      *param_3 = local_b0;
      param_3[1] = puStack_a8;
    }
  }
  if ((puVar4 != local_98) && (puVar4 != (uint *)0x0)) {
    LuafvFreePool((longlong)puVar4);
  }
LAB_14001cb5c:
  if ((psVar5 == (short *)0x0) && (local_c0 != (undefined8 *)0x0)) {
    FltReleaseContext();
  }
  return unaff_ESI;
}



===== LuafvSetEcp @ 14001cba0 =====

undefined8 LuafvSetEcp(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res18;
  undefined8 *local_res20;
  undefined8 local_18 [2];
  
  local_res18 = 0;
  local_18[0] = 0;
  local_res20 = (undefined8 *)0x0;
  FltGetEcpListFromCallbackData(LuafvDriverData,param_1,&local_res18);
  if (local_res18 == 0) {
    uVar2 = FltAllocateExtraCreateParameterList(LuafvDriverData,0,&local_res18);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    FltSetEcpListIntoCallbackData(LuafvDriverData,param_1,local_res18);
  }
  else {
    iVar1 = FltFindExtraCreateParameter(LuafvDriverData,local_res18,&LuafvEcpType,local_18,0);
    if (-1 < iVar1) {
      return 0;
    }
  }
  uVar2 = FltAllocateExtraCreateParameter
                    (LuafvDriverData,&LuafvEcpType,8,0,LuafvCleanUpEcp,0x6661754c,&local_res20);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  *local_res20 = param_2;
  FltInsertExtraCreateParameter(LuafvDriverData,local_res18,local_res20);
  FltReferenceContext(param_2);
  return 0;
}



===== LuafvPreQueryInformation @ 14001cce0 =====

ulonglong LuafvPreQueryInformation(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  short *psVar5;
  ulonglong uVar6;
  undefined8 *local_res8;
  
  lVar3 = *(longlong *)(param_2 + 0x20);
  local_res8 = (undefined8 *)0x0;
  uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8);
  if (lVar3 == 0) {
LAB_14001cd16:
    local_res8 = (undefined8 *)0x0;
LAB_14001cd1b:
    psVar5 = (short *)0x0;
  }
  else {
    psVar5 = *(short **)(lVar3 + 0x18);
    if ((psVar5 == (short *)0x0) || (*psVar5 != 0x7666)) {
      if ((*(longlong *)(param_2 + 0x18) == 0) ||
         (iVar2 = FltGetStreamHandleContext(*(longlong *)(param_2 + 0x18),lVar3,&local_res8),
         iVar2 < 0)) goto LAB_14001cd16;
      goto LAB_14001cd1b;
    }
    local_res8 = *(undefined8 **)(psVar5 + 0x80);
    if (*(longlong *)(psVar5 + 0x78) == 0) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(psVar5 + 0x7c);
      *(undefined8 *)(param_1 + 0x20) = 0;
      return 4;
    }
    *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = *(longlong *)(psVar5 + 0x78);
    FltSetCallbackDataDirty(param_1);
  }
  uVar6 = 1;
  if (((local_res8 == (undefined8 *)0x0) || ((*(byte *)((longlong)local_res8 + 0x14) & 10) == 0)) ||
     (lVar3 = IoGetTopLevelIrp(), lVar3 != 0)) goto LAB_14001cd32;
  iVar2 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if ((iVar2 != 4) && (iVar2 != 0x12)) {
    if (iVar2 == 0x15) {
      uVar4 = LuafvQueryShortNameFromGlobal(*(undefined8 *)(param_2 + 0x18),*local_res8,param_1);
      uVar6 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 4) {
        *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = uVar1;
      }
      goto LAB_14001cd32;
    }
    if ((iVar2 != 0x22) && (iVar2 != 0x23)) goto LAB_14001cd32;
  }
  uVar6 = 0;
LAB_14001cd32:
  if ((psVar5 == (short *)0x0) && (local_res8 != (undefined8 *)0x0)) {
    FltReleaseContext();
  }
  return uVar6;
}



===== LuafvGenerateFileName @ 14001ce60 =====

int LuafvGenerateFileName
              (undefined8 param_1,longlong param_2,longlong param_3,uint param_4,undefined1 *param_5
              ,undefined8 param_6)

{
  short *psVar1;
  int iVar2;
  undefined1 uVar3;
  longlong local_res10;
  
  local_res10 = 0;
  if (((param_2 == 0) || (psVar1 = *(short **)(param_2 + 0x18), psVar1 == (short *)0x0)) ||
     (*psVar1 != 0x7666)) {
    uVar3 = 1;
    if (param_3 != 0) {
      iVar2 = FltGetFileNameInformation(param_3,param_4 & 0xfeffffff,&local_res10);
      goto LAB_14001cead;
    }
  }
  else {
    param_2 = *(longlong *)(psVar1 + 0x78);
    if (param_2 == 0) {
      return *(int *)(psVar1 + 0x7c);
    }
    uVar3 = (undefined1)psVar1[0x7e];
  }
  iVar2 = FltGetFileNameInformationUnsafe(param_2,param_1,param_4 & 0xfeffffff,&local_res10);
LAB_14001cead:
  if (-1 < iVar2) {
    iVar2 = FltCheckAndGrowNameControl(param_6,*(undefined2 *)(local_res10 + 8));
    if (-1 < iVar2) {
      RtlCopyUnicodeString(param_6,local_res10 + 8);
      *param_5 = uVar3;
    }
    FltReleaseFileNameInformation(local_res10);
  }
  return iVar2;
}



===== LuafvPreClose @ 14001cf90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LuafvPreClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  short *psVar3;
  undefined1 auStackY_d8 [32];
  longlong *local_98;
  longlong local_88 [14];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar1 = *(longlong *)(param_2 + 0x20);
  local_98 = (longlong *)0x0;
  if (lVar1 == 0) {
LAB_14001cfcd:
    local_98 = (longlong *)0x0;
  }
  else {
    psVar3 = *(short **)(lVar1 + 0x18);
    if ((psVar3 == (short *)0x0) || (*psVar3 != 0x7666)) {
      if ((*(longlong *)(param_2 + 0x18) == 0) || (iVar2 = FltGetStreamHandleContext(), iVar2 < 0))
      goto LAB_14001cfcd;
      psVar3 = (short *)0x0;
    }
    else {
      local_98 = *(longlong **)(psVar3 + 0x80);
    }
    if ((((local_98 != (longlong *)0x0) && ((*(byte *)((longlong)local_98 + 0x14) & 2) != 0)) &&
        ((*(byte *)((longlong)local_98 + 0x15) & 8) != 0)) &&
       (LuafvUpdateFileTableForFileObject(local_98,0,0), (DAT_14000c0f8 & 1) != 0)) {
      LuafvLogFileEvent(param_1,*local_98,(longlong)local_98,0,&LuafvVirtualDeleteEvent,local_88,7);
    }
    if (psVar3 != (short *)0x0) {
      LuafvUnlinkFsContextFromDvfcb((longlong)psVar3);
      if (((*(byte *)((longlong)*(longlong **)(psVar3 + 0x80) + 0x14) & 0x20) == 0) &&
         ((DAT_14000c0f8 & 2) != 0)) {
        LuafvLogDelayedOnly(param_1,*(longlong **)(psVar3 + 0x80));
      }
      SeReleaseSubjectContext(psVar3 + 0x84);
      FltReleaseContext(*(undefined8 *)(psVar3 + 0x80));
      if (*(longlong *)(psVar3 + 0x6c) != 0) {
        ObfDereferenceObject();
      }
      if (*(longlong *)(psVar3 + 0x68) != 0) {
        FltClose();
      }
      if (*(longlong *)(psVar3 + 0x74) != 0) {
        ObfDereferenceObject();
      }
      if (*(longlong *)(psVar3 + 0x70) != 0) {
        FltClose();
      }
      FsRtlTeardownPerStreamContexts(psVar3);
      LuafvFreePool((longlong)psVar3);
      *(undefined8 *)(lVar1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      return 4;
    }
  }
  if (local_98 != (longlong *)0x0) {
    FltReleaseContext();
  }
  return 1;
}



===== LuafvPreCleanup @ 14001d1c0 =====

undefined8 LuafvPreCleanup(longlong param_1,longlong param_2)

{
  longlong lVar1;
  short *psVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  int iVar6;
  undefined8 uVar7;
  longlong local_res8;
  
  local_res8 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  if ((lVar1 != 0) && ((*(uint *)(lVar1 + 0x50) & 0x400000) != 0)) {
    return 5;
  }
  lVar1 = *(longlong *)(param_2 + 0x20);
  if ((lVar1 == 0) ||
     ((psVar2 = *(short **)(lVar1 + 0x18), psVar2 == (short *)0x0 || (*psVar2 != 0x7666)))) {
    uVar7 = 1;
  }
  else {
    lVar3 = *(longlong *)(psVar2 + 0x60);
    FltAcquirePushLockExclusiveEx(lVar3 + 0x40,0);
    uVar7 = *(undefined8 *)(psVar2 + 0x74);
    uVar4 = *(undefined8 *)(psVar2 + 0x68);
    lVar5 = *(longlong *)(psVar2 + 0x70);
    psVar2[0x68] = 0;
    psVar2[0x69] = 0;
    psVar2[0x6a] = 0;
    psVar2[0x6b] = 0;
    psVar2[0x70] = 0;
    psVar2[0x71] = 0;
    psVar2[0x72] = 0;
    psVar2[0x73] = 0;
    *(uint *)(lVar1 + 0x50) = *(uint *)(lVar1 + 0x50) | 0x4000;
    FltReleasePushLockEx(lVar3 + 0x40,0);
    FltClose(uVar4);
    if (lVar5 != 0) {
      if (*(char *)(lVar1 + 0x48) != '\0') {
        iVar6 = FltAllocateCallbackData(*(undefined8 *)(param_2 + 0x18),uVar7,&local_res8);
        if (-1 < iVar6) {
          *(undefined1 *)(*(longlong *)(local_res8 + 0x10) + 4) = 0x11;
          *(undefined1 *)(*(longlong *)(local_res8 + 0x10) + 5) = 3;
          FltPerformSynchronousIo(local_res8);
          FltFreeCallbackData(local_res8);
        }
      }
      FltClose(lVar5);
    }
    FltAcquirePushLockExclusiveEx(lVar3 + 0x40,0);
    IoRemoveShareAccess(lVar1,lVar3 + 0x48);
    FltReleasePushLockEx(lVar3 + 0x40,0);
    uVar7 = 4;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return uVar7;
}



===== LuafvPreFileSystemControl @ 14001d3a0 =====

ulonglong LuafvPreFileSystemControl(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  short *psVar8;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8 = 0;
  uVar7 = 1;
  iVar4 = *(int *)(lVar1 + 0x28);
  if ((*(longlong *)(lVar1 + 8) != 0) &&
     ((*(uint *)(*(longlong *)(lVar1 + 8) + 0x50) & 0x400000) != 0)) {
    if (iVar4 != 0x9001c) {
      if ((iVar4 != 0x90018) && (iVar4 != 0x90020)) {
        return 1;
      }
      uVar5 = LuafvPauseUsn(param_1);
      if ((int)uVar5 < 0) {
        *(int *)(param_1 + 0x18) = (int)uVar5;
        return 4;
      }
    }
    return 5;
  }
  lVar2 = *(longlong *)(param_2 + 0x20);
  if (lVar2 == 0) {
LAB_14001d3fc:
    local_res8 = 0;
    goto LAB_14001d44a;
  }
  psVar8 = *(short **)(lVar2 + 0x18);
  if ((psVar8 == (short *)0x0) || (*psVar8 != 0x7666)) {
    if ((*(longlong *)(param_2 + 0x18) == 0) ||
       (iVar3 = FltGetStreamHandleContext(*(longlong *)(param_2 + 0x18),lVar2,&local_res8),
       iVar3 < 0)) goto LAB_14001d3fc;
    psVar8 = (short *)0x0;
  }
  else {
    local_res8 = *(longlong *)(psVar8 + 0x80);
  }
  if (local_res8 != 0) {
    if (iVar4 == 0x90448) {
      if (*(uint *)(lVar1 + 0x20) < 0x18) {
        *(undefined4 *)(param_1 + 0x18) = 0xc0000206;
        goto LAB_14001d623;
      }
      if ((**(int **)(lVar1 + 0x30) - 1U & 0xfffffffd) != 0) goto LAB_14001d445;
      iVar4 = FltVetoBypassIo(param_1,param_2,0xc00004c8,&BypassIoErrMsg);
      *(int *)(param_1 + 0x18) = iVar4;
      *(ulonglong *)(param_1 + 0x20) = ((longlong)iVar4 >> 0x3f & 0xfffffffffffffea0U) + 0x160;
    }
    else {
      if ((iVar4 == 0x94264) || (iVar4 == 0x98268)) {
        *(uint *)(param_1 + 0x18) = (iVar4 != 0x94264) + 0xc000a2a3;
      }
      else {
        if (psVar8 != (short *)0x0) {
          if (((iVar4 - 0x90000U < 9) && ((0x111U >> (iVar4 - 0x90000U & 0x1f) & 1) != 0)) ||
             (iVar4 == 0x9005c)) {
            *(undefined4 *)(param_1 + 0x18) = 0xc00000e2;
            *(undefined8 *)(param_1 + 0x20) = 0;
            *(byte *)(*(longlong *)(psVar8 + 0x80) + 0x15) =
                 *(byte *)(*(longlong *)(psVar8 + 0x80) + 0x15) | 4;
            return 4;
          }
          if (iVar4 == 0x9000c) {
            return 1;
          }
          uVar6 = LuafvPreWrite(param_1,param_2,param_3);
          uVar7 = uVar6 & 0xffffffff;
          if ((int)uVar6 == 4) {
            return uVar7;
          }
        }
        if (((*(byte *)(local_res8 + 0x14) & 2) == 0) ||
           (((iVar4 != 0x900a4 && (iVar4 != 0x900d7)) && (iVar4 != 0x9040c)))) goto LAB_14001d445;
        *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
      }
LAB_14001d623:
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    uVar7 = 4;
  }
LAB_14001d445:
  if (psVar8 != (short *)0x0) {
    return uVar7;
  }
LAB_14001d44a:
  if (local_res8 != 0) {
    FltReleaseContext(local_res8);
  }
  return uVar7;
}



===== LuafvPreLockControl @ 14001d640 =====

undefined8 LuafvPreLockControl(longlong param_1,longlong param_2,undefined8 *param_3)

{
  short *psVar1;
  undefined8 uVar2;
  
  if (((*(longlong *)(param_2 + 0x20) == 0) ||
      (psVar1 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x18), psVar1 == (short *)0x0)) ||
     (*psVar1 != 0x7666)) {
    return 1;
  }
  uVar2 = LuafvPreWrite(param_1,param_2,param_3);
  return uVar2;
}



===== LuafvNormalizeNameComponentEx @ 14001d680 =====

ulonglong LuafvNormalizeNameComponentEx
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,undefined4 param_7,uint param_8)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res18 [2];
  undefined8 in_stack_ffffffffffffff48;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined2 local_60;
  undefined8 local_5e;
  undefined8 uStack_56;
  undefined4 local_4e;
  undefined2 local_4a;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar1 = (uint)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  local_78 = 0;
  local_res18[0] = 0;
  local_38 = 0x30;
  local_20 = ((~param_8 & 1) + 8) * 0x40;
  local_1c = 0;
  local_60 = 0x28;
  local_30 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_4e = 0;
  local_5e = 0;
  uStack_56 = 0;
  local_4a = 0;
  local_40 = 1;
  local_28 = param_3;
  local_48 = IoGetTransactionParameterBlock(param_2);
  uVar2 = FltCreateFileEx2(LuafvDriverData,param_1,&local_78,local_res18,0x100000,&local_38,
                           &local_70,0,(ulonglong)uVar1 << 0x20,7,1,0x4021,0,0,0x900,&local_60);
  if (-1 < (int)uVar2) {
    uVar1 = FltQueryDirectoryFile(param_1,local_res18[0],param_6,param_7,0xc,1,param_5,1,0);
    uVar2 = (ulonglong)uVar1;
    ObfDereferenceObject(local_res18[0]);
    FltClose(local_78);
  }
  return uVar2;
}



===== LuafvRemoveExtraStreamName @ 14001d800 =====

void LuafvRemoveExtraStreamName(ushort *param_1,undefined8 param_2)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  undefined8 local_18;
  short *local_10;
  
  sVar3 = 0;
  local_10 = (short *)((ulonglong)*param_1 + (longlong)*(short **)(param_1 + 4));
  while( true ) {
    if (local_10 <= *(short **)(param_1 + 4)) {
      return;
    }
    local_10 = local_10 + -1;
    sVar3 = sVar3 + 2;
    if (*local_10 == 0x3a) break;
    if (*local_10 == 0x5c) {
      return;
    }
  }
  local_18 = (ulonglong)CONCAT22(sVar3,sVar3);
  cVar2 = RtlEqualUnicodeString(&local_18,param_2,1);
  if (cVar2 == '\0') {
    return;
  }
  uVar1 = *param_1;
  *param_1 = uVar1 - (short)local_18;
  if (local_10 <= *(short **)(param_1 + 4)) {
    return;
  }
  if (local_10[-1] == 0x3a) {
    *param_1 = (uVar1 - (short)local_18) - 2;
    return;
  }
  return;
}



===== LuafvBuildTableNodeName @ 14001d8b0 =====

undefined8
LuafvBuildTableNodeName
          (longlong param_1,longlong param_2,ushort *param_3,ushort *param_4,char param_5,
          undefined2 *param_6)

{
  int *piVar1;
  short sVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  longlong lVar10;
  uint *puVar11;
  uint uVar12;
  undefined8 uVar13;
  char cVar14;
  uint uVar15;
  undefined2 *_Dst;
  void *_Dst_00;
  
  if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  }
  else {
    FltAcquirePushLockSharedEx(param_1,0);
  }
  FltAcquirePushLockSharedEx(&DAT_14000c280,0);
  uVar12 = 0;
  lVar10 = param_1;
  while( true ) {
    if ((*(longlong *)(lVar10 + 0x20) == 0) || (lVar10 == param_2)) goto LAB_14001d93b;
    if (*(longlong *)(lVar10 + 0xf8) != 0) break;
    uVar12 = uVar12 + 2 + (uint)*(ushort *)(lVar10 + 0x50);
    lVar10 = *(longlong *)(lVar10 + 0x20);
  }
  param_3 = (ushort *)(lVar10 + 0xf0);
  param_2 = lVar10;
LAB_14001d93b:
  if ((param_3 == (ushort *)0x0) || (*param_3 == 0)) {
    bVar6 = false;
    bVar5 = false;
  }
  else {
    bVar6 = true;
    if (*(short *)(*(longlong *)(param_3 + 4) + -2 + (ulonglong)(*param_3 >> 1) * 2) == 0x5c) {
      bVar5 = true;
      uVar12 = (*param_3 - 2) + uVar12;
    }
    else {
      uVar12 = *param_3 + uVar12;
      bVar6 = true;
      bVar5 = false;
    }
  }
  if ((param_4 == (ushort *)0x0) || (*param_4 == 0)) {
    bVar7 = false;
    bVar8 = false;
LAB_14001d9c4:
    bVar4 = bVar8;
    bVar8 = false;
  }
  else {
    bVar4 = true;
    sVar2 = **(short **)(param_4 + 4);
    if ((sVar2 == 0x5c) || (sVar2 == 0x3a)) {
      bVar7 = true;
    }
    else {
      bVar7 = false;
    }
    bVar8 = true;
    if ((*(short **)(param_4 + 4))[(ulonglong)(*param_4 >> 1) - 1] != 0x5c) goto LAB_14001d9c4;
    bVar8 = true;
  }
  if ((bVar4) && (uVar12 = uVar12 + *param_4, !bVar7)) {
    uVar12 = uVar12 + 2;
  }
  if ((param_5 != '\0') && (!bVar8)) {
    uVar12 = uVar12 + 2;
  }
  if (7 < uVar12 + 8) {
    cVar14 = -1;
    if (uVar12 < 0xb9) {
      uVar15 = 0;
      uVar9 = 0x38;
      do {
        if (uVar12 <= uVar9) break;
        uVar15 = uVar15 + 1;
        uVar9 = uVar9 + 0x20;
      } while (uVar15 < 5);
      puVar11 = (uint *)ExAllocateFromPagedLookasideList
                                  (&StringLookaside + (ulonglong)uVar15 * 0x80);
      cVar14 = (char)uVar15 + '\x02';
      if (cVar14 == -1) goto LAB_14001da82;
    }
    else {
LAB_14001da82:
      puVar11 = (uint *)ExAllocatePool2(0x100,uVar12 + 8,0x6661754c);
    }
    if (puVar11 != (uint *)0x0) {
      *puVar11 = uVar12;
      *(char *)(puVar11 + 1) = cVar14;
      FltAcquirePushLockExclusiveEx(&PoolLock,0);
      DAT_14000c2a4 = DAT_14000c2a4 + uVar12;
      FltReleasePushLockEx(&PoolLock,0);
      if (puVar11 + 2 != (uint *)0x0) {
        _Dst = (undefined2 *)((longlong)(puVar11 + 2) + (ulonglong)uVar12);
        if ((param_5 != '\0') && (!bVar8)) {
          _Dst = _Dst + -1;
          *_Dst = 0x5c;
        }
        if (bVar4) {
          _Dst = (undefined2 *)((longlong)_Dst + (longlong)(int)-(uint)*param_4);
          memmove(_Dst,*(void **)(param_4 + 4),(ulonglong)*param_4);
          if (!bVar7) {
            _Dst = _Dst + -1;
            *_Dst = 0x5c;
          }
        }
        lVar10 = *(longlong *)(param_1 + 0x20);
        lVar3 = param_1;
        while ((lVar10 != 0 && (lVar3 != param_2))) {
          _Dst_00 = (void *)((longlong)_Dst + (longlong)(int)-(uint)*(ushort *)(lVar3 + 0x50));
          memmove(_Dst_00,*(void **)(lVar3 + 0x58),(ulonglong)*(ushort *)(lVar3 + 0x50));
          _Dst = (undefined2 *)((longlong)_Dst_00 + -2);
          *_Dst = 0x5c;
          lVar3 = *(longlong *)(lVar3 + 0x20);
          lVar10 = *(longlong *)(lVar3 + 0x20);
        }
        if (bVar6) {
          uVar9 = *param_3 - 2;
          if (!bVar5) {
            uVar9 = (uint)*param_3;
          }
          _Dst = (undefined2 *)((longlong)_Dst + (longlong)(int)-uVar9);
          memmove(_Dst,*(void **)(param_3 + 4),(longlong)(int)uVar9);
        }
        *param_6 = (short)uVar12;
        param_6[1] = (short)uVar12;
        uVar13 = 0;
        *(undefined2 **)(param_6 + 4) = _Dst;
        goto LAB_14001da08;
      }
    }
  }
  uVar13 = 0xc000009a;
LAB_14001da08:
  FltReleasePushLockEx(&DAT_14000c280,0);
  if (*(void **)(param_1 + 8) == SystemReserved1[0xf]) {
    piVar1 = (int *)(param_1 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) {
      return uVar13;
    }
    *(undefined8 *)(param_1 + 8) = 0;
  }
  FltReleasePushLockEx(param_1,0);
  return uVar13;
}



===== LuafvIsWrpFileDescriptor @ 14001dcd0 =====

ulonglong LuafvIsWrpFileDescriptor(undefined8 param_1)

{
  char cVar1;
  ulonglong uVar2;
  undefined1 local_res10 [8];
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res10[0] = 0;
  uVar2 = RtlGetOwnerSecurityDescriptor(param_1,local_res18,local_res10);
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (local_res18[0] == 0) {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    cVar1 = RtlEqualSid(DAT_14000c2b8);
    uVar2 = (ulonglong)(cVar1 != '\0');
  }
  return uVar2;
}



===== LuafvPreNetworkQueryOpen @ 14001dd50 =====

undefined8 LuafvPreNetworkQueryOpen(void)

{
  return 3;
}



===== LuafvPostCleanup @ 14001dd60 =====

undefined8 LuafvPostCleanup(longlong param_1)

{
  if (-1 < *(int *)(param_1 + 0x18)) {
    LuafvResumeUsn(param_1);
  }
  return 0;
}



===== LuafvOpenDirectory @ 14001dd80 =====

int LuafvOpenDirectory(undefined8 param_1,undefined8 param_2,longlong *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  longlong local_res18 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res18[0] = 0;
  local_2c = 0;
  local_44 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (*param_3 != 0) {
    return 0;
  }
  local_40 = 0;
  local_48 = 0x30;
  local_30 = 0x240;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = param_2;
  iVar1 = FltCreateFileEx2(LuafvDriverData,param_1,local_res18,0,0x100001,&local_48,&local_58,0,0x80
                           ,7,1,0x20,0,0,0x101,0);
  if (iVar1 < 0) {
    return iVar1;
  }
  if ((param_4 < 0x28e) || (uVar4 = 0x1000, param_4 < 0x1000)) {
    uVar4 = 0x28e;
    if (0x28d < param_4) {
      uVar4 = param_4;
    }
    uVar2 = uVar4 + 8;
    if (uVar2 < 8) goto LAB_14001de7a;
  }
  else {
    uVar2 = 0x1008;
  }
  puVar3 = (uint *)ExAllocatePool2(0x100,uVar2,0x6661754c);
  if (puVar3 != (uint *)0x0) {
    *puVar3 = uVar4;
    *(undefined1 *)(puVar3 + 1) = 0xff;
    FltAcquirePushLockExclusiveEx(&PoolLock);
    DAT_14000c2a4 = DAT_14000c2a4 + uVar4;
    FltReleasePushLockEx(&PoolLock);
    puVar3 = puVar3 + 2;
    if (puVar3 != (uint *)0x0) {
      memset(puVar3,0,(ulonglong)uVar4);
      param_3[3] = 0;
      *(undefined4 *)(param_3 + 1) = 0;
      *param_3 = local_res18[0];
      *(uint *)((longlong)param_3 + 0xc) = uVar4;
      param_3[2] = (longlong)puVar3;
      return iVar1;
    }
  }
LAB_14001de7a:
  FltClose(local_res18[0]);
  return -0x3fffff66;
}



===== LuafvQueryDirectoryIfNeeded @ 14001df40 =====

ulonglong LuafvQueryDirectoryIfNeeded
                    (undefined8 param_1,undefined8 *param_2,undefined1 param_3,undefined4 param_4,
                    undefined8 param_5,char param_6)

{
  uint uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 local_28 [2];
  
  local_28[0] = 0;
  uVar5 = 0;
  if (((param_6 != '\0') || (param_2[3] == 0)) ||
     (((ulonglong)*(uint *)((longlong)param_2 + 0xc) + param_2[2] <= (ulonglong)param_2[3] &&
      (*(int *)(param_2 + 1) == 0)))) {
    uVar3 = ObReferenceObjectByHandle
                      (*param_2,0x100001,*(undefined8 *)IoFileObjectType_exref,0,local_28,0);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      *(int *)(param_2 + 1) = (int)uVar3;
      return uVar3;
    }
    uVar2 = FltQueryDirectoryFile
                      (param_1,local_28[0],param_2[2],*(undefined4 *)((longlong)param_2 + 0xc),
                       param_4,param_3,param_5,param_6,0);
    *(undefined4 *)(param_2 + 1) = uVar2;
    ObfDereferenceObject(local_28[0]);
    uVar1 = *(uint *)(param_2 + 1);
    if ((int)uVar1 < 0) {
      if ((uVar1 != 0x80000006) && (uVar1 != 0xc000000f)) {
        uVar5 = (ulonglong)uVar1;
      }
      lVar4 = (ulonglong)*(uint *)((longlong)param_2 + 0xc) + param_2[2];
    }
    else {
      lVar4 = param_2[2];
    }
    param_2[3] = lVar4;
  }
  return uVar5;
}



===== LuafvInstanceSetup @ 14001e080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LuafvInstanceSetup(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  int *piVar6;
  undefined1 auStack_78 [32];
  int ***local_58;
  undefined8 *local_48;
  int *local_40;
  int **local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = (int *)0x0;
  local_38 = (int **)0x0;
  uVar5 = 0xc01c000f;
  local_48 = (undefined8 *)0x0;
  if (param_4 == 2) {
    uVar3 = LuafvGetVolumeProperties(*(undefined8 *)(param_1 + 0x10),(longlong *)&local_40);
    piVar6 = local_40;
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      if (((*local_40 == 8) && ((local_40[1] & 0x5fU) == 0)) &&
         (uVar4 = LuafvIsIncludedVolume((ulonglong *)(local_40 + 0xe),(longlong *)&local_38),
         (char)uVar4 != '\0')) {
        local_58 = (int ***)&local_48;
        uVar1 = FltAllocateContext(LuafvDriverData,2,0x358,0x200);
        uVar5 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          memset(local_48,0,0x358);
          local_48[2] = *(undefined8 *)(param_1 + 0x18);
          local_48[3] = piVar6;
          local_48[4] = local_38;
          iVar2 = RtlCompareUnicodeString(&DAT_14000c108,piVar6 + 0xe,0);
          *(bool *)(local_48 + 0x6a) = iVar2 == 0;
          ExInitializeRundownProtection(local_48 + 0x69);
          uVar1 = FltSetInstanceContext(*(undefined8 *)(param_1 + 0x18),1,local_48);
          uVar5 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            piVar6 = (int *)0x0;
            LuafvInitializeFileTableForVolume(local_48);
            uVar5 = LuafvInitializeUsn((longlong)local_48);
            uVar5 = uVar5 & 0xffffffff;
          }
          FltReleaseContext(local_48);
          if (-1 < (int)uVar5) {
            return uVar5;
          }
        }
      }
      else {
        uVar5 = 0xc01c000f;
      }
      if ((piVar6 != (int *)0x0) && (LuafvFreePool((longlong)piVar6), -1 < (int)uVar5)) {
        return uVar5;
      }
    }
    if ((int)uVar5 != -0x3fe3fff1) {
      local_2c = 0;
      local_38 = &local_40;
      local_58 = &local_38;
      local_40 = (int *)CONCAT44(local_40._4_4_,(int)uVar5);
      local_30 = 4;
      EtwWrite(DAT_14000c100,&LuafvInstanceSetupFailed,0,1);
    }
  }
  return uVar5;
}



===== LuafvInitializeTable @ 14001e294 =====

void LuafvInitializeTable(undefined8 *param_1,undefined4 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_2;
  return;
}



===== _tlgEnableCallback @ 14001e2b0 =====

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



===== LuafvCompareDirectoryEntryName @ 14001e32c =====

void LuafvCompareDirectoryEntryName(longlong param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  undefined2 local_28;
  undefined2 local_26;
  undefined4 local_24;
  longlong local_20;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  longlong local_10;
  
  lVar1 = *(longlong *)(param_1 + 0x60);
  local_14 = 0;
  local_24 = 0;
  local_18 = *(undefined2 *)((ulonglong)param_3 + *(longlong *)(lVar1 + 0x18));
  local_10 = *(longlong *)(lVar1 + 0x18) + (ulonglong)param_2;
  local_28 = *(undefined2 *)((ulonglong)param_3 + *(longlong *)(lVar1 + 0x38));
  local_20 = *(longlong *)(lVar1 + 0x38) + (ulonglong)param_2;
  local_26 = local_28;
  local_16 = local_18;
  RtlCompareUnicodeString(&local_18,&local_28,1);
  return;
}



===== LuafvCreateUserStorePath @ 14001e3a8 =====

ulonglong LuafvCreateUserStorePath(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  longlong local_res18;
  undefined8 local_res20;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  longlong local_50;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  undefined8 local_30;
  
  local_res20 = 0;
  local_3c = 0;
  local_54 = 0;
  uVar4 = 0x100;
  local_res18 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (*(char *)(param_3 + 0x50) == '\0') {
    uVar3 = LuafvCreateUserStoreSecurityDescriptor(*(longlong *)(param_3 + 0x10),&local_res18);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  else {
    uVar4 = 0x101;
  }
  lVar1 = local_res18;
  if (param_2 == 0) {
    local_48 = param_3 + 0x28;
  }
  else {
    local_48 = *(longlong *)(param_3 + 0x10) + 0x58;
  }
  local_30 = 0;
  local_58 = 0x30;
  local_40 = 0x240;
  local_50 = param_2;
  local_38 = local_res18;
  uVar2 = FltCreateFileEx2(LuafvDriverData,param_1,&local_res20,0,0x1c0000,&local_58,&local_68,0,
                           0x10,3,3,0x21,0,0,uVar4,0);
  if (-1 < (int)uVar2) {
    FltClose(local_res20);
  }
  if (lVar1 != 0) {
    LuafvFreePool(lVar1);
  }
  return (ulonglong)uVar2;
}



===== LuafvCleanUpEcp @ 14001e510 =====

void LuafvCleanUpEcp(longlong *param_1)

{
  if (*param_1 != 0) {
    FltReleaseContext();
  }
  return;
}



===== LuafvGetVolumeProperties @ 14001e534 =====

undefined8 LuafvGetVolumeProperties(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  int local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = FltGetVolumeProperties(param_1,0,0,local_res18);
  iVar1 = local_res18[0];
  if ((int)uVar2 == -0x3fffffdd) {
    if ((7 < local_res18[0] + 8U) &&
       (piVar3 = (int *)ExAllocatePool2(0x100,local_res18[0] + 8U,0x6661754c), piVar3 != (int *)0x0)
       ) {
      *piVar3 = iVar1;
      *(undefined1 *)(piVar3 + 1) = 0xff;
      FltAcquirePushLockExclusiveEx(&PoolLock,0);
      DAT_14000c2a4 = DAT_14000c2a4 + iVar1;
      FltReleasePushLockEx(&PoolLock,0);
      piVar3 = piVar3 + 2;
      if (piVar3 != (int *)0x0) {
        uVar2 = FltGetVolumeProperties(param_1,piVar3,local_res18[0],local_res18);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        *param_2 = (longlong)piVar3;
        return uVar2;
      }
    }
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



===== LuafvInitializeSdTable @ 14001e628 =====

undefined8 LuafvInitializeSdTable(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined *puVar3;
  
  puVar1 = &SdTable;
  lVar2 = 0x10;
  puVar3 = &DAT_14000b8f0;
  do {
    puVar1[1] = puVar1;
    *puVar1 = puVar1;
    FltInitializePushLock(puVar3);
    puVar3 = puVar3 + 0x18;
    puVar1 = puVar1 + 3;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return 0;
}



===== LuafvPrePnp @ 14001e690 =====

undefined8 LuafvPrePnp(longlong param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 5);
  if (cVar1 == '\x01') {
    LuafvPauseUsn(param_1);
  }
  else if (cVar1 == '\x03') {
    LuafvResumeUsn(param_1);
  }
  return 1;
}



===== LuafvCreateVirtualFile @ 14001e6c8 =====

ulonglong LuafvCreateVirtualFile
                    (longlong param_1,longlong param_2,ulonglong *param_3,longlong param_4)

{
  int *piVar1;
  ulonglong *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  undefined *puVar7;
  char cVar8;
  char cVar9;
  ulonglong local_68 [4];
  undefined8 local_48;
  
  puVar2 = (ulonglong *)*param_3;
  local_48 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  if (puVar2[10] == 0) {
    puVar6 = (ulonglong *)0x4;
    uVar4 = LuafvFindTableNode((undefined *)0x0,puVar2 + 6,4,local_68);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    cVar9 = (char)local_48;
  }
  else {
    cVar9 = '\x01';
    local_48 = 1;
    puVar6 = param_3;
    local_68[0] = puVar2[10];
  }
  uVar4 = local_68[0];
  cVar8 = '\0';
  if ((cVar9 == '\0') || ((*(byte *)(*(longlong *)(local_68[0] + 0x20) + 0x1e) & 1) == 0)) {
    puVar6 = puVar2;
    uVar3 = LuafvCreateVirtualPath(*(undefined8 *)(param_1 + 0x18),param_2,puVar2);
    if ((int)uVar3 < 0) {
      puVar7 = &LuafvCreateVirtualPathFailed;
LAB_14001e773:
      LuafvLogFileError(param_2,(longlong)puVar2,puVar7,uVar3);
    }
    else {
      if (cVar9 != '\0') goto LAB_14001e7cc;
      uVar5 = LuafvFindTableNode((undefined *)0x0,puVar2 + 6,0xc,local_68);
      puVar6 = (ulonglong *)0x0;
      uVar3 = (uint)uVar5;
      LuafvDereferenceTableNodeEx(uVar4,'\0','\0');
      if ((int)uVar3 < 0) goto LAB_14001e90c;
      uVar4 = local_68[0];
      if ((char)local_48 != '\0') goto LAB_14001e7cc;
      uVar3 = 0xc000003a;
    }
  }
  else {
LAB_14001e7cc:
    if (*(void **)(uVar4 + 8) == SystemReserved1[0xf]) {
      *(int *)(uVar4 + 0x10) = *(int *)(uVar4 + 0x10) + 1;
    }
    else {
      FltAcquirePushLockExclusiveEx(local_68[0],0);
      *(void **)(uVar4 + 8) = SystemReserved1[0xf];
      *(undefined4 *)(uVar4 + 0x10) = 1;
    }
    uVar4 = local_68[0];
    cVar8 = '\x01';
    if ((*(byte *)(local_68[0] + 0x1e) & 1) == 0) {
      puVar6 = puVar2;
      uVar3 = LuafvCopyFile(*(undefined8 *)(param_1 + 0x18),param_2,puVar2,puVar2 + 6,param_4,
                            (byte)puVar2[5] >> 2 & 1);
      if ((int)uVar3 < 0) {
        if ((1 < uVar3 + 0x3fffffcc) && (uVar3 != 0xc000003a)) {
          puVar7 = &LuafvCopyFileFailed;
          goto LAB_14001e773;
        }
        uVar3 = 0;
      }
      else {
        *(byte *)((longlong)param_3 + 0x14) = *(byte *)((longlong)param_3 + 0x14) | 0x60;
        if ((DAT_14000c0f8 & 1) != 0) {
          LuafvLogVirtualCreate(param_2,(longlong *)param_3);
        }
      }
      *(ushort *)(uVar4 + 0x1e) = *(ushort *)(uVar4 + 0x1e) | 1;
      *(ushort *)(uVar4 + 0x1e) = *(ushort *)(uVar4 + 0x1e) | 0x80;
    }
    else {
      uVar3 = 0;
    }
    LuafvLogUtcEvent((uint *)&DAT_14000b280,0x14000b290,puVar6,param_2,(longlong)puVar2,1);
  }
  if (puVar2[10] == 0) {
    LuafvDereferenceTableNodeEx(uVar4,cVar8,'\0');
  }
  else if (cVar8 != '\0') {
    if (*(void **)(uVar4 + 8) == SystemReserved1[0xf]) {
      piVar1 = (int *)(local_68[0] + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 != 0) goto LAB_14001e90c;
      *(undefined8 *)(uVar4 + 8) = 0;
    }
    FltReleasePushLockEx(local_68[0],0);
  }
LAB_14001e90c:
  return (ulonglong)uVar3;
}



===== LuafvCopyFile @ 14001e930 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvCopyFile(undefined8 param_1,longlong param_2,ulonglong *param_3,ulonglong *param_4,
                 longlong param_5,char param_6)

{
  ushort uVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStackY_248 [32];
  undefined1 local_1c4;
  undefined1 local_1c3;
  undefined4 local_1c0 [2];
  longlong local_1b8;
  int local_1b0;
  longlong local_1a8;
  longlong local_1a0;
  longlong local_198;
  longlong local_190;
  longlong local_188;
  uint local_180;
  uint local_17c;
  longlong local_178;
  longlong local_170;
  uint *local_168;
  longlong local_160;
  undefined4 local_158;
  undefined4 uStack_154;
  longlong lStack_150;
  ulonglong *local_148;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  longlong lStack_120;
  undefined4 local_118;
  uint local_114;
  uint *local_110;
  ulonglong local_108;
  short *psStack_100;
  short *local_f8;
  short *local_f0;
  uint *local_e8;
  undefined8 local_e0;
  uint *puStack_d8;
  ulonglong local_d0;
  short *psStack_c8;
  ulonglong *local_c0;
  longlong local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  longlong lStack_80;
  ulonglong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_248;
  local_128 = 0;
  lStack_120 = 0;
  local_e0 = 0;
  puStack_d8 = (uint *)0x0;
  local_180 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  lStack_80 = 0;
  local_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_160 = 0;
  local_178 = 0;
  local_188 = 0;
  local_170 = 0;
  puVar7 = (uint *)0x0;
  local_168 = (uint *)0x0;
  puVar5 = (uint *)0x0;
  local_110 = (uint *)0x0;
  local_1a8 = 0;
  local_1c0[0] = 0;
  local_1b8 = 0;
  local_1a0 = 0;
  local_198 = 0;
  local_190 = 0;
  local_108 = *param_3;
  psStack_100 = (short *)param_3[1];
  bVar2 = false;
  local_1c3 = 0;
  uVar9 = local_108 & 0xffffffff;
  local_f8 = (short *)((local_108 & 0xffff) + (longlong)psStack_100);
  do {
    while( true ) {
      if (local_f8 <= psStack_100) goto LAB_14001eadf;
      local_f8 = local_f8 + -1;
      if (*local_f8 != 0x3a) break;
      uVar1 = (short)((longlong)local_f8 - (longlong)psStack_100 >> 1) * 2;
      uVar9 = (ulonglong)uVar1;
      local_108 = CONCAT62(local_108._2_6_,uVar1);
      bVar2 = true;
      local_1c3 = 1;
    }
  } while (*local_f8 != 0x5c);
LAB_14001eadf:
  local_d0 = *param_4;
  psStack_c8 = (short *)param_4[1];
  local_f0 = (short *)((local_d0 & 0xffff) + (longlong)psStack_c8);
  do {
    while( true ) {
      if (local_f0 <= psStack_c8) goto LAB_14001eb33;
      local_f0 = local_f0 + -1;
      if (*local_f0 != 0x3a) break;
      local_d0 = CONCAT62(local_d0._2_6_,(short)((longlong)local_f0 - (longlong)psStack_c8 >> 1) * 2
                         );
    }
  } while (*local_f0 != 0x5c);
LAB_14001eb33:
  if (param_5 != 0) {
    if (bVar2) {
      param_5 = 0;
    }
    else {
      local_108 = (ulonglong)local_108._2_6_ << 0x10;
    }
  }
  local_158 = 0x30;
  uStack_154 = 0;
  uStack_140 = 0x240;
  uStack_13c = 0;
  local_148 = &local_108;
  local_138 = 0;
  uStack_130 = 0;
  local_1b0 = (-(uint)(param_6 != '\0') & 0xffffffc1) + 100;
  lStack_150 = param_5;
  local_c0 = param_3;
  local_b8 = param_2;
  local_b0 = param_1;
  iVar4 = FltCreateFileEx2(LuafvDriverData,param_1,&local_160,&local_1b8);
  if ((-1 < iVar4) &&
     (iVar4 = FltQueryInformationFile(param_1,local_1b8,&local_a8,0x38), -1 < iVar4)) {
    if (param_6 != '\0') {
      local_88 = 0;
      lStack_80 = 0;
    }
    iVar4 = FltQueryInformationFile(param_1,local_1b8,&local_180);
    local_17c = local_180;
    if ((-1 < iVar4) && (uVar8 = local_180, local_180 != 0)) {
      do {
        puVar5 = LuafvAllocatePool(1,uVar8,'\x01');
        local_110 = puVar5;
        if (puVar5 == (uint *)0x0) goto LAB_14001f425;
        iVar4 = FltQueryEaFile(param_1,local_1b8,puVar5);
        if (iVar4 < 0) {
          uVar8 = uVar8 * 2;
          local_17c = uVar8;
          LuafvFreePool((longlong)puVar5);
          puVar5 = (uint *)0x0;
          local_110 = (uint *)0x0;
        }
      } while ((iVar4 == -0x7ffffffb) || (iVar4 == -0x3fffffdd));
      local_17c = (uint)lStack_120;
      if (iVar4 < 0) {
        local_17c = 0;
      }
      param_3 = local_c0;
    }
    local_158 = 0x30;
    lStack_150 = 0;
    uStack_140 = 0x240;
    local_148 = &local_d0;
    local_138 = 0;
    uStack_130 = 0;
    local_78 = local_78 & 0xffffffffffffefff;
    local_1b0 = (-(uint)(param_6 != '\0') & 0xffffffc1) + 0x4064;
    local_118 = 0x100112;
    if (param_6 == '\0') {
      local_118 = 0x110112;
    }
    iVar4 = FltCreateFileEx2(LuafvDriverData,param_1,&local_188,&local_1a0);
    if (-1 < iVar4) {
      LuafvCopyShortName(param_1,param_3,local_188);
      local_108 = CONCAT62(local_108._2_6_,(short)uVar9);
      iVar4 = LuafvCopySaclWithAudit(param_1,local_b8,local_1b8,local_188,&local_108,&local_d0);
      if (-1 < iVar4) {
        if ((param_6 == '\0') && (lStack_80 != 0)) {
          uVar6 = AllocateDataBuffer(&local_1a8,local_1c0);
          iVar4 = (int)uVar6;
          if (iVar4 < 0) goto LAB_14001f431;
          uVar6 = LuafvCopyStreamData(param_1,local_1b8,local_1a0,&lStack_80,local_1a8,local_1c0[0])
          ;
          iVar4 = (int)uVar6;
          if (iVar4 < 0) goto LAB_14001f431;
        }
        uVar8 = 0x1000;
        local_114 = 0x1000;
        do {
          puVar7 = LuafvAllocatePool(1,uVar8,'\x01');
          local_168 = puVar7;
          if (puVar7 == (uint *)0x0) goto LAB_14001f425;
          iVar4 = FltQueryInformationFile(param_1,local_1b8,puVar7,uVar8);
          if (iVar4 < 0) {
            local_114 = uVar8 * 2;
            uVar8 = local_114;
LAB_14001f07c:
            LuafvFreePool((longlong)puVar7);
            local_168 = (uint *)0x0;
            puVar7 = (uint *)0x0;
          }
          else if (lStack_120 == 0) goto LAB_14001f07c;
        } while ((iVar4 == -0x7ffffffb) || (iVar4 == -0x3fffffdd));
        if (puVar7 != (uint *)0x0) {
          local_e8 = puVar7;
          while( true ) {
            puVar3 = local_e8;
            if ((2 < local_e8[1]) && (*(short *)((longlong)local_e8 + 0x1a) != 0x3a)) {
              puStack_d8 = local_e8 + 6;
              local_e0._0_4_ = CONCAT22((short)local_e8[1],(short)local_e8[1]);
              local_158 = 0x30;
              lStack_150 = local_188;
              uStack_140 = 0x200;
              local_148 = &local_e0;
              local_138 = 0;
              uStack_130 = 0;
              iVar4 = FltCreateFileEx2(LuafvDriverData,param_1,&local_170,&local_190);
              if (iVar4 < 0) goto LAB_14001f431;
              if (*(longlong *)(puVar3 + 2) != 0) {
                local_158 = 0x30;
                lStack_150 = local_160;
                uStack_140 = 0x200;
                local_148 = &local_e0;
                local_138 = 0;
                uStack_130 = 0;
                iVar4 = FltCreateFileEx2(LuafvDriverData,param_1,&local_178,&local_198);
                if (iVar4 < 0) goto LAB_14001f431;
                if (local_1a8 == 0) {
                  uVar6 = AllocateDataBuffer(&local_1a8,local_1c0);
                  iVar4 = (int)uVar6;
                  if (iVar4 < 0) goto LAB_14001f431;
                }
                uVar6 = LuafvCopyStreamData(param_1,local_198,local_190,(undefined8 *)(puVar3 + 2),
                                            local_1a8,local_1c0[0]);
                iVar4 = (int)uVar6;
                if (iVar4 < 0) goto LAB_14001f431;
                ObfDereferenceObject(local_198);
                local_198 = 0;
                FltClose(local_178);
                local_178 = 0;
              }
              ObfDereferenceObject(local_190);
              local_190 = 0;
              FltClose(local_170);
              local_170 = 0;
            }
            if (*puVar3 == 0) break;
            local_e8 = (uint *)((longlong)puVar3 + (ulonglong)*puVar3);
          }
        }
        local_70 = local_a8;
        uStack_68 = uStack_a0;
        local_60 = local_98;
        uStack_58 = uStack_90;
        local_50 = local_50 & 0xffffffff00000000;
        iVar4 = FltSetInformationFile(param_1,local_1a0,&local_70,0x28);
      }
    }
  }
LAB_14001f431:
  if ((iVar4 < 0) && (local_1a0 != 0)) {
    local_1c4 = 1;
    FltSetInformationFile(param_1,local_1a0,&local_1c4,1);
  }
  if (local_198 != 0) {
    ObfDereferenceObject();
  }
  if (local_190 != 0) {
    ObfDereferenceObject();
  }
  if (local_1b8 != 0) {
    ObfDereferenceObject();
  }
  if (local_1a0 != 0) {
    ObfDereferenceObject();
  }
  if (local_178 != 0) {
    FltClose();
  }
  if (local_170 != 0) {
    FltClose();
  }
  if (puVar7 != (uint *)0x0) {
    LuafvFreePool((longlong)puVar7);
  }
  if (local_188 != 0) {
    FltClose();
  }
  if (local_160 != 0) {
    FltClose();
  }
  if (puVar5 != (uint *)0x0) {
    LuafvFreePool((longlong)puVar5);
  }
  if (local_1a8 != 0) {
    ExFreePoolWithTag(local_1a8,0);
  }
  return iVar4;
LAB_14001f425:
  iVar4 = -0x3fffff66;
  goto LAB_14001f431;
}



===== LuafvLogUtcEvent @ 14001f59c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int LuafvLogUtcEvent(uint *param_1,longlong param_2,undefined8 param_3,longlong param_4,
                    longlong param_5,int param_6)

{
  short sVar1;
  char cVar2;
  ushort uVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  ushort uVar8;
  byte *pbVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong *puVar12;
  ulonglong *puVar13;
  uint uVar14;
  ulonglong uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined1 auStack_148 [40];
  undefined1 *local_120;
  int local_118;
  ushort local_110 [4];
  undefined8 uStack_108;
  uint *local_100;
  ulonglong *local_f8;
  uint uStack_f0;
  uint uStack_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  uint *local_c8;
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  undefined1 local_a8 [32];
  uint *local_88;
  undefined8 local_80;
  ulonglong *local_78;
  uint local_70 [2];
  uint *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50 [2];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_148;
  local_c0 = param_5;
  local_100 = (uint *)0x0;
  local_d8 = 0;
  uStack_d0 = (ulonglong *)0x0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_110[0] = 0;
  local_110[1] = 0;
  local_110[2] = 0;
  local_110[3] = 0;
  uStack_108 = 0;
  local_c8 = param_1;
  local_b8 = param_2;
  local_b0 = param_4;
  lVar4 = FltGetRequestorProcess(param_4);
  if (lVar4 == 0) {
    return -0x3ffff8e4;
  }
  local_118 = SeLocateProcessImageName(lVar4,&local_100);
  if (local_118 < 0) {
    return local_118;
  }
  local_f8 = *(ulonglong **)local_100;
  uStack_f0 = local_100[2];
  uStack_ec = local_100[3];
  uVar15 = (ulonglong)*local_100;
  uVar8 = (ushort)*local_100;
  while (1 < uVar8) {
    sVar1 = *(short *)(*(longlong *)(local_100 + 2) + -2 + (uVar15 & 0xfffe));
    if (((sVar1 != 0x5c) && (sVar1 != 0x2f)) && (sVar1 != 0)) break;
    uVar8 = (short)uVar15 - 2;
    uVar15 = (ulonglong)uVar8;
    uVar11 = (ulonglong)local_f8 >> 0x10;
    local_f8 = (ulonglong *)CONCAT62((int6)uVar11,uVar8);
  }
  uVar5 = LuafvPathGetFileNamePart_UStr((ushort *)&local_d8,(ushort *)&local_f8);
  if ((int)uVar5 < 0) {
    puVar12 = (ulonglong *)0x0;
    uVar8 = 0;
  }
  else {
    puVar12 = uStack_d0;
    uVar8 = (ushort)local_d8;
  }
  if (puVar12 != (ulonglong *)0x0) {
    uVar10 = 0;
    uVar14 = (uint)(uVar8 >> 1);
    puVar13 = puVar12;
    if (uVar8 >> 3 != 0) {
      puVar7 = puVar12 + (uint)(uVar8 >> 3);
      uVar15 = 0;
      local_f8 = puVar7;
      do {
        uVar11 = *puVar13;
        if ((uVar11 & 0xff80ff80ff80ff80) == 0) {
          uVar11 = uVar11 & 0xffdfffdfffdfffdf;
        }
        else {
          lVar4 = 4;
          do {
            uVar6 = uVar11 & 0xffff;
            uVar10 = (uint)uVar6;
            if (0x60 < uVar10) {
              if (uVar10 < 0x7b) {
                uVar6 = (ulonglong)(uVar10 - 0x20);
              }
              else {
                uVar3 = RtlUpcaseUnicodeChar(uVar11 & 0xffff);
                uVar6 = (ulonglong)uVar3;
              }
            }
            uVar11 = uVar11 >> 0x10 | uVar6 << 0x30;
            lVar4 = lVar4 + -1;
          } while (lVar4 != 0);
          puVar7 = local_f8;
        }
        puVar13 = puVar13 + 1;
        uVar15 = (uVar15 << 1 | (ulonglong)((longlong)uVar15 < 0)) ^ uVar11;
      } while (puVar13 < puVar7);
      uVar14 = uVar14 & 3;
      uVar10 = ((uint)(uVar15 >> 0x21) | (uint)(uVar15 << 0x1f)) ^ (uint)uVar15;
      uVar10 = uVar10 ^ (uVar10 >> 0x11 | uVar10 << 0xf);
      param_5 = local_c0;
      param_1 = local_c8;
    }
    puVar7 = (ulonglong *)((longlong)puVar13 + (ulonglong)uVar14 * 2);
    for (; puVar13 < puVar7; puVar13 = (ulonglong *)((longlong)puVar13 + 2)) {
      uVar3 = (ushort)*puVar13;
      uVar14 = (uint)uVar3;
      if (0x60 < uVar3) {
        if (uVar3 < 0x7b) {
          uVar14 = uVar3 - 0x20;
        }
        else {
          uVar3 = RtlUpcaseUnicodeChar(uVar3);
          uVar14 = (uint)uVar3;
        }
      }
      uVar10 = (uVar10 << 1 | (uint)((int)uVar10 < 0)) ^ uVar14;
    }
    uVar10 = (uVar10 >> 8 | uVar10 << 0x18) ^ uVar10;
    for (uVar15 = 0; uVar15 < 0x10; uVar15 = uVar15 + 1) {
      if (*(uint *)(local_b8 + uVar15 * 4) == uVar10) {
        return local_118;
      }
    }
    *(uint *)(local_b8 + (ulonglong)*param_1 * 4) = uVar10;
    *param_1 = *param_1 + 1 & 0xf;
    param_4 = local_b0;
  }
  if (param_5 == 0) {
    lVar4 = *(longlong *)(*(longlong *)(param_4 + 0x10) + 8);
    local_e8 = *(ulonglong *)(lVar4 + 0x58);
    uStack_e0 = *(longlong *)(lVar4 + 0x60);
    cVar2 = LuafvSupplyFullPath(param_4,&local_e8);
    uVar16 = (undefined4)local_e8;
    uVar17 = local_e8._4_4_;
    uVar18 = (undefined4)uStack_e0;
    uVar19 = uStack_e0._4_4_;
  }
  else {
    local_e8 = *(ulonglong *)(param_5 + 0x10);
    uStack_e0 = *(longlong *)(param_5 + 0x18);
    cVar2 = '\0';
    uVar16 = *(undefined4 *)(param_5 + 0x10);
    uVar17 = *(undefined4 *)(param_5 + 0x14);
    uVar18 = *(undefined4 *)(param_5 + 0x18);
    uVar19 = *(undefined4 *)(param_5 + 0x1c);
  }
  local_d8 = CONCAT44(uVar17,uVar16);
  uStack_d0 = (ulonglong *)CONCAT44(uVar19,uVar18);
  LuafvExtractFileNameFromPath(local_110,(ushort *)&local_d8);
  if (param_6 == 1) {
    if ((DAT_14000b010 < 6) || (uVar15 = _tlgKeywordOn(), (char)uVar15 == '\0')) goto LAB_14001f8f4;
    pbVar9 = &DAT_14000812a;
  }
  else if (param_6 == 2) {
    if ((DAT_14000b010 < 6) || (uVar15 = _tlgKeywordOn(), (char)uVar15 == '\0')) goto LAB_14001f8f4;
    pbVar9 = &DAT_1400080d0;
  }
  else {
    if (((param_6 != 3) || (DAT_14000b010 < 6)) || (uVar15 = _tlgKeywordOn(), (char)uVar15 == '\0'))
    goto LAB_14001f8f4;
    pbVar9 = &DAT_140008071;
  }
  local_88 = local_70;
  local_80 = 2;
  local_70[0] = uVar8 & 0xfffffffe;
  local_68 = local_50;
  local_58 = uStack_108;
  local_50[0] = local_110[0] & 0xfffffffe;
  local_70[1] = 0;
  local_120 = local_a8;
  local_60 = 2;
  local_50[1] = 0;
  local_78 = puVar12;
  _tlgWriteTransfer_EtwWriteTransfer(0xfffffffe,pbVar9);
LAB_14001f8f4:
  if (cVar2 != '\0') {
    LuafvFreePool(uStack_e0);
  }
  return local_118;
}



===== LuafvSetFileCreateEvent @ 14001f934 =====

void LuafvSetFileCreateEvent(longlong param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  
  if (param_2 == (longlong *)0x0) {
    param_2 = (longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
    lVar1 = *param_2 + 0x10;
  }
  else {
    lVar1 = (longlong)param_2 + 0xc;
  }
  *(undefined4 *)(param_3 + 0x7c) = 0;
  *(longlong **)(param_3 + 0x70) = param_2 + 1;
  *(undefined4 *)(param_3 + 0x78) = 4;
  *(undefined4 *)(param_3 + 0x8c) = 0;
  *(longlong *)(param_3 + 0x80) = lVar1;
  *(undefined4 *)(param_3 + 0x88) = 4;
  return;
}



===== LuafvDelayOrVirtualizeFile @ 14001f984 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LuafvDelayOrVirtualizeFile
                    (longlong param_1,longlong param_2,ulonglong *param_3,byte *param_4,
                    undefined1 *param_5,uint *param_6)

{
  bool bVar1;
  uint uVar2;
  short *psVar3;
  ulonglong uVar4;
  byte bVar5;
  int iVar6;
  ulonglong uVar7;
  bool bVar8;
  undefined1 auStack_158 [32];
  uint local_138;
  undefined8 *local_130;
  uint *local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined4 local_110;
  undefined4 local_108;
  uint local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  longlong local_d8;
  undefined8 local_d0;
  ulonglong *local_c8;
  byte *local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  ushort *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_158;
  bVar8 = false;
  local_d8 = 0;
  local_d0 = 0;
  local_b8 = param_5;
  local_60 = 0;
  local_a0 = (ushort *)*param_3;
  bVar5 = 0;
  if (*param_4 != 0) {
    bVar5 = DAT_14000c0fc;
  }
  bVar1 = false;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  psVar3 = (short *)((ulonglong)*local_a0 + (longlong)*(short **)(local_a0 + 4));
  do {
    while( true ) {
      if (psVar3 <= *(short **)(local_a0 + 4)) goto LAB_14001fa30;
      psVar3 = psVar3 + -1;
      if (*psVar3 != 0x3a) break;
      bVar1 = true;
    }
  } while (*psVar3 != 0x5c);
LAB_14001fa30:
  local_c0 = param_4;
  if (((local_a0[0x2c] & 2) != 0) || (!bVar1)) {
    if (((DAT_14000c0f8 & 8) == 0) || (*param_6 == 0)) {
      local_e0 = 0;
      local_e8 = 0xa01;
      local_f0 = 0;
      local_f8 = 0;
      local_b0 = 0x30;
      uStack_a8 = 0;
      uStack_98 = 0x240;
      local_90 = 0;
      uStack_88 = 0;
      local_100 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0xffefff;
      local_138 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0xfff2fea9
                  | 0x81;
      local_108 = 1;
      local_130 = &local_b0;
      local_110 = 7;
      local_118 = 0;
      local_120 = 0;
      local_128 = (uint *)(param_1 + 0x18);
      local_c8 = param_3;
      uVar2 = FltCreateFileEx2(LuafvDriverData,*(undefined8 *)(param_2 + 0x18),&local_d8,&local_d0);
      uVar7 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        if (bVar5 != 0) {
          local_130 = (undefined8 *)0x0;
          local_138 = 4;
          uVar2 = FltQueryInformationFile(*(undefined8 *)(param_2 + 0x18),local_d0,&local_80,0x28);
          uVar7 = (ulonglong)uVar2;
          if (-1 < (int)uVar2) {
            bVar5 = ~((byte)local_60 >> 4) & 1;
          }
        }
        ObfDereferenceObject(local_d0);
        if ((int)uVar7 < 0) {
          FltClose(local_d8);
          local_d8 = 0;
        }
      }
      iVar6 = (int)uVar7;
      if ((iVar6 == -0x3fffffcc) || (iVar6 == -0x3fffffc6)) {
        bVar5 = 0;
      }
      else {
        if (iVar6 < 0) goto LAB_14001fbf3;
        if (bVar5 != 0) {
          uVar2 = LuafvPrepareDelayedVirtualization(param_2,param_1,(longlong *)local_c8,local_d8);
          uVar7 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            *(uint *)(param_1 + 0x18) = uVar2;
            *(undefined8 *)(param_1 + 0x20) = 0;
          }
          goto LAB_14001fbf3;
        }
      }
      uVar4 = LuafvCreateVirtualFile(param_2,param_1,local_c8,local_d8);
      uVar7 = uVar4 & 0xffffffff;
      if (local_d8 != 0) {
        FltClose();
      }
      bVar8 = (int)uVar4 != -0x3fffffde;
      goto LAB_14001fbf3;
    }
  }
  else if ((DAT_14000c0f8 & 8) != 0) {
    *param_6 = *param_6 | 0x40;
  }
  uVar7 = 0xc0000022;
LAB_14001fbf3:
  *local_c0 = bVar5;
  *local_b8 = bVar8;
  return uVar7;
}



===== LuafvScavengeUserList @ 14001fc2c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LuafvScavengeUserList(char param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  
  lVar8 = _DAT_fffff78000000014 + -3000000000;
  FltAcquirePushLockExclusiveEx(&UserListLock,0);
  puVar9 = UserList;
  while( true ) {
    while( true ) {
      if ((undefined8 **)puVar9 == &UserList) {
        FltReleasePushLockEx(&UserListLock,0);
        return;
      }
      puVar1 = (undefined8 *)*puVar9;
      if ((param_1 != '\0') || ((longlong)puVar9[2] < lVar8)) break;
      puVar3 = puVar9 + 4;
      puVar9 = (undefined8 *)*puVar3;
      while (puVar10 = puVar9, puVar9 = puVar1, puVar10 != puVar3) {
        puVar9 = (undefined8 *)*puVar10;
        if (*(char *)((longlong)puVar10 + 0x51) != '\0') {
          if (((undefined8 *)puVar9[1] != puVar10) ||
             (puVar2 = (undefined8 *)puVar10[1], (undefined8 *)*puVar2 != puVar10))
          goto LAB_14001fd55;
          *puVar2 = puVar9;
          puVar9[1] = puVar2;
          LuafvDereferenceUserStore((longlong)puVar10);
        }
      }
    }
    if (((undefined8 *)puVar1[1] != puVar9) ||
       (puVar3 = (undefined8 *)puVar9[1], (undefined8 *)*puVar3 != puVar9)) break;
    *puVar3 = puVar1;
    puVar1[1] = puVar3;
    while (plVar4 = (longlong *)puVar9[4], plVar4 != puVar9 + 4) {
      lVar5 = *plVar4;
      if ((*(longlong **)(lVar5 + 8) != plVar4) ||
         (plVar6 = (longlong *)plVar4[1], (longlong *)*plVar6 != plVar4)) goto LAB_14001fd55;
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      LuafvDereferenceUserStore((longlong)plVar4);
    }
    LuafvDereferenceUser((longlong)puVar9);
    puVar9 = puVar1;
  }
LAB_14001fd55:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== InitializeFileTableForVolumePreWorker @ 14001fd70 =====

void InitializeFileTableForVolumePreWorker(longlong param_1,ulonglong param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x1e) >> 4 & 1;
  if (bVar1 != 0) {
    RemoveFileIdTableNode(param_1);
  }
  *(ulonglong *)(param_1 + 0xa8) = *(byte *)(param_1 + 0xa8) & 7 | param_2;
  if (bVar1 != 0) {
    InsertFileIdTableNode(param_1);
  }
  return;
}



===== LuafvInitializeUsn @ 14001fdd0 =====

ulonglong LuafvInitializeUsn(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  longlong *plVar7;
  uint uVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 local_res8;
  
  local_res8 = 0;
  ExInitializePushLock(param_1 + 0x108);
  *(undefined4 *)(param_1 + 0x340) = 0;
  KeInitializeEvent(param_1 + 0x58,0);
  KeInitializeEvent(param_1 + 0x70,0);
  KeInitializeEvent(param_1 + 0x88,1);
  KeInitializeEvent(param_1 + 0xa0,0,0);
  KeInitializeEvent(param_1 + 0xb8,1,0);
  KeInitializeEvent(param_1 + 0xd0,0,0);
  plVar2 = (longlong *)(param_1 + 0x330);
  uVar6 = 0;
  lVar3 = param_1 + 0x310;
  *(longlong *)(param_1 + 0x318) = lVar3;
  *(longlong *)lVar3 = lVar3;
  lVar3 = param_1 + 800;
  *(longlong *)(param_1 + 0x328) = lVar3;
  *(longlong *)lVar3 = lVar3;
  *(longlong *)(param_1 + 0x338) = (longlong)plVar2;
  *plVar2 = (longlong)plVar2;
  plVar9 = plVar2;
  plVar10 = plVar2;
  while( true ) {
    plVar7 = (longlong *)(uVar6 * 0x20 + 0x110 + param_1);
    if (plVar10 != plVar2) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar6 = (*pcVar4)();
      return uVar6;
    }
    *plVar7 = (longlong)plVar2;
    uVar8 = (int)uVar6 + 1;
    uVar6 = (ulonglong)uVar8;
    plVar7[1] = (longlong)plVar9;
    *plVar9 = (longlong)plVar7;
    *(longlong *)(param_1 + 0x338) = (longlong)plVar7;
    if (0xf < uVar8) break;
    plVar10 = (longlong *)*plVar7;
    plVar9 = plVar7;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0x1008;
  puVar5 = (undefined4 *)ExAllocatePool2(0x100,0x1010,0x6661754c);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 0x1008;
    *(undefined1 *)(puVar5 + 1) = 0xff;
    FltAcquirePushLockExclusiveEx(&PoolLock);
    DAT_14000c2a4 = DAT_14000c2a4 + 0x1008;
    FltReleasePushLockEx(&PoolLock);
    puVar5 = puVar5 + 2;
  }
  *(undefined4 **)(param_1 + 0xe8) = puVar5;
  if (puVar5 == (undefined4 *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    memset(puVar5,0,(ulonglong)*(uint *)(param_1 + 0xf0));
    uVar6 = InitializeUsn(param_1);
    if (-1 < (int)uVar6) {
      uVar6 = PsCreateSystemThread(&local_res8,0x1fffff,0,0,0,UsnThread,param_1);
      if (-1 < (int)uVar6) {
        puVar1 = (undefined8 *)(param_1 + 0x48);
        ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,puVar1,0);
        ZwClose(local_res8);
        KeWaitForSingleObject(param_1 + 0x58,0,0,0,0);
        if (*(int *)(param_1 + 0xf4) < 0) {
          KeWaitForSingleObject(*puVar1,0,0,0,0);
          ObfDereferenceObject(*puVar1);
          uVar6 = (ulonglong)*(uint *)(param_1 + 0xf4);
        }
        else {
          uVar6 = 0;
        }
      }
    }
  }
  return uVar6;
}



===== UserLogoffCallback @ 140020090 =====

undefined8 UserLogoffCallback(int *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  
  FltAcquirePushLockExclusiveEx(&UserListLock,0);
  puVar1 = UserList;
  while( true ) {
    do {
      puVar8 = puVar1;
      if ((undefined8 **)puVar8 == &UserList) {
        FltReleasePushLockEx(&UserListLock,0);
        return 0;
      }
      puVar1 = (undefined8 *)*puVar8;
    } while (((*(int *)(puVar8 + 6) != *param_1) ||
             (*(int *)((longlong)puVar8 + 0x34) != param_1[1])) || (puVar8[7] != param_2));
    if (((undefined8 *)puVar1[1] != puVar8) ||
       (puVar2 = (undefined8 *)puVar8[1], (undefined8 *)*puVar2 != puVar8)) break;
    *puVar2 = puVar1;
    puVar1[1] = puVar2;
    while (plVar3 = (longlong *)puVar8[4], plVar3 != puVar8 + 4) {
      lVar4 = *plVar3;
      if ((*(longlong **)(lVar4 + 8) != plVar3) ||
         (plVar5 = (longlong *)plVar3[1], (longlong *)*plVar5 != plVar3)) goto LAB_140020170;
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      LuafvDereferenceUserStore((longlong)plVar3);
    }
    LuafvDereferenceUser((longlong)puVar8);
  }
LAB_140020170:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  uVar7 = (*pcVar6)();
  return uVar7;
}



===== LuafvPostSetInformationSafe @ 140020180 =====

undefined8 LuafvPostSetInformationSafe(longlong param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  iVar1 = *(int *)(lVar2 + 0x20);
  if (iVar1 != 10) {
    if (iVar1 == 0xd) {
      *(byte *)((longlong)param_3 + 0x15) =
           -(**(char **)(lVar2 + 0x38) != '\0') & 8U | *(byte *)((longlong)param_3 + 0x15) & 0xf7;
      goto LAB_1400201b3;
    }
    if (iVar1 == 0x40) {
      *(byte *)((longlong)param_3 + 0x15) =
           (**(byte **)(lVar2 + 0x38) & 1) << 3 | *(byte *)((longlong)param_3 + 0x15) & 0xf7;
      goto LAB_1400201b3;
    }
    if (iVar1 != 0x41) goto LAB_1400201b3;
  }
  LuafvLogVirtualRename(param_1,param_3,'\x01','\0');
LAB_1400201b3:
  FltReleaseContext(param_3);
  return 0;
}



===== LuafvCopyDirectoryEntry @ 140020204 =====

void LuafvCopyDirectoryEntry
               (longlong param_1,int param_2,ulonglong param_3,char param_4,uint *param_5,
               void *param_6,char param_7,char param_8,longlong *param_9,undefined1 *param_10)

{
  void *_Dst;
  uint uVar1;
  uint *_Src;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  
  _Src = *(uint **)(param_1 + 0x18);
  uVar4 = 0;
  uVar1 = *_Src;
  uVar6 = *(int *)((param_3 & 0xffffffff) + (longlong)_Src) + param_2;
  uVar3 = (ulonglong)uVar6;
  _Dst = (void *)((longlong)param_5 + uVar3);
  if (param_6 <= _Dst) {
    if (param_7 == '\0') {
      uVar3 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
      uVar2 = (ulonglong)(((int)param_6 - (int)param_5) - 1);
      if ((int)uVar3 == 0) {
        memmove(param_5,_Src,uVar2);
      }
      else if (param_4 == '\0') {
        RtlCopyVolatileMemory(param_5,_Src,uVar2);
      }
      else {
        RtlCopyToUser(param_5,_Src,uVar2);
      }
    }
    uVar4 = 1;
    goto LAB_140020359;
  }
  if (param_8 == '\0') {
    uVar5 = uVar6 + 7 & 0xfffffff8;
    if (param_6 <= (void *)((ulonglong)uVar5 + (longlong)param_5)) {
      uVar5 = ((int)param_6 - (int)param_5) - 1;
    }
  }
  else {
    uVar5 = uVar6;
  }
  if (param_7 == '\0') {
    uVar2 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      memmove(param_5,_Src,uVar3);
      memset((void *)((longlong)param_5 + uVar3),0,(ulonglong)(uVar5 - uVar6));
LAB_1400202ed:
      *param_5 = uVar5;
    }
    else {
      if (param_4 == '\0') {
        RtlCopyVolatileMemory(param_5,_Src,uVar3);
      }
      else {
        RtlCopyToUser(param_5,_Src,uVar3);
      }
      if (param_4 == '\0') {
        RtlSetVolatileMemory(_Dst,0,(ulonglong)(uVar5 - uVar6));
        goto LAB_1400202ed;
      }
      RtlSetUserMemory(_Dst,0,(ulonglong)(uVar5 - uVar6));
      RtlWriteULongToUser(param_5,uVar5);
    }
    if (param_9 != (longlong *)0x0) {
      *param_9 = (ulonglong)uVar5 + (longlong)param_5;
    }
  }
  if (uVar1 == 0) {
    *(ulonglong *)(param_1 + 0x18) =
         (ulonglong)*(uint *)(param_1 + 0xc) + *(longlong *)(param_1 + 0x10);
  }
  else {
    *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + (ulonglong)uVar1;
  }
LAB_140020359:
  *param_10 = uVar4;
  return;
}



===== LuafvCopyNextDirectoryEntry @ 140020388 =====

undefined1
LuafvCopyNextDirectoryEntry
          (longlong param_1,int param_2,char param_3,uint *param_4,void *param_5,char param_6,
          longlong *param_7,char *param_8)

{
  uint *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  byte bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 *_Src;
  undefined8 *puVar9;
  longlong lVar10;
  char cVar11;
  ulonglong uVar12;
  uint local_38;
  uint local_34 [3];
  
  lVar2 = *(longlong *)(param_1 + 0x60);
  bVar4 = 0;
  local_38 = 0;
  local_34[0] = 0;
  bVar5 = false;
  cVar11 = '\0';
  LuafvQueryCommonDirectoryClass(param_2,&local_38,local_34);
  uVar6 = local_34[0];
  uVar8 = *(ulonglong *)(lVar2 + 0x18);
  uVar12 = (ulonglong)local_34[0];
  if (uVar8 == 0) {
LAB_140020518:
    if (*(ulonglong *)(lVar2 + 0x38) == 0) {
      return 0;
    }
    if ((ulonglong)*(uint *)(lVar2 + 0x2c) + *(longlong *)(lVar2 + 0x30) <=
        *(ulonglong *)(lVar2 + 0x38)) {
      return 0;
    }
    if (uVar8 == 0) {
      return 0;
    }
    if (*(int *)(lVar2 + 8) == 0) {
      return 0;
    }
LAB_140020549:
    lVar10 = *(longlong *)(lVar2 + 0x38);
    if ((((*(int *)(uVar12 + lVar10) - 2U & 0xfffffffd) == 0) &&
        (*(short *)((ulonglong)local_38 + lVar10) == 0x2e)) &&
       ((*(int *)(uVar12 + lVar10) == 2 || (*(short *)((ulonglong)local_38 + 2 + lVar10) == 0x2e))))
    {
      cVar11 = '\x01';
    }
  }
  else {
    if ((ulonglong)*(uint *)(lVar2 + 0xc) + *(longlong *)(lVar2 + 0x10) <= uVar8) {
      if (uVar8 != 0) goto LAB_1400204ed;
      goto LAB_140020518;
    }
    if ((*(ulonglong *)(lVar2 + 0x38) == 0) ||
       ((ulonglong)*(uint *)(lVar2 + 0x2c) + *(longlong *)(lVar2 + 0x30) <=
        *(ulonglong *)(lVar2 + 0x38))) {
LAB_1400204ed:
      if ((((ulonglong)*(uint *)(lVar2 + 0xc) + *(longlong *)(lVar2 + 0x10) <= uVar8) ||
          (*(longlong *)(lVar2 + 0x38) == 0)) || (*(int *)(lVar2 + 0x28) == 0)) goto LAB_140020518;
LAB_14002050e:
      bVar4 = 1;
      goto LAB_1400208db;
    }
    iVar7 = LuafvCompareDirectoryEntryName(param_1,local_38,local_34[0]);
    if (iVar7 < 0) goto LAB_14002050e;
    if (0 < iVar7) goto LAB_140020549;
    bVar5 = true;
    if (param_2 < 0x3d) {
      if (((param_2 == 0x3c) || (param_2 == 1)) || ((param_2 == 2 || (param_2 == 3))))
      goto LAB_14002046e;
      if (param_2 != 0xc) {
        iVar7 = param_2 + -0x25;
        goto LAB_140020463;
      }
    }
    else {
      if (((param_2 != 0x3f) && (param_2 != 0x4e)) && (param_2 != 0x4f)) {
        iVar7 = param_2 + -0x50;
LAB_140020463:
        if ((iVar7 != 0) && (iVar7 != 1)) goto LAB_14002050e;
      }
LAB_14002046e:
      if (((*(uint *)(*(longlong *)(lVar2 + 0x18) + 0x38) ^
           *(uint *)(*(longlong *)(lVar2 + 0x38) + 0x38)) & 0x10) != 0) {
        LuafvCopyDirectoryEntry
                  (lVar2 + 0x20,local_38,(ulonglong)uVar6,param_3,param_4,param_5,'\x01',param_6,
                   (longlong *)0x0,param_8);
        goto LAB_14002050e;
      }
    }
  }
  LuafvCopyDirectoryEntry
            (lVar2 + 0x20,local_38,uVar12,param_3,param_4,param_5,cVar11,param_6,param_7,param_8);
  if (*param_8 == '\0') {
    if (cVar11 != '\0') {
      return 0;
    }
    if (bVar5) {
      if ((param_2 == 3) || (param_2 == 0x25)) {
        uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        lVar10 = *(longlong *)(lVar2 + 0x18);
        puVar1 = param_4 + 0x11;
        puVar9 = (undefined8 *)(lVar10 + 0x44);
        if ((int)uVar8 == 0) {
          uVar3 = *(undefined8 *)(lVar10 + 0x4c);
          *(undefined8 *)puVar1 = *puVar9;
          *(undefined8 *)(param_4 + 0x13) = uVar3;
          *(undefined8 *)(param_4 + 0x15) = *(undefined8 *)(lVar10 + 0x54);
          *(undefined1 *)(param_4 + 0x17) = *(undefined1 *)(lVar10 + 0x5c);
        }
        else if (param_3 == '\0') {
          RtlCopyVolatileMemory(puVar1,puVar9,0x19);
        }
        else {
          RtlCopyToUser(puVar1,puVar9,0x19);
        }
      }
      if ((param_2 == 0x25) || (param_2 == 0x26)) {
        uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        lVar10 = 0x48;
        if (param_2 != 0x26) {
          lVar10 = 0x60;
        }
        _Src = (undefined8 *)(*(longlong *)(lVar2 + 0x18) + lVar10);
        puVar9 = (undefined8 *)(lVar10 + (longlong)param_4);
        if ((int)uVar8 == 0) {
          *puVar9 = *_Src;
        }
        else if (param_3 == '\0') {
          RtlCopyVolatileMemory(puVar9,_Src,8);
        }
        else {
          RtlCopyToUser(puVar9,_Src,8);
        }
      }
      if (param_2 == 0x4e) {
LAB_1400206e7:
        uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        puVar1 = param_4 + 0x12;
        puVar9 = (undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x48);
        if ((int)uVar8 == 0) {
          *(undefined8 *)puVar1 = *puVar9;
        }
        else if (param_3 == '\0') {
          RtlCopyVolatileMemory(puVar1,puVar9,8);
        }
        else {
          RtlCopyToUser(puVar1,puVar9,8);
        }
      }
      else if (param_2 == 0x4f) {
        uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        lVar10 = *(longlong *)(lVar2 + 0x18);
        puVar1 = param_4 + 0x14;
        puVar9 = (undefined8 *)(lVar10 + 0x50);
        if ((int)uVar8 == 0) {
          uVar3 = *(undefined8 *)(lVar10 + 0x58);
          *(undefined8 *)puVar1 = *puVar9;
          *(undefined8 *)(param_4 + 0x16) = uVar3;
          *(undefined8 *)(param_4 + 0x18) = *(undefined8 *)(lVar10 + 0x60);
          *(undefined1 *)(param_4 + 0x1a) = *(undefined1 *)(lVar10 + 0x68);
        }
        else if (param_3 == '\0') {
          RtlCopyVolatileMemory(puVar1,puVar9,0x19);
        }
        else {
          RtlCopyToUser(puVar1,puVar9,0x19);
        }
        goto LAB_1400206e7;
      }
      if (param_2 == 0x3c) {
LAB_140020764:
        uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        puVar1 = param_4 + 0x12;
        puVar9 = (undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x48);
        if ((int)uVar8 == 0) {
          uVar3 = *(undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x50);
          *(undefined8 *)puVar1 = *puVar9;
          *(undefined8 *)(param_4 + 0x14) = uVar3;
        }
        else if (param_3 == '\0') {
          RtlCopyVolatileMemory(puVar1,puVar9,0x10);
        }
        else {
          RtlCopyToUser(puVar1,puVar9,0x10);
        }
      }
      else if (param_2 == 0x3f) {
        uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        lVar10 = *(longlong *)(lVar2 + 0x18);
        puVar1 = param_4 + 0x16;
        puVar9 = (undefined8 *)(lVar10 + 0x58);
        if ((int)uVar8 == 0) {
          uVar3 = *(undefined8 *)(lVar10 + 0x60);
          *(undefined8 *)puVar1 = *puVar9;
          *(undefined8 *)(param_4 + 0x18) = uVar3;
          *(undefined8 *)(param_4 + 0x1a) = *(undefined8 *)(lVar10 + 0x68);
          *(undefined1 *)(param_4 + 0x1c) = *(undefined1 *)(lVar10 + 0x70);
        }
        else if (param_3 == '\0') {
          RtlCopyVolatileMemory(puVar1,puVar9,0x19);
        }
        else {
          RtlCopyToUser(puVar1,puVar9,0x19);
        }
        goto LAB_140020764;
      }
      if (param_2 != 0x50) {
        if (param_2 != 0x51) goto LAB_140020853;
        uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        lVar10 = *(longlong *)(lVar2 + 0x18);
        puVar1 = param_4 + 0x18;
        puVar9 = (undefined8 *)(lVar10 + 0x60);
        if ((int)uVar8 == 0) {
          uVar3 = *(undefined8 *)(lVar10 + 0x68);
          *(undefined8 *)puVar1 = *puVar9;
          *(undefined8 *)(param_4 + 0x1a) = uVar3;
          *(undefined8 *)(param_4 + 0x1c) = *(undefined8 *)(lVar10 + 0x70);
          *(undefined1 *)(param_4 + 0x1e) = *(undefined1 *)(lVar10 + 0x78);
        }
        else if (param_3 == '\0') {
          RtlCopyVolatileMemory(puVar1,puVar9,0x19);
        }
        else {
          RtlCopyToUser(puVar1,puVar9,0x19);
        }
      }
      uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
      puVar1 = param_4 + 0x12;
      puVar9 = (undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x48);
      if ((int)uVar8 == 0) {
        *(undefined8 *)puVar1 = *puVar9;
      }
      else if (param_3 == '\0') {
        RtlCopyVolatileMemory(puVar1,puVar9,8);
      }
      else {
        RtlCopyToUser(puVar1,puVar9,8);
      }
      uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
      puVar1 = param_4 + 0x14;
      puVar9 = (undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x50);
      if ((int)uVar8 == 0) {
        uVar3 = *(undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x58);
        *(undefined8 *)puVar1 = *puVar9;
        *(undefined8 *)(param_4 + 0x16) = uVar3;
      }
      else if (param_3 == '\0') {
        RtlCopyVolatileMemory(puVar1,puVar9,0x10);
      }
      else {
        RtlCopyToUser(puVar1,puVar9,0x10);
      }
    }
LAB_140020853:
    if (param_2 < 0x3d) {
      if (((param_2 != 0x3c) && (param_2 != 1)) && ((param_2 != 2 && (param_2 != 3)))) {
        iVar7 = param_2 + -0x25;
LAB_14002086c:
        if ((iVar7 != 0) && (iVar7 != 1)) goto LAB_1400208cb;
      }
    }
    else if (((param_2 != 0x3f) && (param_2 != 0x4e)) && (param_2 != 0x4f)) {
      iVar7 = param_2 + -0x50;
      goto LAB_14002086c;
    }
    uVar8 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar8 == 0) {
      param_4[0xe] = param_4[0xe] | 0x10000;
    }
    else {
      puVar1 = param_4 + 0xe;
      if (param_3 == '\0') {
        uVar12 = (ulonglong)local_34[0];
        *puVar1 = *puVar1 | 0x10000;
      }
      else {
        uVar8 = RtlReadULongFromUser(puVar1);
        RtlWriteULongToUser(puVar1,(uint)uVar8 | 0x10000);
      }
    }
  }
  else {
    bVar5 = false;
  }
LAB_1400208cb:
  cVar11 = '\x01';
  if (!bVar5) {
    return 1;
  }
LAB_1400208db:
  LuafvCopyDirectoryEntry
            (lVar2,local_38,uVar12,param_3,param_4,param_5,cVar11,param_6,
             (longlong *)(-(ulonglong)bVar4 & (ulonglong)param_7),param_8);
  return 1;
}



===== LuafvMergeStoreDirectory @ 140020954 =====

int LuafvMergeStoreDirectory
              (undefined8 param_1,longlong param_2,uint param_3,char param_4,int param_5,
              char param_6,undefined8 param_7,char param_8,undefined4 *param_9,uint *param_10)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *local_70;
  uint *local_68;
  uint *local_60;
  undefined8 *local_58;
  undefined8 *local_50;
  uint *local_48;
  
  puVar10 = param_10;
  local_70 = (uint *)0x0;
  puVar1 = *(undefined8 **)(param_2 + 0x60);
  local_68 = param_10;
  local_60 = param_10;
  puVar11 = (uint *)((ulonglong)param_3 + (longlong)param_10);
  param_10._0_1_ = '\0';
  bVar3 = false;
  puVar7 = puVar10;
  local_58 = puVar1;
  local_50 = puVar1 + 4;
  local_48 = puVar11;
  do {
    do {
      uVar6 = LuafvQueryDirectoryIfNeeded(param_1,puVar1,param_6,param_5,param_7,param_8);
      iVar5 = (int)uVar6;
      puVar8 = puVar7;
      if (-1 < iVar5) {
        uVar6 = LuafvQueryDirectoryIfNeeded(param_1,puVar1 + 4,param_6,param_5,param_7,param_8);
        iVar5 = (int)uVar6;
        if (-1 < iVar5) {
          local_70 = (uint *)0x0;
          cVar4 = LuafvCopyNextDirectoryEntry
                            (param_2,param_5,param_4,puVar7,puVar11,param_6,(longlong *)&local_70,
                             (char *)&param_10);
          if ((cVar4 != '\0') && (puVar8 = puVar11, local_68 = puVar11, (char)param_10 == '\0')) {
            local_68 = local_70;
            bVar3 = true;
            puVar8 = local_70;
            puVar10 = puVar7;
            local_60 = puVar7;
          }
        }
      }
      param_8 = '\0';
      if ((((param_6 != '\0') && (bVar3)) || (iVar5 != 0)) || (puVar11 <= puVar8))
      goto LAB_140020b77;
      uVar6 = puVar1[3];
      puVar7 = puVar8;
    } while ((uVar6 != 0) && (uVar6 < (ulonglong)*(uint *)((longlong)puVar1 + 0xc) + puVar1[2]));
    uVar2 = puVar1[7];
  } while ((((uVar2 != 0) && (uVar2 < (ulonglong)*(uint *)((longlong)puVar1 + 0x2c) + puVar1[6])) ||
           (((uVar6 == 0 || (*(int *)(puVar1 + 1) == 0)) || (uVar2 == 0)))) ||
          (*(int *)(puVar1 + 5) == 0));
LAB_140020b77:
  if (-1 < iVar5) {
    if (bVar3) {
      uVar6 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar6 == 0) {
        *puVar10 = 0;
      }
      else if (param_4 == '\0') {
        *puVar10 = 0;
      }
      else {
        RtlWriteULongToUser(puVar10,0);
      }
      *(ulonglong *)(param_9 + 2) = (ulonglong)(((int)puVar8 - (int)puVar11) + param_3);
      *param_9 = 0;
    }
    else {
      *(undefined8 *)(param_9 + 2) = 0;
      uVar9 = 0x80000005;
      if ((*(int *)(puVar1 + 1) != -0x7ffffffb) && (*(int *)(puVar1 + 5) != -0x7ffffffb)) {
        if ((char)param_10 == '\0') {
          uVar9 = 0x80000006;
          if ((*(int *)(puVar1 + 1) != -0x7ffffffa) && (*(int *)(puVar1 + 5) != -0x7ffffffa)) {
            *param_9 = 0xc000000f;
            return iVar5;
          }
        }
        else {
          *(ulonglong *)(param_9 + 2) = (ulonglong)(((int)puVar8 - (int)puVar11) + param_3);
        }
      }
      *param_9 = uVar9;
    }
  }
  return iVar5;
}



===== LuafvQueryCommonDirectoryClass @ 140020c48 =====

void LuafvQueryCommonDirectoryClass(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 < 0x3d) {
    if (param_1 == 0x3c) {
      *param_2 = 0x58;
      goto LAB_140020ce9;
    }
    if (param_1 == 1) {
      *param_2 = 0x40;
      goto LAB_140020ce9;
    }
    if (param_1 == 2) {
      *param_2 = 0x44;
      goto LAB_140020ce9;
    }
    if (param_1 == 3) {
      *param_2 = 0x5e;
      goto LAB_140020ce9;
    }
    if (param_1 == 0xc) {
      *param_2 = 0xc;
      *param_3 = 8;
      return;
    }
    if (param_1 == 0x25) {
      *param_2 = 0x68;
      goto LAB_140020ce9;
    }
    if (param_1 != 0x26) {
      return;
    }
  }
  else {
    if (param_1 == 0x3f) {
      *param_2 = 0x72;
      goto LAB_140020ce9;
    }
    if (param_1 != 0x4e) {
      if (param_1 == 0x4f) {
        *param_2 = 0x6a;
      }
      else if (param_1 == 0x50) {
        *param_2 = 0x60;
      }
      else {
        if (param_1 != 0x51) {
          return;
        }
        *param_2 = 0x7a;
      }
      goto LAB_140020ce9;
    }
  }
  *param_2 = 0x50;
LAB_140020ce9:
  *param_3 = 0x3c;
  return;
}



===== LuafvQueryStoreDirectory @ 140020cf4 =====

uint LuafvQueryStoreDirectory(undefined8 param_1,uint *param_2,longlong param_3)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  uint *puVar9;
  ulonglong uVar10;
  byte bVar11;
  char cVar12;
  
  lVar5 = *(longlong *)(param_2 + 4);
  lVar6 = *(longlong *)(param_3 + 0x20);
  cVar12 = '\0';
  uVar3 = *(uint *)(lVar5 + 0x18);
  if (*(void **)(lVar6 + 8) == SystemReserved1[0xf]) {
    *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
  }
  else {
    FltAcquirePushLockExclusiveEx(lVar6,0);
    *(void **)(lVar6 + 8) = SystemReserved1[0xf];
    *(undefined4 *)(lVar6 + 0x10) = 1;
  }
  if (*(longlong *)(param_3 + 0x60) == 0) {
    puVar9 = LuafvAllocatePool(1,0x40,'\x16');
    *(uint **)(param_3 + 0x60) = puVar9;
    if (puVar9 != (uint *)0x0) {
      memset(puVar9,0,0x40);
      goto LAB_140020da1;
    }
    uVar8 = 0xc000009a;
  }
  else {
LAB_140020da1:
    uVar8 = LuafvOpenDirectory(param_1,param_3,*(longlong **)(param_3 + 0x60),uVar3);
    if ((-1 < (int)uVar8) &&
       (uVar8 = LuafvOpenDirectory(param_1,param_3 + 0x30,
                                   (longlong *)(*(longlong *)(param_3 + 0x60) + 0x20),uVar3),
       -1 < (int)uVar8)) {
      iVar4 = *(int *)(lVar5 + 0x28);
      bVar2 = *(byte *)(*(longlong *)(param_2 + 4) + 6);
      uVar7 = *(undefined8 *)(lVar5 + 0x20);
      bVar11 = bVar2 & 1;
      uVar10 = Feature_2961076537__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar10 != 0) && (bVar11 == 0)) {
        bVar11 = 0;
        if (*(int *)(param_3 + 0x70) != iVar4) {
          bVar11 = 1;
        }
      }
      lVar6 = *(longlong *)(lVar5 + 0x40);
      if (lVar6 == 0) {
        puVar9 = *(uint **)(lVar5 + 0x38);
        uVar10 = Feature_Bugfix_LuafvUMA__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar10 != 0) && ((*param_2 & 8) == 0)) {
          cVar12 = (char)param_2[0x14];
        }
      }
      else {
        if ((*(byte *)(lVar6 + 10) & 5) == 0) {
          puVar9 = (uint *)MmMapLockedPagesSpecifyCache(lVar6,0,1,0,0,0x40000010);
        }
        else {
          puVar9 = *(uint **)(lVar6 + 0x18);
        }
        cVar12 = '\0';
        if (puVar9 == (uint *)0x0) {
          uVar8 = 0xc000009a;
        }
        if ((int)uVar8 < 0) goto LAB_140020ef0;
      }
      uVar8 = LuafvMergeStoreDirectory
                        (param_1,param_3,uVar3,cVar12,iVar4,bVar2 >> 1 & 1,uVar7,bVar11,param_2 + 6,
                         puVar9);
      uVar10 = Feature_2961076537__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar10 != 0) && (-1 < (int)uVar8)) {
        *(int *)(param_3 + 0x70) = iVar4;
      }
    }
  }
LAB_140020ef0:
  lVar5 = *(longlong *)(param_3 + 0x20);
  if (*(void **)(lVar5 + 8) == SystemReserved1[0xf]) {
    piVar1 = (int *)(lVar5 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) goto LAB_140020f1b;
    *(undefined8 *)(lVar5 + 8) = 0;
  }
  FltReleasePushLockEx(lVar5,0);
LAB_140020f1b:
  if ((int)uVar8 < 0) {
    param_2[6] = uVar8;
    param_2[8] = 0;
    param_2[9] = 0;
  }
  return uVar8;
}



===== LuafvPreAcquireForSectionSynchronization @ 140020f50 =====

ulonglong LuafvPreAcquireForSectionSynchronization
                    (longlong param_1,longlong param_2,longlong *param_3)

{
  undefined4 uVar1;
  short *psVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  undefined8 local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  uVar8 = 0;
  lVar7 = *(longlong *)(param_2 + 0x20);
  local_res10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  if (((lVar7 == 0) || (psVar2 = *(short **)(lVar7 + 0x18), psVar2 == (short *)0x0)) ||
     (*psVar2 != 0x7666)) {
    return 1;
  }
  if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x18) == 1) {
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x1c) & 0x44) == 0) {
      if (**(longlong **)(lVar7 + 0x28) == 0) {
        lVar7 = *(longlong *)(psVar2 + 0x60);
        iVar3 = 0;
        FltAcquirePushLockExclusiveEx(lVar7 + 0x40,0);
        if (*(longlong *)(lVar7 + 0x70) == 0) {
          local_58 = CONCAT44(local_58._4_4_,0x30);
          local_38 = 0;
          uStack_30 = 0;
          uStack_50 = 0;
          uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
          local_48 = 0;
          local_res10 = 1;
          iVar3 = ZwCreateSection(lVar7 + 0x70,5,&local_58,&local_res10,2,0x8000000,
                                  *(undefined8 *)(psVar2 + 0x68));
        }
        FltReleasePushLockEx(lVar7 + 0x40,0);
        if (iVar3 < 0) {
          *(undefined4 *)(param_1 + 0x18) = 0xc000009a;
          *(undefined8 *)(param_1 + 0x20) = 0;
          return 4;
        }
      }
      uVar4 = Feature_3278626104__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
        if (((*(longlong *)(param_2 + 0x20) != 0) &&
            (psVar2 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x18), psVar2 != (short *)0x0)) &&
           (*psVar2 == 0x7666)) {
          if (*(longlong *)(psVar2 + 0x78) == 0) {
            uVar1 = *(undefined4 *)(psVar2 + 0x7c);
            *(undefined8 *)(param_1 + 0x20) = 0;
            uVar8 = 4;
            *(undefined4 *)(param_1 + 0x18) = uVar1;
            goto LAB_140021186;
          }
          *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = *(longlong *)(psVar2 + 0x78);
          FltSetCallbackDataDirty(param_1);
        }
        uVar8 = 1;
      }
      else {
        lVar7 = *(longlong *)(psVar2 + 0x60);
        FltAcquirePushLockSharedEx(lVar7 + 0x40,0);
        if (((*(longlong *)(param_2 + 0x20) != 0) &&
            (psVar2 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x18), psVar2 != (short *)0x0)) &&
           (*psVar2 == 0x7666)) {
          if (*(longlong *)(psVar2 + 0x78) == 0) {
            uVar1 = *(undefined4 *)(psVar2 + 0x7c);
            *(undefined8 *)(param_1 + 0x20) = 0;
            uVar8 = 4;
            *(undefined4 *)(param_1 + 0x18) = uVar1;
            FltReleasePushLockEx(lVar7 + 0x40);
            goto LAB_140021186;
          }
          *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = *(longlong *)(psVar2 + 0x78);
          FltSetCallbackDataDirty(param_1);
        }
        FltSetCallbackDataDirty(param_1);
        *param_3 = lVar7;
      }
LAB_140021186:
      return (ulonglong)uVar8;
    }
    uVar4 = Feature_3278626104__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      uVar4 = LuafvPreWrite(param_1,param_2,param_3);
      return uVar4;
    }
    uVar5 = LuafvPreWrite(param_1,param_2,param_3);
    if ((int)uVar5 == 4) {
      return 4;
    }
  }
  else {
    uVar4 = Feature_3278626104__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      lVar7 = *(longlong *)(psVar2 + 0x78);
      if (lVar7 == 0) {
        lVar7 = *(longlong *)(psVar2 + 0x6c);
      }
      *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = lVar7;
      FltSetCallbackDataDirty(param_1);
      return 1;
    }
  }
  lVar7 = *(longlong *)(psVar2 + 0x60);
  FltAcquirePushLockSharedEx(lVar7 + 0x40,0);
  lVar6 = *(longlong *)(psVar2 + 0x78);
  if (lVar6 == 0) {
    lVar6 = *(longlong *)(psVar2 + 0x6c);
  }
  *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = lVar6;
  FltSetCallbackDataDirty(param_1);
  *param_3 = lVar7;
  return 0;
}



===== LuafvPreDirectoryControl @ 140021280 =====

undefined1 LuafvPreDirectoryControl(uint *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  short *psVar4;
  undefined1 uVar5;
  longlong *local_res10;
  
  lVar3 = *(longlong *)(param_2 + 0x20);
  local_res10 = (longlong *)0x0;
  if (lVar3 == 0) {
LAB_1400213de:
    psVar4 = (short *)0x0;
    local_res10 = (longlong *)0x0;
  }
  else {
    psVar4 = *(short **)(lVar3 + 0x18);
    if ((psVar4 == (short *)0x0) || (*psVar4 != 0x7666)) {
      if ((*(longlong *)(param_2 + 0x18) == 0) ||
         (iVar1 = FltGetStreamHandleContext(*(longlong *)(param_2 + 0x18),lVar3,&local_res10),
         iVar1 < 0)) goto LAB_1400213de;
      psVar4 = (short *)0x0;
    }
    else {
      local_res10 = *(longlong **)(psVar4 + 0x80);
    }
    if (((local_res10 != (longlong *)0x0) && (*(char *)(*(longlong *)(param_1 + 4) + 5) == '\x01'))
       && ((*(byte *)((longlong)local_res10 + 0x14) & 10) != 0)) {
      lVar3 = IoGetTopLevelIrp();
      if (lVar3 == 0) {
        switch(*(int *)(*(longlong *)(param_1 + 4) + 0x28)) {
        case 1:
        case 2:
        case 3:
        case 0xc:
        case 0x25:
        case 0x26:
        case 0x3c:
        case 0x3f:
        case 0x4e:
        case 0x4f:
        case 0x50:
        case 0x51:
          if ((*(byte *)(*local_res10 + 0x28) & 1) == 0) {
            uVar5 = *(int *)(*(longlong *)(param_1 + 4) + 0x28) == 0xc;
          }
          else {
            uVar2 = LuafvQueryStoreDirectory(*(undefined8 *)(param_2 + 0x18),param_1,*local_res10);
            if (((int)uVar2 < 0) &&
               ((uVar2 == 0xc0000033 ||
                (LuafvLogFileError((longlong)param_1,0,&LuafvQueryDirectoryFailed,uVar2),
                uVar2 == 0xc000009a)))) {
              param_1[6] = uVar2;
              param_1[8] = 0;
              param_1[9] = 0;
            }
            FltSetCallbackDataDirty(param_1);
            uVar5 = 4;
          }
          goto LAB_1400213ee;
        }
      }
    }
  }
  uVar5 = 1;
LAB_1400213ee:
  if ((psVar4 == (short *)0x0) && (local_res10 != (longlong *)0x0)) {
    FltReleaseContext();
  }
  return uVar5;
}



===== LuafvPreReleaseForSectionSynchronization @ 140021430 =====

undefined8
LuafvPreReleaseForSectionSynchronization(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  short *psVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  if (((lVar1 != 0) && (psVar2 = *(short **)(lVar1 + 0x18), psVar2 != (short *)0x0)) &&
     (*psVar2 == 0x7666)) {
    lVar3 = *(longlong *)(psVar2 + 0x78);
    if (lVar3 == 0) {
      uVar4 = Feature_3278626104__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 != 0) {
        FltReleasePushLockEx(*(longlong *)(psVar2 + 0x60) + 0x40,0);
      }
      uVar5 = LuafvPreWrite(param_1,param_2,param_3);
      return uVar5;
    }
    FsRtlChangeBackingFileObject(lVar1,lVar3,1);
    FsRtlChangeBackingFileObject(lVar1,lVar3,0,0);
    FsRtlChangeBackingFileObject(lVar1,lVar3,2);
    *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) = lVar3;
    FltSetCallbackDataDirty(param_1);
    uVar4 = Feature_3278626104__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      FltReleasePushLockEx(*(longlong *)(psVar2 + 0x60) + 0x40,0);
    }
  }
  return 1;
}



===== LuafvCopyFile$fin$0 @ 140021562 =====

void LuafvCopyFile_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x80) < 0) && (*(longlong *)(param_2 + 0xa8) != 0)) {
    *(undefined1 *)(param_2 + 0x84) = 1;
    FltSetInformationFile
              (*(undefined8 *)(param_2 + 0x198),*(longlong *)(param_2 + 0xa8),param_2 + 0x84,1,0xd);
  }
  if (*(longlong *)(param_2 + 0xb0) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0xb8) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x90) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0xa8) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0xd0) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0xd8) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0xe0) != 0) {
    LuafvFreePool(*(longlong *)(param_2 + 0xe0));
  }
  if (*(longlong *)(param_2 + 0xc0) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0xe8) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0x138) != 0) {
    LuafvFreePool(*(longlong *)(param_2 + 0x138));
  }
  if (*(longlong *)(param_2 + 0xa0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0xa0),0);
  }
  return;
}



===== TranslatePath @ 140023008 =====

int TranslatePath(ushort *param_1,longlong param_2,longlong param_3)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  longlong local_res8;
  ushort local_78 [8];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  local_28 = 0;
  uStack_20 = uStack_20 & 0xffffffff00000000;
  bVar1 = false;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = (undefined8 *)0x0;
  uStack_30 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  if (*(short *)(*(longlong *)(param_1 + 4) + -2 + (ulonglong)(*param_1 >> 1) * 2) == 0x5c) {
    *param_1 = *param_1 - 2;
  }
  local_68 = *(undefined8 *)param_1;
  uStack_60 = *(undefined8 *)(param_1 + 4);
  do {
    local_res8 = 0;
    uVar3 = LuafvSplitPathLeft((ushort *)&local_68,(short *)local_78);
    if (((char)uVar3 == '\0') || ((ushort)local_68 == 0)) {
      iVar2 = -0x3fffffff;
      goto LAB_1400231e6;
    }
    local_38 = &local_68;
    local_48 = CONCAT44(local_48._4_4_,0x30);
    uStack_40 = 0;
    uStack_30 = CONCAT44(uStack_30._4_4_,0x40);
    local_28 = 0;
    uStack_20 = 0;
    iVar2 = ZwOpenSymbolicLinkObject(&local_res8,1,&local_48);
  } while (iVar2 < 0);
  if (param_3 == 0) {
LAB_14002312b:
    do {
      iVar2 = QuerySymbolicLink(local_res8,(longlong)&local_58);
      if (iVar2 < 0) goto LAB_1400231e6;
      ZwClose(local_res8);
      local_38 = &local_58;
      iVar2 = ZwOpenSymbolicLinkObject(&local_res8,1,&local_48);
    } while (-1 < iVar2);
    local_res8 = 0;
    if (iVar2 != -0x3fffffdc) goto LAB_1400231ff;
    uVar5 = (uint)(ushort)local_58;
    if (param_3 == 0) {
      uVar5 = (uint)(ushort)local_58 + (uint)local_78[0];
    }
    *(short *)(param_2 + 2) = (short)uVar5;
    puVar4 = LuafvAllocatePool(1,uVar5,'\x01');
    *(uint **)(param_2 + 8) = puVar4;
    if (puVar4 == (uint *)0x0) goto LAB_14002310b;
    RtlCopyUnicodeString(param_2,&local_58);
    if (param_3 == 0) {
      RtlAppendUnicodeStringToString(param_2,local_78);
    }
    iVar2 = 0;
  }
  else {
    *(ushort *)(param_3 + 2) = local_78[0];
    puVar4 = LuafvAllocatePool(1,(uint)local_78[0],'\x01');
    *(uint **)(param_3 + 8) = puVar4;
    if (puVar4 != (uint *)0x0) {
      bVar1 = true;
      RtlCopyUnicodeString(param_3,local_78);
      goto LAB_14002312b;
    }
LAB_14002310b:
    iVar2 = -0x3fffff66;
  }
LAB_1400231e6:
  if (local_res8 != 0) {
    ZwClose();
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_1400231ff:
  if (bVar1) {
    LuafvFreePool(*(longlong *)(param_3 + 8));
  }
  return iVar2;
}



===== GetStaticEntryRoots @ 140023234 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint GetStaticEntryRoots(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  longlong lVar5;
  uint uVar6;
  undefined *puVar7;
  uint uVar8;
  longlong local_res8;
  longlong local_res10;
  ushort local_98 [4];
  uint *puStack_90;
  undefined8 local_88;
  uint *puStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ushort local_68 [8];
  undefined8 local_58;
  undefined8 local_50;
  undefined *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_58 = 0x30;
  local_40 = 0x240;
  local_res8 = 0;
  local_res10 = 0;
  local_50 = 0;
  local_48 = &SystemRootLinkName;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  puStack_90 = (uint *)0x0;
  local_88 = 0;
  puStack_80 = (uint *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  uVar3 = ZwOpenSymbolicLinkObject(&local_res8,1,&local_58);
  if ((int)uVar3 < 0) {
    local_res8 = 0;
  }
  else {
    uVar3 = QuerySymbolicLink(local_res8,(longlong)local_68);
    if (-1 < (int)uVar3) {
      ZwClose(local_res8);
      local_res8 = 0;
      uVar3 = TranslatePath(local_68,(longlong)&local_78,(longlong)local_98);
      if (-1 < (int)uVar3) {
        _StaticEntryRoots = (int)local_78;
        uRam000000014000c2c4 = local_78._4_4_;
        DAT_14000c2c8._0_4_ = (undefined4)uStack_70;
        DAT_14000c2c8._4_4_ = uStack_70._4_4_;
        _DAT_14000c108 = (int)local_78;
        uRam000000014000c10c = local_78._4_4_;
        DAT_14000c110._0_4_ = (undefined4)uStack_70;
        DAT_14000c110._4_4_ = uStack_70._4_4_;
        uVar4 = (ushort)((int)local_78 + 4U);
        if (uVar4 < (ushort)local_78) {
          uVar3 = 0xc0000095;
        }
        else {
          puStack_80 = LuafvAllocatePool(1,(int)local_78 + 4U & 0xffff,'\x02');
          if (puStack_80 == (uint *)0x0) {
LAB_140023344:
            uVar3 = 0xc000009a;
          }
          else {
            local_88 = (ulonglong)CONCAT42(local_88._4_4_,uVar4) << 0x10;
            RtlCopyUnicodeString(&local_88,&DAT_14000c108);
            uVar3 = RtlAppendUnicodeToString(&local_88,L"\\");
            if (-1 < (int)uVar3) {
              _DAT_14000c2d2 = local_98[0] + (short)local_78;
              _DAT_14000c118 = local_88;
              DAT_14000c120 = puStack_80;
              local_88 = 0;
              puStack_80 = (uint *)0x0;
              DAT_14000c2d8 = LuafvAllocatePool(1,(uint)_DAT_14000c2d2,'\x01');
              if (DAT_14000c2d8 == (uint *)0x0) {
                uVar3 = 0xc000009a;
                LuafvFreePool((longlong)puStack_90);
              }
              else {
                RtlCopyUnicodeString(&DAT_14000c2d0,&local_78);
                RtlAppendUnicodeStringToString(&DAT_14000c2d0,local_98);
                LuafvFreePool((longlong)puStack_90);
                for (uVar6 = 0; uVar6 < 2; uVar6 = uVar6 + 1) {
                  lVar5 = (ulonglong)uVar6 * 0x10;
                  uVar3 = LuafvOpenKey(0,&RegistryKeyNames + lVar5,&local_res10);
                  if ((int)uVar3 < 0) goto LAB_14002354a;
                  puVar7 = (&RegistryStaticRoots)[(ulonglong)uVar6 * 2];
                  for (uVar8 = 0; uVar8 < *(uint *)(&DAT_140026140 + lVar5); uVar8 = uVar8 + 1) {
                    uVar3 = QueryStringValue(local_res10,puVar7,'\0',(short *)local_68);
                    if ((int)uVar3 < 0) goto LAB_14002354a;
                    local_98[1] = local_68[0] + _GlobalRoot;
                    puStack_90 = LuafvAllocatePool(1,(uint)(ushort)(local_68[0] + _GlobalRoot),
                                                   '\x01');
                    if (puStack_90 == (uint *)0x0) goto LAB_140023344;
                    RtlCopyUnicodeString(local_98,&GlobalRoot);
                    RtlAppendUnicodeStringToString(local_98,local_68);
                    uVar3 = TranslatePath(local_98,(longlong)&local_78,0);
                    LuafvFreePool((longlong)puStack_90);
                    if ((int)uVar3 < 0) goto LAB_14002354a;
                    iVar2 = *(int *)(puVar7 + 0x10);
                    puVar7 = puVar7 + 0x18;
                    lVar1 = (longlong)iVar2 * 0x10;
                    *(int *)(&StaticEntryRoots + lVar1) = (int)local_78;
                    *(undefined4 *)(lVar1 + 0x14000c2c4) = local_78._4_4_;
                    *(undefined4 *)(&DAT_14000c2c8 + (longlong)iVar2 * 2) = (undefined4)uStack_70;
                    *(undefined4 *)((longlong)&DAT_14000c2c8 + lVar1 + 4) = uStack_70._4_4_;
                  }
                  ZwClose();
                  local_res10 = 0;
                }
                uVar3 = 0;
              }
            }
          }
        }
      }
    }
LAB_14002354a:
    if (local_res8 != 0) {
      ZwClose();
    }
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  if (puStack_80 != (uint *)0x0) {
    LuafvFreePool((longlong)puStack_80);
  }
  return uVar3;
}



===== QueryStringValue @ 1400235a8 =====

uint QueryStringValue(undefined8 param_1,undefined8 param_2,char param_3,short *param_4)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  uint local_18 [4];
  
  local_18[0] = 0;
  while ((uVar3 = ZwQueryValueKey(param_1,param_2,2,QueryBuffer,QueryBufferLength,local_18),
         lVar1 = QueryBuffer, uVar3 == 0x80000005 || (uVar3 == 0xc0000023))) {
    uVar3 = GrowQueryBuffer(local_18[0]);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  if (uVar3 != 0) {
    return uVar3;
  }
  if (param_3 == '\0') {
    if (1 < *(int *)(QueryBuffer + 4) - 1U) {
      return 0xc0000024;
    }
    sVar2 = *(short *)(QueryBuffer + 8) + -2;
  }
  else {
    if (*(int *)(QueryBuffer + 4) != 7) {
      return 0xc0000024;
    }
    sVar2 = *(short *)(QueryBuffer + 8);
  }
  *param_4 = sVar2;
  param_4[1] = sVar2;
  *(longlong *)(param_4 + 4) = lVar1 + 0xc;
  return 0;
}



===== GrowQueryBuffer @ 140023690 =====

uint GrowQueryBuffer(uint param_1)

{
  uint uVar1;
  
  if (QueryBuffer != (uint *)0x0) {
    LuafvFreePool((longlong)QueryBuffer);
  }
  if (param_1 + 0x200 < param_1) {
    QueryBufferLength = 0xffffffff;
    uVar1 = 0xc0000095;
    QueryBuffer = (uint *)0x0;
  }
  else {
    QueryBufferLength = param_1 + 0x200 & 0xfffffe00;
    QueryBuffer = LuafvAllocatePool(1,QueryBufferLength,'\x01');
    uVar1 = ~-(uint)(QueryBuffer != (uint *)0x0) & 0xc000009a;
  }
  return uVar1;
}



===== LuafvInitializeFileTable @ 140023704 =====

void LuafvInitializeFileTable(void)

{
  int _Val;
  
  _Val = 0;
  LuafvInitializeTable((undefined8 *)&DAT_14000c230,0);
  memset(&DAT_14000c128,_Val,0x108);
  ExInitializePushLock(&DAT_14000c128);
  DAT_14000c170 = DAT_14000c170 & 0xf8;
  DAT_14000c146 = DAT_14000c146 | 3;
  DAT_14000c144 = DAT_14000c144 | 1;
  DAT_14000c1a0 = DAT_14000c1a0 & 0xf9 | 1;
  DAT_14000c13c = 1;
  DAT_14000c1d0 = DAT_14000c1d0 & 0xfa | 2;
  DAT_14000c140 = 0x10;
  DAT_14000c150 = &DAT_14000c230;
  LuafvInitializeTable(&DAT_14000c248,1);
  FltInitializePushLock(&DAT_14000c260);
  FltInitializePushLock(&DAT_14000c278);
  FltInitializePushLock(&DAT_14000c280);
  return;
}



===== LuafvReadSettings @ 1400237e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint LuafvReadSettings(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_78 [32];
  uint **local_58;
  uint local_48 [2];
  uint local_40;
  longlong local_38;
  longlong local_30;
  uint *local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0;
  local_30 = 0;
  local_38 = 0;
  uVar1 = LuafvOpenKey(0,param_1,&local_30);
  local_40 = uVar1;
  if ((int)uVar1 < 0) {
    local_30 = 0;
    goto LAB_140023a6f;
  }
  uVar1 = LuafvOpenKey(local_30,&LuafvSettingsKeyName,&local_38);
  local_40 = uVar1;
  ZwClose(local_30);
  local_30 = 0;
  if ((int)uVar1 < 0) {
    local_38 = 0;
    goto LAB_140023a6f;
  }
  uVar2 = LuafvReadDwordValue(local_38,&LuafvAccessDeniedMaskValueName,local_48);
  local_40 = (uint)uVar2;
  if ((int)local_40 < 0) {
    _DAT_14000c0f0 = 0xc0156;
LAB_1400238af:
    uVar2 = LuafvReadDwordValue(local_38,&LuafvEnableDelayedVirtualizationValueName,local_48);
    local_40 = (uint)uVar2;
    DAT_14000c0fc = (int)local_40 < 0 || local_48[0] != 0;
    uVar2 = LuafvReadDwordValue(local_38,&LuafvEnableExtensionBasedExclusionValueName,local_48);
    local_40 = (uint)uVar2;
    DAT_14000c0fd = (int)local_40 < 0 || local_48[0] != 0;
    uVar2 = LuafvReadDwordValue(local_38,&LuafvDisableStaticInclusionValueName,local_48);
    local_40 = (uint)uVar2;
    if (-1 < (int)local_40) {
      DAT_14000c0fe = local_48[0] != 0;
    }
    uVar2 = LuafvReadDwordValue(local_38,&LuafvPoolAllocationLimitValueName,local_48);
    local_40 = (uint)uVar2;
    if ((int)local_40 < 0) {
      DAT_14000c2a8 = 0x400000;
    }
    else {
      if ((int)local_48[0] < 0x40000) goto LAB_140023a66;
      DAT_14000c2a8 = local_48[0];
    }
    uVar2 = LuafvReadDwordValue(local_38,&LuafvCallControlValueName,local_48);
    local_40 = (uint)uVar2;
    if (-1 < (int)local_40) {
      if ((local_48[0] & 0xfffffff8) != 0) goto LAB_140023a66;
      DAT_14000c0f4 = local_48[0];
    }
    uVar2 = LuafvReadDwordValue(local_38,&LuafvLogControlValueName,local_48);
    local_40 = (uint)uVar2;
    if ((int)local_40 < 0) {
      DAT_14000c0f8 = 7;
    }
    else {
      DAT_14000c0f8 = local_48[0];
    }
    uVar1 = LuafvReadFileTable(local_38);
    local_40 = uVar1;
    if ((int)uVar1 < 0) {
      local_28 = local_48;
      uStack_20 = 4;
      local_58 = &local_28;
      local_48[0] = uVar1;
      EtwWrite(DAT_14000c100,&LuafvReadFileListFailed,0,1);
    }
  }
  else {
    if ((local_48[0] & 0xfff2fea9) == 0) {
      _DAT_14000c0f0 = local_48[0];
      goto LAB_1400238af;
    }
LAB_140023a66:
    uVar1 = 0xc000000d;
    local_40 = 0xc000000d;
  }
LAB_140023a6f:
  if (local_38 != 0) {
    ZwClose();
  }
  if (local_30 != 0) {
    ZwClose();
  }
  return uVar1;
}



===== CheckExtensionsList @ 140023ab8 =====

undefined8 CheckExtensionsList(ushort *param_1,int *param_2,int *param_3,int *param_4)

{
  short *psVar1;
  short *psVar2;
  undefined8 uVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  uint uVar9;
  
  psVar8 = *(short **)(param_1 + 4);
  uVar9 = (uint)(*param_1 >> 1);
  psVar1 = psVar8 + uVar9;
  if (uVar9 == 0) {
LAB_140023af6:
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 0;
LAB_140023aff:
    uVar3 = 0;
  }
  else {
    if (uVar9 == 1) {
      if (*psVar8 == 0) goto LAB_140023af6;
LAB_140023b33:
      if ((((2 < uVar9) && (*psVar8 != 0)) && (psVar8[uVar9 - 2] == 0)) && (psVar8[uVar9 - 1] == 0))
      {
        iVar5 = 0;
        iVar6 = 0;
        iVar7 = 0;
        psVar4 = psVar8;
        do {
          do {
            psVar2 = psVar4;
            psVar4 = psVar2 + 1;
          } while (*psVar4 != 0);
          uVar9 = (uint)((longlong)psVar4 - (longlong)psVar8 >> 1);
          if (uVar9 < 5) {
            iVar5 = iVar5 + 1;
          }
          else {
            iVar6 = iVar6 + 1;
            iVar7 = iVar7 + uVar9;
          }
          psVar8 = psVar2 + 2;
          psVar4 = psVar8;
        } while (*psVar8 != 0);
        if (psVar2 + 3 == psVar1) {
          *param_2 = iVar5;
          *param_3 = iVar6;
          *param_4 = iVar7;
          goto LAB_140023aff;
        }
      }
    }
    else {
      if (uVar9 != 2) goto LAB_140023b33;
      if ((*psVar8 == 0) && (psVar8[1] == 0)) goto LAB_140023af6;
    }
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== LuafvSkipDriverLoad @ 140023bac =====

bool LuafvSkipDriverLoad(void)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  int local_res8 [2];
  longlong local_res10 [3];
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  bVar3 = false;
  iVar1 = LuafvOpenKey(0,&LuafvSystemPolicyKeyPath,local_res10);
  if (-1 < iVar1) {
    uVar2 = LuafvReadDwordValue(local_res10[0],&LuafvEnableLUAValueName,local_res8);
    if (((int)uVar2 < 0) || (local_res8[0] != 0)) {
      uVar2 = LuafvReadDwordValue(local_res10[0],&LuafvEnableVirtValueName,local_res8);
      if (-1 < (int)uVar2) {
        bVar3 = local_res8[0] == 0;
      }
    }
    else {
      bVar3 = true;
    }
  }
  if (local_res10[0] != 0) {
    ZwClose();
  }
  return bVar3;
}



===== LuafvInitializeUserList @ 140023c50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LuafvInitializeUserList(void)

{
  FltInitializePushLock(&UserListLock);
  _DAT_14000b888 = &UserList;
  UserList = &UserList;
  SeRegisterLogonSessionTerminatedRoutineEx(UserLogoffCallback,0);
  return;
}



===== LuafvInitializeScavenger @ 140023ca0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 LuafvInitializeScavenger(void)

{
  KeInitializeSpinLock(&ScavengerSpinLock);
  _DAT_14000b828 = 0;
  _ScavengerWorkItem = 0;
  _DAT_14000b820 = ScavengerThreadRoutine;
  ScavengerInitialized = 1;
  return 0;
}



===== entry @ 140023cf0 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140023d24 =====

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



===== AllocateTraversalNode @ 140023d58 =====

uint * AllocateTraversalNode(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  code *pcVar2;
  uint *_Dst;
  uint *puVar3;
  longlong *plVar4;
  
  uVar1 = *param_2;
  _Dst = LuafvAllocatePool(1,uVar1 + 0x48,'\t');
  if (_Dst != (uint *)0x0) {
    memset(_Dst,0,(ulonglong)(uVar1 + 0x48));
    *(uint **)(_Dst + 2) = _Dst;
    *(uint **)_Dst = _Dst;
    *(longlong *)(_Dst + 8) = param_1;
    *(ushort *)((longlong)_Dst + 0x32) = *param_2;
    *(uint **)(_Dst + 0xe) = _Dst + 0x12;
    RtlCopyUnicodeString(_Dst + 0xc,param_2);
    plVar4 = *(longlong **)(param_1 + 8);
    puVar3 = _Dst + 4;
    if (*plVar4 != param_1) {
      plVar4 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      puVar3 = (uint *)(*pcVar2)();
    }
    *(longlong *)puVar3 = param_1;
    *(longlong **)(puVar3 + 2) = plVar4;
    *plVar4 = (longlong)puVar3;
    *(uint **)(param_1 + 8) = puVar3;
  }
  return _Dst;
}



===== EnumerateKey @ 140023e10 =====

uint EnumerateKey(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint local_res8 [2];
  ushort local_18 [4];
  longlong lStack_10;
  
  local_res8[0] = 0;
  iVar4 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  lStack_10 = 0;
  while( true ) {
    while ((uVar1 = ZwEnumerateKey(*(undefined8 *)(param_1 + 0x28),iVar4,0,QueryBuffer,
                                   QueryBufferLength,local_res8), uVar1 == 0x80000005 ||
           (uVar1 == 0xc0000023))) {
      uVar1 = GrowQueryBuffer(local_res8[0]);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
    }
    if ((int)uVar1 < 0) {
      uVar3 = 0;
      if (uVar1 != 0x8000001a) {
        uVar3 = uVar1;
      }
      return uVar3;
    }
    local_18[1] = *(undefined2 *)(QueryBuffer + 0xc);
    local_18[0] = *(undefined2 *)(QueryBuffer + 0xc);
    lStack_10 = QueryBuffer + 0x10;
    puVar2 = AllocateTraversalNode(param_1,local_18);
    if (puVar2 == (uint *)0x0) break;
    iVar4 = iVar4 + 1;
  }
  return 0xc000009a;
}



===== ProcessKey @ 140023ee4 =====

ulonglong ProcessKey(longlong param_1)

{
  ushort *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  char local_res8 [8];
  byte local_res10 [8];
  longlong local_48 [4];
  undefined8 local_28;
  
  local_48[0] = 0;
  local_48[1] = 0;
  local_28 = 0;
  local_res8[0] = '\0';
  local_res10[0] = 0;
  uVar4 = LuafvOpenKey(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x28),param_1 + 0x30,
                       param_1 + 0x28);
  if ((int)uVar4 < 0) {
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  else {
    uVar3 = EnumerateKey(param_1);
    uVar4 = CONCAT44(extraout_var,uVar3);
    if (-1 < (int)uVar3) {
      uVar4 = LuafvFindTableNode(*(undefined **)(*(longlong *)(param_1 + 0x20) + 0x40),
                                 (ulonglong *)(param_1 + 0x30),2,local_48);
      lVar2 = local_48[0];
      if (-1 < (int)uVar4) {
        *(longlong *)(param_1 + 0x40) = local_48[0];
        uVar4 = uVar4 & 0xffffffff;
        if (local_28._1_1_ != '\0') {
          uVar3 = QueryExcludeValue(param_1,local_res8,local_res10);
          uVar4 = (ulonglong)uVar3;
          if (((int)uVar3 < 0) || (local_res8[0] == '\0')) {
            uVar4 = 0;
          }
          else {
            *(ushort *)(lVar2 + 0x1e) = *(ushort *)(lVar2 + 0x1e) | 2;
            *(undefined1 *)(lVar2 + 0x1c) = 0;
            *(byte *)(lVar2 + 0x1c) = (local_res10[0] & 1) * '\x02';
            if ((local_res10[0] == 0) && (*(longlong *)(lVar2 + 0x20) != 0)) {
              puVar1 = (ushort *)(*(longlong *)(lVar2 + 0x20) + 0x1e);
              *puVar1 = *puVar1 | 0x100;
            }
          }
        }
        LuafvDereferenceTableNodeEx(lVar2,'\0','\0');
      }
    }
  }
  return uVar4;
}



===== QueryExcludeValue @ 140023fec =====

uint QueryExcludeValue(longlong param_1,undefined1 *param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  do {
    uVar2 = ZwQueryValueKey(*(undefined8 *)(param_1 + 0x28),&ExcludeValueName,2,QueryBuffer,
                            QueryBufferLength,local_res8);
    if ((uVar2 != 0x80000005) && (uVar2 != 0xc0000023)) break;
    uVar2 = GrowQueryBuffer(local_res8[0]);
  } while (-1 < (int)uVar2);
  if (uVar2 == 0) {
    if ((*(int *)(QueryBuffer + 4) == 4) && (*(int *)(QueryBuffer + 8) == 4)) {
      iVar1 = *(int *)(QueryBuffer + 0xc);
      *param_2 = 1;
      *(bool *)param_3 = iVar1 != 0;
    }
    else {
      uVar2 = 0xc0000024;
    }
  }
  else if (uVar2 == 0xc0000034) {
    *param_2 = 0;
    uVar2 = 0;
  }
  return uVar2;
}



===== QuerySymbolicLink @ 1400240b4 =====

void QuerySymbolicLink(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  uint local_res10 [6];
  
  local_res10[0] = 0;
  while( true ) {
    *(undefined2 *)(param_2 + 2) = (undefined2)QueryBufferLength;
    *(undefined8 *)(param_2 + 8) = QueryBuffer;
    iVar1 = ZwQuerySymbolicLinkObject(param_1,param_2,local_res10);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) break;
    uVar2 = GrowQueryBuffer(local_res10[0]);
    if ((int)uVar2 < 0) {
      return;
    }
  }
  return;
}



===== RemoveExtensionsList @ 140024124 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RemoveExtensionsList(longlong param_1)

{
  short *psVar1;
  int iVar2;
  short *psVar3;
  undefined8 uVar4;
  uint uVar5;
  void *_Dst;
  void *_Src;
  short *psVar6;
  size_t _Size;
  char local_res8 [8];
  uint local_res10 [2];
  
  psVar3 = *(short **)(param_1 + 8);
  local_res8[0] = '\0';
  local_res10[0] = 0;
  psVar6 = psVar3;
  do {
    do {
      psVar1 = psVar6;
      psVar6 = psVar1 + 1;
    } while (*psVar6 != 0);
    uVar4 = IsExcludedExtension(psVar3,(uint)((longlong)psVar6 - (longlong)psVar3 >> 1),local_res8,
                                (int *)local_res10);
    if ((char)uVar4 != '\0') {
      if (local_res8[0] == '\0') {
        iVar2 = DAT_14000c29c + -1;
        uVar5 = (DAT_14000c29c - local_res10[0]) - 1;
        DAT_14000c29c = iVar2;
        if (uVar5 != 0) {
          _Src = (void *)((ulonglong)(local_res10[0] + 1) * 0x10 + _DAT_14000c290);
          _Size = (ulonglong)uVar5 << 4;
          _Dst = (void *)((ulonglong)local_res10[0] * 0x10 + _DAT_14000c290);
          goto LAB_1400241f0;
        }
      }
      else {
        iVar2 = DAT_14000c298 + -1;
        uVar5 = (DAT_14000c298 - local_res10[0]) - 1;
        DAT_14000c298 = iVar2;
        if (uVar5 != 0) {
          _Size = (ulonglong)uVar5 << 3;
          _Src = (void *)(DAT_14000c288 + (ulonglong)(local_res10[0] + 1) * 8);
          _Dst = (void *)(DAT_14000c288 + (ulonglong)local_res10[0] * 8);
LAB_1400241f0:
          memmove(_Dst,_Src,_Size);
        }
      }
    }
    psVar3 = psVar1 + 2;
    psVar6 = psVar3;
    if (*psVar3 == 0) {
      return;
    }
  } while( true );
}



===== wil_InitializeFeatureStaging @ 140024214 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140024304 =====

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



===== LuafvInitializeSecurity @ 1400243ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong LuafvInitializeSecurity(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar1 = RtlCreateSecurityDescriptor(&LuafvInteractiveDescriptor,1);
  uVar5 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x100));
    puVar3 = LuafvAllocatePool(1,iVar2 + 0x14,'\x05');
    if (puVar3 == (uint *)0x0) {
      uVar5 = 0xc000009a;
    }
    else {
      uVar1 = RtlCreateAcl(puVar3,iVar2 + 0x14,2);
      uVar5 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar1 = RtlAddAccessAllowedAce
                          (puVar3,2,1,*(undefined8 *)(*(longlong *)SeExports_exref + 0x100));
        uVar5 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar1 = RtlSetDaclSecurityDescriptor(&LuafvInteractiveDescriptor,1,puVar3,0);
          uVar5 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar4 = LuafvCreateTrustedInstallerSid(&DAT_14000c2b8);
            uVar5 = uVar4 & 0xffffffff;
            if (-1 < (int)uVar4) {
              return 0;
            }
          }
        }
      }
      LuafvFreePool((longlong)puVar3);
      _LuafvInteractiveDescriptor = 0;
      uRam000000014000b8a8 = 0;
      DAT_14000b8c0 = 0;
      _DAT_14000b8b0 = 0;
      uRam000000014000b8b8 = 0;
    }
  }
  return uVar5;
}



===== LuafvReadFileTable @ 140024514 =====

uint LuafvReadFileTable(undefined8 param_1)

{
  undefined8 ****ppppuVar1;
  undefined8 ***pppuVar2;
  undefined8 ***pppuVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 ****ppppuVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  uint uVar16;
  undefined8 ****ppppuVar17;
  longlong *plVar18;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  undefined8 ****local_68;
  undefined8 ****local_60;
  longlong local_40 [3];
  undefined *local_28;
  
  plVar18 = &DAT_14000c2c8;
  puVar7 = &DAT_14000c2c8;
  lVar12 = 7;
  do {
    lVar11 = lVar12;
    *puVar7 = 0;
    puVar7 = puVar7 + 2;
    lVar12 = lVar11 + -1;
  } while (lVar12 != 0);
  memset(&local_68,0,(ulonglong)((int)lVar11 + 0x47));
  local_60 = &local_68;
  local_68 = &local_68;
  local_28 = &DAT_14000c128;
  uVar5 = GrowQueryBuffer(0x200);
  if (-1 < (int)uVar5) {
    uVar8 = BuildExcludedExtensionsList(param_1);
    uVar5 = (uint)uVar8;
    if ((-1 < (int)uVar5) && (uVar5 = GetStaticEntryRoots(), -1 < (int)uVar5)) {
      uVar16 = 0;
      puVar13 = (ulonglong *)&StaticEntries;
      while( true ) {
        puVar15 = auStack_88;
        if (0xfa < uVar16) break;
        if ((DAT_14000c0fe == '\0') || (*(char *)((longlong)puVar13 + 0x14) != '\0')) {
          uVar9 = CreateStaticEntry(puVar13);
          uVar5 = (uint)uVar9;
          if ((int)uVar5 < 0) goto LAB_1400246ac;
        }
        uVar16 = uVar16 + 1;
        puVar13 = puVar13 + 3;
      }
      iVar6 = LuafvOpenKey(param_1,&LuafvFileListKeyName,local_40);
      if (iVar6 < 0) {
        local_40[0] = 0;
        uVar5 = 0;
        goto LAB_14002474c;
      }
      uVar5 = EnumerateKey((longlong)&local_68);
      if (-1 < (int)uVar5) {
        puVar15 = auStack_88;
        if ((undefined8 *****)local_68 != &local_68) {
          ppppuVar17 = local_68 + -2;
          do {
            puVar14 = auStack_88;
            uVar9 = ProcessKey((longlong)ppppuVar17);
            uVar5 = (uint)uVar9;
            if ((int)uVar5 < 0) goto LAB_1400246ac;
            ppppuVar10 = (undefined8 ****)*ppppuVar17;
            if (ppppuVar10 == ppppuVar17) {
              do {
                ZwClose(ppppuVar17[5]);
                if (ppppuVar17[4] == (undefined8 ***)0x0) goto LAB_140024732;
                ppppuVar10 = ppppuVar17 + 2;
                pppuVar2 = *ppppuVar10;
                if (((undefined8 ****)pppuVar2[1] != ppppuVar10) ||
                   (pppuVar3 = ppppuVar17[3], (undefined8 ****)*pppuVar3 != ppppuVar10))
                goto LAB_14002472b;
                *pppuVar3 = pppuVar2;
                pppuVar2[1] = pppuVar3;
                ppppuVar1 = (undefined8 ****)ppppuVar17[4];
                LuafvFreePool((longlong)ppppuVar17);
                ppppuVar10 = (undefined8 ****)*ppppuVar1;
                ppppuVar17 = ppppuVar1;
              } while (ppppuVar10 == ppppuVar1);
            }
            ppppuVar17 = ppppuVar10 + -2;
            puVar15 = auStack_88;
          } while (ppppuVar17 != (undefined8 ****)0x0);
        }
        goto LAB_140024737;
      }
    }
  }
LAB_1400246ac:
  puVar15 = auStack_88;
  if ((undefined8 *****)local_68 != &local_68) {
    ppppuVar17 = local_68 + -2;
    do {
      if ((undefined8 ****)*ppppuVar17 == ppppuVar17) goto LAB_1400246d0;
      ppppuVar17 = (undefined8 ****)(*ppppuVar17 + -2);
      puVar15 = auStack_88;
    } while (ppppuVar17 != (undefined8 ****)0x0);
  }
  goto LAB_140024737;
LAB_14002472b:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar14 = auStack_80;
LAB_140024732:
  ppppuVar17[5] = (undefined8 ***)0x0;
  puVar15 = puVar14;
  goto LAB_140024737;
  while( true ) {
    ppppuVar10 = ppppuVar17 + 2;
    pppuVar2 = *ppppuVar10;
    if (((undefined8 ****)pppuVar2[1] != ppppuVar10) ||
       (pppuVar3 = ppppuVar17[3], (undefined8 ****)*pppuVar3 != ppppuVar10)) goto LAB_14002472b;
    *pppuVar3 = pppuVar2;
    pppuVar2[1] = pppuVar3;
    ppppuVar10 = (undefined8 ****)ppppuVar17[4];
    LuafvFreePool((longlong)ppppuVar17);
    if ((undefined8 ****)*ppppuVar10 != ppppuVar10) {
      ppppuVar10 = (undefined8 ****)(*ppppuVar10 + -2);
    }
    puVar15 = auStack_88;
    ppppuVar17 = ppppuVar10;
    if (ppppuVar10 == (undefined8 ****)0x0) break;
LAB_1400246d0:
    puVar14 = auStack_88;
    if (ppppuVar17[5] != (undefined8 ***)0x0) {
      ZwClose();
    }
    if (ppppuVar17[4] == (undefined8 ***)0x0) goto LAB_140024732;
  }
LAB_140024737:
  if (local_40[0] != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x140024747;
    ZwClose();
  }
LAB_14002474c:
  if (QueryBuffer != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x14002475d;
    LuafvFreePool(QueryBuffer);
    QueryBuffer = 0;
  }
  uVar16 = 0;
  do {
    if ((uVar16 != 0) && (lVar12 = *plVar18, lVar12 != 0)) {
      *(undefined8 *)(puVar15 + -8) = 0x140024778;
      LuafvFreePool(lVar12);
    }
    uVar16 = uVar16 + 1;
    plVar18 = plVar18 + 2;
  } while (uVar16 < 7);
  return uVar5;
}



===== CreateStaticEntry @ 1400247a8 =====

ulonglong CreateStaticEntry(ulonglong *param_1)

{
  byte bVar1;
  undefined *puVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined *local_38;
  undefined8 uStack_30;
  
  local_38 = (undefined *)0x0;
  uStack_30 = 0;
  uVar4 = LuafvFindTableNode((undefined *)0x0,
                             (ulonglong *)(&StaticEntryRoots + (longlong)(int)param_1[2] * 0x10),2,
                             &local_38);
  puVar2 = local_38;
  if (-1 < (int)uVar4) {
    if ((short)*param_1 == 0) {
      local_38[0x1c] = 0;
      bVar3 = *(byte *)((longlong)param_1 + 0x14) & 1;
      local_38[0x1c] = bVar3;
      bVar1 = *(byte *)((longlong)param_1 + 0x15);
      *(ushort *)(local_38 + 0x1e) = *(ushort *)(local_38 + 0x1e) | 2;
      bVar3 = (bVar1 & 1) << 3 | bVar3;
      local_38[0x1c] = bVar3;
      if (bVar3 != 1) {
        *(ushort *)(*(longlong *)(local_38 + 0x20) + 0x1e) =
             *(ushort *)(*(longlong *)(local_38 + 0x20) + 0x1e) | 0x100;
      }
    }
    else {
      uVar4 = LuafvFindTableNode(local_38,param_1,2,&local_38);
      LuafvDereferenceTableNodeEx((longlong)puVar2,'\0','\0');
      if ((int)uVar4 < 0) {
        return uVar4 & 0xffffffff;
      }
      local_38[0x1c] = 0;
      bVar3 = *(byte *)((longlong)param_1 + 0x14) & 1;
      local_38[0x1c] = bVar3;
      bVar1 = *(byte *)((longlong)param_1 + 0x15);
      *(ushort *)(local_38 + 0x1e) = *(ushort *)(local_38 + 0x1e) | 2;
      bVar3 = (bVar1 & 1) << 3 | bVar3;
      local_38[0x1c] = bVar3;
      if (bVar3 != 1) {
        *(ushort *)(*(longlong *)(local_38 + 0x20) + 0x1e) =
             *(ushort *)(*(longlong *)(local_38 + 0x20) + 0x1e) | 0x100;
      }
    }
    LuafvDereferenceTableNodeEx((longlong)local_38,'\0','\0');
    uVar4 = 0;
  }
  return uVar4;
}



===== BuildExcludedExtensionsList @ 1400248d4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 BuildExcludedExtensionsList(undefined8 param_1)

{
  uint *puVar1;
  bool bVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint *puVar7;
  short *psVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *_Dst;
  int iVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined8 local_res10;
  uint local_res18 [2];
  uint local_res20 [2];
  uint local_98 [2];
  undefined8 local_90;
  undefined8 uStack_88;
  uint *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  longlong lStack_68;
  ushort local_60 [16];
  
  local_70 = 0;
  lStack_68 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  local_60[5] = 0;
  local_60[6] = 0;
  local_60[7] = 0;
  uVar4 = QueryStringValue(param_1,&ExcludedExtensionsAddValueName,'\x01',(short *)&local_70);
  lVar15 = lStack_68;
  if ((int)uVar4 < 0) {
    lVar15 = 0;
  }
  uVar4 = (uint)(DefaultExcludedExtensions >> 1);
  if (uVar4 == 0) {
LAB_14002494c:
    uVar12 = 0;
    uVar11 = 0;
    uVar13 = 0;
  }
  else {
    if (uVar4 == 1) {
      if (*(short *)PTR_u_acm_140026020 != 0) goto LAB_1400249cb;
      goto LAB_14002494c;
    }
    if (uVar4 == 2) {
      if ((*(short *)PTR_u_acm_140026020 == 0) && (*(short *)(PTR_u_acm_140026020 + 2) == 0))
      goto LAB_14002494c;
LAB_140024a35:
      uVar6 = 0xc000000d;
      goto LAB_140024d29;
    }
LAB_1400249cb:
    if ((((uVar4 < 3) || (*(short *)PTR_u_acm_140026020 == 0)) ||
        (*(short *)(PTR_u_acm_140026020 + (ulonglong)(uVar4 - 2) * 2) != 0)) ||
       (*(short *)(PTR_u_acm_140026020 + (ulonglong)(uVar4 - 1) * 2) != 0)) goto LAB_140024a35;
    uVar13 = 0;
    uVar11 = 0;
    uVar12 = 0;
    psVar8 = (short *)PTR_u_acm_140026020;
    psVar10 = (short *)PTR_u_acm_140026020;
    do {
      do {
        psVar3 = psVar8;
        psVar8 = psVar3 + 1;
      } while (*psVar8 != 0);
      uVar9 = (uint)((longlong)psVar8 - (longlong)psVar10 >> 1);
      if (uVar9 < 5) {
        uVar13 = uVar13 + 1;
      }
      else {
        uVar11 = uVar11 + 1;
        uVar12 = uVar12 + uVar9;
      }
      psVar10 = psVar3 + 2;
      psVar8 = psVar10;
    } while (*psVar10 != 0);
    if (psVar3 + 3 != (short *)(PTR_u_acm_140026020 + (ulonglong)uVar4 * 2)) goto LAB_140024a35;
  }
  local_res20[0] = uVar13;
  local_98[0] = uVar11;
  lStack_68 = lVar15;
  local_res10._0_4_ = uVar12;
  if (lVar15 != 0) {
    uVar6 = CheckExtensionsList((ushort *)&local_70,(int *)local_res20,(int *)local_98,
                                (int *)&local_res10);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar13 = uVar13 + local_res20[0];
    uVar11 = uVar11 + local_98[0];
    uVar12 = uVar12 + (uint)local_res10;
  }
  puVar7 = LuafvAllocatePool(1,(uVar12 + (uVar13 + uVar11 * 2) * 4) * 2,'\x0e');
  if (puVar7 == (uint *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    puVar1 = puVar7 + (ulonglong)uVar13 * 2;
    local_90 = puVar1 + (ulonglong)uVar11 * 4;
    local_80 = puVar7;
    memset(puVar7,0,(ulonglong)uVar13 * 8);
    local_res10 = (ulonglong)local_res10._4_4_ << 0x20;
    local_res18[0] = 0;
    AddExtensionsList(&DefaultExcludedExtensions,(longlong)puVar7,(uint *)&local_res10,
                      (longlong)puVar1,local_res18,&local_90);
    if (lVar15 != 0) {
      AddExtensionsList((ushort *)&local_70,(longlong)puVar7,(uint *)&local_res10,(longlong)puVar1,
                        local_res18,&local_90);
    }
    uVar4 = uVar13;
    do {
      uVar12 = 1;
      local_res10 = CONCAT44(local_res10._4_4_,1);
      bVar2 = true;
      if (1 < uVar4) {
        do {
          uVar16 = *(ulonglong *)(puVar7 + (ulonglong)(uVar12 - 1) * 2);
          if (*(ulonglong *)(puVar7 + (ulonglong)uVar12 * 2) < uVar16) {
            bVar2 = false;
            *(ulonglong *)(puVar7 + (ulonglong)(uVar12 - 1) * 2) =
                 *(ulonglong *)(puVar7 + (ulonglong)uVar12 * 2);
            *(ulonglong *)(puVar7 + (ulonglong)uVar12 * 2) = uVar16;
          }
          uVar12 = uVar12 + 1;
          local_res10 = CONCAT44(local_res10._4_4_,uVar12);
        } while (uVar12 < uVar4);
      }
      uVar4 = uVar4 - 1;
    } while (!bVar2);
    do {
      bVar2 = true;
      if (uVar11 < 2) break;
      uVar4 = 1;
      do {
        local_res10 = (ulonglong)(uVar4 - 1) * 0x10;
        local_90 = *(uint **)(puVar1 + (ulonglong)(uVar4 - 1) * 4);
        uStack_88 = *(undefined8 *)(puVar1 + (ulonglong)(uVar4 - 1) * 4 + 2);
        local_70 = *(undefined8 *)(puVar1 + (ulonglong)uVar4 * 4);
        lStack_68 = *(longlong *)(puVar1 + (ulonglong)uVar4 * 4 + 2);
        iVar5 = RtlCompareUnicodeString(&local_90,&local_70,0);
        if (0 < iVar5) {
          *(undefined8 *)(local_res10 + (longlong)puVar1) = local_70;
          ((undefined8 *)(local_res10 + (longlong)puVar1))[1] = lStack_68;
          bVar2 = false;
          puVar7 = puVar1 + (ulonglong)uVar4 * 4;
          *puVar7 = (uint)local_90;
          puVar7[1] = local_90._4_4_;
          puVar7[2] = (uint)uStack_88;
          puVar7[3] = uStack_88._4_4_;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar11);
    } while (!bVar2);
    puVar7 = local_80;
    uVar16 = 1;
    if (1 < uVar13) {
      do {
        iVar5 = (int)uVar16;
        if (*(longlong *)(puVar7 + (ulonglong)(iVar5 - 1) * 2) == *(longlong *)(puVar7 + uVar16 * 2)
           ) {
          uVar12 = uVar13 - 1;
          uVar4 = (uVar13 - iVar5) - 1;
          uVar13 = uVar12;
          if (uVar4 != 0) {
            memmove(puVar7 + uVar16 * 2,puVar7 + (ulonglong)(iVar5 + 1U) * 2,(ulonglong)uVar4 << 3);
          }
        }
        else {
          uVar16 = (ulonglong)(iVar5 + 1U);
        }
      } while ((uint)uVar16 < uVar13);
    }
    uVar16 = 1;
    if (1 < uVar11) {
      do {
        iVar14 = (int)uVar16;
        _Dst = puVar1 + uVar16 * 4;
        local_80 = *(uint **)(puVar1 + (ulonglong)(iVar14 - 1) * 4);
        uStack_78 = *(undefined8 *)(puVar1 + (ulonglong)(iVar14 - 1) * 4 + 2);
        local_70 = *(undefined8 *)_Dst;
        lStack_68 = *(longlong *)(_Dst + 2);
        iVar5 = RtlCompareUnicodeString(&local_80,&local_70,0);
        if (iVar5 == 0) {
          uVar12 = uVar11 - 1;
          uVar4 = (uVar11 - iVar14) - 1;
          uVar11 = uVar12;
          if (uVar4 != 0) {
            memmove(_Dst,puVar1 + (ulonglong)(iVar14 + 1U) * 4,(ulonglong)uVar4 << 4);
          }
        }
        else {
          uVar16 = (ulonglong)(iVar14 + 1U);
        }
      } while ((uint)uVar16 < uVar11);
    }
    DAT_14000c288 = puVar7;
    _DAT_14000c290 = puVar1;
    DAT_14000c298 = uVar13;
    DAT_14000c29c = uVar11;
    uVar4 = QueryStringValue(param_1,&ExcludedExtensionsRemoveValueName,'\x01',(short *)local_60);
    if (-1 < (int)uVar4) {
      uVar6 = CheckExtensionsList(local_60,(int *)local_res20,(int *)local_98,(int *)&local_res10);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      if ((local_res20[0] != 0) || (local_98[0] != 0)) {
        RemoveExtensionsList((longlong)local_60);
      }
    }
    uVar6 = 0;
  }
LAB_140024d29:
  return uVar6;
}



===== AddExtensionsList @ 140024d44 =====

void AddExtensionsList(ushort *param_1,longlong param_2,uint *param_3,longlong param_4,uint *param_5
                      ,longlong *param_6)

{
  short sVar1;
  ushort uVar2;
  short *psVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  short *psVar6;
  short *psVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  
  uVar2 = *param_1 >> 1;
  psVar6 = *(short **)(param_1 + 4);
  if (uVar2 == 0) {
    return;
  }
  if (uVar2 == 1) {
    sVar1 = *psVar6;
  }
  else {
    psVar7 = psVar6;
    if ((uVar2 != 2) || (*psVar6 != 0)) goto LAB_140024dad;
    sVar1 = psVar6[1];
  }
  psVar7 = psVar6;
  if (sVar1 == 0) {
    return;
  }
LAB_140024dad:
  do {
    do {
      psVar3 = psVar7;
      psVar7 = psVar3 + 1;
    } while (*psVar7 != 0);
    uVar9 = (longlong)psVar7 - (longlong)psVar6 >> 1;
    if ((uint)uVar9 < 5) {
      lVar10 = (ulonglong)*param_3 * 8 + param_2;
      *param_3 = *param_3 + 1;
      if ((uint)uVar9 != 0) goto LAB_140024e0d;
    }
    else {
      lVar10 = *param_6;
      uVar8 = *param_5;
      *param_6 = lVar10 + (uVar9 & 0xffffffff) * 2;
      uVar5 = (ulonglong)uVar8;
      sVar1 = (short)uVar9 * 2;
      *(short *)(param_4 + uVar5 * 0x10) = sVar1;
      *(short *)(param_4 + 2 + uVar5 * 0x10) = sVar1;
      *param_5 = uVar8 + 1;
      *(longlong *)(param_4 + 8 + uVar5 * 0x10) = lVar10;
LAB_140024e0d:
      lVar10 = lVar10 - (longlong)psVar6;
      do {
        uVar4 = RtlUpcaseUnicodeChar();
        *(undefined2 *)(lVar10 + (longlong)psVar6) = uVar4;
        psVar6 = psVar6 + 1;
        uVar8 = (int)uVar9 - 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 != 0);
    }
    psVar6 = psVar3 + 2;
    psVar7 = psVar6;
    if (*psVar6 == 0) {
      return;
    }
  } while( true );
}



===== LuafvInitializePool @ 140024e68 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LuafvInitializePool(void)

{
  undefined *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  FltInitializePushLock(&PoolLock);
  ExInitializePagedLookasideList(&StoreFileLookaside,0,0,0,0x80,0x6661754c,0x80);
  _LookasideLists = &StoreFileLookaside;
  ExInitializePagedLookasideList(&TableNodeLookaside,0,0,0,0x128,0x6661754c,0x80);
  uVar4 = 0x38;
  _DAT_14000ba68 = &TableNodeLookaside;
  lVar2 = 5;
  puVar1 = &StringLookaside;
  puVar3 = &DAT_14000ba70;
  do {
    ExInitializePagedLookasideList(puVar1,0,0,0,uVar4 + 8,0x6661754c,0x80);
    *puVar3 = puVar1;
    uVar4 = (ulonglong)((int)uVar4 + 0x20);
    puVar1 = puVar1 + 0x80;
    puVar3 = puVar3 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== DriverEntry @ 140024f88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  char *pcVar5;
  longlong lVar6;
  int iVar7;
  undefined **ppuVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  undefined1 auStack_68 [32];
  uint **local_48;
  uint local_38 [2];
  uint *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  if (SkipDriverLoad != '\0') {
    return 0xc0000001;
  }
  bVar1 = LuafvSkipDriverLoad();
  if (bVar1) {
    return 0xc000036c;
  }
  wil_InitializeFeatureStaging();
  _DAT_14000c2b0 = param_1;
  ExInitializeRundownProtection(&DAT_14000c0e8);
  DAT_14000c270 = &DAT_14000c268;
  _DAT_14000c268 = &DAT_14000c268;
  uVar3 = EtwRegister(&LuafvEventProviderId,0,0,&DAT_14000c100);
  uVar4 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    wil_UninitializeFeatureStaging();
  }
  else {
    LuafvInitializePool();
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
    LuafvInitializeSdTable();
    LuafvInitializeFileTable();
    DAT_14000c288 = 0;
    DAT_14000c298 = 0;
    DAT_14000c29c = 0;
    LuafvInitializeUserList();
    LuafvInitializeScavenger();
    memset(&LuafvOperationRegistration,0,0x620);
    iVar7 = 0;
    pcVar5 = &LuafvOperationRegistration;
    do {
      cVar2 = (char)iVar7;
      iVar7 = iVar7 + 1;
      *pcVar5 = cVar2 + -0x14;
      *(code **)(pcVar5 + 8) = LuafvPreRedirect;
      pcVar5 = pcVar5 + 0x20;
    } while (iVar7 < 0x30);
    *pcVar5 = -0x80;
    cVar2 = '\0';
    ppuVar8 = &PTR_LuafvPreCreate_140005158;
    do {
      lVar6 = ((longlong)cVar2 + 0x14) * 0x20;
      *(undefined4 *)(lVar6 + 0x14000baa4) = *(undefined4 *)((longlong)ppuVar8 + -4);
      (&DAT_14000baa8)[((longlong)cVar2 + 0x14) * 4] = *ppuVar8;
      *(undefined **)(lVar6 + 0x14000bab0) = ppuVar8[1];
      cVar2 = *(char *)(ppuVar8 + 3);
      ppuVar8 = ppuVar8 + 4;
    } while (cVar2 != -0x80);
    puVar10 = &LuafvDvfcbHashTable;
    lVar6 = 0x10;
    do {
      puVar10[1] = puVar10;
      *puVar10 = puVar10;
      FltInitializePushLock(puVar10 + 2);
      puVar10 = puVar10 + 3;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    local_38[0] = LuafvReadSettings(param_2);
    uVar4 = (ulonglong)local_38[0];
    if ((int)local_38[0] < 0) {
      puVar9 = &LuafvReadSettingsFailed;
    }
    else {
      if ((DAT_14000c0f4 & 1) != 0) {
        _DAT_1400261a8 = LuafvUnload;
      }
      local_38[0] = FltRegisterFilter(param_1,&LuafvFilterRegistration,&LuafvDriverData);
      uVar4 = (ulonglong)local_38[0];
      if ((int)local_38[0] < 0) {
        LuafvDriverData = 0;
        puVar9 = &LuafvFilterRegistrationFailed;
      }
      else {
        uVar4 = LuafvInitializeSecurity();
        local_38[0] = (uint)uVar4;
        uVar4 = uVar4 & 0xffffffff;
        if ((int)local_38[0] < 0) {
          puVar9 = &LuafvInitializeSecurityFailed;
        }
        else {
          local_38[0] = FltStartFiltering(LuafvDriverData);
          uVar4 = (ulonglong)local_38[0];
          if (-1 < (int)local_38[0]) {
            return uVar4;
          }
          puVar9 = &LuafvStartFilteringFailed;
        }
      }
    }
    local_24 = 0;
    local_30 = local_38;
    local_48 = &local_30;
    local_28 = 4;
    EtwWrite(DAT_14000c100,puVar9,0,1);
    LuafvUnload();
  }
  return uVar4;
}



===== LuafvReadSettings$fin$0 @ 140025214 =====

void LuafvReadSettings_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ZwClose();
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ZwClose();
  }
  return;
}


