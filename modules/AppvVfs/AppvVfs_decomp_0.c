
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



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c0001030 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = (ushort *)param_1[1];
  uVar2 = 0;
  if (puVar1 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = puVar1;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(*param_1,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 1c0001090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&PROVIDER_MICROSOFT_APPV_CLIENT_SHAREDPERFORMANCEEVENTS_Context,param_2,
             param_3,1,local_28);
  return;
}



===== VfsPreAcquireForSectionEx @ 1c00010e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 VfsPreAcquireForSectionEx(uint *param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar4 = 1;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = EtwActivityIdControl();
  if (iVar2 < 0) {
    local_28 = 0;
    uStack_20 = 0;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(uVar4,&VFSC_PreAcquireForSectionStart,&local_28);
  }
  puVar5 = *(uint **)(param_2 + 0x20);
  uVar3 = 1;
  cVar1 = VfsDecodeFileObject((longlong)puVar5,(undefined8 *)0x0,(undefined8 *)0x0);
  if (cVar1 != '\0') {
    uVar3 = VfsAcquireForSectionSync(param_1,param_2);
    puVar5 = param_1;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar5,&VFSC_PreAcquireForSectionFinish,&local_28);
  }
  return uVar3;
}



===== VfsPreCleanupEx @ 1c00011c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VfsPreCleanupEx(uint *param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStack_88 [32];
  int local_68;
  uint *local_58;
  uint *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  uVar3 = 1;
  local_48 = 0;
  uStack_40 = 0;
  iVar2 = EtwActivityIdControl(1,&local_48);
  if (iVar2 < 0) {
    local_48 = 0;
    uStack_40 = 0;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(uVar3,&VFSC_PreCleanupStart,&local_48);
  }
  *param_3 = 0;
  local_50 = (uint *)0x0;
  uVar3 = 1;
  local_58 = (uint *)0x0;
  cVar1 = VfsDecodeFileObject(*(longlong *)(*(longlong *)(param_1 + 4) + 8),&local_58,
                              (undefined8 *)0x0);
  if (cVar1 == '\0') {
    puVar4 = *(uint **)(*(longlong *)(param_1 + 4) + 0x10);
    iVar2 = FltGetStreamContext(puVar4,*(undefined8 *)(*(longlong *)(param_1 + 4) + 8),&local_50);
    if (iVar2 < 0) {
      if (iVar2 != -0x3ffffddb) {
        puVar4 = (uint *)0x1;
        local_68 = iVar2;
        LogWrite(1,0,
                 L"VfsDecodeCleanupOperation() - Failed to get stream context for fileobject: %p\n Status: 0x%08X"
                 ,*(undefined8 *)(*(longlong *)(param_1 + 4) + 8));
      }
      goto LAB_1c000132a;
    }
    puVar4 = local_50;
  }
  else {
    puVar4 = local_58;
  }
  if ((short)*puVar4 == 0x1686) {
    puVar5 = param_1;
    VfsCleanupShadow(param_1,(longlong)puVar4,*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x20));
    param_1[6] = 0;
    uVar3 = 4;
    param_1[8] = 0;
    param_1[9] = 0;
    puVar4 = puVar5;
  }
  else {
    *param_3 = 0;
    if ((puVar4[1] & 4) != 0) {
      local_58 = (uint *)0x0;
      iVar2 = VfsCreateCleanupCompletionContext(param_1,&local_58);
      if (-1 < iVar2) {
        uVar3 = 5;
        *(uint **)local_58 = puVar4;
        *param_3 = local_58;
        puVar4 = param_1;
        goto LAB_1c000132a;
      }
    }
    FltReleaseContext();
    uVar3 = 1;
  }
LAB_1c000132a:
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar4,&VFSC_PreCleanupFinish,&local_48);
  }
  return uVar3;
}



===== VfsPreCreateEx @ 1c0001370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VfsPreCreateEx(ulonglong param_1,longlong param_2,longlong *param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *_Dst;
  undefined7 extraout_var;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined1 auStackY_108 [32];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88 [10];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar4 = 1;
  local_d8 = 0;
  uStack_d0 = 0;
  iVar3 = EtwActivityIdControl();
  if (iVar3 < 0) {
    local_d8 = 0;
    uStack_d0 = 0;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(uVar4,&VFSC_PreCreateStart,&local_d8);
  }
  _Dst = local_88;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  memset(_Dst,0,0x44);
  if (((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 2) == 0) &&
     ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) & 0x400000) == 0)) {
    uVar4 = PsGetCurrentThreadId();
    _Dst = (undefined8 *)PsGetCurrentProcessId();
    iVar3 = VeMgrLookupProcess(_Dst,uVar4,&local_c8,local_88);
    if (iVar3 < 0) {
      if (iVar3 == -0x3fffffcc) {
        local_c8 = 0;
        uStack_c0 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        goto LAB_1c0001468;
      }
      *(int *)(param_1 + 0x18) = iVar3;
LAB_1c00014b1:
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar5 = 4;
      goto LAB_1c00014de;
    }
LAB_1c0001468:
    local_a8 = 0;
    uStack_a0 = 0;
    local_98 = 0;
    uStack_90 = 0;
    iVar3 = memcmp(&local_c8,&local_a8,0x20);
    if (iVar3 != 0) {
      _Dst = &local_c8;
      uVar2 = VfsCreateCommon((undefined4 *)_Dst,(longlong)local_88,param_1,param_2,param_3);
      uVar5 = CONCAT71(extraout_var,uVar2) & 0xffffffff;
      goto LAB_1c00014de;
    }
    _Dst = *(undefined8 **)(*(longlong *)(param_2 + 0x20) + 0x40);
    if (_Dst != (undefined8 *)0x0) {
      cVar1 = VfsDecodeFileObject((longlong)_Dst,(undefined8 *)0x0,(undefined8 *)0x0);
      if (cVar1 != '\0') {
        *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
        goto LAB_1c00014b1;
      }
    }
  }
  uVar5 = 1;
LAB_1c00014de:
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(_Dst,&VFSC_PreCreateFinish,&local_d8);
  }
  return uVar5;
}



===== VfsPreDirectoryCtrlEx @ 1c0001520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VfsPreDirectoryCtrlEx
                    (short *param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  short *psVar4;
  short *psVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_68 [32];
  short *local_48;
  short *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar3 = 1;
  local_38 = 0;
  uStack_30 = 0;
  iVar2 = EtwActivityIdControl();
  if (iVar2 < 0) {
    local_38 = 0;
    uStack_30 = 0;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(uVar3,&VFSC_PreDirectoryCtrlStart,&local_38);
  }
  uVar7 = 1;
  if (*(char *)(*(longlong *)(param_1 + 8) + 5) == '\x01') {
    local_40 = (short *)0x0;
    uVar6 = 0;
    local_48 = (short *)0x0;
    cVar1 = VfsDecodeFileObject(*(longlong *)(*(longlong *)(param_1 + 8) + 8),(undefined8 *)0x0,
                                &local_48);
    if (cVar1 == '\0') {
      uVar6 = *(ulonglong *)(*(longlong *)(param_1 + 8) + 8);
      psVar4 = *(short **)(*(longlong *)(param_1 + 8) + 0x10);
      iVar2 = FltGetStreamHandleContext(psVar4,uVar6,&local_40);
      if (iVar2 < 0) goto LAB_1c0001626;
      psVar5 = local_40;
    }
    else {
      psVar5 = local_48;
    }
    uVar7 = VfsQueryDirectory((longlong)param_1,uVar6,psVar5,param_4);
    uVar7 = uVar7 & 0xffffffff;
    psVar4 = param_1;
    if (*psVar5 == 0x1688) {
      FltReleaseContext();
      psVar4 = psVar5;
    }
  }
  else {
    uVar7 = VfsPreRedirect((longlong)param_1,param_2);
    uVar7 = uVar7 & 0xffffffff;
    psVar4 = param_1;
  }
LAB_1c0001626:
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(psVar4,&VFSC_PreDirectoryCtrlFinish,&local_38);
  }
  return uVar7;
}



===== VfsPreSetInfoEx @ 1c0001670 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 VfsPreSetInfoEx(uint *param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined7 extraout_var;
  undefined8 uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined1 auStack_88 [32];
  int local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  uVar7 = 1;
  local_48 = 0;
  uStack_40 = 0;
  iVar5 = EtwActivityIdControl(1,&local_48);
  if (iVar5 < 0) {
    local_48 = 0;
    uStack_40 = 0;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(uVar7,&VFSC_PreSetInfoStart,&local_48);
  }
  lVar1 = *(longlong *)(param_1 + 4);
  cVar4 = '\0';
  uVar6 = 1;
  iVar5 = *(int *)(lVar1 + 0x20);
  if (iVar5 == 10) {
LAB_1c0001721:
    uVar7 = VfsProcessRename(param_1,param_2);
    uVar6 = (undefined4)uVar7;
    puVar8 = param_1;
    goto LAB_1c000172e;
  }
  if (iVar5 == 0xb) {
    puVar9 = *(uint **)(lVar1 + 0x28);
    puVar8 = *(uint **)(param_2 + 0x20);
    local_58[0] = 0;
    puVar10 = *(uint **)(*(longlong *)(lVar1 + 0x38) + 8);
    local_50 = 0;
    cVar4 = VfsDecodeFileObject((longlong)puVar8,(undefined8 *)0x0,(undefined8 *)0x0);
    if (cVar4 == '\0') {
      if (puVar9 != (uint *)0x0) {
        cVar4 = VfsDecodeFileObject((longlong)puVar9,(undefined8 *)0x0,(undefined8 *)0x0);
        puVar8 = puVar9;
        if (cVar4 != '\0') goto LAB_1c0001803;
      }
      if (puVar10 != (uint *)0x0) {
        cVar4 = VfsDecodeFileHandle(puVar10,(char)param_1[0x14],local_58,&local_50);
        puVar8 = puVar10;
        if (cVar4 != '\0') goto LAB_1c0001803;
      }
      uVar6 = 1;
    }
    else {
LAB_1c0001803:
      param_1[8] = 0;
      param_1[9] = 0;
      uVar6 = 4;
      param_1[6] = 0xc00000bb;
    }
    goto LAB_1c000172e;
  }
  if (iVar5 == 0xd) {
LAB_1c000178f:
    uVar7 = VfsProcessDelete(param_1,param_2);
    uVar6 = (undefined4)uVar7;
    puVar8 = param_1;
  }
  else {
    if ((((iVar5 == 0xe) || (iVar5 == 0x13)) || (iVar5 == 0x14)) || (iVar5 == 0x27)) {
      cVar4 = '\x01';
    }
    else {
      if (iVar5 == 0x40) goto LAB_1c000178f;
      if (iVar5 == 0x41) goto LAB_1c0001721;
    }
    puVar8 = *(uint **)(param_2 + 0x20);
    cVar2 = VfsDecodeFileObject((longlong)puVar8,(undefined8 *)0x0,(undefined8 *)0x0);
    if (cVar2 != '\0') {
      bVar3 = VfsWriteWorker(param_1,param_2,param_3,cVar4,'\x01');
      uVar6 = (undefined4)CONCAT71(extraout_var,bVar3);
      puVar8 = param_1;
    }
  }
LAB_1c000172e:
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar8,&VFSC_PreSetInfoFinish,&local_48);
  }
  return uVar6;
}



===== VfsPreWriteEx @ 1c0001820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VfsPreWriteEx(uint *param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined7 extraout_var;
  undefined8 uVar4;
  uint *puVar5;
  ulonglong uVar6;
  undefined1 auStack_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar4 = 1;
  local_38 = 0;
  uStack_30 = 0;
  iVar3 = EtwActivityIdControl();
  if (iVar3 < 0) {
    local_38 = 0;
    uStack_30 = 0;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(uVar4,&VFSC_PreWriteStart,&local_38);
  }
  puVar5 = *(uint **)(param_2 + 0x20);
  uVar6 = 1;
  cVar1 = VfsDecodeFileObject((longlong)puVar5,(undefined8 *)0x0,(undefined8 *)0x0);
  if (cVar1 != '\0') {
    bVar2 = VfsWriteWorker(param_1,param_2,param_3,'\x01','\0');
    uVar6 = CONCAT71(extraout_var,bVar2) & 0xffffffff;
    puVar5 = param_1;
  }
  if ((Microsoft_AppV_SharedPerformanceEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar5,&VFSC_PreWriteFinish,&local_38);
  }
  return uVar6;
}



===== VfsCleanupShadow @ 1c0001904 =====

undefined8 VfsCleanupShadow(uint *param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  uint *puVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  lVar4 = *(longlong *)(param_2 + 0x78);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar4 + 0x38,1);
  plVar1 = (longlong *)(param_3 + 8);
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) != plVar1) ||
     (plVar5 = *(longlong **)(param_3 + 0x10), (longlong *)*plVar5 != plVar1)) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    uVar7 = (*pcVar6)();
    return uVar7;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  uVar3 = *(uint *)(param_3 + 4);
  *(uint *)(param_3 + 4) = uVar3 & 0xfffffffe;
  if ((uVar3 & 0x20) != 0) {
    IoRemoveShareAccess(*(undefined8 *)(param_3 + 0x60),*(longlong *)(param_3 + 0x18) + 0x11c);
    *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) & 0xffffffdf;
  }
  LOCK();
  *(int *)(param_2 + 0x118) = *(int *)(param_2 + 0x118) + -1;
  UNLOCK();
  ExReleaseResourceLite(*(longlong *)(param_2 + 0x78) + 0x38);
  KeLeaveCriticalRegion();
  VfsProcessDeleteOnCleanupShadow(param_1,param_2,param_3);
  puVar2 = (uint *)(*(longlong *)(*(longlong *)(param_1 + 4) + 8) + 0x50);
  *puVar2 = *puVar2 | 0x4000;
  if (*(longlong *)(param_3 + 0x38) != 0) {
    FltClose();
    *(undefined8 *)(param_3 + 0x38) = 0;
  }
  if (*(longlong *)(param_3 + 0x50) != 0) {
    FltClose();
    *(undefined8 *)(param_3 + 0x50) = 0;
  }
  if (*(longlong *)(param_3 + 0x78) != 0) {
    VfsDeleteDirQueryContext(*(longlong *)(param_3 + 0x78));
    *(undefined8 *)(param_3 + 0x78) = 0;
  }
  return 0;
}



===== VfsCreateCleanupCompletionContext @ 1c0001a44 =====

int VfsCreateCleanupCompletionContext(undefined8 param_1,undefined8 *param_2)

{
  undefined2 uVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  plVar4 = (longlong *)0x0;
  iVar3 = FltGetFileNameInformation(param_1,0x101,local_res18);
  if (iVar3 < 0) {
    LogWrite(1,0,
             L"VfsCreateCleanupCompletionContext() - Failed to get filename info for data: %p\n IRP: %d\n Status: 0x%08X"
             ,param_1);
  }
  else {
    plVar4 = (longlong *)ExAllocateFromPagedLookasideList(&DAT_1c001f880);
    lVar2 = local_res18[0];
    if (plVar4 != (longlong *)0x0) {
      *plVar4 = 0;
      plVar4[1] = 0;
      plVar4[2] = 0;
      uVar1 = *(undefined2 *)(local_res18[0] + 8);
      lVar5 = ExAllocatePool2(0x100,uVar1,0x74534656);
      plVar4[2] = lVar5;
      if (lVar5 != 0) {
        *(undefined2 *)(plVar4 + 1) = 0;
        *(undefined2 *)((longlong)plVar4 + 10) = uVar1;
        iVar3 = 0;
        RtlCopyUnicodeString(plVar4 + 1,lVar2 + 8);
        goto LAB_1c0001b41;
      }
    }
    iVar3 = -0x3fffff66;
  }
LAB_1c0001b41:
  if (local_res18[0] != 0) {
    FltReleaseFileNameInformation();
  }
  if (iVar3 < 0) {
    if (plVar4 != (longlong *)0x0) {
      VfsDeleteCleanupCompletionContext(plVar4);
    }
  }
  else {
    *param_2 = plVar4;
  }
  return iVar3;
}



===== VfsDeleteCleanupCompletionContext @ 1c0001b8c =====

void VfsDeleteCleanupCompletionContext(longlong *param_1)

{
  if (param_1[2] != 0) {
    ExFreePoolWithTag(param_1[2],0);
    param_1[2] = 0;
  }
  if (*param_1 != 0) {
    FltReleaseContext();
  }
  ExFreeToPagedLookasideList(&DAT_1c001f880,param_1);
  return;
}



===== VfsProcessClose @ 1c0001be8 =====

undefined8 VfsProcessClose(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 uVar6;
  
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_2 + 0x88) + 0x18);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((*(uint *)(param_3 + 4) & 1) != 0) {
    lVar3 = *(longlong *)(*(longlong *)(param_3 + 0x18) + 0x78);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar3 + 0x38,1);
    plVar2 = (longlong *)(param_3 + 8);
    lVar3 = *plVar2;
    if ((*(longlong **)(lVar3 + 8) != plVar2) ||
       (plVar4 = *(longlong **)(param_3 + 0x10), (longlong *)*plVar4 != plVar2)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar6 = (*pcVar5)();
      return uVar6;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) & 0xfffffffe;
    if ((*(uint *)(param_3 + 4) & 0x20) != 0) {
      IoRemoveShareAccess(*(undefined8 *)(param_3 + 0x60),*(longlong *)(param_3 + 0x18) + 0x11c);
      *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) & 0xffffffdf;
    }
    ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_3 + 0x18) + 0x78) + 0x38);
    KeLeaveCriticalRegion();
  }
  VfsScbClose(param_2);
  VfsDeleteCcb(param_3);
  return 0;
}



===== _guard_check_icall @ 1c0001cf0 =====

void _guard_check_icall(void)

{
  return;
}



===== VfsCleanupInstanceContext @ 1c0001d00 =====

void VfsCleanupInstanceContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  return;
}



===== VfsCleanupStreamContext @ 1c0001d40 =====

void VfsCleanupStreamContext(longlong param_1)

{
  longlong lVar1;
  
  if ((*(uint *)(param_1 + 4) & 1) == 0) {
    lVar1 = *(longlong *)(param_1 + 8);
    if (lVar1 == 0) {
      return;
    }
  }
  else {
    if (*(longlong *)(param_1 + 8) == 0) {
      return;
    }
    while (lVar1 = RtlEnumerateGenericTableAvl(param_1 + 0x10,1), lVar1 != 0) {
      RtlDeleteElementGenericTableAvl(param_1 + 0x10,lVar1);
    }
    lVar1 = *(longlong *)(param_1 + 8);
  }
  ExDeleteResourceLite(lVar1);
  ExFreePoolWithTag(lVar1,0x72454656);
  return;
}



===== VfsCleanupStreamHandleContext @ 1c0001dd0 =====

void VfsCleanupStreamHandleContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (*(longlong *)(param_1 + 0x90) != 0) {
    VfsDeleteDirQueryContext(*(longlong *)(param_1 + 0x90));
    *(undefined8 *)(param_1 + 0x90) = 0;
  }
  return;
}



===== VfsCreateInstanceContext @ 1c0001e38 =====

ulonglong VfsCreateInstanceContext(undefined8 param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *local_res20;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_res20 = (undefined8 *)0x0;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if ((param_2 != 0x14) && (uVar2 = VfsGetVpbFromInstance(param_1,&local_28), (int)uVar2 < 0)) {
    return uVar2;
  }
  local_30 = 0;
  uStack_18 = 0;
  local_20 = local_20 & 0xffffffff00000000;
  uVar1 = FltGetVolumeFromInstance(param_1,&local_30);
  if (-1 < (int)uVar1) {
    uVar1 = VfsGetVolumeName(local_30,(undefined4 *)&local_20);
    FltObjectDereference(local_30);
  }
  if ((-1 < (int)uVar1) &&
     (uVar1 = FltAllocateContext(VfsData,2,0x28,0x200,&local_res20), -1 < (int)uVar1)) {
    *local_res20 = 0;
    local_res20[1] = 0;
    local_res20[2] = 0;
    local_res20[3] = 0;
    local_res20[4] = 0;
    *local_res20 = param_1;
    *(undefined4 *)(local_res20 + 3) = 0;
    local_res20[4] = local_28;
    *(undefined4 *)(local_res20 + 1) = (undefined4)local_20;
    *(undefined4 *)((longlong)local_res20 + 0xc) = local_20._4_4_;
    *(undefined4 *)(local_res20 + 2) = (undefined4)uStack_18;
    *(undefined4 *)((longlong)local_res20 + 0x14) = uStack_18._4_4_;
    uStack_18 = 0;
    uVar1 = FltSetInstanceContext(param_1,1,local_res20);
    if (-1 < (int)uVar1) {
      *param_3 = local_res20;
    }
  }
  if ((int)uVar1 < 0) {
    if (uStack_18 != 0) {
      ExFreePoolWithTag(uStack_18,0);
      uStack_18 = 0;
    }
    if (local_res20 != (undefined8 *)0x0) {
      FltReleaseContext();
    }
  }
  return (ulonglong)uVar1;
}



===== VfsCreateStreamHandleContext @ 1c0002000 =====

ulonglong VfsCreateStreamHandleContext(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 *local_res20;
  
  local_res20 = (undefined2 *)0x0;
  uVar2 = FltAllocateContext(VfsData,0x10,0x98,1,&local_res20);
  if (-1 < (int)uVar2) {
    memset(local_res20,0,0x98);
    *local_res20 = 0x1688;
    local_res20[1] = 0x98;
    uVar1 = FltSetStreamHandleContext(param_1,param_2,1,local_res20,0);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      FltReleaseContext(local_res20);
    }
    else {
      *param_3 = local_res20;
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== VfsGetStreamContext @ 1c00020d8 =====

ulonglong VfsGetStreamContext(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 *param_4
                             )

{
  undefined2 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined2 *local_28;
  undefined8 local_20;
  
  local_28 = (undefined2 *)0x0;
  local_20 = 0;
  uVar3 = FltGetStreamContext(param_1,param_2,&local_28);
  if (-1 < (int)uVar3) {
    *param_4 = local_28;
    return uVar3;
  }
  if ((int)uVar3 != -0x3ffffddb) {
    return uVar3;
  }
  uVar3 = FltAllocateContext(VfsData,8,0x78,1,&local_28);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  memset(local_28,0,0x78);
  puVar1 = local_28;
  *local_28 = 0x1689;
  *(uint *)(local_28 + 2) = param_3;
  if ((param_3 & 1) == 0) {
    lVar4 = ExAllocatePool2(0x40,0x68,0x72454656);
    if (lVar4 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      uVar2 = ExInitializeResourceLite(lVar4);
      if (-1 < (int)uVar2) {
        *(longlong *)(puVar1 + 4) = lVar4;
        goto LAB_1c0002205;
      }
      ExFreePoolWithTag(lVar4,0x72454656);
    }
  }
  else {
    uVar2 = VfsScbTableInitialize((longlong *)(local_28 + 4));
    if (-1 < (int)uVar2) {
LAB_1c0002205:
      uVar2 = FltSetStreamContext(param_1,param_2,1,local_28,&local_20);
      if (-1 < (int)uVar2) {
        *param_4 = local_28;
        goto LAB_1c000226f;
      }
      if (uVar2 == 0xc01c0002) {
        *param_4 = local_20;
        FltReleaseContext(local_28);
        uVar2 = 0;
        goto LAB_1c000226f;
      }
      *param_4 = 0;
    }
  }
  FltReleaseContext(local_28);
LAB_1c000226f:
  return (ulonglong)uVar2;
}



===== VfsCopyFile @ 1c0002298 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VfsCopyFile(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,char param_7,undefined8 param_8,
               undefined8 param_9,char param_10)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined1 auStackY_1e8 [32];
  undefined1 local_168 [4];
  int local_164;
  int local_160;
  longlong local_158;
  undefined4 local_150 [2];
  longlong local_148;
  longlong local_140;
  undefined4 local_138;
  longlong local_130;
  longlong local_128;
  longlong local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  longlong lStack_98;
  ulonglong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined1 local_60 [32];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_e0 = 0;
  uStack_d8 = 0;
  local_150[0] = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  lStack_98 = 0;
  local_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  local_164 = 0;
  local_128 = 0;
  local_130 = 0;
  local_140 = 0;
  lVar4 = 0;
  local_120 = 0;
  local_148 = 0;
  local_158 = 0;
  local_118 = 0x30;
  uStack_110 = 0;
  uStack_100 = 0x240;
  local_f8 = 0;
  uStack_f0 = 0;
  local_160 = (-(uint)(param_7 != '\0') & 0xffffffc1) + 100;
  local_108 = param_3;
  local_e8 = param_4;
  local_164 = FltCreateFileEx2(VfsData,param_1,&local_128,&local_148);
  if (-1 < local_164) {
    local_164 = FltQueryInformationFile(param_1,local_148,&local_c0,0x38);
    if (-1 < local_164) {
      if (param_7 != '\0') {
        local_a0 = 0;
        lStack_98 = 0;
      }
      uVar3 = VfsQueryEAs(param_1,local_148,&local_140,local_150);
      local_164 = (int)uVar3;
      if (local_164 < 0) {
        local_140 = 0;
        local_150[0] = 0;
        local_164 = 0;
      }
      local_118 = CONCAT44(local_118._4_4_,0x30);
      uStack_110 = param_5;
      uStack_100 = CONCAT44(uStack_100._4_4_,0x240);
      local_108 = param_6;
      local_f8 = 0;
      uStack_f0 = 0;
      local_90 = local_90 & 0xffffffffffffefff;
      if (param_7 == '\0') {
        local_160 = 0x4064;
      }
      else {
        local_160 = 0x4025;
      }
      local_138 = 0x100112;
      if (param_7 == '\0') {
        local_138 = 0x110112;
      }
      local_164 = FltCreateFileEx2(VfsData,param_4,&local_130,&local_158);
      lVar1 = local_158;
      if (-1 < local_164) {
        if (param_10 != '\0') {
          local_d0 = 0;
          uStack_c8 = 0;
          iVar2 = FltQueryInformationFile(param_1,local_148,local_60,0x1c);
          if (-1 < iVar2) {
            iVar2 = FltSetInformationFile(param_4,lVar1,local_60,0x1c);
          }
          local_164 = iVar2;
        }
        if ((param_7 == '\0') && (lStack_98 != 0)) {
          local_120 = 0;
          uVar6 = 0x4000;
          lVar4 = ExAllocatePool2(0x40,0x4000,0x70434656);
          if (lVar4 == 0) {
            uVar6 = 0x1000;
            lVar4 = ExAllocatePool2(0x40,0x1000,0x70434656);
            if (lVar4 == 0) {
              local_164 = -0x3fffff66;
              lVar4 = 0;
              goto LAB_1c00027ef;
            }
          }
          local_164 = 0;
          local_120 = lVar4;
          uVar5 = VfsCopyStreamData(param_1,local_148,param_4,local_158,&lStack_98,lVar4,uVar6);
          local_164 = (int)uVar5;
          if (local_164 < 0) goto LAB_1c00027ef;
        }
        local_88 = local_c0;
        uStack_80 = uStack_b8;
        local_78 = local_b0;
        uStack_70 = uStack_a8;
        local_68 = local_68 & 0xffffffff00000000;
        local_164 = FltSetInformationFile(param_4,local_158,&local_88,0x28);
      }
    }
  }
LAB_1c00027ef:
  iVar2 = local_164;
  if ((local_164 < 0) && (local_158 != 0)) {
    local_168[0] = 1;
    FltSetInformationFile(param_4,local_158,local_168,1);
  }
  if (local_148 != 0) {
    ObfDereferenceObject();
  }
  if (local_158 != 0) {
    ObfDereferenceObject();
  }
  if (local_130 != 0) {
    FltClose();
  }
  if (local_128 != 0) {
    FltClose();
  }
  if (local_140 != 0) {
    ExFreePoolWithTag(local_140,0x6e474656);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x70434656);
  }
  return iVar2;
}



===== VfsCopyStreamData @ 1c00028f8 =====

undefined8
VfsCopyStreamData(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined4 param_7)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint local_28 [2];
  undefined8 local_20;
  
  local_28[0] = 0;
  local_20 = *param_5;
  uVar2 = FltSetInformationFile(param_3,param_4,&local_20,8,0x14);
  uVar1 = param_6;
  if (-1 < (int)uVar2) {
    param_5 = (undefined8 *)0x0;
    while( true ) {
      uVar2 = FltReadFile(param_1,param_2,&param_5,param_7,uVar1,0,local_28,0,0);
      if ((int)uVar2 == -0x3fffffef) break;
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      if (local_28[0] == 0) break;
      uVar3 = (ulonglong)local_28[0];
      uVar2 = FltWriteFile(param_3,param_4,&param_5,local_28[0],uVar1,0,local_28,0,0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      param_5 = (undefined8 *)((longlong)param_5 + uVar3);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== VfsQueryEAs @ 1c0002a2c =====

ulonglong VfsQueryEAs(undefined8 param_1,undefined8 param_2,longlong *param_3,undefined4 *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  int local_res18 [4];
  uint uVar5;
  undefined8 uVar6;
  undefined8 uStack_30;
  
  *param_3 = 0;
  *param_4 = 0;
  local_res18[0] = 0;
  uVar5 = 0;
  uVar6 = 0;
  uStack_30 = 0;
  uVar2 = FltQueryInformationFile(0,param_2,local_res18,4,7,0);
  if (-1 < (int)uVar2) {
    iVar4 = local_res18[0];
    if (local_res18[0] != 0) {
      do {
        lVar3 = ExAllocatePool2(0x100,iVar4,0x6e474656);
        if (lVar3 == 0) {
          return 0xc000009a;
        }
        uVar5 = uVar5 & 0xffffff00;
        uVar1 = FltQueryEaFile(param_1,param_2,lVar3,iVar4,uVar5,0,0,0,1,&uStack_30,uVar6);
        if ((int)uVar1 < 0) {
          iVar4 = iVar4 * 2;
          ExFreePoolWithTag(lVar3,0x6e474656);
          lVar3 = 0;
        }
      } while ((uVar1 == 0x80000005) || (uVar1 == 0xc0000023));
      if ((int)uVar1 < 0) {
        return (ulonglong)uVar1;
      }
      *param_4 = (undefined4)uStack_30;
      *param_3 = lVar3;
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== VfsCowCheckExcludedExtension @ 1c0002b74 =====

void VfsCowCheckExcludedExtension(longlong param_1,undefined8 param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 0x23);
  uVar2 = *param_3;
  *param_3 = uVar2 & 0xfffffffb;
  if ((((((uVar2 & 0x20) == 0) && ((uVar2 & 0x18) != 0)) && ((uVar2 >> 0xd & 1) == 0)) &&
      ((uVar2 >> 8 & 1) == 0)) &&
     (((uVar2 & 0xc0) != 0 || ((cVar1 != '\x01' && (cVar1 != '\x04')))))) {
    if (((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0x20) == 0) &&
       (uVar3 = VfsIsExcludedExtension(param_2), (char)uVar3 == '\0')) {
      return;
    }
    LogWrite(3,0,
             L"VfsCowCheckExcludedExtension() - FileNameExtension: - %wZ\n desiredAccess:     - 0x%08X"
             ,param_2);
    *param_3 = *param_3 | 4;
  }
  return;
}



===== VfsCowCopyFile @ 1c0002c18 =====

/* WARNING: Removing unreachable block (ram,0x0001c0002f27) */
/* WARNING: Removing unreachable block (ram,0x0001c0002f3d) */

ulonglong VfsCowCopyFile(undefined8 param_1,ulonglong param_2,ushort *param_3,ushort *param_4,
                        ushort *param_5,ushort *param_6,undefined4 *param_7,longlong param_8,
                        char param_9,char param_10)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  short sVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  undefined8 uVar8;
  longlong local_res8;
  longlong *plVar9;
  undefined8 uVar10;
  uint7 in_stack_ffffffffffffff81;
  longlong local_50;
  int *local_48;
  undefined8 local_38;
  longlong lStack_30;
  ulonglong local_28;
  longlong lStack_20;
  
  local_50 = 0;
  piVar2 = (int *)0x0;
  local_48 = (int *)0x0;
  local_res8 = 0;
  if (param_9 == '\0') {
LAB_1c0002dd2:
    uVar10 = 0;
    plVar9 = &local_50;
    uVar8 = 0;
    uVar5 = 0;
    uVar1 = VfsOpenScb(param_3,0,(longlong)param_4,'\0',param_7,param_8,&local_res8,plVar9,
                       (longlong *)0x0);
    uVar6 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_1c0002ee8;
    if (local_res8 != 0) {
      uVar1 = VfsCowCopyFileForScb
                        (local_res8,-(ulonglong)(local_res8 != 0) & param_2,param_3,uVar8,param_4,
                         param_5,0,param_6,'\x01',(ulonglong)in_stack_ffffffffffffff81 << 8,
                         (undefined1 *)0x0);
      uVar6 = (ulonglong)uVar1;
      goto LAB_1c0002ee8;
    }
    uVar1 = VfsCopyFile(param_3,uVar5,param_4,param_5,0,param_6,param_10,plVar9,uVar10,'\x01');
    uVar6 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000035) {
      uVar6 = 0;
      goto LAB_1c0002ee8;
    }
    if (-1 < (int)uVar1) goto LAB_1c0002ee8;
    pwVar7 = L"VfsCowCopyFile() - Failed to copy file: %wZ\n Status: 0x%08X";
  }
  else {
    uVar1 = FltGetInstanceContext(param_5);
    if ((int)uVar1 < 0) {
      param_4 = param_5;
    }
    else {
      uVar1 = FltGetInstanceContext(param_3);
      if (-1 < (int)uVar1) {
        if (uRam0000000000000008 < *param_4) {
          lStack_30 = (ulonglong)uRam0000000000000008 + *(longlong *)(param_4 + 4);
          sVar4 = *param_4 - uRam0000000000000008;
          local_38 = (ulonglong)CONCAT22(sVar4,sVar4);
        }
        else {
          lStack_30 = 0;
          local_38 = 0;
        }
        local_28 = local_38;
        lStack_20 = lStack_30;
        piVar2 = (int *)VfsLookupMappingForUserAndPackage
                                  (param_8,param_7,8,(ushort *)&local_28,(undefined4 *)&local_38);
        local_48 = piVar2;
        if (piVar2 == (int *)0x0) {
          uVar6 = 0xc00000e5;
          pwVar7 = 
          L"VfsCowCopyFile() - Failed to get COW mapping to copy %wZ into the COW\n Status: 0x%08X";
        }
        else {
          uVar3 = VfsCreateParentDirectories
                            (param_3,param_5,(longlong)piVar2,param_6,uRam0000000000000008);
          uVar6 = uVar3 & 0xffffffff;
          if (-1 < (int)uVar3) goto LAB_1c0002dd2;
          pwVar7 = 
          L"VfsCowCopyFile() - Failed to create parent directories for %wZ\n Status: 0x%08X";
          param_4 = param_6;
        }
        goto LAB_1c0002c9e;
      }
      param_4 = param_3;
    }
    uVar6 = (ulonglong)uVar1;
    pwVar7 = L"VfsCowCopyFile() - Failed to get instance context for instance: %p\n Status: 0x%08X";
  }
LAB_1c0002c9e:
  LogWrite(1,0,pwVar7,param_4);
LAB_1c0002ee8:
  if (local_res8 != 0) {
    VfsScbClose(local_res8);
  }
  if (local_50 != 0) {
    FltClose();
  }
  if (piVar2 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar2);
  }
  return uVar6;
}



===== VfsCowCopyFileForScb @ 1c0002f70 =====

int VfsCowCopyFileForScb
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
              char param_9,undefined8 param_10,undefined1 *param_11)

{
  longlong lVar1;
  undefined1 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 local_res8;
  int local_res20;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 in_stack_ffffffffffffff48;
  undefined4 in_stack_ffffffffffffff4c;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  
  puVar2 = param_11;
  iVar3 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  if (param_11 != (undefined1 *)0x0) {
    *param_11 = 0;
  }
  lVar1 = *(longlong *)(param_1 + 0x78);
  lVar4 = param_2;
  KeEnterCriticalRegion();
  lVar4 = CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
  ExAcquireResourceExclusiveLite(lVar1 + 0x38);
  if ((*(uint *)(param_1 + 0x110) & 1) == 0) {
    if (param_2 != 0) {
      lVar4 = param_1;
      iVar3 = VfsCheckShareAccess(param_2,param_1,'\x01','\0');
      if (iVar3 < 0) goto LAB_1c0003271;
    }
    uVar6 = param_7;
    iVar3 = VfsCopyFile(param_3,lVar4,param_5,param_6,param_7,param_8,
                        (byte)(*(uint *)(param_1 + 0x110) >> 1) & 1,in_stack_ffffffffffffff40,
                        CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48),param_9);
    if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x3fffffcb)) {
      LogWrite(1,0,L"VfsCowCopyFileForScb() - Failed to copy file: %wZ\n Status: 0x%08X",param_5);
    }
    else {
      local_60 = CONCAT44(local_60._4_4_,0x30);
      uStack_58 = param_7;
      uStack_48 = CONCAT44(uStack_48._4_4_,0x240);
      local_50 = param_8;
      local_40 = 0;
      uStack_38 = 0;
      for (puVar5 = *(undefined8 **)(param_1 + 0x100);
          uVar7 = (undefined4)((ulonglong)uVar6 >> 0x20), puVar5 != (undefined8 *)(param_1 + 0x100);
          puVar5 = (undefined8 *)*puVar5) {
        param_11 = (undefined1 *)0x0;
        local_res8 = 0;
        local_70 = 0;
        uStack_68 = 0;
        if ((*(uint *)((longlong)puVar5 + -4) & 4) != 0) {
          local_res20 = FltObjectReference(param_6);
          if (local_res20 < 0) {
            uVar6 = CONCAT44(uVar7,local_res20);
            LogWrite(1,0,
                     L"VfsCowCopyFileForScb() - Failed to reference instance: %p\n Status: 0x%08X",
                     param_6);
          }
          else {
            uVar6 = CONCAT44(uVar7,*(undefined4 *)(puVar5 + 0xc));
            local_res20 = FltCreateFileEx2(VfsData,param_6,&local_res8,&param_11,uVar6,&local_60,
                                           &local_70,0,0,*(undefined4 *)((longlong)puVar5 + 100),1,
                                           *(uint *)(puVar5 + 0xd) & 0xffffff,0,0,
                                           (*(uint *)((longlong)puVar5 + -4) & 0x10 | 2) << 7,0);
            if (-1 < local_res20) {
              puVar5[9] = local_res8;
              puVar5[8] = param_11;
              puVar5[7] = param_6;
              *(undefined8 *)(puVar5[0xb] + 0x28) = *(undefined8 *)(param_11 + 0x28);
              *(undefined8 *)(puVar5[0xb] + 0x30) = *(undefined8 *)(param_11 + 0x30);
              *(uint *)((longlong)puVar5 + -4) = *(uint *)((longlong)puVar5 + -4) & 0xfffffffb;
              goto LAB_1c000325f;
            }
            FltObjectDereference(param_6);
          }
          *(int *)(puVar5 + 3) = local_res20;
        }
LAB_1c000325f:
      }
      LOCK();
      *(uint *)(param_1 + 0x110) = *(uint *)(param_1 + 0x110) | 1;
      UNLOCK();
      iVar3 = 0;
    }
  }
  else if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 1;
  }
LAB_1c0003271:
  ExReleaseResourceLite(*(longlong *)(param_1 + 0x78) + 0x38);
  KeLeaveCriticalRegion();
  return iVar3;
}



===== VfsCowQueryFile @ 1c00032b4 =====

ulonglong VfsCowQueryFile(longlong param_1,undefined8 param_2,ushort *param_3,undefined4 *param_4,
                         longlong param_5,longlong param_6,undefined8 param_7,ushort *param_8,
                         uint *param_9)

{
  uint uVar1;
  uint extraout_EAX;
  char *pcVar2;
  ulonglong extraout_RAX;
  ulonglong extraout_RAX_00;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  undefined4 uVar8;
  uint *puVar7;
  wchar_t *pwVar9;
  byte bVar10;
  char cVar11;
  byte bVar12;
  byte local_res8 [8];
  char local_48;
  char local_47;
  byte local_46;
  byte local_45 [5];
  ushort local_40 [3];
  ushort uStack_3a;
  longlong lStack_38;
  
  if (param_1 == 0) {
LAB_1c0003397:
    if (param_6 != 0) {
      local_47 = '\0';
      bVar10 = 0;
      local_48 = '\0';
      local_res8[0] = 0;
      local_46 = 0;
      local_45[0] = 0;
      uVar8 = (undefined4)((ulonglong)param_9 >> 0x20);
      iVar6 = VfsQueryFile(param_6,param_7,(longlong)param_8,(undefined4 *)0x0,0,&local_47,
                           (undefined1 *)0x0,&local_48,local_res8,&local_46);
      bVar12 = local_46;
      puVar7 = (uint *)CONCAT44(uVar8,iVar6);
      uVar3 = extraout_RAX & 0xffffffff;
      if ((int)extraout_RAX < 0) {
        if ((int)extraout_RAX == -0x3fffffcd) goto LAB_1c000357d;
        pwVar9 = L"VfsCowQueryFile() - Failed to query user file: %wZ\n Status: 0x%08X";
        param_3 = param_8;
        goto LAB_1c000335f;
      }
      uVar1 = *puVar7;
      cVar11 = local_47;
      if (((uVar1 & 0x40) != 0) && (local_47 != '\0')) {
        if ((uVar1 >> 8 & 1) == 0) {
          if (local_res8[0] != 0) goto LAB_1c0003448;
        }
        else if (local_res8[0] == 0) {
LAB_1c0003448:
          local_res8[0] = (byte)(uVar1 >> 8) & 1;
          *puVar7 = uVar1 | 0x400;
          cVar11 = '\0';
        }
      }
      if ((local_48 != '\0') && ((cVar11 == '\0' || (local_46 != 0)))) {
        local_40[2] = param_8[2];
        uStack_3a = param_8[3];
        lStack_38 = *(longlong *)(param_8 + 4);
        uVar4 = *param_8 >> 1;
        if (uVar4 != 0) {
          uVar5 = uVar4 - 1;
          if (*(short *)(lStack_38 + (ulonglong)uVar5 * 2) == 0x5c) {
            if (uVar5 < 2) goto LAB_1c00034c4;
            uVar5 = uVar4 - 2;
          }
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            if (*(short *)(lStack_38 + (ulonglong)uVar5 * 2) == 0x5c) {
              if ((ushort)(uVar5 + 1) != 0) {
                local_40[1] = param_8[1];
                local_40[0] = (uVar5 + 1) * 2;
                goto LAB_1c00034cc;
              }
              break;
            }
          }
        }
LAB_1c00034c4:
        lStack_38 = 0;
        local_40[0] = 0;
        local_40[1] = 0;
LAB_1c00034cc:
        iVar6 = VfsQueryFile(param_6,param_7,(longlong)local_40,(undefined4 *)0x0,0,&local_48,
                             (undefined1 *)0x0,(undefined1 *)0x0,(undefined1 *)0x0,local_45);
        puVar7 = (uint *)CONCAT44(uVar8,iVar6);
        uVar3 = extraout_RAX_00 & 0xffffffff;
        if ((int)extraout_RAX_00 < 0) {
          if ((int)extraout_RAX_00 == -0x3fffffcd) goto LAB_1c000357d;
          param_3 = local_40;
          pwVar9 = L"VfsCowQueryFile() - Failed to query user parent: %wZ\n Status: 0x%08X";
          goto LAB_1c000335f;
        }
        if (local_48 == '\0') {
          cVar11 = '\0';
          bVar12 = 0;
        }
        else {
          bVar10 = local_45[0];
        }
      }
      if (cVar11 != '\0') {
        *puVar7 = *puVar7 | 0x80;
      }
      if (local_48 != '\0') {
        *puVar7 = *puVar7 | 0x10;
      }
      if (local_res8[0] != 0) {
        *puVar7 = *puVar7 | 0x100;
      }
      if (bVar12 != 0) {
        *puVar7 = *puVar7 | 0x200;
      }
      if (bVar10 != 0) {
        *puVar7 = *puVar7 | 0x20;
      }
    }
    uVar3 = 0;
  }
  else {
    local_res8[0] = 0;
    local_46 = 0;
    local_47 = '\0';
    local_48 = '\0';
    if ((param_4 == (undefined4 *)0x0) || (pcVar2 = &local_48, param_5 == 0)) {
      pcVar2 = (char *)0x0;
    }
    iVar6 = VfsQueryFile(param_1,param_2,(longlong)param_3,param_4,param_5,(char *)local_res8,pcVar2
                         ,&local_46,&local_47,(byte *)0x0);
    param_9 = (uint *)CONCAT44((int)((ulonglong)param_9 >> 0x20),iVar6);
    uVar3 = (ulonglong)extraout_EAX;
    if (-1 < (int)extraout_EAX) {
      if (local_res8[0] != 0) {
        *param_9 = *param_9 | 0x40;
      }
      if (local_46 != 0) {
        *param_9 = *param_9 | 8;
      }
      if (local_47 != '\0') {
        *param_9 = *param_9 | 0x100;
      }
      if (local_48 != '\0') {
        *param_9 = *param_9 | 0x800;
      }
      goto LAB_1c0003397;
    }
    if (extraout_EAX == 0xc0000033) goto LAB_1c000357d;
    pwVar9 = L"VfsCowQueryFile() - Failed to query package file: %wZ\n Status: 0x%08X";
LAB_1c000335f:
    LogWrite(1,0,pwVar9,param_3);
  }
LAB_1c000357d:
  return uVar3;
}



===== VfsCowQueryFileForUserAndPackage @ 1c00035a4 =====

ulonglong VfsCowQueryFileForUserAndPackage
                    (longlong param_1,longlong param_2,undefined4 *param_3,longlong param_4,
                    ushort *param_5,ushort *param_6,short *param_7,ulonglong *param_8,
                    longlong *param_9,undefined8 *param_10,int *param_11,uint *param_12)

{
  uint uVar1;
  bool bVar2;
  ushort uVar3;
  int *piVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  short sVar7;
  longlong lVar8;
  longlong local_80;
  int *local_78;
  ushort local_70 [4];
  short *psStack_68;
  undefined8 local_60;
  longlong lStack_58;
  undefined8 local_48;
  longlong lStack_40;
  
  local_80 = 0;
  local_48._0_4_ = 0;
  lStack_40 = 0;
  local_60 = 0;
  lStack_58 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  psStack_68 = (short *)0x0;
  *param_8 = 0;
  *param_9 = 0;
  *param_11 = 0;
  param_10[1] = 0;
  *(undefined4 *)param_10 = 0;
  uVar3 = *param_5;
  if (uVar3 < *param_6) {
    lStack_40 = (ulonglong)uVar3 + *(longlong *)(param_6 + 4);
    sVar7 = *param_6 - uVar3;
    local_48._0_4_ = CONCAT22(sVar7,sVar7);
  }
  local_48 = (ulonglong)(uint)local_48;
  piVar4 = (int *)VfsLookupMappingForUserAndPackage
                            (param_2,param_3,param_5,(ushort *)&local_48,(undefined4 *)local_70);
  uVar6 = 0;
  if (piVar4 != (int *)0x0) {
    uVar1 = *param_12;
    *param_12 = uVar1 | 1;
    if ((local_70[0] == 0) || ((local_70[0] == 2 && (*psStack_68 == 0x5c)))) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      *param_12 = uVar1 | 3;
    }
    local_78 = piVar4;
    uVar3 = GetNumberComponents((ushort *)&local_48);
    *param_11 = (uint)uVar3 - (uint)*(ushort *)(*(longlong *)(piVar4 + 10) + 0x10);
    uVar5 = VfsGetMappedTarget(param_4,local_70,'\x01',(longlong)piVar4,&local_60,&local_80);
    lVar8 = local_80;
    uVar6 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      LogWrite(1,0,
               L"VfsCowQueryFileForUserAndPackage() - Failed to map filename: %wZ\n for mapping: %wZ\n Status: 0x%08X"
               ,local_70);
      lVar8 = local_80;
    }
    else {
      uVar5 = VfsCowQueryFile(param_4,0,param_6,param_3,param_2,local_80,0,(ushort *)&local_60,
                              param_12);
      uVar6 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        if ((param_7 != (short *)0x0) && (*param_7 != 0)) {
          VfsCowCheckExcludedExtension(param_1,param_7,param_12);
        }
        *param_8 = (ulonglong)piVar4;
        *param_9 = lVar8;
        *param_10 = local_60;
        param_10[1] = lStack_58;
        piVar4 = (int *)0x0;
        local_78 = (int *)0x0;
        lVar8 = 0;
        local_80 = 0;
      }
    }
    if (piVar4 != (int *)0x0) {
      VfsReleaseMappingEntry(piVar4);
    }
    if ((lVar8 != 0) && (FltObjectDereference(lVar8), lStack_58 != 0)) {
      ExFreePoolWithTag(lStack_58,0);
    }
  }
  return uVar6;
}



===== VfsOpenScb @ 1c0003844 =====

int VfsOpenScb(undefined8 param_1,undefined8 param_2,longlong param_3,char param_4,
              undefined4 *param_5,longlong param_6,longlong *param_7,longlong *param_8,
              longlong *param_9)

{
  int iVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  
  local_38 = 0;
  local_40 = 0;
  local_30 = 0;
  *param_7 = 0;
  *param_8 = 0;
  if (param_9 != (longlong *)0x0) {
    *param_9 = 0;
  }
  iVar1 = VfsOpenFile(param_1,param_2,param_3,0x100000,1,0x4020,&local_38,&local_40);
  if (iVar1 < 0) {
    pwVar3 = L"VfsOpenScb() - Failed to open file: %wZ\n Status: 0x%08X";
  }
  else {
    iVar1 = FltGetStreamContext(param_1,local_40,&local_30);
    if (-1 < iVar1) {
      if ((param_5 == (undefined4 *)0x0) || (param_6 == 0)) {
        lVar2 = VfsScbUnitOpenScb(local_30);
      }
      else {
        lVar2 = VfsScbTableGetScb(local_30,param_5,param_6,'\x01',(undefined1 *)0x0);
      }
      *param_7 = lVar2;
      goto LAB_1c0003971;
    }
    if (iVar1 == -0x3ffffddb) {
      iVar1 = 0;
      goto LAB_1c0003971;
    }
    pwVar3 = L"VfsOpenScb() - Failed to get stream context for fileobject: %p\n Status: 0x%08X";
    param_3 = local_40;
  }
  LogWrite(1,0,pwVar3,param_3);
LAB_1c0003971:
  if ((-1 < iVar1) && ((*param_7 != 0 || (param_4 != '\0')))) {
    *param_8 = local_38;
    local_38 = 0;
    if (param_9 != (longlong *)0x0) {
      *param_9 = local_40;
      local_40 = 0;
    }
  }
  if (local_30 != 0) {
    FltReleaseContext();
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  if (local_38 != 0) {
    FltClose();
  }
  return iVar1;
}



===== VfsQueryFile @ 1c0003a08 =====

int VfsQueryFile(undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 *param_4,
                longlong param_5,char *param_6,undefined1 *param_7,undefined1 *param_8,
                undefined1 *param_9,byte *param_10)

{
  char *pcVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  int unaff_EBX;
  wchar_t *pwVar9;
  longlong local_40;
  longlong local_38 [2];
  
  pbVar5 = param_10;
  puVar4 = param_9;
  puVar3 = param_8;
  puVar2 = param_7;
  pcVar1 = param_6;
  local_38[0] = 0;
  local_40 = 0;
  *param_6 = '\0';
  if (param_7 != (undefined1 *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      return unaff_EBX;
    }
    if (param_5 == 0) {
      return unaff_EBX;
    }
    *param_7 = 0;
  }
  if (param_8 != (undefined1 *)0x0) {
    *param_8 = 0;
  }
  if (param_9 != (undefined1 *)0x0) {
    *param_9 = 0;
  }
  if (param_10 != (byte *)0x0) {
    *param_10 = 0;
  }
  iVar6 = VfsOpenFile(param_1,param_2,param_3,0x100008,1,0x4020,local_38,&local_40);
  if (iVar6 < 0) {
    if ((iVar6 == -0x3fffffcc) || (iVar6 == -0x3fffffc6)) {
      if ((puVar3 != (undefined1 *)0x0) && (iVar6 == -0x3fffffcc)) {
        *puVar3 = 1;
      }
      goto LAB_1c0003c4f;
    }
    if (iVar6 == -0x3fffffcd) goto LAB_1c0003c4f;
    pwVar9 = L"VfsQueryFile() - Failed to open file: %wZ\n Status: 0x%08X";
  }
  else {
    *pcVar1 = '\x01';
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 1;
    }
    if ((puVar4 != (undefined1 *)0x0) &&
       (iVar6 = FltIsDirectory(local_40,param_1,puVar4), iVar6 < 0)) goto LAB_1c0003c4f;
    if ((pbVar5 != (byte *)0x0) && (*pcVar1 != '\0')) {
      uVar7 = VfsQueryTombstone(param_1,local_40);
      *pbVar5 = (byte)(uVar7 >> 0x1f) & 1 ^ 1;
    }
    if (puVar2 == (undefined1 *)0x0) goto LAB_1c0003c4f;
    param_6 = (char *)0x0;
    iVar6 = FltGetStreamContext(param_1,local_40,&param_6);
    if (iVar6 == -0x3ffffddb) goto LAB_1c0003c4f;
    if (-1 < iVar6) {
      if ((*(uint *)(param_6 + 4) & 1) == 0) {
        lVar8 = *(longlong *)(param_6 + 0x10);
      }
      else {
        lVar8 = VfsScbTableGetScb((longlong)param_6,param_4,param_5,'\0',(undefined1 *)0x0);
      }
      *puVar2 = lVar8 != 0;
      FltReleaseContext(param_6);
      goto LAB_1c0003c4f;
    }
    pwVar9 = L"VfsQueryFile() - Failed to get stream context for fileobject: %p\n Status: 0x%08X";
    param_3 = local_40;
  }
  LogWrite(1,0,pwVar9,param_3);
LAB_1c0003c4f:
  if (local_38[0] != 0) {
    FltClose();
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  return unaff_EBX;
}



===== VfsCreateCommon @ 1c0003c88 =====

undefined1
VfsCreateCommon(undefined4 *param_1,longlong param_2,ulonglong param_3,longlong param_4,
               longlong *param_5)

{
  ushort *puVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  longlong lVar6;
  bool bVar7;
  undefined1 uVar8;
  int local_res20 [2];
  longlong local_80;
  longlong local_78 [2];
  int *local_68;
  longlong local_48;
  longlong local_38;
  uint local_2c;
  
  uVar8 = 1;
  local_80 = 0;
  lVar6 = *(longlong *)(*(longlong *)(param_4 + 0x20) + 0x40);
  local_res20[0] = 0;
  memset(local_78,0,0x50);
  *param_5 = 0;
  uVar3 = 0x102;
  if (lVar6 != 0) {
    cVar2 = VfsDecodeFileObject(lVar6,(undefined8 *)0x0,(undefined8 *)0x0);
    uVar3 = 0x102;
    if (cVar2 != '\0') {
      uVar3 = 0x1000102;
    }
  }
  uVar3 = VfsGetFileNameInformation(param_3,(ulonglong)uVar3,&local_80,param_4,(short *)0x0);
  lVar6 = local_80;
  if ((int)uVar3 < 0) {
    LogWrite(1,0,
             L"VfsCreateCommon() - Failed to get filename info for data: %p\n IRP: %d\n Status: 0x%08X"
             ,param_3);
    lVar6 = local_80;
  }
  else {
    puVar1 = (ushort *)(local_80 + 8);
    uVar4 = VfsCreateContextSetup
                      (param_2,param_1,param_3,(ushort *)(local_80 + 0x18),puVar1,
                       (short *)(local_80 + 0x38),local_78);
    uVar3 = (uint)uVar4;
    if ((int)uVar3 < 0) {
      if (uVar3 != 0xc0000033) {
        LogWrite(1,0,
                 L"VfsCreateCommon() - Failed to create context setup for file: %wZ\n Status: 0x%08X"
                 ,puVar1);
      }
    }
    else {
      uVar3 = VfsCreateContextValidate(param_3,(longlong)local_78,local_res20);
      if (-1 < (int)uVar3) {
        if (local_res20[0] != 1) {
          bVar5 = *(byte *)(*(longlong *)(param_3 + 0x10) + 0x23);
          if ((bVar5 < 6) && ((0x29U >> (bVar5 & 0x1f) & 1) != 0)) {
            if ((local_2c & 0xc0) == 0 || (local_2c >> 9 & 1) != 0) {
              bVar5 = 2;
            }
            else {
              bVar7 = bVar5 == 3;
              bVar5 = 4;
              if (bVar7) {
                bVar5 = 1;
              }
            }
          }
          if ((*(byte *)(*(longlong *)(param_3 + 0x10) + 6) & 4) == 0) {
            if (bVar5 == 1) {
              uVar4 = VfsCreateForOpen(param_3,local_78,local_res20);
              uVar3 = (uint)uVar4;
            }
            else if (bVar5 == 4) {
              uVar4 = VfsCreateForOverwrite(param_3,local_78,local_res20);
              uVar3 = (uint)uVar4;
            }
            else if (bVar5 == 2) {
              uVar3 = VfsCreateForCreate(param_3,local_78,local_res20);
            }
            else {
              uVar3 = 0xc000000d;
            }
          }
          else {
            uVar3 = VfsCreateForOpenTargetDirectory(param_3,local_78,local_res20);
          }
          if ((int)uVar3 < 0) goto LAB_1c0003f08;
          if (local_res20[0] != 1) {
            uVar8 = 4;
            if (local_res20[0] == 2) {
              *(undefined4 *)(param_3 + 0x18) = 0x104;
              *(undefined8 *)(param_3 + 0x20) = 0;
            }
            goto LAB_1c0003f08;
          }
        }
        uVar3 = VfsCreateCompletionContext(param_3,local_78,lVar6,param_5);
        if (-1 < (int)uVar3) {
          uVar8 = *param_5 == 0;
        }
      }
    }
  }
LAB_1c0003f08:
  if ((int)uVar3 < 0) {
    *(uint *)(param_3 + 0x18) = uVar3;
    *(undefined8 *)(param_3 + 0x20) = 0;
    uVar8 = 4;
  }
  if (lVar6 != 0) {
    FltReleaseFileNameInformation(lVar6);
  }
  if (local_68 != (int *)0x0) {
    VfsReleaseMappingEntry(local_68);
  }
  if ((local_48 != 0) && (FltObjectDereference(), local_38 != 0)) {
    ExFreePoolWithTag(local_38,0);
  }
  return uVar8;
}



===== VfsCreateCompletion @ 1c0003f98 =====

void VfsCreateCompletion(longlong param_1,longlong param_2,uint *param_3)

{
  undefined2 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong local_res8;
  longlong local_res20;
  
  if (*(int *)(param_1 + 0x18) != 0) goto LAB_1c0004193;
  if ((*param_3 & 2) != 0) {
    *(undefined8 *)(*(longlong *)(param_2 + 0x20) + 0x40) = *(undefined8 *)(param_3 + 2);
  }
  if ((*(int *)(param_1 + 0x18) != 0) || ((*param_3 & 4) == 0)) goto LAB_1c0004193;
  local_res8 = 0;
  local_res20 = 0;
  uVar6 = VfsCreateStreamHandleContext
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res8);
  iVar5 = (int)uVar6;
  if (-1 < iVar5) {
    if ((*param_3 & 1) == 0) {
LAB_1c00040fd:
      lVar3 = local_res8;
      RtlCopySid(0x44,local_res8 + 0x48,param_3 + 4);
      uVar2 = *(undefined8 *)(param_3 + 0x17);
      *(undefined8 *)(lVar3 + 0x28) = *(undefined8 *)(param_3 + 0x15);
      *(undefined8 *)(lVar3 + 0x30) = uVar2;
      uVar2 = *(undefined8 *)(param_3 + 0x1b);
      *(undefined8 *)(lVar3 + 0x38) = *(undefined8 *)(param_3 + 0x19);
      *(undefined8 *)(lVar3 + 0x40) = uVar2;
    }
    else {
      iVar5 = FltGetFileNameInformation(param_1,0x101,&local_res20);
      lVar4 = local_res20;
      lVar3 = local_res8;
      if (iVar5 < 0) {
        LogWrite(1,0,
                 L"VfsCreateCompletion() - Failed to get filename info for data: %p\n IRP: %d\n Status: 0x%08X"
                 ,param_1);
      }
      else {
        uVar1 = *(undefined2 *)(local_res20 + 8);
        lVar7 = ExAllocatePool2(0x100,uVar1,0x74534656);
        *(longlong *)(lVar3 + 0x10) = lVar7;
        if (lVar7 == 0) {
          iVar5 = -0x3fffff66;
        }
        else {
          *(undefined2 *)(lVar3 + 8) = 0;
          *(undefined2 *)(lVar3 + 10) = uVar1;
          iVar5 = 0;
          RtlCopyUnicodeString(lVar3 + 8,lVar4 + 8);
        }
        if (-1 < iVar5) {
          if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 4) != 0) {
            uVar2 = *(undefined8 *)(param_3 + 0x20);
            *(undefined8 *)(local_res8 + 0x18) = *(undefined8 *)(param_3 + 0x1e);
            *(undefined8 *)(local_res8 + 0x20) = uVar2;
            param_3[0x20] = 0;
            param_3[0x21] = 0;
          }
          goto LAB_1c00040fd;
        }
      }
    }
  }
  if (local_res20 != 0) {
    FltReleaseFileNameInformation();
  }
  if (local_res8 != 0) {
    if (iVar5 < 0) {
      FltDeleteContext(local_res8);
    }
    FltReleaseContext(local_res8);
  }
  if (iVar5 < 0) {
    FltCancelFileOpen(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    *(int *)(param_1 + 0x18) = iVar5;
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
LAB_1c0004193:
  VfsDeleteCreateCompletionContext((longlong)param_3);
  return;
}



===== VfsCreateCompletionContext @ 1c00041bc =====

int VfsCreateCompletionContext
              (longlong param_1,undefined8 *param_2,longlong param_3,undefined8 *param_4)

{
  undefined2 uVar1;
  ushort uVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  uint *_Dst;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  short sVar11;
  
  iVar7 = 0;
  uVar10 = 0;
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  lVar8 = *(longlong *)(lVar3 + 0x40);
  *param_4 = 0;
  if ((((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0xff000000) == 0x1000000) &&
      ((*(uint *)((longlong)param_2 + 0x4c) & 0x1c0) == 0x1c0)) &&
     (uVar10 = 0, (*(uint *)((longlong)param_2 + 0x4c) >> 9 & 1) == 0)) {
    uVar10 = 4;
  }
  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 4) != 0) {
    uVar10 = 4;
  }
  if ((lVar8 != 0) &&
     (cVar6 = VfsDecodeFileObject(lVar8,(undefined8 *)0x0,(undefined8 *)0x0), cVar6 != '\0')) {
    uVar10 = uVar10 | 2;
  }
  if (uVar10 == 0) {
    return 0;
  }
  _Dst = (uint *)ExAllocateFromPagedLookasideList(&DAT_1c001f800);
  if (_Dst == (uint *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,0x88);
  uVar9 = 0;
  if ((uVar10 & 2) != 0) {
    *_Dst = 2;
    *(longlong *)(_Dst + 2) = lVar8;
    uVar9 = 2;
  }
  if ((uVar10 & 4) != 0) {
    *_Dst = uVar9 | 4;
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 4) != 0) {
      *_Dst = uVar9 | 5;
      uVar1 = *(undefined2 *)(param_3 + 0x58);
      lVar8 = ExAllocatePool2(0x100,uVar1,0x74534656);
      *(longlong *)(_Dst + 0x20) = lVar8;
      if (lVar8 == 0) {
        iVar7 = -0x3fffff66;
      }
      else {
        *(undefined2 *)(_Dst + 0x1e) = 0;
        *(undefined2 *)((longlong)_Dst + 0x7a) = uVar1;
        iVar7 = 0;
        RtlCopyUnicodeString(_Dst + 0x1e,param_3 + 0x58);
      }
      if (iVar7 < 0) goto LAB_1c00043f9;
    }
    puVar4 = (uint *)param_2[1];
    uVar10 = puVar4[1];
    uVar9 = puVar4[2];
    uVar5 = puVar4[3];
    _Dst[0x15] = *puVar4;
    _Dst[0x16] = uVar10;
    _Dst[0x17] = uVar9;
    _Dst[0x18] = uVar5;
    uVar10 = puVar4[5];
    uVar9 = puVar4[6];
    uVar5 = puVar4[7];
    _Dst[0x19] = puVar4[4];
    _Dst[0x1a] = uVar10;
    _Dst[0x1b] = uVar9;
    _Dst[0x1c] = uVar5;
    RtlCopySid(0x44,_Dst + 4,*param_2);
  }
  if ((*_Dst & 2) != 0) {
    uVar2 = *(ushort *)(param_3 + 0x18);
    if (uVar2 < *(ushort *)(param_3 + 8)) {
      lVar8 = (ulonglong)uVar2 + *(longlong *)(param_3 + 0x10);
      sVar11 = *(ushort *)(param_3 + 8) - uVar2;
    }
    else {
      lVar8 = 0;
      sVar11 = 0;
    }
    iVar7 = IoReplaceFileObjectName(lVar3,lVar8,sVar11);
    if (iVar7 < 0) goto LAB_1c00043f9;
    *(undefined8 *)(lVar3 + 0x40) = 0;
  }
  *param_4 = _Dst;
LAB_1c00043f9:
  if (iVar7 < 0) {
    VfsDeleteCreateCompletionContext((longlong)_Dst);
  }
  return iVar7;
}



===== VfsCreateContextNormalize @ 1c0004414 =====

ulonglong VfsCreateContextNormalize(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 local_res8 [8];
  ushort local_50 [4];
  longlong lStack_48;
  ushort local_40 [9];
  undefined6 uStack_2e;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  stack0xffffffffffffffd0 = 0;
  uStack_28 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  local_40[5] = 0;
  local_40[6] = 0;
  local_40[7] = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  lStack_48 = 0;
  local_20 = 0;
  uStack_18 = 0;
  uVar3 = VfsGetRelativeNameByMapping(lVar1,(short *)(param_1 + 0x20),'\0',(undefined8 *)local_40);
  uVar4 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    uStack_28 = *(undefined8 *)(param_1 + 0x28);
    stack0xffffffffffffffd0 =
         CONCAT62(*(undefined6 *)(param_1 + 0x22),*(short *)(param_1 + 0x20) - local_40[0]);
    uVar2 = VfsNormalizeFileName
                      (*(undefined8 *)(param_1 + 0x18),local_40 + 8,local_40,local_50,local_res8);
    uVar4 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar3 = VfsGenerateMappedName(lVar1,local_50,(ushort *)&local_20);
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        if (*(longlong *)(param_1 + 0x40) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_1 + 0x40),0);
          *(undefined8 *)(param_1 + 0x40) = 0;
        }
        *(undefined8 *)(param_1 + 0x38) = local_20;
        *(undefined8 *)(param_1 + 0x40) = uStack_18;
      }
    }
  }
  if (lStack_48 != 0) {
    ExFreePoolWithTag(lStack_48,0);
  }
  return uVar4;
}



===== VfsCreateContextSetup @ 1c0004530 =====

ulonglong VfsCreateContextSetup
                    (longlong param_1,undefined4 *param_2,longlong param_3,ushort *param_4,
                    ushort *param_5,short *param_6,longlong *param_7)

{
  uint *puVar1;
  byte bVar2;
  longlong lVar3;
  short *psVar4;
  ulonglong uVar5;
  uint uVar6;
  
  bVar2 = *(byte *)(*(longlong *)(param_3 + 0x10) + 6);
  param_7[1] = (longlong)param_2;
  puVar1 = (uint *)((longlong)param_7 + 0x4c);
  *param_7 = param_1;
  uVar6 = *(uint *)(*(longlong *)(param_3 + 0x10) + 0x20) & 0x1000 | *puVar1 & 0xffffefff;
  *puVar1 = uVar6;
  uVar6 = (*(int *)(*(longlong *)(param_3 + 0x10) + 0x20) << 0xd ^ uVar6) & 0x2000 ^ uVar6;
  *puVar1 = uVar6;
  *puVar1 = (*(uint *)(*(longlong *)(param_3 + 0x10) + 0x20) & 0x40) << 8 | uVar6 & 0xffffbfff;
  psVar4 = (short *)0x0;
  if ((bVar2 & 4) == 0) {
    psVar4 = param_6;
  }
  uVar5 = VfsCowQueryFileForUserAndPackage
                    (param_3,param_1,param_2,*(longlong *)(*(longlong *)(param_3 + 0x10) + 0x10),
                     param_4,param_5,psVar4,(ulonglong *)(param_7 + 2),param_7 + 6,param_7 + 7,
                     (int *)(param_7 + 9),puVar1);
  if (-1 < (int)uVar5) {
    if (param_7[2] != 0) {
      param_7[3] = *(longlong *)(*(longlong *)(param_3 + 0x10) + 0x10);
      lVar3 = *(longlong *)(param_5 + 4);
      param_7[4] = *(longlong *)param_5;
      param_7[5] = lVar3;
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== VfsCreateContextValidate @ 1c000466c =====

uint VfsCreateContextValidate(longlong param_1,longlong param_2,undefined4 *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x10) + 0x23);
  uVar2 = *(uint *)(param_2 + 0x4c);
  if (*(longlong *)(param_2 + 0x10) == 0) {
    *param_3 = 1;
  }
  else {
    if (((uVar2 & 0x6000) == 0x6000) ||
       ((((bVar1 & 0xfa) == 0 && (bVar1 != 1)) && ((uVar2 & 0x2000) != 0)))) {
      return 0xc000000d;
    }
    if (((uVar2 & 0x20) != 0) || ((uVar2 & 0x18) == 0)) {
      return 0xc000003a;
    }
    uVar3 = (uint)bVar1;
    if ((((bVar1 & 0xfa) == 0) && (uVar3 != 1)) &&
       (((uVar2 & 0xc0) != 0 && (((uVar2 >> 9 & 1) == 0 && ((uVar2 >> 8 & 1) != 0)))))) {
      if ((uVar2 >> 0xe & 1) == 0) {
        return 0xc0000035;
      }
      return 0xc00000ba;
    }
    if ((((bVar1 - 1 & 0xfffffffd) == 0) && ((uVar2 & 0xc0) != 0)) && ((uVar2 >> 9 & 1) == 0)) {
      if ((uVar2 >> 8 & 1) == 0) {
        return -(uint)((uVar2 & 0x2000) != 0) & 0xc0000103;
      }
      if ((uVar2 >> 0xe & 1) != 0) {
        return 0xc00000ba;
      }
    }
    else if ((((uVar2 >> 9 & 1) != 0) && (uVar3 < 6)) && ((0x2dU >> (uVar3 & 0x1f) & 1) != 0)) {
      if ((uVar2 >> 8 & 1) == 0) {
        return -(uint)((uVar2 & 0x2000) != 0) & 0xc0000022;
      }
      if ((uVar2 & 0x2000) == 0) {
        return 0xc0000022;
      }
    }
  }
  return 0;
}



===== VfsCreateForCreate @ 1c0004784 =====

/* WARNING: Removing unreachable block (ram,0x0001c0004824) */

int VfsCreateForCreate(longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  undefined8 *puVar8;
  uint uVar9;
  bool bVar10;
  char local_res10 [8];
  ulonglong local_res18;
  
  *param_3 = 0;
  uVar5 = *(uint *)((longlong)param_2 + 0x4c);
  local_res18 = local_res18 & 0xffffffffff000000;
  uVar4 = uVar5 >> 9 & 1;
  local_res10[0] = '\0';
  if (((uVar5 & 0xc0) != 0) && (uVar4 == 0)) {
    return -0x3fffffcb;
  }
  if ((uVar5 & 4) == 0) {
    if (((uVar5 >> 0xd & 1) == 0) && (uVar4 == 0)) {
      if ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0x10000) == 0) {
        bVar10 = param_2[3] == param_2[6];
      }
      else {
        bVar10 = false;
      }
    }
    else {
      bVar10 = false;
    }
    iVar2 = *(int *)(param_2 + 9);
    lVar6 = param_2[2];
    lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8);
    uVar4 = *(uint *)(lVar1 + 0x10);
    uVar5 = (*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 1) * 2 + 2;
    uVar9 = uVar5 | 0x1000000;
    if ((uVar4 & 0x1000000) == 0) {
      uVar9 = uVar5;
    }
    if ((*(uint *)(lVar1 + 0xc) & 4) != 0) {
      *(uint *)(lVar1 + 0x14) = *(uint *)(lVar1 + 0x14) | uVar4 & 0xfeffffff;
      *(uint *)(lVar1 + 0x10) = ~*(uint *)(lVar1 + 0x14) & uVar4;
      uVar9 = 0;
    }
    if (iVar2 != 0) {
      if (iVar2 == 1) {
        lVar6 = *(longlong *)(lVar6 + 0x48);
      }
      else {
        lVar6 = *(longlong *)(lVar6 + 0x58);
      }
      iVar2 = VfsAccessCheck(lVar6,param_1,uVar9,'\x01');
      if (iVar2 < 0) {
        return iVar2;
      }
      if ((*(uint *)((longlong)param_2 + 0x4c) & 0x10) == 0) {
        local_res18 = 0;
        iVar2 = FltGetInstanceContext(param_2[6]);
        if (iVar2 < 0) {
          puVar8 = (undefined8 *)param_2[6];
          pwVar7 = 
          L"VfsCreateForCreate() - Failed to get instance context for instance: %p\n Status: 0x%08X"
          ;
        }
        else {
          uVar3 = VfsCreateParentDirectories
                            (param_2[3],param_2[6],param_2[2],(ushort *)(param_2 + 7),
                             *(ushort *)(local_res18 + 8));
          FltReleaseContext(local_res18);
          iVar2 = (int)uVar3;
          if (-1 < iVar2) goto LAB_1c0004956;
          puVar8 = param_2 + 7;
          pwVar7 = 
          L"VfsCreateForCreate() - Failed to create parent directories for %wZ\n Status: 0x%08X";
        }
        LogWrite(1,0,pwVar7,puVar8);
        return iVar2;
      }
LAB_1c0004956:
      if (bVar10) {
        iVar2 = IoReplaceFileObjectName
                          (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),param_2[8],
                           *(undefined2 *)(param_2 + 7));
        if (iVar2 < 0) {
          return iVar2;
        }
        *param_3 = 2;
      }
      else {
        uVar5 = *(uint *)((longlong)param_2 + 0x4c);
        iVar2 = VfsCreateShadow(param_1,2,0,0,(uint *)0x0,(uint *)param_2[6],(longlong)(param_2 + 7)
                                ,'\0',(byte)(uVar5 >> 6) & 1,(byte)(uVar5 >> 9) & 1,
                                (byte)(uVar5 >> 0xd) & 1,'\0',*param_2,param_2[1],param_2[2],
                                local_res10);
        if (iVar2 < 0) {
          return iVar2;
        }
        lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 8);
        uVar5 = *(uint *)(lVar6 + 0x10) | *(uint *)(lVar6 + 0x14);
        *(uint *)(lVar6 + 0x14) = uVar5;
        if ((uVar5 >> 0x19 & 1) != 0) {
          *(uint *)(lVar6 + 0x14) = uVar5 & 0xfdffffff | 0x1f01ff;
        }
        *(undefined4 *)(lVar6 + 0x10) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(undefined8 *)(param_1 + 0x20) = 2;
        *param_3 = 3;
      }
      return 0;
    }
  }
  return -0x3fffffde;
}



===== VfsCreateForOpen @ 1c0004a74 =====

ulonglong VfsCreateForOpen(ulonglong param_1,longlong *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  longlong lVar6;
  bool bVar7;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  uVar1 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10);
  *param_3 = 0;
  do {
    bVar7 = false;
    uVar2 = *(uint *)((longlong)param_2 + 0x4c);
    uVar3 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10);
    if ((uVar2 >> 9 & 1) != 0) {
      return 0xc0000034;
    }
    if ((uVar2 & 0xc0) == 0) {
      return 0xc0000034;
    }
    if ((uVar2 & 4) != 0) {
      if ((uVar2 & 0x40) == 0) {
        return 0xc0000034;
      }
LAB_1c0004db7:
      *param_3 = 1;
      return 0;
    }
    if ((uVar2 >> 0xb & 1) == 0) {
      if ((uVar2 >> 8 & 1) == 0) {
        if ((((char)uVar2 < '\0') && ((uVar3 >> 0x10 & 1) == 0)) && (param_2[3] == param_2[6]))
        goto LAB_1c0004d89;
      }
      else if (((uVar2 & 0x40) != 0) && ((uVar3 & 0xd0156) == 0)) goto LAB_1c0004db7;
    }
    if (((uVar2 >> 0xc & 1) != 0) && (-1 < (char)uVar2)) {
      uVar5 = VfsCreateContextNormalize((longlong)param_2);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      uVar5 = VfsCowCopyFile(param_2 + 7,param_1,(ushort *)param_2[3],(ushort *)(param_2 + 4),
                             (ushort *)param_2[6],(ushort *)(param_2 + 7),(undefined4 *)param_2[1],
                             *param_2,~(byte)(*(uint *)((longlong)param_2 + 0x4c) >> 4) & 1,
                             (byte)(*(uint *)((longlong)param_2 + 0x4c) >> 8) & 1);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      uVar2 = *(uint *)((longlong)param_2 + 0x4c);
      *(uint *)((longlong)param_2 + 0x4c) = uVar2 | 0x90;
      if ((uVar2 & 0x900) == 0) {
        if ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0x10000) == 0)
        {
          bVar7 = param_2[3] == param_2[6];
        }
        else {
          bVar7 = false;
        }
      }
    }
    if (bVar7) {
LAB_1c0004d89:
      uVar5 = IoReplaceFileObjectName
                        (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),param_2[8],
                         (short)param_2[7]);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      *param_3 = 2;
      return 0;
    }
    uVar2 = *(uint *)((longlong)param_2 + 0x4c);
    if ((char)uVar2 < '\0') {
      if ((uVar2 & 0x800) == 0) {
        lVar6 = 0;
      }
      else {
        lVar6 = param_2[3];
      }
      iVar4 = VfsCreateShadow(param_1,1,lVar6,
                              -(ulonglong)((uVar2 & 0x800) != 0) & (ulonglong)(param_2 + 4),
                              (uint *)0x0,(uint *)param_2[6],(longlong)(param_2 + 7),'\0',
                              (uVar2 & 0x40) != 0,'\0',(uVar2 & 0x100) != 0,'\0',*param_2,param_2[1]
                              ,param_2[2],local_res8);
      if (iVar4 < 0) {
        return CONCAT44(extraout_var_01,iVar4);
      }
LAB_1c0004d78:
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined8 *)(param_1 + 0x20) = 1;
      *param_3 = 3;
      return 0;
    }
    if (((uVar2 & 4) == 0) && ((uVar1 & 0xd0156) != 0)) {
      lVar6 = param_2[2];
      if ((int)param_2[9] == 0) {
        lVar6 = *(longlong *)(lVar6 + 0x48);
      }
      else if ((uVar2 & 0x100) == 0) {
        lVar6 = *(longlong *)(lVar6 + 0x50);
      }
      else {
        lVar6 = *(longlong *)(lVar6 + 0x58);
      }
      iVar4 = VfsAccessCheck(lVar6,param_1,
                             *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10),
                             '\0');
      if (iVar4 < 0) {
        return CONCAT44(extraout_var,iVar4);
      }
    }
    iVar4 = VfsCreateShadow(param_1,1,0,0,(uint *)param_2[6],(uint *)param_2[3],
                            (longlong)(param_2 + 4),'\x01','\x01','\0',
                            (byte)(*(uint *)((longlong)param_2 + 0x4c) >> 8) & 1,
                            ~(byte)(*(uint *)((longlong)param_2 + 0x4c) >> 2) & 1,*param_2,
                            param_2[1],param_2[2],local_res8);
    if (iVar4 < 0) {
      return CONCAT44(extraout_var_00,iVar4);
    }
    if (local_res8[0] == '\0') goto LAB_1c0004d78;
    *(uint *)((longlong)param_2 + 0x4c) = *(uint *)((longlong)param_2 + 0x4c) | 0x90;
  } while( true );
}



===== VfsCreateForOpenTargetDirectory @ 1c0004de8 =====

int VfsCreateForOpenTargetDirectory(longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  longlong lVar6;
  char local_res8 [16];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  longlong lStack_30;
  
  *param_3 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  local_res8[0] = '\0';
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0xff000000) != 0x1000000) {
    return -0x3ffffff3;
  }
  if ((*(uint *)((longlong)param_2 + 0x4c) & 2) != 0) {
    *param_3 = 1;
    return 0;
  }
  uVar5 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10);
  if ((uVar5 & 0xd0156) != 0) {
    if (*(int *)(param_2 + 9) == 1) {
      lVar6 = *(longlong *)(param_2[2] + 0x48);
    }
    else {
      lVar6 = *(longlong *)(param_2[2] + 0x58);
    }
    iVar2 = VfsAccessCheck(lVar6,param_1,uVar5,'\0');
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  if ((*(uint *)((longlong)param_2 + 0x4c) & 0x10) == 0) {
    local_48 = param_2[4];
    lStack_40 = param_2[5];
    uVar3 = *(ushort *)(param_2 + 4) >> 1;
    if (uVar3 != 0) {
      uVar4 = uVar3 - 1;
      if (*(short *)(lStack_40 + (ulonglong)uVar4 * 2) == 0x5c) {
        if (uVar4 < 2) goto LAB_1c0004ef6;
        uVar4 = uVar3 - 2;
      }
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        if (*(short *)(lStack_40 + (ulonglong)uVar4 * 2) == 0x5c) {
          if ((ushort)(uVar4 + 1) != 0) {
            local_48._2_6_ = (undefined6)((ulonglong)local_48 >> 0x10);
            local_48 = CONCAT62(local_48._2_6_,(uVar4 + 1) * 2);
          }
          break;
        }
      }
    }
LAB_1c0004ef6:
    iVar2 = VfsCreateShadow(param_1,1,0,0,(uint *)param_2[6],(uint *)param_2[3],(longlong)&local_48,
                            '\x01','\x01','\0','\x01','\x01',*param_2,param_2[1],param_2[2],
                            local_res8);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_res8[0] != '\0') {
      *(uint *)((longlong)param_2 + 0x4c) = *(uint *)((longlong)param_2 + 0x4c) | 0x10;
    }
  }
  if ((*(uint *)((longlong)param_2 + 0x4c) & 0x10) == 0) goto LAB_1c00050a8;
  if ((*(uint *)((longlong)param_2 + 0x4c) & 8) != 0) {
    local_48 = param_2[4];
    lStack_40 = param_2[5];
    uVar3 = *(ushort *)(param_2 + 4) >> 1;
    if (uVar3 != 0) {
      uVar4 = uVar3 - 1;
      if (*(short *)(lStack_40 + (ulonglong)uVar4 * 2) == 0x5c) {
        if (uVar4 < 2) goto LAB_1c0004fd0;
        uVar4 = uVar3 - 2;
      }
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        if (*(short *)(lStack_40 + (ulonglong)uVar4 * 2) == 0x5c) {
          if ((ushort)(uVar4 + 1) != 0) {
            local_48._2_6_ = (undefined6)((ulonglong)local_48 >> 0x10);
            local_48 = CONCAT62(local_48._2_6_,(uVar4 + 1) * 2);
          }
          break;
        }
      }
    }
  }
LAB_1c0004fd0:
  local_38 = param_2[7];
  lStack_30 = param_2[8];
  uVar3 = *(ushort *)(param_2 + 7) >> 1;
  if (uVar3 != 0) {
    uVar4 = uVar3 - 1;
    if (*(short *)(lStack_30 + (ulonglong)uVar4 * 2) == 0x5c) {
      if (uVar4 < 2) goto LAB_1c0005022;
      uVar4 = uVar3 - 2;
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (*(short *)(lStack_30 + (ulonglong)uVar4 * 2) == 0x5c) {
        if ((ushort)(uVar4 + 1) != 0) {
          uVar1 = (ulonglong)local_38 >> 0x10;
          local_38 = CONCAT62((int6)uVar1,(uVar4 + 1) * 2);
        }
        break;
      }
    }
  }
LAB_1c0005022:
  uVar5 = *(uint *)((longlong)param_2 + 0x4c) & 8;
  if (uVar5 == 0) {
    lVar6 = 0;
  }
  else {
    lVar6 = param_2[3];
  }
  iVar2 = VfsCreateShadow(param_1,1,lVar6,-(ulonglong)(uVar5 != 0) & (ulonglong)&local_48,
                          (uint *)0x0,(uint *)param_2[6],(longlong)&local_38,'\0',uVar5 != 0,'\0',
                          '\x01','\0',*param_2,param_2[1],param_2[2],local_res8);
  if (iVar2 < 0) {
    return iVar2;
  }
LAB_1c00050a8:
  *(undefined4 *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 0x20) + 0x80) =
       *(undefined4 *)((longlong)param_2 + 0x4c);
  VfsUpdateOpenTargetDirectoryFileName(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8));
  *(undefined8 *)(param_1 + 0x20) = 1;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *param_3 = 3;
  return 0;
}



===== VfsCreateForOverwrite @ 1c0005100 =====

ulonglong VfsCreateForOverwrite(ulonglong param_1,longlong *param_2,undefined4 *param_3)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  uint uVar7;
  longlong lVar8;
  uint uVar9;
  bool bVar10;
  char local_res8 [8];
  uint local_res10;
  uint local_res18;
  
  local_res8[0] = '\0';
  bVar10 = false;
  local_res10 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
  *param_3 = 0;
  uVar2 = *(uint *)((longlong)param_2 + 0x4c);
  if (((uVar2 >> 9 & 1) == 0) && ((uVar2 & 0xc0) != 0)) {
    if ((uVar2 & 4) == 0) {
      if (((uVar2 & 0x800) == 0) &&
         ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0x10000) == 0)) {
        bVar10 = param_2[3] == param_2[6];
      }
      if ((uVar2 & 0x80) == 0) {
        lVar4 = param_2[9];
        lVar8 = param_2[2];
        lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
        uVar2 = *(uint *)(lVar3 + 0x10);
        lVar3 = *(longlong *)(lVar3 + 8);
        uVar7 = (-(uint)(*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) < 0x1000000) & 0xfffe) +
                0x112;
        uVar9 = ~uVar2 & uVar7;
        if ((*(uint *)(lVar3 + 0xc) & 4) != 0) {
          *(uint *)(lVar3 + 0x14) = *(uint *)(lVar3 + 0x14) | uVar9;
        }
        if ((int)lVar4 == 0) {
          lVar8 = *(longlong *)(lVar8 + 0x48);
        }
        else {
          lVar8 = *(longlong *)(lVar8 + 0x50);
        }
        local_res18 = uVar2;
        iVar5 = VfsAccessCheck(lVar8,param_1,uVar2 | uVar9,'\0');
        if ((uVar2 >> 0x19 & 1) == 0) {
          *(uint *)(lVar3 + 0x14) = *(uint *)(lVar3 + 0x14) & (~uVar7 | local_res18);
        }
        if (iVar5 < 0) {
          return CONCAT44(extraout_var,iVar5);
        }
        uVar6 = VfsCreateContextNormalize((longlong)param_2);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        puVar1 = (uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10);
        *puVar1 = *puVar1 | uVar9;
        uVar6 = VfsCowCopyFile(param_2 + 7,param_1,(ushort *)param_2[3],(ushort *)(param_2 + 4),
                               (ushort *)param_2[6],(ushort *)(param_2 + 7),(undefined4 *)param_2[1]
                               ,*param_2,~(byte)(*(uint *)((longlong)param_2 + 0x4c) >> 4) & 1,'\0')
        ;
        puVar1 = (uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10);
        *puVar1 = *puVar1 & ~uVar9;
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar2 = *(uint *)((longlong)param_2 + 0x4c);
        *(uint *)((longlong)param_2 + 0x4c) = uVar2 | 0x90;
        if ((uVar2 & 0x800) == 0) {
          if ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0x10000) == 0
             ) {
            bVar10 = param_2[3] == param_2[6];
          }
          else {
            bVar10 = false;
          }
        }
      }
      uVar2 = local_res10;
      if (bVar10) {
        uVar6 = IoReplaceFileObjectName
                          (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),param_2[8],
                           (short)param_2[7]);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        *param_3 = 2;
      }
      else {
        uVar7 = *(uint *)((longlong)param_2 + 0x4c) & 0x800;
        if (uVar7 == 0) {
          lVar8 = 0;
        }
        else {
          lVar8 = param_2[3];
        }
        iVar5 = VfsCreateShadow(param_1,~-(uint)(local_res10 < 0x1000000) & 4,lVar8,
                                -(ulonglong)(uVar7 != 0) & (ulonglong)(param_2 + 4),(uint *)0x0,
                                (uint *)param_2[6],(longlong)(param_2 + 7),'\0',
                                (*(uint *)((longlong)param_2 + 0x4c) & 0x40) != 0,'\0','\0','\0',
                                *param_2,param_2[1],param_2[2],local_res8);
        if (iVar5 < 0) {
          return CONCAT44(extraout_var_00,iVar5);
        }
        *(undefined4 *)(param_1 + 0x18) = 0;
        *(ulonglong *)(param_1 + 0x20) = (ulonglong)(~-(uint)(uVar2 < 0x1000000) & 3);
        *param_3 = 3;
      }
      uVar6 = 0;
    }
    else {
      uVar6 = (ulonglong)((-(uint)((uVar2 & 0x40) != 0) & 0xffffffee) + 0xc0000034);
    }
  }
  else {
    uVar6 = 0xc0000034;
  }
  return uVar6;
}



===== VfsDeleteCreateCompletionContext @ 1c0005404 =====

void VfsDeleteCreateCompletionContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x80) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x80),0);
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  ExFreeToPagedLookasideList(&DAT_1c001f800,param_1);
  return;
}



===== VfsCtxTableDelete @ 1c0005454 =====

void VfsCtxTableDelete(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (*(longlong *)(param_1 + 0x78) != 0) {
    if ((*(uint *)(param_1 + 0x80) & 1) != 0) {
      ExWaitForRundownProtectionRelease(param_1 + 0x70);
    }
    while( true ) {
      lVar2 = RtlEnumerateGenericTableAvl(param_1,1);
      if (lVar2 == 0) break;
      RtlDeleteElementGenericTableAvl(param_1,lVar2);
    }
    uVar1 = *(undefined8 *)(param_1 + 0x78);
    ExDeleteResourceLite(uVar1);
    ExFreePoolWithTag(uVar1,0x72454656);
    ExRundownCompleted(param_1 + 0x70);
  }
  return;
}



===== VfsCtxTableElementInsert @ 1c00054f8 =====

int VfsCtxTableElementInsert
              (longlong param_1,undefined8 param_2,undefined4 param_3,longlong *param_4)

{
  undefined8 uVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  char local_28 [4];
  int local_24;
  longlong local_20;
  
  local_24 = 0;
  local_20 = 0;
  local_28[0] = '\0';
  if ((*(uint *)(param_1 + 0x80) & 1) == 0) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = ExAcquireRundownProtection(param_1 + 0x70);
  }
  if (cVar3 == '\0') {
    return -0x3fffffff;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x78);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(uVar1,1);
  lVar4 = RtlInsertElementGenericTableAvl(param_1,param_2,param_3,local_28);
  local_20 = lVar4;
  if (lVar4 == 0) {
    local_24 = -0x3fffff66;
  }
  else if (local_28[0] == '\0') {
    local_24 = -0x3fffffcb;
    lVar4 = 0;
    local_20 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x84) == 0) {
      local_24 = VfsPkgCtxInitialize(lVar4);
      if (local_24 < 0) goto LAB_1c000563b;
      *(int *)(lVar4 + 0x20) = *(int *)(lVar4 + 0x20) + 1;
    }
    else {
      local_24 = VfsCtxTableInitialize(lVar4 + 0x60,0,0);
      if (-1 < local_24) {
        *(undefined4 *)(lVar4 + 0x50) = 1;
        *(uint *)(lVar4 + 0x54) = *(uint *)(lVar4 + 0x54) | 1;
        local_24 = 0;
      }
      if (local_24 < 0) goto LAB_1c000563b;
      *(int *)(lVar4 + 0x50) = *(int *)(lVar4 + 0x50) + 1;
    }
    *param_4 = lVar4;
  }
LAB_1c000563b:
  iVar2 = local_24;
  if ((local_24 < 0) && (lVar4 != 0)) {
    RtlDeleteElementGenericTableAvl(param_1,param_2);
  }
  ExReleaseResourceLite(*(undefined8 *)(param_1 + 0x78));
  KeLeaveCriticalRegion();
  if ((*(uint *)(param_1 + 0x80) & 1) != 0) {
    ExReleaseRundownProtection(param_1 + 0x70);
  }
  return iVar2;
}



===== VfsCtxTableElementLookup @ 1c000569c =====

longlong VfsCtxTableElementLookup(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  char cVar2;
  longlong lVar3;
  
  if (((*(uint *)(param_1 + 0x80) & 1) != 0) &&
     (cVar2 = ExAcquireRundownProtection(param_1 + 0x70), cVar2 == '\0')) {
    return 0;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x78);
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(uVar1,1);
  lVar3 = RtlLookupElementGenericTableAvl(param_1,param_2);
  if (lVar3 != 0) {
    if (*(int *)(param_1 + 0x84) == 0) {
      LOCK();
      *(int *)(lVar3 + 0x20) = *(int *)(lVar3 + 0x20) + 1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(lVar3 + 0x50) = *(int *)(lVar3 + 0x50) + 1;
      UNLOCK();
    }
  }
  ExReleaseResourceLite(*(undefined8 *)(param_1 + 0x78));
  KeLeaveCriticalRegion();
  if ((*(uint *)(param_1 + 0x80) & 1) != 0) {
    ExReleaseRundownProtection(param_1 + 0x70);
  }
  return lVar3;
}



===== VfsCtxTableGetContext @ 1c0005774 =====

int VfsCtxTableGetContext
              (longlong param_1,undefined8 param_2,undefined4 param_3,char param_4,longlong *param_5
              )

{
  int iVar1;
  longlong local_18 [2];
  
  local_18[0] = VfsCtxTableElementLookup(param_1,param_2);
  if (local_18[0] == 0) {
    if (param_4 == '\0') {
      return -0x3ffffddb;
    }
    iVar1 = VfsCtxTableElementInsert(param_1,param_2,param_3,local_18);
    if (iVar1 < 0) {
      if (iVar1 != -0x3fffffcb) {
        return iVar1;
      }
      local_18[0] = VfsCtxTableElementLookup(param_1,param_2);
      if (local_18[0] == 0) {
        return -0x3fffffff;
      }
    }
  }
  *param_5 = local_18[0];
  return 0;
}



===== VfsCtxTableInitialize @ 1c0005818 =====

int VfsCtxTableInitialize(longlong param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  code *pcVar4;
  code *pcVar5;
  
  lVar2 = ExAllocatePool2(0x40,0x68,0x72454656);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = ExInitializeResourceLite(lVar2);
    if (-1 < iVar1) {
      *(longlong *)(param_1 + 0x78) = lVar2;
      if (param_2 == 0) {
        pcVar5 = VfsPkgCtxTableElementFree;
        pcVar4 = VfsPkgCtxTableElementAllocate;
        pcVar3 = VfsPkgCtxTableElementCompare;
      }
      else {
        pcVar5 = VfsUserCtxTableElementFree;
        pcVar4 = VfsUserCtxTableElementAllocate;
        pcVar3 = VfsUserCtxTableElementCompare;
      }
      RtlInitializeGenericTableAvl(param_1,pcVar3,pcVar4,pcVar5,0);
      ExInitializeRundownProtection(param_1 + 0x70);
      *(int *)(param_1 + 0x84) = param_2;
      *(undefined4 *)(param_1 + 0x80) = param_3;
      return 0;
    }
    ExFreePoolWithTag(lVar2,0x72454656);
  }
  return iVar1;
}



===== VfsPkgCtxInitialize @ 1c000591c =====

int VfsPkgCtxInitialize(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = param_1 + 0x30;
  *(longlong *)(param_1 + 0x38) = lVar2;
  *(longlong *)lVar2 = lVar2;
  lVar2 = ExAllocatePool2(0x40,0x68,0x72454656);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = ExInitializeResourceLite(lVar2);
    if (-1 < iVar1) {
      *(longlong *)(param_1 + 0x28) = lVar2;
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 1;
      *(undefined4 *)(param_1 + 0x20) = 1;
      return 0;
    }
    ExFreePoolWithTag(lVar2,0x72454656);
  }
  return iVar1;
}



===== VfsPkgCtxRelease @ 1c00059b8 =====

void VfsPkgCtxRelease(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x20);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    plVar2 = (longlong *)(param_1 + 0x28);
    if (*plVar2 != 0) {
      VfsRemoveMappings(plVar2);
      lVar4 = *plVar2;
      ExDeleteResourceLite(lVar4);
      ExFreePoolWithTag(lVar4,0x72454656);
    }
    ExFreeToPagedLookasideList(&DAT_1c001f500,param_1 + -0x20);
  }
  return;
}



===== VfsPkgCtxTableElementAllocate @ 1c0005a40 =====

void * VfsPkgCtxTableElementAllocate(void)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocateFromPagedLookasideList(&DAT_1c001f500);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x60);
  }
  return _Dst;
}



===== VfsPkgCtxTableElementCompare @ 1c0005a80 =====

undefined1 VfsPkgCtxTableElementCompare(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  
  lVar2 = RtlCompareMemory(param_2,param_3,0x20);
  if (lVar2 == 0x20) {
    uVar1 = 2;
  }
  else {
    uVar1 = *(byte *)(lVar2 + param_3) <= *(byte *)(lVar2 + param_2);
  }
  return uVar1;
}



===== VfsPkgCtxTableElementFree @ 1c0005ae0 =====

void VfsPkgCtxTableElementFree(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x44) & 1) == 0) {
    ExFreeToPagedLookasideList(&DAT_1c001f500);
  }
  else {
    VfsPkgCtxRelease(param_2 + 0x20);
  }
  return;
}



===== VfsUserCtxRelease @ 1c0005b18 =====

void VfsUserCtxRelease(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x50);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    VfsCtxTableDelete(param_1 + 0x60);
    ExFreeToPagedLookasideList(&DAT_1c001f580,param_1 + -0x20);
  }
  return;
}



===== VfsUserCtxTableElementAllocate @ 1c0005b60 =====

void * VfsUserCtxTableElementAllocate(void)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocateFromPagedLookasideList(&DAT_1c001f580);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x110);
  }
  return _Dst;
}



===== VfsUserCtxTableElementCompare @ 1c0005bb0 =====

undefined1 VfsUserCtxTableElementCompare(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  
  uVar1 = RtlLengthSid(param_2);
  uVar2 = RtlLengthSid(param_3);
  if (uVar1 < uVar2) {
    uVar4 = 0;
  }
  else if (uVar2 < uVar1) {
    uVar4 = 1;
  }
  else {
    uVar3 = RtlCompareMemory(param_2,param_3,(ulonglong)uVar1);
    if (uVar3 == uVar1) {
      uVar4 = 2;
    }
    else {
      uVar4 = *(byte *)(uVar3 + param_3) <= *(byte *)(uVar3 + param_2);
    }
  }
  return uVar4;
}



===== VfsUserCtxTableElementFree @ 1c0005c40 =====

void VfsUserCtxTableElementFree(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x74) & 1) == 0) {
    ExFreeToPagedLookasideList(&DAT_1c001f580);
  }
  else {
    VfsUserCtxRelease(param_2 + 0x20);
  }
  return;
}



===== VfsMarkPackageFileDeleted @ 1c0005c78 =====

ulonglong VfsMarkPackageFileDeleted(longlong param_1,ushort *param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong local_res20;
  ushort local_18 [4];
  longlong lStack_10;
  
  local_res20 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  lStack_10 = 0;
  uVar2 = VfsGetMappedTarget(param_1,param_2,'\0',param_3,(undefined8 *)local_18,&local_res20);
  lVar1 = local_res20;
  if ((int)uVar2 < 0) {
    LogWrite(1,0,
             L"VfsMarkPackageFileDeleted() - Failed to map filename: %wZ\n for mapping: %wZ\n Status: 0x%08X"
             ,param_2);
  }
  else {
    lVar3 = local_res20;
    uVar2 = VfsCreateParentDirectories
                      (param_1,local_res20,param_3,local_18,*(ushort *)(param_3 + 0x18));
    if ((int)uVar2 < 0) {
      LogWrite(1,0,
               L"VfsMarkPackageFileDeleted() - Failed to create parent directories for %wZ\n Status: 0x%08X"
               ,local_18);
    }
    else {
      uVar2 = VfsMarkFileDeleted(lVar1,lVar3,local_18,'\0','\x01');
    }
    FltObjectDereference(lVar1);
    if (lStack_10 != 0) {
      ExFreePoolWithTag(lStack_10,0);
    }
  }
  return uVar2 & 0xffffffff;
}



===== VfsProcessDelete @ 1c0005d8c =====

undefined8 VfsProcessDelete(uint *param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong local_res8;
  longlong local_res18;
  
  uVar5 = 0;
  local_res8 = 0;
  local_res18 = 0;
  bVar2 = **(byte **)(*(longlong *)(param_1 + 4) + 0x38);
  cVar4 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),&local_res8,&local_res18);
  lVar3 = local_res8;
  if (cVar4 == '\0') {
    return 1;
  }
  if (bVar2 != ((byte)(*(uint *)(local_res8 + 0x110) >> 3) & 1)) {
    if ((*(uint *)(local_res8 + 0x110) & 2) == 0) {
      uVar6 = VfsProcessDeleteFile(param_1,local_res8,local_res18);
      uVar5 = (uint)uVar6;
    }
    else if ((*(uint *)(local_res18 + 4) & 4) == 0) {
      uVar6 = VfsProcessDeleteStoreDirectory(param_1,local_res8,local_res18);
      uVar5 = (uint)uVar6;
    }
    else {
      uVar6 = VfsProcessDeletePackageDirectory(param_1,local_res8,local_res18);
      uVar5 = (uint)uVar6;
    }
    if ((int)uVar5 < 0) goto LAB_1c0005e44;
  }
  *(bool *)(*(longlong *)(param_2 + 0x20) + 0x49) = bVar2 != 0;
  if (bVar2 == 0) {
    LOCK();
    puVar1 = (uint *)(lVar3 + 0x110);
    *puVar1 = *puVar1 & 0xfffffff7;
    UNLOCK();
  }
  else {
    LOCK();
    puVar1 = (uint *)(lVar3 + 0x110);
    *puVar1 = *puVar1 | 8;
    UNLOCK();
  }
LAB_1c0005e44:
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = uVar5;
  return 4;
}



===== VfsProcessDeleteFile @ 1c0005e6c =====

ulonglong VfsProcessDeleteFile(uint *param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 local_res8 [8];
  
  uVar1 = **(undefined1 **)(*(longlong *)(param_1 + 4) + 0x38);
  if ((*(uint *)(param_3 + 4) & 4) != 0) {
    uVar3 = VfsDelayedCopy(param_1,param_2,param_3);
    if ((int)uVar3 < 0) {
      LogWrite(1,0,L"VfsProcessDeleteFile() - Failed to delay copy file. Status: 0x%08X",
               uVar3 & 0xffffffff);
      return uVar3 & 0xffffffff;
    }
  }
  local_res8[0] = uVar1;
  uVar2 = FltSetInformationFile
                    (*(undefined8 *)(param_3 + 0x40),*(undefined8 *)(param_3 + 0x48),local_res8,1,
                     0xd);
  return (ulonglong)uVar2;
}



===== VfsProcessDeleteOnCleanupShadow @ 1c0005f00 =====

ulonglong VfsProcessDeleteOnCleanupShadow(uint *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  bool bVar7;
  longlong local_res10;
  char local_res18 [8];
  uint local_res20;
  longlong local_30;
  
  local_30 = 0;
  if (((*(uint *)(param_3 + 4) & 0x40) == 0) || ((*(uint *)(param_2 + 0x110) & 8) != 0))
  goto LAB_1c0005fc2;
  bVar7 = false;
  if ((*(uint *)(param_2 + 0x110) & 2) == 0) {
    local_res10 = CONCAT71(local_res10._1_7_,1);
    FltSetInformationFile
              (*(undefined8 *)(param_3 + 0x40),*(undefined8 *)(param_3 + 0x48),&local_res10,1,0xd);
LAB_1c0005faa:
    bVar7 = true;
  }
  else {
    local_res10 = (ulonglong)local_res10._1_7_ << 8;
    uVar2 = VfsCheckDirectoryEmpty(param_1,param_3,'\0',(undefined1 *)&local_res10);
    if ((int)uVar2 < 0) {
      LogWrite(1,0,L"VfsMoveDeleteoncloseToScb() - Failed to check directory empty. Status: 0x%08X",
               uVar2 & 0xffffffff);
    }
    else if ((char)local_res10 != '\0') goto LAB_1c0005faa;
  }
  if (bVar7) {
    LOCK();
    *(uint *)(param_2 + 0x110) = *(uint *)(param_2 + 0x110) | 8;
    UNLOCK();
  }
LAB_1c0005fc2:
  if ((*(int *)(param_2 + 0x118) == 0) && (((byte)*(undefined4 *)(param_2 + 0x110) & 0xc) == 0xc)) {
    if (*(longlong *)(param_3 + 0x50) == 0) {
      uVar2 = 0xc00000e5;
    }
    else {
      bVar7 = false;
      local_res18[0] = '\0';
      lVar5 = *(longlong *)(param_3 + 0x48);
      uVar2 = VfsGetFileNameInfoForFileObject
                        (param_1,lVar5,*(undefined8 *)(param_3 + 0x40),0x101,&local_30);
      local_res20 = (uint)uVar2;
      uVar2 = uVar2 & 0xffffffff;
      if ((int)local_res20 < 0) {
        LogWrite(1,0,
                 L"VfsProcessDeleteOnCleanupShadow() - Failed to get filename info for fileobject: %p\n IRP: %d\n Status: 0x%08X"
                 ,*(undefined8 *)(param_3 + 0x48));
      }
      else {
        FltClose(*(undefined8 *)(param_3 + 0x50));
        *(undefined8 *)(param_3 + 0x50) = 0;
        if ((*(uint *)(param_2 + 0x110) & 2) == 0) {
          uVar6 = *(undefined8 *)(param_3 + 0x48);
          VfsCheckFileDeleted(*(undefined8 *)(param_3 + 0x40),uVar6,local_res18);
          if (local_res18[0] == '\0') {
            bVar7 = true;
          }
          else {
            VfsMarkFileDeleted(*(undefined8 *)(param_3 + 0x40),uVar6,local_30 + 8,'\0','\x01');
          }
        }
        else {
          uVar3 = VfsMarkFileDeleted(*(undefined8 *)(param_3 + 0x40),lVar5,local_30 + 8,'\x01',
                                     '\x01');
          bVar7 = (int)uVar3 < 0;
        }
        if (bVar7) {
          uVar1 = *(uint *)(*(longlong *)(param_3 + 0x18) + 0x110);
          if ((uVar1 & 1) == 0) {
            puVar4 = (uint *)(*(longlong *)(*(longlong *)(param_3 + 0x18) + 0x80) + 4);
            LOCK();
            *puVar4 = *puVar4 | 4;
            UNLOCK();
          }
          else {
            local_res10 = 0;
            uVar2 = VfsGetStreamContext(*(undefined8 *)(param_3 + 0x40),
                                        *(undefined8 *)(param_3 + 0x48),uVar1 & 2,&local_res10);
            LOCK();
            *(uint *)(local_res10 + 4) = *(uint *)(local_res10 + 4) | 4;
            UNLOCK();
            if ((int)uVar2 < 0) {
              LogWrite(1,0,
                       L"VfsDelayMarkFileDeleted() - Failed to get stream context for fileobject: %p\n Status: 0x%08X"
                       ,*(undefined8 *)(param_3 + 0x48));
            }
            else {
              FltReleaseContext(local_res10);
            }
          }
          uVar2 = (ulonglong)local_res20;
        }
      }
      if (local_30 != 0) {
        FltReleaseFileNameInformation();
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== VfsProcessDeletePackageDirectory @ 1c000619c =====

ulonglong VfsProcessDeletePackageDirectory(uint *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  char local_res8 [8];
  
  if (**(char **)(*(longlong *)(param_1 + 4) + 0x38) == '\0') {
    return 0;
  }
  local_res8[0] = '\0';
  uVar2 = VfsCheckDirectoryEmpty(param_1,param_3,'\x01',local_res8);
  uVar1 = (uint)uVar2;
  uVar2 = uVar2 & 0xffffffff;
  if ((int)uVar1 < 0) {
    pwVar3 = L"VfsProcessDeletePackageDirectory() - Failed to check directory empty. Status: 0x%08X"
    ;
  }
  else {
    if (local_res8[0] == '\0') {
      return 0xc0000101;
    }
    uVar2 = VfsDelayedCopy(param_1,param_2,param_3);
    uVar1 = (uint)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar1) {
      return uVar2;
    }
    pwVar3 = L"VfsProcessDeletePackageDirectory() - Failed to delay copy file. Status: 0x%08X";
  }
  LogWrite(1,0,pwVar3,(ulonglong)uVar1);
  return uVar2;
}



===== VfsProcessDeleteStoreDirectory @ 1c0006258 =====

ulonglong VfsProcessDeleteStoreDirectory(uint *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char local_res8 [24];
  char local_res20 [8];
  
  uVar3 = 0;
  local_res8[0] = **(char **)(*(longlong *)(param_1 + 4) + 0x38);
  if ((*(uint *)(param_2 + 0x110) & 4) == 0) {
    uVar1 = FltSetInformationFile
                      (*(undefined8 *)(param_3 + 0x40),*(undefined8 *)(param_3 + 0x48),local_res8,1,
                       0xd);
    uVar3 = (ulonglong)uVar1;
  }
  else if (local_res8[0] != '\0') {
    local_res20[0] = '\0';
    uVar2 = VfsCheckDirectoryEmpty(param_1,param_3,'\0',local_res20);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      LogWrite(1,0,
               L"VfsProcessDeleteStoreDirectory() - Failed to check directory empty. Status: 0x%08X"
               ,uVar2 & 0xffffffff);
    }
    else if (local_res20[0] == '\0') {
      uVar3 = 0xc0000101;
    }
  }
  return uVar3;
}



===== VfsCheckDirectoryEmpty @ 1c0006308 =====

ulonglong VfsCheckDirectoryEmpty(uint *param_1,longlong param_2,char param_3,undefined1 *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong local_res20;
  longlong local_60;
  int *local_58;
  longlong local_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res20 = 0;
  piVar3 = (int *)0x0;
  local_58 = (int *)0x0;
  local_48 = 0;
  lStack_40 = 0;
  local_60 = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar7 = 0;
  *param_4 = 0;
  if ((param_3 == '\0') && ((*(uint *)(param_2 + 4) >> 2 & 1) == 0)) {
    uVar6 = 0x101;
    uVar2 = VfsGetFileNameInfoForFileObject
                      (param_1,*(longlong *)(param_2 + 0x48),*(undefined8 *)(param_2 + 0x40),0x101,
                       &local_res20);
    lVar4 = local_res20;
    uVar5 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      local_38 = *(undefined8 *)(local_res20 + 8);
      uStack_30 = *(undefined8 *)(local_res20 + 0x10);
      lVar7 = *(longlong *)(param_2 + 0x40);
      local_50 = lVar7;
      piVar3 = VfsScbGetMapping(*(longlong *)(param_2 + 0x18));
      local_58 = piVar3;
      if (piVar3 == (int *)0x0) goto LAB_1c00064c7;
      if ((*(uint *)(*(longlong *)(param_2 + 0x18) + 0x110) & 4) != 0) {
        uVar2 = VfsGetUnMappedSource
                          (*(longlong *)(param_2 + 0x40),(short *)(lVar4 + 8),(longlong)piVar3,uVar6
                           ,&local_48,&local_60);
        uVar5 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) goto LAB_1c00064c7;
      }
LAB_1c000648d:
      uVar1 = VfsQueryDirectoryEmpty
                        (local_60,-(ulonglong)(local_60 != 0) & (ulonglong)&local_48,lVar7,
                         -(ulonglong)(lVar7 != 0) & (ulonglong)&local_38,param_4);
      uVar5 = (ulonglong)uVar1;
      goto LAB_1c00064c7;
    }
  }
  else {
    uVar2 = VfsGetFileNameInfoForFileObject
                      (param_1,*(longlong *)(param_2 + 0x30),*(undefined8 *)(param_2 + 0x28),0x102,
                       &local_res20);
    uVar5 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      local_60 = *(longlong *)(param_2 + 0x28);
      local_48 = *(undefined8 *)(local_res20 + 8);
      lStack_40 = *(longlong *)(local_res20 + 0x10);
      lVar4 = local_res20;
      goto LAB_1c000648d;
    }
  }
  LogWrite(1,0,
           L"VfsCheckDirectoryEmpty() - Failed to get filename info for fileobject: %p\n IRP: %d\n Status: 0x%08X"
           ,*(undefined8 *)(param_2 + 0x48));
  lVar4 = local_res20;
LAB_1c00064c7:
  if (lVar4 != 0) {
    FltReleaseFileNameInformation(lVar4);
  }
  if (piVar3 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar3);
    if (lStack_40 != 0) {
      ExFreePoolWithTag(lStack_40,0);
      lStack_40 = 0;
    }
    if (local_60 != 0) {
      FltObjectDereference();
    }
  }
  return uVar5;
}



===== VfsGetDirQueryRecordInformation @ 1c0006540 =====

void VfsGetDirQueryRecordInformation
               (int param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
               ushort *param_7)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 == 1) {
    iVar4 = 0x40;
    *param_3 = *param_2;
    *param_5 = param_2[0xe];
    *param_6 = -1;
    piVar3 = param_2 + 0x10;
LAB_1c000665a:
    *(int **)(param_7 + 4) = piVar3;
    uVar1 = *(ushort *)(param_2 + 0xf);
  }
  else {
    if (param_1 == 2) {
      iVar4 = 0x44;
      *param_3 = *param_2;
      *param_5 = param_2[0xe];
      *param_6 = param_2[0x10];
      piVar3 = param_2 + 0x11;
      goto LAB_1c000665a;
    }
    if (param_1 == 3) {
      iVar4 = 0x5e;
      *param_3 = *param_2;
      *param_5 = param_2[0xe];
      *param_6 = param_2[0x10];
      piVar3 = (int *)((longlong)param_2 + 0x5e);
      goto LAB_1c000665a;
    }
    if (param_1 != 0xc) {
      if (param_1 == 0x25) {
        iVar4 = 0x68;
        *param_3 = *param_2;
        *param_5 = param_2[0xe];
        *param_6 = param_2[0x10];
        piVar3 = param_2 + 0x1a;
      }
      else {
        if (param_1 != 0x26) goto LAB_1c000666b;
        iVar4 = 0x50;
        *param_3 = *param_2;
        *param_5 = param_2[0xe];
        *param_6 = param_2[0x10];
        piVar3 = param_2 + 0x14;
      }
      goto LAB_1c000665a;
    }
    iVar4 = 0xc;
    *param_3 = *param_2;
    *param_5 = -1;
    *param_6 = -1;
    *(int **)(param_7 + 4) = param_2 + 3;
    uVar1 = *(ushort *)(param_2 + 2);
  }
  param_7[1] = uVar1;
  *param_7 = uVar1;
LAB_1c000666b:
  iVar2 = *param_3;
  if (iVar2 == 0) {
    iVar2 = (uint)*param_7 + iVar4;
  }
  *param_4 = iVar2;
  return;
}



===== VfsMergeDirectory @ 1c0006684 =====

uint VfsMergeDirectory(longlong param_1,uint *param_2,longlong param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *_Dst;
  byte local_67;
  uint local_64;
  uint local_60;
  uint local_5c;
  void *local_58;
  longlong local_50;
  uint *local_48;
  
  local_48 = (uint *)0x0;
  local_60 = 0;
  local_67 = *(byte *)(*(longlong *)(param_1 + 0x10) + 6);
  bVar1 = local_67 & 2;
  local_67 = local_67 & 1;
  do {
    _Dst = local_48;
    uVar4 = local_60;
    local_58 = (void *)0x0;
    local_64 = 0;
    local_5c = 0;
    local_50 = 0;
    uVar2 = VfsQueryDirectoryRecord
                      (param_2,bVar1 != 0,local_67,&local_58,&local_64,&local_5c,&local_50);
    local_67 = 0;
    if (uVar2 == 0xc000000f) {
LAB_1c00067f8:
      if (-1 < (int)uVar2) {
        if (_Dst != (uint *)0x0) {
          *_Dst = 0;
        }
        if (-1 < (int)uVar2) {
          *(uint *)(param_1 + 0x18) = uVar2;
          *(ulonglong *)(param_1 + 0x20) = (ulonglong)uVar4;
        }
      }
      *param_2 = *param_2 & 0xfffffffe;
      LOCK();
      param_2[1] = 0;
      UNLOCK();
      return uVar2;
    }
    if (uVar2 == 0x80000006) {
      if (uVar4 == 0) {
        if ((*param_2 & 1) != 0) {
          uVar2 = 0xc000000f;
        }
      }
      else {
        uVar2 = 0;
      }
      goto LAB_1c00067f8;
    }
    if ((int)uVar2 < 0) goto LAB_1c00067f8;
    uVar3 = local_64 + 7 & 0xfffffff8;
    if (param_4 - uVar4 < uVar3) {
      if (uVar4 == 0) {
        uVar2 = 0x80000005;
      }
      goto LAB_1c00067f8;
    }
    _Dst = (uint *)((ulonglong)uVar4 + param_3);
    memcpy(_Dst,local_58,(ulonglong)local_64);
    *_Dst = uVar3;
    uVar4 = uVar4 + uVar3;
    if (local_5c == 0) {
      *(undefined8 *)(local_50 + 0x3c) = 0;
    }
    else {
      *(int *)(local_50 + 0x3c) = *(int *)(local_50 + 0x3c) - local_64;
      *(int *)(local_50 + 0x40) = *(int *)(local_50 + 0x40) + local_64;
    }
    if (bVar1 != 0) goto LAB_1c00067f8;
    local_60 = uVar4;
    local_48 = _Dst;
  } while( true );
}



===== VfsPrepareMergeDirectory @ 1c0006850 =====

int VfsPrepareMergeDirectory
              (longlong param_1,short *param_2,undefined8 *param_3,longlong *param_4,
              undefined4 *param_5,undefined1 *param_6)

{
  undefined4 uVar1;
  longlong lVar2;
  bool bVar3;
  uint *puVar4;
  longlong *plVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  bool bVar10;
  int local_44;
  uint *local_38;
  longlong *local_30;
  
  local_38 = (uint *)0x0;
  local_30 = (longlong *)0x0;
  bVar3 = false;
  *param_5 = 0;
  *param_6 = 0;
  if (*param_2 == 0x1688) {
    local_30 = (longlong *)(param_2 + 0x48);
LAB_1c00068dd:
    local_38 = (uint *)*local_30;
    local_44 = 0;
  }
  else {
    if ((*(uint *)(*(longlong *)(param_2 + 0xc) + 0x110) & 2) == 0) {
      local_44 = -0x3ffffff3;
      goto LAB_1c0006a9c;
    }
    if (((*(uint *)(param_2 + 2) & 4) != 0) || (local_44 = *(int *)(param_2 + 0x10), -1 < local_44))
    {
      local_30 = (longlong *)(param_2 + 0x3c);
      goto LAB_1c00068dd;
    }
  }
  plVar5 = local_30;
  if (local_44 < 0) goto LAB_1c0006a9c;
  lVar6 = *(longlong *)(param_1 + 0x10);
  uVar9 = (ulonglong)(int)*(uint *)(lVar6 + 0x28);
  if ((0x26 < *(uint *)(lVar6 + 0x28)) || ((0x600000100eU >> (uVar9 & 0x3f) & 1) == 0)) {
    LogWrite(1,0,L"VfsValidateDirQueryParameters() - Invalid directory query inforamtion class: %d",
             uVar9);
    local_44 = -0x3ffffffd;
    goto LAB_1c0006a9c;
  }
  if ((*(byte *)(lVar6 + 6) & 4) != 0) {
    LogWrite(1,0,L"VfsValidateDirQueryParameters() - Directory query index is not supported",uVar9);
    local_44 = -0x3fffff45;
    goto LAB_1c0006a9c;
  }
  lVar2 = *(longlong *)(lVar6 + 0x40);
  if (lVar2 == 0) {
    lVar6 = *(longlong *)(lVar6 + 0x38);
LAB_1c0006998:
    uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x18);
    if (local_38 == (uint *)0x0) {
      uVar7 = VfsCreateDirQueryContext(param_1,param_2,&local_38,uVar9);
      local_44 = (int)uVar7;
      if (local_44 < 0) {
        LogWrite(1,0,L"VfsPrepareMergeDirectory() - Failed to create directory query context",uVar9)
        ;
        goto LAB_1c0006a9c;
      }
      LOCK();
      bVar10 = *plVar5 == 0;
      if (bVar10) {
        *plVar5 = (longlong)local_38;
      }
      UNLOCK();
      if (bVar10) goto LAB_1c0006a0f;
      VfsDeleteDirQueryContext((longlong)local_38);
      local_38 = (uint *)0x0;
    }
    else {
LAB_1c0006a0f:
      puVar4 = local_38;
      if (local_38[7] < 2) {
        *param_6 = 1;
        local_44 = 0;
        goto LAB_1c0006a9c;
      }
      LOCK();
      bVar10 = local_38[1] == 0;
      if (bVar10) {
        local_38[1] = 1;
      }
      UNLOCK();
      if (bVar10) {
        bVar3 = true;
        uVar8 = VfsUpdateDirQueryContext(param_1,local_38);
        local_44 = (int)uVar8;
        if (-1 < local_44) {
          *param_3 = puVar4;
          *param_4 = lVar6;
          *param_5 = uVar1;
        }
        goto LAB_1c0006a9c;
      }
    }
    LogWrite(1,0,
             L"VfsPrepareMergeDirectory() - Multi async directory queries on the same directory are not supported"
             ,uVar9);
  }
  else {
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      uVar9 = 0;
      lVar6 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x10);
    }
    else {
      lVar6 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar6 != 0) goto LAB_1c0006998;
  }
  local_44 = -0x3fffff66;
LAB_1c0006a9c:
  if ((local_44 < 0) && (bVar3)) {
    LOCK();
    local_38[1] = 0;
    UNLOCK();
  }
  return local_44;
}



===== VfsQueryDirectory @ 1c0006ad8 =====

undefined8 VfsQueryDirectory(longlong param_1,ulonglong param_2,short *param_3,ulonglong param_4)

{
  uint uVar1;
  ulonglong local_res10;
  ulonglong local_res20;
  longlong local_18;
  uint *local_10;
  
  local_10 = (uint *)0x0;
  local_18 = 0;
  local_res10 = param_2 & 0xffffffff00000000;
  local_res20 = param_4 & 0xffffffffffffff00;
  uVar1 = VfsPrepareMergeDirectory
                    (param_1,param_3,&local_10,&local_18,(undefined4 *)&local_res10,
                     (undefined1 *)&local_res20);
  if (-1 < (int)uVar1) {
    if ((char)local_res20 == '\0') {
      uVar1 = VfsMergeDirectory(param_1,local_10,local_18,(int)local_res10);
      if (-1 < (int)uVar1) {
        return 4;
      }
    }
    else if ((*param_3 != 0x1687) ||
            (uVar1 = VfsRedirectIo(param_1,(longlong)param_3), -1 < (int)uVar1)) {
      return 1;
    }
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(uint *)(param_1 + 0x18) = uVar1;
  return 4;
}



===== VfsQueryDirectoryEmpty @ 1c0006b94 =====

uint VfsQueryDirectoryEmpty
               (longlong param_1,longlong param_2,longlong param_3,longlong param_4,
               undefined1 *param_5)

{
  undefined1 *puVar1;
  bool bVar2;
  bool bVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint local_res8 [2];
  undefined8 in_stack_ffffffffffffff80;
  longlong local_60;
  longlong local_58;
  short local_50;
  short local_4e;
  short *local_48;
  uint local_40 [14];
  
  puVar4 = param_5;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  local_40[5] = 0;
  local_40[6] = 0;
  local_40[7] = 0;
  local_40[8] = 0;
  local_40[9] = 0;
  local_40[10] = 0;
  local_40[0xb] = 0;
  local_40[0xc] = 0;
  local_40[0xd] = 0;
  bVar3 = false;
  *param_5 = 0;
  if (((param_1 == 0) || (param_2 == 0)) && ((param_3 == 0 || (param_4 == 0)))) {
    uVar5 = 0xc000000d;
  }
  else {
    uVar5 = VfsCreateDirQueryContextLocal
                      (param_1,param_2,param_3,param_4,0x6d8,in_stack_ffffffffffffff80,local_40);
    puVar1 = param_5;
    if (-1 < (int)uVar5) {
      bVar3 = true;
      while( true ) {
        local_60 = 0;
        local_res8[0] = 0;
        param_5._0_4_ = 0;
        local_58 = 0;
        uVar5 = VfsQueryDirectoryRecord
                          (local_40,1,0,&local_60,local_res8,(uint *)&param_5,&local_58);
        puVar1 = (undefined1 *)CONCAT44(param_5._4_4_,(int)param_5);
        if ((uVar5 == 0xc000000f) || (uVar5 == 0x80000006)) break;
        puVar1 = (undefined1 *)CONCAT44(param_5._4_4_,(int)param_5);
        if ((int)uVar5 < 0) goto LAB_1c0006d17;
        local_48 = (short *)(local_60 + 0x44);
        local_50 = *(short *)(local_60 + 0x3c);
        if (((local_50 == 2) && (*local_48 == 0x2e)) ||
           ((local_50 == 4 && ((*local_48 == 0x2e && (*(short *)(local_60 + 0x46) == 0x2e)))))) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        local_4e = local_50;
        puVar1 = (undefined1 *)CONCAT44(param_5._4_4_,(int)param_5);
        if (!bVar2) goto LAB_1c0006d17;
        if ((int)param_5 == 0) {
          *(undefined4 *)(local_58 + 0x3c) = 0;
          *(undefined4 *)(local_58 + 0x40) = 0;
        }
        else {
          *(uint *)(local_58 + 0x3c) = *(int *)(local_58 + 0x3c) - local_res8[0];
          *(uint *)(local_58 + 0x40) = local_res8[0] + *(int *)(local_58 + 0x40);
        }
      }
      *puVar4 = 1;
      uVar5 = 0;
    }
LAB_1c0006d17:
    if (bVar3) {
      param_5 = puVar1;
      VfsCleanupDirQueryContext((longlong)local_40);
    }
  }
  return uVar5;
}



===== VfsQueryDirectoryRecord @ 1c0006d4c =====

uint VfsQueryDirectoryRecord
               (uint *param_1,undefined1 param_2,undefined1 param_3,undefined8 *param_4,
               uint *param_5,uint *param_6,longlong *param_7)

{
  uint *puVar1;
  short sVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  ulonglong uVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_58 [2];
  undefined8 local_50;
  undefined8 local_48 [2];
  
  puVar1 = param_1 + 2;
  puVar12 = (uint *)0x0;
  for (puVar9 = *(uint **)puVar1; puVar9 != puVar1; puVar9 = *(uint **)puVar9) {
    *(undefined1 *)(puVar9 + 0x1d) = param_3;
  }
LAB_1c0006d87:
  puVar9 = (uint *)0x0;
  uVar14 = 0;
  uVar13 = 0;
  iVar8 = 0;
  for (puVar11 = *(uint **)puVar1; puVar11 != puVar1; puVar11 = *(uint **)puVar11) {
LAB_1c0006dad:
    lVar4 = *(longlong *)(param_1 + 0xc);
    uVar3 = param_1[8];
    puVar11[0x14] = 0;
    puVar11[0x15] = 0;
    puVar11[0x16] = 0;
    puVar11[0x17] = 0;
    puVar11[0x1a] = 0;
    puVar11[0x1b] = 0;
    if ((char)puVar11[0x1d] == '\0') {
      if ((puVar11[0x11] & 2) == 0) goto LAB_1c0006dfe;
      uVar7 = (-(uint)((puVar11[0x11] & 1) != 0) & 0xbffffff7) + 0xc000000f;
    }
    else {
      puVar11[0xf] = 0;
      puVar11[0x10] = 0;
      puVar11[0x11] = 0;
LAB_1c0006dfe:
      if (puVar11[0xf] == 0) {
        local_58[0] = 0;
        uVar7 = FltQueryDirectoryFile
                          (*(undefined8 *)(puVar11 + 6),*(undefined8 *)(puVar11 + 8),
                           *(undefined8 *)(puVar11 + 0xc),puVar11[0xe],uVar3,param_2,
                           -(ulonglong)(lVar4 != 0) & (ulonglong)(param_1 + 10),(char)puVar11[0x1d],
                           local_58);
        if ((uVar7 == 0xc000000f) || (uVar7 == 0x80000006)) {
          puVar11[0x11] = puVar11[0x11] | 2;
        }
        else if (-1 < (int)uVar7) {
          puVar11[0x11] = puVar11[0x11] | 1;
          puVar11[0x10] = 0;
          puVar11[0xf] = local_58[0];
          goto LAB_1c0006e7a;
        }
      }
      else {
LAB_1c0006e7a:
        *(int **)(puVar11 + 0x12) = (int *)((ulonglong)puVar11[0x10] + *(longlong *)(puVar11 + 0xc))
        ;
        VfsGetDirQueryRecordInformation
                  (uVar3,(int *)((ulonglong)puVar11[0x10] + *(longlong *)(puVar11 + 0xc)),
                   (int *)(puVar11 + 0x15),(int *)(puVar11 + 0x14),(int *)(puVar11 + 0x16),
                   (int *)(puVar11 + 0x17),(ushort *)(puVar11 + 0x18));
        uVar7 = 0;
      }
    }
    puVar11[0x1c] = uVar7;
    *(undefined1 *)(puVar11 + 0x1d) = 0;
    if (uVar7 != 0xc000000f) {
      if (uVar7 == 0x80000006) {
        iVar8 = iVar8 + 1;
        goto LAB_1c0006f5b;
      }
      if ((int)uVar7 < 0) {
        LogWrite(1,0,
                 L"VfsQueryDirectoryRecord() - Failed to query directory namespace for fileobject: %p\n InfoClass: %d\n Status: 0x%08X"
                 ,*(undefined8 *)(puVar11 + 8));
        return puVar11[0x1c];
      }
      if ((*param_1 & 2) == 0) goto LAB_1c0006f5b;
      if ((short)puVar11[0x18] == 2) {
        sVar2 = **(short **)(puVar11 + 0x1a);
      }
      else {
        if (((short)puVar11[0x18] != 4) || (**(short **)(puVar11 + 0x1a) != 0x2e))
        goto LAB_1c0006f5b;
        sVar2 = (*(short **)(puVar11 + 0x1a))[1];
      }
      if (sVar2 != 0x2e) goto LAB_1c0006f5b;
      if (puVar11[0x15] == 0) {
        puVar11[0xf] = 0;
        puVar11[0x10] = 0;
      }
      else {
        puVar11[0xf] = puVar11[0xf] - puVar11[0x14];
        puVar11[0x10] = puVar11[0x10] + puVar11[0x14];
      }
      goto LAB_1c0006dad;
    }
    uVar13 = uVar13 + 1;
LAB_1c0006f5b:
  }
  if (uVar13 == param_1[7]) {
    return 0xc000000f;
  }
  if (iVar8 + uVar13 == param_1[7]) {
    return 0x80000006;
  }
  puVar11 = *(uint **)puVar1;
  if (puVar11 != puVar1) {
    do {
      if (*(longlong *)(puVar11 + 0x1a) != 0) {
        if (puVar9 == (uint *)0x0) {
          puVar9 = puVar11 + 0x12;
          uVar14 = 1;
          puVar12 = puVar11;
        }
        else {
          iVar8 = RtlCompareUnicodeString(puVar9 + 6,puVar11 + 0x18,1);
          if (iVar8 < 1) {
            if (iVar8 == 0) {
              uVar14 = uVar14 + 1;
            }
          }
          else {
            puVar9 = puVar11 + 0x12;
            puVar12 = puVar11;
          }
        }
      }
      puVar11 = *(uint **)puVar11;
    } while (puVar11 != puVar1);
    if (puVar9 != (uint *)0x0) {
      uVar13 = 0;
      puVar11 = puVar12;
      if (puVar12 == puVar1) {
LAB_1c000719f:
        uVar13 = 0;
        goto LAB_1c00071dc;
      }
      do {
        if (uVar14 <= uVar13) goto LAB_1c000719f;
        if (((*(longlong *)(puVar11 + 0x1a) != 0) &&
            (((puVar11 + 0x12 == puVar9 ||
              (cVar6 = RtlEqualUnicodeString(puVar9 + 6,puVar11 + 0x18,1), cVar6 != '\0')) &&
             (uVar13 = uVar13 + 1, (puVar11[4] & 1) != 0)))) && (puVar11[0x17] != 0)) {
          uVar5 = *(undefined8 *)(puVar11 + 6);
          local_48[0] = 0;
          local_50 = 0;
          iVar8 = VfsOpenFile(uVar5,*(undefined8 *)(puVar11 + 10),puVar11 + 0x18,0x100008,1,0x4020,
                              local_48,&local_50);
          if (-1 < iVar8) {
            uVar10 = VfsQueryTombstone(uVar5,local_50);
            ObfDereferenceObject(local_50);
            FltClose();
            if (-1 < (int)uVar10) goto LAB_1c0007103;
          }
        }
        puVar11 = *(uint **)puVar11;
        if (puVar11 == puVar1) {
          uVar13 = 0;
          goto LAB_1c00070db;
        }
      } while( true );
    }
  }
  return 0xc00000e5;
LAB_1c0007103:
  uVar13 = 0;
  puVar11 = puVar12;
  do {
    if (uVar14 <= uVar13) break;
    if ((*(longlong *)(puVar11 + 0x1a) != 0) &&
       ((puVar11 + 0x12 == puVar9 ||
        (cVar6 = RtlEqualUnicodeString(puVar9 + 6,puVar11 + 0x18,1), cVar6 != '\0')))) {
      uVar13 = uVar13 + 1;
      if (puVar11[0x15] == 0) {
        puVar11[0xf] = 0;
        puVar11[0x10] = 0;
      }
      else {
        puVar11[0xf] = puVar11[0xf] - puVar11[0x14];
        puVar11[0x10] = puVar11[0x10] + puVar11[0x14];
      }
    }
    puVar11 = *(uint **)puVar11;
  } while (puVar11 != puVar1);
  goto LAB_1c0006d87;
  while( true ) {
    if (*(longlong *)(puVar12 + 0x1a) != 0) {
      if (puVar12 + 0x12 == puVar9) {
        uVar13 = uVar13 + 1;
      }
      else {
        cVar6 = RtlEqualUnicodeString(puVar9 + 6,puVar12 + 0x18,1);
        if (cVar6 != '\0') {
          uVar13 = uVar13 + 1;
          if (puVar12[0x15] == 0) {
            puVar12[0xf] = 0;
            puVar12[0x10] = 0;
          }
          else {
            puVar12[0xf] = puVar12[0xf] - puVar12[0x14];
            puVar12[0x10] = puVar12[0x10] + puVar12[0x14];
          }
        }
      }
    }
    puVar12 = *(uint **)puVar12;
LAB_1c00071dc:
    if (puVar12 == puVar1) break;
LAB_1c00070db:
    if (uVar14 <= uVar13) break;
  }
  *param_4 = *(undefined8 *)puVar9;
  *param_5 = puVar9[2];
  *param_6 = puVar9[3];
  *param_7 = (longlong)(puVar9 + -0x12);
  return 0;
}



===== VfsAddDirQuerySubContext @ 1c0007254 =====

ulonglong VfsAddDirQuerySubContext
                    (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,
                    ushort *param_5,ushort *param_6,longlong param_7)

{
  ushort uVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong *plVar7;
  short sVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined8 uStackY_d0;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  longlong *local_90;
  longlong local_88 [2];
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  longlong lStack_60;
  int *local_58;
  ushort local_50 [12];
  ulonglong local_38;
  longlong lStack_30;
  
  local_58 = (int *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  lVar15 = 0;
  local_88[1] = 0;
  local_90 = (longlong *)0x0;
  local_88[0] = 0;
  uVar1 = *param_5;
  if (uVar1 < *param_6) {
    lStack_70 = (ulonglong)uVar1 + *(longlong *)(param_6 + 4);
    sVar8 = *param_6 - uVar1;
    local_78 = (ulonglong)CONCAT22(sVar8,sVar8);
  }
  else {
    lStack_70 = 0;
    local_78 = 0;
  }
  local_38 = local_78;
  lStack_30 = lStack_70;
  piVar4 = (int *)VfsLookupMappingForUserAndPackage
                            (param_1,param_2,param_5,(ushort *)&local_38,(undefined4 *)local_50);
  plVar14 = (longlong *)0x0;
  local_58 = piVar4;
  if (piVar4 == (int *)0x0) {
LAB_1c00073d8:
    uVar3 = VfsCreateDirQuerySubContext
                      (param_3,param_4,param_6,*(undefined4 *)(param_7 + 0x18),'\0',local_88);
    puVar12 = auStackY_c8;
    puVar11 = auStackY_c8;
    uVar13 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      lVar10 = local_88[0];
    }
    else {
      lVar9 = param_7 + 8;
      puVar12 = auStackY_c8;
      if (plVar14 != (longlong *)0x0) {
        plVar6 = *(longlong **)(param_7 + 0x10);
        if (*plVar6 != lVar9) {
          lVar9 = 3;
          pcVar2 = (code *)swi(0x29);
          plVar6 = (longlong *)(*pcVar2)();
          puVar11 = auStackY_c0;
        }
        *plVar14 = lVar9;
        plVar14[1] = (longlong)plVar6;
        *plVar6 = (longlong)plVar14;
        *(longlong **)(lVar9 + 8) = plVar14;
        *(int *)(param_7 + 0x1c) = *(int *)(param_7 + 0x1c) + 1;
        plVar14 = (longlong *)0x0;
        *(undefined8 *)(puVar11 + 0x38) = 0;
        puVar12 = puVar11;
      }
      plVar6 = *(longlong **)(puVar12 + 0x40);
      lVar10 = 0;
      if (plVar6 != (longlong *)0x0) {
        plVar7 = *(longlong **)(lVar9 + 8);
        if (*plVar7 != lVar9) {
          lVar9 = 3;
          pcVar2 = (code *)swi(0x29);
          plVar7 = (longlong *)(*pcVar2)();
          puVar12 = puVar12 + 8;
        }
        *plVar6 = lVar9;
        plVar6[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar6;
        *(longlong **)(lVar9 + 8) = plVar6;
        *(int *)(param_7 + 0x1c) = *(int *)(param_7 + 0x1c) + 1;
        *(undefined8 *)(puVar12 + 0x40) = 0;
        lVar10 = 0;
      }
    }
  }
  else {
    uVar5 = VfsGetMappedTarget(param_3,local_50,'\x01',(longlong)piVar4,&local_68,local_88 + 1);
    lVar15 = local_88[1];
    uVar13 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      LogWrite(1,0,
               L"VfsAddDirQuerySubContext() - Failed to map filename: %wZ\n for mapping: %wZ\n Status: 0x%08X"
               ,local_50);
      lVar15 = local_88[1];
    }
    else {
      uVar3 = VfsCreateDirQuerySubContext
                        (local_88[1],0,&local_68,*(undefined4 *)(param_7 + 0x18),'\x01',&local_90);
      uVar13 = (ulonglong)uVar3;
      plVar14 = local_90;
      if (-1 < (int)uVar3) goto LAB_1c00073d8;
    }
    puVar12 = auStackY_c8;
    lVar10 = 0;
  }
  if (piVar4 != (int *)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x1c000748c;
    VfsReleaseMappingEntry(piVar4);
  }
  if (lVar15 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1c000749b;
    FltObjectDereference(lVar15);
    if (*(longlong *)(puVar12 + 0x68) != 0) {
      *(undefined8 *)(puVar12 + -8) = 0x1c00074b3;
      ExFreePoolWithTag(*(longlong *)(puVar12 + 0x68),0);
      *(undefined8 *)(puVar12 + 0x68) = 0;
    }
  }
  if (plVar14 != (longlong *)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x1c00074ca;
    VfsDeleteDirQuerySubContext((longlong)plVar14);
  }
  if (lVar10 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1c00074d7;
    VfsDeleteDirQuerySubContext(lVar10);
  }
  return uVar13;
}



===== VfsAllocateDirQueryContext @ 1c0007500 =====

undefined8 VfsAllocateDirQueryContext(longlong param_1,undefined8 *param_2)

{
  uint *puVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  lVar8 = *(longlong *)(param_1 + 0x10);
  iVar3 = *(int *)(lVar8 + 0x18);
  uVar4 = *(uint *)(lVar8 + 0x28);
  puVar5 = *(undefined2 **)(lVar8 + 0x20);
  puVar6 = (uint *)ExAllocateFromPagedLookasideList(&DAT_1c001f980);
  if (puVar6 == (uint *)0x0) {
LAB_1c000754d:
    uVar7 = 0xc000009a;
  }
  else {
    puVar6[0] = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[7] = 0;
    puVar6[8] = 0;
    puVar6[9] = 0;
    puVar6[10] = 0;
    puVar6[0xb] = 0;
    puVar6[0xc] = 0;
    puVar6[0xd] = 0;
    puVar1 = puVar6 + 2;
    *puVar6 = *puVar6 | 1;
    *(uint **)(puVar6 + 4) = puVar1;
    *(uint **)puVar1 = puVar1;
    puVar6[6] = iVar3 + 7U & 0xfffffff8;
    puVar6[8] = uVar4;
    if (puVar5 != (undefined2 *)0x0) {
      uVar2 = *puVar5;
      lVar8 = ExAllocatePool2(0x100,uVar2,0x74534656);
      *(longlong *)(puVar6 + 0xc) = lVar8;
      if (lVar8 == 0) {
        ExFreeToPagedLookasideList(&DAT_1c001f980,puVar6);
        goto LAB_1c000754d;
      }
      *(undefined2 *)(puVar6 + 10) = 0;
      *(undefined2 *)((longlong)puVar6 + 0x2a) = uVar2;
      RtlCopyUnicodeString(puVar6 + 10,puVar5);
    }
    *param_2 = puVar6;
    uVar7 = 0;
  }
  return uVar7;
}



===== VfsCleanupDirQueryContext @ 1c0007604 =====

void VfsCleanupDirQueryContext(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0);
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  plVar4 = (longlong *)(param_1 + 8);
  while( true ) {
    plVar1 = (longlong *)*plVar4;
    if (plVar1 == plVar4) {
      return;
    }
    if (((longlong *)plVar1[1] != plVar4) ||
       (lVar2 = *plVar1, (longlong *)*(longlong *)(lVar2 + 8) != plVar1)) break;
    *plVar4 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar4;
    VfsDeleteDirQuerySubContext((longlong)plVar1);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== VfsCreateDirQueryContext @ 1c0007668 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VfsCreateDirQueryContext
                    (longlong param_1,short *param_2,undefined8 *param_3,undefined8 param_4)

{
  longlong lVar1;
  bool bVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  short *psVar7;
  undefined1 auStackY_b8 [32];
  uint *local_78;
  longlong local_70;
  int local_68;
  short local_60 [4];
  short *psStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = (uint *)0x0;
  local_70 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  psStack_58 = (short *)0x0;
  lVar6 = 0;
  uVar4 = 0x101;
  if (*param_2 == 0x1687) {
    lVar1 = *(longlong *)(param_2 + 0xc);
    psVar7 = (short *)(lVar1 + 0x98);
    local_50 = *(undefined8 *)(lVar1 + 0xdc);
    uStack_48 = *(undefined8 *)(lVar1 + 0xe4);
    local_40 = *(undefined8 *)(lVar1 + 0xec);
    uStack_38 = *(undefined8 *)(lVar1 + 0xf4);
    if ((*(uint *)(param_2 + 2) & 4) != 0) {
      lVar6 = *(longlong *)(param_2 + 0x18);
    }
    uVar4 = 0x1000101;
  }
  else {
    psVar7 = param_2 + 0x24;
    local_50 = *(undefined8 *)(param_2 + 0x14);
    uStack_48 = *(undefined8 *)(param_2 + 0x18);
    local_40 = *(undefined8 *)(param_2 + 0x1c);
    uStack_38 = *(undefined8 *)(param_2 + 0x20);
    lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  }
  uVar4 = VfsGetFileNameInformation(param_1,(ulonglong)uVar4,&local_70,param_4,local_60);
  if ((int)uVar4 < 0) {
    LogWrite(1,0,
             L"VfsCreateDirQueryContext() - Failed to get filename info for data: %p\n IRP: %d\n Status: 0x%08X"
             ,param_1);
    uVar5 = (ulonglong)uVar4;
  }
  else {
    uVar5 = VfsAllocateDirQueryContext(param_1,&local_78);
    puVar3 = local_78;
    local_68 = (int)uVar5;
    uVar5 = uVar5 & 0xffffffff;
    if (-1 < local_68) {
      if ((local_60[0] == 2) && (*psStack_58 == 0x5c)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        *local_78 = *local_78 | 2;
      }
      uVar5 = VfsAddDirQuerySubContext
                        (psVar7,&local_50,*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10),lVar6,
                         (ushort *)(local_70 + 0x18),(ushort *)(local_70 + 8),(longlong)local_78);
      local_68 = (int)uVar5;
      uVar5 = uVar5 & 0xffffffff;
      if (-1 < local_68) {
        *param_3 = puVar3;
        local_78 = (uint *)0x0;
      }
    }
    FltReleaseFileNameInformation(local_70);
    if (local_78 != (uint *)0x0) {
      VfsDeleteDirQueryContext((longlong)local_78);
    }
  }
  return uVar5;
}



===== VfsCreateDirQueryContextLocal @ 1c0007848 =====

int VfsCreateDirQueryContextLocal
              (longlong param_1,longlong param_2,longlong param_3,longlong param_4,uint param_5,
              undefined8 param_6,uint *param_7)

{
  uint *puVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 local_res8;
  undefined8 uStackY_60;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  iVar4 = 0;
  local_res8 = 0;
  if (((param_1 == 0) || (param_2 == 0)) && ((param_3 == 0 || (param_4 == 0)))) {
    return -0x3ffffff3;
  }
  param_7[0] = 0;
  param_7[1] = 0;
  param_7[2] = 0;
  param_7[3] = 0;
  param_7[4] = 0;
  param_7[5] = 0;
  param_7[6] = 0;
  param_7[7] = 0;
  param_7[8] = 0;
  param_7[9] = 0;
  param_7[10] = 0;
  param_7[0xb] = 0;
  param_7[0xc] = 0;
  param_7[0xd] = 0;
  puVar1 = param_7 + 2;
  *(uint **)(param_7 + 4) = puVar1;
  *(uint **)puVar1 = puVar1;
  *param_7 = *param_7 | 1;
  param_7[6] = param_5;
  param_7[8] = 2;
  puVar7 = auStackY_58;
  if ((param_1 != 0) && (puVar7 = auStackY_58, param_2 != 0)) {
    iVar4 = VfsCreateDirQuerySubContext(param_1,0,param_2,param_5,'\0',&local_res8);
    puVar7 = auStackY_58;
    puVar6 = auStackY_58;
    if (iVar4 < 0) goto LAB_1c0007986;
    plVar5 = *(longlong **)(param_7 + 4);
    if ((uint *)*plVar5 != puVar1) {
      plVar5 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)();
      puVar6 = auStackY_50;
    }
    plVar2 = *(longlong **)(puVar6 + 0x60);
    *plVar2 = (longlong)puVar1;
    plVar2[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar2;
    *(longlong **)(param_7 + 4) = plVar2;
    param_7[7] = param_7[7] + 1;
    puVar7 = puVar6;
  }
  if ((param_3 != 0) && (param_4 != 0)) {
    *(undefined1 **)(puVar7 + 0x28) = puVar7 + 0x60;
    puVar7[0x20] = 1;
    *(undefined8 *)(puVar7 + -8) = 0x1c0007951;
    iVar4 = VfsCreateDirQuerySubContext
                      (param_3,0,param_4,param_5,puVar7[0x20],*(undefined8 **)(puVar7 + 0x28));
    *(int *)(puVar7 + 0x30) = iVar4;
    if (-1 < iVar4) {
      plVar5 = *(longlong **)(param_7 + 4);
      if ((uint *)*plVar5 != puVar1) {
        plVar5 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)();
        puVar7 = puVar7 + 8;
      }
      plVar2 = *(longlong **)(puVar7 + 0x60);
      *plVar2 = (longlong)puVar1;
      plVar2[1] = (longlong)plVar5;
      *plVar5 = (longlong)plVar2;
      *(longlong **)(param_7 + 4) = plVar2;
      param_7[7] = param_7[7] + 1;
    }
  }
LAB_1c0007986:
  if (iVar4 < 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c0007992;
    VfsCleanupDirQueryContext((longlong)param_7);
  }
  return iVar4;
}



===== VfsCreateDirQuerySubContext @ 1c00079bc =====

int VfsCreateDirQuerySubContext
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
              char param_5,undefined8 *param_6)

{
  int iVar1;
  void *_Dst;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong local_30;
  longlong local_28;
  void *local_20;
  
  _Dst = (void *)0x0;
  local_20 = (void *)0x0;
  local_30 = 0;
  local_28 = 0;
  *param_6 = 0;
  if (param_2 == 0) {
    iVar1 = VfsOpenFile(param_1,0,param_3,0x100001,1,0x4020,&local_30,&local_28);
    if (-1 < iVar1) goto LAB_1c0007a71;
    if ((iVar1 == -0x3fffffc6) || (iVar1 == -0x3fffffcc)) {
      iVar1 = 0;
      goto LAB_1c0007b3e;
    }
    pwVar3 = L"VfsCreateDirQuerySubContext() - Failed to open file: %wZ\n Status: 0x%08X";
    param_1 = param_3;
LAB_1c0007b08:
    LogWrite(1,0,pwVar3,param_1);
  }
  else {
    local_30 = 0;
    local_28 = param_2;
LAB_1c0007a71:
    _Dst = (void *)ExAllocateFromPagedLookasideList(&DAT_1c001fa00);
    local_20 = _Dst;
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,0x78);
      if (param_5 != '\0') {
        *(undefined4 *)((longlong)_Dst + 0x10) = 1;
      }
      lVar2 = ExAllocatePool2(0x100,param_4,0x62444656);
      *(longlong *)((longlong)_Dst + 0x30) = lVar2;
      if (lVar2 != 0) {
        *(undefined4 *)((longlong)_Dst + 0x38) = param_4;
        *(undefined8 *)((longlong)_Dst + 0x3c) = 0;
        *(undefined4 *)((longlong)_Dst + 0x44) = 0;
        iVar1 = FltObjectReference(param_1);
        if (-1 < iVar1) {
          *(undefined8 *)((longlong)_Dst + 0x18) = param_1;
          *(longlong *)((longlong)_Dst + 0x28) = local_30;
          *(longlong *)((longlong)_Dst + 0x20) = local_28;
          local_30 = 0;
          local_28 = 0;
          *param_6 = _Dst;
          goto LAB_1c0007b3e;
        }
        pwVar3 = 
        L"VfsCreateDirQuerySubContext() - Failed to reference instance: %p\n Status: 0x%08X";
        goto LAB_1c0007b08;
      }
    }
    iVar1 = -0x3fffff66;
  }
LAB_1c0007b3e:
  if (iVar1 < 0) {
    if (local_30 != 0) {
      ObfDereferenceObject(local_28);
      FltClose(local_30);
    }
    if (_Dst != (void *)0x0) {
      VfsDeleteDirQuerySubContext((longlong)_Dst);
    }
  }
  return iVar1;
}



===== VfsDeleteDirQueryContext @ 1c0007ba0 =====

void VfsDeleteDirQueryContext(longlong param_1)

{
  VfsCleanupDirQueryContext(param_1);
  ExFreeToPagedLookasideList(&DAT_1c001f980,param_1);
  return;
}



===== VfsDeleteDirQuerySubContext @ 1c0007bd4 =====

void VfsDeleteDirQuerySubContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x28) != 0) {
    ObfDereferenceObject(*(undefined8 *)(param_1 + 0x20));
    FltClose(*(undefined8 *)(param_1 + 0x28));
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    FltObjectDereference();
  }
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0x62444656);
  }
  ExFreeToPagedLookasideList(&DAT_1c001fa00,param_1);
  return;
}



===== VfsUpdateDirQueryContext @ 1c0007c58 =====

undefined8 VfsUpdateDirQueryContext(longlong param_1,uint *param_2)

{
  uint *puVar1;
  void *_Dst;
  uint uVar2;
  
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x28);
  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 1) == 0) {
    if (param_2[8] != uVar2) {
      return 0xc000000d;
    }
  }
  else {
    *param_2 = *param_2 | 1;
    param_2[8] = uVar2;
    for (puVar1 = *(uint **)(param_2 + 2); puVar1 != param_2 + 2; puVar1 = *(uint **)puVar1) {
      puVar1[0xf] = 0;
      puVar1[0x10] = 0;
      puVar1[0x11] = 0;
    }
  }
  uVar2 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x18) + 7U & 0xfffffff8;
  if (param_2[6] < uVar2) {
    for (puVar1 = *(uint **)(param_2 + 2); puVar1 != param_2 + 2; puVar1 = *(uint **)puVar1) {
      if ((puVar1[0xe] < uVar2) &&
         (_Dst = (void *)ExAllocatePool2(0x100,uVar2,0x62444656), _Dst != (void *)0x0)) {
        if (puVar1[0xf] != 0) {
          memcpy(_Dst,*(void **)(puVar1 + 0xc),(ulonglong)puVar1[0xe]);
        }
        ExFreePoolWithTag(*(undefined8 *)(puVar1 + 0xc),0x62444656);
        *(void **)(puVar1 + 0xc) = _Dst;
        puVar1[0xe] = uVar2;
      }
    }
    param_2[6] = uVar2;
  }
  return 0;
}



===== VfsIsExcludedExtension @ 1c0007d54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VfsIsExcludedExtension(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined1 *puStack_60;
  undefined1 local_58 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = 0x400000;
  puStack_60 = local_58;
  uVar3 = RtlUpcaseUnicodeString(&local_68,param_1,0);
  if (-1 < (int)uVar3) {
    iVar4 = 0;
    iVar5 = 3;
    do {
      iVar2 = (iVar5 + iVar4) / 2;
      uVar3 = RtlCompareUnicodeString
                        (&local_68,&DefaultExcludedExtensions + (longlong)iVar2 * 0x10,0);
      if ((int)uVar3 == 0) {
        return CONCAT71((int7)(uVar3 >> 8),1);
      }
      iVar1 = iVar2 + -1;
      if (-1 < (int)uVar3) {
        iVar4 = iVar2 + 1;
        iVar1 = iVar5;
      }
      iVar5 = iVar1;
    } while (iVar4 <= iVar5);
  }
  return uVar3 & 0xffffffffffffff00;
}



===== VfsProcessQueryInfoName @ 1c0007e24 =====

undefined8 VfsProcessQueryInfoName(longlong param_1,longlong param_2,ulonglong param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  char cVar5;
  undefined4 uVar6;
  int *piVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  longlong local_res8;
  longlong local_res10;
  ulonglong local_res18 [2];
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_res18[0] = param_3 & 0xffffffff00000000;
  local_res10 = 0;
  local_res8 = 0;
  iVar1 = *(int *)(lVar3 + 0x20);
  puVar4 = *(uint **)(lVar3 + 0x28);
  uVar2 = *(uint *)(lVar3 + 0x18);
  cVar5 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),&local_res10,&local_res8);
  if (cVar5 == '\0') {
    return 1;
  }
  if ((*(uint *)(local_res8 + 4) & 4) == 0) {
    uVar10 = *(undefined8 *)(local_res8 + 0x48);
    uVar9 = *(undefined8 *)(local_res8 + 0x40);
    piVar7 = VfsScbGetMapping(local_res10);
    if (piVar7 != (int *)0x0) {
      uVar8 = VfsQueryUnMappedFileNameInfo
                        (uVar9,uVar10,(longlong)piVar7,puVar4,uVar2,iVar1,(int *)local_res18);
      uVar6 = (undefined4)uVar8;
      VfsReleaseMappingEntry(piVar7);
      goto LAB_1c0007f13;
    }
  }
  else {
    uVar10 = *(undefined8 *)(local_res8 + 0x30);
    uVar9 = *(undefined8 *)(local_res8 + 0x28);
  }
  uVar6 = FltQueryInformationFile(uVar9,uVar10,puVar4,uVar2,iVar1,local_res18);
LAB_1c0007f13:
  *(ulonglong *)(param_1 + 0x20) = local_res18[0] & 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = uVar6;
  return 4;
}



===== VfsQueryUnMappedFileName @ 1c0007f3c =====

ulonglong VfsQueryUnMappedFileName
                    (undefined8 param_1,undefined8 param_2,longlong param_3,undefined2 *param_4)

{
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong local_18 [2];
  
  local_18[0] = 0;
  lVar2 = IoGetTopLevelIrp();
  if ((lVar2 != 0) || (cVar1 = KeAreAllApcsDisabled(), cVar1 != '\0')) {
    return 0xc01c0005;
  }
  uVar3 = FltGetFileNameInformationUnsafe(param_2,param_1,0x102,local_18);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar3 = VfsUnMapName(param_3,(short *)(local_18[0] + 8),'\0','\x01',param_4);
  FltReleaseFileNameInformation(local_18[0]);
  return uVar3 & 0xffffffff;
}



===== VfsQueryUnMappedFileNameInfo @ 1c0007ff8 =====

ulonglong VfsQueryUnMappedFileNameInfo
                    (undefined8 param_1,undefined8 param_2,longlong param_3,uint *param_4,
                    uint param_5,int param_6,int *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  undefined8 local_40;
  void *pvStack_38;
  
  local_40 = 0;
  pvStack_38 = (void *)0x0;
  iVar4 = 0;
  *param_7 = 0;
  memset(param_4,0,(ulonglong)param_5);
  if (((param_6 == 0x12) && (param_5 < 0x68)) || ((param_6 == 9 && (param_5 < 8)))) {
    return 0xc000000d;
  }
  if (param_6 == 0x12) {
    uVar1 = FltQueryInformationFile(param_1,param_2,param_4,param_5,0x12,0);
    uVar3 = (ulonglong)uVar1;
    if (((uVar1 + 0x80000000 & 0x80000000) == 0) && (uVar1 != 0x80000005)) goto LAB_1c0008136;
    iVar4 = 0x60;
    param_4 = param_4 + 0x18;
    param_5 = param_5 - 0x60;
  }
  uVar2 = VfsQueryUnMappedFileName(param_1,param_2,param_3,(undefined2 *)&local_40);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = param_5 - 4 & 0xfffffffe;
    if (uVar1 < (ushort)local_40) {
      uVar3 = 0x80000005;
    }
    if ((ushort)local_40 <= uVar1) {
      uVar1 = (uint)(ushort)local_40;
    }
    memcpy(param_4 + 1,pvStack_38,(ulonglong)uVar1);
    *param_4 = (uint)(ushort)local_40;
    *param_7 = uVar1 + 4 + iVar4;
  }
LAB_1c0008136:
  if (pvStack_38 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_38,0);
  }
  return uVar3;
}



===== VfsMarkHandle @ 1c000815c =====

undefined8 VfsMarkHandle(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 uVar2;
  longlong lVar3;
  int local_res8 [2];
  undefined8 local_res20;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_res20 = 0;
  if (*(char *)(lVar3 + 5) != '\0') {
    return 1;
  }
  cVar1 = FltIs32bitProcess();
  if (cVar1 == '\0') {
    if (*(uint *)(lVar3 + 0x20) < 0x18) goto LAB_1c00081af;
    lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 8);
  }
  else {
    if (*(uint *)(lVar3 + 0x20) < 0xc) {
LAB_1c00081af:
      *(undefined4 *)(param_1 + 0x18) = 0xc0000023;
      goto LAB_1c00081b7;
    }
    lVar3 = (longlong)*(int *)(*(longlong *)(lVar3 + 0x30) + 4);
  }
  local_res8[0] = 0;
  if ((lVar3 == 0) ||
     (cVar1 = VfsDecodeFileHandle(lVar3,*(undefined1 *)(param_1 + 0x50),local_res8,&local_res20),
     cVar1 == '\0')) {
    uVar2 = VfsPreRedirect(param_1,param_2);
    return uVar2;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
LAB_1c00081b7:
  *(undefined8 *)(param_1 + 0x20) = 0;
  return 4;
}



===== DriverInitialize @ 1c0008218 =====

uint DriverInitialize(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  LogInitialize(param_1,param_2);
  McGenEventRegister_EtwRegister
            (&PROVIDER_MICROSOFT_APPV_CLIENT_SHAREDPERFORMANCEEVENTS,param_2,
             &PROVIDER_MICROSOFT_APPV_CLIENT_SHAREDPERFORMANCEEVENTS_Context,
             (longlong *)&PROVIDER_MICROSOFT_APPV_CLIENT_SHAREDPERFORMANCEEVENTS_Context);
  memset(&VfsData,0,0x740);
  VfsInitializeLookasideLists(0x1c001f500);
  PrefixTreeContext::referenceCallback = VfsPrefixTreeReferenceMapping;
  PrefixTreeContext::releaseCallback = VfsPrefixTreeReleaseMapping;
  ExInitializePagedLookasideList
            (&PrefixTreeAllocator::PrefixTreeLookasideList,0,0,0,0x10,0x31704656,0);
  ExInitializePagedLookasideList
            (&PrefixTreeAllocator::PrefixTableLookasideList,0,0,0,0x68,0x32704656,0);
  ExInitializePagedLookasideList
            (&PrefixTreeAllocator::PrefixEntryLookasideList,0,0,0,0xd0,0x33704656,0);
  uVar3 = 0;
  ExInitializePagedLookasideList
            (&PrefixTreeAllocator::PrefixShortNameEntryLookasideList,0,0,0,0x50,0x34704656,0);
  PrefixTreeAllocator::LookasideInited = true;
  uVar1 = VfsCtxTableInitialize(0x1c001f3e0,0,1);
  if (-1 < (int)uVar1) {
    uVar1 = VfsCtxTableInitialize(0x1c001f470,1,1);
    if (-1 < (int)uVar1) {
      uVar2 = VfsCreateControlDevice(param_1);
      uVar1 = (uint)uVar2;
      if (-1 < (int)uVar1) {
        uVar1 = FltRegisterFilter(param_1,&FilterRegistration,&VfsData);
        if (-1 < (int)uVar1) {
          uVar1 = FltStartFiltering(VfsData);
          if (-1 < (int)uVar1) {
            *(undefined8 *)(param_1 + 0x68) = 0;
          }
        }
      }
    }
  }
  if ((int)uVar1 < 0) {
    VfsDriverCleanup();
    LogWrite(1,0,L"DriverInitialize() - VFS failed to load filter, Status: 0x%08X",(ulonglong)uVar1)
    ;
    LogUninitialize();
  }
  else {
    LogWrite(3,0,L"DriverInitialize() - VFS filter load succeeded",uVar3);
  }
  return uVar1;
}



===== McGenControlCallbackV2 @ 1c0008440 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c0008550 =====

void McGenEventRegister_EtwRegister
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  if (*param_4 == 0) {
    EtwRegister(param_1,McGenControlCallbackV2);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c000857c =====

undefined8 McGenEventUnregister_EtwUnregister(longlong *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    *param_1 = 0;
  }
  return uVar1;
}



===== VfsCreateControlDevice @ 1c00085b0 =====

ulonglong VfsCreateControlDevice(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_28,L"\\Device\\AppvVfs");
  pwVar3 = L"\\DosDevices\\AppvVfs";
  RtlInitUnicodeString(&local_18);
  uVar2 = WdmlibIoCreateDeviceSecure(param_1,pwVar3,&local_28);
  if (-1 < (int)uVar2) {
    uVar1 = IoCreateSymbolicLink(&local_18,&local_28);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      IoDeleteDevice(0);
    }
    DAT_1c001f3c8 = 0;
    *(code **)(param_1 + 0x70) = VfsDispatchControl;
    *(code **)(param_1 + 0x80) = VfsDispatchControl;
    *(code **)(param_1 + 0x100) = VfsDispatchControl;
    *(code **)(param_1 + 0xf0) = VfsDispatchControl;
    *(code **)(param_1 + 0xe0) = VfsDispatchDeviceIoControl;
  }
  return uVar2;
}



===== VfsDeleteControlDevice @ 1c00086a4 =====

void VfsDeleteControlDevice(void)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if (DAT_1c001f3c8 != 0) {
    RtlInitUnicodeString(&local_18,L"\\DosDevices\\AppvVfs");
    IoDeleteSymbolicLink(&local_18);
    IoDeleteDevice(DAT_1c001f3c8);
    DAT_1c001f3c8 = 0;
  }
  return;
}



===== VfsDispatchControl @ 1c0008710 =====

undefined4 VfsDispatchControl(undefined8 param_1,longlong param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = **(char **)(param_2 + 0xb8);
  if ((((cVar1 == '\0') || (cVar1 == '\x02')) || (cVar1 == '\x10')) || (cVar1 == '\x12')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc000000d;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== VfsDispatchDeviceIoControl @ 1c0008770 =====

uint VfsDispatchDeviceIoControl(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if ((uVar3 & 3) == 0) {
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    puVar2 = *(uint **)(param_2 + 0x18);
    if (((puVar2 != (uint *)0x0) && (7 < uVar1)) && (uVar3 == 0xa6888004)) {
      if (puVar2[1] == 1) {
        uVar3 = VfsMessageAddMappings(puVar2,uVar1);
        goto LAB_1c00087d9;
      }
      if (puVar2[1] == 2) {
        uVar3 = VfsMessageRemoveMappings(puVar2,uVar1);
        goto LAB_1c00087d9;
      }
    }
  }
  uVar3 = 0xc000000d;
LAB_1c00087d9:
  *(uint *)(param_2 + 0x30) = uVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== VfsCleanupPrefixTreeLibrary @ 1c000880c =====

void VfsCleanupPrefixTreeLibrary(void)

{
  ExDeletePagedLookasideList(&PrefixTreeAllocator::PrefixShortNameEntryLookasideList);
  ExDeletePagedLookasideList(&PrefixTreeAllocator::PrefixEntryLookasideList);
  ExDeletePagedLookasideList(&PrefixTreeAllocator::PrefixTableLookasideList);
  ExDeletePagedLookasideList(&PrefixTreeAllocator::PrefixTreeLookasideList);
  PrefixTreeAllocator::LookasideInited = false;
  return;
}



===== VfsCreateMappingEntry @ 1c0008870 =====

int VfsCreateMappingEntry
              (ushort *param_1,ushort *param_2,ushort *param_3,ushort *param_4,ushort *param_5,
              ushort *param_6,uint *param_7,undefined8 *param_8)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  wchar_t *pwVar7;
  undefined8 in_stack_ffffffffffffffb8;
  longlong local_30;
  int *local_28;
  
  piVar4 = (int *)ExAllocatePool2(0x100,0x60,0x654d4656);
  if (piVar4 == (int *)0x0) {
    return -0x3fffff66;
  }
  uVar6 = 0;
  local_28 = piVar4;
  memset(piVar4 + 2,0,0x58);
  *piVar4 = 1;
  piVar4[1] = 0;
  uVar5 = VfsGetDeviceVolumeNameFromVolumeName(param_1,uVar6,piVar4 + 2);
  iVar3 = (int)uVar5;
  if (iVar3 < 0) {
    param_5 = param_1;
LAB_1c0008915:
    pwVar7 = 
    L"VfsCreateMappingEntry() - Failed to get device volume name for volume: %wZ\n Status: 0x%08X";
  }
  else {
    puVar1 = (ushort *)(piVar4 + 6);
    uVar5 = VfsGetDeviceVolumeNameFromVolumeName(param_4,uVar6,(undefined4 *)puVar1);
    iVar3 = (int)uVar5;
    if (iVar3 < 0) {
      param_5 = param_4;
      goto LAB_1c0008915;
    }
    uVar5 = CreateMappingNames(param_2,param_3,param_5,param_6,in_stack_ffffffffffffffb8,
                               (longlong *)(piVar4 + 10));
    iVar3 = (int)uVar5;
    if ((iVar3 < 0) || (uVar2 = *param_7, piVar4[1] = uVar2, (uVar2 & 1) == 0)) goto LAB_1c0008a1f;
    local_30 = 0;
    uVar6 = VfsGetInstanceFromVolumeName(puVar1,&local_30);
    iVar3 = (int)uVar6;
    if (iVar3 < 0) {
      pwVar7 = L"VfsCreateMappingEntry() - Failed to get instance for volume: %wZ\n Status: 0x%08X";
      param_5 = puVar1;
    }
    else {
      iVar3 = VfsCreateSecurityDescriptors
                        (local_30,(undefined8 *)puVar1,(undefined8 *)param_5,
                         *(longlong *)(param_7 + 2),(longlong *)(piVar4 + 0x12));
      FltObjectDereference(local_30);
      if (-1 < iVar3) goto LAB_1c0008a1f;
      pwVar7 = 
      L"VfsCreateMappingEntry() - Failed to create security descriptors for directory: %wZ\n Status: 0x%08X"
      ;
    }
  }
  LogWrite(1,0,pwVar7,param_5);
LAB_1c0008a1f:
  if (iVar3 < 0) {
    VfsReleaseMappingEntry(piVar4);
  }
  else {
    *param_8 = piVar4;
  }
  return iVar3;
}



===== VfsCreateMappingPrefixTable @ 1c0008a48 =====

uint VfsCreateMappingPrefixTable
               (undefined2 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined2 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  puVar3 = (undefined8 *)ExAllocateFromPagedLookasideList(&DAT_1c001fa80);
  if (puVar3 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    uVar2 = VfsPrefixTreeCreate(puVar3 + 4);
    if (-1 < (int)uVar2) {
      uVar1 = *param_1;
      lVar4 = ExAllocatePool2(0x100,uVar1,0x6e564656);
      puVar3[3] = lVar4;
      if (lVar4 == 0) {
        uVar2 = 0xc000009a;
      }
      else {
        *(undefined2 *)(puVar3 + 2) = 0;
        *(undefined2 *)((longlong)puVar3 + 0x12) = uVar1;
        uVar2 = 0;
        RtlCopyUnicodeString(puVar3 + 2,param_1);
      }
    }
    if ((int)uVar2 < 0) {
      VfsDeleteMappingPrefixTable((longlong)puVar3);
    }
    else {
      *param_2 = puVar3;
    }
  }
  return uVar2;
}



===== VfsDeleteMappingPrefixTable @ 1c0008b38 =====

void VfsDeleteMappingPrefixTable(longlong param_1)

{
  prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *this;
  
  this = *(prefix_tree<PrefixTreeContext,PrefixTreeAllocator> **)(param_1 + 0x20);
  if (this != (prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *)0x0) {
    appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::
    ~prefix_tree<PrefixTreeContext,PrefixTreeAllocator>(this);
    if (PrefixTreeAllocator::LookasideInited == false) {
      ExFreePoolWithTag(this,0x30704656);
    }
    else {
      ExFreeToPagedLookasideList(&PrefixTreeAllocator::PrefixTreeLookasideList,this);
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x18),0);
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  ExFreeToPagedLookasideList(&DAT_1c001fa80,param_1);
  return;
}



===== VfsGenerateMappedName @ 1c0008bd4 =====

ulonglong VfsGenerateMappedName(longlong param_1,ushort *param_2,ushort *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  bVar3 = 0;
  bVar4 = 0;
  if (*param_2 != 0) {
    bVar4 = 0;
    if (**(short **)(param_2 + 4) != 0x5c) {
      bVar4 = 1;
    }
  }
  if ((*(uint *)(param_1 + 4) & 2) != 0) {
    uVar1 = IsProcessElevated(local_res8);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    bVar3 = 0;
    if (local_res8[0] != '\0') {
      bVar3 = 1;
    }
  }
  uVar5 = (uint)**(ushort **)(param_1 + 0x38) + ((uint)bVar4 + (uint)bVar3) * 2 +
          (uint)*(ushort *)(param_1 + 0x18) + (uint)*param_2;
  if (uVar5 < 0xffff) {
    lVar2 = ExAllocatePool2(0x100,uVar5 & 0xffff,0x74534656);
    *(longlong *)(param_3 + 4) = lVar2;
    if (lVar2 == 0) {
      uVar1 = 0xc000009a;
    }
    else {
      *param_3 = 0;
      param_3[1] = (ushort)uVar5;
      RtlCopyUnicodeString(param_3,param_1 + 0x18);
      RtlAppendUnicodeStringToString(param_3,*(undefined8 *)(param_1 + 0x38));
      if (bVar3 != 0) {
        *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(*param_3 >> 1) * 2) = 0x53;
        *param_3 = *param_3 + 2;
      }
      if (bVar4 != 0) {
        *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(*param_3 >> 1) * 2) = 0x5c;
        *param_3 = *param_3 + 2;
      }
      if (*param_2 != 0) {
        RtlAppendUnicodeStringToString(param_3,param_2);
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc0000106;
  }
  return uVar1;
}



===== VfsGetMappedTarget @ 1c0008d48 =====

ulonglong VfsGetMappedTarget(longlong param_1,ushort *param_2,char param_3,longlong param_4,
                            undefined8 *param_5,longlong *param_6)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ushort local_28 [8];
  
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  param_5[1] = 0;
  *(undefined4 *)param_5 = 0;
  if (param_3 == '\0') {
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    local_28[4] = 0;
    local_28[5] = 0;
    local_28[6] = 0;
    local_28[7] = 0;
    uVar3 = VfsGetRelativeNameByMapping(param_4,(short *)param_2,'\0',(undefined8 *)local_28);
    if (-1 < (int)uVar3) {
      param_2 = local_28;
      goto LAB_1c0008da8;
    }
  }
  else {
LAB_1c0008da8:
    uVar3 = VfsGenerateMappedName(param_4,param_2,(ushort *)&local_38);
  }
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if (param_6 == (longlong *)0x0) {
    *param_5 = local_38;
    param_5[1] = uStack_30;
    return 0;
  }
  lVar6 = param_4 + 0x18;
  cVar1 = RtlEqualUnicodeString(param_4 + 8,lVar6,1);
  if (cVar1 == '\0') {
    uVar4 = VfsGetInstanceFromVolumeName(lVar6,&local_40);
    uVar2 = (uint)uVar4;
    if (-1 < (int)uVar2) goto LAB_1c0008e65;
    pwVar5 = L"VfsGetMappedTarget() - Failed to get instance for volume: %wZ\n Status: 0x%08X";
  }
  else {
    local_40 = param_1;
    uVar2 = FltObjectReference(param_1);
    if (-1 < (int)uVar2) goto LAB_1c0008e65;
    pwVar5 = L"VfsGetMappedTarget() - Failed to reference instance: %p\n Status: 0x%08X";
    lVar6 = param_1;
  }
  LogWrite(1,0,pwVar5,lVar6);
LAB_1c0008e65:
  if (-1 < (int)uVar2) {
    *(undefined4 *)param_5 = (undefined4)local_38;
    *(undefined4 *)((longlong)param_5 + 4) = local_38._4_4_;
    *(undefined4 *)(param_5 + 1) = (undefined4)uStack_30;
    *(undefined4 *)((longlong)param_5 + 0xc) = uStack_30._4_4_;
    *param_6 = local_40;
  }
  if (((int)uVar2 < 0) && (uStack_30 != 0)) {
    ExFreePoolWithTag(uStack_30,0);
  }
  return (ulonglong)uVar2;
}



===== VfsGetRelativeNameByMapping @ 1c0008ea4 =====

ulonglong VfsGetRelativeNameByMapping
                    (longlong param_1,short *param_2,char param_3,undefined8 *param_4)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 extraout_var;
  ushort *puVar7;
  char local_res18 [16];
  undefined8 in_stack_ffffffffffffffa8;
  ushort local_48 [4];
  short *psStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res18[0] = '\0';
  puVar7 = (ushort *)(param_1 + 8 + (ulonglong)(-(uint)(param_3 != '\0') & 0x10));
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  psStack_40 = (short *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  cVar2 = RtlPrefixUnicodeString(puVar7,0,1);
  if (cVar2 != '\0') {
    uVar1 = *puVar7;
    uVar3 = *param_2 - uVar1;
    psStack_40 = (short *)((ulonglong)uVar1 + *(longlong *)(param_2 + 4));
    local_48[1] = uVar3;
    local_48[0] = uVar3;
    if ((1 < uVar3) && (*psStack_40 == 0x5c)) {
      cVar2 = '\0';
      if ((param_3 != '\0') && ((*(uint *)(param_1 + 4) & 2) != 0)) {
        uVar5 = IsProcessElevated(local_res18);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        cVar2 = '\0';
        if (local_res18[0] != '\0') {
          cVar2 = '\x01';
        }
      }
      uVar5 = MappingPrefixFileName
                        ((longlong *)(param_1 + 0x28),local_48,param_3,cVar2,
                         in_stack_ffffffffffffffa8,0);
      if ((char)uVar5 != '\0') {
        if (param_3 == '\0') {
          lVar6 = *(longlong *)(param_1 + 0x28);
        }
        else {
          lVar6 = *(longlong *)(param_1 + 0x38);
        }
        uVar4 = GetRemainingPath(local_48,*(ushort *)(lVar6 + 0x10),(short *)&local_38);
        if ((int)uVar4 < 0) {
          return CONCAT44(extraout_var,uVar4);
        }
        *param_4 = local_38;
        param_4[1] = uStack_30;
        return 0;
      }
    }
  }
  return 0xc000000d;
}



===== VfsGetUnMappedSource @ 1c0008fd0 =====

ulonglong VfsGetUnMappedSource
                    (longlong param_1,short *param_2,longlong param_3,undefined8 param_4,
                    undefined8 *param_5,longlong *param_6)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  longlong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  param_5[1] = 0;
  *(undefined4 *)param_5 = 0;
  uVar3 = VfsUnMapName(param_3,param_2,'\0','\0',(undefined2 *)&local_28);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if (param_6 == (longlong *)0x0) {
    *param_5 = local_28;
    param_5[1] = uStack_20;
    return 0;
  }
  lVar6 = param_3 + 8;
  cVar1 = RtlEqualUnicodeString(lVar6,param_3 + 0x18,1);
  if (cVar1 == '\0') {
    uVar4 = VfsGetInstanceFromVolumeName(lVar6,&local_30);
    uVar2 = (uint)uVar4;
    if (-1 < (int)uVar2) goto LAB_1c00090d7;
    pwVar5 = L"VfsGetUnMappedSource() - Failed to get instance for volume: %wZ\n Status: 0x%08X";
  }
  else {
    local_30 = param_1;
    uVar2 = FltObjectReference(param_1);
    if (-1 < (int)uVar2) goto LAB_1c00090d7;
    pwVar5 = L"VfsGetUnMappedSource() - Failed to reference instance: %p\n Status: 0x%08X";
    lVar6 = param_1;
  }
  LogWrite(1,0,pwVar5,lVar6);
LAB_1c00090d7:
  if (-1 < (int)uVar2) {
    *(undefined4 *)param_5 = (undefined4)local_28;
    *(undefined4 *)((longlong)param_5 + 4) = local_28._4_4_;
    *(undefined4 *)(param_5 + 1) = (undefined4)uStack_20;
    *(undefined4 *)((longlong)param_5 + 0xc) = uStack_20._4_4_;
    *param_6 = local_30;
  }
  if (((int)uVar2 < 0) && (uStack_20 != 0)) {
    ExFreePoolWithTag(uStack_20,0);
  }
  return (ulonglong)uVar2;
}



===== VfsInsertMappingEntry @ 1c0009118 =====

uint VfsInsertMappingEntry(undefined8 *param_1,void *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  short *psVar3;
  prefix_tree_name_entry<PrefixTreeContext> *ppVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 *puVar12;
  undefined8 *local_res8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  uVar1 = *param_1;
  local_res8 = (undefined8 *)0x0;
  iVar6 = 0;
  uVar7 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(uVar1,1);
  puVar10 = auStack_48;
  puVar8 = param_1 + 1;
  puVar12 = (undefined8 *)0x0;
  for (puVar9 = (undefined8 *)*puVar8; puVar9 != puVar8; puVar9 = (undefined8 *)*puVar9) {
    param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
    local_res8 = puVar9;
    iVar6 = RtlCompareUnicodeString((longlong)param_2 + 8,puVar9 + 2);
    puVar12 = puVar9;
    if (iVar6 < 1) break;
  }
  if (((undefined8 *)*puVar8 == puVar8) || (puVar11 = auStack_48, iVar6 != 0)) {
    uVar7 = VfsCreateMappingPrefixTable
                      ((undefined2 *)((longlong)param_2 + 8),&local_res8,param_3,param_4);
    puVar11 = auStack_48;
    if ((int)uVar7 < 0) goto LAB_1c00091fa;
    puVar8 = (undefined8 *)puVar9[1];
    if ((undefined8 *)*puVar8 != puVar9) {
      puVar8 = (undefined8 *)0x3;
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)();
      puVar10 = auStack_40;
    }
    puVar12 = *(undefined8 **)(puVar10 + 0x50);
    *puVar12 = puVar9;
    puVar12[1] = puVar8;
    *puVar8 = puVar12;
    puVar9[1] = puVar12;
    puVar11 = puVar10;
  }
  if (puVar12 != (undefined8 *)0x0) {
    puVar2 = *(undefined4 **)((longlong)param_2 + 0x30);
    psVar3 = *(short **)((longlong)param_2 + 0x28);
    ppVar4 = (prefix_tree_name_entry<PrefixTreeContext> *)puVar12[4];
    *(undefined8 *)(puVar11 + -8) = 0x1c00091f8;
    uVar7 = VfsPrefixTreeInsert(ppVar4,psVar3,puVar2,param_2);
  }
LAB_1c00091fa:
  uVar1 = *param_1;
  *(undefined8 *)(puVar11 + -8) = 0x1c0009205;
  ExReleaseResourceLite(uVar1);
  *(undefined8 *)(puVar11 + -8) = 0x1c0009211;
  KeLeaveCriticalRegion();
  return uVar7;
}



===== VfsLookupMappingEntry @ 1c000923c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool VfsLookupMappingEntry
               (undefined8 *param_1,undefined8 param_2,ushort *param_3,undefined4 *param_4,
               longlong *param_5)

{
  short *psVar1;
  undefined8 uVar2;
  int iVar3;
  prefix_tree_name_entry<PrefixTreeContext> *ppVar4;
  undefined8 *puVar5;
  prefix_tree_name_entry<PrefixTreeContext> *ppVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 local_78;
  undefined8 uStack_70;
  short local_68 [8];
  longlong local_58;
  longlong lStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  uVar2 = *param_1;
  lVar7 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(uVar2,1);
  for (puVar5 = (undefined8 *)param_1[1]; puVar5 != param_1 + 1; puVar5 = (undefined8 *)*puVar5) {
    iVar3 = RtlCompareUnicodeString(puVar5 + 2,param_2,1);
    if (-1 < iVar3) {
      if ((iVar3 < 1) && (*param_3 != 0)) {
        uVar12 = 0;
        uVar13 = 0;
        uVar14 = 0;
        uVar15 = 0;
        uVar8 = *(undefined4 *)param_3;
        ppVar6 = (prefix_tree_name_entry<PrefixTreeContext> *)0x0;
        local_58 = *(longlong *)puVar5[4];
        lStack_50 = ((longlong *)puVar5[4])[1];
        uVar9 = *(undefined4 *)(param_3 + 2);
        uVar10 = *(undefined4 *)(param_3 + 4);
        uVar11 = *(undefined4 *)(param_3 + 6);
        goto LAB_1c00092e5;
      }
      break;
    }
  }
LAB_1c00093d9:
  ExReleaseResourceLite(*param_1);
  KeLeaveCriticalRegion();
  return lVar7 != 0;
LAB_1c00092e5:
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_78 = 0;
  uStack_70 = (short *)0x0;
  local_48 = uVar8;
  uStack_44 = uVar9;
  uStack_40 = uVar10;
  uStack_3c = uVar11;
  FsRtlDissectName(&local_48,local_68,&local_78);
  if (((short)local_78 != 0) && (*uStack_70 == 0x5c)) goto LAB_1c00093d9;
  if ((local_68[0] == 0) ||
     (ppVar4 = appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::find_avl
                         ((prefix_tree_table *)&local_58,(_UNICODE_STRING *)local_68),
     ppVar4 == (prefix_tree_name_entry<PrefixTreeContext> *)0x0)) goto LAB_1c000936b;
  local_58 = *(longlong *)(ppVar4 + 0x80);
  lStack_50 = *(longlong *)(ppVar4 + 0x88);
  uVar8 = (undefined4)local_78;
  if (ppVar4[0x98] != (prefix_tree_name_entry<PrefixTreeContext>)0x0) {
    ppVar6 = ppVar4;
    uVar12 = (undefined4)local_78;
    uVar13 = local_78._4_4_;
    uVar14 = (undefined4)uStack_70;
    uVar15 = uStack_70._4_4_;
  }
  if ((local_58 == 0) ||
     (uVar9 = local_78._4_4_, uVar10 = (undefined4)uStack_70, uVar11 = uStack_70._4_4_,
     (short)local_78 == 0)) goto LAB_1c000936b;
  goto LAB_1c00092e5;
LAB_1c000936b:
  if (ppVar6 != (prefix_tree_name_entry<PrefixTreeContext> *)0x0) {
    if ((PrefixTreeContext::referenceCallback != (_func_void_void_ptr *)0x0) &&
       (*(void **)(ppVar6 + 0xa0) != (void *)0x0)) {
      (*PrefixTreeContext::referenceCallback)(*(void **)(ppVar6 + 0xa0));
    }
    lVar7 = *(longlong *)(ppVar6 + 0xa0);
    *param_4 = uVar12;
    param_4[1] = uVar13;
    param_4[2] = uVar14;
    param_4[3] = uVar15;
    *param_5 = lVar7;
    if ((((short)uVar12 == 0) && (1 < *param_3)) &&
       (psVar1 = (short *)(*(longlong *)(param_3 + 4) + -2 + (ulonglong)(*param_3 >> 1) * 2),
       *psVar1 == 0x5c)) {
      *(short **)(param_4 + 2) = psVar1;
      *param_4 = 0x20002;
    }
  }
  goto LAB_1c00093d9;
}



===== VfsLookupMappingForPackage @ 1c0009428 =====

ulonglong VfsLookupMappingForPackage
                    (longlong param_1,undefined8 param_2,undefined8 param_3,ushort *param_4,
                    undefined4 *param_5)

{
  bool bVar1;
  longlong lVar2;
  ulonglong local_18 [2];
  
  local_18[0] = 0;
  lVar2 = VfsCtxTableElementLookup(param_1,param_2);
  if ((lVar2 == 0) || ((undefined8 *)(lVar2 + 0x28) == (undefined8 *)0x0)) {
    local_18[0] = 0;
  }
  else {
    bVar1 = VfsLookupMappingEntry
                      ((undefined8 *)(lVar2 + 0x28),param_3,param_4,param_5,(longlong *)local_18);
    VfsPkgCtxRelease(lVar2);
    local_18[0] = -(ulonglong)bVar1 & local_18[0];
  }
  return local_18[0];
}



===== VfsLookupMappingForUserAndPackage @ 1c00094a4 =====

ulonglong VfsLookupMappingForUserAndPackage
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort *param_4,
                    undefined4 *param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  
  RtlLengthSid();
  lVar1 = VfsCtxTableElementLookup(0x1c001f470,param_1);
  if (lVar1 != 0) {
    uVar2 = VfsLookupMappingForPackage(lVar1 + 0x60,param_2,param_3,param_4,param_5);
    VfsUserCtxRelease(lVar1);
    if (uVar2 != 0) {
      return uVar2;
    }
  }
  uVar2 = VfsLookupMappingForPackage(0x1c001f3e0,param_2,param_3,param_4,param_5);
  return uVar2;
}



===== VfsPrefixTreeReferenceMapping @ 1c0009560 =====

void VfsPrefixTreeReferenceMapping(int *param_1)

{
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  return;
}



===== VfsPrefixTreeReleaseMapping @ 1c0009570 =====

void VfsPrefixTreeReleaseMapping(int *param_1)

{
  VfsReleaseMappingEntry(param_1);
  return;
}



===== VfsReleaseMappingEntry @ 1c0009588 =====

void VfsReleaseMappingEntry(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    DeleteMappingNames((longlong *)(param_1 + 10));
    if (*(longlong *)(param_1 + 4) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 4),0);
      param_1[4] = 0;
      param_1[5] = 0;
    }
    if (*(longlong *)(param_1 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 8),0);
      param_1[8] = 0;
      param_1[9] = 0;
    }
    VfsDeleteSecurityDescriptors((longlong *)(param_1 + 0x12));
    ExFreePoolWithTag(param_1,0x654d4656);
  }
  return;
}



===== VfsRemoveMappings @ 1c0009608 =====

void VfsRemoveMappings(undefined8 *param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = *param_1;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(uVar2,1);
  puVar6 = auStack_28;
  plVar1 = param_1 + 1;
  do {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
LAB_1c0009665:
      uVar2 = *param_1;
      *(undefined8 *)(puVar6 + -8) = 0x1c000966f;
      ExReleaseResourceLite(uVar2);
      *(undefined8 *)(puVar6 + -8) = 0x1c000967b;
      KeLeaveCriticalRegion();
      return;
    }
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStack_20;
      goto LAB_1c0009665;
    }
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    VfsDeleteMappingPrefixTable((longlong)plVar3);
  } while( true );
}



===== VfsUnMapName @ 1c0009694 =====

ulonglong VfsUnMapName(longlong param_1,short *param_2,char param_3,char param_4,undefined2 *param_5
                      )

{
  ulonglong uVar1;
  ushort *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = VfsGetRelativeNameByMapping(param_1,param_2,'\x01',&local_28);
  if (-1 < (int)uVar1) {
    if (param_3 == '\0') {
      puVar2 = *(ushort **)(param_1 + 0x28);
    }
    else {
      puVar2 = *(ushort **)(param_1 + 0x30);
    }
    uVar5 = (uint)*puVar2 + (uint)(ushort)local_28;
    if (param_4 == '\0') {
      uVar5 = uVar5 + *(ushort *)(param_1 + 8);
    }
    if (uVar5 < 0x10000) {
      lVar3 = ExAllocatePool2(0x100,uVar5 & 0xffff,0x74534656);
      *(longlong *)(param_5 + 4) = lVar3;
      if (lVar3 == 0) {
        uVar1 = 0xc000009a;
      }
      else {
        *param_5 = 0;
        param_5[1] = (short)uVar5;
        if (param_4 == '\0') {
          RtlCopyUnicodeString(param_5,param_1 + 8);
        }
        if (param_3 == '\0') {
          uVar4 = *(undefined8 *)(param_1 + 0x28);
        }
        else {
          uVar4 = *(undefined8 *)(param_1 + 0x30);
        }
        RtlAppendUnicodeStringToString(param_5,uVar4);
        RtlAppendUnicodeStringToString(param_5,&local_28);
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xc0000106;
    }
  }
  return uVar1;
}



===== VfsCreateMappingEntryFromMessage @ 1c00097b0 =====

int VfsCreateMappingEntryFromMessage(uint *param_1,uint param_2,uint *param_3,undefined8 *param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  undefined8 local_a0;
  undefined8 local_98;
  longlong lStack_90;
  undefined8 local_88;
  longlong lStack_80;
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  longlong lStack_40;
  
  local_a0 = 0;
  uVar6 = *param_1;
  lStack_90 = 0;
  if (uVar6 != 0) {
    if (param_2 < uVar6) {
      return -0x3ffffff3;
    }
    param_2 = uVar6;
  }
  if (0x2b < param_2) {
    uVar8 = (ushort)param_1[4];
    uVar6 = param_2 - 0x28;
    if ((uint)uVar8 + (uint)(ushort)param_1[2] <= uVar6) {
      uVar1 = *(ushort *)((longlong)param_1 + 0x12);
      if ((uint)uVar1 + (uint)*(ushort *)((longlong)param_1 + 10) <= uVar6) {
        uVar2 = (ushort)param_1[5];
        if ((uint)uVar2 + (uint)(ushort)param_1[3] <= uVar6) {
          uVar3 = (ushort)param_1[8];
          if ((uint)(ushort)param_1[6] + (uint)uVar3 <= uVar6) {
            uVar4 = *(ushort *)((longlong)param_1 + 0x22);
            if ((uint)*(ushort *)((longlong)param_1 + 0x1a) + (uint)uVar4 <= uVar6) {
              uVar5 = (ushort)param_1[9];
              if ((uint)uVar5 + (uint)(ushort)param_1[7] <= uVar6) {
                lStack_40 = (longlong)param_1 + (ulonglong)(ushort)param_1[2] + 0x28;
                local_68 = (ulonglong)CONCAT22(uVar2,uVar2);
                lStack_50 = (longlong)param_1 +
                            (ulonglong)*(ushort *)((longlong)param_1 + 10) + 0x28;
                local_48 = (ulonglong)CONCAT22(uVar8,uVar8);
                lStack_60 = (longlong)param_1 + (ulonglong)(ushort)param_1[3] + 0x28;
                local_58 = (ulonglong)CONCAT22(uVar1,uVar1);
                lStack_70 = (ulonglong)(ushort)param_1[6] + 0x28 + (longlong)param_1;
                local_78 = (ulonglong)CONCAT22(uVar3,uVar3);
                lStack_80 = (ulonglong)*(ushort *)((longlong)param_1 + 0x1a) + 0x28 +
                            (longlong)param_1;
                local_88 = (ulonglong)CONCAT22(uVar4,uVar4);
                local_98 = 0;
                uVar8 = 0;
                if (uVar5 != 0) {
                  lStack_90 = (longlong)param_1 + (ulonglong)(ushort)param_1[7] + 0x28;
                  local_98 = (ulonglong)CONCAT22(uVar5,uVar5);
                  uVar8 = uVar5;
                }
                *param_3 = param_1[1];
                iVar7 = VfsCreateMappingEntry
                                  ((ushort *)&local_48,(ushort *)&local_58,(ushort *)&local_68,
                                   (ushort *)&local_78,(ushort *)&local_88,
                                   (ushort *)(-(ulonglong)(uVar8 != 0) & (ulonglong)&local_98),
                                   param_3,&local_a0);
                if (iVar7 < 0) {
                  return iVar7;
                }
                *param_4 = local_a0;
                return iVar7;
              }
            }
          }
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== VfsMessageAddMappings @ 1c00099b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint VfsMessageAddMappings(uint *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  int **ppiVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 auStackY_e8 [32];
  uint local_a4;
  longlong local_a0 [2];
  int *local_90;
  undefined8 uStack_88;
  longlong local_80;
  longlong local_78;
  uint local_70 [2];
  longlong lStack_68;
  uint local_60;
  uint *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_90 = (int *)0x0;
  local_80 = 0;
  lVar14 = 0;
  local_78 = 0;
  local_a0[0] = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  lStack_68 = 0;
  local_a4 = 0;
  uVar6 = VfsMessageCommonValidate(param_1,param_2,&local_a4,(undefined4 *)&local_50,local_a0);
  lVar3 = local_a0[0];
  if ((int)uVar6 < 0) {
    return 0xc000000d;
  }
  uVar1 = (ushort)param_1[5];
  if (local_a4 < uVar1) {
    return 0xc000000d;
  }
  puVar10 = (uint *)((longlong)param_1 + (ulonglong)uVar1 + 0x18);
  uVar9 = local_a4 - uVar1;
  if (local_a0[0] == 0) {
    puVar8 = &DAT_1c001f3e0;
  }
  else {
    uVar4 = RtlLengthSid(local_a0[0]);
    uVar5 = VfsCtxTableGetContext(0x1c001f470,lVar3,uVar4,'\x01',&local_78);
    if ((int)uVar5 < 0) {
      local_a0[0] = 0;
      local_a0[1] = 0;
      puVar7 = ConvertSidToString(lVar3,local_a0);
      LogWrite(1,0,
               L"VfsMessageAddMappings() - Failed to get or create user context for user: %wZ\n Status: 0x%08X"
               ,puVar7);
      FreeSidString((longlong)local_a0);
      lVar13 = 0;
      lVar14 = local_78;
      goto LAB_1c0009ce5;
    }
    puVar8 = (undefined *)(local_78 + 0x60);
    lVar14 = local_78;
  }
  uVar5 = VfsCtxTableGetContext((longlong)puVar8,&local_50,0x20,'\x01',&local_80);
  lVar13 = local_80;
  if ((int)uVar5 < 0) {
    local_70[0] = 0;
    local_70[1] = 0;
    lStack_68 = 0;
    local_90 = (int *)0x0;
    uStack_88 = 0;
    local_a0[0] = 0;
    local_a0[1] = 0;
    ConvertGuidToString(&local_40,local_a0);
    ConvertGuidToString(&local_50,&local_90);
    puVar7 = ConvertSidToString(lVar3,(undefined8 *)local_70);
    LogWrite(1,0,
             L"VfsMessageAddMappings() - Failed to get or create package context for user: %wZ\n PackageId: %wZ\n VersionId: %wZ\n Status: 0x%08X"
             ,puVar7);
    FreeSidString((longlong)local_a0);
    FreeSidString((longlong)&local_90);
    FreeSidString((longlong)local_70);
    lVar13 = local_80;
  }
  else {
    while( true ) {
      lStack_68 = lVar3;
      ppiVar12 = &local_90;
      puVar11 = local_70;
      uVar5 = VfsCreateMappingEntryFromMessage(puVar10,uVar9,puVar11,ppiVar12);
      if ((int)uVar5 < 0) break;
      uVar5 = VfsInsertMappingEntry((undefined8 *)(lVar13 + 0x28),local_90,puVar11,ppiVar12);
      if ((int)uVar5 < 0) {
        if (uVar5 == 0xc00000bd) {
          uVar5 = 0;
        }
        else {
          LogWrite(1,0,
                   L"VfsMessageAddMappings() - Failed to insert mapping for file: %wZ\n Status: 0x%08X"
                   ,*(undefined8 *)(local_90 + 10));
        }
      }
      VfsReleaseMappingEntry(local_90);
      if ((int)uVar5 < 0) goto LAB_1c0009ce5;
      uVar2 = *puVar10;
      if (uVar2 == 0) goto LAB_1c0009ce5;
      uVar9 = uVar9 - uVar2;
      puVar10 = (uint *)((longlong)puVar10 + (ulonglong)uVar2);
      local_60 = uVar9;
      local_58 = puVar10;
    }
    local_90 = (int *)0x0;
    uStack_88 = 0;
    local_a0[0] = 0;
    local_a0[1] = 0;
    local_70[0] = 0;
    local_70[1] = 0;
    lStack_68 = 0;
    ConvertGuidToString(&local_40,(undefined8 *)local_70);
    ConvertGuidToString(&local_50,local_a0);
    puVar7 = ConvertSidToString(lVar3,&local_90);
    LogWrite(1,0,
             L"VfsMessageAddMappings() - Failed to create mapping from message for user: %wZ\n PackageId: %wZ\n VersionId: %wZ\n Status: 0x%08X"
             ,puVar7);
    FreeSidString((longlong)local_70);
    FreeSidString((longlong)local_a0);
    FreeSidString((longlong)&local_90);
  }
LAB_1c0009ce5:
  if (lVar13 != 0) {
    VfsPkgCtxRelease(lVar13);
  }
  if (lVar14 != 0) {
    VfsUserCtxRelease(lVar14);
  }
  return uVar5;
}



===== VfsMessageCommonValidate @ 1c0009d3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
VfsMessageCommonValidate
          (uint *param_1,uint param_2,uint *param_3,undefined4 *param_4,longlong *param_5)

{
  undefined8 *_Src;
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined1 auStack_128 [32];
  undefined4 local_108;
  undefined4 uStack_104;
  undefined2 *puStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined2 local_b8;
  undefined8 local_b6;
  undefined8 uStack_ae;
  undefined8 local_a6;
  undefined8 uStack_9e;
  undefined8 local_96;
  undefined8 uStack_8e;
  undefined4 local_86;
  undefined4 uStack_82;
  undefined4 uStack_7e;
  undefined4 uStack_7a;
  undefined8 local_76;
  undefined2 local_6e;
  ulonglong local_68;
  
  local_68 = __security_cookie ^ (ulonglong)auStack_128;
  lVar6 = 0;
  local_f8 = 0;
  uStack_f0 = (undefined2 *)0x0;
  local_e8 = 0;
  uStack_e0 = 0;
  if ((((0x1b < param_2) && (uVar3 = *param_1, uVar3 <= param_2)) && (0x1b < uVar3)) &&
     (uVar3 = uVar3 - 0x18,
     (uint)*(ushort *)((longlong)param_1 + 0x12) + (uint)(ushort)param_1[4] <= uVar3)) {
    uVar1 = *(ushort *)((longlong)param_1 + 0xe);
    uVar2 = (ushort)param_1[3];
    if ((uint)uVar1 + (uint)uVar2 <= uVar3) {
      _Src = (undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x18);
      if (uVar1 == 0x20) {
        memcpy(&local_f8,_Src,0x20);
        uVar7 = (undefined4)local_f8;
        uVar8 = local_f8._4_4_;
        uVar9 = (undefined4)uStack_f0;
        uVar10 = uStack_f0._4_4_;
        uVar11 = (undefined4)local_e8;
        uVar12 = local_e8._4_4_;
        uVar13 = (undefined4)uStack_e0;
        uVar14 = uStack_e0._4_4_;
      }
      else {
        uStack_104 = 0;
        local_d8 = 0;
        uStack_d0 = 0;
        local_c8 = 0;
        uStack_c0 = 0;
        if ((uVar1 & 0xfffe) != 0x92) {
          return 0xc000000d;
        }
        if (*(short *)((longlong)param_1 + (ulonglong)uVar2 + 0x60) != 0x5f) {
          return 0xc000000d;
        }
        local_108 = 0x4c004c;
        local_b8 = 0x7b;
        local_6e = 0x7d;
        puStack_100 = &local_b8;
        local_b6 = *_Src;
        uStack_ae = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x20);
        local_a6 = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x28);
        uStack_9e = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x30);
        local_96 = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x38);
        uStack_8e = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x40);
        local_86 = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x48);
        uStack_82 = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x4c);
        uStack_7e = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x50);
        uStack_7a = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x54);
        local_76 = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x58);
        uVar5 = RtlGUIDFromString(&local_108,&local_d8);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        local_f8 = CONCAT44(uStack_104,local_108);
        uStack_f0 = puStack_100;
        local_b6 = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x62);
        uStack_ae = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x6a);
        local_a6 = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x72);
        uStack_9e = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x7a);
        local_96 = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x82);
        uStack_8e = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0x8a);
        local_86 = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x92);
        uStack_82 = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x96);
        uStack_7e = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x9a);
        uStack_7a = *(undefined4 *)((longlong)param_1 + (ulonglong)uVar2 + 0x9e);
        local_76 = *(undefined8 *)((longlong)param_1 + (ulonglong)uVar2 + 0xa2);
        uVar5 = RtlGUIDFromString(&local_f8,&local_c8);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        uVar7 = (undefined4)local_d8;
        uVar8 = local_d8._4_4_;
        uVar9 = (undefined4)uStack_d0;
        uVar10 = uStack_d0._4_4_;
        uVar11 = (undefined4)local_c8;
        uVar12 = local_c8._4_4_;
        uVar13 = (undefined4)uStack_c0;
        uVar14 = uStack_c0._4_4_;
      }
      if (*(ushort *)((longlong)param_1 + 0x12) == 0) {
LAB_1c0009f25:
        *param_3 = uVar3;
        *param_4 = uVar7;
        param_4[1] = uVar8;
        param_4[2] = uVar9;
        param_4[3] = uVar10;
        param_4[4] = uVar11;
        param_4[5] = uVar12;
        param_4[6] = uVar13;
        param_4[7] = uVar14;
        *param_5 = lVar6;
        return 0;
      }
      if (*(ushort *)((longlong)param_1 + 0x12) < 0x45) {
        lVar6 = (ulonglong)(ushort)param_1[4] + 0x18 + (longlong)param_1;
        cVar4 = RtlValidSid(lVar6);
        if (cVar4 != '\0') goto LAB_1c0009f25;
      }
    }
  }
  return 0xc000000d;
}



===== VfsMessageRemoveMappings @ 1c0009f78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VfsMessageRemoveMappings(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStackY_d8 [32];
  longlong local_98;
  longlong local_90;
  longlong local_88;
  uint local_80;
  int local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_90 = 0;
  lVar7 = 0;
  local_88 = 0;
  local_98 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_80 = 0;
  uVar3 = VfsMessageCommonValidate(param_1,param_2,&local_80,(undefined4 *)&local_48,&local_98);
  if ((int)uVar3 < 0) {
    return -0x3ffffff3;
  }
  if (local_98 == 0) {
    puVar5 = &DAT_1c001f3e0;
  }
  else {
    uVar1 = RtlLengthSid(local_98);
    iVar2 = VfsCtxTableGetContext(0x1c001f470,local_98,uVar1,'\0',&local_88);
    local_7c = iVar2;
    if (iVar2 < 0) {
      local_78 = 0;
      uStack_70 = 0;
      puVar4 = ConvertSidToString(local_98,&local_78);
      LogWrite(1,0,
               L"VfsMessageRemoveMappings() - Failed to get user context for user: %wZ\n Status: 0x%08X"
               ,puVar4);
      FreeSidString((longlong)&local_78);
      lVar6 = 0;
      lVar7 = local_88;
      goto LAB_1c000a17c;
    }
    puVar5 = (undefined *)(local_88 + 0x60);
    lVar7 = local_88;
  }
  iVar2 = VfsCtxTableGetContext((longlong)puVar5,&local_48,0x20,'\0',&local_90);
  lVar6 = local_90;
  local_7c = iVar2;
  if (iVar2 < 0) {
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    ConvertGuidToString(&local_38,&local_78);
    ConvertGuidToString(&local_48,&local_68);
    puVar4 = ConvertSidToString(local_98,&local_58);
    LogWrite(1,0,
             L"VfsMessageRemoveMappings() - Failed to get package context for user: %wZ\n PackageId: %wZ\n VersionId: %wZ\n Status: 0x%08X"
             ,puVar4);
    FreeSidString((longlong)&local_78);
    FreeSidString((longlong)&local_68);
    FreeSidString((longlong)&local_58);
    lVar6 = local_90;
  }
  else {
    VfsRemoveMappings((undefined8 *)(local_90 + 0x28));
  }
LAB_1c000a17c:
  if (lVar6 != 0) {
    VfsPkgCtxRelease(lVar6);
  }
  if (lVar7 != 0) {
    VfsUserCtxRelease(lVar7);
  }
  return iVar2;
}



===== VfsCreateNameNormalizationContext @ 1c000a1a4 =====

undefined8
VfsCreateNameNormalizationContext
          (ushort *param_1,ushort param_2,undefined8 param_3,undefined8 param_4,undefined8 *param_5)

{
  int *piVar1;
  ulonglong *puVar2;
  undefined8 uVar3;
  short sVar4;
  undefined8 local_38;
  longlong lStack_30;
  ushort local_28;
  ushort local_26;
  undefined4 local_24;
  longlong local_20;
  undefined4 local_18 [4];
  
  uVar3 = 0;
  local_24 = 0;
  local_20 = *(longlong *)(param_1 + 4);
  local_38._0_4_ = 0;
  lStack_30 = 0;
  if (param_2 < *param_1) {
    lStack_30 = (ulonglong)param_2 + local_20;
    sVar4 = *param_1 - param_2;
    local_38._0_4_ = CONCAT22(sVar4,sVar4);
  }
  local_38 = (ulonglong)(uint)local_38;
  local_28 = param_2;
  local_26 = param_2;
  piVar1 = (int *)VfsLookupMappingForUserAndPackage
                            (param_3,param_4,&local_28,(ushort *)&local_38,local_18);
  puVar2 = (ulonglong *)ExAllocateFromPagedLookasideList(&DAT_1c001f900);
  if (puVar2 == (ulonglong *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    *puVar2 = (ulonglong)piVar1;
    piVar1 = (int *)0x0;
    *param_5 = puVar2;
  }
  if (piVar1 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar1);
  }
  return uVar3;
}



===== VfsExpandComponentByMapping @ 1c000a288 =====

ulonglong VfsExpandComponentByMapping
                    (longlong param_1,ushort *param_2,longlong param_3,undefined4 *param_4,
                    int param_5)

{
  longlong lVar1;
  longlong lVar2;
  ushort uVar3;
  ulonglong uVar4;
  void *pvVar5;
  ushort *puVar6;
  longlong lVar7;
  short sVar8;
  ulonglong uVar9;
  undefined8 local_38;
  longlong lStack_30;
  
  uVar3 = *(ushort *)(param_1 + 8);
  local_38._0_4_ = 0;
  lStack_30 = 0;
  if (uVar3 < *param_2) {
    lStack_30 = (ulonglong)uVar3 + *(longlong *)(param_2 + 4);
    sVar8 = *param_2 - uVar3;
    local_38._0_4_ = CONCAT22(sVar8,sVar8);
  }
  local_38 = (ulonglong)(uint)local_38;
  uVar4 = FileNamePrefixMapping((ushort *)&local_38,(longlong *)(param_1 + 0x28));
  if ((char)uVar4 == '\0') goto LAB_1c000a42d;
  uVar3 = GetNumberComponents((ushort *)&local_38);
  lVar1 = *(longlong *)(param_1 + 0x28);
  lVar2 = *(longlong *)(param_1 + 0x30);
  uVar9 = (ulonglong)uVar3;
  lVar7 = uVar9 * 0x10;
  uVar4 = RtlEqualUnicodeString(lVar1 + 0x18 + lVar7,param_3,1);
  if ((char)uVar4 == '\0') {
    if (lVar2 != 0) {
      uVar4 = RtlEqualUnicodeString(lVar2 + 0x18 + lVar7,param_3,1);
      if ((char)uVar4 != '\0') goto LAB_1c000a3ef;
    }
    uVar3 = *(ushort *)(lVar1 + 0x18 + lVar7);
    uVar4 = RtlPrefixUnicodeString(lVar1 + 0x18 + lVar7,param_3,1);
    if (((char)uVar4 == '\0') ||
       (uVar4 = *(ulonglong *)(param_3 + 8), *(short *)(uVar4 + (ulonglong)(uVar3 >> 1) * 2) != 0x3a
       )) {
      if (lVar2 == 0) goto LAB_1c000a42d;
      puVar6 = (ushort *)(lVar2 + 0x18 + lVar7);
      uVar3 = *puVar6;
      uVar4 = RtlPrefixUnicodeString(puVar6,param_3,1);
      if (((char)uVar4 == '\0') ||
         (uVar4 = *(ulonglong *)(param_3 + 8),
         *(short *)(uVar4 + (ulonglong)(uVar3 >> 1) * 2) != 0x3a)) goto LAB_1c000a42d;
    }
  }
LAB_1c000a3ef:
  lVar1 = *(longlong *)(param_1 + 0x28);
  if ((uint)*(ushort *)(lVar1 + 0x18 + uVar9 * 0x10) <= param_5 - 0xcU) {
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = (uint)*(ushort *)(lVar1 + 0x18 + uVar9 * 0x10);
    pvVar5 = memcpy(param_4 + 3,*(void **)(lVar1 + 0x20 + uVar9 * 0x10),
                    (ulonglong)*(ushort *)(lVar1 + 0x18 + uVar9 * 0x10));
    return CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
  }
LAB_1c000a42d:
  return uVar4 & 0xffffffffffffff00;
}



===== VfsExpandTargetComponent @ 1c000a454 =====

ulonglong VfsExpandTargetComponent
                    (longlong param_1,undefined8 *param_2,longlong param_3,longlong *param_4,
                    undefined4 *param_5,int param_6)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  longlong lStack_10;
  
  local_18 = 0;
  lStack_10 = 0;
  local_30 = 0;
  param_5[2] = 0;
  local_28 = *param_2;
  uStack_20 = param_2[1];
  lVar1 = *param_4;
  if (lVar1 == 0) {
LAB_1c000a511:
    if (local_30 != 0) {
      uVar2 = VfsQueryDirectoryFileName(local_30,&local_18,param_3,param_5,param_6);
      uVar5 = (ulonglong)uVar2;
      if ((0x2b < uVar2 + 0x3ffffff1) ||
         ((0x82000000001U >> ((longlong)(int)(uVar2 + 0x3ffffff1) & 0x3fU) & 1) == 0))
      goto LAB_1c000a5a9;
    }
    if (param_1 != 0) {
      uVar2 = VfsQueryDirectoryFileName(param_1,&local_28,param_3,param_5,param_6);
      uVar5 = (ulonglong)uVar2;
      if ((0x2b < uVar2 + 0x3ffffff1) ||
         ((0x82000000001U >> ((longlong)(int)(uVar2 + 0x3ffffff1) & 0x3fU) & 1) == 0))
      goto LAB_1c000a5a9;
    }
  }
  else {
    uVar3 = VfsGetMappedTarget(param_1,(ushort *)&local_28,'\0',lVar1,&local_18,&local_30);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 != -0x3ffffff3) {
      if ((int)uVar3 < 0) goto LAB_1c000a5a9;
LAB_1c000a507:
      if (param_5[2] != 0) goto LAB_1c000a5a9;
      goto LAB_1c000a511;
    }
    uVar4 = VfsExpandComponentByMapping(lVar1,(ushort *)&local_28,param_3,param_5,param_6);
    if ((char)uVar4 != '\0') {
      uVar5 = 0;
      goto LAB_1c000a507;
    }
  }
  uVar5 = 0xc0000225;
LAB_1c000a5a9:
  if ((local_30 != 0) && (FltObjectDereference(), lStack_10 != 0)) {
    ExFreePoolWithTag(lStack_10,0);
  }
  return uVar5;
}



===== VfsGenerateFileName @ 1c000a600 =====

ulonglong VfsGenerateFileName(undefined8 param_1,longlong param_2,longlong param_3,uint param_4,
                             undefined1 *param_5,undefined8 param_6)

{
  longlong *plVar1;
  longlong lVar2;
  char cVar3;
  int *piVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong *local_40;
  longlong local_38;
  longlong local_30 [3];
  
  local_30[0] = 0;
  local_38 = 0;
  local_40 = (longlong *)0x0;
  local_30[1] = 0;
  local_30[2] = 0;
  *param_5 = 0;
  uVar9 = param_4 & 0xfeffffff;
  if (*(longlong *)(param_2 + 0x18) == 0) {
    uVar9 = FltGetFileNameInformation(param_3,uVar9,&local_40);
LAB_1c000a6bf:
    uVar8 = (ulonglong)uVar9;
    plVar1 = local_40;
    if ((int)uVar9 < 0) goto LAB_1c000a790;
  }
  else {
    cVar3 = VfsDecodeFileObject(param_2,local_30,&local_38);
    lVar2 = local_38;
    if (cVar3 == '\0') {
      if (param_3 == 0) {
        uVar9 = FltGetFileNameInformationUnsafe(param_2,param_1,uVar9,&local_40);
      }
      else {
        uVar9 = FltGetFileNameInformation(param_3,uVar9,&local_40);
      }
      goto LAB_1c000a6bf;
    }
    piVar4 = (int *)0x0;
    uVar7 = *(undefined8 *)(local_38 + 0x30);
    uVar6 = *(undefined8 *)(local_38 + 0x28);
    cVar3 = '\x01';
    if ((*(uint *)(local_38 + 4) & 4) == 0) {
      uVar8 = (ulonglong)*(uint *)(local_38 + 0x20);
      if ((int)*(uint *)(local_38 + 0x20) < 0) goto LAB_1c000a790;
      piVar4 = VfsScbGetMapping(local_30[0]);
      uVar7 = *(undefined8 *)(lVar2 + 0x48);
      uVar6 = *(undefined8 *)(lVar2 + 0x40);
      cVar3 = '\0';
    }
    uVar5 = VfsUnMapFileName(uVar6,uVar7,(longlong)piVar4,uVar9,cVar3,(undefined2 *)(local_30 + 1));
    uVar8 = uVar5 & 0xffffffff;
    if (piVar4 != (int *)0x0) {
      VfsReleaseMappingEntry(piVar4);
    }
    if ((int)uVar5 < 0) goto LAB_1c000a790;
    plVar1 = local_30;
  }
  uVar9 = FltCheckAndGrowNameControl(param_6,(short)plVar1[1]);
  uVar8 = (ulonglong)uVar9;
  if ((-1 < (int)uVar9) &&
     (RtlCopyUnicodeString(param_6,plVar1 + 1), *(longlong *)(param_2 + 0x18) != 0)) {
    *param_5 = 1;
  }
LAB_1c000a790:
  if (local_40 != (longlong *)0x0) {
    FltReleaseFileNameInformation();
  }
  if (local_30[2] != 0) {
    ExFreePoolWithTag(local_30[2],0);
  }
  return uVar8;
}



===== VfsNormalizeNameComponentEx @ 1c000a7f0 =====

int VfsNormalizeNameComponentEx
              (longlong param_1,longlong param_2,ushort *param_3,ushort param_4,undefined8 *param_5,
              undefined4 *param_6,uint param_7,undefined8 param_8,longlong *param_9)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  short sVar7;
  longlong *local_60;
  undefined8 local_58;
  short *psStack_50;
  longlong local_48;
  ushort local_40;
  ushort uStack_3e;
  ushort uStack_3c;
  ushort uStack_3a;
  ushort uStack_38;
  ushort uStack_36;
  ushort uStack_34;
  ushort uStack_32;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_18;
  short *psStack_10;
  
  local_48 = 0;
  local_60 = (longlong *)0x0;
  bVar2 = false;
  if (param_7 < 0x10) {
    return -0x3ffffff3;
  }
  local_40 = *param_3;
  uStack_3e = param_3[1];
  uStack_3c = param_3[2];
  uStack_3a = param_3[3];
  uStack_38 = param_3[4];
  uStack_36 = param_3[5];
  uStack_34 = param_3[6];
  uStack_32 = param_3[7];
  local_30 = *param_5;
  uStack_28 = param_5[1];
  if (param_4 < local_40) {
    psStack_50 = (short *)((ulonglong)param_4 + *(longlong *)(param_3 + 4));
    sVar7 = local_40 - param_4;
    local_58 = (ulonglong)CONCAT22(sVar7,sVar7);
  }
  else {
    psStack_50 = (short *)0x0;
    local_58 = 0;
    sVar7 = 0;
  }
  local_18 = local_58;
  psStack_10 = psStack_50;
  if ((sVar7 != 2) || (bVar1 = true, *psStack_50 != 0x5c)) {
    bVar1 = false;
  }
  if ((!bVar1) && (cVar3 = VfsDecodeFileObject(param_2,&local_48,&local_58), cVar3 != '\0')) {
    if ((longlong *)*param_9 == (longlong *)0x0) {
      uVar5 = VfsCreateNameNormalizationContext
                        (&local_40,param_4,local_48 + 0x98,local_48 + 0xdc,&local_60);
      iVar4 = (int)uVar5;
      if (iVar4 < 0) goto LAB_1c000a9a1;
      bVar2 = true;
    }
    else {
      local_60 = (longlong *)*param_9;
    }
    uVar6 = VfsExpandTargetComponent
                      (param_1,(undefined8 *)&local_40,(longlong)&local_30,local_60,param_6,param_7)
    ;
    iVar4 = (int)uVar6;
    if (iVar4 != -0x3ffffddb) goto LAB_1c000a9a1;
  }
  iVar4 = VfsQueryDirectoryFileName(param_1,&local_40,&local_30,param_6,param_7);
LAB_1c000a9a1:
  if ((local_60 != (longlong *)0x0) && (bVar2)) {
    if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3ffffff1)) {
      if ((int *)*local_60 != (int *)0x0) {
        VfsReleaseMappingEntry((int *)*local_60);
      }
      ExFreeToPagedLookasideList(&DAT_1c001f900,local_60);
    }
    else {
      *param_9 = (longlong)local_60;
    }
  }
  return iVar4;
}



===== VfsNormalizeNameContextCleanup @ 1c000aa10 =====

void VfsNormalizeNameContextCleanup(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    if ((int *)*param_1 != (int *)0x0) {
      VfsReleaseMappingEntry((int *)*param_1);
    }
    ExFreeToPagedLookasideList(&DAT_1c001f900,param_1);
  }
  return;
}



===== VfsUnMapFileName @ 1c000aa50 =====

/* WARNING: Removing unreachable block (ram,0x0001c000ab24) */

ulonglong VfsUnMapFileName(undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 param_4
                          ,char param_5,undefined2 *param_6)

{
  undefined2 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = FltGetFileNameInformationUnsafe(param_2,param_1,param_4);
  uVar1 = uRam0000000000000008;
  if (-1 < (int)uVar2) {
    if ((param_5 == '\0') && (param_3 != 0)) {
      uVar2 = VfsUnMapName(param_3,(short *)0x8,(char)param_4 == '\x03','\0',param_6);
      uVar2 = uVar2 & 0xffffffff;
    }
    else {
      lVar3 = ExAllocatePool2(0x100,uRam0000000000000008,0x74534656);
      *(longlong *)(param_6 + 4) = lVar3;
      if (lVar3 == 0) {
        uVar2 = 0xc000009a;
      }
      else {
        *param_6 = 0;
        param_6[1] = uVar1;
        uVar2 = 0;
        RtlCopyUnicodeString(param_6,8);
      }
    }
  }
  return uVar2;
}



===== VfsPostCleanup @ 1c000ab50 =====

undefined8 VfsPostCleanup(longlong param_1,undefined8 param_2,longlong *param_3,ulonglong param_4)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  undefined8 local_res18 [2];
  
  if ((param_4 & 1) == 0) {
    lVar2 = *(longlong *)(param_1 + 0x10);
    uVar3 = (ulonglong)*(uint *)(*param_3 + 4);
    if ((*(uint *)(*param_3 + 4) & 2) == 0) {
      uVar3 = *(ulonglong *)(lVar2 + 8);
      local_res18[0] = 0;
      iVar1 = FltQueryInformationFile(*(undefined8 *)(lVar2 + 0x10),uVar3,local_res18,8,6,0);
      if (iVar1 != -0x3ffffedd) goto LAB_1c000abd4;
      lVar2 = *(longlong *)(param_1 + 0x10);
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    VfsMarkFileDeleted(*(undefined8 *)(lVar2 + 0x10),uVar3,param_3 + 1,cVar4,'\x01');
  }
LAB_1c000abd4:
  VfsDeleteCleanupCompletionContext(param_3);
  return 0;
}



===== VfsPostCreate @ 1c000ac00 =====

undefined8 VfsPostCreate(longlong param_1,longlong param_2,uint *param_3,byte param_4)

{
  if ((param_4 & 1) == 0) {
    VfsCreateCompletion(param_1,param_2,param_3);
  }
  else {
    VfsDeleteCreateCompletionContext((longlong)param_3);
  }
  return 0;
}



===== VfsPostReadWrite @ 1c000ac30 =====

undefined4 VfsPostReadWrite(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  if ((lVar1 != 0) && (param_3 != 0)) {
    if (*(longlong *)(lVar1 + 0x28) != *(longlong *)(param_3 + 0x28)) {
      *(longlong *)(lVar1 + 0x28) = *(longlong *)(param_3 + 0x28);
    }
    if (((*(uint *)(param_3 + 0x50) & 2) != 0) && ((**(uint **)(param_1 + 0x10) & 2) == 0)) {
      *(undefined8 *)(lVar1 + 0x68) = *(undefined8 *)(param_3 + 0x68);
    }
    if ((*(char *)(*(longlong *)(param_1 + 0x10) + 4) == '\x04') && (-1 < *(int *)(param_1 + 0x18)))
    {
      FltDoCompletionProcessingWhenSafe(param_1);
    }
  }
  return 0;
}



===== VfsPostSetInformation @ 1c000acc0 =====

undefined8 VfsPostSetInformation(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0x20);
  if (lVar2 == 0) {
    return 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (iVar1 != 0xd) {
    if (iVar1 == 0xe) {
      *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(param_3 + 0x68);
      return 0;
    }
    if (((iVar1 == 0x13) || (iVar1 == 0x14)) || (iVar1 == 0x27)) {
      VfsUpdateFileSizes(param_3,lVar2);
      return 0;
    }
    if (iVar1 != 0x40) {
      return 0;
    }
  }
  *(undefined1 *)(lVar2 + 0x49) = *(undefined1 *)(param_3 + 0x49);
  return 0;
}



===== VfsPreClose @ 1c000ad30 =====

undefined8 VfsPreClose(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 uVar2;
  longlong local_res10 [2];
  longlong local_res20;
  
  local_res20 = 0;
  local_res10[0] = 0;
  cVar1 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),&local_res20,local_res10);
  if (cVar1 == '\0') {
    uVar2 = 1;
  }
  else {
    VfsProcessClose(*(longlong *)(param_2 + 0x20),local_res20,local_res10[0]);
    *(undefined4 *)(param_1 + 0x18) = 0;
    uVar2 = 4;
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  return uVar2;
}



===== VfsPreFsControl @ 1c000ada0 =====

ulonglong VfsPreFsControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 local_res8;
  undefined8 local_res20;
  
  lVar5 = *(longlong *)(param_1 + 0x10);
  if ((*(byte *)(lVar5 + 5) & 0xfb) != 0) goto LAB_1c000ae1e;
  uVar1 = *(uint *)(lVar5 + 0x28);
  if (uVar1 < 0x900a5) {
    if (uVar1 != 0x900a4) {
      if (uVar1 < 0x90015) {
        if (((uVar1 != 0x90014) && (uVar1 != 0x90000)) &&
           ((uVar1 != 0x90004 && (((uVar1 != 0x90008 && (uVar1 != 0x9000c)) && (uVar1 != 0x90010))))
           )) goto LAB_1c000ae1e;
      }
      else if ((uVar1 != 0x90050) && (uVar1 != 0x9005c)) {
        if (uVar1 != 0x90074) {
          iVar3 = uVar1 - 0x90098;
          goto LAB_1c000aefb;
        }
        local_res20 = 0;
        cVar2 = FltIs32bitProcess(param_1);
        if (cVar2 == '\0') {
          if (0x1f < *(uint *)(lVar5 + 0x20)) {
            lVar5 = **(longlong **)(lVar5 + 0x30);
            goto LAB_1c000ae9f;
          }
        }
        else if (0x1f < *(uint *)(lVar5 + 0x20)) {
          lVar5 = (longlong)**(int **)(lVar5 + 0x30);
LAB_1c000ae9f:
          local_res8 = (ulonglong)local_res8._4_4_ << 0x20;
          if ((lVar5 == 0) ||
             (cVar2 = VfsDecodeFileHandle(lVar5,*(undefined1 *)(param_1 + 0x50),(int *)&local_res8,
                                          &local_res20), cVar2 == '\0')) goto LAB_1c000aec5;
          *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
          goto LAB_1c000ae91;
        }
        *(undefined4 *)(param_1 + 0x18) = 0xc0000023;
        goto LAB_1c000ae91;
      }
LAB_1c000af6d:
      local_res8 = 0;
      cVar2 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),&local_res20,&local_res8);
      if ((cVar2 == '\0') || ((*(uint *)(local_res8 + 4) & 4) == 0)) goto LAB_1c000aec5;
      *(undefined4 *)(param_1 + 0x18) = 0xc00000e2;
      goto LAB_1c000ae91;
    }
  }
  else if (uVar1 < 0x900fd) {
    if (uVar1 == 0x900fc) {
      uVar4 = VfsMarkHandle(param_1,param_2);
      return uVar4;
    }
    if (((uVar1 != 0x900ac) && (uVar1 != 0x900bc)) && (uVar1 != 0x900c4)) {
      iVar3 = uVar1 - 0x900d7;
LAB_1c000aefb:
      if ((iVar3 != 0) && (iVar3 != 8)) {
LAB_1c000ae1e:
        uVar4 = VfsPreRedirect(param_1,param_2);
        return uVar4;
      }
    }
  }
  else {
    if (uVar1 == 0x90240) goto LAB_1c000af6d;
    if (((uVar1 != 0x9040c) && (uVar1 != 0x980c8)) && (uVar1 != 0x9c040)) goto LAB_1c000ae1e;
  }
  local_res8 = 0;
  cVar2 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),&local_res20,&local_res8);
  if ((cVar2 == '\0') || ((*(uint *)(local_res8 + 4) & 4) == 0)) {
LAB_1c000aec5:
    uVar4 = VfsPreRedirect(param_1,param_2);
    return uVar4 & 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
LAB_1c000ae91:
  *(undefined8 *)(param_1 + 0x20) = 0;
  return 4;
}



===== VfsPreSetSecurity @ 1c000afb0 =====

ulonglong VfsPreSetSecurity(uint *param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  byte bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  uVar3 = 1;
  cVar1 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),(undefined8 *)0x0,(undefined8 *)0x0);
  if (cVar1 != '\0') {
    bVar2 = VfsWriteWorker(param_1,param_2,param_3,'\0','\0');
    uVar3 = CONCAT71(extraout_var,bVar2) & 0xffffffff;
  }
  return uVar3;
}



===== VfsPreNetworkQueryOpen @ 1c000b020 =====

int VfsPreNetworkQueryOpen(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  cVar2 = VfsDecodeFileObject(lVar1,(undefined8 *)0x0,(undefined8 *)0x0);
  if (cVar2 == '\0') {
    iVar3 = (-(uint)(*(longlong *)(lVar1 + 0x18) != 0) & 0xfffffffe) + 3;
  }
  else {
    iVar3 = 3;
  }
  return iVar3;
}



===== VfsPreQueryInformation @ 1c000b060 =====

void VfsPreQueryInformation(longlong param_1,longlong param_2,ulonglong param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if ((iVar1 == 9) || (iVar1 == 0x12)) {
    VfsProcessQueryInfoName(param_1,param_2,param_3);
  }
  else {
    VfsPreRedirect(param_1,param_2);
  }
  return;
}



===== VfsPreRead @ 1c000b090 =====

undefined8 VfsPreRead(longlong param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 1;
  cVar1 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),(undefined8 *)0x0,(undefined8 *)0x0);
  if (cVar1 != '\0') {
    iVar2 = VfsRedirectIo(param_1,*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x20));
    if (iVar2 < 0) {
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar3 = 4;
      *(int *)(param_1 + 0x18) = iVar2;
    }
    else {
      uVar3 = 0;
      *param_3 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8);
    }
  }
  return uVar3;
}



===== VfsPreRedirect @ 1c000b120 =====

undefined8 VfsPreRedirect(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  longlong local_res10 [2];
  undefined8 local_res20;
  
  local_res10[0] = 0;
  cVar1 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),&local_res20,local_res10);
  if (cVar1 != '\0') {
    if (((*(char *)(*(longlong *)(param_1 + 0x10) + 4) + 0x11U & 0xfb) == 0) &&
       ((*(uint *)(local_res10[0] + 4) & 4) != 0)) {
      return 3;
    }
    iVar2 = VfsRedirectIo(param_1,local_res10[0]);
    if (iVar2 < 0) {
      *(undefined8 *)(param_1 + 0x20) = 0;
      *(int *)(param_1 + 0x18) = iVar2;
      return 4;
    }
  }
  return 1;
}



===== VfsPreReleaseForSectionSynchronization @ 1c000b1a0 =====

undefined8 VfsPreReleaseForSectionSynchronization(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar5 = 1;
  cVar3 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),(undefined8 *)0x0,(undefined8 *)0x0);
  if (cVar3 != '\0') {
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x20);
    if (*(longlong *)(lVar2 + 0x58) != 0) {
      LOCK();
      lVar1 = *(longlong *)(lVar2 + 0x58);
      *(longlong *)(lVar2 + 0x58) = 0;
      UNLOCK();
      if (lVar1 != 0) {
        ZwClose();
      }
    }
    iVar4 = VfsRedirectIo(param_1,lVar2);
    if (iVar4 < 0) {
      *(undefined8 *)(param_1 + 0x20) = 0;
      uVar5 = 4;
      *(int *)(param_1 + 0x18) = iVar4;
    }
  }
  return uVar5;
}



===== VfsDelayedCopy @ 1c000b228 =====

ulonglong VfsDelayedCopy(uint *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  ulonglong uVar4;
  longlong lVar5;
  ushort *puVar6;
  ushort *puVar7;
  longlong local_res20;
  uint7 in_stack_ffffffffffffff91;
  longlong local_50;
  int *local_48;
  ushort local_40 [4];
  longlong lStack_38;
  
  piVar3 = (int *)0x0;
  local_48 = (int *)0x0;
  local_res20 = 0;
  local_50 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  lStack_38 = 0;
  uVar2 = VfsGetFileNameInfoForFileObject
                    (param_1,*(longlong *)(param_3 + 0x30),*(undefined8 *)(param_3 + 0x28),0x101,
                     &local_res20);
  uVar4 = uVar2 & 0xffffffff;
  lVar5 = 0;
  if ((int)uVar2 < 0) {
    LogWrite(1,0,
             L"VfsDelayedCopy() - Failed to get filename info for fileobject: %p\n IRP: %d\n Status: 0x%08X"
             ,*(undefined8 *)(param_3 + 0x48));
  }
  else {
    piVar3 = VfsScbGetMapping(param_2);
    local_48 = piVar3;
    if (piVar3 != (int *)0x0) {
      puVar7 = (ushort *)(local_res20 + 8);
      uVar2 = VfsGetMappedTarget(*(longlong *)(*(longlong *)(param_1 + 4) + 0x10),puVar7,'\0',
                                 (longlong)piVar3,(undefined8 *)local_40,&local_50);
      lVar5 = local_50;
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        LogWrite(1,0,
                 L"VfsDelayedCopy() - Failed to map filename: %wZ%\n for mapping: %wZ\n Status: 0x%08X"
                 ,puVar7);
        lVar5 = local_50;
      }
      else {
        puVar6 = local_40;
        uVar2 = VfsCreateParentDirectories
                          (*(undefined8 *)(param_3 + 0x28),local_50,(longlong)piVar3,puVar6,
                           *(ushort *)(piVar3 + 6));
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) {
          LogWrite(1,0,
                   L"VfsDelayedCopy() - Failed to create parent directories for %wZ\n Status: 0x%08X"
                   ,local_40);
        }
        else {
          uVar1 = VfsCowCopyFileForScb
                            (param_2,0,*(undefined8 *)(param_3 + 0x28),puVar6,puVar7,lVar5,0,
                             local_40,'\x01',(ulonglong)in_stack_ffffffffffffff91 << 8,
                             (undefined1 *)0x0);
          uVar4 = (ulonglong)uVar1;
          if ((-1 < (int)uVar1) && ((int)*(uint *)(param_3 + 0x20) < 0)) {
            uVar4 = (ulonglong)*(uint *)(param_3 + 0x20);
          }
        }
      }
    }
  }
  if (piVar3 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar3);
  }
  if (local_res20 != 0) {
    FltReleaseFileNameInformation();
  }
  if ((lVar5 != 0) && (FltObjectDereference(lVar5), lStack_38 != 0)) {
    ExFreePoolWithTag(lStack_38,0);
  }
  return uVar4;
}



===== VfsRedirectIo @ 1c000b448 =====

int VfsRedirectIo(longlong param_1,longlong param_2)

{
  int iVar1;
  char local_res10 [24];
  
  if ((*(uint *)(param_2 + 4) & 4) == 0) {
    if (*(int *)(param_2 + 0x20) < 0) {
      return *(int *)(param_2 + 0x20);
    }
    local_res10[0] = '\0';
    if ((*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10) != *(longlong *)(param_2 + 0x40)) &&
       ((iVar1 = FltIsIoRedirectionAllowedForOperation
                           (param_1,*(longlong *)(param_2 + 0x40),local_res10,0), iVar1 < 0 ||
        (local_res10[0] == '\0')))) {
      return -0x3fffffff;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = *(undefined8 *)(param_2 + 0x48);
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10) = *(undefined8 *)(param_2 + 0x40);
  }
  else {
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8) = *(undefined8 *)(param_2 + 0x30);
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10) = *(undefined8 *)(param_2 + 0x28);
  }
  FltSetCallbackDataDirty(param_1);
  return 0;
}



===== VfsUpdateFileSizesWorker @ 1c000b500 =====

undefined8 VfsUpdateFileSizesWorker(undefined8 param_1,longlong param_2,longlong param_3)

{
  VfsUpdateFileSizes(param_3,*(longlong *)(param_2 + 0x20));
  return 0;
}



===== VfsWriteWorker @ 1c000b520 =====

byte VfsWriteWorker(uint *param_1,longlong param_2,undefined8 *param_3,char param_4,char param_5)

{
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x20);
  if ((*(uint *)(lVar1 + 4) & 4) != 0) {
    uVar3 = VfsDelayedCopy(param_1,*(longlong *)(*(longlong *)(param_2 + 0x20) + 0x18),lVar1);
    if ((int)(uint)uVar3 < 0) {
      LogWrite(1,0,L"VfsWriteWorker() - Failed to delay copy file. Status: 0x%08X",
               uVar3 & 0xffffffff);
      param_1[8] = 0;
      param_1[9] = 0;
      param_1[6] = (uint)uVar3;
      return 4;
    }
  }
  *(undefined8 *)(*(longlong *)(param_1 + 4) + 8) = *(undefined8 *)(lVar1 + 0x48);
  *(undefined8 *)(*(longlong *)(param_1 + 4) + 0x10) = *(undefined8 *)(lVar1 + 0x40);
  FltSetCallbackDataDirty(param_1);
  if (param_4 == '\0') {
    bVar2 = 1;
  }
  else {
    bVar2 = -(param_5 != '\0') & 5;
    *param_3 = *(undefined8 *)(*(longlong *)(param_1 + 4) + 8);
  }
  return bVar2;
}



===== VfsCheckPackageDirectoryForRename @ 1c000b5f0 =====

uint VfsCheckPackageDirectoryForRename(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x18) + 0x110);
  if ((uVar1 & 2) == 0) {
    return 0;
  }
  if ((*(uint *)(param_2 + 4) & 4) == 0) {
    return -(uint)((uVar1 & 4) != 0) & 0xc00000bb;
  }
  return 0xc00000bb;
}



===== VfsCheckPackageFileForDelete @ 1c000b628 =====

int VfsCheckPackageFileForDelete
              (ulonglong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
              undefined4 *param_5,longlong param_6,longlong param_7)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  bool bVar5;
  ulonglong local_res8;
  int local_54 [3];
  longlong local_48;
  longlong local_40;
  longlong local_38 [6];
  
  local_48 = 0;
  local_38[0] = 0;
  local_40 = 0;
  local_res8 = param_1;
  iVar3 = VfsOpenScb(param_2,param_3,param_4,'\x01',param_5,param_6,&local_48,local_38,&local_40);
  lVar1 = local_48;
  if (iVar3 < 0) goto LAB_1c000b7c6;
  if (local_48 == 0) {
LAB_1c000b6db:
    local_res8 = local_res8 & 0xffffffffffffff00;
    iVar3 = FltIsDirectory(local_40,param_2,&local_res8);
    if (iVar3 < 0) goto LAB_1c000b7c6;
    bVar5 = (char)local_res8 == '\0';
LAB_1c000b6d7:
    if (bVar5) {
      if (*(longlong *)(param_7 + 0x50) != 0) {
        local_38[1] = 0;
        local_38[2] = 0;
        local_38[3] = 0;
        local_38[4] = 0;
        local_54[0] = 0;
        local_54[1] = 0;
        SeCaptureSubjectContext(local_38 + 1);
        uVar4 = IoGetFileObjectGenericMapping();
        cVar2 = SeAccessCheck(*(undefined8 *)(param_7 + 0x50),local_38 + 1,0,0x10000,
                              (ulonglong)param_5 & 0xffffffff00000000,0,uVar4,1,local_54 + 1,
                              local_54);
        SeReleaseSubjectContext(local_38 + 1);
        if (cVar2 == '\0') {
          iVar3 = local_54[0];
        }
      }
      goto LAB_1c000b7c6;
    }
  }
  else if (*(int *)(local_48 + 0x118) == 0) {
    if (local_48 == 0) goto LAB_1c000b6db;
    bVar5 = (*(uint *)(local_48 + 0x110) & 2) == 0;
    goto LAB_1c000b6d7;
  }
  iVar3 = -0x3fffffde;
LAB_1c000b7c6:
  if (lVar1 != 0) {
    VfsScbClose(lVar1);
  }
  if (local_40 != 0) {
    ObfDereferenceObject();
  }
  if (local_38[0] != 0) {
    FltClose();
  }
  return iVar3;
}



===== VfsCheckSimpleTargetForRename @ 1c000b820 =====

ulonglong VfsCheckSimpleTargetForRename
                    (uint *param_1,longlong param_2,longlong *param_3,undefined8 *param_4,
                    uint *param_5)

{
  undefined8 uVar1;
  bool bVar2;
  undefined2 uVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  ulonglong uVar7;
  int *piVar8;
  longlong lVar9;
  ulonglong uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  longlong *plVar14;
  wchar_t *pwVar15;
  undefined8 uVar16;
  undefined8 *puVar17;
  bool bVar18;
  undefined8 local_110;
  longlong lStack_108;
  undefined8 local_100;
  longlong lStack_f8;
  uint local_f0;
  uint local_ec;
  longlong local_e8;
  uint local_e0;
  byte *local_d8;
  uint local_d0 [2];
  longlong local_c8 [2];
  undefined8 local_b8;
  byte *pbStack_b0;
  longlong local_a8 [2];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  longlong local_78;
  int *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  byte *pbStack_50;
  ulonglong local_48;
  byte *pbStack_40;
  
  local_d8 = *(byte **)(*(longlong *)(param_1 + 4) + 0x38);
  local_a8[0] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_110 = 0;
  lStack_108 = 0;
  local_e8 = 0;
  local_100 = 0;
  lStack_f8 = 0;
  local_c8[0] = 0;
  piVar8 = (int *)0x0;
  local_70 = (int *)0x0;
  local_d0[0] = 0;
  bVar2 = false;
  *param_3 = 0;
  param_4[1] = 0;
  pbStack_b0 = local_d8 + 0x14;
  local_b8 = (ulonglong)CONCAT22(*(undefined2 *)(local_d8 + 0x10),*(undefined2 *)(local_d8 + 0x10));
  bVar18 = (*(uint *)(param_2 + 4) & 4) == 0;
  if (bVar18) {
    uVar1 = *(undefined8 *)(param_2 + 0x40);
    lVar9 = *(longlong *)(param_2 + 0x48);
  }
  else {
    uVar1 = *(undefined8 *)(param_2 + 0x28);
    lVar9 = *(longlong *)(param_2 + 0x30);
  }
  uVar16 = 0x101;
  uVar7 = VfsGetFileNameInfoForFileObject(param_1,lVar9,uVar1,0x101,local_a8);
  uVar10 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) {
    plVar14 = (longlong *)(param_2 + 0x30);
    if (bVar18) {
      plVar14 = (longlong *)(param_2 + 0x48);
    }
    puVar17 = (undefined8 *)*plVar14;
    pwVar15 = 
    L"VfsCheckSimpleTargetForRename() - Failed to get filename info for fileobject: %p\n IRP: %d\n Status: 0x%08X"
    ;
LAB_1c000b942:
    LogWrite(1,0,pwVar15,puVar17);
    goto LAB_1c000be86;
  }
  local_78 = *(longlong *)(local_a8[0] + 0x10);
  uVar11 = *(short *)(local_a8[0] + 8) - *(short *)(local_a8[0] + 0x58);
  local_68._0_4_ = CONCAT22(uVar11,uVar11);
  uStack_60 = local_78;
  cVar4 = RtlEqualUnicodeString();
  if (cVar4 != '\0') goto LAB_1c000be86;
  piVar8 = VfsScbGetMapping(*(longlong *)(param_2 + 0x18));
  uVar6 = local_98;
  local_70 = piVar8;
  if (piVar8 == (int *)0x0) {
    if (*(longlong *)(*(longlong *)(param_1 + 4) + 0x10) == *(longlong *)(param_2 + 0x40)) {
      bVar5 = *local_d8;
      if (*(int *)(*(longlong *)(param_1 + 4) + 0x20) != 10) {
        bVar5 = bVar5 & 1;
      }
      uVar6 = VfsRenameFile(*(longlong *)(param_2 + 0x40),*(longlong *)(param_2 + 0x48),0,
                            (ushort *)&local_b8,bVar5);
      uVar10 = (ulonglong)uVar6;
    }
    else {
      uVar10 = 0xc00000e5;
    }
    goto LAB_1c000be86;
  }
  lVar9 = (ulonglong)(uVar11 >> 1) * 2;
  local_98._2_2_ = (undefined2)((ulonglong)local_68 >> 0x10);
  uVar3 = local_98._2_2_;
  if (bVar18) {
    local_88 = (uint)local_68;
    uStack_84 = local_68._4_4_;
    uStack_80 = (undefined4)uStack_60;
    uStack_7c = uStack_60._4_4_;
    local_48 = local_b8;
    pbStack_40 = pbStack_b0;
    local_ec = (uint)(*(short *)(lVar9 + -2 + local_78) == 0x5c);
    if (*(short *)pbStack_b0 == 0x5c) {
      local_ec = local_ec + 1;
    }
    if (local_ec == 2) {
      local_88 = CONCAT22(local_98._2_2_,uVar11 - 2);
      local_ec = 1;
    }
    uVar12 = local_ec;
    if (local_ec == 0) {
      uVar13 = (ushort)local_b8 + 2 + (local_88 & 0xffff);
    }
    else {
      uVar13 = (local_88 & 0xffff) + (uint)(ushort)local_b8;
    }
    local_d8 = (byte *)CONCAT44((int)((ulonglong)local_d8 >> 0x20),uVar13);
    local_98 = uVar6;
    if (uVar13 < 0xffff) {
      lStack_108 = ExAllocatePool2(0x100,uVar13 & 0xffff,0x74534656);
      if (lStack_108 != 0) {
        uVar7 = (ulonglong)local_110 >> 0x20;
        local_110._0_4_ = uVar13 << 0x10;
        local_110 = CONCAT44((int)uVar7,(int)local_110);
        uVar11 = 0;
        if ((ushort)local_88 != 0) {
          RtlCopyUnicodeString(&local_110,&local_88);
          uVar11 = (ushort)local_88;
        }
        if (uVar12 == 0) {
          *(undefined2 *)(lStack_108 + (ulonglong)(uVar11 >> 1) * 2) = 0x5c;
          local_110 = CONCAT62(local_110._2_6_,(ushort)local_110 + 2);
        }
        RtlAppendUnicodeStringToString(&local_110);
        uVar6 = FltObjectReference(*(undefined8 *)(param_2 + 0x40));
        uVar10 = (ulonglong)uVar6;
        lVar9 = *(longlong *)(param_2 + 0x40);
        if ((int)uVar6 < 0) {
          LogWrite(1,0,
                   L"VfsCheckSimpleTargetForRename() - Failed to reference instance: %p\n Status: 0x%08X"
                   ,lVar9);
          goto LAB_1c000be86;
        }
        local_e8 = lVar9;
        uVar7 = VfsGetUnMappedSource
                          (lVar9,(short *)&local_110,(longlong)piVar8,uVar16,&local_100,local_c8);
        uVar10 = uVar7 & 0xffffffff;
        if ((int)uVar7 < 0) goto LAB_1c000be86;
        bVar2 = true;
        goto LAB_1c000bdcf;
      }
      goto LAB_1c000be7d;
    }
  }
  else {
    local_98 = (uint)local_68;
    uStack_94 = local_68._4_4_;
    uStack_90 = (undefined4)uStack_60;
    uStack_8c = uStack_60._4_4_;
    local_58 = local_b8;
    pbStack_50 = pbStack_b0;
    local_f0 = (uint)(*(short *)(lVar9 + -2 + local_78) == 0x5c);
    if (*(short *)pbStack_b0 == 0x5c) {
      local_f0 = local_f0 + 1;
    }
    if (local_f0 == 2) {
      local_98 = CONCAT22(uVar3,uVar11 - 2);
      local_f0 = 1;
    }
    uVar6 = local_f0;
    if (local_f0 == 0) {
      uVar12 = (ushort)local_b8 + 2 + (local_98 & 0xffff);
    }
    else {
      uVar12 = (local_98 & 0xffff) + (uint)(ushort)local_b8;
    }
    local_e0 = uVar12;
    if (uVar12 < 0xffff) {
      lStack_f8 = ExAllocatePool2(0x100);
      if (lStack_f8 != 0) {
        uVar7 = (ulonglong)local_100 >> 0x20;
        local_100._0_4_ = uVar12 << 0x10;
        local_100 = CONCAT44((int)uVar7,(int)local_100);
        uVar11 = 0;
        if ((ushort)local_98 != 0) {
          RtlCopyUnicodeString(&local_100,&local_98);
          uVar11 = (ushort)local_98;
        }
        if (uVar6 == 0) {
          *(undefined2 *)(lStack_f8 + (ulonglong)(uVar11 >> 1) * 2) = 0x5c;
          local_100 = CONCAT62(local_100._2_6_,(ushort)local_100 + 2);
        }
        RtlAppendUnicodeStringToString(&local_100,&local_58);
        local_c8[0] = *(longlong *)(param_2 + 0x28);
        uVar7 = VfsGetMappedTarget(local_c8[0],(ushort *)&local_100,'\0',(longlong)piVar8,&local_110
                                   ,&local_e8);
        uVar10 = uVar7 & 0xffffffff;
        if ((int)uVar7 < 0) {
          puVar17 = &local_100;
          pwVar15 = 
          L"VfsCheckSimpleTargetForRename() - Failed to map filename: %wZ\n for mapping: %wZ\n Status: 0x%08X"
          ;
          goto LAB_1c000b942;
        }
LAB_1c000bdcf:
        lVar9 = local_e8;
        uVar7 = VfsCheckTargetForRename
                          ((longlong)param_1,local_c8[0],0,(ushort *)&local_100,local_e8,0,
                           (ushort *)&local_110,(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0xdc)
                           ,*(longlong *)(param_2 + 0x18) + 0x98,(longlong)piVar8,local_d0);
        uVar10 = uVar7 & 0xffffffff;
        if (-1 < (int)uVar7) {
          *param_3 = lVar9;
          *param_4 = local_110;
          param_4[1] = lStack_108;
          *param_5 = local_d0[0];
          local_e8 = 0;
          lStack_108 = 0;
        }
        goto LAB_1c000be86;
      }
LAB_1c000be7d:
      uVar10 = 0xc000009a;
      goto LAB_1c000be86;
    }
  }
  uVar10 = 0xc0000106;
LAB_1c000be86:
  if (local_a8[0] != 0) {
    FltReleaseFileNameInformation();
  }
  if ((bVar2) && (local_c8[0] != 0)) {
    FltObjectDereference();
  }
  if (local_e8 != 0) {
    FltObjectDereference(local_e8);
  }
  if (lStack_108 != 0) {
    ExFreePoolWithTag();
    lStack_108 = 0;
  }
  if (lStack_f8 != 0) {
    ExFreePoolWithTag();
    lStack_f8 = 0;
  }
  if (piVar8 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar8);
  }
  return uVar10;
}



===== VfsCheckTargetForRename @ 1c000bf4c =====

ulonglong VfsCheckTargetForRename
                    (longlong param_1,longlong param_2,undefined8 param_3,ushort *param_4,
                    longlong param_5,undefined8 param_6,ushort *param_7,undefined4 *param_8,
                    longlong param_9,longlong param_10,uint *param_11)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined4 extraout_var;
  uint uVar8;
  ushort uVar9;
  short sVar10;
  ushort uVar11;
  uint local_res8 [2];
  undefined8 local_38;
  longlong lStack_30;
  
  local_res8[0] = 0;
  pbVar1 = *(byte **)(*(longlong *)(param_1 + 0x10) + 0x38);
  local_38 = 0;
  lStack_30 = 0;
  if ((param_2 == 0) && (param_5 == 0)) {
    uVar6 = 0xc000000d;
  }
  else {
    uVar6 = VfsCowQueryFile(param_2,param_3,param_4,(undefined4 *)0x0,0,param_5,param_6,param_7,
                            local_res8);
    uVar3 = local_res8[0];
    if (-1 < (int)uVar6) {
      if ((local_res8[0] >> 10 & 1) == 0) {
        uVar9 = *param_7 >> 1;
        if (uVar9 != 0) {
          uVar2 = uVar9;
          do {
            uVar11 = uVar2 - 1;
            sVar10 = *(short *)(*(longlong *)(param_7 + 4) + (ulonglong)uVar11 * 2);
            if (sVar10 == 0x5c) break;
            if (sVar10 == 0x3a) {
              uVar9 = uVar2;
            }
            else if (sVar10 == 0x2e) {
              sVar10 = (uVar9 - uVar11) * 2 + -2;
              local_38 = CONCAT62(CONCAT42(local_38._4_4_,sVar10),sVar10);
              lStack_30 = *(longlong *)(param_7 + 4) + 2 + (ulonglong)uVar11 * 2;
              uVar7 = VfsIsExcludedExtension(&local_38);
              if ((char)uVar7 != '\0') goto LAB_1c000c10b;
              break;
            }
            uVar2 = uVar11;
          } while (uVar11 != 0);
        }
        uVar8 = uVar3 >> 6 & 1;
        if (((uVar8 != 0) || ((char)uVar3 < '\0')) && ((uVar3 >> 9 & 1) == 0)) {
          bVar4 = *pbVar1;
          if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x20) != 10) {
            bVar4 = bVar4 & 1;
          }
          if (bVar4 == 0) {
            return 0xc0000035;
          }
          if ((uVar8 != 0) && (-1 < (char)uVar3)) {
            iVar5 = VfsCheckPackageFileForDelete
                              ((ulonglong)uVar8,param_2,param_3,(longlong)param_4,param_8,param_9,
                               param_10);
            if (iVar5 < 0) {
              return CONCAT44(extraout_var,iVar5);
            }
          }
        }
        *param_11 = uVar3;
        uVar6 = 0;
      }
      else {
LAB_1c000c10b:
        uVar6 = 0xc0000022;
      }
    }
  }
  return uVar6;
}



===== VfsCheckVirtualTargetForRename @ 1c000c138 =====

void VfsCheckVirtualTargetForRename
               (longlong param_1,longlong param_2,longlong param_3,longlong param_4,uint *param_5)

{
  VfsCheckTargetForRename
            (param_1,*(longlong *)(param_3 + 0x28),*(undefined8 *)(param_3 + 0x38),
             (ushort *)(param_2 + 0x58),*(longlong *)(param_3 + 0x40),
             *(undefined8 *)(param_3 + 0x50),(ushort *)(param_2 + 0x58),
             (undefined4 *)(*(longlong *)(param_3 + 0x18) + 0xdc),
             *(longlong *)(param_3 + 0x18) + 0x98,param_4,param_5);
  return;
}



===== VfsCreateStoreForRename @ 1c000c1a8 =====

ulonglong VfsCreateStoreForRename
                    (uint *param_1,longlong param_2,longlong param_3,longlong *param_4,
                    undefined8 *param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  longlong local_res20;
  longlong local_50;
  undefined8 local_48;
  ushort local_40 [4];
  longlong lStack_38;
  
  puVar1 = param_5;
  local_50 = 0;
  local_res20 = 0;
  local_48 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  lStack_38 = 0;
  *param_4 = 0;
  *param_5 = 0;
  uVar3 = VfsGetFileNameInfoForFileObject
                    (param_1,*(longlong *)(param_2 + 0x30),*(undefined8 *)(param_2 + 0x28),0x101,
                     &local_50);
  lVar5 = local_50;
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    LogWrite(1,0,
             L"VfsCreateStoreForRename() - Failed to get filename info for fileobject: %p\n IRP: %d\n Status: 0x%08X"
             ,*(undefined8 *)(param_2 + 0x30));
    lVar5 = local_50;
    lVar6 = 0;
  }
  else {
    uVar3 = VfsGetMappedTarget(*(longlong *)(param_2 + 0x28),(ushort *)(local_50 + 8),'\0',param_3,
                               (undefined8 *)local_40,&local_res20);
    lVar6 = local_res20;
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      LogWrite(1,0,
               L"VfsCreateStoreForRename() - Failed to map filename: %wZ\n for mapping: %wZ\n Status: 0x%08X"
               ,lVar5 + 8);
      lVar6 = local_res20;
    }
    else {
      uVar3 = VfsCreateParentDirectories
                        (*(undefined8 *)(param_2 + 0x28),local_res20,param_3,local_40,
                         *(ushort *)(param_3 + 8));
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        pwVar7 = 
        L"VfsCreateStoreForRename() - Failed to create parent directories for %wZ\n Status: 0x%08X";
      }
      else {
        param_5 = (undefined8 *)0x0;
        uVar2 = VfsOpenFile(lVar6,0,local_40,0x100000,2,0x4021,&param_5,0);
        uVar4 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          LogWrite(1,0,L"VfsCreateDirectory() - Failed to open file: %wZ\n Status: 0x%08X",local_40)
          ;
        }
        else {
          FltClose(param_5);
          uVar4 = 0;
        }
        if ((int)uVar4 < 0) {
          pwVar7 = 
          L"VfsCreateStoreForRename() - Failed to create directory for %wZ\n Status: 0x%08X";
        }
        else {
          uVar2 = VfsOpenFile(lVar6,0,local_40,0x100000,1,0x4020,&local_48,0);
          uVar4 = (ulonglong)uVar2;
          if (-1 < (int)uVar2) {
            *param_4 = lVar6;
            *puVar1 = local_48;
            lVar6 = 0;
            local_res20 = 0;
            local_48 = 0;
            goto LAB_1c000c3f8;
          }
          pwVar7 = L"VfsCreateStoreForRename() - Failed to open file: %wZ\n Status: 0x%08X";
        }
      }
      LogWrite(1,0,pwVar7,local_40);
    }
  }
LAB_1c000c3f8:
  if (lVar5 != 0) {
    FltReleaseFileNameInformation(lVar5);
  }
  if (lStack_38 != 0) {
    ExFreePoolWithTag(lStack_38,0);
    lStack_38 = 0;
  }
  if (lVar6 != 0) {
    FltObjectDereference(lVar6);
  }
  return uVar4;
}



===== VfsProcessRename @ 1c000c464 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VfsProcessRename(uint *param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined1 auStackY_108 [32];
  undefined8 local_d8;
  longlong local_d0 [3];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d0[1] = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 4) + 0x38);
  puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 4) + 0x28);
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  memset(local_78,0,0x44);
  local_d8 = 0;
  local_d0[0] = 0;
  cVar5 = VfsDecodeFileObject(*(longlong *)(param_2 + 0x20),local_d0 + 2,&local_d8);
  if (cVar5 != '\0') {
    if (puVar2 == (undefined8 *)0x0) {
      uVar8 = VfsRenameVirtualFileSimple(param_1,local_d8);
      return uVar8;
    }
    cVar5 = VfsDecodeFileObject((longlong)puVar2,(undefined8 *)0x0,local_d0);
    if (cVar5 == '\0') {
      uVar8 = VfsRenameVirtualFileToNativeTarget(param_1,local_d8,puVar2);
      return uVar8;
    }
    uVar8 = VfsRenameVirtualFileToVirtualTarget(param_1,local_d8,(longlong)puVar2,local_d0[0]);
    return uVar8;
  }
  if (puVar2 == (undefined8 *)0x0) {
    return 1;
  }
  uVar8 = PsGetCurrentThreadId();
  uVar9 = PsGetCurrentProcessId();
  uVar6 = VeMgrLookupProcess(uVar9,uVar8,&local_b8,local_78);
  if (uVar6 == 0xc0000034) {
    local_d8._0_4_ = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
LAB_1c000c534:
    local_98 = 0;
    uStack_90 = 0;
    local_88 = 0;
    uStack_80 = 0;
    iVar7 = memcmp(&local_b8,&local_98,0x20);
    if (iVar7 == 0) {
      cVar5 = VfsDecodeFileObject((longlong)puVar2,(undefined8 *)0x0,(undefined8 *)0x0);
      if ((cVar5 == '\0') &&
         ((lVar1 = *(longlong *)(lVar1 + 8), lVar1 == 0 ||
          (cVar5 = VfsDecodeFileHandle(lVar1,(char)param_1[0x14],(int *)&local_d8,local_d0 + 1),
          cVar5 == '\0')))) {
        return 1;
      }
      param_1[6] = 0xc0000001;
      goto LAB_1c000c59f;
    }
    cVar5 = VfsDecodeFileObject((longlong)puVar2,(undefined8 *)0x0,local_d0);
    if (cVar5 != '\0') {
      uVar8 = VfsRenameNativeFileToVirtualTarget(param_1,(longlong)puVar2,local_d0[0]);
      return uVar8;
    }
    local_d8 = (ulonglong)local_d8._4_4_ << 0x20;
    local_d0[0] = 0;
    puVar3 = *(undefined1 **)(*(longlong *)(param_1 + 4) + 0x38);
    lVar1 = *(longlong *)(puVar3 + 8);
    if (lVar1 == 0) {
      return 1;
    }
    cVar5 = VfsDecodeFileHandle(lVar1,(char)param_1[0x14],(int *)&local_d8,local_d0);
    if (cVar5 == '\0') {
      return 1;
    }
    uVar6 = (uint)local_d8;
    if (-1 < (int)(uint)local_d8) {
      *(longlong *)(puVar3 + 8) = local_d0[0];
      lVar4 = *(longlong *)(param_1 + 4);
      uVar10 = VfsSetRenameInformation
                         (*(undefined8 *)(lVar4 + 0x10),*(undefined8 *)(lVar4 + 8),(longlong)puVar2,
                          puVar3,*(undefined4 *)(lVar4 + 0x18));
      uVar6 = (uint)uVar10;
      *(longlong *)(puVar3 + 8) = lVar1;
    }
  }
  else {
    local_d8._0_4_ = uVar6;
    if (-1 < (int)uVar6) goto LAB_1c000c534;
  }
  param_1[6] = uVar6;
LAB_1c000c59f:
  param_1[8] = 0;
  param_1[9] = 0;
  return 4;
}



===== VfsRenameCanReplace @ 1c000c6a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VfsRenameCanReplace(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 auStackY_98 [32];
  undefined8 local_58;
  short local_50;
  ushort local_4e;
  undefined4 local_4c;
  wchar_t *local_48;
  undefined8 local_40;
  wchar_t local_38 [12];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  local_40 = 0;
  local_58 = 0;
  local_4c = 0;
  local_4e = 0x12;
  local_48 = local_38;
  uVar1 = KeQueryPerformanceCounter(0);
  RtlStringCchPrintfW(local_48,(ulonglong)(local_4e >> 1),L"%08x",(ulonglong)uVar1);
  if ((local_4e & 0xfffe) < 0x11) {
    local_50 = local_4e - 2;
  }
  else {
    local_50 = 0x10;
  }
  iVar2 = VfsOpenFile(param_1,param_2,&local_50,0x110000,2,0x5020,&local_40,&local_58);
  if (iVar2 < 0) {
    LogWrite(1,0,L"VfsRenameCanReplace() - Failed to open file: %wZ\n Status: 0x%08X",&local_50);
  }
  else {
    iVar2 = VfsRenameFile(param_1,local_58,param_2,param_3,1);
    ObfDereferenceObject(local_58);
    FltClose(local_40);
  }
  return iVar2;
}



===== VfsRenameNativeFileToVirtualTarget @ 1c000c804 =====

undefined8 VfsRenameNativeFileToVirtualTarget(uint *param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  uint uVar3;
  int *piVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  byte bVar8;
  uint local_res8 [4];
  longlong local_res18;
  longlong local_res20;
  
  pbVar1 = *(byte **)(*(longlong *)(param_1 + 4) + 0x38);
  local_res18 = 0;
  local_res20 = 0;
  local_res8[0] = 0;
  piVar4 = VfsScbGetMapping(*(longlong *)(param_3 + 0x18));
  if (piVar4 == (int *)0x0) {
    return 0xc00000bb;
  }
  uVar3 = VfsCheckVirtualTargetForRename
                    ((longlong)param_1,param_2,param_3,(longlong)piVar4,local_res8);
  if (-1 < (int)uVar3) {
    bVar8 = *pbVar1;
    if (*(int *)(*(longlong *)(param_1 + 4) + 0x20) != 10) {
      bVar8 = bVar8 & 1;
    }
    if ((local_res8[0] & 0x10) == 0) {
      uVar5 = VfsCreateStoreForRename(param_1,param_3,(longlong)piVar4,&local_res18,&local_res20);
      uVar3 = (uint)uVar5;
      if ((int)uVar3 < 0) goto LAB_1c000c927;
      lVar6 = local_res18;
      lVar7 = local_res20;
    }
    else {
      lVar6 = *(longlong *)(param_3 + 0x40);
      lVar7 = *(longlong *)(param_3 + 0x50);
    }
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 4) + 0x10);
    if (lVar6 == lVar2) {
      if ((local_res8[0] & 0x200) != 0) {
        bVar8 = 1;
      }
      uVar3 = VfsRenameFile(lVar2,*(undefined8 *)(*(longlong *)(param_1 + 4) + 8),lVar7,
                            (ushort *)(param_2 + 0x58),bVar8);
    }
    else {
      uVar3 = 0xc0000002;
    }
  }
LAB_1c000c927:
  VfsReleaseMappingEntry(piVar4);
  if (local_res18 != 0) {
    FltObjectDereference();
  }
  if (local_res20 != 0) {
    FltClose();
  }
  param_1[6] = uVar3;
  param_1[8] = 0;
  param_1[9] = 0;
  return 4;
}



===== VfsRenamePackageFile @ 1c000c97c =====

ulonglong VfsRenamePackageFile
                    (uint *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,int *param_6,char param_7,char param_8,undefined1 *param_9)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort *puVar6;
  undefined7 in_stack_ffffffffffffffb1;
  char local_38 [4];
  uint local_34;
  longlong local_30;
  int *local_28;
  
  uVar4 = 0;
  local_30 = 0;
  local_28 = (int *)0x0;
  local_38[0] = '\0';
  *param_9 = 0;
  piVar3 = VfsScbGetMapping(*(longlong *)(param_2 + 0x18));
  local_28 = piVar3;
  if (piVar3 != (int *)0x0) {
    uVar5 = 0x101;
    uVar4 = VfsGetFileNameInfoForFileObject
                      (param_1,*(longlong *)(param_2 + 0x30),*(undefined8 *)(param_2 + 0x28),0x101,
                       &local_30);
    local_34 = (uint)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if ((int)local_34 < 0) {
      LogWrite(1,0,
               L"VfsRenamePackageFile() - Failed to get filename info for fileobject: %p\n IRP: %d\n Status: 0x%08X"
               ,*(undefined8 *)(param_2 + 0x30));
    }
    else {
      puVar6 = (ushort *)(local_30 + 8);
      local_34 = VfsCowCopyFileForScb
                           (*(longlong *)(param_2 + 0x18),0,*(undefined8 *)(param_2 + 0x28),uVar5,
                            puVar6,param_3,param_4,param_5,'\0',
                            CONCAT71(in_stack_ffffffffffffffb1,1),local_38);
      uVar4 = (ulonglong)local_34;
      if ((-1 < (int)local_34) && (local_38[0] == '\0')) {
        uVar2 = *(uint *)(param_2 + 0x20);
        uVar4 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          local_34 = uVar2;
        }
        else {
          if (param_7 != '\0') {
            VfsScbUpdateMapping(*(longlong *)(param_2 + 0x18),param_6);
          }
          piVar3 = local_28;
          if (param_8 == '\0') {
            LOCK();
            puVar1 = (uint *)(*(longlong *)(param_2 + 0x18) + 0x110);
            *puVar1 = *puVar1 & 0xfffffffb;
            UNLOCK();
          }
          else {
            LOCK();
            puVar1 = (uint *)(*(longlong *)(param_2 + 0x18) + 0x110);
            *puVar1 = *puVar1 | 4;
            UNLOCK();
          }
          uVar4 = VfsMarkPackageFileDeleted(*(longlong *)(param_2 + 0x28),puVar6,(longlong)local_28)
          ;
          local_34 = (uint)uVar4;
          uVar4 = uVar4 & 0xffffffff;
          if (-1 < (int)local_34) {
            *param_9 = 1;
          }
        }
      }
    }
  }
  if (piVar3 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar3);
  }
  if (local_30 != 0) {
    FltReleaseFileNameInformation();
  }
  return uVar4;
}



===== VfsRenameStoreFile @ 1c000cb44 =====

int VfsRenameStoreFile(uint *param_1,longlong param_2,undefined8 param_3,ushort *param_4,
                      int *param_5,char param_6,char param_7,undefined1 param_8)

{
  undefined8 *puVar1;
  uint *puVar2;
  ulonglong uVar3;
  int *piVar4;
  uint uVar5;
  longlong local_res10;
  int local_38;
  
  local_res10 = 0;
  uVar5 = *(uint *)(*(longlong *)(param_2 + 0x18) + 0x110) & 4;
  puVar1 = (undefined8 *)(param_2 + 0x40);
  if (uVar5 != 0) {
    uVar3 = VfsGetFileNameInfoForFileObject
                      (param_1,*(longlong *)(param_2 + 0x48),*puVar1,0x101,&local_res10);
    local_38 = (int)uVar3;
    if (local_38 < 0) {
      LogWrite(1,0,
               L"VfsRenameStoreFile() - Failed to get filename info for fileobject: %p\n IRP: %d\n Status: 0x%08X"
               ,*(undefined8 *)(param_2 + 0x30));
      goto LAB_1c000cc5f;
    }
  }
  piVar4 = *(int **)(param_2 + 0x48);
  local_38 = VfsRenameFile(*puVar1,piVar4,param_3,param_4,param_8);
  if (-1 < local_38) {
    if (param_6 != '\0') {
      VfsScbUpdateMapping(*(longlong *)(param_2 + 0x18),param_5);
      piVar4 = param_5;
    }
    if (param_7 == '\0') {
      LOCK();
      puVar2 = (uint *)(*(longlong *)(param_2 + 0x18) + 0x110);
      *puVar2 = *puVar2 & 0xfffffffb;
      UNLOCK();
    }
    else {
      LOCK();
      puVar2 = (uint *)(*(longlong *)(param_2 + 0x18) + 0x110);
      *puVar2 = *puVar2 | 4;
      UNLOCK();
    }
    if (uVar5 != 0) {
      uVar3 = VfsMarkFileDeleted(*puVar1,piVar4,local_res10 + 8,
                                 (byte)(*(uint *)(*(longlong *)(param_2 + 0x18) + 0x110) >> 1) & 1,
                                 '\x01');
      local_38 = (int)uVar3;
    }
  }
LAB_1c000cc5f:
  if (local_res10 != 0) {
    FltReleaseFileNameInformation();
  }
  return local_38;
}



===== VfsRenameVirtualFileSimple @ 1c000cc9c =====

undefined8 VfsRenameVirtualFileSimple(uint *param_1,longlong param_2)

{
  uint uVar1;
  ushort *puVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  int *piVar6;
  uint *puVar7;
  char cVar8;
  wchar_t *pwVar9;
  ushort *puVar10;
  char local_res8 [16];
  uint local_res18 [2];
  longlong local_res20;
  ushort *local_60;
  byte *local_58;
  int *local_50;
  ushort local_48 [4];
  longlong lStack_40;
  
  local_58 = *(byte **)(*(longlong *)(param_1 + 4) + 0x38);
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  lStack_40 = 0;
  local_60 = (ushort *)0x0;
  local_res20 = 0;
  piVar6 = (int *)0x0;
  local_50 = (int *)0x0;
  local_res18[0] = 0;
  local_res8[0] = '\0';
  puVar10 = local_48;
  puVar7 = param_1;
  uVar5 = VfsCheckSimpleTargetForRename
                    (param_1,param_2,(longlong *)&local_60,(undefined8 *)puVar10,local_res18);
  puVar2 = local_60;
  uVar4 = (uint)uVar5;
  if (((int)uVar4 < 0) || (local_60 == (ushort *)0x0)) goto LAB_1c000cee9;
  uVar4 = VfsCheckPackageDirectoryForRename(puVar7,param_2);
  uVar1 = local_res18[0];
  if ((int)uVar4 < 0) {
    LogWrite(1,0,L"VfsRenameVirtualFileSimple() - Package directory rename is not supported",puVar10
            );
    goto LAB_1c000cee9;
  }
  cVar8 = (char)local_res18[0];
  if ((local_res18[0] & 0x10) != 0) {
LAB_1c000cdf6:
    if ((*(uint *)(param_2 + 4) & 4) != 0) {
      if (((cVar8 < '\0') && ((uVar1 >> 9 & 1) == 0)) &&
         (uVar4 = VfsRenameCanReplace(puVar2,0,local_48), (int)uVar4 < 0)) goto LAB_1c000cee9;
      uVar5 = VfsRenamePackageFile
                        (param_1,param_2,puVar2,0,local_48,(int *)0x0,'\0',(byte)(uVar1 >> 6) & 1,
                         local_res8);
      uVar4 = (uint)uVar5;
      if (((int)uVar4 < 0) || (local_res8[0] != '\0')) goto LAB_1c000cee9;
    }
    if (*(ushort **)(param_2 + 0x40) == puVar2) {
      bVar3 = *local_58;
      if (*(int *)(*(longlong *)(param_1 + 4) + 0x20) != 10) {
        bVar3 = bVar3 & 1;
      }
      if ((uVar1 >> 9 & 1) != 0) {
        bVar3 = 1;
      }
      uVar4 = VfsRenameStoreFile(param_1,param_2,0,local_48,(int *)0x0,'\0',(byte)(uVar1 >> 6) & 1,
                                 bVar3);
    }
    else {
      uVar4 = 0xc0000002;
    }
    goto LAB_1c000cee9;
  }
  uVar4 = FltGetInstanceContext(puVar2);
  if ((int)uVar4 < 0) {
    pwVar9 = 
    L"VfsRenameVirtualFileSimple() - Failed to get instance context for instance: %p\n Status: 0x%08X"
    ;
    puVar10 = puVar2;
LAB_1c000cd7a:
  }
  else {
    piVar6 = VfsScbGetMapping(*(longlong *)(param_2 + 0x18));
    puVar10 = local_48;
    local_50 = piVar6;
    if (piVar6 != (int *)0x0) {
      uVar5 = VfsCreateParentDirectories
                        (*(undefined8 *)(param_2 + 0x28),puVar2,(longlong)piVar6,puVar10,
                         *(ushort *)(local_res20 + 8));
      uVar4 = (uint)uVar5;
      if (-1 < (int)uVar4) goto LAB_1c000cdf6;
      puVar10 = local_48;
      pwVar9 = 
      L"VfsRenameVirtualFileSimple() - Failed to create parent directories for %wZ\n Status: 0x%08X"
      ;
      goto LAB_1c000cd7a;
    }
    uVar4 = 0xc00000e5;
    pwVar9 = 
    L"VfsRenameVirtualFileSimple() - Failed to get COW mapping for simple rename of %wZ\n Status: 0x%08X"
    ;
  }
  LogWrite(1,0,pwVar9,puVar10);
LAB_1c000cee9:
  if (piVar6 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar6);
  }
  if (local_res20 != 0) {
    FltReleaseContext();
  }
  if (puVar2 != (ushort *)0x0) {
    FltObjectDereference(puVar2);
  }
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0);
  }
  param_1[6] = uVar4;
  param_1[8] = 0;
  param_1[9] = 0;
  return 4;
}



===== VfsRenameVirtualFileToNativeTarget @ 1c000cf64 =====

undefined8 VfsRenameVirtualFileToNativeTarget(uint *param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  uint uVar2;
  uint extraout_EAX;
  ulonglong uVar3;
  undefined8 uVar4;
  char cVar5;
  wchar_t *pwVar6;
  undefined8 uVar7;
  byte bVar8;
  char local_res8 [8];
  char local_res20 [8];
  char local_68 [8];
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  lVar1 = *(longlong *)(param_1 + 4);
  local_58 = 0;
  local_60 = 0;
  local_68[0] = '\0';
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_res8[0] = '\0';
  local_res20[0] = '\0';
  bVar8 = **(byte **)(lVar1 + 0x38);
  if (*(int *)(lVar1 + 0x20) != 10) {
    bVar8 = bVar8 & 1;
  }
  uVar2 = FltGetStreamHandleContext(*(undefined8 *)(lVar1 + 0x10),param_3,&local_58);
  if ((int)uVar2 < 0) {
    pwVar6 = 
    L"VfsRenameVirtualFileToNativeTarget() - Failed to get stream handle context for fileobject: %p\n Status: 0x%08X"
    ;
  }
  else {
    if ((*(longlong *)(local_58 + 0x10) == 0) || (*(longlong *)(local_58 + 0x20) == 0)) {
      uVar2 = 0xc0000001;
      goto LAB_1c000d1d9;
    }
    local_40 = *(undefined8 *)(local_58 + 8);
    uStack_38 = *(undefined8 *)(local_58 + 0x10);
    local_50 = *(undefined8 *)(local_58 + 0x18);
    uStack_48 = *(undefined8 *)(local_58 + 0x20);
    uVar2 = VfsOpenFile(*(undefined8 *)(*(longlong *)(param_1 + 4) + 0x10),0,&local_40,0x100000,1,
                        0x4020,&local_60,0);
    if (-1 < (int)uVar2) {
      uVar7 = 0;
      uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 4) + 0x10);
      VfsQueryFile(uVar4,local_60,(longlong)&local_50,(undefined4 *)0x0,0,local_res8,
                   (undefined1 *)0x0,(undefined1 *)0x0,local_res20,(byte *)0x0);
      uVar2 = extraout_EAX;
      if ((int)extraout_EAX < 0) goto LAB_1c000d1d9;
      if (local_res8[0] != '\0') {
        if (bVar8 == 0) {
          uVar2 = 0xc0000035;
          goto LAB_1c000d1d9;
        }
        if (local_res20[0] != '\0') {
          uVar2 = 0xc0000022;
          goto LAB_1c000d1d9;
        }
      }
      cVar5 = local_res8[0];
      uVar2 = VfsCheckPackageDirectoryForRename(uVar4,param_2);
      if ((int)uVar2 < 0) {
        LogWrite(1,0,
                 L"VfsRenameVirtualFileToNativeTarget() - Package directory rename is not supported"
                 ,uVar7);
      }
      else {
        if ((*(uint *)(param_2 + 4) & 4) != 0) {
          if (cVar5 != '\0') {
            uVar2 = VfsRenameCanReplace(*(undefined8 *)(*(longlong *)(param_1 + 4) + 0x10),local_60,
                                        (ushort *)&local_50);
            if ((int)uVar2 < 0) goto LAB_1c000d1d9;
          }
          uVar3 = VfsRenamePackageFile
                            (param_1,param_2,*(undefined8 *)(*(longlong *)(param_1 + 4) + 0x10),
                             local_60,&local_50,(int *)0x0,'\x01','\0',local_68);
          uVar2 = (uint)uVar3;
          if (((int)uVar2 < 0) || (local_68[0] != '\0')) goto LAB_1c000d1d9;
        }
        if (*(longlong *)(param_2 + 0x40) == *(longlong *)(*(longlong *)(param_1 + 4) + 0x10)) {
          uVar2 = VfsRenameStoreFile(param_1,param_2,local_60,(ushort *)&local_50,(int *)0x0,'\x01',
                                     '\0',bVar8);
        }
        else {
          uVar2 = 0xc0000002;
        }
      }
      goto LAB_1c000d1d9;
    }
    param_3 = &local_40;
    pwVar6 = L"VfsRenameVirtualFileToNativeTarget() - Failed to open file: %wZ\n Status: 0x%08X";
  }
  LogWrite(1,0,pwVar6,param_3);
LAB_1c000d1d9:
  if (local_60 != 0) {
    FltClose();
  }
  if (local_58 != 0) {
    FltReleaseContext();
  }
  param_1[6] = uVar2;
  param_1[8] = 0;
  param_1[9] = 0;
  return 4;
}



===== VfsRenameVirtualFileToVirtualTarget @ 1c000d234 =====

undefined8
VfsRenameVirtualFileToVirtualTarget
          (uint *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int *piVar5;
  ulonglong uVar6;
  uint *puVar7;
  ushort *puVar8;
  char cVar9;
  int *piVar10;
  longlong lVar11;
  longlong lVar12;
  char local_res8 [8];
  longlong local_res10;
  longlong local_res18;
  byte local_res20;
  ushort *local_58;
  longlong local_50;
  longlong local_48;
  int *local_40;
  
  pbVar1 = *(byte **)(*(longlong *)(param_1 + 4) + 0x38);
  local_50 = 0;
  local_48 = 0;
  local_58 = (ushort *)((ulonglong)local_58 & 0xffffffff00000000);
  local_res8[0] = '\0';
  local_res10 = param_2;
  local_res18 = param_3;
  piVar5 = VfsScbGetMapping(*(longlong *)(param_4 + 0x18));
  if (piVar5 == (int *)0x0) {
    return 0xc00000bb;
  }
  puVar7 = param_1;
  piVar10 = piVar5;
  local_40 = piVar5;
  uVar4 = VfsCheckVirtualTargetForRename
                    ((longlong)param_1,param_3,param_4,(longlong)piVar5,(uint *)&local_58);
  if (-1 < (int)uVar4) {
    uVar4 = VfsCheckPackageDirectoryForRename(puVar7,param_2);
    if ((int)uVar4 < 0) {
      LogWrite(1,0,
               L"VfsRenameVirtualFileToVirtualTarget() - Package directory rename is not supported",
               piVar10);
    }
    else {
      local_res20 = *pbVar1;
      if (*(int *)(*(longlong *)(param_1 + 4) + 0x20) != 10) {
        local_res20 = local_res20 & 1;
      }
      uVar2 = (uint)local_58;
      cVar9 = (char)local_58;
      if (((ulonglong)local_58 & 0x10) == 0) {
        uVar6 = VfsCreateStoreForRename(param_1,param_4,(longlong)piVar5,&local_50,&local_48);
        uVar4 = (uint)uVar6;
        if ((int)uVar4 < 0) goto LAB_1c000d44c;
        lVar11 = local_50;
        lVar12 = local_48;
      }
      else {
        lVar11 = *(longlong *)(param_4 + 0x40);
        lVar12 = *(longlong *)(param_4 + 0x50);
      }
      if ((*(uint *)(local_res10 + 4) & 4) == 0) {
        puVar8 = (ushort *)(local_res18 + 0x58);
      }
      else {
        if (((cVar9 < '\0') && ((uVar2 >> 9 & 1) == 0)) &&
           (uVar4 = VfsRenameCanReplace(lVar11,lVar12,(ushort *)(local_res18 + 0x58)),
           (int)uVar4 < 0)) goto LAB_1c000d44c;
        local_58 = (ushort *)(local_res18 + 0x58);
        uVar6 = VfsRenamePackageFile
                          (param_1,local_res10,lVar11,lVar12,local_58,piVar5,'\x01',
                           (byte)(uVar2 >> 6) & 1,local_res8);
        uVar4 = (uint)uVar6;
        if (((int)uVar4 < 0) || (local_res8[0] != '\0')) goto LAB_1c000d44c;
        puVar8 = local_58;
      }
      if (*(longlong *)(local_res10 + 0x40) == lVar11) {
        bVar3 = local_res20;
        if ((uVar2 >> 9 & 1) != 0) {
          bVar3 = 1;
        }
        uVar4 = VfsRenameStoreFile(param_1,local_res10,lVar12,puVar8,piVar5,'\x01',
                                   (byte)(uVar2 >> 6) & 1,bVar3);
      }
      else {
        uVar4 = 0xc0000002;
      }
    }
  }
LAB_1c000d44c:
  VfsReleaseMappingEntry(piVar5);
  if (local_50 != 0) {
    FltObjectDereference();
  }
  if (local_48 != 0) {
    FltClose();
  }
  param_1[6] = uVar4;
  param_1[8] = 0;
  param_1[9] = 0;
  return 4;
}



===== VfsCreateCcb @ 1c000d49c =====

int VfsCreateCcb(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,char param_6,undefined8 *param_7)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *_Dst;
  
  _Dst = (undefined4 *)ExAllocateFromPagedLookasideList(&DAT_1c001f780);
  if (_Dst == (undefined4 *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x88);
    puVar1 = _Dst + 2;
    *_Dst = 0x881687;
    *(undefined4 **)(_Dst + 4) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    *(undefined8 *)(_Dst + 6) = param_1;
    iVar3 = FltObjectReference(param_3);
    if (iVar3 < 0) {
      LogWrite(1,0,L"VfsCreateCcb() - Failed to reference instance: %p\n Status: 0x%08X",param_3);
      ExFreeToPagedLookasideList(&DAT_1c001f780,_Dst);
    }
    else {
      if (param_6 == '\0') {
        *(undefined8 *)(_Dst + 0x10) = param_3;
        *(undefined8 *)(_Dst + 0x12) = param_4;
        *(undefined8 *)(_Dst + 0x14) = param_5;
      }
      else {
        _Dst[1] = _Dst[1] | 4;
        *(undefined8 *)(_Dst + 10) = param_3;
        *(undefined8 *)(_Dst + 0xc) = param_4;
        *(undefined8 *)(_Dst + 0xe) = param_5;
      }
      *(undefined8 *)(_Dst + 0x18) = *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 8);
      _Dst[0x1a] = *(undefined4 *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18) + 0x10);
      _Dst[0x1b] = (uint)*(ushort *)(*(longlong *)(param_2 + 0x10) + 0x2a);
      _Dst[0x1c] = *(uint *)(*(longlong *)(param_2 + 0x10) + 0x20) & 0xffffff;
      if ((param_6 != '\0') && (*(char *)(param_2 + 0x50) == '\0')) {
        cVar2 = IoIsFileObjectIgnoringSharing(*(undefined8 *)(*(longlong *)(param_2 + 0x10) + 8));
        if (cVar2 != '\0') {
          _Dst[1] = _Dst[1] | 0x10;
        }
      }
      *param_7 = _Dst;
      iVar3 = 0;
    }
  }
  return iVar3;
}



===== VfsCreateScb @ 1c000d608 =====

int VfsCreateScb(longlong param_1,undefined8 param_2,undefined4 *param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int iVar8;
  undefined8 *_Dst;
  undefined4 *_Dst_00;
  
  _Dst_00 = (undefined4 *)0x0;
  _Dst = (undefined8 *)ExAllocateFromPagedLookasideList(&DAT_1c001f680);
  if (_Dst != (undefined8 *)0x0) {
    memset(_Dst,0,0x198);
    _Dst_00 = (undefined4 *)ExAllocateFromNPagedLookasideList(&DAT_1c001f700);
    if (_Dst_00 != (undefined4 *)0x0) {
      memset(_Dst_00,0,0xa0);
      *_Dst_00 = 1;
      KeInitializeEvent(_Dst_00 + 6,1,0);
      iVar8 = ExInitializeResourceLite(_Dst_00 + 0xe);
      if (-1 < iVar8) {
        _Dst[0xf] = _Dst_00;
        puVar1 = *(undefined4 **)(param_3 + 4);
        uVar4 = puVar1[1];
        uVar5 = puVar1[2];
        uVar6 = puVar1[3];
        *(undefined4 *)((longlong)_Dst + 0xdc) = *puVar1;
        *(undefined4 *)(_Dst + 0x1c) = uVar4;
        *(undefined4 *)((longlong)_Dst + 0xe4) = uVar5;
        *(undefined4 *)(_Dst + 0x1d) = uVar6;
        uVar4 = puVar1[5];
        uVar5 = puVar1[6];
        uVar6 = puVar1[7];
        *(undefined4 *)((longlong)_Dst + 0xec) = puVar1[4];
        *(undefined4 *)(_Dst + 0x1e) = uVar4;
        *(undefined4 *)((longlong)_Dst + 0xf4) = uVar5;
        *(undefined4 *)(_Dst + 0x1f) = uVar6;
        RtlCopySid(0x44,_Dst + 0x13,*(undefined8 *)(param_3 + 2));
        _Dst[0x11] = *(undefined8 *)(param_3 + 6);
        piVar2 = *(int **)(param_3 + 8);
        if (piVar2 != (int *)0x0) {
          _Dst[0x12] = piVar2;
          LOCK();
          *piVar2 = *piVar2 + 1;
          UNLOCK();
        }
        *(undefined4 *)(_Dst + 0x22) = *param_3;
        _Dst[0x10] = param_2;
        FltReferenceContext(param_2);
        puVar3 = _Dst + 0x20;
        _Dst[0x21] = puVar3;
        *puVar3 = puVar3;
        *(undefined4 *)((longlong)_Dst + 0x114) = 1;
        *(undefined4 *)(_Dst + 0x23) = 0;
        puVar3 = *(undefined8 **)(param_1 + 0x18);
        uVar7 = puVar3[1];
        *_Dst = *puVar3;
        _Dst[1] = uVar7;
        uVar7 = puVar3[3];
        _Dst[2] = puVar3[2];
        _Dst[3] = uVar7;
        uVar4 = *(undefined4 *)((longlong)puVar3 + 0x24);
        uVar5 = *(undefined4 *)(puVar3 + 5);
        uVar6 = *(undefined4 *)((longlong)puVar3 + 0x2c);
        *(undefined4 *)(_Dst + 4) = *(undefined4 *)(puVar3 + 4);
        *(undefined4 *)((longlong)_Dst + 0x24) = uVar4;
        *(undefined4 *)(_Dst + 5) = uVar5;
        *(undefined4 *)((longlong)_Dst + 0x2c) = uVar6;
        *(undefined4 *)_Dst = 0x1981686;
        *(byte *)((longlong)_Dst + 4) = *(byte *)((longlong)_Dst + 4) | 0x40;
        *(byte *)((longlong)_Dst + 6) = *(byte *)((longlong)_Dst + 6) | 2;
        *(byte *)((longlong)_Dst + 7) = *(byte *)((longlong)_Dst + 7) & 0xf | 0x50;
        puVar3 = _Dst + 7;
        _Dst[8] = puVar3;
        *puVar3 = puVar3;
        _Dst[6] = _Dst_00;
        _Dst[9] = 0;
        _Dst[10] = 0;
        _Dst[0xb] = 0;
        _Dst[0xc] = 0;
        *(undefined4 *)(_Dst + 0xd) = 0;
        _Dst[0xe] = 0;
        *param_4 = _Dst;
      }
      goto LAB_1c000d7f5;
    }
  }
  iVar8 = -0x3fffff66;
LAB_1c000d7f5:
  if (iVar8 < 0) {
    if (_Dst_00 != (undefined4 *)0x0) {
      if (_Dst[0x10] != 0) {
        FltReleaseContext();
      }
      if (_Dst[0xf] != 0) {
        ExDeleteResourceLite(_Dst[0xf] + 0x38);
      }
      ExFreeToNPagedLookasideList(&DAT_1c001f700,_Dst_00);
    }
    if (_Dst != (undefined8 *)0x0) {
      ExFreeToPagedLookasideList(&DAT_1c001f680,_Dst);
    }
  }
  return iVar8;
}



===== VfsDeleteCcb @ 1c000d888 =====

void VfsDeleteCcb(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x28) != 0) {
    FltObjectDereference();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(longlong *)(param_1 + 0x40) != 0) {
    FltObjectDereference();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (*(longlong *)(param_1 + 0x58) != 0) {
    ZwClose();
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  if ((*(uint *)(param_1 + 4) & 2) != 0) {
    if (*(longlong *)(param_1 + 0x38) != 0) {
      FltClose();
      *(undefined8 *)(param_1 + 0x38) = 0;
    }
    if (*(longlong *)(param_1 + 0x30) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    if (*(longlong *)(param_1 + 0x50) != 0) {
      FltClose();
      *(undefined8 *)(param_1 + 0x50) = 0;
    }
    if (*(longlong *)(param_1 + 0x48) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0x48) = 0;
    }
  }
  if (*(longlong *)(param_1 + 0x78) != 0) {
    VfsDeleteDirQueryContext(*(longlong *)(param_1 + 0x78));
    *(undefined8 *)(param_1 + 0x78) = 0;
  }
  ExFreeToPagedLookasideList(&DAT_1c001f780,param_1);
  return;
}



===== VfsDeleteScb @ 1c000d984 =====

void VfsDeleteScb(longlong param_1)

{
  FsRtlTeardownPerStreamContexts();
  ExDeleteResourceLite(*(longlong *)(param_1 + 0x78) + 0x38);
  if (*(int **)(param_1 + 0x90) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_1 + 0x90));
  }
  if (*(longlong *)(param_1 + 0x80) != 0) {
    FltReleaseContext();
  }
  ExFreeToNPagedLookasideList(&DAT_1c001f700,*(undefined8 *)(param_1 + 0x78));
  ExFreeToPagedLookasideList(&DAT_1c001f680,param_1);
  return;
}



===== VfsLinkCcb @ 1c000da10 =====

void VfsLinkCcb(longlong param_1,undefined1 *param_2)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  lVar4 = *(longlong *)(lVar1 + 0x78);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar4 + 0x38,1);
  puVar6 = auStack_28;
  if ((param_2 == (undefined1 *)0x0) || ((*(uint *)(lVar1 + 0x110) & 1) == 0)) {
    lVar4 = lVar1 + 0x100;
    plVar5 = *(longlong **)(lVar1 + 0x108);
    plVar3 = (longlong *)(param_1 + 8);
    if (*plVar5 != lVar4) {
      lVar4 = 3;
      pcVar2 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar2)();
      puVar6 = auStack_20;
    }
    *plVar3 = lVar4;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(lVar4 + 8) = plVar3;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
  }
  else {
    *param_2 = 1;
    puVar6 = auStack_28;
  }
  lVar1 = *(longlong *)(lVar1 + 0x78);
  *(undefined8 *)(puVar6 + -8) = 0x1c000daa8;
  ExReleaseResourceLite(lVar1 + 0x38);
  *(undefined8 *)(puVar6 + -8) = 0x1c000dab4;
  KeLeaveCriticalRegion();
  return;
}



===== VfsScbClose @ 1c000dad8 =====

void VfsScbClose(longlong param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  char local_res8 [8];
  
  lVar4 = *(longlong *)(param_1 + 0x78);
  local_res8[0] = '\0';
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(lVar4 + 0x38,1);
  lVar4 = *(longlong *)(param_1 + 0x80);
  puVar1 = (undefined8 *)(lVar4 + 8);
  if ((*(uint *)(lVar4 + 4) & 1) == 0) {
    ExReleaseResourceLite(*(longlong *)(param_1 + 0x78) + 0x38);
    KeLeaveCriticalRegion();
    uVar5 = *puVar1;
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(uVar5,1);
    LOCK();
    piVar2 = (int *)(param_1 + 0x114);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      *(undefined8 *)(lVar4 + 0x10) = 0;
    }
    ExReleaseResourceLite(*puVar1);
    KeLeaveCriticalRegion();
    if (iVar3 != 1) {
      return;
    }
  }
  else {
    VfsScbTableCloseScb(param_1,puVar1,local_res8);
    ExReleaseResourceLite(*(longlong *)(param_1 + 0x78) + 0x38);
    KeLeaveCriticalRegion();
    if (local_res8[0] == '\0') {
      return;
    }
    lVar4 = *(longlong *)(param_1 + 0x78);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar4 + 0x38,1);
    ExReleaseResourceLite(*(longlong *)(param_1 + 0x78) + 0x38);
    KeLeaveCriticalRegion();
  }
  VfsDeleteScb(param_1);
  return;
}



===== VfsScbGetMapping @ 1c000dc3c =====

int * VfsScbGetMapping(longlong param_1)

{
  int *piVar1;
  
  if (*(longlong *)(param_1 + 0x90) == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    ExAcquireFastMutex(*(undefined8 *)(param_1 + 0x78));
    piVar1 = *(int **)(param_1 + 0x90);
    if (piVar1 != (int *)0x0) {
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    ExReleaseFastMutex(*(undefined8 *)(param_1 + 0x78));
  }
  return piVar1;
}



===== VfsScbTableCloseScb @ 1c000dc9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VfsScbTableCloseScb(longlong param_1,undefined8 *param_2,undefined1 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 local_78 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  *param_3 = 0;
  uVar3 = *param_2;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(uVar3);
  LOCK();
  piVar1 = (int *)(param_1 + 0x114);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    memset(&local_98,0,100);
    local_98 = *(undefined4 *)(param_1 + 0xdc);
    uStack_94 = *(undefined4 *)(param_1 + 0xe0);
    uStack_90 = *(undefined4 *)(param_1 + 0xe4);
    uStack_8c = *(undefined4 *)(param_1 + 0xe8);
    local_88 = *(undefined4 *)(param_1 + 0xec);
    uStack_84 = *(undefined4 *)(param_1 + 0xf0);
    uStack_80 = *(undefined4 *)(param_1 + 0xf4);
    uStack_7c = *(undefined4 *)(param_1 + 0xf8);
    RtlCopySid(0x44,local_78,param_1 + 0x98);
    lVar4 = RtlLookupElementGenericTableAvl(param_2 + 1,&local_98);
    if (lVar4 != 0) {
      if (*(longlong *)(lVar4 + 0x70) != 0) {
        *param_3 = 1;
      }
      RtlDeleteElementGenericTableAvl(param_2 + 1,&local_98);
    }
  }
  ExReleaseResourceLite(*param_2);
  KeLeaveCriticalRegion();
  return;
}



===== VfsScbTableCreateScb @ 1c000ddc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VfsScbTableCreateScb
              (longlong param_1,longlong param_2,undefined4 *param_3,longlong *param_4,
              undefined1 *param_5)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  undefined1 auStack_f8 [32];
  char local_d8 [8];
  longlong local_d0;
  longlong local_c8;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  iVar3 = 0;
  local_c8 = param_1;
  memset(&local_b8,0,100);
  *param_4 = 0;
  *param_5 = 0;
  puVar1 = *(undefined4 **)(param_3 + 4);
  local_d8[0] = '\0';
  local_d0 = 0;
  local_b8 = *puVar1;
  uStack_b4 = puVar1[1];
  uStack_b0 = puVar1[2];
  uStack_ac = puVar1[3];
  local_a8 = puVar1[4];
  uStack_a4 = puVar1[5];
  uStack_a0 = puVar1[6];
  uStack_9c = puVar1[7];
  RtlCopySid(0x44,local_98,*(undefined8 *)(param_3 + 2));
  uVar2 = *(undefined8 *)(param_2 + 8);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(uVar2,1);
  lVar4 = RtlInsertElementGenericTableAvl(param_2 + 0x10,&local_b8,100,local_d8);
  if (lVar4 == 0) {
    iVar3 = -0x3fffff66;
  }
  else if (local_d8[0] == '\0') {
    local_d0 = *(longlong *)(lVar4 + 0x70);
    if ((*(uint *)(local_d0 + 0x110) & 1) == 0) {
      LOCK();
      *(int *)(local_d0 + 0x114) = *(int *)(local_d0 + 0x114) + 1;
      UNLOCK();
      *param_4 = local_d0;
    }
    else {
      *param_5 = 1;
    }
  }
  else {
    iVar3 = VfsCreateScb(local_c8,param_2,param_3,&local_d0);
    if (iVar3 < 0) {
      RtlDeleteElementGenericTableAvl(param_2 + 0x10,&local_b8);
    }
    else {
      *(longlong *)(lVar4 + 0x70) = local_d0;
      *param_4 = local_d0;
    }
  }
  ExReleaseResourceLite(*(undefined8 *)(param_2 + 8));
  KeLeaveCriticalRegion();
  return iVar3;
}



===== VfsScbTableElementAllocate @ 1c000df50 =====

void * VfsScbTableElementAllocate(void)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocateFromPagedLookasideList(&DAT_1c001f600);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0xa0);
  }
  return _Dst;
}



===== VfsScbTableElementCompare @ 1c000dfa0 =====

bool VfsScbTableElementCompare(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = RtlCompareMemory(param_2,param_3,0x20);
  if (lVar3 == 0x20) {
    uVar1 = RtlLengthSid(param_2 + 0x20);
    uVar2 = RtlLengthSid(param_3 + 0x20);
    if (uVar1 < uVar2) {
      return false;
    }
    if (uVar2 < uVar1) {
      return true;
    }
    uVar4 = RtlCompareMemory(param_2 + 0x20,param_3 + 0x20,(ulonglong)uVar1);
    if (uVar4 == uVar1) {
      return true;
    }
    bVar5 = *(byte *)(uVar4 + 0x20 + param_2) < *(byte *)(uVar4 + 0x20 + param_3);
  }
  else {
    bVar5 = *(byte *)(lVar3 + param_2) < *(byte *)(lVar3 + param_3);
  }
  return !bVar5;
}



===== VfsScbTableElementFree @ 1c000e060 =====

void VfsScbTableElementFree(void)

{
  ExFreeToPagedLookasideList(&DAT_1c001f600);
  return;
}



===== VfsScbTableGetScb @ 1c000e084 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong VfsScbTableGetScb(longlong param_1,undefined4 *param_2,undefined8 param_3,char param_4,
                          undefined1 *param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(&local_a8,0,100);
  if (param_5 != (undefined1 *)0x0) {
    *param_5 = 0;
  }
  local_a8 = *param_2;
  uStack_a4 = param_2[1];
  uStack_a0 = param_2[2];
  uStack_9c = param_2[3];
  local_98 = param_2[4];
  uStack_94 = param_2[5];
  uStack_90 = param_2[6];
  uStack_8c = param_2[7];
  RtlCopySid(0x44,local_88,param_3);
  uVar1 = *(undefined8 *)(param_1 + 8);
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(uVar1,1);
  lVar2 = RtlLookupElementGenericTableAvl(param_1 + 0x10,&local_a8);
  lVar3 = 0;
  if (lVar2 != 0) {
    lVar3 = *(longlong *)(lVar2 + 0x70);
    if (((*(uint *)(lVar3 + 0x110) & 1) == 0) || (param_5 == (undefined1 *)0x0)) {
      if ((lVar3 != 0) && (param_4 != '\0')) {
        LOCK();
        *(int *)(lVar3 + 0x114) = *(int *)(lVar3 + 0x114) + 1;
        UNLOCK();
      }
    }
    else {
      *param_5 = 1;
      lVar3 = 0;
    }
  }
  ExReleaseResourceLite(*(undefined8 *)(param_1 + 8));
  KeLeaveCriticalRegion();
  return lVar3;
}



===== VfsScbTableInitialize @ 1c000e1b8 =====

int VfsScbTableInitialize(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = ExAllocatePool2(0x40,0x68,0x72454656);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = ExInitializeResourceLite(lVar2);
    if (-1 < iVar1) {
      *param_1 = lVar2;
      RtlInitializeGenericTableAvl
                (param_1 + 1,VfsScbTableElementCompare,VfsScbTableElementAllocate,
                 VfsScbTableElementFree,0);
      return 0;
    }
    ExFreePoolWithTag(lVar2,0x72454656);
  }
  return iVar1;
}



===== VfsScbUnitCreateScb @ 1c000e268 =====

int VfsScbUnitCreateScb(longlong param_1,longlong param_2,undefined4 *param_3,longlong *param_4)

{
  undefined8 uVar1;
  int iVar2;
  longlong local_res10;
  
  uVar1 = *(undefined8 *)(param_2 + 8);
  iVar2 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(uVar1,1);
  local_res10 = *(longlong *)(param_2 + 0x10);
  if (local_res10 == 0) {
    iVar2 = VfsCreateScb(param_1,param_2,param_3,&local_res10);
    if (-1 < iVar2) {
      *(longlong *)(param_2 + 0x10) = local_res10;
      *param_4 = local_res10;
    }
  }
  else {
    LOCK();
    *(int *)(local_res10 + 0x114) = *(int *)(local_res10 + 0x114) + 1;
    UNLOCK();
    *param_4 = local_res10;
  }
  ExReleaseResourceLite(*(undefined8 *)(param_2 + 8));
  KeLeaveCriticalRegion();
  return iVar2;
}



===== VfsScbUnitOpenScb @ 1c000e334 =====

longlong VfsScbUnitOpenScb(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(uVar1,1);
  lVar2 = *(longlong *)(param_1 + 0x10);
  if (lVar2 != 0) {
    LOCK();
    *(int *)(lVar2 + 0x114) = *(int *)(lVar2 + 0x114) + 1;
    UNLOCK();
  }
  ExReleaseResourceLite(*(undefined8 *)(param_1 + 8));
  KeLeaveCriticalRegion();
  return lVar2;
}



===== VfsScbUpdateMapping @ 1c000e3a4 =====

void VfsScbUpdateMapping(longlong param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  ExAcquireFastMutex(*(undefined8 *)(param_1 + 0x78));
  piVar1 = *(int **)(param_1 + 0x90);
  piVar2 = (int *)0x0;
  if ((param_2 != piVar1) &&
     (*(int **)(param_1 + 0x90) = param_2, piVar2 = piVar1, param_2 != (int *)0x0)) {
    LOCK();
    *param_2 = *param_2 + 1;
    UNLOCK();
  }
  ExReleaseFastMutex(*(undefined8 *)(param_1 + 0x78));
  if (piVar2 != (int *)0x0) {
    VfsReleaseMappingEntry(piVar2);
  }
  return;
}



===== VfsAcquireForSectionSync @ 1c000e420 =====

undefined4 VfsAcquireForSectionSync(uint *param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  bool bVar7;
  bool bVar8;
  undefined4 local_res10;
  longlong local_res18;
  longlong local_res20;
  uint local_44;
  
  local_res10 = 1;
  bVar7 = false;
  bVar4 = false;
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0x20);
  iVar1 = *(int *)(*(longlong *)(param_1 + 4) + 0x18);
  local_res20 = lVar2;
  if ((((*(uint *)(lVar3 + 4) & 4) != 0) && (iVar1 == 1)) &&
     ((*(uint *)(*(longlong *)(param_1 + 4) + 0x1c) & 0x44) != 0)) {
    uVar5 = VfsDelayedCopy(param_1,lVar2,lVar3);
    local_44 = (uint)uVar5;
    if ((int)local_44 < 0) {
      LogWrite(1,0,L"VfsAcquireForSectionSync() - Failed to delay copy file. Status: 0x%08X",
               uVar5 & 0xffffffff);
      goto LAB_1c000e56d;
    }
  }
  if ((iVar1 == 1) && (**(longlong **)(*(longlong *)(param_2 + 0x20) + 0x28) == 0)) {
    local_res18 = 0;
    bVar7 = (*(uint *)(lVar3 + 4) & 4) != 0;
    if (bVar7) {
      lVar2 = *(longlong *)(lVar2 + 0x78);
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(lVar2 + 0x38);
    }
    bVar8 = (*(uint *)(lVar3 + 4) & 4) == 0;
    if (bVar8) {
      uVar6 = *(undefined8 *)(lVar3 + 0x50);
    }
    else {
      uVar6 = *(undefined8 *)(lVar3 + 0x38);
    }
    local_44 = VfsCreateSection(uVar6,!bVar8,&local_res18);
    if ((int)local_44 < 0) goto LAB_1c000e56d;
    bVar4 = true;
    LOCK();
    bVar8 = *(longlong *)(lVar3 + 0x58) == 0;
    if (bVar8) {
      *(longlong *)(lVar3 + 0x58) = local_res18;
    }
    UNLOCK();
    if (!bVar8) {
      ZwClose(local_res18);
      bVar4 = false;
    }
  }
  local_44 = VfsRedirectIo((longlong)param_1,lVar3);
LAB_1c000e56d:
  if (bVar7) {
    ExReleaseResourceLite();
    KeLeaveCriticalRegion();
  }
  if ((int)local_44 < 0) {
    if (bVar4) {
      LOCK();
      lVar2 = *(longlong *)(lVar3 + 0x58);
      *(longlong *)(lVar3 + 0x58) = 0;
      UNLOCK();
      if (lVar2 != 0) {
        ZwClose();
      }
    }
    param_1[6] = local_44;
    param_1[8] = 0;
    param_1[9] = 0;
    local_res10 = 4;
  }
  return local_res10;
}



===== VfsCreateSection @ 1c000e5e4 =====

void VfsCreateSection(undefined8 param_1,char param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_res20;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_30 = 0;
  local_28 = 0;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_res20 = 1;
  iVar1 = ZwCreateSection(param_3,5,&local_38,&local_res20,2,0x8000000,param_1);
  if ((iVar1 == -0x3fffffc0) && (param_2 == '\0')) {
    ZwCreateSection(param_3,5,&local_38,&local_res20,4,0x8000000,param_1);
  }
  return;
}



===== VfsAccessCheck @ 1c000e6c0 =====

undefined4 VfsAccessCheck(longlong param_1,longlong param_2,uint param_3,char param_4)

{
  longlong lVar1;
  char cVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined4 local_res10 [2];
  uint local_res18 [4];
  longlong local_48 [2];
  
  local_res10[0] = 0;
  uVar3 = 0;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18) + 8);
  local_48[0] = 0;
  local_res18[0] = 0;
  uVar6 = param_3 & ~*(uint *)(lVar1 + 0x14);
  if (uVar6 != 0) {
    if (param_1 == 0) {
      if ((uVar6 >> 0x19 & 1) != 0) {
        lVar4 = IoGetFileObjectGenericMapping();
        uVar6 = uVar6 & 0xfdffffff | *(uint *)(lVar4 + 0xc);
      }
      local_res18[0] = uVar6;
    }
    else {
      uVar7 = 1;
      if ((*(byte *)(*(longlong *)(param_2 + 0x10) + 6) & 1) == 0) {
        uVar7 = *(undefined1 *)(param_2 + 0x50);
      }
      lVar4 = lVar1 + 0x20;
      SeLockSubjectContext(lVar4);
      uVar5 = IoGetFileObjectGenericMapping();
      cVar2 = SeAccessCheck(param_1,lVar4,1,uVar6,0,local_48,uVar5,uVar7,local_res18,local_res10);
      if (local_48[0] != 0) {
        uVar3 = SeAppendPrivileges(lVar1);
        SeFreePrivileges(local_48[0]);
        local_48[0] = 0;
      }
      SeUnlockSubjectContext(lVar4);
      if (cVar2 == '\0') {
        return local_res10[0];
      }
    }
    if (param_4 == '\0') {
      *(uint *)(lVar1 + 0x14) = *(uint *)(lVar1 + 0x14) | local_res18[0];
      *(uint *)(lVar1 + 0x10) = *(uint *)(lVar1 + 0x10) & ~(local_res18[0] | 0x2000000);
    }
  }
  return uVar3;
}



===== VfsCreateSecurityDescriptors @ 1c000e824 =====

int VfsCreateSecurityDescriptors
              (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,longlong param_4,
              longlong *param_5)

{
  bool bVar1;
  bool bVar2;
  ulonglong uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  wchar_t *pwVar10;
  undefined1 local_67 [3];
  int local_64;
  uint local_60;
  undefined8 local_58;
  longlong lStack_50;
  uint local_48;
  longlong local_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  short *psStack_20;
  
  local_64 = 0;
  local_58 = 0;
  lStack_50 = 0;
  bVar2 = false;
  *param_5 = 0;
  param_5[1] = 0;
  param_5[2] = 0;
  local_38 = *param_2;
  lStack_30 = param_2[1];
  uVar8 = (uint)local_38;
  local_28 = *param_3;
  psStack_20 = (short *)param_3[1];
  local_60 = (uint)(*(short *)(lStack_30 + -2 + (ulonglong)(ushort)((ushort)local_38 >> 1) * 2) ==
                   0x5c);
  if (*psStack_20 == 0x5c) {
    local_60 = local_60 + 1;
  }
  if (local_60 == 2) {
    uVar9 = (ushort)local_38 - 2;
    uVar8 = (uint)uVar9;
    uVar3 = (ulonglong)local_38 >> 0x10;
    local_38 = CONCAT62((int6)uVar3,uVar9);
    local_60 = 1;
  }
  uVar4 = local_60;
  if (local_60 == 0) {
    uVar8 = (uVar8 & 0xffff) + (ushort)local_28 + 2;
  }
  else {
    uVar8 = (uint)(ushort)local_28 + (uVar8 & 0xffff);
  }
  local_48 = uVar8;
  if (uVar8 < 0xffff) {
    lStack_50 = ExAllocatePool2(0x100,uVar8 & 0xffff,0x74534656);
    if (lStack_50 != 0) {
      uVar3 = (ulonglong)local_58 >> 0x20;
      local_58._0_4_ = uVar8 << 0x10;
      local_58 = CONCAT44((int)uVar3,(int)local_58);
      uVar9 = 0;
      if ((ushort)local_38 != 0) {
        RtlCopyUnicodeString(&local_58,&local_38);
        uVar9 = (ushort)local_38;
      }
      if (uVar4 == 0) {
        *(undefined2 *)(lStack_50 + (ulonglong)(uVar9 >> 1) * 2) = 0x5c;
        local_58 = CONCAT62(local_58._2_6_,(short)local_58 + 2);
      }
      RtlAppendUnicodeStringToString(&local_58,&local_28);
      local_64 = 0;
      iVar6 = VfsReadSecurityDescriptor(param_1,&local_58,param_5);
      local_64 = iVar6;
      if (iVar6 < 0) {
        pwVar10 = 
        L"VfsCreateSecurityDescriptors() - Failed to read security descriptors for : %wZ\n Status: 0x%08X"
        ;
      }
      else {
        if (*param_5 == 0) goto LAB_1c000eaa3;
        if (param_4 != 0) {
          local_40 = 0;
          local_67[0] = 0;
          iVar7 = RtlGetOwnerSecurityDescriptor(*param_5,&local_40,local_67);
          if (-1 < iVar7) {
            if (local_40 == 0) {
LAB_1c000ea42:
              bVar1 = true;
            }
            else {
              cVar5 = RtlEqualSid();
              bVar1 = false;
              if (cVar5 != '\0') goto LAB_1c000ea42;
            }
            if (!bVar1) goto LAB_1c000ea52;
          }
          bVar2 = true;
          goto LAB_1c000eaa3;
        }
LAB_1c000ea52:
        local_64 = VfsGetChildSecurityDescriptor(*param_5,0,param_5 + 1);
        if (local_64 < 0) {
          pwVar10 = 
          L"VfsCreateSecurityDescriptors() - Failed to get child file security descriptors for : %wZ\n Status: 0x%08X"
          ;
        }
        else {
          iVar6 = VfsGetChildSecurityDescriptor(*param_5,1,param_5 + 2);
          local_64 = iVar6;
          if (-1 < iVar6) goto LAB_1c000eaa3;
          pwVar10 = 
          L"VfsCreateSecurityDescriptors() - Failed to get child directory security descriptors for : %wZ\n Status: 0x%08X"
          ;
        }
      }
      iVar6 = local_64;
      LogWrite(1,0,pwVar10,&local_58);
      goto LAB_1c000eaa3;
    }
    iVar6 = -0x3fffff66;
  }
  else {
    iVar6 = -0x3ffffefa;
  }
  local_64 = iVar6;
LAB_1c000eaa3:
  if ((iVar6 < 0) || (bVar2)) {
    VfsDeleteSecurityDescriptors(param_5);
  }
  if (lStack_50 != 0) {
    ExFreePoolWithTag(lStack_50,0);
  }
  return iVar6;
}



===== VfsDeleteSecurityDescriptors @ 1c000eaf8 =====

void VfsDeleteSecurityDescriptors(longlong *param_1)

{
  longlong *plVar1;
  
  if (*param_1 != 0) {
    ExFreePoolWithTag(*param_1,0x64534656);
    *param_1 = 0;
  }
  plVar1 = param_1 + 1;
  if (*plVar1 != 0) {
    SeDeassignSecurity(plVar1);
    *plVar1 = 0;
  }
  if (param_1[2] != 0) {
    SeDeassignSecurity(param_1 + 2);
    param_1[2] = 0;
  }
  return;
}



===== VfsGetChildSecurityDescriptor @ 1c000eb70 =====

void VfsGetChildSecurityDescriptor(undefined8 param_1,undefined1 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = IoGetFileObjectGenericMapping();
  SeAssignSecurityEx(param_1,0,param_3,0,param_2,0x7b,0,uVar1,1);
  return;
}



===== VfsReadSecurityDescriptor @ 1c000ebe0 =====

int VfsReadSecurityDescriptor(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res18 [2];
  longlong local_res20;
  longlong *plVar3;
  longlong *plVar4;
  longlong local_30;
  longlong local_28;
  
  local_30 = 0;
  local_res20 = 0;
  lVar2 = 0;
  local_28 = 0;
  local_res18[0] = 0;
  *param_3 = 0;
  plVar4 = &local_res20;
  plVar3 = &local_30;
  iVar1 = VfsOpenFile(param_1,0,param_2,0x1120001,1,0x4020,plVar3,plVar4);
  if (iVar1 < 0) {
    if ((iVar1 == -0x3fffffc6) || (iVar1 == -0x3fffffcc)) {
      iVar1 = 0;
    }
    else {
      LogWrite(1,0,L"VfsReadSecurityDescriptor() - Failed to open file: %wZ\n Status: 0x%08X",
               param_2);
    }
  }
  else {
    iVar1 = FltQuerySecurityObject(param_1,local_res20,0x1f,0,0,local_res18,plVar3,plVar4,iVar1);
    if (iVar1 == -0x3fffffdd) {
      lVar2 = ExAllocatePool2(0x100,local_res18[0],0x64534656);
      local_28 = lVar2;
      if (lVar2 == 0) {
        iVar1 = -0x3fffff66;
      }
      else {
        iVar1 = FltQuerySecurityObject(param_1,local_res20,0x1f,lVar2,local_res18[0],local_res18);
        if (-1 < iVar1) {
          *param_3 = lVar2;
          lVar2 = 0;
          local_28 = 0;
        }
      }
    }
  }
  if (local_res20 != 0) {
    ObfDereferenceObject();
  }
  if (local_30 != 0) {
    FltClose();
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x64534656);
  }
  return iVar1;
}



===== VfsCreateShadow @ 1c000eda8 =====

int VfsCreateShadow(longlong param_1,uint param_2,longlong param_3,longlong param_4,uint *param_5,
                   uint *param_6,longlong param_7,char param_8,char param_9,char param_10,
                   char param_11,char param_12,undefined8 param_13,undefined8 param_14,
                   undefined8 param_15,char *param_16)

{
  uint *puVar1;
  int *piVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  longlong *plVar12;
  uint uVar13;
  wchar_t *pwVar14;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  uint local_68 [2];
  undefined8 uStack_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_40 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  local_70 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  uStack_60 = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_48 = 0;
  bVar5 = false;
  bVar4 = false;
  *param_16 = '\0';
  if ((param_10 != '\0') && (param_8 != '\0')) {
    return -0x3ffffff3;
  }
  plVar12 = &local_70;
  iVar6 = FltGetInstanceContext(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10));
  if (iVar6 < 0) {
    param_4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
    pwVar14 = 
    L"VfsCreateShadow() - Failed to get instance context for instance: %p\n Status: 0x%08X";
LAB_1c000eea2:
    puVar11 = (uint *)0x0;
    LogWrite(1,0,pwVar14,param_4);
    goto LAB_1c000f260;
  }
  if ((((param_8 == '\0') && (param_10 == '\0')) && (param_3 != 0)) && (param_4 != 0)) {
    plVar12 = (longlong *)0x0;
    iVar6 = VfsOpenFile(param_3,0,param_4,0x100000,1,0x4020,&local_90,&local_88);
    if (iVar6 < 0) {
      pwVar14 = L"VfsCreateShadow() - Failed to open file: %wZ\n Status: 0x%08X";
      goto LAB_1c000eea2;
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 4) != 0) {
      iVar6 = FltObjectReference(param_3);
      if (iVar6 < 0) {
        pwVar14 = L"VfsCreateShadow() - Failed to reference instance: %p\n Status: 0x%08X";
        param_4 = param_3;
        goto LAB_1c000eea2;
      }
      bVar5 = true;
    }
  }
  if ((param_10 != '\0') && (param_2 == 2)) {
    if (param_11 == '\0') {
      iVar6 = VfsDeleteFile(param_6,plVar12,param_7);
    }
    else {
      uVar7 = VfsMarkFileDeleted(param_6,plVar12,param_7,'\x01','\0');
      iVar6 = (int)uVar7;
    }
    if (iVar6 < 0) {
      pwVar14 = L"VfsCreateShadow() - Failed to delete tombstone: %wZ\n Status: 0x%08X";
      param_4 = param_7;
      goto LAB_1c000eea2;
    }
    uVar9 = 3;
    if (param_11 == '\0') {
      uVar9 = param_2;
    }
    param_2 = uVar9;
    bVar4 = true;
  }
  puVar11 = (uint *)(ulonglong)param_2;
  uVar7 = VfsCreateFileByCallbackData
                    (param_1,param_2,param_6,param_7,
                     *(byte *)(*(longlong *)(param_1 + 0x10) + 6) >> 2 & 1,param_12,param_12 != '\0'
                     ,(undefined4 *)&local_38,&local_80,&local_78);
  iVar6 = (int)uVar7;
  if (iVar6 < 0) goto LAB_1c000f260;
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
  puVar11 = param_6;
  uVar8 = VfsAdjustDeviceStackSizeForIoRedirection(lVar3,(longlong)param_6);
  iVar6 = (int)uVar8;
  if (iVar6 < 0) {
LAB_1c000f089:
  }
  else {
    if ((param_5 != (uint *)0x0) && (param_5 != param_6)) {
      uVar8 = VfsAdjustDeviceStackSizeForIoRedirection(lVar3,(longlong)param_5);
      iVar6 = (int)uVar8;
      puVar11 = param_5;
      if (iVar6 < 0) goto LAB_1c000f089;
    }
    iVar6 = 0;
    puVar11 = param_5;
  }
  if (iVar6 < 0) goto LAB_1c000f260;
  uStack_60 = param_13;
  local_58 = param_14;
  lStack_50 = local_70;
  local_48 = param_15;
  local_68[0] = 0;
  uVar9 = 0;
  uVar10 = 0;
  uVar13 = 0;
  if (param_9 != '\0') {
    local_68[0] = 4;
    uVar9 = 4;
    uVar10 = 4;
    uVar13 = 4;
  }
  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 4) == 0) {
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 1) != 0) {
      uVar9 = uVar10;
      goto LAB_1c000f149;
    }
    uVar9 = uVar13;
    if (param_11 != '\0') goto LAB_1c000f149;
  }
  else {
LAB_1c000f149:
    local_68[0] = uVar9 | 2;
  }
  puVar11 = local_68;
  iVar6 = VfsSetupShadowFileObject
                    (param_1,puVar11,param_3,local_88,param_6,local_78,local_80,param_8,param_16);
  if ((-1 < iVar6) && (*param_16 == '\0')) {
    LOCK();
    *(int *)(local_70 + 0x18) = *(int *)(local_70 + 0x18) + 1;
    UNLOCK();
    LOCK();
    piVar2 = (int *)(*(longlong *)(local_40 + 0x18) + 0x118);
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    puVar11 = *(uint **)(local_40 + 0x20);
    puVar1 = puVar11 + 1;
    *puVar1 = *puVar1 | 2;
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 0x1000) != 0) {
      LOCK();
      *puVar1 = *puVar1 | 0x40;
      UNLOCK();
    }
    local_80 = 0;
    local_78 = 0;
    if (((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 4) != 0) && (local_90 != 0)) {
      *puVar1 = *puVar1 | 8;
      *(longlong *)(puVar11 + 10) = param_3;
      *(longlong *)(puVar11 + 0xe) = local_90;
      *(longlong *)(puVar11 + 0xc) = local_88;
      bVar5 = false;
      local_90 = 0;
      local_88 = 0;
    }
  }
LAB_1c000f260:
  if ((iVar6 < 0) && (bVar4)) {
    VfsMarkFileDeleted(param_6,puVar11,param_7,param_11,'\x01');
  }
  if (bVar5) {
    FltObjectDereference(param_3);
  }
  if (local_90 != 0) {
    FltClose();
  }
  if (local_88 != 0) {
    ObfDereferenceObject();
  }
  if (local_80 != 0) {
    FltClose();
  }
  if (local_78 != 0) {
    ObfDereferenceObject();
  }
  if (local_70 != 0) {
    FltReleaseContext();
  }
  return iVar6;
}



===== VfsDecodeFileHandle @ 1c000f320 =====

undefined1
VfsDecodeFileHandle(undefined8 param_1,undefined1 param_2,int *param_3,undefined8 *param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  longlong local_res18;
  longlong local_res20;
  
  uVar2 = 0;
  *param_3 = 0;
  pcVar1 = IoFileObjectType_exref;
  *param_4 = 0;
  local_res18 = 0;
  local_res20 = 0;
  iVar4 = ObReferenceObjectByHandle(param_1,0,*(undefined8 *)pcVar1,param_2,&local_res18,0);
  if (iVar4 < 0) {
    uVar2 = 0;
  }
  else {
    cVar3 = VfsDecodeFileObject(local_res18,(undefined8 *)0x0,&local_res20);
    if (cVar3 != '\0') {
      if ((*(uint *)(local_res20 + 4) & 4) == 0) {
        if (*(int *)(local_res20 + 0x20) < 0) {
          *param_3 = *(int *)(local_res20 + 0x20);
        }
        uVar5 = *(undefined8 *)(local_res20 + 0x50);
      }
      else {
        uVar5 = *(undefined8 *)(local_res20 + 0x38);
      }
      *param_4 = uVar5;
      uVar2 = 1;
    }
    ObfDereferenceObject(local_res18);
  }
  return uVar2;
}



===== VfsDecodeFileObject @ 1c000f3d8 =====

void VfsDecodeFileObject(longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
  short *psVar1;
  
  if ((((param_1 != 0) && (psVar1 = *(short **)(param_1 + 0x18), psVar1 != (short *)0x0)) &&
      (*psVar1 == 0x1686)) &&
     ((*(short **)(param_1 + 0x20) != (short *)0x0 && (**(short **)(param_1 + 0x20) == 0x1687)))) {
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = psVar1;
    }
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = *(undefined8 *)(param_1 + 0x20);
    }
  }
  return;
}



===== VfsSetupShadowFileObject @ 1c000f43c =====

int VfsSetupShadowFileObject
              (longlong param_1,uint *param_2,longlong param_3,longlong param_4,undefined8 param_5,
              longlong param_6,undefined8 param_7,char param_8,char *param_9)

{
  longlong lVar1;
  undefined8 uVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  
  local_48 = 0;
  local_50 = 0;
  local_60 = 0;
  lVar8 = 0;
  local_58 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  bVar3 = false;
  *param_9 = '\0';
  local_40 = lVar1;
  uVar5 = VfsGetStreamContext(param_5,param_6,(uint)(param_8 != '\0') | *param_2 & 2,&local_50);
  lVar9 = local_50;
  iVar4 = (int)uVar5;
  if (iVar4 < 0) {
    LogWrite(1,0,
             L"VfsSetupShadowFileObject() - Failed to get stream context for fileobject: %p\n Status: 0x%08X"
             ,param_6);
    lVar6 = 0;
    lVar9 = local_50;
    goto LAB_1c000f7f9;
  }
  if ((*(uint *)(local_50 + 4) & 1) == 0) {
    lVar6 = VfsScbUnitOpenScb(local_50);
    local_60 = lVar6;
    if (lVar6 == 0) {
      if ((param_3 != 0) && (param_4 != 0)) {
        iVar4 = FltGetStreamContext();
        if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3ffffddb)) {
          LogWrite(1,0,
                   L"VfsSetupShadowFileObject() - Failed to get stream context for fileobject: %p\n Status: 0x%08X"
                   ,param_4);
          goto LAB_1c000f7f9;
        }
        if (-1 < iVar4) {
          lVar6 = VfsScbTableGetScb(local_48,*(undefined4 **)(param_2 + 4),
                                    *(undefined8 *)(param_2 + 2),'\x01',(undefined1 *)0x0);
          local_60 = lVar6;
        }
      }
      if (lVar6 == 0) {
        lVar6 = VfsScbUnitOpenScb(lVar9);
        if (lVar6 == 0) {
          iVar4 = VfsScbUnitCreateScb(param_6,lVar9,param_2,&local_60);
        }
        else {
          iVar4 = 0;
          local_60 = lVar6;
        }
        lVar6 = local_60;
        if (iVar4 < 0) goto LAB_1c000f7f9;
      }
    }
  }
  else {
    local_60 = 0;
    *param_9 = '\0';
    lVar6 = VfsScbTableGetScb(local_50,*(undefined4 **)(param_2 + 4),*(undefined8 *)(param_2 + 2),
                              '\x01',param_9);
    if (*param_9 == '\x01') {
      iVar4 = 0;
      lVar6 = 0;
    }
    else {
      if (lVar6 == 0) {
        iVar4 = VfsScbTableCreateScb(param_6,lVar9,param_2,&local_60,param_9);
      }
      else {
        iVar4 = 0;
        local_60 = lVar6;
      }
      lVar6 = local_60;
      if (iVar4 < 0) goto LAB_1c000f7f9;
    }
    if (*param_9 != '\0') goto LAB_1c000f7f9;
    iVar4 = VfsCheckShareAccess(param_1,lVar6,'\0','\x01');
    if (iVar4 < 0) goto LAB_1c000f7f9;
    bVar3 = true;
  }
  if ((*(uint *)(lVar6 + 0x110) & 8) == 0) {
    iVar4 = VfsCreateCcb(lVar6,param_1,param_5,param_6,param_7,param_8,&local_58);
    lVar8 = local_58;
    if (iVar4 < 0) {
    }
    else {
      VfsLinkCcb(local_58,(undefined1 *)(-(ulonglong)(param_8 != '\0') & (ulonglong)param_9));
      if (*param_9 == '\0') {
        if (bVar3) {
          *(uint *)(lVar8 + 4) = *(uint *)(lVar8 + 4) | 0x20;
          bVar3 = false;
        }
        uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 6) + 0x20);
        if ((*(uint *)(lVar8 + 4) & 4) == 0) {
          lVar7 = *(longlong *)(lVar8 + 0x48);
        }
        else {
          lVar7 = *(longlong *)(lVar8 + 0x30);
        }
        *(longlong *)(lVar1 + 0x18) = lVar6;
        *(longlong *)(lVar1 + 0x20) = lVar8;
        *(undefined1 *)(lVar1 + 0x48) = *(undefined1 *)(lVar7 + 0x48);
        if ((*(uint *)(lVar8 + 4) & 4) == 0) {
          *(undefined1 *)(lVar1 + 0x49) = *(undefined1 *)(lVar7 + 0x49);
          *(undefined1 *)(lVar1 + 0x4a) = *(undefined1 *)(lVar7 + 0x4a);
          *(undefined1 *)(lVar1 + 0x4b) = *(undefined1 *)(lVar7 + 0x4b);
          *(undefined1 *)(lVar1 + 0x4c) = *(undefined1 *)(lVar7 + 0x4c);
          *(undefined1 *)(lVar1 + 0x4d) = *(undefined1 *)(lVar7 + 0x4d);
          *(undefined1 *)(lVar1 + 0x4e) = *(undefined1 *)(lVar7 + 0x4e);
          *(undefined1 *)(lVar1 + 0x4f) = *(undefined1 *)(lVar7 + 0x4f);
        }
        *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(lVar7 + 0x28);
        *(undefined8 *)(lVar1 + 0x10) = uVar2;
        VfsUpdateFileSizes(param_6,lVar1);
      }
    }
  }
  else {
    iVar4 = -0x3fffffaa;
  }
LAB_1c000f7f9:
  if ((iVar4 < 0) || (*param_9 != '\0')) {
    if (lVar8 != 0) {
      VfsDeleteCcb(lVar8);
    }
    if (lVar6 != 0) {
      if (bVar3) {
        VfsRemoveShareAccess(lVar1,lVar6,'\0');
      }
      VfsScbClose(lVar6);
    }
  }
  if (lVar9 != 0) {
    FltReleaseContext(lVar9);
  }
  if (local_48 != 0) {
    FltReleaseContext();
  }
  return iVar4;
}



===== VfsUpdateFileSizes @ 1c000f874 =====

void VfsUpdateFileSizes(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x18);
  ExAcquireFastMutex(*(undefined8 *)(lVar1 + 0x30));
  ExAcquireFastMutex(*(undefined8 *)(lVar2 + 0x30));
  *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(lVar2 + 0x18);
  *(undefined8 *)(lVar1 + 0x20) = *(undefined8 *)(lVar2 + 0x20);
  *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(lVar2 + 0x28);
  ExReleaseFastMutex(*(undefined8 *)(lVar2 + 0x30));
  ExReleaseFastMutex(*(undefined8 *)(lVar1 + 0x30));
  return;
}



===== VfsCheckShareAccess @ 1c000f8f0 =====

undefined4 VfsCheckShareAccess(longlong param_1,longlong param_2,char param_3,char param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  uVar5 = 0;
  uVar1 = *(undefined2 *)(lVar3 + 0x2a);
  uVar4 = *(undefined8 *)(lVar3 + 8);
  uVar2 = *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x10);
  if (param_3 == '\0') {
    lVar3 = *(longlong *)(param_2 + 0x78);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar3 + 0x38,1);
  }
  LOCK();
  bVar6 = *(int *)(param_2 + 0x114) == 1;
  if (bVar6) {
    *(int *)(param_2 + 0x114) = 1;
  }
  UNLOCK();
  if (bVar6) {
    if (param_4 != '\0') {
      IoSetShareAccess(uVar2,uVar1,uVar4,param_2 + 0x11c);
    }
  }
  else {
    uVar5 = IoCheckShareAccess(uVar2,uVar1,uVar4,param_2 + 0x11c,param_4);
  }
  if (param_3 == '\0') {
    ExReleaseResourceLite(*(longlong *)(param_2 + 0x78) + 0x38);
    KeLeaveCriticalRegion();
  }
  return uVar5;
}



===== VfsRemoveShareAccess @ 1c000f9fc =====

void VfsRemoveShareAccess(undefined8 param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  
  if (param_3 == '\0') {
    lVar1 = *(longlong *)(param_2 + 0x78);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar1 + 0x38,1);
  }
  IoRemoveShareAccess(param_1,param_2 + 0x11c);
  if (param_3 == '\0') {
    ExReleaseResourceLite(*(longlong *)(param_2 + 0x78) + 0x38);
    KeLeaveCriticalRegion();
  }
  return;
}



===== VfsMarkFileDeleted @ 1c000faa4 =====

ulonglong VfsMarkFileDeleted(undefined8 param_1,undefined8 param_2,undefined8 param_3,char param_4,
                            char param_5)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 local_res10;
  undefined8 local_18 [2];
  
  local_18[0] = 0;
  local_res10 = 0;
  uVar1 = VfsOpenFile(param_1,0,param_3,0x100010,-(uint)(param_4 != '\0') & 3,
                      (param_4 != '\0') + 0x4020,local_18,&local_res10);
  uVar3 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    LogWrite(1,0,L"VfsMarkFileDeleted() - Failed to open file: %wZ\n Status: 0x%08X",param_3);
  }
  else {
    uVar2 = VfsMarkTombstone(param_1,local_res10,param_5);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      LogWrite(1,0,L"VfsMarkFileDeleted() - Failed to mark tombstone file: %wZ\n Status: 0x%08X",
               param_3);
    }
    ObfDereferenceObject(local_res10);
    FltClose(local_18[0]);
  }
  return uVar3;
}



===== VfsMarkTombstone @ 1c000fb98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VfsMarkTombstone(undefined8 param_1,undefined8 param_2,char param_3)

{
  ulonglong _Size;
  undefined8 uVar1;
  undefined1 auStack_88 [32];
  ulonglong local_68;
  void *pvStack_60;
  undefined4 local_58;
  undefined1 local_54;
  byte local_53;
  undefined2 local_52;
  undefined1 local_50;
  uint auStack_4f [5];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = 0;
  pvStack_60 = (void *)0x0;
  RtlInitAnsiString(&local_68,"$metastone");
  _Size = local_68 & 0xffff;
  if ((ushort)local_68 < 0x11) {
    local_58 = 0;
    local_54 = 0;
    local_53 = (byte)local_68;
    local_52 = 4;
    memcpy(&local_50,pvStack_60,_Size);
    *(undefined1 *)((longlong)auStack_4f + (_Size - 1)) = 0;
    *(uint *)((longlong)auStack_4f + (ulonglong)local_53) = (uint)(param_3 != '\0');
    uVar1 = FltSetEaFile(param_1,param_2,&local_58,0x20);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== VfsQueryTombstone @ 1c000fc70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VfsQueryTombstone(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  undefined1 auStack_b8 [32];
  undefined1 local_98;
  undefined4 *local_90;
  undefined4 local_88;
  undefined8 local_80;
  undefined1 local_78;
  undefined8 local_70;
  ulonglong local_68;
  void *pvStack_60;
  undefined4 local_58;
  undefined1 local_54;
  undefined1 local_53 [19];
  undefined1 local_40 [5];
  byte local_3b;
  int aiStack_37 [5];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_68 = 0;
  pvStack_60 = (void *)0x0;
  RtlInitAnsiString(&local_68,"$metastone");
  uVar1 = local_68 & 0xffff;
  if ((ushort)local_68 < 0x11) {
    local_58 = 0;
    local_54 = (undefined1)local_68;
    memcpy(local_53,pvStack_60,uVar1);
    local_70 = 0;
    local_90 = &local_58;
    local_78 = 1;
    local_80 = 0;
    local_88 = 0x18;
    local_98 = 1;
    local_53[uVar1] = 0;
    uVar1 = FltQueryEaFile(param_1,param_2,local_40,0x20);
    if (-1 < (int)uVar1) {
      uVar1 = (ulonglong)
              (-(uint)(*(int *)((longlong)aiStack_37 + (ulonglong)local_3b) != 1) & 0xc0000225);
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== VfsCheckFileDeleted @ 1c000fd68 =====

undefined8 VfsCheckFileDeleted(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  *param_3 = 0;
  uVar1 = FltQueryInformationFile(param_1,param_2,local_res18,8,6,0);
  if ((int)uVar1 == -0x3ffffedd) {
    *param_3 = 1;
    uVar1 = 0;
  }
  return uVar1;
}



===== VfsCreateFileByCallbackData @ 1c000fdb8 =====

ulonglong VfsCreateFileByCallbackData
                    (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                    char param_5,char param_6,char param_7,undefined4 *param_8,undefined8 param_9,
                    undefined8 param_10)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  char cVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong local_a0 [5];
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  uint local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  
  local_74 = 0;
  local_5c = 0;
  *param_8 = 0;
  uVar9 = 0x200;
  *(undefined8 *)(param_8 + 2) = 0;
  cVar7 = *(char *)(param_1 + 0x50);
  local_a0[0] = (ulonglong)(ushort)local_a0[0];
  if ((cVar7 == '\x01') ||
     ((cVar7 == '\0' && ((*(byte *)(*(longlong *)(param_1 + 0x10) + 6) & 1) != 0)))) {
    uVar9 = 0x600;
  }
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_78 = 0x30;
  local_70 = 0;
  local_60 = uVar9 | 0x40;
  if (*(char *)(lVar4 + 6) < '\0') {
    local_60 = uVar9;
  }
  local_58 = *(undefined8 *)(*(longlong *)(*(longlong *)(lVar4 + 0x18) + 8) + 0x40);
  local_50 = 0;
  uVar1 = *(undefined2 *)(lVar4 + 0x28);
  uVar10 = *(uint *)(lVar4 + 0x20) & 0xffffff;
  uVar9 = *(uint *)(*(longlong *)(lVar4 + 0x18) + 0x10);
  uVar2 = *(undefined2 *)(lVar4 + 0x2a);
  uVar5 = *(undefined8 *)(lVar4 + 0x38);
  uVar3 = *(undefined4 *)(lVar4 + 0x30);
  if (param_6 != '\0') {
    uVar9 = uVar9 & 0xfff2fea9 | 0x81;
    uVar10 = *(uint *)(lVar4 + 0x20) & 0xffefff;
  }
  if (param_5 != '\0') {
    uVar10 = 0x4021;
  }
  uVar6 = *(byte *)(lVar4 + 6) & 0xfffffffb;
  if (param_5 == '\0') {
    uVar6 = (uint)*(byte *)(lVar4 + 6);
  }
  uVar11 = uVar6 | 1;
  if (cVar7 != '\x01') {
    uVar11 = uVar6;
  }
  local_68 = param_4;
  if ((param_7 != '\0') ||
     ((cVar7 == '\0' &&
      (cVar7 = IoIsFileObjectIgnoringSharing(*(undefined8 *)(lVar4 + 8)), cVar7 != '\0')))) {
    uVar11 = uVar11 | 0x800;
  }
  local_a0[4] = 1;
  local_a0[1] = 0;
  local_a0[0] = 0x28;
  local_a0[2] = 0;
  local_a0[3] = 0;
  uVar8 = FltGetEcpListFromCallbackData(VfsData,param_1,local_a0 + 1);
  if (-1 < (int)uVar8) {
    uVar9 = FltCreateFileEx2(VfsData,param_3,param_9,param_10,uVar9,&local_78,param_8,
                             *(longlong *)(param_1 + 0x10) + 0x40,uVar1,uVar2,param_2,uVar10,uVar5,
                             uVar3,uVar11,local_a0);
    uVar8 = (ulonglong)uVar9;
    if ((int)uVar9 < 0) {
      LogWrite(1,0,
               L"VfsCreateFileByCallbackData() - Failed to create file by callback data: %wZ\n Access:0x%08X\n ShareAccess:0x%08X\n Attributes:0x%08X\n CreateDisposition:0x%08X\n CreateOptions:0x%08X\n CreateFlags:0x%08X\n Status: 0x%08X"
               ,param_4);
    }
  }
  return uVar8;
}



===== VfsCreateParentDirectories @ 1c0010014 =====

ulonglong VfsCreateParentDirectories
                    (undefined8 param_1,undefined8 param_2,longlong param_3,ushort *param_4,
                    ushort param_5)

{
  uint *puVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  ulonglong uVar8;
  short sVar9;
  ushort uVar10;
  ushort uVar11;
  undefined8 *puVar12;
  uint uVar13;
  ushort uVar14;
  wchar_t *pwVar15;
  char cVar16;
  uint uVar17;
  undefined8 in_stack_fffffffffffffe78;
  undefined4 in_stack_fffffffffffffe90;
  undefined4 in_stack_fffffffffffffe94;
  undefined4 in_stack_fffffffffffffe98;
  undefined4 in_stack_fffffffffffffe9c;
  char local_138;
  char local_137 [3];
  uint local_134;
  ulonglong local_130;
  longlong lStack_128;
  longlong local_120;
  char local_118;
  ushort local_114;
  uint local_110;
  ushort local_108 [4];
  longlong lStack_100;
  int local_f8;
  undefined4 uStack_f4;
  longlong lStack_f0;
  undefined8 local_e8;
  longlong lStack_e0;
  uint local_d8;
  ushort local_d0;
  ushort local_ce;
  undefined4 local_cc;
  longlong local_c8;
  undefined8 local_b8;
  short *psStack_b0;
  ulonglong local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  ushort *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  uint local_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined8 local_38;
  short *psStack_30;
  
  local_cc = 0;
  local_137[0] = '\0';
  local_120 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = (ushort *)0x0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_108[0] = 0;
  local_108[1] = 0;
  local_108[2] = 0;
  local_108[3] = 0;
  lStack_100 = 0;
  bVar4 = false;
  bVar3 = false;
  uStack_f4 = 0;
  local_138 = '\0';
  local_b8 = 0;
  psStack_b0 = (short *)0x0;
  local_130 = 0;
  lStack_128 = 0;
  local_134 = local_134 & 0xffffff00;
  uVar14 = param_5 >> 1;
  if (((param_5 < 4) || (*param_4 <= param_5)) ||
     (local_c8 = *(longlong *)(param_4 + 4), *(short *)(local_c8 + (ulonglong)uVar14 * 2) != 0x5c))
  {
    return 0xc000000d;
  }
  uVar10 = *param_4 >> 1;
  uVar11 = uVar10 - 1;
  if (uVar11 == uVar14) {
    return 0;
  }
  uVar10 = uVar10 - 2;
  if (*(short *)(local_c8 + (ulonglong)uVar11 * 2) != 0x5c) {
    uVar10 = uVar11;
  }
  local_d0 = param_5;
  local_ce = param_5;
  iVar7 = RtlCompareUnicodeString
                    (param_3 + 0x18,&local_d0,CONCAT71((int7)((ulonglong)local_c8 >> 8),1));
  if (iVar7 != 0) {
    LogWrite(1,0,
             L"VfsCreateParentDirectories() - Failed to create parent directories for store entry \'%wZ\' because the volume name did not match the COW mapping."
             ,param_4);
    return 0xc0000012;
  }
  uVar17 = 0;
  local_e8 = 0;
  lStack_e0 = 0;
  if (param_5 < *param_4) {
    lStack_e0 = (ulonglong)param_5 + *(longlong *)(param_4 + 4);
    sVar9 = *param_4 - param_5;
    local_e8._0_4_ = CONCAT22(sVar9,sVar9);
    uVar17 = (uint)local_e8;
    local_e8 = (ulonglong)(uint)local_e8;
  }
  local_a8 = (ulonglong)uVar17;
  lStack_a0 = lStack_e0;
  uVar8 = IsProcessElevated(&local_134);
  if ((int)uVar8 < 0) {
    return uVar8;
  }
  if (((char)local_134 == '\0') || ((*(uint *)(param_3 + 4) & 2) == 0)) {
    cVar16 = '\0';
  }
  else {
    cVar16 = '\x01';
  }
  uVar8 = MappingPrefixFileName
                    ((longlong *)(param_3 + 0x28),(ushort *)&local_a8,'\x01',cVar16,
                     in_stack_fffffffffffffe78,(longlong)local_137);
  if ((char)uVar8 == '\0') {
    LogWrite(1,0,
             L"VfsCreateParentDirectories() - Failed to create parent directories for store entry \'%wZ\' because it is not a child of the COW mapping."
             ,param_4);
    return 0xc000003a;
  }
  sVar9 = GetNumberComponents(&local_d0);
  local_134 = CONCAT22(local_134._2_2_,sVar9 + *(short *)(*(longlong *)(param_3 + 0x38) + 0x10));
  if (uVar14 < uVar10) {
    sVar9 = uVar10 * 2;
    uVar11 = uVar10;
    do {
      if (*(short *)(*(longlong *)(param_4 + 4) + (ulonglong)uVar11 * 2) == 0x5c) {
        if (bVar3) {
          bVar3 = false;
        }
        else {
          local_108[1] = sVar9;
          local_108[0] = sVar9;
          local_98 = CONCAT44(local_98._4_4_,0x30);
          uStack_90 = 0;
          uStack_80 = CONCAT44(uStack_80._4_4_,0x240);
          local_88 = local_108;
          local_78 = 0;
          uStack_70 = 0;
          in_stack_fffffffffffffe98 = 7;
          in_stack_fffffffffffffe90 = 0x80;
          lStack_100 = *(longlong *)(param_4 + 4);
          iVar7 = FltCreateFile(VfsData,param_2,&local_120,0x100000,&local_98,&local_60,0,0x80,7,1,
                                0x21,0,0,0x900);
          if (-1 < iVar7) {
            FltClose(local_120);
            local_120 = 0;
            bVar4 = true;
            break;
          }
          if (iVar7 == -0x3fffffc6) {
            bVar3 = true;
          }
        }
      }
      uVar11 = uVar11 - 1;
      sVar9 = sVar9 + -2;
    } while (uVar14 < uVar11);
  }
  cVar16 = local_137[0];
  if (bVar4) {
    uVar14 = local_108[0] >> 1;
  }
  lStack_f0 = 0;
  local_f8 = 0;
  if (local_137[0] == '\0') {
    puVar1 = *(uint **)(param_3 + 0x28);
    local_68 = 0;
    local_a8 = *(ulonglong *)(param_3 + 8);
    lStack_a0 = *(longlong *)(param_3 + 0x10);
    local_50 = *puVar1;
    uStack_4c = puVar1[1];
    uStack_48 = puVar1[2];
    uStack_44 = puVar1[3];
    uVar17 = (local_50 & 0xffff) + ((uint)local_a8 & 0xffff);
    local_d8 = uVar17;
    if ((0xfffe < uVar17) ||
       (lStack_f0 = ExAllocatePool2(0x100,uVar17 & 0xffff,0x74534656), lStack_f0 == 0)) {
LAB_1c00108a0:
      if (lStack_128 != 0) {
        ExFreePoolWithTag(lStack_128,0);
        lStack_128 = 0;
      }
      if (local_120 != 0) {
        FltClose();
      }
      if (lStack_f0 == 0) {
        return 0;
      }
      ExFreePoolWithTag(lStack_f0,0);
      return 0;
    }
    local_f8 = uVar17 * 0x10000;
    if ((short)local_a8 != 0) {
      RtlCopyUnicodeString(&local_f8,&local_a8);
    }
    RtlAppendUnicodeStringToString(&local_f8,&local_50);
  }
  uVar11 = (ushort)local_134;
LAB_1c00104c7:
  do {
    local_114 = uVar14 + 1;
    uVar14 = local_114;
    if (uVar10 < local_114) goto LAB_1c00108a0;
    lVar2 = *(longlong *)(param_4 + 4);
    if (*(short *)((ulonglong)local_114 * 2 + lVar2) == 0x5c) {
      uVar5 = (undefined2)((ulonglong)local_114 * 2);
      local_108[1] = uVar5;
      local_108[0] = uVar5;
      lStack_100 = lVar2;
      if (local_138 == '\0') {
        if (cVar16 == '\0') {
          uVar6 = GetNumberComponents(local_108);
          local_138 = '\x01';
          if (uVar6 <= uVar11) goto LAB_1c001052e;
        }
        else {
LAB_1c001052e:
          local_138 = '\0';
        }
        local_118 = local_138;
        if (local_138 != '\0') goto LAB_1c0010647;
        local_98 = CONCAT44(local_98._4_4_,0x30);
        uStack_90 = 0;
        uStack_80 = CONCAT44(uStack_80._4_4_,0x240);
        local_88 = local_108;
        local_78 = 0;
        uStack_70 = 0;
        in_stack_fffffffffffffe98 = 7;
        in_stack_fffffffffffffe90 = 0x80;
        iVar7 = FltCreateFile(VfsData,param_2,&local_120,0x100000,&local_98,&local_60,0,0x80,7,2,
                              0x21,0,0,0x900);
        if (-1 < iVar7) {
          FltClose(local_120);
          local_120 = 0;
          goto LAB_1c00104c7;
        }
        pwVar15 = 
        L"VfsCreateParentDirectories() - Failed to create parent directory \'%wZ\'.\n Status: 0x%08X"
        ;
      }
      else {
LAB_1c0010647:
        uVar17 = GetRemainingPath(local_108,uVar11,(short *)&local_b8);
        if ((int)uVar17 < 0) {
          LogWrite(1,0,
                   L"VfsCreateParentDirectories() - Failed to determine the remaining path of new COW directory \'%wZ\' after component #%d.\n Status: 0x%08X"
                   ,local_108);
          goto LAB_1c00104c7;
        }
        local_e8 = CONCAT44(uStack_f4,local_f8);
        lStack_e0 = lStack_f0;
        local_38 = local_b8;
        psStack_30 = psStack_b0;
        local_110 = (uint)(*(short *)(lStack_f0 + -2 + (ulonglong)((ushort)local_f8 >> 1) * 2) ==
                          0x5c);
        if (*psStack_b0 == 0x5c) {
          local_110 = local_110 + 1;
        }
        if (local_110 == 2) {
          local_e8 = CONCAT62(local_e8._2_6_,(ushort)local_f8 - 2);
          local_110 = 1;
        }
        uVar17 = local_110;
        if (local_110 == 0) {
          uVar13 = (ushort)local_e8 + 2 + (uint)(ushort)local_b8;
        }
        else {
          uVar13 = (uint)(ushort)local_b8 + (uint)(ushort)local_e8;
        }
        local_134 = uVar13;
        if ((0xfffe < uVar13) ||
           (lStack_128 = ExAllocatePool2(0x100,uVar13 & 0xffff,0x74534656), lStack_128 == 0))
        goto LAB_1c00104c7;
        uVar8 = local_130 >> 0x20;
        local_130._0_4_ = uVar13 << 0x10;
        local_130 = CONCAT44((int)uVar8,(int)local_130);
        uVar6 = 0;
        if ((ushort)local_e8 != 0) {
          RtlCopyUnicodeString(&local_130,&local_e8);
          uVar6 = (ushort)local_e8;
        }
        if (uVar17 == 0) {
          *(undefined2 *)(lStack_128 + (ulonglong)(uVar6 >> 1) * 2) = 0x5c;
          local_130 = CONCAT62(local_130._2_6_,(short)local_130 + 2);
        }
        puVar12 = &local_38;
        RtlAppendUnicodeStringToString(&local_130);
        iVar7 = VfsCopyFile(param_1,puVar12,&local_130,param_2,0,local_108,'\x01',
                            CONCAT44(in_stack_fffffffffffffe94,in_stack_fffffffffffffe90),
                            CONCAT44(in_stack_fffffffffffffe9c,in_stack_fffffffffffffe98),'\x01');
        if (lStack_128 != 0) {
          ExFreePoolWithTag();
        }
        lStack_128 = 0;
        local_130 = local_130 & 0xffffffff00000000;
        if (-1 < iVar7) goto LAB_1c00104c7;
        pwVar15 = 
        L"VfsCreateParentDirectories() - Failed to copy to parent directory \'%wZ\' from package.\n Status: 0x%08X"
        ;
      }
      LogWrite(1,0,pwVar15,local_108);
    }
  } while( true );
}



===== VfsDeleteFile @ 1c001092c =====

int VfsDeleteFile(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_res10 [2];
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res10[0] = 0;
  iVar1 = VfsOpenFile(param_1,0,param_3,0x110000,1,0x5020,&local_res20,local_res10);
  if (iVar1 < 0) {
    if ((iVar1 != -0x3fffffcc) && (iVar1 != -0x3fffffc6)) {
      LogWrite(1,0,L"VfsDeleteFile() - Failed to open file: %wZ\n Status: 0x%08X",param_3);
      return iVar1;
    }
  }
  else {
    ObfDereferenceObject(local_res10[0]);
    FltClose(local_res20);
  }
  return 0;
}



===== VfsOpenFile @ 1c00109dc =====

void VfsOpenFile(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_20 = 0x240;
  local_48 = 0;
  uStack_40 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_2;
  local_28 = param_3;
  FltCreateFileEx2(VfsData,param_1,param_7,param_8,param_4,&local_38,&local_48,0,0,7,param_5,param_6
                   ,0,0,0x900,0);
  return;
}



===== VfsQueryDirectoryFileName @ 1c0010a98 =====

int VfsQueryDirectoryFileName
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = 0;
  local_10 = 0;
  iVar1 = VfsOpenFile(param_1,0,param_2,0x100001,1,0x4021,&local_10,&local_18);
  if (iVar1 < 0) {
    LogWrite(1,0,L"VfsQueryDirectoryFileName() - Failed to open file: %wZ\n Status: 0x%08X",param_2)
    ;
  }
  else {
    iVar1 = FltQueryDirectoryFile(param_1,local_18,param_4,param_5,0xc,1,param_3,1,0);
    ObfDereferenceObject(local_18);
    FltClose(local_10);
  }
  return iVar1;
}



===== VfsAppendFileName @ 1c0010b9c =====

undefined8 VfsAppendFileName(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  undefined2 local_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  longlong lStack_20;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  if (((uVar1 < 2) || (uVar2 < 2)) || (**(short **)(param_2 + 4) == 0x5c)) {
    return 0xc000000d;
  }
  sVar3 = *(short *)(*(longlong *)(param_1 + 4) + -2 + (ulonglong)(uVar1 >> 1) * 2);
  uVar4 = uVar2 + 2;
  if (sVar3 == 0x5c) {
    uVar4 = uVar2;
  }
  if ((ushort)(param_1[1] - uVar1) < uVar4) {
    uVar5 = (uint)uVar4 + (uint)uVar1;
    uStack_24 = 0;
    if (0xffff < uVar5) {
      return 0xc0000106;
    }
    lStack_20 = ExAllocatePool2(0x100,uVar5 & 0xffff,0x74534656);
    if (lStack_20 == 0) {
      return 0xc000009a;
    }
    local_28 = 0;
    uStack_26 = (undefined2)uVar5;
    RtlCopyUnicodeString(&local_28,param_1);
    if (*(longlong *)(param_1 + 4) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 4),0);
    }
    *(ulonglong *)param_1 = CONCAT44(uStack_24,CONCAT22(uStack_26,local_28));
    *(longlong *)(param_1 + 4) = lStack_20;
  }
  if (sVar3 != 0x5c) {
    *(undefined2 *)(*(longlong *)(param_1 + 4) + (ulonglong)(*param_1 >> 1) * 2) = 0x5c;
    *param_1 = *param_1 + 2;
  }
  RtlAppendUnicodeStringToString(param_1,param_2);
  return 0;
}



===== VfsCreateInitialNameForNormalize @ 1c0010cf0 =====

undefined8 VfsCreateInitialNameForNormalize(ushort *param_1,ushort *param_2,undefined2 *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)*param_2 + (uint)*param_1;
  uVar3 = uVar4 + 2;
  if (*(short *)(*(longlong *)(param_1 + 4) + -2 + (ulonglong)(*param_1 >> 1) * 2) != 0x5c) {
    uVar3 = uVar4;
  }
  if (uVar3 < 0x10000) {
    uVar3 = uVar3 + 0x200;
    if (0xffff < uVar3) {
      uVar3 = 0xfffe;
    }
    lVar2 = ExAllocatePool2(0x100,uVar3 & 0xffff,0x74534656);
    *(longlong *)(param_3 + 4) = lVar2;
    if (lVar2 == 0) {
      uVar1 = 0xc000009a;
    }
    else {
      *param_3 = 0;
      param_3[1] = (short)uVar3;
      RtlCopyUnicodeString(param_3,param_1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc0000106;
  }
  return uVar1;
}



===== VfsGetFileNameInfoForFileObject @ 1c0010da4 =====

ulonglong VfsGetFileNameInfoForFileObject
                    (uint *param_1,longlong param_2,undefined8 param_3,uint param_4,
                    undefined8 *param_5)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  
  local_res8 = 0;
  cVar1 = (char)(*(uint **)(param_1 + 4))[1];
  if (((((**(uint **)(param_1 + 4) & 2) != 0) ||
       (((lVar3 = IoGetTopLevelIrp(), lVar3 != 0 && (cVar1 != '\0')) ||
        ((*(uint *)(param_2 + 0x50) & 0x4000) != 0)))) ||
      (((byte)(cVar1 + 6U) < 5 ||
       ((((*param_1 & 0x80000) != 0 && (cVar1 == -1)) ||
        (cVar1 = KeAreAllApcsDisabled(), cVar1 != '\0')))))) &&
     (((param_4 & 0xff00) - 0x100 & 0xfffffdff) == 0)) {
    return 0xc01c0005;
  }
  uVar4 = FltGetFileNameInformationUnsafe(param_2,param_3,param_4,&local_res8);
  if (-1 < (int)uVar4) {
    uVar2 = FltParseFileNameInformation(local_res8);
    uVar4 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      FltReleaseFileNameInformation(local_res8);
    }
    else {
      *param_5 = local_res8;
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== VfsGetFileNameInformation @ 1c0010ea4 =====

int VfsGetFileNameInformation
              (longlong param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
              short *param_5)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  longlong local_res20;
  
  local_res20 = 0;
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x10) + 6);
  if ((bVar1 & 4) == 0) {
    iVar4 = FltGetFileNameInformation(param_1,param_2,&local_res20,param_4,0);
  }
  else {
    *(byte *)(*(longlong *)(param_1 + 0x10) + 6) = bVar1 & 0xfb;
    iVar4 = FltGetFileNameInformation
                      (param_1,(uint)param_2 & 0xff0003ff | 0x300,&local_res20,param_4,0);
    *(byte *)(*(longlong *)(param_1 + 0x10) + 6) = *(byte *)(*(longlong *)(param_1 + 0x10) + 6) | 4;
  }
  if ((-1 < iVar4) && (iVar4 = FltParseFileNameInformation(local_res20), -1 < iVar4)) {
    uVar2 = *(ushort *)(local_res20 + 0x18);
    if (param_5 != (short *)0x0) {
      sVar3 = *(short *)(local_res20 + 8) - uVar2;
      *param_5 = sVar3;
      param_5[1] = sVar3;
      *(ulonglong *)(param_5 + 4) = (ulonglong)uVar2 + *(longlong *)(local_res20 + 0x10);
    }
    *param_3 = local_res20;
  }
  if ((iVar4 < 0) && (local_res20 != 0)) {
    FltReleaseFileNameInformation();
  }
  return iVar4;
}



===== VfsNormalizeFileName @ 1c0010fa4 =====

int VfsNormalizeFileName
              (undefined8 param_1,ushort *param_2,ushort *param_3,ushort *param_4,
              undefined1 *param_5)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  ushort uVar6;
  ulonglong *puVar7;
  ulonglong uVar8;
  short sVar9;
  ushort uVar10;
  undefined1 uVar11;
  undefined8 local_a8;
  short *psStack_a0;
  ushort local_98 [4];
  longlong lStack_90;
  undefined8 local_88;
  longlong lStack_80;
  undefined8 local_78;
  longlong lStack_70;
  ulonglong local_68;
  short *psStack_60;
  undefined8 local_58;
  longlong lStack_50;
  longlong local_48;
  ulonglong local_38;
  longlong lStack_30;
  
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  lStack_90 = 0;
  local_48 = 0;
  *param_5 = 0;
  if ((*param_2 < 2) || (*param_3 < 2)) {
LAB_1c0011402:
    iVar3 = -0x3ffffff3;
  }
  else {
    local_a8 = *(undefined8 *)param_3;
    psStack_a0 = *(short **)(param_3 + 4);
    if (**(short **)(param_3 + 4) == 0x5c) {
      psStack_a0 = *(short **)(param_3 + 4) + 1;
      uVar2 = (ushort)local_a8 - 2;
      uVar8 = (ulonglong)local_a8 >> 0x10;
      local_a8 = CONCAT62((int6)uVar8,uVar2);
      if (uVar2 < 2) goto LAB_1c0011402;
    }
    cVar1 = FsRtlDoesNameContainWildCards(&local_a8);
    if (cVar1 == '\0') {
      uVar11 = 0;
      lVar4 = ExAllocatePool2(0x100,0x210,0x6e474656);
      local_48 = lVar4;
      if (lVar4 == 0) {
        iVar3 = -0x3fffff66;
      }
      else {
        uVar5 = VfsCreateInitialNameForNormalize(param_2,(ushort *)&local_a8,local_98);
        iVar3 = (int)uVar5;
        uVar2 = 0;
        if (-1 < iVar3) {
          while( true ) {
            if ((ushort)local_a8 >> 1 <= uVar2) break;
            local_68 = 0;
            psStack_60 = (short *)0x0;
            local_58 = 0;
            lStack_50 = 0;
            sVar9 = 0;
            uVar10 = uVar2;
            if ((uVar2 == 0) && (*psStack_a0 == 0x5c)) {
              uVar10 = 1;
            }
            for (uVar6 = uVar10; (uVar6 < (ushort)local_a8 >> 1 && (psStack_a0[uVar6] != 0x5c));
                uVar6 = uVar6 + 1) {
              sVar9 = sVar9 + 1;
            }
            if (sVar9 == 0) {
              iVar3 = -0x3ffffff3;
              goto LAB_1c00113cd;
            }
            local_68 = (ulonglong)CONCAT22(sVar9 * 2,sVar9 * 2);
            psStack_60 = psStack_a0 + uVar10;
            cVar1 = RtlIsNameLegalDOS8Dot3(&local_68,0,0);
            if (cVar1 == '\0') {
              puVar7 = &local_68;
            }
            else {
              iVar3 = VfsQueryDirectoryFileName(param_1,local_98,&local_68,lVar4,0x210);
              if (iVar3 < 0) {
                if ((0x2b < iVar3 + 0x3ffffff1U) ||
                   ((0x82000000001U >> ((longlong)(int)(iVar3 + 0x3ffffff1U) & 0x3fU) & 1) == 0))
                goto LAB_1c00113cd;
                if ((iVar3 == -0x3fffffcc) ||
                   ((iVar3 == -0x3fffffc6 ||
                    (uVar11 = 0, (ushort)(uVar6 + 1) < (ushort)local_a8 >> 1)))) {
                  uVar11 = 1;
                }
                if ((ushort)(uVar2 * 2) < (ushort)local_a8) {
                  lStack_80 = (ulonglong)(ushort)(uVar2 * 2) + (longlong)psStack_a0;
                  sVar9 = (ushort)local_a8 + uVar2 * -2;
                  local_88 = (ulonglong)CONCAT22(sVar9,sVar9);
                }
                else {
                  lStack_80 = 0;
                  local_88 = 0;
                }
                local_58 = local_88;
                lStack_50 = lStack_80;
                uVar5 = VfsAppendFileName(local_98,(ushort *)&local_58);
                iVar3 = (int)uVar5;
                if (iVar3 < 0) goto LAB_1c00113cd;
                break;
              }
              local_58._0_4_ = CONCAT22(*(undefined2 *)(lVar4 + 8),*(undefined2 *)(lVar4 + 8));
              lStack_50 = lVar4 + 0xc;
              puVar7 = &local_58;
            }
            uVar5 = VfsAppendFileName(local_98,(ushort *)puVar7);
            iVar3 = (int)uVar5;
            if (iVar3 < 0) goto LAB_1c00113cd;
            uVar2 = uVar6 + 1;
          }
          uVar2 = *param_2;
          if (uVar2 < local_98[0]) {
            lStack_70 = lStack_90 + (ulonglong)uVar2;
            local_78 = (ulonglong)CONCAT22(local_98[0] - uVar2,local_98[0] - uVar2);
          }
          else {
            lStack_70 = 0;
            local_78 = 0;
          }
          local_38 = local_78;
          lStack_30 = lStack_70;
          uVar8 = 0;
          while( true ) {
            uVar2 = (ushort)local_78;
            if (uVar2 >> 1 <= (ushort)uVar8) break;
            *(undefined2 *)(lStack_90 + uVar8 * 2) = *(undefined2 *)(lStack_70 + uVar8 * 2);
            uVar8 = (ulonglong)(ushort)((ushort)uVar8 + 1);
          }
          *param_4 = uVar2;
          param_4[1] = uVar2;
          *(longlong *)(param_4 + 4) = lStack_90;
          lStack_90 = 0;
          *param_5 = uVar11;
        }
      }
LAB_1c00113cd:
      if (lVar4 != 0) {
        ExFreePoolWithTag(lVar4,0x6e474656);
      }
      if (lStack_90 != 0) {
        ExFreePoolWithTag(lStack_90,0);
      }
    }
    else {
      iVar3 = -0x3fffffcd;
    }
  }
  return iVar3;
}



===== VfsRenameFile @ 1c001142c =====

undefined4
VfsRenameFile(undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort *param_4,
             undefined1 param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar1 = *param_4;
  puVar3 = (undefined1 *)ExAllocatePool2(0x100,uVar1 + 0x14,0x6e474656);
  if (puVar3 == (undefined1 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar3 = param_5;
    *(undefined8 *)(puVar3 + 8) = param_3;
    *(uint *)(puVar3 + 0x10) = (uint)*param_4;
    memcpy(puVar3 + 0x14,*(void **)(param_4 + 4),(ulonglong)*param_4);
    uVar2 = FltSetInformationFile(param_1,param_2,puVar3,uVar1 + 0x14,10);
    ExFreePoolWithTag(puVar3,0x6e474656);
  }
  return uVar2;
}



===== VfsSetRenameInformation @ 1c00114f8 =====

ulonglong VfsSetRenameInformation
                    (undefined8 param_1,undefined8 param_2,longlong param_3,undefined1 *param_4,
                    undefined4 param_5)

{
  uint uVar1;
  ulonglong uVar2;
  longlong local_18 [2];
  
  local_18[0] = 0;
  if (((*(short *)(param_4 + 0x14) == 0x5c) || (*(longlong *)(param_4 + 8) != 0)) && (param_3 != 0))
  {
    uVar2 = FltAllocateCallbackData(param_1,param_2,local_18);
    if (-1 < (int)uVar2) {
      *(undefined1 *)(*(longlong *)(local_18[0] + 0x10) + 4) = 6;
      *(undefined4 *)(*(longlong *)(local_18[0] + 0x10) + 0x18) = param_5;
      *(undefined4 *)(*(longlong *)(local_18[0] + 0x10) + 0x20) = 10;
      *(longlong *)(*(longlong *)(local_18[0] + 0x10) + 0x28) = param_3;
      *(undefined8 *)(*(longlong *)(local_18[0] + 0x10) + 0x30) = 0;
      *(undefined1 *)(*(longlong *)(local_18[0] + 0x10) + 0x30) = *param_4;
      *(undefined1 **)(*(longlong *)(local_18[0] + 0x10) + 0x38) = param_4;
      FltPerformSynchronousIo(local_18[0]);
      uVar1 = *(uint *)(local_18[0] + 0x18);
      FltFreeCallbackData();
      uVar2 = (ulonglong)uVar1;
    }
  }
  else {
    uVar2 = FltSetInformationFile(param_1,param_2,param_4,param_5,10);
  }
  return uVar2;
}



===== VfsUpdateOpenTargetDirectoryFileName @ 1c00115f8 =====

void VfsUpdateOpenTargetDirectoryFileName(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ulonglong uVar4;
  
  uVar2 = *(ushort *)(param_1 + 0x58) >> 1;
  if (uVar2 != 0) {
    uVar3 = uVar2 - 1;
    if (*(short *)(*(longlong *)(param_1 + 0x60) + (ulonglong)uVar3 * 2) == 0x5c) {
      if (uVar3 < 2) {
        return;
      }
      uVar3 = uVar2 - 2;
    }
    uVar2 = 0;
    if (uVar3 != 0) {
      while (*(short *)(*(longlong *)(param_1 + 0x60) + (ulonglong)uVar3 * 2) != 0x5c) {
        uVar3 = uVar3 - 1;
        if (uVar3 == 0) {
          return;
        }
      }
      uVar3 = uVar3 + 1;
      if ((uVar3 != 0) &&
         (uVar1 = *(ushort *)(param_1 + 0x58) + uVar3 * -2, *(ushort *)(param_1 + 0x58) = uVar1,
         (uVar1 & 0xfffe) != 0)) {
        do {
          uVar4 = (ulonglong)uVar2;
          uVar2 = uVar2 + 1;
          *(undefined2 *)(*(longlong *)(param_1 + 0x60) + uVar4 * 2) =
               *(undefined2 *)(*(longlong *)(param_1 + 0x60) + (uVar4 + uVar3) * 2);
        } while (uVar2 < *(ushort *)(param_1 + 0x58) >> 1);
      }
    }
  }
  return;
}



===== RtlStringCchPrintfW @ 1c00116a4 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== VfsGetDeviceVolumeNameFromVolumeName @ 1c0011720 =====

ulonglong VfsGetDeviceVolumeNameFromVolumeName
                    (undefined2 *param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 local_res18;
  
  uVar3 = 0;
  *(undefined8 *)(param_3 + 2) = 0;
  local_res18 = 0;
  cVar2 = RtlPrefixUnicodeString(&DAT_1c00176f0,param_1,1);
  if (cVar2 == '\0') {
    uVar5 = FltGetVolumeFromName(VfsData,param_1,&local_res18);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    uVar3 = VfsGetVolumeName(local_res18,param_3);
    FltObjectDereference(local_res18);
  }
  else {
    uVar1 = *param_1;
    lVar4 = ExAllocatePool2(0x100,uVar1,0x6e564656);
    *(longlong *)(param_3 + 2) = lVar4;
    if (lVar4 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      *(undefined2 *)param_3 = 0;
      *(undefined2 *)((longlong)param_3 + 2) = uVar1;
      RtlCopyUnicodeString(param_3,param_1);
    }
  }
  return (ulonglong)uVar3;
}



===== VfsGetInstanceFromVolumeName @ 1c0011808 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VfsGetInstanceFromVolumeName(undefined8 param_1,longlong *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStack_138 [32];
  uint *local_118;
  uint local_108 [2];
  longlong local_100;
  undefined1 local_f8 [192];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_138;
  memset(local_f8,0,0xc0);
  lVar5 = 0;
  local_108[0] = 0;
  puVar3 = local_f8;
  iVar2 = 0;
  uVar6 = 0x18;
  while( true ) {
    local_118 = local_108;
    uVar4 = FltEnumerateInstances(0,VfsData,puVar3,uVar6);
    if (-1 < (int)uVar4) break;
    if ((int)uVar4 != -0x3fffffdd) {
      return uVar4;
    }
    if (puVar3 != local_f8) {
      ExFreePoolWithTag(puVar3,0x6e474656);
    }
    uVar6 = local_108[0];
    if (iVar2 == 2) {
      return 0xc0000001;
    }
    puVar3 = (undefined1 *)ExAllocatePool2(0x100,(ulonglong)local_108[0] << 3,0x6e474656);
    if (puVar3 == (undefined1 *)0x0) {
      return 0xc000009a;
    }
    iVar2 = iVar2 + 1;
  }
  uVar8 = 0;
  if (local_108[0] != 0) {
    do {
      local_100 = 0;
      iVar2 = FltGetInstanceContext(*(undefined8 *)(puVar3 + uVar8 * 8),&local_100);
      if (-1 < iVar2) {
        cVar1 = RtlEqualUnicodeString(local_100 + 8,param_1,1);
        if (cVar1 != '\0') {
          lVar5 = *(longlong *)(puVar3 + uVar8 * 8);
          FltReleaseContext(local_100);
          break;
        }
        FltReleaseContext();
      }
      uVar6 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar6;
    } while (uVar6 < local_108[0]);
  }
  uVar8 = 0;
  uVar6 = local_108[0];
  if (local_108[0] != 0) {
    do {
      if (*(longlong *)(puVar3 + uVar8 * 8) != lVar5) {
        FltObjectDereference(*(longlong *)(puVar3 + uVar8 * 8));
        uVar6 = local_108[0];
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < uVar6);
  }
  if (puVar3 != local_f8) {
    ExFreePoolWithTag(puVar3,0x6e474656);
  }
  if (lVar5 == 0) {
    uVar4 = 0xc0000225;
  }
  else {
    *param_2 = lVar5;
    uVar4 = 0;
  }
  return uVar4;
}



===== VfsGetVolumeName @ 1c0011a00 =====

int VfsGetVolumeName(undefined8 param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  longlong lVar3;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  *(undefined8 *)(param_2 + 2) = 0;
  *param_2 = 0;
  iVar2 = FltGetVolumeName(param_1,param_2,local_res10);
  if (iVar2 == -0x3fffffdd) {
    uVar1 = (undefined2)local_res10[0];
    lVar3 = ExAllocatePool2(0x100,(undefined2)local_res10[0],0x6e564656);
    *(longlong *)(param_2 + 2) = lVar3;
    if (lVar3 == 0) {
      return -0x3fffff66;
    }
    *(undefined2 *)param_2 = 0;
    *(undefined2 *)((longlong)param_2 + 2) = uVar1;
    iVar2 = FltGetVolumeName(param_1,param_2,local_res10);
    if ((iVar2 < 0) && (*(longlong *)(param_2 + 2) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
      *(undefined8 *)(param_2 + 2) = 0;
    }
  }
  return iVar2;
}



===== VfsGetVpbFromInstance @ 1c0011acc =====

ulonglong VfsGetVpbFromInstance(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res18;
  longlong local_res20;
  
  local_res18 = 0;
  local_res20 = 0;
  uVar2 = FltGetVolumeFromInstance(param_1,&local_res18);
  if (-1 < (int)uVar2) {
    uVar1 = FltGetDiskDeviceObject(local_res18,&local_res20);
    uVar2 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      *param_2 = *(undefined8 *)(local_res20 + 0x38);
      ObfDereferenceObject();
    }
    FltObjectDereference(local_res18);
  }
  return uVar2;
}



===== IsProcessElevated @ 1c0011b54 =====

ulonglong IsProcessElevated(undefined8 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  int local_res10 [2];
  undefined4 local_res18 [2];
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  uVar2 = ZwOpenProcessTokenEx(0xffffffffffffffff,8,0x200,&local_res20);
  if (-1 < (int)uVar2) {
    uVar1 = ZwQueryInformationToken(local_res20,0x14,local_res10,4,local_res18);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      ZwClose();
    }
    else {
      ZwClose(local_res20);
      *(bool *)param_1 = local_res10[0] != 0;
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== VfsAdjustDeviceStackSizeForIoRedirection @ 1c0011c04 =====

undefined8 VfsAdjustDeviceStackSizeForIoRedirection(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  if (param_1 == param_2) {
    uVar1 = 0;
  }
  else {
    uVar1 = FltIsIoRedirectionAllowed(param_1,param_2,local_res8);
    if ((-1 < (int)uVar1) && (local_res8[0] == '\0')) {
      uVar1 = FltAdjustDeviceStackSizeForIoRedirection(param_1,param_2,0);
    }
  }
  return uVar1;
}



===== ~prefix_tree<PrefixTreeContext,PrefixTreeAllocator> @ 1c0011c68 =====

/* public: __cdecl appv::shared::vfs::prefix_tree<class PrefixTreeContext,class
   PrefixTreeAllocator>::~prefix_tree<class PrefixTreeContext,class PrefixTreeAllocator>(void)
   __ptr64 */

void __thiscall
appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::
~prefix_tree<PrefixTreeContext,PrefixTreeAllocator>
          (prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *this)

{
  char cVar1;
  
  if (*(longlong *)this != 0) {
    remove_directory((prefix_tree_table *)this);
  }
  if (*(longlong *)(this + 8) != 0) {
    cVar1 = RtlIsGenericTableEmptyAvl();
    if (cVar1 != '\0') {
      if (PrefixTreeAllocator::LookasideInited == false) {
        ExFreePoolWithTag(*(undefined8 *)(this + 8),0x30704656);
      }
      else {
        ExFreeToPagedLookasideList
                  (&PrefixTreeAllocator::PrefixTableLookasideList,*(undefined8 *)(this + 8));
      }
      *(undefined8 *)(this + 8) = 0;
    }
  }
  if (*(longlong *)this != 0) {
    cVar1 = RtlIsGenericTableEmptyAvl();
    if (cVar1 != '\0') {
      if (PrefixTreeAllocator::LookasideInited == false) {
        ExFreePoolWithTag(*(undefined8 *)this,0x30704656);
      }
      else {
        ExFreeToPagedLookasideList
                  (&PrefixTreeAllocator::PrefixTableLookasideList,*(undefined8 *)this);
      }
      *(undefined8 *)this = 0;
    }
  }
  return;
}



===== ~PrefixTreeContext @ 1c0011d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl PrefixTreeContext::~PrefixTreeContext(void) __ptr64 */

void __thiscall PrefixTreeContext::~PrefixTreeContext(PrefixTreeContext *this)

{
  if ((releaseCallback != (_func_void_void_ptr *)0x0) && (*(void **)this != (void *)0x0)) {
    (*releaseCallback)(*(void **)this);
  }
  return;
}



===== allocate @ 1c0011d5c =====

/* public: static void * __ptr64 __cdecl PrefixTreeAllocator::allocate(unsigned __int64,bool) */

void * __cdecl PrefixTreeAllocator::allocate(__uint64 param_1,bool param_2)

{
  void *pvVar1;
  _PAGED_LOOKASIDE_LIST *p_Var2;
  
  if ((LookasideInited) && (param_2)) {
    if (param_1 == 0xd0) {
      p_Var2 = &PrefixEntryLookasideList;
    }
    else if (param_1 == 0x50) {
      p_Var2 = &PrefixShortNameEntryLookasideList;
    }
    else if (param_1 == 0x68) {
      p_Var2 = &PrefixTableLookasideList;
    }
    else {
      if (param_1 != 0x10) goto LAB_1c0011db8;
      p_Var2 = &PrefixTreeLookasideList;
    }
    pvVar1 = (void *)ExAllocateFromPagedLookasideList(p_Var2);
  }
  else {
LAB_1c0011db8:
    pvVar1 = (void *)ExAllocatePool2(0x100,param_1,0x30704656);
  }
  return pvVar1;
}



===== deallocate @ 1c0011de0 =====

/* public: static void __cdecl PrefixTreeAllocator::deallocate(void * __ptr64,unsigned __int64) */

void __cdecl PrefixTreeAllocator::deallocate(void *param_1,__uint64 param_2)

{
  _PAGED_LOOKASIDE_LIST *p_Var1;
  
  if ((LookasideInited) && (param_2 != 0)) {
    if (param_2 == 0xd0) {
      p_Var1 = &PrefixEntryLookasideList;
    }
    else if (param_2 == 0x50) {
      p_Var1 = &PrefixShortNameEntryLookasideList;
    }
    else if (param_2 == 0x68) {
      p_Var1 = &PrefixTableLookasideList;
    }
    else {
      if (param_2 != 0x10) {
        return;
      }
      p_Var1 = &PrefixTreeLookasideList;
    }
    ExFreeToPagedLookasideList(p_Var1,param_1);
  }
  else {
    ExFreePoolWithTag(param_1,0x30704656);
  }
  return;
}



===== find_avl @ 1c0011e68 =====

/* private: static struct appv::shared::vfs::prefix_tree_name_entry<class PrefixTreeContext> *
   __ptr64 __cdecl appv::shared::vfs::prefix_tree<class PrefixTreeContext,class
   PrefixTreeAllocator>::find_avl(struct appv::shared::vfs::prefix_tree_table const & __ptr64,struct
   _UNICODE_STRING const & __ptr64) */

prefix_tree_name_entry<PrefixTreeContext> * __cdecl
appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::find_avl
          (prefix_tree_table *param_1,_UNICODE_STRING *param_2)

{
  prefix_tree_name_entry<PrefixTreeContext> *ppVar1;
  longlong lVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  if (*(longlong *)param_1 != 0) {
    ppVar1 = (prefix_tree_name_entry<PrefixTreeContext> *)RtlLookupElementGenericTableAvl();
    if (ppVar1 != (prefix_tree_name_entry<PrefixTreeContext> *)0x0) {
      return ppVar1;
    }
    if ((*(longlong *)(param_1 + 8) != 0) && (*(ushort *)param_2 < 0x19)) {
      uVar3 = *(ushort *)param_2 >> 1;
      uVar5 = 0;
      uVar4 = 0;
      if (uVar3 != 0) {
        do {
          if (*(short *)(*(longlong *)(param_2 + 8) + (ulonglong)uVar4 * 2) == 0x2e) {
            uVar5 = (uVar3 - uVar4) - 1;
            uVar3 = uVar4;
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
      }
      if (((uVar3 < 9) && (uVar5 < 4)) &&
         (lVar2 = RtlLookupElementGenericTableAvl(*(longlong *)(param_1 + 8),param_2), lVar2 != 0))
      {
        return *(prefix_tree_name_entry<PrefixTreeContext> **)(lVar2 + 0x28);
      }
    }
  }
  return (prefix_tree_name_entry<PrefixTreeContext> *)0x0;
}



===== insert_avl @ 1c0011f30 =====

/* private: static long __cdecl appv::shared::vfs::prefix_tree<class PrefixTreeContext,class
   PrefixTreeAllocator>::insert_avl(struct appv::shared::vfs::prefix_tree_table & __ptr64,struct
   _UNICODE_STRING const & __ptr64,struct _UNICODE_STRING const & __ptr64,struct
   appv::shared::vfs::prefix_tree_name_entry<class PrefixTreeContext> * __ptr64 & __ptr64) */

long __cdecl
appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::insert_avl
          (prefix_tree_table *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3,
          prefix_tree_name_entry<PrefixTreeContext> **param_4)

{
  char cVar1;
  longlong lVar2;
  prefix_tree_name_entry<PrefixTreeContext> *_Dst;
  prefix_tree_name_entry<PrefixTreeContext> *ppVar3;
  undefined8 uVar4;
  char local_res18 [8];
  char local_38 [16];
  
  if (0x18 < *(ushort *)param_3) {
    return -0x3ffffff3;
  }
  if (*(longlong *)param_1 == 0) {
    if (PrefixTreeAllocator::LookasideInited) {
      lVar2 = ExAllocateFromPagedLookasideList(&PrefixTreeAllocator::PrefixTableLookasideList);
    }
    else {
      lVar2 = ExAllocatePool2(0x100,0x68,0x30704656);
    }
    *(longlong *)param_1 = lVar2;
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
    RtlInitializeGenericTableAvl
              (lVar2,named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>
                     ::named_avl_compare,
               named_avl_table<appv::shared::vfs::prefix_tree_name_entry<PrefixTreeContext>,PrefixTreeAllocator>
               ::named_avl_allocate,
               named_avl_table<appv::shared::vfs::prefix_tree_name_entry<PrefixTreeContext>,PrefixTreeAllocator>
               ::named_avl_free,0);
  }
  uVar4 = *(undefined8 *)param_1;
  local_res18[0] = '\0';
  _Dst = (prefix_tree_name_entry<PrefixTreeContext> *)
         RtlInsertElementGenericTableAvl(uVar4,param_2,0x10,local_res18);
  if ((_Dst == (prefix_tree_name_entry<PrefixTreeContext> *)0x0) || (local_res18[0] == '\0')) {
    if (_Dst == (prefix_tree_name_entry<PrefixTreeContext> *)0x0) {
      return -0x3fffff66;
    }
  }
  else {
    memset(_Dst,0,0xb0);
    *(prefix_tree_name_entry<PrefixTreeContext> **)(_Dst + 8) = _Dst + 0x10;
    *(undefined2 *)(_Dst + 2) = 0x48;
    if (0x48 < *(ushort *)param_2) {
      lVar2 = ExAllocatePool2(0x100,*(ushort *)param_2,0x30704656);
      *(longlong *)(_Dst + 8) = lVar2;
      if (lVar2 == 0) {
        ppVar3 = _Dst;
        goto LAB_1c00121d4;
      }
      *(undefined2 *)_Dst = 0;
      *(undefined2 *)(_Dst + 2) = *(undefined2 *)param_2;
    }
    RtlCopyUnicodeString(_Dst,param_2);
  }
  *(prefix_tree_table **)(_Dst + 0x90) = param_1;
  if (((*(short *)(_Dst + 0x58) == 0) && (*(short *)param_3 != 0)) &&
     (cVar1 = RtlEqualUnicodeString(_Dst,param_3,1), cVar1 == '\0')) {
    if (*(longlong *)(param_1 + 8) == 0) {
      if (PrefixTreeAllocator::LookasideInited == false) {
        lVar2 = ExAllocatePool2(0x100,0x68,0x30704656);
      }
      else {
        lVar2 = ExAllocateFromPagedLookasideList(&PrefixTreeAllocator::PrefixTableLookasideList);
      }
      *(longlong *)(param_1 + 8) = lVar2;
      if (lVar2 == 0) {
        return -0x3fffff66;
      }
      RtlInitializeGenericTableAvl
                (lVar2,named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>
                       ::named_avl_compare,
                 named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>
                 ::named_avl_allocate,
                 named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>
                 ::named_avl_free,0);
    }
    uVar4 = *(undefined8 *)(param_1 + 8);
    local_38[0] = '\0';
    ppVar3 = (prefix_tree_name_entry<PrefixTreeContext> *)
             RtlInsertElementGenericTableAvl(uVar4,param_3,0x10,local_38);
    if ((ppVar3 == (prefix_tree_name_entry<PrefixTreeContext> *)0x0) || (local_38[0] == '\0')) {
      if (ppVar3 == (prefix_tree_name_entry<PrefixTreeContext> *)0x0) {
        return -0x3fffff66;
      }
    }
    else {
      *(undefined8 *)ppVar3 = 0;
      *(undefined8 *)(ppVar3 + 8) = 0;
      *(undefined8 *)(ppVar3 + 0x10) = 0;
      *(undefined8 *)(ppVar3 + 0x18) = 0;
      *(undefined8 *)(ppVar3 + 0x20) = 0;
      *(undefined8 *)(ppVar3 + 0x28) = 0;
      *(prefix_tree_name_entry<PrefixTreeContext> **)(ppVar3 + 8) = ppVar3 + 0x10;
      *(undefined2 *)(ppVar3 + 2) = 0x18;
      if (0x18 < *(ushort *)param_3) {
        lVar2 = ExAllocatePool2(0x100,*(ushort *)param_3,0x30704656);
        *(longlong *)(ppVar3 + 8) = lVar2;
        if (lVar2 == 0) {
LAB_1c00121d4:
          RtlDeleteElementGenericTableAvl(uVar4,ppVar3);
          return -0x3fffff66;
        }
        *(undefined2 *)ppVar3 = 0;
        *(undefined2 *)(ppVar3 + 2) = *(undefined2 *)param_3;
      }
      RtlCopyUnicodeString(ppVar3,param_3);
    }
    *(prefix_tree_name_entry<PrefixTreeContext> **)(ppVar3 + 0x28) = _Dst;
    *(prefix_tree_name_entry<PrefixTreeContext> **)(_Dst + 0x60) = _Dst + 0x68;
    *(undefined2 *)(_Dst + 0x5a) = 0x18;
    RtlCopyUnicodeString(_Dst + 0x58,param_3);
  }
  *param_4 = _Dst;
  return 0;
}



===== named_avl_allocate @ 1c0012260 =====

/* private: static void * __ptr64 __cdecl appv::shared::vfs::named_avl_table<struct
   appv::shared::vfs::prefix_tree_name_entry<class PrefixTreeContext>,class
   PrefixTreeAllocator>::named_avl_allocate(struct _RTL_AVL_TABLE * __ptr64,unsigned long) */

void * __cdecl
appv::shared::vfs::
named_avl_table<appv::shared::vfs::prefix_tree_name_entry<PrefixTreeContext>,PrefixTreeAllocator>::
named_avl_allocate(_RTL_AVL_TABLE *param_1,ulong param_2)

{
  void *pvVar1;
  
  pvVar1 = PrefixTreeAllocator::allocate(0xd0,true);
  return pvVar1;
}



===== named_avl_allocate @ 1c0012280 =====

/* private: static void * __ptr64 __cdecl appv::shared::vfs::named_avl_table<struct
   appv::shared::vfs::prefix_tree_shortname_entry,class
   PrefixTreeAllocator>::named_avl_allocate(struct _RTL_AVL_TABLE * __ptr64,unsigned long) */

void * __cdecl
appv::shared::vfs::
named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>::
named_avl_allocate(_RTL_AVL_TABLE *param_1,ulong param_2)

{
  void *pvVar1;
  
  pvVar1 = PrefixTreeAllocator::allocate(0x50,true);
  return pvVar1;
}



===== named_avl_compare @ 1c00122a0 =====

/* private: static enum _RTL_GENERIC_COMPARE_RESULTS __cdecl
   appv::shared::vfs::named_avl_table<struct appv::shared::vfs::prefix_tree_shortname_entry,class
   PrefixTreeAllocator>::named_avl_compare(struct _RTL_AVL_TABLE * __ptr64,void * __ptr64,void *
   __ptr64) */

_RTL_GENERIC_COMPARE_RESULTS __cdecl
appv::shared::vfs::
named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>::
named_avl_compare(_RTL_AVL_TABLE *param_1,void *param_2,void *param_3)

{
  int iVar1;
  _RTL_GENERIC_COMPARE_RESULTS _Var2;
  
  iVar1 = RtlCompareUnicodeString(param_2,param_3,1);
  _Var2 = 0;
  if (-1 < iVar1) {
    _Var2 = (iVar1 < 1) + 1;
  }
  return _Var2;
}



===== named_avl_free @ 1c00122e0 =====

/* private: static void __cdecl appv::shared::vfs::named_avl_table<struct
   appv::shared::vfs::prefix_tree_name_entry<class PrefixTreeContext>,class
   PrefixTreeAllocator>::named_avl_free(struct _RTL_AVL_TABLE * __ptr64,void * __ptr64) */

void __cdecl
appv::shared::vfs::
named_avl_table<appv::shared::vfs::prefix_tree_name_entry<PrefixTreeContext>,PrefixTreeAllocator>::
named_avl_free(_RTL_AVL_TABLE *param_1,void *param_2)

{
  PrefixTreeAllocator::deallocate(param_2,0xd0);
  return;
}



===== named_avl_free @ 1c0012300 =====

/* private: static void __cdecl appv::shared::vfs::named_avl_table<struct
   appv::shared::vfs::prefix_tree_shortname_entry,class PrefixTreeAllocator>::named_avl_free(struct
   _RTL_AVL_TABLE * __ptr64,void * __ptr64) */

void __cdecl
appv::shared::vfs::
named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>::named_avl_free
          (_RTL_AVL_TABLE *param_1,void *param_2)

{
  PrefixTreeAllocator::deallocate(param_2,0x50);
  return;
}



===== remove_directory @ 1c0012320 =====

/* private: static void __cdecl appv::shared::vfs::prefix_tree<class PrefixTreeContext,class
   PrefixTreeAllocator>::remove_directory(struct appv::shared::vfs::prefix_tree_table & __ptr64) */

void __cdecl
appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::remove_directory
          (prefix_tree_table *param_1)

{
  undefined8 *puVar1;
  prefix_tree_table *ppVar2;
  undefined8 uVar3;
  char cVar4;
  longlong lVar5;
  prefix_tree_table *ppVar6;
  longlong lVar7;
  longlong lVar8;
  prefix_tree_table *ppVar9;
  prefix_tree_table *ppVar10;
  
  ppVar6 = (prefix_tree_table *)0x0;
  ppVar10 = param_1;
  while( true ) {
    while( true ) {
      lVar7 = *(longlong *)(ppVar10 + 8);
      if (lVar7 != 0) {
        while( true ) {
          lVar5 = RtlEnumerateGenericTableAvl(lVar7,1);
          lVar7 = *(longlong *)(ppVar10 + 8);
          if (lVar5 == 0) break;
          RtlDeleteElementGenericTableAvl(lVar7,lVar5);
          lVar7 = *(longlong *)(ppVar10 + 8);
        }
        if (PrefixTreeAllocator::LookasideInited == false) {
          ExFreePoolWithTag(lVar7,0x30704656);
        }
        else {
          ExFreeToPagedLookasideList(&PrefixTreeAllocator::PrefixTableLookasideList,lVar7);
        }
        *(longlong *)(ppVar10 + 8) = 0;
      }
      if ((*(longlong *)ppVar10 == 0) || (cVar4 = RtlIsGenericTableEmptyAvl(), cVar4 != '\0'))
      break;
      ppVar6 = (prefix_tree_table *)RtlEnumerateGenericTableAvl(*(longlong *)ppVar10,1);
      ppVar10 = ppVar6 + 0x80;
    }
    if (ppVar10 == param_1) break;
    ppVar10 = *(prefix_tree_table **)(ppVar6 + 0x90);
    if ((*(longlong *)(ppVar6 + 0x80) != 0) && (cVar4 = RtlIsGenericTableEmptyAvl(), cVar4 != '\0'))
    {
      if (PrefixTreeAllocator::LookasideInited == false) {
        ExFreePoolWithTag(*(longlong *)(ppVar6 + 0x80),0x30704656);
      }
      else {
        ExFreeToPagedLookasideList
                  (&PrefixTreeAllocator::PrefixTableLookasideList,*(longlong *)(ppVar6 + 0x80));
      }
      *(longlong *)(ppVar6 + 0x80) = 0;
    }
    if ((*(longlong *)(ppVar6 + 0x88) != 0) && (cVar4 = RtlIsGenericTableEmptyAvl(), cVar4 != '\0'))
    {
      if (PrefixTreeAllocator::LookasideInited == false) {
        ExFreePoolWithTag(*(longlong *)(ppVar6 + 0x88),0x30704656);
      }
      else {
        ExFreeToPagedLookasideList
                  (&PrefixTreeAllocator::PrefixTableLookasideList,*(longlong *)(ppVar6 + 0x88));
      }
      *(longlong *)(ppVar6 + 0x88) = 0;
    }
    if (ppVar6[0x98] != (prefix_tree_table)0x0) {
      PrefixTreeContext::~PrefixTreeContext((PrefixTreeContext *)(ppVar6 + 0xa0));
      ppVar6[0x98] = (prefix_tree_table)0x0;
    }
    puVar1 = *(undefined8 **)(ppVar6 + 0x90);
    if (((puVar1[1] != 0) && (*(short *)(ppVar6 + 0x58) != 0)) &&
       (lVar7 = RtlLookupElementGenericTableAvl(), lVar7 != 0)) {
      lVar5 = *(longlong *)(lVar7 + 8);
      lVar8 = 0;
      if ((lVar5 != 0) && (lVar5 != lVar7 + 0x10)) {
        lVar8 = lVar5;
      }
      cVar4 = RtlDeleteElementGenericTableAvl(puVar1[1],lVar7);
      if ((cVar4 != '\0') && (lVar8 != 0)) {
        ExFreePoolWithTag(lVar8,0x30704656);
      }
    }
    ppVar2 = *(prefix_tree_table **)(ppVar6 + 8);
    ppVar9 = (prefix_tree_table *)0x0;
    if ((ppVar2 != (prefix_tree_table *)0x0) && (ppVar2 != ppVar6 + 0x10)) {
      ppVar9 = ppVar2;
    }
    cVar4 = RtlDeleteElementGenericTableAvl(*puVar1,ppVar6);
    if ((cVar4 != '\0') && (ppVar9 != (prefix_tree_table *)0x0)) {
      ExFreePoolWithTag(ppVar9,0x30704656);
    }
    ppVar6 = ppVar10 + -0x80;
  }
  lVar7 = *(longlong *)param_1;
  if (lVar7 != 0) {
    while( true ) {
      lVar7 = RtlEnumerateGenericTableAvl(lVar7,1);
      uVar3 = *(undefined8 *)param_1;
      if (lVar7 == 0) break;
      RtlDeleteElementGenericTableAvl(uVar3,lVar7);
      lVar7 = *(longlong *)param_1;
    }
    if (PrefixTreeAllocator::LookasideInited == false) {
      ExFreePoolWithTag(uVar3,0x30704656);
    }
    else {
      ExFreeToPagedLookasideList(&PrefixTreeAllocator::PrefixTableLookasideList,uVar3);
    }
    *(undefined8 *)param_1 = 0;
  }
  return;
}



===== VfsPrefixTreeCreate @ 1c0012618 =====

uint VfsPrefixTreeCreate(undefined8 *param_1)

{
  prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *this;
  longlong lVar1;
  prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *ppVar2;
  bool bVar3;
  
  ppVar2 = (prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *)0x0;
  if (PrefixTreeAllocator::LookasideInited) {
    this = (prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *)
           ExAllocateFromPagedLookasideList(&PrefixTreeAllocator::PrefixTreeLookasideList);
  }
  else {
    this = (prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *)
           ExAllocatePool2(0x100,0x10,0x30704656);
  }
  if (this != (prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *)0x0) {
    bVar3 = PrefixTreeAllocator::LookasideInited == false;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)this = 0;
    if (bVar3) {
      lVar1 = ExAllocatePool2(0x100,0x68,0x30704656);
    }
    else {
      lVar1 = ExAllocateFromPagedLookasideList(&PrefixTreeAllocator::PrefixTableLookasideList);
    }
    *(longlong *)this = lVar1;
    if (lVar1 == 0) {
      appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::
      ~prefix_tree<PrefixTreeContext,PrefixTreeAllocator>(this);
      if (PrefixTreeAllocator::LookasideInited == false) {
        ExFreePoolWithTag(this,0x30704656);
      }
      else {
        ExFreeToPagedLookasideList(&PrefixTreeAllocator::PrefixTreeLookasideList,this);
      }
    }
    else {
      RtlInitializeGenericTableAvl
                (lVar1,appv::shared::vfs::
                       named_avl_table<appv::shared::vfs::prefix_tree_shortname_entry,PrefixTreeAllocator>
                       ::named_avl_compare,
                 appv::shared::vfs::
                 named_avl_table<appv::shared::vfs::prefix_tree_name_entry<PrefixTreeContext>,PrefixTreeAllocator>
                 ::named_avl_allocate,
                 appv::shared::vfs::
                 named_avl_table<appv::shared::vfs::prefix_tree_name_entry<PrefixTreeContext>,PrefixTreeAllocator>
                 ::named_avl_free,0);
      ppVar2 = this;
    }
  }
  *param_1 = ppVar2;
  return ~-(uint)(ppVar2 != (prefix_tree<PrefixTreeContext,PrefixTreeAllocator> *)0x0) & 0xc000009a;
}



===== VfsPrefixTreeInsert @ 1c001274c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long VfsPrefixTreeInsert(prefix_tree_name_entry<PrefixTreeContext> *param_1,short *param_2,
                        undefined4 *param_3,void *param_4)

{
  void *pvVar1;
  _func_void_void_ptr *p_Var2;
  long lVar3;
  prefix_tree_name_entry<PrefixTreeContext> *ppVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  prefix_tree_name_entry<PrefixTreeContext> *local_res8;
  void *local_res10;
  undefined4 local_78;
  undefined4 uStack_74;
  short sStack_70;
  short sStack_6e;
  short sStack_6c;
  short sStack_6a;
  short local_68 [8];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_res10 = param_4;
  if ((PrefixTreeContext::referenceCallback != (_func_void_void_ptr *)0x0) &&
     (param_4 != (void *)0x0)) {
    (*PrefixTreeContext::referenceCallback)(param_4);
  }
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  if (param_3 != (undefined4 *)0x0) {
    uVar6 = *param_3;
    uVar7 = param_3[1];
    uVar8 = param_3[2];
    uVar9 = param_3[3];
  }
  puVar5 = (undefined8 *)(-(ulonglong)(param_4 != (void *)0x0) & (ulonglong)&local_res10);
  if (*param_2 != 0) {
    ppVar4 = (prefix_tree_name_entry<PrefixTreeContext> *)0x0;
    local_78 = *(undefined4 *)param_2;
    uStack_74 = *(undefined4 *)(param_2 + 2);
    sStack_70 = param_2[4];
    sStack_6e = param_2[5];
    sStack_6c = param_2[6];
    sStack_6a = param_2[7];
    local_58 = uVar6;
    uStack_54 = uVar7;
    uStack_50 = uVar8;
    uStack_4c = uVar9;
    do {
      local_68[0] = 0;
      local_68[1] = 0;
      local_68[2] = 0;
      local_68[3] = 0;
      local_68[4] = 0;
      local_68[5] = 0;
      local_68[6] = 0;
      local_68[7] = 0;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = local_58;
      uStack_34 = uStack_54;
      uStack_30 = uStack_50;
      uStack_2c = uStack_4c;
      FsRtlDissectName(&local_38,&local_48,&local_58);
      if (((short)local_58 != 0) && (*(short *)CONCAT44(uStack_4c,uStack_50) == 0x5c)) {
LAB_1c001288d:
        lVar3 = -0x3fffffcd;
        goto LAB_1c00128e8;
      }
      uStack_30 = CONCAT22(sStack_6e,sStack_70);
      uStack_2c = CONCAT22(sStack_6a,sStack_6c);
      local_38 = local_78;
      uStack_34 = uStack_74;
      FsRtlDissectName(&local_38,local_68,&local_78);
      if (((short)local_78 != 0) &&
         (*(short *)CONCAT26(sStack_6a,CONCAT24(sStack_6c,CONCAT22(sStack_6e,sStack_70))) == 0x5c))
      goto LAB_1c001288d;
      if (local_68[0] == 0) break;
      local_res8 = appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::find_avl
                             ((prefix_tree_table *)param_1,(_UNICODE_STRING *)local_68);
      if ((local_res8 == (prefix_tree_name_entry<PrefixTreeContext> *)0x0) &&
         (lVar3 = appv::shared::vfs::prefix_tree<PrefixTreeContext,PrefixTreeAllocator>::insert_avl
                            ((prefix_tree_table *)param_1,(_UNICODE_STRING *)local_68,
                             (_UNICODE_STRING *)&local_48,&local_res8), lVar3 < 0))
      goto LAB_1c00128e8;
      param_1 = local_res8 + 0x80;
      ppVar4 = local_res8;
    } while ((short)local_78 != 0);
    if (ppVar4 != (prefix_tree_name_entry<PrefixTreeContext> *)0x0) {
      if (puVar5 != (undefined8 *)0x0) {
        if (ppVar4[0x98] != (prefix_tree_name_entry<PrefixTreeContext>)0x0) {
          PrefixTreeContext::~PrefixTreeContext((PrefixTreeContext *)(ppVar4 + 0xa0));
          ppVar4[0x98] = (prefix_tree_name_entry<PrefixTreeContext>)0x0;
        }
        p_Var2 = PrefixTreeContext::referenceCallback;
        pvVar1 = (void *)*puVar5;
        *(void **)(ppVar4 + 0xa0) = pvVar1;
        if ((p_Var2 != (_func_void_void_ptr *)0x0) && (pvVar1 != (void *)0x0)) {
          (*p_Var2)(pvVar1);
        }
        ppVar4[0x98] = (prefix_tree_name_entry<PrefixTreeContext>)0x1;
      }
      lVar3 = 0;
      goto LAB_1c00128e8;
    }
  }
  lVar3 = -0x3ffffff3;
LAB_1c00128e8:
  PrefixTreeContext::~PrefixTreeContext((PrefixTreeContext *)&local_res10);
  return lVar3;
}



===== AllocateGenericBuffer @ 1c0012910 =====

uint AllocateGenericBuffer(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  if (param_3 == (longlong *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    lVar2 = ExAllocatePool2(param_1,param_2,0x676c6462);
    *param_3 = lVar2;
    uVar1 = ~-(uint)(lVar2 != 0) & 0xc000009a;
  }
  return uVar1;
}



===== AllocateLogBufferEntry @ 1c0012954 =====

undefined8 * AllocateLogBufferEntry(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_1c001fd10);
  puVar3 = DAT_1c001fd00;
  puVar5 = (undefined8 *)0x0;
  puVar6 = auStack_28;
  if ((undefined8 **)DAT_1c001fd00 != &DAT_1c001fd00) {
    puVar1 = (undefined8 *)*DAT_1c001fd00;
    puVar5 = puVar3;
    if (((undefined8 **)DAT_1c001fd00[1] == &DAT_1c001fd00) &&
       ((undefined8 *)puVar1[1] == DAT_1c001fd00)) {
      DAT_1c001fd00 = puVar1;
      puVar1[1] = &DAT_1c001fd00;
      puVar6 = auStack_28;
    }
    else {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3,uVar4);
      puVar6 = auStack_20;
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x1c00129c7;
  KeReleaseSpinLock(&DAT_1c001fd10);
  if (puVar5 == (undefined8 *)0x0) {
    *(undefined8 *)(puVar6 + -8) = 0x1c00129e6;
    puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x828,0x676c6462);
    if (puVar5 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
    *(undefined1 *)(puVar5 + 2) = 1;
  }
  puVar5[4] = puVar5 + 5;
  *(undefined4 *)(puVar5 + 3) = 0x8000000;
  return puVar5;
}



===== ConvertGuidToString @ 1c0012a20 =====

undefined8 * ConvertGuidToString(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  
  *param_2 = 0;
  param_2[1] = 0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    iVar2 = RtlStringFromGUID(param_1,param_2);
    if (iVar2 < 0) {
      *(undefined2 *)param_2 = 0;
    }
  }
  return param_2;
}



===== ConvertSidToString @ 1c0012a80 =====

undefined8 * ConvertSidToString(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  
  *param_2 = 0;
  param_2[1] = 0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    RtlConvertSidToUnicodeString(param_2,param_1,1);
  }
  return param_2;
}



===== FreeLogBufferEntry @ 1c0012ad0 =====

void FreeLogBufferEntry(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (param_1 != (undefined8 *)0x0) {
    if (*(char *)(param_1 + 2) == '\x01') {
      ExFreePoolWithTag(param_1,0x676c6462);
    }
    else {
      uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_1c001fd10);
      puVar5 = auStack_28;
      puVar4 = &DAT_1c001fd00;
      puVar3 = DAT_1c001fd08;
      if ((undefined8 *)*DAT_1c001fd08 != &DAT_1c001fd00) {
        puVar3 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        uVar2 = (*pcVar1)();
        puVar5 = auStack_20;
      }
      *param_1 = puVar4;
      param_1[1] = puVar3;
      *puVar3 = param_1;
      *(undefined8 *)(puVar5 + -8) = 0x1c0012b4d;
      DAT_1c001fd08 = param_1;
      KeReleaseSpinLock(&DAT_1c001fd10,uVar2);
    }
  }
  return;
}



===== FreeSidString @ 1c0012b5c =====

void FreeSidString(longlong param_1)

{
  code *pcVar1;
  char cVar2;
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    if ((param_1 != 0) && (*(longlong *)(param_1 + 8) != 0)) {
      RtlFreeUnicodeString(param_1);
    }
  }
  else {
    DbgPrint(
            "FreeSidString() called at IRQL > PASSIVE_LEVEL. The caller should refactorthe log message so this method is only called at IRQL == PASSIVE_LEVEL."
            );
    pcVar1 = (code *)swi(0x2c);
    (*pcVar1)();
  }
  return;
}



===== LogUninitialize @ 1c0012bb4 =====

void LogUninitialize(void)

{
  longlong ****pppplVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong ****pppplVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_1c001fd10);
  if ((longlong *****)DAT_1c001fd00 != &DAT_1c001fd00) {
    local_18 = DAT_1c001fd00;
    DAT_1c001fd00[1] = (longlong ***)&local_18;
    local_10 = DAT_1c001fd08;
    *DAT_1c001fd08 = (longlong ***)&local_18;
    DAT_1c001fd08 = (longlong ****)&DAT_1c001fd00;
    DAT_1c001fd00 = (longlong ****)&DAT_1c001fd00;
  }
  KeReleaseSpinLock(&DAT_1c001fd10,uVar5);
  puVar6 = auStack_38;
  do {
    pppplVar4 = local_18;
    if ((longlong *****)local_18 == &local_18) {
LAB_1c0012c85:
      *(undefined8 *)(puVar6 + -8) = 0x1c0012c91;
      McGenEventUnregister_EtwUnregister((longlong *)&AppVClientDbg_Context);
      uVar3 = DAT_1c001f100;
      DAT_1c001f0e0 = 0;
      DAT_1c001f100 = 0;
      *(undefined8 *)(puVar6 + -8) = 0x1c0012cae;
      EtwUnregister(uVar3);
      return;
    }
    pppplVar1 = (longlong ****)*local_18;
    if (((longlong *****)local_18[1] != &local_18) || ((longlong ****)pppplVar1[1] != local_18)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar6 = auStack_30;
      goto LAB_1c0012c85;
    }
    pppplVar1[1] = (longlong ***)&local_18;
    local_18 = pppplVar1;
    ExFreePoolWithTag(pppplVar4,0x676c6462);
  } while( true );
}



===== LogWrite @ 1c0012cc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LogWrite(uint param_1,undefined8 param_2,wchar_t *param_3,undefined8 param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong _Count;
  undefined8 local_res20;
  undefined1 auStack_168 [32];
  undefined4 local_148;
  undefined **local_140;
  int local_138 [4];
  undefined8 local_128;
  wchar_t *local_120;
  ulonglong local_118;
  undefined8 *local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined8 local_100;
  undefined8 local_f8;
  undefined1 *puStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined *local_d8;
  uint local_d0;
  undefined4 local_cc;
  undefined *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  int *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  int local_a0;
  undefined4 local_9c;
  wchar_t *local_98;
  undefined8 local_90;
  int *local_88;
  undefined8 local_80;
  undefined1 local_78 [48];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_168;
  local_128 = 0;
  if (((_DAT_1c001f1d0 & param_1) != 0) && (DAT_1c001f024 != 0)) {
    if (((byte)(DAT_1c001f028 - 1U) < 4) ||
       (((_DAT_1c001f010 & 0x8000000000000001) == 0 ||
        (bVar5 = true, (DAT_1c001f018 & 0x8000000000000001) != DAT_1c001f018)))) {
      bVar5 = false;
    }
    if (bVar5) {
      uStack_e0 = 0x8000000000000001;
      if (param_1 == 1) {
        local_e8 = 0x210000001;
      }
      else if (param_1 == 2) {
        local_e8 = 0x310000001;
      }
      else if (param_1 == 3) {
        local_e8 = 0x410000001;
      }
      else if (param_1 == 4) {
        local_e8 = 0x510000001;
      }
      else {
        local_e8 = 0x10000001;
      }
      local_res20 = param_4;
      puVar9 = AllocateLogBufferEntry();
      if (puVar9 != (undefined8 *)0x0) {
        puVar1 = (ushort *)(puVar9 + 3);
        local_110 = puVar9;
        PsGetCurrentThreadId();
        PsGetCurrentProcessId();
        local_f8 = 0x2a0000;
        puStack_f0 = local_78;
        iVar7 = RtlAppendUnicodeStringToString(puVar1,&DAT_1c001fd18);
        if ((-1 < iVar7) && (iVar7 = RtlAppendUnicodeToString(puVar1,L": ["), -1 < iVar7)) {
          puVar9[4] = puVar9[4] + (ulonglong)(*puVar1 >> 1) * 2;
          *(ushort *)((longlong)puVar9 + 0x1a) = *(short *)((longlong)puVar9 + 0x1a) - *puVar1;
          *puVar1 = 0;
          puVar2 = (ushort *)(puVar9 + 3);
          cVar6 = KeGetCurrentIrql();
          if (cVar6 == '\0') {
            local_120 = (wchar_t *)0x0;
            local_118 = 0;
            iVar7 = 0;
            local_138[1] = 0;
            uVar3 = *puVar2;
            if (((((uVar3 & 1) == 0) &&
                 (uVar4 = *(ushort *)((longlong)puVar9 + 0x1a), (uVar4 & 1) == 0)) &&
                (uVar3 <= uVar4)) && (uVar4 != 0xffff)) {
              if ((puVar9[4] == 0) && ((uVar3 != 0 || (uVar4 != 0)))) {
                iVar7 = -0x3ffffff3;
                local_138[1] = 0xc000000d;
              }
            }
            else {
              iVar7 = -0x3ffffff3;
              local_138[1] = 0xc000000d;
            }
            if (-1 < iVar7) {
              local_120 = (wchar_t *)puVar9[4];
              _Count = (ulonglong)(*(ushort *)((longlong)puVar9 + 0x1a) >> 1);
              local_118 = _Count;
              if (-1 < iVar7) {
                iVar7 = 0;
                iVar8 = _vsnwprintf(local_120,_Count,param_3,(va_list)&local_res20);
                if ((iVar8 < 0) || (uVar10 = (longlong)iVar8, _Count < (ulonglong)(longlong)iVar8))
                {
                  iVar7 = -0x7ffffffb;
                  uVar10 = _Count;
                }
                *puVar2 = (short)uVar10 * 2;
              }
            }
            local_128 = 0;
            local_138[0] = iVar7;
          }
          else {
            local_138[0] = RtlAppendUnicodeToString(puVar2,param_3);
          }
          if ((-1 < local_138[0]) &&
             ((ulonglong)*puVar1 + 2 <= (ulonglong)*(ushort *)((longlong)puVar9 + 0x1a))) {
            *(undefined2 *)(puVar9[4] + (ulonglong)(*puVar1 >> 1) * 2) = 0;
            if (param_1 - 4 < 2) {
              McTemplateK0z_EtwWriteTransfer
                        ((undefined8 *)&AppVClientDbg_Context,&local_e8,param_2,
                         (wchar_t *)(puVar9 + 5));
            }
            else if (5 < DAT_1c001f0e0) {
              if (((_DAT_1c001f0f0 & 0x200000000000) == 0) ||
                 (bVar5 = true, (DAT_1c001f0f8 & 0x200000000000) != DAT_1c001f0f8)) {
                bVar5 = false;
              }
              if (bVar5) {
                local_b8 = local_138 + 2;
                local_b0 = 4;
                local_a8 = (wchar_t *)(puVar9 + 5);
                if (local_a8 == (wchar_t *)0x0) {
                  local_a8 = L"";
                  local_a0 = 2;
                }
                else {
                  lVar11 = -1;
                  do {
                    lVar11 = lVar11 + 1;
                  } while (local_a8[lVar11] != L'\0');
                  local_a0 = (int)lVar11 * 2 + 2;
                }
                local_9c = 0;
                local_98 = L"";
                local_90 = 2;
                local_138[0] = 0;
                local_88 = local_138;
                local_80 = 4;
                local_108 = 0xb000000;
                local_104 = 5;
                local_100 = 0x200000000000;
                local_d8 = PTR_DAT_1c001f0e8;
                local_d0 = (uint)*(ushort *)PTR_DAT_1c001f0e8;
                local_cc = 2;
                local_c8 = &DAT_1c001cb9c;
                local_c0 = 0x36;
                local_bc = 1;
                local_128 = CONCAT44(local_128._4_4_,0x96);
                local_140 = &local_d8;
                local_148 = 6;
                local_138[2] = param_1;
                EtwWriteTransfer(DAT_1c001f100,&local_108,0,0);
                puVar9 = local_110;
              }
            }
          }
        }
        FreeLogBufferEntry(puVar9);
      }
    }
  }
  return;
}



===== McTemplateK0z_EtwWriteTransfer @ 1c00131b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0z_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_4 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_hAppVProviderProv @ 1c001323c =====

void _tlgDefineProvider_annotation__Tlgg_hAppVProviderProv(void)

{
  return;
}



===== FileNamePrefixMapping @ 1c0013248 =====

undefined8 FileNamePrefixMapping(ushort *param_1,longlong *param_2)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  ushort uVar4;
  undefined6 extraout_var;
  short *psVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ushort *puVar11;
  longlong in_stack_00000030;
  undefined8 local_40;
  short *psStack_38;
  
  uVar1 = *(ushort *)(*param_2 + 0x10);
  uVar4 = GetNumberComponents(param_1);
  psVar5 = (short *)CONCAT62(extraout_var,uVar4);
  if (uVar4 != 0) {
    if (uVar1 < uVar4) {
LAB_1c0013453:
      return (ulonglong)psVar5 & 0xffffffffffffff00;
    }
    uVar8 = 0;
    uVar7 = 0;
    local_40 = 0;
    if (uVar4 != 0) {
      do {
        uVar10 = (ulonglong)uVar7;
        sVar6 = 0;
        if ((uVar7 == 0) && (psVar5 = *(short **)(param_1 + 4), *psVar5 == 0x5c)) {
          uVar10 = 1;
        }
        uVar7 = (ushort)uVar10;
        if (*param_1 >> 1 <= uVar7) goto LAB_1c0013453;
        do {
          psVar5 = (short *)(ulonglong)uVar7;
          if (*(short *)(*(longlong *)(param_1 + 4) + (longlong)psVar5 * 2) == 0x5c) break;
          sVar6 = sVar6 + 1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *param_1 >> 1);
        if (sVar6 == 0) goto LAB_1c0013453;
        lVar3 = param_2[1];
        uVar7 = uVar7 + 1;
        local_40 = CONCAT62(CONCAT42(local_40._4_4_,sVar6 * 2),sVar6 * 2);
        psStack_38 = (short *)(*(longlong *)(param_1 + 4) + uVar10 * 2);
        lVar9 = (ulonglong)uVar8 * 0x10;
        puVar11 = (ushort *)(*param_2 + 0x18 + lVar9);
        psVar5 = (short *)RtlEqualUnicodeString(puVar11,&local_40,CONCAT71((int7)(uVar10 >> 8),1));
        if ((char)psVar5 == '\0') {
          if (lVar3 != 0) {
            psVar5 = (short *)RtlEqualUnicodeString(lVar3 + 0x18 + lVar9,&local_40,1);
            if ((char)psVar5 != '\0') goto LAB_1c0013403;
          }
          uVar2 = *puVar11;
          psVar5 = (short *)RtlPrefixUnicodeString(puVar11,&local_40,1);
          if (((char)psVar5 == '\0') || (psVar5 = psStack_38, psStack_38[uVar2 >> 1] != 0x3a)) {
            if (lVar3 == 0) goto LAB_1c0013453;
            puVar11 = (ushort *)(lVar3 + 0x18 + lVar9);
            uVar2 = *puVar11;
            psVar5 = (short *)RtlPrefixUnicodeString(puVar11,&local_40,1);
            if (((char)psVar5 == '\0') || (psVar5 = psStack_38, psStack_38[uVar2 >> 1] != 0x3a))
            goto LAB_1c0013453;
          }
        }
LAB_1c0013403:
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar4);
    }
    if (in_stack_00000030 != 0) {
      psVar5 = (short *)CONCAT71((int7)((ulonglong)psVar5 >> 8),uVar1 == uVar4);
      *(bool *)in_stack_00000030 = uVar1 == uVar4;
    }
  }
  return CONCAT71((int7)((ulonglong)psVar5 >> 8),1);
}



===== GetNumberComponents @ 1c0013460 =====

short GetNumberComponents(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  ushort uVar4;
  short *psVar5;
  bool bVar6;
  
  sVar3 = 0;
  uVar4 = *param_1 >> 1;
  if (uVar4 != 0) {
    bVar6 = **(short **)(param_1 + 4) == 0x5c;
    uVar2 = (uint)bVar6;
    uVar1 = (ushort)bVar6;
    if (uVar1 < uVar4) {
      psVar5 = *(short **)(param_1 + 4) + uVar1;
      do {
        if ((*psVar5 == 0x5c) || (uVar2 == uVar4 - 1)) {
          sVar3 = sVar3 + 1;
        }
        uVar1 = (short)uVar2 + 1;
        uVar2 = (uint)uVar1;
        psVar5 = psVar5 + 1;
      } while (uVar1 < uVar4);
    }
  }
  return sVar3;
}



===== GetRemainingPath @ 1c00134c4 =====

uint GetRemainingPath(ushort *param_1,ushort param_2,short *param_3)

{
  short sVar1;
  undefined8 uVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar6 = *param_1 >> 1;
  uVar5 = 0;
  if (uVar6 == 0) {
LAB_1c00135a5:
    uVar3 = 0xc000000d;
  }
  else if (param_2 == 0) {
    uVar2 = *(undefined8 *)(param_1 + 4);
    *(undefined8 *)param_3 = *(undefined8 *)param_1;
    *(undefined8 *)(param_3 + 4) = uVar2;
LAB_1c00135a1:
    uVar3 = 0;
  }
  else {
    for (uVar4 = (ushort)(**(short **)(param_1 + 4) == 0x5c); uVar4 < uVar6; uVar4 = uVar4 + 1) {
      sVar1 = (*(short **)(param_1 + 4))[uVar4];
      if (((sVar1 == 0x5c) || (sVar1 == 0x3a)) || ((uint)uVar4 == uVar6 - 1)) {
        uVar5 = uVar5 + 1;
      }
      if ((sVar1 == 0x3a) && (uVar5 < param_2)) goto LAB_1c00135a5;
      if (uVar5 == param_2) {
        if ((sVar1 == 0x5c) || (sVar1 == 0x3a)) {
          sVar1 = (uVar6 - uVar4) * 2;
          *param_3 = sVar1;
          param_3[1] = sVar1;
          *(ulonglong *)(param_3 + 4) = *(longlong *)(param_1 + 4) + (ulonglong)uVar4 * 2;
        }
        else {
          param_3[0] = 0;
          param_3[1] = 0;
          param_3[4] = 0;
          param_3[5] = 0;
          param_3[6] = 0;
          param_3[7] = 0;
        }
        goto LAB_1c00135a1;
      }
    }
    uVar3 = -(uint)(uVar5 < param_2) & 0xc000000d;
  }
  return uVar3;
}



===== MappingPrefixFileName @ 1c00135cc =====

ulonglong MappingPrefixFileName
                    (longlong *param_1,ushort *param_2,char param_3,char param_4,undefined8 param_5,
                    longlong param_6)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  undefined6 extraout_var;
  longlong *plVar5;
  longlong lVar6;
  short *psVar7;
  ulonglong uVar8;
  short sVar9;
  ushort *puVar10;
  ushort uVar11;
  longlong lVar12;
  ushort uVar13;
  undefined8 local_48;
  short *psStack_40;
  
  if (param_3 == '\0') {
    lVar4 = *param_1;
  }
  else {
    lVar4 = param_1[2];
  }
  uVar1 = *(ushort *)(lVar4 + 0x10);
  uVar3 = GetNumberComponents(param_2);
  psVar7 = (short *)CONCAT62(extraout_var,uVar3);
  if (uVar3 < uVar1) {
LAB_1c001380d:
    uVar8 = (ulonglong)psVar7 & 0xffffffffffffff00;
  }
  else {
    uVar13 = 0;
    uVar11 = 0;
    local_48 = 0;
    if (uVar1 != 0) {
      do {
        uVar8 = (ulonglong)uVar11;
        sVar9 = 0;
        if ((uVar11 == 0) && (psVar7 = *(short **)(param_2 + 4), *psVar7 == 0x5c)) {
          uVar8 = 1;
        }
        uVar11 = (ushort)uVar8;
        if (*param_2 >> 1 <= uVar11) goto LAB_1c001380d;
        do {
          psVar7 = (short *)(ulonglong)uVar11;
          if (*(short *)(*(longlong *)(param_2 + 4) + (longlong)psVar7 * 2) == 0x5c) break;
          sVar9 = sVar9 + 1;
          uVar11 = uVar11 + 1;
        } while (uVar11 < *param_2 >> 1);
        if (sVar9 == 0) goto LAB_1c001380d;
        uVar11 = uVar11 + 1;
        local_48 = CONCAT62(CONCAT42(local_48._4_4_,sVar9 * 2),sVar9 * 2);
        plVar5 = param_1 + 2;
        if (param_3 == '\0') {
          plVar5 = param_1;
        }
        psStack_40 = (short *)(*(longlong *)(param_2 + 4) + uVar8 * 2);
        lVar4 = *plVar5;
        if (param_3 == '\0') {
          lVar12 = param_1[1];
        }
        else {
          lVar12 = param_1[3];
        }
        lVar6 = (ulonglong)uVar13 * 0x10;
        psVar7 = (short *)RtlEqualUnicodeString
                                    (lVar4 + lVar6 + 0x18,&local_48,CONCAT71((int7)(uVar8 >> 8),1));
        if ((char)psVar7 == '\0') {
          if (lVar12 != 0) {
            psVar7 = (short *)RtlEqualUnicodeString(lVar6 + 0x18 + lVar12,&local_48,1);
            if ((char)psVar7 != '\0') goto LAB_1c001382b;
          }
          uVar8 = (ulonglong)(*(ushort *)(lVar4 + lVar6 + 0x18) >> 1);
          if ((((param_3 != '\0') && (param_4 != '\0')) &&
              ((uint)uVar13 == *(ushort *)(lVar4 + 0x10) - 1)) &&
             (((local_48 & 0xffff) == uVar8 * 2 + 2 && (psStack_40[uVar8] == 0x53)))) {
            psVar7 = (short *)RtlPrefixUnicodeString(lVar6 + lVar4 + 0x18,&local_48,1);
            if ((char)psVar7 != '\0') goto LAB_1c001382b;
          }
          psVar7 = (short *)RtlPrefixUnicodeString(lVar6 + lVar4 + 0x18,&local_48,1);
          if (((char)psVar7 == '\0') || (psVar7 = psStack_40, psStack_40[uVar8] != 0x3a)) {
            if (lVar12 == 0) goto LAB_1c001380d;
            puVar10 = (ushort *)(lVar6 + 0x18 + lVar12);
            uVar2 = *puVar10;
            psVar7 = (short *)RtlPrefixUnicodeString(puVar10,&local_48,1);
            if (((char)psVar7 == '\0') || (psVar7 = psStack_40, psStack_40[uVar2 >> 1] != 0x3a))
            goto LAB_1c001380d;
          }
        }
LAB_1c001382b:
        uVar13 = uVar13 + 1;
      } while (uVar13 < uVar1);
      psVar7 = (short *)(ulonglong)uVar3;
    }
    if (param_6 != 0) {
      *(bool *)param_6 = uVar1 == (ushort)psVar7;
    }
    uVar8 = CONCAT71((int7)((ulonglong)psVar7 >> 8),1);
  }
  return uVar8;
}



===== CreateMappingName @ 1c0013864 =====

undefined8 CreateMappingName(ushort *param_1,undefined8 param_2,undefined8 *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  undefined8 uVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  ulonglong uVar8;
  ushort *puVar9;
  
  uVar1 = GetNumberComponents(param_1);
  iVar7 = param_1[1] + 0x18 + (uint)uVar1 * 0x10;
  puVar2 = (ushort *)ExAllocatePool2(0x100,iVar7,0x6e464656);
  if (puVar2 == (ushort *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = param_1[1];
    if (uVar1 != 0) {
      *(ulonglong *)(puVar2 + 4) = (ulonglong)(iVar7 - (uint)param_1[1]) + (longlong)puVar2;
      RtlCopyUnicodeString(puVar2,param_1);
    }
    puVar2[8] = uVar1;
    uVar8 = 0;
    uVar6 = 0;
    if (uVar1 != 0) {
      do {
        sVar4 = 0;
        puVar9 = puVar2 + uVar8 * 8 + 0xc;
        if ((uVar6 == 0) && (**(short **)(puVar2 + 4) == 0x5c)) {
          uVar6 = 1;
        }
        if (*puVar2 >> 1 <= uVar6) {
LAB_1c00139c1:
          ExFreePoolWithTag(puVar2,0x6e464656);
          return 0xc000000d;
        }
        uVar5 = uVar6;
        do {
          if (*(short *)(*(longlong *)(puVar2 + 4) + (ulonglong)uVar5 * 2) == 0x5c) break;
          sVar4 = sVar4 + 1;
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar2 >> 1);
        if (sVar4 == 0) goto LAB_1c00139c1;
        if (puVar9 != (ushort *)0x0) {
          puVar9[1] = sVar4 * 2;
          *puVar9 = sVar4 * 2;
          *(ulonglong *)(puVar9 + 4) = *(longlong *)(puVar2 + 4) + (ulonglong)uVar6 * 2;
        }
        uVar6 = uVar5 + 1;
        uVar5 = (short)uVar8 + 1;
        uVar8 = (ulonglong)uVar5;
      } while (uVar5 < uVar1);
    }
    *param_3 = puVar2;
    uVar3 = 0;
  }
  return uVar3;
}



===== CreateMappingNames @ 1c00139e4 =====

ulonglong CreateMappingNames(ushort *param_1,ushort *param_2,ushort *param_3,ushort *param_4,
                            undefined8 param_5,longlong *param_6)

{
  ulonglong uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  
  *param_6 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  param_6[3] = 0;
  puVar2 = param_2;
  uVar1 = CreateMappingName(param_1,param_2,param_6);
  uVar3 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) goto LAB_1c0013aa0;
  if ((param_2 == (ushort *)0x0) || (*param_2 == 0)) {
LAB_1c0013a58:
    uVar1 = CreateMappingName(param_3,puVar2,param_6 + 2);
    uVar3 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) goto LAB_1c0013aa0;
    if ((param_4 == (ushort *)0x0) || (*param_4 == 0)) {
      return 0;
    }
    uVar1 = CreateMappingName(param_4,puVar2,param_6 + 3);
    uVar3 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) goto LAB_1c0013aa0;
    if (*(short *)(param_6[2] + 0x10) == *(short *)(param_6[3] + 0x10)) {
      return 0;
    }
  }
  else {
    uVar1 = CreateMappingName(param_2,puVar2,param_6 + 1);
    uVar3 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) goto LAB_1c0013aa0;
    puVar2 = (ushort *)*param_6;
    if (puVar2[8] == *(ushort *)(param_6[1] + 0x10)) goto LAB_1c0013a58;
  }
  uVar3 = 0xc000000d;
LAB_1c0013aa0:
  DeleteMappingNames(param_6);
  return uVar3;
}



===== DeleteMappingNames @ 1c0013ad8 =====

void DeleteMappingNames(longlong *param_1)

{
  if (*param_1 != 0) {
    ExFreePoolWithTag(*param_1,0x6e464656);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    ExFreePoolWithTag(param_1[1],0x6e464656);
    param_1[1] = 0;
  }
  if (param_1[2] != 0) {
    ExFreePoolWithTag(param_1[2],0x6e464656);
    param_1[2] = 0;
  }
  if (param_1[3] != 0) {
    ExFreePoolWithTag(param_1[3],0x6e464656);
    param_1[3] = 0;
  }
  return;
}



===== WdmlibRtlInitUnicodeStringEx @ 1c0013b68 =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== __GSHandlerCheck @ 1c0013bb8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0013bdc =====

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



===== __GSHandlerCheck_SEH @ 1c0013c44 =====

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



===== __cpu_features_init @ 1c0013ce0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0013d4a) */
/* WARNING: Removing unreachable block (ram,0x0001c0013cf9) */
/* WARNING: Removing unreachable block (ram,0x0001c0013cea) */

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



===== __security_check_cookie @ 1c0013db0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0013df0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0013e20 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0013e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0013e50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c0013ea0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c0013ee3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0013f54;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0013f50:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0013f54;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c0013f4c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0013f50;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0013f4c;
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
LAB_1c0013f54:
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
LAB_1c0013ee3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0013fc0 =====

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



===== memset @ 1c00142c0 =====

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



===== __memset_repmovs @ 1c0014400 =====

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



===== __memset_query @ 1c0014480 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0014500 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0014640 =====

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



===== __memset_spec_plain @ 1c00146c0 =====

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



===== VfsCreateCleanupCompletionContext$fin$0 @ 1c00147bd =====

void VfsCreateCleanupCompletionContext_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x80) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    if (*(longlong **)(param_2 + 0x38) != (longlong *)0x0) {
      VfsDeleteCleanupCompletionContext(*(longlong **)(param_2 + 0x38));
    }
  }
  else {
    **(undefined8 **)(param_2 + 0x78) = *(undefined8 *)(param_2 + 0x38);
  }
  return;
}



===== VfsCreateInstanceContext$fin$0 @ 1c001480d =====

void VfsCreateInstanceContext_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x30) < 0) {
    if (*(longlong *)(param_2 + 0x50) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0);
      *(undefined8 *)(param_2 + 0x50) = 0;
    }
    if (*(longlong *)(param_2 + 0x88) != 0) {
      FltReleaseContext();
    }
  }
  return;
}



===== VfsCopyFile$fin$0 @ 1c001485e =====

void VfsCopyFile_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x84) < 0) && (*(longlong *)(param_2 + 0x90) != 0)) {
    *(undefined1 *)(param_2 + 0x80) = 1;
    FltSetInformationFile
              (*(undefined8 *)(param_2 + 0x100),*(longlong *)(param_2 + 0x90),param_2 + 0x80,1,0xd);
  }
  if (*(longlong *)(param_2 + 0xa0) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x90) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0xb8) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0xc0) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0xa8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0xa8),0x6e474656);
  }
  if (*(longlong *)(param_2 + 200) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 200),0x70434656);
  }
  return;
}



===== VfsCowCopyFile$fin$0 @ 1c0014962 =====

void VfsCowCopyFile_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0xd0) != 0) {
    VfsScbClose(*(longlong *)(param_2 + 0xd0));
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    FltClose();
  }
  if (*(int **)(param_2 + 0x80) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x80));
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    FltReleaseContext();
  }
  if (*(longlong *)(param_2 + 0x70) != 0) {
    FltReleaseContext();
  }
  return;
}



===== VfsCowCopyFileForScb$fin$0 @ 1c00149de =====

void VfsCowCopyFileForScb_fin_0(void)

{
  return;
}



===== VfsCowQueryFileForUserAndPackage$fin$0 @ 1c00149fa =====

void VfsCowQueryFileForUserAndPackage_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int **)(param_2 + 0x60) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x60));
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltObjectDereference();
    if (*(longlong *)(param_2 + 0x80) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x80),0);
    }
  }
  return;
}



===== VfsOpenScb$fin$0 @ 1c0014a4f =====

void VfsOpenScb_fin_0(undefined8 param_1,longlong param_2)

{
  if ((-1 < *(int *)(param_2 + 0x40)) &&
     ((**(longlong **)(param_2 + 0xc0) != 0 || (*(char *)(param_2 + 0xa8) != '\0')))) {
    **(undefined8 **)(param_2 + 200) = *(undefined8 *)(param_2 + 0x50);
    *(undefined8 *)(param_2 + 0x50) = 0;
    if (*(undefined8 **)(param_2 + 0xd0) != (undefined8 *)0x0) {
      **(undefined8 **)(param_2 + 0xd0) = *(undefined8 *)(param_2 + 0x48);
      *(undefined8 *)(param_2 + 0x48) = 0;
    }
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltReleaseContext();
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    FltClose();
  }
  return;
}



===== VfsQueryFile$fin$0 @ 1c0014aee =====

void VfsQueryFile_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x50) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== VfsCreateCommon$fin$0 @ 1c0014b30 =====

void VfsCreateCommon_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(int *)(param_2 + 0x40) < 0) {
    lVar1 = *(longlong *)(param_2 + 0xe0);
    *(int *)(lVar1 + 0x18) = *(int *)(param_2 + 0x40);
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(int **)(param_2 + 0x60) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x60));
  }
  if (*(longlong *)(param_2 + 0x80) != 0) {
    FltObjectDereference();
    if (*(longlong *)(param_2 + 0x90) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x90),0);
    }
  }
  return;
}



===== VfsCreateCompletion$fin$0 @ 1c0014bb4 =====

void VfsCreateCompletion_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(longlong *)(param_2 + 0x88) != 0) {
    FltReleaseFileNameInformation();
  }
  lVar1 = *(longlong *)(param_2 + 0x70);
  if (lVar1 != 0) {
    if (*(int *)(param_2 + 0x30) < 0) {
      FltDeleteContext(lVar1);
    }
    FltReleaseContext(lVar1);
  }
  return;
}



===== VfsCreateCompletionContext$fin$0 @ 1c0014c14 =====

void VfsCreateCompletionContext_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x20) < 0) {
    VfsDeleteCreateCompletionContext(*(longlong *)(param_2 + 0x28));
  }
  return;
}



===== VfsCreateContextNormalize$fin$0 @ 1c0014c3a =====

void VfsCreateContextNormalize_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x40),0);
  }
  return;
}



===== VfsCtxTableElementInsert$fin$0 @ 1c0014c68 =====

void VfsCtxTableElementInsert_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x24) < 0) && (*(longlong *)(param_2 + 0x28) != 0)) {
    RtlDeleteElementGenericTableAvl(*(undefined8 *)(param_2 + 0x50),*(undefined8 *)(param_2 + 0x58))
    ;
  }
  return;
}



===== VfsMarkPackageFileDeleted$fin$0 @ 1c0014ca0 =====

void VfsMarkPackageFileDeleted_fin_0(undefined8 param_1,longlong param_2)

{
  FltObjectDereference(*(undefined8 *)(param_2 + 0x68));
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
  }
  return;
}



===== VfsProcessDeleteFile$fin$0 @ 1c0014cde =====

void VfsProcessDeleteFile_fin_0(void)

{
  return;
}



===== VfsProcessDeleteOnCleanupShadow$fin$0 @ 1c0014cf4 =====

void VfsProcessDeleteOnCleanupShadow_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    FltReleaseFileNameInformation();
  }
  return;
}



===== VfsProcessDeletePackageDirectory$fin$0 @ 1c0014d20 =====

void VfsProcessDeletePackageDirectory_fin_0(void)

{
  return;
}



===== VfsCheckDirectoryEmpty$fin$0 @ 1c0014d36 =====

void VfsCheckDirectoryEmpty_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0xb8) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(int **)(param_2 + 0x40) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x40));
    if (*(longlong *)(param_2 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x58),0);
      *(undefined8 *)(param_2 + 0x58) = 0;
    }
    if (*(longlong *)(param_2 + 0x38) != 0) {
      FltObjectDereference();
    }
  }
  return;
}



===== VfsPrepareMergeDirectory$fin$0 @ 1c0014da5 =====

void VfsPrepareMergeDirectory_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x34) < 0) && (*(char *)(param_2 + 0x30) != '\0')) {
    LOCK();
    *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 4) = 0;
    UNLOCK();
  }
  return;
}



===== VfsQueryDirectoryEmpty$fin$0 @ 1c0014dd0 =====

void VfsQueryDirectoryEmpty_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x40) != '\0') {
    VfsCleanupDirQueryContext(param_2 + 0x68);
  }
  return;
}



===== VfsAddDirQuerySubContext$fin$0 @ 1c0014df6 =====

void VfsAddDirQuerySubContext_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int **)(param_2 + 0x70) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x70));
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    FltObjectDereference();
    if (*(longlong *)(param_2 + 0x68) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x68),0);
      *(undefined8 *)(param_2 + 0x68) = 0;
    }
  }
  if (*(longlong *)(param_2 + 0x38) != 0) {
    VfsDeleteDirQuerySubContext(*(longlong *)(param_2 + 0x38));
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    VfsDeleteDirQuerySubContext(*(longlong *)(param_2 + 0x40));
  }
  return;
}



===== VfsCreateDirQueryContext$fin$0 @ 1c0014e6a =====

void VfsCreateDirQueryContext_fin_0(undefined8 param_1,longlong param_2)

{
  FltReleaseFileNameInformation(*(undefined8 *)(param_2 + 0x48));
  if (*(longlong *)(param_2 + 0x40) != 0) {
    VfsDeleteDirQueryContext(*(longlong *)(param_2 + 0x40));
  }
  return;
}



===== VfsCreateDirQueryContextLocal$fin$0 @ 1c0014e9f =====

void VfsCreateDirQueryContextLocal_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x30) < 0) {
    VfsCleanupDirQueryContext(*(longlong *)(param_2 + 0x90));
  }
  return;
}



===== VfsCreateDirQuerySubContext$fin$0 @ 1c0014ec8 =====

void VfsCreateDirQuerySubContext_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x40) < 0) {
    if (*(longlong *)(param_2 + 0x48) != 0) {
      ObfDereferenceObject(*(undefined8 *)(param_2 + 0x50));
      FltClose(*(undefined8 *)(param_2 + 0x48));
    }
    if (*(longlong *)(param_2 + 0x58) != 0) {
      VfsDeleteDirQuerySubContext(*(longlong *)(param_2 + 0x58));
    }
  }
  return;
}



===== DriverInitialize$fin$0 @ 1c0014f1b =====

void DriverInitialize_fin_0
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x40);
  if ((int)uVar1 < 0) {
    VfsDriverCleanup();
    LogWrite(1,0,L"DriverInitialize() - VFS failed to load filter, Status: 0x%08X",(ulonglong)uVar1)
    ;
    LogUninitialize();
  }
  else {
    LogWrite(3,0,L"DriverInitialize() - VFS filter load succeeded",param_4);
  }
  return;
}



===== VfsDispatchDeviceIoControl$fin$0 @ 1c0014f6c =====

void VfsDispatchDeviceIoControl_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x48);
  *(undefined4 *)(lVar1 + 0x30) = *(undefined4 *)(param_2 + 0x20);
  *(undefined8 *)(lVar1 + 0x38) = 0;
  return;
}



===== VfsCreateMappingEntry$fin$0 @ 1c0014f91 =====

void VfsCreateMappingEntry_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x30) < 0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x40));
  }
  else {
    **(undefined8 **)(param_2 + 0xa8) = *(undefined8 *)(param_2 + 0x40);
  }
  return;
}



===== VfsCreateMappingPrefixTable$fin$0 @ 1c0014fc7 =====

void VfsCreateMappingPrefixTable_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x20) < 0) {
    VfsDeleteMappingPrefixTable(*(longlong *)(param_2 + 0x70));
  }
  else {
    **(undefined8 **)(param_2 + 0x68) = *(undefined8 *)(param_2 + 0x70);
  }
  return;
}



===== VfsGetMappedTarget$fin$0 @ 1c0014ffa =====

void VfsGetMappedTarget_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x30) < 0) && (*(longlong *)(param_2 + 0x48) != 0)) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x48),0);
  }
  return;
}



===== VfsMessageAddMappings$fin$0 @ 1c001502e =====

void VfsMessageAddMappings_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x68) != 0) {
    VfsPkgCtxRelease(*(longlong *)(param_2 + 0x68));
  }
  if (*(longlong *)(param_2 + 0x70) != 0) {
    VfsUserCtxRelease(*(longlong *)(param_2 + 0x70));
  }
  return;
}



===== VfsMessageRemoveMappings$fin$0 @ 1c0015062 =====

void VfsMessageRemoveMappings_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x48) != 0) {
    VfsPkgCtxRelease(*(longlong *)(param_2 + 0x48));
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    VfsUserCtxRelease(*(longlong *)(param_2 + 0x50));
  }
  return;
}



===== VfsCreateNameNormalizationContext$fin$0 @ 1c0015096 =====

void VfsCreateNameNormalizationContext_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int **)(param_2 + 0x30) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x30));
  }
  return;
}



===== VfsExpandTargetComponent$fin$0 @ 1c00150bb =====

void VfsExpandTargetComponent_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    FltObjectDereference();
    if (*(longlong *)(param_2 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x58),0);
    }
  }
  return;
}



===== VfsGenerateFileName$fin$0 @ 1c00150fe =====

void VfsGenerateFileName_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x58),0);
  }
  return;
}



===== VfsNormalizeNameComponentEx$fin$0 @ 1c0015142 =====

void VfsNormalizeNameComponentEx_fin_0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_2 + 0x38);
  if ((plVar1 != (longlong *)0x0) && (*(char *)(param_2 + 0x30) != '\0')) {
    if ((*(int *)(param_2 + 0x34) + -0x80000000 < 0) || (*(int *)(param_2 + 0x34) == -0x3ffffff1)) {
      **(longlong **)(param_2 + 0xe0) = (longlong)plVar1;
    }
    else {
      if (*plVar1 != 0) {
        VfsReleaseMappingEntry((int *)*plVar1);
      }
      ExFreeToPagedLookasideList(&DAT_1c001f900,plVar1);
    }
  }
  return;
}



===== VfsUnMapFileName$fin$0 @ 1c00151ae =====

void VfsUnMapFileName_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x30) != 0) {
    FltReleaseFileNameInformation();
  }
  return;
}



===== VfsDelayedCopy$fin$0 @ 1c00151da =====

void VfsDelayedCopy_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int **)(param_2 + 0x70) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x70));
  }
  if (*(longlong *)(param_2 + 0xd8) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    FltObjectDereference();
    if (*(longlong *)(param_2 + 0x80) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x80),0);
    }
  }
  return;
}



===== VfsCheckPackageFileForDelete$fin$0 @ 1c0015248 =====

void VfsCheckPackageFileForDelete_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x60) != 0) {
    VfsScbClose(*(longlong *)(param_2 + 0x60));
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x70) != 0) {
    FltClose();
  }
  return;
}



===== VfsCheckSimpleTargetForRename$fin$0 @ 1c0015299 =====

void VfsCheckSimpleTargetForRename_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0xd0) != 0) {
    FltReleaseFileNameInformation();
  }
  if ((*(char *)(param_2 + 0x60) != '\0') && (*(longlong *)(param_2 + 0xb0) != 0)) {
    FltObjectDereference();
  }
  if (*(longlong *)(param_2 + 0x90) != 0) {
    FltObjectDereference();
  }
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
    *(undefined8 *)(param_2 + 0x70) = 0;
  }
  if (*(longlong *)(param_2 + 0x80) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x80),0);
    *(undefined8 *)(param_2 + 0x80) = 0;
  }
  if (*(int **)(param_2 + 0x108) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x108));
  }
  return;
}



===== VfsCreateStoreForRename$fin$0 @ 1c0015350 =====

void VfsCreateStoreForRename_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x48) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x60),0);
    *(undefined8 *)(param_2 + 0x60) = 0;
  }
  if (*(longlong *)(param_2 + 0xb8) != 0) {
    FltObjectDereference();
  }
  return;
}



===== VfsRenameCanReplace$fin$0 @ 1c00153b1 =====

void VfsRenameCanReplace_fin_0(undefined8 param_1,longlong param_2)

{
  ObfDereferenceObject(*(undefined8 *)(param_2 + 0x40));
  FltClose(*(undefined8 *)(param_2 + 0x58));
  return;
}



===== VfsRenameNativeFileToVirtualTarget$fin$0 @ 1c00153e8 =====

void VfsRenameNativeFileToVirtualTarget_fin_0(undefined8 param_1,longlong param_2)

{
  VfsReleaseMappingEntry(*(int **)(param_2 + 0x30));
  if (*(longlong *)(param_2 + 0x90) != 0) {
    FltObjectDereference();
  }
  if (*(longlong *)(param_2 + 0x98) != 0) {
    FltClose();
  }
  return;
}



===== VfsRenamePackageFile$fin$0 @ 1c0015439 =====

void VfsRenamePackageFile_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int **)(param_2 + 0x70) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x70));
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    FltReleaseFileNameInformation();
  }
  return;
}



===== VfsRenameStoreFile$fin$0 @ 1c0015474 =====

void VfsRenameStoreFile_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x78) != 0) {
    FltReleaseFileNameInformation();
  }
  return;
}



===== VfsRenameVirtualFileSimple$fin$0 @ 1c00154a0 =====

void VfsRenameVirtualFileSimple_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int **)(param_2 + 0x68) != (int *)0x0) {
    VfsReleaseMappingEntry(*(int **)(param_2 + 0x68));
  }
  if (*(longlong *)(param_2 + 0xd8) != 0) {
    FltReleaseContext();
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltObjectDereference();
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0);
  }
  return;
}



===== VfsRenameVirtualFileToNativeTarget$fin$0 @ 1c001550c =====

void VfsRenameVirtualFileToNativeTarget_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    FltReleaseContext();
  }
  return;
}



===== VfsRenameVirtualFileToVirtualTarget$fin$0 @ 1c001554e =====

void VfsRenameVirtualFileToVirtualTarget_fin_0(undefined8 param_1,longlong param_2)

{
  VfsReleaseMappingEntry(*(int **)(param_2 + 0x68));
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltObjectDereference();
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    FltClose();
  }
  return;
}



===== VfsCreateScb$fin$0 @ 1c0015599 =====

void VfsCreateScb_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (*(int *)(param_2 + 0x20) < 0) {
    lVar1 = *(longlong *)(param_2 + 0x30);
    lVar2 = *(longlong *)(param_2 + 0x28);
    if (lVar1 != 0) {
      if (*(longlong *)(lVar2 + 0x80) != 0) {
        FltReleaseContext(*(undefined8 *)(lVar2 + 0x80));
      }
      if (*(longlong *)(lVar2 + 0x78) != 0) {
        ExDeleteResourceLite(*(longlong *)(lVar2 + 0x78) + 0x38);
      }
      ExFreeToNPagedLookasideList(&DAT_1c001f700,lVar1);
    }
    if (lVar2 != 0) {
      ExFreeToPagedLookasideList(&DAT_1c001f680,lVar2);
    }
  }
  return;
}



===== VfsAcquireForSectionSync$fin$0 @ 1c0015633 =====

void VfsAcquireForSectionSync_fin_0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  if (*(char *)(param_2 + 0x21) != '\0') {
    ExReleaseResourceLite();
    KeLeaveCriticalRegion();
  }
  if (*(int *)(param_2 + 0x24) < 0) {
    if (*(char *)(param_2 + 0x20) != '\0') {
      LOCK();
      plVar1 = (longlong *)(*(longlong *)(param_2 + 0x28) + 0x58);
      lVar2 = *plVar1;
      *plVar1 = 0;
      UNLOCK();
      if (lVar2 != 0) {
        ZwClose();
      }
    }
    lVar2 = *(longlong *)(param_2 + 0x70);
    *(undefined4 *)(lVar2 + 0x18) = *(undefined4 *)(param_2 + 0x24);
    *(undefined8 *)(lVar2 + 0x20) = 0;
  }
  return;
}



===== VfsCreateSecurityDescriptors$fin$0 @ 1c00156ae =====

void VfsCreateSecurityDescriptors_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x34) < 0) || (*(char *)(param_2 + 0x30) != '\0')) {
    VfsDeleteSecurityDescriptors(*(longlong **)(param_2 + 0xc0));
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x48),0);
  }
  return;
}



===== VfsReadSecurityDescriptor$fin$0 @ 1c00156f5 =====

void VfsReadSecurityDescriptor_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x98) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0x64534656);
  }
  return;
}



===== VfsCreateShadow$fin$0 @ 1c0015755 =====

void VfsCreateShadow_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x54) < 0) && (*(char *)(param_2 + 0x51) != '\0')) {
    VfsMarkFileDeleted(*(undefined8 *)(param_2 + 0x118),param_2,*(undefined8 *)(param_2 + 0x120),
                       *(char *)(param_2 + 0x140),'\x01');
  }
  if (*(char *)(param_2 + 0x50) != '\0') {
    FltObjectDereference(*(undefined8 *)(param_2 + 0x100));
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    FltReleaseContext();
  }
  return;
}



===== VfsSetupShadowFileObject$fin$0 @ 1c001581f =====

void VfsSetupShadowFileObject_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if ((*(int *)(param_2 + 0x44) < 0) || (**(char **)(param_2 + 0xf0) != '\0')) {
    if (*(longlong *)(param_2 + 0x50) != 0) {
      VfsDeleteCcb(*(longlong *)(param_2 + 0x50));
    }
    lVar1 = *(longlong *)(param_2 + 0x48);
    if (lVar1 != 0) {
      if (*(char *)(param_2 + 0x40) != '\0') {
        VfsRemoveShareAccess(*(undefined8 *)(param_2 + 0x68),lVar1,'\0');
      }
      VfsScbClose(lVar1);
    }
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltReleaseContext();
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    FltReleaseContext();
  }
  return;
}



===== VfsCreateParentDirectories$fin$0 @ 1c00158ac =====

void VfsCreateParentDirectories_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x80) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x80),0);
    *(undefined8 *)(param_2 + 0x80) = 0;
  }
  if (*(longlong *)(param_2 + 0x88) != 0) {
    FltClose();
  }
  if (*(longlong *)(param_2 + 0xb8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0xb8),0);
  }
  return;
}



===== VfsGetFileNameInformation$fin$0 @ 1c0015918 =====

void VfsGetFileNameInformation_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x20) < 0) && (*(longlong *)(param_2 + 0x58) != 0)) {
    FltReleaseFileNameInformation();
  }
  return;
}



===== VfsNormalizeFileName$fin$0 @ 1c001594a =====

void VfsNormalizeFileName_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0xb0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0xb0),0x6e474656);
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x68),0);
  }
  return;
}



===== VfsGetVpbFromInstance$fin$0 @ 1c0015996 =====

void VfsGetVpbFromInstance_fin_0(undefined8 param_1,longlong param_2)

{
  FltObjectDereference(*(undefined8 *)(param_2 + 0x40));
  return;
}



===== AllocateLogBufferEntry$fin$0 @ 1c00159bd =====

void AllocateLogBufferEntry_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseSpinLock(&DAT_1c001fd10,*(undefined1 *)(param_2 + 0x30));
  return;
}



===== LogUninitialize$fin$0 @ 1c00159ea =====

void LogUninitialize_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseSpinLock(&DAT_1c001fd10,*(undefined1 *)(param_2 + 0x40));
  return;
}



===== LogWrite$fin$0 @ 1c0015a17 =====

void LogWrite_fin_0(undefined8 param_1,longlong param_2)

{
  FreeLogBufferEntry(*(undefined8 **)(param_2 + 0x58));
  return;
}



===== VfsDriverCleanup @ 1c0024008 =====

void VfsDriverCleanup(void)

{
  if (VfsData != 0) {
    FltUnregisterFilter();
  }
  VfsDeleteControlDevice();
  VfsCtxTableDelete(0x1c001f3e0);
  VfsCtxTableDelete(0x1c001f470);
  VfsCleanupPrefixTreeLibrary();
  ExDeletePagedLookasideList(&DAT_1c001fa80);
  ExDeletePagedLookasideList(&DAT_1c001fa00);
  ExDeletePagedLookasideList(&DAT_1c001f980);
  ExDeletePagedLookasideList(&DAT_1c001f900);
  ExDeletePagedLookasideList(&DAT_1c001f880);
  ExDeletePagedLookasideList(&DAT_1c001f800);
  ExDeletePagedLookasideList(&DAT_1c001f780);
  ExDeleteNPagedLookasideList(&DAT_1c001f700);
  ExDeletePagedLookasideList(&DAT_1c001f680);
  ExDeletePagedLookasideList(&DAT_1c001f600);
  ExDeletePagedLookasideList(&DAT_1c001f500);
  ExDeletePagedLookasideList(&DAT_1c001f580);
  return;
}



===== VfsDriverUnload @ 1c0024140 =====

undefined8 VfsDriverUnload(void)

{
  undefined8 uVar1;
  undefined8 in_R9;
  
  if (DAT_1c001f3d0 == 0) {
    VfsDriverCleanup();
    LogWrite(3,0,L"VfsDriverUnload() - VFS filter unload succeeded",in_R9);
    McGenEventUnregister_EtwUnregister
              ((longlong *)&PROVIDER_MICROSOFT_APPV_CLIENT_SHAREDPERFORMANCEEVENTS_Context);
    LogUninitialize();
    uVar1 = 0;
  }
  else {
    LogWrite(3,0,L"VfsDriverUnload() - VFS filter unload is not allowed at this time",in_R9);
    uVar1 = 0xc01c0010;
  }
  return uVar1;
}



===== VfsInstanceQueryTeardown @ 1c00241a0 =====

int VfsInstanceQueryTeardown(longlong param_1)

{
  bool bVar1;
  int local_res8;
  
  local_res8 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18));
  if (local_res8 < 0) {
    LogWrite(1,0,
             L"VfsInstanceQueryTeardown() - Failed to get instance context for instance: %p\n Status: 0x%08X"
             ,*(undefined8 *)(param_1 + 0x18));
    local_res8 = -0x3fe3fff0;
  }
  else {
    LOCK();
    bVar1 = iRam0000000000000018 == 0;
    if (bVar1) {
      iRam0000000000000018 = 0;
    }
    UNLOCK();
    if (!bVar1) {
      LogWrite(3,0,
               L"VfsInstanceQueryTeardown() - VFS volume detach is not allowed for volume: %wZ\n because of opened files: %d"
               ,8);
      local_res8 = -0x3fe3fff0;
    }
    FltReleaseContext(0);
  }
  return local_res8;
}



===== VfsInstanceSetup @ 1c0024250 =====

undefined8 VfsInstanceSetup(longlong param_1,ulonglong param_2,int param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong local_18 [2];
  
  local_18[0] = 0;
  if ((param_2 & 1) == 0) {
    if (((param_3 == 8) && ((int)param_4 == 2)) || ((param_3 == 0x14 && ((int)param_4 == 0xd)))) {
      uVar2 = VfsCreateInstanceContext(*(undefined8 *)(param_1 + 0x18),param_3,local_18);
      lVar1 = local_18[0];
      if (-1 < (int)uVar2) {
        LOCK();
        DAT_1c001f3d0 = DAT_1c001f3d0 + 1;
        UNLOCK();
        LogWrite(3,0,L"VfsInstanceSetup() - VFS attached to volume: %wZ",local_18[0] + 8);
        FltReleaseContext(lVar1);
        return 0;
      }
      LogWrite(1,0,L"VfsInstanceSetup() - VFS failed to attach to volume, Status: 0x%08X",
               uVar2 & 0xffffffff);
    }
    else {
      LogWrite(3,0,
               L"VfsInstanceSetup() - VFS volume attach is not allowed for this particular volume",
               param_4);
    }
  }
  return 0xc01c000f;
}



===== VfsInstanceTeardownComplete @ 1c0024300 =====

void VfsInstanceTeardownComplete(longlong param_1)

{
  int iVar1;
  undefined8 local_18;
  longlong local_10;
  
  local_18 = 0;
  local_10 = 0;
  LOCK();
  DAT_1c001f3d0 = DAT_1c001f3d0 + -1;
  UNLOCK();
  iVar1 = VfsGetVolumeName(*(undefined8 *)(param_1 + 0x10),(undefined4 *)&local_18);
  if (-1 < iVar1) {
    LogWrite(3,0,L"VfsInstanceTeardownComplete() - VFS detached from volume: %wZ",&local_18);
    if (local_10 != 0) {
      ExFreePoolWithTag(local_10,0);
    }
  }
  return;
}



===== VfsInstanceTeardownStart @ 1c0024370 =====

void VfsInstanceTeardownStart(void)

{
  return;
}



===== VfsInitializeLookasideLists @ 1c002437c =====

void VfsInitializeLookasideLists(longlong param_1)

{
  ExInitializePagedLookasideList(param_1,0,0,0,0x60,0x63504656,0);
  ExInitializePagedLookasideList(param_1 + 0x80,0,0,0,0x110,0x63554656,0);
  ExInitializePagedLookasideList(param_1 + 0x100,0,0,0,0xa0,0x74534656,0);
  ExInitializePagedLookasideList(param_1 + 0x180,0,0,0,0x198,0x62534656,0);
  ExInitializeNPagedLookasideList(param_1 + 0x200,0,0,0,0xa0,0x6e534656,0);
  ExInitializePagedLookasideList(param_1 + 0x280,0,0,0,0x88,0x62434656,0);
  ExInitializePagedLookasideList(param_1 + 0x300,0,0,0,0x88,0x72434656,0);
  ExInitializePagedLookasideList(param_1 + 0x380,0,0,0,0x18,0x6c434656,0);
  ExInitializePagedLookasideList(param_1 + 0x400,0,0,0,8,0x6e4e4656,0);
  ExInitializePagedLookasideList(param_1 + 0x480,0,0,0,0x38,0x71444656,0);
  ExInitializePagedLookasideList(param_1 + 0x500,0,0,0,0x78,0x73444656,0);
  ExInitializePagedLookasideList(param_1 + 0x580,0,0,0,0x28,0x704d4656,0);
  return;
}



===== _tlgEnableCallback @ 1c00245f0 =====

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



===== WdmlibIoCreateDeviceSecure @ 1c002466c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000048;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (WdmlibInitialized == '\0') {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
    PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
    if (PfnIoCreateDeviceSecure == (code *)0x0) {
      PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
    }
    RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
    MmGetSystemRoutineAddress(&local_18);
    WdmlibInitialized = '\x01';
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,param_3,0xa688,0x100,0,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL,&APPV_VFS_CLASS_GUID,
             in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1c0024760 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,undefined4 *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (undefined4 *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1c00248c0;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1c00248c0;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_1c00248c0:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1c00248f4 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 1c00249e4 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memcpy(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 1c0024ac4 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memcpy(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 1c0024bc4 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 1c0024cb0 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  undefined **ppuVar17;
  short *local_res8;
  uint local_res10;
  uint local_res18;
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_50[0] = 0;
  iVar5 = 0;
  uVar16 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar2 = false;
  bVar1 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar16 = uVar16 + 1;
    }
    else {
      bVar1 = bVar2;
      if (*pwVar10 != L' ') {
        bVar2 = true;
        bVar1 = true;
      }
    }
  }
  local_res18 = uVar16 / 5;
  if ((uVar16 != local_res18 * 5) || ((uVar16 == 0 && (bVar1)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (local_res18 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar16 = local_res18 * 0x30 + 8;
      if (0xffff < uVar16) {
        uVar16 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar16,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar16);
        *_Dst = 2;
        _Dst[1] = (short)uVar16;
        *(undefined4 *)(_Dst + 2) = 0;
        local_res10 = 0;
        uVar16 = local_res18;
        uVar15 = 8;
        if (local_res18 != 0) {
          do {
            uVar15 = 0;
            local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
            for (; *param_1 == L' '; param_1 = param_1 + 1) {
            }
            if (*param_1 == L'(') {
              do {
                param_1 = param_1 + 1;
              } while (*param_1 == L' ');
            }
            iVar4 = _wcsnicmp(param_1,L"A",1);
            if (iVar4 != 0) {
LAB_1c002504b:
              iVar5 = -0x3ffffff3;
LAB_1c002504d:
              lVar7 = *param_2;
              goto LAB_1c0025033;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1c002504b;
            do {
              pwVar6 = pwVar6 + 1;
              wVar3 = *pwVar6;
            } while (wVar3 == L' ');
            if (wVar3 != L';') {
              do {
                uVar11 = 0;
                while (wVar3 == L' ') {
                  pwVar6 = pwVar6 + 1;
                  wVar3 = *pwVar6;
                }
                ppuVar17 = &PTR_u_RC_1c001f120;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_1c001f12c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_1c001f128)[uVar11 * 4];
                    goto LAB_1c0024f3d;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_1c002504b;
                uVar15 = (uint)local_res8;
LAB_1c0024f3d:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1c002504d;
            lVar7 = 2;
            do {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              if (*pwVar6 != L';') {
                iVar5 = -0x3ffffff3;
              }
              pwVar6 = pwVar6 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (iVar5 != 0) goto LAB_1c002504d;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_1c0024fbb:
              iVar5 = -0x3fffff89;
              goto LAB_1c002504d;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_1c0024fbb;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1c002504d;
            }
            if (*param_1 == L'(') {
              param_1 = psVar12 + 2;
            }
            local_res10 = local_res10 + 1;
          } while (local_res10 < uVar16);
          uVar15 = local_res20[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar15;
          return 0;
        }
LAB_1c0025033:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1c0025078 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_1c001f1f4;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1c001f1ec + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1c001f1e8 + uVar7 * 0x18);
      uVar6 = (&DAT_1c001f1f4)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_1c002510f;
      }
      else {
LAB_1c002510f:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1c001f1e0 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_1c0025124;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_1c0025124:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 1c002514c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_1c00251cf:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_1c00251ad;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1c00251cf;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_1c00251ad:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 1c0025258 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_1c002539d;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c002539d:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1c00253fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (undefined4 *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x1c001ca00,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar5 = *param_1;
    pwVar4 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar5 = 2;
    }
    else {
      uVar3 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar4,uVar5,0,&local_b8,local_a8);
      uVar2 = (uint)uVar3;
      uVar5 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar5;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 1c0025598 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1c001c980);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_1c0025717;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c001c998,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0025717;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c001c9b0,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0025717;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c001c9e0,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1c0025717:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 1c002575c =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined4 *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1c001c920,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1c001c938);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c001c948,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c001c968,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 1c00258c0 =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined4 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  uVar2 = (undefined4)uVar8;
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar2 = (undefined4)uVar8;
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar5 = CmRegUtilCreateWstrKey
                      (local_res20,0x1c001c920,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = uVar5 & 0xffffffff;
    ZwClose(local_res20);
    if (-1 < (int)uVar5) {
      uVar2 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1c001c980);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar3 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar2);
        uVar4 = (ulonglong)uVar3;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1c0025a28 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateWstrKey @ 1c0025b24 =====

ulonglong CmRegUtilCreateWstrKey
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res20[0] = param_4;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_res20[0] = 0;
    local_58 = 0;
    local_18 = 0;
    local_20 = param_5;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    uVar1 = ZwCreateKey(&local_58,0xf003f,&local_40,0,0,0,local_res20);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      local_58 = 0;
      local_res20[0] = 0;
    }
    *param_7 = local_58;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_res20[0];
    }
  }
  return uVar2;
}



===== CmRegUtilOpenExistingWstrKey @ 1c0025bf4 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 1c0025c88 =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_1c0025dc0;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1c0025dc0:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1c0025e04 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memcpy(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 1c0025f50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 1c0025ff4 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== VfsInstanceQueryTeardown$fin$0 @ 1c002604e =====

void VfsInstanceQueryTeardown_fin_0(undefined8 param_1,longlong param_2)

{
  FltReleaseContext(*(undefined8 *)(param_2 + 0x50));
  return;
}



===== entry @ 1c0027010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0027044 =====

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



===== DriverEntry @ 1c0027078 =====

void DriverEntry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverInitialize(param_1,param_2);
  return;
}



===== LogInitialize @ 1c002709c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong LogInitialize(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 *puVar5;
  int iVar6;
  uint uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [48];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  McGenEventRegister_EtwRegister
            (&AppVClientDbg,param_2,&AppVClientDbg_Context,(longlong *)&AppVClientDbg_Context);
  puVar11 = auStack_58;
  local_20 = *(undefined4 *)(PTR_DAT_1c001f0e8 + -0x10);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c001f0e8 + -0xc);
  uStack_18 = *(undefined4 *)(PTR_DAT_1c001f0e8 + -8);
  uStack_14 = *(undefined4 *)(PTR_DAT_1c001f0e8 + -4);
  if (DAT_1c001f100 != 0) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(5);
    puVar11 = auStack_50;
  }
  puVar12 = &DAT_1c001f0e0;
  _DAT_1c001f108 = 0;
  uRam00000001c001f110 = 0;
  *(undefined8 *)(puVar11 + -8) = 0x1c002711e;
  iVar6 = EtwRegister(puVar11 + 0x38,_tlgEnableCallback,&DAT_1c001f0e0,&DAT_1c001f100);
  if (iVar6 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c001f0e8;
    *(undefined8 *)(puVar11 + -8) = 0x1c0027143;
    puVar12 = (undefined4 *)PTR_DAT_1c001f0e8;
    EtwSetInformation(DAT_1c001f100,2,PTR_DAT_1c001f0e8,uVar1);
  }
  *(undefined8 *)(puVar11 + -8) = 0x1c002715d;
  RtlInitUnicodeString(&DAT_1c001fd18,L"VfscDrv");
  *(undefined8 *)(puVar11 + -8) = 0x1c0027170;
  KeInitializeSpinLock(&DAT_1c001fd10);
  DAT_1c001fd08 = &DAT_1c001fd00;
  DAT_1c001fd00 = &DAT_1c001fd00;
  *(undefined8 *)(puVar11 + 0x38) = 0;
  *(undefined8 *)(puVar11 + 0x40) = 0;
  *(undefined8 *)(puVar11 + 0x28) = 0;
  *(undefined8 *)(puVar11 + 0x30) = 0;
  *(undefined8 *)(puVar11 + -8) = 0x1c00271ad;
  RtlInitUnicodeString
            (puVar11 + 0x38,L"\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\AppV\\Shared\\Policy");
  *(undefined8 *)(puVar11 + -8) = 0x1c00271c5;
  RtlInitUnicodeString(puVar11 + 0x28,L"DbgFilterMask");
  *(undefined8 *)(puVar11 + 0x20) = 0;
  *(undefined8 *)(puVar11 + -8) = 0x1c00271e4;
  uVar7 = ReadRegistryValue((longlong)(puVar11 + 0x38),(longlong)(puVar11 + 0x28),puVar12,
                            (longlong *)(puVar11 + 0x20));
  if ((int)uVar7 < 0) {
    uVar10 = 0xffffffff;
  }
  else {
    lVar2 = *(longlong *)(puVar11 + 0x20);
    uVar10 = *(undefined4 *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2);
    *(undefined8 *)(puVar11 + -8) = 0x1c00271ff;
    ExFreePoolWithTag(lVar2,0x676c6462);
  }
  iVar6 = 0;
  _DAT_1c001f1d0 = uVar10;
  do {
    *(undefined8 *)(puVar11 + -8) = 0x1c0027228;
    puVar8 = (undefined8 *)ExAllocatePool2(0x40,0x828,0x676c6462);
    if (puVar8 == (undefined8 *)0x0) goto LAB_1c0027286;
    if ((undefined8 **)*DAT_1c001fd08 != &DAT_1c001fd00) goto LAB_1c00272c4;
    *puVar8 = &DAT_1c001fd00;
    iVar6 = iVar6 + 1;
    puVar8[1] = DAT_1c001fd08;
    *DAT_1c001fd08 = puVar8;
    DAT_1c001fd08 = puVar8;
  } while (iVar6 < 10);
LAB_1c0027266:
  *(undefined8 *)(puVar11 + -8) = 0x1c0027275;
  return (ulonglong)(~-(uint)(puVar8 != (undefined8 *)0x0) & 0xc000009a);
LAB_1c0027286:
  while (puVar5 = DAT_1c001fd00, (undefined8 **)DAT_1c001fd00 != &DAT_1c001fd00) {
    if (((undefined8 **)DAT_1c001fd00[1] != &DAT_1c001fd00) ||
       (puVar3 = (undefined8 *)*DAT_1c001fd00, (undefined8 *)puVar3[1] != DAT_1c001fd00)) {
LAB_1c00272c4:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar9 = (*pcVar4)();
      return uVar9;
    }
    DAT_1c001fd00 = puVar3;
    puVar3[1] = &DAT_1c001fd00;
    if (puVar5 != (undefined8 *)0x0) {
      *(undefined8 *)(puVar11 + -8) = 0x1c00272bd;
      ExFreePoolWithTag(puVar5,0x676c6462);
    }
  }
  goto LAB_1c0027266;
}



===== ReadRegistryValue @ 1c00272d4 =====

uint ReadRegistryValue(longlong param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  uint uVar2;
  uint local_res18 [2];
  longlong *local_res20;
  longlong local_60;
  longlong local_58 [8];
  
  local_60 = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = local_58[6] & 0xffffffff00000000;
  local_58[0] = 0;
  local_res18[0] = 0;
  local_res20 = param_4;
  if (((param_1 == 0) || (param_2 == 0)) || (param_4 == (longlong *)0x0)) {
    uVar2 = 0xc000000d;
  }
  else {
    *param_4 = 0;
    local_58[1] = 0x30;
    local_58[2] = 0;
    local_58[4] = 0x240;
    local_58[5] = 0;
    local_58[6] = 0;
    local_58[3] = param_1;
    uVar2 = ZwOpenKey(&local_60,0x20019,local_58 + 1);
    if ((-1 < (int)uVar2) &&
       ((uVar2 = ZwQueryValueKey(local_60,param_2,1,0,0,local_res18,uVar2), uVar2 == 0xc0000023 ||
        (uVar2 == 0x80000005)))) {
      uVar2 = AllocateGenericBuffer(0x100,(ulonglong)local_res18[0],local_58);
      lVar1 = local_58[0];
      if ((-1 < (int)uVar2) &&
         ((uVar2 = ZwQueryValueKey(local_60,param_2,1,local_58[0],local_res18[0],local_res18,uVar2),
          -1 < (int)uVar2 && (*(int *)(lVar1 + 4) != 4)))) {
        uVar2 = 0xc0000001;
      }
    }
  }
  if (local_60 != 0) {
    ZwClose();
  }
  if (local_58[0] != 0) {
    if ((int)uVar2 < 0) {
      ExFreePoolWithTag(local_58[0],0x676c6462);
    }
    else {
      *param_4 = local_58[0];
    }
  }
  return uVar2;
}



===== ReadRegistryValue$fin$0 @ 1c002749d =====

void ReadRegistryValue_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ZwClose();
  }
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (lVar1 != 0) {
    if (*(int *)(param_2 + 0x30) < 0) {
      ExFreePoolWithTag(lVar1,0x676c6462);
    }
    else {
      **(longlong **)(param_2 + 0xb8) = lVar1;
    }
  }
  return;
}


